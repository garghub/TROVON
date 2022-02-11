static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_10 ;
int V_11 ;
V_4 = F_2 ( V_6 , sizeof( * V_4 ) , V_12 ) ;
if ( ! V_4 )
return - V_13 ;
V_10 = F_3 ( V_8 ) ;
if ( V_10 < 0 )
return V_10 ;
V_4 -> V_14 = V_10 ;
V_4 -> V_15 = F_4 ( V_6 , V_4 -> V_14 ,
sizeof( struct V_16 * ) , V_12 ) ;
if ( ! V_4 -> V_15 )
return - V_13 ;
V_4 -> V_6 = V_6 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_14 ; V_11 ++ ) {
struct V_16 * V_16 ;
V_16 = F_5 ( V_8 , V_11 ) ;
if ( F_6 ( V_16 ) ) {
while ( -- V_11 >= 0 )
F_7 ( V_4 -> V_15 [ V_11 ] ) ;
return F_8 ( V_16 ) ;
}
V_10 = F_9 ( V_16 ) ;
if ( V_10 < 0 ) {
while ( -- V_11 >= 0 ) {
F_10 ( V_4 -> V_15 [ V_11 ] ) ;
F_7 ( V_4 -> V_15 [ V_11 ] ) ;
}
F_7 ( V_16 ) ;
return V_10 ;
}
V_4 -> V_15 [ V_11 ] = V_16 ;
}
V_10 = F_11 ( V_8 , NULL , NULL , V_6 ) ;
if ( V_10 ) {
for ( V_11 = 0 ; V_11 < V_4 -> V_14 ; V_11 ++ ) {
F_10 ( V_4 -> V_15 [ V_11 ] ) ;
F_7 ( V_4 -> V_15 [ V_11 ] ) ;
}
return V_10 ;
}
F_12 ( V_6 ) ;
F_13 ( V_6 ) ;
F_14 ( V_6 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_16 ( V_2 ) ;
struct V_5 * V_6 = & V_2 -> V_6 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_14 ; V_11 ++ ) {
F_17 ( V_4 -> V_15 [ V_11 ] ) ;
F_7 ( V_4 -> V_15 [ V_11 ] ) ;
}
F_18 ( V_6 ) ;
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_22 ( V_6 ) ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_14 ; V_11 ++ )
F_23 ( V_4 -> V_15 [ V_11 ] ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_22 ( V_6 ) ;
int V_10 ;
int V_11 ;
for ( V_11 = 0 ; V_11 < V_4 -> V_14 ; V_11 ++ ) {
V_10 = F_25 ( V_4 -> V_15 [ V_11 ] ) ;
if ( V_10 < 0 ) {
while ( -- V_11 >= 0 )
F_23 ( V_4 -> V_15 [ V_11 ] ) ;
return V_10 ;
}
}
return 0 ;
}
