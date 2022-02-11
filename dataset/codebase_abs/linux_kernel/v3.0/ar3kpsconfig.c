void F_1 ( T_1 * V_1 , T_1 * V_2 , T_2 V_3 )
{
int V_4 ;
F_2 ( V_5 , ( L_1 , V_1 ) ) ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
F_2 ( V_5 , ( L_2 , V_2 [ V_4 ] ) ) ;
}
F_2 ( V_5 , ( L_3 ) ) ;
}
int F_3 ( struct V_6 * V_7 )
{
int V_8 = 0 ;
if( V_7 == NULL ) {
F_2 ( V_5 , ( L_4 ) ) ;
return V_9 ;
}
#ifndef F_4
F_5 ( V_10 , V_11 ) ;
#endif
#ifdef F_4
V_8 = F_6 ( ( void * ) V_7 ) ;
#else
if( F_7 ( V_7 ) == - 1 ) {
return V_9 ;
}
F_8 ( V_12 ) ;
F_9 ( & V_13 , & V_10 ) ;
F_10 ( V_14 ) ;
if( ! F_11 ( F_6 , ( void * ) V_7 , V_15 | V_16 | V_17 | V_18 ) ) {
F_2 ( V_5 , ( L_5 ) ) ;
F_12 ( & V_13 , & V_10 ) ;
return V_9 ;
}
F_13 ( V_13 , ( V_19 == false ) ) ;
F_10 ( V_20 ) ;
F_12 ( & V_13 , & V_10 ) ;
#endif
return V_8 ;
}
int F_6 ( void * V_21 )
{
int V_4 ;
int V_8 = 0 ;
struct V_22 * V_23 ;
const struct V_24 * V_24 ;
T_2 V_25 ;
T_1 * V_26 ;
T_1 * V_27 ;
struct V_28 * V_29 ;
T_1 * V_30 ;
T_2 V_3 ;
T_2 V_31 ;
T_1 * V_32 ;
T_1 * V_33 ;
T_1 * V_34 = NULL ;
T_1 * V_35 = NULL ;
T_1 V_36 [ V_37 ] ;
struct V_6 * V_7 = (struct V_6 * ) V_21 ;
struct V_29 * V_38 = NULL ;
V_8 = 0 ;
V_23 = NULL ;
#ifdef F_4
V_29 = V_7 -> V_39 ;
V_38 = V_29 -> V_40 ;
#else
V_29 = V_7 ;
V_38 = & V_29 -> V_41 ;
F_14 ( true ) ;
#endif
V_34 = ( T_1 * ) F_15 ( V_42 ) ;
if( V_34 == NULL ) {
F_2 ( V_5 , ( L_6 , V_42 ) ) ;
goto V_43;
}
V_35 = ( T_1 * ) F_15 ( V_42 ) ;
if( V_35 == NULL ) {
F_2 ( V_5 , ( L_7 , V_42 ) ) ;
goto V_43;
}
if( V_9 == F_16 ( V_7 , & V_31 ) ) {
V_8 = 1 ;
goto V_43;
}
if( V_9 == F_17 ( V_7 ) ) {
V_8 = 1 ;
goto V_43;
}
V_33 = V_44 ;
snprintf ( V_34 , V_42 , L_8 , V_45 , V_46 ) ;
if( V_31 ) {
if( V_31 == 0xdeadc0de ) {
V_32 = V_47 ;
} else{
F_2 ( V_5 , ( L_9 , V_46 , V_48 ) ) ;
if( ( V_46 == 0x99999999 ) && ( V_48 == 1 ) ) {
F_2 ( V_5 , ( L_10 ) ) ;
V_33 = NULL ;
}
V_32 = V_49 ;
}
}
else{
V_32 = V_47 ;
}
snprintf ( V_35 , V_42 , L_11 , V_34 , V_32 ) ;
F_2 ( V_5 , ( L_12 , V_31 , V_35 ) ) ;
if( F_18 ( & V_24 , V_35 , V_38 ) < 0 ) {
F_2 ( V_5 , ( L_13 , V_50 ) ) ;
V_8 = 1 ;
goto V_43;
}
if( NULL == V_24 || V_24 -> V_51 == 0 ) {
V_8 = 1 ;
goto V_43;
}
V_30 = ( T_1 * ) F_15 ( V_24 -> V_51 ) ;
if( V_30 != NULL ) {
memcpy ( V_30 , V_24 -> V_2 , V_24 -> V_51 ) ;
V_3 = V_24 -> V_51 ;
F_19 ( V_24 ) ;
V_8 = F_20 ( V_30 , V_3 ) ;
F_21 ( V_30 ) ;
} else {
F_19 ( V_24 ) ;
}
if( V_33 != NULL )
snprintf ( V_35 ,
V_42 , L_11 , V_34 , V_33 ) ;
else {
V_8 = 0 ;
}
F_2 ( V_5 , ( L_14 , V_35 ) ) ;
if( ( V_33 == NULL ) || ( F_18 ( & V_24 , V_35 , V_38 ) < 0 ) ) {
F_2 ( V_5 , ( L_13 , V_50 ) ) ;
V_8 = 0 ;
} else {
if( NULL == V_24 || V_24 -> V_51 == 0 ) {
V_8 = 0 ;
} else {
V_30 = ( T_1 * ) F_15 ( V_24 -> V_51 ) ;
if( V_30 != NULL ) {
memcpy ( V_30 , V_24 -> V_2 , V_24 -> V_51 ) ;
V_3 = V_24 -> V_51 ;
F_19 ( V_24 ) ;
V_8 = F_22 ( V_30 , V_3 ) ;
F_21 ( V_30 ) ;
} else {
F_19 ( V_24 ) ;
}
}
}
F_23 ( & V_23 , & V_25 ) ;
if( F_24
( V_7 ,
V_23 [ 0 ] . V_52 ,
V_23 [ 0 ] . V_53 ,
& V_26 ,
& V_27 ) == 0 ) {
if( F_25 ( V_26 ) == 0 ) {
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
#ifndef F_4
if( V_54 && V_54 [ 0 ] != '\0' ) {
F_26 ( V_7 , V_54 , V_55 ) ;
}
#endif
V_8 = 1 ;
goto V_43;
}
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
} else {
V_8 = 0 ;
goto V_43;
}
for( V_4 = 1 ; V_4 < V_25 ; V_4 ++ ) {
if( F_24
( V_7 ,
V_23 [ V_4 ] . V_52 ,
V_23 [ V_4 ] . V_53 ,
& V_26 ,
& V_27 ) == 0 ) {
if( F_25 ( V_26 ) != 0 ) {
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
V_8 = 1 ;
goto V_43;
}
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
} else {
V_8 = 0 ;
goto V_43;
}
}
#ifdef F_4
if( V_56 == false )
if( V_7 -> V_54 [ 0 ] != 0x00 ||
V_7 -> V_54 [ 1 ] != 0x00 ||
V_7 -> V_54 [ 2 ] != 0x00 ||
V_7 -> V_54 [ 3 ] != 0x00 ||
V_7 -> V_54 [ 4 ] != 0x00 ||
V_7 -> V_54 [ 5 ] != 0x00 )
F_26 ( V_7 , V_7 -> V_54 , V_57 ) ;
#ifndef F_4
if( V_54 && V_54 [ 0 ] != '\0' ) {
F_26 ( V_7 , V_54 , V_55 ) ;
} else
#endif
#endif
{
snprintf ( V_35 , V_42 , L_11 , V_34 , V_58 ) ;
F_2 ( V_5 , ( L_14 , V_35 ) ) ;
if( F_18 ( & V_24 , V_35 , V_38 ) < 0 ) {
F_2 ( V_5 , ( L_13 , V_50 ) ) ;
V_8 = 1 ;
goto V_43;
}
if( NULL == V_24 || V_24 -> V_51 == 0 ) {
V_8 = 1 ;
goto V_43;
}
V_3 = F_27 ( V_59 , V_24 -> V_51 , V_37 - 1 ) ;
memcpy ( V_36 , V_24 -> V_2 , V_3 ) ;
V_36 [ V_3 ] = '\0' ;
F_26 ( V_7 , V_36 , V_55 ) ;
F_19 ( V_24 ) ;
}
V_43:
#ifndef F_4
F_14 ( false ) ;
V_19 = false ;
F_28 ( & V_13 ) ;
#endif
if( NULL != V_23 ) {
F_29 ( & V_23 , V_25 ) ;
}
if( V_34 ) {
F_21 ( V_34 ) ;
}
if( V_35 ) {
F_21 ( V_35 ) ;
}
return V_8 ;
}
int F_24 ( struct V_6 * V_60 ,
T_1 * V_61 ,
int V_62 ,
T_1 * * V_63 ,
T_1 * * V_64 )
{
if( V_62 == 0 ) {
return V_9 ;
}
F_1 ( L_15 , V_61 , V_62 ) ;
V_65 = false ;
if( F_30 ( V_60 , V_61 , V_62 ) == 0 ) {
return V_9 ;
}
F_13 ( V_66 , ( V_65 == true ) ) ;
if( NULL != V_67 ) {
* V_63 = V_67 ;
* V_64 = V_67 ;
} else {
* V_64 = NULL ;
return V_9 ;
}
return 0 ;
}
int F_25 ( T_1 * V_68 ) {
F_2 ( V_5 , ( L_16 , V_68 [ 4 ] , V_68 [ 5 ] , V_68 [ 3 ] ) ) ;
if( V_68 [ 4 ] == 0xFC && V_68 [ 5 ] == 0x00 )
{
switch( V_68 [ 3 ] ) {
case 0x0B :
return 0 ;
break;
case 0x0C :
return 0 ;
break;
case 0x04 :
return 0 ;
break;
case 0x1E :
V_46 = V_68 [ 9 ] ;
V_46 = ( ( V_46 << 8 ) | V_68 [ 8 ] ) ;
V_46 = ( ( V_46 << 8 ) | V_68 [ 7 ] ) ;
V_46 = ( ( V_46 << 8 ) | V_68 [ 6 ] ) ;
V_48 = V_68 [ 13 ] ;
V_48 = ( ( V_48 << 8 ) | V_68 [ 12 ] ) ;
V_48 = ( ( V_48 << 8 ) | V_68 [ 11 ] ) ;
V_48 = ( ( V_48 << 8 ) | V_68 [ 10 ] ) ;
return 0 ;
break;
}
}
return V_9 ;
}
int F_31 ( unsigned char * V_69 , unsigned char * V_54 )
{
unsigned char V_70 [ 3 ] ;
unsigned char * V_71 = V_69 ;
int V_4 , V_72 ;
unsigned char V_73 = 0 ;
if( NULL != strstr ( V_69 , L_17 ) ) {
V_73 = 1 ;
}
V_70 [ 2 ] = '\0' ;
for( V_4 = 0 , V_72 = 5 ; V_4 < 6 ; V_4 ++ , V_72 -- ) {
V_70 [ 0 ] = V_71 [ 0 ] ;
V_70 [ 1 ] = V_71 [ 1 ] ;
V_54 [ V_72 ] = F_32 ( V_70 , NULL , 16 ) ;
if( V_73 == 1 ) {
V_71 += 3 ;
} else {
V_71 += 2 ;
}
}
return 0 ;
}
int F_26 ( struct V_6 * V_60 , T_1 * V_54 , int type )
{
T_1 V_74 [] = { 0x0B , 0xFC , 0x0A , 0x01 , 0x01 ,
0x00 , 0x06 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
T_1 * V_26 ;
T_1 * V_27 = NULL ;
int V_75 = V_9 ;
int V_76 , V_77 ;
if ( type == V_55 )
F_31 ( V_54 , & V_74 [ 7 ] ) ;
else {
for( V_76 = 5 , V_77 = 7 ; V_76 >= 0 ; V_76 -- , V_77 ++ )
V_74 [ V_77 ] = V_54 [ V_76 ] ;
}
if( 0 == F_24 ( V_60 , V_74 ,
sizeof( V_74 ) ,
& V_26 , & V_27 ) ) {
if( V_26 [ 4 ] == 0xFC && V_26 [ 5 ] == 0x00 ) {
if( V_26 [ 3 ] == 0x0B ) {
V_75 = 0 ;
}
}
}
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
return V_75 ;
}
int F_17 ( struct V_6 * V_60 )
{
T_1 V_78 [] = { 0x1E , 0xfc , 0x00 } ;
T_1 * V_26 ;
T_1 * V_27 = NULL ;
int V_75 = V_9 ;
if( 0 == F_24 ( V_60 , V_78 , sizeof( V_78 ) , & V_26 , & V_27 ) ) {
V_75 = F_25 ( V_26 ) ;
}
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
return V_75 ;
}
int F_16 ( struct V_6 * V_60 , T_2 * V_79 )
{
T_1 V_78 [] = { 0x05 , 0xfc , 0x05 , 0x00 , 0x00 , 0x00 , 0x00 , 0x04 } ;
T_1 * V_26 ;
T_1 * V_27 = NULL ;
T_2 V_80 ;
int V_75 = V_9 ;
* V_79 = 0 ;
V_78 [ 3 ] = ( T_1 ) ( V_81 & 0xFF ) ;
V_78 [ 4 ] = ( T_1 ) ( ( V_81 >> 8 ) & 0xFF ) ;
V_78 [ 5 ] = ( T_1 ) ( ( V_81 >> 16 ) & 0xFF ) ;
V_78 [ 6 ] = ( T_1 ) ( ( V_81 >> 24 ) & 0xFF ) ;
if( 0 == F_24 ( V_60 , V_78 , sizeof( V_78 ) , & V_26 , & V_27 ) ) {
if( V_26 [ 4 ] == 0xFC && V_26 [ 5 ] == 0x00 ) {
switch( V_26 [ 3 ] ) {
case 0x05 :
V_80 = V_26 [ 9 ] ;
V_80 = ( ( V_80 << 8 ) | V_26 [ 8 ] ) ;
V_80 = ( ( V_80 << 8 ) | V_26 [ 7 ] ) ;
V_80 = ( ( V_80 << 8 ) | V_26 [ 6 ] ) ;
* V_79 = V_80 ;
V_75 = 0 ;
break;
case 0x06 :
break;
}
}
}
if( V_27 != NULL ) {
F_21 ( V_27 ) ;
}
return V_75 ;
}
