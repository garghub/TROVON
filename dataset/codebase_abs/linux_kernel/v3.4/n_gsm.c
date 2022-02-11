static inline T_1 F_1 ( T_1 V_1 , T_1 V_2 )
{
return V_3 [ V_1 ^ V_2 ] ;
}
static inline T_1 F_2 ( T_1 V_1 , T_1 * V_2 , int V_4 )
{
while ( V_4 -- )
V_1 = V_3 [ V_1 ^ * V_2 ++ ] ;
return V_1 ;
}
static int F_3 ( unsigned int * V_5 , T_1 V_2 )
{
* V_5 <<= 7 ;
* V_5 |= V_2 >> 1 ;
return V_2 & V_6 ;
}
static T_1 F_4 ( const struct V_7 * V_8 )
{
T_1 V_9 = 0 ;
if ( V_8 -> V_10 )
V_9 |= V_11 ;
if ( V_8 -> V_12 & V_13 )
V_9 |= V_14 ;
if ( V_8 -> V_12 & V_15 )
V_9 |= V_16 ;
if ( V_8 -> V_12 & V_17 )
V_9 |= V_18 ;
if ( V_8 -> V_12 & V_19 )
V_9 |= V_20 ;
return V_9 ;
}
static void F_5 ( const char * V_21 , int V_22 , int V_23 ,
T_1 V_24 , const T_1 * V_25 , int V_26 )
{
if ( ! ( V_27 & 1 ) )
return;
F_6 ( L_1 , V_21 , V_22 , L_2 [ V_23 ] ) ;
switch ( V_24 & ~ V_28 ) {
case V_29 :
F_7 ( L_3 ) ;
break;
case V_30 :
F_7 ( L_4 ) ;
break;
case V_31 :
F_7 ( L_5 ) ;
break;
case V_32 :
F_7 ( L_6 ) ;
break;
case V_33 :
F_7 ( L_7 ) ;
break;
case V_34 :
F_7 ( L_8 ) ;
break;
default:
if ( ! ( V_24 & 0x01 ) ) {
F_7 ( L_9 ,
( V_24 & 0x0E ) >> 1 , ( V_24 & 0xE ) >> 5 ) ;
} else switch ( V_24 & 0x0F ) {
case V_35 :
F_7 ( L_10 , ( V_24 & 0xE0 ) >> 5 ) ;
break;
case V_36 :
F_7 ( L_11 , ( V_24 & 0xE0 ) >> 5 ) ;
break;
case V_37 :
F_7 ( L_12 , ( V_24 & 0xE0 ) >> 5 ) ;
break;
default:
F_7 ( L_13 , V_24 ) ;
}
}
if ( V_24 & V_28 )
F_7 ( L_14 ) ;
else
F_7 ( L_15 ) ;
if ( V_26 ) {
int V_38 = 0 ;
while ( V_26 -- ) {
if ( V_38 % 8 == 0 ) {
F_7 ( L_16 ) ;
F_8 ( L_17 ) ;
}
F_7 ( L_18 , * V_25 ++ ) ;
V_38 ++ ;
}
}
F_7 ( L_16 ) ;
}
static int F_9 ( const T_1 * V_39 , T_1 * V_40 , int V_4 )
{
int V_41 = 0 ;
while ( V_4 -- ) {
if ( * V_39 == V_42 || * V_39 == V_43
|| * V_39 == V_44 || * V_39 == V_45 ) {
* V_40 ++ = V_43 ;
* V_40 ++ = * V_39 ++ ^ V_46 ;
V_41 ++ ;
} else
* V_40 ++ = * V_39 ++ ;
V_41 ++ ;
}
return V_41 ;
}
static void F_10 ( struct V_47 * V_48 , int V_22 , int V_23 , int V_24 )
{
int V_4 ;
T_1 V_49 [ 10 ] ;
T_1 V_50 [ 3 ] ;
switch ( V_48 -> V_51 ) {
case 0 :
V_49 [ 0 ] = V_52 ;
V_49 [ 1 ] = ( V_22 << 2 ) | ( V_23 << 1 ) | V_6 ;
V_49 [ 2 ] = V_24 ;
V_49 [ 3 ] = V_6 ;
V_49 [ 4 ] = 0xFF - F_2 ( V_53 , V_49 + 1 , 3 ) ;
V_49 [ 5 ] = V_52 ;
V_4 = 6 ;
break;
case 1 :
case 2 :
V_50 [ 0 ] = ( V_22 << 2 ) | ( V_23 << 1 ) | V_6 ;
V_50 [ 1 ] = V_24 ;
V_50 [ 2 ] = 0xFF - F_2 ( V_53 , V_50 , 2 ) ;
V_4 = F_9 ( V_50 , V_49 + 1 , 3 ) ;
V_49 [ 0 ] = V_42 ;
V_49 [ V_4 + 1 ] = V_42 ;
V_4 += 2 ;
break;
default:
F_11 ( 1 ) ;
return;
}
V_48 -> V_40 ( V_48 , V_49 , V_4 ) ;
F_5 ( L_19 , V_22 , V_23 , V_24 , NULL , 0 ) ;
}
static inline void F_12 ( struct V_47 * V_48 , int V_22 , int V_24 )
{
F_10 ( V_48 , V_22 , 0 , V_24 ) ;
}
static inline void F_13 ( struct V_47 * V_48 , int V_22 , int V_24 )
{
F_10 ( V_48 , V_22 , 1 , V_24 ) ;
}
static struct V_54 * F_14 ( struct V_47 * V_48 , T_1 V_22 , int V_4 ,
T_1 V_55 )
{
struct V_54 * V_56 = F_15 ( sizeof( struct V_54 ) + V_4 + V_57 ,
V_58 ) ;
if ( V_56 == NULL )
return NULL ;
V_56 -> V_25 = V_56 -> V_59 + V_57 - 1 ;
V_56 -> V_4 = V_4 ;
V_56 -> V_22 = V_22 ;
V_56 -> V_55 = V_55 ;
V_56 -> V_60 = NULL ;
return V_56 ;
}
static void F_16 ( struct V_47 * V_48 )
{
struct V_54 * V_61 = V_48 -> V_62 ;
int V_4 ;
int V_63 = 0 ;
if ( V_48 -> V_64 )
return;
while ( V_48 -> V_62 != NULL ) {
V_61 = V_48 -> V_62 ;
if ( V_48 -> V_51 != 0 ) {
V_48 -> V_65 [ 0 ] = V_42 ;
V_4 = F_9 ( V_61 -> V_25 ,
V_48 -> V_65 + 1 , V_61 -> V_4 ) ;
V_48 -> V_65 [ V_4 + 1 ] = V_42 ;
V_4 += 2 ;
} else {
V_48 -> V_65 [ 0 ] = V_52 ;
memcpy ( V_48 -> V_65 + 1 , V_61 -> V_25 , V_61 -> V_4 ) ;
V_48 -> V_65 [ V_61 -> V_4 + 1 ] = V_52 ;
V_4 = V_61 -> V_4 + 2 ;
}
if ( V_27 & 4 )
F_17 ( L_20 ,
V_66 ,
V_48 -> V_65 , V_4 ) ;
if ( V_48 -> V_40 ( V_48 , V_48 -> V_65 + V_63 ,
V_4 - V_63 ) < 0 )
break;
V_48 -> V_62 = V_61 -> V_60 ;
if ( V_48 -> V_62 == NULL )
V_48 -> V_67 = NULL ;
V_48 -> V_68 -= V_61 -> V_4 ;
F_18 ( V_61 ) ;
V_63 = 1 ;
}
}
static void F_19 ( struct V_7 * V_8 , struct V_54 * V_61 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
T_1 * V_69 = V_61 -> V_25 ;
T_1 * V_1 = V_69 + V_61 -> V_4 ;
if ( V_48 -> V_51 == 0 ) {
if ( V_61 -> V_4 < 128 )
* -- V_69 = ( V_61 -> V_4 << 1 ) | V_6 ;
else {
* -- V_69 = ( V_61 -> V_4 >> 7 ) ;
* -- V_69 = ( V_61 -> V_4 & 127 ) << 1 ;
}
}
* -- V_69 = V_61 -> V_55 ;
if ( V_48 -> V_70 )
* -- V_69 = ( V_61 -> V_22 << 2 ) | 2 | V_6 ;
else
* -- V_69 = ( V_61 -> V_22 << 2 ) | V_6 ;
* V_1 = F_2 ( V_53 , V_69 , V_61 -> V_25 - V_69 ) ;
if ( V_61 -> V_55 == V_33 || V_61 -> V_55 == ( V_33 | V_28 ) )
* V_1 = F_2 ( * V_1 , V_61 -> V_25 , V_61 -> V_4 ) ;
* V_1 = 0xFF - * V_1 ;
F_5 ( L_21 , V_61 -> V_22 , V_48 -> V_70 , V_61 -> V_55 ,
V_61 -> V_25 , V_61 -> V_4 ) ;
V_61 -> V_4 += ( V_61 -> V_25 - V_69 ) + 1 ;
V_61 -> V_25 = V_69 ;
if ( V_48 -> V_67 )
V_48 -> V_67 -> V_60 = V_61 ;
else
V_48 -> V_62 = V_61 ;
V_48 -> V_67 = V_61 ;
V_48 -> V_68 += V_61 -> V_4 ;
F_16 ( V_48 ) ;
}
static void F_20 ( struct V_7 * V_8 , struct V_54 * V_61 )
{
unsigned long V_71 ;
F_21 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
F_19 ( V_8 , V_61 ) ;
F_22 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
}
static int F_23 ( struct V_47 * V_48 , struct V_7 * V_8 )
{
struct V_54 * V_61 ;
T_1 * V_69 ;
int V_4 , V_73 , V_74 ;
int V_75 = V_8 -> V_76 - 1 ;
V_73 = 0 ;
while( 1 ) {
V_4 = F_24 ( V_8 -> V_77 ) ;
if ( V_4 == 0 )
return V_73 ;
if ( V_4 > V_48 -> V_78 )
V_4 = V_48 -> V_78 ;
V_74 = V_4 + V_75 ;
V_61 = F_14 ( V_48 , V_8 -> V_22 , V_74 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return - V_80 ;
V_69 = V_61 -> V_25 ;
switch ( V_8 -> V_76 ) {
case 1 :
break;
case 2 :
* V_69 ++ = F_4 ( V_8 ) ;
break;
}
F_11 ( F_25 ( V_8 -> V_77 , V_69 , V_4 , & V_8 -> V_81 ) != V_4 ) ;
F_19 ( V_8 , V_61 ) ;
V_73 += V_74 ;
}
return V_73 ;
}
static int F_26 ( struct V_47 * V_48 ,
struct V_7 * V_8 )
{
struct V_54 * V_61 ;
T_1 * V_69 ;
int V_4 , V_74 ;
int V_82 = 0 , V_83 = 0 ;
int V_84 = 0 ;
if ( V_8 -> V_76 == 4 )
V_84 = 1 ;
if ( V_8 -> V_85 == NULL ) {
V_8 -> V_85 = F_27 ( & V_8 -> V_86 ) ;
if ( V_8 -> V_85 == NULL )
return 0 ;
V_83 = 1 ;
}
V_4 = V_8 -> V_85 -> V_4 + V_84 ;
if ( V_4 > V_48 -> V_78 ) {
if ( V_8 -> V_76 == 3 ) {
F_28 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
return 0 ;
}
V_4 = V_48 -> V_78 ;
} else
V_82 = 1 ;
V_74 = V_4 + V_84 ;
V_61 = F_14 ( V_48 , V_8 -> V_22 , V_74 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return - V_80 ;
V_69 = V_61 -> V_25 ;
if ( V_8 -> V_76 == 4 ) {
* V_69 ++ = V_82 << 7 | V_83 << 6 | 1 ;
V_4 -- ;
}
memcpy ( V_69 , V_8 -> V_85 -> V_25 , V_4 ) ;
F_29 ( V_8 -> V_85 , V_4 ) ;
F_19 ( V_8 , V_61 ) ;
if ( V_82 ) {
F_28 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
}
return V_74 ;
}
static void F_30 ( struct V_47 * V_48 )
{
int V_4 ;
int V_87 = 1 ;
while ( V_87 < V_88 ) {
struct V_7 * V_8 ;
if ( V_48 -> V_68 > V_89 )
break;
V_8 = V_48 -> V_8 [ V_87 ] ;
if ( V_8 == NULL || V_8 -> V_64 ) {
V_87 ++ ;
continue;
}
if ( V_8 -> V_76 < 3 && ! V_8 -> V_90 )
V_4 = F_23 ( V_48 , V_8 ) ;
else
V_4 = F_26 ( V_48 , V_8 ) ;
if ( V_4 < 0 )
break;
if ( V_4 == 0 )
V_87 ++ ;
}
}
static void F_31 ( struct V_7 * V_8 )
{
unsigned long V_71 ;
F_21 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
if ( V_8 -> V_48 -> V_68 == 0 ) {
if ( V_8 -> V_90 )
F_26 ( V_8 -> V_48 , V_8 ) ;
else
F_23 ( V_8 -> V_48 , V_8 ) ;
} else if ( V_8 -> V_48 -> V_68 < V_91 )
F_30 ( V_8 -> V_48 ) ;
F_22 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
}
static void F_32 ( struct V_47 * V_48 , int V_92 , T_1 * V_25 ,
int V_26 )
{
struct V_54 * V_61 ;
V_61 = F_14 ( V_48 , 0 , V_26 + 2 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_92 & 0xFE ) << 1 | V_6 ;
V_61 -> V_25 [ 1 ] = ( V_26 << 1 ) | V_6 ;
memcpy ( V_61 -> V_25 + 2 , V_25 , V_26 ) ;
F_20 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_33 ( struct V_93 * V_94 , struct V_7 * V_8 ,
T_2 V_95 , int V_96 )
{
int V_97 = 0 ;
T_1 V_98 = 0 ;
if ( V_96 == 2 )
V_95 = V_95 & 0x7f ;
else {
V_98 = V_95 & 0x7f ;
V_95 = ( V_95 >> 7 ) & 0x7f ;
} ;
if ( V_95 & V_11 ) {
V_8 -> V_64 = 1 ;
}
if ( V_95 & V_14 ) {
V_97 |= V_99 | V_13 ;
V_8 -> V_64 = 0 ;
F_31 ( V_8 ) ;
}
if ( V_95 & V_16 )
V_97 |= V_15 | V_100 ;
if ( V_95 & V_18 )
V_97 |= V_17 ;
if ( V_95 & V_20 )
V_97 |= V_19 ;
if ( V_94 ) {
if ( ( V_97 & V_19 ) == 0 && ( V_8 -> V_101 & V_19 ) )
if ( ! ( V_94 -> V_102 -> V_103 & V_104 ) )
F_34 ( V_94 ) ;
if ( V_98 & 0x01 )
F_35 ( V_94 , 0 , V_105 ) ;
}
V_8 -> V_101 = V_97 ;
}
static void F_36 ( struct V_47 * V_48 , T_1 * V_25 , int V_96 )
{
unsigned int V_22 = 0 ;
unsigned int V_95 = 0 ;
struct V_7 * V_8 ;
int V_4 = V_96 ;
T_1 * V_69 = V_25 ;
struct V_93 * V_94 ;
while ( F_3 ( & V_22 , * V_69 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_4 -- ;
if ( V_4 <= 0 )
return;
V_22 >>= 1 ;
if ( V_22 == 0 || V_22 >= V_88 || V_48 -> V_8 [ V_22 ] == NULL )
return;
V_8 = V_48 -> V_8 [ V_22 ] ;
while ( F_3 ( & V_95 , * V_69 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_94 = F_37 ( & V_8 -> V_106 ) ;
F_33 ( V_94 , V_8 , V_95 , V_96 ) ;
if ( V_94 ) {
F_38 ( V_94 ) ;
F_39 ( V_94 ) ;
}
F_32 ( V_48 , V_107 , V_25 , V_96 ) ;
}
static void F_40 ( struct V_47 * V_48 , T_1 * V_25 , int V_96 )
{
struct V_93 * V_94 ;
unsigned int V_22 = 0 ;
T_1 V_108 ;
int V_4 = V_96 ;
T_1 * V_69 = V_25 ;
while ( F_3 ( & V_22 , * V_69 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_4 -- ;
if ( V_4 <= 0 )
return;
V_22 >>= 1 ;
if ( V_22 == 0 || V_22 >= V_88 || V_48 -> V_8 [ V_22 ] == NULL )
return;
V_108 = * V_69 ;
if ( ( V_108 & 1 ) == 0 )
return;
V_94 = F_37 ( & V_48 -> V_8 [ V_22 ] -> V_106 ) ;
if ( V_94 ) {
if ( V_108 & 2 )
F_35 ( V_94 , 0 , V_109 ) ;
if ( V_108 & 4 )
F_35 ( V_94 , 0 , V_110 ) ;
if ( V_108 & 8 )
F_35 ( V_94 , 0 , V_111 ) ;
F_41 ( V_94 ) ;
F_39 ( V_94 ) ;
}
F_32 ( V_48 , V_112 , V_25 , V_96 ) ;
}
static void F_42 ( struct V_47 * V_48 , unsigned int V_113 ,
T_1 * V_25 , int V_96 )
{
T_1 V_114 [ 1 ] ;
switch ( V_113 ) {
case V_115 : {
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
if ( V_8 ) {
V_8 -> V_116 = 1 ;
V_48 -> V_116 = 1 ;
F_43 ( V_8 ) ;
}
}
break;
case V_117 :
F_32 ( V_48 , V_117 , V_25 , V_96 ) ;
break;
case V_118 :
V_48 -> V_64 = 1 ;
F_32 ( V_48 , V_118 , NULL , 0 ) ;
break;
case V_119 :
V_48 -> V_64 = 0 ;
F_32 ( V_48 , V_119 , NULL , 0 ) ;
F_16 ( V_48 ) ;
break;
case V_107 :
F_36 ( V_48 , V_25 , V_96 ) ;
break;
case V_112 :
F_40 ( V_48 , V_25 , V_96 ) ;
break;
case V_120 :
F_32 ( V_48 , V_120 , NULL , 0 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
default:
V_114 [ 0 ] = V_113 ;
F_32 ( V_48 , V_124 , V_114 , 1 ) ;
break;
}
}
static void F_44 ( struct V_47 * V_48 , unsigned int V_113 ,
T_1 * V_25 , int V_96 )
{
struct V_125 * V_55 ;
unsigned long V_71 ;
F_21 ( & V_48 -> V_126 , V_71 ) ;
V_55 = V_48 -> V_127 ;
V_113 |= 1 ;
if ( V_55 != NULL && ( V_113 == V_55 -> V_92 || V_113 == V_124 ) ) {
F_45 ( & V_48 -> V_128 ) ;
V_48 -> V_127 = NULL ;
if ( V_113 == V_124 )
V_55 -> error = - V_129 ;
V_55 -> V_130 = 1 ;
F_46 ( & V_48 -> V_131 ) ;
}
F_22 ( & V_48 -> V_126 , V_71 ) ;
}
static void F_47 ( struct V_47 * V_48 , struct V_125 * V_55 )
{
struct V_54 * V_61 = F_14 ( V_48 , 0 , V_55 -> V_4 + 1 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_55 -> V_92 << 1 ) | 2 | V_6 ;
memcpy ( V_61 -> V_25 + 1 , V_55 -> V_25 , V_55 -> V_4 ) ;
F_20 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_48 ( unsigned long V_25 )
{
struct V_47 * V_48 = (struct V_47 * ) V_25 ;
struct V_125 * V_55 ;
unsigned long V_71 ;
F_21 ( & V_48 -> V_126 , V_71 ) ;
V_55 = V_48 -> V_127 ;
if ( V_55 ) {
V_48 -> V_132 -- ;
if ( V_48 -> V_132 == 0 ) {
V_48 -> V_127 = NULL ;
V_55 -> error = - V_133 ;
V_55 -> V_130 = 1 ;
F_22 ( & V_48 -> V_126 , V_71 ) ;
F_46 ( & V_48 -> V_131 ) ;
return;
}
F_47 ( V_48 , V_55 ) ;
F_49 ( & V_48 -> V_128 , V_134 + V_48 -> V_135 * V_136 / 100 ) ;
}
F_22 ( & V_48 -> V_126 , V_71 ) ;
}
static struct V_125 * F_50 ( struct V_47 * V_48 ,
unsigned int V_113 , T_1 * V_25 , int V_96 )
{
struct V_125 * V_55 = F_51 ( sizeof( struct V_125 ) ,
V_137 ) ;
unsigned long V_71 ;
if ( V_55 == NULL )
return NULL ;
V_138:
F_52 ( V_48 -> V_131 , V_48 -> V_127 == NULL ) ;
F_21 ( & V_48 -> V_126 , V_71 ) ;
if ( V_48 -> V_127 != NULL ) {
F_22 ( & V_48 -> V_126 , V_71 ) ;
goto V_138;
}
V_55 -> V_92 = V_113 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_4 = V_96 ;
V_48 -> V_127 = V_55 ;
V_48 -> V_132 = V_48 -> V_139 ;
F_49 ( & V_48 -> V_128 , V_134 + V_48 -> V_135 * V_136 / 100 ) ;
F_47 ( V_48 , V_55 ) ;
F_22 ( & V_48 -> V_126 , V_71 ) ;
return V_55 ;
}
static int F_53 ( struct V_47 * V_48 , struct V_125 * V_24 )
{
int V_140 ;
F_52 ( V_48 -> V_131 , V_24 -> V_130 == 1 ) ;
V_140 = V_24 -> error ;
F_18 ( V_24 ) ;
return V_140 ;
}
static void F_54 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_141 ) ;
if ( V_27 & 8 )
F_8 ( L_22 , V_8 -> V_22 ) ;
V_8 -> V_142 = V_143 ;
if ( V_8 -> V_22 != 0 ) {
struct V_93 * V_94 = F_37 ( & V_8 -> V_106 ) ;
if ( V_94 ) {
F_34 ( V_94 ) ;
F_39 ( V_94 ) ;
}
F_55 ( V_8 -> V_77 ) ;
} else
V_8 -> V_48 -> V_116 = 1 ;
F_46 ( & V_8 -> V_48 -> V_131 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_141 ) ;
V_8 -> V_142 = V_144 ;
if ( V_27 & 8 )
F_8 ( L_23 , V_8 -> V_22 ) ;
F_46 ( & V_8 -> V_48 -> V_131 ) ;
}
static void F_57 ( unsigned long V_25 )
{
struct V_7 * V_8 = (struct V_7 * ) V_25 ;
struct V_47 * V_48 = V_8 -> V_48 ;
switch ( V_8 -> V_142 ) {
case V_145 :
V_8 -> V_146 -- ;
if ( V_8 -> V_146 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_49 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
} else
F_54 ( V_8 ) ;
break;
case V_147 :
V_8 -> V_146 -- ;
if ( V_8 -> V_146 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_49 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
} else
F_54 ( V_8 ) ;
break;
}
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_142 == V_144 || V_8 -> V_142 == V_145 )
return;
V_8 -> V_146 = V_48 -> V_139 ;
V_8 -> V_142 = V_145 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_49 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_142 == V_143 || V_8 -> V_142 == V_147 )
return;
V_8 -> V_146 = V_48 -> V_139 ;
V_8 -> V_142 = V_147 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_49 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
}
static void F_59 ( struct V_7 * V_8 , T_1 * V_25 , int V_96 )
{
struct V_148 * V_106 = & V_8 -> V_106 ;
struct V_93 * V_94 = F_37 ( V_106 ) ;
unsigned int V_95 = 0 ;
int V_4 = V_96 ;
if ( V_27 & 16 )
F_8 ( L_24 , V_4 , V_94 ) ;
if ( V_94 ) {
switch ( V_8 -> V_76 ) {
case 4 :
break;
case 3 :
break;
case 2 :
while ( F_3 ( & V_95 , * V_25 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
F_33 ( V_94 , V_8 , V_95 , V_96 ) ;
case 1 :
default:
F_60 ( V_94 , V_25 , V_4 ) ;
F_41 ( V_94 ) ;
}
F_39 ( V_94 ) ;
}
}
static void F_61 ( struct V_7 * V_8 , T_1 * V_25 , int V_4 )
{
unsigned int V_113 = 0 ;
while ( V_4 -- > 0 ) {
if ( F_3 ( & V_113 , * V_25 ++ ) == 1 ) {
int V_96 = * V_25 ++ ;
V_4 -- ;
V_96 >>= 1 ;
if ( V_96 > V_4 )
return;
if ( V_113 & 1 )
F_42 ( V_8 -> V_48 , V_113 ,
V_25 , V_96 ) ;
else
F_44 ( V_8 -> V_48 , V_113 ,
V_25 , V_96 ) ;
return;
}
}
}
static struct V_7 * F_62 ( struct V_47 * V_48 , int V_22 )
{
struct V_7 * V_8 = F_51 ( sizeof( struct V_7 ) , V_58 ) ;
if ( V_8 == NULL )
return NULL ;
F_63 ( & V_8 -> V_81 ) ;
F_64 ( & V_8 -> V_149 ) ;
F_65 ( & V_8 -> V_150 ) ;
V_8 -> V_77 = & V_8 -> V_151 ;
if ( F_66 ( & V_8 -> V_151 , 4096 , V_137 ) < 0 ) {
F_18 ( V_8 ) ;
return NULL ;
}
F_67 ( & V_8 -> V_86 ) ;
F_68 ( & V_8 -> V_141 ) ;
V_8 -> V_141 . V_152 = F_57 ;
V_8 -> V_141 . V_25 = ( unsigned long ) V_8 ;
F_69 ( & V_8 -> V_106 ) ;
V_8 -> V_106 . V_153 = & V_154 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_76 = V_48 -> V_76 ;
V_8 -> V_142 = V_143 ;
if ( V_22 )
V_8 -> V_25 = F_59 ;
else
V_8 -> V_25 = F_61 ;
V_48 -> V_8 [ V_22 ] = V_8 ;
return V_8 ;
}
static void F_70 ( struct V_155 * V_149 )
{
struct V_7 * V_8 = F_71 ( V_149 , struct V_7 , V_149 ) ;
F_72 ( & V_8 -> V_141 ) ;
V_8 -> V_48 -> V_8 [ V_8 -> V_22 ] = NULL ;
F_73 ( V_8 -> V_77 ) ;
while ( ( V_8 -> V_85 = F_27 ( & V_8 -> V_86 ) ) )
F_28 ( V_8 -> V_85 ) ;
F_18 ( V_8 ) ;
}
static inline void F_74 ( struct V_7 * V_8 )
{
F_75 ( & V_8 -> V_149 ) ;
}
static inline void F_76 ( struct V_7 * V_8 )
{
F_77 ( & V_8 -> V_149 , F_70 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_93 * V_94 = F_37 ( & V_8 -> V_106 ) ;
if ( V_94 ) {
F_79 ( V_94 ) ;
F_39 ( V_94 ) ;
}
F_76 ( V_8 ) ;
}
static void F_80 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
T_1 V_23 ;
int V_156 ;
if ( ( V_48 -> V_24 & ~ V_28 ) == V_33 )
V_48 -> V_1 = F_2 ( V_48 -> V_1 , V_48 -> V_114 , V_48 -> V_4 ) ;
if ( V_48 -> V_51 == 0 ) {
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_157 ) ;
}
if ( V_48 -> V_1 != V_158 ) {
V_48 -> V_159 ++ ;
if ( V_27 & 4 )
F_8 ( L_25 , V_48 -> V_1 ) ;
return;
}
V_156 = V_48 -> V_156 >> 1 ;
if ( V_156 >= V_88 )
goto V_160;
V_23 = V_48 -> V_156 & 1 ;
F_5 ( L_26 , V_156 , V_23 , V_48 -> V_24 , V_48 -> V_114 , V_48 -> V_4 ) ;
V_23 ^= 1 - V_48 -> V_70 ;
V_8 = V_48 -> V_8 [ V_156 ] ;
switch ( V_48 -> V_24 ) {
case V_29 | V_28 :
if ( V_23 == 0 )
goto V_160;
if ( V_8 == NULL )
V_8 = F_62 ( V_48 , V_156 ) ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_116 )
F_12 ( V_48 , V_156 , V_32 ) ;
else {
F_12 ( V_48 , V_156 , V_30 ) ;
F_56 ( V_8 ) ;
}
break;
case V_31 | V_28 :
if ( V_23 == 0 )
goto V_160;
if ( V_8 == NULL || V_8 -> V_142 == V_143 ) {
F_12 ( V_48 , V_156 , V_32 ) ;
return;
}
F_12 ( V_48 , V_156 , V_30 ) ;
F_54 ( V_8 ) ;
break;
case V_30 :
case V_30 | V_28 :
if ( V_23 == 0 || V_8 == NULL )
break;
switch ( V_8 -> V_142 ) {
case V_147 :
F_54 ( V_8 ) ;
break;
case V_145 :
F_56 ( V_8 ) ;
break;
}
break;
case V_32 :
case V_32 | V_28 :
if ( V_23 )
goto V_160;
if ( V_8 == NULL )
return;
F_54 ( V_8 ) ;
break;
case V_33 :
case V_33 | V_28 :
case V_34 :
case V_34 | V_28 :
#if 0
if (cr)
goto invalid;
#endif
if ( V_8 == NULL || V_8 -> V_142 != V_144 ) {
F_13 ( V_48 , V_156 , V_32 | V_28 ) ;
return;
}
V_8 -> V_25 ( V_8 , V_48 -> V_114 , V_48 -> V_4 ) ;
break;
default:
goto V_160;
}
return;
V_160:
V_48 -> V_161 ++ ;
return;
}
static void F_81 ( struct V_47 * V_48 , unsigned char V_2 )
{
unsigned int V_4 ;
switch ( V_48 -> V_142 ) {
case V_162 :
if ( V_2 == V_52 ) {
V_48 -> V_142 = V_163 ;
V_48 -> V_156 = 0 ;
V_48 -> V_4 = 0 ;
V_48 -> V_1 = V_53 ;
}
break;
case V_163 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_156 , V_2 ) )
V_48 -> V_142 = V_164 ;
break;
case V_164 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_142 = V_165 ;
break;
case V_165 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_4 , V_2 ) ) {
if ( V_48 -> V_4 > V_48 -> V_166 ) {
V_48 -> V_167 ++ ;
V_48 -> V_142 = V_162 ;
break;
}
V_48 -> V_168 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_142 = V_169 ;
else
V_48 -> V_142 = V_170 ;
break;
}
V_48 -> V_142 = V_171 ;
break;
case V_171 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_4 = V_2 ;
V_48 -> V_4 |= V_4 << 7 ;
if ( V_48 -> V_4 > V_48 -> V_166 ) {
V_48 -> V_167 ++ ;
V_48 -> V_142 = V_162 ;
break;
}
V_48 -> V_168 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_142 = V_169 ;
else
V_48 -> V_142 = V_170 ;
break;
case V_170 :
V_48 -> V_114 [ V_48 -> V_168 ++ ] = V_2 ;
if ( V_48 -> V_168 == V_48 -> V_4 )
V_48 -> V_142 = V_169 ;
break;
case V_169 :
V_48 -> V_157 = V_2 ;
F_80 ( V_48 ) ;
V_48 -> V_142 = V_172 ;
break;
case V_172 :
if ( V_2 == V_52 ) {
V_48 -> V_142 = V_162 ;
break;
}
break;
}
}
static void F_82 ( struct V_47 * V_48 , unsigned char V_2 )
{
if ( V_2 == V_42 ) {
if ( V_48 -> V_142 == V_170 && V_48 -> V_168 ) {
V_48 -> V_168 -- ;
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_114 [ V_48 -> V_168 ] ) ;
V_48 -> V_4 = V_48 -> V_168 ;
F_80 ( V_48 ) ;
V_48 -> V_142 = V_173 ;
return;
}
if ( V_48 -> V_142 != V_173 ) {
V_48 -> V_161 ++ ;
V_48 -> V_142 = V_173 ;
}
return;
}
if ( V_2 == V_43 ) {
V_48 -> V_174 = 1 ;
return;
}
if ( V_48 -> V_142 == V_162 )
return;
if ( V_48 -> V_174 ) {
V_2 ^= V_46 ;
V_48 -> V_174 = 0 ;
}
switch ( V_48 -> V_142 ) {
case V_173 :
V_48 -> V_156 = 0 ;
V_48 -> V_142 = V_163 ;
V_48 -> V_1 = V_53 ;
case V_163 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_156 , V_2 ) )
V_48 -> V_142 = V_164 ;
break;
case V_164 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_168 = 0 ;
V_48 -> V_142 = V_170 ;
break;
case V_170 :
if ( V_48 -> V_168 > V_48 -> V_166 ) {
V_48 -> V_142 = V_175 ;
V_48 -> V_167 ++ ;
} else
V_48 -> V_114 [ V_48 -> V_168 ++ ] = V_2 ;
break;
case V_175 :
break;
}
}
static void F_83 ( struct V_47 * V_48 ,
unsigned char V_25 , unsigned char V_176 )
{
V_48 -> V_142 = V_162 ;
V_48 -> V_177 ++ ;
}
void F_84 ( struct V_47 * V_48 )
{
int V_87 ;
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_54 * V_178 ;
struct V_125 * V_179 ;
V_48 -> V_116 = 1 ;
F_85 ( & V_180 ) ;
for ( V_87 = 0 ; V_87 < V_181 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == V_48 ) {
V_47 [ V_87 ] = NULL ;
break;
}
}
F_86 ( & V_180 ) ;
F_11 ( V_87 == V_181 ) ;
if ( V_8 ) {
V_179 = F_50 ( V_48 , V_115 , NULL , 0 ) ;
if ( V_179 )
F_53 ( V_48 , V_179 ) ;
}
F_72 ( & V_48 -> V_128 ) ;
if ( V_8 ) {
V_8 -> V_116 = 1 ;
F_43 ( V_8 ) ;
F_87 ( V_48 -> V_131 ,
V_8 -> V_142 == V_143 ) ;
}
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
if ( V_48 -> V_8 [ V_87 ] )
F_78 ( V_48 -> V_8 [ V_87 ] ) ;
for ( V_178 = V_48 -> V_62 ; V_178 != NULL ; V_178 = V_48 -> V_62 ) {
V_48 -> V_62 = V_178 -> V_60 ;
F_18 ( V_178 ) ;
}
V_48 -> V_67 = NULL ;
}
int F_88 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_87 = 0 ;
F_68 ( & V_48 -> V_128 ) ;
V_48 -> V_128 . V_152 = F_48 ;
V_48 -> V_128 . V_25 = ( unsigned long ) V_48 ;
F_89 ( & V_48 -> V_131 ) ;
F_63 ( & V_48 -> V_126 ) ;
F_63 ( & V_48 -> V_72 ) ;
if ( V_48 -> V_51 == 0 )
V_48 -> V_182 = F_81 ;
else
V_48 -> V_182 = F_82 ;
V_48 -> error = F_83 ;
F_85 ( & V_180 ) ;
for ( V_87 = 0 ; V_87 < V_181 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == NULL ) {
V_48 -> V_183 = V_87 ;
V_47 [ V_87 ] = V_48 ;
break;
}
}
F_86 ( & V_180 ) ;
if ( V_87 == V_181 )
return - V_184 ;
V_8 = F_62 ( V_48 , 0 ) ;
if ( V_8 == NULL )
return - V_80 ;
V_48 -> V_116 = 0 ;
return 0 ;
}
void F_90 ( struct V_47 * V_48 )
{
F_18 ( V_48 -> V_65 ) ;
F_18 ( V_48 -> V_114 ) ;
F_18 ( V_48 ) ;
}
static void F_91 ( struct V_155 * V_149 )
{
struct V_47 * V_48 = F_71 ( V_149 , struct V_47 , V_149 ) ;
F_90 ( V_48 ) ;
}
static inline void F_92 ( struct V_47 * V_48 )
{
F_75 ( & V_48 -> V_149 ) ;
}
static inline void F_93 ( struct V_47 * V_48 )
{
F_77 ( & V_48 -> V_149 , F_91 ) ;
}
struct V_47 * F_94 ( void )
{
struct V_47 * V_48 = F_51 ( sizeof( struct V_47 ) , V_137 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_114 = F_15 ( V_185 + 1 , V_137 ) ;
if ( V_48 -> V_114 == NULL ) {
F_18 ( V_48 ) ;
return NULL ;
}
V_48 -> V_65 = F_15 ( 2 * V_185 + 2 , V_137 ) ;
if ( V_48 -> V_65 == NULL ) {
F_18 ( V_48 -> V_114 ) ;
F_18 ( V_48 ) ;
return NULL ;
}
F_63 ( & V_48 -> V_81 ) ;
F_64 ( & V_48 -> V_149 ) ;
V_48 -> V_141 = V_186 ;
V_48 -> V_135 = V_187 ;
V_48 -> V_139 = V_188 ;
V_48 -> V_79 = V_34 ;
V_48 -> V_76 = 1 ;
V_48 -> V_51 = 1 ;
V_48 -> V_166 = 64 ;
V_48 -> V_78 = 64 ;
V_48 -> V_116 = 1 ;
return V_48 ;
}
static int F_95 ( struct V_47 * V_48 , T_1 * V_25 , int V_4 )
{
if ( F_96 ( V_48 -> V_94 ) < V_4 ) {
F_97 ( V_189 , & V_48 -> V_94 -> V_71 ) ;
return - V_190 ;
}
if ( V_27 & 4 )
F_17 ( L_27 , V_66 ,
V_25 , V_4 ) ;
V_48 -> V_94 -> V_153 -> V_191 ( V_48 -> V_94 , V_25 , V_4 ) ;
return V_4 ;
}
static int F_98 ( struct V_93 * V_94 , struct V_47 * V_48 )
{
int V_192 , V_87 ;
int V_193 = V_48 -> V_183 << 6 ;
V_48 -> V_94 = F_99 ( V_94 ) ;
V_48 -> V_40 = F_95 ;
V_192 = F_88 ( V_48 ) ;
if ( V_192 != 0 )
F_39 ( V_48 -> V_94 ) ;
else {
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_100 ( V_194 , V_193 + V_87 , NULL ) ;
}
return V_192 ;
}
static void F_101 ( struct V_93 * V_94 , struct V_47 * V_48 )
{
int V_87 ;
int V_193 = V_48 -> V_183 << 6 ;
F_11 ( V_94 != V_48 -> V_94 ) ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_102 ( V_194 , V_193 + V_87 ) ;
F_84 ( V_48 ) ;
F_39 ( V_48 -> V_94 ) ;
V_48 -> V_94 = NULL ;
}
static void F_103 ( struct V_93 * V_94 , const unsigned char * V_195 ,
char * V_196 , int V_168 )
{
struct V_47 * V_48 = V_94 -> V_197 ;
const unsigned char * V_69 ;
char * V_198 ;
int V_87 ;
char V_114 [ 64 ] ;
char V_71 ;
if ( V_27 & 4 )
F_17 ( L_28 , V_66 ,
V_195 , V_168 ) ;
for ( V_87 = V_168 , V_69 = V_195 , V_198 = V_196 ; V_87 ; V_87 -- , V_69 ++ ) {
V_71 = * V_198 ++ ;
switch ( V_71 ) {
case V_199 :
V_48 -> V_182 ( V_48 , * V_69 ) ;
break;
case V_109 :
case V_105 :
case V_110 :
case V_111 :
V_48 -> error ( V_48 , * V_69 , V_71 ) ;
break;
default:
F_104 ( L_29 ,
F_105 ( V_94 , V_114 ) , V_71 ) ;
break;
}
}
}
static T_3 F_106 ( struct V_93 * V_94 )
{
return 0 ;
}
static void F_107 ( struct V_93 * V_94 )
{
}
static void F_108 ( struct V_93 * V_94 )
{
struct V_47 * V_48 = V_94 -> V_197 ;
F_101 ( V_94 , V_48 ) ;
F_107 ( V_94 ) ;
F_93 ( V_48 ) ;
}
static int F_109 ( struct V_93 * V_94 )
{
struct V_47 * V_48 ;
if ( V_94 -> V_153 -> V_191 == NULL )
return - V_200 ;
V_48 = F_94 () ;
if ( V_48 == NULL )
return - V_80 ;
V_94 -> V_197 = V_48 ;
V_94 -> V_201 = 65536 ;
V_48 -> V_51 = 1 ;
return F_98 ( V_94 , V_48 ) ;
}
static void F_110 ( struct V_93 * V_94 )
{
struct V_47 * V_48 = V_94 -> V_197 ;
unsigned long V_71 ;
F_111 ( V_189 , & V_94 -> V_71 ) ;
F_16 ( V_48 ) ;
if ( V_48 -> V_68 < V_91 ) {
F_21 ( & V_48 -> V_72 , V_71 ) ;
F_30 ( V_48 ) ;
F_22 ( & V_48 -> V_72 , V_71 ) ;
}
}
static T_3 F_112 ( struct V_93 * V_94 , struct V_202 * V_202 ,
unsigned char T_4 * V_114 , T_5 V_203 )
{
return - V_129 ;
}
static T_3 F_113 ( struct V_93 * V_94 , struct V_202 * V_202 ,
const unsigned char * V_114 , T_5 V_203 )
{
int V_204 = F_96 ( V_94 ) ;
if ( V_204 >= V_203 )
return V_94 -> V_153 -> V_191 ( V_94 , V_114 , V_203 ) ;
F_97 ( V_189 , & V_94 -> V_71 ) ;
return - V_205 ;
}
static unsigned int F_114 ( struct V_93 * V_94 , struct V_202 * V_202 ,
T_6 * V_206 )
{
unsigned int V_207 = 0 ;
struct V_47 * V_48 = V_94 -> V_197 ;
F_115 ( V_202 , & V_94 -> V_208 , V_206 ) ;
F_115 ( V_202 , & V_94 -> V_209 , V_206 ) ;
if ( F_116 ( V_202 ) )
V_207 |= V_210 ;
if ( ! F_117 ( V_94 ) && F_96 ( V_94 ) > 0 )
V_207 |= V_211 | V_212 ;
if ( V_48 -> V_116 )
V_207 |= V_210 ;
return V_207 ;
}
static int F_118 ( struct V_93 * V_94 , struct V_47 * V_48 ,
struct V_213 * V_2 )
{
int V_214 = 0 ;
int V_215 = 0 ;
if ( ( V_2 -> V_76 != 1 && V_2 -> V_76 != 2 ) || V_2 -> V_216 )
return - V_129 ;
if ( V_2 -> V_166 > V_185 || V_2 -> V_78 > V_217 || V_2 -> V_166 < 8 || V_2 -> V_78 < 8 )
return - V_200 ;
if ( V_2 -> V_139 < 3 )
return - V_200 ;
if ( V_2 -> V_218 > 1 )
return - V_200 ;
if ( V_2 -> V_70 > 1 )
return - V_200 ;
if ( V_2 -> V_87 == 0 || V_2 -> V_87 > 2 )
return - V_200 ;
if ( V_2 -> V_141 != 0 && V_2 -> V_141 != V_48 -> V_141 )
V_215 = 1 ;
if ( V_2 -> V_135 != 0 && V_2 -> V_135 != V_48 -> V_135 )
V_215 = 1 ;
if ( V_2 -> V_218 != V_48 -> V_51 )
V_215 = 1 ;
if ( V_2 -> V_76 != V_48 -> V_76 )
V_215 = 1 ;
if ( V_2 -> V_70 != V_48 -> V_70 )
V_214 = 1 ;
if ( V_2 -> V_166 != V_48 -> V_166 )
V_215 = 1 ;
if ( V_2 -> V_78 != V_48 -> V_78 )
V_215 = 1 ;
if ( V_214 || V_215 ) {
F_43 ( V_48 -> V_8 [ 0 ] ) ;
F_87 ( V_48 -> V_131 ,
V_48 -> V_8 [ 0 ] -> V_142 == V_143 ) ;
if ( F_119 ( V_219 ) )
return - V_220 ;
}
if ( V_215 )
F_84 ( V_48 ) ;
V_48 -> V_70 = V_2 -> V_70 ;
V_48 -> V_166 = V_2 -> V_166 ;
V_48 -> V_78 = V_2 -> V_78 ;
V_48 -> V_51 = V_2 -> V_218 ;
V_48 -> V_76 = V_2 -> V_76 ;
V_48 -> V_139 = V_2 -> V_139 ;
if ( V_2 -> V_87 == 1 )
V_48 -> V_79 = V_34 ;
else if ( V_2 -> V_87 == 2 )
V_48 -> V_79 = V_33 ;
if ( V_2 -> V_141 )
V_48 -> V_141 = V_2 -> V_141 ;
if ( V_2 -> V_135 )
V_48 -> V_135 = V_2 -> V_135 ;
if ( V_215 )
F_88 ( V_48 ) ;
if ( V_48 -> V_70 && V_214 )
F_58 ( V_48 -> V_8 [ 0 ] ) ;
return 0 ;
}
static int F_120 ( struct V_93 * V_94 , struct V_202 * V_202 ,
unsigned int V_92 , unsigned long V_221 )
{
struct V_213 V_2 ;
struct V_47 * V_48 = V_94 -> V_197 ;
switch ( V_92 ) {
case V_222 :
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_76 = V_48 -> V_76 ;
V_2 . V_218 = V_48 -> V_51 ;
V_2 . V_70 = V_48 -> V_70 ;
V_2 . V_141 = V_48 -> V_141 ;
V_2 . V_135 = V_48 -> V_135 ;
V_2 . V_223 = 0 ;
V_2 . V_139 = V_48 -> V_139 ;
if ( V_48 -> V_79 == V_34 )
V_2 . V_87 = 1 ;
else
V_2 . V_87 = 2 ;
F_8 ( L_30 , V_48 -> V_79 , V_2 . V_87 ) ;
V_2 . V_166 = V_48 -> V_166 ;
V_2 . V_78 = V_48 -> V_78 ;
V_2 . V_216 = 0 ;
if ( F_121 ( ( void * ) V_221 , & V_2 , sizeof( V_2 ) ) )
return - V_224 ;
return 0 ;
case V_225 :
if ( F_122 ( & V_2 , ( void * ) V_221 , sizeof( V_2 ) ) )
return - V_224 ;
return F_118 ( V_94 , V_48 , & V_2 ) ;
default:
return F_123 ( V_94 , V_202 , V_92 , V_221 ) ;
}
}
static int F_124 ( struct V_226 * V_90 )
{
F_8 ( L_31 , V_227 ) ;
F_125 ( V_90 ) ;
return 0 ;
}
static int F_126 ( struct V_226 * V_90 )
{
F_127 ( V_90 ) ;
return 0 ;
}
static struct V_228 * F_128 ( struct V_226 * V_90 )
{
return & ( (struct V_229 * ) F_129 ( V_90 ) ) -> V_230 ;
}
static void F_130 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_90 ) {
F_11 ( 1 ) ;
return;
}
V_8 -> V_76 = V_8 -> V_231 ;
V_8 -> V_25 = V_8 -> V_232 ;
F_131 ( V_8 -> V_90 ) ;
V_8 -> V_90 = NULL ;
}
static void F_132 ( struct V_155 * V_149 )
{
struct V_229 * V_233 ;
struct V_7 * V_8 ;
V_233 = F_71 ( V_149 , struct V_229 , V_149 ) ;
V_8 = V_233 -> V_8 ;
if ( V_8 -> V_90 ) {
F_133 ( V_8 -> V_90 ) ;
F_130 ( V_8 ) ;
}
}
static inline void F_134 ( struct V_229 * V_233 )
{
F_75 ( & V_233 -> V_149 ) ;
}
static inline void F_135 ( struct V_229 * V_233 )
{
F_77 ( & V_233 -> V_149 , F_132 ) ;
}
static int F_136 ( struct V_234 * V_85 ,
struct V_226 * V_90 )
{
struct V_229 * V_233 = (struct V_229 * ) F_129 ( V_90 ) ;
struct V_7 * V_8 = V_233 -> V_8 ;
F_134 ( V_233 ) ;
F_137 ( & V_8 -> V_86 , V_85 ) ;
F_138 ( V_90 ) . V_235 ++ ;
F_138 ( V_90 ) . V_68 += V_85 -> V_4 ;
F_31 ( V_8 ) ;
V_90 -> V_236 = V_134 ;
F_135 ( V_233 ) ;
return V_237 ;
}
static void F_139 ( struct V_226 * V_90 )
{
F_140 ( & V_90 -> V_238 , L_32 ) ;
F_138 ( V_90 ) . V_239 ++ ;
}
static void F_141 ( struct V_7 * V_8 ,
unsigned char * V_240 , int V_74 )
{
struct V_226 * V_90 = V_8 -> V_90 ;
struct V_234 * V_85 ;
struct V_229 * V_233 = (struct V_229 * ) F_129 ( V_90 ) ;
F_134 ( V_233 ) ;
V_85 = F_142 ( V_74 + V_241 ) ;
if ( ! V_85 ) {
F_138 ( V_90 ) . V_242 ++ ;
F_135 ( V_233 ) ;
return;
}
F_143 ( V_85 , V_241 ) ;
memcpy ( F_144 ( V_85 , V_74 ) , V_240 , V_74 ) ;
V_85 -> V_238 = V_90 ;
V_85 -> V_243 = F_145 ( V_244 ) ;
F_146 ( V_85 ) ;
F_138 ( V_90 ) . V_245 ++ ;
F_138 ( V_90 ) . V_246 += V_74 ;
F_135 ( V_233 ) ;
return;
}
int F_147 ( struct V_226 * V_90 , int V_247 )
{
struct V_229 * V_233 = (struct V_229 * ) F_129 ( V_90 ) ;
if ( ( V_247 < 8 ) || ( V_247 > V_233 -> V_8 -> V_48 -> V_78 ) )
return - V_200 ;
V_90 -> V_78 = V_247 ;
return 0 ;
}
static void F_148 ( struct V_226 * V_90 )
{
static const struct V_248 V_249 = {
. V_250 = F_124 ,
. V_251 = F_126 ,
. V_252 = F_136 ,
. V_253 = F_139 ,
. V_254 = F_128 ,
. V_255 = F_147 ,
} ;
V_90 -> V_256 = & V_249 ;
V_90 -> V_257 = V_258 ;
V_90 -> V_71 = V_259 | V_260 | V_261 ;
V_90 -> type = V_262 ;
V_90 -> V_263 = 10 ;
}
static void F_149 ( struct V_7 * V_8 )
{
struct V_229 * V_233 ;
F_8 ( L_33 ) ;
if ( ! V_8 -> V_90 )
return;
V_233 = (struct V_229 * ) F_129 ( V_8 -> V_90 ) ;
F_135 ( V_233 ) ;
}
static int F_150 ( struct V_7 * V_8 , struct V_264 * V_265 )
{
char * V_266 ;
int V_267 = 0 ;
struct V_226 * V_90 ;
struct V_229 * V_233 ;
if ( ! F_151 ( V_268 ) )
return - V_269 ;
if ( V_8 -> V_76 > 2 )
return - V_184 ;
if ( V_265 -> V_243 != F_152 ( V_244 ) )
return - V_270 ;
if ( V_265 -> V_76 != 3 && V_265 -> V_76 != 4 )
return - V_270 ;
F_8 ( L_34 ) ;
V_266 = L_35 ;
if ( V_265 -> V_271 [ 0 ] != '\0' )
V_266 = V_265 -> V_271 ;
V_90 = F_153 ( sizeof( struct V_229 ) ,
V_266 ,
F_148 ) ;
if ( ! V_90 ) {
F_154 ( L_36 ) ;
return - V_80 ;
}
V_90 -> V_78 = V_8 -> V_48 -> V_78 ;
V_233 = (struct V_229 * ) F_129 ( V_90 ) ;
V_233 -> V_8 = V_8 ;
F_64 ( & V_233 -> V_149 ) ;
strncpy ( V_265 -> V_271 , V_90 -> V_272 , V_273 ) ;
V_8 -> V_231 = V_8 -> V_76 ;
V_8 -> V_232 = V_8 -> V_25 ;
V_8 -> V_76 = V_265 -> V_76 ;
V_8 -> V_25 = F_141 ;
V_8 -> V_90 = V_90 ;
F_8 ( L_37 ) ;
V_267 = F_155 ( V_90 ) ;
if ( V_267 ) {
F_154 ( L_38 , V_267 ) ;
F_130 ( V_8 ) ;
return V_267 ;
}
return V_90 -> V_274 ;
}
static int F_156 ( struct V_7 * V_8 , T_1 V_98 )
{
T_1 V_9 [ 5 ] ;
struct V_125 * V_55 ;
int V_4 = 2 ;
if ( V_98 )
V_4 ++ ;
V_9 [ 0 ] = V_4 << 1 | V_6 ;
V_9 [ 1 ] = V_8 -> V_22 << 2 | 3 ;
V_9 [ 2 ] = F_4 ( V_8 ) << 1 | V_6 ;
if ( V_98 )
V_9 [ 3 ] = V_98 << 4 | 2 | V_6 ;
V_55 = F_50 ( V_8 -> V_48 , V_107 , V_9 , V_4 + 1 ) ;
if ( V_55 == NULL )
return - V_80 ;
return F_53 ( V_8 -> V_48 , V_55 ) ;
}
static int F_157 ( struct V_148 * V_106 )
{
struct V_7 * V_8 = F_71 ( V_106 , struct V_7 , V_106 ) ;
if ( V_8 -> V_142 != V_144 )
return 0 ;
if ( V_27 & 2 )
return 1 ;
return V_8 -> V_101 & V_19 ;
}
static void F_158 ( struct V_148 * V_106 , int V_275 )
{
struct V_7 * V_8 = F_71 ( V_106 , struct V_7 , V_106 ) ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_275 )
V_12 |= V_13 | V_15 ;
else
V_12 &= ~ ( V_13 | V_15 ) ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
F_156 ( V_8 , 0 ) ;
}
}
static int F_159 ( struct V_93 * V_94 , struct V_202 * V_276 )
{
struct V_47 * V_48 ;
struct V_7 * V_8 ;
struct V_148 * V_106 ;
unsigned int line = V_94 -> V_277 ;
unsigned int V_278 = line >> 6 ;
line = line & 0x3F ;
if ( V_278 >= V_181 )
return - V_279 ;
if ( V_47 [ V_278 ] == NULL )
return - V_280 ;
if ( line == 0 || line > 61 )
return - V_281 ;
V_48 = V_47 [ V_278 ] ;
if ( V_48 -> V_116 )
return - V_282 ;
V_8 = V_48 -> V_8 [ line ] ;
if ( V_8 == NULL )
V_8 = F_62 ( V_48 , line ) ;
if ( V_8 == NULL )
return - V_80 ;
V_106 = & V_8 -> V_106 ;
V_106 -> V_168 ++ ;
V_94 -> V_283 = V_8 ;
F_74 ( V_8 ) ;
F_74 ( V_8 -> V_48 -> V_8 [ 0 ] ) ;
F_92 ( V_8 -> V_48 ) ;
F_160 ( V_106 , V_94 ) ;
V_8 -> V_101 = 0 ;
F_97 ( V_284 , & V_106 -> V_71 ) ;
F_58 ( V_8 ) ;
return F_161 ( V_106 , V_94 , V_276 ) ;
}
static void F_162 ( struct V_93 * V_94 , struct V_202 * V_276 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
struct V_47 * V_48 ;
if ( V_8 == NULL )
return;
F_163 ( & V_8 -> V_150 ) ;
F_149 ( V_8 ) ;
F_164 ( & V_8 -> V_150 ) ;
V_48 = V_8 -> V_48 ;
if ( F_165 ( & V_8 -> V_106 , V_94 , V_276 ) == 0 )
goto V_285;
F_43 ( V_8 ) ;
F_166 ( & V_8 -> V_106 , V_94 ) ;
F_160 ( & V_8 -> V_106 , NULL ) ;
V_285:
F_76 ( V_8 ) ;
F_76 ( V_48 -> V_8 [ 0 ] ) ;
F_93 ( V_48 ) ;
}
static void F_167 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
F_168 ( & V_8 -> V_106 ) ;
F_43 ( V_8 ) ;
}
static int F_169 ( struct V_93 * V_94 , const unsigned char * V_114 ,
int V_4 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
int V_286 = F_170 ( V_8 -> V_77 , V_114 , V_4 , & V_8 -> V_81 ) ;
F_31 ( V_8 ) ;
return V_286 ;
}
static int F_171 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
return V_287 - F_24 ( V_8 -> V_77 ) ;
}
static int F_172 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
return F_24 ( V_8 -> V_77 ) ;
}
static void F_173 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
F_55 ( V_8 -> V_77 ) ;
}
static void F_174 ( struct V_93 * V_94 , int V_288 )
{
}
static int F_175 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
return V_8 -> V_101 ;
}
static int F_176 ( struct V_93 * V_94 ,
unsigned int V_289 , unsigned int V_290 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
unsigned int V_12 = V_8 -> V_12 ;
V_12 &= ~ V_290 ;
V_12 |= V_289 ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
return F_156 ( V_8 , 0 ) ;
}
return 0 ;
}
static int F_177 ( struct V_93 * V_94 ,
unsigned int V_92 , unsigned long V_221 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
struct V_264 V_265 ;
int V_277 ;
switch ( V_92 ) {
case V_291 :
if ( F_122 ( & V_265 , ( void T_4 * ) V_221 , sizeof( V_265 ) ) )
return - V_224 ;
V_265 . V_271 [ V_273 - 1 ] = '\0' ;
F_163 ( & V_8 -> V_150 ) ;
V_277 = F_150 ( V_8 , & V_265 ) ;
F_164 ( & V_8 -> V_150 ) ;
if ( F_121 ( ( void T_4 * ) V_221 , & V_265 , sizeof( V_265 ) ) )
return - V_224 ;
return V_277 ;
case V_292 :
if ( ! F_151 ( V_268 ) )
return - V_269 ;
F_163 ( & V_8 -> V_150 ) ;
F_149 ( V_8 ) ;
F_164 ( & V_8 -> V_150 ) ;
return 0 ;
default:
return - V_293 ;
}
}
static void F_178 ( struct V_93 * V_94 , struct V_294 * V_295 )
{
F_179 ( V_94 -> V_102 , V_295 ) ;
}
static void F_180 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
if ( V_94 -> V_102 -> V_103 & V_296 )
V_8 -> V_12 &= ~ V_13 ;
V_8 -> V_10 = 1 ;
F_156 ( V_8 , 0 ) ;
}
static void F_181 ( struct V_93 * V_94 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
if ( V_94 -> V_102 -> V_103 & V_296 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_10 = 0 ;
F_156 ( V_8 , 0 ) ;
}
static int F_182 ( struct V_93 * V_94 , int V_142 )
{
struct V_7 * V_8 = V_94 -> V_283 ;
int V_297 = 0 ;
if ( V_142 == - 1 )
V_297 = 0x0F ;
else if ( V_142 > 0 ) {
V_297 = V_142 / 200 ;
if ( V_297 > 0x0F )
V_297 = 0x0F ;
}
return F_156 ( V_8 , V_297 ) ;
}
static int T_7 F_183 ( void )
{
int V_298 = F_184 ( V_299 , & V_300 ) ;
if ( V_298 != 0 ) {
F_154 ( L_39 ,
V_298 ) ;
return V_298 ;
}
V_194 = F_185 ( 256 ) ;
if ( ! V_194 ) {
F_186 ( V_299 ) ;
F_154 ( L_40 ) ;
return - V_200 ;
}
V_194 -> V_301 = L_41 ;
V_194 -> V_272 = L_41 ;
V_194 -> V_302 = 0 ;
V_194 -> V_303 = 0 ;
V_194 -> type = V_304 ;
V_194 -> V_305 = V_306 ;
V_194 -> V_71 = V_307 | V_308
| V_309 ;
V_194 -> V_310 = V_311 ;
V_194 -> V_310 . V_312 &= ~ V_313 ;
F_187 ( V_194 , & V_314 ) ;
F_63 ( & V_180 ) ;
if ( F_188 ( V_194 ) ) {
F_189 ( V_194 ) ;
F_186 ( V_299 ) ;
F_154 ( L_42 ) ;
return - V_184 ;
}
F_8 ( L_43 ,
V_194 -> V_302 , V_194 -> V_303 ) ;
return 0 ;
}
static void T_8 F_190 ( void )
{
int V_298 = F_186 ( V_299 ) ;
if ( V_298 != 0 )
F_154 ( L_44 ,
V_298 ) ;
F_191 ( V_194 ) ;
F_189 ( V_194 ) ;
}
