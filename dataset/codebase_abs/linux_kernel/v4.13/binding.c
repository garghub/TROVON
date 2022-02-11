static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * V_5 )
{
struct V_6 V_7 ;
struct V_8 * V_9 = V_5 -> V_9 ;
int V_10 , V_11 ;
T_1 V_12 ;
int V_13 ;
memset ( & V_7 , 0 , sizeof( V_7 ) ) ;
if ( F_2 ( & V_2 -> V_14 -> V_15 ,
V_16 ) ) {
V_13 = sizeof( V_7 ) ;
if ( V_9 -> V_17 -> V_18 == V_19 ||
! F_3 ( V_2 ) )
V_7 . V_20 = F_4 ( V_21 ) ;
else
V_7 . V_20 = F_4 ( V_22 ) ;
} else {
V_13 = V_23 ;
}
V_7 . V_24 = F_4 ( F_5 ( V_9 -> V_25 ,
V_9 -> V_26 ) ) ;
V_7 . V_3 = F_4 ( V_3 ) ;
V_7 . V_27 = F_4 ( F_5 ( V_9 -> V_25 ,
V_9 -> V_26 ) ) ;
for ( V_10 = 0 ; V_10 < V_28 ; V_10 ++ )
V_7 . V_29 [ V_10 ] = F_4 ( V_30 ) ;
for ( V_10 = 0 ; V_10 < V_5 -> V_31 ; V_10 ++ )
V_7 . V_29 [ V_10 ] = F_4 ( F_5 ( V_5 -> V_32 [ V_10 ] ,
V_5 -> V_33 [ V_10 ] ) ) ;
V_12 = 0 ;
V_11 = F_6 ( V_2 , V_34 ,
V_13 , & V_7 , & V_12 ) ;
if ( V_11 ) {
F_7 ( V_2 , L_1 ,
V_3 , V_11 ) ;
return V_11 ;
}
if ( V_12 ) {
F_7 ( V_2 , L_2 , V_12 ) ;
V_11 = - V_35 ;
}
return V_11 ;
}
static void F_8 ( void * V_36 , T_2 * V_37 ,
struct V_38 * V_39 )
{
struct V_4 * V_5 = V_36 ;
struct V_40 * V_41 = F_9 ( V_39 ) ;
if ( V_39 == V_5 -> V_42 )
return;
if ( V_41 -> V_43 != V_5 -> V_9 )
return;
if ( F_10 ( V_5 -> V_31 >= V_28 ) )
return;
V_5 -> V_32 [ V_5 -> V_31 ] = V_41 -> V_25 ;
V_5 -> V_33 [ V_5 -> V_31 ] = V_41 -> V_26 ;
V_5 -> V_31 ++ ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
struct V_8 * V_9 ,
bool V_44 )
{
struct V_40 * V_41 = F_9 ( V_39 ) ;
struct V_4 V_5 = {
. V_42 = V_39 ,
. V_9 = V_9 ,
} ;
T_1 V_3 = V_45 ;
F_12 ( & V_2 -> V_46 ) ;
F_13 ( V_2 -> V_47 ,
V_48 ,
F_8 ,
& V_5 ) ;
if ( V_5 . V_31 == 0 ) {
if ( V_44 )
V_3 = V_49 ;
else
V_3 = V_50 ;
}
if ( V_44 ) {
if ( F_10 ( V_5 . V_31 >= V_28 ) )
return - V_51 ;
V_5 . V_32 [ V_5 . V_31 ] = V_41 -> V_25 ;
V_5 . V_33 [ V_5 . V_31 ] = V_41 -> V_26 ;
V_5 . V_31 ++ ;
}
return F_1 ( V_2 , V_3 , & V_5 ) ;
}
int F_14 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_40 * V_41 = F_9 ( V_39 ) ;
if ( F_10 ( ! V_41 -> V_43 ) )
return - V_51 ;
if ( F_15 ( V_2 , V_39 , false ) )
return - V_51 ;
return F_11 ( V_2 , V_39 , V_41 -> V_43 , true ) ;
}
int F_16 ( struct V_1 * V_2 , struct V_38 * V_39 )
{
struct V_40 * V_41 = F_9 ( V_39 ) ;
int V_11 ;
if ( F_10 ( ! V_41 -> V_43 ) )
return - V_51 ;
V_11 = F_11 ( V_2 , V_39 , V_41 -> V_43 , false ) ;
if ( ! V_11 )
if ( F_15 ( V_2 , V_39 , true ) )
F_7 ( V_2 , L_3 ) ;
return V_11 ;
}
