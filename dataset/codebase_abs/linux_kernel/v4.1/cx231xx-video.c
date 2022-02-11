static int F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 , * V_8 = NULL , * V_9 ;
struct V_10 * V_11 , * V_12 = NULL ;
int V_13 , V_14 , V_15 = 0 ;
if ( ! V_4 )
return 0 ;
F_3 (entity, mdev) {
if ( V_7 -> type == V_16 ) {
V_8 = V_7 ;
break;
}
}
if ( ! V_8 )
return 0 ;
for ( V_13 = 0 ; V_13 < V_8 -> V_17 ; V_13 ++ ) {
V_11 = & V_8 -> V_18 [ V_13 ] ;
if ( V_11 -> V_19 -> V_7 == V_8 ) {
V_12 = V_11 ;
if ( V_11 -> V_20 & V_21 )
V_15 ++ ;
break;
}
}
if ( V_15 == 1 || ! V_12 )
return 0 ;
V_9 = V_12 -> V_9 -> V_7 ;
for ( V_13 = 0 ; V_13 < V_9 -> V_17 ; V_13 ++ ) {
struct V_6 * V_19 ;
int V_20 = 0 ;
V_11 = & V_9 -> V_18 [ V_13 ] ;
V_19 = V_11 -> V_19 -> V_7 ;
if ( V_19 == V_7 )
V_20 = V_21 ;
V_14 = F_4 ( V_11 , V_20 ) ;
if ( V_14 ) {
F_5 ( V_2 -> V_2 ,
L_1 ,
V_9 -> V_22 , V_19 -> V_22 ,
V_20 ? L_2 : L_3 ,
V_14 ) ;
return V_14 ;
} else
F_6 ( V_2 -> V_2 ,
L_4 ,
V_9 -> V_22 , V_19 -> V_22 ,
V_20 ? L_5 : L_3 ) ;
}
#endif
return 0 ;
}
static inline void F_7 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_25 * V_26 )
{
F_8 ( L_6 , V_26 , V_26 -> V_27 . V_13 ) ;
V_26 -> V_27 . V_28 = V_29 ;
V_26 -> V_27 . V_30 ++ ;
F_9 ( & V_26 -> V_27 . V_31 ) ;
if ( V_2 -> V_32 )
V_2 -> V_33 . V_34 . V_26 = NULL ;
else
V_2 -> V_33 . V_35 . V_26 = NULL ;
F_10 ( & V_26 -> V_27 . V_36 ) ;
F_11 ( & V_26 -> V_27 . V_37 ) ;
}
static inline void F_12 ( struct V_1 * V_2 , int V_38 , int V_39 )
{
char * V_40 = L_7 ;
switch ( V_39 ) {
case - V_41 :
V_40 = L_8 ;
break;
case - V_42 :
V_40 = L_9 ;
break;
case - V_43 :
V_40 = L_10 ;
break;
case - V_44 :
V_40 = L_11 ;
break;
case - V_45 :
V_40 = L_12 ;
break;
case - V_46 :
V_40 = L_13 ;
break;
case - V_47 :
V_40 = L_14 ;
break;
case - V_48 :
V_40 = L_15 ;
break;
}
if ( V_38 < 0 ) {
F_8 ( L_16 , V_39 , V_40 ) ;
} else {
F_8 ( L_17 ,
V_38 , V_39 , V_40 ) ;
}
}
static inline void F_13 ( struct V_23 * V_24 ,
struct V_25 * * V_26 )
{
struct V_49 * V_50 =
F_14 ( V_24 , struct V_49 , V_51 ) ;
struct V_1 * V_2 = F_14 ( V_50 , struct V_1 , V_33 ) ;
char * V_52 ;
if ( F_15 ( & V_24 -> V_53 ) ) {
F_8 ( L_18 ) ;
if ( V_2 -> V_32 )
V_2 -> V_33 . V_34 . V_26 = NULL ;
else
V_2 -> V_33 . V_35 . V_26 = NULL ;
* V_26 = NULL ;
return;
}
* V_26 = F_16 ( V_24 -> V_53 . V_54 , struct V_25 , V_27 . V_36 ) ;
V_52 = F_17 ( & ( * V_26 ) -> V_27 ) ;
memset ( V_52 , 0 , ( * V_26 ) -> V_27 . V_55 ) ;
if ( V_2 -> V_32 )
V_2 -> V_33 . V_34 . V_26 = * V_26 ;
else
V_2 -> V_33 . V_35 . V_26 = * V_26 ;
return;
}
static inline int F_18 ( struct V_1 * V_2 , struct V_56 * V_56 )
{
struct V_23 * V_24 = V_56 -> V_57 ;
int V_13 ;
unsigned char * V_58 ;
T_1 V_59 = 0 , V_60 = 0 ;
T_2 V_61 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_28 & V_62 )
return 0 ;
if ( V_56 -> V_39 < 0 ) {
F_12 ( V_2 , - 1 , V_56 -> V_39 ) ;
if ( V_56 -> V_39 == - V_41 )
return 0 ;
}
for ( V_13 = 0 ; V_13 < V_56 -> V_63 ; V_13 ++ ) {
int V_39 = V_56 -> V_64 [ V_13 ] . V_39 ;
if ( V_39 < 0 ) {
F_12 ( V_2 , V_13 , V_39 ) ;
if ( V_56 -> V_64 [ V_13 ] . V_39 != - V_46 )
continue;
}
if ( V_56 -> V_64 [ V_13 ] . V_65 <= 0 ) {
continue;
}
if ( V_56 -> V_64 [ V_13 ] . V_65 >
V_2 -> V_33 . V_66 ) {
F_8 ( L_19 ) ;
continue;
}
V_58 = V_56 -> V_67 + V_56 -> V_64 [ V_13 ] . V_68 ;
V_60 = V_56 -> V_64 [ V_13 ] . V_65 ;
V_59 = 0 ;
if ( V_24 -> V_69 ) {
V_61 = V_24 -> V_70 ;
} else {
V_61 =
F_19 ( V_58 ,
V_24 -> V_71 ,
& V_59 ) ;
}
V_61 &= 0xF0 ;
if ( V_61 ) {
V_59 += F_20 ( V_2 , V_24 ,
V_61 ,
V_58 + V_59 ,
V_60 - V_59 ) ;
}
while ( V_59 < V_60 ) {
T_1 V_72 = 0 ;
V_61 = F_21 (
V_58 + V_59 ,
V_60 - V_59 ,
& V_72 ) ;
V_59 += V_72 ;
V_61 &= 0xF0 ;
if ( V_61 && ( V_59 < V_60 ) ) {
V_59 += F_20 ( V_2 ,
V_24 , V_61 ,
V_58 + V_59 ,
V_60 - V_59 ) ;
}
}
memcpy ( V_24 -> V_71 , V_58 + V_60 - 4 , 4 ) ;
V_59 = 0 ;
}
return 1 ;
}
static inline int F_22 ( struct V_1 * V_2 , struct V_56 * V_56 )
{
struct V_23 * V_24 = V_56 -> V_57 ;
unsigned char * V_58 ;
T_1 V_59 = 0 , V_60 = 0 ;
T_2 V_61 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_28 & V_62 )
return 0 ;
if ( V_56 -> V_39 < 0 ) {
F_12 ( V_2 , - 1 , V_56 -> V_39 ) ;
if ( V_56 -> V_39 == - V_41 )
return 0 ;
}
if ( 1 ) {
V_58 = V_56 -> V_67 ;
V_60 = V_56 -> V_65 ;
V_59 = 0 ;
if ( V_24 -> V_69 ) {
V_61 = V_24 -> V_70 ;
} else {
V_61 =
F_19 ( V_58 ,
V_24 -> V_71 ,
& V_59 ) ;
}
V_61 &= 0xF0 ;
if ( V_61 ) {
V_59 += F_20 ( V_2 , V_24 ,
V_61 ,
V_58 + V_59 ,
V_60 - V_59 ) ;
}
while ( V_59 < V_60 ) {
T_1 V_72 = 0 ;
V_61 = F_21 (
V_58 + V_59 ,
V_60 - V_59 ,
& V_72 ) ;
V_59 += V_72 ;
V_61 &= 0xF0 ;
if ( V_61 && ( V_59 < V_60 ) ) {
V_59 += F_20 ( V_2 ,
V_24 , V_61 ,
V_58 + V_59 ,
V_60 - V_59 ) ;
}
}
memcpy ( V_24 -> V_71 , V_58 + V_60 - 4 , 4 ) ;
V_59 = 0 ;
}
return 1 ;
}
T_2 F_19 ( T_2 * V_58 , T_2 * V_71 ,
T_1 * V_73 )
{
T_1 V_72 ;
T_2 V_74 [ 8 ] ;
T_2 V_61 = 0 ;
* V_73 = 0 ;
memcpy ( V_74 , V_71 , 4 ) ;
memcpy ( V_74 + 4 , V_58 , 4 ) ;
V_61 = F_21 ( ( T_2 * ) & V_74 , 8 ,
& V_72 ) ;
if ( V_61 ) {
* V_73 = V_72 - 4 ;
}
return V_61 ;
}
T_2 F_21 ( T_2 * V_58 , T_1 V_60 , T_1 * V_73 )
{
T_1 V_13 ;
T_2 V_61 = 0 ;
if ( V_60 < 4 ) {
* V_73 = V_60 ;
return 0 ;
}
for ( V_13 = 0 ; V_13 < ( V_60 - 3 ) ; V_13 ++ ) {
if ( ( V_58 [ V_13 ] == 0xFF ) &&
( V_58 [ V_13 + 1 ] == 0x00 ) && ( V_58 [ V_13 + 2 ] == 0x00 ) ) {
* V_73 = V_13 + 4 ;
V_61 = V_58 [ V_13 + 3 ] ;
return V_61 ;
}
}
* V_73 = V_60 ;
return 0 ;
}
T_1 F_20 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_2 V_61 ,
T_2 * V_58 , T_1 V_60 )
{
T_1 V_75 = 0 ;
int V_76 = - 1 ;
switch ( V_61 ) {
case V_77 :
if ( ( V_60 > 3 ) && ( V_58 [ 0 ] == 0xFF ) &&
( V_58 [ 1 ] == 0x00 ) && ( V_58 [ 2 ] == 0x00 ) &&
( ( V_58 [ 3 ] == V_78 ) ||
( V_58 [ 3 ] == V_79 ) ||
( V_58 [ 3 ] == V_80 ) ||
( V_58 [ 3 ] == V_81 ) ) )
return V_75 ;
V_76 = 1 ;
break;
case V_82 :
if ( ( V_60 > 3 ) && ( V_58 [ 0 ] == 0xFF ) &&
( V_58 [ 1 ] == 0x00 ) && ( V_58 [ 2 ] == 0x00 ) &&
( ( V_58 [ 3 ] == V_78 ) ||
( V_58 [ 3 ] == V_79 ) ||
( V_58 [ 3 ] == V_80 ) ||
( V_58 [ 3 ] == V_81 ) ) )
return V_75 ;
V_76 = 2 ;
break;
}
V_24 -> V_70 = V_61 ;
V_75 = F_23 ( V_2 , V_24 , V_58 ,
V_60 , V_76 ) ;
return V_75 ;
}
T_1 F_23 ( struct V_1 * V_2 ,
struct V_23 * V_24 , T_2 * V_83 ,
T_1 V_84 , int V_85 )
{
T_1 V_86 ;
struct V_25 * V_26 ;
T_1 V_87 = V_2 -> V_88 * 2 ;
if ( V_24 -> V_76 != V_85 )
F_24 ( V_2 , V_24 ) ;
if ( V_2 -> V_32 )
V_26 = V_2 -> V_33 . V_34 . V_26 ;
else
V_26 = V_2 -> V_33 . V_35 . V_26 ;
V_24 -> V_76 = V_85 ;
V_86 = V_24 -> V_89 ;
if ( V_86 > V_84 )
V_86 = V_84 ;
if ( V_24 -> V_90 >= V_24 -> V_91 ) {
V_24 -> V_89 -= V_86 ;
V_24 -> V_69 = ( V_24 -> V_89 == 0 ) ?
0 : 1 ;
return 0 ;
}
V_24 -> V_69 = 1 ;
if ( ! V_26 ) {
V_24 -> V_89 -= V_86 ;
V_24 -> V_69 = ( V_24 -> V_89 == 0 )
? 0 : 1 ;
return V_86 ;
}
F_25 ( V_2 , V_24 , V_83 , V_86 ) ;
V_24 -> V_92 += V_86 ;
V_24 -> V_89 -= V_86 ;
if ( V_24 -> V_89 == 0 ) {
V_24 -> V_89 = V_87 ;
V_24 -> V_90 ++ ;
V_24 -> V_69 = 0 ;
if ( F_26 ( V_2 , V_24 ) && V_26 ) {
F_7 ( V_2 , V_24 , V_26 ) ;
V_24 -> V_92 = 0 ;
V_26 = NULL ;
V_24 -> V_90 = 0 ;
}
}
return V_86 ;
}
void F_24 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 ;
if ( V_24 -> V_76 == 1 ) {
if ( V_24 -> V_90 >= V_24 -> V_91 )
V_24 -> V_93 = 1 ;
else
V_24 -> V_93 = 0 ;
}
if ( V_2 -> V_32 )
V_26 = V_2 -> V_33 . V_34 . V_26 ;
else
V_26 = V_2 -> V_33 . V_35 . V_26 ;
if ( V_26 == NULL ) {
F_13 ( V_24 , & V_26 ) ;
V_24 -> V_92 = 0 ;
V_24 -> V_93 = 0 ;
V_24 -> V_76 = - 1 ;
}
V_24 -> V_89 = V_2 -> V_88 << 1 ;
V_24 -> V_90 = 0 ;
}
int F_25 ( struct V_1 * V_2 , struct V_23 * V_24 ,
T_2 * V_58 , T_1 V_86 )
{
T_2 * V_94 = NULL ;
T_1 V_95 = 0 ;
struct V_25 * V_26 ;
T_1 V_87 = V_2 -> V_88 << 1 ;
void * V_96 ;
int V_68 , V_97 ;
if ( V_2 -> V_32 )
V_26 = V_2 -> V_33 . V_34 . V_26 ;
else
V_26 = V_2 -> V_33 . V_35 . V_26 ;
if ( V_26 == NULL )
return - 1 ;
V_94 = F_17 ( & V_26 -> V_27 ) ;
V_95 = V_87 - V_24 -> V_89 ;
V_68 = ( V_24 -> V_76 == 1 ) ? 0 : V_87 ;
V_96 = V_94 + V_68 ;
V_96 += ( V_24 -> V_90 * V_87 * 2 ) ;
V_96 += V_95 ;
V_97 = V_24 -> V_89 > V_86 ?
V_86 : V_24 -> V_89 ;
if ( ( T_2 * ) ( V_96 + V_97 ) > ( T_2 * ) ( V_94 + V_26 -> V_27 . V_55 ) )
return 0 ;
F_27 ( ( V_98 * ) V_58 , ( V_98 * ) V_96 , ( V_98 ) V_97 ) ;
return 0 ;
}
void F_27 ( V_98 * V_99 , V_98 * V_100 , V_98 V_101 )
{
V_98 V_13 ;
if ( V_101 <= 0 )
return;
for ( V_13 = 0 ; V_13 < V_101 / 2 ; V_13 ++ )
V_100 [ V_13 ] = ( V_99 [ V_13 ] << 8 ) | ( V_99 [ V_13 ] >> 8 ) ;
}
T_2 F_26 ( struct V_1 * V_2 , struct V_23 * V_24 )
{
T_2 V_102 = 0 ;
V_102 = ( ( V_24 -> V_76 == 2 ) &&
( V_24 -> V_90 >= V_24 -> V_91 ) &&
V_24 -> V_93 ) ;
return V_102 ;
}
static int
F_28 ( struct V_103 * V_104 , unsigned int * V_105 , unsigned int * V_55 )
{
struct V_106 * V_107 = V_104 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
* V_55 = ( V_107 -> V_2 -> V_88 * V_107 -> V_2 -> V_109 * V_2 -> V_110 -> V_111 + 7 ) >> 3 ;
if ( 0 == * V_105 )
* V_105 = V_112 ;
if ( * V_105 < V_113 )
* V_105 = V_113 ;
F_1 ( V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_103 * V_104 , struct V_25 * V_26 )
{
struct V_106 * V_107 = V_104 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
unsigned long V_20 = 0 ;
if ( F_30 () )
F_31 () ;
F_32 ( & V_2 -> V_33 . V_114 , V_20 ) ;
if ( V_2 -> V_32 ) {
if ( V_2 -> V_33 . V_34 . V_26 == V_26 )
V_2 -> V_33 . V_34 . V_26 = NULL ;
} else {
if ( V_2 -> V_33 . V_35 . V_26 == V_26 )
V_2 -> V_33 . V_35 . V_26 = NULL ;
}
F_33 ( & V_2 -> V_33 . V_114 , V_20 ) ;
F_34 ( & V_26 -> V_27 ) ;
V_26 -> V_27 . V_28 = V_115 ;
}
static int
F_35 ( struct V_103 * V_104 , struct V_116 * V_27 ,
enum V_117 V_118 )
{
struct V_106 * V_107 = V_104 -> V_108 ;
struct V_25 * V_26 =
F_14 ( V_27 , struct V_25 , V_27 ) ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 = 0 , V_120 = 0 ;
V_26 -> V_27 . V_55 = ( V_107 -> V_2 -> V_88 * V_107 -> V_2 -> V_109 * V_2 -> V_110 -> V_111
+ 7 ) >> 3 ;
if ( 0 != V_26 -> V_27 . V_121 && V_26 -> V_27 . V_122 < V_26 -> V_27 . V_55 )
return - V_123 ;
V_26 -> V_27 . V_88 = V_2 -> V_88 ;
V_26 -> V_27 . V_109 = V_2 -> V_109 ;
V_26 -> V_27 . V_118 = V_118 ;
if ( V_115 == V_26 -> V_27 . V_28 ) {
V_119 = F_36 ( V_104 , & V_26 -> V_27 , NULL ) ;
if ( V_119 < 0 )
goto V_124;
}
if ( V_2 -> V_32 ) {
if ( ! V_2 -> V_33 . V_34 . V_125 )
V_120 = 1 ;
} else {
if ( ! V_2 -> V_33 . V_35 . V_125 )
V_120 = 1 ;
}
F_6 ( V_2 -> V_2 ,
L_20 ,
V_120 , V_2 -> V_33 . V_66 ) ;
if ( V_120 ) {
V_2 -> V_126 = 0 ;
if ( V_2 -> V_32 )
V_119 = F_37 ( V_2 , V_127 ,
V_128 ,
V_2 -> V_33 . V_66 ,
F_18 ) ;
else
V_119 = F_38 ( V_2 , V_127 ,
V_128 ,
V_2 -> V_33 . V_66 ,
F_22 ) ;
if ( V_119 < 0 )
goto V_124;
}
V_26 -> V_27 . V_28 = V_129 ;
return 0 ;
V_124:
F_29 ( V_104 , V_26 ) ;
return V_119 ;
}
static void F_39 ( struct V_103 * V_104 , struct V_116 * V_27 )
{
struct V_25 * V_26 =
F_14 ( V_27 , struct V_25 , V_27 ) ;
struct V_106 * V_107 = V_104 -> V_108 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_23 * V_51 = & V_2 -> V_33 . V_51 ;
V_26 -> V_27 . V_28 = V_130 ;
F_40 ( & V_26 -> V_27 . V_36 , & V_51 -> V_53 ) ;
}
static void F_41 ( struct V_103 * V_104 ,
struct V_116 * V_27 )
{
struct V_25 * V_26 =
F_14 ( V_27 , struct V_25 , V_27 ) ;
struct V_106 * V_107 = V_104 -> V_108 ;
struct V_1 * V_2 = (struct V_1 * ) V_107 -> V_2 ;
F_8 ( L_21 ) ;
F_29 ( V_104 , V_26 ) ;
}
void F_42 ( struct V_1 * V_2 , int V_131 )
{
V_2 -> V_132 = V_131 ;
V_2 -> V_133 = F_43 ( V_131 ) -> V_134 ;
F_44 ( V_2 , V_131 ) ;
F_45 ( V_2 , V_135 , V_136 , F_43 ( V_131 ) -> V_137 , 0 , 0 ) ;
F_46 ( V_2 , V_2 -> V_133 ) ;
F_6 ( V_2 -> V_2 , L_22 , V_131 ) ;
F_47 ( V_2 ) ;
}
static int F_48 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 = 0 ;
if ( V_107 -> V_138 )
return V_119 ;
if ( V_107 -> type == V_139 ) {
if ( V_2 -> V_138 )
return - V_140 ;
V_2 -> V_138 = 1 ;
} else if ( V_107 -> type == V_141 ) {
if ( V_2 -> V_142 )
return - V_140 ;
V_2 -> V_142 = 1 ;
} else
return - V_123 ;
V_107 -> V_138 = 1 ;
return V_119 ;
}
static int F_49 ( struct V_106 * V_107 )
{
return V_107 -> V_138 ;
}
static void F_50 ( struct V_106 * V_107 )
{
struct V_1 * V_2 = V_107 -> V_2 ;
V_107 -> V_138 = 0 ;
if ( V_107 -> type == V_139 )
V_2 -> V_138 = 0 ;
if ( V_107 -> type == V_141 )
V_2 -> V_142 = 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 & V_62 ) {
F_5 ( V_2 -> V_2 , L_23 ) ;
return - V_143 ;
}
return 0 ;
}
static int F_52 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
V_147 -> V_148 . V_149 . V_88 = V_2 -> V_88 ;
V_147 -> V_148 . V_149 . V_109 = V_2 -> V_109 ;
V_147 -> V_148 . V_149 . V_150 = V_2 -> V_110 -> V_151 ;
V_147 -> V_148 . V_149 . V_152 = ( V_2 -> V_88 * V_2 -> V_110 -> V_111 + 7 ) >> 3 ;
V_147 -> V_148 . V_149 . V_153 = V_147 -> V_148 . V_149 . V_152 * V_2 -> V_109 ;
V_147 -> V_148 . V_149 . V_154 = V_155 ;
V_147 -> V_148 . V_149 . V_118 = V_156 ;
return 0 ;
}
static struct V_157 * F_53 ( unsigned int V_151 )
{
unsigned int V_13 ;
for ( V_13 = 0 ; V_13 < F_54 ( V_110 ) ; V_13 ++ )
if ( V_110 [ V_13 ] . V_151 == V_151 )
return & V_110 [ V_13 ] ;
return NULL ;
}
static int F_55 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
unsigned int V_88 = V_147 -> V_148 . V_149 . V_88 ;
unsigned int V_109 = V_147 -> V_148 . V_149 . V_109 ;
unsigned int V_158 = F_56 ( V_2 ) ;
unsigned int V_159 = F_57 ( V_2 ) ;
struct V_157 * V_148 ;
V_148 = F_53 ( V_147 -> V_148 . V_149 . V_150 ) ;
if ( ! V_148 ) {
F_58 ( L_24 ,
V_147 -> V_148 . V_149 . V_150 ) ;
return - V_123 ;
}
F_59 ( & V_88 , 48 , V_158 , 1 , & V_109 , 32 , V_159 , 1 , 0 ) ;
V_147 -> V_148 . V_149 . V_88 = V_88 ;
V_147 -> V_148 . V_149 . V_109 = V_109 ;
V_147 -> V_148 . V_149 . V_150 = V_148 -> V_151 ;
V_147 -> V_148 . V_149 . V_152 = ( V_88 * V_148 -> V_111 + 7 ) >> 3 ;
V_147 -> V_148 . V_149 . V_153 = V_147 -> V_148 . V_149 . V_152 * V_109 ;
V_147 -> V_148 . V_149 . V_154 = V_155 ;
V_147 -> V_148 . V_149 . V_118 = V_156 ;
return 0 ;
}
static int F_60 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
struct V_157 * V_148 ;
struct V_160 V_161 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
F_55 ( V_144 , V_145 , V_147 ) ;
V_148 = F_53 ( V_147 -> V_148 . V_149 . V_150 ) ;
if ( ! V_148 )
return - V_123 ;
if ( F_61 ( & V_107 -> V_162 ) ) {
F_5 ( V_2 -> V_2 , L_25 , V_163 ) ;
return - V_140 ;
}
if ( V_2 -> V_138 && ! V_107 -> V_138 ) {
F_5 ( V_2 -> V_2 ,
L_26 , V_163 ) ;
return - V_140 ;
}
V_2 -> V_88 = V_147 -> V_148 . V_149 . V_88 ;
V_2 -> V_109 = V_147 -> V_148 . V_149 . V_109 ;
V_2 -> V_110 = V_148 ;
F_62 ( & V_161 , & V_147 -> V_148 . V_149 , V_164 ) ;
F_63 ( V_2 , V_135 , V_165 , & V_161 ) ;
F_64 ( & V_147 -> V_148 . V_149 , & V_161 ) ;
return V_119 ;
}
static int F_65 ( struct V_144 * V_144 , void * V_145 , T_3 * V_166 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
* V_166 = V_2 -> V_167 ;
return 0 ;
}
static int F_66 ( struct V_144 * V_144 , void * V_145 , T_3 V_167 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_160 V_161 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_2 -> V_167 == V_167 )
return 0 ;
if ( F_61 ( & V_107 -> V_162 ) )
return - V_140 ;
V_2 -> V_167 = V_167 ;
V_2 -> V_88 = 720 ;
V_2 -> V_109 = ( V_2 -> V_167 & V_168 ) ? 576 : 480 ;
F_63 ( V_2 , V_135 , V_169 , V_2 -> V_167 ) ;
memset ( & V_161 , 0 , sizeof( V_161 ) ) ;
V_161 . V_170 = V_164 ;
V_161 . V_88 = V_2 -> V_88 ;
V_161 . V_109 = V_2 -> V_109 ;
F_63 ( V_2 , V_135 , V_165 , & V_161 ) ;
F_47 ( V_2 ) ;
return 0 ;
}
int F_67 ( struct V_144 * V_144 , void * V_145 ,
struct V_171 * V_13 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
T_1 V_172 ;
unsigned int V_14 , V_173 ;
V_173 = V_13 -> V_131 ;
if ( V_173 >= V_174 )
return - V_123 ;
if ( 0 == F_43 ( V_173 ) -> type )
return - V_123 ;
V_13 -> V_131 = V_173 ;
V_13 -> type = V_175 ;
strcpy ( V_13 -> V_22 , V_176 [ F_43 ( V_173 ) -> type ] ) ;
if ( ( V_177 == F_43 ( V_173 ) -> type ) ||
( V_178 == F_43 ( V_173 ) -> type ) )
V_13 -> type = V_179 ;
V_13 -> V_180 = V_2 -> V_181 . V_182 ;
if ( V_173 == V_2 -> V_132 ) {
V_14 = F_68 ( V_2 , V_183 ,
V_184 , 2 , & V_172 , 4 ) ;
if ( V_14 > 0 ) {
if ( ( V_172 & V_185 ) == 0x00 )
V_13 -> V_39 |= V_186 ;
if ( ( V_172 & V_187 ) == 0x00 )
V_13 -> V_39 |= V_188 ;
}
}
return 0 ;
}
int F_69 ( struct V_144 * V_144 , void * V_145 , unsigned int * V_13 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
* V_13 = V_2 -> V_132 ;
return 0 ;
}
int F_70 ( struct V_144 * V_144 , void * V_145 , unsigned int V_13 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_2 -> V_126 = 0 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( V_13 >= V_174 )
return - V_123 ;
if ( 0 == F_43 ( V_13 ) -> type )
return - V_123 ;
F_42 ( V_2 , V_13 ) ;
if ( F_43 ( V_13 ) -> type == V_177 ||
F_43 ( V_13 ) -> type == V_178 ) {
F_63 ( V_2 , V_135 , V_169 , V_2 -> V_167 ) ;
}
return 0 ;
}
int F_71 ( struct V_144 * V_144 , void * V_145 , struct V_189 * V_190 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( 0 != V_190 -> V_131 )
return - V_123 ;
strcpy ( V_190 -> V_22 , L_27 ) ;
V_190 -> type = V_191 ;
V_190 -> V_192 = V_193 ;
V_190 -> V_194 = 0xffffffffUL ;
V_190 -> signal = 0xffff ;
F_63 ( V_2 , V_195 , V_196 , V_190 ) ;
return 0 ;
}
int F_72 ( struct V_144 * V_144 , void * V_145 , const struct V_189 * V_190 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( 0 != V_190 -> V_131 )
return - V_123 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
int F_73 ( struct V_144 * V_144 , void * V_145 ,
struct V_197 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
if ( V_147 -> V_195 )
return - V_123 ;
V_147 -> V_198 = V_2 -> V_199 ;
return 0 ;
}
int F_74 ( struct V_144 * V_144 , void * V_145 ,
const struct V_197 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
struct V_197 V_200 = * V_147 ;
int V_119 ;
T_1 V_201 = 5400000 ;
F_6 ( V_2 -> V_2 ,
L_28 ,
V_147 -> V_198 , V_147 -> type ) ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( 0 != V_147 -> V_195 )
return - V_123 ;
V_119 = F_75 ( V_2 ) ;
F_63 ( V_2 , V_195 , V_202 , V_147 ) ;
F_63 ( V_2 , V_195 , V_203 , & V_200 ) ;
V_2 -> V_199 = V_200 . V_198 ;
V_119 = F_76 ( V_2 ) ;
if ( V_2 -> V_204 == V_205 ) {
if ( V_2 -> V_167 & ( V_206 | V_207 ) )
V_201 = 5400000 ;
else if ( V_2 -> V_167 & V_208 )
V_201 = 6000000 ;
else if ( V_2 -> V_167 & ( V_209 | V_210 ) )
V_201 = 6900000 ;
else if ( V_2 -> V_167 & V_211 )
V_201 = 7100000 ;
else if ( V_2 -> V_167 & V_212 )
V_201 = 7250000 ;
else if ( V_2 -> V_167 & V_213 )
V_201 = 6900000 ;
else if ( V_2 -> V_167 & V_214 )
V_201 = 1250000 ;
F_6 ( V_2 -> V_2 ,
L_29 , V_201 ) ;
F_77 ( V_2 , V_201 , 1 , 1 ) ;
F_78 ( V_2 ) ;
}
F_6 ( V_2 -> V_2 , L_30 , V_147 -> V_198 ) ;
return V_119 ;
}
int F_79 ( struct V_144 * V_144 , void * V_107 ,
struct V_215 * V_216 )
{
switch ( V_216 -> V_217 . V_218 ) {
case 0 :
return 0 ;
case 1 :
F_80 ( V_216 -> V_22 , L_31 , sizeof( V_216 -> V_22 ) ) ;
return 0 ;
case 2 :
F_80 ( V_216 -> V_22 , L_32 , sizeof( V_216 -> V_22 ) ) ;
return 0 ;
case 3 :
F_80 ( V_216 -> V_22 , L_33 , sizeof( V_216 -> V_22 ) ) ;
return 0 ;
case 4 :
F_80 ( V_216 -> V_22 , L_34 , sizeof( V_216 -> V_22 ) ) ;
return 0 ;
case 5 :
F_80 ( V_216 -> V_22 , L_35 , sizeof( V_216 -> V_22 ) ) ;
return 0 ;
case 6 :
F_80 ( V_216 -> V_22 , L_36 , sizeof( V_216 -> V_22 ) ) ;
return 0 ;
}
return - V_123 ;
}
int F_81 ( struct V_144 * V_144 , void * V_145 ,
struct V_219 * V_220 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_14 ;
T_2 V_221 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_222 = 0 ;
switch ( V_220 -> V_217 . V_218 ) {
case 0 :
V_14 = F_82 ( V_2 , V_223 ,
( V_98 ) V_220 -> V_220 , V_221 , 4 ) ;
V_220 -> V_224 = V_221 [ 0 ] | V_221 [ 1 ] << 8 |
V_221 [ 2 ] << 16 | V_221 [ 3 ] << 24 ;
V_220 -> V_55 = 4 ;
break;
case 1 :
V_14 = F_68 ( V_2 , V_225 ,
( V_98 ) V_220 -> V_220 , 2 , & V_222 , 1 ) ;
V_220 -> V_224 = V_222 ;
V_220 -> V_55 = 1 ;
break;
case 2 :
V_14 = F_68 ( V_2 , V_183 ,
( V_98 ) V_220 -> V_220 , 2 , & V_222 , 1 ) ;
V_220 -> V_224 = V_222 ;
V_220 -> V_55 = 1 ;
break;
case 3 :
V_14 = F_68 ( V_2 , V_226 ,
( V_98 ) V_220 -> V_220 , 1 , & V_222 , 1 ) ;
V_220 -> V_224 = V_222 ;
V_220 -> V_55 = 1 ;
break;
case 4 :
V_14 = F_68 ( V_2 , V_225 ,
( V_98 ) V_220 -> V_220 , 2 , & V_222 , 4 ) ;
V_220 -> V_224 = V_222 ;
V_220 -> V_55 = 4 ;
break;
case 5 :
V_14 = F_68 ( V_2 , V_183 ,
( V_98 ) V_220 -> V_220 , 2 , & V_222 , 4 ) ;
V_220 -> V_224 = V_222 ;
V_220 -> V_55 = 4 ;
break;
case 6 :
V_14 = F_68 ( V_2 , V_226 ,
( V_98 ) V_220 -> V_220 , 1 , & V_222 , 4 ) ;
V_220 -> V_224 = V_222 ;
V_220 -> V_55 = 4 ;
break;
default:
return - V_123 ;
}
return V_14 < 0 ? V_14 : 0 ;
}
int F_83 ( struct V_144 * V_144 , void * V_145 ,
const struct V_219 * V_220 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_14 ;
T_2 V_222 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_220 -> V_217 . V_218 ) {
case 0 :
V_222 [ 0 ] = ( T_2 ) V_220 -> V_224 ;
V_222 [ 1 ] = ( T_2 ) ( V_220 -> V_224 >> 8 ) ;
V_222 [ 2 ] = ( T_2 ) ( V_220 -> V_224 >> 16 ) ;
V_222 [ 3 ] = ( T_2 ) ( V_220 -> V_224 >> 24 ) ;
V_14 = F_84 ( V_2 , V_227 ,
( V_98 ) V_220 -> V_220 , V_222 , 4 ) ;
break;
case 1 :
V_14 = F_85 ( V_2 , V_225 ,
( V_98 ) V_220 -> V_220 , 2 , V_220 -> V_224 , 1 ) ;
break;
case 2 :
V_14 = F_85 ( V_2 , V_183 ,
( V_98 ) V_220 -> V_220 , 2 , V_220 -> V_224 , 1 ) ;
break;
case 3 :
V_14 = F_85 ( V_2 , V_226 ,
( V_98 ) V_220 -> V_220 , 1 , V_220 -> V_224 , 1 ) ;
break;
case 4 :
V_14 = F_85 ( V_2 , V_225 ,
( V_98 ) V_220 -> V_220 , 2 , V_220 -> V_224 , 4 ) ;
break;
case 5 :
V_14 = F_85 ( V_2 , V_183 ,
( V_98 ) V_220 -> V_220 , 2 , V_220 -> V_224 , 4 ) ;
break;
case 6 :
V_14 = F_85 ( V_2 , V_226 ,
( V_98 ) V_220 -> V_220 , 1 , V_220 -> V_224 , 4 ) ;
break;
default:
return - V_123 ;
}
return V_14 < 0 ? V_14 : 0 ;
}
static int F_86 ( struct V_144 * V_144 , void * V_145 ,
struct V_228 * V_229 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
if ( V_229 -> type != V_139 )
return - V_123 ;
V_229 -> V_230 . V_231 = 0 ;
V_229 -> V_230 . V_232 = 0 ;
V_229 -> V_230 . V_88 = V_2 -> V_88 ;
V_229 -> V_230 . V_109 = V_2 -> V_109 ;
V_229 -> V_233 = V_229 -> V_230 ;
V_229 -> V_234 . V_235 = 54 ;
V_229 -> V_234 . V_236 = 59 ;
return 0 ;
}
static int F_87 ( struct V_144 * V_144 , void * V_145 ,
enum V_237 type )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_48 ( V_107 ) ;
if ( F_88 ( V_119 >= 0 ) )
V_119 = F_89 ( & V_107 -> V_162 ) ;
F_63 ( V_2 , V_135 , V_238 , 1 ) ;
return V_119 ;
}
static int F_90 ( struct V_144 * V_144 , void * V_145 ,
enum V_237 type )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( type != V_107 -> type )
return - V_123 ;
F_45 ( V_2 , V_135 , V_238 , 0 ) ;
F_91 ( & V_107 -> V_162 ) ;
F_50 ( V_107 ) ;
return 0 ;
}
int F_92 ( struct V_144 * V_144 , void * V_145 ,
struct V_239 * V_240 )
{
struct V_241 * V_181 = F_93 ( V_144 ) ;
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
F_80 ( V_240 -> V_242 , L_37 , sizeof( V_240 -> V_242 ) ) ;
F_80 ( V_240 -> V_243 , V_244 [ V_2 -> V_245 ] . V_22 , sizeof( V_240 -> V_243 ) ) ;
F_94 ( V_2 -> V_246 , V_240 -> V_247 , sizeof( V_240 -> V_247 ) ) ;
if ( V_181 -> V_248 == V_249 )
V_240 -> V_250 = V_251 ;
else {
V_240 -> V_250 = V_252 | V_253 ;
if ( V_181 -> V_248 == V_254 )
V_240 -> V_250 |= V_255 ;
else
V_240 -> V_250 |= V_256 ;
}
if ( V_2 -> V_204 != V_257 )
V_240 -> V_250 |= V_258 ;
V_240 -> V_259 = V_240 -> V_250 | V_252 |
V_255 | V_256 |
V_253 | V_260 ;
if ( F_95 ( & V_2 -> V_261 ) )
V_240 -> V_259 |= V_251 ;
return 0 ;
}
static int F_96 ( struct V_144 * V_144 , void * V_145 ,
struct V_262 * V_147 )
{
if ( F_97 ( V_147 -> V_131 >= F_54 ( V_110 ) ) )
return - V_123 ;
F_80 ( V_147 -> V_263 , V_110 [ V_147 -> V_131 ] . V_22 , sizeof( V_147 -> V_263 ) ) ;
V_147 -> V_150 = V_110 [ V_147 -> V_131 ] . V_151 ;
return 0 ;
}
static int F_98 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
V_147 -> V_148 . V_264 . V_265 = 6750000 * 4 ;
V_147 -> V_148 . V_264 . V_266 = V_267 ;
V_147 -> V_148 . V_264 . V_268 = V_269 ;
V_147 -> V_148 . V_264 . V_68 = 0 ;
V_147 -> V_148 . V_264 . V_270 [ 0 ] = ( V_2 -> V_167 & V_168 ) ?
V_271 : V_272 ;
V_147 -> V_148 . V_264 . V_105 [ 0 ] = ( V_2 -> V_167 & V_168 ) ?
V_273 : V_274 ;
V_147 -> V_148 . V_264 . V_270 [ 1 ] = ( V_2 -> V_167 & V_168 ) ?
V_271 + 312 : V_272 + 263 ;
V_147 -> V_148 . V_264 . V_105 [ 1 ] = V_147 -> V_148 . V_264 . V_105 [ 0 ] ;
memset ( V_147 -> V_148 . V_264 . V_275 , 0 , sizeof( V_147 -> V_148 . V_264 . V_275 ) ) ;
return 0 ;
}
static int F_99 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
V_147 -> V_148 . V_264 . V_265 = 6750000 * 4 ;
V_147 -> V_148 . V_264 . V_266 = V_267 ;
V_147 -> V_148 . V_264 . V_268 = V_269 ;
V_147 -> V_148 . V_264 . V_68 = 0 ;
V_147 -> V_148 . V_264 . V_20 = 0 ;
V_147 -> V_148 . V_264 . V_270 [ 0 ] = ( V_2 -> V_167 & V_168 ) ?
V_271 : V_272 ;
V_147 -> V_148 . V_264 . V_105 [ 0 ] = ( V_2 -> V_167 & V_168 ) ?
V_273 : V_274 ;
V_147 -> V_148 . V_264 . V_270 [ 1 ] = ( V_2 -> V_167 & V_168 ) ?
V_271 + 312 : V_272 + 263 ;
V_147 -> V_148 . V_264 . V_105 [ 1 ] = V_147 -> V_148 . V_264 . V_105 [ 0 ] ;
memset ( V_147 -> V_148 . V_264 . V_275 , 0 , sizeof( V_147 -> V_148 . V_264 . V_275 ) ) ;
return 0 ;
}
static int F_100 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
if ( V_2 -> V_142 && ! V_107 -> V_138 ) {
F_5 ( V_2 -> V_2 ,
L_38 , V_163 ) ;
return - V_140 ;
}
return F_99 ( V_144 , V_145 , V_147 ) ;
}
static int F_101 ( struct V_144 * V_144 , void * V_145 ,
struct V_276 * V_277 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
return F_102 ( & V_107 -> V_162 , V_277 ) ;
}
static int F_103 ( struct V_144 * V_144 , void * V_145 , struct V_278 * V_279 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
return F_104 ( & V_107 -> V_162 , V_279 ) ;
}
static int F_105 ( struct V_144 * V_144 , void * V_145 , struct V_278 * V_279 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
return F_106 ( & V_107 -> V_162 , V_279 ) ;
}
static int F_107 ( struct V_144 * V_144 , void * V_145 , struct V_278 * V_279 )
{
struct V_106 * V_107 = V_145 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
return F_108 ( & V_107 -> V_162 , V_279 , V_144 -> V_280 & V_281 ) ;
}
static int F_109 ( struct V_144 * V_144 , void * V_145 , struct V_189 * V_190 )
{
struct V_1 * V_2 = ( (struct V_106 * ) V_145 ) -> V_2 ;
if ( V_190 -> V_131 )
return - V_123 ;
strcpy ( V_190 -> V_22 , L_39 ) ;
F_63 ( V_2 , V_195 , V_196 , V_190 ) ;
return 0 ;
}
static int F_110 ( struct V_144 * V_144 , void * V_145 , const struct V_189 * V_190 )
{
struct V_1 * V_2 = ( (struct V_106 * ) V_145 ) -> V_2 ;
if ( V_190 -> V_131 )
return - V_123 ;
F_63 ( V_2 , V_195 , V_282 , V_190 ) ;
return 0 ;
}
static int F_111 ( struct V_144 * V_283 )
{
int V_284 = 0 ;
struct V_241 * V_181 = F_93 ( V_283 ) ;
struct V_1 * V_2 = F_112 ( V_283 ) ;
struct V_106 * V_107 ;
enum V_237 V_285 = 0 ;
switch ( V_181 -> V_248 ) {
case V_286 :
V_285 = V_139 ;
break;
case V_254 :
V_285 = V_141 ;
break;
case V_249 :
V_284 = 1 ;
break;
}
F_58 ( L_40 ,
F_113 ( V_181 ) , V_287 [ V_285 ] ,
V_2 -> V_288 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
dev_err(dev->dev,
"Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_107 = F_114 ( sizeof( struct V_106 ) , V_289 ) ;
if ( ! V_107 )
return - V_290 ;
if ( F_115 ( & V_2 -> V_291 ) ) {
F_116 ( V_107 ) ;
return - V_292 ;
}
V_107 -> V_2 = V_2 ;
V_107 -> type = V_285 ;
V_283 -> V_293 = V_107 ;
F_117 ( & V_107 -> V_107 , V_181 ) ;
if ( V_107 -> type == V_139 && V_2 -> V_288 == 0 ) {
if ( V_2 -> V_294 . V_295 )
F_118 ( V_2 ,
V_296 ) ;
else
F_118 ( V_2 , V_297 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
V_2 -> V_132 = V_2 -> V_132 > 2 ? 2 : V_2 -> V_132 ;
}
if ( V_284 ) {
F_58 ( L_41 ) ;
F_63 ( V_2 , V_195 , V_298 ) ;
}
V_2 -> V_288 ++ ;
if ( V_107 -> type == V_139 )
F_121 ( & V_107 -> V_162 , & V_299 ,
NULL , & V_2 -> V_33 . V_114 ,
V_107 -> type , V_156 ,
sizeof( struct V_25 ) ,
V_107 , & V_2 -> V_291 ) ;
if ( V_107 -> type == V_141 ) {
F_122 ( V_2 , V_300 , 0 ) ;
F_121 ( & V_107 -> V_162 , & V_301 ,
NULL , & V_2 -> V_302 . V_114 ,
V_107 -> type , V_303 ,
sizeof( struct V_25 ) ,
V_107 , & V_2 -> V_291 ) ;
}
F_123 ( & V_2 -> V_291 ) ;
F_124 ( & V_107 -> V_107 ) ;
return 0 ;
}
void F_125 ( struct V_1 * V_2 )
{
if ( F_95 ( & V_2 -> V_261 ) )
F_126 ( & V_2 -> V_261 ) ;
if ( F_95 ( & V_2 -> V_304 ) ) {
F_127 ( V_2 -> V_2 , L_42 ,
F_113 ( & V_2 -> V_304 ) ) ;
F_126 ( & V_2 -> V_304 ) ;
}
if ( F_95 ( & V_2 -> V_181 ) ) {
F_127 ( V_2 -> V_2 , L_42 ,
F_113 ( & V_2 -> V_181 ) ) ;
if ( V_2 -> V_294 . V_305 )
F_128 ( V_2 ) ;
F_126 ( & V_2 -> V_181 ) ;
}
F_129 ( & V_2 -> V_306 ) ;
F_129 ( & V_2 -> V_307 ) ;
}
static int F_130 ( struct V_144 * V_283 )
{
struct V_106 * V_107 = V_283 -> V_293 ;
struct V_1 * V_2 = V_107 -> V_2 ;
F_58 ( L_43 , V_2 -> V_288 ) ;
F_58 ( L_43 , V_2 -> V_288 ) ;
if ( F_49 ( V_107 ) )
F_50 ( V_107 ) ;
if ( ! V_2 -> V_294 . V_308 )
if ( V_107 -> type == V_141 ) {
F_131 ( & V_107 -> V_162 ) ;
F_132 ( & V_107 -> V_162 ) ;
if ( V_2 -> V_28 & V_62 ) {
if ( F_133 ( & V_2 -> V_309 ) > 0 ) {
F_134 ( V_2 ) ;
V_107 -> V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_135 ( V_2 ) ;
if ( ! V_2 -> V_310 )
F_122 ( V_2 , V_300 , 0 ) ;
else
F_122 ( V_2 , V_311 , 0 ) ;
F_136 ( & V_107 -> V_107 ) ;
F_137 ( & V_107 -> V_107 ) ;
F_116 ( V_107 ) ;
V_2 -> V_288 -- ;
F_138 ( & V_2 -> V_312 , 1 ) ;
return 0 ;
}
F_136 ( & V_107 -> V_107 ) ;
V_2 -> V_288 -- ;
if ( ! V_2 -> V_288 ) {
F_131 ( & V_107 -> V_162 ) ;
F_132 ( & V_107 -> V_162 ) ;
if ( V_2 -> V_28 & V_62 ) {
F_134 ( V_2 ) ;
V_107 -> V_2 = NULL ;
return 0 ;
}
F_63 ( V_2 , V_313 , V_314 , 0 ) ;
if ( V_2 -> V_32 )
F_139 ( V_2 ) ;
else
F_140 ( V_2 ) ;
F_141 ( V_2 , V_315 ) ;
F_122 ( V_2 , V_316 , 0 ) ;
}
F_137 ( & V_107 -> V_107 ) ;
F_116 ( V_107 ) ;
F_138 ( & V_2 -> V_312 , 1 ) ;
return 0 ;
}
static int F_142 ( struct V_144 * V_283 )
{
struct V_106 * V_107 = V_283 -> V_293 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
F_143 ( & V_2 -> V_291 ) ;
V_119 = F_130 ( V_283 ) ;
F_123 ( & V_2 -> V_291 ) ;
return V_119 ;
}
static T_4
F_144 ( struct V_144 * V_283 , char T_5 * V_26 , T_6 V_105 ,
T_7 * V_92 )
{
struct V_106 * V_107 = V_283 -> V_293 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
if ( ( V_107 -> type == V_139 ) ||
( V_107 -> type == V_141 ) ) {
V_119 = F_48 ( V_107 ) ;
if ( F_97 ( V_119 < 0 ) )
return V_119 ;
if ( F_115 ( & V_2 -> V_291 ) )
return - V_292 ;
V_119 = F_145 ( & V_107 -> V_162 , V_26 , V_105 , V_92 , 0 ,
V_283 -> V_280 & V_281 ) ;
F_123 ( & V_2 -> V_291 ) ;
return V_119 ;
}
return 0 ;
}
static unsigned int F_146 ( struct V_144 * V_283 , T_8 * V_317 )
{
unsigned long V_318 = F_147 ( V_317 ) ;
struct V_106 * V_107 = V_283 -> V_293 ;
struct V_1 * V_2 = V_107 -> V_2 ;
unsigned V_319 = 0 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_320 ;
V_119 = F_48 ( V_107 ) ;
if ( F_97 ( V_119 < 0 ) )
return V_320 ;
if ( F_148 ( & V_107 -> V_107 ) )
V_319 |= V_321 ;
else
F_149 ( V_283 , & V_107 -> V_107 . V_317 , V_317 ) ;
if ( ! ( V_318 & ( V_322 | V_323 ) ) )
return V_319 ;
if ( ( V_139 == V_107 -> type ) ||
( V_141 == V_107 -> type ) ) {
F_143 ( & V_2 -> V_291 ) ;
V_319 |= F_150 ( V_283 , & V_107 -> V_162 , V_317 ) ;
F_123 ( & V_2 -> V_291 ) ;
return V_319 ;
}
return V_319 | V_320 ;
}
static int F_151 ( struct V_144 * V_283 , struct V_324 * V_325 )
{
struct V_106 * V_107 = V_283 -> V_293 ;
struct V_1 * V_2 = V_107 -> V_2 ;
int V_119 ;
V_119 = F_51 ( V_2 ) ;
if ( V_119 < 0 )
return V_119 ;
V_119 = F_48 ( V_107 ) ;
if ( F_97 ( V_119 < 0 ) )
return V_119 ;
if ( F_115 ( & V_2 -> V_291 ) )
return - V_292 ;
V_119 = F_152 ( & V_107 -> V_162 , V_325 ) ;
F_123 ( & V_2 -> V_291 ) ;
F_58 ( L_44 ,
( unsigned long ) V_325 -> V_326 ,
( unsigned long ) V_325 -> V_327 -
( unsigned long ) V_325 -> V_326 , V_119 ) ;
return V_119 ;
}
static void F_153 ( struct V_1 * V_2 ,
struct V_241 * V_328 ,
const struct V_241 * V_329 ,
const char * V_330 )
{
* V_328 = * V_329 ;
V_328 -> V_331 = & V_2 -> V_331 ;
V_328 -> V_332 = V_333 ;
V_328 -> V_291 = & V_2 -> V_291 ;
snprintf ( V_328 -> V_22 , sizeof( V_328 -> V_22 ) , L_45 , V_2 -> V_22 , V_330 ) ;
F_154 ( V_328 , V_2 ) ;
if ( V_2 -> V_204 == V_257 ) {
F_155 ( V_328 , V_334 ) ;
F_155 ( V_328 , V_335 ) ;
F_155 ( V_328 , V_336 ) ;
F_155 ( V_328 , V_337 ) ;
}
}
int F_156 ( struct V_1 * V_2 )
{
int V_14 ;
F_127 ( V_2 -> V_2 , L_46 , V_338 ) ;
V_2 -> V_167 = V_339 ;
V_2 -> V_88 = F_56 ( V_2 ) ;
V_2 -> V_109 = F_57 ( V_2 ) ;
V_2 -> V_340 = 0 ;
V_2 -> V_110 = & V_110 [ 0 ] ;
F_42 ( V_2 , V_2 -> V_132 ) ;
F_63 ( V_2 , V_135 , V_169 , V_2 -> V_167 ) ;
F_157 ( & V_2 -> V_306 , 10 ) ;
F_157 ( & V_2 -> V_307 , 5 ) ;
if ( V_2 -> V_341 ) {
F_158 ( & V_2 -> V_306 ,
V_2 -> V_341 -> V_306 , NULL ) ;
F_158 ( & V_2 -> V_307 ,
V_2 -> V_341 -> V_306 ,
V_342 ) ;
}
if ( V_2 -> V_306 . error )
return V_2 -> V_306 . error ;
if ( V_2 -> V_307 . error )
return V_2 -> V_307 . error ;
F_153 ( V_2 , & V_2 -> V_181 , & V_343 , L_47 ) ;
#if F_159 ( F_2 )
V_2 -> V_344 . V_20 = V_345 ;
V_14 = F_160 ( & V_2 -> V_181 . V_7 , 1 , & V_2 -> V_344 , 0 ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_2 , L_48 ) ;
#endif
V_2 -> V_181 . V_306 = & V_2 -> V_306 ;
V_14 = F_161 ( & V_2 -> V_181 , V_286 ,
V_346 [ V_2 -> V_347 ] ) ;
if ( V_14 ) {
F_5 ( V_2 -> V_2 ,
L_49 ,
V_14 ) ;
return V_14 ;
}
F_127 ( V_2 -> V_2 , L_50 ,
F_113 ( & V_2 -> V_181 ) ) ;
V_348 = V_343 ;
strcpy ( V_348 . V_22 , L_51 ) ;
F_153 ( V_2 , & V_2 -> V_304 , & V_348 , L_52 ) ;
#if F_159 ( F_2 )
V_2 -> V_349 . V_20 = V_345 ;
V_14 = F_160 ( & V_2 -> V_304 . V_7 , 1 , & V_2 -> V_349 , 0 ) ;
if ( V_14 < 0 )
F_5 ( V_2 -> V_2 , L_53 ) ;
#endif
V_2 -> V_304 . V_306 = & V_2 -> V_306 ;
V_14 = F_161 ( & V_2 -> V_304 , V_254 ,
V_350 [ V_2 -> V_347 ] ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_2 , L_54 ) ;
return V_14 ;
}
F_127 ( V_2 -> V_2 , L_55 ,
F_113 ( & V_2 -> V_304 ) ) ;
if ( V_244 [ V_2 -> V_245 ] . V_284 . type == V_351 ) {
F_153 ( V_2 , & V_2 -> V_261 ,
& V_352 , L_56 ) ;
V_2 -> V_261 . V_306 = & V_2 -> V_307 ;
V_14 = F_161 ( & V_2 -> V_261 , V_249 ,
V_353 [ V_2 -> V_347 ] ) ;
if ( V_14 < 0 ) {
F_5 ( V_2 -> V_2 ,
L_57 ) ;
return V_14 ;
}
F_127 ( V_2 -> V_2 , L_58 ,
F_113 ( & V_2 -> V_261 ) ) ;
}
return 0 ;
}
