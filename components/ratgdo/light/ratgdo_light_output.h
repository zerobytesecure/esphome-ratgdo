#pragma once

#include "../ratgdo.h"
#include "../ratgdo_state.h"
#include "esphome/components/light/light_output.h"
#include "esphome/core/component.h"

namespace esphome {
namespace ratgdo {

    class RATGDOLightOutput : public light::LightOutput, public RATGDOClient, public Component {
    public:
        void dump_config() override;
        void setup() override;
        light::LightTraits get_traits() override;
        void write_state(light::LightState* state) override;
        void setup_state(light::LightState* state) override;
        void set_state(esphome::ratgdo::LightState state);
        light::LightState* get_state() { return this->light_state_; }

        void on_light_state(esphome::ratgdo::LightState state);

    protected:
        light::LightState* light_state_;
        bool has_initial_state_ = false;
    };

} // namespace ratgdo
} // namespace esphome
