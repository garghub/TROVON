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
if ( ! ( V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &
( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ) )
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
F_6 ( V_1 , V_77 , ( V_78 ) V_12 -> V_39 -> V_61 ) ;
F_6 ( V_1 , V_79 ,
V_37 -> V_80 [ V_12 -> V_39 -> V_60 ] ) ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] |= ( 1 << ( V_12 -> V_39 -> V_61 & 0xFF ) ) ;
if ( ( V_37 -> V_81 == V_82 ) ||
( V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] == V_84 ) ) {
V_37 -> V_57 = V_12 ;
if ( V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] == V_84 )
V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] = V_85 ;
V_37 -> V_86 = V_87 ;
F_7 ( V_1 , 0 ) ;
F_10 ( V_1 , V_88 ) ;
} else {
V_37 -> V_58 = V_12 ;
F_6 ( V_1 , V_89 , 0 ) ;
F_8 ( V_1 , V_12 -> V_90 , V_12 -> V_9 ) ;
F_6 ( V_1 , V_91 , V_12 -> V_90 ) ;
if ( ( V_12 -> V_43 . V_67 == 0 ) && ( V_37 -> V_92 == 0 ) ) {
if ( V_37 -> V_93 ( V_12 ,
( V_12 -> V_63 == V_64 ) ?
V_94 : V_95 ) )
F_7 ( V_1 , 0 ) ;
else {
F_7 ( V_1 ,
V_12 -> V_43 . V_47 ) ;
F_6 ( V_1 , V_16 ,
V_17 | V_18 | V_37 -> V_96 ) ;
V_37 -> V_97 = V_98 ;
}
} else
F_7 ( V_1 , 0 ) ;
V_37 -> V_86 = V_99 ;
F_10 ( V_1 , V_100 ) ;
}
F_17 (DB_EXECUTE,
printk(L_6, (cmd->SCp.phase) ? L_7 : L_8))
}
static void
F_26 ( const T_2 V_1 , T_1 * V_101 , int V_102 ,
int V_103 , struct V_36 * V_37 )
{
T_1 V_14 ;
F_17 (DB_TRANSFER,
printk(L_9, buf, cnt, data_in_dir ? L_10 : L_11))
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
F_7 ( V_1 , V_102 ) ;
F_10 ( V_1 , V_20 ) ;
if ( V_103 ) {
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
* V_101 ++ = F_1 ( V_1 , V_22 ) ;
} while ( ! ( V_14 & V_23 ) );
} else {
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
F_6 ( V_1 , V_22 , * V_101 ++ ) ;
} while ( ! ( V_14 & V_23 ) );
}
}
static void
F_27 ( const T_2 V_1 , struct V_35 * V_12 ,
int V_103 )
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
F_6 ( V_1 , V_79 ,
V_37 -> V_80 [ V_12 -> V_39 -> V_60 ] ) ;
if ( V_37 -> V_92 || V_37 -> V_93 ( V_12 , V_103 ) ) {
#ifdef F_25
V_37 -> V_104 ++ ;
#endif
F_26 ( V_1 , ( T_1 * ) V_12 -> V_43 . V_46 ,
V_12 -> V_43 . V_47 , V_103 , V_37 ) ;
V_48 = V_12 -> V_43 . V_47 ;
V_12 -> V_43 . V_47 = F_4 ( V_1 ) ;
V_12 -> V_43 . V_46 += ( V_48 - V_12 -> V_43 . V_47 ) ;
}
else {
#ifdef F_25
V_37 -> V_105 ++ ;
#endif
F_6 ( V_1 , V_16 , V_17 | V_18 | V_37 -> V_96 ) ;
F_7 ( V_1 , V_12 -> V_43 . V_47 ) ;
if ( ( V_37 -> V_81 >= V_106 ) ||
( V_37 -> V_81 == V_107 && V_12 -> V_43 . V_67 == 0 ) ) {
F_6 ( V_1 , V_89 , 0x45 ) ;
F_10 ( V_1 , V_100 ) ;
V_37 -> V_86 = V_99 ;
} else
F_10 ( V_1 , V_20 ) ;
V_37 -> V_97 = V_98 ;
}
}
void
F_28 ( struct V_54 * V_55 )
{
struct V_36 * V_37 =
(struct V_36 * ) V_55 -> V_37 ;
const T_2 V_1 = V_37 -> V_1 ;
struct V_35 * V_108 , * V_12 ;
T_1 V_14 , V_109 , V_110 , V_60 , V_61 , * V_111 , V_34 ;
unsigned long V_48 , V_112 ;
V_14 = F_5 ( V_1 ) ;
if ( ! ( V_14 & V_23 ) || ( V_14 & V_113 ) )
return;
F_29 ( & V_37 -> V_51 , V_112 ) ;
#ifdef F_25
V_37 -> V_114 ++ ;
#endif
V_12 = (struct V_35 * ) V_37 -> V_58 ;
V_109 = F_1 ( V_1 , V_115 ) ;
V_110 = F_1 ( V_1 , V_89 ) ;
F_17 (DB_INTR, printk(L_12, asr, sr))
if ( V_37 -> V_97 == V_98 ) {
F_17 (DB_TRANSFER,
printk(L_13, cmd->SCp.ptr, cmd->SCp.this_residual))
V_37 -> V_116 ( V_12 -> V_39 -> V_40 , V_12 , 1 ) ;
V_37 -> V_97 = V_117 ;
V_48 = V_12 -> V_43 . V_47 ;
V_12 -> V_43 . V_47 = F_4 ( V_1 ) ;
V_12 -> V_43 . V_46 += ( V_48 - V_12 -> V_43 . V_47 ) ;
F_17 (DB_TRANSFER,
printk(L_14, cmd->SCp.ptr, cmd->SCp.this_residual))
}
switch ( V_109 ) {
case V_118 :
F_17 (DB_INTR, printk(L_15))
if ( V_37 -> V_86 == V_99 )
V_37 -> V_58 = NULL ;
else {
V_12 = (struct V_35 * ) V_37 -> V_57 ;
V_37 -> V_57 = NULL ;
}
V_12 -> V_30 = V_119 << 16 ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_37 -> V_86 = V_120 ;
V_12 -> V_42 ( V_12 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
F_23 ( V_55 ) ;
break;
case V_121 :
F_17 (DB_INTR, printk(L_16))
V_37 -> V_58 = V_12 =
(struct V_35 * ) V_37 -> V_57 ;
V_37 -> V_57 = NULL ;
V_37 -> V_122 [ 0 ] = F_31 ( 0 , V_12 -> V_39 -> V_61 ) ;
if ( V_12 -> V_43 . V_67 )
V_37 -> V_122 [ 0 ] |= 0x40 ;
if ( V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] == V_85 ) {
V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] = V_123 ;
V_37 -> V_122 [ 1 ] = V_124 ;
V_37 -> V_122 [ 2 ] = 3 ;
V_37 -> V_122 [ 3 ] = V_125 ;
if ( V_37 -> V_126 & ( 1 << V_12 -> V_39 -> V_60 ) ) {
F_14 ( V_37 -> V_127 , 0 ,
0 , V_37 -> V_122 + 4 ) ;
} else {
F_14 ( F_32 ( V_37 ) ,
V_33 ,
V_37 -> V_29 ,
V_37 -> V_122 + 4 ) ;
}
V_37 -> V_128 = 6 ;
#ifdef F_33
V_111 = V_37 -> V_122 + 1 ;
F_34 ( L_17 ,
V_111 [ 0 ] , V_111 [ 2 ] , V_111 [ 3 ] , V_111 [ 4 ] ) ;
#endif
} else
V_37 -> V_128 = 1 ;
V_37 -> V_86 = V_129 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_130 | V_131 :
case V_132 | V_131 :
case V_133 | V_131 :
F_17 (DB_INTR,
printk(L_18, cmd->SCp.this_residual,
cmd->SCp.buffers_residual))
F_27 ( V_1 , V_12 , V_95 ) ;
if ( V_37 -> V_86 != V_99 )
V_37 -> V_86 = V_129 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_130 | V_134 :
case V_132 | V_134 :
case V_133 | V_134 :
F_17 (DB_INTR,
printk(L_19, cmd->SCp.this_residual,
cmd->SCp.buffers_residual))
F_27 ( V_1 , V_12 , V_94 ) ;
if ( V_37 -> V_86 != V_99 )
V_37 -> V_86 = V_129 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_130 | V_135 :
case V_132 | V_135 :
case V_133 | V_135 :
F_17 (DB_INTR, printk(L_20, cmd->cmnd[0]))
F_26 ( V_1 , V_12 -> V_9 , V_12 -> V_90 , V_94 ,
V_37 ) ;
V_37 -> V_86 = V_129 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_130 | V_136 :
case V_132 | V_136 :
case V_133 | V_136 :
F_17 (DB_INTR, printk(L_21))
V_12 -> V_43 . V_49 = F_11 ( V_1 ) ;
F_17 (DB_INTR, printk(L_22, cmd->SCp.Status))
if ( V_37 -> V_81 >= V_107 ) {
V_109 = F_1 ( V_1 , V_115 ) ;
F_35 ( 7 ) ;
V_37 -> V_86 = V_99 ;
F_6 ( V_1 , V_89 , 0x50 ) ;
F_10 ( V_1 , V_100 ) ;
} else {
V_37 -> V_86 = V_129 ;
}
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_130 | V_137 :
case V_132 | V_137 :
case V_133 | V_137 :
F_17 (DB_INTR, printk(L_23))
V_34 = F_11 ( V_1 ) ;
V_109 = F_1 ( V_1 , V_115 ) ;
F_35 ( 7 ) ;
V_37 -> V_138 [ V_37 -> V_139 ] = V_34 ;
if ( V_37 -> V_138 [ 0 ] == V_124 )
V_34 = V_124 ;
else
V_37 -> V_139 = 0 ;
V_12 -> V_43 . V_140 = V_34 ;
switch ( V_34 ) {
case V_141 :
F_17 (DB_INTR, printk(L_24))
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_143 ;
break;
case V_144 :
F_17 (DB_INTR, printk(L_25))
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_129 ;
break;
case V_145 :
F_17 (DB_INTR, printk(L_26))
if ( V_37 -> V_81 >= V_107 ) {
F_6 ( V_1 , V_89 , 0x45 ) ;
F_10 ( V_1 , V_100 ) ;
V_37 -> V_86 = V_99 ;
} else {
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_129 ;
}
break;
case V_146 :
F_17 (DB_INTR, printk(L_27))
V_12 -> V_39 -> V_68 = 1 ;
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_147 ;
break;
case V_148 :
F_17 (DB_INTR, printk(L_28))
#ifdef F_33
F_34 ( L_29 ) ;
#endif
if ( V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] == V_123 ) {
V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] = V_149 ;
V_37 -> V_80 [ V_12 -> V_39 -> V_60 ] =
F_13 ( V_37 -> V_127
/ 4 , 0 , 0 , V_37 -> V_26 ) ;
}
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_129 ;
break;
case V_124 :
F_17 (DB_INTR, printk(L_30))
V_111 = V_37 -> V_138 ;
#ifdef F_33
F_34 ( L_22 , V_111 [ V_37 -> V_139 ] ) ;
#endif
if ( ( V_37 -> V_139 >= 2 ) &&
( V_37 -> V_139 == ( V_111 [ 1 ] + 1 ) ) ) {
switch ( V_111 [ 2 ] ) {
case V_125 :
V_60 = F_13 ( V_37 ->
V_127 / 4 , 0 ,
0 , V_37 -> V_26 ) ;
if ( V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] !=
V_123 ) {
F_10 ( V_1 , V_150 ) ;
V_37 -> V_122 [ 0 ] =
V_124 ;
V_37 -> V_122 [ 1 ] = 3 ;
V_37 -> V_122 [ 2 ] =
V_125 ;
F_14 ( V_37 ->
V_127 , 0 ,
0 , V_37 -> V_122 + 3 ) ;
V_37 -> V_128 = 5 ;
} else {
if ( V_111 [ 4 ] )
V_60 = F_13 ( V_111 [ 3 ] , V_111 [ 4 ] ,
V_37 -> V_29 ,
V_37 -> V_26 ) ;
else if ( V_111 [ 3 ] )
V_60 = F_13 ( V_111 [ 3 ] , V_111 [ 4 ] ,
0 , V_37 -> V_26 ) ;
}
V_37 -> V_80 [ V_12 -> V_39 -> V_60 ] = V_60 ;
#ifdef F_33
F_34 ( L_31 ,
V_37 -> V_80 [ V_12 -> V_39 -> V_60 ] ) ;
#endif
V_37 -> V_83 [ V_12 -> V_39 -> V_60 ] =
V_149 ;
F_10 ( V_1 ,
V_142 ) ;
V_37 -> V_86 = V_129 ;
break;
case V_151 :
F_10 ( V_1 , V_150 ) ;
F_34 ( L_32 ) ;
V_37 -> V_122 [ 0 ] =
V_124 ;
V_37 -> V_122 [ 1 ] = 2 ;
V_37 -> V_122 [ 2 ] =
V_151 ;
V_37 -> V_122 [ 3 ] = 0 ;
V_37 -> V_128 = 4 ;
F_10 ( V_1 ,
V_142 ) ;
V_37 -> V_86 = V_129 ;
break;
default:
F_10 ( V_1 , V_150 ) ;
F_34
( L_33 ,
V_111 [ 2 ] ) ;
V_37 -> V_122 [ 0 ] =
V_148 ;
V_37 -> V_128 = 1 ;
F_10 ( V_1 ,
V_142 ) ;
V_37 -> V_86 = V_129 ;
break;
}
V_37 -> V_139 = 0 ;
}
else {
V_37 -> V_139 ++ ;
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_129 ;
}
break;
default:
F_34 ( L_34 , V_34 ) ;
F_10 ( V_1 , V_150 ) ;
V_37 -> V_122 [ 0 ] = V_148 ;
V_37 -> V_128 = 1 ;
F_10 ( V_1 , V_142 ) ;
V_37 -> V_86 = V_129 ;
}
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_152 :
F_6 ( V_1 , V_75 , V_76 ) ;
if ( V_110 == 0x60 ) {
F_17 (DB_INTR, printk(L_35))
V_12 -> V_43 . V_140 = V_141 ;
V_61 = F_1 ( V_1 , V_77 ) ;
F_17 (DB_INTR, printk(L_36, cmd->SCp.Status, lun))
V_37 -> V_58 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_37 -> V_86 = V_120 ;
if ( V_12 -> V_43 . V_49 == V_50 )
V_12 -> V_43 . V_49 = V_61 ;
if ( V_12 -> V_9 [ 0 ] == V_53
&& V_12 -> V_43 . V_49 != V_153 )
V_12 -> V_30 =
( V_12 ->
V_30 & 0x00ffff ) | ( V_154 << 16 ) ;
else
V_12 -> V_30 =
V_12 -> V_43 . V_49 | ( V_12 -> V_43 . V_140 << 8 ) ;
V_12 -> V_42 ( V_12 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
F_23 ( V_55 ) ;
} else {
F_34
( L_37 ,
V_14 , V_109 , V_110 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
}
break;
case V_155 :
F_17 (DB_INTR, printk(L_25))
V_37 -> V_86 = V_99 ;
F_6 ( V_1 , V_89 , 0x41 ) ;
F_10 ( V_1 , V_100 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_130 | V_156 :
case V_132 | V_156 :
case V_133 | V_156 :
F_17 (DB_INTR, printk(L_38))
if ( V_37 -> V_128 == 0 ) {
V_37 -> V_128 = 1 ;
V_37 -> V_122 [ 0 ] = V_157 ;
}
F_26 ( V_1 , V_37 -> V_122 ,
V_37 -> V_128 , V_94 , V_37 ) ;
F_17 (DB_INTR, printk(L_22, hostdata->outgoing_msg[0]))
V_37 -> V_128 = 0 ;
V_37 -> V_86 = V_129 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
case V_158 :
F_6 ( V_1 , V_75 , V_76 ) ;
if ( V_12 == NULL ) {
F_34 ( L_39 ) ;
V_37 -> V_86 = V_120 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
return;
}
F_17 (DB_INTR, printk(L_40))
V_37 -> V_58 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_37 -> V_86 = V_120 ;
if ( V_12 -> V_9 [ 0 ] == V_53 && V_12 -> V_43 . V_49 != V_153 )
V_12 -> V_30 =
( V_12 -> V_30 & 0x00ffff ) | ( V_154 << 16 ) ;
else
V_12 -> V_30 = V_12 -> V_43 . V_49 | ( V_12 -> V_43 . V_140 << 8 ) ;
V_12 -> V_42 ( V_12 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
F_23 ( V_55 ) ;
break;
case V_159 :
F_6 ( V_1 , V_75 , V_76 ) ;
F_17 (DB_INTR, printk(L_41))
if ( V_12 == NULL ) {
F_34 ( L_39 ) ;
V_37 -> V_86 = V_120 ;
}
switch ( V_37 -> V_86 ) {
case V_143 :
V_37 -> V_58 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_37 -> V_86 = V_120 ;
F_17 (DB_INTR, printk(L_42, cmd->SCp.Status))
if ( V_12 -> V_9 [ 0 ] == V_53
&& V_12 -> V_43 . V_49 != V_153 )
V_12 -> V_30 =
( V_12 ->
V_30 & 0x00ffff ) | ( V_154 << 16 ) ;
else
V_12 -> V_30 =
V_12 -> V_43 . V_49 | ( V_12 -> V_43 . V_140 << 8 ) ;
V_12 -> V_42 ( V_12 ) ;
break;
case V_147 :
case V_99 :
V_12 -> V_41 = ( T_1 * ) V_37 -> V_73 ;
V_37 -> V_73 = V_12 ;
V_37 -> V_58 = NULL ;
V_37 -> V_86 = V_120 ;
#ifdef F_25
V_37 -> V_160 [ V_12 -> V_39 -> V_60 ] ++ ;
#endif
break;
default:
F_34 ( L_43 ) ;
V_37 -> V_86 = V_120 ;
}
F_30 ( & V_37 -> V_51 , V_112 ) ;
F_23 ( V_55 ) ;
break;
case V_161 :
case V_162 :
F_17 (DB_INTR, printk(L_44, sr == CSR_RESEL_AM ? L_45 : L_8))
if ( V_37 -> V_81 <= V_82 ) {
if ( V_37 -> V_57 ) {
V_12 = (struct V_35 * ) V_37 -> V_57 ;
V_37 -> V_57 = NULL ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_12 -> V_41 =
( T_1 * ) V_37 -> V_52 ;
V_37 -> V_52 = V_12 ;
}
}
else {
if ( V_12 ) {
if ( V_110 == 0x00 ) {
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &=
~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_12 -> V_41 =
( T_1 * ) V_37 -> V_52 ;
V_37 -> V_52 = V_12 ;
} else {
F_34
( L_46 ,
V_14 , V_109 , V_110 ) ;
while ( 1 )
F_34 ( L_47 ) ;
}
}
}
V_60 = F_1 ( V_1 , V_75 ) ;
V_60 &= V_163 ;
if ( V_109 == V_161 ) {
V_61 = F_1 ( V_1 , V_22 ) ;
if ( V_37 -> V_81 < V_164 )
F_10 ( V_1 , V_142 ) ;
V_61 &= 7 ;
} else {
for ( V_61 = 255 ; V_61 ; V_61 -- ) {
if ( ( V_14 = F_5 ( V_1 ) ) & V_23 )
break;
F_35 ( 10 ) ;
}
if ( ! ( V_14 & V_23 ) ) {
F_34
( L_48 ) ;
V_61 = 0 ;
} else {
V_109 = F_1 ( V_1 , V_115 ) ;
F_35 ( 7 ) ;
if ( V_109 == ( V_165 | V_137 ) ||
V_109 == ( V_132 | V_137 ) ||
V_109 == ( V_133 | V_137 ) ) {
V_61 = F_11 ( V_1 ) ;
V_14 = F_5 ( V_1 ) ;
if ( ! ( V_14 & V_23 ) ) {
F_35 ( 10 ) ;
V_14 = F_5 ( V_1 ) ;
if ( ! ( V_14 & V_23 ) )
F_34
( L_49 ,
V_14 ) ;
}
V_109 = F_1 ( V_1 , V_115 ) ;
F_35 ( 7 ) ;
if ( V_109 != V_166 )
F_34
( L_50 ,
V_109 ) ;
V_61 &= 7 ;
F_10 ( V_1 ,
V_142 ) ;
} else {
F_34
( L_51 ,
V_109 ) ;
V_61 = 0 ;
}
}
}
V_12 = (struct V_35 * ) V_37 -> V_73 ;
V_108 = NULL ;
while ( V_12 ) {
if ( V_60 == V_12 -> V_39 -> V_60 && V_61 == ( V_78 ) V_12 -> V_39 -> V_61 )
break;
V_108 = V_12 ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
if ( ! V_12 ) {
F_34
( L_52 ,
V_60 , ( V_78 ) V_61 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
return;
}
if ( V_108 )
V_108 -> V_41 = V_12 -> V_41 ;
else
V_37 -> V_73 =
(struct V_35 * ) V_12 -> V_41 ;
V_37 -> V_58 = V_12 ;
if ( V_12 -> V_63 == V_64 )
F_6 ( V_1 , V_65 , V_12 -> V_39 -> V_60 ) ;
else
F_6 ( V_1 , V_65 ,
V_12 -> V_39 -> V_60 | V_66 ) ;
if ( V_37 -> V_81 >= V_164 ) {
F_7 ( V_1 , 0 ) ;
F_6 ( V_1 , V_89 , 0x45 ) ;
F_10 ( V_1 , V_100 ) ;
V_37 -> V_86 = V_99 ;
} else
V_37 -> V_86 = V_129 ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
break;
default:
F_34 ( L_53 , V_14 , V_109 , V_110 ) ;
F_30 ( & V_37 -> V_51 , V_112 ) ;
}
F_17 (DB_INTR, printk(L_54))
}
static void
F_36 ( struct V_54 * V_55 )
{
struct V_36 * V_37 =
(struct V_36 * ) V_55 -> V_37 ;
const T_2 V_1 = V_37 -> V_1 ;
T_1 V_109 ;
#ifdef F_37
{
int V_167 = 0 ;
extern void V_168 ( unsigned long ) ;
while ( ( F_5 ( V_1 ) & V_113 ) && V_167 ++ < 100 )
F_35 ( 10 ) ;
if ( F_5 ( V_1 ) & V_113 )
V_168 ( V_55 -> V_169 ) ;
}
#endif
F_6 ( V_1 , V_91 , V_170 | V_171 |
V_55 -> V_172 | V_37 -> V_173 ) ;
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
F_6 ( V_1 , V_79 ,
F_13 ( V_37 -> V_127 / 4 ,
V_174 , 0 , V_37 -> V_26 ) ) ;
F_6 ( V_1 , V_13 , V_175 ) ;
#ifdef F_38
F_35 ( 25 ) ;
#endif
while ( ! ( F_5 ( V_1 ) & V_23 ) )
;
V_109 = F_1 ( V_1 , V_115 ) ;
V_37 -> V_176 = F_1 ( V_1 , V_11 ) ;
if ( V_109 == 0x00 )
V_37 -> V_177 = V_178 ;
else if ( V_109 == 0x01 ) {
F_6 ( V_1 , V_179 , 0xa5 ) ;
V_109 = F_1 ( V_1 , V_179 ) ;
if ( V_109 == 0xa5 ) {
V_37 -> V_177 = V_180 ;
F_6 ( V_1 , V_179 , 0 ) ;
} else
V_37 -> V_177 = V_181 ;
} else
V_37 -> V_177 = V_182 ;
if ( V_37 -> V_177 != V_180 )
V_37 -> V_29 = 0 ;
F_6 ( V_1 , V_183 , V_184 ) ;
F_6 ( V_1 , V_16 , V_17 | V_18 | V_19 ) ;
}
int
F_39 ( struct V_35 * V_185 )
{
struct V_54 * V_55 ;
struct V_36 * V_37 ;
int V_10 ;
V_55 = V_185 -> V_39 -> V_40 ;
F_22 ( V_55 -> V_186 ) ;
V_37 = (struct V_36 * ) V_55 -> V_37 ;
F_34 ( L_55 , V_55 -> V_187 ) ;
F_40 ( V_55 -> V_188 ) ;
V_37 -> V_116 ( V_55 , NULL , 0 ) ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_37 -> V_59 [ V_10 ] = 0 ;
V_37 -> V_80 [ V_10 ] =
F_13 ( V_189 / 4 , V_174 ,
0 , V_37 -> V_26 ) ;
V_37 -> V_83 [ V_10 ] = V_84 ;
}
V_37 -> V_52 = NULL ;
V_37 -> V_57 = NULL ;
V_37 -> V_58 = NULL ;
V_37 -> V_73 = NULL ;
V_37 -> V_86 = V_120 ;
V_37 -> V_97 = V_117 ;
V_37 -> V_139 = 0 ;
V_37 -> V_128 = 0 ;
F_36 ( V_55 ) ;
V_185 -> V_30 = V_190 << 16 ;
F_41 ( V_55 -> V_188 ) ;
F_24 ( V_55 -> V_186 ) ;
return V_191 ;
}
int
F_42 ( struct V_35 * V_12 )
{
struct V_54 * V_55 ;
struct V_36 * V_37 ;
T_2 V_1 ;
struct V_35 * V_38 , * V_56 ;
F_40 ( V_12 -> V_39 -> V_40 -> V_188 ) ;
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
V_12 -> V_30 = V_192 << 16 ;
F_34
( L_56 ,
V_55 -> V_187 ) ;
F_41 ( V_12 -> V_39 -> V_40 -> V_188 ) ;
V_12 -> V_42 ( V_12 ) ;
return V_191 ;
}
V_56 = V_38 ;
V_38 = (struct V_35 * ) V_38 -> V_41 ;
}
if ( V_37 -> V_58 == V_12 ) {
T_1 V_109 , V_14 ;
unsigned long V_193 ;
F_34 ( L_57 ,
V_55 -> V_187 ) ;
F_34 ( L_58 ) ;
if ( V_37 -> V_97 == V_98 ) {
V_37 -> V_116 ( V_55 , V_12 , 0 ) ;
V_37 -> V_97 = V_117 ;
}
F_34 ( L_59 ) ;
F_6 ( V_1 , V_16 ,
V_17 | V_18 | V_19 ) ;
F_10 ( V_1 , V_194 ) ;
F_34 ( L_60 ) ;
V_193 = 1000000 ;
do {
V_14 = F_5 ( V_1 ) ;
if ( V_14 & V_21 )
F_1 ( V_1 , V_22 ) ;
} while ( ! ( V_14 & V_23 ) && V_193 -- > 0 );
V_109 = F_1 ( V_1 , V_115 ) ;
F_34
( L_61 ,
V_14 , V_109 , F_4 ( V_1 ) , V_193 ) ;
F_34 ( L_62 ) ;
F_10 ( V_1 , V_195 ) ;
V_193 = 1000000 ;
V_14 = F_5 ( V_1 ) ;
while ( ( V_14 & V_196 ) && V_193 -- > 0 )
V_14 = F_5 ( V_1 ) ;
V_109 = F_1 ( V_1 , V_115 ) ;
F_34 ( L_63 , V_14 , V_109 ) ;
V_37 -> V_59 [ V_12 -> V_39 -> V_60 ] &= ~ ( 1 << ( V_12 -> V_39 -> V_61 & 0xff ) ) ;
V_37 -> V_58 = NULL ;
V_37 -> V_86 = V_120 ;
V_12 -> V_30 = V_192 << 16 ;
F_23 ( V_55 ) ;
F_41 ( V_12 -> V_39 -> V_40 -> V_188 ) ;
V_12 -> V_42 ( V_12 ) ;
return V_191 ;
}
V_38 = (struct V_35 * ) V_37 -> V_73 ;
while ( V_38 ) {
if ( V_38 == V_12 ) {
F_34
( L_64 ,
V_55 -> V_187 ) ;
F_34 ( L_65 ) ;
F_41 ( V_12 -> V_39 -> V_40 -> V_188 ) ;
return V_197 ;
}
V_38 = (struct V_35 * ) V_38 -> V_41 ;
}
F_23 ( V_55 ) ;
F_41 ( V_12 -> V_39 -> V_40 -> V_188 ) ;
F_34 ( L_66
L_67 , V_55 -> V_187 ) ;
return V_197 ;
}
static int
F_43 ( char * V_198 )
{
int V_10 ;
char * V_199 , * V_200 ;
V_199 = V_201 ;
* V_199 = '\0' ;
if ( V_198 )
strncpy ( V_199 , V_198 , V_202 - strlen ( V_201 ) ) ;
V_201 [ V_202 - 1 ] = '\0' ;
V_199 = V_201 ;
V_10 = 0 ;
while ( * V_199 && ( V_10 < V_203 ) ) {
V_200 = strchr ( V_199 , ',' ) ;
if ( V_200 ) {
* V_200 = '\0' ;
if ( V_199 != V_200 )
V_204 [ V_10 ] = V_199 ;
V_199 = V_200 + 1 ;
V_10 ++ ;
} else {
V_204 [ V_10 ] = V_199 ;
break;
}
}
for ( V_10 = 0 ; V_10 < V_203 ; V_10 ++ )
V_205 [ V_10 ] = 0 ;
V_206 = 1 ;
return 1 ;
}
static int
F_44 ( char * V_207 , int * V_112 , int * V_208 , char * V_101 )
{
int V_15 ;
char * V_209 ;
for ( V_15 = 0 ; V_15 < V_203 ; V_15 ++ ) {
if ( V_205 [ V_15 ] )
continue;
if ( ! strncmp ( V_204 [ V_15 ] , V_207 , strlen ( V_207 ) ) )
break;
if ( ! strncmp ( V_204 [ V_15 ] , L_68 , strlen ( L_68 ) ) )
return 0 ;
}
if ( V_15 == V_203 )
return 0 ;
V_205 [ V_15 ] = 1 ;
V_209 = V_204 [ V_15 ] + strlen ( V_207 ) ;
* V_208 = - 1 ;
if ( * V_209 != ':' )
return ++ V_15 ;
V_209 ++ ;
if ( ( * V_209 >= '0' ) && ( * V_209 <= '9' ) ) {
* V_208 = F_45 ( V_209 , NULL , 0 ) ;
}
return ++ V_15 ;
}
static inline unsigned int
F_46 ( unsigned int V_15 )
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
F_47 ( unsigned int V_210 , struct V_25 V_26 [ 9 ] )
{
unsigned int V_211 , V_10 ;
if ( V_210 < 11 )
V_211 = 2 ;
else if ( V_210 < 16 )
V_211 = 3 ;
else
V_211 = 4 ;
V_211 = ( 100000 * V_211 ) / 2 / V_210 ;
V_26 [ 0 ] . V_27 = 1 ;
V_26 [ 0 ] . V_32 = 0x20 ;
for ( V_10 = 1 ; V_10 < 8 ; V_10 ++ ) {
V_26 [ V_10 ] . V_27 = F_46 ( ( V_10 + 1 ) * V_211 / 100 ) ;
V_26 [ V_10 ] . V_32 = ( V_10 + 1 ) * 0x10 ;
}
V_26 [ 7 ] . V_32 = 0 ;
V_26 [ 8 ] . V_27 = 0 ;
V_26 [ 8 ] . V_32 = 0 ;
}
static T_1
F_48 ( int V_212 , int * V_210 )
{
int V_15 = V_212 ;
if ( V_213 == V_212 )
V_212 = 8 ;
else if ( V_214 == V_212 )
V_212 = 12 ;
else if ( V_215 == V_212 )
V_212 = 16 ;
else if ( V_212 > 7 && V_212 < 11 )
V_15 = V_213 ;
else if ( V_212 > 11 && V_212 < 16 )
V_15 = V_214 ;
else if ( V_212 > 15 && V_212 < 21 )
V_15 = V_215 ;
else {
V_15 = V_213 ;
V_212 = 8 ;
}
* V_210 = V_212 ;
return V_15 ;
}
static inline void F_49 ( struct V_36 * V_216 , int V_217 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ )
if ( V_217 & ( 1 << V_10 ) )
V_216 -> V_83 [ V_10 ] = V_84 ;
}
void
F_50 ( struct V_54 * V_55 , const T_2 V_1 ,
T_4 V_218 , T_5 V_219 , int V_173 )
{
struct V_36 * V_37 ;
int V_10 ;
int V_112 ;
int V_208 ;
char V_101 [ 32 ] ;
if ( ! V_206 && V_220 )
F_43 ( V_220 ) ;
V_37 = (struct V_36 * ) V_55 -> V_37 ;
V_37 -> V_1 = V_1 ;
V_37 -> V_173 = F_48 ( V_173 , & V_10 ) ;
F_47 ( V_10 , V_37 -> V_26 ) ;
V_37 -> V_93 = V_218 ;
V_37 -> V_116 = V_219 ;
V_37 -> V_221 = NULL ;
V_37 -> V_222 = 0 ;
for ( V_10 = 0 ; V_10 < 8 ; V_10 ++ ) {
V_37 -> V_59 [ V_10 ] = 0 ;
V_37 -> V_80 [ V_10 ] =
F_13 ( V_189 / 4 , V_174 ,
0 , V_37 -> V_26 ) ;
V_37 -> V_83 [ V_10 ] = V_84 ;
#ifdef F_25
V_37 -> V_62 [ V_10 ] = 0 ;
V_37 -> V_74 [ V_10 ] = 0 ;
V_37 -> V_160 [ V_10 ] = 0 ;
#endif
}
V_37 -> V_52 = NULL ;
V_37 -> V_57 = NULL ;
V_37 -> V_58 = NULL ;
V_37 -> V_73 = NULL ;
V_37 -> V_86 = V_120 ;
V_37 -> V_97 = V_117 ;
V_37 -> V_81 = V_107 ;
V_37 -> V_68 = V_223 ;
V_37 -> args = V_224 ;
V_37 -> V_139 = 0 ;
V_37 -> V_128 = 0 ;
V_37 -> V_127 = V_189 ;
V_37 -> V_92 = 0 ;
#ifdef F_51
V_37 -> V_225 = V_226 | V_227 | V_228 |
V_229 | V_230 | V_231 | V_232 ;
#ifdef F_25
V_37 -> V_105 = 0 ;
V_37 -> V_104 = 0 ;
V_37 -> V_114 = 0 ;
#endif
#endif
if ( F_44 ( L_69 , & V_112 , & V_208 , V_101 ) ) {
V_37 -> V_173 = F_48 ( V_208 , & V_208 ) ;
F_47 ( V_208 , V_37 -> V_26 ) ;
}
if ( F_44 ( L_70 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_126 = V_208 ;
if ( F_44 ( L_71 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_92 = ( V_208 == - 1 ) ? 1 : V_208 ;
if ( F_44 ( L_72 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_127 =
V_37 -> V_26 [ F_12 ( ( unsigned int ) V_208 ,
V_37 -> V_26 ) ] . V_27 ;
if ( F_44 ( L_73 , & V_112 , & V_208 , V_101 ) ) {
if ( ( V_208 >= V_69 ) && ( V_208 <= V_71 ) )
V_37 -> V_68 = V_208 ;
else
V_37 -> V_68 = V_223 ;
}
if ( F_44 ( L_74 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_81 = V_208 ;
if ( F_44 ( L_75 , & V_112 , & V_208 , V_101 ) )
V_37 -> args = V_208 & V_233 ;
if ( F_44 ( L_76 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_96 = V_208 ? V_234 : V_235 ;
if ( V_215 == V_37 -> V_173
&& F_44 ( L_77 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_29 = ! ! V_208 ;
if ( ( V_10 = F_44 ( L_68 , & V_112 , & V_208 , V_101 ) ) ) {
while ( V_10 )
V_205 [ -- V_10 ] = 1 ;
}
#ifdef F_51
if ( F_44 ( L_78 , & V_112 , & V_208 , V_101 ) )
V_37 -> V_225 = V_208 ;
#endif
F_22 ( & V_37 -> V_51 ) ;
F_36 ( V_55 ) ;
F_24 ( & V_37 -> V_51 ) ;
F_34 ( L_79 ,
V_55 -> V_187 ,
( V_37 -> V_177 == V_178 ) ? L_80 : ( V_37 -> V_177 ==
V_181 ) ?
L_81 : ( V_37 -> V_177 ==
V_180 ) ? L_82 : L_83 ,
V_37 -> V_176 , V_37 -> V_126 , V_37 -> V_92 ) ;
#ifdef F_52
F_34 ( L_84 , V_37 -> args ) ;
#else
F_34 ( L_85 ) ;
#endif
F_34 ( L_86 ) ;
for ( V_10 = 0 ; V_10 < V_203 ; V_10 ++ )
F_34 ( L_87 , V_204 [ V_10 ] ) ;
F_34 ( L_88 ) ;
F_34 ( L_89 , V_236 , V_237 ) ;
}
int F_53 ( struct V_54 * V_55 , char * V_101 , int V_8 )
{
#ifdef F_51
char * V_238 ;
struct V_36 * V_216 ;
int V_15 ;
V_216 = (struct V_36 * ) V_55 -> V_37 ;
V_101 [ V_8 ] = '\0' ;
for ( V_238 = V_101 ; * V_238 ; ) {
while ( ',' == * V_238 || ' ' == * V_238 )
++ V_238 ;
if ( ! strncmp ( V_238 , L_90 , 6 ) ) {
V_216 -> args = F_45 ( V_238 + 6 , & V_238 , 0 ) & V_233 ;
} else if ( ! strncmp ( V_238 , L_91 , 11 ) ) {
V_15 = F_45 ( V_238 + 11 , & V_238 , 0 ) ;
if ( V_15 < V_69 || V_15 > V_71 )
V_15 = V_223 ;
V_216 -> V_68 = V_15 ;
} else if ( ! strncmp ( V_238 , L_92 , 7 ) ) {
V_15 = F_45 ( V_238 + 7 , & V_238 , 0 ) ;
V_216 -> V_127 =
V_216 -> V_26 [ F_12 ( ( unsigned int ) V_15 ,
V_216 -> V_26 ) ] . V_27 ;
} else if ( ! strncmp ( V_238 , L_93 , 7 ) ) {
F_49 ( V_216 , ( int ) F_45 ( V_238 + 7 , & V_238 , 0 ) ) ;
} else if ( ! strncmp ( V_238 , L_94 , 5 ) ) {
V_216 -> V_225 = F_45 ( V_238 + 5 , & V_238 , 0 ) ;
} else if ( ! strncmp ( V_238 , L_95 , 6 ) ) {
V_216 -> V_92 = F_45 ( V_238 + 6 , & V_238 , 0 ) ;
} else if ( ! strncmp ( V_238 , L_96 , 7 ) ) {
V_216 -> V_81 = F_45 ( V_238 + 7 , & V_238 , 0 ) ;
} else if ( ! strncmp ( V_238 , L_97 , 6 ) ) {
V_216 -> V_96 =
F_54 ( V_238 + 6 , & V_238 , 0 ) ? V_234 : V_235 ;
} else if ( ! strncmp ( V_238 , L_98 , 5 ) ) {
V_15 = ! ! F_54 ( V_238 + 5 , & V_238 , 0 ) ;
if ( V_15 != V_216 -> V_29 )
F_49 ( V_216 , 0xff ) ;
V_216 -> V_29 = V_15 ;
} else if ( ! strncmp ( V_238 , L_99 , 7 ) ) {
V_15 = F_45 ( V_238 + 7 , & V_238 , 0 ) ;
F_49 ( V_216 , V_15 ^ V_216 -> V_126 ) ;
V_216 -> V_126 = V_15 ;
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
F_55 ( struct V_239 * V_240 , struct V_54 * V_55 )
{
#ifdef F_51
struct V_36 * V_216 ;
struct V_35 * V_12 ;
int V_15 ;
V_216 = (struct V_36 * ) V_55 -> V_37 ;
F_22 ( & V_216 -> V_51 ) ;
if ( V_216 -> V_225 & V_226 )
F_56 ( V_240 , L_100 ,
V_236 , V_237 ) ;
if ( V_216 -> V_225 & V_227 ) {
F_56 ( V_240 , L_101
L_102 ,
V_216 -> V_173 , V_216 -> V_126 , V_216 -> V_92 , V_216 -> V_96 , V_216 -> V_29 ) ;
F_57 ( V_240 , L_103 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_56 ( V_240 , L_104 , V_216 -> V_80 [ V_15 ] ) ;
F_57 ( V_240 , L_105 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_56 ( V_240 , L_104 , V_216 -> V_83 [ V_15 ] ) ;
}
#ifdef F_25
if ( V_216 -> V_225 & V_228 ) {
F_57 ( V_240 , L_106 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_56 ( V_240 , L_107 , V_216 -> V_62 [ V_15 ] ) ;
F_57 ( V_240 , L_108 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_56 ( V_240 , L_107 , V_216 -> V_74 [ V_15 ] ) ;
F_57 ( V_240 , L_109 ) ;
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_56 ( V_240 , L_107 , V_216 -> V_160 [ V_15 ] ) ;
F_56 ( V_240 ,
L_110 ,
V_216 -> V_114 , V_216 -> V_105 , V_216 -> V_104 ) ;
}
#endif
if ( V_216 -> V_225 & V_229 ) {
F_57 ( V_240 , L_111 ) ;
if ( V_216 -> V_58 ) {
V_12 = (struct V_35 * ) V_216 -> V_58 ;
F_56 ( V_240 , L_112 ,
V_12 -> V_39 -> V_60 , V_12 -> V_39 -> V_61 , V_12 -> V_9 [ 0 ] ) ;
}
}
if ( V_216 -> V_225 & V_230 ) {
F_57 ( V_240 , L_113 ) ;
V_12 = (struct V_35 * ) V_216 -> V_52 ;
while ( V_12 ) {
F_56 ( V_240 , L_112 ,
V_12 -> V_39 -> V_60 , V_12 -> V_39 -> V_61 , V_12 -> V_9 [ 0 ] ) ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
}
if ( V_216 -> V_225 & V_231 ) {
F_57 ( V_240 , L_114 ) ;
V_12 = (struct V_35 * ) V_216 -> V_73 ;
while ( V_12 ) {
F_56 ( V_240 , L_112 ,
V_12 -> V_39 -> V_60 , V_12 -> V_39 -> V_61 , V_12 -> V_9 [ 0 ] ) ;
V_12 = (struct V_35 * ) V_12 -> V_41 ;
}
}
F_58 ( V_240 , '\n' ) ;
F_24 ( & V_216 -> V_51 ) ;
#endif
return 0 ;
}
