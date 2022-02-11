static bool F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
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
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
if ( V_9 & 8 )
F_6 ( & V_11 -> V_14 , V_15 ) ;
else
F_6 ( & V_11 -> V_16 , V_15 ) ;
F_6 ( & V_11 -> V_12 , V_9 & V_17 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_18 )
{
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
F_5 ( V_2 , V_18 ) ;
F_8 ( 1 ) ;
F_6 ( & V_11 -> V_12 , V_11 -> V_12 | V_19 ) ;
F_8 ( 2 ) ;
F_6 ( & V_11 -> V_12 , V_11 -> V_12 & ~ V_19 ) ;
F_8 ( 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_20 )
{
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
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
F_1 ( V_2 , V_36 , 0 ) ;
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
F_1 ( V_2 , V_36 , 0 ) ;
continue;
}
if ( V_2 -> V_38 ) {
F_2 ( L_5 , L_8 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
continue;
}
if ( F_16 ( V_6 ) == V_39 ) {
if ( V_2 -> V_40 < 0 )
V_2 -> V_40 = F_9 ( V_2 , V_41 ) ;
if ( V_2 -> V_40 ) {
F_2 ( L_5 , L_9 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
continue;
}
}
V_2 -> V_42 = ( ( long ) F_15 ( V_6 ) ) / V_2 -> V_43 ;
V_24 = ( ( long ) F_15 ( V_6 ) ) % V_2 -> V_43 ;
V_2 -> V_44 = V_24 / V_2 -> V_45 ;
V_2 -> V_46 = V_24 % V_2 -> V_45 + 1 ;
V_2 -> V_25 = V_47 ;
V_2 -> V_48 = 0 ;
F_17 ( V_2 ) ;
}
}
static void F_18 ( struct V_49 * V_50 )
{
F_11 ( V_50 -> V_51 ) ;
}
static void F_19 ( struct V_1 * V_2 , int V_52 ,
void (* F_20)( unsigned long ) )
{
if ( V_2 -> V_53 )
F_21 ( & V_2 -> V_54 ) ;
V_2 -> V_54 . V_55 = V_56 + V_52 ;
V_2 -> V_54 . V_57 = F_20 ;
V_2 -> V_54 . V_58 = ( unsigned long ) V_2 ;
F_22 ( & V_2 -> V_54 ) ;
V_2 -> V_53 = 1 ;
}
static inline void F_23 ( struct V_1 * V_2 )
{
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
F_5 ( V_2 , V_59 ) ;
F_10 ( & V_11 -> V_60 ) ;
F_10 ( & V_11 -> error ) ;
F_6 ( & V_11 -> V_61 , V_62 ) ;
F_6 ( & V_11 -> V_14 , V_63 ) ;
F_19 ( V_2 , V_64 , V_65 ) ;
}
static inline void F_24 ( struct V_1 * V_2 , int V_66 )
{
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
if ( V_66 >= 0 ) {
F_7 ( V_2 , V_67 ) ;
V_11 -> V_68 = V_66 ;
} else {
F_7 ( V_2 , V_69 ) ;
V_11 -> V_68 = - V_66 ;
}
V_2 -> V_70 = ( V_2 -> V_71 >= 0 ) ? V_2 -> V_71 + V_66 : - 1 ;
F_5 ( V_2 , V_72 ) ;
F_10 ( & V_11 -> error ) ;
F_6 ( & V_11 -> V_61 , V_73 ) ;
F_6 ( & V_11 -> V_14 , V_74 ) ;
F_19 ( V_2 , 3 * V_64 , V_75 ) ;
V_2 -> V_76 = 0 ;
}
static inline void F_25 ( struct V_77 * V_78 , int V_79 ,
void * V_80 , int V_81 )
{
V_78 -> V_82 = F_26 ( V_81 ) ;
V_78 -> V_83 = F_26 ( V_79 ) ;
V_78 -> V_84 = F_27 ( F_28 ( V_80 ) ) ;
V_78 -> V_85 = 0 ;
}
static inline void F_29 ( struct V_1 * V_2 )
{
int V_66 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
struct V_77 * V_78 = V_2 -> V_86 ;
struct V_87 T_2 * V_88 = V_2 -> V_89 ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( F_30 ( V_6 ) <= 0 ) {
F_31 ( L_5 , L_10 ) ;
return;
}
if ( F_16 ( V_6 ) == V_39 )
V_66 = 1 ;
else {
V_66 = V_2 -> V_45 - V_2 -> V_46 + 1 ;
if ( V_66 > F_30 ( V_6 ) )
V_66 = F_30 ( V_6 ) ;
}
F_2 ( L_11 ,
V_2 -> V_46 , V_2 -> V_45 , V_2 -> V_44 , V_66 ) ;
V_2 -> V_90 = V_66 ;
F_5 ( V_2 , V_2 -> V_44 ? V_91 : V_59 ) ;
F_6 ( & V_11 -> V_92 , V_2 -> V_46 ) ;
F_6 ( & V_11 -> V_93 , V_66 ) ;
F_6 ( & V_11 -> V_94 , 0 ) ;
F_32 ( & V_88 -> V_95 , F_28 ( V_78 ) ) ;
if ( F_16 ( V_6 ) == V_39 ) {
F_25 ( V_78 , V_96 , V_97 , sizeof( V_97 ) ) ;
++ V_78 ;
F_25 ( V_78 , V_96 , F_33 ( V_6 -> V_98 ) , 512 ) ;
++ V_78 ;
F_25 ( V_78 , V_99 , V_100 , sizeof( V_100 ) ) ;
} else {
F_25 ( V_78 , V_101 , F_33 ( V_6 -> V_98 ) , V_66 * 512 ) ;
}
++ V_78 ;
F_34 ( & V_78 -> V_83 , V_102 ) ;
F_6 ( & V_11 -> V_16 , V_63 | V_103 ) ;
F_10 ( & V_11 -> error ) ;
F_6 ( & V_11 -> V_16 , V_63 | V_103 ) ;
if ( F_16 ( V_6 ) == V_39 )
F_6 ( & V_11 -> V_14 , V_103 ) ;
F_10 ( & V_11 -> V_60 ) ;
F_32 ( & V_88 -> V_104 , ( V_105 << 16 ) | V_105 ) ;
F_6 ( & V_11 -> V_61 , V_106 ) ;
F_6 ( & V_11 -> V_14 , V_63 ) ;
F_19 ( V_2 , 2 * V_64 , V_107 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
for (; ; ) {
F_2 ( L_12 ,
V_2 -> V_25 , V_2 -> V_42 , V_2 -> V_71 ) ;
switch ( V_2 -> V_25 ) {
case V_26 :
return;
case V_108 :
if ( F_9 ( V_2 , V_109 ) ) {
F_2 ( L_5 , L_13 ) ;
V_2 -> V_71 = 0 ;
if ( V_2 -> V_42 == 0 )
V_2 -> V_25 = V_47 ;
else
V_2 -> V_25 = V_110 ;
break;
}
F_23 ( V_2 ) ;
return;
case V_110 :
if ( V_2 -> V_71 < 0 ) {
V_2 -> V_70 = - 1 ;
V_2 -> V_25 = V_108 ;
break;
}
if ( V_2 -> V_42 == V_2 -> V_71 ) {
F_31 ( L_5 , L_14 ) ;
V_2 -> V_25 = V_47 ;
break;
}
F_24 ( V_2 , V_2 -> V_42 - V_2 -> V_71 ) ;
return;
case V_111 :
V_2 -> V_76 = ( V_64 + 32 ) / 33 ;
F_19 ( V_2 , V_2 -> V_76 , V_112 ) ;
return;
case V_47 :
if ( V_2 -> V_71 != V_2 -> V_42 ) {
if ( V_2 -> V_48 > 5 ) {
F_35 ( L_15 ,
V_2 -> V_42 , V_2 -> V_71 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
return;
}
V_2 -> V_25 = V_110 ;
break;
}
F_29 ( V_2 ) ;
return;
case V_113 :
F_24 ( V_2 , - 5 ) ;
return;
default:
F_35 ( L_16 , V_2 -> V_25 ) ;
return;
}
}
}
static void V_65 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
unsigned long V_114 ;
F_2 ( L_17 , V_2 -> V_25 ) ;
F_36 ( & V_115 , V_114 ) ;
V_2 -> V_53 = 0 ;
F_6 ( & V_11 -> V_16 , V_63 | V_103 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
V_2 -> V_71 = - 1 ;
if ( V_2 -> V_48 > 5 ) {
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_25 = V_113 ;
F_17 ( V_2 ) ;
}
F_37 ( & V_115 , V_114 ) ;
}
static void V_75 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
unsigned long V_114 ;
F_2 ( L_18 , V_2 -> V_25 ) ;
F_36 ( & V_115 , V_114 ) ;
V_2 -> V_53 = 0 ;
F_6 ( & V_11 -> V_16 , V_74 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_35 ( L_5 , L_19 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
F_37 ( & V_115 , V_114 ) ;
}
static void V_112 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
unsigned long V_114 ;
F_2 ( L_20 , V_2 -> V_25 ) ;
F_36 ( & V_115 , V_114 ) ;
V_2 -> V_53 = 0 ;
if ( F_9 ( V_2 , V_116 ) ) {
F_6 ( & V_11 -> V_12 , V_13 ) ;
V_2 -> V_25 = V_108 ;
F_17 ( V_2 ) ;
goto V_117;
}
F_6 ( & V_11 -> V_12 , V_13 ) ;
if ( V_2 -> V_76 < 2 * V_64 ) {
++ V_2 -> V_76 ;
F_19 ( V_2 , 1 , V_112 ) ;
goto V_117;
}
F_35 ( L_5 , L_21 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
V_117:
F_37 ( & V_115 , V_114 ) ;
}
static void V_107 ( unsigned long V_58 )
{
struct V_1 * V_2 = (struct V_1 * ) V_58 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
struct V_87 T_2 * V_88 = V_2 -> V_89 ;
unsigned long V_114 ;
int V_66 ;
F_2 ( L_22 , V_2 -> V_25 ) ;
F_36 ( & V_115 , V_114 ) ;
V_2 -> V_53 = 0 ;
F_32 ( & V_88 -> V_104 , V_105 << 16 ) ;
for ( V_66 = 0 ; ( F_38 ( & V_88 -> V_22 ) & V_118 ) && V_66 < 1000 ; V_66 ++ )
F_8 ( 1 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_6 ( & V_11 -> V_16 , V_103 | V_63 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_35 ( L_23 ,
( F_16 ( V_2 -> V_7 ) == V_39 ? L_24 : L_25 ) ,
( long ) F_15 ( V_2 -> V_7 ) ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
F_37 ( & V_115 , V_114 ) ;
}
static T_3 F_39 ( int V_119 , void * V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
int V_60 , V_3 , V_66 ;
int V_21 , V_121 ;
struct V_87 T_2 * V_88 ;
struct V_77 * V_78 ;
unsigned long V_114 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( L_26 , V_2 -> V_25 ) ;
F_36 ( & V_115 , V_114 ) ;
V_60 = F_10 ( & V_11 -> V_60 ) ;
V_3 = ( V_60 & V_122 ) ? F_10 ( & V_11 -> error ) : 0 ;
if ( ( V_60 & V_122 ) && V_2 -> V_25 != V_47 )
F_35 ( L_27 ,
V_2 -> V_25 , F_16 ( V_6 ) , V_60 , V_3 ) ;
switch ( V_2 -> V_25 ) {
case V_108 :
if ( V_60 & V_62 ) {
F_6 ( & V_11 -> V_16 , V_63 | V_103 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_21 ( & V_2 -> V_54 ) ;
V_2 -> V_53 = 0 ;
if ( V_11 -> V_123 == 0xff ) {
F_35 ( L_5 , L_28 ) ;
V_2 -> V_71 = - 1 ;
if ( V_2 -> V_48 > 5 ) {
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
} else {
V_2 -> V_25 = V_113 ;
F_17 ( V_2 ) ;
}
break;
}
V_2 -> V_71 = V_11 -> V_123 ;
V_2 -> V_124 = V_11 -> V_125 ;
if ( V_2 -> V_70 != - 1 && V_2 -> V_70 != V_2 -> V_71 )
F_35 ( L_29 ,
V_2 -> V_70 , V_2 -> V_71 ) ;
V_2 -> V_25 = V_47 ;
F_17 ( V_2 ) ;
}
break;
case V_110 :
case V_113 :
if ( V_11 -> V_68 == 0 ) {
F_6 ( & V_11 -> V_16 , V_74 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_21 ( & V_2 -> V_54 ) ;
V_2 -> V_53 = 0 ;
if ( V_2 -> V_25 == V_110 )
++ V_2 -> V_48 ;
V_2 -> V_25 = V_111 ;
F_17 ( V_2 ) ;
}
break;
case V_111 :
F_6 ( & V_11 -> V_61 , 0 ) ;
F_21 ( & V_2 -> V_54 ) ;
V_2 -> V_53 = 0 ;
F_17 ( V_2 ) ;
break;
case V_47 :
if ( ( V_60 & ( V_122 | V_106 ) ) == 0 )
break;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_6 ( & V_11 -> V_16 , V_103 | V_63 ) ;
F_6 ( & V_11 -> V_12 , V_13 ) ;
F_21 ( & V_2 -> V_54 ) ;
V_2 -> V_53 = 0 ;
V_88 = V_2 -> V_89 ;
V_78 = V_2 -> V_86 ;
if ( F_16 ( V_6 ) == V_39 )
++ V_78 ;
if ( ( V_60 & V_122 ) == 0 && V_78 -> V_85 == 0 ) {
for ( V_66 = 0 ; V_66 < 100 ; ++ V_66 ) {
if ( V_78 -> V_85 != 0 )
break;
F_8 ( 1 ) ;
F_40 () ;
}
}
F_32 ( & V_88 -> V_104 , ( V_105 | V_126 ) << 16 ) ;
V_21 = F_41 ( V_78 -> V_85 ) ;
V_121 = F_41 ( V_78 -> V_127 ) ;
if ( V_60 & V_122 ) {
V_66 = V_2 -> V_90 - 1 - V_121 / 512 ;
if ( V_66 > 0 ) {
F_42 ( V_6 , 0 , V_66 << 9 ) ;
V_2 -> V_46 += V_66 ;
}
if ( V_2 -> V_48 < 5 ) {
++ V_2 -> V_48 ;
F_17 ( V_2 ) ;
} else {
F_35 ( L_30 ,
F_16 ( V_6 ) == V_39 ? L_24 : L_25 ,
( long ) F_15 ( V_6 ) , V_3 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
}
} else {
if ( ( V_21 & V_118 ) == 0 || V_121 != 0 ) {
F_35 ( L_31 , V_21 , V_121 ) ;
F_35 ( L_32 ,
V_2 -> V_25 , F_16 ( V_6 ) , V_60 , V_3 ) ;
F_1 ( V_2 , V_36 , 0 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
break;
}
V_2 -> V_48 = 0 ;
if ( F_1 ( V_2 , 0 , V_2 -> V_90 << 9 ) ) {
V_2 -> V_46 += V_2 -> V_90 ;
if ( V_2 -> V_46 > V_2 -> V_45 ) {
V_2 -> V_46 -= V_2 -> V_45 ;
if ( ++ V_2 -> V_44 > 1 ) {
V_2 -> V_44 = 0 ;
++ V_2 -> V_42 ;
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
F_37 ( & V_115 , V_114 ) ;
return V_128 ;
}
static int F_43 ( struct V_1 * V_2 , enum V_129 V_25 ,
int V_130 )
{
unsigned long V_114 ;
F_2 ( L_5 , L_34 ) ;
F_36 ( & V_115 , V_114 ) ;
if ( V_2 -> V_25 != V_26 && V_2 -> V_25 != V_28 ) {
++ V_2 -> V_27 ;
if ( ! V_130 )
F_44 ( V_2 -> V_29 ,
V_2 -> V_25 == V_28 ,
V_115 ) ;
else if ( F_45 ( V_2 -> V_29 ,
V_2 -> V_25 == V_28 ,
V_115 ) ) {
-- V_2 -> V_27 ;
F_37 ( & V_115 , V_114 ) ;
return - V_131 ;
}
-- V_2 -> V_27 ;
}
V_2 -> V_25 = V_25 ;
F_37 ( & V_115 , V_114 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 )
{
unsigned long V_114 ;
F_2 ( L_5 , L_35 ) ;
F_36 ( & V_115 , V_114 ) ;
V_2 -> V_25 = V_26 ;
F_11 ( V_2 ) ;
F_37 ( & V_115 , V_114 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
int V_3 , V_66 ;
V_3 = F_43 ( V_2 , V_132 , 1 ) ;
if ( V_3 )
return V_3 ;
F_7 ( V_2 , V_133 ) ;
for ( V_66 = 20 ; V_66 > 0 ; -- V_66 ) {
if ( F_48 ( V_134 ) ) {
V_3 = - V_131 ;
break;
}
F_5 ( V_2 , V_13 ) ;
F_49 ( 1 ) ;
if ( F_9 ( V_2 , V_135 ) == 0 )
break;
}
F_5 ( V_2 , V_13 ) ;
F_8 ( 150 ) ;
V_2 -> V_38 = 1 ;
F_46 ( V_2 ) ;
return V_3 ;
}
static int F_50 ( struct V_136 * V_137 , T_4 V_138 ,
unsigned int V_79 , unsigned long V_139 )
{
struct V_1 * V_2 = V_137 -> V_140 -> V_141 ;
int V_3 ;
if ( ( V_79 & 0x80 ) && ! F_51 ( V_142 ) )
return - V_143 ;
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 )
return - V_144 ;
switch ( V_79 ) {
case V_145 :
if ( V_2 -> V_146 != 1 )
return - V_147 ;
V_3 = F_47 ( V_2 ) ;
return V_3 ;
case V_148 :
if ( F_52 ( ( void V_149 * ) V_139 , & V_150 ,
sizeof( struct V_151 ) ) )
return - V_152 ;
return 0 ;
}
return - V_153 ;
}
static int F_53 ( struct V_136 * V_137 , T_4 V_138 ,
unsigned int V_79 , unsigned long V_139 )
{
int V_154 ;
F_54 ( & V_155 ) ;
V_154 = F_50 ( V_137 , V_138 , V_79 , V_139 ) ;
F_55 ( & V_155 ) ;
return V_154 ;
}
static int F_56 ( struct V_136 * V_137 , T_4 V_138 )
{
struct V_1 * V_2 = V_137 -> V_140 -> V_141 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
int V_66 , V_3 = 0 ;
if ( V_2 -> V_146 == 0 ) {
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 )
return - V_144 ;
F_6 ( & V_11 -> V_156 , V_157 | V_158 ) ;
F_6 ( & V_11 -> V_16 , 0xff ) ;
F_6 ( & V_11 -> V_138 , 0x95 ) ;
F_8 ( 10 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_6 ( & V_11 -> V_14 , V_159 | V_160 ) ;
F_7 ( V_2 , V_161 ) ;
V_2 -> V_40 = - 1 ;
V_2 -> V_71 = - 1 ;
for ( V_66 = 0 ; V_66 < 2 * V_64 ; ++ V_66 ) {
if ( V_66 >= V_64 / 30 && F_9 ( V_2 , V_116 ) )
break;
if ( F_48 ( V_134 ) ) {
V_3 = - V_131 ;
break;
}
F_5 ( V_2 , V_13 ) ;
F_49 ( 1 ) ;
}
if ( V_3 == 0 && ( F_9 ( V_2 , V_116 ) == 0
|| F_9 ( V_2 , V_135 ) == 0 ) )
V_3 = - V_144 ;
F_7 ( V_2 , V_162 ) ;
F_5 ( V_2 , V_13 ) ;
} else if ( V_2 -> V_146 == - 1 || V_138 & V_163 )
return - V_147 ;
if ( V_3 == 0 && ( V_138 & V_164 ) == 0
&& ( V_138 & ( V_165 | V_166 ) ) ) {
F_57 ( V_137 ) ;
if ( V_2 -> V_38 )
V_3 = - V_144 ;
}
if ( V_3 == 0 && ( V_138 & V_166 ) ) {
if ( V_2 -> V_40 < 0 )
V_2 -> V_40 = F_9 ( V_2 , V_41 ) ;
if ( V_2 -> V_40 )
V_3 = - V_167 ;
}
if ( V_3 ) {
if ( V_2 -> V_146 == 0 ) {
F_7 ( V_2 , V_168 ) ;
F_6 ( & V_11 -> V_16 , V_159 | V_160 ) ;
F_5 ( V_2 , V_13 ) ;
}
return V_3 ;
}
if ( V_138 & V_163 )
V_2 -> V_146 = - 1 ;
else
++ V_2 -> V_146 ;
return 0 ;
}
static int F_58 ( struct V_136 * V_137 , T_4 V_138 )
{
int V_154 ;
F_54 ( & V_155 ) ;
V_154 = F_56 ( V_137 , V_138 ) ;
F_55 ( & V_155 ) ;
return V_154 ;
}
static void F_59 ( struct V_169 * V_170 , T_4 V_138 )
{
struct V_1 * V_2 = V_170 -> V_141 ;
struct V_10 T_2 * V_11 = V_2 -> V_10 ;
F_54 ( & V_155 ) ;
if ( V_2 -> V_146 > 0 && -- V_2 -> V_146 == 0 ) {
F_7 ( V_2 , V_168 ) ;
F_6 ( & V_11 -> V_16 , 0xff ) ;
F_5 ( V_2 , V_13 ) ;
}
F_55 ( & V_155 ) ;
}
static unsigned int F_60 ( struct V_169 * V_170 ,
unsigned int V_171 )
{
struct V_1 * V_2 = V_170 -> V_141 ;
return V_2 -> V_38 ? V_172 : 0 ;
}
static int F_61 ( struct V_169 * V_170 )
{
struct V_1 * V_2 = V_170 -> V_141 ;
struct V_10 T_2 * V_11 ;
int V_154 , V_66 ;
if ( V_2 -> V_33 -> V_34 &&
F_14 ( V_2 -> V_33 -> V_34 ) != V_35 )
return - V_144 ;
V_11 = V_2 -> V_10 ;
F_43 ( V_2 , V_173 , 0 ) ;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_6 ( & V_11 -> V_14 , V_159 ) ;
F_7 ( V_2 , V_161 ) ;
V_2 -> V_40 = - 1 ;
V_2 -> V_71 = - 1 ;
F_62 ( 1 ) ;
for ( V_66 = V_64 ; V_66 > 0 ; -- V_66 ) {
if ( F_9 ( V_2 , V_116 ) )
break;
if ( F_48 ( V_134 ) )
break;
F_5 ( V_2 , V_13 ) ;
F_49 ( 1 ) ;
}
V_154 = F_9 ( V_2 , V_116 ) == 0
|| F_9 ( V_2 , V_135 ) == 0 ;
if ( V_154 )
F_7 ( V_2 , V_168 ) ;
else {
V_2 -> V_38 = 0 ;
F_7 ( V_2 , V_162 ) ;
}
F_5 ( V_2 , V_13 ) ;
F_46 ( V_2 ) ;
return V_154 ;
}
static void F_63 ( struct V_174 * V_33 , int V_175 )
{
struct V_1 * V_2 = F_64 ( V_33 ) ;
struct V_10 T_2 * V_11 ;
if ( ! V_2 )
return;
V_11 = V_2 -> V_10 ;
if ( V_175 != V_35 )
return;
F_6 ( & V_11 -> V_61 , 0 ) ;
F_10 ( & V_11 -> V_60 ) ;
F_10 ( & V_11 -> error ) ;
}
static int F_65 ( struct V_174 * V_33 , int V_31 )
{
struct V_176 * V_177 = V_33 -> V_178 . V_179 . V_180 ;
struct V_1 * V_2 = & V_181 [ V_31 ] ;
int V_8 = - V_147 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_33 = V_33 ;
V_2 -> V_31 = V_31 ;
if ( F_66 ( V_33 ) < 2 ) {
F_35 ( L_5 , L_36 ) ;
return - V_144 ;
}
if ( F_67 ( V_33 ) < 1 ) {
F_35 ( L_5 , L_37 ) ;
return - V_144 ;
}
if ( F_68 ( V_33 , 0 , L_38 ) ) {
F_35 ( L_5 , L_39 ) ;
return - V_147 ;
}
if ( F_68 ( V_33 , 1 , L_40 ) ) {
F_35 ( L_5 , L_41 ) ;
F_69 ( V_33 , 0 ) ;
return - V_147 ;
}
F_70 ( & V_33 -> V_178 . V_179 , V_2 ) ;
if ( V_33 -> V_34 == NULL )
F_71 ( V_182 , V_177 , 0 , 1 ) ;
V_2 -> V_25 = V_26 ;
V_2 -> V_10 = (struct V_10 T_2 * )
F_72 ( F_73 ( V_33 , 0 ) , 0x200 ) ;
if ( V_2 -> V_10 == NULL ) {
F_35 ( L_5 , L_42 ) ;
V_8 = - V_183 ;
goto V_184;
}
V_2 -> V_89 = (struct V_87 T_2 * )
F_72 ( F_73 ( V_33 , 1 ) , 0x200 ) ;
if ( V_2 -> V_89 == NULL ) {
F_35 ( L_5 , L_43 ) ;
F_74 ( V_2 -> V_10 ) ;
V_8 = - V_183 ;
goto V_184;
}
V_2 -> V_185 = F_75 ( V_33 , 0 ) ;
V_2 -> V_186 = F_75 ( V_33 , 1 ) ;
V_2 -> V_71 = - 1 ;
V_2 -> V_124 = - 1 ;
V_2 -> V_43 = 36 ;
V_2 -> V_45 = 18 ;
V_2 -> V_37 = 2880 ;
F_76 ( & V_2 -> V_29 ) ;
V_2 -> V_86 = (struct V_77 * ) F_77 ( V_2 -> V_187 ) ;
memset ( V_2 -> V_86 , 0 , 2 * sizeof( struct V_77 ) ) ;
V_2 -> V_86 [ 1 ] . V_83 = F_26 ( V_102 ) ;
if ( V_33 -> V_34 == NULL || F_14 ( V_33 -> V_34 ) == V_35 )
F_63 ( V_33 , V_35 ) ;
if ( F_78 ( V_2 -> V_185 , F_39 , 0 , L_44 , V_2 ) ) {
F_35 ( L_5 , L_45 ) ;
F_71 ( V_182 , V_177 , 0 , 0 ) ;
goto V_188;
return - V_147 ;
}
F_79 ( & V_2 -> V_54 ) ;
F_80 ( L_46 ,
V_33 -> V_34 ? L_47 : L_48 ) ;
return 0 ;
V_188:
F_74 ( V_2 -> V_89 ) ;
F_74 ( V_2 -> V_10 ) ;
V_184:
F_69 ( V_33 , 0 ) ;
F_69 ( V_33 , 1 ) ;
return V_8 ;
}
static int F_81 ( struct V_174 * V_33 ,
const struct V_189 * V_190 )
{
struct V_169 * V_170 ;
int V_31 , V_8 ;
V_31 = V_191 ++ ;
if ( V_31 >= V_192 )
return - V_144 ;
V_8 = F_65 ( V_33 , V_31 ) ;
if ( V_8 )
return V_8 ;
V_170 = V_30 [ V_31 ] = F_82 ( 1 ) ;
if ( V_170 == NULL )
return - V_183 ;
V_170 -> V_32 = F_83 ( F_18 , & V_115 ) ;
if ( V_170 -> V_32 == NULL ) {
F_84 ( V_170 ) ;
return - V_183 ;
}
F_85 ( V_170 -> V_32 , V_193 ) ;
V_170 -> V_32 -> V_51 = & V_181 [ V_31 ] ;
if ( V_31 == 0 ) {
if ( F_86 ( V_194 , L_49 ) )
return 0 ;
}
V_170 -> V_195 = V_194 ;
V_170 -> V_196 = V_31 ;
V_170 -> V_197 = & V_198 ;
V_170 -> V_141 = & V_181 [ V_31 ] ;
V_170 -> V_114 |= V_199 ;
sprintf ( V_170 -> V_200 , L_50 , V_31 ) ;
F_87 ( V_170 , 2880 ) ;
F_88 ( V_170 ) ;
return 0 ;
}
int F_89 ( void )
{
F_90 ( & V_201 ) ;
return 0 ;
}
