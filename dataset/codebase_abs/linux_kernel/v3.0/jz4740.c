static unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
return F_3 ( V_4 -> V_5 + ( V_3 << 2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_6 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
T_1 * V_7 = V_2 -> V_8 ;
V_7 [ V_3 ] = V_6 ;
F_5 ( V_6 , V_4 -> V_5 + ( V_3 << 2 ) ) ;
return 0 ;
}
static int F_6 ( struct V_9 * V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
T_2 V_6 ;
struct V_15 * V_16 = V_10 -> V_17 ;
struct V_1 * V_2 = V_16 -> V_2 ;
switch ( F_7 ( V_12 ) ) {
case 8000 :
V_6 = 0 ;
break;
case 11025 :
V_6 = 1 ;
break;
case 12000 :
V_6 = 2 ;
break;
case 16000 :
V_6 = 3 ;
break;
case 22050 :
V_6 = 4 ;
break;
case 24000 :
V_6 = 5 ;
break;
case 32000 :
V_6 = 6 ;
break;
case 44100 :
V_6 = 7 ;
break;
case 48000 :
V_6 = 8 ;
break;
default:
return - V_18 ;
}
V_6 <<= V_19 ;
F_8 ( V_2 , V_20 ,
V_21 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_22 ;
T_2 * V_7 = V_2 -> V_8 ;
F_8 ( V_2 , V_23 ,
V_24 , V_24 ) ;
F_10 ( 2 ) ;
F_8 ( V_2 , V_23 ,
V_25 | V_24 , 0 ) ;
for ( V_22 = 0 ; V_22 < F_11 ( V_26 ) ; ++ V_22 )
F_4 ( V_2 , V_22 , V_7 [ V_22 ] ) ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_27 V_28 )
{
unsigned int V_29 ;
unsigned int V_30 ;
switch ( V_28 ) {
case V_31 :
break;
case V_32 :
V_29 = V_33 |
V_34 |
V_35 ;
V_30 = 0 ;
F_8 ( V_2 , V_23 , V_29 , V_30 ) ;
break;
case V_36 :
if ( V_2 -> V_37 . V_38 == V_39 )
F_9 ( V_2 ) ;
V_29 = V_33 |
V_34 |
V_35 ;
V_30 = V_33 |
V_34 |
V_35 ;
F_8 ( V_2 , V_23 , V_29 , V_30 ) ;
break;
case V_39 :
V_29 = V_25 ;
V_30 = V_25 ;
F_8 ( V_2 , V_23 , V_29 , V_30 ) ;
break;
default:
break;
}
V_2 -> V_37 . V_38 = V_28 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_23 ,
V_40 , V_40 ) ;
F_12 ( V_2 , V_36 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_39 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 , T_3 V_41 )
{
return F_12 ( V_2 , V_39 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_36 ) ;
}
static int T_4 F_17 ( struct V_42 * V_43 )
{
int V_44 ;
struct V_4 * V_4 ;
struct V_45 * V_46 ;
V_4 = F_18 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
V_46 = F_19 ( V_43 , V_49 , 0 ) ;
if ( ! V_46 ) {
F_20 ( & V_43 -> V_50 , L_1 ) ;
V_44 = - V_51 ;
goto V_52;
}
V_46 = F_21 ( V_46 -> V_53 , F_22 ( V_46 ) , V_43 -> V_54 ) ;
if ( ! V_46 ) {
F_20 ( & V_43 -> V_50 , L_2 ) ;
V_44 = - V_55 ;
goto V_52;
}
V_4 -> V_5 = F_23 ( V_46 -> V_53 , F_22 ( V_46 ) ) ;
if ( ! V_4 -> V_5 ) {
F_20 ( & V_43 -> V_50 , L_3 ) ;
V_44 = - V_55 ;
goto V_56;
}
V_4 -> V_46 = V_46 ;
F_24 ( V_43 , V_4 ) ;
V_44 = F_25 ( & V_43 -> V_50 ,
& V_57 , & V_58 , 1 ) ;
if ( V_44 ) {
F_20 ( & V_43 -> V_50 , L_4 ) ;
goto V_59;
}
return 0 ;
V_59:
F_26 ( V_4 -> V_5 ) ;
V_56:
F_27 ( V_46 -> V_53 , F_22 ( V_46 ) ) ;
V_52:
F_28 ( V_4 ) ;
return V_44 ;
}
static int T_5 F_29 ( struct V_42 * V_43 )
{
struct V_4 * V_4 = F_30 ( V_43 ) ;
struct V_45 * V_46 = V_4 -> V_46 ;
F_31 ( & V_43 -> V_50 ) ;
F_26 ( V_4 -> V_5 ) ;
F_27 ( V_46 -> V_53 , F_22 ( V_46 ) ) ;
F_24 ( V_43 , NULL ) ;
F_28 ( V_4 ) ;
return 0 ;
}
static int T_6 F_32 ( void )
{
return F_33 ( & V_60 ) ;
}
static void T_7 F_34 ( void )
{
F_35 ( & V_60 ) ;
}
