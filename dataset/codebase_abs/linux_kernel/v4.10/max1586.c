static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
int V_9 ;
T_1 V_10 ;
F_4 ( & V_8 -> V_11 , L_1 ,
F_5 ( V_2 , V_6 ) / 1000 ) ;
V_10 = V_12 | ( T_1 ) V_6 ;
V_9 = F_6 ( V_8 , V_10 ) ;
if ( V_9 )
return V_9 ;
V_4 -> V_5 = V_6 ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_13 ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_14 ;
int V_9 ;
F_4 ( & V_8 -> V_11 , L_2 ,
V_2 -> V_15 -> V_16 [ V_6 ] / 1000 ) ;
V_14 = V_17 | ( T_1 ) V_6 ;
V_9 = F_6 ( V_8 , V_14 ) ;
if ( V_9 )
return V_9 ;
V_4 -> V_13 = V_6 ;
return 0 ;
}
static int F_9 ( struct V_18 * V_11 ,
struct V_19 * V_20 )
{
struct V_21 * V_22 ;
struct V_23 V_24 [ F_10 ( V_25 ) ] = { } ;
struct V_26 * V_27 = V_11 -> V_28 ;
int V_29 , V_30 ;
if ( F_11 ( V_27 , L_3 ,
& V_20 -> V_31 ) < 0 ) {
F_12 ( V_11 , L_4 , V_27 -> V_32 ) ;
return - V_33 ;
}
V_27 = F_13 ( V_27 , L_5 ) ;
if ( ! V_27 ) {
F_12 ( V_11 , L_6 ) ;
return - V_33 ;
}
for ( V_29 = 0 ; V_29 < F_10 ( V_24 ) ; V_29 ++ )
V_24 [ V_29 ] . V_34 = V_25 [ V_29 ] . V_34 ;
V_30 = V_23 ( V_11 , V_27 , V_24 , F_10 ( V_24 ) ) ;
F_14 ( V_27 ) ;
if ( V_30 <= 0 )
return V_30 ;
V_20 -> V_35 = F_15 ( V_11 , sizeof( struct V_21 ) *
V_30 , V_36 ) ;
if ( ! V_20 -> V_35 )
return - V_37 ;
V_20 -> V_38 = V_30 ;
V_22 = V_20 -> V_35 ;
for ( V_29 = 0 ; V_29 < V_30 ; V_29 ++ ) {
V_22 -> V_39 = V_29 ;
V_22 -> V_34 = V_24 [ V_29 ] . V_28 -> V_34 ;
V_22 -> V_40 = V_24 [ V_29 ] . V_41 ;
V_22 ++ ;
}
return 0 ;
}
static int F_16 ( struct V_7 * V_8 ,
const struct V_42 * V_43 )
{
struct V_19 * V_20 , V_44 ;
struct V_45 V_46 = { } ;
struct V_3 * V_4 ;
int V_29 , V_39 , V_9 ;
const struct V_47 * V_48 ;
V_20 = F_17 ( & V_8 -> V_11 ) ;
if ( V_8 -> V_11 . V_28 && ! V_20 ) {
V_48 = F_18 ( F_19 ( V_49 ) ,
& V_8 -> V_11 ) ;
if ( ! V_48 ) {
F_12 ( & V_8 -> V_11 , L_7 ) ;
return - V_50 ;
}
V_9 = F_9 ( & V_8 -> V_11 , & V_44 ) ;
if ( V_9 < 0 )
return V_9 ;
V_20 = & V_44 ;
}
V_4 = F_15 ( & V_8 -> V_11 , sizeof( struct V_3 ) ,
V_36 ) ;
if ( ! V_4 )
return - V_37 ;
V_4 -> V_8 = V_8 ;
if ( ! V_20 -> V_31 )
return - V_33 ;
V_4 -> V_51 = V_52 / 1000 * V_20 -> V_31 / 1000 ;
V_4 -> V_53 = V_54 / 1000 * V_20 -> V_31 / 1000 ;
V_4 -> V_5 = 24 ;
V_4 -> V_13 = 0 ;
for ( V_29 = 0 ; V_29 < V_20 -> V_38 && V_29 <= V_55 ; V_29 ++ ) {
struct V_1 * V_2 ;
V_39 = V_20 -> V_35 [ V_29 ] . V_39 ;
if ( ! V_20 -> V_35 [ V_29 ] . V_40 )
continue;
if ( V_39 < V_56 || V_39 > V_55 ) {
F_12 ( & V_8 -> V_11 , L_8 , V_39 ) ;
return - V_33 ;
}
if ( V_39 == V_56 ) {
V_25 [ V_39 ] . V_51 = V_4 -> V_51 ;
V_25 [ V_39 ] . V_57 =
( V_4 -> V_53 - V_4 -> V_51 ) /
V_58 ;
}
V_46 . V_11 = & V_8 -> V_11 ;
V_46 . V_41 = V_20 -> V_35 [ V_29 ] . V_40 ;
V_46 . V_59 = V_4 ;
V_2 = F_20 ( & V_8 -> V_11 ,
& V_25 [ V_39 ] , & V_46 ) ;
if ( F_21 ( V_2 ) ) {
F_12 ( & V_8 -> V_11 , L_9 ,
V_25 [ V_39 ] . V_34 ) ;
return F_22 ( V_2 ) ;
}
}
F_23 ( V_8 , V_4 ) ;
F_24 ( & V_8 -> V_11 , L_10 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
return F_26 ( & V_60 ) ;
}
static void T_3 F_27 ( void )
{
F_28 ( & V_60 ) ;
}
