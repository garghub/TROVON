static T_1 F_1 ( struct V_1 * V_1 , char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
struct V_5 * V_6 = V_1 -> V_7 ;
unsigned long V_8 ;
T_4 V_9 = * V_4 ;
struct V_10 * V_11 ;
void * V_12 ;
T_5 V_13 ;
if ( V_9 < 0 )
return - V_14 ;
if ( V_9 >= V_6 -> V_15 )
return 0 ;
if ( V_3 > V_6 -> V_15 - V_9 )
V_3 = V_6 -> V_15 - V_9 ;
V_13 = V_6 -> V_16 + sizeof( struct V_17 ) + V_9 ;
V_11 = F_2 ( ( V_13 + V_3 - 1 ) >> V_18 ) ;
if ( F_3 ( V_11 ) ) {
V_12 = F_4 ( V_13 , V_3 ) ;
if ( ! V_12 )
return - V_19 ;
} else
V_12 = F_5 ( V_13 ) ;
V_8 = F_6 ( V_2 , V_12 , V_3 ) ;
if ( F_3 ( V_11 ) )
F_7 ( V_12 ) ;
if ( V_8 )
return - V_20 ;
* V_4 = V_9 + V_3 ;
return V_3 ;
}
static int F_8 ( struct V_21 * V_21 , struct V_1 * V_1 )
{
V_1 -> V_7 = V_21 -> V_22 ;
return 0 ;
}
static int T_6
F_9 ( struct V_23 * V_24 , int V_25 ,
struct V_5 * V_6 )
{
struct V_23 * V_26 , * type , * V_27 ;
char V_28 [ 16 ] ;
sprintf ( V_28 , L_1 , V_25 ) ;
V_26 = F_10 ( V_28 , V_24 ) ;
if ( ! V_26 )
return - V_29 ;
type = F_11 ( L_2 , V_30 , V_26 , & V_6 -> type ) ;
if ( ! type )
goto V_31;
V_27 = F_12 ( L_3 , V_30 , V_26 , V_6 , & V_32 ) ;
if ( ! V_27 )
goto V_33;
return 0 ;
V_33:
F_13 ( type ) ;
V_31:
F_13 ( V_26 ) ;
return - V_29 ;
}
static int T_6 F_14 ( struct V_23 * V_24 )
{
struct V_5 * V_6 ;
struct V_17 * V_27 ;
int error = - V_29 ;
struct V_23 * V_26 ;
struct V_10 * V_11 ;
T_5 V_34 ;
int V_25 = 0 ;
V_26 = F_10 ( L_4 , V_24 ) ;
if ( ! V_26 )
return - V_29 ;
V_34 = V_35 . V_36 . V_17 ;
while ( V_34 ) {
V_6 = F_15 ( sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
goto V_31;
V_11 = F_2 ( ( V_34 + sizeof( * V_27 ) - 1 ) >> V_18 ) ;
if ( F_3 ( V_11 ) ) {
V_27 = F_4 ( V_34 , sizeof( * V_27 ) ) ;
if ( ! V_27 ) {
F_16 ( V_6 ) ;
error = - V_19 ;
goto V_31;
}
} else
V_27 = F_5 ( V_34 ) ;
V_6 -> V_16 = V_34 ;
V_6 -> type = V_27 -> type ;
V_6 -> V_15 = V_27 -> V_15 ;
error = F_9 ( V_26 , V_25 , V_6 ) ;
V_34 = V_27 -> V_38 ;
if ( F_3 ( V_11 ) )
F_7 ( V_27 ) ;
if ( error )
goto V_31;
V_25 ++ ;
}
return 0 ;
V_31:
F_13 ( V_26 ) ;
return error ;
}
static int T_6 F_17 ( void )
{
struct V_23 * V_39 , * V_40 , * V_27 ;
int error = - V_29 ;
V_39 = F_10 ( L_5 , NULL ) ;
if ( ! V_39 )
return - V_29 ;
V_40 = F_18 ( L_6 , V_30 , V_39 ,
& V_35 . V_36 . V_40 ) ;
if ( ! V_40 )
goto V_31;
V_27 = F_19 ( L_3 , V_30 , V_39 ,
& V_41 ) ;
if ( ! V_27 )
goto V_42;
error = F_14 ( V_39 ) ;
if ( error )
goto V_43;
return 0 ;
V_43:
F_13 ( V_27 ) ;
V_42:
F_13 ( V_40 ) ;
V_31:
F_13 ( V_39 ) ;
return error ;
}
static int T_6 F_20 ( void )
{
int error = 0 ;
V_44 = F_10 ( L_7 , NULL ) ;
if ( ! V_44 )
return - V_29 ;
#ifdef F_21
error = F_17 () ;
#endif
return error ;
}
