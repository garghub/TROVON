static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_9 = F_3 ( V_8 -> V_10 ) << V_6 -> V_11 ;
return ! ! ( F_4 ( V_4 -> V_12 ) & V_9 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_13 = 0 ;
T_1 V_12 ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_4 -> V_12 ) ;
V_12 |= ( F_3 ( V_8 -> V_10 ) << V_6 -> V_11 ) ;
F_7 ( V_12 , V_4 -> V_12 ) ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_13 = 0 ;
T_1 V_12 ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_4 -> V_12 ) ;
V_12 &= ~ ( F_3 ( V_8 -> V_10 ) << V_6 -> V_11 ) ;
F_7 ( V_12 , V_4 -> V_12 ) ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
}
static unsigned long F_10 ( struct V_1 * V_2 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
T_1 V_12 , div ;
V_12 = F_4 ( V_4 -> V_12 + V_6 -> V_16 ) ;
div = ( V_12 >> V_8 -> V_17 ) & V_8 -> V_18 ;
return V_15 / div ;
}
static long F_11 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long * V_15 )
{
T_1 div ;
div = * V_15 / V_19 ;
if ( div < 4 )
div = 4 ;
else if ( div > 6 )
div = 8 ;
return * V_15 / div ;
}
static int F_12 ( struct V_1 * V_2 , unsigned long V_19 ,
unsigned long V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_5 * V_6 = V_4 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
unsigned long V_13 = 0 ;
T_1 V_12 , div ;
div = V_15 / V_19 ;
F_6 ( & V_4 -> V_14 , V_13 ) ;
V_12 = F_4 ( V_4 -> V_12 + V_6 -> V_16 ) ;
V_12 &= ~ ( V_8 -> V_18 << V_8 -> V_17 ) ;
V_12 |= ( div & V_8 -> V_18 ) << V_8 -> V_17 ;
F_7 ( V_12 , V_4 -> V_12 + V_6 -> V_16 ) ;
V_12 = F_4 ( V_4 -> V_12 ) | F_3 ( V_8 -> V_10 ) ;
F_7 ( V_12 , V_4 -> V_12 ) ;
V_12 = F_4 ( V_4 -> V_12 ) | V_6 -> V_20 ;
F_7 ( V_12 , V_4 -> V_12 ) ;
F_13 ( 1000 ) ;
V_12 &= ~ ( V_21 | V_6 -> V_20 ) ;
F_7 ( V_12 , V_4 -> V_12 ) ;
F_13 ( 1000 ) ;
F_8 ( & V_4 -> V_14 , V_13 ) ;
return 0 ;
}
static void T_2
F_14 ( struct V_22 * V_23 ,
const struct V_5 * V_6 )
{
struct V_24 V_25 ;
struct V_3 * V_4 ;
struct V_26 * * V_27 ;
void T_3 * V_28 ;
const char * V_29 ;
const char * V_30 ;
int V_31 ;
V_28 = F_15 ( V_23 , 0 ) ;
if ( F_16 ( ! V_28 ) )
return;
V_29 = F_17 ( V_23 , 0 ) ;
V_32 . V_33 = V_6 -> V_34 ;
V_27 = F_18 ( V_32 . V_33 , sizeof( struct V_26 * ) ,
V_35 ) ;
if ( F_16 ( ! V_27 ) )
goto V_36;
V_4 = F_18 ( V_32 . V_33 , sizeof( struct V_3 ) ,
V_35 ) ;
if ( F_16 ( ! V_4 ) )
goto V_37;
F_19 ( & V_4 -> V_14 ) ;
for ( V_31 = 0 ; V_31 < V_32 . V_33 ; V_31 ++ ) {
F_20 ( V_23 , L_1 ,
V_31 , & V_30 ) ;
V_25 . V_38 = 1 ;
V_25 . V_39 = & V_29 ;
V_25 . V_40 = V_30 ;
V_25 . V_41 = & V_6 -> V_41 ;
V_25 . V_13 = 0 ;
V_4 [ V_31 ] . V_6 = V_6 ;
V_4 [ V_31 ] . V_8 = V_6 -> V_42 + V_31 ;
V_4 [ V_31 ] . V_12 = V_28 ;
V_4 [ V_31 ] . V_43 . V_25 = & V_25 ;
V_27 [ V_31 ] = F_21 ( NULL , & V_4 [ V_31 ] . V_43 ) ;
F_16 ( F_22 ( V_27 [ V_31 ] ) ) ;
}
V_32 . V_27 = V_27 ;
F_23 ( V_23 , V_44 , & V_32 ) ;
return;
V_37:
F_24 ( V_27 ) ;
V_36:
F_25 ( V_28 ) ;
}
static void T_2 F_26 ( struct V_22 * V_23 )
{
return F_14 ( V_23 , & V_45 ) ;
}
static void T_2 F_27 ( struct V_22 * V_23 )
{
return F_14 ( V_23 , & V_46 ) ;
}
static void T_2 F_28 ( struct V_22 * V_23 )
{
return F_14 ( V_23 , & V_47 ) ;
}
static void T_2 F_29 ( struct V_22 * V_23 )
{
return F_14 ( V_23 , & V_48 ) ;
}
