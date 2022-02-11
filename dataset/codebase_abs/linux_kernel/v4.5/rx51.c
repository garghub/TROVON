static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = 0 , V_8 = 0 , V_9 = 0 ;
switch ( V_10 ) {
case V_11 :
V_9 = 1 ;
V_7 = 1 ;
break;
case V_12 :
V_8 = 1 ;
case V_13 :
V_7 = 1 ;
break;
}
F_3 ( V_2 ) ;
if ( V_14 )
F_4 ( V_2 , L_1 ) ;
else
F_5 ( V_2 , L_1 ) ;
if ( V_15 )
F_4 ( V_2 , L_2 ) ;
else
F_5 ( V_2 , L_2 ) ;
if ( V_7 )
F_4 ( V_2 , L_3 ) ;
else
F_5 ( V_2 , L_3 ) ;
if ( V_8 )
F_4 ( V_2 , L_4 ) ;
else
F_5 ( V_2 , L_4 ) ;
F_6 ( V_6 -> V_16 , V_9 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static int F_9 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_20 ;
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_3 * V_4 = V_22 -> V_4 ;
F_10 ( V_20 , V_24 , 2 ) ;
F_1 ( & V_4 -> V_2 ) ;
return 0 ;
}
static int F_11 ( struct V_17 * V_18 ,
struct V_25 * V_26 )
{
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_27 * V_28 = V_22 -> V_28 ;
return F_12 ( V_28 , 0 , 19200000 ,
V_29 ) ;
}
static int F_13 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 . V_35 . V_36 [ 0 ] = V_14 ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = F_15 ( V_31 ) ;
if ( V_14 == V_33 -> V_34 . V_35 . V_36 [ 0 ] )
return 0 ;
V_14 = V_33 -> V_34 . V_35 . V_36 [ 0 ] ;
F_1 ( & V_4 -> V_2 ) ;
return 1 ;
}
static int F_16 ( struct V_37 * V_38 ,
struct V_30 * V_39 , int V_40 )
{
struct V_1 * V_2 = V_38 -> V_2 ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_17 ( V_6 -> V_41 ,
! ! F_18 ( V_40 ) ) ;
return 0 ;
}
static int F_19 ( struct V_37 * V_38 ,
struct V_30 * V_39 , int V_40 )
{
struct V_42 * V_43 = F_20 ( V_38 -> V_2 ) ;
if ( F_18 ( V_40 ) )
F_21 ( V_43 , 1 ) ;
else
F_21 ( V_43 , 0 ) ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 . V_35 . V_36 [ 0 ] = V_15 ;
return 0 ;
}
static int F_23 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = F_15 ( V_31 ) ;
if ( V_15 == V_33 -> V_34 . V_35 . V_36 [ 0 ] )
return 0 ;
V_15 = V_33 -> V_34 . V_35 . V_36 [ 0 ] ;
F_1 ( & V_4 -> V_2 ) ;
return 1 ;
}
static int F_24 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 . V_35 . V_36 [ 0 ] = V_10 ;
return 0 ;
}
static int F_25 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = F_15 ( V_31 ) ;
if ( V_10 == V_33 -> V_34 . V_35 . V_36 [ 0 ] )
return 0 ;
V_10 = V_33 -> V_34 . V_35 . V_36 [ 0 ] ;
F_1 ( & V_4 -> V_2 ) ;
return 1 ;
}
static int F_26 ( struct V_21 * V_22 )
{
struct V_42 * V_43 = V_22 -> V_43 ;
struct V_3 * V_4 = V_22 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_44 ;
V_44 = F_27 ( V_43 ) ;
if ( V_44 < 0 ) {
F_28 ( V_4 -> V_45 , L_5 ) ;
return V_44 ;
}
F_29 ( V_4 , L_6 , 42 ) ;
V_44 = F_30 ( V_22 , 2 ) ;
if ( V_44 < 0 ) {
F_28 ( V_4 -> V_45 , L_7 ) ;
return V_44 ;
}
V_44 = F_31 ( V_22 -> V_4 , L_8 ,
V_46 | V_47 ,
& V_48 , NULL , 0 ) ;
if ( V_44 ) {
F_28 ( V_4 -> V_45 , L_9 ) ;
return V_44 ;
}
V_49 [ 0 ] . V_50 = F_32 ( V_6 -> V_51 ) ;
F_33 ( V_4 -> V_45 , V_6 -> V_51 ) ;
V_44 = F_34 ( & V_48 ,
F_35 ( V_49 ) ,
V_49 ) ;
if ( V_44 ) {
F_28 ( V_4 -> V_45 , L_10 ) ;
return V_44 ;
}
return V_44 ;
}
static int F_36 ( struct V_3 * V_4 )
{
F_37 ( & V_48 , F_35 ( V_49 ) ,
V_49 ) ;
return 0 ;
}
static int F_38 ( struct V_52 * V_53 )
{
struct V_5 * V_6 ;
struct V_54 * V_55 = V_53 -> V_45 . V_56 ;
struct V_3 * V_4 = & V_57 ;
int V_44 ;
if ( ! F_39 () && ! F_40 ( L_11 ) )
return - V_58 ;
V_4 -> V_45 = & V_53 -> V_45 ;
if ( V_55 ) {
struct V_54 * V_59 ;
V_59 = F_41 ( V_55 , L_12 , 0 ) ;
if ( ! V_59 ) {
F_28 ( & V_53 -> V_45 , L_13 ) ;
return - V_60 ;
}
V_61 [ 0 ] . V_62 = NULL ;
V_61 [ 0 ] . V_63 = NULL ;
V_61 [ 0 ] . V_64 = V_59 ;
V_61 [ 0 ] . V_65 = V_59 ;
V_59 = F_41 ( V_55 , L_14 , 0 ) ;
if ( ! V_59 ) {
F_28 ( & V_53 -> V_45 , L_15 ) ;
return - V_60 ;
}
V_61 [ 0 ] . V_66 = NULL ;
V_61 [ 0 ] . V_67 = V_59 ;
V_59 = F_41 ( V_55 , L_14 , 1 ) ;
if ( ! V_59 ) {
F_28 ( & V_53 -> V_45 , L_16 ) ;
return - V_60 ;
}
V_68 [ 0 ] . V_66 = NULL ;
V_68 [ 0 ] . V_67 = V_59 ;
V_69 [ 0 ] . V_70 = NULL ;
V_69 [ 0 ] . V_56 = V_59 ;
V_59 = F_41 ( V_55 , L_17 , 0 ) ;
if ( ! V_59 ) {
F_28 ( & V_53 -> V_45 , L_18 ) ;
return - V_60 ;
}
}
V_6 = F_42 ( & V_53 -> V_45 , sizeof( * V_6 ) , V_71 ) ;
if ( V_6 == NULL ) {
F_28 ( V_4 -> V_45 , L_19 ) ;
return - V_72 ;
}
F_43 ( V_4 , V_6 ) ;
V_6 -> V_16 = F_44 ( V_4 -> V_45 ,
L_20 ,
V_73 ) ;
if ( F_45 ( V_6 -> V_16 ) ) {
F_28 ( V_4 -> V_45 , L_21 ) ;
return F_46 ( V_6 -> V_16 ) ;
}
V_6 -> V_51 = F_44 ( V_4 -> V_45 ,
L_22 ,
V_74 ) ;
if ( F_45 ( V_6 -> V_51 ) ) {
F_28 ( V_4 -> V_45 , L_23 ) ;
return F_46 ( V_6 -> V_51 ) ;
}
V_6 -> V_75 = F_44 ( V_4 -> V_45 , L_24 ,
V_76 ) ;
if ( F_45 ( V_6 -> V_75 ) ) {
F_28 ( V_4 -> V_45 , L_25 ) ;
return F_46 ( V_6 -> V_75 ) ;
}
V_6 -> V_41 = F_44 ( V_4 -> V_45 ,
L_26 ,
V_73 ) ;
if ( F_45 ( V_6 -> V_41 ) ) {
F_28 ( V_4 -> V_45 , L_27 ) ;
return F_46 ( V_6 -> V_41 ) ;
}
V_44 = F_47 ( V_4 -> V_45 , V_4 ) ;
if ( V_44 ) {
F_28 ( & V_53 -> V_45 , L_28 , V_44 ) ;
return V_44 ;
}
return 0 ;
}
