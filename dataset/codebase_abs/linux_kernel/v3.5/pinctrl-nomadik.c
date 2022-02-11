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
unsigned V_3 , bool V_28 )
{
T_1 V_5 = F_7 ( V_3 ) ;
bool V_29 = V_2 -> V_28 & V_5 ;
if ( V_28 == V_29 )
return;
if ( V_28 )
V_2 -> V_28 |= V_5 ;
else
V_2 -> V_28 &= ~ V_5 ;
F_8 ( V_2 -> V_28 ,
V_2 -> V_8 + V_30 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned V_3 )
{
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
if ( V_32 )
F_3 ( 1 << V_3 , V_2 -> V_8 + V_25 ) ;
else
F_3 ( 1 << V_3 , V_2 -> V_8 + V_27 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_32 )
{
F_3 ( 1 << V_3 , V_2 -> V_8 + V_33 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned V_3 , int V_4 ,
bool V_34 )
{
T_1 V_35 = V_2 -> V_35 ;
T_1 V_36 = V_2 -> V_36 ;
if ( V_34 && V_2 -> V_37 ) {
T_1 V_5 = F_7 ( V_3 ) ;
F_3 ( V_35 & ~ V_5 , V_2 -> V_8 + V_38 ) ;
F_3 ( V_36 & ~ V_5 , V_2 -> V_8 + V_39 ) ;
V_2 -> V_37 ( true ) ;
}
F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_34 && V_2 -> V_37 ) {
V_2 -> V_37 ( false ) ;
F_3 ( V_35 , V_2 -> V_8 + V_38 ) ;
F_3 ( V_36 , V_2 -> V_8 + V_39 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_40 = V_2 -> V_41 & F_7 ( V_3 ) ;
T_1 V_42 = V_2 -> V_43 & F_7 ( V_3 ) ;
int V_44 = V_2 -> V_45 . V_46 + V_3 ;
int V_47 = F_14 ( V_44 ) ;
struct V_48 * V_49 = F_15 ( V_47 ) ;
if ( ! V_42 && ! V_40 )
return;
if ( ! V_49 || ! F_16 ( V_49 ) )
return;
if ( V_42 ) {
V_2 -> V_43 &= ~ F_7 ( V_3 ) ;
F_8 ( V_2 -> V_43 ,
V_2 -> V_8 + V_50 ) ;
}
if ( V_40 ) {
V_2 -> V_41 &= ~ F_7 ( V_3 ) ;
F_8 ( V_2 -> V_41 ,
V_2 -> V_8 + V_51 ) ;
}
F_17 ( V_2 -> V_45 . V_52 , L_1 , V_44 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned V_3 ,
T_2 V_53 , bool V_54 , unsigned int * V_55 )
{
static const char * V_56 [] = {
[ V_57 ] = L_2 ,
[ V_11 ] = L_3 ,
[ V_12 ] = L_4 ,
[ V_58 ] = L_5
} ;
static const char * V_59 [] = {
[ V_22 ] = L_6 ,
[ V_24 ] = L_7 ,
[ V_26 ] = L_8 ,
[ 3 ] = L_9
} ;
static const char * V_60 [] = {
[ V_61 ] = L_10 ,
[ V_17 ] = L_11 ,
} ;
int V_62 = F_19 ( V_53 ) ;
int V_19 = F_20 ( V_53 ) ;
int V_63 = F_21 ( V_53 ) ;
int V_15 = F_22 ( V_53 ) ;
int V_64 = F_23 ( V_53 ) ;
int V_32 = F_24 ( V_53 ) ;
bool V_34 = V_63 == V_58 ;
F_17 ( V_2 -> V_45 . V_52 , L_12 ,
V_62 , V_53 , V_56 [ V_63 ] , V_59 [ V_19 ] , V_60 [ V_15 ] ,
V_64 ? L_13 : L_14 ,
V_64 ? ( V_32 ? L_15 : L_16 ) : L_17 ) ;
if ( V_54 ) {
int V_65 = F_25 ( V_53 ) ;
int V_66 = F_26 ( V_53 ) ;
int V_67 = F_27 ( V_53 ) ;
V_63 = V_57 ;
if ( V_65 )
V_19 = V_65 - 1 ;
if ( V_66 )
V_64 = V_66 - 1 ;
if ( V_67 )
V_32 = V_67 - 1 ;
F_17 ( V_2 -> V_45 . V_52 , L_18 ,
V_62 ,
V_65 ? V_59 [ V_19 ] : L_19 ,
V_66 ? ( V_64 ? L_20 : L_14 ) : L_19 ,
V_67 ? ( V_32 ? L_15 : L_16 ) : L_19 ) ;
}
if ( V_64 )
F_11 ( V_2 , V_3 , V_32 ) ;
else {
F_9 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 , V_19 ) ;
}
F_6 ( V_2 , V_3 , F_28 ( V_53 ) ) ;
if ( V_63 != V_57 )
F_13 ( V_2 , V_3 ) ;
if ( V_55 ) {
if ( V_15 == V_17 )
V_55 [ V_2 -> V_68 ] |= F_7 ( V_3 ) ;
else
V_55 [ V_2 -> V_68 ] &= ~ F_7 ( V_3 ) ;
} else
F_4 ( V_2 , V_3 , V_15 ) ;
F_12 ( V_2 , V_3 , V_63 , V_34 ) ;
}
static void F_29 ( unsigned int * V_15 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_1 * V_45 = V_71 [ V_69 ] ;
unsigned int V_72 = V_15 [ V_69 ] ;
if ( ! V_45 )
break;
F_30 ( V_45 -> V_73 ) ;
V_15 [ V_69 ] = F_2 ( V_45 -> V_8 + V_16 ) ;
F_3 ( V_72 , V_45 -> V_8 + V_16 ) ;
}
}
static void F_31 ( unsigned int * V_15 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_1 * V_45 = V_71 [ V_69 ] ;
if ( ! V_45 )
break;
F_3 ( V_15 [ V_69 ] , V_45 -> V_8 + V_16 ) ;
F_32 ( V_45 -> V_73 ) ;
}
}
static int F_33 ( T_2 * V_74 , int V_75 , bool V_54 )
{
static unsigned int V_15 [ V_70 ] ;
unsigned long V_76 ;
bool V_34 = false ;
int V_77 = 0 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_75 ; V_69 ++ ) {
if ( F_21 ( V_74 [ V_69 ] ) == V_58 ) {
V_34 = true ;
break;
}
}
F_34 ( & V_78 , V_76 ) ;
if ( V_34 ) {
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_69 = 0 ; V_69 < V_75 ; V_69 ++ ) {
int V_62 = F_19 ( V_74 [ V_69 ] ) ;
int V_3 = V_62 % V_79 ;
if ( F_21 ( V_74 [ V_69 ] ) == V_58 )
V_15 [ V_62 / V_79 ] &= ~ F_7 ( V_3 ) ;
}
F_29 ( V_15 ) ;
}
for ( V_69 = 0 ; V_69 < V_75 ; V_69 ++ ) {
struct V_1 * V_2 ;
int V_62 = F_19 ( V_74 [ V_69 ] ) ;
V_2 = V_71 [ V_62 / V_79 ] ;
if ( ! V_2 ) {
V_77 = - V_80 ;
break;
}
F_30 ( V_2 -> V_73 ) ;
F_35 ( & V_2 -> V_81 ) ;
F_18 ( V_2 , V_62 % V_79 ,
V_74 [ V_69 ] , V_54 , V_34 ? V_15 : NULL ) ;
F_36 ( & V_2 -> V_81 ) ;
F_32 ( V_2 -> V_73 ) ;
}
if ( V_34 )
F_31 ( V_15 ) ;
F_37 ( & V_78 , V_76 ) ;
return V_77 ;
}
int F_38 ( T_2 V_53 , bool V_54 )
{
return F_33 ( & V_53 , 1 , V_54 ) ;
}
int F_39 ( T_2 * V_74 , int V_75 )
{
return F_33 ( V_74 , V_75 , false ) ;
}
int F_40 ( T_2 * V_74 , int V_75 )
{
return F_33 ( V_74 , V_75 , true ) ;
}
int F_41 ( int V_44 , enum V_13 V_14 )
{
struct V_1 * V_2 ;
unsigned long V_76 ;
V_2 = V_71 [ V_44 / V_79 ] ;
if ( ! V_2 )
return - V_80 ;
F_30 ( V_2 -> V_73 ) ;
F_34 ( & V_78 , V_76 ) ;
F_35 ( & V_2 -> V_81 ) ;
F_4 ( V_2 , V_44 % V_79 , V_14 ) ;
F_36 ( & V_2 -> V_81 ) ;
F_37 ( & V_78 , V_76 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
int F_42 ( int V_44 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
unsigned long V_76 ;
V_2 = V_71 [ V_44 / V_79 ] ;
if ( ! V_2 )
return - V_80 ;
F_30 ( V_2 -> V_73 ) ;
F_34 ( & V_2 -> V_81 , V_76 ) ;
F_5 ( V_2 , V_44 % V_79 , V_19 ) ;
F_37 ( & V_2 -> V_81 , V_76 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
int F_43 ( int V_44 , int V_4 )
{
struct V_1 * V_2 ;
unsigned long V_76 ;
V_2 = V_71 [ V_44 / V_79 ] ;
if ( ! V_2 )
return - V_80 ;
F_30 ( V_2 -> V_73 ) ;
F_34 ( & V_2 -> V_81 , V_76 ) ;
F_1 ( V_2 , V_44 % V_79 , V_4 ) ;
F_37 ( & V_2 -> V_81 , V_76 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
int F_44 ( int V_44 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = V_71 [ V_44 / V_79 ] ;
if ( ! V_2 )
return - V_80 ;
V_5 = 1 << ( V_44 % V_79 ) ;
F_30 ( V_2 -> V_73 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
F_32 ( V_2 -> V_73 ) ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_45 ( int V_44 )
{
return 1 << ( V_44 % V_79 ) ;
}
static void F_46 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_47 ( V_49 ) ;
if ( ! V_2 )
return;
F_30 ( V_2 -> V_73 ) ;
F_3 ( F_45 ( V_49 -> V_82 ) , V_2 -> V_8 + V_83 ) ;
F_32 ( V_2 -> V_73 ) ;
}
static void F_48 ( struct V_1 * V_2 ,
int V_44 , enum V_84 V_85 ,
bool V_86 )
{
T_1 V_87 = F_45 ( V_44 ) ;
T_1 * V_88 ;
T_1 * V_89 ;
T_1 V_90 ;
T_1 V_91 ;
if ( V_85 == V_92 ) {
V_90 = V_50 ;
V_91 = V_51 ;
V_88 = & V_2 -> V_43 ;
V_89 = & V_2 -> V_41 ;
} else {
V_90 = V_38 ;
V_91 = V_39 ;
V_88 = & V_2 -> V_35 ;
V_89 = & V_2 -> V_36 ;
}
if ( V_2 -> V_93 & V_87 ) {
if ( V_86 )
* V_88 |= V_87 ;
else
* V_88 &= ~ V_87 ;
F_3 ( * V_88 , V_2 -> V_8 + V_90 ) ;
}
if ( V_2 -> V_94 & V_87 ) {
if ( V_86 )
* V_89 |= V_87 ;
else
* V_89 &= ~ V_87 ;
F_3 ( * V_89 , V_2 -> V_8 + V_91 ) ;
}
}
static void F_49 ( struct V_1 * V_2 ,
int V_44 , bool V_95 )
{
if ( V_2 -> V_96 && V_95 ) {
F_4 ( V_2 , V_44 % V_79 ,
V_97 ) ;
}
F_48 ( V_2 , V_44 , V_98 , V_95 ) ;
}
static int F_50 ( struct V_48 * V_49 , bool V_86 )
{
struct V_1 * V_2 ;
unsigned long V_76 ;
T_1 V_87 ;
V_2 = F_47 ( V_49 ) ;
V_87 = F_45 ( V_49 -> V_82 ) ;
if ( ! V_2 )
return - V_80 ;
F_30 ( V_2 -> V_73 ) ;
F_34 ( & V_78 , V_76 ) ;
F_35 ( & V_2 -> V_81 ) ;
F_48 ( V_2 , V_49 -> V_82 , V_92 , V_86 ) ;
if ( ! ( V_2 -> V_99 & V_87 ) )
F_49 ( V_2 , V_49 -> V_82 , V_86 ) ;
F_36 ( & V_2 -> V_81 ) ;
F_37 ( & V_78 , V_76 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
static void F_51 ( struct V_48 * V_49 )
{
F_50 ( V_49 , false ) ;
}
static void F_52 ( struct V_48 * V_49 )
{
F_50 ( V_49 , true ) ;
}
static int F_53 ( struct V_48 * V_49 , unsigned int V_95 )
{
struct V_1 * V_2 ;
unsigned long V_76 ;
T_1 V_87 ;
V_2 = F_47 ( V_49 ) ;
if ( ! V_2 )
return - V_80 ;
V_87 = F_45 ( V_49 -> V_82 ) ;
F_30 ( V_2 -> V_73 ) ;
F_34 ( & V_78 , V_76 ) ;
F_35 ( & V_2 -> V_81 ) ;
if ( F_16 ( V_49 ) )
F_49 ( V_2 , V_49 -> V_82 , V_95 ) ;
if ( V_95 )
V_2 -> V_99 |= V_87 ;
else
V_2 -> V_99 &= ~ V_87 ;
F_36 ( & V_2 -> V_81 ) ;
F_37 ( & V_78 , V_76 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_54 ( struct V_48 * V_49 , unsigned int type )
{
bool V_29 = ! F_16 ( V_49 ) ;
bool V_100 = F_55 ( V_49 ) ;
struct V_1 * V_2 ;
unsigned long V_76 ;
T_1 V_87 ;
V_2 = F_47 ( V_49 ) ;
V_87 = F_45 ( V_49 -> V_82 ) ;
if ( ! V_2 )
return - V_80 ;
if ( type & V_101 )
return - V_80 ;
if ( type & V_102 )
return - V_80 ;
F_30 ( V_2 -> V_73 ) ;
F_34 ( & V_2 -> V_81 , V_76 ) ;
if ( V_29 )
F_48 ( V_2 , V_49 -> V_82 , V_92 , false ) ;
if ( V_29 || V_100 )
F_48 ( V_2 , V_49 -> V_82 , V_98 , false ) ;
V_2 -> V_93 &= ~ V_87 ;
if ( type & V_103 )
V_2 -> V_93 |= V_87 ;
V_2 -> V_94 &= ~ V_87 ;
if ( type & V_104 )
V_2 -> V_94 |= V_87 ;
if ( V_29 )
F_48 ( V_2 , V_49 -> V_82 , V_92 , true ) ;
if ( V_29 || V_100 )
F_48 ( V_2 , V_49 -> V_82 , V_98 , true ) ;
F_37 ( & V_2 -> V_81 , V_76 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
static unsigned int F_56 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
F_30 ( V_2 -> V_73 ) ;
F_52 ( V_49 ) ;
return 0 ;
}
static void F_57 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_47 ( V_49 ) ;
F_51 ( V_49 ) ;
F_32 ( V_2 -> V_73 ) ;
}
static void F_58 ( unsigned int V_47 , struct V_105 * V_106 ,
T_1 V_107 )
{
struct V_1 * V_2 ;
struct V_108 * V_109 = F_59 ( V_47 ) ;
unsigned int V_110 ;
F_60 ( V_109 , V_106 ) ;
V_2 = F_61 ( V_47 ) ;
V_110 = V_2 -> V_111 -> V_112 . V_113 . V_110 ;
while ( V_107 ) {
int V_5 = F_62 ( V_107 ) ;
F_63 ( V_110 + V_5 ) ;
V_107 &= ~ F_7 ( V_5 ) ;
}
F_64 ( V_109 , V_106 ) ;
}
static void F_65 ( unsigned int V_47 , struct V_105 * V_106 )
{
struct V_1 * V_2 = F_61 ( V_47 ) ;
T_1 V_107 ;
F_30 ( V_2 -> V_73 ) ;
V_107 = F_2 ( V_2 -> V_8 + V_114 ) ;
F_32 ( V_2 -> V_73 ) ;
F_58 ( V_47 , V_106 , V_107 ) ;
}
static void F_66 ( unsigned int V_47 ,
struct V_105 * V_106 )
{
struct V_1 * V_2 = F_61 ( V_47 ) ;
T_1 V_107 = V_2 -> V_115 ( V_2 -> V_68 ) ;
F_58 ( V_47 , V_106 , V_107 ) ;
}
static int F_67 ( struct V_1 * V_2 )
{
F_68 ( V_2 -> V_116 , F_65 ) ;
F_69 ( V_2 -> V_116 , V_2 ) ;
if ( V_2 -> V_117 >= 0 ) {
F_68 ( V_2 -> V_117 ,
F_66 ) ;
F_69 ( V_2 -> V_117 , V_2 ) ;
}
return 0 ;
}
static int F_70 ( struct V_118 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
return F_71 ( V_44 ) ;
}
static void F_72 ( struct V_118 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
F_73 ( V_44 ) ;
}
static int F_74 ( struct V_118 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_75 ( V_45 , struct V_1 , V_45 ) ;
F_30 ( V_2 -> V_73 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_76 ( struct V_118 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_75 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_5 = 1 << V_3 ;
int V_119 ;
F_30 ( V_2 -> V_73 ) ;
V_119 = ( F_2 ( V_2 -> V_8 + V_120 ) & V_5 ) != 0 ;
F_32 ( V_2 -> V_73 ) ;
return V_119 ;
}
static void F_77 ( struct V_118 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_75 ( V_45 , struct V_1 , V_45 ) ;
F_30 ( V_2 -> V_73 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_32 ( V_2 -> V_73 ) ;
}
static int F_78 ( struct V_118 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_75 ( V_45 , struct V_1 , V_45 ) ;
F_30 ( V_2 -> V_73 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
static int F_79 ( struct V_118 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_75 ( V_45 , struct V_1 , V_45 ) ;
return F_80 ( V_2 -> V_111 , V_3 ) ;
}
static void F_81 ( struct V_121 * V_122 , struct V_118 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_123 = F_82 ( V_45 , V_3 ) ;
struct V_1 * V_2 =
F_75 ( V_45 , struct V_1 , V_45 ) ;
int V_14 ;
bool V_124 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_125 [] = {
[ V_57 ] = L_21 ,
[ V_11 ] = L_22 ,
[ V_12 ] = L_23 ,
[ V_58 ] = L_24 ,
} ;
F_30 ( V_2 -> V_73 ) ;
V_124 = ! ! ( F_2 ( V_2 -> V_8 + V_126 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_44 ( V_44 ) ;
F_83 ( V_122 , L_25 ,
V_44 , V_123 ? : L_26 ,
V_124 ? L_27 : L_28 ,
V_45 -> V_127
? ( V_45 -> V_127 ( V_45 , V_3 ) ? L_29 : L_30 )
: L_31 ,
( V_14 < 0 ) ? L_32 : V_125 [ V_14 ] ,
V_19 ? L_33 : L_6 ) ;
if ( V_123 && ! V_124 ) {
int V_47 = F_84 ( V_44 ) ;
struct V_105 * V_106 = F_85 ( V_47 ) ;
if ( V_47 >= 0 && V_106 -> V_128 ) {
char * V_129 ;
T_1 V_87 = F_45 ( V_44 ) ;
if ( V_2 -> V_93 & V_87 )
V_129 = L_34 ;
else if ( V_2 -> V_94 & V_87 )
V_129 = L_35 ;
else
V_129 = L_36 ;
F_83 ( V_122 , L_37 ,
V_47 , V_129 ,
F_55 ( & V_106 -> V_48 )
? L_38 : L_17 ) ;
}
}
F_32 ( V_2 -> V_73 ) ;
}
static void F_86 ( struct V_121 * V_122 , struct V_118 * V_45 )
{
unsigned V_69 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_69 = 0 ; V_69 < V_45 -> V_130 ; V_69 ++ , V_44 ++ ) {
F_81 ( V_122 , V_45 , V_69 , V_44 ) ;
F_83 ( V_122 , L_39 ) ;
}
}
static inline void F_81 ( struct V_121 * V_122 ,
struct V_118 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_87 ( void )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_1 * V_45 = V_71 [ V_69 ] ;
if ( ! V_45 )
continue;
F_30 ( V_45 -> V_73 ) ;
}
}
void F_88 ( void )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_1 * V_45 = V_71 [ V_69 ] ;
if ( ! V_45 )
continue;
F_32 ( V_45 -> V_73 ) ;
}
}
void F_89 ( void )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_1 * V_45 = V_71 [ V_69 ] ;
if ( ! V_45 )
break;
F_30 ( V_45 -> V_73 ) ;
F_3 ( V_45 -> V_35 & V_45 -> V_99 ,
V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 & V_45 -> V_99 ,
V_45 -> V_8 + V_39 ) ;
F_32 ( V_45 -> V_73 ) ;
}
}
void F_90 ( void )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_70 ; V_69 ++ ) {
struct V_1 * V_45 = V_71 [ V_69 ] ;
if ( ! V_45 )
break;
F_30 ( V_45 -> V_73 ) ;
F_3 ( V_45 -> V_35 , V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 , V_45 -> V_8 + V_39 ) ;
F_32 ( V_45 -> V_73 ) ;
}
}
void F_91 ( int V_131 , T_1 * V_23 )
{
if ( V_131 < V_70 ) {
struct V_1 * V_45 = V_71 [ V_131 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
int F_92 ( struct V_132 * V_49 , unsigned int V_47 ,
T_3 V_82 )
{
struct V_1 * V_2 = V_49 -> V_133 ;
if ( ! V_2 )
return - V_80 ;
F_93 ( V_47 , & V_134 , V_135 ) ;
F_94 ( V_47 , V_136 ) ;
F_95 ( V_47 , V_2 ) ;
F_96 ( V_47 , V_104 ) ;
return 0 ;
}
static int T_4 F_97 ( struct V_137 * V_52 )
{
struct V_138 * V_139 = V_52 -> V_52 . V_140 ;
struct V_141 * V_142 = V_52 -> V_52 . V_143 ;
struct V_1 * V_2 ;
struct V_118 * V_45 ;
struct V_144 * V_145 ;
struct V_73 * V_73 ;
int V_146 ;
void T_5 * V_46 ;
int V_47 ;
int V_77 ;
if ( ! V_139 && ! V_142 ) {
F_98 ( & V_52 -> V_52 , L_40 ) ;
return - V_147 ;
}
if ( V_142 ) {
V_139 = F_99 ( sizeof( * V_139 ) , V_148 ) ;
if ( ! V_139 )
return - V_149 ;
if ( F_100 ( V_142 , L_41 , NULL ) )
V_139 -> V_150 = true ;
if ( F_101 ( V_142 , L_42 , & V_52 -> V_151 ) ) {
F_98 ( & V_52 -> V_52 , L_43 ) ;
V_77 = - V_80 ;
goto V_152;
}
V_139 -> V_153 = V_52 -> V_151 * V_79 ;
V_139 -> V_154 = V_79 ;
}
V_145 = F_102 ( V_52 , V_155 , 0 ) ;
if ( ! V_145 ) {
V_77 = - V_156 ;
goto V_152;
}
V_47 = F_103 ( V_52 , 0 ) ;
if ( V_47 < 0 ) {
V_77 = V_47 ;
goto V_152;
}
V_146 = F_103 ( V_52 , 1 ) ;
if ( V_146 >= 0 && ! V_139 -> V_115 ) {
V_77 = - V_80 ;
goto V_152;
}
if ( F_104 ( V_145 -> V_157 , F_105 ( V_145 ) ,
F_106 ( & V_52 -> V_52 ) ) == NULL ) {
V_77 = - V_158 ;
goto V_152;
}
V_46 = F_107 ( V_145 -> V_157 , F_105 ( V_145 ) ) ;
if ( ! V_46 ) {
V_77 = - V_149 ;
goto V_159;
}
V_73 = F_108 ( & V_52 -> V_52 , NULL ) ;
if ( F_109 ( V_73 ) ) {
V_77 = F_110 ( V_73 ) ;
goto V_160;
}
F_111 ( V_73 ) ;
V_2 = F_99 ( sizeof( * V_2 ) , V_148 ) ;
if ( ! V_2 ) {
V_77 = - V_149 ;
goto V_161;
}
V_2 -> V_68 = V_52 -> V_151 ;
V_2 -> V_73 = V_73 ;
V_2 -> V_8 = V_46 ;
V_2 -> V_45 = V_162 ;
V_2 -> V_116 = V_47 ;
V_2 -> V_117 = V_146 ;
V_2 -> V_115 = V_139 -> V_115 ;
V_2 -> V_37 = V_139 -> V_37 ;
V_2 -> V_96 = V_139 -> V_150 ;
F_112 ( & V_2 -> V_81 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_139 -> V_153 ;
V_45 -> V_130 = V_139 -> V_154 ;
V_45 -> V_123 = V_139 -> V_163 ? : F_106 ( & V_52 -> V_52 ) ;
V_45 -> V_52 = & V_52 -> V_52 ;
V_45 -> V_164 = V_165 ;
F_30 ( V_2 -> V_73 ) ;
V_2 -> V_28 = F_113 ( V_2 -> V_8 + V_30 ) ;
F_32 ( V_2 -> V_73 ) ;
#ifdef F_114
V_45 -> V_143 = V_142 ;
#endif
V_77 = F_115 ( & V_2 -> V_45 ) ;
if ( V_77 )
goto V_166;
F_116 ( V_2 -> V_68 >= F_117 ( V_71 ) ) ;
V_71 [ V_2 -> V_68 ] = V_2 ;
F_118 ( V_52 , V_2 ) ;
V_2 -> V_111 = F_119 ( V_142 , V_79 ,
F_14 ( V_139 -> V_153 ) ,
0 , & V_167 , V_2 ) ;
if ( ! V_2 -> V_111 ) {
F_120 ( L_44 , V_142 -> V_168 ) ;
V_77 = - V_169 ;
goto V_166;
}
F_67 ( V_2 ) ;
F_121 ( & V_52 -> V_52 , L_45 , V_2 -> V_8 ) ;
return 0 ;
V_166:
F_122 ( V_2 ) ;
V_161:
F_32 ( V_73 ) ;
F_123 ( V_73 ) ;
V_160:
F_124 ( V_46 ) ;
V_159:
F_125 ( V_145 -> V_157 , F_105 ( V_145 ) ) ;
V_152:
F_98 ( & V_52 -> V_52 , L_46 , V_77 ,
V_139 -> V_153 , V_139 -> V_153 + 31 ) ;
if ( V_142 )
F_122 ( V_139 ) ;
return V_77 ;
}
static int F_126 ( struct V_170 * V_171 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
return V_173 -> V_174 -> V_175 ;
}
static const char * F_128 ( struct V_170 * V_171 ,
unsigned V_176 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
return V_173 -> V_174 -> V_177 [ V_176 ] . V_163 ;
}
static int F_129 ( struct V_170 * V_171 , unsigned V_176 ,
const unsigned * * V_178 ,
unsigned * V_179 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
* V_178 = V_173 -> V_174 -> V_177 [ V_176 ] . V_178 ;
* V_179 = V_173 -> V_174 -> V_177 [ V_176 ] . V_180 ;
return 0 ;
}
static struct V_181 *
F_130 ( struct V_170 * V_171 , unsigned V_3 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_173 -> V_174 -> V_182 ; V_69 ++ ) {
struct V_181 * V_183 ;
V_183 = & V_173 -> V_174 -> V_184 [ V_69 ] ;
if ( V_3 >= V_183 -> V_185 &&
V_3 <= ( V_183 -> V_185 + V_183 -> V_180 - 1 ) )
return V_183 ;
}
return NULL ;
}
static void F_131 ( struct V_170 * V_171 , struct V_121 * V_122 ,
unsigned V_3 )
{
struct V_181 * V_183 ;
struct V_118 * V_45 ;
V_183 = F_130 ( V_171 , V_3 ) ;
if ( ! V_183 || ! V_183 -> V_186 ) {
F_83 ( V_122 , L_47 ) ;
return;
}
V_45 = V_183 -> V_186 ;
F_81 ( V_122 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static int F_132 ( struct V_170 * V_171 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
return V_173 -> V_174 -> V_187 ;
}
static const char * F_133 ( struct V_170 * V_171 ,
unsigned V_188 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
return V_173 -> V_174 -> V_189 [ V_188 ] . V_163 ;
}
static int F_134 ( struct V_170 * V_171 ,
unsigned V_188 ,
const char * const * * V_177 ,
unsigned * const V_190 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
* V_177 = V_173 -> V_174 -> V_189 [ V_188 ] . V_177 ;
* V_190 = V_173 -> V_174 -> V_189 [ V_188 ] . V_175 ;
return 0 ;
}
static int F_135 ( struct V_170 * V_171 , unsigned V_188 ,
unsigned V_191 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
const struct V_192 * V_193 ;
static unsigned int V_15 [ V_70 ] ;
unsigned long V_76 ;
bool V_34 ;
int V_77 = - V_80 ;
int V_69 ;
V_193 = & V_173 -> V_174 -> V_177 [ V_191 ] ;
if ( V_193 -> V_194 < 0 )
return - V_80 ;
F_17 ( V_173 -> V_52 , L_48 , V_193 -> V_163 , V_193 -> V_180 ) ;
V_34 = ( V_193 -> V_194 == V_58 ) ;
if ( V_34 ) {
F_34 ( & V_78 , V_76 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_69 = 0 ; V_69 < V_193 -> V_180 ; V_69 ++ )
V_15 [ V_193 -> V_178 [ V_69 ] / V_79 ] &= ~ F_7 ( V_193 -> V_178 [ V_69 ] ) ;
F_29 ( V_15 ) ;
}
for ( V_69 = 0 ; V_69 < V_193 -> V_180 ; V_69 ++ ) {
struct V_181 * V_183 ;
struct V_1 * V_2 ;
struct V_118 * V_45 ;
unsigned V_5 ;
V_183 = F_130 ( V_171 , V_193 -> V_178 [ V_69 ] ) ;
if ( ! V_183 ) {
F_98 ( V_173 -> V_52 ,
L_49 ,
V_193 -> V_178 [ V_69 ] , V_193 -> V_163 , V_69 ) ;
goto V_195;
}
if ( ! V_183 -> V_186 ) {
F_98 ( V_173 -> V_52 , L_50 ,
V_193 -> V_178 [ V_69 ] , V_193 -> V_163 , V_69 ) ;
goto V_195;
}
V_45 = V_183 -> V_186 ;
V_2 = F_75 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_173 -> V_52 , L_51 , V_193 -> V_178 [ V_69 ] , V_193 -> V_194 ) ;
F_30 ( V_2 -> V_73 ) ;
V_5 = V_193 -> V_178 [ V_69 ] % V_79 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 , V_193 -> V_194 , V_34 ) ;
F_32 ( V_2 -> V_73 ) ;
}
V_77 = 0 ;
V_195:
if ( V_34 ) {
F_31 ( V_15 ) ;
F_37 ( & V_78 , V_76 ) ;
}
return V_77 ;
}
static void F_136 ( struct V_170 * V_171 ,
unsigned V_188 , unsigned V_191 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
const struct V_192 * V_193 ;
V_193 = & V_173 -> V_174 -> V_177 [ V_191 ] ;
if ( V_193 -> V_194 < 0 )
return;
F_17 ( V_173 -> V_52 , L_52 , V_193 -> V_163 , V_193 -> V_180 ) ;
}
int F_137 ( struct V_170 * V_171 ,
struct V_181 * V_183 ,
unsigned V_3 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
struct V_1 * V_2 ;
struct V_118 * V_45 ;
unsigned V_5 ;
if ( ! V_183 ) {
F_98 ( V_173 -> V_52 , L_53 ) ;
return - V_80 ;
}
if ( ! V_183 -> V_186 ) {
F_98 ( V_173 -> V_52 , L_54 ) ;
return - V_80 ;
}
V_45 = V_183 -> V_186 ;
V_2 = F_75 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_173 -> V_52 , L_55 , V_3 ) ;
F_30 ( V_2 -> V_73 ) ;
V_5 = V_3 % V_79 ;
F_1 ( V_2 , V_5 , V_57 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
void F_138 ( struct V_170 * V_171 ,
struct V_181 * V_183 ,
unsigned V_3 )
{
struct V_172 * V_173 = F_127 ( V_171 ) ;
F_17 ( V_173 -> V_52 , L_56 , V_3 ) ;
}
int F_139 ( struct V_170 * V_171 ,
unsigned V_62 ,
unsigned long * V_196 )
{
return - V_80 ;
}
int F_140 ( struct V_170 * V_171 ,
unsigned V_62 ,
unsigned long V_196 )
{
static const char * V_59 [] = {
[ V_22 ] = L_6 ,
[ V_24 ] = L_7 ,
[ V_26 ] = L_8 ,
[ 3 ] = L_9
} ;
static const char * V_60 [] = {
[ V_61 ] = L_10 ,
[ V_17 ] = L_11 ,
} ;
struct V_172 * V_173 = F_127 ( V_171 ) ;
struct V_1 * V_2 ;
struct V_181 * V_183 ;
struct V_118 * V_45 ;
unsigned V_5 ;
T_2 V_53 = ( T_2 ) V_196 ;
int V_19 = F_20 ( V_53 ) ;
int V_15 = F_22 ( V_53 ) ;
int V_64 = F_23 ( V_53 ) ;
int V_32 = F_24 ( V_53 ) ;
bool V_28 = F_28 ( V_53 ) ;
bool V_197 = F_141 ( V_53 ) ;
bool V_54 = F_142 ( V_53 ) ;
V_183 = F_130 ( V_171 , V_62 ) ;
if ( ! V_183 ) {
F_98 ( V_173 -> V_52 , L_57 , V_62 ) ;
return - V_80 ;
}
if ( ! V_183 -> V_186 ) {
F_98 ( V_173 -> V_52 , L_58 ,
V_62 ) ;
return - V_80 ;
}
V_45 = V_183 -> V_186 ;
V_2 = F_75 ( V_45 , struct V_1 , V_45 ) ;
if ( V_54 ) {
int V_65 = F_25 ( V_53 ) ;
int V_66 = F_26 ( V_53 ) ;
int V_67 = F_27 ( V_53 ) ;
V_197 = true ;
if ( V_65 )
V_19 = V_65 - 1 ;
if ( V_66 )
V_64 = V_66 - 1 ;
if ( V_67 )
V_32 = V_67 - 1 ;
F_17 ( V_2 -> V_45 . V_52 , L_18 ,
V_62 ,
V_65 ? V_59 [ V_19 ] : L_19 ,
V_66 ? ( V_64 ? L_20 : L_14 ) : L_19 ,
V_67 ? ( V_32 ? L_15 : L_16 ) : L_19 ) ;
}
F_17 ( V_2 -> V_45 . V_52 , L_59 ,
V_62 , V_53 , V_59 [ V_19 ] , V_60 [ V_15 ] ,
V_64 ? L_13 : L_14 ,
V_64 ? ( V_32 ? L_15 : L_16 ) : L_17 ,
V_28 ? L_60 : L_61 ) ;
F_30 ( V_2 -> V_73 ) ;
V_5 = V_62 % V_79 ;
if ( V_197 )
F_1 ( V_2 , V_5 , V_57 ) ;
if ( V_64 )
F_11 ( V_2 , V_5 , V_32 ) ;
else {
F_9 ( V_2 , V_5 ) ;
F_5 ( V_2 , V_5 , V_19 ) ;
}
F_6 ( V_2 , V_5 , V_28 ) ;
F_4 ( V_2 , V_5 , V_15 ) ;
F_32 ( V_2 -> V_73 ) ;
return 0 ;
}
static int T_4 F_143 ( struct V_137 * V_198 )
{
const struct V_199 * V_200 = F_144 ( V_198 ) ;
struct V_141 * V_142 = V_198 -> V_52 . V_143 ;
struct V_172 * V_173 ;
unsigned int V_201 = 0 ;
int V_69 ;
V_173 = F_145 ( & V_198 -> V_52 , sizeof( * V_173 ) , V_148 ) ;
if ( ! V_173 )
return - V_149 ;
if ( V_200 )
V_201 = V_200 -> V_202 ;
else if ( V_142 )
V_201 = ( unsigned int )
F_146 ( V_203 , & V_198 -> V_52 ) -> V_204 ;
if ( V_201 == V_205 )
F_147 ( & V_173 -> V_174 ) ;
for ( V_69 = 0 ; V_69 < V_173 -> V_174 -> V_182 ; V_69 ++ ) {
if ( ! V_71 [ V_69 ] ) {
F_148 ( & V_198 -> V_52 , L_62 , V_69 ) ;
F_149 ( & V_198 -> V_52 , V_173 ) ;
return - V_206 ;
}
V_173 -> V_174 -> V_184 [ V_69 ] . V_186 = & V_71 [ V_69 ] -> V_45 ;
}
V_207 . V_178 = V_173 -> V_174 -> V_178 ;
V_207 . V_180 = V_173 -> V_174 -> V_180 ;
V_173 -> V_52 = & V_198 -> V_52 ;
V_173 -> V_208 = F_150 ( & V_207 , & V_198 -> V_52 , V_173 ) ;
if ( ! V_173 -> V_208 ) {
F_98 ( & V_198 -> V_52 , L_63 ) ;
return - V_80 ;
}
for ( V_69 = 0 ; V_69 < V_173 -> V_174 -> V_182 ; V_69 ++ )
F_151 ( V_173 -> V_208 , & V_173 -> V_174 -> V_184 [ V_69 ] ) ;
F_118 ( V_198 , V_173 ) ;
F_121 ( & V_198 -> V_52 , L_64 ) ;
return 0 ;
}
static int T_6 F_152 ( void )
{
int V_77 ;
V_77 = F_153 ( & V_209 ) ;
if ( V_77 )
return V_77 ;
return F_153 ( & V_210 ) ;
}
