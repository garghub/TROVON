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
static unsigned long F_10 ( struct V_2 * V_2 ,
unsigned long V_14 )
{
unsigned long V_10 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_18 ;
unsigned V_19 = 256 ;
unsigned div ;
int V_20 ;
if ( ! V_21 )
return - V_22 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
div = V_23 [ V_20 ] ;
if ( div ) {
V_18 = ( V_10 / div / 1000 ) * 1000 ;
if ( V_18 <= V_14 && div < V_19 )
V_19 = div ;
}
}
return V_10 / V_19 ;
}
static unsigned long F_11 ( struct V_2 * V_2 )
{
unsigned long V_14 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_24 ;
int V_25 ;
if ( ! V_21 || ! V_26 )
return - V_22 ;
V_24 = F_2 ( V_11 ) ;
V_24 &= V_26 ;
V_25 = V_24 >> V_27 ;
return V_14 / V_23 [ V_25 ] ;
}
static int F_12 ( struct V_2 * V_2 , unsigned long V_14 )
{
unsigned long V_10 = F_8 ( V_2 -> V_10 ) ;
unsigned long V_18 ;
unsigned div ;
unsigned V_19 = 256 ;
int V_20 ;
int V_25 = - 1 ;
if ( ! V_21 || ! V_26 )
return - V_22 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
div = V_23 [ V_20 ] ;
if ( div ) {
V_18 = ( V_10 / div / 1000 ) * 1000 ;
if ( V_18 <= V_14 && div < V_19 ) {
V_19 = div ;
V_25 = V_20 ;
}
}
}
if ( V_25 >= 0 ) {
unsigned long V_24 ;
V_24 = F_2 ( V_11 ) ;
V_24 &= ~ V_26 ;
V_24 |= V_25 << V_27 ;
F_3 ( V_24 , V_11 ) ;
}
return ( V_25 == - 1 ) ? - V_22 : 0 ;
}
static inline unsigned long F_13 ( unsigned long V_24 )
{
V_24 &= V_28 ;
return V_24 + 1 ;
}
void T_3 F_14 ( T_4 V_29 )
{
unsigned long V_30 = F_2 ( V_31 ) ;
unsigned long V_32 = F_2 ( V_33 ) ;
unsigned long V_15 = F_2 ( V_11 ) ;
struct V_2 * V_34 ;
unsigned long V_35 ;
unsigned long V_36 ;
unsigned long V_37 ;
unsigned long V_38 ;
unsigned long V_39 ;
int V_20 ;
V_34 = F_15 ( NULL , L_1 ) ;
V_35 = F_8 ( V_34 ) ;
F_16 ( V_34 ) ;
V_36 = V_29 ( V_32 , V_35 ) ;
V_40 . V_2 . V_14 = V_36 ;
V_37 = F_8 ( & V_41 ) ;
V_38 = F_9 ( & V_42 ) ;
V_38 /= F_13 ( V_15 ) ;
V_39 = V_38 / ( ( V_15 & V_43 ) ? 2 : 1 ) ;
F_17 ( V_37 , V_38 , V_39 ) ;
F_18 ( L_2 ,
( V_32 & V_44 ) ? L_3 : L_4 ,
F_19 ( V_36 ) , F_19 ( V_37 ) ,
F_19 ( V_38 ) , F_19 ( V_39 ) ) ;
for ( V_20 = 0 ; V_20 < F_20 ( V_45 ) ; V_20 ++ )
F_21 ( & V_45 [ V_20 ] , true ) ;
if ( F_8 ( & V_46 . V_2 ) != ( 48 * 1000 * 1000 ) ) {
F_18 ( V_47 L_5 ) ;
F_22 ( & V_46 . V_2 , 48 * 1000 * 1000 ) ;
}
F_18 ( L_6 ,
( V_30 & V_44 ) ? L_3 : L_4 ,
F_19 ( F_8 ( & V_48 ) ) ,
F_19 ( F_8 ( & V_49 ) ) ) ;
}
void T_5 F_23 ( int V_35 , T_4 V_29 ,
unsigned int * V_50 , int V_51 ,
int V_52 )
{
int V_20 ;
V_23 = V_50 ;
V_21 = V_51 ;
V_26 = V_52 ;
V_53 . V_10 = & V_42 ;
V_54 . V_10 = & V_42 ;
V_49 . V_10 = & V_46 . V_2 ;
V_48 . V_10 = & V_55 . V_2 ;
F_24 ( V_35 ) ;
F_25 ( V_56 , F_20 ( V_56 ) ) ;
for ( V_20 = 0 ; V_20 < F_20 ( V_57 ) ; V_20 ++ )
F_26 ( V_57 [ V_20 ] , 1 ) ;
F_26 ( V_45 , F_20 ( V_45 ) ) ;
F_27 ( V_58 , F_20 ( V_58 ) ) ;
F_27 ( V_59 , F_20 ( V_59 ) ) ;
F_28 ( V_59 , F_20 ( V_59 ) ) ;
F_14 ( V_29 ) ;
}
