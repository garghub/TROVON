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
( V_24 & 0x0E ) >> 1 , ( V_24 & 0xE0 ) >> 5 ) ;
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
F_16 ( & V_56 -> V_60 ) ;
return V_56 ;
}
static void F_17 ( struct V_47 * V_48 )
{
struct V_54 * V_61 , * V_62 ;
int V_4 ;
int V_63 = 0 ;
F_18 (msg, nmsg, &gsm->tx_list, list) {
if ( V_48 -> V_64 && V_61 -> V_22 )
continue;
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
F_19 ( L_20 ,
V_66 ,
V_48 -> V_65 , V_4 ) ;
if ( V_48 -> V_40 ( V_48 , V_48 -> V_65 + V_63 ,
V_4 - V_63 ) < 0 )
break;
V_48 -> V_67 -= V_61 -> V_4 ;
V_63 = 1 ;
F_20 ( & V_61 -> V_60 ) ;
F_21 ( V_61 ) ;
}
}
static void F_22 ( struct V_7 * V_8 , struct V_54 * V_61 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
T_1 * V_68 = V_61 -> V_25 ;
T_1 * V_1 = V_68 + V_61 -> V_4 ;
if ( V_48 -> V_51 == 0 ) {
if ( V_61 -> V_4 < 128 )
* -- V_68 = ( V_61 -> V_4 << 1 ) | V_6 ;
else {
* -- V_68 = ( V_61 -> V_4 >> 7 ) ;
* -- V_68 = ( V_61 -> V_4 & 127 ) << 1 ;
}
}
* -- V_68 = V_61 -> V_55 ;
if ( V_48 -> V_69 )
* -- V_68 = ( V_61 -> V_22 << 2 ) | 2 | V_6 ;
else
* -- V_68 = ( V_61 -> V_22 << 2 ) | V_6 ;
* V_1 = F_2 ( V_53 , V_68 , V_61 -> V_25 - V_68 ) ;
if ( V_61 -> V_55 == V_33 || V_61 -> V_55 == ( V_33 | V_28 ) )
* V_1 = F_2 ( * V_1 , V_61 -> V_25 , V_61 -> V_4 ) ;
* V_1 = 0xFF - * V_1 ;
F_5 ( L_21 , V_61 -> V_22 , V_48 -> V_69 , V_61 -> V_55 ,
V_61 -> V_25 , V_61 -> V_4 ) ;
V_61 -> V_4 += ( V_61 -> V_25 - V_68 ) + 1 ;
V_61 -> V_25 = V_68 ;
F_23 ( & V_61 -> V_60 , & V_48 -> V_70 ) ;
V_48 -> V_67 += V_61 -> V_4 ;
F_17 ( V_48 ) ;
}
static void F_24 ( struct V_7 * V_8 , struct V_54 * V_61 )
{
unsigned long V_71 ;
F_25 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
F_22 ( V_8 , V_61 ) ;
F_26 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
}
static int F_27 ( struct V_47 * V_48 , struct V_7 * V_8 )
{
struct V_54 * V_61 ;
T_1 * V_68 ;
int V_4 , V_73 , V_74 ;
int V_75 = V_8 -> V_76 - 1 ;
V_73 = 0 ;
while ( 1 ) {
V_4 = F_28 ( V_8 -> V_77 ) ;
if ( V_4 == 0 )
return V_73 ;
if ( V_4 > V_48 -> V_78 )
V_4 = V_48 -> V_78 ;
V_74 = V_4 + V_75 ;
V_61 = F_14 ( V_48 , V_8 -> V_22 , V_74 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return - V_80 ;
V_68 = V_61 -> V_25 ;
switch ( V_8 -> V_76 ) {
case 1 :
break;
case 2 :
* V_68 ++ = F_4 ( V_8 ) ;
break;
}
F_11 ( F_29 ( V_8 -> V_77 , V_68 , V_4 , & V_8 -> V_81 ) != V_4 ) ;
F_22 ( V_8 , V_61 ) ;
V_73 += V_74 ;
}
return V_73 ;
}
static int F_30 ( struct V_47 * V_48 ,
struct V_7 * V_8 )
{
struct V_54 * V_61 ;
T_1 * V_68 ;
int V_4 , V_74 ;
int V_82 = 0 , V_83 = 0 ;
int V_84 = 0 ;
if ( V_8 -> V_76 == 4 )
V_84 = 1 ;
if ( V_8 -> V_85 == NULL ) {
V_8 -> V_85 = F_31 ( & V_8 -> V_86 ) ;
if ( V_8 -> V_85 == NULL )
return 0 ;
V_83 = 1 ;
}
V_4 = V_8 -> V_85 -> V_4 + V_84 ;
if ( V_4 > V_48 -> V_78 ) {
if ( V_8 -> V_76 == 3 ) {
F_32 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
return 0 ;
}
V_4 = V_48 -> V_78 ;
} else
V_82 = 1 ;
V_74 = V_4 + V_84 ;
V_61 = F_14 ( V_48 , V_8 -> V_22 , V_74 , V_48 -> V_79 ) ;
if ( V_61 == NULL ) {
F_33 ( & V_8 -> V_86 , V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
return - V_80 ;
}
V_68 = V_61 -> V_25 ;
if ( V_8 -> V_76 == 4 ) {
* V_68 ++ = V_82 << 7 | V_83 << 6 | 1 ;
V_4 -- ;
}
memcpy ( V_68 , V_8 -> V_85 -> V_25 , V_4 ) ;
F_34 ( V_8 -> V_85 , V_4 ) ;
F_22 ( V_8 , V_61 ) ;
if ( V_82 ) {
F_32 ( V_8 -> V_85 ) ;
V_8 -> V_85 = NULL ;
}
return V_74 ;
}
static void F_35 ( struct V_47 * V_48 )
{
int V_4 ;
int V_87 = 1 ;
while ( V_87 < V_88 ) {
struct V_7 * V_8 ;
if ( V_48 -> V_67 > V_89 )
break;
V_8 = V_48 -> V_8 [ V_87 ] ;
if ( V_8 == NULL || V_8 -> V_64 ) {
V_87 ++ ;
continue;
}
if ( V_8 -> V_76 < 3 && ! V_8 -> V_90 )
V_4 = F_27 ( V_48 , V_8 ) ;
else
V_4 = F_30 ( V_48 , V_8 ) ;
if ( V_4 < 0 )
break;
if ( V_4 == 0 )
V_87 ++ ;
}
}
static void F_36 ( struct V_7 * V_8 )
{
unsigned long V_71 ;
int V_91 ;
if ( V_8 -> V_64 )
return;
F_25 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
V_91 = ( V_8 -> V_48 -> V_67 < V_92 ) ;
if ( V_8 -> V_48 -> V_67 == 0 ) {
if ( V_8 -> V_90 )
F_30 ( V_8 -> V_48 , V_8 ) ;
else
F_27 ( V_8 -> V_48 , V_8 ) ;
}
if ( V_91 )
F_35 ( V_8 -> V_48 ) ;
F_26 ( & V_8 -> V_48 -> V_72 , V_71 ) ;
}
static void F_37 ( struct V_47 * V_48 , int V_93 , T_1 * V_25 ,
int V_26 )
{
struct V_54 * V_61 ;
V_61 = F_14 ( V_48 , 0 , V_26 + 2 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_93 & 0xFE ) << 1 | V_6 ;
V_61 -> V_25 [ 1 ] = ( V_26 << 1 ) | V_6 ;
memcpy ( V_61 -> V_25 + 2 , V_25 , V_26 ) ;
F_24 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_38 ( struct V_94 * V_95 , struct V_7 * V_8 ,
T_2 V_96 , int V_97 )
{
int V_98 = 0 ;
T_1 V_99 = 0 ;
int V_100 ;
if ( V_97 == 2 )
V_96 = V_96 & 0x7f ;
else {
V_99 = V_96 & 0x7f ;
V_96 = ( V_96 >> 7 ) & 0x7f ;
}
V_100 = ( V_96 & V_11 ) || ! ( V_96 & V_16 ) ;
if ( V_100 && ! V_8 -> V_64 ) {
V_8 -> V_64 = 1 ;
} else if ( ! V_100 && V_8 -> V_64 ) {
V_8 -> V_64 = 0 ;
F_36 ( V_8 ) ;
}
if ( V_96 & V_14 )
V_98 |= V_101 | V_13 ;
if ( V_96 & V_16 )
V_98 |= V_15 | V_102 ;
if ( V_96 & V_18 )
V_98 |= V_17 ;
if ( V_96 & V_20 )
V_98 |= V_19 ;
if ( V_95 ) {
if ( ( V_98 & V_19 ) == 0 && ( V_8 -> V_103 & V_19 ) )
if ( ! ( V_95 -> V_104 . V_105 & V_106 ) )
F_39 ( V_95 ) ;
}
if ( V_99 & 0x01 )
F_40 ( & V_8 -> V_107 , 0 , V_108 ) ;
V_8 -> V_103 = V_98 ;
}
static void F_41 ( struct V_47 * V_48 , T_1 * V_25 , int V_97 )
{
unsigned int V_22 = 0 ;
unsigned int V_96 = 0 ;
unsigned int V_99 = 0 ;
struct V_7 * V_8 ;
int V_4 = V_97 ;
T_1 * V_68 = V_25 ;
struct V_94 * V_95 ;
while ( F_3 ( & V_22 , * V_68 ++ ) == 0 ) {
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
while ( F_3 ( & V_96 , * V_68 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_4 -- ;
if ( V_4 > 0 ) {
while ( F_3 ( & V_99 , * V_68 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_96 <<= 7 ;
V_96 |= ( V_99 & 0x7f ) ;
}
V_95 = F_42 ( & V_8 -> V_107 ) ;
F_38 ( V_95 , V_8 , V_96 , V_97 ) ;
if ( V_95 ) {
F_43 ( V_95 ) ;
F_44 ( V_95 ) ;
}
F_37 ( V_48 , V_109 , V_25 , V_97 ) ;
}
static void F_45 ( struct V_47 * V_48 , T_1 * V_25 , int V_97 )
{
struct V_110 * V_107 ;
unsigned int V_22 = 0 ;
T_1 V_111 ;
int V_4 = V_97 ;
T_1 * V_68 = V_25 ;
while ( F_3 ( & V_22 , * V_68 ++ ) == 0 ) {
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
V_111 = * V_68 ;
if ( ( V_111 & 1 ) == 0 )
return;
V_107 = & V_48 -> V_8 [ V_22 ] -> V_107 ;
if ( V_111 & 2 )
F_40 ( V_107 , 0 , V_112 ) ;
if ( V_111 & 4 )
F_40 ( V_107 , 0 , V_113 ) ;
if ( V_111 & 8 )
F_40 ( V_107 , 0 , V_114 ) ;
F_46 ( V_107 ) ;
F_37 ( V_48 , V_115 , V_25 , V_97 ) ;
}
static void F_47 ( struct V_47 * V_48 , unsigned int V_116 ,
T_1 * V_25 , int V_97 )
{
T_1 V_117 [ 1 ] ;
unsigned long V_71 ;
switch ( V_116 ) {
case V_118 : {
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
if ( V_8 ) {
V_8 -> V_119 = 1 ;
V_48 -> V_119 = 1 ;
F_48 ( V_8 ) ;
}
}
break;
case V_120 :
F_37 ( V_48 , V_120 , V_25 , V_97 ) ;
break;
case V_121 :
V_48 -> V_64 = 0 ;
F_37 ( V_48 , V_121 , NULL , 0 ) ;
F_25 ( & V_48 -> V_72 , V_71 ) ;
F_17 ( V_48 ) ;
F_26 ( & V_48 -> V_72 , V_71 ) ;
break;
case V_122 :
V_48 -> V_64 = 1 ;
F_37 ( V_48 , V_122 , NULL , 0 ) ;
break;
case V_109 :
F_41 ( V_48 , V_25 , V_97 ) ;
break;
case V_115 :
F_45 ( V_48 , V_25 , V_97 ) ;
break;
case V_123 :
F_37 ( V_48 , V_123 , NULL , 0 ) ;
break;
case V_124 :
case V_125 :
case V_126 :
default:
V_117 [ 0 ] = V_116 ;
F_37 ( V_48 , V_127 , V_117 , 1 ) ;
break;
}
}
static void F_49 ( struct V_47 * V_48 , unsigned int V_116 ,
T_1 * V_25 , int V_97 )
{
struct V_128 * V_55 ;
unsigned long V_71 ;
F_25 ( & V_48 -> V_129 , V_71 ) ;
V_55 = V_48 -> V_130 ;
V_116 |= 1 ;
if ( V_55 != NULL && ( V_116 == V_55 -> V_93 || V_116 == V_127 ) ) {
F_50 ( & V_48 -> V_131 ) ;
V_48 -> V_130 = NULL ;
if ( V_116 == V_127 )
V_55 -> error = - V_132 ;
V_55 -> V_133 = 1 ;
F_51 ( & V_48 -> V_134 ) ;
}
F_26 ( & V_48 -> V_129 , V_71 ) ;
}
static void F_52 ( struct V_47 * V_48 , struct V_128 * V_55 )
{
struct V_54 * V_61 = F_14 ( V_48 , 0 , V_55 -> V_4 + 1 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_55 -> V_93 << 1 ) | 2 | V_6 ;
memcpy ( V_61 -> V_25 + 1 , V_55 -> V_25 , V_55 -> V_4 ) ;
F_24 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_53 ( unsigned long V_25 )
{
struct V_47 * V_48 = (struct V_47 * ) V_25 ;
struct V_128 * V_55 ;
unsigned long V_71 ;
F_25 ( & V_48 -> V_129 , V_71 ) ;
V_55 = V_48 -> V_130 ;
if ( V_55 ) {
V_48 -> V_135 -- ;
if ( V_48 -> V_135 == 0 ) {
V_48 -> V_130 = NULL ;
V_55 -> error = - V_136 ;
V_55 -> V_133 = 1 ;
F_26 ( & V_48 -> V_129 , V_71 ) ;
F_51 ( & V_48 -> V_134 ) ;
return;
}
F_52 ( V_48 , V_55 ) ;
F_54 ( & V_48 -> V_131 , V_137 + V_48 -> V_138 * V_139 / 100 ) ;
}
F_26 ( & V_48 -> V_129 , V_71 ) ;
}
static struct V_128 * F_55 ( struct V_47 * V_48 ,
unsigned int V_116 , T_1 * V_25 , int V_97 )
{
struct V_128 * V_55 = F_56 ( sizeof( struct V_128 ) ,
V_140 ) ;
unsigned long V_71 ;
if ( V_55 == NULL )
return NULL ;
V_141:
F_57 ( V_48 -> V_134 , V_48 -> V_130 == NULL ) ;
F_25 ( & V_48 -> V_129 , V_71 ) ;
if ( V_48 -> V_130 != NULL ) {
F_26 ( & V_48 -> V_129 , V_71 ) ;
goto V_141;
}
V_55 -> V_93 = V_116 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_4 = V_97 ;
V_48 -> V_130 = V_55 ;
V_48 -> V_135 = V_48 -> V_142 ;
F_54 ( & V_48 -> V_131 , V_137 + V_48 -> V_138 * V_139 / 100 ) ;
F_52 ( V_48 , V_55 ) ;
F_26 ( & V_48 -> V_129 , V_71 ) ;
return V_55 ;
}
static int F_58 ( struct V_47 * V_48 , struct V_128 * V_24 )
{
int V_143 ;
F_57 ( V_48 -> V_134 , V_24 -> V_133 == 1 ) ;
V_143 = V_24 -> error ;
F_21 ( V_24 ) ;
return V_143 ;
}
static void F_59 ( struct V_7 * V_8 )
{
F_50 ( & V_8 -> V_144 ) ;
if ( V_27 & 8 )
F_8 ( L_22 , V_8 -> V_22 ) ;
V_8 -> V_145 = V_146 ;
if ( V_8 -> V_22 != 0 ) {
F_60 ( & V_8 -> V_107 , false ) ;
F_61 ( V_8 -> V_77 ) ;
} else
V_8 -> V_48 -> V_119 = 1 ;
F_51 ( & V_8 -> V_48 -> V_134 ) ;
}
static void F_62 ( struct V_7 * V_8 )
{
F_50 ( & V_8 -> V_144 ) ;
V_8 -> V_145 = V_147 ;
if ( V_27 & 8 )
F_8 ( L_23 , V_8 -> V_22 ) ;
F_51 ( & V_8 -> V_48 -> V_134 ) ;
}
static void F_63 ( unsigned long V_25 )
{
struct V_7 * V_8 = (struct V_7 * ) V_25 ;
struct V_47 * V_48 = V_8 -> V_48 ;
switch ( V_8 -> V_145 ) {
case V_148 :
V_8 -> V_149 -- ;
if ( V_8 -> V_149 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_54 ( & V_8 -> V_144 , V_137 + V_48 -> V_144 * V_139 / 100 ) ;
} else
F_59 ( V_8 ) ;
break;
case V_150 :
V_8 -> V_149 -- ;
if ( V_8 -> V_149 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_54 ( & V_8 -> V_144 , V_137 + V_48 -> V_144 * V_139 / 100 ) ;
} else
F_59 ( V_8 ) ;
break;
}
}
static void F_64 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_145 == V_147 || V_8 -> V_145 == V_148 )
return;
V_8 -> V_149 = V_48 -> V_142 ;
V_8 -> V_145 = V_148 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_54 ( & V_8 -> V_144 , V_137 + V_48 -> V_144 * V_139 / 100 ) ;
}
static void F_48 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_145 == V_146 || V_8 -> V_145 == V_150 )
return;
V_8 -> V_149 = V_48 -> V_142 ;
V_8 -> V_145 = V_150 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_54 ( & V_8 -> V_144 , V_137 + V_48 -> V_144 * V_139 / 100 ) ;
}
static void F_65 ( struct V_7 * V_8 , T_1 * V_25 , int V_97 )
{
struct V_110 * V_107 = & V_8 -> V_107 ;
struct V_94 * V_95 ;
unsigned int V_96 = 0 ;
int V_4 = V_97 ;
if ( V_27 & 16 )
F_8 ( L_24 , V_4 ) ;
switch ( V_8 -> V_76 ) {
case 4 :
break;
case 3 :
break;
case 2 :
while ( F_3 ( & V_96 , * V_25 ++ ) == 0 ) {
V_4 -- ;
if ( V_4 == 0 )
return;
}
V_95 = F_42 ( V_107 ) ;
if ( V_95 ) {
F_38 ( V_95 , V_8 , V_96 , V_97 ) ;
F_44 ( V_95 ) ;
}
case 1 :
default:
F_66 ( V_107 , V_25 , V_4 ) ;
F_46 ( V_107 ) ;
}
}
static void F_67 ( struct V_7 * V_8 , T_1 * V_25 , int V_4 )
{
unsigned int V_116 = 0 ;
while ( V_4 -- > 0 ) {
if ( F_3 ( & V_116 , * V_25 ++ ) == 1 ) {
int V_97 = * V_25 ++ ;
V_4 -- ;
V_97 >>= 1 ;
if ( V_97 > V_4 )
return;
if ( V_116 & 1 )
F_47 ( V_8 -> V_48 , V_116 ,
V_25 , V_97 ) ;
else
F_49 ( V_8 -> V_48 , V_116 ,
V_25 , V_97 ) ;
return;
}
}
}
static struct V_7 * F_68 ( struct V_47 * V_48 , int V_22 )
{
struct V_7 * V_8 = F_56 ( sizeof( struct V_7 ) , V_58 ) ;
if ( V_8 == NULL )
return NULL ;
F_69 ( & V_8 -> V_81 ) ;
F_70 ( & V_8 -> V_151 ) ;
V_8 -> V_77 = & V_8 -> V_152 ;
if ( F_71 ( & V_8 -> V_152 , 4096 , V_140 ) < 0 ) {
F_21 ( V_8 ) ;
return NULL ;
}
F_72 ( & V_8 -> V_86 ) ;
F_73 ( & V_8 -> V_144 ) ;
V_8 -> V_144 . V_153 = F_63 ;
V_8 -> V_144 . V_25 = ( unsigned long ) V_8 ;
F_74 ( & V_8 -> V_107 ) ;
V_8 -> V_107 . V_154 = & V_155 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_76 = V_48 -> V_76 ;
V_8 -> V_145 = V_146 ;
if ( V_22 )
V_8 -> V_25 = F_65 ;
else
V_8 -> V_25 = F_67 ;
V_48 -> V_8 [ V_22 ] = V_8 ;
return V_8 ;
}
static void F_75 ( struct V_110 * V_107 )
{
struct V_7 * V_8 = F_76 ( V_107 , struct V_7 , V_107 ) ;
F_77 ( & V_8 -> V_144 ) ;
V_8 -> V_48 -> V_8 [ V_8 -> V_22 ] = NULL ;
F_78 ( V_8 -> V_77 ) ;
while ( ( V_8 -> V_85 = F_79 ( & V_8 -> V_86 ) ) )
F_80 ( V_8 -> V_85 ) ;
F_21 ( V_8 ) ;
}
static inline void F_81 ( struct V_7 * V_8 )
{
F_82 ( & V_8 -> V_107 ) ;
}
static inline void F_83 ( struct V_7 * V_8 )
{
F_84 ( & V_8 -> V_107 ) ;
}
static void F_85 ( struct V_7 * V_8 )
{
struct V_94 * V_95 = F_42 ( & V_8 -> V_107 ) ;
if ( V_95 ) {
F_86 ( & V_8 -> V_151 ) ;
F_87 ( V_8 ) ;
F_88 ( & V_8 -> V_151 ) ;
F_89 ( V_95 ) ;
F_90 ( & V_8 -> V_107 , NULL ) ;
F_44 ( V_95 ) ;
}
V_8 -> V_145 = V_146 ;
F_83 ( V_8 ) ;
}
static void F_91 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
T_1 V_23 ;
int V_156 ;
if ( ( V_48 -> V_24 & ~ V_28 ) == V_33 )
V_48 -> V_1 = F_2 ( V_48 -> V_1 , V_48 -> V_117 , V_48 -> V_4 ) ;
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
F_5 ( L_26 , V_156 , V_23 , V_48 -> V_24 , V_48 -> V_117 , V_48 -> V_4 ) ;
V_23 ^= 1 - V_48 -> V_69 ;
V_8 = V_48 -> V_8 [ V_156 ] ;
switch ( V_48 -> V_24 ) {
case V_29 | V_28 :
if ( V_23 == 0 )
goto V_160;
if ( V_8 == NULL )
V_8 = F_68 ( V_48 , V_156 ) ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_119 )
F_12 ( V_48 , V_156 , V_32 ) ;
else {
F_12 ( V_48 , V_156 , V_30 ) ;
F_62 ( V_8 ) ;
}
break;
case V_31 | V_28 :
if ( V_23 == 0 )
goto V_160;
if ( V_8 == NULL || V_8 -> V_145 == V_146 ) {
F_12 ( V_48 , V_156 , V_32 ) ;
return;
}
F_12 ( V_48 , V_156 , V_30 ) ;
F_59 ( V_8 ) ;
break;
case V_30 :
case V_30 | V_28 :
if ( V_23 == 0 || V_8 == NULL )
break;
switch ( V_8 -> V_145 ) {
case V_150 :
F_59 ( V_8 ) ;
break;
case V_148 :
F_62 ( V_8 ) ;
break;
}
break;
case V_32 :
case V_32 | V_28 :
if ( V_23 )
goto V_160;
if ( V_8 == NULL )
return;
F_59 ( V_8 ) ;
break;
case V_33 :
case V_33 | V_28 :
case V_34 :
case V_34 | V_28 :
#if 0
if (cr)
goto invalid;
#endif
if ( V_8 == NULL || V_8 -> V_145 != V_147 ) {
F_13 ( V_48 , V_156 , V_32 | V_28 ) ;
return;
}
V_8 -> V_25 ( V_8 , V_48 -> V_117 , V_48 -> V_4 ) ;
break;
default:
goto V_160;
}
return;
V_160:
V_48 -> V_161 ++ ;
return;
}
static void F_92 ( struct V_47 * V_48 , unsigned char V_2 )
{
unsigned int V_4 ;
switch ( V_48 -> V_145 ) {
case V_162 :
if ( V_2 == V_52 ) {
V_48 -> V_145 = V_163 ;
V_48 -> V_156 = 0 ;
V_48 -> V_4 = 0 ;
V_48 -> V_1 = V_53 ;
}
break;
case V_163 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_156 , V_2 ) )
V_48 -> V_145 = V_164 ;
break;
case V_164 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_145 = V_165 ;
break;
case V_165 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_4 , V_2 ) ) {
if ( V_48 -> V_4 > V_48 -> V_166 ) {
V_48 -> V_167 ++ ;
V_48 -> V_145 = V_162 ;
break;
}
V_48 -> V_168 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_145 = V_169 ;
else
V_48 -> V_145 = V_170 ;
break;
}
V_48 -> V_145 = V_171 ;
break;
case V_171 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_4 = V_2 ;
V_48 -> V_4 |= V_4 << 7 ;
if ( V_48 -> V_4 > V_48 -> V_166 ) {
V_48 -> V_167 ++ ;
V_48 -> V_145 = V_162 ;
break;
}
V_48 -> V_168 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_145 = V_169 ;
else
V_48 -> V_145 = V_170 ;
break;
case V_170 :
V_48 -> V_117 [ V_48 -> V_168 ++ ] = V_2 ;
if ( V_48 -> V_168 == V_48 -> V_4 )
V_48 -> V_145 = V_169 ;
break;
case V_169 :
V_48 -> V_157 = V_2 ;
F_91 ( V_48 ) ;
V_48 -> V_145 = V_172 ;
break;
case V_172 :
if ( V_2 == V_52 ) {
V_48 -> V_145 = V_162 ;
break;
}
break;
}
}
static void F_93 ( struct V_47 * V_48 , unsigned char V_2 )
{
if ( V_2 == V_42 ) {
if ( V_48 -> V_145 == V_170 && V_48 -> V_168 ) {
V_48 -> V_168 -- ;
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_117 [ V_48 -> V_168 ] ) ;
V_48 -> V_4 = V_48 -> V_168 ;
F_91 ( V_48 ) ;
V_48 -> V_145 = V_173 ;
return;
}
if ( V_48 -> V_145 != V_173 ) {
V_48 -> V_161 ++ ;
V_48 -> V_145 = V_173 ;
}
return;
}
if ( V_2 == V_43 ) {
V_48 -> V_174 = 1 ;
return;
}
if ( V_48 -> V_145 == V_162 )
return;
if ( V_48 -> V_174 ) {
V_2 ^= V_46 ;
V_48 -> V_174 = 0 ;
}
switch ( V_48 -> V_145 ) {
case V_173 :
V_48 -> V_156 = 0 ;
V_48 -> V_145 = V_163 ;
V_48 -> V_1 = V_53 ;
case V_163 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_156 , V_2 ) )
V_48 -> V_145 = V_164 ;
break;
case V_164 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_168 = 0 ;
V_48 -> V_145 = V_170 ;
break;
case V_170 :
if ( V_48 -> V_168 > V_48 -> V_166 ) {
V_48 -> V_145 = V_175 ;
V_48 -> V_167 ++ ;
} else
V_48 -> V_117 [ V_48 -> V_168 ++ ] = V_2 ;
break;
case V_175 :
break;
}
}
static void F_94 ( struct V_47 * V_48 ,
unsigned char V_25 , unsigned char V_176 )
{
V_48 -> V_145 = V_162 ;
V_48 -> V_177 ++ ;
}
static void F_95 ( struct V_47 * V_48 )
{
int V_87 ;
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_54 * V_178 , * V_179 ;
struct V_128 * V_180 ;
V_48 -> V_119 = 1 ;
F_96 ( & V_181 ) ;
for ( V_87 = 0 ; V_87 < V_182 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == V_48 ) {
V_47 [ V_87 ] = NULL ;
break;
}
}
F_97 ( & V_181 ) ;
F_11 ( V_87 == V_182 ) ;
if ( V_8 ) {
V_180 = F_55 ( V_48 , V_118 , NULL , 0 ) ;
if ( V_180 )
F_58 ( V_48 , V_180 ) ;
}
F_77 ( & V_48 -> V_131 ) ;
if ( V_8 ) {
V_8 -> V_119 = 1 ;
F_48 ( V_8 ) ;
F_98 ( V_48 -> V_134 ,
V_8 -> V_145 == V_146 ) ;
}
F_86 ( & V_48 -> V_151 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
if ( V_48 -> V_8 [ V_87 ] )
F_85 ( V_48 -> V_8 [ V_87 ] ) ;
F_88 ( & V_48 -> V_151 ) ;
F_18 (txq, ntxq, &gsm->tx_list, list)
F_21 ( V_178 ) ;
F_16 ( & V_48 -> V_70 ) ;
}
static int F_99 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_87 = 0 ;
F_100 ( & V_48 -> V_131 , F_53 , ( unsigned long ) V_48 ) ;
F_101 ( & V_48 -> V_134 ) ;
F_69 ( & V_48 -> V_129 ) ;
F_69 ( & V_48 -> V_72 ) ;
if ( V_48 -> V_51 == 0 )
V_48 -> V_183 = F_92 ;
else
V_48 -> V_183 = F_93 ;
V_48 -> error = F_94 ;
F_96 ( & V_181 ) ;
for ( V_87 = 0 ; V_87 < V_182 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == NULL ) {
V_48 -> V_184 = V_87 ;
V_47 [ V_87 ] = V_48 ;
break;
}
}
F_97 ( & V_181 ) ;
if ( V_87 == V_182 )
return - V_185 ;
V_8 = F_68 ( V_48 , 0 ) ;
if ( V_8 == NULL )
return - V_80 ;
V_48 -> V_119 = 0 ;
return 0 ;
}
static void F_102 ( struct V_47 * V_48 )
{
F_21 ( V_48 -> V_65 ) ;
F_21 ( V_48 -> V_117 ) ;
F_21 ( V_48 ) ;
}
static void F_103 ( struct V_186 * V_187 )
{
struct V_47 * V_48 = F_76 ( V_187 , struct V_47 , V_187 ) ;
F_102 ( V_48 ) ;
}
static inline void F_104 ( struct V_47 * V_48 )
{
F_105 ( & V_48 -> V_187 ) ;
}
static inline void F_106 ( struct V_47 * V_48 )
{
F_107 ( & V_48 -> V_187 , F_103 ) ;
}
static struct V_47 * F_108 ( void )
{
struct V_47 * V_48 = F_56 ( sizeof( struct V_47 ) , V_140 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_117 = F_15 ( V_188 + 1 , V_140 ) ;
if ( V_48 -> V_117 == NULL ) {
F_21 ( V_48 ) ;
return NULL ;
}
V_48 -> V_65 = F_15 ( 2 * V_188 + 2 , V_140 ) ;
if ( V_48 -> V_65 == NULL ) {
F_21 ( V_48 -> V_117 ) ;
F_21 ( V_48 ) ;
return NULL ;
}
F_69 ( & V_48 -> V_81 ) ;
F_70 ( & V_48 -> V_151 ) ;
F_109 ( & V_48 -> V_187 ) ;
F_16 ( & V_48 -> V_70 ) ;
V_48 -> V_144 = V_189 ;
V_48 -> V_138 = V_190 ;
V_48 -> V_142 = V_191 ;
V_48 -> V_79 = V_34 ;
V_48 -> V_76 = 1 ;
V_48 -> V_51 = 1 ;
V_48 -> V_166 = 64 ;
V_48 -> V_78 = 64 ;
V_48 -> V_119 = 1 ;
return V_48 ;
}
static int F_110 ( struct V_47 * V_48 , T_1 * V_25 , int V_4 )
{
if ( F_111 ( V_48 -> V_95 ) < V_4 ) {
F_112 ( V_192 , & V_48 -> V_95 -> V_71 ) ;
return - V_193 ;
}
if ( V_27 & 4 )
F_19 ( L_27 , V_66 ,
V_25 , V_4 ) ;
V_48 -> V_95 -> V_154 -> V_194 ( V_48 -> V_95 , V_25 , V_4 ) ;
return V_4 ;
}
static int F_113 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
int V_195 , V_87 , V_196 ;
V_48 -> V_95 = F_114 ( V_95 ) ;
V_48 -> V_40 = F_110 ;
V_195 = F_99 ( V_48 ) ;
if ( V_195 != 0 )
F_44 ( V_48 -> V_95 ) ;
else {
V_196 = V_48 -> V_184 << 6 ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_115 ( V_197 , V_196 + V_87 , NULL ) ;
}
return V_195 ;
}
static void F_116 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
int V_87 ;
int V_196 = V_48 -> V_184 << 6 ;
F_11 ( V_95 != V_48 -> V_95 ) ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_117 ( V_197 , V_196 + V_87 ) ;
F_95 ( V_48 ) ;
F_44 ( V_48 -> V_95 ) ;
V_48 -> V_95 = NULL ;
}
static void F_118 ( struct V_94 * V_95 , const unsigned char * V_198 ,
char * V_199 , int V_168 )
{
struct V_47 * V_48 = V_95 -> V_200 ;
const unsigned char * V_68 ;
char * V_201 ;
int V_87 ;
char V_71 = V_202 ;
if ( V_27 & 4 )
F_19 ( L_28 , V_66 ,
V_198 , V_168 ) ;
for ( V_87 = V_168 , V_68 = V_198 , V_201 = V_199 ; V_87 ; V_87 -- , V_68 ++ ) {
if ( V_201 )
V_71 = * V_201 ++ ;
switch ( V_71 ) {
case V_202 :
V_48 -> V_183 ( V_48 , * V_68 ) ;
break;
case V_112 :
case V_108 :
case V_113 :
case V_114 :
V_48 -> error ( V_48 , * V_68 , V_71 ) ;
break;
default:
F_119 ( 1 , L_29 ,
F_120 ( V_95 ) , V_71 ) ;
break;
}
}
}
static T_3 F_121 ( struct V_94 * V_95 )
{
return 0 ;
}
static void F_122 ( struct V_94 * V_95 )
{
}
static void F_123 ( struct V_94 * V_95 )
{
struct V_47 * V_48 = V_95 -> V_200 ;
F_116 ( V_95 , V_48 ) ;
F_122 ( V_95 ) ;
F_106 ( V_48 ) ;
}
static int F_124 ( struct V_94 * V_95 )
{
struct V_47 * V_48 ;
int V_195 ;
if ( V_95 -> V_154 -> V_194 == NULL )
return - V_203 ;
V_48 = F_108 () ;
if ( V_48 == NULL )
return - V_80 ;
V_95 -> V_200 = V_48 ;
V_95 -> V_204 = 65536 ;
V_48 -> V_51 = 1 ;
V_195 = F_113 ( V_95 , V_48 ) ;
if ( V_195 != 0 ) {
F_95 ( V_48 ) ;
F_106 ( V_48 ) ;
}
return V_195 ;
}
static void F_125 ( struct V_94 * V_95 )
{
struct V_47 * V_48 = V_95 -> V_200 ;
unsigned long V_71 ;
F_126 ( V_192 , & V_95 -> V_71 ) ;
F_25 ( & V_48 -> V_72 , V_71 ) ;
F_17 ( V_48 ) ;
if ( V_48 -> V_67 < V_92 ) {
F_35 ( V_48 ) ;
}
F_26 ( & V_48 -> V_72 , V_71 ) ;
}
static T_3 F_127 ( struct V_94 * V_95 , struct V_205 * V_205 ,
unsigned char T_4 * V_117 , T_5 V_206 )
{
return - V_132 ;
}
static T_3 F_128 ( struct V_94 * V_95 , struct V_205 * V_205 ,
const unsigned char * V_117 , T_5 V_206 )
{
int V_207 = F_111 ( V_95 ) ;
if ( V_207 >= V_206 )
return V_95 -> V_154 -> V_194 ( V_95 , V_117 , V_206 ) ;
F_112 ( V_192 , & V_95 -> V_71 ) ;
return - V_208 ;
}
static unsigned int F_129 ( struct V_94 * V_95 , struct V_205 * V_205 ,
T_6 * V_209 )
{
unsigned int V_210 = 0 ;
struct V_47 * V_48 = V_95 -> V_200 ;
F_130 ( V_205 , & V_95 -> V_211 , V_209 ) ;
F_130 ( V_205 , & V_95 -> V_212 , V_209 ) ;
if ( F_131 ( V_205 ) )
V_210 |= V_213 ;
if ( ! F_132 ( V_95 ) && F_111 ( V_95 ) > 0 )
V_210 |= V_214 | V_215 ;
if ( V_48 -> V_119 )
V_210 |= V_213 ;
return V_210 ;
}
static int F_133 ( struct V_94 * V_95 , struct V_47 * V_48 ,
struct V_216 * V_2 )
{
int V_217 = 0 ;
int V_218 = 0 ;
if ( ( V_2 -> V_76 != 1 && V_2 -> V_76 != 2 ) || V_2 -> V_219 )
return - V_132 ;
if ( V_2 -> V_166 > V_188 || V_2 -> V_78 > V_220 || V_2 -> V_166 < 8 || V_2 -> V_78 < 8 )
return - V_203 ;
if ( V_2 -> V_142 < 3 )
return - V_203 ;
if ( V_2 -> V_221 > 1 )
return - V_203 ;
if ( V_2 -> V_69 > 1 )
return - V_203 ;
if ( V_2 -> V_87 == 0 || V_2 -> V_87 > 2 )
return - V_203 ;
if ( V_2 -> V_144 != 0 && V_2 -> V_144 != V_48 -> V_144 )
V_218 = 1 ;
if ( V_2 -> V_138 != 0 && V_2 -> V_138 != V_48 -> V_138 )
V_218 = 1 ;
if ( V_2 -> V_221 != V_48 -> V_51 )
V_218 = 1 ;
if ( V_2 -> V_76 != V_48 -> V_76 )
V_218 = 1 ;
if ( V_2 -> V_69 != V_48 -> V_69 )
V_217 = 1 ;
if ( V_2 -> V_166 != V_48 -> V_166 )
V_218 = 1 ;
if ( V_2 -> V_78 != V_48 -> V_78 )
V_218 = 1 ;
if ( V_217 || V_218 ) {
F_48 ( V_48 -> V_8 [ 0 ] ) ;
F_98 ( V_48 -> V_134 ,
V_48 -> V_8 [ 0 ] -> V_145 == V_146 ) ;
if ( F_134 ( V_222 ) )
return - V_223 ;
}
if ( V_218 )
F_95 ( V_48 ) ;
V_48 -> V_69 = V_2 -> V_69 ;
V_48 -> V_166 = V_2 -> V_166 ;
V_48 -> V_78 = V_2 -> V_78 ;
V_48 -> V_51 = V_2 -> V_221 ;
V_48 -> V_76 = V_2 -> V_76 ;
V_48 -> V_142 = V_2 -> V_142 ;
if ( V_2 -> V_87 == 1 )
V_48 -> V_79 = V_34 ;
else if ( V_2 -> V_87 == 2 )
V_48 -> V_79 = V_33 ;
if ( V_2 -> V_144 )
V_48 -> V_144 = V_2 -> V_144 ;
if ( V_2 -> V_138 )
V_48 -> V_138 = V_2 -> V_138 ;
if ( V_218 )
F_99 ( V_48 ) ;
if ( V_48 -> V_69 && V_217 )
F_64 ( V_48 -> V_8 [ 0 ] ) ;
return 0 ;
}
static int F_135 ( struct V_94 * V_95 , struct V_205 * V_205 ,
unsigned int V_93 , unsigned long V_224 )
{
struct V_216 V_2 ;
struct V_47 * V_48 = V_95 -> V_200 ;
switch ( V_93 ) {
case V_225 :
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_76 = V_48 -> V_76 ;
V_2 . V_221 = V_48 -> V_51 ;
V_2 . V_69 = V_48 -> V_69 ;
V_2 . V_144 = V_48 -> V_144 ;
V_2 . V_138 = V_48 -> V_138 ;
V_2 . V_226 = 0 ;
V_2 . V_142 = V_48 -> V_142 ;
if ( V_48 -> V_79 == V_34 )
V_2 . V_87 = 1 ;
else
V_2 . V_87 = 2 ;
F_8 ( L_30 , V_48 -> V_79 , V_2 . V_87 ) ;
V_2 . V_166 = V_48 -> V_166 ;
V_2 . V_78 = V_48 -> V_78 ;
V_2 . V_219 = 0 ;
if ( F_136 ( ( void * ) V_224 , & V_2 , sizeof( V_2 ) ) )
return - V_227 ;
return 0 ;
case V_228 :
if ( F_137 ( & V_2 , ( void * ) V_224 , sizeof( V_2 ) ) )
return - V_227 ;
return F_133 ( V_95 , V_48 , & V_2 ) ;
default:
return F_138 ( V_95 , V_205 , V_93 , V_224 ) ;
}
}
static int F_139 ( struct V_229 * V_90 )
{
F_8 ( L_31 , V_230 ) ;
F_140 ( V_90 ) ;
return 0 ;
}
static int F_141 ( struct V_229 * V_90 )
{
F_142 ( V_90 ) ;
return 0 ;
}
static struct V_231 * F_143 ( struct V_229 * V_90 )
{
return & ( (struct V_232 * ) F_144 ( V_90 ) ) -> V_233 ;
}
static void F_145 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_90 ) {
F_11 ( 1 ) ;
return;
}
V_8 -> V_76 = V_8 -> V_234 ;
V_8 -> V_25 = V_8 -> V_235 ;
F_146 ( V_8 -> V_90 ) ;
V_8 -> V_90 = NULL ;
}
static void F_147 ( struct V_186 * V_187 )
{
struct V_232 * V_236 ;
struct V_7 * V_8 ;
V_236 = F_76 ( V_187 , struct V_232 , V_187 ) ;
V_8 = V_236 -> V_8 ;
if ( V_8 -> V_90 ) {
F_148 ( V_8 -> V_90 ) ;
F_145 ( V_8 ) ;
}
}
static inline void F_149 ( struct V_232 * V_236 )
{
F_105 ( & V_236 -> V_187 ) ;
}
static inline void F_150 ( struct V_232 * V_236 )
{
F_107 ( & V_236 -> V_187 , F_147 ) ;
}
static int F_151 ( struct V_237 * V_85 ,
struct V_229 * V_90 )
{
struct V_232 * V_236 = F_144 ( V_90 ) ;
struct V_7 * V_8 = V_236 -> V_8 ;
F_149 ( V_236 ) ;
F_152 ( & V_8 -> V_86 , V_85 ) ;
F_153 ( V_90 ) . V_238 ++ ;
F_153 ( V_90 ) . V_67 += V_85 -> V_4 ;
F_36 ( V_8 ) ;
V_90 -> V_239 = V_137 ;
F_150 ( V_236 ) ;
return V_240 ;
}
static void F_154 ( struct V_229 * V_90 )
{
F_155 ( & V_90 -> V_241 , L_32 ) ;
F_153 ( V_90 ) . V_242 ++ ;
}
static void F_156 ( struct V_7 * V_8 ,
unsigned char * V_243 , int V_74 )
{
struct V_229 * V_90 = V_8 -> V_90 ;
struct V_237 * V_85 ;
struct V_232 * V_236 = F_144 ( V_90 ) ;
F_149 ( V_236 ) ;
V_85 = F_157 ( V_74 + V_244 ) ;
if ( ! V_85 ) {
F_153 ( V_90 ) . V_245 ++ ;
F_150 ( V_236 ) ;
return;
}
F_158 ( V_85 , V_244 ) ;
memcpy ( F_159 ( V_85 , V_74 ) , V_243 , V_74 ) ;
V_85 -> V_241 = V_90 ;
V_85 -> V_246 = F_160 ( V_247 ) ;
F_161 ( V_85 ) ;
F_153 ( V_90 ) . V_248 ++ ;
F_153 ( V_90 ) . V_249 += V_74 ;
F_150 ( V_236 ) ;
return;
}
static int F_162 ( struct V_229 * V_90 , int V_250 )
{
struct V_232 * V_236 = F_144 ( V_90 ) ;
if ( ( V_250 < 8 ) || ( V_250 > V_236 -> V_8 -> V_48 -> V_78 ) )
return - V_203 ;
V_90 -> V_78 = V_250 ;
return 0 ;
}
static void F_163 ( struct V_229 * V_90 )
{
static const struct V_251 V_252 = {
. V_253 = F_139 ,
. V_254 = F_141 ,
. V_255 = F_151 ,
. V_256 = F_154 ,
. V_257 = F_143 ,
. V_258 = F_162 ,
} ;
V_90 -> V_259 = & V_252 ;
V_90 -> V_260 = V_261 ;
V_90 -> V_71 = V_262 | V_263 | V_264 ;
V_90 -> type = V_265 ;
V_90 -> V_266 = 10 ;
}
static void F_87 ( struct V_7 * V_8 )
{
struct V_232 * V_236 ;
F_8 ( L_33 ) ;
if ( ! V_8 -> V_90 )
return;
V_236 = F_144 ( V_8 -> V_90 ) ;
F_150 ( V_236 ) ;
}
static int F_164 ( struct V_7 * V_8 , struct V_267 * V_268 )
{
char * V_269 ;
int V_270 = 0 ;
struct V_229 * V_90 ;
struct V_232 * V_236 ;
if ( ! F_165 ( V_271 ) )
return - V_272 ;
if ( V_8 -> V_76 > 2 )
return - V_185 ;
if ( V_268 -> V_246 != F_166 ( V_247 ) )
return - V_273 ;
if ( V_268 -> V_76 != 3 && V_268 -> V_76 != 4 )
return - V_273 ;
F_8 ( L_34 ) ;
V_269 = L_35 ;
if ( V_268 -> V_274 [ 0 ] != '\0' )
V_269 = V_268 -> V_274 ;
V_90 = F_167 ( sizeof( struct V_232 ) , V_269 ,
V_275 , F_163 ) ;
if ( ! V_90 ) {
F_168 ( L_36 ) ;
return - V_80 ;
}
V_90 -> V_78 = V_8 -> V_48 -> V_78 ;
V_236 = F_144 ( V_90 ) ;
V_236 -> V_8 = V_8 ;
F_109 ( & V_236 -> V_187 ) ;
strncpy ( V_268 -> V_274 , V_90 -> V_276 , V_277 ) ;
V_8 -> V_234 = V_8 -> V_76 ;
V_8 -> V_235 = V_8 -> V_25 ;
V_8 -> V_76 = V_268 -> V_76 ;
V_8 -> V_25 = F_156 ;
V_8 -> V_90 = V_90 ;
F_8 ( L_37 ) ;
V_270 = F_169 ( V_90 ) ;
if ( V_270 ) {
F_168 ( L_38 , V_270 ) ;
F_145 ( V_8 ) ;
return V_270 ;
}
return V_90 -> V_278 ;
}
static int F_170 ( struct V_7 * V_8 , T_1 V_99 )
{
T_1 V_9 [ 5 ] ;
struct V_128 * V_55 ;
int V_4 = 2 ;
if ( V_99 )
V_4 ++ ;
V_9 [ 0 ] = V_4 << 1 | V_6 ;
V_9 [ 1 ] = V_8 -> V_22 << 2 | 3 ;
V_9 [ 2 ] = F_4 ( V_8 ) << 1 | V_6 ;
if ( V_99 )
V_9 [ 3 ] = V_99 << 4 | 2 | V_6 ;
V_55 = F_55 ( V_8 -> V_48 , V_109 , V_9 , V_4 + 1 ) ;
if ( V_55 == NULL )
return - V_80 ;
return F_58 ( V_8 -> V_48 , V_55 ) ;
}
static int F_171 ( struct V_110 * V_107 )
{
struct V_7 * V_8 = F_76 ( V_107 , struct V_7 , V_107 ) ;
if ( V_8 -> V_145 != V_147 )
return 0 ;
if ( V_27 & 2 )
return 1 ;
return V_8 -> V_103 & V_19 ;
}
static void F_172 ( struct V_110 * V_107 , int V_279 )
{
struct V_7 * V_8 = F_76 ( V_107 , struct V_7 , V_107 ) ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_279 )
V_12 |= V_13 | V_15 ;
else
V_12 &= ~ ( V_13 | V_15 ) ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
F_170 ( V_8 , 0 ) ;
}
}
static int F_173 ( struct V_280 * V_281 , struct V_94 * V_95 )
{
struct V_47 * V_48 ;
struct V_7 * V_8 ;
unsigned int line = V_95 -> V_282 ;
unsigned int V_283 = line >> 6 ;
bool V_284 = false ;
int V_195 ;
line = line & 0x3F ;
if ( V_283 >= V_182 )
return - V_285 ;
if ( V_47 [ V_283 ] == NULL )
return - V_286 ;
if ( line == 0 || line > 61 )
return - V_287 ;
V_48 = V_47 [ V_283 ] ;
if ( V_48 -> V_119 )
return - V_288 ;
F_86 ( & V_48 -> V_151 ) ;
if ( V_48 -> V_8 [ 0 ] && V_48 -> V_8 [ 0 ] -> V_145 != V_147 ) {
F_88 ( & V_48 -> V_151 ) ;
return - V_289 ;
}
V_8 = V_48 -> V_8 [ line ] ;
if ( V_8 == NULL ) {
V_284 = true ;
V_8 = F_68 ( V_48 , line ) ;
}
if ( V_8 == NULL ) {
F_88 ( & V_48 -> V_151 ) ;
return - V_80 ;
}
V_195 = F_174 ( & V_8 -> V_107 , V_281 , V_95 ) ;
if ( V_195 ) {
if ( V_284 )
F_83 ( V_8 ) ;
F_88 ( & V_48 -> V_151 ) ;
return V_195 ;
}
F_81 ( V_8 ) ;
F_81 ( V_48 -> V_8 [ 0 ] ) ;
F_104 ( V_48 ) ;
V_95 -> V_290 = V_8 ;
F_88 ( & V_48 -> V_151 ) ;
return 0 ;
}
static int F_175 ( struct V_94 * V_95 , struct V_205 * V_291 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
struct V_110 * V_107 = & V_8 -> V_107 ;
V_107 -> V_168 ++ ;
F_90 ( V_107 , V_95 ) ;
V_8 -> V_103 = 0 ;
F_112 ( V_292 , & V_107 -> V_71 ) ;
F_64 ( V_8 ) ;
return F_176 ( V_107 , V_95 , V_291 ) ;
}
static void F_177 ( struct V_94 * V_95 , struct V_205 * V_291 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
struct V_47 * V_48 ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_145 == V_146 )
return;
F_86 ( & V_8 -> V_151 ) ;
F_87 ( V_8 ) ;
F_88 ( & V_8 -> V_151 ) ;
V_48 = V_8 -> V_48 ;
if ( F_178 ( & V_8 -> V_107 , V_95 , V_291 ) == 0 )
return;
F_48 ( V_8 ) ;
if ( F_179 ( V_292 , & V_8 -> V_107 . V_71 ) ) {
if ( F_180 ( V_95 ) )
F_181 ( & V_8 -> V_107 ) ;
}
F_182 ( & V_8 -> V_107 , V_95 ) ;
F_90 ( & V_8 -> V_107 , NULL ) ;
return;
}
static void F_183 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return;
F_184 ( & V_8 -> V_107 ) ;
F_48 ( V_8 ) ;
}
static int F_185 ( struct V_94 * V_95 , const unsigned char * V_117 ,
int V_4 )
{
int V_293 ;
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
V_293 = F_186 ( V_8 -> V_77 , V_117 , V_4 , & V_8 -> V_81 ) ;
F_36 ( V_8 ) ;
return V_293 ;
}
static int F_187 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
return V_294 - F_28 ( V_8 -> V_77 ) ;
}
static int F_188 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
return F_28 ( V_8 -> V_77 ) ;
}
static void F_189 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return;
F_61 ( V_8 -> V_77 ) ;
}
static void F_190 ( struct V_94 * V_95 , int V_295 )
{
}
static int F_191 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
return V_8 -> V_103 ;
}
static int F_192 ( struct V_94 * V_95 ,
unsigned int V_296 , unsigned int V_297 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
V_12 &= ~ V_297 ;
V_12 |= V_296 ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
return F_170 ( V_8 , 0 ) ;
}
return 0 ;
}
static int F_193 ( struct V_94 * V_95 ,
unsigned int V_93 , unsigned long V_224 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
struct V_267 V_268 ;
int V_282 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
switch ( V_93 ) {
case V_298 :
if ( F_137 ( & V_268 , ( void T_4 * ) V_224 , sizeof( V_268 ) ) )
return - V_227 ;
V_268 . V_274 [ V_277 - 1 ] = '\0' ;
F_86 ( & V_8 -> V_151 ) ;
V_282 = F_164 ( V_8 , & V_268 ) ;
F_88 ( & V_8 -> V_151 ) ;
if ( F_136 ( ( void T_4 * ) V_224 , & V_268 , sizeof( V_268 ) ) )
return - V_227 ;
return V_282 ;
case V_299 :
if ( ! F_165 ( V_271 ) )
return - V_272 ;
F_86 ( & V_8 -> V_151 ) ;
F_87 ( V_8 ) ;
F_88 ( & V_8 -> V_151 ) ;
return 0 ;
default:
return - V_300 ;
}
}
static void F_194 ( struct V_94 * V_95 , struct V_301 * V_302 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return;
F_195 ( & V_95 -> V_104 , V_302 ) ;
}
static void F_196 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return;
if ( V_95 -> V_104 . V_105 & V_303 )
V_8 -> V_12 &= ~ V_13 ;
V_8 -> V_10 = 1 ;
F_170 ( V_8 , 0 ) ;
}
static void F_197 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
if ( V_8 -> V_145 == V_146 )
return;
if ( V_95 -> V_104 . V_105 & V_303 )
V_8 -> V_12 |= V_13 ;
V_8 -> V_10 = 0 ;
F_170 ( V_8 , 0 ) ;
}
static int F_198 ( struct V_94 * V_95 , int V_145 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
int V_304 = 0 ;
if ( V_8 -> V_145 == V_146 )
return - V_203 ;
if ( V_145 == - 1 )
V_304 = 0x0F ;
else if ( V_145 > 0 ) {
V_304 = V_145 / 200 ;
if ( V_304 > 0x0F )
V_304 = 0x0F ;
}
return F_170 ( V_8 , V_304 ) ;
}
static void F_199 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_290 ;
struct V_47 * V_48 = V_8 -> V_48 ;
F_83 ( V_8 ) ;
F_83 ( V_48 -> V_8 [ 0 ] ) ;
F_106 ( V_48 ) ;
}
static int T_7 F_200 ( void )
{
int V_305 = F_201 ( V_306 , & V_307 ) ;
if ( V_305 != 0 ) {
F_168 ( L_39 ,
V_305 ) ;
return V_305 ;
}
V_197 = F_202 ( 256 ) ;
if ( ! V_197 ) {
F_203 ( V_306 ) ;
F_168 ( L_40 ) ;
return - V_203 ;
}
V_197 -> V_308 = L_41 ;
V_197 -> V_276 = L_41 ;
V_197 -> V_309 = 0 ;
V_197 -> V_310 = 0 ;
V_197 -> type = V_311 ;
V_197 -> V_312 = V_313 ;
V_197 -> V_71 = V_314 | V_315
| V_316 ;
V_197 -> V_317 = V_318 ;
V_197 -> V_317 . V_319 &= ~ V_320 ;
F_204 ( V_197 , & V_321 ) ;
F_69 ( & V_181 ) ;
if ( F_205 ( V_197 ) ) {
F_206 ( V_197 ) ;
F_203 ( V_306 ) ;
F_168 ( L_42 ) ;
return - V_185 ;
}
F_8 ( L_43 ,
V_197 -> V_309 , V_197 -> V_310 ) ;
return 0 ;
}
static void T_8 F_207 ( void )
{
int V_305 = F_203 ( V_306 ) ;
if ( V_305 != 0 )
F_168 ( L_44 ,
V_305 ) ;
F_208 ( V_197 ) ;
F_206 ( V_197 ) ;
}
