static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 ,
int V_4 )
{
struct V_5 * V_6 = NULL ;
int V_7 = 0 ;
do {
V_6 = (struct V_5 * ) F_2 ( sizeof( struct V_5 ) ) ;
if ( NULL == V_6 ) {
V_7 = V_8 ;
break;
}
F_3 ( V_6 , sizeof( struct V_5 ) ) ;
F_4 ( V_6 ,
NULL ,
V_3 ,
V_4 ,
V_9 ,
V_10 ) ;
V_7 = F_5 ( V_2 -> V_11 , V_6 , true ) ;
} while ( false );
if ( V_6 != NULL ) {
F_6 ( V_6 ) ;
}
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 ,
T_1 * V_3 ,
int * V_12 )
{
int V_7 = 0 ;
struct V_5 * V_13 = NULL ;
do {
V_13 = (struct V_5 * ) F_2 ( sizeof( struct V_5 ) ) ;
if ( NULL == V_13 ) {
V_7 = V_8 ;
F_8 ( V_14 , ( L_1 ) ) ;
break;
}
F_3 ( V_13 , sizeof( struct V_5 ) ) ;
F_9 ( V_13 , NULL , V_3 , * V_12 , V_15 ) ;
V_7 = F_10 ( V_2 -> V_11 ,
V_13 ,
V_16 ) ;
if ( V_7 ) {
break;
}
* V_12 = V_13 -> V_17 ;
} while ( false );
if ( V_13 != NULL ) {
F_6 ( V_13 ) ;
}
return V_7 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 * V_18 ,
int V_19 ,
T_1 * * V_20 ,
T_1 * * V_21 )
{
int V_7 = 0 ;
T_1 * V_3 = NULL ;
T_1 * V_22 ;
int V_23 ;
bool V_24 = false ;
T_1 V_25 [ 2 ] ;
do {
V_23 = F_12 ( V_26 , V_19 ) ;
V_23 += V_2 -> V_27 -> V_28 + V_2 -> V_27 -> V_29 ;
V_23 += V_2 -> V_27 -> V_30 ;
V_3 = ( T_1 * ) F_2 ( V_23 ) ;
if ( NULL == V_3 ) {
F_8 ( V_14 , ( L_2 ) ) ;
V_7 = V_8 ;
break;
}
V_25 [ 0 ] = V_18 [ V_31 ] ;
V_25 [ 1 ] = V_18 [ V_32 ] ;
memcpy ( V_3 + V_2 -> V_27 -> V_28 , V_18 , V_19 ) ;
V_7 = F_1 ( V_2 ,
V_3 + V_2 -> V_27 -> V_28 ,
V_19 ) ;
if ( V_7 ) {
F_8 ( V_14 , ( L_3 , V_7 ) ) ;
F_13 ( V_18 , V_19 , L_4 ) ;
break;
}
F_3 ( V_3 , V_23 ) ;
V_7 = F_7 ( V_2 , V_3 , & V_23 ) ;
if ( V_7 ) {
F_8 ( V_14 , ( L_5 ) ) ;
F_13 ( V_18 , V_19 , L_4 ) ;
break;
}
V_22 = V_3 + V_2 -> V_27 -> V_28 ;
if ( V_22 [ 0 ] == V_33 ) {
if ( ( V_22 [ V_34 ] == V_25 [ 0 ] ) &&
( V_22 [ V_35 ] == V_25 [ 1 ] ) ) {
V_24 = true ;
}
}
if ( ! V_24 ) {
F_8 ( V_14 , ( L_6 , V_22 [ 0 ] ) ) ;
F_13 ( V_22 , V_22 [ 1 ] , L_7 ) ;
V_7 = V_36 ;
break;
}
if ( V_20 != NULL ) {
* V_20 = V_22 ;
if ( V_21 == NULL ) {
V_7 = V_37 ;
break;
}
* V_21 = V_3 ;
V_3 = NULL ;
}
} while ( false );
if ( V_3 != NULL ) {
F_6 ( V_3 ) ;
}
return V_7 ;
}
static int F_14 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
T_1 V_38 [] = { 0x0c , 0xfc , 0x2 , 0 , 0 } ;
T_2 V_39 ;
T_1 * V_40 = NULL ;
T_1 * V_41 = NULL ;
do {
if ( V_2 -> V_42 & V_43 ) {
V_39 = ( T_2 ) ( V_2 -> V_44 / 100 ) ;
V_38 [ 3 ] = ( T_1 ) V_39 ;
V_38 [ 4 ] = ( T_1 ) ( V_39 >> 8 ) ;
V_7 = F_11 ( V_2 ,
V_38 ,
sizeof( V_38 ) ,
& V_40 ,
& V_41 ) ;
if ( V_7 ) {
F_8 ( V_14 , ( L_8 ) ) ;
break;
}
if ( V_40 [ V_45 ] != 0 ) {
F_8 ( V_14 ,
( L_9 ,
V_40 [ V_45 ] ) ) ;
V_7 = V_36 ;
break;
}
F_8 ( V_46 ,
( L_10 , V_2 -> V_44 ) ) ;
}
if ( V_2 -> V_42 & V_47 ) {
F_15 ( 325 ) ;
}
if ( V_2 -> V_42 & V_48 ) {
V_7 = F_16 ( V_2 -> V_11 , V_2 -> V_44 ) ;
if ( V_7 ) {
F_8 ( V_14 ,
( L_11 , V_7 ) ) ;
break;
}
F_8 ( V_46 ,
( L_12 , V_2 -> V_44 ) ) ;
}
} while ( false );
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_7 ;
char V_49 [] = { 0x25 , 0xFC , 0x0c , 0x03 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 , 0x00 } ;
T_1 * V_40 = NULL ;
T_1 * V_41 = NULL ;
V_7 = F_11 ( V_2 ,
V_49 ,
sizeof( V_49 ) ,
& V_40 ,
& V_41 ) ;
if ( ! V_7 ) {
if ( V_40 [ V_50 ] != 0 ) {
F_8 ( V_14 ,
( L_13 ,
V_40 [ V_50 ] ) ) ;
V_7 = V_36 ;
} else {
F_8 ( V_51 ,
( L_14 ) ) ;
F_15 ( 1 ) ;
}
} else {
F_8 ( V_14 , ( L_15 ) ) ;
}
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
return V_7 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
T_1 V_52 [] = { 0x03 , 0x0c , 0x0 } ;
T_1 * V_40 = NULL ;
T_1 * V_41 = NULL ;
V_7 = F_11 ( V_2 ,
V_52 ,
sizeof( V_52 ) ,
& V_40 ,
& V_41 ) ;
if ( V_7 ) {
F_8 ( V_14 , ( L_16 ) ) ;
}
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
return V_7 ;
}
static int F_19 ( struct V_1 * V_2 )
{
int V_7 ;
char V_53 [] = { 0x31 , 0xFC , 0x18 ,
0x02 , 0x00 , 0x00 , 0x00 ,
0x01 , 0x00 , 0x00 , 0x00 ,
V_54 , V_55 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
V_56 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
char V_57 [] = { 0x31 , 0xFC , 0x18 ,
0x04 , 0x00 , 0x00 , 0x00 ,
0x01 , 0x00 , 0x00 , 0x00 ,
V_54 , V_55 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 ,
V_56 , 0x00 , 0x00 , 0x00 ,
0x00 , 0x00 , 0x00 , 0x00 } ;
char V_58 [] = { 0x31 , 0xFC , 0x4 ,
0x01 , 0x00 , 0x00 , 0x00 } ;
char V_59 [] = { 0x31 , 0xFC , 0x4 ,
0x06 , 0x00 , 0x00 , 0x00 } ;
char V_60 [] = { 0x4 , 0xFC , 0x1 ,
0x1 } ;
T_1 * V_40 = NULL ;
T_1 * V_41 = NULL ;
if ( 0 != V_2 -> V_61 ) {
T_1 V_62 = V_2 -> V_61 & 0xFF ;
T_1 V_63 = ( V_2 -> V_61 & 0xFF00 ) >> 8 ;
V_53 [ 11 ] = V_57 [ 11 ] = V_62 ;
V_53 [ 12 ] = V_57 [ 12 ] = V_63 ;
}
if ( 0 != V_2 -> V_64 ) {
V_53 [ 19 ] = V_57 [ 19 ] = ( V_2 -> V_64 & 0xFF ) ;
}
V_7 = F_11 ( V_2 ,
V_53 ,
sizeof( V_53 ) ,
& V_40 ,
& V_41 ) ;
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
if ( V_7 ) {
F_8 ( V_14 , ( L_17 ) ) ;
return V_7 ;
}
V_40 = NULL ;
V_41 = NULL ;
V_7 = F_11 ( V_2 ,
V_57 ,
sizeof( V_57 ) ,
& V_40 ,
& V_41 ) ;
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
if ( V_7 ) {
F_8 ( V_14 , ( L_18 ) ) ;
return V_7 ;
}
V_40 = NULL ;
V_41 = NULL ;
V_7 = F_11 ( V_2 ,
V_58 ,
sizeof( V_58 ) ,
& V_40 ,
& V_41 ) ;
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
if ( V_7 ) {
F_8 ( V_14 , ( L_19 ) ) ;
return V_7 ;
}
V_40 = NULL ;
V_41 = NULL ;
V_7 = F_11 ( V_2 ,
V_59 ,
sizeof( V_59 ) ,
& V_40 ,
& V_41 ) ;
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
if ( V_7 ) {
F_8 ( V_14 , ( L_20 ) ) ;
return V_7 ;
}
V_40 = NULL ;
V_41 = NULL ;
V_7 = F_11 ( V_2 ,
V_60 ,
sizeof( V_60 ) ,
& V_40 ,
& V_41 ) ;
if ( V_41 != NULL ) {
F_6 ( V_41 ) ;
}
if ( V_7 ) {
F_8 ( V_14 , ( L_21 ) ) ;
}
F_8 ( V_14 , ( L_22 , V_7 ) ) ;
return V_7 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_7 = 0 ;
F_8 ( V_51 , ( L_23 ) ) ;
do {
if ( ( V_2 -> V_11 == NULL ) || ( V_2 -> V_27 == NULL ) || ( V_2 -> V_65 == NULL ) ) {
V_7 = V_37 ;
break;
}
V_7 = F_21 ( V_2 -> V_11 , false ) ;
if ( V_7 ) {
break;
}
if ( V_2 -> V_42 & V_66 ) {
V_7 = F_17 ( V_2 ) ;
if ( V_7 ) {
break;
}
}
if ( 0 != F_22 ( V_2 ) ) {
F_8 ( V_14 , ( L_24 ) ) ;
}
F_18 ( V_2 ) ;
if ( V_2 -> V_42 &
( V_43 | V_48 ) ) {
V_7 = F_14 ( V_2 ) ;
if ( V_7 ) {
break;
}
}
if ( V_2 -> V_67 ) {
F_15 ( 200 ) ;
F_19 ( V_2 ) ;
}
V_7 = F_21 ( V_2 -> V_11 , true ) ;
if ( V_7 ) {
break;
}
} while ( false );
F_8 ( V_51 , ( L_25 , V_7 ) ) ;
return V_7 ;
}
int F_23 ( void * V_68 )
{
int V_7 = 0 ;
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
F_8 ( V_51 , ( L_26 ) ) ;
do {
if ( ( V_2 -> V_11 == NULL ) || ( V_2 -> V_27 == NULL ) || ( V_2 -> V_65 == NULL ) ) {
V_7 = V_37 ;
break;
}
V_7 = F_21 ( V_2 -> V_11 , false ) ;
if ( V_7 ) {
break;
}
if ( V_2 -> V_42 &
( V_43 | V_48 ) ) {
V_7 = F_14 ( V_2 ) ;
if ( V_7 ) {
break;
}
}
V_7 = F_21 ( V_2 -> V_11 , true ) ;
if ( V_7 ) {
break;
}
} while ( false );
F_8 ( V_51 , ( L_27 , V_7 ) ) ;
return V_7 ;
}
