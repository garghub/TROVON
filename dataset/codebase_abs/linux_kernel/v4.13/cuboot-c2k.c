static void F_1 ( T_1 V_1 )
{
T_1 V_2 , V_3 [ 30 ] , V_4 , V_5 ;
T_1 V_6 , V_7 , V_8 , V_9 [ 2 ] ;
unsigned long V_10 ;
int V_11 ;
void * V_12 , * V_13 ;
T_2 * V_14 , V_15 ;
struct V_16 * V_17 ;
int V_18 ;
V_14 = F_2 () ;
V_15 = F_3 () ;
if ( V_15 )
V_5 = V_19
| V_20
| V_21
| V_22 ;
else
V_5 = V_23
| V_20
| V_24
| V_25 ;
F_4 ( V_26 , V_14 , V_15 ) ;
V_13 = F_5 ( NULL , L_1 ) ;
if ( V_13 == NULL )
F_6 ( L_2 ) ;
V_4 = F_7 ( ( T_1 * ) ( V_26 + V_27 ) ) ;
V_4 |= 0x007ffe00 ;
F_8 ( ( T_1 * ) ( V_26 + V_27 ) , V_4 ) ;
V_12 = NULL ;
for ( V_18 = 0 ; ; V_18 ++ ) {
char V_28 [] = L_3 ;
V_28 [ strlen ( V_28 ) - 1 ] = V_18 + '0' ;
V_12 = F_9 ( V_28 ) ;
if ( V_12 == NULL )
break;
if ( V_18 >= 2 )
F_6 ( L_4 \
L_5 ) ;
F_10 ( V_26 , V_14 , V_18 , 0 ,
V_1 , V_5 ) ;
V_11 = F_11 ( V_12 , L_6 , V_3 , sizeof( V_3 ) ) ;
if ( V_11 == 0 )
F_6 ( L_7
L_8 ) ;
for ( V_2 = 0 ; V_2 < V_11 ; V_2 += 6 ) {
switch ( V_3 [ V_2 ] & 0xff000000 ) {
case 0x01000000 :
V_17 = V_29 ;
break;
case 0x02000000 :
V_17 = V_30 ;
break;
default:
continue;
}
V_6 = V_3 [ V_2 + 1 ] ;
V_7 = V_3 [ V_2 + 2 ] ;
V_10 = V_3 [ V_2 + 3 ] ;
V_8 = V_3 [ V_2 + 5 ] ;
V_9 [ 0 ] = V_10 ;
V_9 [ 1 ] = V_8 ;
if ( ! F_12 ( V_12 , V_9 , sizeof( V_9 ) , & V_10 ) )
F_6 ( L_9 \
L_10 , ( T_1 ) V_10 ) ;
F_13 ( V_26 , V_18 ,
V_6 , V_7 , V_10 , V_8 , V_17 ) ;
}
V_4 &= ~ ( 3 << ( 9 + V_18 * 5 ) ) ;
F_8 ( ( T_1 * ) ( V_26 + V_27 ) ,
V_4 ) ;
} ;
}
static void F_14 ( void )
{
T_1 V_1 ;
V_1 = F_15 ( V_26 ) ;
F_1 ( V_1 ) ;
}
static void F_16 ( void )
{
T_1 V_31 ;
F_17 ( 5000000 ) ;
if ( V_26 != 0 ) {
V_31 = F_7 ( ( T_1 * ) ( V_26 + V_32 ) ) ;
V_31 &= 0xFFFF0FFF ;
F_8 ( ( T_1 * ) ( V_26 + V_32 ) , V_31 ) ;
V_31 = F_7 ( ( T_1 * ) ( V_26 + V_33 ) ) ;
V_31 |= 0x00000004 ;
F_8 ( ( T_1 * ) ( V_26 + V_33 ) , V_31 ) ;
V_31 = F_7 ( ( T_1 * ) ( V_26 + V_34 ) ) ;
V_31 |= 0x00000004 ;
F_8 ( ( T_1 * ) ( V_26 + V_34 ) , V_31 ) ;
V_31 = F_7 ( ( T_1 * ) ( V_26 + V_35 ) ) ;
V_31 &= 0xFFFF0FFF ;
F_8 ( ( T_1 * ) ( V_26 + V_35 ) , V_31 ) ;
V_31 = F_7 ( ( T_1 * ) ( V_26 + V_33 ) ) ;
V_31 |= 0x00080000 ;
F_8 ( ( T_1 * ) ( V_26 + V_33 ) , V_31 ) ;
V_31 = F_7 ( ( T_1 * ) ( V_26 + V_34 ) ) ;
V_31 |= 0x00080000 ;
F_8 ( ( T_1 * ) ( V_26 + V_34 ) , V_31 ) ;
F_8 ( ( T_1 * ) ( V_26 + V_36 ) ,
0x00080004 ) ;
}
for (; ; ) ;
}
void F_18 ( unsigned long V_37 , unsigned long V_38 , unsigned long V_39 ,
unsigned long V_40 , unsigned long V_41 )
{
F_19 () ;
F_20 ( V_42 ) ;
V_26 = F_21 () ;
V_43 . V_44 = F_14 ;
V_43 . exit = F_16 ;
if ( F_22 () < 0 )
exit () ;
}
