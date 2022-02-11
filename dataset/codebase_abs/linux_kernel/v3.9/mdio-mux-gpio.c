static int F_1 ( int V_1 , int V_2 ,
void * V_3 )
{
int V_4 ;
unsigned int V_5 ;
struct V_6 * V_7 = V_3 ;
if ( V_1 == V_2 )
return 0 ;
V_4 = V_1 == - 1 ? - 1 : V_1 ^ V_2 ;
for ( V_5 = 0 ; V_5 < V_7 -> V_8 ; V_5 ++ ) {
if ( V_4 & 1 )
F_2 ( V_7 -> V_9 [ V_5 ] ,
( V_2 & 1 ) != 0 ) ;
V_4 >>= 1 ;
V_2 >>= 1 ;
}
return 0 ;
}
static int F_3 ( struct V_10 * V_11 )
{
enum V_12 V_13 ;
struct V_6 * V_7 ;
int V_8 ;
unsigned int V_5 ;
int V_14 ;
if ( ! V_11 -> V_15 . V_16 )
return - V_17 ;
V_8 = F_4 ( V_11 -> V_15 . V_16 ) ;
if ( V_8 <= 0 || V_8 > V_18 )
return - V_17 ;
V_7 = F_5 ( & V_11 -> V_15 , sizeof( * V_7 ) , V_19 ) ;
if ( ! V_7 )
return - V_20 ;
V_7 -> V_8 = V_8 ;
for ( V_5 = 0 ; V_5 < V_8 ; ) {
int V_9 = F_6 ( V_11 -> V_15 . V_16 , V_5 , & V_13 ) ;
if ( V_9 < 0 ) {
V_14 = ( V_9 == - V_17 ) ? - V_21 : V_9 ;
goto V_22;
}
V_7 -> V_9 [ V_5 ] = V_9 ;
V_5 ++ ;
V_14 = F_7 ( V_9 , L_1 ) ;
if ( V_14 )
goto V_22;
V_14 = F_8 ( V_9 , 0 ) ;
if ( V_14 )
goto V_22;
}
V_14 = F_9 ( & V_11 -> V_15 ,
F_1 , & V_7 -> V_23 , V_7 ) ;
if ( V_14 == 0 ) {
V_11 -> V_15 . V_24 = V_7 ;
return 0 ;
}
V_22:
while ( V_5 ) {
V_5 -- ;
F_10 ( V_7 -> V_9 [ V_5 ] ) ;
}
return V_14 ;
}
static int F_11 ( struct V_10 * V_11 )
{
struct V_6 * V_7 = V_11 -> V_15 . V_24 ;
F_12 ( V_7 -> V_23 ) ;
return 0 ;
}
