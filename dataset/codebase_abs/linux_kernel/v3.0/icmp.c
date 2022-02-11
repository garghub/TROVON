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
int V_73 ;
memset ( V_10 , 0 , sizeof( * V_10 ) ) ;
V_10 -> V_24 = ( V_71 -> V_54 . V_55 . V_55 . V_61 ?
V_71 -> V_54 . V_55 . V_55 . V_62 : V_70 -> V_58 ) ;
V_10 -> V_58 = V_58 ;
V_10 -> V_64 = F_38 ( V_56 ) ;
V_10 -> V_65 = V_66 ;
V_10 -> V_74 = type ;
V_10 -> V_75 = V_11 ;
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
} else if ( F_47 ( V_8 ) == - V_76 ) {
V_8 = NULL ;
} else
return V_8 ;
V_73 = F_48 ( V_68 , F_40 ( V_10 ) , V_77 ) ;
if ( V_73 )
goto V_78;
if ( F_49 ( V_2 , V_10 -> V_58 ) == V_79 ) {
V_72 = F_45 ( V_2 , V_10 ) ;
if ( F_42 ( V_72 ) )
V_73 = F_47 ( V_72 ) ;
} else {
struct V_9 V_80 = {} ;
unsigned long V_81 ;
V_80 . V_24 = V_10 -> V_58 ;
V_72 = F_41 ( V_2 , & V_80 ) ;
if ( F_42 ( V_72 ) ) {
V_73 = F_47 ( V_72 ) ;
goto V_78;
}
V_81 = V_68 -> V_82 ;
V_73 = F_50 ( V_68 , V_10 -> V_24 , V_10 -> V_58 ,
F_38 ( V_56 ) , V_72 -> V_13 . V_19 ) ;
F_51 ( & V_72 -> V_13 ) ;
V_72 = F_34 ( V_68 ) ;
V_68 -> V_82 = V_81 ;
}
if ( V_73 )
goto V_78;
V_72 = (struct V_7 * ) F_46 ( V_2 , & V_72 -> V_13 ,
F_40 ( V_10 ) , NULL ,
V_83 ) ;
if ( ! F_42 ( V_72 ) ) {
F_51 ( & V_8 -> V_13 ) ;
V_8 = V_72 ;
} else if ( F_47 ( V_72 ) == - V_76 ) {
if ( V_8 )
F_51 ( & V_8 -> V_13 ) ;
return V_72 ;
} else {
V_73 = F_47 ( V_72 ) ;
goto V_78;
}
return V_8 ;
V_78:
if ( V_8 )
return V_8 ;
return F_52 ( V_73 ) ;
}
void F_53 ( struct V_32 * V_68 , int type , int V_11 , T_2 V_84 )
{
struct V_69 * V_70 ;
int V_85 ;
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
if ( ( T_3 * ) V_70 < V_68 -> V_86 ||
( V_68 -> V_87 + sizeof( * V_70 ) ) > V_68 -> V_88 )
goto V_16;
if ( V_68 -> V_89 != V_90 )
goto V_16;
if ( V_8 -> V_91 & ( V_92 | V_93 ) )
goto V_16;
if ( V_70 -> V_94 & F_54 ( V_95 ) )
goto V_16;
if ( V_37 [ type ] . error ) {
if ( V_70 -> V_96 == V_66 ) {
T_3 V_97 , * V_98 ;
V_98 = F_55 ( V_68 ,
F_56 ( V_68 ) +
( V_70 -> V_99 << 2 ) +
F_57 ( struct V_47 ,
type ) -
V_68 -> V_38 ,
sizeof( V_97 ) ,
& V_97 ) ;
if ( V_98 == NULL )
goto V_16;
if ( * V_98 > V_15 ||
V_37 [ * V_98 ] . error )
goto V_16;
}
}
V_4 = F_3 ( V_2 ) ;
if ( V_4 == NULL )
return;
V_58 = V_70 -> V_24 ;
if ( ! ( V_8 -> V_91 & V_100 ) ) {
struct V_101 * V_19 = NULL ;
F_58 () ;
if ( F_59 ( V_8 ) &&
V_2 -> V_3 . V_102 )
V_19 = F_60 ( V_2 , V_8 -> V_103 ) ;
if ( V_19 )
V_58 = F_61 ( V_19 , 0 , V_104 ) ;
else
V_58 = 0 ;
F_62 () ;
}
V_56 = V_37 [ type ] . error ? ( ( V_70 -> V_56 & V_105 ) |
V_106 ) :
V_70 -> V_56 ;
if ( F_35 ( & V_35 . V_54 . V_55 . V_55 , V_68 ) )
goto V_67;
V_35 . V_38 . V_39 . type = type ;
V_35 . V_38 . V_39 . V_11 = V_11 ;
V_35 . V_38 . V_39 . V_107 . V_108 = V_84 ;
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
goto V_109;
V_85 = F_64 ( & V_8 -> V_13 ) ;
if ( V_85 > 576 )
V_85 = 576 ;
V_85 -= sizeof( struct V_69 ) + V_35 . V_54 . V_55 . V_55 . V_60 ;
V_85 -= sizeof( struct V_47 ) ;
V_35 . V_42 = V_68 -> V_30 - V_35 . V_29 ;
if ( V_35 . V_42 > V_85 )
V_35 . V_42 = V_85 ;
V_35 . V_43 = sizeof( struct V_47 ) ;
F_20 ( & V_35 , & V_10 , & V_41 , & V_8 ) ;
V_109:
F_43 ( V_8 ) ;
V_67:
F_8 ( V_4 ) ;
V_16: ;
}
static void F_65 ( struct V_32 * V_33 )
{
const struct V_69 * V_70 ;
struct V_47 * V_39 ;
int V_110 , V_96 ;
const struct V_111 * V_112 ;
T_4 V_84 = 0 ;
struct V_2 * V_2 ;
V_2 = F_21 ( F_66 ( V_33 ) -> V_19 ) ;
if ( ! F_67 ( V_33 , sizeof( struct V_69 ) ) )
goto V_113;
V_39 = F_27 ( V_33 ) ;
V_70 = ( const struct V_69 * ) V_33 -> V_38 ;
if ( V_70 -> V_99 < 5 )
goto V_113;
if ( V_39 -> type == V_17 ) {
switch ( V_39 -> V_11 & 15 ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
break;
case V_18 :
if ( V_118 . V_119 ) {
F_68 ( V_120 L_1 ,
& V_70 -> V_24 ) ;
} else {
V_84 = F_69 ( V_2 , V_70 ,
F_70 ( V_39 -> V_107 . V_121 . V_122 ) ,
V_33 -> V_19 ) ;
if ( ! V_84 )
goto V_16;
}
break;
case V_123 :
F_68 ( V_120 L_2 ,
& V_70 -> V_24 ) ;
break;
default:
break;
}
if ( V_39 -> V_11 > V_124 )
goto V_16;
} else if ( V_39 -> type == V_125 )
V_84 = F_71 ( V_39 -> V_107 . V_108 ) >> 24 ;
if ( ! V_2 -> V_3 . V_126 &&
F_49 ( V_2 , V_70 -> V_24 ) == V_127 ) {
if ( F_72 () )
F_73 ( V_128 L_3
L_4
L_5 ,
& F_37 ( V_33 ) -> V_58 ,
V_39 -> type , V_39 -> V_11 ,
& V_70 -> V_24 ,
V_33 -> V_19 -> V_129 ) ;
goto V_16;
}
if ( ! F_67 ( V_33 , V_70 -> V_99 * 4 + 8 ) )
goto V_16;
V_70 = ( const struct V_69 * ) V_33 -> V_38 ;
V_96 = V_70 -> V_96 ;
F_74 ( V_33 , V_96 , V_84 ) ;
V_110 = V_96 & ( V_130 - 1 ) ;
F_58 () ;
V_112 = F_75 ( V_131 [ V_110 ] ) ;
if ( V_112 && V_112 -> V_132 )
V_112 -> V_132 ( V_33 , V_84 ) ;
F_62 () ;
V_16:
return;
V_113:
F_23 ( V_2 , V_133 ) ;
goto V_16;
}
static void F_76 ( struct V_32 * V_33 )
{
const struct V_69 * V_70 ;
if ( V_33 -> V_30 < sizeof( struct V_69 ) )
goto V_113;
if ( ! F_67 ( V_33 , sizeof( struct V_69 ) ) )
goto V_16;
V_70 = ( const struct V_69 * ) V_33 -> V_38 ;
switch ( F_27 ( V_33 ) -> V_11 & 7 ) {
case V_134 :
case V_135 :
case V_136 :
case V_137 :
F_77 ( F_37 ( V_33 ) -> V_58 , V_70 -> V_24 ,
F_27 ( V_33 ) -> V_107 . V_108 ,
V_70 -> V_58 , V_33 -> V_19 ) ;
break;
}
if ( V_70 -> V_96 == V_66 &&
V_70 -> V_99 >= 5 &&
F_67 ( V_33 , ( V_70 -> V_99 << 2 ) + 8 ) ) {
F_78 ( V_33 , F_27 ( V_33 ) -> V_107 . V_108 ) ;
}
V_16:
return;
V_113:
F_23 ( F_21 ( V_33 -> V_19 ) , V_133 ) ;
goto V_16;
}
static void F_79 ( struct V_32 * V_33 )
{
struct V_2 * V_2 ;
V_2 = F_21 ( F_66 ( V_33 ) -> V_19 ) ;
if ( ! V_2 -> V_3 . V_138 ) {
struct V_34 V_35 ;
V_35 . V_38 . V_39 = * F_27 ( V_33 ) ;
V_35 . V_38 . V_39 . type = V_139 ;
V_35 . V_33 = V_33 ;
V_35 . V_29 = 0 ;
V_35 . V_42 = V_33 -> V_30 ;
V_35 . V_43 = sizeof( struct V_47 ) ;
F_33 ( & V_35 , V_33 ) ;
}
}
static void F_80 ( struct V_32 * V_33 )
{
struct V_140 V_141 ;
struct V_34 V_35 ;
if ( V_33 -> V_30 < 4 )
goto V_113;
F_81 ( & V_141 ) ;
V_35 . V_38 . V_142 [ 1 ] = F_82 ( ( V_141 . V_143 % 86400 ) * V_144 +
V_141 . V_145 / V_146 ) ;
V_35 . V_38 . V_142 [ 2 ] = V_35 . V_38 . V_142 [ 1 ] ;
if ( F_83 ( V_33 , 0 , & V_35 . V_38 . V_142 [ 0 ] , 4 ) )
F_84 () ;
V_35 . V_38 . V_39 = * F_27 ( V_33 ) ;
V_35 . V_38 . V_39 . type = V_147 ;
V_35 . V_38 . V_39 . V_11 = 0 ;
V_35 . V_33 = V_33 ;
V_35 . V_29 = 0 ;
V_35 . V_42 = 0 ;
V_35 . V_43 = sizeof( struct V_47 ) + 12 ;
F_33 ( & V_35 , V_33 ) ;
V_16:
return;
V_113:
F_23 ( F_21 ( F_66 ( V_33 ) -> V_19 ) , V_133 ) ;
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
struct V_101 * V_19 = V_33 -> V_19 ;
struct V_148 * V_149 ;
struct V_150 * V_151 ;
if ( V_33 -> V_30 < 4 || ! ( V_8 -> V_91 & V_152 ) )
return;
V_149 = F_87 ( V_19 ) ;
if ( ! V_149 )
return;
if ( V_149 -> V_153 &&
F_88 ( V_149 ) &&
F_89 ( V_149 ) ) {
T_2 V_154 , * V_155 ;
V_155 = F_55 ( V_33 , 0 , sizeof( V_154 ) , & V_154 ) ;
F_90 ( V_155 == NULL ) ;
for ( V_151 = V_149 -> V_153 ; V_151 ; V_151 = V_151 -> V_156 ) {
if ( * V_155 == V_151 -> V_157 &&
F_91 ( F_37 ( V_33 ) -> V_58 , V_151 ) )
break;
}
if ( ! V_151 && F_72 () ) {
F_73 ( V_120 L_6 ,
V_155 , V_19 -> V_129 , & F_37 ( V_33 ) -> V_58 ) ;
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
if ( ! F_94 ( NULL , V_158 , V_33 ) ) {
struct V_159 * V_160 = F_95 ( V_33 ) ;
int V_161 ;
if ( ! ( V_160 && V_160 -> V_162 [ V_160 -> V_30 - 1 ] -> V_163 . V_20 &
V_164 ) )
goto V_165;
if ( ! F_67 ( V_33 , sizeof( * V_39 ) + sizeof( struct V_69 ) ) )
goto V_165;
V_161 = F_63 ( V_33 ) ;
F_96 ( V_33 , sizeof( * V_39 ) ) ;
if ( ! F_97 ( NULL , V_158 , V_33 ) )
goto V_165;
F_96 ( V_33 , V_161 ) ;
}
F_23 ( V_2 , V_166 ) ;
switch ( V_33 -> V_50 ) {
case V_167 :
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
if ( V_8 -> V_91 & ( V_92 | V_93 ) ) {
if ( ( V_39 -> type == V_168 ||
V_39 -> type == V_169 ) &&
V_2 -> V_3 . V_170 ) {
goto error;
}
if ( V_39 -> type != V_168 &&
V_39 -> type != V_169 &&
V_39 -> type != V_171 &&
V_39 -> type != V_172 ) {
goto error;
}
}
V_37 [ V_39 -> type ] . F_101 ( V_33 ) ;
V_165:
F_102 ( V_33 ) ;
return 0 ;
error:
F_23 ( V_2 , V_133 ) ;
goto V_165;
}
static void T_5 F_103 ( struct V_2 * V_2 )
{
int V_173 ;
F_104 (i)
F_105 ( V_2 -> V_3 . F_1 [ V_173 ] ) ;
F_106 ( V_2 -> V_3 . F_1 ) ;
V_2 -> V_3 . F_1 = NULL ;
}
static int T_6 F_107 ( struct V_2 * V_2 )
{
int V_173 , V_73 ;
V_2 -> V_3 . F_1 =
F_108 ( V_174 * sizeof( struct V_1 * ) , V_175 ) ;
if ( V_2 -> V_3 . F_1 == NULL )
return - V_176 ;
F_104 (i) {
struct V_1 * V_4 ;
V_73 = F_109 ( & V_4 , V_177 ,
V_178 , V_66 , V_2 ) ;
if ( V_73 < 0 )
goto V_179;
V_2 -> V_3 . F_1 [ V_173 ] = V_4 ;
V_4 -> V_180 =
( 2 * ( ( 64 * 1024 ) + sizeof( struct V_32 ) ) ) ;
F_110 ( V_4 , V_181 ) ;
F_36 ( V_4 ) -> V_182 = V_183 ;
}
V_2 -> V_3 . V_138 = 0 ;
V_2 -> V_3 . V_170 = 1 ;
V_2 -> V_3 . V_126 = 1 ;
V_2 -> V_3 . V_25 = 1 * V_184 ;
V_2 -> V_3 . V_22 = 0x1818 ;
V_2 -> V_3 . V_102 = 0 ;
return 0 ;
V_179:
F_104 (i)
F_105 ( V_2 -> V_3 . F_1 [ V_173 ] ) ;
F_106 ( V_2 -> V_3 . F_1 ) ;
return V_73 ;
}
int T_7 F_111 ( void )
{
return F_112 ( & V_185 ) ;
}
