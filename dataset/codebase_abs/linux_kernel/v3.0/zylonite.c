static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_6 ;
if ( V_7 )
F_2 ( V_2 -> V_8 , 0 , 0 ,
F_3 ( V_9 ) , 0 ) ;
F_4 ( V_6 , V_10 ,
F_5 ( V_10 ) ) ;
F_6 ( V_6 , V_11 , F_5 ( V_11 ) ) ;
F_7 ( V_6 , L_1 ) ;
F_7 ( V_6 , L_2 ) ;
F_8 ( V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_1 * V_2 = V_13 -> V_16 ;
struct V_17 * V_8 = V_2 -> V_8 ;
struct V_17 * V_18 = V_2 -> V_18 ;
unsigned int V_19 = 0 ;
unsigned int V_20 = 0 ;
int V_21 = 0 ;
int V_22 = F_10 ( V_15 ) ;
int V_23 = F_11 ( F_12 ( V_15 ) ) ;
switch ( V_22 ) {
case 8000 :
V_20 = 12 ;
break;
case 16000 :
V_20 = 6 ;
break;
case 48000 :
V_20 = 2 ;
break;
default:
return - V_24 ;
}
V_19 = V_22 * ( V_23 + 1 ) * 8 ;
V_21 = F_13 ( V_18 , V_25 , 0 , 1 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_2 ( V_18 , 0 , 0 , 0 , V_19 ) ;
if ( V_21 < 0 )
return V_21 ;
if ( V_7 )
V_21 = F_14 ( V_8 , V_26 ,
F_15 ( V_20 ) ) ;
else
V_21 = F_14 ( V_8 , V_27 ,
F_15 ( V_20 ) ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_16 ( V_8 , V_28 |
V_29 | V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
V_21 = F_16 ( V_18 , V_28 |
V_29 | V_30 ) ;
if ( V_21 < 0 )
return V_21 ;
return 0 ;
}
static int F_17 ( struct V_31 * V_32 )
{
int V_21 ;
if ( V_7 ) {
V_9 = F_18 ( NULL , L_3 ) ;
if ( F_19 ( V_9 ) ) {
F_20 ( & V_33 -> V_34 , L_4 ,
F_21 ( V_9 ) ) ;
return F_21 ( V_9 ) ;
}
V_21 = F_22 ( V_9 ) ;
if ( V_21 != 0 ) {
F_20 ( & V_33 -> V_34 , L_5 ,
V_21 ) ;
F_23 ( V_9 ) ;
return V_21 ;
}
F_24 ( & V_33 -> V_34 , L_6 ,
F_3 ( V_9 ) ) ;
}
return 0 ;
}
static int F_25 ( struct V_31 * V_32 )
{
if ( V_7 ) {
F_26 ( V_9 ) ;
F_23 ( V_9 ) ;
}
return 0 ;
}
static int F_27 ( struct V_31 * V_32 )
{
if ( V_7 )
F_26 ( V_9 ) ;
return 0 ;
}
static int F_28 ( struct V_31 * V_32 )
{
int V_21 = 0 ;
if ( V_7 ) {
V_21 = F_22 ( V_9 ) ;
if ( V_21 != 0 )
F_20 ( & V_33 -> V_34 , L_5 ,
V_21 ) ;
}
return V_21 ;
}
static int T_1 F_29 ( void )
{
int V_21 ;
V_35 = F_30 ( L_7 , - 1 ) ;
if ( ! V_35 )
return - V_36 ;
F_31 ( V_35 , & V_37 ) ;
V_21 = F_32 ( V_35 ) ;
if ( V_21 != 0 )
F_33 ( V_35 ) ;
return V_21 ;
}
static void T_2 F_34 ( void )
{
F_35 ( V_35 ) ;
}
