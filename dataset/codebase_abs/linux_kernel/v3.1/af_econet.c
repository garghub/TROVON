static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_5 ) ;
F_3 ( V_4 ) ;
F_4 ( & V_5 ) ;
}
static void F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_2 ( & V_5 ) ;
F_6 ( V_4 , V_2 ) ;
F_4 ( & V_5 ) ;
}
static int F_7 ( struct V_6 * V_7 , struct V_8 * V_3 ,
struct V_9 * V_10 , T_1 V_11 , int V_12 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
struct V_13 * V_14 ;
T_1 V_15 ;
int V_16 ;
V_10 -> V_17 = sizeof( struct V_18 ) ;
F_8 ( & V_19 ) ;
V_14 = F_9 ( V_4 , V_12 , V_12 & V_20 , & V_16 ) ;
if ( V_14 == NULL )
goto V_21;
V_15 = V_14 -> V_11 ;
if ( V_15 > V_11 ) {
V_15 = V_11 ;
V_10 -> V_22 |= V_23 ;
}
V_16 = F_10 ( V_10 -> V_24 , V_14 -> V_25 , V_15 ) ;
if ( V_16 )
goto V_26;
V_4 -> V_27 = V_14 -> V_28 ;
if ( V_10 -> V_29 )
memcpy ( V_10 -> V_29 , V_14 -> V_30 , V_10 -> V_17 ) ;
V_16 = V_15 ;
V_26:
F_11 ( V_4 , V_14 ) ;
V_21:
F_12 ( & V_19 ) ;
return V_16 ;
}
static int F_13 ( struct V_8 * V_3 , struct V_31 * V_32 ,
int V_33 )
{
struct V_18 * V_34 = (struct V_18 * ) V_32 ;
struct V_3 * V_4 ;
struct V_35 * V_36 ;
if ( V_33 < sizeof( struct V_18 ) ||
V_34 -> V_37 != V_38 )
return - V_39 ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
V_36 = F_14 ( V_4 ) ;
V_36 -> V_30 = V_34 -> V_30 ;
V_36 -> V_40 = V_34 -> V_40 ;
V_36 -> V_41 = V_34 -> V_42 . V_41 ;
V_36 -> V_43 = V_34 -> V_42 . V_43 ;
F_12 ( & V_19 ) ;
return 0 ;
}
static void F_15 ( struct V_3 * V_4 , unsigned long V_44 , int V_45 )
{
struct V_13 * V_14 = F_16 ( 0 , V_46 ) ;
struct V_47 * V_48 ;
struct V_18 * V_34 ;
if ( V_14 == NULL ) {
F_17 ( L_1 ) ;
return;
}
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_34 = (struct V_18 * ) & V_48 -> V_34 ;
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_44 = V_44 ;
V_34 -> type = V_49 | V_45 ;
V_34 -> V_37 = V_38 ;
if ( F_18 ( V_4 , V_14 ) < 0 )
F_19 ( V_14 ) ;
}
static void F_20 ( struct V_13 * V_14 , int V_45 )
{
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
F_15 ( V_14 -> V_4 , V_48 -> V_44 , V_45 ) ;
}
static int F_21 ( struct V_6 * V_7 , struct V_8 * V_3 ,
struct V_9 * V_10 , T_1 V_11 )
{
struct V_18 * V_50 = (struct V_18 * ) V_10 -> V_29 ;
struct V_51 * V_52 ;
struct V_53 V_42 ;
int V_16 ;
unsigned char V_40 , V_30 ;
#if F_22 ( V_54 ) || F_22 ( V_55 )
struct V_3 * V_4 = V_3 -> V_4 ;
struct V_13 * V_14 ;
struct V_47 * V_48 ;
#endif
#ifdef V_54
struct V_9 V_56 ;
struct V_57 V_58 [ 2 ] ;
struct V_59 V_60 ;
struct V_61 V_62 ;
T_2 V_63 ;
T_3 V_64 ;
char * V_65 ;
#endif
if ( V_10 -> V_22 & ~ ( V_20 | V_66 ) )
return - V_39 ;
F_8 ( & V_19 ) ;
if ( V_50 == NULL || V_10 -> V_17 < sizeof( struct V_18 ) ) {
F_12 ( & V_19 ) ;
return - V_39 ;
}
V_42 . V_41 = V_50 -> V_42 . V_41 ;
V_42 . V_43 = V_50 -> V_42 . V_43 ;
V_40 = V_50 -> V_40 ;
V_30 = V_50 -> V_30 ;
V_52 = V_67 [ V_42 . V_43 ] ;
if ( V_52 == NULL ) {
V_52 = V_67 [ 0 ] ;
if ( V_52 == NULL ) {
F_12 ( & V_19 ) ;
return - V_68 ;
}
}
if ( V_52 -> type == V_69 ) {
#ifdef V_55
unsigned short V_70 = 0 ;
int V_71 ;
if ( V_11 + 15 > V_52 -> V_72 ) {
F_12 ( & V_19 ) ;
return - V_73 ;
}
F_23 ( V_52 ) ;
V_14 = F_24 ( V_4 , V_11 + F_25 ( V_52 ) ,
V_10 -> V_22 & V_20 , & V_16 ) ;
if ( V_14 == NULL )
goto V_74;
F_26 ( V_14 , F_27 ( V_52 ) ) ;
F_28 ( V_14 ) ;
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_48 -> V_44 = V_50 -> V_44 ;
V_48 -> V_34 = * V_50 ;
V_48 -> V_75 = F_20 ;
V_16 = - V_39 ;
V_71 = F_29 ( V_14 , V_52 , F_30 ( V_70 ) , & V_42 , NULL , V_11 ) ;
if ( V_71 < 0 )
goto V_26;
if ( V_71 > 0 ) {
struct V_76 * V_77 ;
V_77 = (struct V_76 * ) V_14 -> V_25 ;
V_77 -> V_30 = V_30 ;
V_77 -> V_40 = V_40 ;
if ( V_3 -> type != V_78 ) {
F_31 ( V_14 ) ;
V_14 -> V_11 = 0 ;
}
}
V_16 = F_32 ( F_33 ( V_14 , V_11 ) , V_10 -> V_24 , V_11 ) ;
V_14 -> V_79 = V_70 ;
V_14 -> V_52 = V_52 ;
V_14 -> V_80 = V_4 -> V_81 ;
if ( V_16 )
goto V_26;
V_16 = - V_68 ;
if ( ! ( V_52 -> V_12 & V_82 ) )
goto V_26;
F_34 ( V_14 ) ;
F_35 ( V_52 ) ;
F_12 ( & V_19 ) ;
return V_11 ;
V_26:
F_19 ( V_14 ) ;
V_74:
if ( V_52 )
F_35 ( V_52 ) ;
#else
V_16 = - V_83 ;
#endif
F_12 ( & V_19 ) ;
return V_16 ;
}
#ifdef V_54
if ( V_84 == NULL ) {
F_12 ( & V_19 ) ;
return - V_68 ;
}
if ( V_11 > 32768 ) {
V_16 = - V_85 ;
goto error;
}
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_86 = V_87 ;
V_62 . V_88 = F_36 ( V_89 ) ;
{
struct V_90 * V_91 ;
unsigned long V_92 = 0 ;
F_37 () ;
V_91 = F_38 ( V_52 ) ;
if ( V_91 ) {
if ( V_91 -> V_93 )
V_92 = F_39 ( V_91 -> V_93 -> V_94 ) &
0xffffff00 ;
}
F_40 () ;
V_62 . V_95 . V_96 = F_41 ( V_92 | V_42 . V_41 ) ;
}
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_40 = V_40 ;
V_60 . V_30 = V_30 & 0x7f ;
V_60 . V_97 = 2 ;
V_63 = sizeof( struct V_59 ) ;
V_58 [ 0 ] . V_98 = ( void * ) & V_60 ;
V_58 [ 0 ] . V_99 = V_63 ;
V_65 = F_42 ( V_11 ) ;
if ( V_65 == NULL ) {
V_16 = - V_100 ;
goto error;
}
V_58 [ 1 ] . V_98 = V_65 ;
V_58 [ 1 ] . V_99 = V_11 ;
V_16 = F_32 ( V_65 , V_10 -> V_24 , V_11 ) ;
if ( V_16 )
goto V_101;
V_14 = F_24 ( V_4 , 0 , V_10 -> V_22 & V_20 , & V_16 ) ;
if ( V_14 == NULL )
goto V_101;
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_48 -> V_44 = V_50 -> V_44 ;
V_48 -> V_102 = 5 * V_103 ;
V_48 -> V_104 = V_105 ;
V_60 . V_106 = V_107 ;
V_48 -> V_108 = ( V_107 ++ ) ;
V_48 -> V_34 = * V_50 ;
F_43 ( & V_109 , V_14 ) ;
V_56 . V_29 = ( void * ) & V_62 ;
V_56 . V_17 = sizeof( V_62 ) ;
V_56 . V_24 = & V_58 [ 0 ] ;
V_56 . V_110 = 2 ;
V_56 . V_111 = NULL ;
V_56 . V_112 = 0 ;
V_56 . V_22 = 0 ;
V_64 = F_44 () ;
F_45 ( V_113 ) ;
V_16 = F_46 ( V_84 , & V_56 , V_63 ) ;
F_45 ( V_64 ) ;
V_101:
F_47 ( V_65 ) ;
error:
#else
V_16 = - V_83 ;
#endif
F_12 ( & V_19 ) ;
return V_16 ;
}
static int F_48 ( struct V_8 * V_3 , struct V_31 * V_32 ,
int * V_114 , int V_115 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
struct V_18 * V_34 = (struct V_18 * ) V_32 ;
if ( V_115 )
return - V_116 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
V_36 = F_14 ( V_4 ) ;
V_34 -> V_37 = V_38 ;
V_34 -> V_40 = V_36 -> V_40 ;
V_34 -> V_42 . V_41 = V_36 -> V_41 ;
V_34 -> V_42 . V_43 = V_36 -> V_43 ;
F_12 ( & V_19 ) ;
* V_114 = sizeof( * V_34 ) ;
return 0 ;
}
static void F_49 ( unsigned long V_25 )
{
struct V_3 * V_4 = (struct V_3 * ) V_25 ;
if ( ! F_50 ( V_4 ) ) {
F_51 ( V_4 ) ;
return;
}
V_4 -> V_117 . V_118 = V_105 + 10 * V_103 ;
F_52 ( & V_4 -> V_117 ) ;
F_17 ( L_2 ) ;
}
static int F_53 ( struct V_8 * V_3 )
{
struct V_3 * V_4 ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
if ( ! V_4 )
goto V_74;
F_1 ( & V_119 , V_4 ) ;
V_4 -> V_120 ( V_4 ) ;
F_54 ( V_4 ) ;
F_55 ( & V_4 -> V_121 ) ;
if ( F_50 ( V_4 ) ) {
V_4 -> V_117 . V_25 = ( unsigned long ) V_4 ;
V_4 -> V_117 . V_118 = V_105 + V_103 ;
V_4 -> V_117 . V_122 = F_49 ;
F_52 ( & V_4 -> V_117 ) ;
goto V_74;
}
F_51 ( V_4 ) ;
V_74:
F_12 ( & V_19 ) ;
return 0 ;
}
static int F_56 ( struct V_43 * V_43 , struct V_8 * V_3 , int V_79 ,
int V_123 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_16 ;
if ( ! F_57 ( V_43 , & V_124 ) )
return - V_125 ;
if ( V_3 -> type != V_78 )
return - V_126 ;
V_3 -> V_127 = V_128 ;
V_16 = - V_129 ;
V_4 = F_58 ( V_43 , V_130 , V_131 , & V_132 ) ;
if ( V_4 == NULL )
goto V_21;
V_4 -> V_133 = 1 ;
V_3 -> V_134 = & V_135 ;
F_59 ( V_3 , V_4 ) ;
V_36 = F_14 ( V_4 ) ;
F_60 ( V_4 , V_136 ) ;
V_4 -> V_137 = V_130 ;
V_36 -> V_138 = V_79 ;
F_5 ( & V_119 , V_4 ) ;
return 0 ;
V_21:
return V_16 ;
}
static int F_61 ( struct V_8 * V_3 , unsigned int V_139 , void T_4 * V_140 )
{
struct V_141 V_142 ;
struct V_143 * V_144 ;
struct V_51 * V_52 ;
struct V_18 * V_34 ;
int V_16 ;
if ( F_62 ( & V_142 , V_140 , sizeof( struct V_141 ) ) )
return - V_145 ;
V_52 = F_63 ( & V_124 , V_142 . V_146 ) ;
if ( V_52 == NULL )
return - V_147 ;
V_34 = (struct V_18 * ) & V_142 . V_148 ;
F_8 ( & V_19 ) ;
V_16 = 0 ;
switch ( V_139 ) {
case V_149 :
if ( ! F_64 ( V_150 ) ) {
V_16 = - V_151 ;
break;
}
V_144 = V_52 -> V_152 ;
if ( V_144 == NULL ) {
V_144 = F_65 ( sizeof( struct V_143 ) , V_131 ) ;
if ( V_144 == NULL ) {
V_16 = - V_100 ;
break;
}
V_52 -> V_152 = V_144 ;
} else
V_67 [ V_144 -> V_43 ] = NULL ;
V_144 -> V_41 = V_34 -> V_42 . V_41 ;
V_144 -> V_43 = V_34 -> V_42 . V_43 ;
V_67 [ V_34 -> V_42 . V_43 ] = V_52 ;
if ( ! V_67 [ 0 ] )
V_67 [ 0 ] = V_52 ;
break;
case V_153 :
V_144 = V_52 -> V_152 ;
if ( V_144 == NULL ) {
V_16 = - V_147 ;
break;
}
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_42 . V_41 = V_144 -> V_41 ;
V_34 -> V_42 . V_43 = V_144 -> V_43 ;
V_34 -> V_37 = V_38 ;
F_35 ( V_52 ) ;
if ( F_66 ( V_140 , & V_142 , sizeof( struct V_141 ) ) )
V_16 = - V_145 ;
break;
default:
V_16 = - V_39 ;
break;
}
F_12 ( & V_19 ) ;
F_35 ( V_52 ) ;
return V_16 ;
}
static int F_67 ( struct V_8 * V_3 , unsigned int V_139 ,
unsigned long V_140 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
void T_4 * V_154 = ( void T_4 * ) V_140 ;
switch ( V_139 ) {
case V_155 :
return F_68 ( V_4 , V_154 ) ;
case V_156 :
return F_69 ( V_4 , V_154 ) ;
case V_149 :
case V_153 :
return F_61 ( V_3 , V_139 , V_154 ) ;
}
return - V_157 ;
}
static struct V_3 * F_70 ( unsigned char V_40 , unsigned char
V_41 , unsigned char V_43 )
{
struct V_3 * V_4 ;
struct V_158 * V_159 ;
F_71 ( & V_5 ) ;
F_72 (sk, node, &econet_sklist) {
struct V_35 * V_160 = F_14 ( V_4 ) ;
if ( ( V_160 -> V_40 == V_40 || V_160 -> V_40 == 0 ) &&
( V_160 -> V_41 == V_41 || V_160 -> V_41 == 0 ) &&
( V_160 -> V_43 == V_43 || V_160 -> V_43 == 0 ) ) {
F_73 ( V_4 ) ;
goto V_161;
}
}
V_4 = NULL ;
V_161:
F_74 ( & V_5 ) ;
return V_4 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_13 * V_14 ,
unsigned char V_162 , unsigned char V_43 ,
unsigned char V_30 , unsigned char V_40 )
{
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
struct V_18 * V_34 = (struct V_18 * ) & V_48 -> V_34 ;
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_37 = V_38 ;
V_34 -> type = V_163 ;
V_34 -> V_40 = V_40 ;
V_34 -> V_30 = V_30 ;
V_34 -> V_42 . V_43 = V_43 ;
V_34 -> V_42 . V_41 = V_162 ;
return F_18 ( V_4 , V_14 ) ;
}
static void F_76 ( T_5 V_42 , unsigned long V_108 , int V_97 , int V_30 )
{
struct V_61 sin = {
. V_86 = V_87 ,
. V_88 = F_36 ( V_89 ) ,
. V_95 = { . V_96 = V_42 }
} ;
struct V_59 V_60 = { . V_97 = V_97 , . V_30 = V_30 , . V_106 = V_108 } ;
struct V_164 V_58 = { . V_98 = ( void * ) & V_60 , . V_99 = sizeof( V_60 ) } ;
struct V_9 V_56 ;
V_56 . V_29 = ( void * ) & sin ;
V_56 . V_17 = sizeof( sin ) ;
V_56 . V_111 = NULL ;
V_56 . V_112 = 0 ;
V_56 . V_22 = 0 ;
F_77 ( V_84 , & V_56 , & V_58 , 1 , sizeof( V_60 ) ) ;
}
static void F_78 ( struct V_13 * V_14 , struct V_59 * V_60 , T_1 V_11 )
{
struct V_165 * V_166 = F_79 ( V_14 ) ;
unsigned char V_162 = F_39 ( V_166 -> V_50 ) & 0xff ;
struct V_167 * V_168 = F_80 ( V_14 ) ;
struct V_143 * V_144 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_13 * V_169 ;
if ( V_168 )
V_144 = V_168 -> V_52 -> V_152 ;
if ( ! V_144 )
goto V_170;
V_4 = F_70 ( V_60 -> V_40 , V_162 , V_144 -> V_43 ) ;
if ( V_4 == NULL )
goto V_170;
V_169 = F_16 ( ( V_11 - sizeof( struct V_59 ) + 15 ) & ~ 15 ,
V_46 ) ;
if ( V_169 == NULL ) {
F_17 ( L_3 ) ;
goto V_170;
}
memcpy ( F_33 ( V_169 , V_11 - sizeof( struct V_59 ) ) , ( void * ) ( V_60 + 1 ) ,
V_11 - sizeof( struct V_59 ) ) ;
if ( F_75 ( V_4 , V_169 , V_162 , V_144 -> V_43 , V_60 -> V_30 , V_60 -> V_40 ) ) {
F_19 ( V_169 ) ;
goto V_170;
}
F_76 ( V_166 -> V_50 , V_60 -> V_106 , 3 , 0 ) ;
F_81 ( V_4 ) ;
return;
V_170:
F_76 ( V_166 -> V_50 , V_60 -> V_106 , 4 , 0 ) ;
if ( V_4 )
F_81 ( V_4 ) ;
}
static void F_82 ( unsigned long V_108 , int V_45 )
{
struct V_13 * V_14 ;
unsigned long V_12 ;
struct V_47 * V_48 ;
F_83 ( & V_171 , V_12 ) ;
F_84 (&aun_queue, skb) {
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
if ( V_48 -> V_108 == V_108 )
goto V_172;
}
F_85 ( & V_171 , V_12 ) ;
F_17 ( L_4 , V_108 ) ;
return;
V_172:
F_15 ( V_14 -> V_4 , V_48 -> V_44 , V_45 ) ;
F_86 ( V_14 , & V_109 ) ;
F_85 ( & V_171 , V_12 ) ;
F_19 ( V_14 ) ;
}
static void F_87 ( struct V_3 * V_4 , int V_173 )
{
int V_16 ;
struct V_13 * V_14 ;
unsigned char * V_25 ;
struct V_59 * V_60 ;
T_1 V_11 ;
while ( ( V_14 = F_9 ( V_4 , 0 , 1 , & V_16 ) ) == NULL ) {
if ( V_16 == - V_174 ) {
F_88 ( L_5 ) ;
return;
}
F_17 ( L_6 , - V_16 ) ;
}
V_25 = F_89 ( V_14 ) + sizeof( struct V_175 ) ;
V_60 = (struct V_59 * ) V_25 ;
V_11 = V_14 -> V_11 - sizeof( struct V_175 ) ;
switch ( V_60 -> V_97 ) {
case 2 :
F_78 ( V_14 , V_60 , V_11 ) ;
break;
case 3 :
F_82 ( V_60 -> V_106 , V_176 ) ;
break;
case 4 :
F_82 ( V_60 -> V_106 , V_177 ) ;
break;
default:
F_17 ( L_7 , V_25 [ 0 ] ) ;
}
F_11 ( V_4 , V_14 ) ;
}
static void F_90 ( unsigned long V_178 )
{
struct V_13 * V_14 , * V_179 ;
unsigned long V_12 ;
F_83 ( & V_171 , V_12 ) ;
F_91 (&aun_queue, skb, n) {
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
if ( ( V_105 - V_48 -> V_104 ) > V_48 -> V_102 ) {
F_15 ( V_14 -> V_4 , V_48 -> V_44 ,
V_180 ) ;
F_86 ( V_14 , & V_109 ) ;
F_19 ( V_14 ) ;
}
}
F_85 ( & V_171 , V_12 ) ;
F_92 ( & V_181 , V_105 + ( V_103 * 2 ) ) ;
}
static int T_6 F_93 ( void )
{
int error ;
struct V_61 sin ;
F_94 ( & V_109 ) ;
F_95 ( & V_181 , F_90 , 0 ) ;
V_181 . V_118 = V_105 + ( V_103 * 2 ) ;
F_52 ( & V_181 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_88 = F_36 ( V_89 ) ;
error = F_96 ( V_182 , V_78 , 0 , & V_84 ) ;
if ( error < 0 ) {
F_88 ( L_8 , - error ) ;
return error ;
}
V_84 -> V_4 -> V_133 = 1 ;
V_84 -> V_4 -> V_183 = V_46 ;
error = V_84 -> V_134 -> V_184 ( V_84 , (struct V_31 * ) & sin ,
sizeof( sin ) ) ;
if ( error < 0 ) {
F_88 ( L_9 , - error ) ;
goto V_185;
}
V_84 -> V_4 -> V_186 = F_87 ;
return 0 ;
V_185:
F_97 ( V_84 ) ;
V_84 = NULL ;
return error ;
}
static int F_98 ( struct V_13 * V_14 , struct V_51 * V_52 ,
struct V_187 * V_188 , struct V_51 * V_189 )
{
struct V_76 * V_190 ;
struct V_3 * V_4 = NULL ;
struct V_143 * V_144 = V_52 -> V_152 ;
if ( ! F_57 ( F_99 ( V_52 ) , & V_124 ) )
goto V_191;
if ( V_14 -> V_192 == V_193 )
goto V_191;
if ( ! V_144 )
goto V_191;
V_14 = F_100 ( V_14 , V_46 ) ;
if ( V_14 == NULL )
return V_194 ;
if ( ! F_101 ( V_14 , sizeof( struct V_76 ) ) )
goto V_191;
V_190 = (struct V_76 * ) V_14 -> V_25 ;
if ( V_190 -> V_40 == V_195 ) {
V_14 -> V_79 = F_36 ( V_196 ) ;
F_102 ( V_14 , sizeof( struct V_76 ) ) ;
F_103 ( V_14 ) ;
return V_197 ;
}
V_4 = F_70 ( V_190 -> V_40 , V_190 -> V_198 , V_190 -> V_199 ) ;
if ( ! V_4 )
goto V_191;
if ( F_75 ( V_4 , V_14 , V_144 -> V_43 , V_190 -> V_198 , V_190 -> V_30 ,
V_190 -> V_40 ) )
goto V_191;
F_81 ( V_4 ) ;
return V_197 ;
V_191:
if ( V_4 )
F_81 ( V_4 ) ;
F_19 ( V_14 ) ;
return V_194 ;
}
static void F_104 ( void )
{
F_105 ( & V_200 ) ;
}
static int F_106 ( struct V_201 * V_202 , unsigned long V_10 ,
void * V_25 )
{
struct V_51 * V_52 = V_25 ;
struct V_143 * V_144 ;
if ( ! F_57 ( F_99 ( V_52 ) , & V_124 ) )
return V_203 ;
switch ( V_10 ) {
case V_204 :
V_144 = V_52 -> V_152 ;
if ( V_144 ) {
if ( V_67 [ 0 ] == V_52 )
V_67 [ 0 ] = NULL ;
V_67 [ V_144 -> V_43 ] = NULL ;
F_107 ( V_144 ) ;
V_52 -> V_152 = NULL ;
}
break;
}
return V_203 ;
}
static void T_7 F_108 ( void )
{
#ifdef V_54
F_109 ( & V_181 ) ;
if ( V_84 )
F_97 ( V_84 ) ;
#endif
F_110 ( & V_205 ) ;
#ifdef V_55
F_111 ( & V_200 ) ;
#endif
F_112 ( V_206 . V_207 ) ;
F_113 ( & V_132 ) ;
}
static int T_6 F_114 ( void )
{
int V_16 = F_115 ( & V_132 , 0 ) ;
if ( V_16 != 0 )
goto V_21;
F_116 ( & V_206 ) ;
#ifdef V_54
F_93 () ;
#endif
#ifdef V_55
F_104 () ;
#endif
F_117 ( & V_205 ) ;
V_21:
return V_16 ;
}
