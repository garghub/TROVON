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
static int F_19 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 . V_35 . V_36 [ 0 ] = V_15 ;
return 0 ;
}
static int F_20 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = F_15 ( V_31 ) ;
if ( V_15 == V_33 -> V_34 . V_35 . V_36 [ 0 ] )
return 0 ;
V_15 = V_33 -> V_34 . V_35 . V_36 [ 0 ] ;
F_1 ( & V_4 -> V_2 ) ;
return 1 ;
}
static int F_21 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
V_33 -> V_34 . V_35 . V_36 [ 0 ] = V_10 ;
return 0 ;
}
static int F_22 ( struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_3 * V_4 = F_15 ( V_31 ) ;
if ( V_10 == V_33 -> V_34 . V_35 . V_36 [ 0 ] )
return 0 ;
V_10 = V_33 -> V_34 . V_35 . V_36 [ 0 ] ;
F_1 ( & V_4 -> V_2 ) ;
return 1 ;
}
static int F_23 ( struct V_21 * V_22 )
{
struct V_3 * V_4 = V_22 -> V_4 ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_42 ;
F_24 ( V_4 , L_5 , 42 ) ;
V_42 = F_25 ( V_22 , 2 ) ;
if ( V_42 < 0 ) {
F_26 ( V_4 -> V_43 , L_6 ) ;
return V_42 ;
}
V_42 = F_27 ( V_22 -> V_4 , L_7 ,
V_44 | V_45 ,
& V_46 , NULL , 0 ) ;
if ( V_42 ) {
F_26 ( V_4 -> V_43 , L_8 ) ;
return V_42 ;
}
V_47 [ 0 ] . V_48 = F_28 ( V_6 -> V_49 ) ;
F_29 ( V_4 -> V_43 , V_6 -> V_49 ) ;
V_42 = F_30 ( & V_46 ,
F_31 ( V_47 ) ,
V_47 ) ;
if ( V_42 ) {
F_26 ( V_4 -> V_43 , L_9 ) ;
return V_42 ;
}
return V_42 ;
}
static int F_32 ( struct V_3 * V_4 )
{
F_33 ( & V_46 , F_31 ( V_47 ) ,
V_47 ) ;
return 0 ;
}
static int F_34 ( struct V_50 * V_51 )
{
struct V_5 * V_6 ;
struct V_52 * V_53 = V_51 -> V_43 . V_54 ;
struct V_3 * V_4 = & V_55 ;
int V_42 ;
if ( ! F_35 () && ! F_36 ( L_10 ) )
return - V_56 ;
V_4 -> V_43 = & V_51 -> V_43 ;
if ( V_53 ) {
struct V_52 * V_57 ;
V_57 = F_37 ( V_53 , L_11 , 0 ) ;
if ( ! V_57 ) {
F_26 ( & V_51 -> V_43 , L_12 ) ;
return - V_58 ;
}
V_59 [ 0 ] . V_60 = NULL ;
V_59 [ 0 ] . V_61 = NULL ;
V_59 [ 0 ] . V_62 = V_57 ;
V_59 [ 0 ] . V_63 = V_57 ;
V_57 = F_37 ( V_53 , L_13 , 0 ) ;
if ( ! V_57 ) {
F_26 ( & V_51 -> V_43 , L_14 ) ;
return - V_58 ;
}
V_59 [ 0 ] . V_64 = NULL ;
V_59 [ 0 ] . V_65 = V_57 ;
V_57 = F_37 ( V_53 , L_13 , 1 ) ;
if ( ! V_57 ) {
F_26 ( & V_51 -> V_43 , L_15 ) ;
return - V_58 ;
}
V_66 [ 0 ] . V_64 = NULL ;
V_66 [ 0 ] . V_65 = V_57 ;
V_67 [ 0 ] . V_68 = NULL ;
V_67 [ 0 ] . V_54 = V_57 ;
V_57 = F_37 ( V_53 , L_16 , 0 ) ;
if ( ! V_57 ) {
F_26 ( & V_51 -> V_43 , L_17 ) ;
return - V_58 ;
}
V_66 [ 1 ] . V_64 = NULL ;
V_66 [ 1 ] . V_65 = V_57 ;
V_67 [ 1 ] . V_68 = NULL ;
V_67 [ 1 ] . V_54 = V_57 ;
}
V_6 = F_38 ( & V_51 -> V_43 , sizeof( * V_6 ) , V_69 ) ;
if ( V_6 == NULL )
return - V_70 ;
F_39 ( V_4 , V_6 ) ;
V_6 -> V_16 = F_40 ( V_4 -> V_43 ,
L_18 ,
V_71 ) ;
if ( F_41 ( V_6 -> V_16 ) ) {
F_26 ( V_4 -> V_43 , L_19 ) ;
return F_42 ( V_6 -> V_16 ) ;
}
V_6 -> V_49 = F_40 ( V_4 -> V_43 ,
L_20 ,
V_72 ) ;
if ( F_41 ( V_6 -> V_49 ) ) {
F_26 ( V_4 -> V_43 , L_21 ) ;
return F_42 ( V_6 -> V_49 ) ;
}
V_6 -> V_73 = F_40 ( V_4 -> V_43 , L_22 ,
V_74 ) ;
if ( F_41 ( V_6 -> V_73 ) ) {
F_26 ( V_4 -> V_43 , L_23 ) ;
return F_42 ( V_6 -> V_73 ) ;
}
V_6 -> V_41 = F_40 ( V_4 -> V_43 ,
L_24 ,
V_71 ) ;
if ( F_41 ( V_6 -> V_41 ) ) {
F_26 ( V_4 -> V_43 , L_25 ) ;
return F_42 ( V_6 -> V_41 ) ;
}
V_42 = F_43 ( V_4 -> V_43 , V_4 ) ;
if ( V_42 ) {
F_26 ( & V_51 -> V_43 , L_26 , V_42 ) ;
return V_42 ;
}
return 0 ;
}
