static void F_1 ( void )
{
unsigned long V_1 , V_2 , V_3 , V_4 , V_5 , V_6 ;
unsigned long V_7 , V_8 , V_9 , V_10 , V_11 ;
unsigned long V_12 , V_13 , V_14 , V_15 ;
unsigned long div ;
unsigned long V_16 ;
unsigned short V_17 ;
unsigned long V_18 ;
unsigned short V_19 ;
unsigned short V_20 ;
unsigned long V_21 ;
unsigned long V_22 ;
void * V_23 ;
V_1 = ( F_2 ( ( unsigned char * ) 0x80000000 ) == 0xc ) ? 66666666 : 33333000 ;
V_2 = F_3 ( V_24 ) ;
V_3 = F_3 ( V_25 ) ;
V_7 = ( ( V_2 & V_26 ) >> 16 ) ;
V_8 = ( ( V_2 & V_27 ) >> 8 ) ;
if ( V_8 == 0 )
V_8 = 8 ;
V_9 = ( ( V_2 & V_28 ) >> 24 ) ;
if ( V_9 == 0 )
V_9 = 256 ;
V_4 = F_3 ( V_29 ) ;
V_10 = ( ( V_4 & V_30 ) >> 16 ) ;
if ( V_10 == 0 )
V_10 = 16 ;
V_11 = ( V_4 & V_31 ) ;
if ( V_11 == 0 )
V_11 = 16 ;
V_12 = ( ( V_4 & V_32 ) >> 8 ) ;
if ( V_12 == 0 )
V_12 = 16 ;
V_15 = ( V_1 * V_9 ) / V_12 ;
V_13 = ( V_1 * V_9 ) / V_11 ;
V_5 = ( ( V_1 * ( ( V_3 & V_33 ) ?
V_8 : V_7 ) *
V_9 ) / V_8 ) ;
V_23 = F_4 ( L_1 ) ;
if ( F_5 ( V_23 , L_2 , & V_22 , sizeof( V_22 ) ) != sizeof( V_22 ) )
F_6 ( L_3 ) ;
V_18 = 256 ;
div = V_5 / ( 16 * V_22 ) ;
V_16 = ( V_5 / V_15 ) << 1 ;
V_17 = 256 ;
for ( V_6 = 256 ; V_6 > V_16 ; V_6 -- ) {
V_20 = div / V_6 ;
V_21 = V_6 * V_20 ;
V_19 = ( V_21 > div ) ? ( V_21 - div ) : ( div - V_21 ) ;
if ( V_19 == 0 ) {
V_18 = V_6 ;
break;
} else if ( V_19 < V_17 ) {
V_18 = V_6 ;
V_17 = V_19 ;
}
}
V_14 = V_5 / V_18 ;
F_7 ( V_34 . V_35 , V_34 . V_36 , V_34 . V_37 ) ;
F_8 ( L_4 , V_13 ) ;
F_8 ( L_5 , V_15 ) ;
F_8 ( L_6 , V_14 ) ;
F_8 ( L_7 , V_14 ) ;
}
static void F_9 ( void )
{
F_10 ( V_34 . V_38 , V_34 . V_39 ) ;
F_1 () ;
F_11 ( L_8 , V_34 . V_40 ) ;
}
void F_12 ( unsigned long V_41 , unsigned long V_42 , unsigned long V_43 ,
unsigned long V_44 , unsigned long V_45 )
{
F_13 () ;
V_46 . V_47 = F_9 ;
V_46 . exit = V_48 ;
F_14 ( V_49 ) ;
F_15 () ;
}
