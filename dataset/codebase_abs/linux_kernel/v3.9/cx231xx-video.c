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
V_129 -> V_130 . V_131 . V_134 = ( V_2 -> V_70 * V_130 -> V_93 + 7 ) >> 3 ;
V_129 -> V_130 . V_131 . V_135 = V_129 -> V_130 . V_131 . V_134 * V_91 ;
V_129 -> V_130 . V_131 . V_136 = V_137 ;
V_129 -> V_130 . V_131 . V_101 = V_138 ;
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
static int F_62 ( struct V_126 * V_126 , void * V_127 , T_3 * V_149 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
struct V_142 V_143 ;
struct V_128 V_129 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_41 ( L_21 , ( unsigned int ) * V_149 ) ;
V_2 -> V_149 = * V_149 ;
V_129 . V_130 . V_131 . V_70 = V_2 -> V_70 ;
V_129 . V_130 . V_131 . V_91 = V_2 -> V_91 ;
F_51 ( V_126 , V_127 , & V_129 ) ;
F_59 ( V_2 , V_150 , V_151 , V_2 -> V_149 ) ;
F_58 ( & V_143 , & V_129 . V_130 . V_131 , V_146 ) ;
F_59 ( V_2 , V_117 , V_147 , & V_143 ) ;
F_60 ( & V_129 . V_130 . V_131 , & V_143 ) ;
V_2 -> V_70 = V_129 . V_130 . V_131 . V_70 ;
V_2 -> V_91 = V_129 . V_130 . V_131 . V_91 ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_126 * V_126 , void * V_127 ,
struct V_152 * V_8 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
T_1 V_153 ;
unsigned int V_154 , V_155 ;
V_155 = V_8 -> V_113 ;
if ( V_155 >= V_156 )
return - V_105 ;
if ( 0 == F_37 ( V_155 ) -> type )
return - V_105 ;
V_8 -> V_113 = V_155 ;
V_8 -> type = V_157 ;
strcpy ( V_8 -> V_158 , V_159 [ F_37 ( V_155 ) -> type ] ) ;
if ( ( V_160 == F_37 ( V_155 ) -> type ) ||
( V_161 == F_37 ( V_155 ) -> type ) )
V_8 -> type = V_162 ;
V_8 -> V_163 = V_2 -> V_164 -> V_165 ;
if ( V_155 == V_2 -> V_114 ) {
V_154 = F_64 ( V_2 , V_166 ,
V_167 , 2 , & V_153 , 4 ) ;
if ( V_154 > 0 ) {
if ( ( V_153 & V_168 ) == 0x00 )
V_8 -> V_20 |= V_169 ;
if ( ( V_153 & V_170 ) == 0x00 )
V_8 -> V_20 |= V_171 ;
}
}
return 0 ;
}
static int F_65 ( struct V_126 * V_126 , void * V_127 , unsigned int * V_8 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
* V_8 = V_2 -> V_114 ;
return 0 ;
}
static int F_66 ( struct V_126 * V_126 , void * V_127 , unsigned int V_8 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_2 -> V_108 = 0 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_8 >= V_156 )
return - V_105 ;
if ( 0 == F_37 ( V_8 ) -> type )
return - V_105 ;
F_36 ( V_2 , V_8 ) ;
if ( F_37 ( V_8 ) -> type == V_160 ||
F_37 ( V_8 ) -> type == V_161 ) {
F_59 ( V_2 , V_150 , V_151 , V_2 -> V_149 ) ;
}
return 0 ;
}
static int F_67 ( struct V_126 * V_126 , void * V_127 , struct V_172 * V_173 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
switch ( V_173 -> V_113 ) {
case V_174 :
strcpy ( V_173 -> V_158 , L_22 ) ;
break;
case V_175 :
strcpy ( V_173 -> V_158 , L_23 ) ;
break;
default:
return - V_105 ;
}
V_173 -> V_113 = V_2 -> V_115 ;
V_173 -> V_176 = V_177 ;
return 0 ;
}
static int F_68 ( struct V_126 * V_126 , void * V_127 , const struct V_172 * V_173 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_20 = 0 ;
if ( V_173 -> V_113 != V_2 -> V_115 )
return - V_105 ;
V_2 -> V_115 = F_37 ( V_173 -> V_113 ) -> V_116 ;
V_20 = F_40 ( V_2 , V_2 -> V_115 ) ;
return V_20 ;
}
static int F_69 ( struct V_126 * V_126 , void * V_127 ,
struct V_178 * V_179 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_148 = V_179 -> V_148 ;
int V_8 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_179 -> V_148 = F_70 ( V_180 , V_179 -> V_148 ) ;
if ( F_71 ( V_179 -> V_148 == 0 ) )
return - V_105 ;
memset ( V_179 , 0 , sizeof( * V_179 ) ) ;
V_179 -> V_148 = V_148 ;
if ( V_179 -> V_148 < V_181 || V_179 -> V_148 >= V_182 )
return - V_105 ;
for ( V_8 = 0 ; V_8 < V_183 ; V_8 ++ )
if ( V_184 [ V_8 ] . V_185 . V_148 == V_179 -> V_148 )
break;
if ( V_8 == V_183 ) {
* V_179 = V_186 ;
return 0 ;
}
* V_179 = V_184 [ V_8 ] . V_185 ;
F_59 ( V_2 , V_150 , V_187 , V_179 ) ;
if ( V_179 -> type )
return 0 ;
else
return - V_105 ;
}
static int F_72 ( struct V_126 * V_126 , void * V_127 ,
struct V_188 * V_189 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_150 , V_190 , V_189 ) ;
return V_39 ;
}
static int F_73 ( struct V_126 * V_126 , void * V_127 ,
struct V_188 * V_189 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_150 , V_191 , V_189 ) ;
return V_39 ;
}
static int F_74 ( struct V_126 * V_126 , void * V_127 , struct V_192 * V_193 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_193 -> V_113 )
return - V_105 ;
strcpy ( V_193 -> V_158 , L_24 ) ;
V_193 -> type = V_194 ;
V_193 -> V_176 = V_195 ;
V_193 -> V_196 = 0xffffffffUL ;
V_193 -> signal = 0xffff ;
return 0 ;
}
static int F_75 ( struct V_126 * V_126 , void * V_127 , struct V_192 * V_193 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_193 -> V_113 )
return - V_105 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
static int F_76 ( struct V_126 * V_126 , void * V_127 ,
struct V_197 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> type = V_89 -> V_198 ? V_199 : V_194 ;
V_129 -> V_200 = V_2 -> V_201 ;
F_59 ( V_2 , V_202 , V_203 , V_129 ) ;
return 0 ;
}
static int F_77 ( struct V_126 * V_126 , void * V_127 ,
struct V_197 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
T_1 V_204 = 5400000 ;
F_41 ( L_25 ,
V_129 -> V_200 , V_129 -> type ) ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_129 -> V_202 )
return - V_105 ;
if ( F_71 ( 0 == V_89 -> V_198 && V_129 -> type != V_194 ) )
return - V_105 ;
if ( F_71 ( 1 == V_89 -> V_198 && V_129 -> type != V_199 ) )
return - V_105 ;
V_39 = F_78 ( V_2 ) ;
V_2 -> V_201 = V_129 -> V_200 ;
F_59 ( V_2 , V_202 , V_205 , V_129 ) ;
V_39 = F_79 ( V_2 ) ;
if ( V_2 -> V_206 == V_207 ) {
if ( V_2 -> V_149 & ( V_208 | V_209 ) )
V_204 = 5400000 ;
else if ( V_2 -> V_149 & V_210 )
V_204 = 6000000 ;
else if ( V_2 -> V_149 & ( V_211 | V_212 ) )
V_204 = 6900000 ;
else if ( V_2 -> V_149 & V_213 )
V_204 = 7100000 ;
else if ( V_2 -> V_149 & V_214 )
V_204 = 7250000 ;
else if ( V_2 -> V_149 & V_215 )
V_204 = 6900000 ;
else if ( V_2 -> V_149 & V_216 )
V_204 = 1250000 ;
F_41 ( L_26 , V_204 ) ;
F_80 ( V_2 , V_204 , 1 , 1 ) ;
F_81 ( V_2 ) ;
}
F_41 ( L_27 , V_129 -> V_200 ) ;
return V_39 ;
}
static int F_82 ( struct V_126 * V_126 , void * V_127 ,
struct V_217 * V_218 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_154 = 0 ;
T_2 V_219 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_220 = 0 ;
switch ( V_218 -> V_221 . type ) {
case V_222 :
switch ( V_218 -> V_221 . V_223 ) {
case 0 :
V_154 = F_83 ( V_2 , V_224 ,
( V_80 ) V_218 -> V_218 , V_219 , 4 ) ;
V_218 -> V_225 = V_219 [ 0 ] | V_219 [ 1 ] << 8 |
V_219 [ 2 ] << 16 | V_219 [ 3 ] << 24 ;
break;
case 1 :
V_154 = F_64 ( V_2 , V_226 ,
( V_80 ) V_218 -> V_218 , 2 , & V_220 , 1 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 14 :
V_154 = F_64 ( V_2 , V_226 ,
( V_80 ) V_218 -> V_218 , 2 , & V_220 , 4 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
break;
case 2 :
V_154 = F_64 ( V_2 , V_166 ,
( V_80 ) V_218 -> V_218 , 2 , & V_220 , 1 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 24 :
V_154 = F_64 ( V_2 , V_166 ,
( V_80 ) V_218 -> V_218 , 2 , & V_220 , 4 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
break;
case 3 :
V_154 = F_64 ( V_2 ,
V_227 ,
( V_80 ) V_218 -> V_218 , 1 ,
& V_220 , 1 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 34 :
V_154 =
F_64 ( V_2 , V_227 ,
( V_80 ) V_218 -> V_218 , 1 , & V_220 , 4 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
break;
}
return V_154 < 0 ? V_154 : 0 ;
case V_228 :
F_59 ( V_2 , V_150 , V_229 , V_218 ) ;
return 0 ;
case V_230 :
switch ( V_218 -> V_221 . V_223 ) {
case 0 :
V_154 = F_83 ( V_2 , V_224 ,
( V_80 ) V_218 -> V_218 , V_219 , 4 ) ;
V_218 -> V_225 = V_219 [ 0 ] | V_219 [ 1 ] << 8 |
V_219 [ 2 ] << 16 | V_219 [ 3 ] << 24 ;
break;
case 0x600 :
V_154 = F_85 ( V_2 , V_226 ,
( V_80 ) V_218 -> V_218 , 2 ,
& V_220 , 1 , 0 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 0x880 :
if ( V_218 -> V_218 < 0x0b ) {
V_154 = F_85 ( V_2 ,
V_166 ,
( V_80 ) V_218 -> V_218 , 2 ,
& V_220 , 1 , 0 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
} else {
V_154 = F_85 ( V_2 ,
V_166 ,
( V_80 ) V_218 -> V_218 , 2 ,
& V_220 , 4 , 0 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
}
break;
case 0x980 :
V_154 = F_85 ( V_2 ,
V_227 ,
( V_80 ) V_218 -> V_218 , 1 ,
& V_220 , 1 , 0 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 0x400 :
V_154 =
F_85 ( V_2 , 0x40 ,
( V_80 ) V_218 -> V_218 , 1 ,
& V_220 , 1 , 0 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 0xc01 :
V_154 =
F_85 ( V_2 , 0xc0 ,
( V_80 ) V_218 -> V_218 , 2 ,
& V_220 , 38 , 1 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
break;
case 0x022 :
V_154 =
F_85 ( V_2 , 0x02 ,
( V_80 ) V_218 -> V_218 , 1 ,
& V_220 , 1 , 2 ) ;
V_218 -> V_225 = F_84 ( V_220 & 0xff ) ;
break;
case 0x322 :
V_154 = F_85 ( V_2 ,
0x32 ,
( V_80 ) V_218 -> V_218 , 1 ,
& V_220 , 4 , 2 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
break;
case 0x342 :
V_154 = F_85 ( V_2 ,
0x34 ,
( V_80 ) V_218 -> V_218 , 1 ,
& V_220 , 4 , 2 ) ;
V_218 -> V_225 = F_84 ( V_220 ) ;
break;
default:
F_41 ( L_28 ) ;
break;
}
return V_154 < 0 ? V_154 : 0 ;
default:
if ( ! F_86 ( & V_218 -> V_221 ) )
return - V_105 ;
}
F_59 ( V_2 , V_150 , V_229 , V_218 ) ;
return V_154 ;
}
static int F_87 ( struct V_126 * V_126 , void * V_127 ,
struct V_217 * V_218 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_154 = 0 ;
T_4 V_6 ;
T_1 V_219 ;
T_2 V_220 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_6 = F_88 ( V_218 -> V_225 ) ;
switch ( V_218 -> V_221 . type ) {
case V_222 :
{
V_219 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_218 -> V_221 . V_223 ) {
case 0 :
V_220 [ 0 ] = ( T_2 ) V_219 ;
V_220 [ 1 ] = ( T_2 ) ( V_219 >> 8 ) ;
V_220 [ 2 ] = ( T_2 ) ( V_219 >> 16 ) ;
V_220 [ 3 ] = ( T_2 ) ( V_219 >> 24 ) ;
V_154 = F_89 ( V_2 ,
V_231 ,
( V_80 ) V_218 -> V_218 , V_220 ,
4 ) ;
break;
case 1 :
V_154 = F_90 ( V_2 ,
V_226 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 1 ) ;
break;
case 14 :
V_154 = F_90 ( V_2 ,
V_226 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 4 ) ;
break;
case 2 :
V_154 =
F_90 ( V_2 ,
V_166 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 1 ) ;
break;
case 24 :
V_154 =
F_90 ( V_2 ,
V_166 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 4 ) ;
break;
case 3 :
V_154 =
F_90 ( V_2 ,
V_227 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 1 ) ;
break;
case 34 :
V_154 =
F_90 ( V_2 ,
V_227 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 4 ) ;
break;
}
}
return V_154 < 0 ? V_154 : 0 ;
case V_230 :
{
V_219 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_218 -> V_221 . V_223 ) {
case 0 :
V_220 [ 0 ] = ( T_2 ) V_219 ;
V_220 [ 1 ] = ( T_2 ) ( V_219 >> 8 ) ;
V_220 [ 2 ] = ( T_2 ) ( V_219 >> 16 ) ;
V_220 [ 3 ] = ( T_2 ) ( V_219 >> 24 ) ;
V_154 = F_89 ( V_2 ,
V_231 ,
( V_80 ) V_218 -> V_218 , V_220 ,
4 ) ;
break;
case 0x600 :
V_154 = F_91 ( V_2 ,
V_226 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 1 , 0 ) ;
break;
case 0x880 :
if ( V_218 -> V_218 < 0x0b )
F_91 ( V_2 ,
V_166 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 1 , 0 ) ;
else
F_91 ( V_2 ,
V_166 ,
( V_80 ) V_218 -> V_218 , 2 ,
V_219 , 4 , 0 ) ;
break;
case 0x980 :
V_154 =
F_91 ( V_2 ,
V_227 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 1 , 0 ) ;
break;
case 0x400 :
V_154 =
F_91 ( V_2 ,
0x40 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 1 , 0 ) ;
break;
case 0xc01 :
V_154 =
F_91 ( V_2 ,
0xc0 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 1 , 1 ) ;
break;
case 0x022 :
V_154 =
F_91 ( V_2 ,
0x02 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 1 , 2 ) ;
break;
case 0x322 :
V_154 =
F_91 ( V_2 ,
0x32 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 4 , 2 ) ;
break;
case 0x342 :
V_154 =
F_91 ( V_2 ,
0x34 ,
( V_80 ) V_218 -> V_218 , 1 ,
V_219 , 4 , 2 ) ;
break;
default:
F_41 ( L_29
L_30 , V_218 -> V_221 . V_223 ) ;
break;
}
}
default:
break;
}
F_59 ( V_2 , V_150 , V_232 , V_218 ) ;
return V_154 ;
}
static int F_92 ( struct V_126 * V_126 , void * V_127 ,
struct V_233 * V_234 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_234 -> type != V_121 )
return - V_105 ;
V_234 -> V_235 . V_236 = 0 ;
V_234 -> V_235 . V_237 = 0 ;
V_234 -> V_235 . V_70 = V_2 -> V_70 ;
V_234 -> V_235 . V_91 = V_2 -> V_91 ;
V_234 -> V_238 = V_234 -> V_235 ;
V_234 -> V_239 . V_240 = 54 ;
V_234 -> V_239 . V_241 = 59 ;
return 0 ;
}
static int F_93 ( struct V_126 * V_126 , void * V_127 ,
enum V_242 type )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_94 ( V_39 >= 0 ) )
V_39 = F_95 ( & V_89 -> V_144 ) ;
F_59 ( V_2 , V_117 , V_243 , 1 ) ;
return V_39 ;
}
static int F_96 ( struct V_126 * V_126 , void * V_127 ,
enum V_242 type )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_89 -> type != V_121 ) &&
( V_89 -> type != V_123 ) )
return - V_105 ;
if ( type != V_89 -> type )
return - V_105 ;
F_39 ( V_2 , V_117 , V_243 , 0 ) ;
F_97 ( & V_89 -> V_144 ) ;
F_45 ( V_89 ) ;
return 0 ;
}
static int F_98 ( struct V_126 * V_126 , void * V_127 ,
struct V_244 * V_245 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_99 ( V_245 -> V_246 , L_31 , sizeof( V_245 -> V_246 ) ) ;
F_99 ( V_245 -> V_247 , V_248 [ V_2 -> V_249 ] . V_158 , sizeof( V_245 -> V_247 ) ) ;
F_100 ( V_2 -> V_250 , V_245 -> V_251 , sizeof( V_245 -> V_251 ) ) ;
V_245 -> V_252 = V_253 |
#if 0
V4L2_CAP_SLICED_VBI_CAPTURE |
#endif
V_254 |
V_255 |
V_256 |
V_257 ;
if ( V_2 -> V_206 != V_258 )
V_245 -> V_252 |= V_259 ;
return 0 ;
}
static int F_101 ( struct V_126 * V_126 , void * V_127 ,
struct V_260 * V_129 )
{
if ( F_71 ( V_129 -> V_113 >= F_50 ( V_92 ) ) )
return - V_105 ;
F_99 ( V_129 -> V_261 , V_92 [ V_129 -> V_113 ] . V_158 , sizeof( V_129 -> V_261 ) ) ;
V_129 -> V_132 = V_92 [ V_129 -> V_113 ] . V_133 ;
return 0 ;
}
static int F_102 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_129 -> V_130 . V_262 . V_263 = 0 ;
F_59 ( V_2 , V_264 , V_265 , & V_129 -> V_130 . V_262 ) ;
if ( V_129 -> V_130 . V_262 . V_263 == 0 )
V_39 = - V_105 ;
return V_39 ;
}
static int F_103 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_264 , V_265 , & V_129 -> V_130 . V_262 ) ;
if ( V_129 -> V_130 . V_262 . V_263 == 0 )
return - V_105 ;
return 0 ;
}
static int F_104 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
V_129 -> V_130 . V_264 . V_266 = 6750000 * 4 ;
V_129 -> V_130 . V_264 . V_267 = V_268 ;
V_129 -> V_130 . V_264 . V_269 = V_270 ;
V_129 -> V_130 . V_264 . V_50 = 0 ;
V_129 -> V_130 . V_264 . V_271 [ 0 ] = ( V_2 -> V_149 & V_272 ) ?
V_273 : V_274 ;
V_129 -> V_130 . V_264 . V_87 [ 0 ] = ( V_2 -> V_149 & V_272 ) ?
V_275 : V_276 ;
V_129 -> V_130 . V_264 . V_271 [ 1 ] = ( V_2 -> V_149 & V_272 ) ?
V_273 + 312 : V_274 + 263 ;
V_129 -> V_130 . V_264 . V_87 [ 1 ] = V_129 -> V_130 . V_264 . V_87 [ 0 ] ;
return 0 ;
}
static int F_105 ( struct V_126 * V_126 , void * V_127 ,
struct V_128 * V_129 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
if ( V_2 -> V_124 && ! V_89 -> V_120 ) {
F_47 ( L_20 , V_145 ) ;
return - V_122 ;
}
V_129 -> type = V_123 ;
V_129 -> V_130 . V_264 . V_266 = 6750000 * 4 ;
V_129 -> V_130 . V_264 . V_267 = V_268 ;
V_129 -> V_130 . V_264 . V_269 = V_270 ;
V_129 -> V_130 . V_264 . V_50 = 0 ;
V_129 -> V_130 . V_264 . V_96 = 0 ;
V_129 -> V_130 . V_264 . V_271 [ 0 ] = ( V_2 -> V_149 & V_272 ) ?
V_273 : V_274 ;
V_129 -> V_130 . V_264 . V_87 [ 0 ] = ( V_2 -> V_149 & V_272 ) ?
V_275 : V_276 ;
V_129 -> V_130 . V_264 . V_271 [ 1 ] = ( V_2 -> V_149 & V_272 ) ?
V_273 + 312 : V_274 + 263 ;
V_129 -> V_130 . V_264 . V_87 [ 1 ] = V_129 -> V_130 . V_264 . V_87 [ 0 ] ;
return 0 ;
}
static int F_106 ( struct V_126 * V_126 , void * V_127 ,
struct V_277 * V_278 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_107 ( & V_89 -> V_144 , V_278 ) ;
}
static int F_108 ( struct V_126 * V_126 , void * V_127 , struct V_279 * V_280 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_109 ( & V_89 -> V_144 , V_280 ) ;
}
static int F_110 ( struct V_126 * V_126 , void * V_127 , struct V_279 * V_280 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_111 ( & V_89 -> V_144 , V_280 ) ;
}
static int F_112 ( struct V_126 * V_126 , void * V_127 , struct V_279 * V_280 )
{
struct V_88 * V_89 = V_127 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_113 ( & V_89 -> V_144 , V_280 , V_126 -> V_281 & V_282 ) ;
}
static int F_114 ( struct V_126 * V_126 , void * V_127 ,
struct V_244 * V_245 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
F_99 ( V_245 -> V_246 , L_31 , sizeof( V_245 -> V_246 ) ) ;
F_99 ( V_245 -> V_247 , V_248 [ V_2 -> V_249 ] . V_158 , sizeof( V_245 -> V_247 ) ) ;
F_100 ( V_2 -> V_250 , V_245 -> V_251 , sizeof( V_245 -> V_251 ) ) ;
V_245 -> V_252 = V_259 ;
return 0 ;
}
static int F_115 ( struct V_126 * V_126 , void * V_127 , struct V_192 * V_193 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
if ( F_71 ( V_193 -> V_113 > 0 ) )
return - V_105 ;
strcpy ( V_193 -> V_158 , L_32 ) ;
V_193 -> type = V_199 ;
F_59 ( V_2 , V_202 , V_283 , V_193 ) ;
return 0 ;
}
static int F_116 ( struct V_126 * V_126 , void * V_127 , struct V_152 * V_8 )
{
if ( V_8 -> V_113 != 0 )
return - V_105 ;
strcpy ( V_8 -> V_158 , L_32 ) ;
V_8 -> type = V_162 ;
return 0 ;
}
static int F_117 ( struct V_126 * V_126 , void * V_127 , struct V_172 * V_173 )
{
if ( F_71 ( V_173 -> V_113 ) )
return - V_105 ;
strcpy ( V_173 -> V_158 , L_32 ) ;
return 0 ;
}
static int F_118 ( struct V_126 * V_126 , void * V_127 , struct V_192 * V_193 )
{
struct V_1 * V_2 = ( (struct V_88 * ) V_127 ) -> V_2 ;
if ( 0 != V_193 -> V_113 )
return - V_105 ;
F_59 ( V_2 , V_202 , V_283 , V_193 ) ;
return 0 ;
}
static int F_119 ( struct V_126 * V_126 , void * V_89 , const struct V_172 * V_173 )
{
return 0 ;
}
static int F_120 ( struct V_126 * V_126 , void * V_89 , unsigned int V_8 )
{
return 0 ;
}
static int F_121 ( struct V_126 * V_126 , void * V_127 ,
struct V_178 * V_284 )
{
int V_8 ;
if ( V_284 -> V_148 < V_181 || V_284 -> V_148 >= V_182 )
return - V_105 ;
if ( V_284 -> V_148 == V_285 ) {
for ( V_8 = 0 ; V_8 < V_183 ; V_8 ++ ) {
if ( V_184 [ V_8 ] . V_185 . V_148 == V_284 -> V_148 )
break;
}
if ( V_8 == V_183 )
return - V_105 ;
* V_284 = V_184 [ V_8 ] . V_185 ;
} else
* V_284 = V_186 ;
return 0 ;
}
static int F_122 ( struct V_126 * V_286 )
{
int V_287 = 0 , V_198 = 0 ;
struct V_288 * V_164 = F_123 ( V_286 ) ;
struct V_1 * V_2 = F_124 ( V_286 ) ;
struct V_88 * V_89 ;
enum V_242 V_289 = 0 ;
switch ( V_164 -> V_290 ) {
case V_291 :
V_289 = V_121 ;
break;
case V_292 :
V_289 = V_123 ;
break;
case V_293 :
V_198 = 1 ;
break;
}
F_54 ( L_33 ,
F_125 ( V_164 ) , V_294 [ V_289 ] ,
V_2 -> V_295 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
cx231xx_errdev
("Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_89 = F_126 ( sizeof( struct V_88 ) , V_296 ) ;
if ( ! V_89 ) {
F_47 ( L_34 ) ;
return - V_297 ;
}
if ( F_127 ( & V_2 -> V_298 ) ) {
F_128 ( V_89 ) ;
return - V_299 ;
}
V_89 -> V_2 = V_2 ;
V_89 -> V_198 = V_198 ;
V_89 -> type = V_289 ;
V_286 -> V_300 = V_89 ;
if ( V_89 -> type == V_121 && V_2 -> V_295 == 0 ) {
V_2 -> V_70 = F_52 ( V_2 ) ;
V_2 -> V_91 = F_53 ( V_2 ) ;
if ( V_2 -> V_301 . V_302 )
F_129 ( V_2 ,
V_303 ) ;
else
F_129 ( V_2 , V_304 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_130 ( V_2 ) ;
F_131 ( V_2 ) ;
V_2 -> V_114 = V_2 -> V_114 > 2 ? 2 : V_2 -> V_114 ;
}
if ( V_89 -> V_198 ) {
F_54 ( L_35 ) ;
F_59 ( V_2 , V_202 , V_305 ) ;
}
V_2 -> V_295 ++ ;
if ( V_89 -> type == V_121 )
F_132 ( & V_89 -> V_144 , & V_306 ,
NULL , & V_2 -> V_14 . V_97 ,
V_89 -> type , V_138 ,
sizeof( struct V_5 ) ,
V_89 , & V_2 -> V_298 ) ;
if ( V_89 -> type == V_123 ) {
F_133 ( V_2 , V_307 , 0 ) ;
F_132 ( & V_89 -> V_144 , & V_308 ,
NULL , & V_2 -> V_309 . V_97 ,
V_89 -> type , V_310 ,
sizeof( struct V_5 ) ,
V_89 , & V_2 -> V_298 ) ;
}
F_134 ( & V_2 -> V_298 ) ;
return V_287 ;
}
void F_135 ( struct V_1 * V_2 )
{
if ( V_2 -> V_311 ) {
if ( F_136 ( V_2 -> V_311 ) )
F_137 ( V_2 -> V_311 ) ;
else
F_138 ( V_2 -> V_311 ) ;
V_2 -> V_311 = NULL ;
}
if ( V_2 -> V_312 ) {
F_41 ( L_36 ,
F_125 ( V_2 -> V_312 ) ) ;
if ( F_136 ( V_2 -> V_312 ) )
F_137 ( V_2 -> V_312 ) ;
else
F_138 ( V_2 -> V_312 ) ;
V_2 -> V_312 = NULL ;
}
if ( V_2 -> V_164 ) {
F_41 ( L_36 ,
F_125 ( V_2 -> V_164 ) ) ;
if ( V_2 -> V_301 . V_313 )
F_139 ( V_2 ) ;
if ( F_136 ( V_2 -> V_164 ) )
F_137 ( V_2 -> V_164 ) ;
else
F_138 ( V_2 -> V_164 ) ;
V_2 -> V_164 = NULL ;
}
}
static int F_140 ( struct V_126 * V_286 )
{
struct V_88 * V_89 = V_286 -> V_300 ;
struct V_1 * V_2 = V_89 -> V_2 ;
F_54 ( L_37 , V_2 -> V_295 ) ;
F_54 ( L_37 , V_2 -> V_295 ) ;
if ( F_44 ( V_89 ) )
F_45 ( V_89 ) ;
if ( ! V_2 -> V_301 . V_314 )
if ( V_89 -> type == V_123 ) {
F_141 ( & V_89 -> V_144 ) ;
F_142 ( & V_89 -> V_144 ) ;
if ( V_2 -> V_9 & V_44 ) {
if ( F_143 ( & V_2 -> V_315 ) > 0 ) {
F_144 ( V_2 ) ;
V_89 -> V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_145 ( V_2 ) ;
if ( ! V_2 -> V_316 )
F_133 ( V_2 , V_307 , 0 ) ;
else
F_133 ( V_2 , V_317 , 0 ) ;
F_128 ( V_89 ) ;
V_2 -> V_295 -- ;
F_146 ( & V_2 -> V_318 , 1 ) ;
return 0 ;
}
V_2 -> V_295 -- ;
if ( ! V_2 -> V_295 ) {
F_141 ( & V_89 -> V_144 ) ;
F_142 ( & V_89 -> V_144 ) ;
if ( V_2 -> V_9 & V_44 ) {
F_144 ( V_2 ) ;
V_89 -> V_2 = NULL ;
return 0 ;
}
F_59 ( V_2 , V_150 , V_319 , 0 ) ;
if ( V_2 -> V_13 )
F_147 ( V_2 ) ;
else
F_148 ( V_2 ) ;
F_149 ( V_2 , V_320 ) ;
F_133 ( V_2 , V_321 , 0 ) ;
}
F_128 ( V_89 ) ;
F_146 ( & V_2 -> V_318 , 1 ) ;
return 0 ;
}
static int F_150 ( struct V_126 * V_286 )
{
struct V_88 * V_89 = V_286 -> V_300 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
F_151 ( & V_2 -> V_298 ) ;
V_39 = F_140 ( V_286 ) ;
F_134 ( & V_2 -> V_298 ) ;
return V_39 ;
}
static T_5
F_152 ( struct V_126 * V_286 , char T_6 * V_6 , T_7 V_87 ,
T_8 * V_74 )
{
struct V_88 * V_89 = V_286 -> V_300 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_89 -> type == V_121 ) ||
( V_89 -> type == V_123 ) ) {
V_39 = F_43 ( V_89 ) ;
if ( F_71 ( V_39 < 0 ) )
return V_39 ;
if ( F_127 ( & V_2 -> V_298 ) )
return - V_299 ;
V_39 = F_153 ( & V_89 -> V_144 , V_6 , V_87 , V_74 , 0 ,
V_286 -> V_281 & V_282 ) ;
F_134 ( & V_2 -> V_298 ) ;
return V_39 ;
}
return 0 ;
}
static unsigned int F_154 ( struct V_126 * V_286 , T_9 * V_322 )
{
struct V_88 * V_89 = V_286 -> V_300 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_71 ( V_39 < 0 ) )
return V_323 ;
if ( ( V_121 == V_89 -> type ) ||
( V_123 == V_89 -> type ) ) {
unsigned int V_324 ;
F_151 ( & V_2 -> V_298 ) ;
V_324 = F_155 ( V_286 , & V_89 -> V_144 , V_322 ) ;
F_134 ( & V_2 -> V_298 ) ;
return V_324 ;
}
return V_323 ;
}
static int F_156 ( struct V_126 * V_286 , struct V_325 * V_326 )
{
struct V_88 * V_89 = V_286 -> V_300 ;
struct V_1 * V_2 = V_89 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_89 ) ;
if ( F_71 ( V_39 < 0 ) )
return V_39 ;
if ( F_127 ( & V_2 -> V_298 ) )
return - V_299 ;
V_39 = F_157 ( & V_89 -> V_144 , V_326 ) ;
F_134 ( & V_2 -> V_298 ) ;
F_54 ( L_38 ,
( unsigned long ) V_326 -> V_327 ,
( unsigned long ) V_326 -> V_328 -
( unsigned long ) V_326 -> V_327 , V_39 ) ;
return V_39 ;
}
static struct V_288 * F_158 ( struct V_1 * V_2 ,
const struct V_288
* V_329 , const char * V_330 )
{
struct V_288 * V_331 ;
V_331 = F_159 () ;
if ( NULL == V_331 )
return NULL ;
* V_331 = * V_329 ;
V_331 -> V_332 = & V_2 -> V_332 ;
V_331 -> V_333 = F_138 ;
V_331 -> V_334 = V_335 ;
V_331 -> V_298 = & V_2 -> V_298 ;
snprintf ( V_331 -> V_158 , sizeof( V_331 -> V_158 ) , L_39 , V_2 -> V_158 , V_330 ) ;
F_160 ( V_331 , V_2 ) ;
return V_331 ;
}
int F_161 ( struct V_1 * V_2 )
{
int V_154 ;
F_41 ( L_40 ,
V_2 -> V_158 , V_336 ) ;
V_2 -> V_70 = F_52 ( V_2 ) ;
V_2 -> V_91 = F_53 ( V_2 ) ;
V_2 -> V_337 = 0 ;
V_2 -> V_92 = & V_92 [ 0 ] ;
F_36 ( V_2 , V_2 -> V_114 ) ;
V_2 -> V_338 = 1 ;
V_2 -> V_339 = 0x1f ;
V_2 -> V_164 = F_158 ( V_2 , & V_340 , L_41 ) ;
if ( ! V_2 -> V_164 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_154 = F_162 ( V_2 -> V_164 , V_291 ,
V_341 [ V_2 -> V_342 ] ) ;
if ( V_154 ) {
F_47 ( L_43 ,
V_154 ) ;
return V_154 ;
}
F_41 ( L_44 ,
V_2 -> V_158 , F_125 ( V_2 -> V_164 ) ) ;
V_343 = V_340 ;
strcpy ( V_343 . V_158 , L_45 ) ;
V_2 -> V_312 = F_158 ( V_2 , & V_343 , L_46 ) ;
V_154 = F_162 ( V_2 -> V_312 , V_292 ,
V_344 [ V_2 -> V_342 ] ) ;
if ( V_154 < 0 ) {
F_47 ( L_47 ) ;
return V_154 ;
}
F_41 ( L_48 ,
V_2 -> V_158 , F_125 ( V_2 -> V_312 ) ) ;
if ( V_248 [ V_2 -> V_249 ] . V_198 . type == V_345 ) {
V_2 -> V_311 = F_158 ( V_2 , & V_346 ,
L_49 ) ;
if ( ! V_2 -> V_311 ) {
F_47 ( L_42 ) ;
return - V_125 ;
}
V_154 = F_162 ( V_2 -> V_311 , V_293 ,
V_347 [ V_2 -> V_342 ] ) ;
if ( V_154 < 0 ) {
F_47 ( L_50 ) ;
return V_154 ;
}
F_41 ( L_51 ,
F_125 ( V_2 -> V_311 ) ) ;
}
F_41 ( L_52 ,
F_125 ( V_2 -> V_164 ) ,
F_125 ( V_2 -> V_312 ) ) ;
return 0 ;
}
