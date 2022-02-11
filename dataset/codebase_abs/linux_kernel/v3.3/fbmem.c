static struct V_1 * F_1 ( unsigned int V_2 )
{
struct V_1 * V_1 ;
if ( V_2 >= V_3 )
return F_2 ( - V_4 ) ;
F_3 ( & V_5 ) ;
V_1 = V_6 [ V_2 ] ;
if ( V_1 )
F_4 ( & V_1 -> V_7 ) ;
F_5 ( & V_5 ) ;
return V_1 ;
}
static void F_6 ( struct V_1 * V_1 )
{
if ( ! F_7 ( & V_1 -> V_7 ) )
return;
if ( V_1 -> V_8 -> V_9 )
V_1 -> V_8 -> V_9 ( V_1 ) ;
}
int F_8 ( struct V_1 * V_10 )
{
F_3 ( & V_10 -> V_11 ) ;
if ( ! V_10 -> V_8 ) {
F_5 ( & V_10 -> V_11 ) ;
return 0 ;
}
return 1 ;
}
int F_9 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
int V_16 = 0 ;
if ( V_15 -> V_17 == V_18 ||
V_15 -> V_17 == V_19 )
V_16 = 1 ;
else {
if ( V_13 -> V_20 . V_21 == V_13 -> V_22 . V_21 &&
V_13 -> V_20 . V_21 == V_13 -> V_23 . V_21 &&
V_13 -> V_20 . V_24 == V_13 -> V_22 . V_24 &&
V_13 -> V_20 . V_24 == V_13 -> V_23 . V_24 )
V_16 = V_13 -> V_20 . V_21 ;
else
V_16 = V_13 -> V_20 . V_21 + V_13 -> V_23 . V_21 +
V_13 -> V_22 . V_21 ;
}
return V_16 ;
}
void F_10 ( T_1 * V_25 , T_2 V_26 , T_1 * V_27 , T_2 V_28 , T_2 V_29 )
{
F_11 ( V_25 , V_26 , V_27 , V_28 , V_29 ) ;
}
void F_12 ( T_1 * V_25 , T_2 V_26 , T_1 * V_27 , T_2 V_2 , T_2 V_29 ,
T_2 V_30 , T_2 V_31 , T_2 V_32 )
{
T_1 V_33 = ( T_1 ) ( 0xfff << V_30 ) , V_34 ;
int V_35 , V_36 ;
for ( V_35 = V_29 ; V_35 -- ; ) {
for ( V_36 = 0 ; V_36 < V_2 ; V_36 ++ ) {
V_34 = V_25 [ V_36 ] ;
V_34 &= V_33 ;
V_34 |= * V_27 >> V_31 ;
V_25 [ V_36 ] = V_34 ;
V_34 = * V_27 << V_30 ;
V_25 [ V_36 + 1 ] = V_34 ;
V_27 ++ ;
}
V_34 = V_25 [ V_2 ] ;
V_34 &= V_33 ;
V_34 |= * V_27 >> V_31 ;
V_25 [ V_2 ] = V_34 ;
if ( V_30 < V_32 ) {
V_34 = * V_27 << V_30 ;
V_25 [ V_2 + 1 ] = V_34 ;
}
V_27 ++ ;
V_25 += V_26 ;
}
}
char * F_13 ( struct V_1 * V_10 , struct V_37 * V_38 , T_2 V_39 )
{
T_2 V_40 = V_38 -> V_41 - 1 , V_24 ;
char * V_42 = V_38 -> V_42 ;
if ( V_38 -> V_43 & V_44 ) {
if ( V_10 -> V_8 -> V_45 && ( V_38 -> V_43 & V_46 ) )
V_10 -> V_8 -> V_45 ( V_10 ) ;
return V_42 ;
}
V_24 = V_38 -> V_24 + V_40 ;
V_24 &= ~ V_40 ;
if ( V_24 + V_39 > V_38 -> V_39 ) {
if ( V_10 -> V_8 -> V_45 && ( V_38 -> V_43 & V_46 ) )
V_10 -> V_8 -> V_45 ( V_10 ) ;
V_24 = 0 ;
}
V_38 -> V_24 = V_24 + V_39 ;
V_42 += V_24 ;
return V_42 ;
}
static inline unsigned F_14 ( unsigned V_47 , int V_48 )
{
return V_48 < 0 ? V_47 > > - V_48 : V_47 << V_48 ;
}
static void F_15 ( struct V_1 * V_10 ,
const struct V_49 * V_50 )
{
struct V_51 V_52 ;
T_3 V_53 [ 16 ] ;
T_3 V_54 [ 16 ] ;
T_3 V_55 [ 16 ] ;
int V_35 , V_36 , V_48 ;
const unsigned char * V_56 = V_50 -> V_56 ;
V_52 . V_57 = 0 ;
V_52 . V_58 = 16 ;
V_52 . V_23 = V_55 ;
V_52 . V_20 = V_53 ;
V_52 . V_22 = V_54 ;
V_52 . V_59 = NULL ;
for ( V_35 = 0 ; V_35 < V_50 -> V_60 ; V_35 += V_48 ) {
V_48 = V_50 -> V_60 - V_35 ;
if ( V_48 > 16 )
V_48 = 16 ;
V_52 . V_57 = 32 + V_35 ;
V_52 . V_58 = V_48 ;
for ( V_36 = 0 ; V_36 < V_48 ; ++ V_36 ) {
V_52 . V_23 [ V_36 ] = V_56 [ 0 ] << 8 | V_56 [ 0 ] ;
V_52 . V_20 [ V_36 ] = V_56 [ 1 ] << 8 | V_56 [ 1 ] ;
V_52 . V_22 [ V_36 ] = V_56 [ 2 ] << 8 | V_56 [ 2 ] ;
V_56 += 3 ;
}
F_16 ( & V_52 , V_10 ) ;
}
}
static void F_17 ( struct V_1 * V_10 ,
const struct V_49 * V_50 ,
T_2 * V_61 )
{
static const unsigned char V_33 [] = { 0 , 0x80 , 0xc0 , 0xe0 , 0xf0 , 0xf8 , 0xfc , 0xfe , 0xff } ;
unsigned char V_62 , V_63 , V_64 ;
int V_65 , V_66 , V_67 ;
int V_35 ;
const unsigned char * V_56 = V_50 -> V_56 ;
V_62 = V_33 [ V_10 -> V_13 . V_23 . V_21 < 8 ? V_10 -> V_13 . V_23 . V_21 : 8 ] ;
V_63 = V_33 [ V_10 -> V_13 . V_20 . V_21 < 8 ? V_10 -> V_13 . V_20 . V_21 : 8 ] ;
V_64 = V_33 [ V_10 -> V_13 . V_22 . V_21 < 8 ? V_10 -> V_13 . V_22 . V_21 : 8 ] ;
V_65 = V_10 -> V_13 . V_23 . V_24 - ( 8 - V_10 -> V_13 . V_23 . V_21 ) ;
V_66 = V_10 -> V_13 . V_20 . V_24 - ( 8 - V_10 -> V_13 . V_20 . V_21 ) ;
V_67 = V_10 -> V_13 . V_22 . V_24 - ( 8 - V_10 -> V_13 . V_22 . V_21 ) ;
for ( V_35 = 0 ; V_35 < V_50 -> V_60 ; V_35 ++ ) {
V_61 [ V_35 + 32 ] = ( F_14 ( ( V_56 [ 0 ] & V_62 ) , V_65 ) |
F_14 ( ( V_56 [ 1 ] & V_63 ) , V_66 ) |
F_14 ( ( V_56 [ 2 ] & V_64 ) , V_67 ) ) ;
V_56 += 3 ;
}
}
static void F_18 ( struct V_1 * V_10 ,
const struct V_49 * V_50 ,
T_2 * V_61 )
{
int V_65 , V_66 , V_67 ;
int V_35 ;
V_65 = V_10 -> V_13 . V_23 . V_24 ;
V_66 = V_10 -> V_13 . V_20 . V_24 ;
V_67 = V_10 -> V_13 . V_22 . V_24 ;
for ( V_35 = 32 ; V_35 < 32 + V_50 -> V_60 ; V_35 ++ )
V_61 [ V_35 ] = V_35 << V_65 | V_35 << V_66 | V_35 << V_67 ;
}
static void F_19 ( struct V_1 * V_10 ,
const struct V_49 * V_50 , T_1 * V_25 ,
int V_16 )
{
int V_35 , V_36 , V_68 ;
const T_1 * V_27 = V_50 -> V_69 ;
T_1 V_70 = ( V_10 -> V_15 . V_17 == V_18 ) ? 0xff : 0 ;
T_1 V_71 = 1 , V_47 ;
switch ( F_9 ( & V_10 -> V_13 , & V_10 -> V_15 ) ) {
case 1 :
V_71 = 1 ;
break;
case 2 :
V_71 = 3 ;
break;
default:
V_71 = 7 ;
break;
}
if ( V_10 -> V_15 . V_17 == V_18 ||
V_10 -> V_15 . V_17 == V_19 )
V_71 = ~ ( ( T_1 ) ( 0xfff << V_10 -> V_13 . V_20 . V_21 ) ) ;
switch ( V_16 ) {
case 4 :
for ( V_35 = 0 ; V_35 < V_50 -> V_29 ; V_35 ++ )
for ( V_36 = 0 ; V_36 < V_50 -> V_72 ; V_27 ++ ) {
* V_25 ++ = * V_27 >> 4 ;
V_36 ++ ;
if ( V_36 < V_50 -> V_72 ) {
* V_25 ++ = * V_27 & 0x0f ;
V_36 ++ ;
}
}
break;
case 1 :
for ( V_35 = 0 ; V_35 < V_50 -> V_29 ; V_35 ++ ) {
for ( V_36 = 0 ; V_36 < V_50 -> V_72 ; V_27 ++ ) {
V_47 = * V_27 ^ V_70 ;
for ( V_68 = 7 ; V_68 >= 0 ; V_68 -- ) {
* V_25 ++ = ( ( V_47 >> V_68 ) & 1 ) ? V_71 : 0 ;
V_36 ++ ;
}
}
}
break;
}
}
static void F_20 ( const T_1 * V_73 , T_1 * V_74 , T_2 V_72 , T_2 V_29 )
{
T_2 V_39 = V_72 * V_29 , V_35 ;
V_74 += V_39 - 1 ;
for ( V_35 = V_39 ; V_35 -- ; )
* V_74 -- = * V_73 ++ ;
}
static void F_21 ( const T_1 * V_73 , T_1 * V_74 , T_2 V_72 , T_2 V_29 )
{
int V_35 , V_36 , V_75 = V_29 - 1 ;
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ )
for ( V_36 = 0 ; V_36 < V_72 ; V_36 ++ )
V_74 [ V_29 * V_36 + V_75 - V_35 ] = * V_73 ++ ;
}
static void F_22 ( const T_1 * V_73 , T_1 * V_74 , T_2 V_72 , T_2 V_29 )
{
int V_35 , V_36 , V_76 = V_72 - 1 ;
for ( V_35 = 0 ; V_35 < V_29 ; V_35 ++ )
for ( V_36 = 0 ; V_36 < V_72 ; V_36 ++ )
V_74 [ V_29 * ( V_76 - V_36 ) + V_35 ] = * V_73 ++ ;
}
static void F_23 ( struct V_1 * V_10 , T_1 * V_25 ,
struct V_77 * V_78 , int V_79 )
{
T_2 V_34 ;
if ( V_79 == V_80 ) {
F_20 ( V_78 -> V_69 , V_25 , V_78 -> V_72 ,
V_78 -> V_29 ) ;
V_78 -> V_81 = V_10 -> V_13 . V_82 - V_78 -> V_72 - V_78 -> V_81 ;
V_78 -> V_83 = V_10 -> V_13 . V_84 - V_78 -> V_29 - V_78 -> V_83 ;
} else if ( V_79 == V_85 ) {
F_21 ( V_78 -> V_69 , V_25 , V_78 -> V_72 ,
V_78 -> V_29 ) ;
V_34 = V_78 -> V_72 ;
V_78 -> V_72 = V_78 -> V_29 ;
V_78 -> V_29 = V_34 ;
V_34 = V_78 -> V_83 ;
V_78 -> V_83 = V_78 -> V_81 ;
V_78 -> V_81 = V_10 -> V_13 . V_82 - V_78 -> V_72 - V_34 ;
} else if ( V_79 == V_86 ) {
F_22 ( V_78 -> V_69 , V_25 , V_78 -> V_72 ,
V_78 -> V_29 ) ;
V_34 = V_78 -> V_72 ;
V_78 -> V_72 = V_78 -> V_29 ;
V_78 -> V_29 = V_34 ;
V_34 = V_78 -> V_81 ;
V_78 -> V_81 = V_78 -> V_83 ;
V_78 -> V_83 = V_10 -> V_13 . V_84 - V_78 -> V_29 - V_34 ;
}
V_78 -> V_69 = V_25 ;
}
static void F_24 ( struct V_1 * V_10 , struct V_77 * V_78 ,
int V_79 , unsigned int V_87 )
{
unsigned int V_88 ;
if ( V_79 == V_89 ) {
for ( V_88 = 0 ;
V_88 < V_87 && V_78 -> V_81 + V_78 -> V_72 <= V_10 -> V_13 . V_82 ;
V_88 ++ ) {
V_10 -> V_8 -> V_90 ( V_10 , V_78 ) ;
V_78 -> V_81 += V_78 -> V_72 + 8 ;
}
} else if ( V_79 == V_80 ) {
for ( V_88 = 0 ; V_88 < V_87 && V_78 -> V_81 >= 0 ; V_88 ++ ) {
V_10 -> V_8 -> V_90 ( V_10 , V_78 ) ;
V_78 -> V_81 -= V_78 -> V_72 + 8 ;
}
} else if ( V_79 == V_85 ) {
for ( V_88 = 0 ;
V_88 < V_87 && V_78 -> V_83 + V_78 -> V_29 <= V_10 -> V_13 . V_84 ;
V_88 ++ ) {
V_10 -> V_8 -> V_90 ( V_10 , V_78 ) ;
V_78 -> V_83 += V_78 -> V_29 + 8 ;
}
} else if ( V_79 == V_86 ) {
for ( V_88 = 0 ; V_88 < V_87 && V_78 -> V_83 >= 0 ; V_88 ++ ) {
V_10 -> V_8 -> V_90 ( V_10 , V_78 ) ;
V_78 -> V_83 -= V_78 -> V_29 + 8 ;
}
}
}
static int F_25 ( struct V_1 * V_10 , int V_79 ,
const struct V_49 * V_50 , int V_91 ,
unsigned int V_48 )
{
T_2 * V_61 = NULL , * V_92 = NULL ;
unsigned char * V_93 = NULL , * V_94 = NULL ;
struct V_77 V_78 ;
if ( V_50 == NULL || V_10 -> V_95 != V_96 ||
V_10 -> V_43 & V_97 )
return 0 ;
V_78 . V_16 = 8 ;
V_78 . V_69 = V_50 -> V_69 ;
if ( V_98 . V_99 )
F_15 ( V_10 , V_50 ) ;
if ( V_98 . V_100 ||
V_98 . V_101 ) {
V_61 = F_26 ( 256 * 4 , V_102 ) ;
if ( V_61 == NULL )
return 0 ;
if ( V_98 . V_100 )
F_17 ( V_10 , V_50 , V_61 ) ;
else
F_18 ( V_10 , V_50 , V_61 ) ;
V_92 = V_10 -> V_103 ;
V_10 -> V_103 = V_61 ;
}
if ( V_98 . V_16 <= 4 ) {
V_93 = F_26 ( V_50 -> V_72 * V_50 -> V_29 , V_102 ) ;
if ( V_93 == NULL ) {
F_27 ( V_61 ) ;
if ( V_92 )
V_10 -> V_103 = V_92 ;
return 0 ;
}
V_78 . V_69 = V_93 ;
F_19 ( V_10 , V_50 , V_93 , V_98 . V_16 ) ;
}
V_78 . V_81 = 0 ;
V_78 . V_83 = V_91 ;
V_78 . V_72 = V_50 -> V_72 ;
V_78 . V_29 = V_50 -> V_29 ;
if ( V_79 ) {
V_94 = F_26 ( V_50 -> V_72 *
V_50 -> V_29 , V_102 ) ;
if ( V_94 )
F_23 ( V_10 , V_94 , & V_78 , V_79 ) ;
}
F_24 ( V_10 , & V_78 , V_79 , V_48 ) ;
F_27 ( V_61 ) ;
if ( V_92 != NULL )
V_10 -> V_103 = V_92 ;
F_27 ( V_93 ) ;
F_27 ( V_94 ) ;
return V_50 -> V_29 ;
}
void F_28 ( const struct V_49 * V_50 , unsigned int V_48 )
{
if ( ! V_48 || V_104 == V_105 )
return;
V_106 [ V_104 ] . V_50 = V_50 ;
V_106 [ V_104 ] . V_48 = V_48 ;
V_104 ++ ;
}
static int F_29 ( struct V_1 * V_10 , unsigned int V_29 ,
unsigned int V_84 )
{
unsigned int V_35 ;
if ( V_10 -> V_15 . V_17 != V_107 )
V_104 = 0 ;
for ( V_35 = 0 ; V_35 < V_104 ; V_35 ++ ) {
if ( V_106 [ V_35 ] . V_50 -> type != V_98 . V_50 -> type ) {
V_106 [ V_35 ] . V_50 = NULL ;
continue;
}
V_29 += V_106 [ V_35 ] . V_50 -> V_29 ;
if ( V_29 > V_84 ) {
V_29 -= V_106 [ V_35 ] . V_50 -> V_29 ;
V_104 = V_35 ;
break;
}
}
return V_29 ;
}
static int F_30 ( struct V_1 * V_10 , int V_91 , int V_79 )
{
unsigned int V_35 ;
for ( V_35 = 0 ; V_35 < V_104 ; V_35 ++ )
V_91 += F_25 ( V_10 , V_79 ,
V_106 [ V_35 ] . V_50 , V_91 , V_106 [ V_35 ] . V_48 ) ;
return V_91 ;
}
static inline int F_29 ( struct V_1 * V_10 ,
unsigned int V_29 ,
unsigned int V_84 )
{
return V_29 ;
}
static inline int F_30 ( struct V_1 * V_10 , int V_91 , int V_79 )
{
return V_91 ;
}
int F_31 ( struct V_1 * V_10 , int V_79 )
{
int V_16 = F_9 ( & V_10 -> V_13 , & V_10 -> V_15 ) ;
unsigned int V_84 ;
memset ( & V_98 , 0 , sizeof( struct V_108 ) ) ;
if ( V_10 -> V_43 & V_109 ||
V_10 -> V_43 & V_97 )
return 0 ;
if ( V_10 -> V_15 . V_17 == V_110 ) {
V_16 = V_10 -> V_13 . V_22 . V_21 ;
if ( V_10 -> V_13 . V_23 . V_21 < V_16 )
V_16 = V_10 -> V_13 . V_23 . V_21 ;
if ( V_10 -> V_13 . V_20 . V_21 < V_16 )
V_16 = V_10 -> V_13 . V_20 . V_21 ;
}
if ( V_10 -> V_15 . V_17 == V_111 && V_16 > 4 ) {
V_16 = 4 ;
}
V_98 . V_50 = F_32 ( V_16 ) ;
if ( ! V_98 . V_50 ) {
return 0 ;
}
if ( V_79 == V_89 || V_79 == V_80 )
V_84 = V_10 -> V_13 . V_84 ;
else
V_84 = V_10 -> V_13 . V_82 ;
if ( V_98 . V_50 -> V_29 > V_84 ) {
V_98 . V_50 = NULL ;
return 0 ;
}
if ( V_98 . V_50 -> type == V_112 )
V_98 . V_16 = 8 ;
else if ( V_98 . V_50 -> type == V_113 )
V_98 . V_16 = 4 ;
else
V_98 . V_16 = 1 ;
if ( V_98 . V_16 > 4 && V_16 > 4 ) {
switch ( V_10 -> V_15 . V_17 ) {
case V_107 :
V_98 . V_100 = 1 ;
break;
case V_110 :
V_98 . V_101 = 1 ;
V_98 . V_99 = 1 ;
break;
case V_114 :
V_98 . V_99 = 1 ;
break;
}
}
return F_29 ( V_10 , V_98 . V_50 -> V_29 , V_84 ) ;
}
int F_33 ( struct V_1 * V_10 , int V_79 )
{
int V_91 ;
V_91 = F_25 ( V_10 , V_79 , V_98 . V_50 , 0 ,
F_34 () ) ;
V_91 = F_30 ( V_10 , V_91 , V_79 ) ;
return V_91 ;
}
int F_31 ( struct V_1 * V_10 , int V_79 ) { return 0 ; }
int F_33 ( struct V_1 * V_10 , int V_79 ) { return 0 ; }
static void * F_35 ( struct V_115 * V_116 , T_4 * V_117 )
{
F_3 ( & V_5 ) ;
return ( * V_117 < V_3 ) ? V_117 : NULL ;
}
static void * F_36 ( struct V_115 * V_116 , void * V_118 , T_4 * V_117 )
{
( * V_117 ) ++ ;
return ( * V_117 < V_3 ) ? V_117 : NULL ;
}
static void F_37 ( struct V_115 * V_116 , void * V_118 )
{
F_5 ( & V_5 ) ;
}
static int F_38 ( struct V_115 * V_116 , void * V_118 )
{
int V_35 = * ( T_4 * ) V_118 ;
struct V_1 * V_119 = V_6 [ V_35 ] ;
if ( V_119 )
F_39 ( V_116 , L_1 , V_119 -> V_120 , V_119 -> V_15 . V_121 ) ;
return 0 ;
}
static int F_40 ( struct V_122 * V_122 , struct V_123 * V_123 )
{
return F_41 ( V_123 , & V_124 ) ;
}
static struct V_1 * F_42 ( struct V_123 * V_123 )
{
struct V_122 * V_122 = V_123 -> V_125 . V_126 -> V_127 ;
int V_128 = F_43 ( V_122 ) ;
struct V_1 * V_10 = V_6 [ V_128 ] ;
if ( V_10 != V_123 -> V_129 )
V_10 = NULL ;
return V_10 ;
}
static T_5
F_44 ( struct V_123 * V_123 , char T_6 * V_38 , T_7 V_7 , T_4 * V_130 )
{
unsigned long V_131 = * V_130 ;
struct V_1 * V_10 = F_42 ( V_123 ) ;
T_1 * V_132 , * V_25 ;
T_1 T_8 * V_27 ;
int V_133 , V_134 = 0 , V_135 = 0 ;
unsigned long V_136 ;
if ( ! V_10 || ! V_10 -> V_137 )
return - V_4 ;
if ( V_10 -> V_95 != V_96 )
return - V_138 ;
if ( V_10 -> V_8 -> F_44 )
return V_10 -> V_8 -> F_44 ( V_10 , V_38 , V_7 , V_130 ) ;
V_136 = V_10 -> V_139 ;
if ( V_136 == 0 )
V_136 = V_10 -> V_15 . V_140 ;
if ( V_131 >= V_136 )
return 0 ;
if ( V_7 >= V_136 )
V_7 = V_136 ;
if ( V_7 + V_131 > V_136 )
V_7 = V_136 - V_131 ;
V_132 = F_26 ( ( V_7 > V_141 ) ? V_141 : V_7 ,
V_102 ) ;
if ( ! V_132 )
return - V_142 ;
V_27 = ( T_1 T_8 * ) ( V_10 -> V_137 + V_131 ) ;
if ( V_10 -> V_8 -> V_45 )
V_10 -> V_8 -> V_45 ( V_10 ) ;
while ( V_7 ) {
V_133 = ( V_7 > V_141 ) ? V_141 : V_7 ;
V_25 = V_132 ;
F_45 ( V_25 , V_27 , V_133 ) ;
V_25 += V_133 ;
V_27 += V_133 ;
if ( F_46 ( V_38 , V_132 , V_133 ) ) {
V_135 = - V_143 ;
break;
}
* V_130 += V_133 ;
V_38 += V_133 ;
V_134 += V_133 ;
V_7 -= V_133 ;
}
F_27 ( V_132 ) ;
return ( V_135 ) ? V_135 : V_134 ;
}
static T_5
F_47 ( struct V_123 * V_123 , const char T_6 * V_38 , T_7 V_7 , T_4 * V_130 )
{
unsigned long V_131 = * V_130 ;
struct V_1 * V_10 = F_42 ( V_123 ) ;
T_1 * V_132 , * V_27 ;
T_1 T_8 * V_25 ;
int V_133 , V_134 = 0 , V_135 = 0 ;
unsigned long V_136 ;
if ( ! V_10 || ! V_10 -> V_137 )
return - V_4 ;
if ( V_10 -> V_95 != V_96 )
return - V_138 ;
if ( V_10 -> V_8 -> F_47 )
return V_10 -> V_8 -> F_47 ( V_10 , V_38 , V_7 , V_130 ) ;
V_136 = V_10 -> V_139 ;
if ( V_136 == 0 )
V_136 = V_10 -> V_15 . V_140 ;
if ( V_131 > V_136 )
return - V_144 ;
if ( V_7 > V_136 ) {
V_135 = - V_144 ;
V_7 = V_136 ;
}
if ( V_7 + V_131 > V_136 ) {
if ( ! V_135 )
V_135 = - V_145 ;
V_7 = V_136 - V_131 ;
}
V_132 = F_26 ( ( V_7 > V_141 ) ? V_141 : V_7 ,
V_102 ) ;
if ( ! V_132 )
return - V_142 ;
V_25 = ( T_1 T_8 * ) ( V_10 -> V_137 + V_131 ) ;
if ( V_10 -> V_8 -> V_45 )
V_10 -> V_8 -> V_45 ( V_10 ) ;
while ( V_7 ) {
V_133 = ( V_7 > V_141 ) ? V_141 : V_7 ;
V_27 = V_132 ;
if ( F_48 ( V_27 , V_38 , V_133 ) ) {
V_135 = - V_143 ;
break;
}
F_49 ( V_25 , V_27 , V_133 ) ;
V_25 += V_133 ;
V_27 += V_133 ;
* V_130 += V_133 ;
V_38 += V_133 ;
V_134 += V_133 ;
V_7 -= V_133 ;
}
F_27 ( V_132 ) ;
return ( V_134 ) ? V_134 : V_135 ;
}
int
F_50 ( struct V_1 * V_10 , struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_10 -> V_15 ;
unsigned int V_84 = V_10 -> V_13 . V_84 ;
int V_135 = 0 ;
if ( V_13 -> V_146 > 0 ) {
if ( V_13 -> V_147 & V_148 ) {
if ( ! V_15 -> V_149 || ( V_13 -> V_146 % V_15 -> V_149 ) )
V_135 = - V_150 ;
else
V_84 = 0 ;
} else if ( ! V_15 -> V_151 || ( V_13 -> V_146 % V_15 -> V_151 ) )
V_135 = - V_150 ;
}
if ( V_13 -> V_152 > 0 && ( ! V_15 -> V_153 ||
( V_13 -> V_152 % V_15 -> V_153 ) ) )
V_135 = - V_150 ;
if ( V_135 || ! V_10 -> V_8 -> F_50 ||
V_13 -> V_146 > V_10 -> V_13 . V_154 - V_84 ||
V_13 -> V_152 > V_10 -> V_13 . V_155 - V_10 -> V_13 . V_82 )
return - V_150 ;
if ( ( V_135 = V_10 -> V_8 -> F_50 ( V_13 , V_10 ) ) )
return V_135 ;
V_10 -> V_13 . V_152 = V_13 -> V_152 ;
V_10 -> V_13 . V_146 = V_13 -> V_146 ;
if ( V_13 -> V_147 & V_148 )
V_10 -> V_13 . V_147 |= V_148 ;
else
V_10 -> V_13 . V_147 &= ~ V_148 ;
return 0 ;
}
static int F_51 ( struct V_1 * V_10 , struct V_12 * V_13 ,
T_2 V_156 )
{
struct V_157 V_158 ;
struct V_159 V_160 , V_161 ;
int V_135 = 0 ;
memset ( & V_160 , 0 , sizeof( V_160 ) ) ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_160 . V_43 = ( V_156 & V_162 ) ? 1 : 0 ;
V_158 . V_10 = V_10 ;
V_158 . V_69 = & V_160 ;
F_52 ( V_163 , & V_158 ) ;
V_10 -> V_8 -> V_164 ( V_10 , & V_161 , V_13 ) ;
if ( ( ( V_161 . V_88 ^ V_160 . V_88 ) & V_160 . V_88 ) ||
( ( V_161 . V_91 ^ V_160 . V_91 ) & V_160 . V_91 ) ||
( V_161 . V_58 < V_160 . V_58 ) )
V_135 = - V_150 ;
return V_135 ;
}
int
F_53 ( struct V_1 * V_10 , struct V_12 * V_13 )
{
int V_43 = V_10 -> V_43 ;
int V_165 = 0 ;
if ( V_13 -> V_156 & V_166 ) {
struct V_167 V_168 , V_169 ;
F_54 ( & V_168 , V_13 ) ;
F_54 ( & V_169 , & V_10 -> V_13 ) ;
V_165 = F_55 ( & V_168 , & V_169 ) ;
if ( ! V_165 ) {
struct V_157 V_158 ;
V_158 . V_10 = V_10 ;
V_158 . V_69 = & V_168 ;
V_165 = F_52 ( V_170 , & V_158 ) ;
}
if ( ! V_165 )
F_56 ( & V_168 , & V_10 -> V_171 ) ;
V_165 = ( V_165 ) ? - V_150 : 0 ;
goto V_172;
}
if ( ( V_13 -> V_156 & V_173 ) ||
memcmp ( & V_10 -> V_13 , V_13 , sizeof( struct V_12 ) ) ) {
T_2 V_156 = V_13 -> V_156 ;
if ( ( V_10 -> V_15 . V_174 & V_175 ) &&
V_13 -> V_176 > 1 ) {
if ( V_13 -> V_23 . V_24 || V_13 -> V_20 . V_24 ||
V_13 -> V_22 . V_24 || V_13 -> V_59 . V_24 ||
V_13 -> V_23 . V_21 || V_13 -> V_20 . V_21 ||
V_13 -> V_22 . V_21 || V_13 -> V_59 . V_21 ||
V_13 -> V_23 . V_177 || V_13 -> V_20 . V_177 ||
V_13 -> V_22 . V_177 || V_13 -> V_59 . V_177 )
return - V_150 ;
}
if ( ! V_10 -> V_8 -> V_178 ) {
* V_13 = V_10 -> V_13 ;
goto V_172;
}
V_165 = V_10 -> V_8 -> V_178 ( V_13 , V_10 ) ;
if ( V_165 )
goto V_172;
if ( ( V_13 -> V_156 & V_179 ) == V_180 ) {
struct V_12 V_181 ;
struct V_167 V_182 ;
if ( V_10 -> V_8 -> V_164 ) {
V_165 = F_51 ( V_10 , V_13 , V_156 ) ;
if ( V_165 )
goto V_172;
}
V_181 = V_10 -> V_13 ;
V_10 -> V_13 = * V_13 ;
if ( V_10 -> V_8 -> V_183 ) {
V_165 = V_10 -> V_8 -> V_183 ( V_10 ) ;
if ( V_165 ) {
V_10 -> V_13 = V_181 ;
F_57 ( V_184 L_2
L_3
L_4 , V_165 ) ;
goto V_172;
}
}
F_50 ( V_10 , & V_10 -> V_13 ) ;
F_16 ( & V_10 -> V_185 , V_10 ) ;
F_54 ( & V_182 , & V_10 -> V_13 ) ;
if ( V_10 -> V_171 . V_186 && V_10 -> V_171 . V_187 &&
! F_58 ( & V_10 -> V_171 ) )
V_165 = F_59 ( & V_182 , & V_10 -> V_171 ) ;
if ( ! V_165 && ( V_43 & V_188 ) ) {
struct V_157 V_158 ;
int V_189 = ( V_156 & V_162 ) ?
V_190 :
V_191 ;
V_10 -> V_43 &= ~ V_188 ;
V_158 . V_10 = V_10 ;
V_158 . V_69 = & V_182 ;
F_52 ( V_189 , & V_158 ) ;
}
}
}
V_172:
return V_165 ;
}
int
F_60 ( struct V_1 * V_10 , int V_192 )
{
int V_165 = - V_150 ;
if ( V_192 > V_193 )
V_192 = V_193 ;
if ( V_10 -> V_8 -> F_60 )
V_165 = V_10 -> V_8 -> F_60 ( V_192 , V_10 ) ;
if ( ! V_165 ) {
struct V_157 V_158 ;
V_158 . V_10 = V_10 ;
V_158 . V_69 = & V_192 ;
F_52 ( V_194 , & V_158 ) ;
}
return V_165 ;
}
static long F_61 ( struct V_1 * V_10 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_197 * V_198 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
struct V_199 V_200 ;
struct V_51 V_201 ;
struct V_202 V_185 ;
struct V_157 V_158 ;
void T_6 * V_203 = ( void T_6 * ) V_196 ;
long V_165 = 0 ;
switch ( V_195 ) {
case V_204 :
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_13 = V_10 -> V_13 ;
F_62 ( V_10 ) ;
V_165 = F_46 ( V_203 , & V_13 , sizeof( V_13 ) ) ? - V_143 : 0 ;
break;
case V_205 :
if ( F_48 ( & V_13 , V_203 , sizeof( V_13 ) ) )
return - V_143 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
F_63 () ;
V_10 -> V_43 |= V_188 ;
V_165 = F_53 ( V_10 , & V_13 ) ;
V_10 -> V_43 &= ~ V_188 ;
F_64 () ;
F_62 ( V_10 ) ;
if ( ! V_165 && F_46 ( V_203 , & V_13 , sizeof( V_13 ) ) )
V_165 = - V_143 ;
break;
case V_206 :
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_15 = V_10 -> V_15 ;
F_62 ( V_10 ) ;
V_165 = F_46 ( V_203 , & V_15 , sizeof( V_15 ) ) ? - V_143 : 0 ;
break;
case V_207 :
if ( F_48 ( & V_185 , V_203 , sizeof( V_185 ) ) )
return - V_143 ;
V_165 = F_65 ( & V_185 , V_10 ) ;
break;
case V_208 :
if ( F_48 ( & V_185 , V_203 , sizeof( V_185 ) ) )
return - V_143 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_201 = V_10 -> V_185 ;
F_62 ( V_10 ) ;
V_165 = F_66 ( & V_201 , & V_185 ) ;
break;
case V_209 :
if ( F_48 ( & V_13 , V_203 , sizeof( V_13 ) ) )
return - V_143 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
F_63 () ;
V_165 = F_50 ( V_10 , & V_13 ) ;
F_64 () ;
F_62 ( V_10 ) ;
if ( V_165 == 0 && F_46 ( V_203 , & V_13 , sizeof( V_13 ) ) )
return - V_143 ;
break;
case V_210 :
V_165 = - V_150 ;
break;
case V_211 :
if ( F_48 ( & V_200 , V_203 , sizeof( V_200 ) ) )
return - V_143 ;
if ( V_200 . V_212 < 1 || V_200 . V_212 > V_213 )
return - V_150 ;
V_200 . V_214 = - 1 ;
V_158 . V_69 = & V_200 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_158 . V_10 = V_10 ;
F_52 ( V_215 , & V_158 ) ;
F_62 ( V_10 ) ;
V_165 = F_46 ( V_203 , & V_200 , sizeof( V_200 ) ) ? - V_143 : 0 ;
break;
case V_216 :
if ( F_48 ( & V_200 , V_203 , sizeof( V_200 ) ) )
return - V_143 ;
if ( V_200 . V_212 < 1 || V_200 . V_212 > V_213 )
return - V_150 ;
if ( V_200 . V_214 < 0 || V_200 . V_214 >= V_3 )
return - V_150 ;
if ( ! V_6 [ V_200 . V_214 ] )
F_67 ( L_5 , V_200 . V_214 ) ;
if ( ! V_6 [ V_200 . V_214 ] ) {
V_165 = - V_150 ;
break;
}
V_158 . V_69 = & V_200 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_158 . V_10 = V_10 ;
V_165 = F_52 ( V_217 , & V_158 ) ;
F_62 ( V_10 ) ;
break;
case V_218 :
if ( ! F_8 ( V_10 ) )
return - V_4 ;
F_63 () ;
V_10 -> V_43 |= V_188 ;
V_165 = F_60 ( V_10 , V_196 ) ;
V_10 -> V_43 &= ~ V_188 ;
F_64 () ;
F_62 ( V_10 ) ;
break;
default:
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_198 = V_10 -> V_8 ;
if ( V_198 -> V_219 )
V_165 = V_198 -> V_219 ( V_10 , V_195 , V_196 ) ;
else
V_165 = - V_220 ;
F_62 ( V_10 ) ;
}
return V_165 ;
}
static long V_219 ( struct V_123 * V_123 , unsigned int V_195 , unsigned long V_196 )
{
struct V_1 * V_10 = F_42 ( V_123 ) ;
if ( ! V_10 )
return - V_4 ;
return F_61 ( V_10 , V_195 , V_196 ) ;
}
static int F_68 ( struct V_1 * V_10 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_202 T_6 * V_185 ;
struct V_221 T_6 * V_222 ;
T_9 V_69 ;
int V_135 ;
V_185 = F_69 ( sizeof( * V_185 ) ) ;
V_222 = F_70 ( V_196 ) ;
if ( F_71 ( & V_185 -> V_57 , & V_222 -> V_57 , 2 * sizeof( T_9 ) ) )
return - V_143 ;
if ( F_72 ( V_69 , & V_222 -> V_23 ) ||
F_73 ( F_70 ( V_69 ) , & V_185 -> V_23 ) ||
F_72 ( V_69 , & V_222 -> V_20 ) ||
F_73 ( F_70 ( V_69 ) , & V_185 -> V_20 ) ||
F_72 ( V_69 , & V_222 -> V_22 ) ||
F_73 ( F_70 ( V_69 ) , & V_185 -> V_22 ) ||
F_72 ( V_69 , & V_222 -> V_59 ) ||
F_73 ( F_70 ( V_69 ) , & V_185 -> V_59 ) )
return - V_143 ;
V_135 = F_61 ( V_10 , V_195 , ( unsigned long ) V_185 ) ;
if ( ! V_135 ) {
if ( F_71 ( & V_222 -> V_57 ,
& V_185 -> V_57 ,
2 * sizeof( T_9 ) ) )
V_135 = - V_143 ;
}
return V_135 ;
}
static int F_74 ( struct V_14 * V_15 ,
struct V_223 T_6 * V_224 )
{
T_9 V_69 ;
int V_135 ;
V_135 = F_46 ( & V_224 -> V_121 , & V_15 -> V_121 , sizeof( V_224 -> V_121 ) ) ;
V_69 = ( T_9 ) ( unsigned long ) V_15 -> V_225 ;
V_135 |= F_73 ( V_69 , & V_224 -> V_225 ) ;
V_135 |= F_73 ( V_15 -> V_140 , & V_224 -> V_140 ) ;
V_135 |= F_73 ( V_15 -> type , & V_224 -> type ) ;
V_135 |= F_73 ( V_15 -> V_226 , & V_224 -> V_226 ) ;
V_135 |= F_73 ( V_15 -> V_17 , & V_224 -> V_17 ) ;
V_135 |= F_73 ( V_15 -> V_153 , & V_224 -> V_153 ) ;
V_135 |= F_73 ( V_15 -> V_151 , & V_224 -> V_151 ) ;
V_135 |= F_73 ( V_15 -> V_149 , & V_224 -> V_149 ) ;
V_135 |= F_73 ( V_15 -> V_227 , & V_224 -> V_227 ) ;
V_69 = ( T_9 ) ( unsigned long ) V_15 -> V_228 ;
V_135 |= F_73 ( V_69 , & V_224 -> V_228 ) ;
V_135 |= F_73 ( V_15 -> V_229 , & V_224 -> V_229 ) ;
V_135 |= F_73 ( V_15 -> V_230 , & V_224 -> V_230 ) ;
V_135 |= F_46 ( V_224 -> V_231 , V_15 -> V_231 ,
sizeof( V_15 -> V_231 ) ) ;
return V_135 ;
}
static int F_75 ( struct V_1 * V_10 , unsigned int V_195 ,
unsigned long V_196 )
{
T_10 V_232 ;
struct V_14 V_15 ;
struct V_223 T_6 * V_224 ;
int V_135 ;
V_224 = F_70 ( V_196 ) ;
V_232 = F_76 () ;
F_77 ( V_233 ) ;
V_135 = F_61 ( V_10 , V_195 , ( unsigned long ) & V_15 ) ;
F_77 ( V_232 ) ;
if ( ! V_135 )
V_135 = F_74 ( & V_15 , V_224 ) ;
return V_135 ;
}
static long F_78 ( struct V_123 * V_123 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_1 * V_10 = F_42 ( V_123 ) ;
struct V_197 * V_198 ;
long V_165 = - V_234 ;
if ( ! V_10 )
return - V_4 ;
V_198 = V_10 -> V_8 ;
switch( V_195 ) {
case V_204 :
case V_205 :
case V_209 :
case V_211 :
case V_216 :
V_196 = ( unsigned long ) F_70 ( V_196 ) ;
case V_218 :
V_165 = F_61 ( V_10 , V_195 , V_196 ) ;
break;
case V_206 :
V_165 = F_75 ( V_10 , V_195 , V_196 ) ;
break;
case V_208 :
case V_207 :
V_165 = F_68 ( V_10 , V_195 , V_196 ) ;
break;
default:
if ( V_198 -> F_78 )
V_165 = V_198 -> F_78 ( V_10 , V_195 , V_196 ) ;
break;
}
return V_165 ;
}
static int
F_79 ( struct V_123 * V_123 , struct V_235 * V_236 )
{
struct V_1 * V_10 = F_42 ( V_123 ) ;
struct V_197 * V_198 ;
unsigned long V_237 ;
unsigned long V_57 ;
T_2 V_58 ;
if ( ! V_10 )
return - V_4 ;
if ( V_236 -> V_238 > ( ~ 0UL >> V_239 ) )
return - V_150 ;
V_237 = V_236 -> V_238 << V_239 ;
V_198 = V_10 -> V_8 ;
if ( ! V_198 )
return - V_4 ;
F_3 ( & V_10 -> V_240 ) ;
if ( V_198 -> F_79 ) {
int V_241 ;
V_241 = V_198 -> F_79 ( V_10 , V_236 ) ;
F_5 ( & V_10 -> V_240 ) ;
return V_241 ;
}
V_57 = V_10 -> V_15 . V_225 ;
V_58 = F_80 ( ( V_57 & ~ V_242 ) + V_10 -> V_15 . V_140 ) ;
if ( V_237 >= V_58 ) {
V_237 -= V_58 ;
if ( V_10 -> V_13 . V_243 ) {
F_5 ( & V_10 -> V_240 ) ;
return - V_150 ;
}
V_57 = V_10 -> V_15 . V_228 ;
V_58 = F_80 ( ( V_57 & ~ V_242 ) + V_10 -> V_15 . V_229 ) ;
}
F_5 ( & V_10 -> V_240 ) ;
V_57 &= V_242 ;
if ( ( V_236 -> V_244 - V_236 -> V_245 + V_237 ) > V_58 )
return - V_150 ;
V_237 += V_57 ;
V_236 -> V_238 = V_237 >> V_239 ;
V_236 -> V_246 |= V_247 | V_248 ;
V_236 -> V_249 = F_81 ( V_236 -> V_246 ) ;
F_82 ( V_123 , V_236 , V_237 ) ;
if ( F_83 ( V_236 , V_236 -> V_245 , V_237 >> V_239 ,
V_236 -> V_244 - V_236 -> V_245 , V_236 -> V_249 ) )
return - V_250 ;
return 0 ;
}
static int
F_84 ( struct V_122 * V_122 , struct V_123 * V_123 )
__acquires( &info->lock
static int
F_85 ( struct V_122 * V_122 , struct V_123 * V_123 )
__acquires( &info->lock
static int F_86 ( struct V_1 * V_119 )
{
const bool V_251 = V_119 -> V_43 & V_252 ;
V_119 -> V_43 &= ~ V_252 ;
#ifdef F_87
V_119 -> V_43 |= V_251 ? 0 : V_253 ;
#else
V_119 -> V_43 |= V_251 ? V_253 : 0 ;
#endif
if ( V_119 -> V_43 & V_253 && ! F_88 ( V_119 ) ) {
F_89 ( L_6
L_7 , V_119 -> V_15 . V_121 ) ;
return - V_254 ;
} else if ( ! ( V_119 -> V_43 & V_253 ) && F_88 ( V_119 ) ) {
F_89 ( L_8
L_7 , V_119 -> V_15 . V_121 ) ;
return - V_254 ;
}
return 0 ;
}
static bool F_90 ( struct V_255 * V_256 , struct V_255 * V_257 )
{
if ( V_256 -> V_258 == V_257 -> V_258 )
return true ;
if ( V_256 -> V_258 > V_257 -> V_258 && V_256 -> V_258 < V_257 -> V_258 + V_257 -> V_39 )
return true ;
return false ;
}
static bool F_91 ( struct V_259 * V_260 ,
struct V_259 * V_261 )
{
int V_35 , V_36 ;
if ( ! V_261 || ! V_260 )
return false ;
for ( V_35 = 0 ; V_35 < V_261 -> V_7 ; ++ V_35 ) {
struct V_255 * V_75 = & V_261 -> V_262 [ V_35 ] ;
for ( V_36 = 0 ; V_36 < V_260 -> V_7 ; ++ V_36 ) {
struct V_255 * V_263 = & V_260 -> V_262 [ V_36 ] ;
F_57 ( V_264 L_9 ,
( unsigned long long ) V_263 -> V_258 ,
( unsigned long long ) V_263 -> V_39 ,
( unsigned long long ) V_75 -> V_258 ,
( unsigned long long ) V_75 -> V_39 ) ;
if ( F_90 ( V_263 , V_75 ) )
return true ;
}
}
return false ;
}
static void F_92 ( struct V_259 * V_265 ,
const char * V_266 , bool V_267 )
{
int V_35 ;
for ( V_35 = 0 ; V_35 < V_3 ; V_35 ++ ) {
struct V_259 * V_268 ;
if ( ! V_6 [ V_35 ] )
continue;
if ( ! ( V_6 [ V_35 ] -> V_43 & V_269 ) )
continue;
V_268 = V_6 [ V_35 ] -> V_270 ;
if ( F_91 ( V_268 , V_265 ) ||
( V_267 && V_268 && V_268 -> V_7 &&
V_268 -> V_262 [ 0 ] . V_258 == V_271 ) ) {
F_57 ( V_272 L_10
L_11 ,
V_266 , V_6 [ V_35 ] -> V_15 . V_121 ) ;
F_93 ( V_6 [ V_35 ] ) ;
}
}
}
static int F_94 ( struct V_1 * V_1 )
{
int V_35 ;
struct V_157 V_158 ;
struct V_167 V_182 ;
if ( F_86 ( V_1 ) )
return - V_254 ;
F_92 ( V_1 -> V_270 , V_1 -> V_15 . V_121 ,
F_95 ( V_1 ) ) ;
if ( V_273 == V_3 )
return - V_274 ;
V_273 ++ ;
for ( V_35 = 0 ; V_35 < V_3 ; V_35 ++ )
if ( ! V_6 [ V_35 ] )
break;
V_1 -> V_120 = V_35 ;
F_96 ( & V_1 -> V_7 , 1 ) ;
F_97 ( & V_1 -> V_11 ) ;
F_97 ( & V_1 -> V_240 ) ;
V_1 -> V_275 = F_98 ( V_276 , V_1 -> V_277 ,
F_99 ( V_278 , V_35 ) , NULL , L_5 , V_35 ) ;
if ( F_100 ( V_1 -> V_275 ) ) {
F_57 ( V_184 L_12 , V_35 , F_101 ( V_1 -> V_275 ) ) ;
V_1 -> V_275 = NULL ;
} else
F_102 ( V_1 ) ;
if ( V_1 -> V_279 . V_42 == NULL ) {
V_1 -> V_279 . V_42 = F_26 ( V_280 , V_102 ) ;
if ( V_1 -> V_279 . V_42 ) {
V_1 -> V_279 . V_39 = V_280 ;
V_1 -> V_279 . V_41 = 1 ;
V_1 -> V_279 . V_281 = 1 ;
V_1 -> V_279 . V_282 = 32 ;
V_1 -> V_279 . V_43 = V_283 ;
}
}
V_1 -> V_279 . V_24 = 0 ;
if ( ! V_1 -> V_279 . V_284 )
V_1 -> V_279 . V_284 = ~ ( T_2 ) 0 ;
if ( ! V_1 -> V_279 . V_285 )
V_1 -> V_279 . V_285 = ~ ( T_2 ) 0 ;
if ( ! V_1 -> V_171 . V_186 || ! V_1 -> V_171 . V_187 )
F_103 ( & V_1 -> V_171 ) ;
F_54 ( & V_182 , & V_1 -> V_13 ) ;
F_59 ( & V_182 , & V_1 -> V_171 ) ;
V_6 [ V_35 ] = V_1 ;
V_158 . V_10 = V_1 ;
if ( ! F_8 ( V_1 ) )
return - V_4 ;
F_52 ( V_286 , & V_158 ) ;
F_62 ( V_1 ) ;
return 0 ;
}
static int F_93 ( struct V_1 * V_1 )
{
struct V_157 V_158 ;
int V_35 , V_165 = 0 ;
V_35 = V_1 -> V_120 ;
if ( V_35 < 0 || V_35 >= V_3 || V_6 [ V_35 ] != V_1 )
return - V_150 ;
if ( ! F_8 ( V_1 ) )
return - V_4 ;
V_158 . V_10 = V_1 ;
V_165 = F_52 ( V_287 , & V_158 ) ;
F_62 ( V_1 ) ;
if ( V_165 )
return - V_150 ;
if ( V_1 -> V_279 . V_42 &&
( V_1 -> V_279 . V_43 & V_283 ) )
F_27 ( V_1 -> V_279 . V_42 ) ;
F_104 ( & V_1 -> V_171 ) ;
V_6 [ V_35 ] = NULL ;
V_273 -- ;
F_105 ( V_1 ) ;
F_106 ( V_276 , F_99 ( V_278 , V_35 ) ) ;
V_158 . V_10 = V_1 ;
F_52 ( V_288 , & V_158 ) ;
F_6 ( V_1 ) ;
return 0 ;
}
void F_107 ( struct V_259 * V_265 ,
const char * V_266 , bool V_267 )
{
F_3 ( & V_5 ) ;
F_92 ( V_265 , V_266 , V_267 ) ;
F_5 ( & V_5 ) ;
}
int
F_108 ( struct V_1 * V_1 )
{
int V_165 ;
F_3 ( & V_5 ) ;
V_165 = F_94 ( V_1 ) ;
F_5 ( & V_5 ) ;
return V_165 ;
}
int
F_109 ( struct V_1 * V_1 )
{
int V_165 ;
F_3 ( & V_5 ) ;
V_165 = F_93 ( V_1 ) ;
F_5 ( & V_5 ) ;
return V_165 ;
}
void F_110 ( struct V_1 * V_10 , int V_95 )
{
struct V_157 V_158 ;
V_158 . V_10 = V_10 ;
if ( V_95 ) {
F_52 ( V_289 , & V_158 ) ;
V_10 -> V_95 = V_290 ;
} else {
V_10 -> V_95 = V_96 ;
F_52 ( V_291 , & V_158 ) ;
}
}
static int T_11
F_111 ( void )
{
F_112 ( L_13 , 0 , NULL , & V_292 ) ;
if ( F_113 ( V_278 , L_13 , & V_293 ) )
F_57 ( L_14 , V_278 ) ;
V_276 = F_114 ( V_294 , L_15 ) ;
if ( F_100 ( V_276 ) ) {
F_57 ( V_184 L_16 , F_101 ( V_276 ) ) ;
V_276 = NULL ;
}
return 0 ;
}
static void T_12
F_115 ( void )
{
F_116 ( L_13 , NULL ) ;
F_117 ( V_276 ) ;
F_118 ( V_278 , L_13 ) ;
}
int F_119 ( struct V_1 * V_10 )
{
struct V_157 V_158 ;
struct V_12 V_13 = V_10 -> V_13 ;
struct V_295 * V_117 , * V_48 ;
struct V_296 * V_171 ;
struct V_167 * V_116 , V_182 ;
int V_135 = 1 ;
F_120 (pos, n, &info->modelist) {
V_171 = F_121 ( V_117 , struct V_296 , V_297 ) ;
V_116 = & V_171 -> V_182 ;
F_122 ( & V_13 , V_116 ) ;
V_13 . V_156 = V_298 ;
V_135 = F_53 ( V_10 , & V_13 ) ;
F_54 ( & V_182 , & V_13 ) ;
if ( V_135 || ! F_55 ( V_116 , & V_182 ) ) {
F_123 ( V_117 ) ;
F_27 ( V_117 ) ;
}
}
V_135 = 1 ;
if ( ! F_58 ( & V_10 -> V_171 ) ) {
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_158 . V_10 = V_10 ;
V_135 = F_52 ( V_299 , & V_158 ) ;
F_62 ( V_10 ) ;
}
return V_135 ;
}
int F_124 ( char * V_266 , char * * V_300 )
{
char * V_301 , * V_302 = NULL ;
int V_303 = 0 ;
int V_304 = strlen ( V_266 ) , V_35 ;
if ( V_304 && V_305 && strncmp ( V_266 , L_17 , 4 ) )
V_303 = 1 ;
if ( V_304 && ! V_303 ) {
for ( V_35 = 0 ; V_35 < V_3 ; V_35 ++ ) {
if ( V_306 [ V_35 ] == NULL )
continue;
if ( ! V_306 [ V_35 ] [ 0 ] )
continue;
V_301 = V_306 [ V_35 ] ;
if ( ! strncmp ( V_266 , V_301 , V_304 ) &&
V_301 [ V_304 ] == ':' )
V_302 = V_301 + V_304 + 1 ;
}
}
if ( V_302 && ! strncmp ( V_302 , L_18 , 3 ) )
V_303 = 1 ;
if ( V_300 )
* V_300 = V_302 ;
return V_303 ;
}
static int T_11 F_125 ( char * V_302 )
{
int V_35 , V_307 = 0 ;
if ( ! V_302 || ! * V_302 )
V_307 = 1 ;
if ( ! V_307 && ! strncmp ( V_302 , L_19 , 6 ) ) {
V_305 = 1 ;
V_307 = 1 ;
}
if ( ! V_307 && ! strchr ( V_302 , ':' ) ) {
V_308 = V_302 ;
V_307 = 1 ;
}
if ( ! V_307 ) {
for ( V_35 = 0 ; V_35 < V_3 ; V_35 ++ ) {
if ( V_306 [ V_35 ] == NULL ) {
V_306 [ V_35 ] = V_302 ;
break;
}
}
}
return 1 ;
}
