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
static int F_13 ( struct V_25 * V_26 , int V_18 , int V_33 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
unsigned int V_35 ;
V_35 = V_18 * 1000 + V_33 / 1000 ;
if ( V_35 <= 0 )
return - V_36 ;
V_35 = 2460000 / V_35 ;
if ( V_35 > 2048 )
V_35 = 2048 ;
if ( V_35 != 0 )
V_35 -- ;
return F_14 ( & V_34 -> V_11 , V_37 , V_35 ) ;
}
static int F_15 ( struct V_25 * V_26 , int * V_18 , int * V_33 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
T_8 V_35 ;
int V_10 ;
unsigned V_38 ;
V_10 = F_2 ( & V_34 -> V_11 , V_37 , & V_35 ) ;
if ( V_10 < 0 )
return V_10 ;
V_38 = 2460000 / ( V_35 + 1 ) ;
* V_18 = V_38 / 1000 ;
* V_33 = ( V_38 % 1000 ) * 1000 ;
return V_39 ;
}
static int F_16 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int V_42 )
{
unsigned int V_43 = V_44 [ V_41 -> V_45 ] ;
struct V_5 * V_34 = F_11 ( V_26 ) ;
switch ( V_41 -> type ) {
case V_46 :
case V_47 :
if ( V_42 < - 0x8000 || V_42 >= 0x8000 )
return - V_36 ;
return F_14 ( & V_34 -> V_11 , V_43 , V_42 ) ;
case V_48 :
case V_49 :
return F_17 ( & V_34 -> V_11 , V_43 , V_42 ) ;
default:
break;
}
return - V_36 ;
}
static int F_18 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int * V_42 )
{
unsigned int V_43 = V_44 [ V_41 -> V_45 ] ;
struct V_5 * V_34 = F_11 ( V_26 ) ;
T_8 V_50 ;
T_9 V_51 ;
int V_10 ;
switch ( V_41 -> type ) {
case V_46 :
case V_47 :
V_10 = F_2 ( & V_34 -> V_11 , V_43 , & V_50 ) ;
* V_42 = F_19 ( V_50 , 15 ) ;
break;
case V_48 :
case V_49 :
V_10 = F_9 ( & V_34 -> V_11 , V_43 , & V_51 ) ;
* V_42 = F_19 ( V_51 , 31 ) ;
break;
default:
V_10 = - V_36 ;
}
if ( V_10 < 0 )
return V_10 ;
return V_52 ;
}
static int F_20 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int V_53 )
{
unsigned int V_43 = V_54 [ V_41 -> V_45 ] ;
struct V_5 * V_34 = F_11 ( V_26 ) ;
if ( V_53 < - 0x8000 || V_53 >= 0x8000 )
return - V_36 ;
return F_14 ( & V_34 -> V_11 , V_43 , V_53 ) ;
}
static int F_21 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int * V_53 )
{
unsigned int V_43 = V_54 [ V_41 -> V_45 ] ;
struct V_5 * V_34 = F_11 ( V_26 ) ;
T_8 V_50 ;
int V_10 ;
V_10 = F_2 ( & V_34 -> V_11 , V_43 , & V_50 ) ;
if ( V_10 < 0 )
return V_10 ;
* V_53 = F_19 ( V_50 , 15 ) ;
return V_52 ;
}
static int F_22 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int * V_38 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
unsigned int V_55 , V_56 , V_43 ;
T_8 V_18 ;
int V_10 ;
V_43 = V_57 [ V_41 -> V_45 ] [ 0 ] ;
V_56 = V_57 [ V_41 -> V_45 ] [ 1 ] ;
V_55 = F_23 ( V_56 + 2 ) ;
V_10 = F_2 ( & V_34 -> V_11 , V_43 , & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( ! ( V_18 & V_55 ) )
* V_38 = 0 ;
else
* V_38 = V_58 [ ( V_18 >> V_56 ) & 0x3 ] ;
return V_52 ;
}
static int F_24 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , unsigned int V_38 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
unsigned int V_55 , V_56 , V_43 ;
unsigned int V_59 , V_60 ;
unsigned int V_61 , V_62 ;
T_8 V_18 ;
int V_10 ;
V_43 = V_57 [ V_41 -> V_45 ] [ 0 ] ;
V_56 = V_57 [ V_41 -> V_45 ] [ 1 ] ;
V_55 = F_23 ( V_56 + 2 ) ;
V_10 = F_2 ( & V_34 -> V_11 , V_43 , & V_18 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_38 == 0 ) {
V_18 &= ~ V_55 ;
} else {
V_62 = 0 ;
V_60 = 310 ;
for ( V_61 = 0 ; V_61 < F_25 ( V_58 ) ; V_61 ++ ) {
if ( V_58 [ V_61 ] >= V_38 ) {
V_59 = V_58 [ V_61 ] - V_38 ;
if ( V_59 < V_60 ) {
V_60 = V_59 ;
V_62 = V_61 ;
}
}
}
V_18 &= ~ ( 0x3 << V_56 ) ;
V_18 |= V_62 << V_56 ;
V_18 |= V_55 ;
}
return F_14 ( & V_34 -> V_11 , V_43 , V_18 ) ;
}
static int F_26 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int * V_18 , int * V_33 , long V_63 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
switch ( V_63 ) {
case V_64 :
return F_27 ( V_26 , V_41 , 0 , V_18 ) ;
case V_65 :
switch ( V_41 -> type ) {
case V_48 :
* V_18 = V_34 -> V_66 -> V_67 ;
* V_33 = V_34 -> V_66 -> V_68 ;
return V_69 ;
case V_49 :
* V_18 = V_34 -> V_66 -> V_70 ;
* V_33 = V_34 -> V_66 -> V_71 ;
return V_69 ;
case V_46 :
* V_18 = 0 ;
* V_33 = 100 ;
return V_39 ;
case V_72 :
* V_18 = 5 ;
* V_33 = 650000 ;
return V_39 ;
case V_47 :
* V_18 = 0 ;
* V_33 = 4000 ;
return V_39 ;
default:
return - V_36 ;
}
case V_73 :
* V_18 = 4425 ;
return V_52 ;
case V_74 :
return F_18 ( V_26 , V_41 , V_18 ) ;
case V_75 :
return F_21 ( V_26 , V_41 , V_18 ) ;
case V_76 :
return F_22 ( V_26 , V_41 , V_18 ) ;
case V_77 :
return F_15 ( V_26 , V_18 , V_33 ) ;
default:
return - V_36 ;
}
}
static int F_28 ( struct V_25 * V_26 ,
const struct V_40 * V_41 , int V_18 , int V_33 , long V_63 )
{
switch ( V_63 ) {
case V_74 :
return F_16 ( V_26 , V_41 , V_18 ) ;
case V_75 :
return F_20 ( V_26 , V_41 , V_18 ) ;
case V_76 :
return F_24 ( V_26 , V_41 , V_18 ) ;
case V_77 :
return F_13 ( V_26 , V_18 , V_33 ) ;
default:
return - V_36 ;
}
}
static int F_29 ( struct V_25 * V_26 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
int V_10 ;
V_10 = F_14 ( & V_34 -> V_11 , V_78 , F_23 ( 9 ) ) ;
if ( V_10 )
F_30 ( & V_26 -> V_79 ,
L_8 , V_10 ) ;
return V_10 ;
}
static int F_31 ( struct V_11 * V_11 , bool V_80 )
{
return F_14 ( V_11 , V_81 ,
V_80 ? F_23 ( 3 ) : 0 ) ;
}
static int F_32 ( struct V_25 * V_26 )
{
struct V_5 * V_34 = F_11 ( V_26 ) ;
T_8 V_21 ;
unsigned int V_82 ;
int V_10 ;
F_33 ( & V_34 -> V_11 ) ;
F_34 ( 70 ) ;
V_10 = F_14 ( & V_34 -> V_11 , V_83 , F_23 ( 1 ) ) ;
if ( V_10 )
return V_10 ;
F_34 ( 30 ) ;
V_10 = F_35 ( & V_34 -> V_11 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_2 ( & V_34 -> V_11 , V_22 , & V_21 ) ;
if ( V_10 )
return V_10 ;
V_10 = sscanf ( V_26 -> V_84 , L_9 , & V_82 ) ;
if ( V_10 != 1 )
return - V_36 ;
if ( V_21 != V_82 )
F_36 ( & V_26 -> V_79 , L_10 ,
V_82 , V_21 ) ;
return 0 ;
}
static int F_37 ( struct V_85 * V_86 )
{
const struct V_87 * V_88 = F_38 ( V_86 ) ;
struct V_25 * V_26 ;
struct V_5 * V_34 ;
int V_10 ;
V_26 = F_39 ( & V_86 -> V_79 , sizeof( * V_34 ) ) ;
if ( V_26 == NULL )
return - V_89 ;
F_40 ( V_86 , V_26 ) ;
V_34 = F_11 ( V_26 ) ;
V_34 -> V_66 = & V_90 [ V_88 -> V_91 ] ;
V_26 -> V_79 . V_92 = & V_86 -> V_79 ;
V_26 -> V_84 = F_38 ( V_86 ) -> V_84 ;
V_26 -> V_93 = V_34 -> V_66 -> V_93 ;
V_26 -> V_94 = V_34 -> V_66 -> V_94 ;
V_26 -> V_63 = & V_95 ;
V_26 -> V_96 = V_97 ;
V_10 = F_41 ( & V_34 -> V_11 , V_26 , V_86 , & V_98 ) ;
if ( V_10 )
return V_10 ;
V_10 = F_42 ( & V_34 -> V_11 , V_26 , NULL ) ;
if ( V_10 )
return V_10 ;
V_10 = F_32 ( V_26 ) ;
if ( V_10 )
goto V_99;
V_10 = F_43 ( V_26 ) ;
if ( V_10 )
goto V_100;
F_10 ( V_26 ) ;
return 0 ;
V_100:
F_29 ( V_26 ) ;
V_99:
F_44 ( & V_34 -> V_11 , V_26 ) ;
return V_10 ;
}
static int F_45 ( struct V_85 * V_86 )
{
struct V_25 * V_26 = F_46 ( V_86 ) ;
struct V_5 * V_34 = F_11 ( V_26 ) ;
F_47 ( V_26 ) ;
F_29 ( V_26 ) ;
F_44 ( & V_34 -> V_11 , V_26 ) ;
return 0 ;
}
