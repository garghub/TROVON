static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
int V_5 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_6 ) ;
if ( ! V_4 )
return NULL ;
V_5 = F_3 ( V_3 ) ;
V_4 -> V_7 = F_4 ( V_5 * sizeof( V_4 -> V_7 [ 0 ] ) ) ;
if ( ! V_4 -> V_7 ) {
F_5 ( V_4 ) ;
return NULL ;
}
V_4 -> V_8 = V_5 ;
return V_4 ;
}
void F_6 ( struct V_1 * V_4 )
{
F_7 ( V_4 -> V_7 ) ;
F_5 ( V_4 ) ;
}
struct V_1 *
F_8 ( struct V_2 * V_3 , struct V_9 * V_10 )
{
struct V_1 * V_4 ;
int V_11 , V_12 , V_13 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 )
return NULL ;
V_4 -> V_14 = ( char * ) F_9 ( V_6 ) ;
if ( ! V_4 -> V_14 ) {
F_6 ( V_4 ) ;
return NULL ;
}
V_4 -> V_14 [ 0 ] = '\0' ;
V_4 -> V_10 = V_10 ;
F_10 ( V_3 , 0 , V_4 -> V_15 ) ;
snprintf ( V_4 -> V_14 , V_16 , L_1 , V_4 -> V_15 ) ;
if ( isdigit ( V_4 -> V_15 [ strlen ( V_4 -> V_15 ) - 1 ] ) )
sprintf ( V_4 -> V_15 , L_2 ) ;
V_11 = V_12 = V_13 = 0 ;
while ( ! V_12 && V_17 [ V_11 ] ) {
memset ( V_4 -> V_7 , 0 , V_4 -> V_8 * sizeof( V_4 -> V_7 [ 0 ] ) ) ;
V_12 = V_17 [ V_11 ++ ] ( V_4 ) ;
if ( V_12 < 0 ) {
V_13 = V_12 ;
V_12 = 0 ;
}
}
if ( V_12 > 0 ) {
F_11 ( V_18 L_3 , V_4 -> V_14 ) ;
F_12 ( ( unsigned long ) V_4 -> V_14 ) ;
return V_4 ;
}
if ( V_4 -> V_19 )
V_13 = - V_20 ;
if ( V_13 )
V_12 = V_13 ;
if ( ! V_12 )
F_13 ( V_4 -> V_14 , L_4 , V_16 ) ;
else if ( V_21 )
F_13 ( V_4 -> V_14 , L_5 , V_16 ) ;
F_11 ( V_18 L_3 , V_4 -> V_14 ) ;
F_12 ( ( unsigned long ) V_4 -> V_14 ) ;
F_6 ( V_4 ) ;
return F_14 ( V_12 ) ;
}
