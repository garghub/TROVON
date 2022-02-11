unsigned char F_1 ( unsigned char V_1 )
{
unsigned char V_2 ;
if ( V_1 > 0xd || ! V_3 )
return 0xff ;
F_2 ( V_1 ) ;
V_2 = F_3 ( V_3 + ( V_1 << 2 ) ) ;
F_4 ( V_1 ) ;
return V_2 ;
}
void F_5 ( unsigned char V_4 , unsigned char V_1 )
{
if ( V_1 > 0xd || ! V_3 )
return;
F_2 ( V_1 ) ;
F_6 ( V_4 , V_3 + ( V_1 << 2 ) ) ;
F_4 ( V_1 ) ;
}
unsigned long F_7 ( void )
{
T_1 V_5 , V_6 , V_7 , V_8 , V_9 ;
T_2 V_10 ;
while ( ( F_1 ( V_11 ) & V_12 ) )
F_8 () ;
V_5 = F_1 ( V_13 ) ;
V_6 = F_1 ( V_14 ) ;
V_7 = F_1 ( V_15 ) ;
V_8 = F_1 ( V_16 ) ;
V_9 = F_1 ( V_17 ) ;
V_10 = F_1 ( V_18 ) ;
V_10 += 1960 ;
F_9 ( V_19 L_1
L_2 , V_5 , V_6 , V_7 , V_8 , V_9 , V_10 ) ;
return mktime ( V_10 , V_9 , V_8 , V_7 , V_6 , V_5 ) ;
}
int F_10 ( unsigned long V_20 )
{
int V_21 , V_22 ;
int V_23 ;
V_23 = F_1 ( V_14 ) ;
V_21 = V_20 % 60 ;
V_22 = V_20 / 60 ;
if ( ( ( abs ( V_22 - V_23 ) + 15 ) / 30 ) & 1 )
V_22 += 30 ;
V_22 %= 60 ;
F_5 ( V_21 , V_13 ) ;
F_5 ( V_22 , V_14 ) ;
return 0 ;
}
void T_3 F_11 ( void )
{
unsigned long V_24 ;
F_12 ( V_25 , NULL , NULL , V_26 ) ;
V_24 = V_27 [ 0 ] . V_28 ;
if ( ! V_29 || ! V_24 )
return;
V_3 = ( void V_30 * ) F_13 ( V_31 ,
V_24 ) ;
V_32 . V_33 = F_7 ;
V_32 . V_34 = F_10 ;
}
static int T_3 F_14 ( void )
{
if ( ! F_15 () )
return - V_35 ;
if ( ! V_29 )
return - V_35 ;
V_36 [ 0 ] . V_37 = V_27 [ 0 ] . V_28 ;
V_36 [ 0 ] . V_38 = V_27 [ 0 ] . V_28 +
V_39 ;
V_36 [ 1 ] . V_37 = V_27 [ 0 ] . V_40 ;
V_36 [ 1 ] . V_38 = V_27 [ 0 ] . V_40 ;
return F_16 ( & V_41 ) ;
}
