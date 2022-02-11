T_1 * F_1 ( void )
{
T_1 * V_1 = F_2 ( sizeof( * V_1 ) ) ;
if ( V_1 == NULL )
F_3 ( V_2 , V_3 ) ;
return V_1 ;
}
void F_4 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return;
F_5 ( V_1 -> V_4 ) ;
F_6 ( V_1 -> V_5 ) ;
F_6 ( V_1 -> V_6 ) ;
F_6 ( V_1 -> V_7 ) ;
F_6 ( V_1 -> V_8 ) ;
F_6 ( V_1 ) ;
}
static int F_7 ( T_2 * V_9 , int V_10 , int * V_11 )
{
int V_12 = F_8 ( V_9 , V_10 , - 1 ) ;
if ( V_11 != NULL )
* V_11 = V_12 >= 0 && F_8 ( V_9 , V_10 , V_12 ) >= 0 ;
return V_12 ;
}
T_3 static int F_9 ( T_2 * V_9 , T_2 * V_13 )
{
int V_14 , V_15 ;
int V_16 , V_17 ;
if ( V_13 == NULL )
return 1 ;
V_14 = F_7 ( V_13 , V_18 ,
& V_16 ) ;
V_15 = F_7 ( V_9 , V_18 ,
& V_17 ) ;
if ( V_14 < - 1 || V_15 < - 1 )
return 0 ;
if ( V_16 || V_17 )
return 0 ;
if ( V_14 >= 0 && V_15 == - 1 )
return 0 ;
if ( V_14 == - 1 && V_15 >= 0 )
return 0 ;
if ( ! F_10 ( V_9 , F_11 ( V_13 ) ) )
return 0 ;
if ( V_14 != - 1 ) {
T_4 * V_19 = F_12 ( V_13 , V_14 ) ;
T_4 * V_20 = F_12 ( V_9 , V_15 ) ;
T_5 * V_21 ;
if ( V_19 == NULL || V_20 == NULL )
return 0 ;
V_21 = F_13 ( V_19 ) ;
if ( V_21 == NULL ||
! F_14 ( V_20 , V_21 ) )
return 0 ;
}
return 1 ;
}
int F_15 ( T_1 * V_1 , T_2 * V_9 , T_2 * V_13 )
{
unsigned char * V_7 = NULL , * V_8 = NULL ;
T_2 * V_22 = NULL ;
int V_23 = 0 , V_24 = 0 ;
int V_25 = - 1 ;
int V_26 , V_27 ;
int V_28 = F_7 ( V_9 , V_29 , & V_26 ) ;
if ( V_26 )
goto V_30;
if ( V_28 == - 1 ) {
if ( V_13 != NULL )
goto V_30;
V_23 = F_16 ( V_9 , & V_7 ) ;
if ( V_23 < 0 )
goto V_30;
}
V_25 = F_7 ( V_9 , V_31 , & V_27 ) ;
if ( V_27 )
goto V_30;
if ( V_25 >= 0 && V_28 >= 0 ) {
goto V_30;
}
if ( V_25 == - 1 ) {
V_25 = V_28 ;
}
if ( V_25 >= 0 ) {
T_4 * V_32 ;
V_22 = F_17 ( V_9 ) ;
if ( V_22 == NULL )
goto V_30;
V_32 = F_18 ( V_22 , V_25 ) ;
F_19 ( V_32 ) ;
if ( ! F_9 ( V_22 , V_13 ) )
goto V_30;
V_24 = F_20 ( V_22 , & V_8 ) ;
if ( V_24 <= 0 )
goto V_30;
}
F_21 ( V_22 ) ;
F_6 ( V_1 -> V_7 ) ;
V_1 -> V_7 = V_7 ;
V_1 -> V_23 = V_23 ;
F_6 ( V_1 -> V_8 ) ;
V_1 -> V_8 = V_8 ;
V_1 -> V_24 = V_24 ;
return 1 ;
V_30:
F_6 ( V_7 ) ;
F_6 ( V_8 ) ;
F_21 ( V_22 ) ;
return 0 ;
}
T_3 static int F_22 ( T_6 * V_4 , unsigned char * * V_33 ,
T_7 * V_34 )
{
int V_12 = 0 ;
unsigned char * V_35 = NULL , * V_36 = NULL ;
int V_37 ;
unsigned int V_38 ;
if ( * V_33 != NULL && * V_34 >= V_39 ) {
V_35 = * V_33 ;
} else {
V_35 = F_23 ( V_39 ) ;
if ( V_35 == NULL )
goto V_30;
}
V_37 = F_24 ( V_4 , & V_36 ) ;
if ( V_37 <= 0 )
goto V_30;
if ( ! F_25 ( V_36 , V_37 , V_35 , & V_38 , F_26 () , NULL ) )
goto V_30;
if ( V_35 != * V_33 ) {
F_6 ( * V_33 ) ;
* V_33 = V_35 ;
* V_34 = V_39 ;
}
V_35 = NULL ;
V_12 = 1 ;
V_30:
F_6 ( V_35 ) ;
F_6 ( V_36 ) ;
return V_12 ;
}
int F_27 ( T_1 * V_1 , const T_2 * V_40 )
{
return F_28 ( V_1 , F_29 ( V_40 ) ) ;
}
int F_28 ( T_1 * V_1 , T_6 * V_41 )
{
return F_22 ( V_41 , & V_1 -> V_6 , & V_1 -> V_42 ) ;
}
int F_30 ( T_1 * V_1 , T_6 * V_41 )
{
T_8 * V_4 = F_31 ( V_41 ) ;
if ( V_4 == NULL )
return 0 ;
if ( ! F_22 ( V_41 , & V_1 -> V_5 , & V_1 -> V_43 ) ) {
F_5 ( V_4 ) ;
return 0 ;
}
F_5 ( V_1 -> V_4 ) ;
V_1 -> V_4 = V_4 ;
return 1 ;
}
