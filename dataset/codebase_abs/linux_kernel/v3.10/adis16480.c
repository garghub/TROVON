static T_1 F_1 ( struct V_1 * V_1 ,
char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_5 = V_1 -> V_6 ;
char V_7 [ 7 ] ;
T_3 V_8 ;
T_5 V_9 ;
int V_10 ;
V_10 = F_2 ( & V_5 -> V_11 , V_12 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
V_8 = F_3 ( V_7 , sizeof( V_7 ) , L_1 , V_9 >> 8 , V_9 & 0xff ) ;
return F_4 ( V_2 , V_3 , V_4 , V_7 , V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_1 ,
char T_2 * V_2 , T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_5 = V_1 -> V_6 ;
T_5 V_13 , V_14 ;
char V_7 [ 12 ] ;
T_3 V_8 ;
int V_10 ;
V_10 = F_2 ( & V_5 -> V_11 , V_15 , & V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_2 ( & V_5 -> V_11 , V_16 , & V_13 ) ;
if ( V_10 < 0 )
return V_10 ;
V_8 = snprintf ( V_7 , sizeof( V_7 ) , L_2 ,
V_13 >> 8 , V_13 & 0xff , V_14 ) ;
return F_4 ( V_2 , V_3 , V_4 , V_7 , V_8 ) ;
}
static int F_6 ( void * V_17 , T_6 * V_18 )
{
struct V_5 * V_5 = V_17 ;
T_5 V_19 ;
int V_10 ;
V_10 = F_2 ( & V_5 -> V_11 , V_20 ,
& V_19 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_18 = V_19 ;
return 0 ;
}
static int F_7 ( void * V_17 , T_6 * V_18 )
{
struct V_5 * V_5 = V_17 ;
T_5 V_21 ;
int V_10 ;
V_10 = F_2 ( & V_5 -> V_11 , V_22 ,
& V_21 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_18 = V_21 ;
return 0 ;
}
static int F_8 ( void * V_17 , T_6 * V_18 )
{
struct V_5 * V_5 = V_17 ;
T_7 V_23 ;
int V_10 ;
V_10 = F_9 ( & V_5 -> V_11 , V_24 ,
& V_23 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_18 = V_23 ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 )
{
struct V_5 * V_5 = F_11 ( V_26 ) ;
F_12 ( L_3 , 0400 ,
V_26 -> V_27 , V_5 ,
& V_28 ) ;
F_12 ( L_4 , 0400 , V_26 -> V_27 ,
V_5 , & V_29 ) ;
F_12 ( L_5 , 0400 , V_26 -> V_27 ,
V_5 , & V_30 ) ;
F_12 ( L_6 , 0400 , V_26 -> V_27 ,
V_5 , & V_31 ) ;
F_12 ( L_7 , 0400 , V_26 -> V_27 ,
V_5 , & V_32 ) ;
return 0 ;
}
static int F_10 ( struct V_25 * V_26 )
{
return 0 ;
}
static int F_13 ( struct V_5 * V_33 , unsigned int V_34 )
{
unsigned int V_35 ;
V_35 = 2460000 / V_34 ;
if ( V_35 > 2048 )
V_35 = 2048 ;
if ( V_35 != 0 )
V_35 -- ;
return F_14 ( & V_33 -> V_11 , V_36 , V_35 ) ;
}
static int F_15 ( struct V_5 * V_33 , unsigned int * V_34 )
{
T_8 V_35 ;
int V_10 ;
V_10 = F_2 ( & V_33 -> V_11 , V_36 , & V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_34 = 2460000 / ( V_35 + 1 ) ;
return 0 ;
}
static T_1 F_16 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
char * V_7 )
{
struct V_25 * V_26 = F_17 ( V_38 ) ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
unsigned int V_34 ;
int V_10 ;
V_10 = F_15 ( V_33 , & V_34 ) ;
if ( V_10 < 0 )
return V_10 ;
return sprintf ( V_7 , L_8 , V_34 / 1000 , V_34 % 1000 ) ;
}
static T_1 F_18 ( struct V_37 * V_38 ,
struct V_39 * V_40 ,
const char * V_7 ,
T_3 V_8 )
{
struct V_25 * V_26 = F_17 ( V_38 ) ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
int V_41 , V_42 ;
long V_18 ;
int V_10 ;
V_10 = F_19 ( V_7 , 100 , & V_41 , & V_42 ) ;
if ( V_10 )
return V_10 ;
V_18 = V_41 * 1000 + V_42 ;
if ( V_18 <= 0 )
return - V_43 ;
V_10 = F_13 ( V_33 , V_18 ) ;
return V_10 ? V_10 : V_8 ;
}
static int F_20 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int V_46 )
{
unsigned int V_47 = V_48 [ V_45 -> V_49 ] ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
switch ( V_45 -> type ) {
case V_50 :
case V_51 :
if ( V_46 < - 0x8000 || V_46 >= 0x8000 )
return - V_43 ;
return F_14 ( & V_33 -> V_11 , V_47 , V_46 ) ;
case V_52 :
case V_53 :
return F_21 ( & V_33 -> V_11 , V_47 , V_46 ) ;
default:
break;
}
return - V_43 ;
}
static int F_22 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int * V_46 )
{
unsigned int V_47 = V_48 [ V_45 -> V_49 ] ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
T_8 V_54 ;
T_9 V_55 ;
int V_10 ;
switch ( V_45 -> type ) {
case V_50 :
case V_51 :
V_10 = F_2 ( & V_33 -> V_11 , V_47 , & V_54 ) ;
* V_46 = F_23 ( V_54 , 15 ) ;
break;
case V_52 :
case V_53 :
V_10 = F_9 ( & V_33 -> V_11 , V_47 , & V_55 ) ;
* V_46 = F_23 ( V_55 , 31 ) ;
break;
default:
V_10 = - V_43 ;
}
if ( V_10 < 0 )
return V_10 ;
return V_56 ;
}
static int F_24 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int V_57 )
{
unsigned int V_47 = V_58 [ V_45 -> V_49 ] ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
if ( V_57 < - 0x8000 || V_57 >= 0x8000 )
return - V_43 ;
return F_14 ( & V_33 -> V_11 , V_47 , V_57 ) ;
}
static int F_25 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int * V_57 )
{
unsigned int V_47 = V_58 [ V_45 -> V_49 ] ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
T_8 V_54 ;
int V_10 ;
V_10 = F_2 ( & V_33 -> V_11 , V_47 , & V_54 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_57 = F_23 ( V_54 , 15 ) ;
return V_56 ;
}
static int F_26 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int * V_34 )
{
struct V_5 * V_33 = F_11 ( V_26 ) ;
unsigned int V_59 , V_60 , V_47 ;
T_8 V_18 ;
int V_10 ;
V_47 = V_61 [ V_45 -> V_49 ] [ 0 ] ;
V_60 = V_61 [ V_45 -> V_49 ] [ 1 ] ;
V_59 = F_27 ( V_60 + 2 ) ;
V_10 = F_2 ( & V_33 -> V_11 , V_47 , & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_18 & V_59 ) )
* V_34 = 0 ;
else
* V_34 = V_62 [ ( V_18 >> V_60 ) & 0x3 ] ;
return V_56 ;
}
static int F_28 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , unsigned int V_34 )
{
struct V_5 * V_33 = F_11 ( V_26 ) ;
unsigned int V_59 , V_60 , V_47 ;
unsigned int V_63 , V_64 ;
unsigned int V_65 , V_66 ;
T_8 V_18 ;
int V_10 ;
V_47 = V_61 [ V_45 -> V_49 ] [ 0 ] ;
V_60 = V_61 [ V_45 -> V_49 ] [ 1 ] ;
V_59 = F_27 ( V_60 + 2 ) ;
V_10 = F_2 ( & V_33 -> V_11 , V_47 , & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_34 == 0 ) {
V_18 &= ~ V_59 ;
} else {
V_66 = 0 ;
V_64 = 310 ;
for ( V_65 = 0 ; V_65 < F_29 ( V_62 ) ; V_65 ++ ) {
if ( V_62 [ V_65 ] >= V_34 ) {
V_63 = V_62 [ V_65 ] - V_34 ;
if ( V_63 < V_64 ) {
V_64 = V_63 ;
V_66 = V_65 ;
}
}
}
V_18 &= ~ ( 0x3 << V_60 ) ;
V_18 |= V_66 << V_60 ;
V_18 |= V_59 ;
}
return F_14 ( & V_33 -> V_11 , V_47 , V_18 ) ;
}
static int F_30 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int * V_18 , int * V_67 , long V_68 )
{
switch ( V_68 ) {
case V_69 :
return F_31 ( V_26 , V_45 , 0 , V_18 ) ;
case V_70 :
switch ( V_45 -> type ) {
case V_52 :
* V_18 = 0 ;
* V_67 = F_32 ( 20000 ) ;
return V_71 ;
case V_53 :
* V_18 = 0 ;
* V_67 = F_33 ( 800 ) ;
return V_71 ;
case V_50 :
* V_18 = 0 ;
* V_67 = 100 ;
return V_71 ;
case V_72 :
* V_18 = 5 ;
* V_67 = 650000 ;
return V_71 ;
case V_51 :
* V_18 = 0 ;
* V_67 = 4000 ;
return V_71 ;
default:
return - V_43 ;
}
case V_73 :
* V_18 = 4425 ;
return V_56 ;
case V_74 :
return F_22 ( V_26 , V_45 , V_18 ) ;
case V_75 :
return F_25 ( V_26 , V_45 , V_18 ) ;
case V_76 :
return F_26 ( V_26 , V_45 , V_18 ) ;
default:
return - V_43 ;
}
}
static int F_34 ( struct V_25 * V_26 ,
const struct V_44 * V_45 , int V_18 , int V_67 , long V_68 )
{
switch ( V_68 ) {
case V_74 :
return F_20 ( V_26 , V_45 , V_18 ) ;
case V_75 :
return F_24 ( V_26 , V_45 , V_18 ) ;
case V_76 :
return F_28 ( V_26 , V_45 , V_18 ) ;
default:
return - V_43 ;
}
}
static int F_35 ( struct V_25 * V_26 )
{
struct V_5 * V_33 = F_11 ( V_26 ) ;
int V_10 ;
V_10 = F_14 ( & V_33 -> V_11 , V_77 , F_27 ( 9 ) ) ;
if ( V_10 )
F_36 ( & V_26 -> V_38 ,
L_9 , V_10 ) ;
return V_10 ;
}
static int F_37 ( struct V_11 * V_11 , bool V_78 )
{
return F_14 ( V_11 , V_79 ,
V_78 ? F_27 ( 3 ) : 0 ) ;
}
static int F_38 ( struct V_25 * V_26 )
{
struct V_5 * V_33 = F_11 ( V_26 ) ;
T_8 V_21 ;
unsigned int V_80 ;
int V_10 ;
F_39 ( & V_33 -> V_11 ) ;
F_40 ( 70 ) ;
V_10 = F_14 ( & V_33 -> V_11 , V_81 , F_27 ( 1 ) ) ;
if ( V_10 )
return V_10 ;
F_40 ( 30 ) ;
V_10 = F_41 ( & V_33 -> V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_2 ( & V_33 -> V_11 , V_22 , & V_21 ) ;
if ( V_10 )
return V_10 ;
sscanf ( V_26 -> V_82 , L_10 , & V_80 ) ;
if ( V_21 != V_80 )
F_42 ( & V_26 -> V_38 , L_11 ,
V_80 , V_21 ) ;
return 0 ;
}
static int F_43 ( struct V_83 * V_84 )
{
const struct V_85 * V_86 = F_44 ( V_84 ) ;
struct V_25 * V_26 ;
struct V_5 * V_33 ;
int V_10 ;
V_26 = F_45 ( sizeof( * V_33 ) ) ;
if ( V_26 == NULL )
return - V_87 ;
F_46 ( V_84 , V_26 ) ;
V_33 = F_11 ( V_26 ) ;
V_33 -> V_88 = & V_89 [ V_86 -> V_90 ] ;
V_26 -> V_38 . V_91 = & V_84 -> V_38 ;
V_26 -> V_82 = F_44 ( V_84 ) -> V_82 ;
V_26 -> V_92 = V_33 -> V_88 -> V_92 ;
V_26 -> V_93 = V_33 -> V_88 -> V_93 ;
V_26 -> V_68 = & V_94 ;
V_26 -> V_95 = V_96 ;
V_10 = F_47 ( & V_33 -> V_11 , V_26 , V_84 , & V_97 ) ;
if ( V_10 )
goto V_98;
V_10 = F_48 ( & V_33 -> V_11 , V_26 , NULL ) ;
if ( V_10 )
goto V_98;
V_10 = F_38 ( V_26 ) ;
if ( V_10 )
goto V_99;
V_10 = F_49 ( V_26 ) ;
if ( V_10 )
goto V_100;
F_10 ( V_26 ) ;
return 0 ;
V_100:
F_35 ( V_26 ) ;
V_99:
F_50 ( & V_33 -> V_11 , V_26 ) ;
V_98:
F_51 ( V_26 ) ;
return V_10 ;
}
static int F_52 ( struct V_83 * V_84 )
{
struct V_25 * V_26 = F_53 ( V_84 ) ;
struct V_5 * V_33 = F_11 ( V_26 ) ;
F_54 ( V_26 ) ;
F_35 ( V_26 ) ;
F_50 ( & V_33 -> V_11 , V_26 ) ;
F_51 ( V_26 ) ;
return 0 ;
}
