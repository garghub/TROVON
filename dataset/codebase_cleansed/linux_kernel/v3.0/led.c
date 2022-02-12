void ath5k_led_enable(struct ath5k_softc *sc)
{
if (test_bit(ATH_STAT_LEDSOFT, sc->status)) {
ath5k_hw_set_gpio_output(sc->ah, sc->led_pin);
ath5k_led_off(sc);
}
}
static void ath5k_led_on(struct ath5k_softc *sc)
{
if (!test_bit(ATH_STAT_LEDSOFT, sc->status))
return;
ath5k_hw_set_gpio(sc->ah, sc->led_pin, sc->led_on);
}
void ath5k_led_off(struct ath5k_softc *sc)
{
if (!test_bit(ATH_STAT_LEDSOFT, sc->status))
return;
ath5k_hw_set_gpio(sc->ah, sc->led_pin, !sc->led_on);
}
static void
ath5k_led_brightness_set(struct led_classdev *led_dev,
enum led_brightness brightness)
{
struct ath5k_led *led = container_of(led_dev, struct ath5k_led,
led_dev);
if (brightness == LED_OFF)
ath5k_led_off(led->sc);
else
ath5k_led_on(led->sc);
}
static int
ath5k_register_led(struct ath5k_softc *sc, struct ath5k_led *led,
const char *name, char *trigger)
{
int err;
led->sc = sc;
strncpy(led->name, name, sizeof(led->name));
led->led_dev.name = led->name;
led->led_dev.default_trigger = trigger;
led->led_dev.brightness_set = ath5k_led_brightness_set;
err = led_classdev_register(sc->dev, &led->led_dev);
if (err) {
ATH5K_WARN(sc, "could not register LED %s\n", name);
led->sc = NULL;
}
return err;
}
static void
ath5k_unregister_led(struct ath5k_led *led)
{
if (!led->sc)
return;
led_classdev_unregister(&led->led_dev);
ath5k_led_off(led->sc);
led->sc = NULL;
}
void ath5k_unregister_leds(struct ath5k_softc *sc)
{
ath5k_unregister_led(&sc->rx_led);
ath5k_unregister_led(&sc->tx_led);
}
int ath5k_init_leds(struct ath5k_softc *sc)
{
int ret = 0;
struct ieee80211_hw *hw = sc->hw;
#ifndef CONFIG_ATHEROS_AR231X
struct pci_dev *pdev = sc->pdev;
#endif
char name[ATH5K_LED_MAX_NAME_LEN + 1];
const struct pci_device_id *match;
if (!sc->pdev)
return 0;
#ifdef CONFIG_ATHEROS_AR231X
match = NULL;
#else
match = pci_match_id(&ath5k_led_devices[0], pdev);
#endif
if (match) {
__set_bit(ATH_STAT_LEDSOFT, sc->status);
sc->led_pin = ATH_PIN(match->driver_data);
sc->led_on = ATH_POLARITY(match->driver_data);
}
if (!test_bit(ATH_STAT_LEDSOFT, sc->status))
goto out;
ath5k_led_enable(sc);
snprintf(name, sizeof(name), "ath5k-%s::rx", wiphy_name(hw->wiphy));
ret = ath5k_register_led(sc, &sc->rx_led, name,
ieee80211_get_rx_led_name(hw));
if (ret)
goto out;
snprintf(name, sizeof(name), "ath5k-%s::tx", wiphy_name(hw->wiphy));
ret = ath5k_register_led(sc, &sc->tx_led, name,
ieee80211_get_tx_led_name(hw));
out:
return ret;
}
