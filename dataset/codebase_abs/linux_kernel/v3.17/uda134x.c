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
switch ( F_17 ( V_50 ) ) {
case 16 :
V_51 |= ( 1 << 1 ) ;
break;
case 18 :
V_51 |= ( 1 << 2 ) ;
break;
case 20 :
V_51 |= ( ( 1 << 2 ) | ( 1 << 1 ) ) ;
break;
default:
F_5 ( V_15 L_9 ,
V_14 ) ;
return - V_16 ;
}
break;
case V_59 :
V_51 |= ( 1 << 3 ) ;
break;
default:
F_5 ( V_15 L_10 , V_14 ) ;
return - V_16 ;
}
F_3 ( V_2 , V_17 , V_51 ) ;
return 0 ;
}
static int F_18 ( struct V_32 * V_60 ,
int V_61 , unsigned int V_62 , int V_63 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
F_4 ( L_11 , V_14 ,
V_61 , V_62 , V_63 ) ;
if ( ( V_62 >= ( 256 * 8000 ) ) && ( V_62 <= ( 512 * 48000 ) ) ) {
V_39 -> V_54 = V_62 ;
return 0 ;
}
F_5 ( V_15 L_12 , V_14 ) ;
return - V_16 ;
}
static int F_19 ( struct V_32 * V_60 ,
unsigned int V_64 )
{
struct V_1 * V_2 = V_60 -> V_2 ;
struct V_38 * V_39 = F_11 ( V_2 ) ;
F_4 ( L_13 , V_14 , V_64 ) ;
if ( ( V_64 & V_65 ) != V_66 ) {
F_5 ( V_15 L_14 , V_14 ) ;
return - V_16 ;
}
if ( ( V_64 & V_67 ) != V_68 ) {
F_5 ( V_15 L_15 , V_14 ) ;
return - V_16 ;
}
V_39 -> V_55 = V_64 ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
enum V_69 V_70 )
{
struct V_11 * V_12 = V_2 -> V_13 ;
int V_71 ;
T_1 * V_4 = V_2 -> V_5 ;
F_4 ( L_16 , V_14 , V_70 ) ;
switch ( V_70 ) {
case V_72 :
break;
case V_73 :
if ( V_12 -> V_74 ) {
V_12 -> V_74 ( 1 ) ;
for ( V_71 = 0 ; V_71 < F_21 ( V_75 ) ; V_71 ++ )
V_2 -> V_76 -> V_77 ( V_2 , V_71 , * V_4 ++ ) ;
}
break;
case V_78 :
break;
case V_79 :
if ( V_12 -> V_74 )
V_12 -> V_74 ( 0 ) ;
break;
}
V_2 -> V_80 . V_81 = V_70 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_38 * V_39 ;
struct V_11 * V_12 = V_2 -> V_82 . V_83 -> V_84 -> V_85 ;
const struct V_86 * V_87 ;
unsigned V_88 ;
int V_8 ;
F_5 ( V_89 L_17 ) ;
if ( ! V_12 ) {
F_5 ( V_15 L_18
L_19 ) ;
return - V_90 ;
}
switch ( V_12 -> V_91 ) {
case V_92 :
case V_93 :
case V_94 :
case V_95 :
break;
default:
F_5 ( V_15 L_18
L_20 ,
V_12 -> V_91 ) ;
return - V_16 ;
}
V_39 = F_23 ( sizeof( struct V_38 ) , V_96 ) ;
if ( V_39 == NULL )
return - V_97 ;
F_24 ( V_2 , V_39 ) ;
V_2 -> V_13 = V_12 ;
if ( V_12 -> V_74 )
V_12 -> V_74 ( 1 ) ;
F_7 ( V_2 ) ;
if ( V_12 -> V_98 )
F_20 ( V_2 , V_72 ) ;
else
F_20 ( V_2 , V_78 ) ;
if ( V_12 -> V_91 == V_93 ) {
V_87 = V_99 ;
V_88 = F_21 ( V_99 ) ;
} else {
V_87 = V_100 ;
V_88 = F_21 ( V_100 ) ;
}
V_8 = F_25 ( & V_2 -> V_80 , V_87 , V_88 ) ;
if ( V_8 ) {
F_5 ( V_15 L_21 ,
V_14 , V_8 ) ;
F_26 ( V_39 ) ;
return V_8 ;
}
switch ( V_12 -> V_91 ) {
case V_92 :
case V_94 :
V_8 = F_27 ( V_2 , V_101 ,
F_21 ( V_101 ) ) ;
break;
case V_93 :
V_8 = F_27 ( V_2 , V_102 ,
F_21 ( V_102 ) ) ;
break;
case V_95 :
V_8 = F_27 ( V_2 , V_103 ,
F_21 ( V_103 ) ) ;
break;
default:
F_5 ( V_15 L_22 ,
V_14 , V_12 -> V_91 ) ;
F_26 ( V_39 ) ;
return - V_16 ;
}
if ( V_8 < 0 ) {
F_5 ( V_15 L_23 ) ;
F_26 ( V_39 ) ;
return V_8 ;
}
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_38 * V_39 = F_11 ( V_2 ) ;
F_20 ( V_2 , V_78 ) ;
F_20 ( V_2 , V_79 ) ;
F_26 ( V_39 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_78 ) ;
F_20 ( V_2 , V_79 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_20 ( V_2 , V_73 ) ;
F_20 ( V_2 , V_72 ) ;
return 0 ;
}
static int F_31 ( struct V_104 * V_105 )
{
return F_32 ( & V_105 -> V_84 ,
& V_106 , & V_107 , 1 ) ;
}
static int F_33 ( struct V_104 * V_105 )
{
F_34 ( & V_105 -> V_84 ) ;
return 0 ;
}
