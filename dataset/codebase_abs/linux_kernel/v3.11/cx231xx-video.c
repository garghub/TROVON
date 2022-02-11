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
switch ( V_201 -> V_202 . V_203 ) {
case 0 :
return 0 ;
case 1 :
F_76 ( V_201 -> V_160 , L_25 , sizeof( V_201 -> V_160 ) ) ;
return 0 ;
case 2 :
F_76 ( V_201 -> V_160 , L_26 , sizeof( V_201 -> V_160 ) ) ;
return 0 ;
case 3 :
F_76 ( V_201 -> V_160 , L_27 , sizeof( V_201 -> V_160 ) ) ;
return 0 ;
case 4 :
F_76 ( V_201 -> V_160 , L_28 , sizeof( V_201 -> V_160 ) ) ;
return 0 ;
case 5 :
F_76 ( V_201 -> V_160 , L_29 , sizeof( V_201 -> V_160 ) ) ;
return 0 ;
case 6 :
F_76 ( V_201 -> V_160 , L_30 , sizeof( V_201 -> V_160 ) ) ;
return 0 ;
}
return - V_105 ;
}
int F_77 ( struct V_126 * V_126 , void * V_127 ,
struct V_204 * V_205 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_156 ;
T_2 V_206 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_207 = 0 ;
switch ( V_205 -> V_202 . V_203 ) {
case 0 :
V_156 = F_78 ( V_2 , V_208 ,
( V_80 ) V_205 -> V_205 , V_206 , 4 ) ;
V_205 -> V_209 = V_206 [ 0 ] | V_206 [ 1 ] << 8 |
V_206 [ 2 ] << 16 | V_206 [ 3 ] << 24 ;
V_205 -> V_36 = 4 ;
break;
case 1 :
V_156 = F_64 ( V_2 , V_210 ,
( V_80 ) V_205 -> V_205 , 2 , & V_207 , 1 ) ;
V_205 -> V_209 = V_207 ;
V_205 -> V_36 = 1 ;
break;
case 2 :
V_156 = F_64 ( V_2 , V_168 ,
( V_80 ) V_205 -> V_205 , 2 , & V_207 , 1 ) ;
V_205 -> V_209 = V_207 ;
V_205 -> V_36 = 1 ;
break;
case 3 :
V_156 = F_64 ( V_2 , V_211 ,
( V_80 ) V_205 -> V_205 , 1 , & V_207 , 1 ) ;
V_205 -> V_209 = V_207 ;
V_205 -> V_36 = 1 ;
break;
case 4 :
V_156 = F_64 ( V_2 , V_210 ,
( V_80 ) V_205 -> V_205 , 2 , & V_207 , 4 ) ;
V_205 -> V_209 = V_207 ;
V_205 -> V_36 = 4 ;
break;
case 5 :
V_156 = F_64 ( V_2 , V_168 ,
( V_80 ) V_205 -> V_205 , 2 , & V_207 , 4 ) ;
V_205 -> V_209 = V_207 ;
V_205 -> V_36 = 4 ;
break;
case 6 :
V_156 = F_64 ( V_2 , V_211 ,
( V_80 ) V_205 -> V_205 , 1 , & V_207 , 4 ) ;
V_205 -> V_209 = V_207 ;
V_205 -> V_36 = 4 ;
break;
default:
return - V_105 ;
}
return V_156 < 0 ? V_156 : 0 ;
}
int F_79 ( struct V_126 * V_126 , void * V_127 ,
const struct V_204 * V_205 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_156 ;
T_2 V_207 [ 4 ] = { 0 , 0 , 0 , 0 } ;
switch ( V_205 -> V_202 . V_203 ) {
case 0 :
V_207 [ 0 ] = ( T_2 ) V_205 -> V_209 ;
V_207 [ 1 ] = ( T_2 ) ( V_205 -> V_209 >> 8 ) ;
V_207 [ 2 ] = ( T_2 ) ( V_205 -> V_209 >> 16 ) ;
V_207 [ 3 ] = ( T_2 ) ( V_205 -> V_209 >> 24 ) ;
V_156 = F_80 ( V_2 , V_212 ,
( V_80 ) V_205 -> V_205 , V_207 , 4 ) ;
break;
case 1 :
V_156 = F_81 ( V_2 , V_210 ,
( V_80 ) V_205 -> V_205 , 2 , V_205 -> V_209 , 1 ) ;
break;
case 2 :
V_156 = F_81 ( V_2 , V_168 ,
( V_80 ) V_205 -> V_205 , 2 , V_205 -> V_209 , 1 ) ;
break;
case 3 :
V_156 = F_81 ( V_2 , V_211 ,
( V_80 ) V_205 -> V_205 , 1 , V_205 -> V_209 , 1 ) ;
break;
case 4 :
V_156 = F_81 ( V_2 , V_210 ,
( V_80 ) V_205 -> V_205 , 2 , V_205 -> V_209 , 4 ) ;
break;
case 5 :
V_156 = F_81 ( V_2 , V_168 ,
( V_80 ) V_205 -> V_205 , 2 , V_205 -> V_209 , 4 ) ;
break;
case 6 :
V_156 = F_81 ( V_2 , V_211 ,
( V_80 ) V_205 -> V_205 , 1 , V_205 -> V_209 , 4 ) ;
break;
default:
return - V_105 ;
}
return V_156 < 0 ? V_156 : 0 ;
}
static int F_82 ( struct V_126 * V_126 , void * V_127 ,
struct V_213 * V_214 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_214 -> type != V_121 )
return - V_105 ;
V_214 -> V_215 . V_216 = 0 ;
V_214 -> V_215 . V_217 = 0 ;
V_214 -> V_215 . V_70 = V_2 -> V_70 ;
V_214 -> V_215 . V_91 = V_2 -> V_91 ;
V_214 -> V_218 = V_214 -> V_215 ;
V_214 -> V_219 . V_220 = 54 ;
V_214 -> V_219 . V_221 = 59 ;
return 0 ;
}
static int F_83 ( struct V_126 * V_126 , void * V_127 ,
enum V_222 type )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_84 ( V_39 >= 0 ) )
V_39 = F_85 ( & V_89 -> V_144 ) ;
F_59 ( V_2 , V_117 , V_223 , 1 ) ;
return V_39 ;
}
static int F_86 ( struct V_126 * V_126 , void * V_127 ,
enum V_222 type )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( type != V_89 -> type )
return - V_105 ;
F_39 ( V_2 , V_117 , V_223 , 0 ) ;
F_87 ( & V_89 -> V_144 ) ;
F_45 ( V_89 ) ;
return 0 ;
}
int F_88 ( struct V_126 * V_126 , void * V_127 ,
struct V_224 * V_225 )
{
struct V_226 * V_166 = F_89 ( V_126 ) ;
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_76 ( V_225 -> V_227 , L_31 , sizeof( V_225 -> V_227 ) ) ;
F_76 ( V_225 -> V_228 , V_229 [ V_2 -> V_230 ] . V_160 , sizeof( V_225 -> V_228 ) ) ;
F_90 ( V_2 -> V_231 , V_225 -> V_232 , sizeof( V_225 -> V_232 ) ) ;
if ( V_166 -> V_233 == V_234 )
V_225 -> V_235 = V_236 ;
else {
V_225 -> V_235 = V_237 | V_238 ;
if ( V_166 -> V_233 == V_239 )
V_225 -> V_235 |= V_240 ;
else
V_225 -> V_235 |= V_241 ;
}
if ( V_2 -> V_189 != V_242 )
V_225 -> V_235 |= V_243 ;
V_225 -> V_244 = V_225 -> V_235 | V_237 |
V_240 | V_241 |
V_238 | V_245 ;
if ( V_2 -> V_246 )
V_225 -> V_244 |= V_236 ;
return 0 ;
}
static int F_91 ( struct V_126 * V_126 , void * V_127 ,
struct V_247 * V_129 )
{
if ( F_92 ( V_129 -> V_113 >= F_50 ( V_92 ) ) )
return - V_105 ;
F_76 ( V_129 -> V_248 , V_92 [ V_129 -> V_113 ] . V_160 , sizeof( V_129 -> V_248 ) ) ;
V_129 -> V_132 = V_92 [ V_129 -> V_113 ] . V_133 ;
return 0 ;
}
static int F_93 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> V_130 . V_249 . V_250 = 6750000 * 4 ;
V_129 -> V_130 . V_249 . V_251 = V_252 ;
V_129 -> V_130 . V_249 . V_253 = V_254 ;
V_129 -> V_130 . V_249 . V_50 = 0 ;
V_129 -> V_130 . V_249 . V_255 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_256 : V_257 ;
V_129 -> V_130 . V_249 . V_87 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_258 : V_259 ;
V_129 -> V_130 . V_249 . V_255 [ 1 ] = ( V_2 -> V_149 & V_150 ) ?
V_256 + 312 : V_257 + 263 ;
V_129 -> V_130 . V_249 . V_87 [ 1 ] = V_129 -> V_130 . V_249 . V_87 [ 0 ] ;
memset ( V_129 -> V_130 . V_249 . V_260 , 0 , sizeof( V_129 -> V_130 . V_249 . V_260 ) ) ;
return 0 ;
}
static int F_94 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> V_130 . V_249 . V_250 = 6750000 * 4 ;
V_129 -> V_130 . V_249 . V_251 = V_252 ;
V_129 -> V_130 . V_249 . V_253 = V_254 ;
V_129 -> V_130 . V_249 . V_50 = 0 ;
V_129 -> V_130 . V_249 . V_96 = 0 ;
V_129 -> V_130 . V_249 . V_255 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_256 : V_257 ;
V_129 -> V_130 . V_249 . V_87 [ 0 ] = ( V_2 -> V_149 & V_150 ) ?
V_258 : V_259 ;
V_129 -> V_130 . V_249 . V_255 [ 1 ] = ( V_2 -> V_149 & V_150 ) ?
V_256 + 312 : V_257 + 263 ;
V_129 -> V_130 . V_249 . V_87 [ 1 ] = V_129 -> V_130 . V_249 . V_87 [ 0 ] ;
memset ( V_129 -> V_130 . V_249 . V_260 , 0 , sizeof( V_129 -> V_130 . V_249 . V_260 ) ) ;
return 0 ;
}
static int F_95 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_2 -> V_124 && ! V_89 -> V_120 ) {
F_47 ( L_20 , V_145 ) ;
return - V_122 ;
}
return F_94 ( V_126 , V_127 , V_129 ) ;
}
static int F_96 ( struct V_126 * V_126 , void * V_127 ,
struct V_261 * V_262 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_97 ( & V_89 -> V_144 , V_262 ) ;
}
static int F_98 ( struct V_126 * V_126 , void * V_127 , struct V_263 * V_264 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_99 ( & V_89 -> V_144 , V_264 ) ;
}
static int F_100 ( struct V_126 * V_126 , void * V_127 , struct V_263 * V_264 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_101 ( & V_89 -> V_144 , V_264 ) ;
}
static int F_102 ( struct V_126 * V_126 , void * V_127 , struct V_263 * V_264 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_103 ( & V_89 -> V_144 , V_264 , V_126 -> V_265 & V_266 ) ;
}
static int F_104 ( struct V_126 * V_126 , void * V_127 , struct V_174 * V_175 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
if ( V_175 -> V_113 )
return - V_105 ;
strcpy ( V_175 -> V_160 , L_32 ) ;
F_59 ( V_2 , V_180 , V_181 , V_175 ) ;
return 0 ;
}
static int F_105 ( struct V_126 * V_126 , void * V_127 , const struct V_174 * V_175 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
if ( V_175 -> V_113 )
return - V_105 ;
F_59 ( V_2 , V_180 , V_267 , V_175 ) ;
return 0 ;
}
static int F_106 ( struct V_126 * V_268 )
{
int V_269 = 0 , V_270 = 0 ;
struct V_226 * V_166 = F_89 ( V_268 ) ;
struct V_1 * V_2 = F_107 ( V_268 ) ;
struct V_88 * V_89 ;
enum V_222 V_271 = 0 ;
switch ( V_166 -> V_233 ) {
case V_272 :
V_271 = V_121 ;
break;
case V_239 :
V_271 = V_123 ;
break;
case V_234 :
V_270 = 1 ;
break;
}
F_54 ( L_33 ,
F_108 ( V_166 ) , V_273 [ V_271 ] ,
V_2 -> V_274 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
cx231xx_errdev
("Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_89 = F_109 ( sizeof( struct V_88 ) , V_275 ) ;
if ( ! V_89 ) {
F_47 ( L_34 ) ;
return - V_276 ;
}
if ( F_110 ( & V_2 -> V_277 ) ) {
F_111 ( V_89 ) ;
return - V_278 ;
}
V_89 -> V_2 = V_2 ;
V_89 -> type = V_271 ;
V_268 -> V_279 = V_89 ;
F_112 ( & V_89 -> V_89 , V_166 ) ;
if ( V_89 -> type == V_121 && V_2 -> V_274 == 0 ) {
if ( V_2 -> V_280 . V_281 )
F_113 ( V_2 ,
V_282 ) ;
else
F_113 ( V_2 , V_283 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
V_2 -> V_114 = V_2 -> V_114 > 2 ? 2 : V_2 -> V_114 ;
}
if ( V_270 ) {
F_54 ( L_35 ) ;
F_59 ( V_2 , V_180 , V_284 ) ;
}
V_2 -> V_274 ++ ;
if ( V_89 -> type == V_121 )
F_116 ( & V_89 -> V_144 , & V_285 ,
NULL , & V_2 -> V_14 . V_97 ,
V_89 -> type , V_138 ,
sizeof( struct V_5 ) ,
V_89 , & V_2 -> V_277 ) ;
if ( V_89 -> type == V_123 ) {
F_117 ( V_2 , V_286 , 0 ) ;
F_116 ( & V_89 -> V_144 , & V_287 ,
NULL , & V_2 -> V_288 . V_97 ,
V_89 -> type , V_289 ,
sizeof( struct V_5 ) ,
V_89 , & V_2 -> V_277 ) ;
}
F_118 ( & V_2 -> V_277 ) ;
F_119 ( & V_89 -> V_89 ) ;
return V_269 ;
}
void F_120 ( struct V_1 * V_2 )
{
if ( V_2 -> V_246 ) {
if ( F_121 ( V_2 -> V_246 ) )
F_122 ( V_2 -> V_246 ) ;
else
F_123 ( V_2 -> V_246 ) ;
V_2 -> V_246 = NULL ;
}
if ( V_2 -> V_290 ) {
F_41 ( L_36 ,
F_108 ( V_2 -> V_290 ) ) ;
if ( F_121 ( V_2 -> V_290 ) )
F_122 ( V_2 -> V_290 ) ;
else
F_123 ( V_2 -> V_290 ) ;
V_2 -> V_290 = NULL ;
}
if ( V_2 -> V_166 ) {
F_41 ( L_36 ,
F_108 ( V_2 -> V_166 ) ) ;
if ( V_2 -> V_280 . V_291 )
F_124 ( V_2 ) ;
if ( F_121 ( V_2 -> V_166 ) )
F_122 ( V_2 -> V_166 ) ;
else
F_123 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
}
F_125 ( & V_2 -> V_292 ) ;
F_125 ( & V_2 -> V_293 ) ;
}
static int F_126 ( struct V_126 * V_268 )
{
struct V_88 * V_89 = V_268 -> V_279 ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_54 ( L_37 , V_2 -> V_274 ) ;
F_54 ( L_37 , V_2 -> V_274 ) ;
if ( F_44 ( V_89 ) )
F_45 ( V_89 ) ;
if ( ! V_2 -> V_280 . V_294 )
if ( V_89 -> type == V_123 ) {
F_127 ( & V_89 -> V_144 ) ;
F_128 ( & V_89 -> V_144 ) ;
if ( V_2 -> V_9 & V_44 ) {
if ( F_129 ( & V_2 -> V_295 ) > 0 ) {
F_130 ( V_2 ) ;
V_89 -> V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_131 ( V_2 ) ;
if ( ! V_2 -> V_296 )
F_117 ( V_2 , V_286 , 0 ) ;
else
F_117 ( V_2 , V_297 , 0 ) ;
F_132 ( & V_89 -> V_89 ) ;
F_133 ( & V_89 -> V_89 ) ;
F_111 ( V_89 ) ;
V_2 -> V_274 -- ;
F_134 ( & V_2 -> V_298 , 1 ) ;
return 0 ;
}
F_132 ( & V_89 -> V_89 ) ;
V_2 -> V_274 -- ;
if ( ! V_2 -> V_274 ) {
F_127 ( & V_89 -> V_144 ) ;
F_128 ( & V_89 -> V_144 ) ;
if ( V_2 -> V_9 & V_44 ) {
F_130 ( V_2 ) ;
V_89 -> V_2 = NULL ;
return 0 ;
}
F_59 ( V_2 , V_151 , V_299 , 0 ) ;
if ( V_2 -> V_13 )
F_135 ( V_2 ) ;
else
F_136 ( V_2 ) ;
F_137 ( V_2 , V_300 ) ;
F_117 ( V_2 , V_301 , 0 ) ;
}
F_133 ( & V_89 -> V_89 ) ;
F_111 ( V_89 ) ;
F_134 ( & V_2 -> V_298 , 1 ) ;
return 0 ;
}
static int F_138 ( struct V_126 * V_268 )
{
struct V_88 * V_89 = V_268 -> V_279 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
F_139 ( & V_2 -> V_277 ) ;
V_39 = F_126 ( V_268 ) ;
F_118 ( & V_2 -> V_277 ) ;
return V_39 ;
}
static T_4
F_140 ( struct V_126 * V_268 , char T_5 * V_6 , T_6 V_87 ,
T_7 * V_74 )
{
struct V_88 * V_89 = V_268 -> V_279 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_89 -> type == V_121 ) ||
( V_89 -> type == V_123 ) ) {
V_39 = F_43 ( V_89 ) ;
if ( F_92 ( V_39 < 0 ) )
return V_39 ;
if ( F_110 ( & V_2 -> V_277 ) )
return - V_278 ;
V_39 = F_141 ( & V_89 -> V_144 , V_6 , V_87 , V_74 , 0 ,
V_268 -> V_265 & V_266 ) ;
F_118 ( & V_2 -> V_277 ) ;
return V_39 ;
}
return 0 ;
}
static unsigned int F_142 ( struct V_126 * V_268 , T_8 * V_302 )
{
unsigned long V_303 = F_143 ( V_302 ) ;
struct V_88 * V_89 = V_268 -> V_279 ;
struct V_1 * V_2 = V_89 -> V_2 ;
unsigned V_304 = 0 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_305 ;
V_39 = F_43 ( V_89 ) ;
if ( F_92 ( V_39 < 0 ) )
return V_305 ;
if ( F_144 ( & V_89 -> V_89 ) )
V_304 |= V_306 ;
else
F_145 ( V_268 , & V_89 -> V_89 . V_302 , V_302 ) ;
if ( ! ( V_303 & ( V_307 | V_308 ) ) )
return V_304 ;
if ( ( V_121 == V_89 -> type ) ||
( V_123 == V_89 -> type ) ) {
F_139 ( & V_2 -> V_277 ) ;
V_304 |= F_146 ( V_268 , & V_89 -> V_144 , V_302 ) ;
F_118 ( & V_2 -> V_277 ) ;
return V_304 ;
}
return V_304 | V_305 ;
}
static int F_147 ( struct V_126 * V_268 , struct V_309 * V_310 )
{
struct V_88 * V_89 = V_268 -> V_279 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_92 ( V_39 < 0 ) )
return V_39 ;
if ( F_110 ( & V_2 -> V_277 ) )
return - V_278 ;
V_39 = F_148 ( & V_89 -> V_144 , V_310 ) ;
F_118 ( & V_2 -> V_277 ) ;
F_54 ( L_38 ,
( unsigned long ) V_310 -> V_311 ,
( unsigned long ) V_310 -> V_312 -
( unsigned long ) V_310 -> V_311 , V_39 ) ;
return V_39 ;
}
static struct V_226 * F_149 ( struct V_1 * V_2 ,
const struct V_226
* V_313 , const char * V_314 )
{
struct V_226 * V_315 ;
V_315 = F_150 () ;
if ( NULL == V_315 )
return NULL ;
* V_315 = * V_313 ;
V_315 -> V_316 = & V_2 -> V_316 ;
V_315 -> V_317 = F_123 ;
V_315 -> V_318 = V_319 ;
V_315 -> V_277 = & V_2 -> V_277 ;
F_151 ( V_320 , & V_315 -> V_96 ) ;
snprintf ( V_315 -> V_160 , sizeof( V_315 -> V_160 ) , L_39 , V_2 -> V_160 , V_314 ) ;
F_152 ( V_315 , V_2 ) ;
if ( V_2 -> V_189 == V_242 ) {
F_153 ( V_315 , V_321 ) ;
F_153 ( V_315 , V_322 ) ;
F_153 ( V_315 , V_323 ) ;
F_153 ( V_315 , V_324 ) ;
}
return V_315 ;
}
int F_154 ( struct V_1 * V_2 )
{
int V_156 ;
F_41 ( L_40 ,
V_2 -> V_160 , V_325 ) ;
V_2 -> V_149 = V_326 ;
V_2 -> V_70 = F_52 ( V_2 ) ;
V_2 -> V_91 = F_53 ( V_2 ) ;
V_2 -> V_327 = 0 ;
V_2 -> V_92 = & V_92 [ 0 ] ;
F_36 ( V_2 , V_2 -> V_114 ) ;
F_59 ( V_2 , V_151 , V_152 , V_2 -> V_149 ) ;
F_155 ( & V_2 -> V_292 , 10 ) ;
F_155 ( & V_2 -> V_293 , 5 ) ;
if ( V_2 -> V_328 ) {
F_156 ( & V_2 -> V_292 ,
V_2 -> V_328 -> V_292 , NULL ) ;
F_156 ( & V_2 -> V_293 ,
V_2 -> V_328 -> V_292 ,
V_329 ) ;
}
if ( V_2 -> V_292 . error )
return V_2 -> V_292 . error ;
if ( V_2 -> V_293 . error )
return V_2 -> V_293 . error ;
V_2 -> V_166 = F_149 ( V_2 , & V_330 , L_41 ) ;
if ( ! V_2 -> V_166 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_2 -> V_166 -> V_292 = & V_2 -> V_292 ;
V_156 = F_157 ( V_2 -> V_166 , V_272 ,
V_331 [ V_2 -> V_332 ] ) ;
if ( V_156 ) {
F_47 ( L_43 ,
V_156 ) ;
return V_156 ;
}
F_41 ( L_44 ,
V_2 -> V_160 , F_108 ( V_2 -> V_166 ) ) ;
V_333 = V_330 ;
strcpy ( V_333 . V_160 , L_45 ) ;
V_2 -> V_290 = F_149 ( V_2 , & V_333 , L_46 ) ;
if ( ! V_2 -> V_290 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_2 -> V_290 -> V_292 = & V_2 -> V_292 ;
V_156 = F_157 ( V_2 -> V_290 , V_239 ,
V_334 [ V_2 -> V_332 ] ) ;
if ( V_156 < 0 ) {
F_47 ( L_47 ) ;
return V_156 ;
}
F_41 ( L_48 ,
V_2 -> V_160 , F_108 ( V_2 -> V_290 ) ) ;
if ( V_229 [ V_2 -> V_230 ] . V_270 . type == V_335 ) {
V_2 -> V_246 = F_149 ( V_2 , & V_336 ,
L_49 ) ;
if ( ! V_2 -> V_246 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_2 -> V_246 -> V_292 = & V_2 -> V_293 ;
V_156 = F_157 ( V_2 -> V_246 , V_234 ,
V_337 [ V_2 -> V_332 ] ) ;
if ( V_156 < 0 ) {
F_47 ( L_50 ) ;
return V_156 ;
}
F_41 ( L_51 ,
F_108 ( V_2 -> V_246 ) ) ;
}
F_41 ( L_52 ,
F_108 ( V_2 -> V_166 ) ,
F_108 ( V_2 -> V_290 ) ) ;
return 0 ;
}
