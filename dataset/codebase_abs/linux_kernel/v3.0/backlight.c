int F_1 ( const char * type )
{
struct V_1 * V_2 = F_2 ( NULL , L_1 ) ;
if ( V_2 ) {
const char * V_3 = F_3 ( V_2 ,
L_2 , NULL ) ;
if ( V_3 && strncmp ( V_3 , type , strlen ( type ) ) == 0 ) {
F_4 ( V_2 ) ;
return 1 ;
}
F_4 ( V_2 ) ;
}
return 0 ;
}
int F_5 ( struct V_4 * V_5 , int V_6 )
{
int V_7 = ( V_8 - 1 ) ;
if ( V_5 && V_5 -> V_9 ) {
int V_10 , V_11 = 0 ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ )
V_11 = V_11 ( ( int ) V_5 -> V_12 [ V_10 ] , V_11 ) ;
for ( V_10 = 0 ; V_10 < V_8 ; V_10 ++ ) {
int V_13 = abs ( V_5 -> V_12 [ V_10 ] - V_6 ) ;
if ( V_13 < V_11 ) {
V_11 = V_13 ;
V_7 = V_10 ;
}
}
}
return V_7 ;
}
static void F_6 ( struct V_14 * V_15 )
{
if ( F_7 ( & V_16 ) )
return;
F_8 ( & V_17 ) ;
if ( V_18 ) {
struct V_19 * V_20 ;
int V_21 ;
V_20 = & V_18 -> V_20 ;
V_21 = V_20 -> V_21 +
( ( V_22 ? - 1 : 1 ) *
( V_20 -> V_23 / 15 ) ) ;
if ( V_21 < 0 )
V_21 = 0 ;
else if ( V_21 > V_20 -> V_23 )
V_21 = V_20 -> V_23 ;
V_20 -> V_21 = V_21 ;
F_9 ( V_18 ) ;
}
F_10 ( & V_17 ) ;
}
void F_11 ( int V_24 )
{
if ( F_7 ( & V_16 ) )
return;
V_22 = V_24 ;
F_12 ( & V_25 ) ;
}
static int F_13 ( int V_21 )
{
int error = - V_26 ;
F_8 ( & V_17 ) ;
if ( V_18 ) {
struct V_19 * V_20 ;
V_20 = & V_18 -> V_20 ;
V_20 -> V_21 = V_21 *
( V_20 -> V_23 + 1 ) /
( V_27 + 1 ) ;
if ( V_20 -> V_21 > V_20 -> V_23 )
V_20 -> V_21 = V_20 -> V_23 ;
else if ( V_20 -> V_21 < 0 )
V_20 -> V_21 = 0 ;
F_9 ( V_18 ) ;
error = 0 ;
}
F_10 ( & V_17 ) ;
return error ;
}
static void F_14 ( struct V_14 * V_15 )
{
if ( F_7 ( & V_16 ) )
return;
F_13 ( V_28 ) ;
}
void F_15 ( int V_21 ) {
if ( F_7 ( & V_16 ) )
return;
V_28 = V_21 ;
F_12 ( & V_29 ) ;
}
int F_16 ( int V_21 )
{
return F_13 ( V_21 ) ;
}
int F_17 ()
{
int V_30 = - V_26 ;
F_8 ( & V_17 ) ;
if ( V_18 ) {
struct V_19 * V_20 ;
V_20 = & V_18 -> V_20 ;
V_30 = V_20 -> V_21 *
( V_27 + 1 ) /
( V_20 -> V_23 + 1 ) ;
}
F_10 ( & V_17 ) ;
return V_30 ;
}
void F_18 ()
{
F_19 ( & V_16 ) ;
}
void F_20 ()
{
F_21 ( & V_16 ) ;
}
