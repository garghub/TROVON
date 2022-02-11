static int F_1 ( void T_1 * V_1 , struct V_2 * V_2 , int V_3 )
{
T_2 V_4 = V_2 -> V_4 ;
T_2 V_5 = F_2 ( V_1 ) ;
if ( V_3 )
V_5 |= V_4 ;
else
V_5 &= ~ V_4 ;
F_3 ( V_5 , V_1 ) ;
return 0 ;
}
int F_4 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_6 , V_2 , V_3 ) ;
}
int F_5 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_7 , V_2 , V_3 ) ;
}
int F_6 ( struct V_2 * V_2 , int V_3 )
{
return F_1 ( V_8 , V_2 , V_3 ) ;
}
static unsigned long F_7 ( struct V_2 * V_2 )
{
unsigned long V_9 = F_8 ( V_2 -> V_10 ) ;
unsigned long div = F_2 ( V_11 ) ;
div &= V_12 ;
div >>= ( V_13 - 1 ) ;
return V_9 / ( div + 1 ) ;
}
static unsigned long F_9 ( struct V_2 * V_2 )
{
unsigned long V_14 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_15 = F_2 ( V_11 ) ;
V_15 &= V_16 ;
V_15 >>= V_17 ;
return V_14 / ( V_15 + 1 ) ;
}
static unsigned long F_10 ( struct V_2 * V_2 )
{
unsigned long V_14 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_15 = F_2 ( V_11 ) ;
V_15 &= V_18 ;
return V_14 / ( V_15 + 1 ) ;
}
static unsigned long F_11 ( struct V_2 * V_2 )
{
unsigned long V_14 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_15 = F_2 ( V_11 ) ;
V_15 = ( ( V_15 & V_19 ) ? 1 : 0 ) ;
return V_14 / ( V_15 + 1 ) ;
}
static unsigned long F_12 ( struct V_2 * V_2 ,
unsigned long V_14 )
{
unsigned long V_10 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_20 ;
unsigned V_21 = 256 ;
unsigned div ;
int V_22 ;
if ( ! V_23 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
div = V_25 [ V_22 ] ;
if ( div ) {
V_20 = ( V_10 / div / 1000 ) * 1000 ;
if ( V_20 <= V_14 && div < V_21 )
V_21 = div ;
}
}
return V_10 / V_21 ;
}
static unsigned long F_13 ( struct V_2 * V_2 )
{
unsigned long V_14 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_26 ;
int V_27 ;
if ( ! V_23 || ! V_28 )
return - V_24 ;
V_26 = F_2 ( V_11 ) ;
V_26 &= V_28 ;
V_27 = V_26 >> V_29 ;
return V_14 / V_25 [ V_27 ] ;
}
static int F_14 ( struct V_2 * V_2 , unsigned long V_14 )
{
unsigned long V_10 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_20 ;
unsigned div ;
unsigned V_21 = 256 ;
int V_22 ;
int V_27 = - 1 ;
if ( ! V_23 || ! V_28 )
return - V_24 ;
for ( V_22 = 0 ; V_22 < V_23 ; V_22 ++ ) {
div = V_25 [ V_22 ] ;
if ( div ) {
V_20 = ( V_10 / div / 1000 ) * 1000 ;
if ( V_20 <= V_14 && div < V_21 ) {
V_21 = div ;
V_27 = V_22 ;
}
}
}
if ( V_27 >= 0 ) {
unsigned long V_26 ;
V_26 = F_2 ( V_11 ) ;
V_26 &= ~ V_28 ;
V_26 |= V_27 << V_29 ;
F_3 ( V_26 , V_11 ) ;
}
return ( V_27 == - 1 ) ? - V_24 : 0 ;
}
void T_3 F_15 ( T_4 V_30 )
{
unsigned long V_31 = F_2 ( V_32 ) ;
unsigned long V_33 = F_2 ( V_34 ) ;
struct V_2 * V_35 ;
unsigned long V_36 ;
unsigned long V_37 ;
int V_22 ;
V_35 = F_16 ( NULL , L_1 ) ;
V_36 = F_8 ( V_35 ) ;
F_17 ( V_35 ) ;
V_37 = V_30 ( V_33 , V_36 ) ;
V_38 . V_2 . V_14 = V_37 ;
V_39 . V_14 = V_37 ;
F_18 ( L_2 ,
( V_33 & V_40 ) ? L_3 : L_4 ,
F_19 ( V_37 ) , F_19 ( F_8 ( & V_41 ) ) ,
F_19 ( F_8 ( & V_42 ) ) ,
F_19 ( F_8 ( & V_43 ) ) ) ;
for ( V_22 = 0 ; V_22 < F_20 ( V_44 ) ; V_22 ++ )
F_21 ( & V_44 [ V_22 ] , true ) ;
if ( F_8 ( & V_45 . V_2 ) != ( 48 * 1000 * 1000 ) ) {
F_18 ( V_46 L_5 ) ;
F_22 ( & V_45 . V_2 , 48 * 1000 * 1000 ) ;
}
F_18 ( L_6 ,
( V_31 & V_40 ) ? L_3 : L_4 ,
F_19 ( F_8 ( & V_47 ) ) ,
F_19 ( F_8 ( & V_48 ) ) ) ;
}
void T_5 F_23 ( int V_36 , T_4 V_30 ,
unsigned int * V_49 , int V_50 ,
int V_51 )
{
int V_22 ;
V_25 = V_49 ;
V_23 = V_50 ;
V_28 = V_51 ;
V_42 . V_10 = & V_52 ;
V_42 . V_53 = & V_54 ;
V_43 . V_10 = & V_42 ;
V_43 . V_53 = & V_55 ;
V_48 . V_10 = & V_45 . V_2 ;
V_47 . V_10 = & V_56 . V_2 ;
F_24 ( V_36 ) ;
F_25 ( V_57 , F_20 ( V_57 ) ) ;
for ( V_22 = 0 ; V_22 < F_20 ( V_58 ) ; V_22 ++ )
F_26 ( V_58 [ V_22 ] , 1 ) ;
F_26 ( V_44 , F_20 ( V_44 ) ) ;
F_27 ( V_59 , F_20 ( V_59 ) ) ;
F_27 ( V_60 , F_20 ( V_60 ) ) ;
F_28 ( V_60 , F_20 ( V_60 ) ) ;
F_29 ( V_61 , F_20 ( V_61 ) ) ;
F_15 ( V_30 ) ;
}
