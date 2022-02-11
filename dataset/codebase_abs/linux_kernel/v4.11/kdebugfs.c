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
static int T_6
F_8 ( struct V_21 * V_22 , int V_23 ,
struct V_5 * V_6 )
{
struct V_21 * V_24 , * type , * V_25 ;
char V_26 [ 16 ] ;
sprintf ( V_26 , L_1 , V_23 ) ;
V_24 = F_9 ( V_26 , V_22 ) ;
if ( ! V_24 )
return - V_27 ;
type = F_10 ( L_2 , V_28 , V_24 , & V_6 -> type ) ;
if ( ! type )
goto V_29;
V_25 = F_11 ( L_3 , V_28 , V_24 , V_6 , & V_30 ) ;
if ( ! V_25 )
goto V_31;
return 0 ;
V_31:
F_12 ( type ) ;
V_29:
F_12 ( V_24 ) ;
return - V_27 ;
}
static int T_6 F_13 ( struct V_21 * V_22 )
{
struct V_5 * V_6 ;
struct V_17 * V_25 ;
int error ;
struct V_21 * V_24 ;
struct V_10 * V_11 ;
T_5 V_32 ;
int V_23 = 0 ;
V_24 = F_9 ( L_4 , V_22 ) ;
if ( ! V_24 )
return - V_27 ;
V_32 = V_33 . V_34 . V_17 ;
while ( V_32 ) {
V_6 = F_14 ( sizeof( * V_6 ) , V_35 ) ;
if ( ! V_6 ) {
error = - V_27 ;
goto V_29;
}
V_11 = F_2 ( ( V_32 + sizeof( * V_25 ) - 1 ) >> V_18 ) ;
if ( F_3 ( V_11 ) ) {
V_25 = F_4 ( V_32 , sizeof( * V_25 ) ) ;
if ( ! V_25 ) {
F_15 ( V_6 ) ;
error = - V_19 ;
goto V_29;
}
} else
V_25 = F_5 ( V_32 ) ;
V_6 -> V_16 = V_32 ;
V_6 -> type = V_25 -> type ;
V_6 -> V_15 = V_25 -> V_15 ;
error = F_8 ( V_24 , V_23 , V_6 ) ;
V_32 = V_25 -> V_36 ;
if ( F_3 ( V_11 ) )
F_7 ( V_25 ) ;
if ( error )
goto V_29;
V_23 ++ ;
}
return 0 ;
V_29:
F_12 ( V_24 ) ;
return error ;
}
static int T_6 F_16 ( void )
{
struct V_21 * V_37 , * V_38 , * V_25 ;
int error = - V_27 ;
V_37 = F_9 ( L_5 , V_39 ) ;
if ( ! V_37 )
return - V_27 ;
V_38 = F_17 ( L_6 , V_28 , V_37 ,
& V_33 . V_34 . V_38 ) ;
if ( ! V_38 )
goto V_29;
V_25 = F_18 ( L_3 , V_28 , V_37 ,
& V_40 ) ;
if ( ! V_25 )
goto V_41;
error = F_13 ( V_37 ) ;
if ( error )
goto V_42;
return 0 ;
V_42:
F_12 ( V_25 ) ;
V_41:
F_12 ( V_38 ) ;
V_29:
F_12 ( V_37 ) ;
return error ;
}
static int T_6 F_19 ( void )
{
int error = 0 ;
V_39 = F_9 ( L_7 , NULL ) ;
if ( ! V_39 )
return - V_27 ;
#ifdef F_20
error = F_16 () ;
#endif
return error ;
}
