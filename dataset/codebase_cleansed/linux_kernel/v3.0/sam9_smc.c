void __init sam9_smc_configure(int cs, struct sam9_smc_config* config)
{
at91_sys_write(AT91_SMC_SETUP(cs),
AT91_SMC_NWESETUP_(config->nwe_setup)
| AT91_SMC_NCS_WRSETUP_(config->ncs_write_setup)
| AT91_SMC_NRDSETUP_(config->nrd_setup)
| AT91_SMC_NCS_RDSETUP_(config->ncs_read_setup)
);
at91_sys_write(AT91_SMC_PULSE(cs),
AT91_SMC_NWEPULSE_(config->nwe_pulse)
| AT91_SMC_NCS_WRPULSE_(config->ncs_write_pulse)
| AT91_SMC_NRDPULSE_(config->nrd_pulse)
| AT91_SMC_NCS_RDPULSE_(config->ncs_read_pulse)
);
at91_sys_write(AT91_SMC_CYCLE(cs),
AT91_SMC_NWECYCLE_(config->write_cycle)
| AT91_SMC_NRDCYCLE_(config->read_cycle)
);
at91_sys_write(AT91_SMC_MODE(cs),
config->mode
| AT91_SMC_TDF_(config->tdf_cycles)
);
}
