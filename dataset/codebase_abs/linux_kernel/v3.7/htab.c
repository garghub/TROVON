static long F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 , unsigned long V_5 ,
int V_6 , int V_7 )
{
int V_8 ;
T_1 V_9 , V_10 ;
T_1 V_11 ;
T_1 V_12 , V_13 ;
T_1 V_14 [ 4 ] , V_15 ;
unsigned long V_16 ;
long V_17 = - 1 ;
V_5 &= ~ V_18 ;
V_9 = F_2 ( V_2 , V_6 , V_7 ) | V_5 | V_19 ;
V_10 = F_3 ( F_4 ( V_3 ) , V_6 ) | V_4 ;
F_5 ( & V_20 , V_16 ) ;
V_8 = F_6 ( V_21 , V_1 ,
V_9 , V_10 ,
V_22 , 0 ,
& V_11 ,
& V_12 , & V_13 ) ;
if ( V_8 ) {
F_7 ( L_1 ,
V_23 , V_8 , V_2 , V_3 , V_1 , V_9 , V_10 ) ;
F_8 () ;
}
V_8 = F_9 ( V_21 ,
V_11 & ~ 0x3UL ,
& V_14 [ 0 ] , & V_14 [ 1 ] ,
& V_14 [ 2 ] , & V_14 [ 3 ] ,
& V_15 ) ;
F_10 ( V_8 ) ;
if ( V_14 [ V_11 % 4 ] & V_18 )
V_17 = ( V_11 & 7 ) | ( 1 << 3 ) ;
else
V_17 = V_11 & 7 ;
F_11 ( & V_20 , V_16 ) ;
return V_17 ;
}
static long F_12 ( unsigned long V_1 )
{
F_13 ( L_2 ) ;
return 0 ;
}
static long F_14 ( unsigned long V_24 , unsigned long V_25 ,
unsigned long V_2 , int V_6 , int V_7 , int V_26 )
{
int V_8 ;
T_1 V_9 , V_27 , V_15 ;
T_1 V_14 [ 4 ] ;
unsigned long V_16 ;
long V_17 ;
V_27 = F_2 ( V_2 , V_6 , V_7 ) ;
F_5 ( & V_20 , V_16 ) ;
V_8 = F_9 ( V_21 , V_24 & ~ 0x3UL ,
& V_14 [ 0 ] , & V_14 [ 1 ] ,
& V_14 [ 2 ] , & V_14 [ 3 ] ,
& V_15 ) ;
if ( V_8 ) {
F_7 ( L_3 ,
V_23 , V_8 , V_2 , V_24 , V_6 ) ;
F_8 () ;
}
V_9 = V_14 [ V_24 % 4 ] ;
if ( ! F_15 ( V_9 , V_27 ) || ! ( V_9 & V_19 ) ) {
V_17 = - 1 ;
} else {
V_8 = F_16 ( V_21 ,
V_24 , 0 , 0 ) ;
V_17 = - 1 ;
}
F_11 ( & V_20 , V_16 ) ;
return V_17 ;
}
static void F_17 ( unsigned long V_25 , unsigned long V_28 ,
int V_6 , int V_7 )
{
F_13 ( L_4 ) ;
}
static void F_18 ( unsigned long V_24 , unsigned long V_2 ,
int V_6 , int V_7 , int V_26 )
{
unsigned long V_16 ;
int V_8 ;
F_5 ( & V_20 , V_16 ) ;
V_8 = F_16 ( V_21 , V_24 , 0 , 0 ) ;
if ( V_8 ) {
F_7 ( L_5 ,
V_23 , V_8 , V_2 , V_24 , V_6 ) ;
F_8 () ;
}
F_11 ( & V_20 , V_16 ) ;
}
static void F_19 ( void )
{
unsigned long V_29 = ( 1UL << V_30 ) >> 4 ;
T_1 V_31 ;
for ( V_31 = 0 ; V_31 < V_29 ; V_31 ++ )
F_16 ( V_21 , V_31 , 0 , 0 ) ;
F_20 () ;
F_21 () ;
}
void T_2 F_22 ( unsigned long V_32 )
{
V_33 . V_34 = F_18 ;
V_33 . V_35 = F_14 ;
V_33 . V_36 = F_17 ;
V_33 . V_37 = F_1 ;
V_33 . V_38 = F_12 ;
V_33 . V_39 = F_19 ;
V_30 = F_23 ( V_32 ) ;
}
