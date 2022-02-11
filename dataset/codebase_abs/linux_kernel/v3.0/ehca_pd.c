struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_2 ( V_11 , V_12 ) ;
if ( ! V_9 ) {
F_3 ( V_3 , L_1 ,
V_3 , V_5 ) ;
return F_4 ( - V_13 ) ;
}
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_5 ( & V_9 -> free [ V_10 ] ) ;
F_5 ( & V_9 -> V_14 [ V_10 ] ) ;
}
F_6 ( & V_9 -> V_15 ) ;
if ( ! V_5 ) {
struct V_16 * V_17 = F_7 ( V_3 , struct V_16 ,
V_2 ) ;
V_9 -> V_18 . V_19 = V_17 -> V_9 -> V_18 . V_19 ;
} else
V_9 -> V_18 . V_19 = ( V_20 ) V_9 ;
return & V_9 -> V_1 ;
}
int F_8 ( struct V_1 * V_9 )
{
struct V_8 * V_21 = F_7 ( V_9 , struct V_8 , V_1 ) ;
int V_10 , V_22 = 0 ;
struct V_23 * V_24 , * V_25 ;
for ( V_10 = 0 ; V_10 < 2 ; V_10 ++ ) {
F_9 ( & V_21 -> V_14 [ V_10 ] , & V_21 -> free [ V_10 ] ) ;
F_10 (page, tmp, &my_pd->free[i], list) {
V_22 = 1 ;
F_11 ( V_24 -> V_24 ) ;
F_12 ( V_26 , V_24 ) ;
}
}
if ( V_22 )
F_13 ( V_9 -> V_3 ,
L_2 ) ;
F_12 ( V_11 , V_21 ) ;
return 0 ;
}
int F_14 ( void )
{
V_11 = F_15 ( L_3 ,
sizeof( struct V_8 ) , 0 ,
V_27 ,
NULL ) ;
if ( ! V_11 )
return - V_13 ;
return 0 ;
}
void F_16 ( void )
{
if ( V_11 )
F_17 ( V_11 ) ;
}
