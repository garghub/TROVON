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
case V_33 :
return V_34 ;
}
return 0x0000 ;
}
static void
F_10 ( struct V_35 * V_36 ,
struct V_37 * V_38 )
{
F_11 ( & V_38 -> V_12 ) ;
F_12 ( & V_36 -> V_39 , & V_38 -> V_40 ) ;
F_13 ( & V_38 -> V_41 ) ;
F_4 ( V_38 ) ;
}
static void
F_14 ( struct V_1 * V_6 ,
struct V_35 * V_36 )
{
struct V_37 * V_38 , * V_42 ;
if ( V_36 -> V_36 && V_36 -> V_38 )
F_15 ( V_36 -> V_36 ) ;
F_16 (ntfy, temp, &chan->notifiers, head) {
F_10 ( V_36 , V_38 ) ;
}
if ( V_36 -> V_38 ) {
F_17 ( V_36 -> V_38 , & V_36 -> V_43 ) ;
F_18 ( V_36 -> V_38 ) ;
F_19 ( & V_36 -> V_38 -> V_44 ) ;
}
if ( V_36 -> V_39 . V_45 )
F_20 ( & V_36 -> V_39 ) ;
if ( V_36 -> V_36 ) {
F_15 ( V_36 -> V_36 ) ;
F_21 ( & V_36 -> V_36 ) ;
}
F_13 ( & V_36 -> V_41 ) ;
F_4 ( V_36 ) ;
}
void
F_22 ( struct V_1 * V_6 )
{
struct V_4 * V_5 = ( void * ) V_6 -> V_9 . V_12 . V_16 ;
struct V_35 * V_36 , * V_42 ;
F_16 (chan, temp, &abi16->channels, head) {
F_14 ( V_6 , V_36 ) ;
}
F_23 ( & V_6 -> V_9 ) ;
F_4 ( V_5 -> V_6 ) ;
V_5 -> V_6 = NULL ;
}
int
F_24 ( T_2 )
{
struct V_4 * V_5 = V_4 ( V_3 ) ;
struct V_17 * V_18 = V_17 ( V_46 ) ;
struct V_47 * V_9 = & V_18 -> V_9 ;
struct V_48 * V_49 = F_25 ( V_9 ) ;
struct V_50 * V_51 = V_52 ;
switch ( V_51 -> V_53 ) {
case V_54 :
V_51 -> V_55 = V_9 -> V_19 . V_56 ;
break;
case V_57 :
if ( F_26 ( V_9 ) -> V_58 -> V_59 )
V_51 -> V_55 = V_46 -> V_60 -> V_61 ;
else
V_51 -> V_55 = 0 ;
break;
case V_62 :
if ( F_26 ( V_9 ) -> V_58 -> V_59 )
V_51 -> V_55 = V_46 -> V_60 -> V_9 ;
else
V_51 -> V_55 = 0 ;
break;
case V_63 :
if ( ! F_26 ( V_9 ) -> V_58 -> V_59 )
V_51 -> V_55 = 3 ;
else
if ( F_27 ( V_46 ) )
V_51 -> V_55 = 0 ;
else
if ( ! F_28 ( V_46 -> V_60 ) )
V_51 -> V_55 = 1 ;
else
V_51 -> V_55 = 2 ;
break;
case V_64 :
V_51 -> V_55 = V_18 -> V_44 . V_65 ;
break;
case V_66 :
V_51 -> V_55 = V_18 -> V_44 . V_67 ;
break;
case V_68 :
V_51 -> V_55 = 0 ;
break;
case V_69 :
V_51 -> V_55 = F_29 ( V_9 ) ;
break;
case V_70 :
V_51 -> V_55 = 1 ;
break;
case V_71 :
V_51 -> V_55 = 1 ;
break;
case V_72 :
V_51 -> V_55 = F_30 ( V_49 ) ;
break;
default:
F_31 ( V_73 , V_5 , L_1 , V_51 -> V_53 ) ;
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
struct V_4 * V_5 = V_4 ( V_3 ) ;
struct V_17 * V_18 = V_17 ( V_46 ) ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_35 * V_36 ;
struct V_47 * V_9 ;
int V_15 ;
if ( F_34 ( ! V_6 ) )
return - V_77 ;
if ( ! V_18 -> V_78 )
return F_8 ( V_6 , - V_79 ) ;
V_9 = & V_6 -> V_9 ;
if ( V_9 -> V_19 . V_20 >= V_31 ) {
if ( V_76 -> V_80 != ~ 0 )
V_76 -> V_80 = V_81 ;
else {
V_76 -> V_80 = 0 ;
#define _ ( T_3 , T_4 ) if (init->tt_ctxdma_handle & (A)) init->fb_ctxdma_handle |= (B)
_ ( 0x01 , V_81 ) ;
_ ( 0x02 , V_82 ) ;
_ ( 0x04 , V_83 ) ;
_ ( 0x08 , V_84 ) ;
_ ( 0x10 , V_85 ) ;
_ ( 0x20 , V_86 ) ;
_ ( 0x40 , V_87 ) ;
#undef _
}
V_76 -> V_88 = 0 ;
if ( V_76 -> V_80 == V_81 )
V_76 -> V_88 = 1 ;
}
if ( V_76 -> V_80 == ~ 0 || V_76 -> V_88 == ~ 0 )
return F_8 ( V_6 , - V_74 ) ;
V_36 = F_1 ( sizeof( * V_36 ) , V_7 ) ;
if ( ! V_36 )
return F_8 ( V_6 , - V_77 ) ;
F_2 ( & V_36 -> V_89 ) ;
F_35 ( & V_36 -> V_41 , & V_6 -> V_10 ) ;
V_15 = F_36 ( V_18 , V_9 , V_76 -> V_80 ,
V_76 -> V_88 , & V_36 -> V_36 ) ;
if ( V_15 )
goto V_90;
V_76 -> V_78 = V_36 -> V_36 -> V_91 ;
if ( V_9 -> V_19 . V_20 >= V_28 )
V_76 -> V_92 = V_93 |
V_94 ;
else
if ( V_36 -> V_36 -> V_95 . V_96 -> V_97 . V_98 . V_99 == V_100 )
V_76 -> V_92 = V_93 ;
else
V_76 -> V_92 = V_94 ;
if ( V_9 -> V_19 . V_20 < V_23 ) {
V_76 -> V_101 [ 0 ] . V_102 = 0x00000000 ;
V_76 -> V_101 [ 0 ] . V_103 = 0x0000 ;
V_76 -> V_101 [ 1 ] . V_102 = V_36 -> V_36 -> V_104 . V_102 ;
V_76 -> V_101 [ 1 ] . V_103 = 0x506e ;
V_76 -> V_105 = 2 ;
}
V_15 = F_37 ( V_46 , V_106 , 0 , V_94 ,
0 , 0 , & V_36 -> V_38 ) ;
if ( V_15 == 0 )
V_15 = F_38 ( V_36 -> V_38 , V_107 , false ) ;
if ( V_15 )
goto V_90;
if ( V_9 -> V_19 . V_20 >= V_28 ) {
V_15 = F_39 ( V_36 -> V_38 , V_5 -> V_108 ,
& V_36 -> V_43 ) ;
if ( V_15 )
goto V_90;
}
V_15 = F_40 ( V_3 , & V_36 -> V_38 -> V_44 ,
& V_76 -> V_109 ) ;
if ( V_15 )
goto V_90;
V_15 = F_41 ( & V_36 -> V_39 , 0 , V_106 , 1 ) ;
V_90:
if ( V_15 )
F_14 ( V_6 , V_36 ) ;
return F_8 ( V_6 , V_15 ) ;
}
static struct V_35 *
V_35 ( struct V_1 * V_6 , int V_78 )
{
struct V_35 * V_36 ;
F_42 (chan, &abi16->channels, head) {
if ( V_36 -> V_36 -> V_91 == V_78 )
return V_36 ;
}
return NULL ;
}
int
F_43 ( struct V_2 * V_3 , void * V_52 , T_5 V_110 )
{
union {
struct V_111 V_112 ;
} * args = V_52 ;
struct V_35 * V_36 ;
struct V_1 * V_6 ;
int V_15 = - V_113 ;
if ( ! ( V_15 = F_44 ( V_15 , & V_52 , & V_110 , args -> V_112 , 0 , 0 , true ) ) ) {
switch ( args -> V_112 . type ) {
case V_114 :
case V_115 :
case V_116 :
break;
default:
return - V_117 ;
}
} else
return V_15 ;
if ( ! ( V_6 = V_1 ( V_3 ) ) )
return - V_77 ;
if ( args -> V_112 . V_118 != ~ 0ULL ) {
if ( ! ( V_36 = V_35 ( V_6 , args -> V_112 . V_118 ) ) )
return - V_74 ;
args -> V_112 . V_12 = F_45 ( & V_36 -> V_36 -> V_119 ) ;
args -> V_112 . V_120 = V_121 ;
return 0 ;
}
args -> V_112 . V_12 = F_45 ( & V_6 -> V_9 . V_12 ) ;
args -> V_112 . V_120 = V_121 ;
return 0 ;
}
int
F_46 ( T_2 )
{
struct V_122 * V_123 = V_52 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_35 * V_36 ;
if ( F_34 ( ! V_6 ) )
return - V_77 ;
V_36 = V_35 ( V_6 , V_123 -> V_78 ) ;
if ( ! V_36 )
return F_8 ( V_6 , - V_124 ) ;
F_14 ( V_6 , V_36 ) ;
return F_8 ( V_6 , 0 ) ;
}
int
F_47 ( T_2 )
{
struct V_125 * V_76 = V_52 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_126 * V_16 ;
struct V_127 * V_128 ;
T_1 V_129 = 0 ;
int V_15 , V_130 ;
if ( F_34 ( ! V_6 ) )
return - V_77 ;
if ( V_76 -> V_102 == ~ 0 )
return F_8 ( V_6 , - V_74 ) ;
V_16 = V_6 -> V_9 . V_12 . V_16 ;
V_36 = V_35 ( V_6 , V_76 -> V_78 ) ;
if ( ! V_36 )
return F_8 ( V_6 , - V_124 ) ;
V_15 = F_48 ( & V_36 -> V_36 -> V_119 , & V_128 ) ;
if ( V_15 < 0 )
return F_8 ( V_6 , V_15 ) ;
if ( ( V_76 -> V_131 & 0x00ff ) == 0x006e ) {
for ( V_130 = 0 ; ! V_129 && V_130 < V_15 ; V_130 ++ ) {
switch ( V_128 [ V_130 ] . V_129 ) {
case V_22 :
case V_27 :
case V_29 :
case V_34 :
V_129 = V_128 [ V_130 ] . V_129 ;
break;
default:
break;
}
}
} else
if ( ( V_76 -> V_131 & 0x00ff ) == 0x00b1 ) {
for ( V_130 = 0 ; V_130 < V_15 ; V_130 ++ ) {
if ( ( V_128 [ V_130 ] . V_129 & 0x00ff ) == 0x00b1 ) {
V_129 = V_128 [ V_130 ] . V_129 ;
break;
}
}
} else
if ( ( V_76 -> V_131 & 0x00ff ) == 0x00b2 ) {
for ( V_130 = 0 ; V_130 < V_15 ; V_130 ++ ) {
if ( ( V_128 [ V_130 ] . V_129 & 0x00ff ) == 0x00b2 ) {
V_129 = V_128 [ V_130 ] . V_129 ;
break;
}
}
} else
if ( ( V_76 -> V_131 & 0x00ff ) == 0x00b3 ) {
for ( V_130 = 0 ; V_130 < V_15 ; V_130 ++ ) {
if ( ( V_128 [ V_130 ] . V_129 & 0x00ff ) == 0x00b3 ) {
V_129 = V_128 [ V_130 ] . V_129 ;
break;
}
}
} else {
V_129 = V_76 -> V_131 ;
}
F_49 ( & V_128 ) ;
if ( ! V_129 )
return F_8 ( V_6 , - V_74 ) ;
V_38 = F_1 ( sizeof( * V_38 ) , V_7 ) ;
if ( ! V_38 )
return F_8 ( V_6 , - V_77 ) ;
F_35 ( & V_38 -> V_41 , & V_36 -> V_89 ) ;
V_16 -> V_132 = V_133 ;
V_15 = F_50 ( & V_36 -> V_36 -> V_119 , V_76 -> V_102 , V_129 ,
NULL , 0 , & V_38 -> V_12 ) ;
V_16 -> V_132 = V_134 ;
if ( V_15 )
F_10 ( V_36 , V_38 ) ;
return F_8 ( V_6 , V_15 ) ;
}
int
F_51 ( T_2 )
{
struct V_135 * V_19 = V_52 ;
struct V_17 * V_18 = V_17 ( V_46 ) ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
struct V_47 * V_9 = & V_6 -> V_9 ;
struct V_126 * V_16 ;
struct V_136 args = {} ;
int V_15 ;
if ( F_34 ( ! V_6 ) )
return - V_77 ;
if ( F_34 ( V_9 -> V_19 . V_20 >= V_30 ) )
return F_8 ( V_6 , - V_74 ) ;
V_16 = V_6 -> V_9 . V_12 . V_16 ;
V_36 = V_35 ( V_6 , V_19 -> V_78 ) ;
if ( ! V_36 )
return F_8 ( V_6 , - V_124 ) ;
V_38 = F_1 ( sizeof( * V_38 ) , V_7 ) ;
if ( ! V_38 )
return F_8 ( V_6 , - V_77 ) ;
F_35 ( & V_38 -> V_41 , & V_36 -> V_89 ) ;
V_15 = F_52 ( & V_36 -> V_39 , 0 , 1 , V_19 -> V_110 , V_19 -> V_110 , 1 ,
& V_38 -> V_40 ) ;
if ( V_15 )
goto V_90;
args . V_137 = V_38 -> V_40 -> V_138 ;
args . V_139 = V_38 -> V_40 -> V_138 + V_38 -> V_40 -> V_140 - 1 ;
if ( V_9 -> V_19 . V_20 >= V_28 ) {
args . V_141 = V_142 ;
args . V_143 = V_144 ;
args . V_137 += V_36 -> V_43 . V_138 ;
args . V_139 += V_36 -> V_43 . V_138 ;
} else
if ( V_18 -> V_145 . V_146 ) {
args . V_141 = V_147 ;
args . V_143 = V_148 ;
args . V_137 += V_18 -> V_145 . V_11 + V_36 -> V_38 -> V_97 . V_138 ;
args . V_139 += V_18 -> V_145 . V_11 + V_36 -> V_38 -> V_97 . V_138 ;
} else {
args . V_141 = V_142 ;
args . V_143 = V_148 ;
args . V_137 += V_36 -> V_38 -> V_97 . V_138 ;
args . V_139 += V_36 -> V_38 -> V_97 . V_138 ;
}
V_16 -> V_132 = V_133 ;
V_16 -> V_149 = true ;
V_15 = F_50 ( & V_36 -> V_36 -> V_119 , V_19 -> V_102 ,
V_150 , & args , sizeof( args ) ,
& V_38 -> V_12 ) ;
V_16 -> V_149 = false ;
V_16 -> V_132 = V_134 ;
if ( V_15 )
goto V_90;
V_19 -> V_138 = V_38 -> V_40 -> V_138 ;
V_90:
if ( V_15 )
F_10 ( V_36 , V_38 ) ;
return F_8 ( V_6 , V_15 ) ;
}
int
F_53 ( T_2 )
{
struct V_151 * V_152 = V_52 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_35 * V_36 ;
struct V_37 * V_38 ;
int V_15 = - V_124 ;
if ( F_34 ( ! V_6 ) )
return - V_77 ;
V_36 = V_35 ( V_6 , V_152 -> V_78 ) ;
if ( ! V_36 )
return F_8 ( V_6 , - V_74 ) ;
F_15 ( V_36 -> V_36 ) ;
F_42 (ntfy, &chan->notifiers, head) {
if ( V_38 -> V_12 . V_102 == V_152 -> V_102 ) {
F_10 ( V_36 , V_38 ) ;
V_15 = 0 ;
break;
}
}
return F_8 ( V_6 , V_15 ) ;
}
