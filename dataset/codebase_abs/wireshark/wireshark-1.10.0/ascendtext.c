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
T_7 V_25 [ V_26 ] ;
T_8 V_27 ;
T_1 V_28 ;
T_9 * V_22 ;
V_1 -> V_29 = NULL ;
V_23 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_23 == - 1 ) {
if ( * V_2 != 0 && * V_2 != V_30 )
return - 1 ;
return 0 ;
}
F_7 () ;
if ( F_8 ( V_1 -> V_12 , V_25 , & V_1 -> V_20 . V_21 . V_22 , & V_27 ,
& V_28 ) != V_31 ) {
return 0 ;
}
V_1 -> V_32 = V_33 ;
switch( V_1 -> V_20 . V_21 . V_22 . type ) {
case V_34 :
case V_35 :
V_1 -> V_36 = V_37 ;
break;
case V_38 :
V_1 -> V_36 = V_39 ;
break;
default:
V_1 -> V_36 = V_40 ;
}
V_1 -> V_41 = V_26 ;
V_1 -> V_42 = V_43 ;
V_1 -> V_44 = V_45 ;
V_22 = ( T_9 * ) F_9 ( sizeof( T_9 ) ) ;
V_1 -> V_29 = ( void * ) V_22 ;
V_22 -> V_46 = V_23 ;
if ( F_10 ( V_1 , & V_24 , V_2 ) == - 1 ) {
return - 1 ;
}
V_22 -> V_47 = V_24 . V_48 ;
V_22 -> V_49 = 0 ;
V_1 -> V_50 = V_51 ;
F_7 () ;
return 1 ;
}
static void F_11 ( union V_52 * V_53 )
{
switch( V_53 -> V_22 . type ) {
case V_34 :
V_53 -> V_54 . V_55 = TRUE ;
V_53 -> V_54 . V_56 = 0 ;
break;
case V_35 :
V_53 -> V_54 . V_55 = FALSE ;
V_53 -> V_54 . V_56 = 0 ;
break;
case V_38 :
V_53 -> V_57 . V_58 = 0 ;
break;
}
}
static T_10 V_43 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_59 )
{
T_9 * V_22 = ( T_9 * ) V_1 -> V_29 ;
T_1 V_23 ;
T_7 * V_25 = F_12 ( V_1 -> V_60 ) ;
T_8 V_27 ;
if ( F_5 ( V_1 -> V_12 , V_22 -> V_46 ,
V_19 , V_2 ) == - 1 )
return FALSE ;
V_23 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_23 == - 1 )
return FALSE ;
if ( F_8 ( V_1 -> V_12 , V_25 , & V_1 -> V_20 . V_21 . V_22 , & V_27 ,
& ( V_22 -> V_46 ) ) != V_31 ) {
* V_2 = V_61 ;
* V_3 = F_13 ( ( V_62 != NULL ) ? V_62 : L_1 ) ;
return FALSE ;
}
F_14 ( V_1 -> V_60 , V_1 -> V_41 ) ;
F_11 ( & V_1 -> V_20 . V_21 ) ;
if ( ! V_22 -> V_49 ) {
V_22 -> V_49 = 1 ;
if ( V_27 . V_63 != 0 ) {
V_22 -> V_47 = V_27 . V_63 ;
}
if ( V_22 -> V_47 > V_27 . V_64 )
V_22 -> V_47 -= V_27 . V_64 ;
}
V_1 -> V_20 . V_65 = V_66 | V_67 ;
V_1 -> V_20 . V_68 . V_64 = V_27 . V_64 + V_22 -> V_47 ;
V_1 -> V_20 . V_68 . V_69 = V_27 . V_70 * 1000 ;
V_1 -> V_20 . V_71 = V_27 . V_71 ;
V_1 -> V_20 . V_16 = V_27 . V_16 ;
* V_59 = V_23 ;
return TRUE ;
}
static T_10 V_45 ( T_2 * V_1 , T_1 V_72 ,
struct V_73 * V_20 , T_7 * V_74 , int V_16 V_75 ,
int * V_2 , T_3 * * V_3 )
{
union V_52 * V_53 = & V_20 -> V_21 ;
T_9 * V_22 = ( T_9 * ) V_1 -> V_29 ;
if ( F_5 ( V_1 -> V_76 , V_72 , V_19 , V_2 ) == - 1 )
return FALSE ;
if ( F_8 ( V_1 -> V_76 , V_74 , & V_53 -> V_22 , NULL ,
& ( V_22 -> V_46 ) ) != V_31 ) {
* V_2 = V_61 ;
* V_3 = F_13 ( ( V_62 != NULL ) ? V_62 : L_1 ) ;
return FALSE ;
}
F_11 ( V_53 ) ;
return TRUE ;
}
