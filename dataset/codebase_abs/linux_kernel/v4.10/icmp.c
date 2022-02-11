static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return * F_2 ( V_2 -> V_3 . F_1 ) ;
}
static inline struct V_1 * F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 ;
F_4 () ;
V_4 = F_1 ( V_2 ) ;
if ( F_5 ( ! F_6 ( & V_4 -> V_5 . V_6 ) ) ) {
F_7 () ;
return NULL ;
}
return V_4 ;
}
static inline void F_8 ( struct V_1 * V_4 )
{
F_9 ( & V_4 -> V_5 . V_6 ) ;
}
bool F_10 ( void )
{
T_1 V_7 , V_8 , V_9 = 0 , V_10 = ( T_1 ) V_11 ;
bool V_12 = false ;
if ( ! V_13 . V_7 ) {
V_8 = F_11 ( T_1 , V_10 - V_13 . V_14 , V_15 ) ;
if ( V_8 < V_15 / 50 )
return false ;
}
F_12 ( & V_13 . V_16 ) ;
V_8 = F_11 ( T_1 , V_10 - V_13 . V_14 , V_15 ) ;
if ( V_8 >= V_15 / 50 ) {
V_9 = V_17 * V_8 / V_15 ;
if ( V_9 )
V_13 . V_14 = V_10 ;
}
V_7 = F_11 ( T_1 , V_13 . V_7 + V_9 , V_18 ) ;
if ( V_7 ) {
V_7 -- ;
V_12 = true ;
}
V_13 . V_7 = V_7 ;
F_13 ( & V_13 . V_16 ) ;
return V_12 ;
}
static bool F_14 ( struct V_2 * V_2 , struct V_19 * V_20 ,
struct V_21 * V_22 , int type , int V_23 )
{
struct V_24 * V_25 = & V_20 -> V_25 ;
bool V_12 = true ;
if ( type > V_26 )
goto V_27;
if ( type == V_28 && V_23 == V_29 )
goto V_27;
if ( V_25 -> V_30 && ( V_25 -> V_30 -> V_31 & V_32 ) )
goto V_27;
if ( ! ( ( 1 << type ) & V_2 -> V_3 . V_33 ) )
goto V_27;
V_12 = false ;
if ( F_10 () ) {
int V_34 = F_15 ( V_25 -> V_30 ) ;
struct V_35 * V_36 ;
V_36 = F_16 ( V_2 -> V_3 . V_37 , V_22 -> V_38 , V_34 , 1 ) ;
V_12 = F_17 ( V_36 ,
V_2 -> V_3 . V_39 ) ;
if ( V_36 )
F_18 ( V_36 ) ;
}
V_27:
return V_12 ;
}
void F_19 ( struct V_2 * V_2 , unsigned char type )
{
F_20 ( V_2 , type ) ;
F_21 ( V_2 , V_40 ) ;
}
static int F_22 ( void * V_41 , char * V_42 , int V_43 , int V_44 , int V_45 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_41 ;
T_2 V_50 ;
V_50 = F_23 ( V_49 -> V_47 ,
V_49 -> V_43 + V_43 ,
V_42 , V_44 , 0 ) ;
V_47 -> V_50 = F_24 ( V_47 -> V_50 , V_50 , V_45 ) ;
if ( V_51 [ V_49 -> V_52 . V_53 . type ] . error )
F_25 ( V_47 , V_49 -> V_47 ) ;
return 0 ;
}
static void F_26 ( struct V_48 * V_49 ,
struct V_21 * V_22 ,
struct V_54 * V_55 , struct V_19 * * V_20 )
{
struct V_1 * V_4 ;
struct V_46 * V_47 ;
V_4 = F_1 ( F_27 ( ( * V_20 ) -> V_25 . V_30 ) ) ;
if ( F_28 ( V_4 , V_22 , F_22 , V_49 ,
V_49 -> V_56 + V_49 -> V_57 ,
V_49 -> V_57 ,
V_55 , V_20 , V_58 ) < 0 ) {
F_29 ( F_30 ( V_4 ) , V_59 ) ;
F_31 ( V_4 ) ;
} else if ( ( V_47 = F_32 ( & V_4 -> V_60 ) ) != NULL ) {
struct V_61 * V_53 = F_33 ( V_47 ) ;
T_2 V_50 = 0 ;
struct V_46 * V_62 ;
F_34 (&sk->sk_write_queue, skb1) {
V_50 = F_35 ( V_50 , V_62 -> V_50 ) ;
}
V_50 = F_36 ( ( void * ) & V_49 -> V_52 ,
( char * ) V_53 ,
V_49 -> V_57 , V_50 ) ;
V_53 -> V_63 = F_37 ( V_50 ) ;
V_47 -> V_64 = V_65 ;
F_38 ( V_4 , V_22 ) ;
}
}
static void F_39 ( struct V_48 * V_49 , struct V_46 * V_47 )
{
struct V_54 V_55 ;
struct V_19 * V_20 = F_40 ( V_47 ) ;
struct V_2 * V_2 = F_27 ( V_20 -> V_25 . V_30 ) ;
struct V_21 V_22 ;
struct V_1 * V_4 ;
struct V_66 * V_67 ;
T_3 V_38 , V_68 ;
T_1 V_69 = F_41 ( V_2 , V_47 -> V_69 ) ;
if ( F_42 ( & V_49 -> V_70 . V_71 . V_71 , V_47 ) )
return;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 )
return;
V_67 = F_43 ( V_4 ) ;
V_49 -> V_52 . V_53 . V_63 = 0 ;
V_67 -> V_72 = F_44 ( V_47 ) -> V_72 ;
V_4 -> V_73 = V_69 ;
V_38 = V_55 . V_74 = F_44 ( V_47 ) -> V_68 ;
V_68 = F_45 ( V_47 ) ;
V_55 . V_71 = NULL ;
V_55 . V_75 = 0 ;
V_55 . V_76 = 0 ;
V_55 . V_72 = - 1 ;
if ( V_49 -> V_70 . V_71 . V_71 . V_77 ) {
V_55 . V_71 = & V_49 -> V_70 . V_71 ;
if ( V_55 . V_71 -> V_71 . V_78 )
V_38 = V_49 -> V_70 . V_71 . V_71 . V_79 ;
}
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
V_22 . V_38 = V_38 ;
V_22 . V_68 = V_68 ;
V_22 . V_80 = V_69 ;
V_22 . V_81 = F_46 ( V_2 , NULL ) ;
V_22 . V_82 = F_47 ( F_44 ( V_47 ) -> V_72 ) ;
V_22 . V_83 = V_84 ;
V_22 . V_85 = F_15 ( V_47 -> V_30 ) ;
F_48 ( V_47 , F_49 ( & V_22 ) ) ;
V_20 = F_50 ( V_2 , & V_22 ) ;
if ( F_51 ( V_20 ) )
goto V_86;
if ( F_14 ( V_2 , V_20 , & V_22 , V_49 -> V_52 . V_53 . type ,
V_49 -> V_52 . V_53 . V_23 ) )
F_26 ( V_49 , & V_22 , & V_55 , & V_20 ) ;
F_52 ( V_20 ) ;
V_86:
F_8 ( V_4 ) ;
}
static int F_53 ( const struct V_46 * V_47 )
{
const struct V_87 * V_88 = F_44 ( V_47 ) ;
return F_54 ( V_88 -> V_38 , V_88 -> V_68 ) ;
}
static struct V_19 * F_55 ( struct V_2 * V_2 ,
struct V_21 * V_22 ,
struct V_46 * V_89 ,
const struct V_87 * V_88 ,
T_3 V_68 , T_4 V_72 , T_1 V_69 ,
int type , int V_23 ,
struct V_48 * V_90 )
{
struct V_19 * V_20 , * V_91 ;
struct V_21 V_92 ;
int V_93 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_38 = ( V_90 -> V_70 . V_71 . V_71 . V_78 ?
V_90 -> V_70 . V_71 . V_71 . V_79 : V_88 -> V_68 ) ;
V_22 -> V_68 = V_68 ;
V_22 -> V_80 = V_69 ;
V_22 -> V_81 = F_46 ( V_2 , NULL ) ;
V_22 -> V_82 = F_47 ( V_72 ) ;
V_22 -> V_83 = V_84 ;
V_22 -> V_94 = type ;
V_22 -> V_95 = V_23 ;
V_22 -> V_85 = F_15 ( F_56 ( V_89 ) -> V_30 ) ;
F_48 ( V_89 , F_49 ( V_22 ) ) ;
V_20 = F_57 ( V_2 , V_22 ,
F_53 ( V_89 ) ) ;
if ( F_51 ( V_20 ) )
return V_20 ;
V_91 = V_20 ;
V_20 = (struct V_19 * ) F_58 ( V_2 , & V_20 -> V_25 ,
F_49 ( V_22 ) , NULL , 0 ) ;
if ( ! F_51 ( V_20 ) ) {
if ( V_20 != V_91 )
return V_20 ;
} else if ( F_59 ( V_20 ) == - V_96 ) {
V_20 = NULL ;
} else
return V_20 ;
V_93 = F_60 ( V_89 , F_49 ( & V_92 ) , V_97 ) ;
if ( V_93 )
goto V_98;
if ( F_61 ( V_2 , F_56 ( V_89 ) -> V_30 ,
V_92 . V_68 ) == V_99 ) {
V_91 = F_62 ( V_2 , & V_92 ) ;
if ( F_51 ( V_91 ) )
V_93 = F_59 ( V_91 ) ;
} else {
struct V_21 V_100 = {} ;
unsigned long V_101 ;
V_100 . V_38 = V_92 . V_68 ;
V_91 = F_50 ( V_2 , & V_100 ) ;
if ( F_51 ( V_91 ) ) {
V_93 = F_59 ( V_91 ) ;
goto V_98;
}
V_101 = V_89 -> V_102 ;
F_63 ( V_89 , NULL ) ;
V_93 = F_64 ( V_89 , V_92 . V_38 , V_92 . V_68 ,
F_47 ( V_72 ) , V_91 -> V_25 . V_30 ) ;
F_65 ( & V_91 -> V_25 ) ;
V_91 = F_40 ( V_89 ) ;
V_89 -> V_102 = V_101 ;
}
if ( V_93 )
goto V_98;
V_91 = (struct V_19 * ) F_58 ( V_2 , & V_91 -> V_25 ,
F_49 ( & V_92 ) , NULL ,
V_103 ) ;
if ( ! F_51 ( V_91 ) ) {
F_65 ( & V_20 -> V_25 ) ;
memcpy ( V_22 , & V_92 , sizeof( * V_22 ) ) ;
V_20 = V_91 ;
} else if ( F_59 ( V_91 ) == - V_96 ) {
if ( V_20 )
F_65 ( & V_20 -> V_25 ) ;
return V_91 ;
} else {
V_93 = F_59 ( V_91 ) ;
goto V_98;
}
return V_20 ;
V_98:
if ( V_20 )
return V_20 ;
return F_66 ( V_93 ) ;
}
void F_67 ( struct V_46 * V_89 , int type , int V_23 , T_3 V_104 )
{
struct V_87 * V_88 ;
int V_105 ;
struct V_48 * V_49 ;
struct V_19 * V_20 = F_40 ( V_89 ) ;
struct V_54 V_55 ;
struct V_21 V_22 ;
T_3 V_68 ;
T_4 V_72 ;
T_1 V_69 ;
struct V_2 * V_2 ;
struct V_1 * V_4 ;
if ( ! V_20 )
goto V_27;
V_2 = F_27 ( V_20 -> V_25 . V_30 ) ;
V_88 = F_44 ( V_89 ) ;
if ( ( T_4 * ) V_88 < V_89 -> V_106 ||
( F_68 ( V_89 ) + sizeof( * V_88 ) ) >
F_69 ( V_89 ) )
goto V_27;
if ( V_89 -> V_107 != V_108 )
goto V_27;
if ( V_20 -> V_109 & ( V_110 | V_111 ) )
goto V_27;
if ( V_88 -> V_112 & F_70 ( V_113 ) )
goto V_27;
if ( V_51 [ type ] . error ) {
if ( V_88 -> V_114 == V_84 ) {
T_4 V_115 , * V_116 ;
V_116 = F_71 ( V_89 ,
F_68 ( V_89 ) +
( V_88 -> V_117 << 2 ) +
F_72 ( struct V_61 ,
type ) -
V_89 -> V_52 ,
sizeof( V_115 ) ,
& V_115 ) ;
if ( ! V_116 )
goto V_27;
if ( * V_116 > V_26 ||
V_51 [ * V_116 ] . error )
goto V_27;
}
}
V_49 = F_73 ( sizeof( * V_49 ) , V_118 ) ;
if ( ! V_49 )
return;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 )
goto V_119;
V_68 = V_88 -> V_38 ;
if ( ! ( V_20 -> V_109 & V_120 ) ) {
struct V_121 * V_30 = NULL ;
F_74 () ;
if ( F_75 ( V_20 ) &&
V_2 -> V_3 . V_122 )
V_30 = F_76 ( V_2 , F_77 ( V_89 ) ) ;
if ( V_30 )
V_68 = F_78 ( V_30 , 0 , V_123 ) ;
else
V_68 = 0 ;
F_79 () ;
}
V_72 = V_51 [ type ] . error ? ( ( V_88 -> V_72 & V_124 ) |
V_125 ) :
V_88 -> V_72 ;
V_69 = F_41 ( V_2 , V_89 -> V_69 ) ;
if ( F_42 ( & V_49 -> V_70 . V_71 . V_71 , V_89 ) )
goto V_86;
V_49 -> V_52 . V_53 . type = type ;
V_49 -> V_52 . V_53 . V_23 = V_23 ;
V_49 -> V_52 . V_53 . V_126 . V_127 = V_104 ;
V_49 -> V_52 . V_53 . V_63 = 0 ;
V_49 -> V_47 = V_89 ;
V_49 -> V_43 = F_80 ( V_89 ) ;
F_43 ( V_4 ) -> V_72 = V_72 ;
V_4 -> V_73 = V_69 ;
V_55 . V_74 = V_88 -> V_68 ;
V_55 . V_71 = & V_49 -> V_70 . V_71 ;
V_55 . V_75 = 0 ;
V_55 . V_76 = 0 ;
V_55 . V_72 = - 1 ;
V_20 = F_55 ( V_2 , & V_22 , V_89 , V_88 , V_68 , V_72 , V_69 ,
type , V_23 , V_49 ) ;
if ( F_51 ( V_20 ) )
goto V_86;
if ( ! F_14 ( V_2 , V_20 , & V_22 , type , V_23 ) )
goto V_128;
V_105 = F_81 ( & V_20 -> V_25 ) ;
if ( V_105 > 576 )
V_105 = 576 ;
V_105 -= sizeof( struct V_87 ) + V_49 -> V_70 . V_71 . V_71 . V_77 ;
V_105 -= sizeof( struct V_61 ) ;
V_49 -> V_56 = V_89 -> V_44 - V_49 -> V_43 ;
if ( V_49 -> V_56 > V_105 )
V_49 -> V_56 = V_105 ;
V_49 -> V_57 = sizeof( struct V_61 ) ;
F_26 ( V_49 , & V_22 , & V_55 , & V_20 ) ;
V_128:
F_52 ( V_20 ) ;
V_86:
F_8 ( V_4 ) ;
V_119:
F_82 ( V_49 ) ;
V_27: ;
}
static void F_83 ( struct V_46 * V_47 , T_1 V_104 )
{
const struct V_87 * V_88 = ( const struct V_87 * ) V_47 -> V_52 ;
const struct V_129 * V_130 ;
int V_114 = V_88 -> V_114 ;
if ( ! F_84 ( V_47 , V_88 -> V_117 * 4 + 8 ) ) {
F_29 ( F_27 ( V_47 -> V_30 ) , V_131 ) ;
return;
}
F_85 ( V_47 , V_114 , V_104 ) ;
V_130 = F_86 ( V_132 [ V_114 ] ) ;
if ( V_130 && V_130 -> V_133 )
V_130 -> V_133 ( V_47 , V_104 ) ;
}
static bool F_87 ( int V_134 )
{
bool V_135 ;
F_74 () ;
V_135 = F_86 ( V_132 [ V_134 ] ) -> V_136 ;
F_79 () ;
return V_135 ;
}
static bool F_88 ( struct V_46 * V_47 )
{
const struct V_87 * V_88 ;
struct V_61 * V_53 ;
struct V_2 * V_2 ;
T_1 V_104 = 0 ;
V_2 = F_27 ( F_56 ( V_47 ) -> V_30 ) ;
if ( ! F_84 ( V_47 , sizeof( struct V_87 ) ) )
goto V_137;
V_53 = F_33 ( V_47 ) ;
V_88 = ( const struct V_87 * ) V_47 -> V_52 ;
if ( V_88 -> V_117 < 5 )
goto V_137;
if ( V_53 -> type == V_28 ) {
switch ( V_53 -> V_23 & 15 ) {
case V_138 :
case V_139 :
case V_140 :
case V_141 :
break;
case V_29 :
switch ( V_2 -> V_3 . V_142 ) {
default:
F_89 ( L_1 ,
& V_88 -> V_38 ) ;
break;
case 2 :
goto V_27;
case 3 :
if ( ! F_87 ( V_88 -> V_114 ) )
goto V_27;
case 0 :
V_104 = F_90 ( V_53 -> V_126 . V_143 . V_144 ) ;
}
break;
case V_145 :
F_89 ( L_2 ,
& V_88 -> V_38 ) ;
break;
default:
break;
}
if ( V_53 -> V_23 > V_146 )
goto V_27;
} else if ( V_53 -> type == V_147 )
V_104 = F_91 ( V_53 -> V_126 . V_127 ) >> 24 ;
if ( ! V_2 -> V_3 . V_148 &&
F_61 ( V_2 , V_47 -> V_30 , V_88 -> V_38 ) == V_149 ) {
F_92 ( L_3 ,
& F_44 ( V_47 ) -> V_68 ,
V_53 -> type , V_53 -> V_23 ,
& V_88 -> V_38 , V_47 -> V_30 -> V_150 ) ;
goto V_27;
}
F_83 ( V_47 , V_104 ) ;
V_27:
return true ;
V_137:
F_29 ( V_2 , V_131 ) ;
return false ;
}
static bool F_93 ( struct V_46 * V_47 )
{
if ( V_47 -> V_44 < sizeof( struct V_87 ) ) {
F_29 ( F_27 ( V_47 -> V_30 ) , V_131 ) ;
return false ;
}
if ( ! F_84 ( V_47 , sizeof( struct V_87 ) ) ) {
return false ;
}
F_83 ( V_47 , F_33 ( V_47 ) -> V_126 . V_127 ) ;
return true ;
}
static bool F_94 ( struct V_46 * V_47 )
{
struct V_2 * V_2 ;
V_2 = F_27 ( F_56 ( V_47 ) -> V_30 ) ;
if ( ! V_2 -> V_3 . V_151 ) {
struct V_48 V_49 ;
V_49 . V_52 . V_53 = * F_33 ( V_47 ) ;
V_49 . V_52 . V_53 . type = V_152 ;
V_49 . V_47 = V_47 ;
V_49 . V_43 = 0 ;
V_49 . V_56 = V_47 -> V_44 ;
V_49 . V_57 = sizeof( struct V_61 ) ;
F_39 ( & V_49 , V_47 ) ;
}
return true ;
}
static bool F_95 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
if ( V_47 -> V_44 < 4 )
goto V_137;
V_49 . V_52 . V_153 [ 1 ] = F_96 () ;
V_49 . V_52 . V_153 [ 2 ] = V_49 . V_52 . V_153 [ 1 ] ;
if ( F_97 ( V_47 , 0 , & V_49 . V_52 . V_153 [ 0 ] , 4 ) )
F_98 () ;
V_49 . V_52 . V_53 = * F_33 ( V_47 ) ;
V_49 . V_52 . V_53 . type = V_154 ;
V_49 . V_52 . V_53 . V_23 = 0 ;
V_49 . V_47 = V_47 ;
V_49 . V_43 = 0 ;
V_49 . V_56 = 0 ;
V_49 . V_57 = sizeof( struct V_61 ) + 12 ;
F_39 ( & V_49 , V_47 ) ;
return true ;
V_137:
F_29 ( F_27 ( F_56 ( V_47 ) -> V_30 ) , V_131 ) ;
return false ;
}
static bool F_99 ( struct V_46 * V_47 )
{
return true ;
}
int F_100 ( struct V_46 * V_47 )
{
struct V_61 * V_53 ;
struct V_19 * V_20 = F_40 ( V_47 ) ;
struct V_2 * V_2 = F_27 ( V_20 -> V_25 . V_30 ) ;
bool V_155 ;
if ( ! F_101 ( NULL , V_156 , V_47 ) ) {
struct V_157 * V_158 = F_102 ( V_47 ) ;
int V_159 ;
if ( ! ( V_158 && V_158 -> V_160 [ V_158 -> V_44 - 1 ] -> V_161 . V_31 &
V_162 ) )
goto V_163;
if ( ! F_84 ( V_47 , sizeof( * V_53 ) + sizeof( struct V_87 ) ) )
goto V_163;
V_159 = F_80 ( V_47 ) ;
F_103 ( V_47 , sizeof( * V_53 ) ) ;
if ( ! F_104 ( NULL , V_156 , V_47 ) )
goto V_163;
F_103 ( V_47 , V_159 ) ;
}
F_29 ( V_2 , V_164 ) ;
if ( F_105 ( V_47 ) )
goto V_165;
if ( ! F_106 ( V_47 , sizeof( * V_53 ) ) )
goto error;
V_53 = F_33 ( V_47 ) ;
F_107 ( V_2 , V_53 -> type ) ;
if ( V_53 -> type > V_26 )
goto error;
if ( V_20 -> V_109 & ( V_110 | V_111 ) ) {
if ( ( V_53 -> type == V_166 ||
V_53 -> type == V_167 ) &&
V_2 -> V_3 . V_168 ) {
goto error;
}
if ( V_53 -> type != V_166 &&
V_53 -> type != V_167 &&
V_53 -> type != V_169 &&
V_53 -> type != V_170 ) {
goto error;
}
}
V_155 = V_51 [ V_53 -> type ] . F_108 ( V_47 ) ;
if ( V_155 ) {
F_109 ( V_47 ) ;
return V_171 ;
}
V_163:
F_110 ( V_47 ) ;
return V_172 ;
V_165:
F_29 ( V_2 , V_173 ) ;
error:
F_29 ( V_2 , V_131 ) ;
goto V_163;
}
void F_111 ( struct V_46 * V_47 , T_1 V_104 )
{
struct V_87 * V_88 = (struct V_87 * ) V_47 -> V_52 ;
int V_43 = V_88 -> V_117 << 2 ;
struct V_61 * V_53 = (struct V_61 * ) ( V_47 -> V_52 + V_43 ) ;
int type = F_33 ( V_47 ) -> type ;
int V_23 = F_33 ( V_47 ) -> V_23 ;
struct V_2 * V_2 = F_27 ( V_47 -> V_30 ) ;
if ( V_53 -> type != V_152 ) {
F_112 ( V_47 , V_43 , V_104 ) ;
return;
}
if ( type == V_28 && V_23 == V_29 )
F_113 ( V_47 , V_2 , V_104 , 0 , 0 , V_84 , 0 ) ;
else if ( type == V_174 )
F_114 ( V_47 , V_2 , 0 , 0 , V_84 , 0 ) ;
}
static void T_5 F_115 ( struct V_2 * V_2 )
{
int V_175 ;
F_116 (i)
F_117 ( * F_118 ( V_2 -> V_3 . F_1 , V_175 ) ) ;
F_119 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_120 ( struct V_2 * V_2 )
{
int V_175 , V_93 ;
V_2 -> V_3 . F_1 = F_121 ( struct V_1 * ) ;
if ( ! V_2 -> V_3 . F_1 )
return - V_176 ;
F_116 (i) {
struct V_1 * V_4 ;
V_93 = F_122 ( & V_4 , V_177 ,
V_178 , V_84 , V_2 ) ;
if ( V_93 < 0 )
goto V_179;
* F_118 ( V_2 -> V_3 . F_1 , V_175 ) = V_4 ;
V_4 -> V_180 = 2 * F_123 ( 64 * 1024 ) ;
F_124 ( V_4 , V_181 ) ;
F_43 ( V_4 ) -> V_182 = V_183 ;
}
V_2 -> V_3 . V_151 = 0 ;
V_2 -> V_3 . V_168 = 1 ;
V_2 -> V_3 . V_148 = 1 ;
V_2 -> V_3 . V_39 = 1 * V_15 ;
V_2 -> V_3 . V_33 = 0x1818 ;
V_2 -> V_3 . V_122 = 0 ;
return 0 ;
V_179:
F_116 (i)
F_117 ( * F_118 ( V_2 -> V_3 . F_1 , V_175 ) ) ;
F_119 ( V_2 -> V_3 . F_1 ) ;
return V_93 ;
}
int T_7 F_125 ( void )
{
return F_126 ( & V_184 ) ;
}
