static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
for ( V_3 = V_8 ; V_3 ; V_3 = V_3 -> V_9 ) {
V_5 = V_3 -> V_5 ;
V_7 = & V_3 -> V_10 ;
F_2 ( 0 , V_11 ) ;
F_3 ( 1 ) ;
F_4 ( V_12 , ( F_5 ( V_13 ) & 0xff ) |
( ( F_5 ( V_14 ) & 0xff ) << 8 ) ) ;
F_4 ( V_15 , ( F_5 ( V_16 ) & 0xff ) |
( ( F_5 ( V_17 ) & 0xff ) << 8 ) |
( ( F_5 ( V_18 ) & 0xf ) << 16 ) ) ;
F_4 ( V_19 , ( F_5 ( V_20 ) & 0xff ) |
( ( F_5 ( V_21 ) & 0xff ) << 8 ) ) ;
F_4 ( V_22 , ( F_5 ( V_23 ) & 0xff ) |
( ( F_5 ( V_24 ) & 0xff ) << 8 ) |
( ( F_5 ( V_25 ) & 0xf ) << 16 ) ) ;
F_4 ( V_26 , ( F_5 ( V_27 ) & 0xff ) |
( ( F_5 ( V_28 ) & 0xff ) << 8 ) ) ;
F_4 ( V_29 , F_5 ( V_30 ) & 0xff ) ;
F_4 ( V_31 , F_5 ( V_32 ) & 0xff ) ;
F_4 ( V_33 , ( F_5 ( V_34 ) & 0xff ) |
( ( F_5 ( V_35 ) & 0xff ) << 8 ) |
( ( F_5 ( V_36 ) & 7 ) << 16 ) ) ;
F_4 ( V_37 , ( F_5 ( V_38 ) & 0xff ) |
( ( F_5 ( V_39 ) & 0xff ) << 8 ) |
( ( F_5 ( V_40 ) & 7 ) << 16 ) ) ;
}
if ( V_1 ) F_6 ( & V_41 , V_42 + V_43 ) ;
}
static int F_7 ( struct V_4 * V_5 , struct V_10 T_1 * V_44 , int V_45 )
{
struct V_10 V_46 ;
int error = 0 ;
F_8 ( & F_9 ( V_5 ) -> V_10 , & V_46 ) ;
if ( V_44 ) error = F_10 ( V_44 , & V_46 , sizeof( V_46 ) ) ;
if ( V_45 && ! error ) F_11 ( & F_9 ( V_5 ) -> V_10 , & V_46 ) ;
return error ? - V_47 : 0 ;
}
static int F_12 ( struct V_4 * V_5 , void T_1 * V_44 , int V_48 )
{
int V_49 ;
if ( F_13 ( V_49 , ( int T_1 * ) V_44 ) ) return - V_47 ;
F_14 ( V_50 , V_51 , V_52 ) ;
F_14 ( V_53 , V_54 , V_55 ) ;
F_14 ( V_56 , V_57 , V_58 ) ;
F_14 ( V_59 , V_60 , V_61 ) ;
F_14 ( V_62 , V_63 , V_64 ) ;
F_14 ( V_65 , V_57 , V_66 ) ;
F_14 ( V_67 , V_51 , V_68 ) ;
F_14 ( V_69 , V_70 , V_71 ) ;
return F_15 ( V_49 , ( int T_1 * ) V_44 ) ? - V_47 : 0 ;
}
static int F_16 ( struct V_4 * V_5 , void T_1 * V_44 )
{
int V_48 ;
V_48 = 0 ;
if ( F_5 ( V_51 ) & V_52 ) V_48 |= V_50 ;
if ( F_5 ( V_54 ) & V_55 ) V_48 |= V_53 ;
if ( F_5 ( V_57 ) & V_58 ) V_48 |= V_56 ;
if ( F_5 ( V_63 ) & V_64 ) V_48 |= V_62 ;
if ( F_5 ( V_57 ) & V_66 ) V_48 |= V_65 ;
if ( F_5 ( V_51 ) & V_68 ) V_48 |= V_67 ;
if ( F_5 ( V_70 ) & V_71 ) V_48 |= V_69 ;
return F_15 ( V_48 , ( int T_1 * ) V_44 ) ? - V_47 : 0 ;
}
static int F_17 ( struct V_4 * V_5 , int V_72 )
{
unsigned char V_73 ;
int V_74 , V_75 , V_76 ;
if ( F_9 ( V_5 ) -> type == V_77 ) {
V_74 = V_78 ;
V_75 = V_79 ;
V_76 = V_80 ;
} else {
V_74 = V_81 ;
V_75 = V_82 ;
V_76 = V_83 ;
}
V_73 = V_5 -> V_84 -> V_85 ( V_5 , V_74 ) & ~ ( V_75 | V_76 ) ;
switch ( V_72 ) {
case V_86 :
break;
case V_87 :
V_73 |= V_75 ;
break;
case V_88 :
V_73 |= V_76 ;
break;
default:
return - V_89 ;
}
V_5 -> V_84 -> V_90 ( V_5 , V_73 , V_74 ) ;
F_9 ( V_5 ) -> V_91 = V_72 ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
if ( F_9 ( V_5 ) -> type == V_77 ) {
F_2 ( F_5 ( V_92 ) & ~ V_93 , V_92 ) ;
F_2 ( F_5 ( V_94 ) & ~ V_95 , V_94 ) ;
F_2 ( F_5 ( V_96 ) & ~ V_97 , V_96 ) ;
}
F_19 ( V_98 , V_99 ,
V_100 , V_101 ) ;
return 0 ;
}
static int F_20 ( struct V_4 * V_5 )
{
if ( F_9 ( V_5 ) -> type == V_77 ) {
F_2 ( F_5 ( V_92 ) | V_93 , V_92 ) ;
F_2 ( F_5 ( V_94 ) | V_95 , V_94 ) ;
F_2 ( F_5 ( V_96 ) | V_97 , V_96 ) ;
}
F_19 ( V_98 , V_99 ,
V_102 , V_101 ) ;
return 0 ;
}
static int F_21 ( struct V_4 * V_5 , void T_1 * V_44 )
{
int V_103 ;
unsigned char V_104 ;
V_104 = ( F_5 ( V_101 ) & V_98 ) >> V_99 ;
if ( V_104 == V_100 )
V_103 = V_105 ;
else
V_103 = V_106 ;
return F_15 ( V_103 , ( int T_1 * ) V_44 ) ? - V_47 : 0 ;
}
static int F_22 ( struct V_4 * V_5 , void T_1 * V_44 )
{
int V_72 ;
if ( F_13 ( V_72 , ( int T_1 * ) V_44 ) )
return - V_47 ;
if ( V_72 == V_105 )
return F_18 ( V_5 ) ;
else if ( V_72 == V_106 )
return F_20 ( V_5 ) ;
return - V_89 ;
}
static int F_23 ( struct V_4 * V_5 , unsigned int V_107 , void T_1 * V_44 )
{
switch ( V_107 ) {
case V_108 :
case V_109 :
return F_7 ( V_5 , V_44 , V_107 == V_108 ) ;
case V_110 :
return F_12 ( V_5 , V_44 , 1 ) ;
case V_111 :
return F_12 ( V_5 , V_44 , 0 ) ;
case V_112 :
return F_16 ( V_5 , V_44 ) ;
case V_113 :
if ( ! F_24 ( V_114 ) )
return - V_115 ;
return F_22 ( V_5 , V_44 ) ;
case V_116 :
return F_21 ( V_5 , V_44 ) ;
case V_117 :
return - V_89 ;
case V_118 :
if ( ! F_24 ( V_114 ) )
return - V_115 ;
return F_17 ( V_5 , ( int ) ( unsigned long ) V_44 ) ;
case V_119 :
return F_15 ( F_9 ( V_5 ) -> V_91 , ( int T_1 * ) V_44 ) ?
- V_47 : 0 ;
case V_120 :
return F_15 ( V_87 | V_88 ,
( int T_1 * ) V_44 ) ? - V_47 : 0 ;
default:
return - V_121 ;
}
}
static void F_25 ( struct V_4 * V_5 )
{
F_26 ( V_5 ,
F_5 ( V_122 ) & V_123 ?
V_124 : V_125 ) ;
}
static void F_27 ( struct V_4 * V_5 )
{
F_25 ( V_5 ) ;
F_28 ( V_126 L_1 , V_5 -> type , V_5 -> V_127 ,
V_5 -> signal == V_124 ? L_2 : L_3 ) ;
}
static int F_29 ( struct V_4 * V_5 )
{
unsigned long V_128 ;
int V_129 ;
F_30 ( & V_130 , V_128 ) ;
V_129 = ! V_8 ;
F_9 ( V_5 ) -> V_9 = V_8 ;
V_8 = F_9 ( V_5 ) ;
F_31 ( & V_130 , V_128 ) ;
memset ( & F_9 ( V_5 ) -> V_10 , 0 , sizeof( struct V_6 ) ) ;
F_2 ( F_5 ( V_60 ) | V_131 , V_60 ) ;
F_25 ( V_5 ) ;
if ( V_5 -> signal == V_124 )
F_28 ( V_132 L_4 , V_5 -> type ,
V_5 -> V_127 ) ;
F_9 ( V_5 ) -> V_91 = V_86 ;
F_1 ( 0 ) ;
( void ) F_7 ( V_5 , NULL , 1 ) ;
if ( V_129 ) {
F_32 ( & V_41 ) ;
V_41 . V_133 = V_42 + V_43 ;
V_41 . V_134 = F_1 ;
V_41 . V_135 = 1 ;
#if 0
printk(KERN_DEBUG "[u] p=0x%lx,n=0x%lx\n",(unsigned long) poll_timer.list.prev,
(unsigned long) poll_timer.list.next);
#endif
F_33 ( & V_41 ) ;
}
return 0 ;
}
static int F_34 ( struct V_4 * V_5 )
{
struct V_2 * * V_3 ;
unsigned long V_128 ;
F_30 ( & V_130 , V_128 ) ;
for ( V_3 = & V_8 ; * V_3 != F_9 ( V_5 ) ;
V_3 = & F_9 ( ( * V_3 ) -> V_5 ) -> V_9 ) ;
* V_3 = F_9 ( ( * V_3 ) -> V_5 ) -> V_9 ;
if ( ! V_8 ) F_35 ( & V_41 ) ;
F_31 ( & V_130 , V_128 ) ;
F_36 ( F_9 ( V_5 ) ) ;
return 0 ;
}
int F_37 ( struct V_4 * V_5 )
{
unsigned char V_136 ;
if ( ! ( V_5 -> V_137 = F_38 ( sizeof( struct V_2 ) , V_138 ) ) )
return - V_139 ;
F_9 ( V_5 ) -> V_5 = V_5 ;
V_136 = F_5 ( V_11 ) ;
F_9 ( V_5 ) -> type = ( V_136 & V_140 ) >> V_141 ;
F_2 ( V_136 | V_142 , V_11 ) ;
F_2 ( V_136 , V_11 ) ;
F_2 ( ( F_5 ( V_143 ) & V_144 ) , V_143 ) ;
F_18 ( V_5 ) ;
F_19 ( V_145 , 0 , V_145 ,
V_146 ) ;
F_2 ( V_147 , V_148 ) ;
V_5 -> V_149 = & V_150 ;
return 0 ;
}
