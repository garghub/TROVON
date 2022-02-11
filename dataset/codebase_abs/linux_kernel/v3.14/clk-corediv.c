static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_7 = F_3 ( V_6 -> V_8 ) << V_9 ;
return ! ! ( F_4 ( V_4 -> V_10 ) & V_7 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_11 = 0 ;
T_1 V_10 ;
F_6 ( & V_4 -> V_12 , V_11 ) ;
V_10 = F_4 ( V_4 -> V_10 ) ;
V_10 |= ( F_3 ( V_6 -> V_8 ) << V_9 ) ;
F_7 ( V_10 , V_4 -> V_10 ) ;
F_8 ( & V_4 -> V_12 , V_11 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_11 = 0 ;
T_1 V_10 ;
F_6 ( & V_4 -> V_12 , V_11 ) ;
V_10 = F_4 ( V_4 -> V_10 ) ;
V_10 &= ~ ( F_3 ( V_6 -> V_8 ) << V_9 ) ;
F_7 ( V_10 , V_4 -> V_10 ) ;
F_8 ( & V_4 -> V_12 , V_11 ) ;
}
static unsigned long F_10 ( struct V_1 * V_2 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
T_1 V_10 , div ;
V_10 = F_4 ( V_4 -> V_10 + V_14 ) ;
div = ( V_10 >> V_6 -> V_15 ) & V_6 -> V_16 ;
return V_13 / div ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long * V_13 )
{
T_1 div ;
div = * V_13 / V_17 ;
if ( div < 4 )
div = 4 ;
else if ( div > 6 )
div = 8 ;
return * V_13 / div ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_17 ,
unsigned long V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = & V_4 -> V_6 ;
unsigned long V_11 = 0 ;
T_1 V_10 , div ;
div = V_13 / V_17 ;
F_6 ( & V_4 -> V_12 , V_11 ) ;
V_10 = F_4 ( V_4 -> V_10 + V_14 ) ;
V_10 &= ~ ( V_6 -> V_16 << V_6 -> V_15 ) ;
V_10 |= ( div & V_6 -> V_16 ) << V_6 -> V_15 ;
F_7 ( V_10 , V_4 -> V_10 + V_14 ) ;
V_10 = F_4 ( V_4 -> V_10 ) | F_3 ( V_6 -> V_8 ) ;
F_7 ( V_10 , V_4 -> V_10 ) ;
V_10 = F_4 ( V_4 -> V_10 ) | V_18 ;
F_7 ( V_10 , V_4 -> V_10 ) ;
F_13 ( 1000 ) ;
V_10 &= ~ ( V_19 | V_18 ) ;
F_7 ( V_10 , V_4 -> V_10 ) ;
F_13 ( 1000 ) ;
F_8 ( & V_4 -> V_12 , V_11 ) ;
return 0 ;
}
static void T_2 F_14 ( struct V_20 * V_21 )
{
struct V_22 V_23 ;
struct V_3 * V_4 ;
struct V_24 * * V_25 ;
void T_3 * V_26 ;
const char * V_27 ;
const char * V_28 ;
int V_29 ;
V_26 = F_15 ( V_21 , 0 ) ;
if ( F_16 ( ! V_26 ) )
return;
V_27 = F_17 ( V_21 , 0 ) ;
V_30 . V_31 = F_18 ( V_32 ) ;
V_25 = F_19 ( V_30 . V_31 , sizeof( struct V_24 * ) ,
V_33 ) ;
if ( F_16 ( ! V_25 ) )
goto V_34;
V_4 = F_19 ( V_30 . V_31 , sizeof( struct V_3 ) ,
V_33 ) ;
if ( F_16 ( ! V_4 ) )
goto V_35;
F_20 ( & V_4 -> V_12 ) ;
for ( V_29 = 0 ; V_29 < V_30 . V_31 ; V_29 ++ ) {
F_21 ( V_21 , L_1 ,
V_29 , & V_28 ) ;
V_23 . V_36 = 1 ;
V_23 . V_37 = & V_27 ;
V_23 . V_38 = V_28 ;
V_23 . V_39 = & V_40 ;
V_23 . V_11 = 0 ;
V_4 [ V_29 ] . V_6 = V_32 [ V_29 ] ;
V_4 [ V_29 ] . V_10 = V_26 ;
V_4 [ V_29 ] . V_41 . V_23 = & V_23 ;
V_25 [ V_29 ] = F_22 ( NULL , & V_4 [ V_29 ] . V_41 ) ;
F_16 ( F_23 ( V_25 [ V_29 ] ) ) ;
}
V_30 . V_25 = V_25 ;
F_24 ( V_21 , V_42 , & V_30 ) ;
return;
V_35:
F_25 ( V_25 ) ;
V_34:
F_26 ( V_26 ) ;
}
