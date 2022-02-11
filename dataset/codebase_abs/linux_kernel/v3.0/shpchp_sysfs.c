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
V_8 += sprintf ( V_8 , L_2
L_3 ,
( unsigned long long ) V_12 -> V_19 ,
( unsigned long long ) ( V_12 -> V_20 - V_12 -> V_19 ) ) ;
}
}
V_8 += sprintf ( V_8 , L_4 ) ;
F_3 (bus, res, index) {
if ( V_12 && ( V_12 -> V_16 & V_17 ) &&
( V_12 -> V_16 & V_18 ) ) {
V_8 += sprintf ( V_8 , L_2
L_3 ,
( unsigned long long ) V_12 -> V_19 ,
( unsigned long long ) ( V_12 -> V_20 - V_12 -> V_19 ) ) ;
}
}
V_8 += sprintf ( V_8 , L_5 ) ;
F_3 (bus, res, index) {
if ( V_12 && ( V_12 -> V_16 & V_21 ) ) {
V_8 += sprintf ( V_8 , L_2
L_3 ,
( unsigned long long ) V_12 -> V_19 ,
( unsigned long long ) ( V_12 -> V_20 - V_12 -> V_19 ) ) ;
}
}
V_8 += sprintf ( V_8 , L_6 ) ;
for ( V_10 = V_14 -> V_22 ; V_10 <= V_14 -> V_15 ; V_10 ++ ) {
if ( ! F_4 ( F_5 ( V_14 ) , V_10 ) )
break;
}
if ( V_10 < V_14 -> V_15 )
V_8 += sprintf ( V_8 , L_7 ,
V_10 , ( V_14 -> V_15 - V_10 ) ) ;
return V_8 - V_5 ;
}
int T_2 F_6 ( struct V_23 * V_24 )
{
return F_7 ( & V_24 -> V_6 -> V_2 , & V_25 ) ;
}
void F_8 ( struct V_23 * V_24 )
{
F_9 ( & V_24 -> V_6 -> V_2 , & V_25 ) ;
}
