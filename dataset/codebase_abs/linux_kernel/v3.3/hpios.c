void F_1 ( T_1 V_1 )
{
if ( ( F_2 ( V_1 ) > 1 ) && ! F_3 () ) {
F_4 ( F_2
( V_1 ) ) ;
} else if ( V_1 <= 2000 )
F_5 ( V_1 ) ;
else
F_6 ( V_1 / 1000 ) ;
}
T_2 F_7 ( struct V_2 * V_3 , T_1 V_4 ,
struct V_5 * V_6 )
{
V_3 -> V_7 =
F_8 ( & V_6 -> V_8 , V_4 , & V_3 -> V_9 ,
V_10 | V_11 ) ;
if ( V_3 -> V_7 ) {
F_9 ( V_12 , L_1 ,
V_4 , ( unsigned int ) V_3 -> V_9 ,
V_3 -> V_7 ) ;
V_3 -> V_6 = & V_6 -> V_8 ;
V_3 -> V_4 = V_4 ;
return 0 ;
} else {
F_9 ( V_13 ,
L_2 , V_4 ) ;
V_3 -> V_4 = 0 ;
return - V_14 ;
}
}
T_2 F_10 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 ) {
F_11 ( V_3 -> V_6 , V_3 -> V_4 ,
V_3 -> V_7 , V_3 -> V_9 ) ;
F_9 ( V_12 , L_3 ,
( unsigned long ) V_3 -> V_4 ,
( unsigned int ) V_3 -> V_9 ,
V_3 -> V_7 ) ;
V_3 -> V_4 = 0 ;
return 0 ;
} else {
return 1 ;
}
}
