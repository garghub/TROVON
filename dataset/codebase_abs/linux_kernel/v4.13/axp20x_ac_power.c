static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 -> V_5 ) ;
return V_6 ;
}
static int F_3 ( struct V_7 * V_8 ,
enum V_9 V_10 ,
union V_11 * V_12 )
{
struct V_3 * V_4 = F_4 ( V_8 ) ;
int V_13 , V_14 ;
switch ( V_10 ) {
case V_15 :
V_13 = F_5 ( V_4 -> V_16 , V_17 , & V_14 ) ;
if ( V_13 )
return V_13 ;
if ( V_14 & V_18 ) {
V_12 -> V_19 = V_20 ;
return 0 ;
}
V_12 -> V_19 = V_21 ;
return 0 ;
case V_22 :
V_13 = F_5 ( V_4 -> V_16 , V_17 , & V_14 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_19 = ! ! ( V_14 & V_18 ) ;
return 0 ;
case V_23 :
V_13 = F_5 ( V_4 -> V_16 , V_17 , & V_14 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_19 = ! ! ( V_14 & V_24 ) ;
return 0 ;
case V_25 :
V_13 = F_6 ( V_4 -> V_26 , & V_12 -> V_19 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_19 *= 1000 ;
return 0 ;
case V_27 :
V_13 = F_6 ( V_4 -> V_28 , & V_12 -> V_19 ) ;
if ( V_13 )
return V_13 ;
V_12 -> V_19 *= 1000 ;
return 0 ;
default:
return - V_29 ;
}
return - V_29 ;
}
static int F_7 ( struct V_30 * V_31 )
{
struct V_32 * V_33 = F_8 ( V_31 -> V_34 . V_35 ) ;
struct V_36 V_37 = {} ;
struct V_3 * V_4 ;
struct V_38 * V_38 ;
static const char * const V_39 [] = { L_1 , L_2 ,
NULL } ;
int V_40 , V_1 , V_13 ;
if ( ! F_9 ( V_31 -> V_34 . V_41 ) )
return - V_42 ;
if ( ! V_33 ) {
F_10 ( & V_31 -> V_34 , L_3 ) ;
return - V_29 ;
}
V_4 = F_11 ( & V_31 -> V_34 , sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_44 ;
V_38 = (struct V_38 * ) F_12 ( & V_31 -> V_34 ) ;
if ( V_38 -> V_45 ) {
V_4 -> V_26 = F_13 ( & V_31 -> V_34 , L_4 ) ;
if ( F_14 ( V_4 -> V_26 ) ) {
if ( F_15 ( V_4 -> V_26 ) == - V_42 )
return - V_46 ;
return F_15 ( V_4 -> V_26 ) ;
}
V_4 -> V_28 = F_13 ( & V_31 -> V_34 , L_5 ) ;
if ( F_14 ( V_4 -> V_28 ) ) {
if ( F_15 ( V_4 -> V_28 ) == - V_42 )
return - V_46 ;
return F_15 ( V_4 -> V_28 ) ;
}
}
V_4 -> V_16 = F_16 ( V_31 -> V_34 . V_35 , NULL ) ;
F_17 ( V_31 , V_4 ) ;
V_37 . V_41 = V_31 -> V_34 . V_41 ;
V_37 . V_47 = V_4 ;
V_4 -> V_5 = F_18 ( & V_31 -> V_34 ,
V_38 -> V_48 ,
& V_37 ) ;
if ( F_14 ( V_4 -> V_5 ) )
return F_15 ( V_4 -> V_5 ) ;
for ( V_40 = 0 ; V_39 [ V_40 ] ; V_40 ++ ) {
V_1 = F_19 ( V_31 , V_39 [ V_40 ] ) ;
if ( V_1 < 0 ) {
F_20 ( & V_31 -> V_34 , L_6 ,
V_39 [ V_40 ] , V_1 ) ;
continue;
}
V_1 = F_21 ( V_33 -> V_49 , V_1 ) ;
V_13 = F_22 ( & V_31 -> V_34 , V_1 ,
F_1 , 0 ,
V_50 , V_4 ) ;
if ( V_13 < 0 )
F_20 ( & V_31 -> V_34 , L_7 ,
V_39 [ V_40 ] , V_13 ) ;
}
return 0 ;
}
