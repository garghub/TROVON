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
#if F_27 ( V_46 ) || F_27 ( V_47 )
if ( memcmp ( V_5 -> V_11 , V_48 , sizeof( V_48 ) ) == 0 )
F_6 ( V_5 , V_7 ) ;
#endif
if ( F_28 ( V_5 ) < 2 ) {
F_22 ( L_5 ) ;
V_15 = F_29 ( V_5 , V_49 ) ;
if ( F_30 ( ! V_15 ) ) {
F_24 ( V_5 ) ;
return V_44 ;
}
F_31 ( V_5 ) ;
V_5 = V_15 ;
}
F_32 ( V_5 , 2 ) ;
V_39 = (struct V_38 * ) V_5 -> V_11 ;
V_39 -> V_50 = F_33 ( V_10 -> V_51 ) ;
#if V_52 >= 2
#define F_34 99
#elif V_52 >= 1
#define F_34 30
#endif
#if V_52 >= 1
F_35 ( V_53 L_6 ,
V_7 -> V_37 , V_5 -> V_19 , V_10 -> V_51 ) ;
F_36 ( V_53 , L_7 , V_54 , 16 , 1 ,
V_5 -> V_11 , F_37 ( V_5 -> V_19 , F_34 ) , true ) ;
#endif
V_41 = V_55 ;
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
V_40 = V_39 -> V_56 ;
V_2 = NULL ;
V_29 = F_42 ( V_10 , V_40 , V_42 , & V_2 ) ;
F_22 ( L_8 ,
V_7 -> V_37 , V_29 , V_29 ? V_29 -> V_57 : 0 , V_2 ) ;
if ( ! V_29 || ! F_43 ( V_58 , & V_29 -> V_57 ) ) {
if ( V_2 && ( V_2 -> V_59 . V_60 < V_61 ) ) {
F_22 ( L_9 ,
V_7 -> V_37 , V_39 -> V_56 ) ;
F_11 ( & V_2 -> V_59 , V_5 ) ;
} else {
F_22 ( L_10 ,
V_7 -> V_37 , V_39 -> V_56 ) ;
V_7 -> V_33 . V_34 ++ ;
F_40 ( V_5 ) ;
}
goto V_62;
}
#if V_52 > 0
F_35 ( V_53 L_11 ,
V_7 -> V_37 , V_29 -> V_63 , V_29 -> V_64 ) ;
#endif
while ( V_2 && ( V_15 = F_44 ( & V_2 -> V_59 ) ) ) {
F_22 ( L_12 , V_39 -> V_56 ) ;
F_14 ( V_29 , V_15 ) ;
}
F_14 ( V_29 , V_5 ) ;
if ( ! F_45 ( V_29 , 0 ) ) {
struct V_65 * V_66 = F_46 ( V_29 ) ;
V_66 -> V_67 = 1 ;
F_23 ( V_7 ) ;
if ( F_45 ( V_29 , 0 ) )
F_20 ( V_7 ) ;
}
V_62:
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
unsigned long V_57 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_68 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_69 ;
char * V_70 ;
F_49 ( V_5 -> V_25 , & F_10 ( V_29 ) -> V_31 ) ;
V_17 = (struct V_16 * ) V_5 -> V_11 ;
V_70 = V_5 -> V_11 ;
V_70 += sizeof( struct V_16 ) ;
F_22 ( L_13 , V_7 -> V_37 , V_17 -> type ) ;
switch ( V_17 -> type ) {
case V_71 :
for ( V_69 = 0 ; V_69 < 6 ; V_69 ++ )
V_7 -> V_72 [ V_69 ] = V_17 -> V_21 . V_22 . V_73 [ V_69 ] ;
break;
case V_74 :
for ( V_69 = 0 ; V_69 < 6 ; V_69 ++ )
V_7 -> V_72 [ V_69 ] = 0 ;
break;
case V_75 :
F_50 ( V_10 , V_17 -> V_21 . V_22 . V_76 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_20 :
V_10 -> V_77 = V_17 -> V_21 . V_22 . V_23 ;
break;
case V_78 :
F_51 ( V_10 , V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_79 :
F_52 ( & V_10 -> V_80 , V_57 ) ;
V_2 = F_53 ( V_10 , V_17 -> V_21 . V_22 . V_73 ) ;
F_54 ( V_10 , V_2 ) ;
F_55 ( & V_10 -> V_80 , V_57 ) ;
if ( V_17 -> V_21 . V_22 . V_81 )
break;
case V_82 :
F_56 ( V_10 , V_17 -> V_21 . V_22 . V_73 ,
V_17 -> V_21 . V_22 . V_76 ,
V_17 -> V_21 . V_22 . V_23 ,
V_17 -> V_21 . V_22 . V_83 ) ;
F_22 ( L_14 ) ;
if ( V_17 -> V_84 != 0 ) {
F_22 ( L_15 ,
V_17 -> V_84 ) ;
F_57 ( V_7 , V_17 -> V_21 . V_22 . V_73 ,
V_70 , V_17 -> V_84 ) ;
}
break;
case V_85 :
V_10 -> V_86 =
V_17 -> V_21 . V_87 . V_86 ;
V_10 -> V_88 =
( V_17 -> V_21 . V_87 . V_88 * V_89 ) ;
V_10 -> V_90 = V_17 -> V_21 . V_87 . V_90 ;
V_10 -> V_91 = ( V_17 -> V_21 . V_87 . V_91 * V_89 ) ;
V_10 -> V_92 =
( V_17 -> V_21 . V_87 . V_92 * V_89 ) ;
V_10 -> V_93 =
( V_17 -> V_21 . V_87 . V_93 * V_89 ) ;
V_10 -> V_94 = ( V_17 -> V_21 . V_87 . V_94 * V_89 ) ;
V_10 -> V_95 =
( V_17 -> V_21 . V_87 . V_95 * V_89 ) ;
V_10 -> V_96 = V_17 -> V_21 . V_87 . V_96 ;
V_10 -> V_97 = NULL ;
if ( V_10 -> V_96 > 1 )
V_10 -> V_97 = & V_97 ;
F_58 () ;
if ( F_59 ( V_7 , V_17 -> V_21 . V_87 . V_98 ) )
F_18 ( L_16 ,
V_7 -> V_37 , V_17 -> V_21 . V_87 . V_98 ) ;
F_60 () ;
V_10 -> V_99 = V_17 -> V_21 . V_87 . V_99 ;
break;
case V_100 :
F_61 ( V_10 , V_17 -> V_21 . V_22 . V_76 ,
V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_101 :
V_10 -> V_51 =
( unsigned short ) ( 0xffff & V_17 -> V_21 . V_22 . V_23 ) ;
break;
case V_102 :
#if F_27 ( V_46 ) || F_27 ( V_47 )
{
F_22 ( L_17 ,
V_7 -> V_37 , V_17 -> V_21 . V_103 . V_73 ) ;
if ( V_104 == NULL )
break;
if ( V_104 ( V_7 , V_17 -> V_21 . V_103 . V_73 ) ) {
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
return - V_105 ;
}
F_40 ( V_5 ) ;
return 0 ;
}
static void F_63 ( struct V_28 * V_29 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_68 ;
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
F_67 ( V_106 ) ;
}
static int
F_68 ( struct V_9 * V_10 , T_2 type ,
const unsigned char * V_73 , const unsigned char * V_76 ,
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
V_17 -> V_84 = V_11 -> V_19 ;
if ( V_73 )
F_69 ( V_17 -> V_21 . V_22 . V_73 , V_73 ) ;
else
V_17 -> V_21 . V_22 . V_83 = 1 ;
if ( V_76 )
memcpy ( & V_17 -> V_21 . V_22 . V_76 , V_76 , V_107 ) ;
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
static int F_70 ( struct V_6 * V_7 , int V_108 )
{
if ( ( V_108 < 68 ) || ( V_108 > 18190 ) )
return - V_105 ;
V_7 -> V_98 = V_108 ;
return 0 ;
}
static void F_71 ( struct V_6 * V_7 )
{
}
static int F_72 ( struct V_28 * V_29 )
{
return ( ( V_29 -> V_109 . V_110 [ 0 ] . V_111 . V_112 . V_113 [ 4 ] == V_114 ) ||
( V_29 -> V_109 . V_110 [ 0 ] . V_111 . V_112 . V_113 [ 4 ] == V_115 ) ) ;
}
static void F_73 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_57 ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_68 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
#if V_52 > 0
F_35 ( V_53 L_23 ,
V_7 -> V_37 , V_29 -> V_63 , V_29 -> V_64 ) ;
#endif
if ( ! V_5 ) {
F_22 ( L_24 , V_7 -> V_37 ) ;
F_74 ( V_10 , V_29 ) ;
return;
}
#if V_52 >= 2
#define F_75 99
#elif V_52 >= 1
#define F_75 30
#endif
#if V_52 > 0
F_35 ( V_53 L_25 ,
V_7 -> V_37 , V_5 -> V_19 , V_10 -> V_51 ) ;
F_36 ( V_53 , L_7 , V_54 , 16 , 1 ,
V_5 -> V_11 , F_37 ( F_75 , V_5 -> V_19 ) , true ) ;
#endif
if ( memcmp ( V_5 -> V_11 , V_116 , 4 ) == 0 ) {
struct V_13 * V_14 = F_10 ( V_29 ) ;
F_22 ( L_26 , V_7 -> V_37 ) ;
F_11 ( & V_14 -> V_26 , V_5 ) ;
V_14 -> V_27 ( V_14 ) ;
} else {
struct V_1 * V_2 ;
unsigned char * V_117 , * V_40 ;
F_66 ( V_29 , V_5 -> V_25 ) ;
if ( * ( V_118 * ) V_5 -> V_11 == F_33 ( V_10 -> V_51 ) ||
! V_10 -> V_24 || ! ( V_7 -> V_57 & V_119 ) ) {
F_22 ( L_27 ) ;
F_40 ( V_5 ) ;
return;
}
V_40 = ( (struct V_38 * ) V_5 -> V_11 ) -> V_56 ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
if ( F_72 ( V_29 ) ) {
V_117 = ( (struct V_38 * ) V_5 -> V_11 ) -> V_120 ;
V_2 = F_53 ( V_10 , V_117 ) ;
if ( V_2 && V_2 -> V_29 != V_29 ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
if ( ! ( V_40 [ 0 ] & 0x01 ) &&
! V_10 -> V_99 &&
memcmp ( V_40 , V_7 -> V_72 , V_7 -> V_121 ) ) {
F_40 ( V_5 ) ;
return;
}
if ( ! F_76 ( & V_10 -> V_122 ) )
F_77 ( V_10 , V_29 , V_5 ) ;
F_78 ( V_5 , 2 ) ;
V_5 -> V_123 = F_79 ( V_5 , V_7 ) ;
V_7 -> V_33 . V_124 ++ ;
V_7 -> V_33 . V_125 += V_5 -> V_19 ;
memset ( F_15 ( V_5 ) , 0 , sizeof( struct V_126 ) ) ;
F_80 ( V_5 ) ;
}
}
static void F_81 ( struct V_28 * V_29 , struct V_4 * V_5 )
{
struct V_65 * V_66 = F_46 ( V_29 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
if ( V_66 == NULL ) {
F_18 ( L_28 ) ;
return;
}
V_66 -> V_127 ( V_29 , V_5 ) ;
if ( V_66 -> V_67 && F_45 ( V_29 , 0 ) ) {
V_66 -> V_67 = 0 ;
if ( F_82 ( V_7 ) && F_83 ( V_7 ) )
F_20 ( V_7 ) ;
}
}
static int F_84 ( struct V_28 * V_29 , void T_3 * V_128 )
{
struct V_65 * V_66 ;
int V_129 ;
struct V_130 V_131 ;
V_129 = F_85 ( & V_131 , V_128 , sizeof( struct V_130 ) ) ;
if ( V_129 != 0 )
F_18 ( L_29 , V_129 ) ;
if ( V_131 . V_132 < 0 || V_131 . V_132 >= V_133 ||
! V_134 [ V_131 . V_132 ] )
return - V_105 ;
V_66 = F_86 ( sizeof( struct V_65 ) , V_135 ) ;
if ( ! V_66 )
return - V_136 ;
V_66 -> V_67 = 0 ;
V_66 -> V_127 = V_29 -> V_137 ;
V_29 -> V_138 = V_66 ;
V_29 -> V_137 = F_81 ;
F_87 ( F_8 ( V_134 [ V_131 . V_132 ] ) ,
& V_131 , V_29 , V_29 -> V_139 ) ;
V_29 -> V_68 = V_134 [ V_131 . V_132 ] ;
V_29 -> V_139 = F_73 ;
return 0 ;
}
static int F_88 ( struct V_28 * V_29 , int V_128 )
{
if ( V_128 < 0 || V_128 >= V_133 || ! V_134 [ V_128 ] )
return - V_105 ;
V_29 -> V_68 = V_134 [ V_128 ] ;
return F_89 ( F_8 ( V_134 [ V_128 ] ) , V_29 ) ;
}
static int F_90 ( struct V_28 * V_29 , int V_128 )
{
int V_69 ;
struct V_9 * V_10 ;
if ( V_128 < 0 )
V_69 = 0 ;
else
V_69 = V_128 ;
if ( V_128 >= V_133 )
return - V_105 ;
if ( ! V_134 [ V_69 ] ) {
int V_140 ;
V_140 = sizeof( struct V_9 ) ;
V_134 [ V_69 ] = F_91 ( V_140 ) ;
if ( ! V_134 [ V_69 ] )
return - V_136 ;
V_134 [ V_69 ] -> V_141 = & V_142 ;
snprintf ( V_134 [ V_69 ] -> V_37 , V_143 , L_30 , V_69 ) ;
if ( F_92 ( V_134 [ V_69 ] ) ) {
F_93 ( V_134 [ V_69 ] ) ;
return - V_105 ;
}
V_10 = F_8 ( V_134 [ V_69 ] ) ;
} else {
V_10 = F_8 ( V_134 [ V_69 ] ) ;
if ( V_10 -> V_24 )
return - V_144 ;
}
F_94 ( V_10 ) ;
V_10 -> V_145 = V_69 ;
V_10 -> V_24 = V_29 ;
V_29 -> V_7 = & V_146 ;
F_95 ( F_10 ( V_29 ) ) ;
V_29 -> V_68 = V_134 [ V_69 ] ;
F_96 ( V_147 , & V_29 -> V_57 ) ;
F_96 ( V_58 , & V_29 -> V_57 ) ;
V_10 -> V_86 = 1 ;
V_10 -> V_88 = ( 1 * V_89 ) ;
V_10 -> V_148 = ( 1200 * V_89 ) ;
V_10 -> V_90 = 1 ;
V_10 -> V_91 = ( 300 * V_89 ) ;
V_10 -> V_92 = ( 15 * V_89 ) ;
V_10 -> V_77 = 0 ;
V_10 -> V_93 = ( 1 * V_89 ) ;
V_10 -> V_94 = ( 4 * V_89 ) ;
V_10 -> V_95 = ( 6 * V_89 ) ;
if ( V_134 [ V_69 ] -> V_57 & V_119 )
F_13 ( V_134 [ V_69 ] ) ;
F_97 ( V_106 ) ;
return V_69 ;
}
static const char * F_98 ( unsigned char V_149 )
{
static const char * const V_150 [] = {
L_31 ,
L_32 ,
L_33 ,
L_34 ,
L_35 ,
L_36
} ;
if ( V_149 > V_151 )
V_149 = 3 ;
return V_150 [ V_149 ] ;
}
static void F_99 ( struct V_152 * V_153 , struct V_1 * V_2 )
{
int V_69 ;
for ( V_69 = 0 ; V_69 < V_154 ; V_69 ++ )
F_100 ( V_153 , L_37 , V_2 -> V_73 [ V_69 ] & 0xff ) ;
F_100 ( V_153 , L_38 ) ;
for ( V_69 = 0 ; V_69 < V_107 ; V_69 ++ )
F_100 ( V_153 , L_37 , V_2 -> V_76 [ V_69 ] & 0xff ) ;
F_100 ( V_153 , L_39 , F_98 ( V_2 -> V_149 ) ,
V_2 -> V_57 & 0xffff ) ;
if ( V_2 -> V_29 )
F_100 ( V_153 , L_40 , V_2 -> V_29 -> V_63 , V_2 -> V_29 -> V_64 ) ;
else
F_100 ( V_153 , L_41 ) ;
if ( V_2 -> V_155 ) {
F_100 ( V_153 , L_42 , V_2 -> V_155 -> V_63 ,
V_2 -> V_155 -> V_64 ) ;
}
F_101 ( V_153 , '\n' ) ;
}
static void * F_102 ( struct V_156 * V_157 , struct V_158 * V_159 ,
T_4 * V_160 )
{
struct V_161 * V_162 = V_157 -> V_163 ;
if ( ! V_162 )
V_162 = V_159 -> V_164 ;
if ( V_162 == V_165 ) {
V_162 = V_159 -> V_164 ;
-- * V_160 ;
}
for (; V_162 ; V_162 = V_162 -> V_166 ) {
if ( -- * V_160 < 0 )
break;
}
V_157 -> V_163 = V_162 ;
return ( * V_160 < 0 ) ? V_157 : NULL ;
}
static void * F_103 ( struct V_156 * V_157 , T_4 * V_160 ,
struct V_9 * V_10 )
{
void * V_167 = NULL ;
int V_168 ;
for ( V_168 = V_157 -> V_169 ; V_168 < V_170 ; V_168 ++ ) {
V_167 = F_102 ( V_157 , & V_10 -> V_171 [ V_168 ] , V_160 ) ;
if ( V_167 )
break;
}
V_157 -> V_169 = V_168 ;
return V_167 ;
}
static void * F_104 ( struct V_156 * V_157 , T_4 * V_160 ,
struct V_9 * V_10 )
{
struct V_158 * V_172 [] = {
& V_10 -> V_122 ,
& V_10 -> V_173 ,
& V_10 -> V_174
} ;
void * V_167 = NULL ;
int V_175 ;
for ( V_175 = V_157 -> V_176 ; V_175 < F_105 ( V_172 ) ; V_175 ++ ) {
V_167 = F_102 ( V_157 , V_172 [ V_175 ] , V_160 ) ;
if ( V_167 )
break;
}
V_157 -> V_176 = V_175 ;
return V_167 ;
}
static void * F_106 ( struct V_156 * V_157 , T_4 * V_160 ,
struct V_9 * V_10 )
{
if ( ! V_157 -> V_177 ) {
V_157 -> V_177 = V_10 ;
F_52 ( & V_10 -> V_80 , V_157 -> V_57 ) ;
}
if ( ! F_103 ( V_157 , V_160 , V_10 ) && ! F_104 ( V_157 , V_160 , V_10 ) ) {
F_55 ( & V_10 -> V_80 , V_157 -> V_57 ) ;
V_157 -> V_177 = NULL ;
V_157 -> V_169 = V_157 -> V_176 = 0 ;
}
return V_157 -> V_177 ;
}
static void * F_107 ( struct V_156 * V_157 , T_4 * V_160 )
{
struct V_6 * V_7 ;
void * V_167 ;
V_7 = V_157 -> V_7 ? V_157 -> V_7 : V_134 [ V_157 -> V_178 ] ;
V_167 = ( V_7 && F_8 ( V_7 ) ) ?
F_106 ( V_157 , V_160 , F_8 ( V_7 ) ) : NULL ;
if ( ! V_167 && V_7 ) {
F_108 ( V_7 ) ;
V_7 = NULL ;
}
V_157 -> V_7 = V_7 ;
return V_167 ;
}
static void * F_109 ( struct V_156 * V_157 , T_4 V_160 )
{
void * V_167 = NULL ;
for (; V_157 -> V_178 < V_133 ; V_157 -> V_178 ++ ) {
V_167 = F_107 ( V_157 , & V_160 ) ;
if ( V_167 )
break;
}
return V_167 ;
}
static void * F_110 ( struct V_152 * V_153 , T_4 * V_179 )
{
struct V_156 * V_157 = V_153 -> V_180 ;
V_157 -> V_178 = 0 ;
V_157 -> V_7 = NULL ;
V_157 -> V_177 = NULL ;
V_157 -> V_169 = 0 ;
V_157 -> V_176 = 0 ;
V_157 -> V_163 = V_165 ;
return * V_179 ? F_109 ( V_157 , * V_179 ) : V_165 ;
}
static void F_111 ( struct V_152 * V_153 , void * V_167 )
{
struct V_156 * V_157 = V_153 -> V_180 ;
if ( V_157 -> V_7 ) {
F_55 ( & V_157 -> V_177 -> V_80 ,
V_157 -> V_57 ) ;
F_108 ( V_157 -> V_7 ) ;
}
}
static void * F_112 ( struct V_152 * V_153 , void * V_167 , T_4 * V_179 )
{
struct V_156 * V_157 = V_153 -> V_180 ;
V_167 = F_109 ( V_157 , 1 ) ;
* V_179 += ! ! F_113 ( V_167 ) ;
return V_167 ;
}
static int F_114 ( struct V_152 * V_153 , void * V_167 )
{
static const char V_181 [] =
L_43
L_44
L_45 ;
if ( V_167 == V_165 )
F_115 ( V_153 , V_181 ) ;
else {
struct V_156 * V_157 = V_153 -> V_180 ;
struct V_6 * V_7 = V_157 -> V_7 ;
struct V_1 * V_2 = F_116 ( V_157 -> V_163 ,
struct V_1 ,
V_166 ) ;
F_100 ( V_153 , L_46 , V_7 -> V_37 ) ;
F_99 ( V_153 , V_2 ) ;
}
return 0 ;
}
static int F_117 ( struct V_182 * V_182 , struct V_183 * V_183 )
{
return F_118 ( V_183 , & V_184 , sizeof( struct V_156 ) ) ;
}
static int F_119 ( struct V_185 * V_13 , unsigned int V_186 , unsigned long V_128 )
{
struct V_28 * V_29 = F_120 ( V_13 ) ;
int V_187 = 0 ;
switch ( V_186 ) {
case V_188 :
case V_189 :
case V_190 :
if ( ! F_121 ( V_191 ) )
return - V_192 ;
break;
default:
return - V_193 ;
}
switch ( V_186 ) {
case V_188 :
V_187 = F_90 ( V_29 , ( int ) V_128 ) ;
if ( V_187 >= 0 )
V_13 -> V_157 = V_194 ;
break;
case V_189 :
V_187 = F_88 ( V_29 , ( int ) V_128 ) ;
break;
case V_190 :
V_187 = F_84 ( V_29 , ( void T_3 * ) V_128 ) ;
break;
}
return V_187 ;
}
static int T_5 F_122 ( void )
{
#ifdef F_123
struct V_195 * V_168 ;
V_168 = F_124 ( L_47 , V_196 , V_197 , & V_198 ) ;
if ( ! V_168 ) {
F_125 ( L_48 ) ;
return - V_136 ;
}
#endif
F_126 ( & V_199 ) ;
F_18 ( L_49 ) ;
return 0 ;
}
static void T_6 F_127 ( void )
{
int V_69 ;
F_128 ( L_47 , V_197 ) ;
F_129 ( & V_199 ) ;
for ( V_69 = 0 ; V_69 < V_133 ; V_69 ++ ) {
if ( V_134 [ V_69 ] != NULL ) {
F_130 ( V_134 [ V_69 ] ) ;
F_93 ( V_134 [ V_69 ] ) ;
V_134 [ V_69 ] = NULL ;
}
}
}
static int F_131 ( struct V_6 * V_7 , const T_7 * V_200 , int V_201 ,
T_7 * * V_202 , T_8 * V_84 )
{
unsigned long V_57 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
struct V_1 * V_203 ;
struct V_4 * V_5 ;
int V_204 ;
if ( V_201 == 0 ) {
F_52 ( & V_10 -> V_80 , V_57 ) ;
V_203 = F_53 ( V_10 , V_200 ) ;
F_55 ( & V_10 -> V_80 , V_57 ) ;
if ( V_203 == NULL )
return - 1 ;
* V_202 = F_132 ( V_203 -> V_202 , V_203 -> V_84 , V_18 ) ;
if ( * V_202 == NULL )
return - 1 ;
* V_84 = V_203 -> V_84 ;
return 0 ;
}
if ( V_84 == NULL )
V_204 = F_68 ( V_10 , V_205 , V_200 , NULL , NULL ) ;
else {
V_5 = F_7 ( * V_84 , V_18 ) ;
if ( V_5 == NULL )
return - 1 ;
V_5 -> V_19 = * V_84 ;
F_62 ( V_5 , * V_202 , * V_84 ) ;
V_204 = F_68 ( V_10 , V_205 , V_200 , NULL , V_5 ) ;
}
return V_204 ;
}
static int F_133 ( struct V_6 * V_7 , const T_7 * V_206 ,
const T_7 * V_202 , T_8 V_84 )
{
int V_204 ;
struct V_4 * V_5 ;
struct V_9 * V_10 = F_8 ( V_7 ) ;
if ( ! F_134 ( V_206 , V_7 -> V_72 ) )
return 0 ;
F_5 ( V_10 -> V_202 ) ;
V_10 -> V_202 = F_132 ( V_202 , V_84 , V_135 ) ;
if ( V_10 -> V_202 == NULL )
return 0 ;
V_10 -> V_84 = V_84 ;
V_5 = F_7 ( V_84 , V_18 ) ;
if ( V_5 == NULL )
return 0 ;
V_5 -> V_19 = V_84 ;
F_62 ( V_5 , V_202 , V_84 ) ;
V_204 = F_68 ( V_10 , V_207 , NULL , NULL , V_5 ) ;
if ( V_204 != 0 )
F_18 ( L_50 ) ;
return 1 ;
}
static void F_57 ( struct V_6 * V_7 , const T_7 * V_73 ,
const T_7 * V_202 , T_8 V_84 )
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
if ( V_10 -> V_97 && V_10 -> V_97 -> V_208 ) {
V_10 -> V_97 -> V_208 ( V_7 , V_73 ,
V_202 , V_84 ) ;
}
}
static void F_94 ( struct V_9 * V_10 )
{
unsigned short V_69 ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ )
F_135 ( & V_10 -> V_171 [ V_69 ] ) ;
F_135 ( & V_10 -> V_122 ) ;
F_135 ( & V_10 -> V_173 ) ;
F_135 ( & V_10 -> V_174 ) ;
F_136 ( & V_10 -> V_80 ) ;
F_137 ( & V_10 -> V_209 , V_210 ) ;
F_138 ( & V_10 -> V_209 , V_211 ) ;
}
static void F_139 ( struct V_1 * V_2 )
{
if ( V_2 -> V_29 ) {
struct V_28 * V_29 = V_2 -> V_29 ;
struct V_65 * V_66 = F_46 ( V_29 ) ;
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_68 ;
V_29 -> V_137 = V_66 -> V_127 ;
if ( V_66 -> V_67 )
F_20 ( V_7 ) ;
F_5 ( V_66 ) ;
V_29 -> V_138 = NULL ;
V_29 -> V_139 = V_2 -> V_212 ;
F_140 ( V_29 , - V_213 ) ;
V_2 -> V_29 = NULL ;
}
if ( V_2 -> V_155 ) {
V_2 -> V_155 -> V_139 = V_2 -> V_214 ;
F_140 ( V_2 -> V_155 , - V_213 ) ;
V_2 -> V_155 = NULL ;
}
}
static inline void
F_141 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_158 * V_70 ;
V_70 = & V_10 -> V_171 [ F_142 ( V_2 -> V_73 [ V_154 - 1 ] ) ] ;
F_143 ( & V_2 -> V_166 , V_70 ) ;
F_22 ( L_51 , V_2 -> V_73 ) ;
}
static int
F_54 ( struct V_9 * V_10 , struct V_1 * V_215 )
{
struct V_1 * V_2 ;
int V_69 , V_216 = 1 ;
if ( ! V_215 )
return - 1 ;
F_144 ( & V_215 -> V_166 ) ;
F_145 ( & V_215 -> V_217 ) ;
if ( V_215 -> V_149 >= V_218 ) {
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( memcmp ( V_215 -> V_76 ,
V_2 -> V_76 , V_107 ) == 0 ) {
V_216 = 0 ;
break;
}
}
}
if ( V_216 )
F_139 ( V_215 ) ;
}
F_147 ( & V_215 -> V_59 ) ;
F_22 ( L_52 , V_215 -> V_73 ) ;
return 0 ;
}
static const char * F_148 ( unsigned char V_219 )
{
switch ( V_219 ) {
case V_220 :
return L_53 ;
case V_221 :
return L_54 ;
case V_222 :
return L_55 ;
case V_218 :
return L_56 ;
case V_151 :
return L_36 ;
}
return L_57 ;
}
static void F_149 ( struct V_9 * V_10 )
{
struct V_1 * V_223 ;
char V_224 [ 256 ] ;
int V_69 , V_225 , V_226 ;
F_18 ( L_58 , V_10 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_146 (rulla,
&priv->lec_arp_tables[i], next) {
V_226 = 0 ;
V_226 += sprintf ( V_224 , L_59 , V_69 , V_223 ) ;
V_226 += sprintf ( V_224 + V_226 , L_60 ,
V_223 -> V_73 ) ;
V_226 += sprintf ( V_224 + V_226 , L_61 ) ;
for ( V_225 = 0 ; V_225 < V_107 ; V_225 ++ ) {
V_226 += sprintf ( V_224 + V_226 ,
L_62 ,
V_223 -> V_76 [ V_225 ] & 0xff ) ;
}
V_226 += sprintf ( V_224 + V_226 ,
L_63 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_63 : 0 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_64 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 ->
V_63 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 ->
V_64 : 0 , V_223 -> V_227 ,
V_223 -> V_228 , V_223 -> V_229 ) ;
V_226 +=
sprintf ( V_224 + V_226 ,
L_64 ,
V_223 -> V_57 , V_223 -> V_230 ,
F_148 ( V_223 -> V_149 ) ) ;
F_18 ( L_1 , V_224 ) ;
}
}
if ( ! F_76 ( & V_10 -> V_173 ) )
F_18 ( L_65 ) ;
F_146 (rulla, &priv->lec_no_forward, next) {
V_226 = 0 ;
V_226 += sprintf ( V_224 + V_226 , L_60 , V_223 -> V_73 ) ;
V_226 += sprintf ( V_224 + V_226 , L_61 ) ;
for ( V_225 = 0 ; V_225 < V_107 ; V_225 ++ ) {
V_226 += sprintf ( V_224 + V_226 , L_62 ,
V_223 -> V_76 [ V_225 ] & 0xff ) ;
}
V_226 += sprintf ( V_224 + V_226 ,
L_63 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_63 : 0 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_64 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 -> V_63 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 -> V_64 : 0 ,
V_223 -> V_227 ,
V_223 -> V_228 , V_223 -> V_229 ) ;
V_226 += sprintf ( V_224 + V_226 ,
L_64 ,
V_223 -> V_57 , V_223 -> V_230 ,
F_148 ( V_223 -> V_149 ) ) ;
F_18 ( L_1 , V_224 ) ;
}
if ( ! F_76 ( & V_10 -> V_122 ) )
F_18 ( L_66 ) ;
F_146 (rulla, &priv->lec_arp_empty_ones, next) {
V_226 = 0 ;
V_226 += sprintf ( V_224 + V_226 , L_60 , V_223 -> V_73 ) ;
V_226 += sprintf ( V_224 + V_226 , L_61 ) ;
for ( V_225 = 0 ; V_225 < V_107 ; V_225 ++ ) {
V_226 += sprintf ( V_224 + V_226 , L_62 ,
V_223 -> V_76 [ V_225 ] & 0xff ) ;
}
V_226 += sprintf ( V_224 + V_226 ,
L_63 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_63 : 0 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_64 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 -> V_63 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 -> V_64 : 0 ,
V_223 -> V_227 ,
V_223 -> V_228 , V_223 -> V_229 ) ;
V_226 += sprintf ( V_224 + V_226 ,
L_64 ,
V_223 -> V_57 , V_223 -> V_230 ,
F_148 ( V_223 -> V_149 ) ) ;
F_18 ( L_67 , V_224 ) ;
}
if ( ! F_76 ( & V_10 -> V_174 ) )
F_18 ( L_68 ) ;
F_146 (rulla, &priv->mcast_fwds, next) {
V_226 = 0 ;
V_226 += sprintf ( V_224 + V_226 , L_60 , V_223 -> V_73 ) ;
V_226 += sprintf ( V_224 + V_226 , L_61 ) ;
for ( V_225 = 0 ; V_225 < V_107 ; V_225 ++ ) {
V_226 += sprintf ( V_224 + V_226 , L_62 ,
V_223 -> V_76 [ V_225 ] & 0xff ) ;
}
V_226 += sprintf ( V_224 + V_226 ,
L_63 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_63 : 0 ,
V_223 -> V_29 ? V_223 -> V_29 -> V_64 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 -> V_63 : 0 ,
V_223 -> V_155 ? V_223 -> V_155 -> V_64 : 0 ,
V_223 -> V_227 ,
V_223 -> V_228 , V_223 -> V_229 ) ;
V_226 += sprintf ( V_224 + V_226 ,
L_64 ,
V_223 -> V_57 , V_223 -> V_230 ,
F_148 ( V_223 -> V_149 ) ) ;
F_18 ( L_1 , V_224 ) ;
}
}
static void F_64 ( struct V_9 * V_10 )
{
unsigned long V_57 ;
struct V_161 * V_166 ;
struct V_1 * V_2 ;
int V_69 ;
F_150 ( & V_10 -> V_209 ) ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_171 [ V_69 ] ) ;
}
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
F_152 ( & V_2 -> V_217 ) ;
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_166 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_122 ) ;
F_151 (entry, next,
&priv->lec_no_forward, next) {
F_152 ( & V_2 -> V_217 ) ;
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_166 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_173 ) ;
F_151 (entry, next, &priv->mcast_fwds, next) {
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_166 ) ;
F_3 ( V_2 ) ;
}
F_135 ( & V_10 -> V_174 ) ;
V_10 -> V_231 = NULL ;
F_55 ( & V_10 -> V_80 , V_57 ) ;
}
static struct V_1 * F_53 ( struct V_9 * V_10 ,
const unsigned char * V_73 )
{
struct V_158 * V_45 ;
struct V_1 * V_2 ;
F_22 ( L_69 , V_73 ) ;
V_45 = & V_10 -> V_171 [ F_142 ( V_73 [ V_154 - 1 ] ) ] ;
F_146 (entry, head, next) {
if ( F_134 ( V_73 , V_2 -> V_73 ) )
return V_2 ;
}
return NULL ;
}
static struct V_1 * F_153 ( struct V_9 * V_10 ,
const unsigned char * V_73 )
{
struct V_1 * V_232 ;
V_232 = F_154 ( sizeof( struct V_1 ) , V_18 ) ;
if ( ! V_232 ) {
F_18 ( L_70 ) ;
return NULL ;
}
F_69 ( V_232 -> V_73 , V_73 ) ;
F_155 ( & V_232 -> V_166 ) ;
F_156 ( & V_232 -> V_217 , V_233 ,
( unsigned long ) V_232 ) ;
V_232 -> V_227 = V_234 ;
V_232 -> V_10 = V_10 ;
F_157 ( & V_232 -> V_59 ) ;
F_158 ( & V_232 -> V_3 , 1 ) ;
return V_232 ;
}
static void V_233 ( unsigned long V_11 )
{
struct V_1 * V_2 ;
V_2 = (struct V_1 * ) V_11 ;
F_22 ( L_71 ) ;
if ( V_2 -> V_149 == V_221 ) {
if ( V_2 -> V_229 <= V_2 -> V_10 -> V_90 ) {
if ( V_2 -> V_42 )
F_68 ( V_2 -> V_10 , V_235 ,
V_2 -> V_73 , NULL , NULL ) ;
else
F_68 ( V_2 -> V_10 , V_205 ,
V_2 -> V_73 , NULL , NULL ) ;
V_2 -> V_229 ++ ;
}
F_159 ( & V_2 -> V_217 , V_234 + ( 1 * V_89 ) ) ;
}
}
static void F_160 ( unsigned long V_11 )
{
unsigned long V_57 ;
struct V_1 * V_215 = (struct V_1 * ) V_11 ;
struct V_9 * V_10 = V_215 -> V_10 ;
F_145 ( & V_215 -> V_217 ) ;
F_22 ( L_72 ,
V_215 , V_10 ,
V_215 -> V_29 ? V_215 -> V_155 -> V_63 : 0 ,
V_215 -> V_29 ? V_215 -> V_155 -> V_64 : 0 ) ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
F_144 ( & V_215 -> V_166 ) ;
F_55 ( & V_10 -> V_80 , V_57 ) ;
F_139 ( V_215 ) ;
F_3 ( V_215 ) ;
}
static bool F_161 ( struct V_1 * V_2 ,
unsigned long V_236 ,
struct V_9 * V_10 )
{
unsigned long V_237 ;
if ( ( V_2 -> V_57 ) & V_238 && V_10 -> V_77 )
V_237 = V_10 -> V_92 ;
else
V_237 = V_10 -> V_91 ;
F_22 ( L_73 ,
V_236 , V_2 -> V_227 , V_237 ) ;
if ( F_162 ( V_236 , V_2 -> V_227 + V_237 ) &&
! ( V_2 -> V_57 & V_239 ) &&
! ( V_2 -> V_73 [ 0 ] & 0x01 ) ) {
F_22 ( L_74 ) ;
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
} else {
if ( ( V_2 -> V_149 == V_222 ||
V_2 -> V_149 == V_221 ) &&
F_163 ( V_236 , V_2 -> V_228 +
V_10 -> V_88 ) ) {
V_2 -> V_228 = V_234 ;
V_2 -> V_230 = 0 ;
if ( V_2 -> V_149 == V_222 )
F_68 ( V_10 , V_240 ,
V_2 -> V_73 ,
V_2 -> V_76 ,
NULL ) ;
}
if ( V_2 -> V_149 == V_218 &&
F_163 ( V_236 , V_2 -> V_228 +
V_10 -> V_95 ) ) {
F_1 ( V_2 ) ;
return true ;
}
}
return false ;
}
static void V_210 ( struct V_241 * V_242 )
{
unsigned long V_57 ;
struct V_9 * V_10 =
F_164 ( V_242 , struct V_9 , V_209 . V_242 ) ;
struct V_161 * V_166 ;
struct V_1 * V_2 ;
unsigned long V_236 ;
int V_69 ;
F_22 ( L_75 , V_10 ) ;
V_236 = V_234 ;
V_243:
F_52 ( & V_10 -> V_80 , V_57 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( F_161 ( V_2 , V_236 , V_10 ) ) {
struct V_4 * V_5 ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_55 ( & V_10 -> V_80 ,
V_57 ) ;
while ( ( V_5 = F_44 ( & V_2 -> V_59 ) ) )
F_14 ( V_29 , V_5 ) ;
V_2 -> V_227 = V_234 ;
V_2 -> V_149 = V_151 ;
F_3 ( V_2 ) ;
goto V_243;
}
}
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
F_138 ( & V_10 -> V_209 , V_211 ) ;
}
static struct V_28 * F_42 ( struct V_9 * V_10 ,
const unsigned char * V_244 ,
int V_42 ,
struct V_1 * * V_245 )
{
unsigned long V_57 ;
struct V_1 * V_2 ;
struct V_28 * V_246 ;
if ( V_244 [ 0 ] & 0x01 ) {
switch ( V_10 -> V_96 ) {
case 1 :
return V_10 -> V_231 ;
case 2 :
if ( F_134 ( V_244 , V_247 ) )
return V_10 -> V_231 ;
break;
default:
break;
}
}
F_52 ( & V_10 -> V_80 , V_57 ) ;
V_2 = F_53 ( V_10 , V_244 ) ;
if ( V_2 ) {
if ( V_2 -> V_149 == V_151 ) {
V_2 -> V_227 = V_234 ;
F_1 ( V_2 ) ;
* V_245 = V_2 ;
V_246 = V_2 -> V_29 ;
goto V_62;
}
if ( V_2 -> V_149 == V_221 )
V_2 -> V_229 = 0 ;
if ( V_2 -> V_149 != V_218 &&
V_2 -> V_230 <
V_10 -> V_86 ) {
V_2 -> V_230 ++ ;
F_22 ( L_76 ) ;
V_246 = V_10 -> V_231 ;
goto V_62;
}
F_1 ( V_2 ) ;
* V_245 = V_2 ;
F_22 ( L_77 , V_2 -> V_149 ,
V_2 -> V_29 ) ;
V_246 = NULL ;
} else {
V_2 = F_153 ( V_10 , V_244 ) ;
F_22 ( L_78 ) ;
if ( ! V_2 ) {
V_246 = V_10 -> V_231 ;
goto V_62;
}
F_141 ( V_10 , V_2 ) ;
V_2 -> V_230 = 1 ;
V_2 -> V_149 = V_221 ;
V_2 -> V_229 = 1 ;
V_2 -> V_227 = V_2 -> V_228 = V_234 ;
V_2 -> V_42 = V_42 ;
if ( V_2 -> V_42 )
F_68 ( V_10 , V_235 , V_244 , NULL ,
NULL ) ;
else
F_68 ( V_10 , V_205 , V_244 , NULL , NULL ) ;
V_2 -> V_217 . V_248 = V_234 + ( 1 * V_89 ) ;
V_2 -> V_217 . V_249 = V_233 ;
F_165 ( & V_2 -> V_217 ) ;
V_246 = V_10 -> V_231 ;
}
V_62:
F_55 ( & V_10 -> V_80 , V_57 ) ;
return V_246 ;
}
static int
F_50 ( struct V_9 * V_10 , const unsigned char * V_76 ,
unsigned long V_250 )
{
unsigned long V_57 ;
struct V_161 * V_166 ;
struct V_1 * V_2 ;
int V_69 ;
F_22 ( L_71 ) ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_76 , V_2 -> V_76 , V_107 ) &&
( V_250 ||
! ( V_2 -> V_57 & V_239 ) ) ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
return 0 ;
}
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
return - 1 ;
}
static void
F_56 ( struct V_9 * V_10 , const unsigned char * V_73 ,
const unsigned char * V_76 , unsigned long V_251 ,
unsigned int V_83 )
{
unsigned long V_57 ;
struct V_161 * V_166 ;
struct V_1 * V_2 , * V_70 ;
int V_69 ;
F_22 ( L_79 ,
( V_83 ) ? L_80 : L_7 , V_73 ) ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
V_2 = F_53 ( V_10 , V_73 ) ;
if ( V_2 == NULL && V_83 )
goto V_62;
if ( ! F_76 ( & V_10 -> V_122 ) ) {
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( memcmp ( V_2 -> V_76 , V_76 , V_107 ) == 0 ) {
F_144 ( & V_2 -> V_166 ) ;
F_145 ( & V_2 -> V_217 ) ;
V_70 = F_53 ( V_10 , V_73 ) ;
if ( V_70 ) {
F_145 ( & V_70 -> V_217 ) ;
V_70 -> V_149 = V_151 ;
memcpy ( V_70 -> V_76 , V_76 , V_107 ) ;
V_70 -> V_29 = V_2 -> V_29 ;
V_70 -> V_212 = V_2 -> V_212 ;
V_70 -> V_227 = V_234 ;
F_145 ( & V_2 -> V_217 ) ;
F_3 ( V_2 ) ;
V_2 = V_70 ;
} else {
V_2 -> V_149 = V_151 ;
F_69 ( V_2 -> V_73 ,
V_73 ) ;
V_2 -> V_227 = V_234 ;
F_141 ( V_10 , V_2 ) ;
}
if ( V_251 )
V_2 -> V_57 |= V_238 ;
else
V_2 -> V_57 &= ~ V_238 ;
F_22 ( L_81 ) ;
F_149 ( V_10 ) ;
goto V_62;
}
}
}
V_2 = F_53 ( V_10 , V_73 ) ;
if ( ! V_2 ) {
V_2 = F_153 ( V_10 , V_73 ) ;
if ( ! V_2 )
goto V_62;
V_2 -> V_149 = V_220 ;
F_141 ( V_10 , V_2 ) ;
}
memcpy ( V_2 -> V_76 , V_76 , V_107 ) ;
F_145 ( & V_2 -> V_217 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_146 (tmp,
&priv->lec_arp_tables[i], next) {
if ( V_2 != V_70 &&
! memcmp ( V_70 -> V_76 , V_76 , V_107 ) ) {
if ( V_70 -> V_149 > V_222 ) {
V_2 -> V_29 = V_70 -> V_29 ;
V_2 -> V_212 = V_70 -> V_212 ;
}
V_2 -> V_149 = V_70 -> V_149 ;
break;
}
}
}
if ( V_251 )
V_2 -> V_57 |= V_238 ;
else
V_2 -> V_57 &= ~ V_238 ;
if ( V_2 -> V_149 == V_221 || V_2 -> V_149 == V_220 ) {
V_2 -> V_149 = V_222 ;
F_68 ( V_10 , V_240 , V_2 -> V_73 , V_76 , NULL ) ;
}
F_22 ( L_82 ) ;
F_149 ( V_10 ) ;
V_62:
F_55 ( & V_10 -> V_80 , V_57 ) ;
}
static void
F_87 ( struct V_9 * V_10 , const struct V_130 * V_131 ,
struct V_28 * V_29 ,
void (* V_212) ( struct V_28 * V_29 , struct V_4 * V_5 ) )
{
unsigned long V_57 ;
struct V_1 * V_2 ;
int V_69 , V_252 = 0 ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
if ( V_131 -> V_253 == 2 ) {
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
V_2 = F_153 ( V_10 , V_247 ) ;
if ( V_2 == NULL )
goto V_62;
F_145 ( & V_2 -> V_217 ) ;
memcpy ( V_2 -> V_76 , V_131 -> V_76 , V_107 ) ;
V_2 -> V_155 = V_29 ;
V_2 -> V_214 = V_212 ;
F_143 ( & V_2 -> V_166 , & V_10 -> V_174 ) ;
goto V_62;
} else if ( V_131 -> V_253 == 1 ) {
F_22 ( L_84 ,
V_131 -> V_76 [ 0 ] , V_131 -> V_76 [ 1 ] ,
V_131 -> V_76 [ 2 ] , V_131 -> V_76 [ 3 ] ,
V_131 -> V_76 [ 4 ] , V_131 -> V_76 [ 5 ] ,
V_131 -> V_76 [ 6 ] , V_131 -> V_76 [ 7 ] ,
V_131 -> V_76 [ 8 ] , V_131 -> V_76 [ 9 ] ,
V_131 -> V_76 [ 10 ] , V_131 -> V_76 [ 11 ] ,
V_131 -> V_76 [ 12 ] , V_131 -> V_76 [ 13 ] ,
V_131 -> V_76 [ 14 ] , V_131 -> V_76 [ 15 ] ,
V_131 -> V_76 [ 16 ] , V_131 -> V_76 [ 17 ] ,
V_131 -> V_76 [ 18 ] , V_131 -> V_76 [ 19 ] ) ;
V_2 = F_153 ( V_10 , V_247 ) ;
if ( V_2 == NULL )
goto V_62;
memcpy ( V_2 -> V_76 , V_131 -> V_76 , V_107 ) ;
F_166 ( V_2 -> V_73 ) ;
V_2 -> V_155 = V_29 ;
V_2 -> V_214 = V_212 ;
V_2 -> V_149 = V_220 ;
V_2 -> V_217 . V_248 = V_234 + V_10 -> V_148 ;
V_2 -> V_217 . V_249 = F_160 ;
F_143 ( & V_2 -> V_166 , & V_10 -> V_173 ) ;
F_165 ( & V_2 -> V_217 ) ;
F_149 ( V_10 ) ;
goto V_62;
}
F_22 ( L_85 ,
V_131 -> V_76 [ 0 ] , V_131 -> V_76 [ 1 ] ,
V_131 -> V_76 [ 2 ] , V_131 -> V_76 [ 3 ] ,
V_131 -> V_76 [ 4 ] , V_131 -> V_76 [ 5 ] ,
V_131 -> V_76 [ 6 ] , V_131 -> V_76 [ 7 ] ,
V_131 -> V_76 [ 8 ] , V_131 -> V_76 [ 9 ] ,
V_131 -> V_76 [ 10 ] , V_131 -> V_76 [ 11 ] ,
V_131 -> V_76 [ 12 ] , V_131 -> V_76 [ 13 ] ,
V_131 -> V_76 [ 14 ] , V_131 -> V_76 [ 15 ] ,
V_131 -> V_76 [ 16 ] , V_131 -> V_76 [ 17 ] ,
V_131 -> V_76 [ 18 ] , V_131 -> V_76 [ 19 ] ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( memcmp
( V_131 -> V_76 , V_2 -> V_76 ,
V_107 ) == 0 ) {
F_22 ( L_86 ) ;
F_22 ( L_87 ,
V_2 -> V_29 ? V_2 -> V_29 -> V_64 : 0 ,
V_2 -> V_155 ? V_2 -> V_155 ->
V_64 : 0 ) ;
V_252 = 1 ;
F_145 ( & V_2 -> V_217 ) ;
V_2 -> V_29 = V_29 ;
V_2 -> V_212 = V_212 ;
if ( V_2 -> V_149 == V_222 ) {
if ( V_10 -> V_86
== 0 )
V_2 -> V_149 =
V_151 ;
else {
V_2 -> V_228 = V_234 ;
V_2 -> V_149 =
V_218 ;
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
if ( V_252 ) {
F_22 ( L_88 ) ;
F_149 ( V_10 ) ;
goto V_62;
}
V_2 = F_153 ( V_10 , V_247 ) ;
if ( ! V_2 )
goto V_62;
V_2 -> V_29 = V_29 ;
V_2 -> V_212 = V_212 ;
memcpy ( V_2 -> V_76 , V_131 -> V_76 , V_107 ) ;
F_166 ( V_2 -> V_73 ) ;
V_2 -> V_149 = V_220 ;
F_143 ( & V_2 -> V_166 , & V_10 -> V_122 ) ;
V_2 -> V_217 . V_248 = V_234 + V_10 -> V_148 ;
V_2 -> V_217 . V_249 = F_160 ;
F_165 ( & V_2 -> V_217 ) ;
F_22 ( L_88 ) ;
F_149 ( V_10 ) ;
V_62:
F_55 ( & V_10 -> V_80 , V_57 ) ;
}
static void F_51 ( struct V_9 * V_10 , unsigned long V_254 )
{
unsigned long V_57 ;
struct V_1 * V_2 ;
int V_69 ;
F_22 ( L_89 , V_254 ) ;
V_243:
F_52 ( & V_10 -> V_80 , V_57 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( V_2 -> V_255 == V_254 &&
V_2 -> V_149 == V_218 ) {
struct V_4 * V_5 ;
struct V_28 * V_29 = V_2 -> V_29 ;
F_1 ( V_2 ) ;
F_55 ( & V_10 -> V_80 ,
V_57 ) ;
while ( ( V_5 = F_44 ( & V_2 -> V_59 ) ) )
F_14 ( V_29 , V_5 ) ;
V_2 -> V_227 = V_234 ;
V_2 -> V_149 = V_151 ;
F_3 ( V_2 ) ;
F_22 ( L_90 ) ;
goto V_243;
}
}
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
F_149 ( V_10 ) ;
}
static void
F_61 ( struct V_9 * V_10 ,
const unsigned char * V_76 , unsigned long V_254 )
{
unsigned long V_57 ;
struct V_1 * V_2 ;
int V_69 ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ )
F_146 (entry,
&priv->lec_arp_tables[i], next) {
if ( ! memcmp ( V_76 , V_2 -> V_76 , V_107 ) ) {
V_2 -> V_255 = V_254 ;
F_22 ( L_91 ,
V_254 , V_2 ) ;
}
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
}
static int F_89 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
unsigned long V_57 ;
unsigned char V_73 [] = {
0xff , 0xff , 0xff , 0xff , 0xff , 0xff
} ;
struct V_1 * V_256 ;
struct V_65 * V_66 ;
int V_187 = 0 ;
V_66 = F_86 ( sizeof( struct V_65 ) , V_135 ) ;
if ( ! V_66 )
return - V_136 ;
V_66 -> V_67 = 0 ;
V_66 -> V_127 = V_29 -> V_137 ;
V_29 -> V_138 = V_66 ;
V_29 -> V_137 = F_81 ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
V_256 = F_153 ( V_10 , V_73 ) ;
if ( ! V_256 ) {
V_29 -> V_137 = V_66 -> V_127 ;
F_5 ( V_66 ) ;
V_187 = - V_136 ;
goto V_62;
}
memcpy ( V_256 -> V_76 , V_29 -> V_257 . V_258 . V_259 , V_107 ) ;
V_256 -> V_149 = V_151 ;
V_256 -> V_57 |= V_239 ;
V_256 -> V_29 = V_29 ;
V_256 -> V_212 = V_29 -> V_139 ;
V_29 -> V_139 = F_73 ;
V_10 -> V_231 = V_29 ;
F_141 ( V_10 , V_256 ) ;
V_62:
F_55 ( & V_10 -> V_80 , V_57 ) ;
return V_187 ;
}
static void F_74 ( struct V_9 * V_10 , struct V_28 * V_29 )
{
unsigned long V_57 ;
struct V_161 * V_166 ;
struct V_1 * V_2 ;
int V_69 ;
F_22 ( L_92 , V_29 -> V_63 , V_29 -> V_64 ) ;
F_149 ( V_10 ) ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
for ( V_69 = 0 ; V_69 < V_170 ; V_69 ++ ) {
F_151 (entry, next,
&priv->lec_arp_tables[i], next) {
if ( V_29 == V_2 -> V_29 ) {
F_54 ( V_10 , V_2 ) ;
F_3 ( V_2 ) ;
if ( V_10 -> V_231 == V_29 )
V_10 -> V_231 = NULL ;
}
}
}
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( V_2 -> V_29 == V_29 ) {
F_139 ( V_2 ) ;
F_145 ( & V_2 -> V_217 ) ;
F_144 ( & V_2 -> V_166 ) ;
F_3 ( V_2 ) ;
}
}
F_151 (entry, next,
&priv->lec_no_forward, next) {
if ( V_2 -> V_155 == V_29 ) {
F_139 ( V_2 ) ;
F_145 ( & V_2 -> V_217 ) ;
F_144 ( & V_2 -> V_166 ) ;
F_3 ( V_2 ) ;
}
}
F_151 (entry, next, &priv->mcast_fwds, next) {
if ( V_2 -> V_155 == V_29 ) {
F_139 ( V_2 ) ;
F_144 ( & V_2 -> V_166 ) ;
F_3 ( V_2 ) ;
}
}
F_55 ( & V_10 -> V_80 , V_57 ) ;
F_149 ( V_10 ) ;
}
static void
F_77 ( struct V_9 * V_10 ,
struct V_28 * V_29 , struct V_4 * V_5 )
{
unsigned long V_57 ;
struct V_161 * V_166 ;
struct V_1 * V_2 , * V_70 ;
struct V_38 * V_260 = (struct V_38 * ) V_5 -> V_11 ;
unsigned char * V_117 = V_260 -> V_120 ;
F_52 ( & V_10 -> V_80 , V_57 ) ;
F_151 (entry, next,
&priv->lec_arp_empty_ones, next) {
if ( V_29 == V_2 -> V_29 ) {
F_145 ( & V_2 -> V_217 ) ;
F_69 ( V_2 -> V_73 , V_117 ) ;
V_2 -> V_149 = V_151 ;
V_2 -> V_227 = V_234 ;
V_70 = F_53 ( V_10 , V_117 ) ;
if ( V_70 ) {
F_54 ( V_10 , V_70 ) ;
F_3 ( V_70 ) ;
}
F_144 ( & V_2 -> V_166 ) ;
F_141 ( V_10 , V_2 ) ;
goto V_62;
}
}
F_22 ( L_93 ) ;
V_62:
F_55 ( & V_10 -> V_80 , V_57 ) ;
}
