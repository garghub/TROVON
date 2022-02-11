static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 =
F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( V_5 -> V_6 == 0 ) {
F_3 ( V_5 -> V_7 , 0 ) ;
return;
}
V_3 = 32 - ( V_5 -> V_6 * 32 ) / 255 ;
if ( V_3 == 0 ) {
F_3 ( V_5 -> V_7 , 0 ) ;
F_4 ( 1 ) ;
F_3 ( V_5 -> V_7 , 1 ) ;
return;
}
F_3 ( V_5 -> V_7 , 1 ) ;
while ( V_3 -- ) {
F_3 ( V_5 -> V_7 , 0 ) ;
F_5 ( 1 ) ;
F_3 ( V_5 -> V_7 , 1 ) ;
F_5 ( 1 ) ;
}
}
static void F_6 ( struct V_8 * V_9 ,
enum V_10 V_11 )
{
struct V_4 * V_5 =
F_2 ( V_9 , struct V_4 , V_12 ) ;
V_5 -> V_6 = V_11 ;
F_7 ( & V_5 -> V_2 ) ;
}
static int T_1 F_8 ( const struct V_13 * V_14 ,
struct V_4 * V_5 , struct V_15 * V_16 )
{
int V_17 , V_18 ;
if ( ! F_9 ( V_14 -> V_7 ) ) {
F_10 ( V_19 L_1 ,
V_20 , V_14 -> V_7 , V_14 -> V_21 ) ;
return 0 ;
}
V_17 = F_11 ( V_14 -> V_7 , V_14 -> V_21 ) ;
if ( V_17 < 0 )
return V_17 ;
V_5 -> V_12 . V_21 = V_14 -> V_21 ;
V_5 -> V_12 . V_22 = V_14 -> V_22 ;
V_5 -> V_7 = V_14 -> V_7 ;
V_5 -> V_12 . V_23 = F_6 ;
V_18 = ( V_14 -> V_24 == V_25 ) ;
V_5 -> V_12 . V_26 = V_18 ? V_27 : V_28 ;
if ( ! V_14 -> V_29 )
V_5 -> V_12 . V_30 |= V_31 ;
V_17 = F_12 ( V_5 -> V_7 , V_18 ) ;
if ( V_17 < 0 )
goto V_32;
F_13 ( & V_5 -> V_2 , F_1 ) ;
V_17 = F_14 ( V_16 , & V_5 -> V_12 ) ;
if ( V_17 < 0 )
goto V_32;
F_10 ( V_19 L_2 ,
V_20 , V_14 -> V_21 , V_14 -> V_7 ) ;
return 0 ;
V_32:
F_15 ( V_5 -> V_7 ) ;
return V_17 ;
}
static void F_16 ( struct V_4 * V_33 )
{
if ( ! F_9 ( V_33 -> V_7 ) )
return;
F_17 ( & V_33 -> V_12 ) ;
F_18 ( & V_33 -> V_2 ) ;
F_15 ( V_33 -> V_7 ) ;
}
static int T_1 F_19 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = V_35 -> V_38 . V_39 ;
struct V_4 * V_40 ;
int V_41 , V_17 = 0 ;
if ( ! V_37 )
return - V_42 ;
V_40 = F_20 ( sizeof( struct V_4 ) * V_37 -> V_43 ,
V_44 ) ;
if ( ! V_40 )
return - V_45 ;
for ( V_41 = 0 ; V_41 < V_37 -> V_43 ; V_41 ++ ) {
V_17 = F_8 ( & V_37 -> V_46 [ V_41 ] , & V_40 [ V_41 ] ,
& V_35 -> V_38 ) ;
if ( V_17 < 0 )
goto V_32;
}
F_21 ( V_35 , V_40 ) ;
return 0 ;
V_32:
for ( V_41 = V_41 - 1 ; V_41 >= 0 ; V_41 -- )
F_16 ( & V_40 [ V_41 ] ) ;
F_22 ( V_40 ) ;
return V_17 ;
}
static int T_2 F_23 ( struct V_34 * V_35 )
{
int V_41 ;
struct V_36 * V_37 = V_35 -> V_38 . V_39 ;
struct V_4 * V_40 ;
V_40 = F_24 ( V_35 ) ;
for ( V_41 = 0 ; V_41 < V_37 -> V_43 ; V_41 ++ )
F_16 ( & V_40 [ V_41 ] ) ;
F_22 ( V_40 ) ;
return 0 ;
}
