static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return * F_2 ( V_2 -> V_3 . F_1 ) ;
}
static inline struct V_1 * F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_4 ;
V_4 = F_1 ( V_2 ) ;
if ( F_4 ( ! F_5 ( & V_4 -> V_5 . V_6 ) ) ) {
return NULL ;
}
return V_4 ;
}
static inline void F_6 ( struct V_1 * V_4 )
{
F_7 ( & V_4 -> V_5 . V_6 ) ;
}
bool F_8 ( void )
{
T_1 V_7 , V_8 , V_9 = 0 , V_10 = ( T_1 ) V_11 ;
bool V_12 = false ;
if ( ! V_13 . V_7 ) {
V_8 = F_9 ( T_1 , V_10 - V_13 . V_14 , V_15 ) ;
if ( V_8 < V_15 / 50 )
return false ;
}
F_10 ( & V_13 . V_16 ) ;
V_8 = F_9 ( T_1 , V_10 - V_13 . V_14 , V_15 ) ;
if ( V_8 >= V_15 / 50 ) {
V_9 = V_17 * V_8 / V_15 ;
if ( V_9 )
V_13 . V_14 = V_10 ;
}
V_7 = F_9 ( T_1 , V_13 . V_7 + V_9 , V_18 ) ;
if ( V_7 ) {
V_7 -- ;
V_12 = true ;
}
V_13 . V_7 = V_7 ;
F_7 ( & V_13 . V_16 ) ;
return V_12 ;
}
static bool F_11 ( struct V_2 * V_2 , int type , int V_19 )
{
if ( type > V_20 )
return true ;
if ( type == V_21 && V_19 == V_22 )
return true ;
if ( ! ( ( 1 << type ) & V_2 -> V_3 . V_23 ) )
return true ;
return false ;
}
static bool F_12 ( struct V_2 * V_2 , int type , int V_19 )
{
if ( F_11 ( V_2 , type , V_19 ) )
return true ;
if ( F_8 () )
return true ;
return false ;
}
static bool F_13 ( struct V_2 * V_2 , struct V_24 * V_25 ,
struct V_26 * V_27 , int type , int V_19 )
{
struct V_28 * V_29 = & V_25 -> V_29 ;
struct V_30 * V_31 ;
bool V_12 = true ;
int V_32 ;
if ( F_11 ( V_2 , type , V_19 ) )
goto V_33;
if ( V_29 -> V_34 && ( V_29 -> V_34 -> V_35 & V_36 ) )
goto V_33;
V_32 = F_14 ( V_29 -> V_34 ) ;
V_31 = F_15 ( V_2 -> V_3 . V_37 , V_27 -> V_38 , V_32 , 1 ) ;
V_12 = F_16 ( V_31 , V_2 -> V_3 . V_39 ) ;
if ( V_31 )
F_17 ( V_31 ) ;
V_33:
return V_12 ;
}
void F_18 ( struct V_2 * V_2 , unsigned char type )
{
F_19 ( V_2 , type ) ;
F_20 ( V_2 , V_40 ) ;
}
static int F_21 ( void * V_41 , char * V_42 , int V_43 , int V_44 , int V_45 ,
struct V_46 * V_47 )
{
struct V_48 * V_49 = (struct V_48 * ) V_41 ;
T_2 V_50 ;
V_50 = F_22 ( V_49 -> V_47 ,
V_49 -> V_43 + V_43 ,
V_42 , V_44 , 0 ) ;
V_47 -> V_50 = F_23 ( V_47 -> V_50 , V_50 , V_45 ) ;
if ( V_51 [ V_49 -> V_52 . V_53 . type ] . error )
F_24 ( V_47 , V_49 -> V_47 ) ;
return 0 ;
}
static void F_25 ( struct V_48 * V_49 ,
struct V_26 * V_27 ,
struct V_54 * V_55 , struct V_24 * * V_25 )
{
struct V_1 * V_4 ;
struct V_46 * V_47 ;
V_4 = F_1 ( F_26 ( ( * V_25 ) -> V_29 . V_34 ) ) ;
if ( F_27 ( V_4 , V_27 , F_21 , V_49 ,
V_49 -> V_56 + V_49 -> V_57 ,
V_49 -> V_57 ,
V_55 , V_25 , V_58 ) < 0 ) {
F_28 ( F_29 ( V_4 ) , V_59 ) ;
F_30 ( V_4 ) ;
} else if ( ( V_47 = F_31 ( & V_4 -> V_60 ) ) != NULL ) {
struct V_61 * V_53 = F_32 ( V_47 ) ;
T_2 V_50 = 0 ;
struct V_46 * V_62 ;
F_33 (&sk->sk_write_queue, skb1) {
V_50 = F_34 ( V_50 , V_62 -> V_50 ) ;
}
V_50 = F_35 ( ( void * ) & V_49 -> V_52 ,
( char * ) V_53 ,
V_49 -> V_57 , V_50 ) ;
V_53 -> V_63 = F_36 ( V_50 ) ;
V_47 -> V_64 = V_65 ;
F_37 ( V_4 , V_27 ) ;
}
}
static void F_38 ( struct V_48 * V_49 , struct V_46 * V_47 )
{
struct V_54 V_55 ;
struct V_24 * V_25 = F_39 ( V_47 ) ;
struct V_2 * V_2 = F_26 ( V_25 -> V_29 . V_34 ) ;
struct V_26 V_27 ;
struct V_1 * V_4 ;
struct V_66 * V_67 ;
T_3 V_38 , V_68 ;
T_1 V_69 = F_40 ( V_2 , V_47 -> V_69 ) ;
int type = V_49 -> V_52 . V_53 . type ;
int V_19 = V_49 -> V_52 . V_53 . V_19 ;
if ( F_41 ( & V_49 -> V_70 . V_71 . V_71 , V_47 ) )
return;
F_42 () ;
if ( ! F_12 ( V_2 , type , V_19 ) )
goto V_72;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 )
goto V_72;
V_67 = F_43 ( V_4 ) ;
V_49 -> V_52 . V_53 . V_63 = 0 ;
V_67 -> V_73 = F_44 ( V_47 ) -> V_73 ;
V_4 -> V_74 = V_69 ;
V_38 = V_55 . V_75 = F_44 ( V_47 ) -> V_68 ;
V_68 = F_45 ( V_47 ) ;
V_55 . V_71 = NULL ;
V_55 . V_76 = 0 ;
V_55 . V_77 = 0 ;
V_55 . V_73 = - 1 ;
if ( V_49 -> V_70 . V_71 . V_71 . V_78 ) {
V_55 . V_71 = & V_49 -> V_70 . V_71 ;
if ( V_55 . V_71 -> V_71 . V_79 )
V_38 = V_49 -> V_70 . V_71 . V_71 . V_80 ;
}
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_38 = V_38 ;
V_27 . V_68 = V_68 ;
V_27 . V_81 = V_69 ;
V_27 . V_82 = F_46 ( V_2 , NULL ) ;
V_27 . V_83 = F_47 ( F_44 ( V_47 ) -> V_73 ) ;
V_27 . V_84 = V_85 ;
V_27 . V_86 = F_14 ( V_47 -> V_34 ) ;
F_48 ( V_47 , F_49 ( & V_27 ) ) ;
V_25 = F_50 ( V_2 , & V_27 ) ;
if ( F_51 ( V_25 ) )
goto V_87;
if ( F_13 ( V_2 , V_25 , & V_27 , type , V_19 ) )
F_25 ( V_49 , & V_27 , & V_55 , & V_25 ) ;
F_52 ( V_25 ) ;
V_87:
F_6 ( V_4 ) ;
V_72:
F_53 () ;
}
static int F_54 ( const struct V_46 * V_47 )
{
const struct V_88 * V_89 = F_44 ( V_47 ) ;
return F_55 ( V_89 -> V_38 , V_89 -> V_68 ) ;
}
static struct V_24 * F_56 ( struct V_2 * V_2 ,
struct V_26 * V_27 ,
struct V_46 * V_90 ,
const struct V_88 * V_89 ,
T_3 V_68 , T_4 V_73 , T_1 V_69 ,
int type , int V_19 ,
struct V_48 * V_91 )
{
struct V_24 * V_25 , * V_92 ;
struct V_26 V_93 ;
int V_94 ;
memset ( V_27 , 0 , sizeof( * V_27 ) ) ;
V_27 -> V_38 = ( V_91 -> V_70 . V_71 . V_71 . V_79 ?
V_91 -> V_70 . V_71 . V_71 . V_80 : V_89 -> V_68 ) ;
V_27 -> V_68 = V_68 ;
V_27 -> V_81 = V_69 ;
V_27 -> V_82 = F_46 ( V_2 , NULL ) ;
V_27 -> V_83 = F_47 ( V_73 ) ;
V_27 -> V_84 = V_85 ;
V_27 -> V_95 = type ;
V_27 -> V_96 = V_19 ;
V_27 -> V_86 = F_14 ( F_57 ( V_90 ) -> V_34 ) ;
F_48 ( V_90 , F_49 ( V_27 ) ) ;
V_25 = F_58 ( V_2 , V_27 ,
F_54 ( V_90 ) ) ;
if ( F_51 ( V_25 ) )
return V_25 ;
V_92 = V_25 ;
V_25 = (struct V_24 * ) F_59 ( V_2 , & V_25 -> V_29 ,
F_49 ( V_27 ) , NULL , 0 ) ;
if ( ! F_51 ( V_25 ) ) {
if ( V_25 != V_92 )
return V_25 ;
} else if ( F_60 ( V_25 ) == - V_97 ) {
V_25 = NULL ;
} else
return V_25 ;
V_94 = F_61 ( V_90 , F_49 ( & V_93 ) , V_98 ) ;
if ( V_94 )
goto V_99;
if ( F_62 ( V_2 , F_57 ( V_90 ) -> V_34 ,
V_93 . V_68 ) == V_100 ) {
V_92 = F_63 ( V_2 , & V_93 ) ;
if ( F_51 ( V_92 ) )
V_94 = F_60 ( V_92 ) ;
} else {
struct V_26 V_101 = {} ;
unsigned long V_102 ;
V_101 . V_38 = V_93 . V_68 ;
V_92 = F_50 ( V_2 , & V_101 ) ;
if ( F_51 ( V_92 ) ) {
V_94 = F_60 ( V_92 ) ;
goto V_99;
}
V_102 = V_90 -> V_103 ;
F_64 ( V_90 , NULL ) ;
V_94 = F_65 ( V_90 , V_93 . V_38 , V_93 . V_68 ,
F_47 ( V_73 ) , V_92 -> V_29 . V_34 ) ;
F_66 ( & V_92 -> V_29 ) ;
V_92 = F_39 ( V_90 ) ;
V_90 -> V_103 = V_102 ;
}
if ( V_94 )
goto V_99;
V_92 = (struct V_24 * ) F_59 ( V_2 , & V_92 -> V_29 ,
F_49 ( & V_93 ) , NULL ,
V_104 ) ;
if ( ! F_51 ( V_92 ) ) {
F_66 ( & V_25 -> V_29 ) ;
memcpy ( V_27 , & V_93 , sizeof( * V_27 ) ) ;
V_25 = V_92 ;
} else if ( F_60 ( V_92 ) == - V_97 ) {
if ( V_25 )
F_66 ( & V_25 -> V_29 ) ;
return V_92 ;
} else {
V_94 = F_60 ( V_92 ) ;
goto V_99;
}
return V_25 ;
V_99:
if ( V_25 )
return V_25 ;
return F_67 ( V_94 ) ;
}
void F_68 ( struct V_46 * V_90 , int type , int V_19 , T_3 V_105 )
{
struct V_88 * V_89 ;
int V_106 ;
struct V_48 V_49 ;
struct V_24 * V_25 = F_39 ( V_90 ) ;
struct V_54 V_55 ;
struct V_26 V_27 ;
T_3 V_68 ;
T_4 V_73 ;
T_1 V_69 ;
struct V_2 * V_2 ;
struct V_1 * V_4 ;
if ( ! V_25 )
goto V_33;
V_2 = F_26 ( V_25 -> V_29 . V_34 ) ;
V_89 = F_44 ( V_90 ) ;
if ( ( T_4 * ) V_89 < V_90 -> V_107 ||
( F_69 ( V_90 ) + sizeof( * V_89 ) ) >
F_70 ( V_90 ) )
goto V_33;
if ( V_90 -> V_108 != V_109 )
goto V_33;
if ( V_25 -> V_110 & ( V_111 | V_112 ) )
goto V_33;
if ( V_89 -> V_113 & F_71 ( V_114 ) )
goto V_33;
if ( V_51 [ type ] . error ) {
if ( V_89 -> V_115 == V_85 ) {
T_4 V_116 , * V_117 ;
V_117 = F_72 ( V_90 ,
F_69 ( V_90 ) +
( V_89 -> V_118 << 2 ) +
F_73 ( struct V_61 ,
type ) -
V_90 -> V_52 ,
sizeof( V_116 ) ,
& V_116 ) ;
if ( ! V_117 )
goto V_33;
if ( * V_117 > V_20 ||
V_51 [ * V_117 ] . error )
goto V_33;
}
}
F_42 () ;
if ( ! F_12 ( V_2 , type , V_19 ) )
goto V_72;
V_4 = F_3 ( V_2 ) ;
if ( ! V_4 )
goto V_72;
V_68 = V_89 -> V_38 ;
if ( ! ( V_25 -> V_110 & V_119 ) ) {
struct V_120 * V_34 = NULL ;
F_74 () ;
if ( F_75 ( V_25 ) &&
V_2 -> V_3 . V_121 )
V_34 = F_76 ( V_2 , F_77 ( V_90 ) ) ;
if ( V_34 )
V_68 = F_78 ( V_34 , 0 , V_122 ) ;
else
V_68 = 0 ;
F_79 () ;
}
V_73 = V_51 [ type ] . error ? ( ( V_89 -> V_73 & V_123 ) |
V_124 ) :
V_89 -> V_73 ;
V_69 = F_40 ( V_2 , V_90 -> V_69 ) ;
if ( F_41 ( & V_49 . V_70 . V_71 . V_71 , V_90 ) )
goto V_87;
V_49 . V_52 . V_53 . type = type ;
V_49 . V_52 . V_53 . V_19 = V_19 ;
V_49 . V_52 . V_53 . V_125 . V_126 = V_105 ;
V_49 . V_52 . V_53 . V_63 = 0 ;
V_49 . V_47 = V_90 ;
V_49 . V_43 = F_80 ( V_90 ) ;
F_43 ( V_4 ) -> V_73 = V_73 ;
V_4 -> V_74 = V_69 ;
V_55 . V_75 = V_89 -> V_68 ;
V_55 . V_71 = & V_49 . V_70 . V_71 ;
V_55 . V_76 = 0 ;
V_55 . V_77 = 0 ;
V_55 . V_73 = - 1 ;
V_25 = F_56 ( V_2 , & V_27 , V_90 , V_89 , V_68 , V_73 , V_69 ,
type , V_19 , & V_49 ) ;
if ( F_51 ( V_25 ) )
goto V_87;
if ( ! F_13 ( V_2 , V_25 , & V_27 , type , V_19 ) )
goto V_127;
V_106 = F_81 ( & V_25 -> V_29 ) ;
if ( V_106 > 576 )
V_106 = 576 ;
V_106 -= sizeof( struct V_88 ) + V_49 . V_70 . V_71 . V_71 . V_78 ;
V_106 -= sizeof( struct V_61 ) ;
V_49 . V_56 = V_90 -> V_44 - V_49 . V_43 ;
if ( V_49 . V_56 > V_106 )
V_49 . V_56 = V_106 ;
V_49 . V_57 = sizeof( struct V_61 ) ;
F_25 ( & V_49 , & V_27 , & V_55 , & V_25 ) ;
V_127:
F_52 ( V_25 ) ;
V_87:
F_6 ( V_4 ) ;
V_72:
F_53 () ;
V_33: ;
}
static void F_82 ( struct V_46 * V_47 , T_1 V_105 )
{
const struct V_88 * V_89 = ( const struct V_88 * ) V_47 -> V_52 ;
const struct V_128 * V_129 ;
int V_115 = V_89 -> V_115 ;
if ( ! F_83 ( V_47 , V_89 -> V_118 * 4 + 8 ) ) {
F_28 ( F_26 ( V_47 -> V_34 ) , V_130 ) ;
return;
}
F_84 ( V_47 , V_115 , V_105 ) ;
V_129 = F_85 ( V_131 [ V_115 ] ) ;
if ( V_129 && V_129 -> V_132 )
V_129 -> V_132 ( V_47 , V_105 ) ;
}
static bool F_86 ( int V_133 )
{
bool V_134 ;
F_74 () ;
V_134 = F_85 ( V_131 [ V_133 ] ) -> V_135 ;
F_79 () ;
return V_134 ;
}
static bool F_87 ( struct V_46 * V_47 )
{
const struct V_88 * V_89 ;
struct V_61 * V_53 ;
struct V_2 * V_2 ;
T_1 V_105 = 0 ;
V_2 = F_26 ( F_57 ( V_47 ) -> V_34 ) ;
if ( ! F_83 ( V_47 , sizeof( struct V_88 ) ) )
goto V_136;
V_53 = F_32 ( V_47 ) ;
V_89 = ( const struct V_88 * ) V_47 -> V_52 ;
if ( V_89 -> V_118 < 5 )
goto V_136;
if ( V_53 -> type == V_21 ) {
switch ( V_53 -> V_19 & 15 ) {
case V_137 :
case V_138 :
case V_139 :
case V_140 :
break;
case V_22 :
switch ( V_2 -> V_3 . V_141 ) {
default:
F_88 ( L_1 ,
& V_89 -> V_38 ) ;
break;
case 2 :
goto V_33;
case 3 :
if ( ! F_86 ( V_89 -> V_115 ) )
goto V_33;
case 0 :
V_105 = F_89 ( V_53 -> V_125 . V_142 . V_143 ) ;
}
break;
case V_144 :
F_88 ( L_2 ,
& V_89 -> V_38 ) ;
break;
default:
break;
}
if ( V_53 -> V_19 > V_145 )
goto V_33;
} else if ( V_53 -> type == V_146 )
V_105 = F_90 ( V_53 -> V_125 . V_126 ) >> 24 ;
if ( ! V_2 -> V_3 . V_147 &&
F_62 ( V_2 , V_47 -> V_34 , V_89 -> V_38 ) == V_148 ) {
F_91 ( L_3 ,
& F_44 ( V_47 ) -> V_68 ,
V_53 -> type , V_53 -> V_19 ,
& V_89 -> V_38 , V_47 -> V_34 -> V_149 ) ;
goto V_33;
}
F_82 ( V_47 , V_105 ) ;
V_33:
return true ;
V_136:
F_28 ( V_2 , V_130 ) ;
return false ;
}
static bool F_92 ( struct V_46 * V_47 )
{
if ( V_47 -> V_44 < sizeof( struct V_88 ) ) {
F_28 ( F_26 ( V_47 -> V_34 ) , V_130 ) ;
return false ;
}
if ( ! F_83 ( V_47 , sizeof( struct V_88 ) ) ) {
return false ;
}
F_82 ( V_47 , F_32 ( V_47 ) -> V_125 . V_126 ) ;
return true ;
}
static bool F_93 ( struct V_46 * V_47 )
{
struct V_2 * V_2 ;
V_2 = F_26 ( F_57 ( V_47 ) -> V_34 ) ;
if ( ! V_2 -> V_3 . V_150 ) {
struct V_48 V_49 ;
V_49 . V_52 . V_53 = * F_32 ( V_47 ) ;
V_49 . V_52 . V_53 . type = V_151 ;
V_49 . V_47 = V_47 ;
V_49 . V_43 = 0 ;
V_49 . V_56 = V_47 -> V_44 ;
V_49 . V_57 = sizeof( struct V_61 ) ;
F_38 ( & V_49 , V_47 ) ;
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
V_49 . V_52 . V_53 = * F_32 ( V_47 ) ;
V_49 . V_52 . V_53 . type = V_153 ;
V_49 . V_52 . V_53 . V_19 = 0 ;
V_49 . V_47 = V_47 ;
V_49 . V_43 = 0 ;
V_49 . V_56 = 0 ;
V_49 . V_57 = sizeof( struct V_61 ) + 12 ;
F_38 ( & V_49 , V_47 ) ;
return true ;
V_136:
F_28 ( F_26 ( F_57 ( V_47 ) -> V_34 ) , V_130 ) ;
return false ;
}
static bool F_98 ( struct V_46 * V_47 )
{
return true ;
}
int F_99 ( struct V_46 * V_47 )
{
struct V_61 * V_53 ;
struct V_24 * V_25 = F_39 ( V_47 ) ;
struct V_2 * V_2 = F_26 ( V_25 -> V_29 . V_34 ) ;
bool V_154 ;
if ( ! F_100 ( NULL , V_155 , V_47 ) ) {
struct V_156 * V_157 = F_101 ( V_47 ) ;
int V_158 ;
if ( ! ( V_157 && V_157 -> V_159 [ V_157 -> V_44 - 1 ] -> V_160 . V_35 &
V_161 ) )
goto V_162;
if ( ! F_83 ( V_47 , sizeof( * V_53 ) + sizeof( struct V_88 ) ) )
goto V_162;
V_158 = F_80 ( V_47 ) ;
F_102 ( V_47 , sizeof( * V_53 ) ) ;
if ( ! F_103 ( NULL , V_155 , V_47 ) )
goto V_162;
F_102 ( V_47 , V_158 ) ;
}
F_28 ( V_2 , V_163 ) ;
if ( F_104 ( V_47 ) )
goto V_164;
if ( ! F_105 ( V_47 , sizeof( * V_53 ) ) )
goto error;
V_53 = F_32 ( V_47 ) ;
F_106 ( V_2 , V_53 -> type ) ;
if ( V_53 -> type > V_20 )
goto error;
if ( V_25 -> V_110 & ( V_111 | V_112 ) ) {
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
return V_170 ;
}
V_162:
F_109 ( V_47 ) ;
return V_171 ;
V_164:
F_28 ( V_2 , V_172 ) ;
error:
F_28 ( V_2 , V_130 ) ;
goto V_162;
}
void F_110 ( struct V_46 * V_47 , T_1 V_105 )
{
struct V_88 * V_89 = (struct V_88 * ) V_47 -> V_52 ;
int V_43 = V_89 -> V_118 << 2 ;
struct V_61 * V_53 = (struct V_61 * ) ( V_47 -> V_52 + V_43 ) ;
int type = F_32 ( V_47 ) -> type ;
int V_19 = F_32 ( V_47 ) -> V_19 ;
struct V_2 * V_2 = F_26 ( V_47 -> V_34 ) ;
if ( V_53 -> type != V_151 ) {
F_111 ( V_47 , V_43 , V_105 ) ;
return;
}
if ( type == V_21 && V_19 == V_22 )
F_112 ( V_47 , V_2 , V_105 , 0 , 0 , V_85 , 0 ) ;
else if ( type == V_173 )
F_113 ( V_47 , V_2 , 0 , 0 , V_85 , 0 ) ;
}
static void T_5 F_114 ( struct V_2 * V_2 )
{
int V_174 ;
F_115 (i)
F_116 ( * F_117 ( V_2 -> V_3 . F_1 , V_174 ) ) ;
F_118 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_119 ( struct V_2 * V_2 )
{
int V_174 , V_94 ;
V_2 -> V_3 . F_1 = F_120 ( struct V_1 * ) ;
if ( ! V_2 -> V_3 . F_1 )
return - V_175 ;
F_115 (i) {
struct V_1 * V_4 ;
V_94 = F_121 ( & V_4 , V_176 ,
V_177 , V_85 , V_2 ) ;
if ( V_94 < 0 )
goto V_178;
* F_117 ( V_2 -> V_3 . F_1 , V_174 ) = V_4 ;
V_4 -> V_179 = 2 * F_122 ( 64 * 1024 ) ;
F_123 ( V_4 , V_180 ) ;
F_43 ( V_4 ) -> V_181 = V_182 ;
}
V_2 -> V_3 . V_150 = 0 ;
V_2 -> V_3 . V_167 = 1 ;
V_2 -> V_3 . V_147 = 1 ;
V_2 -> V_3 . V_39 = 1 * V_15 ;
V_2 -> V_3 . V_23 = 0x1818 ;
V_2 -> V_3 . V_121 = 0 ;
return 0 ;
V_178:
F_115 (i)
F_116 ( * F_117 ( V_2 -> V_3 . F_1 , V_174 ) ) ;
F_118 ( V_2 -> V_3 . F_1 ) ;
return V_94 ;
}
int T_7 F_124 ( void )
{
return F_125 ( & V_183 ) ;
}
