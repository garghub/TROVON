void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = 0 ;
V_4 -> V_6 = 0 ;
V_4 -> V_7 = 0 ;
if ( V_4 -> V_8 ) {
V_4 -> V_9 = V_4 -> V_8 ;
V_4 -> V_10 = V_4 -> V_8 ;
V_4 -> V_11 = V_4 -> V_8 ;
V_4 -> V_12 = V_4 -> V_9 + V_13 ;
}
}
int F_2 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = & V_2 -> V_16 ;
int V_17 , V_18 = V_19 ;
struct V_3 * V_4 ;
F_3 ( & V_15 -> V_20 ,
( void (*) ( unsigned long ) ) V_21 ,
( unsigned long ) V_2 ) ;
F_4 ( & V_15 -> V_22 ) ;
V_15 -> V_23 = F_5 ( V_24 * sizeof( struct V_3 ) + 4 ) ;
if ( V_15 -> V_23 == NULL ) {
V_18 = V_25 ;
F_6 ( V_26 , V_27 , ( L_1 ) ) ;
goto exit;
}
F_7 ( V_15 -> V_23 , 0 , V_24 * sizeof( struct V_3 ) + 4 ) ;
V_15 -> V_28 = ( V_29 * ) F_8 ( ( V_30 ) ( V_15 -> V_23 ) , 4 ) ;
V_4 = (struct V_3 * ) V_15 -> V_28 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
F_9 ( & V_4 -> V_31 ) ;
F_10 ( & V_4 -> V_32 ) ;
V_4 -> V_33 = V_13 ;
V_18 = F_11 ( V_2 , V_4 ) ;
if ( V_18 == V_25 )
break;
V_4 -> V_7 = 0 ;
V_4 -> V_1 = V_2 ;
V_4 ++ ;
}
V_15 -> V_34 = V_24 ;
F_12 ( & V_15 -> V_35 ) ;
{
int V_17 ;
V_30 V_36 = 0 ;
V_30 V_37 = 0 ;
struct V_38 * V_39 = NULL ;
F_12 ( & V_15 -> V_40 ) ;
for ( V_17 = 0 ; V_17 < V_41 ; V_17 ++ ) {
V_39 = F_13 ( V_2 -> V_42 , V_13 + V_43 , V_44 ) ;
if ( V_39 ) {
V_39 -> V_45 = V_2 -> V_42 ;
V_36 = ( V_30 ) V_39 -> V_46 ;
V_37 = V_36 & ( V_43 - 1 ) ;
F_14 ( V_39 , ( V_43 - V_37 ) ) ;
F_15 ( & V_15 -> V_40 , V_39 ) ;
}
V_39 = NULL ;
}
}
exit:
return V_18 ;
}
void F_16 ( struct V_1 * V_2 )
{
int V_17 ;
struct V_3 * V_4 ;
struct V_14 * V_15 = & V_2 -> V_16 ;
V_4 = (struct V_3 * ) V_15 -> V_28 ;
for ( V_17 = 0 ; V_17 < V_24 ; V_17 ++ ) {
F_17 ( V_2 , V_4 ) ;
V_4 ++ ;
}
F_18 ( V_15 -> V_23 ) ;
if ( F_19 ( & V_15 -> V_35 ) )
F_20 ( V_47 L_2 ) ;
F_21 ( & V_15 -> V_35 ) ;
if ( F_19 ( & V_15 -> V_40 ) )
F_20 ( V_47 L_3 , F_19 ( & V_15 -> V_40 ) ) ;
F_21 ( & V_15 -> V_40 ) ;
}
