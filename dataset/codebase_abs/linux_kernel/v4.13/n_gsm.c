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
static int F_96 ( struct V_47 * V_48 )
{
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_125 * V_175 ;
if ( ! V_8 )
return 0 ;
V_175 = F_56 ( V_48 , V_115 , NULL , 0 ) ;
if ( V_175 )
F_59 ( V_48 , V_175 ) ;
F_78 ( & V_48 -> V_128 ) ;
F_49 ( V_8 ) ;
F_97 ( V_48 -> V_131 ,
V_8 -> V_142 == V_143 ) ;
if ( F_98 ( V_176 ) )
return - V_177 ;
return 0 ;
}
static void F_99 ( struct V_47 * V_48 )
{
int V_87 ;
struct V_7 * V_8 = V_48 -> V_8 [ 0 ] ;
struct V_54 * V_178 , * V_179 ;
V_48 -> V_116 = 1 ;
F_100 ( & V_180 ) ;
for ( V_87 = 0 ; V_87 < V_181 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == V_48 ) {
V_47 [ V_87 ] = NULL ;
break;
}
}
F_101 ( & V_180 ) ;
if ( V_87 == V_181 )
return;
F_78 ( & V_48 -> V_128 ) ;
if ( V_8 )
V_8 -> V_116 = 1 ;
F_87 ( & V_48 -> V_148 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
if ( V_48 -> V_8 [ V_87 ] )
F_86 ( V_48 -> V_8 [ V_87 ] ) ;
F_89 ( & V_48 -> V_148 ) ;
F_18 (txq, ntxq, &gsm->tx_list, list)
F_21 ( V_178 ) ;
F_16 ( & V_48 -> V_70 ) ;
}
static int F_102 ( struct V_47 * V_48 )
{
struct V_7 * V_8 ;
int V_87 = 0 ;
F_103 ( & V_48 -> V_128 , F_54 , ( unsigned long ) V_48 ) ;
F_104 ( & V_48 -> V_131 ) ;
F_70 ( & V_48 -> V_126 ) ;
F_70 ( & V_48 -> V_72 ) ;
if ( V_48 -> V_51 == 0 )
V_48 -> V_182 = F_93 ;
else
V_48 -> V_182 = F_94 ;
V_48 -> error = F_95 ;
F_100 ( & V_180 ) ;
for ( V_87 = 0 ; V_87 < V_181 ; V_87 ++ ) {
if ( V_47 [ V_87 ] == NULL ) {
V_48 -> V_183 = V_87 ;
V_47 [ V_87 ] = V_48 ;
break;
}
}
F_101 ( & V_180 ) ;
if ( V_87 == V_181 )
return - V_184 ;
V_8 = F_69 ( V_48 , 0 ) ;
if ( V_8 == NULL )
return - V_80 ;
V_48 -> V_116 = 0 ;
return 0 ;
}
static void F_105 ( struct V_47 * V_48 )
{
F_21 ( V_48 -> V_65 ) ;
F_21 ( V_48 -> V_114 ) ;
F_21 ( V_48 ) ;
}
static void F_106 ( struct V_185 * V_186 )
{
struct V_47 * V_48 = F_77 ( V_186 , struct V_47 , V_186 ) ;
F_105 ( V_48 ) ;
}
static inline void F_107 ( struct V_47 * V_48 )
{
F_108 ( & V_48 -> V_186 ) ;
}
static inline void F_109 ( struct V_47 * V_48 )
{
F_110 ( & V_48 -> V_186 , F_106 ) ;
}
static struct V_47 * F_111 ( void )
{
struct V_47 * V_48 = F_57 ( sizeof( struct V_47 ) , V_137 ) ;
if ( V_48 == NULL )
return NULL ;
V_48 -> V_114 = F_15 ( V_187 + 1 , V_137 ) ;
if ( V_48 -> V_114 == NULL ) {
F_21 ( V_48 ) ;
return NULL ;
}
V_48 -> V_65 = F_15 ( 2 * V_187 + 2 , V_137 ) ;
if ( V_48 -> V_65 == NULL ) {
F_21 ( V_48 -> V_114 ) ;
F_21 ( V_48 ) ;
return NULL ;
}
F_70 ( & V_48 -> V_81 ) ;
F_71 ( & V_48 -> V_148 ) ;
F_112 ( & V_48 -> V_186 ) ;
F_16 ( & V_48 -> V_70 ) ;
V_48 -> V_141 = V_188 ;
V_48 -> V_135 = V_189 ;
V_48 -> V_139 = V_190 ;
V_48 -> V_79 = V_34 ;
V_48 -> V_76 = 1 ;
V_48 -> V_51 = 1 ;
V_48 -> V_163 = 64 ;
V_48 -> V_78 = 64 ;
V_48 -> V_116 = 1 ;
return V_48 ;
}
static int F_113 ( struct V_47 * V_48 , T_1 * V_25 , int V_4 )
{
if ( F_114 ( V_48 -> V_95 ) < V_4 ) {
F_115 ( V_191 , & V_48 -> V_95 -> V_71 ) ;
return - V_192 ;
}
if ( V_27 & 4 )
F_19 ( L_27 , V_66 ,
V_25 , V_4 ) ;
V_48 -> V_95 -> V_151 -> V_193 ( V_48 -> V_95 , V_25 , V_4 ) ;
return V_4 ;
}
static int F_116 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
int V_194 , V_87 , V_195 ;
V_48 -> V_95 = F_117 ( V_95 ) ;
V_48 -> V_40 = F_113 ;
V_194 = F_102 ( V_48 ) ;
if ( V_194 != 0 )
F_45 ( V_48 -> V_95 ) ;
else {
V_195 = V_48 -> V_183 << 6 ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_118 ( V_196 , V_195 + V_87 , NULL ) ;
}
return V_194 ;
}
static void F_119 ( struct V_94 * V_95 , struct V_47 * V_48 )
{
int V_87 ;
int V_195 = V_48 -> V_183 << 6 ;
F_11 ( V_95 != V_48 -> V_95 ) ;
for ( V_87 = 1 ; V_87 < V_88 ; V_87 ++ )
F_120 ( V_196 , V_195 + V_87 ) ;
F_99 ( V_48 ) ;
F_45 ( V_48 -> V_95 ) ;
V_48 -> V_95 = NULL ;
}
static void F_121 ( struct V_94 * V_95 , const unsigned char * V_197 ,
char * V_198 , int V_165 )
{
struct V_47 * V_48 = V_95 -> V_199 ;
const unsigned char * V_68 ;
char * V_200 ;
int V_87 ;
char V_71 = V_201 ;
if ( V_27 & 4 )
F_19 ( L_28 , V_66 ,
V_197 , V_165 ) ;
for ( V_87 = V_165 , V_68 = V_197 , V_200 = V_198 ; V_87 ; V_87 -- , V_68 ++ ) {
if ( V_200 )
V_71 = * V_200 ++ ;
switch ( V_71 ) {
case V_201 :
V_48 -> V_182 ( V_48 , * V_68 ) ;
break;
case V_109 :
case V_105 :
case V_110 :
case V_111 :
V_48 -> error ( V_48 , * V_68 , V_71 ) ;
break;
default:
F_122 ( 1 , L_29 ,
F_123 ( V_95 ) , V_71 ) ;
break;
}
}
}
static void F_124 ( struct V_94 * V_95 )
{
}
static void F_125 ( struct V_94 * V_95 )
{
struct V_47 * V_48 = V_95 -> V_199 ;
F_119 ( V_95 , V_48 ) ;
F_124 ( V_95 ) ;
F_109 ( V_48 ) ;
}
static int F_126 ( struct V_94 * V_95 )
{
struct V_47 * V_48 ;
int V_194 ;
if ( V_95 -> V_151 -> V_193 == NULL )
return - V_202 ;
V_48 = F_111 () ;
if ( V_48 == NULL )
return - V_80 ;
V_95 -> V_199 = V_48 ;
V_95 -> V_203 = 65536 ;
V_48 -> V_51 = 1 ;
V_194 = F_116 ( V_95 , V_48 ) ;
if ( V_194 != 0 ) {
F_99 ( V_48 ) ;
F_109 ( V_48 ) ;
}
return V_194 ;
}
static void F_127 ( struct V_94 * V_95 )
{
struct V_47 * V_48 = V_95 -> V_199 ;
unsigned long V_71 ;
F_128 ( V_191 , & V_95 -> V_71 ) ;
F_25 ( & V_48 -> V_72 , V_71 ) ;
F_17 ( V_48 ) ;
if ( V_48 -> V_67 < V_92 ) {
F_35 ( V_48 ) ;
}
F_26 ( & V_48 -> V_72 , V_71 ) ;
}
static T_3 F_129 ( struct V_94 * V_95 , struct V_204 * V_204 ,
unsigned char T_4 * V_114 , T_5 V_205 )
{
return - V_129 ;
}
static T_3 F_130 ( struct V_94 * V_95 , struct V_204 * V_204 ,
const unsigned char * V_114 , T_5 V_205 )
{
int V_206 = F_114 ( V_95 ) ;
if ( V_206 >= V_205 )
return V_95 -> V_151 -> V_193 ( V_95 , V_114 , V_205 ) ;
F_115 ( V_191 , & V_95 -> V_71 ) ;
return - V_207 ;
}
static unsigned int F_131 ( struct V_94 * V_95 , struct V_204 * V_204 ,
T_6 * V_208 )
{
unsigned int V_209 = 0 ;
struct V_47 * V_48 = V_95 -> V_199 ;
F_132 ( V_204 , & V_95 -> V_210 , V_208 ) ;
F_132 ( V_204 , & V_95 -> V_211 , V_208 ) ;
if ( F_133 ( V_204 ) )
V_209 |= V_212 ;
if ( ! F_134 ( V_95 ) && F_114 ( V_95 ) > 0 )
V_209 |= V_213 | V_214 ;
if ( V_48 -> V_116 )
V_209 |= V_212 ;
return V_209 ;
}
static int F_135 ( struct V_94 * V_95 , struct V_47 * V_48 ,
struct V_215 * V_2 )
{
int V_216 = 0 ;
int V_217 = 0 ;
if ( ( V_2 -> V_76 != 1 && V_2 -> V_76 != 2 ) || V_2 -> V_218 )
return - V_129 ;
if ( V_2 -> V_163 > V_187 || V_2 -> V_78 > V_219 || V_2 -> V_163 < 8 || V_2 -> V_78 < 8 )
return - V_202 ;
if ( V_2 -> V_139 < 3 )
return - V_202 ;
if ( V_2 -> V_220 > 1 )
return - V_202 ;
if ( V_2 -> V_69 > 1 )
return - V_202 ;
if ( V_2 -> V_87 == 0 || V_2 -> V_87 > 2 )
return - V_202 ;
if ( V_2 -> V_141 != 0 && V_2 -> V_141 != V_48 -> V_141 )
V_217 = 1 ;
if ( V_2 -> V_135 != 0 && V_2 -> V_135 != V_48 -> V_135 )
V_217 = 1 ;
if ( V_2 -> V_220 != V_48 -> V_51 )
V_217 = 1 ;
if ( V_2 -> V_76 != V_48 -> V_76 )
V_217 = 1 ;
if ( V_2 -> V_69 != V_48 -> V_69 )
V_216 = 1 ;
if ( V_2 -> V_163 != V_48 -> V_163 )
V_217 = 1 ;
if ( V_2 -> V_78 != V_48 -> V_78 )
V_217 = 1 ;
if ( V_216 || V_217 ) {
int V_194 ;
V_194 = F_96 ( V_48 ) ;
if ( V_194 )
return V_194 ;
}
if ( V_217 )
F_99 ( V_48 ) ;
V_48 -> V_69 = V_2 -> V_69 ;
V_48 -> V_163 = V_2 -> V_163 ;
V_48 -> V_78 = V_2 -> V_78 ;
V_48 -> V_51 = V_2 -> V_220 ;
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
if ( V_217 )
F_102 ( V_48 ) ;
if ( V_48 -> V_69 && V_216 )
F_65 ( V_48 -> V_8 [ 0 ] ) ;
return 0 ;
}
static int F_136 ( struct V_94 * V_95 , struct V_204 * V_204 ,
unsigned int V_93 , unsigned long V_221 )
{
struct V_215 V_2 ;
struct V_47 * V_48 = V_95 -> V_199 ;
switch ( V_93 ) {
case V_222 :
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_76 = V_48 -> V_76 ;
V_2 . V_220 = V_48 -> V_51 ;
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
V_2 . V_218 = 0 ;
if ( F_137 ( ( void * ) V_221 , & V_2 , sizeof( V_2 ) ) )
return - V_224 ;
return 0 ;
case V_225 :
if ( F_138 ( & V_2 , ( void * ) V_221 , sizeof( V_2 ) ) )
return - V_224 ;
return F_135 ( V_95 , V_48 , & V_2 ) ;
default:
return F_139 ( V_95 , V_204 , V_93 , V_221 ) ;
}
}
static int F_140 ( struct V_226 * V_90 )
{
F_8 ( L_31 , V_227 ) ;
F_141 ( V_90 ) ;
return 0 ;
}
static int F_142 ( struct V_226 * V_90 )
{
F_143 ( V_90 ) ;
return 0 ;
}
static void F_144 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_90 ) {
F_11 ( 1 ) ;
return;
}
V_8 -> V_76 = V_8 -> V_228 ;
V_8 -> V_25 = V_8 -> V_229 ;
F_145 ( V_8 -> V_90 ) ;
V_8 -> V_90 = NULL ;
}
static void F_146 ( struct V_185 * V_186 )
{
struct V_230 * V_231 ;
struct V_7 * V_8 ;
V_231 = F_77 ( V_186 , struct V_230 , V_186 ) ;
V_8 = V_231 -> V_8 ;
if ( V_8 -> V_90 ) {
F_147 ( V_8 -> V_90 ) ;
F_144 ( V_8 ) ;
}
}
static inline void F_148 ( struct V_230 * V_231 )
{
F_108 ( & V_231 -> V_186 ) ;
}
static inline void F_149 ( struct V_230 * V_231 )
{
F_110 ( & V_231 -> V_186 , F_146 ) ;
}
static int F_150 ( struct V_232 * V_85 ,
struct V_226 * V_90 )
{
struct V_230 * V_231 = F_151 ( V_90 ) ;
struct V_7 * V_8 = V_231 -> V_8 ;
F_148 ( V_231 ) ;
F_152 ( & V_8 -> V_86 , V_85 ) ;
V_90 -> V_233 . V_234 ++ ;
V_90 -> V_233 . V_67 += V_85 -> V_4 ;
F_36 ( V_8 ) ;
F_153 ( V_90 ) ;
F_149 ( V_231 ) ;
return V_235 ;
}
static void F_154 ( struct V_226 * V_90 )
{
F_155 ( & V_90 -> V_236 , L_32 ) ;
V_90 -> V_233 . V_237 ++ ;
}
static void F_156 ( struct V_7 * V_8 ,
unsigned char * V_238 , int V_74 )
{
struct V_226 * V_90 = V_8 -> V_90 ;
struct V_232 * V_85 ;
struct V_230 * V_231 = F_151 ( V_90 ) ;
F_148 ( V_231 ) ;
V_85 = F_157 ( V_74 + V_239 ) ;
if ( ! V_85 ) {
V_90 -> V_233 . V_240 ++ ;
F_149 ( V_231 ) ;
return;
}
F_158 ( V_85 , V_239 ) ;
F_159 ( V_85 , V_238 , V_74 ) ;
V_85 -> V_236 = V_90 ;
V_85 -> V_241 = F_160 ( V_242 ) ;
F_161 ( V_85 ) ;
V_90 -> V_233 . V_243 ++ ;
V_90 -> V_233 . V_244 += V_74 ;
F_149 ( V_231 ) ;
return;
}
static void F_162 ( struct V_226 * V_90 )
{
static const struct V_245 V_246 = {
. V_247 = F_140 ,
. V_248 = F_142 ,
. V_249 = F_150 ,
. V_250 = F_154 ,
} ;
V_90 -> V_251 = & V_246 ;
V_90 -> V_252 = V_253 ;
V_90 -> V_71 = V_254 | V_255 | V_256 ;
V_90 -> type = V_257 ;
V_90 -> V_258 = 10 ;
}
static void F_88 ( struct V_7 * V_8 )
{
struct V_230 * V_231 ;
F_8 ( L_33 ) ;
if ( ! V_8 -> V_90 )
return;
V_231 = F_151 ( V_8 -> V_90 ) ;
F_149 ( V_231 ) ;
}
static int F_163 ( struct V_7 * V_8 , struct V_259 * V_260 )
{
char * V_261 ;
int V_262 = 0 ;
struct V_226 * V_90 ;
struct V_230 * V_231 ;
if ( ! F_164 ( V_263 ) )
return - V_264 ;
if ( V_8 -> V_76 > 2 )
return - V_184 ;
if ( V_260 -> V_241 != F_160 ( V_242 ) )
return - V_265 ;
if ( V_260 -> V_76 != 3 && V_260 -> V_76 != 4 )
return - V_265 ;
F_8 ( L_34 ) ;
V_261 = L_35 ;
if ( V_260 -> V_266 [ 0 ] != '\0' )
V_261 = V_260 -> V_266 ;
V_90 = F_165 ( sizeof( struct V_230 ) , V_261 ,
V_267 , F_162 ) ;
if ( ! V_90 ) {
F_166 ( L_36 ) ;
return - V_80 ;
}
V_90 -> V_78 = V_8 -> V_48 -> V_78 ;
V_90 -> V_268 = 8 ;
V_90 -> V_269 = V_8 -> V_48 -> V_78 ;
V_231 = F_151 ( V_90 ) ;
V_231 -> V_8 = V_8 ;
F_112 ( & V_231 -> V_186 ) ;
strncpy ( V_260 -> V_266 , V_90 -> V_270 , V_271 ) ;
V_8 -> V_228 = V_8 -> V_76 ;
V_8 -> V_229 = V_8 -> V_25 ;
V_8 -> V_76 = V_260 -> V_76 ;
V_8 -> V_25 = F_156 ;
V_8 -> V_90 = V_90 ;
F_8 ( L_37 ) ;
V_262 = F_167 ( V_90 ) ;
if ( V_262 ) {
F_166 ( L_38 , V_262 ) ;
F_144 ( V_8 ) ;
return V_262 ;
}
return V_90 -> V_272 ;
}
static int F_168 ( struct V_7 * V_8 , T_1 V_99 )
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
static int F_169 ( struct V_107 * V_104 )
{
struct V_7 * V_8 = F_77 ( V_104 , struct V_7 , V_104 ) ;
if ( V_8 -> V_142 != V_144 )
return 0 ;
if ( V_27 & 2 )
return 1 ;
return V_8 -> V_103 & V_19 ;
}
static void F_170 ( struct V_107 * V_104 , int V_273 )
{
struct V_7 * V_8 = F_77 ( V_104 , struct V_7 , V_104 ) ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_273 )
V_12 |= V_13 | V_15 ;
else
V_12 &= ~ ( V_13 | V_15 ) ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
F_168 ( V_8 , 0 ) ;
}
}
static int F_171 ( struct V_274 * V_275 , struct V_94 * V_95 )
{
struct V_47 * V_48 ;
struct V_7 * V_8 ;
unsigned int line = V_95 -> V_276 ;
unsigned int V_277 = line >> 6 ;
bool V_278 = false ;
int V_194 ;
line = line & 0x3F ;
if ( V_277 >= V_181 )
return - V_279 ;
if ( V_47 [ V_277 ] == NULL )
return - V_280 ;
if ( line == 0 || line > 61 )
return - V_281 ;
V_48 = V_47 [ V_277 ] ;
if ( V_48 -> V_116 )
return - V_282 ;
F_87 ( & V_48 -> V_148 ) ;
if ( V_48 -> V_8 [ 0 ] && V_48 -> V_8 [ 0 ] -> V_142 != V_144 ) {
F_89 ( & V_48 -> V_148 ) ;
return - V_283 ;
}
V_8 = V_48 -> V_8 [ line ] ;
if ( V_8 == NULL ) {
V_278 = true ;
V_8 = F_69 ( V_48 , line ) ;
}
if ( V_8 == NULL ) {
F_89 ( & V_48 -> V_148 ) ;
return - V_80 ;
}
V_194 = F_172 ( & V_8 -> V_104 , V_275 , V_95 ) ;
if ( V_194 ) {
if ( V_278 )
F_84 ( V_8 ) ;
F_89 ( & V_48 -> V_148 ) ;
return V_194 ;
}
F_82 ( V_8 ) ;
F_82 ( V_48 -> V_8 [ 0 ] ) ;
F_107 ( V_48 ) ;
V_95 -> V_284 = V_8 ;
F_89 ( & V_48 -> V_148 ) ;
return 0 ;
}
static int F_173 ( struct V_94 * V_95 , struct V_204 * V_285 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
struct V_107 * V_104 = & V_8 -> V_104 ;
V_104 -> V_165 ++ ;
F_91 ( V_104 , V_95 ) ;
V_8 -> V_103 = 0 ;
F_174 ( V_104 , 1 ) ;
F_65 ( V_8 ) ;
return F_175 ( V_104 , V_95 , V_285 ) ;
}
static void F_176 ( struct V_94 * V_95 , struct V_204 * V_285 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
struct V_47 * V_48 ;
if ( V_8 == NULL )
return;
if ( V_8 -> V_142 == V_143 )
return;
F_87 ( & V_8 -> V_148 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_148 ) ;
V_48 = V_8 -> V_48 ;
if ( F_177 ( & V_8 -> V_104 , V_95 , V_285 ) == 0 )
return;
F_49 ( V_8 ) ;
if ( F_178 ( & V_8 -> V_104 ) && F_179 ( V_95 ) )
F_180 ( & V_8 -> V_104 ) ;
F_181 ( & V_8 -> V_104 , V_95 ) ;
F_91 ( & V_8 -> V_104 , NULL ) ;
return;
}
static void F_182 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return;
F_183 ( & V_8 -> V_104 ) ;
F_49 ( V_8 ) ;
}
static int F_184 ( struct V_94 * V_95 , const unsigned char * V_114 ,
int V_4 )
{
int V_286 ;
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
V_286 = F_185 ( V_8 -> V_77 , V_114 , V_4 , & V_8 -> V_81 ) ;
F_36 ( V_8 ) ;
return V_286 ;
}
static int F_186 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
return V_287 - F_28 ( V_8 -> V_77 ) ;
}
static int F_187 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
return F_28 ( V_8 -> V_77 ) ;
}
static void F_188 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return;
F_62 ( V_8 -> V_77 ) ;
}
static void F_189 ( struct V_94 * V_95 , int V_288 )
{
}
static int F_190 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
return V_8 -> V_103 ;
}
static int F_191 ( struct V_94 * V_95 ,
unsigned int V_289 , unsigned int V_290 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
unsigned int V_12 = V_8 -> V_12 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
V_12 &= ~ V_290 ;
V_12 |= V_289 ;
if ( V_12 != V_8 -> V_12 ) {
V_8 -> V_12 = V_12 ;
return F_168 ( V_8 , 0 ) ;
}
return 0 ;
}
static int F_192 ( struct V_94 * V_95 ,
unsigned int V_93 , unsigned long V_221 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
struct V_259 V_260 ;
int V_276 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
switch ( V_93 ) {
case V_291 :
if ( F_138 ( & V_260 , ( void T_4 * ) V_221 , sizeof( V_260 ) ) )
return - V_224 ;
V_260 . V_266 [ V_271 - 1 ] = '\0' ;
F_87 ( & V_8 -> V_148 ) ;
V_276 = F_163 ( V_8 , & V_260 ) ;
F_89 ( & V_8 -> V_148 ) ;
if ( F_137 ( ( void T_4 * ) V_221 , & V_260 , sizeof( V_260 ) ) )
return - V_224 ;
return V_276 ;
case V_292 :
if ( ! F_164 ( V_263 ) )
return - V_264 ;
F_87 ( & V_8 -> V_148 ) ;
F_88 ( V_8 ) ;
F_89 ( & V_8 -> V_148 ) ;
return 0 ;
default:
return - V_293 ;
}
}
static void F_193 ( struct V_94 * V_95 , struct V_294 * V_295 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return;
F_194 ( & V_95 -> V_296 , V_295 ) ;
}
static void F_195 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return;
if ( F_196 ( V_95 ) )
V_8 -> V_12 &= ~ V_13 ;
V_8 -> V_10 = 1 ;
F_168 ( V_8 , 0 ) ;
}
static void F_197 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
if ( V_8 -> V_142 == V_143 )
return;
if ( F_196 ( V_95 ) )
V_8 -> V_12 |= V_13 ;
V_8 -> V_10 = 0 ;
F_168 ( V_8 , 0 ) ;
}
static int F_198 ( struct V_94 * V_95 , int V_142 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
int V_297 = 0 ;
if ( V_8 -> V_142 == V_143 )
return - V_202 ;
if ( V_142 == - 1 )
V_297 = 0x0F ;
else if ( V_142 > 0 ) {
V_297 = V_142 / 200 ;
if ( V_297 > 0x0F )
V_297 = 0x0F ;
}
return F_168 ( V_8 , V_297 ) ;
}
static void F_199 ( struct V_94 * V_95 )
{
struct V_7 * V_8 = V_95 -> V_284 ;
struct V_47 * V_48 = V_8 -> V_48 ;
F_84 ( V_8 ) ;
F_84 ( V_48 -> V_8 [ 0 ] ) ;
F_109 ( V_48 ) ;
}
static int T_7 F_200 ( void )
{
int V_298 = F_201 ( V_299 , & V_300 ) ;
if ( V_298 != 0 ) {
F_166 ( L_39 ,
V_298 ) ;
return V_298 ;
}
V_196 = F_202 ( 256 ) ;
if ( ! V_196 ) {
F_203 ( V_299 ) ;
F_166 ( L_40 ) ;
return - V_202 ;
}
V_196 -> V_301 = L_41 ;
V_196 -> V_270 = L_41 ;
V_196 -> V_302 = 0 ;
V_196 -> V_303 = 0 ;
V_196 -> type = V_304 ;
V_196 -> V_305 = V_306 ;
V_196 -> V_71 = V_307 | V_308
| V_309 ;
V_196 -> V_310 = V_311 ;
V_196 -> V_310 . V_312 &= ~ V_313 ;
F_204 ( V_196 , & V_314 ) ;
F_70 ( & V_180 ) ;
if ( F_205 ( V_196 ) ) {
F_206 ( V_196 ) ;
F_203 ( V_299 ) ;
F_166 ( L_42 ) ;
return - V_184 ;
}
F_8 ( L_43 ,
V_196 -> V_302 , V_196 -> V_303 ) ;
return 0 ;
}
static void T_8 F_207 ( void )
{
int V_298 = F_203 ( V_299 ) ;
if ( V_298 != 0 )
F_166 ( L_44 ,
V_298 ) ;
F_208 ( V_196 ) ;
F_206 ( V_196 ) ;
}
