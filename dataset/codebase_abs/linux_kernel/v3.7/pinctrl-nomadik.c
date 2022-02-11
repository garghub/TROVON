static inline T_1 F_1 ( unsigned int V_1 ) {
return 0 ;
}
static inline void F_2 ( unsigned int V_1 , T_1 V_2 ) {}
static inline void F_3 ( unsigned int V_1 , T_1 V_3 , T_1 V_2 ) {}
static void F_4 ( struct V_4 * V_5 ,
unsigned V_6 , int V_7 )
{
T_1 V_8 = 1 << V_6 ;
T_1 V_9 , V_10 ;
V_9 = F_5 ( V_5 -> V_11 + V_12 ) & ~ V_8 ;
V_10 = F_5 ( V_5 -> V_11 + V_13 ) & ~ V_8 ;
if ( V_7 & V_14 )
V_9 |= V_8 ;
if ( V_7 & V_15 )
V_10 |= V_8 ;
F_6 ( V_9 , V_5 -> V_11 + V_12 ) ;
F_6 ( V_10 , V_5 -> V_11 + V_13 ) ;
}
static void F_7 ( struct V_4 * V_5 ,
unsigned V_6 , enum V_16 V_17 )
{
T_1 V_8 = 1 << V_6 ;
T_1 V_18 ;
V_18 = F_5 ( V_5 -> V_11 + V_19 ) ;
if ( V_17 == V_20 )
V_18 |= V_8 ;
else
V_18 &= ~ V_8 ;
F_6 ( V_18 , V_5 -> V_11 + V_19 ) ;
}
static void F_8 ( struct V_4 * V_5 ,
unsigned V_6 , enum V_21 V_22 )
{
T_1 V_8 = 1 << V_6 ;
T_1 V_23 ;
V_23 = F_5 ( V_5 -> V_11 + V_24 ) ;
if ( V_22 == V_25 ) {
V_23 |= V_8 ;
V_5 -> V_26 &= ~ V_8 ;
} else {
V_23 &= ~ V_8 ;
}
F_6 ( V_23 , V_5 -> V_11 + V_24 ) ;
if ( V_22 == V_27 ) {
V_5 -> V_26 |= V_8 ;
F_6 ( V_8 , V_5 -> V_11 + V_28 ) ;
} else if ( V_22 == V_29 ) {
V_5 -> V_26 &= ~ V_8 ;
F_6 ( V_8 , V_5 -> V_11 + V_30 ) ;
}
}
static void F_9 ( struct V_4 * V_5 ,
unsigned V_6 , bool V_31 )
{
T_1 V_8 = F_10 ( V_6 ) ;
bool V_32 = V_5 -> V_31 & V_8 ;
if ( V_31 == V_32 )
return;
if ( V_31 )
V_5 -> V_31 |= V_8 ;
else
V_5 -> V_31 &= ~ V_8 ;
F_11 ( V_5 -> V_31 ,
V_5 -> V_11 + V_33 ) ;
}
static void F_12 ( struct V_4 * V_5 ,
unsigned V_6 )
{
F_6 ( 1 << V_6 , V_5 -> V_11 + V_34 ) ;
}
static void F_13 ( struct V_4 * V_5 ,
unsigned V_6 , int V_35 )
{
if ( V_35 )
F_6 ( 1 << V_6 , V_5 -> V_11 + V_28 ) ;
else
F_6 ( 1 << V_6 , V_5 -> V_11 + V_30 ) ;
}
static void F_14 ( struct V_4 * V_5 ,
unsigned V_6 , int V_35 )
{
F_6 ( 1 << V_6 , V_5 -> V_11 + V_36 ) ;
F_13 ( V_5 , V_6 , V_35 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
unsigned V_6 , int V_7 ,
bool V_37 )
{
T_1 V_38 = V_5 -> V_38 ;
T_1 V_39 = V_5 -> V_39 ;
if ( V_37 && V_5 -> V_40 ) {
T_1 V_8 = F_10 ( V_6 ) ;
F_6 ( V_38 & ~ V_8 , V_5 -> V_11 + V_41 ) ;
F_6 ( V_39 & ~ V_8 , V_5 -> V_11 + V_42 ) ;
V_5 -> V_40 ( true ) ;
}
F_4 ( V_5 , V_6 , V_7 ) ;
if ( V_37 && V_5 -> V_40 ) {
V_5 -> V_40 ( false ) ;
F_6 ( V_38 , V_5 -> V_11 + V_41 ) ;
F_6 ( V_39 , V_5 -> V_11 + V_42 ) ;
}
}
static void
F_16 ( struct V_4 * V_5 , unsigned V_6 )
{
T_1 V_43 = V_5 -> V_44 & F_10 ( V_6 ) ;
T_1 V_45 = V_5 -> V_46 & F_10 ( V_6 ) ;
int V_47 = V_5 -> V_48 . V_49 + V_6 ;
int V_50 = F_17 ( V_47 ) ;
struct V_51 * V_52 = F_18 ( V_50 ) ;
if ( ! V_45 && ! V_43 )
return;
if ( ! V_52 || ! F_19 ( V_52 ) )
return;
if ( V_45 ) {
V_5 -> V_46 &= ~ F_10 ( V_6 ) ;
F_11 ( V_5 -> V_46 ,
V_5 -> V_11 + V_53 ) ;
}
if ( V_43 ) {
V_5 -> V_44 &= ~ F_10 ( V_6 ) ;
F_11 ( V_5 -> V_44 ,
V_5 -> V_11 + V_54 ) ;
}
F_20 ( V_5 -> V_48 . V_55 , L_1 , V_47 ) ;
}
static void F_21 ( struct V_56 * V_57 ,
unsigned V_6 , unsigned V_58 )
{
int V_59 ;
T_2 V_1 ;
T_3 V_8 ;
T_3 V_60 ;
const struct V_61 * V_62 ;
const T_2 * V_63 ;
if ( V_58 > V_64 ) {
F_22 ( V_57 -> V_55 , L_2 ,
V_58 ) ;
return;
}
for ( V_59 = 0 ; V_59 < V_57 -> V_65 -> V_66 ; V_59 ++ ) {
if ( V_57 -> V_65 -> V_67 [ V_59 ] . V_68 == V_6 )
break;
}
if ( V_59 == V_57 -> V_65 -> V_66 ) {
F_20 ( V_57 -> V_55 , L_3 ,
V_6 ) ;
return;
}
V_62 = V_57 -> V_65 -> V_67 + V_59 ;
V_63 = V_57 -> V_65 -> V_69 ;
if ( ! V_58 ) {
for ( V_59 = 0 ; V_59 < V_64 ; V_59 ++ ) {
if ( V_62 -> V_70 [ V_59 ] . V_71 == true ) {
V_1 = V_63 [ V_62 -> V_70 [ V_59 ] . V_72 ] ;
V_8 = V_62 -> V_70 [ V_59 ] . V_73 ;
if ( F_1 ( V_1 ) & F_10 ( V_8 ) ) {
F_3 ( V_1 , F_10 ( V_8 ) , 0 ) ;
F_20 ( V_57 -> V_55 ,
L_4 ,
V_6 , V_59 + 1 ) ;
}
}
}
return;
}
V_60 = V_58 - 1 ;
if ( V_62 -> V_70 [ V_60 ] . V_71 == false ) {
F_23 ( V_57 -> V_55 ,
L_5 ,
V_6 , V_58 ) ;
return;
}
for ( V_59 = 0 ; V_59 < V_64 ; V_59 ++ ) {
if ( V_59 == V_60 )
continue;
if ( V_62 -> V_70 [ V_59 ] . V_71 == true ) {
V_1 = V_63 [ V_62 -> V_70 [ V_59 ] . V_72 ] ;
V_8 = V_62 -> V_70 [ V_59 ] . V_73 ;
if ( F_1 ( V_1 ) & F_10 ( V_8 ) ) {
F_3 ( V_1 , F_10 ( V_8 ) , 0 ) ;
F_20 ( V_57 -> V_55 ,
L_4 ,
V_6 , V_59 + 1 ) ;
}
}
}
V_1 = V_63 [ V_62 -> V_70 [ V_60 ] . V_72 ] ;
V_8 = V_62 -> V_70 [ V_60 ] . V_73 ;
F_20 ( V_57 -> V_55 , L_6 ,
V_6 , V_60 + 1 ) ;
F_3 ( V_1 , F_10 ( V_8 ) , F_10 ( V_8 ) ) ;
}
static void F_24 ( struct V_4 * V_5 , unsigned V_6 ,
T_4 V_74 , bool V_75 , unsigned int * V_76 )
{
static const char * V_77 [] = {
[ V_78 ] = L_7 ,
[ V_14 ] = L_8 ,
[ V_15 ] = L_9 ,
[ V_79 ] = L_10
} ;
static const char * V_80 [] = {
[ V_25 ] = L_11 ,
[ V_27 ] = L_12 ,
[ V_29 ] = L_13 ,
[ 3 ] = L_14
} ;
static const char * V_81 [] = {
[ V_82 ] = L_15 ,
[ V_20 ] = L_16 ,
} ;
int V_68 = F_25 ( V_74 ) ;
int V_22 = F_26 ( V_74 ) ;
int V_83 = F_27 ( V_74 ) ;
int V_18 = F_28 ( V_74 ) ;
int V_84 = F_29 ( V_74 ) ;
int V_35 = F_30 ( V_74 ) ;
bool V_37 = V_83 == V_79 ;
F_20 ( V_5 -> V_48 . V_55 , L_17 ,
V_68 , V_74 , V_77 [ V_83 ] , V_80 [ V_22 ] , V_81 [ V_18 ] ,
V_84 ? L_18 : L_19 ,
V_84 ? ( V_35 ? L_20 : L_21 ) : L_22 ) ;
if ( V_75 ) {
int V_85 = F_31 ( V_74 ) ;
int V_86 = F_32 ( V_74 ) ;
int V_87 = F_33 ( V_74 ) ;
V_83 = V_78 ;
if ( V_85 )
V_22 = V_85 - 1 ;
if ( V_86 )
V_84 = V_86 - 1 ;
if ( V_87 )
V_35 = V_87 - 1 ;
F_20 ( V_5 -> V_48 . V_55 , L_23 ,
V_68 ,
V_85 ? V_80 [ V_22 ] : L_24 ,
V_86 ? ( V_84 ? L_25 : L_19 ) : L_24 ,
V_87 ? ( V_35 ? L_20 : L_21 ) : L_24 ) ;
}
if ( V_84 )
F_14 ( V_5 , V_6 , V_35 ) ;
else {
F_12 ( V_5 , V_6 ) ;
F_8 ( V_5 , V_6 , V_22 ) ;
}
F_9 ( V_5 , V_6 , F_34 ( V_74 ) ) ;
if ( V_83 != V_78 )
F_16 ( V_5 , V_6 ) ;
if ( V_76 ) {
if ( V_18 == V_20 )
V_76 [ V_5 -> V_88 ] |= F_10 ( V_6 ) ;
else
V_76 [ V_5 -> V_88 ] &= ~ F_10 ( V_6 ) ;
} else
F_7 ( V_5 , V_6 , V_18 ) ;
F_15 ( V_5 , V_6 , V_83 , V_37 ) ;
}
static void F_35 ( unsigned int * V_18 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ ) {
struct V_4 * V_48 = V_90 [ V_59 ] ;
unsigned int V_91 = V_18 [ V_59 ] ;
if ( ! V_48 )
break;
F_36 ( V_48 -> V_92 ) ;
V_18 [ V_59 ] = F_5 ( V_48 -> V_11 + V_19 ) ;
F_6 ( V_91 , V_48 -> V_11 + V_19 ) ;
}
}
static void F_37 ( unsigned int * V_18 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ ) {
struct V_4 * V_48 = V_90 [ V_59 ] ;
if ( ! V_48 )
break;
F_6 ( V_18 [ V_59 ] , V_48 -> V_11 + V_19 ) ;
F_38 ( V_48 -> V_92 ) ;
}
}
static int F_39 ( T_4 * V_93 , int V_94 , bool V_75 )
{
static unsigned int V_18 [ V_89 ] ;
unsigned long V_95 ;
bool V_37 = false ;
int V_96 = 0 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_94 ; V_59 ++ ) {
if ( F_27 ( V_93 [ V_59 ] ) == V_79 ) {
V_37 = true ;
break;
}
}
F_40 ( & V_97 , V_95 ) ;
if ( V_37 ) {
memset ( V_18 , 0xff , sizeof( V_18 ) ) ;
for ( V_59 = 0 ; V_59 < V_94 ; V_59 ++ ) {
int V_68 = F_25 ( V_93 [ V_59 ] ) ;
int V_6 = V_68 % V_98 ;
if ( F_27 ( V_93 [ V_59 ] ) == V_79 )
V_18 [ V_68 / V_98 ] &= ~ F_10 ( V_6 ) ;
}
F_35 ( V_18 ) ;
}
for ( V_59 = 0 ; V_59 < V_94 ; V_59 ++ ) {
struct V_4 * V_5 ;
int V_68 = F_25 ( V_93 [ V_59 ] ) ;
V_5 = V_90 [ V_68 / V_98 ] ;
if ( ! V_5 ) {
V_96 = - V_99 ;
break;
}
F_36 ( V_5 -> V_92 ) ;
F_41 ( & V_5 -> V_100 ) ;
F_24 ( V_5 , V_68 % V_98 ,
V_93 [ V_59 ] , V_75 , V_37 ? V_18 : NULL ) ;
F_42 ( & V_5 -> V_100 ) ;
F_38 ( V_5 -> V_92 ) ;
}
if ( V_37 )
F_37 ( V_18 ) ;
F_43 ( & V_97 , V_95 ) ;
return V_96 ;
}
int F_44 ( T_4 V_74 , bool V_75 )
{
return F_39 ( & V_74 , 1 , V_75 ) ;
}
int F_45 ( T_4 * V_93 , int V_94 )
{
return F_39 ( V_93 , V_94 , false ) ;
}
int F_46 ( T_4 * V_93 , int V_94 )
{
return F_39 ( V_93 , V_94 , true ) ;
}
int F_47 ( int V_47 , enum V_16 V_17 )
{
struct V_4 * V_5 ;
unsigned long V_95 ;
V_5 = V_90 [ V_47 / V_98 ] ;
if ( ! V_5 )
return - V_99 ;
F_36 ( V_5 -> V_92 ) ;
F_40 ( & V_97 , V_95 ) ;
F_41 ( & V_5 -> V_100 ) ;
F_7 ( V_5 , V_47 % V_98 , V_17 ) ;
F_42 ( & V_5 -> V_100 ) ;
F_43 ( & V_97 , V_95 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
int F_48 ( int V_47 , enum V_21 V_22 )
{
struct V_4 * V_5 ;
unsigned long V_95 ;
V_5 = V_90 [ V_47 / V_98 ] ;
if ( ! V_5 )
return - V_99 ;
F_36 ( V_5 -> V_92 ) ;
F_40 ( & V_5 -> V_100 , V_95 ) ;
F_8 ( V_5 , V_47 % V_98 , V_22 ) ;
F_43 ( & V_5 -> V_100 , V_95 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
int F_49 ( int V_47 , int V_7 )
{
struct V_4 * V_5 ;
unsigned long V_95 ;
V_5 = V_90 [ V_47 / V_98 ] ;
if ( ! V_5 )
return - V_99 ;
F_36 ( V_5 -> V_92 ) ;
F_40 ( & V_5 -> V_100 , V_95 ) ;
F_4 ( V_5 , V_47 % V_98 , V_7 ) ;
F_43 ( & V_5 -> V_100 , V_95 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
int F_50 ( int V_47 )
{
struct V_4 * V_5 ;
T_1 V_9 , V_10 , V_8 ;
V_5 = V_90 [ V_47 / V_98 ] ;
if ( ! V_5 )
return - V_99 ;
V_8 = 1 << ( V_47 % V_98 ) ;
F_36 ( V_5 -> V_92 ) ;
V_9 = F_5 ( V_5 -> V_11 + V_12 ) & V_8 ;
V_10 = F_5 ( V_5 -> V_11 + V_13 ) & V_8 ;
F_38 ( V_5 -> V_92 ) ;
return ( V_9 ? V_14 : 0 ) | ( V_10 ? V_15 : 0 ) ;
}
static inline int F_51 ( int V_47 )
{
return 1 << ( V_47 % V_98 ) ;
}
static void F_52 ( struct V_51 * V_52 )
{
struct V_4 * V_5 ;
V_5 = F_53 ( V_52 ) ;
if ( ! V_5 )
return;
F_36 ( V_5 -> V_92 ) ;
F_6 ( F_51 ( V_52 -> V_101 ) , V_5 -> V_11 + V_102 ) ;
F_38 ( V_5 -> V_92 ) ;
}
static void F_54 ( struct V_4 * V_5 ,
int V_47 , enum V_103 V_104 ,
bool V_105 )
{
T_1 V_106 = F_51 ( V_47 ) ;
T_1 * V_107 ;
T_1 * V_108 ;
T_1 V_109 ;
T_1 V_110 ;
if ( V_104 == V_111 ) {
V_109 = V_53 ;
V_110 = V_54 ;
V_107 = & V_5 -> V_46 ;
V_108 = & V_5 -> V_44 ;
} else {
V_109 = V_41 ;
V_110 = V_42 ;
V_107 = & V_5 -> V_38 ;
V_108 = & V_5 -> V_39 ;
}
if ( V_5 -> V_112 & V_106 ) {
if ( V_105 )
* V_107 |= V_106 ;
else
* V_107 &= ~ V_106 ;
F_6 ( * V_107 , V_5 -> V_11 + V_109 ) ;
}
if ( V_5 -> V_113 & V_106 ) {
if ( V_105 )
* V_108 |= V_106 ;
else
* V_108 &= ~ V_106 ;
F_6 ( * V_108 , V_5 -> V_11 + V_110 ) ;
}
}
static void F_55 ( struct V_4 * V_5 ,
int V_47 , bool V_114 )
{
if ( V_5 -> V_115 && V_114 ) {
F_7 ( V_5 , V_47 % V_98 ,
V_116 ) ;
}
F_54 ( V_5 , V_47 , V_117 , V_114 ) ;
}
static int F_56 ( struct V_51 * V_52 , bool V_105 )
{
struct V_4 * V_5 ;
unsigned long V_95 ;
T_1 V_106 ;
V_5 = F_53 ( V_52 ) ;
V_106 = F_51 ( V_52 -> V_101 ) ;
if ( ! V_5 )
return - V_99 ;
F_36 ( V_5 -> V_92 ) ;
F_40 ( & V_97 , V_95 ) ;
F_41 ( & V_5 -> V_100 ) ;
F_54 ( V_5 , V_52 -> V_101 , V_111 , V_105 ) ;
if ( ! ( V_5 -> V_118 & V_106 ) )
F_55 ( V_5 , V_52 -> V_101 , V_105 ) ;
F_42 ( & V_5 -> V_100 ) ;
F_43 ( & V_97 , V_95 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
static void F_57 ( struct V_51 * V_52 )
{
F_56 ( V_52 , false ) ;
}
static void F_58 ( struct V_51 * V_52 )
{
F_56 ( V_52 , true ) ;
}
static int F_59 ( struct V_51 * V_52 , unsigned int V_114 )
{
struct V_4 * V_5 ;
unsigned long V_95 ;
T_1 V_106 ;
V_5 = F_53 ( V_52 ) ;
if ( ! V_5 )
return - V_99 ;
V_106 = F_51 ( V_52 -> V_101 ) ;
F_36 ( V_5 -> V_92 ) ;
F_40 ( & V_97 , V_95 ) ;
F_41 ( & V_5 -> V_100 ) ;
if ( F_19 ( V_52 ) )
F_55 ( V_5 , V_52 -> V_101 , V_114 ) ;
if ( V_114 )
V_5 -> V_118 |= V_106 ;
else
V_5 -> V_118 &= ~ V_106 ;
F_42 ( & V_5 -> V_100 ) ;
F_43 ( & V_97 , V_95 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
static int F_60 ( struct V_51 * V_52 , unsigned int type )
{
bool V_32 = ! F_19 ( V_52 ) ;
bool V_119 = F_61 ( V_52 ) ;
struct V_4 * V_5 ;
unsigned long V_95 ;
T_1 V_106 ;
V_5 = F_53 ( V_52 ) ;
V_106 = F_51 ( V_52 -> V_101 ) ;
if ( ! V_5 )
return - V_99 ;
if ( type & V_120 )
return - V_99 ;
if ( type & V_121 )
return - V_99 ;
F_36 ( V_5 -> V_92 ) ;
F_40 ( & V_5 -> V_100 , V_95 ) ;
if ( V_32 )
F_54 ( V_5 , V_52 -> V_101 , V_111 , false ) ;
if ( V_32 || V_119 )
F_54 ( V_5 , V_52 -> V_101 , V_117 , false ) ;
V_5 -> V_112 &= ~ V_106 ;
if ( type & V_122 )
V_5 -> V_112 |= V_106 ;
V_5 -> V_113 &= ~ V_106 ;
if ( type & V_123 )
V_5 -> V_113 |= V_106 ;
if ( V_32 )
F_54 ( V_5 , V_52 -> V_101 , V_111 , true ) ;
if ( V_32 || V_119 )
F_54 ( V_5 , V_52 -> V_101 , V_117 , true ) ;
F_43 ( & V_5 -> V_100 , V_95 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
static unsigned int F_62 ( struct V_51 * V_52 )
{
struct V_4 * V_5 = F_53 ( V_52 ) ;
F_36 ( V_5 -> V_92 ) ;
F_58 ( V_52 ) ;
return 0 ;
}
static void F_63 ( struct V_51 * V_52 )
{
struct V_4 * V_5 = F_53 ( V_52 ) ;
F_57 ( V_52 ) ;
F_38 ( V_5 -> V_92 ) ;
}
static void F_64 ( unsigned int V_50 , struct V_124 * V_125 ,
T_1 V_126 )
{
struct V_4 * V_5 ;
struct V_127 * V_128 = F_65 ( V_50 ) ;
F_66 ( V_128 , V_125 ) ;
V_5 = F_67 ( V_50 ) ;
while ( V_126 ) {
int V_8 = F_68 ( V_126 ) ;
F_69 ( F_70 ( V_5 -> V_129 , V_8 ) ) ;
V_126 &= ~ F_10 ( V_8 ) ;
}
F_71 ( V_128 , V_125 ) ;
}
static void F_72 ( unsigned int V_50 , struct V_124 * V_125 )
{
struct V_4 * V_5 = F_67 ( V_50 ) ;
T_1 V_126 ;
F_36 ( V_5 -> V_92 ) ;
V_126 = F_5 ( V_5 -> V_11 + V_130 ) ;
F_38 ( V_5 -> V_92 ) ;
F_64 ( V_50 , V_125 , V_126 ) ;
}
static void F_73 ( unsigned int V_50 ,
struct V_124 * V_125 )
{
struct V_4 * V_5 = F_67 ( V_50 ) ;
T_1 V_126 = V_5 -> V_131 ( V_5 -> V_88 ) ;
F_64 ( V_50 , V_125 , V_126 ) ;
}
static int F_74 ( struct V_4 * V_5 )
{
F_75 ( V_5 -> V_132 , F_72 ) ;
F_76 ( V_5 -> V_132 , V_5 ) ;
if ( V_5 -> V_133 >= 0 ) {
F_75 ( V_5 -> V_133 ,
F_73 ) ;
F_76 ( V_5 -> V_133 , V_5 ) ;
}
return 0 ;
}
static int F_77 ( struct V_134 * V_48 , unsigned V_6 )
{
int V_47 = V_48 -> V_49 + V_6 ;
return F_78 ( V_47 ) ;
}
static void F_79 ( struct V_134 * V_48 , unsigned V_6 )
{
int V_47 = V_48 -> V_49 + V_6 ;
F_80 ( V_47 ) ;
}
static int F_81 ( struct V_134 * V_48 , unsigned V_6 )
{
struct V_4 * V_5 =
F_82 ( V_48 , struct V_4 , V_48 ) ;
F_36 ( V_5 -> V_92 ) ;
F_6 ( 1 << V_6 , V_5 -> V_11 + V_34 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
static int F_83 ( struct V_134 * V_48 , unsigned V_6 )
{
struct V_4 * V_5 =
F_82 ( V_48 , struct V_4 , V_48 ) ;
T_1 V_8 = 1 << V_6 ;
int V_2 ;
F_36 ( V_5 -> V_92 ) ;
V_2 = ( F_5 ( V_5 -> V_11 + V_135 ) & V_8 ) != 0 ;
F_38 ( V_5 -> V_92 ) ;
return V_2 ;
}
static void F_84 ( struct V_134 * V_48 , unsigned V_6 ,
int V_35 )
{
struct V_4 * V_5 =
F_82 ( V_48 , struct V_4 , V_48 ) ;
F_36 ( V_5 -> V_92 ) ;
F_13 ( V_5 , V_6 , V_35 ) ;
F_38 ( V_5 -> V_92 ) ;
}
static int F_85 ( struct V_134 * V_48 , unsigned V_6 ,
int V_35 )
{
struct V_4 * V_5 =
F_82 ( V_48 , struct V_4 , V_48 ) ;
F_36 ( V_5 -> V_92 ) ;
F_14 ( V_5 , V_6 , V_35 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
static int F_86 ( struct V_134 * V_48 , unsigned V_6 )
{
struct V_4 * V_5 =
F_82 ( V_48 , struct V_4 , V_48 ) ;
return F_87 ( V_5 -> V_129 , V_6 ) ;
}
static void F_88 ( struct V_136 * V_137 , struct V_134 * V_48 ,
unsigned V_6 , unsigned V_47 )
{
const char * V_138 = F_89 ( V_48 , V_6 ) ;
struct V_4 * V_5 =
F_82 ( V_48 , struct V_4 , V_48 ) ;
int V_17 ;
bool V_139 ;
bool V_22 ;
T_1 V_8 = 1 << V_6 ;
const char * V_140 [] = {
[ V_78 ] = L_26 ,
[ V_14 ] = L_27 ,
[ V_15 ] = L_28 ,
[ V_79 ] = L_29 ,
} ;
F_36 ( V_5 -> V_92 ) ;
V_139 = ! ! ( F_5 ( V_5 -> V_11 + V_141 ) & V_8 ) ;
V_22 = ! ( F_5 ( V_5 -> V_11 + V_24 ) & V_8 ) ;
V_17 = F_50 ( V_47 ) ;
F_90 ( V_137 , L_30 ,
V_47 , V_138 ? : L_31 ,
V_139 ? L_32 : L_33 ,
V_48 -> V_142
? ( V_48 -> V_142 ( V_48 , V_6 ) ? L_34 : L_35 )
: L_36 ,
( V_17 < 0 ) ? L_37 : V_140 [ V_17 ] ,
V_22 ? L_38 : L_11 ) ;
if ( V_138 && ! V_139 ) {
int V_50 = F_91 ( V_47 ) ;
struct V_124 * V_125 = F_92 ( V_50 ) ;
if ( V_50 >= 0 && V_125 -> V_143 ) {
char * V_144 ;
T_1 V_106 = F_51 ( V_47 ) ;
if ( V_5 -> V_112 & V_106 )
V_144 = L_39 ;
else if ( V_5 -> V_113 & V_106 )
V_144 = L_40 ;
else
V_144 = L_41 ;
F_90 ( V_137 , L_42 ,
V_50 , V_144 ,
F_61 ( & V_125 -> V_51 )
? L_43 : L_22 ) ;
}
}
F_38 ( V_5 -> V_92 ) ;
}
static void F_93 ( struct V_136 * V_137 , struct V_134 * V_48 )
{
unsigned V_59 ;
unsigned V_47 = V_48 -> V_49 ;
for ( V_59 = 0 ; V_59 < V_48 -> V_145 ; V_59 ++ , V_47 ++ ) {
F_88 ( V_137 , V_48 , V_59 , V_47 ) ;
F_90 ( V_137 , L_44 ) ;
}
}
static inline void F_88 ( struct V_136 * V_137 ,
struct V_134 * V_48 ,
unsigned V_6 , unsigned V_47 )
{
}
void F_94 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ ) {
struct V_4 * V_48 = V_90 [ V_59 ] ;
if ( ! V_48 )
continue;
F_36 ( V_48 -> V_92 ) ;
}
}
void F_95 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ ) {
struct V_4 * V_48 = V_90 [ V_59 ] ;
if ( ! V_48 )
continue;
F_38 ( V_48 -> V_92 ) ;
}
}
void F_96 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ ) {
struct V_4 * V_48 = V_90 [ V_59 ] ;
if ( ! V_48 )
break;
F_36 ( V_48 -> V_92 ) ;
F_6 ( V_48 -> V_38 & V_48 -> V_118 ,
V_48 -> V_11 + V_41 ) ;
F_6 ( V_48 -> V_39 & V_48 -> V_118 ,
V_48 -> V_11 + V_42 ) ;
F_38 ( V_48 -> V_92 ) ;
}
}
void F_97 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_89 ; V_59 ++ ) {
struct V_4 * V_48 = V_90 [ V_59 ] ;
if ( ! V_48 )
break;
F_36 ( V_48 -> V_92 ) ;
F_6 ( V_48 -> V_38 , V_48 -> V_11 + V_41 ) ;
F_6 ( V_48 -> V_39 , V_48 -> V_11 + V_42 ) ;
F_38 ( V_48 -> V_92 ) ;
}
}
void F_98 ( int V_146 , T_1 * V_26 )
{
if ( V_146 < V_89 ) {
struct V_4 * V_48 = V_90 [ V_146 ] ;
if ( ! V_48 )
return;
* V_26 = V_48 -> V_26 ;
}
}
int F_99 ( struct V_147 * V_52 , unsigned int V_50 ,
T_5 V_101 )
{
struct V_4 * V_5 = V_52 -> V_148 ;
if ( ! V_5 )
return - V_99 ;
F_100 ( V_50 , & V_149 , V_150 ) ;
F_101 ( V_50 , V_151 ) ;
F_102 ( V_50 , V_5 ) ;
F_103 ( V_50 , V_123 ) ;
return 0 ;
}
static int T_6 F_104 ( struct V_152 * V_55 )
{
struct V_153 * V_154 = V_55 -> V_55 . V_155 ;
struct V_156 * V_157 = V_55 -> V_55 . V_158 ;
struct V_4 * V_5 ;
struct V_134 * V_48 ;
struct V_159 * V_160 ;
struct V_92 * V_92 ;
int V_161 ;
void T_7 * V_49 ;
int V_162 = 0 ;
int V_50 ;
int V_96 ;
if ( ! V_154 && ! V_157 ) {
F_22 ( & V_55 -> V_55 , L_45 ) ;
return - V_163 ;
}
if ( V_157 ) {
V_154 = F_105 ( & V_55 -> V_55 , sizeof( * V_154 ) , V_164 ) ;
if ( ! V_154 )
return - V_165 ;
if ( F_106 ( V_157 , L_46 , NULL ) )
V_154 -> V_166 = true ;
if ( F_107 ( V_157 , L_47 , & V_55 -> V_167 ) ) {
F_22 ( & V_55 -> V_55 , L_48 ) ;
V_96 = - V_99 ;
goto V_168;
}
V_154 -> V_169 = V_55 -> V_167 * V_98 ;
V_154 -> V_170 = V_98 ;
}
V_160 = F_108 ( V_55 , V_171 , 0 ) ;
if ( ! V_160 ) {
V_96 = - V_172 ;
goto V_168;
}
V_50 = F_109 ( V_55 , 0 ) ;
if ( V_50 < 0 ) {
V_96 = V_50 ;
goto V_168;
}
V_161 = F_109 ( V_55 , 1 ) ;
if ( V_161 >= 0 && ! V_154 -> V_131 ) {
V_96 = - V_99 ;
goto V_168;
}
V_49 = F_110 ( & V_55 -> V_55 , V_160 ) ;
if ( ! V_49 ) {
V_96 = - V_165 ;
goto V_168;
}
V_92 = F_111 ( & V_55 -> V_55 , NULL ) ;
if ( F_112 ( V_92 ) ) {
V_96 = F_113 ( V_92 ) ;
goto V_168;
}
F_114 ( V_92 ) ;
V_5 = F_105 ( & V_55 -> V_55 , sizeof( * V_5 ) , V_164 ) ;
if ( ! V_5 ) {
V_96 = - V_165 ;
goto V_168;
}
V_5 -> V_88 = V_55 -> V_167 ;
V_5 -> V_92 = V_92 ;
V_5 -> V_11 = V_49 ;
V_5 -> V_48 = V_173 ;
V_5 -> V_132 = V_50 ;
V_5 -> V_133 = V_161 ;
V_5 -> V_131 = V_154 -> V_131 ;
V_5 -> V_40 = V_154 -> V_40 ;
V_5 -> V_115 = V_154 -> V_166 ;
F_115 ( & V_5 -> V_100 ) ;
V_48 = & V_5 -> V_48 ;
V_48 -> V_49 = V_154 -> V_169 ;
V_48 -> V_145 = V_154 -> V_170 ;
V_48 -> V_138 = V_154 -> V_174 ? : F_116 ( & V_55 -> V_55 ) ;
V_48 -> V_55 = & V_55 -> V_55 ;
V_48 -> V_175 = V_176 ;
F_36 ( V_5 -> V_92 ) ;
V_5 -> V_31 = F_117 ( V_5 -> V_11 + V_33 ) ;
F_38 ( V_5 -> V_92 ) ;
#ifdef F_118
V_48 -> V_158 = V_157 ;
#endif
V_96 = F_119 ( & V_5 -> V_48 ) ;
if ( V_96 )
goto V_168;
F_120 ( V_5 -> V_88 >= F_121 ( V_90 ) ) ;
V_90 [ V_5 -> V_88 ] = V_5 ;
F_122 ( V_55 , V_5 ) ;
if ( ! V_157 )
V_162 = F_17 ( V_154 -> V_169 ) ;
V_5 -> V_129 = F_123 ( V_157 ,
V_98 , V_162 ,
& V_177 , V_5 ) ;
if ( ! V_5 -> V_129 ) {
F_22 ( & V_55 -> V_55 , L_49 ) ;
V_96 = - V_178 ;
goto V_168;
}
F_74 ( V_5 ) ;
F_124 ( & V_55 -> V_55 , L_50 , V_5 -> V_11 ) ;
return 0 ;
V_168:
F_22 ( & V_55 -> V_55 , L_51 , V_96 ,
V_154 -> V_169 , V_154 -> V_169 + 31 ) ;
return V_96 ;
}
static int F_125 ( struct V_179 * V_180 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
return V_57 -> V_65 -> V_181 ;
}
static const char * F_127 ( struct V_179 * V_180 ,
unsigned V_182 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
return V_57 -> V_65 -> V_183 [ V_182 ] . V_174 ;
}
static int F_128 ( struct V_179 * V_180 , unsigned V_182 ,
const unsigned * * V_184 ,
unsigned * V_185 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
* V_184 = V_57 -> V_65 -> V_183 [ V_182 ] . V_184 ;
* V_185 = V_57 -> V_65 -> V_183 [ V_182 ] . V_186 ;
return 0 ;
}
static struct V_187 *
F_129 ( struct V_179 * V_180 , unsigned V_6 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_57 -> V_65 -> V_188 ; V_59 ++ ) {
struct V_187 * V_189 ;
V_189 = & V_57 -> V_65 -> V_190 [ V_59 ] ;
if ( V_6 >= V_189 -> V_191 &&
V_6 <= ( V_189 -> V_191 + V_189 -> V_186 - 1 ) )
return V_189 ;
}
return NULL ;
}
static void F_130 ( struct V_179 * V_180 , struct V_136 * V_137 ,
unsigned V_6 )
{
struct V_187 * V_189 ;
struct V_134 * V_48 ;
V_189 = F_129 ( V_180 , V_6 ) ;
if ( ! V_189 || ! V_189 -> V_192 ) {
F_90 ( V_137 , L_52 ) ;
return;
}
V_48 = V_189 -> V_192 ;
F_88 ( V_137 , V_48 , V_6 - V_48 -> V_49 , V_6 ) ;
}
static int F_131 ( struct V_179 * V_180 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
return V_57 -> V_65 -> V_193 ;
}
static const char * F_132 ( struct V_179 * V_180 ,
unsigned V_194 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
return V_57 -> V_65 -> V_195 [ V_194 ] . V_174 ;
}
static int F_133 ( struct V_179 * V_180 ,
unsigned V_194 ,
const char * const * * V_183 ,
unsigned * const V_196 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
* V_183 = V_57 -> V_65 -> V_195 [ V_194 ] . V_183 ;
* V_196 = V_57 -> V_65 -> V_195 [ V_194 ] . V_181 ;
return 0 ;
}
static int F_134 ( struct V_179 * V_180 , unsigned V_194 ,
unsigned V_197 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
const struct V_198 * V_199 ;
static unsigned int V_18 [ V_89 ] ;
unsigned long V_95 ;
bool V_37 ;
int V_96 = - V_99 ;
int V_59 ;
V_199 = & V_57 -> V_65 -> V_183 [ V_197 ] ;
if ( V_199 -> V_200 < 0 )
return - V_99 ;
F_20 ( V_57 -> V_55 , L_53 , V_199 -> V_174 , V_199 -> V_186 ) ;
V_37 = ( ( V_199 -> V_200 & V_79 ) == V_79 ) ;
if ( V_37 ) {
F_40 ( & V_97 , V_95 ) ;
memset ( V_18 , 0xff , sizeof( V_18 ) ) ;
for ( V_59 = 0 ; V_59 < V_199 -> V_186 ; V_59 ++ )
V_18 [ V_199 -> V_184 [ V_59 ] / V_98 ] &= ~ F_10 ( V_199 -> V_184 [ V_59 ] ) ;
F_35 ( V_18 ) ;
}
for ( V_59 = 0 ; V_59 < V_199 -> V_186 ; V_59 ++ ) {
struct V_187 * V_189 ;
struct V_4 * V_5 ;
struct V_134 * V_48 ;
unsigned V_8 ;
V_189 = F_129 ( V_180 , V_199 -> V_184 [ V_59 ] ) ;
if ( ! V_189 ) {
F_22 ( V_57 -> V_55 ,
L_54 ,
V_199 -> V_184 [ V_59 ] , V_199 -> V_174 , V_59 ) ;
goto V_201;
}
if ( ! V_189 -> V_192 ) {
F_22 ( V_57 -> V_55 , L_55 ,
V_199 -> V_184 [ V_59 ] , V_199 -> V_174 , V_59 ) ;
goto V_201;
}
V_48 = V_189 -> V_192 ;
V_5 = F_82 ( V_48 , struct V_4 , V_48 ) ;
F_20 ( V_57 -> V_55 , L_56 , V_199 -> V_184 [ V_59 ] , V_199 -> V_200 ) ;
F_36 ( V_5 -> V_92 ) ;
V_8 = V_199 -> V_184 [ V_59 ] % V_98 ;
F_16 ( V_5 , V_8 ) ;
F_15 ( V_5 , V_8 ,
( V_199 -> V_200 & V_79 ) , V_37 ) ;
F_38 ( V_5 -> V_92 ) ;
if ( ( V_199 -> V_200 & V_79 ) == V_79 )
F_21 ( V_57 , V_199 -> V_184 [ V_59 ] ,
V_199 -> V_200 >> V_202 ) ;
}
V_96 = 0 ;
V_201:
if ( V_37 ) {
F_37 ( V_18 ) ;
F_43 ( & V_97 , V_95 ) ;
}
return V_96 ;
}
static void F_135 ( struct V_179 * V_180 ,
unsigned V_194 , unsigned V_197 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
const struct V_198 * V_199 ;
V_199 = & V_57 -> V_65 -> V_183 [ V_197 ] ;
if ( V_199 -> V_200 < 0 )
return;
F_20 ( V_57 -> V_55 , L_57 , V_199 -> V_174 , V_199 -> V_186 ) ;
}
int F_136 ( struct V_179 * V_180 ,
struct V_187 * V_189 ,
unsigned V_6 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
struct V_4 * V_5 ;
struct V_134 * V_48 ;
unsigned V_8 ;
if ( ! V_189 ) {
F_22 ( V_57 -> V_55 , L_58 ) ;
return - V_99 ;
}
if ( ! V_189 -> V_192 ) {
F_22 ( V_57 -> V_55 , L_59 ) ;
return - V_99 ;
}
V_48 = V_189 -> V_192 ;
V_5 = F_82 ( V_48 , struct V_4 , V_48 ) ;
F_20 ( V_57 -> V_55 , L_60 , V_6 ) ;
F_36 ( V_5 -> V_92 ) ;
V_8 = V_6 % V_98 ;
F_4 ( V_5 , V_8 , V_78 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
void F_137 ( struct V_179 * V_180 ,
struct V_187 * V_189 ,
unsigned V_6 )
{
struct V_56 * V_57 = F_126 ( V_180 ) ;
F_20 ( V_57 -> V_55 , L_61 , V_6 ) ;
}
int F_138 ( struct V_179 * V_180 ,
unsigned V_68 ,
unsigned long * V_203 )
{
return - V_99 ;
}
int F_139 ( struct V_179 * V_180 ,
unsigned V_68 ,
unsigned long V_203 )
{
static const char * V_80 [] = {
[ V_25 ] = L_11 ,
[ V_27 ] = L_12 ,
[ V_29 ] = L_13 ,
[ 3 ] = L_14
} ;
static const char * V_81 [] = {
[ V_82 ] = L_15 ,
[ V_20 ] = L_16 ,
} ;
struct V_56 * V_57 = F_126 ( V_180 ) ;
struct V_4 * V_5 ;
struct V_187 * V_189 ;
struct V_134 * V_48 ;
unsigned V_8 ;
T_4 V_74 = ( T_4 ) V_203 ;
int V_22 = F_26 ( V_74 ) ;
int V_18 = F_28 ( V_74 ) ;
int V_84 = F_29 ( V_74 ) ;
int V_35 = F_30 ( V_74 ) ;
bool V_31 = F_34 ( V_74 ) ;
bool V_204 = F_140 ( V_74 ) ;
bool V_75 = F_141 ( V_74 ) ;
V_189 = F_129 ( V_180 , V_68 ) ;
if ( ! V_189 ) {
F_22 ( V_57 -> V_55 , L_62 , V_68 ) ;
return - V_99 ;
}
if ( ! V_189 -> V_192 ) {
F_22 ( V_57 -> V_55 , L_63 ,
V_68 ) ;
return - V_99 ;
}
V_48 = V_189 -> V_192 ;
V_5 = F_82 ( V_48 , struct V_4 , V_48 ) ;
if ( V_75 ) {
int V_85 = F_31 ( V_74 ) ;
int V_86 = F_32 ( V_74 ) ;
int V_87 = F_33 ( V_74 ) ;
V_204 = true ;
if ( V_85 )
V_22 = V_85 - 1 ;
if ( V_86 )
V_84 = V_86 - 1 ;
if ( V_87 )
V_35 = V_87 - 1 ;
F_20 ( V_5 -> V_48 . V_55 , L_23 ,
V_68 ,
V_85 ? V_80 [ V_22 ] : L_24 ,
V_86 ? ( V_84 ? L_25 : L_19 ) : L_24 ,
V_87 ? ( V_35 ? L_20 : L_21 ) : L_24 ) ;
}
F_20 ( V_5 -> V_48 . V_55 , L_64 ,
V_68 , V_74 , V_80 [ V_22 ] , V_81 [ V_18 ] ,
V_84 ? L_18 : L_19 ,
V_84 ? ( V_35 ? L_20 : L_21 ) : L_22 ,
V_31 ? L_65 : L_66 ) ;
F_36 ( V_5 -> V_92 ) ;
V_8 = V_68 % V_98 ;
if ( V_204 )
F_4 ( V_5 , V_8 , V_78 ) ;
if ( V_84 )
F_14 ( V_5 , V_8 , V_35 ) ;
else {
F_12 ( V_5 , V_8 ) ;
F_8 ( V_5 , V_8 , V_22 ) ;
}
F_9 ( V_5 , V_8 , V_31 ) ;
F_7 ( V_5 , V_8 , V_18 ) ;
F_38 ( V_5 -> V_92 ) ;
return 0 ;
}
static int T_6 F_142 ( struct V_152 * V_205 )
{
const struct V_206 * V_207 = F_143 ( V_205 ) ;
struct V_156 * V_157 = V_205 -> V_55 . V_158 ;
struct V_56 * V_57 ;
unsigned int V_208 = 0 ;
int V_59 ;
V_57 = F_105 ( & V_205 -> V_55 , sizeof( * V_57 ) , V_164 ) ;
if ( ! V_57 )
return - V_165 ;
if ( V_207 )
V_208 = V_207 -> V_209 ;
else if ( V_157 )
V_208 = ( unsigned int )
F_144 ( V_210 , & V_205 -> V_55 ) -> V_211 ;
if ( V_208 == V_212 )
F_145 ( & V_57 -> V_65 ) ;
if ( V_208 == V_213 )
F_146 ( & V_57 -> V_65 ) ;
if ( V_208 == V_214 )
F_147 ( & V_57 -> V_65 ) ;
for ( V_59 = 0 ; V_59 < V_57 -> V_65 -> V_188 ; V_59 ++ ) {
if ( ! V_90 [ V_59 ] ) {
F_23 ( & V_205 -> V_55 , L_67 , V_59 ) ;
return - V_215 ;
}
V_57 -> V_65 -> V_190 [ V_59 ] . V_192 = & V_90 [ V_59 ] -> V_48 ;
}
V_216 . V_184 = V_57 -> V_65 -> V_184 ;
V_216 . V_186 = V_57 -> V_65 -> V_186 ;
V_57 -> V_55 = & V_205 -> V_55 ;
V_57 -> V_217 = F_148 ( & V_216 , & V_205 -> V_55 , V_57 ) ;
if ( ! V_57 -> V_217 ) {
F_22 ( & V_205 -> V_55 , L_68 ) ;
return - V_99 ;
}
for ( V_59 = 0 ; V_59 < V_57 -> V_65 -> V_188 ; V_59 ++ )
F_149 ( V_57 -> V_217 , & V_57 -> V_65 -> V_190 [ V_59 ] ) ;
F_122 ( V_205 , V_57 ) ;
F_124 ( & V_205 -> V_55 , L_69 ) ;
return 0 ;
}
static int T_8 F_150 ( void )
{
int V_96 ;
V_96 = F_151 ( & V_218 ) ;
if ( V_96 )
return V_96 ;
return F_151 ( & V_219 ) ;
}
