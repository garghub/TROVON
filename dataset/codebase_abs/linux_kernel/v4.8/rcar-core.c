static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 = {
. V_7 = V_8 ,
} ;
V_4 = F_2 ( V_2 ) ;
V_6 . V_9 = 0 ;
while ( ! F_3 ( V_4 , V_10 , V_11 , NULL , & V_6 ) ) {
V_6 . V_9 ++ ;
switch ( V_6 . V_6 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
V_2 -> V_16 . V_6 = V_6 . V_6 ;
F_4 ( V_2 , L_1 ,
V_2 -> V_16 . V_6 ) ;
return true ;
default:
break;
}
}
return false ;
}
static int F_5 ( struct V_17 * V_18 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
int V_19 ;
V_19 = F_7 ( & V_2 -> V_20 ) ;
if ( V_19 < 0 ) {
F_8 ( V_2 , L_2 ) ;
return V_19 ;
}
if ( ! F_1 ( V_2 ) ) {
F_8 ( V_2 , L_3 ) ;
return - V_21 ;
}
return F_9 ( V_2 ) ;
}
static void F_10 ( struct V_17 * V_18 ,
struct V_3 * V_4 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
F_11 ( V_2 ) ;
}
static int F_12 ( struct V_17 * V_18 ,
struct V_3 * V_24 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = F_6 ( V_18 ) ;
F_4 ( V_2 , L_4 , V_24 -> V_25 ) ;
V_2 -> V_26 . V_26 = & V_24 -> V_26 ;
V_2 -> V_26 . V_24 = V_24 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
struct V_27 * V_29 ;
struct V_27 * V_30 = NULL ;
struct V_27 * V_31 ;
int V_19 = 0 ;
while ( 1 ) {
V_31 = F_14 ( V_28 , V_30 ) ;
if ( ! V_31 )
break;
F_15 ( V_30 ) ;
V_30 = V_31 ;
V_29 = F_16 ( V_30 ) ;
if ( ! V_29 ) {
V_19 = - V_21 ;
break;
}
if ( V_29 == V_2 -> V_32 -> V_33 ) {
F_15 ( V_29 ) ;
continue;
}
if ( ! V_2 -> V_26 . V_28 ) {
V_2 -> V_26 . V_28 = V_29 ;
V_2 -> V_26 . V_23 . V_34 = V_35 ;
V_2 -> V_26 . V_23 . V_36 . V_37 . V_28 = V_29 ;
V_19 ++ ;
}
}
F_15 ( V_30 ) ;
return V_19 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_22 * * V_38 = NULL ;
int V_19 ;
V_19 = F_13 ( V_2 , V_2 -> V_32 -> V_33 ) ;
if ( V_19 < 0 ) {
F_8 ( V_2 , L_5 ) ;
goto V_39;
}
if ( ! V_19 ) {
F_8 ( V_2 , L_6 ) ;
goto V_39;
}
if ( V_19 != 1 ) {
F_8 ( V_2 , L_7 ) ;
goto V_39;
}
V_38 = F_18 ( V_2 -> V_32 , sizeof( * V_38 ) , V_40 ) ;
if ( V_38 == NULL ) {
V_19 = - V_41 ;
goto V_39;
}
V_38 [ 0 ] = & V_2 -> V_26 . V_23 ;
V_2 -> V_18 . V_38 = V_38 ;
V_2 -> V_18 . V_42 = 1 ;
V_2 -> V_18 . V_43 = F_12 ;
V_2 -> V_18 . V_44 = F_10 ;
V_2 -> V_18 . V_45 = F_5 ;
V_19 = F_19 ( & V_2 -> V_20 , & V_2 -> V_18 ) ;
if ( V_19 < 0 ) {
F_8 ( V_2 , L_8 ) ;
goto V_39;
}
V_19 = 0 ;
V_39:
if ( V_19 < 0 ) {
F_20 ( & V_2 -> V_18 ) ;
F_15 ( V_2 -> V_26 . V_28 ) ;
}
return V_19 ;
}
static int F_21 ( struct V_1 * V_2 )
{
const struct V_46 * V_36 ;
struct V_47 V_30 ;
struct V_27 * V_48 ;
int V_19 ;
V_36 = F_22 ( F_23 ( V_49 ) , V_2 -> V_32 ) ;
if ( ! V_36 )
return - V_50 ;
V_2 -> V_51 = (enum V_52 ) V_36 -> V_53 ;
V_48 = F_14 ( V_2 -> V_32 -> V_33 , NULL ) ;
if ( ! V_48 ) {
F_8 ( V_2 , L_9 ) ;
return - V_21 ;
}
V_19 = F_24 ( V_48 , & V_30 ) ;
if ( V_19 ) {
F_8 ( V_2 , L_10 ) ;
return V_19 ;
}
F_15 ( V_48 ) ;
V_2 -> V_54 . type = V_30 . V_55 ;
switch ( V_2 -> V_54 . type ) {
case V_56 :
V_2 -> V_54 . V_57 = V_30 . V_58 . V_59 . V_57 ;
break;
case V_60 :
V_2 -> V_54 . V_57 = 0 ;
break;
default:
F_8 ( V_2 , L_11 ) ;
return - V_21 ;
}
return 0 ;
}
static int F_25 ( struct V_61 * V_62 )
{
struct V_1 * V_2 ;
struct V_63 * V_64 ;
int V_65 , V_19 ;
V_2 = F_18 ( & V_62 -> V_32 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_2 -> V_32 = & V_62 -> V_32 ;
V_19 = F_21 ( V_2 ) ;
if ( V_19 )
return V_19 ;
V_64 = F_26 ( V_62 , V_66 , 0 ) ;
if ( V_64 == NULL )
return - V_21 ;
V_2 -> V_67 = F_27 ( V_2 -> V_32 , V_64 ) ;
if ( F_28 ( V_2 -> V_67 ) )
return F_29 ( V_2 -> V_67 ) ;
V_65 = F_30 ( V_62 , 0 ) ;
if ( V_65 <= 0 )
return V_19 ;
V_19 = F_31 ( V_2 , V_65 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_17 ( V_2 ) ;
if ( V_19 < 0 )
goto error;
F_32 ( & V_62 -> V_32 , true ) ;
F_33 ( & V_62 -> V_32 ) ;
F_34 ( V_62 , V_2 ) ;
return 0 ;
error:
F_35 ( V_2 ) ;
return V_19 ;
}
static int F_36 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_37 ( V_62 ) ;
F_38 ( & V_62 -> V_32 ) ;
F_20 ( & V_2 -> V_18 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
