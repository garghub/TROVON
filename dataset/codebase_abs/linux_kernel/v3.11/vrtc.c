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
void F_7 ( struct V_5 * V_6 )
{
T_1 V_7 , V_8 , V_9 , V_10 , V_11 ;
unsigned long V_12 ;
T_2 V_13 ;
F_8 ( & V_14 , V_12 ) ;
while ( ( F_1 ( V_15 ) & V_16 ) )
F_9 () ;
V_7 = F_1 ( V_17 ) ;
V_8 = F_1 ( V_18 ) ;
V_9 = F_1 ( V_19 ) ;
V_10 = F_1 ( V_20 ) ;
V_11 = F_1 ( V_21 ) ;
V_13 = F_1 ( V_22 ) ;
F_10 ( & V_14 , V_12 ) ;
V_13 += 1972 ;
F_11 ( V_23 L_1
L_2 , V_7 , V_8 , V_9 , V_10 , V_11 , V_13 ) ;
V_6 -> V_24 = mktime ( V_13 , V_11 , V_10 , V_9 , V_8 , V_7 ) ;
V_6 -> V_25 = 0 ;
}
int F_12 ( const struct V_5 * V_6 )
{
unsigned long V_12 ;
struct V_26 V_27 ;
int V_13 ;
int V_2 = 0 ;
F_13 ( V_6 -> V_24 , & V_27 ) ;
if ( ! F_14 ( & V_27 ) && V_27 . V_28 >= 72 ) {
V_13 = V_27 . V_28 - 72 ;
F_8 ( & V_14 , V_12 ) ;
F_5 ( V_13 , V_22 ) ;
F_5 ( V_27 . V_29 , V_21 ) ;
F_5 ( V_27 . V_30 , V_20 ) ;
F_5 ( V_27 . V_31 , V_19 ) ;
F_5 ( V_27 . V_32 , V_18 ) ;
F_5 ( V_27 . V_33 , V_17 ) ;
F_10 ( & V_14 , V_12 ) ;
} else {
F_11 ( V_34
L_3 ,
V_35 , V_6 -> V_24 ) ;
V_2 = - V_36 ;
}
return V_2 ;
}
void T_3 F_15 ( void )
{
unsigned long V_37 ;
F_16 ( V_38 , NULL , NULL , V_39 ) ;
V_37 = V_40 [ 0 ] . V_41 ;
if ( ! V_42 || ! V_37 )
return;
V_3 = ( void V_43 * ) F_17 ( V_44 ,
V_37 ) ;
V_45 . V_46 = F_7 ;
V_45 . V_47 = F_12 ;
}
static int T_3 F_18 ( void )
{
if ( ! F_19 () )
return - V_48 ;
if ( ! V_42 )
return - V_48 ;
V_49 [ 0 ] . V_50 = V_40 [ 0 ] . V_41 ;
V_49 [ 0 ] . V_51 = V_40 [ 0 ] . V_41 +
V_52 ;
V_49 [ 1 ] . V_50 = V_40 [ 0 ] . V_53 ;
V_49 [ 1 ] . V_51 = V_40 [ 0 ] . V_53 ;
return F_20 ( & V_54 ) ;
}
