static int T_1 F_1 ( void )
{
struct V_1 * V_2 = & V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int error ;
if ( ! V_2 -> V_8 ) {
F_2 ( V_9
L_1 ,
V_2 -> V_10 ) ;
return - V_11 ;
}
V_2 -> V_12 = V_13 ;
F_3 ( & V_2 -> V_14 ) ;
V_2 -> V_15 ( V_2 ) ;
if ( F_4 ( & V_2 -> V_14 ) )
return - V_16 ;
F_5 (shost, &sht->legacy_hosts, sht_legacy_list) {
error = F_6 ( V_5 , NULL ) ;
if ( error )
goto V_17;
F_7 ( V_5 ) ;
}
return 0 ;
V_17:
V_7 = & V_5 -> V_18 ;
while ( ( V_7 = V_7 -> V_19 ) != & V_2 -> V_14 )
F_8 ( F_9 ( V_7 , struct V_4 , V_18 ) ) ;
return error ;
}
static void T_2 F_10 ( void )
{
struct V_1 * V_2 = & V_3 ;
struct V_4 * V_5 , * V_20 ;
F_5 (shost, &sht->legacy_hosts, sht_legacy_list)
F_8 ( V_5 ) ;
F_11 (shost, s, &sht->legacy_hosts, sht_legacy_list)
V_2 -> V_8 ( V_5 ) ;
if ( F_4 ( & V_2 -> V_14 ) )
return;
F_2 ( V_21 L_2 , V_2 -> V_10 ) ;
F_12 () ;
F_11 (shost, s, &sht->legacy_hosts, sht_legacy_list)
F_13 ( V_5 ) ;
}
