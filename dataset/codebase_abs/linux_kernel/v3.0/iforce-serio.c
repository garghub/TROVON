void F_1 ( struct V_1 * V_1 )
{
unsigned char V_2 ;
int V_3 ;
unsigned long V_4 ;
if ( F_2 ( V_5 , V_1 -> V_6 ) ) {
F_3 ( V_7 , V_1 -> V_6 ) ;
return;
}
F_4 ( & V_1 -> V_8 , V_4 ) ;
V_9:
if ( V_1 -> V_10 . V_11 == V_1 -> V_10 . V_12 ) {
F_5 ( V_5 , V_1 -> V_6 ) ;
F_6 ( & V_1 -> V_8 , V_4 ) ;
return;
}
V_2 = 0x2b ;
F_7 ( V_1 -> V_13 , 0x2b ) ;
F_7 ( V_1 -> V_13 , V_1 -> V_10 . V_14 [ V_1 -> V_10 . V_12 ] ) ;
V_2 ^= V_1 -> V_10 . V_14 [ V_1 -> V_10 . V_12 ] ;
F_8 ( V_1 -> V_10 . V_12 , 1 ) ;
for ( V_3 = V_1 -> V_10 . V_14 [ V_1 -> V_10 . V_12 ] ; V_3 >= 0 ; -- V_3 ) {
F_7 ( V_1 -> V_13 , V_1 -> V_10 . V_14 [ V_1 -> V_10 . V_12 ] ) ;
V_2 ^= V_1 -> V_10 . V_14 [ V_1 -> V_10 . V_12 ] ;
F_8 ( V_1 -> V_10 . V_12 , 1 ) ;
}
F_7 ( V_1 -> V_13 , V_2 ) ;
if ( F_9 ( V_7 , V_1 -> V_6 ) )
goto V_9;
F_5 ( V_5 , V_1 -> V_6 ) ;
F_6 ( & V_1 -> V_8 , V_4 ) ;
}
static void F_10 ( struct V_13 * V_13 )
{
struct V_1 * V_1 = F_11 ( V_13 ) ;
F_1 ( V_1 ) ;
}
static T_1 F_12 ( struct V_13 * V_13 ,
unsigned char V_15 , unsigned int V_4 )
{
struct V_1 * V_1 = F_11 ( V_13 ) ;
if ( ! V_1 -> V_16 ) {
if ( V_15 == 0x2b )
V_1 -> V_16 = 1 ;
goto V_17;
}
if ( ! V_1 -> V_18 ) {
if ( V_15 > 3 && V_15 != 0xff )
V_1 -> V_16 = 0 ;
else
V_1 -> V_18 = V_15 ;
goto V_17;
}
if ( ! V_1 -> V_19 ) {
if ( V_15 > V_20 ) {
V_1 -> V_16 = 0 ;
V_1 -> V_18 = 0 ;
} else {
V_1 -> V_19 = V_15 ;
}
goto V_17;
}
if ( V_1 -> V_21 < V_1 -> V_19 ) {
V_1 -> V_22 += V_1 -> V_15 [ V_1 -> V_21 ++ ] = V_15 ;
goto V_17;
}
if ( V_1 -> V_21 == V_1 -> V_19 ) {
F_13 ( V_1 , ( V_1 -> V_18 << 8 ) | V_1 -> V_21 , V_1 -> V_15 ) ;
V_1 -> V_16 = 0 ;
V_1 -> V_18 = 0 ;
V_1 -> V_19 = 0 ;
V_1 -> V_21 = 0 ;
V_1 -> V_22 = 0 ;
}
V_17:
return V_23 ;
}
static int F_14 ( struct V_13 * V_13 , struct V_24 * V_25 )
{
struct V_1 * V_1 ;
int V_26 ;
V_1 = F_15 ( sizeof( struct V_1 ) , V_27 ) ;
if ( ! V_1 )
return - V_28 ;
V_1 -> V_29 = V_30 ;
V_1 -> V_13 = V_13 ;
F_16 ( V_13 , V_1 ) ;
V_26 = F_17 ( V_13 , V_25 ) ;
if ( V_26 )
goto V_31;
V_26 = F_18 ( V_1 ) ;
if ( V_26 )
goto V_32;
return 0 ;
V_32: F_19 ( V_13 ) ;
V_31: F_16 ( V_13 , NULL ) ;
F_20 ( V_1 ) ;
return V_26 ;
}
static void F_21 ( struct V_13 * V_13 )
{
struct V_1 * V_1 = F_11 ( V_13 ) ;
F_22 ( V_1 -> V_33 ) ;
F_19 ( V_13 ) ;
F_16 ( V_13 , NULL ) ;
F_20 ( V_1 ) ;
}
