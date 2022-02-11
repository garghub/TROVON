static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ) {
T_1 V_5 ;
T_2 V_6 ;
V_5 = V_2 -> V_7 & 0xFFF0 ;
V_5 <<= 12 ;
V_5 |= V_2 -> V_8 ;
V_6 = V_2 -> V_7 & 0x000F ;
return V_5 * V_4 -> V_9 * V_4 -> V_10 +
V_6 * V_4 -> V_10 ;
}
static T_1
F_2 ( struct V_11 * V_2 , struct V_3 * V_4 ) {
T_1 V_5 ;
T_2 V_6 ;
V_5 = V_2 -> V_7 & 0xFFF0 ;
V_5 <<= 12 ;
V_5 |= V_2 -> V_8 ;
V_6 = V_2 -> V_7 & 0x000F ;
return V_5 * V_4 -> V_9 * V_4 -> V_10 +
V_6 * V_4 -> V_10 +
V_2 -> V_12 ;
}
int F_3 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_17 , V_18 ;
T_3 V_19 , V_20 , V_21 , V_22 ;
T_4 * V_23 ;
struct V_3 * V_4 ;
char type [ 5 ] = { 0 ,} ;
char V_24 [ 7 ] = { 0 ,} ;
union T_5 {
struct V_25 V_26 ;
struct V_27 V_28 ;
struct V_29 V_30 ;
} * V_31 ;
unsigned char * V_32 ;
T_6 V_33 ;
T_1 V_34 ;
char V_35 [ 64 ] ;
V_18 = 0 ;
V_17 = F_4 ( V_16 ) ;
if ( V_17 <= 0 )
goto V_36;
V_19 = F_5 ( V_16 -> V_37 ) ;
if ( V_19 == 0 )
goto V_36;
V_23 = F_6 ( sizeof( T_4 ) , V_38 ) ;
if ( V_23 == NULL )
goto V_36;
V_4 = F_6 ( sizeof( struct V_3 ) , V_38 ) ;
if ( V_4 == NULL )
goto V_39;
V_31 = F_6 ( sizeof( union T_5 ) , V_38 ) ;
if ( V_31 == NULL )
goto V_40;
if ( F_7 ( V_16 , V_41 , ( unsigned long ) V_23 ) != 0 ||
F_7 ( V_16 , V_42 , ( unsigned long ) V_4 ) != 0 )
goto V_43;
if ( ( V_23 -> V_44 == 0x6310 && V_23 -> V_45 == 0x9336 ) ||
( V_23 -> V_44 == 0x3880 && V_23 -> V_45 == 0x3370 ) )
V_34 = V_23 -> V_46 ;
else
V_34 = V_23 -> V_46 * ( V_17 >> 9 ) ;
V_32 = F_8 ( V_14 , V_34 , & V_33 ) ;
if ( V_32 == NULL )
goto V_47;
memcpy ( V_31 , V_32 , sizeof( union T_5 ) ) ;
F_9 ( V_33 ) ;
if ( ( ! V_23 -> V_48 ) && ( ! strcmp ( V_23 -> type , L_1 ) ) ) {
strncpy ( type , V_31 -> V_26 . V_49 , 4 ) ;
strncpy ( V_24 , V_31 -> V_26 . V_50 , 6 ) ;
} else {
strncpy ( type , V_31 -> V_28 . V_49 , 4 ) ;
strncpy ( V_24 , V_31 -> V_28 . V_50 , 6 ) ;
}
F_10 ( type , 4 ) ;
F_10 ( V_24 , 6 ) ;
V_18 = 1 ;
if ( V_23 -> V_51 == V_52 ) {
if ( strncmp ( type , L_2 , 4 ) == 0 ) {
V_17 = V_31 -> V_30 . V_53 ;
if ( V_31 -> V_30 . V_54 != 0 ) {
snprintf ( V_35 , sizeof( V_35 ) , L_3 , V_24 ) ;
F_11 ( V_14 -> V_55 , V_35 , V_56 ) ;
V_20 = V_31 -> V_30 . V_54 ;
V_21 = ( V_31 -> V_30 . V_57 - 1 )
* ( V_17 >> 9 ) ;
} else {
snprintf ( V_35 , sizeof( V_35 ) , L_4 , V_24 ) ;
F_11 ( V_14 -> V_55 , V_35 , V_56 ) ;
V_20 = ( V_23 -> V_46 + 1 ) ;
V_21 = V_31 -> V_30 . V_57
* ( V_17 >> 9 ) ;
}
F_12 ( V_14 , 1 , V_20 * ( V_17 >> 9 ) ,
V_21 - V_20 * ( V_17 >> 9 ) ) ;
} else {
if ( strncmp ( type , L_5 , 4 ) == 0 ) {
snprintf ( V_35 , sizeof( V_35 ) , L_6 , V_24 ) ;
F_11 ( V_14 -> V_55 , V_35 , V_56 ) ;
if ( V_31 -> V_28 . V_58 == 0xf2 ) {
V_22 = V_31 -> V_28 . V_59
* ( V_17 >> 9 ) ;
} else if ( ! strcmp ( V_23 -> type , L_1 ) ) {
V_22 = V_4 -> V_60 * V_4 -> V_9
* V_4 -> V_10 * ( V_17 >> 9 ) ;
} else {
V_22 = V_19 >> 9 ;
}
V_21 = V_19 >> 9 ;
if ( V_22 < V_21 )
V_21 = V_22 ;
V_20 = ( V_23 -> V_46 + 1 ) ;
} else {
F_11 ( V_14 -> V_55 , L_7 , V_56 ) ;
V_21 = V_19 >> 9 ;
V_20 = ( V_23 -> V_46 + 1 ) ;
}
F_12 ( V_14 , 1 , V_20 * ( V_17 >> 9 ) ,
V_21 - V_20 * ( V_17 >> 9 ) ) ;
}
} else if ( V_23 -> V_51 == V_61 ) {
T_1 V_62 ;
int V_63 ;
if ( strncmp ( type , L_8 , 4 ) == 0 ) {
snprintf ( V_35 , sizeof( V_35 ) , L_9 , V_24 ) ;
F_11 ( V_14 -> V_55 , V_35 , V_56 ) ;
V_62 = F_2 ( & V_31 -> V_26 . V_64 , V_4 ) + 1 ;
V_63 = 0 ;
V_32 = F_8 ( V_14 , V_62 * ( V_17 / 512 ) ,
& V_33 ) ;
while ( V_32 != NULL ) {
struct V_65 V_66 ;
memcpy ( & V_66 , V_32 ,
sizeof( struct V_65 ) ) ;
F_9 ( V_33 ) ;
if ( V_66 . V_67 == V_68 [ '4' ]
|| V_66 . V_67 == V_68 [ '5' ]
|| V_66 . V_67 == V_68 [ '7' ]
|| V_66 . V_67 == V_68 [ '9' ] ) {
V_62 ++ ;
V_32 = F_8 ( V_14 ,
V_62 * ( V_17 / 512 ) , & V_33 ) ;
continue;
}
if ( V_66 . V_67 != V_68 [ '1' ] &&
V_66 . V_67 != V_68 [ '8' ] )
break;
V_20 = F_1 ( & V_66 . V_69 . V_70 , V_4 ) ;
V_21 = F_1 ( & V_66 . V_69 . V_71 , V_4 ) -
V_20 + V_4 -> V_10 ;
if ( V_63 >= V_14 -> V_72 )
break;
F_12 ( V_14 , V_63 + 1 ,
V_20 * ( V_17 >> 9 ) ,
V_21 * ( V_17 >> 9 ) ) ;
V_63 ++ ;
V_62 ++ ;
V_32 = F_8 ( V_14 ,
V_62 * ( V_17 / 512 ) , & V_33 ) ;
}
if ( ! V_32 )
goto V_47;
} else
F_13 ( V_73 L_10
L_11 ) ;
}
F_11 ( V_14 -> V_55 , L_12 , V_56 ) ;
goto V_43;
V_47:
V_18 = - 1 ;
V_43:
F_14 ( V_31 ) ;
V_40:
F_14 ( V_4 ) ;
V_39:
F_14 ( V_23 ) ;
V_36:
return V_18 ;
}
