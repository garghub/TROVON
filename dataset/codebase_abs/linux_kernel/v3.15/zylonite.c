static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 )
F_2 ( V_2 -> V_4 , 0 , 0 ,
F_3 ( V_5 ) , 0 ) ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_2 = V_7 -> V_10 ;
struct V_11 * V_4 = V_2 -> V_4 ;
struct V_11 * V_12 = V_2 -> V_12 ;
unsigned int V_13 = 0 ;
unsigned int V_14 = 0 ;
int V_15 = 0 ;
int V_16 = F_5 ( V_9 ) ;
int V_17 = F_6 ( F_7 ( V_9 ) ) ;
switch ( V_16 ) {
case 8000 :
V_14 = 12 ;
break;
case 16000 :
V_14 = 6 ;
break;
case 48000 :
V_14 = 2 ;
break;
default:
return - V_18 ;
}
V_13 = V_16 * ( V_17 + 1 ) * 8 ;
V_15 = F_8 ( V_12 , V_19 , 0 , 1 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_2 ( V_12 , 0 , 0 , 0 , V_13 ) ;
if ( V_15 < 0 )
return V_15 ;
if ( V_3 )
V_15 = F_9 ( V_4 , V_20 ,
F_10 ( V_14 ) ) ;
else
V_15 = F_9 ( V_4 , V_21 ,
F_10 ( V_14 ) ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_11 ( V_4 , V_22 |
V_23 | V_24 ) ;
if ( V_15 < 0 )
return V_15 ;
V_15 = F_11 ( V_12 , V_22 |
V_23 | V_24 ) ;
if ( V_15 < 0 )
return V_15 ;
return 0 ;
}
static int F_12 ( struct V_25 * V_26 )
{
int V_15 ;
if ( V_3 ) {
V_5 = F_13 ( NULL , L_1 ) ;
if ( F_14 ( V_5 ) ) {
F_15 ( V_26 -> V_27 , L_2 ,
F_16 ( V_5 ) ) ;
return F_16 ( V_5 ) ;
}
V_15 = F_17 ( V_5 ) ;
if ( V_15 != 0 ) {
F_15 ( V_26 -> V_27 , L_3 ,
V_15 ) ;
F_18 ( V_5 ) ;
return V_15 ;
}
F_19 ( V_26 -> V_27 , L_4 ,
F_3 ( V_5 ) ) ;
}
return 0 ;
}
static int F_20 ( struct V_25 * V_26 )
{
if ( V_3 ) {
F_21 ( V_5 ) ;
F_18 ( V_5 ) ;
}
return 0 ;
}
static int F_22 ( struct V_25 * V_26 )
{
if ( V_3 )
F_21 ( V_5 ) ;
return 0 ;
}
static int F_23 ( struct V_25 * V_26 )
{
int V_15 = 0 ;
if ( V_3 ) {
V_15 = F_17 ( V_5 ) ;
if ( V_15 != 0 )
F_15 ( V_26 -> V_27 , L_3 ,
V_15 ) ;
}
return V_15 ;
}
static int T_1 F_24 ( void )
{
int V_15 ;
V_28 = F_25 ( L_5 , - 1 ) ;
if ( ! V_28 )
return - V_29 ;
F_26 ( V_28 , & V_30 ) ;
V_15 = F_27 ( V_28 ) ;
if ( V_15 != 0 )
F_28 ( V_28 ) ;
return V_15 ;
}
static void T_2 F_29 ( void )
{
F_30 ( V_28 ) ;
}
