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
if ( ! F_39 ( V_95 ) )
F_40 ( V_95 ) ;
}
if ( V_99 & 0x01 )
F_41 ( & V_8 -> V_104 , 0 , V_105 ) ;
V_8 -> V_103 = V_98 ;
}
static void F_42 ( struct V_47 * V_48 , T_1 * V_25 , int V_97 )
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
V_95 = F_43 ( & V_8 -> V_104 ) ;
F_38 ( V_95 , V_8 , V_96 , V_97 ) ;
if ( V_95 ) {
F_44 ( V_95 ) ;
F_45 ( V_95 ) ;
}
F_37 ( V_48 , V_106 , V_25 , V_97 ) ;
}
static void F_46 ( struct V_47 * V_48 , T_1 * V_25 , int V_97 )
{
struct V_107 * V_104 ;
unsigned int V_22 = 0 ;
T_1 V_108 ;
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
V_108 = * V_68 ;
if ( ( V_108 & 1 ) == 0 )
return;
V_104 = & V_48 -> V_8 [ V_22 ] -> V_104 ;
if ( V_108 & 2 )
F_41 ( V_104 , 0 , V_109 ) ;
if ( V_108 & 4 )
F_41 ( V_104 , 0 , V_110 ) ;
if ( V_108 & 8 )
F_41 ( V_104 , 0 , V_111 ) ;
F_47 ( V_104 ) ;
F_37 ( V_48 , V_112 , V_25 , V_97 ) ;
}
static void F_48 ( struct V_47 * V_48 , unsigned int V_113 ,
T_1 * V_25 , int V_97 )
{
T_1 V_114 [ 1 ] ;
unsigned long V_71 ;
switch ( V_113 ) {
case V_115 : {
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
if ( V_8 ) {
V_8 -> V_116 = 1 ;
V_48 -> V_116 = 1 ;
F_49 ( V_8 ) ;
}
}
break;
case V_117 :
F_37 ( V_48 , V_117 , V_25 , V_97 ) ;
break;
case V_118 :
V_48 -> V_64 = 0 ;
F_37 ( V_48 , V_118 , NULL , 0 ) ;
F_25 ( & V_48 -> V_72 , V_71 ) ;
F_17 ( V_48 ) ;
F_26 ( & V_48 -> V_72 , V_71 ) ;
break;
case V_119 :
V_48 -> V_64 = 1 ;
F_37 ( V_48 , V_119 , NULL , 0 ) ;
break;
case V_106 :
F_42 ( V_48 , V_25 , V_97 ) ;
break;
case V_112 :
F_46 ( V_48 , V_25 , V_97 ) ;
break;
case V_120 :
F_37 ( V_48 , V_120 , NULL , 0 ) ;
break;
case V_121 :
case V_122 :
case V_123 :
default:
V_114 [ 0 ] = V_113 ;
F_37 ( V_48 , V_124 , V_114 , 1 ) ;
break;
}
}
static void F_50 ( struct V_47 * V_48 , unsigned int V_113 ,
T_1 * V_25 , int V_97 )
{
struct V_125 * V_55 ;
unsigned long V_71 ;
F_25 ( & V_48 -> V_126 , V_71 ) ;
V_55 = V_48 -> V_127 ;
V_113 |= 1 ;
if ( V_55 != NULL && ( V_113 == V_55 -> V_93 || V_113 == V_124 ) ) {
F_51 ( & V_48 -> V_128 ) ;
V_48 -> V_127 = NULL ;
if ( V_113 == V_124 )
V_55 -> error = - V_129 ;
V_55 -> V_130 = 1 ;
F_52 ( & V_48 -> V_131 ) ;
}
F_26 ( & V_48 -> V_126 , V_71 ) ;
}
static void F_53 ( struct V_47 * V_48 , struct V_125 * V_55 )
{
struct V_54 * V_61 = F_14 ( V_48 , 0 , V_55 -> V_4 + 1 , V_48 -> V_79 ) ;
if ( V_61 == NULL )
return;
V_61 -> V_25 [ 0 ] = ( V_55 -> V_93 << 1 ) | 2 | V_6 ;
memcpy ( V_61 -> V_25 + 1 , V_55 -> V_25 , V_55 -> V_4 ) ;
F_24 ( V_48 -> V_8 [ 0 ] , V_61 ) ;
}
static void F_54 ( unsigned long V_25 )
{
struct V_47 * V_48 = (struct V_47 * ) V_25 ;
struct V_125 * V_55 ;
unsigned long V_71 ;
F_25 ( & V_48 -> V_126 , V_71 ) ;
V_55 = V_48 -> V_127 ;
if ( V_55 ) {
V_48 -> V_132 -- ;
if ( V_48 -> V_132 == 0 ) {
V_48 -> V_127 = NULL ;
V_55 -> error = - V_133 ;
V_55 -> V_130 = 1 ;
F_26 ( & V_48 -> V_126 , V_71 ) ;
F_52 ( & V_48 -> V_131 ) ;
return;
}
F_53 ( V_48 , V_55 ) ;
F_55 ( & V_48 -> V_128 , V_134 + V_48 -> V_135 * V_136 / 100 ) ;
}
F_26 ( & V_48 -> V_126 , V_71 ) ;
}
static struct V_125 * F_56 ( struct V_47 * V_48 ,
unsigned int V_113 , T_1 * V_25 , int V_97 )
{
struct V_125 * V_55 = F_57 ( sizeof( struct V_125 ) ,
V_137 ) ;
unsigned long V_71 ;
if ( V_55 == NULL )
return NULL ;
V_138:
F_58 ( V_48 -> V_131 , V_48 -> V_127 == NULL ) ;
F_25 ( & V_48 -> V_126 , V_71 ) ;
if ( V_48 -> V_127 != NULL ) {
F_26 ( & V_48 -> V_126 , V_71 ) ;
goto V_138;
}
V_55 -> V_93 = V_113 ;
V_55 -> V_25 = V_25 ;
V_55 -> V_4 = V_97 ;
V_48 -> V_127 = V_55 ;
V_48 -> V_132 = V_48 -> V_139 ;
F_55 ( & V_48 -> V_128 , V_134 + V_48 -> V_135 * V_136 / 100 ) ;
F_53 ( V_48 , V_55 ) ;
F_26 ( & V_48 -> V_126 , V_71 ) ;
return V_55 ;
}
static int F_59 ( struct V_47 * V_48 , struct V_125 * V_24 )
{
int V_140 ;
F_58 ( V_48 -> V_131 , V_24 -> V_130 == 1 ) ;
V_140 = V_24 -> error ;
F_21 ( V_24 ) ;
return V_140 ;
}
static void F_60 ( struct V_7 * V_8 )
{
F_51 ( & V_8 -> V_141 ) ;
if ( V_27 & 8 )
F_8 ( L_22 , V_8 -> V_22 ) ;
V_8 -> V_142 = V_143 ;
if ( V_8 -> V_22 != 0 ) {
F_61 ( & V_8 -> V_104 , false ) ;
F_62 ( V_8 -> V_77 ) ;
} else
V_8 -> V_48 -> V_116 = 1 ;
F_52 ( & V_8 -> V_48 -> V_131 ) ;
}
static void F_63 ( struct V_7 * V_8 )
{
F_51 ( & V_8 -> V_141 ) ;
V_8 -> V_142 = V_144 ;
if ( V_27 & 8 )
F_8 ( L_23 , V_8 -> V_22 ) ;
F_52 ( & V_8 -> V_48 -> V_131 ) ;
}
static void F_64 ( unsigned long V_25 )
{
struct V_7 * V_8 = (struct V_7 * ) V_25 ;
struct V_47 * V_48 = V_8 -> V_48 ;
switch ( V_8 -> V_142 ) {
case V_145 :
V_8 -> V_146 -- ;
if ( V_8 -> V_146 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_55 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
} else
F_60 ( V_8 ) ;
break;
case V_147 :
V_8 -> V_146 -- ;
if ( V_8 -> V_146 ) {
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_55 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
} else
F_60 ( V_8 ) ;
break;
}
}
static void F_65 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_142 == V_144 || V_8 -> V_142 == V_145 )
return;
V_8 -> V_146 = V_48 -> V_139 ;
V_8 -> V_142 = V_145 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_29 | V_28 ) ;
F_55 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
}
static void F_49 ( struct V_7 * V_8 )
{
struct V_47 * V_48 = V_8 -> V_48 ;
if ( V_8 -> V_142 == V_143 || V_8 -> V_142 == V_147 )
return;
V_8 -> V_146 = V_48 -> V_139 ;
V_8 -> V_142 = V_147 ;
F_13 ( V_8 -> V_48 , V_8 -> V_22 , V_31 | V_28 ) ;
F_55 ( & V_8 -> V_141 , V_134 + V_48 -> V_141 * V_136 / 100 ) ;
}
static void F_66 ( struct V_7 * V_8 , T_1 * V_25 , int V_97 )
{
struct V_107 * V_104 = & V_8 -> V_104 ;
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
V_95 = F_43 ( V_104 ) ;
if ( V_95 ) {
F_38 ( V_95 , V_8 , V_96 , V_97 ) ;
F_45 ( V_95 ) ;
}
case 1 :
default:
F_67 ( V_104 , V_25 , V_4 ) ;
F_47 ( V_104 ) ;
}
}
static void F_68 ( struct V_7 * V_8 , T_1 * V_25 , int V_4 )
{
unsigned int V_113 = 0 ;
while ( V_4 -- > 0 ) {
if ( F_3 ( & V_113 , * V_25 ++ ) == 1 ) {
int V_97 = * V_25 ++ ;
V_4 -- ;
V_97 >>= 1 ;
if ( V_97 > V_4 )
return;
if ( V_113 & 1 )
F_48 ( V_8 -> V_48 , V_113 ,
V_25 , V_97 ) ;
else
F_50 ( V_8 -> V_48 , V_113 ,
V_25 , V_97 ) ;
return;
}
}
}
static struct V_7 * F_69 ( struct V_47 * V_48 , int V_22 )
{
struct V_7 * V_8 = F_57 ( sizeof( struct V_7 ) , V_58 ) ;
if ( V_8 == NULL )
return NULL ;
F_70 ( & V_8 -> V_81 ) ;
F_71 ( & V_8 -> V_148 ) ;
V_8 -> V_77 = & V_8 -> V_149 ;
if ( F_72 ( & V_8 -> V_149 , 4096 , V_137 ) < 0 ) {
F_21 ( V_8 ) ;
return NULL ;
}
F_73 ( & V_8 -> V_86 ) ;
F_74 ( & V_8 -> V_141 ) ;
V_8 -> V_141 . V_150 = F_64 ;
V_8 -> V_141 . V_25 = ( unsigned long ) V_8 ;
F_75 ( & V_8 -> V_104 ) ;
V_8 -> V_104 . V_151 = & V_152 ;
V_8 -> V_48 = V_48 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_76 = V_48 -> V_76 ;
V_8 -> V_142 = V_143 ;
if ( V_22 )
V_8 -> V_25 = F_66 ;
else
V_8 -> V_25 = F_68 ;
V_48 -> V_8 [ V_22 ] = V_8 ;
return V_8 ;
}
static void F_76 ( struct V_107 * V_104 )
{
struct V_7 * V_8 = F_77 ( V_104 , struct V_7 , V_104 ) ;
F_78 ( & V_8 -> V_141 ) ;
V_8 -> V_48 -> V_8 [ V_8 -> V_22 ] = NULL ;
F_79 ( V_8 -> V_77 ) ;
while ( ( V_8 -> V_85 = F_80 ( & V_8 -> V_86 ) ) )
F_81 ( V_8 -> V_85 ) ;
F_21 ( V_8 ) ;
}
static inline void F_82 ( struct V_7 * V_8 )
{
F_83 ( & V_8 -> V_104 ) ;
}
static inline void F_84 ( struct V_7 * V_8 )
{
F_85 ( & V_8 -> V_104 ) ;
}
static void F_86 ( struct V_7 * V_8 )
{
struct V_94 * V_95 = F_43 ( & V_8 -> V_104 ) ;
if ( V_95 ) {
F_87 ( & V_8 -> V_148 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_148 ) ;
F_90 ( V_95 ) ;
F_91 ( & V_8 -> V_104 , NULL ) ;
F_45 ( V_95 ) ;
}
V_8 -> V_142 = V_143 ;
F_84 ( V_8 ) ;
}
static void F_92 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
T_1 V_23 ;
int V_153 ;
if ( ( V_48 -> V_24 & ~ V_28 ) == V_33 )
V_48 -> V_1 = F_2 ( V_48 -> V_1 , V_48 -> V_114 , V_48 -> V_4 ) ;
if ( V_48 -> V_51 == 0 ) {
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_154 ) ;
}
if ( V_48 -> V_1 != V_155 ) {
V_48 -> V_156 ++ ;
if ( V_27 & 4 )
F_8 ( L_25 , V_48 -> V_1 ) ;
return;
}
V_153 = V_48 -> V_153 >> 1 ;
if ( V_153 >= V_88 )
goto V_157;
V_23 = V_48 -> V_153 & 1 ;
F_5 ( L_26 , V_153 , V_23 , V_48 -> V_24 , V_48 -> V_114 , V_48 -> V_4 ) ;
V_23 ^= 1 - V_48 -> V_69 ;
V_8 = V_48 -> V_8 [ V_153 ] ;
switch ( V_48 -> V_24 ) {
case V_29 | V_28 :
if ( V_23 == 0 )
goto V_157;
if ( V_8 == NULL )
V_8 = F_69 ( V_48 , V_153 ) ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_116 )
F_12 ( V_48 , V_153 , V_32 ) ;
else {
F_12 ( V_48 , V_153 , V_30 ) ;
F_63 ( V_8 ) ;
}
break;
case V_31 | V_28 :
if ( V_23 == 0 )
goto V_157;
if ( V_8 == NULL || V_8 -> V_142 == V_143 ) {
F_12 ( V_48 , V_153 , V_32 ) ;
return;
}
F_12 ( V_48 , V_153 , V_30 ) ;
F_60 ( V_8 ) ;
break;
case V_30 :
case V_30 | V_28 :
if ( V_23 == 0 || V_8 == NULL )
break;
switch ( V_8 -> V_142 ) {
case V_147 :
F_60 ( V_8 ) ;
break;
case V_145 :
F_63 ( V_8 ) ;
break;
}
break;
case V_32 :
case V_32 | V_28 :
if ( V_23 )
goto V_157;
if ( V_8 == NULL )
return;
F_60 ( V_8 ) ;
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
F_13 ( V_48 , V_153 , V_32 | V_28 ) ;
return;
}
V_8 -> V_25 ( V_8 , V_48 -> V_114 , V_48 -> V_4 ) ;
break;
default:
goto V_157;
}
return;
V_157:
V_48 -> V_158 ++ ;
return;
}
static void F_93 ( struct V_47 * V_48 , unsigned char V_2 )
{
unsigned int V_4 ;
switch ( V_48 -> V_142 ) {
case V_159 :
if ( V_2 == V_52 ) {
V_48 -> V_142 = V_160 ;
V_48 -> V_153 = 0 ;
V_48 -> V_4 = 0 ;
V_48 -> V_1 = V_53 ;
}
break;
case V_160 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_153 , V_2 ) )
V_48 -> V_142 = V_161 ;
break;
case V_161 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_142 = V_162 ;
break;
case V_162 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_4 , V_2 ) ) {
if ( V_48 -> V_4 > V_48 -> V_163 ) {
V_48 -> V_164 ++ ;
V_48 -> V_142 = V_159 ;
break;
}
V_48 -> V_165 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_142 = V_166 ;
else
V_48 -> V_142 = V_167 ;
break;
}
V_48 -> V_142 = V_168 ;
break;
case V_168 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_4 = V_2 ;
V_48 -> V_4 |= V_4 << 7 ;
if ( V_48 -> V_4 > V_48 -> V_163 ) {
V_48 -> V_164 ++ ;
V_48 -> V_142 = V_159 ;
break;
}
V_48 -> V_165 = 0 ;
if ( ! V_48 -> V_4 )
V_48 -> V_142 = V_166 ;
else
V_48 -> V_142 = V_167 ;
break;
case V_167 :
V_48 -> V_114 [ V_48 -> V_165 ++ ] = V_2 ;
if ( V_48 -> V_165 == V_48 -> V_4 )
V_48 -> V_142 = V_166 ;
break;
case V_166 :
V_48 -> V_154 = V_2 ;
F_92 ( V_48 ) ;
V_48 -> V_142 = V_169 ;
break;
case V_169 :
if ( V_2 == V_52 ) {
V_48 -> V_142 = V_159 ;
break;
}
break;
}
}
static void F_94 ( struct V_47 * V_48 , unsigned char V_2 )
{
if ( V_2 == V_42 ) {
if ( V_48 -> V_142 == V_167 && V_48 -> V_165 ) {
V_48 -> V_165 -- ;
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_48 -> V_114 [ V_48 -> V_165 ] ) ;
V_48 -> V_4 = V_48 -> V_165 ;
F_92 ( V_48 ) ;
V_48 -> V_142 = V_170 ;
return;
}
if ( V_48 -> V_142 != V_170 ) {
V_48 -> V_158 ++ ;
V_48 -> V_142 = V_170 ;
}
return;
}
if ( V_2 == V_43 ) {
V_48 -> V_171 = 1 ;
return;
}
if ( V_48 -> V_142 == V_159 )
return;
if ( V_48 -> V_171 ) {
V_2 ^= V_46 ;
V_48 -> V_171 = 0 ;
}
switch ( V_48 -> V_142 ) {
case V_170 :
V_48 -> V_153 = 0 ;
V_48 -> V_142 = V_160 ;
V_48 -> V_1 = V_53 ;
case V_160 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
if ( F_3 ( & V_48 -> V_153 , V_2 ) )
V_48 -> V_142 = V_161 ;
break;
case V_161 :
V_48 -> V_1 = F_1 ( V_48 -> V_1 , V_2 ) ;
V_48 -> V_24 = V_2 ;
V_48 -> V_165 = 0 ;
V_48 -> V_142 = V_167 ;
break;
case V_167 :
if ( V_48 -> V_165 > V_48 -> V_163 ) {
V_48 -> V_142 = V_172 ;
V_48 -> V_164 ++ ;
} else
V_48 -> V_114 [ V_48 -> V_165 ++ ] = V_2 ;
break;
case V_172 :
break;
}
}
static void F_95 ( struct V_47 * V_48 ,
unsigned char V_25 , unsigned char V_173 )
{
V_48 -> V_142 = V_159 ;
V_48 -> V_174 ++ ;
}
static void F_96 ( struct V_47 * V_48 )
{
int V_87 ;
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_54 * V_175 , * V_176 ;
struct V_125 * V_177 ;
V_48 -> V_116 = 1 ;
F_97 ( & V_178 ) ;
for ( V_87 = 0 ; V_87 < V_179 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == V_48 ) {
V_47 [ V_87 ] = NULL ;
break;
}
}
F_98 ( & V_178 ) ;
if ( V_87 == V_179 )
return;
if ( V_8 ) {
V_177 = F_56 ( V_48 , V_115 , NULL , 0 ) ;
if ( V_177 )
F_59 ( V_48 , V_177 ) ;
}
F_78 ( & V_48 -> V_128 ) ;
if ( V_8 ) {
V_8 -> V_116 = 1 ;
F_49 ( V_8 ) ;
F_99 ( V_48 -> V_131 ,
V_8 -> V_142 == V_143 ) ;
}
F_87 ( & V_48 -> V_148 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
if ( V_48 -> V_8 [ V_87 ] )
F_86 ( V_48 -> V_8 [ V_87 ] ) ;
F_89 ( & V_48 -> V_148 ) ;
F_18 (txq, ntxq, &gsm->tx_list, list)
F_21 ( V_175 ) ;
F_16 ( & V_48 -> V_70 ) ;
}
static int F_100 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_87 = 0 ;
F_101 ( & V_48 -> V_128 , F_54 , ( unsigned long ) V_48 ) ;
F_102 ( & V_48 -> V_131 ) ;
F_70 ( & V_48 -> V_126 ) ;
F_70 ( & V_48 -> V_72 ) ;
if ( V_48 -> V_51 == 0 )
V_48 -> V_180 = F_93 ;
else
V_48 -> V_180 = F_94 ;
V_48 -> error = F_95 ;
F_97 ( & V_178 ) ;
for ( V_87 = 0 ; V_87 < V_179 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == NULL ) {
V_48 -> V_181 = V_87 ;
V_47 [ V_87 ] = V_48 ;
break;
}
}
F_98 ( & V_178 ) ;
if ( V_87 == V_179 )
return - V_182 ;
V_8 = F_69 ( V_48 , 0 ) ;
if ( V_8 == NULL )
return - V_80 ;
V_48 -> V_116 = 0 ;
return 0 ;
}
static void F_103 ( struct V_47 * V_48 )
{
F_21 ( V_48 -> V_65 ) ;
F_21 ( V_48 -> V_114 ) ;
F_21 ( V_48 ) ;
}
static void F_104 ( struct V_183 * V_184 )
{
struct V_47 * V_48 = F_77 ( V_184 , struct V_47 , V_184 ) ;
F_103 ( V_48 ) ;
}
static inline void F_105 ( struct V_47 * V_48 )
{
F_106 ( & V_48 -> V_184 ) ;
}
static inline void F_107 ( struct V_47 * V_48 )
{
F_108 ( & V_48 -> V_184 , F_104 ) ;
}
static struct V_47 * F_109 ( void )
{
struct V_47 * V_48 = F_57 ( sizeof( struct V_47 ) , V_137 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_114 = F_15 ( V_185 + 1 , V_137 ) ;
if ( V_48 -> V_114 == NULL ) {
F_21 ( V_48 ) ;
return NULL ;
}
V_48 -> V_65 = F_15 ( 2 * V_185 + 2 , V_137 ) ;
if ( V_48 -> V_65 == NULL ) {
F_21 ( V_48 -> V_114 ) ;
F_21 ( V_48 ) ;
return NULL ;
}
F_70 ( & V_48 -> V_81 ) ;
F_71 ( & V_48 -> V_148 ) ;
F_110 ( & V_48 -> V_184 ) ;
F_16 ( & V_48 -> V_70 ) ;
V_48 -> V_141 = V_186 ;
V_48 -> V_135 = V_187 ;
V_48 -> V_139 = V_188 ;
V_48 -> V_79 = V_34 ;
V_48 -> V_76 = 1 ;
V_48 -> V_51 = 1 ;
V_48 -> V_163 = 64 ;
V_48 -> V_78 = 64 ;
V_48 -> V_116 = 1 ;
return V_48 ;
}
static int F_111 ( struct V_47 * V_48 , T_1 * V_25 , int V_4 )
{
if ( F_112 ( V_48 -> V_95 ) < V_4 ) {
F_113 ( V_189 , & V_48 -> V_95 -> V_71 ) ;
return - V_190 ;
}
if ( V_27 & 4 )
F_19 ( L_27 , V_66 ,
V_25 , V_4 ) ;
V_48 -> V_95 -> V_151 -> V_191 ( V_48 -> V_95 , V_25 , V_4 ) ;
return V_4 ;
}
static int F_114 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
int V_192 , V_87 , V_193 ;
V_48 -> V_95 = F_115 ( V_95 ) ;
V_48 -> V_40 = F_111 ;
V_192 = F_100 ( V_48 ) ;
if ( V_192 != 0 )
F_45 ( V_48 -> V_95 ) ;
else {
V_193 = V_48 -> V_181 << 6 ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_116 ( V_194 , V_193 + V_87 , NULL ) ;
}
return V_192 ;
}
static void F_117 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
int V_87 ;
int V_193 = V_48 -> V_181 << 6 ;
F_11 ( V_95 != V_48 -> V_95 ) ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_118 ( V_194 , V_193 + V_87 ) ;
F_96 ( V_48 ) ;
F_45 ( V_48 -> V_95 ) ;
V_48 -> V_95 = NULL ;
}
static void F_119 ( struct V_94 * V_95 , const unsigned char * V_195 ,
char * V_196 , int V_165 )
{
struct V_47 * V_48 = V_95 -> V_197 ;
const unsigned char * V_68 ;
char * V_198 ;
int V_87 ;
char V_71 = V_199 ;
if ( V_27 & 4 )
F_19 ( L_28 , V_66 ,
V_195 , V_165 ) ;
for ( V_87 = V_165 , V_68 = V_195 , V_198 = V_196 ; V_87 ; V_87 -- , V_68 ++ ) {
if ( V_198 )
V_71 = * V_198 ++ ;
switch ( V_71 ) {
case V_199 :
V_48 -> V_180 ( V_48 , * V_68 ) ;
break;
case V_109 :
case V_105 :
case V_110 :
case V_111 :
V_48 -> error ( V_48 , * V_68 , V_71 ) ;
break;
default:
F_120 ( 1 , L_29 ,
F_121 ( V_95 ) , V_71 ) ;
break;
}
}
}
static void F_122 ( struct V_94 * V_95 )
{
}
static void F_123 ( struct V_94 * V_95 )
{
struct V_47 * V_48 = V_95 -> V_197 ;
F_117 ( V_95 , V_48 ) ;
F_122 ( V_95 ) ;
F_107 ( V_48 ) ;
}
static int F_124 ( struct V_94 * V_95 )
{
struct V_47 * V_48 ;
int V_192 ;
if ( V_95 -> V_151 -> V_191 == NULL )
return - V_200 ;
V_48 = F_109 () ;
if ( V_48 == NULL )
return - V_80 ;
V_95 -> V_197 = V_48 ;
V_95 -> V_201 = 65536 ;
V_48 -> V_51 = 1 ;
V_192 = F_114 ( V_95 , V_48 ) ;
if ( V_192 != 0 ) {
F_96 ( V_48 ) ;
F_107 ( V_48 ) ;
}
return V_192 ;
}
static void F_125 ( struct V_94 * V_95 )
{
struct V_47 * V_48 = V_95 -> V_197 ;
unsigned long V_71 ;
F_126 ( V_189 , & V_95 -> V_71 ) ;
F_25 ( & V_48 -> V_72 , V_71 ) ;
F_17 ( V_48 ) ;
if ( V_48 -> V_67 < V_92 ) {
F_35 ( V_48 ) ;
}
F_26 ( & V_48 -> V_72 , V_71 ) ;
}
static T_3 F_127 ( struct V_94 * V_95 , struct V_202 * V_202 ,
unsigned char T_4 * V_114 , T_5 V_203 )
{
return - V_129 ;
}
static T_3 F_128 ( struct V_94 * V_95 , struct V_202 * V_202 ,
const unsigned char * V_114 , T_5 V_203 )
{
int V_204 = F_112 ( V_95 ) ;
if ( V_204 >= V_203 )
return V_95 -> V_151 -> V_191 ( V_95 , V_114 , V_203 ) ;
F_113 ( V_189 , & V_95 -> V_71 ) ;
return - V_205 ;
}
static unsigned int F_129 ( struct V_94 * V_95 , struct V_202 * V_202 ,
T_6 * V_206 )
{
unsigned int V_207 = 0 ;
struct V_47 * V_48 = V_95 -> V_197 ;
F_130 ( V_202 , & V_95 -> V_208 , V_206 ) ;
F_130 ( V_202 , & V_95 -> V_209 , V_206 ) ;
if ( F_131 ( V_202 ) )
V_207 |= V_210 ;
if ( ! F_132 ( V_95 ) && F_112 ( V_95 ) > 0 )
V_207 |= V_211 | V_212 ;
if ( V_48 -> V_116 )
V_207 |= V_210 ;
return V_207 ;
}
static int F_133 ( struct V_94 * V_95 , struct V_47 * V_48 ,
struct V_213 * V_2 )
{
int V_214 = 0 ;
int V_215 = 0 ;
if ( ( V_2 -> V_76 != 1 && V_2 -> V_76 != 2 ) || V_2 -> V_216 )
return - V_129 ;
if ( V_2 -> V_163 > V_185 || V_2 -> V_78 > V_217 || V_2 -> V_163 < 8 || V_2 -> V_78 < 8 )
return - V_200 ;
if ( V_2 -> V_139 < 3 )
return - V_200 ;
if ( V_2 -> V_218 > 1 )
return - V_200 ;
if ( V_2 -> V_69 > 1 )
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
if ( V_2 -> V_69 != V_48 -> V_69 )
V_214 = 1 ;
if ( V_2 -> V_163 != V_48 -> V_163 )
V_215 = 1 ;
if ( V_2 -> V_78 != V_48 -> V_78 )
V_215 = 1 ;
if ( V_214 || V_215 ) {
F_49 ( V_48 -> V_8 [ 0 ] ) ;
F_99 ( V_48 -> V_131 ,
V_48 -> V_8 [ 0 ] -> V_142 == V_143 ) ;
if ( F_134 ( V_219 ) )
return - V_220 ;
}
if ( V_215 )
F_96 ( V_48 ) ;
V_48 -> V_69 = V_2 -> V_69 ;
V_48 -> V_163 = V_2 -> V_163 ;
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
F_100 ( V_48 ) ;
if ( V_48 -> V_69 && V_214 )
F_65 ( V_48 -> V_8 [ 0 ] ) ;
return 0 ;
}
static int F_135 ( struct V_94 * V_95 , struct V_202 * V_202 ,
unsigned int V_93 , unsigned long V_221 )
{
struct V_213 V_2 ;
struct V_47 * V_48 = V_95 -> V_197 ;
switch ( V_93 ) {
case V_222 :
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_76 = V_48 -> V_76 ;
V_2 . V_218 = V_48 -> V_51 ;
V_2 . V_69 = V_48 -> V_69 ;
V_2 . V_141 = V_48 -> V_141 ;
V_2 . V_135 = V_48 -> V_135 ;
V_2 . V_223 = 0 ;
V_2 . V_139 = V_48 -> V_139 ;
if ( V_48 -> V_79 == V_34 )
V_2 . V_87 = 1 ;
else
V_2 . V_87 = 2 ;
F_8 ( L_30 , V_48 -> V_79 , V_2 . V_87 ) ;
V_2 . V_163 = V_48 -> V_163 ;
V_2 . V_78 = V_48 -> V_78 ;
V_2 . V_216 = 0 ;
if ( F_136 ( ( void * ) V_221 , & V_2 , sizeof( V_2 ) ) )
return - V_224 ;
return 0 ;
case V_225 :
if ( F_137 ( & V_2 , ( void * ) V_221 , sizeof( V_2 ) ) )
return - V_224 ;
return F_133 ( V_95 , V_48 , & V_2 ) ;
default:
return F_138 ( V_95 , V_202 , V_93 , V_221 ) ;
}
}
static int F_139 ( struct V_226 * V_90 )
{
F_8 ( L_31 , V_227 ) ;
F_140 ( V_90 ) ;
return 0 ;
}
static int F_141 ( struct V_226 * V_90 )
{
F_142 ( V_90 ) ;
return 0 ;
}
static struct V_228 * F_143 ( struct V_226 * V_90 )
{
return & ( (struct V_229 * ) F_144 ( V_90 ) ) -> V_230 ;
}
static void F_145 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_90 ) {
F_11 ( 1 ) ;
return;
}
V_8 -> V_76 = V_8 -> V_231 ;
V_8 -> V_25 = V_8 -> V_232 ;
F_146 ( V_8 -> V_90 ) ;
V_8 -> V_90 = NULL ;
}
static void F_147 ( struct V_183 * V_184 )
{
struct V_229 * V_233 ;
struct V_7 * V_8 ;
V_233 = F_77 ( V_184 , struct V_229 , V_184 ) ;
V_8 = V_233 -> V_8 ;
if ( V_8 -> V_90 ) {
F_148 ( V_8 -> V_90 ) ;
F_145 ( V_8 ) ;
}
}
static inline void F_149 ( struct V_229 * V_233 )
{
F_106 ( & V_233 -> V_184 ) ;
}
static inline void F_150 ( struct V_229 * V_233 )
{
F_108 ( & V_233 -> V_184 , F_147 ) ;
}
static int F_151 ( struct V_234 * V_85 ,
struct V_226 * V_90 )
{
struct V_229 * V_233 = F_144 ( V_90 ) ;
struct V_7 * V_8 = V_233 -> V_8 ;
F_149 ( V_233 ) ;
F_152 ( & V_8 -> V_86 , V_85 ) ;
F_153 ( V_90 ) . V_235 ++ ;
F_153 ( V_90 ) . V_67 += V_85 -> V_4 ;
F_36 ( V_8 ) ;
F_154 ( V_90 ) ;
F_150 ( V_233 ) ;
return V_236 ;
}
static void F_155 ( struct V_226 * V_90 )
{
F_156 ( & V_90 -> V_237 , L_32 ) ;
F_153 ( V_90 ) . V_238 ++ ;
}
static void F_157 ( struct V_7 * V_8 ,
unsigned char * V_239 , int V_74 )
{
struct V_226 * V_90 = V_8 -> V_90 ;
struct V_234 * V_85 ;
struct V_229 * V_233 = F_144 ( V_90 ) ;
F_149 ( V_233 ) ;
V_85 = F_158 ( V_74 + V_240 ) ;
if ( ! V_85 ) {
F_153 ( V_90 ) . V_241 ++ ;
F_150 ( V_233 ) ;
return;
}
F_159 ( V_85 , V_240 ) ;
memcpy ( F_160 ( V_85 , V_74 ) , V_239 , V_74 ) ;
V_85 -> V_237 = V_90 ;
V_85 -> V_242 = F_161 ( V_243 ) ;
F_162 ( V_85 ) ;
F_153 ( V_90 ) . V_244 ++ ;
F_153 ( V_90 ) . V_245 += V_74 ;
F_150 ( V_233 ) ;
return;
}
static void F_163 ( struct V_226 * V_90 )
{
static const struct V_246 V_247 = {
. V_248 = F_139 ,
. V_249 = F_141 ,
. V_250 = F_151 ,
. V_251 = F_155 ,
. V_252 = F_143 ,
} ;
V_90 -> V_253 = & V_247 ;
V_90 -> V_254 = V_255 ;
V_90 -> V_71 = V_256 | V_257 | V_258 ;
V_90 -> type = V_259 ;
V_90 -> V_260 = 10 ;
}
static void F_88 ( struct V_7 * V_8 )
{
struct V_229 * V_233 ;
F_8 ( L_33 ) ;
if ( ! V_8 -> V_90 )
return;
V_233 = F_144 ( V_8 -> V_90 ) ;
F_150 ( V_233 ) ;
}
static int F_164 ( struct V_7 * V_8 , struct V_261 * V_262 )
{
char * V_263 ;
int V_264 = 0 ;
struct V_226 * V_90 ;
struct V_229 * V_233 ;
if ( ! F_165 ( V_265 ) )
return - V_266 ;
if ( V_8 -> V_76 > 2 )
return - V_182 ;
if ( V_262 -> V_242 != F_161 ( V_243 ) )
return - V_267 ;
if ( V_262 -> V_76 != 3 && V_262 -> V_76 != 4 )
return - V_267 ;
F_8 ( L_34 ) ;
V_263 = L_35 ;
if ( V_262 -> V_268 [ 0 ] != '\0' )
V_263 = V_262 -> V_268 ;
V_90 = F_166 ( sizeof( struct V_229 ) , V_263 ,
V_269 , F_163 ) ;
if ( ! V_90 ) {
F_167 ( L_36 ) ;
return - V_80 ;
}
V_90 -> V_78 = V_8 -> V_48 -> V_78 ;
V_90 -> V_270 = 8 ;
V_90 -> V_271 = V_8 -> V_48 -> V_78 ;
V_233 = F_144 ( V_90 ) ;
V_233 -> V_8 = V_8 ;
F_110 ( & V_233 -> V_184 ) ;
strncpy ( V_262 -> V_268 , V_90 -> V_272 , V_273 ) ;
V_8 -> V_231 = V_8 -> V_76 ;
V_8 -> V_232 = V_8 -> V_25 ;
V_8 -> V_76 = V_262 -> V_76 ;
V_8 -> V_25 = F_157 ;
V_8 -> V_90 = V_90 ;
F_8 ( L_37 ) ;
V_264 = F_168 ( V_90 ) ;
if ( V_264 ) {
F_167 ( L_38 , V_264 ) ;
F_145 ( V_8 ) ;
return V_264 ;
}
return V_90 -> V_274 ;
}
static int F_169 ( struct V_7 * V_8 , T_1 V_99 )
{
T_1 V_9 [ 5 ] ;
struct V_125 * V_55 ;
int V_4 = 2 ;
if ( V_99 )
V_4 ++ ;
V_9 [ 0 ] = V_4 << 1 | V_6 ;
V_9 [ 1 ] = V_8 -> V_22 << 2 | 3 ;
V_9 [ 2 ] = F_4 ( V_8 ) << 1 | V_6 ;
if ( V_99 )
V_9 [ 3 ] = V_99 << 4 | 2 | V_6 ;
V_55 = F_56 ( V_8 -> V_48 , V_106 , V_9 , V_4 + 1 ) ;
if ( V_55 == NULL )
return - V_80 ;
return F_59 ( V_8 -> V_48 , V_55 ) ;
}
static int F_170 ( struct V_107 * V_104 )
{
struct V_7 * V_8 = F_77 ( V_104 , struct V_7 , V_104 ) ;
if ( V_8 -> V_142 != V_144 )
return 0 ;
if ( V_27 & 2 )
return 1 ;
return V_8 -> V_103 & V_19 ;
}
static void F_171 ( struct V_107 * V_104 , int V_275 )
{
struct V_7 * V_8 = F_77 ( V_104 , struct V_7 , V_104 ) ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_275 )
V_12 |= V_13 | V_15 ;
else
V_12 &= ~ ( V_13 | V_15 ) ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
F_169 ( V_8 , 0 ) ;
}
}
static int F_172 ( struct V_276 * V_277 , struct V_94 * V_95 )
{
struct V_47 * V_48 ;
struct V_7 * V_8 ;
unsigned int line = V_95 -> V_278 ;
unsigned int V_279 = line >> 6 ;
bool V_280 = false ;
int V_192 ;
line = line & 0x3F ;
if ( V_279 >= V_179 )
return - V_281 ;
if ( V_47 [ V_279 ] == NULL )
return - V_282 ;
if ( line == 0 || line > 61 )
return - V_283 ;
V_48 = V_47 [ V_279 ] ;
if ( V_48 -> V_116 )
return - V_284 ;
F_87 ( & V_48 -> V_148 ) ;
if ( V_48 -> V_8 [ 0 ] && V_48 -> V_8 [ 0 ] -> V_142 != V_144 ) {
F_89 ( & V_48 -> V_148 ) ;
return - V_285 ;
}
V_8 = V_48 -> V_8 [ line ] ;
if ( V_8 == NULL ) {
V_280 = true ;
V_8 = F_69 ( V_48 , line ) ;
}
if ( V_8 == NULL ) {
F_89 ( & V_48 -> V_148 ) ;
return - V_80 ;
}
V_192 = F_173 ( & V_8 -> V_104 , V_277 , V_95 ) ;
if ( V_192 ) {
if ( V_280 )
F_84 ( V_8 ) ;
F_89 ( & V_48 -> V_148 ) ;
return V_192 ;
}
F_82 ( V_8 ) ;
F_82 ( V_48 -> V_8 [ 0 ] ) ;
F_105 ( V_48 ) ;
V_95 -> V_286 = V_8 ;
F_89 ( & V_48 -> V_148 ) ;
return 0 ;
}
static int F_174 ( struct V_94 * V_95 , struct V_202 * V_287 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
struct V_107 * V_104 = & V_8 -> V_104 ;
V_104 -> V_165 ++ ;
F_91 ( V_104 , V_95 ) ;
V_8 -> V_103 = 0 ;
F_175 ( V_104 , 1 ) ;
F_65 ( V_8 ) ;
return F_176 ( V_104 , V_95 , V_287 ) ;
}
static void F_177 ( struct V_94 * V_95 , struct V_202 * V_287 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
struct V_47 * V_48 ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_142 == V_143 )
return;
F_87 ( & V_8 -> V_148 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_148 ) ;
V_48 = V_8 -> V_48 ;
if ( F_178 ( & V_8 -> V_104 , V_95 , V_287 ) == 0 )
return;
F_49 ( V_8 ) ;
if ( F_179 ( & V_8 -> V_104 ) && F_180 ( V_95 ) )
F_181 ( & V_8 -> V_104 ) ;
F_182 ( & V_8 -> V_104 , V_95 ) ;
F_91 ( & V_8 -> V_104 , NULL ) ;
return;
}
static void F_183 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return;
F_184 ( & V_8 -> V_104 ) ;
F_49 ( V_8 ) ;
}
static int F_185 ( struct V_94 * V_95 , const unsigned char * V_114 ,
int V_4 )
{
int V_288 ;
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
V_288 = F_186 ( V_8 -> V_77 , V_114 , V_4 , & V_8 -> V_81 ) ;
F_36 ( V_8 ) ;
return V_288 ;
}
static int F_187 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
return V_289 - F_28 ( V_8 -> V_77 ) ;
}
static int F_188 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
return F_28 ( V_8 -> V_77 ) ;
}
static void F_189 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return;
F_62 ( V_8 -> V_77 ) ;
}
static void F_190 ( struct V_94 * V_95 , int V_290 )
{
}
static int F_191 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
return V_8 -> V_103 ;
}
static int F_192 ( struct V_94 * V_95 ,
unsigned int V_291 , unsigned int V_292 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
V_12 &= ~ V_292 ;
V_12 |= V_291 ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
return F_169 ( V_8 , 0 ) ;
}
return 0 ;
}
static int F_193 ( struct V_94 * V_95 ,
unsigned int V_93 , unsigned long V_221 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
struct V_261 V_262 ;
int V_278 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
switch ( V_93 ) {
case V_293 :
if ( F_137 ( & V_262 , ( void T_4 * ) V_221 , sizeof( V_262 ) ) )
return - V_224 ;
V_262 . V_268 [ V_273 - 1 ] = '\0' ;
F_87 ( & V_8 -> V_148 ) ;
V_278 = F_164 ( V_8 , & V_262 ) ;
F_89 ( & V_8 -> V_148 ) ;
if ( F_136 ( ( void T_4 * ) V_221 , & V_262 , sizeof( V_262 ) ) )
return - V_224 ;
return V_278 ;
case V_294 :
if ( ! F_165 ( V_265 ) )
return - V_266 ;
F_87 ( & V_8 -> V_148 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_148 ) ;
return 0 ;
default:
return - V_295 ;
}
}
static void F_194 ( struct V_94 * V_95 , struct V_296 * V_297 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return;
F_195 ( & V_95 -> V_298 , V_297 ) ;
}
static void F_196 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return;
if ( F_197 ( V_95 ) )
V_8 -> V_12 &= ~ V_13 ;
V_8 -> V_10 = 1 ;
F_169 ( V_8 , 0 ) ;
}
static void F_198 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
if ( V_8 -> V_142 == V_143 )
return;
if ( F_197 ( V_95 ) )
V_8 -> V_12 |= V_13 ;
V_8 -> V_10 = 0 ;
F_169 ( V_8 , 0 ) ;
}
static int F_199 ( struct V_94 * V_95 , int V_142 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
int V_299 = 0 ;
if ( V_8 -> V_142 == V_143 )
return - V_200 ;
if ( V_142 == - 1 )
V_299 = 0x0F ;
else if ( V_142 > 0 ) {
V_299 = V_142 / 200 ;
if ( V_299 > 0x0F )
V_299 = 0x0F ;
}
return F_169 ( V_8 , V_299 ) ;
}
static void F_200 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_286 ;
struct V_47 * V_48 = V_8 -> V_48 ;
F_84 ( V_8 ) ;
F_84 ( V_48 -> V_8 [ 0 ] ) ;
F_107 ( V_48 ) ;
}
static int T_7 F_201 ( void )
{
int V_300 = F_202 ( V_301 , & V_302 ) ;
if ( V_300 != 0 ) {
F_167 ( L_39 ,
V_300 ) ;
return V_300 ;
}
V_194 = F_203 ( 256 ) ;
if ( ! V_194 ) {
F_204 ( V_301 ) ;
F_167 ( L_40 ) ;
return - V_200 ;
}
V_194 -> V_303 = L_41 ;
V_194 -> V_272 = L_41 ;
V_194 -> V_304 = 0 ;
V_194 -> V_305 = 0 ;
V_194 -> type = V_306 ;
V_194 -> V_307 = V_308 ;
V_194 -> V_71 = V_309 | V_310
| V_311 ;
V_194 -> V_312 = V_313 ;
V_194 -> V_312 . V_314 &= ~ V_315 ;
F_205 ( V_194 , & V_316 ) ;
F_70 ( & V_178 ) ;
if ( F_206 ( V_194 ) ) {
F_207 ( V_194 ) ;
F_204 ( V_301 ) ;
F_167 ( L_42 ) ;
return - V_182 ;
}
F_8 ( L_43 ,
V_194 -> V_304 , V_194 -> V_305 ) ;
return 0 ;
}
static void T_8 F_208 ( void )
{
int V_300 = F_204 ( V_301 ) ;
if ( V_300 != 0 )
F_167 ( L_44 ,
V_300 ) ;
F_209 ( V_194 ) ;
F_207 ( V_194 ) ;
}
