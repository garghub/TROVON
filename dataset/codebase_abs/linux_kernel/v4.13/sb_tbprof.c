static void F_1 ( void )
{
T_1 V_1 ;
T_1 V_2 = ( 1ULL << 40 ) - V_3 ;
T_1 V_4 = V_5 ;
F_2 ( 0 , F_3 ( V_6 ) ) ;
V_1 = F_4 ( F_3 ( V_7 ) ) ;
#if F_5 ( V_8 ) || F_5 ( V_9 )
F_2 ( ( V_1 & ~ V_10 ) |
F_6 ( 1 ) ,
F_3 ( V_11 ) ) ;
F_2 (
V_12 |
V_13 |
F_6 ( 1 ) ,
F_3 ( V_14 ) ) ;
#else
F_2 ( ( V_1 & ~ V_10 ) |
V_12 |
V_13 |
F_6 ( 1 ) ,
F_3 ( V_7 ) ) ;
#endif
F_2 ( V_2 , F_3 ( V_6 ) ) ;
F_2 ( V_15 , F_3 ( V_16 ) ) ;
#if 0 && F_5 ( V_17 )
tb_options |= M_SCD_TRACE_CFG_FORCECNT;
#endif
F_2 ( V_4 , F_3 ( V_16 ) ) ;
V_18 . V_19 = 1 ;
}
static T_2 F_7 ( int V_20 , void * V_21 )
{
int V_22 ;
F_8 ( V_23 L_1 ) ;
if ( V_18 . V_24 < V_25 ) {
T_1 * V_26 = V_18 . V_27 [ V_18 . V_24 ++ ] ;
F_2 ( V_28 ,
F_3 ( V_16 ) ) ;
__asm__ __volatile__ ("sync" : : : "memory");
for ( V_22 = 256 * 6 ; V_22 > 0 ; V_22 -= 6 ) {
V_26 [ V_22 - 1 ] = F_4 ( F_3 ( V_29 ) ) ;
V_26 [ V_22 - 2 ] = F_4 ( F_3 ( V_29 ) ) ;
V_26 [ V_22 - 3 ] = F_4 ( F_3 ( V_29 ) ) ;
V_26 [ V_22 - 4 ] = F_4 ( F_3 ( V_29 ) ) ;
V_26 [ V_22 - 5 ] = F_4 ( F_3 ( V_29 ) ) ;
V_26 [ V_22 - 6 ] = F_4 ( F_3 ( V_29 ) ) ;
}
if ( ! V_18 . V_30 ) {
F_8 ( V_23 L_2 ) ;
F_2 ( V_15 ,
F_3 ( V_16 ) ) ;
V_18 . V_19 = 0 ;
F_9 ( & V_18 . V_31 ) ;
} else {
F_1 () ;
}
} else {
F_8 ( V_23 L_3 ) ;
F_2 ( V_15 , F_3 ( V_16 ) ) ;
V_18 . V_19 = 0 ;
if ( ! V_18 . V_30 )
F_9 ( & V_18 . V_31 ) ;
F_9 ( & V_18 . V_32 ) ;
}
return V_33 ;
}
static T_2 F_10 ( int V_20 , void * V_21 )
{
F_11 ( V_23 L_4 ) ;
return V_34 ;
}
static int F_12 ( struct V_35 * V_36 )
{
T_1 V_1 ;
int V_37 ;
if ( F_13 ( & V_18 . V_30 , 1 ) )
return - V_38 ;
F_8 ( V_23 L_5 ) ;
V_18 . V_24 = 0 ;
V_36 -> V_39 = 0 ;
V_37 = F_14 ( V_40 , F_7 , 0 ,
V_23 L_6 , & V_18 ) ;
if ( V_37 )
return - V_38 ;
V_1 = F_4 ( F_3 ( V_7 ) ) ;
F_2 ( ( V_1 & ~ ( V_10 | V_12 ) ) |
V_12 | V_13 | F_6 ( 1 ) ,
F_3 ( V_7 ) ) ;
if ( F_14 ( V_41 , F_10 , 0 , V_23 L_7 , & V_18 ) ) {
F_15 ( V_40 , & V_18 ) ;
return - V_38 ;
}
#if F_5 ( V_8 ) || F_5 ( V_9 )
F_2 ( V_42 ,
F_3 ( F_16 ( 0 , V_43 ) +
( ( V_44 & 0x3f ) << 3 ) ) ) ;
#else
F_2 ( V_45 ,
F_3 ( F_17 ( 0 , V_46 ) +
( V_41 << 3 ) ) ) ;
#endif
F_2 ( 0 , F_3 ( V_47 ) ) ;
F_2 ( 0 , F_3 ( V_48 ) ) ;
F_2 ( 0 , F_3 ( V_49 ) ) ;
F_2 ( 0 , F_3 ( V_50 ) ) ;
F_2 ( 0 , F_3 ( V_51 ) ) ;
F_2 ( 0 , F_3 ( V_52 ) ) ;
F_2 ( 0 , F_3 ( V_53 ) ) ;
F_2 ( 0 , F_3 ( V_54 ) ) ;
F_2 ( 0 , F_3 ( V_55 ) ) ;
F_2 ( 0 , F_3 ( V_56 ) ) ;
F_2 ( 0 , F_3 ( V_57 ) ) ;
F_2 ( 0 , F_3 ( V_58 ) ) ;
F_2 ( V_59 , F_3 ( V_60 ) ) ;
F_2 ( 0 , F_3 ( V_61 ) ) ;
F_2 ( 0 , F_3 ( V_62 ) ) ;
F_2 ( 0 , F_3 ( V_63 ) ) ;
F_2 ( 0 , F_3 ( V_64 ) ) ;
F_2 ( 0 , F_3 ( V_65 ) ) ;
F_2 ( 0 , F_3 ( V_66 ) ) ;
F_2 ( 0 , F_3 ( V_67 ) ) ;
F_2 ( V_68 | 0x0fff ,
F_3 ( V_69 ) ) ;
F_2 ( V_70 | V_71 |
V_72 ,
F_3 ( V_73 ) ) ;
F_2 ( 0 , F_3 ( V_74 ) ) ;
F_2 ( 0 , F_3 ( V_75 ) ) ;
F_2 ( 0 , F_3 ( V_76 ) ) ;
F_2 ( 0 , F_3 ( V_77 ) ) ;
F_2 ( 0 , F_3 ( V_78 ) ) ;
F_2 ( 0 , F_3 ( V_79 ) ) ;
#if F_5 ( V_8 ) || F_5 ( V_9 )
F_2 ( 1ULL << ( V_44 & 0x3f ) ,
F_3 ( F_16 ( 0 , V_80 ) ) ) ;
#else
F_2 ( 1ULL << V_41 ,
F_3 ( F_17 ( 0 , V_81 ) ) ) ;
#endif
F_1 () ;
F_8 ( V_23 L_8 ) ;
return 0 ;
}
static int F_18 ( void )
{
int V_37 = 0 ;
F_8 ( V_23 L_9 ) ;
if ( V_18 . V_30 ) {
F_8 ( V_23 L_10 ) ;
V_37 = F_19 ( V_18 . V_31 , ! V_18 . V_19 ) ;
F_8 ( V_23 L_11 , V_37 ) ;
if ( V_37 )
return V_37 ;
V_18 . V_30 = 0 ;
F_15 ( V_40 , & V_18 ) ;
F_15 ( V_41 , & V_18 ) ;
}
F_8 ( V_23 L_12 ) ;
return V_37 ;
}
static int F_20 ( struct V_82 * V_82 , struct V_35 * V_36 )
{
int V_83 ;
V_83 = F_21 ( V_82 ) ;
if ( V_83 != 0 )
return - V_84 ;
if ( F_13 ( & V_18 . V_85 , V_86 ) != V_87 )
return - V_38 ;
memset ( & V_18 , 0 , sizeof( struct V_88 ) ) ;
V_18 . V_27 = F_22 ( V_89 ) ;
if ( ! V_18 . V_27 ) {
V_18 . V_85 = V_87 ;
F_23 () ;
return - V_90 ;
}
F_24 ( & V_18 . V_31 ) ;
F_24 ( & V_18 . V_32 ) ;
F_25 ( & V_18 . V_91 ) ;
V_18 . V_85 = V_92 ;
F_23 () ;
return 0 ;
}
static int F_26 ( struct V_82 * V_82 , struct V_35 * V_36 )
{
int V_83 ;
V_83 = F_21 ( V_82 ) ;
if ( V_83 != 0 || V_18 . V_85 != V_87 )
return - V_84 ;
F_27 ( & V_18 . V_91 ) ;
if ( V_18 . V_19 || V_18 . V_30 )
F_18 () ;
F_28 ( V_18 . V_27 ) ;
V_18 . V_85 = V_87 ;
F_23 () ;
F_29 ( & V_18 . V_91 ) ;
return 0 ;
}
static T_3 F_30 ( struct V_35 * V_36 , char * V_93 ,
T_4 V_94 , T_5 * V_95 )
{
int V_96 , V_97 , V_98 , V_99 ;
char * V_100 ;
int V_101 = 0 ;
char * V_102 = V_93 ;
long V_103 = * V_95 ;
if ( ! F_31 ( V_104 , V_93 , V_94 ) )
return - V_105 ;
F_27 ( & V_18 . V_91 ) ;
V_101 = 0 ;
V_96 = V_103 / V_106 ;
V_97 = V_103 % V_106 ;
V_99 = V_106 - V_97 ;
while ( V_94 && ( V_96 < V_18 . V_24 ) ) {
int V_37 ;
V_98 = V_94 < V_99 ? V_94 : V_99 ;
V_100 = ( char * ) ( ( ( long ) V_18 . V_27 [ V_96 ] ) + V_97 ) ;
V_37 = F_32 ( V_102 , V_100 , V_98 ) ;
if ( V_37 ) {
* V_95 = V_103 + V_98 - V_37 ;
F_29 ( & V_18 . V_91 ) ;
return V_37 ;
}
F_8 ( V_23 L_13 ,
V_96 , V_98 ) ;
V_94 -= V_98 ;
V_99 -= V_98 ;
if ( ! V_99 ) {
V_96 ++ ;
V_97 = 0 ;
V_99 = V_106 ;
} else {
V_97 += V_98 ;
}
V_103 += V_98 ;
V_102 += V_98 ;
V_101 += V_98 ;
}
* V_95 = V_103 ;
F_29 ( & V_18 . V_91 ) ;
return V_101 ;
}
static long F_33 ( struct V_35 * V_36 ,
unsigned int V_107 ,
unsigned long V_108 )
{
int V_37 = 0 ;
switch ( V_107 ) {
case V_109 :
F_27 ( & V_18 . V_91 ) ;
V_37 = F_12 ( V_36 ) ;
F_29 ( & V_18 . V_91 ) ;
break;
case V_110 :
F_27 ( & V_18 . V_91 ) ;
V_37 = F_18 () ;
F_29 ( & V_18 . V_91 ) ;
break;
case V_111 : {
V_37 = F_19 ( V_18 . V_32 , V_112 ) ;
if ( V_37 )
break;
V_37 = F_34 ( V_112 , ( int * ) V_108 ) ;
break;
}
default:
V_37 = - V_113 ;
break;
}
return V_37 ;
}
static int T_6 F_35 ( void )
{
struct V_114 * V_115 ;
struct V_116 * V_117 ;
int V_37 ;
if ( F_36 ( V_118 , V_23 , & V_119 ) ) {
F_11 (KERN_WARNING DEVNAME L_14 ,
SBPROF_TB_MAJOR) ;
return - V_120 ;
}
V_117 = F_37 ( V_121 , L_15 ) ;
if ( F_38 ( V_117 ) ) {
V_37 = F_39 ( V_117 ) ;
goto V_122;
}
V_123 = V_117 ;
V_115 = F_40 ( V_117 , NULL , F_41 ( V_118 , 0 ) , NULL , L_16 ) ;
if ( F_38 ( V_115 ) ) {
V_37 = F_39 ( V_115 ) ;
goto V_124;
}
V_125 = V_115 ;
V_18 . V_85 = V_87 ;
F_23 () ;
V_3 = V_126 * 10000LL ;
F_42 ( V_23 L_17 ,
( long long ) V_3 ) ;
return 0 ;
V_124:
F_43 ( V_123 ) ;
V_122:
F_44 ( V_118 , V_23 ) ;
return V_37 ;
}
static void T_7 F_45 ( void )
{
F_46 ( V_123 , F_41 ( V_118 , 0 ) ) ;
F_44 ( V_118 , V_23 ) ;
F_43 ( V_123 ) ;
}
