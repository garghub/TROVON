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
int V_8 ;
unsigned char * V_39 ;
T_1 V_40 = 0 , V_41 = 0 ;
T_2 V_42 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_9 & V_43 )
return 0 ;
if ( V_37 -> V_20 < 0 ) {
F_6 ( V_2 , - 1 , V_37 -> V_20 ) ;
if ( V_37 -> V_20 == - V_22 )
return 0 ;
}
for ( V_8 = 0 ; V_8 < V_37 -> V_44 ; V_8 ++ ) {
int V_20 = V_37 -> V_45 [ V_8 ] . V_20 ;
if ( V_20 < 0 ) {
F_6 ( V_2 , V_8 , V_20 ) ;
if ( V_37 -> V_45 [ V_8 ] . V_20 != - V_27 )
continue;
}
if ( V_37 -> V_45 [ V_8 ] . V_46 <= 0 ) {
continue;
}
if ( V_37 -> V_45 [ V_8 ] . V_46 >
V_2 -> V_14 . V_47 ) {
F_2 ( L_14 ) ;
continue;
}
V_39 = V_37 -> V_48 + V_37 -> V_45 [ V_8 ] . V_49 ;
V_41 = V_37 -> V_45 [ V_8 ] . V_46 ;
V_40 = 0 ;
if ( V_4 -> V_50 ) {
V_42 = V_4 -> V_51 ;
} else {
V_42 =
F_13 ( V_39 ,
V_4 -> V_52 ,
& V_40 ) ;
}
V_42 &= 0xF0 ;
if ( V_42 ) {
V_40 += F_14 ( V_2 , V_4 ,
V_42 ,
V_39 + V_40 ,
V_41 - V_40 ) ;
}
while ( V_40 < V_41 ) {
T_1 V_53 = 0 ;
V_42 = F_15 (
V_39 + V_40 ,
V_41 - V_40 ,
& V_53 ) ;
V_40 += V_53 ;
V_42 &= 0xF0 ;
if ( V_42 && ( V_40 < V_41 ) ) {
V_40 += F_14 ( V_2 ,
V_4 , V_42 ,
V_39 + V_40 ,
V_41 - V_40 ) ;
}
}
memcpy ( V_4 -> V_52 , V_39 + V_41 - 4 , 4 ) ;
V_40 = 0 ;
}
return 1 ;
}
static inline int F_16 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
struct V_3 * V_4 = V_37 -> V_38 ;
unsigned char * V_39 ;
T_1 V_40 = 0 , V_41 = 0 ;
T_2 V_42 = 0 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_9 & V_43 )
return 0 ;
if ( V_37 -> V_20 < 0 ) {
F_6 ( V_2 , - 1 , V_37 -> V_20 ) ;
if ( V_37 -> V_20 == - V_22 )
return 0 ;
}
if ( 1 ) {
V_39 = V_37 -> V_48 ;
V_41 = V_37 -> V_46 ;
V_40 = 0 ;
if ( V_4 -> V_50 ) {
V_42 = V_4 -> V_51 ;
} else {
V_42 =
F_13 ( V_39 ,
V_4 -> V_52 ,
& V_40 ) ;
}
V_42 &= 0xF0 ;
if ( V_42 ) {
V_40 += F_14 ( V_2 , V_4 ,
V_42 ,
V_39 + V_40 ,
V_41 - V_40 ) ;
}
while ( V_40 < V_41 ) {
T_1 V_53 = 0 ;
V_42 = F_15 (
V_39 + V_40 ,
V_41 - V_40 ,
& V_53 ) ;
V_40 += V_53 ;
V_42 &= 0xF0 ;
if ( V_42 && ( V_40 < V_41 ) ) {
V_40 += F_14 ( V_2 ,
V_4 , V_42 ,
V_39 + V_40 ,
V_41 - V_40 ) ;
}
}
memcpy ( V_4 -> V_52 , V_39 + V_41 - 4 , 4 ) ;
V_40 = 0 ;
}
return 1 ;
}
T_2 F_13 ( T_2 * V_39 , T_2 * V_52 ,
T_1 * V_54 )
{
T_1 V_53 ;
T_2 V_55 [ 8 ] ;
T_2 V_42 = 0 ;
* V_54 = 0 ;
memcpy ( V_55 , V_52 , 4 ) ;
memcpy ( V_55 + 4 , V_39 , 4 ) ;
V_42 = F_15 ( ( T_2 * ) & V_55 , 8 ,
& V_53 ) ;
if ( V_42 ) {
* V_54 = V_53 - 4 ;
}
return V_42 ;
}
T_2 F_15 ( T_2 * V_39 , T_1 V_41 , T_1 * V_54 )
{
T_1 V_8 ;
T_2 V_42 = 0 ;
if ( V_41 < 4 ) {
* V_54 = V_41 ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < ( V_41 - 3 ) ; V_8 ++ ) {
if ( ( V_39 [ V_8 ] == 0xFF ) &&
( V_39 [ V_8 + 1 ] == 0x00 ) && ( V_39 [ V_8 + 2 ] == 0x00 ) ) {
* V_54 = V_8 + 4 ;
V_42 = V_39 [ V_8 + 3 ] ;
return V_42 ;
}
}
* V_54 = V_41 ;
return 0 ;
}
T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_42 ,
T_2 * V_39 , T_1 V_41 )
{
T_1 V_56 = 0 ;
int V_57 = - 1 ;
switch ( V_42 ) {
case V_58 :
if ( ( V_41 > 3 ) && ( V_39 [ 0 ] == 0xFF ) &&
( V_39 [ 1 ] == 0x00 ) && ( V_39 [ 2 ] == 0x00 ) &&
( ( V_39 [ 3 ] == V_59 ) ||
( V_39 [ 3 ] == V_60 ) ||
( V_39 [ 3 ] == V_61 ) ||
( V_39 [ 3 ] == V_62 ) ) )
return V_56 ;
V_57 = 1 ;
break;
case V_63 :
if ( ( V_41 > 3 ) && ( V_39 [ 0 ] == 0xFF ) &&
( V_39 [ 1 ] == 0x00 ) && ( V_39 [ 2 ] == 0x00 ) &&
( ( V_39 [ 3 ] == V_59 ) ||
( V_39 [ 3 ] == V_60 ) ||
( V_39 [ 3 ] == V_61 ) ||
( V_39 [ 3 ] == V_62 ) ) )
return V_56 ;
V_57 = 2 ;
break;
}
V_4 -> V_51 = V_42 ;
V_56 = F_17 ( V_2 , V_4 , V_39 ,
V_41 , V_57 ) ;
return V_56 ;
}
T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_64 ,
T_1 V_65 , int V_66 )
{
T_1 V_67 ;
struct V_5 * V_6 ;
T_1 V_68 = V_2 -> V_69 * 2 ;
if ( V_4 -> V_57 != V_66 )
F_18 ( V_2 , V_4 ) ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
V_4 -> V_57 = V_66 ;
V_67 = V_4 -> V_70 ;
if ( V_67 > V_65 )
V_67 = V_65 ;
if ( V_4 -> V_71 >= V_4 -> V_72 ) {
V_4 -> V_70 -= V_67 ;
V_4 -> V_50 = ( V_4 -> V_70 == 0 ) ?
0 : 1 ;
return 0 ;
}
V_4 -> V_50 = 1 ;
if ( ! V_6 ) {
V_4 -> V_70 -= V_67 ;
V_4 -> V_50 = ( V_4 -> V_70 == 0 )
? 0 : 1 ;
return V_67 ;
}
F_19 ( V_2 , V_4 , V_64 , V_67 ) ;
V_4 -> V_73 += V_67 ;
V_4 -> V_70 -= V_67 ;
if ( V_4 -> V_70 == 0 ) {
V_4 -> V_70 = V_68 ;
V_4 -> V_71 ++ ;
V_4 -> V_50 = 0 ;
if ( F_20 ( V_2 , V_4 ) && V_6 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_73 = 0 ;
V_6 = NULL ;
V_4 -> V_71 = 0 ;
}
}
return V_67 ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 -> V_57 == 1 ) {
if ( V_4 -> V_71 >= V_4 -> V_72 )
V_4 -> V_74 = 1 ;
else
V_4 -> V_74 = 0 ;
}
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 == NULL ) {
F_7 ( V_4 , & V_6 ) ;
V_4 -> V_73 = 0 ;
V_4 -> V_74 = 0 ;
V_4 -> V_57 = - 1 ;
}
V_4 -> V_70 = V_2 -> V_69 << 1 ;
V_4 -> V_71 = 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 * V_39 , T_1 V_67 )
{
T_2 * V_75 = NULL ;
T_1 V_76 = 0 ;
struct V_5 * V_6 ;
T_1 V_68 = V_2 -> V_69 << 1 ;
void * V_77 ;
int V_49 , V_78 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 == NULL )
return - 1 ;
V_75 = F_11 ( & V_6 -> V_7 ) ;
V_76 = V_68 - V_4 -> V_70 ;
V_49 = ( V_4 -> V_57 == 1 ) ? 0 : V_68 ;
V_77 = V_75 + V_49 ;
V_77 += ( V_4 -> V_71 * V_68 * 2 ) ;
V_77 += V_76 ;
V_78 = V_4 -> V_70 > V_67 ?
V_67 : V_4 -> V_70 ;
if ( ( T_2 * ) ( V_77 + V_78 ) > ( T_2 * ) ( V_75 + V_6 -> V_7 . V_36 ) )
return 0 ;
F_21 ( ( V_79 * ) V_39 , ( V_79 * ) V_77 , ( V_79 ) V_78 ) ;
return 0 ;
}
void F_21 ( V_79 * V_80 , V_79 * V_81 , V_79 V_82 )
{
V_79 V_8 ;
if ( V_82 <= 0 )
return;
for ( V_8 = 0 ; V_8 < V_82 / 2 ; V_8 ++ )
V_81 [ V_8 ] = ( V_80 [ V_8 ] << 8 ) | ( V_80 [ V_8 ] >> 8 ) ;
}
T_2 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_83 = 0 ;
V_83 = ( ( V_4 -> V_57 == 2 ) &&
( V_4 -> V_71 >= V_4 -> V_72 ) &&
V_4 -> V_74 ) ;
return V_83 ;
}
static int
F_22 ( struct V_84 * V_85 , unsigned int * V_86 , unsigned int * V_36 )
{
struct V_87 * V_88 = V_85 -> V_89 ;
struct V_1 * V_2 = V_88 -> V_2 ;
* V_36 = ( V_88 -> V_2 -> V_69 * V_88 -> V_2 -> V_90 * V_2 -> V_91 -> V_92 + 7 ) >> 3 ;
if ( 0 == * V_86 )
* V_86 = V_93 ;
if ( * V_86 < V_94 )
* V_86 = V_94 ;
return 0 ;
}
static void F_23 ( struct V_84 * V_85 , struct V_5 * V_6 )
{
struct V_87 * V_88 = V_85 -> V_89 ;
struct V_1 * V_2 = V_88 -> V_2 ;
unsigned long V_95 = 0 ;
if ( F_24 () )
F_25 () ;
F_26 ( & V_2 -> V_14 . V_96 , V_95 ) ;
if ( V_2 -> V_13 ) {
if ( V_2 -> V_14 . V_15 . V_6 == V_6 )
V_2 -> V_14 . V_15 . V_6 = NULL ;
} else {
if ( V_2 -> V_14 . V_16 . V_6 == V_6 )
V_2 -> V_14 . V_16 . V_6 = NULL ;
}
F_27 ( & V_2 -> V_14 . V_96 , V_95 ) ;
F_28 ( & V_6 -> V_7 ) ;
V_6 -> V_7 . V_9 = V_97 ;
}
static int
F_29 ( struct V_84 * V_85 , struct V_98 * V_7 ,
enum V_99 V_100 )
{
struct V_87 * V_88 = V_85 -> V_89 ;
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 = 0 , V_102 = 0 ;
V_6 -> V_7 . V_36 = ( V_88 -> V_2 -> V_69 * V_88 -> V_2 -> V_90 * V_2 -> V_91 -> V_92
+ 7 ) >> 3 ;
if ( 0 != V_6 -> V_7 . V_103 && V_6 -> V_7 . V_104 < V_6 -> V_7 . V_36 )
return - V_105 ;
V_6 -> V_7 . V_69 = V_2 -> V_69 ;
V_6 -> V_7 . V_90 = V_2 -> V_90 ;
V_6 -> V_7 . V_100 = V_100 ;
if ( V_97 == V_6 -> V_7 . V_9 ) {
V_101 = F_30 ( V_85 , & V_6 -> V_7 , NULL ) ;
if ( V_101 < 0 )
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
V_101 = F_31 ( V_2 , V_109 ,
V_110 ,
V_2 -> V_14 . V_47 ,
F_12 ) ;
else
V_101 = F_32 ( V_2 , V_109 ,
V_110 ,
V_2 -> V_14 . V_47 ,
F_16 ) ;
if ( V_101 < 0 )
goto V_106;
}
V_6 -> V_7 . V_9 = V_111 ;
return 0 ;
V_106:
F_23 ( V_85 , V_6 ) ;
return V_101 ;
}
static void F_33 ( struct V_84 * V_85 , struct V_98 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_87 * V_88 = V_85 -> V_89 ;
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_3 * V_32 = & V_2 -> V_14 . V_32 ;
V_6 -> V_7 . V_9 = V_112 ;
F_34 ( & V_6 -> V_7 . V_17 , & V_32 -> V_34 ) ;
}
static void F_35 ( struct V_84 * V_85 ,
struct V_98 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_87 * V_88 = V_85 -> V_89 ;
struct V_1 * V_2 = (struct V_1 * ) V_88 -> V_2 ;
F_2 ( L_15 ) ;
F_23 ( V_85 , V_6 ) ;
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
static int F_43 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 = 0 ;
if ( V_88 -> V_120 )
return V_101 ;
if ( V_88 -> type == V_121 ) {
if ( V_2 -> V_120 )
return - V_122 ;
V_2 -> V_120 = 1 ;
} else if ( V_88 -> type == V_123 ) {
if ( V_2 -> V_124 )
return - V_122 ;
V_2 -> V_124 = 1 ;
} else
return - V_105 ;
V_88 -> V_120 = 1 ;
return V_101 ;
}
static int F_44 ( struct V_87 * V_88 )
{
return V_88 -> V_120 ;
}
static void F_45 ( struct V_87 * V_88 )
{
struct V_1 * V_2 = V_88 -> V_2 ;
V_88 -> V_120 = 0 ;
if ( V_88 -> type == V_121 )
V_2 -> V_120 = 0 ;
if ( V_88 -> type == V_123 )
V_2 -> V_124 = 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_43 ) {
F_47 ( L_17 ) ;
return - V_125 ;
}
return 0 ;
}
static int F_48 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
V_129 -> V_130 . V_131 . V_69 = V_2 -> V_69 ;
V_129 -> V_130 . V_131 . V_90 = V_2 -> V_90 ;
V_129 -> V_130 . V_131 . V_132 = V_2 -> V_91 -> V_133 ;
V_129 -> V_130 . V_131 . V_134 = ( V_2 -> V_69 * V_2 -> V_91 -> V_92 + 7 ) >> 3 ;
V_129 -> V_130 . V_131 . V_135 = V_129 -> V_130 . V_131 . V_134 * V_2 -> V_90 ;
V_129 -> V_130 . V_131 . V_136 = V_137 ;
V_129 -> V_130 . V_131 . V_100 = V_138 ;
return 0 ;
}
static struct V_139 * F_49 ( unsigned int V_133 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_50 ( V_91 ) ; V_8 ++ )
if ( V_91 [ V_8 ] . V_133 == V_133 )
return & V_91 [ V_8 ] ;
return NULL ;
}
static int F_51 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
unsigned int V_69 = V_129 -> V_130 . V_131 . V_69 ;
unsigned int V_90 = V_129 -> V_130 . V_131 . V_90 ;
unsigned int V_140 = F_52 ( V_2 ) ;
unsigned int V_141 = F_53 ( V_2 ) ;
struct V_139 * V_130 ;
V_130 = F_49 ( V_129 -> V_130 . V_131 . V_132 ) ;
if ( ! V_130 ) {
F_54 ( L_18 ,
V_129 -> V_130 . V_131 . V_132 ) ;
return - V_105 ;
}
F_55 ( & V_69 , 48 , V_140 , 1 , & V_90 , 32 , V_141 , 1 , 0 ) ;
V_129 -> V_130 . V_131 . V_69 = V_69 ;
V_129 -> V_130 . V_131 . V_90 = V_90 ;
V_129 -> V_130 . V_131 . V_132 = V_130 -> V_133 ;
V_129 -> V_130 . V_131 . V_134 = ( V_69 * V_130 -> V_92 + 7 ) >> 3 ;
V_129 -> V_130 . V_131 . V_135 = V_129 -> V_130 . V_131 . V_134 * V_90 ;
V_129 -> V_130 . V_131 . V_136 = V_137 ;
V_129 -> V_130 . V_131 . V_100 = V_138 ;
return 0 ;
}
static int F_56 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
struct V_139 * V_130 ;
struct V_142 V_143 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
F_51 ( V_126 , V_127 , V_129 ) ;
V_130 = F_49 ( V_129 -> V_130 . V_131 . V_132 ) ;
if ( ! V_130 )
return - V_105 ;
if ( F_57 ( & V_88 -> V_144 ) ) {
F_47 ( L_19 , V_145 ) ;
return - V_122 ;
}
if ( V_2 -> V_120 && ! V_88 -> V_120 ) {
F_47 ( L_20 , V_145 ) ;
return - V_122 ;
}
V_2 -> V_69 = V_129 -> V_130 . V_131 . V_69 ;
V_2 -> V_90 = V_129 -> V_130 . V_131 . V_90 ;
V_2 -> V_91 = V_130 ;
F_58 ( & V_143 , & V_129 -> V_130 . V_131 , V_146 ) ;
F_59 ( V_2 , V_117 , V_147 , & V_143 ) ;
F_60 ( & V_129 -> V_130 . V_131 , & V_143 ) ;
return V_101 ;
}
static int F_61 ( struct V_126 * V_126 , void * V_127 , T_3 * V_148 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
* V_148 = V_2 -> V_149 ;
return 0 ;
}
static int F_62 ( struct V_126 * V_126 , void * V_127 , T_3 V_149 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_142 V_143 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( V_2 -> V_149 == V_149 )
return 0 ;
if ( F_57 ( & V_88 -> V_144 ) )
return - V_122 ;
V_2 -> V_149 = V_149 ;
V_2 -> V_69 = 720 ;
V_2 -> V_90 = ( V_2 -> V_149 & V_150 ) ? 576 : 480 ;
F_59 ( V_2 , V_117 , V_151 , V_2 -> V_149 ) ;
memset ( & V_143 , 0 , sizeof( V_143 ) ) ;
V_143 . V_152 = V_146 ;
V_143 . V_69 = V_2 -> V_69 ;
V_143 . V_90 = V_2 -> V_90 ;
F_59 ( V_2 , V_117 , V_147 , & V_143 ) ;
F_42 ( V_2 ) ;
return 0 ;
}
int F_63 ( struct V_126 * V_126 , void * V_127 ,
struct V_153 * V_8 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
T_1 V_154 ;
unsigned int V_155 , V_156 ;
V_156 = V_8 -> V_113 ;
if ( V_156 >= V_157 )
return - V_105 ;
if ( 0 == F_37 ( V_156 ) -> type )
return - V_105 ;
V_8 -> V_113 = V_156 ;
V_8 -> type = V_158 ;
strcpy ( V_8 -> V_159 , V_160 [ F_37 ( V_156 ) -> type ] ) ;
if ( ( V_161 == F_37 ( V_156 ) -> type ) ||
( V_162 == F_37 ( V_156 ) -> type ) )
V_8 -> type = V_163 ;
V_8 -> V_164 = V_2 -> V_165 -> V_166 ;
if ( V_156 == V_2 -> V_114 ) {
V_155 = F_64 ( V_2 , V_167 ,
V_168 , 2 , & V_154 , 4 ) ;
if ( V_155 > 0 ) {
if ( ( V_154 & V_169 ) == 0x00 )
V_8 -> V_20 |= V_170 ;
if ( ( V_154 & V_171 ) == 0x00 )
V_8 -> V_20 |= V_172 ;
}
}
return 0 ;
}
int F_65 ( struct V_126 * V_126 , void * V_127 , unsigned int * V_8 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
* V_8 = V_2 -> V_114 ;
return 0 ;
}
int F_66 ( struct V_126 * V_126 , void * V_127 , unsigned int V_8 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_2 -> V_108 = 0 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( V_8 >= V_157 )
return - V_105 ;
if ( 0 == F_37 ( V_8 ) -> type )
return - V_105 ;
F_36 ( V_2 , V_8 ) ;
if ( F_37 ( V_8 ) -> type == V_161 ||
F_37 ( V_8 ) -> type == V_162 ) {
F_59 ( V_2 , V_117 , V_151 , V_2 -> V_149 ) ;
}
return 0 ;
}
int F_67 ( struct V_126 * V_126 , void * V_127 , struct V_173 * V_174 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( 0 != V_174 -> V_113 )
return - V_105 ;
strcpy ( V_174 -> V_159 , L_21 ) ;
V_174 -> type = V_175 ;
V_174 -> V_176 = V_177 ;
V_174 -> V_178 = 0xffffffffUL ;
V_174 -> signal = 0xffff ;
F_59 ( V_2 , V_179 , V_180 , V_174 ) ;
return 0 ;
}
int F_68 ( struct V_126 * V_126 , void * V_127 , const struct V_173 * V_174 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( 0 != V_174 -> V_113 )
return - V_105 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
int F_69 ( struct V_126 * V_126 , void * V_127 ,
struct V_181 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
if ( V_129 -> V_179 )
return - V_105 ;
V_129 -> V_182 = V_2 -> V_183 ;
return 0 ;
}
int F_70 ( struct V_126 * V_126 , void * V_127 ,
const struct V_181 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
struct V_181 V_184 = * V_129 ;
int V_101 ;
T_1 V_185 = 5400000 ;
F_41 ( L_22 ,
V_129 -> V_182 , V_129 -> type ) ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( 0 != V_129 -> V_179 )
return - V_105 ;
V_101 = F_71 ( V_2 ) ;
F_59 ( V_2 , V_179 , V_186 , V_129 ) ;
F_59 ( V_2 , V_179 , V_187 , & V_184 ) ;
V_2 -> V_183 = V_184 . V_182 ;
V_101 = F_72 ( V_2 ) ;
if ( V_2 -> V_188 == V_189 ) {
if ( V_2 -> V_149 & ( V_190 | V_191 ) )
V_185 = 5400000 ;
else if ( V_2 -> V_149 & V_192 )
V_185 = 6000000 ;
else if ( V_2 -> V_149 & ( V_193 | V_194 ) )
V_185 = 6900000 ;
else if ( V_2 -> V_149 & V_195 )
V_185 = 7100000 ;
else if ( V_2 -> V_149 & V_196 )
V_185 = 7250000 ;
else if ( V_2 -> V_149 & V_197 )
V_185 = 6900000 ;
else if ( V_2 -> V_149 & V_198 )
V_185 = 1250000 ;
F_41 ( L_23 , V_185 ) ;
F_73 ( V_2 , V_185 , 1 , 1 ) ;
F_74 ( V_2 ) ;
}
F_41 ( L_24 , V_129 -> V_182 ) ;
return V_101 ;
}
int F_75 ( struct V_126 * V_126 , void * V_88 ,
struct V_199 * V_200 )
{
switch ( V_200 -> V_201 . V_202 ) {
case 0 :
return 0 ;
case 1 :
F_76 ( V_200 -> V_159 , L_25 , sizeof( V_200 -> V_159 ) ) ;
return 0 ;
case 2 :
F_76 ( V_200 -> V_159 , L_26 , sizeof( V_200 -> V_159 ) ) ;
return 0 ;
case 3 :
F_76 ( V_200 -> V_159 , L_27 , sizeof( V_200 -> V_159 ) ) ;
return 0 ;
case 4 :
F_76 ( V_200 -> V_159 , L_28 , sizeof( V_200 -> V_159 ) ) ;
return 0 ;
case 5 :
F_76 ( V_200 -> V_159 , L_29 , sizeof( V_200 -> V_159 ) ) ;
return 0 ;
case 6 :
F_76 ( V_200 -> V_159 , L_30 , sizeof( V_200 -> V_159 ) ) ;
return 0 ;
}
return - V_105 ;
}
int F_77 ( struct V_126 * V_126 , void * V_127 ,
struct V_203 * V_204 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_155 ;
T_2 V_205 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_206 = 0 ;
switch ( V_204 -> V_201 . V_202 ) {
case 0 :
V_155 = F_78 ( V_2 , V_207 ,
( V_79 ) V_204 -> V_204 , V_205 , 4 ) ;
V_204 -> V_208 = V_205 [ 0 ] | V_205 [ 1 ] << 8 |
V_205 [ 2 ] << 16 | V_205 [ 3 ] << 24 ;
V_204 -> V_36 = 4 ;
break;
case 1 :
V_155 = F_64 ( V_2 , V_209 ,
( V_79 ) V_204 -> V_204 , 2 , & V_206 , 1 ) ;
V_204 -> V_208 = V_206 ;
V_204 -> V_36 = 1 ;
break;
case 2 :
V_155 = F_64 ( V_2 , V_167 ,
( V_79 ) V_204 -> V_204 , 2 , & V_206 , 1 ) ;
V_204 -> V_208 = V_206 ;
V_204 -> V_36 = 1 ;
break;
case 3 :
V_155 = F_64 ( V_2 , V_210 ,
( V_79 ) V_204 -> V_204 , 1 , & V_206 , 1 ) ;
V_204 -> V_208 = V_206 ;
V_204 -> V_36 = 1 ;
break;
case 4 :
V_155 = F_64 ( V_2 , V_209 ,
( V_79 ) V_204 -> V_204 , 2 , & V_206 , 4 ) ;
V_204 -> V_208 = V_206 ;
V_204 -> V_36 = 4 ;
break;
case 5 :
V_155 = F_64 ( V_2 , V_167 ,
( V_79 ) V_204 -> V_204 , 2 , & V_206 , 4 ) ;
V_204 -> V_208 = V_206 ;
V_204 -> V_36 = 4 ;
break;
case 6 :
V_155 = F_64 ( V_2 , V_210 ,
( V_79 ) V_204 -> V_204 , 1 , & V_206 , 4 ) ;
V_204 -> V_208 = V_206 ;
V_204 -> V_36 = 4 ;
break;
default:
return - V_105 ;
}
return V_155 < 0 ? V_155 : 0 ;
}
int F_79 ( struct V_126 * V_126 , void * V_127 ,
const struct V_203 * V_204 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_155 ;
T_2 V_206 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_204 -> V_201 . V_202 ) {
case 0 :
V_206 [ 0 ] = ( T_2 ) V_204 -> V_208 ;
V_206 [ 1 ] = ( T_2 ) ( V_204 -> V_208 >> 8 ) ;
V_206 [ 2 ] = ( T_2 ) ( V_204 -> V_208 >> 16 ) ;
V_206 [ 3 ] = ( T_2 ) ( V_204 -> V_208 >> 24 ) ;
V_155 = F_80 ( V_2 , V_211 ,
( V_79 ) V_204 -> V_204 , V_206 , 4 ) ;
break;
case 1 :
V_155 = F_81 ( V_2 , V_209 ,
( V_79 ) V_204 -> V_204 , 2 , V_204 -> V_208 , 1 ) ;
break;
case 2 :
V_155 = F_81 ( V_2 , V_167 ,
( V_79 ) V_204 -> V_204 , 2 , V_204 -> V_208 , 1 ) ;
break;
case 3 :
V_155 = F_81 ( V_2 , V_210 ,
( V_79 ) V_204 -> V_204 , 1 , V_204 -> V_208 , 1 ) ;
break;
case 4 :
V_155 = F_81 ( V_2 , V_209 ,
( V_79 ) V_204 -> V_204 , 2 , V_204 -> V_208 , 4 ) ;
break;
case 5 :
V_155 = F_81 ( V_2 , V_167 ,
( V_79 ) V_204 -> V_204 , 2 , V_204 -> V_208 , 4 ) ;
break;
case 6 :
V_155 = F_81 ( V_2 , V_210 ,
( V_79 ) V_204 -> V_204 , 1 , V_204 -> V_208 , 4 ) ;
break;
default:
return - V_105 ;
}
return V_155 < 0 ? V_155 : 0 ;
}
static int F_82 ( struct V_126 * V_126 , void * V_127 ,
struct V_212 * V_213 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
if ( V_213 -> type != V_121 )
return - V_105 ;
V_213 -> V_214 . V_215 = 0 ;
V_213 -> V_214 . V_216 = 0 ;
V_213 -> V_214 . V_69 = V_2 -> V_69 ;
V_213 -> V_214 . V_90 = V_2 -> V_90 ;
V_213 -> V_217 = V_213 -> V_214 ;
V_213 -> V_218 . V_219 = 54 ;
V_213 -> V_218 . V_220 = 59 ;
return 0 ;
}
static int F_83 ( struct V_126 * V_126 , void * V_127 ,
enum V_221 type )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_43 ( V_88 ) ;
if ( F_84 ( V_101 >= 0 ) )
V_101 = F_85 ( & V_88 -> V_144 ) ;
F_59 ( V_2 , V_117 , V_222 , 1 ) ;
return V_101 ;
}
static int F_86 ( struct V_126 * V_126 , void * V_127 ,
enum V_221 type )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( type != V_88 -> type )
return - V_105 ;
F_39 ( V_2 , V_117 , V_222 , 0 ) ;
F_87 ( & V_88 -> V_144 ) ;
F_45 ( V_88 ) ;
return 0 ;
}
int F_88 ( struct V_126 * V_126 , void * V_127 ,
struct V_223 * V_224 )
{
struct V_225 * V_165 = F_89 ( V_126 ) ;
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
F_76 ( V_224 -> V_226 , L_31 , sizeof( V_224 -> V_226 ) ) ;
F_76 ( V_224 -> V_227 , V_228 [ V_2 -> V_229 ] . V_159 , sizeof( V_224 -> V_227 ) ) ;
F_90 ( V_2 -> V_230 , V_224 -> V_231 , sizeof( V_224 -> V_231 ) ) ;
if ( V_165 -> V_232 == V_233 )
V_224 -> V_234 = V_235 ;
else {
V_224 -> V_234 = V_236 | V_237 ;
if ( V_165 -> V_232 == V_238 )
V_224 -> V_234 |= V_239 ;
else
V_224 -> V_234 |= V_240 ;
}
if ( V_2 -> V_188 != V_241 )
V_224 -> V_234 |= V_242 ;
V_224 -> V_243 = V_224 -> V_234 | V_236 |
V_239 | V_240 |
V_237 | V_244 ;
if ( V_2 -> V_245 )
V_224 -> V_243 |= V_235 ;
return 0 ;
}
static int F_91 ( struct V_126 * V_126 , void * V_127 ,
struct V_246 * V_129 )
{
if ( F_92 ( V_129 -> V_113 >= F_50 ( V_91 ) ) )
return - V_105 ;
F_76 ( V_129 -> V_247 , V_91 [ V_129 -> V_113 ] . V_159 , sizeof( V_129 -> V_247 ) ) ;
V_129 -> V_132 = V_91 [ V_129 -> V_113 ] . V_133 ;
return 0 ;
}
static int F_93 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
V_129 -> V_130 . V_248 . V_249 = 6750000 * 4 ;
V_129 -> V_130 . V_248 . V_250 = V_251 ;
V_129 -> V_130 . V_248 . V_252 = V_253 ;
V_129 -> V_130 . V_248 . V_49 = 0 ;
V_129 -> V_130 . V_248 . V_254 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_255 : V_256 ;
V_129 -> V_130 . V_248 . V_86 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_257 : V_258 ;
V_129 -> V_130 . V_248 . V_254 [ 1 ] = ( V_2 -> V_149 & V_150 ) ?
V_255 + 312 : V_256 + 263 ;
V_129 -> V_130 . V_248 . V_86 [ 1 ] = V_129 -> V_130 . V_248 . V_86 [ 0 ] ;
memset ( V_129 -> V_130 . V_248 . V_259 , 0 , sizeof( V_129 -> V_130 . V_248 . V_259 ) ) ;
return 0 ;
}
static int F_94 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
V_129 -> V_130 . V_248 . V_249 = 6750000 * 4 ;
V_129 -> V_130 . V_248 . V_250 = V_251 ;
V_129 -> V_130 . V_248 . V_252 = V_253 ;
V_129 -> V_130 . V_248 . V_49 = 0 ;
V_129 -> V_130 . V_248 . V_95 = 0 ;
V_129 -> V_130 . V_248 . V_254 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_255 : V_256 ;
V_129 -> V_130 . V_248 . V_86 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_257 : V_258 ;
V_129 -> V_130 . V_248 . V_254 [ 1 ] = ( V_2 -> V_149 & V_150 ) ?
V_255 + 312 : V_256 + 263 ;
V_129 -> V_130 . V_248 . V_86 [ 1 ] = V_129 -> V_130 . V_248 . V_86 [ 0 ] ;
memset ( V_129 -> V_130 . V_248 . V_259 , 0 , sizeof( V_129 -> V_130 . V_248 . V_259 ) ) ;
return 0 ;
}
static int F_95 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
if ( V_2 -> V_124 && ! V_88 -> V_120 ) {
F_47 ( L_20 , V_145 ) ;
return - V_122 ;
}
return F_94 ( V_126 , V_127 , V_129 ) ;
}
static int F_96 ( struct V_126 * V_126 , void * V_127 ,
struct V_260 * V_261 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
return F_97 ( & V_88 -> V_144 , V_261 ) ;
}
static int F_98 ( struct V_126 * V_126 , void * V_127 , struct V_262 * V_263 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
return F_99 ( & V_88 -> V_144 , V_263 ) ;
}
static int F_100 ( struct V_126 * V_126 , void * V_127 , struct V_262 * V_263 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
return F_101 ( & V_88 -> V_144 , V_263 ) ;
}
static int F_102 ( struct V_126 * V_126 , void * V_127 , struct V_262 * V_263 )
{
struct V_87 * V_88 = V_127 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
return F_103 ( & V_88 -> V_144 , V_263 , V_126 -> V_264 & V_265 ) ;
}
static int F_104 ( struct V_126 * V_126 , void * V_127 , struct V_173 * V_174 )
{
struct V_1 * V_2 = ( (struct V_87 * ) V_127 ) -> V_2 ;
if ( V_174 -> V_113 )
return - V_105 ;
strcpy ( V_174 -> V_159 , L_32 ) ;
F_59 ( V_2 , V_179 , V_180 , V_174 ) ;
return 0 ;
}
static int F_105 ( struct V_126 * V_126 , void * V_127 , const struct V_173 * V_174 )
{
struct V_1 * V_2 = ( (struct V_87 * ) V_127 ) -> V_2 ;
if ( V_174 -> V_113 )
return - V_105 ;
F_59 ( V_2 , V_179 , V_266 , V_174 ) ;
return 0 ;
}
static int F_106 ( struct V_126 * V_267 )
{
int V_268 = 0 ;
struct V_225 * V_165 = F_89 ( V_267 ) ;
struct V_1 * V_2 = F_107 ( V_267 ) ;
struct V_87 * V_88 ;
enum V_221 V_269 = 0 ;
switch ( V_165 -> V_232 ) {
case V_270 :
V_269 = V_121 ;
break;
case V_238 :
V_269 = V_123 ;
break;
case V_233 :
V_268 = 1 ;
break;
}
F_54 ( L_33 ,
F_108 ( V_165 ) , V_271 [ V_269 ] ,
V_2 -> V_272 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
cx231xx_errdev
("Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_88 = F_109 ( sizeof( struct V_87 ) , V_273 ) ;
if ( ! V_88 ) {
F_47 ( L_34 ) ;
return - V_274 ;
}
if ( F_110 ( & V_2 -> V_275 ) ) {
F_111 ( V_88 ) ;
return - V_276 ;
}
V_88 -> V_2 = V_2 ;
V_88 -> type = V_269 ;
V_267 -> V_277 = V_88 ;
F_112 ( & V_88 -> V_88 , V_165 ) ;
if ( V_88 -> type == V_121 && V_2 -> V_272 == 0 ) {
if ( V_2 -> V_278 . V_279 )
F_113 ( V_2 ,
V_280 ) ;
else
F_113 ( V_2 , V_281 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
V_2 -> V_114 = V_2 -> V_114 > 2 ? 2 : V_2 -> V_114 ;
}
if ( V_268 ) {
F_54 ( L_35 ) ;
F_59 ( V_2 , V_179 , V_282 ) ;
}
V_2 -> V_272 ++ ;
if ( V_88 -> type == V_121 )
F_116 ( & V_88 -> V_144 , & V_283 ,
NULL , & V_2 -> V_14 . V_96 ,
V_88 -> type , V_138 ,
sizeof( struct V_5 ) ,
V_88 , & V_2 -> V_275 ) ;
if ( V_88 -> type == V_123 ) {
F_117 ( V_2 , V_284 , 0 ) ;
F_116 ( & V_88 -> V_144 , & V_285 ,
NULL , & V_2 -> V_286 . V_96 ,
V_88 -> type , V_287 ,
sizeof( struct V_5 ) ,
V_88 , & V_2 -> V_275 ) ;
}
F_118 ( & V_2 -> V_275 ) ;
F_119 ( & V_88 -> V_88 ) ;
return 0 ;
}
void F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_245 ) {
if ( F_121 ( V_2 -> V_245 ) )
F_122 ( V_2 -> V_245 ) ;
else
F_123 ( V_2 -> V_245 ) ;
V_2 -> V_245 = NULL ;
}
if ( V_2 -> V_288 ) {
F_41 ( L_36 ,
F_108 ( V_2 -> V_288 ) ) ;
if ( F_121 ( V_2 -> V_288 ) )
F_122 ( V_2 -> V_288 ) ;
else
F_123 ( V_2 -> V_288 ) ;
V_2 -> V_288 = NULL ;
}
if ( V_2 -> V_165 ) {
F_41 ( L_36 ,
F_108 ( V_2 -> V_165 ) ) ;
if ( V_2 -> V_278 . V_289 )
F_124 ( V_2 ) ;
if ( F_121 ( V_2 -> V_165 ) )
F_122 ( V_2 -> V_165 ) ;
else
F_123 ( V_2 -> V_165 ) ;
V_2 -> V_165 = NULL ;
}
F_125 ( & V_2 -> V_290 ) ;
F_125 ( & V_2 -> V_291 ) ;
}
static int F_126 ( struct V_126 * V_267 )
{
struct V_87 * V_88 = V_267 -> V_277 ;
struct V_1 * V_2 = V_88 -> V_2 ;
F_54 ( L_37 , V_2 -> V_272 ) ;
F_54 ( L_37 , V_2 -> V_272 ) ;
if ( F_44 ( V_88 ) )
F_45 ( V_88 ) ;
if ( ! V_2 -> V_278 . V_292 )
if ( V_88 -> type == V_123 ) {
F_127 ( & V_88 -> V_144 ) ;
F_128 ( & V_88 -> V_144 ) ;
if ( V_2 -> V_9 & V_43 ) {
if ( F_129 ( & V_2 -> V_293 ) > 0 ) {
F_130 ( V_2 ) ;
V_88 -> V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_131 ( V_2 ) ;
if ( ! V_2 -> V_294 )
F_117 ( V_2 , V_284 , 0 ) ;
else
F_117 ( V_2 , V_295 , 0 ) ;
F_132 ( & V_88 -> V_88 ) ;
F_133 ( & V_88 -> V_88 ) ;
F_111 ( V_88 ) ;
V_2 -> V_272 -- ;
F_134 ( & V_2 -> V_296 , 1 ) ;
return 0 ;
}
F_132 ( & V_88 -> V_88 ) ;
V_2 -> V_272 -- ;
if ( ! V_2 -> V_272 ) {
F_127 ( & V_88 -> V_144 ) ;
F_128 ( & V_88 -> V_144 ) ;
if ( V_2 -> V_9 & V_43 ) {
F_130 ( V_2 ) ;
V_88 -> V_2 = NULL ;
return 0 ;
}
F_59 ( V_2 , V_297 , V_298 , 0 ) ;
if ( V_2 -> V_13 )
F_135 ( V_2 ) ;
else
F_136 ( V_2 ) ;
F_137 ( V_2 , V_299 ) ;
F_117 ( V_2 , V_300 , 0 ) ;
}
F_133 ( & V_88 -> V_88 ) ;
F_111 ( V_88 ) ;
F_134 ( & V_2 -> V_296 , 1 ) ;
return 0 ;
}
static int F_138 ( struct V_126 * V_267 )
{
struct V_87 * V_88 = V_267 -> V_277 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
F_139 ( & V_2 -> V_275 ) ;
V_101 = F_126 ( V_267 ) ;
F_118 ( & V_2 -> V_275 ) ;
return V_101 ;
}
static T_4
F_140 ( struct V_126 * V_267 , char T_5 * V_6 , T_6 V_86 ,
T_7 * V_73 )
{
struct V_87 * V_88 = V_267 -> V_277 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
if ( ( V_88 -> type == V_121 ) ||
( V_88 -> type == V_123 ) ) {
V_101 = F_43 ( V_88 ) ;
if ( F_92 ( V_101 < 0 ) )
return V_101 ;
if ( F_110 ( & V_2 -> V_275 ) )
return - V_276 ;
V_101 = F_141 ( & V_88 -> V_144 , V_6 , V_86 , V_73 , 0 ,
V_267 -> V_264 & V_265 ) ;
F_118 ( & V_2 -> V_275 ) ;
return V_101 ;
}
return 0 ;
}
static unsigned int F_142 ( struct V_126 * V_267 , T_8 * V_301 )
{
unsigned long V_302 = F_143 ( V_301 ) ;
struct V_87 * V_88 = V_267 -> V_277 ;
struct V_1 * V_2 = V_88 -> V_2 ;
unsigned V_303 = 0 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_304 ;
V_101 = F_43 ( V_88 ) ;
if ( F_92 ( V_101 < 0 ) )
return V_304 ;
if ( F_144 ( & V_88 -> V_88 ) )
V_303 |= V_305 ;
else
F_145 ( V_267 , & V_88 -> V_88 . V_301 , V_301 ) ;
if ( ! ( V_302 & ( V_306 | V_307 ) ) )
return V_303 ;
if ( ( V_121 == V_88 -> type ) ||
( V_123 == V_88 -> type ) ) {
F_139 ( & V_2 -> V_275 ) ;
V_303 |= F_146 ( V_267 , & V_88 -> V_144 , V_301 ) ;
F_118 ( & V_2 -> V_275 ) ;
return V_303 ;
}
return V_303 | V_304 ;
}
static int F_147 ( struct V_126 * V_267 , struct V_308 * V_309 )
{
struct V_87 * V_88 = V_267 -> V_277 ;
struct V_1 * V_2 = V_88 -> V_2 ;
int V_101 ;
V_101 = F_46 ( V_2 ) ;
if ( V_101 < 0 )
return V_101 ;
V_101 = F_43 ( V_88 ) ;
if ( F_92 ( V_101 < 0 ) )
return V_101 ;
if ( F_110 ( & V_2 -> V_275 ) )
return - V_276 ;
V_101 = F_148 ( & V_88 -> V_144 , V_309 ) ;
F_118 ( & V_2 -> V_275 ) ;
F_54 ( L_38 ,
( unsigned long ) V_309 -> V_310 ,
( unsigned long ) V_309 -> V_311 -
( unsigned long ) V_309 -> V_310 , V_101 ) ;
return V_101 ;
}
static struct V_225 * F_149 ( struct V_1 * V_2 ,
const struct V_225
* V_312 , const char * V_313 )
{
struct V_225 * V_314 ;
V_314 = F_150 () ;
if ( NULL == V_314 )
return NULL ;
* V_314 = * V_312 ;
V_314 -> V_315 = & V_2 -> V_315 ;
V_314 -> V_316 = F_123 ;
V_314 -> V_317 = V_318 ;
V_314 -> V_275 = & V_2 -> V_275 ;
snprintf ( V_314 -> V_159 , sizeof( V_314 -> V_159 ) , L_39 , V_2 -> V_159 , V_313 ) ;
F_151 ( V_314 , V_2 ) ;
if ( V_2 -> V_188 == V_241 ) {
F_152 ( V_314 , V_319 ) ;
F_152 ( V_314 , V_320 ) ;
F_152 ( V_314 , V_321 ) ;
F_152 ( V_314 , V_322 ) ;
}
return V_314 ;
}
int F_153 ( struct V_1 * V_2 )
{
int V_155 ;
F_41 ( L_40 ,
V_2 -> V_159 , V_323 ) ;
V_2 -> V_149 = V_324 ;
V_2 -> V_69 = F_52 ( V_2 ) ;
V_2 -> V_90 = F_53 ( V_2 ) ;
V_2 -> V_325 = 0 ;
V_2 -> V_91 = & V_91 [ 0 ] ;
F_36 ( V_2 , V_2 -> V_114 ) ;
F_59 ( V_2 , V_117 , V_151 , V_2 -> V_149 ) ;
F_154 ( & V_2 -> V_290 , 10 ) ;
F_154 ( & V_2 -> V_291 , 5 ) ;
if ( V_2 -> V_326 ) {
F_155 ( & V_2 -> V_290 ,
V_2 -> V_326 -> V_290 , NULL ) ;
F_155 ( & V_2 -> V_291 ,
V_2 -> V_326 -> V_290 ,
V_327 ) ;
}
if ( V_2 -> V_290 . error )
return V_2 -> V_290 . error ;
if ( V_2 -> V_291 . error )
return V_2 -> V_291 . error ;
V_2 -> V_165 = F_149 ( V_2 , & V_328 , L_41 ) ;
if ( ! V_2 -> V_165 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_2 -> V_165 -> V_290 = & V_2 -> V_290 ;
V_155 = F_156 ( V_2 -> V_165 , V_270 ,
V_329 [ V_2 -> V_330 ] ) ;
if ( V_155 ) {
F_47 ( L_43 ,
V_155 ) ;
return V_155 ;
}
F_41 ( L_44 ,
V_2 -> V_159 , F_108 ( V_2 -> V_165 ) ) ;
V_331 = V_328 ;
strcpy ( V_331 . V_159 , L_45 ) ;
V_2 -> V_288 = F_149 ( V_2 , & V_331 , L_46 ) ;
if ( ! V_2 -> V_288 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_2 -> V_288 -> V_290 = & V_2 -> V_290 ;
V_155 = F_156 ( V_2 -> V_288 , V_238 ,
V_332 [ V_2 -> V_330 ] ) ;
if ( V_155 < 0 ) {
F_47 ( L_47 ) ;
return V_155 ;
}
F_41 ( L_48 ,
V_2 -> V_159 , F_108 ( V_2 -> V_288 ) ) ;
if ( V_228 [ V_2 -> V_229 ] . V_268 . type == V_333 ) {
V_2 -> V_245 = F_149 ( V_2 , & V_334 ,
L_49 ) ;
if ( ! V_2 -> V_245 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_2 -> V_245 -> V_290 = & V_2 -> V_291 ;
V_155 = F_156 ( V_2 -> V_245 , V_233 ,
V_335 [ V_2 -> V_330 ] ) ;
if ( V_155 < 0 ) {
F_47 ( L_50 ) ;
return V_155 ;
}
F_41 ( L_51 ,
F_108 ( V_2 -> V_245 ) ) ;
}
F_41 ( L_52 ,
F_108 ( V_2 -> V_165 ) ,
F_108 ( V_2 -> V_288 ) ) ;
return 0 ;
}
