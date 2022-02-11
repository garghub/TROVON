static char * F_1 ( unsigned long V_1 , char * V_2 , int V_3 )
{
V_2 [ 0 ] = '\0' ;
if ( V_1 & V_4 )
F_2 ( V_2 , L_1 , V_3 ) ;
if ( V_1 & V_5 )
F_2 ( V_2 , L_2 , V_3 ) ;
if ( V_1 & V_6 )
F_2 ( V_2 , L_3 , V_3 ) ;
if ( V_1 & V_7 )
F_2 ( V_2 , L_4 , V_3 ) ;
if ( V_2 [ 0 ] == '\0' )
F_2 ( V_2 , L_5 , V_3 ) ;
return V_2 ;
}
static int F_3 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_14 * V_15 = & V_12 -> V_16 . V_15 ;
struct V_17 * V_18 = NULL ;
char V_19 [ 32 ] ;
F_4 ( strcmp ( V_12 -> V_20 -> V_21 , V_22 ) == 0 ||
strcmp ( V_12 -> V_20 -> V_21 , V_23 ) == 0 ||
strcmp ( V_12 -> V_20 -> V_21 , V_24 ) == 0 ) ;
if ( V_15 -> V_25 )
V_18 = F_5 ( V_15 -> V_25 ) ;
if ( V_18 == NULL )
goto V_26;
F_1 ( V_18 -> V_27 . V_28 , V_19 , sizeof( V_19 ) ) ;
F_6 ( V_9 , L_6 ,
F_7 ( V_18 -> V_27 . V_29 ) ) ;
F_6 ( V_9 , L_7 ,
F_8 ( & V_18 -> V_27 , V_19 , sizeof( V_19 ) ) ) ;
F_6 ( V_9 , L_8 ,
F_1 ( V_18 -> V_27 . V_28 , V_19 , sizeof( V_19 ) ) ) ;
F_6 ( V_9 , L_9 , V_18 -> V_30 ) ;
F_6 ( V_9 , L_10 ,
F_9 ( & V_18 -> V_31 ) ) ;
F_6 ( V_9 , L_11 , F_9 ( & V_18 -> V_32 ) ) ;
F_6 ( V_9 , L_12 , V_18 -> V_33 ) ;
F_6 ( V_9 , L_13 ,
V_18 -> V_33 ?
( V_34 ) ( V_18 -> V_35 - F_10 () ) : 0ll ) ;
F_11 ( V_18 ) ;
V_26:
return 0 ;
}
static int F_12 ( struct V_8 * V_9 , void * V_10 )
{
struct V_11 * V_12 = V_9 -> V_13 ;
struct V_14 * V_15 = & V_12 -> V_16 . V_15 ;
struct V_17 * V_18 = NULL ;
F_4 ( strcmp ( V_12 -> V_20 -> V_21 , V_22 ) == 0 ||
strcmp ( V_12 -> V_20 -> V_21 , V_23 ) == 0 ||
strcmp ( V_12 -> V_20 -> V_21 , V_24 ) == 0 ) ;
if ( V_15 -> V_25 )
V_18 = F_5 ( V_15 -> V_25 ) ;
if ( V_18 == NULL )
goto V_26;
if ( V_18 -> V_36 -> V_37 -> V_38 )
V_18 -> V_36 -> V_37 -> V_38 ( V_18 , V_9 ) ;
F_11 ( V_18 ) ;
V_26:
return 0 ;
}
int F_13 ( struct V_11 * V_12 )
{
int V_39 ;
if ( strcmp ( V_12 -> V_20 -> V_21 , V_22 ) != 0 &&
strcmp ( V_12 -> V_20 -> V_21 , V_23 ) != 0 &&
strcmp ( V_12 -> V_20 -> V_21 , V_24 ) != 0 ) {
F_14 ( L_14 ,
V_12 -> V_20 -> V_21 ) ;
return - V_40 ;
}
V_39 = F_15 ( V_12 , L_15 , 0444 ,
& V_41 , V_12 ) ;
if ( V_39 ) {
F_14 ( L_16 ,
V_12 -> V_42 , V_39 ) ;
return V_39 ;
}
V_39 = F_15 ( V_12 , L_17 , 0444 ,
& V_43 , V_12 ) ;
if ( V_39 ) {
F_14 ( L_18 ,
V_12 -> V_42 , V_39 ) ;
return V_39 ;
}
return 0 ;
}
int F_16 ( void )
{
int V_39 ;
F_4 ( V_44 == NULL ) ;
V_44 = F_17 ( L_19 , V_45 ,
V_46 , NULL ) ;
if ( F_18 ( V_44 ) ) {
V_39 = V_44 ? F_19 ( V_44 )
: - V_47 ;
V_44 = NULL ;
return V_39 ;
}
return 0 ;
}
void F_20 ( void )
{
if ( ! F_18 ( V_44 ) )
F_21 ( & V_44 ) ;
}
