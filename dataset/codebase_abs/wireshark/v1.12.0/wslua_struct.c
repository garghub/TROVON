static int F_1 ( const T_1 * * V_1 , int V_2 ) {
if ( ! isdigit ( * * V_1 ) )
return V_2 ;
else {
int V_3 = 0 ;
do {
V_3 = V_3 * 10 + * ( ( * V_1 ) ++ ) - '0' ;
} while ( isdigit ( * * V_1 ) );
return V_3 ;
}
}
static T_2 F_2 ( T_3 * V_4 , T_1 V_5 , const T_1 * * V_1 ) {
switch ( V_5 ) {
case 'B' : case 'b' : return sizeof( T_1 ) ;
case 'H' : case 'h' : return sizeof( V_6 ) ;
case 'L' : case 'l' : return sizeof( V_7 ) ;
case 'E' : case 'e' : return sizeof( V_8 ) ;
case 'T' : return sizeof( T_2 ) ;
case 'f' : return sizeof( V_9 ) ;
case 'd' : return sizeof( V_10 ) ;
case 'x' : return F_1 ( V_1 , 1 ) ;
case 'X' : return F_1 ( V_1 , V_11 ) ;
case 'c' : return F_1 ( V_1 , 1 ) ;
case 'i' : case 'I' : {
int V_12 = F_1 ( V_1 , sizeof( int ) ) ;
if ( V_12 > V_13 )
F_3 ( V_4 , L_1 ,
V_12 , V_13 ) ;
return V_12 ;
}
case 's' : case ' ' :
case '<' : case '>' :
case '(' : case ')' :
case '!' : case '=' :
return 0 ;
default: {
const T_1 * V_14 = F_4 ( V_4 , L_2 , V_5 ) ;
return F_5 ( V_4 , 1 , V_14 ) ;
}
}
}
static int F_6 ( T_2 V_15 , T_4 * V_16 , int V_5 , T_2 V_17 ) {
if ( V_17 == 0 || V_5 == 'c' || V_5 == 's' ) return 0 ;
if ( V_17 > ( T_2 ) V_16 -> V_18 )
V_17 = V_16 -> V_18 ;
return ( int ) ( ( V_17 - ( V_15 & ( V_17 - 1 ) ) ) & ( V_17 - 1 ) ) ;
}
static void F_7 ( T_3 * V_4 , int V_5 , const T_1 * * V_1 ,
T_4 * V_16 ) {
switch ( V_5 ) {
case ' ' : return;
case '>' : V_16 -> V_19 = V_20 ; return;
case '<' : V_16 -> V_19 = V_21 ; return;
case '(' : V_16 -> V_22 = TRUE ; return;
case ')' : V_16 -> V_22 = FALSE ; return;
case '!' : {
int V_3 = F_1 ( V_1 , V_11 ) ;
if ( ! F_8 ( V_3 ) )
F_3 ( V_4 , L_3 , V_3 ) ;
V_16 -> V_18 = V_3 ;
return;
}
default: {
const char * V_14 = F_4 ( V_4 , L_4 , V_5 ) ;
F_5 ( V_4 , 1 , V_14 ) ;
}
}
}
static void F_9 ( T_3 * V_4 , T_5 * V_23 , int V_24 , int V_19 ,
int V_17 ) {
T_6 V_25 = F_10 ( V_4 , V_24 ) ;
V_8 V_26 ;
T_1 V_27 [ V_13 ] ;
if ( V_25 < 0 )
V_26 = ( V_28 ) ( V_8 ) V_25 ;
else
V_26 = ( V_28 ) V_25 ;
if ( V_19 == V_21 ) {
int V_29 ;
for ( V_29 = 0 ; V_29 < V_17 ; V_29 ++ ) {
V_27 [ V_29 ] = ( V_26 & 0xff ) ;
V_26 >>= 8 ;
}
}
else {
int V_29 ;
for ( V_29 = V_17 - 1 ; V_29 >= 0 ; V_29 -- ) {
V_27 [ V_29 ] = ( V_26 & 0xff ) ;
V_26 >>= 8 ;
}
}
F_11 ( V_23 , V_27 , V_17 ) ;
}
static void F_12 ( T_1 * V_23 , int V_17 , int V_19 ) {
if ( V_19 != V_30 . V_19 ) {
int V_29 = 0 ;
while ( V_29 < -- V_17 ) {
T_1 V_31 = V_23 [ V_29 ] ;
V_23 [ V_29 ++ ] = V_23 [ V_17 ] ;
V_23 [ V_17 ] = V_31 ;
}
}
}
T_7 F_13 ( T_3 * V_4 ) {
#define F_14 1
#define F_15 2
T_5 V_23 ;
const char * V_1 = F_16 ( V_4 , F_14 ) ;
T_4 V_16 ;
int V_32 = 0 ;
int V_33 [ 10 ] ;
int V_24 = 2 ;
T_2 V_34 = 0 ;
F_17 ( & V_16 ) ;
F_18 ( V_4 ) ;
F_19 ( V_4 , & V_23 ) ;
while ( * V_1 != '\0' ) {
int V_5 = * V_1 ++ ;
T_2 V_17 = F_2 ( V_4 , V_5 , & V_1 ) ;
int V_35 = F_6 ( V_34 , & V_16 , V_5 , V_17 ) ;
V_34 += V_35 ;
while ( V_35 -- > 0 ) F_20 ( & V_23 , '\0' ) ;
if ( V_5 == 'X' ) V_17 = 0 ;
if ( V_16 . V_22 && V_17 ) V_5 = 'x' ;
switch ( V_5 ) {
case 'b' : case 'B' : case 'h' : case 'H' :
case 'l' : case 'L' : case 'T' : case 'i' : case 'I' : {
F_9 ( V_4 , & V_23 , V_24 ++ , V_16 . V_19 , ( int ) V_17 ) ;
break;
}
case 'e' : {
F_21 ( V_4 , & V_23 , V_24 ++ , V_16 . V_19 == V_21 ) ;
break;
}
case 'E' : {
F_22 ( V_4 , & V_23 , V_24 ++ , V_16 . V_19 == V_21 ) ;
break;
}
case 'x' : case 'X' : {
T_2 V_15 = V_17 ;
while ( V_15 -- > 0 )
F_20 ( & V_23 , '\0' ) ;
break;
}
case 'f' : {
V_9 V_36 = ( V_9 ) F_10 ( V_4 , V_24 ++ ) ;
F_12 ( ( T_1 * ) & V_36 , ( int ) V_17 , V_16 . V_19 ) ;
F_11 ( & V_23 , ( T_1 * ) & V_36 , V_17 ) ;
break;
}
case 'd' : {
V_10 V_37 = F_10 ( V_4 , V_24 ++ ) ;
F_12 ( ( T_1 * ) & V_37 , ( int ) V_17 , V_16 . V_19 ) ;
F_11 ( & V_23 , ( T_1 * ) & V_37 , V_17 ) ;
break;
}
case 'c' : case 's' : {
T_2 V_38 ;
const T_1 * V_39 = F_23 ( V_4 , V_24 ++ , & V_38 ) ;
if ( V_17 == 0 ) V_17 = V_38 ;
F_24 ( V_4 , V_38 >= ( T_2 ) V_17 , V_24 , L_5 ) ;
F_11 ( & V_23 , V_39 , V_17 ) ;
if ( V_5 == 's' ) {
F_20 ( & V_23 , '\0' ) ;
V_17 ++ ;
}
break;
}
case '=' : {
if ( V_32 < ( int ) ( sizeof( V_33 ) / sizeof( V_33 [ 0 ] ) ) )
V_33 [ V_32 ++ ] = ( int ) V_34 + 1 ;
break;
}
default: F_7 ( V_4 , V_5 , & V_1 , & V_16 ) ;
}
V_34 += V_17 ;
}
F_25 ( & V_23 ) ;
for ( V_24 = 0 ; V_24 < V_32 ; V_24 ++ )
F_26 ( V_4 , V_33 [ V_24 ] ) ;
F_27 ( V_32 + 1 ) ;
}
static T_6 F_28 ( const T_1 * V_27 , int V_19 ,
int V_40 , int V_17 ) {
T_8 V_38 = 0 ;
int V_29 ;
if ( V_19 == V_20 ) {
for ( V_29 = 0 ; V_29 < V_17 ; V_29 ++ ) {
V_38 <<= 8 ;
V_38 |= ( T_8 ) ( V_41 ) V_27 [ V_29 ] ;
}
}
else {
for ( V_29 = V_17 - 1 ; V_29 >= 0 ; V_29 -- ) {
V_38 <<= 8 ;
V_38 |= ( T_8 ) ( V_41 ) V_27 [ V_29 ] ;
}
}
if ( ! V_40 )
return ( T_6 ) V_38 ;
else {
T_8 V_42 = ( T_8 ) ( ~ ( ( T_8 ) 0 ) ) << ( V_17 * 8 - 1 ) ;
if ( V_38 & V_42 )
V_38 |= V_42 ;
return ( T_6 ) ( V_43 ) V_38 ;
}
}
T_7 F_29 ( T_3 * V_4 ) {
#define F_30 1
#define F_31 2
#define F_32 3
T_4 V_16 ;
const char * V_1 = F_16 ( V_4 , F_30 ) ;
T_2 V_44 ;
const char * V_45 = F_33 ( V_4 , F_31 , & V_44 ) ;
T_2 V_46 = F_34 ( V_4 , F_32 , 1 ) - 1 ;
F_17 ( & V_16 ) ;
F_35 ( V_4 , 2 ) ;
while ( * V_1 ) {
int V_5 = * V_1 ++ ;
T_2 V_17 = F_2 ( V_4 , V_5 , & V_1 ) ;
V_46 += F_6 ( V_46 , & V_16 , V_5 , V_17 ) ;
F_24 ( V_4 , V_46 + V_17 <= V_44 , 2 , L_6 ) ;
if ( V_5 == 'X' ) V_17 = 0 ;
if ( V_16 . V_22 && V_17 > 0 ) {
V_46 += V_17 ;
continue;
}
F_36 ( V_4 , 1 , L_7 ) ;
switch ( V_5 ) {
case 'b' : case 'B' : case 'h' : case 'H' :
case 'l' : case 'L' : case 'T' : case 'i' : case 'I' : {
int V_40 = islower ( V_5 ) ;
T_6 V_47 = F_28 ( V_45 + V_46 , V_16 . V_19 , V_40 , ( int ) V_17 ) ;
F_37 ( V_4 , V_47 ) ;
break;
}
case 'e' : {
F_38 ( V_4 , V_45 + V_46 , V_16 . V_19 == V_21 ) ;
break;
}
case 'E' : {
F_39 ( V_4 , V_45 + V_46 , V_16 . V_19 == V_21 ) ;
break;
}
case 'x' : case 'X' : {
break;
}
case 'f' : {
V_9 V_36 ;
memcpy ( & V_36 , V_45 + V_46 , V_17 ) ;
F_12 ( ( T_1 * ) & V_36 , sizeof( V_36 ) , V_16 . V_19 ) ;
F_37 ( V_4 , V_36 ) ;
break;
}
case 'd' : {
V_10 V_37 ;
memcpy ( & V_37 , V_45 + V_46 , V_17 ) ;
F_12 ( ( T_1 * ) & V_37 , sizeof( V_37 ) , V_16 . V_19 ) ;
F_37 ( V_4 , V_37 ) ;
break;
}
case 'c' : {
if ( V_17 == 0 ) {
if ( ! F_40 ( V_4 , - 1 ) )
F_3 ( V_4 , L_8 ) ;
V_17 = F_41 ( V_4 , - 1 ) ;
F_42 ( V_4 , 1 ) ;
F_24 ( V_4 , V_46 + V_17 <= V_44 , 2 , L_6 ) ;
}
if ( ! V_16 . V_22 )
F_43 ( V_4 , V_45 + V_46 , V_17 ) ;
break;
}
case 's' : {
const T_1 * V_48 = ( const char * ) memchr ( V_45 + V_46 , '\0' , V_44 - V_46 ) ;
if ( V_48 == NULL )
F_3 ( V_4 , L_9 ) ;
V_17 = ( V_48 - ( V_45 + V_46 ) ) + 1 ;
if ( ! V_16 . V_22 )
F_43 ( V_4 , V_45 + V_46 , V_17 - 1 ) ;
break;
}
case '=' : {
F_26 ( V_4 , V_46 + 1 ) ;
break;
}
default: F_7 ( V_4 , V_5 , & V_1 , & V_16 ) ;
}
V_46 += V_17 ;
}
F_26 ( V_4 , V_46 + 1 ) ;
F_27 ( F_44 ( V_4 ) - 2 ) ;
}
T_7 F_45 ( T_3 * V_4 ) {
#define F_46 1
T_4 V_16 ;
const T_1 * V_1 = F_16 ( V_4 , F_46 ) ;
T_2 V_46 = 0 ;
F_17 ( & V_16 ) ;
while ( * V_1 ) {
int V_5 = * V_1 ++ ;
T_2 V_17 = F_2 ( V_4 , V_5 , & V_1 ) ;
V_46 += F_6 ( V_46 , & V_16 , V_5 , V_17 ) ;
if ( V_5 == 's' )
F_5 ( V_4 , 1 , L_10 ) ;
else if ( V_5 == 'c' && V_17 == 0 )
F_5 ( V_4 , 1 , L_11 ) ;
if ( ! isalnum ( V_5 ) )
F_7 ( V_4 , V_5 , & V_1 , & V_16 ) ;
V_46 += V_17 ;
}
F_26 ( V_4 , V_46 ) ;
F_27 ( 1 ) ;
}
T_7 F_47 ( T_3 * V_4 ) {
#define F_48 1
T_4 V_16 ;
const T_1 * V_1 = F_16 ( V_4 , F_48 ) ;
T_2 V_49 = 0 ;
F_17 ( & V_16 ) ;
while ( * V_1 ) {
int V_5 = * V_1 ++ ;
T_2 V_17 = F_2 ( V_4 , V_5 , & V_1 ) ;
switch ( V_5 ) {
case 's' : case 'c' :
V_17 = 1 ;
break;
case 'x' : case 'X' :
V_17 = 0 ;
break;
default:
break;
}
if ( ! isalnum ( V_5 ) )
F_7 ( V_4 , V_5 , & V_1 , & V_16 ) ;
else if ( V_17 && ! V_16 . V_22 )
V_49 ++ ;
}
F_26 ( V_4 , V_49 ) ;
F_27 ( 1 ) ;
}
T_7 F_49 ( T_3 * V_4 ) {
#define F_50 1
#define F_51 2
#define F_52 3
const T_1 * V_39 = NULL ;
T_2 V_15 = 0 ;
T_9 V_50 = FALSE ;
const T_1 * V_51 = NULL ;
V_39 = F_23 ( V_4 , F_50 , & V_15 ) ;
if ( ! V_39 ) {
F_53 ( F_49 , V_52 , L_12 ) ;
return 0 ;
}
V_50 = F_54 ( V_4 , F_51 , FALSE ) ;
V_51 = F_55 ( V_4 , F_52 , NULL ) ;
F_56 ( V_4 , V_39 , ( V_53 ) V_15 , V_50 , V_51 ) ;
F_27 ( 1 ) ;
}
T_7 F_57 ( T_3 * V_4 ) {
#define F_58 1
#define F_59 2
const T_1 * V_39 = NULL ;
T_2 V_15 = 0 ;
const T_1 * V_51 = NULL ;
V_39 = F_33 ( V_4 , F_58 , & V_15 ) ;
if ( ! V_39 ) {
F_53 ( F_57 , V_54 , L_12 ) ;
return 0 ;
}
V_51 = F_55 ( V_4 , F_59 , NULL ) ;
F_60 ( V_4 , V_39 , ( V_53 ) V_15 , V_51 ) ;
F_27 ( 1 ) ;
}
static int F_61 ( T_3 * V_4 V_55 ) {
return 0 ;
}
T_10 int F_62 ( T_3 * V_4 ) {
F_63 ( Struct ) ;
return 0 ;
}
