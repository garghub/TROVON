static bool F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 V_7 = {
. V_8 = V_9 ,
} ;
V_7 . V_10 = 0 ;
while ( ! F_2 ( V_4 , V_11 , V_12 , NULL , & V_7 ) ) {
V_7 . V_10 ++ ;
switch ( V_7 . V_7 ) {
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_2 -> V_7 = V_7 . V_7 ;
return true ;
default:
break;
}
}
return false ;
}
static int F_3 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = F_4 ( V_18 ) ;
int V_21 ;
if ( ! F_1 ( & V_20 -> V_22 ) ) {
F_5 ( V_20 , L_1 ,
V_20 -> V_22 . V_5 -> V_23 ) ;
return - V_24 ;
}
F_6 ( V_20 , L_2 ,
V_20 -> V_22 . V_5 -> V_23 , V_20 -> V_22 . V_7 ) ;
V_21 = F_7 ( & V_20 -> V_25 ) ;
if ( V_21 < 0 ) {
F_5 ( V_20 , L_3 ) ;
return V_21 ;
}
return F_8 ( V_20 ) ;
}
static void F_9 ( struct V_17 * V_18 ,
struct V_3 * V_5 ,
struct V_26 * V_27 )
{
struct V_19 * V_20 = F_4 ( V_18 ) ;
if ( V_20 -> V_22 . V_5 == V_5 ) {
F_6 ( V_20 , L_4 , V_5 -> V_23 ) ;
F_10 ( V_20 ) ;
V_20 -> V_22 . V_5 = NULL ;
return;
}
F_5 ( V_20 , L_5 , V_5 -> V_23 ) ;
}
static int F_11 ( struct V_17 * V_18 ,
struct V_3 * V_5 ,
struct V_26 * V_27 )
{
struct V_19 * V_20 = F_4 ( V_18 ) ;
F_12 ( V_5 , V_20 ) ;
if ( V_20 -> V_22 . V_27 . V_28 . V_29 . V_30 == V_5 -> V_31 -> V_32 ) {
F_6 ( V_20 , L_6 , V_5 -> V_23 ) ;
V_20 -> V_22 . V_5 = V_5 ;
return 0 ;
}
F_5 ( V_20 , L_7 , V_5 -> V_23 ) ;
return - V_24 ;
}
static int F_13 ( struct V_19 * V_20 ,
struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 V_38 ;
int V_21 ;
V_21 = F_14 ( V_34 , & V_38 ) ;
if ( V_21 ) {
F_5 ( V_20 , L_8 ) ;
return - V_24 ;
}
V_36 -> type = V_38 . V_39 ;
switch ( V_36 -> type ) {
case V_40 :
F_6 ( V_20 , L_9 ) ;
V_36 -> V_41 = V_38 . V_42 . V_43 . V_41 ;
break;
case V_44 :
F_6 ( V_20 , L_10 ) ;
V_36 -> V_41 = 0 ;
break;
default:
F_5 ( V_20 , L_11 ) ;
return - V_24 ;
}
return 0 ;
}
static int F_15 ( struct V_19 * V_20 )
{
struct V_33 * V_34 , * V_45 ;
int V_21 ;
V_20 -> V_22 . V_27 . V_28 . V_29 . V_30 = NULL ;
V_20 -> V_22 . V_5 = NULL ;
V_34 = F_16 ( V_20 -> V_31 -> V_32 , 0 , 0 ) ;
if ( ! V_34 )
return 0 ;
V_45 = F_17 ( V_34 ) ;
if ( ! V_45 ) {
F_5 ( V_20 , L_12 ) ;
F_18 ( V_34 ) ;
return - V_24 ;
}
F_18 ( V_45 ) ;
V_21 = F_13 ( V_20 , V_34 , & V_20 -> V_22 . V_36 ) ;
F_18 ( V_34 ) ;
if ( V_21 )
return V_21 ;
V_20 -> V_22 . V_27 . V_28 . V_29 . V_30 = V_45 ;
V_20 -> V_22 . V_27 . V_46 = V_47 ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 )
{
struct V_26 * * V_48 = NULL ;
int V_21 ;
V_21 = F_15 ( V_20 ) ;
if ( V_21 )
return V_21 ;
if ( ! V_20 -> V_22 . V_27 . V_28 . V_29 . V_30 ) {
F_6 ( V_20 , L_13 ) ;
return - V_49 ;
}
V_48 = F_20 ( V_20 -> V_31 , sizeof( * V_48 ) , V_50 ) ;
if ( V_48 == NULL )
return - V_51 ;
V_48 [ 0 ] = & V_20 -> V_22 . V_27 ;
F_6 ( V_20 , L_14 ,
F_21 ( V_48 [ 0 ] -> V_28 . V_29 . V_30 ) ) ;
V_20 -> V_18 . V_52 = 1 ;
V_20 -> V_18 . V_48 = V_48 ;
V_20 -> V_18 . V_53 = F_11 ;
V_20 -> V_18 . V_54 = F_9 ;
V_20 -> V_18 . V_55 = F_3 ;
V_21 = F_22 ( & V_20 -> V_25 , & V_20 -> V_18 ) ;
if ( V_21 < 0 ) {
F_5 ( V_20 , L_15 ) ;
return V_21 ;
}
return 0 ;
}
static int F_23 ( struct V_56 * V_57 )
{
const struct V_58 * V_28 ;
struct V_19 * V_20 ;
struct V_59 * V_60 ;
int V_61 , V_21 ;
V_20 = F_20 ( & V_57 -> V_31 , sizeof( * V_20 ) , V_50 ) ;
if ( ! V_20 )
return - V_51 ;
V_28 = F_24 ( F_25 ( V_62 ) , & V_57 -> V_31 ) ;
if ( ! V_28 )
return - V_49 ;
V_20 -> V_31 = & V_57 -> V_31 ;
V_20 -> V_63 = (enum V_64 ) V_28 -> V_65 ;
V_60 = F_26 ( V_57 , V_66 , 0 ) ;
if ( V_60 == NULL )
return - V_24 ;
V_20 -> V_67 = F_27 ( V_20 -> V_31 , V_60 ) ;
if ( F_28 ( V_20 -> V_67 ) )
return F_29 ( V_20 -> V_67 ) ;
V_61 = F_30 ( V_57 , 0 ) ;
if ( V_61 < 0 )
return V_61 ;
V_21 = F_31 ( V_20 , V_61 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_19 ( V_20 ) ;
if ( V_21 < 0 )
goto error;
F_32 ( & V_57 -> V_31 , true ) ;
F_33 ( & V_57 -> V_31 ) ;
F_34 ( V_57 , V_20 ) ;
return 0 ;
error:
F_35 ( V_20 ) ;
return V_21 ;
}
static int F_36 ( struct V_56 * V_57 )
{
struct V_19 * V_20 = F_37 ( V_57 ) ;
F_38 ( & V_57 -> V_31 ) ;
F_39 ( & V_20 -> V_18 ) ;
F_35 ( V_20 ) ;
return 0 ;
}
