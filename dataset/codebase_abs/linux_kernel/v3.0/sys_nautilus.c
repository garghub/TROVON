static void T_1
F_1 ( void )
{
if ( V_1 ) {
V_2 . V_3 = V_4 ;
}
F_2 () ;
F_3 () ;
}
static int T_1
F_4 ( struct V_5 * V_6 , T_2 V_7 , T_2 V_8 )
{
T_2 V_9 ;
if ( V_7 == 1 && V_8 == 2 &&
V_6 -> V_10 -> V_11 && V_6 -> V_10 -> V_11 -> V_12 == 0x700f )
return 5 ;
F_5 ( V_6 , V_13 , & V_9 ) ;
return V_9 ;
}
void
F_6 ( int V_14 )
{
struct V_15 * V_10 = V_16 -> V_10 ;
T_3 V_17 ;
int V_18 ;
switch ( V_14 ) {
case V_19 :
if ( ! V_1 ) {
T_2 V_20 ;
F_7 ( V_10 , 0x38 , 0x43 , & V_20 ) ;
F_8 ( V_10 , 0x38 , 0x43 , V_20 | 0x80 ) ;
F_9 ( 1 , 0x92 ) ;
F_9 ( 0 , 0x92 ) ;
}
break;
case V_21 :
V_18 = 0x2000 ;
F_10 ( V_10 , 0x88 , 0x10 , & V_17 ) ;
if ( ! V_17 ) {
V_18 = 0x3400 ;
F_10 ( V_10 , 0x88 , 0xe0 , & V_17 ) ;
}
V_17 &= 0xfffe ;
F_11 ( 0xffff , V_17 ) ;
F_11 ( V_18 , V_17 + 4 ) ;
break;
}
}
static void
F_12 ( unsigned long V_22 , unsigned long V_23 ,
struct V_24 * V_25 )
{
F_13 ( L_1 , V_25 -> V_26 , V_25 -> V_27 ) ;
F_14 () ;
}
void
F_15 ( unsigned long V_22 , unsigned long V_23 )
{
char * V_28 ;
if ( V_22 == V_29
&& ( ( V_30 -> V_31 & 0x300 ) == 0x300 ) ) {
unsigned long V_32 ;
V_32 = F_16 ( 0x61 ) ;
V_32 |= 0x0c ;
F_9 ( V_32 , 0x61 ) ;
V_32 &= ~ 0x0c ;
F_9 ( V_32 , 0x61 ) ;
V_30 -> V_33 = V_30 -> V_33 & ~ 0x100 ;
F_17 () ;
V_30 -> V_33 ;
V_30 -> V_31 = V_30 -> V_31 ;
F_17 () ;
V_30 -> V_31 ;
F_18 () ;
F_19 ( 0x7 ) ;
F_17 () ;
return;
}
if ( V_22 == V_34 )
V_28 = L_2 ;
else if ( V_22 == V_29 )
V_28 = L_3 ;
else {
F_20 ( V_22 , V_23 ) ;
return;
}
F_13 ( V_35 L_4
L_5 ,
V_22 , V_28 ) ;
F_12 ( V_22 , V_23 , F_21 () ) ;
F_18 () ;
F_19 ( 0x7 ) ;
F_17 () ;
}
void T_1
F_22 ( void )
{
struct V_36 * V_37 = V_38 ;
struct V_15 * V_10 ;
struct V_5 * V_39 ;
unsigned long V_40 , V_41 , V_42 ;
unsigned long V_43 = V_44 << V_45 ;
V_10 = F_23 ( 0 , V_2 . V_46 , V_37 ) ;
V_37 -> V_10 = V_10 ;
F_24 ( V_10 ) ;
V_39 = F_25 ( 0 , 0 ) ;
V_10 -> V_11 = V_39 ;
V_10 -> V_47 [ 1 ] = & V_48 ;
F_26 ( V_10 ) ;
V_10 -> V_47 [ 0 ] -> V_49 = 0 ;
V_10 -> V_47 [ 0 ] -> V_50 = 0xffff ;
V_40 = V_10 -> V_47 [ 1 ] -> V_49 ;
V_41 = V_10 -> V_47 [ 1 ] -> V_50 + 1 - V_40 ;
if ( V_40 < 0x1000000UL )
V_40 = 0x1000000UL ;
V_42 = ( 0x100000000UL - V_41 ) & - V_40 ;
V_10 -> V_47 [ 1 ] -> V_49 = V_42 ;
V_10 -> V_47 [ 1 ] -> V_50 = 0xffffffffUL ;
if ( F_27 ( & V_51 , V_10 -> V_47 [ 1 ] ) < 0 )
F_13 ( V_52 L_6 ) ;
if ( V_42 < V_43 )
V_43 = V_42 ;
if ( V_43 > V_2 . V_53 ) {
F_28 ( F_29 ( V_2 . V_53 ) ,
F_29 ( V_43 ) ) ;
F_13 ( L_7 ,
( V_43 - V_2 . V_53 ) >> 10 ) ;
}
if ( ( V_30 -> V_54 >> 16 ) > 0x7006 )
V_30 -> V_42 = V_42 ;
F_30 ( V_10 ) ;
V_10 -> V_11 = NULL ;
F_31 ( V_2 . V_55 , V_2 . V_56 ) ;
}
