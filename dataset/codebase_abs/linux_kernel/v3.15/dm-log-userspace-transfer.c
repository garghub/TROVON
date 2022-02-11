static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_6 ;
memset ( V_5 , 0 , sizeof( struct V_4 ) ) ;
V_5 -> V_7 . V_8 = V_9 . V_8 ;
V_5 -> V_7 . V_10 = V_9 . V_10 ;
V_5 -> V_11 = 0 ;
V_5 -> V_12 = V_2 -> V_12 ;
V_5 -> V_13 = sizeof( struct V_1 ) + V_2 -> V_14 ;
V_3 = F_2 ( V_5 , 0 , 0 , F_3 () ) ;
return V_3 ;
}
static int F_4 ( struct V_4 * V_5 , struct V_1 * V_2 )
{
T_1 V_15 = ( V_5 ) ? V_5 -> V_12 : ( V_2 ) ? V_2 -> V_12 : 0 ;
struct V_16 * V_17 ;
F_5 (pkg, &receiving_list, list) {
if ( V_15 != V_17 -> V_12 )
continue;
if ( V_5 ) {
V_17 -> error = - V_5 -> V_11 ;
if ( V_17 -> error != - V_18 )
* ( V_17 -> V_14 ) = 0 ;
} else if ( V_2 -> V_14 > * ( V_17 -> V_14 ) ) {
F_6 ( L_1
L_2 , V_2 -> V_19 ,
V_2 -> V_14 , * ( V_17 -> V_14 ) ) ;
* ( V_17 -> V_14 ) = 0 ;
V_17 -> error = - V_20 ;
} else {
V_17 -> error = V_2 -> error ;
memcpy ( V_17 -> V_21 , V_2 -> V_21 , V_2 -> V_14 ) ;
* ( V_17 -> V_14 ) = V_2 -> V_14 ;
}
F_7 ( & V_17 -> F_7 ) ;
return 0 ;
}
return - V_22 ;
}
static void F_8 ( struct V_4 * V_5 , struct V_23 * V_24 )
{
struct V_1 * V_2 = (struct V_1 * ) ( V_5 + 1 ) ;
if ( ! F_9 ( V_25 ) )
return;
F_10 ( & V_26 ) ;
if ( V_5 -> V_13 == 0 )
F_4 ( V_5 , NULL ) ;
else if ( V_5 -> V_13 < sizeof( * V_2 ) )
F_6 ( L_3 ,
( unsigned ) sizeof( * V_2 ) , V_5 -> V_13 , V_5 -> V_12 ) ;
else
F_4 ( NULL , V_2 ) ;
F_11 ( & V_26 ) ;
}
int F_12 ( const char * V_27 , T_2 V_28 , int V_19 ,
char * V_21 , T_3 V_14 ,
char * V_29 , T_3 * V_30 )
{
int V_3 = 0 ;
T_3 V_31 = 0 ;
int V_32 = sizeof( struct V_1 ) + sizeof( struct V_4 ) ;
struct V_1 * V_2 = V_33 ;
struct V_16 V_17 ;
if ( V_14 > ( V_34 - V_32 ) ) {
F_13 ( L_4 ) ;
return - V_35 ;
}
if ( ! V_30 )
V_30 = & V_31 ;
V_36:
F_14 ( & V_37 ) ;
memset ( V_2 , 0 , V_34 - sizeof( struct V_4 ) ) ;
memcpy ( V_2 -> V_27 , V_27 , V_38 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_12 = V_41 ++ ;
V_2 -> V_19 = V_19 & V_42 ;
V_2 -> V_14 = V_14 ;
if ( V_21 && V_14 )
memcpy ( V_2 -> V_21 , V_21 , V_14 ) ;
memset ( & V_17 , 0 , sizeof( V_17 ) ) ;
F_15 ( & V_17 . F_7 ) ;
V_17 . V_12 = V_2 -> V_12 ;
V_17 . V_14 = V_30 ;
V_17 . V_21 = V_29 ;
F_10 ( & V_26 ) ;
F_16 ( & ( V_17 . V_43 ) , & V_44 ) ;
F_11 ( & V_26 ) ;
V_3 = F_1 ( V_2 ) ;
F_17 ( & V_37 ) ;
if ( V_3 ) {
F_6 ( L_5 ,
V_19 , V_3 ) ;
F_10 ( & V_26 ) ;
F_18 ( & ( V_17 . V_43 ) ) ;
F_11 ( & V_26 ) ;
goto V_45;
}
V_3 = F_19 ( & ( V_17 . F_7 ) , V_46 ) ;
F_10 ( & V_26 ) ;
F_18 ( & ( V_17 . V_43 ) ) ;
F_11 ( & V_26 ) ;
if ( ! V_3 ) {
F_20 ( L_6 ,
( strlen ( V_27 ) > 8 ) ?
( V_27 + ( strlen ( V_27 ) - 8 ) ) : ( V_27 ) ,
V_19 , V_17 . V_12 ) ;
goto V_36;
}
V_3 = V_17 . error ;
if ( V_3 == - V_18 )
goto V_36;
V_45:
return V_3 ;
}
int F_21 ( void )
{
int V_3 ;
void * V_47 ;
F_22 ( & V_44 ) ;
V_47 = F_23 ( V_34 , V_48 ) ;
if ( ! V_47 )
return - V_49 ;
V_6 = V_47 ;
V_33 = V_47 + sizeof( struct V_4 ) ;
V_3 = F_24 ( & V_9 , L_7 , F_8 ) ;
if ( V_3 ) {
F_25 ( & V_9 ) ;
return V_3 ;
}
return 0 ;
}
void F_26 ( void )
{
F_25 ( & V_9 ) ;
F_27 ( V_6 ) ;
}
