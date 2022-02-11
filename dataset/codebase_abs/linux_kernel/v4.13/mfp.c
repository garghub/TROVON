static inline void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
F_3 ( V_2 -> V_3 , V_2 -> V_4 ) ;
}
static inline void F_4 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
unsigned long V_5 = ( V_2 -> V_4 & ~ V_6 ) | V_7 ;
if ( V_5 != V_2 -> V_4 )
F_3 ( V_2 -> V_3 , V_5 ) ;
if ( V_2 -> V_8 != V_5 )
F_3 ( V_2 -> V_3 , V_2 -> V_8 ) ;
}
}
void F_5 ( unsigned long * V_9 , int V_10 )
{
unsigned long V_11 ;
int V_12 ;
F_6 ( & V_13 , V_11 ) ;
for ( V_12 = 0 ; V_12 < V_10 ; V_12 ++ , V_9 ++ ) {
unsigned long V_14 , V_15 = * V_9 ;
struct V_1 * V_2 ;
int V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ;
V_16 = F_7 ( V_15 ) ;
F_8 ( V_16 >= V_22 ) ;
V_2 = & V_23 [ V_16 ] ;
V_17 = F_9 ( V_15 ) ;
V_18 = F_10 ( V_15 ) ;
V_19 = F_11 ( V_15 ) ;
V_20 = F_12 ( V_15 ) ;
V_21 = F_13 ( V_15 ) ;
V_14 = F_14 ( V_17 ) | F_15 ( V_18 ) ;
if ( F_16 ( V_21 == V_24 ) ) {
V_2 -> V_4 = V_14 | V_8 [ V_19 ] | V_25 [ V_20 ] ;
V_2 -> V_8 = V_2 -> V_4 ;
} else {
V_2 -> V_8 = V_14 | V_8 [ V_19 ] | V_25 [ V_20 ] ;
V_2 -> V_4 = V_14 | V_26 [ V_21 ] ;
}
V_2 -> V_27 = V_15 ; F_1 ( V_2 ) ;
}
F_17 () ;
F_18 ( & V_13 , V_11 ) ;
}
unsigned long F_19 ( int V_28 )
{
unsigned long V_29 , V_11 ;
F_8 ( V_28 < 0 || V_28 >= V_22 ) ;
F_6 ( & V_13 , V_11 ) ;
V_29 = F_20 ( V_23 [ V_28 ] . V_3 ) ;
F_18 ( & V_13 , V_11 ) ;
return V_29 ;
}
void F_21 ( int V_28 , unsigned long V_29 )
{
unsigned long V_11 ;
F_8 ( V_28 < 0 || V_28 >= V_22 ) ;
F_6 ( & V_13 , V_11 ) ;
F_3 ( V_23 [ V_28 ] . V_3 , V_29 ) ;
F_17 () ;
F_18 ( & V_13 , V_11 ) ;
}
void T_1 F_22 ( void T_2 * V_30 )
{
int V_12 ;
for ( V_12 = 0 ; V_12 < F_23 ( V_23 ) ; V_12 ++ )
V_23 [ V_12 ] . V_27 = - 1 ;
V_31 = V_30 ;
}
void T_1 F_24 ( struct V_32 * V_33 )
{
struct V_32 * V_2 ;
unsigned long V_34 , V_11 ;
int V_12 ;
F_6 ( & V_13 , V_11 ) ;
V_35 = V_33 [ 0 ] . V_34 ;
for ( V_2 = V_33 ; V_2 -> V_36 != V_37 ; V_2 ++ ) {
V_34 = V_2 -> V_34 ;
V_12 = V_2 -> V_36 ;
do {
V_23 [ V_12 ] . V_3 = V_34 ;
V_23 [ V_12 ] . V_4 = 0 ;
V_23 [ V_12 ] . V_8 = 0 ;
V_34 += 4 ; V_12 ++ ;
} while ( ( V_12 <= V_2 -> V_38 ) && ( V_2 -> V_38 != - 1 ) );
}
F_18 ( & V_13 , V_11 ) ;
}
void F_25 ( void )
{
struct V_1 * V_2 = & V_23 [ 0 ] ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_23 ( V_23 ) ; V_16 ++ , V_2 ++ )
F_4 ( V_2 ) ;
}
void F_26 ( void )
{
struct V_1 * V_2 = & V_23 [ 0 ] ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_23 ( V_23 ) ; V_16 ++ , V_2 ++ )
F_1 ( V_2 ) ;
}
