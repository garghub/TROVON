static bool F_1 ( int V_1 , unsigned int V_2 )
{
if ( F_2 ( V_3 , V_1 , V_2 ) )
return true ;
V_3 = NULL ;
return false ;
}
static bool F_3 ( int V_1 )
{
return F_1 ( V_1 , F_4 ( V_3 ) ) ;
}
static void F_5 ( struct V_4 * V_5 , int V_6 )
{
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
if ( V_6 & 8 )
F_6 ( & V_8 -> V_11 , V_12 ) ;
else
F_6 ( & V_8 -> V_13 , V_12 ) ;
F_6 ( & V_8 -> V_9 , V_6 & V_14 ) ;
}
static void F_7 ( struct V_4 * V_5 , int V_15 )
{
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
F_5 ( V_5 , V_15 ) ;
F_8 ( 1 ) ;
F_6 ( & V_8 -> V_9 , V_8 -> V_9 | V_16 ) ;
F_8 ( 2 ) ;
F_6 ( & V_8 -> V_9 , V_8 -> V_9 & ~ V_16 ) ;
F_8 ( 1 ) ;
}
static int F_9 ( struct V_4 * V_5 , int V_17 )
{
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
int V_18 ;
F_5 ( V_5 , V_17 ) ;
F_8 ( 1 ) ;
V_18 = F_10 ( & V_8 -> V_19 ) ;
return ( V_18 & V_20 ) == 0 ;
}
static void F_11 ( struct V_21 * V_22 )
{
int V_23 ;
for( V_23 = 0 ; V_23 < V_24 ; V_23 ++ ) {
struct V_4 * V_5 = & V_25 [ V_23 ] ;
if ( V_5 -> V_26 -> V_27 &&
F_12 ( V_5 -> V_26 -> V_27 ) != V_28 )
continue;
F_13 ( V_5 ) ;
}
}
static void F_13 ( struct V_4 * V_5 )
{
struct V_29 * V_30 ;
unsigned long V_31 ;
if ( V_5 -> V_32 == V_33 && V_5 -> V_34 ) {
V_5 -> V_32 = V_35 ;
F_14 ( & V_5 -> V_36 ) ;
return;
}
while ( V_5 -> V_32 == V_33 ) {
if ( ! V_3 ) {
V_3 = F_15 ( V_37 ) ;
if ( ! V_3 )
break;
}
V_30 = V_3 ;
#if 0
printk("do_fd_req: dev=%s cmd=%d sec=%ld nr_sec=%u buf=%p\n",
req->rq_disk->disk_name, req->cmd,
(long)blk_rq_pos(req), blk_rq_sectors(req), req->buffer);
printk(" errors=%d current_nr_sectors=%u\n",
req->errors, blk_rq_cur_sectors(req));
#endif
if ( F_16 ( V_30 ) >= V_5 -> V_38 ) {
F_3 ( - V_39 ) ;
continue;
}
if ( V_5 -> V_40 ) {
F_3 ( - V_39 ) ;
continue;
}
if ( F_17 ( V_30 ) == V_41 ) {
if ( V_5 -> V_42 < 0 )
V_5 -> V_42 = F_9 ( V_5 , V_43 ) ;
if ( V_5 -> V_42 ) {
F_3 ( - V_39 ) ;
continue;
}
}
V_5 -> V_44 = ( ( long ) F_16 ( V_30 ) ) / V_5 -> V_45 ;
V_31 = ( ( long ) F_16 ( V_30 ) ) % V_5 -> V_45 ;
V_5 -> V_46 = V_31 / V_5 -> V_47 ;
V_5 -> V_48 = V_31 % V_5 -> V_47 + 1 ;
V_3 = V_30 ;
V_5 -> V_32 = V_49 ;
V_5 -> V_50 = 0 ;
F_18 ( V_5 ) ;
}
}
static void F_19 ( struct V_4 * V_5 , int V_51 ,
void (* F_20)( unsigned long ) )
{
unsigned long V_52 ;
F_21 ( & V_5 -> V_53 , V_52 ) ;
if ( V_5 -> V_54 )
F_22 ( & V_5 -> V_55 ) ;
V_5 -> V_55 . V_56 = V_57 + V_51 ;
V_5 -> V_55 . V_58 = F_20 ;
V_5 -> V_55 . V_59 = ( unsigned long ) V_5 ;
F_23 ( & V_5 -> V_55 ) ;
V_5 -> V_54 = 1 ;
F_24 ( & V_5 -> V_53 , V_52 ) ;
}
static inline void F_25 ( struct V_4 * V_5 )
{
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
F_5 ( V_5 , V_60 ) ;
F_10 ( & V_8 -> V_61 ) ;
F_10 ( & V_8 -> error ) ;
F_6 ( & V_8 -> V_62 , V_63 ) ;
F_6 ( & V_8 -> V_11 , V_64 ) ;
F_19 ( V_5 , V_65 , V_66 ) ;
}
static inline void F_26 ( struct V_4 * V_5 , int V_67 )
{
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
if ( V_67 >= 0 ) {
F_7 ( V_5 , V_68 ) ;
V_8 -> V_69 = V_67 ;
} else {
F_7 ( V_5 , V_70 ) ;
V_8 -> V_69 = - V_67 ;
}
V_5 -> V_71 = ( V_5 -> V_72 >= 0 ) ? V_5 -> V_72 + V_67 : - 1 ;
F_5 ( V_5 , V_73 ) ;
F_10 ( & V_8 -> error ) ;
F_6 ( & V_8 -> V_62 , V_74 ) ;
F_6 ( & V_8 -> V_11 , V_75 ) ;
F_19 ( V_5 , 3 * V_65 , V_76 ) ;
V_5 -> V_77 = 0 ;
}
static inline void F_27 ( struct V_78 * V_79 , int V_80 ,
void * V_81 , int V_82 )
{
F_28 ( & V_79 -> V_83 , V_82 ) ;
F_28 ( & V_79 -> V_84 , V_80 ) ;
F_29 ( & V_79 -> V_85 , F_30 ( V_81 ) ) ;
V_79 -> V_86 = 0 ;
}
static inline void F_31 ( struct V_4 * V_5 )
{
int V_67 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
struct V_78 * V_79 = V_5 -> V_87 ;
struct V_88 T_1 * V_89 = V_5 -> V_90 ;
if ( F_32 ( V_3 ) <= 0 ) {
F_33 ( V_91 L_1 ) ;
return;
}
if ( F_17 ( V_3 ) == V_41 )
V_67 = 1 ;
else {
V_67 = V_5 -> V_47 - V_5 -> V_48 + 1 ;
if ( V_67 > F_32 ( V_3 ) )
V_67 = F_32 ( V_3 ) ;
}
V_5 -> V_92 = V_67 ;
F_5 ( V_5 , V_5 -> V_46 ? V_93 : V_60 ) ;
F_6 ( & V_8 -> V_94 , V_5 -> V_48 ) ;
F_6 ( & V_8 -> V_95 , V_67 ) ;
F_6 ( & V_8 -> V_96 , 0 ) ;
F_34 ( & V_89 -> V_97 , F_30 ( V_79 ) ) ;
if ( F_17 ( V_3 ) == V_41 ) {
F_27 ( V_79 , V_98 , V_99 , sizeof( V_99 ) ) ;
++ V_79 ;
F_27 ( V_79 , V_98 , V_3 -> V_100 , 512 ) ;
++ V_79 ;
F_27 ( V_79 , V_101 , V_102 , sizeof( V_102 ) ) ;
} else {
F_27 ( V_79 , V_103 , V_3 -> V_100 , V_67 * 512 ) ;
}
++ V_79 ;
F_35 ( & V_79 -> V_84 , V_104 ) ;
F_6 ( & V_8 -> V_13 , V_64 | V_105 ) ;
F_10 ( & V_8 -> error ) ;
F_6 ( & V_8 -> V_13 , V_64 | V_105 ) ;
if ( F_17 ( V_3 ) == V_41 )
F_6 ( & V_8 -> V_11 , V_105 ) ;
F_10 ( & V_8 -> V_61 ) ;
F_34 ( & V_89 -> V_106 , ( V_107 << 16 ) | V_107 ) ;
F_6 ( & V_8 -> V_62 , V_108 ) ;
F_6 ( & V_8 -> V_11 , V_64 ) ;
F_19 ( V_5 , 2 * V_65 , V_109 ) ;
}
static void F_18 ( struct V_4 * V_5 )
{
for (; ; ) {
switch ( V_5 -> V_32 ) {
case V_33 :
return;
case V_110 :
if ( F_9 ( V_5 , V_111 ) ) {
V_5 -> V_72 = 0 ;
if ( V_5 -> V_44 == 0 )
V_5 -> V_32 = V_49 ;
else
V_5 -> V_32 = V_112 ;
break;
}
F_25 ( V_5 ) ;
return;
case V_112 :
if ( V_5 -> V_72 < 0 ) {
V_5 -> V_71 = - 1 ;
V_5 -> V_32 = V_110 ;
break;
}
if ( V_5 -> V_44 == V_5 -> V_72 ) {
F_33 ( L_2 ) ;
V_5 -> V_32 = V_49 ;
break;
}
F_26 ( V_5 , V_5 -> V_44 - V_5 -> V_72 ) ;
return;
case V_113 :
V_5 -> V_77 = ( V_65 + 32 ) / 33 ;
F_19 ( V_5 , V_5 -> V_77 , V_114 ) ;
return;
case V_49 :
if ( V_5 -> V_72 != V_5 -> V_44 ) {
if ( V_5 -> V_50 > 5 ) {
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
return;
}
V_5 -> V_32 = V_112 ;
break;
}
F_31 ( V_5 ) ;
return;
case V_115 :
F_26 ( V_5 , - 5 ) ;
return;
default:
F_33 ( V_91 L_3 , V_5 -> V_32 ) ;
return;
}
}
}
static void V_66 ( unsigned long V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
V_5 -> V_54 = 0 ;
F_6 ( & V_8 -> V_13 , V_64 | V_105 ) ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
V_5 -> V_72 = - 1 ;
if ( V_5 -> V_50 > 5 ) {
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
} else {
V_5 -> V_32 = V_115 ;
F_18 ( V_5 ) ;
}
}
static void V_76 ( unsigned long V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
V_5 -> V_54 = 0 ;
F_6 ( & V_8 -> V_13 , V_75 ) ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_33 ( V_91 L_4 ) ;
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
}
static void V_114 ( unsigned long V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
V_5 -> V_54 = 0 ;
if ( F_9 ( V_5 , V_116 ) ) {
F_6 ( & V_8 -> V_9 , V_10 ) ;
V_5 -> V_32 = V_110 ;
F_18 ( V_5 ) ;
return;
}
F_6 ( & V_8 -> V_9 , V_10 ) ;
if ( V_5 -> V_77 < 2 * V_65 ) {
++ V_5 -> V_77 ;
F_19 ( V_5 , 1 , V_114 ) ;
return;
}
F_33 ( V_91 L_5 ) ;
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
}
static void V_109 ( unsigned long V_59 )
{
struct V_4 * V_5 = (struct V_4 * ) V_59 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
struct V_88 T_1 * V_89 = V_5 -> V_90 ;
int V_67 ;
V_5 -> V_54 = 0 ;
F_34 ( & V_89 -> V_106 , V_107 << 16 ) ;
for ( V_67 = 0 ; ( F_36 ( & V_89 -> V_19 ) & V_117 ) && V_67 < 1000 ; V_67 ++ )
F_8 ( 1 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_6 ( & V_8 -> V_13 , V_105 | V_64 ) ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
F_33 ( V_91 L_6 ,
( F_17 ( V_3 ) == V_41 ? L_7 : L_8 ) ,
( long ) F_16 ( V_3 ) ) ;
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
}
static T_2 F_37 ( int V_118 , void * V_119 )
{
struct V_4 * V_5 = (struct V_4 * ) V_119 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
int V_61 , V_1 , V_67 ;
int V_18 , V_120 ;
struct V_88 T_1 * V_89 ;
struct V_78 * V_79 ;
V_61 = F_10 ( & V_8 -> V_61 ) ;
V_1 = ( V_61 & V_121 ) ? F_10 ( & V_8 -> error ) : 0 ;
if ( ( V_61 & V_121 ) && V_5 -> V_32 != V_49 )
F_33 ( V_91 L_9 ,
V_5 -> V_32 , F_17 ( V_3 ) , V_61 , V_1 ) ;
switch ( V_5 -> V_32 ) {
case V_110 :
if ( V_61 & V_63 ) {
F_6 ( & V_8 -> V_13 , V_64 | V_105 ) ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_22 ( & V_5 -> V_55 ) ;
V_5 -> V_54 = 0 ;
if ( V_8 -> V_122 == 0xff ) {
F_33 ( V_91 L_10 ) ;
V_5 -> V_72 = - 1 ;
if ( V_5 -> V_50 > 5 ) {
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
} else {
V_5 -> V_32 = V_115 ;
F_18 ( V_5 ) ;
}
break;
}
V_5 -> V_72 = V_8 -> V_122 ;
V_5 -> V_123 = V_8 -> V_124 ;
if ( V_5 -> V_71 != - 1 && V_5 -> V_71 != V_5 -> V_72 )
F_33 ( V_91 L_11 ,
V_5 -> V_71 , V_5 -> V_72 ) ;
V_5 -> V_32 = V_49 ;
F_18 ( V_5 ) ;
}
break;
case V_112 :
case V_115 :
if ( V_8 -> V_69 == 0 ) {
F_6 ( & V_8 -> V_13 , V_75 ) ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_22 ( & V_5 -> V_55 ) ;
V_5 -> V_54 = 0 ;
if ( V_5 -> V_32 == V_112 )
++ V_5 -> V_50 ;
V_5 -> V_32 = V_113 ;
F_18 ( V_5 ) ;
}
break;
case V_113 :
F_6 ( & V_8 -> V_62 , 0 ) ;
F_22 ( & V_5 -> V_55 ) ;
V_5 -> V_54 = 0 ;
F_18 ( V_5 ) ;
break;
case V_49 :
if ( ( V_61 & ( V_121 | V_108 ) ) == 0 )
break;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_6 ( & V_8 -> V_13 , V_105 | V_64 ) ;
F_6 ( & V_8 -> V_9 , V_10 ) ;
F_22 ( & V_5 -> V_55 ) ;
V_5 -> V_54 = 0 ;
V_89 = V_5 -> V_90 ;
V_79 = V_5 -> V_87 ;
if ( F_17 ( V_3 ) == V_41 )
++ V_79 ;
if ( ( V_61 & V_121 ) == 0 && V_79 -> V_86 == 0 ) {
for ( V_67 = 0 ; V_67 < 100 ; ++ V_67 ) {
if ( V_79 -> V_86 != 0 )
break;
F_8 ( 1 ) ;
F_38 () ;
}
}
F_34 ( & V_89 -> V_106 , ( V_107 | V_125 ) << 16 ) ;
V_18 = F_39 ( & V_79 -> V_86 ) ;
V_120 = F_39 ( & V_79 -> V_126 ) ;
if ( V_61 & V_121 ) {
V_67 = V_5 -> V_92 - 1 - V_120 / 512 ;
if ( V_67 > 0 ) {
F_40 ( V_3 , 0 , V_67 << 9 ) ;
V_5 -> V_48 += V_67 ;
}
if ( V_5 -> V_50 < 5 ) {
++ V_5 -> V_50 ;
F_18 ( V_5 ) ;
} else {
F_33 ( L_12 ,
F_17 ( V_3 ) == V_41 ? L_7 : L_8 ,
( long ) F_16 ( V_3 ) , V_1 ) ;
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
}
} else {
if ( ( V_18 & V_117 ) == 0 || V_120 != 0 ) {
F_33 ( V_91 L_13 , V_18 , V_120 ) ;
F_33 ( V_91 L_14 ,
V_5 -> V_32 , F_17 ( V_3 ) , V_61 , V_1 ) ;
F_3 ( - V_39 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
break;
}
if ( F_1 ( 0 , V_5 -> V_92 << 9 ) ) {
V_5 -> V_48 += V_5 -> V_92 ;
if ( V_5 -> V_48 > V_5 -> V_47 ) {
V_5 -> V_48 -= V_5 -> V_47 ;
if ( ++ V_5 -> V_46 > 1 ) {
V_5 -> V_46 = 0 ;
++ V_5 -> V_44 ;
}
}
F_18 ( V_5 ) ;
} else
V_5 -> V_32 = V_33 ;
}
if ( V_5 -> V_32 == V_33 )
F_13 ( V_5 ) ;
break;
default:
F_33 ( V_91 L_15 , V_5 -> V_32 ) ;
}
return V_127 ;
}
static int F_41 ( struct V_4 * V_5 , enum V_128 V_32 ,
int V_129 )
{
unsigned long V_52 ;
F_21 ( & V_5 -> V_53 , V_52 ) ;
if ( V_5 -> V_32 != V_33 ) {
++ V_5 -> V_34 ;
while ( V_5 -> V_32 != V_35 ) {
if ( V_129 && F_42 ( V_130 ) ) {
-- V_5 -> V_34 ;
F_24 ( & V_5 -> V_53 , V_52 ) ;
return - V_131 ;
}
F_43 ( & V_5 -> V_36 ) ;
}
-- V_5 -> V_34 ;
}
V_5 -> V_32 = V_32 ;
F_24 ( & V_5 -> V_53 , V_52 ) ;
return 0 ;
}
static void F_44 ( struct V_4 * V_5 )
{
unsigned long V_52 ;
F_21 ( & V_5 -> V_53 , V_52 ) ;
V_5 -> V_32 = V_33 ;
F_13 ( V_5 ) ;
F_24 ( & V_5 -> V_53 , V_52 ) ;
}
static int F_45 ( struct V_4 * V_5 )
{
int V_1 , V_67 ;
V_1 = F_41 ( V_5 , V_132 , 1 ) ;
if ( V_1 )
return V_1 ;
F_7 ( V_5 , V_133 ) ;
for ( V_67 = 20 ; V_67 > 0 ; -- V_67 ) {
if ( F_42 ( V_130 ) ) {
V_1 = - V_131 ;
break;
}
F_5 ( V_5 , V_10 ) ;
F_46 ( 1 ) ;
if ( F_9 ( V_5 , V_134 ) == 0 )
break;
}
F_5 ( V_5 , V_10 ) ;
F_8 ( 150 ) ;
V_5 -> V_40 = 1 ;
F_44 ( V_5 ) ;
return V_1 ;
}
static int F_47 ( struct V_135 * V_136 , T_3 V_137 ,
unsigned int V_80 , unsigned long V_138 )
{
struct V_4 * V_5 = V_136 -> V_139 -> V_140 ;
int V_1 ;
if ( ( V_80 & 0x80 ) && ! F_48 ( V_141 ) )
return - V_142 ;
if ( V_5 -> V_26 -> V_27 &&
F_12 ( V_5 -> V_26 -> V_27 ) != V_28 )
return - V_143 ;
switch ( V_80 ) {
case V_144 :
if ( V_5 -> V_145 != 1 )
return - V_146 ;
V_1 = F_45 ( V_5 ) ;
return V_1 ;
case V_147 :
if ( F_49 ( ( void V_148 * ) V_138 , & V_149 ,
sizeof( struct V_150 ) ) )
return - V_151 ;
return 0 ;
}
return - V_152 ;
}
static int F_50 ( struct V_135 * V_136 , T_3 V_137 ,
unsigned int V_80 , unsigned long V_138 )
{
int V_153 ;
F_51 ( & V_154 ) ;
V_153 = F_47 ( V_136 , V_137 , V_80 , V_138 ) ;
F_52 ( & V_154 ) ;
return V_153 ;
}
static int F_53 ( struct V_135 * V_136 , T_3 V_137 )
{
struct V_4 * V_5 = V_136 -> V_139 -> V_140 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
int V_67 , V_1 = 0 ;
if ( V_5 -> V_145 == 0 ) {
if ( V_5 -> V_26 -> V_27 &&
F_12 ( V_5 -> V_26 -> V_27 ) != V_28 )
return - V_143 ;
F_6 ( & V_8 -> V_155 , V_156 | V_157 ) ;
F_6 ( & V_8 -> V_13 , 0xff ) ;
F_6 ( & V_8 -> V_137 , 0x95 ) ;
F_8 ( 10 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_6 ( & V_8 -> V_11 , V_158 | V_159 ) ;
F_7 ( V_5 , V_160 ) ;
V_5 -> V_42 = - 1 ;
V_5 -> V_72 = - 1 ;
for ( V_67 = 0 ; V_67 < 2 * V_65 ; ++ V_67 ) {
if ( V_67 >= V_65 / 30 && F_9 ( V_5 , V_116 ) )
break;
if ( F_42 ( V_130 ) ) {
V_1 = - V_131 ;
break;
}
F_5 ( V_5 , V_10 ) ;
F_46 ( 1 ) ;
}
if ( V_1 == 0 && ( F_9 ( V_5 , V_116 ) == 0
|| F_9 ( V_5 , V_134 ) == 0 ) )
V_1 = - V_143 ;
F_7 ( V_5 , V_161 ) ;
F_5 ( V_5 , V_10 ) ;
} else if ( V_5 -> V_145 == - 1 || V_137 & V_162 )
return - V_146 ;
if ( V_1 == 0 && ( V_137 & V_163 ) == 0
&& ( V_137 & ( V_164 | V_165 ) ) ) {
F_54 ( V_136 ) ;
if ( V_5 -> V_40 )
V_1 = - V_143 ;
}
if ( V_1 == 0 && ( V_137 & V_165 ) ) {
if ( V_5 -> V_42 < 0 )
V_5 -> V_42 = F_9 ( V_5 , V_43 ) ;
if ( V_5 -> V_42 )
V_1 = - V_166 ;
}
if ( V_1 ) {
if ( V_5 -> V_145 == 0 ) {
F_7 ( V_5 , V_167 ) ;
F_6 ( & V_8 -> V_13 , V_158 | V_159 ) ;
F_5 ( V_5 , V_10 ) ;
}
return V_1 ;
}
if ( V_137 & V_162 )
V_5 -> V_145 = - 1 ;
else
++ V_5 -> V_145 ;
return 0 ;
}
static int F_55 ( struct V_135 * V_136 , T_3 V_137 )
{
int V_153 ;
F_51 ( & V_154 ) ;
V_153 = F_53 ( V_136 , V_137 ) ;
F_52 ( & V_154 ) ;
return V_153 ;
}
static int F_56 ( struct V_168 * V_169 , T_3 V_137 )
{
struct V_4 * V_5 = V_169 -> V_140 ;
struct V_7 T_1 * V_8 = V_5 -> V_7 ;
F_51 ( & V_154 ) ;
if ( V_5 -> V_145 > 0 && -- V_5 -> V_145 == 0 ) {
F_7 ( V_5 , V_167 ) ;
F_6 ( & V_8 -> V_13 , 0xff ) ;
F_5 ( V_5 , V_10 ) ;
}
F_52 ( & V_154 ) ;
return 0 ;
}
static unsigned int F_57 ( struct V_168 * V_169 ,
unsigned int V_170 )
{
struct V_4 * V_5 = V_169 -> V_140 ;
return V_5 -> V_40 ? V_171 : 0 ;
}
static int F_58 ( struct V_168 * V_169 )
{
struct V_4 * V_5 = V_169 -> V_140 ;
struct V_7 T_1 * V_8 ;
int V_153 , V_67 ;
if ( V_5 -> V_26 -> V_27 &&
F_12 ( V_5 -> V_26 -> V_27 ) != V_28 )
return - V_143 ;
V_8 = V_5 -> V_7 ;
F_41 ( V_5 , V_172 , 0 ) ;
F_6 ( & V_8 -> V_62 , 0 ) ;
F_6 ( & V_8 -> V_11 , V_158 ) ;
F_7 ( V_5 , V_160 ) ;
V_5 -> V_42 = - 1 ;
V_5 -> V_72 = - 1 ;
F_59 ( 1 ) ;
for ( V_67 = V_65 ; V_67 > 0 ; -- V_67 ) {
if ( F_9 ( V_5 , V_116 ) )
break;
if ( F_42 ( V_130 ) )
break;
F_5 ( V_5 , V_10 ) ;
F_46 ( 1 ) ;
}
V_153 = F_9 ( V_5 , V_116 ) == 0
|| F_9 ( V_5 , V_134 ) == 0 ;
if ( V_153 )
F_7 ( V_5 , V_167 ) ;
else {
V_5 -> V_40 = 0 ;
F_7 ( V_5 , V_161 ) ;
}
F_5 ( V_5 , V_10 ) ;
F_44 ( V_5 ) ;
return V_153 ;
}
static int F_60 ( struct V_173 * V_26 , int V_174 )
{
struct V_175 * V_176 = V_26 -> V_177 . V_178 . V_179 ;
struct V_4 * V_5 = & V_25 [ V_174 ] ;
int V_180 = - V_146 ;
if ( F_61 ( V_26 ) < 2 ) {
F_33 ( V_181 L_16 ,
V_174 , V_176 -> V_182 ) ;
return - V_143 ;
}
if ( F_62 ( V_26 ) < 2 ) {
F_33 ( V_181 L_17 ,
V_174 , V_176 -> V_182 ) ;
}
if ( F_63 ( V_26 , 0 , L_18 ) ) {
F_33 ( V_91 L_19 ,
V_174 , V_176 -> V_182 ) ;
return - V_146 ;
}
if ( F_63 ( V_26 , 1 , L_20 ) ) {
F_33 ( V_91 L_21 ,
V_174 , V_176 -> V_182 ) ;
F_64 ( V_26 , 0 ) ;
return - V_146 ;
}
F_65 ( & V_26 -> V_177 . V_178 , V_5 ) ;
if ( V_26 -> V_27 == NULL )
F_66 ( V_183 , V_176 , 0 , 1 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
F_67 ( & V_5 -> V_53 ) ;
V_5 -> V_32 = V_33 ;
V_5 -> V_7 = (struct V_7 T_1 * )
F_68 ( F_69 ( V_26 , 0 ) , 0x200 ) ;
if ( V_5 -> V_7 == NULL ) {
F_33 ( L_22 ,
V_174 , V_176 -> V_182 ) ;
V_180 = - V_184 ;
goto V_185;
}
V_5 -> V_90 = (struct V_88 T_1 * )
F_68 ( F_69 ( V_26 , 1 ) , 0x200 ) ;
if ( V_5 -> V_90 == NULL ) {
F_33 ( L_23 ,
V_174 , V_176 -> V_182 ) ;
F_70 ( V_5 -> V_7 ) ;
V_180 = - V_184 ;
goto V_185;
}
V_5 -> V_186 = F_71 ( V_26 , 0 ) ;
V_5 -> V_187 = F_71 ( V_26 , 1 ) ;
V_5 -> V_72 = - 1 ;
V_5 -> V_123 = - 1 ;
V_5 -> V_45 = 36 ;
V_5 -> V_47 = 18 ;
V_5 -> V_38 = 2880 ;
V_5 -> V_26 = V_26 ;
F_72 ( & V_5 -> V_36 ) ;
V_5 -> V_87 = (struct V_78 * ) F_73 ( V_5 -> V_188 ) ;
memset ( V_5 -> V_87 , 0 , 2 * sizeof( struct V_78 ) ) ;
F_28 ( & V_5 -> V_87 [ 1 ] . V_84 , V_104 ) ;
if ( F_74 ( V_5 -> V_186 , F_37 , 0 , L_24 , V_5 ) ) {
F_33 ( V_91 L_25 ,
V_174 , V_5 -> V_186 , V_176 -> V_182 ) ;
F_66 ( V_183 , V_176 , 0 , 0 ) ;
goto V_189;
return - V_146 ;
}
F_75 ( & V_5 -> V_55 ) ;
F_33 ( V_190 L_26 , V_24 ,
V_26 -> V_27 ? L_27 : L_28 ) ;
return 0 ;
V_189:
F_70 ( V_5 -> V_90 ) ;
F_70 ( V_5 -> V_7 ) ;
V_185:
F_64 ( V_26 , 0 ) ;
F_64 ( V_26 , 1 ) ;
return V_180 ;
}
static int T_4 F_76 ( struct V_173 * V_26 , const struct V_191 * V_192 )
{
int V_23 , V_180 ;
struct V_168 * V_169 ;
V_180 = F_60 ( V_26 , V_24 ) ;
if ( V_180 )
return V_180 ;
if ( V_37 == NULL ) {
if ( F_77 ( V_193 , L_29 ) )
return 0 ;
V_37 = F_78 ( F_11 , & V_194 ) ;
if ( V_37 == NULL ) {
F_79 ( V_193 , L_29 ) ;
return 0 ;
}
}
V_23 = V_24 ++ ;
V_169 = V_195 [ V_23 ] = F_80 ( 1 ) ;
if ( V_169 == NULL )
return 0 ;
V_169 -> V_196 = V_193 ;
V_169 -> V_197 = V_23 ;
V_169 -> V_198 = & V_199 ;
V_169 -> V_140 = & V_25 [ V_23 ] ;
V_169 -> V_200 = V_37 ;
V_169 -> V_52 |= V_201 ;
sprintf ( V_169 -> V_202 , L_30 , V_23 ) ;
F_81 ( V_169 , 2880 ) ;
F_82 ( V_169 ) ;
return 0 ;
}
int F_83 ( void )
{
F_84 ( & V_203 ) ;
return 0 ;
}
