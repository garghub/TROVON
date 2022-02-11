static void F_1 ( void )
{
T_1 V_1 ;
F_2 ( V_2 , V_1 ) ;
V_1 |= ( V_3 | V_4 ) ;
F_3 ( V_2 , V_1 ) ;
}
static void F_4 ( void )
{
T_1 V_1 ;
F_2 ( V_2 , V_1 ) ;
V_1 &= ~ ( V_3 | V_4 ) ;
F_3 ( V_2 , V_1 ) ;
}
static void F_5 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 . V_7 ; V_5 ++ )
F_3 ( V_6 . V_8 + V_5 , 0 ) ;
}
static void F_6 ( void )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 . V_7 ; V_5 ++ ) {
F_3 ( V_6 . V_8 + V_5 , 0 ) ;
F_3 ( V_6 . V_9 + V_5 , 0 ) ;
}
}
void F_7 ( void )
{
if ( ! V_6 . V_7 )
return;
if ( V_6 . V_10 . V_11 == V_12 )
F_5 () ;
else
F_6 () ;
}
void F_8 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & F_9 ( V_15 ) ;
if ( ! V_6 . V_7 )
return;
if ( V_14 -> V_17 -> V_18 && V_16 -> V_19 != V_14 -> V_17 ) {
F_7 () ;
V_16 -> V_19 = V_14 -> V_17 ;
}
V_16 -> V_20 ++ ;
}
void F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = & F_9 ( V_15 ) ;
if ( ! V_6 . V_7 )
return;
V_16 -> V_20 -- ;
F_11 ( V_16 -> V_20 < 0 ) ;
if ( V_16 -> V_21 && ! V_16 -> V_20 )
F_4 () ;
}
void F_12 ( void )
{
struct V_15 * V_16 = & F_9 ( V_15 ) ;
if ( V_16 -> V_20 )
F_1 () ;
}
void F_13 ( void )
{
struct V_15 * V_16 = & F_9 ( V_15 ) ;
if ( V_16 -> V_20 )
F_4 () ;
}
static inline T_1 F_14 ( void )
{
T_1 V_22 ;
F_2 ( V_6 . V_23 , V_22 ) ;
return V_22 ;
}
static void F_15 ( struct V_15 * V_16 )
{
unsigned long V_24 = V_6 . V_7 - 1 ;
T_1 V_22 = F_14 () ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 . V_7 ; V_5 ++ ) {
unsigned long V_25 = ( V_22 - V_5 ) & V_24 ;
union {
struct {
T_2 V_26 ;
T_2 V_27 ;
};
T_1 V_28 ;
} V_29 ;
F_2 ( V_6 . V_8 + V_25 , V_29 . V_28 ) ;
V_16 -> V_30 [ V_5 ] . V_26 = V_29 . V_26 ;
V_16 -> V_30 [ V_5 ] . V_27 = V_29 . V_27 ;
V_16 -> V_30 [ V_5 ] . V_31 = 0 ;
}
V_16 -> V_32 . V_33 = V_5 ;
}
static void F_16 ( struct V_15 * V_16 )
{
unsigned long V_24 = V_6 . V_7 - 1 ;
int V_11 = V_6 . V_10 . V_11 ;
T_1 V_22 = F_14 () ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_6 . V_7 ; V_5 ++ ) {
unsigned long V_25 = ( V_22 - V_5 ) & V_24 ;
T_1 V_26 , V_27 , V_31 = 0 ;
F_2 ( V_6 . V_8 + V_25 , V_26 ) ;
F_2 ( V_6 . V_9 + V_25 , V_27 ) ;
if ( V_11 == V_34 ) {
V_31 = ! ! ( V_26 & V_35 ) ;
V_26 = ( T_1 ) ( ( ( ( V_36 ) V_26 ) << 1 ) >> 1 ) ;
}
V_16 -> V_30 [ V_5 ] . V_26 = V_26 ;
V_16 -> V_30 [ V_5 ] . V_27 = V_27 ;
V_16 -> V_30 [ V_5 ] . V_31 = V_31 ;
}
V_16 -> V_32 . V_33 = V_5 ;
}
void F_17 ( void )
{
struct V_15 * V_16 = & F_9 ( V_15 ) ;
if ( ! V_16 -> V_20 )
return;
if ( V_6 . V_10 . V_11 == V_12 )
F_15 ( V_16 ) ;
else
F_16 ( V_16 ) ;
}
void F_18 ( void )
{
V_6 . V_7 = 4 ;
V_6 . V_23 = 0x01c9 ;
V_6 . V_8 = 0x40 ;
V_6 . V_9 = 0x60 ;
}
void F_19 ( void )
{
V_6 . V_7 = 16 ;
V_6 . V_23 = 0x01c9 ;
V_6 . V_8 = 0x680 ;
V_6 . V_9 = 0x6c0 ;
}
void F_20 ( void )
{
V_6 . V_7 = 8 ;
V_6 . V_23 = 0x01c9 ;
V_6 . V_8 = 0x40 ;
V_6 . V_9 = 0x60 ;
}
