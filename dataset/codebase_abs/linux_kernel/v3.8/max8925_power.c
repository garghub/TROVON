static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 ) {
if ( V_2 -> V_6 )
V_2 -> V_6 ( 1 ) ;
F_2 ( V_2 -> V_7 , V_8 , 1 << 7 , 0 ) ;
} else {
F_2 ( V_2 -> V_7 , V_8 , 1 << 7 , 1 << 7 ) ;
if ( V_2 -> V_6 )
V_2 -> V_6 ( 0 ) ;
}
F_3 ( V_5 -> V_9 , L_1 , ( V_3 ) ? L_2
: L_3 ) ;
return 0 ;
}
static T_1 F_4 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
struct V_4 * V_5 = V_2 -> V_5 ;
switch ( V_10 - V_5 -> V_12 ) {
case V_13 :
V_2 -> V_14 = 1 ;
F_1 ( V_2 , 1 ) ;
F_3 ( V_5 -> V_9 , L_4 ) ;
break;
case V_15 :
V_2 -> V_14 = 0 ;
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_5 ) ;
break;
case V_16 :
F_3 ( V_5 -> V_9 , L_6 ) ;
case V_17 :
F_3 ( V_5 -> V_9 , L_7 ) ;
F_1 ( V_2 , 0 ) ;
break;
case V_18 :
F_3 ( V_5 -> V_9 , L_8 ) ;
break;
case V_19 :
F_5 ( V_5 -> V_9 , L_9 ) ;
break;
case V_20 :
F_3 ( V_5 -> V_9 , L_10 ) ;
break;
case V_21 :
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_11 ) ;
break;
case V_22 :
F_3 ( V_5 -> V_9 , L_12 ) ;
break;
case V_23 :
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_13 ) ;
break;
case V_24 :
F_1 ( V_2 , 0 ) ;
F_3 ( V_5 -> V_9 , L_14 ) ;
break;
}
return V_25 ;
}
static int F_6 ( struct V_1 * V_2 , int type )
{
unsigned char V_26 [ 2 ] = { 0 , 0 } ;
int V_27 ;
int V_28 = 0 , V_29 ;
switch ( type ) {
case V_30 :
V_27 = V_31 ;
V_28 = V_32 ;
break;
case V_33 :
V_27 = V_34 ;
V_28 = V_35 ;
break;
case V_36 :
V_27 = V_37 ;
V_28 = V_38 ;
break;
case V_39 :
V_27 = V_40 ;
V_28 = V_41 ;
break;
default:
return - V_42 ;
}
F_7 ( V_2 -> V_43 , V_27 , 0 ) ;
F_8 ( V_2 -> V_43 , V_28 , 2 , V_26 ) ;
V_29 = ( ( V_26 [ 0 ] << 8 ) | V_26 [ 1 ] ) >> 4 ;
return V_29 ;
}
static int F_9 ( struct V_44 * V_45 ,
enum V_46 V_47 ,
union V_48 * V_49 )
{
struct V_1 * V_2 = F_10 ( V_45 -> V_9 -> V_50 ) ;
int V_29 = 0 ;
switch ( V_47 ) {
case V_51 :
V_49 -> V_52 = V_2 -> V_14 ;
break;
case V_53 :
if ( V_2 -> V_14 ) {
V_29 = F_6 ( V_2 , V_30 ) ;
if ( V_29 >= 0 ) {
V_49 -> V_52 = V_29 * 2000 ;
goto V_54;
}
}
V_29 = - V_55 ;
break;
default:
V_29 = - V_56 ;
break;
}
V_54:
return V_29 ;
}
static int F_11 ( struct V_44 * V_45 ,
enum V_46 V_47 ,
union V_48 * V_49 )
{
struct V_1 * V_2 = F_10 ( V_45 -> V_9 -> V_50 ) ;
int V_29 = 0 ;
switch ( V_47 ) {
case V_51 :
V_49 -> V_52 = V_2 -> V_57 ;
break;
case V_53 :
if ( V_2 -> V_57 ) {
V_29 = F_6 ( V_2 , V_30 ) ;
if ( V_29 >= 0 ) {
V_49 -> V_52 = V_29 * 2000 ;
goto V_54;
}
}
V_29 = - V_55 ;
break;
default:
V_29 = - V_56 ;
break;
}
V_54:
return V_29 ;
}
static int F_12 ( struct V_44 * V_45 ,
enum V_46 V_47 ,
union V_48 * V_49 )
{
struct V_1 * V_2 = F_10 ( V_45 -> V_9 -> V_50 ) ;
int V_29 = 0 ;
switch ( V_47 ) {
case V_51 :
V_49 -> V_52 = V_2 -> V_58 ;
break;
case V_53 :
if ( V_2 -> V_58 ) {
V_29 = F_6 ( V_2 , V_36 ) ;
if ( V_29 >= 0 ) {
V_49 -> V_52 = V_29 * 2000 ;
V_29 = 0 ;
break;
}
}
V_29 = - V_55 ;
break;
case V_59 :
if ( V_2 -> V_58 ) {
V_29 = F_6 ( V_2 , V_39 ) ;
if ( V_29 >= 0 ) {
V_29 = ( ( V_29 * 6250 ) - 3125 ) ;
V_49 -> V_52 = 0 ;
if ( V_29 > 0 )
V_49 -> V_52 = V_29 ;
V_29 = 0 ;
break;
}
}
V_29 = - V_55 ;
break;
case V_60 :
if ( ! V_2 -> V_58 ) {
V_29 = - V_55 ;
break;
}
V_29 = F_13 ( V_2 -> V_7 , V_61 ) ;
V_29 = ( V_29 & V_62 ) >> 2 ;
switch ( V_29 ) {
case 1 :
V_49 -> V_52 = V_63 ;
break;
case 0 :
case 2 :
V_49 -> V_52 = V_64 ;
break;
case 3 :
V_49 -> V_52 = V_65 ;
break;
}
V_29 = 0 ;
break;
case V_66 :
if ( ! V_2 -> V_58 ) {
V_29 = - V_55 ;
break;
}
V_29 = F_13 ( V_2 -> V_7 , V_61 ) ;
if ( V_2 -> V_57 || V_2 -> V_14 ) {
V_49 -> V_52 = V_67 ;
if ( V_29 & V_68 )
V_49 -> V_52 = V_69 ;
} else
V_49 -> V_52 = V_70 ;
V_29 = 0 ;
break;
default:
V_29 = - V_56 ;
break;
}
return V_29 ;
}
static int F_14 ( struct V_4 * V_5 ,
struct V_1 * V_2 )
{
int V_29 ;
F_15 ( V_17 , L_15 ) ;
if ( ! V_2 -> V_71 ) {
F_15 ( V_15 , L_16 ) ;
F_15 ( V_13 , L_17 ) ;
}
if ( ! V_2 -> V_72 ) {
F_15 ( V_18 , L_18 ) ;
F_15 ( V_16 , L_19 ) ;
}
F_15 ( V_20 , L_20 ) ;
F_15 ( V_19 , L_21 ) ;
F_15 ( V_24 , L_22 ) ;
F_15 ( V_21 , L_23 ) ;
F_15 ( V_22 , L_24 ) ;
F_15 ( V_23 , L_25 ) ;
V_2 -> V_57 = 0 ;
V_2 -> V_58 = 0 ;
if ( F_6 ( V_2 , V_30 ) * 2000 > 500000 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
V_29 = F_13 ( V_2 -> V_7 , V_61 ) ;
if ( V_29 >= 0 ) {
if ( V_2 -> V_73 )
V_2 -> V_58 = ( V_29 & V_74 ) ? 0 : 1 ;
else
V_2 -> V_58 = 1 ;
if ( V_29 & V_75 )
V_2 -> V_14 = 1 ;
else
V_2 -> V_14 = 0 ;
}
F_2 ( V_2 -> V_7 , V_8 , 1 << 7 , 1 << 7 ) ;
F_2 ( V_2 -> V_7 , V_8 , 3 << 5 ,
V_2 -> V_76 << 5 ) ;
F_2 ( V_2 -> V_7 , V_8 , 7 , V_2 -> V_77 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_10 ;
V_10 = V_5 -> V_12 + V_17 ;
for (; V_10 <= V_5 -> V_12 + V_23 ; V_10 ++ )
F_17 ( V_10 , V_2 ) ;
return 0 ;
}
static struct V_78 *
F_18 ( struct V_79 * V_80 )
{
struct V_81 * V_82 = V_80 -> V_9 . V_50 -> V_83 ;
struct V_81 * V_84 ;
int V_73 ;
int V_76 ;
int V_77 ;
int V_72 ;
int V_71 ;
struct V_78 * V_85 ;
if ( ! V_82 )
return V_80 -> V_9 . V_86 ;
V_84 = F_19 ( V_82 , L_26 ) ;
if ( ! V_84 ) {
F_20 ( & V_80 -> V_9 , L_27 ) ;
return NULL ;
}
V_85 = F_21 ( & V_80 -> V_9 ,
sizeof( struct V_78 ) ,
V_87 ) ;
F_22 ( V_84 , L_28 , & V_76 ) ;
F_22 ( V_84 , L_29 , & V_73 ) ;
F_22 ( V_84 , L_30 , & V_77 ) ;
F_22 ( V_84 , L_31 , & V_71 ) ;
F_22 ( V_84 , L_32 , & V_72 ) ;
V_85 -> V_73 = V_73 ;
V_85 -> V_77 = V_77 ;
V_85 -> V_76 = V_76 ;
V_85 -> V_71 = V_71 ;
V_85 -> V_72 = V_72 ;
return V_85 ;
}
static struct V_78 *
F_18 ( struct V_79 * V_80 )
{
return V_80 -> V_9 . V_86 ;
}
static int F_23 ( struct V_79 * V_80 )
{
struct V_4 * V_5 = F_10 ( V_80 -> V_9 . V_50 ) ;
struct V_78 * V_85 = NULL ;
struct V_1 * V_2 ;
int V_29 ;
V_85 = F_18 ( V_80 ) ;
if ( ! V_85 ) {
F_20 ( & V_80 -> V_9 , L_33
L_34 ) ;
return - V_42 ;
}
V_2 = F_24 ( sizeof( struct V_1 ) , V_87 ) ;
if ( ! V_2 )
return - V_88 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_7 = V_5 -> V_89 ;
V_2 -> V_43 = V_5 -> V_43 ;
F_25 ( V_80 , V_2 ) ;
V_2 -> V_90 . V_91 = L_35 ;
V_2 -> V_90 . type = V_92 ;
V_2 -> V_90 . V_93 = V_94 ;
V_2 -> V_90 . V_95 = F_26 ( V_94 ) ;
V_2 -> V_90 . V_96 = F_9 ;
V_2 -> V_90 . V_97 = V_85 -> V_97 ;
V_2 -> V_90 . V_98 = V_85 -> V_98 ;
V_29 = F_27 ( & V_80 -> V_9 , & V_2 -> V_90 ) ;
if ( V_29 )
goto V_54;
V_2 -> V_90 . V_9 -> V_50 = & V_80 -> V_9 ;
V_2 -> V_99 . V_91 = L_36 ;
V_2 -> V_99 . type = V_100 ;
V_2 -> V_99 . V_93 = V_101 ;
V_2 -> V_99 . V_95 = F_26 ( V_101 ) ;
V_2 -> V_99 . V_96 = F_11 ;
V_2 -> V_99 . V_97 = V_85 -> V_97 ;
V_2 -> V_99 . V_98 = V_85 -> V_98 ;
V_29 = F_27 ( & V_80 -> V_9 , & V_2 -> V_99 ) ;
if ( V_29 )
goto V_102;
V_2 -> V_99 . V_9 -> V_50 = & V_80 -> V_9 ;
V_2 -> V_103 . V_91 = L_37 ;
V_2 -> V_103 . type = V_104 ;
V_2 -> V_103 . V_93 = V_105 ;
V_2 -> V_103 . V_95 = F_26 ( V_105 ) ;
V_2 -> V_103 . V_96 = F_12 ;
V_29 = F_27 ( & V_80 -> V_9 , & V_2 -> V_103 ) ;
if ( V_29 )
goto V_106;
V_2 -> V_103 . V_9 -> V_50 = & V_80 -> V_9 ;
V_2 -> V_73 = V_85 -> V_73 ;
V_2 -> V_76 = V_85 -> V_76 ;
V_2 -> V_77 = V_85 -> V_77 ;
V_2 -> V_6 = V_85 -> V_6 ;
V_2 -> V_72 = V_85 -> V_72 ;
V_2 -> V_71 = V_85 -> V_71 ;
F_14 ( V_5 , V_2 ) ;
return 0 ;
V_106:
F_28 ( & V_2 -> V_103 ) ;
V_102:
F_28 ( & V_2 -> V_90 ) ;
V_54:
F_29 ( V_2 ) ;
return V_29 ;
}
static int F_30 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_31 ( V_80 ) ;
if ( V_2 ) {
F_28 ( & V_2 -> V_90 ) ;
F_28 ( & V_2 -> V_99 ) ;
F_28 ( & V_2 -> V_103 ) ;
F_16 ( V_2 ) ;
F_29 ( V_2 ) ;
}
return 0 ;
}
