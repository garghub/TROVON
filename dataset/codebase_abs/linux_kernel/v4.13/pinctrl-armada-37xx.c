static inline void F_1 ( unsigned int * V_1 ,
unsigned int V_2 )
{
if ( V_2 >= V_3 ) {
V_2 -= V_3 ;
* V_1 += sizeof( V_4 ) ;
}
}
static int F_2 ( struct V_5 * V_6 ,
const char * V_7 )
{
int V_8 ;
for ( V_8 = 0 ; ( V_8 < V_9 ) && V_6 -> V_10 [ V_8 ] ; V_8 ++ )
if ( ! strcmp ( V_6 -> V_10 [ V_8 ] , V_7 ) )
return V_8 ;
return - V_11 ;
}
static struct V_5 * F_3 (
struct V_12 * V_13 , int V_14 , int * V_6 )
{
while ( * V_6 < V_13 -> V_15 ) {
struct V_5 * V_16 = & V_13 -> V_17 [ * V_6 ] ;
int V_18 ;
* V_6 = * V_6 + 1 ;
for ( V_18 = 0 ; V_18 < ( V_16 -> V_19 + V_16 -> V_20 ) ; V_18 ++ )
if ( V_16 -> V_21 [ V_18 ] == V_14 )
return V_16 ;
}
return NULL ;
}
static int F_4 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned long * V_25 )
{
return - V_11 ;
}
static int F_5 ( struct V_22 * V_23 ,
unsigned int V_24 , unsigned long * V_26 ,
unsigned int V_27 )
{
return - V_11 ;
}
static int F_6 ( struct V_22 * V_23 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_15 ;
}
static const char * F_8 ( struct V_22 * V_23 ,
unsigned int V_16 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_17 [ V_16 ] . V_28 ;
}
static int F_9 ( struct V_22 * V_23 ,
unsigned int V_24 ,
const unsigned int * * V_21 ,
unsigned int * V_19 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
if ( V_24 >= V_13 -> V_15 )
return - V_29 ;
* V_21 = V_13 -> V_17 [ V_24 ] . V_21 ;
* V_19 = V_13 -> V_17 [ V_24 ] . V_19 +
V_13 -> V_17 [ V_24 ] . V_20 ;
return 0 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_30 ;
}
static const char * F_11 ( struct V_22 * V_23 ,
unsigned int V_24 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
return V_13 -> V_10 [ V_24 ] . V_28 ;
}
static int F_12 ( struct V_22 * V_23 ,
unsigned int V_24 ,
const char * const * * V_17 ,
unsigned int * const V_31 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
* V_17 = V_13 -> V_10 [ V_24 ] . V_17 ;
* V_31 = V_13 -> V_10 [ V_24 ] . V_15 ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 ,
const char * V_28 ,
struct V_5 * V_6 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
unsigned int V_1 = V_32 ;
unsigned int V_33 = V_6 -> V_34 ;
int V_7 , V_35 ;
F_14 ( V_13 -> V_36 , L_1 ,
V_28 , V_6 -> V_28 ) ;
V_7 = F_2 ( V_6 , V_28 ) ;
if ( V_7 < 0 )
return V_7 ;
V_35 = V_6 -> V_35 [ V_7 ] ;
F_15 ( V_13 -> V_37 , V_1 , V_33 , V_35 ) ;
return 0 ;
}
static int F_16 ( struct V_22 * V_23 ,
unsigned int V_24 ,
unsigned int V_16 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
struct V_5 * V_6 = & V_13 -> V_17 [ V_16 ] ;
const char * V_28 = V_13 -> V_10 [ V_24 ] . V_28 ;
return F_13 ( V_23 , V_28 , V_6 ) ;
}
static inline void F_17 ( unsigned int * V_1 ,
struct V_38 * V_39 )
{
int V_2 = F_18 ( V_39 ) ;
F_1 ( V_1 , V_2 ) ;
}
static int F_19 ( struct V_40 * V_41 ,
unsigned int V_2 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
unsigned int V_1 = V_42 ;
unsigned int V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_21 ( V_2 ) ;
return F_15 ( V_13 -> V_37 , V_1 , V_33 , 0 ) ;
}
static int F_22 ( struct V_40 * V_41 ,
unsigned int V_2 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
unsigned int V_1 = V_42 ;
unsigned int V_35 , V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_21 ( V_2 ) ;
F_23 ( V_13 -> V_37 , V_1 , & V_35 ) ;
return ! ( V_35 & V_33 ) ;
}
static int F_24 ( struct V_40 * V_41 ,
unsigned int V_2 , int V_43 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
unsigned int V_1 = V_42 ;
unsigned int V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_21 ( V_2 ) ;
return F_15 ( V_13 -> V_37 , V_1 , V_33 , V_33 ) ;
}
static int F_25 ( struct V_40 * V_41 , unsigned int V_2 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
unsigned int V_1 = V_44 ;
unsigned int V_35 , V_33 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_21 ( V_2 ) ;
F_23 ( V_13 -> V_37 , V_1 , & V_35 ) ;
return ( V_35 & V_33 ) != 0 ;
}
static void F_26 ( struct V_40 * V_41 , unsigned int V_2 ,
int V_43 )
{
struct V_12 * V_13 = F_20 ( V_41 ) ;
unsigned int V_1 = V_45 ;
unsigned int V_33 , V_35 ;
F_1 ( & V_1 , V_2 ) ;
V_33 = F_21 ( V_2 ) ;
V_35 = V_43 ? V_33 : 0 ;
F_15 ( V_13 -> V_37 , V_1 , V_33 , V_35 ) ;
}
static int F_27 ( struct V_22 * V_23 ,
struct V_46 * V_47 ,
unsigned int V_2 , bool V_48 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
struct V_40 * V_41 = V_47 -> V_49 ;
F_14 ( V_13 -> V_36 , L_2 ,
V_2 , V_47 -> V_28 , V_2 , V_48 ? L_3 : L_4 ) ;
if ( V_48 )
F_19 ( V_41 , V_2 ) ;
else
F_24 ( V_41 , V_2 , 0 ) ;
return 0 ;
}
static int F_28 ( struct V_22 * V_23 ,
struct V_46 * V_47 ,
unsigned int V_2 )
{
struct V_12 * V_13 = F_7 ( V_23 ) ;
struct V_5 * V_16 ;
int V_6 = 0 ;
F_14 ( V_13 -> V_36 , L_5 , V_2 ) ;
while ( ( V_16 = F_3 ( V_13 , V_2 , & V_6 ) ) )
F_13 ( V_23 , L_6 , V_16 ) ;
return 0 ;
}
static void F_29 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_30 ( V_39 ) ;
struct V_12 * V_13 = F_20 ( V_41 ) ;
V_4 V_1 = V_50 ;
unsigned long V_51 ;
F_17 ( & V_1 , V_39 ) ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
F_32 ( V_39 -> V_33 , V_13 -> V_53 + V_1 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
}
static void F_34 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_30 ( V_39 ) ;
struct V_12 * V_13 = F_20 ( V_41 ) ;
V_4 V_35 , V_1 = V_54 ;
unsigned long V_51 ;
F_17 ( & V_1 , V_39 ) ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
V_35 = F_35 ( V_13 -> V_53 + V_1 ) ;
F_32 ( V_35 & ~ V_39 -> V_33 , V_13 -> V_53 + V_1 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
}
static void F_36 ( struct V_38 * V_39 )
{
struct V_40 * V_41 = F_30 ( V_39 ) ;
struct V_12 * V_13 = F_20 ( V_41 ) ;
V_4 V_35 , V_1 = V_54 ;
unsigned long V_51 ;
F_17 ( & V_1 , V_39 ) ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
V_35 = F_35 ( V_13 -> V_53 + V_1 ) ;
F_32 ( V_35 | V_39 -> V_33 , V_13 -> V_53 + V_1 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
}
static int F_37 ( struct V_38 * V_39 , unsigned int V_55 )
{
struct V_40 * V_41 = F_30 ( V_39 ) ;
struct V_12 * V_13 = F_20 ( V_41 ) ;
V_4 V_35 , V_1 = V_56 ;
unsigned long V_51 ;
F_17 ( & V_1 , V_39 ) ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
V_35 = F_35 ( V_13 -> V_53 + V_1 ) ;
if ( V_55 )
V_35 |= V_39 -> V_33 ;
else
V_35 &= ~ V_39 -> V_33 ;
F_32 ( V_35 , V_13 -> V_53 + V_1 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
return 0 ;
}
static int F_38 ( struct V_38 * V_39 , unsigned int type )
{
struct V_40 * V_41 = F_30 ( V_39 ) ;
struct V_12 * V_13 = F_20 ( V_41 ) ;
V_4 V_35 , V_1 = V_57 ;
unsigned long V_51 ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
F_17 ( & V_1 , V_39 ) ;
V_35 = F_35 ( V_13 -> V_53 + V_1 ) ;
switch ( type ) {
case V_58 :
V_35 &= ~ V_39 -> V_33 ;
break;
case V_59 :
V_35 |= V_39 -> V_33 ;
break;
default:
F_33 ( & V_13 -> V_52 , V_51 ) ;
return - V_29 ;
}
F_32 ( V_35 , V_13 -> V_53 + V_1 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
return 0 ;
}
static void F_39 ( struct V_60 * V_61 )
{
struct V_40 * V_49 = F_40 ( V_61 ) ;
struct V_62 * V_41 = F_41 ( V_61 ) ;
struct V_12 * V_13 = F_20 ( V_49 ) ;
struct V_63 * V_39 = V_49 -> V_64 ;
int V_65 ;
F_42 ( V_41 , V_61 ) ;
for ( V_65 = 0 ; V_65 <= V_39 -> V_66 / V_3 ; V_65 ++ ) {
V_4 V_67 ;
unsigned long V_51 ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
V_67 = F_43 ( V_13 -> V_53 + V_50 + 4 * V_65 ) ;
V_67 &= F_43 ( V_13 -> V_53 + V_54 + 4 * V_65 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
while ( V_67 ) {
V_4 V_68 = F_44 ( V_67 ) - 1 ;
V_4 V_69 = F_45 ( V_39 , V_68 +
V_65 * V_3 ) ;
F_46 ( V_69 ) ;
F_31 ( & V_13 -> V_52 , V_51 ) ;
V_67 = F_43 ( V_13 -> V_53 +
V_50 + 4 * V_65 ) ;
V_67 &= F_43 ( V_13 -> V_53 + V_54 + 4 * V_65 ) ;
F_33 ( & V_13 -> V_52 , V_51 ) ;
}
}
F_47 ( V_41 , V_61 ) ;
}
static int F_48 ( struct V_70 * V_71 ,
struct V_12 * V_13 )
{
struct V_72 * V_73 = V_13 -> V_36 -> V_74 ;
int V_75 = V_13 -> V_76 -> V_77 ;
struct V_40 * V_49 = & V_13 -> V_40 ;
struct V_62 * V_78 = & V_13 -> V_62 ;
struct V_79 V_80 ;
int V_81 = - V_82 , V_65 , V_83 ;
F_49 (info->dev->of_node, np) {
if ( F_50 ( V_73 , L_7 ) ) {
V_81 = 0 ;
break;
}
} ;
if ( V_81 )
return V_81 ;
V_83 = F_51 ( V_73 ) ;
F_52 ( & V_13 -> V_52 ) ;
if ( ! V_83 ) {
F_53 ( & V_71 -> V_36 , L_8 ) ;
return 0 ;
}
if ( F_54 ( V_13 -> V_36 -> V_74 , 1 , & V_80 ) ) {
F_53 ( V_13 -> V_36 , L_9 ) ;
return - V_84 ;
}
V_13 -> V_53 = F_55 ( V_13 -> V_36 , & V_80 ) ;
if ( F_56 ( V_13 -> V_53 ) )
return F_57 ( V_13 -> V_53 ) ;
V_78 -> V_85 = F_29 ;
V_78 -> V_86 = F_34 ;
V_78 -> V_87 = F_36 ;
V_78 -> V_88 = F_37 ;
V_78 -> V_89 = F_38 ;
V_78 -> V_28 = V_13 -> V_76 -> V_28 ;
V_81 = F_58 ( V_49 , V_78 , 0 ,
V_90 , V_91 ) ;
if ( V_81 ) {
F_59 ( & V_71 -> V_36 , L_10 ) ;
return V_81 ;
}
for ( V_65 = 0 ; V_65 < V_75 ; V_65 ++ ) {
struct V_38 * V_39 = F_60 ( V_49 -> V_92 + V_65 ) ;
V_39 -> V_33 = F_21 ( V_65 % V_3 ) ;
}
for ( V_65 = 0 ; V_65 < V_83 ; V_65 ++ ) {
int V_93 = F_61 ( V_73 , V_65 ) ;
if ( V_93 < 0 )
continue;
F_62 ( V_49 , V_78 , V_93 ,
F_39 ) ;
}
return 0 ;
}
static int F_63 ( struct V_70 * V_71 ,
struct V_12 * V_13 )
{
struct V_72 * V_73 ;
struct V_40 * V_49 ;
int V_81 = - V_82 ;
F_49 (info->dev->of_node, np) {
if ( F_64 ( V_73 , L_7 , NULL ) ) {
V_81 = 0 ;
break;
}
} ;
if ( V_81 )
return V_81 ;
V_13 -> V_40 = V_94 ;
V_49 = & V_13 -> V_40 ;
V_49 -> V_95 = V_13 -> V_76 -> V_77 ;
V_49 -> V_96 = & V_71 -> V_36 ;
V_49 -> V_53 = - 1 ;
V_49 -> V_74 = V_73 ;
V_49 -> V_97 = V_13 -> V_76 -> V_28 ;
V_81 = F_65 ( & V_71 -> V_36 , V_49 , V_13 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_48 ( V_71 , V_13 ) ;
if ( V_81 )
return V_81 ;
return 0 ;
}
static int F_66 ( struct V_98 * V_10 ,
int * V_99 , const char * V_28 )
{
int V_65 = 0 ;
if ( * V_99 <= 0 )
return - V_100 ;
while ( V_10 -> V_15 ) {
if ( strcmp ( V_10 -> V_28 , V_28 ) == 0 ) {
V_10 -> V_15 ++ ;
return - V_101 ;
}
V_10 ++ ;
V_65 ++ ;
}
V_10 -> V_28 = V_28 ;
V_10 -> V_15 = 1 ;
( * V_99 ) -- ;
return 0 ;
}
static int F_67 ( struct V_12 * V_13 )
{
int V_102 , V_103 = 0 , V_99 = V_13 -> V_76 -> V_77 ;
for ( V_102 = 0 ; V_102 < V_13 -> V_15 ; V_102 ++ ) {
struct V_5 * V_6 = & V_13 -> V_17 [ V_102 ] ;
int V_65 , V_18 , V_8 ;
V_6 -> V_21 = F_68 ( V_13 -> V_36 ,
( V_6 -> V_19 + V_6 -> V_20 ) *
sizeof( * V_6 -> V_21 ) , V_104 ) ;
if ( ! V_6 -> V_21 )
return - V_105 ;
for ( V_65 = 0 ; V_65 < V_6 -> V_19 ; V_65 ++ )
V_6 -> V_21 [ V_65 ] = V_6 -> V_106 + V_65 ;
for ( V_18 = 0 ; V_18 < V_6 -> V_20 ; V_18 ++ )
V_6 -> V_21 [ V_65 + V_18 ] = V_6 -> V_107 + V_18 ;
for ( V_8 = 0 ; ( V_8 < V_9 ) && V_6 -> V_10 [ V_8 ] ; V_8 ++ ) {
int V_81 ;
V_81 = F_66 ( V_13 -> V_10 , & V_99 ,
V_6 -> V_10 [ V_8 ] ) ;
if ( V_81 == - V_100 )
F_53 ( V_13 -> V_36 ,
L_11 ,
V_13 -> V_76 -> V_77 ) ;
if ( V_81 < 0 )
continue;
V_103 ++ ;
}
}
V_13 -> V_30 = V_103 ;
return 0 ;
}
static int F_69 ( struct V_12 * V_13 )
{
struct V_98 * V_10 = V_13 -> V_10 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < V_13 -> V_30 ; V_102 ++ ) {
const char * V_28 = V_10 [ V_102 ] . V_28 ;
const char * * V_17 ;
int V_108 ;
V_10 [ V_102 ] . V_17 = F_68 ( V_13 -> V_36 , V_10 [ V_102 ] . V_15 *
sizeof( * ( V_10 [ V_102 ] . V_17 ) ) ,
V_104 ) ;
if ( ! V_10 [ V_102 ] . V_17 )
return - V_105 ;
V_17 = V_10 [ V_102 ] . V_17 ;
for ( V_108 = 0 ; V_108 < V_13 -> V_15 ; V_108 ++ ) {
struct V_5 * V_109 = & V_13 -> V_17 [ V_108 ] ;
int V_8 ;
for ( V_8 = 0 ; ( V_8 < V_9 ) && V_109 -> V_10 [ V_8 ] ; V_8 ++ ) {
if ( strcmp ( V_109 -> V_10 [ V_8 ] , V_28 ) == 0 ) {
* V_17 = V_109 -> V_28 ;
V_17 ++ ;
}
}
}
}
return 0 ;
}
static int F_70 ( struct V_70 * V_71 ,
struct V_12 * V_13 )
{
const struct V_110 * V_111 = V_13 -> V_76 ;
struct V_112 * V_113 = & V_13 -> V_114 ;
struct V_115 * V_116 , * V_117 ;
int V_14 , V_81 ;
V_13 -> V_17 = V_111 -> V_17 ;
V_13 -> V_15 = V_111 -> V_15 ;
V_113 -> V_28 = L_12 ;
V_113 -> V_118 = V_119 ;
V_113 -> V_120 = & V_121 ;
V_113 -> V_122 = & V_123 ;
V_113 -> V_124 = & V_125 ;
V_116 = F_68 ( & V_71 -> V_36 , sizeof( * V_116 ) *
V_111 -> V_77 , V_104 ) ;
if ( ! V_116 )
return - V_105 ;
V_113 -> V_21 = V_116 ;
V_113 -> V_19 = V_111 -> V_77 ;
V_117 = V_116 ;
for ( V_14 = 0 ; V_14 < V_111 -> V_77 ; V_14 ++ ) {
V_117 -> V_126 = V_14 ;
V_117 -> V_28 = F_71 ( V_104 , L_13 ,
V_111 -> V_28 , V_14 ) ;
V_117 ++ ;
}
V_13 -> V_10 = F_68 ( & V_71 -> V_36 , V_111 -> V_77 *
sizeof( struct V_98 ) , V_104 ) ;
if ( ! V_13 -> V_10 )
return - V_105 ;
V_81 = F_67 ( V_13 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_69 ( V_13 ) ;
if ( V_81 )
return V_81 ;
V_13 -> V_127 = F_72 ( & V_71 -> V_36 , V_113 , V_13 ) ;
if ( F_56 ( V_13 -> V_127 ) ) {
F_53 ( & V_71 -> V_36 , L_14 ) ;
return F_57 ( V_13 -> V_127 ) ;
}
return 0 ;
}
static int T_1 F_73 ( struct V_70 * V_71 )
{
struct V_12 * V_13 ;
struct V_128 * V_36 = & V_71 -> V_36 ;
struct V_72 * V_73 = V_36 -> V_74 ;
struct V_37 * V_37 ;
int V_81 ;
V_13 = F_68 ( V_36 , sizeof( struct V_12 ) ,
V_104 ) ;
if ( ! V_13 )
return - V_105 ;
V_13 -> V_36 = V_36 ;
V_37 = F_74 ( V_73 ) ;
if ( F_56 ( V_37 ) ) {
F_53 ( & V_71 -> V_36 , L_15 ) ;
return F_57 ( V_37 ) ;
}
V_13 -> V_37 = V_37 ;
V_13 -> V_76 = F_75 ( V_36 ) ;
V_81 = F_70 ( V_71 , V_13 ) ;
if ( V_81 )
return V_81 ;
V_81 = F_63 ( V_71 , V_13 ) ;
if ( V_81 )
return V_81 ;
F_76 ( V_71 , V_13 ) ;
return 0 ;
}
