int F_1 ( struct V_1 * V_2 , int V_3 ,
enum V_4 * type )
{
T_1 V_5 ;
int V_6 = 0 ;
V_6 = F_2 ( V_2 , 0 , & V_5 , V_3 , 0 ,
V_7 , V_8 ) ;
if ( V_6 ) {
F_3 ( V_2 , L_1 , V_3 ) ;
return V_6 ;
}
if ( V_5 > 2 ) {
F_3 ( V_2 , L_2 , V_5 ) ;
return - V_9 ;
}
* type = V_5 ;
return 0 ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_4 * V_10 ,
enum V_4 * V_11 )
{
struct V_12 * V_13 = & F_5 ( V_2 ) -> V_13 ;
int V_6 ;
int V_14 ;
for ( V_14 = 1 ; V_14 <= V_2 -> V_15 . V_16 ; V_14 ++ ) {
V_10 [ V_14 - 1 ] = 0 ;
if ( V_13 -> V_17 [ V_14 ] && V_13 -> V_18 [ V_14 ] &&
V_2 -> V_15 . V_19 [ V_14 ] == V_20 ) {
V_6 = F_1 ( V_2 , V_14 , & V_10 [ V_14 - 1 ] ) ;
if ( V_6 )
V_10 [ V_14 - 1 ] = V_11 [ V_14 - 1 ] ;
} else
V_10 [ V_14 - 1 ] = V_11 [ V_14 - 1 ] ;
}
if ( V_10 [ 0 ] == V_21 ) {
for ( V_14 = 1 ; V_14 < V_2 -> V_15 . V_16 ; V_14 ++ )
V_10 [ V_14 ] = V_10 [ V_14 ] ? V_10 [ V_14 ] : V_21 ;
}
if ( V_10 [ V_2 -> V_15 . V_16 - 1 ] == V_22 ) {
for ( V_14 = 0 ; V_14 < V_2 -> V_15 . V_16 - 1 ; V_14 ++ )
V_10 [ V_14 ] = V_10 [ V_14 ] ? V_10 [ V_14 ] : V_22 ;
}
for ( V_14 = 0 ; V_14 < V_2 -> V_15 . V_16 ; V_14 ++ )
V_10 [ V_14 ] = V_10 [ V_14 ] ? V_10 [ V_14 ] : V_11 [ V_14 ] ;
}
static void F_6 ( struct V_23 * V_24 )
{
struct V_25 * V_26 = F_7 ( V_24 ) ;
struct V_12 * V_13 = F_8 ( V_26 , struct V_12 ,
V_27 ) ;
struct V_1 * V_2 = V_13 -> V_2 ;
struct F_5 * V_28 = F_5 ( V_2 ) ;
enum V_4 V_10 [ V_29 ] ;
F_9 ( & V_28 -> V_30 ) ;
F_4 ( V_2 , V_10 , & V_2 -> V_15 . V_31 [ 1 ] ) ;
if ( F_10 ( V_2 , V_10 ) )
goto V_32;
if ( F_11 ( V_2 , V_10 ) )
F_3 ( V_2 , L_3 ) ;
V_32:
F_12 ( & V_28 -> V_30 ) ;
F_13 ( V_33 , & V_13 -> V_27 ,
F_14 ( V_34 ) ) ;
}
void F_15 ( struct V_1 * V_2 )
{
struct F_5 * V_28 = F_5 ( V_2 ) ;
struct V_12 * V_13 = & V_28 -> V_13 ;
if ( ! ( V_2 -> V_15 . V_35 & V_36 ) )
return;
F_13 ( V_33 , & V_13 -> V_27 ,
F_14 ( V_34 ) ) ;
}
void F_16 ( struct V_1 * V_2 )
{
F_17 ( & F_5 ( V_2 ) -> V_13 . V_27 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct F_5 * V_28 = F_5 ( V_2 ) ;
struct V_12 * V_13 = & V_28 -> V_13 ;
int V_3 ;
V_13 -> V_2 = V_2 ;
for ( V_3 = 1 ; V_3 <= V_2 -> V_15 . V_16 ; V_3 ++ )
V_13 -> V_17 [ V_3 ] = 1 ;
F_19 ( & V_13 -> V_27 , F_6 ) ;
}
