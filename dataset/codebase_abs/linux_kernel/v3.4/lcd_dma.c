int F_1 ( void )
{
if ( F_2 () )
if ( F_3 ( V_1 ) & V_2 )
return 1 ;
if ( F_4 () )
if ( F_3 ( V_3 ) & V_4 )
return 1 ;
return 0 ;
}
void F_5 ( unsigned long V_5 , T_1 V_6 , T_1 V_7 ,
int V_8 )
{
V_9 . V_5 = V_5 ;
V_9 . V_8 = V_8 ;
V_9 . V_10 = V_6 ;
V_9 . V_11 = V_7 ;
}
void F_6 ( int V_12 )
{
V_9 . V_13 = V_12 ;
}
void F_7 ( int V_14 )
{
V_9 . V_15 = V_14 ;
}
void F_8 ( int V_16 )
{
V_9 . V_17 = V_16 ;
}
void F_9 ( int V_18 )
{
if ( F_2 () ) {
F_10 ( V_19 L_1 ) ;
F_11 () ;
return;
}
V_9 . V_18 = V_18 ;
}
void F_12 ( int V_20 )
{
if ( F_2 () ) {
F_10 ( V_19 L_2 ) ;
F_11 () ;
}
V_9 . V_20 = V_20 ;
}
void F_13 ( unsigned long V_21 )
{
if ( F_2 () ) {
F_10 ( V_19 L_3
L_4 ) ;
F_11 () ;
}
V_9 . V_21 = V_21 ;
}
void F_14 ( unsigned int V_22 , unsigned int V_23 )
{
if ( F_2 () ) {
F_10 ( V_19 L_5 ) ;
F_11 () ;
}
V_9 . V_22 = V_22 ;
V_9 . V_23 = V_23 ;
}
static void F_15 ( void )
{
unsigned long V_24 , V_25 ;
int V_26 ;
T_1 V_27 ;
unsigned long V_28 , V_29 ;
long V_30 , V_31 ;
unsigned long V_21 ;
unsigned int V_22 , V_23 ;
switch ( V_9 . V_8 ) {
case V_32 :
V_26 = 1 ;
break;
case V_33 :
V_26 = 2 ;
break;
case V_34 :
V_26 = 4 ;
break;
default:
F_11 () ;
return;
}
V_21 = V_9 . V_21 ? V_9 . V_21 : V_9 . V_10 ;
V_22 = V_9 . V_22 ? V_9 . V_22 : 1 ;
V_23 = V_9 . V_23 ? V_9 . V_23 : 1 ;
F_16 ( V_21 < V_9 . V_10 ) ;
#define F_17 ( T_2 , T_3 ) (lcd_dma.addr + \
((y) * vxres * yscale + (x) * xscale) * es)
#define F_18 ( T_4 , T_5 , T_6 , T_7 ) (PIXADDR(dx, dy) - PIXADDR(sx, sy) - es + 1)
switch ( V_9 . V_18 ) {
case 0 :
if ( ! V_9 . V_20 ) {
V_24 = F_17 ( 0 , 0 ) ;
V_25 = F_17 ( V_9 . V_10 - 1 , V_9 . V_11 - 1 ) ;
if ( F_2 () &&
V_9 . V_8 == V_34 )
V_25 += 2 ;
V_30 = F_18 ( 0 , 0 , 1 , 0 ) ;
V_31 = F_18 ( V_9 . V_10 - 1 , 0 , 0 , 1 ) ;
} else {
V_24 = F_17 ( V_9 . V_10 - 1 , 0 ) ;
V_25 = F_17 ( 0 , V_9 . V_11 - 1 ) ;
V_30 = F_18 ( 1 , 0 , 0 , 0 ) ;
V_31 = F_18 ( 0 , 0 , V_9 . V_10 - 1 , 1 ) ;
}
V_28 = V_9 . V_10 ;
V_29 = V_9 . V_11 ;
break;
case 90 :
if ( ! V_9 . V_20 ) {
V_24 = F_17 ( 0 , V_9 . V_11 - 1 ) ;
V_25 = F_17 ( V_9 . V_10 - 1 , 0 ) ;
V_30 = F_18 ( 0 , 1 , 0 , 0 ) ;
V_31 = F_18 ( 0 , 0 , 1 , V_9 . V_11 - 1 ) ;
} else {
V_24 = F_17 ( V_9 . V_10 - 1 , V_9 . V_11 - 1 ) ;
V_25 = F_17 ( 0 , 0 ) ;
V_30 = F_18 ( 0 , 1 , 0 , 0 ) ;
V_31 = F_18 ( 1 , 0 , 0 , V_9 . V_11 - 1 ) ;
}
V_28 = V_9 . V_11 ;
V_29 = V_9 . V_10 ;
break;
case 180 :
if ( ! V_9 . V_20 ) {
V_24 = F_17 ( V_9 . V_10 - 1 , V_9 . V_11 - 1 ) ;
V_25 = F_17 ( 0 , 0 ) ;
V_30 = F_18 ( 1 , 0 , 0 , 0 ) ;
V_31 = F_18 ( 0 , 1 , V_9 . V_10 - 1 , 0 ) ;
} else {
V_24 = F_17 ( 0 , V_9 . V_11 - 1 ) ;
V_25 = F_17 ( V_9 . V_10 - 1 , 0 ) ;
V_30 = F_18 ( 0 , 0 , 1 , 0 ) ;
V_31 = F_18 ( V_9 . V_10 - 1 , 1 , 0 , 0 ) ;
}
V_28 = V_9 . V_10 ;
V_29 = V_9 . V_11 ;
break;
case 270 :
if ( ! V_9 . V_20 ) {
V_24 = F_17 ( V_9 . V_10 - 1 , 0 ) ;
V_25 = F_17 ( 0 , V_9 . V_11 - 1 ) ;
V_30 = F_18 ( 0 , 0 , 0 , 1 ) ;
V_31 = F_18 ( 1 , V_9 . V_11 - 1 , 0 , 0 ) ;
} else {
V_24 = F_17 ( 0 , 0 ) ;
V_25 = F_17 ( V_9 . V_10 - 1 , V_9 . V_11 - 1 ) ;
V_30 = F_18 ( 0 , 0 , 0 , 1 ) ;
V_31 = F_18 ( 0 , V_9 . V_11 - 1 , 1 , 0 ) ;
}
V_28 = V_9 . V_11 ;
V_29 = V_9 . V_10 ;
break;
default:
F_11 () ;
return;
}
if ( F_2 () ) {
F_19 ( V_24 >> 16 , V_35 ) ;
F_19 ( V_24 , V_36 ) ;
F_19 ( V_25 >> 16 , V_37 ) ;
F_19 ( V_25 , V_38 ) ;
return;
}
F_19 ( V_24 >> 16 , V_39 ) ;
F_19 ( V_24 , V_40 ) ;
F_19 ( V_25 >> 16 , V_41 ) ;
F_19 ( V_25 , V_42 ) ;
F_19 ( V_28 , V_43 ) ;
F_19 ( V_29 , V_44 ) ;
V_27 = F_3 ( V_45 ) ;
V_27 &= ~ 0x03 ;
V_27 |= V_9 . V_8 ;
F_19 ( V_27 , V_45 ) ;
V_27 = F_3 ( V_46 ) ;
V_27 &= ~ ( 0x03 << 6 ) ;
if ( V_9 . V_47 != NULL )
V_27 |= 1 << 1 ;
else
V_27 &= ~ ( 1 << 1 ) ;
F_19 ( V_27 , V_46 ) ;
if ( ! ( V_9 . V_18 || V_9 . V_20 ||
V_9 . V_21 || V_9 . V_22 || V_9 . V_23 ) )
return;
V_27 = F_3 ( V_3 ) ;
V_27 |= ( 0x03 << 12 ) ;
F_19 ( V_27 , V_3 ) ;
F_19 ( V_30 , V_48 ) ;
F_19 ( V_31 >> 16 , V_49 ) ;
F_19 ( V_31 , V_50 ) ;
}
static T_8 F_20 ( int V_51 , void * V_52 )
{
T_1 V_27 ;
V_27 = F_3 ( V_46 ) ;
if ( F_21 ( ! ( V_27 & ( 1 << 3 ) ) ) ) {
F_10 ( V_53 L_6 ) ;
return V_54 ;
}
V_27 |= ( 1 << 3 ) ;
F_19 ( V_27 , V_46 ) ;
V_9 . V_55 = 0 ;
if ( V_9 . V_47 != NULL )
V_9 . V_47 ( V_27 , V_9 . V_56 ) ;
return V_57 ;
}
int F_22 ( void (* V_47)( T_1 V_58 , void * V_59 ) ,
void * V_59 )
{
F_23 ( & V_9 . V_60 ) ;
if ( V_9 . V_61 ) {
F_24 ( & V_9 . V_60 ) ;
F_10 ( V_19 L_7 ) ;
F_11 () ;
return - V_62 ;
}
V_9 . V_61 = 1 ;
F_24 ( & V_9 . V_60 ) ;
V_9 . V_47 = V_47 ;
V_9 . V_56 = V_59 ;
V_9 . V_55 = 0 ;
V_9 . V_17 = 0 ;
V_9 . V_18 = 0 ;
V_9 . V_21 = 0 ;
V_9 . V_20 = 0 ;
V_9 . V_22 = 0 ;
V_9 . V_23 = 0 ;
V_9 . V_15 = 0 ;
V_9 . V_13 = 0 ;
return 0 ;
}
void F_25 ( void )
{
F_26 ( & V_9 . V_60 ) ;
if ( ! V_9 . V_61 ) {
F_27 ( & V_9 . V_60 ) ;
F_10 ( V_19 L_8 ) ;
F_11 () ;
return;
}
if ( ! F_2 () )
F_19 ( F_3 ( V_3 ) & ~ 1 ,
V_3 ) ;
V_9 . V_61 = 0 ;
F_27 ( & V_9 . V_60 ) ;
}
void F_28 ( void )
{
T_1 V_27 ;
if ( F_2 () || ! V_9 . V_15 )
return;
V_27 = F_3 ( V_46 ) ;
V_27 |= 1 << 8 ;
F_19 ( V_27 , V_46 ) ;
V_9 . V_55 = 1 ;
V_27 = F_3 ( V_3 ) ;
V_27 |= 1 << 7 ;
F_19 ( V_27 , V_3 ) ;
}
void F_29 ( void )
{
F_16 ( V_9 . V_55 ) ;
if ( ! F_2 () ) {
F_19 ( 0x5440 , V_3 ) ;
F_19 ( 0x9102 , V_45 ) ;
F_19 ( 0x0004 , V_63 ) ;
}
F_15 () ;
if ( ! F_2 () ) {
T_1 V_27 ;
V_27 = F_3 ( V_3 ) ;
V_27 |= 1 << 11 ;
if ( ! V_9 . V_17 )
V_27 |= ( 3 << 8 ) ;
F_19 ( V_27 , V_3 ) ;
}
}
void F_30 ( void )
{
T_1 V_27 ;
V_9 . V_55 = 0 ;
if ( F_2 () || ! V_9 . V_15 )
return;
V_27 = F_3 ( V_3 ) ;
V_27 &= ~ ( 1 << 7 ) ;
F_19 ( V_27 , V_3 ) ;
V_27 = F_3 ( V_46 ) ;
V_27 &= ~ ( 1 << 8 ) ;
F_19 ( V_27 , V_46 ) ;
}
static int T_9 F_31 ( void )
{
int V_64 ;
if ( ! F_32 () )
return - V_65 ;
if ( F_4 () ) {
T_1 V_27 ;
V_27 = F_3 ( V_46 ) ;
V_27 &= ~ ( 1 << 8 ) ;
F_19 ( V_27 , V_46 ) ;
}
F_33 ( & V_9 . V_60 ) ;
V_64 = F_34 ( V_66 , F_20 , 0 ,
L_9 , NULL ) ;
if ( V_64 != 0 )
F_10 ( V_19 L_10
L_11 , V_64 ) ;
return V_64 ;
}
