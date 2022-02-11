int F_1 ( struct V_1 * V_2 )
{
static char * V_3 [ V_4 ] [ 4 ] = {
[ V_5 ] = {
NULL , L_1 , L_2 , L_3 ,
} ,
[ V_6 ] = {
NULL , L_4 , L_5 , L_6 ,
} ,
[ V_7 ] = {
NULL , L_4 , L_5 , L_6 ,
} ,
[ V_8 ] = {
L_7 , L_8 , L_9 , L_10
} ,
[ V_9 ] = {
L_11 , L_12 , L_9 , L_13
} ,
} ;
int V_10 , V_11 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ ) {
char V_12 [ 32 ] ;
const struct V_13 * V_14 ;
if ( ! V_3 [ V_2 -> type ] [ V_10 ] )
continue;
sprintf ( V_12 , L_14 , V_3 [ V_2 -> type ] [ V_10 ] ) ;
if ( F_2 ( & V_14 , V_12 , V_2 -> V_15 ) ) {
F_3 ( V_16 L_15 , V_12 ) ;
return - V_17 ;
}
V_11 = V_2 -> V_18 -> V_19 ( V_2 , V_10 , V_14 ) ;
if ( V_11 < 0 ) {
F_4 ( V_14 ) ;
return V_11 ;
}
if ( V_10 == 1 )
V_2 -> V_20 |= V_21 ;
#ifdef F_5
V_2 -> V_13 [ V_10 ] = V_14 ;
#else
F_4 ( V_14 ) ;
#endif
}
if ( ( V_11 = F_6 ( V_2 ) ) < 0 )
return V_11 ;
if ( ( V_11 = F_7 ( V_2 ) ) < 0 )
return V_11 ;
if ( V_2 -> V_18 -> V_22 )
if ( ( V_11 = V_2 -> V_18 -> V_22 ( V_2 ) ) < 0 )
return V_11 ;
V_2 -> V_20 |= V_23 ;
V_2 -> V_20 |= V_24 ;
return F_8 ( V_2 -> V_25 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
#ifdef F_5
int V_10 ;
for ( V_10 = 0 ; V_10 < 4 ; V_10 ++ )
F_4 ( V_2 -> V_13 [ V_10 ] ) ;
#endif
}
