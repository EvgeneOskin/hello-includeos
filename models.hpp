#pragma once
#ifndef MODELS_HPP
#define MODEL_SQUIRREL_HPP

#include <mana/attributes/json.hpp>

namespace hello {

  struct Person : mana::Serializable {
    Person() {}
    Person(const std::string& _name): name {_name} {}

    std::string json() const;
    virtual void serialize(rapidjson::Writer<rapidjson::StringBuffer>&) const override;
    virtual bool deserialize(const rapidjson::Document&) override;

  private:
    std::string name;
  };

  inline void Person::serialize(rapidjson::Writer<rapidjson::StringBuffer>& writer) const {
    writer.StartObject();

    writer.Key("name");
    writer.String(name);

    writer.Key("title");
    writer.String("Welcome " + name);

    writer.EndObject();
  }

  inline bool Person::deserialize(const rapidjson::Document& document) {
    name = document["name"].GetString();
    return true;
  }

  inline std::string Person::json() const {
    rapidjson::StringBuffer buffer;
    rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
    serialize(writer);
    return buffer.GetString();
  }

}

#endif // MODELS_HPP
