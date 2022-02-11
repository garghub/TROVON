struct V_1 *
F_1 ( struct V_2 * V_3 , struct V_4 * V_5 )
{
struct V_1 * V_6 ;
int V_7 , V_8 , V_9 ;
V_6 = F_2 ( sizeof( struct V_1 ) , V_10 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> V_11 = ( char * ) F_3 ( V_10 ) ;
if ( ! V_6 -> V_11 ) {
F_4 ( V_6 ) ;
return NULL ;
}
V_6 -> V_11 [ 0 ] = '\0' ;
V_6 -> V_5 = V_5 ;
F_5 ( V_3 , 0 , V_6 -> V_12 ) ;
snprintf ( V_6 -> V_11 , V_13 , L_1 , V_6 -> V_12 ) ;
if ( isdigit ( V_6 -> V_12 [ strlen ( V_6 -> V_12 ) - 1 ] ) )
sprintf ( V_6 -> V_12 , L_2 ) ;
V_6 -> V_14 = F_6 ( V_3 ) ;
V_7 = V_8 = V_9 = 0 ;
while ( ! V_8 && V_15 [ V_7 ] ) {
memset ( & V_6 -> V_16 , 0 , sizeof( V_6 -> V_16 ) ) ;
V_8 = V_15 [ V_7 ++ ] ( V_6 ) ;
if ( V_8 < 0 ) {
V_9 = V_8 ;
V_8 = 0 ;
}
}
if ( V_8 > 0 ) {
F_7 ( V_17 L_3 , V_6 -> V_11 ) ;
F_8 ( ( unsigned long ) V_6 -> V_11 ) ;
return V_6 ;
}
if ( V_6 -> V_18 )
V_9 = - V_19 ;
if ( V_9 )
V_8 = V_9 ;
if ( ! V_8 )
F_9 ( V_6 -> V_11 , L_4 , V_13 ) ;
else if ( V_20 )
F_9 ( V_6 -> V_11 , L_5 , V_13 ) ;
F_7 ( V_17 L_3 , V_6 -> V_11 ) ;
F_8 ( ( unsigned long ) V_6 -> V_11 ) ;
F_4 ( V_6 ) ;
return F_10 ( V_8 ) ;
}
