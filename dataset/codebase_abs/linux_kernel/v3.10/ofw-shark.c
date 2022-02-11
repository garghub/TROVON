T_1 void
F_1 ( unsigned long * V_1 )
{
struct V_2 * V_2 = (struct V_2 * ) 0x08003000 ;
int V_3 , V_4 , V_5 , V_6 , V_7 , V_8 ;
unsigned char * V_9 ;
V_6 = 0 ;
V_2 -> V_10 . V_2 = V_11 ;
V_2 -> V_10 . V_8 = F_2 ( V_12 ) ;
V_2 -> V_13 . V_14 . V_15 = 1 ;
V_2 -> V_13 . V_14 . V_16 = V_17 ;
V_2 -> V_13 . V_14 . V_18 = 0 ;
V_8 = 0 ;
V_7 = ( unsigned int ) V_1 [ 0 ] ;
for ( V_3 = 0 ; V_3 < V_7 ; V_3 ++ ) {
V_5 = 0xffffffff ;
for ( V_4 = 0 ; V_4 < ( unsigned int ) V_1 [ 0 ] ; V_4 ++ ) {
if ( V_1 [ 2 * V_4 + 1 ] < V_5 ) {
V_5 = V_1 [ 2 * V_4 + 1 ] ;
V_6 = V_4 ;
}
}
V_2 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_2 = V_19 ;
V_2 -> V_10 . V_8 = F_2 ( V_20 ) ;
V_2 -> V_13 . V_21 . V_8 = V_1 [ 2 * V_6 + 2 ] ;
V_2 -> V_13 . V_21 . V_22 = V_1 [ 2 * V_6 + 1 ] ;
V_8 += V_1 [ 2 * V_6 + 2 ] ;
V_1 [ 2 * V_6 + 1 ] = 0xffffffff ;
}
V_2 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_2 = V_23 ;
V_9 = ( unsigned char * ) ( & V_1 [ 34 ] ) ;
V_3 = 0 ;
while ( * V_9 ) V_2 -> V_13 . V_24 . V_24 [ V_3 ++ ] = * V_9 ++ ;
V_2 -> V_13 . V_24 . V_24 [ V_3 ] = 0 ;
V_2 -> V_10 . V_8 = ( V_3 + 7 + sizeof( struct V_25 ) ) >> 2 ;
V_2 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_2 = V_26 ;
V_2 -> V_10 . V_8 = F_2 ( V_27 ) ;
V_2 -> V_13 . V_28 . V_29 = ( ( unsigned char ) V_1 [ 33 ] ) - '0' ;
V_2 = F_3 ( V_2 ) ;
V_2 -> V_10 . V_2 = 0 ;
V_2 -> V_10 . V_8 = 0 ;
}
int
F_4 ( const unsigned char * V_30 )
{
unsigned int V_4 = * V_30 ++ << 8 ;
V_4 = ( V_4 + * V_30 ++ ) << 8 ;
V_4 = ( V_4 + * V_30 ++ ) << 8 ;
return ( V_4 + * V_30 ) ;
}
int
F_5 ( T_2 V_31 , char * V_32 )
{
unsigned int args [ 8 ] ;
char V_33 [ 12 ] ;
V_33 [ 0 ] = 'f' ;
V_33 [ 1 ] = 'i' ;
V_33 [ 2 ] = 'n' ;
V_33 [ 3 ] = 'd' ;
V_33 [ 4 ] = 'd' ;
V_33 [ 5 ] = 'e' ;
V_33 [ 6 ] = 'v' ;
V_33 [ 7 ] = 'i' ;
V_33 [ 8 ] = 'c' ;
V_33 [ 9 ] = 'e' ;
V_33 [ 10 ] = '\0' ;
args [ 0 ] = ( unsigned int ) V_33 ;
args [ 1 ] = 1 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_32 ;
if ( V_31 ( args ) == - 1 )
return - 1 ;
return args [ 4 ] ;
}
int
F_6 ( T_2 V_31 , int V_34 , char * V_35 )
{
unsigned int args [ 8 ] ;
char V_33 [ 12 ] ;
V_33 [ 0 ] = 'g' ;
V_33 [ 1 ] = 'e' ;
V_33 [ 2 ] = 't' ;
V_33 [ 3 ] = 'p' ;
V_33 [ 4 ] = 'r' ;
V_33 [ 5 ] = 'o' ;
V_33 [ 6 ] = 'p' ;
V_33 [ 7 ] = 'l' ;
V_33 [ 8 ] = 'e' ;
V_33 [ 9 ] = 'n' ;
V_33 [ 10 ] = '\0' ;
args [ 0 ] = ( unsigned int ) V_33 ;
args [ 1 ] = 2 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_34 ;
args [ 4 ] = ( unsigned int ) V_35 ;
if ( V_31 ( args ) == - 1 )
return - 1 ;
return args [ 5 ] ;
}
int
F_7 ( T_2 V_31 , int V_34 , char * V_35 , void * V_36 , unsigned int V_37 )
{
unsigned int args [ 8 ] ;
char V_33 [ 8 ] ;
V_33 [ 0 ] = 'g' ;
V_33 [ 1 ] = 'e' ;
V_33 [ 2 ] = 't' ;
V_33 [ 3 ] = 'p' ;
V_33 [ 4 ] = 'r' ;
V_33 [ 5 ] = 'o' ;
V_33 [ 6 ] = 'p' ;
V_33 [ 7 ] = '\0' ;
args [ 0 ] = ( unsigned int ) V_33 ;
args [ 1 ] = 4 ;
args [ 2 ] = 1 ;
args [ 3 ] = ( unsigned int ) V_34 ;
args [ 4 ] = ( unsigned int ) V_35 ;
args [ 5 ] = ( unsigned int ) V_36 ;
args [ 6 ] = V_37 ;
if ( V_31 ( args ) == - 1 )
return - 1 ;
return args [ 7 ] ;
}
T_1 void F_8 ( T_2 V_38 , int * V_39 , int * V_40 )
{
int V_41 , V_4 , V_42 , V_1 [ 32 ] ;
char V_43 [ 15 ] ;
V_43 [ 0 ] = '/' ;
V_43 [ 1 ] = 'm' ;
V_43 [ 2 ] = 'e' ;
V_43 [ 3 ] = 'm' ;
V_43 [ 4 ] = 'o' ;
V_43 [ 5 ] = 'r' ;
V_43 [ 6 ] = 'y' ;
V_43 [ 7 ] = '\0' ;
V_41 = F_5 ( V_38 , V_43 ) ;
V_43 [ 0 ] = 'r' ;
V_43 [ 1 ] = 'e' ;
V_43 [ 2 ] = 'g' ;
V_43 [ 3 ] = '\0' ;
V_42 = F_6 ( V_38 , V_41 , V_43 ) ;
F_7 ( V_38 , V_41 , V_43 , V_1 , V_42 ) ;
* V_39 = V_42 >> 3 ;
for ( V_4 = 0 ; V_4 <= V_42 / 4 ; V_4 ++ ) V_40 [ V_4 ] = F_4 ( ( const unsigned char * ) & V_1 [ V_4 ] ) ;
V_43 [ 0 ] = '/' ;
V_43 [ 1 ] = 'c' ;
V_43 [ 2 ] = 'h' ;
V_43 [ 3 ] = 'o' ;
V_43 [ 4 ] = 's' ;
V_43 [ 5 ] = 'e' ;
V_43 [ 6 ] = 'n' ;
V_43 [ 7 ] = '\0' ;
V_41 = F_5 ( V_38 , V_43 ) ;
V_43 [ 0 ] = 'b' ;
V_43 [ 1 ] = 'o' ;
V_43 [ 2 ] = 'o' ;
V_43 [ 3 ] = 't' ;
V_43 [ 4 ] = 'a' ;
V_43 [ 5 ] = 'r' ;
V_43 [ 6 ] = 'g' ;
V_43 [ 7 ] = 's' ;
V_43 [ 8 ] = '\0' ;
V_42 = F_6 ( V_38 , V_41 , V_43 ) ;
F_7 ( V_38 , V_41 , V_43 , V_1 , V_42 ) ;
if ( V_42 > 128 ) V_42 = 128 ;
for ( V_4 = 0 ; V_4 <= V_42 / 4 ; V_4 ++ ) V_40 [ V_4 + 33 ] = V_1 [ V_4 ] ;
V_40 [ V_4 + 33 ] = 0 ;
V_43 [ 0 ] = '/' ;
V_43 [ 1 ] = '\0' ;
V_41 = F_5 ( V_38 , V_43 ) ;
V_43 [ 0 ] = 'b' ;
V_43 [ 1 ] = 'a' ;
V_43 [ 2 ] = 'n' ;
V_43 [ 3 ] = 'n' ;
V_43 [ 4 ] = 'e' ;
V_43 [ 5 ] = 'r' ;
V_43 [ 6 ] = '-' ;
V_43 [ 7 ] = 'n' ;
V_43 [ 8 ] = 'a' ;
V_43 [ 9 ] = 'm' ;
V_43 [ 10 ] = 'e' ;
V_43 [ 11 ] = '\0' ;
V_42 = F_6 ( V_38 , V_41 , V_43 ) ;
F_7 ( V_38 , V_41 , V_43 , V_1 , V_42 ) ;
* ( ( unsigned char * ) & V_40 [ 32 ] ) = ( ( unsigned char * ) V_1 ) [ V_42 - 2 ] ;
}
