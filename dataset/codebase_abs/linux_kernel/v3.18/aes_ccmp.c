static void F_1 ( unsigned char * V_1 , unsigned char * V_2 , unsigned char * V_3 )
{
unsigned long * V_4 = ( unsigned long * ) V_1 ;
unsigned long * V_5 = ( unsigned long * ) V_2 ;
unsigned long * V_6 = ( unsigned long * ) V_3 ;
( * V_6 ++ ) = ( * V_4 ++ ) ^ ( * V_5 ++ ) ;
( * V_6 ++ ) = ( * V_4 ++ ) ^ ( * V_5 ++ ) ;
( * V_6 ++ ) = ( * V_4 ++ ) ^ ( * V_5 ++ ) ;
( * V_6 ++ ) = ( * V_4 ++ ) ^ ( * V_5 ++ ) ;
}
static void F_2 ( unsigned char * V_1 , unsigned char * V_2 , unsigned char * V_3 )
{
unsigned long * V_4 = ( unsigned long * ) V_1 ;
unsigned long * V_5 = ( unsigned long * ) V_2 ;
unsigned long * V_6 = ( unsigned long * ) V_3 ;
( * V_6 ++ ) = ( * V_4 ++ ) ^ ( * V_5 ++ ) ;
}
static void F_3 ( unsigned char * V_7 , int V_8 )
{
unsigned char V_9 [ 4 ] ;
unsigned char V_10 [ 10 ] = { 0x01 , 0x02 , 0x04 , 0x08 , 0x10 , 0x20 , 0x40 , 0x80 , 0x1b , 0x36 } ;
V_9 [ 0 ] = V_11 [ V_7 [ 13 ] ] ;
V_9 [ 1 ] = V_11 [ V_7 [ 14 ] ] ;
V_9 [ 2 ] = V_11 [ V_7 [ 15 ] ] ;
V_9 [ 3 ] = V_11 [ V_7 [ 12 ] ] ;
V_7 [ 0 ] = V_7 [ 0 ] ^ V_10 [ V_8 ] ;
F_2 ( & V_7 [ 0 ] , V_9 , & V_7 [ 0 ] ) ;
F_2 ( & V_7 [ 4 ] , & V_7 [ 0 ] , & V_7 [ 4 ] ) ;
F_2 ( & V_7 [ 8 ] , & V_7 [ 4 ] , & V_7 [ 8 ] ) ;
F_2 ( & V_7 [ 12 ] , & V_7 [ 8 ] , & V_7 [ 12 ] ) ;
}
static void F_4 ( unsigned char * V_12 , unsigned char * V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
V_3 [ V_13 ] = V_11 [ V_12 [ V_13 ] ] ;
}
static void F_5 ( unsigned char * V_12 , unsigned char * V_3 )
{
V_3 [ 0 ] = V_12 [ 0 ] ;
V_3 [ 1 ] = V_12 [ 5 ] ;
V_3 [ 2 ] = V_12 [ 10 ] ;
V_3 [ 3 ] = V_12 [ 15 ] ;
V_3 [ 4 ] = V_12 [ 4 ] ;
V_3 [ 5 ] = V_12 [ 9 ] ;
V_3 [ 6 ] = V_12 [ 14 ] ;
V_3 [ 7 ] = V_12 [ 3 ] ;
V_3 [ 8 ] = V_12 [ 8 ] ;
V_3 [ 9 ] = V_12 [ 13 ] ;
V_3 [ 10 ] = V_12 [ 2 ] ;
V_3 [ 11 ] = V_12 [ 7 ] ;
V_3 [ 12 ] = V_12 [ 12 ] ;
V_3 [ 13 ] = V_12 [ 1 ] ;
V_3 [ 14 ] = V_12 [ 6 ] ;
V_3 [ 15 ] = V_12 [ 11 ] ;
}
static void F_6 ( unsigned char * V_12 , unsigned char * V_3 )
{
V_3 [ 0 ] = V_14 [ V_12 [ 0 ] ] ^ V_15 [ V_12 [ 1 ] ] ^ V_12 [ 2 ] ^ V_12 [ 3 ] ;
V_3 [ 1 ] = V_12 [ 0 ] ^ V_14 [ V_12 [ 1 ] ] ^ V_15 [ V_12 [ 2 ] ] ^ V_12 [ 3 ] ;
V_3 [ 2 ] = V_12 [ 0 ] ^ V_12 [ 1 ] ^ V_14 [ V_12 [ 2 ] ] ^ V_15 [ V_12 [ 3 ] ] ;
V_3 [ 3 ] = V_15 [ V_12 [ 0 ] ] ^ V_12 [ 1 ] ^ V_12 [ 2 ] ^ V_14 [ V_12 [ 3 ] ] ;
}
static void F_7 ( unsigned char * V_7 , unsigned char * V_16 , unsigned char * V_17 )
{
int V_13 ;
int V_8 ;
unsigned char V_18 [ 16 ] ;
unsigned char V_19 [ 16 ] ;
unsigned char V_20 [ 16 ] ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 ++ )
V_20 [ V_13 ] = V_7 [ V_13 ] ;
for ( V_8 = 0 ; V_8 < 11 ; V_8 ++ ) {
if ( V_8 == 0 ) {
F_1 ( V_20 , V_16 , V_17 ) ;
F_3 ( V_20 , V_8 ) ;
} else if ( V_8 == 10 ) {
F_4 ( V_17 , V_18 ) ;
F_5 ( V_18 , V_19 ) ;
F_1 ( V_19 , V_20 , V_17 ) ;
} else {
F_4 ( V_17 , V_18 ) ;
F_5 ( V_18 , V_19 ) ;
F_6 ( & V_19 [ 0 ] , & V_18 [ 0 ] ) ;
F_6 ( & V_19 [ 4 ] , & V_18 [ 4 ] ) ;
F_6 ( & V_19 [ 8 ] , & V_18 [ 8 ] ) ;
F_6 ( & V_19 [ 12 ] , & V_18 [ 12 ] ) ;
F_1 ( V_18 , V_20 , V_17 ) ;
F_3 ( V_20 , V_8 ) ;
}
}
}
bool F_8 ( unsigned char * V_21 , unsigned char * V_22 , unsigned short V_23 )
{
unsigned char V_24 [ 13 ] ;
unsigned char V_25 [ 16 ] ;
unsigned char V_26 [ 16 ] ;
unsigned char V_27 [ 16 ] ;
unsigned char V_28 [ 16 ] ;
unsigned char V_29 [ 16 ] ;
unsigned char V_30 [ 16 ] ;
unsigned char V_31 [ 16 ] ;
unsigned char V_32 [ 16 ] ;
T_1 V_33 = ( T_1 ) V_22 ;
unsigned char * V_34 ;
unsigned char * V_35 ;
unsigned short V_36 = 22 ;
unsigned short V_37 = V_23 - 8 - 8 - 4 - V_38 ;
bool V_39 = false ;
unsigned char V_40 ;
unsigned short V_41 ;
int V_42 , V_43 , V_44 ;
V_34 = V_22 + V_38 ;
if ( F_9 ( * ( unsigned short * ) V_22 ) &&
F_10 ( * ( unsigned short * ) V_22 ) ) {
V_39 = true ;
V_34 += 6 ;
V_36 += 6 ;
V_37 -= 6 ;
}
V_35 = V_34 + 8 ;
V_24 [ 0 ] = 0x00 ;
memcpy ( & ( V_24 [ 1 ] ) , V_33 -> V_45 , V_46 ) ;
V_24 [ 7 ] = V_34 [ 7 ] ;
V_24 [ 8 ] = V_34 [ 6 ] ;
V_24 [ 9 ] = V_34 [ 5 ] ;
V_24 [ 10 ] = V_34 [ 4 ] ;
V_24 [ 11 ] = V_34 [ 1 ] ;
V_24 [ 12 ] = V_34 [ 0 ] ;
V_25 [ 0 ] = 0x59 ;
memcpy ( & ( V_25 [ 1 ] ) , & ( V_24 [ 0 ] ) , 13 ) ;
V_25 [ 14 ] = ( unsigned char ) ( V_37 >> 8 ) ;
V_25 [ 15 ] = ( unsigned char ) ( V_37 & 0xff ) ;
V_26 [ 0 ] = ( unsigned char ) ( V_36 >> 8 ) ;
V_26 [ 1 ] = ( unsigned char ) ( V_36 & 0xff ) ;
V_40 = ( unsigned char ) ( V_33 -> V_47 & 0xff ) ;
V_26 [ 2 ] = V_40 & 0x8f ;
V_40 = ( unsigned char ) ( V_33 -> V_47 >> 8 ) ;
V_40 &= 0x87 ;
V_26 [ 3 ] = V_40 | 0x40 ;
memcpy ( & ( V_26 [ 4 ] ) , V_33 -> V_48 , V_46 ) ;
memcpy ( & ( V_26 [ 10 ] ) , V_33 -> V_45 , V_46 ) ;
memcpy ( & ( V_27 [ 0 ] ) , V_33 -> V_49 , V_46 ) ;
V_40 = ( unsigned char ) ( V_33 -> V_50 & 0xff ) ;
V_27 [ 6 ] = V_40 & 0x0f ;
V_27 [ 7 ] = 0 ;
if ( V_39 ) {
memcpy ( & ( V_27 [ 8 ] ) , V_33 -> V_51 , V_46 ) ;
} else {
V_27 [ 8 ] = 0x00 ;
V_27 [ 9 ] = 0x00 ;
V_27 [ 10 ] = 0x00 ;
V_27 [ 11 ] = 0x00 ;
V_27 [ 12 ] = 0x00 ;
V_27 [ 13 ] = 0x00 ;
}
V_27 [ 14 ] = 0x00 ;
V_27 [ 15 ] = 0x00 ;
F_7 ( V_21 , V_25 , V_28 ) ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_30 [ V_44 ] = V_26 [ V_44 ] ^ V_28 [ V_44 ] ;
F_7 ( V_21 , V_30 , V_28 ) ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_30 [ V_44 ] = V_27 [ V_44 ] ^ V_28 [ V_44 ] ;
F_7 ( V_21 , V_30 , V_28 ) ;
V_41 = 1 ;
V_29 [ 0 ] = 0x01 ;
memcpy ( & ( V_29 [ 1 ] ) , & ( V_24 [ 0 ] ) , 13 ) ;
for ( V_43 = V_37 ; V_43 > 16 ; V_43 = V_43 - 16 ) {
V_29 [ 14 ] = ( unsigned char ) ( V_41 >> 8 ) ;
V_29 [ 15 ] = ( unsigned char ) ( V_41 & 0xff ) ;
F_7 ( V_21 , V_29 , V_30 ) ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_31 [ V_44 ] = V_30 [ V_44 ] ^ V_35 [ V_44 ] ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_30 [ V_44 ] = V_28 [ V_44 ] ^ V_31 [ V_44 ] ;
F_7 ( V_21 , V_30 , V_28 ) ;
memcpy ( V_35 , V_31 , 16 ) ;
V_41 ++ ;
V_35 += 16 ;
}
memcpy ( & ( V_32 [ 0 ] ) , V_35 , V_43 ) ;
for ( V_42 = V_43 ; V_42 < 16 ; V_42 ++ )
V_32 [ V_42 ] = 0x00 ;
V_29 [ 14 ] = ( unsigned char ) ( V_41 >> 8 ) ;
V_29 [ 15 ] = ( unsigned char ) ( V_41 & 0xff ) ;
F_7 ( V_21 , V_29 , V_30 ) ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_31 [ V_44 ] = V_30 [ V_44 ] ^ V_32 [ V_44 ] ;
memcpy ( V_35 , V_31 , V_43 ) ;
V_35 += V_43 ;
for ( V_42 = V_43 ; V_42 < 16 ; V_42 ++ )
V_31 [ V_42 ] = 0x00 ;
for ( V_44 = 0 ; V_44 < 16 ; V_44 ++ )
V_30 [ V_44 ] = V_28 [ V_44 ] ^ V_31 [ V_44 ] ;
F_7 ( V_21 , V_30 , V_28 ) ;
V_41 = 0 ;
V_29 [ 14 ] = ( unsigned char ) ( V_41 >> 8 ) ;
V_29 [ 15 ] = ( unsigned char ) ( V_41 & 0xff ) ;
F_7 ( V_21 , V_29 , V_30 ) ;
for ( V_44 = 0 ; V_44 < 8 ; V_44 ++ )
V_30 [ V_44 ] = V_30 [ V_44 ] ^ V_35 [ V_44 ] ;
return ! memcmp ( V_28 , V_30 , 8 ) ;
}
