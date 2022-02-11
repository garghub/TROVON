static inline bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 != NULL &&
( V_2 -> V_4 & V_5 ) != 0 ) ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_4 |= V_5 ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
V_2 -> V_4 &= ~ V_5 ;
}
static void F_4 ( void )
{
unsigned int V_6 ;
static bool V_7 ;
if ( V_7 )
return;
V_7 = true ;
F_5 (i)
F_6 ( V_8 , V_6 ) = F_7 ( V_6 , V_9 ) ;
}
void F_8 ( struct V_1 * V_2 ,
unsigned long V_10 ,
T_1 V_11 ,
void (* V_3)( struct V_1 * ) ,
bool V_12 , T_1 V_13 ,
bool V_14 )
{
unsigned int V_15 , V_6 ;
struct V_16 * V_17 = & ( V_2 -> V_12 ) ;
F_4 () ;
if ( V_13 == 0 )
V_2 -> V_18 = V_19 ;
else
V_2 -> V_18 = V_13 ;
F_9 ( V_13 > V_19 ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_3 = V_3 ;
V_15 = 0 ;
if ( V_14 )
V_2 -> V_4 |= V_20 ;
if ( V_12 )
V_2 -> V_4 |= V_21 ;
if ( ! V_12 )
V_2 -> V_22 = V_10 / V_2 -> V_18 ;
else
V_2 -> V_22 = ( V_10 * 3 / 4 ) / V_2 -> V_18 ;
for ( V_6 = 0 ; V_6 < V_2 -> V_18 ; V_6 ++ ) {
F_10 ( & ( V_2 -> V_23 [ V_6 ] . V_24 ) ) ;
V_2 -> V_23 [ V_6 ] . V_15 = V_15 ;
V_2 -> V_23 [ V_6 ] . V_25 = V_15 ;
V_15 += V_2 -> V_22 ;
V_2 -> V_23 [ V_6 ] . V_26 = V_15 - 1 ;
}
if ( ! V_12 )
return;
F_10 ( & ( V_17 -> V_24 ) ) ;
V_17 -> V_15 = V_15 ;
V_17 -> V_25 = V_17 -> V_15 ;
V_17 -> V_26 = V_10 ;
}
unsigned long F_11 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
unsigned long V_29 ,
unsigned long * V_30 ,
unsigned long V_31 ,
unsigned int V_32 )
{
unsigned int V_33 = F_12 ( V_8 ) ;
unsigned long V_34 , V_26 , V_15 , V_35 , V_36 ;
struct V_16 * V_37 ;
int V_38 = 0 ;
unsigned int V_39 ;
unsigned int V_13 = V_2 -> V_18 ;
unsigned long V_4 ;
bool V_12 = ( ( V_2 -> V_4 & V_21 ) != 0 ) ;
bool V_40 = ( V_12 && V_29 > V_41 ) ;
unsigned long V_42 ;
unsigned long V_43 = 0 ;
if ( V_32 > 0 )
V_43 = ~ 0ul >> ( V_44 - V_32 ) ;
if ( F_13 ( V_29 == 0 ) ) {
F_14 ( 1 ) ;
return V_45 ;
}
if ( V_40 ) {
V_37 = & ( V_2 -> V_12 ) ;
V_39 = 0 ;
} else {
V_39 = V_33 & ( V_13 - 1 ) ;
V_37 = & ( V_2 -> V_23 [ V_39 ] ) ;
}
F_15 ( & V_37 -> V_24 , V_4 ) ;
V_46:
if ( V_38 == 0 && V_30 && * V_30 &&
( * V_30 >= V_37 -> V_15 ) && ( * V_30 < V_37 -> V_26 ) )
V_15 = * V_30 ;
else
V_15 = V_37 -> V_25 ;
V_35 = V_37 -> V_26 ;
if ( V_15 >= V_35 )
V_15 = V_37 -> V_15 ;
V_42 = V_2 -> V_47 >> V_2 -> V_11 ;
if ( V_35 + V_42 > V_31 ) {
V_35 = V_31 - V_42 + 1 ;
if ( ( V_15 & V_31 ) >= V_35 || V_38 > 0 ) {
F_16 ( & ( V_37 -> V_24 ) ) ;
V_37 = & ( V_2 -> V_23 [ 0 ] ) ;
F_17 ( & ( V_37 -> V_24 ) ) ;
V_15 = V_37 -> V_15 ;
} else {
V_15 &= V_31 ;
}
}
if ( V_28 )
V_36 = F_18 ( F_19 ( V_28 ) + 1 ,
1 << V_2 -> V_11 ) ;
else
V_36 = F_18 ( 1ULL << 32 , 1 << V_2 -> V_11 ) ;
V_36 = V_36 >> V_2 -> V_11 ;
if ( ( V_2 -> V_4 & V_20 ) != 0 ) {
V_42 = 0 ;
V_36 = V_2 -> V_22 * V_2 -> V_18 ;
}
V_34 = F_20 ( V_2 -> V_48 , V_35 , V_15 , V_29 , V_42 ,
V_36 , V_43 ) ;
if ( V_34 == - 1 ) {
if ( F_21 ( V_38 == 0 ) ) {
V_37 -> V_25 = V_37 -> V_15 ;
F_2 ( V_2 ) ;
V_38 ++ ;
goto V_46;
} else if ( ! V_40 && V_38 <= V_2 -> V_18 ) {
F_16 ( & ( V_37 -> V_24 ) ) ;
V_39 = ( V_39 + 1 ) & ( V_2 -> V_18 - 1 ) ;
V_37 = & ( V_2 -> V_23 [ V_39 ] ) ;
F_17 ( & ( V_37 -> V_24 ) ) ;
V_37 -> V_25 = V_37 -> V_15 ;
F_2 ( V_2 ) ;
V_38 ++ ;
goto V_46;
} else {
V_34 = V_45 ;
goto V_49;
}
}
if ( V_34 < V_37 -> V_25 || F_1 ( V_2 ) ) {
F_3 ( V_2 ) ;
V_2 -> V_3 ( V_2 ) ;
}
V_26 = V_34 + V_29 ;
V_37 -> V_25 = V_26 ;
if ( V_30 )
* V_30 = V_26 ;
V_49:
F_22 ( & ( V_37 -> V_24 ) , V_4 ) ;
return V_34 ;
}
static struct V_16 * F_23 ( struct V_1 * V_50 ,
unsigned long V_51 )
{
struct V_16 * V_17 ;
unsigned long V_52 = V_50 -> V_12 . V_15 ;
bool V_12 = ( ( V_50 -> V_4 & V_21 ) != 0 ) ;
if ( V_12 && V_51 >= V_52 ) {
V_17 = & V_50 -> V_12 ;
} else {
unsigned int V_39 = V_51 / V_50 -> V_22 ;
F_9 ( V_39 >= V_50 -> V_18 ) ;
V_17 = & V_50 -> V_23 [ V_39 ] ;
}
return V_17 ;
}
void F_24 ( struct V_1 * V_2 , T_2 V_53 ,
unsigned long V_29 , unsigned long V_51 )
{
struct V_16 * V_37 ;
unsigned long V_4 ;
unsigned long V_42 = V_2 -> V_11 ;
if ( V_51 == V_45 )
V_51 = ( V_53 - V_2 -> V_47 ) >> V_42 ;
V_37 = F_23 ( V_2 , V_51 ) ;
F_15 ( & ( V_37 -> V_24 ) , V_4 ) ;
F_25 ( V_2 -> V_48 , V_51 , V_29 ) ;
F_22 ( & ( V_37 -> V_24 ) , V_4 ) ;
}
