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
if( V_14 == NULL )
goto V_21;
V_15 = V_14 -> V_11 ;
if ( V_15 > V_11 )
{
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
static int F_13 ( struct V_8 * V_3 , struct V_31 * V_32 , int V_33 )
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
if ( V_14 == NULL )
{
F_17 ( V_49 L_1 ) ;
return;
}
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_34 = (struct V_18 * ) & V_48 -> V_34 ;
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_44 = V_44 ;
V_34 -> type = V_50 | V_45 ;
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
struct V_18 * V_51 = (struct V_18 * ) V_10 -> V_29 ;
struct V_52 * V_53 ;
struct V_54 V_42 ;
int V_16 ;
unsigned char V_40 , V_30 ;
#if F_22 ( V_55 ) || F_22 ( V_56 )
struct V_3 * V_4 = V_3 -> V_4 ;
struct V_13 * V_14 ;
struct V_47 * V_48 ;
#endif
#ifdef V_55
struct V_9 V_57 ;
struct V_58 V_59 [ 2 ] ;
struct V_60 V_61 ;
struct V_62 V_63 ;
T_2 V_64 ;
T_3 V_65 ;
char * V_66 ;
#endif
if ( V_10 -> V_22 & ~ ( V_20 | V_67 ) )
return - V_39 ;
F_8 ( & V_19 ) ;
if ( V_51 == NULL || V_10 -> V_17 < sizeof( struct V_18 ) ) {
F_12 ( & V_19 ) ;
return - V_39 ;
}
V_42 . V_41 = V_51 -> V_42 . V_41 ;
V_42 . V_43 = V_51 -> V_42 . V_43 ;
V_40 = V_51 -> V_40 ;
V_30 = V_51 -> V_30 ;
V_53 = V_68 [ V_42 . V_43 ] ;
if ( V_53 == NULL ) {
V_53 = V_68 [ 0 ] ;
if ( V_53 == NULL ) {
F_12 ( & V_19 ) ;
return - V_69 ;
}
}
if ( V_53 -> type == V_70 ) {
#ifdef V_56
unsigned short V_71 = 0 ;
int V_72 ;
if ( V_11 + 15 > V_53 -> V_73 ) {
F_12 ( & V_19 ) ;
return - V_74 ;
}
F_23 ( V_53 ) ;
V_14 = F_24 ( V_4 , V_11 + F_25 ( V_53 ) ,
V_10 -> V_22 & V_20 , & V_16 ) ;
if ( V_14 == NULL )
goto V_75;
F_26 ( V_14 , F_27 ( V_53 ) ) ;
F_28 ( V_14 ) ;
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_48 -> V_44 = V_51 -> V_44 ;
V_48 -> V_34 = * V_51 ;
V_48 -> V_76 = F_20 ;
V_16 = - V_39 ;
V_72 = F_29 ( V_14 , V_53 , F_30 ( V_71 ) , & V_42 , NULL , V_11 ) ;
if ( V_72 < 0 )
goto V_26;
if ( V_72 > 0 ) {
struct V_77 * V_78 ;
V_78 = (struct V_77 * ) ( V_14 -> V_25 ) ;
V_78 -> V_30 = V_30 ;
V_78 -> V_40 = V_40 ;
if ( V_3 -> type != V_79 ) {
F_31 ( V_14 ) ;
V_14 -> V_11 = 0 ;
}
}
V_16 = F_32 ( F_33 ( V_14 , V_11 ) , V_10 -> V_24 , V_11 ) ;
V_14 -> V_80 = V_71 ;
V_14 -> V_53 = V_53 ;
V_14 -> V_81 = V_4 -> V_82 ;
if ( V_16 )
goto V_26;
V_16 = - V_69 ;
if ( ! ( V_53 -> V_12 & V_83 ) )
goto V_26;
F_34 ( V_14 ) ;
F_35 ( V_53 ) ;
F_12 ( & V_19 ) ;
return V_11 ;
V_26:
F_19 ( V_14 ) ;
V_75:
if ( V_53 )
F_35 ( V_53 ) ;
#else
V_16 = - V_84 ;
#endif
F_12 ( & V_19 ) ;
return V_16 ;
}
#ifdef V_55
if ( V_85 == NULL ) {
F_12 ( & V_19 ) ;
return - V_69 ;
}
if ( V_11 > 32768 ) {
V_16 = - V_86 ;
goto error;
}
memset ( & V_63 , 0 , sizeof( V_63 ) ) ;
V_63 . V_87 = V_88 ;
V_63 . V_89 = F_36 ( V_90 ) ;
{
struct V_91 * V_92 ;
unsigned long V_93 = 0 ;
F_37 () ;
V_92 = F_38 ( V_53 ) ;
if ( V_92 ) {
if ( V_92 -> V_94 )
V_93 = F_39 ( V_92 -> V_94 -> V_95 ) &
0xffffff00 ;
}
F_40 () ;
V_63 . V_96 . V_97 = F_41 ( V_93 | V_42 . V_41 ) ;
}
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
V_61 . V_40 = V_40 ;
V_61 . V_30 = V_30 & 0x7f ;
V_61 . V_98 = 2 ;
V_64 = sizeof( struct V_60 ) ;
V_59 [ 0 ] . V_99 = ( void * ) & V_61 ;
V_59 [ 0 ] . V_100 = V_64 ;
V_66 = F_42 ( V_11 ) ;
if ( V_66 == NULL ) {
V_16 = - V_101 ;
goto error;
}
V_59 [ 1 ] . V_99 = V_66 ;
V_59 [ 1 ] . V_100 = V_11 ;
V_16 = F_32 ( V_66 , V_10 -> V_24 , V_11 ) ;
if ( V_16 )
goto V_102;
if ( ( V_14 = F_24 ( V_4 , 0 ,
V_10 -> V_22 & V_20 ,
& V_16 ) ) == NULL )
goto V_102;
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
V_48 -> V_44 = V_51 -> V_44 ;
V_48 -> V_103 = ( 5 * V_104 ) ;
V_48 -> V_105 = V_106 ;
V_61 . V_107 = V_108 ;
V_48 -> V_109 = ( V_108 ++ ) ;
V_48 -> V_34 = * V_51 ;
F_43 ( & V_110 , V_14 ) ;
V_57 . V_29 = ( void * ) & V_63 ;
V_57 . V_17 = sizeof( V_63 ) ;
V_57 . V_24 = & V_59 [ 0 ] ;
V_57 . V_111 = 2 ;
V_57 . V_112 = NULL ;
V_57 . V_113 = 0 ;
V_57 . V_22 = 0 ;
V_65 = F_44 () ; F_45 ( V_114 ) ;
V_16 = F_46 ( V_85 , & V_57 , V_64 ) ;
F_45 ( V_65 ) ;
V_102:
F_47 ( V_66 ) ;
error:
#else
V_16 = - V_84 ;
#endif
F_12 ( & V_19 ) ;
return V_16 ;
}
static int F_48 ( struct V_8 * V_3 , struct V_31 * V_32 ,
int * V_115 , int V_116 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
struct V_18 * V_34 = (struct V_18 * ) V_32 ;
if ( V_116 )
return - V_117 ;
memset ( V_34 , 0 , sizeof( * V_34 ) ) ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
V_36 = F_14 ( V_4 ) ;
V_34 -> V_37 = V_38 ;
V_34 -> V_40 = V_36 -> V_40 ;
V_34 -> V_42 . V_41 = V_36 -> V_41 ;
V_34 -> V_42 . V_43 = V_36 -> V_43 ;
F_12 ( & V_19 ) ;
* V_115 = sizeof( * V_34 ) ;
return 0 ;
}
static void F_49 ( unsigned long V_25 )
{
struct V_3 * V_4 = (struct V_3 * ) V_25 ;
if ( ! F_50 ( V_4 ) ) {
F_51 ( V_4 ) ;
return;
}
V_4 -> V_118 . V_119 = V_106 + 10 * V_104 ;
F_52 ( & V_4 -> V_118 ) ;
F_17 ( V_49 L_2 ) ;
}
static int F_53 ( struct V_8 * V_3 )
{
struct V_3 * V_4 ;
F_8 ( & V_19 ) ;
V_4 = V_3 -> V_4 ;
if ( ! V_4 )
goto V_75;
F_1 ( & V_120 , V_4 ) ;
V_4 -> V_121 ( V_4 ) ;
F_54 ( V_4 ) ;
F_55 ( & V_4 -> V_122 ) ;
if ( F_50 ( V_4 ) ) {
V_4 -> V_118 . V_25 = ( unsigned long ) V_4 ;
V_4 -> V_118 . V_119 = V_106 + V_104 ;
V_4 -> V_118 . V_123 = F_49 ;
F_52 ( & V_4 -> V_118 ) ;
goto V_75;
}
F_51 ( V_4 ) ;
V_75:
F_12 ( & V_19 ) ;
return 0 ;
}
static int F_56 ( struct V_43 * V_43 , struct V_8 * V_3 , int V_80 ,
int V_124 )
{
struct V_3 * V_4 ;
struct V_35 * V_36 ;
int V_16 ;
if ( ! F_57 ( V_43 , & V_125 ) )
return - V_126 ;
if ( V_3 -> type != V_79 )
return - V_127 ;
V_3 -> V_128 = V_129 ;
V_16 = - V_130 ;
V_4 = F_58 ( V_43 , V_131 , V_132 , & V_133 ) ;
if ( V_4 == NULL )
goto V_21;
V_4 -> V_134 = 1 ;
V_3 -> V_135 = & V_136 ;
F_59 ( V_3 , V_4 ) ;
V_36 = F_14 ( V_4 ) ;
F_60 ( V_4 , V_137 ) ;
V_4 -> V_138 = V_131 ;
V_36 -> V_139 = V_80 ;
F_5 ( & V_120 , V_4 ) ;
return 0 ;
V_21:
return V_16 ;
}
static int F_61 ( struct V_8 * V_3 , unsigned int V_140 , void T_4 * V_141 )
{
struct V_142 V_143 ;
struct V_144 * V_145 ;
struct V_52 * V_53 ;
struct V_18 * V_34 ;
int V_16 ;
if ( F_62 ( & V_143 , V_141 , sizeof( struct V_142 ) ) )
return - V_146 ;
if ( ( V_53 = F_63 ( & V_125 , V_143 . V_147 ) ) == NULL )
return - V_148 ;
V_34 = (struct V_18 * ) & V_143 . V_149 ;
F_8 ( & V_19 ) ;
V_16 = 0 ;
switch ( V_140 ) {
case V_150 :
if ( ! F_64 ( V_151 ) ) {
V_16 = - V_152 ;
break;
}
V_145 = V_53 -> V_153 ;
if ( V_145 == NULL ) {
V_145 = F_65 ( sizeof( struct V_144 ) , V_132 ) ;
if ( V_145 == NULL ) {
V_16 = - V_101 ;
break;
}
V_53 -> V_153 = V_145 ;
} else
V_68 [ V_145 -> V_43 ] = NULL ;
V_145 -> V_41 = V_34 -> V_42 . V_41 ;
V_145 -> V_43 = V_34 -> V_42 . V_43 ;
V_68 [ V_34 -> V_42 . V_43 ] = V_53 ;
if ( ! V_68 [ 0 ] )
V_68 [ 0 ] = V_53 ;
break;
case V_154 :
V_145 = V_53 -> V_153 ;
if ( V_145 == NULL ) {
V_16 = - V_148 ;
break;
}
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_42 . V_41 = V_145 -> V_41 ;
V_34 -> V_42 . V_43 = V_145 -> V_43 ;
V_34 -> V_37 = V_38 ;
F_35 ( V_53 ) ;
if ( F_66 ( V_141 , & V_143 , sizeof( struct V_142 ) ) )
V_16 = - V_146 ;
break;
default:
V_16 = - V_39 ;
break;
}
F_12 ( & V_19 ) ;
F_35 ( V_53 ) ;
return V_16 ;
}
static int F_67 ( struct V_8 * V_3 , unsigned int V_140 , unsigned long V_141 )
{
struct V_3 * V_4 = V_3 -> V_4 ;
void T_4 * V_155 = ( void T_4 * ) V_141 ;
switch( V_140 ) {
case V_156 :
return F_68 ( V_4 , V_155 ) ;
case V_157 :
return F_69 ( V_4 , V_155 ) ;
case V_150 :
case V_154 :
return F_61 ( V_3 , V_140 , V_155 ) ;
break;
default:
return - V_158 ;
}
return 0 ;
}
static struct V_3 * F_70 ( unsigned char V_40 , unsigned char
V_41 , unsigned char V_43 )
{
struct V_3 * V_4 ;
struct V_159 * V_160 ;
F_71 ( & V_5 ) ;
F_72 (sk, node, &econet_sklist) {
struct V_35 * V_161 = F_14 ( V_4 ) ;
if ( ( V_161 -> V_40 == V_40 || V_161 -> V_40 == 0 ) &&
( V_161 -> V_41 == V_41 || V_161 -> V_41 == 0 ) &&
( V_161 -> V_43 == V_43 || V_161 -> V_43 == 0 ) ) {
F_73 ( V_4 ) ;
goto V_162;
}
}
V_4 = NULL ;
V_162:
F_74 ( & V_5 ) ;
return V_4 ;
}
static int F_75 ( struct V_3 * V_4 , struct V_13 * V_14 ,
unsigned char V_163 , unsigned char V_43 ,
unsigned char V_30 , unsigned char V_40 )
{
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
struct V_18 * V_34 = (struct V_18 * ) & V_48 -> V_34 ;
memset ( V_34 , 0 , sizeof( struct V_18 ) ) ;
V_34 -> V_37 = V_38 ;
V_34 -> type = V_164 ;
V_34 -> V_40 = V_40 ;
V_34 -> V_30 = V_30 ;
V_34 -> V_42 . V_43 = V_43 ;
V_34 -> V_42 . V_41 = V_163 ;
return F_18 ( V_4 , V_14 ) ;
}
static void F_76 ( T_5 V_42 , unsigned long V_109 , int V_98 , int V_30 )
{
struct V_62 sin = {
. V_87 = V_88 ,
. V_89 = F_36 ( V_90 ) ,
. V_96 = { . V_97 = V_42 }
} ;
struct V_60 V_61 = { . V_98 = V_98 , . V_30 = V_30 , . V_107 = V_109 } ;
struct V_165 V_59 = { . V_99 = ( void * ) & V_61 , . V_100 = sizeof( V_61 ) } ;
struct V_9 V_57 ;
V_57 . V_29 = ( void * ) & sin ;
V_57 . V_17 = sizeof( sin ) ;
V_57 . V_112 = NULL ;
V_57 . V_113 = 0 ;
V_57 . V_22 = 0 ;
F_77 ( V_85 , & V_57 , & V_59 , 1 , sizeof( V_61 ) ) ;
}
static void F_78 ( struct V_13 * V_14 , struct V_60 * V_61 , T_1 V_11 )
{
struct V_166 * V_167 = F_79 ( V_14 ) ;
unsigned char V_163 = F_39 ( V_167 -> V_51 ) & 0xff ;
struct V_168 * V_169 = F_80 ( V_14 ) ;
struct V_144 * V_145 = NULL ;
struct V_3 * V_4 = NULL ;
struct V_13 * V_170 ;
if ( V_169 )
V_145 = V_169 -> V_53 -> V_153 ;
if ( ! V_145 )
goto V_171;
if ( ( V_4 = F_70 ( V_61 -> V_40 , V_163 , V_145 -> V_43 ) ) == NULL )
goto V_171;
V_170 = F_16 ( ( V_11 - sizeof( struct V_60 ) + 15 ) & ~ 15 ,
V_46 ) ;
if ( V_170 == NULL )
{
F_17 ( V_49 L_3 ) ;
goto V_171;
}
memcpy ( F_33 ( V_170 , V_11 - sizeof( struct V_60 ) ) , ( void * ) ( V_61 + 1 ) ,
V_11 - sizeof( struct V_60 ) ) ;
if ( F_75 ( V_4 , V_170 , V_163 , V_145 -> V_43 , V_61 -> V_30 , V_61 -> V_40 ) )
{
F_19 ( V_170 ) ;
goto V_171;
}
F_76 ( V_167 -> V_51 , V_61 -> V_107 , 3 , 0 ) ;
F_81 ( V_4 ) ;
return;
V_171:
F_76 ( V_167 -> V_51 , V_61 -> V_107 , 4 , 0 ) ;
if ( V_4 )
F_81 ( V_4 ) ;
}
static void F_82 ( unsigned long V_109 , int V_45 )
{
struct V_13 * V_14 ;
unsigned long V_12 ;
struct V_47 * V_48 ;
F_83 ( & V_172 , V_12 ) ;
F_84 (&aun_queue, skb) {
V_48 = (struct V_47 * ) & V_14 -> V_30 ;
if ( V_48 -> V_109 == V_109 )
goto V_173;
}
F_85 ( & V_172 , V_12 ) ;
F_17 ( V_49 L_4 , V_109 ) ;
return;
V_173:
F_15 ( V_14 -> V_4 , V_48 -> V_44 , V_45 ) ;
F_86 ( V_14 , & V_110 ) ;
F_85 ( & V_172 , V_12 ) ;
F_19 ( V_14 ) ;
}
static void F_87 ( struct V_3 * V_4 , int V_174 )
{
int V_16 ;
struct V_13 * V_14 ;
unsigned char * V_25 ;
struct V_60 * V_61 ;
T_1 V_11 ;
while ( ( V_14 = F_9 ( V_4 , 0 , 1 , & V_16 ) ) == NULL ) {
if ( V_16 == - V_175 ) {
F_17 ( V_176 L_5 ) ;
return;
}
F_17 ( V_49 L_6 , - V_16 ) ;
}
V_25 = F_88 ( V_14 ) + sizeof( struct V_177 ) ;
V_61 = (struct V_60 * ) V_25 ;
V_11 = V_14 -> V_11 - sizeof( struct V_177 ) ;
switch ( V_61 -> V_98 )
{
case 2 :
F_78 ( V_14 , V_61 , V_11 ) ;
break;
case 3 :
F_82 ( V_61 -> V_107 , V_178 ) ;
break;
case 4 :
F_82 ( V_61 -> V_107 , V_179 ) ;
break;
default:
F_17 ( V_49 L_7 , V_25 [ 0 ] ) ;
}
F_11 ( V_4 , V_14 ) ;
}
static void F_89 ( unsigned long V_180 )
{
struct V_13 * V_14 , * V_181 ;
unsigned long V_12 ;
F_83 ( & V_172 , V_12 ) ;
F_90 (&aun_queue, skb, n) {
struct V_47 * V_48 = (struct V_47 * ) & V_14 -> V_30 ;
if ( ( V_106 - V_48 -> V_105 ) > V_48 -> V_103 ) {
F_15 ( V_14 -> V_4 , V_48 -> V_44 ,
V_182 ) ;
F_86 ( V_14 , & V_110 ) ;
F_19 ( V_14 ) ;
}
}
F_85 ( & V_172 , V_12 ) ;
F_91 ( & V_183 , V_106 + ( V_104 * 2 ) ) ;
}
static int T_6 F_92 ( void )
{
int error ;
struct V_62 sin ;
F_93 ( & V_110 ) ;
F_94 ( & V_183 , F_89 , 0 ) ;
V_183 . V_119 = V_106 + ( V_104 * 2 ) ;
F_52 ( & V_183 ) ;
memset ( & sin , 0 , sizeof( sin ) ) ;
sin . V_89 = F_36 ( V_90 ) ;
if ( ( error = F_95 ( V_184 , V_79 , 0 , & V_85 ) ) < 0 )
{
F_17 ( L_8 , - error ) ;
return error ;
}
V_85 -> V_4 -> V_134 = 1 ;
V_85 -> V_4 -> V_185 = V_46 ;
error = V_85 -> V_135 -> V_186 ( V_85 , (struct V_31 * ) & sin ,
sizeof( sin ) ) ;
if ( error < 0 )
{
F_17 ( L_9 , - error ) ;
goto V_187;
}
V_85 -> V_4 -> V_188 = F_87 ;
return 0 ;
V_187:
F_96 ( V_85 ) ;
V_85 = NULL ;
return error ;
}
static int F_97 ( struct V_13 * V_14 , struct V_52 * V_53 , struct V_189 * V_190 , struct V_52 * V_191 )
{
struct V_77 * V_192 ;
struct V_3 * V_4 = NULL ;
struct V_144 * V_145 = V_53 -> V_153 ;
if ( ! F_57 ( F_98 ( V_53 ) , & V_125 ) )
goto V_193;
if ( V_14 -> V_194 == V_195 )
goto V_193;
if ( ! V_145 )
goto V_193;
if ( ( V_14 = F_99 ( V_14 , V_46 ) ) == NULL )
return V_196 ;
if ( ! F_100 ( V_14 , sizeof( struct V_77 ) ) )
goto V_193;
V_192 = (struct V_77 * ) V_14 -> V_25 ;
if ( V_192 -> V_40 == V_197 ) {
V_14 -> V_80 = F_36 ( V_198 ) ;
F_101 ( V_14 , sizeof( struct V_77 ) ) ;
F_102 ( V_14 ) ;
return V_199 ;
}
V_4 = F_70 ( V_192 -> V_40 , V_192 -> V_200 , V_192 -> V_201 ) ;
if ( ! V_4 )
goto V_193;
if ( F_75 ( V_4 , V_14 , V_145 -> V_43 , V_192 -> V_200 , V_192 -> V_30 ,
V_192 -> V_40 ) )
goto V_193;
F_81 ( V_4 ) ;
return V_199 ;
V_193:
if ( V_4 )
F_81 ( V_4 ) ;
F_19 ( V_14 ) ;
return V_196 ;
}
static void F_103 ( void )
{
F_104 ( & V_202 ) ;
}
static int F_105 ( struct V_203 * V_204 , unsigned long V_10 , void * V_25 )
{
struct V_52 * V_53 = (struct V_52 * ) V_25 ;
struct V_144 * V_145 ;
if ( ! F_57 ( F_98 ( V_53 ) , & V_125 ) )
return V_205 ;
switch ( V_10 ) {
case V_206 :
V_145 = V_53 -> V_153 ;
if ( V_145 )
{
if ( V_68 [ 0 ] == V_53 )
V_68 [ 0 ] = NULL ;
V_68 [ V_145 -> V_43 ] = NULL ;
F_106 ( V_145 ) ;
V_53 -> V_153 = NULL ;
}
break;
}
return V_205 ;
}
static void T_7 F_107 ( void )
{
#ifdef V_55
F_108 ( & V_183 ) ;
if ( V_85 )
F_96 ( V_85 ) ;
#endif
F_109 ( & V_207 ) ;
#ifdef V_56
F_110 ( & V_202 ) ;
#endif
F_111 ( V_208 . V_209 ) ;
F_112 ( & V_133 ) ;
}
static int T_6 F_113 ( void )
{
int V_16 = F_114 ( & V_133 , 0 ) ;
if ( V_16 != 0 )
goto V_21;
F_115 ( & V_208 ) ;
#ifdef V_55
F_92 () ;
#endif
#ifdef V_56
F_103 () ;
#endif
F_116 ( & V_207 ) ;
V_21:
return V_16 ;
}
