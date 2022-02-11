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
static int F_8 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_3 )
{
T_1 V_6 ;
unsigned long V_14 , V_15 , V_16 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_5 -> V_17 )
return - V_18 ;
V_16 = F_9 ( V_2 -> V_19 ) ;
V_6 = F_3 ( V_5 -> V_7 + V_20 ) ;
V_14 = ( V_6 >> V_21 ) &
V_10 ;
if ( V_11 == 2 * V_16 )
V_15 = V_14 / 2 ;
else
V_15 = V_14 ;
if ( V_15 == 0 )
V_15 = 1 ;
V_6 = F_3 ( V_5 -> V_17 ) ;
V_6 &= ~ ( V_22 << V_23 ) ;
V_6 |= ( V_15 << V_23 ) ;
F_6 ( V_6 , V_5 -> V_17 ) ;
V_6 = F_3 ( V_5 -> V_7 + V_13 ) ;
V_6 |= ( V_24 <<
V_25 ) ;
F_6 ( V_6 , V_5 -> V_7 + V_13 ) ;
return F_10 ( V_5 -> V_9 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned long V_11 ,
unsigned long V_3 )
{
if ( F_12 ( V_2 -> V_19 ) )
return F_8 ( V_2 , V_11 , V_3 ) ;
else
return F_5 ( V_2 , V_11 , V_3 ) ;
}
static void T_2 F_13 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
void T_3 * V_28 = F_14 ( V_27 , 0 ) ;
void T_3 * V_29 = F_14 ( V_27 , 1 ) ;
int V_30 = 0 ;
struct V_26 * V_31 ;
if ( V_28 == NULL ) {
F_15 ( L_1 ,
V_32 ) ;
return;
}
if ( V_29 == NULL )
F_16 ( L_2 ,
V_32 ) ;
F_17 (dn, L_3 )
V_30 ++ ;
V_5 = F_18 ( V_30 * sizeof( * V_5 ) , V_33 ) ;
if ( F_19 ( ! V_5 ) )
goto V_34;
V_35 = F_18 ( V_30 * sizeof( * V_35 ) , V_33 ) ;
if ( F_19 ( ! V_35 ) )
goto V_36;
F_17 (dn, L_3 ) {
struct V_37 V_38 ;
struct V_19 * V_19 ;
struct V_19 * V_39 ;
char * V_40 = F_18 ( 5 , V_33 ) ;
int V_9 , V_41 ;
if ( F_19 ( ! V_40 ) )
goto V_42;
V_41 = F_20 ( V_31 , L_4 , & V_9 ) ;
if ( F_19 ( V_41 ) )
goto V_42;
sprintf ( V_40 , L_5 , V_9 ) ;
V_39 = F_21 ( V_27 , 0 ) ;
V_5 [ V_9 ] . V_43 = F_22 ( V_39 ) ;
V_5 [ V_9 ] . V_40 = V_40 ;
V_5 [ V_9 ] . V_9 = V_9 ;
V_5 [ V_9 ] . V_7 = V_28 ;
if ( V_29 )
V_5 [ V_9 ] . V_17 = V_29 + 4 * V_9 ;
V_5 [ V_9 ] . V_44 . V_38 = & V_38 ;
V_38 . V_45 = V_5 [ V_9 ] . V_40 ;
V_38 . V_46 = & V_47 ;
V_38 . V_48 = 0 ;
V_38 . V_49 = & V_5 [ V_9 ] . V_43 ;
V_38 . V_50 = 1 ;
V_19 = F_23 ( NULL , & V_5 [ V_9 ] . V_44 ) ;
if ( F_19 ( F_24 ( V_19 ) ) )
goto V_42;
V_35 [ V_9 ] = V_19 ;
}
V_51 . V_52 = V_53 ;
V_51 . V_35 = V_35 ;
F_25 ( V_27 , V_54 , & V_51 ) ;
return;
V_42:
F_26 ( V_35 ) ;
while( V_30 -- )
F_26 ( V_5 [ V_30 ] . V_40 ) ;
V_36:
F_26 ( V_5 ) ;
V_34:
F_27 ( V_28 ) ;
}
