static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_2 * F_3 ( struct V_4 * V_5 )
{
return & F_2 ( V_5 -> V_6 , struct V_1 , V_7 ) -> V_3 ;
}
static int F_4 ( struct V_2 * V_3 , T_1 V_8 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
T_2 V_11 [ 2 ] ;
V_11 [ 0 ] = V_8 >> 8 ;
V_11 [ 1 ] = V_8 ;
F_6 ( V_10 , V_11 , 2 ) ;
F_7 ( V_10 , V_11 , 1 ) ;
return V_11 [ 0 ] ;
}
static int F_8 ( struct V_2 * V_3 , T_1 V_8 ,
T_2 V_12 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
T_2 V_11 [ 3 ] ;
V_11 [ 0 ] = V_8 >> 8 ;
V_11 [ 1 ] = V_8 ;
V_11 [ 2 ] = V_12 ;
return F_6 ( V_10 , V_11 , 3 ) ;
}
static int F_9 ( struct V_2 * V_3 , const T_1 * V_13 )
{
T_1 V_14 ;
T_2 V_15 ;
while ( * V_13 != 0x00 ) {
V_14 = * V_13 ++ ;
V_15 = * V_13 ++ ;
F_8 ( V_3 , V_14 , V_15 ) ;
}
return 0 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_2 * V_3 = F_3 ( V_5 ) ;
switch ( V_5 -> V_16 ) {
case V_17 :
F_8 ( V_3 , V_18 , V_5 -> V_19 ) ;
break;
case V_20 :
F_8 ( V_3 , V_21 , V_5 -> V_19 ) ;
break;
case V_22 :
F_8 ( V_3 , V_23 , V_5 -> V_19 ) ;
break;
case V_24 :
F_8 ( V_3 , V_25 , V_5 -> V_19 ) ;
break;
default:
return - V_26 ;
}
return 0 ;
}
static int F_11 ( struct V_2 * V_3 , unsigned V_8 ,
enum V_27 * V_28 )
{
if ( V_8 >= F_12 ( V_29 ) )
return - V_26 ;
* V_28 = V_29 [ V_8 ] . V_30 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_12 ( V_29 ) ; V_8 ++ )
if ( V_29 [ V_8 ] . V_30 == V_32 -> V_28 )
break;
if ( V_8 >= F_12 ( V_29 ) ) {
V_8 = 0 ;
V_32 -> V_28 = V_29 [ 0 ] . V_30 ;
}
if ( V_32 -> V_33 > V_34 )
V_32 -> V_33 = V_34 ;
if ( V_32 -> V_35 > V_36 )
V_32 -> V_35 = V_36 ;
V_32 -> V_33 = V_32 -> V_33 & ( ~ 3 ) ;
V_32 -> V_35 = V_32 -> V_35 & ( ~ 3 ) ;
V_32 -> V_37 = V_38 ;
V_32 -> V_39 = V_29 [ V_8 ] . V_39 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
int V_41 ;
V_41 = F_13 ( V_3 , V_32 ) ;
if ( V_41 )
return V_41 ;
switch ( V_32 -> V_28 ) {
case V_42 :
F_8 ( V_3 , V_43 , 0x0 ) ;
F_8 ( V_3 , V_44 , 0x1 ) ;
break;
case V_45 :
F_8 ( V_3 , V_43 , 0x0 ) ;
F_8 ( V_3 , V_44 , 0x3 ) ;
break;
case V_46 :
F_8 ( V_3 , V_43 , 0x4 ) ;
F_8 ( V_3 , V_47 , 0x0 ) ;
break;
default:
return - V_26 ;
}
if ( ( V_32 -> V_33 == V_34 ) && ( V_32 -> V_35 == V_36 ) )
F_8 ( V_3 , V_48 , 0x2 ) ;
else if ( ( V_32 -> V_33 == V_49 ) && ( V_32 -> V_35 == V_50 ) )
F_8 ( V_3 , V_48 , 0x4 ) ;
else if ( ( V_32 -> V_33 == V_51 ) && ( V_32 -> V_35 == V_52 ) )
F_8 ( V_3 , V_48 , 0x6 ) ;
else if ( ( V_32 -> V_33 == V_53 ) && ( V_32 -> V_35 == V_54 ) )
F_8 ( V_3 , V_48 , 0x3 ) ;
else if ( ( V_32 -> V_33 == V_55 ) && ( V_32 -> V_35 == V_56 ) )
F_8 ( V_3 , V_48 , 0x5 ) ;
else if ( ( V_32 -> V_33 == V_57 ) && ( V_32 -> V_35 == V_58 ) )
F_8 ( V_3 , V_48 , 0x7 ) ;
else {
F_8 ( V_3 , V_48 , 0x8 ) ;
F_8 ( V_3 , V_59 , V_32 -> V_33 >> 8 ) ;
F_8 ( V_3 , V_60 , V_32 -> V_33 & 0xFF ) ;
F_8 ( V_3 , V_61 , V_32 -> V_35 >> 8 ) ;
F_8 ( V_3 , V_62 , V_32 -> V_35 & 0xFF ) ;
F_8 ( V_3 , V_63 , 0x1 ) ;
}
V_40 -> V_32 = * V_32 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_31 * V_32 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
* V_32 = V_40 -> V_32 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_66 * V_67 = & V_65 -> V_68 . V_69 ;
if ( V_65 -> type != V_70 )
return - V_26 ;
memset ( V_67 , 0 , sizeof( * V_67 ) ) ;
V_67 -> V_71 = V_72 ;
V_67 -> V_73 . V_74 = V_40 -> V_75 . V_76 ;
V_67 -> V_73 . V_76 = V_40 -> V_75 . V_74 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
struct V_1 * V_40 = F_1 ( V_3 ) ;
struct V_66 * V_67 = & V_65 -> V_68 . V_69 ;
struct V_77 * V_78 = & V_67 -> V_73 ;
if ( V_65 -> type != V_70 )
return - V_26 ;
if ( V_67 -> V_79 != 0 )
return - V_26 ;
if ( V_78 -> V_74 == 0 || V_78 -> V_76 == 0
|| ( V_78 -> V_76 > V_78 -> V_74 * V_80 ) ) {
V_78 -> V_74 = 1 ;
V_78 -> V_76 = V_80 ;
}
V_40 -> V_75 . V_74 = V_78 -> V_76 ;
V_40 -> V_75 . V_76 = V_78 -> V_74 ;
F_8 ( V_3 , V_81 , 0x0 ) ;
F_8 ( V_3 , V_82 ,
V_40 -> V_75 . V_74 >> 8 ) ;
F_8 ( V_3 , V_83 ,
V_40 -> V_75 . V_74 & 0xFF ) ;
F_8 ( V_3 , V_84 ,
V_40 -> V_75 . V_76 & 0xFF ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , int V_85 )
{
if ( V_85 )
F_8 ( V_3 , V_86 , 0x2 ) ;
else
F_8 ( V_3 , V_86 , 0x4 ) ;
F_19 ( 100 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_87 * V_88 )
{
int V_89 ;
struct V_9 * V_10 = F_5 ( V_3 ) ;
V_89 = ( F_4 ( V_3 , V_90 ) << 8 )
| F_4 ( V_3 , V_91 ) ;
return F_21 ( V_10 , V_88 , V_92 , V_89 ) ;
}
static int F_22 ( struct V_2 * V_3 , struct V_93 * V_14 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
if ( ! F_23 ( V_10 , & V_14 -> V_94 ) )
return - V_26 ;
if ( ! F_24 ( V_95 ) )
return - V_96 ;
V_14 -> V_19 = F_4 ( V_3 , V_14 -> V_14 & 0xffff ) ;
V_14 -> V_97 = 1 ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 , const struct V_93 * V_14 )
{
struct V_9 * V_10 = F_5 ( V_3 ) ;
if ( ! F_23 ( V_10 , & V_14 -> V_94 ) )
return - V_26 ;
if ( ! F_24 ( V_95 ) )
return - V_96 ;
F_8 ( V_3 , V_14 -> V_14 & 0xffff , V_14 -> V_19 & 0xff ) ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 ,
const struct V_98 * V_16 )
{
struct V_1 * V_40 ;
struct V_2 * V_3 ;
struct V_99 * V_7 ;
const unsigned * V_100 ;
int V_41 ;
if ( ! F_27 ( V_10 -> V_101 , V_102 ) )
return - V_103 ;
V_100 = V_10 -> V_104 . V_105 ;
if ( V_100 == NULL )
return - V_26 ;
V_41 = F_28 ( * V_100 , L_1 ) ;
if ( V_41 ) {
F_29 ( V_10 , L_2 , * V_100 ) ;
return V_41 ;
}
F_30 ( * V_100 , 1 ) ;
F_31 ( 100 ) ;
V_40 = F_32 ( sizeof( * V_40 ) , V_106 ) ;
if ( V_40 == NULL ) {
F_33 ( * V_100 ) ;
return - V_107 ;
}
V_3 = & V_40 -> V_3 ;
F_34 ( V_3 , V_10 , & V_108 ) ;
F_9 ( V_3 , V_109 ) ;
F_8 ( V_3 , V_110 , 0x2 ) ;
F_8 ( V_3 , V_111 , 0x1 ) ;
F_31 ( 10 ) ;
F_9 ( V_3 , V_112 ) ;
F_9 ( V_3 , V_113 ) ;
F_8 ( V_3 , V_114 , 0xF ) ;
F_9 ( V_3 , V_115 ) ;
V_40 -> V_75 . V_74 = V_80 ;
V_40 -> V_75 . V_76 = 1 ;
F_8 ( V_3 , V_81 , 0x0 ) ;
F_8 ( V_3 , V_82 ,
V_40 -> V_75 . V_74 >> 8 ) ;
F_8 ( V_3 , V_83 ,
V_40 -> V_75 . V_74 & 0xFF ) ;
F_8 ( V_3 , V_84 ,
V_40 -> V_75 . V_76 & 0xFF ) ;
V_40 -> V_32 = V_116 ;
V_40 -> V_117 = * V_100 ;
F_35 ( V_10 , L_3 ,
V_10 -> V_118 << 1 , V_10 -> V_101 -> V_119 ) ;
V_7 = & V_40 -> V_7 ;
F_36 ( V_7 , 4 ) ;
F_37 ( V_7 , & V_120 ,
V_17 , 0 , 0xFF , 1 , 0x87 ) ;
F_37 ( V_7 , & V_120 ,
V_20 , 0 , 0xFF , 1 , 0x78 ) ;
F_37 ( V_7 , & V_120 ,
V_22 , 0 , 1 , 1 , 0 ) ;
F_37 ( V_7 , & V_120 ,
V_24 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_121 = V_7 ;
if ( V_7 -> error ) {
int V_122 = V_7 -> error ;
F_38 ( V_7 ) ;
F_39 ( V_40 ) ;
F_33 ( * V_100 ) ;
return V_122 ;
}
V_41 = F_40 ( V_7 ) ;
if ( V_41 ) {
F_38 ( V_7 ) ;
F_39 ( V_40 ) ;
F_33 ( * V_100 ) ;
}
return V_41 ;
}
static int F_41 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_42 ( V_10 ) ;
struct V_1 * V_40 = F_1 ( V_3 ) ;
F_43 ( V_3 ) ;
F_38 ( V_3 -> V_121 ) ;
F_33 ( V_40 -> V_117 ) ;
F_39 ( V_40 ) ;
return 0 ;
}
