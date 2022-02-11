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
V_6 = V_4 -> V_10 = F_6 ( sizeof( struct V_5 ) ,
V_15 ) ;
if ( V_6 == NULL )
goto V_16;
V_4 -> V_17 = ( V_18 * ) V_2 ;
F_2 ( & V_4 -> V_19 ) ;
F_3 ( V_4 ) ;
F_4 ( & V_4 -> V_20 ) ;
V_6 -> V_21 = ( V_18 * ) & ( V_2 -> V_22 ) ;
if ( F_5 ( V_6 ) == V_23 )
goto V_16;
return V_24 ;
V_16:
F_7 ( V_6 ) ;
return V_23 ;
}
static void F_8 ( struct V_5 * V_10 )
{
void (* F_9)( struct V_5 * V_10 );
F_9 = & V_25 ;
F_9 ( V_10 ) ;
F_7 ( V_10 ) ;
}
static T_1 F_10 ( V_18 * V_26 , struct V_3 * V_27 )
{
struct V_1 * V_17 = (struct V_1 * ) V_26 ;
V_27 -> V_19 = 0 ;
V_27 -> V_17 = V_26 ;
V_27 -> V_21 = ( V_18 * ) & ( V_17 -> V_22 ) ;
if ( F_1 ( V_17 , V_27 ) == false )
goto V_28;
return V_24 ;
V_28:
return false ;
}
static void F_11 ( struct V_3 * V_27 )
{
F_8 ( V_27 -> V_10 ) ;
memset ( ( V_18 * ) V_27 , 0 , sizeof( struct V_3 ) ) ;
}
T_1 F_12 ( struct V_1 * V_17 )
{
T_2 V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
V_31 = F_6 ( sizeof( * V_31 ) , V_15 ) ;
if ( V_31 == NULL )
goto V_34;
F_13 ( & V_31 -> V_35 ) ;
F_13 ( & V_31 -> V_36 ) ;
F_13 ( & V_31 -> V_37 ) ;
F_14 ( & V_31 -> V_38 ) ;
V_31 -> V_39 = F_6 ( V_40 *
( sizeof( struct V_32 ) ) + 4 ,
V_15 ) ;
if ( ( V_31 -> V_39 ) == NULL )
goto V_34;
memset ( V_31 -> V_39 , 0 ,
( V_40 * ( sizeof( struct V_32 ) ) + 4 ) ) ;
V_31 -> V_41 = V_31 -> V_39 + 4
- ( ( V_42 ) ( V_31 -> V_39 )
& 3 ) ;
V_33 = (struct V_32 * ) ( V_31 -> V_41 ) ;
for ( V_29 = 0 ; V_29 < V_40 ; V_29 ++ ) {
F_13 ( & V_33 -> V_43 ) ;
F_15 ( & V_33 -> V_43 , & V_31 -> V_35 ) ;
V_33 ++ ;
}
if ( ( F_10 ( ( V_18 * ) V_17 , & ( V_31 -> V_44 ) ) ) == V_23 )
goto V_34;
V_17 -> V_31 = V_31 ;
return V_24 ;
V_34:
if ( V_31 ) {
F_7 ( V_31 -> V_39 ) ;
F_7 ( ( V_18 * ) V_31 ) ;
}
V_17 -> V_31 = NULL ;
return V_23 ;
}
void F_16 ( struct V_1 * V_17 )
{
struct V_30 * V_31 = (struct V_30 * ) ( V_17 -> V_31 ) ;
if ( V_31 ) {
F_7 ( V_31 -> V_39 ) ;
V_17 -> V_31 = NULL ;
F_11 ( & V_31 -> V_44 ) ;
F_7 ( ( V_18 * ) V_31 ) ;
}
}
