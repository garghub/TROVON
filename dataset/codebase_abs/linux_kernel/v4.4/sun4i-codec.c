static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_5 ) ,
F_3 ( V_5 ) ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_6 ) ,
F_3 ( V_6 ) ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_6 ) ,
0 ) ;
}
static int F_5 ( struct V_7 * V_8 , int V_9 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_1 * V_2 = F_6 ( V_13 -> V_15 ) ;
if ( V_8 -> V_16 != V_17 )
return - V_18 ;
switch ( V_9 ) {
case V_19 :
case V_20 :
case V_21 :
F_1 ( V_2 ) ;
break;
case V_22 :
case V_23 :
case V_24 :
F_4 ( V_2 ) ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_1 * V_2 = F_6 ( V_13 -> V_15 ) ;
T_1 V_26 ;
if ( V_8 -> V_16 != V_17 )
return - V_18 ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_5 ) ,
F_3 ( V_5 ) ) ;
F_2 ( V_2 -> V_3 , V_4 ,
0x3f << V_27 ,
0xf << V_27 ) ;
if ( V_8 -> V_28 -> V_29 > 32000 )
V_26 = 0 ;
else
V_26 = F_3 ( V_30 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_30 ) ,
V_26 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_31 ) ,
0 ) ;
return 0 ;
}
static unsigned long F_8 ( struct V_32 * V_33 )
{
unsigned int V_29 = F_9 ( V_33 ) ;
switch ( V_29 ) {
case 176400 :
case 88200 :
case 44100 :
case 33075 :
case 22050 :
case 14700 :
case 11025 :
case 7350 :
return 22579200 ;
case 192000 :
case 96000 :
case 48000 :
case 32000 :
case 24000 :
case 16000 :
case 12000 :
case 8000 :
return 24576000 ;
default:
return 0 ;
}
}
static int F_10 ( struct V_32 * V_33 )
{
unsigned int V_29 = F_9 ( V_33 ) ;
switch ( V_29 ) {
case 192000 :
case 176400 :
return 6 ;
case 96000 :
case 88200 :
return 7 ;
case 48000 :
case 44100 :
return 0 ;
case 32000 :
case 33075 :
return 1 ;
case 24000 :
case 22050 :
return 2 ;
case 16000 :
case 14700 :
return 3 ;
case 12000 :
case 11025 :
return 4 ;
case 8000 :
case 7350 :
return 5 ;
default:
return - V_25 ;
}
}
static int F_11 ( struct V_7 * V_8 ,
struct V_32 * V_33 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_1 * V_2 = F_6 ( V_13 -> V_15 ) ;
unsigned long V_34 ;
int V_35 , V_36 ;
T_1 V_26 ;
if ( V_8 -> V_16 != V_17 )
return - V_18 ;
V_34 = F_8 ( V_33 ) ;
if ( ! V_34 )
return - V_25 ;
V_35 = F_12 ( V_2 -> V_37 , V_34 ) ;
if ( V_35 )
return V_35 ;
V_36 = F_10 ( V_33 ) ;
if ( V_36 < 0 )
return V_36 ;
F_2 ( V_2 -> V_3 , V_4 ,
7 << V_38 ,
V_36 << V_38 ) ;
if ( F_13 ( V_33 ) == 1 )
V_26 = F_3 ( V_39 ) ;
else
V_26 = 0 ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_39 ) ,
V_26 ) ;
if ( F_14 ( V_33 , V_40 ) -> V_41 == 32 ) {
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_42 ) ,
F_3 ( V_42 ) ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_43 ) ,
0 ) ;
V_2 -> V_44 . V_45 = V_46 ;
} else {
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_42 ) ,
0 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
F_3 ( V_43 ) ,
F_3 ( V_43 ) ) ;
V_2 -> V_44 . V_45 = V_47 ;
}
return 0 ;
}
static int F_15 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_1 * V_2 = F_6 ( V_13 -> V_15 ) ;
F_2 ( V_2 -> V_3 , V_4 ,
3 << V_48 ,
3 << V_48 ) ;
return F_16 ( V_2 -> V_37 ) ;
}
static void F_17 ( struct V_7 * V_8 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = V_8 -> V_14 ;
struct V_1 * V_2 = F_6 ( V_13 -> V_15 ) ;
F_18 ( V_2 -> V_37 ) ;
}
static int F_19 ( struct V_10 * V_11 )
{
struct V_49 * V_15 = F_20 ( V_11 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_21 ( V_11 , & V_2 -> V_44 ,
NULL ) ;
return 0 ;
}
static struct V_50 * F_22 ( struct V_51 * V_52 ,
int * V_53 )
{
struct V_50 * V_54 = F_23 ( V_52 , sizeof( * V_54 ) ,
V_55 ) ;
if ( ! V_54 )
return NULL ;
V_54 -> V_56 = L_1 ;
V_54 -> V_57 = L_2 ;
V_54 -> V_58 = L_3 ;
V_54 -> V_59 = F_24 ( V_52 ) ;
V_54 -> V_60 = F_24 ( V_52 ) ;
V_54 -> V_61 = F_24 ( V_52 ) ;
V_54 -> V_62 = V_63 ;
* V_53 = 1 ;
return V_54 ;
}
static struct V_49 * F_25 ( struct V_51 * V_52 )
{
struct V_49 * V_15 ;
V_15 = F_23 ( V_52 , sizeof( * V_15 ) , V_55 ) ;
if ( ! V_15 )
return NULL ;
V_15 -> V_64 = F_22 ( V_52 , & V_15 -> V_53 ) ;
if ( ! V_15 -> V_64 )
return NULL ;
V_15 -> V_52 = V_52 ;
V_15 -> V_56 = L_4 ;
return V_15 ;
}
static int F_26 ( struct V_65 * V_66 )
{
struct V_49 * V_15 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
void T_2 * V_69 ;
int V_35 ;
V_2 = F_23 ( & V_66 -> V_52 , sizeof( * V_2 ) , V_55 ) ;
if ( ! V_2 )
return - V_70 ;
V_2 -> V_52 = & V_66 -> V_52 ;
V_68 = F_27 ( V_66 , V_71 , 0 ) ;
V_69 = F_28 ( & V_66 -> V_52 , V_68 ) ;
if ( F_29 ( V_69 ) ) {
F_30 ( & V_66 -> V_52 , L_5 ) ;
return F_31 ( V_69 ) ;
}
V_2 -> V_3 = F_32 ( & V_66 -> V_52 , V_69 ,
& V_72 ) ;
if ( F_29 ( V_2 -> V_3 ) ) {
F_30 ( & V_66 -> V_52 , L_6 ) ;
return F_31 ( V_2 -> V_3 ) ;
}
V_2 -> V_73 = F_33 ( & V_66 -> V_52 , L_7 ) ;
if ( F_29 ( V_2 -> V_73 ) ) {
F_30 ( & V_66 -> V_52 , L_8 ) ;
return F_31 ( V_2 -> V_73 ) ;
}
V_2 -> V_37 = F_33 ( & V_66 -> V_52 , L_9 ) ;
if ( F_29 ( V_2 -> V_37 ) ) {
F_30 ( & V_66 -> V_52 , L_10 ) ;
return F_31 ( V_2 -> V_37 ) ;
}
if ( F_16 ( V_2 -> V_73 ) ) {
F_30 ( & V_66 -> V_52 , L_11 ) ;
return - V_25 ;
}
V_2 -> V_44 . V_74 = V_68 -> V_75 + V_76 ;
V_2 -> V_44 . V_77 = 4 ;
V_2 -> V_44 . V_45 = V_47 ;
V_35 = F_34 ( & V_66 -> V_52 , & V_78 ,
& V_79 , 1 ) ;
if ( V_35 ) {
F_30 ( & V_66 -> V_52 , L_12 ) ;
goto V_80;
}
V_35 = F_35 ( & V_66 -> V_52 ,
& V_81 ,
& V_82 , 1 ) ;
if ( V_35 ) {
F_30 ( & V_66 -> V_52 , L_13 ) ;
goto V_83;
}
V_35 = F_36 ( & V_66 -> V_52 , NULL , 0 ) ;
if ( V_35 ) {
F_30 ( & V_66 -> V_52 , L_14 ) ;
goto V_83;
}
V_15 = F_25 ( & V_66 -> V_52 ) ;
if ( ! V_15 ) {
F_30 ( & V_66 -> V_52 , L_15 ) ;
goto V_83;
}
F_37 ( V_66 , V_15 ) ;
F_38 ( V_15 , V_2 ) ;
V_35 = F_39 ( V_15 ) ;
if ( V_35 ) {
F_30 ( & V_66 -> V_52 , L_16 ) ;
goto V_83;
}
return 0 ;
V_83:
F_40 ( & V_66 -> V_52 ) ;
V_80:
F_18 ( V_2 -> V_73 ) ;
return V_35 ;
}
static int F_41 ( struct V_65 * V_66 )
{
struct V_49 * V_15 = F_42 ( V_66 ) ;
struct V_1 * V_2 = F_6 ( V_15 ) ;
F_43 ( V_15 ) ;
F_40 ( & V_66 -> V_52 ) ;
F_18 ( V_2 -> V_73 ) ;
return 0 ;
}
