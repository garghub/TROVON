struct V_1 * F_1 ( struct V_2 * V_2 ,
const char * V_3 ,
const void * V_4 , T_1 V_5 ,
T_2 V_6 )
{
int V_7 ;
struct V_8 * V_9 = F_2 ( V_2 ) ;
T_1 V_10 ;
void * V_11 ;
struct V_1 * V_12 ;
V_10 = F_3 ( V_5 )
+ F_3 ( sizeof( V_13 ) )
+ ( V_3 ? F_3 ( strlen ( V_3 ) ) : 0 ) ;
V_7 = - V_14 ;
V_12 = F_4 ( V_10 , V_6 ) ;
if ( V_12 == NULL )
goto V_15;
V_11 = F_5 ( V_12 , 0 , 0 , & V_16 ,
0 , V_17 ) ;
if ( V_11 == NULL ) {
F_6 ( V_9 , L_1 ) ;
goto V_18;
}
V_7 = F_7 ( V_12 , V_19 ,
V_2 -> V_20 -> V_21 ) ;
if ( V_7 < 0 ) {
F_6 ( V_9 , L_2 ) ;
goto V_22;
}
if ( V_3 ) {
V_7 = F_8 ( V_12 , V_23 ,
V_3 ) ;
if ( V_7 < 0 ) {
F_6 ( V_9 , L_3 ) ;
goto V_22;
}
}
V_7 = F_9 ( V_12 , V_24 , V_5 , V_4 ) ;
if ( V_7 < 0 ) {
F_6 ( V_9 , L_4
L_5 , V_4 , V_5 , V_7 ) ;
goto V_22;
}
F_10 ( V_12 , V_11 ) ;
return V_12 ;
V_22:
V_18:
V_15:
F_11 ( V_12 ) ;
return F_12 ( V_7 ) ;
}
const void * F_13 ( struct V_1 * V_4 , T_1 * V_5 )
{
struct V_25 * V_26 = ( void * ) V_4 -> V_27 ;
struct V_28 * V_29 ;
V_29 = F_14 ( V_26 , sizeof( struct V_30 ) ,
V_24 ) ;
if ( V_29 == NULL ) {
F_15 ( V_31 L_6 ) ;
return NULL ;
}
* V_5 = F_16 ( V_29 ) ;
return F_17 ( V_29 ) ;
}
const void * F_18 ( struct V_1 * V_4 )
{
struct V_25 * V_26 = ( void * ) V_4 -> V_27 ;
struct V_28 * V_29 ;
V_29 = F_14 ( V_26 , sizeof( struct V_30 ) ,
V_24 ) ;
if ( V_29 == NULL ) {
F_15 ( V_31 L_6 ) ;
return NULL ;
}
return F_17 ( V_29 ) ;
}
T_3 F_19 ( struct V_1 * V_4 )
{
struct V_25 * V_26 = ( void * ) V_4 -> V_27 ;
struct V_28 * V_29 ;
V_29 = F_14 ( V_26 , sizeof( struct V_30 ) ,
V_24 ) ;
if ( V_29 == NULL ) {
F_15 ( V_31 L_6 ) ;
return - V_32 ;
}
return F_16 ( V_29 ) ;
}
int F_20 ( struct V_2 * V_2 , struct V_1 * V_12 )
{
struct V_8 * V_9 = F_2 ( V_2 ) ;
void * V_4 = V_12 -> V_33 ;
T_1 V_5 = V_12 -> V_34 ;
F_21 () ;
F_22 ( 1 , V_9 , L_7 , V_5 ) ;
F_23 ( 2 , V_9 , V_4 , V_5 ) ;
F_24 ( & V_16 , V_12 , 0 , 0 , V_35 ) ;
F_22 ( 1 , V_9 , L_8 ) ;
return 0 ;
}
int F_25 ( struct V_2 * V_2 , const char * V_3 ,
const void * V_36 , T_1 V_5 , T_2 V_6 )
{
int V_7 = - V_14 ;
struct V_1 * V_12 ;
V_12 = F_1 ( V_2 , V_3 , V_36 , V_5 , V_6 ) ;
if ( F_26 ( V_12 ) )
V_7 = F_27 ( V_12 ) ;
else
V_7 = F_20 ( V_2 , V_12 ) ;
return V_7 ;
}
int F_28 ( struct V_1 * V_12 , struct V_37 * V_38 )
{
int V_7 , V_21 ;
struct V_2 * V_2 ;
struct V_8 * V_9 ;
struct V_25 * V_26 = V_38 -> V_39 ;
char * V_3 ;
void * V_40 ;
T_1 V_41 ;
F_21 () ;
F_29 ( 3 , NULL , L_9 , V_12 , V_38 ) ;
V_7 = - V_42 ;
if ( V_38 -> V_43 [ V_19 ] == NULL ) {
F_15 ( V_31 L_10
L_11 ) ;
goto V_44;
}
V_21 = F_30 ( V_38 -> V_43 [ V_19 ] ) ;
V_2 = F_31 ( V_38 , V_21 ) ;
if ( V_2 == NULL )
goto V_44;
V_9 = F_2 ( V_2 ) ;
V_7 = - V_32 ;
if ( V_38 -> V_43 [ V_24 ] == NULL ) {
F_6 ( V_9 , L_12
L_11 ) ;
goto V_45;
}
V_40 = F_17 ( V_38 -> V_43 [ V_24 ] ) ;
V_41 = F_16 ( V_38 -> V_43 [ V_24 ] ) ;
if ( V_38 -> V_43 [ V_23 ] == NULL )
V_3 = NULL ;
else {
struct V_28 * V_46 = V_38 -> V_43 [ V_23 ] ;
T_1 V_47 = F_16 ( V_46 ) ;
V_7 = - V_14 ;
V_3 = F_32 ( F_17 ( V_46 ) , V_47 + 1 , V_35 ) ;
if ( V_3 == NULL )
goto V_48;
V_3 [ V_47 ] = 0 ;
}
F_33 ( & V_2 -> V_49 ) ;
V_7 = F_34 ( V_2 ) ;
if ( V_7 == - V_50 )
V_7 = 0 ;
if ( V_7 < 0 )
goto V_51;
V_7 = - V_52 ;
if ( V_2 -> V_53 == NULL )
goto V_54;
F_22 ( 1 , V_9 ,
L_13 ,
V_26 -> V_55 , V_26 -> V_56 , V_26 -> V_57 ,
V_26 -> V_58 , V_26 -> V_59 ) ;
F_22 ( 1 , V_9 , L_14 , V_41 ) ;
F_23 ( 2 , V_9 , V_40 , V_41 ) ;
V_7 = V_2 -> V_53 ( V_2 , V_3 ,
V_40 , V_41 , V_38 ) ;
V_54:
V_51:
F_35 ( & V_2 -> V_49 ) ;
V_48:
F_36 ( V_3 ) ;
V_45:
F_37 ( V_2 -> V_20 ) ;
V_44:
F_38 ( 3 , NULL , L_15 , V_12 , V_38 , V_7 ) ;
return V_7 ;
}
