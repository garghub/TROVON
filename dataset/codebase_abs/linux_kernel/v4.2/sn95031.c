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
static int F_13 ( void * V_29 , unsigned int V_30 , unsigned int * V_6 )
{
T_2 V_7 = 0 ;
int V_31 ;
V_31 = F_14 ( V_30 , & V_7 ) ;
if ( V_31 == 0 )
* V_6 = V_7 ;
return V_31 ;
}
static int F_15 ( void * V_29 , unsigned int V_30 , unsigned int V_7 )
{
return F_16 ( V_30 , V_7 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_32 V_33 )
{
switch ( V_33 ) {
case V_34 :
break;
case V_35 :
if ( F_18 ( V_2 ) == V_36 ) {
F_10 ( L_4 ) ;
F_2 ( V_2 , V_37 , F_3 ( 5 ) ) ;
F_4 ( V_2 , V_38 ,
F_3 ( 0 ) , F_3 ( 0 ) ) ;
}
break;
case V_36 :
switch ( F_18 ( V_2 ) ) {
case V_39 :
F_10 ( L_5 ) ;
F_2 ( V_2 , V_3 ,
F_3 ( 2 ) | F_3 ( 1 ) | F_3 ( 0 ) ) ;
F_12 ( 1 ) ;
break;
case V_35 :
F_10 ( L_6 ) ;
F_4 ( V_2 , V_38 , F_3 ( 0 ) , 0 ) ;
F_2 ( V_2 , V_37 , 0 ) ;
break;
default:
break;
}
break;
case V_39 :
F_10 ( L_7 ) ;
F_2 ( V_2 , V_3 , F_3 ( 3 ) ) ;
break;
}
return 0 ;
}
static int F_19 ( struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 )
{
struct V_1 * V_2 = F_20 ( V_41 -> V_45 ) ;
if ( F_21 ( V_44 ) ) {
F_10 ( L_8 ) ;
F_2 ( V_2 , V_46 , 0x3D ) ;
F_2 ( V_2 , V_47 , 0x3F ) ;
F_12 ( 1 ) ;
} else if ( F_22 ( V_44 ) ) {
F_10 ( L_9 ) ;
F_2 ( V_2 , V_46 , 0xC4 ) ;
F_2 ( V_2 , V_47 , 0x04 ) ;
}
return 0 ;
}
static int F_23 ( struct V_40 * V_41 ,
struct V_42 * V_43 , int V_44 )
{
struct V_1 * V_2 = F_20 ( V_41 -> V_45 ) ;
if ( F_21 ( V_44 ) ) {
F_10 ( L_10 ) ;
F_2 ( V_2 , V_48 , 0x27 ) ;
F_12 ( 1 ) ;
} else if ( F_22 ( V_44 ) ) {
F_10 ( L_11 ) ;
F_2 ( V_2 , V_48 , 0x24 ) ;
}
return 0 ;
}
static int F_24 ( struct V_40 * V_41 ,
struct V_42 * V_49 , int V_44 )
{
struct V_1 * V_2 = F_20 ( V_41 -> V_45 ) ;
unsigned int V_50 = 0 , V_51 = 0 , V_52 = 0 ;
if ( F_21 ( V_44 ) ) {
V_50 = F_3 ( 5 ) | F_3 ( 4 ) ;
V_51 = F_3 ( 0 ) ;
V_52 = F_3 ( 7 ) ;
}
F_4 ( V_2 , V_4 , F_3 ( 5 ) | F_3 ( 4 ) , V_50 ) ;
F_4 ( V_2 , V_53 , F_3 ( 0 ) , V_51 ) ;
F_4 ( V_2 , V_53 , F_3 ( 7 ) , V_52 ) ;
return 0 ;
}
static int F_25 ( struct V_40 * V_41 ,
struct V_42 * V_49 , int V_44 )
{
struct V_1 * V_2 = F_20 ( V_41 -> V_45 ) ;
unsigned int V_50 = 0 , V_51 = 0 , V_52 = 0 ;
if ( F_21 ( V_44 ) ) {
V_50 = F_3 ( 5 ) | F_3 ( 4 ) ;
V_51 = F_3 ( 2 ) ;
V_52 = F_3 ( 1 ) ;
}
F_4 ( V_2 , V_4 , F_3 ( 5 ) | F_3 ( 4 ) , V_50 ) ;
F_4 ( V_2 , V_53 , F_3 ( 2 ) , V_51 ) ;
F_4 ( V_2 , V_54 , F_3 ( 1 ) , V_52 ) ;
return 0 ;
}
static int F_26 ( struct V_40 * V_41 ,
struct V_42 * V_49 , int V_44 )
{
struct V_1 * V_2 = F_20 ( V_41 -> V_45 ) ;
unsigned int V_50 = 0 ;
if ( F_21 ( V_44 ) )
V_50 = F_3 ( 7 ) | F_3 ( 6 ) ;
F_4 ( V_2 , V_4 , F_3 ( 7 ) | F_3 ( 6 ) , V_50 ) ;
return 0 ;
}
static int F_27 ( struct V_55 * V_56 , int V_57 )
{
F_4 ( V_56 -> V_2 ,
V_58 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
F_4 ( V_56 -> V_2 ,
V_59 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
return 0 ;
}
static int F_28 ( struct V_55 * V_56 , int V_57 )
{
F_4 ( V_56 -> V_2 ,
V_60 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
F_4 ( V_56 -> V_2 ,
V_61 , F_3 ( 7 ) , ( ! V_57 << 7 ) ) ;
return 0 ;
}
static int F_29 ( struct V_62 * V_63 ,
struct V_64 * V_65 , struct V_55 * V_56 )
{
unsigned int V_66 , V_67 ;
switch ( F_30 ( V_65 ) ) {
case 16 :
V_66 = F_3 ( 4 ) | F_3 ( 5 ) ;
break;
case 24 :
V_66 = 0 ;
break;
default:
return - V_16 ;
}
F_4 ( V_56 -> V_2 , V_38 ,
F_3 ( 4 ) | F_3 ( 5 ) , V_66 ) ;
switch ( F_31 ( V_65 ) ) {
case 48000 :
F_10 ( L_12 ) ;
V_67 = 0 ;
break;
case 44100 :
F_10 ( L_13 ) ;
V_67 = F_3 ( 7 ) ;
break;
default:
F_9 ( L_14 , F_31 ( V_65 ) ) ;
return - V_16 ;
}
F_4 ( V_56 -> V_2 , V_68 , F_3 ( 7 ) , V_67 ) ;
return 0 ;
}
static inline void F_32 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_69 , 0x00 ) ;
}
static inline void F_33 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_70 , 0x77 ) ;
F_2 ( V_2 , V_69 , 0x01 ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
int V_73 = F_11 ( V_2 ) ;
int V_74 = F_35 ( V_72 , V_73 ) ;
F_10 ( L_15 , V_74 ) ;
if ( V_74 == V_75 )
F_33 ( V_2 ) ;
return V_74 ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_76 * V_77 )
{
unsigned int V_78 ;
unsigned int V_79 = V_80 | V_81 | V_75 ;
F_10 ( L_16 , V_77 -> V_82 ) ;
if ( V_77 -> V_82 & 0x1 ) {
F_10 ( L_17 ) ;
V_78 = V_75 | V_80 ;
} else if ( V_77 -> V_82 & 0x2 ) {
F_10 ( L_18 ) ;
V_78 = V_75 | V_81 ;
} else if ( V_77 -> V_82 & 0x4 ) {
F_10 ( L_19 ) ;
V_78 = F_34 ( V_2 , V_77 -> V_72 ) ;
} else if ( V_77 -> V_82 & 0x8 ) {
F_10 ( L_20 ) ;
V_78 = 0 ;
F_32 ( V_2 ) ;
} else {
F_9 ( L_21 ) ;
return;
}
F_37 ( V_77 -> V_72 , V_78 , V_79 ) ;
if ( ( V_78 & V_80 ) | ( V_78 & V_81 ) )
F_37 ( V_77 -> V_72 ,
V_75 , V_79 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
F_10 ( L_22 ) ;
F_2 ( V_2 , V_83 , 0x10 ) ;
F_2 ( V_2 , V_84 , 0x32 ) ;
F_2 ( V_2 , V_85 , 0x54 ) ;
F_2 ( V_2 , V_86 , 0x10 ) ;
F_2 ( V_2 , V_87 , 0x32 ) ;
F_2 ( V_2 , V_68 , 0x00 ) ;
F_2 ( V_2 , V_88 , 0x01 ) ;
F_2 ( V_2 , V_38 , 0x0A ) ;
F_2 ( V_2 , V_89 , F_3 ( 0 ) | F_3 ( 4 ) ) ;
F_2 ( V_2 , V_90 , 0x80 ) ;
F_2 ( V_2 , V_91 , 0x80 ) ;
F_2 ( V_2 , V_92 , 0x00 ) ;
F_2 ( V_2 , V_93 , 0x00 ) ;
F_2 ( V_2 , V_94 , 0x00 ) ;
F_2 ( V_2 , V_95 , 0x00 ) ;
F_2 ( V_2 , V_96 , 0x3 ) ;
F_2 ( V_2 , V_58 , 0x08 ) ;
F_2 ( V_2 , V_59 , 0x08 ) ;
F_2 ( V_2 , V_60 , 0x08 ) ;
F_2 ( V_2 , V_61 , 0x08 ) ;
F_2 ( V_2 , V_97 , 0x10 ) ;
F_2 ( V_2 , V_98 , 0x40 ) ;
return 0 ;
}
static int F_39 ( struct V_99 * V_100 )
{
struct V_101 * V_101 ;
F_10 ( L_23 , F_40 ( & V_100 -> V_102 ) ) ;
V_101 = F_41 ( & V_100 -> V_102 , NULL , NULL , & V_103 ) ;
if ( F_42 ( V_101 ) )
return F_43 ( V_101 ) ;
return F_44 ( & V_100 -> V_102 , & V_5 ,
V_104 , F_45 ( V_104 ) ) ;
}
static int F_46 ( struct V_99 * V_100 )
{
F_10 ( L_24 ) ;
F_47 ( & V_100 -> V_102 ) ;
return 0 ;
}
