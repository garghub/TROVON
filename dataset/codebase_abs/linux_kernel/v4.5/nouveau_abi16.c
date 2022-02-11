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
else
V_75 -> V_79 = V_75 -> V_81 ;
V_75 -> V_81 = 0 ;
if ( V_75 -> V_79 == V_80 )
V_75 -> V_81 = 1 ;
}
if ( V_75 -> V_79 == ~ 0 || V_75 -> V_81 == ~ 0 )
return F_8 ( V_6 , - V_73 ) ;
V_35 = F_1 ( sizeof( * V_35 ) , V_7 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_76 ) ;
F_2 ( & V_35 -> V_82 ) ;
F_35 ( & V_35 -> V_40 , & V_6 -> V_10 ) ;
V_15 = F_36 ( V_18 , V_9 , V_75 -> V_79 ,
V_75 -> V_81 , & V_35 -> V_35 ) ;
if ( V_15 )
goto V_83;
V_75 -> V_77 = V_35 -> V_35 -> V_84 ;
if ( V_9 -> V_19 . V_20 >= V_28 )
V_75 -> V_85 = V_86 |
V_87 ;
else
if ( V_35 -> V_35 -> V_88 . V_89 -> V_90 . V_91 . V_92 == V_93 )
V_75 -> V_85 = V_86 ;
else
V_75 -> V_85 = V_87 ;
if ( V_9 -> V_19 . V_20 < V_23 ) {
V_75 -> V_94 [ 0 ] . V_95 = 0x00000000 ;
V_75 -> V_94 [ 0 ] . V_96 = 0x0000 ;
V_75 -> V_94 [ 1 ] . V_95 = V_35 -> V_35 -> V_97 . V_95 ;
V_75 -> V_94 [ 1 ] . V_96 = 0x506e ;
V_75 -> V_98 = 2 ;
}
V_15 = F_37 ( V_45 , V_99 , 0 , V_87 ,
0 , 0 , & V_35 -> V_37 ) ;
if ( V_15 == 0 )
V_15 = F_38 ( V_35 -> V_37 , V_100 , false ) ;
if ( V_15 )
goto V_83;
if ( V_9 -> V_19 . V_20 >= V_28 ) {
V_15 = F_39 ( V_35 -> V_37 , V_5 -> V_101 ,
& V_35 -> V_42 ) ;
if ( V_15 )
goto V_83;
}
V_15 = F_40 ( V_3 , & V_35 -> V_37 -> V_43 ,
& V_75 -> V_102 ) ;
if ( V_15 )
goto V_83;
V_15 = F_41 ( & V_35 -> V_38 , 0 , V_99 , 1 ) ;
V_83:
if ( V_15 )
F_14 ( V_6 , V_35 ) ;
return F_8 ( V_6 , V_15 ) ;
}
static struct V_34 *
V_34 ( struct V_1 * V_6 , int V_77 )
{
struct V_34 * V_35 ;
F_42 (chan, &abi16->channels, head) {
if ( V_35 -> V_35 -> V_84 == V_77 )
return V_35 ;
}
return NULL ;
}
int
F_43 ( struct V_2 * V_3 , void * V_51 , T_3 V_103 )
{
union {
struct V_104 V_105 ;
} * args = V_51 ;
struct V_34 * V_35 ;
struct V_1 * V_6 ;
int V_15 = - V_106 ;
if ( ! ( V_15 = F_44 ( V_15 , & V_51 , & V_103 , args -> V_105 , 0 , 0 , true ) ) ) {
switch ( args -> V_105 . type ) {
case V_107 :
case V_108 :
case V_109 :
break;
default:
return - V_110 ;
}
} else
return V_15 ;
if ( ! ( V_6 = V_1 ( V_3 ) ) )
return - V_76 ;
if ( args -> V_105 . V_111 != ~ 0ULL ) {
if ( ! ( V_35 = V_34 ( V_6 , args -> V_105 . V_111 ) ) )
return - V_73 ;
args -> V_105 . V_12 = F_45 ( & V_35 -> V_35 -> V_112 ) ;
args -> V_105 . V_113 = V_114 ;
return 0 ;
}
args -> V_105 . V_12 = F_45 ( & V_6 -> V_9 . V_12 ) ;
args -> V_105 . V_113 = V_114 ;
return 0 ;
}
int
F_46 ( T_2 )
{
struct V_115 * V_116 = V_51 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
V_35 = V_34 ( V_6 , V_116 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_117 ) ;
F_14 ( V_6 , V_35 ) ;
return F_8 ( V_6 , 0 ) ;
}
int
F_47 ( T_2 )
{
struct V_118 * V_75 = V_51 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_119 * V_16 ;
struct V_120 * V_121 ;
T_1 V_122 = 0 ;
int V_15 , V_123 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
if ( V_75 -> V_95 == ~ 0 )
return F_8 ( V_6 , - V_73 ) ;
V_16 = V_6 -> V_9 . V_12 . V_16 ;
V_35 = V_34 ( V_6 , V_75 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_117 ) ;
V_15 = F_48 ( & V_35 -> V_35 -> V_112 , & V_121 ) ;
if ( V_15 < 0 )
return F_8 ( V_6 , V_15 ) ;
if ( ( V_75 -> V_124 & 0x00ff ) == 0x006e ) {
for ( V_123 = 0 ; ! V_122 && V_123 < V_15 ; V_123 ++ ) {
switch ( V_121 [ V_123 ] . V_122 ) {
case V_22 :
case V_27 :
case V_29 :
case V_33 :
V_122 = V_121 [ V_123 ] . V_122 ;
break;
default:
break;
}
}
} else
if ( ( V_75 -> V_124 & 0x00ff ) == 0x00b1 ) {
for ( V_123 = 0 ; V_123 < V_15 ; V_123 ++ ) {
if ( ( V_121 [ V_123 ] . V_122 & 0x00ff ) == 0x00b1 ) {
V_122 = V_121 [ V_123 ] . V_122 ;
break;
}
}
} else
if ( ( V_75 -> V_124 & 0x00ff ) == 0x00b2 ) {
for ( V_123 = 0 ; V_123 < V_15 ; V_123 ++ ) {
if ( ( V_121 [ V_123 ] . V_122 & 0x00ff ) == 0x00b2 ) {
V_122 = V_121 [ V_123 ] . V_122 ;
break;
}
}
} else
if ( ( V_75 -> V_124 & 0x00ff ) == 0x00b3 ) {
for ( V_123 = 0 ; V_123 < V_15 ; V_123 ++ ) {
if ( ( V_121 [ V_123 ] . V_122 & 0x00ff ) == 0x00b3 ) {
V_122 = V_121 [ V_123 ] . V_122 ;
break;
}
}
} else {
V_122 = V_75 -> V_124 ;
}
F_49 ( & V_121 ) ;
if ( ! V_122 )
return F_8 ( V_6 , - V_73 ) ;
V_37 = F_1 ( sizeof( * V_37 ) , V_7 ) ;
if ( ! V_37 )
return F_8 ( V_6 , - V_76 ) ;
F_35 ( & V_37 -> V_40 , & V_35 -> V_82 ) ;
V_16 -> V_125 = V_126 ;
V_15 = F_50 ( & V_35 -> V_35 -> V_112 , V_75 -> V_95 , V_122 ,
NULL , 0 , & V_37 -> V_12 ) ;
V_16 -> V_125 = V_127 ;
if ( V_15 )
F_10 ( V_35 , V_37 ) ;
return F_8 ( V_6 , V_15 ) ;
}
int
F_51 ( T_2 )
{
struct V_128 * V_19 = V_51 ;
struct V_17 * V_18 = V_17 ( V_45 ) ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
struct V_46 * V_9 = & V_6 -> V_9 ;
struct V_119 * V_16 ;
struct V_129 args = {} ;
int V_15 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
if ( F_34 ( V_9 -> V_19 . V_20 >= V_30 ) )
return F_8 ( V_6 , - V_73 ) ;
V_16 = V_6 -> V_9 . V_12 . V_16 ;
V_35 = V_34 ( V_6 , V_19 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_117 ) ;
V_37 = F_1 ( sizeof( * V_37 ) , V_7 ) ;
if ( ! V_37 )
return F_8 ( V_6 , - V_76 ) ;
F_35 ( & V_37 -> V_40 , & V_35 -> V_82 ) ;
V_15 = F_52 ( & V_35 -> V_38 , 0 , 1 , V_19 -> V_103 , V_19 -> V_103 , 1 ,
& V_37 -> V_39 ) ;
if ( V_15 )
goto V_83;
args . V_130 = V_37 -> V_39 -> V_131 ;
args . V_132 = V_37 -> V_39 -> V_131 + V_37 -> V_39 -> V_133 - 1 ;
if ( V_9 -> V_19 . V_20 >= V_28 ) {
args . V_134 = V_135 ;
args . V_136 = V_137 ;
args . V_130 += V_35 -> V_42 . V_131 ;
args . V_132 += V_35 -> V_42 . V_131 ;
} else
if ( V_18 -> V_138 . V_139 ) {
args . V_134 = V_140 ;
args . V_136 = V_141 ;
args . V_130 += V_18 -> V_138 . V_11 + V_35 -> V_37 -> V_90 . V_131 ;
args . V_132 += V_18 -> V_138 . V_11 + V_35 -> V_37 -> V_90 . V_131 ;
} else {
args . V_134 = V_135 ;
args . V_136 = V_141 ;
args . V_130 += V_35 -> V_37 -> V_90 . V_131 ;
args . V_132 += V_35 -> V_37 -> V_90 . V_131 ;
}
V_16 -> V_125 = V_126 ;
V_16 -> V_142 = true ;
V_15 = F_50 ( & V_35 -> V_35 -> V_112 , V_19 -> V_95 ,
V_143 , & args , sizeof( args ) ,
& V_37 -> V_12 ) ;
V_16 -> V_142 = false ;
V_16 -> V_125 = V_127 ;
if ( V_15 )
goto V_83;
V_19 -> V_131 = V_37 -> V_39 -> V_131 ;
V_83:
if ( V_15 )
F_10 ( V_35 , V_37 ) ;
return F_8 ( V_6 , V_15 ) ;
}
int
F_53 ( T_2 )
{
struct V_144 * V_145 = V_51 ;
struct V_1 * V_6 = F_5 ( V_3 ) ;
struct V_34 * V_35 ;
struct V_36 * V_37 ;
int V_15 = - V_117 ;
if ( F_34 ( ! V_6 ) )
return - V_76 ;
V_35 = V_34 ( V_6 , V_145 -> V_77 ) ;
if ( ! V_35 )
return F_8 ( V_6 , - V_73 ) ;
F_15 ( V_35 -> V_35 ) ;
F_42 (ntfy, &chan->notifiers, head) {
if ( V_37 -> V_12 . V_95 == V_145 -> V_95 ) {
F_10 ( V_35 , V_37 ) ;
V_15 = 0 ;
break;
}
}
return F_8 ( V_6 , V_15 ) ;
}
