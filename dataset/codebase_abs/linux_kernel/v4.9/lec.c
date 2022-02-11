static inline void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
if ( F_4 ( & V_2 -> V_3 ) )
F_5 ( V_2 ) ;
}
static void F_6 ( struct V_4 * V_5 , struct V_6 * V_7 )
{
char * V_8 ;
struct V_9 * V_10 ;
V_8 = V_5 -> V_11 + V_5 -> V_7 -> V_12 ;
if ( * V_8 ++ == 0x42 && * V_8 ++ == 0x42 && * V_8 ++ == 0x03 ) {
struct V_13 * V_14 ;
struct V_4 * V_15 ;
struct V_16 * V_17 ;
V_15 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( V_15 == NULL )
return;
V_15 -> V_19 = sizeof( struct V_16 ) ;
V_17 = (struct V_16 * ) V_15 -> V_11 ;
V_17 -> type = V_20 ;
V_8 += 4 ;
V_17 -> V_21 . V_22 . V_23 = * V_8 & 0x01 ;
V_10 = F_8 ( V_7 ) ;
F_9 ( V_10 -> V_24 , V_15 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_15 ) ;
V_14 -> V_27 ( V_14 ) ;
}
}
static int F_12 ( struct V_6 * V_7 )
{
F_13 ( V_7 ) ;
return 0 ;
}
static void
F_14 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_7 ;
F_15 ( V_5 ) -> V_29 = V_29 ;
F_15 ( V_5 ) -> V_30 = V_29 -> V_30 ;
F_16 ( V_5 -> V_25 , & F_10 ( V_29 ) -> V_31 ) ;
if ( V_29 -> V_32 ( V_29 , V_5 ) < 0 ) {
V_7 -> V_33 . V_34 ++ ;
return;
}
V_7 -> V_33 . V_35 ++ ;
V_7 -> V_33 . V_36 += V_5 -> V_19 ;
}
static void F_17 ( struct V_6 * V_7 )
{
F_18 ( L_1 , V_7 -> V_37 ) ;
F_19 ( V_7 ) ;
F_20 ( V_7 ) ;
}
static T_1 F_21 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_4 * V_15 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_38 * V_39 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
unsigned char * V_40 ;
int V_41 ;
int V_42 ;
F_22 ( L_2 ) ;
if ( ! V_10 -> V_24 ) {
F_18 ( L_3 , V_7 -> V_37 ) ;
V_7 -> V_33 . V_43 ++ ;
F_23 ( V_7 ) ;
F_24 ( V_5 ) ;
return V_44 ;
}
F_22 ( L_4 ,
( long ) V_5 -> V_45 , ( long ) V_5 -> V_11 , ( long ) F_25 ( V_5 ) ,
( long ) F_26 ( V_5 ) ) ;
#if F_27 ( V_46 )
if ( memcmp ( V_5 -> V_11 , V_47 , sizeof( V_47 ) ) == 0 )
F_6 ( V_5 , V_7 ) ;
#endif
if ( F_28 ( V_5 ) < 2 ) {
F_22 ( L_5 ) ;
V_15 = F_29 ( V_5 , V_48 ) ;
if ( F_30 ( ! V_15 ) ) {
F_24 ( V_5 ) ;
return V_44 ;
}
F_31 ( V_5 ) ;
V_5 = V_15 ;
}
F_32 ( V_5 , 2 ) ;
V_39 = (struct V_38 * ) V_5 -> V_11 ;
V_39 -> V_49 = F_33 ( V_10 -> V_50 ) ;
#if V_51 >= 2
#define F_34 99
#elif V_51 >= 1
#define F_34 30
#endif
#if V_51 >= 1
F_35 ( V_52 L_6 ,
V_7 -> V_37 , V_5 -> V_19 , V_10 -> V_50 ) ;
F_36 ( V_52 , L_7 , V_53 , 16 , 1 ,
V_5 -> V_11 , F_37 ( V_5 -> V_19 , F_34 ) , true ) ;
#endif
V_41 = V_54 ;
if ( V_5 -> V_19 < V_41 ) {
if ( ( V_5 -> V_19 + F_38 ( V_5 ) ) < V_41 ) {
V_15 = F_39 ( V_5 , 0 ,
V_41 - V_5 -> V_25 ,
V_18 ) ;
F_40 ( V_5 ) ;
if ( V_15 == NULL ) {
V_7 -> V_33 . V_34 ++ ;
return V_44 ;
}
V_5 = V_15 ;
}
F_41 ( V_5 , V_41 - V_5 -> V_19 ) ;
}
V_42 = 0 ;
V_40 = V_39 -> V_55 ;
V_2 = NULL ;
V_29 = F_42 ( V_10 , V_40 , V_42 , & V_2 ) ;
F_22 ( L_8 ,
V_7 -> V_37 , V_29 , V_29 ? V_29 -> V_56 : 0 , V_2 ) ;
if ( ! V_29 || ! F_43 ( V_57 , & V_29 -> V_56 ) ) {
if ( V_2 && ( V_2 -> V_58 . V_59 < V_60 ) ) {
F_22 ( L_9 ,
V_7 -> V_37 , V_39 -> V_55 ) ;
F_11 ( & V_2 -> V_58 , V_5 ) ;
} else {
F_22 ( L_10 ,
V_7 -> V_37 , V_39 -> V_55 ) ;
V_7 -> V_33 . V_34 ++ ;
F_40 ( V_5 ) ;
}
goto V_61;
}
#if V_51 > 0
F_35 ( V_52 L_11 ,
V_7 -> V_37 , V_29 -> V_62 , V_29 -> V_63 ) ;
#endif
while ( V_2 && ( V_15 = F_44 ( & V_2 -> V_58 ) ) ) {
F_22 ( L_12 , V_39 -> V_55 ) ;
F_14 ( V_29 , V_15 ) ;
}
F_14 ( V_29 , V_5 ) ;
if ( ! F_45 ( V_29 , 0 ) ) {
struct V_64 * V_65 = F_46 ( V_29 ) ;
V_65 -> V_66 = 1 ;
F_23 ( V_7 ) ;
if ( F_45 ( V_29 , 0 ) )
F_20 ( V_7 ) ;
}
V_61:
if ( V_2 )
F_3 ( V_2 ) ;
F_19 ( V_7 ) ;
return V_44 ;
}
static int F_47 ( struct V_6 * V_7 )
{
F_23 ( V_7 ) ;
return 0 ;
}
static int F_48 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_56 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_67 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_68 ;
char * V_69 ;
F_49 ( V_5 -> V_25 , & F_10 ( V_29 ) -> V_31 ) ;
V_17 = (struct V_16 * ) V_5 -> V_11 ;
V_69 = V_5 -> V_11 ;
V_69 += sizeof( struct V_16 ) ;
F_22 ( L_13 , V_7 -> V_37 , V_17 -> type ) ;
switch ( V_17 -> type ) {
case V_70 :
for ( V_68 = 0 ; V_68 < 6 ; V_68 ++ )
V_7 -> V_71 [ V_68 ] = V_17 -> V_21 . V_22 . V_72 [ V_68 ] ;
break;
case V_73 :
for ( V_68 = 0 ; V_68 < 6 ; V_68 ++ )
V_7 -> V_71 [ V_68 ] = 0 ;
break;
case V_74 :
F_50 ( V_10 , V_17 -> V_21 . V_22 . V_75 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_20 :
V_10 -> V_76 = V_17 -> V_21 . V_22 . V_23 ;
break;
case V_77 :
F_51 ( V_10 , V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_78 :
F_52 ( & V_10 -> V_79 , V_56 ) ;
V_2 = F_53 ( V_10 , V_17 -> V_21 . V_22 . V_72 ) ;
F_54 ( V_10 , V_2 ) ;
F_55 ( & V_10 -> V_79 , V_56 ) ;
if ( V_17 -> V_21 . V_22 . V_80 )
break;
case V_81 :
F_56 ( V_10 , V_17 -> V_21 . V_22 . V_72 ,
V_17 -> V_21 . V_22 . V_75 ,
V_17 -> V_21 . V_22 . V_23 ,
V_17 -> V_21 . V_22 . V_82 ) ;
F_22 ( L_14 ) ;
if ( V_17 -> V_83 != 0 ) {
F_22 ( L_15 ,
V_17 -> V_83 ) ;
F_57 ( V_7 , V_17 -> V_21 . V_22 . V_72 ,
V_69 , V_17 -> V_83 ) ;
}
break;
case V_84 :
V_10 -> V_85 =
V_17 -> V_21 . V_86 . V_85 ;
V_10 -> V_87 =
( V_17 -> V_21 . V_86 . V_87 * V_88 ) ;
V_10 -> V_89 = V_17 -> V_21 . V_86 . V_89 ;
V_10 -> V_90 = ( V_17 -> V_21 . V_86 . V_90 * V_88 ) ;
V_10 -> V_91 =
( V_17 -> V_21 . V_86 . V_91 * V_88 ) ;
V_10 -> V_92 =
( V_17 -> V_21 . V_86 . V_92 * V_88 ) ;
V_10 -> V_93 = ( V_17 -> V_21 . V_86 . V_93 * V_88 ) ;
V_10 -> V_94 =
( V_17 -> V_21 . V_86 . V_94 * V_88 ) ;
V_10 -> V_95 = V_17 -> V_21 . V_86 . V_95 ;
V_10 -> V_96 = NULL ;
if ( V_10 -> V_95 > 1 )
V_10 -> V_96 = & V_96 ;
F_58 () ;
if ( F_59 ( V_7 , V_17 -> V_21 . V_86 . V_97 ) )
F_18 ( L_16 ,
V_7 -> V_37 , V_17 -> V_21 . V_86 . V_97 ) ;
F_60 () ;
V_10 -> V_98 = V_17 -> V_21 . V_86 . V_98 ;
break;
case V_99 :
F_61 ( V_10 , V_17 -> V_21 . V_22 . V_75 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_100 :
V_10 -> V_50 =
( unsigned short ) ( 0xffff & V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_101 :
#if F_27 ( V_46 )
{
F_22 ( L_17 ,
V_7 -> V_37 , V_17 -> V_21 . V_102 . V_72 ) ;
if ( V_103 == NULL )
break;
if ( V_103 ( V_7 , V_17 -> V_21 . V_102 . V_72 ) ) {
struct V_4 * V_15 ;
struct V_13 * V_14 ;
F_22 ( L_18 ,
V_7 -> V_37 ) ;
V_15 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( V_15 == NULL )
break;
V_15 -> V_19 = sizeof( struct V_16 ) ;
F_62 ( V_15 , V_17 , sizeof( * V_17 ) ) ;
F_9 ( V_10 -> V_24 , V_15 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_15 ) ;
V_14 -> V_27 ( V_14 ) ;
}
}
#endif
break;
default:
F_18 ( L_19 , V_7 -> V_37 , V_17 -> type ) ;
F_40 ( V_5 ) ;
return - V_104 ;
}
F_40 ( V_5 ) ;
return 0 ;
}
static void F_63 ( struct V_28 * V_29 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_67 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
V_10 -> V_24 = NULL ;
F_23 ( V_7 ) ;
F_64 ( V_10 ) ;
if ( F_65 ( & F_10 ( V_29 ) -> V_26 ) )
F_18 ( L_20 , V_7 -> V_37 ) ;
while ( ( V_5 = F_44 ( & F_10 ( V_29 ) -> V_26 ) ) ) {
F_66 ( V_29 , V_5 -> V_25 ) ;
F_40 ( V_5 ) ;
}
F_18 ( L_21 , V_7 -> V_37 ) ;
F_67 ( V_105 ) ;
}
static int
F_68 ( struct V_9 * V_10 , T_2 type ,
const unsigned char * V_72 , const unsigned char * V_75 ,
struct V_4 * V_11 )
{
struct V_13 * V_14 ;
struct V_4 * V_5 ;
struct V_16 * V_17 ;
if ( ! V_10 || ! V_10 -> V_24 )
return - 1 ;
V_5 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( ! V_5 )
return - 1 ;
V_5 -> V_19 = sizeof( struct V_16 ) ;
V_17 = (struct V_16 * ) V_5 -> V_11 ;
memset ( V_17 , 0 , sizeof( struct V_16 ) ) ;
V_17 -> type = type ;
if ( V_11 != NULL )
V_17 -> V_83 = V_11 -> V_19 ;
if ( V_72 )
F_69 ( V_17 -> V_21 . V_22 . V_72 , V_72 ) ;
else
V_17 -> V_21 . V_22 . V_82 = 1 ;
if ( V_75 )
memcpy ( & V_17 -> V_21 . V_22 . V_75 , V_75 , V_106 ) ;
F_9 ( V_10 -> V_24 , V_5 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 ) ;
if ( V_11 != NULL ) {
F_22 ( L_22 , V_11 -> V_19 ) ;
F_9 ( V_10 -> V_24 , V_11 -> V_25 ) ;
F_11 ( & V_14 -> V_26 , V_11 ) ;
V_14 -> V_27 ( V_14 ) ;
}
return 0 ;
}
static int F_70 ( struct V_6 * V_7 , int V_107 )
{
if ( ( V_107 < 68 ) || ( V_107 > 18190 ) )
return - V_104 ;
V_7 -> V_97 = V_107 ;
return 0 ;
}
static void F_71 ( struct V_6 * V_7 )
{
}
static int F_72 ( struct V_28 * V_29 )
{
return ( ( V_29 -> V_108 . V_109 [ 0 ] . V_110 . V_111 . V_112 [ 4 ] == V_113 ) ||
( V_29 -> V_108 . V_109 [ 0 ] . V_110 . V_111 . V_112 [ 4 ] == V_114 ) ) ;
}
static void F_73 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_56 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_67 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
#if V_51 > 0
F_35 ( V_52 L_23 ,
V_7 -> V_37 , V_29 -> V_62 , V_29 -> V_63 ) ;
#endif
if ( ! V_5 ) {
F_22 ( L_24 , V_7 -> V_37 ) ;
F_74 ( V_10 , V_29 ) ;
return;
}
#if V_51 >= 2
#define F_75 99
#elif V_51 >= 1
#define F_75 30
#endif
#if V_51 > 0
F_35 ( V_52 L_25 ,
V_7 -> V_37 , V_5 -> V_19 , V_10 -> V_50 ) ;
F_36 ( V_52 , L_7 , V_53 , 16 , 1 ,
V_5 -> V_11 , F_37 ( F_75 , V_5 -> V_19 ) , true ) ;
#endif
if ( memcmp ( V_5 -> V_11 , V_115 , 4 ) == 0 ) {
struct V_13 * V_14 = F_10 ( V_29 ) ;
F_22 ( L_26 , V_7 -> V_37 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 ) ;
} else {
struct V_1 * V_2 ;
unsigned char * V_116 , * V_40 ;
F_66 ( V_29 , V_5 -> V_25 ) ;
if ( * ( V_117 * ) V_5 -> V_11 == F_33 ( V_10 -> V_50 ) ||
! V_10 -> V_24 || ! ( V_7 -> V_56 & V_118 ) ) {
F_22 ( L_27 ) ;
F_40 ( V_5 ) ;
return;
}
V_40 = ( (struct V_38 * ) V_5 -> V_11 ) -> V_55 ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
if ( F_72 ( V_29 ) ) {
V_116 = ( (struct V_38 * ) V_5 -> V_11 ) -> V_119 ;
V_2 = F_53 ( V_10 , V_116 ) ;
if ( V_2 && V_2 -> V_29 != V_29 ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
if ( ! ( V_40 [ 0 ] & 0x01 ) &&
! V_10 -> V_98 &&
memcmp ( V_40 , V_7 -> V_71 , V_7 -> V_120 ) ) {
F_40 ( V_5 ) ;
return;
}
if ( ! F_76 ( & V_10 -> V_121 ) )
F_77 ( V_10 , V_29 , V_5 ) ;
F_78 ( V_5 , 2 ) ;
V_5 -> V_122 = F_79 ( V_5 , V_7 ) ;
V_7 -> V_33 . V_123 ++ ;
V_7 -> V_33 . V_124 += V_5 -> V_19 ;
memset ( F_15 ( V_5 ) , 0 , sizeof( struct V_125 ) ) ;
F_80 ( V_5 ) ;
}
}
static void F_81 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
struct V_64 * V_65 = F_46 ( V_29 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_65 == NULL ) {
F_18 ( L_28 ) ;
return;
}
V_65 -> V_126 ( V_29 , V_5 ) ;
if ( V_65 -> V_66 && F_45 ( V_29 , 0 ) ) {
V_65 -> V_66 = 0 ;
if ( F_82 ( V_7 ) && F_83 ( V_7 ) )
F_20 ( V_7 ) ;
}
}
static int F_84 ( struct V_28 * V_29 , void T_3 * V_127 )
{
struct V_64 * V_65 ;
int V_128 ;
struct V_129 V_130 ;
V_128 = F_85 ( & V_130 , V_127 , sizeof( struct V_129 ) ) ;
if ( V_128 != 0 )
F_18 ( L_29 , V_128 ) ;
if ( V_130 . V_131 < 0 || V_130 . V_131 >= V_132 ||
! V_133 [ V_130 . V_131 ] )
return - V_104 ;
V_65 = F_86 ( sizeof( struct V_64 ) , V_134 ) ;
if ( ! V_65 )
return - V_135 ;
V_65 -> V_66 = 0 ;
V_65 -> V_126 = V_29 -> V_136 ;
V_29 -> V_137 = V_65 ;
V_29 -> V_136 = F_81 ;
F_87 ( F_8 ( V_133 [ V_130 . V_131 ] ) ,
& V_130 , V_29 , V_29 -> V_138 ) ;
V_29 -> V_67 = V_133 [ V_130 . V_131 ] ;
V_29 -> V_138 = F_73 ;
return 0 ;
}
static int F_88 ( struct V_28 * V_29 , int V_127 )
{
if ( V_127 < 0 || V_127 >= V_132 || ! V_133 [ V_127 ] )
return - V_104 ;
V_29 -> V_67 = V_133 [ V_127 ] ;
return F_89 ( F_8 ( V_133 [ V_127 ] ) , V_29 ) ;
}
static int F_90 ( struct V_28 * V_29 , int V_127 )
{
int V_68 ;
struct V_9 * V_10 ;
if ( V_127 < 0 )
V_68 = 0 ;
else
V_68 = V_127 ;
if ( V_127 >= V_132 )
return - V_104 ;
if ( ! V_133 [ V_68 ] ) {
int V_139 ;
V_139 = sizeof( struct V_9 ) ;
V_133 [ V_68 ] = F_91 ( V_139 ) ;
if ( ! V_133 [ V_68 ] )
return - V_135 ;
V_133 [ V_68 ] -> V_140 = & V_141 ;
snprintf ( V_133 [ V_68 ] -> V_37 , V_142 , L_30 , V_68 ) ;
if ( F_92 ( V_133 [ V_68 ] ) ) {
F_93 ( V_133 [ V_68 ] ) ;
return - V_104 ;
}
V_10 = F_8 ( V_133 [ V_68 ] ) ;
} else {
V_10 = F_8 ( V_133 [ V_68 ] ) ;
if ( V_10 -> V_24 )
return - V_143 ;
}
F_94 ( V_10 ) ;
V_10 -> V_144 = V_68 ;
V_10 -> V_24 = V_29 ;
V_29 -> V_7 = & V_145 ;
F_95 ( F_10 ( V_29 ) ) ;
V_29 -> V_67 = V_133 [ V_68 ] ;
F_96 ( V_146 , & V_29 -> V_56 ) ;
F_96 ( V_57 , & V_29 -> V_56 ) ;
V_10 -> V_85 = 1 ;
V_10 -> V_87 = ( 1 * V_88 ) ;
V_10 -> V_147 = ( 1200 * V_88 ) ;
V_10 -> V_89 = 1 ;
V_10 -> V_90 = ( 300 * V_88 ) ;
V_10 -> V_91 = ( 15 * V_88 ) ;
V_10 -> V_76 = 0 ;
V_10 -> V_92 = ( 1 * V_88 ) ;
V_10 -> V_93 = ( 4 * V_88 ) ;
V_10 -> V_94 = ( 6 * V_88 ) ;
if ( V_133 [ V_68 ] -> V_56 & V_118 )
F_13 ( V_133 [ V_68 ] ) ;
F_97 ( V_105 ) ;
return V_68 ;
}
static const char * F_98 ( unsigned char V_148 )
{
static const char * const V_149 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36
} ;
if ( V_148 > V_150 )
V_148 = 3 ;
return V_149 [ V_148 ] ;
}
static void F_99 ( struct V_151 * V_152 , struct V_1 * V_2 )
{
int V_68 ;
for ( V_68 = 0 ; V_68 < V_153 ; V_68 ++ )
F_100 ( V_152 , L_37 , V_2 -> V_72 [ V_68 ] & 0xff ) ;
F_100 ( V_152 , L_38 ) ;
for ( V_68 = 0 ; V_68 < V_106 ; V_68 ++ )
F_100 ( V_152 , L_37 , V_2 -> V_75 [ V_68 ] & 0xff ) ;
F_100 ( V_152 , L_39 , F_98 ( V_2 -> V_148 ) ,
V_2 -> V_56 & 0xffff ) ;
if ( V_2 -> V_29 )
F_100 ( V_152 , L_40 , V_2 -> V_29 -> V_62 , V_2 -> V_29 -> V_63 ) ;
else
F_100 ( V_152 , L_41 ) ;
if ( V_2 -> V_154 ) {
F_100 ( V_152 , L_42 , V_2 -> V_154 -> V_62 ,
V_2 -> V_154 -> V_63 ) ;
}
F_101 ( V_152 , '\n' ) ;
}
static void * F_102 ( struct V_155 * V_156 , struct V_157 * V_158 ,
T_4 * V_159 )
{
struct V_160 * V_161 = V_156 -> V_162 ;
if ( ! V_161 )
V_161 = V_158 -> V_163 ;
if ( V_161 == V_164 ) {
V_161 = V_158 -> V_163 ;
-- * V_159 ;
}
for (; V_161 ; V_161 = V_161 -> V_165 ) {
if ( -- * V_159 < 0 )
break;
}
V_156 -> V_162 = V_161 ;
return ( * V_159 < 0 ) ? V_156 : NULL ;
}
static void * F_103 ( struct V_155 * V_156 , T_4 * V_159 ,
struct V_9 * V_10 )
{
void * V_166 = NULL ;
int V_167 ;
for ( V_167 = V_156 -> V_168 ; V_167 < V_169 ; V_167 ++ ) {
V_166 = F_102 ( V_156 , & V_10 -> V_170 [ V_167 ] , V_159 ) ;
if ( V_166 )
break;
}
V_156 -> V_168 = V_167 ;
return V_166 ;
}
static void * F_104 ( struct V_155 * V_156 , T_4 * V_159 ,
struct V_9 * V_10 )
{
struct V_157 * V_171 [] = {
& V_10 -> V_121 ,
& V_10 -> V_172 ,
& V_10 -> V_173
} ;
void * V_166 = NULL ;
int V_174 ;
for ( V_174 = V_156 -> V_175 ; V_174 < F_105 ( V_171 ) ; V_174 ++ ) {
V_166 = F_102 ( V_156 , V_171 [ V_174 ] , V_159 ) ;
if ( V_166 )
break;
}
V_156 -> V_175 = V_174 ;
return V_166 ;
}
static void * F_106 ( struct V_155 * V_156 , T_4 * V_159 ,
struct V_9 * V_10 )
{
if ( ! V_156 -> V_176 ) {
V_156 -> V_176 = V_10 ;
F_52 ( & V_10 -> V_79 , V_156 -> V_56 ) ;
}
if ( ! F_103 ( V_156 , V_159 , V_10 ) && ! F_104 ( V_156 , V_159 , V_10 ) ) {
F_55 ( & V_10 -> V_79 , V_156 -> V_56 ) ;
V_156 -> V_176 = NULL ;
V_156 -> V_168 = V_156 -> V_175 = 0 ;
}
return V_156 -> V_176 ;
}
static void * F_107 ( struct V_155 * V_156 , T_4 * V_159 )
{
struct V_6 * V_7 ;
void * V_166 ;
V_7 = V_156 -> V_7 ? V_156 -> V_7 : V_133 [ V_156 -> V_177 ] ;
V_166 = ( V_7 && F_8 ( V_7 ) ) ?
F_106 ( V_156 , V_159 , F_8 ( V_7 ) ) : NULL ;
if ( ! V_166 && V_7 ) {
F_108 ( V_7 ) ;
V_7 = NULL ;
}
V_156 -> V_7 = V_7 ;
return V_166 ;
}
static void * F_109 ( struct V_155 * V_156 , T_4 V_159 )
{
void * V_166 = NULL ;
for (; V_156 -> V_177 < V_132 ; V_156 -> V_177 ++ ) {
V_166 = F_107 ( V_156 , & V_159 ) ;
if ( V_166 )
break;
}
return V_166 ;
}
static void * F_110 ( struct V_151 * V_152 , T_4 * V_178 )
{
struct V_155 * V_156 = V_152 -> V_179 ;
V_156 -> V_177 = 0 ;
V_156 -> V_7 = NULL ;
V_156 -> V_176 = NULL ;
V_156 -> V_168 = 0 ;
V_156 -> V_175 = 0 ;
V_156 -> V_162 = V_164 ;
return * V_178 ? F_109 ( V_156 , * V_178 ) : V_164 ;
}
static void F_111 ( struct V_151 * V_152 , void * V_166 )
{
struct V_155 * V_156 = V_152 -> V_179 ;
if ( V_156 -> V_7 ) {
F_55 ( & V_156 -> V_176 -> V_79 ,
V_156 -> V_56 ) ;
F_108 ( V_156 -> V_7 ) ;
}
}
static void * F_112 ( struct V_151 * V_152 , void * V_166 , T_4 * V_178 )
{
struct V_155 * V_156 = V_152 -> V_179 ;
V_166 = F_109 ( V_156 , 1 ) ;
* V_178 += ! ! F_113 ( V_166 ) ;
return V_166 ;
}
static int F_114 ( struct V_151 * V_152 , void * V_166 )
{
static const char V_180 [] =
L_43
L_44
L_45 ;
if ( V_166 == V_164 )
F_115 ( V_152 , V_180 ) ;
else {
struct V_155 * V_156 = V_152 -> V_179 ;
struct V_6 * V_7 = V_156 -> V_7 ;
struct V_1 * V_2 = F_116 ( V_156 -> V_162 ,
struct V_1 ,
V_165 ) ;
F_100 ( V_152 , L_46 , V_7 -> V_37 ) ;
F_99 ( V_152 , V_2 ) ;
}
return 0 ;
}
static int F_117 ( struct V_181 * V_181 , struct V_182 * V_182 )
{
return F_118 ( V_182 , & V_183 , sizeof( struct V_155 ) ) ;
}
static int F_119 ( struct V_184 * V_13 , unsigned int V_185 , unsigned long V_127 )
{
struct V_28 * V_29 = F_120 ( V_13 ) ;
int V_186 = 0 ;
switch ( V_185 ) {
case V_187 :
case V_188 :
case V_189 :
if ( ! F_121 ( V_190 ) )
return - V_191 ;
break;
default:
return - V_192 ;
}
switch ( V_185 ) {
case V_187 :
V_186 = F_90 ( V_29 , ( int ) V_127 ) ;
if ( V_186 >= 0 )
V_13 -> V_156 = V_193 ;
break;
case V_188 :
V_186 = F_88 ( V_29 , ( int ) V_127 ) ;
break;
case V_189 :
V_186 = F_84 ( V_29 , ( void T_3 * ) V_127 ) ;
break;
}
return V_186 ;
}
static int T_5 F_122 ( void )
{
#ifdef F_123
struct V_194 * V_167 ;
V_167 = F_124 ( L_47 , V_195 , V_196 , & V_197 ) ;
if ( ! V_167 ) {
F_125 ( L_48 ) ;
return - V_135 ;
}
#endif
F_126 ( & V_198 ) ;
F_18 ( L_49 ) ;
return 0 ;
}
static void T_6 F_127 ( void )
{
int V_68 ;
F_128 ( L_47 , V_196 ) ;
F_129 ( & V_198 ) ;
for ( V_68 = 0 ; V_68 < V_132 ; V_68 ++ ) {
if ( V_133 [ V_68 ] != NULL ) {
F_130 ( V_133 [ V_68 ] ) ;
F_93 ( V_133 [ V_68 ] ) ;
V_133 [ V_68 ] = NULL ;
}
}
}
static int F_131 ( struct V_6 * V_7 , const T_7 * V_199 , int V_200 ,
T_7 * * V_201 , T_8 * V_83 )
{
unsigned long V_56 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_1 * V_202 ;
struct V_4 * V_5 ;
int V_203 ;
if ( V_200 == 0 ) {
F_52 ( & V_10 -> V_79 , V_56 ) ;
V_202 = F_53 ( V_10 , V_199 ) ;
F_55 ( & V_10 -> V_79 , V_56 ) ;
if ( V_202 == NULL )
return - 1 ;
* V_201 = F_132 ( V_202 -> V_201 , V_202 -> V_83 , V_18 ) ;
if ( * V_201 == NULL )
return - 1 ;
* V_83 = V_202 -> V_83 ;
return 0 ;
}
if ( V_83 == NULL )
V_203 = F_68 ( V_10 , V_204 , V_199 , NULL , NULL ) ;
else {
V_5 = F_7 ( * V_83 , V_18 ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 -> V_19 = * V_83 ;
F_62 ( V_5 , * V_201 , * V_83 ) ;
V_203 = F_68 ( V_10 , V_204 , V_199 , NULL , V_5 ) ;
}
return V_203 ;
}
static int F_133 ( struct V_6 * V_7 , const T_7 * V_205 ,
const T_7 * V_201 , T_8 V_83 )
{
int V_203 ;
struct V_4 * V_5 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
if ( ! F_134 ( V_205 , V_7 -> V_71 ) )
return 0 ;
F_5 ( V_10 -> V_201 ) ;
V_10 -> V_201 = F_132 ( V_201 , V_83 , V_134 ) ;
if ( V_10 -> V_201 == NULL )
return 0 ;
V_10 -> V_83 = V_83 ;
V_5 = F_7 ( V_83 , V_18 ) ;
if ( V_5 == NULL )
return 0 ;
V_5 -> V_19 = V_83 ;
F_62 ( V_5 , V_201 , V_83 ) ;
V_203 = F_68 ( V_10 , V_206 , NULL , NULL , V_5 ) ;
if ( V_203 != 0 )
F_18 ( L_50 ) ;
return 1 ;
}
static void F_57 ( struct V_6 * V_7 , const T_7 * V_72 ,
const T_7 * V_201 , T_8 V_83 )
{
#if 0
int i = 0;
#endif
struct V_9 * V_10 = F_8 ( V_7 ) ;
#if 0
struct lec_arp_table *entry = lec_arp_find(priv, mac_addr);
if (entry == NULL)
return;
kfree(entry->tlvs);
entry->tlvs = kmemdup(tlvs, sizeoftlvs, GFP_KERNEL);
if (entry->tlvs == NULL)
return;
entry->sizeoftlvs = sizeoftlvs;
#endif
#if 0
pr_info("\n");
pr_info("dump of tlvs, sizeoftlvs=%d\n", sizeoftlvs);
while (i < sizeoftlvs)
pr_cont("%02x ", tlvs[i++]);
pr_cont("\n");
#endif
if ( V_10 -> V_96 && V_10 -> V_96 -> V_207 ) {
V_10 -> V_96 -> V_207 ( V_7 , V_72 ,
V_201 , V_83 ) ;
}
}
static void F_94 ( struct V_9 * V_10 )
{
unsigned short V_68 ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ )
F_135 ( & V_10 -> V_170 [ V_68 ] ) ;
F_135 ( & V_10 -> V_121 ) ;
F_135 ( & V_10 -> V_172 ) ;
F_135 ( & V_10 -> V_173 ) ;
F_136 ( & V_10 -> V_79 ) ;
F_137 ( & V_10 -> V_208 , V_209 ) ;
F_138 ( & V_10 -> V_208 , V_210 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 ) {
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_64 * V_65 = F_46 ( V_29 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_67 ;
V_29 -> V_136 = V_65 -> V_126 ;
if ( V_65 -> V_66 )
F_20 ( V_7 ) ;
F_5 ( V_65 ) ;
V_29 -> V_137 = NULL ;
V_29 -> V_138 = V_2 -> V_211 ;
F_140 ( V_29 , - V_212 ) ;
V_2 -> V_29 = NULL ;
}
if ( V_2 -> V_154 ) {
V_2 -> V_154 -> V_138 = V_2 -> V_213 ;
F_140 ( V_2 -> V_154 , - V_212 ) ;
V_2 -> V_154 = NULL ;
}
}
static inline void
F_141 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_157 * V_69 ;
V_69 = & V_10 -> V_170 [ F_142 ( V_2 -> V_72 [ V_153 - 1 ] ) ] ;
F_143 ( & V_2 -> V_165 , V_69 ) ;
F_22 ( L_51 , V_2 -> V_72 ) ;
}
static int
F_54 ( struct V_9 * V_10 , struct V_1 * V_214 )
{
struct V_1 * V_2 ;
int V_68 , V_215 = 1 ;
if ( ! V_214 )
return - 1 ;
F_144 ( & V_214 -> V_165 ) ;
F_145 ( & V_214 -> V_216 ) ;
if ( V_214 -> V_148 >= V_217 ) {
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( memcmp ( V_214 -> V_75 ,
V_2 -> V_75 , V_106 ) == 0 ) {
V_215 = 0 ;
break;
}
}
}
if ( V_215 )
F_139 ( V_214 ) ;
}
F_147 ( & V_214 -> V_58 ) ;
F_22 ( L_52 , V_214 -> V_72 ) ;
return 0 ;
}
static const char * F_148 ( unsigned char V_218 )
{
switch ( V_218 ) {
case V_219 :
return L_53 ;
case V_220 :
return L_54 ;
case V_221 :
return L_55 ;
case V_217 :
return L_56 ;
case V_150 :
return L_36 ;
}
return L_57 ;
}
static void F_149 ( struct V_9 * V_10 )
{
struct V_1 * V_222 ;
char V_223 [ 256 ] ;
int V_68 , V_224 , V_225 ;
F_18 ( L_58 , V_10 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_146 (rulla,
&priv->lec_arp_tables[i], next) {
V_225 = 0 ;
V_225 += sprintf ( V_223 , L_59 , V_68 , V_222 ) ;
V_225 += sprintf ( V_223 + V_225 , L_60 ,
V_222 -> V_72 ) ;
V_225 += sprintf ( V_223 + V_225 , L_61 ) ;
for ( V_224 = 0 ; V_224 < V_106 ; V_224 ++ ) {
V_225 += sprintf ( V_223 + V_225 ,
L_62 ,
V_222 -> V_75 [ V_224 ] & 0xff ) ;
}
V_225 += sprintf ( V_223 + V_225 ,
L_63 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_62 : 0 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_63 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 ->
V_62 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 ->
V_63 : 0 , V_222 -> V_226 ,
V_222 -> V_227 , V_222 -> V_228 ) ;
V_225 +=
sprintf ( V_223 + V_225 ,
L_64 ,
V_222 -> V_56 , V_222 -> V_229 ,
F_148 ( V_222 -> V_148 ) ) ;
F_18 ( L_1 , V_223 ) ;
}
}
if ( ! F_76 ( & V_10 -> V_172 ) )
F_18 ( L_65 ) ;
F_146 (rulla, &priv->lec_no_forward, next) {
V_225 = 0 ;
V_225 += sprintf ( V_223 + V_225 , L_60 , V_222 -> V_72 ) ;
V_225 += sprintf ( V_223 + V_225 , L_61 ) ;
for ( V_224 = 0 ; V_224 < V_106 ; V_224 ++ ) {
V_225 += sprintf ( V_223 + V_225 , L_62 ,
V_222 -> V_75 [ V_224 ] & 0xff ) ;
}
V_225 += sprintf ( V_223 + V_225 ,
L_63 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_62 : 0 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_63 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 -> V_62 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 -> V_63 : 0 ,
V_222 -> V_226 ,
V_222 -> V_227 , V_222 -> V_228 ) ;
V_225 += sprintf ( V_223 + V_225 ,
L_64 ,
V_222 -> V_56 , V_222 -> V_229 ,
F_148 ( V_222 -> V_148 ) ) ;
F_18 ( L_1 , V_223 ) ;
}
if ( ! F_76 ( & V_10 -> V_121 ) )
F_18 ( L_66 ) ;
F_146 (rulla, &priv->lec_arp_empty_ones, next) {
V_225 = 0 ;
V_225 += sprintf ( V_223 + V_225 , L_60 , V_222 -> V_72 ) ;
V_225 += sprintf ( V_223 + V_225 , L_61 ) ;
for ( V_224 = 0 ; V_224 < V_106 ; V_224 ++ ) {
V_225 += sprintf ( V_223 + V_225 , L_62 ,
V_222 -> V_75 [ V_224 ] & 0xff ) ;
}
V_225 += sprintf ( V_223 + V_225 ,
L_63 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_62 : 0 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_63 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 -> V_62 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 -> V_63 : 0 ,
V_222 -> V_226 ,
V_222 -> V_227 , V_222 -> V_228 ) ;
V_225 += sprintf ( V_223 + V_225 ,
L_64 ,
V_222 -> V_56 , V_222 -> V_229 ,
F_148 ( V_222 -> V_148 ) ) ;
F_18 ( L_67 , V_223 ) ;
}
if ( ! F_76 ( & V_10 -> V_173 ) )
F_18 ( L_68 ) ;
F_146 (rulla, &priv->mcast_fwds, next) {
V_225 = 0 ;
V_225 += sprintf ( V_223 + V_225 , L_60 , V_222 -> V_72 ) ;
V_225 += sprintf ( V_223 + V_225 , L_61 ) ;
for ( V_224 = 0 ; V_224 < V_106 ; V_224 ++ ) {
V_225 += sprintf ( V_223 + V_225 , L_62 ,
V_222 -> V_75 [ V_224 ] & 0xff ) ;
}
V_225 += sprintf ( V_223 + V_225 ,
L_63 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_62 : 0 ,
V_222 -> V_29 ? V_222 -> V_29 -> V_63 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 -> V_62 : 0 ,
V_222 -> V_154 ? V_222 -> V_154 -> V_63 : 0 ,
V_222 -> V_226 ,
V_222 -> V_227 , V_222 -> V_228 ) ;
V_225 += sprintf ( V_223 + V_225 ,
L_64 ,
V_222 -> V_56 , V_222 -> V_229 ,
F_148 ( V_222 -> V_148 ) ) ;
F_18 ( L_1 , V_223 ) ;
}
}
static void F_64 ( struct V_9 * V_10 )
{
unsigned long V_56 ;
struct V_160 * V_165 ;
struct V_1 * V_2 ;
int V_68 ;
F_150 ( & V_10 -> V_208 ) ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_170 [ V_68 ] ) ;
}
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
F_152 ( & V_2 -> V_216 ) ;
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_121 ) ;
F_151 (entry, next,
&priv->lec_no_forward, next) {
F_152 ( & V_2 -> V_216 ) ;
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_172 ) ;
F_151 (entry, next, &priv->mcast_fwds, next) {
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_173 ) ;
V_10 -> V_230 = NULL ;
F_55 ( & V_10 -> V_79 , V_56 ) ;
}
static struct V_1 * F_53 ( struct V_9 * V_10 ,
const unsigned char * V_72 )
{
struct V_157 * V_45 ;
struct V_1 * V_2 ;
F_22 ( L_69 , V_72 ) ;
V_45 = & V_10 -> V_170 [ F_142 ( V_72 [ V_153 - 1 ] ) ] ;
F_146 (entry, head, next) {
if ( F_134 ( V_72 , V_2 -> V_72 ) )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_153 ( struct V_9 * V_10 ,
const unsigned char * V_72 )
{
struct V_1 * V_231 ;
V_231 = F_154 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_231 ) {
F_18 ( L_70 ) ;
return NULL ;
}
F_69 ( V_231 -> V_72 , V_72 ) ;
F_155 ( & V_231 -> V_165 ) ;
F_156 ( & V_231 -> V_216 , V_232 ,
( unsigned long ) V_231 ) ;
V_231 -> V_226 = V_233 ;
V_231 -> V_10 = V_10 ;
F_157 ( & V_231 -> V_58 ) ;
F_158 ( & V_231 -> V_3 , 1 ) ;
return V_231 ;
}
static void V_232 ( unsigned long V_11 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_11 ;
F_22 ( L_71 ) ;
if ( V_2 -> V_148 == V_220 ) {
if ( V_2 -> V_228 <= V_2 -> V_10 -> V_89 ) {
if ( V_2 -> V_42 )
F_68 ( V_2 -> V_10 , V_234 ,
V_2 -> V_72 , NULL , NULL ) ;
else
F_68 ( V_2 -> V_10 , V_204 ,
V_2 -> V_72 , NULL , NULL ) ;
V_2 -> V_228 ++ ;
}
F_159 ( & V_2 -> V_216 , V_233 + ( 1 * V_88 ) ) ;
}
}
static void F_160 ( unsigned long V_11 )
{
unsigned long V_56 ;
struct V_1 * V_214 = (struct V_1 * ) V_11 ;
struct V_9 * V_10 = V_214 -> V_10 ;
F_145 ( & V_214 -> V_216 ) ;
F_22 ( L_72 ,
V_214 , V_10 ,
V_214 -> V_29 ? V_214 -> V_154 -> V_62 : 0 ,
V_214 -> V_29 ? V_214 -> V_154 -> V_63 : 0 ) ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
F_144 ( & V_214 -> V_165 ) ;
F_55 ( & V_10 -> V_79 , V_56 ) ;
F_139 ( V_214 ) ;
F_3 ( V_214 ) ;
}
static bool F_161 ( struct V_1 * V_2 ,
unsigned long V_235 ,
struct V_9 * V_10 )
{
unsigned long V_236 ;
if ( ( V_2 -> V_56 ) & V_237 && V_10 -> V_76 )
V_236 = V_10 -> V_91 ;
else
V_236 = V_10 -> V_90 ;
F_22 ( L_73 ,
V_235 , V_2 -> V_226 , V_236 ) ;
if ( F_162 ( V_235 , V_2 -> V_226 + V_236 ) &&
! ( V_2 -> V_56 & V_238 ) &&
! ( V_2 -> V_72 [ 0 ] & 0x01 ) ) {
F_22 ( L_74 ) ;
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
} else {
if ( ( V_2 -> V_148 == V_221 ||
V_2 -> V_148 == V_220 ) &&
F_163 ( V_235 , V_2 -> V_227 +
V_10 -> V_87 ) ) {
V_2 -> V_227 = V_233 ;
V_2 -> V_229 = 0 ;
if ( V_2 -> V_148 == V_221 )
F_68 ( V_10 , V_239 ,
V_2 -> V_72 ,
V_2 -> V_75 ,
NULL ) ;
}
if ( V_2 -> V_148 == V_217 &&
F_163 ( V_235 , V_2 -> V_227 +
V_10 -> V_94 ) ) {
F_1 ( V_2 ) ;
return true ;
}
}
return false ;
}
static void V_209 ( struct V_240 * V_241 )
{
unsigned long V_56 ;
struct V_9 * V_10 =
F_164 ( V_241 , struct V_9 , V_208 . V_241 ) ;
struct V_160 * V_165 ;
struct V_1 * V_2 ;
unsigned long V_235 ;
int V_68 ;
F_22 ( L_75 , V_10 ) ;
V_235 = V_233 ;
V_242:
F_52 ( & V_10 -> V_79 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( F_161 ( V_2 , V_235 , V_10 ) ) {
struct V_4 * V_5 ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_55 ( & V_10 -> V_79 ,
V_56 ) ;
while ( ( V_5 = F_44 ( & V_2 -> V_58 ) ) )
F_14 ( V_29 , V_5 ) ;
V_2 -> V_226 = V_233 ;
V_2 -> V_148 = V_150 ;
F_3 ( V_2 ) ;
goto V_242;
}
}
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
F_138 ( & V_10 -> V_208 , V_210 ) ;
}
static struct V_28 * F_42 ( struct V_9 * V_10 ,
const unsigned char * V_243 ,
int V_42 ,
struct V_1 * * V_244 )
{
unsigned long V_56 ;
struct V_1 * V_2 ;
struct V_28 * V_245 ;
if ( V_243 [ 0 ] & 0x01 ) {
switch ( V_10 -> V_95 ) {
case 1 :
return V_10 -> V_230 ;
case 2 :
if ( F_134 ( V_243 , V_246 ) )
return V_10 -> V_230 ;
break;
default:
break;
}
}
F_52 ( & V_10 -> V_79 , V_56 ) ;
V_2 = F_53 ( V_10 , V_243 ) ;
if ( V_2 ) {
if ( V_2 -> V_148 == V_150 ) {
V_2 -> V_226 = V_233 ;
F_1 ( V_2 ) ;
* V_244 = V_2 ;
V_245 = V_2 -> V_29 ;
goto V_61;
}
if ( V_2 -> V_148 == V_220 )
V_2 -> V_228 = 0 ;
if ( V_2 -> V_148 != V_217 &&
V_2 -> V_229 <
V_10 -> V_85 ) {
V_2 -> V_229 ++ ;
F_22 ( L_76 ) ;
V_245 = V_10 -> V_230 ;
goto V_61;
}
F_1 ( V_2 ) ;
* V_244 = V_2 ;
F_22 ( L_77 , V_2 -> V_148 ,
V_2 -> V_29 ) ;
V_245 = NULL ;
} else {
V_2 = F_153 ( V_10 , V_243 ) ;
F_22 ( L_78 ) ;
if ( ! V_2 ) {
V_245 = V_10 -> V_230 ;
goto V_61;
}
F_141 ( V_10 , V_2 ) ;
V_2 -> V_229 = 1 ;
V_2 -> V_148 = V_220 ;
V_2 -> V_228 = 1 ;
V_2 -> V_226 = V_2 -> V_227 = V_233 ;
V_2 -> V_42 = V_42 ;
if ( V_2 -> V_42 )
F_68 ( V_10 , V_234 , V_243 , NULL ,
NULL ) ;
else
F_68 ( V_10 , V_204 , V_243 , NULL , NULL ) ;
V_2 -> V_216 . V_247 = V_233 + ( 1 * V_88 ) ;
V_2 -> V_216 . V_248 = V_232 ;
F_165 ( & V_2 -> V_216 ) ;
V_245 = V_10 -> V_230 ;
}
V_61:
F_55 ( & V_10 -> V_79 , V_56 ) ;
return V_245 ;
}
static int
F_50 ( struct V_9 * V_10 , const unsigned char * V_75 ,
unsigned long V_249 )
{
unsigned long V_56 ;
struct V_160 * V_165 ;
struct V_1 * V_2 ;
int V_68 ;
F_22 ( L_71 ) ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_75 , V_2 -> V_75 , V_106 ) &&
( V_249 ||
! ( V_2 -> V_56 & V_238 ) ) ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
return 0 ;
}
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
return - 1 ;
}
static void
F_56 ( struct V_9 * V_10 , const unsigned char * V_72 ,
const unsigned char * V_75 , unsigned long V_250 ,
unsigned int V_82 )
{
unsigned long V_56 ;
struct V_160 * V_165 ;
struct V_1 * V_2 , * V_69 ;
int V_68 ;
F_22 ( L_79 ,
( V_82 ) ? L_80 : L_7 , V_72 ) ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
V_2 = F_53 ( V_10 , V_72 ) ;
if ( V_2 == NULL && V_82 )
goto V_61;
if ( ! F_76 ( & V_10 -> V_121 ) ) {
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( memcmp ( V_2 -> V_75 , V_75 , V_106 ) == 0 ) {
F_144 ( & V_2 -> V_165 ) ;
F_145 ( & V_2 -> V_216 ) ;
V_69 = F_53 ( V_10 , V_72 ) ;
if ( V_69 ) {
F_145 ( & V_69 -> V_216 ) ;
V_69 -> V_148 = V_150 ;
memcpy ( V_69 -> V_75 , V_75 , V_106 ) ;
V_69 -> V_29 = V_2 -> V_29 ;
V_69 -> V_211 = V_2 -> V_211 ;
V_69 -> V_226 = V_233 ;
F_145 ( & V_2 -> V_216 ) ;
F_3 ( V_2 ) ;
V_2 = V_69 ;
} else {
V_2 -> V_148 = V_150 ;
F_69 ( V_2 -> V_72 ,
V_72 ) ;
V_2 -> V_226 = V_233 ;
F_141 ( V_10 , V_2 ) ;
}
if ( V_250 )
V_2 -> V_56 |= V_237 ;
else
V_2 -> V_56 &= ~ V_237 ;
F_22 ( L_81 ) ;
F_149 ( V_10 ) ;
goto V_61;
}
}
}
V_2 = F_53 ( V_10 , V_72 ) ;
if ( ! V_2 ) {
V_2 = F_153 ( V_10 , V_72 ) ;
if ( ! V_2 )
goto V_61;
V_2 -> V_148 = V_219 ;
F_141 ( V_10 , V_2 ) ;
}
memcpy ( V_2 -> V_75 , V_75 , V_106 ) ;
F_145 ( & V_2 -> V_216 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_146 (tmp,
&priv->lec_arp_tables[i], next) {
if ( V_2 != V_69 &&
! memcmp ( V_69 -> V_75 , V_75 , V_106 ) ) {
if ( V_69 -> V_148 > V_221 ) {
V_2 -> V_29 = V_69 -> V_29 ;
V_2 -> V_211 = V_69 -> V_211 ;
}
V_2 -> V_148 = V_69 -> V_148 ;
break;
}
}
}
if ( V_250 )
V_2 -> V_56 |= V_237 ;
else
V_2 -> V_56 &= ~ V_237 ;
if ( V_2 -> V_148 == V_220 || V_2 -> V_148 == V_219 ) {
V_2 -> V_148 = V_221 ;
F_68 ( V_10 , V_239 , V_2 -> V_72 , V_75 , NULL ) ;
}
F_22 ( L_82 ) ;
F_149 ( V_10 ) ;
V_61:
F_55 ( & V_10 -> V_79 , V_56 ) ;
}
static void
F_87 ( struct V_9 * V_10 , const struct V_129 * V_130 ,
struct V_28 * V_29 ,
void (* V_211) ( struct V_28 * V_29 , struct V_4 * V_5 ) )
{
unsigned long V_56 ;
struct V_1 * V_2 ;
int V_68 , V_251 = 0 ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
if ( V_130 -> V_252 == 2 ) {
F_22 ( L_83 ) ;
#if 0
entry = lec_arp_find(priv, bus_mac);
if (!entry) {
pr_info("LEC_ARP: Multicast entry not found!\n");
goto out;
}
memcpy(entry->atm_addr, ioc_data->atm_addr, ATM_ESA_LEN);
entry->recv_vcc = vcc;
entry->old_recv_push = old_push;
#endif
V_2 = F_153 ( V_10 , V_246 ) ;
if ( V_2 == NULL )
goto V_61;
F_145 ( & V_2 -> V_216 ) ;
memcpy ( V_2 -> V_75 , V_130 -> V_75 , V_106 ) ;
V_2 -> V_154 = V_29 ;
V_2 -> V_213 = V_211 ;
F_143 ( & V_2 -> V_165 , & V_10 -> V_173 ) ;
goto V_61;
} else if ( V_130 -> V_252 == 1 ) {
F_22 ( L_84 ,
V_130 -> V_75 [ 0 ] , V_130 -> V_75 [ 1 ] ,
V_130 -> V_75 [ 2 ] , V_130 -> V_75 [ 3 ] ,
V_130 -> V_75 [ 4 ] , V_130 -> V_75 [ 5 ] ,
V_130 -> V_75 [ 6 ] , V_130 -> V_75 [ 7 ] ,
V_130 -> V_75 [ 8 ] , V_130 -> V_75 [ 9 ] ,
V_130 -> V_75 [ 10 ] , V_130 -> V_75 [ 11 ] ,
V_130 -> V_75 [ 12 ] , V_130 -> V_75 [ 13 ] ,
V_130 -> V_75 [ 14 ] , V_130 -> V_75 [ 15 ] ,
V_130 -> V_75 [ 16 ] , V_130 -> V_75 [ 17 ] ,
V_130 -> V_75 [ 18 ] , V_130 -> V_75 [ 19 ] ) ;
V_2 = F_153 ( V_10 , V_246 ) ;
if ( V_2 == NULL )
goto V_61;
memcpy ( V_2 -> V_75 , V_130 -> V_75 , V_106 ) ;
F_166 ( V_2 -> V_72 ) ;
V_2 -> V_154 = V_29 ;
V_2 -> V_213 = V_211 ;
V_2 -> V_148 = V_219 ;
V_2 -> V_216 . V_247 = V_233 + V_10 -> V_147 ;
V_2 -> V_216 . V_248 = F_160 ;
F_143 ( & V_2 -> V_165 , & V_10 -> V_172 ) ;
F_165 ( & V_2 -> V_216 ) ;
F_149 ( V_10 ) ;
goto V_61;
}
F_22 ( L_85 ,
V_130 -> V_75 [ 0 ] , V_130 -> V_75 [ 1 ] ,
V_130 -> V_75 [ 2 ] , V_130 -> V_75 [ 3 ] ,
V_130 -> V_75 [ 4 ] , V_130 -> V_75 [ 5 ] ,
V_130 -> V_75 [ 6 ] , V_130 -> V_75 [ 7 ] ,
V_130 -> V_75 [ 8 ] , V_130 -> V_75 [ 9 ] ,
V_130 -> V_75 [ 10 ] , V_130 -> V_75 [ 11 ] ,
V_130 -> V_75 [ 12 ] , V_130 -> V_75 [ 13 ] ,
V_130 -> V_75 [ 14 ] , V_130 -> V_75 [ 15 ] ,
V_130 -> V_75 [ 16 ] , V_130 -> V_75 [ 17 ] ,
V_130 -> V_75 [ 18 ] , V_130 -> V_75 [ 19 ] ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( memcmp
( V_130 -> V_75 , V_2 -> V_75 ,
V_106 ) == 0 ) {
F_22 ( L_86 ) ;
F_22 ( L_87 ,
V_2 -> V_29 ? V_2 -> V_29 -> V_63 : 0 ,
V_2 -> V_154 ? V_2 -> V_154 ->
V_63 : 0 ) ;
V_251 = 1 ;
F_145 ( & V_2 -> V_216 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_211 = V_211 ;
if ( V_2 -> V_148 == V_221 ) {
if ( V_10 -> V_85
== 0 )
V_2 -> V_148 =
V_150 ;
else {
V_2 -> V_227 = V_233 ;
V_2 -> V_148 =
V_217 ;
#if 0
send_to_lecd(priv, l_flush_xmt,
NULL,
entry->atm_addr,
NULL);
#endif
}
} else {
;
}
}
}
}
if ( V_251 ) {
F_22 ( L_88 ) ;
F_149 ( V_10 ) ;
goto V_61;
}
V_2 = F_153 ( V_10 , V_246 ) ;
if ( ! V_2 )
goto V_61;
V_2 -> V_29 = V_29 ;
V_2 -> V_211 = V_211 ;
memcpy ( V_2 -> V_75 , V_130 -> V_75 , V_106 ) ;
F_166 ( V_2 -> V_72 ) ;
V_2 -> V_148 = V_219 ;
F_143 ( & V_2 -> V_165 , & V_10 -> V_121 ) ;
V_2 -> V_216 . V_247 = V_233 + V_10 -> V_147 ;
V_2 -> V_216 . V_248 = F_160 ;
F_165 ( & V_2 -> V_216 ) ;
F_22 ( L_88 ) ;
F_149 ( V_10 ) ;
V_61:
F_55 ( & V_10 -> V_79 , V_56 ) ;
}
static void F_51 ( struct V_9 * V_10 , unsigned long V_253 )
{
unsigned long V_56 ;
struct V_1 * V_2 ;
int V_68 ;
F_22 ( L_89 , V_253 ) ;
V_242:
F_52 ( & V_10 -> V_79 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( V_2 -> V_254 == V_253 &&
V_2 -> V_148 == V_217 ) {
struct V_4 * V_5 ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_1 ( V_2 ) ;
F_55 ( & V_10 -> V_79 ,
V_56 ) ;
while ( ( V_5 = F_44 ( & V_2 -> V_58 ) ) )
F_14 ( V_29 , V_5 ) ;
V_2 -> V_226 = V_233 ;
V_2 -> V_148 = V_150 ;
F_3 ( V_2 ) ;
F_22 ( L_90 ) ;
goto V_242;
}
}
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
F_149 ( V_10 ) ;
}
static void
F_61 ( struct V_9 * V_10 ,
const unsigned char * V_75 , unsigned long V_253 )
{
unsigned long V_56 ;
struct V_1 * V_2 ;
int V_68 ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ )
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_75 , V_2 -> V_75 , V_106 ) ) {
V_2 -> V_254 = V_253 ;
F_22 ( L_91 ,
V_253 , V_2 ) ;
}
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
}
static int F_89 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
unsigned long V_56 ;
unsigned char V_72 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
struct V_1 * V_255 ;
struct V_64 * V_65 ;
int V_186 = 0 ;
V_65 = F_86 ( sizeof( struct V_64 ) , V_134 ) ;
if ( ! V_65 )
return - V_135 ;
V_65 -> V_66 = 0 ;
V_65 -> V_126 = V_29 -> V_136 ;
V_29 -> V_137 = V_65 ;
V_29 -> V_136 = F_81 ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
V_255 = F_153 ( V_10 , V_72 ) ;
if ( ! V_255 ) {
V_29 -> V_136 = V_65 -> V_126 ;
F_5 ( V_65 ) ;
V_186 = - V_135 ;
goto V_61;
}
memcpy ( V_255 -> V_75 , V_29 -> V_256 . V_257 . V_258 , V_106 ) ;
V_255 -> V_148 = V_150 ;
V_255 -> V_56 |= V_238 ;
V_255 -> V_29 = V_29 ;
V_255 -> V_211 = V_29 -> V_138 ;
V_29 -> V_138 = F_73 ;
V_10 -> V_230 = V_29 ;
F_141 ( V_10 , V_255 ) ;
V_61:
F_55 ( & V_10 -> V_79 , V_56 ) ;
return V_186 ;
}
static void F_74 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
unsigned long V_56 ;
struct V_160 * V_165 ;
struct V_1 * V_2 ;
int V_68 ;
F_22 ( L_92 , V_29 -> V_62 , V_29 -> V_63 ) ;
F_149 ( V_10 ) ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
for ( V_68 = 0 ; V_68 < V_169 ; V_68 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( V_29 == V_2 -> V_29 ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_10 -> V_230 == V_29 )
V_10 -> V_230 = NULL ;
}
}
}
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( V_2 -> V_29 == V_29 ) {
F_139 ( V_2 ) ;
F_145 ( & V_2 -> V_216 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_3 ( V_2 ) ;
}
}
F_151 (entry, next,
&priv->lec_no_forward, next) {
if ( V_2 -> V_154 == V_29 ) {
F_139 ( V_2 ) ;
F_145 ( & V_2 -> V_216 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_3 ( V_2 ) ;
}
}
F_151 (entry, next, &priv->mcast_fwds, next) {
if ( V_2 -> V_154 == V_29 ) {
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_165 ) ;
F_3 ( V_2 ) ;
}
}
F_55 ( & V_10 -> V_79 , V_56 ) ;
F_149 ( V_10 ) ;
}
static void
F_77 ( struct V_9 * V_10 ,
struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_56 ;
struct V_160 * V_165 ;
struct V_1 * V_2 , * V_69 ;
struct V_38 * V_259 = (struct V_38 * ) V_5 -> V_11 ;
unsigned char * V_116 = V_259 -> V_119 ;
F_52 ( & V_10 -> V_79 , V_56 ) ;
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( V_29 == V_2 -> V_29 ) {
F_145 ( & V_2 -> V_216 ) ;
F_69 ( V_2 -> V_72 , V_116 ) ;
V_2 -> V_148 = V_150 ;
V_2 -> V_226 = V_233 ;
V_69 = F_53 ( V_10 , V_116 ) ;
if ( V_69 ) {
F_54 ( V_10 , V_69 ) ;
F_3 ( V_69 ) ;
}
F_144 ( & V_2 -> V_165 ) ;
F_141 ( V_10 , V_2 ) ;
goto V_61;
}
}
F_22 ( L_93 ) ;
V_61:
F_55 ( & V_10 -> V_79 , V_56 ) ;
}
