static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_5 ;
T_2 V_6 ;
V_5 = V_2 -> V_7 & 0xFFF0 ;
V_5 <<= 12 ;
V_5 |= V_2 -> V_8 ;
V_6 = V_2 -> V_7 & 0x000F ;
return V_5 * V_4 -> V_9 * V_4 -> V_10 +
V_6 * V_4 -> V_10 ;
}
static T_1 F_2 ( struct V_11 * V_2 , struct V_3 * V_4 )
{
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
static int F_3 ( struct V_13 * V_14 ,
T_3 * V_15 ,
struct V_3 * V_4 ,
int V_16 ,
T_1 * V_17 ,
char V_18 [] ,
char type [] ,
union V_19 * V_20 )
{
T_4 V_21 ;
unsigned char * V_22 ;
T_1 V_23 [ 3 ] ;
unsigned char V_24 [ 5 ] ;
int V_25 = 0 ;
int V_26 , V_27 ;
if ( V_15 ) {
if ( ( V_15 -> V_28 == 0x6310 && V_15 -> V_29 == 0x9336 ) ||
( V_15 -> V_28 == 0x3880 && V_15 -> V_29 == 0x3370 ) )
V_23 [ 0 ] = V_15 -> V_30 ;
else
V_23 [ 0 ] = V_15 -> V_30 * ( V_16 >> 9 ) ;
V_27 = 1 ;
} else {
V_23 [ 0 ] = 1 ;
V_23 [ 1 ] = ( V_16 >> 9 ) ;
V_23 [ 2 ] = 2 * ( V_16 >> 9 ) ;
V_27 = 3 ;
}
for ( V_26 = 0 ; V_26 < V_27 ; ++ V_26 ) {
V_22 = F_4 ( V_14 , V_23 [ V_26 ] , & V_21 ) ;
if ( V_22 == NULL )
continue;
memcpy ( V_20 , V_22 , sizeof( * V_20 ) ) ;
memcpy ( V_24 , V_22 , 4 ) ;
V_24 [ 4 ] = 0 ;
F_5 ( V_24 , 4 ) ;
F_6 ( V_21 ) ;
if ( ! strcmp ( V_24 , L_1 ) ||
! strcmp ( V_24 , L_2 ) ||
! strcmp ( V_24 , L_3 ) ) {
if ( ! strcmp ( V_24 , L_1 ) ) {
strncpy ( type , V_20 -> V_31 . V_32 , 4 ) ;
strncpy ( V_18 , V_20 -> V_31 . V_33 , 6 ) ;
} else {
strncpy ( type , V_20 -> V_34 . V_32 , 4 ) ;
strncpy ( V_18 , V_20 -> V_34 . V_33 , 6 ) ;
}
F_5 ( type , 4 ) ;
F_5 ( V_18 , 6 ) ;
* V_17 = V_23 [ V_26 ] ;
V_25 = 1 ;
break;
}
}
if ( ! V_25 )
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
return V_25 ;
}
static int F_7 ( struct V_13 * V_14 ,
struct V_3 * V_4 ,
int V_16 ,
char V_18 [] ,
union V_19 * V_20 )
{
T_1 V_35 ;
int V_36 ;
char V_37 [ 64 ] ;
T_4 V_21 ;
unsigned char * V_22 ;
T_5 V_38 , V_39 ;
struct V_40 V_41 ;
int V_42 ;
snprintf ( V_37 , sizeof( V_37 ) , L_4 , V_18 ) ;
F_8 ( V_14 -> V_43 , V_37 , V_44 ) ;
V_42 = V_16 >> 9 ;
V_35 = F_2 ( & V_20 -> V_31 . V_45 , V_4 ) + 1 ;
V_36 = 0 ;
V_22 = F_4 ( V_14 , V_35 * V_42 , & V_21 ) ;
while ( V_22 != NULL ) {
memcpy ( & V_41 , V_22 , sizeof( struct V_40 ) ) ;
F_6 ( V_21 ) ;
if ( V_41 . V_46 == V_47 [ '4' ]
|| V_41 . V_46 == V_47 [ '5' ]
|| V_41 . V_46 == V_47 [ '7' ]
|| V_41 . V_46 == V_47 [ '9' ] ) {
V_35 ++ ;
V_22 = F_4 ( V_14 , V_35 * V_42 , & V_21 ) ;
continue;
}
if ( V_41 . V_46 != V_47 [ '1' ] &&
V_41 . V_46 != V_47 [ '8' ] )
break;
V_38 = F_1 ( & V_41 . V_48 . V_49 , V_4 ) ;
V_39 = F_1 ( & V_41 . V_48 . V_50 , V_4 ) -
V_38 + V_4 -> V_10 ;
V_38 *= V_42 ;
V_39 *= V_42 ;
if ( V_36 >= V_14 -> V_51 )
break;
F_9 ( V_14 , V_36 + 1 , V_38 , V_39 ) ;
V_36 ++ ;
V_35 ++ ;
V_22 = F_4 ( V_14 , V_35 * V_42 , & V_21 ) ;
}
F_8 ( V_14 -> V_43 , L_5 , V_44 ) ;
if ( ! V_22 )
return - 1 ;
return 1 ;
}
static int F_10 ( struct V_13 * V_14 ,
struct V_3 * V_4 ,
int V_16 ,
char V_18 [] ,
union V_19 * V_20 ,
T_1 V_17 ,
T_5 V_52 ,
T_3 * V_15 )
{
T_5 V_38 , V_53 , V_39 ;
char V_37 [ 64 ] ;
int V_42 ;
snprintf ( V_37 , sizeof( V_37 ) , L_6 , V_18 ) ;
F_8 ( V_14 -> V_43 , V_37 , V_44 ) ;
V_42 = V_16 >> 9 ;
if ( V_20 -> V_34 . V_54 == 0xf2 ) {
V_39 = V_20 -> V_34 . V_55 * V_42 ;
} else {
V_53 = V_4 -> V_56 * V_4 -> V_9
* V_4 -> V_10 * V_42 ;
V_39 = V_52 >> 9 ;
if ( V_39 != V_53 ) {
if ( ! V_15 ) {
F_8 ( V_14 -> V_43 , L_5 , V_44 ) ;
return 1 ;
}
if ( ! strcmp ( V_15 -> type , L_7 ) )
if ( V_53 < V_39 )
V_39 = V_53 ;
}
}
V_38 = V_17 + V_42 ;
F_9 ( V_14 , 1 , V_38 , V_39 - V_38 ) ;
F_8 ( V_14 -> V_43 , L_5 , V_44 ) ;
return 1 ;
}
static int F_11 ( struct V_13 * V_14 ,
struct V_3 * V_4 ,
int V_16 ,
char V_18 [] ,
union V_19 * V_20 ,
T_1 V_17 )
{
T_5 V_38 , V_39 ;
char V_37 [ 64 ] ;
int V_42 ;
V_16 = V_20 -> V_57 . V_58 ;
V_42 = V_16 >> 9 ;
if ( V_20 -> V_57 . V_59 != 0 ) {
snprintf ( V_37 , sizeof( V_37 ) , L_8 , V_18 ) ;
F_8 ( V_14 -> V_43 , V_37 , V_44 ) ;
V_38 = V_20 -> V_57 . V_59 * V_42 ;
V_39 = ( V_20 -> V_57 . V_60 - 1 ) * V_42 ;
} else {
snprintf ( V_37 , sizeof( V_37 ) , L_9 , V_18 ) ;
F_8 ( V_14 -> V_43 , V_37 , V_44 ) ;
if ( V_17 == 1 )
V_38 = 2 * V_42 ;
else
V_38 = V_17 + V_42 ;
V_39 = V_20 -> V_57 . V_60 * V_42 ;
}
F_9 ( V_14 , 1 , V_38 , V_39 - V_38 ) ;
F_8 ( V_14 -> V_43 , L_5 , V_44 ) ;
return 1 ;
}
int F_12 ( struct V_13 * V_14 )
{
struct V_61 * V_62 = V_14 -> V_62 ;
int V_16 , V_63 ;
T_5 V_52 , V_38 , V_39 ;
T_3 * V_15 ;
struct V_3 * V_4 ;
char type [ 5 ] = { 0 ,} ;
char V_18 [ 7 ] = { 0 ,} ;
T_1 V_17 ;
union V_19 * V_20 ;
V_63 = 0 ;
V_16 = F_13 ( V_62 ) ;
if ( V_16 <= 0 )
goto V_64;
V_52 = F_14 ( V_62 -> V_65 ) ;
if ( V_52 == 0 )
goto V_64;
V_15 = F_15 ( sizeof( T_3 ) , V_66 ) ;
if ( V_15 == NULL )
goto V_64;
V_4 = F_15 ( sizeof( struct V_3 ) , V_66 ) ;
if ( V_4 == NULL )
goto V_67;
V_20 = F_15 ( sizeof( union V_19 ) , V_66 ) ;
if ( V_20 == NULL )
goto V_68;
if ( F_16 ( V_62 , V_69 , ( unsigned long ) V_4 ) != 0 )
goto V_70;
if ( F_16 ( V_62 , V_71 , ( unsigned long ) V_15 ) != 0 ) {
F_17 ( V_15 ) ;
V_15 = NULL ;
}
if ( F_3 ( V_14 , V_15 , V_4 , V_16 , & V_17 , V_18 , type ,
V_20 ) ) {
if ( ! strncmp ( type , L_1 , 4 ) ) {
V_63 = F_7 ( V_14 , V_4 , V_16 , V_18 ,
V_20 ) ;
} else if ( ! strncmp ( type , L_2 , 4 ) ) {
V_63 = F_10 ( V_14 , V_4 , V_16 , V_18 ,
V_20 , V_17 , V_52 ,
V_15 ) ;
} else if ( ! strncmp ( type , L_3 , 4 ) ) {
V_63 = F_11 ( V_14 , V_4 , V_16 , V_18 ,
V_20 , V_17 ) ;
}
} else if ( V_15 ) {
V_63 = 1 ;
if ( V_15 -> V_72 == V_73 ) {
F_8 ( V_14 -> V_43 , L_10 , V_44 ) ;
V_39 = V_52 >> 9 ;
V_38 = ( V_15 -> V_30 + 1 ) * ( V_16 >> 9 ) ;
F_9 ( V_14 , 1 , V_38 , V_39 - V_38 ) ;
F_8 ( V_14 -> V_43 , L_5 , V_44 ) ;
}
} else
V_63 = 0 ;
V_70:
F_17 ( V_20 ) ;
V_68:
F_17 ( V_4 ) ;
V_67:
F_17 ( V_15 ) ;
V_64:
return V_63 ;
}
