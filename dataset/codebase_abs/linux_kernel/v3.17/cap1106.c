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
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ )
F_6 ( V_12 -> V_19 , V_12 -> V_20 [ V_15 ] ,
V_13 & ( 1 << V_15 ) ) ;
F_7 ( V_12 -> V_19 ) ;
V_17:
return V_21 ;
}
static int F_8 ( struct V_11 * V_12 , bool V_22 )
{
return F_4 ( V_12 -> V_16 , V_4 ,
V_23 ,
V_22 ? V_23 : 0 ) ;
}
static int F_9 ( struct V_24 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
return F_8 ( V_12 , false ) ;
}
static void F_11 ( struct V_24 * V_19 )
{
struct V_11 * V_12 = F_10 ( V_19 ) ;
F_8 ( V_12 , true ) ;
}
static int F_12 ( struct V_25 * V_25 ,
const struct V_26 * V_27 )
{
struct V_1 * V_2 = & V_25 -> V_2 ;
struct V_11 * V_12 ;
struct V_28 * V_29 ;
int V_15 , error , V_30 , V_31 = 0 ;
unsigned int V_32 , V_33 ;
T_2 V_34 , V_20 [ V_18 ] ;
V_12 = F_13 ( V_2 , sizeof( * V_12 ) , V_35 ) ;
if ( ! V_12 )
return - V_36 ;
V_12 -> V_16 = F_14 ( V_25 , & V_37 ) ;
if ( F_15 ( V_12 -> V_16 ) )
return F_16 ( V_12 -> V_16 ) ;
error = F_5 ( V_12 -> V_16 , V_6 , & V_32 ) ;
if ( error )
return error ;
if ( V_32 != V_38 ) {
F_17 ( V_2 , L_1 ,
V_32 , V_38 ) ;
return - V_39 ;
}
error = F_5 ( V_12 -> V_16 , V_7 , & V_32 ) ;
if ( error )
return error ;
if ( V_32 != V_40 ) {
F_17 ( V_2 , L_2 ,
V_32 , V_40 ) ;
return - V_39 ;
}
error = F_5 ( V_12 -> V_16 , V_8 , & V_33 ) ;
if ( error < 0 )
return error ;
F_18 ( V_2 , L_3 , V_33 ) ;
F_19 ( V_25 , V_12 ) ;
V_29 = V_2 -> V_41 ;
if ( ! F_20 ( V_29 , L_4 , & V_34 ) ) {
if ( F_21 ( V_34 ) && V_34 <= 8 )
V_31 = F_22 ( V_34 ) ;
else
F_17 ( V_2 , L_5 , V_34 ) ;
}
F_23 ( F_24 ( V_20 ) != F_24 ( V_12 -> V_20 ) ) ;
for ( V_15 = 0 ; V_15 < F_24 ( V_20 ) ; V_15 ++ )
V_20 [ V_15 ] = V_42 + V_15 ;
F_25 ( V_29 , L_6 ,
V_20 , F_24 ( V_20 ) ) ;
for ( V_15 = 0 ; V_15 < F_24 ( V_20 ) ; V_15 ++ )
V_12 -> V_20 [ V_15 ] = V_20 [ V_15 ] ;
error = F_4 ( V_12 -> V_16 , V_4 ,
V_43 ,
V_31 << V_44 ) ;
if ( error )
return error ;
error = F_26 ( V_12 -> V_16 , V_45 , 0 ) ;
if ( error )
return error ;
V_12 -> V_19 = F_27 ( V_2 ) ;
if ( ! V_12 -> V_19 )
return - V_36 ;
V_12 -> V_19 -> V_46 = L_7 ;
V_12 -> V_19 -> V_27 . V_47 = V_48 ;
V_12 -> V_19 -> V_49 [ 0 ] = F_28 ( V_50 ) ;
if ( F_29 ( V_29 , L_8 ) )
F_30 ( V_51 , V_12 -> V_19 -> V_49 ) ;
for ( V_15 = 0 ; V_15 < V_18 ; V_15 ++ )
F_30 ( V_12 -> V_20 [ V_15 ] , V_12 -> V_19 -> V_52 ) ;
F_31 ( V_53 , V_12 -> V_19 -> V_52 ) ;
V_12 -> V_19 -> V_54 = V_12 -> V_20 ;
V_12 -> V_19 -> V_55 = sizeof( V_12 -> V_20 [ 0 ] ) ;
V_12 -> V_19 -> V_56 = F_24 ( V_12 -> V_20 ) ;
V_12 -> V_19 -> V_27 . V_57 = V_40 ;
V_12 -> V_19 -> V_27 . V_58 = V_38 ;
V_12 -> V_19 -> V_27 . V_59 = V_33 ;
V_12 -> V_19 -> V_60 = F_9 ;
V_12 -> V_19 -> V_61 = F_11 ;
F_32 ( V_12 -> V_19 , V_12 ) ;
F_8 ( V_12 , true ) ;
error = F_33 ( V_12 -> V_19 ) ;
if ( error )
return error ;
V_30 = F_34 ( V_29 , 0 ) ;
if ( ! V_30 ) {
F_17 ( V_2 , L_9 ) ;
return - V_62 ;
}
error = F_35 ( V_2 , V_30 , NULL , F_3 ,
V_63 , F_36 ( V_2 ) , V_12 ) ;
if ( error )
return error ;
return 0 ;
}
