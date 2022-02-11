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
static void T_2 F_8 ( struct V_14 * V_15 )
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
goto V_21;
V_22 = F_12 ( V_17 * sizeof( * V_22 ) , V_20 ) ;
if ( F_13 ( ! V_22 ) )
goto V_23;
F_11 (dn, L_2 ) {
struct V_24 V_25 ;
struct V_26 * V_26 ;
struct V_26 * V_27 ;
char * V_28 = F_12 ( 5 , V_20 ) ;
int V_9 , V_29 ;
if ( F_13 ( ! V_28 ) )
goto V_30;
V_29 = F_14 ( V_18 , L_3 , & V_9 ) ;
if ( F_13 ( V_29 ) )
goto V_30;
sprintf ( V_28 , L_4 , V_9 ) ;
V_27 = F_15 ( V_15 , 0 ) ;
V_5 [ V_9 ] . V_31 = F_16 ( V_27 ) ;
V_5 [ V_9 ] . V_28 = V_28 ;
V_5 [ V_9 ] . V_9 = V_9 ;
V_5 [ V_9 ] . V_7 = V_16 ;
V_5 [ V_9 ] . V_32 . V_25 = & V_25 ;
V_25 . V_33 = V_5 [ V_9 ] . V_28 ;
V_25 . V_34 = & V_35 ;
V_25 . V_36 = 0 ;
V_25 . V_37 = & V_5 [ V_9 ] . V_31 ;
V_25 . V_38 = 1 ;
V_26 = F_17 ( NULL , & V_5 [ V_9 ] . V_32 ) ;
if ( F_13 ( F_18 ( V_26 ) ) )
goto V_30;
V_22 [ V_9 ] = V_26 ;
}
V_39 . V_40 = V_41 ;
V_39 . V_22 = V_22 ;
F_19 ( V_15 , V_42 , & V_39 ) ;
return;
V_30:
F_20 ( V_22 ) ;
while( V_17 -- )
F_20 ( V_5 [ V_17 ] . V_28 ) ;
V_23:
F_20 ( V_5 ) ;
V_21:
F_21 ( V_16 ) ;
}
