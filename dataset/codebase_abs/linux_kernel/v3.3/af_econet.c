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
int V_71 , V_72 ;
int V_73 ;
if ( V_11 + 15 > V_52 -> V_74 ) {
F_12 ( & V_19 ) ;
return - V_75 ;
}
F_23 ( V_52 ) ;
V_71 = F_24 ( V_52 ) ;
V_72 = V_52 -> V_76 ;
V_14 = F_25 ( V_4 , V_11 + V_71 + V_72 ,
V_10 -> V_22 & V_20 , & V_16 ) ;
if ( V_14 == NULL )
goto V_77;
F_26 ( V_14 , V_71 ) ;
F_27 ( V_14 ) ;
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_48 -> V_44 = V_50 -> V_44 ;
V_48 -> V_34 = * V_50 ;
V_48 -> V_78 = F_20 ;
V_16 = - V_39 ;
V_73 = F_28 ( V_14 , V_52 , F_29 ( V_70 ) , & V_42 , NULL , V_11 ) ;
if ( V_73 < 0 )
goto V_26;
if ( V_73 > 0 ) {
struct V_79 * V_80 ;
V_80 = (struct V_79 * ) V_14 -> V_25 ;
V_80 -> V_30 = V_30 ;
V_80 -> V_40 = V_40 ;
if ( V_3 -> type != V_81 ) {
F_30 ( V_14 ) ;
V_14 -> V_11 = 0 ;
}
}
V_16 = F_31 ( F_32 ( V_14 , V_11 ) , V_10 -> V_24 , V_11 ) ;
V_14 -> V_82 = V_70 ;
V_14 -> V_52 = V_52 ;
V_14 -> V_83 = V_4 -> V_84 ;
if ( V_16 )
goto V_26;
V_16 = - V_68 ;
if ( ! ( V_52 -> V_12 & V_85 ) )
goto V_26;
F_33 ( V_14 ) ;
F_34 ( V_52 ) ;
F_12 ( & V_19 ) ;
return V_11 ;
V_26:
F_19 ( V_14 ) ;
V_77:
if ( V_52 )
F_34 ( V_52 ) ;
#else
V_16 = - V_86 ;
#endif
F_12 ( & V_19 ) ;
return V_16 ;
}
#ifdef V_54
if ( V_87 == NULL ) {
F_12 ( & V_19 ) ;
return - V_68 ;
}
if ( V_11 > 32768 ) {
V_16 = - V_88 ;
goto error;
}
memset ( & V_62 , 0 , sizeof( V_62 ) ) ;
V_62 . V_89 = V_90 ;
V_62 . V_91 = F_35 ( V_92 ) ;
{
struct V_93 * V_94 ;
unsigned long V_95 = 0 ;
F_36 () ;
V_94 = F_37 ( V_52 ) ;
if ( V_94 ) {
if ( V_94 -> V_96 )
V_95 = F_38 ( V_94 -> V_96 -> V_97 ) &
0xffffff00 ;
}
F_39 () ;
V_62 . V_98 . V_99 = F_40 ( V_95 | V_42 . V_41 ) ;
}
memset ( & V_60 , 0 , sizeof( V_60 ) ) ;
V_60 . V_40 = V_40 ;
V_60 . V_30 = V_30 & 0x7f ;
V_60 . V_100 = 2 ;
V_63 = sizeof( struct V_59 ) ;
V_58 [ 0 ] . V_101 = ( void * ) & V_60 ;
V_58 [ 0 ] . V_102 = V_63 ;
V_65 = F_41 ( V_11 ) ;
if ( V_65 == NULL ) {
V_16 = - V_103 ;
goto error;
}
V_58 [ 1 ] . V_101 = V_65 ;
V_58 [ 1 ] . V_102 = V_11 ;
V_16 = F_31 ( V_65 , V_10 -> V_24 , V_11 ) ;
if ( V_16 )
goto V_104;
V_14 = F_25 ( V_4 , 0 , V_10 -> V_22 & V_20 , & V_16 ) ;
if ( V_14 == NULL )
goto V_104;
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_48 -> V_44 = V_50 -> V_44 ;
V_48 -> V_105 = 5 * V_106 ;
V_48 -> V_107 = V_108 ;
V_60 . V_109 = V_110 ;
V_48 -> V_111 = ( V_110 ++ ) ;
V_48 -> V_34 = * V_50 ;
F_42 ( & V_112 , V_14 ) ;
V_56 . V_29 = ( void * ) & V_62 ;
V_56 . V_17 = sizeof( V_62 ) ;
V_56 . V_24 = & V_58 [ 0 ] ;
V_56 . V_113 = 2 ;
V_56 . V_114 = NULL ;
V_56 . V_115 = 0 ;
V_56 . V_22 = 0 ;
V_64 = F_43 () ;
F_44 ( V_116 ) ;
V_16 = F_45 ( V_87 , & V_56 , V_63 ) ;
F_44 ( V_64 ) ;
V_104:
F_46 ( V_65 ) ;
error:
#else
V_16 = - V_86 ;
#endif
F_12 ( & V_19 ) ;
return V_16 ;
}
static int F_47 ( struct V_8 * V_3 , struct V_31 * V_32 ,
int * V_117 , int V_118 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
struct V_18 * V_34 = (struct V_18 * ) V_32 ;
if ( V_118 )
return - V_119 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
V_36 = F_14 ( V_4 ) ;
V_34 -> V_37 = V_38 ;
V_34 -> V_40 = V_36 -> V_40 ;
V_34 -> V_42 . V_41 = V_36 -> V_41 ;
V_34 -> V_42 . V_43 = V_36 -> V_43 ;
F_12 ( & V_19 ) ;
* V_117 = sizeof( * V_34 ) ;
return 0 ;
}
static void F_48 ( unsigned long V_25 )
{
struct V_3 * V_4 = (struct V_3 * ) V_25 ;
if ( ! F_49 ( V_4 ) ) {
F_50 ( V_4 ) ;
return;
}
V_4 -> V_120 . V_121 = V_108 + 10 * V_106 ;
F_51 ( & V_4 -> V_120 ) ;
F_17 ( L_2 ) ;
}
static int F_52 ( struct V_8 * V_3 )
{
struct V_3 * V_4 ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
if ( ! V_4 )
goto V_77;
F_1 ( & V_122 , V_4 ) ;
V_4 -> V_123 ( V_4 ) ;
F_53 ( V_4 ) ;
F_54 ( & V_4 -> V_124 ) ;
if ( F_49 ( V_4 ) ) {
V_4 -> V_120 . V_25 = ( unsigned long ) V_4 ;
V_4 -> V_120 . V_121 = V_108 + V_106 ;
V_4 -> V_120 . V_125 = F_48 ;
F_51 ( & V_4 -> V_120 ) ;
goto V_77;
}
F_50 ( V_4 ) ;
V_77:
F_12 ( & V_19 ) ;
return 0 ;
}
static int F_55 ( struct V_43 * V_43 , struct V_8 * V_3 , int V_82 ,
int V_126 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_16 ;
if ( ! F_56 ( V_43 , & V_127 ) )
return - V_128 ;
if ( V_3 -> type != V_81 )
return - V_129 ;
V_3 -> V_130 = V_131 ;
V_16 = - V_132 ;
V_4 = F_57 ( V_43 , V_133 , V_134 , & V_135 ) ;
if ( V_4 == NULL )
goto V_21;
V_4 -> V_136 = 1 ;
V_3 -> V_137 = & V_138 ;
F_58 ( V_3 , V_4 ) ;
V_36 = F_14 ( V_4 ) ;
F_59 ( V_4 , V_139 ) ;
V_4 -> V_140 = V_133 ;
V_36 -> V_141 = V_82 ;
F_5 ( & V_122 , V_4 ) ;
return 0 ;
V_21:
return V_16 ;
}
static int F_60 ( struct V_8 * V_3 , unsigned int V_142 , void T_4 * V_143 )
{
struct V_144 V_145 ;
struct V_146 * V_147 ;
struct V_51 * V_52 ;
struct V_18 * V_34 ;
int V_16 ;
if ( F_61 ( & V_145 , V_143 , sizeof( struct V_144 ) ) )
return - V_148 ;
V_52 = F_62 ( & V_127 , V_145 . V_149 ) ;
if ( V_52 == NULL )
return - V_150 ;
V_34 = (struct V_18 * ) & V_145 . V_151 ;
F_8 ( & V_19 ) ;
V_16 = 0 ;
switch ( V_142 ) {
case V_152 :
if ( ! F_63 ( V_153 ) ) {
V_16 = - V_154 ;
break;
}
V_147 = V_52 -> V_155 ;
if ( V_147 == NULL ) {
V_147 = F_64 ( sizeof( struct V_146 ) , V_134 ) ;
if ( V_147 == NULL ) {
V_16 = - V_103 ;
break;
}
V_52 -> V_155 = V_147 ;
} else
V_67 [ V_147 -> V_43 ] = NULL ;
V_147 -> V_41 = V_34 -> V_42 . V_41 ;
V_147 -> V_43 = V_34 -> V_42 . V_43 ;
V_67 [ V_34 -> V_42 . V_43 ] = V_52 ;
if ( ! V_67 [ 0 ] )
V_67 [ 0 ] = V_52 ;
break;
case V_156 :
V_147 = V_52 -> V_155 ;
if ( V_147 == NULL ) {
V_16 = - V_150 ;
break;
}
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_42 . V_41 = V_147 -> V_41 ;
V_34 -> V_42 . V_43 = V_147 -> V_43 ;
V_34 -> V_37 = V_38 ;
F_34 ( V_52 ) ;
if ( F_65 ( V_143 , & V_145 , sizeof( struct V_144 ) ) )
V_16 = - V_148 ;
break;
default:
V_16 = - V_39 ;
break;
}
F_12 ( & V_19 ) ;
F_34 ( V_52 ) ;
return V_16 ;
}
static int F_66 ( struct V_8 * V_3 , unsigned int V_142 ,
unsigned long V_143 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
void T_4 * V_157 = ( void T_4 * ) V_143 ;
switch ( V_142 ) {
case V_158 :
return F_67 ( V_4 , V_157 ) ;
case V_159 :
return F_68 ( V_4 , V_157 ) ;
case V_152 :
case V_156 :
return F_60 ( V_3 , V_142 , V_157 ) ;
}
return - V_160 ;
}
static struct V_3 * F_69 ( unsigned char V_40 , unsigned char
V_41 , unsigned char V_43 )
{
struct V_3 * V_4 ;
struct V_161 * V_162 ;
F_70 ( & V_5 ) ;
F_71 (sk, node, &econet_sklist) {
struct V_35 * V_163 = F_14 ( V_4 ) ;
if ( ( V_163 -> V_40 == V_40 || V_163 -> V_40 == 0 ) &&
( V_163 -> V_41 == V_41 || V_163 -> V_41 == 0 ) &&
( V_163 -> V_43 == V_43 || V_163 -> V_43 == 0 ) ) {
F_72 ( V_4 ) ;
goto V_164;
}
}
V_4 = NULL ;
V_164:
F_73 ( & V_5 ) ;
return V_4 ;
}
static int F_74 ( struct V_3 * V_4 , struct V_13 * V_14 ,
unsigned char V_165 , unsigned char V_43 ,
unsigned char V_30 , unsigned char V_40 )
{
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
struct V_18 * V_34 = (struct V_18 * ) & V_48 -> V_34 ;
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_37 = V_38 ;
V_34 -> type = V_166 ;
V_34 -> V_40 = V_40 ;
V_34 -> V_30 = V_30 ;
V_34 -> V_42 . V_43 = V_43 ;
V_34 -> V_42 . V_41 = V_165 ;
return F_18 ( V_4 , V_14 ) ;
}
static void F_75 ( T_5 V_42 , unsigned long V_111 , int V_100 , int V_30 )
{
struct V_61 sin = {
. V_89 = V_90 ,
. V_91 = F_35 ( V_92 ) ,
. V_98 = { . V_99 = V_42 }
} ;
struct V_59 V_60 = { . V_100 = V_100 , . V_30 = V_30 , . V_109 = V_111 } ;
struct V_167 V_58 = { . V_101 = ( void * ) & V_60 , . V_102 = sizeof( V_60 ) } ;
struct V_9 V_56 ;
V_56 . V_29 = ( void * ) & sin ;
V_56 . V_17 = sizeof( sin ) ;
V_56 . V_114 = NULL ;
V_56 . V_115 = 0 ;
V_56 . V_22 = 0 ;
F_76 ( V_87 , & V_56 , & V_58 , 1 , sizeof( V_60 ) ) ;
}
static void F_77 ( struct V_13 * V_14 , struct V_59 * V_60 , T_1 V_11 )
{
struct V_168 * V_169 = F_78 ( V_14 ) ;
unsigned char V_165 = F_38 ( V_169 -> V_50 ) & 0xff ;
struct V_170 * V_171 = F_79 ( V_14 ) ;
struct V_146 * V_147 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_13 * V_172 ;
if ( V_171 )
V_147 = V_171 -> V_52 -> V_155 ;
if ( ! V_147 )
goto V_173;
V_4 = F_69 ( V_60 -> V_40 , V_165 , V_147 -> V_43 ) ;
if ( V_4 == NULL )
goto V_173;
V_172 = F_16 ( ( V_11 - sizeof( struct V_59 ) + 15 ) & ~ 15 ,
V_46 ) ;
if ( V_172 == NULL ) {
F_17 ( L_3 ) ;
goto V_173;
}
memcpy ( F_32 ( V_172 , V_11 - sizeof( struct V_59 ) ) , ( void * ) ( V_60 + 1 ) ,
V_11 - sizeof( struct V_59 ) ) ;
if ( F_74 ( V_4 , V_172 , V_165 , V_147 -> V_43 , V_60 -> V_30 , V_60 -> V_40 ) ) {
F_19 ( V_172 ) ;
goto V_173;
}
F_75 ( V_169 -> V_50 , V_60 -> V_109 , 3 , 0 ) ;
F_80 ( V_4 ) ;
return;
V_173:
F_75 ( V_169 -> V_50 , V_60 -> V_109 , 4 , 0 ) ;
if ( V_4 )
F_80 ( V_4 ) ;
}
static void F_81 ( unsigned long V_111 , int V_45 )
{
struct V_13 * V_14 ;
unsigned long V_12 ;
struct V_47 * V_48 ;
F_82 ( & V_174 , V_12 ) ;
F_83 (&aun_queue, skb) {
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
if ( V_48 -> V_111 == V_111 )
goto V_175;
}
F_84 ( & V_174 , V_12 ) ;
F_17 ( L_4 , V_111 ) ;
return;
V_175:
F_15 ( V_14 -> V_4 , V_48 -> V_44 , V_45 ) ;
F_85 ( V_14 , & V_112 ) ;
F_84 ( & V_174 , V_12 ) ;
F_19 ( V_14 ) ;
}
static void F_86 ( struct V_3 * V_4 , int V_176 )
{
int V_16 ;
struct V_13 * V_14 ;
unsigned char * V_25 ;
struct V_59 * V_60 ;
T_1 V_11 ;
while ( ( V_14 = F_9 ( V_4 , 0 , 1 , & V_16 ) ) == NULL ) {
if ( V_16 == - V_177 ) {
F_87 ( L_5 ) ;
return;
}
F_17 ( L_6 , - V_16 ) ;
}
V_25 = F_88 ( V_14 ) + sizeof( struct V_178 ) ;
V_60 = (struct V_59 * ) V_25 ;
V_11 = V_14 -> V_11 - sizeof( struct V_178 ) ;
switch ( V_60 -> V_100 ) {
case 2 :
F_77 ( V_14 , V_60 , V_11 ) ;
break;
case 3 :
F_81 ( V_60 -> V_109 , V_179 ) ;
break;
case 4 :
F_81 ( V_60 -> V_109 , V_180 ) ;
break;
default:
F_17 ( L_7 , V_25 [ 0 ] ) ;
}
F_11 ( V_4 , V_14 ) ;
}
static void F_89 ( unsigned long V_181 )
{
struct V_13 * V_14 , * V_182 ;
unsigned long V_12 ;
F_82 ( & V_174 , V_12 ) ;
F_90 (&aun_queue, skb, n) {
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
if ( ( V_108 - V_48 -> V_107 ) > V_48 -> V_105 ) {
F_15 ( V_14 -> V_4 , V_48 -> V_44 ,
V_183 ) ;
F_85 ( V_14 , & V_112 ) ;
F_19 ( V_14 ) ;
}
}
F_84 ( & V_174 , V_12 ) ;
F_91 ( & V_184 , V_108 + ( V_106 * 2 ) ) ;
}
static int T_6 F_92 ( void )
{
int error ;
struct V_61 sin ;
F_93 ( & V_112 ) ;
F_94 ( & V_184 , F_89 , 0 ) ;
V_184 . V_121 = V_108 + ( V_106 * 2 ) ;
F_51 ( & V_184 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_91 = F_35 ( V_92 ) ;
error = F_95 ( V_185 , V_81 , 0 , & V_87 ) ;
if ( error < 0 ) {
F_87 ( L_8 , - error ) ;
return error ;
}
V_87 -> V_4 -> V_136 = 1 ;
V_87 -> V_4 -> V_186 = V_46 ;
error = V_87 -> V_137 -> V_187 ( V_87 , (struct V_31 * ) & sin ,
sizeof( sin ) ) ;
if ( error < 0 ) {
F_87 ( L_9 , - error ) ;
goto V_188;
}
V_87 -> V_4 -> V_189 = F_86 ;
return 0 ;
V_188:
F_96 ( V_87 ) ;
V_87 = NULL ;
return error ;
}
static int F_97 ( struct V_13 * V_14 , struct V_51 * V_52 ,
struct V_190 * V_191 , struct V_51 * V_192 )
{
struct V_79 * V_193 ;
struct V_3 * V_4 = NULL ;
struct V_146 * V_147 = V_52 -> V_155 ;
if ( ! F_56 ( F_98 ( V_52 ) , & V_127 ) )
goto V_194;
if ( V_14 -> V_195 == V_196 )
goto V_194;
if ( ! V_147 )
goto V_194;
V_14 = F_99 ( V_14 , V_46 ) ;
if ( V_14 == NULL )
return V_197 ;
if ( ! F_100 ( V_14 , sizeof( struct V_79 ) ) )
goto V_194;
V_193 = (struct V_79 * ) V_14 -> V_25 ;
if ( V_193 -> V_40 == V_198 ) {
V_14 -> V_82 = F_35 ( V_199 ) ;
F_101 ( V_14 , sizeof( struct V_79 ) ) ;
F_102 ( V_14 ) ;
return V_200 ;
}
V_4 = F_69 ( V_193 -> V_40 , V_193 -> V_201 , V_193 -> V_202 ) ;
if ( ! V_4 )
goto V_194;
if ( F_74 ( V_4 , V_14 , V_147 -> V_43 , V_193 -> V_201 , V_193 -> V_30 ,
V_193 -> V_40 ) )
goto V_194;
F_80 ( V_4 ) ;
return V_200 ;
V_194:
if ( V_4 )
F_80 ( V_4 ) ;
F_19 ( V_14 ) ;
return V_197 ;
}
static void F_103 ( void )
{
F_104 ( & V_203 ) ;
}
static int F_105 ( struct V_204 * V_205 , unsigned long V_10 ,
void * V_25 )
{
struct V_51 * V_52 = V_25 ;
struct V_146 * V_147 ;
if ( ! F_56 ( F_98 ( V_52 ) , & V_127 ) )
return V_206 ;
switch ( V_10 ) {
case V_207 :
V_147 = V_52 -> V_155 ;
if ( V_147 ) {
if ( V_67 [ 0 ] == V_52 )
V_67 [ 0 ] = NULL ;
V_67 [ V_147 -> V_43 ] = NULL ;
F_106 ( V_147 ) ;
V_52 -> V_155 = NULL ;
}
break;
}
return V_206 ;
}
static void T_7 F_107 ( void )
{
#ifdef V_54
F_108 ( & V_184 ) ;
if ( V_87 )
F_96 ( V_87 ) ;
#endif
F_109 ( & V_208 ) ;
#ifdef V_55
F_110 ( & V_203 ) ;
#endif
F_111 ( V_209 . V_210 ) ;
F_112 ( & V_135 ) ;
}
static int T_6 F_113 ( void )
{
int V_16 = F_114 ( & V_135 , 0 ) ;
if ( V_16 != 0 )
goto V_21;
F_115 ( & V_209 ) ;
#ifdef V_54
F_92 () ;
#endif
#ifdef V_55
F_103 () ;
#endif
F_116 ( & V_208 ) ;
V_21:
return V_16 ;
}
