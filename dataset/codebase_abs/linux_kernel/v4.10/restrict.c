static int T_1 F_1 ( char * V_1 )
{
if ( ! V_1 )
return 1 ;
if ( strncmp ( V_1 , L_1 , 3 ) == 0 ) {
struct V_2 * V_3 = & V_4 . V_5 ;
T_2 V_6 = ( strlen ( V_1 ) - 3 ) / 2 ;
int V_7 ;
if ( V_6 == 0 || V_6 > sizeof( V_4 . V_8 ) ) {
F_2 ( L_2 ) ;
return 1 ;
}
V_7 = F_3 ( V_1 + 3 , V_3 , V_6 ) ;
if ( V_7 < 0 )
F_2 ( L_3 ) ;
else
V_9 = V_3 ;
} else if ( strcmp ( V_1 , L_4 ) == 0 ) {
V_10 = true ;
}
return 1 ;
}
int F_4 ( struct V_11 * V_12 ,
const struct V_13 * type ,
const union V_14 * V_15 )
{
const struct V_16 * V_17 ;
struct V_11 * V_11 ;
int V_7 ;
F_5 ( L_5 , V_18 ) ;
if ( ! V_12 )
return - V_19 ;
if ( type != & V_20 )
return - V_21 ;
V_17 = V_15 -> V_8 [ V_22 ] ;
if ( ! V_17 -> V_23 [ 0 ] && ! V_17 -> V_23 [ 1 ] )
return - V_19 ;
if ( V_9 && ! F_6 ( V_17 -> V_23 [ 1 ] , V_9 ) )
return - V_24 ;
V_11 = F_7 ( V_12 ,
V_17 -> V_23 [ 0 ] , V_17 -> V_23 [ 1 ] ,
false ) ;
if ( F_8 ( V_11 ) )
return - V_19 ;
if ( V_10 && ! F_9 ( V_25 , & V_11 -> V_26 ) )
V_7 = - V_19 ;
else
V_7 = F_10 ( V_11 , V_17 ) ;
F_11 ( V_11 ) ;
return V_7 ;
}
