int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 ;
int V_6 , V_7 = V_8 ;
struct V_9 * V_10 ;
F_2 ( & V_4 -> V_11 ,
( void (*) ( unsigned long ) ) V_12 ,
( unsigned long ) V_2 ) ;
F_3 ( & V_4 -> V_13 ) ;
V_4 -> V_14 = F_4 ( V_15 * sizeof( struct V_9 ) + 4 , V_16 ) ;
if ( V_4 -> V_14 == NULL ) {
V_7 = V_17 ;
F_5 ( V_18 , V_19 , ( L_1 ) ) ;
goto exit;
}
memset ( V_4 -> V_14 , 0 , V_15 * sizeof( struct V_9 ) + 4 ) ;
V_4 -> V_20 = ( V_21 * ) F_6 ( ( V_22 ) ( V_4 -> V_14 ) , 4 ) ;
V_10 = (struct V_9 * ) V_4 -> V_20 ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
V_7 = F_7 ( V_2 , V_10 ) ;
if ( V_7 == V_17 )
break;
V_10 -> V_1 = V_2 ;
V_10 ++ ;
}
V_4 -> V_23 = V_15 ;
F_8 ( & V_4 -> V_24 ) ;
{
int V_6 ;
V_22 V_25 = 0 ;
V_22 V_26 = 0 ;
struct V_27 * V_28 = NULL ;
F_8 ( & V_4 -> V_29 ) ;
for ( V_6 = 0 ; V_6 < V_30 ; V_6 ++ ) {
V_28 = F_9 ( V_2 -> V_31 , V_32 + V_33 , V_16 ) ;
if ( V_28 ) {
V_28 -> V_34 = V_2 -> V_31 ;
V_25 = ( V_22 ) V_28 -> V_35 ;
V_26 = V_25 & ( V_33 - 1 ) ;
F_10 ( V_28 , ( V_33 - V_26 ) ) ;
F_11 ( & V_4 -> V_29 , V_28 ) ;
}
V_28 = NULL ;
}
}
exit:
return V_7 ;
}
void F_12 ( struct V_1 * V_2 )
{
int V_6 ;
struct V_9 * V_10 ;
struct V_3 * V_4 = & V_2 -> V_5 ;
V_10 = (struct V_9 * ) V_4 -> V_20 ;
for ( V_6 = 0 ; V_6 < V_15 ; V_6 ++ ) {
F_13 ( V_10 -> V_36 ) ;
V_10 ++ ;
}
F_14 ( V_4 -> V_14 ) ;
if ( F_15 ( & V_4 -> V_24 ) )
F_16 ( V_37 L_2 ) ;
F_17 ( & V_4 -> V_24 ) ;
if ( F_15 ( & V_4 -> V_29 ) )
F_16 ( V_37 L_3 , F_15 ( & V_4 -> V_29 ) ) ;
F_17 ( & V_4 -> V_29 ) ;
}
