unsigned long T_1
F_1 ( enum V_1 type )
{
#define CASE ( T_2 , T_3 ) \
case PV_GATE_START_##NAME: \
return pv_patchdata.start_##name##_patchlist; \
case PV_GATE_END_##NAME: \
return pv_patchdata.end_##name##_patchlist; \
switch (type) {
CASE ( V_2 , V_3 ) ;
CASE ( V_4 , V_5 ) ;
CASE ( V_6 , V_7 ) ;
CASE ( V_8 , V_9 ) ;
default:
F_2 () ;
break;
}
