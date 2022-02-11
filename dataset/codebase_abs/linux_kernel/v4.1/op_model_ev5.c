static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
int V_7 , int V_8 )
{
int V_9 , V_10 , V_11 , V_12 ;
V_10 = 0 ;
for ( V_9 = 0 ; V_9 < 3 ; ++ V_9 ) {
unsigned long V_13 = V_4 [ V_9 ] . V_13 ;
if ( ! V_4 [ V_9 ] . V_14 )
continue;
if ( V_9 == 2 ) {
if ( V_13 == 0 )
V_13 = 12 + 48 ;
else if ( V_13 == 2 + 41 )
V_13 = 4 + 65 ;
}
if ( V_13 < 2 )
V_10 |= V_13 << 31 ;
else if ( V_13 < 24 )
;
else if ( V_13 < 40 )
V_10 |= ( V_13 - 24 ) << 4 ;
else if ( V_13 < 48 )
V_10 |= ( V_13 - 40 ) << V_7 | 15 << 4 ;
else if ( V_13 < 64 )
V_10 |= V_13 - 48 ;
else if ( V_13 < 72 )
V_10 |= ( V_13 - 64 ) << V_8 | 15 ;
}
V_2 -> V_15 = V_10 ;
V_10 = 0 ;
V_10 |= ! V_6 -> V_16 << 9 ;
V_10 |= ! V_6 -> V_17 << 8 ;
V_10 |= ! V_6 -> V_18 << 30 ;
V_2 -> V_19 = V_10 ;
V_10 = V_11 = V_12 = 0 ;
for ( V_9 = 0 ; V_9 < 3 ; ++ V_9 ) {
unsigned long V_20 , V_21 , V_22 = V_4 [ V_9 ] . V_22 ;
if ( ! V_4 [ V_9 ] . V_14 )
continue;
if ( V_22 <= 256 )
V_22 = 256 , V_21 = 3 , V_20 = 256 ;
else {
V_20 = ( V_9 == 2 ? 16384 : 65536 ) ;
V_21 = 2 ;
if ( V_22 > V_20 )
V_22 = V_20 ;
}
V_4 [ V_9 ] . V_22 = V_22 ;
V_10 |= V_21 << ( 8 - V_9 * 2 ) ;
V_11 |= ( V_20 - V_22 ) << ( 48 - 16 * V_9 ) ;
if ( V_22 != V_20 )
V_12 |= 1 << V_9 ;
}
V_2 -> V_23 = V_10 ;
V_2 -> V_24 = V_11 ;
V_2 -> V_12 = V_12 ;
}
static void
F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_1 ( V_2 , V_4 , V_6 , 19 , 22 ) ;
}
static void
F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
F_1 ( V_2 , V_4 , V_6 , 8 , 11 ) ;
}
static void
F_4 ( void * V_25 )
{
struct V_1 * V_2 = V_25 ;
F_5 ( 2 , V_2 -> V_15 ) ;
F_5 ( 3 , V_2 -> V_19 ) ;
F_5 ( 4 , V_2 -> V_23 ) ;
F_5 ( 6 , V_2 -> V_24 ) ;
}
static void
F_6 ( struct V_1 * V_2 , unsigned long V_4 )
{
unsigned long V_26 , V_27 , V_28 , V_24 ;
V_27 = ( V_4 == 0 ? 0xfffful << 48
: V_4 == 1 ? 0xfffful << 32
: 0x3fff << 16 ) ;
V_28 = 1 << 9 | 1 << 8 ;
V_24 = V_2 -> V_24 ;
if ( ( V_2 -> V_19 & V_28 ) == V_28 ) {
V_26 = F_5 ( 5 , 0 ) ;
V_26 = ( V_24 & V_27 ) | ( V_26 & ~ V_27 & - 2 ) ;
F_5 ( 6 , V_26 ) ;
} else {
F_5 ( 0 , - 1 ) ;
V_26 = F_5 ( 5 , 0 ) ;
V_26 = ( V_24 & V_27 ) | ( V_26 & ~ V_27 & - 2 ) ;
F_5 ( 6 , V_26 ) ;
F_5 ( 1 , V_2 -> V_29 ) ;
}
}
static void
F_7 ( unsigned long V_30 , struct V_31 * V_32 ,
struct V_3 * V_4 )
{
F_8 ( V_32 , V_30 ) ;
}
