struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_6 * V_7 = V_6 ( V_3 ) ;
F_2 ( & V_7 -> V_8 ) ;
if ( ! V_7 -> V_9 ) {
struct V_1 * V_9 ;
V_7 -> V_9 = V_9 = F_3 ( sizeof( * V_9 ) , V_10 ) ;
if ( V_7 -> V_9 ) {
F_4 ( & V_9 -> V_11 ) ;
V_9 -> V_12 = F_5 ( V_7 ) ;
if ( F_6 (abi16->client, NVDRM_CLIENT,
NVDRM_DEVICE, 0x0080 ,
&(struct nv_device_class) {
.device = ~0ULL ,
},
sizeof(struct nv_device_class),
&abi16->device) == 0 )
return V_7 -> V_9 ;
F_7 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
F_8 ( & V_7 -> V_8 ) ;
}
return V_7 -> V_9 ;
}
int
F_9 ( struct V_1 * V_9 , int V_13 )
{
struct V_6 * V_7 = ( void * ) V_9 -> V_12 ;
F_8 ( & V_7 -> V_8 ) ;
return V_13 ;
}
T_1
F_10 ( struct V_14 * V_15 )
{
switch ( F_11 ( V_15 -> V_16 ) -> V_17 ) {
case V_18 :
return 0x006e ;
case V_19 :
case V_20 :
case V_21 :
case V_22 :
return 0x016e ;
case V_23 :
return 0x506e ;
case V_24 :
case V_25 :
case V_26 :
return 0x906e ;
}
return 0x0000 ;
}
static void
F_12 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
F_13 ( & V_28 -> V_31 , & V_30 -> V_32 ) ;
F_14 ( & V_30 -> V_33 ) ;
F_7 ( V_30 ) ;
}
static void
F_15 ( struct V_1 * V_9 ,
struct V_27 * V_28 )
{
struct V_29 * V_30 , * V_34 ;
if ( V_28 -> V_28 && V_28 -> V_30 )
F_16 ( V_28 -> V_28 ) ;
F_17 (ntfy, temp, &chan->notifiers, head) {
F_12 ( V_28 , V_30 ) ;
}
if ( V_28 -> V_30 ) {
F_18 ( V_28 -> V_30 , & V_28 -> V_35 ) ;
F_19 ( V_28 -> V_30 -> V_36 ) ;
}
if ( V_28 -> V_31 . V_37 )
F_20 ( & V_28 -> V_31 ) ;
if ( V_28 -> V_28 ) {
V_9 -> V_38 &= ~ ( 1 << ( V_28 -> V_28 -> V_39 & 0xffff ) ) ;
F_21 ( & V_28 -> V_28 ) ;
}
F_14 ( & V_28 -> V_33 ) ;
F_7 ( V_28 ) ;
}
void
F_22 ( struct V_1 * V_9 )
{
struct V_6 * V_7 = ( void * ) V_9 -> V_12 ;
struct V_27 * V_28 , * V_34 ;
F_17 (chan, temp, &abi16->channels, head) {
F_15 ( V_9 , V_28 ) ;
}
F_23 ( V_9 -> V_12 , V_40 , V_41 ) ;
F_7 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
int
F_24 ( T_2 )
{
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_42 * V_16 = F_11 ( V_15 -> V_16 ) ;
struct V_43 * V_44 = V_43 ( V_16 ) ;
struct V_45 * V_46 = ( void * ) F_25 ( V_16 , V_47 ) ;
struct V_48 * V_49 = V_50 ;
switch ( V_49 -> V_51 ) {
case V_52 :
V_49 -> V_53 = V_16 -> V_54 ;
break;
case V_55 :
V_49 -> V_53 = V_5 -> V_56 ;
break;
case V_57 :
V_49 -> V_53 = V_5 -> V_58 ;
break;
case V_59 :
if ( F_26 ( V_5 ) )
V_49 -> V_53 = 0 ;
else
if ( ! F_27 ( V_5 -> V_60 ) )
V_49 -> V_53 = 1 ;
else
V_49 -> V_53 = 2 ;
break;
case V_61 :
V_49 -> V_53 = V_15 -> V_36 . V_62 ;
break;
case V_63 :
V_49 -> V_53 = V_15 -> V_36 . V_64 ;
break;
case V_65 :
V_49 -> V_53 = 0 ;
break;
case V_66 :
V_49 -> V_53 = V_44 -> V_67 ( V_44 ) ;
break;
case V_68 :
V_49 -> V_53 = 1 ;
break;
case V_69 :
V_49 -> V_53 = 1 ;
break;
case V_70 :
V_49 -> V_53 = V_46 -> V_71 ? V_46 -> V_71 ( V_46 ) : 0 ;
break;
default:
F_28 ( V_16 , L_1 , V_49 -> V_51 ) ;
return - V_72 ;
}
return 0 ;
}
int
F_29 ( T_2 )
{
return - V_72 ;
}
int
F_30 ( T_2 )
{
struct V_73 * V_74 = V_50 ;
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_27 * V_28 ;
struct V_75 * V_12 ;
struct V_42 * V_16 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_13 ;
if ( F_31 ( ! V_9 ) )
return - V_80 ;
if ( ! V_15 -> V_81 )
return F_9 ( V_9 , - V_82 ) ;
V_12 = F_32 ( V_9 -> V_12 ) ;
V_16 = F_11 ( V_9 -> V_16 ) ;
V_77 = V_76 ( V_16 ) ;
V_79 = V_78 ( V_16 ) ;
if ( V_16 -> V_17 >= V_26 ) {
if ( V_74 -> V_83 != ~ 0 )
V_74 -> V_83 = V_84 ;
else
V_74 -> V_83 = V_74 -> V_85 ;
V_74 -> V_85 = 0 ;
if ( V_74 -> V_83 == V_84 )
V_74 -> V_85 = 1 ;
}
if ( V_74 -> V_83 == ~ 0 || V_74 -> V_85 == ~ 0 )
return F_9 ( V_9 , - V_72 ) ;
V_74 -> V_81 = F_33 ( ~ V_9 -> V_38 ) ;
if ( ! V_74 -> V_81 -- )
return F_9 ( V_9 , - V_86 ) ;
V_28 = F_3 ( sizeof( * V_28 ) , V_10 ) ;
if ( ! V_28 )
return F_9 ( V_9 , - V_80 ) ;
F_4 ( & V_28 -> V_87 ) ;
F_34 ( & V_28 -> V_33 , & V_9 -> V_11 ) ;
V_9 -> V_38 |= ( 1 << V_74 -> V_81 ) ;
V_13 = F_35 ( V_15 , V_7 , V_41 , V_88 |
V_74 -> V_81 , V_74 -> V_83 ,
V_74 -> V_85 , & V_28 -> V_28 ) ;
if ( V_13 )
goto V_89;
if ( V_16 -> V_17 >= V_23 )
V_74 -> V_90 = V_91 |
V_92 ;
else
if ( V_28 -> V_28 -> V_93 . V_94 -> V_95 . V_96 . V_97 == V_98 )
V_74 -> V_90 = V_91 ;
else
V_74 -> V_90 = V_92 ;
if ( V_16 -> V_17 < V_24 ) {
V_74 -> V_99 [ 0 ] . V_39 = 0x00000000 ;
V_74 -> V_99 [ 0 ] . V_100 = 0x0000 ;
V_74 -> V_99 [ 1 ] . V_39 = V_101 ;
V_74 -> V_99 [ 1 ] . V_100 = 0x506e ;
V_74 -> V_102 = 2 ;
}
V_13 = F_36 ( V_5 , V_103 , 0 , V_92 ,
0 , 0 , & V_28 -> V_30 ) ;
if ( V_13 == 0 )
V_13 = F_37 ( V_28 -> V_30 , V_104 ) ;
if ( V_13 )
goto V_89;
if ( V_16 -> V_17 >= V_23 ) {
V_13 = F_38 ( V_28 -> V_30 , V_12 -> V_105 ,
& V_28 -> V_35 ) ;
if ( V_13 )
goto V_89;
}
V_13 = F_39 ( V_3 , V_28 -> V_30 -> V_36 ,
& V_74 -> V_106 ) ;
if ( V_13 )
goto V_89;
V_13 = F_40 ( & V_28 -> V_31 , 0 , V_103 , 1 ) ;
V_89:
if ( V_13 )
F_15 ( V_9 , V_28 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_41 ( T_2 )
{
struct V_107 * V_108 = V_50 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_27 * V_28 ;
int V_13 = - V_109 ;
if ( F_31 ( ! V_9 ) )
return - V_80 ;
F_42 (chan, &abi16->channels, head) {
if ( V_28 -> V_28 -> V_39 == ( V_88 | V_108 -> V_81 ) ) {
F_15 ( V_9 , V_28 ) ;
return F_9 ( V_9 , 0 ) ;
}
}
return F_9 ( V_9 , V_13 ) ;
}
int
F_43 ( T_2 )
{
struct V_110 * V_74 = V_50 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_111 * V_112 ;
int V_13 ;
if ( F_31 ( ! V_9 ) )
return - V_80 ;
if ( V_74 -> V_39 == ~ 0 )
return F_9 ( V_9 , - V_72 ) ;
if ( V_74 -> V_113 == 0x506e ) {
V_74 -> V_113 = F_10 ( V_15 ) ;
if ( V_74 -> V_113 == 0x906e )
return F_9 ( V_9 , 0 ) ;
}
V_13 = F_6 ( V_9 -> V_12 , V_88 | V_74 -> V_81 ,
V_74 -> V_39 , V_74 -> V_113 , NULL , 0 , & V_112 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_44 ( T_2 )
{
struct V_114 * V_115 = V_50 ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_42 * V_16 = F_11 ( V_15 -> V_16 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_27 * V_28 = NULL , * V_34 ;
struct V_29 * V_30 ;
struct V_111 * V_112 ;
struct V_116 args = {} ;
int V_13 ;
if ( F_31 ( ! V_9 ) )
return - V_80 ;
if ( F_31 ( F_11 ( V_9 -> V_16 ) -> V_17 >= V_24 ) )
return F_9 ( V_9 , - V_72 ) ;
F_42 (temp, &abi16->channels, head) {
if ( V_34 -> V_28 -> V_39 == ( V_88 | V_115 -> V_81 ) ) {
V_28 = V_34 ;
break;
}
}
if ( ! V_28 )
return F_9 ( V_9 , - V_109 ) ;
V_30 = F_3 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return F_9 ( V_9 , - V_80 ) ;
F_34 ( & V_30 -> V_33 , & V_28 -> V_87 ) ;
V_30 -> V_39 = V_115 -> V_39 ;
V_13 = F_45 ( & V_28 -> V_31 , 1 , V_115 -> V_117 , V_115 -> V_117 , 1 ,
& V_30 -> V_32 ) ;
if ( V_13 )
goto V_89;
args . V_118 = V_30 -> V_32 -> V_119 ;
args . V_120 = V_30 -> V_32 -> V_119 + V_30 -> V_32 -> V_121 - 1 ;
if ( V_16 -> V_17 >= V_23 ) {
args . V_122 = V_123 | V_124 ;
args . V_118 += V_28 -> V_35 . V_119 ;
args . V_120 += V_28 -> V_35 . V_119 ;
} else
if ( V_15 -> V_125 . V_126 == V_127 ) {
args . V_122 = V_128 | V_129 ;
args . V_118 += V_15 -> V_125 . V_130 + V_28 -> V_30 -> V_95 . V_119 ;
args . V_120 += V_15 -> V_125 . V_130 + V_28 -> V_30 -> V_95 . V_119 ;
} else {
args . V_122 = V_123 | V_129 ;
args . V_118 += V_28 -> V_30 -> V_95 . V_119 ;
args . V_120 += V_28 -> V_30 -> V_95 . V_119 ;
}
V_13 = F_6 ( V_9 -> V_12 , V_28 -> V_28 -> V_39 ,
V_30 -> V_39 , 0x003d , & args ,
sizeof( args ) , & V_112 ) ;
if ( V_13 )
goto V_89;
V_89:
if ( V_13 )
F_12 ( V_28 , V_30 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_46 ( T_2 )
{
struct V_131 * V_132 = V_50 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_27 * V_28 = NULL , * V_34 ;
struct V_29 * V_30 ;
int V_13 ;
if ( F_31 ( ! V_9 ) )
return - V_80 ;
F_42 (temp, &abi16->channels, head) {
if ( V_34 -> V_28 -> V_39 == ( V_88 | V_132 -> V_81 ) ) {
V_28 = V_34 ;
break;
}
}
if ( ! V_28 )
return F_9 ( V_9 , - V_109 ) ;
F_16 ( V_28 -> V_28 ) ;
V_13 = F_23 ( V_9 -> V_12 , V_28 -> V_28 -> V_39 , V_132 -> V_39 ) ;
if ( V_13 )
return F_9 ( V_9 , V_13 ) ;
F_42 (ntfy, &chan->notifiers, head) {
if ( V_30 -> V_39 == V_132 -> V_39 ) {
F_13 ( & V_28 -> V_31 , & V_30 -> V_32 ) ;
F_14 ( & V_30 -> V_33 ) ;
break;
}
}
return F_9 ( V_9 , 0 ) ;
}
