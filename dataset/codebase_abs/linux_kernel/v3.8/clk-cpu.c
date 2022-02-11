static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , div ;
V_6 = F_3 ( V_5 -> V_7 + V_8 ) ;
div = ( V_6 >> ( V_5 -> V_9 * 8 ) ) & V_10 ;
return V_3 / div ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long * V_3 )
{
T_1 div ;
div = * V_3 / V_11 ;
if ( div == 0 )
div = 1 ;
else if ( div > 3 )
div = 3 ;
return * V_3 / div ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 , div ;
T_1 V_12 ;
div = V_3 / V_11 ;
V_6 = ( F_3 ( V_5 -> V_7 + V_8 )
& ( ~ ( V_10 << ( V_5 -> V_9 * 8 ) ) ) )
| ( div << ( V_5 -> V_9 * 8 ) ) ;
F_6 ( V_6 , V_5 -> V_7 + V_8 ) ;
V_12 = 1 << ( 20 + V_5 -> V_9 ) ;
V_6 = F_3 ( V_5 -> V_7 + V_13 )
| V_12 ;
F_6 ( V_6 , V_5 -> V_7 + V_13 ) ;
V_6 = F_3 ( V_5 -> V_7 + V_13 )
| 1 << 24 ;
F_6 ( V_6 , V_5 -> V_7 + V_13 ) ;
F_7 ( 1000 ) ;
V_6 &= ~ ( V_12 | 1 << 24 ) ;
F_6 ( V_6 , V_5 -> V_7 + V_13 ) ;
F_7 ( 1000 ) ;
return 0 ;
}
void T_2 F_8 ( struct V_14 * V_15 )
{
struct V_4 * V_5 ;
void T_3 * V_16 = F_9 ( V_15 , 0 ) ;
int V_17 = 0 ;
struct V_14 * V_18 ;
if ( V_16 == NULL ) {
F_10 ( L_1 ,
V_19 ) ;
return;
}
F_11 (dn, L_2 )
V_17 ++ ;
V_5 = F_12 ( V_17 * sizeof( * V_5 ) , V_20 ) ;
if ( F_13 ( ! V_5 ) )
return;
V_21 = F_12 ( V_17 * sizeof( * V_21 ) , V_20 ) ;
if ( F_13 ( ! V_21 ) )
goto V_22;
F_11 (dn, L_2 ) {
struct V_23 V_24 ;
struct V_25 * V_25 ;
struct V_25 * V_26 ;
char * V_27 = F_12 ( 5 , V_20 ) ;
int V_9 , V_28 ;
if ( F_13 ( ! V_27 ) )
goto V_29;
V_28 = F_14 ( V_18 , L_3 , & V_9 ) ;
if ( F_13 ( V_28 ) )
goto V_29;
sprintf ( V_27 , L_4 , V_9 ) ;
V_26 = F_15 ( V_15 , 0 ) ;
V_5 [ V_9 ] . V_30 = F_16 ( V_26 ) ;
V_5 [ V_9 ] . V_27 = V_27 ;
V_5 [ V_9 ] . V_9 = V_9 ;
V_5 [ V_9 ] . V_7 = V_16 ;
V_5 [ V_9 ] . V_31 . V_24 = & V_24 ;
V_24 . V_32 = V_5 [ V_9 ] . V_27 ;
V_24 . V_33 = & V_34 ;
V_24 . V_35 = 0 ;
V_24 . V_36 = & V_5 [ V_9 ] . V_30 ;
V_24 . V_37 = 1 ;
V_25 = F_17 ( NULL , & V_5 [ V_9 ] . V_31 ) ;
if ( F_13 ( F_18 ( V_25 ) ) )
goto V_29;
V_21 [ V_9 ] = V_25 ;
}
V_38 . V_39 = V_40 ;
V_38 . V_21 = V_21 ;
F_19 ( V_15 , V_41 , & V_38 ) ;
return;
V_29:
F_20 ( V_21 ) ;
while( V_17 -- )
F_20 ( V_5 [ V_17 ] . V_27 ) ;
V_22:
F_20 ( V_5 ) ;
}
void T_2 F_21 ( void )
{
F_22 ( V_42 ) ;
}
