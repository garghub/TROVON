static long F_1 ( unsigned long V_1 , unsigned long V_2 ,
unsigned long V_3 , unsigned long V_4 , unsigned long V_5 ,
int V_6 , int V_7 , int V_8 )
{
int V_9 ;
T_1 V_10 , V_11 ;
T_1 V_12 ;
T_1 V_13 , V_14 ;
T_1 V_15 [ 4 ] , V_16 ;
unsigned long V_17 ;
long V_18 = - 1 ;
V_5 &= ~ V_19 ;
V_10 = F_2 ( V_2 , V_6 , V_7 , V_8 ) | V_5 | V_20 ;
V_11 = F_3 ( F_4 ( V_3 ) , V_6 , V_7 ) | V_4 ;
F_5 ( & V_21 , V_17 ) ;
V_9 = F_6 ( V_22 , V_1 ,
V_10 , V_11 ,
V_23 , 0 ,
& V_12 ,
& V_13 , & V_14 ) ;
if ( V_9 ) {
F_7 ( L_1 ,
V_24 , F_8 ( V_9 ) , V_2 , V_3 , V_1 ,
V_10 , V_11 ) ;
F_9 () ;
}
V_9 = F_10 ( V_22 ,
V_12 & ~ 0x3UL ,
& V_15 [ 0 ] , & V_15 [ 1 ] ,
& V_15 [ 2 ] , & V_15 [ 3 ] ,
& V_16 ) ;
F_11 ( V_9 ) ;
if ( V_15 [ V_12 % 4 ] & V_19 )
V_18 = ( V_12 & 7 ) | ( 1 << 3 ) ;
else
V_18 = V_12 & 7 ;
F_12 ( & V_21 , V_17 ) ;
return V_18 ;
}
static long F_13 ( unsigned long V_1 )
{
F_14 ( L_2 ) ;
return 0 ;
}
static long F_15 ( unsigned long V_25 , unsigned long V_26 ,
unsigned long V_2 , int V_6 , int V_7 ,
int V_8 , int V_27 )
{
int V_9 ;
T_1 V_10 , V_28 , V_16 ;
T_1 V_15 [ 4 ] ;
unsigned long V_17 ;
long V_18 ;
V_28 = F_16 ( V_2 , V_6 , V_8 ) ;
F_5 ( & V_21 , V_17 ) ;
V_9 = F_10 ( V_22 , V_25 & ~ 0x3UL ,
& V_15 [ 0 ] , & V_15 [ 1 ] ,
& V_15 [ 2 ] , & V_15 [ 3 ] ,
& V_16 ) ;
if ( V_9 ) {
F_7 ( L_3 ,
V_24 , F_8 ( V_9 ) , V_2 , V_25 , V_6 ) ;
F_9 () ;
}
V_10 = V_15 [ V_25 % 4 ] ;
if ( ! F_17 ( V_10 , V_28 ) || ! ( V_10 & V_20 ) ) {
V_18 = - 1 ;
} else {
V_9 = F_18 ( V_22 ,
V_25 , 0 , 0 ) ;
V_18 = - 1 ;
}
F_12 ( & V_21 , V_17 ) ;
return V_18 ;
}
static void F_19 ( unsigned long V_26 , unsigned long V_29 ,
int V_6 , int V_8 )
{
F_14 ( L_4 ) ;
}
static void F_20 ( unsigned long V_25 , unsigned long V_2 ,
int V_6 , int V_7 , int V_8 , int V_27 )
{
unsigned long V_17 ;
int V_9 ;
F_5 ( & V_21 , V_17 ) ;
V_9 = F_18 ( V_22 , V_25 , 0 , 0 ) ;
if ( V_9 ) {
F_7 ( L_5 ,
V_24 , F_8 ( V_9 ) , V_2 , V_25 , V_6 ) ;
F_9 () ;
}
F_12 ( & V_21 , V_17 ) ;
}
static void F_21 ( void )
{
unsigned long V_30 = ( 1UL << V_31 ) >> 4 ;
T_1 V_32 ;
for ( V_32 = 0 ; V_32 < V_30 ; V_32 ++ )
F_18 ( V_22 , V_32 , 0 , 0 ) ;
F_22 () ;
F_23 () ;
}
void T_2 F_24 ( unsigned long V_33 )
{
V_34 . V_35 = F_20 ;
V_34 . V_36 = F_15 ;
V_34 . V_37 = F_19 ;
V_34 . V_38 = F_1 ;
V_34 . V_39 = F_13 ;
V_34 . V_40 = F_21 ;
V_31 = F_25 ( V_33 ) ;
}
