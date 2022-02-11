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
static bool F_7 ( struct V_1 * V_1 )
{
return ! ( F_2 ( F_3 ( V_17 ) ) & F_8 ( 31 ) ) ;
}
static int F_9 ( struct V_1 * V_1 )
{
int V_9 ;
F_6 ( F_2 ( F_3 ( V_17 ) ) | F_8 ( 31 ) , F_3 ( V_17 ) ) ;
for ( V_9 = 1000 ; V_9 ; V_9 -- )
if ( F_2 ( F_3 ( V_17 ) ) & F_8 ( 31 ) )
F_10 () ;
else
return 0 ;
return - V_18 ;
}
static int F_11 ( struct V_1 * V_1 , unsigned long V_7 )
{
void T_2 * V_19 ;
int V_10 ;
unsigned long V_20 , V_21 ;
T_1 V_8 ;
if ( ! V_1 -> V_6 || ! F_12 ( V_1 -> V_6 ) )
return - V_14 ;
if ( ! F_13 ( & V_22 ) || ! F_7 ( V_1 ) ) {
V_10 = - V_23 ;
goto V_24;
}
V_21 = F_14 ( V_1 -> V_6 ) ;
if ( V_7 == V_21 ) {
V_8 = 0 ;
} else {
V_20 = F_15 ( V_21 , 32 ) ;
if ( V_7 > V_21 || V_7 < V_20 ) {
V_10 = - V_13 ;
goto V_24;
}
V_8 = 32 - V_7 / V_20 ;
}
V_19 = V_1 -> V_5 + ( V_25 - ( T_1 ) V_1 -> V_26 ) ;
F_6 ( ( F_2 ( V_19 ) & ~ ( V_1 -> V_27 << V_1 -> V_4 ) ) |
( V_8 << V_1 -> V_4 ) , V_19 ) ;
V_10 = F_9 ( V_1 ) ;
V_24:
F_16 ( & V_22 ) ;
F_17 ( V_1 -> V_6 ) ;
return V_10 ;
}
static long F_18 ( struct V_1 * V_1 , unsigned long V_7 )
{
unsigned long V_20 , V_28 , V_29 , V_30 , V_31 ;
V_31 = F_14 ( V_1 -> V_6 ) ;
if ( V_7 >= V_31 )
return V_31 ;
V_20 = F_15 ( V_31 , 32 ) ;
if ( V_20 >= V_7 )
return V_20 ;
V_28 = V_7 / V_20 ;
V_29 = F_19 ( V_7 , V_20 ) ;
V_30 = V_20 * V_28 ;
if ( V_29 == V_28 )
return V_30 ;
V_31 = V_20 * V_29 ;
if ( V_31 - V_7 < V_7 - V_30 )
return V_31 ;
return V_30 ;
}
static unsigned long F_20 ( struct V_1 * V_1 )
{
void T_2 * V_19 = V_25 - ( T_1 ) V_1 -> V_26 + V_1 -> V_5 ;
unsigned int V_32 = V_1 -> V_27 + 1 ;
unsigned long V_8 = ( ( F_2 ( V_19 ) >> V_1 -> V_4 ) &
V_1 -> V_27 ) ;
return F_15 ( F_14 ( V_1 -> V_6 ) , V_32 ) *
( V_32 - V_8 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
if ( ! F_22 ( ! F_13 ( & V_22 ) , L_1 ) )
F_9 ( V_1 ) ;
F_16 ( & V_22 ) ;
}
void T_3 F_23 ( void )
{
void T_2 * V_33 ;
int V_34 , V_10 = 0 ;
T_1 V_35 ;
F_24 ( & V_22 , - 1 ) ;
V_33 = F_25 ( V_36 , V_37 ) ;
F_26 ( ! V_33 ) ;
V_35 = F_2 ( V_33 ) ;
F_27 ( V_33 ) ;
switch ( ( V_35 >> 28 ) & 0x3 ) {
case 0 :
V_38 . V_6 = & V_39 ;
break;
case 1 :
V_38 . V_6 = & V_40 ;
break;
case 2 :
V_38 . V_6 = & V_41 ;
break;
case 3 :
V_38 . V_6 = & V_42 ;
break;
}
for ( V_34 = 0 ; ! V_10 && ( V_34 < F_28 ( V_43 ) ) ; V_34 ++ )
V_10 = F_29 ( V_43 [ V_34 ] ) ;
if ( ! V_10 )
V_10 = F_30 ( V_44 , V_45 , & V_46 ) ;
if ( ! V_10 )
V_10 = F_31 ( V_47 , V_48 ) ;
if ( ! V_10 )
V_10 = F_32 ( V_49 , V_50 ) ;
F_33 ( V_51 , F_28 ( V_51 ) ) ;
if ( ! V_10 )
F_34 () ;
else
F_35 ( L_2 ) ;
}
