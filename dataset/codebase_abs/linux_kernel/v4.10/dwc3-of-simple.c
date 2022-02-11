static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_9 ;
V_2 -> V_10 = V_3 ;
if ( ! V_3 )
return 0 ;
V_2 -> V_11 = F_2 ( V_5 , V_2 -> V_10 ,
sizeof( struct V_12 * ) , V_13 ) ;
if ( ! V_2 -> V_11 )
return - V_14 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 ; V_9 ++ ) {
struct V_12 * V_12 ;
int V_15 ;
V_12 = F_3 ( V_7 , V_9 ) ;
if ( F_4 ( V_12 ) ) {
while ( -- V_9 >= 0 )
F_5 ( V_2 -> V_11 [ V_9 ] ) ;
return F_6 ( V_12 ) ;
}
V_15 = F_7 ( V_12 ) ;
if ( V_15 < 0 ) {
while ( -- V_9 >= 0 ) {
F_8 ( V_2 -> V_11 [ V_9 ] ) ;
F_5 ( V_2 -> V_11 [ V_9 ] ) ;
}
F_5 ( V_12 ) ;
return V_15 ;
}
V_2 -> V_11 [ V_9 ] = V_12 ;
}
return 0 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_4 * V_5 = & V_17 -> V_5 ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_15 ;
int V_9 ;
V_2 = F_10 ( V_5 , sizeof( * V_2 ) , V_13 ) ;
if ( ! V_2 )
return - V_14 ;
F_11 ( V_17 , V_2 ) ;
V_2 -> V_5 = V_5 ;
V_15 = F_1 ( V_2 , F_12 ( V_7 ) ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_7 , NULL , NULL , V_5 ) ;
if ( V_15 ) {
for ( V_9 = 0 ; V_9 < V_2 -> V_10 ; V_9 ++ ) {
F_8 ( V_2 -> V_11 [ V_9 ] ) ;
F_5 ( V_2 -> V_11 [ V_9 ] ) ;
}
return V_15 ;
}
F_14 ( V_5 ) ;
F_15 ( V_5 ) ;
F_16 ( V_5 ) ;
return 0 ;
}
static int F_17 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_18 ( V_17 ) ;
struct V_4 * V_5 = & V_17 -> V_5 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 ; V_9 ++ ) {
F_8 ( V_2 -> V_11 [ V_9 ] ) ;
F_5 ( V_2 -> V_11 [ V_9 ] ) ;
}
F_19 ( V_5 ) ;
F_20 ( V_5 ) ;
F_21 ( V_5 ) ;
return 0 ;
}
static int F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_23 ( V_5 ) ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 ; V_9 ++ )
F_24 ( V_2 -> V_11 [ V_9 ] ) ;
return 0 ;
}
static int F_25 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_23 ( V_5 ) ;
int V_15 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_2 -> V_10 ; V_9 ++ ) {
V_15 = F_26 ( V_2 -> V_11 [ V_9 ] ) ;
if ( V_15 < 0 ) {
while ( -- V_9 >= 0 )
F_24 ( V_2 -> V_11 [ V_9 ] ) ;
return V_15 ;
}
}
return 0 ;
}
