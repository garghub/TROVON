static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_4 )
{
int V_5 ;
struct V_6 V_7 [] = {
{
. V_8 = V_2 -> V_8 ,
. V_9 = 0 ,
. V_10 = 2 ,
. V_11 = ( T_2 * ) & V_3 ,
} ,
{
. V_8 = V_2 -> V_8 ,
. V_9 = V_12 ,
. V_10 = 1 ,
. V_11 = V_4 ,
} ,
} ;
V_3 = F_2 ( V_3 ) ;
V_5 = F_3 ( V_2 -> V_13 , V_7 , 2 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 , L_1 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_6 V_7 ;
struct {
T_1 V_3 ;
T_2 V_4 ;
} V_15 V_11 ;
int V_5 ;
V_3 = F_2 ( V_3 ) ;
V_11 . V_3 = V_3 ;
V_11 . V_4 = V_4 ;
V_7 . V_8 = V_2 -> V_8 ;
V_7 . V_9 = 0 ;
V_7 . V_10 = 3 ;
V_7 . V_11 = ( T_2 * ) & V_11 ;
V_5 = F_3 ( V_2 -> V_13 , & V_7 , 1 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 , L_2 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_16 , T_2 V_17 )
{
T_2 V_4 ;
int V_5 ;
V_5 = F_1 ( V_2 , V_3 , & V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 ,
L_3 , V_3 ) ;
return V_5 ;
}
V_4 |= V_16 ;
V_4 &= ~ V_17 ;
V_5 = F_5 ( V_2 , V_3 , V_4 ) ;
if ( V_5 < 0 ) {
F_4 ( & V_2 -> V_14 ,
L_4 , V_3 ) ;
return V_5 ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 ,
const struct V_18 * V_19 ,
int V_20 )
{
int V_21 ;
int V_5 ;
for ( V_21 = 0 ; V_21 < V_20 ; V_21 ++ ) {
V_5 = F_5 ( V_2 ,
V_19 [ V_21 ] . V_3 , V_19 [ V_21 ] . V_4 ) ;
if ( V_5 < 0 )
return V_5 ;
}
return 0 ;
}
static int F_8 ( struct V_22 * V_23 , int V_24 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
int V_5 ;
if ( V_26 -> V_27 )
V_5 = F_6 ( V_2 , V_28 , 0x2 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_28 , 0 , 0x2 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_26 -> V_29 )
V_5 = F_6 ( V_2 , V_28 , 0x1 , 0 ) ;
else
V_5 = F_6 ( V_2 , V_28 , 0 , 0x1 ) ;
if ( V_5 < 0 )
return V_5 ;
if ( V_24 ) {
F_11 ( & V_2 -> V_14 , L_5 ) ;
V_5 = F_5 ( V_2 , V_30 , 0x01 ) ;
} else {
F_11 ( & V_2 -> V_14 , L_6 ) ;
V_5 = F_5 ( V_2 , V_31 , 0x01 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_2 , V_30 ,
0x00 ) ;
}
return V_5 ;
}
static int F_12 ( struct V_32 * V_33 ,
unsigned long V_9 )
{
return 0 ;
}
static unsigned long F_13 ( struct V_32 * V_33 )
{
struct V_34 * V_35 = F_14 ( V_33 ) ;
unsigned long V_9 = V_36 | V_37 |
V_38 | V_39 |
V_40 | V_41 ;
return F_15 ( V_35 , V_9 ) ;
}
static int F_16 ( struct V_22 * V_23 , struct V_42 * V_43 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
switch ( V_43 -> V_44 ) {
case V_45 :
V_43 -> V_46 = V_26 -> V_27 ;
break;
case V_47 :
V_43 -> V_46 = V_26 -> V_29 ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_17 ( struct V_22 * V_23 , struct V_42 * V_43 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
switch ( V_43 -> V_44 ) {
case V_45 :
V_26 -> V_27 = V_43 -> V_46 ;
break;
case V_47 :
V_26 -> V_29 = V_43 -> V_46 ;
break;
default:
return - V_48 ;
}
return 0 ;
}
static int F_18 ( struct V_22 * V_23 ,
struct V_49 * V_44 )
{
struct V_25 * V_26 = F_10 ( V_23 ) ;
V_44 -> V_50 = V_26 -> V_50 ;
V_44 -> V_51 = V_26 -> V_51 ;
return 0 ;
}
static int F_19 ( struct V_22 * V_23 ,
struct V_52 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
int V_5 ;
T_2 V_4 ;
if ( V_3 -> V_3 & ~ 0xffff )
return - V_48 ;
V_3 -> V_53 = 2 ;
V_5 = F_1 ( V_2 , V_3 -> V_3 , & V_4 ) ;
if ( V_5 )
return V_5 ;
V_3 -> V_4 = ( V_54 ) V_4 ;
return V_5 ;
}
static int F_20 ( struct V_22 * V_23 ,
struct V_52 * V_3 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
if ( V_3 -> V_3 & ~ 0xffff || V_3 -> V_4 & ~ 0xff )
return - V_48 ;
return F_5 ( V_2 , V_3 -> V_3 , V_3 -> V_4 ) ;
}
static void F_21 ( T_3 * V_55 , T_3 * V_56 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < F_22 ( V_57 ) ; V_21 ++ )
if ( ( V_57 [ V_21 ] . V_55 >= * V_55 ) &&
( V_57 [ V_21 ] . V_56 >= * V_56 ) ) {
* V_55 = V_57 [ V_21 ] . V_55 ;
* V_56 = V_57 [ V_21 ] . V_56 ;
return;
}
* V_55 = V_57 [ V_58 ] . V_55 ;
* V_56 = V_57 [ V_58 ] . V_56 ;
}
static int F_23 ( struct V_1 * V_2 , T_3 V_55 )
{
int V_5 ;
if ( V_55 == V_57 [ V_59 ] . V_55 ) {
F_11 ( & V_2 -> V_14 , L_7 ) ;
V_5 = F_7 ( V_2 , V_60 ,
F_22 ( V_60 ) ) ;
} else if ( V_55 == V_57 [ V_58 ] . V_55 ) {
F_11 ( & V_2 -> V_14 , L_8 ) ;
V_5 = F_7 ( V_2 , V_61 ,
F_22 ( V_61 ) ) ;
} else {
F_4 ( & V_2 -> V_14 , L_9 ) ;
return - V_48 ;
}
return V_5 ;
}
static int F_24 ( struct V_22 * V_23 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
enum V_64 V_65 ;
enum V_66 V_67 = V_63 -> V_67 ;
int V_5 ;
F_21 ( & V_63 -> V_55 , & V_63 -> V_56 ) ;
switch ( V_67 ) {
case V_68 :
V_65 = V_69 ;
break;
default:
return - V_48 ;
}
V_5 = F_7 ( V_2 , V_70 ,
F_22 ( V_70 ) ) ;
if ( V_5 < 0 )
return V_5 ;
V_5 = F_23 ( V_2 , V_63 -> V_55 ) ;
if ( V_5 < 0 )
return V_5 ;
V_63 -> V_67 = V_67 ;
V_63 -> V_71 = V_65 ;
return V_5 ;
}
static int F_25 ( struct V_22 * V_23 ,
struct V_62 * V_63 )
{
F_21 ( & V_63 -> V_55 , & V_63 -> V_56 ) ;
V_63 -> V_72 = V_73 ;
V_63 -> V_67 = V_68 ;
V_63 -> V_71 = V_69 ;
return 0 ;
}
static int F_26 ( struct V_22 * V_23 , unsigned int V_74 ,
enum V_66 * V_67 )
{
if ( V_74 >= F_22 ( V_75 ) )
return - V_48 ;
* V_67 = V_75 [ V_74 ] ;
return 0 ;
}
static int F_27 ( struct V_22 * V_23 , struct V_76 * V_77 )
{
V_77 -> V_78 . V_79 = 0 ;
V_77 -> V_78 . V_80 = 0 ;
V_77 -> V_78 . V_55 = V_57 [ V_58 ] . V_55 ;
V_77 -> V_78 . V_56 = V_57 [ V_58 ] . V_56 ;
V_77 -> V_81 = V_77 -> V_78 ;
V_77 -> type = V_82 ;
V_77 -> V_83 . V_84 = 1 ;
V_77 -> V_83 . V_85 = 1 ;
return 0 ;
}
static int F_28 ( struct V_22 * V_23 , struct V_86 * V_77 )
{
V_77 -> V_87 . V_79 = 0 ;
V_77 -> V_87 . V_80 = 0 ;
V_77 -> V_87 . V_55 = V_57 [ V_58 ] . V_55 ;
V_77 -> V_87 . V_56 = V_57 [ V_58 ] . V_56 ;
V_77 -> type = V_82 ;
return 0 ;
}
static int F_29 ( struct V_32 * V_33 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 = F_30 ( V_2 ) ;
struct V_25 * V_26 = F_10 ( V_23 ) ;
T_2 V_88 , V_89 ;
int V_5 ;
if ( ! V_33 -> V_14 . V_90 ||
F_31 ( V_33 -> V_14 . V_90 ) -> V_91 != V_33 -> V_92 ) {
F_4 ( & V_2 -> V_14 , L_10 ) ;
V_5 = - V_93 ;
goto V_94;
}
V_5 = F_1 ( V_2 , V_95 , & V_88 ) ;
if ( V_5 < 0 )
goto V_94;
V_5 = F_1 ( V_2 , V_96 , & V_89 ) ;
if ( V_5 < 0 )
goto V_94;
V_26 -> V_97 = ( V_88 << 8 ) | V_89 ;
V_5 = F_1 ( V_2 , V_98 , & V_26 -> V_51 ) ;
if ( V_5 < 0 )
goto V_94;
V_5 = F_1 ( V_2 , V_99 , & V_26 -> V_100 ) ;
if ( V_5 < 0 )
goto V_94;
V_5 = F_1 ( V_2 , V_101 , & V_26 -> V_102 ) ;
if ( V_5 < 0 )
goto V_94;
if ( V_26 -> V_97 != 0x9740 ) {
V_5 = - V_93 ;
goto V_94;
}
V_26 -> V_50 = V_103 ;
F_32 ( & V_2 -> V_14 , L_11
L_12 ,
V_26 -> V_97 , V_26 -> V_51 , V_26 -> V_100 , V_26 -> V_102 ) ;
V_94:
return V_5 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_104 * V_105 )
{
struct V_25 * V_26 ;
struct V_32 * V_33 = V_2 -> V_14 . V_106 ;
struct V_34 * V_35 ;
int V_5 ;
if ( ! V_33 ) {
F_4 ( & V_2 -> V_14 , L_13 ) ;
return - V_48 ;
}
V_35 = F_14 ( V_33 ) ;
if ( ! V_35 ) {
F_4 ( & V_2 -> V_14 , L_14 ) ;
return - V_48 ;
}
V_26 = F_34 ( sizeof( struct V_25 ) , V_107 ) ;
if ( ! V_26 ) {
F_4 ( & V_2 -> V_14 , L_15 ) ;
return - V_108 ;
}
F_35 ( & V_26 -> V_109 , V_2 , & V_110 ) ;
V_33 -> V_111 = & V_112 ;
V_5 = F_29 ( V_33 , V_2 ) ;
if ( V_5 < 0 ) {
V_33 -> V_111 = NULL ;
F_36 ( V_26 ) ;
}
return V_5 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = F_30 ( V_2 ) ;
F_36 ( V_26 ) ;
return 0 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_113 ) ;
}
static void T_5 F_40 ( void )
{
F_41 ( & V_113 ) ;
}
