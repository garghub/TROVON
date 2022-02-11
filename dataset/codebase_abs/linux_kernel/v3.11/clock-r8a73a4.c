static unsigned long F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 = 1 ;
if ( F_2 ( F_3 ( V_3 ) ) & ( 1 << V_1 -> V_4 ) )
V_2 = ( ( ( F_2 ( V_1 -> V_5 ) >> 24 ) & 0x7f ) + 1 ) ;
return V_1 -> V_6 -> V_7 * V_2 ;
}
static int F_4 ( struct V_1 * V_1 , struct V_1 * V_6 )
{
T_1 V_8 ;
int V_9 , V_10 ;
if ( ! V_1 -> V_11 || ! V_1 -> V_12 )
return - V_13 ;
for ( V_9 = 0 ; V_9 < V_1 -> V_12 ; V_9 ++ )
if ( V_1 -> V_11 [ V_9 ] == V_6 )
break;
if ( V_9 == V_1 -> V_12 )
return - V_14 ;
V_10 = F_5 ( V_1 , V_6 ) ;
if ( V_10 < 0 )
return V_10 ;
V_8 = F_2 ( V_1 -> V_5 ) &
~ ( ( ( 1 << V_1 -> V_15 ) - 1 ) << V_1 -> V_16 ) ;
F_6 ( V_8 | V_9 << V_1 -> V_16 , V_1 -> V_5 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_1 )
{
unsigned long V_17 ;
V_17 = F_2 ( F_3 ( V_18 ) ) ;
V_17 |= ( 1 << 31 ) ;
F_6 ( V_17 , F_3 ( V_18 ) ) ;
}
void T_2 F_8 ( void )
{
void T_3 * V_19 ;
int V_20 , V_10 = 0 ;
T_1 V_21 ;
V_19 = F_9 ( V_22 , V_23 ) ;
F_10 ( ! V_19 ) ;
V_21 = F_2 ( V_19 ) ;
F_11 ( V_19 ) ;
switch ( ( V_21 >> 28 ) & 0x3 ) {
case 0 :
V_24 . V_6 = & V_25 ;
break;
case 1 :
V_24 . V_6 = & V_26 ;
break;
case 2 :
V_24 . V_6 = & V_27 ;
break;
case 3 :
V_24 . V_6 = & V_28 ;
break;
}
for ( V_20 = 0 ; ! V_10 && ( V_20 < F_12 ( V_29 ) ) ; V_20 ++ )
V_10 = F_13 ( V_29 [ V_20 ] ) ;
if ( ! V_10 )
V_10 = F_14 ( V_30 , V_31 , & V_32 ) ;
if ( ! V_10 )
V_10 = F_15 ( V_33 , V_34 ) ;
if ( ! V_10 )
V_10 = F_16 ( V_35 , V_36 ) ;
F_17 ( V_37 , F_12 ( V_37 ) ) ;
if ( ! V_10 )
F_18 () ;
else
F_19 ( L_1 ) ;
}
