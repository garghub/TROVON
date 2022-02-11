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
static int F_8 ( const struct V_13 * V_14 ,
struct V_4 * V_5 , struct V_15 * V_16 )
{
int V_17 , V_18 ;
if ( ! F_9 ( V_14 -> V_7 ) ) {
F_10 ( V_16 , L_1 ,
V_19 , V_14 -> V_7 , V_14 -> V_20 ) ;
return 0 ;
}
V_5 -> V_12 . V_20 = V_14 -> V_20 ;
V_5 -> V_12 . V_21 = V_14 -> V_21 ;
V_5 -> V_7 = V_14 -> V_7 ;
V_5 -> V_12 . V_22 = F_6 ;
V_18 = ( V_14 -> V_23 == V_24 ) ;
V_5 -> V_12 . V_25 = V_18 ? V_26 : V_27 ;
if ( ! V_14 -> V_28 )
V_5 -> V_12 . V_29 |= V_30 ;
V_17 = F_11 ( V_16 , V_14 -> V_7 , V_18 ?
V_31 : V_32 ,
V_14 -> V_20 ) ;
if ( V_17 < 0 )
return V_17 ;
F_12 ( & V_5 -> V_2 , F_1 ) ;
V_17 = F_13 ( V_16 , & V_5 -> V_12 ) ;
if ( V_17 < 0 )
return V_17 ;
F_10 ( V_16 , L_2 ,
V_19 , V_14 -> V_20 , V_14 -> V_7 ) ;
return 0 ;
}
static void F_14 ( struct V_4 * V_33 )
{
if ( ! F_9 ( V_33 -> V_7 ) )
return;
F_15 ( & V_33 -> V_12 ) ;
F_16 ( & V_33 -> V_2 ) ;
}
static int F_17 ( struct V_34 * V_35 )
{
struct V_36 * V_37 = F_18 ( & V_35 -> V_38 ) ;
struct V_4 * V_39 ;
int V_40 , V_17 = 0 ;
if ( ! V_37 )
return - V_41 ;
V_39 = F_19 ( & V_35 -> V_38 ,
sizeof( struct V_4 ) * V_37 -> V_42 ,
V_43 ) ;
if ( ! V_39 )
return - V_44 ;
for ( V_40 = 0 ; V_40 < V_37 -> V_42 ; V_40 ++ ) {
V_17 = F_8 ( & V_37 -> V_45 [ V_40 ] , & V_39 [ V_40 ] ,
& V_35 -> V_38 ) ;
if ( V_17 < 0 )
goto V_46;
}
F_20 ( V_35 , V_39 ) ;
return 0 ;
V_46:
for ( V_40 = V_40 - 1 ; V_40 >= 0 ; V_40 -- )
F_14 ( & V_39 [ V_40 ] ) ;
return V_17 ;
}
static int F_21 ( struct V_34 * V_35 )
{
int V_40 ;
struct V_36 * V_37 = F_18 ( & V_35 -> V_38 ) ;
struct V_4 * V_39 ;
V_39 = F_22 ( V_35 ) ;
for ( V_40 = 0 ; V_40 < V_37 -> V_42 ; V_40 ++ )
F_14 ( & V_39 [ V_40 ] ) ;
return 0 ;
}
