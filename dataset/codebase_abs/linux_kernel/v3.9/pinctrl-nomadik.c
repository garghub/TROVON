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
int V_47 = F_14 ( V_2 -> V_48 , V_3 ) ;
struct V_49 * V_50 = F_15 ( V_47 ) ;
if ( ! V_42 && ! V_40 )
return;
if ( ! V_50 || ! F_16 ( V_50 ) )
return;
if ( V_42 ) {
V_2 -> V_43 &= ~ F_7 ( V_3 ) ;
F_8 ( V_2 -> V_43 ,
V_2 -> V_8 + V_51 ) ;
}
if ( V_40 ) {
V_2 -> V_41 &= ~ F_7 ( V_3 ) ;
F_8 ( V_2 -> V_41 ,
V_2 -> V_8 + V_52 ) ;
}
F_17 ( V_2 -> V_45 . V_53 , L_1 , V_44 ) ;
}
static void F_18 ( void T_2 * V_54 , T_1 V_55 , T_1 V_56 )
{
T_1 V_32 ;
V_32 = F_2 ( V_54 ) ;
V_32 = ( ( V_32 & ~ V_55 ) | ( V_56 & V_55 ) ) ;
F_3 ( V_32 , V_54 ) ;
}
static void F_19 ( struct V_57 * V_58 ,
unsigned V_3 , unsigned V_59 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_5 ;
T_4 V_61 ;
const struct V_62 * V_63 ;
const T_3 * V_64 ;
if ( ! V_58 -> V_65 )
return;
if ( V_59 > V_66 ) {
F_20 ( V_58 -> V_53 , L_2 ,
V_59 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_68 ; V_60 ++ ) {
if ( V_58 -> V_67 -> V_69 [ V_60 ] . V_70 == V_3 )
break;
}
if ( V_60 == V_58 -> V_67 -> V_68 ) {
F_17 ( V_58 -> V_53 , L_3 ,
V_3 ) ;
return;
}
V_63 = V_58 -> V_67 -> V_69 + V_60 ;
V_64 = V_58 -> V_67 -> V_71 ;
if ( ! V_59 ) {
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_63 -> V_72 [ V_60 ] . V_73 == true ) {
V_54 = V_64 [ V_63 -> V_72 [ V_60 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_60 ] . V_75 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_58 -> V_53 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
return;
}
V_61 = V_59 - 1 ;
if ( V_63 -> V_72 [ V_61 ] . V_73 == false ) {
F_21 ( V_58 -> V_53 ,
L_5 ,
V_3 , V_59 ) ;
return;
}
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_60 == V_61 )
continue;
if ( V_63 -> V_72 [ V_60 ] . V_73 == true ) {
V_54 = V_64 [ V_63 -> V_72 [ V_60 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_60 ] . V_75 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) ) {
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_58 -> V_53 ,
L_4 ,
V_3 , V_60 + 1 ) ;
}
}
}
V_54 = V_64 [ V_63 -> V_72 [ V_61 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_61 ] . V_75 ;
F_17 ( V_58 -> V_53 , L_6 ,
V_3 , V_61 + 1 ) ;
F_18 ( V_58 -> V_65 + V_54 , F_7 ( V_5 ) , F_7 ( V_5 ) ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned V_3 ,
T_5 V_76 , bool V_77 , unsigned int * V_78 )
{
static const char * V_79 [] = {
[ V_80 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
[ V_81 ] = L_10
} ;
static const char * V_82 [] = {
[ V_22 ] = L_11 ,
[ V_24 ] = L_12 ,
[ V_26 ] = L_13 ,
[ 3 ] = L_14
} ;
static const char * V_83 [] = {
[ V_84 ] = L_15 ,
[ V_17 ] = L_16 ,
} ;
int V_70 = F_23 ( V_76 ) ;
int V_19 = F_24 ( V_76 ) ;
int V_85 = F_25 ( V_76 ) ;
int V_15 = F_26 ( V_76 ) ;
int V_86 = F_27 ( V_76 ) ;
int V_32 = F_28 ( V_76 ) ;
bool V_34 = V_85 == V_81 ;
F_17 ( V_2 -> V_45 . V_53 , L_17 ,
V_70 , V_76 , V_79 [ V_85 ] , V_82 [ V_19 ] , V_83 [ V_15 ] ,
V_86 ? L_18 : L_19 ,
V_86 ? ( V_32 ? L_20 : L_21 ) : L_22 ) ;
if ( V_77 ) {
int V_87 = F_29 ( V_76 ) ;
int V_88 = F_30 ( V_76 ) ;
int V_89 = F_31 ( V_76 ) ;
V_85 = V_80 ;
if ( V_87 )
V_19 = V_87 - 1 ;
if ( V_88 )
V_86 = V_88 - 1 ;
if ( V_89 )
V_32 = V_89 - 1 ;
F_17 ( V_2 -> V_45 . V_53 , L_23 ,
V_70 ,
V_87 ? V_82 [ V_19 ] : L_24 ,
V_88 ? ( V_86 ? L_25 : L_19 ) : L_24 ,
V_89 ? ( V_32 ? L_20 : L_21 ) : L_24 ) ;
}
if ( V_86 )
F_11 ( V_2 , V_3 , V_32 ) ;
else {
F_9 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 , V_19 ) ;
}
F_6 ( V_2 , V_3 , F_32 ( V_76 ) ) ;
if ( V_85 != V_80 )
F_13 ( V_2 , V_3 ) ;
if ( V_78 ) {
if ( V_15 == V_17 )
V_78 [ V_2 -> V_90 ] |= F_7 ( V_3 ) ;
else
V_78 [ V_2 -> V_90 ] &= ~ F_7 ( V_3 ) ;
} else
F_4 ( V_2 , V_3 , V_15 ) ;
F_12 ( V_2 , V_3 , V_85 , V_34 ) ;
}
static void F_33 ( unsigned int * V_15 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_91 ; V_60 ++ ) {
struct V_1 * V_45 = V_92 [ V_60 ] ;
unsigned int V_93 = V_15 [ V_60 ] ;
if ( ! V_45 )
break;
F_34 ( V_45 -> V_94 ) ;
V_15 [ V_60 ] = F_2 ( V_45 -> V_8 + V_16 ) ;
F_3 ( V_93 , V_45 -> V_8 + V_16 ) ;
}
}
static void F_35 ( unsigned int * V_15 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_91 ; V_60 ++ ) {
struct V_1 * V_45 = V_92 [ V_60 ] ;
if ( ! V_45 )
break;
F_3 ( V_15 [ V_60 ] , V_45 -> V_8 + V_16 ) ;
F_36 ( V_45 -> V_94 ) ;
}
}
static int F_37 ( T_5 * V_95 , int V_96 , bool V_77 )
{
static unsigned int V_15 [ V_91 ] ;
unsigned long V_97 ;
bool V_34 = false ;
int V_98 = 0 ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_96 ; V_60 ++ ) {
if ( F_25 ( V_95 [ V_60 ] ) == V_81 ) {
V_34 = true ;
break;
}
}
F_38 ( & V_99 , V_97 ) ;
if ( V_34 ) {
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_96 ; V_60 ++ ) {
int V_70 = F_23 ( V_95 [ V_60 ] ) ;
int V_3 = V_70 % V_100 ;
if ( F_25 ( V_95 [ V_60 ] ) == V_81 )
V_15 [ V_70 / V_100 ] &= ~ F_7 ( V_3 ) ;
}
F_33 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_96 ; V_60 ++ ) {
struct V_1 * V_2 ;
int V_70 = F_23 ( V_95 [ V_60 ] ) ;
V_2 = V_92 [ V_70 / V_100 ] ;
if ( ! V_2 ) {
V_98 = - V_101 ;
break;
}
F_34 ( V_2 -> V_94 ) ;
F_39 ( & V_2 -> V_102 ) ;
F_22 ( V_2 , V_70 % V_100 ,
V_95 [ V_60 ] , V_77 , V_34 ? V_15 : NULL ) ;
F_40 ( & V_2 -> V_102 ) ;
F_36 ( V_2 -> V_94 ) ;
}
if ( V_34 )
F_35 ( V_15 ) ;
F_41 ( & V_99 , V_97 ) ;
return V_98 ;
}
int F_42 ( T_5 V_76 , bool V_77 )
{
return F_37 ( & V_76 , 1 , V_77 ) ;
}
int F_43 ( T_5 * V_95 , int V_96 )
{
return F_37 ( V_95 , V_96 , false ) ;
}
int F_44 ( T_5 * V_95 , int V_96 )
{
return F_37 ( V_95 , V_96 , true ) ;
}
int F_45 ( int V_44 , enum V_13 V_14 )
{
struct V_1 * V_2 ;
unsigned long V_97 ;
V_2 = V_92 [ V_44 / V_100 ] ;
if ( ! V_2 )
return - V_101 ;
F_34 ( V_2 -> V_94 ) ;
F_38 ( & V_99 , V_97 ) ;
F_39 ( & V_2 -> V_102 ) ;
F_4 ( V_2 , V_44 % V_100 , V_14 ) ;
F_40 ( & V_2 -> V_102 ) ;
F_41 ( & V_99 , V_97 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
int F_46 ( int V_44 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
unsigned long V_97 ;
V_2 = V_92 [ V_44 / V_100 ] ;
if ( ! V_2 )
return - V_101 ;
F_34 ( V_2 -> V_94 ) ;
F_38 ( & V_2 -> V_102 , V_97 ) ;
F_5 ( V_2 , V_44 % V_100 , V_19 ) ;
F_41 ( & V_2 -> V_102 , V_97 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
int F_47 ( int V_44 , int V_4 )
{
struct V_1 * V_2 ;
unsigned long V_97 ;
V_2 = V_92 [ V_44 / V_100 ] ;
if ( ! V_2 )
return - V_101 ;
F_34 ( V_2 -> V_94 ) ;
F_38 ( & V_2 -> V_102 , V_97 ) ;
F_1 ( V_2 , V_44 % V_100 , V_4 ) ;
F_41 ( & V_2 -> V_102 , V_97 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static int T_6 F_48 ( struct V_103 * V_104 , int V_44 )
{
int V_60 ;
T_3 V_54 ;
T_4 V_5 ;
struct V_57 * V_58 = F_49 ( V_104 ) ;
const struct V_62 * V_63 ;
const T_3 * V_64 ;
if ( ! V_58 -> V_65 )
return V_81 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_68 ; V_60 ++ ) {
if ( V_58 -> V_67 -> V_69 [ V_60 ] . V_70 == V_44 )
break;
}
if ( V_60 == V_58 -> V_67 -> V_68 )
return V_81 ;
V_63 = V_58 -> V_67 -> V_69 + V_60 ;
V_64 = V_58 -> V_67 -> V_71 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
if ( V_63 -> V_72 [ V_60 ] . V_73 == true ) {
V_54 = V_64 [ V_63 -> V_72 [ V_60 ] . V_74 ] ;
V_5 = V_63 -> V_72 [ V_60 ] . V_75 ;
if ( F_2 ( V_58 -> V_65 + V_54 ) & F_7 ( V_5 ) )
return V_81 + V_60 + 1 ;
}
}
return V_81 ;
}
int F_50 ( int V_44 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = V_92 [ V_44 / V_100 ] ;
if ( ! V_2 )
return - V_101 ;
V_5 = 1 << ( V_44 % V_100 ) ;
F_34 ( V_2 -> V_94 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
F_36 ( V_2 -> V_94 ) ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_51 ( int V_44 )
{
return 1 << ( V_44 % V_100 ) ;
}
static void F_52 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
V_2 = F_53 ( V_50 ) ;
if ( ! V_2 )
return;
F_34 ( V_2 -> V_94 ) ;
F_3 ( F_51 ( V_50 -> V_105 ) , V_2 -> V_8 + V_106 ) ;
F_36 ( V_2 -> V_94 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
int V_44 , enum V_107 V_108 ,
bool V_109 )
{
T_1 V_110 = F_51 ( V_44 ) ;
T_1 * V_111 ;
T_1 * V_112 ;
T_1 V_113 ;
T_1 V_114 ;
if ( V_108 == V_115 ) {
V_113 = V_51 ;
V_114 = V_52 ;
V_111 = & V_2 -> V_43 ;
V_112 = & V_2 -> V_41 ;
} else {
V_113 = V_38 ;
V_114 = V_39 ;
V_111 = & V_2 -> V_35 ;
V_112 = & V_2 -> V_36 ;
}
if ( V_2 -> V_116 & V_110 ) {
if ( V_109 )
* V_111 |= V_110 ;
else
* V_111 &= ~ V_110 ;
F_3 ( * V_111 , V_2 -> V_8 + V_113 ) ;
}
if ( V_2 -> V_117 & V_110 ) {
if ( V_109 )
* V_112 |= V_110 ;
else
* V_112 &= ~ V_110 ;
F_3 ( * V_112 , V_2 -> V_8 + V_114 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
int V_44 , bool V_118 )
{
if ( V_2 -> V_119 && V_118 ) {
F_4 ( V_2 , V_44 % V_100 ,
V_120 ) ;
}
F_54 ( V_2 , V_44 , V_121 , V_118 ) ;
}
static int F_56 ( struct V_49 * V_50 , bool V_109 )
{
struct V_1 * V_2 ;
unsigned long V_97 ;
T_1 V_110 ;
V_2 = F_53 ( V_50 ) ;
V_110 = F_51 ( V_50 -> V_105 ) ;
if ( ! V_2 )
return - V_101 ;
F_34 ( V_2 -> V_94 ) ;
F_38 ( & V_99 , V_97 ) ;
F_39 ( & V_2 -> V_102 ) ;
F_54 ( V_2 , V_50 -> V_105 , V_115 , V_109 ) ;
if ( ! ( V_2 -> V_122 & V_110 ) )
F_55 ( V_2 , V_50 -> V_105 , V_109 ) ;
F_40 ( & V_2 -> V_102 ) ;
F_41 ( & V_99 , V_97 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static void F_57 ( struct V_49 * V_50 )
{
F_56 ( V_50 , false ) ;
}
static void F_58 ( struct V_49 * V_50 )
{
F_56 ( V_50 , true ) ;
}
static int F_59 ( struct V_49 * V_50 , unsigned int V_118 )
{
struct V_1 * V_2 ;
unsigned long V_97 ;
T_1 V_110 ;
V_2 = F_53 ( V_50 ) ;
if ( ! V_2 )
return - V_101 ;
V_110 = F_51 ( V_50 -> V_105 ) ;
F_34 ( V_2 -> V_94 ) ;
F_38 ( & V_99 , V_97 ) ;
F_39 ( & V_2 -> V_102 ) ;
if ( F_16 ( V_50 ) )
F_55 ( V_2 , V_50 -> V_105 , V_118 ) ;
if ( V_118 )
V_2 -> V_122 |= V_110 ;
else
V_2 -> V_122 &= ~ V_110 ;
F_40 ( & V_2 -> V_102 ) ;
F_41 ( & V_99 , V_97 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static int F_60 ( struct V_49 * V_50 , unsigned int type )
{
bool V_29 = ! F_16 ( V_50 ) ;
bool V_123 = F_61 ( V_50 ) ;
struct V_1 * V_2 ;
unsigned long V_97 ;
T_1 V_110 ;
V_2 = F_53 ( V_50 ) ;
V_110 = F_51 ( V_50 -> V_105 ) ;
if ( ! V_2 )
return - V_101 ;
if ( type & V_124 )
return - V_101 ;
if ( type & V_125 )
return - V_101 ;
F_34 ( V_2 -> V_94 ) ;
F_38 ( & V_2 -> V_102 , V_97 ) ;
if ( V_29 )
F_54 ( V_2 , V_50 -> V_105 , V_115 , false ) ;
if ( V_29 || V_123 )
F_54 ( V_2 , V_50 -> V_105 , V_121 , false ) ;
V_2 -> V_116 &= ~ V_110 ;
if ( type & V_126 )
V_2 -> V_116 |= V_110 ;
V_2 -> V_117 &= ~ V_110 ;
if ( type & V_127 )
V_2 -> V_117 |= V_110 ;
if ( V_29 )
F_54 ( V_2 , V_50 -> V_105 , V_115 , true ) ;
if ( V_29 || V_123 )
F_54 ( V_2 , V_50 -> V_105 , V_121 , true ) ;
F_41 ( & V_2 -> V_102 , V_97 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static unsigned int F_62 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_53 ( V_50 ) ;
F_34 ( V_2 -> V_94 ) ;
F_58 ( V_50 ) ;
return 0 ;
}
static void F_63 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_53 ( V_50 ) ;
F_57 ( V_50 ) ;
F_36 ( V_2 -> V_94 ) ;
}
static void F_64 ( unsigned int V_47 , struct V_128 * V_129 ,
T_1 V_130 )
{
struct V_1 * V_2 ;
struct V_131 * V_132 = F_65 ( V_47 ) ;
F_66 ( V_132 , V_129 ) ;
V_2 = F_67 ( V_47 ) ;
while ( V_130 ) {
int V_5 = F_68 ( V_130 ) ;
F_69 ( F_14 ( V_2 -> V_48 , V_5 ) ) ;
V_130 &= ~ F_7 ( V_5 ) ;
}
F_70 ( V_132 , V_129 ) ;
}
static void F_71 ( unsigned int V_47 , struct V_128 * V_129 )
{
struct V_1 * V_2 = F_67 ( V_47 ) ;
T_1 V_130 ;
F_34 ( V_2 -> V_94 ) ;
V_130 = F_2 ( V_2 -> V_8 + V_133 ) ;
F_36 ( V_2 -> V_94 ) ;
F_64 ( V_47 , V_129 , V_130 ) ;
}
static void F_72 ( unsigned int V_47 ,
struct V_128 * V_129 )
{
struct V_1 * V_2 = F_67 ( V_47 ) ;
T_1 V_130 = V_2 -> V_134 ( V_2 -> V_90 ) ;
F_64 ( V_47 , V_129 , V_130 ) ;
}
static int F_73 ( struct V_1 * V_2 )
{
F_74 ( V_2 -> V_135 , F_71 ) ;
F_75 ( V_2 -> V_135 , V_2 ) ;
if ( V_2 -> V_136 >= 0 ) {
F_74 ( V_2 -> V_136 ,
F_72 ) ;
F_75 ( V_2 -> V_136 , V_2 ) ;
}
return 0 ;
}
static int F_76 ( struct V_137 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
return F_77 ( V_44 ) ;
}
static void F_78 ( struct V_137 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
F_79 ( V_44 ) ;
}
static int F_80 ( struct V_137 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_81 ( V_45 , struct V_1 , V_45 ) ;
F_34 ( V_2 -> V_94 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static int F_82 ( struct V_137 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_81 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_5 = 1 << V_3 ;
int V_56 ;
F_34 ( V_2 -> V_94 ) ;
V_56 = ( F_2 ( V_2 -> V_8 + V_138 ) & V_5 ) != 0 ;
F_36 ( V_2 -> V_94 ) ;
return V_56 ;
}
static void F_83 ( struct V_137 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_81 ( V_45 , struct V_1 , V_45 ) ;
F_34 ( V_2 -> V_94 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_36 ( V_2 -> V_94 ) ;
}
static int F_84 ( struct V_137 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_81 ( V_45 , struct V_1 , V_45 ) ;
F_34 ( V_2 -> V_94 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static int F_85 ( struct V_137 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_81 ( V_45 , struct V_1 , V_45 ) ;
return F_86 ( V_2 -> V_48 , V_3 ) ;
}
static void F_87 ( struct V_139 * V_140 ,
struct V_103 * V_104 , struct V_137 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_141 = F_88 ( V_45 , V_3 ) ;
struct V_1 * V_2 =
F_81 ( V_45 , struct V_1 , V_45 ) ;
int V_14 ;
bool V_142 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_143 [] = {
[ V_80 ] = L_26 ,
[ V_11 ] = L_27 ,
[ V_12 ] = L_28 ,
[ V_81 ] = L_29 ,
[ V_81 + 1 ] = L_30 ,
[ V_81 + 2 ] = L_31 ,
[ V_81 + 3 ] = L_32 ,
[ V_81 + 4 ] = L_33 ,
} ;
F_34 ( V_2 -> V_94 ) ;
V_142 = ! ! ( F_2 ( V_2 -> V_8 + V_144 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_50 ( V_44 ) ;
if ( ( V_14 == V_81 ) && V_104 )
V_14 = F_48 ( V_104 , V_44 ) ;
F_89 ( V_140 , L_34 ,
V_44 , V_141 ? : L_35 ,
V_142 ? L_36 : L_37 ,
V_45 -> V_145
? ( V_45 -> V_145 ( V_45 , V_3 ) ? L_38 : L_39 )
: L_40 ,
( V_14 < 0 ) ? L_41 : V_143 [ V_14 ] ,
V_19 ? L_42 : L_11 ) ;
if ( V_141 && ! V_142 ) {
int V_47 = F_90 ( V_44 ) ;
struct V_128 * V_129 = F_91 ( V_47 ) ;
if ( V_47 >= 0 && V_129 -> V_146 ) {
char * V_147 ;
T_1 V_110 = F_51 ( V_44 ) ;
if ( V_2 -> V_116 & V_110 )
V_147 = L_43 ;
else if ( V_2 -> V_117 & V_110 )
V_147 = L_44 ;
else
V_147 = L_45 ;
F_89 ( V_140 , L_46 ,
V_47 , V_147 ,
F_61 ( & V_129 -> V_49 )
? L_47 : L_22 ) ;
}
}
F_36 ( V_2 -> V_94 ) ;
}
static void F_92 ( struct V_139 * V_140 , struct V_137 * V_45 )
{
unsigned V_60 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_60 = 0 ; V_60 < V_45 -> V_148 ; V_60 ++ , V_44 ++ ) {
F_87 ( V_140 , NULL , V_45 , V_60 , V_44 ) ;
F_89 ( V_140 , L_48 ) ;
}
}
static inline void F_87 ( struct V_139 * V_140 ,
struct V_103 * V_104 ,
struct V_137 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_93 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_91 ; V_60 ++ ) {
struct V_1 * V_45 = V_92 [ V_60 ] ;
if ( ! V_45 )
continue;
F_34 ( V_45 -> V_94 ) ;
}
}
void F_94 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_91 ; V_60 ++ ) {
struct V_1 * V_45 = V_92 [ V_60 ] ;
if ( ! V_45 )
continue;
F_36 ( V_45 -> V_94 ) ;
}
}
void F_95 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_91 ; V_60 ++ ) {
struct V_1 * V_45 = V_92 [ V_60 ] ;
if ( ! V_45 )
break;
F_34 ( V_45 -> V_94 ) ;
F_3 ( V_45 -> V_35 & V_45 -> V_122 ,
V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 & V_45 -> V_122 ,
V_45 -> V_8 + V_39 ) ;
F_36 ( V_45 -> V_94 ) ;
}
}
void F_96 ( void )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_91 ; V_60 ++ ) {
struct V_1 * V_45 = V_92 [ V_60 ] ;
if ( ! V_45 )
break;
F_34 ( V_45 -> V_94 ) ;
F_3 ( V_45 -> V_35 , V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 , V_45 -> V_8 + V_39 ) ;
F_36 ( V_45 -> V_94 ) ;
}
}
void F_97 ( int V_149 , T_1 * V_23 )
{
if ( V_149 < V_91 ) {
struct V_1 * V_45 = V_92 [ V_149 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static int F_98 ( struct V_150 * V_50 , unsigned int V_47 ,
T_7 V_105 )
{
struct V_1 * V_2 = V_50 -> V_151 ;
if ( ! V_2 )
return - V_101 ;
F_99 ( V_47 , & V_152 , V_153 ) ;
F_100 ( V_47 , V_154 ) ;
F_101 ( V_47 , V_2 ) ;
F_102 ( V_47 , V_127 ) ;
return 0 ;
}
static int F_103 ( struct V_155 * V_53 )
{
struct V_156 * V_157 = V_53 -> V_53 . V_158 ;
struct V_159 * V_160 = V_53 -> V_53 . V_161 ;
struct V_1 * V_2 ;
struct V_137 * V_45 ;
struct V_162 * V_163 ;
struct V_94 * V_94 ;
int V_164 ;
void T_2 * V_46 ;
int V_165 = 0 ;
int V_47 ;
int V_98 ;
if ( ! V_157 && ! V_160 ) {
F_20 ( & V_53 -> V_53 , L_49 ) ;
return - V_166 ;
}
if ( V_160 ) {
V_157 = F_104 ( & V_53 -> V_53 , sizeof( * V_157 ) , V_167 ) ;
if ( ! V_157 )
return - V_168 ;
if ( F_105 ( V_160 , L_50 , NULL ) )
V_157 -> V_169 = true ;
if ( F_106 ( V_160 , L_51 , & V_53 -> V_170 ) ) {
F_20 ( & V_53 -> V_53 , L_52 ) ;
return - V_101 ;
}
V_157 -> V_171 = V_53 -> V_170 * V_100 ;
V_157 -> V_172 = V_100 ;
}
V_163 = F_107 ( V_53 , V_173 , 0 ) ;
if ( ! V_163 )
return - V_174 ;
V_47 = F_108 ( V_53 , 0 ) ;
if ( V_47 < 0 )
return V_47 ;
V_164 = F_108 ( V_53 , 1 ) ;
if ( V_164 >= 0 && ! V_157 -> V_134 )
return - V_101 ;
V_46 = F_109 ( & V_53 -> V_53 , V_163 ) ;
if ( F_110 ( V_46 ) )
return F_111 ( V_46 ) ;
V_94 = F_112 ( & V_53 -> V_53 , NULL ) ;
if ( F_110 ( V_94 ) )
return F_111 ( V_94 ) ;
F_113 ( V_94 ) ;
V_2 = F_104 ( & V_53 -> V_53 , sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 )
return - V_168 ;
V_2 -> V_90 = V_53 -> V_170 ;
V_2 -> V_94 = V_94 ;
V_2 -> V_8 = V_46 ;
V_2 -> V_45 = V_175 ;
V_2 -> V_135 = V_47 ;
V_2 -> V_136 = V_164 ;
V_2 -> V_134 = V_157 -> V_134 ;
V_2 -> V_37 = V_157 -> V_37 ;
V_2 -> V_119 = V_157 -> V_169 ;
F_114 ( & V_2 -> V_102 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_157 -> V_171 ;
V_45 -> V_148 = V_157 -> V_172 ;
V_45 -> V_141 = V_157 -> V_176 ? : F_115 ( & V_53 -> V_53 ) ;
V_45 -> V_53 = & V_53 -> V_53 ;
V_45 -> V_177 = V_178 ;
F_34 ( V_2 -> V_94 ) ;
V_2 -> V_28 = F_116 ( V_2 -> V_8 + V_30 ) ;
F_36 ( V_2 -> V_94 ) ;
#ifdef F_117
V_45 -> V_161 = V_160 ;
#endif
V_98 = F_118 ( & V_2 -> V_45 ) ;
if ( V_98 )
return V_98 ;
F_119 ( V_2 -> V_90 >= F_120 ( V_92 ) ) ;
V_92 [ V_2 -> V_90 ] = V_2 ;
F_121 ( V_53 , V_2 ) ;
if ( ! V_160 )
V_165 = V_157 -> V_179 ;
V_2 -> V_48 = F_122 ( V_160 ,
V_100 , V_165 ,
& V_180 , V_2 ) ;
if ( ! V_2 -> V_48 ) {
F_20 ( & V_53 -> V_53 , L_53 ) ;
V_98 = F_123 ( & V_2 -> V_45 ) ;
return - V_181 ;
}
F_73 ( V_2 ) ;
F_124 ( & V_53 -> V_53 , L_54 , V_2 -> V_8 ) ;
return 0 ;
}
static int F_125 ( struct V_103 * V_104 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
return V_58 -> V_67 -> V_182 ;
}
static const char * F_126 ( struct V_103 * V_104 ,
unsigned V_183 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
return V_58 -> V_67 -> V_184 [ V_183 ] . V_176 ;
}
static int F_127 ( struct V_103 * V_104 , unsigned V_183 ,
const unsigned * * V_185 ,
unsigned * V_186 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
* V_185 = V_58 -> V_67 -> V_184 [ V_183 ] . V_185 ;
* V_186 = V_58 -> V_67 -> V_184 [ V_183 ] . V_187 ;
return 0 ;
}
static struct V_188 *
F_128 ( struct V_103 * V_104 , unsigned V_3 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
int V_60 ;
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_189 ; V_60 ++ ) {
struct V_188 * V_190 ;
V_190 = & V_58 -> V_67 -> V_191 [ V_60 ] ;
if ( V_3 >= V_190 -> V_192 &&
V_3 <= ( V_190 -> V_192 + V_190 -> V_187 - 1 ) )
return V_190 ;
}
return NULL ;
}
static void F_129 ( struct V_103 * V_104 , struct V_139 * V_140 ,
unsigned V_3 )
{
struct V_188 * V_190 ;
struct V_137 * V_45 ;
V_190 = F_128 ( V_104 , V_3 ) ;
if ( ! V_190 || ! V_190 -> V_193 ) {
F_89 ( V_140 , L_55 ) ;
return;
}
V_45 = V_190 -> V_193 ;
F_87 ( V_140 , V_104 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static void F_130 ( struct V_103 * V_104 ,
struct V_194 * V_195 , unsigned V_196 )
{
int V_60 ;
for ( V_60 = 0 ; V_60 < V_196 ; V_60 ++ )
if ( V_195 [ V_60 ] . type == V_197 )
F_131 ( V_195 [ V_60 ] . V_198 . V_199 . V_199 ) ;
F_131 ( V_195 ) ;
}
static int F_132 ( struct V_194 * * V_195 , unsigned * V_200 ,
unsigned * V_196 , unsigned V_201 )
{
unsigned V_202 = * V_200 ;
unsigned V_203 = * V_196 + V_201 ;
struct V_194 * V_204 ;
if ( V_202 >= V_203 )
return 0 ;
V_204 = F_133 ( * V_195 , sizeof( * V_204 ) * V_203 , V_167 ) ;
if ( ! V_204 )
return - V_168 ;
memset ( V_204 + V_202 , 0 , ( V_203 - V_202 ) * sizeof( * V_204 ) ) ;
* V_195 = V_204 ;
* V_200 = V_203 ;
return 0 ;
}
static int F_134 ( struct V_194 * * V_195 , unsigned * V_200 ,
unsigned * V_196 , const char * V_205 ,
const char * V_206 )
{
if ( * V_196 == * V_200 )
return - V_207 ;
( * V_195 ) [ * V_196 ] . type = V_208 ;
( * V_195 ) [ * V_196 ] . V_198 . V_209 . V_205 = V_205 ;
( * V_195 ) [ * V_196 ] . V_198 . V_209 . V_206 = V_206 ;
( * V_196 ) ++ ;
return 0 ;
}
static int F_135 ( struct V_194 * * V_195 ,
unsigned * V_200 ,
unsigned * V_196 , const char * V_205 ,
unsigned long * V_199 , unsigned V_210 )
{
unsigned long * V_211 ;
if ( * V_196 == * V_200 )
return - V_207 ;
V_211 = F_136 ( V_199 , V_210 * sizeof( * V_211 ) ,
V_167 ) ;
if ( ! V_211 )
return - V_168 ;
( * V_195 ) [ * V_196 ] . type = V_197 ;
( * V_195 ) [ * V_196 ] . V_198 . V_199 . V_212 = V_205 ;
( * V_195 ) [ * V_196 ] . V_198 . V_199 . V_199 = V_211 ;
( * V_195 ) [ * V_196 ] . V_198 . V_199 . V_210 = V_210 ;
( * V_196 ) ++ ;
return 0 ;
}
static int F_137 ( int V_213 , int V_32 , unsigned long * V_214 )
{
int V_98 = 0 ;
if ( V_215 [ V_213 ] . V_216 == NULL )
* V_214 = V_215 [ V_213 ] . V_214 ;
else {
if ( V_32 < V_215 [ V_213 ] . V_217 ) {
* V_214 = V_215 [ V_213 ] . V_214 |
V_215 [ V_213 ] . V_216 [ V_32 ] ;
}
}
return V_98 ;
}
static const char * F_138 ( struct V_103 * V_104 , const char * V_218 )
{
int V_60 , V_219 ;
struct V_57 * V_58 = F_49 ( V_104 ) ;
if ( sscanf ( ( char * ) V_218 , L_56 , & V_219 ) == 1 )
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_187 ; V_60 ++ )
if ( V_58 -> V_67 -> V_185 [ V_60 ] . V_220 == V_219 )
return V_58 -> V_67 -> V_185 [ V_60 ] . V_176 ;
return NULL ;
}
static bool F_139 ( struct V_159 * V_160 ,
unsigned long * V_199 )
{
bool V_221 = 0 ;
unsigned long V_76 = 0 ;
int V_60 , V_32 , V_98 ;
for ( V_60 = 0 ; V_60 < F_120 ( V_215 ) ; V_60 ++ ) {
V_98 = F_106 ( V_160 ,
V_215 [ V_60 ] . V_222 , & V_32 ) ;
if ( V_98 != - V_101 ) {
if ( F_137 ( V_60 , V_32 , & V_76 ) == 0 ) {
* V_199 |= V_76 ;
V_221 = 1 ;
}
}
}
return V_221 ;
}
int F_140 ( struct V_103 * V_104 ,
struct V_159 * V_160 ,
struct V_194 * * V_195 ,
unsigned * V_200 ,
unsigned * V_196 )
{
int V_98 ;
const char * V_206 = NULL ;
unsigned long V_199 = 0 ;
bool V_221 = 0 ;
unsigned V_201 = 0 ;
struct V_222 * V_223 ;
const char * V_205 , * V_224 ;
struct V_159 * V_225 ;
V_98 = F_141 ( V_160 , L_57 , & V_206 ) ;
if ( V_98 >= 0 )
V_201 = 1 ;
V_221 = F_139 ( V_160 , & V_199 ) ;
V_225 = F_142 ( V_160 , L_58 , 0 ) ;
if ( V_225 )
V_221 |= F_139 ( V_225 , & V_199 ) ;
V_98 = F_143 ( V_160 , L_59 ) ;
if ( V_98 < 0 )
goto exit;
if ( V_221 )
V_201 ++ ;
V_201 *= V_98 ;
V_98 = F_132 ( V_195 , V_200 , V_196 , V_201 ) ;
if ( V_98 < 0 )
goto exit;
F_144 (np, L_59 , prop, group) {
if ( V_206 ) {
V_98 = F_134 ( V_195 , V_200 , V_196 ,
V_205 , V_206 ) ;
if ( V_98 < 0 )
goto exit;
}
if ( V_221 ) {
V_224 = F_138 ( V_104 , V_205 ) ;
V_98 = F_135 ( V_195 , V_200 , V_196 ,
V_224 , & V_199 , 1 ) ;
if ( V_98 < 0 )
goto exit;
}
}
exit:
return V_98 ;
}
int F_145 ( struct V_103 * V_104 ,
struct V_159 * V_225 ,
struct V_194 * * V_195 , unsigned * V_196 )
{
unsigned V_200 ;
struct V_159 * V_160 ;
int V_98 ;
V_200 = 0 ;
* V_195 = NULL ;
* V_196 = 0 ;
F_146 (np_config, np) {
V_98 = F_140 ( V_104 , V_160 , V_195 ,
& V_200 , V_196 ) ;
if ( V_98 < 0 ) {
F_130 ( V_104 , * V_195 , * V_196 ) ;
return V_98 ;
}
}
return 0 ;
}
static int F_147 ( struct V_103 * V_104 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
return V_58 -> V_67 -> V_226 ;
}
static const char * F_148 ( struct V_103 * V_104 ,
unsigned V_206 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
return V_58 -> V_67 -> V_227 [ V_206 ] . V_176 ;
}
static int F_149 ( struct V_103 * V_104 ,
unsigned V_206 ,
const char * const * * V_184 ,
unsigned * const V_228 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
* V_184 = V_58 -> V_67 -> V_227 [ V_206 ] . V_184 ;
* V_228 = V_58 -> V_67 -> V_227 [ V_206 ] . V_182 ;
return 0 ;
}
static int F_150 ( struct V_103 * V_104 , unsigned V_206 ,
unsigned V_205 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
const struct V_229 * V_230 ;
static unsigned int V_15 [ V_91 ] ;
unsigned long V_97 ;
bool V_34 ;
int V_98 = - V_101 ;
int V_60 ;
V_230 = & V_58 -> V_67 -> V_184 [ V_205 ] ;
if ( V_230 -> V_231 < 0 )
return - V_101 ;
F_17 ( V_58 -> V_53 , L_60 , V_230 -> V_176 , V_230 -> V_187 ) ;
V_34 = ( ( V_230 -> V_231 & V_81 ) == V_81 ) ;
if ( V_34 ) {
F_38 ( & V_99 , V_97 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_60 = 0 ; V_60 < V_230 -> V_187 ; V_60 ++ )
V_15 [ V_230 -> V_185 [ V_60 ] / V_100 ] &= ~ F_7 ( V_230 -> V_185 [ V_60 ] ) ;
F_33 ( V_15 ) ;
}
for ( V_60 = 0 ; V_60 < V_230 -> V_187 ; V_60 ++ ) {
struct V_188 * V_190 ;
struct V_1 * V_2 ;
struct V_137 * V_45 ;
unsigned V_5 ;
V_190 = F_128 ( V_104 , V_230 -> V_185 [ V_60 ] ) ;
if ( ! V_190 ) {
F_20 ( V_58 -> V_53 ,
L_61 ,
V_230 -> V_185 [ V_60 ] , V_230 -> V_176 , V_60 ) ;
goto V_232;
}
if ( ! V_190 -> V_193 ) {
F_20 ( V_58 -> V_53 , L_62 ,
V_230 -> V_185 [ V_60 ] , V_230 -> V_176 , V_60 ) ;
goto V_232;
}
V_45 = V_190 -> V_193 ;
V_2 = F_81 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_63 , V_230 -> V_185 [ V_60 ] , V_230 -> V_231 ) ;
F_34 ( V_2 -> V_94 ) ;
V_5 = V_230 -> V_185 [ V_60 ] % V_100 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_230 -> V_231 & V_81 ) , V_34 ) ;
F_36 ( V_2 -> V_94 ) ;
if ( ( V_230 -> V_231 & V_81 ) == V_81 )
F_19 ( V_58 , V_230 -> V_185 [ V_60 ] ,
V_230 -> V_231 >> V_233 ) ;
}
V_98 = 0 ;
V_232:
if ( V_34 ) {
F_35 ( V_15 ) ;
F_41 ( & V_99 , V_97 ) ;
}
return V_98 ;
}
static void F_151 ( struct V_103 * V_104 ,
unsigned V_206 , unsigned V_205 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
const struct V_229 * V_230 ;
V_230 = & V_58 -> V_67 -> V_184 [ V_205 ] ;
if ( V_230 -> V_231 < 0 )
return;
F_17 ( V_58 -> V_53 , L_64 , V_230 -> V_176 , V_230 -> V_187 ) ;
}
static int F_152 ( struct V_103 * V_104 ,
struct V_188 * V_190 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
struct V_1 * V_2 ;
struct V_137 * V_45 ;
unsigned V_5 ;
if ( ! V_190 ) {
F_20 ( V_58 -> V_53 , L_65 ) ;
return - V_101 ;
}
if ( ! V_190 -> V_193 ) {
F_20 ( V_58 -> V_53 , L_66 ) ;
return - V_101 ;
}
V_45 = V_190 -> V_193 ;
V_2 = F_81 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_58 -> V_53 , L_67 , V_3 ) ;
F_34 ( V_2 -> V_94 ) ;
V_5 = V_3 % V_100 ;
F_1 ( V_2 , V_5 , V_80 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static void F_153 ( struct V_103 * V_104 ,
struct V_188 * V_190 ,
unsigned V_3 )
{
struct V_57 * V_58 = F_49 ( V_104 ) ;
F_17 ( V_58 -> V_53 , L_68 , V_3 ) ;
}
static int F_154 ( struct V_103 * V_104 , unsigned V_70 ,
unsigned long * V_214 )
{
return - V_101 ;
}
static int F_155 ( struct V_103 * V_104 , unsigned V_70 ,
unsigned long V_214 )
{
static const char * V_82 [] = {
[ V_22 ] = L_11 ,
[ V_24 ] = L_12 ,
[ V_26 ] = L_13 ,
[ 3 ] = L_14
} ;
static const char * V_83 [] = {
[ V_84 ] = L_15 ,
[ V_17 ] = L_16 ,
} ;
struct V_57 * V_58 = F_49 ( V_104 ) ;
struct V_1 * V_2 ;
struct V_188 * V_190 ;
struct V_137 * V_45 ;
unsigned V_5 ;
T_5 V_76 = ( T_5 ) V_214 ;
int V_19 = F_24 ( V_76 ) ;
int V_15 = F_26 ( V_76 ) ;
int V_86 = F_27 ( V_76 ) ;
int V_32 = F_28 ( V_76 ) ;
bool V_28 = F_32 ( V_76 ) ;
bool V_234 = F_156 ( V_76 ) ;
bool V_77 = F_157 ( V_76 ) ;
V_190 = F_128 ( V_104 , V_70 ) ;
if ( ! V_190 ) {
F_20 ( V_58 -> V_53 , L_69 , V_70 ) ;
return - V_101 ;
}
if ( ! V_190 -> V_193 ) {
F_20 ( V_58 -> V_53 , L_70 ,
V_70 ) ;
return - V_101 ;
}
V_45 = V_190 -> V_193 ;
V_2 = F_81 ( V_45 , struct V_1 , V_45 ) ;
if ( V_77 ) {
int V_87 = F_29 ( V_76 ) ;
int V_88 = F_30 ( V_76 ) ;
int V_89 = F_31 ( V_76 ) ;
V_234 = true ;
if ( V_87 )
V_19 = V_87 - 1 ;
if ( V_88 )
V_86 = V_88 - 1 ;
if ( V_89 )
V_32 = V_89 - 1 ;
F_17 ( V_2 -> V_45 . V_53 , L_23 ,
V_70 ,
V_87 ? V_82 [ V_19 ] : L_24 ,
V_88 ? ( V_86 ? L_25 : L_19 ) : L_24 ,
V_89 ? ( V_32 ? L_20 : L_21 ) : L_24 ) ;
}
F_17 ( V_2 -> V_45 . V_53 , L_71 ,
V_70 , V_76 , V_82 [ V_19 ] , V_83 [ V_15 ] ,
V_86 ? L_18 : L_19 ,
V_86 ? ( V_32 ? L_20 : L_21 ) : L_22 ,
V_28 ? L_72 : L_73 ) ;
F_34 ( V_2 -> V_94 ) ;
V_5 = V_70 % V_100 ;
if ( V_234 )
F_1 ( V_2 , V_5 , V_80 ) ;
if ( V_86 )
F_11 ( V_2 , V_5 , V_32 ) ;
else {
F_9 ( V_2 , V_5 ) ;
F_5 ( V_2 , V_5 , V_19 ) ;
}
F_6 ( V_2 , V_5 , V_28 ) ;
F_4 ( V_2 , V_5 , V_15 ) ;
F_36 ( V_2 -> V_94 ) ;
return 0 ;
}
static int F_158 ( struct V_155 * V_235 , T_8 V_236 )
{
struct V_57 * V_58 ;
V_58 = F_159 ( V_235 ) ;
if ( ! V_58 )
return - V_101 ;
return F_160 ( V_58 -> V_237 ) ;
}
static int F_161 ( struct V_155 * V_235 )
{
struct V_57 * V_58 ;
V_58 = F_159 ( V_235 ) ;
if ( ! V_58 )
return - V_101 ;
return F_162 ( V_58 -> V_237 ) ;
}
static int F_163 ( struct V_155 * V_235 )
{
const struct V_238 * V_239 = F_164 ( V_235 ) ;
struct V_159 * V_160 = V_235 -> V_53 . V_161 ;
struct V_159 * V_240 ;
struct V_57 * V_58 ;
struct V_162 * V_163 ;
unsigned int V_241 = 0 ;
int V_60 ;
V_58 = F_104 ( & V_235 -> V_53 , sizeof( * V_58 ) , V_167 ) ;
if ( ! V_58 )
return - V_168 ;
if ( V_239 )
V_241 = V_239 -> V_242 ;
else if ( V_160 ) {
const struct V_243 * V_244 ;
V_244 = F_165 ( V_245 , & V_235 -> V_53 ) ;
if ( ! V_244 )
return - V_166 ;
V_241 = ( unsigned int ) V_244 -> V_198 ;
}
if ( V_241 == V_246 )
F_166 ( & V_58 -> V_67 ) ;
if ( V_241 == V_247 )
F_167 ( & V_58 -> V_67 ) ;
if ( V_241 == V_248 )
F_168 ( & V_58 -> V_67 ) ;
if ( V_160 ) {
V_240 = F_142 ( V_160 , L_74 , 0 ) ;
if ( V_240 )
V_58 -> V_65 = F_169 ( V_240 , 0 ) ;
}
V_163 = F_107 ( V_235 , V_173 , 0 ) ;
if ( V_163 )
V_58 -> V_65 = F_170 ( & V_235 -> V_53 , V_163 -> V_249 ,
F_171 ( V_163 ) ) ;
if ( ! V_58 -> V_65 ) {
if ( V_241 == V_246 ) {
F_124 ( & V_235 -> V_53 ,
L_75
L_76 ) ;
} else {
F_20 ( & V_235 -> V_53 , L_77 ) ;
return - V_101 ;
}
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_189 ; V_60 ++ ) {
if ( ! V_92 [ V_58 -> V_67 -> V_191 [ V_60 ] . V_170 ] ) {
F_21 ( & V_235 -> V_53 , L_78 , V_60 ) ;
return - V_250 ;
}
V_58 -> V_67 -> V_191 [ V_60 ] . V_193 = & V_92 [ V_58 -> V_67 -> V_191 [ V_60 ] . V_170 ] -> V_45 ;
}
V_251 . V_185 = V_58 -> V_67 -> V_185 ;
V_251 . V_187 = V_58 -> V_67 -> V_187 ;
V_58 -> V_53 = & V_235 -> V_53 ;
V_58 -> V_237 = F_172 ( & V_251 , & V_235 -> V_53 , V_58 ) ;
if ( ! V_58 -> V_237 ) {
F_20 ( & V_235 -> V_53 , L_79 ) ;
return - V_101 ;
}
for ( V_60 = 0 ; V_60 < V_58 -> V_67 -> V_189 ; V_60 ++ )
F_173 ( V_58 -> V_237 , & V_58 -> V_67 -> V_191 [ V_60 ] ) ;
F_121 ( V_235 , V_58 ) ;
F_124 ( & V_235 -> V_53 , L_80 ) ;
return 0 ;
}
static int T_9 F_174 ( void )
{
int V_98 ;
V_98 = F_175 ( & V_252 ) ;
if ( V_98 )
return V_98 ;
return F_175 ( & V_253 ) ;
}
