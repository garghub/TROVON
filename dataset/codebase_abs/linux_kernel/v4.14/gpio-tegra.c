static inline void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , T_1 V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned int F_5 ( unsigned int V_6 , unsigned int V_7 ,
unsigned int V_8 )
{
return ( V_6 << 5 ) | ( ( V_7 & 0x3 ) << 3 ) | ( V_8 & 0x7 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_4 ,
unsigned int V_9 , T_1 V_10 )
{
T_1 V_3 ;
V_3 = 0x100 << F_7 ( V_9 ) ;
if ( V_10 )
V_3 |= 1 << F_7 ( V_9 ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 , unsigned int V_9 )
{
F_6 ( V_2 , F_9 ( V_2 , V_9 ) , V_9 , 1 ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned int V_9 )
{
F_6 ( V_2 , F_9 ( V_2 , V_9 ) , V_9 , 0 ) ;
}
static int F_11 ( struct V_11 * V_12 , unsigned int V_13 )
{
return F_12 ( V_13 ) ;
}
static void F_13 ( struct V_11 * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_15 ( V_13 ) ;
F_10 ( V_2 , V_13 ) ;
}
static void F_16 ( struct V_11 * V_12 , unsigned int V_13 ,
int V_10 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_6 ( V_2 , F_17 ( V_2 , V_13 ) , V_13 , V_10 ) ;
}
static int F_18 ( struct V_11 * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
unsigned int V_14 = F_19 ( F_7 ( V_13 ) ) ;
if ( F_3 ( V_2 , F_20 ( V_2 , V_13 ) ) & V_14 )
return ! ! ( F_3 ( V_2 , F_21 ( V_2 , V_13 ) ) & V_14 ) ;
return ! ! ( F_3 ( V_2 , F_22 ( V_2 , V_13 ) ) & V_14 ) ;
}
static int F_23 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_6 ( V_2 , F_24 ( V_2 , V_13 ) , V_13 , 0 ) ;
F_8 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_25 ( struct V_11 * V_12 ,
unsigned int V_13 ,
int V_10 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
F_16 ( V_12 , V_13 , V_10 ) ;
F_6 ( V_2 , F_24 ( V_2 , V_13 ) , V_13 , 1 ) ;
F_8 ( V_2 , V_13 ) ;
return 0 ;
}
static int F_26 ( struct V_11 * V_12 ,
unsigned int V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
T_1 V_15 = F_19 ( F_7 ( V_13 ) ) ;
T_1 V_16 , V_17 ;
V_16 = F_3 ( V_2 , F_27 ( V_2 , V_13 ) ) ;
if ( ! ( V_16 & V_15 ) )
return - V_18 ;
V_17 = F_3 ( V_2 , F_20 ( V_2 , V_13 ) ) ;
return ( V_17 & V_15 ) ? V_19 : V_20 ;
}
static int F_28 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned int V_21 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
struct V_22 * V_6 = & V_2 -> V_23 [ F_29 ( V_13 ) ] ;
unsigned int V_24 = F_30 ( V_21 , 1000 ) ;
unsigned long V_25 ;
unsigned int V_7 ;
if ( ! V_24 ) {
F_6 ( V_2 , F_31 ( V_2 , V_13 ) ,
V_13 , 0 ) ;
return 0 ;
}
V_24 = F_32 ( V_24 , 255U ) ;
V_7 = F_33 ( V_13 ) ;
F_34 ( & V_6 -> V_26 [ V_7 ] , V_25 ) ;
if ( V_6 -> V_27 [ V_7 ] < V_24 ) {
F_1 ( V_2 , V_24 , F_35 ( V_2 , V_13 ) ) ;
V_6 -> V_27 [ V_7 ] = V_24 ;
}
F_36 ( & V_6 -> V_26 [ V_7 ] , V_25 ) ;
F_6 ( V_2 , F_31 ( V_2 , V_13 ) , V_13 , 1 ) ;
return 0 ;
}
static int F_37 ( struct V_11 * V_12 , unsigned int V_13 ,
unsigned long V_28 )
{
T_1 V_21 ;
if ( F_38 ( V_28 ) != V_29 )
return - V_30 ;
V_21 = F_39 ( V_28 ) ;
return F_28 ( V_12 , V_13 , V_21 ) ;
}
static int F_40 ( struct V_11 * V_12 , unsigned int V_13 )
{
struct V_1 * V_2 = F_14 ( V_12 ) ;
return F_41 ( V_2 -> V_31 , V_13 ) ;
}
static void F_42 ( struct V_32 * V_33 )
{
struct V_22 * V_6 = F_43 ( V_33 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned int V_9 = V_33 -> V_34 ;
F_1 ( V_2 , 1 << F_7 ( V_9 ) , F_44 ( V_2 , V_9 ) ) ;
}
static void F_45 ( struct V_32 * V_33 )
{
struct V_22 * V_6 = F_43 ( V_33 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned int V_9 = V_33 -> V_34 ;
F_6 ( V_2 , F_46 ( V_2 , V_9 ) , V_9 , 0 ) ;
}
static void F_47 ( struct V_32 * V_33 )
{
struct V_22 * V_6 = F_43 ( V_33 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned int V_9 = V_33 -> V_34 ;
F_6 ( V_2 , F_46 ( V_2 , V_9 ) , V_9 , 1 ) ;
}
static int F_48 ( struct V_32 * V_33 , unsigned int type )
{
unsigned int V_9 = V_33 -> V_34 , V_7 = F_33 ( V_9 ) , V_35 ;
struct V_22 * V_6 = F_43 ( V_33 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned long V_25 ;
T_1 V_3 ;
int V_36 ;
switch ( type & V_37 ) {
case V_38 :
V_35 = V_39 ;
break;
case V_40 :
V_35 = V_41 ;
break;
case V_42 :
V_35 = V_43 ;
break;
case V_44 :
V_35 = V_45 ;
break;
case V_46 :
V_35 = V_47 ;
break;
default:
return - V_18 ;
}
V_36 = F_49 ( & V_2 -> V_48 , V_9 ) ;
if ( V_36 ) {
F_50 ( V_2 -> V_49 ,
L_1 , V_9 ) ;
return V_36 ;
}
F_34 ( & V_6 -> V_50 [ V_7 ] , V_25 ) ;
V_3 = F_3 ( V_2 , F_51 ( V_2 , V_9 ) ) ;
V_3 &= ~ ( V_51 << F_7 ( V_9 ) ) ;
V_3 |= V_35 << F_7 ( V_9 ) ;
F_1 ( V_2 , V_3 , F_51 ( V_2 , V_9 ) ) ;
F_36 ( & V_6 -> V_50 [ V_7 ] , V_25 ) ;
F_6 ( V_2 , F_24 ( V_2 , V_9 ) , V_9 , 0 ) ;
F_8 ( V_2 , V_9 ) ;
if ( type & ( V_46 | V_44 ) )
F_52 ( V_33 , V_52 ) ;
else if ( type & ( V_40 | V_38 ) )
F_52 ( V_33 , V_53 ) ;
return 0 ;
}
static void F_53 ( struct V_32 * V_33 )
{
struct V_22 * V_6 = F_43 ( V_33 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
unsigned int V_9 = V_33 -> V_34 ;
F_54 ( & V_2 -> V_48 , V_9 ) ;
}
static void F_55 ( struct V_54 * V_55 )
{
unsigned int V_7 , V_56 , V_9 ;
bool V_57 = false ;
T_1 V_58 ;
unsigned long V_59 ;
struct V_60 * V_12 = F_56 ( V_55 ) ;
struct V_22 * V_6 = F_57 ( V_55 ) ;
struct V_1 * V_2 = V_6 -> V_2 ;
F_58 ( V_12 , V_55 ) ;
for ( V_7 = 0 ; V_7 < 4 ; V_7 ++ ) {
V_9 = F_5 ( V_6 -> V_6 , V_7 , 0 ) ;
V_59 = F_3 ( V_2 , F_59 ( V_2 , V_9 ) ) &
F_3 ( V_2 , F_60 ( V_2 , V_9 ) ) ;
V_58 = F_3 ( V_2 , F_51 ( V_2 , V_9 ) ) ;
F_61 (pin, &sta, 8 ) {
F_1 ( V_2 , 1 << V_56 ,
F_44 ( V_2 , V_9 ) ) ;
if ( ! V_57 && V_58 & ( 0x100 << V_56 ) ) {
V_57 = true ;
F_62 ( V_12 , V_55 ) ;
}
F_63 ( F_41 ( V_2 -> V_31 ,
V_9 + V_56 ) ) ;
}
}
if ( ! V_57 )
F_62 ( V_12 , V_55 ) ;
}
static int F_64 ( struct V_61 * V_49 )
{
struct V_62 * V_63 = F_65 ( V_49 ) ;
struct V_1 * V_2 = F_66 ( V_63 ) ;
unsigned long V_25 ;
unsigned int V_64 , V_65 ;
F_67 ( V_25 ) ;
for ( V_64 = 0 ; V_64 < V_2 -> V_66 ; V_64 ++ ) {
struct V_22 * V_6 = & V_2 -> V_23 [ V_64 ] ;
for ( V_65 = 0 ; V_65 < F_68 ( V_6 -> V_17 ) ; V_65 ++ ) {
unsigned int V_9 = ( V_64 << 5 ) | ( V_65 << 3 ) ;
F_1 ( V_2 , V_6 -> V_16 [ V_65 ] ,
F_27 ( V_2 , V_9 ) ) ;
if ( V_2 -> V_67 -> V_68 ) {
F_1 ( V_2 , V_6 -> V_27 [ V_65 ] ,
F_35 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_69 [ V_65 ] ,
F_31 ( V_2 , V_9 ) ) ;
}
F_1 ( V_2 , V_6 -> V_70 [ V_65 ] ,
F_21 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_17 [ V_65 ] ,
F_20 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_71 [ V_65 ] ,
F_51 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_72 [ V_65 ] ,
F_60 ( V_2 , V_9 ) ) ;
}
}
F_69 ( V_25 ) ;
return 0 ;
}
static int F_70 ( struct V_61 * V_49 )
{
struct V_62 * V_63 = F_65 ( V_49 ) ;
struct V_1 * V_2 = F_66 ( V_63 ) ;
unsigned long V_25 ;
unsigned int V_64 , V_65 ;
F_67 ( V_25 ) ;
for ( V_64 = 0 ; V_64 < V_2 -> V_66 ; V_64 ++ ) {
struct V_22 * V_6 = & V_2 -> V_23 [ V_64 ] ;
for ( V_65 = 0 ; V_65 < F_68 ( V_6 -> V_17 ) ; V_65 ++ ) {
unsigned int V_9 = ( V_64 << 5 ) | ( V_65 << 3 ) ;
V_6 -> V_16 [ V_65 ] = F_3 ( V_2 ,
F_27 ( V_2 , V_9 ) ) ;
V_6 -> V_70 [ V_65 ] = F_3 ( V_2 ,
F_21 ( V_2 , V_9 ) ) ;
V_6 -> V_17 [ V_65 ] = F_3 ( V_2 ,
F_20 ( V_2 , V_9 ) ) ;
if ( V_2 -> V_67 -> V_68 ) {
V_6 -> V_69 [ V_65 ] = F_3 ( V_2 ,
F_31 ( V_2 , V_9 ) ) ;
V_6 -> V_69 [ V_65 ] = ( V_6 -> V_69 [ V_65 ] << 8 ) |
V_6 -> V_69 [ V_65 ] ;
}
V_6 -> V_72 [ V_65 ] = F_3 ( V_2 ,
F_60 ( V_2 , V_9 ) ) ;
V_6 -> V_71 [ V_65 ] = F_3 ( V_2 ,
F_51 ( V_2 , V_9 ) ) ;
F_1 ( V_2 , V_6 -> V_73 [ V_65 ] ,
F_60 ( V_2 , V_9 ) ) ;
}
}
F_69 ( V_25 ) ;
return 0 ;
}
static int F_71 ( struct V_32 * V_33 , unsigned int V_74 )
{
struct V_22 * V_6 = F_43 ( V_33 ) ;
unsigned int V_9 = V_33 -> V_34 ;
T_1 V_7 , V_8 , V_75 ;
V_7 = F_33 ( V_9 ) ;
V_8 = F_7 ( V_9 ) ;
V_75 = F_19 ( V_8 ) ;
if ( V_74 )
V_6 -> V_73 [ V_7 ] |= V_75 ;
else
V_6 -> V_73 [ V_7 ] &= ~ V_75 ;
return F_72 ( V_6 -> V_76 , V_74 ) ;
}
static int F_73 ( struct V_77 * V_78 , void * V_79 )
{
struct V_1 * V_2 = V_78 -> V_80 ;
unsigned int V_81 , V_82 ;
for ( V_81 = 0 ; V_81 < V_2 -> V_66 ; V_81 ++ ) {
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
unsigned int V_9 = F_5 ( V_81 , V_82 , 0 ) ;
F_74 ( V_78 ,
L_2 ,
V_81 , V_82 ,
F_3 ( V_2 , F_27 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_20 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_21 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_22 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_59 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_60 ( V_2 , V_9 ) ) ,
F_3 ( V_2 , F_51 ( V_2 , V_9 ) ) ) ;
}
}
return 0 ;
}
static int F_75 ( struct V_83 * V_83 , struct V_84 * V_84 )
{
return F_76 ( V_84 , F_73 , V_83 -> V_85 ) ;
}
static void F_77 ( struct V_1 * V_2 )
{
( void ) F_78 ( L_3 , 0444 ,
NULL , V_2 , & V_86 ) ;
}
static inline void F_77 ( struct V_1 * V_2 )
{
}
static int F_79 ( struct V_62 * V_63 )
{
struct V_1 * V_2 ;
struct V_87 * V_88 ;
struct V_22 * V_6 ;
unsigned int V_9 , V_81 , V_82 ;
int V_36 ;
V_2 = F_80 ( & V_63 -> V_49 , sizeof( * V_2 ) , V_89 ) ;
if ( ! V_2 )
return - V_90 ;
V_2 -> V_67 = F_81 ( & V_63 -> V_49 ) ;
V_2 -> V_49 = & V_63 -> V_49 ;
V_36 = F_82 ( V_63 ) ;
if ( V_36 < 0 )
return V_36 ;
V_2 -> V_66 = V_36 ;
if ( ! V_2 -> V_66 ) {
F_50 ( & V_63 -> V_49 , L_4 ) ;
return - V_90 ;
}
V_2 -> V_48 . V_91 = L_5 ;
V_2 -> V_48 . V_92 = F_11 ;
V_2 -> V_48 . free = F_13 ;
V_2 -> V_48 . V_93 = F_23 ;
V_2 -> V_48 . V_94 = F_18 ;
V_2 -> V_48 . V_95 = F_25 ;
V_2 -> V_48 . V_96 = F_16 ;
V_2 -> V_48 . V_97 = F_26 ;
V_2 -> V_48 . V_98 = F_40 ;
V_2 -> V_48 . V_99 = 0 ;
V_2 -> V_48 . V_100 = V_2 -> V_66 * 32 ;
V_2 -> V_48 . V_101 = & V_63 -> V_49 ;
V_2 -> V_48 . V_102 = V_63 -> V_49 . V_102 ;
V_2 -> V_103 . V_104 = L_6 ;
V_2 -> V_103 . V_105 = F_42 ;
V_2 -> V_103 . V_106 = F_45 ;
V_2 -> V_103 . V_107 = F_47 ;
V_2 -> V_103 . V_108 = F_48 ;
V_2 -> V_103 . V_109 = F_53 ;
#ifdef F_83
V_2 -> V_103 . V_110 = F_71 ;
#endif
F_84 ( V_63 , V_2 ) ;
if ( V_2 -> V_67 -> V_68 )
V_2 -> V_48 . V_111 = F_37 ;
V_2 -> V_23 = F_85 ( & V_63 -> V_49 , V_2 -> V_66 ,
sizeof( * V_2 -> V_23 ) , V_89 ) ;
if ( ! V_2 -> V_23 )
return - V_112 ;
V_2 -> V_31 = F_86 ( V_63 -> V_49 . V_102 ,
V_2 -> V_48 . V_100 ,
& V_113 , NULL ) ;
if ( ! V_2 -> V_31 )
return - V_90 ;
for ( V_81 = 0 ; V_81 < V_2 -> V_66 ; V_81 ++ ) {
V_36 = F_87 ( V_63 , V_81 ) ;
if ( V_36 < 0 ) {
F_50 ( & V_63 -> V_49 , L_7 , V_36 ) ;
return V_36 ;
}
V_6 = & V_2 -> V_23 [ V_81 ] ;
V_6 -> V_6 = V_81 ;
V_6 -> V_76 = V_36 ;
V_6 -> V_2 = V_2 ;
}
V_88 = F_88 ( V_63 , V_114 , 0 ) ;
V_2 -> V_5 = F_89 ( & V_63 -> V_49 , V_88 ) ;
if ( F_90 ( V_2 -> V_5 ) )
return F_91 ( V_2 -> V_5 ) ;
for ( V_81 = 0 ; V_81 < V_2 -> V_66 ; V_81 ++ ) {
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
int V_9 = F_5 ( V_81 , V_82 , 0 ) ;
F_1 ( V_2 , 0x00 , F_60 ( V_2 , V_9 ) ) ;
}
}
V_36 = F_92 ( & V_63 -> V_49 , & V_2 -> V_48 , V_2 ) ;
if ( V_36 < 0 ) {
F_93 ( V_2 -> V_31 ) ;
return V_36 ;
}
for ( V_9 = 0 ; V_9 < V_2 -> V_48 . V_100 ; V_9 ++ ) {
int V_76 = F_94 ( V_2 -> V_31 , V_9 ) ;
V_6 = & V_2 -> V_23 [ F_29 ( V_9 ) ] ;
F_95 ( V_76 , & V_115 ) ;
F_96 ( V_76 , V_6 ) ;
F_97 ( V_76 , & V_2 -> V_103 , V_116 ) ;
}
for ( V_81 = 0 ; V_81 < V_2 -> V_66 ; V_81 ++ ) {
V_6 = & V_2 -> V_23 [ V_81 ] ;
F_98 ( V_6 -> V_76 ,
F_55 , V_6 ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ ) {
F_99 ( & V_6 -> V_50 [ V_82 ] ) ;
F_99 ( & V_6 -> V_26 [ V_82 ] ) ;
}
}
F_77 ( V_2 ) ;
return 0 ;
}
static int T_2 F_100 ( void )
{
return F_101 ( & V_117 ) ;
}
