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
V_7 -> V_38 = V_39 ;
F_19 ( V_7 ) ;
}
static T_1 F_20 ( struct V_4 * V_5 ,
struct V_6 * V_7 )
{
struct V_4 * V_15 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_40 * V_41 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
unsigned char * V_42 ;
int V_43 ;
int V_44 ;
F_21 ( L_2 ) ;
if ( ! V_10 -> V_24 ) {
F_18 ( L_3 , V_7 -> V_37 ) ;
V_7 -> V_33 . V_45 ++ ;
F_22 ( V_7 ) ;
F_23 ( V_5 ) ;
return V_46 ;
}
F_21 ( L_4 ,
( long ) V_5 -> V_47 , ( long ) V_5 -> V_11 , ( long ) F_24 ( V_5 ) ,
( long ) F_25 ( V_5 ) ) ;
#if F_26 ( V_48 ) || F_26 ( V_49 )
if ( memcmp ( V_5 -> V_11 , V_50 , sizeof( V_50 ) ) == 0 )
F_6 ( V_5 , V_7 ) ;
#endif
if ( F_27 ( V_5 ) < 2 ) {
F_21 ( L_5 ) ;
V_15 = F_28 ( V_5 , V_51 ) ;
if ( F_29 ( ! V_15 ) ) {
F_23 ( V_5 ) ;
return V_46 ;
}
F_30 ( V_5 ) ;
V_5 = V_15 ;
}
F_31 ( V_5 , 2 ) ;
V_41 = (struct V_40 * ) V_5 -> V_11 ;
V_41 -> V_52 = F_32 ( V_10 -> V_53 ) ;
#if V_54 >= 2
#define F_33 99
#elif V_54 >= 1
#define F_33 30
#endif
#if V_54 >= 1
F_34 ( V_55 L_6 ,
V_7 -> V_37 , V_5 -> V_19 , V_10 -> V_53 ) ;
F_35 ( V_55 , L_7 , V_56 , 16 , 1 ,
V_5 -> V_11 , F_36 ( V_5 -> V_19 , F_33 ) , true ) ;
#endif
V_43 = V_57 ;
if ( V_5 -> V_19 < V_43 ) {
if ( ( V_5 -> V_19 + F_37 ( V_5 ) ) < V_43 ) {
V_15 = F_38 ( V_5 , 0 ,
V_43 - V_5 -> V_25 ,
V_18 ) ;
F_39 ( V_5 ) ;
if ( V_15 == NULL ) {
V_7 -> V_33 . V_34 ++ ;
return V_46 ;
}
V_5 = V_15 ;
}
F_40 ( V_5 , V_43 - V_5 -> V_19 ) ;
}
V_44 = 0 ;
V_42 = V_41 -> V_58 ;
V_2 = NULL ;
V_29 = F_41 ( V_10 , V_42 , V_44 , & V_2 ) ;
F_21 ( L_8 ,
V_7 -> V_37 , V_29 , V_29 ? V_29 -> V_59 : 0 , V_2 ) ;
if ( ! V_29 || ! F_42 ( V_60 , & V_29 -> V_59 ) ) {
if ( V_2 && ( V_2 -> V_61 . V_62 < V_63 ) ) {
F_21 ( L_9 ,
V_7 -> V_37 , V_41 -> V_58 ) ;
F_11 ( & V_2 -> V_61 , V_5 ) ;
} else {
F_21 ( L_10 ,
V_7 -> V_37 , V_41 -> V_58 ) ;
V_7 -> V_33 . V_34 ++ ;
F_39 ( V_5 ) ;
}
goto V_64;
}
#if V_54 > 0
F_34 ( V_55 L_11 ,
V_7 -> V_37 , V_29 -> V_65 , V_29 -> V_66 ) ;
#endif
while ( V_2 && ( V_15 = F_43 ( & V_2 -> V_61 ) ) ) {
F_21 ( L_12 , V_41 -> V_58 ) ;
F_14 ( V_29 , V_15 ) ;
}
F_14 ( V_29 , V_5 ) ;
if ( ! F_44 ( V_29 , 0 ) ) {
struct V_67 * V_68 = F_45 ( V_29 ) ;
V_68 -> V_69 = 1 ;
F_22 ( V_7 ) ;
if ( F_44 ( V_29 , 0 ) )
F_19 ( V_7 ) ;
}
V_64:
if ( V_2 )
F_3 ( V_2 ) ;
V_7 -> V_38 = V_39 ;
return V_46 ;
}
static int F_46 ( struct V_6 * V_7 )
{
F_22 ( V_7 ) ;
return 0 ;
}
static int F_47 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_59 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_70 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_71 ;
char * V_72 ;
F_48 ( V_5 -> V_25 , & F_10 ( V_29 ) -> V_31 ) ;
V_17 = (struct V_16 * ) V_5 -> V_11 ;
V_72 = V_5 -> V_11 ;
V_72 += sizeof( struct V_16 ) ;
F_21 ( L_13 , V_7 -> V_37 , V_17 -> type ) ;
switch ( V_17 -> type ) {
case V_73 :
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
V_7 -> V_74 [ V_71 ] = V_17 -> V_21 . V_22 . V_75 [ V_71 ] ;
break;
case V_76 :
for ( V_71 = 0 ; V_71 < 6 ; V_71 ++ )
V_7 -> V_74 [ V_71 ] = 0 ;
break;
case V_77 :
F_49 ( V_10 , V_17 -> V_21 . V_22 . V_78 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_20 :
V_10 -> V_79 = V_17 -> V_21 . V_22 . V_23 ;
break;
case V_80 :
F_50 ( V_10 , V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_81 :
F_51 ( & V_10 -> V_82 , V_59 ) ;
V_2 = F_52 ( V_10 , V_17 -> V_21 . V_22 . V_75 ) ;
F_53 ( V_10 , V_2 ) ;
F_54 ( & V_10 -> V_82 , V_59 ) ;
if ( V_17 -> V_21 . V_22 . V_83 )
break;
case V_84 :
F_55 ( V_10 , V_17 -> V_21 . V_22 . V_75 ,
V_17 -> V_21 . V_22 . V_78 ,
V_17 -> V_21 . V_22 . V_23 ,
V_17 -> V_21 . V_22 . V_85 ) ;
F_21 ( L_14 ) ;
if ( V_17 -> V_86 != 0 ) {
F_21 ( L_15 ,
V_17 -> V_86 ) ;
F_56 ( V_7 , V_17 -> V_21 . V_22 . V_75 ,
V_72 , V_17 -> V_86 ) ;
}
break;
case V_87 :
V_10 -> V_88 =
V_17 -> V_21 . V_89 . V_88 ;
V_10 -> V_90 =
( V_17 -> V_21 . V_89 . V_90 * V_91 ) ;
V_10 -> V_92 = V_17 -> V_21 . V_89 . V_92 ;
V_10 -> V_93 = ( V_17 -> V_21 . V_89 . V_93 * V_91 ) ;
V_10 -> V_94 =
( V_17 -> V_21 . V_89 . V_94 * V_91 ) ;
V_10 -> V_95 =
( V_17 -> V_21 . V_89 . V_95 * V_91 ) ;
V_10 -> V_96 = ( V_17 -> V_21 . V_89 . V_96 * V_91 ) ;
V_10 -> V_97 =
( V_17 -> V_21 . V_89 . V_97 * V_91 ) ;
V_10 -> V_98 = V_17 -> V_21 . V_89 . V_98 ;
V_10 -> V_99 = NULL ;
if ( V_10 -> V_98 > 1 )
V_10 -> V_99 = & V_99 ;
F_57 () ;
if ( F_58 ( V_7 , V_17 -> V_21 . V_89 . V_100 ) )
F_18 ( L_16 ,
V_7 -> V_37 , V_17 -> V_21 . V_89 . V_100 ) ;
F_59 () ;
V_10 -> V_101 = V_17 -> V_21 . V_89 . V_101 ;
break;
case V_102 :
F_60 ( V_10 , V_17 -> V_21 . V_22 . V_78 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_103 :
V_10 -> V_53 =
( unsigned short ) ( 0xffff & V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_104 :
#if F_26 ( V_48 ) || F_26 ( V_49 )
{
F_21 ( L_17 ,
V_7 -> V_37 , V_17 -> V_21 . V_105 . V_75 ) ;
if ( V_106 == NULL )
break;
if ( V_106 ( V_7 , V_17 -> V_21 . V_105 . V_75 ) ) {
struct V_4 * V_15 ;
struct V_13 * V_14 ;
F_21 ( L_18 ,
V_7 -> V_37 ) ;
V_15 = F_7 ( sizeof( struct V_16 ) , V_18 ) ;
if ( V_15 == NULL )
break;
V_15 -> V_19 = sizeof( struct V_16 ) ;
F_61 ( V_15 , V_17 , sizeof( * V_17 ) ) ;
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
F_39 ( V_5 ) ;
return - V_107 ;
}
F_39 ( V_5 ) ;
return 0 ;
}
static void F_62 ( struct V_28 * V_29 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_70 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
V_10 -> V_24 = NULL ;
F_22 ( V_7 ) ;
F_63 ( V_10 ) ;
if ( F_64 ( & F_10 ( V_29 ) -> V_26 ) )
F_18 ( L_20 , V_7 -> V_37 ) ;
while ( ( V_5 = F_43 ( & F_10 ( V_29 ) -> V_26 ) ) ) {
F_65 ( V_29 , V_5 -> V_25 ) ;
F_39 ( V_5 ) ;
}
F_18 ( L_21 , V_7 -> V_37 ) ;
F_66 ( V_108 ) ;
}
static int
F_67 ( struct V_9 * V_10 , T_2 type ,
const unsigned char * V_75 , const unsigned char * V_78 ,
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
V_17 -> V_86 = V_11 -> V_19 ;
if ( V_75 )
F_68 ( V_17 -> V_21 . V_22 . V_75 , V_75 ) ;
else
V_17 -> V_21 . V_22 . V_85 = 1 ;
if ( V_78 )
memcpy ( & V_17 -> V_21 . V_22 . V_78 , V_78 , V_109 ) ;
F_9 ( V_10 -> V_24 , V_5 -> V_25 ) ;
V_14 = F_10 ( V_10 -> V_24 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 ) ;
if ( V_11 != NULL ) {
F_21 ( L_22 , V_11 -> V_19 ) ;
F_9 ( V_10 -> V_24 , V_11 -> V_25 ) ;
F_11 ( & V_14 -> V_26 , V_11 ) ;
V_14 -> V_27 ( V_14 ) ;
}
return 0 ;
}
static int F_69 ( struct V_6 * V_7 , int V_110 )
{
if ( ( V_110 < 68 ) || ( V_110 > 18190 ) )
return - V_107 ;
V_7 -> V_100 = V_110 ;
return 0 ;
}
static void F_70 ( struct V_6 * V_7 )
{
}
static int F_71 ( struct V_28 * V_29 )
{
return ( ( V_29 -> V_111 . V_112 [ 0 ] . V_113 . V_114 . V_115 [ 4 ] == V_116 ) ||
( V_29 -> V_111 . V_112 [ 0 ] . V_113 . V_114 . V_115 [ 4 ] == V_117 ) ) ;
}
static void F_72 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_59 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_70 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
#if V_54 > 0
F_34 ( V_55 L_23 ,
V_7 -> V_37 , V_29 -> V_65 , V_29 -> V_66 ) ;
#endif
if ( ! V_5 ) {
F_21 ( L_24 , V_7 -> V_37 ) ;
F_73 ( V_10 , V_29 ) ;
return;
}
#if V_54 >= 2
#define F_74 99
#elif V_54 >= 1
#define F_74 30
#endif
#if V_54 > 0
F_34 ( V_55 L_25 ,
V_7 -> V_37 , V_5 -> V_19 , V_10 -> V_53 ) ;
F_35 ( V_55 , L_7 , V_56 , 16 , 1 ,
V_5 -> V_11 , F_36 ( F_74 , V_5 -> V_19 ) , true ) ;
#endif
if ( memcmp ( V_5 -> V_11 , V_118 , 4 ) == 0 ) {
struct V_13 * V_14 = F_10 ( V_29 ) ;
F_21 ( L_26 , V_7 -> V_37 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 ) ;
} else {
struct V_1 * V_2 ;
unsigned char * V_119 , * V_42 ;
F_65 ( V_29 , V_5 -> V_25 ) ;
if ( * ( V_120 * ) V_5 -> V_11 == F_32 ( V_10 -> V_53 ) ||
! V_10 -> V_24 || ! ( V_7 -> V_59 & V_121 ) ) {
F_21 ( L_27 ) ;
F_39 ( V_5 ) ;
return;
}
V_42 = ( (struct V_40 * ) V_5 -> V_11 ) -> V_58 ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
if ( F_71 ( V_29 ) ) {
V_119 = ( (struct V_40 * ) V_5 -> V_11 ) -> V_122 ;
V_2 = F_52 ( V_10 , V_119 ) ;
if ( V_2 && V_2 -> V_29 != V_29 ) {
F_53 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
if ( ! ( V_42 [ 0 ] & 0x01 ) &&
! V_10 -> V_101 &&
memcmp ( V_42 , V_7 -> V_74 , V_7 -> V_123 ) ) {
F_39 ( V_5 ) ;
return;
}
if ( ! F_75 ( & V_10 -> V_124 ) )
F_76 ( V_10 , V_29 , V_5 ) ;
F_77 ( V_5 , 2 ) ;
V_5 -> V_125 = F_78 ( V_5 , V_7 ) ;
V_7 -> V_33 . V_126 ++ ;
V_7 -> V_33 . V_127 += V_5 -> V_19 ;
memset ( F_15 ( V_5 ) , 0 , sizeof( struct V_128 ) ) ;
F_79 ( V_5 ) ;
}
}
static void F_80 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
struct V_67 * V_68 = F_45 ( V_29 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_68 == NULL ) {
F_18 ( L_28 ) ;
return;
}
V_68 -> V_129 ( V_29 , V_5 ) ;
if ( V_68 -> V_69 && F_44 ( V_29 , 0 ) ) {
V_68 -> V_69 = 0 ;
if ( F_81 ( V_7 ) && F_82 ( V_7 ) )
F_19 ( V_7 ) ;
}
}
static int F_83 ( struct V_28 * V_29 , void T_3 * V_130 )
{
struct V_67 * V_68 ;
int V_131 ;
struct V_132 V_133 ;
V_131 = F_84 ( & V_133 , V_130 , sizeof( struct V_132 ) ) ;
if ( V_131 != 0 )
F_18 ( L_29 , V_131 ) ;
if ( V_133 . V_134 < 0 || V_133 . V_134 >= V_135 ||
! V_136 [ V_133 . V_134 ] )
return - V_107 ;
V_68 = F_85 ( sizeof( struct V_67 ) , V_137 ) ;
if ( ! V_68 )
return - V_138 ;
V_68 -> V_69 = 0 ;
V_68 -> V_129 = V_29 -> V_139 ;
V_29 -> V_140 = V_68 ;
V_29 -> V_139 = F_80 ;
F_86 ( F_8 ( V_136 [ V_133 . V_134 ] ) ,
& V_133 , V_29 , V_29 -> V_141 ) ;
V_29 -> V_70 = V_136 [ V_133 . V_134 ] ;
V_29 -> V_141 = F_72 ;
return 0 ;
}
static int F_87 ( struct V_28 * V_29 , int V_130 )
{
if ( V_130 < 0 || V_130 >= V_135 || ! V_136 [ V_130 ] )
return - V_107 ;
V_29 -> V_70 = V_136 [ V_130 ] ;
return F_88 ( F_8 ( V_136 [ V_130 ] ) , V_29 ) ;
}
static int F_89 ( struct V_28 * V_29 , int V_130 )
{
int V_71 ;
struct V_9 * V_10 ;
if ( V_130 < 0 )
V_71 = 0 ;
else
V_71 = V_130 ;
if ( V_130 >= V_135 )
return - V_107 ;
if ( ! V_136 [ V_71 ] ) {
int V_142 ;
V_142 = sizeof( struct V_9 ) ;
V_136 [ V_71 ] = F_90 ( V_142 ) ;
if ( ! V_136 [ V_71 ] )
return - V_138 ;
V_136 [ V_71 ] -> V_143 = & V_144 ;
snprintf ( V_136 [ V_71 ] -> V_37 , V_145 , L_30 , V_71 ) ;
if ( F_91 ( V_136 [ V_71 ] ) ) {
F_92 ( V_136 [ V_71 ] ) ;
return - V_107 ;
}
V_10 = F_8 ( V_136 [ V_71 ] ) ;
} else {
V_10 = F_8 ( V_136 [ V_71 ] ) ;
if ( V_10 -> V_24 )
return - V_146 ;
}
F_93 ( V_10 ) ;
V_10 -> V_147 = V_71 ;
V_10 -> V_24 = V_29 ;
V_29 -> V_7 = & V_148 ;
F_94 ( F_10 ( V_29 ) ) ;
V_29 -> V_70 = V_136 [ V_71 ] ;
F_95 ( V_149 , & V_29 -> V_59 ) ;
F_95 ( V_60 , & V_29 -> V_59 ) ;
V_10 -> V_88 = 1 ;
V_10 -> V_90 = ( 1 * V_91 ) ;
V_10 -> V_150 = ( 1200 * V_91 ) ;
V_10 -> V_92 = 1 ;
V_10 -> V_93 = ( 300 * V_91 ) ;
V_10 -> V_94 = ( 15 * V_91 ) ;
V_10 -> V_79 = 0 ;
V_10 -> V_95 = ( 1 * V_91 ) ;
V_10 -> V_96 = ( 4 * V_91 ) ;
V_10 -> V_97 = ( 6 * V_91 ) ;
if ( V_136 [ V_71 ] -> V_59 & V_121 )
F_13 ( V_136 [ V_71 ] ) ;
F_96 ( V_108 ) ;
return V_71 ;
}
static const char * F_97 ( unsigned char V_151 )
{
static const char * const V_152 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36
} ;
if ( V_151 > V_153 )
V_151 = 3 ;
return V_152 [ V_151 ] ;
}
static void F_98 ( struct V_154 * V_155 , struct V_1 * V_2 )
{
int V_71 ;
for ( V_71 = 0 ; V_71 < V_156 ; V_71 ++ )
F_99 ( V_155 , L_37 , V_2 -> V_75 [ V_71 ] & 0xff ) ;
F_99 ( V_155 , L_38 ) ;
for ( V_71 = 0 ; V_71 < V_109 ; V_71 ++ )
F_99 ( V_155 , L_37 , V_2 -> V_78 [ V_71 ] & 0xff ) ;
F_99 ( V_155 , L_39 , F_97 ( V_2 -> V_151 ) ,
V_2 -> V_59 & 0xffff ) ;
if ( V_2 -> V_29 )
F_99 ( V_155 , L_40 , V_2 -> V_29 -> V_65 , V_2 -> V_29 -> V_66 ) ;
else
F_99 ( V_155 , L_41 ) ;
if ( V_2 -> V_157 ) {
F_99 ( V_155 , L_42 , V_2 -> V_157 -> V_65 ,
V_2 -> V_157 -> V_66 ) ;
}
F_100 ( V_155 , '\n' ) ;
}
static void * F_101 ( struct V_158 * V_159 , struct V_160 * V_161 ,
T_4 * V_162 )
{
struct V_163 * V_164 = V_159 -> V_165 ;
if ( ! V_164 )
V_164 = V_161 -> V_166 ;
if ( V_164 == V_167 ) {
V_164 = V_161 -> V_166 ;
-- * V_162 ;
}
for (; V_164 ; V_164 = V_164 -> V_168 ) {
if ( -- * V_162 < 0 )
break;
}
V_159 -> V_165 = V_164 ;
return ( * V_162 < 0 ) ? V_159 : NULL ;
}
static void * F_102 ( struct V_158 * V_159 , T_4 * V_162 ,
struct V_9 * V_10 )
{
void * V_169 = NULL ;
int V_170 ;
for ( V_170 = V_159 -> V_171 ; V_170 < V_172 ; V_170 ++ ) {
V_169 = F_101 ( V_159 , & V_10 -> V_173 [ V_170 ] , V_162 ) ;
if ( V_169 )
break;
}
V_159 -> V_171 = V_170 ;
return V_169 ;
}
static void * F_103 ( struct V_158 * V_159 , T_4 * V_162 ,
struct V_9 * V_10 )
{
struct V_160 * V_174 [] = {
& V_10 -> V_124 ,
& V_10 -> V_175 ,
& V_10 -> V_176
} ;
void * V_169 = NULL ;
int V_177 ;
for ( V_177 = V_159 -> V_178 ; V_177 < F_104 ( V_174 ) ; V_177 ++ ) {
V_169 = F_101 ( V_159 , V_174 [ V_177 ] , V_162 ) ;
if ( V_169 )
break;
}
V_159 -> V_178 = V_177 ;
return V_169 ;
}
static void * F_105 ( struct V_158 * V_159 , T_4 * V_162 ,
struct V_9 * V_10 )
{
if ( ! V_159 -> V_179 ) {
V_159 -> V_179 = V_10 ;
F_51 ( & V_10 -> V_82 , V_159 -> V_59 ) ;
}
if ( ! F_102 ( V_159 , V_162 , V_10 ) && ! F_103 ( V_159 , V_162 , V_10 ) ) {
F_54 ( & V_10 -> V_82 , V_159 -> V_59 ) ;
V_159 -> V_179 = NULL ;
V_159 -> V_171 = V_159 -> V_178 = 0 ;
}
return V_159 -> V_179 ;
}
static void * F_106 ( struct V_158 * V_159 , T_4 * V_162 )
{
struct V_6 * V_7 ;
void * V_169 ;
V_7 = V_159 -> V_7 ? V_159 -> V_7 : V_136 [ V_159 -> V_180 ] ;
V_169 = ( V_7 && F_8 ( V_7 ) ) ?
F_105 ( V_159 , V_162 , F_8 ( V_7 ) ) : NULL ;
if ( ! V_169 && V_7 ) {
F_107 ( V_7 ) ;
V_7 = NULL ;
}
V_159 -> V_7 = V_7 ;
return V_169 ;
}
static void * F_108 ( struct V_158 * V_159 , T_4 V_162 )
{
void * V_169 = NULL ;
for (; V_159 -> V_180 < V_135 ; V_159 -> V_180 ++ ) {
V_169 = F_106 ( V_159 , & V_162 ) ;
if ( V_169 )
break;
}
return V_169 ;
}
static void * F_109 ( struct V_154 * V_155 , T_4 * V_181 )
{
struct V_158 * V_159 = V_155 -> V_182 ;
V_159 -> V_180 = 0 ;
V_159 -> V_7 = NULL ;
V_159 -> V_179 = NULL ;
V_159 -> V_171 = 0 ;
V_159 -> V_178 = 0 ;
V_159 -> V_165 = V_167 ;
return * V_181 ? F_108 ( V_159 , * V_181 ) : V_167 ;
}
static void F_110 ( struct V_154 * V_155 , void * V_169 )
{
struct V_158 * V_159 = V_155 -> V_182 ;
if ( V_159 -> V_7 ) {
F_54 ( & V_159 -> V_179 -> V_82 ,
V_159 -> V_59 ) ;
F_107 ( V_159 -> V_7 ) ;
}
}
static void * F_111 ( struct V_154 * V_155 , void * V_169 , T_4 * V_181 )
{
struct V_158 * V_159 = V_155 -> V_182 ;
V_169 = F_108 ( V_159 , 1 ) ;
* V_181 += ! ! F_112 ( V_169 ) ;
return V_169 ;
}
static int F_113 ( struct V_154 * V_155 , void * V_169 )
{
static const char V_183 [] =
L_43
L_44
L_45 ;
if ( V_169 == V_167 )
F_114 ( V_155 , V_183 ) ;
else {
struct V_158 * V_159 = V_155 -> V_182 ;
struct V_6 * V_7 = V_159 -> V_7 ;
struct V_1 * V_2 = F_115 ( V_159 -> V_165 ,
struct V_1 ,
V_168 ) ;
F_99 ( V_155 , L_46 , V_7 -> V_37 ) ;
F_98 ( V_155 , V_2 ) ;
}
return 0 ;
}
static int F_116 ( struct V_184 * V_184 , struct V_185 * V_185 )
{
return F_117 ( V_185 , & V_186 , sizeof( struct V_158 ) ) ;
}
static int F_118 ( struct V_187 * V_13 , unsigned int V_188 , unsigned long V_130 )
{
struct V_28 * V_29 = F_119 ( V_13 ) ;
int V_189 = 0 ;
switch ( V_188 ) {
case V_190 :
case V_191 :
case V_192 :
if ( ! F_120 ( V_193 ) )
return - V_194 ;
break;
default:
return - V_195 ;
}
switch ( V_188 ) {
case V_190 :
V_189 = F_89 ( V_29 , ( int ) V_130 ) ;
if ( V_189 >= 0 )
V_13 -> V_159 = V_196 ;
break;
case V_191 :
V_189 = F_87 ( V_29 , ( int ) V_130 ) ;
break;
case V_192 :
V_189 = F_83 ( V_29 , ( void T_3 * ) V_130 ) ;
break;
}
return V_189 ;
}
static int T_5 F_121 ( void )
{
#ifdef F_122
struct V_197 * V_170 ;
V_170 = F_123 ( L_47 , V_198 , V_199 , & V_200 ) ;
if ( ! V_170 ) {
F_124 ( L_48 ) ;
return - V_138 ;
}
#endif
F_125 ( & V_201 ) ;
F_18 ( L_49 ) ;
return 0 ;
}
static void T_6 F_126 ( void )
{
int V_71 ;
F_127 ( L_47 , V_199 ) ;
F_128 ( & V_201 ) ;
for ( V_71 = 0 ; V_71 < V_135 ; V_71 ++ ) {
if ( V_136 [ V_71 ] != NULL ) {
F_129 ( V_136 [ V_71 ] ) ;
F_92 ( V_136 [ V_71 ] ) ;
V_136 [ V_71 ] = NULL ;
}
}
}
static int F_130 ( struct V_6 * V_7 , const T_7 * V_202 , int V_203 ,
T_7 * * V_204 , T_8 * V_86 )
{
unsigned long V_59 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_1 * V_205 ;
struct V_4 * V_5 ;
int V_206 ;
if ( V_203 == 0 ) {
F_51 ( & V_10 -> V_82 , V_59 ) ;
V_205 = F_52 ( V_10 , V_202 ) ;
F_54 ( & V_10 -> V_82 , V_59 ) ;
if ( V_205 == NULL )
return - 1 ;
* V_204 = F_131 ( V_205 -> V_204 , V_205 -> V_86 , V_18 ) ;
if ( * V_204 == NULL )
return - 1 ;
* V_86 = V_205 -> V_86 ;
return 0 ;
}
if ( V_86 == NULL )
V_206 = F_67 ( V_10 , V_207 , V_202 , NULL , NULL ) ;
else {
V_5 = F_7 ( * V_86 , V_18 ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 -> V_19 = * V_86 ;
F_61 ( V_5 , * V_204 , * V_86 ) ;
V_206 = F_67 ( V_10 , V_207 , V_202 , NULL , V_5 ) ;
}
return V_206 ;
}
static int F_132 ( struct V_6 * V_7 , const T_7 * V_208 ,
const T_7 * V_204 , T_8 V_86 )
{
int V_206 ;
struct V_4 * V_5 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
if ( ! F_133 ( V_208 , V_7 -> V_74 ) )
return 0 ;
F_5 ( V_10 -> V_204 ) ;
V_10 -> V_204 = F_131 ( V_204 , V_86 , V_137 ) ;
if ( V_10 -> V_204 == NULL )
return 0 ;
V_10 -> V_86 = V_86 ;
V_5 = F_7 ( V_86 , V_18 ) ;
if ( V_5 == NULL )
return 0 ;
V_5 -> V_19 = V_86 ;
F_61 ( V_5 , V_204 , V_86 ) ;
V_206 = F_67 ( V_10 , V_209 , NULL , NULL , V_5 ) ;
if ( V_206 != 0 )
F_18 ( L_50 ) ;
return 1 ;
}
static void F_56 ( struct V_6 * V_7 , const T_7 * V_75 ,
const T_7 * V_204 , T_8 V_86 )
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
if ( V_10 -> V_99 && V_10 -> V_99 -> V_210 ) {
V_10 -> V_99 -> V_210 ( V_7 , V_75 ,
V_204 , V_86 ) ;
}
}
static void F_93 ( struct V_9 * V_10 )
{
unsigned short V_71 ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ )
F_134 ( & V_10 -> V_173 [ V_71 ] ) ;
F_134 ( & V_10 -> V_124 ) ;
F_134 ( & V_10 -> V_175 ) ;
F_134 ( & V_10 -> V_176 ) ;
F_135 ( & V_10 -> V_82 ) ;
F_136 ( & V_10 -> V_211 , V_212 ) ;
F_137 ( & V_10 -> V_211 , V_213 ) ;
}
static void F_138 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 ) {
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_67 * V_68 = F_45 ( V_29 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_70 ;
V_29 -> V_139 = V_68 -> V_129 ;
if ( V_68 -> V_69 )
F_19 ( V_7 ) ;
F_5 ( V_68 ) ;
V_29 -> V_140 = NULL ;
V_29 -> V_141 = V_2 -> V_214 ;
F_139 ( V_29 , - V_215 ) ;
V_2 -> V_29 = NULL ;
}
if ( V_2 -> V_157 ) {
V_2 -> V_157 -> V_141 = V_2 -> V_216 ;
F_139 ( V_2 -> V_157 , - V_215 ) ;
V_2 -> V_157 = NULL ;
}
}
static inline void
F_140 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_160 * V_72 ;
V_72 = & V_10 -> V_173 [ F_141 ( V_2 -> V_75 [ V_156 - 1 ] ) ] ;
F_142 ( & V_2 -> V_168 , V_72 ) ;
F_21 ( L_51 , V_2 -> V_75 ) ;
}
static int
F_53 ( struct V_9 * V_10 , struct V_1 * V_217 )
{
struct V_1 * V_2 ;
int V_71 , V_218 = 1 ;
if ( ! V_217 )
return - 1 ;
F_143 ( & V_217 -> V_168 ) ;
F_144 ( & V_217 -> V_219 ) ;
if ( V_217 -> V_151 >= V_220 ) {
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_145 (entry,
&priv->lec_arp_tables[i], next) {
if ( memcmp ( V_217 -> V_78 ,
V_2 -> V_78 , V_109 ) == 0 ) {
V_218 = 0 ;
break;
}
}
}
if ( V_218 )
F_138 ( V_217 ) ;
}
F_146 ( & V_217 -> V_61 ) ;
F_21 ( L_52 , V_217 -> V_75 ) ;
return 0 ;
}
static const char * F_147 ( unsigned char V_221 )
{
switch ( V_221 ) {
case V_222 :
return L_53 ;
case V_223 :
return L_54 ;
case V_224 :
return L_55 ;
case V_220 :
return L_56 ;
case V_153 :
return L_36 ;
}
return L_57 ;
}
static void F_148 ( struct V_9 * V_10 )
{
struct V_1 * V_225 ;
char V_226 [ 256 ] ;
int V_71 , V_227 , V_228 ;
F_18 ( L_58 , V_10 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_145 (rulla,
&priv->lec_arp_tables[i], next) {
V_228 = 0 ;
V_228 += sprintf ( V_226 , L_59 , V_71 , V_225 ) ;
V_228 += sprintf ( V_226 + V_228 , L_60 ,
V_225 -> V_75 ) ;
V_228 += sprintf ( V_226 + V_228 , L_61 ) ;
for ( V_227 = 0 ; V_227 < V_109 ; V_227 ++ ) {
V_228 += sprintf ( V_226 + V_228 ,
L_62 ,
V_225 -> V_78 [ V_227 ] & 0xff ) ;
}
V_228 += sprintf ( V_226 + V_228 ,
L_63 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_65 : 0 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_66 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 ->
V_65 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 ->
V_66 : 0 , V_225 -> V_229 ,
V_225 -> V_230 , V_225 -> V_231 ) ;
V_228 +=
sprintf ( V_226 + V_228 ,
L_64 ,
V_225 -> V_59 , V_225 -> V_232 ,
F_147 ( V_225 -> V_151 ) ) ;
F_18 ( L_1 , V_226 ) ;
}
}
if ( ! F_75 ( & V_10 -> V_175 ) )
F_18 ( L_65 ) ;
F_145 (rulla, &priv->lec_no_forward, next) {
V_228 = 0 ;
V_228 += sprintf ( V_226 + V_228 , L_60 , V_225 -> V_75 ) ;
V_228 += sprintf ( V_226 + V_228 , L_61 ) ;
for ( V_227 = 0 ; V_227 < V_109 ; V_227 ++ ) {
V_228 += sprintf ( V_226 + V_228 , L_62 ,
V_225 -> V_78 [ V_227 ] & 0xff ) ;
}
V_228 += sprintf ( V_226 + V_228 ,
L_63 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_65 : 0 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_66 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 -> V_65 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 -> V_66 : 0 ,
V_225 -> V_229 ,
V_225 -> V_230 , V_225 -> V_231 ) ;
V_228 += sprintf ( V_226 + V_228 ,
L_64 ,
V_225 -> V_59 , V_225 -> V_232 ,
F_147 ( V_225 -> V_151 ) ) ;
F_18 ( L_1 , V_226 ) ;
}
if ( ! F_75 ( & V_10 -> V_124 ) )
F_18 ( L_66 ) ;
F_145 (rulla, &priv->lec_arp_empty_ones, next) {
V_228 = 0 ;
V_228 += sprintf ( V_226 + V_228 , L_60 , V_225 -> V_75 ) ;
V_228 += sprintf ( V_226 + V_228 , L_61 ) ;
for ( V_227 = 0 ; V_227 < V_109 ; V_227 ++ ) {
V_228 += sprintf ( V_226 + V_228 , L_62 ,
V_225 -> V_78 [ V_227 ] & 0xff ) ;
}
V_228 += sprintf ( V_226 + V_228 ,
L_63 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_65 : 0 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_66 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 -> V_65 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 -> V_66 : 0 ,
V_225 -> V_229 ,
V_225 -> V_230 , V_225 -> V_231 ) ;
V_228 += sprintf ( V_226 + V_228 ,
L_64 ,
V_225 -> V_59 , V_225 -> V_232 ,
F_147 ( V_225 -> V_151 ) ) ;
F_18 ( L_67 , V_226 ) ;
}
if ( ! F_75 ( & V_10 -> V_176 ) )
F_18 ( L_68 ) ;
F_145 (rulla, &priv->mcast_fwds, next) {
V_228 = 0 ;
V_228 += sprintf ( V_226 + V_228 , L_60 , V_225 -> V_75 ) ;
V_228 += sprintf ( V_226 + V_228 , L_61 ) ;
for ( V_227 = 0 ; V_227 < V_109 ; V_227 ++ ) {
V_228 += sprintf ( V_226 + V_228 , L_62 ,
V_225 -> V_78 [ V_227 ] & 0xff ) ;
}
V_228 += sprintf ( V_226 + V_228 ,
L_63 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_65 : 0 ,
V_225 -> V_29 ? V_225 -> V_29 -> V_66 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 -> V_65 : 0 ,
V_225 -> V_157 ? V_225 -> V_157 -> V_66 : 0 ,
V_225 -> V_229 ,
V_225 -> V_230 , V_225 -> V_231 ) ;
V_228 += sprintf ( V_226 + V_228 ,
L_64 ,
V_225 -> V_59 , V_225 -> V_232 ,
F_147 ( V_225 -> V_151 ) ) ;
F_18 ( L_1 , V_226 ) ;
}
}
static void F_63 ( struct V_9 * V_10 )
{
unsigned long V_59 ;
struct V_163 * V_168 ;
struct V_1 * V_2 ;
int V_71 ;
F_149 ( & V_10 -> V_211 ) ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_150 (entry, next,
&priv->lec_arp_tables[i], next) {
F_53 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_134 ( & V_10 -> V_173 [ V_71 ] ) ;
}
F_150 (entry, next,
&priv->lec_arp_empty_ones, next) {
F_151 ( & V_2 -> V_219 ) ;
F_138 ( V_2 ) ;
F_143 ( & V_2 -> V_168 ) ;
F_3 ( V_2 ) ;
}
F_134 ( & V_10 -> V_124 ) ;
F_150 (entry, next,
&priv->lec_no_forward, next) {
F_151 ( & V_2 -> V_219 ) ;
F_138 ( V_2 ) ;
F_143 ( & V_2 -> V_168 ) ;
F_3 ( V_2 ) ;
}
F_134 ( & V_10 -> V_175 ) ;
F_150 (entry, next, &priv->mcast_fwds, next) {
F_138 ( V_2 ) ;
F_143 ( & V_2 -> V_168 ) ;
F_3 ( V_2 ) ;
}
F_134 ( & V_10 -> V_176 ) ;
V_10 -> V_233 = NULL ;
F_54 ( & V_10 -> V_82 , V_59 ) ;
}
static struct V_1 * F_52 ( struct V_9 * V_10 ,
const unsigned char * V_75 )
{
struct V_160 * V_47 ;
struct V_1 * V_2 ;
F_21 ( L_69 , V_75 ) ;
V_47 = & V_10 -> V_173 [ F_141 ( V_75 [ V_156 - 1 ] ) ] ;
F_145 (entry, head, next) {
if ( F_133 ( V_75 , V_2 -> V_75 ) )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_152 ( struct V_9 * V_10 ,
const unsigned char * V_75 )
{
struct V_1 * V_234 ;
V_234 = F_153 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_234 ) {
F_18 ( L_70 ) ;
return NULL ;
}
F_68 ( V_234 -> V_75 , V_75 ) ;
F_154 ( & V_234 -> V_168 ) ;
F_155 ( & V_234 -> V_219 , V_235 ,
( unsigned long ) V_234 ) ;
V_234 -> V_229 = V_39 ;
V_234 -> V_10 = V_10 ;
F_156 ( & V_234 -> V_61 ) ;
F_157 ( & V_234 -> V_3 , 1 ) ;
return V_234 ;
}
static void V_235 ( unsigned long V_11 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_11 ;
F_21 ( L_71 ) ;
if ( V_2 -> V_151 == V_223 ) {
if ( V_2 -> V_231 <= V_2 -> V_10 -> V_92 ) {
if ( V_2 -> V_44 )
F_67 ( V_2 -> V_10 , V_236 ,
V_2 -> V_75 , NULL , NULL ) ;
else
F_67 ( V_2 -> V_10 , V_207 ,
V_2 -> V_75 , NULL , NULL ) ;
V_2 -> V_231 ++ ;
}
F_158 ( & V_2 -> V_219 , V_39 + ( 1 * V_91 ) ) ;
}
}
static void F_159 ( unsigned long V_11 )
{
unsigned long V_59 ;
struct V_1 * V_217 = (struct V_1 * ) V_11 ;
struct V_9 * V_10 = V_217 -> V_10 ;
F_144 ( & V_217 -> V_219 ) ;
F_21 ( L_72 ,
V_217 , V_10 ,
V_217 -> V_29 ? V_217 -> V_157 -> V_65 : 0 ,
V_217 -> V_29 ? V_217 -> V_157 -> V_66 : 0 ) ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
F_143 ( & V_217 -> V_168 ) ;
F_54 ( & V_10 -> V_82 , V_59 ) ;
F_138 ( V_217 ) ;
F_3 ( V_217 ) ;
}
static bool F_160 ( struct V_1 * V_2 ,
unsigned long V_237 ,
struct V_9 * V_10 )
{
unsigned long V_238 ;
if ( ( V_2 -> V_59 ) & V_239 && V_10 -> V_79 )
V_238 = V_10 -> V_94 ;
else
V_238 = V_10 -> V_93 ;
F_21 ( L_73 ,
V_237 , V_2 -> V_229 , V_238 ) ;
if ( F_161 ( V_237 , V_2 -> V_229 + V_238 ) &&
! ( V_2 -> V_59 & V_240 ) &&
! ( V_2 -> V_75 [ 0 ] & 0x01 ) ) {
F_21 ( L_74 ) ;
F_53 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
} else {
if ( ( V_2 -> V_151 == V_224 ||
V_2 -> V_151 == V_223 ) &&
F_162 ( V_237 , V_2 -> V_230 +
V_10 -> V_90 ) ) {
V_2 -> V_230 = V_39 ;
V_2 -> V_232 = 0 ;
if ( V_2 -> V_151 == V_224 )
F_67 ( V_10 , V_241 ,
V_2 -> V_75 ,
V_2 -> V_78 ,
NULL ) ;
}
if ( V_2 -> V_151 == V_220 &&
F_162 ( V_237 , V_2 -> V_230 +
V_10 -> V_97 ) ) {
F_1 ( V_2 ) ;
return true ;
}
}
return false ;
}
static void V_212 ( struct V_242 * V_243 )
{
unsigned long V_59 ;
struct V_9 * V_10 =
F_163 ( V_243 , struct V_9 , V_211 . V_243 ) ;
struct V_163 * V_168 ;
struct V_1 * V_2 ;
unsigned long V_237 ;
int V_71 ;
F_21 ( L_75 , V_10 ) ;
V_237 = V_39 ;
V_244:
F_51 ( & V_10 -> V_82 , V_59 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_150 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( F_160 ( V_2 , V_237 , V_10 ) ) {
struct V_4 * V_5 ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_54 ( & V_10 -> V_82 ,
V_59 ) ;
while ( ( V_5 = F_43 ( & V_2 -> V_61 ) ) )
F_14 ( V_29 , V_5 ) ;
V_2 -> V_229 = V_39 ;
V_2 -> V_151 = V_153 ;
F_3 ( V_2 ) ;
goto V_244;
}
}
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
F_137 ( & V_10 -> V_211 , V_213 ) ;
}
static struct V_28 * F_41 ( struct V_9 * V_10 ,
const unsigned char * V_245 ,
int V_44 ,
struct V_1 * * V_246 )
{
unsigned long V_59 ;
struct V_1 * V_2 ;
struct V_28 * V_247 ;
if ( V_245 [ 0 ] & 0x01 ) {
switch ( V_10 -> V_98 ) {
case 1 :
return V_10 -> V_233 ;
case 2 :
if ( F_133 ( V_245 , V_248 ) )
return V_10 -> V_233 ;
break;
default:
break;
}
}
F_51 ( & V_10 -> V_82 , V_59 ) ;
V_2 = F_52 ( V_10 , V_245 ) ;
if ( V_2 ) {
if ( V_2 -> V_151 == V_153 ) {
V_2 -> V_229 = V_39 ;
F_1 ( V_2 ) ;
* V_246 = V_2 ;
V_247 = V_2 -> V_29 ;
goto V_64;
}
if ( V_2 -> V_151 == V_223 )
V_2 -> V_231 = 0 ;
if ( V_2 -> V_151 != V_220 &&
V_2 -> V_232 <
V_10 -> V_88 ) {
V_2 -> V_232 ++ ;
F_21 ( L_76 ) ;
V_247 = V_10 -> V_233 ;
goto V_64;
}
F_1 ( V_2 ) ;
* V_246 = V_2 ;
F_21 ( L_77 , V_2 -> V_151 ,
V_2 -> V_29 ) ;
V_247 = NULL ;
} else {
V_2 = F_152 ( V_10 , V_245 ) ;
F_21 ( L_78 ) ;
if ( ! V_2 ) {
V_247 = V_10 -> V_233 ;
goto V_64;
}
F_140 ( V_10 , V_2 ) ;
V_2 -> V_232 = 1 ;
V_2 -> V_151 = V_223 ;
V_2 -> V_231 = 1 ;
V_2 -> V_229 = V_2 -> V_230 = V_39 ;
V_2 -> V_44 = V_44 ;
if ( V_2 -> V_44 )
F_67 ( V_10 , V_236 , V_245 , NULL ,
NULL ) ;
else
F_67 ( V_10 , V_207 , V_245 , NULL , NULL ) ;
V_2 -> V_219 . V_249 = V_39 + ( 1 * V_91 ) ;
V_2 -> V_219 . V_250 = V_235 ;
F_164 ( & V_2 -> V_219 ) ;
V_247 = V_10 -> V_233 ;
}
V_64:
F_54 ( & V_10 -> V_82 , V_59 ) ;
return V_247 ;
}
static int
F_49 ( struct V_9 * V_10 , const unsigned char * V_78 ,
unsigned long V_251 )
{
unsigned long V_59 ;
struct V_163 * V_168 ;
struct V_1 * V_2 ;
int V_71 ;
F_21 ( L_71 ) ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_150 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_78 , V_2 -> V_78 , V_109 ) &&
( V_251 ||
! ( V_2 -> V_59 & V_240 ) ) ) {
F_53 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
return 0 ;
}
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
return - 1 ;
}
static void
F_55 ( struct V_9 * V_10 , const unsigned char * V_75 ,
const unsigned char * V_78 , unsigned long V_252 ,
unsigned int V_85 )
{
unsigned long V_59 ;
struct V_163 * V_168 ;
struct V_1 * V_2 , * V_72 ;
int V_71 ;
F_21 ( L_79 ,
( V_85 ) ? L_80 : L_7 , V_75 ) ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
V_2 = F_52 ( V_10 , V_75 ) ;
if ( V_2 == NULL && V_85 )
goto V_64;
if ( ! F_75 ( & V_10 -> V_124 ) ) {
F_150 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( memcmp ( V_2 -> V_78 , V_78 , V_109 ) == 0 ) {
F_143 ( & V_2 -> V_168 ) ;
F_144 ( & V_2 -> V_219 ) ;
V_72 = F_52 ( V_10 , V_75 ) ;
if ( V_72 ) {
F_144 ( & V_72 -> V_219 ) ;
V_72 -> V_151 = V_153 ;
memcpy ( V_72 -> V_78 , V_78 , V_109 ) ;
V_72 -> V_29 = V_2 -> V_29 ;
V_72 -> V_214 = V_2 -> V_214 ;
V_72 -> V_229 = V_39 ;
F_144 ( & V_2 -> V_219 ) ;
F_3 ( V_2 ) ;
V_2 = V_72 ;
} else {
V_2 -> V_151 = V_153 ;
F_68 ( V_2 -> V_75 ,
V_75 ) ;
V_2 -> V_229 = V_39 ;
F_140 ( V_10 , V_2 ) ;
}
if ( V_252 )
V_2 -> V_59 |= V_239 ;
else
V_2 -> V_59 &= ~ V_239 ;
F_21 ( L_81 ) ;
F_148 ( V_10 ) ;
goto V_64;
}
}
}
V_2 = F_52 ( V_10 , V_75 ) ;
if ( ! V_2 ) {
V_2 = F_152 ( V_10 , V_75 ) ;
if ( ! V_2 )
goto V_64;
V_2 -> V_151 = V_222 ;
F_140 ( V_10 , V_2 ) ;
}
memcpy ( V_2 -> V_78 , V_78 , V_109 ) ;
F_144 ( & V_2 -> V_219 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_145 (tmp,
&priv->lec_arp_tables[i], next) {
if ( V_2 != V_72 &&
! memcmp ( V_72 -> V_78 , V_78 , V_109 ) ) {
if ( V_72 -> V_151 > V_224 ) {
V_2 -> V_29 = V_72 -> V_29 ;
V_2 -> V_214 = V_72 -> V_214 ;
}
V_2 -> V_151 = V_72 -> V_151 ;
break;
}
}
}
if ( V_252 )
V_2 -> V_59 |= V_239 ;
else
V_2 -> V_59 &= ~ V_239 ;
if ( V_2 -> V_151 == V_223 || V_2 -> V_151 == V_222 ) {
V_2 -> V_151 = V_224 ;
F_67 ( V_10 , V_241 , V_2 -> V_75 , V_78 , NULL ) ;
}
F_21 ( L_82 ) ;
F_148 ( V_10 ) ;
V_64:
F_54 ( & V_10 -> V_82 , V_59 ) ;
}
static void
F_86 ( struct V_9 * V_10 , const struct V_132 * V_133 ,
struct V_28 * V_29 ,
void (* V_214) ( struct V_28 * V_29 , struct V_4 * V_5 ) )
{
unsigned long V_59 ;
struct V_1 * V_2 ;
int V_71 , V_253 = 0 ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
if ( V_133 -> V_254 == 2 ) {
F_21 ( L_83 ) ;
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
V_2 = F_152 ( V_10 , V_248 ) ;
if ( V_2 == NULL )
goto V_64;
F_144 ( & V_2 -> V_219 ) ;
memcpy ( V_2 -> V_78 , V_133 -> V_78 , V_109 ) ;
V_2 -> V_157 = V_29 ;
V_2 -> V_216 = V_214 ;
F_142 ( & V_2 -> V_168 , & V_10 -> V_176 ) ;
goto V_64;
} else if ( V_133 -> V_254 == 1 ) {
F_21 ( L_84 ,
V_133 -> V_78 [ 0 ] , V_133 -> V_78 [ 1 ] ,
V_133 -> V_78 [ 2 ] , V_133 -> V_78 [ 3 ] ,
V_133 -> V_78 [ 4 ] , V_133 -> V_78 [ 5 ] ,
V_133 -> V_78 [ 6 ] , V_133 -> V_78 [ 7 ] ,
V_133 -> V_78 [ 8 ] , V_133 -> V_78 [ 9 ] ,
V_133 -> V_78 [ 10 ] , V_133 -> V_78 [ 11 ] ,
V_133 -> V_78 [ 12 ] , V_133 -> V_78 [ 13 ] ,
V_133 -> V_78 [ 14 ] , V_133 -> V_78 [ 15 ] ,
V_133 -> V_78 [ 16 ] , V_133 -> V_78 [ 17 ] ,
V_133 -> V_78 [ 18 ] , V_133 -> V_78 [ 19 ] ) ;
V_2 = F_152 ( V_10 , V_248 ) ;
if ( V_2 == NULL )
goto V_64;
memcpy ( V_2 -> V_78 , V_133 -> V_78 , V_109 ) ;
F_165 ( V_2 -> V_75 ) ;
V_2 -> V_157 = V_29 ;
V_2 -> V_216 = V_214 ;
V_2 -> V_151 = V_222 ;
V_2 -> V_219 . V_249 = V_39 + V_10 -> V_150 ;
V_2 -> V_219 . V_250 = F_159 ;
F_142 ( & V_2 -> V_168 , & V_10 -> V_175 ) ;
F_164 ( & V_2 -> V_219 ) ;
F_148 ( V_10 ) ;
goto V_64;
}
F_21 ( L_85 ,
V_133 -> V_78 [ 0 ] , V_133 -> V_78 [ 1 ] ,
V_133 -> V_78 [ 2 ] , V_133 -> V_78 [ 3 ] ,
V_133 -> V_78 [ 4 ] , V_133 -> V_78 [ 5 ] ,
V_133 -> V_78 [ 6 ] , V_133 -> V_78 [ 7 ] ,
V_133 -> V_78 [ 8 ] , V_133 -> V_78 [ 9 ] ,
V_133 -> V_78 [ 10 ] , V_133 -> V_78 [ 11 ] ,
V_133 -> V_78 [ 12 ] , V_133 -> V_78 [ 13 ] ,
V_133 -> V_78 [ 14 ] , V_133 -> V_78 [ 15 ] ,
V_133 -> V_78 [ 16 ] , V_133 -> V_78 [ 17 ] ,
V_133 -> V_78 [ 18 ] , V_133 -> V_78 [ 19 ] ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_145 (entry,
&priv->lec_arp_tables[i], next) {
if ( memcmp
( V_133 -> V_78 , V_2 -> V_78 ,
V_109 ) == 0 ) {
F_21 ( L_86 ) ;
F_21 ( L_87 ,
V_2 -> V_29 ? V_2 -> V_29 -> V_66 : 0 ,
V_2 -> V_157 ? V_2 -> V_157 ->
V_66 : 0 ) ;
V_253 = 1 ;
F_144 ( & V_2 -> V_219 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_214 = V_214 ;
if ( V_2 -> V_151 == V_224 ) {
if ( V_10 -> V_88
== 0 )
V_2 -> V_151 =
V_153 ;
else {
V_2 -> V_230 = V_39 ;
V_2 -> V_151 =
V_220 ;
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
if ( V_253 ) {
F_21 ( L_88 ) ;
F_148 ( V_10 ) ;
goto V_64;
}
V_2 = F_152 ( V_10 , V_248 ) ;
if ( ! V_2 )
goto V_64;
V_2 -> V_29 = V_29 ;
V_2 -> V_214 = V_214 ;
memcpy ( V_2 -> V_78 , V_133 -> V_78 , V_109 ) ;
F_165 ( V_2 -> V_75 ) ;
V_2 -> V_151 = V_222 ;
F_142 ( & V_2 -> V_168 , & V_10 -> V_124 ) ;
V_2 -> V_219 . V_249 = V_39 + V_10 -> V_150 ;
V_2 -> V_219 . V_250 = F_159 ;
F_164 ( & V_2 -> V_219 ) ;
F_21 ( L_88 ) ;
F_148 ( V_10 ) ;
V_64:
F_54 ( & V_10 -> V_82 , V_59 ) ;
}
static void F_50 ( struct V_9 * V_10 , unsigned long V_255 )
{
unsigned long V_59 ;
struct V_1 * V_2 ;
int V_71 ;
F_21 ( L_89 , V_255 ) ;
V_244:
F_51 ( & V_10 -> V_82 , V_59 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_145 (entry,
&priv->lec_arp_tables[i], next) {
if ( V_2 -> V_256 == V_255 &&
V_2 -> V_151 == V_220 ) {
struct V_4 * V_5 ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_1 ( V_2 ) ;
F_54 ( & V_10 -> V_82 ,
V_59 ) ;
while ( ( V_5 = F_43 ( & V_2 -> V_61 ) ) )
F_14 ( V_29 , V_5 ) ;
V_2 -> V_229 = V_39 ;
V_2 -> V_151 = V_153 ;
F_3 ( V_2 ) ;
F_21 ( L_90 ) ;
goto V_244;
}
}
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
F_148 ( V_10 ) ;
}
static void
F_60 ( struct V_9 * V_10 ,
const unsigned char * V_78 , unsigned long V_255 )
{
unsigned long V_59 ;
struct V_1 * V_2 ;
int V_71 ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ )
F_145 (entry,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_78 , V_2 -> V_78 , V_109 ) ) {
V_2 -> V_256 = V_255 ;
F_21 ( L_91 ,
V_255 , V_2 ) ;
}
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
}
static int F_88 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
unsigned long V_59 ;
unsigned char V_75 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
struct V_1 * V_257 ;
struct V_67 * V_68 ;
int V_189 = 0 ;
V_68 = F_85 ( sizeof( struct V_67 ) , V_137 ) ;
if ( ! V_68 )
return - V_138 ;
V_68 -> V_69 = 0 ;
V_68 -> V_129 = V_29 -> V_139 ;
V_29 -> V_140 = V_68 ;
V_29 -> V_139 = F_80 ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
V_257 = F_152 ( V_10 , V_75 ) ;
if ( ! V_257 ) {
V_29 -> V_139 = V_68 -> V_129 ;
F_5 ( V_68 ) ;
V_189 = - V_138 ;
goto V_64;
}
memcpy ( V_257 -> V_78 , V_29 -> V_258 . V_259 . V_260 , V_109 ) ;
V_257 -> V_151 = V_153 ;
V_257 -> V_59 |= V_240 ;
V_257 -> V_29 = V_29 ;
V_257 -> V_214 = V_29 -> V_141 ;
V_29 -> V_141 = F_72 ;
V_10 -> V_233 = V_29 ;
F_140 ( V_10 , V_257 ) ;
V_64:
F_54 ( & V_10 -> V_82 , V_59 ) ;
return V_189 ;
}
static void F_73 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
unsigned long V_59 ;
struct V_163 * V_168 ;
struct V_1 * V_2 ;
int V_71 ;
F_21 ( L_92 , V_29 -> V_65 , V_29 -> V_66 ) ;
F_148 ( V_10 ) ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
for ( V_71 = 0 ; V_71 < V_172 ; V_71 ++ ) {
F_150 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( V_29 == V_2 -> V_29 ) {
F_53 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_10 -> V_233 == V_29 )
V_10 -> V_233 = NULL ;
}
}
}
F_150 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( V_2 -> V_29 == V_29 ) {
F_138 ( V_2 ) ;
F_144 ( & V_2 -> V_219 ) ;
F_143 ( & V_2 -> V_168 ) ;
F_3 ( V_2 ) ;
}
}
F_150 (entry, next,
&priv->lec_no_forward, next) {
if ( V_2 -> V_157 == V_29 ) {
F_138 ( V_2 ) ;
F_144 ( & V_2 -> V_219 ) ;
F_143 ( & V_2 -> V_168 ) ;
F_3 ( V_2 ) ;
}
}
F_150 (entry, next, &priv->mcast_fwds, next) {
if ( V_2 -> V_157 == V_29 ) {
F_138 ( V_2 ) ;
F_143 ( & V_2 -> V_168 ) ;
F_3 ( V_2 ) ;
}
}
F_54 ( & V_10 -> V_82 , V_59 ) ;
F_148 ( V_10 ) ;
}
static void
F_76 ( struct V_9 * V_10 ,
struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_59 ;
struct V_163 * V_168 ;
struct V_1 * V_2 , * V_72 ;
struct V_40 * V_261 = (struct V_40 * ) V_5 -> V_11 ;
unsigned char * V_119 = V_261 -> V_122 ;
F_51 ( & V_10 -> V_82 , V_59 ) ;
F_150 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( V_29 == V_2 -> V_29 ) {
F_144 ( & V_2 -> V_219 ) ;
F_68 ( V_2 -> V_75 , V_119 ) ;
V_2 -> V_151 = V_153 ;
V_2 -> V_229 = V_39 ;
V_72 = F_52 ( V_10 , V_119 ) ;
if ( V_72 ) {
F_53 ( V_10 , V_72 ) ;
F_3 ( V_72 ) ;
}
F_143 ( & V_2 -> V_168 ) ;
F_140 ( V_10 , V_2 ) ;
goto V_64;
}
}
F_21 ( L_93 ) ;
V_64:
F_54 ( & V_10 -> V_82 , V_59 ) ;
}
