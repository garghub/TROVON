static bool F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_8 ;
F_2 ( L_1 ,
V_3 , V_4 , V_6 ) ;
if ( V_3 )
V_4 = F_3 ( V_6 ) ;
V_8 = F_4 ( V_6 , V_3 , V_4 ) ;
if ( V_8 )
return true ;
V_2 -> V_7 = NULL ;
return false ;
}
static void F_5 ( struct V_1 * V_2 , int V_9 )
{
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
if ( V_9 & 8 )
F_6 ( & V_11 -> V_14 , V_15 ) ;
else
F_6 ( & V_11 -> V_16 , V_15 ) ;
F_6 ( & V_11 -> V_12 , V_9 & V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_18 )
{
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
F_5 ( V_2 , V_18 ) ;
F_8 ( 1 ) ;
F_6 ( & V_11 -> V_12 , V_11 -> V_12 | V_19 ) ;
F_8 ( 2 ) ;
F_6 ( & V_11 -> V_12 , V_11 -> V_12 & ~ V_19 ) ;
F_8 ( 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_20 )
{
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
int V_21 ;
F_5 ( V_2 , V_20 ) ;
F_8 ( 1 ) ;
V_21 = F_10 ( & V_11 -> V_22 ) ;
return ( V_21 & V_23 ) == 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
unsigned long V_24 ;
F_2 ( L_2 , V_2 -> V_25 ) ;
if ( V_2 -> V_25 == V_26 && V_2 -> V_27 ) {
V_2 -> V_25 = V_28 ;
F_12 ( & V_2 -> V_29 ) ;
return;
}
while ( V_2 -> V_25 == V_26 ) {
F_2 ( L_3 , V_2 -> V_7 ) ;
if ( ! V_2 -> V_7 ) {
V_2 -> V_7 = F_13 ( V_30 [ V_2 -> V_31 ] -> V_32 ) ;
F_2 ( L_4 , V_2 -> V_7 ) ;
if ( ! V_2 -> V_7 )
break;
}
V_6 = V_2 -> V_7 ;
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 ) {
F_2 ( L_5 , L_6 ) ;
F_1 ( V_2 , - V_36 , 0 ) ;
continue;
}
#if 0
swim3_dbg("do_fd_req: dev=%s cmd=%d sec=%ld nr_sec=%u buf=%p\n",
req->rq_disk->disk_name, req->cmd,
(long)blk_rq_pos(req), blk_rq_sectors(req),
bio_data(req->bio));
swim3_dbg(" current_nr_sectors=%u\n",
blk_rq_cur_sectors(req));
#endif
if ( F_15 ( V_6 ) >= V_2 -> V_37 ) {
F_2 ( L_7 ,
( long ) F_15 ( V_6 ) , ( long ) V_2 -> V_37 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
continue;
}
if ( V_2 -> V_39 ) {
F_2 ( L_5 , L_8 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
continue;
}
if ( F_16 ( V_6 ) == V_40 ) {
if ( V_2 -> V_41 < 0 )
V_2 -> V_41 = F_9 ( V_2 , V_42 ) ;
if ( V_2 -> V_41 ) {
F_2 ( L_5 , L_9 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
continue;
}
}
V_2 -> V_43 = ( ( long ) F_15 ( V_6 ) ) / V_2 -> V_44 ;
V_24 = ( ( long ) F_15 ( V_6 ) ) % V_2 -> V_44 ;
V_2 -> V_45 = V_24 / V_2 -> V_46 ;
V_2 -> V_47 = V_24 % V_2 -> V_46 + 1 ;
V_2 -> V_25 = V_48 ;
V_2 -> V_49 = 0 ;
F_17 ( V_2 ) ;
}
}
static void F_18 ( struct V_50 * V_51 )
{
F_11 ( V_51 -> V_52 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_53 ,
void (* F_20)( unsigned long ) )
{
if ( V_2 -> V_54 )
F_21 ( & V_2 -> V_55 ) ;
V_2 -> V_55 . V_56 = V_57 + V_53 ;
V_2 -> V_55 . V_58 = F_20 ;
V_2 -> V_55 . V_59 = ( unsigned long ) V_2 ;
F_22 ( & V_2 -> V_55 ) ;
V_2 -> V_54 = 1 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
F_5 ( V_2 , V_60 ) ;
F_10 ( & V_11 -> V_61 ) ;
F_10 ( & V_11 -> error ) ;
F_6 ( & V_11 -> V_62 , V_63 ) ;
F_6 ( & V_11 -> V_14 , V_64 ) ;
F_19 ( V_2 , V_65 , V_66 ) ;
}
static inline void F_24 ( struct V_1 * V_2 , int V_67 )
{
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
if ( V_67 >= 0 ) {
F_7 ( V_2 , V_68 ) ;
V_11 -> V_69 = V_67 ;
} else {
F_7 ( V_2 , V_70 ) ;
V_11 -> V_69 = - V_67 ;
}
V_2 -> V_71 = ( V_2 -> V_72 >= 0 ) ? V_2 -> V_72 + V_67 : - 1 ;
F_5 ( V_2 , V_73 ) ;
F_10 ( & V_11 -> error ) ;
F_6 ( & V_11 -> V_62 , V_74 ) ;
F_6 ( & V_11 -> V_14 , V_75 ) ;
F_19 ( V_2 , 3 * V_65 , V_76 ) ;
V_2 -> V_77 = 0 ;
}
static inline void F_25 ( struct V_78 * V_79 , int V_80 ,
void * V_81 , int V_82 )
{
V_79 -> V_83 = F_26 ( V_82 ) ;
V_79 -> V_84 = F_26 ( V_80 ) ;
V_79 -> V_85 = F_27 ( F_28 ( V_81 ) ) ;
V_79 -> V_86 = 0 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
int V_67 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
struct V_78 * V_79 = V_2 -> V_87 ;
struct V_88 T_1 * V_89 = V_2 -> V_90 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_30 ( V_6 ) <= 0 ) {
F_31 ( L_5 , L_10 ) ;
return;
}
if ( F_16 ( V_6 ) == V_40 )
V_67 = 1 ;
else {
V_67 = V_2 -> V_46 - V_2 -> V_47 + 1 ;
if ( V_67 > F_30 ( V_6 ) )
V_67 = F_30 ( V_6 ) ;
}
F_2 ( L_11 ,
V_2 -> V_47 , V_2 -> V_46 , V_2 -> V_45 , V_67 ) ;
V_2 -> V_91 = V_67 ;
F_5 ( V_2 , V_2 -> V_45 ? V_92 : V_60 ) ;
F_6 ( & V_11 -> V_93 , V_2 -> V_47 ) ;
F_6 ( & V_11 -> V_94 , V_67 ) ;
F_6 ( & V_11 -> V_95 , 0 ) ;
F_32 ( & V_89 -> V_96 , F_28 ( V_79 ) ) ;
if ( F_16 ( V_6 ) == V_40 ) {
F_25 ( V_79 , V_97 , V_98 , sizeof( V_98 ) ) ;
++ V_79 ;
F_25 ( V_79 , V_97 , F_33 ( V_6 -> V_99 ) , 512 ) ;
++ V_79 ;
F_25 ( V_79 , V_100 , V_101 , sizeof( V_101 ) ) ;
} else {
F_25 ( V_79 , V_102 , F_33 ( V_6 -> V_99 ) , V_67 * 512 ) ;
}
++ V_79 ;
F_34 ( & V_79 -> V_84 , V_103 ) ;
F_6 ( & V_11 -> V_16 , V_64 | V_104 ) ;
F_10 ( & V_11 -> error ) ;
F_6 ( & V_11 -> V_16 , V_64 | V_104 ) ;
if ( F_16 ( V_6 ) == V_40 )
F_6 ( & V_11 -> V_14 , V_104 ) ;
F_10 ( & V_11 -> V_61 ) ;
F_32 ( & V_89 -> V_105 , ( V_106 << 16 ) | V_106 ) ;
F_6 ( & V_11 -> V_62 , V_107 ) ;
F_6 ( & V_11 -> V_14 , V_64 ) ;
F_19 ( V_2 , 2 * V_65 , V_108 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
for (; ; ) {
F_2 ( L_12 ,
V_2 -> V_25 , V_2 -> V_43 , V_2 -> V_72 ) ;
switch ( V_2 -> V_25 ) {
case V_26 :
return;
case V_109 :
if ( F_9 ( V_2 , V_110 ) ) {
F_2 ( L_5 , L_13 ) ;
V_2 -> V_72 = 0 ;
if ( V_2 -> V_43 == 0 )
V_2 -> V_25 = V_48 ;
else
V_2 -> V_25 = V_111 ;
break;
}
F_23 ( V_2 ) ;
return;
case V_111 :
if ( V_2 -> V_72 < 0 ) {
V_2 -> V_71 = - 1 ;
V_2 -> V_25 = V_109 ;
break;
}
if ( V_2 -> V_43 == V_2 -> V_72 ) {
F_31 ( L_5 , L_14 ) ;
V_2 -> V_25 = V_48 ;
break;
}
F_24 ( V_2 , V_2 -> V_43 - V_2 -> V_72 ) ;
return;
case V_112 :
V_2 -> V_77 = ( V_65 + 32 ) / 33 ;
F_19 ( V_2 , V_2 -> V_77 , V_113 ) ;
return;
case V_48 :
if ( V_2 -> V_72 != V_2 -> V_43 ) {
if ( V_2 -> V_49 > 5 ) {
F_35 ( L_15 ,
V_2 -> V_43 , V_2 -> V_72 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
return;
}
V_2 -> V_25 = V_111 ;
break;
}
F_29 ( V_2 ) ;
return;
case V_114 :
F_24 ( V_2 , - 5 ) ;
return;
default:
F_35 ( L_16 , V_2 -> V_25 ) ;
return;
}
}
}
static void V_66 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
unsigned long V_115 ;
F_2 ( L_17 , V_2 -> V_25 ) ;
F_36 ( & V_116 , V_115 ) ;
V_2 -> V_54 = 0 ;
F_6 ( & V_11 -> V_16 , V_64 | V_104 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
V_2 -> V_72 = - 1 ;
if ( V_2 -> V_49 > 5 ) {
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_25 = V_114 ;
F_17 ( V_2 ) ;
}
F_37 ( & V_116 , V_115 ) ;
}
static void V_76 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
unsigned long V_115 ;
F_2 ( L_18 , V_2 -> V_25 ) ;
F_36 ( & V_116 , V_115 ) ;
V_2 -> V_54 = 0 ;
F_6 ( & V_11 -> V_16 , V_75 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_35 ( L_5 , L_19 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
F_37 ( & V_116 , V_115 ) ;
}
static void V_113 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
unsigned long V_115 ;
F_2 ( L_20 , V_2 -> V_25 ) ;
F_36 ( & V_116 , V_115 ) ;
V_2 -> V_54 = 0 ;
if ( F_9 ( V_2 , V_117 ) ) {
F_6 ( & V_11 -> V_12 , V_13 ) ;
V_2 -> V_25 = V_109 ;
F_17 ( V_2 ) ;
goto V_118;
}
F_6 ( & V_11 -> V_12 , V_13 ) ;
if ( V_2 -> V_77 < 2 * V_65 ) {
++ V_2 -> V_77 ;
F_19 ( V_2 , 1 , V_113 ) ;
goto V_118;
}
F_35 ( L_5 , L_21 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
V_118:
F_37 ( & V_116 , V_115 ) ;
}
static void V_108 ( unsigned long V_59 )
{
struct V_1 * V_2 = (struct V_1 * ) V_59 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
struct V_88 T_1 * V_89 = V_2 -> V_90 ;
unsigned long V_115 ;
int V_67 ;
F_2 ( L_22 , V_2 -> V_25 ) ;
F_36 ( & V_116 , V_115 ) ;
V_2 -> V_54 = 0 ;
F_32 ( & V_89 -> V_105 , V_106 << 16 ) ;
for ( V_67 = 0 ; ( F_38 ( & V_89 -> V_22 ) & V_119 ) && V_67 < 1000 ; V_67 ++ )
F_8 ( 1 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_6 ( & V_11 -> V_16 , V_104 | V_64 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_35 ( L_23 ,
( F_16 ( V_2 -> V_7 ) == V_40 ? L_24 : L_25 ) ,
( long ) F_15 ( V_2 -> V_7 ) ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
F_37 ( & V_116 , V_115 ) ;
}
static T_2 F_39 ( int V_120 , void * V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
int V_61 , V_3 , V_67 ;
int V_21 , V_122 ;
struct V_88 T_1 * V_89 ;
struct V_78 * V_79 ;
unsigned long V_115 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_26 , V_2 -> V_25 ) ;
F_36 ( & V_116 , V_115 ) ;
V_61 = F_10 ( & V_11 -> V_61 ) ;
V_3 = ( V_61 & V_123 ) ? F_10 ( & V_11 -> error ) : 0 ;
if ( ( V_61 & V_123 ) && V_2 -> V_25 != V_48 )
F_35 ( L_27 ,
V_2 -> V_25 , F_16 ( V_6 ) , V_61 , V_3 ) ;
switch ( V_2 -> V_25 ) {
case V_109 :
if ( V_61 & V_63 ) {
F_6 ( & V_11 -> V_16 , V_64 | V_104 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_21 ( & V_2 -> V_55 ) ;
V_2 -> V_54 = 0 ;
if ( V_11 -> V_124 == 0xff ) {
F_35 ( L_5 , L_28 ) ;
V_2 -> V_72 = - 1 ;
if ( V_2 -> V_49 > 5 ) {
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_25 = V_114 ;
F_17 ( V_2 ) ;
}
break;
}
V_2 -> V_72 = V_11 -> V_124 ;
V_2 -> V_125 = V_11 -> V_126 ;
if ( V_2 -> V_71 != - 1 && V_2 -> V_71 != V_2 -> V_72 )
F_35 ( L_29 ,
V_2 -> V_71 , V_2 -> V_72 ) ;
V_2 -> V_25 = V_48 ;
F_17 ( V_2 ) ;
}
break;
case V_111 :
case V_114 :
if ( V_11 -> V_69 == 0 ) {
F_6 ( & V_11 -> V_16 , V_75 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_21 ( & V_2 -> V_55 ) ;
V_2 -> V_54 = 0 ;
if ( V_2 -> V_25 == V_111 )
++ V_2 -> V_49 ;
V_2 -> V_25 = V_112 ;
F_17 ( V_2 ) ;
}
break;
case V_112 :
F_6 ( & V_11 -> V_62 , 0 ) ;
F_21 ( & V_2 -> V_55 ) ;
V_2 -> V_54 = 0 ;
F_17 ( V_2 ) ;
break;
case V_48 :
if ( ( V_61 & ( V_123 | V_107 ) ) == 0 )
break;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_6 ( & V_11 -> V_16 , V_104 | V_64 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_21 ( & V_2 -> V_55 ) ;
V_2 -> V_54 = 0 ;
V_89 = V_2 -> V_90 ;
V_79 = V_2 -> V_87 ;
if ( F_16 ( V_6 ) == V_40 )
++ V_79 ;
if ( ( V_61 & V_123 ) == 0 && V_79 -> V_86 == 0 ) {
for ( V_67 = 0 ; V_67 < 100 ; ++ V_67 ) {
if ( V_79 -> V_86 != 0 )
break;
F_8 ( 1 ) ;
F_40 () ;
}
}
F_32 ( & V_89 -> V_105 , ( V_106 | V_127 ) << 16 ) ;
V_21 = F_41 ( V_79 -> V_86 ) ;
V_122 = F_41 ( V_79 -> V_128 ) ;
if ( V_61 & V_123 ) {
V_67 = V_2 -> V_91 - 1 - V_122 / 512 ;
if ( V_67 > 0 ) {
F_42 ( V_6 , 0 , V_67 << 9 ) ;
V_2 -> V_47 += V_67 ;
}
if ( V_2 -> V_49 < 5 ) {
++ V_2 -> V_49 ;
F_17 ( V_2 ) ;
} else {
F_35 ( L_30 ,
F_16 ( V_6 ) == V_40 ? L_24 : L_25 ,
( long ) F_15 ( V_6 ) , V_3 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
}
} else {
if ( ( V_21 & V_119 ) == 0 || V_122 != 0 ) {
F_35 ( L_31 , V_21 , V_122 ) ;
F_35 ( L_32 ,
V_2 -> V_25 , F_16 ( V_6 ) , V_61 , V_3 ) ;
F_1 ( V_2 , - V_38 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
break;
}
V_2 -> V_49 = 0 ;
if ( F_1 ( V_2 , 0 , V_2 -> V_91 << 9 ) ) {
V_2 -> V_47 += V_2 -> V_91 ;
if ( V_2 -> V_47 > V_2 -> V_46 ) {
V_2 -> V_47 -= V_2 -> V_46 ;
if ( ++ V_2 -> V_45 > 1 ) {
V_2 -> V_45 = 0 ;
++ V_2 -> V_43 ;
}
}
F_17 ( V_2 ) ;
} else
V_2 -> V_25 = V_26 ;
}
if ( V_2 -> V_25 == V_26 )
F_11 ( V_2 ) ;
break;
default:
F_35 ( L_33 , V_2 -> V_25 ) ;
}
F_37 ( & V_116 , V_115 ) ;
return V_129 ;
}
static int F_43 ( struct V_1 * V_2 , enum V_130 V_25 ,
int V_131 )
{
unsigned long V_115 ;
F_2 ( L_5 , L_34 ) ;
F_36 ( & V_116 , V_115 ) ;
if ( V_2 -> V_25 != V_26 && V_2 -> V_25 != V_28 ) {
++ V_2 -> V_27 ;
if ( ! V_131 )
F_44 ( V_2 -> V_29 ,
V_2 -> V_25 == V_28 ,
V_116 ) ;
else if ( F_45 ( V_2 -> V_29 ,
V_2 -> V_25 == V_28 ,
V_116 ) ) {
-- V_2 -> V_27 ;
F_37 ( & V_116 , V_115 ) ;
return - V_132 ;
}
-- V_2 -> V_27 ;
}
V_2 -> V_25 = V_25 ;
F_37 ( & V_116 , V_115 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned long V_115 ;
F_2 ( L_5 , L_35 ) ;
F_36 ( & V_116 , V_115 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
F_37 ( & V_116 , V_115 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_3 , V_67 ;
V_3 = F_43 ( V_2 , V_133 , 1 ) ;
if ( V_3 )
return V_3 ;
F_7 ( V_2 , V_134 ) ;
for ( V_67 = 20 ; V_67 > 0 ; -- V_67 ) {
if ( F_48 ( V_135 ) ) {
V_3 = - V_132 ;
break;
}
F_5 ( V_2 , V_13 ) ;
F_49 ( 1 ) ;
if ( F_9 ( V_2 , V_136 ) == 0 )
break;
}
F_5 ( V_2 , V_13 ) ;
F_8 ( 150 ) ;
V_2 -> V_39 = 1 ;
F_46 ( V_2 ) ;
return V_3 ;
}
static int F_50 ( struct V_137 * V_138 , T_3 V_139 ,
unsigned int V_80 , unsigned long V_140 )
{
struct V_1 * V_2 = V_138 -> V_141 -> V_142 ;
int V_3 ;
if ( ( V_80 & 0x80 ) && ! F_51 ( V_143 ) )
return - V_144 ;
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 )
return - V_145 ;
switch ( V_80 ) {
case V_146 :
if ( V_2 -> V_147 != 1 )
return - V_148 ;
V_3 = F_47 ( V_2 ) ;
return V_3 ;
case V_149 :
if ( F_52 ( ( void V_150 * ) V_140 , & V_151 ,
sizeof( struct V_152 ) ) )
return - V_153 ;
return 0 ;
}
return - V_154 ;
}
static int F_53 ( struct V_137 * V_138 , T_3 V_139 ,
unsigned int V_80 , unsigned long V_140 )
{
int V_155 ;
F_54 ( & V_156 ) ;
V_155 = F_50 ( V_138 , V_139 , V_80 , V_140 ) ;
F_55 ( & V_156 ) ;
return V_155 ;
}
static int F_56 ( struct V_137 * V_138 , T_3 V_139 )
{
struct V_1 * V_2 = V_138 -> V_141 -> V_142 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
int V_67 , V_3 = 0 ;
if ( V_2 -> V_147 == 0 ) {
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 )
return - V_145 ;
F_6 ( & V_11 -> V_157 , V_158 | V_159 ) ;
F_6 ( & V_11 -> V_16 , 0xff ) ;
F_6 ( & V_11 -> V_139 , 0x95 ) ;
F_8 ( 10 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_6 ( & V_11 -> V_14 , V_160 | V_161 ) ;
F_7 ( V_2 , V_162 ) ;
V_2 -> V_41 = - 1 ;
V_2 -> V_72 = - 1 ;
for ( V_67 = 0 ; V_67 < 2 * V_65 ; ++ V_67 ) {
if ( V_67 >= V_65 / 30 && F_9 ( V_2 , V_117 ) )
break;
if ( F_48 ( V_135 ) ) {
V_3 = - V_132 ;
break;
}
F_5 ( V_2 , V_13 ) ;
F_49 ( 1 ) ;
}
if ( V_3 == 0 && ( F_9 ( V_2 , V_117 ) == 0
|| F_9 ( V_2 , V_136 ) == 0 ) )
V_3 = - V_145 ;
F_7 ( V_2 , V_163 ) ;
F_5 ( V_2 , V_13 ) ;
} else if ( V_2 -> V_147 == - 1 || V_139 & V_164 )
return - V_148 ;
if ( V_3 == 0 && ( V_139 & V_165 ) == 0
&& ( V_139 & ( V_166 | V_167 ) ) ) {
F_57 ( V_138 ) ;
if ( V_2 -> V_39 )
V_3 = - V_145 ;
}
if ( V_3 == 0 && ( V_139 & V_167 ) ) {
if ( V_2 -> V_41 < 0 )
V_2 -> V_41 = F_9 ( V_2 , V_42 ) ;
if ( V_2 -> V_41 )
V_3 = - V_168 ;
}
if ( V_3 ) {
if ( V_2 -> V_147 == 0 ) {
F_7 ( V_2 , V_169 ) ;
F_6 ( & V_11 -> V_16 , V_160 | V_161 ) ;
F_5 ( V_2 , V_13 ) ;
}
return V_3 ;
}
if ( V_139 & V_164 )
V_2 -> V_147 = - 1 ;
else
++ V_2 -> V_147 ;
return 0 ;
}
static int F_58 ( struct V_137 * V_138 , T_3 V_139 )
{
int V_155 ;
F_54 ( & V_156 ) ;
V_155 = F_56 ( V_138 , V_139 ) ;
F_55 ( & V_156 ) ;
return V_155 ;
}
static void F_59 ( struct V_170 * V_171 , T_3 V_139 )
{
struct V_1 * V_2 = V_171 -> V_142 ;
struct V_10 T_1 * V_11 = V_2 -> V_10 ;
F_54 ( & V_156 ) ;
if ( V_2 -> V_147 > 0 && -- V_2 -> V_147 == 0 ) {
F_7 ( V_2 , V_169 ) ;
F_6 ( & V_11 -> V_16 , 0xff ) ;
F_5 ( V_2 , V_13 ) ;
}
F_55 ( & V_156 ) ;
}
static unsigned int F_60 ( struct V_170 * V_171 ,
unsigned int V_172 )
{
struct V_1 * V_2 = V_171 -> V_142 ;
return V_2 -> V_39 ? V_173 : 0 ;
}
static int F_61 ( struct V_170 * V_171 )
{
struct V_1 * V_2 = V_171 -> V_142 ;
struct V_10 T_1 * V_11 ;
int V_155 , V_67 ;
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 )
return - V_145 ;
V_11 = V_2 -> V_10 ;
F_43 ( V_2 , V_174 , 0 ) ;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_6 ( & V_11 -> V_14 , V_160 ) ;
F_7 ( V_2 , V_162 ) ;
V_2 -> V_41 = - 1 ;
V_2 -> V_72 = - 1 ;
F_62 ( 1 ) ;
for ( V_67 = V_65 ; V_67 > 0 ; -- V_67 ) {
if ( F_9 ( V_2 , V_117 ) )
break;
if ( F_48 ( V_135 ) )
break;
F_5 ( V_2 , V_13 ) ;
F_49 ( 1 ) ;
}
V_155 = F_9 ( V_2 , V_117 ) == 0
|| F_9 ( V_2 , V_136 ) == 0 ;
if ( V_155 )
F_7 ( V_2 , V_169 ) ;
else {
V_2 -> V_39 = 0 ;
F_7 ( V_2 , V_163 ) ;
}
F_5 ( V_2 , V_13 ) ;
F_46 ( V_2 ) ;
return V_155 ;
}
static void F_63 ( struct V_175 * V_33 , int V_176 )
{
struct V_1 * V_2 = F_64 ( V_33 ) ;
struct V_10 T_1 * V_11 ;
if ( ! V_2 )
return;
V_11 = V_2 -> V_10 ;
if ( V_176 != V_35 )
return;
F_6 ( & V_11 -> V_62 , 0 ) ;
F_10 ( & V_11 -> V_61 ) ;
F_10 ( & V_11 -> error ) ;
}
static int F_65 ( struct V_175 * V_33 , int V_31 )
{
struct V_177 * V_178 = V_33 -> V_179 . V_180 . V_181 ;
struct V_1 * V_2 = & V_182 [ V_31 ] ;
int V_8 = - V_148 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_31 = V_31 ;
if ( F_66 ( V_33 ) < 2 ) {
F_35 ( L_5 , L_36 ) ;
return - V_145 ;
}
if ( F_67 ( V_33 ) < 1 ) {
F_35 ( L_5 , L_37 ) ;
return - V_145 ;
}
if ( F_68 ( V_33 , 0 , L_38 ) ) {
F_35 ( L_5 , L_39 ) ;
return - V_148 ;
}
if ( F_68 ( V_33 , 1 , L_40 ) ) {
F_35 ( L_5 , L_41 ) ;
F_69 ( V_33 , 0 ) ;
return - V_148 ;
}
F_70 ( & V_33 -> V_179 . V_180 , V_2 ) ;
if ( V_33 -> V_34 == NULL )
F_71 ( V_183 , V_178 , 0 , 1 ) ;
V_2 -> V_25 = V_26 ;
V_2 -> V_10 = (struct V_10 T_1 * )
F_72 ( F_73 ( V_33 , 0 ) , 0x200 ) ;
if ( V_2 -> V_10 == NULL ) {
F_35 ( L_5 , L_42 ) ;
V_8 = - V_184 ;
goto V_185;
}
V_2 -> V_90 = (struct V_88 T_1 * )
F_72 ( F_73 ( V_33 , 1 ) , 0x200 ) ;
if ( V_2 -> V_90 == NULL ) {
F_35 ( L_5 , L_43 ) ;
F_74 ( V_2 -> V_10 ) ;
V_8 = - V_184 ;
goto V_185;
}
V_2 -> V_186 = F_75 ( V_33 , 0 ) ;
V_2 -> V_187 = F_75 ( V_33 , 1 ) ;
V_2 -> V_72 = - 1 ;
V_2 -> V_125 = - 1 ;
V_2 -> V_44 = 36 ;
V_2 -> V_46 = 18 ;
V_2 -> V_37 = 2880 ;
F_76 ( & V_2 -> V_29 ) ;
V_2 -> V_87 = (struct V_78 * ) F_77 ( V_2 -> V_188 ) ;
memset ( V_2 -> V_87 , 0 , 2 * sizeof( struct V_78 ) ) ;
V_2 -> V_87 [ 1 ] . V_84 = F_26 ( V_103 ) ;
if ( V_33 -> V_34 == NULL || F_14 ( V_33 -> V_34 ) == V_35 )
F_63 ( V_33 , V_35 ) ;
if ( F_78 ( V_2 -> V_186 , F_39 , 0 , L_44 , V_2 ) ) {
F_35 ( L_5 , L_45 ) ;
F_71 ( V_183 , V_178 , 0 , 0 ) ;
goto V_189;
return - V_148 ;
}
F_79 ( & V_2 -> V_55 ) ;
F_80 ( L_46 ,
V_33 -> V_34 ? L_47 : L_48 ) ;
return 0 ;
V_189:
F_74 ( V_2 -> V_90 ) ;
F_74 ( V_2 -> V_10 ) ;
V_185:
F_69 ( V_33 , 0 ) ;
F_69 ( V_33 , 1 ) ;
return V_8 ;
}
static int F_81 ( struct V_175 * V_33 ,
const struct V_190 * V_191 )
{
struct V_170 * V_171 ;
int V_31 , V_8 ;
V_31 = V_192 ++ ;
if ( V_31 >= V_193 )
return - V_145 ;
V_8 = F_65 ( V_33 , V_31 ) ;
if ( V_8 )
return V_8 ;
V_171 = V_30 [ V_31 ] = F_82 ( 1 ) ;
if ( V_171 == NULL )
return - V_184 ;
V_171 -> V_32 = F_83 ( F_18 , & V_116 ) ;
if ( V_171 -> V_32 == NULL ) {
F_84 ( V_171 ) ;
return - V_184 ;
}
V_171 -> V_32 -> V_52 = & V_182 [ V_31 ] ;
if ( V_31 == 0 ) {
if ( F_85 ( V_194 , L_49 ) )
return 0 ;
}
V_171 -> V_195 = V_194 ;
V_171 -> V_196 = V_31 ;
V_171 -> V_197 = & V_198 ;
V_171 -> V_142 = & V_182 [ V_31 ] ;
V_171 -> V_115 |= V_199 ;
sprintf ( V_171 -> V_200 , L_50 , V_31 ) ;
F_86 ( V_171 , 2880 ) ;
F_87 ( V_171 ) ;
return 0 ;
}
int F_88 ( void )
{
F_89 ( & V_201 ) ;
return 0 ;
}
