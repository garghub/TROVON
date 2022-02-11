static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 [ 2 ] , V_5 ;
T_2 V_6 ;
int V_7 , V_8 ;
V_4 [ 0 ] = 0xc0000000 ;
V_4 [ 1 ] = 0x40000000 ;
V_5 = 0xffffffff ;
V_7 = 128 ;
V_3 -> V_9 = V_2 -> V_10 + V_11 ;
V_3 -> V_12 = V_2 -> V_10 + V_13 ;
V_3 -> V_14 = V_2 -> V_10 + V_15 ;
V_3 -> V_16 = V_2 -> V_10 + V_17 ;
V_3 -> V_18 = V_2 -> V_19 + 0x410000UL ;
F_2 ( ~ ( T_2 ) 0 , V_3 -> V_16 ) ;
V_8 = F_3 ( V_3 , V_7 * 8 * 1024 , V_4 [ 0 ] , V_5 ,
V_2 -> V_20 ) ;
if ( V_8 )
return V_8 ;
F_2 ( F_4 ( V_3 -> V_21 ) | 0x7UL , V_3 -> V_12 ) ;
V_6 = F_5 ( V_3 -> V_9 ) ;
V_6 |= ( 0x00000400 |
0x00000300 |
0x00000002 |
0x00000001 ) ;
F_2 ( V_6 , V_3 -> V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long * V_23 )
{
* V_23 = F_5 ( V_2 -> V_10 + F_7 ( V_22 ) ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long * V_23 , unsigned long * V_24 )
{
unsigned long V_25 , type , V_26 ;
struct V_27 * V_28 , * V_29 ;
V_28 = ( V_2 -> V_30 + ( ( V_22 - V_2 -> V_31 ) * 8192 ) ) ;
V_29 = & V_28 [ * V_23 ] ;
if ( ( V_29 -> V_32 & V_33 ) == 0 )
return 0 ;
V_25 = ( ( V_29 -> V_32 & V_33 ) >>
V_34 ) ;
type = ( V_25 >> 3 ) ;
if ( F_9 ( type != V_35 &&
type != V_36 ) )
return - V_37 ;
* V_24 = V_26 = ( ( V_29 -> V_32 & V_38 ) >>
V_39 ) ;
F_2 ( V_40 , V_2 -> V_10 + F_10 ( V_26 ) ) ;
V_29 -> V_32 &= ~ V_33 ;
( * V_23 ) ++ ;
if ( * V_23 >= V_2 -> V_41 )
* V_23 = 0 ;
return 1 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_23 )
{
F_2 ( V_23 , V_2 -> V_10 + F_7 ( V_22 ) ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_22 ,
unsigned long V_24 , int V_42 )
{
T_2 V_43 ;
V_43 = F_5 ( V_2 -> V_10 + F_13 ( V_24 ) ) ;
V_43 &= ~ ( V_44 ) ;
V_43 |= V_22 ;
F_2 ( V_43 , V_2 -> V_10 + F_13 ( V_24 ) ) ;
F_2 ( V_40 , V_2 -> V_10 + F_10 ( V_24 ) ) ;
V_43 = F_5 ( V_2 -> V_10 + F_13 ( V_24 ) ) ;
V_43 |= V_45 ;
F_2 ( V_43 , V_2 -> V_10 + F_13 ( V_24 ) ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned long V_24 )
{
T_2 V_43 ;
V_43 = F_5 ( V_2 -> V_10 + F_13 ( V_24 ) ) ;
V_43 &= ~ V_45 ;
F_2 ( V_43 , V_2 -> V_10 + F_13 ( V_24 ) ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_46 , V_47 , V_48 ;
V_47 = F_16 ( 512 * 1024 ) ;
V_46 = F_17 ( V_49 | V_50 , V_47 ) ;
if ( V_46 == 0UL ) {
F_18 ( V_51 L_1 ,
V_47 ) ;
return - V_52 ;
}
memset ( ( char * ) V_46 , 0 , V_53 << V_47 ) ;
V_2 -> V_30 = ( void * ) V_46 ;
F_2 ( ( V_54 |
F_4 ( V_2 -> V_30 ) ) ,
V_2 -> V_10 + V_55 ) ;
F_2 ( V_2 -> V_56 << 6 , V_2 -> V_10 + V_57 ) ;
F_2 ( 0 , V_2 -> V_10 + V_58 ) ;
F_2 ( V_2 -> V_59 , V_2 -> V_10 + V_60 ) ;
F_2 ( V_2 -> V_61 , V_2 -> V_10 + V_62 ) ;
for ( V_48 = 0 ; V_48 < V_2 -> V_63 ; V_48 ++ ) {
F_2 ( 0 , V_2 -> V_10 + F_7 ( V_48 ) ) ;
F_2 ( 0 , V_2 -> V_10 + F_19 ( V_48 ) ) ;
}
return 0 ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_46 , V_47 ;
V_47 = F_16 ( 512 * 1024 ) ;
V_46 = ( unsigned long ) V_2 -> V_30 ;
F_21 ( V_46 , V_47 ) ;
V_2 -> V_30 = NULL ;
}
static int F_22 ( struct V_1 * V_2 ,
unsigned long V_22 ,
unsigned long V_64 )
{
unsigned long V_65 = ( unsigned long ) V_2 -> V_10 ;
unsigned long V_66 , V_67 , V_68 ;
unsigned int V_69 ;
int V_70 ;
T_2 V_43 ;
V_66 = V_65 + ( 0x001000UL + ( V_64 * 0x08UL ) ) ;
V_67 = V_65 + ( 0x001400UL + ( V_64 * 0x08UL ) ) ;
V_68 = ( 1UL << 6 ) ;
V_43 = F_5 ( V_66 ) ;
V_43 |= ( 1UL << 63 ) | V_68 ;
F_2 ( V_43 , V_66 ) ;
V_70 = ( ( V_2 -> V_56 << 6 ) | V_64 ) - V_68 ;
V_69 = F_23 ( V_70 , V_67 , V_66 ) ;
if ( ! V_69 )
return - V_52 ;
F_2 ( V_71 ,
V_2 -> V_10 + F_24 ( V_22 ) ) ;
return V_69 ;
}
static void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 , & V_72 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
}
static void F_27 ( struct V_1 * V_2 )
{
T_2 V_43 ;
F_2 ( V_73 ,
V_2 -> V_19 + V_74 ) ;
F_2 ( ( V_75 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 |
V_82 ) ,
V_2 -> V_19 + V_83 ) ;
F_2 ( ~ ( T_2 ) 0 , V_2 -> V_19 + V_84 ) ;
V_43 = F_5 ( V_2 -> V_10 + V_85 ) ;
V_43 |= ( V_86 |
V_87 |
V_88 ) ;
F_2 ( V_43 , V_2 -> V_10 + V_85 ) ;
F_2 ( 0 , V_2 -> V_10 + V_89 ) ;
F_2 ( V_90 ,
V_2 -> V_10 + V_91 ) ;
F_2 ( 0 , V_2 -> V_10 + V_92 ) ;
F_2 ( V_93 , V_2 -> V_10 + V_94 ) ;
F_2 ( ( V_95 | V_96 ) ,
V_2 -> V_10 + V_97 ) ;
F_2 ( ( ( 0xffff << 16 ) | ( 0x0000 << 0 ) ) ,
V_2 -> V_10 + V_98 ) ;
F_2 ( 3000000 , V_2 -> V_10 + V_99 ) ;
F_2 ( 500000 , V_2 -> V_10 + V_100 ) ;
F_2 ( ( 2 << 16 ) | ( 140 << 8 ) ,
V_2 -> V_10 + V_101 ) ;
F_2 ( 0 , V_2 -> V_10 + V_102 ) ;
F_2 ( ~ ( T_2 ) 0 , V_2 -> V_10 + V_103 ) ;
F_2 ( 0 , V_2 -> V_10 + V_104 ) ;
F_2 ( 0 , V_2 -> V_10 + V_105 ) ;
F_2 ( ~ ( T_2 ) 0 , V_2 -> V_10 + V_106 ) ;
}
static int T_3 F_28 ( struct V_1 * V_2 ,
struct V_107 * V_108 , T_1 V_56 )
{
const struct V_109 * V_110 ;
struct V_111 * V_112 = V_108 -> V_113 . V_114 ;
int V_8 ;
V_2 -> V_20 = - 1 ;
V_2 -> V_115 = & V_116 ;
V_2 -> V_117 = 12 ;
V_2 -> V_118 = V_119 ++ ;
V_2 -> V_56 = V_56 ;
V_2 -> V_108 = V_108 ;
V_2 -> V_120 = V_112 -> V_121 ;
V_110 = F_29 ( V_112 , L_2 , NULL ) ;
V_2 -> V_10 = V_110 [ 0 ] . V_122 ;
V_2 -> V_19 = V_110 [ 1 ] . V_122 - 0x410000UL ;
F_18 ( L_3 , V_2 -> V_120 ) ;
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_27 ( V_2 ) ;
V_8 = F_1 ( V_2 ) ;
if ( V_8 )
return V_8 ;
F_25 ( V_2 ) ;
V_2 -> V_123 = F_32 ( V_2 , & V_108 -> V_113 ) ;
V_2 -> V_124 = V_125 ;
V_125 = V_2 ;
return 0 ;
}
static int T_3 F_33 ( struct V_107 * V_108 )
{
struct V_111 * V_112 = V_108 -> V_113 . V_114 ;
struct V_1 * V_2 ;
struct V_3 * V_3 ;
T_1 V_56 ;
int V_8 ;
V_56 = F_34 ( V_112 , L_4 , 0xff ) ;
V_8 = - V_52 ;
V_2 = F_35 ( sizeof( * V_2 ) , V_49 ) ;
if ( ! V_2 ) {
F_18 (KERN_ERR PFX L_5 ) ;
goto V_126;
}
V_3 = F_35 ( sizeof( struct V_3 ) , V_49 ) ;
if ( ! V_3 ) {
F_18 (KERN_ERR PFX L_6 ) ;
goto V_127;
}
V_2 -> V_3 = V_3 ;
V_8 = F_28 ( V_2 , V_108 , V_56 ) ;
if ( V_8 )
goto V_128;
F_36 ( & V_108 -> V_113 , V_2 ) ;
return 0 ;
V_128:
F_37 ( V_2 -> V_3 ) ;
V_127:
F_37 ( V_2 ) ;
V_126:
return V_8 ;
}
static int T_4 F_38 ( void )
{
return F_39 ( & V_129 ) ;
}
