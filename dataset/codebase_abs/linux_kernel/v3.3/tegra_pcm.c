static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
struct V_8 * V_9 ;
unsigned long V_10 ;
V_9 = & V_2 -> V_9 [ V_2 -> V_11 ] ;
V_2 -> V_11 = 1 - V_2 -> V_11 ;
V_10 = V_6 -> V_10 + V_2 -> V_12 ;
V_2 -> V_12 += V_9 -> V_13 ;
if ( V_2 -> V_12 >= V_2 -> V_14 )
V_2 -> V_12 = 0 ;
if ( V_4 -> V_15 == V_16 )
V_9 -> V_17 = V_10 ;
else
V_9 -> V_18 = V_10 ;
F_2 ( V_2 -> V_19 , V_9 ) ;
}
static void F_3 ( struct V_8 * V_20 )
{
struct V_1 * V_2 = (struct V_1 * ) V_20 -> V_21 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_22 * V_23 = V_4 -> V_23 ;
F_4 ( & V_2 -> V_24 ) ;
if ( ! V_2 -> V_25 ) {
F_5 ( & V_2 -> V_24 ) ;
return;
}
if ( ++ V_2 -> V_26 >= V_23 -> V_27 )
V_2 -> V_26 = 0 ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_24 ) ;
F_6 ( V_4 ) ;
}
static void F_7 ( struct V_8 * V_20 ,
struct V_28 * V_29 )
{
V_20 -> V_30 = F_3 ;
V_20 -> V_31 = false ;
V_20 -> V_18 = V_29 -> V_10 ;
V_20 -> V_32 = V_29 -> V_33 ;
V_20 -> V_34 = 32 ;
V_20 -> V_35 = 0 ;
V_20 -> V_36 = V_29 -> V_37 ;
V_20 -> V_38 = V_29 -> V_38 ;
}
static void F_8 ( struct V_8 * V_20 ,
struct V_28 * V_29 )
{
V_20 -> V_30 = F_3 ;
V_20 -> V_31 = true ;
V_20 -> V_17 = V_29 -> V_10 ;
V_20 -> V_32 = 0 ;
V_20 -> V_34 = V_29 -> V_37 ;
V_20 -> V_35 = V_29 -> V_33 ;
V_20 -> V_36 = 32 ;
V_20 -> V_38 = V_29 -> V_38 ;
}
static int F_9 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_1 * V_2 ;
struct V_39 * V_40 = V_4 -> V_41 ;
struct V_28 * V_29 ;
int V_42 = 0 ;
V_2 = F_10 ( sizeof( struct V_1 ) , V_43 ) ;
if ( V_2 == NULL )
return - V_44 ;
V_23 -> V_41 = V_2 ;
V_2 -> V_4 = V_4 ;
F_11 ( & V_2 -> V_24 ) ;
if ( V_4 -> V_15 == V_16 ) {
V_29 = F_12 ( V_40 -> V_45 , V_4 ) ;
F_7 ( & V_2 -> V_9 [ 0 ] , V_29 ) ;
F_7 ( & V_2 -> V_9 [ 1 ] , V_29 ) ;
} else {
V_29 = F_12 ( V_40 -> V_45 , V_4 ) ;
F_8 ( & V_2 -> V_9 [ 0 ] , V_29 ) ;
F_8 ( & V_2 -> V_9 [ 1 ] , V_29 ) ;
}
V_2 -> V_9 [ 0 ] . V_21 = V_2 ;
V_2 -> V_9 [ 1 ] . V_21 = V_2 ;
V_2 -> V_19 = F_13 ( V_46 ) ;
if ( V_2 -> V_19 == NULL ) {
V_42 = - V_44 ;
goto V_47;
}
F_14 ( V_4 , & V_48 ) ;
V_42 = F_15 ( V_23 ,
V_49 ) ;
if ( V_42 < 0 )
goto V_47;
return 0 ;
V_47:
if ( V_2 -> V_19 ) {
F_16 ( V_2 -> V_19 ) ;
}
F_17 ( V_2 ) ;
return V_42 ;
}
static int F_18 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_41 ;
F_16 ( V_2 -> V_19 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int F_19 ( struct V_3 * V_4 ,
struct V_50 * V_51 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_41 ;
F_20 ( V_4 , & V_4 -> V_7 ) ;
V_2 -> V_9 [ 0 ] . V_13 = F_21 ( V_51 ) ;
V_2 -> V_9 [ 1 ] . V_13 = V_2 -> V_9 [ 0 ] . V_13 ;
return 0 ;
}
static int F_22 ( struct V_3 * V_4 )
{
F_20 ( V_4 , NULL ) ;
return 0 ;
}
static int F_23 ( struct V_3 * V_4 , int V_52 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_41 ;
unsigned long V_53 ;
switch ( V_52 ) {
case V_54 :
V_2 -> V_12 = 0 ;
V_2 -> V_14 = F_24 ( V_23 , V_23 -> V_27 * V_23 -> V_55 ) ;
V_2 -> V_26 = 0 ;
V_2 -> V_11 = 0 ;
case V_56 :
case V_57 :
F_25 ( & V_2 -> V_24 , V_53 ) ;
V_2 -> V_25 = 1 ;
F_26 ( & V_2 -> V_24 , V_53 ) ;
F_1 ( V_2 ) ;
F_1 ( V_2 ) ;
break;
case V_58 :
case V_59 :
case V_60 :
F_25 ( & V_2 -> V_24 , V_53 ) ;
V_2 -> V_25 = 0 ;
F_26 ( & V_2 -> V_24 , V_53 ) ;
F_27 ( V_2 -> V_19 , & V_2 -> V_9 [ 0 ] ) ;
F_27 ( V_2 -> V_19 , & V_2 -> V_9 [ 1 ] ) ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static T_1 F_28 ( struct V_3 * V_4 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
struct V_1 * V_2 = V_23 -> V_41 ;
return V_2 -> V_26 * V_23 -> V_55 ;
}
static int F_29 ( struct V_3 * V_4 ,
struct V_62 * V_63 )
{
struct V_22 * V_23 = V_4 -> V_23 ;
return F_30 ( V_4 -> V_64 -> V_65 -> V_21 , V_63 ,
V_23 -> V_66 ,
V_23 -> V_67 ,
V_23 -> V_68 ) ;
}
static int F_31 ( struct V_69 * V_64 , int V_15 )
{
struct V_3 * V_4 = V_64 -> V_70 [ V_15 ] . V_4 ;
struct V_5 * V_6 = & V_4 -> V_7 ;
T_2 V_13 = V_48 . V_71 ;
V_6 -> V_72 = F_32 ( V_64 -> V_65 -> V_21 , V_13 ,
& V_6 -> V_10 , V_43 ) ;
if ( ! V_6 -> V_72 )
return - V_44 ;
V_6 -> V_21 . type = V_73 ;
V_6 -> V_21 . V_21 = V_64 -> V_65 -> V_21 ;
V_6 -> V_41 = NULL ;
V_6 -> V_74 = V_13 ;
return 0 ;
}
static void F_33 ( struct V_69 * V_64 , int V_15 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_4 = V_64 -> V_70 [ V_15 ] . V_4 ;
if ( ! V_4 )
return;
V_6 = & V_4 -> V_7 ;
if ( ! V_6 -> V_72 )
return;
F_34 ( V_64 -> V_65 -> V_21 , V_6 -> V_74 ,
V_6 -> V_72 , V_6 -> V_10 ) ;
V_6 -> V_72 = NULL ;
}
static int F_35 ( struct V_39 * V_40 )
{
struct V_75 * V_65 = V_40 -> V_65 -> V_75 ;
struct V_69 * V_64 = V_40 -> V_64 ;
int V_42 = 0 ;
if ( ! V_65 -> V_21 -> V_76 )
V_65 -> V_21 -> V_76 = & V_77 ;
if ( ! V_65 -> V_21 -> V_78 )
V_65 -> V_21 -> V_78 = 0xffffffff ;
if ( V_64 -> V_70 [ V_16 ] . V_4 ) {
V_42 = F_31 ( V_64 ,
V_16 ) ;
if ( V_42 )
goto V_47;
}
if ( V_64 -> V_70 [ V_79 ] . V_4 ) {
V_42 = F_31 ( V_64 ,
V_79 ) ;
if ( V_42 )
goto V_80;
}
return 0 ;
V_80:
F_33 ( V_64 , V_16 ) ;
V_47:
return V_42 ;
}
static void F_36 ( struct V_69 * V_64 )
{
F_33 ( V_64 , V_79 ) ;
F_33 ( V_64 , V_16 ) ;
}
static int T_3 F_37 ( struct V_81 * V_82 )
{
return F_38 ( & V_82 -> V_21 , & V_83 ) ;
}
static int T_4 F_39 ( struct V_81 * V_82 )
{
F_40 ( & V_82 -> V_21 ) ;
return 0 ;
}
