static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_2 ( V_2 ,
V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_7 ) ;
V_4 = F_3 ( & V_8 , V_2 -> V_9 * 1000 ) ;
V_2 -> V_9 = F_4 ( & V_8 , V_4 ) / 1000 ;
V_4 = F_3 ( & V_8 , V_2 -> V_10 * 1000 ) ;
V_2 -> V_10 = F_4 ( & V_8 , V_4 ) / 1000 ;
F_2 ( V_2 ,
V_2 -> V_5 . V_6 ,
V_2 -> V_5 . V_7 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_11 ,
unsigned int V_12 )
{
T_1 V_13 ;
int V_14 = V_2 -> V_14 ;
struct V_3 V_4 ;
struct V_15 V_16 ;
T_2 V_17 ;
V_13 = V_18 -> V_13 ;
F_6 ( V_18 , F_7 ( V_14 ) ) ;
F_8 ( V_14 != F_9 () ) ;
V_17 = F_10 ( V_19 ) ;
if ( F_11 () ) {
V_4 . V_20 = ( V_17 >> 8 ) & 7 ;
} else if ( F_12 () ) {
V_4 . V_20 = 1 ;
}
V_4 . V_21 = V_17 & 255 ;
V_4 . V_22 = 22 ;
V_16 . V_23 = F_4 ( & V_8 , V_4 ) / 1000 ;
if ( V_12 == V_24 )
V_11 += 999 ;
if ( V_11 > V_2 -> V_9 )
V_11 = V_2 -> V_9 ;
V_4 = F_3 ( & V_8 , V_11 * 1000 ) ;
V_16 . V_25 = F_4 ( & V_8 , V_4 ) / 1000 ;
if ( V_16 . V_23 == V_16 . V_25 ) {
F_6 ( V_18 , V_13 ) ;
return 0 ;
}
F_13 ( V_2 , & V_16 , V_26 ) ;
V_17 = F_10 ( V_19 ) ;
if ( F_11 () ) {
V_17 &= 0xfffff800 ;
V_17 |= V_4 . V_20 << 8 ;
} else if ( F_12 () ) {
V_17 &= 0xffffff00 ;
}
V_17 |= V_4 . V_21 ;
F_14 ( 0xa05f , V_27 ) ;
F_14 ( V_17 , V_19 ) ;
F_14 ( 0 , V_27 ) ;
F_6 ( V_18 , V_13 ) ;
F_13 ( V_2 , & V_16 , V_28 ) ;
return 0 ;
}
static unsigned int F_15 ( unsigned int V_14 )
{
T_1 V_13 ;
unsigned int V_29 ;
T_2 V_17 ;
struct V_3 V_4 ;
V_13 = V_18 -> V_13 ;
F_6 ( V_18 , F_7 ( V_14 ) ) ;
F_8 ( V_14 != F_9 () ) ;
V_17 = F_10 ( V_19 ) ;
if ( F_11 () ) {
V_4 . V_20 = ( V_17 >> 8 ) & 7 ;
} else {
V_4 . V_20 = 1 ;
}
V_4 . V_21 = V_17 & 255 ;
V_4 . V_22 = 22 ;
V_29 = F_4 ( & V_8 , V_4 ) / 1000 ;
F_6 ( V_18 , V_13 ) ;
return V_29 ;
}
static int F_16 ( struct V_1 * V_2 )
{
V_2 -> V_5 . V_7 = 160000 ;
V_2 -> V_5 . V_6 = 12000 ;
V_2 -> V_5 . V_30 = 1000000 ;
V_2 -> V_31 = V_2 -> V_10 = V_2 -> V_9 = F_15 ( V_2 -> V_14 ) ;
return 0 ;
}
static int T_3 F_17 ( void )
{
return F_18 ( & V_32 ) ;
}
static void T_4 F_19 ( void )
{
F_20 ( & V_32 ) ;
}
