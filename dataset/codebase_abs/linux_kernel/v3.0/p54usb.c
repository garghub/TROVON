static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 -> V_4 ;
struct V_5 * V_6 = (struct V_5 * ) V_3 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_11 ;
F_2 ( V_3 , & V_11 -> V_12 ) ;
if ( F_3 ( V_1 -> V_13 ) ) {
F_4 ( V_3 ) ;
return;
}
F_5 ( V_3 , V_1 -> V_14 ) ;
if ( V_11 -> V_15 == V_16 )
F_6 ( V_3 , V_11 -> V_17 . V_18 ) ;
if ( V_11 -> V_17 . V_19 == V_20 ) {
F_6 ( V_3 , 4 ) ;
F_5 ( V_3 , 4 ) ;
}
if ( F_7 ( V_9 , V_3 ) ) {
V_3 = F_8 ( V_11 -> V_17 . V_21 + 32 ) ;
if ( F_3 ( ! V_3 ) ) {
return;
}
V_6 = (struct V_5 * ) V_3 -> V_7 ;
V_6 -> V_1 = V_1 ;
V_6 -> V_9 = V_9 ;
V_1 -> V_22 = F_9 ( V_3 ) ;
V_1 -> V_4 = V_3 ;
} else {
if ( V_11 -> V_15 == V_16 )
F_10 ( V_3 , V_11 -> V_17 . V_18 ) ;
if ( V_11 -> V_17 . V_19 == V_20 ) {
F_10 ( V_3 , 4 ) ;
F_5 ( V_3 , 4 ) ;
}
F_11 ( V_3 ) ;
F_12 ( V_3 , 0 ) ;
V_1 -> V_22 = F_9 ( V_3 ) ;
}
F_13 ( & V_11 -> V_12 , V_3 ) ;
F_14 ( V_1 , & V_11 -> V_23 ) ;
if ( F_15 ( V_1 , V_24 ) ) {
F_2 ( V_3 , & V_11 -> V_12 ) ;
F_16 ( V_1 ) ;
F_4 ( V_3 ) ;
}
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
struct V_8 * V_9 =
F_18 ( F_19 ( V_1 -> V_9 , 0 ) ) ;
F_20 ( V_9 , V_3 ) ;
}
static void F_21 ( struct V_1 * V_1 ) { }
static void F_22 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
F_23 ( & V_11 -> V_23 ) ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_25 = NULL ;
struct V_2 * V_3 ;
struct V_5 * V_6 ;
int V_26 = 0 ;
while ( F_25 ( & V_11 -> V_12 ) < 32 ) {
V_3 = F_26 ( V_11 -> V_17 . V_21 + 32 , V_27 ) ;
if ( ! V_3 ) {
V_26 = - V_28 ;
goto V_29;
}
V_25 = F_27 ( 0 , V_27 ) ;
if ( ! V_25 ) {
V_26 = - V_28 ;
goto V_29;
}
F_28 ( V_25 , V_11 -> V_30 ,
F_29 ( V_11 -> V_30 , V_31 ) ,
F_9 ( V_3 ) ,
V_11 -> V_17 . V_21 + 32 , F_1 , V_3 ) ;
V_6 = (struct V_5 * ) V_3 -> V_7 ;
V_6 -> V_1 = V_25 ;
V_6 -> V_9 = V_9 ;
F_13 ( & V_11 -> V_12 , V_3 ) ;
F_14 ( V_25 , & V_11 -> V_23 ) ;
V_26 = F_15 ( V_25 , V_27 ) ;
if ( V_26 ) {
F_2 ( V_3 , & V_11 -> V_12 ) ;
F_16 ( V_25 ) ;
goto V_29;
}
F_30 ( V_25 ) ;
V_25 = NULL ;
}
return 0 ;
V_29:
F_30 ( V_25 ) ;
F_31 ( V_3 ) ;
F_22 ( V_9 ) ;
return V_26 ;
}
static T_1 F_32 ( const T_1 * V_32 , T_2 V_33 )
{
T_3 V_34 = 0 ;
V_33 >>= 2 ;
while ( V_33 -- ) {
V_34 ^= F_33 ( * V_32 ++ ) ;
V_34 = ( V_34 >> 5 ) ^ ( V_34 << 3 ) ;
}
return F_34 ( V_34 ) ;
}
static void F_35 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_35 ;
struct V_36 * V_37 = ( void * ) V_3 -> V_32 - sizeof( * V_37 ) ;
V_35 = F_27 ( 0 , V_24 ) ;
if ( ! V_35 ) {
F_20 ( V_9 , V_3 ) ;
return;
}
V_37 -> V_38 = F_32 ( ( T_1 * ) V_3 -> V_32 , V_3 -> V_39 ) ;
V_37 -> V_40 = ( (struct V_41 * ) V_3 -> V_32 ) -> V_42 ;
F_28 ( V_35 , V_11 -> V_30 ,
F_36 ( V_11 -> V_30 , V_31 ) ,
V_37 , V_3 -> V_39 + sizeof( * V_37 ) , F_37 ( V_3 ) ?
F_17 : F_21 , V_3 ) ;
V_35 -> V_43 |= V_44 ;
F_14 ( V_35 , & V_11 -> V_23 ) ;
if ( F_15 ( V_35 , V_24 ) ) {
F_16 ( V_35 ) ;
F_20 ( V_9 , V_3 ) ;
}
F_30 ( V_35 ) ;
}
static void F_38 ( struct V_8 * V_9 , struct V_2 * V_3 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
struct V_1 * V_45 = NULL , * V_35 = NULL ;
struct V_46 * V_37 = ( void * ) V_3 -> V_32 - sizeof( * V_37 ) ;
struct V_47 * V_48 = NULL ;
int V_29 = - V_28 ;
V_48 = F_39 ( sizeof( * V_48 ) , V_24 ) ;
if ( ! V_48 )
goto V_49;
V_45 = F_27 ( 0 , V_24 ) ;
if ( ! V_45 )
goto V_49;
V_35 = F_27 ( 0 , V_24 ) ;
if ( ! V_35 )
goto V_49;
V_48 -> V_50 = F_40 ( V_51 ) ;
V_48 -> V_52 = F_34 ( V_53 ) ;
V_48 -> V_54 = F_34 ( V_55 ) ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
V_37 -> V_39 = F_40 ( V_3 -> V_39 ) ;
V_37 -> V_40 = ( (struct V_41 * ) V_3 -> V_32 ) -> V_42 ;
F_28 ( V_45 , V_11 -> V_30 ,
F_36 ( V_11 -> V_30 , V_56 ) , V_48 , sizeof( * V_48 ) ,
F_21 , V_9 ) ;
V_45 -> V_43 |= V_57 | V_44 ;
V_48 = NULL ;
F_28 ( V_35 , V_11 -> V_30 ,
F_36 ( V_11 -> V_30 , V_31 ) ,
V_37 , V_3 -> V_39 + sizeof( * V_37 ) , F_37 ( V_3 ) ?
F_17 : F_21 , V_3 ) ;
V_35 -> V_43 |= V_44 ;
F_14 ( V_45 , & V_11 -> V_23 ) ;
V_29 = F_15 ( V_45 , V_24 ) ;
if ( V_29 ) {
F_16 ( V_45 ) ;
goto V_49;
}
F_14 ( V_35 , & V_11 -> V_23 ) ;
V_29 = F_15 ( V_35 , V_24 ) ;
if ( V_29 ) {
F_16 ( V_35 ) ;
goto V_49;
}
V_49:
F_30 ( V_45 ) ;
F_30 ( V_35 ) ;
if ( V_29 ) {
F_41 ( V_48 ) ;
F_20 ( V_9 , V_3 ) ;
}
}
static int F_42 ( struct V_10 * V_11 ,
struct V_47 * V_58 ,
enum V_59 type ,
T_1 V_52 , T_1 V_54 )
{
unsigned int V_60 ;
int V_61 ;
if ( type & 0x0800 )
V_60 = F_36 ( V_11 -> V_30 , V_56 ) ;
else
V_60 = F_36 ( V_11 -> V_30 , V_62 ) ;
V_58 -> V_50 = F_40 ( type ) ;
V_58 -> V_52 = V_52 ;
V_58 -> V_54 = V_54 ;
return F_43 ( V_11 -> V_30 , V_60 , V_58 , sizeof( * V_58 ) , & V_61 , 1000 ) ;
}
static int F_44 ( struct V_10 * V_11 , void * V_58 ,
enum V_59 type ,
T_1 V_52 , T_1 * V_54 )
{
struct V_63 * V_64 = V_58 ;
T_1 * V_48 = V_58 ;
unsigned int V_60 ;
int V_61 , V_29 ;
if ( type & 0x0800 )
V_60 = V_56 ;
else
V_60 = V_62 ;
V_64 -> V_50 = F_40 ( type ) ;
V_64 -> V_52 = V_52 ;
V_29 = F_43 ( V_11 -> V_30 , F_36 ( V_11 -> V_30 , V_60 ) ,
V_64 , sizeof( * V_64 ) , & V_61 , 1000 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_43 ( V_11 -> V_30 , F_29 ( V_11 -> V_30 , V_60 ) ,
V_48 , sizeof( * V_48 ) , & V_61 , 1000 ) ;
if ( V_29 )
return V_29 ;
* V_54 = * V_48 ;
return 0 ;
}
static int F_45 ( struct V_10 * V_11 , unsigned int V_60 ,
void * V_32 , T_2 V_39 )
{
int V_61 ;
return F_43 ( V_11 -> V_30 , F_36 ( V_11 -> V_30 , V_60 ) ,
V_32 , V_39 , & V_61 , 2000 ) ;
}
static int F_46 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
int V_26 , V_65 = ( V_11 -> V_66 -> V_67 != V_68 ) ;
if ( V_65 ) {
V_26 = F_47 ( V_11 -> V_30 , V_11 -> V_66 ) ;
if ( V_26 < 0 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_1
L_2 , V_26 ) ;
return V_26 ;
}
}
V_26 = F_49 ( V_11 -> V_30 ) ;
if ( V_65 )
F_50 ( V_11 -> V_30 ) ;
if ( V_26 )
F_48 ( & V_11 -> V_30 -> V_9 , L_3
L_4 , V_26 ) ;
return V_26 ;
}
static int F_51 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
T_4 * V_58 ;
int V_26 ;
V_58 = F_52 ( V_69 , 4 , V_27 ) ;
if ( ! V_58 )
return - V_28 ;
V_26 = F_45 ( V_11 , V_31 ,
V_58 , 4 ) ;
F_41 ( V_58 ) ;
if ( V_26 )
F_48 ( & V_11 -> V_30 -> V_9 , L_5
L_6 , V_26 ) ;
return V_26 ;
}
static int F_53 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
int V_29 , V_61 ;
T_4 V_70 = 0 ;
T_4 * V_58 , * V_71 ;
const T_4 * V_32 ;
unsigned int V_72 , V_73 , V_74 ;
struct V_75 * V_37 ;
unsigned long V_76 ;
V_29 = F_51 ( V_9 ) ;
if ( V_29 )
return V_29 ;
V_71 = V_58 = F_39 ( V_77 , V_27 ) ;
if ( ! V_58 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_7
L_8 ) ;
return - V_28 ;
}
V_72 = V_74 = F_54 ( ( T_2 ) V_77 , V_11 -> V_78 -> V_79 ) ;
strcpy ( V_58 , V_80 ) ;
V_72 -= strlen ( V_80 ) ;
V_71 += strlen ( V_80 ) ;
V_32 = V_11 -> V_78 -> V_32 ;
V_73 = V_11 -> V_78 -> V_79 ;
V_37 = (struct V_75 * ) ( V_58 + strlen ( V_80 ) ) ;
memcpy ( V_37 -> V_81 , V_82 , V_83 ) ;
V_37 -> V_84 = F_34 ( V_85 ) ;
V_37 -> V_86 = F_34 ( V_11 -> V_78 -> V_79 ) ;
V_37 -> V_87 = F_34 ( ~ F_55 ( ~ 0 , ( void * ) & V_37 -> V_84 ,
sizeof( T_3 ) * 2 ) ) ;
V_72 -= sizeof( * V_37 ) ;
V_71 += sizeof( * V_37 ) ;
while ( V_73 ) {
while ( V_72 -- ) {
if ( V_70 ) {
* V_71 ++ = V_70 ;
V_70 = 0 ;
V_73 -- ;
continue;
}
switch ( * V_32 ) {
case '~' :
* V_71 ++ = '}' ;
V_70 = '^' ;
break;
case '}' :
* V_71 ++ = '}' ;
V_70 = ']' ;
break;
default:
* V_71 ++ = * V_32 ;
V_73 -- ;
break;
}
V_32 ++ ;
}
V_29 = F_45 ( V_11 , V_31 , V_58 , V_74 ) ;
if ( V_29 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_9
L_10 ) ;
goto V_88;
}
V_71 = V_58 ;
V_72 = V_74 = F_54 ( ( unsigned int ) V_77 , V_73 ) ;
}
* ( ( T_1 * ) V_58 ) = F_34 ( ~ F_55 ( ~ 0 , V_11 -> V_78 -> V_32 ,
V_11 -> V_78 -> V_79 ) ) ;
V_29 = F_45 ( V_11 , V_31 , V_58 , sizeof( T_3 ) ) ;
if ( V_29 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_11 ) ;
goto V_88;
}
V_76 = V_89 + F_56 ( 1000 ) ;
while ( ! ( V_29 = F_43 ( V_11 -> V_30 ,
F_29 ( V_11 -> V_30 , V_31 ) , V_58 , 128 , & V_61 , 1000 ) ) ) {
if ( V_61 > 2 && ! memcmp ( V_58 , L_12 , 2 ) )
break;
if ( V_61 > 5 && ! memcmp ( V_58 , L_13 , 5 ) ) {
V_29 = - V_90 ;
break;
}
if ( F_57 ( V_89 , V_76 ) ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_14
L_15 ) ;
V_29 = - V_91 ;
break;
}
}
if ( V_29 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_11 ) ;
goto V_88;
}
V_58 [ 0 ] = 'g' ;
V_58 [ 1 ] = '\r' ;
V_29 = F_45 ( V_11 , V_31 , V_58 , 2 ) ;
if ( V_29 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_16 ) ;
goto V_88;
}
V_76 = V_89 + F_56 ( 1000 ) ;
while ( ! ( V_29 = F_43 ( V_11 -> V_30 ,
F_29 ( V_11 -> V_30 , V_31 ) , V_58 , 128 , & V_61 , 1000 ) ) ) {
if ( V_61 > 0 && V_58 [ 0 ] == 'g' )
break;
if ( F_57 ( V_89 , V_76 ) ) {
V_29 = - V_91 ;
break;
}
}
if ( V_29 )
goto V_88;
V_88:
F_41 ( V_58 ) ;
return V_29 ;
}
static int F_58 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
const struct V_92 * V_93 = ( const struct V_92 * ) V_53 ;
int V_29 , V_61 ;
void * V_58 ;
T_1 V_48 ;
unsigned int V_73 , V_94 ;
const T_4 * V_32 ;
V_58 = F_39 ( 512 , V_27 ) ;
if ( ! V_58 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_17
L_18 ) ;
return - V_28 ;
}
#define F_59 ( type , V_52 , V_32 ) \
do {\
err = p54u_write(priv, buf, type,\
cpu_to_le32((u32)(unsigned long)addr), data);\
if (err) \
goto fail;\
} while (0)
#define F_60 ( type , V_52 ) \
do {\
err = p54u_read(priv, buf, type,\
cpu_to_le32((u32)(unsigned long)addr), &reg);\
if (err)\
goto fail;\
} while (0)
F_60 ( V_95 , V_96 ) ;
V_48 |= F_34 ( V_97 ) ;
V_48 &= F_34 ( ~ V_98 ) ;
F_59 ( V_95 , V_96 , V_48 ) ;
F_61 ( 100 ) ;
V_48 |= F_34 ( V_98 ) ;
V_48 &= F_34 ( ~ V_97 ) ;
F_59 ( V_95 , V_96 , V_48 ) ;
F_61 ( 100 ) ;
F_59 ( V_95 , V_99 ,
F_34 ( V_100 |
V_101 |
V_102 ) ) ;
F_61 ( 20 ) ;
F_59 ( V_103 , V_104 ,
F_34 ( V_105 |
V_106 ) ) ;
F_59 ( V_107 , V_108 ,
F_34 ( V_109 ) ) ;
F_60 ( V_103 , V_110 ) ;
V_48 |= F_34 ( V_111 ) ;
F_59 ( V_103 , V_110 , V_48 ) ;
F_60 ( V_95 , V_112 ) ;
F_59 ( V_95 , V_113 ,
F_34 ( V_114 ) ) ;
F_59 ( V_95 , V_115 ,
F_34 ( V_114 ) ) ;
F_59 ( V_107 , V_116 ,
F_34 ( V_117 ) ) ;
F_59 ( V_118 , 0x10000 | V_104 ,
F_34 ( V_105 |
V_106 ) ) ;
F_59 ( V_118 , 0x10000 | 0x40 , 0 ) ;
F_59 ( V_119 , 0x10000 | V_108 ,
F_34 ( V_53 ) ) ;
F_59 ( V_95 , V_120 , 0 ) ;
F_59 ( V_95 , V_121 ,
F_34 ( V_122 ) ) ;
F_59 ( V_51 , & V_93 -> V_123 , 0 ) ;
F_60 ( V_51 , & V_93 -> V_124 ) ;
V_48 &= F_34 ( ~ V_125 ) ;
V_48 &= F_34 ( ~ V_126 ) ;
V_48 &= F_34 ( ~ V_127 ) ;
F_59 ( V_51 , & V_93 -> V_124 , V_48 ) ;
F_61 ( 20 ) ;
V_48 |= F_34 ( V_125 ) ;
F_59 ( V_51 , & V_93 -> V_124 , V_48 ) ;
F_61 ( 20 ) ;
V_48 &= F_34 ( ~ V_125 ) ;
F_59 ( V_51 , & V_93 -> V_124 , V_48 ) ;
F_61 ( 100 ) ;
F_60 ( V_51 , & V_93 -> V_128 ) ;
F_59 ( V_51 , & V_93 -> V_129 , V_48 ) ;
V_73 = V_11 -> V_78 -> V_79 ;
V_32 = V_11 -> V_78 -> V_32 ;
V_94 = V_85 ;
while ( V_73 ) {
unsigned int V_130 = F_54 ( V_73 , ( unsigned int ) 512 ) ;
memcpy ( V_58 , V_32 , V_130 ) ;
V_29 = F_45 ( V_11 , V_31 , V_58 , V_130 ) ;
if ( V_29 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_19
L_20 ) ;
goto V_131;
}
F_59 ( V_51 , & V_93 -> V_132 ,
F_34 ( 0xc0000f00 ) ) ;
F_59 ( V_51 ,
0x0020 | ( unsigned long ) & V_93 -> V_133 , 0 ) ;
F_59 ( V_51 ,
0x0020 | ( unsigned long ) & V_93 -> V_133 ,
F_34 ( 1 ) ) ;
F_59 ( V_51 ,
0x0024 | ( unsigned long ) & V_93 -> V_133 ,
F_34 ( V_130 ) ) ;
F_59 ( V_51 ,
0x0028 | ( unsigned long ) & V_93 -> V_133 ,
F_34 ( V_94 ) ) ;
F_59 ( V_51 , & V_93 -> V_134 ,
F_34 ( V_135 ) ) ;
F_59 ( V_51 , & V_93 -> V_136 ,
F_34 ( V_130 >> 2 ) ) ;
F_59 ( V_51 , & V_93 -> V_137 ,
F_34 ( V_138 ) ) ;
F_61 ( 10 ) ;
F_60 ( V_51 ,
0x002C | ( unsigned long ) & V_93 -> V_133 ) ;
if ( ! ( V_48 & F_34 ( V_139 ) ) ||
! ( V_48 & F_34 ( V_140 ) ) ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_21
L_22 ) ;
goto V_131;
}
F_59 ( V_95 , V_141 ,
F_34 ( V_142 ) ) ;
V_73 -= V_130 ;
V_32 += V_130 ;
V_94 += V_130 ;
}
F_60 ( V_51 , & V_93 -> V_124 ) ;
V_48 &= F_34 ( ~ V_125 ) ;
V_48 &= F_34 ( ~ V_127 ) ;
V_48 |= F_34 ( V_126 ) ;
F_59 ( V_51 , & V_93 -> V_124 , V_48 ) ;
F_61 ( 20 ) ;
V_48 |= F_34 ( V_125 ) ;
F_59 ( V_51 , & V_93 -> V_124 , V_48 ) ;
V_48 &= F_34 ( ~ V_125 ) ;
F_59 ( V_51 , & V_93 -> V_124 , V_48 ) ;
F_61 ( 100 ) ;
F_60 ( V_51 , & V_93 -> V_128 ) ;
F_59 ( V_51 , & V_93 -> V_129 , V_48 ) ;
F_59 ( V_51 , & V_93 -> V_123 ,
F_34 ( V_143 ) ) ;
F_59 ( V_95 , V_121 ,
F_34 ( V_122 ) ) ;
F_59 ( V_95 , V_120 ,
F_34 ( V_144 |
V_145 ) ) ;
F_59 ( V_51 , & V_93 -> V_146 ,
F_34 ( V_147 ) ) ;
V_29 = F_62 ( V_11 -> V_30 ,
F_29 ( V_11 -> V_30 , V_148 ) ,
V_58 , sizeof( T_1 ) , & V_61 , 1000 ) ;
if ( V_29 || V_61 != sizeof( T_1 ) )
goto V_131;
F_60 ( V_51 , & V_93 -> V_128 ) ;
F_59 ( V_51 , & V_93 -> V_129 , V_48 ) ;
if ( ! ( V_48 & F_34 ( V_143 ) ) )
V_29 = - V_90 ;
F_59 ( V_95 , V_120 , 0 ) ;
F_59 ( V_95 , V_121 ,
F_34 ( V_122 ) ) ;
#undef F_59
#undef F_60
V_131:
F_41 ( V_58 ) ;
return V_29 ;
}
static int F_63 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
int V_29 , V_149 ;
F_64 ( F_65 ( V_150 ) != V_151 ) ;
for ( V_149 = 0 ; V_149 < V_151 ; V_149 ++ )
if ( V_150 [ V_149 ] . type == V_11 -> V_15 )
break;
if ( V_149 == V_151 )
return - V_152 ;
V_29 = F_66 ( & V_11 -> V_78 , V_150 [ V_149 ] . V_78 , & V_11 -> V_30 -> V_9 ) ;
if ( V_29 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_23
L_24 , V_150 [ V_149 ] . V_78 , V_29 ) ;
V_29 = F_66 ( & V_11 -> V_78 , V_150 [ V_149 ] . V_153 ,
& V_11 -> V_30 -> V_9 ) ;
if ( V_29 )
return V_29 ;
}
V_29 = F_67 ( V_9 , V_11 -> V_78 ) ;
if ( V_29 )
goto V_49;
if ( V_11 -> V_17 . V_19 != V_150 [ V_149 ] . V_66 ) {
F_48 ( & V_11 -> V_30 -> V_9 , L_25
L_26 ,
V_150 [ V_149 ] . V_154 ) ;
V_29 = - V_90 ;
}
V_49:
if ( V_29 )
F_68 ( V_11 -> V_78 ) ;
return V_29 ;
}
static int F_69 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = V_9 -> V_11 ;
int V_29 ;
V_29 = F_24 ( V_9 ) ;
if ( V_29 ) {
return V_29 ;
}
V_11 -> V_17 . V_155 = F_24 ;
return 0 ;
}
static void F_70 ( struct V_8 * V_9 )
{
F_22 ( V_9 ) ;
}
static int T_5 F_71 ( struct V_156 * V_66 ,
const struct V_157 * V_158 )
{
struct V_159 * V_30 = F_72 ( V_66 ) ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
int V_29 ;
unsigned int V_149 , V_160 ;
V_9 = F_73 ( sizeof( * V_11 ) ) ;
if ( ! V_9 ) {
F_48 ( & V_30 -> V_9 , L_27 ) ;
return - V_28 ;
}
V_11 = V_9 -> V_11 ;
V_11 -> V_15 = V_161 ;
F_74 ( V_9 , & V_66 -> V_9 ) ;
F_75 ( V_66 , V_9 ) ;
V_11 -> V_30 = V_30 ;
V_11 -> V_66 = V_66 ;
F_76 ( & V_11 -> V_12 ) ;
F_77 ( & V_11 -> V_23 ) ;
F_78 ( V_30 ) ;
V_149 = V_66 -> V_162 -> V_163 . V_164 ;
V_160 = 0 ;
while ( V_149 -- ) {
switch ( V_66 -> V_162 -> V_165 [ V_149 ] . V_163 . V_166 ) {
case V_31 :
case V_167 :
case V_62 :
case V_56 :
case V_31 | V_168 :
case V_167 | V_168 :
case V_62 | V_168 :
case V_56 | V_168 :
case V_148 | V_168 :
V_160 ++ ;
}
}
V_11 -> V_17 . V_155 = F_69 ;
V_11 -> V_17 . V_169 = F_70 ;
if ( V_160 < V_170 ) {
#ifdef F_79
V_30 -> V_171 = 1 ;
#endif
V_29 = F_46 ( V_9 ) ;
V_11 -> V_15 = V_172 ;
V_9 -> V_173 += sizeof( struct V_36 ) ;
V_11 -> V_17 . V_18 = sizeof( struct V_36 ) ;
V_11 -> V_17 . V_174 = F_35 ;
V_11 -> V_175 = F_53 ;
} else {
V_11 -> V_15 = V_16 ;
V_9 -> V_173 += sizeof( struct V_46 ) ;
V_11 -> V_17 . V_18 = sizeof( struct V_46 ) ;
V_11 -> V_17 . V_174 = F_38 ;
V_11 -> V_175 = F_58 ;
}
V_29 = F_63 ( V_9 ) ;
if ( V_29 )
goto V_176;
V_29 = V_11 -> V_175 ( V_9 ) ;
if ( V_29 )
goto V_177;
F_69 ( V_9 ) ;
V_29 = F_80 ( V_9 ) ;
F_70 ( V_9 ) ;
if ( V_29 )
goto V_177;
V_29 = F_81 ( V_9 , & V_30 -> V_9 ) ;
if ( V_29 )
goto V_177;
return 0 ;
V_177:
F_68 ( V_11 -> V_78 ) ;
V_176:
F_82 ( V_9 ) ;
F_75 ( V_66 , NULL ) ;
F_83 ( V_30 ) ;
return V_29 ;
}
static void T_6 F_84 ( struct V_156 * V_66 )
{
struct V_8 * V_9 = F_18 ( V_66 ) ;
struct V_10 * V_11 ;
if ( ! V_9 )
return;
F_85 ( V_9 ) ;
V_11 = V_9 -> V_11 ;
F_83 ( F_72 ( V_66 ) ) ;
F_68 ( V_11 -> V_78 ) ;
F_82 ( V_9 ) ;
}
static int F_86 ( struct V_156 * V_66 )
{
struct V_8 * V_9 = F_18 ( V_66 ) ;
if ( ! V_9 )
return - V_178 ;
F_70 ( V_9 ) ;
return 0 ;
}
static int F_87 ( struct V_156 * V_66 )
{
struct V_8 * V_9 = F_18 ( V_66 ) ;
struct V_10 * V_11 ;
if ( ! V_9 )
return - V_178 ;
V_11 = V_9 -> V_11 ;
if ( F_3 ( ! ( V_11 -> V_175 && V_11 -> V_78 ) ) )
return 0 ;
return V_11 -> V_175 ( V_9 ) ;
}
static int F_88 ( struct V_156 * V_66 )
{
struct V_8 * V_9 = F_18 ( V_66 ) ;
struct V_10 * V_11 ;
int V_29 ;
V_29 = F_87 ( V_66 ) ;
if ( V_29 )
return V_29 ;
V_11 = V_9 -> V_11 ;
if ( V_11 -> V_17 . V_179 != V_180 )
F_89 ( V_9 ) ;
return 0 ;
}
static int F_90 ( struct V_156 * V_66 , T_7 V_181 )
{
return F_86 ( V_66 ) ;
}
static int T_8 F_91 ( void )
{
return F_92 ( & V_182 ) ;
}
static void T_9 F_93 ( void )
{
F_94 ( & V_182 ) ;
}
