int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , void * V_4 , void * V_5 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
int V_8 = V_3 * V_9 * 2 ;
void T_2 * V_10 = V_7 -> V_11 ;
int V_12 = V_3 * V_13 ;
int V_14 , V_15 ;
F_2 ( & V_7 -> V_16 ) ;
if ( F_3 ( V_10 , V_12 ) == 1 ) {
F_4 ( & V_7 -> V_16 ) ;
return - V_17 ;
}
memcpy ( V_7 -> V_18 + V_8 , V_4 , V_9 ) ;
F_5 ( V_10 , V_12 , 1 ) ;
V_15 = 0 ;
for ( V_14 = 0 ; V_14 < 50 ; V_14 ++ ) {
F_6 ( 20 ) ;
if ( F_3 ( V_10 , V_12 ) == 0 ) {
V_15 = 1 ;
break;
}
}
if ( V_15 )
memcpy ( V_5 , V_7 -> V_18 + V_8 +
V_9 , V_9 ) ;
else
F_7 ( & F_8 ( V_2 ) ,
L_1 ) ;
F_4 ( & V_7 -> V_16 ) ;
return V_15 ? 0 : - V_19 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_20 * V_21 = & F_10 ( V_2 ) [ V_22 ] ;
void T_2 * V_23 = V_21 -> V_18 ;
void T_2 * V_10 = V_23 + V_24 ;
T_3 V_25 ;
V_7 = F_11 ( sizeof( * V_2 -> V_7 ) , V_26 ,
F_12 ( & F_8 ( V_2 ) ) ) ;
if ( ! V_7 )
return - V_27 ;
V_7 -> V_18 = F_13 ( & F_8 ( V_2 ) , V_28 ,
& V_7 -> V_29 , V_26 ) ;
if ( ! V_7 -> V_18 ) {
F_7 ( & F_8 ( V_2 ) , L_2 ) ;
F_14 ( V_7 ) ;
return - V_27 ;
}
V_25 = ( T_3 ) V_7 -> V_29 ;
F_5 ( V_23 , V_30 , V_25 >> 32 ) ;
F_5 ( V_23 , V_31 , V_25 ) ;
F_15 ( & V_7 -> V_16 ) ;
V_7 -> V_11 = V_10 ;
V_2 -> V_7 = V_7 ;
return 0 ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = V_2 -> V_7 ;
if ( ! V_7 )
return;
if ( V_7 -> V_18 )
F_17 ( & F_8 ( V_2 ) , V_28 ,
V_7 -> V_18 , V_7 -> V_29 ) ;
F_18 ( & V_7 -> V_16 ) ;
F_14 ( V_7 ) ;
V_2 -> V_7 = NULL ;
}
