static inline T_1 F_1 ( T_2 V_1 , T_2 V_2 , T_2 V_3 )
{
return ( V_1 << 24 ) | ( V_2 << 16 ) | ( V_3 << 8 ) | V_4 ;
}
static int F_2 ( T_1 V_5 , T_1 V_6 , T_1 * V_7 )
{
int V_8 ;
if ( ! V_9 )
return - V_10 ;
if ( V_5 ) {
V_8 = F_3 ( V_9 ,
V_11 , V_5 ) ;
if ( V_8 < 0 )
goto V_12;
}
V_8 = F_3 ( V_9 ,
V_13 , V_6 ) ;
if ( V_8 < 0 )
goto V_12;
V_8 = F_4 ( V_9 ,
V_14 , V_7 ) ;
if ( V_8 < 0 )
goto V_12;
return 0 ;
V_12:
F_5 ( & V_9 -> V_15 , L_1 ,
V_8 ) ;
return V_8 ;
}
static int F_6 ( T_1 V_5 , T_1 V_6 , T_1 V_7 )
{
int V_8 ;
if ( ! V_9 )
return - V_10 ;
V_8 = F_3 ( V_9 ,
V_14 , V_7 ) ;
if ( V_8 < 0 )
goto V_16;
if ( V_5 ) {
V_8 = F_3 ( V_9 ,
V_11 , V_5 ) ;
if ( V_8 < 0 )
goto V_16;
}
V_8 = F_3 ( V_9 ,
V_13 , V_6 ) ;
if ( V_8 < 0 )
goto V_16;
return 0 ;
V_16:
F_5 ( & V_9 -> V_15 , L_1 ,
V_8 ) ;
return V_8 ;
}
int F_7 ( T_2 V_2 , T_2 V_17 , T_1 V_3 , T_1 * V_7 )
{
T_1 V_6 , V_5 ;
unsigned long V_18 ;
int V_19 ;
F_8 ( V_2 == V_20 ) ;
V_6 = F_1 ( V_17 , V_2 , V_3 & V_21 ) ;
V_5 = V_3 & V_22 ;
F_9 ( & V_23 , V_18 ) ;
V_19 = F_2 ( V_5 , V_6 , V_7 ) ;
F_10 ( & V_23 , V_18 ) ;
return V_19 ;
}
int F_11 ( T_2 V_2 , T_2 V_17 , T_1 V_3 , T_1 V_7 )
{
T_1 V_6 , V_5 ;
unsigned long V_18 ;
int V_19 ;
F_8 ( V_2 == V_20 ) ;
V_6 = F_1 ( V_17 , V_2 , V_3 & V_21 ) ;
V_5 = V_3 & V_22 ;
F_9 ( & V_23 , V_18 ) ;
V_19 = F_6 ( V_5 , V_6 , V_7 ) ;
F_10 ( & V_23 , V_18 ) ;
return V_19 ;
}
int F_12 ( T_2 V_2 , T_2 V_17 , T_1 V_3 , T_1 V_7 , T_1 V_24 )
{
T_1 V_6 , V_5 ;
T_1 V_25 ;
unsigned long V_18 ;
int V_19 ;
F_8 ( V_2 == V_20 ) ;
V_6 = F_1 ( V_17 , V_2 , V_3 & V_21 ) ;
V_5 = V_3 & V_22 ;
F_9 ( & V_23 , V_18 ) ;
V_19 = F_2 ( V_5 , V_6 & V_26 , & V_25 ) ;
if ( V_19 < 0 ) {
F_10 ( & V_23 , V_18 ) ;
return V_19 ;
}
V_25 &= ~ V_24 ;
V_7 &= V_24 ;
V_25 |= V_7 ;
V_19 = F_6 ( V_5 , V_6 | V_27 , V_25 ) ;
F_10 ( & V_23 , V_18 ) ;
return V_19 ;
}
static int F_13 ( struct V_28 * V_29 ,
const struct V_30 * V_31 )
{
int V_19 ;
V_19 = F_14 ( V_29 ) ;
if ( V_19 < 0 ) {
F_5 ( & V_29 -> V_15 , L_2 ) ;
return V_19 ;
}
V_9 = F_15 ( V_29 ) ;
return 0 ;
}
static int T_3 F_16 ( void )
{
return F_17 ( & V_32 ) ;
}
static void T_4 F_18 ( void )
{
F_19 ( & V_32 ) ;
if ( V_9 ) {
F_20 ( V_9 ) ;
V_9 = NULL ;
}
}
