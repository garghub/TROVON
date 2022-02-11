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
for ( V_88 = 0 ; V_88 < V_87 ; V_88 ++ ) {
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
for ( V_88 = 0 ; V_88 < V_87 ; V_88 ++ ) {
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
struct V_122 * V_122 = F_43 ( V_123 ) ;
int V_125 = F_44 ( V_122 ) ;
struct V_1 * V_10 = V_6 [ V_125 ] ;
if ( V_10 != V_123 -> V_126 )
V_10 = NULL ;
return V_10 ;
}
static T_5
F_45 ( struct V_123 * V_123 , char T_6 * V_38 , T_7 V_7 , T_4 * V_127 )
{
unsigned long V_128 = * V_127 ;
struct V_1 * V_10 = F_42 ( V_123 ) ;
T_1 * V_129 , * V_25 ;
T_1 T_8 * V_27 ;
int V_130 , V_131 = 0 , V_132 = 0 ;
unsigned long V_133 ;
if ( ! V_10 || ! V_10 -> V_134 )
return - V_4 ;
if ( V_10 -> V_95 != V_96 )
return - V_135 ;
if ( V_10 -> V_8 -> F_45 )
return V_10 -> V_8 -> F_45 ( V_10 , V_38 , V_7 , V_127 ) ;
V_133 = V_10 -> V_136 ;
if ( V_133 == 0 )
V_133 = V_10 -> V_15 . V_137 ;
if ( V_128 >= V_133 )
return 0 ;
if ( V_7 >= V_133 )
V_7 = V_133 ;
if ( V_7 + V_128 > V_133 )
V_7 = V_133 - V_128 ;
V_129 = F_26 ( ( V_7 > V_138 ) ? V_138 : V_7 ,
V_102 ) ;
if ( ! V_129 )
return - V_139 ;
V_27 = ( T_1 T_8 * ) ( V_10 -> V_134 + V_128 ) ;
if ( V_10 -> V_8 -> V_45 )
V_10 -> V_8 -> V_45 ( V_10 ) ;
while ( V_7 ) {
V_130 = ( V_7 > V_138 ) ? V_138 : V_7 ;
V_25 = V_129 ;
F_46 ( V_25 , V_27 , V_130 ) ;
V_25 += V_130 ;
V_27 += V_130 ;
if ( F_47 ( V_38 , V_129 , V_130 ) ) {
V_132 = - V_140 ;
break;
}
* V_127 += V_130 ;
V_38 += V_130 ;
V_131 += V_130 ;
V_7 -= V_130 ;
}
F_27 ( V_129 ) ;
return ( V_132 ) ? V_132 : V_131 ;
}
static T_5
F_48 ( struct V_123 * V_123 , const char T_6 * V_38 , T_7 V_7 , T_4 * V_127 )
{
unsigned long V_128 = * V_127 ;
struct V_1 * V_10 = F_42 ( V_123 ) ;
T_1 * V_129 , * V_27 ;
T_1 T_8 * V_25 ;
int V_130 , V_131 = 0 , V_132 = 0 ;
unsigned long V_133 ;
if ( ! V_10 || ! V_10 -> V_134 )
return - V_4 ;
if ( V_10 -> V_95 != V_96 )
return - V_135 ;
if ( V_10 -> V_8 -> F_48 )
return V_10 -> V_8 -> F_48 ( V_10 , V_38 , V_7 , V_127 ) ;
V_133 = V_10 -> V_136 ;
if ( V_133 == 0 )
V_133 = V_10 -> V_15 . V_137 ;
if ( V_128 > V_133 )
return - V_141 ;
if ( V_7 > V_133 ) {
V_132 = - V_141 ;
V_7 = V_133 ;
}
if ( V_7 + V_128 > V_133 ) {
if ( ! V_132 )
V_132 = - V_142 ;
V_7 = V_133 - V_128 ;
}
V_129 = F_26 ( ( V_7 > V_138 ) ? V_138 : V_7 ,
V_102 ) ;
if ( ! V_129 )
return - V_139 ;
V_25 = ( T_1 T_8 * ) ( V_10 -> V_134 + V_128 ) ;
if ( V_10 -> V_8 -> V_45 )
V_10 -> V_8 -> V_45 ( V_10 ) ;
while ( V_7 ) {
V_130 = ( V_7 > V_138 ) ? V_138 : V_7 ;
V_27 = V_129 ;
if ( F_49 ( V_27 , V_38 , V_130 ) ) {
V_132 = - V_140 ;
break;
}
F_50 ( V_25 , V_27 , V_130 ) ;
V_25 += V_130 ;
V_27 += V_130 ;
* V_127 += V_130 ;
V_38 += V_130 ;
V_131 += V_130 ;
V_7 -= V_130 ;
}
F_27 ( V_129 ) ;
return ( V_131 ) ? V_131 : V_132 ;
}
int
F_51 ( struct V_1 * V_10 , struct V_12 * V_13 )
{
struct V_14 * V_15 = & V_10 -> V_15 ;
unsigned int V_84 = V_10 -> V_13 . V_84 ;
int V_132 = 0 ;
if ( V_13 -> V_143 > 0 ) {
if ( V_13 -> V_144 & V_145 ) {
if ( ! V_15 -> V_146 || ( V_13 -> V_143 % V_15 -> V_146 ) )
V_132 = - V_147 ;
else
V_84 = 0 ;
} else if ( ! V_15 -> V_148 || ( V_13 -> V_143 % V_15 -> V_148 ) )
V_132 = - V_147 ;
}
if ( V_13 -> V_149 > 0 && ( ! V_15 -> V_150 ||
( V_13 -> V_149 % V_15 -> V_150 ) ) )
V_132 = - V_147 ;
if ( V_132 || ! V_10 -> V_8 -> F_51 ||
V_13 -> V_143 > V_10 -> V_13 . V_151 - V_84 ||
V_13 -> V_149 > V_10 -> V_13 . V_152 - V_10 -> V_13 . V_82 )
return - V_147 ;
if ( ( V_132 = V_10 -> V_8 -> F_51 ( V_13 , V_10 ) ) )
return V_132 ;
V_10 -> V_13 . V_149 = V_13 -> V_149 ;
V_10 -> V_13 . V_143 = V_13 -> V_143 ;
if ( V_13 -> V_144 & V_145 )
V_10 -> V_13 . V_144 |= V_145 ;
else
V_10 -> V_13 . V_144 &= ~ V_145 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_10 , struct V_12 * V_13 ,
T_2 V_153 )
{
struct V_154 V_155 ;
struct V_156 V_157 , V_158 ;
int V_132 = 0 ;
memset ( & V_157 , 0 , sizeof( V_157 ) ) ;
memset ( & V_158 , 0 , sizeof( V_158 ) ) ;
V_157 . V_43 = ( V_153 & V_159 ) ? 1 : 0 ;
V_155 . V_10 = V_10 ;
V_155 . V_69 = & V_157 ;
F_53 ( V_160 , & V_155 ) ;
V_10 -> V_8 -> V_161 ( V_10 , & V_158 , V_13 ) ;
if ( ( ( V_158 . V_88 ^ V_157 . V_88 ) & V_157 . V_88 ) ||
( ( V_158 . V_91 ^ V_157 . V_91 ) & V_157 . V_91 ) ||
( V_158 . V_58 < V_157 . V_58 ) )
V_132 = - V_147 ;
return V_132 ;
}
int
F_54 ( struct V_1 * V_10 , struct V_12 * V_13 )
{
int V_43 = V_10 -> V_43 ;
int V_162 = 0 ;
if ( V_13 -> V_153 & V_163 ) {
struct V_164 V_165 , V_166 ;
F_55 ( & V_165 , V_13 ) ;
F_55 ( & V_166 , & V_10 -> V_13 ) ;
V_162 = F_56 ( & V_165 , & V_166 ) ;
if ( ! V_162 ) {
struct V_154 V_155 ;
V_155 . V_10 = V_10 ;
V_155 . V_69 = & V_165 ;
V_162 = F_53 ( V_167 , & V_155 ) ;
}
if ( ! V_162 )
F_57 ( & V_165 , & V_10 -> V_168 ) ;
V_162 = ( V_162 ) ? - V_147 : 0 ;
goto V_169;
}
if ( ( V_13 -> V_153 & V_170 ) ||
memcmp ( & V_10 -> V_13 , V_13 , sizeof( struct V_12 ) ) ) {
T_2 V_153 = V_13 -> V_153 ;
if ( ( V_10 -> V_15 . V_171 & V_172 ) &&
V_13 -> V_173 > 1 ) {
if ( V_13 -> V_23 . V_24 || V_13 -> V_20 . V_24 ||
V_13 -> V_22 . V_24 || V_13 -> V_59 . V_24 ||
V_13 -> V_23 . V_21 || V_13 -> V_20 . V_21 ||
V_13 -> V_22 . V_21 || V_13 -> V_59 . V_21 ||
V_13 -> V_23 . V_174 || V_13 -> V_20 . V_174 ||
V_13 -> V_22 . V_174 || V_13 -> V_59 . V_174 )
return - V_147 ;
}
if ( ! V_10 -> V_8 -> V_175 ) {
* V_13 = V_10 -> V_13 ;
goto V_169;
}
V_162 = V_10 -> V_8 -> V_175 ( V_13 , V_10 ) ;
if ( V_162 )
goto V_169;
if ( ( V_13 -> V_153 & V_176 ) == V_177 ) {
struct V_12 V_178 ;
struct V_164 V_179 ;
if ( V_10 -> V_8 -> V_161 ) {
V_162 = F_52 ( V_10 , V_13 , V_153 ) ;
if ( V_162 )
goto V_169;
}
V_178 = V_10 -> V_13 ;
V_10 -> V_13 = * V_13 ;
if ( V_10 -> V_8 -> V_180 ) {
V_162 = V_10 -> V_8 -> V_180 ( V_10 ) ;
if ( V_162 ) {
V_10 -> V_13 = V_178 ;
F_58 ( V_181 L_2
L_3
L_4 , V_162 ) ;
goto V_169;
}
}
F_51 ( V_10 , & V_10 -> V_13 ) ;
F_16 ( & V_10 -> V_182 , V_10 ) ;
F_55 ( & V_179 , & V_10 -> V_13 ) ;
if ( V_10 -> V_168 . V_183 && V_10 -> V_168 . V_184 &&
! F_59 ( & V_10 -> V_168 ) )
V_162 = F_60 ( & V_179 , & V_10 -> V_168 ) ;
if ( ! V_162 && ( V_43 & V_185 ) ) {
struct V_154 V_155 ;
int V_186 = ( V_153 & V_159 ) ?
V_187 :
V_188 ;
V_10 -> V_43 &= ~ V_185 ;
V_155 . V_10 = V_10 ;
V_155 . V_69 = & V_179 ;
F_53 ( V_186 , & V_155 ) ;
}
}
}
V_169:
return V_162 ;
}
int
F_61 ( struct V_1 * V_10 , int V_189 )
{
struct V_154 V_155 ;
int V_162 = - V_147 , V_190 ;
if ( V_189 > V_191 )
V_189 = V_191 ;
V_155 . V_10 = V_10 ;
V_155 . V_69 = & V_189 ;
V_190 = F_53 ( V_192 , & V_155 ) ;
if ( V_10 -> V_8 -> F_61 )
V_162 = V_10 -> V_8 -> F_61 ( V_189 , V_10 ) ;
if ( ! V_162 )
F_53 ( V_193 , & V_155 ) ;
else {
if ( ! V_190 )
F_53 ( V_194 , & V_155 ) ;
}
return V_162 ;
}
static long F_62 ( struct V_1 * V_10 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_197 * V_198 ;
struct V_12 V_13 ;
struct V_14 V_15 ;
struct V_199 V_200 ;
struct V_51 V_201 ;
struct V_202 V_182 ;
struct V_154 V_155 ;
void T_6 * V_203 = ( void T_6 * ) V_196 ;
long V_162 = 0 ;
switch ( V_195 ) {
case V_204 :
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_13 = V_10 -> V_13 ;
F_63 ( V_10 ) ;
V_162 = F_47 ( V_203 , & V_13 , sizeof( V_13 ) ) ? - V_140 : 0 ;
break;
case V_205 :
if ( F_49 ( & V_13 , V_203 , sizeof( V_13 ) ) )
return - V_140 ;
F_64 () ;
if ( ! F_8 ( V_10 ) ) {
F_65 () ;
return - V_4 ;
}
V_10 -> V_43 |= V_185 ;
V_162 = F_54 ( V_10 , & V_13 ) ;
V_10 -> V_43 &= ~ V_185 ;
F_63 ( V_10 ) ;
F_65 () ;
if ( ! V_162 && F_47 ( V_203 , & V_13 , sizeof( V_13 ) ) )
V_162 = - V_140 ;
break;
case V_206 :
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_15 = V_10 -> V_15 ;
F_63 ( V_10 ) ;
V_162 = F_47 ( V_203 , & V_15 , sizeof( V_15 ) ) ? - V_140 : 0 ;
break;
case V_207 :
if ( F_49 ( & V_182 , V_203 , sizeof( V_182 ) ) )
return - V_140 ;
V_162 = F_66 ( & V_182 , V_10 ) ;
break;
case V_208 :
if ( F_49 ( & V_182 , V_203 , sizeof( V_182 ) ) )
return - V_140 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_201 = V_10 -> V_182 ;
F_63 ( V_10 ) ;
V_162 = F_67 ( & V_201 , & V_182 ) ;
break;
case V_209 :
if ( F_49 ( & V_13 , V_203 , sizeof( V_13 ) ) )
return - V_140 ;
F_64 () ;
if ( ! F_8 ( V_10 ) ) {
F_65 () ;
return - V_4 ;
}
V_162 = F_51 ( V_10 , & V_13 ) ;
F_63 ( V_10 ) ;
F_65 () ;
if ( V_162 == 0 && F_47 ( V_203 , & V_13 , sizeof( V_13 ) ) )
return - V_140 ;
break;
case V_210 :
V_162 = - V_147 ;
break;
case V_211 :
if ( F_49 ( & V_200 , V_203 , sizeof( V_200 ) ) )
return - V_140 ;
if ( V_200 . V_212 < 1 || V_200 . V_212 > V_213 )
return - V_147 ;
V_200 . V_214 = - 1 ;
V_155 . V_69 = & V_200 ;
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_155 . V_10 = V_10 ;
F_53 ( V_215 , & V_155 ) ;
F_63 ( V_10 ) ;
V_162 = F_47 ( V_203 , & V_200 , sizeof( V_200 ) ) ? - V_140 : 0 ;
break;
case V_216 :
if ( F_49 ( & V_200 , V_203 , sizeof( V_200 ) ) )
return - V_140 ;
if ( V_200 . V_212 < 1 || V_200 . V_212 > V_213 )
return - V_147 ;
if ( V_200 . V_214 >= V_3 )
return - V_147 ;
if ( ! V_6 [ V_200 . V_214 ] )
F_68 ( L_5 , V_200 . V_214 ) ;
if ( ! V_6 [ V_200 . V_214 ] ) {
V_162 = - V_147 ;
break;
}
V_155 . V_69 = & V_200 ;
F_64 () ;
if ( ! F_8 ( V_10 ) ) {
F_65 () ;
return - V_4 ;
}
V_155 . V_10 = V_10 ;
V_162 = F_53 ( V_217 , & V_155 ) ;
F_63 ( V_10 ) ;
F_65 () ;
break;
case V_218 :
F_64 () ;
if ( ! F_8 ( V_10 ) ) {
F_65 () ;
return - V_4 ;
}
V_10 -> V_43 |= V_185 ;
V_162 = F_61 ( V_10 , V_196 ) ;
V_10 -> V_43 &= ~ V_185 ;
F_63 ( V_10 ) ;
F_65 () ;
break;
default:
if ( ! F_8 ( V_10 ) )
return - V_4 ;
V_198 = V_10 -> V_8 ;
if ( V_198 -> V_219 )
V_162 = V_198 -> V_219 ( V_10 , V_195 , V_196 ) ;
else
V_162 = - V_220 ;
F_63 ( V_10 ) ;
}
return V_162 ;
}
static long V_219 ( struct V_123 * V_123 , unsigned int V_195 , unsigned long V_196 )
{
struct V_1 * V_10 = F_42 ( V_123 ) ;
if ( ! V_10 )
return - V_4 ;
return F_62 ( V_10 , V_195 , V_196 ) ;
}
static int F_69 ( struct V_1 * V_10 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_202 T_6 * V_182 ;
struct V_221 T_6 * V_222 ;
T_9 V_69 ;
int V_132 ;
V_182 = F_70 ( sizeof( * V_182 ) ) ;
V_222 = F_71 ( V_196 ) ;
if ( F_72 ( & V_182 -> V_57 , & V_222 -> V_57 , 2 * sizeof( T_9 ) ) )
return - V_140 ;
if ( F_73 ( V_69 , & V_222 -> V_23 ) ||
F_74 ( F_71 ( V_69 ) , & V_182 -> V_23 ) ||
F_73 ( V_69 , & V_222 -> V_20 ) ||
F_74 ( F_71 ( V_69 ) , & V_182 -> V_20 ) ||
F_73 ( V_69 , & V_222 -> V_22 ) ||
F_74 ( F_71 ( V_69 ) , & V_182 -> V_22 ) ||
F_73 ( V_69 , & V_222 -> V_59 ) ||
F_74 ( F_71 ( V_69 ) , & V_182 -> V_59 ) )
return - V_140 ;
V_132 = F_62 ( V_10 , V_195 , ( unsigned long ) V_182 ) ;
if ( ! V_132 ) {
if ( F_72 ( & V_222 -> V_57 ,
& V_182 -> V_57 ,
2 * sizeof( T_9 ) ) )
V_132 = - V_140 ;
}
return V_132 ;
}
static int F_75 ( struct V_14 * V_15 ,
struct V_223 T_6 * V_224 )
{
T_9 V_69 ;
int V_132 ;
V_132 = F_47 ( & V_224 -> V_121 , & V_15 -> V_121 , sizeof( V_224 -> V_121 ) ) ;
V_69 = ( T_9 ) ( unsigned long ) V_15 -> V_225 ;
V_132 |= F_74 ( V_69 , & V_224 -> V_225 ) ;
V_132 |= F_74 ( V_15 -> V_137 , & V_224 -> V_137 ) ;
V_132 |= F_74 ( V_15 -> type , & V_224 -> type ) ;
V_132 |= F_74 ( V_15 -> V_226 , & V_224 -> V_226 ) ;
V_132 |= F_74 ( V_15 -> V_17 , & V_224 -> V_17 ) ;
V_132 |= F_74 ( V_15 -> V_150 , & V_224 -> V_150 ) ;
V_132 |= F_74 ( V_15 -> V_148 , & V_224 -> V_148 ) ;
V_132 |= F_74 ( V_15 -> V_146 , & V_224 -> V_146 ) ;
V_132 |= F_74 ( V_15 -> V_227 , & V_224 -> V_227 ) ;
V_69 = ( T_9 ) ( unsigned long ) V_15 -> V_228 ;
V_132 |= F_74 ( V_69 , & V_224 -> V_228 ) ;
V_132 |= F_74 ( V_15 -> V_229 , & V_224 -> V_229 ) ;
V_132 |= F_74 ( V_15 -> V_230 , & V_224 -> V_230 ) ;
V_132 |= F_47 ( V_224 -> V_231 , V_15 -> V_231 ,
sizeof( V_15 -> V_231 ) ) ;
if ( V_132 )
return - V_140 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_10 , unsigned int V_195 ,
unsigned long V_196 )
{
T_10 V_232 ;
struct V_14 V_15 ;
struct V_223 T_6 * V_224 ;
int V_132 ;
V_224 = F_71 ( V_196 ) ;
V_232 = F_77 () ;
F_78 ( V_233 ) ;
V_132 = F_62 ( V_10 , V_195 , ( unsigned long ) & V_15 ) ;
F_78 ( V_232 ) ;
if ( ! V_132 )
V_132 = F_75 ( & V_15 , V_224 ) ;
return V_132 ;
}
static long F_79 ( struct V_123 * V_123 , unsigned int V_195 ,
unsigned long V_196 )
{
struct V_1 * V_10 = F_42 ( V_123 ) ;
struct V_197 * V_198 ;
long V_162 = - V_234 ;
if ( ! V_10 )
return - V_4 ;
V_198 = V_10 -> V_8 ;
switch( V_195 ) {
case V_204 :
case V_205 :
case V_209 :
case V_211 :
case V_216 :
V_196 = ( unsigned long ) F_71 ( V_196 ) ;
case V_218 :
V_162 = F_62 ( V_10 , V_195 , V_196 ) ;
break;
case V_206 :
V_162 = F_76 ( V_10 , V_195 , V_196 ) ;
break;
case V_208 :
case V_207 :
V_162 = F_69 ( V_10 , V_195 , V_196 ) ;
break;
default:
if ( V_198 -> F_79 )
V_162 = V_198 -> F_79 ( V_10 , V_195 , V_196 ) ;
break;
}
return V_162 ;
}
static int
F_80 ( struct V_123 * V_123 , struct V_235 * V_236 )
{
struct V_1 * V_10 = F_42 ( V_123 ) ;
struct V_197 * V_198 ;
unsigned long V_237 ;
unsigned long V_57 ;
T_2 V_58 ;
if ( ! V_10 )
return - V_4 ;
V_198 = V_10 -> V_8 ;
if ( ! V_198 )
return - V_4 ;
F_3 ( & V_10 -> V_238 ) ;
if ( V_198 -> F_80 ) {
int V_239 ;
V_239 = V_198 -> F_80 ( V_10 , V_236 ) ;
F_5 ( & V_10 -> V_238 ) ;
return V_239 ;
}
V_57 = V_10 -> V_15 . V_225 ;
V_58 = V_10 -> V_15 . V_137 ;
V_237 = F_81 ( ( V_57 & ~ V_240 ) + V_58 ) >> V_241 ;
if ( V_236 -> V_242 >= V_237 ) {
if ( V_10 -> V_13 . V_243 ) {
F_5 ( & V_10 -> V_238 ) ;
return - V_147 ;
}
V_236 -> V_242 -= V_237 ;
V_57 = V_10 -> V_15 . V_228 ;
V_58 = V_10 -> V_15 . V_229 ;
}
F_5 ( & V_10 -> V_238 ) ;
V_236 -> V_244 = F_82 ( V_236 -> V_245 ) ;
F_83 ( V_123 , V_236 , V_57 ) ;
return F_84 ( V_236 , V_57 , V_58 ) ;
}
static int
F_85 ( struct V_122 * V_122 , struct V_123 * V_123 )
__acquires( &info->lock
static int
F_86 ( struct V_122 * V_122 , struct V_123 * V_123 )
__acquires( &info->lock
unsigned long F_87 ( struct V_123 * V_246 ,
unsigned long V_42 , unsigned long V_58 ,
unsigned long V_247 , unsigned long V_43 )
{
struct V_1 * const V_10 = V_246 -> V_126 ;
unsigned long V_248 = F_81 ( V_10 -> V_15 . V_137 ) ;
if ( V_247 > V_248 || V_58 > V_248 - V_247 )
return - V_147 ;
return ( unsigned long ) V_10 -> V_134 + V_247 ;
}
static int F_88 ( struct V_1 * V_119 )
{
const bool V_249 = V_119 -> V_43 & V_250 ;
V_119 -> V_43 &= ~ V_250 ;
#ifdef F_89
V_119 -> V_43 |= V_249 ? 0 : V_251 ;
#else
V_119 -> V_43 |= V_249 ? V_251 : 0 ;
#endif
if ( V_119 -> V_43 & V_251 && ! F_90 ( V_119 ) ) {
F_91 ( L_6
L_7 , V_119 -> V_15 . V_121 ) ;
return - V_252 ;
} else if ( ! ( V_119 -> V_43 & V_251 ) && F_90 ( V_119 ) ) {
F_91 ( L_8
L_7 , V_119 -> V_15 . V_121 ) ;
return - V_252 ;
}
return 0 ;
}
static bool F_92 ( struct V_253 * V_254 , struct V_253 * V_255 )
{
if ( V_254 -> V_256 == V_255 -> V_256 )
return true ;
if ( V_254 -> V_256 > V_255 -> V_256 && V_254 -> V_256 < V_255 -> V_256 + V_255 -> V_39 )
return true ;
return false ;
}
static bool F_93 ( struct V_257 * V_258 ,
struct V_257 * V_259 )
{
int V_35 , V_36 ;
if ( ! V_259 || ! V_258 )
return false ;
for ( V_35 = 0 ; V_35 < V_259 -> V_7 ; ++ V_35 ) {
struct V_253 * V_75 = & V_259 -> V_260 [ V_35 ] ;
for ( V_36 = 0 ; V_36 < V_258 -> V_7 ; ++ V_36 ) {
struct V_253 * V_261 = & V_258 -> V_260 [ V_36 ] ;
F_58 ( V_262 L_9 ,
( unsigned long long ) V_261 -> V_256 ,
( unsigned long long ) V_261 -> V_39 ,
( unsigned long long ) V_75 -> V_256 ,
( unsigned long long ) V_75 -> V_39 ) ;
if ( F_92 ( V_261 , V_75 ) )
return true ;
}
}
return false ;
}
static int F_94 ( struct V_257 * V_263 ,
const char * V_264 , bool V_265 )
{
int V_35 , V_162 ;
for ( V_35 = 0 ; V_35 < V_3 ; V_35 ++ ) {
struct V_257 * V_266 ;
if ( ! V_6 [ V_35 ] )
continue;
if ( ! ( V_6 [ V_35 ] -> V_43 & V_267 ) )
continue;
V_266 = V_6 [ V_35 ] -> V_268 ;
if ( F_93 ( V_266 , V_263 ) ||
( V_265 && V_266 && V_266 -> V_7 &&
V_266 -> V_260 [ 0 ] . V_256 == V_269 ) ) {
F_58 ( V_270 L_10 ,
V_264 , V_6 [ V_35 ] -> V_15 . V_121 ) ;
V_162 = F_95 ( V_6 [ V_35 ] ) ;
if ( V_162 )
return V_162 ;
}
}
return 0 ;
}
static int F_96 ( struct V_1 * V_1 )
{
int V_35 , V_162 ;
struct V_154 V_155 ;
struct V_164 V_179 ;
if ( F_88 ( V_1 ) )
return - V_252 ;
V_162 = F_94 ( V_1 -> V_268 ,
V_1 -> V_15 . V_121 ,
F_97 ( V_1 ) ) ;
if ( V_162 )
return V_162 ;
if ( V_271 == V_3 )
return - V_272 ;
V_271 ++ ;
for ( V_35 = 0 ; V_35 < V_3 ; V_35 ++ )
if ( ! V_6 [ V_35 ] )
break;
V_1 -> V_120 = V_35 ;
F_98 ( & V_1 -> V_7 , 1 ) ;
F_99 ( & V_1 -> V_11 ) ;
F_99 ( & V_1 -> V_238 ) ;
V_1 -> V_273 = F_100 ( V_274 , V_1 -> V_275 ,
F_101 ( V_276 , V_35 ) , NULL , L_5 , V_35 ) ;
if ( F_102 ( V_1 -> V_273 ) ) {
F_58 ( V_181 L_11 , V_35 , F_103 ( V_1 -> V_273 ) ) ;
V_1 -> V_273 = NULL ;
} else
F_104 ( V_1 ) ;
if ( V_1 -> V_277 . V_42 == NULL ) {
V_1 -> V_277 . V_42 = F_26 ( V_278 , V_102 ) ;
if ( V_1 -> V_277 . V_42 ) {
V_1 -> V_277 . V_39 = V_278 ;
V_1 -> V_277 . V_41 = 1 ;
V_1 -> V_277 . V_279 = 1 ;
V_1 -> V_277 . V_280 = 32 ;
V_1 -> V_277 . V_43 = V_281 ;
}
}
V_1 -> V_277 . V_24 = 0 ;
if ( ! V_1 -> V_277 . V_282 )
V_1 -> V_277 . V_282 = ~ ( T_2 ) 0 ;
if ( ! V_1 -> V_277 . V_283 )
V_1 -> V_277 . V_283 = ~ ( T_2 ) 0 ;
if ( ! V_1 -> V_168 . V_183 || ! V_1 -> V_168 . V_184 )
F_105 ( & V_1 -> V_168 ) ;
if ( V_1 -> V_284 )
F_106 ( V_1 -> V_273 , false ) ;
else
F_106 ( V_1 -> V_273 , true ) ;
F_55 ( & V_179 , & V_1 -> V_13 ) ;
F_60 ( & V_179 , & V_1 -> V_168 ) ;
V_6 [ V_35 ] = V_1 ;
V_155 . V_10 = V_1 ;
if ( ! V_285 )
F_64 () ;
if ( ! F_8 ( V_1 ) ) {
if ( ! V_285 )
F_65 () ;
return - V_4 ;
}
F_53 ( V_286 , & V_155 ) ;
F_63 ( V_1 ) ;
if ( ! V_285 )
F_65 () ;
return 0 ;
}
static int F_95 ( struct V_1 * V_1 )
{
struct V_154 V_155 ;
int V_35 , V_162 = 0 ;
V_35 = V_1 -> V_120 ;
if ( V_35 < 0 || V_35 >= V_3 || V_6 [ V_35 ] != V_1 )
return - V_147 ;
F_64 () ;
if ( ! F_8 ( V_1 ) ) {
F_65 () ;
return - V_4 ;
}
V_155 . V_10 = V_1 ;
V_162 = F_53 ( V_287 , & V_155 ) ;
F_63 ( V_1 ) ;
F_65 () ;
if ( V_162 )
return - V_147 ;
F_107 ( V_1 -> V_273 ) ;
F_108 ( V_1 ) ;
if ( V_1 -> V_277 . V_42 &&
( V_1 -> V_277 . V_43 & V_281 ) )
F_27 ( V_1 -> V_277 . V_42 ) ;
F_109 ( & V_1 -> V_168 ) ;
V_6 [ V_35 ] = NULL ;
V_271 -- ;
F_110 ( V_1 ) ;
V_155 . V_10 = V_1 ;
F_64 () ;
F_53 ( V_288 , & V_155 ) ;
F_65 () ;
F_6 ( V_1 ) ;
return 0 ;
}
int F_108 ( struct V_1 * V_1 )
{
int V_35 ;
V_35 = V_1 -> V_120 ;
if ( V_35 < 0 || V_35 >= V_3 || V_6 [ V_35 ] != V_1 )
return - V_147 ;
if ( V_1 -> V_273 ) {
F_111 ( V_274 , F_101 ( V_276 , V_35 ) ) ;
V_1 -> V_273 = NULL ;
}
return 0 ;
}
int F_112 ( struct V_257 * V_263 ,
const char * V_264 , bool V_265 )
{
int V_162 ;
F_3 ( & V_5 ) ;
V_162 = F_94 ( V_263 , V_264 , V_265 ) ;
F_5 ( & V_5 ) ;
return V_162 ;
}
int
F_113 ( struct V_1 * V_1 )
{
int V_162 ;
F_3 ( & V_5 ) ;
V_162 = F_96 ( V_1 ) ;
F_5 ( & V_5 ) ;
return V_162 ;
}
int
F_114 ( struct V_1 * V_1 )
{
int V_162 ;
F_3 ( & V_5 ) ;
V_162 = F_95 ( V_1 ) ;
F_5 ( & V_5 ) ;
return V_162 ;
}
void F_115 ( struct V_1 * V_10 , int V_95 )
{
struct V_154 V_155 ;
V_155 . V_10 = V_10 ;
if ( V_95 ) {
F_53 ( V_289 , & V_155 ) ;
V_10 -> V_95 = V_290 ;
} else {
V_10 -> V_95 = V_96 ;
F_53 ( V_291 , & V_155 ) ;
}
}
static int T_11
F_116 ( void )
{
int V_162 ;
if ( ! F_117 ( L_12 , 0 , NULL , & V_292 ) )
return - V_139 ;
V_162 = F_118 ( V_276 , L_12 , & V_293 ) ;
if ( V_162 ) {
F_58 ( L_13 , V_276 ) ;
goto V_294;
}
V_274 = F_119 ( V_295 , L_14 ) ;
if ( F_102 ( V_274 ) ) {
V_162 = F_103 ( V_274 ) ;
F_120 ( L_15 , V_162 ) ;
V_274 = NULL ;
goto V_296;
}
return 0 ;
V_296:
F_121 ( V_276 , L_12 ) ;
V_294:
F_122 ( L_12 , NULL ) ;
return V_162 ;
}
static void T_12
F_123 ( void )
{
F_122 ( L_12 , NULL ) ;
F_124 ( V_274 ) ;
F_121 ( V_276 , L_12 ) ;
}
int F_125 ( struct V_1 * V_10 )
{
struct V_154 V_155 ;
struct V_12 V_13 = V_10 -> V_13 ;
struct V_297 * V_117 , * V_48 ;
struct V_298 * V_168 ;
struct V_164 * V_116 , V_179 ;
int V_132 = 1 ;
F_126 (pos, n, &info->modelist) {
V_168 = F_127 ( V_117 , struct V_298 , V_299 ) ;
V_116 = & V_168 -> V_179 ;
F_128 ( & V_13 , V_116 ) ;
V_13 . V_153 = V_300 ;
V_132 = F_54 ( V_10 , & V_13 ) ;
F_55 ( & V_179 , & V_13 ) ;
if ( V_132 || ! F_56 ( V_116 , & V_179 ) ) {
F_129 ( V_117 ) ;
F_27 ( V_117 ) ;
}
}
V_132 = 1 ;
if ( ! F_59 ( & V_10 -> V_168 ) ) {
V_155 . V_10 = V_10 ;
V_132 = F_53 ( V_301 , & V_155 ) ;
}
return V_132 ;
}
