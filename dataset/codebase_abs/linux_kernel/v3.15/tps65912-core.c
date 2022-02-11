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
struct V_12 * V_13 = F_11 ( V_1 -> V_8 ) ;
struct V_14 * V_15 ;
int V_16 , V_17 , V_18 ;
V_15 = F_12 ( sizeof( struct V_14 ) , V_19 ) ;
if ( V_15 == NULL )
return - V_20 ;
F_13 ( & V_1 -> V_6 ) ;
F_14 ( V_1 -> V_8 , V_1 ) ;
V_17 = ( V_13 -> V_21 << 0 |
V_13 -> V_22 << 1 |
V_13 -> V_23 << 2 |
V_13 -> V_24 << 3 ) ;
if ( V_17 ) {
V_1 -> V_7 ( V_1 , V_25 , 1 , & V_18 ) ;
V_17 |= V_18 ;
V_1 -> V_10 ( V_1 , V_25 , 1 , & V_17 ) ;
}
V_16 = F_15 ( V_1 -> V_8 , - 1 ,
V_26 , F_16 ( V_26 ) ,
NULL , 0 , NULL ) ;
if ( V_16 < 0 )
goto V_5;
V_15 -> V_27 = V_13 -> V_27 ;
V_15 -> V_28 = V_13 -> V_28 ;
V_16 = F_17 ( V_1 , V_15 -> V_27 , V_15 ) ;
if ( V_16 < 0 )
goto V_5;
F_18 ( V_15 ) ;
return V_16 ;
V_5:
F_18 ( V_15 ) ;
F_19 ( V_1 -> V_8 ) ;
return V_16 ;
}
void F_20 ( struct V_1 * V_1 )
{
F_19 ( V_1 -> V_8 ) ;
F_21 ( V_1 ) ;
}
