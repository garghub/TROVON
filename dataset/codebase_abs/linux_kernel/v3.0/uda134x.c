static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return - 1 ;
return V_4 [ V_3 ] ;
}
static inline void F_2 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_7 )
{
T_1 * V_4 = V_2 -> V_5 ;
if ( V_3 >= V_6 )
return;
V_4 [ V_3 ] = V_7 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
int V_8 ;
T_1 V_9 ;
T_1 V_10 = V_7 ;
struct V_11 * V_12 = V_2 -> V_13 ;
F_4 ( L_1 , V_14 , V_3 , V_7 ) ;
if ( V_3 >= V_6 ) {
F_5 ( V_15 L_2 ,
V_14 , V_3 ) ;
return - V_16 ;
}
F_2 ( V_2 , V_3 , V_7 ) ;
switch ( V_3 ) {
case V_17 :
case V_18 :
V_9 = V_19 ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
V_9 = V_24 ;
break;
case V_25 :
V_9 = V_26 ;
break;
default:
V_9 = ( V_3 | V_27 ) ;
V_8 = F_6 ( & V_12 -> V_28 ,
V_24 , & V_9 , 1 ) ;
if ( V_8 != 1 )
return - V_29 ;
V_9 = V_24 ;
V_10 = ( V_7 | V_30 ) ;
break;
}
V_8 = F_6 ( & V_12 -> V_28 ,
V_9 , & V_10 , 1 ) ;
if ( V_8 != 1 )
return - V_29 ;
return 0 ;
}
static inline void F_7 ( struct V_1 * V_2 )
{
T_1 V_31 = F_1 ( V_2 , V_17 ) ;
F_3 ( V_2 , V_17 , V_31 | ( 1 << 6 ) ) ;
F_8 ( 1 ) ;
F_3 ( V_2 , V_17 , V_31 & ~ ( 1 << 6 ) ) ;
}
static int F_9 ( struct V_32 * V_33 , int V_34 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
T_1 V_35 = F_1 ( V_2 , V_22 ) ;
F_4 ( L_3 , V_14 , V_34 ) ;
if ( V_34 )
V_35 |= ( 1 << 2 ) ;
else
V_35 &= ~ ( 1 << 2 ) ;
F_3 ( V_2 , V_22 , V_35 ) ;
return 0 ;
}
static int F_10 ( struct V_36 * V_37 ,
struct V_32 * V_33 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_41 * V_42 = F_11 ( V_2 ) ;
struct V_43 * V_44 ;
if ( V_42 -> V_45 ) {
V_44 = V_42 -> V_45 -> V_46 ;
F_4 ( L_4 , V_14 ,
V_44 -> V_47 ,
V_44 -> V_48 ) ;
F_12 ( V_37 -> V_46 ,
V_49 ,
V_44 -> V_48 ,
V_44 -> V_48 ) ;
F_12 ( V_37 -> V_46 ,
V_50 ,
V_44 -> V_47 ,
V_44 -> V_47 ) ;
V_42 -> V_51 = V_37 ;
} else
V_42 -> V_45 = V_37 ;
return 0 ;
}
static void F_13 ( struct V_36 * V_37 ,
struct V_32 * V_33 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_41 * V_42 = F_11 ( V_2 ) ;
if ( V_42 -> V_45 == V_37 )
V_42 -> V_45 = V_42 -> V_51 ;
V_42 -> V_51 = NULL ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_52 * V_53 ,
struct V_32 * V_33 )
{
struct V_38 * V_39 = V_37 -> V_40 ;
struct V_1 * V_2 = V_39 -> V_2 ;
struct V_41 * V_42 = F_11 ( V_2 ) ;
T_1 V_54 ;
if ( V_37 == V_42 -> V_51 ) {
F_4 ( L_5 ,
V_14 ) ;
return 0 ;
}
V_54 = F_1 ( V_2 , V_17 ) ;
V_54 &= V_55 ;
V_54 &= V_56 ;
F_4 ( L_6 , V_14 ,
V_42 -> V_57 , F_15 ( V_53 ) ) ;
switch ( V_42 -> V_57 / F_15 ( V_53 ) ) {
case 512 :
break;
case 384 :
V_54 |= ( 1 << 4 ) ;
break;
case 256 :
V_54 |= ( 1 << 5 ) ;
break;
default:
F_5 ( V_15 L_7 , V_14 ) ;
return - V_16 ;
}
F_4 ( L_8 , V_14 ,
V_42 -> V_58 , F_16 ( V_53 ) ) ;
switch ( V_42 -> V_58 & V_59 ) {
case V_60 :
break;
case V_61 :
switch ( F_16 ( V_53 ) ) {
case V_62 :
V_54 |= ( 1 << 1 ) ;
break;
case V_63 :
V_54 |= ( 1 << 2 ) ;
break;
case V_64 :
V_54 |= ( ( 1 << 2 ) | ( 1 << 1 ) ) ;
break;
default:
F_5 ( V_15 L_9 ,
V_14 ) ;
return - V_16 ;
}
break;
case V_65 :
V_54 |= ( 1 << 3 ) ;
break;
default:
F_5 ( V_15 L_10 , V_14 ) ;
return - V_16 ;
}
F_3 ( V_2 , V_17 , V_54 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_66 ,
int V_67 , unsigned int V_68 , int V_69 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_41 * V_42 = F_11 ( V_2 ) ;
F_4 ( L_11 , V_14 ,
V_67 , V_68 , V_69 ) ;
if ( ( V_68 >= ( 256 * 8000 ) ) && ( V_68 <= ( 512 * 48000 ) ) ) {
V_42 -> V_57 = V_68 ;
return 0 ;
}
F_5 ( V_15 L_12 , V_14 ) ;
return - V_16 ;
}
static int F_18 ( struct V_32 * V_66 ,
unsigned int V_70 )
{
struct V_1 * V_2 = V_66 -> V_2 ;
struct V_41 * V_42 = F_11 ( V_2 ) ;
F_4 ( L_13 , V_14 , V_70 ) ;
if ( ( V_70 & V_71 ) != V_72 ) {
F_5 ( V_15 L_14 , V_14 ) ;
return - V_16 ;
}
if ( ( V_70 & V_73 ) != V_74 ) {
F_5 ( V_15 L_15 , V_14 ) ;
return - V_16 ;
}
V_42 -> V_58 = V_70 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_75 V_76 )
{
T_1 V_3 ;
struct V_11 * V_12 = V_2 -> V_13 ;
int V_77 ;
T_1 * V_4 = V_2 -> V_5 ;
F_4 ( L_16 , V_14 , V_76 ) ;
switch ( V_76 ) {
case V_78 :
switch ( V_12 -> V_79 ) {
case V_80 :
case V_81 :
case V_82 :
V_3 = F_1 ( V_2 , V_23 ) ;
F_3 ( V_2 , V_23 , V_3 | 0x03 ) ;
break;
case V_83 :
V_3 = F_1 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_18 , V_3 | 0x03 ) ;
break;
default:
F_5 ( V_15 L_17
L_18 , V_12 -> V_79 ) ;
return - V_16 ;
}
break;
case V_84 :
if ( V_12 -> V_85 ) {
V_12 -> V_85 ( 1 ) ;
for ( V_77 = 0 ; V_77 < F_20 ( V_86 ) ; V_77 ++ )
V_2 -> V_87 -> V_88 ( V_2 , V_77 , * V_4 ++ ) ;
}
break;
case V_89 :
switch ( V_12 -> V_79 ) {
case V_80 :
case V_81 :
case V_82 :
V_3 = F_1 ( V_2 , V_23 ) ;
F_3 ( V_2 , V_23 , V_3 & ~ ( 0x03 ) ) ;
break;
case V_83 :
V_3 = F_1 ( V_2 , V_18 ) ;
F_3 ( V_2 , V_18 , V_3 & ~ ( 0x03 ) ) ;
break;
default:
F_5 ( V_15 L_17
L_18 , V_12 -> V_79 ) ;
return - V_16 ;
}
break;
case V_90 :
if ( V_12 -> V_85 )
V_12 -> V_85 ( 0 ) ;
break;
}
V_2 -> V_91 . V_92 = V_76 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_41 * V_42 ;
struct V_11 * V_12 = V_2 -> V_93 -> V_94 -> V_95 ;
int V_8 ;
F_5 ( V_96 L_19 ) ;
if ( ! V_12 ) {
F_5 ( V_15 L_17
L_20 ) ;
return - V_97 ;
}
switch ( V_12 -> V_79 ) {
case V_80 :
case V_83 :
case V_81 :
case V_82 :
break;
default:
F_5 ( V_15 L_17
L_18 ,
V_12 -> V_79 ) ;
return - V_16 ;
}
V_42 = F_22 ( sizeof( struct V_41 ) , V_98 ) ;
if ( V_42 == NULL )
return - V_99 ;
F_23 ( V_2 , V_42 ) ;
V_2 -> V_13 = V_12 ;
if ( V_12 -> V_85 )
V_12 -> V_85 ( 1 ) ;
F_7 ( V_2 ) ;
if ( V_12 -> V_100 )
F_19 ( V_2 , V_78 ) ;
else
F_19 ( V_2 , V_89 ) ;
switch ( V_12 -> V_79 ) {
case V_80 :
case V_81 :
V_8 = F_24 ( V_2 , V_101 ,
F_20 ( V_101 ) ) ;
break;
case V_83 :
V_8 = F_24 ( V_2 , V_102 ,
F_20 ( V_102 ) ) ;
break;
case V_82 :
V_8 = F_24 ( V_2 , V_103 ,
F_20 ( V_103 ) ) ;
break;
default:
F_5 ( V_15 L_21 ,
V_14 , V_12 -> V_79 ) ;
F_25 ( V_42 ) ;
return - V_16 ;
}
if ( V_8 < 0 ) {
F_5 ( V_15 L_22 ) ;
F_25 ( V_42 ) ;
return V_8 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_11 ( V_2 ) ;
F_19 ( V_2 , V_89 ) ;
F_19 ( V_2 , V_90 ) ;
F_25 ( V_42 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 ,
T_2 V_104 )
{
F_19 ( V_2 , V_89 ) ;
F_19 ( V_2 , V_90 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_84 ) ;
F_19 ( V_2 , V_78 ) ;
return 0 ;
}
static int T_3 F_29 ( struct V_105 * V_106 )
{
return F_30 ( & V_106 -> V_94 ,
& V_107 , & V_108 , 1 ) ;
}
static int T_4 F_31 ( struct V_105 * V_106 )
{
F_32 ( & V_106 -> V_94 ) ;
return 0 ;
}
static int T_5 F_33 ( void )
{
return F_34 ( & V_109 ) ;
}
static void T_6 F_35 ( void )
{
F_36 ( & V_109 ) ;
}
