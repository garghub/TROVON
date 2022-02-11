static void F_1 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 )
{
T_1 V_5 = 1 << V_3 ;
T_1 V_6 , V_7 ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & ~ V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & ~ V_5 ;
if ( V_4 & V_11 )
V_6 |= V_5 ;
if ( V_4 & V_12 )
V_7 |= V_5 ;
F_3 ( V_6 , V_2 -> V_8 + V_9 ) ;
F_3 ( V_7 , V_2 -> V_8 + V_10 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
unsigned V_3 , enum V_13 V_14 )
{
T_1 V_5 = 1 << V_3 ;
T_1 V_15 ;
V_15 = F_2 ( V_2 -> V_8 + V_16 ) ;
if ( V_14 == V_17 )
V_15 |= V_5 ;
else
V_15 &= ~ V_5 ;
F_3 ( V_15 , V_2 -> V_8 + V_16 ) ;
}
static void F_5 ( struct V_1 * V_2 ,
unsigned V_3 , enum V_18 V_19 )
{
T_1 V_5 = 1 << V_3 ;
T_1 V_20 ;
V_20 = F_2 ( V_2 -> V_8 + V_21 ) ;
if ( V_19 == V_22 ) {
V_20 |= V_5 ;
V_2 -> V_23 &= ~ V_5 ;
} else {
V_20 &= ~ V_5 ;
}
F_3 ( V_20 , V_2 -> V_8 + V_21 ) ;
if ( V_19 == V_24 ) {
V_2 -> V_23 |= V_5 ;
F_3 ( V_5 , V_2 -> V_8 + V_25 ) ;
} else if ( V_19 == V_26 ) {
V_2 -> V_23 &= ~ V_5 ;
F_3 ( V_5 , V_2 -> V_8 + V_27 ) ;
}
}
static void F_6 ( struct V_1 * V_2 ,
unsigned V_3 )
{
F_3 ( 1 << V_3 , V_2 -> V_8 + V_28 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned V_3 , int V_29 )
{
if ( V_29 )
F_3 ( 1 << V_3 , V_2 -> V_8 + V_25 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_8 + V_27 ) ;
}
static void F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_29 )
{
F_3 ( 1 << V_3 , V_2 -> V_8 + V_30 ) ;
F_7 ( V_2 , V_3 , V_29 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 ,
bool V_31 )
{
T_1 V_32 = F_2 ( V_2 -> V_8 + V_33 ) ;
T_1 V_34 = F_2 ( V_2 -> V_8 + V_35 ) ;
if ( V_31 && V_2 -> V_36 ) {
T_1 V_5 = F_10 ( V_3 ) ;
F_3 ( V_32 & ~ V_5 , V_2 -> V_8 + V_33 ) ;
F_3 ( V_34 & ~ V_5 , V_2 -> V_8 + V_35 ) ;
V_2 -> V_36 ( true ) ;
}
F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_31 && V_2 -> V_36 ) {
V_2 -> V_36 ( false ) ;
F_3 ( V_32 , V_2 -> V_8 + V_33 ) ;
F_3 ( V_34 , V_2 -> V_8 + V_35 ) ;
}
}
static void F_11 ( struct V_1 * V_2 , unsigned V_3 ,
T_2 V_37 , bool V_38 , unsigned int * V_39 )
{
static const char * V_40 [] = {
[ V_41 ] = L_1 ,
[ V_11 ] = L_2 ,
[ V_12 ] = L_3 ,
[ V_42 ] = L_4
} ;
static const char * V_43 [] = {
[ V_22 ] = L_5 ,
[ V_24 ] = L_6 ,
[ V_26 ] = L_7 ,
[ 3 ] = L_8
} ;
static const char * V_44 [] = {
[ V_45 ] = L_9 ,
[ V_17 ] = L_10 ,
} ;
int V_46 = F_12 ( V_37 ) ;
int V_19 = F_13 ( V_37 ) ;
int V_47 = F_14 ( V_37 ) ;
int V_15 = F_15 ( V_37 ) ;
int V_48 = F_16 ( V_37 ) ;
int V_29 = F_17 ( V_37 ) ;
bool V_31 = V_47 == V_42 ;
F_18 ( V_2 -> V_49 . V_50 , L_11 ,
V_46 , V_37 , V_40 [ V_47 ] , V_43 [ V_19 ] , V_44 [ V_15 ] ,
V_48 ? L_12 : L_13 ,
V_48 ? ( V_29 ? L_14 : L_15 ) : L_16 ) ;
if ( V_38 ) {
int V_51 = F_19 ( V_37 ) ;
int V_52 = F_20 ( V_37 ) ;
int V_53 = F_21 ( V_37 ) ;
V_47 = V_41 ;
if ( V_51 )
V_19 = V_51 - 1 ;
if ( V_52 )
V_48 = V_52 - 1 ;
if ( V_53 )
V_29 = V_53 - 1 ;
F_18 ( V_2 -> V_49 . V_50 , L_17 ,
V_46 ,
V_51 ? V_43 [ V_19 ] : L_18 ,
V_52 ? ( V_48 ? L_19 : L_13 ) : L_18 ,
V_53 ? ( V_29 ? L_14 : L_15 ) : L_18 ) ;
}
if ( V_48 )
F_8 ( V_2 , V_3 , V_29 ) ;
else {
F_6 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 , V_19 ) ;
}
if ( V_39 ) {
if ( V_15 == V_17 )
V_39 [ V_2 -> V_54 ] |= F_10 ( V_3 ) ;
else
V_39 [ V_2 -> V_54 ] &= ~ F_10 ( V_3 ) ;
} else
F_4 ( V_2 , V_3 , V_15 ) ;
F_9 ( V_2 , V_3 , V_47 , V_31 ) ;
}
static void F_22 ( unsigned int * V_15 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
unsigned int V_58 = V_15 [ V_55 ] ;
if ( ! V_49 )
break;
V_15 [ V_55 ] = F_2 ( V_49 -> V_8 + V_16 ) ;
F_3 ( V_58 , V_49 -> V_8 + V_16 ) ;
}
}
static void F_23 ( unsigned int * V_15 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
break;
F_3 ( V_15 [ V_55 ] , V_49 -> V_8 + V_16 ) ;
}
}
static int F_24 ( T_2 * V_59 , int V_60 , bool V_38 )
{
static unsigned int V_15 [ V_56 ] ;
unsigned long V_61 ;
bool V_31 = false ;
int V_62 = 0 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_60 ; V_55 ++ ) {
if ( F_14 ( V_59 [ V_55 ] ) == V_42 ) {
V_31 = true ;
break;
}
}
F_25 ( & V_63 , V_61 ) ;
if ( V_31 ) {
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_55 = 0 ; V_55 < V_60 ; V_55 ++ ) {
int V_46 = F_12 ( V_59 [ V_55 ] ) ;
int V_3 = V_46 % V_64 ;
if ( F_14 ( V_59 [ V_55 ] ) == V_42 )
V_15 [ V_46 / V_64 ] &= ~ F_10 ( V_3 ) ;
}
F_22 ( V_15 ) ;
}
for ( V_55 = 0 ; V_55 < V_60 ; V_55 ++ ) {
struct V_1 * V_2 ;
int V_46 = F_12 ( V_59 [ V_55 ] ) ;
V_2 = F_26 ( F_27 ( V_46 ) ) ;
if ( ! V_2 ) {
V_62 = - V_65 ;
break;
}
F_28 ( & V_2 -> V_66 ) ;
F_11 ( V_2 , V_46 - V_2 -> V_49 . V_67 ,
V_59 [ V_55 ] , V_38 , V_31 ? V_15 : NULL ) ;
F_29 ( & V_2 -> V_66 ) ;
}
if ( V_31 )
F_23 ( V_15 ) ;
F_30 ( & V_63 , V_61 ) ;
return V_62 ;
}
int F_31 ( T_2 V_37 , bool V_38 )
{
return F_24 ( & V_37 , 1 , V_38 ) ;
}
int F_32 ( T_2 * V_59 , int V_60 )
{
return F_24 ( V_59 , V_60 , false ) ;
}
int F_33 ( T_2 * V_59 , int V_60 )
{
return F_24 ( V_59 , V_60 , true ) ;
}
int F_34 ( int V_68 , enum V_13 V_14 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
V_2 = F_26 ( F_27 ( V_68 ) ) ;
if ( ! V_2 )
return - V_65 ;
F_25 ( & V_63 , V_61 ) ;
F_28 ( & V_2 -> V_66 ) ;
F_4 ( V_2 , V_68 - V_2 -> V_49 . V_67 , V_14 ) ;
F_29 ( & V_2 -> V_66 ) ;
F_30 ( & V_63 , V_61 ) ;
return 0 ;
}
int F_35 ( int V_68 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
V_2 = F_26 ( F_27 ( V_68 ) ) ;
if ( ! V_2 )
return - V_65 ;
F_25 ( & V_2 -> V_66 , V_61 ) ;
F_5 ( V_2 , V_68 - V_2 -> V_49 . V_67 , V_19 ) ;
F_30 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
int F_36 ( int V_68 , int V_4 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
V_2 = F_26 ( F_27 ( V_68 ) ) ;
if ( ! V_2 )
return - V_65 ;
F_25 ( & V_2 -> V_66 , V_61 ) ;
F_1 ( V_2 , V_68 - V_2 -> V_49 . V_67 , V_4 ) ;
F_30 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
int F_37 ( int V_68 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = F_26 ( F_27 ( V_68 ) ) ;
if ( ! V_2 )
return - V_65 ;
V_5 = 1 << ( V_68 - V_2 -> V_49 . V_67 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_38 ( int V_68 )
{
return 1 << ( V_68 % 32 ) ;
}
static void F_39 ( struct V_69 * V_70 )
{
int V_68 ;
struct V_1 * V_2 ;
V_68 = F_40 ( V_70 -> V_71 ) ;
V_2 = F_41 ( V_70 ) ;
if ( ! V_2 )
return;
F_3 ( F_38 ( V_68 ) , V_2 -> V_8 + V_72 ) ;
}
static void F_42 ( struct V_1 * V_2 ,
int V_68 , enum V_73 V_74 ,
bool V_75 )
{
T_1 V_76 = V_74 == V_77 ? V_33 : V_78 ;
T_1 V_79 = V_74 == V_77 ? V_35 : V_80 ;
T_1 V_81 = F_38 ( V_68 ) ;
T_1 V_82 ;
if ( V_2 -> V_83 & V_81 ) {
V_82 = F_2 ( V_2 -> V_8 + V_76 ) ;
if ( V_75 )
V_82 |= V_81 ;
else
V_82 &= ~ V_81 ;
F_3 ( V_82 , V_2 -> V_8 + V_76 ) ;
}
if ( V_2 -> V_84 & V_81 ) {
V_82 = F_2 ( V_2 -> V_8 + V_79 ) ;
if ( V_75 )
V_82 |= V_81 ;
else
V_82 &= ~ V_81 ;
F_3 ( V_82 , V_2 -> V_8 + V_79 ) ;
}
}
static void F_43 ( struct V_1 * V_2 ,
int V_68 , bool V_85 )
{
if ( V_2 -> V_86 ) {
F_4 ( V_2 , V_68 - V_2 -> V_49 . V_67 ,
V_85 ? V_87
: V_88 ) ;
}
F_42 ( V_2 , V_68 , V_77 , V_85 ) ;
}
static int F_44 ( struct V_69 * V_70 , bool V_75 )
{
int V_68 ;
struct V_1 * V_2 ;
unsigned long V_61 ;
T_1 V_81 ;
V_68 = F_40 ( V_70 -> V_71 ) ;
V_2 = F_41 ( V_70 ) ;
V_81 = F_38 ( V_68 ) ;
if ( ! V_2 )
return - V_65 ;
if ( V_75 )
V_2 -> V_89 |= V_81 ;
else
V_2 -> V_89 &= ~ V_81 ;
F_25 ( & V_63 , V_61 ) ;
F_28 ( & V_2 -> V_66 ) ;
F_42 ( V_2 , V_68 , V_90 , V_75 ) ;
if ( ! ( V_2 -> V_91 & V_81 ) )
F_43 ( V_2 , V_68 , V_75 ) ;
F_29 ( & V_2 -> V_66 ) ;
F_30 ( & V_63 , V_61 ) ;
return 0 ;
}
static void F_45 ( struct V_69 * V_70 )
{
F_44 ( V_70 , false ) ;
}
static void F_46 ( struct V_69 * V_70 )
{
F_44 ( V_70 , true ) ;
}
static int F_47 ( struct V_69 * V_70 , unsigned int V_85 )
{
struct V_1 * V_2 ;
unsigned long V_61 ;
T_1 V_81 ;
int V_68 ;
V_68 = F_40 ( V_70 -> V_71 ) ;
V_2 = F_41 ( V_70 ) ;
if ( ! V_2 )
return - V_65 ;
V_81 = F_38 ( V_68 ) ;
F_25 ( & V_63 , V_61 ) ;
F_28 ( & V_2 -> V_66 ) ;
if ( ! ( V_2 -> V_89 & V_81 ) )
F_43 ( V_2 , V_68 , V_85 ) ;
if ( V_85 )
V_2 -> V_91 |= V_81 ;
else
V_2 -> V_91 &= ~ V_81 ;
F_29 ( & V_2 -> V_66 ) ;
F_30 ( & V_63 , V_61 ) ;
return 0 ;
}
static int F_48 ( struct V_69 * V_70 , unsigned int type )
{
bool V_89 , V_92 = F_49 ( V_70 ) ;
int V_68 ;
struct V_1 * V_2 ;
unsigned long V_61 ;
T_1 V_81 ;
V_68 = F_40 ( V_70 -> V_71 ) ;
V_2 = F_41 ( V_70 ) ;
V_81 = F_38 ( V_68 ) ;
if ( ! V_2 )
return - V_65 ;
if ( type & V_93 )
return - V_65 ;
if ( type & V_94 )
return - V_65 ;
V_89 = V_2 -> V_89 & V_81 ;
F_25 ( & V_2 -> V_66 , V_61 ) ;
if ( V_89 )
F_42 ( V_2 , V_68 , V_90 , false ) ;
if ( V_89 || V_92 )
F_42 ( V_2 , V_68 , V_77 , false ) ;
V_2 -> V_83 &= ~ V_81 ;
if ( type & V_95 )
V_2 -> V_83 |= V_81 ;
V_2 -> V_84 &= ~ V_81 ;
if ( type & V_96 )
V_2 -> V_84 |= V_81 ;
if ( V_89 )
F_42 ( V_2 , V_68 , V_90 , true ) ;
if ( V_89 || V_92 )
F_42 ( V_2 , V_68 , V_77 , true ) ;
F_30 ( & V_2 -> V_66 , V_61 ) ;
return 0 ;
}
static void F_50 ( unsigned int V_71 , struct V_97 * V_98 ,
T_1 V_99 )
{
struct V_1 * V_2 ;
struct V_100 * V_101 = F_51 ( V_71 ) ;
unsigned int V_102 ;
F_52 ( V_101 , V_98 ) ;
V_2 = F_53 ( V_71 ) ;
V_102 = F_27 ( V_2 -> V_49 . V_67 ) ;
while ( V_99 ) {
int V_5 = F_54 ( V_99 ) ;
F_55 ( V_102 + V_5 ) ;
V_99 &= ~ F_10 ( V_5 ) ;
}
F_56 ( V_101 , V_98 ) ;
}
static void F_57 ( unsigned int V_71 , struct V_97 * V_98 )
{
struct V_1 * V_2 = F_53 ( V_71 ) ;
T_1 V_99 = F_2 ( V_2 -> V_8 + V_103 ) ;
F_50 ( V_71 , V_98 , V_99 ) ;
}
static void F_58 ( unsigned int V_71 ,
struct V_97 * V_98 )
{
struct V_1 * V_2 = F_53 ( V_71 ) ;
T_1 V_99 = V_2 -> V_104 ( V_2 -> V_54 ) ;
F_50 ( V_71 , V_98 , V_99 ) ;
}
static int F_59 ( struct V_1 * V_2 )
{
unsigned int V_102 ;
int V_55 ;
V_102 = F_27 ( V_2 -> V_49 . V_67 ) ;
for ( V_55 = V_102 ; V_55 < V_102 + V_2 -> V_49 . V_105 ; V_55 ++ ) {
F_60 ( V_55 , & V_106 ,
V_107 ) ;
F_61 ( V_55 , V_108 ) ;
F_62 ( V_55 , V_2 ) ;
F_63 ( V_55 , V_96 ) ;
}
F_64 ( V_2 -> V_109 , F_57 ) ;
F_65 ( V_2 -> V_109 , V_2 ) ;
if ( V_2 -> V_110 >= 0 ) {
F_64 ( V_2 -> V_110 ,
F_58 ) ;
F_65 ( V_2 -> V_110 , V_2 ) ;
}
return 0 ;
}
static int F_66 ( struct V_111 * V_49 , unsigned V_3 )
{
struct V_1 * V_2 =
F_67 ( V_49 , struct V_1 , V_49 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_28 ) ;
return 0 ;
}
static int F_68 ( struct V_111 * V_49 , unsigned V_3 )
{
struct V_1 * V_2 =
F_67 ( V_49 , struct V_1 , V_49 ) ;
T_1 V_5 = 1 << V_3 ;
return ( F_2 ( V_2 -> V_8 + V_112 ) & V_5 ) != 0 ;
}
static void F_69 ( struct V_111 * V_49 , unsigned V_3 ,
int V_29 )
{
struct V_1 * V_2 =
F_67 ( V_49 , struct V_1 , V_49 ) ;
F_7 ( V_2 , V_3 , V_29 ) ;
}
static int F_70 ( struct V_111 * V_49 , unsigned V_3 ,
int V_29 )
{
struct V_1 * V_2 =
F_67 ( V_49 , struct V_1 , V_49 ) ;
F_8 ( V_2 , V_3 , V_29 ) ;
return 0 ;
}
static int F_71 ( struct V_111 * V_49 , unsigned V_3 )
{
struct V_1 * V_2 =
F_67 ( V_49 , struct V_1 , V_49 ) ;
return F_27 ( V_2 -> V_49 . V_67 ) + V_3 ;
}
static void F_72 ( struct V_113 * V_114 , struct V_111 * V_49 )
{
int V_14 ;
unsigned V_55 ;
unsigned V_68 = V_49 -> V_67 ;
int V_115 ;
struct V_1 * V_2 =
F_67 ( V_49 , struct V_1 , V_49 ) ;
const char * V_116 [] = {
[ V_41 ] = L_20 ,
[ V_11 ] = L_21 ,
[ V_12 ] = L_22 ,
[ V_42 ] = L_23 ,
} ;
for ( V_55 = 0 ; V_55 < V_49 -> V_105 ; V_55 ++ , V_68 ++ ) {
const char * V_117 = F_73 ( V_49 , V_55 ) ;
bool V_19 ;
T_1 V_5 = 1 << V_55 ;
V_115 = F_2 ( V_2 -> V_8 + V_118 ) & V_5 ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_37 ( V_68 ) ;
F_74 ( V_114 , L_24 ,
V_68 , V_117 ? : L_25 ,
V_115 ? L_26 : L_27 ,
V_49 -> V_119
? ( V_49 -> V_119 ( V_49 , V_55 ) ? L_28 : L_29 )
: L_30 ,
( V_14 < 0 ) ? L_31 : V_116 [ V_14 ] ,
V_19 ? L_32 : L_5 ) ;
if ( V_117 && ! V_115 ) {
int V_71 = F_75 ( V_68 ) ;
struct V_97 * V_98 = F_76 ( V_71 ) ;
if ( V_71 >= 0 && V_98 -> V_120 ) {
char * V_121 ;
T_1 V_81 = F_38 ( V_68 ) ;
if ( V_2 -> V_83 & V_81 )
V_121 = L_33 ;
else if ( V_2 -> V_84 & V_81 )
V_121 = L_34 ;
else
V_121 = L_35 ;
F_74 ( V_114 , L_36 ,
V_71 , V_121 ,
F_49 ( & V_98 -> V_69 )
? L_37 : L_16 ) ;
}
}
F_74 ( V_114 , L_38 ) ;
}
}
void F_77 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
break;
V_49 -> V_32 = F_2 ( V_49 -> V_8 + V_33 ) ;
V_49 -> V_34 = F_2 ( V_49 -> V_8 + V_35 ) ;
F_3 ( V_49 -> V_32 & V_49 -> V_91 ,
V_49 -> V_8 + V_33 ) ;
F_3 ( V_49 -> V_34 & V_49 -> V_91 ,
V_49 -> V_8 + V_35 ) ;
if ( V_49 -> V_86 ) {
V_49 -> V_15 = F_2 ( V_49 -> V_8 + V_16 ) ;
F_3 ( ~ V_49 -> V_91 , V_49 -> V_8 + V_16 ) ;
}
}
}
void F_78 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
break;
F_3 ( V_49 -> V_32 , V_49 -> V_8 + V_33 ) ;
F_3 ( V_49 -> V_34 , V_49 -> V_8 + V_35 ) ;
if ( V_49 -> V_86 )
F_3 ( V_49 -> V_15 , V_49 -> V_8 + V_16 ) ;
}
}
void F_79 ( int V_122 , T_1 * V_23 )
{
if ( V_122 < V_56 ) {
struct V_1 * V_49 = V_57 [ V_122 ] ;
if ( ! V_49 )
return;
* V_23 = V_49 -> V_23 ;
}
}
static int T_3 F_80 ( struct V_123 * V_50 )
{
struct V_124 * V_125 = V_50 -> V_50 . V_126 ;
struct V_1 * V_2 ;
struct V_111 * V_49 ;
struct V_127 * V_128 ;
struct V_129 * V_129 ;
int V_130 ;
int V_71 ;
int V_62 ;
if ( ! V_125 )
return - V_131 ;
V_128 = F_81 ( V_50 , V_132 , 0 ) ;
if ( ! V_128 ) {
V_62 = - V_133 ;
goto V_134;
}
V_71 = F_82 ( V_50 , 0 ) ;
if ( V_71 < 0 ) {
V_62 = V_71 ;
goto V_134;
}
V_130 = F_82 ( V_50 , 1 ) ;
if ( V_130 >= 0 && ! V_125 -> V_104 ) {
V_62 = - V_65 ;
goto V_134;
}
if ( F_83 ( V_128 -> V_135 , F_84 ( V_128 ) ,
F_85 ( & V_50 -> V_50 ) ) == NULL ) {
V_62 = - V_136 ;
goto V_134;
}
V_129 = F_86 ( & V_50 -> V_50 , NULL ) ;
if ( F_87 ( V_129 ) ) {
V_62 = F_88 ( V_129 ) ;
goto V_137;
}
F_89 ( V_129 ) ;
V_2 = F_90 ( sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 ) {
V_62 = - V_139 ;
goto V_140;
}
V_2 -> V_54 = V_50 -> V_141 ;
V_2 -> V_129 = V_129 ;
V_2 -> V_8 = F_91 ( V_128 -> V_135 ) ;
V_2 -> V_49 = V_142 ;
V_2 -> V_109 = V_71 ;
V_2 -> V_110 = V_130 ;
V_2 -> V_104 = V_125 -> V_104 ;
V_2 -> V_36 = V_125 -> V_36 ;
V_2 -> V_86 = V_125 -> V_143 ;
F_92 ( & V_2 -> V_66 ) ;
V_49 = & V_2 -> V_49 ;
V_49 -> V_67 = V_125 -> V_144 ;
V_49 -> V_105 = V_125 -> V_145 ;
V_49 -> V_117 = V_125 -> V_146 ? : F_85 ( & V_50 -> V_50 ) ;
V_49 -> V_50 = & V_50 -> V_50 ;
V_49 -> V_147 = V_148 ;
V_62 = F_93 ( & V_2 -> V_49 ) ;
if ( V_62 )
goto V_149;
F_94 ( V_2 -> V_54 >= F_95 ( V_57 ) ) ;
V_57 [ V_2 -> V_54 ] = V_2 ;
F_96 ( V_50 , V_2 ) ;
F_59 ( V_2 ) ;
F_97 ( & V_50 -> V_50 , L_39 ,
V_2 -> V_49 . V_67 , V_2 -> V_49 . V_67 + 31 , V_2 -> V_8 ) ;
return 0 ;
V_149:
F_98 ( V_2 ) ;
V_140:
F_99 ( V_129 ) ;
F_100 ( V_129 ) ;
V_137:
F_101 ( V_128 -> V_135 , F_84 ( V_128 ) ) ;
V_134:
F_102 ( & V_50 -> V_50 , L_40 , V_62 ,
V_125 -> V_144 , V_125 -> V_144 + 31 ) ;
return V_62 ;
}
static int T_4 F_103 ( void )
{
return F_104 ( & V_150 ) ;
}
