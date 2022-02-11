T_1
F_1 ( void * V_1 , const struct V_2 * V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 = V_3 -> V_6 ;
if ( ( V_3 -> V_7 & V_8 ) && ( V_6 & 0x300 ) )
V_6 = ( V_6 + 0x3ff ) & ~ 0x3ff ;
return V_6 ;
}
static void T_2 F_2 ( struct V_9 * V_10 )
{
struct V_9 * V_11 ;
struct V_12 * V_13 ;
struct V_14 * V_15 ;
int V_16 ;
struct V_2 * V_17 ;
for ( V_11 = V_10 -> V_18 ; V_11 != V_10 ; V_11 = V_11 -> V_18 ) {
V_13 = F_3 ( V_11 ) ;
if ( ( V_15 = V_13 -> V_19 ) ) {
for ( V_16 = V_20 ; V_16 < V_21 ; V_16 ++ ) {
V_17 = & V_15 -> V_2 [ V_16 ] ;
if ( ! V_17 -> V_6 )
continue;
F_4 ( V_15 , V_16 ) ;
}
}
F_2 ( & V_13 -> V_22 ) ;
}
}
static void T_2 F_5 ( int V_23 )
{
struct V_14 * V_15 = NULL ;
int V_16 , V_24 ;
T_3 V_25 ;
struct V_2 * V_17 ;
F_6 (dev) {
F_7 ( V_15 , V_26 , & V_25 ) ;
for( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_17 = & V_15 -> V_2 [ V_16 ] ;
if ( V_17 -> V_27 )
continue;
if ( ! V_17 -> V_6 )
continue;
if ( V_17 -> V_7 & V_8 )
V_24 = ! ( V_25 & V_28 ) ;
else
V_24 = ! ( V_25 & V_29 ) ;
if ( V_23 == V_24 ) {
F_8 ( L_1 ,
V_17 -> V_6 , V_17 -> V_30 , V_17 -> V_7 , V_24 , V_23 ) ;
if ( F_4 ( V_15 , V_16 ) < 0 ) {
V_17 -> V_30 -= V_17 -> V_6 ;
V_17 -> V_6 = 0 ;
}
}
}
if ( ! V_23 ) {
V_17 = & V_15 -> V_2 [ V_31 ] ;
if ( V_17 -> V_7 & V_32 ) {
T_4 V_33 ;
F_8 ( L_2 , F_9 ( V_15 ) ) ;
V_17 -> V_7 &= ~ V_32 ;
F_10 ( V_15 , V_15 -> V_34 , & V_33 ) ;
F_11 ( V_15 , V_15 -> V_34 , V_33 & ~ V_35 ) ;
}
}
}
}
static void T_2 F_12 ( void )
{
struct V_14 * V_15 = NULL ;
int V_16 ;
struct V_2 * V_17 ;
F_6 (dev) {
int V_36 = V_15 -> V_36 >> 8 ;
if ( ! V_36 || V_36 == V_37 )
continue;
for( V_16 = 0 ; V_16 < 6 ; V_16 ++ ) {
V_17 = & V_15 -> V_2 [ V_16 ] ;
if ( ( V_36 == V_38 && V_16 < 4 ) ||
( V_36 == V_39 && ( V_17 -> V_7 & V_8 ) ) )
continue;
if ( ! V_17 -> V_6 && V_17 -> V_30 )
F_13 ( V_15 , V_16 ) ;
}
if ( V_40 & V_41 ) {
V_17 = & V_15 -> V_2 [ V_31 ] ;
V_17 -> V_30 -= V_17 -> V_6 ;
V_17 -> V_6 = 0 ;
if ( V_17 -> V_30 )
F_13 ( V_15 , V_31 ) ;
}
}
}
void T_2 F_14 ( void )
{
F_8 ( L_3 ) ;
F_2 ( & V_42 ) ;
F_5 ( 0 ) ;
F_5 ( 1 ) ;
F_12 () ;
}
