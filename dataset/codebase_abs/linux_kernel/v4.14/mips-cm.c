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
F_9 ( V_11 ) ;
if ( V_9 < 6 )
return;
V_10 = F_10 () ;
F_11 ( ( V_10 & V_7 ) != V_10 ) ;
if ( ! V_10 )
return;
F_12 ( V_10 | V_6 ) ;
V_12 = F_13 ( V_10 , V_13 ) ;
}
int F_14 ( void )
{
T_1 V_10 ;
T_2 V_5 ;
unsigned V_14 ;
if ( V_15 )
return 0 ;
V_10 = F_6 () ;
F_11 ( ( V_10 & V_16 ) != V_10 ) ;
if ( ! V_10 )
return - V_17 ;
V_15 = F_13 ( V_10 , V_8 ) ;
if ( ! V_15 )
return - V_18 ;
V_5 = F_15 () ;
if ( ( V_5 & V_16 ) != V_10 ) {
F_16 ( L_1 ,
( unsigned long ) V_10 ) ;
V_15 = NULL ;
return - V_17 ;
}
F_17 ( V_19 , V_20 ) ;
F_18 ( V_21 ) ;
F_19 ( V_22 ) ;
F_20 ( V_21 ) ;
F_21 ( V_22 ) ;
F_22 ( V_21 ) ;
F_23 ( V_22 ) ;
F_24 ( V_21 ) ;
F_25 ( V_22 ) ;
F_7 () ;
V_23 = F_26 ( V_24 ) && ( F_27 () >= V_25 ) ;
F_28 (cpu)
F_29 ( & F_30 ( V_26 , V_14 ) ) ;
return 0 ;
}
void F_31 ( unsigned int V_27 , unsigned int V_28 ,
unsigned int V_29 , unsigned int V_30 )
{
unsigned int V_31 , V_32 ;
T_2 V_33 ;
V_32 = F_27 () ;
F_32 () ;
if ( V_32 >= V_25 ) {
V_33 = V_28 << F_9 ( V_34 ) ;
V_33 |= V_29 << F_9 ( V_35 ) ;
if ( V_32 >= V_36 ) {
V_33 |= V_37 ;
V_33 |= V_27 << F_9 ( V_38 ) ;
V_33 |= V_30 << F_9 ( V_39 ) ;
} else {
F_33 ( V_27 != 0 ) ;
F_33 ( V_30 != V_40 ) ;
}
F_34 ( F_35 ( & V_26 ) ,
* F_35 ( & V_41 ) ) ;
} else {
F_33 ( V_27 != 0 ) ;
F_33 ( V_29 != 0 ) ;
F_33 ( V_30 != V_40 ) ;
V_31 = F_36 ( & V_42 ) ;
F_34 ( & F_30 ( V_26 , V_31 ) ,
F_30 ( V_41 , V_31 ) ) ;
V_33 = V_28 << F_9 ( V_43 ) ;
}
F_37 ( V_33 ) ;
F_38 () ;
}
void F_39 ( void )
{
unsigned int V_31 ;
if ( F_27 () < V_25 ) {
V_31 = F_36 ( & V_42 ) ;
F_40 ( & F_30 ( V_26 , V_31 ) ,
F_30 ( V_41 , V_31 ) ) ;
} else {
F_40 ( F_35 ( & V_26 ) ,
* F_35 ( & V_41 ) ) ;
}
F_41 () ;
}
void F_42 ( void )
{
T_3 V_44 , V_45 , V_46 ;
unsigned long V_47 ;
int V_48 , V_49 ;
char V_50 [ 256 ] ;
if ( ! F_43 () )
return;
V_47 = F_27 () ;
V_44 = F_44 () ;
V_45 = F_45 () ;
V_46 = F_46 () ;
if ( V_47 < V_25 ) {
V_49 = V_44 >> F_9 ( V_51 ) ;
V_48 = V_46 >> F_9 ( V_52 ) ;
if ( ! V_49 )
return;
if ( V_49 < 16 ) {
unsigned long V_53 = ( V_44 >> 15 ) & 7 ;
unsigned long V_54 = ( V_44 >> 12 ) & 7 ;
unsigned long V_55 = ( V_44 >> 7 ) & 0x1f ;
unsigned long V_56 = ( V_44 >> 3 ) & 15 ;
unsigned long V_57 = ( V_44 >> 0 ) & 7 ;
snprintf ( V_50 , sizeof( V_50 ) ,
L_2
L_3 , V_53 , V_58 [ V_54 ] ,
V_59 [ V_55 ] , V_56 , V_57 ) ;
} else {
unsigned long V_60 = ( V_44 >> 18 ) & 7 ;
unsigned long V_61 = ( V_44 >> 15 ) & 7 ;
unsigned long V_62 = ( V_44 >> 12 ) & 7 ;
unsigned long V_63 = ( V_44 >> 9 ) & 7 ;
unsigned long V_64 = ( V_44 >> 8 ) & 1 ;
unsigned long V_55 = ( V_44 >> 3 ) & 0x1f ;
unsigned long V_57 = ( V_44 >> 0 ) & 7 ;
snprintf ( V_50 , sizeof( V_50 ) ,
L_4
L_5 ,
V_65 [ V_60 ] , V_65 [ V_61 ] ,
V_65 [ V_62 ] , V_65 [ V_63 ] ,
V_64 ? L_6 : L_7 ,
V_59 [ V_55 ] , V_57 ) ;
}
F_16 ( L_8 , V_44 ,
V_66 [ V_49 ] , V_50 ) ;
F_16 ( L_9 , V_45 ) ;
F_16 ( L_10 , V_46 , V_66 [ V_48 ] ) ;
} else {
T_4 V_67 , V_68 , V_55 , V_69 ;
T_4 V_70 , V_71 , V_72 , V_73 ;
V_49 = V_44 >> F_47 ( V_74 ) ;
V_48 = V_46 >> F_9 ( V_52 ) ;
if ( ! V_49 )
return;
V_67 = ( V_44 >> 22 ) & 0xf ;
V_68 = ( V_44 >> 18 ) & 0xf ;
V_55 = ( V_44 >> 14 ) & 0xf ;
V_69 = ( V_44 >> 11 ) & 0xf ;
V_70 = ( V_44 >> 8 ) & 7 ;
V_71 = ( V_44 >> 5 ) & 0xf ;
V_72 = ( V_44 >> 1 ) & 0xf ;
V_73 = V_44 & 0x1 ;
if ( V_49 == 1 || V_49 == 3 ) {
unsigned long V_75 = ( V_44 >> 57 ) & 0x1 ;
unsigned long V_76 = ( V_44 >> 29 ) & 0xffff ;
unsigned long V_77 = ( V_44 >> 49 ) & 0xff ;
unsigned long V_78 = ( V_44 >> 45 ) & 0xf ;
unsigned long V_79 = ( V_44 >> 29 ) & 0xfff ;
unsigned long V_80 = ( V_44 >> 28 ) & 0x1 ;
snprintf ( V_50 , sizeof( V_50 ) ,
L_11
L_12
L_13
L_14 ,
V_75 ? L_15 : L_16 ,
V_75 ? ( unsigned long ) F_48 ( V_76 ) - 1 :
V_78 , V_80 , V_77 ,
V_79 ,
V_67 , V_68 ,
V_81 [ V_55 ] ,
V_82 [ V_69 ] ,
V_70 , 1 << V_71 ,
V_83 [ V_72 ] , V_73 ) ;
} else if ( V_49 == 2 ) {
unsigned long V_84 = ( V_44 >> 41 ) & 0xfff ;
unsigned long V_85 = ( V_44 >> 37 ) & 0xf ;
unsigned long V_86 = ( V_44 >> 34 ) & 0x7 ;
unsigned long V_87 = ( V_44 >> 28 ) & 0x3f ;
snprintf ( V_50 , sizeof( V_50 ) ,
L_17
L_18
L_19
L_13
L_14 ,
V_84 , V_85 ,
V_86 , V_87 ,
V_67 , V_68 ,
V_81 [ V_55 ] ,
V_82 [ V_69 ] ,
V_70 , 1 << V_71 ,
V_83 [ V_72 ] , V_73 ) ;
} else {
V_50 [ 0 ] = 0 ;
}
F_16 ( L_20 , V_44 ,
V_88 [ V_49 ] , V_50 ) ;
F_16 ( L_21 , V_45 ) ;
F_16 ( L_22 , V_46 , V_88 [ V_48 ] ) ;
}
F_49 ( 0 ) ;
}
