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
if ( F_5 ( & V_7 -> V_14 . V_15 ,
V_16 , V_17 ,
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
F_8 ( struct V_1 * V_9 , int V_18 )
{
struct V_6 * V_7 = ( void * ) V_9 -> V_12 . V_15 . V_19 ;
F_7 ( & V_7 -> V_8 ) ;
return V_18 ;
}
T_1
F_9 ( struct V_20 * V_21 )
{
switch ( V_21 -> V_12 . V_22 . V_23 ) {
case V_24 :
return V_25 ;
case V_26 :
case V_27 :
case V_28 :
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
case V_34 :
case V_35 :
return V_36 ;
}
return 0x0000 ;
}
static void
F_10 ( struct V_37 * V_38 ,
struct V_39 * V_40 )
{
F_11 ( & V_40 -> V_15 ) ;
F_12 ( & V_38 -> V_41 , & V_40 -> V_42 ) ;
F_13 ( & V_40 -> V_43 ) ;
F_6 ( V_40 ) ;
}
static void
F_14 ( struct V_1 * V_9 ,
struct V_37 * V_38 )
{
struct V_39 * V_40 , * V_44 ;
if ( V_38 -> V_38 && V_38 -> V_40 )
F_15 ( V_38 -> V_38 ) ;
F_16 (ntfy, temp, &chan->notifiers, head) {
F_10 ( V_38 , V_40 ) ;
}
if ( V_38 -> V_40 ) {
F_17 ( V_38 -> V_40 , & V_38 -> V_45 ) ;
F_18 ( V_38 -> V_40 ) ;
F_19 ( & V_38 -> V_40 -> V_46 ) ;
}
if ( V_38 -> V_41 . V_47 )
F_20 ( & V_38 -> V_41 ) ;
if ( V_38 -> V_38 ) {
V_9 -> V_48 &= ~ ( 1ULL << ( V_38 -> V_38 -> V_49 . V_50 & 0xffff ) ) ;
F_15 ( V_38 -> V_38 ) ;
F_21 ( & V_38 -> V_38 ) ;
}
F_13 ( & V_38 -> V_43 ) ;
F_6 ( V_38 ) ;
}
void
F_22 ( struct V_1 * V_9 )
{
struct V_6 * V_7 = ( void * ) V_9 -> V_12 . V_15 . V_19 ;
struct V_37 * V_38 , * V_44 ;
F_16 (chan, temp, &abi16->channels, head) {
F_14 ( V_9 , V_38 ) ;
}
F_23 ( & V_9 -> V_12 ) ;
F_6 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
int
F_24 ( T_2 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_20 * V_21 = V_20 ( V_5 ) ;
struct V_51 * V_12 = & V_21 -> V_12 ;
struct V_52 * V_53 = F_25 ( V_12 ) ;
struct V_54 * V_55 = V_56 ;
switch ( V_55 -> V_57 ) {
case V_58 :
V_55 -> V_59 = V_12 -> V_22 . V_60 ;
break;
case V_61 :
if ( F_26 ( V_12 ) -> V_62 -> V_63 )
V_55 -> V_59 = V_5 -> V_64 -> V_65 ;
else
V_55 -> V_59 = 0 ;
break;
case V_66 :
if ( F_26 ( V_12 ) -> V_62 -> V_63 )
V_55 -> V_59 = V_5 -> V_64 -> V_12 ;
else
V_55 -> V_59 = 0 ;
break;
case V_67 :
if ( ! F_26 ( V_12 ) -> V_62 -> V_63 )
V_55 -> V_59 = 3 ;
else
if ( F_27 ( V_5 ) )
V_55 -> V_59 = 0 ;
else
if ( ! F_28 ( V_5 -> V_64 ) )
V_55 -> V_59 = 1 ;
else
V_55 -> V_59 = 2 ;
break;
case V_68 :
V_55 -> V_59 = V_21 -> V_46 . V_69 ;
break;
case V_70 :
V_55 -> V_59 = V_21 -> V_46 . V_71 ;
break;
case V_72 :
V_55 -> V_59 = 0 ;
break;
case V_73 :
V_55 -> V_59 = F_29 ( V_12 ) ;
break;
case V_74 :
V_55 -> V_59 = 1 ;
break;
case V_75 :
V_55 -> V_59 = 1 ;
break;
case V_76 :
V_55 -> V_59 = F_30 ( V_53 ) ;
break;
default:
F_31 ( V_77 , V_7 , L_1 , V_55 -> V_57 ) ;
return - V_78 ;
}
return 0 ;
}
int
F_32 ( T_2 )
{
return - V_78 ;
}
int
F_33 ( T_2 )
{
struct V_79 * V_80 = V_56 ;
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_20 * V_21 = V_20 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_37 * V_38 ;
struct V_51 * V_12 ;
int V_18 ;
if ( F_34 ( ! V_9 ) )
return - V_81 ;
if ( ! V_21 -> V_82 )
return F_8 ( V_9 , - V_83 ) ;
V_12 = & V_9 -> V_12 ;
if ( V_12 -> V_22 . V_23 >= V_34 ) {
if ( V_80 -> V_84 != ~ 0 )
V_80 -> V_84 = V_85 ;
else
V_80 -> V_84 = V_80 -> V_86 ;
V_80 -> V_86 = 0 ;
if ( V_80 -> V_84 == V_85 )
V_80 -> V_86 = 1 ;
}
if ( V_80 -> V_84 == ~ 0 || V_80 -> V_86 == ~ 0 )
return F_8 ( V_9 , - V_78 ) ;
V_80 -> V_82 = F_35 ( ~ V_9 -> V_48 ) ;
if ( ~ V_9 -> V_48 == 0 )
return F_8 ( V_9 , - V_87 ) ;
V_38 = F_3 ( sizeof( * V_38 ) , V_10 ) ;
if ( ! V_38 )
return F_8 ( V_9 , - V_81 ) ;
F_4 ( & V_38 -> V_88 ) ;
F_36 ( & V_38 -> V_43 , & V_9 -> V_13 ) ;
V_9 -> V_48 |= ( 1ULL << V_80 -> V_82 ) ;
V_18 = F_37 ( V_21 , V_12 ,
F_38 ( V_80 -> V_82 ) ,
V_80 -> V_84 ,
V_80 -> V_86 , & V_38 -> V_38 ) ;
if ( V_18 )
goto V_89;
if ( V_12 -> V_22 . V_23 >= V_31 )
V_80 -> V_90 = V_91 |
V_92 ;
else
if ( V_38 -> V_38 -> V_93 . V_94 -> V_95 . V_96 . V_97 == V_98 )
V_80 -> V_90 = V_91 ;
else
V_80 -> V_90 = V_92 ;
if ( V_12 -> V_22 . V_23 < V_26 ) {
V_80 -> V_99 [ 0 ] . V_50 = 0x00000000 ;
V_80 -> V_99 [ 0 ] . V_100 = 0x0000 ;
V_80 -> V_99 [ 1 ] . V_50 = V_38 -> V_38 -> V_101 . V_50 ;
V_80 -> V_99 [ 1 ] . V_100 = 0x506e ;
V_80 -> V_102 = 2 ;
}
V_18 = F_39 ( V_5 , V_103 , 0 , V_92 ,
0 , 0 , & V_38 -> V_40 ) ;
if ( V_18 == 0 )
V_18 = F_40 ( V_38 -> V_40 , V_104 , false ) ;
if ( V_18 )
goto V_89;
if ( V_12 -> V_22 . V_23 >= V_31 ) {
V_18 = F_41 ( V_38 -> V_40 , V_7 -> V_105 ,
& V_38 -> V_45 ) ;
if ( V_18 )
goto V_89;
}
V_18 = F_42 ( V_3 , & V_38 -> V_40 -> V_46 ,
& V_80 -> V_106 ) ;
if ( V_18 )
goto V_89;
V_18 = F_43 ( & V_38 -> V_41 , 0 , V_103 , 1 ) ;
V_89:
if ( V_18 )
F_14 ( V_9 , V_38 ) ;
return F_8 ( V_9 , V_18 ) ;
}
static struct V_37 *
V_37 ( struct V_1 * V_9 , int V_82 )
{
struct V_37 * V_38 ;
F_44 (chan, &abi16->channels, head) {
if ( V_38 -> V_38 -> V_49 . V_50 == F_38 ( V_82 ) )
return V_38 ;
}
return NULL ;
}
int
F_45 ( T_2 )
{
struct V_107 * V_108 = V_56 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_37 * V_38 ;
if ( F_34 ( ! V_9 ) )
return - V_81 ;
V_38 = V_37 ( V_9 , V_108 -> V_82 ) ;
if ( ! V_38 )
return F_8 ( V_9 , - V_109 ) ;
F_14 ( V_9 , V_38 ) ;
return F_8 ( V_9 , 0 ) ;
}
int
F_46 ( T_2 )
{
struct V_110 * V_80 = V_56 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_111 * V_19 ;
struct V_112 * V_113 ;
T_1 V_114 = 0 ;
int V_18 , V_115 ;
if ( F_34 ( ! V_9 ) )
return - V_81 ;
if ( V_80 -> V_50 == ~ 0 )
return F_8 ( V_9 , - V_78 ) ;
V_19 = V_9 -> V_12 . V_15 . V_19 ;
V_38 = V_37 ( V_9 , V_80 -> V_82 ) ;
if ( ! V_38 )
return F_8 ( V_9 , - V_109 ) ;
V_18 = F_47 ( & V_38 -> V_38 -> V_49 , & V_113 ) ;
if ( V_18 < 0 )
return F_8 ( V_9 , V_18 ) ;
if ( ( V_80 -> V_116 & 0x00ff ) == 0x006e ) {
for ( V_115 = 0 ; ! V_114 && V_115 < V_18 ; V_115 ++ ) {
switch ( V_113 [ V_115 ] . V_114 ) {
case V_25 :
case V_30 :
case V_32 :
case V_36 :
V_114 = V_113 [ V_115 ] . V_114 ;
break;
default:
break;
}
}
} else
if ( ( V_80 -> V_116 & 0x00ff ) == 0x00b1 ) {
for ( V_115 = 0 ; V_115 < V_18 ; V_115 ++ ) {
if ( ( V_113 [ V_115 ] . V_114 & 0x00ff ) == 0x00b1 ) {
V_114 = V_113 [ V_115 ] . V_114 ;
break;
}
}
} else
if ( ( V_80 -> V_116 & 0x00ff ) == 0x00b2 ) {
for ( V_115 = 0 ; V_115 < V_18 ; V_115 ++ ) {
if ( ( V_113 [ V_115 ] . V_114 & 0x00ff ) == 0x00b2 ) {
V_114 = V_113 [ V_115 ] . V_114 ;
break;
}
}
} else
if ( ( V_80 -> V_116 & 0x00ff ) == 0x00b3 ) {
for ( V_115 = 0 ; V_115 < V_18 ; V_115 ++ ) {
if ( ( V_113 [ V_115 ] . V_114 & 0x00ff ) == 0x00b3 ) {
V_114 = V_113 [ V_115 ] . V_114 ;
break;
}
}
} else {
V_114 = V_80 -> V_116 ;
}
F_48 ( & V_113 ) ;
if ( ! V_114 )
return F_8 ( V_9 , - V_78 ) ;
V_40 = F_3 ( sizeof( * V_40 ) , V_10 ) ;
if ( ! V_40 )
return F_8 ( V_9 , - V_81 ) ;
F_36 ( & V_40 -> V_43 , & V_38 -> V_88 ) ;
V_19 -> V_117 = V_118 ;
V_18 = F_49 ( & V_38 -> V_38 -> V_49 , V_80 -> V_50 , V_114 ,
NULL , 0 , & V_40 -> V_15 ) ;
V_19 -> V_117 = V_119 ;
if ( V_18 )
F_10 ( V_38 , V_40 ) ;
return F_8 ( V_9 , V_18 ) ;
}
int
F_50 ( T_2 )
{
struct V_120 * V_22 = V_56 ;
struct V_20 * V_21 = V_20 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
struct V_51 * V_12 = & V_9 -> V_12 ;
struct V_111 * V_19 ;
struct V_121 args = {} ;
int V_18 ;
if ( F_34 ( ! V_9 ) )
return - V_81 ;
if ( F_34 ( V_12 -> V_22 . V_23 >= V_33 ) )
return F_8 ( V_9 , - V_78 ) ;
V_19 = V_9 -> V_12 . V_15 . V_19 ;
V_38 = V_37 ( V_9 , V_22 -> V_82 ) ;
if ( ! V_38 )
return F_8 ( V_9 , - V_109 ) ;
V_40 = F_3 ( sizeof( * V_40 ) , V_10 ) ;
if ( ! V_40 )
return F_8 ( V_9 , - V_81 ) ;
F_36 ( & V_40 -> V_43 , & V_38 -> V_88 ) ;
V_18 = F_51 ( & V_38 -> V_41 , 0 , 1 , V_22 -> V_122 , V_22 -> V_122 , 1 ,
& V_40 -> V_42 ) ;
if ( V_18 )
goto V_89;
args . V_123 = V_40 -> V_42 -> V_124 ;
args . V_125 = V_40 -> V_42 -> V_124 + V_40 -> V_42 -> V_126 - 1 ;
if ( V_12 -> V_22 . V_23 >= V_31 ) {
args . V_127 = V_128 ;
args . V_129 = V_130 ;
args . V_123 += V_38 -> V_45 . V_124 ;
args . V_125 += V_38 -> V_45 . V_124 ;
} else
if ( V_21 -> V_131 . V_132 ) {
args . V_127 = V_133 ;
args . V_129 = V_134 ;
args . V_123 += V_21 -> V_131 . V_14 + V_38 -> V_40 -> V_95 . V_124 ;
args . V_125 += V_21 -> V_131 . V_14 + V_38 -> V_40 -> V_95 . V_124 ;
} else {
args . V_127 = V_128 ;
args . V_129 = V_134 ;
args . V_123 += V_38 -> V_40 -> V_95 . V_124 ;
args . V_125 += V_38 -> V_40 -> V_95 . V_124 ;
}
V_19 -> V_117 = V_118 ;
V_19 -> V_135 = true ;
V_18 = F_49 ( & V_38 -> V_38 -> V_49 , V_22 -> V_50 ,
V_136 , & args , sizeof( args ) ,
& V_40 -> V_15 ) ;
V_19 -> V_135 = false ;
V_19 -> V_117 = V_119 ;
if ( V_18 )
goto V_89;
V_22 -> V_124 = V_40 -> V_42 -> V_124 ;
V_89:
if ( V_18 )
F_10 ( V_38 , V_40 ) ;
return F_8 ( V_9 , V_18 ) ;
}
int
F_52 ( T_2 )
{
struct V_137 * V_138 = V_56 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_37 * V_38 ;
struct V_39 * V_40 ;
int V_18 = - V_109 ;
if ( F_34 ( ! V_9 ) )
return - V_81 ;
V_38 = V_37 ( V_9 , V_138 -> V_82 ) ;
if ( ! V_38 )
return F_8 ( V_9 , - V_78 ) ;
F_15 ( V_38 -> V_38 ) ;
F_44 (ntfy, &chan->notifiers, head) {
if ( V_40 -> V_15 . V_50 == V_138 -> V_50 ) {
F_10 ( V_38 , V_40 ) ;
V_18 = 0 ;
break;
}
}
return F_8 ( V_9 , V_18 ) ;
}
