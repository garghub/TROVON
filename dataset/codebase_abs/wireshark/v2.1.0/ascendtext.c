static T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
int V_4 ;
T_1 V_5 = - 1 , V_6 , V_7 ;
T_4 V_8 [ V_9 ] ;
T_5 V_10 = 0 , type = 0 ;
static const T_3 V_11 [] = V_12 ;
T_4 V_13 = sizeof V_11 - 1 ;
T_4 V_14 ;
T_5 V_15 = 262144 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_14 = 0 ;
while ( ( ( V_4 = F_2 ( V_1 -> V_16 ) ) != V_17 ) ) {
V_15 -- ;
if ( ! V_15 ) {
* V_2 = 0 ;
return - 1 ;
}
for ( V_10 = 0 ; V_10 < V_9 ; V_10 ++ ) {
const T_3 * V_18 = V_19 [ V_10 ] . V_18 ;
T_4 V_20 = V_19 [ V_10 ] . V_21 ;
if ( V_4 == * ( V_18 + V_8 [ V_10 ] ) ) {
V_8 [ V_10 ] ++ ;
if ( V_8 [ V_10 ] >= V_20 ) {
V_6 = F_3 ( V_1 -> V_16 ) ;
if ( V_6 == - 1 ) {
* V_2 = F_4 ( V_1 -> V_16 , V_3 ) ;
return - 1 ;
}
if ( V_5 == - 1 ) {
V_7 = V_6 - V_20 ;
} else {
V_7 = V_5 ;
}
type = V_19 [ V_10 ] . type ;
goto V_22;
}
} else {
V_8 [ V_10 ] = 0 ;
}
}
if ( V_4 == * ( V_11 + V_14 ) ) {
V_14 ++ ;
if ( V_14 >= V_13 ) {
V_6 = F_3 ( V_1 -> V_16 ) ;
if ( V_6 == - 1 ) {
* V_2 = F_4 ( V_1 -> V_16 , V_3 ) ;
return - 1 ;
}
V_5 = V_6 - V_13 ;
V_14 = 0 ;
}
} else {
V_14 = 0 ;
}
}
* V_2 = F_4 ( V_1 -> V_16 , V_3 ) ;
return - 1 ;
V_22:
if ( F_5 ( V_1 -> V_16 , V_7 , V_23 , V_2 ) == - 1 )
return - 1 ;
V_1 -> V_24 . V_25 . V_26 . type = type ;
return V_7 ;
}
T_6 F_6 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_1 V_27 ;
T_7 V_28 [ V_29 ] ;
T_8 V_30 ;
T_9 V_31 ;
T_10 * V_26 ;
V_1 -> V_32 = NULL ;
V_27 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_27 == - 1 ) {
if ( * V_2 != 0 && * V_2 != V_33 )
return V_34 ;
return V_35 ;
}
if ( F_7 ( V_1 -> V_16 , & V_1 -> V_24 , V_28 , & V_30 , V_2 , V_3 ) != 0 ) {
if ( * V_2 != 0 ) {
return V_34 ;
}
}
if ( V_30 . V_36 == 0 ) {
return V_35 ;
}
V_1 -> V_37 = V_38 ;
switch( V_1 -> V_24 . V_25 . V_26 . type ) {
case V_39 :
case V_40 :
V_1 -> V_41 = V_42 ;
break;
case V_43 :
V_1 -> V_41 = V_44 ;
break;
default:
V_1 -> V_41 = V_45 ;
}
V_1 -> V_46 = V_29 ;
V_1 -> V_47 = V_48 ;
V_1 -> V_49 = V_50 ;
V_26 = ( T_10 * ) F_8 ( sizeof( T_10 ) ) ;
V_1 -> V_32 = ( void * ) V_26 ;
V_26 -> V_51 = V_27 ;
if ( F_9 ( V_1 , & V_31 , V_2 ) == - 1 ) {
return V_34 ;
}
V_26 -> V_52 = V_31 . V_53 ;
V_26 -> V_54 = FALSE ;
V_1 -> V_55 = V_56 ;
return V_57 ;
}
static T_11
F_10 ( T_10 * V_26 , T_12 V_16 , struct V_58 * V_24 , T_13 * V_28 ,
T_5 V_59 , int * V_2 , T_3 * * V_3 )
{
T_8 V_30 ;
int V_60 ;
F_11 ( V_28 , V_59 ) ;
V_60 = F_7 ( V_16 , V_24 , F_12 ( V_28 ) , & V_30 ,
V_2 , V_3 ) ;
if ( V_30 . V_61 ) {
V_26 -> V_51 = V_30 . V_61 ;
} else {
V_26 -> V_51 = F_3 ( V_16 ) ;
V_60 = 0 ;
}
if ( V_30 . V_36 ) {
if ( ! V_26 -> V_54 ) {
V_26 -> V_54 = TRUE ;
if ( V_30 . V_62 ) {
V_26 -> V_52 = V_30 . V_63 ;
}
if ( V_26 -> V_52 > V_30 . V_64 )
V_26 -> V_52 -= V_30 . V_64 ;
}
V_24 -> V_65 = V_66 | V_67 ;
V_24 -> V_68 . V_64 = V_30 . V_64 + V_26 -> V_52 ;
V_24 -> V_68 . V_69 = V_30 . V_70 * 1000 ;
V_24 -> V_36 = V_30 . V_36 ;
V_24 -> V_20 = V_30 . V_71 ;
switch( V_24 -> V_25 . V_26 . type ) {
case V_39 :
V_24 -> V_25 . V_72 . V_73 = TRUE ;
V_24 -> V_25 . V_72 . V_74 = 0 ;
break;
case V_40 :
V_24 -> V_25 . V_72 . V_73 = FALSE ;
V_24 -> V_25 . V_72 . V_74 = 0 ;
break;
case V_43 :
V_24 -> V_25 . V_75 . V_76 = 0 ;
break;
}
return V_77 ;
}
if ( V_60 ) {
if ( * V_2 == 0 ) {
* V_2 = V_78 ;
* V_3 = F_13 ( ( V_30 . V_79 != NULL ) ? V_30 . V_79 : L_1 ) ;
}
return V_80 ;
} else
return V_81 ;
}
static T_14 V_48 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_1 * V_82 )
{
T_10 * V_26 = ( T_10 * ) V_1 -> V_32 ;
T_1 V_27 ;
if ( F_5 ( V_1 -> V_16 , V_26 -> V_51 ,
V_23 , V_2 ) == - 1 )
return FALSE ;
V_27 = F_1 ( V_1 , V_2 , V_3 ) ;
if ( V_27 == - 1 )
return FALSE ;
if ( F_10 ( V_26 , V_1 -> V_16 , & V_1 -> V_24 , V_1 -> V_83 ,
V_1 -> V_46 , V_2 , V_3 ) != V_77 )
return FALSE ;
* V_82 = V_27 ;
return TRUE ;
}
static T_14 V_50 ( T_2 * V_1 , T_1 V_84 ,
struct V_58 * V_24 , T_13 * V_28 ,
int * V_2 , T_3 * * V_3 )
{
T_10 * V_26 = ( T_10 * ) V_1 -> V_32 ;
if ( F_5 ( V_1 -> V_85 , V_84 , V_23 , V_2 ) == - 1 )
return FALSE ;
if ( F_10 ( V_26 , V_1 -> V_85 , V_24 , V_28 ,
V_1 -> V_46 , V_2 , V_3 ) != V_77 )
return FALSE ;
return TRUE ;
}
