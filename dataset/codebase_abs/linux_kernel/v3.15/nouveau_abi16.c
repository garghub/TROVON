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
case V_28 :
return 0x906e ;
}
return 0x0000 ;
}
static void
F_12 ( struct V_29 * V_30 ,
struct V_31 * V_32 )
{
F_13 ( & V_30 -> V_33 , & V_32 -> V_34 ) ;
F_14 ( & V_32 -> V_35 ) ;
F_7 ( V_32 ) ;
}
static void
F_15 ( struct V_1 * V_9 ,
struct V_29 * V_30 )
{
struct V_31 * V_32 , * V_36 ;
if ( V_30 -> V_30 && V_30 -> V_32 )
F_16 ( V_30 -> V_30 ) ;
F_17 (ntfy, temp, &chan->notifiers, head) {
F_12 ( V_30 , V_32 ) ;
}
if ( V_30 -> V_32 ) {
F_18 ( V_30 -> V_32 , & V_30 -> V_37 ) ;
F_19 ( V_30 -> V_32 ) ;
F_20 ( & V_30 -> V_32 -> V_38 ) ;
}
if ( V_30 -> V_33 . V_39 )
F_21 ( & V_30 -> V_33 ) ;
if ( V_30 -> V_30 ) {
V_9 -> V_40 &= ~ ( 1ULL << ( V_30 -> V_30 -> V_41 & 0xffff ) ) ;
F_22 ( & V_30 -> V_30 ) ;
}
F_14 ( & V_30 -> V_35 ) ;
F_7 ( V_30 ) ;
}
void
F_23 ( struct V_1 * V_9 )
{
struct V_6 * V_7 = ( void * ) V_9 -> V_12 ;
struct V_29 * V_30 , * V_36 ;
F_17 (chan, temp, &abi16->channels, head) {
F_15 ( V_9 , V_30 ) ;
}
F_24 ( V_9 -> V_12 , V_42 , V_43 ) ;
F_7 ( V_7 -> V_9 ) ;
V_7 -> V_9 = NULL ;
}
int
F_25 ( T_2 )
{
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_44 * V_16 = F_11 ( V_15 -> V_16 ) ;
struct V_45 * V_46 = V_45 ( V_16 ) ;
struct V_47 * V_48 = ( void * ) F_26 ( V_16 , V_49 ) ;
struct V_50 * V_51 = V_52 ;
switch ( V_51 -> V_53 ) {
case V_54 :
V_51 -> V_55 = V_16 -> V_56 ;
break;
case V_57 :
if ( F_27 ( V_16 ) )
V_51 -> V_55 = V_5 -> V_58 -> V_59 ;
else
V_51 -> V_55 = 0 ;
break;
case V_60 :
if ( F_27 ( V_16 ) )
V_51 -> V_55 = V_5 -> V_58 -> V_16 ;
else
V_51 -> V_55 = 0 ;
break;
case V_61 :
if ( ! F_27 ( V_16 ) )
V_51 -> V_55 = 3 ;
else
if ( F_28 ( V_5 ) )
V_51 -> V_55 = 0 ;
else
if ( ! F_29 ( V_5 -> V_58 ) )
V_51 -> V_55 = 1 ;
else
V_51 -> V_55 = 2 ;
break;
case V_62 :
V_51 -> V_55 = V_15 -> V_38 . V_63 ;
break;
case V_64 :
V_51 -> V_55 = V_15 -> V_38 . V_65 ;
break;
case V_66 :
V_51 -> V_55 = 0 ;
break;
case V_67 :
V_51 -> V_55 = V_46 -> V_68 ( V_46 ) ;
break;
case V_69 :
V_51 -> V_55 = 1 ;
break;
case V_70 :
V_51 -> V_55 = 1 ;
break;
case V_71 :
V_51 -> V_55 = V_48 -> V_72 ? V_48 -> V_72 ( V_48 ) : 0 ;
break;
default:
F_30 ( V_16 , L_1 , V_51 -> V_53 ) ;
return - V_73 ;
}
return 0 ;
}
int
F_31 ( T_2 )
{
return - V_73 ;
}
int
F_32 ( T_2 )
{
struct V_74 * V_75 = V_52 ;
struct V_6 * V_7 = V_6 ( V_3 ) ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_29 * V_30 ;
struct V_76 * V_12 ;
struct V_44 * V_16 ;
struct V_77 * V_78 ;
struct V_79 * V_80 ;
int V_13 ;
if ( F_33 ( ! V_9 ) )
return - V_81 ;
if ( ! V_15 -> V_82 )
return F_9 ( V_9 , - V_83 ) ;
V_12 = F_34 ( V_9 -> V_12 ) ;
V_16 = F_11 ( V_9 -> V_16 ) ;
V_78 = V_77 ( V_16 ) ;
V_80 = V_79 ( V_16 ) ;
if ( V_16 -> V_17 >= V_27 ) {
if ( V_75 -> V_84 != ~ 0 )
V_75 -> V_84 = V_85 ;
else
V_75 -> V_84 = V_75 -> V_86 ;
V_75 -> V_86 = 0 ;
if ( V_75 -> V_84 == V_85 )
V_75 -> V_86 = 1 ;
}
if ( V_75 -> V_84 == ~ 0 || V_75 -> V_86 == ~ 0 )
return F_9 ( V_9 , - V_73 ) ;
V_75 -> V_82 = F_35 ( ~ V_9 -> V_40 ) ;
if ( ~ V_9 -> V_40 == 0 )
return F_9 ( V_9 , - V_87 ) ;
V_30 = F_3 ( sizeof( * V_30 ) , V_10 ) ;
if ( ! V_30 )
return F_9 ( V_9 , - V_81 ) ;
F_4 ( & V_30 -> V_88 ) ;
F_36 ( & V_30 -> V_35 , & V_9 -> V_11 ) ;
V_9 -> V_40 |= ( 1ULL << V_75 -> V_82 ) ;
V_13 = F_37 ( V_15 , V_7 , V_43 , V_89 |
V_75 -> V_82 , V_75 -> V_84 ,
V_75 -> V_86 , & V_30 -> V_30 ) ;
if ( V_13 )
goto V_90;
if ( V_16 -> V_17 >= V_24 )
V_75 -> V_91 = V_92 |
V_93 ;
else
if ( V_30 -> V_30 -> V_94 . V_95 -> V_96 . V_97 . V_98 == V_99 )
V_75 -> V_91 = V_92 ;
else
V_75 -> V_91 = V_93 ;
if ( V_16 -> V_17 < V_19 ) {
V_75 -> V_100 [ 0 ] . V_41 = 0x00000000 ;
V_75 -> V_100 [ 0 ] . V_101 = 0x0000 ;
V_75 -> V_100 [ 1 ] . V_41 = V_102 ;
V_75 -> V_100 [ 1 ] . V_101 = 0x506e ;
V_75 -> V_103 = 2 ;
}
V_13 = F_38 ( V_5 , V_104 , 0 , V_93 ,
0 , 0 , & V_30 -> V_32 ) ;
if ( V_13 == 0 )
V_13 = F_39 ( V_30 -> V_32 , V_105 ) ;
if ( V_13 )
goto V_90;
if ( V_16 -> V_17 >= V_24 ) {
V_13 = F_40 ( V_30 -> V_32 , V_12 -> V_106 ,
& V_30 -> V_37 ) ;
if ( V_13 )
goto V_90;
}
V_13 = F_41 ( V_3 , & V_30 -> V_32 -> V_38 ,
& V_75 -> V_107 ) ;
if ( V_13 )
goto V_90;
V_13 = F_42 ( & V_30 -> V_33 , 0 , V_104 , 1 ) ;
V_90:
if ( V_13 )
F_15 ( V_9 , V_30 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_43 ( T_2 )
{
struct V_108 * V_109 = V_52 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_29 * V_30 ;
int V_13 = - V_110 ;
if ( F_33 ( ! V_9 ) )
return - V_81 ;
F_44 (chan, &abi16->channels, head) {
if ( V_30 -> V_30 -> V_41 == ( V_89 | V_109 -> V_82 ) ) {
F_15 ( V_9 , V_30 ) ;
return F_9 ( V_9 , 0 ) ;
}
}
return F_9 ( V_9 , V_13 ) ;
}
int
F_45 ( T_2 )
{
struct V_111 * V_75 = V_52 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_112 * V_113 ;
int V_13 ;
if ( F_33 ( ! V_9 ) )
return - V_81 ;
if ( V_75 -> V_41 == ~ 0 )
return F_9 ( V_9 , - V_73 ) ;
if ( V_75 -> V_114 == 0x506e ) {
V_75 -> V_114 = F_10 ( V_15 ) ;
if ( V_75 -> V_114 == 0x906e )
return F_9 ( V_9 , 0 ) ;
}
V_13 = F_6 ( V_9 -> V_12 , V_89 | V_75 -> V_82 ,
V_75 -> V_41 , V_75 -> V_114 , NULL , 0 , & V_113 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_46 ( T_2 )
{
struct V_115 * V_116 = V_52 ;
struct V_14 * V_15 = V_14 ( V_5 ) ;
struct V_44 * V_16 = F_11 ( V_15 -> V_16 ) ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_29 * V_30 = NULL , * V_36 ;
struct V_31 * V_32 ;
struct V_112 * V_113 ;
struct V_117 args = {} ;
int V_13 ;
if ( F_33 ( ! V_9 ) )
return - V_81 ;
if ( F_33 ( F_11 ( V_9 -> V_16 ) -> V_17 >= V_25 ) )
return F_9 ( V_9 , - V_73 ) ;
F_44 (temp, &abi16->channels, head) {
if ( V_36 -> V_30 -> V_41 == ( V_89 | V_116 -> V_82 ) ) {
V_30 = V_36 ;
break;
}
}
if ( ! V_30 )
return F_9 ( V_9 , - V_110 ) ;
V_32 = F_3 ( sizeof( * V_32 ) , V_10 ) ;
if ( ! V_32 )
return F_9 ( V_9 , - V_81 ) ;
F_36 ( & V_32 -> V_35 , & V_30 -> V_88 ) ;
V_32 -> V_41 = V_116 -> V_41 ;
V_13 = F_47 ( & V_30 -> V_33 , 1 , V_116 -> V_118 , V_116 -> V_118 , 1 ,
& V_32 -> V_34 ) ;
if ( V_13 )
goto V_90;
args . V_119 = V_32 -> V_34 -> V_120 ;
args . V_121 = V_32 -> V_34 -> V_120 + V_32 -> V_34 -> V_122 - 1 ;
if ( V_16 -> V_17 >= V_24 ) {
args . V_123 = V_124 | V_125 ;
args . V_119 += V_30 -> V_37 . V_120 ;
args . V_121 += V_30 -> V_37 . V_120 ;
} else
if ( V_15 -> V_126 . V_127 == V_128 ) {
args . V_123 = V_129 | V_130 ;
args . V_119 += V_15 -> V_126 . V_131 + V_30 -> V_32 -> V_96 . V_120 ;
args . V_121 += V_15 -> V_126 . V_131 + V_30 -> V_32 -> V_96 . V_120 ;
} else {
args . V_123 = V_124 | V_130 ;
args . V_119 += V_30 -> V_32 -> V_96 . V_120 ;
args . V_121 += V_30 -> V_32 -> V_96 . V_120 ;
}
V_13 = F_6 ( V_9 -> V_12 , V_30 -> V_30 -> V_41 ,
V_32 -> V_41 , 0x003d , & args ,
sizeof( args ) , & V_113 ) ;
if ( V_13 )
goto V_90;
V_116 -> V_120 = V_32 -> V_34 -> V_120 ;
V_90:
if ( V_13 )
F_12 ( V_30 , V_32 ) ;
return F_9 ( V_9 , V_13 ) ;
}
int
F_48 ( T_2 )
{
struct V_132 * V_133 = V_52 ;
struct V_1 * V_9 = F_1 ( V_3 , V_5 ) ;
struct V_29 * V_30 = NULL , * V_36 ;
struct V_31 * V_32 ;
int V_13 ;
if ( F_33 ( ! V_9 ) )
return - V_81 ;
F_44 (temp, &abi16->channels, head) {
if ( V_36 -> V_30 -> V_41 == ( V_89 | V_133 -> V_82 ) ) {
V_30 = V_36 ;
break;
}
}
if ( ! V_30 )
return F_9 ( V_9 , - V_110 ) ;
F_16 ( V_30 -> V_30 ) ;
V_13 = F_24 ( V_9 -> V_12 , V_30 -> V_30 -> V_41 , V_133 -> V_41 ) ;
if ( V_13 )
return F_9 ( V_9 , V_13 ) ;
F_44 (ntfy, &chan->notifiers, head) {
if ( V_32 -> V_41 == V_133 -> V_41 ) {
F_13 ( & V_30 -> V_33 , & V_32 -> V_34 ) ;
F_14 ( & V_32 -> V_35 ) ;
break;
}
}
return F_9 ( V_9 , 0 ) ;
}
