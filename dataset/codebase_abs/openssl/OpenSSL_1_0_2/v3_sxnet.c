int F_1 ( T_1 * * V_1 , char * V_2 , char * V_3 , int V_4 )
{
T_2 * V_5 = NULL ;
if ( ! ( V_5 = F_2 ( NULL , V_2 ) ) ) {
F_3 ( V_6 , V_7 ) ;
return 0 ;
}
return F_4 ( V_1 , V_5 , V_3 , V_4 ) ;
}
int F_5 ( T_1 * * V_1 , unsigned long V_8 , char * V_3 ,
int V_4 )
{
T_2 * V_5 = NULL ;
if ( ! ( V_5 = F_6 () ) || ! F_7 ( V_5 , V_8 ) ) {
F_3 ( V_9 , V_10 ) ;
F_8 ( V_5 ) ;
return 0 ;
}
return F_4 ( V_1 , V_5 , V_3 , V_4 ) ;
}
int F_4 ( T_1 * * V_1 , T_2 * V_2 , char * V_3 ,
int V_4 )
{
T_1 * V_11 = NULL ;
T_3 * V_12 = NULL ;
if ( ! V_1 || ! V_2 || ! V_3 ) {
F_3 ( V_13 ,
V_14 ) ;
return 0 ;
}
if ( V_4 == - 1 )
V_4 = strlen ( V_3 ) ;
if ( V_4 > 64 ) {
F_3 ( V_13 , V_15 ) ;
return 0 ;
}
if ( ! * V_1 ) {
if ( ! ( V_11 = F_9 () ) )
goto V_16;
if ( ! F_7 ( V_11 -> V_17 , 0 ) )
goto V_16;
* V_1 = V_11 ;
} else
V_11 = * V_1 ;
if ( F_10 ( V_11 , V_2 ) ) {
F_3 ( V_13 , V_18 ) ;
return 0 ;
}
if ( ! ( V_12 = F_11 () ) )
goto V_16;
if ( V_4 == - 1 )
V_4 = strlen ( V_3 ) ;
if ( ! F_12 ( V_12 -> V_3 , V_3 , V_4 ) )
goto V_16;
if ( ! F_13 ( V_11 -> V_19 , V_12 ) )
goto V_16;
V_12 -> V_2 = V_2 ;
return 1 ;
V_16:
F_3 ( V_13 , V_10 ) ;
F_14 ( V_12 ) ;
F_15 ( V_11 ) ;
* V_1 = NULL ;
return 0 ;
}
T_4 * F_16 ( T_1 * V_11 , char * V_2 )
{
T_2 * V_5 = NULL ;
T_4 * V_20 ;
if ( ! ( V_5 = F_2 ( NULL , V_2 ) ) ) {
F_3 ( V_21 , V_7 ) ;
return NULL ;
}
V_20 = F_10 ( V_11 , V_5 ) ;
F_8 ( V_5 ) ;
return V_20 ;
}
T_4 * F_17 ( T_1 * V_11 , unsigned long V_8 )
{
T_2 * V_5 = NULL ;
T_4 * V_20 ;
if ( ! ( V_5 = F_6 () ) || ! F_7 ( V_5 , V_8 ) ) {
F_3 ( V_22 , V_10 ) ;
F_8 ( V_5 ) ;
return NULL ;
}
V_20 = F_10 ( V_11 , V_5 ) ;
F_8 ( V_5 ) ;
return V_20 ;
}
T_4 * F_10 ( T_1 * V_11 , T_2 * V_2 )
{
T_3 * V_12 ;
int V_23 ;
for ( V_23 = 0 ; V_23 < F_18 ( V_11 -> V_19 ) ; V_23 ++ ) {
V_12 = F_19 ( V_11 -> V_19 , V_23 ) ;
if ( ! F_20 ( V_12 -> V_2 , V_2 ) )
return V_12 -> V_3 ;
}
return NULL ;
}
