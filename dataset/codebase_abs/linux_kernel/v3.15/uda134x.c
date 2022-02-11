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
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
struct V_40 * V_41 ;
if ( V_39 -> V_42 ) {
V_41 = V_39 -> V_42 -> V_43 ;
F_4 ( L_4 , V_14 ,
V_41 -> V_44 ,
V_41 -> V_45 ) ;
F_12 ( V_37 -> V_43 ,
V_46 ,
V_41 -> V_45 ,
V_41 -> V_45 ) ;
F_12 ( V_37 -> V_43 ,
V_47 ,
V_41 -> V_44 ,
V_41 -> V_44 ) ;
V_39 -> V_48 = V_37 ;
} else
V_39 -> V_42 = V_37 ;
return 0 ;
}
static void F_13 ( struct V_36 * V_37 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
if ( V_39 -> V_42 == V_37 )
V_39 -> V_42 = V_39 -> V_48 ;
V_39 -> V_48 = NULL ;
}
static int F_14 ( struct V_36 * V_37 ,
struct V_49 * V_50 ,
struct V_32 * V_33 )
{
struct V_1 * V_2 = V_33 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
T_1 V_51 ;
if ( V_37 == V_39 -> V_48 ) {
F_4 ( L_5 ,
V_14 ) ;
return 0 ;
}
V_51 = F_1 ( V_2 , V_17 ) ;
V_51 &= V_52 ;
V_51 &= V_53 ;
F_4 ( L_6 , V_14 ,
V_39 -> V_54 , F_15 ( V_50 ) ) ;
switch ( V_39 -> V_54 / F_15 ( V_50 ) ) {
case 512 :
break;
case 384 :
V_51 |= ( 1 << 4 ) ;
break;
case 256 :
V_51 |= ( 1 << 5 ) ;
break;
default:
F_5 ( V_15 L_7 , V_14 ) ;
return - V_16 ;
}
F_4 ( L_8 , V_14 ,
V_39 -> V_55 , F_16 ( V_50 ) ) ;
switch ( V_39 -> V_55 & V_56 ) {
case V_57 :
break;
case V_58 :
switch ( F_16 ( V_50 ) ) {
case V_59 :
V_51 |= ( 1 << 1 ) ;
break;
case V_60 :
V_51 |= ( 1 << 2 ) ;
break;
case V_61 :
V_51 |= ( ( 1 << 2 ) | ( 1 << 1 ) ) ;
break;
default:
F_5 ( V_15 L_9 ,
V_14 ) ;
return - V_16 ;
}
break;
case V_62 :
V_51 |= ( 1 << 3 ) ;
break;
default:
F_5 ( V_15 L_10 , V_14 ) ;
return - V_16 ;
}
F_3 ( V_2 , V_17 , V_51 ) ;
return 0 ;
}
static int F_17 ( struct V_32 * V_63 ,
int V_64 , unsigned int V_65 , int V_66 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
F_4 ( L_11 , V_14 ,
V_64 , V_65 , V_66 ) ;
if ( ( V_65 >= ( 256 * 8000 ) ) && ( V_65 <= ( 512 * 48000 ) ) ) {
V_39 -> V_54 = V_65 ;
return 0 ;
}
F_5 ( V_15 L_12 , V_14 ) ;
return - V_16 ;
}
static int F_18 ( struct V_32 * V_63 ,
unsigned int V_67 )
{
struct V_1 * V_2 = V_63 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
F_4 ( L_13 , V_14 , V_67 ) ;
if ( ( V_67 & V_68 ) != V_69 ) {
F_5 ( V_15 L_14 , V_14 ) ;
return - V_16 ;
}
if ( ( V_67 & V_70 ) != V_71 ) {
F_5 ( V_15 L_15 , V_14 ) ;
return - V_16 ;
}
V_39 -> V_55 = V_67 ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 ,
enum V_72 V_73 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_74 ;
T_1 * V_4 = V_2 -> V_5 ;
F_4 ( L_16 , V_14 , V_73 ) ;
switch ( V_73 ) {
case V_75 :
break;
case V_76 :
if ( V_12 -> V_77 ) {
V_12 -> V_77 ( 1 ) ;
for ( V_74 = 0 ; V_74 < F_20 ( V_78 ) ; V_74 ++ )
V_2 -> V_79 -> V_80 ( V_2 , V_74 , * V_4 ++ ) ;
}
break;
case V_81 :
break;
case V_82 :
if ( V_12 -> V_77 )
V_12 -> V_77 ( 0 ) ;
break;
}
V_2 -> V_83 . V_84 = V_73 ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_11 * V_12 = V_2 -> V_85 -> V_86 -> V_87 ;
const struct V_88 * V_89 ;
unsigned V_90 ;
int V_8 ;
F_5 ( V_91 L_17 ) ;
if ( ! V_12 ) {
F_5 ( V_15 L_18
L_19 ) ;
return - V_92 ;
}
switch ( V_12 -> V_93 ) {
case V_94 :
case V_95 :
case V_96 :
case V_97 :
break;
default:
F_5 ( V_15 L_18
L_20 ,
V_12 -> V_93 ) ;
return - V_16 ;
}
V_39 = F_22 ( sizeof( struct V_38 ) , V_98 ) ;
if ( V_39 == NULL )
return - V_99 ;
F_23 ( V_2 , V_39 ) ;
V_2 -> V_13 = V_12 ;
if ( V_12 -> V_77 )
V_12 -> V_77 ( 1 ) ;
F_7 ( V_2 ) ;
if ( V_12 -> V_100 )
F_19 ( V_2 , V_75 ) ;
else
F_19 ( V_2 , V_81 ) ;
if ( V_12 -> V_93 == V_95 ) {
V_89 = V_101 ;
V_90 = F_20 ( V_101 ) ;
} else {
V_89 = V_102 ;
V_90 = F_20 ( V_102 ) ;
}
V_8 = F_24 ( & V_2 -> V_83 , V_89 , V_90 ) ;
if ( V_8 ) {
F_5 ( V_15 L_21 ,
V_14 , V_8 ) ;
F_25 ( V_39 ) ;
return V_8 ;
}
switch ( V_12 -> V_93 ) {
case V_94 :
case V_96 :
V_8 = F_26 ( V_2 , V_103 ,
F_20 ( V_103 ) ) ;
break;
case V_95 :
V_8 = F_26 ( V_2 , V_104 ,
F_20 ( V_104 ) ) ;
break;
case V_97 :
V_8 = F_26 ( V_2 , V_105 ,
F_20 ( V_105 ) ) ;
break;
default:
F_5 ( V_15 L_22 ,
V_14 , V_12 -> V_93 ) ;
F_25 ( V_39 ) ;
return - V_16 ;
}
if ( V_8 < 0 ) {
F_5 ( V_15 L_23 ) ;
F_25 ( V_39 ) ;
return V_8 ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 ) ;
F_19 ( V_2 , V_81 ) ;
F_19 ( V_2 , V_82 ) ;
F_25 ( V_39 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_81 ) ;
F_19 ( V_2 , V_82 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_19 ( V_2 , V_76 ) ;
F_19 ( V_2 , V_75 ) ;
return 0 ;
}
static int F_30 ( struct V_106 * V_107 )
{
return F_31 ( & V_107 -> V_86 ,
& V_108 , & V_109 , 1 ) ;
}
static int F_32 ( struct V_106 * V_107 )
{
F_33 ( & V_107 -> V_86 ) ;
return 0 ;
}
