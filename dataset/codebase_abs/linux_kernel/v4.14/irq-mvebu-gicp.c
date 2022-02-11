static int F_1 ( struct V_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
struct V_6 * V_7 = & V_2 -> V_8 [ V_4 ] ;
if ( V_3 < V_7 -> V_9 )
return V_7 -> V_10 + V_3 ;
V_3 -= V_7 -> V_9 ;
}
return - V_11 ;
}
int F_2 ( struct V_12 * V_13 , T_1 * V_14 ,
T_1 * V_15 )
{
struct V_16 * V_17 ;
struct V_1 * V_2 ;
V_17 = F_3 ( V_13 ) ;
if ( ! V_17 )
return - V_18 ;
V_2 = F_4 ( V_17 ) ;
if ( ! V_2 )
return - V_18 ;
* V_14 = V_2 -> V_19 -> V_10 + V_20 ;
* V_15 = V_2 -> V_19 -> V_10 + V_21 ;
return 0 ;
}
static void F_5 ( struct V_22 * V_23 , struct V_24 * V_25 )
{
struct V_1 * V_2 = V_23 -> V_26 ;
T_1 V_14 = V_2 -> V_19 -> V_10 + V_20 ;
V_25 -> V_23 = V_23 -> V_27 ;
V_25 -> V_28 = F_6 ( V_14 ) ;
V_25 -> V_29 = F_7 ( V_14 ) ;
}
static int F_8 ( struct V_30 * V_31 , unsigned int V_32 ,
unsigned int V_33 , void * args )
{
struct V_1 * V_2 = V_31 -> V_34 ;
struct V_35 V_36 ;
unsigned int V_27 ;
int V_37 ;
F_9 ( & V_2 -> V_38 ) ;
V_27 = F_10 ( V_2 -> V_39 , V_2 -> V_40 ) ;
if ( V_27 == V_2 -> V_40 ) {
F_11 ( & V_2 -> V_38 ) ;
return - V_41 ;
}
F_12 ( V_27 , V_2 -> V_39 ) ;
F_11 ( & V_2 -> V_38 ) ;
V_36 . V_42 = V_31 -> V_43 -> V_42 ;
V_36 . V_44 = 3 ;
V_36 . V_45 [ 0 ] = V_46 ;
V_36 . V_45 [ 1 ] = F_1 ( V_2 , V_27 ) - 32 ;
V_36 . V_45 [ 2 ] = V_47 ;
V_37 = F_13 ( V_31 , V_32 , 1 , & V_36 ) ;
if ( V_37 ) {
F_14 ( V_2 -> V_48 , L_1 ) ;
goto V_49;
}
V_37 = F_15 ( V_31 , V_32 , V_27 ,
& V_50 , V_2 ) ;
if ( V_37 )
goto V_51;
return 0 ;
V_51:
F_16 ( V_31 , V_32 , V_33 ) ;
V_49:
F_9 ( & V_2 -> V_38 ) ;
F_17 ( V_27 , V_2 -> V_39 ) ;
F_11 ( & V_2 -> V_38 ) ;
return V_37 ;
}
static void F_18 ( struct V_30 * V_31 ,
unsigned int V_32 , unsigned int V_33 )
{
struct V_1 * V_2 = V_31 -> V_34 ;
struct V_22 * V_52 = F_19 ( V_31 , V_32 ) ;
if ( V_52 -> V_27 >= V_2 -> V_40 ) {
F_14 ( V_2 -> V_48 , L_2 , V_52 -> V_27 ) ;
return;
}
F_16 ( V_31 , V_32 , V_33 ) ;
F_9 ( & V_2 -> V_38 ) ;
F_17 ( V_52 -> V_27 , V_2 -> V_39 ) ;
F_11 ( & V_2 -> V_38 ) ;
}
static int F_20 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_30 * V_53 , * V_54 , * V_55 ;
struct V_12 * V_56 = V_17 -> V_48 . V_57 ;
struct V_12 * V_58 ;
int V_37 , V_4 ;
V_2 = F_21 ( & V_17 -> V_48 , sizeof( * V_2 ) , V_59 ) ;
if ( ! V_2 )
return - V_60 ;
V_2 -> V_48 = & V_17 -> V_48 ;
F_22 ( & V_2 -> V_38 ) ;
V_2 -> V_19 = F_23 ( V_17 , V_61 , 0 ) ;
if ( ! V_2 -> V_19 )
return - V_18 ;
V_37 = F_24 ( V_56 , L_3 ) ;
if ( V_37 < 0 )
return V_37 ;
V_2 -> V_5 = V_37 / 2 ;
V_2 -> V_8 =
F_21 ( & V_17 -> V_48 ,
V_2 -> V_5 *
sizeof( struct V_6 ) ,
V_59 ) ;
if ( ! V_2 -> V_8 )
return - V_60 ;
for ( V_4 = 0 ; V_4 < V_2 -> V_5 ; V_4 ++ ) {
F_25 ( V_56 , L_3 ,
V_4 * 2 ,
& V_2 -> V_8 [ V_4 ] . V_10 ) ;
F_25 ( V_56 , L_3 ,
V_4 * 2 + 1 ,
& V_2 -> V_8 [ V_4 ] . V_9 ) ;
V_2 -> V_40 += V_2 -> V_8 [ V_4 ] . V_9 ;
}
V_2 -> V_39 = F_21 ( & V_17 -> V_48 ,
F_26 ( V_2 -> V_40 ) * sizeof( long ) ,
V_59 ) ;
if ( ! V_2 -> V_39 )
return - V_60 ;
V_58 = F_27 ( V_56 ) ;
if ( ! V_58 ) {
F_14 ( & V_17 -> V_48 , L_4 ) ;
return - V_18 ;
}
V_55 = F_28 ( V_58 ) ;
if ( ! V_55 ) {
F_14 ( & V_17 -> V_48 , L_5 ) ;
return - V_18 ;
}
V_53 = F_29 ( V_55 , 0 ,
V_2 -> V_40 ,
F_30 ( V_56 ) ,
& V_62 , V_2 ) ;
if ( ! V_53 )
return - V_60 ;
V_54 = F_31 ( F_30 ( V_56 ) ,
& V_63 ,
V_53 ) ;
if ( ! V_54 ) {
F_32 ( V_53 ) ;
return - V_60 ;
}
F_33 ( V_17 , V_2 ) ;
return 0 ;
}
