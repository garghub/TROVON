static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
int V_6 ;
int V_7 ;
if ( ! ( V_2 -> V_8 & V_9 ) )
return 0 ;
V_2 -> V_10 [ V_11 ] = V_3 ;
V_2 -> V_10 [ V_12 ] = V_4 ;
if ( V_5 )
memcpy ( V_2 -> V_10 + V_13 ,
V_5 , V_14 ) ;
V_6 = F_2 ( V_2 -> V_15 ,
F_3 ( V_2 -> V_15 , V_16 ) ,
V_2 -> V_10 , V_17 , & V_7 ,
V_18 ) ;
if ( V_6 )
F_4 ( V_2 -> V_19 ,
L_1 ,
V_3 , V_4 , V_6 ) ;
return V_6 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 * V_5 )
{
int V_6 ;
int V_7 ;
if ( ! ( V_2 -> V_8 & V_9 ) )
return 0 ;
V_6 = F_1 ( V_2 , V_3 , V_4 , NULL ) ;
if ( V_6 )
return V_6 ;
V_6 = F_2 ( V_2 -> V_15 ,
F_6 ( V_2 -> V_15 , V_20 ) ,
V_2 -> V_10 , V_17 , & V_7 ,
V_18 ) ;
if ( V_6 )
F_4 ( V_2 -> V_19 ,
L_2 , V_3 , V_4 , V_6 ) ;
else if ( V_5 )
memcpy ( V_5 , V_2 -> V_10 + V_13 ,
V_14 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_21 )
{
T_1 args [ V_14 ] = {
[ 1 ] = V_21 ,
} ;
return F_1 ( V_2 , 9 , 2 , args ) ;
}
static int F_8 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 args [ V_14 ] = {
[ 0 ] = ! ! V_22 ,
} ;
return F_1 ( V_2 , 3 , 2 , args ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 args [ V_14 ] = {
[ 0 ] = ! ! V_22 ,
} ;
return F_1 ( V_2 , 3 , 3 , args ) ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_22 )
{
T_1 args [ V_14 ] = {
[ 0 ] = ! ! V_22 ,
} ;
return F_1 ( V_2 , 10 , 2 , args ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
T_1 args [ V_14 ] ;
T_1 V_25 , V_26 ;
V_25 = ( ( V_24 -> V_27 - 1 ) & 0x3f ) | ( ( ( V_24 -> V_28 - 1 ) & 0x3 ) << 6 ) ;
V_26 = ( ( V_24 -> V_29 + V_24 -> V_30 - 1 ) & 0xf ) |
( ( ( V_24 -> V_31 - 1 ) & 0x7 ) << 4 ) ;
if ( V_2 -> V_32 . V_33 & V_34 )
V_26 |= 0x80 ;
F_12 ( V_2 -> V_19 , L_3 ,
V_25 , V_26 ) ;
args [ 0 ] = V_26 ;
args [ 1 ] = V_25 ;
return F_1 ( V_2 , 1 , 2 , args ) ;
}
static int F_13 ( struct V_1 * V_2 , T_1 V_22 )
{
int V_6 ;
V_6 = F_8 ( V_2 , V_22 ) ;
if ( V_6 )
return V_6 ;
if ( ! V_22 ) {
V_6 = F_7 ( V_2 , V_35 ) ;
} else {
F_14 ( V_36 ) ;
F_15 ( F_16 ( V_37 ) ) ;
}
return V_6 ;
}
static void F_17 ( unsigned long V_38 )
{
F_18 ( (struct V_1 * ) V_38 ) ;
}
static void F_19 ( struct V_39 * V_39 )
{
struct V_40 * V_41 = V_39 -> V_42 ;
F_20 ( & V_41 -> V_43 ,
V_44 + F_16 ( V_37 ) ) ;
F_21 ( V_39 ) ;
}
static int F_22 ( struct V_1 * V_2 , struct V_39 * V_39 ,
T_1 * V_45 )
{
struct V_40 * V_41 = F_23 ( V_2 , struct V_40 , V_2 ) ;
if ( F_24 ( & V_41 -> V_43 ) )
return - V_46 ;
V_45 [ V_11 ] = 3 ;
V_45 [ V_12 ] = 2 ;
V_45 [ V_13 ] = 1 ;
F_25 ( V_39 , V_2 -> V_15 ,
F_3 ( V_2 -> V_15 , V_16 ) ,
V_45 , V_17 ,
F_19 , V_41 ) ;
return F_26 ( V_39 , V_47 ) ;
}
static int F_27 ( struct V_1 * V_2 , T_2 * V_48 )
{
T_1 args [ V_14 ] ;
int V_6 ;
V_6 = F_5 ( V_2 , 6 , 1 , args ) ;
if ( V_6 ) {
F_4 ( V_2 -> V_19 , L_4 , V_6 ) ;
} else if ( V_48 ) {
T_2 V_49 ;
memcpy ( & V_49 , args , 4 ) ;
* V_48 = F_28 ( V_49 ) ;
}
return V_6 ;
}
static int F_29 ( struct V_1 * V_2 , T_2 * V_50 )
{
T_1 args [ V_14 ] ;
int V_6 ;
V_6 = F_5 ( V_2 , 4 , 1 , args ) ;
if ( V_6 )
F_4 ( V_2 -> V_19 , L_5 , V_6 ) ;
else if ( V_50 )
* V_50 = args [ 0 ] ;
return V_6 ;
}
static int F_30 ( struct V_51 * V_52 )
{
T_3 V_53 ;
if ( ( V_52 -> V_54 + 2 ) > V_52 -> V_55 )
return - V_56 ;
memcpy ( & V_53 , V_52 -> V_54 , 2 ) ;
V_52 -> V_57 = F_31 ( V_53 ) ;
if ( V_52 -> V_58 > 0 )
F_32 ( & V_52 -> V_41 -> V_59 , V_52 -> V_57 ) ;
else
F_33 ( & V_52 -> V_41 -> V_59 , V_52 -> V_57 ) ;
return 0 ;
}
static int F_34 ( struct V_51 * V_52 , T_1 V_60 )
{
if ( V_60 ) {
T_3 V_53 ;
if ( ( V_52 -> V_54 + 2 ) > V_52 -> V_55 )
return - V_56 ;
memcpy ( & V_53 , V_52 -> V_54 , 2 ) ;
V_52 -> V_54 += 2 ;
V_52 -> V_57 = F_31 ( V_53 ) ;
V_52 -> V_61 = V_52 -> V_57 & 0x00ff ;
} else {
T_1 V_62 ;
if ( ( V_52 -> V_54 + 1 ) > V_52 -> V_55 )
return - V_56 ;
V_62 = * V_52 -> V_54 ++ ;
if ( V_62 < V_52 -> V_61 )
V_52 -> V_57 += 0x100 ;
V_52 -> V_57 &= 0xff00 ;
V_52 -> V_57 |= V_62 ;
V_52 -> V_61 = V_62 ;
}
return 0 ;
}
static int F_35 ( struct V_51 * V_52 , T_1 V_4 ,
T_1 V_63 )
{
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 V_69 ;
enum V_70 V_71 ;
if ( V_4 == V_72 )
if ( ! V_52 -> V_41 -> V_59 . V_73 )
return 0 ;
V_71 = V_52 -> V_41 -> V_2 . V_32 . V_8 ;
switch ( V_52 -> V_41 -> V_2 . V_32 . V_8 ) {
case V_74 :
if ( V_4 & V_75 ) {
V_71 = V_76 ;
break;
}
case V_76 :
if ( V_4 & V_77 ) {
V_71 = V_78 ;
break;
}
if ( V_4 & V_79 ) {
V_71 = V_80 ;
break;
}
if ( V_4 & ( V_81 | V_72 ) ) {
V_71 = V_82 ;
break;
}
if ( ( V_4 & V_75 ) == 0 ) {
V_52 -> V_41 -> V_2 . V_32 . V_8 = V_74 ;
return 0 ;
}
break;
case V_78 :
if ( V_4 & V_79 ) {
V_71 = V_80 ;
break;
}
if ( V_4 & V_75 ) {
V_71 = V_76 ;
break;
}
if ( V_4 & ( V_81 | V_72 ) ) {
V_71 = V_82 ;
break;
}
if ( ( V_4 & V_77 ) == 0 ) {
V_52 -> V_41 -> V_2 . V_32 . V_8 = V_74 ;
return 0 ;
}
break;
default:
return 0 ;
}
if ( V_52 -> V_41 -> V_2 . V_32 . V_8 == V_71 )
return 0 ;
V_65 = F_36 ( V_52 -> V_19 , & V_67 ) ;
if ( ! V_65 )
return - V_83 ;
switch ( V_71 ) {
case V_80 :
V_67 -> V_84 |= V_85 ;
F_37 ( V_52 -> V_19 ) ;
break;
case V_78 :
V_67 -> V_84 |= V_86 ;
V_67 -> V_87 [ 1 ] |= V_88 |
V_89 ;
V_52 -> V_41 -> V_2 . V_32 . V_90 . V_91 ++ ;
break;
case V_76 :
V_67 -> V_84 |= V_86 ;
V_67 -> V_87 [ 1 ] |= V_92 |
V_93 ;
V_52 -> V_41 -> V_2 . V_32 . V_90 . V_94 ++ ;
break;
default:
V_67 -> V_84 |= V_86 ;
V_67 -> V_87 [ 1 ] |= V_95 ;
V_52 -> V_19 -> V_96 . V_97 ++ ;
V_52 -> V_19 -> V_96 . V_98 ++ ;
V_71 = V_52 -> V_41 -> V_2 . V_32 . V_8 ;
break;
}
V_52 -> V_41 -> V_2 . V_32 . V_8 = V_71 ;
if ( V_63 & V_99 ) {
F_38 ( & V_52 -> V_41 -> V_59 , V_52 -> V_57 , & V_69 ) ;
V_65 -> V_100 = F_39 ( V_69 ) ;
}
F_40 ( V_65 ) ;
V_52 -> V_19 -> V_96 . V_101 ++ ;
V_52 -> V_19 -> V_96 . V_102 += V_67 -> V_103 ;
return 0 ;
}
static int F_41 ( struct V_51 * V_52 ,
T_1 V_63 )
{
T_1 V_104 = V_63 & V_105 ;
T_1 V_3 , V_4 ;
int V_6 ;
if ( ( V_52 -> V_54 + 2 ) > V_52 -> V_55 )
return - V_56 ;
V_3 = V_52 -> V_54 [ V_11 ] ;
V_4 = V_52 -> V_54 [ V_12 ] ;
V_52 -> V_54 += V_13 ;
if ( V_63 & V_99 ) {
int V_6 = F_34 ( V_52 , ! V_52 -> V_58 ) ;
if ( V_6 )
return V_6 ;
}
switch ( V_3 ) {
case V_106 :
V_6 = F_35 ( V_52 , V_4 , V_63 ) ;
if ( V_6 )
return V_6 ;
break;
case V_107 :
V_104 = 2 ;
break;
case V_108 :
V_104 = 1 ;
break;
case V_109 :
if ( F_30 ( V_52 ) )
return - V_56 ;
break;
case V_110 :
if ( V_4 & V_111 )
F_42 ( V_52 -> V_19 , L_6 ) ;
break;
default:
F_4 ( V_52 -> V_19 , L_7 , V_3 ) ;
break;
}
if ( ( V_52 -> V_54 + V_104 ) > V_52 -> V_55 )
return - V_56 ;
V_52 -> V_54 += V_104 ;
return 0 ;
}
static int F_43 ( struct V_51 * V_52 , T_1 V_63 )
{
T_1 V_104 = V_63 & V_105 ;
struct V_64 * V_65 ;
struct V_66 * V_67 ;
struct V_68 V_69 ;
V_65 = F_44 ( V_52 -> V_19 , & V_67 ) ;
if ( ! V_65 )
return - V_83 ;
if ( V_63 & V_112 ) {
T_2 V_49 ;
if ( ( V_52 -> V_54 + 4 ) > V_52 -> V_55 )
goto V_113;
memcpy ( & V_49 , V_52 -> V_54 , 4 ) ;
V_52 -> V_54 += 4 ;
V_67 -> V_84 = F_28 ( V_49 >> 3 ) | V_114 ;
} else {
T_3 V_53 ;
if ( ( V_52 -> V_54 + 2 ) > V_52 -> V_55 )
goto V_113;
memcpy ( & V_53 , V_52 -> V_54 , 2 ) ;
V_52 -> V_54 += 2 ;
V_67 -> V_84 = F_31 ( V_53 >> 5 ) ;
}
V_67 -> V_103 = F_45 ( V_104 ) ;
if ( F_34 ( V_52 , ! V_52 -> V_115 ) )
goto V_113;
memset ( V_67 -> V_87 , 0x0 , sizeof( V_67 -> V_87 ) ) ;
if ( V_63 & V_116 ) {
V_67 -> V_84 |= V_117 ;
} else {
if ( ( V_52 -> V_54 + V_104 ) > V_52 -> V_55 )
goto V_113;
memcpy ( V_67 -> V_87 , V_52 -> V_54 , V_104 ) ;
V_52 -> V_54 += V_104 ;
}
F_38 ( & V_52 -> V_41 -> V_59 , V_52 -> V_57 , & V_69 ) ;
V_65 -> V_100 = F_39 ( V_69 ) ;
F_40 ( V_65 ) ;
V_52 -> V_19 -> V_96 . V_101 ++ ;
V_52 -> V_19 -> V_96 . V_102 += V_67 -> V_103 ;
return 0 ;
V_113:
F_46 ( V_65 ) ;
return - V_56 ;
}
static int F_47 ( struct V_1 * V_2 , T_1 * V_118 , T_2 V_119 )
{
struct V_51 V_52 = {
. V_120 = V_118 [ 1 ] ,
. V_54 = V_118 + V_121 ,
. V_55 = V_118 + V_119 ,
. V_19 = V_2 -> V_19 ,
. V_41 = F_23 ( V_2 , struct V_40 , V_2 ) ,
} ;
int V_6 ;
for ( V_6 = 0 ; V_52 . V_58 < V_52 . V_120 && ! V_6 ; V_52 . V_58 ++ ) {
T_1 V_122 = * V_52 . V_54 ++ ;
if ( V_122 & V_123 ) {
V_6 = F_41 ( & V_52 , V_122 ) ;
} else {
V_6 = F_43 ( & V_52 , V_122 ) ;
V_52 . V_115 ++ ;
}
}
return V_6 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_39 * V_39 )
{
int V_6 = 0 ;
if ( V_39 -> V_7 > V_121 ) {
V_6 = F_47 ( V_2 , V_39 -> V_124 ,
V_39 -> V_7 ) ;
} else if ( V_39 -> V_7 > 0 ) {
F_4 ( V_2 -> V_19 , L_8 ,
V_39 -> V_7 ) ;
V_6 = - V_56 ;
}
return V_6 ;
}
static int F_49 ( struct V_1 * V_2 , struct V_64 * V_65 ,
T_1 * V_125 , T_4 * V_126 )
{
struct V_127 * V_19 = V_2 -> V_19 ;
struct V_128 * V_96 = & V_19 -> V_96 ;
struct V_66 * V_67 = (struct V_66 * ) V_65 -> V_87 ;
T_1 * V_129 ;
V_125 [ 0 ] = 2 ;
V_125 [ 1 ] = 1 ;
V_129 = V_125 + V_121 ;
* V_129 = V_67 -> V_103 ;
if ( V_67 -> V_84 & V_117 )
* V_129 |= V_116 ;
if ( V_67 -> V_84 & V_114 ) {
T_5 V_49 = F_50 ( ( V_67 -> V_84 & V_130 ) << 3 ) ;
* V_129 |= V_112 ;
memcpy ( ++ V_129 , & V_49 , 4 ) ;
V_129 += 4 ;
} else {
T_6 V_53 = F_51 ( ( V_67 -> V_84 & V_130 ) << 5 ) ;
memcpy ( ++ V_129 , & V_53 , 2 ) ;
V_129 += 2 ;
}
if ( ! ( V_67 -> V_84 & V_117 ) ) {
memcpy ( V_129 , V_67 -> V_87 , V_67 -> V_103 ) ;
V_129 += V_67 -> V_103 ;
}
V_125 [ ( * V_126 ) - 1 ] = ( T_1 ) ( V_96 -> V_131 & 0xff ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_23 ( V_2 , struct V_40 , V_2 ) ;
F_53 ( & V_41 -> V_59 , & V_40 ) ;
if ( V_2 -> V_132 > 3 ) {
int V_6 ;
V_6 = F_9 ( V_2 ,
V_2 -> V_32 . V_33 & V_133 ) ;
if ( V_6 )
return V_6 ;
}
return F_10 ( V_2 , 0 ) ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_40 * V_41 = F_23 ( V_2 , struct V_40 , V_2 ) ;
T_2 V_48 ;
int V_6 ;
F_55 ( & V_41 -> V_43 ) ;
V_41 -> V_43 . V_134 = F_17 ;
V_41 -> V_43 . V_87 = ( unsigned long ) V_2 ;
V_6 = F_27 ( V_2 , & V_48 ) ;
if ( V_6 ) {
F_56 ( V_2 -> V_19 -> V_2 . V_135 ,
L_9 ,
V_40 . V_136 , V_6 ) ;
return V_6 ;
}
F_57 ( V_2 -> V_19 -> V_2 . V_135 ,
L_10 ,
V_40 . V_136 , V_2 -> V_132 , V_48 ,
V_40 . V_137 ) ;
return 0 ;
}
static int F_58 ( struct V_138 * V_139 )
{
struct V_140 * V_141 ;
int V_142 ;
V_141 = V_139 -> V_143 ;
for ( V_142 = 0 ; V_142 < V_141 -> V_144 . V_145 ; V_142 ++ ) {
struct V_146 * V_147 = & V_141 -> V_148 [ V_142 ] . V_144 ;
switch ( V_147 -> V_149 ) {
case V_16 :
case V_20 :
case V_150 :
case V_151 :
break;
default:
return - V_152 ;
}
}
return 0 ;
}
