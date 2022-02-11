int F_1 ( int type , const unsigned char * V_1 , int V_2 ,
unsigned char * V_3 , unsigned int * V_4 ,
const T_1 * V_5 , const T_1 * V_6 , T_2 * V_7 )
{
T_3 * V_8 ;
F_2 ( V_1 , V_2 ) ;
V_8 = F_3 ( V_1 , V_2 , V_5 , V_6 , V_7 ) ;
if ( V_8 == NULL ) {
* V_4 = 0 ;
return 0 ;
}
* V_4 = F_4 ( V_8 , & V_3 ) ;
F_5 ( V_8 ) ;
return 1 ;
}
static int F_6 ( T_2 * V_7 , T_4 * V_9 ,
T_1 * * V_10 , T_1 * * V_11 ,
const unsigned char * V_1 , int V_2 )
{
T_4 * V_12 = NULL ;
T_1 * V_13 = NULL , * V_6 = NULL , * V_14 = NULL ;
const T_1 * V_15 ;
T_5 * V_16 = NULL ;
const T_6 * V_17 ;
int V_18 = 0 ;
if ( V_7 == NULL || ( V_17 = F_7 ( V_7 ) ) == NULL ) {
F_8 ( V_19 , V_20 ) ;
return 0 ;
}
if ( ! F_9 ( V_7 ) ) {
F_8 ( V_19 , V_21 ) ;
return 0 ;
}
if ( V_9 == NULL ) {
if ( ( V_12 = F_10 () ) == NULL ) {
F_8 ( V_19 , V_22 ) ;
return 0 ;
}
} else
V_12 = V_9 ;
V_13 = F_11 () ;
V_6 = F_11 () ;
V_14 = F_11 () ;
if ( V_13 == NULL || V_6 == NULL || V_14 == NULL ) {
F_8 ( V_19 , V_22 ) ;
goto V_23;
}
if ( ( V_16 = F_12 ( V_17 ) ) == NULL ) {
F_8 ( V_19 , V_24 ) ;
goto V_23;
}
V_15 = F_13 ( V_17 ) ;
if ( V_15 == NULL ) {
F_8 ( V_19 , V_24 ) ;
goto V_23;
}
do {
do
if ( V_1 != NULL ) {
if ( ! F_14
( V_13 , V_15 , F_15 ( V_7 ) , V_1 , V_2 ,
V_12 ) ) {
F_8 ( V_19 ,
V_25 ) ;
goto V_23;
}
} else {
if ( ! F_16 ( V_13 , V_15 ) ) {
F_8 ( V_19 ,
V_25 ) ;
goto V_23;
}
}
while ( F_17 ( V_13 ) );
if ( ! F_18 ( V_13 , V_13 , V_15 ) )
goto V_23;
if ( F_19 ( V_13 ) <= F_19 ( V_15 ) )
if ( ! F_18 ( V_13 , V_13 , V_15 ) )
goto V_23;
if ( ! F_20 ( V_17 , V_16 , V_13 , NULL , NULL , V_12 ) ) {
F_8 ( V_19 , V_24 ) ;
goto V_23;
}
if ( F_21 ( F_22 ( V_17 ) ) ==
V_26 ) {
if ( ! F_23
( V_17 , V_16 , V_14 , NULL , V_12 ) ) {
F_8 ( V_19 , V_24 ) ;
goto V_23;
}
}
#ifndef F_24
else {
if ( ! F_25 ( V_17 ,
V_16 , V_14 , NULL ,
V_12 ) ) {
F_8 ( V_19 , V_24 ) ;
goto V_23;
}
}
#endif
if ( ! F_26 ( V_6 , V_14 , V_15 , V_12 ) ) {
F_8 ( V_19 , V_27 ) ;
goto V_23;
}
}
while ( F_17 ( V_6 ) );
if ( F_27 ( V_17 ) != NULL ) {
if ( ! F_28 ( V_14 , 2 ) ) {
F_8 ( V_19 , V_27 ) ;
goto V_23;
}
if ( ! F_29 ( V_14 , V_15 , V_14 , V_15 , V_12 ) ) {
F_8 ( V_19 , V_27 ) ;
goto V_23;
}
F_30 ( V_14 , V_28 ) ;
if ( ! F_31
( V_13 , V_13 , V_14 , V_15 , V_12 , F_27 ( V_17 ) ) ) {
F_8 ( V_19 , V_27 ) ;
goto V_23;
}
} else {
if ( ! F_32 ( V_13 , V_13 , V_15 , V_12 ) ) {
F_8 ( V_19 , V_27 ) ;
goto V_23;
}
}
F_33 ( * V_11 ) ;
F_33 ( * V_10 ) ;
* V_11 = V_6 ;
* V_10 = V_13 ;
V_18 = 1 ;
V_23:
if ( ! V_18 ) {
F_33 ( V_13 ) ;
F_33 ( V_6 ) ;
}
if ( V_12 != V_9 )
F_34 ( V_12 ) ;
F_35 ( V_16 ) ;
F_33 ( V_14 ) ;
return ( V_18 ) ;
}
int F_36 ( T_2 * V_7 , T_4 * V_9 , T_1 * * V_10 ,
T_1 * * V_11 )
{
return F_6 ( V_7 , V_9 , V_10 , V_11 , NULL , 0 ) ;
}
T_3 * F_37 ( const unsigned char * V_1 , int V_29 ,
const T_1 * V_30 , const T_1 * V_31 ,
T_2 * V_7 )
{
int V_32 = 0 , V_33 ;
T_1 * V_5 = NULL , * V_8 , * V_34 = NULL , * V_35 = NULL ;
const T_1 * V_15 , * V_36 ;
T_4 * V_12 = NULL ;
const T_6 * V_17 ;
T_3 * V_18 ;
const T_1 * V_37 ;
V_17 = F_7 ( V_7 ) ;
V_37 = F_15 ( V_7 ) ;
if ( V_17 == NULL || V_37 == NULL ) {
F_8 ( V_38 , V_20 ) ;
return NULL ;
}
if ( ! F_9 ( V_7 ) ) {
F_8 ( V_38 , V_21 ) ;
return NULL ;
}
V_18 = F_38 () ;
if ( V_18 == NULL ) {
F_8 ( V_38 , V_22 ) ;
return NULL ;
}
V_18 -> V_6 = F_11 () ;
V_18 -> V_8 = F_11 () ;
if ( V_18 -> V_6 == NULL || V_18 -> V_8 == NULL ) {
F_8 ( V_38 , V_22 ) ;
goto V_23;
}
V_8 = V_18 -> V_8 ;
if ( ( V_12 = F_10 () ) == NULL ||
( V_35 = F_11 () ) == NULL || ( V_34 = F_11 () ) == NULL ) {
F_8 ( V_38 , V_22 ) ;
goto V_23;
}
V_15 = F_13 ( V_17 ) ;
if ( V_15 == NULL ) {
F_8 ( V_38 , V_24 ) ;
goto V_23;
}
V_33 = F_19 ( V_15 ) ;
if ( 8 * V_29 > V_33 )
V_29 = ( V_33 + 7 ) / 8 ;
if ( ! F_39 ( V_1 , V_29 , V_34 ) ) {
F_8 ( V_38 , V_27 ) ;
goto V_23;
}
if ( ( 8 * V_29 > V_33 ) && ! F_40 ( V_34 , V_34 , 8 - ( V_33 & 0x7 ) ) ) {
F_8 ( V_38 , V_27 ) ;
goto V_23;
}
do {
if ( V_30 == NULL || V_31 == NULL ) {
if ( ! F_6 ( V_7 , V_12 , & V_5 , & V_18 -> V_6 , V_1 , V_29 ) ) {
F_8 ( V_38 , V_39 ) ;
goto V_23;
}
V_36 = V_5 ;
} else {
V_36 = V_30 ;
if ( F_41 ( V_18 -> V_6 , V_31 ) == NULL ) {
F_8 ( V_38 , V_22 ) ;
goto V_23;
}
}
if ( ! F_42 ( V_35 , V_37 , V_18 -> V_6 , V_15 , V_12 ) ) {
F_8 ( V_38 , V_27 ) ;
goto V_23;
}
if ( ! F_43 ( V_8 , V_35 , V_34 , V_15 ) ) {
F_8 ( V_38 , V_27 ) ;
goto V_23;
}
if ( ! F_42 ( V_8 , V_8 , V_36 , V_15 , V_12 ) ) {
F_8 ( V_38 , V_27 ) ;
goto V_23;
}
if ( F_17 ( V_8 ) ) {
if ( V_30 != NULL && V_31 != NULL ) {
F_8 ( V_38 , V_40 ) ;
goto V_23;
}
} else
break;
}
while ( 1 );
V_32 = 1 ;
V_23:
if ( ! V_32 ) {
F_5 ( V_18 ) ;
V_18 = NULL ;
}
F_34 ( V_12 ) ;
F_33 ( V_34 ) ;
F_33 ( V_35 ) ;
F_33 ( V_5 ) ;
return V_18 ;
}
int F_44 ( int type , const unsigned char * V_1 , int V_29 ,
const unsigned char * V_41 , int V_42 , T_2 * V_7 )
{
T_3 * V_8 ;
const unsigned char * V_43 = V_41 ;
unsigned char * V_44 = NULL ;
int V_45 = - 1 ;
int V_18 = - 1 ;
V_8 = F_38 () ;
if ( V_8 == NULL )
return ( V_18 ) ;
if ( F_45 ( & V_8 , & V_43 , V_42 ) == NULL )
goto V_23;
V_45 = F_4 ( V_8 , & V_44 ) ;
if ( V_45 != V_42 || memcmp ( V_41 , V_44 , V_45 ) != 0 )
goto V_23;
V_18 = F_46 ( V_1 , V_29 , V_8 , V_7 ) ;
V_23:
F_47 ( V_44 , V_45 ) ;
F_5 ( V_8 ) ;
return ( V_18 ) ;
}
int F_48 ( const unsigned char * V_1 , int V_29 ,
const T_3 * V_3 , T_2 * V_7 )
{
int V_18 = - 1 , V_33 ;
T_4 * V_12 ;
const T_1 * V_15 ;
T_1 * V_46 , * V_47 , * V_34 , * V_14 ;
T_5 * V_48 = NULL ;
const T_6 * V_17 ;
const T_5 * V_49 ;
if ( V_7 == NULL || ( V_17 = F_7 ( V_7 ) ) == NULL ||
( V_49 = F_49 ( V_7 ) ) == NULL || V_3 == NULL ) {
F_8 ( V_50 , V_51 ) ;
return - 1 ;
}
if ( ! F_9 ( V_7 ) ) {
F_8 ( V_50 , V_21 ) ;
return - 1 ;
}
V_12 = F_10 () ;
if ( V_12 == NULL ) {
F_8 ( V_50 , V_22 ) ;
return - 1 ;
}
F_50 ( V_12 ) ;
V_46 = F_51 ( V_12 ) ;
V_47 = F_51 ( V_12 ) ;
V_34 = F_51 ( V_12 ) ;
V_14 = F_51 ( V_12 ) ;
if ( V_14 == NULL ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
V_15 = F_13 ( V_17 ) ;
if ( V_15 == NULL ) {
F_8 ( V_50 , V_24 ) ;
goto V_23;
}
if ( F_17 ( V_3 -> V_6 ) || F_52 ( V_3 -> V_6 ) ||
F_53 ( V_3 -> V_6 , V_15 ) >= 0 || F_17 ( V_3 -> V_8 ) ||
F_52 ( V_3 -> V_8 ) || F_53 ( V_3 -> V_8 , V_15 ) >= 0 ) {
F_8 ( V_50 , V_52 ) ;
V_18 = 0 ;
goto V_23;
}
if ( ! F_32 ( V_47 , V_3 -> V_8 , V_15 , V_12 ) ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
V_33 = F_19 ( V_15 ) ;
if ( 8 * V_29 > V_33 )
V_29 = ( V_33 + 7 ) / 8 ;
if ( ! F_39 ( V_1 , V_29 , V_34 ) ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
if ( ( 8 * V_29 > V_33 ) && ! F_40 ( V_34 , V_34 , 8 - ( V_33 & 0x7 ) ) ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
if ( ! F_42 ( V_46 , V_34 , V_47 , V_15 , V_12 ) ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
if ( ! F_42 ( V_47 , V_3 -> V_6 , V_47 , V_15 , V_12 ) ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
if ( ( V_48 = F_12 ( V_17 ) ) == NULL ) {
F_8 ( V_50 , V_22 ) ;
goto V_23;
}
if ( ! F_20 ( V_17 , V_48 , V_46 , V_49 , V_47 , V_12 ) ) {
F_8 ( V_50 , V_24 ) ;
goto V_23;
}
if ( F_21 ( F_22 ( V_17 ) ) ==
V_26 ) {
if ( ! F_23 ( V_17 , V_48 , V_14 , NULL , V_12 ) ) {
F_8 ( V_50 , V_24 ) ;
goto V_23;
}
}
#ifndef F_24
else {
if ( ! F_25 ( V_17 , V_48 , V_14 , NULL , V_12 ) ) {
F_8 ( V_50 , V_24 ) ;
goto V_23;
}
}
#endif
if ( ! F_26 ( V_46 , V_14 , V_15 , V_12 ) ) {
F_8 ( V_50 , V_27 ) ;
goto V_23;
}
V_18 = ( F_53 ( V_46 , V_3 -> V_6 ) == 0 ) ;
V_23:
F_54 ( V_12 ) ;
F_34 ( V_12 ) ;
F_35 ( V_48 ) ;
return V_18 ;
}
