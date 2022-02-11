static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
void (* F_2)( T_2 * V_7 ) = NULL ;
void (* F_3)( struct V_3 * V_4 );
void (* F_4)( struct V_8 * V_9 );
T_1 (* F_5)( struct V_5 * V_10 );
F_2 = & ( V_11 ) ;
F_3 = & ( V_12 ) ;
F_4 = & V_13 ;
F_5 = & V_14 ;
V_6 = V_4 -> V_10 = (struct V_5 * )
F_6 ( sizeof( struct V_5 ) ) ;
if ( V_6 == NULL )
goto V_15;
V_4 -> V_16 = ( V_17 * ) V_2 ;
F_2 ( & V_4 -> V_18 ) ;
F_3 ( V_4 ) ;
F_4 ( & V_4 -> V_19 ) ;
V_6 -> V_20 = ( V_17 * ) & ( V_2 -> V_21 ) ;
if ( F_5 ( V_6 ) == V_22 )
goto V_15;
return V_23 ;
V_15:
F_7 ( V_6 ) ;
return V_22 ;
}
static void F_8 ( struct V_5 * V_10 )
{
void (* F_9)( struct V_5 * V_10 );
F_9 = & V_24 ;
F_9 ( V_10 ) ;
F_7 ( V_10 ) ;
}
static T_1 F_10 ( V_17 * V_25 , struct V_3 * V_26 )
{
struct V_1 * V_16 = (struct V_1 * ) V_25 ;
V_26 -> V_18 = 0 ;
V_26 -> V_16 = V_25 ;
V_26 -> V_20 = ( V_17 * ) & ( V_16 -> V_21 ) ;
if ( F_1 ( V_16 , V_26 ) == false )
goto V_27;
return V_23 ;
V_27:
return false ;
}
static void F_11 ( struct V_3 * V_26 )
{
F_8 ( V_26 -> V_10 ) ;
memset ( ( V_17 * ) V_26 , 0 , sizeof( struct V_3 ) ) ;
}
T_1 F_12 ( struct V_1 * V_16 )
{
T_2 V_28 ;
struct V_29 * V_30 ;
struct V_31 * V_32 ;
V_30 = (struct V_29 * ) F_6 ( sizeof( struct V_29 ) ) ;
if ( V_30 == NULL )
goto V_33;
F_13 ( & V_30 -> V_34 ) ;
F_13 ( & V_30 -> V_35 ) ;
F_13 ( & V_30 -> V_36 ) ;
F_14 ( & V_30 -> V_37 ) ;
V_30 -> V_38 = ( V_17 * ) F_6 ( V_39 *
( sizeof( struct V_31 ) ) + 4 ) ;
if ( ( V_30 -> V_38 ) == NULL )
goto V_33;
memset ( V_30 -> V_38 , 0 ,
( V_39 * ( sizeof( struct V_31 ) ) + 4 ) ) ;
V_30 -> V_40 = V_30 -> V_38 + 4
- ( ( V_41 ) ( V_30 -> V_38 )
& 3 ) ;
V_32 = (struct V_31 * ) ( V_30 -> V_40 ) ;
for ( V_28 = 0 ; V_28 < V_39 ; V_28 ++ ) {
F_13 ( & V_32 -> V_42 ) ;
F_15 ( & V_32 -> V_42 , & V_30 -> V_34 ) ;
V_32 ++ ;
}
if ( ( F_10 ( ( V_17 * ) V_16 , & ( V_30 -> V_43 ) ) ) == V_22 )
goto V_33;
V_16 -> V_30 = V_30 ;
return V_23 ;
V_33:
if ( V_30 ) {
F_7 ( V_30 -> V_38 ) ;
F_7 ( ( V_17 * ) V_30 ) ;
}
V_16 -> V_30 = NULL ;
return V_22 ;
}
void F_16 ( struct V_1 * V_16 )
{
struct V_29 * V_30 = (struct V_29 * ) ( V_16 -> V_30 ) ;
if ( V_30 ) {
F_7 ( V_30 -> V_38 ) ;
V_16 -> V_30 = NULL ;
F_11 ( & V_30 -> V_43 ) ;
F_7 ( ( V_17 * ) V_30 ) ;
}
}
