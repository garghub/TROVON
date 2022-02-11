static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( F_3 ( V_2 ) -> V_4 + V_5 ) &
F_4 ( V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_6 )
{
int V_7 = V_6 ? V_8 : V_9 ;
F_6 ( F_4 ( V_3 ) , F_3 ( V_2 ) -> V_4 + V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_10 = F_3 ( V_2 ) -> V_4 + V_11 ;
return ! ( F_2 ( V_10 ) & F_4 ( V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_10 = F_3 ( V_2 ) -> V_4 + V_11 ;
unsigned long V_12 ;
F_9 ( V_12 ) ;
F_6 ( F_2 ( V_10 ) & ~ F_4 ( V_3 ) , V_10 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 , int V_6 )
{
void T_1 * V_10 = F_3 ( V_2 ) -> V_4 + V_11 ;
unsigned long V_12 ;
F_9 ( V_12 ) ;
F_5 ( V_2 , V_3 , V_6 ) ;
F_6 ( F_2 ( V_10 ) | F_4 ( V_3 ) , V_10 ) ;
F_10 ( V_12 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_3 ( V_2 ) -> V_13 + V_3 ;
}
static void F_13 ( struct F_3 * V_14 )
{
void * V_15 = V_14 -> V_4 ;
T_2 V_16 , V_17 ;
V_16 = V_14 -> V_18 & V_14 -> V_19 ;
V_17 = V_14 -> V_20 & V_14 -> V_19 ;
F_6 ( V_16 , V_15 + V_21 ) ;
F_6 ( V_17 , V_15 + V_22 ) ;
}
static int F_14 ( struct V_23 * V_24 , unsigned int type )
{
struct F_3 * V_14 = F_15 ( V_24 ) ;
unsigned int V_25 = F_4 ( V_24 -> V_26 ) ;
if ( type == V_27 ) {
if ( ( V_14 -> V_18 | V_14 -> V_20 ) & V_25 )
return 0 ;
type = V_28 | V_29 ;
}
if ( type & V_28 )
V_14 -> V_18 |= V_25 ;
else
V_14 -> V_18 &= ~ V_25 ;
if ( type & V_29 )
V_14 -> V_20 |= V_25 ;
else
V_14 -> V_20 &= ~ V_25 ;
F_13 ( V_14 ) ;
return 0 ;
}
static void F_16 ( struct V_23 * V_24 )
{
struct F_3 * V_14 = F_15 ( V_24 ) ;
F_6 ( F_4 ( V_24 -> V_26 ) , V_14 -> V_4 + V_30 ) ;
}
static void F_17 ( struct V_23 * V_24 )
{
struct F_3 * V_14 = F_15 ( V_24 ) ;
unsigned int V_25 = F_4 ( V_24 -> V_26 ) ;
V_14 -> V_19 &= ~ V_25 ;
F_13 ( V_14 ) ;
}
static void F_18 ( struct V_23 * V_24 )
{
struct F_3 * V_14 = F_15 ( V_24 ) ;
unsigned int V_25 = F_4 ( V_24 -> V_26 ) ;
V_14 -> V_19 |= V_25 ;
F_13 ( V_14 ) ;
}
static int F_19 ( struct V_23 * V_24 , unsigned int V_31 )
{
struct F_3 * V_14 = F_15 ( V_24 ) ;
int V_32 = F_20 ( V_24 -> V_26 , V_31 ) ;
if ( ! V_32 ) {
if ( V_31 )
V_14 -> V_33 |= F_4 ( V_24 -> V_26 ) ;
else
V_14 -> V_33 &= ~ F_4 ( V_24 -> V_26 ) ;
}
return V_32 ;
}
static int F_21 ( struct V_34 * V_24 ,
unsigned int V_35 , T_3 V_26 )
{
struct F_3 * V_14 = V_24 -> V_36 ;
F_22 ( V_35 , V_14 ) ;
F_23 ( V_35 , & V_37 , V_38 ) ;
F_24 ( V_35 ) ;
return 0 ;
}
static void F_25 ( struct V_39 * V_40 )
{
struct F_3 * V_14 = F_26 ( V_40 ) ;
unsigned int V_35 , V_25 ;
void T_1 * V_41 = V_14 -> V_4 + V_30 ;
V_25 = F_2 ( V_41 ) ;
do {
F_6 ( V_25 , V_41 ) ;
V_35 = V_14 -> V_13 ;
do {
if ( V_25 & 1 )
F_27 ( V_35 ) ;
V_25 >>= 1 ;
V_35 ++ ;
} while ( V_25 );
V_25 = F_2 ( V_41 ) ;
} while ( V_25 );
}
static int F_28 ( void )
{
struct F_3 * V_14 = & F_3 ;
F_6 ( V_14 -> V_33 & V_14 -> V_18 , V_14 -> V_4 + V_21 ) ;
F_6 ( V_14 -> V_33 & V_14 -> V_20 , V_14 -> V_4 + V_22 ) ;
F_6 ( F_2 ( V_14 -> V_4 + V_30 ) ,
V_14 -> V_4 + V_30 ) ;
return 0 ;
}
static void F_29 ( void )
{
F_13 ( & F_3 ) ;
}
static int T_4 F_30 ( void )
{
F_31 ( & V_42 ) ;
return 0 ;
}
void T_4 F_32 ( void )
{
struct F_3 * V_14 = & F_3 ;
int V_43 ;
F_6 ( 0 , V_14 -> V_4 + V_22 ) ;
F_6 ( 0 , V_14 -> V_4 + V_21 ) ;
F_6 ( - 1 , V_14 -> V_4 + V_30 ) ;
F_33 ( & F_3 . V_2 , NULL ) ;
V_44 = F_34 ( NULL ,
28 , V_45 ,
& V_46 , V_14 ) ;
for ( V_43 = 0 ; V_43 < F_35 ( V_47 ) ; V_43 ++ )
F_36 ( V_47 [ V_43 ] ,
F_25 , V_14 ) ;
}
