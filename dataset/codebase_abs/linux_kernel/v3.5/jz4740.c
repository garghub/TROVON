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
struct V_1 * V_2 = V_14 -> V_2 ;
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
return - V_15 ;
}
V_6 <<= V_16 ;
F_8 ( V_2 , V_17 ,
V_18 , V_6 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_19 ;
T_2 * V_7 = V_2 -> V_8 ;
F_8 ( V_2 , V_20 ,
V_21 , V_21 ) ;
F_10 ( 2 ) ;
F_8 ( V_2 , V_20 ,
V_22 | V_21 , 0 ) ;
for ( V_19 = 0 ; V_19 < F_11 ( V_23 ) ; ++ V_19 )
F_4 ( V_2 , V_19 , V_7 [ V_19 ] ) ;
}
static int F_12 ( struct V_1 * V_2 ,
enum V_24 V_25 )
{
unsigned int V_26 ;
unsigned int V_27 ;
switch ( V_25 ) {
case V_28 :
break;
case V_29 :
V_26 = V_30 |
V_31 |
V_32 ;
V_27 = 0 ;
F_8 ( V_2 , V_20 , V_26 , V_27 ) ;
break;
case V_33 :
if ( V_2 -> V_34 . V_35 == V_36 )
F_9 ( V_2 ) ;
V_26 = V_30 |
V_31 |
V_32 ;
V_27 = V_30 |
V_31 |
V_32 ;
F_8 ( V_2 , V_20 , V_26 , V_27 ) ;
break;
case V_36 :
V_26 = V_22 ;
V_27 = V_22 ;
F_8 ( V_2 , V_20 , V_26 , V_27 ) ;
break;
default:
break;
}
V_2 -> V_34 . V_35 = V_25 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
F_8 ( V_2 , V_20 ,
V_37 , V_37 ) ;
F_12 ( V_2 , V_33 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 )
{
F_12 ( V_2 , V_36 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_36 ) ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_12 ( V_2 , V_33 ) ;
}
static int T_3 F_17 ( struct V_38 * V_39 )
{
int V_40 ;
struct V_4 * V_4 ;
struct V_41 * V_42 ;
V_4 = F_18 ( & V_39 -> V_43 , sizeof( * V_4 ) ,
V_44 ) ;
if ( ! V_4 )
return - V_45 ;
V_42 = F_19 ( V_39 , V_46 , 0 ) ;
if ( ! V_42 ) {
F_20 ( & V_39 -> V_43 , L_1 ) ;
V_40 = - V_47 ;
goto V_48;
}
V_42 = F_21 ( V_42 -> V_49 , F_22 ( V_42 ) , V_39 -> V_50 ) ;
if ( ! V_42 ) {
F_20 ( & V_39 -> V_43 , L_2 ) ;
V_40 = - V_51 ;
goto V_48;
}
V_4 -> V_5 = F_23 ( V_42 -> V_49 , F_22 ( V_42 ) ) ;
if ( ! V_4 -> V_5 ) {
F_20 ( & V_39 -> V_43 , L_3 ) ;
V_40 = - V_51 ;
goto V_52;
}
V_4 -> V_42 = V_42 ;
F_24 ( V_39 , V_4 ) ;
V_40 = F_25 ( & V_39 -> V_43 ,
& V_53 , & V_54 , 1 ) ;
if ( V_40 ) {
F_20 ( & V_39 -> V_43 , L_4 ) ;
goto V_55;
}
return 0 ;
V_55:
F_26 ( V_4 -> V_5 ) ;
V_52:
F_27 ( V_42 -> V_49 , F_22 ( V_42 ) ) ;
V_48:
return V_40 ;
}
static int T_4 F_28 ( struct V_38 * V_39 )
{
struct V_4 * V_4 = F_29 ( V_39 ) ;
struct V_41 * V_42 = V_4 -> V_42 ;
F_30 ( & V_39 -> V_43 ) ;
F_26 ( V_4 -> V_5 ) ;
F_27 ( V_42 -> V_49 , F_22 ( V_42 ) ) ;
F_24 ( V_39 , NULL ) ;
return 0 ;
}
