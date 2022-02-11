int
F_1 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
switch ( V_4 -> V_7 . V_8 ) {
case V_9 :
return F_2 ( V_2 , V_4 , V_6 ) ;
case V_10 :
return F_3 ( V_2 , V_4 , V_6 ) ;
case V_11 :
return F_4 ( V_2 , V_4 , V_6 ) ;
case V_12 :
return F_5 ( V_2 , V_4 , V_6 ) ;
case V_13 :
return F_6 ( V_2 , V_4 , V_6 ) ;
case V_14 :
return F_7 ( V_2 , V_4 -> V_15 . V_16 , V_4 -> V_15 . V_17 , V_6 ) ;
case V_18 :
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
if ( ! F_8 ( V_2 -> V_22 ) )
break;
if ( F_9 ( V_2 , V_4 -> V_7 . V_16 , V_23 ) )
break;
if ( F_10 ( V_2 , V_4 -> V_7 . V_16 ) & V_23 )
return F_11 ( V_2 , V_4 -> V_7 . V_16 , V_4 -> V_7 . V_24 , V_6 ) ;
break;
case V_25 :
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
return F_12 ( V_2 , V_4 , V_6 ) ;
case V_26 :
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
return F_13 ( V_2 , V_4 -> V_27 [ 1 ] , V_4 -> V_27 , V_6 ) ;
default:
if ( V_2 -> V_19 == V_20 )
return - V_21 ;
return F_14 ( V_2 , V_4 , V_6 ) ;
}
return - V_21 ;
}
static int
F_14 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
switch ( V_4 -> V_7 . V_8 ) {
case V_28 :
return F_15 ( V_2 , 0 , V_4 -> V_29 . V_30 , V_4 -> V_29 . V_31 , V_4 -> V_29 . V_32 , V_6 ) ;
case V_33 :
return F_16 ( V_2 , 0 , V_4 -> V_29 . V_30 , V_4 -> V_29 . V_31 , V_4 -> V_29 . V_32 , V_6 ) ;
case V_34 :
break;
case V_35 :
return F_17 ( V_2 , 0 , V_36 ,
V_4 -> V_29 . V_30 , 0 , V_4 -> V_29 . V_31 , V_6 ) ;
case V_37 :
return F_18 ( V_2 -> V_38 ) ;
}
return - V_21 ;
}
static int
F_2 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
int V_39 ;
switch ( V_4 -> V_40 . V_41 ) {
case V_28 :
return F_15 ( V_2 , V_4 -> V_40 . V_16 , V_4 -> V_40 . V_30 , V_4 -> V_40 . V_42 , V_4 -> V_40 . V_43 , V_6 ) ;
case V_33 :
return F_16 ( V_2 , V_4 -> V_40 . V_16 , V_4 -> V_40 . V_30 , V_4 -> V_40 . V_42 , V_4 -> V_40 . V_43 , V_6 ) ;
case V_35 :
return F_17 ( V_2 , V_4 -> V_40 . V_16 , V_36 ,
V_4 -> V_40 . V_30 , 0 , V_4 -> V_40 . V_42 , V_6 ) ;
case V_44 :
return F_17 ( V_2 , V_4 -> V_40 . V_16 , V_45 ,
V_4 -> V_40 . V_30 , 0 , V_4 -> V_40 . V_42 , V_6 ) ;
case V_46 :
V_39 = ( char ) V_4 -> V_40 . V_42 ;
V_39 = ( V_39 + 128 ) / 2 ;
return F_17 ( V_2 , V_4 -> V_40 . V_16 , V_47 ,
V_4 -> V_40 . V_30 , V_48 , V_39 , V_6 ) ;
case V_49 :
V_39 = ( ( short ) V_4 -> V_40 . V_50 << 8 ) | ( short ) V_4 -> V_40 . V_43 ;
switch ( V_4 -> V_40 . V_42 ) {
case V_51 :
return F_17 ( V_2 , V_4 -> V_40 . V_16 ,
V_52 ,
V_4 -> V_40 . V_30 , 0 , V_39 , V_6 ) ;
case V_53 :
return F_17 ( V_2 , V_4 -> V_40 . V_16 ,
V_54 ,
V_4 -> V_40 . V_30 , 0 , V_39 * 128 / 100 , V_6 ) ;
default:
return F_17 ( V_2 , V_4 -> V_40 . V_16 ,
V_55 ,
V_4 -> V_40 . V_30 , V_4 -> V_40 . V_42 , V_39 , V_6 ) ;
}
case V_56 :
return F_13 ( V_2 , V_4 -> V_40 . V_16 , V_4 -> V_27 , V_6 ) ;
}
return - V_21 ;
}
static int
F_3 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
if ( V_4 -> V_57 . V_30 >= 32 )
return - V_21 ;
switch ( V_4 -> V_57 . V_41 ) {
case V_58 :
return F_16 ( V_2 , V_4 -> V_57 . V_16 , V_4 -> V_57 . V_30 , V_4 -> V_57 . V_31 , V_4 -> V_57 . V_59 , V_6 ) ;
case V_60 :
return F_15 ( V_2 , V_4 -> V_57 . V_16 , V_4 -> V_57 . V_30 , V_4 -> V_57 . V_31 , V_4 -> V_57 . V_59 , V_6 ) ;
case V_61 :
return F_19 ( V_2 , V_4 -> V_57 . V_16 , V_62 ,
V_4 -> V_57 . V_30 , V_4 -> V_57 . V_31 , V_4 -> V_57 . V_59 , V_6 ) ;
}
return - V_21 ;
}
static int
F_4 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
if ( V_4 -> V_63 . V_30 >= 32 )
return - V_21 ;
switch ( V_4 -> V_63 . V_41 ) {
case V_64 :
return F_17 ( V_2 , V_4 -> V_63 . V_16 , V_36 ,
V_4 -> V_63 . V_30 , 0 , V_4 -> V_63 . V_42 , V_6 ) ;
case V_65 :
return F_17 ( V_2 , V_4 -> V_63 . V_16 , V_47 ,
V_4 -> V_63 . V_30 , V_4 -> V_63 . V_42 , V_4 -> V_63 . V_39 , V_6 ) ;
case V_66 :
return F_17 ( V_2 , V_4 -> V_63 . V_16 , V_52 ,
V_4 -> V_63 . V_30 , 0 , V_4 -> V_63 . V_39 - 8192 , V_6 ) ;
case V_67 :
return F_17 ( V_2 , V_4 -> V_63 . V_16 , V_45 ,
V_4 -> V_63 . V_30 , 0 , V_4 -> V_63 . V_39 , V_6 ) ;
}
return - V_21 ;
}
static int
F_5 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
switch ( V_4 -> V_68 . V_41 ) {
case V_69 :
if ( V_2 -> V_19 == V_20 )
return F_12 ( V_2 , V_4 , V_6 ) ;
else {
union V_3 V_70 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
V_70 . V_71 = ( V_4 -> V_68 . time << 8 ) | V_25 ;
return F_12 ( V_2 , & V_70 , V_6 ) ;
}
case V_72 :
if ( V_2 -> V_19 )
return F_20 ( V_2 -> V_38 ) ;
return 0 ;
case V_73 :
if ( V_2 -> V_19 )
return F_21 ( V_2 -> V_38 ) ;
return 0 ;
case V_74 :
if ( V_2 -> V_19 )
return F_22 ( V_2 -> V_38 , V_4 -> V_68 . time ) ;
return 0 ;
}
return - V_21 ;
}
static int
F_6 ( struct V_1 * V_2 , union V_3 * V_4 , struct V_5 * V_6 )
{
return - V_21 ;
}
static int
F_16 ( struct V_1 * V_2 , int V_16 , int V_75 , int V_31 , int V_32 , struct V_5 * V_6 )
{
struct V_76 * V_77 = & V_2 -> V_78 [ V_16 ] ;
switch ( V_77 -> V_79 . V_80 ) {
case V_81 :
if ( ! V_77 -> V_75 || V_75 < 0 || V_75 >= V_77 -> V_82 ) {
return F_19 ( V_2 , V_16 , V_83 , V_75 , V_31 , V_32 , V_6 ) ;
}
if ( V_31 == 255 && V_77 -> V_75 [ V_75 ] . V_31 >= 0 ) {
int type ;
if ( V_77 -> V_75 [ V_75 ] . V_32 )
type = V_62 ;
else
type = V_83 ;
V_77 -> V_75 [ V_75 ] . V_32 = V_32 ;
return F_19 ( V_2 , V_16 , type , V_75 , V_77 -> V_75 [ V_75 ] . V_31 , V_32 , V_6 ) ;
} else if ( V_31 >= 128 )
return - V_21 ;
if ( V_31 != V_77 -> V_75 [ V_75 ] . V_31 && V_77 -> V_75 [ V_75 ] . V_31 >= 0 )
F_19 ( V_2 , V_16 , V_84 , V_75 , V_77 -> V_75 [ V_75 ] . V_31 , 0 , V_6 ) ;
V_77 -> V_75 [ V_75 ] . V_31 = V_31 ;
V_77 -> V_75 [ V_75 ] . V_32 = V_32 ;
if ( V_32 )
return F_19 ( V_2 , V_16 , V_83 , V_75 , V_31 , V_32 , V_6 ) ;
return - V_21 ;
case V_85 :
return F_19 ( V_2 , V_16 , V_83 , V_75 , V_31 , V_32 , V_6 ) ;
case V_86 :
if ( V_31 >= 128 )
return F_19 ( V_2 , V_16 , V_62 , V_75 , V_31 - 128 , V_32 , V_6 ) ;
else
return F_19 ( V_2 , V_16 , V_83 , V_75 , V_31 , V_32 , V_6 ) ;
}
return - V_21 ;
}
static int
F_15 ( struct V_1 * V_2 , int V_16 , int V_75 , int V_31 , int V_32 , struct V_5 * V_6 )
{
struct V_76 * V_77 = & V_2 -> V_78 [ V_16 ] ;
switch ( V_77 -> V_79 . V_80 ) {
case V_81 :
if ( ! V_77 -> V_75 || V_75 < 0 || V_75 >= V_77 -> V_82 ) {
return F_19 ( V_2 , V_16 , V_83 , V_75 , V_31 , V_32 , V_6 ) ;
}
if ( V_77 -> V_75 [ V_75 ] . V_31 >= 0 ) {
V_31 = V_77 -> V_75 [ V_75 ] . V_31 ;
V_77 -> V_75 [ V_75 ] . V_32 = 0 ;
V_77 -> V_75 [ V_75 ] . V_31 = - 1 ;
return F_19 ( V_2 , V_16 , V_84 , V_75 , V_31 , V_32 , V_6 ) ;
}
return - V_21 ;
case V_85 :
case V_86 :
return F_19 ( V_2 , V_16 , V_84 , V_75 , V_31 , V_32 , V_6 ) ;
}
return - V_21 ;
}
static int
F_19 ( struct V_1 * V_2 , int V_16 , int type , int V_75 , int V_31 , int V_32 , struct V_5 * V_6 )
{
if ( ! F_23 ( V_2 , V_16 ) )
return - V_87 ;
V_6 -> type = type ;
F_24 ( V_2 , V_16 , V_6 ) ;
V_6 -> V_88 . V_31 . V_89 = V_75 ;
V_6 -> V_88 . V_31 . V_31 = V_31 ;
V_6 -> V_88 . V_31 . V_90 = V_32 ;
return 0 ;
}
static int
F_17 ( struct V_1 * V_2 , int V_16 , int type , int V_75 , int V_91 , int V_39 , struct V_5 * V_6 )
{
if ( ! F_23 ( V_2 , V_16 ) )
return - V_87 ;
V_6 -> type = type ;
F_24 ( V_2 , V_16 , V_6 ) ;
V_6 -> V_88 . V_92 . V_89 = V_75 ;
V_6 -> V_88 . V_92 . V_91 = V_91 ;
V_6 -> V_88 . V_92 . V_93 = V_39 ;
return 0 ;
}
static int
F_12 ( struct V_1 * V_2 , union V_3 * V_94 , struct V_5 * V_6 )
{
V_6 -> type = V_95 ;
F_25 ( V_2 , V_6 , V_2 -> V_96 . V_97 , V_2 -> V_96 . V_98 ) ;
memcpy ( & V_6 -> V_88 , V_94 , V_99 ) ;
return 0 ;
}
int
F_26 ( struct V_5 * V_6 , int V_100 , void * V_101 ,
int V_102 , int V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_101 ;
union V_3 * V_94 ;
if ( V_6 -> type != V_95 )
return F_27 ( V_6 , V_100 , V_101 ) ;
if ( V_6 -> V_104 . V_97 != V_2 -> V_105 )
return 0 ;
V_94 = (union V_3 * ) & V_6 -> V_88 ;
if ( V_94 -> V_7 . V_8 == V_37 ) {
F_28 ( V_2 -> V_106 , V_94 -> V_68 . time ) ;
} else {
if ( V_2 -> V_107 == NULL )
return 0 ;
F_29 ( V_2 -> V_107 , V_94 ) ;
}
return 0 ;
}
