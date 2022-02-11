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
unsigned long V_10 ;
T_2 V_11 ;
F_8 ( & V_12 , V_10 ) ;
while ( ( F_1 ( V_13 ) & V_14 ) )
F_9 () ;
V_5 = F_1 ( V_15 ) ;
V_6 = F_1 ( V_16 ) ;
V_7 = F_1 ( V_17 ) ;
V_8 = F_1 ( V_18 ) ;
V_9 = F_1 ( V_19 ) ;
V_11 = F_1 ( V_20 ) ;
F_10 ( & V_12 , V_10 ) ;
V_11 += 1960 ;
F_11 ( V_21 L_1
L_2 , V_5 , V_6 , V_7 , V_8 , V_9 , V_11 ) ;
return mktime ( V_11 , V_9 , V_8 , V_7 , V_6 , V_5 ) ;
}
int F_12 ( unsigned long V_22 )
{
int V_23 , V_24 ;
unsigned long V_10 ;
int V_25 ;
F_8 ( & V_12 , V_10 ) ;
V_25 = F_1 ( V_16 ) ;
V_23 = V_22 % 60 ;
V_24 = V_22 / 60 ;
if ( ( ( abs ( V_24 - V_25 ) + 15 ) / 30 ) & 1 )
V_24 += 30 ;
V_24 %= 60 ;
F_5 ( V_23 , V_15 ) ;
F_5 ( V_24 , V_16 ) ;
F_10 ( & V_12 , V_10 ) ;
return 0 ;
}
void T_3 F_13 ( void )
{
unsigned long V_26 ;
F_14 ( V_27 , NULL , NULL , V_28 ) ;
V_26 = V_29 [ 0 ] . V_30 ;
if ( ! V_31 || ! V_26 )
return;
V_3 = ( void V_32 * ) F_15 ( V_33 ,
V_26 ) ;
V_34 . V_35 = F_7 ;
V_34 . V_36 = F_12 ;
}
static int T_3 F_16 ( void )
{
if ( ! F_17 () )
return - V_37 ;
if ( ! V_31 )
return - V_37 ;
V_38 [ 0 ] . V_39 = V_29 [ 0 ] . V_30 ;
V_38 [ 0 ] . V_40 = V_29 [ 0 ] . V_30 +
V_41 ;
V_38 [ 1 ] . V_39 = V_29 [ 0 ] . V_42 ;
V_38 [ 1 ] . V_40 = V_29 [ 0 ] . V_42 ;
return F_18 ( & V_43 ) ;
}
