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
T_1 V_155 ;
unsigned int V_156 , V_157 ;
V_157 = V_8 -> V_114 ;
if ( V_157 >= V_158 )
return - V_106 ;
if ( 0 == F_37 ( V_157 ) -> type )
return - V_106 ;
V_8 -> V_114 = V_157 ;
V_8 -> type = V_159 ;
strcpy ( V_8 -> V_160 , V_161 [ F_37 ( V_157 ) -> type ] ) ;
if ( ( V_162 == F_37 ( V_157 ) -> type ) ||
( V_163 == F_37 ( V_157 ) -> type ) )
V_8 -> type = V_164 ;
V_8 -> V_165 = V_2 -> V_166 -> V_167 ;
if ( V_157 == V_2 -> V_115 ) {
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
static int F_65 ( struct V_128 * V_128 , void * V_129 , unsigned int * V_8 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
* V_8 = V_2 -> V_115 ;
return 0 ;
}
static int F_66 ( struct V_128 * V_128 , void * V_129 , unsigned int V_8 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_2 -> V_109 = 0 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( V_8 >= V_158 )
return - V_106 ;
if ( 0 == F_37 ( V_8 ) -> type )
return - V_106 ;
F_36 ( V_2 , V_8 ) ;
if ( F_37 ( V_8 ) -> type == V_162 ||
F_37 ( V_8 ) -> type == V_163 ) {
F_59 ( V_2 , V_152 , V_153 , V_2 -> V_151 ) ;
}
return 0 ;
}
static int F_67 ( struct V_128 * V_128 , void * V_129 , struct V_174 * V_175 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
switch ( V_175 -> V_114 ) {
case V_176 :
strcpy ( V_175 -> V_160 , L_24 ) ;
break;
case V_177 :
strcpy ( V_175 -> V_160 , L_25 ) ;
break;
default:
return - V_106 ;
}
V_175 -> V_114 = V_2 -> V_116 ;
V_175 -> V_178 = V_179 ;
return 0 ;
}
static int F_68 ( struct V_128 * V_128 , void * V_129 , struct V_174 * V_175 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_20 = 0 ;
if ( V_175 -> V_114 != V_2 -> V_116 )
return - V_106 ;
V_2 -> V_116 = F_37 ( V_175 -> V_114 ) -> V_117 ;
V_20 = F_40 ( V_2 , V_2 -> V_116 ) ;
return V_20 ;
}
static int F_69 ( struct V_128 * V_128 , void * V_129 ,
struct V_180 * V_181 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_150 = V_181 -> V_150 ;
int V_8 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_181 -> V_150 = F_70 ( V_182 , V_181 -> V_150 ) ;
if ( F_71 ( V_181 -> V_150 == 0 ) )
return - V_106 ;
memset ( V_181 , 0 , sizeof( * V_181 ) ) ;
V_181 -> V_150 = V_150 ;
if ( V_181 -> V_150 < V_183 || V_181 -> V_150 >= V_184 )
return - V_106 ;
for ( V_8 = 0 ; V_8 < V_185 ; V_8 ++ )
if ( V_186 [ V_8 ] . V_187 . V_150 == V_181 -> V_150 )
break;
if ( V_8 == V_185 ) {
* V_181 = V_188 ;
return 0 ;
}
* V_181 = V_186 [ V_8 ] . V_187 ;
F_59 ( V_2 , V_152 , V_189 , V_181 ) ;
if ( V_181 -> type )
return 0 ;
else
return - V_106 ;
}
static int F_72 ( struct V_128 * V_128 , void * V_129 ,
struct V_190 * V_191 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_152 , V_192 , V_191 ) ;
return V_39 ;
}
static int F_73 ( struct V_128 * V_128 , void * V_129 ,
struct V_190 * V_191 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
F_59 ( V_2 , V_152 , V_193 , V_191 ) ;
return V_39 ;
}
static int F_74 ( struct V_128 * V_128 , void * V_129 , struct V_194 * V_195 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_195 -> V_114 )
return - V_106 ;
strcpy ( V_195 -> V_160 , L_26 ) ;
V_195 -> type = V_196 ;
V_195 -> V_178 = V_197 ;
V_195 -> V_198 = 0xffffffffUL ;
V_195 -> signal = 0xffff ;
return 0 ;
}
static int F_75 ( struct V_128 * V_128 , void * V_129 , struct V_194 * V_195 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_195 -> V_114 )
return - V_106 ;
#if 0
call_all(dev, tuner, s_tuner, t);
#endif
return 0 ;
}
static int F_76 ( struct V_128 * V_128 , void * V_129 ,
struct V_199 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
V_131 -> type = V_90 -> V_200 ? V_201 : V_196 ;
V_131 -> V_202 = V_2 -> V_203 ;
F_59 ( V_2 , V_204 , V_205 , V_131 ) ;
return 0 ;
}
static int F_77 ( struct V_128 * V_128 , void * V_129 ,
struct V_199 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
T_1 V_206 = 5400000 ;
F_41 ( L_27 ,
V_131 -> V_202 , V_131 -> type ) ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( 0 != V_131 -> V_204 )
return - V_106 ;
if ( F_71 ( 0 == V_90 -> V_200 && V_131 -> type != V_196 ) )
return - V_106 ;
if ( F_71 ( 1 == V_90 -> V_200 && V_131 -> type != V_201 ) )
return - V_106 ;
V_39 = F_78 ( V_2 ) ;
V_2 -> V_203 = V_131 -> V_202 ;
F_59 ( V_2 , V_204 , V_207 , V_131 ) ;
V_39 = F_79 ( V_2 ) ;
if ( V_2 -> V_208 == V_209 ) {
if ( V_2 -> V_151 & ( V_210 | V_211 ) )
V_206 = 5400000 ;
else if ( V_2 -> V_151 & V_212 )
V_206 = 6000000 ;
else if ( V_2 -> V_151 & ( V_213 | V_214 ) )
V_206 = 6900000 ;
else if ( V_2 -> V_151 & V_215 )
V_206 = 7100000 ;
else if ( V_2 -> V_151 & V_216 )
V_206 = 7250000 ;
else if ( V_2 -> V_151 & V_217 )
V_206 = 6900000 ;
else if ( V_2 -> V_151 & V_218 )
V_206 = 1250000 ;
F_41 ( L_28 , V_206 ) ;
F_80 ( V_2 , V_206 , 1 , 1 ) ;
F_81 ( V_2 ) ;
}
F_41 ( L_29 , V_131 -> V_202 ) ;
return V_39 ;
}
static int F_82 ( struct V_128 * V_128 , void * V_129 ,
struct V_219 * V_220 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_156 = 0 ;
T_2 V_221 [ 4 ] = { 0 , 0 , 0 , 0 } ;
T_1 V_222 = 0 ;
switch ( V_220 -> V_223 . type ) {
case V_224 :
switch ( V_220 -> V_223 . V_225 ) {
case 0 :
V_156 = F_83 ( V_2 , V_226 ,
( V_81 ) V_220 -> V_220 , V_221 , 4 ) ;
V_220 -> V_227 = V_221 [ 0 ] | V_221 [ 1 ] << 8 |
V_221 [ 2 ] << 16 | V_221 [ 3 ] << 24 ;
break;
case 1 :
V_156 = F_64 ( V_2 , V_228 ,
( V_81 ) V_220 -> V_220 , 2 , & V_222 , 1 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 14 :
V_156 = F_64 ( V_2 , V_228 ,
( V_81 ) V_220 -> V_220 , 2 , & V_222 , 4 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
break;
case 2 :
V_156 = F_64 ( V_2 , V_168 ,
( V_81 ) V_220 -> V_220 , 2 , & V_222 , 1 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 24 :
V_156 = F_64 ( V_2 , V_168 ,
( V_81 ) V_220 -> V_220 , 2 , & V_222 , 4 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
break;
case 3 :
V_156 = F_64 ( V_2 ,
V_229 ,
( V_81 ) V_220 -> V_220 , 1 ,
& V_222 , 1 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 34 :
V_156 =
F_64 ( V_2 , V_229 ,
( V_81 ) V_220 -> V_220 , 1 , & V_222 , 4 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
break;
}
return V_156 < 0 ? V_156 : 0 ;
case V_230 :
F_59 ( V_2 , V_152 , V_231 , V_220 ) ;
return 0 ;
case V_232 :
switch ( V_220 -> V_223 . V_225 ) {
case 0 :
V_156 = F_83 ( V_2 , V_226 ,
( V_81 ) V_220 -> V_220 , V_221 , 4 ) ;
V_220 -> V_227 = V_221 [ 0 ] | V_221 [ 1 ] << 8 |
V_221 [ 2 ] << 16 | V_221 [ 3 ] << 24 ;
break;
case 0x600 :
V_156 = F_85 ( V_2 , V_228 ,
( V_81 ) V_220 -> V_220 , 2 ,
& V_222 , 1 , 0 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 0x880 :
if ( V_220 -> V_220 < 0x0b ) {
V_156 = F_85 ( V_2 ,
V_168 ,
( V_81 ) V_220 -> V_220 , 2 ,
& V_222 , 1 , 0 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
} else {
V_156 = F_85 ( V_2 ,
V_168 ,
( V_81 ) V_220 -> V_220 , 2 ,
& V_222 , 4 , 0 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
}
break;
case 0x980 :
V_156 = F_85 ( V_2 ,
V_229 ,
( V_81 ) V_220 -> V_220 , 1 ,
& V_222 , 1 , 0 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 0x400 :
V_156 =
F_85 ( V_2 , 0x40 ,
( V_81 ) V_220 -> V_220 , 1 ,
& V_222 , 1 , 0 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 0xc01 :
V_156 =
F_85 ( V_2 , 0xc0 ,
( V_81 ) V_220 -> V_220 , 2 ,
& V_222 , 38 , 1 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
break;
case 0x022 :
V_156 =
F_85 ( V_2 , 0x02 ,
( V_81 ) V_220 -> V_220 , 1 ,
& V_222 , 1 , 2 ) ;
V_220 -> V_227 = F_84 ( V_222 & 0xff ) ;
break;
case 0x322 :
V_156 = F_85 ( V_2 ,
0x32 ,
( V_81 ) V_220 -> V_220 , 1 ,
& V_222 , 4 , 2 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
break;
case 0x342 :
V_156 = F_85 ( V_2 ,
0x34 ,
( V_81 ) V_220 -> V_220 , 1 ,
& V_222 , 4 , 2 ) ;
V_220 -> V_227 = F_84 ( V_222 ) ;
break;
default:
F_41 ( L_30 ) ;
break;
}
return V_156 < 0 ? V_156 : 0 ;
default:
if ( ! F_86 ( & V_220 -> V_223 ) )
return - V_106 ;
}
F_59 ( V_2 , V_152 , V_231 , V_220 ) ;
return V_156 ;
}
static int F_87 ( struct V_128 * V_128 , void * V_129 ,
struct V_219 * V_220 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_156 = 0 ;
T_4 V_6 ;
T_1 V_221 ;
T_2 V_222 [ 4 ] = { 0 , 0 , 0 , 0 } ;
V_6 = F_88 ( V_220 -> V_227 ) ;
switch ( V_220 -> V_223 . type ) {
case V_224 :
{
V_221 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_220 -> V_223 . V_225 ) {
case 0 :
V_222 [ 0 ] = ( T_2 ) V_221 ;
V_222 [ 1 ] = ( T_2 ) ( V_221 >> 8 ) ;
V_222 [ 2 ] = ( T_2 ) ( V_221 >> 16 ) ;
V_222 [ 3 ] = ( T_2 ) ( V_221 >> 24 ) ;
V_156 = F_89 ( V_2 ,
V_233 ,
( V_81 ) V_220 -> V_220 , V_222 ,
4 ) ;
break;
case 1 :
V_156 = F_90 ( V_2 ,
V_228 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 1 ) ;
break;
case 14 :
V_156 = F_90 ( V_2 ,
V_228 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 4 ) ;
break;
case 2 :
V_156 =
F_90 ( V_2 ,
V_168 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 1 ) ;
break;
case 24 :
V_156 =
F_90 ( V_2 ,
V_168 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 4 ) ;
break;
case 3 :
V_156 =
F_90 ( V_2 ,
V_229 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 1 ) ;
break;
case 34 :
V_156 =
F_90 ( V_2 ,
V_229 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 4 ) ;
break;
}
}
return V_156 < 0 ? V_156 : 0 ;
case V_232 :
{
V_221 = ( T_1 ) V_6 & 0xffffffff ;
switch ( V_220 -> V_223 . V_225 ) {
case 0 :
V_222 [ 0 ] = ( T_2 ) V_221 ;
V_222 [ 1 ] = ( T_2 ) ( V_221 >> 8 ) ;
V_222 [ 2 ] = ( T_2 ) ( V_221 >> 16 ) ;
V_222 [ 3 ] = ( T_2 ) ( V_221 >> 24 ) ;
V_156 = F_89 ( V_2 ,
V_233 ,
( V_81 ) V_220 -> V_220 , V_222 ,
4 ) ;
break;
case 0x600 :
V_156 = F_91 ( V_2 ,
V_228 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 1 , 0 ) ;
break;
case 0x880 :
if ( V_220 -> V_220 < 0x0b )
F_91 ( V_2 ,
V_168 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 1 , 0 ) ;
else
F_91 ( V_2 ,
V_168 ,
( V_81 ) V_220 -> V_220 , 2 ,
V_221 , 4 , 0 ) ;
break;
case 0x980 :
V_156 =
F_91 ( V_2 ,
V_229 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 1 , 0 ) ;
break;
case 0x400 :
V_156 =
F_91 ( V_2 ,
0x40 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 1 , 0 ) ;
break;
case 0xc01 :
V_156 =
F_91 ( V_2 ,
0xc0 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 1 , 1 ) ;
break;
case 0x022 :
V_156 =
F_91 ( V_2 ,
0x02 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 1 , 2 ) ;
case 0x322 :
V_156 =
F_91 ( V_2 ,
0x32 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 4 , 2 ) ;
break;
case 0x342 :
V_156 =
F_91 ( V_2 ,
0x34 ,
( V_81 ) V_220 -> V_220 , 1 ,
V_221 , 4 , 2 ) ;
break;
default:
F_41 ( L_31
L_32 , V_220 -> V_223 . V_225 ) ;
break;
}
}
default:
break;
}
F_59 ( V_2 , V_152 , V_234 , V_220 ) ;
return V_156 ;
}
static int F_92 ( struct V_128 * V_128 , void * V_129 ,
struct V_235 * V_236 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
if ( V_236 -> type != V_122 )
return - V_106 ;
V_236 -> V_237 . V_238 = 0 ;
V_236 -> V_237 . V_239 = 0 ;
V_236 -> V_237 . V_71 = V_2 -> V_71 ;
V_236 -> V_237 . V_92 = V_2 -> V_92 ;
V_236 -> V_240 = V_236 -> V_237 ;
V_236 -> V_241 . V_242 = 54 ;
V_236 -> V_241 . V_243 = 59 ;
return 0 ;
}
static int F_93 ( struct V_128 * V_128 , void * V_129 ,
enum V_244 type )
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
F_59 ( V_2 , V_118 , V_245 , 1 ) ;
return V_39 ;
}
static int F_96 ( struct V_128 * V_128 , void * V_129 ,
enum V_244 type )
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
F_39 ( V_2 , V_118 , V_245 , 0 ) ;
F_97 ( & V_90 -> V_146 ) ;
F_45 ( V_90 ) ;
return 0 ;
}
static int F_98 ( struct V_128 * V_128 , void * V_129 ,
struct V_246 * V_247 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
F_99 ( V_247 -> V_248 , L_33 , sizeof( V_247 -> V_248 ) ) ;
F_99 ( V_247 -> V_249 , V_250 [ V_2 -> V_251 ] . V_160 , sizeof( V_247 -> V_249 ) ) ;
F_100 ( V_2 -> V_252 , V_247 -> V_253 , sizeof( V_247 -> V_253 ) ) ;
V_247 -> V_254 = V_255 |
#if 0
V4L2_CAP_SLICED_VBI_CAPTURE |
#endif
V_256 |
V_257 |
V_258 |
V_259 ;
if ( V_2 -> V_208 != V_260 )
V_247 -> V_254 |= V_261 ;
return 0 ;
}
static int F_101 ( struct V_128 * V_128 , void * V_129 ,
struct V_262 * V_131 )
{
if ( F_71 ( V_131 -> V_114 >= F_50 ( V_93 ) ) )
return - V_106 ;
F_99 ( V_131 -> V_263 , V_93 [ V_131 -> V_114 ] . V_160 , sizeof( V_131 -> V_263 ) ) ;
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
V_131 -> V_132 . V_264 . V_265 = 0 ;
F_59 ( V_2 , V_266 , V_267 , & V_131 -> V_132 . V_264 ) ;
if ( V_131 -> V_132 . V_264 . V_265 == 0 )
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
F_59 ( V_2 , V_266 , V_267 , & V_131 -> V_132 . V_264 ) ;
if ( V_131 -> V_132 . V_264 . V_265 == 0 )
return - V_106 ;
return 0 ;
}
static int F_104 ( struct V_128 * V_128 , void * V_129 ,
struct V_130 * V_131 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
V_131 -> V_132 . V_266 . V_268 = 6750000 * 4 ;
V_131 -> V_132 . V_266 . V_269 = V_270 ;
V_131 -> V_132 . V_266 . V_271 = V_272 ;
V_131 -> V_132 . V_266 . V_51 = 0 ;
V_131 -> V_132 . V_266 . V_273 [ 0 ] = ( V_2 -> V_151 & V_274 ) ?
V_275 : V_276 ;
V_131 -> V_132 . V_266 . V_88 [ 0 ] = ( V_2 -> V_151 & V_274 ) ?
V_277 : V_278 ;
V_131 -> V_132 . V_266 . V_273 [ 1 ] = ( V_2 -> V_151 & V_274 ) ?
V_275 + 312 : V_276 + 263 ;
V_131 -> V_132 . V_266 . V_88 [ 1 ] = V_131 -> V_132 . V_266 . V_88 [ 0 ] ;
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
V_131 -> V_132 . V_266 . V_268 = 6750000 * 4 ;
V_131 -> V_132 . V_266 . V_269 = V_270 ;
V_131 -> V_132 . V_266 . V_271 = V_272 ;
V_131 -> V_132 . V_266 . V_51 = 0 ;
V_131 -> V_132 . V_266 . V_97 = 0 ;
V_131 -> V_132 . V_266 . V_273 [ 0 ] = ( V_2 -> V_151 & V_274 ) ?
V_275 : V_276 ;
V_131 -> V_132 . V_266 . V_88 [ 0 ] = ( V_2 -> V_151 & V_274 ) ?
V_277 : V_278 ;
V_131 -> V_132 . V_266 . V_273 [ 1 ] = ( V_2 -> V_151 & V_274 ) ?
V_275 + 312 : V_276 + 263 ;
V_131 -> V_132 . V_266 . V_88 [ 1 ] = V_131 -> V_132 . V_266 . V_88 [ 0 ] ;
return 0 ;
}
static int F_106 ( struct V_128 * V_128 , void * V_129 ,
struct V_279 * V_280 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_107 ( & V_90 -> V_146 , V_280 ) ;
}
static int F_108 ( struct V_128 * V_128 , void * V_129 , struct V_281 * V_282 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_109 ( & V_90 -> V_146 , V_282 ) ;
}
static int F_110 ( struct V_128 * V_128 , void * V_129 , struct V_281 * V_282 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_111 ( & V_90 -> V_146 , V_282 ) ;
}
static int F_112 ( struct V_128 * V_128 , void * V_129 , struct V_281 * V_282 )
{
struct V_89 * V_90 = V_129 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
return F_113 ( & V_90 -> V_146 , V_282 , V_128 -> V_283 & V_284 ) ;
}
static int F_114 ( struct V_128 * V_128 , void * V_129 ,
struct V_246 * V_247 )
{
struct V_1 * V_2 = ( (struct V_89 * ) V_129 ) -> V_2 ;
F_99 ( V_247 -> V_248 , L_33 , sizeof( V_247 -> V_248 ) ) ;
F_99 ( V_247 -> V_249 , V_250 [ V_2 -> V_251 ] . V_160 , sizeof( V_247 -> V_249 ) ) ;
F_100 ( V_2 -> V_252 , V_247 -> V_253 , sizeof( V_247 -> V_253 ) ) ;
V_247 -> V_254 = V_261 ;
return 0 ;
}
static int F_115 ( struct V_128 * V_128 , void * V_129 , struct V_194 * V_195 )
{
struct V_1 * V_2 = ( (struct V_89 * ) V_129 ) -> V_2 ;
if ( F_71 ( V_195 -> V_114 > 0 ) )
return - V_106 ;
strcpy ( V_195 -> V_160 , L_34 ) ;
V_195 -> type = V_201 ;
F_59 ( V_2 , V_204 , V_285 , V_195 ) ;
return 0 ;
}
static int F_116 ( struct V_128 * V_128 , void * V_129 , struct V_154 * V_8 )
{
if ( V_8 -> V_114 != 0 )
return - V_106 ;
strcpy ( V_8 -> V_160 , L_34 ) ;
V_8 -> type = V_164 ;
return 0 ;
}
static int F_117 ( struct V_128 * V_128 , void * V_129 , struct V_174 * V_175 )
{
if ( F_71 ( V_175 -> V_114 ) )
return - V_106 ;
strcpy ( V_175 -> V_160 , L_34 ) ;
return 0 ;
}
static int F_118 ( struct V_128 * V_128 , void * V_129 , struct V_194 * V_195 )
{
struct V_1 * V_2 = ( (struct V_89 * ) V_129 ) -> V_2 ;
if ( 0 != V_195 -> V_114 )
return - V_106 ;
F_59 ( V_2 , V_204 , V_285 , V_195 ) ;
return 0 ;
}
static int F_119 ( struct V_128 * V_128 , void * V_90 , struct V_174 * V_175 )
{
return 0 ;
}
static int F_120 ( struct V_128 * V_128 , void * V_90 , unsigned int V_8 )
{
return 0 ;
}
static int F_121 ( struct V_128 * V_128 , void * V_129 ,
struct V_180 * V_286 )
{
int V_8 ;
if ( V_286 -> V_150 < V_183 || V_286 -> V_150 >= V_184 )
return - V_106 ;
if ( V_286 -> V_150 == V_287 ) {
for ( V_8 = 0 ; V_8 < V_185 ; V_8 ++ ) {
if ( V_186 [ V_8 ] . V_187 . V_150 == V_286 -> V_150 )
break;
}
if ( V_8 == V_185 )
return - V_106 ;
* V_286 = V_186 [ V_8 ] . V_187 ;
} else
* V_286 = V_188 ;
return 0 ;
}
static int F_122 ( struct V_128 * V_288 )
{
int V_289 = 0 , V_200 = 0 ;
struct V_290 * V_166 = F_123 ( V_288 ) ;
struct V_1 * V_2 = F_124 ( V_288 ) ;
struct V_89 * V_90 ;
enum V_244 V_291 = 0 ;
switch ( V_166 -> V_292 ) {
case V_293 :
V_291 = V_122 ;
break;
case V_294 :
V_291 = V_124 ;
break;
case V_295 :
V_200 = 1 ;
break;
}
F_54 ( L_35 ,
F_125 ( V_166 ) , V_296 [ V_291 ] ,
V_2 -> V_297 ) ;
#if 0
errCode = cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
if (errCode < 0) {
cx231xx_errdev
("Device locked on digital mode. Can't open analog\n");
return -EBUSY;
}
#endif
V_90 = F_126 ( sizeof( struct V_89 ) , V_298 ) ;
if ( ! V_90 ) {
F_47 ( L_36 ) ;
return - V_299 ;
}
V_90 -> V_2 = V_2 ;
V_90 -> V_200 = V_200 ;
V_90 -> type = V_291 ;
V_288 -> V_300 = V_90 ;
if ( V_90 -> type == V_122 && V_2 -> V_297 == 0 ) {
V_2 -> V_71 = F_52 ( V_2 ) ;
V_2 -> V_92 = F_53 ( V_2 ) ;
if ( V_2 -> V_301 . V_302 )
F_127 ( V_2 ,
V_303 ) ;
else
F_127 ( V_2 , V_304 ) ;
#if 0
cx231xx_set_mode(dev, CX231XX_ANALOG_MODE);
#endif
F_128 ( V_2 ) ;
F_129 ( V_2 ) ;
V_2 -> V_115 = V_2 -> V_115 > 2 ? 2 : V_2 -> V_115 ;
}
if ( V_90 -> V_200 ) {
F_54 ( L_37 ) ;
F_59 ( V_2 , V_204 , V_305 ) ;
}
V_2 -> V_297 ++ ;
if ( V_90 -> type == V_122 )
F_130 ( & V_90 -> V_146 , & V_306 ,
NULL , & V_2 -> V_14 . V_98 ,
V_90 -> type , V_140 ,
sizeof( struct V_5 ) ,
V_90 , & V_2 -> V_307 ) ;
if ( V_90 -> type == V_124 ) {
F_131 ( V_2 , V_308 , 0 ) ;
F_130 ( & V_90 -> V_146 , & V_309 ,
NULL , & V_2 -> V_310 . V_98 ,
V_90 -> type , V_311 ,
sizeof( struct V_5 ) ,
V_90 , & V_2 -> V_307 ) ;
}
return V_289 ;
}
void F_132 ( struct V_1 * V_2 )
{
if ( V_2 -> V_312 ) {
if ( F_133 ( V_2 -> V_312 ) )
F_134 ( V_2 -> V_312 ) ;
else
F_135 ( V_2 -> V_312 ) ;
V_2 -> V_312 = NULL ;
}
if ( V_2 -> V_313 ) {
F_41 ( L_38 ,
F_125 ( V_2 -> V_313 ) ) ;
if ( F_133 ( V_2 -> V_313 ) )
F_134 ( V_2 -> V_313 ) ;
else
F_135 ( V_2 -> V_313 ) ;
V_2 -> V_313 = NULL ;
}
if ( V_2 -> V_166 ) {
F_41 ( L_38 ,
F_125 ( V_2 -> V_166 ) ) ;
if ( V_2 -> V_301 . V_314 )
F_136 ( V_2 ) ;
if ( F_133 ( V_2 -> V_166 ) )
F_134 ( V_2 -> V_166 ) ;
else
F_135 ( V_2 -> V_166 ) ;
V_2 -> V_166 = NULL ;
}
}
static int F_137 ( struct V_128 * V_288 )
{
struct V_89 * V_90 = V_288 -> V_300 ;
struct V_1 * V_2 = V_90 -> V_2 ;
F_54 ( L_39 , V_2 -> V_297 ) ;
F_54 ( L_39 , V_2 -> V_297 ) ;
if ( F_44 ( V_90 ) )
F_45 ( V_90 ) ;
if ( ! V_2 -> V_301 . V_315 )
if ( V_90 -> type == V_124 ) {
F_138 ( & V_90 -> V_146 ) ;
F_139 ( & V_90 -> V_146 ) ;
if ( V_2 -> V_9 & V_44 ) {
if ( F_140 ( & V_2 -> V_316 ) > 0 ) {
F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
return 0 ;
}
F_143 ( V_2 ) ;
if ( ! V_2 -> V_317 )
F_131 ( V_2 , V_308 , 0 ) ;
else
F_131 ( V_2 , V_318 , 0 ) ;
F_142 ( V_90 ) ;
V_2 -> V_297 -- ;
F_144 ( & V_2 -> V_319 , 1 ) ;
return 0 ;
}
if ( V_2 -> V_297 == 1 ) {
F_138 ( & V_90 -> V_146 ) ;
F_139 ( & V_90 -> V_146 ) ;
if ( V_2 -> V_9 & V_44 ) {
F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
V_2 = NULL ;
return 0 ;
}
F_59 ( V_2 , V_152 , V_320 , 0 ) ;
if ( V_2 -> V_13 )
F_145 ( V_2 ) ;
else
F_146 ( V_2 ) ;
F_147 ( V_2 , V_321 ) ;
F_131 ( V_2 , V_322 , 0 ) ;
}
F_142 ( V_90 ) ;
V_2 -> V_297 -- ;
F_144 ( & V_2 -> V_319 , 1 ) ;
return 0 ;
}
static T_5
F_148 ( struct V_128 * V_288 , char T_6 * V_6 , T_7 V_88 ,
T_8 * V_75 )
{
struct V_89 * V_90 = V_288 -> V_300 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
if ( ( V_90 -> type == V_122 ) ||
( V_90 -> type == V_124 ) ) {
V_39 = F_43 ( V_90 ) ;
if ( F_71 ( V_39 < 0 ) )
return V_39 ;
return F_149 ( & V_90 -> V_146 , V_6 , V_88 , V_75 , 0 ,
V_288 -> V_283 & V_284 ) ;
}
return 0 ;
}
static unsigned int F_150 ( struct V_128 * V_288 , T_9 * V_323 )
{
struct V_89 * V_90 = V_288 -> V_300 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_90 ) ;
if ( F_71 ( V_39 < 0 ) )
return V_324 ;
if ( ( V_122 == V_90 -> type ) ||
( V_124 == V_90 -> type ) )
return F_151 ( V_288 , & V_90 -> V_146 , V_323 ) ;
else
return V_324 ;
}
static int F_152 ( struct V_128 * V_288 , struct V_325 * V_326 )
{
struct V_89 * V_90 = V_288 -> V_300 ;
struct V_1 * V_2 = V_90 -> V_2 ;
int V_39 ;
V_39 = F_46 ( V_2 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_43 ( V_90 ) ;
if ( F_71 ( V_39 < 0 ) )
return V_39 ;
V_39 = F_153 ( & V_90 -> V_146 , V_326 ) ;
F_54 ( L_40 ,
( unsigned long ) V_326 -> V_327 ,
( unsigned long ) V_326 -> V_328 -
( unsigned long ) V_326 -> V_327 , V_39 ) ;
return V_39 ;
}
static struct V_290 * F_154 ( struct V_1 * V_2 ,
const struct V_290
* V_329 , const char * V_330 )
{
struct V_290 * V_331 ;
V_331 = F_155 () ;
if ( NULL == V_331 )
return NULL ;
* V_331 = * V_329 ;
V_331 -> V_332 = & V_2 -> V_332 ;
V_331 -> V_333 = F_135 ;
V_331 -> V_334 = V_335 ;
V_331 -> V_307 = & V_2 -> V_307 ;
snprintf ( V_331 -> V_160 , sizeof( V_331 -> V_160 ) , L_41 , V_2 -> V_160 , V_330 ) ;
F_156 ( V_331 , V_2 ) ;
return V_331 ;
}
int F_157 ( struct V_1 * V_2 )
{
int V_156 ;
F_41 ( L_42 ,
V_2 -> V_160 , V_336 ) ;
V_2 -> V_71 = F_52 ( V_2 ) ;
V_2 -> V_92 = F_53 ( V_2 ) ;
V_2 -> V_337 = 0 ;
V_2 -> V_93 = & V_93 [ 0 ] ;
F_36 ( V_2 , V_2 -> V_115 ) ;
V_2 -> V_338 = 1 ;
V_2 -> V_339 = 0x1f ;
V_2 -> V_166 = F_154 ( V_2 , & V_340 , L_43 ) ;
if ( ! V_2 -> V_166 ) {
F_47 ( L_44 ) ;
return - V_126 ;
}
V_156 = F_158 ( V_2 -> V_166 , V_293 ,
V_341 [ V_2 -> V_342 ] ) ;
if ( V_156 ) {
F_47 ( L_45 ,
V_156 ) ;
return V_156 ;
}
F_41 ( L_46 ,
V_2 -> V_160 , F_125 ( V_2 -> V_166 ) ) ;
memcpy ( & V_343 , & V_340 ,
sizeof( V_343 ) ) ;
strcpy ( V_343 . V_160 , L_47 ) ;
V_2 -> V_313 = F_154 ( V_2 , & V_343 , L_48 ) ;
V_156 = F_158 ( V_2 -> V_313 , V_294 ,
V_344 [ V_2 -> V_342 ] ) ;
if ( V_156 < 0 ) {
F_47 ( L_49 ) ;
return V_156 ;
}
F_41 ( L_50 ,
V_2 -> V_160 , F_125 ( V_2 -> V_313 ) ) ;
if ( V_250 [ V_2 -> V_251 ] . V_200 . type == V_345 ) {
V_2 -> V_312 = F_154 ( V_2 , & V_346 ,
L_51 ) ;
if ( ! V_2 -> V_312 ) {
F_47 ( L_44 ) ;
return - V_126 ;
}
V_156 = F_158 ( V_2 -> V_312 , V_295 ,
V_347 [ V_2 -> V_342 ] ) ;
if ( V_156 < 0 ) {
F_47 ( L_52 ) ;
return V_156 ;
}
F_41 ( L_53 ,
F_125 ( V_2 -> V_312 ) ) ;
}
F_41 ( L_54 ,
F_125 ( V_2 -> V_166 ) ,
F_125 ( V_2 -> V_313 ) ) ;
return 0 ;
}
