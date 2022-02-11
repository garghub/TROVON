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
if ( F_36 ( & V_37 -> V_57 . V_58 . V_58 , V_35 ) )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_55 = F_37 ( V_4 ) ;
V_37 -> V_40 . V_41 . V_51 = 0 ;
V_55 -> V_59 = F_38 ( V_35 ) -> V_59 ;
V_26 = V_43 . V_60 = F_38 ( V_35 ) -> V_56 ;
V_56 = F_39 ( V_35 ) ;
V_43 . V_58 = NULL ;
V_43 . V_61 = 0 ;
if ( V_37 -> V_57 . V_58 . V_58 . V_62 ) {
V_43 . V_58 = & V_37 -> V_57 . V_58 ;
if ( V_43 . V_58 -> V_58 . V_63 )
V_26 = V_37 -> V_57 . V_58 . V_58 . V_64 ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_26 = V_26 ;
V_10 . V_56 = V_56 ;
V_10 . V_65 = F_40 ( F_38 ( V_35 ) -> V_59 ) ;
V_10 . V_66 = V_67 ;
F_41 ( V_35 , F_42 ( & V_10 ) ) ;
V_8 = F_43 ( V_2 , & V_10 ) ;
if ( F_44 ( V_8 ) )
goto V_68;
if ( F_10 ( V_2 , V_8 , & V_10 , V_37 -> V_40 . V_41 . type ,
V_37 -> V_40 . V_41 . V_11 ) )
F_21 ( V_37 , & V_10 , & V_43 , & V_8 ) ;
F_45 ( V_8 ) ;
V_68:
F_8 ( V_4 ) ;
}
static struct V_7 * F_46 ( struct V_2 * V_2 ,
struct V_9 * V_10 ,
struct V_34 * V_69 ,
const struct V_70 * V_71 ,
T_2 V_56 , T_3 V_59 ,
int type , int V_11 ,
struct V_36 * V_72 )
{
struct V_7 * V_8 , * V_73 ;
struct V_9 V_74 ;
int V_75 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_26 = ( V_72 -> V_57 . V_58 . V_58 . V_63 ?
V_72 -> V_57 . V_58 . V_58 . V_64 : V_71 -> V_56 ) ;
V_10 -> V_56 = V_56 ;
V_10 -> V_65 = F_40 ( V_59 ) ;
V_10 -> V_66 = V_67 ;
V_10 -> V_76 = type ;
V_10 -> V_77 = V_11 ;
F_41 ( V_69 , F_42 ( V_10 ) ) ;
V_8 = F_47 ( V_2 , V_10 ) ;
if ( F_44 ( V_8 ) )
return V_8 ;
V_73 = V_8 ;
V_8 = (struct V_7 * ) F_48 ( V_2 , & V_8 -> V_13 ,
F_42 ( V_10 ) , NULL , 0 ) ;
if ( ! F_44 ( V_8 ) ) {
if ( V_8 != V_73 )
return V_8 ;
} else if ( F_49 ( V_8 ) == - V_78 ) {
V_8 = NULL ;
} else
return V_8 ;
V_75 = F_50 ( V_69 , F_42 ( & V_74 ) , V_79 ) ;
if ( V_75 )
goto V_80;
if ( F_51 ( V_2 , V_74 . V_56 ) == V_81 ) {
V_73 = F_47 ( V_2 , & V_74 ) ;
if ( F_44 ( V_73 ) )
V_75 = F_49 ( V_73 ) ;
} else {
struct V_9 V_82 = {} ;
unsigned long V_83 ;
V_82 . V_26 = V_74 . V_56 ;
V_73 = F_43 ( V_2 , & V_82 ) ;
if ( F_44 ( V_73 ) ) {
V_75 = F_49 ( V_73 ) ;
goto V_80;
}
V_83 = V_69 -> V_84 ;
V_75 = F_52 ( V_69 , V_74 . V_26 , V_74 . V_56 ,
F_40 ( V_59 ) , V_73 -> V_13 . V_19 ) ;
F_53 ( & V_73 -> V_13 ) ;
V_73 = F_35 ( V_69 ) ;
V_69 -> V_84 = V_83 ;
}
if ( V_75 )
goto V_80;
V_73 = (struct V_7 * ) F_48 ( V_2 , & V_73 -> V_13 ,
F_42 ( & V_74 ) , NULL ,
V_85 ) ;
if ( ! F_44 ( V_73 ) ) {
F_53 ( & V_8 -> V_13 ) ;
memcpy ( V_10 , & V_74 , sizeof( * V_10 ) ) ;
V_8 = V_73 ;
} else if ( F_49 ( V_73 ) == - V_78 ) {
if ( V_8 )
F_53 ( & V_8 -> V_13 ) ;
return V_73 ;
} else {
V_75 = F_49 ( V_73 ) ;
goto V_80;
}
return V_8 ;
V_80:
if ( V_8 )
return V_8 ;
return F_54 ( V_75 ) ;
}
void F_55 ( struct V_34 * V_69 , int type , int V_11 , T_2 V_86 )
{
struct V_70 * V_71 ;
int V_87 ;
struct V_36 * V_37 ;
struct V_7 * V_8 = F_35 ( V_69 ) ;
struct V_42 V_43 ;
struct V_9 V_10 ;
T_2 V_56 ;
T_3 V_59 ;
struct V_2 * V_2 ;
struct V_1 * V_4 ;
if ( ! V_8 )
goto V_16;
V_2 = F_22 ( V_8 -> V_13 . V_19 ) ;
V_71 = F_38 ( V_69 ) ;
if ( ( T_3 * ) V_71 < V_69 -> V_88 ||
( F_56 ( V_69 ) + sizeof( * V_71 ) ) >
F_57 ( V_69 ) )
goto V_16;
if ( V_69 -> V_89 != V_90 )
goto V_16;
if ( V_8 -> V_91 & ( V_92 | V_93 ) )
goto V_16;
if ( V_71 -> V_94 & F_58 ( V_95 ) )
goto V_16;
if ( V_39 [ type ] . error ) {
if ( V_71 -> V_96 == V_67 ) {
T_3 V_97 , * V_98 ;
V_98 = F_59 ( V_69 ,
F_56 ( V_69 ) +
( V_71 -> V_99 << 2 ) +
F_60 ( struct V_49 ,
type ) -
V_69 -> V_40 ,
sizeof( V_97 ) ,
& V_97 ) ;
if ( V_98 == NULL )
goto V_16;
if ( * V_98 > V_15 ||
V_39 [ * V_98 ] . error )
goto V_16;
}
}
V_37 = F_61 ( sizeof( * V_37 ) , V_100 ) ;
if ( ! V_37 )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
goto V_101;
V_56 = V_71 -> V_26 ;
if ( ! ( V_8 -> V_91 & V_102 ) ) {
struct V_103 * V_19 = NULL ;
F_62 () ;
if ( F_63 ( V_8 ) &&
V_2 -> V_3 . V_104 )
V_19 = F_64 ( V_2 , F_65 ( V_69 ) ) ;
if ( V_19 )
V_56 = F_66 ( V_19 , 0 , V_105 ) ;
else
V_56 = 0 ;
F_67 () ;
}
V_59 = V_39 [ type ] . error ? ( ( V_71 -> V_59 & V_106 ) |
V_107 ) :
V_71 -> V_59 ;
if ( F_36 ( & V_37 -> V_57 . V_58 . V_58 , V_69 ) )
goto V_68;
V_37 -> V_40 . V_41 . type = type ;
V_37 -> V_40 . V_41 . V_11 = V_11 ;
V_37 -> V_40 . V_41 . V_108 . V_109 = V_86 ;
V_37 -> V_40 . V_41 . V_51 = 0 ;
V_37 -> V_35 = V_69 ;
V_37 -> V_31 = F_68 ( V_69 ) ;
F_37 ( V_4 ) -> V_59 = V_59 ;
V_43 . V_60 = V_71 -> V_56 ;
V_43 . V_58 = & V_37 -> V_57 . V_58 ;
V_43 . V_61 = 0 ;
V_8 = F_46 ( V_2 , & V_10 , V_69 , V_71 , V_56 , V_59 ,
type , V_11 , V_37 ) ;
if ( F_44 ( V_8 ) )
goto V_68;
if ( ! F_10 ( V_2 , V_8 , & V_10 , type , V_11 ) )
goto V_110;
V_87 = F_69 ( & V_8 -> V_13 ) ;
if ( V_87 > 576 )
V_87 = 576 ;
V_87 -= sizeof( struct V_70 ) + V_37 -> V_57 . V_58 . V_58 . V_62 ;
V_87 -= sizeof( struct V_49 ) ;
V_37 -> V_44 = V_69 -> V_32 - V_37 -> V_31 ;
if ( V_37 -> V_44 > V_87 )
V_37 -> V_44 = V_87 ;
V_37 -> V_45 = sizeof( struct V_49 ) ;
F_21 ( V_37 , & V_10 , & V_43 , & V_8 ) ;
V_110:
F_45 ( V_8 ) ;
V_68:
F_8 ( V_4 ) ;
V_101:
F_70 ( V_37 ) ;
V_16: ;
}
static void F_71 ( struct V_34 * V_35 , T_4 V_86 )
{
const struct V_70 * V_71 = ( const struct V_70 * ) V_35 -> V_40 ;
const struct V_111 * V_112 ;
int V_96 = V_71 -> V_96 ;
if ( ! F_72 ( V_35 , V_71 -> V_99 * 4 + 8 ) )
return;
F_73 ( V_35 , V_96 , V_86 ) ;
F_62 () ;
V_112 = F_74 ( V_113 [ V_96 ] ) ;
if ( V_112 && V_112 -> V_114 )
V_112 -> V_114 ( V_35 , V_86 ) ;
F_67 () ;
}
static void F_75 ( struct V_34 * V_35 )
{
const struct V_70 * V_71 ;
struct V_49 * V_41 ;
struct V_2 * V_2 ;
T_4 V_86 = 0 ;
V_2 = F_22 ( F_76 ( V_35 ) -> V_19 ) ;
if ( ! F_72 ( V_35 , sizeof( struct V_70 ) ) )
goto V_115;
V_41 = F_28 ( V_35 ) ;
V_71 = ( const struct V_70 * ) V_35 -> V_40 ;
if ( V_71 -> V_99 < 5 )
goto V_115;
if ( V_41 -> type == V_17 ) {
switch ( V_41 -> V_11 & 15 ) {
case V_116 :
case V_117 :
case V_118 :
case V_119 :
break;
case V_18 :
if ( V_120 . V_121 ) {
F_77 (KERN_INFO pr_fmt(L_1),
&iph->daddr) ;
} else {
V_86 = F_78 ( V_41 -> V_108 . V_122 . V_123 ) ;
if ( ! V_86 )
goto V_16;
}
break;
case V_124 :
F_77 (KERN_INFO pr_fmt(L_2),
&iph->daddr) ;
break;
default:
break;
}
if ( V_41 -> V_11 > V_125 )
goto V_16;
} else if ( V_41 -> type == V_126 )
V_86 = F_79 ( V_41 -> V_108 . V_109 ) >> 24 ;
if ( ! V_2 -> V_3 . V_127 &&
F_51 ( V_2 , V_71 -> V_26 ) == V_128 ) {
F_80 ( L_3 ,
& F_38 ( V_35 ) -> V_56 ,
V_41 -> type , V_41 -> V_11 ,
& V_71 -> V_26 , V_35 -> V_19 -> V_129 ) ;
goto V_16;
}
F_71 ( V_35 , V_86 ) ;
V_16:
return;
V_115:
F_24 ( V_2 , V_130 ) ;
goto V_16;
}
static void F_81 ( struct V_34 * V_35 )
{
if ( V_35 -> V_32 < sizeof( struct V_70 ) ) {
F_24 ( F_22 ( V_35 -> V_19 ) , V_130 ) ;
return;
}
if ( ! F_72 ( V_35 , sizeof( struct V_70 ) ) )
return;
F_71 ( V_35 , F_28 ( V_35 ) -> V_108 . V_109 ) ;
}
static void F_82 ( struct V_34 * V_35 )
{
struct V_2 * V_2 ;
V_2 = F_22 ( F_76 ( V_35 ) -> V_19 ) ;
if ( ! V_2 -> V_3 . V_131 ) {
struct V_36 V_37 ;
V_37 . V_40 . V_41 = * F_28 ( V_35 ) ;
V_37 . V_40 . V_41 . type = V_132 ;
V_37 . V_35 = V_35 ;
V_37 . V_31 = 0 ;
V_37 . V_44 = V_35 -> V_32 ;
V_37 . V_45 = sizeof( struct V_49 ) ;
F_34 ( & V_37 , V_35 ) ;
}
}
static void F_83 ( struct V_34 * V_35 )
{
struct V_133 V_134 ;
struct V_36 V_37 ;
if ( V_35 -> V_32 < 4 )
goto V_115;
F_84 ( & V_134 ) ;
V_37 . V_40 . V_135 [ 1 ] = F_85 ( ( V_134 . V_136 % 86400 ) * V_137 +
V_134 . V_138 / V_139 ) ;
V_37 . V_40 . V_135 [ 2 ] = V_37 . V_40 . V_135 [ 1 ] ;
if ( F_86 ( V_35 , 0 , & V_37 . V_40 . V_135 [ 0 ] , 4 ) )
F_87 () ;
V_37 . V_40 . V_41 = * F_28 ( V_35 ) ;
V_37 . V_40 . V_41 . type = V_140 ;
V_37 . V_40 . V_41 . V_11 = 0 ;
V_37 . V_35 = V_35 ;
V_37 . V_31 = 0 ;
V_37 . V_44 = 0 ;
V_37 . V_45 = sizeof( struct V_49 ) + 12 ;
F_34 ( & V_37 , V_35 ) ;
V_16:
return;
V_115:
F_24 ( F_22 ( F_76 ( V_35 ) -> V_19 ) , V_130 ) ;
goto V_16;
}
static void F_88 ( struct V_34 * V_35 )
{
}
int F_89 ( struct V_34 * V_35 )
{
struct V_49 * V_41 ;
struct V_7 * V_8 = F_35 ( V_35 ) ;
struct V_2 * V_2 = F_22 ( V_8 -> V_13 . V_19 ) ;
if ( ! F_90 ( NULL , V_141 , V_35 ) ) {
struct V_142 * V_143 = F_91 ( V_35 ) ;
int V_144 ;
if ( ! ( V_143 && V_143 -> V_145 [ V_143 -> V_32 - 1 ] -> V_146 . V_20 &
V_147 ) )
goto V_148;
if ( ! F_72 ( V_35 , sizeof( * V_41 ) + sizeof( struct V_70 ) ) )
goto V_148;
V_144 = F_68 ( V_35 ) ;
F_92 ( V_35 , sizeof( * V_41 ) ) ;
if ( ! F_93 ( NULL , V_141 , V_35 ) )
goto V_148;
F_92 ( V_35 , V_144 ) ;
}
F_24 ( V_2 , V_149 ) ;
switch ( V_35 -> V_52 ) {
case V_150 :
if ( ! F_32 ( V_35 -> V_38 ) )
break;
case V_53 :
V_35 -> V_38 = 0 ;
if ( F_94 ( V_35 ) )
goto V_151;
}
if ( ! F_95 ( V_35 , sizeof( * V_41 ) ) )
goto error;
V_41 = F_28 ( V_35 ) ;
F_96 ( V_2 , V_41 -> type ) ;
if ( V_41 -> type > V_15 )
goto error;
if ( V_8 -> V_91 & ( V_92 | V_93 ) ) {
if ( ( V_41 -> type == V_152 ||
V_41 -> type == V_153 ) &&
V_2 -> V_3 . V_154 ) {
goto error;
}
if ( V_41 -> type != V_152 &&
V_41 -> type != V_153 &&
V_41 -> type != V_155 &&
V_41 -> type != V_156 ) {
goto error;
}
}
V_39 [ V_41 -> type ] . F_97 ( V_35 ) ;
V_148:
F_98 ( V_35 ) ;
return 0 ;
V_151:
F_24 ( V_2 , V_157 ) ;
error:
F_24 ( V_2 , V_130 ) ;
goto V_148;
}
void F_99 ( struct V_34 * V_35 , T_4 V_86 )
{
struct V_70 * V_71 = (struct V_70 * ) V_35 -> V_40 ;
int V_31 = V_71 -> V_99 << 2 ;
struct V_49 * V_41 = (struct V_49 * ) ( V_35 -> V_40 + V_31 ) ;
int type = F_28 ( V_35 ) -> type ;
int V_11 = F_28 ( V_35 ) -> V_11 ;
struct V_2 * V_2 = F_22 ( V_35 -> V_19 ) ;
if ( V_41 -> type != V_132 ) {
F_100 ( V_35 , V_31 , V_86 ) ;
return;
}
if ( type == V_17 && V_11 == V_18 )
F_101 ( V_35 , V_2 , V_86 , 0 , 0 , V_67 , 0 ) ;
else if ( type == V_158 )
F_102 ( V_35 , V_2 , 0 , 0 , V_67 , 0 ) ;
}
static void T_5 F_103 ( struct V_2 * V_2 )
{
int V_159 ;
F_104 (i)
F_105 ( V_2 -> V_3 . F_1 [ V_159 ] ) ;
F_70 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_106 ( struct V_2 * V_2 )
{
int V_159 , V_75 ;
V_2 -> V_3 . F_1 =
F_107 ( V_160 * sizeof( struct V_1 * ) , V_161 ) ;
if ( V_2 -> V_3 . F_1 == NULL )
return - V_162 ;
F_104 (i) {
struct V_1 * V_4 ;
V_75 = F_108 ( & V_4 , V_163 ,
V_164 , V_67 , V_2 ) ;
if ( V_75 < 0 )
goto V_165;
V_2 -> V_3 . F_1 [ V_159 ] = V_4 ;
V_4 -> V_166 = 2 * F_109 ( 64 * 1024 ) ;
F_110 ( V_4 , V_167 ) ;
F_37 ( V_4 ) -> V_168 = V_169 ;
}
V_2 -> V_3 . V_131 = 0 ;
V_2 -> V_3 . V_154 = 1 ;
V_2 -> V_3 . V_127 = 1 ;
V_2 -> V_3 . V_27 = 1 * V_170 ;
V_2 -> V_3 . V_22 = 0x1818 ;
V_2 -> V_3 . V_104 = 0 ;
return 0 ;
V_165:
F_104 (i)
F_105 ( V_2 -> V_3 . F_1 [ V_159 ] ) ;
F_70 ( V_2 -> V_3 . F_1 ) ;
return V_75 ;
}
int T_7 F_111 ( void )
{
return F_112 ( & V_171 ) ;
}
