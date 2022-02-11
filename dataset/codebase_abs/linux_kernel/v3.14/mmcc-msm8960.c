static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
int V_4 ;
int V_5 = 0 ;
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
struct V_9 * V_9 = V_2 -> V_9 ;
int V_10 = F_3 ( V_2 -> V_9 ) ;
for ( V_4 = 0 ; V_4 < V_10 ; V_4 ++ ) {
V_5 = F_4 ( F_5 ( V_9 , V_4 ) ) ;
if ( V_5 )
goto V_11;
}
if ( V_3 == 2 )
V_6 = V_8 -> V_12 ;
else
V_6 = 0 ;
F_6 ( V_8 -> V_13 . V_14 , V_8 -> V_15 , V_8 -> V_12 , V_6 ) ;
F_7 ( 1 ) ;
if ( V_3 == 1 )
V_6 = V_8 -> V_16 ;
else
V_6 = 0 ;
F_6 ( V_8 -> V_13 . V_14 , V_8 -> V_17 , V_8 -> V_16 , V_6 ) ;
F_7 ( 1 ) ;
V_11:
for ( V_4 -- ; V_4 >= 0 ; V_4 -- )
F_8 ( F_5 ( V_9 , V_4 ) ) ;
return V_5 ;
}
static T_1 F_9 ( struct V_1 * V_2 )
{
T_2 V_6 ;
struct V_7 * V_8 = F_2 ( V_2 ) ;
F_10 ( V_8 -> V_13 . V_14 , V_8 -> V_15 , & V_6 ) ;
if ( V_6 & V_8 -> V_12 )
return 2 ;
F_10 ( V_8 -> V_13 . V_14 , V_8 -> V_17 , & V_6 ) ;
if ( V_6 & V_8 -> V_16 )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
void T_3 * V_20 ;
struct V_21 * V_22 ;
int V_4 , V_5 ;
struct V_23 * V_24 = & V_19 -> V_24 ;
struct V_9 * V_9 ;
struct V_25 * V_26 ;
struct V_9 * * V_27 ;
struct V_14 * V_14 ;
T_4 V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
V_22 = F_12 ( V_19 , V_33 , 0 ) ;
V_20 = F_13 ( V_24 , V_22 ) ;
if ( F_14 ( V_20 ) )
return F_15 ( V_20 ) ;
V_14 = F_16 ( V_24 , V_20 , & V_34 ) ;
if ( F_14 ( V_14 ) )
return F_15 ( V_14 ) ;
V_28 = F_17 ( V_35 ) ;
V_32 = F_18 ( V_24 , sizeof( * V_32 ) + sizeof( * V_27 ) * V_28 ,
V_36 ) ;
if ( ! V_32 )
return - V_37 ;
V_27 = V_32 -> V_27 ;
V_26 = & V_32 -> V_26 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_38 = V_28 ;
for ( V_4 = 0 ; V_4 < V_28 ; V_4 ++ ) {
if ( ! V_35 [ V_4 ] )
continue;
V_9 = F_19 ( V_24 , V_35 [ V_4 ] ) ;
if ( F_14 ( V_9 ) )
return F_15 ( V_9 ) ;
V_27 [ V_4 ] = V_9 ;
}
V_5 = F_20 ( V_24 -> V_39 , V_40 , V_26 ) ;
if ( V_5 )
return V_5 ;
V_30 = & V_32 -> V_30 ;
V_30 -> V_41 . V_39 = V_24 -> V_39 ;
V_30 -> V_41 . V_42 = & V_43 ,
V_30 -> V_41 . V_44 = V_45 ,
V_30 -> V_41 . V_46 = F_17 ( V_47 ) ,
V_30 -> V_14 = V_14 ;
V_30 -> V_48 = V_47 ,
F_21 ( V_19 , & V_30 -> V_41 ) ;
V_5 = F_22 ( & V_30 -> V_41 ) ;
if ( V_5 )
F_23 ( V_24 -> V_39 ) ;
return V_5 ;
}
static int F_24 ( struct V_18 * V_19 )
{
F_23 ( V_19 -> V_24 . V_39 ) ;
F_25 ( F_26 ( V_19 ) ) ;
return 0 ;
}
