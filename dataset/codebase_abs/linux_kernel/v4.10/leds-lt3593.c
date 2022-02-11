static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 =
F_2 ( V_2 , struct V_5 , V_7 ) ;
int V_8 ;
if ( V_4 == 0 ) {
F_3 ( V_6 -> V_9 , 0 ) ;
return 0 ;
}
V_8 = 32 - ( V_4 * 32 ) / 255 ;
if ( V_8 == 0 ) {
F_3 ( V_6 -> V_9 , 0 ) ;
F_4 ( 1 ) ;
F_3 ( V_6 -> V_9 , 1 ) ;
return 0 ;
}
F_3 ( V_6 -> V_9 , 1 ) ;
while ( V_8 -- ) {
F_3 ( V_6 -> V_9 , 0 ) ;
F_5 ( 1 ) ;
F_3 ( V_6 -> V_9 , 1 ) ;
F_5 ( 1 ) ;
}
return 0 ;
}
static int F_6 ( const struct V_10 * V_11 ,
struct V_5 * V_6 , struct V_12 * V_13 )
{
int V_14 , V_15 ;
if ( ! F_7 ( V_11 -> V_9 ) ) {
F_8 ( V_13 , L_1 ,
V_16 , V_11 -> V_9 , V_11 -> V_17 ) ;
return 0 ;
}
V_6 -> V_7 . V_17 = V_11 -> V_17 ;
V_6 -> V_7 . V_18 = V_11 -> V_18 ;
V_6 -> V_9 = V_11 -> V_9 ;
V_6 -> V_7 . V_19 = F_1 ;
V_15 = ( V_11 -> V_20 == V_21 ) ;
V_6 -> V_7 . V_22 = V_15 ? V_23 : V_24 ;
if ( ! V_11 -> V_25 )
V_6 -> V_7 . V_26 |= V_27 ;
V_14 = F_9 ( V_13 , V_11 -> V_9 , V_15 ?
V_28 : V_29 ,
V_11 -> V_17 ) ;
if ( V_14 < 0 )
return V_14 ;
V_14 = F_10 ( V_13 , & V_6 -> V_7 ) ;
if ( V_14 < 0 )
return V_14 ;
F_8 ( V_13 , L_2 ,
V_16 , V_11 -> V_17 , V_11 -> V_9 ) ;
return 0 ;
}
static void F_11 ( struct V_5 * V_30 )
{
if ( ! F_7 ( V_30 -> V_9 ) )
return;
F_12 ( & V_30 -> V_7 ) ;
}
static int F_13 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_14 ( & V_32 -> V_35 ) ;
struct V_5 * V_36 ;
int V_37 , V_14 = 0 ;
if ( ! V_34 )
return - V_38 ;
V_36 = F_15 ( & V_32 -> V_35 ,
sizeof( struct V_5 ) * V_34 -> V_39 ,
V_40 ) ;
if ( ! V_36 )
return - V_41 ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ ) {
V_14 = F_6 ( & V_34 -> V_42 [ V_37 ] , & V_36 [ V_37 ] ,
& V_32 -> V_35 ) ;
if ( V_14 < 0 )
goto V_43;
}
F_16 ( V_32 , V_36 ) ;
return 0 ;
V_43:
for ( V_37 = V_37 - 1 ; V_37 >= 0 ; V_37 -- )
F_11 ( & V_36 [ V_37 ] ) ;
return V_14 ;
}
static int F_17 ( struct V_31 * V_32 )
{
int V_37 ;
struct V_33 * V_34 = F_14 ( & V_32 -> V_35 ) ;
struct V_5 * V_36 ;
V_36 = F_18 ( V_32 ) ;
for ( V_37 = 0 ; V_37 < V_34 -> V_39 ; V_37 ++ )
F_11 ( & V_36 [ V_37 ] ) ;
return 0 ;
}
