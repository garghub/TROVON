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
unsigned V_15 ;
if ( V_16 )
return 0 ;
V_10 = F_6 () ;
F_10 ( ( V_10 & V_17 ) != V_10 ) ;
if ( ! V_10 )
return - V_18 ;
V_16 = F_12 ( V_10 , V_8 ) ;
if ( ! V_16 )
return - V_19 ;
V_5 = F_14 () ;
if ( ( V_5 & V_17 ) != V_10 ) {
F_15 ( L_1 ,
( unsigned long ) V_10 ) ;
V_16 = NULL ;
return - V_18 ;
}
V_5 &= ~ V_20 ;
V_5 |= V_21 ;
F_16 ( V_5 ) ;
F_17 ( V_22 ) ;
F_18 ( V_23 ) ;
F_19 ( V_22 ) ;
F_20 ( V_23 ) ;
F_21 ( V_22 ) ;
F_22 ( V_23 ) ;
F_23 ( V_22 ) ;
F_24 ( V_23 ) ;
F_7 () ;
V_24 = F_25 ( V_25 ) && ( F_26 () >= V_26 ) ;
F_27 (cpu)
F_28 ( & F_29 ( V_27 , V_15 ) ) ;
return 0 ;
}
void F_30 ( unsigned int V_28 , unsigned int V_29 )
{
unsigned V_30 ;
T_2 V_31 ;
F_31 () ;
if ( F_26 () >= V_26 ) {
V_31 = V_28 << V_32 ;
V_31 |= V_29 << V_33 ;
F_32 ( F_33 ( & V_27 ) ,
* F_33 ( & V_34 ) ) ;
} else {
F_34 ( V_29 != 0 ) ;
V_30 = V_35 . V_28 ;
F_32 ( & F_29 ( V_27 , V_30 ) ,
F_29 ( V_34 , V_30 ) ) ;
V_31 = V_28 << V_36 ;
}
F_35 ( V_31 ) ;
F_36 () ;
}
void F_37 ( void )
{
unsigned int V_30 ;
if ( F_26 () < V_26 ) {
V_30 = V_35 . V_28 ;
F_38 ( & F_29 ( V_27 , V_30 ) ,
F_29 ( V_34 , V_30 ) ) ;
} else {
F_38 ( F_33 ( & V_27 ) ,
* F_33 ( & V_34 ) ) ;
}
F_39 () ;
}
void F_40 ( void )
{
T_3 V_37 , V_38 , V_39 ;
unsigned long V_40 ;
int V_41 , V_42 ;
char V_43 [ 256 ] ;
if ( ! F_41 () )
return;
V_40 = F_26 () ;
if ( V_40 < V_26 ) {
V_37 = F_42 () ;
V_38 = F_43 () ;
V_39 = F_44 () ;
V_42 = V_37 >> V_44 ;
V_41 = V_39 >> V_45 ;
if ( ! V_42 )
return;
if ( V_42 < 16 ) {
unsigned long V_46 = ( V_37 >> 15 ) & 7 ;
unsigned long V_47 = ( V_37 >> 12 ) & 7 ;
unsigned long V_48 = ( V_37 >> 7 ) & 0x1f ;
unsigned long V_49 = ( V_37 >> 3 ) & 15 ;
unsigned long V_50 = ( V_37 >> 0 ) & 7 ;
snprintf ( V_43 , sizeof( V_43 ) ,
L_2
L_3 , V_46 , V_51 [ V_47 ] ,
V_52 [ V_48 ] , V_49 , V_50 ) ;
} else {
unsigned long V_53 = ( V_37 >> 18 ) & 7 ;
unsigned long V_54 = ( V_37 >> 15 ) & 7 ;
unsigned long V_55 = ( V_37 >> 12 ) & 7 ;
unsigned long V_56 = ( V_37 >> 9 ) & 7 ;
unsigned long V_57 = ( V_37 >> 8 ) & 1 ;
unsigned long V_48 = ( V_37 >> 3 ) & 0x1f ;
unsigned long V_50 = ( V_37 >> 0 ) & 7 ;
snprintf ( V_43 , sizeof( V_43 ) ,
L_4
L_5 ,
V_58 [ V_53 ] , V_58 [ V_54 ] ,
V_58 [ V_55 ] , V_58 [ V_56 ] ,
V_57 ? L_6 : L_7 ,
V_52 [ V_48 ] , V_50 ) ;
}
F_15 ( L_8 , V_37 ,
V_59 [ V_42 ] , V_43 ) ;
F_15 ( L_9 , V_38 ) ;
F_15 ( L_10 , V_39 , V_59 [ V_41 ] ) ;
} else {
T_4 V_60 , V_61 , V_48 , V_62 ;
T_4 V_63 , V_64 , V_65 , V_66 ;
V_37 = F_45 () ;
V_38 = F_46 () ;
V_39 = F_47 () ;
V_42 = V_37 >> V_67 ;
V_41 = V_39 >> V_45 ;
if ( ! V_42 )
return;
V_60 = ( V_37 >> 22 ) & 0xf ;
V_61 = ( V_37 >> 18 ) & 0xf ;
V_48 = ( V_37 >> 14 ) & 0xf ;
V_62 = ( V_37 >> 11 ) & 0xf ;
V_63 = ( V_37 >> 8 ) & 7 ;
V_64 = ( V_37 >> 5 ) & 0xf ;
V_65 = ( V_37 >> 1 ) & 0xf ;
V_66 = V_37 & 0x1 ;
if ( V_42 == 1 || V_42 == 3 ) {
unsigned long V_68 = ( V_37 >> 57 ) & 0x1 ;
unsigned long V_69 = ( V_37 >> 29 ) & 0xffff ;
unsigned long V_70 = ( V_37 >> 49 ) & 0xff ;
unsigned long V_71 = ( V_37 >> 45 ) & 0xf ;
unsigned long V_72 = ( V_37 >> 29 ) & 0xfff ;
unsigned long V_73 = ( V_37 >> 28 ) & 0x1 ;
snprintf ( V_43 , sizeof( V_43 ) ,
L_11
L_12
L_13
L_14 ,
V_68 ? L_15 : L_16 ,
V_68 ? ( unsigned long ) F_48 ( V_69 ) - 1 :
V_71 , V_73 , V_70 ,
V_72 ,
V_60 , V_61 ,
V_74 [ V_48 ] ,
V_75 [ V_62 ] ,
V_63 , 1 << V_64 ,
V_76 [ V_65 ] , V_66 ) ;
} else if ( V_42 == 2 ) {
unsigned long V_77 = ( V_37 >> 41 ) & 0xfff ;
unsigned long V_78 = ( V_37 >> 37 ) & 0xf ;
unsigned long V_79 = ( V_37 >> 34 ) & 0x7 ;
unsigned long V_80 = ( V_37 >> 28 ) & 0x3f ;
snprintf ( V_43 , sizeof( V_43 ) ,
L_17
L_18
L_19
L_13
L_14 ,
V_77 , V_78 ,
V_79 , V_80 ,
V_60 , V_61 ,
V_74 [ V_48 ] ,
V_75 [ V_62 ] ,
V_63 , 1 << V_64 ,
V_76 [ V_65 ] , V_66 ) ;
} else {
V_43 [ 0 ] = 0 ;
}
F_15 ( L_20 , V_37 ,
V_81 [ V_42 ] , V_43 ) ;
F_15 ( L_21 , V_38 ) ;
F_15 ( L_22 , V_39 , V_81 [ V_41 ] ) ;
}
F_49 ( 0 ) ;
}
