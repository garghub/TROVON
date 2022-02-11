static int F_1 ( int V_1 , int V_2 ,
void * V_3 )
{
int V_4 [ V_5 ] ;
unsigned int V_6 ;
struct V_7 * V_8 = V_3 ;
if ( V_1 == V_2 )
return 0 ;
for ( V_6 = 0 ; V_6 < V_8 -> V_9 ; V_6 ++ ) {
V_4 [ V_6 ] = ( V_2 >> V_6 ) & 1 ;
}
F_2 ( V_8 -> V_9 , V_8 -> V_10 , V_4 ) ;
return 0 ;
}
static int F_3 ( struct V_11 * V_12 )
{
struct V_7 * V_8 ;
int V_9 ;
unsigned int V_6 ;
int V_13 ;
if ( ! V_12 -> V_14 . V_15 )
return - V_16 ;
V_9 = F_4 ( V_12 -> V_14 . V_15 ) ;
if ( V_9 <= 0 || V_9 > V_5 )
return - V_16 ;
V_8 = F_5 ( & V_12 -> V_14 , sizeof( * V_8 ) , V_17 ) ;
if ( ! V_8 )
return - V_18 ;
V_8 -> V_9 = V_9 ;
for ( V_6 = 0 ; V_6 < V_9 ; ) {
struct V_19 * V_10 = F_6 ( & V_12 -> V_14 , NULL , V_6 ,
V_20 ) ;
if ( F_7 ( V_10 ) ) {
V_13 = F_8 ( V_10 ) ;
goto V_21;
}
V_8 -> V_10 [ V_6 ] = V_10 ;
V_6 ++ ;
}
V_13 = F_9 ( & V_12 -> V_14 ,
F_1 , & V_8 -> V_22 , V_8 ) ;
if ( V_13 == 0 ) {
V_12 -> V_14 . V_23 = V_8 ;
return 0 ;
}
V_21:
while ( V_6 ) {
V_6 -- ;
F_10 ( V_8 -> V_10 [ V_6 ] ) ;
}
return V_13 ;
}
static int F_11 ( struct V_11 * V_12 )
{
unsigned int V_6 ;
struct V_7 * V_8 = F_12 ( & V_12 -> V_14 ) ;
F_13 ( V_8 -> V_22 ) ;
for ( V_6 = 0 ; V_6 < V_8 -> V_9 ; V_6 ++ )
F_10 ( V_8 -> V_10 [ V_6 ] ) ;
return 0 ;
}
