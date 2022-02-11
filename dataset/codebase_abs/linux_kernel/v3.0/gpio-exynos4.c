int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
if ( V_4 == V_5 )
V_4 = 3 ;
return F_2 ( V_2 , V_3 , V_4 ) ;
}
T_1 F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 ;
V_4 = F_4 ( V_2 , V_3 ) ;
if ( V_4 == 3 )
V_4 = V_5 ;
return V_4 ;
}
static T_2 int F_5 ( void )
{
struct V_1 * V_2 ;
int V_6 ;
int V_7 = 0 ;
int V_8 ;
V_2 = V_9 ;
V_8 = F_6 ( V_9 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ , V_2 ++ ) {
if ( V_2 -> V_10 == NULL ) {
V_2 -> V_10 = & V_11 ;
V_2 -> V_7 = V_7 ++ ;
}
if ( V_2 -> V_12 == NULL )
V_2 -> V_12 = V_13 + ( V_6 ) * 0x20 ;
}
F_7 ( V_9 , V_8 ) ;
V_2 = V_14 ;
V_8 = F_6 ( V_14 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ , V_2 ++ ) {
if ( V_2 -> V_10 == NULL ) {
V_2 -> V_10 = & V_11 ;
V_2 -> V_7 = V_7 ++ ;
}
if ( V_2 -> V_12 == NULL )
V_2 -> V_12 = V_15 + ( V_6 ) * 0x20 ;
}
F_7 ( V_14 , V_8 ) ;
V_2 = V_16 ;
V_8 = F_6 ( V_16 ) ;
for ( V_6 = 0 ; V_6 < V_8 ; V_6 ++ , V_2 ++ ) {
if ( V_2 -> V_10 == NULL ) {
V_2 -> V_10 = & V_11 ;
V_2 -> V_7 = V_7 ++ ;
}
if ( V_2 -> V_12 == NULL )
V_2 -> V_12 = V_17 + ( V_6 ) * 0x20 ;
}
F_7 ( V_16 , V_8 ) ;
F_8 ( V_18 , 0 , V_19 ) ;
F_8 ( V_20 , V_19 , V_21 ) ;
return 0 ;
}
