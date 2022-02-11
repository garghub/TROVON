static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_6 = 0 ;
struct V_7 * V_8 ;
struct V_9 V_10 = { 0 } ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
if ( F_3 ( & V_8 -> V_13 . V_14 ) )
return - V_15 ;
F_4 ( & V_10 , V_4 ) ;
V_6 = F_5 ( & V_8 -> V_13 , & V_10 ) ;
if ( V_6 != 0 )
F_6 ( V_16 , L_1 , V_6 ) ;
F_7 ( & V_8 -> V_13 . V_14 ) ;
F_8 () ;
return ( V_6 < 0 ) ? - V_17 : 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_6 = 0 ;
struct V_7 * V_8 ;
struct V_18 V_19 = { 0 } ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_17 ;
if ( F_3 ( & V_8 -> V_13 . V_14 ) )
return - V_15 ;
V_6 = F_10 ( & V_8 -> V_13 , & V_19 ) ;
if ( V_6 == 0 )
F_11 ( V_4 , & V_19 ) ;
F_7 ( & V_8 -> V_13 . V_14 ) ;
F_8 () ;
return ( V_6 < 0 ) ? - V_17 : 0 ;
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
int V_6 = 0 ;
struct V_7 * V_8 ;
struct V_24 V_25 = { 0 } ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
if ( F_3 ( & V_8 -> V_13 . V_14 ) )
return - V_15 ;
V_6 = F_14 ( & V_8 -> V_13 , & V_25 ) ;
if ( V_6 < 0 ) {
F_6 ( V_16 , L_2 ,
V_6 ) ;
goto V_26;
}
V_8 -> V_27 = V_25 . V_27 ;
V_8 -> V_28 = V_25 . V_29 ;
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
F_6 ( V_16 , L_3 ,
V_25 . V_30 , V_25 . V_27 ,
V_25 . V_39 , V_25 . V_29 ) ;
if ( * V_23 & V_37 ) {
if ( F_15 ( & V_8 -> V_13 ,
(struct V_40 * ) & V_8 -> V_41 ) < 0 ) {
memset ( & V_8 -> V_41 , 0 , sizeof( V_8 -> V_41 ) ) ;
F_6 ( V_16 , L_4
L_5 ) ;
} else {
F_6 ( V_16 ,
L_6
L_7 ,
V_8 -> V_41 . V_42 ,
V_8 -> V_41 . V_43 ,
V_8 -> V_41 . V_44 ,
V_8 -> V_41 . V_45 ) ;
}
} else {
memset ( & V_8 -> V_41 , 0 , sizeof( V_8 -> V_41 ) ) ;
}
V_26:
F_7 ( & V_8 -> V_13 . V_14 ) ;
F_8 () ;
return V_6 ;
}
static int F_16 ( struct V_1 * V_2 , T_2 * V_46 )
{
struct V_7 * V_8 ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
* V_46 = V_8 -> V_41 . V_45 ;
F_8 () ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 * V_28 )
{
struct V_7 * V_8 ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
* V_28 = V_8 -> V_28 ;
F_8 () ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_2 * V_47 )
{
struct V_7 * V_8 ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
* V_47 = ( ( ( 0xffff * 400 ) * V_8 -> V_27 + 41000 ) * 2 ) ;
F_8 () ;
return 0 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 * V_48 )
{
struct V_7 * V_8 ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
if ( V_8 -> V_41 . V_49 )
* V_48 = V_8 -> V_41 . V_43 ;
else
* V_48 = 0 ;
F_8 () ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_50 )
{
struct V_7 * V_8 ;
int V_6 ;
F_2 () ;
V_8 = (struct V_7 * ) V_2 -> V_11 ;
if ( V_8 == NULL )
return - V_12 ;
if ( F_3 ( & V_8 -> V_13 . V_14 ) )
return - V_15 ;
if ( V_50 ) {
if ( V_51 )
F_21 ( & V_8 -> V_13 , 1010 , 0xC0 ) ;
V_6 = F_22 ( & V_8 -> V_13 ) ;
} else {
V_6 = F_23 ( & V_8 -> V_13 ) ;
}
F_7 ( & V_8 -> V_13 . V_14 ) ;
F_8 () ;
return V_6 ;
}
int F_24 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
return 0 ;
}
int F_27 ( struct V_7 * V_52 ,
struct V_1 * V_53 )
{
int V_54 ;
struct V_55 * V_56 ;
if ( V_52 == NULL )
return - V_17 ;
V_56 = & V_52 -> V_56 ;
memcpy ( & V_53 -> V_57 , & V_58 , sizeof( struct V_59 ) ) ;
strncpy ( V_53 -> V_57 . V_60 . V_61 , V_52 -> V_61 ,
sizeof( V_53 -> V_57 . V_60 . V_61 ) ) ;
V_54 = F_28 ( V_56 , V_53 ) ;
if ( V_54 == 0 )
V_53 -> V_11 = V_52 ;
return V_54 ;
}
static void F_11 ( struct V_3 * V_62 ,
struct V_18 * V_18 )
{
switch ( V_18 -> V_63 ) {
case V_64 :
V_62 -> V_63 = V_65 ;
break;
case V_66 :
V_62 -> V_63 = V_67 ;
break;
case V_68 :
V_62 -> V_63 = V_69 ;
break;
}
switch ( V_18 -> V_70 ) {
case V_71 :
V_62 -> V_70 = V_72 ;
break;
case V_73 :
V_62 -> V_70 = V_74 ;
break;
case V_75 :
V_62 -> V_70 = V_76 ;
break;
case V_77 :
V_62 -> V_70 = V_78 ;
break;
}
switch ( V_18 -> V_79 ) {
case V_80 :
V_62 -> V_79 = V_81 ;
break;
case V_82 :
V_62 -> V_79 = V_83 ;
break;
case V_84 :
V_62 -> V_79 = V_85 ;
break;
case V_86 :
V_62 -> V_79 = V_87 ;
break;
case V_88 :
V_62 -> V_79 = V_89 ;
break;
}
switch ( V_18 -> V_90 ) {
case V_80 :
V_62 -> V_90 = V_81 ;
break;
case V_82 :
V_62 -> V_90 = V_83 ;
break;
case V_84 :
V_62 -> V_90 = V_85 ;
break;
case V_86 :
V_62 -> V_90 = V_87 ;
break;
case V_88 :
V_62 -> V_90 = V_89 ;
break;
}
switch ( V_18 -> V_91 ) {
case V_92 :
V_62 -> V_91 = V_93 ;
break;
case V_94 :
V_62 -> V_91 = V_95 ;
break;
case V_96 :
V_62 -> V_91 = V_97 ;
break;
case V_98 :
V_62 -> V_91 = V_99 ;
break;
}
switch ( V_18 -> V_100 ) {
case V_101 :
V_62 -> V_100 = V_102 ;
break;
case V_103 :
V_62 -> V_100 = V_104 ;
break;
}
}
static T_4 F_29 ( T_5 V_105 )
{
T_4 V_106 ;
switch ( V_105 ) {
case V_81 :
V_106 = V_80 ;
break;
case V_83 :
V_106 = V_82 ;
break;
case V_85 :
V_106 = V_84 ;
break;
case V_87 :
V_106 = V_86 ;
break;
case V_89 :
V_106 = V_88 ;
break;
default:
V_106 = V_107 ;
break;
}
return V_106 ;
}
static void F_4 ( struct V_9 * V_10 ,
struct V_3 * V_108 )
{
V_10 -> V_109 = V_108 -> V_110 / 1000 ;
V_10 -> V_111 = V_112 ;
switch ( V_108 -> V_113 ) {
case 8000000 :
V_10 -> V_114 = V_115 ;
break;
case 7000000 :
V_10 -> V_114 = V_116 ;
break;
case 6000000 :
V_10 -> V_114 = V_117 ;
break;
default:
V_10 -> V_114 = V_115 ;
}
switch ( V_108 -> V_91 ) {
case V_93 :
V_10 -> V_91 = V_92 ;
break;
case V_95 :
V_10 -> V_91 = V_94 ;
break;
case V_97 :
V_10 -> V_91 = V_96 ;
break;
case V_99 :
V_10 -> V_91 = V_98 ;
break;
case V_118 :
default:
V_10 -> V_91 = V_119 ;
break;
}
switch ( V_108 -> V_63 ) {
case V_65 :
V_10 -> V_63 = V_64 ;
break;
case V_67 :
V_10 -> V_63 = V_66 ;
break;
case V_69 :
V_10 -> V_63 = V_68 ;
break;
default:
V_10 -> V_63 = V_120 ;
break;
}
switch ( V_108 -> V_100 ) {
case V_102 :
V_10 -> V_100 = V_101 ;
break;
case V_104 :
V_10 -> V_100 = V_103 ;
break;
default:
V_10 -> V_100 = V_121 ;
}
switch ( V_108 -> V_70 ) {
case V_72 :
V_10 -> V_70 = V_71 ;
break;
case V_74 :
V_10 -> V_70 = V_73 ;
break;
case V_76 :
V_10 -> V_70 = V_75 ;
break;
case V_78 :
V_10 -> V_70 = V_77 ;
break;
case V_122 :
V_10 -> V_70 = V_123 ;
break;
}
F_6 ( V_16 , L_8 ,
V_108 -> V_110 ,
V_10 -> V_114 ,
V_10 -> V_91 ) ;
if ( ( V_10 -> V_70 != V_71 ) &&
( ( V_108 -> V_90 == V_124 ) ||
( V_108 -> V_79 == V_124 ) ) ) {
if ( V_108 -> V_90 == V_124 ) {
V_10 -> V_125 = V_126 ;
V_10 -> V_127 =
F_29 ( V_108 -> V_79 ) ;
}
if ( V_108 -> V_79 == V_124 ) {
V_10 -> V_125 = V_128 ;
V_10 -> V_127 =
F_29 ( V_108 -> V_90 ) ;
}
F_6 ( V_16 , L_9
L_10 ,
V_10 -> V_70 ,
V_10 -> V_125 == V_126 ?
L_11 : L_12 ,
V_10 -> V_125 == V_126 ?
L_11 : L_12 ,
V_10 -> V_127 ) ;
} else {
V_10 -> V_127 =
F_29 ( V_108 -> V_79 ) ;
}
}
