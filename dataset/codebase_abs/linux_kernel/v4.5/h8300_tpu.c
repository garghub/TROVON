static inline unsigned long F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) << 16 ;
V_3 |= F_2 ( V_2 -> V_6 + V_5 ) ;
return V_3 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned long long * V_7 )
{
unsigned long V_8 , V_9 , V_10 ;
int V_11 , V_12 ;
V_11 = F_4 ( V_2 -> V_4 + V_13 ) & V_14 ;
do {
V_12 = V_11 ;
V_8 = F_1 ( V_2 ) ;
V_9 = F_1 ( V_2 ) ;
V_10 = F_1 ( V_2 ) ;
V_11 = F_4 ( V_2 -> V_4 + V_13 ) & V_14 ;
} while ( F_5 ( ( V_11 != V_12 ) || ( V_8 > V_9 && V_8 < V_10 )
|| ( V_9 > V_10 && V_9 < V_8 ) || ( V_10 > V_8 && V_10 < V_9 ) ) );
* V_7 = V_9 ;
return V_11 ;
}
static inline struct V_1 * F_6 ( struct V_15 * V_16 )
{
return F_7 ( V_16 , struct V_1 , V_16 ) ;
}
static T_1 F_8 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
unsigned long V_17 ;
unsigned long long V_18 ;
F_9 ( & V_2 -> V_19 , V_17 ) ;
if ( F_3 ( V_2 , & V_18 ) )
V_18 += 0x100000000 ;
F_10 ( & V_2 -> V_19 , V_17 ) ;
return V_18 ;
}
static int F_11 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_12 ( V_2 -> V_20 ) ;
F_13 ( 0 , V_2 -> V_4 + V_5 ) ;
F_13 ( 0 , V_2 -> V_6 + V_5 ) ;
F_14 ( 0x0f , V_2 -> V_4 + V_21 ) ;
F_14 ( 0x03 , V_2 -> V_6 + V_21 ) ;
V_2 -> V_20 = true ;
return 0 ;
}
static void F_15 ( struct V_15 * V_16 )
{
struct V_1 * V_2 = F_6 ( V_16 ) ;
F_12 ( ! V_2 -> V_20 ) ;
F_14 ( 0 , V_2 -> V_4 + V_21 ) ;
F_14 ( 0 , V_2 -> V_6 + V_21 ) ;
V_2 -> V_20 = false ;
}
static void T_2 F_16 ( struct V_22 * V_23 )
{
void T_3 * V_24 [ 2 ] ;
struct V_25 * V_25 ;
V_25 = F_17 ( V_23 , 0 ) ;
if ( F_18 ( V_25 ) ) {
F_19 ( L_1 ) ;
return;
}
V_24 [ V_26 ] = F_20 ( V_23 , V_26 ) ;
if ( ! V_24 [ V_26 ] ) {
F_19 ( L_2 ) ;
goto V_27;
}
V_24 [ V_28 ] = F_20 ( V_23 , V_28 ) ;
if ( ! V_24 [ V_28 ] ) {
F_19 ( L_2 ) ;
goto V_29;
}
V_1 . V_4 = V_24 [ V_26 ] ;
V_1 . V_6 = V_24 [ V_28 ] ;
F_21 ( & V_1 . V_16 , F_22 ( V_25 ) / 64 ) ;
return;
V_29:
F_23 ( V_24 [ V_28 ] ) ;
V_27:
F_24 ( V_25 ) ;
}
