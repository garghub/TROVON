static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_2 ( L_1 , V_6 , V_6 -> V_7 . V_8 ) ;
V_6 -> V_7 . V_9 = V_10 ;
V_6 -> V_7 . V_11 ++ ;
F_3 ( & V_6 -> V_7 . V_12 ) ;
if ( V_2 -> V_13 )
V_2 -> V_14 . V_15 . V_6 = NULL ;
else
V_2 -> V_14 . V_16 . V_6 = NULL ;
F_4 ( & V_6 -> V_7 . V_17 ) ;
F_5 ( & V_6 -> V_7 . V_18 ) ;
}
static inline void F_6 ( struct V_1 * V_2 , int V_19 , int V_20 )
{
char * V_21 = L_2 ;
switch ( V_20 ) {
case - V_22 :
V_21 = L_3 ;
break;
case - V_23 :
V_21 = L_4 ;
break;
case - V_24 :
V_21 = L_5 ;
break;
case - V_25 :
V_21 = L_6 ;
break;
case - V_26 :
V_21 = L_7 ;
break;
case - V_27 :
V_21 = L_8 ;
break;
case - V_28 :
V_21 = L_9 ;
break;
case - V_29 :
V_21 = L_10 ;
break;
}
if ( V_19 < 0 ) {
F_2 ( L_11 , V_20 , V_21 ) ;
} else {
F_2 ( L_12 ,
V_19 , V_20 , V_21 ) ;
}
}
static inline void F_7 ( struct V_3 * V_4 ,
struct V_5 * * V_6 )
{
struct V_30 * V_31 =
F_8 ( V_4 , struct V_30 , V_32 ) ;
struct V_1 * V_2 = F_8 ( V_31 , struct V_1 , V_14 ) ;
char * V_33 ;
if ( F_9 ( & V_4 -> V_34 ) ) {
F_2 ( L_13 ) ;
if ( V_2 -> V_13 )
V_2 -> V_14 . V_15 . V_6 = NULL ;
else
V_2 -> V_14 . V_16 . V_6 = NULL ;
* V_6 = NULL ;
return;
}
* V_6 = F_10 ( V_4 -> V_34 . V_35 , struct V_5 , V_7 . V_17 ) ;
V_33 = F_11 ( & ( * V_6 ) -> V_7 ) ;
memset ( V_33 , 0 , ( * V_6 ) -> V_7 . V_36 ) ;
if ( V_2 -> V_13 )
V_2 -> V_14 . V_15 . V_6 = * V_6 ;
else
V_2 -> V_14 . V_16 . V_6 = * V_6 ;
return;
}
static inline int F_12 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_38 ;
int V_8 , V_39 = 1 ;
unsigned char * V_40 ;
T_1 V_41 = 0 , V_42 = 0 ;
T_2 V_43 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_9 & V_44 )
return 0 ;
if ( V_37 -> V_20 < 0 ) {
F_6 ( V_2 , - 1 , V_37 -> V_20 ) ;
if ( V_37 -> V_20 == - V_22 )
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_37 -> V_45 ; V_8 ++ ) {
int V_20 = V_37 -> V_46 [ V_8 ] . V_20 ;
if ( V_20 < 0 ) {
F_6 ( V_2 , V_8 , V_20 ) ;
if ( V_37 -> V_46 [ V_8 ] . V_20 != - V_27 )
continue;
}
if ( V_37 -> V_46 [ V_8 ] . V_47 <= 0 ) {
continue;
}
if ( V_37 -> V_46 [ V_8 ] . V_47 >
V_2 -> V_14 . V_48 ) {
F_2 ( L_14 ) ;
continue;
}
V_40 = V_37 -> V_49 + V_37 -> V_46 [ V_8 ] . V_50 ;
V_42 = V_37 -> V_46 [ V_8 ] . V_47 ;
V_41 = 0 ;
if ( V_4 -> V_51 ) {
V_43 = V_4 -> V_52 ;
} else {
V_43 =
F_13 ( V_40 ,
V_4 -> V_53 ,
& V_41 ) ;
}
V_43 &= 0xF0 ;
if ( V_43 ) {
V_41 += F_14 ( V_2 , V_4 ,
V_43 ,
V_40 + V_41 ,
V_42 - V_41 ) ;
}
while ( V_41 < V_42 ) {
T_1 V_54 = 0 ;
V_43 = F_15 (
V_40 + V_41 ,
V_42 - V_41 ,
& V_54 ) ;
V_41 += V_54 ;
V_43 &= 0xF0 ;
if ( V_43 && ( V_41 < V_42 ) ) {
V_41 += F_14 ( V_2 ,
V_4 , V_43 ,
V_40 + V_41 ,
V_42 - V_41 ) ;
}
}
memcpy ( V_4 -> V_53 , V_40 + V_42 - 4 , 4 ) ;
V_41 = 0 ;
}
return V_39 ;
}
static inline int F_16 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_38 ;
int V_39 = 1 ;
unsigned char * V_40 ;
T_1 V_41 = 0 , V_42 = 0 ;
T_2 V_43 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_9 & V_44 )
return 0 ;
if ( V_37 -> V_20 < 0 ) {
F_6 ( V_2 , - 1 , V_37 -> V_20 ) ;
if ( V_37 -> V_20 == - V_22 )
return 0 ;
}
if ( 1 ) {
V_40 = V_37 -> V_49 ;
V_42 = V_37 -> V_47 ;
V_41 = 0 ;
if ( V_4 -> V_51 ) {
V_43 = V_4 -> V_52 ;
} else {
V_43 =
F_13 ( V_40 ,
V_4 -> V_53 ,
& V_41 ) ;
}
V_43 &= 0xF0 ;
if ( V_43 ) {
V_41 += F_14 ( V_2 , V_4 ,
V_43 ,
V_40 + V_41 ,
V_42 - V_41 ) ;
}
while ( V_41 < V_42 ) {
T_1 V_54 = 0 ;
V_43 = F_15 (
V_40 + V_41 ,
V_42 - V_41 ,
& V_54 ) ;
V_41 += V_54 ;
V_43 &= 0xF0 ;
if ( V_43 && ( V_41 < V_42 ) ) {
V_41 += F_14 ( V_2 ,
V_4 , V_43 ,
V_40 + V_41 ,
V_42 - V_41 ) ;
}
}
memcpy ( V_4 -> V_53 , V_40 + V_42 - 4 , 4 ) ;
V_41 = 0 ;
}
return V_39 ;
}
T_2 F_13 ( T_2 * V_40 , T_2 * V_53 ,
T_1 * V_55 )
{
T_1 V_54 ;
T_2 V_56 [ 8 ] ;
T_2 V_43 = 0 ;
* V_55 = 0 ;
memcpy ( V_56 , V_53 , 4 ) ;
memcpy ( V_56 + 4 , V_40 , 4 ) ;
V_43 = F_15 ( ( T_2 * ) & V_56 , 8 ,
& V_54 ) ;
if ( V_43 ) {
* V_55 = V_54 - 4 ;
}
return V_43 ;
}
T_2 F_15 ( T_2 * V_40 , T_1 V_42 , T_1 * V_55 )
{
T_1 V_8 ;
T_2 V_43 = 0 ;
if ( V_42 < 4 ) {
* V_55 = V_42 ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < ( V_42 - 3 ) ; V_8 ++ ) {
if ( ( V_40 [ V_8 ] == 0xFF ) &&
( V_40 [ V_8 + 1 ] == 0x00 ) && ( V_40 [ V_8 + 2 ] == 0x00 ) ) {
* V_55 = V_8 + 4 ;
V_43 = V_40 [ V_8 + 3 ] ;
return V_43 ;
}
}
* V_55 = V_42 ;
return 0 ;
}
T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_43 ,
T_2 * V_40 , T_1 V_42 )
{
T_1 V_57 = 0 ;
int V_58 = - 1 ;
switch ( V_43 ) {
case V_59 :
if ( ( V_42 > 3 ) && ( V_40 [ 0 ] == 0xFF ) &&
( V_40 [ 1 ] == 0x00 ) && ( V_40 [ 2 ] == 0x00 ) &&
( ( V_40 [ 3 ] == V_60 ) ||
( V_40 [ 3 ] == V_61 ) ||
( V_40 [ 3 ] == V_62 ) ||
( V_40 [ 3 ] == V_63 ) ) )
return V_57 ;
V_58 = 1 ;
break;
case V_64 :
if ( ( V_42 > 3 ) && ( V_40 [ 0 ] == 0xFF ) &&
( V_40 [ 1 ] == 0x00 ) && ( V_40 [ 2 ] == 0x00 ) &&
( ( V_40 [ 3 ] == V_60 ) ||
( V_40 [ 3 ] == V_61 ) ||
( V_40 [ 3 ] == V_62 ) ||
( V_40 [ 3 ] == V_63 ) ) )
return V_57 ;
V_58 = 2 ;
break;
}
V_4 -> V_52 = V_43 ;
V_57 = F_17 ( V_2 , V_4 , V_40 ,
V_42 , V_58 ) ;
return V_57 ;
}
T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_65 ,
T_1 V_66 , int V_67 )
{
T_1 V_68 ;
struct V_5 * V_6 ;
T_1 V_69 = V_2 -> V_70 * 2 ;
if ( V_4 -> V_58 != V_67 )
F_18 ( V_2 , V_4 ) ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
V_4 -> V_58 = V_67 ;
V_68 = V_4 -> V_71 ;
if ( V_68 > V_66 )
V_68 = V_66 ;
if ( V_4 -> V_72 >= V_4 -> V_73 ) {
V_4 -> V_71 -= V_68 ;
V_4 -> V_51 = ( V_4 -> V_71 == 0 ) ?
0 : 1 ;
return 0 ;
}
V_4 -> V_51 = 1 ;
if ( ! V_6 ) {
V_4 -> V_71 -= V_68 ;
V_4 -> V_51 = ( V_4 -> V_71 == 0 )
? 0 : 1 ;
return V_68 ;
}
F_19 ( V_2 , V_4 , V_65 , V_68 ) ;
V_4 -> V_74 += V_68 ;
V_4 -> V_71 -= V_68 ;
if ( V_4 -> V_71 == 0 ) {
V_4 -> V_71 = V_69 ;
V_4 -> V_72 ++ ;
V_4 -> V_51 = 0 ;
if ( F_20 ( V_2 , V_4 ) && V_6 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_74 = 0 ;
V_6 = NULL ;
V_4 -> V_72 = 0 ;
}
}
return V_68 ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 -> V_58 == 1 ) {
if ( V_4 -> V_72 >= V_4 -> V_73 )
V_4 -> V_75 = 1 ;
else
V_4 -> V_75 = 0 ;
}
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 == NULL ) {
F_7 ( V_4 , & V_6 ) ;
V_4 -> V_74 = 0 ;
V_4 -> V_75 = 0 ;
V_4 -> V_58 = - 1 ;
}
V_4 -> V_71 = V_2 -> V_70 << 1 ;
V_4 -> V_72 = 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 * V_40 , T_1 V_68 )
{
T_2 * V_76 = NULL ;
T_1 V_77 = 0 ;
struct V_5 * V_6 ;
T_1 V_69 = V_2 -> V_70 << 1 ;
void * V_78 ;
int V_50 , V_79 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 == NULL )
return - 1 ;
V_76 = F_11 ( & V_6 -> V_7 ) ;
V_77 = V_69 - V_4 -> V_71 ;
V_50 = ( V_4 -> V_58 == 1 ) ? 0 : V_69 ;
V_78 = V_76 + V_50 ;
V_78 += ( V_4 -> V_72 * V_69 * 2 ) ;
V_78 += V_77 ;
V_79 = V_4 -> V_71 > V_68 ?
V_68 : V_4 -> V_71 ;
if ( ( T_2 * ) ( V_78 + V_79 ) > ( T_2 * ) ( V_76 + V_6 -> V_7 . V_36 ) )
return 0 ;
F_21 ( ( V_80 * ) V_40 , ( V_80 * ) V_78 , ( V_80 ) V_79 ) ;
return 0 ;
}
void F_21 ( V_80 * V_81 , V_80 * V_82 , V_80 V_83 )
{
V_80 V_8 ;
if ( V_83 <= 0 )
return;
for ( V_8 = 0 ; V_8 < V_83 / 2 ; V_8 ++ )
V_82 [ V_8 ] = ( V_81 [ V_8 ] << 8 ) | ( V_81 [ V_8 ] >> 8 ) ;
}
T_2 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_84 = 0 ;
V_84 = ( ( V_4 -> V_58 == 2 ) &&
( V_4 -> V_72 >= V_4 -> V_73 ) &&
V_4 -> V_75 ) ;
return V_84 ;
}
static int
F_22 ( struct V_85 * V_86 , unsigned int * V_87 , unsigned int * V_36 )
{
struct V_88 * V_89 = V_86 -> V_90 ;
struct V_1 * V_2 = V_89 -> V_2 ;
* V_36 = ( V_89 -> V_2 -> V_70 * V_89 -> V_2 -> V_91 * V_2 -> V_92 -> V_93 + 7 ) >> 3 ;
if ( 0 == * V_87 )
* V_87 = V_94 ;
if ( * V_87 < V_95 )
* V_87 = V_95 ;
return 0 ;
}
static void F_23 ( struct V_85 * V_86 , struct V_5 * V_6 )
{
struct V_88 * V_89 = V_86 -> V_90 ;
struct V_1 * V_2 = V_89 -> V_2 ;
unsigned long V_96 = 0 ;
if ( F_24 () )
F_25 () ;
F_26 ( & V_2 -> V_14 . V_97 , V_96 ) ;
if ( V_2 -> V_13 ) {
if ( V_2 -> V_14 . V_15 . V_6 == V_6 )
V_2 -> V_14 . V_15 . V_6 = NULL ;
} else {
if ( V_2 -> V_14 . V_16 . V_6 == V_6 )
V_2 -> V_14 . V_16 . V_6 = NULL ;
}
F_27 ( & V_2 -> V_14 . V_97 , V_96 ) ;
F_28 ( & V_6 -> V_7 ) ;
V_6 -> V_7 . V_9 = V_98 ;
}
static int
F_29 ( struct V_85 * V_86 , struct V_99 * V_7 ,
enum V_100 V_101 )
{
struct V_88 * V_89 = V_86 -> V_90 ;
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 = 0 , V_102 = 0 ;
V_6 -> V_7 . V_36 = ( V_89 -> V_2 -> V_70 * V_89 -> V_2 -> V_91 * V_2 -> V_92 -> V_93
+ 7 ) >> 3 ;
if ( 0 != V_6 -> V_7 . V_103 && V_6 -> V_7 . V_104 < V_6 -> V_7 . V_36 )
return - V_105 ;
V_6 -> V_7 . V_70 = V_2 -> V_70 ;
V_6 -> V_7 . V_91 = V_2 -> V_91 ;
V_6 -> V_7 . V_101 = V_101 ;
if ( V_98 == V_6 -> V_7 . V_9 ) {
V_39 = F_30 ( V_86 , & V_6 -> V_7 , NULL ) ;
if ( V_39 < 0 )
goto V_106;
}
if ( V_2 -> V_13 ) {
if ( ! V_2 -> V_14 . V_15 . V_107 )
V_102 = 1 ;
} else {
if ( ! V_2 -> V_14 . V_16 . V_107 )
V_102 = 1 ;
}
if ( V_102 ) {
V_2 -> V_108 = 0 ;
if ( V_2 -> V_13 )
V_39 = F_31 ( V_2 , V_109 ,
V_110 ,
V_2 -> V_14 . V_48 ,
F_12 ) ;
else
V_39 = F_32 ( V_2 , V_109 ,
V_110 ,
V_2 -> V_14 . V_48 ,
F_16 ) ;
if ( V_39 < 0 )
goto V_106;
}
V_6 -> V_7 . V_9 = V_111 ;
return 0 ;
V_106:
F_23 ( V_86 , V_6 ) ;
return V_39 ;
}
static void F_33 ( struct V_85 * V_86 , struct V_99 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_88 * V_89 = V_86 -> V_90 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_3 * V_32 = & V_2 -> V_14 . V_32 ;
V_6 -> V_7 . V_9 = V_112 ;
F_34 ( & V_6 -> V_7 . V_17 , & V_32 -> V_34 ) ;
}
static void F_35 ( struct V_85 * V_86 ,
struct V_99 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_88 * V_89 = V_86 -> V_90 ;
struct V_1 * V_2 = (struct V_1 * ) V_89 -> V_2 ;
F_2 ( L_15 ) ;
F_23 ( V_86 , V_6 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_113 )
{
V_2 -> V_114 = V_113 ;
V_2 -> V_115 = F_37 ( V_113 ) -> V_116 ;
F_38 ( V_2 , V_113 ) ;
F_39 ( V_2 , V_117 , V_118 , F_37 ( V_113 ) -> V_119 , 0 , 0 ) ;
F_40 ( V_2 , V_2 -> V_115 ) ;
F_41 ( L_16 , V_113 ) ;
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 = 0 ;
if ( V_89 -> V_120 )
return V_39 ;
if ( V_89 -> type == V_121 ) {
if ( V_2 -> V_120 )
return - V_122 ;
V_2 -> V_120 = 1 ;
} else if ( V_89 -> type == V_123 ) {
if ( V_2 -> V_124 )
return - V_122 ;
V_2 -> V_124 = 1 ;
} else
return - V_105 ;
V_89 -> V_120 = 1 ;
return V_39 ;
}
static int F_44 ( struct V_88 * V_89 )
{
return V_89 -> V_120 ;
}
static void F_45 ( struct V_88 * V_89 )
{
struct V_1 * V_2 = V_89 -> V_2 ;
V_89 -> V_120 = 0 ;
if ( V_89 -> type == V_121 )
V_2 -> V_120 = 0 ;
if ( V_89 -> type == V_123 )
V_2 -> V_124 = 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_44 ) {
F_47 ( L_17 ) ;
return - V_125 ;
}
return 0 ;
}
static int F_48 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> V_130 . V_131 . V_70 = V_2 -> V_70 ;
V_129 -> V_130 . V_131 . V_91 = V_2 -> V_91 ;
V_129 -> V_130 . V_131 . V_132 = V_2 -> V_92 -> V_133 ;
V_129 -> V_130 . V_131 . V_134 = ( V_2 -> V_70 * V_2 -> V_92 -> V_93 + 7 ) >> 3 ;
V_129 -> V_130 . V_131 . V_135 = V_129 -> V_130 . V_131 . V_134 * V_2 -> V_91 ;
V_129 -> V_130 . V_131 . V_136 = V_137 ;
V_129 -> V_130 . V_131 . V_101 = V_138 ;
V_129 -> V_130 . V_131 . V_127 = 0 ;
return 0 ;
}
static struct V_139 * F_49 ( unsigned int V_133 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_50 ( V_92 ) ; V_8 ++ )
if ( V_92 [ V_8 ] . V_133 == V_133 )
return & V_92 [ V_8 ] ;
return NULL ;
}
static int F_51 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
unsigned int V_70 = V_129 -> V_130 . V_131 . V_70 ;
unsigned int V_91 = V_129 -> V_130 . V_131 . V_91 ;
unsigned int V_140 = F_52 ( V_2 ) ;
unsigned int V_141 = F_53 ( V_2 ) ;
struct V_139 * V_130 ;
V_130 = F_49 ( V_129 -> V_130 . V_131 . V_132 ) ;
if ( ! V_130 ) {
F_54 ( L_18 ,
V_129 -> V_130 . V_131 . V_132 ) ;
return - V_105 ;
}
F_55 ( & V_70 , 48 , V_140 , 1 , & V_91 , 32 , V_141 , 1 , 0 ) ;
V_129 -> V_130 . V_131 . V_70 = V_70 ;
V_129 -> V_130 . V_131 . V_91 = V_91 ;
V_129 -> V_130 . V_131 . V_132 = V_130 -> V_133 ;
V_129 -> V_130 . V_131 . V_134 = ( V_70 * V_130 -> V_93 + 7 ) >> 3 ;
V_129 -> V_130 . V_131 . V_135 = V_129 -> V_130 . V_131 . V_134 * V_91 ;
V_129 -> V_130 . V_131 . V_136 = V_137 ;
V_129 -> V_130 . V_131 . V_101 = V_138 ;
V_129 -> V_130 . V_131 . V_127 = 0 ;
return 0 ;
}
static int F_56 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
struct V_139 * V_130 ;
struct V_142 V_143 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_51 ( V_126 , V_127 , V_129 ) ;
V_130 = F_49 ( V_129 -> V_130 . V_131 . V_132 ) ;
if ( ! V_130 )
return - V_105 ;
if ( F_57 ( & V_89 -> V_144 ) ) {
F_47 ( L_19 , V_145 ) ;
return - V_122 ;
}
if ( V_2 -> V_120 && ! V_89 -> V_120 ) {
F_47 ( L_20 , V_145 ) ;
return - V_122 ;
}
V_2 -> V_70 = V_129 -> V_130 . V_131 . V_70 ;
V_2 -> V_91 = V_129 -> V_130 . V_131 . V_91 ;
V_2 -> V_92 = V_130 ;
F_58 ( & V_143 , & V_129 -> V_130 . V_131 , V_146 ) ;
F_59 ( V_2 , V_117 , V_147 , & V_143 ) ;
F_60 ( & V_129 -> V_130 . V_131 , & V_143 ) ;
return V_39 ;
}
static int F_61 ( struct V_126 * V_126 , void * V_127 , T_3 * V_148 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
* V_148 = V_2 -> V_149 ;
return 0 ;
}
static int F_62 ( struct V_126 * V_126 , void * V_127 , T_3 V_149 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_142 V_143 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_2 -> V_149 == V_149 )
return 0 ;
if ( F_57 ( & V_89 -> V_144 ) )
return - V_122 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_70 = 720 ;
V_2 -> V_91 = ( V_2 -> V_149 & V_150 ) ? 576 : 480 ;
F_59 ( V_2 , V_151 , V_152 , V_2 -> V_149 ) ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_153 = V_146 ;
V_143 . V_70 = V_2 -> V_70 ;
V_143 . V_91 = V_2 -> V_91 ;
F_59 ( V_2 , V_117 , V_147 , & V_143 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
int F_63 ( struct V_126 * V_126 , void * V_127 ,
struct V_154 * V_8 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
T_1 V_155 ;
unsigned int V_156 , V_157 ;
V_157 = V_8 -> V_113 ;
if ( V_157 >= V_158 )
return - V_105 ;
if ( 0 == F_37 ( V_157 ) -> type )
return - V_105 ;
V_8 -> V_113 = V_157 ;
V_8 -> type = V_159 ;
strcpy ( V_8 -> V_160 , V_161 [ F_37 ( V_157 ) -> type ] ) ;
if ( ( V_162 == F_37 ( V_157 ) -> type ) ||
( V_163 == F_37 ( V_157 ) -> type ) )
V_8 -> type = V_164 ;
V_8 -> V_165 = V_2 -> V_166 -> V_167 ;
if ( V_157 == V_2 -> V_114 ) {
V_156 = F_64 ( V_2 , V_168 ,
V_169 , 2 , & V_155 , 4 ) ;
if ( V_156 > 0 ) {
if ( ( V_155 & V_170 ) == 0x00 )
V_8 -> V_20 |= V_171 ;
if ( ( V_155 & V_172 ) == 0x00 )
V_8 -> V_20 |= V_173 ;
}
}
return 0 ;
}
int F_65 ( struct V_126 * V_126 , void * V_127 , unsigned int * V_8 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
* V_8 = V_2 -> V_114 ;
return 0 ;
}
int F_66 ( struct V_126 * V_126 , void * V_127 , unsigned int V_8 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_2 -> V_108 = 0 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_8 >= V_158 )
return - V_105 ;
if ( 0 == F_37 ( V_8 ) -> type )
return - V_105 ;
F_36 ( V_2 , V_8 ) ;
if ( F_37 ( V_8 ) -> type == V_162 ||
F_37 ( V_8 ) -> type == V_163 ) {
F_59 ( V_2 , V_151 , V_152 , V_2 -> V_149 ) ;
}
return 0 ;
}
int F_67 ( struct V_126 * V_126 , void * V_127 , struct V_174 * V_175 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_175 -> V_113 )
return - V_105 ;
strcpy ( V_175 -> V_160 , L_21 ) ;
V_175 -> type = V_176 ;
V_175 -> V_177 = V_178 ;
V_175 -> V_179 = 0xffffffffUL ;
V_175 -> signal = 0xffff ;
F_59 ( V_2 , V_180 , V_181 , V_175 ) ;
return 0 ;
}
int F_68 ( struct V_126 * V_126 , void * V_127 , const struct V_174 * V_175 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_175 -> V_113 )
return - V_105 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
int F_69 ( struct V_126 * V_126 , void * V_127 ,
struct V_182 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_129 -> V_180 )
return - V_105 ;
V_129 -> V_183 = V_2 -> V_184 ;
return 0 ;
}
int F_70 ( struct V_126 * V_126 , void * V_127 ,
const struct V_182 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_182 V_185 = * V_129 ;
int V_39 ;
T_1 V_186 = 5400000 ;
F_41 ( L_22 ,
V_129 -> V_183 , V_129 -> type ) ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_129 -> V_180 )
return - V_105 ;
V_39 = F_71 ( V_2 ) ;
F_59 ( V_2 , V_180 , V_187 , V_129 ) ;
F_59 ( V_2 , V_180 , V_188 , & V_185 ) ;
V_2 -> V_184 = V_185 . V_183 ;
V_39 = F_72 ( V_2 ) ;
if ( V_2 -> V_189 == V_190 ) {
if ( V_2 -> V_149 & ( V_191 | V_192 ) )
V_186 = 5400000 ;
else if ( V_2 -> V_149 & V_193 )
V_186 = 6000000 ;
else if ( V_2 -> V_149 & ( V_194 | V_195 ) )
V_186 = 6900000 ;
else if ( V_2 -> V_149 & V_196 )
V_186 = 7100000 ;
else if ( V_2 -> V_149 & V_197 )
V_186 = 7250000 ;
else if ( V_2 -> V_149 & V_198 )
V_186 = 6900000 ;
else if ( V_2 -> V_149 & V_199 )
V_186 = 1250000 ;
F_41 ( L_23 , V_186 ) ;
F_73 ( V_2 , V_186 , 1 , 1 ) ;
F_74 ( V_2 ) ;
}
F_41 ( L_24 , V_129 -> V_183 ) ;
return V_39 ;
}
int F_75 ( struct V_126 * V_126 , void * V_89 ,
struct V_200 * V_201 )
{
V_201 -> V_202 = V_203 ;
V_201 -> V_204 = 0 ;
if ( V_201 -> V_205 . type == V_206 ) {
if ( F_76 ( & V_201 -> V_205 ) )
V_201 -> V_202 = V_207 ;
return 0 ;
}
return - V_105 ;
}
int F_77 ( struct V_126 * V_126 , void * V_127 ,
struct V_208 * V_209 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_156 = 0 ;
T_2 V_210 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_211 = 0 ;
switch ( V_209 -> V_205 . type ) {
case V_206 :
switch ( V_209 -> V_205 . V_212 ) {
case 0 :
V_156 = F_78 ( V_2 , V_213 ,
( V_80 ) V_209 -> V_209 , V_210 , 4 ) ;
V_209 -> V_214 = V_210 [ 0 ] | V_210 [ 1 ] << 8 |
V_210 [ 2 ] << 16 | V_210 [ 3 ] << 24 ;
break;
case 1 :
V_156 = F_64 ( V_2 , V_215 ,
( V_80 ) V_209 -> V_209 , 2 , & V_211 , 1 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 14 :
V_156 = F_64 ( V_2 , V_215 ,
( V_80 ) V_209 -> V_209 , 2 , & V_211 , 4 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
break;
case 2 :
V_156 = F_64 ( V_2 , V_168 ,
( V_80 ) V_209 -> V_209 , 2 , & V_211 , 1 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 24 :
V_156 = F_64 ( V_2 , V_168 ,
( V_80 ) V_209 -> V_209 , 2 , & V_211 , 4 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
break;
case 3 :
V_156 = F_64 ( V_2 ,
V_216 ,
( V_80 ) V_209 -> V_209 , 1 ,
& V_211 , 1 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 34 :
V_156 =
F_64 ( V_2 , V_216 ,
( V_80 ) V_209 -> V_209 , 1 , & V_211 , 4 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
break;
}
return V_156 < 0 ? V_156 : 0 ;
case V_217 :
F_59 ( V_2 , V_151 , V_218 , V_209 ) ;
return 0 ;
case V_219 :
switch ( V_209 -> V_205 . V_212 ) {
case 0 :
V_156 = F_78 ( V_2 , V_213 ,
( V_80 ) V_209 -> V_209 , V_210 , 4 ) ;
V_209 -> V_214 = V_210 [ 0 ] | V_210 [ 1 ] << 8 |
V_210 [ 2 ] << 16 | V_210 [ 3 ] << 24 ;
break;
case 0x600 :
V_156 = F_80 ( V_2 , V_215 ,
( V_80 ) V_209 -> V_209 , 2 ,
& V_211 , 1 , 0 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 0x880 :
if ( V_209 -> V_209 < 0x0b ) {
V_156 = F_80 ( V_2 ,
V_168 ,
( V_80 ) V_209 -> V_209 , 2 ,
& V_211 , 1 , 0 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
} else {
V_156 = F_80 ( V_2 ,
V_168 ,
( V_80 ) V_209 -> V_209 , 2 ,
& V_211 , 4 , 0 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
}
break;
case 0x980 :
V_156 = F_80 ( V_2 ,
V_216 ,
( V_80 ) V_209 -> V_209 , 1 ,
& V_211 , 1 , 0 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 0x400 :
V_156 =
F_80 ( V_2 , 0x40 ,
( V_80 ) V_209 -> V_209 , 1 ,
& V_211 , 1 , 0 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 0xc01 :
V_156 =
F_80 ( V_2 , 0xc0 ,
( V_80 ) V_209 -> V_209 , 2 ,
& V_211 , 38 , 1 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
break;
case 0x022 :
V_156 =
F_80 ( V_2 , 0x02 ,
( V_80 ) V_209 -> V_209 , 1 ,
& V_211 , 1 , 2 ) ;
V_209 -> V_214 = F_79 ( V_211 & 0xff ) ;
break;
case 0x322 :
V_156 = F_80 ( V_2 ,
0x32 ,
( V_80 ) V_209 -> V_209 , 1 ,
& V_211 , 4 , 2 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
break;
case 0x342 :
V_156 = F_80 ( V_2 ,
0x34 ,
( V_80 ) V_209 -> V_209 , 1 ,
& V_211 , 4 , 2 ) ;
V_209 -> V_214 = F_79 ( V_211 ) ;
break;
default:
F_41 ( L_25 ) ;
break;
}
return V_156 < 0 ? V_156 : 0 ;
default:
if ( ! F_76 ( & V_209 -> V_205 ) )
return - V_105 ;
}
F_59 ( V_2 , V_151 , V_218 , V_209 ) ;
return V_156 ;
}
int F_81 ( struct V_126 * V_126 , void * V_127 ,
const struct V_208 * V_209 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_156 = 0 ;
T_4 V_6 ;
T_1 V_210 ;
T_2 V_211 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_6 = F_82 ( V_209 -> V_214 ) ;
switch ( V_209 -> V_205 . type ) {
case V_206 :
{
V_210 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_209 -> V_205 . V_212 ) {
case 0 :
V_211 [ 0 ] = ( T_2 ) V_210 ;
V_211 [ 1 ] = ( T_2 ) ( V_210 >> 8 ) ;
V_211 [ 2 ] = ( T_2 ) ( V_210 >> 16 ) ;
V_211 [ 3 ] = ( T_2 ) ( V_210 >> 24 ) ;
V_156 = F_83 ( V_2 ,
V_220 ,
( V_80 ) V_209 -> V_209 , V_211 ,
4 ) ;
break;
case 1 :
V_156 = F_84 ( V_2 ,
V_215 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 1 ) ;
break;
case 14 :
V_156 = F_84 ( V_2 ,
V_215 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 4 ) ;
break;
case 2 :
V_156 =
F_84 ( V_2 ,
V_168 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 1 ) ;
break;
case 24 :
V_156 =
F_84 ( V_2 ,
V_168 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 4 ) ;
break;
case 3 :
V_156 =
F_84 ( V_2 ,
V_216 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 1 ) ;
break;
case 34 :
V_156 =
F_84 ( V_2 ,
V_216 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 4 ) ;
break;
}
}
return V_156 < 0 ? V_156 : 0 ;
case V_219 :
{
V_210 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_209 -> V_205 . V_212 ) {
case 0 :
V_211 [ 0 ] = ( T_2 ) V_210 ;
V_211 [ 1 ] = ( T_2 ) ( V_210 >> 8 ) ;
V_211 [ 2 ] = ( T_2 ) ( V_210 >> 16 ) ;
V_211 [ 3 ] = ( T_2 ) ( V_210 >> 24 ) ;
V_156 = F_83 ( V_2 ,
V_220 ,
( V_80 ) V_209 -> V_209 , V_211 ,
4 ) ;
break;
case 0x600 :
V_156 = F_85 ( V_2 ,
V_215 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 1 , 0 ) ;
break;
case 0x880 :
if ( V_209 -> V_209 < 0x0b )
F_85 ( V_2 ,
V_168 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 1 , 0 ) ;
else
F_85 ( V_2 ,
V_168 ,
( V_80 ) V_209 -> V_209 , 2 ,
V_210 , 4 , 0 ) ;
break;
case 0x980 :
V_156 =
F_85 ( V_2 ,
V_216 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 1 , 0 ) ;
break;
case 0x400 :
V_156 =
F_85 ( V_2 ,
0x40 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 1 , 0 ) ;
break;
case 0xc01 :
V_156 =
F_85 ( V_2 ,
0xc0 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 1 , 1 ) ;
break;
case 0x022 :
V_156 =
F_85 ( V_2 ,
0x02 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 1 , 2 ) ;
break;
case 0x322 :
V_156 =
F_85 ( V_2 ,
0x32 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 4 , 2 ) ;
break;
case 0x342 :
V_156 =
F_85 ( V_2 ,
0x34 ,
( V_80 ) V_209 -> V_209 , 1 ,
V_210 , 4 , 2 ) ;
break;
default:
F_41 ( L_26
L_27 , V_209 -> V_205 . V_212 ) ;
break;
}
}
default:
break;
}
F_59 ( V_2 , V_151 , V_221 , V_209 ) ;
return V_156 ;
}
static int F_86 ( struct V_126 * V_126 , void * V_127 ,
struct V_222 * V_223 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_223 -> type != V_121 )
return - V_105 ;
V_223 -> V_224 . V_225 = 0 ;
V_223 -> V_224 . V_226 = 0 ;
V_223 -> V_224 . V_70 = V_2 -> V_70 ;
V_223 -> V_224 . V_91 = V_2 -> V_91 ;
V_223 -> V_227 = V_223 -> V_224 ;
V_223 -> V_228 . V_229 = 54 ;
V_223 -> V_228 . V_230 = 59 ;
return 0 ;
}
static int F_87 ( struct V_126 * V_126 , void * V_127 ,
enum V_231 type )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_88 ( V_39 >= 0 ) )
V_39 = F_89 ( & V_89 -> V_144 ) ;
F_59 ( V_2 , V_117 , V_232 , 1 ) ;
return V_39 ;
}
static int F_90 ( struct V_126 * V_126 , void * V_127 ,
enum V_231 type )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( type != V_89 -> type )
return - V_105 ;
F_39 ( V_2 , V_117 , V_232 , 0 ) ;
F_91 ( & V_89 -> V_144 ) ;
F_45 ( V_89 ) ;
return 0 ;
}
int F_92 ( struct V_126 * V_126 , void * V_127 ,
struct V_233 * V_234 )
{
struct V_235 * V_166 = F_93 ( V_126 ) ;
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_94 ( V_234 -> V_236 , L_28 , sizeof( V_234 -> V_236 ) ) ;
F_94 ( V_234 -> V_237 , V_238 [ V_2 -> V_239 ] . V_160 , sizeof( V_234 -> V_237 ) ) ;
F_95 ( V_2 -> V_240 , V_234 -> V_241 , sizeof( V_234 -> V_241 ) ) ;
if ( V_166 -> V_242 == V_243 )
V_234 -> V_244 = V_245 ;
else {
V_234 -> V_244 = V_246 | V_247 ;
if ( V_166 -> V_242 == V_248 )
V_234 -> V_244 |= V_249 ;
else
V_234 -> V_244 |= V_250 ;
}
if ( V_2 -> V_189 != V_251 )
V_234 -> V_244 |= V_252 ;
V_234 -> V_253 = V_234 -> V_244 | V_246 |
V_249 | V_250 |
V_247 | V_254 ;
if ( V_2 -> V_255 )
V_234 -> V_253 |= V_245 ;
return 0 ;
}
static int F_96 ( struct V_126 * V_126 , void * V_127 ,
struct V_256 * V_129 )
{
if ( F_97 ( V_129 -> V_113 >= F_50 ( V_92 ) ) )
return - V_105 ;
F_94 ( V_129 -> V_257 , V_92 [ V_129 -> V_113 ] . V_160 , sizeof( V_129 -> V_257 ) ) ;
V_129 -> V_132 = V_92 [ V_129 -> V_113 ] . V_133 ;
return 0 ;
}
static int F_98 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> V_130 . V_258 . V_259 = 6750000 * 4 ;
V_129 -> V_130 . V_258 . V_260 = V_261 ;
V_129 -> V_130 . V_258 . V_262 = V_263 ;
V_129 -> V_130 . V_258 . V_50 = 0 ;
V_129 -> V_130 . V_258 . V_264 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_265 : V_266 ;
V_129 -> V_130 . V_258 . V_87 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_267 : V_268 ;
V_129 -> V_130 . V_258 . V_264 [ 1 ] = ( V_2 -> V_149 & V_150 ) ?
V_265 + 312 : V_266 + 263 ;
V_129 -> V_130 . V_258 . V_87 [ 1 ] = V_129 -> V_130 . V_258 . V_87 [ 0 ] ;
memset ( V_129 -> V_130 . V_258 . V_269 , 0 , sizeof( V_129 -> V_130 . V_258 . V_269 ) ) ;
return 0 ;
}
static int F_99 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> V_130 . V_258 . V_259 = 6750000 * 4 ;
V_129 -> V_130 . V_258 . V_260 = V_261 ;
V_129 -> V_130 . V_258 . V_262 = V_263 ;
V_129 -> V_130 . V_258 . V_50 = 0 ;
V_129 -> V_130 . V_258 . V_96 = 0 ;
V_129 -> V_130 . V_258 . V_264 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_265 : V_266 ;
V_129 -> V_130 . V_258 . V_87 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_267 : V_268 ;
V_129 -> V_130 . V_258 . V_264 [ 1 ] = ( V_2 -> V_149 & V_150 ) ?
V_265 + 312 : V_266 + 263 ;
V_129 -> V_130 . V_258 . V_87 [ 1 ] = V_129 -> V_130 . V_258 . V_87 [ 0 ] ;
memset ( V_129 -> V_130 . V_258 . V_269 , 0 , sizeof( V_129 -> V_130 . V_258 . V_269 ) ) ;
return 0 ;
}
static int F_100 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_2 -> V_124 && ! V_89 -> V_120 ) {
F_47 ( L_20 , V_145 ) ;
return - V_122 ;
}
return F_99 ( V_126 , V_127 , V_129 ) ;
}
static int F_101 ( struct V_126 * V_126 , void * V_127 ,
struct V_270 * V_271 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_102 ( & V_89 -> V_144 , V_271 ) ;
}
static int F_103 ( struct V_126 * V_126 , void * V_127 , struct V_272 * V_273 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_104 ( & V_89 -> V_144 , V_273 ) ;
}
static int F_105 ( struct V_126 * V_126 , void * V_127 , struct V_272 * V_273 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_106 ( & V_89 -> V_144 , V_273 ) ;
}
static int F_107 ( struct V_126 * V_126 , void * V_127 , struct V_272 * V_273 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_108 ( & V_89 -> V_144 , V_273 , V_126 -> V_274 & V_275 ) ;
}
static int F_109 ( struct V_126 * V_126 , void * V_127 , struct V_174 * V_175 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
if ( V_175 -> V_113 )
return - V_105 ;
strcpy ( V_175 -> V_160 , L_29 ) ;
F_59 ( V_2 , V_180 , V_181 , V_175 ) ;
return 0 ;
}
static int F_110 ( struct V_126 * V_126 , void * V_127 , const struct V_174 * V_175 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
if ( V_175 -> V_113 )
return - V_105 ;
F_59 ( V_2 , V_180 , V_276 , V_175 ) ;
return 0 ;
}
static int F_111 ( struct V_126 * V_277 )
{
int V_278 = 0 , V_279 = 0 ;
struct V_235 * V_166 = F_93 ( V_277 ) ;
struct V_1 * V_2 = F_112 ( V_277 ) ;
struct V_88 * V_89 ;
enum V_231 V_280 = 0 ;
switch ( V_166 -> V_242 ) {
case V_281 :
V_280 = V_121 ;
break;
case V_248 :
V_280 = V_123 ;
break;
case V_243 :
V_279 = 1 ;
break;
}
F_54 ( L_30 ,
F_113 ( V_166 ) , V_282 [ V_280 ] ,
V_2 -> V_283 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
cx231xx_errdev
("Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_89 = F_114 ( sizeof( struct V_88 ) , V_284 ) ;
if ( ! V_89 ) {
F_47 ( L_31 ) ;
return - V_285 ;
}
if ( F_115 ( & V_2 -> V_286 ) ) {
F_116 ( V_89 ) ;
return - V_287 ;
}
V_89 -> V_2 = V_2 ;
V_89 -> type = V_280 ;
V_277 -> V_288 = V_89 ;
F_117 ( & V_89 -> V_89 , V_166 ) ;
if ( V_89 -> type == V_121 && V_2 -> V_283 == 0 ) {
if ( V_2 -> V_289 . V_290 )
F_118 ( V_2 ,
V_291 ) ;
else
F_118 ( V_2 , V_292 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_119 ( V_2 ) ;
F_120 ( V_2 ) ;
V_2 -> V_114 = V_2 -> V_114 > 2 ? 2 : V_2 -> V_114 ;
}
if ( V_279 ) {
F_54 ( L_32 ) ;
F_59 ( V_2 , V_180 , V_293 ) ;
}
V_2 -> V_283 ++ ;
if ( V_89 -> type == V_121 )
F_121 ( & V_89 -> V_144 , & V_294 ,
NULL , & V_2 -> V_14 . V_97 ,
V_89 -> type , V_138 ,
sizeof( struct V_5 ) ,
V_89 , & V_2 -> V_286 ) ;
if ( V_89 -> type == V_123 ) {
F_122 ( V_2 , V_295 , 0 ) ;
F_121 ( & V_89 -> V_144 , & V_296 ,
NULL , & V_2 -> V_297 . V_97 ,
V_89 -> type , V_298 ,
sizeof( struct V_5 ) ,
V_89 , & V_2 -> V_286 ) ;
}
F_123 ( & V_2 -> V_286 ) ;
F_124 ( & V_89 -> V_89 ) ;
return V_278 ;
}
void F_125 ( struct V_1 * V_2 )
{
if ( V_2 -> V_255 ) {
if ( F_126 ( V_2 -> V_255 ) )
F_127 ( V_2 -> V_255 ) ;
else
F_128 ( V_2 -> V_255 ) ;
V_2 -> V_255 = NULL ;
}
if ( V_2 -> V_299 ) {
F_41 ( L_33 ,
F_113 ( V_2 -> V_299 ) ) ;
if ( F_126 ( V_2 -> V_299 ) )
F_127 ( V_2 -> V_299 ) ;
else
F_128 ( V_2 -> V_299 ) ;
V_2 -> V_299 = NULL ;
}
if ( V_2 -> V_166 ) {
F_41 ( L_33 ,
F_113 ( V_2 -> V_166 ) ) ;
if ( V_2 -> V_289 . V_300 )
F_129 ( V_2 ) ;
if ( F_126 ( V_2 -> V_166 ) )
F_127 ( V_2 -> V_166 ) ;
else
F_128 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
}
F_130 ( & V_2 -> V_301 ) ;
F_130 ( & V_2 -> V_302 ) ;
}
static int F_131 ( struct V_126 * V_277 )
{
struct V_88 * V_89 = V_277 -> V_288 ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_54 ( L_34 , V_2 -> V_283 ) ;
F_54 ( L_34 , V_2 -> V_283 ) ;
if ( F_44 ( V_89 ) )
F_45 ( V_89 ) ;
if ( ! V_2 -> V_289 . V_303 )
if ( V_89 -> type == V_123 ) {
F_132 ( & V_89 -> V_144 ) ;
F_133 ( & V_89 -> V_144 ) ;
if ( V_2 -> V_9 & V_44 ) {
if ( F_134 ( & V_2 -> V_304 ) > 0 ) {
F_135 ( V_2 ) ;
V_89 -> V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_136 ( V_2 ) ;
if ( ! V_2 -> V_305 )
F_122 ( V_2 , V_295 , 0 ) ;
else
F_122 ( V_2 , V_306 , 0 ) ;
F_137 ( & V_89 -> V_89 ) ;
F_138 ( & V_89 -> V_89 ) ;
F_116 ( V_89 ) ;
V_2 -> V_283 -- ;
F_139 ( & V_2 -> V_307 , 1 ) ;
return 0 ;
}
F_137 ( & V_89 -> V_89 ) ;
V_2 -> V_283 -- ;
if ( ! V_2 -> V_283 ) {
F_132 ( & V_89 -> V_144 ) ;
F_133 ( & V_89 -> V_144 ) ;
if ( V_2 -> V_9 & V_44 ) {
F_135 ( V_2 ) ;
V_89 -> V_2 = NULL ;
return 0 ;
}
F_59 ( V_2 , V_151 , V_308 , 0 ) ;
if ( V_2 -> V_13 )
F_140 ( V_2 ) ;
else
F_141 ( V_2 ) ;
F_142 ( V_2 , V_309 ) ;
F_122 ( V_2 , V_310 , 0 ) ;
}
F_138 ( & V_89 -> V_89 ) ;
F_116 ( V_89 ) ;
F_139 ( & V_2 -> V_307 , 1 ) ;
return 0 ;
}
static int F_143 ( struct V_126 * V_277 )
{
struct V_88 * V_89 = V_277 -> V_288 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
F_144 ( & V_2 -> V_286 ) ;
V_39 = F_131 ( V_277 ) ;
F_123 ( & V_2 -> V_286 ) ;
return V_39 ;
}
static T_5
F_145 ( struct V_126 * V_277 , char T_6 * V_6 , T_7 V_87 ,
T_8 * V_74 )
{
struct V_88 * V_89 = V_277 -> V_288 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_89 -> type == V_121 ) ||
( V_89 -> type == V_123 ) ) {
V_39 = F_43 ( V_89 ) ;
if ( F_97 ( V_39 < 0 ) )
return V_39 ;
if ( F_115 ( & V_2 -> V_286 ) )
return - V_287 ;
V_39 = F_146 ( & V_89 -> V_144 , V_6 , V_87 , V_74 , 0 ,
V_277 -> V_274 & V_275 ) ;
F_123 ( & V_2 -> V_286 ) ;
return V_39 ;
}
return 0 ;
}
static unsigned int F_147 ( struct V_126 * V_277 , T_9 * V_311 )
{
unsigned long V_312 = F_148 ( V_311 ) ;
struct V_88 * V_89 = V_277 -> V_288 ;
struct V_1 * V_2 = V_89 -> V_2 ;
unsigned V_313 = 0 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_314 ;
V_39 = F_43 ( V_89 ) ;
if ( F_97 ( V_39 < 0 ) )
return V_314 ;
if ( F_149 ( & V_89 -> V_89 ) )
V_313 |= V_315 ;
else
F_150 ( V_277 , & V_89 -> V_89 . V_311 , V_311 ) ;
if ( ! ( V_312 & ( V_316 | V_317 ) ) )
return V_313 ;
if ( ( V_121 == V_89 -> type ) ||
( V_123 == V_89 -> type ) ) {
F_144 ( & V_2 -> V_286 ) ;
V_313 |= F_151 ( V_277 , & V_89 -> V_144 , V_311 ) ;
F_123 ( & V_2 -> V_286 ) ;
return V_313 ;
}
return V_313 | V_314 ;
}
static int F_152 ( struct V_126 * V_277 , struct V_318 * V_319 )
{
struct V_88 * V_89 = V_277 -> V_288 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_97 ( V_39 < 0 ) )
return V_39 ;
if ( F_115 ( & V_2 -> V_286 ) )
return - V_287 ;
V_39 = F_153 ( & V_89 -> V_144 , V_319 ) ;
F_123 ( & V_2 -> V_286 ) ;
F_54 ( L_35 ,
( unsigned long ) V_319 -> V_320 ,
( unsigned long ) V_319 -> V_321 -
( unsigned long ) V_319 -> V_320 , V_39 ) ;
return V_39 ;
}
static struct V_235 * F_154 ( struct V_1 * V_2 ,
const struct V_235
* V_322 , const char * V_323 )
{
struct V_235 * V_324 ;
V_324 = F_155 () ;
if ( NULL == V_324 )
return NULL ;
* V_324 = * V_322 ;
V_324 -> V_325 = & V_2 -> V_325 ;
V_324 -> V_326 = F_128 ;
V_324 -> V_327 = V_328 ;
V_324 -> V_286 = & V_2 -> V_286 ;
F_156 ( V_329 , & V_324 -> V_96 ) ;
snprintf ( V_324 -> V_160 , sizeof( V_324 -> V_160 ) , L_36 , V_2 -> V_160 , V_323 ) ;
F_157 ( V_324 , V_2 ) ;
if ( V_2 -> V_189 == V_251 ) {
F_158 ( V_324 , V_330 ) ;
F_158 ( V_324 , V_331 ) ;
F_158 ( V_324 , V_332 ) ;
F_158 ( V_324 , V_333 ) ;
}
return V_324 ;
}
int F_159 ( struct V_1 * V_2 )
{
int V_156 ;
F_41 ( L_37 ,
V_2 -> V_160 , V_334 ) ;
V_2 -> V_149 = V_335 ;
V_2 -> V_70 = F_52 ( V_2 ) ;
V_2 -> V_91 = F_53 ( V_2 ) ;
V_2 -> V_336 = 0 ;
V_2 -> V_92 = & V_92 [ 0 ] ;
F_36 ( V_2 , V_2 -> V_114 ) ;
F_59 ( V_2 , V_151 , V_152 , V_2 -> V_149 ) ;
F_160 ( & V_2 -> V_301 , 10 ) ;
F_160 ( & V_2 -> V_302 , 5 ) ;
if ( V_2 -> V_337 ) {
F_161 ( & V_2 -> V_301 ,
V_2 -> V_337 -> V_301 , NULL ) ;
F_161 ( & V_2 -> V_302 ,
V_2 -> V_337 -> V_301 ,
V_338 ) ;
}
if ( V_2 -> V_301 . error )
return V_2 -> V_301 . error ;
if ( V_2 -> V_302 . error )
return V_2 -> V_302 . error ;
V_2 -> V_166 = F_154 ( V_2 , & V_339 , L_38 ) ;
if ( ! V_2 -> V_166 ) {
F_47 ( L_39 ) ;
return - V_125 ;
}
V_2 -> V_166 -> V_301 = & V_2 -> V_301 ;
V_156 = F_162 ( V_2 -> V_166 , V_281 ,
V_340 [ V_2 -> V_341 ] ) ;
if ( V_156 ) {
F_47 ( L_40 ,
V_156 ) ;
return V_156 ;
}
F_41 ( L_41 ,
V_2 -> V_160 , F_113 ( V_2 -> V_166 ) ) ;
V_342 = V_339 ;
strcpy ( V_342 . V_160 , L_42 ) ;
V_2 -> V_299 = F_154 ( V_2 , & V_342 , L_43 ) ;
if ( ! V_2 -> V_299 ) {
F_47 ( L_39 ) ;
return - V_125 ;
}
V_2 -> V_299 -> V_301 = & V_2 -> V_301 ;
V_156 = F_162 ( V_2 -> V_299 , V_248 ,
V_343 [ V_2 -> V_341 ] ) ;
if ( V_156 < 0 ) {
F_47 ( L_44 ) ;
return V_156 ;
}
F_41 ( L_45 ,
V_2 -> V_160 , F_113 ( V_2 -> V_299 ) ) ;
if ( V_238 [ V_2 -> V_239 ] . V_279 . type == V_344 ) {
V_2 -> V_255 = F_154 ( V_2 , & V_345 ,
L_46 ) ;
if ( ! V_2 -> V_255 ) {
F_47 ( L_39 ) ;
return - V_125 ;
}
V_2 -> V_255 -> V_301 = & V_2 -> V_302 ;
V_156 = F_162 ( V_2 -> V_255 , V_243 ,
V_346 [ V_2 -> V_341 ] ) ;
if ( V_156 < 0 ) {
F_47 ( L_47 ) ;
return V_156 ;
}
F_41 ( L_48 ,
F_113 ( V_2 -> V_255 ) ) ;
}
F_41 ( L_49 ,
F_113 ( V_2 -> V_166 ) ,
F_113 ( V_2 -> V_299 ) ) ;
return 0 ;
}
