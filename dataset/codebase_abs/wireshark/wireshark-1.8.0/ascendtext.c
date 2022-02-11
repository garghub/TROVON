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
if ( V_4 != V_13 || F_5 ( V_1 -> V_12 ) ) {
* V_2 = 0 ;
} else {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
}
return - 1 ;
V_18:
if ( F_6 ( V_1 -> V_12 , V_7 , V_19 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_20 . V_21 . type = type ;
return V_7 ;
}
int F_7 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_1 V_22 ;
T_6 V_23 ;
T_7 V_24 [ V_25 ] ;
T_8 V_26 ;
T_1 V_27 ;
T_9 * V_21 ;
V_1 -> V_28 = NULL ;
V_22 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_22 == - 1 ) {
if ( * V_2 == 0 )
return 0 ;
else
return - 1 ;
}
F_8 () ;
if ( F_9 ( V_1 -> V_12 , V_24 , & V_1 -> V_20 . V_21 , & V_26 ,
& V_27 ) != V_29 ) {
return 0 ;
}
V_1 -> V_30 = V_31 ;
switch( V_1 -> V_20 . V_21 . type ) {
case V_32 :
case V_33 :
V_1 -> V_34 = V_35 ;
break;
case V_36 :
V_1 -> V_34 = V_37 ;
break;
default:
V_1 -> V_34 = V_38 ;
}
V_1 -> V_39 = V_25 ;
V_1 -> V_40 = V_41 ;
V_1 -> V_42 = V_43 ;
V_21 = ( T_9 * ) F_10 ( sizeof( T_9 ) ) ;
V_1 -> V_28 = ( void * ) V_21 ;
V_21 -> V_44 = V_22 ;
if ( F_11 ( V_1 , & V_23 , V_2 ) == - 1 ) {
F_12 ( V_21 ) ;
return - 1 ;
}
V_21 -> V_45 = V_23 . V_46 ;
V_21 -> V_47 = 0 ;
V_1 -> V_48 = V_49 ;
F_8 () ;
return 1 ;
}
static void F_13 ( union V_50 * V_51 )
{
switch( V_51 -> V_21 . type ) {
case V_32 :
V_51 -> V_52 . V_53 = TRUE ;
V_51 -> V_52 . V_54 = 0 ;
break;
case V_33 :
V_51 -> V_52 . V_53 = FALSE ;
V_51 -> V_52 . V_54 = 0 ;
break;
case V_36 :
V_51 -> V_55 . V_56 = 0 ;
break;
}
}
static T_10 V_41 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_57 )
{
T_9 * V_21 = ( T_9 * ) V_1 -> V_28 ;
T_1 V_22 ;
T_7 * V_24 = F_14 ( V_1 -> V_58 ) ;
T_8 V_26 ;
if ( F_6 ( V_1 -> V_12 , V_21 -> V_44 ,
V_19 , V_2 ) == - 1 )
return FALSE ;
V_22 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_22 == - 1 )
return FALSE ;
if ( F_9 ( V_1 -> V_12 , V_24 , & V_1 -> V_20 . V_21 , & V_26 ,
& ( V_21 -> V_44 ) ) != V_29 ) {
* V_2 = V_59 ;
* V_3 = F_15 ( ( V_60 != NULL ) ? V_60 : L_1 ) ;
return FALSE ;
}
F_16 ( V_1 -> V_58 , V_1 -> V_39 ) ;
F_13 ( & V_1 -> V_20 ) ;
if ( ! V_21 -> V_47 ) {
V_21 -> V_47 = 1 ;
if ( V_26 . V_61 != 0 ) {
V_21 -> V_45 = V_26 . V_61 ;
}
if ( V_21 -> V_45 > V_26 . V_62 )
V_21 -> V_45 -= V_26 . V_62 ;
}
V_1 -> V_63 . V_64 = V_65 | V_66 ;
V_1 -> V_63 . V_67 . V_62 = V_26 . V_62 + V_21 -> V_45 ;
V_1 -> V_63 . V_67 . V_68 = V_26 . V_69 * 1000 ;
V_1 -> V_63 . V_70 = V_26 . V_70 ;
V_1 -> V_63 . V_16 = V_26 . V_16 ;
* V_57 = V_22 ;
return TRUE ;
}
static T_10 V_43 ( T_2 * V_1 , T_1 V_71 ,
union V_50 * V_51 , T_7 * V_72 , int V_16 V_73 ,
int * V_2 , T_3 * * V_3 )
{
T_9 * V_21 = ( T_9 * ) V_1 -> V_28 ;
if ( F_6 ( V_1 -> V_74 , V_71 , V_19 , V_2 ) == - 1 )
return FALSE ;
if ( F_9 ( V_1 -> V_74 , V_72 , & V_51 -> V_21 , NULL ,
& ( V_21 -> V_44 ) ) != V_29 ) {
* V_2 = V_59 ;
* V_3 = F_15 ( ( V_60 != NULL ) ? V_60 : L_1 ) ;
return FALSE ;
}
F_13 ( V_51 ) ;
return TRUE ;
}
