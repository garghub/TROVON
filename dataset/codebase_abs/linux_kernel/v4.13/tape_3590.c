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
V_21 = F_33 ( ( char V_46 * ) V_42 , sizeof( * V_21 ) ) ;
if ( F_20 ( V_21 ) )
return F_21 ( V_21 ) ;
V_28 = F_29 ( V_2 , V_21 ) ;
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
if ( F_43 ( & V_56 , ( char V_46 * ) V_42 , sizeof( V_56 ) ) )
return - V_47 ;
if ( V_56 . V_57 & ~ V_58 )
return - V_19 ;
if ( V_56 . V_57 & V_58 )
return F_36 ( V_2 ) ;
else
return F_40 ( V_2 ) ;
}
static int F_44 ( struct V_1 * V_2 ,
unsigned long V_42 )
{
F_17 ( 6 , L_10 ) ;
if ( ! F_1 ( V_2 ) )
return - V_43 ;
F_45 ( V_2 ) ;
if ( F_28 ( ( char V_46 * ) V_42 , & F_3 ( V_2 ) ,
sizeof( F_3 ( V_2 ) ) ) )
return - V_47 ;
else
return 0 ;
}
static int
F_46 ( struct V_1 * V_2 , unsigned int V_59 , unsigned long V_42 )
{
switch ( V_59 ) {
case V_60 : {
struct V_61 V_62 ;
if ( F_43 ( & V_62 , ( char V_46 * ) V_42 , sizeof( V_62 ) ) )
return - V_47 ;
return F_47 ( V_2 , & V_62 ) ;
}
case V_63 :
return F_32 ( V_2 , V_42 ) ;
case V_64 :
return F_27 ( V_2 , V_42 ) ;
case V_65 :
return F_42 ( V_2 , V_42 ) ;
case V_66 :
return F_44 ( V_2 , V_42 ) ;
default:
return - V_19 ;
}
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
V_23 = F_19 ( 1 , 128 ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_23 -> V_36 = V_67 ;
F_23 ( V_23 -> V_38 , V_68 , 128 , V_23 -> V_33 ) ;
return F_31 ( V_2 , V_23 ) ;
}
static void F_48 ( struct V_1 * V_2 )
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
V_28 = F_49 ( V_2 , & V_70 ) ;
if ( V_28 )
return V_28 ;
return V_70 >> 32 ;
}
static int
F_50 ( struct V_1 * V_2 , int V_15 )
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
F_51 ( struct V_1 * V_2 ,
struct V_22 * V_23 )
{
struct V_77 * V_51 ;
V_23 -> V_36 = V_78 ;
F_22 ( V_23 -> V_38 , V_72 , 1 , V_2 -> V_73 ) ;
V_51 = V_2 -> V_79 ;
F_52 ( V_23 -> V_38 + 1 , V_51 -> V_80 ,
V_2 -> V_81 . V_82 ) ;
F_22 ( V_23 -> V_38 + 2 , V_83 , 0 , NULL ) ;
F_23 ( V_23 -> V_38 + 3 , V_76 , 0 , NULL ) ;
F_17 ( 6 , L_12 ) ;
}
static void F_53 ( struct V_1 * V_2 )
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
F_54 ( struct V_89 * V_90 )
{
struct V_91 * V_92 =
F_55 ( V_90 , struct V_91 , V_90 ) ;
switch ( V_92 -> V_36 ) {
case V_67 :
F_48 ( V_92 -> V_2 ) ;
break;
case V_85 :
F_53 ( V_92 -> V_2 ) ;
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
F_56 ( V_92 -> V_2 ) ;
F_26 ( V_92 ) ;
}
static int
F_57 ( struct V_1 * V_2 , enum V_93 V_36 )
{
struct V_91 * V_92 ;
if ( ( V_92 = F_58 ( sizeof( * V_92 ) , V_94 ) ) == NULL )
return - V_31 ;
F_59 ( & V_92 -> V_90 , F_54 ) ;
V_92 -> V_2 = F_60 ( V_2 ) ;
V_92 -> V_36 = V_36 ;
F_61 ( V_95 , & V_92 -> V_90 ) ;
return 0 ;
}
static void F_62 ( struct V_1 * V_2 ,
struct V_96 * V_97 )
{
struct V_55 * V_98 ;
V_98 = & F_3 ( V_2 ) ;
F_17 ( 6 , L_15 , V_97 -> V_99 , V_97 -> V_100 ) ;
switch ( V_97 -> V_99 ) {
case 0x04 :
case 0x05 :
case 0x06 :
F_63 ( V_2 , V_101 ) ;
F_3 ( V_2 ) . V_102 = 0 ;
return;
case 0x08 :
case 0x09 :
F_63 ( V_2 , V_103 ) ;
break;
default:
F_63 ( V_2 , V_104 ) ;
return;
}
V_98 -> V_102 |= V_105 ;
if ( V_97 -> V_9 & V_106 ) {
F_17 ( 6 , L_16 , V_97 -> V_9 ) ;
V_98 -> V_102 |= V_107 ;
} else {
F_17 ( 6 , L_17 , V_97 -> V_9 ) ;
V_98 -> V_102 &= ~ V_107 ;
}
}
static int
F_64 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_17 ( 6 , L_18 , V_108 [ V_23 -> V_36 ] ) ;
switch ( V_23 -> V_36 ) {
case V_109 :
case V_110 :
case V_111 :
case V_112 :
case V_113 :
case V_71 :
case V_114 :
case V_78 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
F_63 ( V_2 , V_103 ) ;
break;
case V_120 :
F_63 ( V_2 , V_101 ) ;
F_57 ( V_2 , V_54 ) ;
break;
case V_67 :
F_62 ( V_2 , V_23 -> V_33 ) ;
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
case V_121 :
case V_122 :
case V_123 :
case V_85 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
case V_50 :
case V_37 :
case V_128 :
break;
}
return V_129 ;
}
static inline int
F_65 ( struct V_1 * V_2 , struct V_22 * V_23 )
{
F_17 ( 3 , L_19 ,
V_108 [ V_23 -> V_36 ] ) ;
return F_64 ( V_2 , V_23 ) ;
}
static inline int
F_66 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_130 * V_130 , int V_28 )
{
F_17 ( 3 , L_20 ,
V_108 [ V_23 -> V_36 ] ) ;
F_67 ( V_2 , V_23 , V_130 ) ;
return V_28 ;
}
static inline int
F_68 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_130 * V_130 )
{
F_17 ( 2 , L_21 , V_108 [ V_23 -> V_36 ] ) ;
F_67 ( V_2 , V_23 , V_130 ) ;
return V_131 ;
}
static int
F_69 ( struct V_1 * V_2 , struct V_130 * V_130 )
{
if ( V_130 -> V_132 . V_59 . V_133 == V_134 )
return V_135 ;
else if ( V_130 -> V_132 . V_59 . V_133 == 0x85 )
F_17 ( 3 , L_22 , V_2 -> V_136 ) ;
else if ( V_130 -> V_132 . V_59 . V_133 & V_137 ) {
F_57 ( V_2 , V_85 ) ;
} else {
F_17 ( 3 , L_23 , V_2 -> V_136 ) ;
F_67 ( V_2 , NULL , V_130 ) ;
}
F_57 ( V_2 , V_67 ) ;
return V_129 ;
}
static int
F_70 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_130 * V_130 , int V_28 )
{
struct V_138 * V_97 ;
V_97 = (struct V_138 * ) V_130 -> V_139 ;
switch ( V_97 -> V_140 ) {
case V_141 :
return F_66 ( V_2 , V_23 , V_130 , V_28 ) ;
case V_142 :
return F_65 ( V_2 , V_23 ) ;
case V_143 :
return F_68 ( V_2 , V_23 , V_130 ) ;
case V_144 :
return F_66 ( V_2 , V_23 , V_130 , V_28 ) ;
default:
F_13 () ;
return V_145 ;
}
}
static int
F_71 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_130 * V_130 )
{
return F_70 ( V_2 , V_23 , V_130 , - V_146 ) ;
}
static int
F_72 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_130 * V_130 )
{
F_73 ( & V_2 -> V_147 -> V_148 , L_24
L_25 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_146 ) ;
}
static int
F_74 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_130 * V_130 )
{
F_17 ( 6 , L_26 ) ;
return V_149 ;
}
static int
F_75 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_130 * V_130 )
{
return F_70 ( V_2 , V_23 , V_130 , - V_146 ) ;
}
static int
F_76 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_130 * V_130 )
{
struct V_77 * V_51 ;
V_51 = V_2 -> V_79 ;
if ( V_51 -> V_80 == V_150 ) {
F_17 ( 2 , L_27 ,
V_2 -> V_136 ) ;
V_51 -> V_80 = V_151 ;
} else {
F_17 ( 2 , L_28 ,
V_2 -> V_136 ) ;
V_51 -> V_80 = V_150 ;
}
F_51 ( V_2 , V_23 ) ;
return F_68 ( V_2 , V_23 , V_130 ) ;
}
static int
F_77 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_130 * V_130 )
{
switch ( V_23 -> V_36 ) {
case V_114 :
F_51 ( V_2 , V_23 ) ;
return F_68 ( V_2 , V_23 , V_130 ) ;
case V_78 :
return F_66 ( V_2 , V_23 , V_130 , - V_146 ) ;
break;
default:
return F_66 ( V_2 , V_23 , V_130 , - V_146 ) ;
}
}
static void
F_78 ( struct V_1 * V_2 , struct V_130 * V_130 )
{
struct V_138 * V_97 ;
char * V_152 , * V_153 ;
V_152 = F_18 ( V_154 , V_94 ) ;
V_153 = F_18 ( V_154 , V_94 ) ;
if ( ! V_152 || ! V_153 )
goto V_155;
V_97 = (struct V_138 * ) V_130 -> V_139 ;
switch ( V_97 -> V_156 . V_157 . V_158 ) {
case 0x02 :
snprintf ( V_152 , V_154 , L_29 ) ;
break;
case 0x03 :
snprintf ( V_152 , V_154 , L_30 ,
V_97 -> V_156 . V_157 . V_159 ) ;
break;
case 0x04 :
snprintf ( V_152 , V_154 , L_31 ) ;
break;
case 0x05 :
snprintf ( V_152 , V_154 , L_32 ,
V_97 -> V_156 . V_157 . V_159 ) ;
break;
case 0x06 :
snprintf ( V_152 , V_154 , L_33 ) ;
break;
case 0x07 :
snprintf ( V_152 , V_154 , L_34 ,
V_97 -> V_156 . V_157 . V_160 ) ;
break;
default:
snprintf ( V_152 , V_154 , L_35 ,
V_97 -> V_156 . V_157 . V_158 ) ;
break;
}
switch ( V_97 -> V_156 . V_157 . V_161 ) {
case 0x02 :
snprintf ( V_153 , V_154 , L_36
L_37 , V_97 -> V_156 . V_157 . V_160 ) ;
break;
default:
snprintf ( V_153 , V_154 , L_35 ,
V_97 -> V_156 . V_157 . V_161 ) ;
break;
}
F_73 ( & V_2 -> V_147 -> V_148 , L_38
L_39 , V_152 , V_153 ) ;
V_155:
F_26 ( V_152 ) ;
F_26 ( V_153 ) ;
}
static void
F_79 ( struct V_1 * V_2 , struct V_130 * V_130 )
{
struct V_138 * V_97 ;
char * V_152 , * V_153 ;
V_152 = F_18 ( V_154 , V_94 ) ;
V_153 = F_18 ( V_154 , V_94 ) ;
if ( ! V_152 || ! V_153 )
goto V_155;
V_97 = (struct V_138 * ) V_130 -> V_139 ;
switch ( V_97 -> V_156 . V_162 . V_158 ) {
case 0x01 :
snprintf ( V_152 , V_154 , L_40 ) ;
break;
case 0x02 :
snprintf ( V_152 , V_154 , L_41
L_42 ) ;
break;
case 0x03 :
snprintf ( V_152 , V_154 , L_43
L_44 , V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x04 :
snprintf ( V_152 , V_154 , L_45
L_35 , V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x05 :
snprintf ( V_152 , V_154 , L_46
L_35 , V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x06 :
snprintf ( V_152 , V_154 , L_47 ,
V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x07 :
snprintf ( V_152 , V_154 , L_48
L_35 , V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
default:
snprintf ( V_152 , V_154 , L_35 ,
V_97 -> V_156 . V_162 . V_158 ) ;
}
switch ( V_97 -> V_156 . V_162 . V_161 ) {
case 0x01 :
snprintf ( V_153 , V_154 , L_49 ) ;
break;
case 0x02 :
snprintf ( V_153 , V_154 , L_50
L_51 ) ;
break;
case 0x03 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_52
L_53 , V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_54
L_55 , V_97 -> V_156 . V_162 . V_160 [ 1 ] ,
V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x04 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_54
L_56 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_57
L_58 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x05 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_59
L_60 , V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_59
L_58 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x06 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_54
L_61 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_54
L_62 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x07 :
snprintf ( V_153 , V_154 , L_63 ) ;
break;
default:
snprintf ( V_153 , V_154 , L_35 ,
V_97 -> V_156 . V_162 . V_161 ) ;
}
F_73 ( & V_2 -> V_147 -> V_148 , L_64
L_65 , V_152 , V_153 ) ;
V_155:
F_26 ( V_152 ) ;
F_26 ( V_153 ) ;
}
static void
F_80 ( struct V_1 * V_2 , struct V_130 * V_130 )
{
struct V_138 * V_97 ;
char * V_152 , * V_153 ;
V_152 = F_18 ( V_154 , V_94 ) ;
V_153 = F_18 ( V_154 , V_94 ) ;
if ( ! V_152 || ! V_153 )
goto V_155;
V_97 = (struct V_138 * ) V_130 -> V_139 ;
switch ( V_97 -> V_156 . V_162 . V_158 ) {
case 0x01 :
snprintf ( V_152 , V_154 , L_40 ) ;
break;
case 0x02 :
snprintf ( V_152 , V_154 , L_66
L_67 ) ;
break;
case 0x03 :
snprintf ( V_152 , V_154 , L_68
L_44 , V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x04 :
snprintf ( V_152 , V_154 , L_69 ,
V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x05 :
snprintf ( V_152 , V_154 , L_70
L_71 , V_97 -> V_156 . V_162 . V_160 [ 0 ] ) ;
break;
case 0x06 :
snprintf ( V_152 , V_154 , L_72 ) ;
break;
case 0x07 :
snprintf ( V_152 , V_154 , L_73 ) ;
break;
default:
snprintf ( V_152 , V_154 , L_35 ,
V_97 -> V_156 . V_162 . V_158 ) ;
}
switch ( V_97 -> V_156 . V_162 . V_161 ) {
case 0x01 :
snprintf ( V_153 , V_154 , L_49 ) ;
break;
case 0x02 :
snprintf ( V_153 , V_154 , L_74
L_51 ) ;
break;
case 0x03 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_54
L_75 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_54
L_76 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x04 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_54
L_77 , V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_54
L_78 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x05 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_79
L_80 , V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_79
L_81 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x07 :
snprintf ( V_153 , V_154 , L_82 ) ;
break;
case 0x08 :
if ( V_97 -> V_156 . V_162 . V_163 == 0 )
snprintf ( V_153 , V_154 , L_54
L_83 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] ) ;
else
snprintf ( V_153 , V_154 , L_54
L_84 ,
V_97 -> V_156 . V_162 . V_160 [ 1 ] , V_97 -> V_156 . V_162 . V_160 [ 2 ] ) ;
break;
case 0x09 :
snprintf ( V_153 , V_154 , L_85 ) ;
break;
default:
snprintf ( V_153 , V_154 , L_35 ,
V_97 -> V_156 . V_162 . V_161 ) ;
}
F_73 ( & V_2 -> V_147 -> V_148 , L_86
L_65 , V_152 , V_153 ) ;
V_155:
F_26 ( V_152 ) ;
F_26 ( V_153 ) ;
}
static void
F_81 ( struct V_1 * V_2 , struct V_130 * V_130 )
{
struct V_138 * V_97 ;
V_97 = (struct V_138 * ) V_130 -> V_139 ;
if ( V_97 -> V_164 == 0 )
return;
if ( ( V_97 -> V_164 > 0 ) && ( V_97 -> V_164 < V_165 ) ) {
if ( V_166 [ V_97 -> V_164 ] != NULL )
F_73 ( & V_2 -> V_147 -> V_148 , L_87
L_88 ,
V_166 [ V_97 -> V_164 ] ) ;
else
F_73 ( & V_2 -> V_147 -> V_148 , L_87
L_89 ,
V_97 -> V_164 ) ;
return;
}
if ( V_97 -> V_164 == 0xf0 ) {
F_73 ( & V_2 -> V_147 -> V_148 , L_90
L_91 , V_97 -> V_156 . V_157 . V_167 , V_97 -> V_164 ,
V_97 -> V_156 . V_157 . V_158 , V_97 -> V_156 . V_157 . V_161 ,
V_97 -> V_156 . V_157 . V_168 , V_97 -> V_156 . V_157 . V_169 ,
V_97 -> V_156 . V_157 . V_170 ) ;
F_78 ( V_2 , V_130 ) ;
return;
}
if ( V_97 -> V_164 == 0xf1 ) {
F_73 ( & V_2 -> V_147 -> V_148 , L_92
L_93 ,
V_97 -> V_156 . V_162 . V_167 , V_2 -> V_147 -> V_171 . V_172 ,
V_97 -> V_164 , V_97 -> V_156 . V_162 . V_158 , V_97 -> V_156 . V_162 . V_161 ,
V_97 -> V_156 . V_162 . V_173 , V_97 -> V_156 . V_162 . V_174 ,
V_97 -> V_156 . V_162 . V_175 ) ;
F_79 ( V_2 , V_130 ) ;
return;
}
if ( V_97 -> V_164 == 0xf2 ) {
F_73 ( & V_2 -> V_147 -> V_148 , L_94
L_95 ,
V_97 -> V_156 . V_162 . V_167 , V_2 -> V_147 -> V_171 . V_172 ,
V_97 -> V_164 , V_97 -> V_156 . V_162 . V_158 , V_97 -> V_156 . V_162 . V_161 ,
V_97 -> V_156 . V_162 . V_173 , V_97 -> V_156 . V_162 . V_174 ,
V_97 -> V_156 . V_162 . V_175 ) ;
F_80 ( V_2 , V_130 ) ;
return;
}
if ( V_97 -> V_164 == 0xf3 ) {
return;
}
F_73 ( & V_2 -> V_147 -> V_148 , L_96
L_97 , V_97 -> V_164 ) ;
}
static int F_82 ( struct V_1 * V_2 ,
struct V_22 * V_23 , struct V_130 * V_130 )
{
T_2 V_176 ;
T_3 V_177 ;
char * V_97 ;
V_97 = ( (struct V_138 * ) V_130 -> V_139 ) -> V_156 . V_51 ;
V_176 = V_97 [ 0 ] ;
V_177 = * ( ( T_3 * ) & V_97 [ 10 ] ) ;
if ( ( V_176 == 0 ) && ( V_177 == 0xee31 ) )
return F_70 ( V_2 , V_23 , V_130 , - V_178 ) ;
if ( ( V_176 == 1 ) || ( V_176 == 2 ) )
return F_70 ( V_2 , V_23 , V_130 , - V_179 ) ;
F_83 ( & V_2 -> V_147 -> V_148 , L_98
L_99 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_180 ) ;
}
static int
F_84 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_130 * V_130 )
{
struct V_138 * V_97 ;
V_97 = (struct V_138 * ) V_130 -> V_139 ;
F_17 ( 6 , L_100 , V_97 -> V_181 ) ;
switch ( V_97 -> V_181 ) {
case 0x1110 :
F_81 ( V_2 , V_130 ) ;
return F_71 ( V_2 , V_23 , V_130 ) ;
case 0x2011 :
F_81 ( V_2 , V_130 ) ;
return F_76 ( V_2 , V_23 , V_130 ) ;
case 0x2230 :
case 0x2231 :
F_81 ( V_2 , V_130 ) ;
return F_75 ( V_2 , V_23 , V_130 ) ;
case 0x2240 :
return F_82 ( V_2 , V_23 , V_130 ) ;
case 0x3010 :
F_17 ( 2 , L_101 ,
V_2 -> V_136 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_182 ) ;
case 0x3012 :
F_17 ( 2 , L_102 ,
V_2 -> V_136 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_182 ) ;
case 0x3020 :
F_17 ( 2 , L_103 , V_2 -> V_136 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_182 ) ;
case 0x3122 :
F_17 ( 2 , L_104 ,
V_2 -> V_136 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_146 ) ;
case 0x3123 :
F_17 ( 2 , L_105 ,
V_2 -> V_136 ) ;
F_63 ( V_2 , V_101 ) ;
F_57 ( V_2 , V_54 ) ;
return F_70 ( V_2 , V_23 , V_130 , 0 ) ;
case 0x4010 :
F_63 ( V_2 , V_101 ) ;
F_57 ( V_2 , V_54 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_183 ) ;
case 0x4012 :
F_17 ( 6 , L_106 , V_2 -> V_136 ) ;
F_81 ( V_2 , V_130 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_184 ) ;
case 0x4014 :
F_17 ( 6 , L_107 , V_2 -> V_136 ) ;
return F_74 ( V_2 , V_23 , V_130 ) ;
case 0x5010 :
if ( V_97 -> V_185 == 0xd0 ) {
F_81 ( V_2 , V_130 ) ;
return F_72 ( V_2 , V_23 , V_130 ) ;
}
if ( V_97 -> V_185 == 0x26 ) {
F_81 ( V_2 , V_130 ) ;
return F_77 ( V_2 , V_23 ,
V_130 ) ;
}
return F_70 ( V_2 , V_23 , V_130 , - V_146 ) ;
case 0x5020 :
case 0x5021 :
case 0x5022 :
case 0x5040 :
case 0x5041 :
case 0x5042 :
F_81 ( V_2 , V_130 ) ;
return F_72 ( V_2 , V_23 , V_130 ) ;
case 0x5110 :
case 0x5111 :
return F_70 ( V_2 , V_23 , V_130 , - V_186 ) ;
case 0x5120 :
case 0x1120 :
F_63 ( V_2 , V_101 ) ;
F_57 ( V_2 , V_54 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_183 ) ;
case 0x6020 :
return F_70 ( V_2 , V_23 , V_130 , - V_186 ) ;
case 0x8011 :
return F_70 ( V_2 , V_23 , V_130 , - V_187 ) ;
case 0x8013 :
F_73 ( & V_2 -> V_147 -> V_148 , L_108
L_109 ) ;
return F_70 ( V_2 , V_23 , V_130 , - V_187 ) ;
default:
return F_70 ( V_2 , V_23 , V_130 , - V_146 ) ;
}
}
static int
F_85 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_130 * V_130 )
{
if ( V_23 == NULL )
return F_69 ( V_2 , V_130 ) ;
if ( ( V_130 -> V_132 . V_59 . V_133 & V_188 ) &&
( V_130 -> V_132 . V_59 . V_133 & V_189 ) &&
( V_23 -> V_36 == V_116 ) ) {
F_17 ( 2 , L_110 ) ;
return F_66 ( V_2 , V_23 , V_130 , - V_182 ) ;
}
if ( V_130 -> V_132 . V_59 . V_133 & V_190 )
return F_84 ( V_2 , V_23 , V_130 ) ;
if ( V_130 -> V_132 . V_59 . V_133 & V_189 ) {
if ( V_130 -> V_132 . V_59 . V_133 == V_188 ) {
if ( V_23 -> V_36 == V_112 || V_23 -> V_36 == V_109 )
V_23 -> V_191 ++ ;
else
F_17 ( 5 , L_111 ) ;
}
return F_64 ( V_2 , V_23 ) ;
}
if ( V_130 -> V_132 . V_59 . V_133 & V_134 ) {
F_17 ( 2 , L_112 ) ;
return V_135 ;
}
if ( V_130 -> V_132 . V_59 . V_133 & V_137 ) {
F_17 ( 2 , L_113 ) ;
return V_135 ;
}
F_17 ( 6 , L_114 ) ;
F_67 ( V_2 , V_23 , V_130 ) ;
return V_145 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct V_192 * V_193 )
{
int V_28 ;
struct V_22 * V_23 ;
V_23 = F_19 ( 1 , sizeof( * V_193 ) ) ;
if ( F_20 ( V_23 ) )
return F_21 ( V_23 ) ;
V_23 -> V_36 = V_128 ;
F_23 ( V_23 -> V_38 , V_194 , sizeof( * V_193 ) ,
V_23 -> V_33 ) ;
V_28 = F_24 ( V_2 , V_23 ) ;
if ( V_28 == 0 )
memcpy ( V_193 , V_23 -> V_33 , sizeof( * V_193 ) ) ;
F_25 ( V_23 ) ;
return V_28 ;
}
static int
F_87 ( struct V_1 * V_2 )
{
int V_28 ;
struct V_77 * V_51 ;
struct V_192 * V_193 ;
F_17 ( 6 , L_115 ) ;
V_51 = F_58 ( sizeof( struct V_77 ) , V_29 | V_30 ) ;
if ( V_51 == NULL )
return - V_31 ;
V_51 -> V_80 = V_150 ;
V_2 -> V_79 = V_51 ;
V_193 = F_18 ( sizeof( * V_193 ) , V_29 | V_30 ) ;
if ( ! V_193 ) {
V_28 = - V_31 ;
goto V_195;
}
V_28 = F_86 ( V_2 , V_193 ) ;
if ( V_28 ) {
F_88 ( 3 , L_116 ) ;
goto V_196;
}
V_28 = F_89 ( V_2 ) ;
if ( V_28 )
goto V_196;
if ( V_193 -> V_51 [ 31 ] == 0x13 ) {
V_51 -> V_197 . V_198 |= V_199 ;
F_40 ( V_2 ) ;
} else {
F_17 ( 6 , L_117 ) ;
}
V_28 = F_45 ( V_2 ) ;
if ( V_28 ) {
F_88 ( 3 , L_118 , V_28 ) ;
goto V_196;
}
return 0 ;
V_196:
F_26 ( V_193 ) ;
V_195:
F_26 ( V_51 ) ;
return V_28 ;
}
static void
F_90 ( struct V_1 * V_2 )
{
F_91 ( V_95 ) ;
F_92 ( V_2 ) ;
F_26 ( V_2 -> V_79 ) ;
V_2 -> V_79 = NULL ;
}
static int
F_93 ( struct V_200 * V_147 )
{
return F_94 ( F_95 ( & V_147 -> V_148 ) ,
& V_201 ) ;
}
static int
F_96 ( void )
{
int V_28 ;
V_202 = F_97 ( L_119 , 2 , 2 , 4 * sizeof( long ) ) ;
F_98 ( V_202 , & V_203 ) ;
#ifdef F_99
F_100 ( V_202 , 6 ) ;
#endif
F_17 ( 3 , L_120 ) ;
V_95 = F_101 ( L_119 , 0 , 0 ) ;
if ( ! V_95 )
return - V_31 ;
V_28 = F_102 ( & V_204 ) ;
if ( V_28 ) {
F_103 ( V_95 ) ;
F_17 ( 3 , L_121 ) ;
} else
F_17 ( 3 , L_122 ) ;
return V_28 ;
}
static void
F_104 ( void )
{
F_105 ( & V_204 ) ;
F_103 ( V_95 ) ;
F_106 ( V_202 ) ;
}
