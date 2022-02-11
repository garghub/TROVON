void F_1 ( int V_1 )
{
struct V_2 * V_3 ;
static T_1 V_4 [ 2 ] ;
if ( V_4 [ V_1 ] )
return;
V_4 [ V_1 ] = 1 ;
for ( V_3 = V_5 ; V_3 < V_6 ; V_3 ++ ) {
if ( V_3 -> V_1 == V_1 ) {
if ( V_3 -> V_7 )
V_3 -> V_8 = V_3 -> V_7 () ;
else
V_3 -> V_8 = 0 ;
}
}
}
int F_2 ( T_2 V_9 )
{
struct V_2 * V_3 ;
struct V_10 * V_11 ;
int V_12 ;
for ( V_3 = V_5 ; V_3 < V_6 ; V_3 ++ ) {
V_11 = V_3 -> V_13 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_8 ; V_12 ++ , V_11 ++ ) {
if ( V_11 -> V_9 == V_9 )
return 1 ;
}
}
return 0 ;
}
static int F_3 ( T_2 V_9 , T_2 * V_14 )
{
int V_15 , V_12 ;
struct V_2 * V_3 ;
struct V_10 * V_11 ;
V_9 &= ~ V_16 ;
V_15 = 0 ;
for ( V_3 = V_5 ; V_3 < V_6 ; V_3 ++ ) {
V_11 = V_3 -> V_13 ;
for ( V_12 = 0 ; V_12 < V_3 -> V_8 ; V_12 ++ , V_11 ++ ) {
int V_17 = V_11 -> V_18 || V_11 -> V_19 ;
if ( ( V_9 == V_15 && V_17 ) ||
V_9 == V_11 -> V_9 ||
V_9 == ( V_11 -> V_19 << 8 ) + V_11 -> V_18 ) {
* V_14 = V_11 -> V_9 ;
return V_3 -> V_20 ( V_11 ) ;
}
if ( V_17 )
V_15 ++ ;
}
}
for ( V_3 = V_5 ; V_3 < V_6 ; V_3 ++ ) {
if ( V_9 >= V_3 -> V_21 &&
V_9 < V_3 -> V_21 + V_3 -> V_22 ) {
struct V_10 V_23 ;
* V_14 = V_23 . V_9 = V_9 ;
V_23 . V_18 = V_23 . V_19 = 0 ;
return V_3 -> V_20 ( & V_23 ) ;
}
}
return - 1 ;
}
static void F_4 ( void )
{
unsigned int V_24 , V_25 ;
T_2 V_26 ;
T_1 V_27 , V_28 ;
F_5 ( 0 ) ;
V_24 = F_6 ( 0x485 ) ;
V_25 = V_29 ? V_29 : F_6 ( 0x484 ) + 1 ;
V_25 *= V_24 ;
V_25 -- ;
V_26 = F_7 () ;
V_27 = F_8 ( V_26 , 0x11 ) ;
V_27 &= ~ 0x80 ;
F_9 ( V_27 , V_26 , 0x11 ) ;
F_9 ( ( T_1 ) V_25 , V_26 , 0x12 ) ;
V_28 = F_8 ( V_26 , 0x07 ) ;
V_28 &= 0xbd ;
V_28 |= ( V_25 >> ( 8 - 1 ) ) & 0x02 ;
V_28 |= ( V_25 >> ( 9 - 6 ) ) & 0x40 ;
F_9 ( V_28 , V_26 , 0x07 ) ;
}
int V_20 ( T_2 V_9 )
{
int V_30 ;
T_2 V_14 ;
if ( V_9 == V_31 )
return 0 ;
else if ( V_9 == V_32 )
V_9 = V_33 ;
else if ( V_9 == V_34 )
V_9 = V_35 ;
V_30 = F_3 ( V_9 , & V_14 ) ;
if ( V_30 )
return V_30 ;
if ( V_9 & V_16 )
F_4 () ;
#ifndef F_10
V_36 . V_37 . V_38 = V_14 ;
#endif
return 0 ;
}
