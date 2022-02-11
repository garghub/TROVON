static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_8 ;
F_2 ( & V_6 -> V_9 ) ;
F_3 ( V_6 , V_10 , ( V_3 << 5 ) | V_4 ) ;
V_8 = F_4 ( V_6 , V_11 ) ;
F_5 ( & V_6 -> V_9 ) ;
F_6 ( V_6 -> V_12 , L_1 ,
V_3 , V_4 , V_8 ) ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_2 , int V_3 , int V_4 , T_2 V_13 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_6 ( V_6 -> V_12 , L_2 ,
V_3 , V_4 , V_13 ) ;
F_2 ( & V_6 -> V_9 ) ;
F_8 ( V_6 , V_14 , V_13 ) ;
F_8 ( V_6 , V_11 , ( V_3 << 5 ) | V_4 ) ;
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
}
int F_9 ( struct V_5 * V_6 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
T_1 V_17 ;
int V_18 ;
int V_8 ;
struct V_19 V_20 ;
V_18 = 0x3f ;
if ( F_10 ( V_16 , L_3 , & V_17 ) == 0 ) {
V_18 = V_17 / ( 2500 * 1000 * 2 ) - 1 ;
if ( V_18 < 1 )
V_18 = 1 ;
if ( V_18 > 0x3f )
V_18 = 0x3f ;
}
F_2 ( & V_6 -> V_9 ) ;
F_8 ( V_6 , V_21 , 1 << 6 | V_18 ) ;
F_5 ( & V_6 -> V_9 ) ;
V_2 = F_11 () ;
if ( ! V_2 )
return - V_22 ;
F_12 ( V_16 , 0 , & V_20 ) ;
snprintf ( V_2 -> V_23 , V_24 , L_4 ,
( unsigned long long ) V_20 . V_25 ) ;
V_2 -> V_7 = V_6 ;
V_2 -> V_26 = L_5 ;
V_2 -> V_27 = F_1 ;
V_2 -> V_28 = F_7 ;
V_2 -> V_29 = V_6 -> V_12 ;
V_2 -> V_30 = V_6 -> V_31 ;
V_6 -> V_1 = V_2 ;
V_8 = F_13 ( V_2 , V_16 ) ;
if ( V_8 )
goto V_32;
F_2 ( & V_6 -> V_9 ) ;
F_6 ( V_6 -> V_12 , L_6 ,
F_4 ( V_6 , V_21 ) ) ;
F_5 ( & V_6 -> V_9 ) ;
return 0 ;
V_32:
F_14 ( V_2 ) ;
return V_8 ;
}
void F_15 ( struct V_5 * V_6 )
{
F_16 ( V_6 -> V_1 ) ;
F_17 ( V_6 -> V_1 -> V_30 ) ;
F_14 ( V_6 -> V_1 ) ;
V_6 -> V_1 = NULL ;
}
