static void F_1 ( unsigned int V_1 , unsigned int V_2 )
{
unsigned int V_3 = 0 ;
unsigned long V_4 = 0 , V_5 = 0 ;
F_2 ( L_1 , V_1 , V_2 ) ;
switch( V_1 ) {
case 0 :
V_3 = F_3 ( V_6 ) ;
V_4 = 6 ;
V_5 = 0x7F ;
break;
case 1 :
V_3 = F_3 ( V_6 ) ;
V_4 = 0 ;
V_5 = 0x3F ;
break;
case 2 :
V_3 = F_3 ( V_7 ) ;
V_4 = 31 - 4 ;
V_5 = 0x1F ;
break;
case 3 :
V_3 = F_3 ( V_7 ) ;
V_4 = 31 - 9 ;
V_5 = 0x1F ;
break;
case 4 :
V_3 = F_3 ( V_7 ) ;
V_4 = 31 - 14 ;
V_5 = 0x1F ;
break;
case 5 :
V_3 = F_3 ( V_7 ) ;
V_4 = 31 - 19 ;
V_5 = 0x1F ;
break;
case 6 :
V_3 = F_3 ( V_7 ) ;
V_4 = 31 - 24 ;
V_5 = 0x1F ;
break;
case 7 :
V_3 = F_3 ( V_7 ) ;
V_4 = 31 - 28 ;
V_5 = 0xF ;
break;
}
V_3 = V_3 & ~ ( V_5 << V_4 ) ;
V_3 |= V_2 << V_4 ;
switch( V_1 ) {
case 0 :
case 1 :
F_4 ( V_6 , V_3 ) ;
break;
default:
F_4 ( V_7 , V_3 ) ;
}
F_2 ( L_2 , F_3 ( V_6 ) ,
F_3 ( V_7 ) ) ;
}
static int F_5 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
int V_12 )
{
int V_1 ;
V_13 = V_12 ;
for ( V_1 = 0 ; V_1 < V_13 ; ++ V_1 )
V_14 [ V_1 ] = 0x80000000UL - V_9 [ V_1 ] . V_15 ;
return 0 ;
}
static int F_6 ( struct V_8 * V_9 )
{
unsigned int V_16 ;
V_16 = V_17 ;
F_4 ( V_6 , V_16 ) ;
F_4 ( V_7 , 0 ) ;
if ( F_7 ( V_18 ) )
F_4 ( V_19 , 0 ) ;
V_16 |= V_20 | V_21 | V_22 ;
V_16 |= V_23 | V_24 ;
F_4 ( V_6 , V_16 ) ;
F_2 ( L_3 , F_8 () ,
F_3 ( V_6 ) ) ;
F_2 ( L_4 , F_8 () ,
F_3 ( V_7 ) ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
int V_1 ;
unsigned int V_16 ;
F_10 ( F_11 () | V_25 ) ;
for ( V_1 = 0 ; V_1 < V_13 ; ++ V_1 ) {
if ( V_9 [ V_1 ] . V_26 ) {
F_12 ( V_1 , V_14 [ V_1 ] ) ;
F_1 ( V_1 , V_9 [ V_1 ] . V_27 ) ;
} else {
F_12 ( V_1 , 0 ) ;
}
}
V_16 = F_3 ( V_6 ) ;
V_16 &= ~ V_17 ;
F_4 ( V_6 , V_16 ) ;
F_2 ( L_5 , F_8 () , V_16 ) ;
return 0 ;
}
static void F_13 ( void )
{
unsigned int V_16 ;
V_16 = F_3 ( V_6 ) ;
V_16 |= V_17 ;
F_4 ( V_6 , V_16 ) ;
F_2 ( L_6 , F_8 () , V_16 ) ;
F_14 () ;
}
static void F_15 ( struct V_28 * V_29 ,
struct V_8 * V_9 )
{
unsigned int V_16 ;
int V_30 ;
int V_2 ;
int V_1 ;
unsigned long V_31 = F_3 ( V_32 ) ;
V_30 = F_16 ( V_31 ) ;
F_10 ( F_11 () | V_25 ) ;
for ( V_1 = 0 ; V_1 < V_13 ; ++ V_1 ) {
V_2 = F_17 ( V_1 ) ;
if ( V_2 < 0 ) {
if ( V_9 [ V_1 ] . V_26 ) {
F_18 ( V_31 , V_29 , V_1 , V_30 ) ;
F_12 ( V_1 , V_14 [ V_1 ] ) ;
} else {
F_12 ( V_1 , 0 ) ;
}
}
}
V_16 = F_3 ( V_6 ) ;
V_16 |= V_21 ;
V_16 &= ~ V_17 ;
F_4 ( V_6 , V_16 ) ;
}
