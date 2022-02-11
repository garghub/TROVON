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
F_23 ( V_49 -> V_59 ) ;
V_15 [ V_55 ] = F_2 ( V_49 -> V_8 + V_16 ) ;
F_3 ( V_58 , V_49 -> V_8 + V_16 ) ;
}
}
static void F_24 ( unsigned int * V_15 )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
break;
F_3 ( V_15 [ V_55 ] , V_49 -> V_8 + V_16 ) ;
F_25 ( V_49 -> V_59 ) ;
}
}
static int F_26 ( T_2 * V_60 , int V_61 , bool V_38 )
{
static unsigned int V_15 [ V_56 ] ;
unsigned long V_62 ;
bool V_31 = false ;
int V_63 = 0 ;
int V_55 ;
for ( V_55 = 0 ; V_55 < V_61 ; V_55 ++ ) {
if ( F_14 ( V_60 [ V_55 ] ) == V_42 ) {
V_31 = true ;
break;
}
}
F_27 ( & V_64 , V_62 ) ;
if ( V_31 ) {
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_55 = 0 ; V_55 < V_61 ; V_55 ++ ) {
int V_46 = F_12 ( V_60 [ V_55 ] ) ;
int V_3 = V_46 % V_65 ;
if ( F_14 ( V_60 [ V_55 ] ) == V_42 )
V_15 [ V_46 / V_65 ] &= ~ F_10 ( V_3 ) ;
}
F_22 ( V_15 ) ;
}
for ( V_55 = 0 ; V_55 < V_61 ; V_55 ++ ) {
struct V_1 * V_2 ;
int V_46 = F_12 ( V_60 [ V_55 ] ) ;
V_2 = F_28 ( F_29 ( V_46 ) ) ;
if ( ! V_2 ) {
V_63 = - V_66 ;
break;
}
F_23 ( V_2 -> V_59 ) ;
F_30 ( & V_2 -> V_67 ) ;
F_11 ( V_2 , V_46 - V_2 -> V_49 . V_68 ,
V_60 [ V_55 ] , V_38 , V_31 ? V_15 : NULL ) ;
F_31 ( & V_2 -> V_67 ) ;
F_25 ( V_2 -> V_59 ) ;
}
if ( V_31 )
F_24 ( V_15 ) ;
F_32 ( & V_64 , V_62 ) ;
return V_63 ;
}
int F_33 ( T_2 V_37 , bool V_38 )
{
return F_26 ( & V_37 , 1 , V_38 ) ;
}
int F_34 ( T_2 * V_60 , int V_61 )
{
return F_26 ( V_60 , V_61 , false ) ;
}
int F_35 ( T_2 * V_60 , int V_61 )
{
return F_26 ( V_60 , V_61 , true ) ;
}
int F_36 ( int V_69 , enum V_13 V_14 )
{
struct V_1 * V_2 ;
unsigned long V_62 ;
V_2 = F_28 ( F_29 ( V_69 ) ) ;
if ( ! V_2 )
return - V_66 ;
F_23 ( V_2 -> V_59 ) ;
F_27 ( & V_64 , V_62 ) ;
F_30 ( & V_2 -> V_67 ) ;
F_4 ( V_2 , V_69 - V_2 -> V_49 . V_68 , V_14 ) ;
F_31 ( & V_2 -> V_67 ) ;
F_32 ( & V_64 , V_62 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
int F_37 ( int V_69 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
unsigned long V_62 ;
V_2 = F_28 ( F_29 ( V_69 ) ) ;
if ( ! V_2 )
return - V_66 ;
F_23 ( V_2 -> V_59 ) ;
F_27 ( & V_2 -> V_67 , V_62 ) ;
F_5 ( V_2 , V_69 - V_2 -> V_49 . V_68 , V_19 ) ;
F_32 ( & V_2 -> V_67 , V_62 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
int F_38 ( int V_69 , int V_4 )
{
struct V_1 * V_2 ;
unsigned long V_62 ;
V_2 = F_28 ( F_29 ( V_69 ) ) ;
if ( ! V_2 )
return - V_66 ;
F_23 ( V_2 -> V_59 ) ;
F_27 ( & V_2 -> V_67 , V_62 ) ;
F_1 ( V_2 , V_69 - V_2 -> V_49 . V_68 , V_4 ) ;
F_32 ( & V_2 -> V_67 , V_62 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
int F_39 ( int V_69 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = F_28 ( F_29 ( V_69 ) ) ;
if ( ! V_2 )
return - V_66 ;
V_5 = 1 << ( V_69 - V_2 -> V_49 . V_68 ) ;
F_23 ( V_2 -> V_59 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
F_25 ( V_2 -> V_59 ) ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_40 ( int V_69 )
{
return 1 << ( V_69 % 32 ) ;
}
static void F_41 ( struct V_70 * V_71 )
{
int V_69 ;
struct V_1 * V_2 ;
V_69 = F_42 ( V_71 -> V_72 ) ;
V_2 = F_43 ( V_71 ) ;
if ( ! V_2 )
return;
F_23 ( V_2 -> V_59 ) ;
F_3 ( F_40 ( V_69 ) , V_2 -> V_8 + V_73 ) ;
F_25 ( V_2 -> V_59 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
int V_69 , enum V_74 V_75 ,
bool V_76 )
{
T_1 V_77 = V_75 == V_78 ? V_33 : V_79 ;
T_1 V_80 = V_75 == V_78 ? V_35 : V_81 ;
T_1 V_82 = F_40 ( V_69 ) ;
T_1 V_83 ;
if ( V_2 -> V_84 & V_82 ) {
V_83 = F_2 ( V_2 -> V_8 + V_77 ) ;
if ( V_76 )
V_83 |= V_82 ;
else
V_83 &= ~ V_82 ;
F_3 ( V_83 , V_2 -> V_8 + V_77 ) ;
}
if ( V_2 -> V_85 & V_82 ) {
V_83 = F_2 ( V_2 -> V_8 + V_80 ) ;
if ( V_76 )
V_83 |= V_82 ;
else
V_83 &= ~ V_82 ;
F_3 ( V_83 , V_2 -> V_8 + V_80 ) ;
}
}
static void F_45 ( struct V_1 * V_2 ,
int V_69 , bool V_86 )
{
if ( V_2 -> V_87 ) {
F_4 ( V_2 , V_69 - V_2 -> V_49 . V_68 ,
V_86 ? V_88
: V_89 ) ;
}
F_44 ( V_2 , V_69 , V_78 , V_86 ) ;
}
static int F_46 ( struct V_70 * V_71 , bool V_76 )
{
int V_69 ;
struct V_1 * V_2 ;
unsigned long V_62 ;
T_1 V_82 ;
V_69 = F_42 ( V_71 -> V_72 ) ;
V_2 = F_43 ( V_71 ) ;
V_82 = F_40 ( V_69 ) ;
if ( ! V_2 )
return - V_66 ;
F_23 ( V_2 -> V_59 ) ;
F_27 ( & V_64 , V_62 ) ;
F_30 ( & V_2 -> V_67 ) ;
F_44 ( V_2 , V_69 , V_90 , V_76 ) ;
if ( ! ( V_2 -> V_91 & V_82 ) )
F_45 ( V_2 , V_69 , V_76 ) ;
F_31 ( & V_2 -> V_67 ) ;
F_32 ( & V_64 , V_62 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
static void F_47 ( struct V_70 * V_71 )
{
F_46 ( V_71 , false ) ;
}
static void F_48 ( struct V_70 * V_71 )
{
F_46 ( V_71 , true ) ;
}
static int F_49 ( struct V_70 * V_71 , unsigned int V_86 )
{
struct V_1 * V_2 ;
unsigned long V_62 ;
T_1 V_82 ;
int V_69 ;
V_69 = F_42 ( V_71 -> V_72 ) ;
V_2 = F_43 ( V_71 ) ;
if ( ! V_2 )
return - V_66 ;
V_82 = F_40 ( V_69 ) ;
F_23 ( V_2 -> V_59 ) ;
F_27 ( & V_64 , V_62 ) ;
F_30 ( & V_2 -> V_67 ) ;
if ( F_50 ( V_71 ) )
F_45 ( V_2 , V_69 , V_86 ) ;
if ( V_86 )
V_2 -> V_91 |= V_82 ;
else
V_2 -> V_91 &= ~ V_82 ;
F_31 ( & V_2 -> V_67 ) ;
F_32 ( & V_64 , V_62 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
static int F_51 ( struct V_70 * V_71 , unsigned int type )
{
bool V_92 = ! F_50 ( V_71 ) ;
bool V_93 = F_52 ( V_71 ) ;
int V_69 ;
struct V_1 * V_2 ;
unsigned long V_62 ;
T_1 V_82 ;
V_69 = F_42 ( V_71 -> V_72 ) ;
V_2 = F_43 ( V_71 ) ;
V_82 = F_40 ( V_69 ) ;
if ( ! V_2 )
return - V_66 ;
if ( type & V_94 )
return - V_66 ;
if ( type & V_95 )
return - V_66 ;
F_23 ( V_2 -> V_59 ) ;
F_27 ( & V_2 -> V_67 , V_62 ) ;
if ( V_92 )
F_44 ( V_2 , V_69 , V_90 , false ) ;
if ( V_92 || V_93 )
F_44 ( V_2 , V_69 , V_78 , false ) ;
V_2 -> V_84 &= ~ V_82 ;
if ( type & V_96 )
V_2 -> V_84 |= V_82 ;
V_2 -> V_85 &= ~ V_82 ;
if ( type & V_97 )
V_2 -> V_85 |= V_82 ;
if ( V_92 )
F_44 ( V_2 , V_69 , V_90 , true ) ;
if ( V_92 || V_93 )
F_44 ( V_2 , V_69 , V_78 , true ) ;
F_32 ( & V_2 -> V_67 , V_62 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
static unsigned int F_53 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_43 ( V_71 ) ;
F_23 ( V_2 -> V_59 ) ;
F_48 ( V_71 ) ;
return 0 ;
}
static void F_54 ( struct V_70 * V_71 )
{
struct V_1 * V_2 = F_43 ( V_71 ) ;
F_47 ( V_71 ) ;
F_25 ( V_2 -> V_59 ) ;
}
static void F_55 ( unsigned int V_72 , struct V_98 * V_99 ,
T_1 V_100 )
{
struct V_1 * V_2 ;
struct V_101 * V_102 = F_56 ( V_72 ) ;
unsigned int V_103 ;
F_57 ( V_102 , V_99 ) ;
V_2 = F_58 ( V_72 ) ;
V_103 = F_29 ( V_2 -> V_49 . V_68 ) ;
while ( V_100 ) {
int V_5 = F_59 ( V_100 ) ;
F_60 ( V_103 + V_5 ) ;
V_100 &= ~ F_10 ( V_5 ) ;
}
F_61 ( V_102 , V_99 ) ;
}
static void F_62 ( unsigned int V_72 , struct V_98 * V_99 )
{
struct V_1 * V_2 = F_58 ( V_72 ) ;
T_1 V_100 ;
F_23 ( V_2 -> V_59 ) ;
V_100 = F_2 ( V_2 -> V_8 + V_104 ) ;
F_25 ( V_2 -> V_59 ) ;
F_55 ( V_72 , V_99 , V_100 ) ;
}
static void F_63 ( unsigned int V_72 ,
struct V_98 * V_99 )
{
struct V_1 * V_2 = F_58 ( V_72 ) ;
T_1 V_100 = V_2 -> V_105 ( V_2 -> V_54 ) ;
F_55 ( V_72 , V_99 , V_100 ) ;
}
static int F_64 ( struct V_1 * V_2 )
{
unsigned int V_103 ;
int V_55 ;
V_103 = F_29 ( V_2 -> V_49 . V_68 ) ;
for ( V_55 = V_103 ; V_55 < V_103 + V_2 -> V_49 . V_106 ; V_55 ++ ) {
F_65 ( V_55 , & V_107 ,
V_108 ) ;
F_66 ( V_55 , V_109 ) ;
F_67 ( V_55 , V_2 ) ;
F_68 ( V_55 , V_97 ) ;
}
F_69 ( V_2 -> V_110 , F_62 ) ;
F_70 ( V_2 -> V_110 , V_2 ) ;
if ( V_2 -> V_111 >= 0 ) {
F_69 ( V_2 -> V_111 ,
F_63 ) ;
F_70 ( V_2 -> V_111 , V_2 ) ;
}
return 0 ;
}
static int F_71 ( struct V_112 * V_49 , unsigned V_3 )
{
struct V_1 * V_2 =
F_72 ( V_49 , struct V_1 , V_49 ) ;
F_23 ( V_2 -> V_59 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_28 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
static int F_73 ( struct V_112 * V_49 , unsigned V_3 )
{
struct V_1 * V_2 =
F_72 ( V_49 , struct V_1 , V_49 ) ;
T_1 V_5 = 1 << V_3 ;
int V_113 ;
F_23 ( V_2 -> V_59 ) ;
V_113 = ( F_2 ( V_2 -> V_8 + V_114 ) & V_5 ) != 0 ;
F_25 ( V_2 -> V_59 ) ;
return V_113 ;
}
static void F_74 ( struct V_112 * V_49 , unsigned V_3 ,
int V_29 )
{
struct V_1 * V_2 =
F_72 ( V_49 , struct V_1 , V_49 ) ;
F_23 ( V_2 -> V_59 ) ;
F_7 ( V_2 , V_3 , V_29 ) ;
F_25 ( V_2 -> V_59 ) ;
}
static int F_75 ( struct V_112 * V_49 , unsigned V_3 ,
int V_29 )
{
struct V_1 * V_2 =
F_72 ( V_49 , struct V_1 , V_49 ) ;
F_23 ( V_2 -> V_59 ) ;
F_8 ( V_2 , V_3 , V_29 ) ;
F_25 ( V_2 -> V_59 ) ;
return 0 ;
}
static int F_76 ( struct V_112 * V_49 , unsigned V_3 )
{
struct V_1 * V_2 =
F_72 ( V_49 , struct V_1 , V_49 ) ;
return F_29 ( V_2 -> V_49 . V_68 ) + V_3 ;
}
static void F_77 ( struct V_115 * V_116 , struct V_112 * V_49 )
{
int V_14 ;
unsigned V_55 ;
unsigned V_69 = V_49 -> V_68 ;
int V_117 ;
struct V_1 * V_2 =
F_72 ( V_49 , struct V_1 , V_49 ) ;
const char * V_118 [] = {
[ V_41 ] = L_20 ,
[ V_11 ] = L_21 ,
[ V_12 ] = L_22 ,
[ V_42 ] = L_23 ,
} ;
F_23 ( V_2 -> V_59 ) ;
for ( V_55 = 0 ; V_55 < V_49 -> V_106 ; V_55 ++ , V_69 ++ ) {
const char * V_119 = F_78 ( V_49 , V_55 ) ;
bool V_19 ;
T_1 V_5 = 1 << V_55 ;
V_117 = F_2 ( V_2 -> V_8 + V_120 ) & V_5 ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_39 ( V_69 ) ;
F_79 ( V_116 , L_24 ,
V_69 , V_119 ? : L_25 ,
V_117 ? L_26 : L_27 ,
V_49 -> V_121
? ( V_49 -> V_121 ( V_49 , V_55 ) ? L_28 : L_29 )
: L_30 ,
( V_14 < 0 ) ? L_31 : V_118 [ V_14 ] ,
V_19 ? L_32 : L_5 ) ;
if ( V_119 && ! V_117 ) {
int V_72 = F_80 ( V_69 ) ;
struct V_98 * V_99 = F_81 ( V_72 ) ;
if ( V_72 >= 0 && V_99 -> V_122 ) {
char * V_123 ;
T_1 V_82 = F_40 ( V_69 ) ;
if ( V_2 -> V_84 & V_82 )
V_123 = L_33 ;
else if ( V_2 -> V_85 & V_82 )
V_123 = L_34 ;
else
V_123 = L_35 ;
F_79 ( V_116 , L_36 ,
V_72 , V_123 ,
F_52 ( & V_99 -> V_70 )
? L_37 : L_16 ) ;
}
}
F_79 ( V_116 , L_38 ) ;
}
F_25 ( V_2 -> V_59 ) ;
}
void F_82 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
continue;
F_23 ( V_49 -> V_59 ) ;
}
}
void F_83 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
continue;
F_25 ( V_49 -> V_59 ) ;
}
}
void F_84 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
break;
F_23 ( V_49 -> V_59 ) ;
V_49 -> V_32 = F_2 ( V_49 -> V_8 + V_33 ) ;
V_49 -> V_34 = F_2 ( V_49 -> V_8 + V_35 ) ;
F_3 ( V_49 -> V_32 & V_49 -> V_91 ,
V_49 -> V_8 + V_33 ) ;
F_3 ( V_49 -> V_34 & V_49 -> V_91 ,
V_49 -> V_8 + V_35 ) ;
if ( V_49 -> V_87 ) {
V_49 -> V_15 = F_2 ( V_49 -> V_8 + V_16 ) ;
F_3 ( ~ V_49 -> V_91 , V_49 -> V_8 + V_16 ) ;
}
F_25 ( V_49 -> V_59 ) ;
}
}
void F_85 ( void )
{
int V_55 ;
for ( V_55 = 0 ; V_55 < V_56 ; V_55 ++ ) {
struct V_1 * V_49 = V_57 [ V_55 ] ;
if ( ! V_49 )
break;
F_23 ( V_49 -> V_59 ) ;
F_3 ( V_49 -> V_32 , V_49 -> V_8 + V_33 ) ;
F_3 ( V_49 -> V_34 , V_49 -> V_8 + V_35 ) ;
if ( V_49 -> V_87 )
F_3 ( V_49 -> V_15 , V_49 -> V_8 + V_16 ) ;
F_25 ( V_49 -> V_59 ) ;
}
}
void F_86 ( int V_124 , T_1 * V_23 )
{
if ( V_124 < V_56 ) {
struct V_1 * V_49 = V_57 [ V_124 ] ;
if ( ! V_49 )
return;
* V_23 = V_49 -> V_23 ;
}
}
static int T_3 F_87 ( struct V_125 * V_50 )
{
struct V_126 * V_127 = V_50 -> V_50 . V_128 ;
struct V_1 * V_2 ;
struct V_112 * V_49 ;
struct V_129 * V_130 ;
struct V_59 * V_59 ;
int V_131 ;
int V_72 ;
int V_63 ;
if ( ! V_127 )
return - V_132 ;
V_130 = F_88 ( V_50 , V_133 , 0 ) ;
if ( ! V_130 ) {
V_63 = - V_134 ;
goto V_135;
}
V_72 = F_89 ( V_50 , 0 ) ;
if ( V_72 < 0 ) {
V_63 = V_72 ;
goto V_135;
}
V_131 = F_89 ( V_50 , 1 ) ;
if ( V_131 >= 0 && ! V_127 -> V_105 ) {
V_63 = - V_66 ;
goto V_135;
}
if ( F_90 ( V_130 -> V_136 , F_91 ( V_130 ) ,
F_92 ( & V_50 -> V_50 ) ) == NULL ) {
V_63 = - V_137 ;
goto V_135;
}
V_59 = F_93 ( & V_50 -> V_50 , NULL ) ;
if ( F_94 ( V_59 ) ) {
V_63 = F_95 ( V_59 ) ;
goto V_138;
}
V_2 = F_96 ( sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 ) {
V_63 = - V_140 ;
goto V_141;
}
V_2 -> V_54 = V_50 -> V_142 ;
V_2 -> V_59 = V_59 ;
V_2 -> V_8 = F_97 ( V_130 -> V_136 ) ;
V_2 -> V_49 = V_143 ;
V_2 -> V_110 = V_72 ;
V_2 -> V_111 = V_131 ;
V_2 -> V_105 = V_127 -> V_105 ;
V_2 -> V_36 = V_127 -> V_36 ;
V_2 -> V_87 = V_127 -> V_144 ;
F_98 ( & V_2 -> V_67 ) ;
V_49 = & V_2 -> V_49 ;
V_49 -> V_68 = V_127 -> V_145 ;
V_49 -> V_106 = V_127 -> V_146 ;
V_49 -> V_119 = V_127 -> V_147 ? : F_92 ( & V_50 -> V_50 ) ;
V_49 -> V_50 = & V_50 -> V_50 ;
V_49 -> V_148 = V_149 ;
V_63 = F_99 ( & V_2 -> V_49 ) ;
if ( V_63 )
goto V_150;
F_100 ( V_2 -> V_54 >= F_101 ( V_57 ) ) ;
V_57 [ V_2 -> V_54 ] = V_2 ;
F_102 ( V_50 , V_2 ) ;
F_64 ( V_2 ) ;
F_103 ( & V_50 -> V_50 , L_39 ,
V_2 -> V_8 ) ;
return 0 ;
V_150:
F_104 ( V_2 ) ;
V_141:
F_25 ( V_59 ) ;
F_105 ( V_59 ) ;
V_138:
F_106 ( V_130 -> V_136 , F_91 ( V_130 ) ) ;
V_135:
F_107 ( & V_50 -> V_50 , L_40 , V_63 ,
V_127 -> V_145 , V_127 -> V_145 + 31 ) ;
return V_63 ;
}
static int T_4 F_108 ( void )
{
return F_109 ( & V_151 ) ;
}
