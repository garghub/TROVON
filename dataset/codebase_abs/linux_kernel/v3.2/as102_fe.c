static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
struct V_8 V_9 = { 0 } ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
if ( F_3 ( & V_7 -> V_12 . V_13 ) )
return - V_14 ;
F_4 ( & V_9 , V_4 ) ;
V_5 = F_5 ( & V_7 -> V_12 , & V_9 ) ;
if ( V_5 != 0 )
F_6 ( V_15 , L_1 , V_5 ) ;
F_7 ( & V_7 -> V_12 . V_13 ) ;
F_8 () ;
return ( V_5 < 0 ) ? - V_16 : 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_17 ) {
int V_5 = 0 ;
struct V_6 * V_7 ;
struct V_18 V_19 = { 0 } ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_16 ;
if ( F_3 ( & V_7 -> V_12 . V_13 ) )
return - V_14 ;
V_5 = F_10 ( & V_7 -> V_12 , & V_19 ) ;
if ( V_5 == 0 )
F_11 ( V_17 , & V_19 ) ;
F_7 ( & V_7 -> V_12 . V_13 ) ;
F_8 () ;
return ( V_5 < 0 ) ? - V_16 : 0 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_20 * V_21 ) {
F_2 () ;
#if 0
dprintk(debug, "step_size = %d\n", settings->step_size);
dprintk(debug, "max_drift = %d\n", settings->max_drift);
dprintk(debug, "min_delay_ms = %d -> %d\n", settings->min_delay_ms,
1000);
#endif
V_21 -> V_22 = 1000 ;
F_8 () ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_23 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
struct V_24 V_25 = { 0 } ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
if ( F_3 ( & V_7 -> V_12 . V_13 ) )
return - V_14 ;
V_5 = F_14 ( & V_7 -> V_12 , & V_25 ) ;
if ( V_5 < 0 ) {
F_6 ( V_15 , L_2 ,
V_5 ) ;
goto V_26;
}
V_7 -> V_27 = V_25 . V_27 ;
V_7 -> V_28 = V_25 . V_29 ;
switch ( V_25 . V_30 ) {
case V_31 :
* V_23 = V_32 | V_33 ;
break;
case V_34 :
* V_23 = V_32 | V_33 | V_35 ;
break;
case V_36 :
* V_23 = V_32 | V_33 | V_35 |
V_37 ;
break;
default:
* V_23 = V_38 ;
}
F_6 ( V_15 , L_3 ,
V_25 . V_30 , V_25 . V_27 ,
V_25 . V_39 , V_25 . V_29 ) ;
if ( * V_23 & V_37 ) {
if ( F_15 ( & V_7 -> V_12 ,
(struct V_40 * ) & V_7 -> V_41 ) < 0 ) {
memset ( & V_7 -> V_41 , 0 , sizeof( V_7 -> V_41 ) ) ;
F_6 ( V_15 , L_4
L_5 ) ;
} else {
F_6 ( V_15 ,
L_6
L_7 ,
V_7 -> V_41 . V_42 ,
V_7 -> V_41 . V_43 ,
V_7 -> V_41 . V_44 ,
V_7 -> V_41 . V_45 ) ;
}
} else {
memset ( & V_7 -> V_41 , 0 , sizeof( V_7 -> V_41 ) ) ;
}
V_26:
F_7 ( & V_7 -> V_12 . V_13 ) ;
F_8 () ;
return V_5 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_46 )
{
struct V_6 * V_7 ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
* V_46 = V_7 -> V_41 . V_45 ;
F_8 () ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_28 )
{
struct V_6 * V_7 ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
* V_28 = V_7 -> V_28 ;
F_8 () ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_2 * V_47 )
{
struct V_6 * V_7 ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
* V_47 = ( ( ( 0xffff * 400 ) * V_7 -> V_27 + 41000 ) * 2 ) ;
F_8 () ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 * V_48 )
{
struct V_6 * V_7 ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
if ( V_7 -> V_41 . V_49 )
* V_48 = V_7 -> V_41 . V_43 ;
else
* V_48 = 0 ;
F_8 () ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_50 )
{
struct V_6 * V_7 ;
int V_5 ;
F_2 () ;
V_7 = (struct V_6 * ) V_2 -> V_10 ;
if ( V_7 == NULL )
return - V_11 ;
if ( F_3 ( & V_7 -> V_12 . V_13 ) )
return - V_14 ;
if ( V_50 ) {
if ( V_51 )
F_21 ( & V_7 -> V_12 , 1010 , 0xC0 ) ;
V_5 = F_22 ( & V_7 -> V_12 ) ;
} else {
V_5 = F_23 ( & V_7 -> V_12 ) ;
}
F_7 ( & V_7 -> V_12 . V_13 ) ;
F_8 () ;
return V_5 ;
}
int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_6 * V_52 ,
struct V_1 * V_53 )
{
int V_54 ;
struct V_55 * V_56 ;
if ( V_52 == NULL )
return - V_16 ;
V_56 = & V_52 -> V_56 ;
memcpy ( & V_53 -> V_57 , & V_58 , sizeof( struct V_59 ) ) ;
strncpy ( V_53 -> V_57 . V_60 . V_61 , V_52 -> V_61 ,
sizeof( V_53 -> V_57 . V_60 . V_61 ) ) ;
V_54 = F_28 ( V_56 , V_53 ) ;
if ( V_54 == 0 )
V_53 -> V_10 = V_52 ;
return V_54 ;
}
static void F_11 ( struct V_3 * V_62 ,
struct V_18 * V_18 )
{
struct V_63 * V_64 = & V_62 -> V_65 . V_66 ;
switch ( V_18 -> V_67 ) {
case V_68 :
V_64 -> V_67 = V_69 ;
break;
case V_70 :
V_64 -> V_67 = V_71 ;
break;
case V_72 :
V_64 -> V_67 = V_73 ;
break;
}
switch ( V_18 -> V_74 ) {
case V_75 :
V_64 -> V_76 = V_77 ;
break;
case V_78 :
V_64 -> V_76 = V_79 ;
break;
case V_80 :
V_64 -> V_76 = V_81 ;
break;
case V_82 :
V_64 -> V_76 = V_83 ;
break;
}
switch ( V_18 -> V_84 ) {
case V_85 :
V_64 -> V_84 = V_86 ;
break;
case V_87 :
V_64 -> V_84 = V_88 ;
break;
case V_89 :
V_64 -> V_84 = V_90 ;
break;
case V_91 :
V_64 -> V_84 = V_92 ;
break;
case V_93 :
V_64 -> V_84 = V_94 ;
break;
}
switch ( V_18 -> V_95 ) {
case V_85 :
V_64 -> V_95 = V_86 ;
break;
case V_87 :
V_64 -> V_95 = V_88 ;
break;
case V_89 :
V_64 -> V_95 = V_90 ;
break;
case V_91 :
V_64 -> V_95 = V_92 ;
break;
case V_93 :
V_64 -> V_95 = V_94 ;
break;
}
switch ( V_18 -> V_96 ) {
case V_97 :
V_64 -> V_96 = V_98 ;
break;
case V_99 :
V_64 -> V_96 = V_100 ;
break;
case V_101 :
V_64 -> V_96 = V_102 ;
break;
case V_103 :
V_64 -> V_96 = V_104 ;
break;
}
switch ( V_18 -> V_105 ) {
case V_106 :
V_64 -> V_105 = V_107 ;
break;
case V_108 :
V_64 -> V_105 = V_109 ;
break;
}
}
static T_4 F_29 ( T_5 V_110 )
{
T_4 V_111 ;
switch ( V_110 ) {
case V_86 :
V_111 = V_85 ;
break;
case V_88 :
V_111 = V_87 ;
break;
case V_90 :
V_111 = V_89 ;
break;
case V_92 :
V_111 = V_91 ;
break;
case V_94 :
V_111 = V_93 ;
break;
default:
V_111 = V_112 ;
break;
}
return V_111 ;
}
static void F_4 ( struct V_8 * V_9 ,
struct V_3 * V_4 )
{
V_9 -> V_113 = V_4 -> V_114 / 1000 ;
V_9 -> V_115 = V_116 ;
switch ( V_4 -> V_65 . V_66 . V_117 ) {
case V_118 :
V_9 -> V_117 = V_119 ;
break;
case V_120 :
V_9 -> V_117 = V_121 ;
break;
case V_122 :
V_9 -> V_117 = V_123 ;
break;
default:
V_9 -> V_117 = V_119 ;
}
switch ( V_4 -> V_65 . V_66 . V_96 ) {
case V_98 :
V_9 -> V_96 = V_97 ;
break;
case V_100 :
V_9 -> V_96 = V_99 ;
break;
case V_102 :
V_9 -> V_96 = V_101 ;
break;
case V_104 :
V_9 -> V_96 = V_103 ;
break;
case V_124 :
default:
V_9 -> V_96 = V_125 ;
break;
}
switch ( V_4 -> V_65 . V_66 . V_67 ) {
case V_69 :
V_9 -> V_67 = V_68 ;
break;
case V_71 :
V_9 -> V_67 = V_70 ;
break;
case V_73 :
V_9 -> V_67 = V_72 ;
break;
default:
V_9 -> V_67 = V_126 ;
break;
}
switch ( V_4 -> V_65 . V_66 . V_105 ) {
case V_107 :
V_9 -> V_105 = V_106 ;
break;
case V_109 :
V_9 -> V_105 = V_108 ;
break;
default:
V_9 -> V_105 = V_127 ;
}
switch ( V_4 -> V_65 . V_66 . V_76 ) {
case V_77 :
V_9 -> V_74 = V_75 ;
break;
case V_79 :
V_9 -> V_74 = V_78 ;
break;
case V_81 :
V_9 -> V_74 = V_80 ;
break;
case V_83 :
V_9 -> V_74 = V_82 ;
break;
case V_128 :
V_9 -> V_74 = V_129 ;
break;
}
F_6 ( V_15 , L_8 ,
V_4 -> V_114 ,
V_9 -> V_117 ,
V_9 -> V_96 ) ;
if ( ( V_9 -> V_74 != V_75 ) &&
( ( V_4 -> V_65 . V_66 . V_95 == V_130 ) ||
( V_4 -> V_65 . V_66 . V_84 == V_130 ) ) ) {
if ( V_4 -> V_65 . V_66 . V_95 == V_130 ) {
V_9 -> V_131 = V_132 ;
V_9 -> V_133 =
F_29 ( V_4 -> V_65 . V_66 . V_84 ) ;
}
if ( V_4 -> V_65 . V_66 . V_84 == V_130 ) {
V_9 -> V_131 = V_134 ;
V_9 -> V_133 =
F_29 ( V_4 -> V_65 . V_66 . V_95 ) ;
}
F_6 ( V_15 , L_9
L_10 ,
V_9 -> V_74 ,
V_9 -> V_131 == V_132 ?
L_11 : L_12 ,
V_9 -> V_131 == V_132 ?
L_11 : L_12 ,
V_9 -> V_133 ) ;
} else {
V_9 -> V_133 =
F_29 ( V_4 -> V_65 . V_66 . V_84 ) ;
}
}
