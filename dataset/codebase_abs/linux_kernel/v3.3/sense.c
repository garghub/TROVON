int F_1 ( struct V_1 * V_2 , int V_3 ,
enum V_4 * type )
{
T_1 V_5 ;
int V_6 = 0 ;
V_6 = F_2 ( V_2 , 0 , & V_5 , V_3 , 0 ,
V_7 , V_8 ,
V_9 ) ;
if ( V_6 ) {
F_3 ( V_2 , L_1 , V_3 ) ;
return V_6 ;
}
if ( V_5 > 2 ) {
F_3 ( V_2 , L_2 , V_5 ) ;
return - V_10 ;
}
* type = V_5 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_4 * V_11 ,
enum V_4 * V_12 )
{
struct V_13 * V_14 = & F_5 ( V_2 ) -> V_14 ;
int V_6 ;
int V_15 ;
for ( V_15 = 1 ; V_15 <= V_2 -> V_16 . V_17 ; V_15 ++ ) {
V_11 [ V_15 - 1 ] = 0 ;
if ( V_14 -> V_18 [ V_15 ] && V_14 -> V_19 [ V_15 ] &&
V_2 -> V_16 . V_20 [ V_15 ] == V_21 ) {
V_6 = F_1 ( V_2 , V_15 , & V_11 [ V_15 - 1 ] ) ;
if ( V_6 )
V_11 [ V_15 - 1 ] = V_12 [ V_15 - 1 ] ;
} else
V_11 [ V_15 - 1 ] = V_12 [ V_15 - 1 ] ;
}
if ( V_11 [ 0 ] == V_22 ) {
for ( V_15 = 1 ; V_15 < V_2 -> V_16 . V_17 ; V_15 ++ )
V_11 [ V_15 ] = V_11 [ V_15 ] ? V_11 [ V_15 ] : V_22 ;
}
if ( V_11 [ V_2 -> V_16 . V_17 - 1 ] == V_23 ) {
for ( V_15 = 0 ; V_15 < V_2 -> V_16 . V_17 - 1 ; V_15 ++ )
V_11 [ V_15 ] = V_11 [ V_15 ] ? V_11 [ V_15 ] : V_23 ;
}
for ( V_15 = 0 ; V_15 < V_2 -> V_16 . V_17 ; V_15 ++ )
V_11 [ V_15 ] = V_11 [ V_15 ] ? V_11 [ V_15 ] : V_12 [ V_15 ] ;
}
static void F_6 ( struct V_24 * V_25 )
{
struct V_26 * V_27 = F_7 ( V_25 ) ;
struct V_13 * V_14 = F_8 ( V_27 , struct V_13 ,
V_28 ) ;
struct V_1 * V_2 = V_14 -> V_2 ;
struct F_5 * V_29 = F_5 ( V_2 ) ;
enum V_4 V_11 [ V_30 ] ;
F_9 ( & V_29 -> V_31 ) ;
F_4 ( V_2 , V_11 , & V_2 -> V_16 . V_32 [ 1 ] ) ;
if ( F_10 ( V_2 , V_11 ) )
goto V_33;
if ( F_11 ( V_2 , V_11 ) )
F_3 ( V_2 , L_3 ) ;
V_33:
F_12 ( & V_29 -> V_31 ) ;
F_13 ( V_34 , & V_14 -> V_28 ,
F_14 ( V_35 ) ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct F_5 * V_29 = F_5 ( V_2 ) ;
struct V_13 * V_14 = & V_29 -> V_14 ;
if ( ! ( V_2 -> V_16 . V_36 & V_37 ) )
return;
F_13 ( V_34 , & V_14 -> V_28 ,
F_14 ( V_35 ) ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & F_5 ( V_2 ) -> V_14 . V_28 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct F_5 * V_29 = F_5 ( V_2 ) ;
struct V_13 * V_14 = & V_29 -> V_14 ;
int V_3 ;
V_14 -> V_2 = V_2 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_16 . V_17 ; V_3 ++ )
V_14 -> V_18 [ V_3 ] = 1 ;
F_19 ( & V_14 -> V_28 , F_6 ) ;
}
