static void
F_1 ( int V_1 )
{
F_2 ( V_1 ) ;
F_3 ( 0x01 , V_1 + V_2 ) ;
F_3 ( 0x00 , V_1 + V_3 ) ;
F_3 ( V_4 , V_1 + V_5 ) ;
F_3 ( V_6 , V_1 + V_7 ) ;
F_3 ( V_8 , V_1 + V_9 ) ;
F_3 ( V_10 , V_1 + V_11 ) ;
F_3 ( 0x05 , V_1 + V_12 ) ;
F_3 ( 0x9C , V_1 + V_13 ) ;
F_3 ( 0x05 , V_1 + V_14 ) ;
F_3 ( V_15 , V_1 + V_16 ) ;
}
static void
F_4 ( int V_1 )
{
F_3 ( V_4 , V_1 + V_5 ) ;
F_3 ( V_17 , V_1 + V_18 ) ;
F_3 ( V_19 , V_1 + V_18 ) ;
F_3 ( V_20 , V_1 + V_18 ) ;
F_1 ( V_1 ) ;
}
static T_1 int
F_5 ( int V_21 , int V_22 , unsigned char * V_23 , unsigned int V_24 )
{
int V_25 ;
int V_26 ;
F_2 ( V_22 ) ;
while ( V_24 ) {
V_25 = F_6 ( V_22 + V_2 ) ;
if ( V_25 & 0x80 )
return 0 ;
switch ( V_25 & 0x1e ) {
default:
case 0x10 :
V_26 = 0 ;
break;
case 0x0 :
V_26 = 1 ;
break;
case 0x8 :
V_26 = 42 ;
break;
case 0xc :
V_26 = 84 ;
break;
case 0xe :
V_26 = 128 ;
break;
}
if ( ( V_25 & 0x40 ) && V_26 == 0 ) {
return 0 ;
}
if ( V_26 ) {
if ( V_26 > V_24 )
V_26 = V_24 ;
if ( V_21 && V_26 > 3 ) {
F_7 ( V_22 + V_27 , V_23 , V_26 >> 2 ) ;
V_23 += V_26 & 0xfc ;
V_24 -= V_26 & 0xfc ;
} else {
while ( V_26 -- ) {
* V_23 ++ = F_6 ( V_22 + V_27 ) ;
V_24 -- ;
}
}
}
}
return 0 ;
}
static T_1 int
F_8 ( int V_21 , int V_22 , unsigned char * V_23 , unsigned int V_24 )
{
int V_25 = 0 ;
int V_26 ;
F_2 ( V_22 ) ;
while ( V_24 && ! ( V_25 & 0x40 ) ) {
V_25 = F_6 ( V_22 + V_2 ) ;
if ( V_25 & 0x80 )
return 0 ;
switch ( V_25 & 0x1e ) {
case 0x10 :
V_26 = 128 ;
break;
case 0x0 :
V_26 = 84 ;
break;
case 0x8 :
V_26 = 42 ;
break;
case 0xc :
V_26 = 1 ;
break;
default:
case 0xe :
V_26 = 0 ;
break;
}
if ( V_26 ) {
if ( V_26 > V_24 )
V_26 = V_24 ;
if ( V_21 && V_26 > 3 ) {
F_9 ( V_22 + V_27 , V_23 , V_26 >> 2 ) ;
V_23 += V_26 & 0xfc ;
V_24 -= V_26 & 0xfc ;
} else {
while ( V_26 -- ) {
F_3 ( * V_23 ++ , V_22 + V_27 ) ;
V_24 -- ;
}
}
}
}
return 0 ;
}
static T_2
F_10 ( int V_28 , void * V_29 )
{
unsigned long V_30 ;
struct V_31 * V_32 = V_29 ;
F_11 (unsigned char fifo_size;)
F_11 (unsigned char seq_reg;)
unsigned char V_33 , V_34 ;
unsigned char V_35 ;
int V_36 = V_32 -> V_1 ;
struct V_37 * V_38 =
(struct V_37 * ) V_32 -> V_39 ;
struct V_40 * V_41 = V_38 -> V_42 ;
int V_21 = V_38 -> V_21 ;
F_12 ( V_32 -> V_43 , V_30 ) ;
F_13 ( F_14 ( L_1 ) ) ;
F_2 ( V_36 ) ;
V_35 = F_6 ( V_36 + V_2 ) ;
F_15 ( V_36 ) ;
V_33 = F_6 ( V_36 + V_44 ) ;
F_11 ( V_45 = F_6 ( V_36 + V_46 ) ) ;
V_34 = F_6 ( V_36 + V_47 ) ;
F_11 ( V_48 = F_6 ( V_36 + V_49 ) & 0x1f ) ;
#if V_50
F_14 ( L_2 ,
V_33 , V_45 , V_34 , V_48 ) ;
F_14 ( L_3 , V_35 ) ;
#endif
if ( V_34 & 0x80 ) {
F_11 ( F_14 ( L_4 ) ) ;
V_41 -> V_51 = V_52 << 16 ;
goto V_53;
}
if ( V_35 & 0x80 ) {
F_14 ( L_5 ) ;
V_41 -> V_51 = V_54 << 16 ;
goto V_53;
}
if ( V_33 & 0x20 ) {
F_14 ( L_6 ) ;
V_41 -> V_51 = V_55 << 16 ;
goto V_53;
}
if ( V_33 & 0x40 ) {
F_14 ( L_7 ) ;
V_41 -> V_51 = V_54 << 16 ;
goto V_53;
}
if ( V_34 & 0x20 ) {
F_11 ( F_14 ( L_8 ) ) ;
if ( V_41 -> V_56 . V_57 != V_58 ) {
V_41 -> V_51 = V_59 << 16 ;
} else {
V_41 -> V_51 = ( V_41 -> V_56 . V_60 & 0xff )
| ( ( V_41 -> V_56 . V_61 & 0xff ) << 8 ) | ( V_62 << 16 ) ;
}
goto V_53;
}
switch ( V_33 & 0x07 ) {
case 0x00 :
if ( V_34 & 0x10 ) {
struct V_63 * V_64 ;
int V_25 ;
V_41 -> V_56 . V_57 = V_65 ;
F_13 ( F_14 ( L_9 ) ) ;
F_3 ( V_66 , V_36 + V_18 ) ;
F_16 ( V_36 , F_17 ( V_41 ) ) ;
F_3 ( V_67 | V_68 , V_36 + V_18 ) ;
F_18 (curSC, sg, scsi_sg_count(curSC), i) {
F_8 ( V_21 , V_36 ,
F_19 ( V_64 ) , V_64 -> V_69 ) ;
}
F_15 ( V_36 ) ;
}
break;
case 0x01 :
if ( V_34 & 0x10 ) {
struct V_63 * V_64 ;
int V_25 ;
V_41 -> V_56 . V_57 = V_70 ;
F_13 ( F_14 ( L_10 ) ) ;
F_3 ( V_66 , V_36 + V_18 ) ;
F_16 ( V_36 , F_17 ( V_41 ) ) ;
F_3 ( V_67 | V_68 , V_36 + V_18 ) ;
F_18 (curSC, sg, scsi_sg_count(curSC), i) {
F_5 ( V_21 , V_36 ,
F_19 ( V_64 ) , V_64 -> V_69 ) ;
}
F_15 ( V_36 ) ;
}
break;
case 0x02 :
V_41 -> V_56 . V_57 = V_71 ;
F_14 ( L_11 ) ;
break;
case 0x03 :
V_41 -> V_56 . V_57 = V_72 ;
F_13 ( F_14 ( L_12 ) ) ;
F_3 ( V_66 , V_36 + V_18 ) ;
F_3 ( V_73 , V_36 + V_18 ) ;
break;
case 0x04 :
case 0x05 :
F_14 ( L_13 ) ;
break;
case 0x06 :
F_11 ( F_14 ( L_14 ) ) ;
V_41 -> V_56 . V_57 = V_74 ;
F_3 ( V_75 , V_36 + V_18 ) ;
F_3 ( V_76 , V_36 + V_18 ) ;
break;
case 0x07 :
F_13 ( F_14 ( L_15 ) ) ;
V_41 -> V_56 . V_57 = V_58 ;
V_41 -> V_56 . V_60 = F_6 ( V_36 + V_77 ) ;
V_41 -> V_56 . V_61 = F_6 ( V_36 + V_77 ) ;
F_13 ( F_14 ( L_16 , F_6 ( V_36 + V_49 ) & 0x1f ) ) ;
F_11 ( F_14 ( L_17 , V_41 -> V_56 . V_60 , V_41 -> V_56 . V_61 ) ) ;
if ( V_41 -> V_56 . V_61 == V_78 || V_41 -> V_56 . V_61 == V_79 ) {
F_3 ( V_75 , V_36 + V_18 ) ;
F_11 ( F_14 ( L_18 ) ) ;
}
F_3 ( V_76 , V_36 + V_18 ) ;
break;
}
V_80:
F_20 ( V_32 -> V_43 , V_30 ) ;
return V_81 ;
V_53:
V_41 -> V_56 . V_57 = V_82 ;
V_41 -> V_83 ( V_41 ) ;
goto V_80;
}
static void
F_21 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_88 ;
struct V_31 * V_89 = V_87 -> V_90 ;
F_22 ( & V_85 -> V_32 , L_19 ) ;
F_23 ( V_89 ) ;
if ( V_89 -> V_28 )
F_24 ( V_89 -> V_28 , V_89 ) ;
if ( V_89 -> V_1 && V_89 -> V_91 )
F_25 ( V_89 -> V_1 , V_89 -> V_91 ) ;
F_26 ( V_85 ) ;
F_27 ( V_89 ) ;
}
static const char *
F_28 ( struct V_31 * V_92 )
{
static char V_93 [ 256 ] ;
struct V_37 * V_38 =
(struct V_37 * ) V_92 -> V_39 ;
F_11 ( F_14 ( L_20 ) ) ;
( void ) snprintf ( V_93 , sizeof( V_93 ) ,
L_21 ,
V_92 -> V_1 , V_92 -> V_28 , V_38 -> V_21 ? L_22 : L_23 ) ;
return ( V_93 ) ;
}
static int
F_29 ( struct V_40 * V_94 , void (* F_30)( struct V_40 * ) )
{
int V_25 ;
int V_36 = V_94 -> V_95 -> V_90 -> V_1 ;
struct V_37 * V_38 =
(struct V_37 * ) V_94 -> V_95 -> V_90 -> V_39 ;
F_13 ( F_14 ( L_24 ) ) ;
F_11 ( F_14 ( L_25 ,
V_94 -> V_96 [ 0 ] , V_94 -> V_97 , V_94 -> V_95 -> V_98 ,
( V_99 ) V_94 -> V_95 -> V_100 , F_17 ( V_94 ) ) ) ;
F_13 (for (i = 0; i < SCpnt->cmd_len; i++)
printk(L_26, i, SCpnt->cmnd[i])) ;
F_13 ( F_14 ( L_27 ) ) ;
V_38 -> V_42 = V_94 ;
V_38 -> V_42 -> V_83 = F_30 ;
V_38 -> V_42 -> V_56 . V_57 = V_71 ;
V_38 -> V_42 -> V_56 . V_60 = 0 ;
V_38 -> V_42 -> V_56 . V_61 = 0 ;
F_15 ( V_36 ) ;
F_3 ( F_31 ( V_94 ) , V_36 + V_101 ) ;
F_3 ( V_66 , V_36 + V_18 ) ;
for ( V_25 = 0 ; V_25 < V_94 -> V_97 ; V_25 ++ ) {
F_3 ( V_94 -> V_96 [ V_25 ] , V_36 + V_77 ) ;
}
F_3 ( V_102 , V_36 + V_18 ) ;
return 0 ;
}
static int
F_32 ( struct V_103 * V_104 ,
struct V_105 * V_32 ,
T_3 V_106 , int * V_107 )
{
int V_108 ;
F_11 ( F_14 ( L_28 ) ) ;
V_108 = V_106 ;
V_107 [ 0 ] = 64 ;
V_107 [ 1 ] = 32 ;
V_107 [ 2 ] = V_108 >> 11 ;
if ( V_107 [ 2 ] > 1024 ) {
V_107 [ 0 ] = 255 ;
V_107 [ 1 ] = 63 ;
V_107 [ 2 ] = V_108 / ( 255 * 63 ) ;
}
return 0 ;
}
static T_4
F_33 ( struct V_95 * V_32 , struct V_109 * V_110 ,
char * V_111 )
{
struct V_31 * V_112 = F_34 ( V_32 ) ;
struct V_37 * V_38 =
(struct V_37 * ) V_112 -> V_39 ;
return snprintf ( V_111 , 4 , L_29 , V_38 -> V_21 ) ;
}
static T_4
F_35 ( struct V_95 * V_32 , struct V_109 * V_110 ,
const char * V_111 , T_5 V_113 )
{
int V_114 ;
struct V_31 * V_112 = F_34 ( V_32 ) ;
struct V_37 * V_38 =
(struct V_37 * ) V_112 -> V_39 ;
V_114 = F_36 ( V_111 , NULL , 0 ) ;
if ( V_114 == 0 || V_114 == 1 ) {
V_38 -> V_21 = V_114 ;
return V_113 ;
}
else
return - V_115 ;
}
static int F_37 ( struct V_84 * V_116 , void * V_117 )
{
V_116 -> V_118 = 10 ;
V_116 -> V_119 [ 0 ] -> V_30 &= ~ V_120 ;
V_116 -> V_119 [ 0 ] -> V_30 |= V_121 ;
if ( V_116 -> V_119 [ 0 ] -> V_122 == 0 )
return - V_123 ;
return F_38 ( V_116 ) ;
}
static int
F_39 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_88 ;
int V_124 ;
int V_125 , V_36 ;
struct V_31 * V_90 ;
struct V_126 * V_127 = & V_128 ;
struct V_37 * V_38 ;
F_22 ( & V_85 -> V_32 , L_30 ) ;
V_87 -> V_129 = V_85 -> V_129 ;
V_124 = F_40 ( V_85 , F_37 , NULL ) ;
if ( V_124 )
goto V_130;
if ( ! V_85 -> V_28 )
goto V_130;
V_124 = F_41 ( V_85 ) ;
if ( V_124 )
goto V_130;
if ( ( V_87 -> V_129 == V_131 ) ||
( V_87 -> V_129 == V_132 ) ||
( V_87 -> V_129 == 0x0098 ) ) {
F_3 ( 0xb4 , V_85 -> V_119 [ 0 ] -> V_122 + 0xd ) ;
F_3 ( 0x24 , V_85 -> V_119 [ 0 ] -> V_122 + 0x9 ) ;
F_3 ( 0x04 , V_85 -> V_119 [ 0 ] -> V_122 + 0xd ) ;
}
V_36 = V_85 -> V_119 [ 0 ] -> V_122 ;
V_125 = V_85 -> V_28 ;
F_11 (printk(L_31,
port_base, irq_level, USE_FAST_PIO);)
F_1 ( V_36 ) ;
V_90 = F_42 ( V_127 , sizeof( struct V_37 ) ) ;
if ( ! V_90 ) {
F_14 ( L_32 ) ;
goto V_133;
}
V_38 = (struct V_37 * ) V_90 -> V_39 ;
if ( V_125 > 0 ) {
if ( F_43 ( V_125 , F_10 , V_134 , L_33 , V_90 ) ) {
F_14 ( L_34 , V_125 ) ;
goto V_135;
}
F_11 ( F_14 ( L_35 , V_125 ) ) ;
} else if ( V_125 == 0 ) {
F_11 ( F_14 ( L_36 ) ) ;
goto V_135;
} else {
F_11 ( F_14 ( L_37 ) ) ;
goto V_135;
}
V_90 -> V_136 = V_36 ;
V_90 -> V_28 = V_125 ;
V_90 -> V_1 = V_36 ;
V_90 -> V_91 = 0x10 ;
V_90 -> V_137 = - 1 ;
V_38 -> V_21 = V_138 ;
V_87 -> V_90 = V_90 ;
if ( F_44 ( V_90 , NULL ) )
goto V_139;
F_45 ( V_90 ) ;
return 0 ;
V_139:
F_24 ( V_125 , V_90 ) ;
V_135:
F_27 ( V_90 ) ;
V_133:
F_25 ( V_36 , 0x10 ) ;
F_14 ( V_140 L_38 ) ;
return - V_123 ;
V_130:
F_21 ( V_85 ) ;
return - V_123 ;
}
static int F_46 ( struct V_84 * V_85 )
{
struct V_86 * V_87 = V_85 -> V_88 ;
if ( ( V_87 -> V_129 == V_131 ) ||
( V_87 -> V_129 == V_132 ) ||
( V_87 -> V_129 == 0x0098 ) ) {
F_3 ( 0x80 , V_85 -> V_119 [ 0 ] -> V_122 + 0xd ) ;
F_3 ( 0x24 , V_85 -> V_119 [ 0 ] -> V_122 + 0x9 ) ;
F_3 ( 0x04 , V_85 -> V_119 [ 0 ] -> V_122 + 0xd ) ;
}
F_4 ( V_85 -> V_119 [ 0 ] -> V_122 ) ;
return 0 ;
}
static void
F_47 ( struct V_84 * V_85 )
{
F_22 ( & V_85 -> V_32 , L_39 ) ;
F_21 ( V_85 ) ;
F_48 ( V_85 -> V_88 ) ;
V_85 -> V_88 = NULL ;
}
static int
F_49 ( struct V_84 * V_85 )
{
struct V_86 * V_87 ;
F_22 ( & V_85 -> V_32 , L_40 ) ;
V_87 = F_50 ( sizeof( * V_87 ) , V_141 ) ;
if ( ! V_87 )
return - V_142 ;
V_87 -> V_116 = V_85 ;
V_85 -> V_88 = V_87 ;
V_85 -> V_143 |= V_144 | V_145 ;
return F_39 ( V_85 ) ;
}
static int T_6
F_51 ( void )
{
return F_52 ( & V_146 ) ;
}
static void T_7
F_53 ( void )
{
F_54 ( & V_146 ) ;
}
