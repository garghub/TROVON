static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_6 = 0 ;
int V_7 ;
switch ( V_3 & V_8 ) {
case V_9 :
break;
case V_10 :
V_6 |= V_11 ;
break;
case V_12 :
V_6 |= V_11 | V_13 ;
break;
default:
F_2 ( V_5 -> V_14 , L_1 ) ;
return - V_15 ;
}
if ( ( V_3 & V_16 ) != V_17 )
return - V_15 ;
V_7 = F_3 ( V_5 , V_18 ,
V_11 | V_13 ,
V_6 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_4 ( struct V_19 * V_20 ,
struct V_21 * V_22 ,
struct V_1 * V_23 )
{
struct V_24 * V_25 = V_20 -> V_26 ;
struct V_4 * V_5 = V_25 -> V_5 ;
int V_6 = 0 ;
V_6 |= V_27 ;
F_5 ( V_5 , F_6 ( 0 ) , V_6 ) ;
V_6 = 0 ;
switch ( F_7 ( V_22 ) ) {
case 44100 :
V_6 |= V_28 ;
break;
case 48000 :
V_6 |= V_29 ;
break;
case 32000 :
V_6 |= V_30 ;
break;
default:
F_2 ( V_5 -> V_14 , L_2 ) ;
return - V_15 ;
}
return F_5 ( V_5 , F_6 ( 3 ) , V_6 ) ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_31 * V_32 = F_9 ( V_5 ) ;
int V_7 ;
V_5 -> V_33 = V_32 -> V_34 ;
V_7 = F_10 ( V_5 , 8 , 8 , V_35 ) ;
if ( V_7 != 0 )
return V_7 ;
V_7 = F_3 ( V_5 , V_18 ,
V_36 | V_37 ,
V_36 | V_37 ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_3 ( V_5 , V_38 ,
V_39 , V_39 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_5 )
{
F_3 ( V_5 , V_18 ,
V_36 | V_37 , 0 ) ;
return 0 ;
}
static int F_12 ( struct V_40 * V_41 )
{
struct V_31 * V_32 ;
unsigned int V_6 ;
int V_7 ;
V_41 -> V_42 = 8 ;
V_41 -> V_43 = V_44 ;
V_7 = F_13 ( V_41 ) ;
if ( V_7 < 0 )
return V_7 ;
V_32 = F_14 ( & V_41 -> V_14 , sizeof( struct V_31 ) ,
V_45 ) ;
if ( V_32 == NULL )
return - V_46 ;
V_32 -> V_34 = F_15 ( V_41 , & V_47 ) ;
if ( F_16 ( V_32 -> V_34 ) ) {
V_7 = F_17 ( V_32 -> V_34 ) ;
return V_7 ;
}
V_7 = F_18 ( V_32 -> V_34 , V_48 , & V_6 ) ;
if ( V_7 != 0 )
goto V_49;
if ( V_6 != V_50 ) {
V_7 = - V_51 ;
goto V_49;
}
F_19 ( V_41 , V_32 ) ;
V_7 = F_20 ( & V_41 -> V_14 ,
& V_52 , & V_53 , 1 ) ;
if ( V_7 != 0 )
goto V_49;
return 0 ;
V_49:
F_21 ( V_32 -> V_34 ) ;
return V_7 ;
}
static int T_1 F_22 ( struct V_40 * V_41 )
{
struct V_31 * V_54 = F_23 ( V_41 ) ;
F_21 ( V_54 -> V_34 ) ;
F_24 ( & V_41 -> V_14 ) ;
return 0 ;
}
