static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_3 , F_3 ( 2 ) | F_3 ( 1 ) | F_3 ( 0 ) ) ;
F_4 ( V_2 , V_4 , F_3 ( 2 ) , F_3 ( 2 ) ) ;
}
static void F_5 ( struct V_1 * V_5 , int V_6 )
{
int V_7 = F_6 ( V_5 , V_8 ) ;
if ( V_6 ) {
V_7 |= ( V_9 | V_10 ) ;
V_7 &= ( ~ V_11 ) ;
} else {
V_7 &= ( ~ V_10 ) ;
}
F_2 ( V_5 , V_8 , V_7 ) ;
}
static int F_7 ( struct V_1 * V_5 )
{
int V_12 , V_7 ;
V_7 = F_6 ( V_5 , V_8 ) ;
if ( ( V_7 & V_9 ) == 0 )
return 0 ;
for ( V_12 = 0 ; V_12 < V_13 ; V_12 ++ ) {
V_7 = F_6 ( V_5 ,
V_14 + V_12 ) ;
if ( V_7 & V_15 )
break;
}
return ( V_12 == V_13 ) ? ( - V_16 ) : V_12 ;
}
static int F_8 ( struct V_1 * V_5 )
{
int V_17 , V_18 ;
int V_7 ;
int V_19 ;
V_19 = F_7 ( V_5 ) ;
if ( V_19 < 0 ) {
F_9 ( L_1 ) ;
return V_19 ;
}
V_17 = V_14 + V_19 ;
if ( ! ( V_19 == 0 || V_19 == V_20 ) ) {
V_7 = F_6 ( V_5 , V_17 ) ;
F_2 ( V_5 , V_17 , V_7 & 0xEF ) ;
V_17 ++ ;
V_19 ++ ;
}
F_2 ( V_5 , V_17 ,
V_21 | 0x10 ) ;
V_18 = V_22 + 2 * V_19 ;
F_10 ( L_2 , V_18 ) ;
F_5 ( V_5 , 1 ) ;
return V_18 ;
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
T_1 V_23 = F_8 ( V_2 ) ;
T_1 V_24 , V_25 ;
unsigned int V_26 ;
F_1 ( V_2 ) ;
F_2 ( V_2 , V_27 , 0x05 ) ;
F_2 ( V_2 , V_27 , 0x04 ) ;
F_12 ( 1000 ) ;
V_24 = F_6 ( V_2 , V_23 ) ;
V_23 ++ ;
V_25 = F_6 ( V_2 , V_23 ) ;
V_26 = ( V_24 << 2 ) + ( V_25 & 3 ) ;
V_26 = ( V_26 * V_28 ) / 1000 ;
F_10 ( L_3 , V_26 ) ;
return V_26 ;
}
static inline unsigned int F_13 ( struct V_1 * V_2 ,
unsigned int V_29 )
{
T_2 V_7 = 0 ;
int V_30 ;
V_30 = F_14 ( V_29 , & V_7 ) ;
if ( V_30 )
F_9 ( L_4 , V_29 , V_30 ) ;
return V_7 ;
}
static inline int F_15 ( struct V_1 * V_2 ,
unsigned int V_29 , unsigned int V_7 )
{
int V_30 ;
V_30 = F_16 ( V_29 , V_7 ) ;
if ( V_30 )
F_9 ( L_5 , V_29 , V_30 ) ;
return V_30 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_31 V_32 )
{
switch ( V_32 ) {
case V_33 :
break;
case V_34 :
if ( V_2 -> V_35 . V_36 == V_37 ) {
F_10 ( L_6 ) ;
F_2 ( V_2 , V_38 , F_3 ( 5 ) ) ;
F_4 ( V_2 , V_39 ,
F_3 ( 0 ) , F_3 ( 0 ) ) ;
}
break;
case V_37 :
if ( V_2 -> V_35 . V_36 == V_40 ) {
F_10 ( L_7 ) ;
F_2 ( V_2 , V_3 ,
F_3 ( 2 ) | F_3 ( 1 ) | F_3 ( 0 ) ) ;
F_12 ( 1 ) ;
} else if ( V_2 -> V_35 . V_36 == V_34 ) {
F_10 ( L_8 ) ;
F_4 ( V_2 , V_39 , F_3 ( 0 ) , 0 ) ;
F_2 ( V_2 , V_38 , 0 ) ;
}
break;
case V_40 :
F_10 ( L_9 ) ;
F_2 ( V_2 , V_3 , F_3 ( 3 ) ) ;
break;
}
V_2 -> V_35 . V_36 = V_32 ;
return 0 ;
}
static int F_18 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
if ( F_19 ( V_45 ) ) {
F_10 ( L_10 ) ;
F_2 ( V_42 -> V_2 , V_46 , 0x3D ) ;
F_2 ( V_42 -> V_2 , V_47 , 0x3F ) ;
F_12 ( 1 ) ;
} else if ( F_20 ( V_45 ) ) {
F_10 ( L_11 ) ;
F_2 ( V_42 -> V_2 , V_46 , 0xC4 ) ;
F_2 ( V_42 -> V_2 , V_47 , 0x04 ) ;
}
return 0 ;
}
static int F_21 ( struct V_41 * V_42 ,
struct V_43 * V_44 , int V_45 )
{
if ( F_19 ( V_45 ) ) {
F_10 ( L_12 ) ;
F_2 ( V_42 -> V_2 , V_48 , 0x27 ) ;
F_12 ( 1 ) ;
} else if ( F_20 ( V_45 ) ) {
F_10 ( L_13 ) ;
F_2 ( V_42 -> V_2 , V_48 , 0x24 ) ;
}
return 0 ;
}
static int F_22 ( struct V_41 * V_42 ,
struct V_43 * V_49 , int V_45 )
{
unsigned int V_50 = 0 , V_51 = 0 , V_52 = 0 ;
if ( F_19 ( V_45 ) ) {
V_50 = F_3 ( 5 ) | F_3 ( 4 ) ;
V_51 = F_3 ( 0 ) ;
V_52 = F_3 ( 7 ) ;
}
F_4 ( V_42 -> V_2 , V_4 , F_3 ( 5 ) | F_3 ( 4 ) , V_50 ) ;
F_4 ( V_42 -> V_2 , V_53 , F_3 ( 0 ) , V_51 ) ;
F_4 ( V_42 -> V_2 , V_53 , F_3 ( 7 ) , V_52 ) ;
return 0 ;
}
static int F_23 ( struct V_41 * V_42 ,
struct V_43 * V_49 , int V_45 )
{
unsigned int V_50 = 0 , V_51 = 0 , V_52 = 0 ;
if ( F_19 ( V_45 ) ) {
V_50 = F_3 ( 5 ) | F_3 ( 4 ) ;
V_51 = F_3 ( 2 ) ;
V_52 = F_3 ( 1 ) ;
}
F_4 ( V_42 -> V_2 , V_4 , F_3 ( 5 ) | F_3 ( 4 ) , V_50 ) ;
F_4 ( V_42 -> V_2 , V_53 , F_3 ( 2 ) , V_51 ) ;
F_4 ( V_42 -> V_2 , V_54 , F_3 ( 1 ) , V_52 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 ,
struct V_43 * V_49 , int V_45 )
{
unsigned int V_50 = 0 ;
if ( F_19 ( V_45 ) )
V_50 = F_3 ( 7 ) | F_3 ( 6 ) ;
F_4 ( V_42 -> V_2 , V_4 , F_3 ( 7 ) | F_3 ( 6 ) , V_50 ) ;
return 0 ;
}
static int F_25 ( struct V_55 * V_56 , int V_57 )
{
F_4 ( V_56 -> V_2 ,
V_58 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
F_4 ( V_56 -> V_2 ,
V_59 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
return 0 ;
}
static int F_26 ( struct V_55 * V_56 , int V_57 )
{
F_4 ( V_56 -> V_2 ,
V_60 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
F_4 ( V_56 -> V_2 ,
V_61 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
return 0 ;
}
static int F_27 ( struct V_62 * V_63 ,
struct V_64 * V_65 , struct V_55 * V_56 )
{
unsigned int V_66 , V_67 ;
switch ( F_28 ( V_65 ) ) {
case V_68 :
V_66 = F_3 ( 4 ) | F_3 ( 5 ) ;
break;
case V_69 :
V_66 = 0 ;
break;
default:
return - V_16 ;
}
F_4 ( V_56 -> V_2 , V_39 ,
F_3 ( 4 ) | F_3 ( 5 ) , V_66 ) ;
switch ( F_29 ( V_65 ) ) {
case 48000 :
F_10 ( L_14 ) ;
V_67 = 0 ;
break;
case 44100 :
F_10 ( L_15 ) ;
V_67 = F_3 ( 7 ) ;
break;
default:
F_9 ( L_16 , F_29 ( V_65 ) ) ;
return - V_16 ;
}
F_4 ( V_56 -> V_2 , V_70 , F_3 ( 7 ) , V_67 ) ;
return 0 ;
}
static inline void F_30 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_71 , 0x00 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_72 , 0x77 ) ;
F_2 ( V_2 , V_71 , 0x01 ) ;
}
static int F_32 ( struct V_73 * V_74 )
{
int V_75 = F_11 ( V_74 -> V_2 ) ;
int V_76 = F_33 ( V_74 , V_75 ) ;
F_10 ( L_17 , V_76 ) ;
if ( V_76 == V_77 )
F_31 ( V_74 -> V_2 ) ;
return V_76 ;
}
void F_34 ( struct V_78 * V_79 )
{
unsigned int V_80 ;
unsigned int V_81 = V_82 | V_83 | V_77 ;
F_10 ( L_18 , V_79 -> V_84 ) ;
if ( V_79 -> V_84 & 0x1 ) {
F_10 ( L_19 ) ;
V_80 = V_77 | V_82 ;
} else if ( V_79 -> V_84 & 0x2 ) {
F_10 ( L_20 ) ;
V_80 = V_77 | V_83 ;
} else if ( V_79 -> V_84 & 0x4 ) {
F_10 ( L_21 ) ;
V_80 = F_32 ( V_79 -> V_74 ) ;
} else if ( V_79 -> V_84 & 0x8 ) {
F_10 ( L_22 ) ;
V_80 = 0 ;
F_30 ( V_79 -> V_74 -> V_2 ) ;
} else {
F_9 ( L_23 ) ;
return;
}
F_35 ( V_79 -> V_74 , V_80 , V_81 ) ;
if ( ( V_80 & V_82 ) | ( V_80 & V_83 ) )
F_35 ( V_79 -> V_74 ,
V_77 , V_81 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
F_10 ( L_24 ) ;
F_2 ( V_2 , V_85 , 0x10 ) ;
F_2 ( V_2 , V_86 , 0x32 ) ;
F_2 ( V_2 , V_87 , 0x54 ) ;
F_2 ( V_2 , V_88 , 0x10 ) ;
F_2 ( V_2 , V_89 , 0x32 ) ;
F_2 ( V_2 , V_70 , 0x00 ) ;
F_2 ( V_2 , V_90 , 0x01 ) ;
F_2 ( V_2 , V_39 , 0x0A ) ;
F_2 ( V_2 , V_91 , F_3 ( 0 ) | F_3 ( 4 ) ) ;
F_2 ( V_2 , V_92 , 0x80 ) ;
F_2 ( V_2 , V_93 , 0x80 ) ;
F_2 ( V_2 , V_94 , 0x00 ) ;
F_2 ( V_2 , V_95 , 0x00 ) ;
F_2 ( V_2 , V_96 , 0x00 ) ;
F_2 ( V_2 , V_97 , 0x00 ) ;
F_2 ( V_2 , V_98 , 0x3 ) ;
F_2 ( V_2 , V_58 , 0x08 ) ;
F_2 ( V_2 , V_59 , 0x08 ) ;
F_2 ( V_2 , V_60 , 0x08 ) ;
F_2 ( V_2 , V_61 , 0x08 ) ;
F_2 ( V_2 , V_99 , 0x10 ) ;
F_2 ( V_2 , V_100 , 0x40 ) ;
F_37 ( V_2 , V_101 ,
F_38 ( V_101 ) ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 )
{
F_10 ( L_25 ) ;
F_17 ( V_2 , V_40 ) ;
return 0 ;
}
static int T_3 F_40 ( struct V_102 * V_103 )
{
F_10 ( L_26 , F_41 ( & V_103 -> V_104 ) ) ;
return F_42 ( & V_103 -> V_104 , & V_5 ,
V_105 , F_38 ( V_105 ) ) ;
}
static int T_4 F_43 ( struct V_102 * V_103 )
{
F_10 ( L_27 ) ;
F_44 ( & V_103 -> V_104 ) ;
return 0 ;
}
