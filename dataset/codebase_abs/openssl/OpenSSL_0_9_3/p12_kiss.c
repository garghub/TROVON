int F_1 ( T_1 * V_1 , const char * V_2 , T_2 * * V_3 , T_3 * * V_4 ,
T_4 * * V_5 )
{
if( ! V_1 ) {
F_2 ( V_6 , V_7 ) ;
return 0 ;
}
if ( ( V_5 != NULL ) && ( * V_5 == NULL ) ) {
if ( ! ( * V_5 = F_3 ( NULL ) ) ) {
F_2 ( V_6 , V_8 ) ;
return 0 ;
}
}
if( V_3 ) * V_3 = NULL ;
if( V_4 ) * V_4 = NULL ;
if ( ! F_4 ( V_1 , V_2 , - 1 ) ) {
F_2 ( V_6 , V_9 ) ;
goto V_10;
}
if ( ! F_5 ( V_1 , V_2 , - 1 , V_3 , V_4 , V_5 ) ) {
F_2 ( V_6 , V_11 ) ;
goto V_10;
}
return 1 ;
V_10:
if ( V_3 && * V_3 ) F_6 ( * V_3 ) ;
if ( V_4 && * V_4 ) F_7 ( * V_4 ) ;
if ( V_5 ) F_8 ( * V_5 , F_7 ) ;
return 0 ;
}
static int F_5 ( T_1 * V_1 , const char * V_2 , int V_12 ,
T_2 * * V_3 , T_3 * * V_4 , T_4 * * V_5 )
{
T_4 * V_13 , * V_14 ;
int V_15 , V_16 ;
T_5 * V_17 ;
T_6 * V_18 = NULL ;
char V_19 = 0 ;
if ( ! ( V_13 = F_9 ( V_1 ) ) ) return 0 ;
for ( V_15 = 0 ; V_15 < F_10 ( V_13 ) ; V_15 ++ ) {
V_17 = ( T_5 * ) F_11 ( V_13 , V_15 ) ;
V_16 = F_12 ( V_17 -> type ) ;
if ( V_16 == V_20 ) {
V_14 = F_13 ( V_17 ) ;
} else if ( V_16 == V_21 ) {
V_14 = F_14 ( V_17 , V_2 , V_12 ) ;
} else continue;
if ( ! V_14 ) {
F_8 ( V_13 , V_22 ) ;
return 0 ;
}
if ( ! F_15 ( V_14 , V_2 , V_12 , V_3 , V_4 , V_5 ,
& V_18 , & V_19 ) ) {
F_8 ( V_14 , V_23 ) ;
F_8 ( V_13 , V_22 ) ;
return 0 ;
}
F_8 ( V_14 , V_23 ) ;
}
F_8 ( V_13 , V_22 ) ;
if ( V_18 ) F_16 ( V_18 ) ;
return 1 ;
}
static int F_15 ( T_4 * V_14 , const char * V_2 , int V_12 ,
T_2 * * V_3 , T_3 * * V_4 , T_4 * * V_5 ,
T_6 * * V_18 , char * V_19 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < F_10 ( V_14 ) ; V_15 ++ ) {
if ( ! F_17 ( ( V_24 * ) F_11 ( V_14 , V_15 ) ,
V_2 , V_12 , V_3 , V_4 , V_5 , V_18 ,
V_19 ) ) return 0 ;
}
return 1 ;
}
static int F_17 ( V_24 * V_25 , const char * V_2 , int V_12 ,
T_2 * * V_3 , T_3 * * V_4 , T_4 * * V_5 ,
T_6 * * V_18 ,
char * V_19 )
{
T_7 * V_26 ;
T_3 * V_27 ;
T_6 * V_28 = NULL ;
T_8 * V_29 ;
if ( ( V_29 = F_18 ( V_25 , V_30 ) ) )
V_28 = V_29 -> V_31 . V_32 ;
if ( V_28 && ( ( * V_19 & V_33 ) != V_33 ) ) {
if ( * V_18 ) {
if ( F_19 ( * V_18 , V_28 ) ) V_28 = NULL ;
} else {
if ( ! ( * V_18 = F_20 ( V_28 ) ) ) {
F_2 ( V_34 , V_8 ) ;
return 0 ;
}
}
}
switch ( F_21 ( V_25 ) )
{
case V_35 :
if ( ! V_28 || ! V_3 ) return 1 ;
if ( ! ( * V_3 = F_22 ( V_25 -> V_31 . V_36 ) ) ) return 0 ;
* V_19 |= V_37 ;
break;
case V_38 :
if ( ! V_28 || ! V_3 ) return 1 ;
if ( ! ( V_26 = F_23 ( V_25 , V_2 , V_12 ) ) )
return 0 ;
* V_3 = F_22 ( V_26 ) ;
F_24 ( V_26 ) ;
if ( ! ( * V_3 ) ) return 0 ;
* V_19 |= V_37 ;
break;
case V_39 :
if ( F_25 ( V_25 ) != V_40 )
return 1 ;
if ( ! ( V_27 = F_26 ( V_25 ) ) ) return 0 ;
if ( V_28 ) {
* V_19 |= V_41 ;
if ( V_4 ) * V_4 = V_27 ;
} else if ( V_5 ) F_27 ( * V_5 , ( char * ) V_27 ) ;
break;
case V_42 :
return F_15 ( V_25 -> V_31 . V_43 , V_2 , V_12 ,
V_3 , V_4 , V_5 , V_18 , V_19 ) ;
break;
default:
return 1 ;
break;
}
return 1 ;
}
