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
int V_4 , V_73 ;
int V_74 = V_8 -> V_75 - 1 ;
V_4 = F_24 ( V_8 -> V_76 ) ;
if ( V_4 == 0 )
return 0 ;
if ( V_4 > V_48 -> V_77 )
V_4 = V_48 -> V_77 ;
V_73 = V_4 + V_74 ;
V_61 = F_14 ( V_48 , V_8 -> V_22 , V_73 , V_48 -> V_78 ) ;
if ( V_61 == NULL )
return - V_79 ;
V_69 = V_61 -> V_25 ;
switch ( V_8 -> V_75 ) {
case 1 :
break;
case 2 :
* V_69 += F_4 ( V_8 ) ;
V_4 -- ;
break;
}
F_11 ( F_25 ( V_8 -> V_76 , V_69 , V_4 , & V_8 -> V_80 ) != V_4 ) ;
F_19 ( V_8 , V_61 ) ;
return V_73 ;
}
static int F_26 ( struct V_47 * V_48 ,
struct V_7 * V_8 )
{
struct V_54 * V_61 ;
T_1 * V_69 ;
int V_4 , V_73 ;
int V_81 = 0 , V_82 = 0 ;
int V_83 = 0 ;
if ( V_8 -> V_75 == 4 )
V_83 = 1 ;
if ( V_8 -> V_84 == NULL ) {
V_8 -> V_84 = F_27 ( & V_8 -> V_85 ) ;
if ( V_8 -> V_84 == NULL )
return 0 ;
V_82 = 1 ;
}
V_4 = V_8 -> V_84 -> V_4 + V_83 ;
if ( V_4 > V_48 -> V_77 ) {
if ( V_8 -> V_75 == 3 ) {
F_28 ( V_8 -> V_84 ) ;
V_8 -> V_84 = NULL ;
return 0 ;
}
V_4 = V_48 -> V_77 ;
} else
V_81 = 1 ;
V_73 = V_4 + V_83 ;
V_61 = F_14 ( V_48 , V_8 -> V_22 , V_73 , V_48 -> V_78 ) ;
if ( V_61 == NULL )
return - V_79 ;
V_69 = V_61 -> V_25 ;
if ( V_8 -> V_75 == 4 ) {
* V_69 ++ = V_81 << 7 | V_82 << 6 | 1 ;
V_4 -- ;
}
memcpy ( V_69 , V_8 -> V_84 -> V_25 , V_4 ) ;
F_29 ( V_8 -> V_84 , V_4 ) ;
F_19 ( V_8 , V_61 ) ;
if ( V_81 )
V_8 -> V_84 = NULL ;
return V_73 ;
}
static void F_30 ( struct V_47 * V_48 )
{
int V_4 ;
int V_86 = 1 ;
while ( V_86 < V_87 ) {
struct V_7 * V_8 ;
if ( V_48 -> V_68 > V_88 )
break;
V_8 = V_48 -> V_8 [ V_86 ] ;
if ( V_8 == NULL || V_8 -> V_64 ) {
V_86 ++ ;
continue;
}
if ( V_8 -> V_75 < 3 )
V_4 = F_23 ( V_48 , V_8 ) ;
else
V_4 = F_26 ( V_48 , V_8 ) ;
if ( V_4 < 0 )
break;
if ( V_4 == 0 )
V_86 ++ ;
}
}
static void F_31 ( struct V_7 * V_8 )
{
unsigned long V_71 ;
F_21 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
if ( V_8 -> V_48 -> V_68 == 0 )
F_23 ( V_8 -> V_48 , V_8 ) ;
else if ( V_8 -> V_48 -> V_68 < V_89 )
F_30 ( V_8 -> V_48 ) ;
F_22 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
}
static void F_32 ( struct V_47 * V_48 , int V_90 , T_1 * V_25 ,
int V_26 )
{
struct V_54 * V_61 ;
V_61 = F_14 ( V_48 , 0 , V_26 + 2 , V_48 -> V_78 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_90 & 0xFE ) << 1 | V_6 ;
V_61 -> V_25 [ 1 ] = ( V_26 << 1 ) | V_6 ;
memcpy ( V_61 -> V_25 + 2 , V_25 , V_26 ) ;
F_20 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_33 ( struct V_91 * V_92 , struct V_7 * V_8 ,
T_2 V_93 , int V_94 )
{
int V_95 = 0 ;
T_1 V_96 = 0 ;
if ( V_94 == 2 )
V_93 = V_93 & 0x7f ;
else {
V_96 = V_93 & 0x7f ;
V_93 = ( V_93 >> 7 ) & 0x7f ;
} ;
if ( V_93 & V_11 ) {
V_8 -> V_64 = 1 ;
}
if ( V_93 & V_14 ) {
V_95 |= V_97 | V_13 ;
V_8 -> V_64 = 0 ;
F_31 ( V_8 ) ;
}
if ( V_93 & V_16 )
V_95 |= V_15 | V_98 ;
if ( V_93 & V_18 )
V_95 |= V_17 ;
if ( V_93 & V_20 )
V_95 |= V_19 ;
if ( V_92 ) {
if ( ( V_95 & V_19 ) == 0 && ( V_8 -> V_99 & V_19 ) )
if ( ! ( V_92 -> V_100 -> V_101 & V_102 ) )
F_34 ( V_92 ) ;
if ( V_96 & 0x01 )
F_35 ( V_92 , 0 , V_103 ) ;
}
V_8 -> V_99 = V_95 ;
}
static void F_36 ( struct V_47 * V_48 , T_1 * V_25 , int V_94 )
{
unsigned int V_22 = 0 ;
unsigned int V_93 = 0 ;
struct V_7 * V_8 ;
int V_4 = V_94 ;
T_1 * V_69 = V_25 ;
struct V_91 * V_92 ;
while ( F_3 ( & V_22 , * V_69 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_4 -- ;
if ( V_4 <= 0 )
return;
V_22 >>= 1 ;
if ( V_22 == 0 || V_22 >= V_87 || V_48 -> V_8 [ V_22 ] == NULL )
return;
V_8 = V_48 -> V_8 [ V_22 ] ;
while ( F_3 ( & V_93 , * V_69 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_92 = F_37 ( & V_8 -> V_104 ) ;
F_33 ( V_92 , V_8 , V_93 , V_94 ) ;
if ( V_92 ) {
F_38 ( V_92 ) ;
F_39 ( V_92 ) ;
}
F_32 ( V_48 , V_105 , V_25 , V_94 ) ;
}
static void F_40 ( struct V_47 * V_48 , T_1 * V_25 , int V_94 )
{
struct V_91 * V_92 ;
unsigned int V_22 = 0 ;
T_1 V_106 ;
int V_4 = V_94 ;
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
if ( V_22 == 0 || V_22 >= V_87 || V_48 -> V_8 [ V_22 ] == NULL )
return;
V_106 = * V_69 ;
if ( ( V_106 & 1 ) == 0 )
return;
V_92 = F_37 ( & V_48 -> V_8 [ V_22 ] -> V_104 ) ;
if ( V_92 ) {
if ( V_106 & 2 )
F_35 ( V_92 , 0 , V_107 ) ;
if ( V_106 & 4 )
F_35 ( V_92 , 0 , V_108 ) ;
if ( V_106 & 8 )
F_35 ( V_92 , 0 , V_109 ) ;
F_41 ( V_92 ) ;
F_39 ( V_92 ) ;
}
F_32 ( V_48 , V_110 , V_25 , V_94 ) ;
}
static void F_42 ( struct V_47 * V_48 , unsigned int V_111 ,
T_1 * V_25 , int V_94 )
{
T_1 V_112 [ 1 ] ;
switch ( V_111 ) {
case V_113 : {
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
if ( V_8 ) {
V_8 -> V_114 = 1 ;
V_48 -> V_114 = 1 ;
F_43 ( V_8 ) ;
}
}
break;
case V_115 :
F_32 ( V_48 , V_115 , V_25 , V_94 ) ;
break;
case V_116 :
V_48 -> V_64 = 1 ;
F_32 ( V_48 , V_116 , NULL , 0 ) ;
break;
case V_117 :
V_48 -> V_64 = 0 ;
F_32 ( V_48 , V_117 , NULL , 0 ) ;
F_16 ( V_48 ) ;
break;
case V_105 :
F_36 ( V_48 , V_25 , V_94 ) ;
break;
case V_110 :
F_40 ( V_48 , V_25 , V_94 ) ;
break;
case V_118 :
F_32 ( V_48 , V_118 , NULL , 0 ) ;
break;
case V_119 :
case V_120 :
case V_121 :
default:
V_112 [ 0 ] = V_111 ;
F_32 ( V_48 , V_122 , V_112 , 1 ) ;
break;
}
}
static void F_44 ( struct V_47 * V_48 , unsigned int V_111 ,
T_1 * V_25 , int V_94 )
{
struct V_123 * V_55 ;
unsigned long V_71 ;
F_21 ( & V_48 -> V_124 , V_71 ) ;
V_55 = V_48 -> V_125 ;
V_111 |= 1 ;
if ( V_55 != NULL && ( V_111 == V_55 -> V_90 || V_111 == V_122 ) ) {
F_45 ( & V_48 -> V_126 ) ;
V_48 -> V_125 = NULL ;
if ( V_111 == V_122 )
V_55 -> error = - V_127 ;
V_55 -> V_128 = 1 ;
F_46 ( & V_48 -> V_129 ) ;
}
F_22 ( & V_48 -> V_124 , V_71 ) ;
}
static void F_47 ( struct V_47 * V_48 , struct V_123 * V_55 )
{
struct V_54 * V_61 = F_14 ( V_48 , 0 , V_55 -> V_4 + 1 , V_48 -> V_78 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_55 -> V_90 << 1 ) | 2 | V_6 ;
memcpy ( V_61 -> V_25 + 1 , V_55 -> V_25 , V_55 -> V_4 ) ;
F_20 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_48 ( unsigned long V_25 )
{
struct V_47 * V_48 = (struct V_47 * ) V_25 ;
struct V_123 * V_55 ;
unsigned long V_71 ;
F_21 ( & V_48 -> V_124 , V_71 ) ;
V_55 = V_48 -> V_125 ;
if ( V_55 ) {
V_48 -> V_130 -- ;
if ( V_48 -> V_130 == 0 ) {
V_48 -> V_125 = NULL ;
V_55 -> error = - V_131 ;
V_55 -> V_128 = 1 ;
F_22 ( & V_48 -> V_124 , V_71 ) ;
F_46 ( & V_48 -> V_129 ) ;
return;
}
F_47 ( V_48 , V_55 ) ;
F_49 ( & V_48 -> V_126 , V_132 + V_48 -> V_133 * V_134 / 100 ) ;
}
F_22 ( & V_48 -> V_124 , V_71 ) ;
}
static struct V_123 * F_50 ( struct V_47 * V_48 ,
unsigned int V_111 , T_1 * V_25 , int V_94 )
{
struct V_123 * V_55 = F_51 ( sizeof( struct V_123 ) ,
V_135 ) ;
unsigned long V_71 ;
if ( V_55 == NULL )
return NULL ;
V_136:
F_52 ( V_48 -> V_129 , V_48 -> V_125 == NULL ) ;
F_21 ( & V_48 -> V_124 , V_71 ) ;
if ( V_48 -> V_125 != NULL ) {
F_22 ( & V_48 -> V_124 , V_71 ) ;
goto V_136;
}
V_55 -> V_90 = V_111 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_4 = V_94 ;
V_48 -> V_125 = V_55 ;
V_48 -> V_130 = V_48 -> V_137 ;
F_49 ( & V_48 -> V_126 , V_132 + V_48 -> V_133 * V_134 / 100 ) ;
F_47 ( V_48 , V_55 ) ;
F_22 ( & V_48 -> V_124 , V_71 ) ;
return V_55 ;
}
static int F_53 ( struct V_47 * V_48 , struct V_123 * V_24 )
{
int V_138 ;
F_52 ( V_48 -> V_129 , V_24 -> V_128 == 1 ) ;
V_138 = V_24 -> error ;
F_18 ( V_24 ) ;
return V_138 ;
}
static void F_54 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_139 ) ;
if ( V_27 & 8 )
F_8 ( L_22 , V_8 -> V_22 ) ;
V_8 -> V_140 = V_141 ;
if ( V_8 -> V_22 != 0 ) {
struct V_91 * V_92 = F_37 ( & V_8 -> V_104 ) ;
if ( V_92 ) {
F_34 ( V_92 ) ;
F_39 ( V_92 ) ;
}
F_55 ( V_8 -> V_76 ) ;
} else
V_8 -> V_48 -> V_114 = 1 ;
F_46 ( & V_8 -> V_48 -> V_129 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_139 ) ;
V_8 -> V_140 = V_142 ;
if ( V_27 & 8 )
F_8 ( L_23 , V_8 -> V_22 ) ;
F_46 ( & V_8 -> V_48 -> V_129 ) ;
}
static void F_57 ( unsigned long V_25 )
{
struct V_7 * V_8 = (struct V_7 * ) V_25 ;
struct V_47 * V_48 = V_8 -> V_48 ;
switch ( V_8 -> V_140 ) {
case V_143 :
V_8 -> V_144 -- ;
if ( V_8 -> V_144 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_49 ( & V_8 -> V_139 , V_132 + V_48 -> V_139 * V_134 / 100 ) ;
} else
F_54 ( V_8 ) ;
break;
case V_145 :
V_8 -> V_144 -- ;
if ( V_8 -> V_144 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_49 ( & V_8 -> V_139 , V_132 + V_48 -> V_139 * V_134 / 100 ) ;
} else
F_54 ( V_8 ) ;
break;
}
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_140 == V_142 || V_8 -> V_140 == V_143 )
return;
V_8 -> V_144 = V_48 -> V_137 ;
V_8 -> V_140 = V_143 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_49 ( & V_8 -> V_139 , V_132 + V_48 -> V_139 * V_134 / 100 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_140 == V_141 || V_8 -> V_140 == V_145 )
return;
V_8 -> V_144 = V_48 -> V_137 ;
V_8 -> V_140 = V_145 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_49 ( & V_8 -> V_139 , V_132 + V_48 -> V_139 * V_134 / 100 ) ;
}
static void F_59 ( struct V_7 * V_8 , T_1 * V_25 , int V_94 )
{
struct V_146 * V_104 = & V_8 -> V_104 ;
struct V_91 * V_92 = F_37 ( V_104 ) ;
unsigned int V_93 = 0 ;
int V_4 = V_94 ;
if ( V_27 & 16 )
F_8 ( L_24 , V_4 , V_92 ) ;
if ( V_92 ) {
switch ( V_8 -> V_75 ) {
case 4 :
break;
case 3 :
break;
case 2 :
while ( F_3 ( & V_93 , * V_25 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
F_33 ( V_92 , V_8 , V_93 , V_94 ) ;
case 1 :
default:
F_60 ( V_92 , V_25 , V_4 ) ;
F_41 ( V_92 ) ;
}
F_39 ( V_92 ) ;
}
}
static void F_61 ( struct V_7 * V_8 , T_1 * V_25 , int V_4 )
{
unsigned int V_111 = 0 ;
while ( V_4 -- > 0 ) {
if ( F_3 ( & V_111 , * V_25 ++ ) == 1 ) {
int V_94 = * V_25 ++ ;
V_4 -- ;
V_94 >>= 1 ;
if ( V_94 > V_4 )
return;
if ( V_111 & 1 )
F_42 ( V_8 -> V_48 , V_111 ,
V_25 , V_94 ) ;
else
F_44 ( V_8 -> V_48 , V_111 ,
V_25 , V_94 ) ;
return;
}
}
}
static struct V_7 * F_62 ( struct V_47 * V_48 , int V_22 )
{
struct V_7 * V_8 = F_51 ( sizeof( struct V_7 ) , V_58 ) ;
if ( V_8 == NULL )
return NULL ;
F_63 ( & V_8 -> V_80 ) ;
V_8 -> V_76 = & V_8 -> V_147 ;
if ( F_64 ( & V_8 -> V_147 , 4096 , V_135 ) < 0 ) {
F_18 ( V_8 ) ;
return NULL ;
}
F_65 ( & V_8 -> V_85 ) ;
F_66 ( & V_8 -> V_139 ) ;
V_8 -> V_139 . V_148 = F_57 ;
V_8 -> V_139 . V_25 = ( unsigned long ) V_8 ;
F_67 ( & V_8 -> V_104 ) ;
V_8 -> V_104 . V_149 = & V_150 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_75 = V_48 -> V_75 ;
V_8 -> V_140 = V_141 ;
if ( V_22 )
V_8 -> V_25 = F_59 ;
else
V_8 -> V_25 = F_61 ;
V_48 -> V_8 [ V_22 ] = V_8 ;
return V_8 ;
}
static void F_68 ( struct V_7 * V_8 )
{
struct V_91 * V_92 = F_37 ( & V_8 -> V_104 ) ;
if ( V_92 ) {
F_69 ( V_92 ) ;
F_39 ( V_92 ) ;
}
F_70 ( & V_8 -> V_139 ) ;
V_8 -> V_48 -> V_8 [ V_8 -> V_22 ] = NULL ;
F_71 ( V_8 -> V_76 ) ;
F_18 ( V_8 ) ;
}
static void F_72 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
T_1 V_23 ;
int V_151 ;
if ( ( V_48 -> V_24 & ~ V_28 ) == V_33 )
V_48 -> V_1 = F_2 ( V_48 -> V_1 , V_48 -> V_112 , V_48 -> V_4 ) ;
if ( V_48 -> V_51 == 0 ) {
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_152 ) ;
}
if ( V_48 -> V_1 != V_153 ) {
V_48 -> V_154 ++ ;
if ( V_27 & 4 )
F_8 ( L_25 , V_48 -> V_1 ) ;
return;
}
V_151 = V_48 -> V_151 >> 1 ;
if ( V_151 >= V_87 )
goto V_155;
V_23 = V_48 -> V_151 & 1 ;
F_5 ( L_26 , V_151 , V_23 , V_48 -> V_24 , V_48 -> V_112 , V_48 -> V_4 ) ;
V_23 ^= 1 - V_48 -> V_70 ;
V_8 = V_48 -> V_8 [ V_151 ] ;
switch ( V_48 -> V_24 ) {
case V_29 | V_28 :
if ( V_23 == 0 )
goto V_155;
if ( V_8 == NULL )
V_8 = F_62 ( V_48 , V_151 ) ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_114 )
F_12 ( V_48 , V_151 , V_32 ) ;
else {
F_12 ( V_48 , V_151 , V_30 ) ;
F_56 ( V_8 ) ;
}
break;
case V_31 | V_28 :
if ( V_23 == 0 )
goto V_155;
if ( V_8 == NULL || V_8 -> V_140 == V_141 ) {
F_12 ( V_48 , V_151 , V_32 ) ;
return;
}
F_12 ( V_48 , V_151 , V_30 ) ;
F_54 ( V_8 ) ;
break;
case V_30 :
case V_30 | V_28 :
if ( V_23 == 0 || V_8 == NULL )
break;
switch ( V_8 -> V_140 ) {
case V_145 :
F_54 ( V_8 ) ;
break;
case V_143 :
F_56 ( V_8 ) ;
break;
}
break;
case V_32 :
case V_32 | V_28 :
if ( V_23 )
goto V_155;
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
if ( V_8 == NULL || V_8 -> V_140 != V_142 ) {
F_13 ( V_48 , V_151 , V_32 | V_28 ) ;
return;
}
V_8 -> V_25 ( V_8 , V_48 -> V_112 , V_48 -> V_4 ) ;
break;
default:
goto V_155;
}
return;
V_155:
V_48 -> V_156 ++ ;
return;
}
static void F_73 ( struct V_47 * V_48 , unsigned char V_2 )
{
unsigned int V_4 ;
switch ( V_48 -> V_140 ) {
case V_157 :
if ( V_2 == V_52 ) {
V_48 -> V_140 = V_158 ;
V_48 -> V_151 = 0 ;
V_48 -> V_4 = 0 ;
V_48 -> V_1 = V_53 ;
}
break;
case V_158 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_151 , V_2 ) )
V_48 -> V_140 = V_159 ;
break;
case V_159 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_140 = V_160 ;
break;
case V_160 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_4 , V_2 ) ) {
if ( V_48 -> V_4 > V_48 -> V_161 ) {
V_48 -> V_162 ++ ;
V_48 -> V_140 = V_157 ;
break;
}
V_48 -> V_163 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_140 = V_164 ;
else
V_48 -> V_140 = V_165 ;
break;
}
V_48 -> V_140 = V_166 ;
break;
case V_166 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_4 = V_2 ;
V_48 -> V_4 |= V_4 << 7 ;
if ( V_48 -> V_4 > V_48 -> V_161 ) {
V_48 -> V_162 ++ ;
V_48 -> V_140 = V_157 ;
break;
}
V_48 -> V_163 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_140 = V_164 ;
else
V_48 -> V_140 = V_165 ;
break;
case V_165 :
V_48 -> V_112 [ V_48 -> V_163 ++ ] = V_2 ;
if ( V_48 -> V_163 == V_48 -> V_4 )
V_48 -> V_140 = V_164 ;
break;
case V_164 :
V_48 -> V_152 = V_2 ;
if ( V_2 == V_52 ) {
V_48 -> V_140 = V_157 ;
break;
}
F_72 ( V_48 ) ;
V_48 -> V_140 = V_167 ;
break;
case V_167 :
if ( V_2 == V_52 ) {
V_48 -> V_140 = V_157 ;
break;
}
break;
}
}
static void F_74 ( struct V_47 * V_48 , unsigned char V_2 )
{
if ( V_2 == V_42 ) {
if ( V_48 -> V_140 == V_165 && V_48 -> V_163 ) {
V_48 -> V_163 -- ;
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_112 [ V_48 -> V_163 ] ) ;
V_48 -> V_4 = V_48 -> V_163 ;
F_72 ( V_48 ) ;
V_48 -> V_140 = V_168 ;
return;
}
if ( V_48 -> V_140 != V_168 ) {
V_48 -> V_156 ++ ;
V_48 -> V_140 = V_168 ;
}
return;
}
if ( V_2 == V_43 ) {
V_48 -> V_169 = 1 ;
return;
}
if ( V_48 -> V_140 == V_157 )
return;
if ( V_48 -> V_169 ) {
V_2 ^= V_46 ;
V_48 -> V_169 = 0 ;
}
switch ( V_48 -> V_140 ) {
case V_168 :
V_48 -> V_151 = 0 ;
V_48 -> V_140 = V_158 ;
V_48 -> V_1 = V_53 ;
case V_158 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_151 , V_2 ) )
V_48 -> V_140 = V_159 ;
break;
case V_159 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_163 = 0 ;
V_48 -> V_140 = V_165 ;
break;
case V_165 :
if ( V_48 -> V_163 > V_48 -> V_161 ) {
V_48 -> V_140 = V_170 ;
V_48 -> V_162 ++ ;
} else
V_48 -> V_112 [ V_48 -> V_163 ++ ] = V_2 ;
break;
case V_170 :
break;
}
}
static void F_75 ( struct V_47 * V_48 ,
unsigned char V_25 , unsigned char V_171 )
{
V_48 -> V_140 = V_157 ;
V_48 -> V_172 ++ ;
}
void F_76 ( struct V_47 * V_48 )
{
int V_86 ;
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_54 * V_173 ;
V_48 -> V_114 = 1 ;
F_77 ( & V_174 ) ;
for ( V_86 = 0 ; V_86 < V_175 ; V_86 ++ ) {
if ( V_47 [ V_86 ] == V_48 ) {
V_47 [ V_86 ] = NULL ;
break;
}
}
F_78 ( & V_174 ) ;
F_11 ( V_86 == V_175 ) ;
F_70 ( & V_48 -> V_126 ) ;
if ( V_8 ) {
V_8 -> V_114 = 1 ;
F_43 ( V_8 ) ;
F_79 ( V_48 -> V_129 ,
V_8 -> V_140 == V_141 ) ;
}
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
if ( V_48 -> V_8 [ V_86 ] )
F_68 ( V_48 -> V_8 [ V_86 ] ) ;
for ( V_173 = V_48 -> V_62 ; V_173 != NULL ; V_173 = V_48 -> V_62 ) {
V_48 -> V_62 = V_173 -> V_60 ;
F_18 ( V_173 ) ;
}
V_48 -> V_67 = NULL ;
}
int F_80 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_86 = 0 ;
F_66 ( & V_48 -> V_126 ) ;
V_48 -> V_126 . V_148 = F_48 ;
V_48 -> V_126 . V_25 = ( unsigned long ) V_48 ;
F_81 ( & V_48 -> V_129 ) ;
F_63 ( & V_48 -> V_124 ) ;
F_63 ( & V_48 -> V_72 ) ;
if ( V_48 -> V_51 == 0 )
V_48 -> V_176 = F_73 ;
else
V_48 -> V_176 = F_74 ;
V_48 -> error = F_75 ;
F_77 ( & V_174 ) ;
for ( V_86 = 0 ; V_86 < V_175 ; V_86 ++ ) {
if ( V_47 [ V_86 ] == NULL ) {
V_47 [ V_86 ] = V_48 ;
break;
}
}
F_78 ( & V_174 ) ;
if ( V_86 == V_175 )
return - V_177 ;
V_8 = F_62 ( V_48 , 0 ) ;
if ( V_8 == NULL )
return - V_79 ;
V_48 -> V_114 = 0 ;
return 0 ;
}
void F_82 ( struct V_47 * V_48 )
{
F_18 ( V_48 -> V_65 ) ;
F_18 ( V_48 -> V_112 ) ;
F_18 ( V_48 ) ;
}
struct V_47 * F_83 ( void )
{
struct V_47 * V_48 = F_51 ( sizeof( struct V_47 ) , V_135 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_112 = F_15 ( V_178 + 1 , V_135 ) ;
if ( V_48 -> V_112 == NULL ) {
F_18 ( V_48 ) ;
return NULL ;
}
V_48 -> V_65 = F_15 ( 2 * V_178 + 2 , V_135 ) ;
if ( V_48 -> V_65 == NULL ) {
F_18 ( V_48 -> V_112 ) ;
F_18 ( V_48 ) ;
return NULL ;
}
F_63 ( & V_48 -> V_80 ) ;
V_48 -> V_139 = V_179 ;
V_48 -> V_133 = V_180 ;
V_48 -> V_137 = V_181 ;
V_48 -> V_78 = V_34 ;
V_48 -> V_70 = 0 ;
V_48 -> V_75 = 1 ;
V_48 -> V_51 = 1 ;
V_48 -> V_161 = 64 ;
V_48 -> V_77 = 64 ;
V_48 -> V_114 = 1 ;
return V_48 ;
}
static int F_84 ( struct V_47 * V_48 , T_1 * V_25 , int V_4 )
{
if ( F_85 ( V_48 -> V_92 ) < V_4 ) {
F_86 ( V_182 , & V_48 -> V_92 -> V_71 ) ;
return - V_183 ;
}
if ( V_27 & 4 )
F_17 ( L_27 , V_66 ,
V_25 , V_4 ) ;
V_48 -> V_92 -> V_149 -> V_184 ( V_48 -> V_92 , V_25 , V_4 ) ;
return V_4 ;
}
static int F_87 ( struct V_91 * V_92 , struct V_47 * V_48 )
{
int V_185 ;
V_48 -> V_92 = F_88 ( V_92 ) ;
V_48 -> V_40 = F_84 ;
V_185 = F_80 ( V_48 ) ;
if ( V_185 != 0 )
F_39 ( V_48 -> V_92 ) ;
return V_185 ;
}
static void F_89 ( struct V_91 * V_92 , struct V_47 * V_48 )
{
F_11 ( V_92 != V_48 -> V_92 ) ;
F_76 ( V_48 ) ;
F_39 ( V_48 -> V_92 ) ;
V_48 -> V_92 = NULL ;
}
static void F_90 ( struct V_91 * V_92 , const unsigned char * V_186 ,
char * V_187 , int V_163 )
{
struct V_47 * V_48 = V_92 -> V_188 ;
const unsigned char * V_69 ;
char * V_189 ;
int V_86 ;
char V_112 [ 64 ] ;
char V_71 ;
if ( V_27 & 4 )
F_17 ( L_28 , V_66 ,
V_186 , V_163 ) ;
for ( V_86 = V_163 , V_69 = V_186 , V_189 = V_187 ; V_86 ; V_86 -- , V_69 ++ ) {
V_71 = * V_189 ++ ;
switch ( V_71 ) {
case V_190 :
V_48 -> V_176 ( V_48 , * V_69 ) ;
break;
case V_107 :
case V_103 :
case V_108 :
case V_109 :
V_48 -> error ( V_48 , * V_69 , V_71 ) ;
break;
default:
F_91 ( L_29 ,
F_92 ( V_92 , V_112 ) , V_71 ) ;
break;
}
}
}
static T_3 F_93 ( struct V_91 * V_92 )
{
return 0 ;
}
static void F_94 ( struct V_91 * V_92 )
{
}
static void F_95 ( struct V_91 * V_92 )
{
struct V_47 * V_48 = V_92 -> V_188 ;
F_89 ( V_92 , V_48 ) ;
F_94 ( V_92 ) ;
F_82 ( V_48 ) ;
}
static int F_96 ( struct V_91 * V_92 )
{
struct V_47 * V_48 ;
if ( V_92 -> V_149 -> V_184 == NULL )
return - V_191 ;
V_48 = F_83 () ;
if ( V_48 == NULL )
return - V_79 ;
V_92 -> V_188 = V_48 ;
V_92 -> V_192 = 65536 ;
V_48 -> V_51 = 1 ;
return F_87 ( V_92 , V_48 ) ;
}
static void F_97 ( struct V_91 * V_92 )
{
struct V_47 * V_48 = V_92 -> V_188 ;
unsigned long V_71 ;
F_98 ( V_182 , & V_92 -> V_71 ) ;
F_16 ( V_48 ) ;
if ( V_48 -> V_68 < V_89 ) {
F_21 ( & V_48 -> V_72 , V_71 ) ;
F_30 ( V_48 ) ;
F_22 ( & V_48 -> V_72 , V_71 ) ;
}
}
static T_3 F_99 ( struct V_91 * V_92 , struct V_193 * V_193 ,
unsigned char T_4 * V_112 , T_5 V_194 )
{
return - V_127 ;
}
static T_3 F_100 ( struct V_91 * V_92 , struct V_193 * V_193 ,
const unsigned char * V_112 , T_5 V_194 )
{
int V_195 = F_85 ( V_92 ) ;
if ( V_195 >= V_194 )
return V_92 -> V_149 -> V_184 ( V_92 , V_112 , V_194 ) ;
F_86 ( V_182 , & V_92 -> V_71 ) ;
return - V_196 ;
}
static unsigned int F_101 ( struct V_91 * V_92 , struct V_193 * V_193 ,
T_6 * V_197 )
{
unsigned int V_198 = 0 ;
struct V_47 * V_48 = V_92 -> V_188 ;
F_102 ( V_193 , & V_92 -> V_199 , V_197 ) ;
F_102 ( V_193 , & V_92 -> V_200 , V_197 ) ;
if ( F_103 ( V_193 ) )
V_198 |= V_201 ;
if ( ! F_104 ( V_92 ) && F_85 ( V_92 ) > 0 )
V_198 |= V_202 | V_203 ;
if ( V_48 -> V_114 )
V_198 |= V_201 ;
return V_198 ;
}
static int F_105 ( struct V_91 * V_92 , struct V_47 * V_48 ,
struct V_204 * V_2 )
{
int V_205 = 0 ;
int V_206 = 0 ;
if ( ( V_2 -> V_75 != 1 && V_2 -> V_75 != 2 ) || V_2 -> V_207 )
return - V_127 ;
if ( V_2 -> V_161 > V_178 || V_2 -> V_77 > V_208 || V_2 -> V_161 < 8 || V_2 -> V_77 < 8 )
return - V_191 ;
if ( V_2 -> V_137 < 3 )
return - V_191 ;
if ( V_2 -> V_209 > 1 )
return - V_191 ;
if ( V_2 -> V_70 > 1 )
return - V_191 ;
if ( V_2 -> V_86 == 0 || V_2 -> V_86 > 2 )
return - V_191 ;
if ( V_2 -> V_139 != 0 && V_2 -> V_139 != V_48 -> V_139 )
V_206 = 1 ;
if ( V_2 -> V_133 != 0 && V_2 -> V_133 != V_48 -> V_133 )
V_206 = 1 ;
if ( V_2 -> V_209 != V_48 -> V_51 )
V_206 = 1 ;
if ( V_2 -> V_75 != V_48 -> V_75 )
V_206 = 1 ;
if ( V_2 -> V_70 != V_48 -> V_70 )
V_205 = 1 ;
if ( V_2 -> V_161 != V_48 -> V_161 )
V_206 = 1 ;
if ( V_2 -> V_77 != V_48 -> V_77 )
V_206 = 1 ;
if ( V_205 || V_206 ) {
F_43 ( V_48 -> V_8 [ 0 ] ) ;
F_79 ( V_48 -> V_129 ,
V_48 -> V_8 [ 0 ] -> V_140 == V_141 ) ;
if ( F_106 ( V_210 ) )
return - V_211 ;
}
if ( V_206 )
F_76 ( V_48 ) ;
V_48 -> V_70 = V_2 -> V_70 ;
V_48 -> V_161 = V_2 -> V_161 ;
V_48 -> V_77 = V_2 -> V_77 ;
V_48 -> V_51 = V_2 -> V_209 ;
V_48 -> V_75 = V_2 -> V_75 ;
V_48 -> V_137 = V_2 -> V_137 ;
if ( V_2 -> V_86 == 1 )
V_48 -> V_78 = V_34 ;
else if ( V_2 -> V_86 == 2 )
V_48 -> V_78 = V_33 ;
if ( V_2 -> V_139 )
V_48 -> V_139 = V_2 -> V_139 ;
if ( V_2 -> V_133 )
V_48 -> V_133 = V_2 -> V_133 ;
if ( V_206 )
F_80 ( V_48 ) ;
if ( V_48 -> V_70 && V_205 )
F_58 ( V_48 -> V_8 [ 0 ] ) ;
return 0 ;
}
static int F_107 ( struct V_91 * V_92 , struct V_193 * V_193 ,
unsigned int V_90 , unsigned long V_212 )
{
struct V_204 V_2 ;
struct V_47 * V_48 = V_92 -> V_188 ;
switch ( V_90 ) {
case V_213 :
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_75 = V_48 -> V_75 ;
V_2 . V_209 = V_48 -> V_51 ;
V_2 . V_70 = V_48 -> V_70 ;
V_2 . V_139 = V_48 -> V_139 ;
V_2 . V_133 = V_48 -> V_133 ;
V_2 . V_214 = 0 ;
V_2 . V_137 = V_48 -> V_137 ;
if ( V_48 -> V_78 == V_34 )
V_2 . V_86 = 1 ;
else
V_2 . V_86 = 2 ;
F_8 ( L_30 , V_48 -> V_78 , V_2 . V_86 ) ;
V_2 . V_161 = V_48 -> V_161 ;
V_2 . V_77 = V_48 -> V_77 ;
V_2 . V_207 = 0 ;
if ( F_108 ( ( void * ) V_212 , & V_2 , sizeof( V_2 ) ) )
return - V_215 ;
return 0 ;
case V_216 :
if ( F_109 ( & V_2 , ( void * ) V_212 , sizeof( V_2 ) ) )
return - V_215 ;
return F_105 ( V_92 , V_48 , & V_2 ) ;
default:
return F_110 ( V_92 , V_193 , V_90 , V_212 ) ;
}
}
static int F_111 ( struct V_7 * V_8 , T_1 V_96 )
{
T_1 V_9 [ 5 ] ;
struct V_123 * V_55 ;
int V_4 = 2 ;
if ( V_96 )
V_4 ++ ;
V_9 [ 0 ] = V_4 << 1 | V_6 ;
V_9 [ 1 ] = V_8 -> V_22 << 2 | 3 ;
V_9 [ 2 ] = F_4 ( V_8 ) << 1 | V_6 ;
if ( V_96 )
V_9 [ 3 ] = V_96 << 4 | 2 | V_6 ;
V_55 = F_50 ( V_8 -> V_48 , V_105 , V_9 , V_4 + 1 ) ;
if ( V_55 == NULL )
return - V_79 ;
return F_53 ( V_8 -> V_48 , V_55 ) ;
}
static int F_112 ( struct V_146 * V_104 )
{
struct V_7 * V_8 = F_113 ( V_104 , struct V_7 , V_104 ) ;
if ( V_8 -> V_140 != V_142 )
return 0 ;
if ( V_27 & 2 )
return 1 ;
return V_8 -> V_99 & V_19 ;
}
static void F_114 ( struct V_146 * V_104 , int V_217 )
{
struct V_7 * V_8 = F_113 ( V_104 , struct V_7 , V_104 ) ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_217 )
V_12 |= V_13 | V_15 ;
else
V_12 &= ~ ( V_13 | V_15 ) ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
F_111 ( V_8 , 0 ) ;
}
}
static int F_115 ( struct V_91 * V_92 , struct V_193 * V_218 )
{
struct V_47 * V_48 ;
struct V_7 * V_8 ;
struct V_146 * V_104 ;
unsigned int line = V_92 -> V_219 ;
unsigned int V_220 = line >> 6 ;
line = line & 0x3F ;
if ( V_220 >= V_175 )
return - V_221 ;
if ( V_47 [ V_220 ] == NULL )
return - V_222 ;
if ( line == 0 || line > 61 )
return - V_223 ;
V_48 = V_47 [ V_220 ] ;
if ( V_48 -> V_114 )
return - V_224 ;
V_8 = V_48 -> V_8 [ line ] ;
if ( V_8 == NULL )
V_8 = F_62 ( V_48 , line ) ;
if ( V_8 == NULL )
return - V_79 ;
V_104 = & V_8 -> V_104 ;
V_104 -> V_163 ++ ;
V_92 -> V_225 = V_8 ;
F_116 ( V_104 , V_92 ) ;
V_8 -> V_99 = 0 ;
F_86 ( V_226 , & V_104 -> V_71 ) ;
F_58 ( V_8 ) ;
return F_117 ( V_104 , V_92 , V_218 ) ;
}
static void F_118 ( struct V_91 * V_92 , struct V_193 * V_218 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
if ( V_8 == NULL )
return;
if ( F_119 ( & V_8 -> V_104 , V_92 , V_218 ) == 0 )
return;
F_43 ( V_8 ) ;
F_120 ( & V_8 -> V_104 , V_92 ) ;
F_116 ( & V_8 -> V_104 , NULL ) ;
}
static void F_121 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
F_122 ( & V_8 -> V_104 ) ;
F_43 ( V_8 ) ;
}
static int F_123 ( struct V_91 * V_92 , const unsigned char * V_112 ,
int V_4 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
int V_227 = F_124 ( V_8 -> V_76 , V_112 , V_4 , & V_8 -> V_80 ) ;
F_31 ( V_8 ) ;
return V_227 ;
}
static int F_125 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
return V_228 - F_24 ( V_8 -> V_76 ) ;
}
static int F_126 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
return F_24 ( V_8 -> V_76 ) ;
}
static void F_127 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
F_55 ( V_8 -> V_76 ) ;
}
static void F_128 ( struct V_91 * V_92 , int V_229 )
{
}
static int F_129 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
return V_8 -> V_99 ;
}
static int F_130 ( struct V_91 * V_92 ,
unsigned int V_230 , unsigned int V_231 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
unsigned int V_12 = V_8 -> V_12 ;
V_12 &= V_231 ;
V_12 |= V_230 ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
return F_111 ( V_8 , 0 ) ;
}
return 0 ;
}
static int F_131 ( struct V_91 * V_92 ,
unsigned int V_90 , unsigned long V_212 )
{
return - V_232 ;
}
static void F_132 ( struct V_91 * V_92 , struct V_233 * V_234 )
{
F_133 ( V_92 -> V_100 , V_234 ) ;
}
static void F_134 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
if ( V_92 -> V_100 -> V_101 & V_235 )
V_8 -> V_12 &= ~ V_13 ;
V_8 -> V_10 = 1 ;
F_111 ( V_8 , 0 ) ;
}
static void F_135 ( struct V_91 * V_92 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
if ( V_92 -> V_100 -> V_101 & V_235 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_10 = 0 ;
F_111 ( V_8 , 0 ) ;
}
static int F_136 ( struct V_91 * V_92 , int V_140 )
{
struct V_7 * V_8 = V_92 -> V_225 ;
int V_236 = 0 ;
if ( V_140 == - 1 )
V_236 = 0x0F ;
else if ( V_140 > 0 ) {
V_236 = V_140 / 200 ;
if ( V_236 > 0x0F )
V_236 = 0x0F ;
}
return F_111 ( V_8 , V_236 ) ;
}
static int T_7 F_137 ( void )
{
int V_237 = F_138 ( V_238 , & V_239 ) ;
if ( V_237 != 0 ) {
F_139 ( L_31 ,
V_237 ) ;
return V_237 ;
}
V_240 = F_140 ( 256 ) ;
if ( ! V_240 ) {
F_141 ( V_238 ) ;
F_139 ( L_32 ) ;
return - V_191 ;
}
V_240 -> V_241 = V_242 ;
V_240 -> V_243 = L_33 ;
V_240 -> V_244 = L_33 ;
V_240 -> V_245 = 0 ;
V_240 -> V_246 = 0 ;
V_240 -> type = V_247 ;
V_240 -> V_248 = V_249 ;
V_240 -> V_71 = V_250 | V_251
| V_252 ;
V_240 -> V_253 = V_254 ;
V_240 -> V_253 . V_255 &= ~ V_256 ;
F_142 ( V_240 , & V_257 ) ;
F_63 ( & V_174 ) ;
if ( F_143 ( V_240 ) ) {
F_144 ( V_240 ) ;
F_141 ( V_238 ) ;
F_139 ( L_34 ) ;
return - V_177 ;
}
F_8 ( L_35 ,
V_240 -> V_245 , V_240 -> V_246 ) ;
return 0 ;
}
static void T_8 F_145 ( void )
{
int V_237 = F_141 ( V_238 ) ;
if ( V_237 != 0 )
F_139 ( L_36 ,
V_237 ) ;
F_146 ( V_240 ) ;
F_144 ( V_240 ) ;
}
