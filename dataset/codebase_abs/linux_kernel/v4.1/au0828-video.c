static inline void F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_4 . V_5 && V_2 -> V_4 . V_5 -> V_6 . V_7 . F_1 )
V_2 -> V_4 . V_5 -> V_6 . V_7 . F_1 ( V_2 -> V_4 . V_5 , V_3 ) ;
}
static inline void F_2 ( struct V_1 * V_2 ,
int V_8 , int V_9 )
{
char * V_10 = L_1 ;
switch ( V_9 ) {
case - V_11 :
V_10 = L_2 ;
break;
case - V_12 :
V_10 = L_3 ;
break;
case - V_13 :
V_10 = L_4 ;
break;
case - V_14 :
V_10 = L_5 ;
break;
case - V_15 :
V_10 = L_6 ;
break;
case - V_16 :
V_10 = L_7 ;
break;
case - V_17 :
V_10 = L_8 ;
break;
case - V_18 :
V_10 = L_9 ;
break;
}
if ( V_8 < 0 ) {
F_3 ( L_10 , V_9 , V_10 ) ;
} else {
F_3 ( L_11 ,
V_8 , V_9 , V_10 ) ;
}
}
static int F_4 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 & V_20 ) {
F_5 ( L_12 ) ;
return - V_21 ;
}
if ( V_2 -> V_19 & V_22 ) {
F_5 ( L_13
L_14 ) ;
return - V_23 ;
}
return 0 ;
}
static void F_6 ( struct V_24 * V_24 )
{
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_28 ) ;
unsigned long V_29 = 0 ;
int V_30 ;
switch ( V_24 -> V_9 ) {
case 0 :
case - V_31 :
break;
case - V_12 :
case - V_11 :
case - V_32 :
F_3 ( L_15 ) ;
return;
default:
F_3 ( L_16 , V_24 -> V_9 ) ;
break;
}
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_34 . V_35 ( V_2 , V_24 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
for ( V_30 = 0 ; V_30 < V_24 -> V_36 ; V_30 ++ ) {
V_24 -> V_37 [ V_30 ] . V_9 = 0 ;
V_24 -> V_37 [ V_30 ] . V_38 = 0 ;
}
V_24 -> V_9 = 0 ;
V_24 -> V_9 = F_10 ( V_24 , V_39 ) ;
if ( V_24 -> V_9 ) {
F_3 ( L_17 ,
V_24 -> V_9 ) ;
}
V_2 -> V_40 = V_41 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_3 ( L_18 ) ;
V_2 -> V_34 . V_42 = - 1 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = V_2 -> V_34 . V_24 [ V_30 ] ;
if ( V_24 ) {
if ( ! F_12 () )
F_13 ( V_24 ) ;
else
F_14 ( V_24 ) ;
if ( V_2 -> V_34 . V_44 [ V_30 ] ) {
F_15 ( V_2 -> V_45 ,
V_24 -> V_46 ,
V_2 -> V_34 . V_44 [ V_30 ] ,
V_24 -> V_47 ) ;
}
F_16 ( V_24 ) ;
V_2 -> V_34 . V_24 [ V_30 ] = NULL ;
}
V_2 -> V_34 . V_44 [ V_30 ] = NULL ;
}
F_17 ( V_2 -> V_34 . V_24 ) ;
F_17 ( V_2 -> V_34 . V_44 ) ;
V_2 -> V_34 . V_24 = NULL ;
V_2 -> V_34 . V_44 = NULL ;
V_2 -> V_34 . V_43 = 0 ;
V_2 -> V_40 = V_48 ;
}
static int F_18 ( struct V_1 * V_2 , int V_49 ,
int V_43 , int V_50 ,
int (* V_35) ( struct V_1 * V_2 , struct V_24 * V_24 ) )
{
struct V_25 * V_26 = & V_2 -> V_28 ;
int V_30 ;
int V_51 , V_52 ;
struct V_24 * V_24 ;
int V_53 , V_54 ;
int V_55 ;
F_3 ( L_19 ) ;
V_2 -> V_34 . V_35 = V_35 ;
V_2 -> V_34 . V_43 = V_43 ;
V_2 -> V_34 . V_24 = F_19 ( sizeof( void * ) * V_43 , V_56 ) ;
if ( ! V_2 -> V_34 . V_24 ) {
F_3 ( L_20 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_44 = F_19 ( sizeof( void * ) * V_43 ,
V_56 ) ;
if ( ! V_2 -> V_34 . V_44 ) {
F_3 ( L_21 ) ;
F_17 ( V_2 -> V_34 . V_24 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_50 = V_50 ;
V_2 -> V_34 . V_58 = NULL ;
V_51 = V_49 * V_2 -> V_34 . V_50 ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = F_20 ( V_49 , V_56 ) ;
if ( ! V_24 ) {
F_3 ( L_22 , V_30 ) ;
F_11 ( V_2 ) ;
return - V_57 ;
}
V_2 -> V_34 . V_24 [ V_30 ] = V_24 ;
V_2 -> V_34 . V_44 [ V_30 ] = F_21 ( V_2 -> V_45 ,
V_51 , V_56 , & V_24 -> V_47 ) ;
if ( ! V_2 -> V_34 . V_44 [ V_30 ] ) {
F_22 ( L_23
L_24 ,
V_51 , V_30 ,
F_23 () ? L_25 : L_26 ) ;
F_11 ( V_2 ) ;
return - V_57 ;
}
memset ( V_2 -> V_34 . V_44 [ V_30 ] , 0 , V_51 ) ;
V_52 = F_24 ( V_2 -> V_45 ,
V_2 -> V_59 ) ,
F_25 ( V_24 , V_2 -> V_45 , V_52 ,
V_2 -> V_34 . V_44 [ V_30 ] , V_51 ,
F_6 , V_26 , 1 ) ;
V_24 -> V_36 = V_49 ;
V_24 -> V_60 = V_61 | V_62 ;
V_54 = 0 ;
for ( V_53 = 0 ; V_53 < V_49 ; V_53 ++ ) {
V_24 -> V_37 [ V_53 ] . V_63 = V_54 ;
V_24 -> V_37 [ V_53 ] . V_64 =
V_2 -> V_34 . V_50 ;
V_54 += V_2 -> V_34 . V_50 ;
}
}
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_55 = F_10 ( V_2 -> V_34 . V_24 [ V_30 ] , V_39 ) ;
if ( V_55 ) {
F_3 ( L_27 ,
V_30 , V_55 ) ;
F_11 ( V_2 ) ;
return V_55 ;
}
}
return 0 ;
}
static inline void F_26 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 )
{
struct V_66 * V_67 = & V_58 -> V_67 ;
struct V_68 * V_69 = V_67 -> V_68 ;
F_3 ( L_28 , V_58 , V_58 -> V_70 ) ;
if ( V_69 -> type == V_71 )
V_67 -> V_72 . V_73 = V_2 -> V_74 ++ ;
else
V_67 -> V_72 . V_73 = V_2 -> V_75 ++ ;
V_67 -> V_72 . V_76 = V_77 ;
F_27 ( & V_67 -> V_72 . V_78 ) ;
F_28 ( V_67 , V_79 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_80 ,
unsigned char * V_81 , unsigned long V_82 )
{
void * V_83 , * V_84 , * V_85 ;
int V_86 , V_87 , V_63 , V_88 , V_89 ;
int V_90 = V_2 -> V_91 << 1 ;
if ( V_82 == 0 )
return;
if ( V_26 -> V_92 + V_82 > V_58 -> V_64 )
V_82 = V_58 -> V_64 - V_26 -> V_92 ;
V_85 = V_80 ;
V_89 = V_82 ;
if ( V_58 -> V_70 )
V_83 = V_81 ;
else
V_83 = V_81 + V_90 ;
V_86 = V_26 -> V_92 / V_90 ;
V_87 = V_26 -> V_92 % V_90 ;
V_63 = V_86 * V_90 * 2 + V_87 ;
V_84 = V_83 + V_63 ;
V_88 = V_90 - V_87 ;
V_88 = V_88 > V_89 ? V_89 : V_88 ;
if ( ( char * ) V_84 + V_88 > ( char * ) V_81 + V_58 -> V_64 ) {
F_3 ( L_29 ,
( ( char * ) V_84 + V_88 ) -
( ( char * ) V_81 + V_58 -> V_64 ) ) ;
V_89 = ( char * ) V_81 + V_58 -> V_64 - ( char * ) V_84 ;
V_88 = V_89 ;
}
if ( V_88 <= 0 )
return;
memcpy ( V_84 , V_85 , V_88 ) ;
V_89 -= V_88 ;
while ( V_89 > 0 ) {
V_84 += V_88 + V_90 ;
V_85 += V_88 ;
if ( V_90 > V_89 )
V_88 = V_89 ;
else
V_88 = V_90 ;
if ( ( char * ) V_84 + V_88 > ( char * ) V_81 +
V_58 -> V_64 ) {
F_3 ( L_30 ,
( ( char * ) V_84 + V_88 ) -
( ( char * ) V_81 + V_58 -> V_64 ) ) ;
V_88 = V_89 = ( char * ) V_81 + V_58 -> V_64 -
( char * ) V_84 ;
}
if ( V_88 <= 0 )
break;
memcpy ( V_84 , V_85 , V_88 ) ;
V_89 -= V_88 ;
}
if ( V_63 > 1440 ) {
if ( V_81 [ 0 ] < 0x60 && V_81 [ 1440 ] < 0x60 )
V_2 -> V_93 = 1 ;
}
V_26 -> V_92 += V_82 ;
}
static inline void F_30 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_28 ) ;
if ( F_31 ( & V_26 -> V_94 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_58 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_32 ( V_26 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & ( * V_58 ) -> V_96 ) ;
V_26 -> V_92 = 0 ;
( * V_58 ) -> V_97 = ( * V_58 ) -> V_98 ;
V_2 -> V_34 . V_58 = * V_58 ;
return;
}
static void F_34 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_65 * V_58 ,
unsigned char * V_80 ,
unsigned char * V_81 , unsigned long V_82 )
{
unsigned char * V_84 , * V_85 ;
int V_90 ;
int V_30 , V_53 = 0 ;
if ( V_2 == NULL ) {
F_3 ( L_32 ) ;
return;
}
if ( V_26 == NULL ) {
F_3 ( L_33 ) ;
return;
}
if ( V_58 == NULL )
return;
if ( V_80 == NULL ) {
F_3 ( L_34 ) ;
return;
}
if ( V_81 == NULL ) {
F_3 ( L_35 ) ;
return;
}
V_90 = V_2 -> V_99 ;
if ( V_26 -> V_92 + V_82 > V_58 -> V_64 )
V_82 = V_58 -> V_64 - V_26 -> V_92 ;
V_85 = V_80 ;
V_84 = V_81 + ( V_26 -> V_92 / 2 ) ;
if ( V_58 -> V_70 == 0 )
V_84 += V_90 * V_2 -> V_100 ;
for ( V_30 = 0 ; V_30 < V_82 ; V_30 += 2 )
V_84 [ V_53 ++ ] = V_85 [ V_30 + 1 ] ;
V_26 -> V_92 += V_82 ;
}
static inline void F_35 ( struct V_25 * V_26 ,
struct V_65 * * V_58 )
{
struct V_1 * V_2 = F_7 ( V_26 , struct V_1 , V_101 ) ;
if ( F_31 ( & V_26 -> V_94 ) ) {
F_3 ( L_31 ) ;
V_2 -> V_34 . V_102 = NULL ;
* V_58 = NULL ;
return;
}
* V_58 = F_32 ( V_26 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & ( * V_58 ) -> V_96 ) ;
V_26 -> V_92 = 0 ;
( * V_58 ) -> V_97 = ( * V_58 ) -> V_98 ;
V_2 -> V_34 . V_102 = * V_58 ;
return;
}
static inline int F_36 ( struct V_1 * V_2 , struct V_24 * V_24 )
{
struct V_65 * V_58 ;
struct V_65 * V_102 ;
struct V_25 * V_26 = V_24 -> V_27 ;
struct V_25 * V_103 = & V_2 -> V_101 ;
unsigned char * V_81 = NULL ;
unsigned char * V_104 = NULL ;
int V_30 , V_82 = 0 , V_55 = 1 ;
unsigned char * V_80 ;
unsigned char V_105 ;
unsigned int V_106 ;
unsigned int V_89 , V_88 ;
if ( ! V_2 )
return 0 ;
if ( ( V_2 -> V_19 & V_20 ) ||
( V_2 -> V_19 & V_22 ) )
return 0 ;
if ( V_24 -> V_9 < 0 ) {
F_2 ( V_2 , - 1 , V_24 -> V_9 ) ;
if ( V_24 -> V_9 == - V_11 )
return 0 ;
}
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL )
V_81 = F_37 ( & V_58 -> V_67 , 0 ) ;
V_102 = V_2 -> V_34 . V_102 ;
if ( V_102 != NULL )
V_104 = F_37 ( & V_102 -> V_67 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_24 -> V_36 ; V_30 ++ ) {
int V_9 = V_24 -> V_37 [ V_30 ] . V_9 ;
if ( V_9 < 0 ) {
F_2 ( V_2 , V_30 , V_9 ) ;
if ( V_24 -> V_37 [ V_30 ] . V_9 != - V_16 )
continue;
}
if ( V_24 -> V_37 [ V_30 ] . V_38 <= 0 )
continue;
if ( V_24 -> V_37 [ V_30 ] . V_38 >
V_2 -> V_50 ) {
F_3 ( L_36 ) ;
continue;
}
V_80 = V_24 -> V_44 + V_24 -> V_37 [ V_30 ] . V_63 ;
V_105 = V_80 [ 0 ] ;
V_82 = V_24 -> V_37 [ V_30 ] . V_38 - 4 ;
V_80 += 4 ;
if ( V_105 & 0x80 ) {
V_82 -= 4 ;
V_80 += 4 ;
F_3 ( L_37 ,
( V_105 & 0x40 ) ? L_38 : L_39 ) ;
if ( V_105 & 0x40 ) {
if ( V_102 != NULL )
F_26 ( V_2 , V_103 , V_102 ) ;
F_35 ( V_103 , & V_102 ) ;
if ( V_102 == NULL )
V_104 = NULL ;
else
V_104 = F_37 (
& V_102 -> V_67 , 0 ) ;
if ( V_58 != NULL )
F_26 ( V_2 , V_26 , V_58 ) ;
F_30 ( V_26 , & V_58 ) ;
if ( V_58 == NULL )
V_81 = NULL ;
else
V_81 = F_37 ( & V_58 -> V_67 , 0 ) ;
if ( V_2 -> V_107 )
F_38 ( & V_2 -> V_108 ,
V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_38 ( & V_2 -> V_112 ,
V_109 + ( V_110 / 10 ) ) ;
}
if ( V_58 != NULL ) {
if ( V_105 & 0x40 )
V_58 -> V_70 = 1 ;
else
V_58 -> V_70 = 0 ;
}
if ( V_102 != NULL ) {
if ( V_105 & 0x40 )
V_102 -> V_70 = 1 ;
else
V_102 -> V_70 = 0 ;
}
V_2 -> V_113 = 0 ;
V_103 -> V_92 = 0 ;
V_26 -> V_92 = 0 ;
}
V_106 = V_2 -> V_99 * V_2 -> V_100 * 2 ;
if ( V_2 -> V_113 < V_106 ) {
V_89 = V_106 - V_2 -> V_113 ;
if ( V_82 < V_89 )
V_88 = V_82 ;
else
V_88 = V_89 ;
if ( V_102 != NULL )
F_34 ( V_2 , V_103 , V_102 , V_80 ,
V_104 , V_82 ) ;
V_82 -= V_88 ;
V_80 += V_88 ;
V_2 -> V_113 += V_88 ;
}
if ( V_2 -> V_113 >= V_106 && V_58 != NULL )
F_29 ( V_2 , V_26 , V_58 , V_80 , V_81 , V_82 ) ;
}
return V_55 ;
}
static int F_39 ( struct V_68 * V_114 , const struct V_115 * V_116 ,
unsigned int * V_117 , unsigned int * V_118 ,
unsigned int V_119 [] , void * V_120 [] )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
unsigned long V_121 = V_2 -> V_122 * V_2 -> V_90 ;
unsigned long V_123 ;
V_123 = V_116 ? V_116 -> V_116 . V_124 . V_125 : V_121 ;
if ( V_123 < V_121 )
return - V_126 ;
* V_118 = 1 ;
V_119 [ 0 ] = V_123 ;
return 0 ;
}
static int
F_41 ( struct V_66 * V_67 )
{
struct V_65 * V_58 = F_7 ( V_67 , struct V_65 , V_67 ) ;
struct V_1 * V_2 = F_40 ( V_67 -> V_68 ) ;
V_58 -> V_64 = V_2 -> V_122 * V_2 -> V_90 ;
if ( F_42 ( V_67 , 0 ) < V_58 -> V_64 ) {
F_43 ( L_40 ,
V_127 , F_42 ( V_67 , 0 ) , V_58 -> V_64 ) ;
return - V_126 ;
}
F_44 ( & V_58 -> V_67 , 0 , V_58 -> V_64 ) ;
return 0 ;
}
static void
F_45 ( struct V_66 * V_67 )
{
struct V_65 * V_58 = F_7 ( V_67 ,
struct V_65 ,
V_67 ) ;
struct V_1 * V_2 = F_40 ( V_67 -> V_68 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
V_58 -> V_98 = F_37 ( V_67 , 0 ) ;
V_58 -> V_64 = F_42 ( V_67 , 0 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
F_46 ( & V_58 -> V_96 , & V_28 -> V_94 ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
F_48 ( V_2 , V_128 , 0x01 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_129 )
{
struct V_130 * V_131 ;
int V_132 , V_133 , V_134 ;
F_50 ( 1 , L_41 ) ;
V_131 = F_51 ( V_129 -> V_45 , 0 ) ;
if ( V_131 && V_131 -> V_135 -> V_136 . V_137 != 5 ) {
F_50 ( 1 , L_42 ) ;
V_132 = F_52 ( V_129 -> V_45 , 0 , 5 ) ;
if ( V_132 < 0 ) {
F_5 ( L_43 ) ;
return - V_138 ;
}
}
V_133 = V_129 -> V_122 / 2 + 2 ;
V_134 = V_129 -> V_91 * 2 ;
F_48 ( V_129 , V_139 , 0x00 ) ;
F_48 ( V_129 , 0x106 , 0x00 ) ;
F_48 ( V_129 , 0x110 , 0x00 ) ;
F_48 ( V_129 , 0x111 , 0x00 ) ;
F_48 ( V_129 , 0x114 , V_134 & 0xff ) ;
F_48 ( V_129 , 0x115 , V_134 >> 8 ) ;
F_48 ( V_129 , 0x112 , 0x00 ) ;
F_48 ( V_129 , 0x113 , 0x00 ) ;
F_48 ( V_129 , 0x116 , V_133 & 0xff ) ;
F_48 ( V_129 , 0x117 , V_133 >> 8 ) ;
F_48 ( V_129 , V_140 , 0xb3 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_129 )
{
F_50 ( 1 , L_44 ) ;
F_48 ( V_129 , V_140 , 0x0 ) ;
return 0 ;
}
static void F_54 ( struct V_1 * V_2 )
{
F_50 ( 1 , L_45 ) ;
F_48 ( V_2 , V_140 , 0x0 ) ;
F_55 ( 30 ) ;
F_48 ( V_2 , V_140 , 0xb3 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_132 = 0 ;
V_2 -> V_40 = V_141 ;
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
else if ( V_132 ) {
V_2 -> V_19 = V_22 ;
F_50 ( 1 , L_46 , V_127 ) ;
return V_132 ;
}
return 0 ;
}
int F_57 ( struct V_68 * V_114 , unsigned int V_142 )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
int V_55 = 0 ;
F_50 ( 1 , L_47 ,
V_2 -> V_143 ) ;
if ( V_114 -> type == V_71 )
V_2 -> V_74 = 0 ;
else
V_2 -> V_75 = 0 ;
if ( V_2 -> V_143 == 0 ) {
F_47 ( V_2 ) ;
V_55 = F_18 ( V_2 , V_144 ,
V_145 , V_2 -> V_50 ,
F_36 ) ;
if ( V_55 < 0 ) {
F_5 ( L_48 ) ;
return V_55 ;
}
if ( V_114 -> type == V_71 ) {
F_58 ( & V_2 -> V_146 , 0 , V_147 ,
V_148 , 1 ) ;
V_2 -> V_107 = 1 ;
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
} else if ( V_114 -> type == V_149 ) {
V_2 -> V_111 = 1 ;
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
}
}
V_2 -> V_143 ++ ;
return V_55 ;
}
static void F_59 ( struct V_68 * V_114 )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
struct V_25 * V_28 = & V_2 -> V_28 ;
unsigned long V_29 = 0 ;
F_50 ( 1 , L_49 , V_2 -> V_143 ) ;
if ( V_2 -> V_143 -- == 1 )
F_11 ( V_2 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_147 , V_148 , 0 ) ;
V_2 -> V_107 = 0 ;
F_60 ( & V_2 -> V_108 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_58 != NULL ) {
F_28 ( & V_2 -> V_34 . V_58 -> V_67 , V_150 ) ;
V_2 -> V_34 . V_58 = NULL ;
}
while ( ! F_31 ( & V_28 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_32 ( V_28 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_28 ( & V_58 -> V_67 , V_150 ) ;
F_33 ( & V_58 -> V_96 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
void F_61 ( struct V_68 * V_114 )
{
struct V_1 * V_2 = F_40 ( V_114 ) ;
struct V_25 * V_101 = & V_2 -> V_101 ;
unsigned long V_29 = 0 ;
F_50 ( 1 , L_50 ,
V_2 -> V_143 ) ;
if ( V_2 -> V_143 -- == 1 )
F_11 ( V_2 ) ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
if ( V_2 -> V_34 . V_102 != NULL ) {
F_28 ( & V_2 -> V_34 . V_102 -> V_67 ,
V_150 ) ;
V_2 -> V_34 . V_102 = NULL ;
}
while ( ! F_31 ( & V_101 -> V_94 ) ) {
struct V_65 * V_58 ;
V_58 = F_32 ( V_101 -> V_94 . V_95 , struct V_65 , V_96 ) ;
F_33 ( & V_58 -> V_96 ) ;
F_28 ( & V_58 -> V_67 , V_150 ) ;
}
F_9 ( & V_2 -> V_33 , V_29 ) ;
V_2 -> V_111 = 0 ;
F_60 ( & V_2 -> V_112 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
F_50 ( 1 , L_51 ) ;
F_63 ( & V_151 ) ;
F_64 ( & V_2 -> V_152 ) ;
F_64 ( & V_2 -> V_153 ) ;
F_65 ( & V_151 ) ;
}
static void F_66 ( unsigned long V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
struct V_25 * V_26 = & V_2 -> V_28 ;
struct V_65 * V_58 ;
unsigned char * V_155 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_58 ;
if ( V_58 != NULL ) {
V_155 = F_37 ( & V_58 -> V_67 , 0 ) ;
memset ( V_155 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_30 ( V_26 , & V_58 ) ;
if ( V_2 -> V_107 == 1 )
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static void F_67 ( unsigned long V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
struct V_25 * V_26 = & V_2 -> V_101 ;
struct V_65 * V_58 ;
unsigned char * V_156 ;
unsigned long V_29 = 0 ;
F_8 ( & V_2 -> V_33 , V_29 ) ;
V_58 = V_2 -> V_34 . V_102 ;
if ( V_58 != NULL ) {
V_156 = F_37 ( & V_58 -> V_67 , 0 ) ;
memset ( V_156 , 0x00 , V_58 -> V_64 ) ;
F_26 ( V_2 , V_26 , V_58 ) ;
}
F_35 ( V_26 , & V_58 ) ;
if ( V_2 -> V_111 == 1 )
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_9 ( & V_2 -> V_33 , V_29 ) ;
}
static int F_68 ( struct V_157 * V_158 )
{
struct V_1 * V_2 = F_69 ( V_158 ) ;
int V_132 ;
F_50 ( 1 ,
L_52 ,
V_127 , V_2 -> V_159 , V_2 -> V_19 ,
V_2 -> V_143 , V_2 -> V_160 ) ;
if ( F_70 ( & V_2 -> V_161 ) )
return - V_162 ;
V_132 = F_71 ( V_158 ) ;
if ( V_132 ) {
F_3 ( L_53 ,
V_127 , V_132 ) ;
F_65 ( & V_2 -> V_161 ) ;
return V_132 ;
}
if ( V_2 -> V_160 == 0 ) {
F_49 ( V_2 ) ;
F_54 ( V_2 ) ;
V_2 -> V_40 = V_48 ;
V_2 -> V_19 |= V_163 ;
}
V_2 -> V_160 ++ ;
F_65 ( & V_2 -> V_161 ) ;
return V_132 ;
}
static int F_72 ( struct V_157 * V_158 )
{
int V_132 ;
struct V_1 * V_2 = F_69 ( V_158 ) ;
struct V_164 * V_152 = F_73 ( V_158 ) ;
F_50 ( 1 ,
L_52 ,
V_127 , V_2 -> V_159 , V_2 -> V_19 ,
V_2 -> V_143 , V_2 -> V_160 ) ;
F_63 ( & V_2 -> V_161 ) ;
if ( V_152 -> V_165 == V_166 && V_2 -> V_107 ) {
V_2 -> V_107 = 0 ;
F_60 ( & V_2 -> V_108 ) ;
} else if ( V_152 -> V_165 == V_167 &&
V_2 -> V_111 ) {
V_2 -> V_111 = 0 ;
F_60 ( & V_2 -> V_112 ) ;
}
if ( V_2 -> V_19 == V_20 )
goto V_168;
if ( V_2 -> V_160 == 1 ) {
F_58 ( & V_2 -> V_146 , 0 , V_169 , V_170 , 0 ) ;
V_2 -> V_159 = 0 ;
V_132 = F_52 ( V_2 -> V_45 , 0 , 0 ) ;
if ( V_132 < 0 )
F_5 ( L_54 ) ;
}
V_168:
F_74 ( V_158 , NULL ) ;
V_2 -> V_160 -- ;
F_65 ( & V_2 -> V_161 ) ;
return 0 ;
}
static void F_75 ( struct V_1 * V_2 )
{
struct V_171 V_172 = {
. V_173 = V_2 -> V_174 ,
. type = V_175 ,
} ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
if ( V_2 -> V_159 )
return;
V_2 -> V_159 = 1 ;
F_1 ( V_2 , 1 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_147 , V_176 , V_2 -> V_177 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_178 , V_179 , & V_172 ) ;
F_1 ( V_2 , 0 ) ;
}
static int F_76 ( struct V_1 * V_2 , unsigned int V_180 ,
struct V_115 * V_181 )
{
int V_132 ;
int V_91 = V_181 -> V_116 . V_124 . V_91 ;
int V_122 = V_181 -> V_116 . V_124 . V_122 ;
if ( V_181 -> V_116 . V_124 . V_182 != V_183 )
return - V_126 ;
if ( V_91 != 720 )
V_91 = 720 ;
if ( V_122 != 480 )
V_122 = 480 ;
V_181 -> V_116 . V_124 . V_91 = V_91 ;
V_181 -> V_116 . V_124 . V_122 = V_122 ;
V_181 -> V_116 . V_124 . V_182 = V_183 ;
V_181 -> V_116 . V_124 . V_90 = V_91 * 2 ;
V_181 -> V_116 . V_124 . V_125 = V_91 * V_122 * 2 ;
V_181 -> V_116 . V_124 . V_184 = V_185 ;
V_181 -> V_116 . V_124 . V_76 = V_77 ;
V_181 -> V_116 . V_124 . V_186 = 0 ;
if ( V_180 == V_187 )
return 0 ;
V_2 -> V_91 = V_91 ;
V_2 -> V_122 = V_122 ;
V_2 -> V_188 = V_91 * V_122 * 2 ;
V_2 -> V_189 = V_91 * V_122 ;
V_2 -> V_90 = V_91 * 2 ;
if ( V_2 -> V_40 == V_41 ) {
F_50 ( 1 , L_56 ) ;
V_132 = F_56 ( V_2 ) ;
if ( V_132 != 0 ) {
F_50 ( 1 , L_57 ) ;
return V_132 ;
}
}
F_49 ( V_2 ) ;
return 0 ;
}
static int F_77 ( struct V_157 * V_157 , void * V_186 ,
struct V_190 * V_191 )
{
struct V_164 * V_152 = F_73 ( V_157 ) ;
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
F_78 ( V_191 -> V_192 , L_58 , sizeof( V_191 -> V_192 ) ) ;
F_78 ( V_191 -> V_193 , V_2 -> V_194 . V_195 , sizeof( V_191 -> V_193 ) ) ;
F_79 ( V_2 -> V_45 , V_191 -> V_196 , sizeof( V_191 -> V_196 ) ) ;
V_191 -> V_197 = V_198 |
V_199 |
V_200 |
V_201 ;
if ( V_152 -> V_165 == V_166 )
V_191 -> V_197 |= V_202 ;
else
V_191 -> V_197 |= V_203 ;
V_191 -> V_204 = V_191 -> V_197 | V_205 |
V_203 | V_202 ;
return 0 ;
}
static int F_80 ( struct V_157 * V_157 , void * V_186 ,
struct V_206 * V_172 )
{
if ( V_172 -> V_207 )
return - V_126 ;
F_50 ( 1 , L_59 , V_127 ) ;
V_172 -> type = V_71 ;
strcpy ( V_172 -> V_208 , L_60 ) ;
V_172 -> V_29 = 0 ;
V_172 -> V_182 = V_183 ;
return 0 ;
}
static int F_81 ( struct V_157 * V_157 , void * V_186 ,
struct V_115 * V_172 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_172 -> V_116 . V_124 . V_91 = V_2 -> V_91 ;
V_172 -> V_116 . V_124 . V_122 = V_2 -> V_122 ;
V_172 -> V_116 . V_124 . V_182 = V_183 ;
V_172 -> V_116 . V_124 . V_90 = V_2 -> V_90 ;
V_172 -> V_116 . V_124 . V_125 = V_2 -> V_188 ;
V_172 -> V_116 . V_124 . V_184 = V_185 ;
V_172 -> V_116 . V_124 . V_76 = V_77 ;
V_172 -> V_116 . V_124 . V_186 = 0 ;
return 0 ;
}
static int F_82 ( struct V_157 * V_157 , void * V_186 ,
struct V_115 * V_172 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
return F_76 ( V_2 , V_187 , V_172 ) ;
}
static int F_83 ( struct V_157 * V_157 , void * V_186 ,
struct V_115 * V_172 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
int V_55 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_55 = F_4 ( V_2 ) ;
if ( V_55 < 0 )
return V_55 ;
if ( F_84 ( & V_2 -> V_209 ) ) {
F_5 ( L_61 , V_127 ) ;
V_55 = - V_138 ;
goto V_210;
}
V_55 = F_76 ( V_2 , V_211 , V_172 ) ;
V_210:
return V_55 ;
}
static int F_85 ( struct V_157 * V_157 , void * V_186 , T_1 V_212 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
if ( V_212 == V_2 -> V_177 )
return 0 ;
if ( V_2 -> V_143 > 0 )
return - V_138 ;
V_2 -> V_177 = V_212 ;
F_75 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_147 , V_176 , V_212 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_86 ( struct V_157 * V_157 , void * V_186 , T_1 * V_212 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
* V_212 = V_2 -> V_177 ;
return 0 ;
}
static int F_87 ( struct V_157 * V_157 , void * V_186 ,
struct V_213 * V_214 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
unsigned int V_215 ;
static const char * V_216 [] = {
[ V_217 ] = L_62 ,
[ V_218 ] = L_63 ,
[ V_219 ] = L_64 ,
[ V_220 ] = L_65 ,
[ V_221 ] = L_66 ,
[ V_222 ] = L_67 ,
[ V_223 ] = L_68
} ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_215 = V_214 -> V_207 ;
if ( V_215 >= V_224 )
return - V_126 ;
if ( F_88 ( V_215 ) . type == 0 )
return - V_126 ;
V_214 -> V_207 = V_215 ;
strcpy ( V_214 -> V_195 , V_216 [ F_88 ( V_215 ) . type ] ) ;
if ( ( F_88 ( V_215 ) . type == V_221 ) ||
( F_88 ( V_215 ) . type == V_220 ) ) {
V_214 -> type |= V_225 ;
V_214 -> V_226 = 1 ;
} else {
V_214 -> type |= V_227 ;
V_214 -> V_226 = 2 ;
}
V_214 -> V_177 = V_2 -> V_152 . V_228 ;
return 0 ;
}
static int F_89 ( struct V_157 * V_157 , void * V_186 , unsigned int * V_30 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
* V_30 = V_2 -> V_229 ;
return 0 ;
}
static void F_90 ( struct V_1 * V_2 , int V_207 )
{
int V_30 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
switch ( F_88 ( V_207 ) . type ) {
case V_219 :
V_2 -> V_230 = V_219 ;
V_2 -> V_231 = 1 ;
break;
case V_218 :
V_2 -> V_230 = V_218 ;
V_2 -> V_231 = 1 ;
break;
case V_221 :
V_2 -> V_230 = V_221 ;
V_2 -> V_231 = 0 ;
break;
default:
F_50 ( 1 , L_69 ,
F_88 ( V_207 ) . type ) ;
break;
}
F_58 ( & V_2 -> V_146 , 0 , V_147 , V_232 ,
F_88 ( V_207 ) . V_233 , 0 , 0 ) ;
for ( V_30 = 0 ; V_30 < V_224 ; V_30 ++ ) {
int V_234 = 0 ;
if ( F_88 ( V_30 ) . V_235 == NULL )
continue;
if ( V_30 == V_207 )
V_234 = 1 ;
else
V_234 = 0 ;
if ( V_234 ) {
( F_88 ( V_30 ) . V_235 ) ( V_2 , V_234 ) ;
} else {
if ( ( F_88 ( V_30 ) . V_235 ) !=
( ( F_88 ( V_207 ) . V_235 ) ) ) {
( F_88 ( V_30 ) . V_235 ) ( V_2 , V_234 ) ;
}
}
}
F_58 ( & V_2 -> V_146 , 0 , V_236 , V_232 ,
F_88 ( V_207 ) . V_237 , 0 , 0 ) ;
}
static int F_91 ( struct V_157 * V_157 , void * V_186 , unsigned int V_207 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_70 , V_127 ,
V_207 ) ;
if ( V_207 >= V_224 )
return - V_126 ;
if ( F_88 ( V_207 ) . type == 0 )
return - V_126 ;
V_2 -> V_229 = V_207 ;
F_90 ( V_2 , V_207 ) ;
return 0 ;
}
static int F_92 ( struct V_157 * V_157 , void * V_186 , struct V_238 * V_239 )
{
if ( V_239 -> V_207 > 1 )
return - V_126 ;
F_50 ( 1 , L_59 , V_127 ) ;
if ( V_239 -> V_207 == 0 )
strcpy ( V_239 -> V_195 , L_66 ) ;
else
strcpy ( V_239 -> V_195 , L_71 ) ;
V_239 -> V_240 = V_241 ;
return 0 ;
}
static int F_93 ( struct V_157 * V_157 , void * V_186 , struct V_238 * V_239 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_239 -> V_207 = V_2 -> V_231 ;
if ( V_239 -> V_207 == 0 )
strcpy ( V_239 -> V_195 , L_66 ) ;
else
strcpy ( V_239 -> V_195 , L_71 ) ;
V_239 -> V_240 = V_241 ;
return 0 ;
}
static int F_94 ( struct V_157 * V_157 , void * V_186 , const struct V_238 * V_239 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
if ( V_239 -> V_207 != V_2 -> V_231 )
return - V_126 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
return 0 ;
}
static int F_95 ( struct V_157 * V_157 , void * V_186 , struct V_242 * V_243 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
if ( V_243 -> V_207 != 0 )
return - V_126 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
strcpy ( V_243 -> V_195 , L_72 ) ;
F_75 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_178 , V_244 , V_243 ) ;
F_1 ( V_2 , 0 ) ;
return 0 ;
}
static int F_96 ( struct V_157 * V_157 , void * V_186 ,
const struct V_242 * V_243 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
if ( V_243 -> V_207 != 0 )
return - V_126 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
F_75 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_178 , V_245 , V_243 ) ;
F_1 ( V_2 , 0 ) ;
F_50 ( 1 , L_73 , V_243 -> signal ,
V_243 -> V_246 ) ;
return 0 ;
}
static int F_97 ( struct V_157 * V_157 , void * V_186 ,
struct V_171 * V_247 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
if ( V_247 -> V_178 != 0 )
return - V_126 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_247 -> V_173 = V_2 -> V_174 ;
return 0 ;
}
static int F_98 ( struct V_157 * V_157 , void * V_186 ,
const struct V_171 * V_247 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
struct V_171 V_248 = * V_247 ;
if ( V_247 -> V_178 != 0 )
return - V_126 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
F_75 ( V_2 ) ;
F_1 ( V_2 , 1 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_178 , V_179 , V_247 ) ;
F_58 ( & V_2 -> V_146 , 0 , V_178 , V_249 , & V_248 ) ;
V_2 -> V_174 = V_248 . V_173 ;
F_1 ( V_2 , 0 ) ;
F_54 ( V_2 ) ;
return 0 ;
}
static int F_99 ( struct V_157 * V_157 , void * V_186 ,
struct V_115 * V_181 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_181 -> V_116 . V_250 . V_251 = V_2 -> V_99 ;
V_181 -> V_116 . V_250 . V_252 = V_253 ;
V_181 -> V_116 . V_250 . V_63 = 0 ;
V_181 -> V_116 . V_250 . V_29 = 0 ;
V_181 -> V_116 . V_250 . V_254 = 6750000 * 4 / 2 ;
V_181 -> V_116 . V_250 . V_142 [ 0 ] = V_2 -> V_100 ;
V_181 -> V_116 . V_250 . V_142 [ 1 ] = V_2 -> V_100 ;
V_181 -> V_116 . V_250 . V_255 [ 0 ] = 21 ;
V_181 -> V_116 . V_250 . V_255 [ 1 ] = 284 ;
memset ( V_181 -> V_116 . V_250 . V_256 , 0 , sizeof( V_181 -> V_116 . V_250 . V_256 ) ) ;
return 0 ;
}
static int F_100 ( struct V_157 * V_157 , void * V_186 ,
struct V_257 * V_258 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
if ( V_258 -> type != V_71 )
return - V_126 ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_258 -> V_259 . V_260 = 0 ;
V_258 -> V_259 . V_261 = 0 ;
V_258 -> V_259 . V_91 = V_2 -> V_91 ;
V_258 -> V_259 . V_122 = V_2 -> V_122 ;
V_258 -> V_262 = V_258 -> V_259 ;
V_258 -> V_263 . V_264 = 54 ;
V_258 -> V_263 . V_265 = 59 ;
return 0 ;
}
static int F_101 ( struct V_157 * V_157 , void * V_186 ,
struct V_266 * V_267 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
V_267 -> V_3 = F_102 ( V_2 , V_267 -> V_267 ) ;
V_267 -> V_123 = 1 ;
return 0 ;
}
static int F_103 ( struct V_157 * V_157 , void * V_186 ,
const struct V_266 * V_267 )
{
struct V_1 * V_2 = F_69 ( V_157 ) ;
F_50 ( 1 , L_55 , V_127 ,
V_2 -> V_159 , V_2 -> V_19 ) ;
return F_48 ( V_2 , V_267 -> V_267 , V_267 -> V_3 ) ;
}
static int F_104 ( struct V_157 * V_157 , void * V_268 )
{
struct V_164 * V_152 = F_73 ( V_157 ) ;
F_50 ( 1 , L_59 , V_127 ) ;
F_105 ( V_157 , V_268 ) ;
F_58 ( V_152 -> V_146 , 0 , V_169 , V_269 ) ;
return 0 ;
}
void F_106 ( struct V_1 * V_2 )
{
struct V_24 * V_24 ;
int V_30 ;
F_5 ( L_74 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_5 ( L_75 ) ;
F_53 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_24 = V_2 -> V_34 . V_24 [ V_30 ] ;
if ( V_24 ) {
if ( ! F_12 () )
F_13 ( V_24 ) ;
else
F_14 ( V_24 ) ;
}
}
}
if ( V_2 -> V_107 )
F_60 ( & V_2 -> V_108 ) ;
if ( V_2 -> V_111 )
F_60 ( & V_2 -> V_112 ) ;
}
void F_107 ( struct V_1 * V_2 )
{
int V_30 , V_55 ;
F_5 ( L_76 ) ;
if ( V_2 -> V_40 == V_41 ) {
F_56 ( V_2 ) ;
F_75 ( V_2 ) ;
}
if ( V_2 -> V_107 )
F_38 ( & V_2 -> V_108 , V_109 + ( V_110 / 10 ) ) ;
if ( V_2 -> V_111 )
F_38 ( & V_2 -> V_112 , V_109 + ( V_110 / 10 ) ) ;
F_47 ( V_2 ) ;
F_49 ( V_2 ) ;
if ( ! ( V_2 -> V_40 == V_41 ) ) {
F_54 ( V_2 ) ;
for ( V_30 = 0 ; V_30 < V_2 -> V_34 . V_43 ; V_30 ++ ) {
V_55 = F_10 ( V_2 -> V_34 . V_24 [ V_30 ] , V_39 ) ;
if ( V_55 ) {
F_3 ( L_27 ,
V_30 , V_55 ) ;
F_11 ( V_2 ) ;
}
}
}
}
static int F_108 ( struct V_1 * V_2 )
{
int V_55 ;
struct V_68 * V_69 ;
V_69 = & V_2 -> V_209 ;
V_69 -> type = V_71 ;
V_69 -> V_270 = V_271 | V_272 | V_273 | V_274 ;
V_69 -> V_275 = V_276 ;
V_69 -> V_277 = V_2 ;
V_69 -> V_278 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_279 ;
V_69 -> V_280 = & V_281 ;
V_55 = F_109 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
V_69 = & V_2 -> V_282 ;
V_69 -> type = V_149 ;
V_69 -> V_270 = V_271 | V_272 | V_273 | V_274 ;
V_69 -> V_275 = V_276 ;
V_69 -> V_277 = V_2 ;
V_69 -> V_278 = sizeof( struct V_65 ) ;
V_69 -> V_6 = & V_283 ;
V_69 -> V_280 = & V_281 ;
V_55 = F_109 ( V_69 ) ;
if ( V_55 < 0 )
return V_55 ;
return 0 ;
}
int F_110 ( struct V_1 * V_2 ,
struct V_130 * V_284 )
{
int V_285 = - V_57 ;
struct V_286 * V_287 ;
struct V_288 * V_289 ;
int V_30 , V_132 ;
F_50 ( 1 , L_77 ,
V_284 -> V_135 -> V_136 . V_290 ) ;
V_285 = F_52 ( V_2 -> V_45 ,
V_284 -> V_135 -> V_136 . V_290 , 5 ) ;
if ( V_285 != 0 ) {
F_5 ( L_78 ) ;
return V_285 ;
}
V_287 = V_284 -> V_135 ;
for ( V_30 = 0 ; V_30 < V_287 -> V_136 . V_291 ; V_30 ++ ) {
V_289 = & V_287 -> V_289 [ V_30 ] . V_136 ;
if ( ( ( V_289 -> V_292 & V_293 )
== V_294 ) &&
( ( V_289 -> V_295 & V_296 )
== V_297 ) ) {
T_2 V_215 = F_111 ( V_289 -> V_298 ) ;
V_2 -> V_50 = ( V_215 & 0x07ff ) *
( ( ( V_215 & 0x1800 ) >> 11 ) + 1 ) ;
V_2 -> V_59 = V_289 -> V_292 ;
F_50 ( 1 ,
L_79 ,
V_2 -> V_59 , V_2 -> V_50 ) ;
}
}
if ( ! ( V_2 -> V_59 ) ) {
F_5 ( L_80 ) ;
return - V_21 ;
}
F_112 ( & V_2 -> V_299 ) ;
F_113 ( & V_2 -> V_33 ) ;
F_114 ( & V_2 -> V_28 . V_94 ) ;
F_114 ( & V_2 -> V_101 . V_94 ) ;
F_115 ( & V_2 -> V_108 , F_66 ,
( unsigned long ) V_2 ) ;
F_115 ( & V_2 -> V_112 , F_67 ,
( unsigned long ) V_2 ) ;
V_2 -> V_91 = V_300 ;
V_2 -> V_122 = V_301 ;
V_2 -> V_189 = V_2 -> V_91 * V_2 -> V_122 ;
V_2 -> V_188 = V_2 -> V_189 << 1 ;
V_2 -> V_90 = V_2 -> V_91 << 1 ;
V_2 -> V_99 = 720 ;
V_2 -> V_100 = 1 ;
V_2 -> V_231 = 0 ;
V_2 -> V_174 = 960 ;
V_2 -> V_177 = V_302 ;
F_90 ( V_2 , 0 ) ;
F_116 ( & V_2 -> V_303 ) ;
F_116 ( & V_2 -> V_304 ) ;
V_2 -> V_152 = V_305 ;
V_2 -> V_152 . V_146 = & V_2 -> V_146 ;
V_2 -> V_152 . V_161 = & V_2 -> V_161 ;
V_2 -> V_152 . V_306 = & V_2 -> V_209 ;
V_2 -> V_152 . V_306 -> V_161 = & V_2 -> V_303 ;
strcpy ( V_2 -> V_152 . V_195 , L_81 ) ;
V_2 -> V_153 = V_305 ;
V_2 -> V_153 . V_146 = & V_2 -> V_146 ;
V_2 -> V_153 . V_161 = & V_2 -> V_161 ;
V_2 -> V_153 . V_306 = & V_2 -> V_282 ;
V_2 -> V_153 . V_306 -> V_161 = & V_2 -> V_304 ;
strcpy ( V_2 -> V_153 . V_195 , L_82 ) ;
V_285 = F_108 ( V_2 ) ;
if ( V_285 != 0 ) {
F_50 ( 1 , L_83 ,
V_285 ) ;
return - V_21 ;
}
F_117 ( & V_2 -> V_152 , V_2 ) ;
V_285 = F_118 ( & V_2 -> V_152 , V_166 , - 1 ) ;
if ( V_285 != 0 ) {
F_50 ( 1 , L_84 ,
V_285 ) ;
V_132 = - V_21 ;
goto V_307;
}
F_117 ( & V_2 -> V_153 , V_2 ) ;
V_285 = F_118 ( & V_2 -> V_153 , V_167 , - 1 ) ;
if ( V_285 != 0 ) {
F_50 ( 1 , L_85 ,
V_285 ) ;
V_132 = - V_21 ;
goto V_308;
}
F_50 ( 1 , L_86 , V_127 ) ;
return 0 ;
V_308:
F_64 ( & V_2 -> V_152 ) ;
V_307:
F_119 ( & V_2 -> V_209 ) ;
F_119 ( & V_2 -> V_282 ) ;
return V_132 ;
}
