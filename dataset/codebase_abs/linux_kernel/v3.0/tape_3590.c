static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( F_3 ( V_2 ) ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return F_5 ( F_3 ( V_2 ) ) ;
}
static void F_6 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
if ( V_4 -> type == V_8 )
V_6 -> V_9 |= 0x40 ;
if ( V_4 -> V_10 == V_8 )
V_6 -> V_9 |= 0x80 ;
strncpy ( V_6 -> V_11 , V_4 -> V_11 , 64 ) ;
for ( V_7 = strlen ( V_4 -> V_11 ) ; V_7 < sizeof( V_6 -> V_11 ) ; V_7 ++ )
V_6 -> V_11 [ V_7 ] = ' ' ;
F_7 ( V_6 -> V_11 , sizeof( V_6 -> V_11 ) ) ;
}
static void F_8 ( struct V_5 * V_4 ,
struct V_3 * V_6 )
{
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
if( V_4 -> V_9 & 0x40 )
V_6 -> type = V_8 ;
else
V_6 -> type = V_12 ;
if( V_4 -> V_9 & 0x80 )
V_6 -> V_10 = V_8 ;
else
V_6 -> V_10 = V_12 ;
memcpy ( V_6 -> V_11 , V_4 -> V_11 , sizeof( V_4 -> V_11 ) ) ;
F_9 ( V_6 -> V_11 , sizeof( V_4 -> V_11 ) ) ;
F_10 ( V_6 -> V_11 ) ;
}
static void F_11 ( struct V_13 * V_4 ,
struct V_14 * V_6 )
{
if ( V_4 -> V_15 == 0 ) {
V_6 -> V_16 [ 0 ] . type = V_17 ;
V_6 -> V_16 [ 0 ] . V_10 = V_17 ;
V_6 -> V_16 [ 1 ] . type = V_17 ;
V_6 -> V_16 [ 1 ] . V_10 = V_17 ;
} else if ( V_4 -> V_15 == 1 ) {
F_8 ( & V_4 -> V_16 [ 0 ] , & V_6 -> V_16 [ 0 ] ) ;
V_6 -> V_16 [ 1 ] . type = V_17 ;
V_6 -> V_16 [ 1 ] . V_10 = V_17 ;
} else if ( V_4 -> V_15 == 2 ) {
F_8 ( & V_4 -> V_16 [ 0 ] , & V_6 -> V_16 [ 0 ] ) ;
F_8 ( & V_4 -> V_16 [ 1 ] , & V_6 -> V_16 [ 1 ] ) ;
} else {
F_12 ( L_1 , V_4 -> V_15 ) ;
F_13 () ;
}
}
static int F_14 ( struct V_3 * V_16 )
{
if ( V_16 -> type == V_17 )
goto V_18;
if ( V_16 -> type > V_8 )
goto V_18;
if ( V_16 -> V_10 == V_17 )
goto V_18;
if ( V_16 -> V_10 > V_8 )
goto V_18;
if ( ( V_16 -> type == V_8 ) &&
( V_16 -> V_10 == V_12 ) )
goto V_18;
return 0 ;
V_18:
return - V_19 ;
}
static int F_15 ( struct V_14 * V_20 )
{
if ( F_14 ( & V_20 -> V_16 [ 0 ] ) )
goto V_18;
if ( F_14 ( & V_20 -> V_16 [ 1 ] ) )
goto V_18;
return 0 ;
V_18:
return - V_19 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_14 * V_21 )
{
struct V_22 * V_23 ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
int V_28 ;
F_17 ( 6 , L_2 ) ;
V_27 = F_18 ( sizeof( * V_27 ) , V_29 | V_30 ) ;
if ( ! V_27 )
return - V_31 ;
V_23 = F_19 ( 2 , sizeof( * V_25 ) ) ;
if ( F_20 ( V_23 ) ) {
V_28 = F_21 ( V_23 ) ;
goto V_32;
}
V_25 = V_23 -> V_33 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_34 = 0xe2 ;
V_25 -> V_35 = 2 ;
V_23 -> V_36 = V_37 ;
F_22 ( V_23 -> V_38 , V_39 , sizeof( * V_25 ) , V_25 ) ;
F_23 ( V_23 -> V_38 + 1 , V_40 , sizeof( * V_27 ) ,
V_27 ) ;
V_28 = F_24 ( V_2 , V_23 ) ;
if ( V_28 )
goto V_41;
F_11 ( & V_27 -> V_20 , V_21 ) ;
V_28 = 0 ;
V_41:
F_25 ( V_23 ) ;
V_32:
F_26 ( V_27 ) ;
return V_28 ;
}
static int F_27 ( struct V_1 * V_2 ,
unsigned long V_42 )
{
int V_28 ;
struct V_14 * V_21 ;
F_17 ( 6 , L_3 ) ;
if ( ! F_1 ( V_2 ) )
return - V_43 ;
if ( ! F_4 ( V_2 ) )
return - V_44 ;
V_21 = F_18 ( sizeof( * V_21 ) , V_29 ) ;
if ( ! V_21 )
return - V_31 ;
V_28 = F_16 ( V_2 , V_21 ) ;
if ( V_28 != 0 )
goto V_45;
if ( F_28 ( ( char V_46 * ) V_42 , V_21 , sizeof( * V_21 ) ) ) {
V_28 = - V_47 ;
goto V_45;
}
V_28 = 0 ;
V_45:
F_26 ( V_21 ) ;
return V_28 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_14 * V_21 )
{
struct V_22 * V_23 ;
struct V_48 * V_25 ;
F_17 ( 6 , L_4 ) ;
if ( F_15 ( V_21 ) ) {
F_17 ( 6 , L_5 ) ;
return - V_19 ;
}
if ( F_30 ( V_2 , 0 ) != 0 )
return - V_49 ;
V_23 = F_19 ( 1 , sizeof( * V_25 ) ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_25 = V_23 -> V_33 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_25 -> V_34 = 0xe3 ;
V_25 -> V_20 . V_15 = 2 ;
F_6 ( & V_21 -> V_16 [ 0 ] , & V_25 -> V_20 . V_16 [ 0 ] ) ;
F_6 ( & V_21 -> V_16 [ 1 ] , & V_25 -> V_20 . V_16 [ 1 ] ) ;
V_23 -> V_36 = V_50 ;
F_23 ( V_23 -> V_38 , V_39 , sizeof( * V_25 ) , V_25 ) ;
return F_31 ( V_2 , V_23 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
unsigned long V_42 )
{
int V_28 ;
struct V_14 * V_21 ;
F_17 ( 6 , L_6 ) ;
if ( ! F_1 ( V_2 ) )
return - V_43 ;
if ( ! F_4 ( V_2 ) )
return - V_44 ;
V_21 = F_18 ( sizeof( * V_21 ) , V_29 ) ;
if ( ! V_21 )
return - V_31 ;
if ( F_33 ( V_21 , ( char V_46 * ) V_42 , sizeof( * V_21 ) ) ) {
V_28 = - V_47 ;
goto V_6;
}
V_28 = F_29 ( V_2 , V_21 ) ;
V_6:
F_26 ( V_21 ) ;
return V_28 ;
}
static struct V_22 * F_34 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
char * V_51 ;
F_17 ( 6 , L_7 ) ;
if ( ! F_1 ( V_2 ) )
return F_35 ( - V_43 ) ;
V_23 = F_19 ( 2 , 72 ) ;
if ( F_20 ( V_23 ) )
return V_23 ;
V_51 = V_23 -> V_33 ;
memset ( V_51 , 0 , 72 ) ;
V_51 [ 0 ] = 0x05 ;
V_51 [ 36 + 0 ] = 0x03 ;
V_51 [ 36 + 1 ] = 0x03 ;
V_51 [ 36 + 4 ] = 0x40 ;
V_51 [ 36 + 6 ] = 0x01 ;
V_51 [ 36 + 14 ] = 0x2f ;
V_51 [ 36 + 18 ] = 0xc3 ;
V_51 [ 36 + 35 ] = 0x72 ;
V_23 -> V_36 = V_52 ;
F_22 ( V_23 -> V_38 , V_53 , 36 , V_51 ) ;
F_23 ( V_23 -> V_38 + 1 , V_53 , 36 , V_51 + 36 ) ;
return V_23 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_34 ( V_2 ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
return F_31 ( V_2 , V_23 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_34 ( V_2 ) ;
if ( ! F_20 ( V_23 ) )
F_38 ( V_2 , V_23 ) ;
}
static struct V_22 * F_39 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
char * V_51 ;
F_17 ( 6 , L_8 ) ;
if ( ! F_1 ( V_2 ) )
return F_35 ( - V_43 ) ;
V_23 = F_19 ( 2 , 72 ) ;
if ( F_20 ( V_23 ) )
return V_23 ;
V_51 = V_23 -> V_33 ;
memset ( V_51 , 0 , 72 ) ;
V_51 [ 0 ] = 0x05 ;
V_51 [ 36 + 0 ] = 0x03 ;
V_51 [ 36 + 1 ] = 0x03 ;
V_51 [ 36 + 35 ] = 0x32 ;
V_23 -> V_36 = V_54 ;
F_22 ( V_23 -> V_38 , V_53 , 36 , V_51 ) ;
F_23 ( V_23 -> V_38 + 1 , V_53 , 36 , V_51 + 36 ) ;
return V_23 ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_39 ( V_2 ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
return F_31 ( V_2 , V_23 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_39 ( V_2 ) ;
if ( ! F_20 ( V_23 ) )
F_38 ( V_2 , V_23 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned long V_42 )
{
struct V_55 V_56 ;
F_17 ( 6 , L_9 ) ;
if ( ! F_1 ( V_2 ) )
return - V_43 ;
if ( F_33 ( & V_56 , ( char V_46 * ) V_42 , sizeof( V_56 ) ) )
return - V_47 ;
if ( V_56 . V_57 & ~ V_58 )
return - V_19 ;
if ( V_56 . V_57 & V_58 )
return F_36 ( V_2 ) ;
else
return F_40 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
unsigned long V_42 )
{
F_17 ( 6 , L_10 ) ;
if ( ! F_1 ( V_2 ) )
return - V_43 ;
F_44 ( V_2 ) ;
if ( F_28 ( ( char V_46 * ) V_42 , & F_3 ( V_2 ) ,
sizeof( F_3 ( V_2 ) ) ) )
return - V_47 ;
else
return 0 ;
}
static int
F_45 ( struct V_1 * V_2 , unsigned int V_59 , unsigned long V_42 )
{
switch ( V_59 ) {
case V_60 : {
struct V_61 V_62 ;
if ( F_33 ( & V_62 , ( char V_46 * ) V_42 , sizeof( V_62 ) ) )
return - V_47 ;
return F_46 ( V_2 , & V_62 ) ;
}
case V_63 :
return F_32 ( V_2 , V_42 ) ;
case V_64 :
return F_27 ( V_2 , V_42 ) ;
case V_65 :
return F_42 ( V_2 , V_42 ) ;
case V_66 :
return F_43 ( V_2 , V_42 ) ;
default:
return - V_19 ;
}
}
static int F_44 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_19 ( 1 , 128 ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_23 -> V_36 = V_67 ;
F_23 ( V_23 -> V_38 , V_68 , 128 , V_23 -> V_33 ) ;
return F_31 ( V_2 , V_23 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_19 ( 1 , 128 ) ;
if ( F_20 ( V_23 ) )
return;
V_23 -> V_36 = V_67 ;
F_23 ( V_23 -> V_38 , V_68 , 128 , V_23 -> V_33 ) ;
F_38 ( V_2 , V_23 ) ;
}
static int
F_30 ( struct V_1 * V_2 , int V_69 )
{
T_1 V_70 ;
int V_28 ;
V_28 = F_48 ( V_2 , & V_70 ) ;
if ( V_28 )
return V_28 ;
return V_70 >> 32 ;
}
static int
F_49 ( struct V_1 * V_2 , int V_15 )
{
struct V_22 * V_23 ;
F_17 ( 6 , L_11 , V_15 ) ;
V_23 = F_19 ( 3 , 4 ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_23 -> V_36 = V_71 ;
F_22 ( V_23 -> V_38 , V_72 , 1 , V_2 -> V_73 ) ;
* ( V_74 * ) V_23 -> V_33 = V_15 ;
F_22 ( V_23 -> V_38 + 1 , V_75 , 4 , V_23 -> V_33 ) ;
F_23 ( V_23 -> V_38 + 2 , V_76 , 0 , NULL ) ;
return F_31 ( V_2 , V_23 ) ;
}
static void
F_50 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_77 * V_51 ;
V_23 -> V_36 = V_78 ;
F_22 ( V_23 -> V_38 , V_72 , 1 , V_2 -> V_73 ) ;
V_51 = V_2 -> V_79 ;
F_51 ( V_23 -> V_38 + 1 , V_51 -> V_80 ,
V_2 -> V_81 . V_82 ) ;
F_22 ( V_23 -> V_38 + 2 , V_83 , 0 , NULL ) ;
F_23 ( V_23 -> V_38 + 3 , V_76 , 0 , NULL ) ;
F_17 ( 6 , L_12 ) ;
}
static void F_52 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
char * V_84 ;
V_23 = F_19 ( 3 , 4096 ) ;
if ( F_20 ( V_23 ) )
return;
V_23 -> V_36 = V_85 ;
V_84 = V_23 -> V_33 ;
V_84 [ 0 ] = V_86 ;
V_84 [ 6 ] = V_87 ;
F_22 ( V_23 -> V_38 , V_88 , 12 , V_84 ) ;
F_22 ( V_23 -> V_38 + 1 , V_40 , 4096 - 12 , V_84 + 12 ) ;
F_23 ( V_23 -> V_38 + 2 , V_76 , 0 , NULL ) ;
F_38 ( V_2 , V_23 ) ;
}
static void
F_53 ( struct V_89 * V_90 )
{
struct V_91 * V_92 =
F_54 ( V_90 , struct V_91 , V_90 ) ;
switch ( V_92 -> V_36 ) {
case V_67 :
F_47 ( V_92 -> V_2 ) ;
break;
case V_85 :
F_52 ( V_92 -> V_2 ) ;
break;
case V_52 :
F_37 ( V_92 -> V_2 ) ;
break;
case V_54 :
F_41 ( V_92 -> V_2 ) ;
break;
default:
F_17 ( 3 , L_13
L_14 , V_92 -> V_36 ) ;
}
F_55 ( V_92 -> V_2 ) ;
F_26 ( V_92 ) ;
}
static int
F_56 ( struct V_1 * V_2 , enum V_93 V_36 )
{
struct V_91 * V_92 ;
if ( ( V_92 = F_57 ( sizeof( * V_92 ) , V_94 ) ) == NULL )
return - V_31 ;
F_58 ( & V_92 -> V_90 , F_53 ) ;
V_92 -> V_2 = F_59 ( V_2 ) ;
V_92 -> V_36 = V_36 ;
F_60 ( V_95 , & V_92 -> V_90 ) ;
return 0 ;
}
static struct V_22 *
F_61 ( struct V_1 * V_2 , struct V_23 * V_96 )
{
struct V_22 * V_23 ;
struct V_97 * V_98 ;
int V_15 = 0 , V_99 ;
unsigned V_100 ;
char * V_101 ;
struct V_102 * V_103 ;
struct V_104 V_105 ;
F_17 ( 6 , L_15 ) ;
V_99 = F_62 ( V_96 ) >> V_106 ;
F_17 ( 6 , L_16 , V_99 ) ;
F_63 (bv, req, iter)
V_15 += V_103 -> V_107 >> ( V_106 + 9 ) ;
V_23 = F_19 ( 2 + V_15 + 1 , 4 ) ;
if ( F_20 ( V_23 ) )
return V_23 ;
V_23 -> V_36 = V_108 ;
* ( V_74 * ) V_23 -> V_33 = V_99 ;
V_98 = V_23 -> V_38 ;
V_98 = F_22 ( V_98 , V_72 , 1 , V_2 -> V_73 ) ;
V_98 = F_22 ( V_98 , V_76 , 0 , NULL ) ;
F_63 (bv, req, iter) {
V_101 = F_64 ( V_103 -> V_109 ) + V_103 -> V_110 ;
for ( V_100 = 0 ; V_100 < V_103 -> V_107 ; V_100 += V_111 ) {
V_98 -> V_9 = V_112 ;
V_98 -> V_113 = V_114 ;
V_98 -> V_15 = V_111 ;
F_65 ( V_98 , ( void * ) F_66 ( V_101 ) ) ;
V_98 ++ ;
V_101 += V_111 ;
}
F_67 ( V_100 > V_103 -> V_107 ) ;
}
V_98 = F_23 ( V_98 , V_76 , 0 , NULL ) ;
F_17 ( 6 , L_17 ) ;
return V_23 ;
}
static void
F_68 ( struct V_22 * V_23 )
{
struct V_97 * V_98 ;
for ( V_98 = V_23 -> V_38 ; V_98 -> V_9 & V_112 ; V_98 ++ )
if ( V_98 -> V_113 == V_114 )
F_69 ( V_98 ) ;
F_25 ( V_23 ) ;
}
static void
F_70 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
V_74 * V_99 ;
V_99 = ( V_74 * ) V_23 -> V_33 ;
if ( * V_99 != V_2 -> V_115 . V_116 ) {
* V_99 += V_2 -> V_117 ;
F_22 ( V_23 -> V_38 + 1 , V_75 , 4 , V_23 -> V_33 ) ;
}
}
static void F_71 ( struct V_1 * V_2 ,
struct V_118 * V_119 )
{
struct V_55 * V_120 ;
V_120 = & F_3 ( V_2 ) ;
F_17 ( 6 , L_18 , V_119 -> V_121 , V_119 -> V_122 ) ;
switch ( V_119 -> V_121 ) {
case 0x04 :
case 0x05 :
case 0x06 :
F_72 ( V_2 , V_123 ) ;
F_3 ( V_2 ) . V_124 = 0 ;
return;
case 0x08 :
case 0x09 :
F_72 ( V_2 , V_125 ) ;
break;
default:
F_72 ( V_2 , V_126 ) ;
return;
}
V_120 -> V_124 |= V_127 ;
if ( V_119 -> V_9 & V_128 ) {
F_17 ( 6 , L_19 , V_119 -> V_9 ) ;
V_120 -> V_124 |= V_129 ;
} else {
F_17 ( 6 , L_20 , V_119 -> V_9 ) ;
V_120 -> V_124 &= ~ V_129 ;
}
}
static int
F_73 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_17 ( 6 , L_21 , V_130 [ V_23 -> V_36 ] ) ;
switch ( V_23 -> V_36 ) {
case V_131 :
case V_132 :
case V_133 :
case V_134 :
case V_135 :
case V_71 :
case V_136 :
case V_78 :
case V_137 :
case V_138 :
case V_139 :
case V_108 :
case V_140 :
F_72 ( V_2 , V_125 ) ;
break;
case V_141 :
F_72 ( V_2 , V_123 ) ;
F_56 ( V_2 , V_54 ) ;
break;
case V_67 :
F_71 ( V_2 , V_23 -> V_33 ) ;
break;
case V_52 :
F_3 ( V_2 ) . V_57
|= V_58 ;
* ( V_2 -> V_73 ) |= 0x03 ;
break;
case V_54 :
F_3 ( V_2 ) . V_57
&= ~ V_58 ;
* ( V_2 -> V_73 ) &= ~ 0x03 ;
break;
case V_142 :
case V_143 :
case V_144 :
case V_85 :
case V_145 :
case V_146 :
case V_147 :
case V_148 :
case V_50 :
case V_37 :
case V_149 :
break;
}
return V_150 ;
}
static inline int
F_74 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_17 ( 3 , L_22 ,
V_130 [ V_23 -> V_36 ] ) ;
return F_73 ( V_2 , V_23 ) ;
}
static inline int
F_75 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_151 * V_151 , int V_28 )
{
F_17 ( 3 , L_23 ,
V_130 [ V_23 -> V_36 ] ) ;
F_76 ( V_2 , V_23 , V_151 ) ;
return V_28 ;
}
static inline int
F_77 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_151 * V_151 )
{
F_17 ( 2 , L_24 , V_130 [ V_23 -> V_36 ] ) ;
F_76 ( V_2 , V_23 , V_151 ) ;
return V_152 ;
}
static int
F_78 ( struct V_1 * V_2 , struct V_151 * V_151 )
{
if ( V_151 -> V_153 . V_59 . V_154 == V_155 )
return V_156 ;
else if ( V_151 -> V_153 . V_59 . V_154 == 0x85 )
F_17 ( 3 , L_25 , V_2 -> V_157 ) ;
else if ( V_151 -> V_153 . V_59 . V_154 & V_158 ) {
F_56 ( V_2 , V_85 ) ;
} else {
F_17 ( 3 , L_26 , V_2 -> V_157 ) ;
F_76 ( V_2 , NULL , V_151 ) ;
}
F_56 ( V_2 , V_67 ) ;
return V_150 ;
}
static int
F_79 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_151 * V_151 , int V_28 )
{
struct V_159 * V_119 ;
V_119 = (struct V_159 * ) V_151 -> V_160 ;
switch ( V_119 -> V_161 ) {
case V_162 :
return F_75 ( V_2 , V_23 , V_151 , V_28 ) ;
case V_163 :
return F_74 ( V_2 , V_23 ) ;
case V_164 :
return F_77 ( V_2 , V_23 , V_151 ) ;
case V_165 :
return F_75 ( V_2 , V_23 , V_151 , V_28 ) ;
default:
F_13 () ;
return V_166 ;
}
}
static int
F_80 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_151 * V_151 )
{
return F_79 ( V_2 , V_23 , V_151 , - V_167 ) ;
}
static int
F_81 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_151 * V_151 )
{
F_82 ( & V_2 -> V_168 -> V_169 , L_27
L_28 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_167 ) ;
}
static int
F_83 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_151 * V_151 )
{
F_17 ( 6 , L_29 ) ;
return V_170 ;
}
static int
F_84 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_151 * V_151 )
{
return F_79 ( V_2 , V_23 , V_151 , - V_167 ) ;
}
static int
F_85 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_151 * V_151 )
{
struct V_77 * V_51 ;
V_51 = V_2 -> V_79 ;
if ( V_51 -> V_80 == V_171 ) {
F_17 ( 2 , L_30 ,
V_2 -> V_157 ) ;
V_51 -> V_80 = V_172 ;
} else {
F_17 ( 2 , L_31 ,
V_2 -> V_157 ) ;
V_51 -> V_80 = V_171 ;
}
F_50 ( V_2 , V_23 ) ;
return F_77 ( V_2 , V_23 , V_151 ) ;
}
static int
F_86 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_151 * V_151 )
{
switch ( V_23 -> V_36 ) {
case V_136 :
F_50 ( V_2 , V_23 ) ;
return F_77 ( V_2 , V_23 , V_151 ) ;
case V_78 :
return F_75 ( V_2 , V_23 , V_151 , - V_167 ) ;
break;
default:
return F_75 ( V_2 , V_23 , V_151 , - V_167 ) ;
}
}
static void
F_87 ( struct V_1 * V_2 , struct V_151 * V_151 )
{
struct V_159 * V_119 ;
char * V_173 , * V_174 ;
V_173 = F_18 ( V_175 , V_94 ) ;
V_174 = F_18 ( V_175 , V_94 ) ;
if ( ! V_173 || ! V_174 )
goto V_176;
V_119 = (struct V_159 * ) V_151 -> V_160 ;
switch ( V_119 -> V_177 . V_178 . V_179 ) {
case 0x02 :
snprintf ( V_173 , V_175 , L_32 ) ;
break;
case 0x03 :
snprintf ( V_173 , V_175 , L_33 ,
V_119 -> V_177 . V_178 . V_180 ) ;
break;
case 0x04 :
snprintf ( V_173 , V_175 , L_34 ) ;
break;
case 0x05 :
snprintf ( V_173 , V_175 , L_35 ,
V_119 -> V_177 . V_178 . V_180 ) ;
break;
case 0x06 :
snprintf ( V_173 , V_175 , L_36 ) ;
break;
case 0x07 :
snprintf ( V_173 , V_175 , L_37 ,
V_119 -> V_177 . V_178 . V_181 ) ;
break;
default:
snprintf ( V_173 , V_175 , L_38 ,
V_119 -> V_177 . V_178 . V_179 ) ;
break;
}
switch ( V_119 -> V_177 . V_178 . V_182 ) {
case 0x02 :
snprintf ( V_174 , V_175 , L_39
L_40 , V_119 -> V_177 . V_178 . V_181 ) ;
break;
default:
snprintf ( V_174 , V_175 , L_38 ,
V_119 -> V_177 . V_178 . V_182 ) ;
break;
}
F_82 ( & V_2 -> V_168 -> V_169 , L_41
L_42 , V_173 , V_174 ) ;
V_176:
F_26 ( V_173 ) ;
F_26 ( V_174 ) ;
}
static void
F_88 ( struct V_1 * V_2 , struct V_151 * V_151 )
{
struct V_159 * V_119 ;
char * V_173 , * V_174 ;
V_173 = F_18 ( V_175 , V_94 ) ;
V_174 = F_18 ( V_175 , V_94 ) ;
if ( ! V_173 || ! V_174 )
goto V_176;
V_119 = (struct V_159 * ) V_151 -> V_160 ;
switch ( V_119 -> V_177 . V_183 . V_179 ) {
case 0x01 :
snprintf ( V_173 , V_175 , L_43 ) ;
break;
case 0x02 :
snprintf ( V_173 , V_175 , L_44
L_45 ) ;
break;
case 0x03 :
snprintf ( V_173 , V_175 , L_46
L_47 , V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x04 :
snprintf ( V_173 , V_175 , L_48
L_38 , V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x05 :
snprintf ( V_173 , V_175 , L_49
L_38 , V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x06 :
snprintf ( V_173 , V_175 , L_50 ,
V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x07 :
snprintf ( V_173 , V_175 , L_51
L_38 , V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
default:
snprintf ( V_173 , V_175 , L_38 ,
V_119 -> V_177 . V_183 . V_179 ) ;
}
switch ( V_119 -> V_177 . V_183 . V_182 ) {
case 0x01 :
snprintf ( V_174 , V_175 , L_52 ) ;
break;
case 0x02 :
snprintf ( V_174 , V_175 , L_53
L_54 ) ;
break;
case 0x03 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_55
L_56 , V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_57
L_58 , V_119 -> V_177 . V_183 . V_181 [ 1 ] ,
V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x04 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_57
L_59 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_60
L_61 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x05 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_62
L_63 , V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_62
L_61 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x06 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_57
L_64 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_57
L_65 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x07 :
snprintf ( V_174 , V_175 , L_66 ) ;
break;
default:
snprintf ( V_174 , V_175 , L_38 ,
V_119 -> V_177 . V_183 . V_182 ) ;
}
F_82 ( & V_2 -> V_168 -> V_169 , L_67
L_68 , V_173 , V_174 ) ;
V_176:
F_26 ( V_173 ) ;
F_26 ( V_174 ) ;
}
static void
F_89 ( struct V_1 * V_2 , struct V_151 * V_151 )
{
struct V_159 * V_119 ;
char * V_173 , * V_174 ;
V_173 = F_18 ( V_175 , V_94 ) ;
V_174 = F_18 ( V_175 , V_94 ) ;
if ( ! V_173 || ! V_174 )
goto V_176;
V_119 = (struct V_159 * ) V_151 -> V_160 ;
switch ( V_119 -> V_177 . V_183 . V_179 ) {
case 0x01 :
snprintf ( V_173 , V_175 , L_43 ) ;
break;
case 0x02 :
snprintf ( V_173 , V_175 , L_69
L_70 ) ;
break;
case 0x03 :
snprintf ( V_173 , V_175 , L_71
L_47 , V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x04 :
snprintf ( V_173 , V_175 , L_72 ,
V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x05 :
snprintf ( V_173 , V_175 , L_73
L_74 , V_119 -> V_177 . V_183 . V_181 [ 0 ] ) ;
break;
case 0x06 :
snprintf ( V_173 , V_175 , L_75 ) ;
break;
case 0x07 :
snprintf ( V_173 , V_175 , L_76 ) ;
break;
default:
snprintf ( V_173 , V_175 , L_38 ,
V_119 -> V_177 . V_183 . V_179 ) ;
}
switch ( V_119 -> V_177 . V_183 . V_182 ) {
case 0x01 :
snprintf ( V_174 , V_175 , L_52 ) ;
break;
case 0x02 :
snprintf ( V_174 , V_175 , L_77
L_54 ) ;
break;
case 0x03 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_57
L_78 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_57
L_79 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x04 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_57
L_80 , V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_57
L_81 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x05 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_82
L_83 , V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_82
L_84 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x07 :
snprintf ( V_174 , V_175 , L_85 ) ;
break;
case 0x08 :
if ( V_119 -> V_177 . V_183 . V_184 == 0 )
snprintf ( V_174 , V_175 , L_57
L_86 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] ) ;
else
snprintf ( V_174 , V_175 , L_57
L_87 ,
V_119 -> V_177 . V_183 . V_181 [ 1 ] , V_119 -> V_177 . V_183 . V_181 [ 2 ] ) ;
break;
case 0x09 :
snprintf ( V_174 , V_175 , L_88 ) ;
break;
default:
snprintf ( V_174 , V_175 , L_38 ,
V_119 -> V_177 . V_183 . V_182 ) ;
}
F_82 ( & V_2 -> V_168 -> V_169 , L_89
L_68 , V_173 , V_174 ) ;
V_176:
F_26 ( V_173 ) ;
F_26 ( V_174 ) ;
}
static void
F_90 ( struct V_1 * V_2 , struct V_151 * V_151 )
{
struct V_159 * V_119 ;
V_119 = (struct V_159 * ) V_151 -> V_160 ;
if ( V_119 -> V_185 == 0 )
return;
if ( ( V_119 -> V_185 > 0 ) && ( V_119 -> V_185 < V_186 ) ) {
if ( V_187 [ V_119 -> V_185 ] != NULL )
F_82 ( & V_2 -> V_168 -> V_169 , L_90
L_91 ,
V_187 [ V_119 -> V_185 ] ) ;
else
F_82 ( & V_2 -> V_168 -> V_169 , L_90
L_92 ,
V_119 -> V_185 ) ;
return;
}
if ( V_119 -> V_185 == 0xf0 ) {
F_82 ( & V_2 -> V_168 -> V_169 , L_93
L_94 , V_119 -> V_177 . V_178 . V_188 , V_119 -> V_185 ,
V_119 -> V_177 . V_178 . V_179 , V_119 -> V_177 . V_178 . V_182 ,
V_119 -> V_177 . V_178 . V_189 , V_119 -> V_177 . V_178 . V_190 ,
V_119 -> V_177 . V_178 . V_191 ) ;
F_87 ( V_2 , V_151 ) ;
return;
}
if ( V_119 -> V_185 == 0xf1 ) {
F_82 ( & V_2 -> V_168 -> V_169 , L_95
L_96 ,
V_119 -> V_177 . V_183 . V_188 , V_2 -> V_168 -> V_192 . V_193 ,
V_119 -> V_185 , V_119 -> V_177 . V_183 . V_179 , V_119 -> V_177 . V_183 . V_182 ,
V_119 -> V_177 . V_183 . V_194 , V_119 -> V_177 . V_183 . V_195 ,
V_119 -> V_177 . V_183 . V_196 ) ;
F_88 ( V_2 , V_151 ) ;
return;
}
if ( V_119 -> V_185 == 0xf2 ) {
F_82 ( & V_2 -> V_168 -> V_169 , L_97
L_98 ,
V_119 -> V_177 . V_183 . V_188 , V_2 -> V_168 -> V_192 . V_193 ,
V_119 -> V_185 , V_119 -> V_177 . V_183 . V_179 , V_119 -> V_177 . V_183 . V_182 ,
V_119 -> V_177 . V_183 . V_194 , V_119 -> V_177 . V_183 . V_195 ,
V_119 -> V_177 . V_183 . V_196 ) ;
F_89 ( V_2 , V_151 ) ;
return;
}
if ( V_119 -> V_185 == 0xf3 ) {
return;
}
F_82 ( & V_2 -> V_168 -> V_169 , L_99
L_100 , V_119 -> V_185 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_151 * V_151 )
{
T_2 V_197 ;
T_3 V_198 ;
char * V_119 ;
V_119 = ( (struct V_159 * ) V_151 -> V_160 ) -> V_177 . V_51 ;
V_197 = V_119 [ 0 ] ;
V_198 = * ( ( T_3 * ) & V_119 [ 10 ] ) ;
if ( ( V_197 == 0 ) && ( V_198 == 0xee31 ) )
return F_79 ( V_2 , V_23 , V_151 , - V_199 ) ;
if ( ( V_197 == 1 ) || ( V_197 == 2 ) )
return F_79 ( V_2 , V_23 , V_151 , - V_200 ) ;
F_92 ( & V_2 -> V_168 -> V_169 , L_101
L_102 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_201 ) ;
}
static int
F_93 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_151 * V_151 )
{
struct V_159 * V_119 ;
#ifdef F_94
if ( V_23 -> V_36 == V_108 ) {
V_2 -> V_115 . V_116 = - 1 ;
if ( V_23 -> V_202 -- <= 0 )
return F_75 ( V_2 , V_23 , V_151 , - V_167 ) ;
else
return F_77 ( V_2 , V_23 , V_151 ) ;
}
#endif
V_119 = (struct V_159 * ) V_151 -> V_160 ;
F_17 ( 6 , L_103 , V_119 -> V_203 ) ;
switch ( V_119 -> V_203 ) {
case 0x1110 :
F_90 ( V_2 , V_151 ) ;
return F_80 ( V_2 , V_23 , V_151 ) ;
case 0x2011 :
F_90 ( V_2 , V_151 ) ;
return F_85 ( V_2 , V_23 , V_151 ) ;
case 0x2230 :
case 0x2231 :
F_90 ( V_2 , V_151 ) ;
return F_84 ( V_2 , V_23 , V_151 ) ;
case 0x2240 :
return F_91 ( V_2 , V_23 , V_151 ) ;
case 0x3010 :
F_17 ( 2 , L_104 ,
V_2 -> V_157 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_204 ) ;
case 0x3012 :
F_17 ( 2 , L_105 ,
V_2 -> V_157 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_204 ) ;
case 0x3020 :
F_17 ( 2 , L_106 , V_2 -> V_157 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_204 ) ;
case 0x3122 :
F_17 ( 2 , L_107 ,
V_2 -> V_157 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_167 ) ;
case 0x3123 :
F_17 ( 2 , L_108 ,
V_2 -> V_157 ) ;
F_72 ( V_2 , V_123 ) ;
F_56 ( V_2 , V_54 ) ;
return F_79 ( V_2 , V_23 , V_151 , 0 ) ;
case 0x4010 :
F_72 ( V_2 , V_123 ) ;
F_56 ( V_2 , V_54 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_205 ) ;
case 0x4012 :
F_17 ( 6 , L_109 , V_2 -> V_157 ) ;
F_90 ( V_2 , V_151 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_206 ) ;
case 0x4014 :
F_17 ( 6 , L_110 , V_2 -> V_157 ) ;
return F_83 ( V_2 , V_23 , V_151 ) ;
case 0x5010 :
if ( V_119 -> V_207 == 0xd0 ) {
F_90 ( V_2 , V_151 ) ;
return F_81 ( V_2 , V_23 , V_151 ) ;
}
if ( V_119 -> V_207 == 0x26 ) {
F_90 ( V_2 , V_151 ) ;
return F_86 ( V_2 , V_23 ,
V_151 ) ;
}
return F_79 ( V_2 , V_23 , V_151 , - V_167 ) ;
case 0x5020 :
case 0x5021 :
case 0x5022 :
case 0x5040 :
case 0x5041 :
case 0x5042 :
F_90 ( V_2 , V_151 ) ;
return F_81 ( V_2 , V_23 , V_151 ) ;
case 0x5110 :
case 0x5111 :
return F_79 ( V_2 , V_23 , V_151 , - V_208 ) ;
case 0x5120 :
case 0x1120 :
F_72 ( V_2 , V_123 ) ;
F_56 ( V_2 , V_54 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_205 ) ;
case 0x6020 :
return F_79 ( V_2 , V_23 , V_151 , - V_208 ) ;
case 0x8011 :
return F_79 ( V_2 , V_23 , V_151 , - V_209 ) ;
case 0x8013 :
F_82 ( & V_2 -> V_168 -> V_169 , L_111
L_112 ) ;
return F_79 ( V_2 , V_23 , V_151 , - V_209 ) ;
default:
return F_79 ( V_2 , V_23 , V_151 , - V_167 ) ;
}
}
static int
F_95 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_151 * V_151 )
{
if ( V_23 == NULL )
return F_78 ( V_2 , V_151 ) ;
if ( ( V_151 -> V_153 . V_59 . V_154 & V_210 ) &&
( V_151 -> V_153 . V_59 . V_154 & V_211 ) &&
( V_23 -> V_36 == V_138 ) ) {
F_17 ( 2 , L_113 ) ;
return F_75 ( V_2 , V_23 , V_151 , - V_204 ) ;
}
if ( V_151 -> V_153 . V_59 . V_154 & V_212 )
return F_93 ( V_2 , V_23 , V_151 ) ;
if ( V_151 -> V_153 . V_59 . V_154 & V_211 ) {
if ( V_151 -> V_153 . V_59 . V_154 == V_210 ) {
if ( V_23 -> V_36 == V_134 || V_23 -> V_36 == V_131 )
V_23 -> V_213 ++ ;
else
F_17 ( 5 , L_114 ) ;
}
return F_73 ( V_2 , V_23 ) ;
}
if ( V_151 -> V_153 . V_59 . V_154 & V_155 ) {
F_17 ( 2 , L_115 ) ;
return V_156 ;
}
if ( V_151 -> V_153 . V_59 . V_154 & V_158 ) {
F_17 ( 2 , L_116 ) ;
return V_156 ;
}
F_17 ( 6 , L_117 ) ;
F_76 ( V_2 , V_23 , V_151 ) ;
return V_166 ;
}
static int F_96 ( struct V_1 * V_2 ,
struct V_214 * V_215 )
{
int V_28 ;
struct V_22 * V_23 ;
V_23 = F_19 ( 1 , sizeof( * V_215 ) ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_23 -> V_36 = V_149 ;
F_23 ( V_23 -> V_38 , V_216 , sizeof( * V_215 ) ,
V_23 -> V_33 ) ;
V_28 = F_24 ( V_2 , V_23 ) ;
if ( V_28 == 0 )
memcpy ( V_215 , V_23 -> V_33 , sizeof( * V_215 ) ) ;
F_25 ( V_23 ) ;
return V_28 ;
}
static int
F_97 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_77 * V_51 ;
struct V_214 * V_215 ;
F_17 ( 6 , L_118 ) ;
V_51 = F_57 ( sizeof( struct V_77 ) , V_29 | V_30 ) ;
if ( V_51 == NULL )
return - V_31 ;
V_51 -> V_80 = V_171 ;
V_2 -> V_79 = V_51 ;
V_215 = F_18 ( sizeof( * V_215 ) , V_29 | V_30 ) ;
if ( ! V_215 ) {
V_28 = - V_31 ;
goto V_217;
}
V_28 = F_96 ( V_2 , V_215 ) ;
if ( V_28 ) {
F_98 ( 3 , L_119 ) ;
goto V_218;
}
V_28 = F_99 ( V_2 ) ;
if ( V_28 )
goto V_218;
if ( V_215 -> V_51 [ 31 ] == 0x13 ) {
V_51 -> V_219 . V_220 |= V_221 ;
F_40 ( V_2 ) ;
} else {
F_17 ( 6 , L_120 ) ;
}
V_28 = F_44 ( V_2 ) ;
if ( V_28 ) {
F_98 ( 3 , L_121 , V_28 ) ;
goto V_218;
}
return 0 ;
V_218:
F_26 ( V_215 ) ;
V_217:
F_26 ( V_51 ) ;
return V_28 ;
}
static void
F_100 ( struct V_1 * V_2 )
{
F_101 ( V_95 ) ;
F_102 ( V_2 ) ;
F_26 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
}
static int
F_103 ( struct V_222 * V_168 )
{
return F_104 ( F_105 ( & V_168 -> V_169 ) ,
& V_223 ) ;
}
static int
F_106 ( void )
{
int V_28 ;
V_224 = F_107 ( L_122 , 2 , 2 , 4 * sizeof( long ) ) ;
F_108 ( V_224 , & V_225 ) ;
#ifdef F_109
F_110 ( V_224 , 6 ) ;
#endif
F_17 ( 3 , L_123 ) ;
V_95 = F_111 ( L_122 , 0 , 0 ) ;
if ( ! V_95 )
return - V_31 ;
V_28 = F_112 ( & V_226 ) ;
if ( V_28 ) {
F_113 ( V_95 ) ;
F_17 ( 3 , L_124 ) ;
} else
F_17 ( 3 , L_125 ) ;
return V_28 ;
}
static void
F_114 ( void )
{
F_115 ( & V_226 ) ;
F_113 ( V_95 ) ;
F_116 ( V_224 ) ;
}
