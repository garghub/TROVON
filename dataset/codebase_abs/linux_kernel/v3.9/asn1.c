static void
F_1 ( struct V_1 * V_2 , unsigned char * V_3 , unsigned int V_4 )
{
V_2 -> V_5 = V_3 ;
V_2 -> V_6 = V_3 + V_4 ;
V_2 -> V_7 = V_3 ;
V_2 -> error = V_8 ;
}
static unsigned char
F_2 ( struct V_1 * V_2 , unsigned char * V_9 )
{
if ( V_2 -> V_7 >= V_2 -> V_6 ) {
V_2 -> error = V_10 ;
return 0 ;
}
* V_9 = * ( V_2 -> V_7 ) ++ ;
return 1 ;
}
static unsigned char
F_3 ( struct V_1 * V_2 , unsigned int * V_11 )
{
unsigned char V_9 ;
* V_11 = 0 ;
do {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_11 <<= 7 ;
* V_11 |= V_9 & 0x7F ;
} while ( ( V_9 & 0x80 ) == 0x80 );
return 1 ;
}
static unsigned char
F_4 ( struct V_1 * V_2 ,
unsigned int * V_12 , unsigned int * V_13 , unsigned int * V_11 )
{
unsigned char V_9 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_12 = ( V_9 & 0xC0 ) >> 6 ;
* V_13 = ( V_9 & 0x20 ) >> 5 ;
* V_11 = ( V_9 & 0x1F ) ;
if ( * V_11 == 0x1F ) {
if ( ! F_3 ( V_2 , V_11 ) )
return 0 ;
}
return 1 ;
}
static unsigned char
F_5 ( struct V_1 * V_2 , unsigned int * V_14 , unsigned int * V_4 )
{
unsigned char V_9 , V_15 ;
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
if ( V_9 == 0x80 )
* V_14 = 0 ;
else {
* V_14 = 1 ;
if ( V_9 < 0x80 )
* V_4 = V_9 ;
else {
V_15 = ( unsigned char ) ( V_9 & 0x7F ) ;
* V_4 = 0 ;
while ( V_15 > 0 ) {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_4 <<= 8 ;
* V_4 |= V_9 ;
V_15 -- ;
}
}
}
if ( * V_4 > V_2 -> V_6 - V_2 -> V_7 )
return 0 ;
return 1 ;
}
static unsigned char
F_6 ( struct V_1 * V_2 ,
unsigned char * * V_16 ,
unsigned int * V_12 , unsigned int * V_13 , unsigned int * V_11 )
{
unsigned int V_14 = 0 ;
unsigned int V_4 = 0 ;
if ( ! F_4 ( V_2 , V_12 , V_13 , V_11 ) )
return 0 ;
if ( ! F_5 ( V_2 , & V_14 , & V_4 ) )
return 0 ;
if ( * V_13 == V_17 && ! V_14 )
return 0 ;
if ( V_14 )
* V_16 = V_2 -> V_7 + V_4 ;
else
* V_16 = NULL ;
return 1 ;
}
static unsigned char
F_7 ( struct V_1 * V_2 , unsigned char * V_16 )
{
unsigned char V_9 ;
if ( V_16 == NULL ) {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
if ( V_9 != 0x00 ) {
V_2 -> error = V_18 ;
return 0 ;
}
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
if ( V_9 != 0x00 ) {
V_2 -> error = V_18 ;
return 0 ;
}
return 1 ;
} else {
if ( V_2 -> V_7 != V_16 ) {
V_2 -> error = V_19 ;
return 0 ;
}
return 1 ;
}
}
static unsigned char
F_8 ( struct V_1 * V_2 , unsigned long * V_20 )
{
unsigned char V_9 ;
* V_20 = 0 ;
do {
if ( ! F_2 ( V_2 , & V_9 ) )
return 0 ;
* V_20 <<= 7 ;
* V_20 |= V_9 & 0x7F ;
} while ( ( V_9 & 0x80 ) == 0x80 );
return 1 ;
}
static int
F_9 ( struct V_1 * V_2 ,
unsigned char * V_16 , unsigned long * * V_21 , unsigned int * V_4 )
{
unsigned long V_20 ;
unsigned int V_22 ;
unsigned long * V_23 ;
V_22 = V_16 - V_2 -> V_7 + 1 ;
if ( V_22 < 2 || V_22 > V_24 /sizeof( unsigned long ) )
return 0 ;
* V_21 = F_10 ( V_22 * sizeof( unsigned long ) , V_25 ) ;
if ( * V_21 == NULL )
return 0 ;
V_23 = * V_21 ;
if ( ! F_8 ( V_2 , & V_20 ) ) {
F_11 ( * V_21 ) ;
* V_21 = NULL ;
return 0 ;
}
if ( V_20 < 40 ) {
V_23 [ 0 ] = 0 ;
V_23 [ 1 ] = V_20 ;
} else if ( V_20 < 80 ) {
V_23 [ 0 ] = 1 ;
V_23 [ 1 ] = V_20 - 40 ;
} else {
V_23 [ 0 ] = 2 ;
V_23 [ 1 ] = V_20 - 80 ;
}
* V_4 = 2 ;
V_23 += 2 ;
while ( V_2 -> V_7 < V_16 ) {
if ( ++ ( * V_4 ) > V_22 ) {
V_2 -> error = V_26 ;
F_11 ( * V_21 ) ;
* V_21 = NULL ;
return 0 ;
}
if ( ! F_8 ( V_2 , V_23 ++ ) ) {
F_11 ( * V_21 ) ;
* V_21 = NULL ;
return 0 ;
}
}
return 1 ;
}
static int
F_12 ( unsigned long * V_27 , unsigned int V_28 ,
unsigned long * V_29 , unsigned int V_30 )
{
unsigned int V_31 ;
if ( V_28 != V_30 )
return 0 ;
else {
for ( V_31 = 0 ; V_31 < V_28 ; V_31 ++ ) {
if ( V_27 [ V_31 ] != V_29 [ V_31 ] )
return 0 ;
}
return 1 ;
}
}
int
F_13 ( unsigned char * V_32 , int V_33 ,
struct V_34 * V_35 )
{
struct V_1 V_2 ;
unsigned char * V_6 ;
unsigned char * V_36 ;
unsigned long * V_21 = NULL ;
unsigned int V_12 , V_13 , V_11 , V_37 , V_38 ;
F_1 ( & V_2 , V_32 , V_33 ) ;
if ( F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) == 0 ) {
F_14 ( 1 , L_1 ) ;
return 0 ;
} else if ( ( V_12 != V_39 ) || ( V_13 != V_40 )
|| ( V_11 != V_41 ) ) {
F_14 ( 1 , L_2 , V_12 , V_13 , V_11 ) ;
return 0 ;
}
V_38 = F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) ;
if ( V_38 ) {
if ( ( V_11 == V_42 ) && ( V_13 == V_17 ) &&
( V_12 == V_43 ) ) {
V_38 = F_9 ( & V_2 , V_6 , & V_21 , & V_37 ) ;
if ( V_38 ) {
V_38 = F_12 ( V_21 , V_37 , V_44 ,
V_45 ) ;
F_11 ( V_21 ) ;
}
} else
V_38 = 0 ;
}
if ( ! V_38 ) {
F_14 ( 1 , L_1 ) ;
return 0 ;
}
if ( F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) == 0 ) {
F_14 ( 1 , L_3 ) ;
return 0 ;
} else if ( ( V_12 != V_46 ) || ( V_13 != V_40 )
|| ( V_11 != V_41 ) ) {
F_14 ( 1 , L_4 ,
V_12 , V_13 , V_11 , V_6 , * V_6 ) ;
return 0 ;
}
if ( F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) == 0 ) {
F_14 ( 1 , L_3 ) ;
return 0 ;
} else if ( ( V_12 != V_43 ) || ( V_13 != V_40 )
|| ( V_11 != V_47 ) ) {
F_14 ( 1 , L_5 ,
V_12 , V_13 , V_11 , V_6 , * V_6 ) ;
return 0 ;
}
if ( F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) == 0 ) {
F_14 ( 1 , L_6 ) ;
return 0 ;
} else if ( ( V_12 != V_46 ) || ( V_13 != V_40 )
|| ( V_11 != V_41 ) ) {
F_14 ( 1 , L_4 ,
V_12 , V_13 , V_11 , V_6 , * V_6 ) ;
return 0 ;
}
if ( F_6
( & V_2 , & V_36 , & V_12 , & V_13 , & V_11 ) == 0 ) {
F_14 ( 1 , L_6 ) ;
return 0 ;
} else if ( ( V_12 != V_43 ) || ( V_13 != V_40 )
|| ( V_11 != V_47 ) ) {
F_14 ( 1 , L_5 ,
V_12 , V_13 , V_11 , V_6 , * V_6 ) ;
return 0 ;
}
while ( ! F_7 ( & V_2 , V_36 ) ) {
V_38 = F_6 ( & V_2 , & V_6 , & V_12 , & V_13 , & V_11 ) ;
if ( ! V_38 ) {
F_14 ( 1 , L_7 ) ;
return 0 ;
}
if ( ( V_11 == V_42 ) && ( V_13 == V_17 ) ) {
if ( F_9 ( & V_2 , V_6 , & V_21 , & V_37 ) ) {
F_14 ( 1 , L_8
L_9 , V_37 , * V_21 ,
* ( V_21 + 1 ) , * ( V_21 + 2 ) , * ( V_21 + 3 ) ) ;
if ( F_12 ( V_21 , V_37 , V_48 ,
V_49 ) )
V_35 -> V_50 = true ;
else if ( F_12 ( V_21 , V_37 , V_51 ,
V_52 ) )
V_35 -> V_53 = true ;
else if ( F_12 ( V_21 , V_37 , V_54 ,
V_55 ) )
V_35 -> V_56 = true ;
else if ( F_12 ( V_21 , V_37 , V_57 ,
V_58 ) )
V_35 -> V_59 = true ;
F_11 ( V_21 ) ;
}
} else {
F_14 ( 1 , L_10 ) ;
}
}
return 1 ;
}
