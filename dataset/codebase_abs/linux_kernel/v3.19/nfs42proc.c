static int F_1 ( T_1 * V_1 , struct V_2 * V_2 ,
T_2 V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
int V_8 ;
V_5 = F_2 ( F_3 ( V_2 ) ) ;
V_7 = F_4 ( V_5 ) ;
if ( F_5 ( V_7 ) ) {
F_6 ( V_5 ) ;
return F_7 ( V_7 ) ;
}
V_8 = F_8 ( V_1 , V_5 , V_7 , V_3 ) ;
F_9 ( V_7 ) ;
F_6 ( V_5 ) ;
return V_8 ;
}
static int F_10 ( struct V_9 * V_10 , struct V_2 * V_11 ,
T_3 V_12 , T_3 V_13 )
{
struct V_14 * V_14 = F_11 ( V_11 ) ;
struct V_15 args = {
. V_16 = F_12 ( V_14 ) ,
. V_17 = V_12 ,
. V_18 = V_13 ,
} ;
struct V_19 V_20 ;
struct V_21 * V_22 = F_13 ( V_14 ) ;
int V_23 ;
V_10 -> V_24 = & args ;
V_10 -> V_25 = & V_20 ;
V_23 = F_1 ( & args . V_26 , V_11 , V_27 ) ;
if ( V_23 )
return V_23 ;
return F_14 ( V_22 -> V_28 , V_22 , V_10 ,
& args . V_29 , & V_20 . V_30 , 0 ) ;
}
static int F_15 ( struct V_9 * V_10 , struct V_2 * V_11 ,
T_3 V_12 , T_3 V_13 )
{
struct V_21 * V_22 = F_13 ( F_11 ( V_11 ) ) ;
struct V_31 V_32 = { } ;
int V_33 ;
do {
V_33 = F_10 ( V_10 , V_11 , V_12 , V_13 ) ;
if ( V_33 == - V_34 )
return - V_35 ;
V_33 = F_16 ( V_22 , V_33 , & V_32 ) ;
} while ( V_32 . V_36 );
return V_33 ;
}
int F_17 ( struct V_2 * V_11 , T_3 V_12 , T_3 V_13 )
{
struct V_9 V_10 = {
. V_37 = & V_38 [ V_39 ] ,
} ;
struct V_14 * V_14 = F_11 ( V_11 ) ;
int V_33 ;
if ( ! F_18 ( V_14 , V_40 ) )
return - V_35 ;
V_33 = F_15 ( & V_10 , V_11 , V_12 , V_13 ) ;
if ( V_33 == - V_35 )
F_13 ( V_14 ) -> V_41 &= ~ V_40 ;
return V_33 ;
}
int F_19 ( struct V_2 * V_11 , T_3 V_12 , T_3 V_13 )
{
struct V_9 V_10 = {
. V_37 = & V_38 [ V_42 ] ,
} ;
struct V_14 * V_14 = F_11 ( V_11 ) ;
int V_33 ;
if ( ! F_18 ( V_14 , V_43 ) )
return - V_35 ;
V_33 = F_15 ( & V_10 , V_11 , V_12 , V_13 ) ;
if ( V_33 == - V_35 )
F_13 ( V_14 ) -> V_41 &= ~ V_43 ;
return V_33 ;
}
T_3 F_20 ( struct V_2 * V_11 , T_3 V_12 , int V_44 )
{
struct V_14 * V_14 = F_11 ( V_11 ) ;
struct V_45 args = {
. V_46 = F_12 ( V_14 ) ,
. V_47 = V_12 ,
. V_48 = ( V_44 == V_49 ) ?
V_50 : V_51 ,
} ;
struct V_52 V_20 ;
struct V_9 V_10 = {
. V_37 = & V_38 [ V_53 ] ,
. V_24 = & args ,
. V_25 = & V_20 ,
} ;
struct V_21 * V_22 = F_13 ( V_14 ) ;
int V_23 ;
if ( ! F_18 ( V_14 , V_54 ) )
return - V_34 ;
V_23 = F_1 ( & args . V_55 , V_11 , V_56 ) ;
if ( V_23 )
return V_23 ;
F_21 ( V_14 ) ;
V_23 = F_14 ( V_22 -> V_28 , V_22 , & V_10 ,
& args . V_29 , & V_20 . V_30 , 0 ) ;
if ( V_23 == - V_34 )
V_22 -> V_41 &= ~ V_54 ;
if ( V_23 )
return V_23 ;
return F_22 ( V_11 , V_20 . V_57 , V_14 -> V_58 -> V_59 ) ;
}
