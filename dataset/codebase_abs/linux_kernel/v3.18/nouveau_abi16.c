struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
F_2 ( & V_7 -> V_8 ) ;
if ( ! V_7 -> V_9 ) {
struct V_1 * V_9 ;
V_7 -> V_9 = V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_7 -> V_9 ) {
struct V_11 args = {
. V_12 = ~ 0ULL ,
} ;
F_4 ( & V_9 -> V_13 ) ;
if ( F_5 ( & V_7 -> V_14 . V_14 , NULL ,
V_15 , V_16 ,
& args , sizeof( args ) ,
& V_9 -> V_12 ) == 0 )
return V_7 -> V_9 ;
F_6 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
F_7 ( & V_7 -> V_8 ) ;
}
return V_7 -> V_9 ;
}
int
F_8 ( struct V_1 * V_9 , int V_17 )
{
struct V_6 * V_7 = ( void * ) F_9 ( & V_9 -> V_12 . V_14 ) ;
F_7 ( & V_7 -> V_8 ) ;
return V_17 ;
}
T_1
F_10 ( struct V_18 * V_19 )
{
switch ( V_19 -> V_12 . V_20 . V_21 ) {
case V_22 :
return 0x006e ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return 0x016e ;
case V_27 :
return 0x506e ;
case V_28 :
case V_29 :
case V_30 :
return 0x906e ;
}
return 0x0000 ;
}
static void
F_11 ( struct V_31 * V_32 ,
struct V_33 * V_34 )
{
F_12 ( & V_32 -> V_35 , & V_34 -> V_36 ) ;
F_13 ( & V_34 -> V_37 ) ;
F_6 ( V_34 ) ;
}
static void
F_14 ( struct V_1 * V_9 ,
struct V_31 * V_32 )
{
struct V_33 * V_34 , * V_38 ;
if ( V_32 -> V_32 && V_32 -> V_34 )
F_15 ( V_32 -> V_32 ) ;
F_16 (ntfy, temp, &chan->notifiers, head) {
F_11 ( V_32 , V_34 ) ;
}
if ( V_32 -> V_34 ) {
F_17 ( V_32 -> V_34 , & V_32 -> V_39 ) ;
F_18 ( V_32 -> V_34 ) ;
F_19 ( & V_32 -> V_34 -> V_40 ) ;
}
if ( V_32 -> V_35 . V_41 )
F_20 ( & V_32 -> V_35 ) ;
if ( V_32 -> V_32 ) {
V_9 -> V_42 &= ~ ( 1ULL << ( V_32 -> V_32 -> V_43 -> V_44 & 0xffff ) ) ;
F_21 ( & V_32 -> V_32 ) ;
}
F_13 ( & V_32 -> V_37 ) ;
F_6 ( V_32 ) ;
}
void
F_22 ( struct V_1 * V_9 )
{
struct V_6 * V_7 = ( void * ) F_9 ( & V_9 -> V_12 . V_14 ) ;
struct V_31 * V_32 , * V_38 ;
F_16 (chan, temp, &abi16->channels, head) {
F_14 ( V_9 , V_32 ) ;
}
F_23 ( & V_9 -> V_12 ) ;
F_6 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
int
F_24 ( T_2 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_18 * V_19 = V_18 ( V_5 ) ;
struct V_45 * V_12 = & V_19 -> V_12 ;
struct V_46 * V_47 = F_25 ( V_12 ) ;
struct V_48 * V_49 = F_26 ( V_12 ) ;
struct V_50 * V_51 = V_52 ;
switch ( V_51 -> V_53 ) {
case V_54 :
V_51 -> V_55 = V_12 -> V_20 . V_56 ;
break;
case V_57 :
if ( F_27 ( F_28 ( V_12 ) ) )
V_51 -> V_55 = V_5 -> V_58 -> V_59 ;
else
V_51 -> V_55 = 0 ;
break;
case V_60 :
if ( F_27 ( F_28 ( V_12 ) ) )
V_51 -> V_55 = V_5 -> V_58 -> V_12 ;
else
V_51 -> V_55 = 0 ;
break;
case V_61 :
if ( ! F_27 ( F_28 ( V_12 ) ) )
V_51 -> V_55 = 3 ;
else
if ( F_29 ( V_5 ) )
V_51 -> V_55 = 0 ;
else
if ( ! F_30 ( V_5 -> V_58 ) )
V_51 -> V_55 = 1 ;
else
V_51 -> V_55 = 2 ;
break;
case V_62 :
V_51 -> V_55 = V_19 -> V_40 . V_63 ;
break;
case V_64 :
V_51 -> V_55 = V_19 -> V_40 . V_65 ;
break;
case V_66 :
V_51 -> V_55 = 0 ;
break;
case V_67 :
V_51 -> V_55 = V_47 -> V_68 ( V_47 ) ;
break;
case V_69 :
V_51 -> V_55 = 1 ;
break;
case V_70 :
V_51 -> V_55 = 1 ;
break;
case V_71 :
V_51 -> V_55 = V_49 -> V_72 ? V_49 -> V_72 ( V_49 ) : 0 ;
break;
default:
F_31 ( V_73 , V_7 , L_1 , V_51 -> V_53 ) ;
return - V_74 ;
}
return 0 ;
}
int
F_32 ( T_2 )
{
return - V_74 ;
}
int
F_33 ( T_2 )
{
struct V_75 * V_76 = V_52 ;
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_18 * V_19 = V_18 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_31 * V_32 ;
struct V_45 * V_12 ;
int V_17 ;
if ( F_34 ( ! V_9 ) )
return - V_77 ;
if ( ! V_19 -> V_78 )
return F_8 ( V_9 , - V_79 ) ;
V_12 = & V_9 -> V_12 ;
if ( V_12 -> V_20 . V_21 >= V_29 ) {
if ( V_76 -> V_80 != ~ 0 )
V_76 -> V_80 = V_81 ;
else
V_76 -> V_80 = V_76 -> V_82 ;
V_76 -> V_82 = 0 ;
if ( V_76 -> V_80 == V_81 )
V_76 -> V_82 = 1 ;
}
if ( V_76 -> V_80 == ~ 0 || V_76 -> V_82 == ~ 0 )
return F_8 ( V_9 , - V_74 ) ;
V_76 -> V_78 = F_35 ( ~ V_9 -> V_42 ) ;
if ( ~ V_9 -> V_42 == 0 )
return F_8 ( V_9 , - V_83 ) ;
V_32 = F_3 ( sizeof( * V_32 ) , V_10 ) ;
if ( ! V_32 )
return F_8 ( V_9 , - V_77 ) ;
F_4 ( & V_32 -> V_84 ) ;
F_36 ( & V_32 -> V_37 , & V_9 -> V_13 ) ;
V_9 -> V_42 |= ( 1ULL << V_76 -> V_78 ) ;
V_17 = F_37 ( V_19 , V_12 ,
F_38 ( V_76 -> V_78 ) ,
V_76 -> V_80 ,
V_76 -> V_82 , & V_32 -> V_32 ) ;
if ( V_17 )
goto V_85;
if ( V_12 -> V_20 . V_21 >= V_27 )
V_76 -> V_86 = V_87 |
V_88 ;
else
if ( V_32 -> V_32 -> V_89 . V_90 -> V_91 . V_92 . V_93 == V_94 )
V_76 -> V_86 = V_87 ;
else
V_76 -> V_86 = V_88 ;
if ( V_12 -> V_20 . V_21 < V_23 ) {
V_76 -> V_95 [ 0 ] . V_44 = 0x00000000 ;
V_76 -> V_95 [ 0 ] . V_96 = 0x0000 ;
V_76 -> V_95 [ 1 ] . V_44 = V_32 -> V_32 -> V_97 . V_44 ;
V_76 -> V_95 [ 1 ] . V_96 = 0x506e ;
V_76 -> V_98 = 2 ;
}
V_17 = F_39 ( V_5 , V_99 , 0 , V_88 ,
0 , 0 , & V_32 -> V_34 ) ;
if ( V_17 == 0 )
V_17 = F_40 ( V_32 -> V_34 , V_100 ) ;
if ( V_17 )
goto V_85;
if ( V_12 -> V_20 . V_21 >= V_27 ) {
V_17 = F_41 ( V_32 -> V_34 , V_7 -> V_101 ,
& V_32 -> V_39 ) ;
if ( V_17 )
goto V_85;
}
V_17 = F_42 ( V_3 , & V_32 -> V_34 -> V_40 ,
& V_76 -> V_102 ) ;
if ( V_17 )
goto V_85;
V_17 = F_43 ( & V_32 -> V_35 , 0 , V_99 , 1 ) ;
V_85:
if ( V_17 )
F_14 ( V_9 , V_32 ) ;
return F_8 ( V_9 , V_17 ) ;
}
static struct V_31 *
V_31 ( struct V_1 * V_9 , int V_78 )
{
struct V_31 * V_32 ;
F_44 (chan, &abi16->channels, head) {
if ( V_32 -> V_32 -> V_43 -> V_44 == F_38 ( V_78 ) )
return V_32 ;
}
return NULL ;
}
int
F_45 ( T_2 )
{
struct V_103 * V_104 = V_52 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_31 * V_32 ;
if ( F_34 ( ! V_9 ) )
return - V_77 ;
V_32 = V_31 ( V_9 , V_104 -> V_78 ) ;
if ( ! V_32 )
return F_8 ( V_9 , - V_105 ) ;
F_14 ( V_9 , V_32 ) ;
return F_8 ( V_9 , 0 ) ;
}
int
F_46 ( T_2 )
{
struct V_106 * V_76 = V_52 ;
struct {
struct V_107 V_108 ;
struct V_109 V_110 ;
} args = {
. V_108 . V_111 = V_112 ,
. V_108 . type = V_113 ,
. V_108 . V_114 = 3 ,
. V_108 . V_115 [ 2 ] = V_116 ,
. V_108 . V_115 [ 1 ] = V_15 ,
. V_108 . V_115 [ 0 ] = F_38 ( V_76 -> V_78 ) ,
. V_110 . V_117 = V_118 ,
. V_110 . V_44 = V_76 -> V_44 ,
. V_110 . V_119 = V_76 -> V_120 ,
} ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_18 * V_19 = V_18 ( V_5 ) ;
struct F_9 * V_121 ;
int V_17 ;
if ( F_34 ( ! V_9 ) )
return - V_77 ;
if ( V_76 -> V_44 == ~ 0 )
return F_8 ( V_9 , - V_74 ) ;
V_121 = F_9 ( F_47 ( & V_9 -> V_12 ) ) ;
if ( V_76 -> V_120 == 0x506e ) {
V_76 -> V_120 = F_10 ( V_19 ) ;
if ( V_76 -> V_120 == 0x906e )
return F_8 ( V_9 , 0 ) ;
}
V_17 = F_48 ( V_121 , & args , sizeof( args ) ) ;
return F_8 ( V_9 , V_17 ) ;
}
int
F_49 ( T_2 )
{
struct V_122 * V_20 = V_52 ;
struct {
struct V_107 V_108 ;
struct V_109 V_110 ;
struct V_123 V_124 ;
} args = {
. V_108 . V_111 = V_112 ,
. V_108 . type = V_113 ,
. V_108 . V_114 = 3 ,
. V_108 . V_115 [ 2 ] = V_116 ,
. V_108 . V_115 [ 1 ] = V_15 ,
. V_108 . V_115 [ 0 ] = F_38 ( V_20 -> V_78 ) ,
. V_110 . V_117 = V_118 ,
. V_110 . V_44 = V_20 -> V_44 ,
. V_110 . V_119 = V_125 ,
} ;
struct V_18 * V_19 = V_18 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct V_45 * V_12 = & V_9 -> V_12 ;
struct F_9 * V_121 ;
int V_17 ;
if ( F_34 ( ! V_9 ) )
return - V_77 ;
if ( F_34 ( V_12 -> V_20 . V_21 >= V_28 ) )
return F_8 ( V_9 , - V_74 ) ;
V_121 = F_9 ( F_47 ( & V_9 -> V_12 ) ) ;
V_32 = V_31 ( V_9 , V_20 -> V_78 ) ;
if ( ! V_32 )
return F_8 ( V_9 , - V_105 ) ;
V_34 = F_3 ( sizeof( * V_34 ) , V_10 ) ;
if ( ! V_34 )
return F_8 ( V_9 , - V_77 ) ;
F_36 ( & V_34 -> V_37 , & V_32 -> V_84 ) ;
V_34 -> V_44 = V_20 -> V_44 ;
V_17 = F_50 ( & V_32 -> V_35 , 0 , 1 , V_20 -> V_126 , V_20 -> V_126 , 1 ,
& V_34 -> V_36 ) ;
if ( V_17 )
goto V_85;
args . V_124 . V_127 = V_34 -> V_36 -> V_128 ;
args . V_124 . V_129 = V_34 -> V_36 -> V_128 + V_34 -> V_36 -> V_130 - 1 ;
if ( V_12 -> V_20 . V_21 >= V_27 ) {
args . V_124 . V_131 = V_132 ;
args . V_124 . V_133 = V_134 ;
args . V_124 . V_127 += V_32 -> V_39 . V_128 ;
args . V_124 . V_129 += V_32 -> V_39 . V_128 ;
} else
if ( V_19 -> V_135 . V_136 == V_137 ) {
args . V_124 . V_131 = V_138 ;
args . V_124 . V_133 = V_139 ;
args . V_124 . V_127 += V_19 -> V_135 . V_14 + V_32 -> V_34 -> V_91 . V_128 ;
args . V_124 . V_129 += V_19 -> V_135 . V_14 + V_32 -> V_34 -> V_91 . V_128 ;
V_121 -> V_140 = true ;
} else {
args . V_124 . V_131 = V_132 ;
args . V_124 . V_133 = V_139 ;
args . V_124 . V_127 += V_32 -> V_34 -> V_91 . V_128 ;
args . V_124 . V_129 += V_32 -> V_34 -> V_91 . V_128 ;
}
V_17 = F_48 ( V_121 , & args , sizeof( args ) ) ;
V_121 -> V_140 = false ;
if ( V_17 )
goto V_85;
V_20 -> V_128 = V_34 -> V_36 -> V_128 ;
V_85:
if ( V_17 )
F_11 ( V_32 , V_34 ) ;
return F_8 ( V_9 , V_17 ) ;
}
int
F_51 ( T_2 )
{
struct V_141 * V_142 = V_52 ;
struct {
struct V_107 V_108 ;
struct V_143 V_144 ;
} args = {
. V_108 . V_111 = V_118 ,
. V_108 . type = V_145 ,
. V_108 . V_114 = 4 ,
. V_108 . V_115 [ 3 ] = V_116 ,
. V_108 . V_115 [ 2 ] = V_15 ,
. V_108 . V_115 [ 1 ] = F_38 ( V_142 -> V_78 ) ,
. V_108 . V_115 [ 0 ] = V_142 -> V_44 ,
} ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_31 * V_32 ;
struct V_33 * V_34 ;
struct F_9 * V_121 ;
int V_17 ;
if ( F_34 ( ! V_9 ) )
return - V_77 ;
V_32 = V_31 ( V_9 , V_142 -> V_78 ) ;
if ( ! V_32 )
return F_8 ( V_9 , - V_105 ) ;
V_121 = F_9 ( F_47 ( & V_9 -> V_12 ) ) ;
F_15 ( V_32 -> V_32 ) ;
V_17 = F_48 ( V_121 , & args , sizeof( args ) ) ;
if ( V_17 )
return F_8 ( V_9 , V_17 ) ;
F_44 (ntfy, &chan->notifiers, head) {
if ( V_34 -> V_44 == V_142 -> V_44 ) {
F_12 ( & V_32 -> V_35 , & V_34 -> V_36 ) ;
F_13 ( & V_34 -> V_37 ) ;
break;
}
}
return F_8 ( V_9 , 0 ) ;
}
