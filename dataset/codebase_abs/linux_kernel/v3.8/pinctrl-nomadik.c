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
static void F_18 ( void T_2 * V_53 , T_1 V_54 , T_1 V_55 )
{
T_1 V_32 ;
V_32 = F_2 ( V_53 ) ;
V_32 = ( ( V_32 & ~ V_54 ) | ( V_55 & V_54 ) ) ;
F_3 ( V_32 , V_53 ) ;
}
static void F_19 ( struct V_56 * V_57 ,
unsigned V_3 , unsigned V_58 )
{
int V_59 ;
T_3 V_53 ;
T_4 V_5 ;
T_4 V_60 ;
const struct V_61 * V_62 ;
const T_3 * V_63 ;
if ( ! V_57 -> V_64 )
return;
if ( V_58 > V_65 ) {
F_20 ( V_57 -> V_52 , L_2 ,
V_58 ) ;
return;
}
for ( V_59 = 0 ; V_59 < V_57 -> V_66 -> V_67 ; V_59 ++ ) {
if ( V_57 -> V_66 -> V_68 [ V_59 ] . V_69 == V_3 )
break;
}
if ( V_59 == V_57 -> V_66 -> V_67 ) {
F_17 ( V_57 -> V_52 , L_3 ,
V_3 ) ;
return;
}
V_62 = V_57 -> V_66 -> V_68 + V_59 ;
V_63 = V_57 -> V_66 -> V_70 ;
if ( ! V_58 ) {
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
if ( V_62 -> V_71 [ V_59 ] . V_72 == true ) {
V_53 = V_63 [ V_62 -> V_71 [ V_59 ] . V_73 ] ;
V_5 = V_62 -> V_71 [ V_59 ] . V_74 ;
if ( F_2 ( V_57 -> V_64 + V_53 ) & F_7 ( V_5 ) ) {
F_18 ( V_57 -> V_64 + V_53 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_57 -> V_52 ,
L_4 ,
V_3 , V_59 + 1 ) ;
}
}
}
return;
}
V_60 = V_58 - 1 ;
if ( V_62 -> V_71 [ V_60 ] . V_72 == false ) {
F_21 ( V_57 -> V_52 ,
L_5 ,
V_3 , V_58 ) ;
return;
}
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
if ( V_59 == V_60 )
continue;
if ( V_62 -> V_71 [ V_59 ] . V_72 == true ) {
V_53 = V_63 [ V_62 -> V_71 [ V_59 ] . V_73 ] ;
V_5 = V_62 -> V_71 [ V_59 ] . V_74 ;
if ( F_2 ( V_57 -> V_64 + V_53 ) & F_7 ( V_5 ) ) {
F_18 ( V_57 -> V_64 + V_53 , F_7 ( V_5 ) , 0 ) ;
F_17 ( V_57 -> V_52 ,
L_4 ,
V_3 , V_59 + 1 ) ;
}
}
}
V_53 = V_63 [ V_62 -> V_71 [ V_60 ] . V_73 ] ;
V_5 = V_62 -> V_71 [ V_60 ] . V_74 ;
F_17 ( V_57 -> V_52 , L_6 ,
V_3 , V_60 + 1 ) ;
F_18 ( V_57 -> V_64 + V_53 , F_7 ( V_5 ) , F_7 ( V_5 ) ) ;
}
static void F_22 ( struct V_1 * V_2 , unsigned V_3 ,
T_5 V_75 , bool V_76 , unsigned int * V_77 )
{
static const char * V_78 [] = {
[ V_79 ] = L_7 ,
[ V_11 ] = L_8 ,
[ V_12 ] = L_9 ,
[ V_80 ] = L_10
} ;
static const char * V_81 [] = {
[ V_22 ] = L_11 ,
[ V_24 ] = L_12 ,
[ V_26 ] = L_13 ,
[ 3 ] = L_14
} ;
static const char * V_82 [] = {
[ V_83 ] = L_15 ,
[ V_17 ] = L_16 ,
} ;
int V_69 = F_23 ( V_75 ) ;
int V_19 = F_24 ( V_75 ) ;
int V_84 = F_25 ( V_75 ) ;
int V_15 = F_26 ( V_75 ) ;
int V_85 = F_27 ( V_75 ) ;
int V_32 = F_28 ( V_75 ) ;
bool V_34 = V_84 == V_80 ;
F_17 ( V_2 -> V_45 . V_52 , L_17 ,
V_69 , V_75 , V_78 [ V_84 ] , V_81 [ V_19 ] , V_82 [ V_15 ] ,
V_85 ? L_18 : L_19 ,
V_85 ? ( V_32 ? L_20 : L_21 ) : L_22 ) ;
if ( V_76 ) {
int V_86 = F_29 ( V_75 ) ;
int V_87 = F_30 ( V_75 ) ;
int V_88 = F_31 ( V_75 ) ;
V_84 = V_79 ;
if ( V_86 )
V_19 = V_86 - 1 ;
if ( V_87 )
V_85 = V_87 - 1 ;
if ( V_88 )
V_32 = V_88 - 1 ;
F_17 ( V_2 -> V_45 . V_52 , L_23 ,
V_69 ,
V_86 ? V_81 [ V_19 ] : L_24 ,
V_87 ? ( V_85 ? L_25 : L_19 ) : L_24 ,
V_88 ? ( V_32 ? L_20 : L_21 ) : L_24 ) ;
}
if ( V_85 )
F_11 ( V_2 , V_3 , V_32 ) ;
else {
F_9 ( V_2 , V_3 ) ;
F_5 ( V_2 , V_3 , V_19 ) ;
}
F_6 ( V_2 , V_3 , F_32 ( V_75 ) ) ;
if ( V_84 != V_79 )
F_13 ( V_2 , V_3 ) ;
if ( V_77 ) {
if ( V_15 == V_17 )
V_77 [ V_2 -> V_89 ] |= F_7 ( V_3 ) ;
else
V_77 [ V_2 -> V_89 ] &= ~ F_7 ( V_3 ) ;
} else
F_4 ( V_2 , V_3 , V_15 ) ;
F_12 ( V_2 , V_3 , V_84 , V_34 ) ;
}
static void F_33 ( unsigned int * V_15 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
struct V_1 * V_45 = V_91 [ V_59 ] ;
unsigned int V_92 = V_15 [ V_59 ] ;
if ( ! V_45 )
break;
F_34 ( V_45 -> V_93 ) ;
V_15 [ V_59 ] = F_2 ( V_45 -> V_8 + V_16 ) ;
F_3 ( V_92 , V_45 -> V_8 + V_16 ) ;
}
}
static void F_35 ( unsigned int * V_15 )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
struct V_1 * V_45 = V_91 [ V_59 ] ;
if ( ! V_45 )
break;
F_3 ( V_15 [ V_59 ] , V_45 -> V_8 + V_16 ) ;
F_36 ( V_45 -> V_93 ) ;
}
}
static int F_37 ( T_5 * V_94 , int V_95 , bool V_76 )
{
static unsigned int V_15 [ V_90 ] ;
unsigned long V_96 ;
bool V_34 = false ;
int V_97 = 0 ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_95 ; V_59 ++ ) {
if ( F_25 ( V_94 [ V_59 ] ) == V_80 ) {
V_34 = true ;
break;
}
}
F_38 ( & V_98 , V_96 ) ;
if ( V_34 ) {
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_59 = 0 ; V_59 < V_95 ; V_59 ++ ) {
int V_69 = F_23 ( V_94 [ V_59 ] ) ;
int V_3 = V_69 % V_99 ;
if ( F_25 ( V_94 [ V_59 ] ) == V_80 )
V_15 [ V_69 / V_99 ] &= ~ F_7 ( V_3 ) ;
}
F_33 ( V_15 ) ;
}
for ( V_59 = 0 ; V_59 < V_95 ; V_59 ++ ) {
struct V_1 * V_2 ;
int V_69 = F_23 ( V_94 [ V_59 ] ) ;
V_2 = V_91 [ V_69 / V_99 ] ;
if ( ! V_2 ) {
V_97 = - V_100 ;
break;
}
F_34 ( V_2 -> V_93 ) ;
F_39 ( & V_2 -> V_101 ) ;
F_22 ( V_2 , V_69 % V_99 ,
V_94 [ V_59 ] , V_76 , V_34 ? V_15 : NULL ) ;
F_40 ( & V_2 -> V_101 ) ;
F_36 ( V_2 -> V_93 ) ;
}
if ( V_34 )
F_35 ( V_15 ) ;
F_41 ( & V_98 , V_96 ) ;
return V_97 ;
}
int F_42 ( T_5 V_75 , bool V_76 )
{
return F_37 ( & V_75 , 1 , V_76 ) ;
}
int F_43 ( T_5 * V_94 , int V_95 )
{
return F_37 ( V_94 , V_95 , false ) ;
}
int F_44 ( T_5 * V_94 , int V_95 )
{
return F_37 ( V_94 , V_95 , true ) ;
}
int F_45 ( int V_44 , enum V_13 V_14 )
{
struct V_1 * V_2 ;
unsigned long V_96 ;
V_2 = V_91 [ V_44 / V_99 ] ;
if ( ! V_2 )
return - V_100 ;
F_34 ( V_2 -> V_93 ) ;
F_38 ( & V_98 , V_96 ) ;
F_39 ( & V_2 -> V_101 ) ;
F_4 ( V_2 , V_44 % V_99 , V_14 ) ;
F_40 ( & V_2 -> V_101 ) ;
F_41 ( & V_98 , V_96 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
int F_46 ( int V_44 , enum V_18 V_19 )
{
struct V_1 * V_2 ;
unsigned long V_96 ;
V_2 = V_91 [ V_44 / V_99 ] ;
if ( ! V_2 )
return - V_100 ;
F_34 ( V_2 -> V_93 ) ;
F_38 ( & V_2 -> V_101 , V_96 ) ;
F_5 ( V_2 , V_44 % V_99 , V_19 ) ;
F_41 ( & V_2 -> V_101 , V_96 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
int F_47 ( int V_44 , int V_4 )
{
struct V_1 * V_2 ;
unsigned long V_96 ;
V_2 = V_91 [ V_44 / V_99 ] ;
if ( ! V_2 )
return - V_100 ;
F_34 ( V_2 -> V_93 ) ;
F_38 ( & V_2 -> V_101 , V_96 ) ;
F_1 ( V_2 , V_44 % V_99 , V_4 ) ;
F_41 ( & V_2 -> V_101 , V_96 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static int T_6 F_48 ( struct V_102 * V_103 , int V_44 )
{
int V_59 ;
T_3 V_53 ;
T_4 V_5 ;
struct V_56 * V_57 = F_49 ( V_103 ) ;
const struct V_61 * V_62 ;
const T_3 * V_63 ;
if ( ! V_57 -> V_64 )
return V_80 ;
for ( V_59 = 0 ; V_59 < V_57 -> V_66 -> V_67 ; V_59 ++ ) {
if ( V_57 -> V_66 -> V_68 [ V_59 ] . V_69 == V_44 )
break;
}
if ( V_59 == V_57 -> V_66 -> V_67 )
return V_80 ;
V_62 = V_57 -> V_66 -> V_68 + V_59 ;
V_63 = V_57 -> V_66 -> V_70 ;
for ( V_59 = 0 ; V_59 < V_65 ; V_59 ++ ) {
if ( V_62 -> V_71 [ V_59 ] . V_72 == true ) {
V_53 = V_63 [ V_62 -> V_71 [ V_59 ] . V_73 ] ;
V_5 = V_62 -> V_71 [ V_59 ] . V_74 ;
if ( F_2 ( V_57 -> V_64 + V_53 ) & F_7 ( V_5 ) )
return V_80 + V_59 + 1 ;
}
}
return V_80 ;
}
int F_50 ( int V_44 )
{
struct V_1 * V_2 ;
T_1 V_6 , V_7 , V_5 ;
V_2 = V_91 [ V_44 / V_99 ] ;
if ( ! V_2 )
return - V_100 ;
V_5 = 1 << ( V_44 % V_99 ) ;
F_34 ( V_2 -> V_93 ) ;
V_6 = F_2 ( V_2 -> V_8 + V_9 ) & V_5 ;
V_7 = F_2 ( V_2 -> V_8 + V_10 ) & V_5 ;
F_36 ( V_2 -> V_93 ) ;
return ( V_6 ? V_11 : 0 ) | ( V_7 ? V_12 : 0 ) ;
}
static inline int F_51 ( int V_44 )
{
return 1 << ( V_44 % V_99 ) ;
}
static void F_52 ( struct V_48 * V_49 )
{
struct V_1 * V_2 ;
V_2 = F_53 ( V_49 ) ;
if ( ! V_2 )
return;
F_34 ( V_2 -> V_93 ) ;
F_3 ( F_51 ( V_49 -> V_104 ) , V_2 -> V_8 + V_105 ) ;
F_36 ( V_2 -> V_93 ) ;
}
static void F_54 ( struct V_1 * V_2 ,
int V_44 , enum V_106 V_107 ,
bool V_108 )
{
T_1 V_109 = F_51 ( V_44 ) ;
T_1 * V_110 ;
T_1 * V_111 ;
T_1 V_112 ;
T_1 V_113 ;
if ( V_107 == V_114 ) {
V_112 = V_50 ;
V_113 = V_51 ;
V_110 = & V_2 -> V_43 ;
V_111 = & V_2 -> V_41 ;
} else {
V_112 = V_38 ;
V_113 = V_39 ;
V_110 = & V_2 -> V_35 ;
V_111 = & V_2 -> V_36 ;
}
if ( V_2 -> V_115 & V_109 ) {
if ( V_108 )
* V_110 |= V_109 ;
else
* V_110 &= ~ V_109 ;
F_3 ( * V_110 , V_2 -> V_8 + V_112 ) ;
}
if ( V_2 -> V_116 & V_109 ) {
if ( V_108 )
* V_111 |= V_109 ;
else
* V_111 &= ~ V_109 ;
F_3 ( * V_111 , V_2 -> V_8 + V_113 ) ;
}
}
static void F_55 ( struct V_1 * V_2 ,
int V_44 , bool V_117 )
{
if ( V_2 -> V_118 && V_117 ) {
F_4 ( V_2 , V_44 % V_99 ,
V_119 ) ;
}
F_54 ( V_2 , V_44 , V_120 , V_117 ) ;
}
static int F_56 ( struct V_48 * V_49 , bool V_108 )
{
struct V_1 * V_2 ;
unsigned long V_96 ;
T_1 V_109 ;
V_2 = F_53 ( V_49 ) ;
V_109 = F_51 ( V_49 -> V_104 ) ;
if ( ! V_2 )
return - V_100 ;
F_34 ( V_2 -> V_93 ) ;
F_38 ( & V_98 , V_96 ) ;
F_39 ( & V_2 -> V_101 ) ;
F_54 ( V_2 , V_49 -> V_104 , V_114 , V_108 ) ;
if ( ! ( V_2 -> V_121 & V_109 ) )
F_55 ( V_2 , V_49 -> V_104 , V_108 ) ;
F_40 ( & V_2 -> V_101 ) ;
F_41 ( & V_98 , V_96 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static void F_57 ( struct V_48 * V_49 )
{
F_56 ( V_49 , false ) ;
}
static void F_58 ( struct V_48 * V_49 )
{
F_56 ( V_49 , true ) ;
}
static int F_59 ( struct V_48 * V_49 , unsigned int V_117 )
{
struct V_1 * V_2 ;
unsigned long V_96 ;
T_1 V_109 ;
V_2 = F_53 ( V_49 ) ;
if ( ! V_2 )
return - V_100 ;
V_109 = F_51 ( V_49 -> V_104 ) ;
F_34 ( V_2 -> V_93 ) ;
F_38 ( & V_98 , V_96 ) ;
F_39 ( & V_2 -> V_101 ) ;
if ( F_16 ( V_49 ) )
F_55 ( V_2 , V_49 -> V_104 , V_117 ) ;
if ( V_117 )
V_2 -> V_121 |= V_109 ;
else
V_2 -> V_121 &= ~ V_109 ;
F_40 ( & V_2 -> V_101 ) ;
F_41 ( & V_98 , V_96 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static int F_60 ( struct V_48 * V_49 , unsigned int type )
{
bool V_29 = ! F_16 ( V_49 ) ;
bool V_122 = F_61 ( V_49 ) ;
struct V_1 * V_2 ;
unsigned long V_96 ;
T_1 V_109 ;
V_2 = F_53 ( V_49 ) ;
V_109 = F_51 ( V_49 -> V_104 ) ;
if ( ! V_2 )
return - V_100 ;
if ( type & V_123 )
return - V_100 ;
if ( type & V_124 )
return - V_100 ;
F_34 ( V_2 -> V_93 ) ;
F_38 ( & V_2 -> V_101 , V_96 ) ;
if ( V_29 )
F_54 ( V_2 , V_49 -> V_104 , V_114 , false ) ;
if ( V_29 || V_122 )
F_54 ( V_2 , V_49 -> V_104 , V_120 , false ) ;
V_2 -> V_115 &= ~ V_109 ;
if ( type & V_125 )
V_2 -> V_115 |= V_109 ;
V_2 -> V_116 &= ~ V_109 ;
if ( type & V_126 )
V_2 -> V_116 |= V_109 ;
if ( V_29 )
F_54 ( V_2 , V_49 -> V_104 , V_114 , true ) ;
if ( V_29 || V_122 )
F_54 ( V_2 , V_49 -> V_104 , V_120 , true ) ;
F_41 ( & V_2 -> V_101 , V_96 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static unsigned int F_62 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_53 ( V_49 ) ;
F_34 ( V_2 -> V_93 ) ;
F_58 ( V_49 ) ;
return 0 ;
}
static void F_63 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_53 ( V_49 ) ;
F_57 ( V_49 ) ;
F_36 ( V_2 -> V_93 ) ;
}
static void F_64 ( unsigned int V_47 , struct V_127 * V_128 ,
T_1 V_129 )
{
struct V_1 * V_2 ;
struct V_130 * V_131 = F_65 ( V_47 ) ;
F_66 ( V_131 , V_128 ) ;
V_2 = F_67 ( V_47 ) ;
while ( V_129 ) {
int V_5 = F_68 ( V_129 ) ;
F_69 ( F_70 ( V_2 -> V_132 , V_5 ) ) ;
V_129 &= ~ F_7 ( V_5 ) ;
}
F_71 ( V_131 , V_128 ) ;
}
static void F_72 ( unsigned int V_47 , struct V_127 * V_128 )
{
struct V_1 * V_2 = F_67 ( V_47 ) ;
T_1 V_129 ;
F_34 ( V_2 -> V_93 ) ;
V_129 = F_2 ( V_2 -> V_8 + V_133 ) ;
F_36 ( V_2 -> V_93 ) ;
F_64 ( V_47 , V_128 , V_129 ) ;
}
static void F_73 ( unsigned int V_47 ,
struct V_127 * V_128 )
{
struct V_1 * V_2 = F_67 ( V_47 ) ;
T_1 V_129 = V_2 -> V_134 ( V_2 -> V_89 ) ;
F_64 ( V_47 , V_128 , V_129 ) ;
}
static int F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 -> V_135 , F_72 ) ;
F_76 ( V_2 -> V_135 , V_2 ) ;
if ( V_2 -> V_136 >= 0 ) {
F_75 ( V_2 -> V_136 ,
F_73 ) ;
F_76 ( V_2 -> V_136 , V_2 ) ;
}
return 0 ;
}
static int F_77 ( struct V_137 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
return F_78 ( V_44 ) ;
}
static void F_79 ( struct V_137 * V_45 , unsigned V_3 )
{
int V_44 = V_45 -> V_46 + V_3 ;
F_80 ( V_44 ) ;
}
static int F_81 ( struct V_137 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_82 ( V_45 , struct V_1 , V_45 ) ;
F_34 ( V_2 -> V_93 ) ;
F_3 ( 1 << V_3 , V_2 -> V_8 + V_31 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static int F_83 ( struct V_137 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_82 ( V_45 , struct V_1 , V_45 ) ;
T_1 V_5 = 1 << V_3 ;
int V_55 ;
F_34 ( V_2 -> V_93 ) ;
V_55 = ( F_2 ( V_2 -> V_8 + V_138 ) & V_5 ) != 0 ;
F_36 ( V_2 -> V_93 ) ;
return V_55 ;
}
static void F_84 ( struct V_137 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_82 ( V_45 , struct V_1 , V_45 ) ;
F_34 ( V_2 -> V_93 ) ;
F_10 ( V_2 , V_3 , V_32 ) ;
F_36 ( V_2 -> V_93 ) ;
}
static int F_85 ( struct V_137 * V_45 , unsigned V_3 ,
int V_32 )
{
struct V_1 * V_2 =
F_82 ( V_45 , struct V_1 , V_45 ) ;
F_34 ( V_2 -> V_93 ) ;
F_11 ( V_2 , V_3 , V_32 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static int F_86 ( struct V_137 * V_45 , unsigned V_3 )
{
struct V_1 * V_2 =
F_82 ( V_45 , struct V_1 , V_45 ) ;
return F_87 ( V_2 -> V_132 , V_3 ) ;
}
static void F_88 ( struct V_139 * V_140 ,
struct V_102 * V_103 , struct V_137 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
const char * V_141 = F_89 ( V_45 , V_3 ) ;
struct V_1 * V_2 =
F_82 ( V_45 , struct V_1 , V_45 ) ;
int V_14 ;
bool V_142 ;
bool V_19 ;
T_1 V_5 = 1 << V_3 ;
const char * V_143 [] = {
[ V_79 ] = L_26 ,
[ V_11 ] = L_27 ,
[ V_12 ] = L_28 ,
[ V_80 ] = L_29 ,
[ V_80 + 1 ] = L_30 ,
[ V_80 + 2 ] = L_31 ,
[ V_80 + 3 ] = L_32 ,
[ V_80 + 4 ] = L_33 ,
} ;
F_34 ( V_2 -> V_93 ) ;
V_142 = ! ! ( F_2 ( V_2 -> V_8 + V_144 ) & V_5 ) ;
V_19 = ! ( F_2 ( V_2 -> V_8 + V_21 ) & V_5 ) ;
V_14 = F_50 ( V_44 ) ;
if ( ( V_14 == V_80 ) && V_103 )
V_14 = F_48 ( V_103 , V_44 ) ;
F_90 ( V_140 , L_34 ,
V_44 , V_141 ? : L_35 ,
V_142 ? L_36 : L_37 ,
V_45 -> V_145
? ( V_45 -> V_145 ( V_45 , V_3 ) ? L_38 : L_39 )
: L_40 ,
( V_14 < 0 ) ? L_41 : V_143 [ V_14 ] ,
V_19 ? L_42 : L_11 ) ;
if ( V_141 && ! V_142 ) {
int V_47 = F_91 ( V_44 ) ;
struct V_127 * V_128 = F_92 ( V_47 ) ;
if ( V_47 >= 0 && V_128 -> V_146 ) {
char * V_147 ;
T_1 V_109 = F_51 ( V_44 ) ;
if ( V_2 -> V_115 & V_109 )
V_147 = L_43 ;
else if ( V_2 -> V_116 & V_109 )
V_147 = L_44 ;
else
V_147 = L_45 ;
F_90 ( V_140 , L_46 ,
V_47 , V_147 ,
F_61 ( & V_128 -> V_48 )
? L_47 : L_22 ) ;
}
}
F_36 ( V_2 -> V_93 ) ;
}
static void F_93 ( struct V_139 * V_140 , struct V_137 * V_45 )
{
unsigned V_59 ;
unsigned V_44 = V_45 -> V_46 ;
for ( V_59 = 0 ; V_59 < V_45 -> V_148 ; V_59 ++ , V_44 ++ ) {
F_88 ( V_140 , NULL , V_45 , V_59 , V_44 ) ;
F_90 ( V_140 , L_48 ) ;
}
}
static inline void F_88 ( struct V_139 * V_140 ,
struct V_102 * V_103 ,
struct V_137 * V_45 ,
unsigned V_3 , unsigned V_44 )
{
}
void F_94 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
struct V_1 * V_45 = V_91 [ V_59 ] ;
if ( ! V_45 )
continue;
F_34 ( V_45 -> V_93 ) ;
}
}
void F_95 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
struct V_1 * V_45 = V_91 [ V_59 ] ;
if ( ! V_45 )
continue;
F_36 ( V_45 -> V_93 ) ;
}
}
void F_96 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
struct V_1 * V_45 = V_91 [ V_59 ] ;
if ( ! V_45 )
break;
F_34 ( V_45 -> V_93 ) ;
F_3 ( V_45 -> V_35 & V_45 -> V_121 ,
V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 & V_45 -> V_121 ,
V_45 -> V_8 + V_39 ) ;
F_36 ( V_45 -> V_93 ) ;
}
}
void F_97 ( void )
{
int V_59 ;
for ( V_59 = 0 ; V_59 < V_90 ; V_59 ++ ) {
struct V_1 * V_45 = V_91 [ V_59 ] ;
if ( ! V_45 )
break;
F_34 ( V_45 -> V_93 ) ;
F_3 ( V_45 -> V_35 , V_45 -> V_8 + V_38 ) ;
F_3 ( V_45 -> V_36 , V_45 -> V_8 + V_39 ) ;
F_36 ( V_45 -> V_93 ) ;
}
}
void F_98 ( int V_149 , T_1 * V_23 )
{
if ( V_149 < V_90 ) {
struct V_1 * V_45 = V_91 [ V_149 ] ;
if ( ! V_45 )
return;
* V_23 = V_45 -> V_23 ;
}
}
static int F_99 ( struct V_150 * V_49 , unsigned int V_47 ,
T_7 V_104 )
{
struct V_1 * V_2 = V_49 -> V_151 ;
if ( ! V_2 )
return - V_100 ;
F_100 ( V_47 , & V_152 , V_153 ) ;
F_101 ( V_47 , V_154 ) ;
F_102 ( V_47 , V_2 ) ;
F_103 ( V_47 , V_126 ) ;
return 0 ;
}
static int F_104 ( struct V_155 * V_52 )
{
struct V_156 * V_157 = V_52 -> V_52 . V_158 ;
struct V_159 * V_160 = V_52 -> V_52 . V_161 ;
struct V_1 * V_2 ;
struct V_137 * V_45 ;
struct V_162 * V_163 ;
struct V_93 * V_93 ;
int V_164 ;
void T_2 * V_46 ;
int V_165 = 0 ;
int V_47 ;
int V_97 ;
if ( ! V_157 && ! V_160 ) {
F_20 ( & V_52 -> V_52 , L_49 ) ;
return - V_166 ;
}
if ( V_160 ) {
V_157 = F_105 ( & V_52 -> V_52 , sizeof( * V_157 ) , V_167 ) ;
if ( ! V_157 )
return - V_168 ;
if ( F_106 ( V_160 , L_50 , NULL ) )
V_157 -> V_169 = true ;
if ( F_107 ( V_160 , L_51 , & V_52 -> V_170 ) ) {
F_20 ( & V_52 -> V_52 , L_52 ) ;
V_97 = - V_100 ;
goto V_171;
}
V_157 -> V_172 = V_52 -> V_170 * V_99 ;
V_157 -> V_173 = V_99 ;
}
V_163 = F_108 ( V_52 , V_174 , 0 ) ;
if ( ! V_163 ) {
V_97 = - V_175 ;
goto V_171;
}
V_47 = F_109 ( V_52 , 0 ) ;
if ( V_47 < 0 ) {
V_97 = V_47 ;
goto V_171;
}
V_164 = F_109 ( V_52 , 1 ) ;
if ( V_164 >= 0 && ! V_157 -> V_134 ) {
V_97 = - V_100 ;
goto V_171;
}
V_46 = F_110 ( & V_52 -> V_52 , V_163 ) ;
if ( ! V_46 ) {
V_97 = - V_168 ;
goto V_171;
}
V_93 = F_111 ( & V_52 -> V_52 , NULL ) ;
if ( F_112 ( V_93 ) ) {
V_97 = F_113 ( V_93 ) ;
goto V_171;
}
F_114 ( V_93 ) ;
V_2 = F_105 ( & V_52 -> V_52 , sizeof( * V_2 ) , V_167 ) ;
if ( ! V_2 ) {
V_97 = - V_168 ;
goto V_171;
}
V_2 -> V_89 = V_52 -> V_170 ;
V_2 -> V_93 = V_93 ;
V_2 -> V_8 = V_46 ;
V_2 -> V_45 = V_176 ;
V_2 -> V_135 = V_47 ;
V_2 -> V_136 = V_164 ;
V_2 -> V_134 = V_157 -> V_134 ;
V_2 -> V_37 = V_157 -> V_37 ;
V_2 -> V_118 = V_157 -> V_169 ;
F_115 ( & V_2 -> V_101 ) ;
V_45 = & V_2 -> V_45 ;
V_45 -> V_46 = V_157 -> V_172 ;
V_45 -> V_148 = V_157 -> V_173 ;
V_45 -> V_141 = V_157 -> V_177 ? : F_116 ( & V_52 -> V_52 ) ;
V_45 -> V_52 = & V_52 -> V_52 ;
V_45 -> V_178 = V_179 ;
F_34 ( V_2 -> V_93 ) ;
V_2 -> V_28 = F_117 ( V_2 -> V_8 + V_30 ) ;
F_36 ( V_2 -> V_93 ) ;
#ifdef F_118
V_45 -> V_161 = V_160 ;
#endif
V_97 = F_119 ( & V_2 -> V_45 ) ;
if ( V_97 )
goto V_171;
F_120 ( V_2 -> V_89 >= F_121 ( V_91 ) ) ;
V_91 [ V_2 -> V_89 ] = V_2 ;
F_122 ( V_52 , V_2 ) ;
if ( ! V_160 )
V_165 = F_14 ( V_157 -> V_172 ) ;
V_2 -> V_132 = F_123 ( V_160 ,
V_99 , V_165 ,
& V_180 , V_2 ) ;
if ( ! V_2 -> V_132 ) {
F_20 ( & V_52 -> V_52 , L_53 ) ;
V_97 = - V_181 ;
goto V_171;
}
F_74 ( V_2 ) ;
F_124 ( & V_52 -> V_52 , L_54 , V_2 -> V_8 ) ;
return 0 ;
V_171:
F_20 ( & V_52 -> V_52 , L_55 , V_97 ,
V_157 -> V_172 , V_157 -> V_172 + 31 ) ;
return V_97 ;
}
static int F_125 ( struct V_102 * V_103 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
return V_57 -> V_66 -> V_182 ;
}
static const char * F_126 ( struct V_102 * V_103 ,
unsigned V_183 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
return V_57 -> V_66 -> V_184 [ V_183 ] . V_177 ;
}
static int F_127 ( struct V_102 * V_103 , unsigned V_183 ,
const unsigned * * V_185 ,
unsigned * V_186 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
* V_185 = V_57 -> V_66 -> V_184 [ V_183 ] . V_185 ;
* V_186 = V_57 -> V_66 -> V_184 [ V_183 ] . V_187 ;
return 0 ;
}
static struct V_188 *
F_128 ( struct V_102 * V_103 , unsigned V_3 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
int V_59 ;
for ( V_59 = 0 ; V_59 < V_57 -> V_66 -> V_189 ; V_59 ++ ) {
struct V_188 * V_190 ;
V_190 = & V_57 -> V_66 -> V_191 [ V_59 ] ;
if ( V_3 >= V_190 -> V_192 &&
V_3 <= ( V_190 -> V_192 + V_190 -> V_187 - 1 ) )
return V_190 ;
}
return NULL ;
}
static void F_129 ( struct V_102 * V_103 , struct V_139 * V_140 ,
unsigned V_3 )
{
struct V_188 * V_190 ;
struct V_137 * V_45 ;
V_190 = F_128 ( V_103 , V_3 ) ;
if ( ! V_190 || ! V_190 -> V_193 ) {
F_90 ( V_140 , L_56 ) ;
return;
}
V_45 = V_190 -> V_193 ;
F_88 ( V_140 , V_103 , V_45 , V_3 - V_45 -> V_46 , V_3 ) ;
}
static int F_130 ( struct V_102 * V_103 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
return V_57 -> V_66 -> V_194 ;
}
static const char * F_131 ( struct V_102 * V_103 ,
unsigned V_195 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
return V_57 -> V_66 -> V_196 [ V_195 ] . V_177 ;
}
static int F_132 ( struct V_102 * V_103 ,
unsigned V_195 ,
const char * const * * V_184 ,
unsigned * const V_197 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
* V_184 = V_57 -> V_66 -> V_196 [ V_195 ] . V_184 ;
* V_197 = V_57 -> V_66 -> V_196 [ V_195 ] . V_182 ;
return 0 ;
}
static int F_133 ( struct V_102 * V_103 , unsigned V_195 ,
unsigned V_198 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
const struct V_199 * V_200 ;
static unsigned int V_15 [ V_90 ] ;
unsigned long V_96 ;
bool V_34 ;
int V_97 = - V_100 ;
int V_59 ;
V_200 = & V_57 -> V_66 -> V_184 [ V_198 ] ;
if ( V_200 -> V_201 < 0 )
return - V_100 ;
F_17 ( V_57 -> V_52 , L_57 , V_200 -> V_177 , V_200 -> V_187 ) ;
V_34 = ( ( V_200 -> V_201 & V_80 ) == V_80 ) ;
if ( V_34 ) {
F_38 ( & V_98 , V_96 ) ;
memset ( V_15 , 0xff , sizeof( V_15 ) ) ;
for ( V_59 = 0 ; V_59 < V_200 -> V_187 ; V_59 ++ )
V_15 [ V_200 -> V_185 [ V_59 ] / V_99 ] &= ~ F_7 ( V_200 -> V_185 [ V_59 ] ) ;
F_33 ( V_15 ) ;
}
for ( V_59 = 0 ; V_59 < V_200 -> V_187 ; V_59 ++ ) {
struct V_188 * V_190 ;
struct V_1 * V_2 ;
struct V_137 * V_45 ;
unsigned V_5 ;
V_190 = F_128 ( V_103 , V_200 -> V_185 [ V_59 ] ) ;
if ( ! V_190 ) {
F_20 ( V_57 -> V_52 ,
L_58 ,
V_200 -> V_185 [ V_59 ] , V_200 -> V_177 , V_59 ) ;
goto V_202;
}
if ( ! V_190 -> V_193 ) {
F_20 ( V_57 -> V_52 , L_59 ,
V_200 -> V_185 [ V_59 ] , V_200 -> V_177 , V_59 ) ;
goto V_202;
}
V_45 = V_190 -> V_193 ;
V_2 = F_82 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_57 -> V_52 , L_60 , V_200 -> V_185 [ V_59 ] , V_200 -> V_201 ) ;
F_34 ( V_2 -> V_93 ) ;
V_5 = V_200 -> V_185 [ V_59 ] % V_99 ;
F_13 ( V_2 , V_5 ) ;
F_12 ( V_2 , V_5 ,
( V_200 -> V_201 & V_80 ) , V_34 ) ;
F_36 ( V_2 -> V_93 ) ;
if ( ( V_200 -> V_201 & V_80 ) == V_80 )
F_19 ( V_57 , V_200 -> V_185 [ V_59 ] ,
V_200 -> V_201 >> V_203 ) ;
}
V_97 = 0 ;
V_202:
if ( V_34 ) {
F_35 ( V_15 ) ;
F_41 ( & V_98 , V_96 ) ;
}
return V_97 ;
}
static void F_134 ( struct V_102 * V_103 ,
unsigned V_195 , unsigned V_198 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
const struct V_199 * V_200 ;
V_200 = & V_57 -> V_66 -> V_184 [ V_198 ] ;
if ( V_200 -> V_201 < 0 )
return;
F_17 ( V_57 -> V_52 , L_61 , V_200 -> V_177 , V_200 -> V_187 ) ;
}
static int F_135 ( struct V_102 * V_103 ,
struct V_188 * V_190 ,
unsigned V_3 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
struct V_1 * V_2 ;
struct V_137 * V_45 ;
unsigned V_5 ;
if ( ! V_190 ) {
F_20 ( V_57 -> V_52 , L_62 ) ;
return - V_100 ;
}
if ( ! V_190 -> V_193 ) {
F_20 ( V_57 -> V_52 , L_63 ) ;
return - V_100 ;
}
V_45 = V_190 -> V_193 ;
V_2 = F_82 ( V_45 , struct V_1 , V_45 ) ;
F_17 ( V_57 -> V_52 , L_64 , V_3 ) ;
F_34 ( V_2 -> V_93 ) ;
V_5 = V_3 % V_99 ;
F_1 ( V_2 , V_5 , V_79 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static void F_136 ( struct V_102 * V_103 ,
struct V_188 * V_190 ,
unsigned V_3 )
{
struct V_56 * V_57 = F_49 ( V_103 ) ;
F_17 ( V_57 -> V_52 , L_65 , V_3 ) ;
}
static int F_137 ( struct V_102 * V_103 , unsigned V_69 ,
unsigned long * V_204 )
{
return - V_100 ;
}
static int F_138 ( struct V_102 * V_103 , unsigned V_69 ,
unsigned long V_204 )
{
static const char * V_81 [] = {
[ V_22 ] = L_11 ,
[ V_24 ] = L_12 ,
[ V_26 ] = L_13 ,
[ 3 ] = L_14
} ;
static const char * V_82 [] = {
[ V_83 ] = L_15 ,
[ V_17 ] = L_16 ,
} ;
struct V_56 * V_57 = F_49 ( V_103 ) ;
struct V_1 * V_2 ;
struct V_188 * V_190 ;
struct V_137 * V_45 ;
unsigned V_5 ;
T_5 V_75 = ( T_5 ) V_204 ;
int V_19 = F_24 ( V_75 ) ;
int V_15 = F_26 ( V_75 ) ;
int V_85 = F_27 ( V_75 ) ;
int V_32 = F_28 ( V_75 ) ;
bool V_28 = F_32 ( V_75 ) ;
bool V_205 = F_139 ( V_75 ) ;
bool V_76 = F_140 ( V_75 ) ;
V_190 = F_128 ( V_103 , V_69 ) ;
if ( ! V_190 ) {
F_20 ( V_57 -> V_52 , L_66 , V_69 ) ;
return - V_100 ;
}
if ( ! V_190 -> V_193 ) {
F_20 ( V_57 -> V_52 , L_67 ,
V_69 ) ;
return - V_100 ;
}
V_45 = V_190 -> V_193 ;
V_2 = F_82 ( V_45 , struct V_1 , V_45 ) ;
if ( V_76 ) {
int V_86 = F_29 ( V_75 ) ;
int V_87 = F_30 ( V_75 ) ;
int V_88 = F_31 ( V_75 ) ;
V_205 = true ;
if ( V_86 )
V_19 = V_86 - 1 ;
if ( V_87 )
V_85 = V_87 - 1 ;
if ( V_88 )
V_32 = V_88 - 1 ;
F_17 ( V_2 -> V_45 . V_52 , L_23 ,
V_69 ,
V_86 ? V_81 [ V_19 ] : L_24 ,
V_87 ? ( V_85 ? L_25 : L_19 ) : L_24 ,
V_88 ? ( V_32 ? L_20 : L_21 ) : L_24 ) ;
}
F_17 ( V_2 -> V_45 . V_52 , L_68 ,
V_69 , V_75 , V_81 [ V_19 ] , V_82 [ V_15 ] ,
V_85 ? L_18 : L_19 ,
V_85 ? ( V_32 ? L_20 : L_21 ) : L_22 ,
V_28 ? L_69 : L_70 ) ;
F_34 ( V_2 -> V_93 ) ;
V_5 = V_69 % V_99 ;
if ( V_205 )
F_1 ( V_2 , V_5 , V_79 ) ;
if ( V_85 )
F_11 ( V_2 , V_5 , V_32 ) ;
else {
F_9 ( V_2 , V_5 ) ;
F_5 ( V_2 , V_5 , V_19 ) ;
}
F_6 ( V_2 , V_5 , V_28 ) ;
F_4 ( V_2 , V_5 , V_15 ) ;
F_36 ( V_2 -> V_93 ) ;
return 0 ;
}
static int F_141 ( struct V_155 * V_206 )
{
const struct V_207 * V_208 = F_142 ( V_206 ) ;
struct V_159 * V_160 = V_206 -> V_52 . V_161 ;
struct V_56 * V_57 ;
struct V_162 * V_163 ;
unsigned int V_209 = 0 ;
int V_59 ;
V_57 = F_105 ( & V_206 -> V_52 , sizeof( * V_57 ) , V_167 ) ;
if ( ! V_57 )
return - V_168 ;
if ( V_208 )
V_209 = V_208 -> V_210 ;
else if ( V_160 ) {
const struct V_211 * V_212 ;
V_212 = F_143 ( V_213 , & V_206 -> V_52 ) ;
if ( ! V_212 )
return - V_166 ;
V_209 = ( unsigned int ) V_212 -> V_214 ;
}
if ( V_209 == V_215 )
F_144 ( & V_57 -> V_66 ) ;
if ( V_209 == V_216 )
F_145 ( & V_57 -> V_66 ) ;
if ( V_209 == V_217 )
F_146 ( & V_57 -> V_66 ) ;
V_163 = F_108 ( V_206 , V_174 , 0 ) ;
if ( V_163 ) {
V_57 -> V_64 = F_147 ( & V_206 -> V_52 , V_163 -> V_218 ,
F_148 ( V_163 ) ) ;
if ( ! V_57 -> V_64 ) {
F_20 ( & V_206 -> V_52 ,
L_71 ) ;
return - V_168 ;
}
} else if ( V_209 == V_215 ) {
F_124 ( & V_206 -> V_52 ,
L_72 ) ;
} else {
F_20 ( & V_206 -> V_52 , L_73 ) ;
return - V_100 ;
}
for ( V_59 = 0 ; V_59 < V_57 -> V_66 -> V_189 ; V_59 ++ ) {
if ( ! V_91 [ V_57 -> V_66 -> V_191 [ V_59 ] . V_170 ] ) {
F_21 ( & V_206 -> V_52 , L_74 , V_59 ) ;
return - V_219 ;
}
V_57 -> V_66 -> V_191 [ V_59 ] . V_193 = & V_91 [ V_57 -> V_66 -> V_191 [ V_59 ] . V_170 ] -> V_45 ;
}
V_220 . V_185 = V_57 -> V_66 -> V_185 ;
V_220 . V_187 = V_57 -> V_66 -> V_187 ;
V_57 -> V_52 = & V_206 -> V_52 ;
V_57 -> V_221 = F_149 ( & V_220 , & V_206 -> V_52 , V_57 ) ;
if ( ! V_57 -> V_221 ) {
F_20 ( & V_206 -> V_52 , L_75 ) ;
return - V_100 ;
}
for ( V_59 = 0 ; V_59 < V_57 -> V_66 -> V_189 ; V_59 ++ )
F_150 ( V_57 -> V_221 , & V_57 -> V_66 -> V_191 [ V_59 ] ) ;
F_122 ( V_206 , V_57 ) ;
F_124 ( & V_206 -> V_52 , L_76 ) ;
return 0 ;
}
static int T_8 F_151 ( void )
{
int V_97 ;
V_97 = F_152 ( & V_222 ) ;
if ( V_97 )
return V_97 ;
return F_152 ( & V_223 ) ;
}
