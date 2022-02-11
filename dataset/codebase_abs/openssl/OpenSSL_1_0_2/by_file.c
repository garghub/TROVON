T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( T_2 * V_2 , int V_3 , const char * V_4 ,
long V_5 , char * * V_6 )
{
int V_7 = 0 ;
char * V_8 ;
switch ( V_3 ) {
case V_9 :
if ( V_5 == V_10 ) {
V_8 = ( char * ) getenv ( F_3 () ) ;
if ( V_8 )
V_7 = ( F_4 ( V_2 , V_8 ,
V_11 ) != 0 ) ;
else
V_7 = ( F_4
( V_2 , F_5 () ,
V_11 ) != 0 ) ;
if ( ! V_7 ) {
F_6 ( V_12 , V_13 ) ;
}
} else {
if ( V_5 == V_11 )
V_7 = ( F_4 ( V_2 , V_4 ,
V_11 ) != 0 ) ;
else
V_7 = ( F_7 ( V_2 , V_4 , ( int ) V_5 ) != 0 ) ;
}
break;
}
return ( V_7 ) ;
}
int F_7 ( T_2 * V_2 , const char * V_8 , int type )
{
int V_6 = 0 ;
T_3 * V_14 = NULL ;
int V_15 , V_16 = 0 ;
T_4 * V_17 = NULL ;
if ( V_8 == NULL )
return ( 1 ) ;
V_14 = F_8 ( F_9 () ) ;
if ( ( V_14 == NULL ) || ( F_10 ( V_14 , V_8 ) <= 0 ) ) {
F_6 ( V_18 , V_19 ) ;
goto V_20;
}
if ( type == V_11 ) {
for (; ; ) {
V_17 = F_11 ( V_14 , NULL , NULL , NULL ) ;
if ( V_17 == NULL ) {
if ( ( F_12 ( F_13 () ) ==
V_21 ) && ( V_16 > 0 ) ) {
F_14 () ;
break;
} else {
F_6 ( V_18 , V_22 ) ;
goto V_20;
}
}
V_15 = F_15 ( V_2 -> V_23 , V_17 ) ;
if ( ! V_15 )
goto V_20;
V_16 ++ ;
F_16 ( V_17 ) ;
V_17 = NULL ;
}
V_6 = V_16 ;
} else if ( type == V_24 ) {
V_17 = F_17 ( V_14 , NULL ) ;
if ( V_17 == NULL ) {
F_6 ( V_18 , V_25 ) ;
goto V_20;
}
V_15 = F_15 ( V_2 -> V_23 , V_17 ) ;
if ( ! V_15 )
goto V_20;
V_6 = V_15 ;
} else {
F_6 ( V_18 , V_26 ) ;
goto V_20;
}
V_20:
if ( V_17 != NULL )
F_16 ( V_17 ) ;
if ( V_14 != NULL )
F_18 ( V_14 ) ;
return ( V_6 ) ;
}
int F_19 ( T_2 * V_2 , const char * V_8 , int type )
{
int V_6 = 0 ;
T_3 * V_14 = NULL ;
int V_15 , V_16 = 0 ;
T_5 * V_17 = NULL ;
if ( V_8 == NULL )
return ( 1 ) ;
V_14 = F_8 ( F_9 () ) ;
if ( ( V_14 == NULL ) || ( F_10 ( V_14 , V_8 ) <= 0 ) ) {
F_6 ( V_27 , V_19 ) ;
goto V_20;
}
if ( type == V_11 ) {
for (; ; ) {
V_17 = F_20 ( V_14 , NULL , NULL , NULL ) ;
if ( V_17 == NULL ) {
if ( ( F_12 ( F_13 () ) ==
V_21 ) && ( V_16 > 0 ) ) {
F_14 () ;
break;
} else {
F_6 ( V_27 , V_22 ) ;
goto V_20;
}
}
V_15 = F_21 ( V_2 -> V_23 , V_17 ) ;
if ( ! V_15 )
goto V_20;
V_16 ++ ;
F_22 ( V_17 ) ;
V_17 = NULL ;
}
V_6 = V_16 ;
} else if ( type == V_24 ) {
V_17 = F_23 ( V_14 , NULL ) ;
if ( V_17 == NULL ) {
F_6 ( V_27 , V_25 ) ;
goto V_20;
}
V_15 = F_21 ( V_2 -> V_23 , V_17 ) ;
if ( ! V_15 )
goto V_20;
V_6 = V_15 ;
} else {
F_6 ( V_27 , V_26 ) ;
goto V_20;
}
V_20:
if ( V_17 != NULL )
F_22 ( V_17 ) ;
if ( V_14 != NULL )
F_18 ( V_14 ) ;
return ( V_6 ) ;
}
int F_4 ( T_2 * V_2 , const char * V_8 , int type )
{
F_24 ( V_28 ) * V_29 ;
V_28 * V_30 ;
T_3 * V_14 ;
int V_15 , V_16 = 0 ;
if ( type != V_11 )
return F_7 ( V_2 , V_8 , type ) ;
V_14 = F_25 ( V_8 , L_1 ) ;
if ( ! V_14 ) {
F_6 ( V_31 , V_19 ) ;
return 0 ;
}
V_29 = F_26 ( V_14 , NULL , NULL , NULL ) ;
F_18 ( V_14 ) ;
if ( ! V_29 ) {
F_6 ( V_31 , V_22 ) ;
return 0 ;
}
for ( V_15 = 0 ; V_15 < F_27 ( V_29 ) ; V_15 ++ ) {
V_30 = F_28 ( V_29 , V_15 ) ;
if ( V_30 -> V_32 ) {
F_15 ( V_2 -> V_23 , V_30 -> V_32 ) ;
V_16 ++ ;
}
if ( V_30 -> V_33 ) {
F_21 ( V_2 -> V_23 , V_30 -> V_33 ) ;
V_16 ++ ;
}
}
F_29 ( V_29 , V_34 ) ;
return V_16 ;
}
