static unsigned int F_1 ( const struct V_1 * V_2 )
{
unsigned int V_3 ;
unsigned int V_4 ;
if ( V_2 -> V_5 == V_6 )
V_4 = 1000000000 / V_2 -> V_7 ;
else
V_4 = 0xffffffff ;
V_3 = ( V_4 / 3 ) * V_8 ;
if ( V_3 > V_9 )
V_3 = V_9 - V_9 % V_8 ;
else if ( V_3 < V_8 )
V_3 = V_8 ;
return V_3 ;
}
void F_2 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_1 * V_2 = & V_13 -> V_17 -> V_2 ;
unsigned long V_18 ;
V_18 = F_3 () ;
F_4 ( V_15 -> V_19 ) ;
F_5 ( V_15 -> V_19 ) ;
F_6 ( V_15 -> V_19 , V_15 -> V_20 ) ;
V_15 -> V_21 = F_1 ( V_2 ) ;
if ( V_2 -> V_22 == V_23 &&
V_15 -> V_24 * V_8 < V_15 -> V_21 )
V_15 -> V_21 = V_15 -> V_24 * V_8 ;
F_7 ( V_15 -> V_19 , V_15 -> V_21 ) ;
F_8 ( V_15 -> V_19 ) ;
F_9 ( V_18 ) ;
V_15 -> V_25 |= ( V_26 | V_27 ) ;
}
void F_10 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
struct V_12 * V_13 = V_11 -> V_28 ;
struct V_29 * V_17 = V_13 -> V_17 ;
struct V_1 * V_2 = & V_17 -> V_2 ;
int V_30 ;
unsigned long V_31 ;
unsigned int V_32 , V_33 , V_34 , V_35 ;
int V_36 ;
V_30 = V_15 -> V_37 ;
V_31 = F_3 () ;
F_4 ( V_15 -> V_19 ) ;
F_5 ( V_15 -> V_19 ) ;
V_32 = V_15 -> V_21 / V_8 ;
V_34 = F_11 ( V_15 -> V_19 ) / V_8 ;
V_33 = V_32 - V_34 ;
if ( V_2 -> V_22 == V_23 && V_15 -> V_24 < V_33 )
V_33 = V_15 -> V_24 ;
V_35 = 0 ;
if ( V_2 -> V_22 != V_23 ) {
V_35 = V_15 -> V_21 / V_8 ;
} else if ( V_15 -> V_24 > V_33 ) {
V_35 = V_15 -> V_24 - V_33 ;
if ( V_35 > V_32 )
V_35 = V_32 ;
}
for ( V_36 = 0 ; V_36 < V_33 ; V_36 ++ )
F_12 ( V_13 , V_15 -> V_38 [ V_36 ] ) ;
if ( V_2 -> V_22 == V_23 )
V_15 -> V_24 -= V_33 ;
F_6 ( V_15 -> V_19 , V_15 -> V_20 ) ;
F_7 ( V_15 -> V_19 , V_35 * V_8 ) ;
F_9 ( V_31 ) ;
V_17 -> V_39 |= V_40 ;
}
static void F_13 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_10 ( V_11 ) ;
F_8 ( V_15 -> V_19 ) ;
V_15 -> V_41 ( 0x1 , V_11 -> V_42 + V_43 ) ;
}
void F_14 ( struct V_10 * V_11 )
{
const struct V_44 * V_45 = F_15 ( V_11 ) ;
struct V_14 * V_15 = V_11 -> V_16 ;
if ( V_15 -> V_37 & V_46 ||
( V_45 -> V_47 && V_15 -> V_48 & V_49 ) )
F_13 ( V_11 ) ;
}
int F_16 ( struct V_10 * V_11 , unsigned int V_19 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
void * V_38 ;
unsigned long V_50 ;
int V_51 ;
if ( V_19 != 1 && V_19 != 3 )
return - V_52 ;
V_38 = F_17 ( V_9 , V_53 | V_54 ) ;
if ( ! V_38 )
return - V_55 ;
V_51 = F_18 ( V_19 , V_11 -> V_56 ) ;
if ( V_51 ) {
F_19 ( V_38 ) ;
return V_51 ;
}
V_15 -> V_38 = V_38 ;
V_15 -> V_19 = V_19 ;
V_15 -> V_20 = F_20 ( V_15 -> V_38 ) ;
V_50 = F_3 () ;
F_4 ( V_15 -> V_19 ) ;
F_21 ( V_15 -> V_19 , V_57 ) ;
F_9 ( V_50 ) ;
return 0 ;
}
void F_22 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_16 ;
F_19 ( V_15 -> V_38 ) ;
V_15 -> V_38 = NULL ;
if ( V_15 -> V_19 ) {
F_23 ( V_15 -> V_19 ) ;
V_15 -> V_19 = 0 ;
}
}
static int T_1 F_24 ( void )
{
return 0 ;
}
static void T_2 F_25 ( void )
{
}
