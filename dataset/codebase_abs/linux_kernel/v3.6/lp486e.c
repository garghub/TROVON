static inline T_1
F_1 ( void * V_1 ) {
return V_1 ? F_2 ( V_1 ) : V_2 ;
}
static inline void *
F_3 ( T_1 V_1 ) {
return ( V_1 == V_2 ) ? NULL : F_4 ( V_1 ) ;
}
static int
F_5 ( struct V_3 * V_4 , char * V_5 , int V_6 ) {
struct V_7 * V_8 ;
int V_9 = V_6 ;
V_8 = F_6 ( V_4 ) ;
while ( V_8 -> V_10 . V_11 ) {
if ( -- V_9 == 0 ) {
F_7 ( L_1 ,
V_4 -> V_12 , V_5 ,
V_8 -> V_10 . V_13 , V_8 -> V_10 . V_11 ) ;
return 1 ;
}
F_8 ( 5 ) ;
F_9 () ;
}
return 0 ;
}
static inline int
F_10 ( struct V_3 * V_4 , int V_14 ) {
struct V_7 * V_8 ;
struct V_15 * V_16 ;
int V_17 ;
V_8 = F_6 ( V_4 ) ;
V_8 -> V_10 . V_18 = V_2 ;
for ( V_17 = 0 ; V_17 < V_14 ; V_17 ++ ) {
V_16 = F_11 ( sizeof( struct V_15 ) , V_19 ) ;
if ( V_16 == NULL )
break;
V_16 -> V_20 = 0 ;
V_16 -> V_21 = V_2 ;
V_16 -> V_22 = 0 ;
V_16 -> V_23 = 1532 ;
if ( V_17 == 0 ) {
V_16 -> V_24 = V_25 ;
V_8 -> V_26 = V_16 ;
} else {
V_16 -> V_24 = 0 ;
}
V_16 -> V_27 = V_8 -> V_10 . V_18 ;
V_8 -> V_10 . V_18 = F_1 ( V_16 ) ;
V_8 -> V_26 -> V_27 = V_8 -> V_10 . V_18 ;
}
#if 0
for (i = 0; i<RX_RBD_SIZE; i++) {
rbd = kmalloc(sizeof(struct i596_rbd), GFP_KERNEL);
if (rbd) {
rbd->pad = 0;
rbd->count = 0;
rbd->skb = dev_alloc_skb(RX_SKBSIZE);
if (!rbd->skb) {
printk("dev_alloc_skb failed");
}
rbd->next = rfd->rbd;
if (i) {
rfd->rbd->prev = rbd;
rbd->size = RX_SKBSIZE;
} else {
rbd->size = (RX_SKBSIZE | RBD_EL);
lp->rbd_tail = rbd;
}
rfd->rbd = rbd;
}
}
lp->rbd_tail->next = rfd->rbd;
#endif
return V_17 ;
}
static inline void
F_12 ( struct V_3 * V_4 ) {
struct V_7 * V_8 ;
struct V_15 * V_16 ;
V_8 = F_6 ( V_4 ) ;
V_8 -> V_26 -> V_27 = V_2 ;
do {
V_16 = F_3 ( V_8 -> V_10 . V_18 ) ;
V_8 -> V_10 . V_18 = V_16 -> V_27 ;
F_13 ( V_16 ) ;
} while ( V_16 != V_8 -> V_26 );
V_8 -> V_26 = NULL ;
#if 0
for (lp->rbd_list) {
}
#endif
}
static inline void
F_14 ( T_1 V_28 , unsigned int V_24 ) {
if ( V_28 & 0xf )
F_7 ( L_2 ) ;
F_15 ( ( ( V_28 & 0xffff ) | V_24 ) , V_29 ) ;
F_15 ( ( ( V_28 >> 16 ) & 0xffff ) , V_29 + 2 ) ;
}
static inline void
F_16 ( void ) {
F_17 ( 0 , V_29 + 4 ) ;
F_8 ( 8 ) ;
}
static inline void
F_18 ( void ) {
F_17 ( 0 , V_29 + 8 ) ;
}
static int
F_19 ( struct V_3 * V_4 ) {
struct V_7 * V_8 = F_6 ( V_4 ) ;
int V_9 ;
V_8 -> V_30 . V_31 = 0x00440000 ;
V_8 -> V_30 . V_32 = 0 ;
V_8 -> V_30 . V_33 = F_1 ( & ( V_8 -> V_34 ) ) ;
V_8 -> V_34 . V_35 = 0x0001 ;
V_8 -> V_34 . V_36 = F_1 ( & ( V_8 -> V_10 ) ) ;
V_8 -> V_10 . V_11 = 0 ;
V_8 -> V_10 . V_13 = 0 ;
V_8 -> V_10 . V_37 = V_2 ;
V_8 -> V_38 = V_39 ;
V_8 -> V_40 = 0 ;
V_8 -> V_41 = NULL ;
F_14 ( 0 , V_42 ) ;
F_8 ( 100 ) ;
F_14 ( F_1 ( & V_8 -> V_30 ) , V_43 ) ;
F_16 () ;
V_9 = 100 ;
while ( V_8 -> V_34 . V_35 ) {
if ( -- V_9 == 0 ) {
F_7 ( L_3 ,
V_4 -> V_12 ) ;
return 1 ;
}
F_8 ( 5 ) ;
F_9 () ;
}
return 0 ;
}
static int
F_20 ( struct V_3 * V_4 ) {
struct V_7 * V_8 ;
if ( F_19 ( V_4 ) )
return 1 ;
V_8 = F_6 ( V_4 ) ;
V_8 -> V_10 . V_11 = 0 ;
memcpy ( ( void * ) V_8 -> V_44 , V_45 , 14 ) ;
V_8 -> V_46 . V_11 = V_47 ;
F_21 ( V_4 , ( void * ) & V_8 -> V_46 ) ;
memcpy ( ( void * ) V_8 -> V_48 , V_4 -> V_49 , 6 ) ;
V_8 -> V_50 . V_11 = V_51 ;
F_21 ( V_4 , & V_8 -> V_50 ) ;
V_8 -> V_52 . V_11 = V_53 ;
F_21 ( V_4 , & V_8 -> V_52 ) ;
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_4 , 200 ) )
return 1 ;
V_8 -> V_10 . V_11 = V_54 ;
F_16 () ;
F_9 () ;
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_5 , 100 ) )
return 1 ;
return 0 ;
}
static inline int
F_22 ( struct V_3 * V_4 , struct V_7 * V_8 ,
struct V_15 * V_16 , int * V_55 ) {
if ( V_16 -> V_20 & V_56 ) {
int V_57 = ( V_16 -> V_22 & 0x3fff ) ;
struct V_58 * V_59 = F_23 ( V_4 , V_57 ) ;
( * V_55 ) ++ ;
if ( V_16 -> V_24 & V_25 )
F_7 ( L_6 ) ;
if ( V_59 == NULL ) {
F_7 ( L_7
L_8 , V_4 -> V_12 ) ;
V_4 -> V_60 . V_61 ++ ;
return 1 ;
}
memcpy ( F_24 ( V_59 , V_57 ) , V_16 -> V_62 , V_57 ) ;
V_59 -> V_63 = F_25 ( V_59 , V_4 ) ;
F_26 ( V_59 ) ;
V_4 -> V_60 . V_64 ++ ;
} else {
#if 0
printk("Frame reception error status %04x\n",
rfd->stat);
#endif
V_4 -> V_60 . V_65 ++ ;
if ( V_16 -> V_20 & V_66 )
V_4 -> V_60 . V_67 ++ ;
if ( V_16 -> V_20 & V_68 )
V_4 -> V_60 . V_69 ++ ;
if ( V_16 -> V_20 & V_70 )
V_4 -> V_60 . V_71 ++ ;
if ( V_16 -> V_20 & V_72 )
V_4 -> V_60 . V_73 ++ ;
if ( V_16 -> V_20 & V_74 )
V_4 -> V_60 . V_75 ++ ;
if ( V_16 -> V_20 & V_76 )
V_4 -> V_60 . V_77 ++ ;
if ( V_16 -> V_20 & V_78 )
V_4 -> V_60 . V_69 ++ ;
}
V_16 -> V_20 = V_16 -> V_22 = 0 ;
return 0 ;
}
static int
F_27 ( struct V_3 * V_4 ) {
struct V_7 * V_8 = F_6 ( V_4 ) ;
struct V_15 * V_16 ;
int V_55 = 0 ;
while ( 1 ) {
V_16 = F_3 ( V_8 -> V_10 . V_18 ) ;
if ( ! V_16 ) {
F_7 ( V_79 L_9 ) ;
return 0 ;
}
#if 1
if ( V_16 -> V_20 && ! ( V_16 -> V_20 & ( V_80 | V_81 ) ) )
F_7 ( L_10 , V_16 , V_16 -> V_20 ) ;
#endif
if ( ! ( V_16 -> V_20 & V_80 ) )
break;
if ( F_22 ( V_4 , V_8 , V_16 , & V_55 ) )
break;
V_16 -> V_24 = V_25 ;
V_8 -> V_26 -> V_24 = 0 ;
V_8 -> V_26 = V_16 ;
V_8 -> V_10 . V_18 = V_16 -> V_27 ;
F_9 () ;
}
return V_55 ;
}
static void
F_28 ( struct V_3 * V_4 ) {
struct V_7 * V_8 ;
struct V_82 * V_24 ;
V_8 = F_6 ( V_4 ) ;
while ( V_8 -> V_41 ) {
V_24 = V_8 -> V_41 ;
V_8 -> V_41 = F_3 ( V_8 -> V_41 -> V_27 ) ;
V_8 -> V_40 -- ;
switch ( ( V_24 -> V_11 ) & 0x7 ) {
case V_83 : {
struct V_84 * V_84 = (struct V_84 * ) V_24 ;
struct V_85 * V_86 ;
V_86 = F_3 ( V_84 -> V_87 ) ;
F_29 ( V_86 -> V_59 ) ;
V_4 -> V_60 . V_88 ++ ;
V_4 -> V_60 . V_89 ++ ;
V_24 -> V_27 = V_2 ;
F_13 ( ( unsigned char * ) V_84 ) ;
F_30 ( V_4 ) ;
break;
}
case V_90 : {
V_24 -> V_27 = V_2 ;
F_13 ( ( unsigned char * ) V_24 ) ;
break;
}
default: {
V_24 -> V_27 = V_2 ;
break;
}
}
F_9 () ;
}
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_11 , 100 ) )
;
V_8 -> V_10 . V_37 = F_1 ( V_8 -> V_41 ) ;
}
static void F_31 ( struct V_3 * V_4 , struct V_7 * V_8 , int V_91 ) {
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_12 , 100 ) )
;
F_32 ( V_4 ) ;
V_8 -> V_10 . V_11 = V_92 | V_93 ;
F_16 () ;
F_9 () ;
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_13 , 400 ) )
;
F_28 ( V_4 ) ;
F_27 ( V_4 ) ;
F_33 ( V_4 ) ;
F_20 ( V_4 ) ;
}
static void F_21 ( struct V_3 * V_4 , struct V_82 * V_24 ) {
struct V_7 * V_8 = F_6 ( V_4 ) ;
int V_91 = V_4 -> V_94 ;
unsigned long V_95 ;
V_24 -> V_13 = 0 ;
V_24 -> V_11 |= ( V_25 | V_96 ) ;
V_24 -> V_27 = V_2 ;
F_34 ( & V_8 -> V_97 , V_95 ) ;
if ( V_8 -> V_41 ) {
V_8 -> V_98 -> V_27 = F_1 ( V_24 ) ;
} else {
V_8 -> V_41 = V_24 ;
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_14 , 100 ) )
;
V_8 -> V_10 . V_37 = F_1 ( V_24 ) ;
V_8 -> V_10 . V_11 = V_99 ;
F_16 () ;
}
V_8 -> V_98 = V_24 ;
V_8 -> V_40 ++ ;
V_8 -> V_41 = F_3 ( V_8 -> V_10 . V_37 ) ;
F_35 ( & V_8 -> V_97 , V_95 ) ;
if ( V_8 -> V_40 > 16 ) {
int V_100 = V_39 - V_8 -> V_38 ;
if ( V_100 < V_101 / 4 )
return;
F_7 ( V_102 L_15 , V_4 -> V_12 ) ;
F_31 ( V_4 , V_8 , V_91 ) ;
}
}
static int F_36 ( struct V_3 * V_4 )
{
int V_17 ;
V_17 = F_37 ( V_4 -> V_103 , V_104 , V_105 , V_4 -> V_12 , V_4 ) ;
if ( V_17 ) {
F_7 ( V_79 L_16 , V_4 -> V_12 , V_4 -> V_103 ) ;
return V_17 ;
}
if ( ( V_17 = F_10 ( V_4 , V_106 ) ) < V_106 )
F_7 ( V_79 L_17 , V_4 -> V_12 , V_17 ) ;
if ( V_17 < 4 ) {
F_38 ( V_4 -> V_103 , V_4 ) ;
return - V_107 ;
}
F_33 ( V_4 ) ;
F_20 ( V_4 ) ;
return 0 ;
}
static T_2 F_39 ( struct V_58 * V_59 , struct V_3 * V_4 ) {
struct V_84 * V_84 ;
short V_108 ;
V_108 = V_59 -> V_109 ;
if ( V_108 < V_110 ) {
if ( F_40 ( V_59 , V_110 ) )
return V_111 ;
V_108 = V_110 ;
}
V_84 = F_11 ( ( sizeof ( struct V_84 ) + sizeof ( struct V_85 ) ) , V_112 ) ;
if ( V_84 == NULL ) {
F_7 ( V_102 L_18 , V_4 -> V_12 ) ;
V_4 -> V_60 . V_113 ++ ;
F_41 ( V_59 ) ;
} else {
struct V_85 * V_86 ;
V_86 = (struct V_85 * ) ( V_84 + 1 ) ;
V_84 -> V_87 = F_1 ( V_86 ) ;
V_86 -> V_27 = V_2 ;
V_84 -> V_24 . V_11 = ( V_114 | V_83 ) ;
V_84 -> V_32 = 0 ;
V_84 -> V_23 = 0 ;
V_86 -> V_32 = 0 ;
V_86 -> V_23 = ( V_115 | V_108 ) ;
V_86 -> V_116 = F_1 ( V_59 -> V_62 ) ;
V_86 -> V_59 = V_59 ;
if ( V_117 & V_118 )
F_42 ( V_59 -> V_62 ) ;
F_21 ( V_4 , (struct V_82 * ) V_84 ) ;
V_4 -> V_60 . V_119 ++ ;
}
return V_111 ;
}
static void
F_43 ( struct V_3 * V_4 ) {
struct V_7 * V_8 = F_6 ( V_4 ) ;
int V_91 = V_4 -> V_94 ;
F_7 ( V_102 L_19 , V_4 -> V_12 ) ;
V_4 -> V_60 . V_88 ++ ;
if ( V_8 -> V_120 == V_4 -> V_60 . V_119 ) {
F_7 ( L_20 ) ;
F_31 ( V_4 , V_8 , V_91 ) ;
} else {
F_7 ( L_21 ) ;
V_8 -> V_10 . V_11 = ( V_99 | V_54 ) ;
F_16 () ;
V_8 -> V_120 = V_4 -> V_60 . V_119 ;
}
F_30 ( V_4 ) ;
}
static void F_42 ( char * V_121 )
{
int V_17 ;
F_7 ( L_22 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ )
F_7 ( L_23 , ( unsigned char ) V_121 [ V_17 ] ) ;
F_7 ( L_24 ) ;
F_7 ( L_25 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ )
F_7 ( L_23 , ( unsigned char ) V_121 [ V_17 + 6 ] ) ;
F_7 ( L_24 ) ;
F_7 ( L_26 ,
( unsigned char ) V_121 [ 12 ] , ( unsigned char ) V_121 [ 13 ] ) ;
}
static int T_3 F_44 ( struct V_3 * V_4 ) {
struct V_7 * V_8 ;
unsigned char V_48 [ 6 ] = { 0 , 0xaa , 0 , 0 , 0 , 0 } ;
unsigned char * V_122 ;
int V_17 , V_123 ;
int V_124 = - V_125 ;
static int V_126 ;
if ( V_126 )
return - V_127 ;
V_126 ++ ;
if ( ! F_45 ( V_29 , V_128 , V_129 ) ) {
F_7 ( V_79 L_27 , V_29 ) ;
return - V_130 ;
}
V_8 = F_6 ( V_4 ) ;
F_46 ( & V_8 -> V_97 ) ;
if ( F_19 ( V_4 ) ) {
V_124 = - V_127 ;
goto V_131;
}
V_4 -> V_94 = V_29 ;
V_4 -> V_103 = V_132 ;
V_122 = F_4 ( 0xe8000 ) ;
for ( V_123 = 0 ; V_123 < 0x2000 ; V_123 ++ ) {
if ( V_122 [ V_123 ] == 0 && V_122 [ V_123 + 1 ] == 0xaa && V_122 [ V_123 + 2 ] == 0 ) {
F_7 ( L_28 ,
V_4 -> V_12 , 0xe8000 + V_123 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ ) {
V_48 [ V_17 ] = V_122 [ V_17 + V_123 ] ;
F_7 ( L_23 , V_48 [ V_17 ] ) ;
}
F_7 ( L_24 ) ;
}
}
F_7 ( L_29 ,
V_4 -> V_12 , V_4 -> V_94 , V_4 -> V_103 ) ;
for ( V_17 = 0 ; V_17 < 6 ; V_17 ++ )
F_7 ( L_23 , V_4 -> V_49 [ V_17 ] = V_48 [ V_17 ] ) ;
F_7 ( L_24 ) ;
V_4 -> V_133 = & V_134 ;
V_4 -> V_135 = 5 * V_101 ;
#if 0
i596_port_do(dev, PORT_SELFTEST, "selftest");
i596_port_do(dev, PORT_DUMP, "dump");
#endif
return 0 ;
V_131:
F_47 ( V_29 , V_128 ) ;
return V_124 ;
}
static inline void
F_48 ( struct V_3 * V_4 ,
struct V_7 * V_8 ,
unsigned short V_13 ,
unsigned short * V_136 ) {
struct V_82 * V_24 ;
int V_137 = 0 ;
int V_138 = 0 ;
int V_139 ;
unsigned long V_95 ;
F_34 ( & V_8 -> V_97 , V_95 ) ;
V_24 = V_8 -> V_41 ;
while ( V_8 -> V_41 && ( V_8 -> V_41 -> V_13 & V_140 ) ) {
V_24 = V_8 -> V_41 ;
V_8 -> V_41 = F_3 ( V_8 -> V_41 -> V_27 ) ;
V_8 -> V_40 -- ;
V_138 ++ ;
V_139 = V_24 -> V_11 & 0x7 ;
#if 0
printk("finished CU %s command (%d)\n",
CUcmdnames[cmd_val], cmd_val);
#endif
switch ( V_139 ) {
case V_83 :
{
struct V_84 * V_84 ;
struct V_85 * V_86 ;
V_84 = (struct V_84 * ) V_24 ;
V_86 = F_3 ( V_84 -> V_87 ) ;
V_137 ++ ;
if ( V_24 -> V_13 & V_141 ) {
if ( V_117 )
F_42 ( F_3 ( V_86 -> V_116 ) ) ;
} else {
V_4 -> V_60 . V_88 ++ ;
if ( V_117 )
F_7 ( L_30 ,
V_24 -> V_13 ) ;
if ( V_24 -> V_13 & 0x0020 )
V_4 -> V_60 . V_67 ++ ;
if ( ! ( V_24 -> V_13 & 0x0040 ) )
V_4 -> V_60 . V_142 ++ ;
if ( V_24 -> V_13 & 0x0400 )
V_4 -> V_60 . V_143 ++ ;
if ( V_24 -> V_13 & 0x0800 )
V_4 -> V_60 . V_67 ++ ;
if ( V_24 -> V_13 & 0x1000 )
V_4 -> V_60 . V_89 ++ ;
}
F_49 ( V_86 -> V_59 ) ;
V_24 -> V_27 = V_2 ;
F_13 ( ( unsigned char * ) V_84 ) ;
F_30 ( V_4 ) ;
break;
}
case V_90 :
V_24 -> V_27 = V_2 ;
F_13 ( ( unsigned char * ) V_24 ) ;
break;
case V_53 :
{
unsigned long V_13 = * ( ( unsigned long * ) ( V_24 + 1 ) ) ;
if ( V_13 & 0x8000 ) {
if ( V_117 )
F_7 ( L_31 , V_4 -> V_12 ) ;
} else {
if ( V_13 & 0x4000 )
F_7 ( L_32 ,
V_4 -> V_12 ) ;
if ( V_13 & 0x2000 )
F_7 ( L_33 ,
V_4 -> V_12 ) ;
if ( V_13 & 0x1000 )
F_7 ( L_34 ,
V_4 -> V_12 ) ;
F_7 ( L_35 ,
V_4 -> V_12 , V_13 & 0x07ff ) ;
}
}
default:
V_24 -> V_27 = V_2 ;
V_8 -> V_38 = V_39 ;
}
F_9 () ;
}
V_24 = V_8 -> V_41 ;
while ( V_24 && ( V_24 != V_8 -> V_98 ) ) {
V_24 -> V_11 &= 0x1fff ;
V_24 = F_3 ( V_24 -> V_27 ) ;
F_9 () ;
}
if ( V_8 -> V_41 )
* V_136 |= V_99 ;
V_8 -> V_10 . V_37 = F_1 ( V_8 -> V_41 ) ;
F_35 ( & V_8 -> V_97 , V_95 ) ;
}
static T_4
V_104 ( int V_103 , void * V_144 )
{
struct V_3 * V_4 = V_144 ;
struct V_7 * V_8 = F_6 ( V_4 ) ;
unsigned short V_13 , V_145 = 0 ;
int V_146 = 0 ;
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_36 , 40 ) )
;
V_13 = V_8 -> V_10 . V_13 ;
#if 0
if (i596_debug) {
printk("%s: i596 interrupt, ", dev->name);
i596_out_status(status);
}
#endif
if ( V_13 == 0xffff ) {
F_7 ( L_37 , V_4 -> V_12 ) ;
goto V_147;
}
V_145 = ( V_13 & V_148 ) ;
if ( V_13 & ( V_149 | V_150 ) )
F_48 ( V_4 , V_8 , V_13 , & V_145 ) ;
if ( V_13 & ( V_151 | V_152 ) ) {
if ( ( V_13 & V_152 ) && F_50 ( V_4 ) )
V_145 |= V_54 ;
if ( V_13 & V_151 ) {
V_146 = F_27 ( V_4 ) ;
if ( ! V_146 )
F_7 ( L_38 ) ;
}
}
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_39 , 100 ) )
;
V_8 -> V_10 . V_11 = V_145 ;
F_18 () ;
F_16 () ;
V_147:
return V_153 ;
}
static int F_51 ( struct V_3 * V_4 ) {
struct V_7 * V_8 = F_6 ( V_4 ) ;
F_32 ( V_4 ) ;
if ( V_117 )
F_7 ( L_40 ,
V_4 -> V_12 , V_8 -> V_10 . V_13 ) ;
V_8 -> V_10 . V_11 = ( V_92 | V_93 ) ;
F_16 () ;
F_28 ( V_4 ) ;
if ( V_8 -> V_10 . V_11 && F_5 ( V_4 , L_41 , 200 ) )
;
F_38 ( V_4 -> V_103 , V_4 ) ;
F_12 ( V_4 ) ;
return 0 ;
}
static void F_52 ( struct V_3 * V_4 ) {
struct V_7 * V_8 = F_6 ( V_4 ) ;
struct V_82 * V_24 ;
if ( V_117 > 1 )
F_7 ( L_42 ,
V_4 -> V_12 , F_53 ( V_4 ) ) ;
if ( ! F_54 ( V_4 ) ) {
struct V_154 * V_155 ;
char * V_156 ;
V_24 = F_11 ( sizeof( struct V_82 ) + 2 +
F_53 ( V_4 ) * 6 , V_112 ) ;
if ( V_24 == NULL ) {
F_7 ( V_79 L_43 , V_4 -> V_12 ) ;
return;
}
V_24 -> V_11 = V_90 ;
* ( ( unsigned short * ) ( V_24 + 1 ) ) = F_53 ( V_4 ) * 6 ;
V_156 = ( ( char * ) ( V_24 + 1 ) ) + 2 ;
F_55 (ha, dev) {
memcpy ( V_156 , V_155 -> V_157 , 6 ) ;
V_156 += 6 ;
}
if ( V_117 & V_118 )
F_42 ( ( ( char * ) ( V_24 + 1 ) ) + 2 ) ;
F_21 ( V_4 , V_24 ) ;
} else {
if ( V_8 -> V_46 . V_27 != V_2 ) {
return;
}
if ( F_54 ( V_4 ) &&
! ( V_4 -> V_95 & ( V_158 | V_159 ) ) ) {
V_8 -> V_44 [ 8 ] &= ~ 0x01 ;
} else {
V_8 -> V_44 [ 8 ] |= 0x01 ;
}
F_21 ( V_4 , & V_8 -> V_46 ) ;
}
}
static int T_3 F_56 ( void ) {
int V_160 ;
struct V_3 * V_4 = F_57 ( sizeof( struct V_7 ) ) ;
if ( ! V_4 )
return - V_125 ;
V_4 -> V_103 = V_103 ;
V_4 -> V_94 = V_161 ;
V_160 = F_44 ( V_4 ) ;
if ( V_160 ) {
F_58 ( V_4 ) ;
return V_160 ;
}
V_160 = F_59 ( V_4 ) ;
if ( V_160 ) {
F_47 ( V_4 -> V_94 , V_128 ) ;
F_58 ( V_4 ) ;
return V_160 ;
}
V_162 = V_4 ;
V_163 = 0 ;
V_164 = 0 ;
return 0 ;
}
static void T_5 F_60 ( void ) {
F_61 ( V_162 ) ;
F_47 ( V_162 -> V_94 , V_128 ) ;
F_58 ( V_162 ) ;
}
