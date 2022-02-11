static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 , & V_4 ) ;
}
int F_3 ( struct V_5 * V_6 )
{
int V_7 = 0 ;
struct V_1 * V_2 ;
int V_8 ;
F_4 (cap, &capabilities, cap_list) {
V_8 = F_5 ( V_6 , V_2 -> V_9 ) ;
if ( V_8 ) {
F_6 ( & V_6 -> V_6 , L_1 ,
V_2 -> V_9 , V_8 ) ;
V_7 = F_7 ( V_6 ,
V_10 ,
V_8 ) ;
if ( V_7 )
goto V_11;
V_7 = F_7 ( V_6 ,
V_2 -> V_12 ,
V_8 ) ;
if ( V_7 )
goto V_11;
}
}
V_11:
return V_7 ;
}
static int F_8 ( struct V_5 * V_6 , int V_13 , T_1 V_14 ,
void * V_15 )
{
if ( V_14 & V_16 )
return V_17 ;
else
return F_9 ( V_6 , V_13 , V_14 ) ;
}
static int F_10 ( struct V_5 * V_6 , int V_13 , T_1 * V_14 ,
void * V_15 )
{
int V_7 ;
T_1 V_18 ;
V_7 = F_11 ( V_6 , V_13 , & V_18 ) ;
if ( V_7 )
goto V_11;
* V_14 = V_18 & ~ V_19 ;
V_11:
return V_7 ;
}
static int F_12 ( struct V_5 * V_6 , int V_13 , T_1 V_20 ,
void * V_15 )
{
int V_7 ;
T_1 V_21 ;
T_2 V_22 , V_23 ;
V_7 = F_11 ( V_6 , V_13 , & V_21 ) ;
if ( V_7 )
goto V_11;
V_23 = ( T_2 ) ( V_21 & V_24 ) ;
V_22 = ( T_2 ) ( V_20 & V_24 ) ;
V_20 &= V_25 ;
if ( ( V_21 & V_25 ) != V_20 ) {
V_20 = ( V_21 & ~ V_25 ) | V_20 ;
V_7 = F_9 ( V_6 , V_13 , V_20 ) ;
if ( V_7 )
goto V_11;
}
F_6 ( & V_6 -> V_6 , L_2 , V_22 ) ;
V_7 = F_13 ( V_6 , V_22 ) ;
if ( V_7 ) {
V_7 = V_17 ;
goto V_11;
}
V_11:
return V_7 ;
}
static void * F_14 ( struct V_5 * V_6 , int V_13 )
{
int V_7 ;
T_1 V_14 ;
V_7 = F_11 ( V_6 , V_13 , & V_14 ) ;
if ( V_7 )
goto V_11;
if ( V_14 & V_26 ) {
V_14 &= ~ V_26 ;
V_7 = F_9 ( V_6 , V_13 , V_14 ) ;
}
V_11:
return F_15 ( V_7 ) ;
}
int F_16 ( void )
{
F_1 ( & V_27 ) ;
F_1 ( & V_28 ) ;
return 0 ;
}
