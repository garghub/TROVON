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
default:
return 0 ;
}
return F_6 ( V_2 , V_4 , V_5 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 -> V_8 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
unsigned int V_24 = 0 ;
int V_25 ;
switch ( V_5 ) {
case V_26 :
V_25 = F_8 ( V_9 -> V_12 , V_27 , & V_24 ) ;
if ( V_25 != 0 ) {
F_9 ( V_7 -> V_10 ,
L_1 , V_25 ) ;
return - V_28 ;
}
V_24 = ( V_24 & V_29 ) >> V_30 ;
if ( V_24 >= 3 ) {
V_25 = F_10 ( V_7 , V_31 ) ;
if ( V_25 ) {
F_9 ( V_7 -> V_10 ,
L_2 , V_25 ) ;
return V_25 ;
}
}
break;
case V_32 :
V_25 = F_11 ( V_7 , V_31 ) ;
if ( V_25 )
F_12 ( V_7 -> V_10 ,
L_3 , V_25 ) ;
break;
default:
break;
}
return F_13 ( V_2 , V_4 , V_5 , V_24 ) ;
}
static int F_14 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_15 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_16 ( & V_9 -> V_35 ) ;
F_17 ( V_9 -> V_36 ,
V_34 -> V_37 . V_38 . V_39 ) ;
F_18 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_15 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_16 ( & V_9 -> V_35 ) ;
memcpy ( & V_9 -> V_36 , V_34 -> V_37 . V_38 . V_39 ,
sizeof( V_9 -> V_36 ) ) ;
V_9 -> V_36 = F_20 ( V_9 -> V_36 ) ;
F_18 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_15 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_16 ( & V_9 -> V_35 ) ;
V_34 -> V_37 . integer . V_37 [ 0 ] = V_9 -> V_40 ;
F_18 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 ,
struct V_33 * V_34 )
{
struct V_6 * V_7 = F_15 ( V_4 ) ;
struct V_9 * V_9 = F_3 ( V_7 -> V_10 -> V_11 ) ;
F_16 ( & V_9 -> V_35 ) ;
V_9 -> V_40 = V_34 -> V_37 . integer . V_37 [ 0 ] ;
F_18 ( & V_9 -> V_35 ) ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , int V_41 , int V_42 ,
unsigned int V_43 , unsigned int V_44 )
{
struct V_45 * V_46 = F_24 ( V_7 ) ;
switch ( V_41 ) {
case V_47 :
return F_25 ( & V_46 -> V_48 [ 0 ] , V_42 , V_43 , V_44 ) ;
case V_49 :
return F_25 ( & V_46 -> V_48 [ 1 ] , V_42 , V_43 , V_44 ) ;
case V_50 :
return F_26 ( & V_46 -> V_48 [ 0 ] , V_42 , V_43 ,
V_44 ) ;
case V_51 :
return F_26 ( & V_46 -> V_48 [ 1 ] , V_42 , V_43 ,
V_44 ) ;
default:
return - V_52 ;
}
}
static int F_27 ( struct V_53 * V_54 )
{
struct V_55 * V_56 = V_54 -> V_57 ;
struct V_45 * V_58 = F_24 ( V_56 -> V_7 ) ;
return F_28 ( & V_58 -> V_59 . V_60 [ 0 ] , V_54 ) ;
}
static T_1 F_29 ( int V_61 , void * V_39 )
{
struct V_45 * V_58 = V_39 ;
struct V_9 * V_9 = V_58 -> V_59 . V_9 ;
int V_25 ;
V_25 = F_30 ( & V_58 -> V_59 . V_60 [ 0 ] ) ;
if ( V_25 == - V_62 ) {
F_9 ( V_9 -> V_10 , L_4 ) ;
return V_63 ;
}
return V_64 ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_65 * V_8 = F_32 ( V_7 ) ;
struct V_45 * V_58 = F_24 ( V_7 ) ;
struct V_9 * V_9 = V_58 -> V_59 . V_9 ;
int V_25 ;
V_25 = F_33 ( V_9 , V_66 ,
L_5 , F_29 ,
V_58 ) ;
if ( V_25 != 0 ) {
F_9 ( V_7 -> V_10 , L_6 , V_25 ) ;
return V_25 ;
}
V_25 = F_34 ( & V_58 -> V_59 . V_60 [ 0 ] , V_7 ) ;
if ( V_25 )
return V_25 ;
V_25 = F_35 ( V_7 ,
V_67 , 1 ) ;
if ( V_25 )
goto V_68;
F_36 ( V_7 ) ;
F_37 ( V_7 ) ;
F_38 ( V_8 , L_7 ) ;
V_58 -> V_59 . V_9 -> V_8 = V_8 ;
return 0 ;
V_68:
F_39 ( & V_58 -> V_59 . V_60 [ 0 ] , V_7 ) ;
return V_25 ;
}
static int F_40 ( struct V_6 * V_7 )
{
struct V_45 * V_58 = F_24 ( V_7 ) ;
struct V_9 * V_9 = V_58 -> V_59 . V_9 ;
F_39 ( & V_58 -> V_59 . V_60 [ 0 ] , V_7 ) ;
V_58 -> V_59 . V_9 -> V_8 = NULL ;
F_41 ( V_9 , V_66 , V_58 ) ;
F_42 ( V_7 ) ;
return 0 ;
}
static struct V_12 * F_43 ( struct V_69 * V_10 )
{
struct V_45 * V_58 = F_3 ( V_10 ) ;
return V_58 -> V_59 . V_9 -> V_12 ;
}
static int F_44 ( struct V_70 * V_71 )
{
struct V_9 * V_9 = F_3 ( V_71 -> V_10 . V_11 ) ;
struct V_45 * V_46 ;
int V_15 , V_25 ;
V_46 = F_45 ( & V_71 -> V_10 , sizeof( struct V_45 ) ,
V_72 ) ;
if ( V_46 == NULL )
return - V_73 ;
F_46 ( V_71 , V_46 ) ;
F_47 ( & V_9 -> V_35 ) ;
V_46 -> V_59 . V_9 = V_9 ;
V_46 -> V_59 . V_74 = 6 ;
F_48 ( & V_46 -> V_59 ) ;
V_46 -> V_59 . V_60 [ 0 ] . V_75 = L_8 ;
V_46 -> V_59 . V_60 [ 0 ] . V_76 = 1 ;
V_46 -> V_59 . V_60 [ 0 ] . type = V_77 ;
V_46 -> V_59 . V_60 [ 0 ] . V_78 = V_79 ;
V_46 -> V_59 . V_60 [ 0 ] . V_10 = V_9 -> V_10 ;
V_46 -> V_59 . V_60 [ 0 ] . V_12 = V_9 -> V_12 ;
V_46 -> V_59 . V_60 [ 0 ] . V_80 = V_81 ;
V_46 -> V_59 . V_60 [ 0 ] . V_82 = F_4 ( V_81 ) ;
V_25 = F_49 ( & V_46 -> V_59 . V_60 [ 0 ] ) ;
if ( V_25 != 0 )
return V_25 ;
for ( V_15 = 0 ; V_15 < F_4 ( V_46 -> V_48 ) ; V_15 ++ )
V_46 -> V_48 [ V_15 ] . V_83 = 1 ;
F_50 ( V_9 , 1 , V_84 - 1 ,
V_85 , V_86 ,
& V_46 -> V_48 [ 0 ] ) ;
F_50 ( V_9 , 2 , V_87 - 1 ,
V_88 , V_89 ,
& V_46 -> V_48 [ 1 ] ) ;
F_51 ( V_9 -> V_12 , V_90 ,
V_91 , 0x11 ) ;
F_51 ( V_9 -> V_12 , V_92 ,
V_93 , 0x12 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_94 ) ; V_15 ++ )
F_52 ( & V_46 -> V_59 , V_15 ) ;
for ( V_15 = 0 ; V_15 < F_4 ( V_95 ) ; V_15 ++ )
F_51 ( V_9 -> V_12 , V_95 [ V_15 ] ,
V_96 , V_96 ) ;
F_53 ( & V_71 -> V_10 ) ;
F_54 ( & V_71 -> V_10 ) ;
V_25 = F_55 ( & V_71 -> V_10 , & V_97 ) ;
if ( V_25 < 0 ) {
F_9 ( & V_71 -> V_10 , L_9 , V_25 ) ;
return V_25 ;
}
V_25 = F_56 ( & V_71 -> V_10 , & V_98 ,
V_94 , F_4 ( V_94 ) ) ;
if ( V_25 < 0 ) {
F_9 ( & V_71 -> V_10 , L_10 , V_25 ) ;
F_57 ( & V_71 -> V_10 ) ;
}
return V_25 ;
}
static int F_58 ( struct V_70 * V_71 )
{
F_57 ( & V_71 -> V_10 ) ;
F_59 ( & V_71 -> V_10 ) ;
F_60 ( & V_71 -> V_10 ) ;
return 0 ;
}
