static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_6 , V_8 ,
V_9 ,
V_10 ,
V_4 -> V_11 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_1 , V_7 ) ;
return V_7 ;
}
V_7 = F_3 ( V_6 , V_13 ,
V_9 ,
V_10 ,
V_4 -> V_11 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_2 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_6 , V_14 ,
V_15 ,
V_4 -> V_11 ,
V_16 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_3 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_6 , V_13 , 0 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_4 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_6 , V_14 ,
V_15 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_5 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_7 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_5 * V_6 = V_22 -> V_6 ;
struct V_3 * V_4 = F_2 ( V_22 -> V_2 ) ;
switch ( F_8 ( V_20 ) ) {
case 4000 :
case 8000 :
case 12000 :
case 16000 :
case 24000 :
case 32000 :
case 48000 :
case 96000 :
case 192000 :
V_4 -> V_11 = 147456000U ;
break;
case 11025 :
case 22050 :
case 44100 :
case 88200 :
case 176400 :
V_4 -> V_11 = 135475200U ;
break;
default:
F_4 ( V_6 -> V_12 , L_6 ,
F_8 ( V_20 ) ) ;
return - V_24 ;
}
return F_1 ( V_22 -> V_2 ) ;
}
static int F_9 ( struct V_17 * V_18 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_5 * V_6 = V_22 -> V_6 ;
unsigned int V_25 ;
int V_7 ;
switch ( F_8 ( V_20 ) ) {
case 8000 :
case 12000 :
case 16000 :
V_25 = 49152000U ;
break;
case 11025 :
V_25 = 45158400U ;
break;
default:
F_4 ( V_6 -> V_12 , L_6 ,
F_8 ( V_20 ) ) ;
return - V_24 ;
}
V_7 = F_3 ( V_6 , V_26 ,
V_9 ,
V_10 ,
V_25 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_7 , V_7 ) ;
return V_7 ;
}
V_7 = F_3 ( V_6 , V_27 ,
V_9 ,
V_10 ,
V_25 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_8 , V_7 ) ;
return V_7 ;
}
V_7 = F_5 ( V_6 , V_28 ,
V_29 ,
V_25 ,
V_16 ) ;
if ( V_7 < 0 ) {
F_4 ( V_6 -> V_12 , L_9 , V_7 ) ;
return V_7 ;
}
return 0 ;
}
static int F_10 ( struct V_17 * V_18 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_5 * V_6 = V_22 -> V_6 ;
int V_7 ;
V_7 = F_3 ( V_6 , V_27 , V_9 ,
0 , 0 ) ;
if ( V_7 < 0 )
F_4 ( V_6 -> V_12 , L_10 , V_7 ) ;
return V_7 ;
}
static int F_11 ( struct V_30 * V_31 ,
struct V_32 * V_33 , int V_34 )
{
struct V_1 * V_2 = V_31 -> V_35 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
switch ( V_34 ) {
case V_36 :
F_12 ( V_4 -> V_37 , 1 ) ;
break;
case V_38 :
F_12 ( V_4 -> V_37 , 0 ) ;
break;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_39 * V_35 ,
enum V_40 V_41 )
{
struct V_21 * V_22 ;
V_22 = F_14 ( V_2 , V_2 -> V_42 [ 0 ] . V_43 ) ;
if ( V_35 -> V_12 != V_22 -> V_44 -> V_12 )
return 0 ;
switch ( V_41 ) {
case V_45 :
if ( V_2 -> V_35 . V_46 == V_47 )
F_1 ( V_2 ) ;
break;
case V_47 :
F_6 ( V_2 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_48 V_49 = { 0 } ;
unsigned int V_50 [] = { 0 , 1 } ;
struct V_51 * V_52 ;
struct V_21 * V_22 ;
struct V_51 * V_53 ;
struct V_51 * V_54 ;
int V_7 ;
V_22 = F_14 ( V_2 , V_2 -> V_42 [ V_55 ] . V_43 ) ;
V_53 = V_22 -> V_44 ;
V_4 -> V_6 = V_22 -> V_6 ;
V_7 = F_16 ( V_53 , V_14 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_53 -> V_12 , L_11 , V_7 ) ;
return V_7 ;
}
V_22 = F_14 ( V_2 , V_2 -> V_42 [ V_56 ] . V_43 ) ;
V_54 = V_22 -> V_44 ;
V_7 = F_16 ( V_54 , V_28 , 0 , 0 ) ;
if ( V_7 < 0 ) {
F_4 ( V_54 -> V_12 , L_12 , V_7 ) ;
return V_7 ;
}
V_49 . V_57 = V_58 . V_59 ;
V_52 = F_17 ( & V_49 ) ;
if ( ! V_52 )
return - V_60 ;
V_7 = F_18 ( V_52 , F_19 ( V_50 ) ,
V_50 , 0 , NULL ) ;
if ( V_7 < 0 )
return V_7 ;
V_7 = F_20 ( V_52 , 0x3 , 0x0 , 2 , 16 ) ;
if ( V_7 < 0 )
return V_7 ;
return 0 ;
}
static int F_21 ( struct V_61 * V_62 )
{
struct V_63 * V_12 = & V_62 -> V_12 ;
struct V_1 * V_2 = & V_64 ;
struct V_3 * V_4 ;
struct V_65 * V_66 , * V_67 ;
int V_7 , V_68 ;
V_4 = F_22 ( V_12 , sizeof( * V_4 ) , V_69 ) ;
if ( ! V_4 )
return - V_70 ;
F_23 ( V_2 , V_4 ) ;
V_2 -> V_12 = V_12 ;
V_4 -> V_37 = F_24 ( V_12 , L_13 ,
V_71 ) ;
if ( F_25 ( V_4 -> V_37 ) ) {
F_4 ( V_12 , L_14 ) ;
return F_26 ( V_4 -> V_37 ) ;
}
V_7 = F_27 ( V_2 , L_15 ) ;
if ( V_7 < 0 ) {
F_4 ( V_12 , L_16 ) ;
return V_7 ;
}
V_7 = F_28 ( V_2 , L_17 ) ;
if ( V_7 < 0 ) {
F_4 ( V_12 , L_18 ) ;
return V_7 ;
}
V_2 -> V_72 [ 0 ] . V_59 = F_29 ( V_12 -> V_57 ,
L_19 , 0 ) ;
if ( ! V_2 -> V_72 [ 0 ] . V_59 ) {
F_4 ( V_12 , L_20 ) ;
return - V_24 ;
}
V_66 = F_29 ( V_12 -> V_57 , L_21 , 0 ) ;
if ( ! V_66 ) {
F_4 ( V_12 , L_22 ) ;
V_7 = - V_24 ;
goto V_73;
}
V_67 = F_29 ( V_12 -> V_57 , L_23 , 0 ) ;
if ( ! V_67 ) {
F_4 ( V_12 , L_24 ) ;
V_7 = - V_24 ;
goto V_74;
}
for ( V_68 = 0 ; V_68 < V_2 -> V_75 ; V_68 ++ ) {
V_2 -> V_42 [ V_68 ] . V_76 = NULL ;
V_2 -> V_42 [ V_68 ] . V_77 = NULL ;
V_2 -> V_42 [ V_68 ] . V_78 = NULL ;
V_2 -> V_42 [ V_68 ] . V_59 = V_67 ;
V_2 -> V_42 [ V_68 ] . V_79 = V_66 ;
V_2 -> V_42 [ V_68 ] . V_80 = V_66 ;
}
V_7 = F_30 ( V_12 , & V_81 ,
V_82 , F_19 ( V_82 ) ) ;
if ( V_7 < 0 ) {
F_4 ( V_12 , L_25 , V_7 ) ;
goto V_83;
}
V_7 = F_31 ( V_12 , V_2 ) ;
if ( V_7 < 0 ) {
F_4 ( V_12 , L_26 , V_7 ) ;
goto V_83;
}
V_83:
F_32 ( V_67 ) ;
V_74:
F_32 ( V_66 ) ;
V_73:
F_32 ( V_2 -> V_72 [ 0 ] . V_59 ) ;
return V_7 ;
}
static int F_33 ( struct V_63 * V_12 )
{
struct V_1 * V_2 = F_34 ( V_12 ) ;
return F_6 ( V_2 ) ;
}
static void F_35 ( struct V_63 * V_12 )
{
struct V_1 * V_2 = F_34 ( V_12 ) ;
F_1 ( V_2 ) ;
}
