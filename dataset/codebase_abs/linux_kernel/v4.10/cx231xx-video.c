static int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_8 = NULL , * V_9 ;
struct V_10 * V_11 , * V_12 = NULL ;
int V_13 , V_14 = 0 ;
if ( ! V_4 )
return 0 ;
F_3 (entity, mdev) {
if ( V_7 -> V_15 == V_16 ) {
V_8 = V_7 ;
break;
}
}
if ( ! V_8 )
return 0 ;
F_4 (link, &decoder->links, list) {
if ( V_11 -> V_17 -> V_7 == V_8 ) {
V_12 = V_11 ;
if ( V_11 -> V_18 & V_19 )
V_14 ++ ;
break;
}
}
if ( V_14 == 1 || ! V_12 )
return 0 ;
V_9 = V_12 -> V_9 -> V_7 ;
F_4 (link, &source->links, list) {
struct V_6 * V_17 ;
int V_18 = 0 ;
V_17 = V_11 -> V_17 -> V_7 ;
if ( V_17 == V_7 )
V_18 = V_19 ;
V_13 = F_5 ( V_11 , V_18 ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_2 ,
L_1 ,
V_9 -> V_20 , V_17 -> V_20 ,
V_18 ? L_2 : L_3 ,
V_13 ) ;
return V_13 ;
} else
F_7 ( V_2 -> V_2 ,
L_4 ,
V_9 -> V_20 , V_17 -> V_20 ,
V_18 ? L_5 : L_3 ) ;
}
#endif
return 0 ;
}
static inline void F_8 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_23 * V_24 )
{
F_9 ( L_6 , V_24 , V_24 -> V_25 . V_26 ) ;
V_24 -> V_25 . V_27 = V_28 ;
V_24 -> V_25 . V_29 ++ ;
F_10 ( & V_24 -> V_25 . V_30 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 . V_33 . V_24 = NULL ;
else
V_2 -> V_32 . V_34 . V_24 = NULL ;
F_11 ( & V_24 -> V_25 . V_35 ) ;
F_12 ( & V_24 -> V_25 . V_36 ) ;
}
static inline void F_13 ( struct V_1 * V_2 , int V_37 , int V_38 )
{
char * V_39 = L_7 ;
switch ( V_38 ) {
case - V_40 :
V_39 = L_8 ;
break;
case - V_41 :
V_39 = L_9 ;
break;
case - V_42 :
V_39 = L_10 ;
break;
case - V_43 :
V_39 = L_11 ;
break;
case - V_44 :
V_39 = L_12 ;
break;
case - V_45 :
V_39 = L_13 ;
break;
case - V_46 :
V_39 = L_14 ;
break;
case - V_47 :
V_39 = L_15 ;
break;
}
if ( V_37 < 0 ) {
F_9 ( L_16 , V_38 , V_39 ) ;
} else {
F_9 ( L_17 ,
V_37 , V_38 , V_39 ) ;
}
}
static inline void F_14 ( struct V_21 * V_22 ,
struct V_23 * * V_24 )
{
struct V_48 * V_49 =
F_15 ( V_22 , struct V_48 , V_50 ) ;
struct V_1 * V_2 = F_15 ( V_49 , struct V_1 , V_32 ) ;
char * V_51 ;
if ( F_16 ( & V_22 -> V_52 ) ) {
F_9 ( L_18 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 . V_33 . V_24 = NULL ;
else
V_2 -> V_32 . V_34 . V_24 = NULL ;
* V_24 = NULL ;
return;
}
* V_24 = F_17 ( V_22 -> V_52 . V_53 , struct V_23 , V_25 . V_35 ) ;
V_51 = F_18 ( & ( * V_24 ) -> V_25 ) ;
memset ( V_51 , 0 , ( * V_24 ) -> V_25 . V_54 ) ;
if ( V_2 -> V_31 )
V_2 -> V_32 . V_33 . V_24 = * V_24 ;
else
V_2 -> V_32 . V_34 . V_24 = * V_24 ;
return;
}
static inline int F_19 ( struct V_1 * V_2 , struct V_55 * V_55 )
{
struct V_21 * V_22 = V_55 -> V_56 ;
int V_26 ;
unsigned char * V_57 ;
T_1 V_58 = 0 , V_59 = 0 ;
T_2 V_60 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_27 & V_61 )
return 0 ;
if ( V_55 -> V_38 < 0 ) {
F_13 ( V_2 , - 1 , V_55 -> V_38 ) ;
if ( V_55 -> V_38 == - V_40 )
return 0 ;
}
for ( V_26 = 0 ; V_26 < V_55 -> V_62 ; V_26 ++ ) {
int V_38 = V_55 -> V_63 [ V_26 ] . V_38 ;
if ( V_38 < 0 ) {
F_13 ( V_2 , V_26 , V_38 ) ;
if ( V_55 -> V_63 [ V_26 ] . V_38 != - V_45 )
continue;
}
if ( V_55 -> V_63 [ V_26 ] . V_64 <= 0 ) {
continue;
}
if ( V_55 -> V_63 [ V_26 ] . V_64 >
V_2 -> V_32 . V_65 ) {
F_9 ( L_19 ) ;
continue;
}
V_57 = V_55 -> V_66 + V_55 -> V_63 [ V_26 ] . V_67 ;
V_59 = V_55 -> V_63 [ V_26 ] . V_64 ;
V_58 = 0 ;
if ( V_22 -> V_68 ) {
V_60 = V_22 -> V_69 ;
} else {
V_60 =
F_20 ( V_57 ,
V_22 -> V_70 ,
& V_58 ) ;
}
V_60 &= 0xF0 ;
if ( V_60 ) {
V_58 += F_21 ( V_2 , V_22 ,
V_60 ,
V_57 + V_58 ,
V_59 - V_58 ) ;
}
while ( V_58 < V_59 ) {
T_1 V_71 = 0 ;
V_60 = F_22 (
V_57 + V_58 ,
V_59 - V_58 ,
& V_71 ) ;
V_58 += V_71 ;
V_60 &= 0xF0 ;
if ( V_60 && ( V_58 < V_59 ) ) {
V_58 += F_21 ( V_2 ,
V_22 , V_60 ,
V_57 + V_58 ,
V_59 - V_58 ) ;
}
}
memcpy ( V_22 -> V_70 , V_57 + V_59 - 4 , 4 ) ;
V_58 = 0 ;
}
return 1 ;
}
static inline int F_23 ( struct V_1 * V_2 , struct V_55 * V_55 )
{
struct V_21 * V_22 = V_55 -> V_56 ;
unsigned char * V_57 ;
T_1 V_58 = 0 , V_59 = 0 ;
T_2 V_60 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_27 & V_61 )
return 0 ;
if ( V_55 -> V_38 < 0 ) {
F_13 ( V_2 , - 1 , V_55 -> V_38 ) ;
if ( V_55 -> V_38 == - V_40 )
return 0 ;
}
if ( 1 ) {
V_57 = V_55 -> V_66 ;
V_59 = V_55 -> V_64 ;
V_58 = 0 ;
if ( V_22 -> V_68 ) {
V_60 = V_22 -> V_69 ;
} else {
V_60 =
F_20 ( V_57 ,
V_22 -> V_70 ,
& V_58 ) ;
}
V_60 &= 0xF0 ;
if ( V_60 ) {
V_58 += F_21 ( V_2 , V_22 ,
V_60 ,
V_57 + V_58 ,
V_59 - V_58 ) ;
}
while ( V_58 < V_59 ) {
T_1 V_71 = 0 ;
V_60 = F_22 (
V_57 + V_58 ,
V_59 - V_58 ,
& V_71 ) ;
V_58 += V_71 ;
V_60 &= 0xF0 ;
if ( V_60 && ( V_58 < V_59 ) ) {
V_58 += F_21 ( V_2 ,
V_22 , V_60 ,
V_57 + V_58 ,
V_59 - V_58 ) ;
}
}
memcpy ( V_22 -> V_70 , V_57 + V_59 - 4 , 4 ) ;
V_58 = 0 ;
}
return 1 ;
}
T_2 F_20 ( T_2 * V_57 , T_2 * V_70 ,
T_1 * V_72 )
{
T_1 V_71 ;
T_2 V_73 [ 8 ] ;
T_2 V_60 = 0 ;
* V_72 = 0 ;
memcpy ( V_73 , V_70 , 4 ) ;
memcpy ( V_73 + 4 , V_57 , 4 ) ;
V_60 = F_22 ( ( T_2 * ) & V_73 , 8 ,
& V_71 ) ;
if ( V_60 ) {
* V_72 = V_71 - 4 ;
}
return V_60 ;
}
T_2 F_22 ( T_2 * V_57 , T_1 V_59 , T_1 * V_72 )
{
T_1 V_26 ;
T_2 V_60 = 0 ;
if ( V_59 < 4 ) {
* V_72 = V_59 ;
return 0 ;
}
for ( V_26 = 0 ; V_26 < ( V_59 - 3 ) ; V_26 ++ ) {
if ( ( V_57 [ V_26 ] == 0xFF ) &&
( V_57 [ V_26 + 1 ] == 0x00 ) && ( V_57 [ V_26 + 2 ] == 0x00 ) ) {
* V_72 = V_26 + 4 ;
V_60 = V_57 [ V_26 + 3 ] ;
return V_60 ;
}
}
* V_72 = V_59 ;
return 0 ;
}
T_1 F_21 ( struct V_1 * V_2 ,
struct V_21 * V_22 , T_2 V_60 ,
T_2 * V_57 , T_1 V_59 )
{
T_1 V_74 = 0 ;
int V_75 = - 1 ;
switch ( V_60 ) {
case V_76 :
if ( ( V_59 > 3 ) && ( V_57 [ 0 ] == 0xFF ) &&
( V_57 [ 1 ] == 0x00 ) && ( V_57 [ 2 ] == 0x00 ) &&
( ( V_57 [ 3 ] == V_77 ) ||
( V_57 [ 3 ] == V_78 ) ||
( V_57 [ 3 ] == V_79 ) ||
( V_57 [ 3 ] == V_80 ) ) )
return V_74 ;
V_75 = 1 ;
break;
case V_81 :
if ( ( V_59 > 3 ) && ( V_57 [ 0 ] == 0xFF ) &&
( V_57 [ 1 ] == 0x00 ) && ( V_57 [ 2 ] == 0x00 ) &&
( ( V_57 [ 3 ] == V_77 ) ||
( V_57 [ 3 ] == V_78 ) ||
( V_57 [ 3 ] == V_79 ) ||
( V_57 [ 3 ] == V_80 ) ) )
return V_74 ;
V_75 = 2 ;
break;
}
V_22 -> V_69 = V_60 ;
V_74 = F_24 ( V_2 , V_22 , V_57 ,
V_59 , V_75 ) ;
return V_74 ;
}
T_1 F_24 ( struct V_1 * V_2 ,
struct V_21 * V_22 , T_2 * V_82 ,
T_1 V_83 , int V_84 )
{
T_1 V_85 ;
struct V_23 * V_24 ;
T_1 V_86 = V_2 -> V_87 * 2 ;
if ( V_22 -> V_75 != V_84 )
F_25 ( V_2 , V_22 ) ;
if ( V_2 -> V_31 )
V_24 = V_2 -> V_32 . V_33 . V_24 ;
else
V_24 = V_2 -> V_32 . V_34 . V_24 ;
V_22 -> V_75 = V_84 ;
V_85 = V_22 -> V_88 ;
if ( V_85 > V_83 )
V_85 = V_83 ;
if ( V_22 -> V_89 >= V_22 -> V_90 ) {
V_22 -> V_88 -= V_85 ;
V_22 -> V_68 = ( V_22 -> V_88 == 0 ) ?
0 : 1 ;
return 0 ;
}
V_22 -> V_68 = 1 ;
if ( ! V_24 ) {
V_22 -> V_88 -= V_85 ;
V_22 -> V_68 = ( V_22 -> V_88 == 0 )
? 0 : 1 ;
return V_85 ;
}
F_26 ( V_2 , V_22 , V_82 , V_85 ) ;
V_22 -> V_91 += V_85 ;
V_22 -> V_88 -= V_85 ;
if ( V_22 -> V_88 == 0 ) {
V_22 -> V_88 = V_86 ;
V_22 -> V_89 ++ ;
V_22 -> V_68 = 0 ;
if ( F_27 ( V_2 , V_22 ) && V_24 ) {
F_8 ( V_2 , V_22 , V_24 ) ;
V_22 -> V_91 = 0 ;
V_24 = NULL ;
V_22 -> V_89 = 0 ;
}
}
return V_85 ;
}
void F_25 ( struct V_1 * V_2 ,
struct V_21 * V_22 )
{
struct V_23 * V_24 ;
if ( V_22 -> V_75 == 1 ) {
if ( V_22 -> V_89 >= V_22 -> V_90 )
V_22 -> V_92 = 1 ;
else
V_22 -> V_92 = 0 ;
}
if ( V_2 -> V_31 )
V_24 = V_2 -> V_32 . V_33 . V_24 ;
else
V_24 = V_2 -> V_32 . V_34 . V_24 ;
if ( V_24 == NULL ) {
F_14 ( V_22 , & V_24 ) ;
V_22 -> V_91 = 0 ;
V_22 -> V_92 = 0 ;
V_22 -> V_75 = - 1 ;
}
V_22 -> V_88 = V_2 -> V_87 << 1 ;
V_22 -> V_89 = 0 ;
}
int F_26 ( struct V_1 * V_2 , struct V_21 * V_22 ,
T_2 * V_57 , T_1 V_85 )
{
T_2 * V_93 = NULL ;
T_1 V_94 = 0 ;
struct V_23 * V_24 ;
T_1 V_86 = V_2 -> V_87 << 1 ;
void * V_95 ;
int V_67 , V_96 ;
if ( V_2 -> V_31 )
V_24 = V_2 -> V_32 . V_33 . V_24 ;
else
V_24 = V_2 -> V_32 . V_34 . V_24 ;
if ( V_24 == NULL )
return - 1 ;
V_93 = F_18 ( & V_24 -> V_25 ) ;
V_94 = V_86 - V_22 -> V_88 ;
V_67 = ( V_22 -> V_75 == 1 ) ? 0 : V_86 ;
V_95 = V_93 + V_67 ;
V_95 += ( V_22 -> V_89 * V_86 * 2 ) ;
V_95 += V_94 ;
V_96 = V_22 -> V_88 > V_85 ?
V_85 : V_22 -> V_88 ;
if ( ( T_2 * ) ( V_95 + V_96 ) > ( T_2 * ) ( V_93 + V_24 -> V_25 . V_54 ) )
return 0 ;
F_28 ( ( V_97 * ) V_57 , ( V_97 * ) V_95 , ( V_97 ) V_96 ) ;
return 0 ;
}
void F_28 ( V_97 * V_98 , V_97 * V_99 , V_97 V_100 )
{
V_97 V_26 ;
if ( V_100 <= 0 )
return;
for ( V_26 = 0 ; V_26 < V_100 / 2 ; V_26 ++ )
V_99 [ V_26 ] = ( V_98 [ V_26 ] << 8 ) | ( V_98 [ V_26 ] >> 8 ) ;
}
T_2 F_27 ( struct V_1 * V_2 , struct V_21 * V_22 )
{
T_2 V_101 = 0 ;
V_101 = ( ( V_22 -> V_75 == 2 ) &&
( V_22 -> V_89 >= V_22 -> V_90 ) &&
V_22 -> V_92 ) ;
return V_101 ;
}
static int
F_29 ( struct V_102 * V_103 , unsigned int * V_104 , unsigned int * V_54 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_1 * V_2 = V_106 -> V_2 ;
* V_54 = ( V_106 -> V_2 -> V_87 * V_106 -> V_2 -> V_108 * V_2 -> V_109 -> V_110 + 7 ) >> 3 ;
if ( 0 == * V_104 )
* V_104 = V_111 ;
if ( * V_104 < V_112 )
* V_104 = V_112 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_102 * V_103 , struct V_23 * V_24 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_1 * V_2 = V_106 -> V_2 ;
unsigned long V_18 = 0 ;
F_31 ( F_32 () ) ;
F_33 ( & V_2 -> V_32 . V_113 , V_18 ) ;
if ( V_2 -> V_31 ) {
if ( V_2 -> V_32 . V_33 . V_24 == V_24 )
V_2 -> V_32 . V_33 . V_24 = NULL ;
} else {
if ( V_2 -> V_32 . V_34 . V_24 == V_24 )
V_2 -> V_32 . V_34 . V_24 = NULL ;
}
F_34 ( & V_2 -> V_32 . V_113 , V_18 ) ;
F_35 ( & V_24 -> V_25 ) ;
V_24 -> V_25 . V_27 = V_114 ;
}
static int
F_36 ( struct V_102 * V_103 , struct V_115 * V_25 ,
enum V_116 V_117 )
{
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_23 * V_24 =
F_15 ( V_25 , struct V_23 , V_25 ) ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 = 0 , V_119 = 0 ;
V_24 -> V_25 . V_54 = ( V_106 -> V_2 -> V_87 * V_106 -> V_2 -> V_108 * V_2 -> V_109 -> V_110
+ 7 ) >> 3 ;
if ( 0 != V_24 -> V_25 . V_120 && V_24 -> V_25 . V_121 < V_24 -> V_25 . V_54 )
return - V_122 ;
V_24 -> V_25 . V_87 = V_2 -> V_87 ;
V_24 -> V_25 . V_108 = V_2 -> V_108 ;
V_24 -> V_25 . V_117 = V_117 ;
if ( V_114 == V_24 -> V_25 . V_27 ) {
V_118 = F_37 ( V_103 , & V_24 -> V_25 , NULL ) ;
if ( V_118 < 0 )
goto V_123;
}
if ( V_2 -> V_31 ) {
if ( ! V_2 -> V_32 . V_33 . V_124 )
V_119 = 1 ;
} else {
if ( ! V_2 -> V_32 . V_34 . V_124 )
V_119 = 1 ;
}
F_7 ( V_2 -> V_2 ,
L_20 ,
V_119 , V_2 -> V_32 . V_65 ) ;
if ( V_119 ) {
V_2 -> V_125 = 0 ;
if ( V_2 -> V_31 )
V_118 = F_38 ( V_2 , V_126 ,
V_127 ,
V_2 -> V_32 . V_65 ,
F_19 ) ;
else
V_118 = F_39 ( V_2 , V_126 ,
V_127 ,
V_2 -> V_32 . V_65 ,
F_23 ) ;
if ( V_118 < 0 )
goto V_123;
}
V_24 -> V_25 . V_27 = V_128 ;
return 0 ;
V_123:
F_30 ( V_103 , V_24 ) ;
return V_118 ;
}
static void F_40 ( struct V_102 * V_103 , struct V_115 * V_25 )
{
struct V_23 * V_24 =
F_15 ( V_25 , struct V_23 , V_25 ) ;
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_21 * V_50 = & V_2 -> V_32 . V_50 ;
V_24 -> V_25 . V_27 = V_129 ;
F_41 ( & V_24 -> V_25 . V_35 , & V_50 -> V_52 ) ;
}
static void F_42 ( struct V_102 * V_103 ,
struct V_115 * V_25 )
{
struct V_23 * V_24 =
F_15 ( V_25 , struct V_23 , V_25 ) ;
struct V_105 * V_106 = V_103 -> V_107 ;
struct V_1 * V_2 = (struct V_1 * ) V_106 -> V_2 ;
F_9 ( L_21 ) ;
F_30 ( V_103 , V_24 ) ;
}
void F_43 ( struct V_1 * V_2 , int V_130 )
{
V_2 -> V_131 = V_130 ;
V_2 -> V_132 = F_44 ( V_130 ) -> V_133 ;
F_45 ( V_2 , V_130 ) ;
F_46 ( V_2 , V_134 , V_135 , F_44 ( V_130 ) -> V_136 , 0 , 0 ) ;
F_47 ( V_2 , V_2 -> V_132 ) ;
F_7 ( V_2 -> V_2 , L_22 , V_130 ) ;
F_48 ( V_2 ) ;
}
static int F_49 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 = 0 ;
if ( V_106 -> V_137 )
return V_118 ;
if ( V_106 -> type == V_138 ) {
if ( V_2 -> V_137 )
return - V_139 ;
V_2 -> V_137 = 1 ;
} else if ( V_106 -> type == V_140 ) {
if ( V_2 -> V_141 )
return - V_139 ;
V_2 -> V_141 = 1 ;
} else
return - V_122 ;
V_106 -> V_137 = 1 ;
return V_118 ;
}
static int F_50 ( struct V_105 * V_106 )
{
return V_106 -> V_137 ;
}
static void F_51 ( struct V_105 * V_106 )
{
struct V_1 * V_2 = V_106 -> V_2 ;
V_106 -> V_137 = 0 ;
if ( V_106 -> type == V_138 )
V_2 -> V_137 = 0 ;
if ( V_106 -> type == V_140 )
V_2 -> V_141 = 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 & V_61 ) {
F_6 ( V_2 -> V_2 , L_23 ) ;
return - V_142 ;
}
return 0 ;
}
static int F_53 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
V_146 -> V_147 . V_148 . V_87 = V_2 -> V_87 ;
V_146 -> V_147 . V_148 . V_108 = V_2 -> V_108 ;
V_146 -> V_147 . V_148 . V_149 = V_2 -> V_109 -> V_150 ;
V_146 -> V_147 . V_148 . V_151 = ( V_2 -> V_87 * V_2 -> V_109 -> V_110 + 7 ) >> 3 ;
V_146 -> V_147 . V_148 . V_152 = V_146 -> V_147 . V_148 . V_151 * V_2 -> V_108 ;
V_146 -> V_147 . V_148 . V_153 = V_154 ;
V_146 -> V_147 . V_148 . V_117 = V_155 ;
return 0 ;
}
static struct V_156 * F_54 ( unsigned int V_150 )
{
unsigned int V_26 ;
for ( V_26 = 0 ; V_26 < F_55 ( V_109 ) ; V_26 ++ )
if ( V_109 [ V_26 ] . V_150 == V_150 )
return & V_109 [ V_26 ] ;
return NULL ;
}
static int F_56 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
unsigned int V_87 = V_146 -> V_147 . V_148 . V_87 ;
unsigned int V_108 = V_146 -> V_147 . V_148 . V_108 ;
unsigned int V_157 = F_57 ( V_2 ) ;
unsigned int V_158 = F_58 ( V_2 ) ;
struct V_156 * V_147 ;
V_147 = F_54 ( V_146 -> V_147 . V_148 . V_149 ) ;
if ( ! V_147 ) {
F_59 ( L_24 ,
V_146 -> V_147 . V_148 . V_149 ) ;
return - V_122 ;
}
F_60 ( & V_87 , 48 , V_157 , 1 , & V_108 , 32 , V_158 , 1 , 0 ) ;
V_146 -> V_147 . V_148 . V_87 = V_87 ;
V_146 -> V_147 . V_148 . V_108 = V_108 ;
V_146 -> V_147 . V_148 . V_149 = V_147 -> V_150 ;
V_146 -> V_147 . V_148 . V_151 = ( V_87 * V_147 -> V_110 + 7 ) >> 3 ;
V_146 -> V_147 . V_148 . V_152 = V_146 -> V_147 . V_148 . V_151 * V_108 ;
V_146 -> V_147 . V_148 . V_153 = V_154 ;
V_146 -> V_147 . V_148 . V_117 = V_155 ;
return 0 ;
}
static int F_61 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
struct V_156 * V_147 ;
struct V_159 V_109 = {
. V_160 = V_161 ,
} ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
F_56 ( V_143 , V_144 , V_146 ) ;
V_147 = F_54 ( V_146 -> V_147 . V_148 . V_149 ) ;
if ( ! V_147 )
return - V_122 ;
if ( F_62 ( & V_106 -> V_162 ) ) {
F_6 ( V_2 -> V_2 , L_25 , V_163 ) ;
return - V_139 ;
}
if ( V_2 -> V_137 && ! V_106 -> V_137 ) {
F_6 ( V_2 -> V_2 ,
L_26 , V_163 ) ;
return - V_139 ;
}
V_2 -> V_87 = V_146 -> V_147 . V_148 . V_87 ;
V_2 -> V_108 = V_146 -> V_147 . V_148 . V_108 ;
V_2 -> V_109 = V_147 ;
F_63 ( & V_109 . V_109 , & V_146 -> V_147 . V_148 , V_164 ) ;
F_64 ( V_2 , V_165 , V_166 , NULL , & V_109 ) ;
F_65 ( & V_146 -> V_147 . V_148 , & V_109 . V_109 ) ;
return V_118 ;
}
static int F_66 ( struct V_143 * V_143 , void * V_144 , T_3 * V_167 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
* V_167 = V_2 -> V_168 ;
return 0 ;
}
static int F_67 ( struct V_143 * V_143 , void * V_144 , T_3 V_168 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_159 V_109 = {
. V_160 = V_161 ,
} ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_2 -> V_168 == V_168 )
return 0 ;
if ( F_62 ( & V_106 -> V_162 ) )
return - V_139 ;
V_2 -> V_168 = V_168 ;
V_2 -> V_87 = 720 ;
V_2 -> V_108 = ( V_2 -> V_168 & V_169 ) ? 576 : 480 ;
F_64 ( V_2 , V_134 , V_170 , V_2 -> V_168 ) ;
V_109 . V_109 . V_171 = V_164 ;
V_109 . V_109 . V_87 = V_2 -> V_87 ;
V_109 . V_109 . V_108 = V_2 -> V_108 ;
F_64 ( V_2 , V_165 , V_166 , NULL , & V_109 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
void F_68 ( struct V_1 * V_2 )
{
#if F_69 ( F_2 )
int V_13 , V_26 ;
for ( V_26 = 0 ; V_26 < V_172 ; V_26 ++ ) {
struct V_6 * V_173 = & V_2 -> V_174 [ V_26 ] ;
if ( ! F_44 ( V_26 ) -> type )
break;
V_173 -> V_20 = V_175 [ F_44 ( V_26 ) -> type ] ;
V_173 -> V_18 = V_176 ;
V_2 -> V_177 [ V_26 ] . V_18 = V_178 ;
switch ( F_44 ( V_26 ) -> type ) {
case V_179 :
V_173 -> V_15 = V_180 ;
break;
case V_181 :
V_173 -> V_15 = V_182 ;
break;
case V_183 :
case V_184 :
case V_185 :
if ( V_2 -> V_186 == V_187 )
continue;
default:
V_173 -> V_15 = V_188 ;
break;
}
V_13 = F_70 ( V_173 , 1 , & V_2 -> V_177 [ V_26 ] ) ;
if ( V_13 < 0 )
F_71 ( L_27 , V_26 ) ;
V_13 = F_72 ( V_2 -> V_5 , V_173 ) ;
if ( V_13 < 0 )
F_71 ( L_28 , V_26 ) ;
}
#endif
}
int F_73 ( struct V_143 * V_143 , void * V_144 ,
struct V_189 * V_26 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
T_1 V_190 ;
unsigned int V_191 ;
int V_13 ;
V_191 = V_26 -> V_130 ;
if ( V_191 >= V_172 )
return - V_122 ;
if ( 0 == F_44 ( V_191 ) -> type )
return - V_122 ;
V_26 -> V_130 = V_191 ;
V_26 -> type = V_192 ;
strcpy ( V_26 -> V_20 , V_175 [ F_44 ( V_191 ) -> type ] ) ;
if ( ( V_183 == F_44 ( V_191 ) -> type ) ||
( V_184 == F_44 ( V_191 ) -> type ) )
V_26 -> type = V_193 ;
V_26 -> V_194 = V_2 -> V_195 . V_196 ;
if ( V_191 == V_2 -> V_131 ) {
V_13 = F_74 ( V_2 , V_197 ,
V_198 , 2 , & V_190 , 4 ) ;
if ( V_13 > 0 ) {
if ( ( V_190 & V_199 ) == 0x00 )
V_26 -> V_38 |= V_200 ;
if ( ( V_190 & V_201 ) == 0x00 )
V_26 -> V_38 |= V_202 ;
}
}
return 0 ;
}
int F_75 ( struct V_143 * V_143 , void * V_144 , unsigned int * V_26 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
* V_26 = V_2 -> V_131 ;
return 0 ;
}
int F_76 ( struct V_143 * V_143 , void * V_144 , unsigned int V_26 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_2 -> V_125 = 0 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( V_26 >= V_172 )
return - V_122 ;
if ( 0 == F_44 ( V_26 ) -> type )
return - V_122 ;
F_43 ( V_2 , V_26 ) ;
if ( F_44 ( V_26 ) -> type == V_183 ||
F_44 ( V_26 ) -> type == V_184 ) {
F_64 ( V_2 , V_134 , V_170 , V_2 -> V_168 ) ;
}
return 0 ;
}
int F_77 ( struct V_143 * V_143 , void * V_144 , struct V_203 * V_204 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( 0 != V_204 -> V_130 )
return - V_122 ;
strcpy ( V_204 -> V_20 , L_29 ) ;
V_204 -> type = V_205 ;
V_204 -> V_206 = V_207 ;
V_204 -> V_208 = 0xffffffffUL ;
V_204 -> signal = 0xffff ;
F_64 ( V_2 , V_209 , V_210 , V_204 ) ;
return 0 ;
}
int F_78 ( struct V_143 * V_143 , void * V_144 , const struct V_203 * V_204 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( 0 != V_204 -> V_130 )
return - V_122 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
int F_79 ( struct V_143 * V_143 , void * V_144 ,
struct V_211 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
if ( V_146 -> V_209 )
return - V_122 ;
V_146 -> V_212 = V_2 -> V_213 ;
return 0 ;
}
int F_80 ( struct V_143 * V_143 , void * V_144 ,
const struct V_211 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
struct V_211 V_214 = * V_146 ;
int V_118 ;
T_1 V_215 = 5400000 ;
F_7 ( V_2 -> V_2 ,
L_30 ,
V_146 -> V_212 , V_146 -> type ) ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( 0 != V_146 -> V_209 )
return - V_122 ;
V_118 = F_81 ( V_2 ) ;
F_64 ( V_2 , V_209 , V_216 , V_146 ) ;
F_64 ( V_2 , V_209 , V_217 , & V_214 ) ;
V_2 -> V_213 = V_214 . V_212 ;
V_118 = F_82 ( V_2 ) ;
if ( V_2 -> V_186 == V_218 ) {
if ( V_2 -> V_168 & ( V_219 | V_220 ) )
V_215 = 5400000 ;
else if ( V_2 -> V_168 & V_221 )
V_215 = 6000000 ;
else if ( V_2 -> V_168 & ( V_222 | V_223 ) )
V_215 = 6900000 ;
else if ( V_2 -> V_168 & V_224 )
V_215 = 7100000 ;
else if ( V_2 -> V_168 & V_225 )
V_215 = 7250000 ;
else if ( V_2 -> V_168 & V_226 )
V_215 = 6900000 ;
else if ( V_2 -> V_168 & V_227 )
V_215 = 1250000 ;
F_7 ( V_2 -> V_2 ,
L_31 , V_215 ) ;
F_83 ( V_2 , V_215 , 1 , 1 ) ;
F_84 ( V_2 ) ;
}
F_7 ( V_2 -> V_2 , L_32 , V_146 -> V_212 ) ;
return V_118 ;
}
int F_85 ( struct V_143 * V_143 , void * V_106 ,
struct V_228 * V_229 )
{
switch ( V_229 -> V_230 . V_231 ) {
case 0 :
return 0 ;
case 1 :
F_86 ( V_229 -> V_20 , L_33 , sizeof( V_229 -> V_20 ) ) ;
return 0 ;
case 2 :
F_86 ( V_229 -> V_20 , L_34 , sizeof( V_229 -> V_20 ) ) ;
return 0 ;
case 3 :
F_86 ( V_229 -> V_20 , L_35 , sizeof( V_229 -> V_20 ) ) ;
return 0 ;
case 4 :
F_86 ( V_229 -> V_20 , L_36 , sizeof( V_229 -> V_20 ) ) ;
return 0 ;
case 5 :
F_86 ( V_229 -> V_20 , L_37 , sizeof( V_229 -> V_20 ) ) ;
return 0 ;
case 6 :
F_86 ( V_229 -> V_20 , L_38 , sizeof( V_229 -> V_20 ) ) ;
return 0 ;
}
return - V_122 ;
}
int F_87 ( struct V_143 * V_143 , void * V_144 ,
struct V_232 * V_233 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_13 ;
T_2 V_234 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_235 = 0 ;
switch ( V_233 -> V_230 . V_231 ) {
case 0 :
V_13 = F_88 ( V_2 , V_236 ,
( V_97 ) V_233 -> V_233 , V_234 , 4 ) ;
V_233 -> V_237 = V_234 [ 0 ] | V_234 [ 1 ] << 8 |
V_234 [ 2 ] << 16 | V_234 [ 3 ] << 24 ;
V_233 -> V_54 = 4 ;
break;
case 1 :
V_13 = F_74 ( V_2 , V_238 ,
( V_97 ) V_233 -> V_233 , 2 , & V_235 , 1 ) ;
V_233 -> V_237 = V_235 ;
V_233 -> V_54 = 1 ;
break;
case 2 :
V_13 = F_74 ( V_2 , V_197 ,
( V_97 ) V_233 -> V_233 , 2 , & V_235 , 1 ) ;
V_233 -> V_237 = V_235 ;
V_233 -> V_54 = 1 ;
break;
case 3 :
V_13 = F_74 ( V_2 , V_239 ,
( V_97 ) V_233 -> V_233 , 1 , & V_235 , 1 ) ;
V_233 -> V_237 = V_235 ;
V_233 -> V_54 = 1 ;
break;
case 4 :
V_13 = F_74 ( V_2 , V_238 ,
( V_97 ) V_233 -> V_233 , 2 , & V_235 , 4 ) ;
V_233 -> V_237 = V_235 ;
V_233 -> V_54 = 4 ;
break;
case 5 :
V_13 = F_74 ( V_2 , V_197 ,
( V_97 ) V_233 -> V_233 , 2 , & V_235 , 4 ) ;
V_233 -> V_237 = V_235 ;
V_233 -> V_54 = 4 ;
break;
case 6 :
V_13 = F_74 ( V_2 , V_239 ,
( V_97 ) V_233 -> V_233 , 1 , & V_235 , 4 ) ;
V_233 -> V_237 = V_235 ;
V_233 -> V_54 = 4 ;
break;
default:
return - V_122 ;
}
return V_13 < 0 ? V_13 : 0 ;
}
int F_89 ( struct V_143 * V_143 , void * V_144 ,
const struct V_232 * V_233 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_13 ;
T_2 V_235 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_233 -> V_230 . V_231 ) {
case 0 :
V_235 [ 0 ] = ( T_2 ) V_233 -> V_237 ;
V_235 [ 1 ] = ( T_2 ) ( V_233 -> V_237 >> 8 ) ;
V_235 [ 2 ] = ( T_2 ) ( V_233 -> V_237 >> 16 ) ;
V_235 [ 3 ] = ( T_2 ) ( V_233 -> V_237 >> 24 ) ;
V_13 = F_90 ( V_2 , V_240 ,
( V_97 ) V_233 -> V_233 , V_235 , 4 ) ;
break;
case 1 :
V_13 = F_91 ( V_2 , V_238 ,
( V_97 ) V_233 -> V_233 , 2 , V_233 -> V_237 , 1 ) ;
break;
case 2 :
V_13 = F_91 ( V_2 , V_197 ,
( V_97 ) V_233 -> V_233 , 2 , V_233 -> V_237 , 1 ) ;
break;
case 3 :
V_13 = F_91 ( V_2 , V_239 ,
( V_97 ) V_233 -> V_233 , 1 , V_233 -> V_237 , 1 ) ;
break;
case 4 :
V_13 = F_91 ( V_2 , V_238 ,
( V_97 ) V_233 -> V_233 , 2 , V_233 -> V_237 , 4 ) ;
break;
case 5 :
V_13 = F_91 ( V_2 , V_197 ,
( V_97 ) V_233 -> V_233 , 2 , V_233 -> V_237 , 4 ) ;
break;
case 6 :
V_13 = F_91 ( V_2 , V_239 ,
( V_97 ) V_233 -> V_233 , 1 , V_233 -> V_237 , 4 ) ;
break;
default:
return - V_122 ;
}
return V_13 < 0 ? V_13 : 0 ;
}
static int F_92 ( struct V_143 * V_143 , void * V_144 ,
struct V_241 * V_242 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
bool V_243 = V_2 -> V_168 & V_169 ;
if ( V_242 -> type != V_138 )
return - V_122 ;
V_242 -> V_244 . V_245 = 0 ;
V_242 -> V_244 . V_246 = 0 ;
V_242 -> V_244 . V_87 = V_2 -> V_87 ;
V_242 -> V_244 . V_108 = V_2 -> V_108 ;
V_242 -> V_247 = V_242 -> V_244 ;
V_242 -> V_248 . V_249 = V_243 ? 54 : 11 ;
V_242 -> V_248 . V_250 = V_243 ? 59 : 10 ;
return 0 ;
}
static int F_93 ( struct V_143 * V_143 , void * V_144 ,
enum V_251 type )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
V_118 = F_49 ( V_106 ) ;
if ( F_94 ( V_118 >= 0 ) )
V_118 = F_95 ( & V_106 -> V_162 ) ;
F_64 ( V_2 , V_134 , V_252 , 1 ) ;
return V_118 ;
}
static int F_96 ( struct V_143 * V_143 , void * V_144 ,
enum V_251 type )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( type != V_106 -> type )
return - V_122 ;
F_46 ( V_2 , V_134 , V_252 , 0 ) ;
F_97 ( & V_106 -> V_162 ) ;
F_51 ( V_106 ) ;
return 0 ;
}
int F_98 ( struct V_143 * V_143 , void * V_144 ,
struct V_253 * V_254 )
{
struct V_255 * V_195 = F_99 ( V_143 ) ;
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
F_86 ( V_254 -> V_256 , L_39 , sizeof( V_254 -> V_256 ) ) ;
F_86 ( V_254 -> V_257 , V_258 [ V_2 -> V_259 ] . V_20 , sizeof( V_254 -> V_257 ) ) ;
F_100 ( V_2 -> V_260 , V_254 -> V_261 , sizeof( V_254 -> V_261 ) ) ;
if ( V_195 -> V_262 == V_263 )
V_254 -> V_264 = V_265 ;
else {
V_254 -> V_264 = V_266 | V_267 ;
if ( V_195 -> V_262 == V_268 )
V_254 -> V_264 |= V_269 ;
else
V_254 -> V_264 |= V_270 ;
}
if ( V_2 -> V_186 != V_187 )
V_254 -> V_264 |= V_271 ;
V_254 -> V_272 = V_254 -> V_264 | V_266 |
V_269 | V_270 |
V_267 | V_273 ;
if ( F_101 ( & V_2 -> V_274 ) )
V_254 -> V_272 |= V_265 ;
return 0 ;
}
static int F_102 ( struct V_143 * V_143 , void * V_144 ,
struct V_275 * V_146 )
{
if ( F_103 ( V_146 -> V_130 >= F_55 ( V_109 ) ) )
return - V_122 ;
F_86 ( V_146 -> V_276 , V_109 [ V_146 -> V_130 ] . V_20 , sizeof( V_146 -> V_276 ) ) ;
V_146 -> V_149 = V_109 [ V_146 -> V_130 ] . V_150 ;
return 0 ;
}
static int F_104 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
V_146 -> V_147 . V_277 . V_278 = 6750000 * 4 ;
V_146 -> V_147 . V_277 . V_279 = V_280 ;
V_146 -> V_147 . V_277 . V_281 = V_282 ;
V_146 -> V_147 . V_277 . V_67 = 0 ;
V_146 -> V_147 . V_277 . V_283 [ 0 ] = ( V_2 -> V_168 & V_169 ) ?
V_284 : V_285 ;
V_146 -> V_147 . V_277 . V_104 [ 0 ] = ( V_2 -> V_168 & V_169 ) ?
V_286 : V_287 ;
V_146 -> V_147 . V_277 . V_283 [ 1 ] = ( V_2 -> V_168 & V_169 ) ?
V_284 + 312 : V_285 + 263 ;
V_146 -> V_147 . V_277 . V_104 [ 1 ] = V_146 -> V_147 . V_277 . V_104 [ 0 ] ;
memset ( V_146 -> V_147 . V_277 . V_288 , 0 , sizeof( V_146 -> V_147 . V_277 . V_288 ) ) ;
return 0 ;
}
static int F_105 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
V_146 -> V_147 . V_277 . V_278 = 6750000 * 4 ;
V_146 -> V_147 . V_277 . V_279 = V_280 ;
V_146 -> V_147 . V_277 . V_281 = V_282 ;
V_146 -> V_147 . V_277 . V_67 = 0 ;
V_146 -> V_147 . V_277 . V_18 = 0 ;
V_146 -> V_147 . V_277 . V_283 [ 0 ] = ( V_2 -> V_168 & V_169 ) ?
V_284 : V_285 ;
V_146 -> V_147 . V_277 . V_104 [ 0 ] = ( V_2 -> V_168 & V_169 ) ?
V_286 : V_287 ;
V_146 -> V_147 . V_277 . V_283 [ 1 ] = ( V_2 -> V_168 & V_169 ) ?
V_284 + 312 : V_285 + 263 ;
V_146 -> V_147 . V_277 . V_104 [ 1 ] = V_146 -> V_147 . V_277 . V_104 [ 0 ] ;
memset ( V_146 -> V_147 . V_277 . V_288 , 0 , sizeof( V_146 -> V_147 . V_277 . V_288 ) ) ;
return 0 ;
}
static int F_106 ( struct V_143 * V_143 , void * V_144 ,
struct V_145 * V_146 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
if ( V_2 -> V_141 && ! V_106 -> V_137 ) {
F_6 ( V_2 -> V_2 ,
L_40 , V_163 ) ;
return - V_139 ;
}
return F_105 ( V_143 , V_144 , V_146 ) ;
}
static int F_107 ( struct V_143 * V_143 , void * V_144 ,
struct V_289 * V_290 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
return F_108 ( & V_106 -> V_162 , V_290 ) ;
}
static int F_109 ( struct V_143 * V_143 , void * V_144 , struct V_291 * V_292 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
return F_110 ( & V_106 -> V_162 , V_292 ) ;
}
static int F_111 ( struct V_143 * V_143 , void * V_144 , struct V_291 * V_292 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
return F_112 ( & V_106 -> V_162 , V_292 ) ;
}
static int F_113 ( struct V_143 * V_143 , void * V_144 , struct V_291 * V_292 )
{
struct V_105 * V_106 = V_144 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
return F_114 ( & V_106 -> V_162 , V_292 , V_143 -> V_293 & V_294 ) ;
}
static int F_115 ( struct V_143 * V_143 , void * V_144 , struct V_203 * V_204 )
{
struct V_1 * V_2 = ( (struct V_105 * ) V_144 ) -> V_2 ;
if ( V_204 -> V_130 )
return - V_122 ;
strcpy ( V_204 -> V_20 , L_41 ) ;
F_64 ( V_2 , V_209 , V_210 , V_204 ) ;
return 0 ;
}
static int F_116 ( struct V_143 * V_143 , void * V_144 , const struct V_203 * V_204 )
{
struct V_1 * V_2 = ( (struct V_105 * ) V_144 ) -> V_2 ;
if ( V_204 -> V_130 )
return - V_122 ;
F_64 ( V_2 , V_209 , V_295 , V_204 ) ;
return 0 ;
}
static int F_117 ( struct V_143 * V_296 )
{
int V_297 = 0 ;
struct V_255 * V_195 = F_99 ( V_296 ) ;
struct V_1 * V_2 = F_118 ( V_296 ) ;
struct V_105 * V_106 ;
enum V_251 V_298 = 0 ;
switch ( V_195 -> V_262 ) {
case V_299 :
V_298 = V_138 ;
break;
case V_268 :
V_298 = V_140 ;
break;
case V_263 :
V_297 = 1 ;
break;
}
F_59 ( L_42 ,
F_119 ( V_195 ) , V_300 [ V_298 ] ,
V_2 -> V_301 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
dev_err(dev->dev,
"Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_106 = F_120 ( sizeof( struct V_105 ) , V_302 ) ;
if ( ! V_106 )
return - V_303 ;
if ( F_121 ( & V_2 -> V_304 ) ) {
F_122 ( V_106 ) ;
return - V_305 ;
}
V_106 -> V_2 = V_2 ;
V_106 -> type = V_298 ;
V_296 -> V_306 = V_106 ;
F_123 ( & V_106 -> V_106 , V_195 ) ;
if ( V_106 -> type == V_138 && V_2 -> V_301 == 0 ) {
if ( V_2 -> V_307 . V_308 )
F_124 ( V_2 ,
V_309 ) ;
else
F_124 ( V_2 , V_310 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_125 ( V_2 ) ;
F_126 ( V_2 ) ;
V_2 -> V_131 = V_2 -> V_131 > 2 ? 2 : V_2 -> V_131 ;
}
if ( V_297 ) {
F_59 ( L_43 ) ;
F_64 ( V_2 , V_209 , V_311 ) ;
}
V_2 -> V_301 ++ ;
if ( V_106 -> type == V_138 )
F_127 ( & V_106 -> V_162 , & V_312 ,
NULL , & V_2 -> V_32 . V_113 ,
V_106 -> type , V_155 ,
sizeof( struct V_23 ) ,
V_106 , & V_2 -> V_304 ) ;
if ( V_106 -> type == V_140 ) {
F_128 ( V_2 , V_313 , 0 ) ;
F_127 ( & V_106 -> V_162 , & V_314 ,
NULL , & V_2 -> V_315 . V_113 ,
V_106 -> type , V_316 ,
sizeof( struct V_23 ) ,
V_106 , & V_2 -> V_304 ) ;
}
F_129 ( & V_2 -> V_304 ) ;
F_130 ( & V_106 -> V_106 ) ;
return 0 ;
}
void F_131 ( struct V_1 * V_2 )
{
if ( F_101 ( & V_2 -> V_274 ) )
F_132 ( & V_2 -> V_274 ) ;
if ( F_101 ( & V_2 -> V_317 ) ) {
F_133 ( V_2 -> V_2 , L_44 ,
F_119 ( & V_2 -> V_317 ) ) ;
F_132 ( & V_2 -> V_317 ) ;
}
if ( F_101 ( & V_2 -> V_195 ) ) {
F_133 ( V_2 -> V_2 , L_44 ,
F_119 ( & V_2 -> V_195 ) ) ;
if ( V_2 -> V_307 . V_318 )
F_134 ( V_2 ) ;
F_132 ( & V_2 -> V_195 ) ;
}
F_135 ( & V_2 -> V_319 ) ;
F_135 ( & V_2 -> V_320 ) ;
}
static int F_136 ( struct V_143 * V_296 )
{
struct V_105 * V_106 = V_296 -> V_306 ;
struct V_1 * V_2 = V_106 -> V_2 ;
F_59 ( L_45 , V_2 -> V_301 ) ;
F_59 ( L_45 , V_2 -> V_301 ) ;
if ( F_50 ( V_106 ) )
F_51 ( V_106 ) ;
if ( ! V_2 -> V_307 . V_321 )
if ( V_106 -> type == V_140 ) {
F_137 ( & V_106 -> V_162 ) ;
F_138 ( & V_106 -> V_162 ) ;
if ( V_2 -> V_27 & V_61 ) {
if ( F_139 ( & V_2 -> V_322 ) > 0 ) {
F_140 ( V_2 ) ;
V_106 -> V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_141 ( V_2 ) ;
if ( ! V_2 -> V_323 )
F_128 ( V_2 , V_313 , 0 ) ;
else
F_128 ( V_2 , V_324 , 0 ) ;
F_142 ( & V_106 -> V_106 ) ;
F_143 ( & V_106 -> V_106 ) ;
F_122 ( V_106 ) ;
V_2 -> V_301 -- ;
F_144 ( & V_2 -> V_325 ) ;
return 0 ;
}
F_142 ( & V_106 -> V_106 ) ;
V_2 -> V_301 -- ;
if ( ! V_2 -> V_301 ) {
F_137 ( & V_106 -> V_162 ) ;
F_138 ( & V_106 -> V_162 ) ;
if ( V_2 -> V_27 & V_61 ) {
F_140 ( V_2 ) ;
V_106 -> V_2 = NULL ;
return 0 ;
}
F_64 ( V_2 , V_326 , V_327 , 0 ) ;
if ( V_2 -> V_31 )
F_145 ( V_2 ) ;
else
F_146 ( V_2 ) ;
F_147 ( V_2 , V_328 ) ;
F_128 ( V_2 , V_329 , 0 ) ;
}
F_143 ( & V_106 -> V_106 ) ;
F_122 ( V_106 ) ;
F_144 ( & V_2 -> V_325 ) ;
return 0 ;
}
static int F_148 ( struct V_143 * V_296 )
{
struct V_105 * V_106 = V_296 -> V_306 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
F_149 ( & V_2 -> V_304 ) ;
V_118 = F_136 ( V_296 ) ;
F_129 ( & V_2 -> V_304 ) ;
return V_118 ;
}
static T_4
F_150 ( struct V_143 * V_296 , char T_5 * V_24 , T_6 V_104 ,
T_7 * V_91 )
{
struct V_105 * V_106 = V_296 -> V_306 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
if ( ( V_106 -> type == V_138 ) ||
( V_106 -> type == V_140 ) ) {
V_118 = F_49 ( V_106 ) ;
if ( F_103 ( V_118 < 0 ) )
return V_118 ;
if ( F_121 ( & V_2 -> V_304 ) )
return - V_305 ;
V_118 = F_151 ( & V_106 -> V_162 , V_24 , V_104 , V_91 , 0 ,
V_296 -> V_293 & V_294 ) ;
F_129 ( & V_2 -> V_304 ) ;
return V_118 ;
}
return 0 ;
}
static unsigned int F_152 ( struct V_143 * V_296 , T_8 * V_330 )
{
unsigned long V_331 = F_153 ( V_330 ) ;
struct V_105 * V_106 = V_296 -> V_306 ;
struct V_1 * V_2 = V_106 -> V_2 ;
unsigned V_332 = 0 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_333 ;
V_118 = F_49 ( V_106 ) ;
if ( F_103 ( V_118 < 0 ) )
return V_333 ;
if ( F_154 ( & V_106 -> V_106 ) )
V_332 |= V_334 ;
else
F_155 ( V_296 , & V_106 -> V_106 . V_330 , V_330 ) ;
if ( ! ( V_331 & ( V_335 | V_336 ) ) )
return V_332 ;
if ( ( V_138 == V_106 -> type ) ||
( V_140 == V_106 -> type ) ) {
F_149 ( & V_2 -> V_304 ) ;
V_332 |= F_156 ( V_296 , & V_106 -> V_162 , V_330 ) ;
F_129 ( & V_2 -> V_304 ) ;
return V_332 ;
}
return V_332 | V_333 ;
}
static int F_157 ( struct V_143 * V_296 , struct V_337 * V_338 )
{
struct V_105 * V_106 = V_296 -> V_306 ;
struct V_1 * V_2 = V_106 -> V_2 ;
int V_118 ;
V_118 = F_52 ( V_2 ) ;
if ( V_118 < 0 )
return V_118 ;
V_118 = F_49 ( V_106 ) ;
if ( F_103 ( V_118 < 0 ) )
return V_118 ;
if ( F_121 ( & V_2 -> V_304 ) )
return - V_305 ;
V_118 = F_158 ( & V_106 -> V_162 , V_338 ) ;
F_129 ( & V_2 -> V_304 ) ;
F_59 ( L_46 ,
( unsigned long ) V_338 -> V_339 ,
( unsigned long ) V_338 -> V_340 -
( unsigned long ) V_338 -> V_339 , V_118 ) ;
return V_118 ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_255 * V_341 ,
const struct V_255 * V_342 ,
const char * V_343 )
{
* V_341 = * V_342 ;
V_341 -> V_344 = & V_2 -> V_344 ;
V_341 -> V_345 = V_346 ;
V_341 -> V_304 = & V_2 -> V_304 ;
snprintf ( V_341 -> V_20 , sizeof( V_341 -> V_20 ) , L_47 , V_2 -> V_20 , V_343 ) ;
F_160 ( V_341 , V_2 ) ;
if ( V_2 -> V_186 == V_187 ) {
F_161 ( V_341 , V_347 ) ;
F_161 ( V_341 , V_348 ) ;
F_161 ( V_341 , V_349 ) ;
F_161 ( V_341 , V_350 ) ;
}
}
int F_162 ( struct V_1 * V_2 )
{
int V_13 ;
F_133 ( V_2 -> V_2 , L_48 , V_351 ) ;
V_2 -> V_168 = V_352 ;
V_2 -> V_87 = F_57 ( V_2 ) ;
V_2 -> V_108 = F_58 ( V_2 ) ;
V_2 -> V_353 = 0 ;
V_2 -> V_109 = & V_109 [ 0 ] ;
F_43 ( V_2 , V_2 -> V_131 ) ;
F_64 ( V_2 , V_134 , V_170 , V_2 -> V_168 ) ;
F_163 ( & V_2 -> V_319 , 10 ) ;
F_163 ( & V_2 -> V_320 , 5 ) ;
if ( V_2 -> V_354 ) {
F_164 ( & V_2 -> V_319 ,
V_2 -> V_354 -> V_319 , NULL ) ;
F_164 ( & V_2 -> V_320 ,
V_2 -> V_354 -> V_319 ,
V_355 ) ;
}
if ( V_2 -> V_319 . error )
return V_2 -> V_319 . error ;
if ( V_2 -> V_320 . error )
return V_2 -> V_320 . error ;
F_159 ( V_2 , & V_2 -> V_195 , & V_356 , L_49 ) ;
#if F_69 ( F_2 )
V_2 -> V_357 . V_18 = V_358 ;
V_13 = F_70 ( & V_2 -> V_195 . V_7 , 1 , & V_2 -> V_357 ) ;
if ( V_13 < 0 )
F_6 ( V_2 -> V_2 , L_50 ) ;
#endif
V_2 -> V_195 . V_319 = & V_2 -> V_319 ;
V_13 = F_165 ( & V_2 -> V_195 , V_299 ,
V_359 [ V_2 -> V_360 ] ) ;
if ( V_13 ) {
F_6 ( V_2 -> V_2 ,
L_51 ,
V_13 ) ;
return V_13 ;
}
F_133 ( V_2 -> V_2 , L_52 ,
F_119 ( & V_2 -> V_195 ) ) ;
V_361 = V_356 ;
strcpy ( V_361 . V_20 , L_53 ) ;
F_159 ( V_2 , & V_2 -> V_317 , & V_361 , L_54 ) ;
#if F_69 ( F_2 )
V_2 -> V_362 . V_18 = V_358 ;
V_13 = F_70 ( & V_2 -> V_317 . V_7 , 1 , & V_2 -> V_362 ) ;
if ( V_13 < 0 )
F_6 ( V_2 -> V_2 , L_55 ) ;
#endif
V_2 -> V_317 . V_319 = & V_2 -> V_319 ;
V_13 = F_165 ( & V_2 -> V_317 , V_268 ,
V_363 [ V_2 -> V_360 ] ) ;
if ( V_13 < 0 ) {
F_6 ( V_2 -> V_2 , L_56 ) ;
return V_13 ;
}
F_133 ( V_2 -> V_2 , L_57 ,
F_119 ( & V_2 -> V_317 ) ) ;
if ( V_258 [ V_2 -> V_259 ] . V_297 . type == V_364 ) {
F_159 ( V_2 , & V_2 -> V_274 ,
& V_365 , L_58 ) ;
V_2 -> V_274 . V_319 = & V_2 -> V_320 ;
V_13 = F_165 ( & V_2 -> V_274 , V_263 ,
V_366 [ V_2 -> V_360 ] ) ;
if ( V_13 < 0 ) {
F_6 ( V_2 -> V_2 ,
L_59 ) ;
return V_13 ;
}
F_133 ( V_2 -> V_2 , L_60 ,
F_119 ( & V_2 -> V_274 ) ) ;
}
return 0 ;
}
