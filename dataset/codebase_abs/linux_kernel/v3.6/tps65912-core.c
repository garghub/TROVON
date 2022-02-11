int F_1 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_5 ;
F_2 ( & V_1 -> V_6 ) ;
V_5 = V_1 -> V_7 ( V_1 , V_2 , 1 , & V_4 ) ;
if ( V_5 ) {
F_3 ( V_1 -> V_8 , L_1 , V_2 ) ;
goto V_9;
}
V_4 |= V_3 ;
V_5 = V_1 -> V_10 ( V_1 , V_2 , 1 , & V_4 ) ;
if ( V_5 )
F_3 ( V_1 -> V_8 , L_2 , V_2 ) ;
V_9:
F_4 ( & V_1 -> V_6 ) ;
return V_5 ;
}
int F_5 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 ;
int V_5 ;
F_2 ( & V_1 -> V_6 ) ;
V_5 = V_1 -> V_7 ( V_1 , V_2 , 1 , & V_4 ) ;
if ( V_5 ) {
F_3 ( V_1 -> V_8 , L_1 , V_2 ) ;
goto V_9;
}
V_4 &= ~ V_3 ;
V_5 = V_1 -> V_10 ( V_1 , V_2 , 1 , & V_4 ) ;
if ( V_5 )
F_3 ( V_1 -> V_8 , L_2 , V_2 ) ;
V_9:
F_4 ( & V_1 -> V_6 ) ;
return V_5 ;
}
static inline int F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
T_1 V_11 ;
int V_5 ;
V_5 = V_1 -> V_7 ( V_1 , V_2 , 1 , & V_11 ) ;
if ( V_5 < 0 )
return V_5 ;
return V_11 ;
}
static inline int F_7 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_11 )
{
return V_1 -> V_10 ( V_1 , V_2 , 1 , & V_11 ) ;
}
int F_8 ( struct V_1 * V_1 , T_1 V_2 )
{
int V_4 ;
F_2 ( & V_1 -> V_6 ) ;
V_4 = F_6 ( V_1 , V_2 ) ;
if ( V_4 < 0 )
F_3 ( V_1 -> V_8 , L_1 , V_2 ) ;
F_4 ( & V_1 -> V_6 ) ;
return V_4 ;
}
int F_9 ( struct V_1 * V_1 , T_1 V_2 , T_1 V_11 )
{
int V_5 ;
F_2 ( & V_1 -> V_6 ) ;
V_5 = F_7 ( V_1 , V_2 , V_11 ) ;
if ( V_5 < 0 )
F_3 ( V_1 -> V_8 , L_3 , V_2 ) ;
F_4 ( & V_1 -> V_6 ) ;
return V_5 ;
}
int F_10 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = V_1 -> V_8 -> V_14 ;
struct V_15 * V_16 ;
int V_17 , V_18 , V_19 ;
V_16 = F_11 ( sizeof( struct V_15 ) , V_20 ) ;
if ( V_16 == NULL )
return - V_21 ;
F_12 ( & V_1 -> V_6 ) ;
F_13 ( V_1 -> V_8 , V_1 ) ;
V_18 = ( V_13 -> V_22 << 0 |
V_13 -> V_23 << 1 |
V_13 -> V_24 << 2 |
V_13 -> V_25 << 3 ) ;
if ( V_18 ) {
V_1 -> V_7 ( V_1 , V_26 , 1 , & V_19 ) ;
V_18 |= V_19 ;
V_1 -> V_10 ( V_1 , V_26 , 1 , & V_18 ) ;
}
V_17 = F_14 ( V_1 -> V_8 , - 1 ,
V_27 , F_15 ( V_27 ) ,
NULL , 0 , NULL ) ;
if ( V_17 < 0 )
goto V_5;
V_16 -> V_28 = V_13 -> V_28 ;
V_16 -> V_29 = V_13 -> V_29 ;
V_17 = F_16 ( V_1 , V_16 -> V_28 , V_16 ) ;
if ( V_17 < 0 )
goto V_5;
F_17 ( V_16 ) ;
return V_17 ;
V_5:
F_17 ( V_16 ) ;
F_18 ( V_1 -> V_8 ) ;
F_17 ( V_1 ) ;
return V_17 ;
}
void F_19 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_8 ) ;
F_17 ( V_1 ) ;
}
