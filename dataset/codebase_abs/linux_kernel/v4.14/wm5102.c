static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
struct V_12 * V_12 = V_9 -> V_12 ;
const struct V_13 * V_14 = NULL ;
int V_15 , V_16 ;
switch ( V_9 -> V_17 ) {
case 0 :
V_14 = V_18 ;
V_16 = F_4 ( V_18 ) ;
break;
default:
V_14 = V_19 ;
V_16 = F_4 ( V_19 ) ;
break;
}
switch ( V_5 ) {
case V_20 :
if ( V_14 )
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ )
F_5 ( V_12 , V_14 [ V_15 ] . V_21 ,
V_14 [ V_15 ] . V_22 ) ;
break;
case V_23 :
break;
case V_24 :
case V_25 :
return F_6 ( V_2 , V_4 , V_5 ) ;
default:
return 0 ;
}
return F_7 ( V_2 , V_4 , V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_26 = 0 ;
int V_27 ;
switch ( V_5 ) {
case V_24 :
V_27 = F_9 ( V_9 -> V_12 , V_28 , & V_26 ) ;
if ( V_27 != 0 ) {
F_10 ( V_7 -> V_10 ,
L_1 , V_27 ) ;
return - V_29 ;
}
V_26 = ( V_26 & V_30 ) >> V_31 ;
if ( V_26 >= 3 ) {
V_27 = F_11 ( V_7 , V_32 ) ;
if ( V_27 ) {
F_10 ( V_7 -> V_10 ,
L_2 , V_27 ) ;
return V_27 ;
}
}
break;
case V_25 :
V_27 = F_12 ( V_7 , V_32 ) ;
if ( V_27 )
F_13 ( V_7 -> V_10 ,
L_3 , V_27 ) ;
break;
default:
break;
}
return F_14 ( V_2 , V_4 , V_5 , V_26 ) ;
}
static int F_15 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_16 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_17 ( & V_9 -> V_35 ) ;
F_18 ( V_9 -> V_36 ,
V_34 -> V_37 . V_38 . V_39 ) ;
F_19 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_20 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_16 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_17 ( & V_9 -> V_35 ) ;
memcpy ( & V_9 -> V_36 , V_34 -> V_37 . V_38 . V_39 ,
sizeof( V_9 -> V_36 ) ) ;
V_9 -> V_36 = F_21 ( V_9 -> V_36 ) ;
F_19 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_16 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_17 ( & V_9 -> V_35 ) ;
V_34 -> V_37 . integer . V_37 [ 0 ] = V_9 -> V_40 ;
F_19 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_16 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_17 ( & V_9 -> V_35 ) ;
V_9 -> V_40 = V_34 -> V_37 . integer . V_37 [ 0 ] ;
F_19 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_24 ( struct V_6 * V_7 , int V_41 , int V_42 ,
unsigned int V_43 , unsigned int V_44 )
{
struct V_45 * V_46 = F_25 ( V_7 ) ;
switch ( V_41 ) {
case V_47 :
return F_26 ( & V_46 -> V_48 [ 0 ] , V_42 , V_43 , V_44 ) ;
case V_49 :
return F_26 ( & V_46 -> V_48 [ 1 ] , V_42 , V_43 , V_44 ) ;
case V_50 :
return F_27 ( & V_46 -> V_48 [ 0 ] , V_42 , V_43 ,
V_44 ) ;
case V_51 :
return F_27 ( & V_46 -> V_48 [ 1 ] , V_42 , V_43 ,
V_44 ) ;
default:
return - V_52 ;
}
}
static int F_28 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_45 * V_58 = F_29 ( V_56 -> V_59 ) ;
return F_30 ( & V_58 -> V_60 . V_61 [ 0 ] , V_54 ) ;
}
static T_1 F_31 ( int V_62 , void * V_39 )
{
struct V_45 * V_58 = V_39 ;
struct V_9 * V_9 = V_58 -> V_60 . V_9 ;
int V_27 ;
V_27 = F_32 ( & V_58 -> V_60 . V_61 [ 0 ] ) ;
if ( V_27 == - V_63 ) {
F_10 ( V_9 -> V_10 , L_4 ) ;
return V_64 ;
}
return V_65 ;
}
static int F_33 ( struct V_6 * V_7 )
{
struct V_66 * V_8 = F_34 ( V_7 ) ;
struct V_67 * V_68 = F_35 ( V_8 ) ;
struct V_45 * V_58 = F_25 ( V_7 ) ;
int V_27 ;
V_27 = F_36 ( & V_58 -> V_60 . V_61 [ 0 ] , V_7 ) ;
if ( V_27 )
return V_27 ;
V_27 = F_37 ( V_7 ,
V_69 , 1 ) ;
if ( V_27 )
goto V_70;
V_27 = F_38 ( V_7 ) ;
if ( V_27 < 0 )
return V_27 ;
F_39 ( V_7 ) ;
F_40 ( V_7 ) ;
F_41 ( V_68 , L_5 ) ;
V_58 -> V_60 . V_9 -> V_8 = V_8 ;
return 0 ;
V_70:
F_42 ( & V_58 -> V_60 . V_61 [ 0 ] , V_7 ) ;
return V_27 ;
}
static int F_43 ( struct V_6 * V_7 )
{
struct V_45 * V_58 = F_25 ( V_7 ) ;
F_42 ( & V_58 -> V_60 . V_61 [ 0 ] , V_7 ) ;
V_58 -> V_60 . V_9 -> V_8 = NULL ;
return 0 ;
}
static struct V_12 * F_44 ( struct V_71 * V_10 )
{
struct V_45 * V_58 = F_3 ( V_10 ) ;
return V_58 -> V_60 . V_9 -> V_12 ;
}
static int F_45 ( struct V_72 * V_73 )
{
struct V_9 * V_9 = F_3 ( V_73 -> V_10 . V_11 ) ;
struct V_45 * V_46 ;
int V_15 , V_27 ;
V_46 = F_46 ( & V_73 -> V_10 , sizeof( struct V_45 ) ,
V_74 ) ;
if ( V_46 == NULL )
return - V_75 ;
F_47 ( V_73 , V_46 ) ;
F_48 ( & V_9 -> V_35 ) ;
V_46 -> V_60 . V_9 = V_9 ;
V_46 -> V_60 . V_76 = 6 ;
F_49 ( & V_46 -> V_60 ) ;
V_46 -> V_60 . V_61 [ 0 ] . V_77 = L_6 ;
V_46 -> V_60 . V_61 [ 0 ] . V_78 = 1 ;
V_46 -> V_60 . V_61 [ 0 ] . type = V_79 ;
V_46 -> V_60 . V_61 [ 0 ] . V_80 = V_81 ;
V_46 -> V_60 . V_61 [ 0 ] . V_10 = V_9 -> V_10 ;
V_46 -> V_60 . V_61 [ 0 ] . V_12 = V_9 -> V_12 ;
V_46 -> V_60 . V_61 [ 0 ] . V_82 = V_83 ;
V_46 -> V_60 . V_61 [ 0 ] . V_84 = F_4 ( V_83 ) ;
V_27 = F_50 ( & V_46 -> V_60 . V_61 [ 0 ] ) ;
if ( V_27 != 0 )
return V_27 ;
for ( V_15 = 0 ; V_15 < F_4 ( V_46 -> V_48 ) ; V_15 ++ )
V_46 -> V_48 [ V_15 ] . V_85 = 1 ;
F_51 ( V_9 , 1 , V_86 - 1 ,
V_87 , V_88 ,
& V_46 -> V_48 [ 0 ] ) ;
F_51 ( V_9 , 2 , V_89 - 1 ,
V_90 , V_91 ,
& V_46 -> V_48 [ 1 ] ) ;
F_52 ( V_9 -> V_12 , V_92 ,
V_93 , 0x11 ) ;
F_52 ( V_9 -> V_12 , V_94 ,
V_95 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_96 ) ; V_15 ++ )
F_53 ( & V_46 -> V_60 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_97 ) ; V_15 ++ )
F_52 ( V_9 -> V_12 , V_97 [ V_15 ] ,
V_98 , V_98 ) ;
F_54 ( & V_73 -> V_10 ) ;
F_55 ( & V_73 -> V_10 ) ;
V_27 = F_56 ( V_9 , V_99 ,
L_7 , F_31 ,
V_46 ) ;
if ( V_27 != 0 ) {
F_10 ( & V_73 -> V_10 , L_8 , V_27 ) ;
return V_27 ;
}
V_27 = F_57 ( V_9 ) ;
if ( V_27 < 0 )
goto V_100;
V_27 = F_58 ( & V_73 -> V_10 , & V_101 ) ;
if ( V_27 < 0 ) {
F_10 ( & V_73 -> V_10 , L_9 , V_27 ) ;
goto V_102;
}
V_27 = F_59 ( & V_73 -> V_10 , & V_103 ,
V_96 , F_4 ( V_96 ) ) ;
if ( V_27 < 0 ) {
F_10 ( & V_73 -> V_10 , L_10 , V_27 ) ;
goto V_104;
}
return V_27 ;
V_104:
F_60 ( & V_73 -> V_10 ) ;
V_102:
F_61 ( V_9 ) ;
V_100:
F_62 ( V_9 , V_99 , V_46 ) ;
return V_27 ;
}
static int F_63 ( struct V_72 * V_73 )
{
struct V_45 * V_46 = F_64 ( V_73 ) ;
struct V_9 * V_9 = V_46 -> V_60 . V_9 ;
F_60 ( & V_73 -> V_10 ) ;
F_65 ( & V_73 -> V_10 ) ;
F_66 ( & V_73 -> V_10 ) ;
F_67 ( & V_46 -> V_60 . V_61 [ 0 ] ) ;
F_61 ( V_9 ) ;
F_62 ( V_9 , V_99 , V_46 ) ;
return 0 ;
}
