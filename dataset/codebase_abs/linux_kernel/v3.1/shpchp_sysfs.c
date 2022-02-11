static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 ;
char * V_8 = V_5 ;
int V_9 , V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
V_14 = V_7 -> V_15 ;
V_8 += sprintf ( V_5 , L_1 ) ;
F_3 (bus, res, index) {
if ( V_12 && ( V_12 -> V_16 & V_17 ) &&
! ( V_12 -> V_16 & V_18 ) ) {
V_8 += sprintf ( V_8 , L_2 ,
( unsigned long long ) V_12 -> V_19 ,
( unsigned long long ) F_4 ( V_12 ) ) ;
}
}
V_8 += sprintf ( V_8 , L_3 ) ;
F_3 (bus, res, index) {
if ( V_12 && ( V_12 -> V_16 & V_17 ) &&
( V_12 -> V_16 & V_18 ) ) {
V_8 += sprintf ( V_8 , L_2 ,
( unsigned long long ) V_12 -> V_19 ,
( unsigned long long ) F_4 ( V_12 ) ) ;
}
}
V_8 += sprintf ( V_8 , L_4 ) ;
F_3 (bus, res, index) {
if ( V_12 && ( V_12 -> V_16 & V_20 ) ) {
V_8 += sprintf ( V_8 , L_2 ,
( unsigned long long ) V_12 -> V_19 ,
( unsigned long long ) F_4 ( V_12 ) ) ;
}
}
V_8 += sprintf ( V_8 , L_5 ) ;
for ( V_10 = V_14 -> V_21 ; V_10 <= V_14 -> V_15 ; V_10 ++ ) {
if ( ! F_5 ( F_6 ( V_14 ) , V_10 ) )
break;
}
if ( V_10 < V_14 -> V_15 )
V_8 += sprintf ( V_8 , L_6 ,
V_10 , ( V_14 -> V_15 - V_10 ) ) ;
return V_8 - V_5 ;
}
int T_2 F_7 ( struct V_22 * V_23 )
{
return F_8 ( & V_23 -> V_6 -> V_2 , & V_24 ) ;
}
void F_9 ( struct V_22 * V_23 )
{
F_10 ( & V_23 -> V_6 -> V_2 , & V_24 ) ;
}
