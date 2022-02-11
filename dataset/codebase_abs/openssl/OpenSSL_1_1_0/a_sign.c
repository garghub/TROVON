int F_1 ( T_1 * V_1 , T_2 * V_2 , T_2 * V_3 ,
T_3 * V_4 , char * V_5 , T_4 * V_6 ,
const T_5 * type )
{
T_6 * V_7 = F_2 () ;
unsigned char * V_8 , * V_9 = NULL , * V_10 = NULL ;
int V_11 , V_12 = 0 , V_13 = 0 , V_14 = 0 ;
T_2 * V_15 ;
if ( V_7 == NULL ) {
F_3 ( V_16 , V_17 ) ;
goto V_18;
}
for ( V_11 = 0 ; V_11 < 2 ; V_11 ++ ) {
if ( V_11 == 0 )
V_15 = V_2 ;
else
V_15 = V_3 ;
if ( V_15 == NULL )
continue;
if ( type -> V_19 == V_20 ) {
F_4 ( V_15 -> V_21 ) ;
V_15 -> V_21 = NULL ;
} else if ( ( V_15 -> V_21 == NULL ) ||
( V_15 -> V_21 -> type != V_22 ) ) {
F_4 ( V_15 -> V_21 ) ;
if ( ( V_15 -> V_21 = F_5 () ) == NULL )
goto V_18;
V_15 -> V_21 -> type = V_22 ;
}
F_6 ( V_15 -> V_23 ) ;
V_15 -> V_23 = F_7 ( type -> V_19 ) ;
if ( V_15 -> V_23 == NULL ) {
F_3 ( V_16 , V_24 ) ;
goto V_18;
}
if ( V_15 -> V_23 -> V_25 == 0 ) {
F_3 ( V_16 ,
V_26 ) ;
goto V_18;
}
}
V_12 = V_1 ( V_5 , NULL ) ;
V_9 = F_8 ( ( unsigned int ) V_12 ) ;
V_14 = V_13 = F_9 ( V_6 ) ;
V_10 = F_8 ( ( unsigned int ) V_13 ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) ) {
V_13 = 0 ;
F_3 ( V_16 , V_17 ) ;
goto V_18;
}
V_8 = V_9 ;
V_1 ( V_5 , & V_8 ) ;
if ( ! F_10 ( V_7 , type , NULL )
|| ! F_11 ( V_7 , ( unsigned char * ) V_9 , V_12 )
|| ! F_12 ( V_7 , ( unsigned char * ) V_10 ,
( unsigned int * ) & V_13 , V_6 ) ) {
V_13 = 0 ;
F_3 ( V_16 , V_27 ) ;
goto V_18;
}
F_13 ( V_4 -> V_5 ) ;
V_4 -> V_5 = V_10 ;
V_10 = NULL ;
V_4 -> V_25 = V_13 ;
V_4 -> V_28 &= ~ ( V_29 | 0x07 ) ;
V_4 -> V_28 |= V_29 ;
V_18:
F_14 ( V_7 ) ;
F_15 ( ( char * ) V_9 , ( unsigned int ) V_12 ) ;
F_15 ( ( char * ) V_10 , V_14 ) ;
return ( V_13 ) ;
}
int F_16 ( const T_7 * V_30 , T_2 * V_2 ,
T_2 * V_3 , T_3 * V_4 , void * V_31 ,
T_4 * V_6 , const T_5 * type )
{
int V_32 ;
T_6 * V_7 = F_2 () ;
if ( V_7 == NULL ) {
F_3 ( V_33 , V_17 ) ;
return 0 ;
}
if ( ! F_17 ( V_7 , NULL , type , NULL , V_6 ) ) {
F_14 ( V_7 ) ;
return 0 ;
}
V_32 = F_18 ( V_30 , V_2 , V_3 , V_4 , V_31 , V_7 ) ;
F_14 ( V_7 ) ;
return V_32 ;
}
int F_18 ( const T_7 * V_30 ,
T_2 * V_2 , T_2 * V_3 ,
T_3 * V_4 , void * V_31 , T_6 * V_7 )
{
const T_5 * type ;
T_4 * V_6 ;
unsigned char * V_9 = NULL , * V_10 = NULL ;
T_8 V_12 = 0 , V_13 = 0 , V_14 = 0 ;
int V_34 , V_35 ;
int V_32 ;
type = F_19 ( V_7 ) ;
V_6 = F_20 ( F_21 ( V_7 ) ) ;
if ( type == NULL || V_6 == NULL ) {
F_3 ( V_36 , V_37 ) ;
goto V_18;
}
if ( V_6 -> V_38 == NULL ) {
F_3 ( V_36 , V_39 ) ;
goto V_18;
}
if ( V_6 -> V_38 -> V_40 ) {
V_32 = V_6 -> V_38 -> V_40 ( V_7 , V_30 , V_31 , V_2 , V_3 , V_4 ) ;
if ( V_32 == 1 )
V_13 = V_4 -> V_25 ;
if ( V_32 <= 0 )
F_3 ( V_36 , V_27 ) ;
if ( V_32 <= 1 )
goto V_18;
} else
V_32 = 2 ;
if ( V_32 == 2 ) {
if ( ! F_22 ( & V_34 ,
F_23 ( type ) ,
V_6 -> V_38 -> V_41 ) ) {
F_3 ( V_36 ,
V_39 ) ;
goto V_18;
}
if ( V_6 -> V_38 -> V_42 & V_43 )
V_35 = V_22 ;
else
V_35 = V_44 ;
if ( V_2 )
F_24 ( V_2 , F_7 ( V_34 ) , V_35 , NULL ) ;
if ( V_3 )
F_24 ( V_3 , F_7 ( V_34 ) , V_35 , NULL ) ;
}
V_12 = F_25 ( V_31 , & V_9 , V_30 ) ;
V_14 = V_13 = F_9 ( V_6 ) ;
V_10 = F_8 ( ( unsigned int ) V_13 ) ;
if ( ( V_9 == NULL ) || ( V_10 == NULL ) ) {
V_13 = 0 ;
F_3 ( V_36 , V_17 ) ;
goto V_18;
}
if ( ! F_26 ( V_7 , V_9 , V_12 )
|| ! F_27 ( V_7 , V_10 , & V_13 ) ) {
V_13 = 0 ;
F_3 ( V_36 , V_27 ) ;
goto V_18;
}
F_13 ( V_4 -> V_5 ) ;
V_4 -> V_5 = V_10 ;
V_10 = NULL ;
V_4 -> V_25 = V_13 ;
V_4 -> V_28 &= ~ ( V_29 | 0x07 ) ;
V_4 -> V_28 |= V_29 ;
V_18:
F_15 ( ( char * ) V_9 , ( unsigned int ) V_12 ) ;
F_15 ( ( char * ) V_10 , V_14 ) ;
return ( V_13 ) ;
}
