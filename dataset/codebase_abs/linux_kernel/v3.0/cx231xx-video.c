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
struct V_5 * V_6 ;
struct V_3 * V_4 = V_37 -> V_38 ;
unsigned char * V_33 = NULL ;
int V_8 , V_39 = 1 ;
unsigned char * V_40 ;
T_1 V_41 = 0 , V_42 = 0 ;
T_2 V_43 = 0 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_9 & V_44 ) || ( V_2 -> V_9 & V_45 ) )
return 0 ;
if ( V_37 -> V_20 < 0 ) {
F_6 ( V_2 , - 1 , V_37 -> V_20 ) ;
if ( V_37 -> V_20 == - V_22 )
return 0 ;
}
V_6 = V_2 -> V_14 . V_15 . V_6 ;
if ( V_6 != NULL )
V_33 = F_11 ( & V_6 -> V_7 ) ;
for ( V_8 = 0 ; V_8 < V_37 -> V_46 ; V_8 ++ ) {
int V_20 = V_37 -> V_47 [ V_8 ] . V_20 ;
if ( V_20 < 0 ) {
F_6 ( V_2 , V_8 , V_20 ) ;
if ( V_37 -> V_47 [ V_8 ] . V_20 != - V_27 )
continue;
}
if ( V_37 -> V_47 [ V_8 ] . V_48 <= 0 ) {
continue;
}
if ( V_37 -> V_47 [ V_8 ] . V_48 >
V_2 -> V_14 . V_49 ) {
F_2 ( L_14 ) ;
continue;
}
V_40 = V_37 -> V_50 + V_37 -> V_47 [ V_8 ] . V_51 ;
V_42 = V_37 -> V_47 [ V_8 ] . V_48 ;
V_41 = 0 ;
if ( V_4 -> V_52 ) {
V_43 = V_4 -> V_53 ;
} else {
V_43 =
F_13 ( V_40 ,
V_4 -> V_54 ,
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
T_1 V_55 = 0 ;
V_43 = F_15 (
V_40 + V_41 ,
V_42 - V_41 ,
& V_55 ) ;
V_41 += V_55 ;
V_43 &= 0xF0 ;
if ( V_43 && ( V_41 < V_42 ) ) {
V_41 += F_14 ( V_2 ,
V_4 , V_43 ,
V_40 + V_41 ,
V_42 - V_41 ) ;
}
}
memcpy ( V_4 -> V_54 , V_40 + V_42 - 4 , 4 ) ;
V_41 = 0 ;
}
return V_39 ;
}
static inline int F_16 ( struct V_1 * V_2 , struct V_37 * V_37 )
{
struct V_5 * V_6 ;
struct V_3 * V_4 = V_37 -> V_38 ;
unsigned char * V_33 = NULL ;
int V_39 = 1 ;
unsigned char * V_40 ;
T_1 V_41 = 0 , V_42 = 0 ;
T_2 V_43 = 0 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_9 & V_44 ) || ( V_2 -> V_9 & V_45 ) )
return 0 ;
if ( V_37 -> V_20 < 0 ) {
F_6 ( V_2 , - 1 , V_37 -> V_20 ) ;
if ( V_37 -> V_20 == - V_22 )
return 0 ;
}
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 != NULL )
V_33 = F_11 ( & V_6 -> V_7 ) ;
if ( 1 ) {
V_40 = V_37 -> V_50 ;
V_42 = V_37 -> V_48 ;
V_41 = 0 ;
if ( V_4 -> V_52 ) {
V_43 = V_4 -> V_53 ;
} else {
V_43 =
F_13 ( V_40 ,
V_4 -> V_54 ,
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
T_1 V_55 = 0 ;
V_43 = F_15 (
V_40 + V_41 ,
V_42 - V_41 ,
& V_55 ) ;
V_41 += V_55 ;
V_43 &= 0xF0 ;
if ( V_43 && ( V_41 < V_42 ) ) {
V_41 += F_14 ( V_2 ,
V_4 , V_43 ,
V_40 + V_41 ,
V_42 - V_41 ) ;
}
}
memcpy ( V_4 -> V_54 , V_40 + V_42 - 4 , 4 ) ;
V_41 = 0 ;
}
return V_39 ;
}
T_2 F_13 ( T_2 * V_40 , T_2 * V_54 ,
T_1 * V_56 )
{
T_1 V_55 ;
T_2 V_57 [ 8 ] ;
T_2 V_43 = 0 ;
* V_56 = 0 ;
memcpy ( V_57 , V_54 , 4 ) ;
memcpy ( V_57 + 4 , V_40 , 4 ) ;
V_43 = F_15 ( ( T_2 * ) & V_57 , 8 ,
& V_55 ) ;
if ( V_43 ) {
* V_56 = V_55 - 4 ;
}
return V_43 ;
}
T_2 F_15 ( T_2 * V_40 , T_1 V_42 , T_1 * V_56 )
{
T_1 V_8 ;
T_2 V_43 = 0 ;
if ( V_42 < 4 ) {
* V_56 = V_42 ;
return 0 ;
}
for ( V_8 = 0 ; V_8 < ( V_42 - 3 ) ; V_8 ++ ) {
if ( ( V_40 [ V_8 ] == 0xFF ) &&
( V_40 [ V_8 + 1 ] == 0x00 ) && ( V_40 [ V_8 + 2 ] == 0x00 ) ) {
* V_56 = V_8 + 4 ;
V_43 = V_40 [ V_8 + 3 ] ;
return V_43 ;
}
}
* V_56 = V_42 ;
return 0 ;
}
T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 V_43 ,
T_2 * V_40 , T_1 V_42 )
{
T_1 V_58 = 0 ;
int V_59 = - 1 ;
switch ( V_43 ) {
case V_60 :
if ( ( V_42 > 3 ) && ( V_40 [ 0 ] == 0xFF ) &&
( V_40 [ 1 ] == 0x00 ) && ( V_40 [ 2 ] == 0x00 ) &&
( ( V_40 [ 3 ] == V_61 ) ||
( V_40 [ 3 ] == V_62 ) ||
( V_40 [ 3 ] == V_63 ) ||
( V_40 [ 3 ] == V_64 ) ) )
return V_58 ;
V_59 = 1 ;
break;
case V_65 :
if ( ( V_42 > 3 ) && ( V_40 [ 0 ] == 0xFF ) &&
( V_40 [ 1 ] == 0x00 ) && ( V_40 [ 2 ] == 0x00 ) &&
( ( V_40 [ 3 ] == V_61 ) ||
( V_40 [ 3 ] == V_62 ) ||
( V_40 [ 3 ] == V_63 ) ||
( V_40 [ 3 ] == V_64 ) ) )
return V_58 ;
V_59 = 2 ;
break;
}
V_4 -> V_53 = V_43 ;
V_58 = F_17 ( V_2 , V_4 , V_40 ,
V_42 , V_59 ) ;
return V_58 ;
}
T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_2 * V_66 ,
T_1 V_67 , int V_68 )
{
T_1 V_69 ;
struct V_5 * V_6 ;
T_1 V_70 = V_2 -> V_71 * 2 ;
if ( V_4 -> V_59 != V_68 )
F_18 ( V_2 , V_4 ) ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
V_4 -> V_59 = V_68 ;
V_69 = V_4 -> V_72 ;
if ( V_69 > V_67 )
V_69 = V_67 ;
if ( V_4 -> V_73 >= V_4 -> V_74 ) {
V_4 -> V_72 -= V_69 ;
V_4 -> V_52 = ( V_4 -> V_72 == 0 ) ?
0 : 1 ;
return 0 ;
}
V_4 -> V_52 = 1 ;
if ( ! V_6 ) {
V_4 -> V_72 -= V_69 ;
V_4 -> V_52 = ( V_4 -> V_72 == 0 )
? 0 : 1 ;
return V_69 ;
}
F_19 ( V_2 , V_4 , V_66 , V_69 ) ;
V_4 -> V_75 += V_69 ;
V_4 -> V_72 -= V_69 ;
if ( V_4 -> V_72 == 0 ) {
V_4 -> V_72 = V_70 ;
V_4 -> V_73 ++ ;
V_4 -> V_52 = 0 ;
if ( F_20 ( V_2 , V_4 ) && V_6 ) {
F_1 ( V_2 , V_4 , V_6 ) ;
V_4 -> V_75 = 0 ;
V_6 = NULL ;
V_4 -> V_73 = 0 ;
}
}
return V_69 ;
}
void F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
if ( V_4 -> V_59 == 1 ) {
if ( V_4 -> V_73 >= V_4 -> V_74 )
V_4 -> V_76 = 1 ;
else
V_4 -> V_76 = 0 ;
}
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 == NULL ) {
T_2 * V_33 = NULL ;
F_7 ( V_4 , & V_6 ) ;
if ( V_6 )
V_33 = F_11 ( & V_6 -> V_7 ) ;
V_4 -> V_75 = 0 ;
V_4 -> V_76 = 0 ;
V_4 -> V_59 = - 1 ;
}
V_4 -> V_72 = V_2 -> V_71 << 1 ;
V_4 -> V_73 = 0 ;
}
int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_2 * V_40 , T_1 V_69 )
{
T_2 * V_77 = NULL ;
T_1 V_78 = 0 ;
struct V_5 * V_6 ;
T_1 V_70 = V_2 -> V_71 << 1 ;
void * V_79 ;
int V_51 , V_80 ;
if ( V_2 -> V_13 )
V_6 = V_2 -> V_14 . V_15 . V_6 ;
else
V_6 = V_2 -> V_14 . V_16 . V_6 ;
if ( V_6 == NULL )
return - 1 ;
V_77 = F_11 ( & V_6 -> V_7 ) ;
V_78 = V_70 - V_4 -> V_72 ;
V_51 = ( V_4 -> V_59 == 1 ) ? 0 : V_70 ;
V_79 = V_77 + V_51 ;
V_79 += ( V_4 -> V_73 * V_70 * 2 ) ;
V_79 += V_78 ;
V_80 = V_4 -> V_72 > V_69 ?
V_69 : V_4 -> V_72 ;
if ( ( T_2 * ) ( V_79 + V_80 ) > ( T_2 * ) ( V_77 + V_6 -> V_7 . V_36 ) )
return 0 ;
F_21 ( ( V_81 * ) V_40 , ( V_81 * ) V_79 , ( V_81 ) V_80 ) ;
return 0 ;
}
void F_21 ( V_81 * V_82 , V_81 * V_83 , V_81 V_84 )
{
V_81 V_8 ;
if ( V_84 <= 0 )
return;
for ( V_8 = 0 ; V_8 < V_84 / 2 ; V_8 ++ )
V_83 [ V_8 ] = ( V_82 [ V_8 ] << 8 ) | ( V_82 [ V_8 ] >> 8 ) ;
}
T_2 F_20 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_2 V_85 = 0 ;
V_85 = ( ( V_4 -> V_59 == 2 ) &&
( V_4 -> V_73 >= V_4 -> V_74 ) &&
V_4 -> V_76 ) ;
return V_85 ;
}
static int
F_22 ( struct V_86 * V_87 , unsigned int * V_88 , unsigned int * V_36 )
{
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_1 * V_2 = V_90 -> V_2 ;
* V_36 = ( V_90 -> V_2 -> V_71 * V_90 -> V_2 -> V_92 * V_2 -> V_93 -> V_94 + 7 ) >> 3 ;
if ( 0 == * V_88 )
* V_88 = V_95 ;
if ( * V_88 < V_96 )
* V_88 = V_96 ;
return 0 ;
}
static void F_23 ( struct V_86 * V_87 , struct V_5 * V_6 )
{
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_1 * V_2 = V_90 -> V_2 ;
unsigned long V_97 = 0 ;
if ( F_24 () )
F_25 () ;
F_26 ( & V_2 -> V_14 . V_98 , V_97 ) ;
if ( V_2 -> V_13 ) {
if ( V_2 -> V_14 . V_15 . V_6 == V_6 )
V_2 -> V_14 . V_15 . V_6 = NULL ;
} else {
if ( V_2 -> V_14 . V_16 . V_6 == V_6 )
V_2 -> V_14 . V_16 . V_6 = NULL ;
}
F_27 ( & V_2 -> V_14 . V_98 , V_97 ) ;
F_28 ( & V_6 -> V_7 ) ;
V_6 -> V_7 . V_9 = V_99 ;
}
static int
F_29 ( struct V_86 * V_87 , struct V_100 * V_7 ,
enum V_101 V_102 )
{
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 = 0 , V_103 = 0 ;
V_6 -> V_7 . V_36 = ( V_90 -> V_2 -> V_71 * V_90 -> V_2 -> V_92 * V_2 -> V_93 -> V_94
+ 7 ) >> 3 ;
if ( 0 != V_6 -> V_7 . V_104 && V_6 -> V_7 . V_105 < V_6 -> V_7 . V_36 )
return - V_106 ;
V_6 -> V_7 . V_71 = V_2 -> V_71 ;
V_6 -> V_7 . V_92 = V_2 -> V_92 ;
V_6 -> V_7 . V_102 = V_102 ;
if ( V_99 == V_6 -> V_7 . V_9 ) {
V_39 = F_30 ( V_87 , & V_6 -> V_7 , NULL ) ;
if ( V_39 < 0 )
goto V_107;
}
if ( V_2 -> V_13 ) {
if ( ! V_2 -> V_14 . V_15 . V_108 )
V_103 = 1 ;
} else {
if ( ! V_2 -> V_14 . V_16 . V_108 )
V_103 = 1 ;
}
if ( V_103 ) {
V_2 -> V_109 = 0 ;
if ( V_2 -> V_13 )
V_39 = F_31 ( V_2 , V_110 ,
V_111 ,
V_2 -> V_14 . V_49 ,
F_12 ) ;
else
V_39 = F_32 ( V_2 , V_110 ,
V_111 ,
V_2 -> V_14 . V_49 ,
F_16 ) ;
if ( V_39 < 0 )
goto V_107;
}
V_6 -> V_7 . V_9 = V_112 ;
return 0 ;
V_107:
F_23 ( V_87 , V_6 ) ;
return V_39 ;
}
static void F_33 ( struct V_86 * V_87 , struct V_100 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_3 * V_32 = & V_2 -> V_14 . V_32 ;
V_6 -> V_7 . V_9 = V_113 ;
F_34 ( & V_6 -> V_7 . V_17 , & V_32 -> V_34 ) ;
}
static void F_35 ( struct V_86 * V_87 ,
struct V_100 * V_7 )
{
struct V_5 * V_6 =
F_8 ( V_7 , struct V_5 , V_7 ) ;
struct V_89 * V_90 = V_87 -> V_91 ;
struct V_1 * V_2 = (struct V_1 * ) V_90 -> V_2 ;
F_2 ( L_15 ) ;
F_23 ( V_87 , V_6 ) ;
}
void F_36 ( struct V_1 * V_2 , int V_114 )
{
V_2 -> V_115 = V_114 ;
V_2 -> V_116 = F_37 ( V_114 ) -> V_117 ;
F_38 ( V_2 , V_114 ) ;
F_39 ( V_2 , V_118 , V_119 , F_37 ( V_114 ) -> V_120 , 0 , 0 ) ;
F_40 ( V_2 , V_2 -> V_116 ) ;
F_41 ( L_16 , V_114 ) ;
F_42 ( V_2 ) ;
}
static int F_43 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 = 0 ;
if ( V_90 -> V_121 )
return V_39 ;
if ( V_90 -> type == V_122 ) {
if ( V_2 -> V_121 )
return - V_123 ;
V_2 -> V_121 = 1 ;
} else if ( V_90 -> type == V_124 ) {
if ( V_2 -> V_125 )
return - V_123 ;
V_2 -> V_125 = 1 ;
} else
return - V_106 ;
V_90 -> V_121 = 1 ;
return V_39 ;
}
static int F_44 ( struct V_89 * V_90 )
{
return V_90 -> V_121 ;
}
static void F_45 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = V_90 -> V_2 ;
V_90 -> V_121 = 0 ;
if ( V_90 -> type == V_122 )
V_2 -> V_121 = 0 ;
if ( V_90 -> type == V_124 )
V_2 -> V_125 = 0 ;
}
static int F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 & V_44 ) {
F_47 ( L_17 ) ;
return - V_126 ;
}
if ( V_2 -> V_9 & V_45 ) {
F_47 ( L_18
L_19 ) ;
return - V_127 ;
}
return 0 ;
}
static int F_48 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
V_131 -> V_132 . V_133 . V_71 = V_2 -> V_71 ;
V_131 -> V_132 . V_133 . V_92 = V_2 -> V_92 ;
V_131 -> V_132 . V_133 . V_134 = V_2 -> V_93 -> V_135 ;
V_131 -> V_132 . V_133 . V_136 = ( V_2 -> V_71 * V_2 -> V_93 -> V_94 + 7 ) >> 3 ;
V_131 -> V_132 . V_133 . V_137 = V_131 -> V_132 . V_133 . V_136 * V_2 -> V_92 ;
V_131 -> V_132 . V_133 . V_138 = V_139 ;
V_131 -> V_132 . V_133 . V_102 = V_140 ;
return 0 ;
}
static struct V_141 * F_49 ( unsigned int V_135 )
{
unsigned int V_8 ;
for ( V_8 = 0 ; V_8 < F_50 ( V_93 ) ; V_8 ++ )
if ( V_93 [ V_8 ] . V_135 == V_135 )
return & V_93 [ V_8 ] ;
return NULL ;
}
static int F_51 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
unsigned int V_71 = V_131 -> V_132 . V_133 . V_71 ;
unsigned int V_92 = V_131 -> V_132 . V_133 . V_92 ;
unsigned int V_142 = F_52 ( V_2 ) ;
unsigned int V_143 = F_53 ( V_2 ) ;
struct V_141 * V_132 ;
V_132 = F_49 ( V_131 -> V_132 . V_133 . V_134 ) ;
if ( ! V_132 ) {
F_54 ( L_20 ,
V_131 -> V_132 . V_133 . V_134 ) ;
return - V_106 ;
}
F_55 ( & V_71 , 48 , V_142 , 1 , & V_92 , 32 , V_143 , 1 , 0 ) ;
V_131 -> V_132 . V_133 . V_71 = V_71 ;
V_131 -> V_132 . V_133 . V_92 = V_92 ;
V_131 -> V_132 . V_133 . V_134 = V_132 -> V_135 ;
V_131 -> V_132 . V_133 . V_136 = ( V_2 -> V_71 * V_132 -> V_94 + 7 ) >> 3 ;
V_131 -> V_132 . V_133 . V_137 = V_131 -> V_132 . V_133 . V_136 * V_92 ;
V_131 -> V_132 . V_133 . V_138 = V_139 ;
V_131 -> V_132 . V_133 . V_102 = V_140 ;
return 0 ;
}
static int F_56 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
struct V_141 * V_132 ;
struct V_144 V_145 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_51 ( V_128 , V_129 , V_131 ) ;
V_132 = F_49 ( V_131 -> V_132 . V_133 . V_134 ) ;
if ( ! V_132 )
return - V_106 ;
if ( F_57 ( & V_90 -> V_146 ) ) {
F_47 ( L_21 , V_147 ) ;
return - V_123 ;
}
if ( V_2 -> V_121 && ! V_90 -> V_121 ) {
F_47 ( L_22 , V_147 ) ;
return - V_123 ;
}
V_2 -> V_71 = V_131 -> V_132 . V_133 . V_71 ;
V_2 -> V_92 = V_131 -> V_132 . V_133 . V_92 ;
V_2 -> V_93 = V_132 ;
F_58 ( & V_145 , & V_131 -> V_132 . V_133 , V_148 ) ;
F_59 ( V_2 , V_118 , V_149 , & V_145 ) ;
F_60 ( & V_131 -> V_132 . V_133 , & V_145 ) ;
return V_39 ;
}
static int F_61 ( struct V_128 * V_128 , void * V_129 , T_3 * V_150 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
* V_150 = V_2 -> V_151 ;
return 0 ;
}
static int F_62 ( struct V_128 * V_128 , void * V_129 , T_3 * V_151 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
struct V_144 V_145 ;
struct V_130 V_131 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_41 ( L_23 , ( unsigned int ) * V_151 ) ;
V_2 -> V_151 = * V_151 ;
V_131 . V_132 . V_133 . V_71 = V_2 -> V_71 ;
V_131 . V_132 . V_133 . V_92 = V_2 -> V_92 ;
F_51 ( V_128 , V_129 , & V_131 ) ;
F_59 ( V_2 , V_152 , V_153 , V_2 -> V_151 ) ;
F_58 ( & V_145 , & V_131 . V_132 . V_133 , V_148 ) ;
F_59 ( V_2 , V_118 , V_149 , & V_145 ) ;
F_60 ( & V_131 . V_132 . V_133 , & V_145 ) ;
V_2 -> V_71 = V_131 . V_132 . V_133 . V_71 ;
V_2 -> V_92 = V_131 . V_132 . V_133 . V_92 ;
F_42 ( V_2 ) ;
return 0 ;
}
static int F_63 ( struct V_128 * V_128 , void * V_129 ,
struct V_154 * V_8 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
unsigned int V_155 ;
V_155 = V_8 -> V_114 ;
if ( V_155 >= V_156 )
return - V_106 ;
if ( 0 == F_37 ( V_155 ) -> type )
return - V_106 ;
V_8 -> V_114 = V_155 ;
V_8 -> type = V_157 ;
strcpy ( V_8 -> V_158 , V_159 [ F_37 ( V_155 ) -> type ] ) ;
if ( ( V_160 == F_37 ( V_155 ) -> type ) ||
( V_161 == F_37 ( V_155 ) -> type ) )
V_8 -> type = V_162 ;
V_8 -> V_163 = V_2 -> V_164 -> V_165 ;
return 0 ;
}
static int F_64 ( struct V_128 * V_128 , void * V_129 , unsigned int * V_8 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
* V_8 = V_2 -> V_115 ;
return 0 ;
}
static int F_65 ( struct V_128 * V_128 , void * V_129 , unsigned int V_8 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_2 -> V_109 = 0 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_8 >= V_156 )
return - V_106 ;
if ( 0 == F_37 ( V_8 ) -> type )
return - V_106 ;
F_36 ( V_2 , V_8 ) ;
if ( F_37 ( V_8 ) -> type == V_160 ||
F_37 ( V_8 ) -> type == V_161 ) {
F_59 ( V_2 , V_152 , V_153 , V_2 -> V_151 ) ;
}
return 0 ;
}
static int F_66 ( struct V_128 * V_128 , void * V_129 , struct V_166 * V_167 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
switch ( V_167 -> V_114 ) {
case V_168 :
strcpy ( V_167 -> V_158 , L_24 ) ;
break;
case V_169 :
strcpy ( V_167 -> V_158 , L_25 ) ;
break;
default:
return - V_106 ;
}
V_167 -> V_114 = V_2 -> V_116 ;
V_167 -> V_170 = V_171 ;
return 0 ;
}
static int F_67 ( struct V_128 * V_128 , void * V_129 , struct V_166 * V_167 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_20 = 0 ;
if ( V_167 -> V_114 != V_2 -> V_116 )
return - V_106 ;
V_2 -> V_116 = F_37 ( V_167 -> V_114 ) -> V_117 ;
V_20 = F_40 ( V_2 , V_2 -> V_116 ) ;
return V_20 ;
}
static int F_68 ( struct V_128 * V_128 , void * V_129 ,
struct V_172 * V_173 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_150 = V_173 -> V_150 ;
int V_8 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_173 -> V_150 = F_69 ( V_174 , V_173 -> V_150 ) ;
if ( F_70 ( V_173 -> V_150 == 0 ) )
return - V_106 ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_150 = V_150 ;
if ( V_173 -> V_150 < V_175 || V_173 -> V_150 >= V_176 )
return - V_106 ;
for ( V_8 = 0 ; V_8 < V_177 ; V_8 ++ )
if ( V_178 [ V_8 ] . V_179 . V_150 == V_173 -> V_150 )
break;
if ( V_8 == V_177 ) {
* V_173 = V_180 ;
return 0 ;
}
* V_173 = V_178 [ V_8 ] . V_179 ;
F_59 ( V_2 , V_152 , V_181 , V_173 ) ;
if ( V_173 -> type )
return 0 ;
else
return - V_106 ;
}
static int F_71 ( struct V_128 * V_128 , void * V_129 ,
struct V_182 * V_183 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_152 , V_184 , V_183 ) ;
return V_39 ;
}
static int F_72 ( struct V_128 * V_128 , void * V_129 ,
struct V_182 * V_183 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_152 , V_185 , V_183 ) ;
return V_39 ;
}
static int F_73 ( struct V_128 * V_128 , void * V_129 , struct V_186 * V_187 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_187 -> V_114 )
return - V_106 ;
strcpy ( V_187 -> V_158 , L_26 ) ;
V_187 -> type = V_188 ;
V_187 -> V_170 = V_189 ;
V_187 -> V_190 = 0xffffffffUL ;
V_187 -> signal = 0xffff ;
return 0 ;
}
static int F_74 ( struct V_128 * V_128 , void * V_129 , struct V_186 * V_187 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_187 -> V_114 )
return - V_106 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
static int F_75 ( struct V_128 * V_128 , void * V_129 ,
struct V_191 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
V_131 -> type = V_90 -> V_192 ? V_193 : V_188 ;
V_131 -> V_194 = V_2 -> V_195 ;
F_59 ( V_2 , V_196 , V_197 , V_131 ) ;
return 0 ;
}
static int F_76 ( struct V_128 * V_128 , void * V_129 ,
struct V_191 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
T_1 V_198 = 5400000 ;
F_41 ( L_27 ,
V_131 -> V_194 , V_131 -> type ) ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_131 -> V_196 )
return - V_106 ;
if ( F_70 ( 0 == V_90 -> V_192 && V_131 -> type != V_188 ) )
return - V_106 ;
if ( F_70 ( 1 == V_90 -> V_192 && V_131 -> type != V_193 ) )
return - V_106 ;
V_39 = F_77 ( V_2 ) ;
V_2 -> V_195 = V_131 -> V_194 ;
F_59 ( V_2 , V_196 , V_199 , V_131 ) ;
V_39 = F_78 ( V_2 ) ;
if ( V_2 -> V_200 == V_201 ) {
if ( V_2 -> V_151 & ( V_202 | V_203 ) )
V_198 = 5400000 ;
else if ( V_2 -> V_151 & V_204 )
V_198 = 6000000 ;
else if ( V_2 -> V_151 & ( V_205 | V_206 ) )
V_198 = 6900000 ;
else if ( V_2 -> V_151 & V_207 )
V_198 = 7100000 ;
else if ( V_2 -> V_151 & V_208 )
V_198 = 7250000 ;
else if ( V_2 -> V_151 & V_209 )
V_198 = 6900000 ;
else if ( V_2 -> V_151 & V_210 )
V_198 = 1250000 ;
F_41 ( L_28 , V_198 ) ;
F_79 ( V_2 , V_198 , 1 , 1 ) ;
F_80 ( V_2 ) ;
}
F_41 ( L_29 , V_131 -> V_194 ) ;
return V_39 ;
}
static int F_81 ( struct V_128 * V_128 , void * V_129 ,
struct V_211 * V_212 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_213 = 0 ;
T_2 V_214 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_215 = 0 ;
switch ( V_212 -> V_216 . type ) {
case V_217 :
switch ( V_212 -> V_216 . V_218 ) {
case 0 :
V_213 = F_82 ( V_2 , V_219 ,
( V_81 ) V_212 -> V_212 , V_214 , 4 ) ;
V_212 -> V_220 = V_214 [ 0 ] | V_214 [ 1 ] << 8 |
V_214 [ 2 ] << 16 | V_214 [ 3 ] << 24 ;
break;
case 1 :
V_213 = F_83 ( V_2 , V_221 ,
( V_81 ) V_212 -> V_212 , 2 , & V_215 , 1 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 14 :
V_213 = F_83 ( V_2 , V_221 ,
( V_81 ) V_212 -> V_212 , 2 , & V_215 , 4 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
break;
case 2 :
V_213 = F_83 ( V_2 , V_222 ,
( V_81 ) V_212 -> V_212 , 2 , & V_215 , 1 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 24 :
V_213 = F_83 ( V_2 , V_222 ,
( V_81 ) V_212 -> V_212 , 2 , & V_215 , 4 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
break;
case 3 :
V_213 = F_83 ( V_2 ,
V_223 ,
( V_81 ) V_212 -> V_212 , 1 ,
& V_215 , 1 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 34 :
V_213 =
F_83 ( V_2 , V_223 ,
( V_81 ) V_212 -> V_212 , 1 , & V_215 , 4 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
break;
}
return V_213 < 0 ? V_213 : 0 ;
case V_224 :
F_59 ( V_2 , V_152 , V_225 , V_212 ) ;
return 0 ;
case V_226 :
switch ( V_212 -> V_216 . V_218 ) {
case 0 :
V_213 = F_82 ( V_2 , V_219 ,
( V_81 ) V_212 -> V_212 , V_214 , 4 ) ;
V_212 -> V_220 = V_214 [ 0 ] | V_214 [ 1 ] << 8 |
V_214 [ 2 ] << 16 | V_214 [ 3 ] << 24 ;
break;
case 0x600 :
V_213 = F_85 ( V_2 , V_221 ,
( V_81 ) V_212 -> V_212 , 2 ,
& V_215 , 1 , 0 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 0x880 :
if ( V_212 -> V_212 < 0x0b ) {
V_213 = F_85 ( V_2 ,
V_222 ,
( V_81 ) V_212 -> V_212 , 2 ,
& V_215 , 1 , 0 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
} else {
V_213 = F_85 ( V_2 ,
V_222 ,
( V_81 ) V_212 -> V_212 , 2 ,
& V_215 , 4 , 0 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
}
break;
case 0x980 :
V_213 = F_85 ( V_2 ,
V_223 ,
( V_81 ) V_212 -> V_212 , 1 ,
& V_215 , 1 , 0 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 0x400 :
V_213 =
F_85 ( V_2 , 0x40 ,
( V_81 ) V_212 -> V_212 , 1 ,
& V_215 , 1 , 0 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 0xc01 :
V_213 =
F_85 ( V_2 , 0xc0 ,
( V_81 ) V_212 -> V_212 , 2 ,
& V_215 , 38 , 1 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
break;
case 0x022 :
V_213 =
F_85 ( V_2 , 0x02 ,
( V_81 ) V_212 -> V_212 , 1 ,
& V_215 , 1 , 2 ) ;
V_212 -> V_220 = F_84 ( V_215 & 0xff ) ;
break;
case 0x322 :
V_213 = F_85 ( V_2 ,
0x32 ,
( V_81 ) V_212 -> V_212 , 1 ,
& V_215 , 4 , 2 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
break;
case 0x342 :
V_213 = F_85 ( V_2 ,
0x34 ,
( V_81 ) V_212 -> V_212 , 1 ,
& V_215 , 4 , 2 ) ;
V_212 -> V_220 = F_84 ( V_215 ) ;
break;
default:
F_41 ( L_30 ) ;
break;
}
return V_213 < 0 ? V_213 : 0 ;
default:
if ( ! F_86 ( & V_212 -> V_216 ) )
return - V_106 ;
}
F_59 ( V_2 , V_152 , V_225 , V_212 ) ;
return V_213 ;
}
static int F_87 ( struct V_128 * V_128 , void * V_129 ,
struct V_211 * V_212 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_213 = 0 ;
T_4 V_6 ;
T_1 V_214 ;
T_2 V_215 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_6 = F_88 ( V_212 -> V_220 ) ;
switch ( V_212 -> V_216 . type ) {
case V_217 :
{
V_214 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_212 -> V_216 . V_218 ) {
case 0 :
V_215 [ 0 ] = ( T_2 ) V_214 ;
V_215 [ 1 ] = ( T_2 ) ( V_214 >> 8 ) ;
V_215 [ 2 ] = ( T_2 ) ( V_214 >> 16 ) ;
V_215 [ 3 ] = ( T_2 ) ( V_214 >> 24 ) ;
V_213 = F_89 ( V_2 ,
V_227 ,
( V_81 ) V_212 -> V_212 , V_215 ,
4 ) ;
break;
case 1 :
V_213 = F_90 ( V_2 ,
V_221 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 1 ) ;
break;
case 14 :
V_213 = F_90 ( V_2 ,
V_221 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 4 ) ;
break;
case 2 :
V_213 =
F_90 ( V_2 ,
V_222 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 1 ) ;
break;
case 24 :
V_213 =
F_90 ( V_2 ,
V_222 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 4 ) ;
break;
case 3 :
V_213 =
F_90 ( V_2 ,
V_223 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 1 ) ;
break;
case 34 :
V_213 =
F_90 ( V_2 ,
V_223 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 4 ) ;
break;
}
}
return V_213 < 0 ? V_213 : 0 ;
case V_226 :
{
V_214 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_212 -> V_216 . V_218 ) {
case 0 :
V_215 [ 0 ] = ( T_2 ) V_214 ;
V_215 [ 1 ] = ( T_2 ) ( V_214 >> 8 ) ;
V_215 [ 2 ] = ( T_2 ) ( V_214 >> 16 ) ;
V_215 [ 3 ] = ( T_2 ) ( V_214 >> 24 ) ;
V_213 = F_89 ( V_2 ,
V_227 ,
( V_81 ) V_212 -> V_212 , V_215 ,
4 ) ;
break;
case 0x600 :
V_213 = F_91 ( V_2 ,
V_221 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 1 , 0 ) ;
break;
case 0x880 :
if ( V_212 -> V_212 < 0x0b )
F_91 ( V_2 ,
V_222 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 1 , 0 ) ;
else
F_91 ( V_2 ,
V_222 ,
( V_81 ) V_212 -> V_212 , 2 ,
V_214 , 4 , 0 ) ;
break;
case 0x980 :
V_213 =
F_91 ( V_2 ,
V_223 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 1 , 0 ) ;
break;
case 0x400 :
V_213 =
F_91 ( V_2 ,
0x40 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 1 , 0 ) ;
break;
case 0xc01 :
V_213 =
F_91 ( V_2 ,
0xc0 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 1 , 1 ) ;
break;
case 0x022 :
V_213 =
F_91 ( V_2 ,
0x02 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 1 , 2 ) ;
case 0x322 :
V_213 =
F_91 ( V_2 ,
0x32 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 4 , 2 ) ;
break;
case 0x342 :
V_213 =
F_91 ( V_2 ,
0x34 ,
( V_81 ) V_212 -> V_212 , 1 ,
V_214 , 4 , 2 ) ;
break;
default:
F_41 ( L_31
L_32 , V_212 -> V_216 . V_218 ) ;
break;
}
}
default:
break;
}
F_59 ( V_2 , V_152 , V_228 , V_212 ) ;
return V_213 ;
}
static int F_92 ( struct V_128 * V_128 , void * V_129 ,
struct V_229 * V_230 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
if ( V_230 -> type != V_122 )
return - V_106 ;
V_230 -> V_231 . V_232 = 0 ;
V_230 -> V_231 . V_233 = 0 ;
V_230 -> V_231 . V_71 = V_2 -> V_71 ;
V_230 -> V_231 . V_92 = V_2 -> V_92 ;
V_230 -> V_234 = V_230 -> V_231 ;
V_230 -> V_235 . V_236 = 54 ;
V_230 -> V_235 . V_237 = 59 ;
return 0 ;
}
static int F_93 ( struct V_128 * V_128 , void * V_129 ,
enum V_238 type )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_90 ) ;
if ( F_94 ( V_39 >= 0 ) )
V_39 = F_95 ( & V_90 -> V_146 ) ;
F_59 ( V_2 , V_118 , V_239 , 1 ) ;
return V_39 ;
}
static int F_96 ( struct V_128 * V_128 , void * V_129 ,
enum V_238 type )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_90 -> type != V_122 ) &&
( V_90 -> type != V_124 ) )
return - V_106 ;
if ( type != V_90 -> type )
return - V_106 ;
F_39 ( V_2 , V_118 , V_239 , 0 ) ;
F_97 ( & V_90 -> V_146 ) ;
F_45 ( V_90 ) ;
return 0 ;
}
static int F_98 ( struct V_128 * V_128 , void * V_129 ,
struct V_240 * V_241 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
F_99 ( V_241 -> V_242 , L_33 , sizeof( V_241 -> V_242 ) ) ;
F_99 ( V_241 -> V_243 , V_244 [ V_2 -> V_245 ] . V_158 , sizeof( V_241 -> V_243 ) ) ;
F_100 ( V_2 -> V_246 , V_241 -> V_247 , sizeof( V_241 -> V_247 ) ) ;
V_241 -> V_248 = V_249 ;
V_241 -> V_250 = V_251 |
#if 0
V4L2_CAP_SLICED_VBI_CAPTURE |
#endif
V_252 |
V_253 |
V_254 |
V_255 ;
if ( V_2 -> V_200 != V_256 )
V_241 -> V_250 |= V_257 ;
return 0 ;
}
static int F_101 ( struct V_128 * V_128 , void * V_129 ,
struct V_258 * V_131 )
{
if ( F_70 ( V_131 -> V_114 >= F_50 ( V_93 ) ) )
return - V_106 ;
F_99 ( V_131 -> V_259 , V_93 [ V_131 -> V_114 ] . V_158 , sizeof( V_131 -> V_259 ) ) ;
V_131 -> V_134 = V_93 [ V_131 -> V_114 ] . V_135 ;
return 0 ;
}
static int F_102 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_131 -> V_132 . V_260 . V_261 = 0 ;
F_59 ( V_2 , V_262 , V_263 , & V_131 -> V_132 . V_260 ) ;
if ( V_131 -> V_132 . V_260 . V_261 == 0 )
V_39 = - V_106 ;
return V_39 ;
}
static int F_103 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_262 , V_263 , & V_131 -> V_132 . V_260 ) ;
if ( V_131 -> V_132 . V_260 . V_261 == 0 )
return - V_106 ;
return 0 ;
}
static int F_104 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
V_131 -> V_132 . V_262 . V_264 = 6750000 * 4 ;
V_131 -> V_132 . V_262 . V_265 = V_266 ;
V_131 -> V_132 . V_262 . V_267 = V_268 ;
V_131 -> V_132 . V_262 . V_51 = 0 ;
V_131 -> V_132 . V_262 . V_269 [ 0 ] = ( V_2 -> V_151 & V_270 ) ?
V_271 : V_272 ;
V_131 -> V_132 . V_262 . V_88 [ 0 ] = ( V_2 -> V_151 & V_270 ) ?
V_273 : V_274 ;
V_131 -> V_132 . V_262 . V_269 [ 1 ] = ( V_2 -> V_151 & V_270 ) ?
V_271 + 312 : V_272 + 263 ;
V_131 -> V_132 . V_262 . V_88 [ 1 ] = V_131 -> V_132 . V_262 . V_88 [ 0 ] ;
return 0 ;
}
static int F_105 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
if ( V_2 -> V_125 && ! V_90 -> V_121 ) {
F_47 ( L_22 , V_147 ) ;
return - V_123 ;
}
V_131 -> type = V_124 ;
V_131 -> V_132 . V_262 . V_264 = 6750000 * 4 ;
V_131 -> V_132 . V_262 . V_265 = V_266 ;
V_131 -> V_132 . V_262 . V_267 = V_268 ;
V_131 -> V_132 . V_262 . V_51 = 0 ;
V_131 -> V_132 . V_262 . V_97 = 0 ;
V_131 -> V_132 . V_262 . V_269 [ 0 ] = ( V_2 -> V_151 & V_270 ) ?
V_271 : V_272 ;
V_131 -> V_132 . V_262 . V_88 [ 0 ] = ( V_2 -> V_151 & V_270 ) ?
V_273 : V_274 ;
V_131 -> V_132 . V_262 . V_269 [ 1 ] = ( V_2 -> V_151 & V_270 ) ?
V_271 + 312 : V_272 + 263 ;
V_131 -> V_132 . V_262 . V_88 [ 1 ] = V_131 -> V_132 . V_262 . V_88 [ 0 ] ;
return 0 ;
}
static int F_106 ( struct V_128 * V_128 , void * V_129 ,
struct V_275 * V_276 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_107 ( & V_90 -> V_146 , V_276 ) ;
}
static int F_108 ( struct V_128 * V_128 , void * V_129 , struct V_277 * V_278 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_109 ( & V_90 -> V_146 , V_278 ) ;
}
static int F_110 ( struct V_128 * V_128 , void * V_129 , struct V_277 * V_278 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_111 ( & V_90 -> V_146 , V_278 ) ;
}
static int F_112 ( struct V_128 * V_128 , void * V_129 , struct V_277 * V_278 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_113 ( & V_90 -> V_146 , V_278 , V_128 -> V_279 & V_280 ) ;
}
static int F_114 ( struct V_128 * V_128 , void * V_129 ,
struct V_240 * V_241 )
{
struct V_1 * V_2 = ( (struct V_89 * ) V_129 ) -> V_2 ;
F_99 ( V_241 -> V_242 , L_33 , sizeof( V_241 -> V_242 ) ) ;
F_99 ( V_241 -> V_243 , V_244 [ V_2 -> V_245 ] . V_158 , sizeof( V_241 -> V_243 ) ) ;
F_100 ( V_2 -> V_246 , V_241 -> V_247 , sizeof( V_241 -> V_247 ) ) ;
V_241 -> V_248 = V_249 ;
V_241 -> V_250 = V_257 ;
return 0 ;
}
static int F_115 ( struct V_128 * V_128 , void * V_129 , struct V_186 * V_187 )
{
struct V_1 * V_2 = ( (struct V_89 * ) V_129 ) -> V_2 ;
if ( F_70 ( V_187 -> V_114 > 0 ) )
return - V_106 ;
strcpy ( V_187 -> V_158 , L_34 ) ;
V_187 -> type = V_193 ;
F_59 ( V_2 , V_196 , V_281 , V_187 ) ;
return 0 ;
}
static int F_116 ( struct V_128 * V_128 , void * V_129 , struct V_154 * V_8 )
{
if ( V_8 -> V_114 != 0 )
return - V_106 ;
strcpy ( V_8 -> V_158 , L_34 ) ;
V_8 -> type = V_162 ;
return 0 ;
}
static int F_117 ( struct V_128 * V_128 , void * V_129 , struct V_166 * V_167 )
{
if ( F_70 ( V_167 -> V_114 ) )
return - V_106 ;
strcpy ( V_167 -> V_158 , L_34 ) ;
return 0 ;
}
static int F_118 ( struct V_128 * V_128 , void * V_129 , struct V_186 * V_187 )
{
struct V_1 * V_2 = ( (struct V_89 * ) V_129 ) -> V_2 ;
if ( 0 != V_187 -> V_114 )
return - V_106 ;
F_59 ( V_2 , V_196 , V_281 , V_187 ) ;
return 0 ;
}
static int F_119 ( struct V_128 * V_128 , void * V_90 , struct V_166 * V_167 )
{
return 0 ;
}
static int F_120 ( struct V_128 * V_128 , void * V_90 , unsigned int V_8 )
{
return 0 ;
}
static int F_121 ( struct V_128 * V_128 , void * V_129 ,
struct V_172 * V_282 )
{
int V_8 ;
if ( V_282 -> V_150 < V_175 || V_282 -> V_150 >= V_176 )
return - V_106 ;
if ( V_282 -> V_150 == V_283 ) {
for ( V_8 = 0 ; V_8 < V_177 ; V_8 ++ ) {
if ( V_178 [ V_8 ] . V_179 . V_150 == V_282 -> V_150 )
break;
}
if ( V_8 == V_177 )
return - V_106 ;
* V_282 = V_178 [ V_8 ] . V_179 ;
} else
* V_282 = V_180 ;
return 0 ;
}
static int F_122 ( struct V_128 * V_284 )
{
int V_285 = 0 , V_192 = 0 ;
struct V_286 * V_164 = F_123 ( V_284 ) ;
struct V_1 * V_2 = F_124 ( V_284 ) ;
struct V_89 * V_90 ;
enum V_238 V_287 = 0 ;
switch ( V_164 -> V_288 ) {
case V_289 :
V_287 = V_122 ;
break;
case V_290 :
V_287 = V_124 ;
break;
case V_291 :
V_192 = 1 ;
break;
}
F_54 ( L_35 ,
F_125 ( V_164 ) , V_292 [ V_287 ] ,
V_2 -> V_293 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
cx231xx_errdev
("Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_90 = F_126 ( sizeof( struct V_89 ) , V_294 ) ;
if ( ! V_90 ) {
F_47 ( L_36 ) ;
return - V_295 ;
}
V_90 -> V_2 = V_2 ;
V_90 -> V_192 = V_192 ;
V_90 -> type = V_287 ;
V_284 -> V_296 = V_90 ;
if ( V_90 -> type == V_122 && V_2 -> V_293 == 0 ) {
V_2 -> V_71 = F_52 ( V_2 ) ;
V_2 -> V_92 = F_53 ( V_2 ) ;
if ( V_2 -> V_297 . V_298 )
F_127 ( V_2 ,
V_299 ) ;
else
F_127 ( V_2 , V_300 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> V_115 = V_2 -> V_115 > 2 ? 2 : V_2 -> V_115 ;
}
if ( V_90 -> V_192 ) {
F_54 ( L_37 ) ;
F_59 ( V_2 , V_196 , V_301 ) ;
}
V_2 -> V_293 ++ ;
if ( V_90 -> type == V_122 )
F_130 ( & V_90 -> V_146 , & V_302 ,
NULL , & V_2 -> V_14 . V_98 ,
V_90 -> type , V_140 ,
sizeof( struct V_5 ) ,
V_90 , & V_2 -> V_303 ) ;
if ( V_90 -> type == V_124 ) {
F_131 ( V_2 , V_304 , 0 ) ;
F_130 ( & V_90 -> V_146 , & V_305 ,
NULL , & V_2 -> V_306 . V_98 ,
V_90 -> type , V_307 ,
sizeof( struct V_5 ) ,
V_90 , & V_2 -> V_303 ) ;
}
return V_285 ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_308 ) {
if ( F_133 ( V_2 -> V_308 ) )
F_134 ( V_2 -> V_308 ) ;
else
F_135 ( V_2 -> V_308 ) ;
V_2 -> V_308 = NULL ;
}
if ( V_2 -> V_309 ) {
F_41 ( L_38 ,
F_125 ( V_2 -> V_309 ) ) ;
if ( F_133 ( V_2 -> V_309 ) )
F_134 ( V_2 -> V_309 ) ;
else
F_135 ( V_2 -> V_309 ) ;
V_2 -> V_309 = NULL ;
}
if ( V_2 -> V_164 ) {
F_41 ( L_38 ,
F_125 ( V_2 -> V_164 ) ) ;
if ( V_2 -> V_297 . V_310 )
F_136 ( V_2 ) ;
if ( F_133 ( V_2 -> V_164 ) )
F_134 ( V_2 -> V_164 ) ;
else
F_135 ( V_2 -> V_164 ) ;
V_2 -> V_164 = NULL ;
}
}
static int F_137 ( struct V_128 * V_284 )
{
struct V_89 * V_90 = V_284 -> V_296 ;
struct V_1 * V_2 = V_90 -> V_2 ;
F_54 ( L_39 , V_2 -> V_293 ) ;
F_54 ( L_39 , V_2 -> V_293 ) ;
if ( F_44 ( V_90 ) )
F_45 ( V_90 ) ;
if ( ! V_2 -> V_297 . V_311 )
if ( V_90 -> type == V_124 ) {
F_138 ( & V_90 -> V_146 ) ;
F_139 ( & V_90 -> V_146 ) ;
if ( V_2 -> V_9 & V_44 ) {
if ( F_140 ( & V_2 -> V_312 ) > 0 ) {
F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_143 ( V_2 ) ;
if ( ! V_2 -> V_313 )
F_131 ( V_2 , V_304 , 0 ) ;
else
F_131 ( V_2 , V_314 , 0 ) ;
F_142 ( V_90 ) ;
V_2 -> V_293 -- ;
F_144 ( & V_2 -> V_315 , 1 ) ;
return 0 ;
}
if ( V_2 -> V_293 == 1 ) {
F_138 ( & V_90 -> V_146 ) ;
F_139 ( & V_90 -> V_146 ) ;
if ( V_2 -> V_9 & V_44 ) {
F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
F_59 ( V_2 , V_152 , V_316 , 0 ) ;
if ( V_2 -> V_13 )
F_145 ( V_2 ) ;
else
F_146 ( V_2 ) ;
F_147 ( V_2 , V_317 ) ;
F_131 ( V_2 , V_318 , 0 ) ;
}
F_142 ( V_90 ) ;
V_2 -> V_293 -- ;
F_144 ( & V_2 -> V_315 , 1 ) ;
return 0 ;
}
static T_5
F_148 ( struct V_128 * V_284 , char T_6 * V_6 , T_7 V_88 ,
T_8 * V_75 )
{
struct V_89 * V_90 = V_284 -> V_296 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_90 -> type == V_122 ) ||
( V_90 -> type == V_124 ) ) {
V_39 = F_43 ( V_90 ) ;
if ( F_70 ( V_39 < 0 ) )
return V_39 ;
return F_149 ( & V_90 -> V_146 , V_6 , V_88 , V_75 , 0 ,
V_284 -> V_279 & V_280 ) ;
}
return 0 ;
}
static unsigned int F_150 ( struct V_128 * V_284 , T_9 * V_319 )
{
struct V_89 * V_90 = V_284 -> V_296 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_90 ) ;
if ( F_70 ( V_39 < 0 ) )
return V_320 ;
if ( ( V_122 == V_90 -> type ) ||
( V_124 == V_90 -> type ) )
return F_151 ( V_284 , & V_90 -> V_146 , V_319 ) ;
else
return V_320 ;
}
static int F_152 ( struct V_128 * V_284 , struct V_321 * V_322 )
{
struct V_89 * V_90 = V_284 -> V_296 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_90 ) ;
if ( F_70 ( V_39 < 0 ) )
return V_39 ;
V_39 = F_153 ( & V_90 -> V_146 , V_322 ) ;
F_54 ( L_40 ,
( unsigned long ) V_322 -> V_323 ,
( unsigned long ) V_322 -> V_324 -
( unsigned long ) V_322 -> V_323 , V_39 ) ;
return V_39 ;
}
static struct V_286 * F_154 ( struct V_1 * V_2 ,
const struct V_286
* V_325 , const char * V_326 )
{
struct V_286 * V_327 ;
V_327 = F_155 () ;
if ( NULL == V_327 )
return NULL ;
* V_327 = * V_325 ;
V_327 -> V_328 = & V_2 -> V_328 ;
V_327 -> V_329 = F_135 ;
V_327 -> V_330 = V_331 ;
V_327 -> V_303 = & V_2 -> V_303 ;
snprintf ( V_327 -> V_158 , sizeof( V_327 -> V_158 ) , L_41 , V_2 -> V_158 , V_326 ) ;
F_156 ( V_327 , V_2 ) ;
return V_327 ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_213 ;
F_41 ( L_42 ,
V_2 -> V_158 ,
( V_249 >> 16 ) & 0xff ,
( V_249 >> 8 ) & 0xff ,
V_249 & 0xff ) ;
V_2 -> V_71 = F_52 ( V_2 ) ;
V_2 -> V_92 = F_53 ( V_2 ) ;
V_2 -> V_332 = 0 ;
V_2 -> V_93 = & V_93 [ 0 ] ;
F_36 ( V_2 , V_2 -> V_115 ) ;
V_2 -> V_333 = 1 ;
V_2 -> V_334 = 0x1f ;
V_2 -> V_164 = F_154 ( V_2 , & V_335 , L_43 ) ;
if ( ! V_2 -> V_164 ) {
F_47 ( L_44 ) ;
return - V_126 ;
}
V_213 = F_158 ( V_2 -> V_164 , V_289 ,
V_336 [ V_2 -> V_337 ] ) ;
if ( V_213 ) {
F_47 ( L_45 ,
V_213 ) ;
return V_213 ;
}
F_41 ( L_46 ,
V_2 -> V_158 , F_125 ( V_2 -> V_164 ) ) ;
memcpy ( & V_338 , & V_335 ,
sizeof( V_338 ) ) ;
strcpy ( V_338 . V_158 , L_47 ) ;
V_2 -> V_309 = F_154 ( V_2 , & V_338 , L_48 ) ;
V_213 = F_158 ( V_2 -> V_309 , V_290 ,
V_339 [ V_2 -> V_337 ] ) ;
if ( V_213 < 0 ) {
F_47 ( L_49 ) ;
return V_213 ;
}
F_41 ( L_50 ,
V_2 -> V_158 , F_125 ( V_2 -> V_309 ) ) ;
if ( V_244 [ V_2 -> V_245 ] . V_192 . type == V_340 ) {
V_2 -> V_308 = F_154 ( V_2 , & V_341 ,
L_51 ) ;
if ( ! V_2 -> V_308 ) {
F_47 ( L_44 ) ;
return - V_126 ;
}
V_213 = F_158 ( V_2 -> V_308 , V_291 ,
V_342 [ V_2 -> V_337 ] ) ;
if ( V_213 < 0 ) {
F_47 ( L_52 ) ;
return V_213 ;
}
F_41 ( L_53 ,
F_125 ( V_2 -> V_308 ) ) ;
}
F_41 ( L_54 ,
F_125 ( V_2 -> V_164 ) ,
F_125 ( V_2 -> V_309 ) ) ;
return 0 ;
}
