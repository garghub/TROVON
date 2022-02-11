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
if ( V_81 ) {
F_28 ( V_8 -> V_84 ) ;
V_8 -> V_84 = NULL ;
}
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
if ( V_8 -> V_75 < 3 && ! V_8 -> V_89 )
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
if ( V_8 -> V_48 -> V_68 == 0 ) {
if ( V_8 -> V_89 )
F_26 ( V_8 -> V_48 , V_8 ) ;
else
F_23 ( V_8 -> V_48 , V_8 ) ;
} else if ( V_8 -> V_48 -> V_68 < V_90 )
F_30 ( V_8 -> V_48 ) ;
F_22 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
}
static void F_32 ( struct V_47 * V_48 , int V_91 , T_1 * V_25 ,
int V_26 )
{
struct V_54 * V_61 ;
V_61 = F_14 ( V_48 , 0 , V_26 + 2 , V_48 -> V_78 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_91 & 0xFE ) << 1 | V_6 ;
V_61 -> V_25 [ 1 ] = ( V_26 << 1 ) | V_6 ;
memcpy ( V_61 -> V_25 + 2 , V_25 , V_26 ) ;
F_20 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_33 ( struct V_92 * V_93 , struct V_7 * V_8 ,
T_2 V_94 , int V_95 )
{
int V_96 = 0 ;
T_1 V_97 = 0 ;
if ( V_95 == 2 )
V_94 = V_94 & 0x7f ;
else {
V_97 = V_94 & 0x7f ;
V_94 = ( V_94 >> 7 ) & 0x7f ;
} ;
if ( V_94 & V_11 ) {
V_8 -> V_64 = 1 ;
}
if ( V_94 & V_14 ) {
V_96 |= V_98 | V_13 ;
V_8 -> V_64 = 0 ;
F_31 ( V_8 ) ;
}
if ( V_94 & V_16 )
V_96 |= V_15 | V_99 ;
if ( V_94 & V_18 )
V_96 |= V_17 ;
if ( V_94 & V_20 )
V_96 |= V_19 ;
if ( V_93 ) {
if ( ( V_96 & V_19 ) == 0 && ( V_8 -> V_100 & V_19 ) )
if ( ! ( V_93 -> V_101 -> V_102 & V_103 ) )
F_34 ( V_93 ) ;
if ( V_97 & 0x01 )
F_35 ( V_93 , 0 , V_104 ) ;
}
V_8 -> V_100 = V_96 ;
}
static void F_36 ( struct V_47 * V_48 , T_1 * V_25 , int V_95 )
{
unsigned int V_22 = 0 ;
unsigned int V_94 = 0 ;
struct V_7 * V_8 ;
int V_4 = V_95 ;
T_1 * V_69 = V_25 ;
struct V_92 * V_93 ;
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
while ( F_3 ( & V_94 , * V_69 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_93 = F_37 ( & V_8 -> V_105 ) ;
F_33 ( V_93 , V_8 , V_94 , V_95 ) ;
if ( V_93 ) {
F_38 ( V_93 ) ;
F_39 ( V_93 ) ;
}
F_32 ( V_48 , V_106 , V_25 , V_95 ) ;
}
static void F_40 ( struct V_47 * V_48 , T_1 * V_25 , int V_95 )
{
struct V_92 * V_93 ;
unsigned int V_22 = 0 ;
T_1 V_107 ;
int V_4 = V_95 ;
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
V_107 = * V_69 ;
if ( ( V_107 & 1 ) == 0 )
return;
V_93 = F_37 ( & V_48 -> V_8 [ V_22 ] -> V_105 ) ;
if ( V_93 ) {
if ( V_107 & 2 )
F_35 ( V_93 , 0 , V_108 ) ;
if ( V_107 & 4 )
F_35 ( V_93 , 0 , V_109 ) ;
if ( V_107 & 8 )
F_35 ( V_93 , 0 , V_110 ) ;
F_41 ( V_93 ) ;
F_39 ( V_93 ) ;
}
F_32 ( V_48 , V_111 , V_25 , V_95 ) ;
}
static void F_42 ( struct V_47 * V_48 , unsigned int V_112 ,
T_1 * V_25 , int V_95 )
{
T_1 V_113 [ 1 ] ;
switch ( V_112 ) {
case V_114 : {
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
if ( V_8 ) {
V_8 -> V_115 = 1 ;
V_48 -> V_115 = 1 ;
F_43 ( V_8 ) ;
}
}
break;
case V_116 :
F_32 ( V_48 , V_116 , V_25 , V_95 ) ;
break;
case V_117 :
V_48 -> V_64 = 1 ;
F_32 ( V_48 , V_117 , NULL , 0 ) ;
break;
case V_118 :
V_48 -> V_64 = 0 ;
F_32 ( V_48 , V_118 , NULL , 0 ) ;
F_16 ( V_48 ) ;
break;
case V_106 :
F_36 ( V_48 , V_25 , V_95 ) ;
break;
case V_111 :
F_40 ( V_48 , V_25 , V_95 ) ;
break;
case V_119 :
F_32 ( V_48 , V_119 , NULL , 0 ) ;
break;
case V_120 :
case V_121 :
case V_122 :
default:
V_113 [ 0 ] = V_112 ;
F_32 ( V_48 , V_123 , V_113 , 1 ) ;
break;
}
}
static void F_44 ( struct V_47 * V_48 , unsigned int V_112 ,
T_1 * V_25 , int V_95 )
{
struct V_124 * V_55 ;
unsigned long V_71 ;
F_21 ( & V_48 -> V_125 , V_71 ) ;
V_55 = V_48 -> V_126 ;
V_112 |= 1 ;
if ( V_55 != NULL && ( V_112 == V_55 -> V_91 || V_112 == V_123 ) ) {
F_45 ( & V_48 -> V_127 ) ;
V_48 -> V_126 = NULL ;
if ( V_112 == V_123 )
V_55 -> error = - V_128 ;
V_55 -> V_129 = 1 ;
F_46 ( & V_48 -> V_130 ) ;
}
F_22 ( & V_48 -> V_125 , V_71 ) ;
}
static void F_47 ( struct V_47 * V_48 , struct V_124 * V_55 )
{
struct V_54 * V_61 = F_14 ( V_48 , 0 , V_55 -> V_4 + 1 , V_48 -> V_78 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_55 -> V_91 << 1 ) | 2 | V_6 ;
memcpy ( V_61 -> V_25 + 1 , V_55 -> V_25 , V_55 -> V_4 ) ;
F_20 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_48 ( unsigned long V_25 )
{
struct V_47 * V_48 = (struct V_47 * ) V_25 ;
struct V_124 * V_55 ;
unsigned long V_71 ;
F_21 ( & V_48 -> V_125 , V_71 ) ;
V_55 = V_48 -> V_126 ;
if ( V_55 ) {
V_48 -> V_131 -- ;
if ( V_48 -> V_131 == 0 ) {
V_48 -> V_126 = NULL ;
V_55 -> error = - V_132 ;
V_55 -> V_129 = 1 ;
F_22 ( & V_48 -> V_125 , V_71 ) ;
F_46 ( & V_48 -> V_130 ) ;
return;
}
F_47 ( V_48 , V_55 ) ;
F_49 ( & V_48 -> V_127 , V_133 + V_48 -> V_134 * V_135 / 100 ) ;
}
F_22 ( & V_48 -> V_125 , V_71 ) ;
}
static struct V_124 * F_50 ( struct V_47 * V_48 ,
unsigned int V_112 , T_1 * V_25 , int V_95 )
{
struct V_124 * V_55 = F_51 ( sizeof( struct V_124 ) ,
V_136 ) ;
unsigned long V_71 ;
if ( V_55 == NULL )
return NULL ;
V_137:
F_52 ( V_48 -> V_130 , V_48 -> V_126 == NULL ) ;
F_21 ( & V_48 -> V_125 , V_71 ) ;
if ( V_48 -> V_126 != NULL ) {
F_22 ( & V_48 -> V_125 , V_71 ) ;
goto V_137;
}
V_55 -> V_91 = V_112 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_4 = V_95 ;
V_48 -> V_126 = V_55 ;
V_48 -> V_131 = V_48 -> V_138 ;
F_49 ( & V_48 -> V_127 , V_133 + V_48 -> V_134 * V_135 / 100 ) ;
F_47 ( V_48 , V_55 ) ;
F_22 ( & V_48 -> V_125 , V_71 ) ;
return V_55 ;
}
static int F_53 ( struct V_47 * V_48 , struct V_124 * V_24 )
{
int V_139 ;
F_52 ( V_48 -> V_130 , V_24 -> V_129 == 1 ) ;
V_139 = V_24 -> error ;
F_18 ( V_24 ) ;
return V_139 ;
}
static void F_54 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_140 ) ;
if ( V_27 & 8 )
F_8 ( L_22 , V_8 -> V_22 ) ;
V_8 -> V_141 = V_142 ;
if ( V_8 -> V_22 != 0 ) {
struct V_92 * V_93 = F_37 ( & V_8 -> V_105 ) ;
if ( V_93 ) {
F_34 ( V_93 ) ;
F_39 ( V_93 ) ;
}
F_55 ( V_8 -> V_76 ) ;
} else
V_8 -> V_48 -> V_115 = 1 ;
F_46 ( & V_8 -> V_48 -> V_130 ) ;
}
static void F_56 ( struct V_7 * V_8 )
{
F_45 ( & V_8 -> V_140 ) ;
V_8 -> V_141 = V_143 ;
if ( V_27 & 8 )
F_8 ( L_23 , V_8 -> V_22 ) ;
F_46 ( & V_8 -> V_48 -> V_130 ) ;
}
static void F_57 ( unsigned long V_25 )
{
struct V_7 * V_8 = (struct V_7 * ) V_25 ;
struct V_47 * V_48 = V_8 -> V_48 ;
switch ( V_8 -> V_141 ) {
case V_144 :
V_8 -> V_145 -- ;
if ( V_8 -> V_145 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_49 ( & V_8 -> V_140 , V_133 + V_48 -> V_140 * V_135 / 100 ) ;
} else
F_54 ( V_8 ) ;
break;
case V_146 :
V_8 -> V_145 -- ;
if ( V_8 -> V_145 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_49 ( & V_8 -> V_140 , V_133 + V_48 -> V_140 * V_135 / 100 ) ;
} else
F_54 ( V_8 ) ;
break;
}
}
static void F_58 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_141 == V_143 || V_8 -> V_141 == V_144 )
return;
V_8 -> V_145 = V_48 -> V_138 ;
V_8 -> V_141 = V_144 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_49 ( & V_8 -> V_140 , V_133 + V_48 -> V_140 * V_135 / 100 ) ;
}
static void F_43 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_141 == V_142 || V_8 -> V_141 == V_146 )
return;
V_8 -> V_145 = V_48 -> V_138 ;
V_8 -> V_141 = V_146 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_49 ( & V_8 -> V_140 , V_133 + V_48 -> V_140 * V_135 / 100 ) ;
}
static void F_59 ( struct V_7 * V_8 , T_1 * V_25 , int V_95 )
{
struct V_147 * V_105 = & V_8 -> V_105 ;
struct V_92 * V_93 = F_37 ( V_105 ) ;
unsigned int V_94 = 0 ;
int V_4 = V_95 ;
if ( V_27 & 16 )
F_8 ( L_24 , V_4 , V_93 ) ;
if ( V_93 ) {
switch ( V_8 -> V_75 ) {
case 4 :
break;
case 3 :
break;
case 2 :
while ( F_3 ( & V_94 , * V_25 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
F_33 ( V_93 , V_8 , V_94 , V_95 ) ;
case 1 :
default:
F_60 ( V_93 , V_25 , V_4 ) ;
F_41 ( V_93 ) ;
}
F_39 ( V_93 ) ;
}
}
static void F_61 ( struct V_7 * V_8 , T_1 * V_25 , int V_4 )
{
unsigned int V_112 = 0 ;
while ( V_4 -- > 0 ) {
if ( F_3 ( & V_112 , * V_25 ++ ) == 1 ) {
int V_95 = * V_25 ++ ;
V_4 -- ;
V_95 >>= 1 ;
if ( V_95 > V_4 )
return;
if ( V_112 & 1 )
F_42 ( V_8 -> V_48 , V_112 ,
V_25 , V_95 ) ;
else
F_44 ( V_8 -> V_48 , V_112 ,
V_25 , V_95 ) ;
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
F_64 ( & V_8 -> V_148 ) ;
F_65 ( & V_8 -> V_149 ) ;
V_8 -> V_76 = & V_8 -> V_150 ;
if ( F_66 ( & V_8 -> V_150 , 4096 , V_136 ) < 0 ) {
F_18 ( V_8 ) ;
return NULL ;
}
F_67 ( & V_8 -> V_85 ) ;
F_68 ( & V_8 -> V_140 ) ;
V_8 -> V_140 . V_151 = F_57 ;
V_8 -> V_140 . V_25 = ( unsigned long ) V_8 ;
F_69 ( & V_8 -> V_105 ) ;
V_8 -> V_105 . V_152 = & V_153 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_75 = V_48 -> V_75 ;
V_8 -> V_141 = V_142 ;
if ( V_22 )
V_8 -> V_25 = F_59 ;
else
V_8 -> V_25 = F_61 ;
V_48 -> V_8 [ V_22 ] = V_8 ;
return V_8 ;
}
static void F_70 ( struct V_154 * V_148 )
{
struct V_7 * V_8 = F_71 ( V_148 , struct V_7 , V_148 ) ;
F_72 ( & V_8 -> V_140 ) ;
V_8 -> V_48 -> V_8 [ V_8 -> V_22 ] = NULL ;
F_73 ( V_8 -> V_76 ) ;
while ( ( V_8 -> V_84 = F_27 ( & V_8 -> V_85 ) ) )
F_28 ( V_8 -> V_84 ) ;
F_18 ( V_8 ) ;
}
static inline void F_74 ( struct V_7 * V_8 )
{
F_75 ( & V_8 -> V_148 ) ;
}
static inline void F_76 ( struct V_7 * V_8 )
{
F_77 ( & V_8 -> V_148 , F_70 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_92 * V_93 = F_37 ( & V_8 -> V_105 ) ;
if ( V_93 ) {
F_79 ( V_93 ) ;
F_39 ( V_93 ) ;
}
F_76 ( V_8 ) ;
}
static void F_80 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
T_1 V_23 ;
int V_155 ;
if ( ( V_48 -> V_24 & ~ V_28 ) == V_33 )
V_48 -> V_1 = F_2 ( V_48 -> V_1 , V_48 -> V_113 , V_48 -> V_4 ) ;
if ( V_48 -> V_51 == 0 ) {
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_156 ) ;
}
if ( V_48 -> V_1 != V_157 ) {
V_48 -> V_158 ++ ;
if ( V_27 & 4 )
F_8 ( L_25 , V_48 -> V_1 ) ;
return;
}
V_155 = V_48 -> V_155 >> 1 ;
if ( V_155 >= V_87 )
goto V_159;
V_23 = V_48 -> V_155 & 1 ;
F_5 ( L_26 , V_155 , V_23 , V_48 -> V_24 , V_48 -> V_113 , V_48 -> V_4 ) ;
V_23 ^= 1 - V_48 -> V_70 ;
V_8 = V_48 -> V_8 [ V_155 ] ;
switch ( V_48 -> V_24 ) {
case V_29 | V_28 :
if ( V_23 == 0 )
goto V_159;
if ( V_8 == NULL )
V_8 = F_62 ( V_48 , V_155 ) ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_115 )
F_12 ( V_48 , V_155 , V_32 ) ;
else {
F_12 ( V_48 , V_155 , V_30 ) ;
F_56 ( V_8 ) ;
}
break;
case V_31 | V_28 :
if ( V_23 == 0 )
goto V_159;
if ( V_8 == NULL || V_8 -> V_141 == V_142 ) {
F_12 ( V_48 , V_155 , V_32 ) ;
return;
}
F_12 ( V_48 , V_155 , V_30 ) ;
F_54 ( V_8 ) ;
break;
case V_30 :
case V_30 | V_28 :
if ( V_23 == 0 || V_8 == NULL )
break;
switch ( V_8 -> V_141 ) {
case V_146 :
F_54 ( V_8 ) ;
break;
case V_144 :
F_56 ( V_8 ) ;
break;
}
break;
case V_32 :
case V_32 | V_28 :
if ( V_23 )
goto V_159;
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
if ( V_8 == NULL || V_8 -> V_141 != V_143 ) {
F_13 ( V_48 , V_155 , V_32 | V_28 ) ;
return;
}
V_8 -> V_25 ( V_8 , V_48 -> V_113 , V_48 -> V_4 ) ;
break;
default:
goto V_159;
}
return;
V_159:
V_48 -> V_160 ++ ;
return;
}
static void F_81 ( struct V_47 * V_48 , unsigned char V_2 )
{
unsigned int V_4 ;
switch ( V_48 -> V_141 ) {
case V_161 :
if ( V_2 == V_52 ) {
V_48 -> V_141 = V_162 ;
V_48 -> V_155 = 0 ;
V_48 -> V_4 = 0 ;
V_48 -> V_1 = V_53 ;
}
break;
case V_162 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_155 , V_2 ) )
V_48 -> V_141 = V_163 ;
break;
case V_163 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_141 = V_164 ;
break;
case V_164 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_4 , V_2 ) ) {
if ( V_48 -> V_4 > V_48 -> V_165 ) {
V_48 -> V_166 ++ ;
V_48 -> V_141 = V_161 ;
break;
}
V_48 -> V_167 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_141 = V_168 ;
else
V_48 -> V_141 = V_169 ;
break;
}
V_48 -> V_141 = V_170 ;
break;
case V_170 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_4 = V_2 ;
V_48 -> V_4 |= V_4 << 7 ;
if ( V_48 -> V_4 > V_48 -> V_165 ) {
V_48 -> V_166 ++ ;
V_48 -> V_141 = V_161 ;
break;
}
V_48 -> V_167 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_141 = V_168 ;
else
V_48 -> V_141 = V_169 ;
break;
case V_169 :
V_48 -> V_113 [ V_48 -> V_167 ++ ] = V_2 ;
if ( V_48 -> V_167 == V_48 -> V_4 )
V_48 -> V_141 = V_168 ;
break;
case V_168 :
V_48 -> V_156 = V_2 ;
F_80 ( V_48 ) ;
V_48 -> V_141 = V_171 ;
break;
case V_171 :
if ( V_2 == V_52 ) {
V_48 -> V_141 = V_161 ;
break;
}
break;
}
}
static void F_82 ( struct V_47 * V_48 , unsigned char V_2 )
{
if ( V_2 == V_42 ) {
if ( V_48 -> V_141 == V_169 && V_48 -> V_167 ) {
V_48 -> V_167 -- ;
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_113 [ V_48 -> V_167 ] ) ;
V_48 -> V_4 = V_48 -> V_167 ;
F_80 ( V_48 ) ;
V_48 -> V_141 = V_172 ;
return;
}
if ( V_48 -> V_141 != V_172 ) {
V_48 -> V_160 ++ ;
V_48 -> V_141 = V_172 ;
}
return;
}
if ( V_2 == V_43 ) {
V_48 -> V_173 = 1 ;
return;
}
if ( V_48 -> V_141 == V_161 )
return;
if ( V_48 -> V_173 ) {
V_2 ^= V_46 ;
V_48 -> V_173 = 0 ;
}
switch ( V_48 -> V_141 ) {
case V_172 :
V_48 -> V_155 = 0 ;
V_48 -> V_141 = V_162 ;
V_48 -> V_1 = V_53 ;
case V_162 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_155 , V_2 ) )
V_48 -> V_141 = V_163 ;
break;
case V_163 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_167 = 0 ;
V_48 -> V_141 = V_169 ;
break;
case V_169 :
if ( V_48 -> V_167 > V_48 -> V_165 ) {
V_48 -> V_141 = V_174 ;
V_48 -> V_166 ++ ;
} else
V_48 -> V_113 [ V_48 -> V_167 ++ ] = V_2 ;
break;
case V_174 :
break;
}
}
static void F_83 ( struct V_47 * V_48 ,
unsigned char V_25 , unsigned char V_175 )
{
V_48 -> V_141 = V_161 ;
V_48 -> V_176 ++ ;
}
void F_84 ( struct V_47 * V_48 )
{
int V_86 ;
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_54 * V_177 ;
V_48 -> V_115 = 1 ;
F_85 ( & V_178 ) ;
for ( V_86 = 0 ; V_86 < V_179 ; V_86 ++ ) {
if ( V_47 [ V_86 ] == V_48 ) {
V_47 [ V_86 ] = NULL ;
break;
}
}
F_86 ( & V_178 ) ;
F_11 ( V_86 == V_179 ) ;
F_72 ( & V_48 -> V_127 ) ;
if ( V_8 ) {
V_8 -> V_115 = 1 ;
F_43 ( V_8 ) ;
F_87 ( V_48 -> V_130 ,
V_8 -> V_141 == V_142 ) ;
}
for ( V_86 = 0 ; V_86 < V_87 ; V_86 ++ )
if ( V_48 -> V_8 [ V_86 ] )
F_78 ( V_48 -> V_8 [ V_86 ] ) ;
for ( V_177 = V_48 -> V_62 ; V_177 != NULL ; V_177 = V_48 -> V_62 ) {
V_48 -> V_62 = V_177 -> V_60 ;
F_18 ( V_177 ) ;
}
V_48 -> V_67 = NULL ;
}
int F_88 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_86 = 0 ;
F_68 ( & V_48 -> V_127 ) ;
V_48 -> V_127 . V_151 = F_48 ;
V_48 -> V_127 . V_25 = ( unsigned long ) V_48 ;
F_89 ( & V_48 -> V_130 ) ;
F_63 ( & V_48 -> V_125 ) ;
F_63 ( & V_48 -> V_72 ) ;
if ( V_48 -> V_51 == 0 )
V_48 -> V_180 = F_81 ;
else
V_48 -> V_180 = F_82 ;
V_48 -> error = F_83 ;
F_85 ( & V_178 ) ;
for ( V_86 = 0 ; V_86 < V_179 ; V_86 ++ ) {
if ( V_47 [ V_86 ] == NULL ) {
V_48 -> V_181 = V_86 ;
V_47 [ V_86 ] = V_48 ;
break;
}
}
F_86 ( & V_178 ) ;
if ( V_86 == V_179 )
return - V_182 ;
V_8 = F_62 ( V_48 , 0 ) ;
if ( V_8 == NULL )
return - V_79 ;
V_48 -> V_115 = 0 ;
return 0 ;
}
void F_90 ( struct V_47 * V_48 )
{
F_18 ( V_48 -> V_65 ) ;
F_18 ( V_48 -> V_113 ) ;
F_18 ( V_48 ) ;
}
static void F_91 ( struct V_154 * V_148 )
{
struct V_47 * V_48 = F_71 ( V_148 , struct V_47 , V_148 ) ;
F_90 ( V_48 ) ;
}
static inline void F_92 ( struct V_47 * V_48 )
{
F_75 ( & V_48 -> V_148 ) ;
}
static inline void F_93 ( struct V_47 * V_48 )
{
F_77 ( & V_48 -> V_148 , F_91 ) ;
}
struct V_47 * F_94 ( void )
{
struct V_47 * V_48 = F_51 ( sizeof( struct V_47 ) , V_136 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_113 = F_15 ( V_183 + 1 , V_136 ) ;
if ( V_48 -> V_113 == NULL ) {
F_18 ( V_48 ) ;
return NULL ;
}
V_48 -> V_65 = F_15 ( 2 * V_183 + 2 , V_136 ) ;
if ( V_48 -> V_65 == NULL ) {
F_18 ( V_48 -> V_113 ) ;
F_18 ( V_48 ) ;
return NULL ;
}
F_63 ( & V_48 -> V_80 ) ;
F_64 ( & V_48 -> V_148 ) ;
V_48 -> V_140 = V_184 ;
V_48 -> V_134 = V_185 ;
V_48 -> V_138 = V_186 ;
V_48 -> V_78 = V_34 ;
V_48 -> V_75 = 1 ;
V_48 -> V_51 = 1 ;
V_48 -> V_165 = 64 ;
V_48 -> V_77 = 64 ;
V_48 -> V_115 = 1 ;
return V_48 ;
}
static int F_95 ( struct V_47 * V_48 , T_1 * V_25 , int V_4 )
{
if ( F_96 ( V_48 -> V_93 ) < V_4 ) {
F_97 ( V_187 , & V_48 -> V_93 -> V_71 ) ;
return - V_188 ;
}
if ( V_27 & 4 )
F_17 ( L_27 , V_66 ,
V_25 , V_4 ) ;
V_48 -> V_93 -> V_152 -> V_189 ( V_48 -> V_93 , V_25 , V_4 ) ;
return V_4 ;
}
static int F_98 ( struct V_92 * V_93 , struct V_47 * V_48 )
{
int V_190 , V_86 ;
int V_191 = V_48 -> V_181 << 6 ;
V_48 -> V_93 = F_99 ( V_93 ) ;
V_48 -> V_40 = F_95 ;
V_190 = F_88 ( V_48 ) ;
if ( V_190 != 0 )
F_39 ( V_48 -> V_93 ) ;
else {
for ( V_86 = 1 ; V_86 < V_87 ; V_86 ++ )
F_100 ( V_192 , V_191 + V_86 , NULL ) ;
}
return V_190 ;
}
static void F_101 ( struct V_92 * V_93 , struct V_47 * V_48 )
{
int V_86 ;
int V_191 = V_48 -> V_181 << 6 ;
F_11 ( V_93 != V_48 -> V_93 ) ;
for ( V_86 = 1 ; V_86 < V_87 ; V_86 ++ )
F_102 ( V_192 , V_191 + V_86 ) ;
F_84 ( V_48 ) ;
F_39 ( V_48 -> V_93 ) ;
V_48 -> V_93 = NULL ;
}
static void F_103 ( struct V_92 * V_93 , const unsigned char * V_193 ,
char * V_194 , int V_167 )
{
struct V_47 * V_48 = V_93 -> V_195 ;
const unsigned char * V_69 ;
char * V_196 ;
int V_86 ;
char V_113 [ 64 ] ;
char V_71 ;
if ( V_27 & 4 )
F_17 ( L_28 , V_66 ,
V_193 , V_167 ) ;
for ( V_86 = V_167 , V_69 = V_193 , V_196 = V_194 ; V_86 ; V_86 -- , V_69 ++ ) {
V_71 = * V_196 ++ ;
switch ( V_71 ) {
case V_197 :
V_48 -> V_180 ( V_48 , * V_69 ) ;
break;
case V_108 :
case V_104 :
case V_109 :
case V_110 :
V_48 -> error ( V_48 , * V_69 , V_71 ) ;
break;
default:
F_104 ( L_29 ,
F_105 ( V_93 , V_113 ) , V_71 ) ;
break;
}
}
}
static T_3 F_106 ( struct V_92 * V_93 )
{
return 0 ;
}
static void F_107 ( struct V_92 * V_93 )
{
}
static void F_108 ( struct V_92 * V_93 )
{
struct V_47 * V_48 = V_93 -> V_195 ;
F_101 ( V_93 , V_48 ) ;
F_107 ( V_93 ) ;
F_93 ( V_48 ) ;
}
static int F_109 ( struct V_92 * V_93 )
{
struct V_47 * V_48 ;
if ( V_93 -> V_152 -> V_189 == NULL )
return - V_198 ;
V_48 = F_94 () ;
if ( V_48 == NULL )
return - V_79 ;
V_93 -> V_195 = V_48 ;
V_93 -> V_199 = 65536 ;
V_48 -> V_51 = 1 ;
return F_98 ( V_93 , V_48 ) ;
}
static void F_110 ( struct V_92 * V_93 )
{
struct V_47 * V_48 = V_93 -> V_195 ;
unsigned long V_71 ;
F_111 ( V_187 , & V_93 -> V_71 ) ;
F_16 ( V_48 ) ;
if ( V_48 -> V_68 < V_90 ) {
F_21 ( & V_48 -> V_72 , V_71 ) ;
F_30 ( V_48 ) ;
F_22 ( & V_48 -> V_72 , V_71 ) ;
}
}
static T_3 F_112 ( struct V_92 * V_93 , struct V_200 * V_200 ,
unsigned char T_4 * V_113 , T_5 V_201 )
{
return - V_128 ;
}
static T_3 F_113 ( struct V_92 * V_93 , struct V_200 * V_200 ,
const unsigned char * V_113 , T_5 V_201 )
{
int V_202 = F_96 ( V_93 ) ;
if ( V_202 >= V_201 )
return V_93 -> V_152 -> V_189 ( V_93 , V_113 , V_201 ) ;
F_97 ( V_187 , & V_93 -> V_71 ) ;
return - V_203 ;
}
static unsigned int F_114 ( struct V_92 * V_93 , struct V_200 * V_200 ,
T_6 * V_204 )
{
unsigned int V_205 = 0 ;
struct V_47 * V_48 = V_93 -> V_195 ;
F_115 ( V_200 , & V_93 -> V_206 , V_204 ) ;
F_115 ( V_200 , & V_93 -> V_207 , V_204 ) ;
if ( F_116 ( V_200 ) )
V_205 |= V_208 ;
if ( ! F_117 ( V_93 ) && F_96 ( V_93 ) > 0 )
V_205 |= V_209 | V_210 ;
if ( V_48 -> V_115 )
V_205 |= V_208 ;
return V_205 ;
}
static int F_118 ( struct V_92 * V_93 , struct V_47 * V_48 ,
struct V_211 * V_2 )
{
int V_212 = 0 ;
int V_213 = 0 ;
if ( ( V_2 -> V_75 != 1 && V_2 -> V_75 != 2 ) || V_2 -> V_214 )
return - V_128 ;
if ( V_2 -> V_165 > V_183 || V_2 -> V_77 > V_215 || V_2 -> V_165 < 8 || V_2 -> V_77 < 8 )
return - V_198 ;
if ( V_2 -> V_138 < 3 )
return - V_198 ;
if ( V_2 -> V_216 > 1 )
return - V_198 ;
if ( V_2 -> V_70 > 1 )
return - V_198 ;
if ( V_2 -> V_86 == 0 || V_2 -> V_86 > 2 )
return - V_198 ;
if ( V_2 -> V_140 != 0 && V_2 -> V_140 != V_48 -> V_140 )
V_213 = 1 ;
if ( V_2 -> V_134 != 0 && V_2 -> V_134 != V_48 -> V_134 )
V_213 = 1 ;
if ( V_2 -> V_216 != V_48 -> V_51 )
V_213 = 1 ;
if ( V_2 -> V_75 != V_48 -> V_75 )
V_213 = 1 ;
if ( V_2 -> V_70 != V_48 -> V_70 )
V_212 = 1 ;
if ( V_2 -> V_165 != V_48 -> V_165 )
V_213 = 1 ;
if ( V_2 -> V_77 != V_48 -> V_77 )
V_213 = 1 ;
if ( V_212 || V_213 ) {
F_43 ( V_48 -> V_8 [ 0 ] ) ;
F_87 ( V_48 -> V_130 ,
V_48 -> V_8 [ 0 ] -> V_141 == V_142 ) ;
if ( F_119 ( V_217 ) )
return - V_218 ;
}
if ( V_213 )
F_84 ( V_48 ) ;
V_48 -> V_70 = V_2 -> V_70 ;
V_48 -> V_165 = V_2 -> V_165 ;
V_48 -> V_77 = V_2 -> V_77 ;
V_48 -> V_51 = V_2 -> V_216 ;
V_48 -> V_75 = V_2 -> V_75 ;
V_48 -> V_138 = V_2 -> V_138 ;
if ( V_2 -> V_86 == 1 )
V_48 -> V_78 = V_34 ;
else if ( V_2 -> V_86 == 2 )
V_48 -> V_78 = V_33 ;
if ( V_2 -> V_140 )
V_48 -> V_140 = V_2 -> V_140 ;
if ( V_2 -> V_134 )
V_48 -> V_134 = V_2 -> V_134 ;
if ( V_213 )
F_88 ( V_48 ) ;
if ( V_48 -> V_70 && V_212 )
F_58 ( V_48 -> V_8 [ 0 ] ) ;
return 0 ;
}
static int F_120 ( struct V_92 * V_93 , struct V_200 * V_200 ,
unsigned int V_91 , unsigned long V_219 )
{
struct V_211 V_2 ;
struct V_47 * V_48 = V_93 -> V_195 ;
switch ( V_91 ) {
case V_220 :
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_75 = V_48 -> V_75 ;
V_2 . V_216 = V_48 -> V_51 ;
V_2 . V_70 = V_48 -> V_70 ;
V_2 . V_140 = V_48 -> V_140 ;
V_2 . V_134 = V_48 -> V_134 ;
V_2 . V_221 = 0 ;
V_2 . V_138 = V_48 -> V_138 ;
if ( V_48 -> V_78 == V_34 )
V_2 . V_86 = 1 ;
else
V_2 . V_86 = 2 ;
F_8 ( L_30 , V_48 -> V_78 , V_2 . V_86 ) ;
V_2 . V_165 = V_48 -> V_165 ;
V_2 . V_77 = V_48 -> V_77 ;
V_2 . V_214 = 0 ;
if ( F_121 ( ( void * ) V_219 , & V_2 , sizeof( V_2 ) ) )
return - V_222 ;
return 0 ;
case V_223 :
if ( F_122 ( & V_2 , ( void * ) V_219 , sizeof( V_2 ) ) )
return - V_222 ;
return F_118 ( V_93 , V_48 , & V_2 ) ;
default:
return F_123 ( V_93 , V_200 , V_91 , V_219 ) ;
}
}
static int F_124 ( struct V_224 * V_89 )
{
F_8 ( L_31 , V_225 ) ;
F_125 ( V_89 ) ;
return 0 ;
}
static int F_126 ( struct V_224 * V_89 )
{
F_127 ( V_89 ) ;
return 0 ;
}
static struct V_226 * F_128 ( struct V_224 * V_89 )
{
return & ( (struct V_227 * ) F_129 ( V_89 ) ) -> V_228 ;
}
static void F_130 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_89 ) {
F_11 ( 1 ) ;
return;
}
V_8 -> V_75 = V_8 -> V_229 ;
V_8 -> V_25 = V_8 -> V_230 ;
F_131 ( V_8 -> V_89 ) ;
V_8 -> V_89 = NULL ;
}
static void F_132 ( struct V_154 * V_148 )
{
struct V_227 * V_231 ;
struct V_7 * V_8 ;
V_231 = F_71 ( V_148 , struct V_227 , V_148 ) ;
V_8 = V_231 -> V_8 ;
if ( V_8 -> V_89 ) {
F_133 ( V_8 -> V_89 ) ;
F_130 ( V_8 ) ;
}
}
static inline void F_134 ( struct V_227 * V_231 )
{
F_75 ( & V_231 -> V_148 ) ;
}
static inline void F_135 ( struct V_227 * V_231 )
{
F_77 ( & V_231 -> V_148 , F_132 ) ;
}
static int F_136 ( struct V_232 * V_84 ,
struct V_224 * V_89 )
{
struct V_227 * V_231 = (struct V_227 * ) F_129 ( V_89 ) ;
struct V_7 * V_8 = V_231 -> V_8 ;
F_134 ( V_231 ) ;
F_137 ( & V_8 -> V_85 , V_84 ) ;
F_138 ( V_89 ) . V_233 ++ ;
F_138 ( V_89 ) . V_68 += V_84 -> V_4 ;
F_31 ( V_8 ) ;
V_89 -> V_234 = V_133 ;
F_135 ( V_231 ) ;
return V_235 ;
}
static void F_139 ( struct V_224 * V_89 )
{
F_140 ( & V_89 -> V_236 , L_32 ) ;
F_138 ( V_89 ) . V_237 ++ ;
}
static void F_141 ( struct V_7 * V_8 ,
unsigned char * V_238 , int V_73 )
{
struct V_224 * V_89 = V_8 -> V_89 ;
struct V_232 * V_84 ;
struct V_227 * V_231 = (struct V_227 * ) F_129 ( V_89 ) ;
F_134 ( V_231 ) ;
V_84 = F_142 ( V_73 + V_239 ) ;
if ( ! V_84 ) {
F_138 ( V_89 ) . V_240 ++ ;
F_135 ( V_231 ) ;
return;
}
F_143 ( V_84 , V_239 ) ;
memcpy ( F_144 ( V_84 , V_73 ) , V_238 , V_73 ) ;
V_84 -> V_236 = V_89 ;
V_84 -> V_241 = F_145 ( V_242 ) ;
F_146 ( V_84 ) ;
F_138 ( V_89 ) . V_243 ++ ;
F_138 ( V_89 ) . V_244 += V_73 ;
F_135 ( V_231 ) ;
return;
}
int F_147 ( struct V_224 * V_89 , int V_245 )
{
struct V_227 * V_231 = (struct V_227 * ) F_129 ( V_89 ) ;
if ( ( V_245 < 8 ) || ( V_245 > V_231 -> V_8 -> V_48 -> V_77 ) )
return - V_198 ;
V_89 -> V_77 = V_245 ;
return 0 ;
}
static void F_148 ( struct V_224 * V_89 )
{
static const struct V_246 V_247 = {
. V_248 = F_124 ,
. V_249 = F_126 ,
. V_250 = F_136 ,
. V_251 = F_139 ,
. V_252 = F_128 ,
. V_253 = F_147 ,
} ;
V_89 -> V_254 = & V_247 ;
V_89 -> V_255 = V_256 ;
V_89 -> V_71 = V_257 | V_258 | V_259 ;
V_89 -> type = V_260 ;
V_89 -> V_261 = 10 ;
}
static void F_149 ( struct V_7 * V_8 )
{
struct V_227 * V_231 ;
F_8 ( L_33 ) ;
if ( ! V_8 -> V_89 )
return;
V_231 = (struct V_227 * ) F_129 ( V_8 -> V_89 ) ;
F_135 ( V_231 ) ;
}
static int F_150 ( struct V_7 * V_8 , struct V_262 * V_263 )
{
char * V_264 ;
int V_265 = 0 ;
struct V_224 * V_89 ;
struct V_227 * V_231 ;
if ( ! F_151 ( V_266 ) )
return - V_267 ;
if ( V_8 -> V_75 > 2 )
return - V_182 ;
if ( V_263 -> V_241 != F_152 ( V_242 ) )
return - V_268 ;
if ( V_263 -> V_75 != 3 && V_263 -> V_75 != 4 )
return - V_268 ;
F_8 ( L_34 ) ;
V_264 = L_35 ;
if ( V_263 -> V_269 [ 0 ] != '\0' )
V_264 = V_263 -> V_269 ;
V_89 = F_153 ( sizeof( struct V_227 ) ,
V_264 ,
F_148 ) ;
if ( ! V_89 ) {
F_154 ( L_36 ) ;
return - V_79 ;
}
V_89 -> V_77 = V_8 -> V_48 -> V_77 ;
V_231 = (struct V_227 * ) F_129 ( V_89 ) ;
V_231 -> V_8 = V_8 ;
F_64 ( & V_231 -> V_148 ) ;
strncpy ( V_263 -> V_269 , V_89 -> V_270 , V_271 ) ;
V_8 -> V_229 = V_8 -> V_75 ;
V_8 -> V_230 = V_8 -> V_25 ;
V_8 -> V_75 = V_263 -> V_75 ;
V_8 -> V_25 = F_141 ;
V_8 -> V_89 = V_89 ;
F_8 ( L_37 ) ;
V_265 = F_155 ( V_89 ) ;
if ( V_265 ) {
F_154 ( L_38 , V_265 ) ;
F_130 ( V_8 ) ;
return V_265 ;
}
return V_89 -> V_272 ;
}
static int F_156 ( struct V_7 * V_8 , T_1 V_97 )
{
T_1 V_9 [ 5 ] ;
struct V_124 * V_55 ;
int V_4 = 2 ;
if ( V_97 )
V_4 ++ ;
V_9 [ 0 ] = V_4 << 1 | V_6 ;
V_9 [ 1 ] = V_8 -> V_22 << 2 | 3 ;
V_9 [ 2 ] = F_4 ( V_8 ) << 1 | V_6 ;
if ( V_97 )
V_9 [ 3 ] = V_97 << 4 | 2 | V_6 ;
V_55 = F_50 ( V_8 -> V_48 , V_106 , V_9 , V_4 + 1 ) ;
if ( V_55 == NULL )
return - V_79 ;
return F_53 ( V_8 -> V_48 , V_55 ) ;
}
static int F_157 ( struct V_147 * V_105 )
{
struct V_7 * V_8 = F_71 ( V_105 , struct V_7 , V_105 ) ;
if ( V_8 -> V_141 != V_143 )
return 0 ;
if ( V_27 & 2 )
return 1 ;
return V_8 -> V_100 & V_19 ;
}
static void F_158 ( struct V_147 * V_105 , int V_273 )
{
struct V_7 * V_8 = F_71 ( V_105 , struct V_7 , V_105 ) ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_273 )
V_12 |= V_13 | V_15 ;
else
V_12 &= ~ ( V_13 | V_15 ) ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
F_156 ( V_8 , 0 ) ;
}
}
static int F_159 ( struct V_92 * V_93 , struct V_200 * V_274 )
{
struct V_47 * V_48 ;
struct V_7 * V_8 ;
struct V_147 * V_105 ;
unsigned int line = V_93 -> V_275 ;
unsigned int V_276 = line >> 6 ;
line = line & 0x3F ;
if ( V_276 >= V_179 )
return - V_277 ;
if ( V_47 [ V_276 ] == NULL )
return - V_278 ;
if ( line == 0 || line > 61 )
return - V_279 ;
V_48 = V_47 [ V_276 ] ;
if ( V_48 -> V_115 )
return - V_280 ;
V_8 = V_48 -> V_8 [ line ] ;
if ( V_8 == NULL )
V_8 = F_62 ( V_48 , line ) ;
if ( V_8 == NULL )
return - V_79 ;
V_105 = & V_8 -> V_105 ;
V_105 -> V_167 ++ ;
V_93 -> V_281 = V_8 ;
F_74 ( V_8 ) ;
F_74 ( V_8 -> V_48 -> V_8 [ 0 ] ) ;
F_92 ( V_8 -> V_48 ) ;
F_160 ( V_105 , V_93 ) ;
V_8 -> V_100 = 0 ;
F_97 ( V_282 , & V_105 -> V_71 ) ;
F_58 ( V_8 ) ;
return F_161 ( V_105 , V_93 , V_274 ) ;
}
static void F_162 ( struct V_92 * V_93 , struct V_200 * V_274 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
struct V_47 * V_48 ;
if ( V_8 == NULL )
return;
F_163 ( & V_8 -> V_149 ) ;
F_149 ( V_8 ) ;
F_164 ( & V_8 -> V_149 ) ;
V_48 = V_8 -> V_48 ;
if ( F_165 ( & V_8 -> V_105 , V_93 , V_274 ) == 0 )
goto V_283;
F_43 ( V_8 ) ;
F_166 ( & V_8 -> V_105 , V_93 ) ;
F_160 ( & V_8 -> V_105 , NULL ) ;
V_283:
F_76 ( V_8 ) ;
F_76 ( V_48 -> V_8 [ 0 ] ) ;
F_93 ( V_48 ) ;
}
static void F_167 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
F_168 ( & V_8 -> V_105 ) ;
F_43 ( V_8 ) ;
}
static int F_169 ( struct V_92 * V_93 , const unsigned char * V_113 ,
int V_4 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
int V_284 = F_170 ( V_8 -> V_76 , V_113 , V_4 , & V_8 -> V_80 ) ;
F_31 ( V_8 ) ;
return V_284 ;
}
static int F_171 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
return V_285 - F_24 ( V_8 -> V_76 ) ;
}
static int F_172 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
return F_24 ( V_8 -> V_76 ) ;
}
static void F_173 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
F_55 ( V_8 -> V_76 ) ;
}
static void F_174 ( struct V_92 * V_93 , int V_286 )
{
}
static int F_175 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
return V_8 -> V_100 ;
}
static int F_176 ( struct V_92 * V_93 ,
unsigned int V_287 , unsigned int V_288 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
unsigned int V_12 = V_8 -> V_12 ;
V_12 &= V_288 ;
V_12 |= V_287 ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
return F_156 ( V_8 , 0 ) ;
}
return 0 ;
}
static int F_177 ( struct V_92 * V_93 ,
unsigned int V_91 , unsigned long V_219 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
struct V_262 V_263 ;
int V_275 ;
switch ( V_91 ) {
case V_289 :
if ( F_122 ( & V_263 , ( void T_4 * ) V_219 , sizeof( V_263 ) ) )
return - V_222 ;
V_263 . V_269 [ V_271 - 1 ] = '\0' ;
F_163 ( & V_8 -> V_149 ) ;
V_275 = F_150 ( V_8 , & V_263 ) ;
F_164 ( & V_8 -> V_149 ) ;
if ( F_121 ( ( void T_4 * ) V_219 , & V_263 , sizeof( V_263 ) ) )
return - V_222 ;
return V_275 ;
case V_290 :
if ( ! F_151 ( V_266 ) )
return - V_267 ;
F_163 ( & V_8 -> V_149 ) ;
F_149 ( V_8 ) ;
F_164 ( & V_8 -> V_149 ) ;
return 0 ;
default:
return - V_291 ;
}
}
static void F_178 ( struct V_92 * V_93 , struct V_292 * V_293 )
{
F_179 ( V_93 -> V_101 , V_293 ) ;
}
static void F_180 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
if ( V_93 -> V_101 -> V_102 & V_294 )
V_8 -> V_12 &= ~ V_13 ;
V_8 -> V_10 = 1 ;
F_156 ( V_8 , 0 ) ;
}
static void F_181 ( struct V_92 * V_93 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
if ( V_93 -> V_101 -> V_102 & V_294 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_10 = 0 ;
F_156 ( V_8 , 0 ) ;
}
static int F_182 ( struct V_92 * V_93 , int V_141 )
{
struct V_7 * V_8 = V_93 -> V_281 ;
int V_295 = 0 ;
if ( V_141 == - 1 )
V_295 = 0x0F ;
else if ( V_141 > 0 ) {
V_295 = V_141 / 200 ;
if ( V_295 > 0x0F )
V_295 = 0x0F ;
}
return F_156 ( V_8 , V_295 ) ;
}
static int T_7 F_183 ( void )
{
int V_296 = F_184 ( V_297 , & V_298 ) ;
if ( V_296 != 0 ) {
F_154 ( L_39 ,
V_296 ) ;
return V_296 ;
}
V_192 = F_185 ( 256 ) ;
if ( ! V_192 ) {
F_186 ( V_297 ) ;
F_154 ( L_40 ) ;
return - V_198 ;
}
V_192 -> V_299 = V_300 ;
V_192 -> V_301 = L_41 ;
V_192 -> V_270 = L_41 ;
V_192 -> V_302 = 0 ;
V_192 -> V_303 = 0 ;
V_192 -> type = V_304 ;
V_192 -> V_305 = V_306 ;
V_192 -> V_71 = V_307 | V_308
| V_309 ;
V_192 -> V_310 = V_311 ;
V_192 -> V_310 . V_312 &= ~ V_313 ;
F_187 ( V_192 , & V_314 ) ;
F_63 ( & V_178 ) ;
if ( F_188 ( V_192 ) ) {
F_189 ( V_192 ) ;
F_186 ( V_297 ) ;
F_154 ( L_42 ) ;
return - V_182 ;
}
F_8 ( L_43 ,
V_192 -> V_302 , V_192 -> V_303 ) ;
return 0 ;
}
static void T_8 F_190 ( void )
{
int V_296 = F_186 ( V_297 ) ;
if ( V_296 != 0 )
F_154 ( L_44 ,
V_296 ) ;
F_191 ( V_192 ) ;
F_189 ( V_192 ) ;
}
