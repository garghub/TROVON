static inline T_1
F_1 ( const T_2 V_1 , T_1 V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_1 . V_4 ) ;
V_3 = F_3 ( V_1 . V_5 ) ;
return V_3 ;
}
static inline unsigned long
F_4 ( const T_2 V_1 )
{
unsigned long V_6 ;
F_2 ( V_7 , V_1 . V_4 ) ;
V_6 = F_3 ( V_1 . V_5 ) << 16 ;
V_6 |= F_3 ( V_1 . V_5 ) << 8 ;
V_6 |= F_3 ( V_1 . V_5 ) ;
return V_6 ;
}
static inline T_1
F_5 ( const T_2 V_1 )
{
return F_3 ( V_1 . V_4 ) ;
}
static inline void
F_6 ( const T_2 V_1 , T_1 V_2 , T_1 V_6 )
{
F_2 ( V_2 , V_1 . V_4 ) ;
F_2 ( V_6 , V_1 . V_5 ) ;
}
static inline void
F_7 ( const T_2 V_1 , unsigned long V_6 )
{
F_2 ( V_7 , V_1 . V_4 ) ;
F_2 ( ( V_6 >> 16 ) & 0xff , V_1 . V_5 ) ;
F_2 ( ( V_6 >> 8 ) & 0xff , V_1 . V_5 ) ;
F_2 ( V_6 & 0xff , V_1 . V_5 ) ;
}
static inline void
F_8 ( const T_2 V_1 , T_3 V_8 , T_1 V_9 [] )
{
int V_10 ;
F_2 ( V_11 , V_1 . V_4 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
F_2 ( V_9 [ V_10 ] , V_1 . V_5 ) ;
}
static inline T_1
F_1 ( const T_2 V_1 , T_1 V_2 )
{
* V_1 . V_4 = V_2 ;
F_9 () ;
return ( * V_1 . V_5 ) ;
}
static unsigned long
F_4 ( const T_2 V_1 )
{
unsigned long V_6 ;
* V_1 . V_4 = V_7 ;
F_9 () ;
V_6 = * V_1 . V_5 << 16 ;
V_6 |= * V_1 . V_5 << 8 ;
V_6 |= * V_1 . V_5 ;
F_9 () ;
return V_6 ;
}
static inline T_1
F_5 ( const T_2 V_1 )
{
return * V_1 . V_4 ;
}
static inline void
F_6 ( const T_2 V_1 , T_1 V_2 , T_1 V_6 )
{
* V_1 . V_4 = V_2 ;
F_9 () ;
* V_1 . V_5 = V_6 ;
F_9 () ;
}
static void
F_7 ( const T_2 V_1 , unsigned long V_6 )
{
* V_1 . V_4 = V_7 ;
F_9 () ;
* V_1 . V_5 = V_6 >> 16 ;
* V_1 . V_5 = V_6 >> 8 ;
* V_1 . V_5 = V_6 ;
F_9 () ;
}
static inline void
F_10 ( const T_2 V_1 , T_1 V_12 )
{
* V_1 . V_4 = V_13 ;
F_9 () ;
* V_1 . V_5 = V_12 ;
F_9 () ;
}
static inline void
F_8 ( const T_2 V_1 , T_3 V_8 , T_1 V_9 [] )
{
int V_10 ;
* V_1 . V_4 = V_11 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
* V_1 . V_5 = V_9 [ V_10 ] ;
}
static inline T_1
F_11 ( const T_2 V_1 )
{
T_1 V_14 ;
T_1 V_15 = 0 ;
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
F_10 ( V_1 , V_20 | 0x80 ) ;
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
V_15 = F_1 ( V_1 , V_22 ) ;
} while ( ! ( V_14 & V_23 ) );
return V_15 ;
}
static int
F_12 ( unsigned int V_24 , const struct V_25 * V_26 )
{
int V_15 ;
for ( V_15 = 1 ; V_26 [ V_15 ] . V_27 ; V_15 ++ ) {
if ( ( V_24 <= V_26 [ V_15 - 0 ] . V_27 ) &&
( V_24 > V_26 [ V_15 - 1 ] . V_27 ) ) {
return V_15 ;
}
}
return 7 ;
}
static T_1
F_13 ( unsigned int V_24 , unsigned int V_28 , unsigned int V_29 ,
const struct V_25 * V_26 )
{
T_1 V_30 ;
if ( V_28 && V_29 ) {
V_29 = V_31 ;
V_24 *= 2 ;
} else {
V_29 = 0 ;
}
V_24 *= 4 ;
V_30 = V_26 [ F_12 ( V_24 , V_26 ) ] . V_32 ;
V_30 |= ( V_28 < V_33 ) ? V_28 : V_33 ;
V_30 |= V_29 ;
return V_30 ;
}
static inline void
F_14 ( unsigned int V_24 , unsigned int V_28 , unsigned int V_29 ,
T_1 V_34 [ 2 ] )
{
V_24 /= 4 ;
if ( V_28 && V_29 )
V_24 /= 2 ;
V_34 [ 0 ] = V_24 ;
V_34 [ 1 ] = V_28 ;
}
static int
F_15 ( struct V_35 * V_12 ,
void (* F_16)( struct V_35 * ) )
{
struct V_36 * V_37 ;
struct V_35 * V_38 ;
V_37 = (struct V_36 * ) V_12 -> V_39 -> V_40 -> V_37 ;
F_17 (DB_QUEUE_COMMAND,
printk(L_1, cmd->device->id, cmd->cmnd[0]))
V_12 -> V_41 = NULL ;
V_12 -> V_42 = F_16 ;
V_12 -> V_30 = 0 ;
if ( F_18 ( V_12 ) ) {
V_12 -> V_43 . V_44 = F_19 ( V_12 ) ;
V_12 -> V_43 . V_45 = F_20 ( V_12 ) - 1 ;
V_12 -> V_43 . V_46 = F_21 ( V_12 -> V_43 . V_44 ) ;
V_12 -> V_43 . V_47 = V_12 -> V_43 . V_44 -> V_48 ;
} else {
V_12 -> V_43 . V_44 = NULL ;
V_12 -> V_43 . V_45 = 0 ;
V_12 -> V_43 . V_46 = NULL ;
V_12 -> V_43 . V_47 = 0 ;
}
V_12 -> V_43 . V_49 = V_50 ;
F_22 ( & V_37 -> V_51 ) ;
if ( ! ( V_37 -> V_52 ) || ( V_12 -> V_9 [ 0 ] == V_53 ) ) {
V_12 -> V_41 = ( T_1 * ) V_37 -> V_52 ;
V_37 -> V_52 = V_12 ;
} else {
for ( V_38 = (struct V_35 * ) V_37 -> V_52 ;
V_38 -> V_41 ;
V_38 = (struct V_35 * ) V_38 -> V_41 ) ;
V_38 -> V_41 = ( T_1 * ) V_12 ;
}
F_23 ( V_12 -> V_39 -> V_40 ) ;
F_17 (DB_QUEUE_COMMAND, printk(L_2))
F_24 ( & V_37 -> V_51 ) ;
return 0 ;
}
static void
F_23 ( struct V_54 * V_55 )
{
struct V_36 * V_37 =
(struct V_36 * ) V_55 -> V_37 ;
const T_2 V_1 = V_37 -> V_1 ;
struct V_35 * V_12 , * V_56 ;
F_17 (DB_EXECUTE, printk(L_3))
if ( V_37 -> V_57 || V_37 -> V_58 ) {
F_17 (DB_EXECUTE, printk(L_4))
return;
}
V_12 = (struct V_35 * ) V_37 -> V_52 ;
V_56 = NULL ;
while ( V_12 ) {
if ( ! ( V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] & ( 1 << V_12 -> V_39 -> V_61 ) ) )
break;
V_56 = V_12 ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
if ( ! V_12 ) {
F_17 (DB_EXECUTE, printk(L_5))
return;
}
if ( V_56 )
V_56 -> V_41 = V_12 -> V_41 ;
else
V_37 -> V_52 = (struct V_35 * ) V_12 -> V_41 ;
#ifdef F_25
V_37 -> V_62 [ V_12 -> V_39 -> V_60 ] ++ ;
#endif
if ( V_12 -> V_63 == V_64 )
F_6 ( V_1 , V_65 , V_12 -> V_39 -> V_60 ) ;
else
F_6 ( V_1 , V_65 , V_12 -> V_39 -> V_60 | V_66 ) ;
V_12 -> V_43 . V_67 = 0 ;
if ( V_37 -> V_68 == V_69 )
goto V_70;
if ( V_37 -> V_68 == V_71 )
goto V_72;
if ( V_12 -> V_39 -> type == 1 )
goto V_72;
if ( V_37 -> V_73 )
goto V_72;
if ( ! ( V_37 -> V_52 ) )
goto V_70;
for ( V_56 = (struct V_35 * ) V_37 -> V_52 ; V_56 ;
V_56 = (struct V_35 * ) V_56 -> V_41 ) {
if ( ( V_56 -> V_39 -> V_60 != V_12 -> V_39 -> V_60 ) ||
( V_56 -> V_39 -> V_61 != V_12 -> V_39 -> V_61 ) ) {
for ( V_56 = (struct V_35 * ) V_37 -> V_52 ; V_56 ;
V_56 = (struct V_35 * ) V_56 -> V_41 )
V_56 -> V_43 . V_67 = 1 ;
goto V_72;
}
}
goto V_70;
V_72:
V_12 -> V_43 . V_67 = 1 ;
#ifdef F_25
V_37 -> V_74 [ V_12 -> V_39 -> V_60 ] ++ ;
#endif
V_70:
F_6 ( V_1 , V_75 , ( ( V_12 -> V_43 . V_67 ) ? V_76 : 0 ) ) ;
F_6 ( V_1 , V_77 , V_12 -> V_39 -> V_61 ) ;
F_6 ( V_1 , V_78 ,
V_37 -> V_79 [ V_12 -> V_39 -> V_60 ] ) ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] |= ( 1 << V_12 -> V_39 -> V_61 ) ;
if ( ( V_37 -> V_80 == V_81 ) ||
( V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] == V_83 ) ) {
V_37 -> V_57 = V_12 ;
if ( V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] == V_83 )
V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] = V_84 ;
V_37 -> V_85 = V_86 ;
F_7 ( V_1 , 0 ) ;
F_10 ( V_1 , V_87 ) ;
} else {
V_37 -> V_58 = V_12 ;
F_6 ( V_1 , V_88 , 0 ) ;
F_8 ( V_1 , V_12 -> V_89 , V_12 -> V_9 ) ;
F_6 ( V_1 , V_90 , V_12 -> V_89 ) ;
if ( ( V_12 -> V_43 . V_67 == 0 ) && ( V_37 -> V_91 == 0 ) ) {
if ( V_37 -> V_92 ( V_12 ,
( V_12 -> V_63 == V_64 ) ?
V_93 : V_94 ) )
F_7 ( V_1 , 0 ) ;
else {
F_7 ( V_1 ,
V_12 -> V_43 . V_47 ) ;
F_6 ( V_1 , V_16 ,
V_17 | V_18 | V_37 -> V_95 ) ;
V_37 -> V_96 = V_97 ;
}
} else
F_7 ( V_1 , 0 ) ;
V_37 -> V_85 = V_98 ;
F_10 ( V_1 , V_99 ) ;
}
F_17 (DB_EXECUTE,
printk(L_6, (cmd->SCp.phase) ? L_7 : L_8))
}
static void
F_26 ( const T_2 V_1 , T_1 * V_100 , int V_101 ,
int V_102 , struct V_36 * V_37 )
{
T_1 V_14 ;
F_17 (DB_TRANSFER,
printk(L_9, buf, cnt, data_in_dir ? L_10 : L_11))
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
F_7 ( V_1 , V_101 ) ;
F_10 ( V_1 , V_20 ) ;
if ( V_102 ) {
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
* V_100 ++ = F_1 ( V_1 , V_22 ) ;
} while ( ! ( V_14 & V_23 ) );
} else {
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
F_6 ( V_1 , V_22 , * V_100 ++ ) ;
} while ( ! ( V_14 & V_23 ) );
}
}
static void
F_27 ( const T_2 V_1 , struct V_35 * V_12 ,
int V_102 )
{
struct V_36 * V_37 ;
unsigned long V_48 ;
V_37 = (struct V_36 * ) V_12 -> V_39 -> V_40 -> V_37 ;
if ( ! V_12 -> V_43 . V_47 && V_12 -> V_43 . V_45 ) {
++ V_12 -> V_43 . V_44 ;
-- V_12 -> V_43 . V_45 ;
V_12 -> V_43 . V_47 = V_12 -> V_43 . V_44 -> V_48 ;
V_12 -> V_43 . V_46 = F_21 ( V_12 -> V_43 . V_44 ) ;
}
if ( ! V_12 -> V_43 . V_47 )
return;
F_6 ( V_1 , V_78 ,
V_37 -> V_79 [ V_12 -> V_39 -> V_60 ] ) ;
if ( V_37 -> V_91 || V_37 -> V_92 ( V_12 , V_102 ) ) {
#ifdef F_25
V_37 -> V_103 ++ ;
#endif
F_26 ( V_1 , ( T_1 * ) V_12 -> V_43 . V_46 ,
V_12 -> V_43 . V_47 , V_102 , V_37 ) ;
V_48 = V_12 -> V_43 . V_47 ;
V_12 -> V_43 . V_47 = F_4 ( V_1 ) ;
V_12 -> V_43 . V_46 += ( V_48 - V_12 -> V_43 . V_47 ) ;
}
else {
#ifdef F_25
V_37 -> V_104 ++ ;
#endif
F_6 ( V_1 , V_16 , V_17 | V_18 | V_37 -> V_95 ) ;
F_7 ( V_1 , V_12 -> V_43 . V_47 ) ;
if ( ( V_37 -> V_80 >= V_105 ) ||
( V_37 -> V_80 == V_106 && V_12 -> V_43 . V_67 == 0 ) ) {
F_6 ( V_1 , V_88 , 0x45 ) ;
F_10 ( V_1 , V_99 ) ;
V_37 -> V_85 = V_98 ;
} else
F_10 ( V_1 , V_20 ) ;
V_37 -> V_96 = V_97 ;
}
}
void
F_28 ( struct V_54 * V_55 )
{
struct V_36 * V_37 =
(struct V_36 * ) V_55 -> V_37 ;
const T_2 V_1 = V_37 -> V_1 ;
struct V_35 * V_107 , * V_12 ;
T_1 V_14 , V_108 , V_109 , V_60 , V_61 , * V_110 , V_34 ;
unsigned long V_48 , V_111 ;
V_14 = F_5 ( V_1 ) ;
if ( ! ( V_14 & V_23 ) || ( V_14 & V_112 ) )
return;
F_29 ( & V_37 -> V_51 , V_111 ) ;
#ifdef F_25
V_37 -> V_113 ++ ;
#endif
V_12 = (struct V_35 * ) V_37 -> V_58 ;
V_108 = F_1 ( V_1 , V_114 ) ;
V_109 = F_1 ( V_1 , V_88 ) ;
F_17 (DB_INTR, printk(L_12, asr, sr))
if ( V_37 -> V_96 == V_97 ) {
F_17 (DB_TRANSFER,
printk(L_13, cmd->SCp.ptr, cmd->SCp.this_residual))
V_37 -> V_115 ( V_12 -> V_39 -> V_40 , V_12 , 1 ) ;
V_37 -> V_96 = V_116 ;
V_48 = V_12 -> V_43 . V_47 ;
V_12 -> V_43 . V_47 = F_4 ( V_1 ) ;
V_12 -> V_43 . V_46 += ( V_48 - V_12 -> V_43 . V_47 ) ;
F_17 (DB_TRANSFER,
printk(L_14, cmd->SCp.ptr, cmd->SCp.this_residual))
}
switch ( V_108 ) {
case V_117 :
F_17 (DB_INTR, printk(L_15))
if ( V_37 -> V_85 == V_98 )
V_37 -> V_58 = NULL ;
else {
V_12 = (struct V_35 * ) V_37 -> V_57 ;
V_37 -> V_57 = NULL ;
}
V_12 -> V_30 = V_118 << 16 ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_37 -> V_85 = V_119 ;
V_12 -> V_42 ( V_12 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
F_23 ( V_55 ) ;
break;
case V_120 :
F_17 (DB_INTR, printk(L_16))
V_37 -> V_58 = V_12 =
(struct V_35 * ) V_37 -> V_57 ;
V_37 -> V_57 = NULL ;
V_37 -> V_121 [ 0 ] = ( 0x80 | 0x00 | V_12 -> V_39 -> V_61 ) ;
if ( V_12 -> V_43 . V_67 )
V_37 -> V_121 [ 0 ] |= 0x40 ;
if ( V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] == V_84 ) {
V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] = V_122 ;
V_37 -> V_121 [ 1 ] = V_123 ;
V_37 -> V_121 [ 2 ] = 3 ;
V_37 -> V_121 [ 3 ] = V_124 ;
if ( V_37 -> V_125 & ( 1 << V_12 -> V_39 -> V_60 ) ) {
F_14 ( V_37 -> V_126 , 0 ,
0 , V_37 -> V_121 + 4 ) ;
} else {
F_14 ( F_31 ( V_37 ) ,
V_33 ,
V_37 -> V_29 ,
V_37 -> V_121 + 4 ) ;
}
V_37 -> V_127 = 6 ;
#ifdef F_32
V_110 = V_37 -> V_121 + 1 ;
F_33 ( L_17 ,
V_110 [ 0 ] , V_110 [ 2 ] , V_110 [ 3 ] , V_110 [ 4 ] ) ;
#endif
} else
V_37 -> V_127 = 1 ;
V_37 -> V_85 = V_128 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_129 | V_130 :
case V_131 | V_130 :
case V_132 | V_130 :
F_17 (DB_INTR,
printk(L_18, cmd->SCp.this_residual,
cmd->SCp.buffers_residual))
F_27 ( V_1 , V_12 , V_94 ) ;
if ( V_37 -> V_85 != V_98 )
V_37 -> V_85 = V_128 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_129 | V_133 :
case V_131 | V_133 :
case V_132 | V_133 :
F_17 (DB_INTR,
printk(L_19, cmd->SCp.this_residual,
cmd->SCp.buffers_residual))
F_27 ( V_1 , V_12 , V_93 ) ;
if ( V_37 -> V_85 != V_98 )
V_37 -> V_85 = V_128 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_129 | V_134 :
case V_131 | V_134 :
case V_132 | V_134 :
F_17 (DB_INTR, printk(L_20, cmd->cmnd[0]))
F_26 ( V_1 , V_12 -> V_9 , V_12 -> V_89 , V_93 ,
V_37 ) ;
V_37 -> V_85 = V_128 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_129 | V_135 :
case V_131 | V_135 :
case V_132 | V_135 :
F_17 (DB_INTR, printk(L_21))
V_12 -> V_43 . V_49 = F_11 ( V_1 ) ;
F_17 (DB_INTR, printk(L_22, cmd->SCp.Status))
if ( V_37 -> V_80 >= V_106 ) {
V_108 = F_1 ( V_1 , V_114 ) ;
F_34 ( 7 ) ;
V_37 -> V_85 = V_98 ;
F_6 ( V_1 , V_88 , 0x50 ) ;
F_10 ( V_1 , V_99 ) ;
} else {
V_37 -> V_85 = V_128 ;
}
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_129 | V_136 :
case V_131 | V_136 :
case V_132 | V_136 :
F_17 (DB_INTR, printk(L_23))
V_34 = F_11 ( V_1 ) ;
V_108 = F_1 ( V_1 , V_114 ) ;
F_34 ( 7 ) ;
V_37 -> V_137 [ V_37 -> V_138 ] = V_34 ;
if ( V_37 -> V_137 [ 0 ] == V_123 )
V_34 = V_123 ;
else
V_37 -> V_138 = 0 ;
V_12 -> V_43 . V_139 = V_34 ;
switch ( V_34 ) {
case V_140 :
F_17 (DB_INTR, printk(L_24))
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_142 ;
break;
case V_143 :
F_17 (DB_INTR, printk(L_25))
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_128 ;
break;
case V_144 :
F_17 (DB_INTR, printk(L_26))
if ( V_37 -> V_80 >= V_106 ) {
F_6 ( V_1 , V_88 , 0x45 ) ;
F_10 ( V_1 , V_99 ) ;
V_37 -> V_85 = V_98 ;
} else {
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_128 ;
}
break;
case V_145 :
F_17 (DB_INTR, printk(L_27))
V_12 -> V_39 -> V_68 = 1 ;
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_146 ;
break;
case V_147 :
F_17 (DB_INTR, printk(L_28))
#ifdef F_32
F_33 ( L_29 ) ;
#endif
if ( V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] == V_122 ) {
V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] = V_148 ;
V_37 -> V_79 [ V_12 -> V_39 -> V_60 ] =
F_13 ( V_37 -> V_126
/ 4 , 0 , 0 , V_37 -> V_26 ) ;
}
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_128 ;
break;
case V_123 :
F_17 (DB_INTR, printk(L_30))
V_110 = V_37 -> V_137 ;
#ifdef F_32
F_33 ( L_22 , V_110 [ V_37 -> V_138 ] ) ;
#endif
if ( ( V_37 -> V_138 >= 2 ) &&
( V_37 -> V_138 == ( V_110 [ 1 ] + 1 ) ) ) {
switch ( V_110 [ 2 ] ) {
case V_124 :
V_60 = F_13 ( V_37 ->
V_126 / 4 , 0 ,
0 , V_37 -> V_26 ) ;
if ( V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] !=
V_122 ) {
F_10 ( V_1 , V_149 ) ;
V_37 -> V_121 [ 0 ] =
V_123 ;
V_37 -> V_121 [ 1 ] = 3 ;
V_37 -> V_121 [ 2 ] =
V_124 ;
F_14 ( V_37 ->
V_126 , 0 ,
0 , V_37 -> V_121 + 3 ) ;
V_37 -> V_127 = 5 ;
} else {
if ( V_110 [ 4 ] )
V_60 = F_13 ( V_110 [ 3 ] , V_110 [ 4 ] ,
V_37 -> V_29 ,
V_37 -> V_26 ) ;
else if ( V_110 [ 3 ] )
V_60 = F_13 ( V_110 [ 3 ] , V_110 [ 4 ] ,
0 , V_37 -> V_26 ) ;
}
V_37 -> V_79 [ V_12 -> V_39 -> V_60 ] = V_60 ;
#ifdef F_32
F_33 ( L_31 ,
V_37 -> V_79 [ V_12 -> V_39 -> V_60 ] ) ;
#endif
V_37 -> V_82 [ V_12 -> V_39 -> V_60 ] =
V_148 ;
F_10 ( V_1 ,
V_141 ) ;
V_37 -> V_85 = V_128 ;
break;
case V_150 :
F_10 ( V_1 , V_149 ) ;
F_33 ( L_32 ) ;
V_37 -> V_121 [ 0 ] =
V_123 ;
V_37 -> V_121 [ 1 ] = 2 ;
V_37 -> V_121 [ 2 ] =
V_150 ;
V_37 -> V_121 [ 3 ] = 0 ;
V_37 -> V_127 = 4 ;
F_10 ( V_1 ,
V_141 ) ;
V_37 -> V_85 = V_128 ;
break;
default:
F_10 ( V_1 , V_149 ) ;
F_33
( L_33 ,
V_110 [ 2 ] ) ;
V_37 -> V_121 [ 0 ] =
V_147 ;
V_37 -> V_127 = 1 ;
F_10 ( V_1 ,
V_141 ) ;
V_37 -> V_85 = V_128 ;
break;
}
V_37 -> V_138 = 0 ;
}
else {
V_37 -> V_138 ++ ;
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_128 ;
}
break;
default:
F_33 ( L_34 , V_34 ) ;
F_10 ( V_1 , V_149 ) ;
V_37 -> V_121 [ 0 ] = V_147 ;
V_37 -> V_127 = 1 ;
F_10 ( V_1 , V_141 ) ;
V_37 -> V_85 = V_128 ;
}
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_151 :
F_6 ( V_1 , V_75 , V_76 ) ;
if ( V_109 == 0x60 ) {
F_17 (DB_INTR, printk(L_35))
V_12 -> V_43 . V_139 = V_140 ;
V_61 = F_1 ( V_1 , V_77 ) ;
F_17 (DB_INTR, printk(L_36, cmd->SCp.Status, lun))
V_37 -> V_58 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_37 -> V_85 = V_119 ;
if ( V_12 -> V_43 . V_49 == V_50 )
V_12 -> V_43 . V_49 = V_61 ;
if ( V_12 -> V_9 [ 0 ] == V_53
&& V_12 -> V_43 . V_49 != V_152 )
V_12 -> V_30 =
( V_12 ->
V_30 & 0x00ffff ) | ( V_153 << 16 ) ;
else
V_12 -> V_30 =
V_12 -> V_43 . V_49 | ( V_12 -> V_43 . V_139 << 8 ) ;
V_12 -> V_42 ( V_12 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
F_23 ( V_55 ) ;
} else {
F_33
( L_37 ,
V_14 , V_108 , V_109 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
}
break;
case V_154 :
F_17 (DB_INTR, printk(L_25))
V_37 -> V_85 = V_98 ;
F_6 ( V_1 , V_88 , 0x41 ) ;
F_10 ( V_1 , V_99 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_129 | V_155 :
case V_131 | V_155 :
case V_132 | V_155 :
F_17 (DB_INTR, printk(L_38))
if ( V_37 -> V_127 == 0 ) {
V_37 -> V_127 = 1 ;
V_37 -> V_121 [ 0 ] = V_156 ;
}
F_26 ( V_1 , V_37 -> V_121 ,
V_37 -> V_127 , V_93 , V_37 ) ;
F_17 (DB_INTR, printk(L_22, hostdata->outgoing_msg[0]))
V_37 -> V_127 = 0 ;
V_37 -> V_85 = V_128 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
case V_157 :
F_6 ( V_1 , V_75 , V_76 ) ;
if ( V_12 == NULL ) {
F_33 ( L_39 ) ;
V_37 -> V_85 = V_119 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
return;
}
F_17 (DB_INTR, printk(L_40))
V_37 -> V_58 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_37 -> V_85 = V_119 ;
if ( V_12 -> V_9 [ 0 ] == V_53 && V_12 -> V_43 . V_49 != V_152 )
V_12 -> V_30 =
( V_12 -> V_30 & 0x00ffff ) | ( V_153 << 16 ) ;
else
V_12 -> V_30 = V_12 -> V_43 . V_49 | ( V_12 -> V_43 . V_139 << 8 ) ;
V_12 -> V_42 ( V_12 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
F_23 ( V_55 ) ;
break;
case V_158 :
F_6 ( V_1 , V_75 , V_76 ) ;
F_17 (DB_INTR, printk(L_41))
if ( V_12 == NULL ) {
F_33 ( L_39 ) ;
V_37 -> V_85 = V_119 ;
}
switch ( V_37 -> V_85 ) {
case V_142 :
V_37 -> V_58 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_37 -> V_85 = V_119 ;
F_17 (DB_INTR, printk(L_42, cmd->SCp.Status))
if ( V_12 -> V_9 [ 0 ] == V_53
&& V_12 -> V_43 . V_49 != V_152 )
V_12 -> V_30 =
( V_12 ->
V_30 & 0x00ffff ) | ( V_153 << 16 ) ;
else
V_12 -> V_30 =
V_12 -> V_43 . V_49 | ( V_12 -> V_43 . V_139 << 8 ) ;
V_12 -> V_42 ( V_12 ) ;
break;
case V_146 :
case V_98 :
V_12 -> V_41 = ( T_1 * ) V_37 -> V_73 ;
V_37 -> V_73 = V_12 ;
V_37 -> V_58 = NULL ;
V_37 -> V_85 = V_119 ;
#ifdef F_25
V_37 -> V_159 [ V_12 -> V_39 -> V_60 ] ++ ;
#endif
break;
default:
F_33 ( L_43 ) ;
V_37 -> V_85 = V_119 ;
}
F_30 ( & V_37 -> V_51 , V_111 ) ;
F_23 ( V_55 ) ;
break;
case V_160 :
case V_161 :
F_17 (DB_INTR, printk(L_44, sr == CSR_RESEL_AM ? L_45 : L_8))
if ( V_37 -> V_80 <= V_81 ) {
if ( V_37 -> V_57 ) {
V_12 = (struct V_35 * ) V_37 -> V_57 ;
V_37 -> V_57 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_12 -> V_41 =
( T_1 * ) V_37 -> V_52 ;
V_37 -> V_52 = V_12 ;
}
}
else {
if ( V_12 ) {
if ( V_109 == 0x00 ) {
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &=
~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_12 -> V_41 =
( T_1 * ) V_37 -> V_52 ;
V_37 -> V_52 = V_12 ;
} else {
F_33
( L_46 ,
V_14 , V_108 , V_109 ) ;
while ( 1 )
F_33 ( L_47 ) ;
}
}
}
V_60 = F_1 ( V_1 , V_75 ) ;
V_60 &= V_162 ;
if ( V_108 == V_160 ) {
V_61 = F_1 ( V_1 , V_22 ) ;
if ( V_37 -> V_80 < V_163 )
F_10 ( V_1 , V_141 ) ;
V_61 &= 7 ;
} else {
for ( V_61 = 255 ; V_61 ; V_61 -- ) {
if ( ( V_14 = F_5 ( V_1 ) ) & V_23 )
break;
F_34 ( 10 ) ;
}
if ( ! ( V_14 & V_23 ) ) {
F_33
( L_48 ) ;
V_61 = 0 ;
} else {
V_108 = F_1 ( V_1 , V_114 ) ;
F_34 ( 7 ) ;
if ( V_108 == ( V_164 | V_136 ) ||
V_108 == ( V_131 | V_136 ) ||
V_108 == ( V_132 | V_136 ) ) {
V_61 = F_11 ( V_1 ) ;
V_14 = F_5 ( V_1 ) ;
if ( ! ( V_14 & V_23 ) ) {
F_34 ( 10 ) ;
V_14 = F_5 ( V_1 ) ;
if ( ! ( V_14 & V_23 ) )
F_33
( L_49 ,
V_14 ) ;
}
V_108 = F_1 ( V_1 , V_114 ) ;
F_34 ( 7 ) ;
if ( V_108 != V_165 )
F_33
( L_50 ,
V_108 ) ;
V_61 &= 7 ;
F_10 ( V_1 ,
V_141 ) ;
} else {
F_33
( L_51 ,
V_108 ) ;
V_61 = 0 ;
}
}
}
V_12 = (struct V_35 * ) V_37 -> V_73 ;
V_107 = NULL ;
while ( V_12 ) {
if ( V_60 == V_12 -> V_39 -> V_60 && V_61 == V_12 -> V_39 -> V_61 )
break;
V_107 = V_12 ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
if ( ! V_12 ) {
F_33
( L_52 ,
V_60 , V_61 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
return;
}
if ( V_107 )
V_107 -> V_41 = V_12 -> V_41 ;
else
V_37 -> V_73 =
(struct V_35 * ) V_12 -> V_41 ;
V_37 -> V_58 = V_12 ;
if ( V_12 -> V_63 == V_64 )
F_6 ( V_1 , V_65 , V_12 -> V_39 -> V_60 ) ;
else
F_6 ( V_1 , V_65 ,
V_12 -> V_39 -> V_60 | V_66 ) ;
if ( V_37 -> V_80 >= V_163 ) {
F_7 ( V_1 , 0 ) ;
F_6 ( V_1 , V_88 , 0x45 ) ;
F_10 ( V_1 , V_99 ) ;
V_37 -> V_85 = V_98 ;
} else
V_37 -> V_85 = V_128 ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
break;
default:
F_33 ( L_53 , V_14 , V_108 , V_109 ) ;
F_30 ( & V_37 -> V_51 , V_111 ) ;
}
F_17 (DB_INTR, printk(L_54))
}
static void
F_35 ( struct V_54 * V_55 )
{
struct V_36 * V_37 =
(struct V_36 * ) V_55 -> V_37 ;
const T_2 V_1 = V_37 -> V_1 ;
T_1 V_108 ;
#ifdef F_36
{
int V_166 = 0 ;
extern void V_167 ( unsigned long ) ;
while ( ( F_5 ( V_1 ) & V_112 ) && V_166 ++ < 100 )
F_34 ( 10 ) ;
if ( F_5 ( V_1 ) & V_112 )
V_167 ( V_55 -> V_168 ) ;
}
#endif
F_6 ( V_1 , V_90 , V_169 | V_170 |
V_55 -> V_171 | V_37 -> V_172 ) ;
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
F_6 ( V_1 , V_78 ,
F_13 ( V_37 -> V_126 / 4 ,
V_173 , 0 , V_37 -> V_26 ) ) ;
F_6 ( V_1 , V_13 , V_174 ) ;
#ifdef F_37
F_34 ( 25 ) ;
#endif
while ( ! ( F_5 ( V_1 ) & V_23 ) )
;
V_108 = F_1 ( V_1 , V_114 ) ;
V_37 -> V_175 = F_1 ( V_1 , V_11 ) ;
if ( V_108 == 0x00 )
V_37 -> V_176 = V_177 ;
else if ( V_108 == 0x01 ) {
F_6 ( V_1 , V_178 , 0xa5 ) ;
V_108 = F_1 ( V_1 , V_178 ) ;
if ( V_108 == 0xa5 ) {
V_37 -> V_176 = V_179 ;
F_6 ( V_1 , V_178 , 0 ) ;
} else
V_37 -> V_176 = V_180 ;
} else
V_37 -> V_176 = V_181 ;
if ( V_37 -> V_176 != V_179 )
V_37 -> V_29 = 0 ;
F_6 ( V_1 , V_182 , V_183 ) ;
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
}
int
F_38 ( struct V_35 * V_184 )
{
struct V_54 * V_55 ;
struct V_36 * V_37 ;
int V_10 ;
V_55 = V_184 -> V_39 -> V_40 ;
V_37 = (struct V_36 * ) V_55 -> V_37 ;
F_33 ( L_55 , V_55 -> V_185 ) ;
F_39 ( V_55 -> V_186 ) ;
V_37 -> V_115 ( V_55 , NULL , 0 ) ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_37 -> V_59 [ V_10 ] = 0 ;
V_37 -> V_79 [ V_10 ] =
F_13 ( V_187 / 4 , V_173 ,
0 , V_37 -> V_26 ) ;
V_37 -> V_82 [ V_10 ] = V_83 ;
}
V_37 -> V_52 = NULL ;
V_37 -> V_57 = NULL ;
V_37 -> V_58 = NULL ;
V_37 -> V_73 = NULL ;
V_37 -> V_85 = V_119 ;
V_37 -> V_96 = V_116 ;
V_37 -> V_138 = 0 ;
V_37 -> V_127 = 0 ;
F_35 ( V_55 ) ;
V_184 -> V_30 = V_188 << 16 ;
F_40 ( V_55 -> V_186 ) ;
return V_189 ;
}
int
F_41 ( struct V_35 * V_12 )
{
struct V_54 * V_55 ;
struct V_36 * V_37 ;
T_2 V_1 ;
struct V_35 * V_38 , * V_56 ;
F_39 ( V_12 -> V_39 -> V_40 -> V_186 ) ;
V_55 = V_12 -> V_39 -> V_40 ;
V_37 = (struct V_36 * ) V_55 -> V_37 ;
V_1 = V_37 -> V_1 ;
V_38 = (struct V_35 * ) V_37 -> V_52 ;
V_56 = NULL ;
while ( V_38 ) {
if ( V_38 == V_12 ) {
if ( V_56 )
V_56 -> V_41 = V_12 -> V_41 ;
else
V_37 -> V_52 =
(struct V_35 * ) V_12 -> V_41 ;
V_12 -> V_41 = NULL ;
V_12 -> V_30 = V_190 << 16 ;
F_33
( L_56 ,
V_55 -> V_185 ) ;
F_40 ( V_12 -> V_39 -> V_40 -> V_186 ) ;
V_12 -> V_42 ( V_12 ) ;
return V_189 ;
}
V_56 = V_38 ;
V_38 = (struct V_35 * ) V_38 -> V_41 ;
}
if ( V_37 -> V_58 == V_12 ) {
T_1 V_108 , V_14 ;
unsigned long V_191 ;
F_33 ( L_57 ,
V_55 -> V_185 ) ;
F_33 ( L_58 ) ;
if ( V_37 -> V_96 == V_97 ) {
V_37 -> V_115 ( V_55 , V_12 , 0 ) ;
V_37 -> V_96 = V_116 ;
}
F_33 ( L_59 ) ;
F_6 ( V_1 , V_16 ,
V_17 | V_18 | V_19 ) ;
F_10 ( V_1 , V_192 ) ;
F_33 ( L_60 ) ;
V_191 = 1000000 ;
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
F_1 ( V_1 , V_22 ) ;
} while ( ! ( V_14 & V_23 ) && V_191 -- > 0 );
V_108 = F_1 ( V_1 , V_114 ) ;
F_33
( L_61 ,
V_14 , V_108 , F_4 ( V_1 ) , V_191 ) ;
F_33 ( L_62 ) ;
F_10 ( V_1 , V_193 ) ;
V_191 = 1000000 ;
V_14 = F_5 ( V_1 ) ;
while ( ( V_14 & V_194 ) && V_191 -- > 0 )
V_14 = F_5 ( V_1 ) ;
V_108 = F_1 ( V_1 , V_114 ) ;
F_33 ( L_63 , V_14 , V_108 ) ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << V_12 -> V_39 -> V_61 ) ;
V_37 -> V_58 = NULL ;
V_37 -> V_85 = V_119 ;
V_12 -> V_30 = V_190 << 16 ;
F_23 ( V_55 ) ;
F_40 ( V_12 -> V_39 -> V_40 -> V_186 ) ;
V_12 -> V_42 ( V_12 ) ;
return V_189 ;
}
V_38 = (struct V_35 * ) V_37 -> V_73 ;
while ( V_38 ) {
if ( V_38 == V_12 ) {
F_33
( L_64 ,
V_55 -> V_185 ) ;
F_33 ( L_65 ) ;
F_40 ( V_12 -> V_39 -> V_40 -> V_186 ) ;
return V_195 ;
}
V_38 = (struct V_35 * ) V_38 -> V_41 ;
}
F_23 ( V_55 ) ;
F_40 ( V_12 -> V_39 -> V_40 -> V_186 ) ;
F_33 ( L_66
L_67 , V_55 -> V_185 ) ;
return V_195 ;
}
static int
F_42 ( char * V_196 )
{
int V_10 ;
char * V_197 , * V_198 ;
V_197 = V_199 ;
* V_197 = '\0' ;
if ( V_196 )
strncpy ( V_197 , V_196 , V_200 - strlen ( V_199 ) ) ;
V_199 [ V_200 - 1 ] = '\0' ;
V_197 = V_199 ;
V_10 = 0 ;
while ( * V_197 && ( V_10 < V_201 ) ) {
V_198 = strchr ( V_197 , ',' ) ;
if ( V_198 ) {
* V_198 = '\0' ;
if ( V_197 != V_198 )
V_202 [ V_10 ] = V_197 ;
V_197 = V_198 + 1 ;
V_10 ++ ;
} else {
V_202 [ V_10 ] = V_197 ;
break;
}
}
for ( V_10 = 0 ; V_10 < V_201 ; V_10 ++ )
V_203 [ V_10 ] = 0 ;
V_204 = 1 ;
return 1 ;
}
static int
F_43 ( char * V_205 , int * V_111 , int * V_206 , char * V_100 )
{
int V_15 ;
char * V_207 ;
for ( V_15 = 0 ; V_15 < V_201 ; V_15 ++ ) {
if ( V_203 [ V_15 ] )
continue;
if ( ! strncmp ( V_202 [ V_15 ] , V_205 , strlen ( V_205 ) ) )
break;
if ( ! strncmp ( V_202 [ V_15 ] , L_68 , strlen ( L_68 ) ) )
return 0 ;
}
if ( V_15 == V_201 )
return 0 ;
V_203 [ V_15 ] = 1 ;
V_207 = V_202 [ V_15 ] + strlen ( V_205 ) ;
* V_206 = - 1 ;
if ( * V_207 != ':' )
return ++ V_15 ;
V_207 ++ ;
if ( ( * V_207 >= '0' ) && ( * V_207 <= '9' ) ) {
* V_206 = F_44 ( V_207 , NULL , 0 ) ;
}
return ++ V_15 ;
}
static inline unsigned int
F_45 ( unsigned int V_15 )
{
switch ( V_15 & 3 ) {
case 1 : -- V_15 ;
break;
case 2 : ++ V_15 ;
case 3 : ++ V_15 ;
}
return V_15 ;
}
static void
F_46 ( unsigned int V_208 , struct V_25 V_26 [ 9 ] )
{
unsigned int V_209 , V_10 ;
if ( V_208 < 11 )
V_209 = 2 ;
else if ( V_208 < 16 )
V_209 = 3 ;
else
V_209 = 4 ;
V_209 = ( 100000 * V_209 ) / 2 / V_208 ;
V_26 [ 0 ] . V_27 = 1 ;
V_26 [ 0 ] . V_32 = 0x20 ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ ) {
V_26 [ V_10 ] . V_27 = F_45 ( ( V_10 + 1 ) * V_209 / 100 ) ;
V_26 [ V_10 ] . V_32 = ( V_10 + 1 ) * 0x10 ;
}
V_26 [ 7 ] . V_32 = 0 ;
V_26 [ 8 ] . V_27 = 0 ;
V_26 [ 8 ] . V_32 = 0 ;
}
static T_1
F_47 ( int V_210 , int * V_208 )
{
int V_15 = V_210 ;
if ( V_211 == V_210 )
V_210 = 8 ;
else if ( V_212 == V_210 )
V_210 = 12 ;
else if ( V_213 == V_210 )
V_210 = 16 ;
else if ( V_210 > 7 && V_210 < 11 )
V_15 = V_211 ;
else if ( V_210 > 11 && V_210 < 16 )
V_15 = V_212 ;
else if ( V_210 > 15 && V_210 < 21 )
V_15 = V_213 ;
else {
V_15 = V_211 ;
V_210 = 8 ;
}
* V_208 = V_210 ;
return V_15 ;
}
static inline void F_48 ( struct V_36 * V_214 , int V_215 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ )
if ( V_215 & ( 1 << V_10 ) )
V_214 -> V_82 [ V_10 ] = V_83 ;
}
void
F_49 ( struct V_54 * V_55 , const T_2 V_1 ,
T_4 V_216 , T_5 V_217 , int V_172 )
{
struct V_36 * V_37 ;
int V_10 ;
int V_111 ;
int V_206 ;
char V_100 [ 32 ] ;
if ( ! V_204 && V_218 )
F_42 ( V_218 ) ;
V_37 = (struct V_36 * ) V_55 -> V_37 ;
V_37 -> V_1 = V_1 ;
V_37 -> V_172 = F_47 ( V_172 , & V_10 ) ;
F_46 ( V_10 , V_37 -> V_26 ) ;
V_37 -> V_92 = V_216 ;
V_37 -> V_115 = V_217 ;
V_37 -> V_219 = NULL ;
V_37 -> V_220 = 0 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_37 -> V_59 [ V_10 ] = 0 ;
V_37 -> V_79 [ V_10 ] =
F_13 ( V_187 / 4 , V_173 ,
0 , V_37 -> V_26 ) ;
V_37 -> V_82 [ V_10 ] = V_83 ;
#ifdef F_25
V_37 -> V_62 [ V_10 ] = 0 ;
V_37 -> V_74 [ V_10 ] = 0 ;
V_37 -> V_159 [ V_10 ] = 0 ;
#endif
}
V_37 -> V_52 = NULL ;
V_37 -> V_57 = NULL ;
V_37 -> V_58 = NULL ;
V_37 -> V_73 = NULL ;
V_37 -> V_85 = V_119 ;
V_37 -> V_96 = V_116 ;
V_37 -> V_80 = V_106 ;
V_37 -> V_68 = V_221 ;
V_37 -> args = V_222 ;
V_37 -> V_138 = 0 ;
V_37 -> V_127 = 0 ;
V_37 -> V_126 = V_187 ;
V_37 -> V_91 = 0 ;
#ifdef F_50
V_37 -> V_223 = V_224 | V_225 | V_226 |
V_227 | V_228 | V_229 | V_230 ;
#ifdef F_25
V_37 -> V_104 = 0 ;
V_37 -> V_103 = 0 ;
V_37 -> V_113 = 0 ;
#endif
#endif
if ( F_43 ( L_69 , & V_111 , & V_206 , V_100 ) ) {
V_37 -> V_172 = F_47 ( V_206 , & V_206 ) ;
F_46 ( V_206 , V_37 -> V_26 ) ;
}
if ( F_43 ( L_70 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_125 = V_206 ;
if ( F_43 ( L_71 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_91 = ( V_206 == - 1 ) ? 1 : V_206 ;
if ( F_43 ( L_72 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_126 =
V_37 -> V_26 [ F_12 ( ( unsigned int ) V_206 ,
V_37 -> V_26 ) ] . V_27 ;
if ( F_43 ( L_73 , & V_111 , & V_206 , V_100 ) ) {
if ( ( V_206 >= V_69 ) && ( V_206 <= V_71 ) )
V_37 -> V_68 = V_206 ;
else
V_37 -> V_68 = V_221 ;
}
if ( F_43 ( L_74 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_80 = V_206 ;
if ( F_43 ( L_75 , & V_111 , & V_206 , V_100 ) )
V_37 -> args = V_206 & V_231 ;
if ( F_43 ( L_76 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_95 = V_206 ? V_232 : V_233 ;
if ( V_213 == V_37 -> V_172
&& F_43 ( L_77 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_29 = ! ! V_206 ;
if ( ( V_10 = F_43 ( L_68 , & V_111 , & V_206 , V_100 ) ) ) {
while ( V_10 )
V_203 [ -- V_10 ] = 1 ;
}
#ifdef F_50
if ( F_43 ( L_78 , & V_111 , & V_206 , V_100 ) )
V_37 -> V_223 = V_206 ;
#endif
F_22 ( & V_37 -> V_51 ) ;
F_35 ( V_55 ) ;
F_24 ( & V_37 -> V_51 ) ;
F_33 ( L_79 ,
V_55 -> V_185 ,
( V_37 -> V_176 == V_177 ) ? L_80 : ( V_37 -> V_176 ==
V_180 ) ?
L_81 : ( V_37 -> V_176 ==
V_179 ) ? L_82 : L_83 ,
V_37 -> V_175 , V_37 -> V_125 , V_37 -> V_91 ) ;
#ifdef F_51
F_33 ( L_84 , V_37 -> args ) ;
#else
F_33 ( L_85 ) ;
#endif
F_33 ( L_86 ) ;
for ( V_10 = 0 ; V_10 < V_201 ; V_10 ++ )
F_33 ( L_87 , V_202 [ V_10 ] ) ;
F_33 ( L_88 ) ;
F_33 ( L_89 , V_234 , V_235 ) ;
}
int F_52 ( struct V_54 * V_55 , char * V_100 , int V_8 )
{
#ifdef F_50
char * V_236 ;
struct V_36 * V_214 ;
int V_15 ;
V_214 = (struct V_36 * ) V_55 -> V_37 ;
V_100 [ V_8 ] = '\0' ;
for ( V_236 = V_100 ; * V_236 ; ) {
while ( ',' == * V_236 || ' ' == * V_236 )
++ V_236 ;
if ( ! strncmp ( V_236 , L_90 , 6 ) ) {
V_214 -> args = F_44 ( V_236 + 6 , & V_236 , 0 ) & V_231 ;
} else if ( ! strncmp ( V_236 , L_91 , 11 ) ) {
V_15 = F_44 ( V_236 + 11 , & V_236 , 0 ) ;
if ( V_15 < V_69 || V_15 > V_71 )
V_15 = V_221 ;
V_214 -> V_68 = V_15 ;
} else if ( ! strncmp ( V_236 , L_92 , 7 ) ) {
V_15 = F_44 ( V_236 + 7 , & V_236 , 0 ) ;
V_214 -> V_126 =
V_214 -> V_26 [ F_12 ( ( unsigned int ) V_15 ,
V_214 -> V_26 ) ] . V_27 ;
} else if ( ! strncmp ( V_236 , L_93 , 7 ) ) {
F_48 ( V_214 , ( int ) F_44 ( V_236 + 7 , & V_236 , 0 ) ) ;
} else if ( ! strncmp ( V_236 , L_94 , 5 ) ) {
V_214 -> V_223 = F_44 ( V_236 + 5 , & V_236 , 0 ) ;
} else if ( ! strncmp ( V_236 , L_95 , 6 ) ) {
V_214 -> V_91 = F_44 ( V_236 + 6 , & V_236 , 0 ) ;
} else if ( ! strncmp ( V_236 , L_96 , 7 ) ) {
V_214 -> V_80 = F_44 ( V_236 + 7 , & V_236 , 0 ) ;
} else if ( ! strncmp ( V_236 , L_97 , 6 ) ) {
V_214 -> V_95 =
F_53 ( V_236 + 6 , & V_236 , 0 ) ? V_232 : V_233 ;
} else if ( ! strncmp ( V_236 , L_98 , 5 ) ) {
V_15 = ! ! F_53 ( V_236 + 5 , & V_236 , 0 ) ;
if ( V_15 != V_214 -> V_29 )
F_48 ( V_214 , 0xff ) ;
V_214 -> V_29 = V_15 ;
} else if ( ! strncmp ( V_236 , L_99 , 7 ) ) {
V_15 = F_44 ( V_236 + 7 , & V_236 , 0 ) ;
F_48 ( V_214 , V_15 ^ V_214 -> V_125 ) ;
V_214 -> V_125 = V_15 ;
} else {
break;
}
}
return V_8 ;
#else
return 0 ;
#endif
}
int
F_54 ( struct V_237 * V_238 , struct V_54 * V_55 )
{
#ifdef F_50
struct V_36 * V_214 ;
struct V_35 * V_12 ;
int V_15 ;
V_214 = (struct V_36 * ) V_55 -> V_37 ;
F_22 ( & V_214 -> V_51 ) ;
if ( V_214 -> V_223 & V_224 )
F_55 ( V_238 , L_100 ,
V_234 , V_235 ) ;
if ( V_214 -> V_223 & V_225 ) {
F_55 ( V_238 , L_101
L_102 ,
V_214 -> V_172 , V_214 -> V_125 , V_214 -> V_91 , V_214 -> V_95 , V_214 -> V_29 ) ;
F_55 ( V_238 , L_103 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_55 ( V_238 , L_104 , V_214 -> V_79 [ V_15 ] ) ;
F_55 ( V_238 , L_105 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_55 ( V_238 , L_104 , V_214 -> V_82 [ V_15 ] ) ;
}
#ifdef F_25
if ( V_214 -> V_223 & V_226 ) {
F_55 ( V_238 , L_106 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_55 ( V_238 , L_107 , V_214 -> V_62 [ V_15 ] ) ;
F_55 ( V_238 , L_108 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_55 ( V_238 , L_107 , V_214 -> V_74 [ V_15 ] ) ;
F_55 ( V_238 , L_109 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_55 ( V_238 , L_107 , V_214 -> V_159 [ V_15 ] ) ;
F_55 ( V_238 ,
L_110 ,
V_214 -> V_113 , V_214 -> V_104 , V_214 -> V_103 ) ;
}
#endif
if ( V_214 -> V_223 & V_227 ) {
F_55 ( V_238 , L_111 ) ;
if ( V_214 -> V_58 ) {
V_12 = (struct V_35 * ) V_214 -> V_58 ;
F_55 ( V_238 , L_112 ,
V_12 -> V_39 -> V_60 , V_12 -> V_39 -> V_61 , V_12 -> V_9 [ 0 ] ) ;
}
}
if ( V_214 -> V_223 & V_228 ) {
F_55 ( V_238 , L_113 ) ;
V_12 = (struct V_35 * ) V_214 -> V_52 ;
while ( V_12 ) {
F_55 ( V_238 , L_112 ,
V_12 -> V_39 -> V_60 , V_12 -> V_39 -> V_61 , V_12 -> V_9 [ 0 ] ) ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
}
if ( V_214 -> V_223 & V_229 ) {
F_55 ( V_238 , L_114 ) ;
V_12 = (struct V_35 * ) V_214 -> V_73 ;
while ( V_12 ) {
F_55 ( V_238 , L_112 ,
V_12 -> V_39 -> V_60 , V_12 -> V_39 -> V_61 , V_12 -> V_9 [ 0 ] ) ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
}
F_55 ( V_238 , L_88 ) ;
F_24 ( & V_214 -> V_51 ) ;
#endif
return 0 ;
}
