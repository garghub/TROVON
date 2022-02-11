static bool F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
case V_5 :
case F_2 ( 0 ) :
case F_2 ( 1 ) :
case F_2 ( 2 ) :
case F_2 ( 3 ) :
case F_2 ( 4 ) :
case F_2 ( 5 ) :
case V_6 :
case V_7 :
case V_8 :
return true ;
}
return false ;
}
static T_1 F_3 ( int V_9 , void * V_10 )
{
struct V_11 * V_12 = V_10 ;
unsigned int V_13 ;
int V_14 , V_15 ;
V_14 = F_4 ( V_12 -> V_16 , V_4 , 1 , 0 ) ;
if ( V_14 < 0 )
goto V_17;
V_14 = F_5 ( V_12 -> V_16 , V_5 , & V_13 ) ;
if ( V_14 < 0 )
goto V_17;
for ( V_15 = 0 ; V_15 < V_12 -> V_18 -> V_19 ; V_15 ++ )
F_6 ( V_12 -> V_18 , V_12 -> V_20 [ V_15 ] ,
V_13 & ( 1 << V_15 ) ) ;
F_7 ( V_12 -> V_18 ) ;
V_17:
return V_21 ;
}
static int F_8 ( struct V_11 * V_12 , bool V_22 )
{
return F_4 ( V_12 -> V_16 , V_4 ,
V_23 ,
V_22 ? V_23 : 0 ) ;
}
static int F_9 ( struct V_24 * V_18 )
{
struct V_11 * V_12 = F_10 ( V_18 ) ;
return F_8 ( V_12 , false ) ;
}
static void F_11 ( struct V_24 * V_18 )
{
struct V_11 * V_12 = F_10 ( V_18 ) ;
F_8 ( V_12 , true ) ;
}
static int F_12 ( struct V_25 * V_25 ,
const struct V_26 * V_27 )
{
struct V_1 * V_2 = & V_25 -> V_2 ;
struct V_11 * V_12 ;
struct V_28 * V_29 ;
const struct V_30 * V_31 ;
int V_15 , error , V_32 , V_33 = 0 ;
unsigned int V_34 , V_35 ;
T_2 V_36 ;
if ( V_27 -> V_37 >= F_13 ( V_38 ) ) {
F_14 ( V_2 , L_1 , V_27 -> V_37 ) ;
return - V_39 ;
}
V_31 = & V_38 [ V_27 -> V_37 ] ;
if ( ! V_31 || ! V_31 -> V_40 ) {
F_14 ( V_2 , L_2 ) ;
return - V_39 ;
}
V_12 = F_15 ( V_2 ,
sizeof( * V_12 ) +
V_31 -> V_40 * sizeof( V_12 -> V_20 [ 0 ] ) ,
V_41 ) ;
if ( ! V_12 )
return - V_42 ;
V_12 -> V_16 = F_16 ( V_25 , & V_43 ) ;
if ( F_17 ( V_12 -> V_16 ) )
return F_18 ( V_12 -> V_16 ) ;
error = F_5 ( V_12 -> V_16 , V_6 , & V_34 ) ;
if ( error )
return error ;
if ( V_34 != V_31 -> V_44 ) {
F_14 ( V_2 , L_3 ,
V_34 , V_31 -> V_44 ) ;
return - V_45 ;
}
error = F_5 ( V_12 -> V_16 , V_7 , & V_34 ) ;
if ( error )
return error ;
if ( V_34 != V_46 ) {
F_14 ( V_2 , L_4 ,
V_34 , V_46 ) ;
return - V_45 ;
}
error = F_5 ( V_12 -> V_16 , V_8 , & V_35 ) ;
if ( error < 0 )
return error ;
F_19 ( V_2 , L_5 , V_35 ) ;
F_20 ( V_25 , V_12 ) ;
V_29 = V_2 -> V_47 ;
if ( ! F_21 ( V_29 , L_6 , & V_36 ) ) {
if ( F_22 ( V_36 ) && V_36 <= 8 )
V_33 = F_23 ( V_36 ) ;
else
F_14 ( V_2 , L_7 , V_36 ) ;
}
if ( F_24 ( V_29 , L_8 ) ) {
error = F_4 ( V_12 -> V_16 , V_48 ,
V_49 , 0 ) ;
if ( error )
return error ;
}
for ( V_15 = 0 ; V_15 < V_31 -> V_40 ; V_15 ++ )
V_12 -> V_20 [ V_15 ] = V_50 + V_15 ;
F_25 ( V_29 , L_9 ,
V_12 -> V_20 , V_31 -> V_40 ) ;
error = F_4 ( V_12 -> V_16 , V_4 ,
V_51 ,
V_33 << V_52 ) ;
if ( error )
return error ;
error = F_26 ( V_12 -> V_16 , V_53 , 0 ) ;
if ( error )
return error ;
V_12 -> V_18 = F_27 ( V_2 ) ;
if ( ! V_12 -> V_18 )
return - V_42 ;
V_12 -> V_18 -> V_54 = L_10 ;
V_12 -> V_18 -> V_27 . V_55 = V_56 ;
V_12 -> V_18 -> V_57 [ 0 ] = F_28 ( V_58 ) ;
if ( F_24 ( V_29 , L_11 ) )
F_29 ( V_59 , V_12 -> V_18 -> V_57 ) ;
for ( V_15 = 0 ; V_15 < V_31 -> V_40 ; V_15 ++ )
F_29 ( V_12 -> V_20 [ V_15 ] , V_12 -> V_18 -> V_60 ) ;
F_30 ( V_61 , V_12 -> V_18 -> V_60 ) ;
V_12 -> V_18 -> V_62 = V_12 -> V_20 ;
V_12 -> V_18 -> V_63 = sizeof( V_12 -> V_20 [ 0 ] ) ;
V_12 -> V_18 -> V_19 = V_31 -> V_40 ;
V_12 -> V_18 -> V_27 . V_64 = V_46 ;
V_12 -> V_18 -> V_27 . V_65 = V_31 -> V_44 ;
V_12 -> V_18 -> V_27 . V_66 = V_35 ;
V_12 -> V_18 -> V_67 = F_9 ;
V_12 -> V_18 -> V_68 = F_11 ;
F_31 ( V_12 -> V_18 , V_12 ) ;
F_8 ( V_12 , true ) ;
error = F_32 ( V_12 -> V_18 ) ;
if ( error )
return error ;
V_32 = F_33 ( V_29 , 0 ) ;
if ( ! V_32 ) {
F_14 ( V_2 , L_12 ) ;
return - V_45 ;
}
error = F_34 ( V_2 , V_32 , NULL , F_3 ,
V_69 , F_35 ( V_2 ) , V_12 ) ;
if ( error )
return error ;
return 0 ;
}
