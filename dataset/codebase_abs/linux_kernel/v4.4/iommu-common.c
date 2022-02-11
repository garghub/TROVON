static inline bool F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 & V_4 ) != 0 ) ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 |= V_4 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_3 &= ~ V_4 ;
}
static void F_4 ( void )
{
unsigned int V_5 ;
static bool V_6 ;
if ( V_6 )
return;
V_6 = true ;
F_5 (i)
F_6 ( V_7 , V_5 ) = F_7 ( V_5 , V_8 ) ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned long V_9 ,
T_1 V_10 ,
void (* F_9)( struct V_1 * ) ,
bool V_11 , T_1 V_12 ,
bool V_13 )
{
unsigned int V_14 , V_5 ;
struct V_15 * V_16 = & ( V_2 -> V_11 ) ;
F_4 () ;
if ( V_12 == 0 )
V_2 -> V_17 = V_18 ;
else
V_2 -> V_17 = V_12 ;
F_10 ( V_12 > V_18 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> F_9 = F_9 ;
V_14 = 0 ;
if ( V_13 )
V_2 -> V_3 |= V_19 ;
if ( V_11 )
V_2 -> V_3 |= V_20 ;
if ( ! V_11 )
V_2 -> V_21 = V_9 / V_2 -> V_17 ;
else
V_2 -> V_21 = ( V_9 * 3 / 4 ) / V_2 -> V_17 ;
for ( V_5 = 0 ; V_5 < V_2 -> V_17 ; V_5 ++ ) {
F_11 ( & ( V_2 -> V_22 [ V_5 ] . V_23 ) ) ;
V_2 -> V_22 [ V_5 ] . V_14 = V_14 ;
V_2 -> V_22 [ V_5 ] . V_24 = V_14 ;
V_14 += V_2 -> V_21 ;
V_2 -> V_22 [ V_5 ] . V_25 = V_14 - 1 ;
}
if ( ! V_11 )
return;
F_11 ( & ( V_16 -> V_23 ) ) ;
V_16 -> V_14 = V_14 ;
V_16 -> V_24 = V_16 -> V_14 ;
V_16 -> V_25 = V_9 ;
}
unsigned long F_12 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
unsigned long V_28 ,
unsigned long * V_29 ,
unsigned long V_30 ,
unsigned int V_31 )
{
unsigned int V_32 = F_13 ( V_7 ) ;
unsigned long V_33 , V_25 , V_14 , V_34 , V_35 ;
struct V_15 * V_36 ;
int V_37 = 0 ;
unsigned int V_38 ;
unsigned int V_12 = V_2 -> V_17 ;
unsigned long V_3 ;
bool V_11 = ( ( V_2 -> V_3 & V_20 ) != 0 ) ;
bool V_39 = ( V_11 && V_28 > V_40 ) ;
unsigned long V_41 ;
unsigned long V_42 = 0 ;
if ( V_31 > 0 )
V_42 = ~ 0ul >> ( V_43 - V_31 ) ;
if ( F_14 ( V_28 == 0 ) ) {
F_15 ( 1 ) ;
return V_44 ;
}
if ( V_39 ) {
V_36 = & ( V_2 -> V_11 ) ;
V_38 = 0 ;
} else {
V_38 = V_32 & ( V_12 - 1 ) ;
V_36 = & ( V_2 -> V_22 [ V_38 ] ) ;
}
F_16 ( & V_36 -> V_23 , V_3 ) ;
V_45:
if ( V_37 == 0 && V_29 && * V_29 &&
( * V_29 >= V_36 -> V_14 ) && ( * V_29 < V_36 -> V_25 ) )
V_14 = * V_29 ;
else
V_14 = V_36 -> V_24 ;
V_34 = V_36 -> V_25 ;
if ( V_14 >= V_34 )
V_14 = V_36 -> V_14 ;
V_41 = V_2 -> V_46 >> V_2 -> V_10 ;
if ( V_34 + V_41 > V_30 ) {
V_34 = V_30 - V_41 + 1 ;
if ( ( V_14 & V_30 ) >= V_34 || V_37 > 0 ) {
F_17 ( & ( V_36 -> V_23 ) ) ;
V_36 = & ( V_2 -> V_22 [ 0 ] ) ;
F_18 ( & ( V_36 -> V_23 ) ) ;
V_14 = V_36 -> V_14 ;
} else {
V_14 &= V_30 ;
}
}
if ( V_27 )
V_35 = F_19 ( F_20 ( V_27 ) + 1 ,
1 << V_2 -> V_10 ) ;
else
V_35 = F_19 ( 1ULL << 32 , 1 << V_2 -> V_10 ) ;
V_35 = V_35 >> V_2 -> V_10 ;
if ( ( V_2 -> V_3 & V_19 ) != 0 ) {
V_41 = 0 ;
V_35 = V_2 -> V_21 * V_2 -> V_17 ;
}
V_33 = F_21 ( V_2 -> V_47 , V_34 , V_14 , V_28 , V_41 ,
V_35 , V_42 ) ;
if ( V_33 == - 1 ) {
if ( F_22 ( V_37 == 0 ) ) {
V_36 -> V_24 = V_36 -> V_14 ;
F_2 ( V_2 ) ;
V_37 ++ ;
goto V_45;
} else if ( ! V_39 && V_37 <= V_2 -> V_17 ) {
F_17 ( & ( V_36 -> V_23 ) ) ;
V_38 = ( V_38 + 1 ) & ( V_2 -> V_17 - 1 ) ;
V_36 = & ( V_2 -> V_22 [ V_38 ] ) ;
F_18 ( & ( V_36 -> V_23 ) ) ;
V_36 -> V_24 = V_36 -> V_14 ;
F_2 ( V_2 ) ;
V_37 ++ ;
goto V_45;
} else {
V_33 = V_44 ;
goto V_48;
}
}
if ( V_2 -> F_9 &&
( V_33 < V_36 -> V_24 || F_1 ( V_2 ) ) ) {
F_3 ( V_2 ) ;
V_2 -> F_9 ( V_2 ) ;
}
V_25 = V_33 + V_28 ;
V_36 -> V_24 = V_25 ;
if ( V_29 )
* V_29 = V_25 ;
V_48:
F_23 ( & ( V_36 -> V_23 ) , V_3 ) ;
return V_33 ;
}
static struct V_15 * F_24 ( struct V_1 * V_49 ,
unsigned long V_50 )
{
struct V_15 * V_16 ;
unsigned long V_51 = V_49 -> V_11 . V_14 ;
bool V_11 = ( ( V_49 -> V_3 & V_20 ) != 0 ) ;
if ( V_11 && V_50 >= V_51 ) {
V_16 = & V_49 -> V_11 ;
} else {
unsigned int V_38 = V_50 / V_49 -> V_21 ;
F_10 ( V_38 >= V_49 -> V_17 ) ;
V_16 = & V_49 -> V_22 [ V_38 ] ;
}
return V_16 ;
}
void F_25 ( struct V_1 * V_2 , T_2 V_52 ,
unsigned long V_28 , unsigned long V_50 )
{
struct V_15 * V_36 ;
unsigned long V_3 ;
unsigned long V_41 = V_2 -> V_10 ;
if ( V_50 == V_44 )
V_50 = ( V_52 - V_2 -> V_46 ) >> V_41 ;
V_36 = F_24 ( V_2 , V_50 ) ;
F_16 ( & ( V_36 -> V_23 ) , V_3 ) ;
F_26 ( V_2 -> V_47 , V_50 , V_28 ) ;
F_23 ( & ( V_36 -> V_23 ) , V_3 ) ;
}
