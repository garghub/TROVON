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
T_3 * V_27 )
{
if ( V_8 >= F_12 ( V_28 ) )
return - V_26 ;
* V_27 = V_28 [ V_8 ] . V_29 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < F_12 ( V_28 ) ; V_8 ++ )
if ( V_28 [ V_8 ] . V_29 == V_31 -> V_27 )
break;
if ( V_8 >= F_12 ( V_28 ) ) {
V_8 = 0 ;
V_31 -> V_27 = V_28 [ 0 ] . V_29 ;
}
if ( V_31 -> V_32 > V_33 )
V_31 -> V_32 = V_33 ;
if ( V_31 -> V_34 > V_35 )
V_31 -> V_34 = V_35 ;
V_31 -> V_32 = V_31 -> V_32 & ( ~ 3 ) ;
V_31 -> V_34 = V_31 -> V_34 & ( ~ 3 ) ;
V_31 -> V_36 = V_37 ;
V_31 -> V_38 = V_28 [ V_8 ] . V_38 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
int V_40 ;
V_40 = F_13 ( V_3 , V_31 ) ;
if ( V_40 )
return V_40 ;
switch ( V_31 -> V_27 ) {
case V_41 :
F_8 ( V_3 , V_42 , 0x0 ) ;
F_8 ( V_3 , V_43 , 0x1 ) ;
break;
case V_44 :
F_8 ( V_3 , V_42 , 0x0 ) ;
F_8 ( V_3 , V_43 , 0x3 ) ;
break;
case V_45 :
F_8 ( V_3 , V_42 , 0x4 ) ;
F_8 ( V_3 , V_46 , 0x0 ) ;
break;
default:
return - V_26 ;
}
if ( ( V_31 -> V_32 == V_33 ) && ( V_31 -> V_34 == V_35 ) )
F_8 ( V_3 , V_47 , 0x2 ) ;
else if ( ( V_31 -> V_32 == V_48 ) && ( V_31 -> V_34 == V_49 ) )
F_8 ( V_3 , V_47 , 0x4 ) ;
else if ( ( V_31 -> V_32 == V_50 ) && ( V_31 -> V_34 == V_51 ) )
F_8 ( V_3 , V_47 , 0x6 ) ;
else if ( ( V_31 -> V_32 == V_52 ) && ( V_31 -> V_34 == V_53 ) )
F_8 ( V_3 , V_47 , 0x3 ) ;
else if ( ( V_31 -> V_32 == V_54 ) && ( V_31 -> V_34 == V_55 ) )
F_8 ( V_3 , V_47 , 0x5 ) ;
else if ( ( V_31 -> V_32 == V_56 ) && ( V_31 -> V_34 == V_57 ) )
F_8 ( V_3 , V_47 , 0x7 ) ;
else {
F_8 ( V_3 , V_47 , 0x8 ) ;
F_8 ( V_3 , V_58 , V_31 -> V_32 >> 8 ) ;
F_8 ( V_3 , V_59 , V_31 -> V_32 & 0xFF ) ;
F_8 ( V_3 , V_60 , V_31 -> V_34 >> 8 ) ;
F_8 ( V_3 , V_61 , V_31 -> V_34 & 0xFF ) ;
F_8 ( V_3 , V_62 , 0x1 ) ;
}
V_39 -> V_31 = * V_31 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_30 * V_31 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
* V_31 = V_39 -> V_31 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 , struct V_63 * V_64 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_65 * V_66 = & V_64 -> V_67 . V_68 ;
if ( V_64 -> type != V_69 )
return - V_26 ;
memset ( V_66 , 0 , sizeof( * V_66 ) ) ;
V_66 -> V_70 = V_71 ;
V_66 -> V_72 . V_73 = V_39 -> V_74 . V_75 ;
V_66 -> V_72 . V_75 = V_39 -> V_74 . V_73 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_63 * V_64 )
{
struct V_1 * V_39 = F_1 ( V_3 ) ;
struct V_65 * V_66 = & V_64 -> V_67 . V_68 ;
struct V_76 * V_77 = & V_66 -> V_72 ;
if ( V_64 -> type != V_69 )
return - V_26 ;
if ( V_66 -> V_78 != 0 )
return - V_26 ;
if ( V_77 -> V_73 == 0 || V_77 -> V_75 == 0
|| ( V_77 -> V_75 > V_77 -> V_73 * V_79 ) ) {
V_77 -> V_73 = 1 ;
V_77 -> V_75 = V_79 ;
}
V_39 -> V_74 . V_73 = V_77 -> V_75 ;
V_39 -> V_74 . V_75 = V_77 -> V_73 ;
F_8 ( V_3 , V_80 , 0x0 ) ;
F_8 ( V_3 , V_81 ,
V_39 -> V_74 . V_73 >> 8 ) ;
F_8 ( V_3 , V_82 ,
V_39 -> V_74 . V_73 & 0xFF ) ;
F_8 ( V_3 , V_83 ,
V_39 -> V_74 . V_75 & 0xFF ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 , int V_84 )
{
if ( V_84 )
F_8 ( V_3 , V_85 , 0x2 ) ;
else
F_8 ( V_3 , V_85 , 0x4 ) ;
F_19 ( 100 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , struct V_86 * V_14 )
{
V_14 -> V_19 = F_4 ( V_3 , V_14 -> V_14 & 0xffff ) ;
V_14 -> V_87 = 1 ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , const struct V_86 * V_14 )
{
F_8 ( V_3 , V_14 -> V_14 & 0xffff , V_14 -> V_19 & 0xff ) ;
return 0 ;
}
static int F_22 ( struct V_9 * V_10 ,
const struct V_88 * V_16 )
{
struct V_1 * V_39 ;
struct V_2 * V_3 ;
struct V_89 * V_7 ;
const unsigned * V_90 ;
int V_40 ;
if ( ! F_23 ( V_10 -> V_91 , V_92 ) )
return - V_93 ;
V_90 = V_10 -> V_94 . V_95 ;
if ( V_90 == NULL )
return - V_26 ;
V_40 = F_24 ( & V_10 -> V_94 , * V_90 , V_96 ,
L_1 ) ;
if ( V_40 ) {
F_25 ( V_10 , L_2 , * V_90 ) ;
return V_40 ;
}
F_26 ( 100 ) ;
V_39 = F_27 ( & V_10 -> V_94 , sizeof( * V_39 ) , V_97 ) ;
if ( V_39 == NULL )
return - V_98 ;
V_3 = & V_39 -> V_3 ;
F_28 ( V_3 , V_10 , & V_99 ) ;
F_9 ( V_3 , V_100 ) ;
F_8 ( V_3 , V_101 , 0x2 ) ;
F_8 ( V_3 , V_102 , 0x1 ) ;
F_26 ( 10 ) ;
F_9 ( V_3 , V_103 ) ;
F_9 ( V_3 , V_104 ) ;
F_8 ( V_3 , V_105 , 0xF ) ;
F_9 ( V_3 , V_106 ) ;
V_39 -> V_74 . V_73 = V_79 ;
V_39 -> V_74 . V_75 = 1 ;
F_8 ( V_3 , V_80 , 0x0 ) ;
F_8 ( V_3 , V_81 ,
V_39 -> V_74 . V_73 >> 8 ) ;
F_8 ( V_3 , V_82 ,
V_39 -> V_74 . V_73 & 0xFF ) ;
F_8 ( V_3 , V_83 ,
V_39 -> V_74 . V_75 & 0xFF ) ;
V_39 -> V_31 = V_107 ;
V_39 -> V_108 = * V_90 ;
F_29 ( V_10 , L_3 ,
V_10 -> V_109 << 1 , V_10 -> V_91 -> V_110 ) ;
V_7 = & V_39 -> V_7 ;
F_30 ( V_7 , 4 ) ;
F_31 ( V_7 , & V_111 ,
V_17 , 0 , 0xFF , 1 , 0x87 ) ;
F_31 ( V_7 , & V_111 ,
V_20 , 0 , 0xFF , 1 , 0x78 ) ;
F_31 ( V_7 , & V_111 ,
V_22 , 0 , 1 , 1 , 0 ) ;
F_31 ( V_7 , & V_111 ,
V_24 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_112 = V_7 ;
if ( V_7 -> error ) {
int V_113 = V_7 -> error ;
F_32 ( V_7 ) ;
return V_113 ;
}
V_40 = F_33 ( V_7 ) ;
if ( V_40 )
F_32 ( V_7 ) ;
return V_40 ;
}
static int F_34 ( struct V_9 * V_10 )
{
struct V_2 * V_3 = F_35 ( V_10 ) ;
F_36 ( V_3 ) ;
F_32 ( V_3 -> V_112 ) ;
return 0 ;
}
