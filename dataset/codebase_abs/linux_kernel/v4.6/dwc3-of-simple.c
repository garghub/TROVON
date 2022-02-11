static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
struct V_7 * V_8 = V_6 -> V_9 ;
unsigned int V_10 ;
int V_11 ;
int V_12 ;
V_4 = F_2 ( V_6 , sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_10 = F_3 ( V_8 ) ;
if ( ! V_10 )
return - V_15 ;
V_4 -> V_16 = V_10 ;
V_4 -> V_17 = F_4 ( V_6 , V_4 -> V_16 ,
sizeof( struct V_18 * ) , V_13 ) ;
if ( ! V_4 -> V_17 )
return - V_14 ;
V_4 -> V_6 = V_6 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
struct V_18 * V_18 ;
V_18 = F_5 ( V_8 , V_12 ) ;
if ( F_6 ( V_18 ) ) {
while ( -- V_12 >= 0 )
F_7 ( V_4 -> V_17 [ V_12 ] ) ;
return F_8 ( V_18 ) ;
}
V_11 = F_9 ( V_18 ) ;
if ( V_11 < 0 ) {
while ( -- V_12 >= 0 ) {
F_10 ( V_4 -> V_17 [ V_12 ] ) ;
F_7 ( V_4 -> V_17 [ V_12 ] ) ;
}
F_7 ( V_18 ) ;
return V_11 ;
}
V_4 -> V_17 [ V_12 ] = V_18 ;
}
V_11 = F_11 ( V_8 , NULL , NULL , V_6 ) ;
if ( V_11 ) {
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
F_10 ( V_4 -> V_17 [ V_12 ] ) ;
F_7 ( V_4 -> V_17 [ V_12 ] ) ;
}
return V_11 ;
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
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
F_17 ( V_4 -> V_17 [ V_12 ] ) ;
F_7 ( V_4 -> V_17 [ V_12 ] ) ;
}
F_18 ( V_6 ) ;
F_19 ( V_6 ) ;
F_20 ( V_6 ) ;
return 0 ;
}
static int F_21 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_22 ( V_6 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ )
F_23 ( V_4 -> V_17 [ V_12 ] ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_22 ( V_6 ) ;
int V_11 ;
int V_12 ;
for ( V_12 = 0 ; V_12 < V_4 -> V_16 ; V_12 ++ ) {
V_11 = F_25 ( V_4 -> V_17 [ V_12 ] ) ;
if ( V_11 < 0 ) {
while ( -- V_12 >= 0 )
F_23 ( V_4 -> V_17 [ V_12 ] ) ;
return V_11 ;
}
}
return 0 ;
}
