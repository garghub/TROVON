static int F_1 ( struct V_1 * V_2 , void (* F_2)( struct V_1 * ) )
{
struct V_3 * V_4 ;
#if 0
if (cmd->sc_data_direction == DMA_TO_DEVICE) {
int i;
printk(KERN_DEBUG "mac53c94_queue %p: command is", cmd);
for (i = 0; i < cmd->cmd_len; ++i)
printk(KERN_CONT " %.2x", cmd->cmnd[i]);
printk(KERN_CONT "\n");
printk(KERN_DEBUG "use_sg=%d request_bufflen=%d request_buffer=%p\n",
scsi_sg_count(cmd), scsi_bufflen(cmd), scsi_sglist(cmd));
}
#endif
V_2 -> V_5 = F_2 ;
V_2 -> V_6 = NULL ;
V_4 = (struct V_3 * ) V_2 -> V_7 -> V_8 -> V_9 ;
if ( V_4 -> V_10 == NULL )
V_4 -> V_10 = V_2 ;
else
V_4 -> V_11 -> V_6 = ( void * ) V_2 ;
V_4 -> V_11 = V_2 ;
if ( V_4 -> V_12 == V_13 )
F_3 ( V_4 ) ;
return 0 ;
}
static void F_4 ( struct V_3 * V_4 )
{
struct V_14 T_1 * V_15 = V_4 -> V_15 ;
struct V_16 T_1 * V_17 = V_4 -> V_17 ;
int V_18 ;
F_5 ( V_4 -> V_8 -> V_19 | V_20 , & V_15 -> V_21 ) ;
F_5 ( F_6 ( 250 ) , & V_15 -> V_22 ) ;
F_5 ( F_7 ( V_4 -> V_23 ) , & V_15 -> V_24 ) ;
F_5 ( V_25 , & V_15 -> V_26 ) ;
F_5 ( 0 , & V_15 -> V_27 ) ;
F_5 ( 0 , & V_15 -> V_28 ) ;
F_5 ( 0 , & V_15 -> V_29 ) ;
V_18 = F_8 ( & V_15 -> V_30 ) ;
F_9 ( ( V_31 | V_32 | V_33 | V_34 ) << 16 , & V_17 -> V_35 ) ;
}
static void F_3 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
struct V_14 T_1 * V_15 = V_4 -> V_15 ;
int V_36 ;
if ( V_4 -> V_12 != V_13 || V_4 -> V_37 != NULL )
F_10 ( L_1 , V_4 ) ;
if ( V_4 -> V_10 == NULL )
return;
V_4 -> V_37 = V_2 = V_4 -> V_10 ;
V_4 -> V_10 = (struct V_1 * ) V_2 -> V_6 ;
F_5 ( 0 , & V_15 -> V_38 ) ;
F_5 ( 0 , & V_15 -> V_39 ) ;
F_5 ( 0 , & V_15 -> V_40 ) ;
F_5 ( V_41 + V_42 , & V_15 -> V_43 ) ;
F_11 ( 1 ) ;
F_5 ( V_44 , & V_15 -> V_43 ) ;
F_11 ( 1 ) ;
F_5 ( V_2 -> V_7 -> V_45 , & V_15 -> V_46 ) ;
F_5 ( 0 , & V_15 -> V_28 ) ;
F_5 ( 0 , & V_15 -> V_29 ) ;
for ( V_36 = 0 ; V_36 < V_2 -> V_47 ; ++ V_36 )
F_5 ( V_2 -> V_48 [ V_36 ] , & V_15 -> V_49 ) ;
F_5 ( V_50 , & V_15 -> V_43 ) ;
V_4 -> V_12 = V_51 ;
F_12 ( V_4 , V_2 ) ;
}
static T_2 F_13 ( int V_52 , void * V_53 )
{
unsigned long V_54 ;
struct V_55 * V_56 = ( (struct V_3 * ) V_53 ) -> V_37 -> V_7 -> V_8 ;
F_14 ( V_56 -> V_57 , V_54 ) ;
F_15 ( V_52 , V_53 ) ;
F_16 ( V_56 -> V_57 , V_54 ) ;
return V_58 ;
}
static void F_15 ( int V_52 , void * V_53 )
{
struct V_3 * V_4 = (struct V_3 * ) V_53 ;
struct V_14 T_1 * V_15 = V_4 -> V_15 ;
struct V_16 T_1 * V_17 = V_4 -> V_17 ;
struct V_1 * V_2 = V_4 -> V_37 ;
int V_59 , V_60 , V_61 , V_62 ;
static int V_63 ;
V_61 = F_8 ( & V_15 -> V_64 ) ;
V_60 = F_8 ( & V_15 -> V_65 ) ;
V_62 = F_8 ( & V_15 -> V_30 ) ;
#if 0
printk(KERN_DEBUG "mac53c94_intr, intr=%x stat=%x seq=%x phase=%d\n",
intr, stat, seq, state->phase);
#endif
if ( V_62 & V_66 ) {
F_17 ( V_67 L_2 ) ;
F_5 ( V_41 , & V_15 -> V_43 ) ;
F_9 ( V_31 << 16 , & V_17 -> V_35 ) ;
F_18 ( V_4 , V_68 << 16 ) ;
return;
}
if ( V_62 & V_69 ) {
F_17 ( V_70 L_3 ,
V_62 , V_60 , V_61 , V_4 -> V_12 ) ;
F_18 ( V_4 , V_71 << 16 ) ;
return;
}
if ( V_60 & V_72 ) {
#if 0
printk("53c94: bad error, intr=%x stat=%x seq=%x phase=%d\n",
intr, stat, seq, state->phase);
#endif
++ V_63 ;
F_5 ( V_41 + V_42 , & V_15 -> V_43 ) ;
}
if ( V_2 == 0 ) {
F_17 ( V_73 L_4 ) ;
return;
}
if ( V_60 & V_74 ) {
F_17 ( V_70 L_5 ) ;
F_18 ( V_4 , V_75 << 16 ) ;
return;
}
switch ( V_4 -> V_12 ) {
case V_51 :
if ( V_62 & V_76 ) {
F_18 ( V_4 , V_77 << 16 ) ;
return;
}
if ( V_62 != V_78 + V_79 ) {
F_17 ( V_73 L_6 , V_62 ) ;
F_18 ( V_4 , V_71 << 16 ) ;
return;
}
if ( ( V_61 & V_80 ) != V_81 ) {
F_17 ( V_73 L_7 , V_61 ) ;
F_18 ( V_4 , V_71 << 16 ) ;
return;
}
F_5 ( V_41 , & V_15 -> V_43 ) ;
if ( ( V_60 & ( V_82 | V_83 ) ) == 0
&& ( F_19 ( V_2 ) > 0 || F_20 ( V_2 ) ) ) {
V_59 = V_2 -> V_84 . V_85 ;
if ( V_59 > 0xfff0 )
V_59 = 0xfff0 ;
V_2 -> V_84 . V_85 -= V_59 ;
F_5 ( V_59 , & V_15 -> V_38 ) ;
F_5 ( V_59 >> 8 , & V_15 -> V_39 ) ;
F_5 ( V_42 + V_41 , & V_15 -> V_43 ) ;
F_9 ( F_21 ( V_4 -> V_86 ) , & V_17 -> V_87 ) ;
F_9 ( ( V_31 << 16 ) | V_31 , & V_17 -> V_35 ) ;
F_5 ( V_42 + V_88 , & V_15 -> V_43 ) ;
V_4 -> V_12 = V_89 ;
break;
} else if ( ( V_60 & V_90 ) == V_83 + V_91 ) {
F_5 ( V_92 , & V_15 -> V_43 ) ;
V_4 -> V_12 = V_93 ;
} else {
F_17 ( V_73 L_8 ,
V_60 & V_90 ) ;
F_18 ( V_4 , V_71 << 16 ) ;
return;
}
break;
case V_89 :
if ( V_62 != V_78 ) {
F_17 ( V_73 L_9 , V_62 ) ;
F_18 ( V_4 , V_71 << 16 ) ;
return;
}
if ( V_2 -> V_84 . V_85 != 0
&& ( V_60 & ( V_82 | V_83 ) ) == 0 ) {
V_59 = V_2 -> V_84 . V_85 ;
if ( V_59 > 0xfff0 )
V_59 = 0xfff0 ;
V_2 -> V_84 . V_85 -= V_59 ;
F_5 ( V_59 , & V_15 -> V_38 ) ;
F_5 ( V_59 >> 8 , & V_15 -> V_39 ) ;
F_5 ( V_42 + V_41 , & V_15 -> V_43 ) ;
F_5 ( V_42 + V_88 , & V_15 -> V_43 ) ;
break;
}
if ( ( V_60 & V_90 ) != V_83 + V_91 ) {
F_17 ( V_73 L_10 , V_62 ) ;
}
F_9 ( V_31 << 16 , & V_17 -> V_35 ) ;
F_22 ( V_2 ) ;
F_5 ( V_92 , & V_15 -> V_43 ) ;
V_4 -> V_12 = V_93 ;
break;
case V_93 :
if ( V_62 != V_79 ) {
F_17 ( V_73 L_11 , V_62 ) ;
F_18 ( V_4 , V_71 << 16 ) ;
return;
}
V_2 -> V_84 . V_94 = F_8 ( & V_15 -> V_49 ) ;
V_2 -> V_84 . V_95 = F_8 ( & V_15 -> V_49 ) ;
V_2 -> V_96 = V_97 ;
F_5 ( V_97 , & V_15 -> V_43 ) ;
V_4 -> V_12 = V_98 ;
break;
case V_98 :
if ( V_62 != V_76 ) {
F_17 ( V_73 L_12 , V_62 ) ;
}
F_18 ( V_4 , ( V_99 << 16 ) + ( V_2 -> V_84 . V_95 << 8 )
+ V_2 -> V_84 . V_94 ) ;
break;
default:
F_17 ( V_73 L_13 , V_4 -> V_12 ) ;
}
}
static void F_18 ( struct V_3 * V_4 , int V_96 )
{
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 ;
if ( V_2 != 0 ) {
V_2 -> V_96 = V_96 ;
(* V_2 -> V_5 )( V_2 ) ;
V_4 -> V_37 = NULL ;
}
V_4 -> V_12 = V_13 ;
F_3 ( V_4 ) ;
}
static void F_12 ( struct V_3 * V_4 , struct V_1 * V_2 )
{
int V_36 , V_100 , V_101 , V_102 ;
struct V_103 * V_104 ;
struct V_105 * V_106 ;
T_3 V_107 ;
T_4 V_108 ;
V_102 = F_23 ( V_2 ) ;
F_24 ( V_102 < 0 ) ;
if ( ! V_102 )
return;
V_100 = V_2 -> V_109 == V_110 ?
V_111 : V_112 ;
V_106 = V_4 -> V_86 ;
V_101 = 0 ;
F_25 (cmd, scl, nseg, i) {
V_107 = F_26 ( V_104 ) ;
V_108 = F_27 ( V_104 ) ;
if ( V_108 > 0xffff )
F_10 ( L_14 ) ;
V_101 += V_108 ;
V_106 -> V_113 = F_28 ( V_108 ) ;
V_106 -> V_43 = F_28 ( V_100 ) ;
V_106 -> V_114 = F_29 ( V_107 ) ;
V_106 -> V_115 = 0 ;
++ V_106 ;
}
V_100 += V_116 - V_111 ;
V_106 [ - 1 ] . V_43 = F_28 ( V_100 ) ;
V_106 -> V_43 = F_28 ( V_117 ) ;
V_2 -> V_84 . V_85 = V_101 ;
}
static int F_30 ( struct V_118 * V_119 , const struct V_120 * V_121 )
{
struct V_122 * V_123 = F_31 ( V_119 ) ;
struct V_124 * V_125 = F_32 ( V_119 ) ;
struct V_3 * V_4 ;
struct V_55 * V_8 ;
void * V_126 ;
const unsigned char * V_127 ;
int V_128 , V_129 = - V_130 ;
if ( F_33 ( V_119 ) != 2 || F_34 ( V_119 ) != 2 ) {
F_17 ( V_70 L_15
L_16 ,
F_33 ( V_119 ) , F_34 ( V_119 ) ) ;
return - V_130 ;
}
if ( F_35 ( V_119 , L_17 ) != 0 ) {
F_17 ( V_70 L_18 ) ;
return - V_131 ;
}
V_8 = F_36 ( & V_132 , sizeof( struct V_3 ) ) ;
if ( V_8 == NULL ) {
F_17 ( V_70 L_19 ) ;
V_129 = - V_133 ;
goto V_134;
}
V_4 = (struct V_3 * ) V_8 -> V_9 ;
F_37 ( V_119 , V_4 ) ;
V_4 -> V_8 = V_8 ;
V_4 -> V_125 = V_125 ;
V_4 -> V_119 = V_119 ;
V_4 -> V_15 = (struct V_14 T_1 * )
F_38 ( F_39 ( V_119 , 0 ) , 0x1000 ) ;
V_4 -> V_62 = F_40 ( V_119 , 0 ) ;
V_4 -> V_17 = (struct V_16 T_1 * )
F_38 ( F_39 ( V_119 , 1 ) , 0x1000 ) ;
V_4 -> V_135 = F_40 ( V_119 , 1 ) ;
if ( V_4 -> V_15 == NULL || V_4 -> V_17 == NULL ) {
F_17 ( V_70 L_20 ,
V_123 -> V_136 ) ;
goto V_137;
}
V_127 = F_41 ( V_123 , L_21 , & V_128 ) ;
if ( V_127 == NULL || V_128 != sizeof( int ) ) {
F_17 ( V_70 L_22
L_23 , V_123 -> V_136 ) ;
V_4 -> V_23 = 25000000 ;
} else
V_4 -> V_23 = * ( int * ) V_127 ;
V_126 = F_42 ( ( V_8 -> V_138 + 2 ) *
sizeof( struct V_105 ) , V_139 ) ;
if ( V_126 == 0 ) {
F_17 ( V_70 L_24
L_25 , V_123 -> V_136 ) ;
V_129 = - V_133 ;
goto V_137;
}
V_4 -> V_86 = (struct V_105 * ) F_43 ( V_126 ) ;
memset ( V_4 -> V_86 , 0 , ( V_8 -> V_138 + 1 )
* sizeof( struct V_105 ) ) ;
V_4 -> V_126 = V_126 ;
F_4 ( V_4 ) ;
if ( F_44 ( V_4 -> V_62 , F_13 , 0 , L_26 , V_4 ) ) {
F_17 ( V_70 L_27 ,
V_4 -> V_62 , V_123 -> V_136 ) ;
goto V_140;
}
V_129 = F_45 ( V_8 , & V_119 -> V_141 . V_56 ) ;
if ( V_129 != 0 )
goto V_142;
F_46 ( V_8 ) ;
return 0 ;
V_142:
F_47 ( V_4 -> V_62 , V_4 ) ;
V_140:
F_48 ( V_4 -> V_126 ) ;
V_137:
if ( V_4 -> V_17 != NULL )
F_49 ( V_4 -> V_17 ) ;
if ( V_4 -> V_15 != NULL )
F_49 ( V_4 -> V_15 ) ;
F_50 ( V_8 ) ;
V_134:
F_51 ( V_119 ) ;
return V_129 ;
}
static int F_52 ( struct V_118 * V_119 )
{
struct V_3 * V_143 = (struct V_3 * ) F_53 ( V_119 ) ;
struct V_55 * V_8 = V_143 -> V_8 ;
F_54 ( V_8 ) ;
F_47 ( V_143 -> V_62 , V_143 ) ;
if ( V_143 -> V_15 )
F_49 ( V_143 -> V_15 ) ;
if ( V_143 -> V_17 )
F_49 ( V_143 -> V_17 ) ;
F_48 ( V_143 -> V_126 ) ;
F_50 ( V_8 ) ;
F_51 ( V_119 ) ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return F_56 ( & V_144 ) ;
}
static void T_6 F_57 ( void )
{
return F_58 ( & V_144 ) ;
}
