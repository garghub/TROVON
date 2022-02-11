static struct V_1 *
V_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_4 ( V_3 ) ;
if ( ! V_5 -> V_6 ) {
struct V_1 * V_6 ;
V_5 -> V_6 = V_6 = F_1 ( sizeof( * V_6 ) , V_7 ) ;
if ( V_5 -> V_6 ) {
struct V_8 args = {
. V_9 = ~ 0ULL ,
} ;
F_2 ( & V_6 -> V_10 ) ;
if ( F_3 ( & V_5 -> V_11 . V_12 , 0 , V_13 ,
& args , sizeof( args ) ,
& V_6 -> V_9 ) == 0 )
return V_5 -> V_6 ;
F_4 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
}
return V_5 -> V_6 ;
}
struct V_1 *
F_5 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = V_4 ( V_3 ) ;
F_6 ( & V_5 -> V_14 ) ;
if ( V_1 ( V_3 ) )
return V_5 -> V_6 ;
F_7 ( & V_5 -> V_14 ) ;
return NULL ;
}
int
F_8 ( struct V_1 * V_6 , int V_15 )
{
struct V_4 * V_5 = ( void * ) V_6 -> V_9 . V_12 . V_16 ;
F_7 ( & V_5 -> V_14 ) ;
return V_15 ;
}
T_1
F_9 ( struct V_17 * V_18 )
{
switch ( V_18 -> V_9 . V_19 . V_20 ) {
case V_21 :
return V_22 ;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
return V_27 ;
case V_28 :
return V_29 ;
case V_30 :
case V_31 :
case V_32 :
return V_33 ;
}
return 0x0000 ;
}
static void
F_10 ( struct V_34 * V_35 ,
struct V_36 * V_37 )
{
F_11 ( & V_37 -> V_12 ) ;
F_12 ( & V_35 -> V_38 , & V_37 -> V_39 ) ;
F_13 ( & V_37 -> V_40 ) ;
F_4 ( V_37 ) ;
}
static void
F_14 ( struct V_1 * V_6 ,
struct V_34 * V_35 )
{
struct V_36 * V_37 , * V_41 ;
if ( V_35 -> V_35 && V_35 -> V_37 )
F_15 ( V_35 -> V_35 ) ;
F_16 (ntfy, temp, &chan->notifiers, head) {
F_10 ( V_35 , V_37 ) ;
}
if ( V_35 -> V_37 ) {
F_17 ( V_35 -> V_37 , & V_35 -> V_42 ) ;
F_18 ( V_35 -> V_37 ) ;
F_19 ( & V_35 -> V_37 -> V_43 ) ;
}
if ( V_35 -> V_38 . V_44 )
F_20 ( & V_35 -> V_38 ) ;
if ( V_35 -> V_35 ) {
F_15 ( V_35 -> V_35 ) ;
F_21 ( & V_35 -> V_35 ) ;
}
F_13 ( & V_35 -> V_40 ) ;
F_4 ( V_35 ) ;
}
void
F_22 ( struct V_1 * V_6 )
{
struct V_4 * V_5 = ( void * ) V_6 -> V_9 . V_12 . V_16 ;
struct V_34 * V_35 , * V_41 ;
F_16 (chan, temp, &abi16->channels, head) {
F_14 ( V_6 , V_35 ) ;
}
F_23 ( & V_6 -> V_9 ) ;
F_4 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
int
F_24 ( T_2 )
{
struct V_4 * V_5 = V_4 ( V_3 ) ;
struct V_17 * V_18 = V_17 ( V_45 ) ;
struct V_46 * V_9 = & V_18 -> V_9 ;
struct V_47 * V_48 = F_25 ( V_9 ) ;
struct V_49 * V_50 = V_51 ;
switch ( V_50 -> V_52 ) {
case V_53 :
V_50 -> V_54 = V_9 -> V_19 . V_55 ;
break;
case V_56 :
if ( F_26 ( V_9 ) -> V_57 -> V_58 )
V_50 -> V_54 = V_45 -> V_59 -> V_60 ;
else
V_50 -> V_54 = 0 ;
break;
case V_61 :
if ( F_26 ( V_9 ) -> V_57 -> V_58 )
V_50 -> V_54 = V_45 -> V_59 -> V_9 ;
else
V_50 -> V_54 = 0 ;
break;
case V_62 :
if ( ! F_26 ( V_9 ) -> V_57 -> V_58 )
V_50 -> V_54 = 3 ;
else
if ( F_27 ( V_45 ) )
V_50 -> V_54 = 0 ;
else
if ( ! F_28 ( V_45 -> V_59 ) )
V_50 -> V_54 = 1 ;
else
V_50 -> V_54 = 2 ;
break;
case V_63 :
V_50 -> V_54 = V_18 -> V_43 . V_64 ;
break;
case V_65 :
V_50 -> V_54 = V_18 -> V_43 . V_66 ;
break;
case V_67 :
V_50 -> V_54 = 0 ;
break;
case V_68 :
V_50 -> V_54 = F_29 ( V_9 ) ;
break;
case V_69 :
V_50 -> V_54 = 1 ;
break;
case V_70 :
V_50 -> V_54 = 1 ;
break;
case V_71 :
V_50 -> V_54 = F_30 ( V_48 ) ;
break;
default:
F_31 ( V_72 , V_5 , L_1 , V_50 -> V_52 ) ;
return - V_73 ;
}
return 0 ;
}
int
F_32 ( T_2 )
{
return - V_73 ;
}
int
F_33 ( T_2 )
{
struct V_74 * V_75 = V_51 ;
struct V_4 * V_5 = V_4 ( V_3 ) ;
struct V_17 * V_18 = V_17 ( V_45 ) ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_46 * V_9 ;
int V_15 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
if ( ! V_18 -> V_77 )
return F_8 ( V_6 , - V_78 ) ;
V_9 = & V_6 -> V_9 ;
if ( V_9 -> V_19 . V_20 >= V_31 ) {
if ( V_75 -> V_79 != ~ 0 )
V_75 -> V_79 = V_80 ;
else {
V_75 -> V_79 = 0 ;
#define _ ( T_3 , T_4 ) if (init->tt_ctxdma_handle & (A)) init->fb_ctxdma_handle |= (B)
_ ( 0x01 , V_80 ) ;
_ ( 0x02 , V_81 ) ;
_ ( 0x04 , V_82 ) ;
_ ( 0x08 , V_83 ) ;
_ ( 0x10 , V_84 ) ;
_ ( 0x20 , V_85 ) ;
_ ( 0x40 , V_86 ) ;
#undef _
}
V_75 -> V_87 = 0 ;
if ( V_75 -> V_79 == V_80 )
V_75 -> V_87 = 1 ;
}
if ( V_75 -> V_79 == ~ 0 || V_75 -> V_87 == ~ 0 )
return F_8 ( V_6 , - V_73 ) ;
V_35 = F_1 ( sizeof( * V_35 ) , V_7 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_76 ) ;
F_2 ( & V_35 -> V_88 ) ;
F_35 ( & V_35 -> V_40 , & V_6 -> V_10 ) ;
V_15 = F_36 ( V_18 , V_9 , V_75 -> V_79 ,
V_75 -> V_87 , & V_35 -> V_35 ) ;
if ( V_15 )
goto V_89;
V_75 -> V_77 = V_35 -> V_35 -> V_90 ;
if ( V_9 -> V_19 . V_20 >= V_28 )
V_75 -> V_91 = V_92 |
V_93 ;
else
if ( V_35 -> V_35 -> V_94 . V_95 -> V_96 . V_97 . V_98 == V_99 )
V_75 -> V_91 = V_92 ;
else
V_75 -> V_91 = V_93 ;
if ( V_9 -> V_19 . V_20 < V_23 ) {
V_75 -> V_100 [ 0 ] . V_101 = 0x00000000 ;
V_75 -> V_100 [ 0 ] . V_102 = 0x0000 ;
V_75 -> V_100 [ 1 ] . V_101 = V_35 -> V_35 -> V_103 . V_101 ;
V_75 -> V_100 [ 1 ] . V_102 = 0x506e ;
V_75 -> V_104 = 2 ;
}
V_15 = F_37 ( V_45 , V_105 , 0 , V_93 ,
0 , 0 , & V_35 -> V_37 ) ;
if ( V_15 == 0 )
V_15 = F_38 ( V_35 -> V_37 , V_106 , false ) ;
if ( V_15 )
goto V_89;
if ( V_9 -> V_19 . V_20 >= V_28 ) {
V_15 = F_39 ( V_35 -> V_37 , V_5 -> V_107 ,
& V_35 -> V_42 ) ;
if ( V_15 )
goto V_89;
}
V_15 = F_40 ( V_3 , & V_35 -> V_37 -> V_43 ,
& V_75 -> V_108 ) ;
if ( V_15 )
goto V_89;
V_15 = F_41 ( & V_35 -> V_38 , 0 , V_105 , 1 ) ;
V_89:
if ( V_15 )
F_14 ( V_6 , V_35 ) ;
return F_8 ( V_6 , V_15 ) ;
}
static struct V_34 *
V_34 ( struct V_1 * V_6 , int V_77 )
{
struct V_34 * V_35 ;
F_42 (chan, &abi16->channels, head) {
if ( V_35 -> V_35 -> V_90 == V_77 )
return V_35 ;
}
return NULL ;
}
int
F_43 ( struct V_2 * V_3 , void * V_51 , T_5 V_109 )
{
union {
struct V_110 V_111 ;
} * args = V_51 ;
struct V_34 * V_35 ;
struct V_1 * V_6 ;
int V_15 = - V_112 ;
if ( ! ( V_15 = F_44 ( V_15 , & V_51 , & V_109 , args -> V_111 , 0 , 0 , true ) ) ) {
switch ( args -> V_111 . type ) {
case V_113 :
case V_114 :
case V_115 :
break;
default:
return - V_116 ;
}
} else
return V_15 ;
if ( ! ( V_6 = V_1 ( V_3 ) ) )
return - V_76 ;
if ( args -> V_111 . V_117 != ~ 0ULL ) {
if ( ! ( V_35 = V_34 ( V_6 , args -> V_111 . V_117 ) ) )
return - V_73 ;
args -> V_111 . V_12 = F_45 ( & V_35 -> V_35 -> V_118 ) ;
args -> V_111 . V_119 = V_120 ;
return 0 ;
}
args -> V_111 . V_12 = F_45 ( & V_6 -> V_9 . V_12 ) ;
args -> V_111 . V_119 = V_120 ;
return 0 ;
}
int
F_46 ( T_2 )
{
struct V_121 * V_122 = V_51 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
V_35 = V_34 ( V_6 , V_122 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_123 ) ;
F_14 ( V_6 , V_35 ) ;
return F_8 ( V_6 , 0 ) ;
}
int
F_47 ( T_2 )
{
struct V_124 * V_75 = V_51 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_125 * V_16 ;
struct V_126 * V_127 ;
T_1 V_128 = 0 ;
int V_15 , V_129 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
if ( V_75 -> V_101 == ~ 0 )
return F_8 ( V_6 , - V_73 ) ;
V_16 = V_6 -> V_9 . V_12 . V_16 ;
V_35 = V_34 ( V_6 , V_75 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_123 ) ;
V_15 = F_48 ( & V_35 -> V_35 -> V_118 , & V_127 ) ;
if ( V_15 < 0 )
return F_8 ( V_6 , V_15 ) ;
if ( ( V_75 -> V_130 & 0x00ff ) == 0x006e ) {
for ( V_129 = 0 ; ! V_128 && V_129 < V_15 ; V_129 ++ ) {
switch ( V_127 [ V_129 ] . V_128 ) {
case V_22 :
case V_27 :
case V_29 :
case V_33 :
V_128 = V_127 [ V_129 ] . V_128 ;
break;
default:
break;
}
}
} else
if ( ( V_75 -> V_130 & 0x00ff ) == 0x00b1 ) {
for ( V_129 = 0 ; V_129 < V_15 ; V_129 ++ ) {
if ( ( V_127 [ V_129 ] . V_128 & 0x00ff ) == 0x00b1 ) {
V_128 = V_127 [ V_129 ] . V_128 ;
break;
}
}
} else
if ( ( V_75 -> V_130 & 0x00ff ) == 0x00b2 ) {
for ( V_129 = 0 ; V_129 < V_15 ; V_129 ++ ) {
if ( ( V_127 [ V_129 ] . V_128 & 0x00ff ) == 0x00b2 ) {
V_128 = V_127 [ V_129 ] . V_128 ;
break;
}
}
} else
if ( ( V_75 -> V_130 & 0x00ff ) == 0x00b3 ) {
for ( V_129 = 0 ; V_129 < V_15 ; V_129 ++ ) {
if ( ( V_127 [ V_129 ] . V_128 & 0x00ff ) == 0x00b3 ) {
V_128 = V_127 [ V_129 ] . V_128 ;
break;
}
}
} else {
V_128 = V_75 -> V_130 ;
}
F_49 ( & V_127 ) ;
if ( ! V_128 )
return F_8 ( V_6 , - V_73 ) ;
V_37 = F_1 ( sizeof( * V_37 ) , V_7 ) ;
if ( ! V_37 )
return F_8 ( V_6 , - V_76 ) ;
F_35 ( & V_37 -> V_40 , & V_35 -> V_88 ) ;
V_16 -> V_131 = V_132 ;
V_15 = F_50 ( & V_35 -> V_35 -> V_118 , V_75 -> V_101 , V_128 ,
NULL , 0 , & V_37 -> V_12 ) ;
V_16 -> V_131 = V_133 ;
if ( V_15 )
F_10 ( V_35 , V_37 ) ;
return F_8 ( V_6 , V_15 ) ;
}
int
F_51 ( T_2 )
{
struct V_134 * V_19 = V_51 ;
struct V_17 * V_18 = V_17 ( V_45 ) ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_46 * V_9 = & V_6 -> V_9 ;
struct V_125 * V_16 ;
struct V_135 args = {} ;
int V_15 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
if ( F_34 ( V_9 -> V_19 . V_20 >= V_30 ) )
return F_8 ( V_6 , - V_73 ) ;
V_16 = V_6 -> V_9 . V_12 . V_16 ;
V_35 = V_34 ( V_6 , V_19 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_123 ) ;
V_37 = F_1 ( sizeof( * V_37 ) , V_7 ) ;
if ( ! V_37 )
return F_8 ( V_6 , - V_76 ) ;
F_35 ( & V_37 -> V_40 , & V_35 -> V_88 ) ;
V_15 = F_52 ( & V_35 -> V_38 , 0 , 1 , V_19 -> V_109 , V_19 -> V_109 , 1 ,
& V_37 -> V_39 ) ;
if ( V_15 )
goto V_89;
args . V_136 = V_37 -> V_39 -> V_137 ;
args . V_138 = V_37 -> V_39 -> V_137 + V_37 -> V_39 -> V_139 - 1 ;
if ( V_9 -> V_19 . V_20 >= V_28 ) {
args . V_140 = V_141 ;
args . V_142 = V_143 ;
args . V_136 += V_35 -> V_42 . V_137 ;
args . V_138 += V_35 -> V_42 . V_137 ;
} else
if ( V_18 -> V_144 . V_145 ) {
args . V_140 = V_146 ;
args . V_142 = V_147 ;
args . V_136 += V_18 -> V_144 . V_11 + V_35 -> V_37 -> V_96 . V_137 ;
args . V_138 += V_18 -> V_144 . V_11 + V_35 -> V_37 -> V_96 . V_137 ;
} else {
args . V_140 = V_141 ;
args . V_142 = V_147 ;
args . V_136 += V_35 -> V_37 -> V_96 . V_137 ;
args . V_138 += V_35 -> V_37 -> V_96 . V_137 ;
}
V_16 -> V_131 = V_132 ;
V_16 -> V_148 = true ;
V_15 = F_50 ( & V_35 -> V_35 -> V_118 , V_19 -> V_101 ,
V_149 , & args , sizeof( args ) ,
& V_37 -> V_12 ) ;
V_16 -> V_148 = false ;
V_16 -> V_131 = V_133 ;
if ( V_15 )
goto V_89;
V_19 -> V_137 = V_37 -> V_39 -> V_137 ;
V_89:
if ( V_15 )
F_10 ( V_35 , V_37 ) ;
return F_8 ( V_6 , V_15 ) ;
}
int
F_53 ( T_2 )
{
struct V_150 * V_151 = V_51 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_15 = - V_123 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
V_35 = V_34 ( V_6 , V_151 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_73 ) ;
F_15 ( V_35 -> V_35 ) ;
F_42 (ntfy, &chan->notifiers, head) {
if ( V_37 -> V_12 . V_101 == V_151 -> V_101 ) {
F_10 ( V_35 , V_37 ) ;
V_15 = 0 ;
break;
}
}
return F_8 ( V_6 , V_15 ) ;
}
