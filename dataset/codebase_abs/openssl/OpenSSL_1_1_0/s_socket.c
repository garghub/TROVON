int F_1 ( int * V_1 , const char * V_2 , const char * V_3 ,
int V_4 , int type )
{
T_1 * V_5 = NULL ;
const T_1 * V_6 = NULL ;
int V_7 ;
if ( ! F_2 () )
return 0 ;
V_7 = F_3 ( V_2 , V_3 , V_8 , V_4 , type , & V_5 ) ;
if ( V_7 == 0 ) {
F_4 ( V_9 ) ;
return 0 ;
}
V_7 = 0 ;
for ( V_6 = V_5 ; V_6 != NULL ; V_6 = F_5 ( V_6 ) ) {
F_6 ( ( V_4 == V_10 || V_4 == F_7 ( V_5 ) )
&& ( type == 0 || type == F_8 ( V_5 ) ) ) ;
* V_1 = F_9 ( F_7 ( V_6 ) , F_8 ( V_6 ) ,
F_10 ( V_5 ) , 0 ) ;
if ( * V_1 == V_11 ) {
continue;
}
if ( ! F_11 ( * V_1 , F_12 ( V_6 ) , 0 ) ) {
F_13 ( * V_1 ) ;
* V_1 = V_11 ;
continue;
}
break;
}
if ( * V_1 == V_11 ) {
F_4 ( V_9 ) ;
} else {
F_14 () ;
V_7 = 1 ;
}
F_15 ( V_5 ) ;
return V_7 ;
}
int F_16 ( int * V_12 , const char * V_2 , const char * V_3 ,
int V_4 , int type , T_2 V_13 ,
unsigned char * V_14 , int V_15 )
{
int V_16 = 0 ;
int V_1 ;
int V_17 ;
T_1 * V_5 = NULL ;
int V_7 = 0 ;
if ( ! F_2 () )
return 0 ;
if ( ! F_3 ( V_2 , V_3 , V_18 , V_4 , type , & V_5 ) ) {
F_4 ( V_9 ) ;
return 0 ;
}
F_6 ( ( V_4 == V_10 || V_4 == F_7 ( V_5 ) )
&& ( type == 0 || type == F_8 ( V_5 ) ) ) ;
V_16 = F_9 ( F_7 ( V_5 ) , F_8 ( V_5 ) ,
F_10 ( V_5 ) , 0 ) ;
if ( V_16 == V_11
|| ! F_17 ( V_16 , F_12 ( V_5 ) , V_19 ) ) {
F_15 ( V_5 ) ;
F_4 ( V_9 ) ;
if ( V_16 != V_11 )
F_13 ( V_16 ) ;
goto V_20;
}
F_15 ( V_5 ) ;
V_5 = NULL ;
if ( V_12 != NULL )
* V_12 = V_16 ;
for (; ; ) {
if ( type == V_21 ) {
do {
V_1 = F_18 ( V_16 , NULL , 0 ) ;
} while ( V_1 < 0 && F_19 ( V_7 ) );
if ( V_1 < 0 ) {
F_4 ( V_9 ) ;
F_13 ( V_16 ) ;
break;
}
V_17 = (* V_13)( V_1 , type , V_14 ) ;
F_13 ( V_1 ) ;
} else {
V_17 = (* V_13)( V_16 , type , V_14 ) ;
}
if ( V_15 != - 1 )
V_15 -- ;
if ( V_17 < 0 || V_15 == 0 ) {
F_13 ( V_16 ) ;
V_7 = V_17 ;
break;
}
}
V_20:
# ifdef F_20
if ( V_4 == F_20 )
F_21 ( V_2 ) ;
# endif
return V_7 ;
}
