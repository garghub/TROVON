T_1 F_1 ( void )
{
T_2 V_1 = F_2 () ;
unsigned long V_2 ;
if ( ! ( V_1 & V_3 ) )
return 0 ;
V_2 = F_3 () ;
return ( V_2 & V_4 ) << ( 36 - 32 ) ;
}
T_1 F_4 ( void )
{
T_2 V_5 ;
V_5 = F_5 () ;
if ( V_5 & V_6 )
return V_5 & V_7 ;
return F_6 () + V_8 ;
}
static void F_7 ( void )
{
unsigned V_9 ;
T_1 V_10 ;
V_9 = ( F_8 () & V_11 ) >>
V_12 ;
if ( V_9 < 6 )
return;
V_10 = F_9 () ;
F_10 ( ( V_10 & V_7 ) != V_10 ) ;
if ( ! V_10 )
return;
F_11 ( V_10 | V_6 ) ;
V_13 = F_12 ( V_10 , V_14 ) ;
}
int F_13 ( void )
{
T_1 V_10 ;
T_2 V_5 ;
if ( V_15 )
return 0 ;
V_10 = F_6 () ;
F_10 ( ( V_10 & V_16 ) != V_10 ) ;
if ( ! V_10 )
return - V_17 ;
V_15 = F_12 ( V_10 , V_8 ) ;
if ( ! V_15 )
return - V_18 ;
V_5 = F_14 () ;
if ( ( V_5 & V_16 ) != V_10 ) {
F_15 ( L_1 ,
( unsigned long ) V_10 ) ;
V_15 = NULL ;
return - V_17 ;
}
V_5 &= ~ V_19 ;
V_5 |= V_20 ;
F_16 ( V_5 ) ;
F_17 ( V_21 ) ;
F_18 ( V_22 ) ;
F_19 ( V_21 ) ;
F_20 ( V_22 ) ;
F_21 ( V_21 ) ;
F_22 ( V_22 ) ;
F_23 ( V_21 ) ;
F_24 ( V_22 ) ;
F_7 () ;
V_23 = F_25 ( V_24 ) && ( F_26 () >= V_25 ) ;
return 0 ;
}
void F_27 ( void )
{
unsigned long V_26 = F_26 () ;
T_3 V_27 = F_28 () ;
int V_28 = V_29 +
( ( V_26 >= V_25 ) ? 31 : 0 ) ;
unsigned long V_30 = F_29 () ;
unsigned long V_31 = F_30 () ;
int V_32 , V_33 ;
char V_34 [ 256 ] ;
if ( ! F_31 () )
return;
V_33 = V_27 >> V_28 ;
if ( ! V_33 )
return;
V_32 = V_31 >> V_35 ;
if ( V_26 < V_25 ) {
if ( V_33 < 16 ) {
unsigned long V_36 = ( V_27 >> 15 ) & 7 ;
unsigned long V_37 = ( V_27 >> 12 ) & 7 ;
unsigned long V_38 = ( V_27 >> 7 ) & 0x1f ;
unsigned long V_39 = ( V_27 >> 3 ) & 15 ;
unsigned long V_40 = ( V_27 >> 0 ) & 7 ;
snprintf ( V_34 , sizeof( V_34 ) ,
L_2
L_3 , V_36 , V_41 [ V_37 ] ,
V_42 [ V_38 ] , V_39 , V_40 ) ;
} else {
unsigned long V_43 = ( V_27 >> 18 ) & 7 ;
unsigned long V_44 = ( V_27 >> 15 ) & 7 ;
unsigned long V_45 = ( V_27 >> 12 ) & 7 ;
unsigned long V_46 = ( V_27 >> 9 ) & 7 ;
unsigned long V_47 = ( V_27 >> 8 ) & 1 ;
unsigned long V_38 = ( V_27 >> 3 ) & 0x1f ;
unsigned long V_40 = ( V_27 >> 0 ) & 7 ;
snprintf ( V_34 , sizeof( V_34 ) ,
L_4
L_5 ,
V_48 [ V_43 ] , V_48 [ V_44 ] ,
V_48 [ V_45 ] , V_48 [ V_46 ] ,
V_47 ? L_6 : L_7 ,
V_42 [ V_38 ] , V_40 ) ;
}
F_15 ( L_8 , V_27 ,
V_49 [ V_33 ] , V_34 ) ;
F_15 ( L_9 , V_30 ) ;
F_15 ( L_10 , V_31 , V_49 [ V_32 ] ) ;
} else {
unsigned long V_50 = ( V_27 >> 22 ) & 0xf ;
unsigned long V_51 = ( V_27 >> 18 ) & 0xf ;
unsigned long V_38 = ( V_27 >> 14 ) & 0xf ;
unsigned long V_52 = ( V_27 >> 11 ) & 0xf ;
unsigned long V_53 = ( V_27 >> 8 ) & 7 ;
unsigned long V_54 = ( V_27 >> 5 ) & 0xf ;
unsigned long V_55 = ( V_27 >> 1 ) & 0xf ;
unsigned long V_56 = V_27 & 0x1 ;
if ( V_33 == 1 || V_33 == 3 ) {
unsigned long V_57 = ( V_27 >> 57 ) & 0x1 ;
unsigned long V_58 = ( V_27 >> 29 ) & 0xffff ;
unsigned long V_59 = ( V_27 >> 49 ) & 0xff ;
unsigned long V_60 = ( V_27 >> 45 ) & 0xf ;
unsigned long V_61 = ( V_27 >> 29 ) & 0xfff ;
unsigned long V_62 = ( V_27 >> 28 ) & 0x1 ;
snprintf ( V_34 , sizeof( V_34 ) ,
L_11
L_12
L_13
L_14 ,
V_57 ? L_15 : L_16 ,
V_57 ? ( unsigned long ) F_32 ( V_58 ) - 1 :
V_60 , V_62 , V_59 ,
V_61 ,
V_50 , V_51 ,
V_63 [ V_38 ] ,
V_64 [ V_52 ] ,
V_53 , 1 << V_54 ,
V_65 [ V_55 ] , V_56 ) ;
} else if ( V_33 == 2 ) {
unsigned long V_66 = ( V_27 >> 41 ) & 0xfff ;
unsigned long V_67 = ( V_27 >> 37 ) & 0xf ;
unsigned long V_68 = ( V_27 >> 34 ) & 0x7 ;
unsigned long V_69 = ( V_27 >> 28 ) & 0x3f ;
snprintf ( V_34 , sizeof( V_34 ) ,
L_17
L_18
L_19
L_13
L_14 ,
V_66 , V_67 ,
V_68 , V_69 ,
V_50 , V_51 ,
V_63 [ V_38 ] ,
V_64 [ V_52 ] ,
V_53 , 1 << V_54 ,
V_65 [ V_55 ] , V_56 ) ;
}
F_15 ( L_20 , V_27 ,
V_70 [ V_33 ] , V_34 ) ;
F_15 ( L_21 , V_30 ) ;
F_15 ( L_22 , V_31 , V_70 [ V_32 ] ) ;
}
F_33 ( 0 ) ;
}
