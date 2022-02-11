static struct V_1 * F_1 ( struct V_2 * V_2 )
{
return V_2 -> V_3 . F_1 [ F_2 () ] ;
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
static inline bool F_10 ( struct V_2 * V_2 , struct V_7 * V_8 ,
struct V_9 * V_10 , int type , int V_11 )
{
struct V_12 * V_13 = & V_8 -> V_13 ;
bool V_14 = true ;
if ( type > V_15 )
goto V_16;
if ( type == V_17 && V_11 == V_18 )
goto V_16;
if ( V_13 -> V_19 && ( V_13 -> V_19 -> V_20 & V_21 ) )
goto V_16;
if ( ( 1 << type ) & V_2 -> V_3 . V_22 ) {
struct V_23 * V_24 = F_11 ( V_2 -> V_3 . V_25 , V_10 -> V_26 , 1 ) ;
V_14 = F_12 ( V_24 ,
V_2 -> V_3 . V_27 ) ;
if ( V_24 )
F_13 ( V_24 ) ;
}
V_16:
return V_14 ;
}
void F_14 ( struct V_2 * V_2 , unsigned char type )
{
F_15 ( V_2 , type ) ;
F_16 ( V_2 , V_28 ) ;
}
static int F_17 ( void * V_29 , char * V_30 , int V_31 , int V_32 , int V_33 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 = (struct V_36 * ) V_29 ;
T_1 V_38 ;
V_38 = F_18 ( V_37 -> V_35 ,
V_37 -> V_31 + V_31 ,
V_30 , V_32 , 0 ) ;
V_35 -> V_38 = F_19 ( V_35 -> V_38 , V_38 , V_33 ) ;
if ( V_39 [ V_37 -> V_40 . V_41 . type ] . error )
F_20 ( V_35 , V_37 -> V_35 ) ;
return 0 ;
}
static void F_21 ( struct V_36 * V_37 ,
struct V_9 * V_10 ,
struct V_42 * V_43 , struct V_7 * * V_8 )
{
struct V_1 * V_4 ;
struct V_34 * V_35 ;
V_4 = F_1 ( F_22 ( ( * V_8 ) -> V_13 . V_19 ) ) ;
if ( F_23 ( V_4 , V_10 , F_17 , V_37 ,
V_37 -> V_44 + V_37 -> V_45 ,
V_37 -> V_45 ,
V_43 , V_8 , V_46 ) < 0 ) {
F_24 ( F_25 ( V_4 ) , V_47 ) ;
F_26 ( V_4 ) ;
} else if ( ( V_35 = F_27 ( & V_4 -> V_48 ) ) != NULL ) {
struct V_49 * V_41 = F_28 ( V_35 ) ;
T_1 V_38 = 0 ;
struct V_34 * V_50 ;
F_29 (&sk->sk_write_queue, skb1) {
V_38 = F_30 ( V_38 , V_50 -> V_38 ) ;
}
V_38 = F_31 ( ( void * ) & V_37 -> V_40 ,
( char * ) V_41 ,
V_37 -> V_45 , V_38 ) ;
V_41 -> V_51 = F_32 ( V_38 ) ;
V_35 -> V_52 = V_53 ;
F_33 ( V_4 , V_10 ) ;
}
}
static void F_34 ( struct V_36 * V_37 , struct V_34 * V_35 )
{
struct V_42 V_43 ;
struct V_7 * V_8 = F_35 ( V_35 ) ;
struct V_2 * V_2 = F_22 ( V_8 -> V_13 . V_19 ) ;
struct V_9 V_10 ;
struct V_1 * V_4 ;
struct V_54 * V_55 ;
T_2 V_26 , V_56 ;
T_3 V_57 = F_36 ( V_2 , V_35 -> V_57 ) ;
if ( F_37 ( & V_37 -> V_58 . V_59 . V_59 , V_35 ) )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_55 = F_38 ( V_4 ) ;
V_37 -> V_40 . V_41 . V_51 = 0 ;
V_55 -> V_60 = F_39 ( V_35 ) -> V_60 ;
V_4 -> V_61 = V_57 ;
V_26 = V_43 . V_62 = F_39 ( V_35 ) -> V_56 ;
V_56 = F_40 ( V_35 ) ;
V_43 . V_59 = NULL ;
V_43 . V_63 = 0 ;
V_43 . V_64 = 0 ;
V_43 . V_60 = - 1 ;
if ( V_37 -> V_58 . V_59 . V_59 . V_65 ) {
V_43 . V_59 = & V_37 -> V_58 . V_59 ;
if ( V_43 . V_59 -> V_59 . V_66 )
V_26 = V_37 -> V_58 . V_59 . V_59 . V_67 ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_26 = V_26 ;
V_10 . V_56 = V_56 ;
V_10 . V_68 = V_57 ;
V_10 . V_69 = F_41 ( F_39 ( V_35 ) -> V_60 ) ;
V_10 . V_70 = V_71 ;
F_42 ( V_35 , F_43 ( & V_10 ) ) ;
V_8 = F_44 ( V_2 , & V_10 ) ;
if ( F_45 ( V_8 ) )
goto V_72;
if ( F_10 ( V_2 , V_8 , & V_10 , V_37 -> V_40 . V_41 . type ,
V_37 -> V_40 . V_41 . V_11 ) )
F_21 ( V_37 , & V_10 , & V_43 , & V_8 ) ;
F_46 ( V_8 ) ;
V_72:
F_8 ( V_4 ) ;
}
static struct V_7 * F_47 ( struct V_2 * V_2 ,
struct V_9 * V_10 ,
struct V_34 * V_73 ,
const struct V_74 * V_75 ,
T_2 V_56 , T_4 V_60 , T_3 V_57 ,
int type , int V_11 ,
struct V_36 * V_76 )
{
struct V_7 * V_8 , * V_77 ;
struct V_9 V_78 ;
int V_79 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_26 = ( V_76 -> V_58 . V_59 . V_59 . V_66 ?
V_76 -> V_58 . V_59 . V_59 . V_67 : V_75 -> V_56 ) ;
V_10 -> V_56 = V_56 ;
V_10 -> V_68 = V_57 ;
V_10 -> V_69 = F_41 ( V_60 ) ;
V_10 -> V_70 = V_71 ;
V_10 -> V_80 = type ;
V_10 -> V_81 = V_11 ;
F_42 ( V_73 , F_43 ( V_10 ) ) ;
V_8 = F_48 ( V_2 , V_10 ) ;
if ( F_45 ( V_8 ) )
return V_8 ;
V_77 = V_8 ;
V_8 = (struct V_7 * ) F_49 ( V_2 , & V_8 -> V_13 ,
F_43 ( V_10 ) , NULL , 0 ) ;
if ( ! F_45 ( V_8 ) ) {
if ( V_8 != V_77 )
return V_8 ;
} else if ( F_50 ( V_8 ) == - V_82 ) {
V_8 = NULL ;
} else
return V_8 ;
V_79 = F_51 ( V_73 , F_43 ( & V_78 ) , V_83 ) ;
if ( V_79 )
goto V_84;
if ( F_52 ( V_2 , V_78 . V_56 ) == V_85 ) {
V_77 = F_48 ( V_2 , & V_78 ) ;
if ( F_45 ( V_77 ) )
V_79 = F_50 ( V_77 ) ;
} else {
struct V_9 V_86 = {} ;
unsigned long V_87 ;
V_86 . V_26 = V_78 . V_56 ;
V_77 = F_44 ( V_2 , & V_86 ) ;
if ( F_45 ( V_77 ) ) {
V_79 = F_50 ( V_77 ) ;
goto V_84;
}
V_87 = V_73 -> V_88 ;
V_79 = F_53 ( V_73 , V_78 . V_26 , V_78 . V_56 ,
F_41 ( V_60 ) , V_77 -> V_13 . V_19 ) ;
F_54 ( & V_77 -> V_13 ) ;
V_77 = F_35 ( V_73 ) ;
V_73 -> V_88 = V_87 ;
}
if ( V_79 )
goto V_84;
V_77 = (struct V_7 * ) F_49 ( V_2 , & V_77 -> V_13 ,
F_43 ( & V_78 ) , NULL ,
V_89 ) ;
if ( ! F_45 ( V_77 ) ) {
F_54 ( & V_8 -> V_13 ) ;
memcpy ( V_10 , & V_78 , sizeof( * V_10 ) ) ;
V_8 = V_77 ;
} else if ( F_50 ( V_77 ) == - V_82 ) {
if ( V_8 )
F_54 ( & V_8 -> V_13 ) ;
return V_77 ;
} else {
V_79 = F_50 ( V_77 ) ;
goto V_84;
}
return V_8 ;
V_84:
if ( V_8 )
return V_8 ;
return F_55 ( V_79 ) ;
}
void F_56 ( struct V_34 * V_73 , int type , int V_11 , T_2 V_90 )
{
struct V_74 * V_75 ;
int V_91 ;
struct V_36 * V_37 ;
struct V_7 * V_8 = F_35 ( V_73 ) ;
struct V_42 V_43 ;
struct V_9 V_10 ;
T_2 V_56 ;
T_4 V_60 ;
T_3 V_57 ;
struct V_2 * V_2 ;
struct V_1 * V_4 ;
if ( ! V_8 )
goto V_16;
V_2 = F_22 ( V_8 -> V_13 . V_19 ) ;
V_75 = F_39 ( V_73 ) ;
if ( ( T_4 * ) V_75 < V_73 -> V_92 ||
( F_57 ( V_73 ) + sizeof( * V_75 ) ) >
F_58 ( V_73 ) )
goto V_16;
if ( V_73 -> V_93 != V_94 )
goto V_16;
if ( V_8 -> V_95 & ( V_96 | V_97 ) )
goto V_16;
if ( V_75 -> V_98 & F_59 ( V_99 ) )
goto V_16;
if ( V_39 [ type ] . error ) {
if ( V_75 -> V_100 == V_71 ) {
T_4 V_101 , * V_102 ;
V_102 = F_60 ( V_73 ,
F_57 ( V_73 ) +
( V_75 -> V_103 << 2 ) +
F_61 ( struct V_49 ,
type ) -
V_73 -> V_40 ,
sizeof( V_101 ) ,
& V_101 ) ;
if ( V_102 == NULL )
goto V_16;
if ( * V_102 > V_15 ||
V_39 [ * V_102 ] . error )
goto V_16;
}
}
V_37 = F_62 ( sizeof( * V_37 ) , V_104 ) ;
if ( ! V_37 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
goto V_105;
V_56 = V_75 -> V_26 ;
if ( ! ( V_8 -> V_95 & V_106 ) ) {
struct V_107 * V_19 = NULL ;
F_63 () ;
if ( F_64 ( V_8 ) &&
V_2 -> V_3 . V_108 )
V_19 = F_65 ( V_2 , F_66 ( V_73 ) ) ;
if ( V_19 )
V_56 = F_67 ( V_19 , 0 , V_109 ) ;
else
V_56 = 0 ;
F_68 () ;
}
V_60 = V_39 [ type ] . error ? ( ( V_75 -> V_60 & V_110 ) |
V_111 ) :
V_75 -> V_60 ;
V_57 = F_36 ( V_2 , V_73 -> V_57 ) ;
if ( F_37 ( & V_37 -> V_58 . V_59 . V_59 , V_73 ) )
goto V_72;
V_37 -> V_40 . V_41 . type = type ;
V_37 -> V_40 . V_41 . V_11 = V_11 ;
V_37 -> V_40 . V_41 . V_112 . V_113 = V_90 ;
V_37 -> V_40 . V_41 . V_51 = 0 ;
V_37 -> V_35 = V_73 ;
V_37 -> V_31 = F_69 ( V_73 ) ;
F_38 ( V_4 ) -> V_60 = V_60 ;
V_4 -> V_61 = V_57 ;
V_43 . V_62 = V_75 -> V_56 ;
V_43 . V_59 = & V_37 -> V_58 . V_59 ;
V_43 . V_63 = 0 ;
V_43 . V_64 = 0 ;
V_43 . V_60 = - 1 ;
V_8 = F_47 ( V_2 , & V_10 , V_73 , V_75 , V_56 , V_60 , V_57 ,
type , V_11 , V_37 ) ;
if ( F_45 ( V_8 ) )
goto V_72;
if ( ! F_10 ( V_2 , V_8 , & V_10 , type , V_11 ) )
goto V_114;
V_91 = F_70 ( & V_8 -> V_13 ) ;
if ( V_91 > 576 )
V_91 = 576 ;
V_91 -= sizeof( struct V_74 ) + V_37 -> V_58 . V_59 . V_59 . V_65 ;
V_91 -= sizeof( struct V_49 ) ;
V_37 -> V_44 = V_73 -> V_32 - V_37 -> V_31 ;
if ( V_37 -> V_44 > V_91 )
V_37 -> V_44 = V_91 ;
V_37 -> V_45 = sizeof( struct V_49 ) ;
F_21 ( V_37 , & V_10 , & V_43 , & V_8 ) ;
V_114:
F_46 ( V_8 ) ;
V_72:
F_8 ( V_4 ) ;
V_105:
F_71 ( V_37 ) ;
V_16: ;
}
static void F_72 ( struct V_34 * V_35 , T_3 V_90 )
{
const struct V_74 * V_75 = ( const struct V_74 * ) V_35 -> V_40 ;
const struct V_115 * V_116 ;
int V_100 = V_75 -> V_100 ;
if ( ! F_73 ( V_35 , V_75 -> V_103 * 4 + 8 ) ) {
F_24 ( F_22 ( V_35 -> V_19 ) , V_117 ) ;
return;
}
F_74 ( V_35 , V_100 , V_90 ) ;
V_116 = F_75 ( V_118 [ V_100 ] ) ;
if ( V_116 && V_116 -> V_119 )
V_116 -> V_119 ( V_35 , V_90 ) ;
}
static bool F_76 ( int V_120 )
{
bool V_121 ;
F_63 () ;
V_121 = F_75 ( V_118 [ V_120 ] ) -> V_122 ;
F_68 () ;
return V_121 ;
}
static void F_77 ( struct V_34 * V_35 )
{
const struct V_74 * V_75 ;
struct V_49 * V_41 ;
struct V_2 * V_2 ;
T_3 V_90 = 0 ;
V_2 = F_22 ( F_78 ( V_35 ) -> V_19 ) ;
if ( ! F_73 ( V_35 , sizeof( struct V_74 ) ) )
goto V_123;
V_41 = F_28 ( V_35 ) ;
V_75 = ( const struct V_74 * ) V_35 -> V_40 ;
if ( V_75 -> V_103 < 5 )
goto V_123;
if ( V_41 -> type == V_17 ) {
switch ( V_41 -> V_11 & 15 ) {
case V_124 :
case V_125 :
case V_126 :
case V_127 :
break;
case V_18 :
switch ( V_2 -> V_3 . V_128 ) {
default:
F_79 (KERN_INFO pr_fmt(L_1),
&iph->daddr) ;
break;
case 2 :
goto V_16;
case 3 :
if ( ! F_76 ( V_75 -> V_100 ) )
goto V_16;
case 0 :
V_90 = F_80 ( V_41 -> V_112 . V_129 . V_130 ) ;
}
break;
case V_131 :
F_79 (KERN_INFO pr_fmt(L_2),
&iph->daddr) ;
break;
default:
break;
}
if ( V_41 -> V_11 > V_132 )
goto V_16;
} else if ( V_41 -> type == V_133 )
V_90 = F_81 ( V_41 -> V_112 . V_113 ) >> 24 ;
if ( ! V_2 -> V_3 . V_134 &&
F_52 ( V_2 , V_75 -> V_26 ) == V_135 ) {
F_82 ( L_3 ,
& F_39 ( V_35 ) -> V_56 ,
V_41 -> type , V_41 -> V_11 ,
& V_75 -> V_26 , V_35 -> V_19 -> V_136 ) ;
goto V_16;
}
F_72 ( V_35 , V_90 ) ;
V_16:
return;
V_123:
F_24 ( V_2 , V_117 ) ;
goto V_16;
}
static void F_83 ( struct V_34 * V_35 )
{
if ( V_35 -> V_32 < sizeof( struct V_74 ) ) {
F_24 ( F_22 ( V_35 -> V_19 ) , V_117 ) ;
return;
}
if ( ! F_73 ( V_35 , sizeof( struct V_74 ) ) )
return;
F_72 ( V_35 , F_28 ( V_35 ) -> V_112 . V_113 ) ;
}
static void F_84 ( struct V_34 * V_35 )
{
struct V_2 * V_2 ;
V_2 = F_22 ( F_78 ( V_35 ) -> V_19 ) ;
if ( ! V_2 -> V_3 . V_137 ) {
struct V_36 V_37 ;
V_37 . V_40 . V_41 = * F_28 ( V_35 ) ;
V_37 . V_40 . V_41 . type = V_138 ;
V_37 . V_35 = V_35 ;
V_37 . V_31 = 0 ;
V_37 . V_44 = V_35 -> V_32 ;
V_37 . V_45 = sizeof( struct V_49 ) ;
F_34 ( & V_37 , V_35 ) ;
}
}
static void F_85 ( struct V_34 * V_35 )
{
struct V_139 V_140 ;
struct V_36 V_37 ;
if ( V_35 -> V_32 < 4 )
goto V_123;
F_86 ( & V_140 ) ;
V_37 . V_40 . V_141 [ 1 ] = F_87 ( ( V_140 . V_142 % 86400 ) * V_143 +
V_140 . V_144 / V_145 ) ;
V_37 . V_40 . V_141 [ 2 ] = V_37 . V_40 . V_141 [ 1 ] ;
if ( F_88 ( V_35 , 0 , & V_37 . V_40 . V_141 [ 0 ] , 4 ) )
F_89 () ;
V_37 . V_40 . V_41 = * F_28 ( V_35 ) ;
V_37 . V_40 . V_41 . type = V_146 ;
V_37 . V_40 . V_41 . V_11 = 0 ;
V_37 . V_35 = V_35 ;
V_37 . V_31 = 0 ;
V_37 . V_44 = 0 ;
V_37 . V_45 = sizeof( struct V_49 ) + 12 ;
F_34 ( & V_37 , V_35 ) ;
V_16:
return;
V_123:
F_24 ( F_22 ( F_78 ( V_35 ) -> V_19 ) , V_117 ) ;
goto V_16;
}
static void F_90 ( struct V_34 * V_35 )
{
}
int F_91 ( struct V_34 * V_35 )
{
struct V_49 * V_41 ;
struct V_7 * V_8 = F_35 ( V_35 ) ;
struct V_2 * V_2 = F_22 ( V_8 -> V_13 . V_19 ) ;
if ( ! F_92 ( NULL , V_147 , V_35 ) ) {
struct V_148 * V_149 = F_93 ( V_35 ) ;
int V_150 ;
if ( ! ( V_149 && V_149 -> V_151 [ V_149 -> V_32 - 1 ] -> V_152 . V_20 &
V_153 ) )
goto V_154;
if ( ! F_73 ( V_35 , sizeof( * V_41 ) + sizeof( struct V_74 ) ) )
goto V_154;
V_150 = F_69 ( V_35 ) ;
F_94 ( V_35 , sizeof( * V_41 ) ) ;
if ( ! F_95 ( NULL , V_147 , V_35 ) )
goto V_154;
F_94 ( V_35 , V_150 ) ;
}
F_24 ( V_2 , V_155 ) ;
if ( F_96 ( V_35 ) )
goto V_156;
if ( ! F_97 ( V_35 , sizeof( * V_41 ) ) )
goto error;
V_41 = F_28 ( V_35 ) ;
F_98 ( V_2 , V_41 -> type ) ;
if ( V_41 -> type > V_15 )
goto error;
if ( V_8 -> V_95 & ( V_96 | V_97 ) ) {
if ( ( V_41 -> type == V_157 ||
V_41 -> type == V_158 ) &&
V_2 -> V_3 . V_159 ) {
goto error;
}
if ( V_41 -> type != V_157 &&
V_41 -> type != V_158 &&
V_41 -> type != V_160 &&
V_41 -> type != V_161 ) {
goto error;
}
}
V_39 [ V_41 -> type ] . F_99 ( V_35 ) ;
V_154:
F_100 ( V_35 ) ;
return 0 ;
V_156:
F_24 ( V_2 , V_162 ) ;
error:
F_24 ( V_2 , V_117 ) ;
goto V_154;
}
void F_101 ( struct V_34 * V_35 , T_3 V_90 )
{
struct V_74 * V_75 = (struct V_74 * ) V_35 -> V_40 ;
int V_31 = V_75 -> V_103 << 2 ;
struct V_49 * V_41 = (struct V_49 * ) ( V_35 -> V_40 + V_31 ) ;
int type = F_28 ( V_35 ) -> type ;
int V_11 = F_28 ( V_35 ) -> V_11 ;
struct V_2 * V_2 = F_22 ( V_35 -> V_19 ) ;
if ( V_41 -> type != V_138 ) {
F_102 ( V_35 , V_31 , V_90 ) ;
return;
}
if ( type == V_17 && V_11 == V_18 )
F_103 ( V_35 , V_2 , V_90 , 0 , 0 , V_71 , 0 ) ;
else if ( type == V_163 )
F_104 ( V_35 , V_2 , 0 , 0 , V_71 , 0 ) ;
}
static void T_5 F_105 ( struct V_2 * V_2 )
{
int V_164 ;
F_106 (i)
F_107 ( V_2 -> V_3 . F_1 [ V_164 ] ) ;
F_71 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_108 ( struct V_2 * V_2 )
{
int V_164 , V_79 ;
V_2 -> V_3 . F_1 =
F_109 ( V_165 * sizeof( struct V_1 * ) , V_166 ) ;
if ( V_2 -> V_3 . F_1 == NULL )
return - V_167 ;
F_106 (i) {
struct V_1 * V_4 ;
V_79 = F_110 ( & V_4 , V_168 ,
V_169 , V_71 , V_2 ) ;
if ( V_79 < 0 )
goto V_170;
V_2 -> V_3 . F_1 [ V_164 ] = V_4 ;
V_4 -> V_171 = 2 * F_111 ( 64 * 1024 ) ;
F_112 ( V_4 , V_172 ) ;
F_38 ( V_4 ) -> V_173 = V_174 ;
}
V_2 -> V_3 . V_137 = 0 ;
V_2 -> V_3 . V_159 = 1 ;
V_2 -> V_3 . V_134 = 1 ;
V_2 -> V_3 . V_27 = 1 * V_175 ;
V_2 -> V_3 . V_22 = 0x1818 ;
V_2 -> V_3 . V_108 = 0 ;
return 0 ;
V_170:
F_106 (i)
F_107 ( V_2 -> V_3 . F_1 [ V_164 ] ) ;
F_71 ( V_2 -> V_3 . F_1 ) ;
return V_79 ;
}
int T_7 F_113 ( void )
{
return F_114 ( & V_176 ) ;
}
