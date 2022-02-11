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
V_22 . V_81 = F_46 ( F_44 ( V_47 ) -> V_72 ) ;
V_22 . V_82 = V_83 ;
V_22 . V_84 = F_15 ( V_47 -> V_30 ) ;
F_47 ( V_47 , F_48 ( & V_22 ) ) ;
V_20 = F_49 ( V_2 , & V_22 ) ;
if ( F_50 ( V_20 ) )
goto V_85;
if ( F_14 ( V_2 , V_20 , & V_22 , V_49 -> V_52 . V_53 . type ,
V_49 -> V_52 . V_53 . V_23 ) )
F_26 ( V_49 , & V_22 , & V_55 , & V_20 ) ;
F_51 ( V_20 ) ;
V_85:
F_8 ( V_4 ) ;
}
static int F_52 ( const struct V_46 * V_47 )
{
const struct V_86 * V_87 = F_44 ( V_47 ) ;
return F_53 ( V_87 -> V_38 , V_87 -> V_68 ) ;
}
static struct V_19 * F_54 ( struct V_2 * V_2 ,
struct V_21 * V_22 ,
struct V_46 * V_88 ,
const struct V_86 * V_87 ,
T_3 V_68 , T_4 V_72 , T_1 V_69 ,
int type , int V_23 ,
struct V_48 * V_89 )
{
struct V_19 * V_20 , * V_90 ;
struct V_21 V_91 ;
int V_92 ;
memset ( V_22 , 0 , sizeof( * V_22 ) ) ;
V_22 -> V_38 = ( V_89 -> V_70 . V_71 . V_71 . V_78 ?
V_89 -> V_70 . V_71 . V_71 . V_79 : V_87 -> V_68 ) ;
V_22 -> V_68 = V_68 ;
V_22 -> V_80 = V_69 ;
V_22 -> V_81 = F_46 ( V_72 ) ;
V_22 -> V_82 = V_83 ;
V_22 -> V_93 = type ;
V_22 -> V_94 = V_23 ;
V_22 -> V_84 = F_15 ( V_88 -> V_30 ) ;
F_47 ( V_88 , F_48 ( V_22 ) ) ;
V_20 = F_55 ( V_2 , V_22 ,
F_52 ( V_88 ) ) ;
if ( F_50 ( V_20 ) )
return V_20 ;
V_90 = V_20 ;
V_20 = (struct V_19 * ) F_56 ( V_2 , & V_20 -> V_25 ,
F_48 ( V_22 ) , NULL , 0 ) ;
if ( ! F_50 ( V_20 ) ) {
if ( V_20 != V_90 )
return V_20 ;
} else if ( F_57 ( V_20 ) == - V_95 ) {
V_20 = NULL ;
} else
return V_20 ;
V_92 = F_58 ( V_88 , F_48 ( & V_91 ) , V_96 ) ;
if ( V_92 )
goto V_97;
if ( F_59 ( V_2 , V_88 -> V_30 ,
V_91 . V_68 ) == V_98 ) {
V_90 = F_60 ( V_2 , & V_91 ) ;
if ( F_50 ( V_90 ) )
V_92 = F_57 ( V_90 ) ;
} else {
struct V_21 V_99 = {} ;
unsigned long V_100 ;
V_99 . V_38 = V_91 . V_68 ;
V_90 = F_49 ( V_2 , & V_99 ) ;
if ( F_50 ( V_90 ) ) {
V_92 = F_57 ( V_90 ) ;
goto V_97;
}
V_100 = V_88 -> V_101 ;
F_61 ( V_88 , NULL ) ;
V_92 = F_62 ( V_88 , V_91 . V_38 , V_91 . V_68 ,
F_46 ( V_72 ) , V_90 -> V_25 . V_30 ) ;
F_63 ( & V_90 -> V_25 ) ;
V_90 = F_40 ( V_88 ) ;
V_88 -> V_101 = V_100 ;
}
if ( V_92 )
goto V_97;
V_90 = (struct V_19 * ) F_56 ( V_2 , & V_90 -> V_25 ,
F_48 ( & V_91 ) , NULL ,
V_102 ) ;
if ( ! F_50 ( V_90 ) ) {
F_63 ( & V_20 -> V_25 ) ;
memcpy ( V_22 , & V_91 , sizeof( * V_22 ) ) ;
V_20 = V_90 ;
} else if ( F_57 ( V_90 ) == - V_95 ) {
if ( V_20 )
F_63 ( & V_20 -> V_25 ) ;
return V_90 ;
} else {
V_92 = F_57 ( V_90 ) ;
goto V_97;
}
return V_20 ;
V_97:
if ( V_20 )
return V_20 ;
return F_64 ( V_92 ) ;
}
void F_65 ( struct V_46 * V_88 , int type , int V_23 , T_3 V_103 )
{
struct V_86 * V_87 ;
int V_104 ;
struct V_48 * V_49 ;
struct V_19 * V_20 = F_40 ( V_88 ) ;
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
V_87 = F_44 ( V_88 ) ;
if ( ( T_4 * ) V_87 < V_88 -> V_105 ||
( F_66 ( V_88 ) + sizeof( * V_87 ) ) >
F_67 ( V_88 ) )
goto V_27;
if ( V_88 -> V_106 != V_107 )
goto V_27;
if ( V_20 -> V_108 & ( V_109 | V_110 ) )
goto V_27;
if ( V_87 -> V_111 & F_68 ( V_112 ) )
goto V_27;
if ( V_51 [ type ] . error ) {
if ( V_87 -> V_113 == V_83 ) {
T_4 V_114 , * V_115 ;
V_115 = F_69 ( V_88 ,
F_66 ( V_88 ) +
( V_87 -> V_116 << 2 ) +
F_70 ( struct V_61 ,
type ) -
V_88 -> V_52 ,
sizeof( V_114 ) ,
& V_114 ) ;
if ( ! V_115 )
goto V_27;
if ( * V_115 > V_26 ||
V_51 [ * V_115 ] . error )
goto V_27;
}
}
V_49 = F_71 ( sizeof( * V_49 ) , V_117 ) ;
if ( ! V_49 )
return;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 )
goto V_118;
V_68 = V_87 -> V_38 ;
if ( ! ( V_20 -> V_108 & V_119 ) ) {
struct V_120 * V_30 = NULL ;
F_72 () ;
if ( F_73 ( V_20 ) &&
V_2 -> V_3 . V_121 )
V_30 = F_74 ( V_2 , F_75 ( V_88 ) ) ;
if ( V_30 )
V_68 = F_76 ( V_30 , 0 , V_122 ) ;
else
V_68 = 0 ;
F_77 () ;
}
V_72 = V_51 [ type ] . error ? ( ( V_87 -> V_72 & V_123 ) |
V_124 ) :
V_87 -> V_72 ;
V_69 = F_41 ( V_2 , V_88 -> V_69 ) ;
if ( F_42 ( & V_49 -> V_70 . V_71 . V_71 , V_88 ) )
goto V_85;
V_49 -> V_52 . V_53 . type = type ;
V_49 -> V_52 . V_53 . V_23 = V_23 ;
V_49 -> V_52 . V_53 . V_125 . V_126 = V_103 ;
V_49 -> V_52 . V_53 . V_63 = 0 ;
V_49 -> V_47 = V_88 ;
V_49 -> V_43 = F_78 ( V_88 ) ;
F_43 ( V_4 ) -> V_72 = V_72 ;
V_4 -> V_73 = V_69 ;
V_55 . V_74 = V_87 -> V_68 ;
V_55 . V_71 = & V_49 -> V_70 . V_71 ;
V_55 . V_75 = 0 ;
V_55 . V_76 = 0 ;
V_55 . V_72 = - 1 ;
V_20 = F_54 ( V_2 , & V_22 , V_88 , V_87 , V_68 , V_72 , V_69 ,
type , V_23 , V_49 ) ;
if ( F_50 ( V_20 ) )
goto V_85;
if ( ! F_14 ( V_2 , V_20 , & V_22 , type , V_23 ) )
goto V_127;
V_104 = F_79 ( & V_20 -> V_25 ) ;
if ( V_104 > 576 )
V_104 = 576 ;
V_104 -= sizeof( struct V_86 ) + V_49 -> V_70 . V_71 . V_71 . V_77 ;
V_104 -= sizeof( struct V_61 ) ;
V_49 -> V_56 = V_88 -> V_44 - V_49 -> V_43 ;
if ( V_49 -> V_56 > V_104 )
V_49 -> V_56 = V_104 ;
V_49 -> V_57 = sizeof( struct V_61 ) ;
F_26 ( V_49 , & V_22 , & V_55 , & V_20 ) ;
V_127:
F_51 ( V_20 ) ;
V_85:
F_8 ( V_4 ) ;
V_118:
F_80 ( V_49 ) ;
V_27: ;
}
static void F_81 ( struct V_46 * V_47 , T_1 V_103 )
{
const struct V_86 * V_87 = ( const struct V_86 * ) V_47 -> V_52 ;
const struct V_128 * V_129 ;
int V_113 = V_87 -> V_113 ;
if ( ! F_82 ( V_47 , V_87 -> V_116 * 4 + 8 ) ) {
F_29 ( F_27 ( V_47 -> V_30 ) , V_130 ) ;
return;
}
F_83 ( V_47 , V_113 , V_103 ) ;
V_129 = F_84 ( V_131 [ V_113 ] ) ;
if ( V_129 && V_129 -> V_132 )
V_129 -> V_132 ( V_47 , V_103 ) ;
}
static bool F_85 ( int V_133 )
{
bool V_134 ;
F_72 () ;
V_134 = F_84 ( V_131 [ V_133 ] ) -> V_135 ;
F_77 () ;
return V_134 ;
}
static bool F_86 ( struct V_46 * V_47 )
{
const struct V_86 * V_87 ;
struct V_61 * V_53 ;
struct V_2 * V_2 ;
T_1 V_103 = 0 ;
V_2 = F_27 ( F_87 ( V_47 ) -> V_30 ) ;
if ( ! F_82 ( V_47 , sizeof( struct V_86 ) ) )
goto V_136;
V_53 = F_33 ( V_47 ) ;
V_87 = ( const struct V_86 * ) V_47 -> V_52 ;
if ( V_87 -> V_116 < 5 )
goto V_136;
if ( V_53 -> type == V_28 ) {
switch ( V_53 -> V_23 & 15 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
break;
case V_29 :
switch ( V_2 -> V_3 . V_141 ) {
default:
F_88 ( L_1 ,
& V_87 -> V_38 ) ;
break;
case 2 :
goto V_27;
case 3 :
if ( ! F_85 ( V_87 -> V_113 ) )
goto V_27;
case 0 :
V_103 = F_89 ( V_53 -> V_125 . V_142 . V_143 ) ;
}
break;
case V_144 :
F_88 ( L_2 ,
& V_87 -> V_38 ) ;
break;
default:
break;
}
if ( V_53 -> V_23 > V_145 )
goto V_27;
} else if ( V_53 -> type == V_146 )
V_103 = F_90 ( V_53 -> V_125 . V_126 ) >> 24 ;
if ( ! V_2 -> V_3 . V_147 &&
F_59 ( V_2 , V_47 -> V_30 , V_87 -> V_38 ) == V_148 ) {
F_91 ( L_3 ,
& F_44 ( V_47 ) -> V_68 ,
V_53 -> type , V_53 -> V_23 ,
& V_87 -> V_38 , V_47 -> V_30 -> V_149 ) ;
goto V_27;
}
F_81 ( V_47 , V_103 ) ;
V_27:
return true ;
V_136:
F_29 ( V_2 , V_130 ) ;
return false ;
}
static bool F_92 ( struct V_46 * V_47 )
{
if ( V_47 -> V_44 < sizeof( struct V_86 ) ) {
F_29 ( F_27 ( V_47 -> V_30 ) , V_130 ) ;
return false ;
}
if ( ! F_82 ( V_47 , sizeof( struct V_86 ) ) ) {
return false ;
}
F_81 ( V_47 , F_33 ( V_47 ) -> V_125 . V_126 ) ;
return true ;
}
static bool F_93 ( struct V_46 * V_47 )
{
struct V_2 * V_2 ;
V_2 = F_27 ( F_87 ( V_47 ) -> V_30 ) ;
if ( ! V_2 -> V_3 . V_150 ) {
struct V_48 V_49 ;
V_49 . V_52 . V_53 = * F_33 ( V_47 ) ;
V_49 . V_52 . V_53 . type = V_151 ;
V_49 . V_47 = V_47 ;
V_49 . V_43 = 0 ;
V_49 . V_56 = V_47 -> V_44 ;
V_49 . V_57 = sizeof( struct V_61 ) ;
F_39 ( & V_49 , V_47 ) ;
}
return true ;
}
static bool F_94 ( struct V_46 * V_47 )
{
struct V_48 V_49 ;
if ( V_47 -> V_44 < 4 )
goto V_136;
V_49 . V_52 . V_152 [ 1 ] = F_95 () ;
V_49 . V_52 . V_152 [ 2 ] = V_49 . V_52 . V_152 [ 1 ] ;
if ( F_96 ( V_47 , 0 , & V_49 . V_52 . V_152 [ 0 ] , 4 ) )
F_97 () ;
V_49 . V_52 . V_53 = * F_33 ( V_47 ) ;
V_49 . V_52 . V_53 . type = V_153 ;
V_49 . V_52 . V_53 . V_23 = 0 ;
V_49 . V_47 = V_47 ;
V_49 . V_43 = 0 ;
V_49 . V_56 = 0 ;
V_49 . V_57 = sizeof( struct V_61 ) + 12 ;
F_39 ( & V_49 , V_47 ) ;
return true ;
V_136:
F_29 ( F_27 ( F_87 ( V_47 ) -> V_30 ) , V_130 ) ;
return false ;
}
static bool F_98 ( struct V_46 * V_47 )
{
return true ;
}
int F_99 ( struct V_46 * V_47 )
{
struct V_61 * V_53 ;
struct V_19 * V_20 = F_40 ( V_47 ) ;
struct V_2 * V_2 = F_27 ( V_20 -> V_25 . V_30 ) ;
bool V_154 ;
if ( ! F_100 ( NULL , V_155 , V_47 ) ) {
struct V_156 * V_157 = F_101 ( V_47 ) ;
int V_158 ;
if ( ! ( V_157 && V_157 -> V_159 [ V_157 -> V_44 - 1 ] -> V_160 . V_31 &
V_161 ) )
goto V_162;
if ( ! F_82 ( V_47 , sizeof( * V_53 ) + sizeof( struct V_86 ) ) )
goto V_162;
V_158 = F_78 ( V_47 ) ;
F_102 ( V_47 , sizeof( * V_53 ) ) ;
if ( ! F_103 ( NULL , V_155 , V_47 ) )
goto V_162;
F_102 ( V_47 , V_158 ) ;
}
F_29 ( V_2 , V_163 ) ;
if ( F_104 ( V_47 ) )
goto V_164;
if ( ! F_105 ( V_47 , sizeof( * V_53 ) ) )
goto error;
V_53 = F_33 ( V_47 ) ;
F_106 ( V_2 , V_53 -> type ) ;
if ( V_53 -> type > V_26 )
goto error;
if ( V_20 -> V_108 & ( V_109 | V_110 ) ) {
if ( ( V_53 -> type == V_165 ||
V_53 -> type == V_166 ) &&
V_2 -> V_3 . V_167 ) {
goto error;
}
if ( V_53 -> type != V_165 &&
V_53 -> type != V_166 &&
V_53 -> type != V_168 &&
V_53 -> type != V_169 ) {
goto error;
}
}
V_154 = V_51 [ V_53 -> type ] . F_107 ( V_47 ) ;
if ( V_154 ) {
F_108 ( V_47 ) ;
return 0 ;
}
V_162:
F_109 ( V_47 ) ;
return 0 ;
V_164:
F_29 ( V_2 , V_170 ) ;
error:
F_29 ( V_2 , V_130 ) ;
goto V_162;
}
void F_110 ( struct V_46 * V_47 , T_1 V_103 )
{
struct V_86 * V_87 = (struct V_86 * ) V_47 -> V_52 ;
int V_43 = V_87 -> V_116 << 2 ;
struct V_61 * V_53 = (struct V_61 * ) ( V_47 -> V_52 + V_43 ) ;
int type = F_33 ( V_47 ) -> type ;
int V_23 = F_33 ( V_47 ) -> V_23 ;
struct V_2 * V_2 = F_27 ( V_47 -> V_30 ) ;
if ( V_53 -> type != V_151 ) {
F_111 ( V_47 , V_43 , V_103 ) ;
return;
}
if ( type == V_28 && V_23 == V_29 )
F_112 ( V_47 , V_2 , V_103 , 0 , 0 , V_83 , 0 ) ;
else if ( type == V_171 )
F_113 ( V_47 , V_2 , 0 , 0 , V_83 , 0 ) ;
}
static void T_5 F_114 ( struct V_2 * V_2 )
{
int V_172 ;
F_115 (i)
F_116 ( * F_117 ( V_2 -> V_3 . F_1 , V_172 ) ) ;
F_118 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_119 ( struct V_2 * V_2 )
{
int V_172 , V_92 ;
V_2 -> V_3 . F_1 = F_120 ( struct V_1 * ) ;
if ( ! V_2 -> V_3 . F_1 )
return - V_173 ;
F_115 (i) {
struct V_1 * V_4 ;
V_92 = F_121 ( & V_4 , V_174 ,
V_175 , V_83 , V_2 ) ;
if ( V_92 < 0 )
goto V_176;
* F_117 ( V_2 -> V_3 . F_1 , V_172 ) = V_4 ;
V_4 -> V_177 = 2 * F_122 ( 64 * 1024 ) ;
F_123 ( V_4 , V_178 ) ;
F_43 ( V_4 ) -> V_179 = V_180 ;
}
V_2 -> V_3 . V_150 = 0 ;
V_2 -> V_3 . V_167 = 1 ;
V_2 -> V_3 . V_147 = 1 ;
V_2 -> V_3 . V_39 = 1 * V_15 ;
V_2 -> V_3 . V_33 = 0x1818 ;
V_2 -> V_3 . V_121 = 0 ;
return 0 ;
V_176:
F_115 (i)
F_116 ( * F_117 ( V_2 -> V_3 . F_1 , V_172 ) ) ;
F_118 ( V_2 -> V_3 . F_1 ) ;
return V_92 ;
}
int T_7 F_124 ( void )
{
return F_125 ( & V_181 ) ;
}
