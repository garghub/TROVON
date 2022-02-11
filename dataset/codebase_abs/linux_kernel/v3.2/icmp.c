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
if ( ! V_8 -> V_23 )
F_11 ( V_8 , V_10 -> V_24 , 1 ) ;
V_14 = F_12 ( V_8 -> V_23 ,
V_2 -> V_3 . V_25 ) ;
}
V_16:
return V_14 ;
}
void F_13 ( struct V_2 * V_2 , unsigned char type )
{
F_14 ( V_2 , type ) ;
F_15 ( V_2 , V_26 ) ;
}
static int F_16 ( void * V_27 , char * V_28 , int V_29 , int V_30 , int V_31 ,
struct V_32 * V_33 )
{
struct V_34 * V_35 = (struct V_34 * ) V_27 ;
T_1 V_36 ;
V_36 = F_17 ( V_35 -> V_33 ,
V_35 -> V_29 + V_29 ,
V_28 , V_30 , 0 ) ;
V_33 -> V_36 = F_18 ( V_33 -> V_36 , V_36 , V_31 ) ;
if ( V_37 [ V_35 -> V_38 . V_39 . type ] . error )
F_19 ( V_33 , V_35 -> V_33 ) ;
return 0 ;
}
static void F_20 ( struct V_34 * V_35 ,
struct V_9 * V_10 ,
struct V_40 * V_41 , struct V_7 * * V_8 )
{
struct V_1 * V_4 ;
struct V_32 * V_33 ;
V_4 = F_1 ( F_21 ( ( * V_8 ) -> V_13 . V_19 ) ) ;
if ( F_22 ( V_4 , V_10 , F_16 , V_35 ,
V_35 -> V_42 + V_35 -> V_43 ,
V_35 -> V_43 ,
V_41 , V_8 , V_44 ) < 0 ) {
F_23 ( F_24 ( V_4 ) , V_45 ) ;
F_25 ( V_4 ) ;
} else if ( ( V_33 = F_26 ( & V_4 -> V_46 ) ) != NULL ) {
struct V_47 * V_39 = F_27 ( V_33 ) ;
T_1 V_36 = 0 ;
struct V_32 * V_48 ;
F_28 (&sk->sk_write_queue, skb1) {
V_36 = F_29 ( V_36 , V_48 -> V_36 ) ;
}
V_36 = F_30 ( ( void * ) & V_35 -> V_38 ,
( char * ) V_39 ,
V_35 -> V_43 , V_36 ) ;
V_39 -> V_49 = F_31 ( V_36 ) ;
V_33 -> V_50 = V_51 ;
F_32 ( V_4 , V_10 ) ;
}
}
static void F_33 ( struct V_34 * V_35 , struct V_32 * V_33 )
{
struct V_40 V_41 ;
struct V_7 * V_8 = F_34 ( V_33 ) ;
struct V_2 * V_2 = F_21 ( V_8 -> V_13 . V_19 ) ;
struct V_9 V_10 ;
struct V_1 * V_4 ;
struct V_52 * V_53 ;
T_2 V_24 ;
if ( F_35 ( & V_35 -> V_54 . V_55 . V_55 , V_33 ) )
return;
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_53 = F_36 ( V_4 ) ;
V_35 -> V_38 . V_39 . V_49 = 0 ;
V_53 -> V_56 = F_37 ( V_33 ) -> V_56 ;
V_24 = V_41 . V_57 = F_37 ( V_33 ) -> V_58 ;
V_41 . V_55 = NULL ;
V_41 . V_59 = 0 ;
if ( V_35 -> V_54 . V_55 . V_55 . V_60 ) {
V_41 . V_55 = & V_35 -> V_54 . V_55 ;
if ( V_41 . V_55 -> V_55 . V_61 )
V_24 = V_35 -> V_54 . V_55 . V_55 . V_62 ;
}
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
V_10 . V_24 = V_24 ;
V_10 . V_58 = V_8 -> V_63 ;
V_10 . V_64 = F_38 ( F_37 ( V_33 ) -> V_56 ) ;
V_10 . V_65 = V_66 ;
F_39 ( V_33 , F_40 ( & V_10 ) ) ;
V_8 = F_41 ( V_2 , & V_10 ) ;
if ( F_42 ( V_8 ) )
goto V_67;
if ( F_10 ( V_2 , V_8 , & V_10 , V_35 -> V_38 . V_39 . type ,
V_35 -> V_38 . V_39 . V_11 ) )
F_20 ( V_35 , & V_10 , & V_41 , & V_8 ) ;
F_43 ( V_8 ) ;
V_67:
F_8 ( V_4 ) ;
}
static struct V_7 * F_44 ( struct V_2 * V_2 ,
struct V_9 * V_10 ,
struct V_32 * V_68 ,
const struct V_69 * V_70 ,
T_2 V_58 , T_3 V_56 ,
int type , int V_11 ,
struct V_34 * V_71 )
{
struct V_7 * V_8 , * V_72 ;
struct V_9 V_73 ;
int V_74 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_24 = ( V_71 -> V_54 . V_55 . V_55 . V_61 ?
V_71 -> V_54 . V_55 . V_55 . V_62 : V_70 -> V_58 ) ;
V_10 -> V_58 = V_58 ;
V_10 -> V_64 = F_38 ( V_56 ) ;
V_10 -> V_65 = V_66 ;
V_10 -> V_75 = type ;
V_10 -> V_76 = V_11 ;
F_39 ( V_68 , F_40 ( V_10 ) ) ;
V_8 = F_45 ( V_2 , V_10 ) ;
if ( F_42 ( V_8 ) )
return V_8 ;
V_72 = V_8 ;
V_8 = (struct V_7 * ) F_46 ( V_2 , & V_8 -> V_13 ,
F_40 ( V_10 ) , NULL , 0 ) ;
if ( ! F_42 ( V_8 ) ) {
if ( V_8 != V_72 )
return V_8 ;
} else if ( F_47 ( V_8 ) == - V_77 ) {
V_8 = NULL ;
} else
return V_8 ;
V_74 = F_48 ( V_68 , F_40 ( & V_73 ) , V_78 ) ;
if ( V_74 )
goto V_79;
if ( F_49 ( V_2 , V_73 . V_58 ) == V_80 ) {
V_72 = F_45 ( V_2 , & V_73 ) ;
if ( F_42 ( V_72 ) )
V_74 = F_47 ( V_72 ) ;
} else {
struct V_9 V_81 = {} ;
unsigned long V_82 ;
V_81 . V_24 = V_73 . V_58 ;
V_72 = F_41 ( V_2 , & V_81 ) ;
if ( F_42 ( V_72 ) ) {
V_74 = F_47 ( V_72 ) ;
goto V_79;
}
V_82 = V_68 -> V_83 ;
V_74 = F_50 ( V_68 , V_73 . V_24 , V_73 . V_58 ,
F_38 ( V_56 ) , V_72 -> V_13 . V_19 ) ;
F_51 ( & V_72 -> V_13 ) ;
V_72 = F_34 ( V_68 ) ;
V_68 -> V_83 = V_82 ;
}
if ( V_74 )
goto V_79;
V_72 = (struct V_7 * ) F_46 ( V_2 , & V_72 -> V_13 ,
F_40 ( & V_73 ) , NULL ,
V_84 ) ;
if ( ! F_42 ( V_72 ) ) {
F_51 ( & V_8 -> V_13 ) ;
memcpy ( V_10 , & V_73 , sizeof( * V_10 ) ) ;
V_8 = V_72 ;
} else if ( F_47 ( V_72 ) == - V_77 ) {
if ( V_8 )
F_51 ( & V_8 -> V_13 ) ;
return V_72 ;
} else {
V_74 = F_47 ( V_72 ) ;
goto V_79;
}
return V_8 ;
V_79:
if ( V_8 )
return V_8 ;
return F_52 ( V_74 ) ;
}
void F_53 ( struct V_32 * V_68 , int type , int V_11 , T_2 V_85 )
{
struct V_69 * V_70 ;
int V_86 ;
struct V_34 V_35 ;
struct V_7 * V_8 = F_34 ( V_68 ) ;
struct V_40 V_41 ;
struct V_9 V_10 ;
T_2 V_58 ;
T_3 V_56 ;
struct V_2 * V_2 ;
struct V_1 * V_4 ;
if ( ! V_8 )
goto V_16;
V_2 = F_21 ( V_8 -> V_13 . V_19 ) ;
V_70 = F_37 ( V_68 ) ;
if ( ( T_3 * ) V_70 < V_68 -> V_87 ||
( V_68 -> V_88 + sizeof( * V_70 ) ) > V_68 -> V_89 )
goto V_16;
if ( V_68 -> V_90 != V_91 )
goto V_16;
if ( V_8 -> V_92 & ( V_93 | V_94 ) )
goto V_16;
if ( V_70 -> V_95 & F_54 ( V_96 ) )
goto V_16;
if ( V_37 [ type ] . error ) {
if ( V_70 -> V_97 == V_66 ) {
T_3 V_98 , * V_99 ;
V_99 = F_55 ( V_68 ,
F_56 ( V_68 ) +
( V_70 -> V_100 << 2 ) +
F_57 ( struct V_47 ,
type ) -
V_68 -> V_38 ,
sizeof( V_98 ) ,
& V_98 ) ;
if ( V_99 == NULL )
goto V_16;
if ( * V_99 > V_15 ||
V_37 [ * V_99 ] . error )
goto V_16;
}
}
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_58 = V_70 -> V_24 ;
if ( ! ( V_8 -> V_92 & V_101 ) ) {
struct V_102 * V_19 = NULL ;
F_58 () ;
if ( F_59 ( V_8 ) &&
V_2 -> V_3 . V_103 )
V_19 = F_60 ( V_2 , V_8 -> V_104 ) ;
if ( V_19 )
V_58 = F_61 ( V_19 , 0 , V_105 ) ;
else
V_58 = 0 ;
F_62 () ;
}
V_56 = V_37 [ type ] . error ? ( ( V_70 -> V_56 & V_106 ) |
V_107 ) :
V_70 -> V_56 ;
if ( F_35 ( & V_35 . V_54 . V_55 . V_55 , V_68 ) )
goto V_67;
V_35 . V_38 . V_39 . type = type ;
V_35 . V_38 . V_39 . V_11 = V_11 ;
V_35 . V_38 . V_39 . V_108 . V_109 = V_85 ;
V_35 . V_38 . V_39 . V_49 = 0 ;
V_35 . V_33 = V_68 ;
V_35 . V_29 = F_63 ( V_68 ) ;
F_36 ( V_4 ) -> V_56 = V_56 ;
V_41 . V_57 = V_70 -> V_58 ;
V_41 . V_55 = & V_35 . V_54 . V_55 ;
V_41 . V_59 = 0 ;
V_8 = F_44 ( V_2 , & V_10 , V_68 , V_70 , V_58 , V_56 ,
type , V_11 , & V_35 ) ;
if ( F_42 ( V_8 ) )
goto V_67;
if ( ! F_10 ( V_2 , V_8 , & V_10 , type , V_11 ) )
goto V_110;
V_86 = F_64 ( & V_8 -> V_13 ) ;
if ( V_86 > 576 )
V_86 = 576 ;
V_86 -= sizeof( struct V_69 ) + V_35 . V_54 . V_55 . V_55 . V_60 ;
V_86 -= sizeof( struct V_47 ) ;
V_35 . V_42 = V_68 -> V_30 - V_35 . V_29 ;
if ( V_35 . V_42 > V_86 )
V_35 . V_42 = V_86 ;
V_35 . V_43 = sizeof( struct V_47 ) ;
F_20 ( & V_35 , & V_10 , & V_41 , & V_8 ) ;
V_110:
F_43 ( V_8 ) ;
V_67:
F_8 ( V_4 ) ;
V_16: ;
}
static void F_65 ( struct V_32 * V_33 )
{
const struct V_69 * V_70 ;
struct V_47 * V_39 ;
int V_111 , V_97 ;
const struct V_112 * V_113 ;
T_4 V_85 = 0 ;
struct V_2 * V_2 ;
V_2 = F_21 ( F_66 ( V_33 ) -> V_19 ) ;
if ( ! F_67 ( V_33 , sizeof( struct V_69 ) ) )
goto V_114;
V_39 = F_27 ( V_33 ) ;
V_70 = ( const struct V_69 * ) V_33 -> V_38 ;
if ( V_70 -> V_100 < 5 )
goto V_114;
if ( V_39 -> type == V_17 ) {
switch ( V_39 -> V_11 & 15 ) {
case V_115 :
case V_116 :
case V_117 :
case V_118 :
break;
case V_18 :
if ( V_119 . V_120 ) {
F_68 ( V_121 L_1 ,
& V_70 -> V_24 ) ;
} else {
V_85 = F_69 ( V_2 , V_70 ,
F_70 ( V_39 -> V_108 . V_122 . V_123 ) ,
V_33 -> V_19 ) ;
if ( ! V_85 )
goto V_16;
}
break;
case V_124 :
F_68 ( V_121 L_2 ,
& V_70 -> V_24 ) ;
break;
default:
break;
}
if ( V_39 -> V_11 > V_125 )
goto V_16;
} else if ( V_39 -> type == V_126 )
V_85 = F_71 ( V_39 -> V_108 . V_109 ) >> 24 ;
if ( ! V_2 -> V_3 . V_127 &&
F_49 ( V_2 , V_70 -> V_24 ) == V_128 ) {
if ( F_72 () )
F_73 ( V_129 L_3
L_4
L_5 ,
& F_37 ( V_33 ) -> V_58 ,
V_39 -> type , V_39 -> V_11 ,
& V_70 -> V_24 ,
V_33 -> V_19 -> V_130 ) ;
goto V_16;
}
if ( ! F_67 ( V_33 , V_70 -> V_100 * 4 + 8 ) )
goto V_16;
V_70 = ( const struct V_69 * ) V_33 -> V_38 ;
V_97 = V_70 -> V_97 ;
F_74 ( V_33 , V_97 , V_85 ) ;
V_111 = V_97 & ( V_131 - 1 ) ;
F_58 () ;
V_113 = F_75 ( V_132 [ V_111 ] ) ;
if ( V_113 && V_113 -> V_133 )
V_113 -> V_133 ( V_33 , V_85 ) ;
F_62 () ;
V_16:
return;
V_114:
F_23 ( V_2 , V_134 ) ;
goto V_16;
}
static void F_76 ( struct V_32 * V_33 )
{
const struct V_69 * V_70 ;
if ( V_33 -> V_30 < sizeof( struct V_69 ) )
goto V_114;
if ( ! F_67 ( V_33 , sizeof( struct V_69 ) ) )
goto V_16;
V_70 = ( const struct V_69 * ) V_33 -> V_38 ;
switch ( F_27 ( V_33 ) -> V_11 & 7 ) {
case V_135 :
case V_136 :
case V_137 :
case V_138 :
F_77 ( F_37 ( V_33 ) -> V_58 , V_70 -> V_24 ,
F_27 ( V_33 ) -> V_108 . V_109 ,
V_70 -> V_58 , V_33 -> V_19 ) ;
break;
}
if ( V_70 -> V_97 == V_66 &&
V_70 -> V_100 >= 5 &&
F_67 ( V_33 , ( V_70 -> V_100 << 2 ) + 8 ) ) {
F_78 ( V_33 , F_27 ( V_33 ) -> V_108 . V_109 ) ;
}
V_16:
return;
V_114:
F_23 ( F_21 ( V_33 -> V_19 ) , V_134 ) ;
goto V_16;
}
static void F_79 ( struct V_32 * V_33 )
{
struct V_2 * V_2 ;
V_2 = F_21 ( F_66 ( V_33 ) -> V_19 ) ;
if ( ! V_2 -> V_3 . V_139 ) {
struct V_34 V_35 ;
V_35 . V_38 . V_39 = * F_27 ( V_33 ) ;
V_35 . V_38 . V_39 . type = V_140 ;
V_35 . V_33 = V_33 ;
V_35 . V_29 = 0 ;
V_35 . V_42 = V_33 -> V_30 ;
V_35 . V_43 = sizeof( struct V_47 ) ;
F_33 ( & V_35 , V_33 ) ;
}
}
static void F_80 ( struct V_32 * V_33 )
{
struct V_141 V_142 ;
struct V_34 V_35 ;
if ( V_33 -> V_30 < 4 )
goto V_114;
F_81 ( & V_142 ) ;
V_35 . V_38 . V_143 [ 1 ] = F_82 ( ( V_142 . V_144 % 86400 ) * V_145 +
V_142 . V_146 / V_147 ) ;
V_35 . V_38 . V_143 [ 2 ] = V_35 . V_38 . V_143 [ 1 ] ;
if ( F_83 ( V_33 , 0 , & V_35 . V_38 . V_143 [ 0 ] , 4 ) )
F_84 () ;
V_35 . V_38 . V_39 = * F_27 ( V_33 ) ;
V_35 . V_38 . V_39 . type = V_148 ;
V_35 . V_38 . V_39 . V_11 = 0 ;
V_35 . V_33 = V_33 ;
V_35 . V_29 = 0 ;
V_35 . V_42 = 0 ;
V_35 . V_43 = sizeof( struct V_47 ) + 12 ;
F_33 ( & V_35 , V_33 ) ;
V_16:
return;
V_114:
F_23 ( F_21 ( F_66 ( V_33 ) -> V_19 ) , V_134 ) ;
goto V_16;
}
static void F_85 ( struct V_32 * V_33 )
{
#if 0
if (net_ratelimit())
printk(KERN_DEBUG "a guy asks for address mask. Who is it?\n");
#endif
}
static void F_86 ( struct V_32 * V_33 )
{
struct V_7 * V_8 = F_34 ( V_33 ) ;
struct V_102 * V_19 = V_33 -> V_19 ;
struct V_149 * V_150 ;
struct V_151 * V_152 ;
if ( V_33 -> V_30 < 4 || ! ( V_8 -> V_92 & V_153 ) )
return;
V_150 = F_87 ( V_19 ) ;
if ( ! V_150 )
return;
if ( V_150 -> V_154 &&
F_88 ( V_150 ) &&
F_89 ( V_150 ) ) {
T_2 V_155 , * V_156 ;
V_156 = F_55 ( V_33 , 0 , sizeof( V_155 ) , & V_155 ) ;
F_90 ( V_156 == NULL ) ;
for ( V_152 = V_150 -> V_154 ; V_152 ; V_152 = V_152 -> V_157 ) {
if ( * V_156 == V_152 -> V_158 &&
F_91 ( F_37 ( V_33 ) -> V_58 , V_152 ) )
break;
}
if ( ! V_152 && F_72 () ) {
F_73 ( V_121 L_6 ,
V_156 , V_19 -> V_130 , & F_37 ( V_33 ) -> V_58 ) ;
}
}
}
static void F_92 ( struct V_32 * V_33 )
{
}
int F_93 ( struct V_32 * V_33 )
{
struct V_47 * V_39 ;
struct V_7 * V_8 = F_34 ( V_33 ) ;
struct V_2 * V_2 = F_21 ( V_8 -> V_13 . V_19 ) ;
if ( ! F_94 ( NULL , V_159 , V_33 ) ) {
struct V_160 * V_161 = F_95 ( V_33 ) ;
int V_162 ;
if ( ! ( V_161 && V_161 -> V_163 [ V_161 -> V_30 - 1 ] -> V_164 . V_20 &
V_165 ) )
goto V_166;
if ( ! F_67 ( V_33 , sizeof( * V_39 ) + sizeof( struct V_69 ) ) )
goto V_166;
V_162 = F_63 ( V_33 ) ;
F_96 ( V_33 , sizeof( * V_39 ) ) ;
if ( ! F_97 ( NULL , V_159 , V_33 ) )
goto V_166;
F_96 ( V_33 , V_162 ) ;
}
F_23 ( V_2 , V_167 ) ;
switch ( V_33 -> V_50 ) {
case V_168 :
if ( ! F_31 ( V_33 -> V_36 ) )
break;
case V_51 :
V_33 -> V_36 = 0 ;
if ( F_98 ( V_33 ) )
goto error;
}
if ( ! F_99 ( V_33 , sizeof( * V_39 ) ) )
goto error;
V_39 = F_27 ( V_33 ) ;
F_100 ( V_2 , V_39 -> type ) ;
if ( V_39 -> type > V_15 )
goto error;
if ( V_8 -> V_92 & ( V_93 | V_94 ) ) {
if ( ( V_39 -> type == V_169 ||
V_39 -> type == V_170 ) &&
V_2 -> V_3 . V_171 ) {
goto error;
}
if ( V_39 -> type != V_169 &&
V_39 -> type != V_170 &&
V_39 -> type != V_172 &&
V_39 -> type != V_173 ) {
goto error;
}
}
V_37 [ V_39 -> type ] . F_101 ( V_33 ) ;
V_166:
F_102 ( V_33 ) ;
return 0 ;
error:
F_23 ( V_2 , V_134 ) ;
goto V_166;
}
static void T_5 F_103 ( struct V_2 * V_2 )
{
int V_174 ;
F_104 (i)
F_105 ( V_2 -> V_3 . F_1 [ V_174 ] ) ;
F_106 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_107 ( struct V_2 * V_2 )
{
int V_174 , V_74 ;
V_2 -> V_3 . F_1 =
F_108 ( V_175 * sizeof( struct V_1 * ) , V_176 ) ;
if ( V_2 -> V_3 . F_1 == NULL )
return - V_177 ;
F_104 (i) {
struct V_1 * V_4 ;
V_74 = F_109 ( & V_4 , V_178 ,
V_179 , V_66 , V_2 ) ;
if ( V_74 < 0 )
goto V_180;
V_2 -> V_3 . F_1 [ V_174 ] = V_4 ;
V_4 -> V_181 = 2 * F_110 ( 64 * 1024 ) ;
F_111 ( V_4 , V_182 ) ;
F_36 ( V_4 ) -> V_183 = V_184 ;
}
V_2 -> V_3 . V_139 = 0 ;
V_2 -> V_3 . V_171 = 1 ;
V_2 -> V_3 . V_127 = 1 ;
V_2 -> V_3 . V_25 = 1 * V_185 ;
V_2 -> V_3 . V_22 = 0x1818 ;
V_2 -> V_3 . V_103 = 0 ;
return 0 ;
V_180:
F_104 (i)
F_105 ( V_2 -> V_3 . F_1 [ V_174 ] ) ;
F_106 ( V_2 -> V_3 . F_1 ) ;
return V_74 ;
}
int T_7 F_112 ( void )
{
return F_113 ( & V_186 ) ;
}
