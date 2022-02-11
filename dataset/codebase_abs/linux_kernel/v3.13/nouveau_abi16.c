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
case V_23 :
return 0x016e ;
case V_24 :
return 0x506e ;
case V_25 :
case V_26 :
case V_27 :
return 0x906e ;
}
return 0x0000 ;
}
static void
F_12 ( struct V_28 * V_29 ,
struct V_30 * V_31 )
{
F_13 ( & V_29 -> V_32 , & V_31 -> V_33 ) ;
F_14 ( & V_31 -> V_34 ) ;
F_7 ( V_31 ) ;
}
static void
F_15 ( struct V_1 * V_9 ,
struct V_28 * V_29 )
{
struct V_30 * V_31 , * V_35 ;
if ( V_29 -> V_29 && V_29 -> V_31 )
F_16 ( V_29 -> V_29 ) ;
F_17 (ntfy, temp, &chan->notifiers, head) {
F_12 ( V_29 , V_31 ) ;
}
if ( V_29 -> V_31 ) {
F_18 ( V_29 -> V_31 , & V_29 -> V_36 ) ;
F_19 ( V_29 -> V_31 ) ;
F_20 ( & V_29 -> V_31 -> V_37 ) ;
}
if ( V_29 -> V_32 . V_38 )
F_21 ( & V_29 -> V_32 ) ;
if ( V_29 -> V_29 ) {
V_9 -> V_39 &= ~ ( 1 << ( V_29 -> V_29 -> V_40 & 0xffff ) ) ;
F_22 ( & V_29 -> V_29 ) ;
}
F_14 ( & V_29 -> V_34 ) ;
F_7 ( V_29 ) ;
}
void
F_23 ( struct V_1 * V_9 )
{
struct V_6 * V_7 = ( void * ) V_9 -> V_12 ;
struct V_28 * V_29 , * V_35 ;
F_17 (chan, temp, &abi16->channels, head) {
F_15 ( V_9 , V_29 ) ;
}
F_24 ( V_9 -> V_12 , V_41 , V_42 ) ;
F_7 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
int
F_25 ( T_2 )
{
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_43 * V_16 = F_11 ( V_15 -> V_16 ) ;
struct V_44 * V_45 = V_44 ( V_16 ) ;
struct V_46 * V_47 = ( void * ) F_26 ( V_16 , V_48 ) ;
struct V_49 * V_50 = V_51 ;
switch ( V_50 -> V_52 ) {
case V_53 :
V_50 -> V_54 = V_16 -> V_55 ;
break;
case V_56 :
V_50 -> V_54 = V_5 -> V_57 -> V_58 ;
break;
case V_59 :
V_50 -> V_54 = V_5 -> V_57 -> V_16 ;
break;
case V_60 :
if ( F_27 ( V_5 ) )
V_50 -> V_54 = 0 ;
else
if ( ! F_28 ( V_5 -> V_57 ) )
V_50 -> V_54 = 1 ;
else
V_50 -> V_54 = 2 ;
break;
case V_61 :
V_50 -> V_54 = V_15 -> V_37 . V_62 ;
break;
case V_63 :
V_50 -> V_54 = V_15 -> V_37 . V_64 ;
break;
case V_65 :
V_50 -> V_54 = 0 ;
break;
case V_66 :
V_50 -> V_54 = V_45 -> V_67 ( V_45 ) ;
break;
case V_68 :
V_50 -> V_54 = 1 ;
break;
case V_69 :
V_50 -> V_54 = 1 ;
break;
case V_70 :
V_50 -> V_54 = V_47 -> V_71 ? V_47 -> V_71 ( V_47 ) : 0 ;
break;
default:
F_29 ( V_16 , L_1 , V_50 -> V_52 ) ;
return - V_72 ;
}
return 0 ;
}
int
F_30 ( T_2 )
{
return - V_72 ;
}
int
F_31 ( T_2 )
{
struct V_73 * V_74 = V_51 ;
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_28 * V_29 ;
struct V_75 * V_12 ;
struct V_43 * V_16 ;
struct V_76 * V_77 ;
struct V_78 * V_79 ;
int V_13 ;
if ( F_32 ( ! V_9 ) )
return - V_80 ;
if ( ! V_15 -> V_81 )
return F_9 ( V_9 , - V_82 ) ;
V_12 = F_33 ( V_9 -> V_12 ) ;
V_16 = F_11 ( V_9 -> V_16 ) ;
V_77 = V_76 ( V_16 ) ;
V_79 = V_78 ( V_16 ) ;
if ( V_16 -> V_17 >= V_27 ) {
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
V_74 -> V_81 = F_34 ( ~ V_9 -> V_39 ) ;
if ( ! V_74 -> V_81 -- )
return F_9 ( V_9 , - V_86 ) ;
V_29 = F_3 ( sizeof( * V_29 ) , V_10 ) ;
if ( ! V_29 )
return F_9 ( V_9 , - V_80 ) ;
F_4 ( & V_29 -> V_87 ) ;
F_35 ( & V_29 -> V_34 , & V_9 -> V_11 ) ;
V_9 -> V_39 |= ( 1 << V_74 -> V_81 ) ;
V_13 = F_36 ( V_15 , V_7 , V_42 , V_88 |
V_74 -> V_81 , V_74 -> V_83 ,
V_74 -> V_85 , & V_29 -> V_29 ) ;
if ( V_13 )
goto V_89;
if ( V_16 -> V_17 >= V_24 )
V_74 -> V_90 = V_91 |
V_92 ;
else
if ( V_29 -> V_29 -> V_93 . V_94 -> V_95 . V_96 . V_97 == V_98 )
V_74 -> V_90 = V_91 ;
else
V_74 -> V_90 = V_92 ;
if ( V_16 -> V_17 < V_19 ) {
V_74 -> V_99 [ 0 ] . V_40 = 0x00000000 ;
V_74 -> V_99 [ 0 ] . V_100 = 0x0000 ;
V_74 -> V_99 [ 1 ] . V_40 = V_101 ;
V_74 -> V_99 [ 1 ] . V_100 = 0x506e ;
V_74 -> V_102 = 2 ;
}
V_13 = F_37 ( V_5 , V_103 , 0 , V_92 ,
0 , 0 , & V_29 -> V_31 ) ;
if ( V_13 == 0 )
V_13 = F_38 ( V_29 -> V_31 , V_104 ) ;
if ( V_13 )
goto V_89;
if ( V_16 -> V_17 >= V_24 ) {
V_13 = F_39 ( V_29 -> V_31 , V_12 -> V_105 ,
& V_29 -> V_36 ) ;
if ( V_13 )
goto V_89;
}
V_13 = F_40 ( V_3 , & V_29 -> V_31 -> V_37 ,
& V_74 -> V_106 ) ;
if ( V_13 )
goto V_89;
V_13 = F_41 ( & V_29 -> V_32 , 0 , V_103 , 1 ) ;
V_89:
if ( V_13 )
F_15 ( V_9 , V_29 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_42 ( T_2 )
{
struct V_107 * V_108 = V_51 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_28 * V_29 ;
int V_13 = - V_109 ;
if ( F_32 ( ! V_9 ) )
return - V_80 ;
F_43 (chan, &abi16->channels, head) {
if ( V_29 -> V_29 -> V_40 == ( V_88 | V_108 -> V_81 ) ) {
F_15 ( V_9 , V_29 ) ;
return F_9 ( V_9 , 0 ) ;
}
}
return F_9 ( V_9 , V_13 ) ;
}
int
F_44 ( T_2 )
{
struct V_110 * V_74 = V_51 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_111 * V_112 ;
int V_13 ;
if ( F_32 ( ! V_9 ) )
return - V_80 ;
if ( V_74 -> V_40 == ~ 0 )
return F_9 ( V_9 , - V_72 ) ;
if ( V_74 -> V_113 == 0x506e ) {
V_74 -> V_113 = F_10 ( V_15 ) ;
if ( V_74 -> V_113 == 0x906e )
return F_9 ( V_9 , 0 ) ;
}
V_13 = F_6 ( V_9 -> V_12 , V_88 | V_74 -> V_81 ,
V_74 -> V_40 , V_74 -> V_113 , NULL , 0 , & V_112 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_45 ( T_2 )
{
struct V_114 * V_115 = V_51 ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_43 * V_16 = F_11 ( V_15 -> V_16 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_28 * V_29 = NULL , * V_35 ;
struct V_30 * V_31 ;
struct V_111 * V_112 ;
struct V_116 args = {} ;
int V_13 ;
if ( F_32 ( ! V_9 ) )
return - V_80 ;
if ( F_32 ( F_11 ( V_9 -> V_16 ) -> V_17 >= V_25 ) )
return F_9 ( V_9 , - V_72 ) ;
F_43 (temp, &abi16->channels, head) {
if ( V_35 -> V_29 -> V_40 == ( V_88 | V_115 -> V_81 ) ) {
V_29 = V_35 ;
break;
}
}
if ( ! V_29 )
return F_9 ( V_9 , - V_109 ) ;
V_31 = F_3 ( sizeof( * V_31 ) , V_10 ) ;
if ( ! V_31 )
return F_9 ( V_9 , - V_80 ) ;
F_35 ( & V_31 -> V_34 , & V_29 -> V_87 ) ;
V_31 -> V_40 = V_115 -> V_40 ;
V_13 = F_46 ( & V_29 -> V_32 , 1 , V_115 -> V_117 , V_115 -> V_117 , 1 ,
& V_31 -> V_33 ) ;
if ( V_13 )
goto V_89;
args . V_118 = V_31 -> V_33 -> V_119 ;
args . V_120 = V_31 -> V_33 -> V_119 + V_31 -> V_33 -> V_121 - 1 ;
if ( V_16 -> V_17 >= V_24 ) {
args . V_122 = V_123 | V_124 ;
args . V_118 += V_29 -> V_36 . V_119 ;
args . V_120 += V_29 -> V_36 . V_119 ;
} else
if ( V_15 -> V_125 . V_126 == V_127 ) {
args . V_122 = V_128 | V_129 ;
args . V_118 += V_15 -> V_125 . V_130 + V_29 -> V_31 -> V_95 . V_119 ;
args . V_120 += V_15 -> V_125 . V_130 + V_29 -> V_31 -> V_95 . V_119 ;
} else {
args . V_122 = V_123 | V_129 ;
args . V_118 += V_29 -> V_31 -> V_95 . V_119 ;
args . V_120 += V_29 -> V_31 -> V_95 . V_119 ;
}
V_13 = F_6 ( V_9 -> V_12 , V_29 -> V_29 -> V_40 ,
V_31 -> V_40 , 0x003d , & args ,
sizeof( args ) , & V_112 ) ;
if ( V_13 )
goto V_89;
V_115 -> V_119 = V_31 -> V_33 -> V_119 ;
V_89:
if ( V_13 )
F_12 ( V_29 , V_31 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_47 ( T_2 )
{
struct V_131 * V_132 = V_51 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_28 * V_29 = NULL , * V_35 ;
struct V_30 * V_31 ;
int V_13 ;
if ( F_32 ( ! V_9 ) )
return - V_80 ;
F_43 (temp, &abi16->channels, head) {
if ( V_35 -> V_29 -> V_40 == ( V_88 | V_132 -> V_81 ) ) {
V_29 = V_35 ;
break;
}
}
if ( ! V_29 )
return F_9 ( V_9 , - V_109 ) ;
F_16 ( V_29 -> V_29 ) ;
V_13 = F_24 ( V_9 -> V_12 , V_29 -> V_29 -> V_40 , V_132 -> V_40 ) ;
if ( V_13 )
return F_9 ( V_9 , V_13 ) ;
F_43 (ntfy, &chan->notifiers, head) {
if ( V_31 -> V_40 == V_132 -> V_40 ) {
F_13 ( & V_29 -> V_32 , & V_31 -> V_33 ) ;
F_14 ( & V_31 -> V_34 ) ;
break;
}
}
return F_9 ( V_9 , 0 ) ;
}
