static T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_4 ;
T_1 V_5 = - 1 , V_6 , V_7 ;
T_4 V_8 [ V_9 ] ;
T_5 V_10 = 0 , type = 0 ;
T_5 V_11 = 262144 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
while ( ( ( V_4 = F_2 ( V_1 -> V_12 ) ) != V_13 ) ) {
V_11 -- ;
if ( ! V_11 ) {
* V_2 = 0 ;
return - 1 ;
}
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
const T_3 * V_14 = V_15 [ V_10 ] . V_14 ;
T_4 V_16 = strlen ( V_14 ) ;
if ( V_4 == * ( V_14 + V_8 [ V_10 ] ) ) {
V_8 [ V_10 ] ++ ;
if ( V_8 [ V_10 ] >= V_16 ) {
V_6 = F_3 ( V_1 -> V_12 ) ;
if ( V_6 == - 1 ) {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
return - 1 ;
}
if ( strcmp ( V_14 , V_17 ) == 0 ) {
V_5 = V_6 - V_16 ;
} else {
if ( V_5 == - 1 ) {
V_7 = V_6 - V_16 ;
} else {
V_7 = V_5 ;
}
type = V_15 [ V_10 ] . type ;
goto V_18;
}
}
} else {
V_8 [ V_10 ] = 0 ;
}
}
}
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
return - 1 ;
V_18:
if ( F_5 ( V_1 -> V_12 , V_7 , V_19 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_20 . V_21 . V_22 . type = type ;
return V_7 ;
}
int F_6 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_1 V_23 ;
T_6 V_24 ;
T_7 * V_22 ;
V_1 -> V_25 = NULL ;
V_23 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_23 == - 1 ) {
if ( * V_2 != 0 && * V_2 != V_26 )
return - 1 ;
return 0 ;
}
F_7 () ;
if ( ! F_8 ( V_1 -> V_12 , & V_1 -> V_20 ) ) {
return 0 ;
}
V_1 -> V_27 = V_28 ;
switch( V_1 -> V_20 . V_21 . V_22 . type ) {
case V_29 :
case V_30 :
V_1 -> V_31 = V_32 ;
break;
case V_33 :
V_1 -> V_31 = V_34 ;
break;
default:
V_1 -> V_31 = V_35 ;
}
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
V_1 -> V_40 = V_41 ;
V_22 = ( T_7 * ) F_9 ( sizeof( T_7 ) ) ;
V_1 -> V_25 = ( void * ) V_22 ;
V_22 -> V_42 = V_23 ;
if ( F_10 ( V_1 , & V_24 , V_2 ) == - 1 ) {
return - 1 ;
}
V_22 -> V_43 = V_24 . V_44 ;
V_22 -> V_45 = FALSE ;
V_1 -> V_46 = V_47 ;
F_7 () ;
return 1 ;
}
static T_8 V_39 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_48 )
{
T_7 * V_22 = ( T_7 * ) V_1 -> V_25 ;
T_1 V_23 ;
if ( F_5 ( V_1 -> V_12 , V_22 -> V_42 ,
V_19 , V_2 ) == - 1 )
return FALSE ;
V_23 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_23 == - 1 )
return FALSE ;
if ( F_11 ( V_22 , V_1 -> V_12 , & V_1 -> V_20 , V_1 -> V_49 ,
V_1 -> V_36 ) != V_50 ) {
* V_2 = V_51 ;
* V_3 = F_12 ( ( V_52 != NULL ) ? V_52 : L_1 ) ;
return FALSE ;
}
* V_48 = V_23 ;
return TRUE ;
}
static T_8 V_41 ( T_2 * V_1 , T_1 V_53 ,
struct V_54 * V_20 , T_9 * V_55 , int V_16 V_56 ,
int * V_2 , T_3 * * V_3 )
{
T_7 * V_22 = ( T_7 * ) V_1 -> V_25 ;
if ( F_5 ( V_1 -> V_57 , V_53 , V_19 , V_2 ) == - 1 )
return FALSE ;
if ( F_11 ( V_22 , V_1 -> V_57 , V_20 , V_55 ,
V_1 -> V_36 ) != V_50 ) {
* V_2 = V_51 ;
* V_3 = F_12 ( ( V_52 != NULL ) ? V_52 : L_1 ) ;
return FALSE ;
}
return TRUE ;
}
