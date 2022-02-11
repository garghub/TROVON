static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
F_2 ( V_2 ) ;
V_4 = F_3 ( & V_5 , V_2 -> V_6 * 1000 ) ;
V_2 -> V_6 = F_4 ( & V_5 , V_4 ) / 1000 ;
V_4 = F_3 ( & V_5 , V_2 -> V_7 * 1000 ) ;
V_2 -> V_7 = F_4 ( & V_5 , V_4 ) / 1000 ;
F_2 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
unsigned int V_8 ,
unsigned int V_9 )
{
T_1 V_10 ;
int V_11 = V_2 -> V_11 ;
struct V_3 V_4 ;
struct V_12 V_13 ;
T_2 V_14 ;
V_10 = V_15 -> V_10 ;
F_6 ( V_15 , F_7 ( V_11 ) ) ;
F_8 ( V_11 != F_9 () ) ;
V_14 = F_10 ( V_16 + V_17 ) ;
if ( F_11 () )
V_4 . V_18 = ( V_14 >> 8 ) & 7 ;
else if ( F_12 () )
V_4 . V_18 = 1 ;
V_4 . V_19 = V_14 & 255 ;
V_4 . V_20 = 22 ;
V_13 . V_21 = F_4 ( & V_5 , V_4 ) / 1000 ;
if ( V_9 == V_22 )
V_8 += 999 ;
if ( V_8 > V_2 -> V_6 )
V_8 = V_2 -> V_6 ;
V_4 = F_3 ( & V_5 , V_8 * 1000 ) ;
V_13 . V_23 = F_4 ( & V_5 , V_4 ) / 1000 ;
if ( V_13 . V_21 == V_13 . V_23 ) {
F_6 ( V_15 , & V_10 ) ;
return 0 ;
}
F_13 ( V_2 , & V_13 ) ;
V_14 = F_10 ( V_16 + V_17 ) ;
if ( F_11 () ) {
V_14 &= 0xfffff800 ;
V_14 |= V_4 . V_18 << 8 ;
} else if ( F_12 () ) {
V_14 &= 0xffffff00 ;
}
V_14 |= V_4 . V_19 ;
F_14 ( 0xa05f , V_16 + V_24 ) ;
F_14 ( V_14 , V_16 + V_17 ) ;
F_14 ( 0 , V_16 + V_24 ) ;
F_6 ( V_15 , & V_10 ) ;
F_15 ( V_2 , & V_13 , 0 ) ;
return 0 ;
}
static unsigned int F_16 ( unsigned int V_11 )
{
T_1 V_10 ;
unsigned int V_25 ;
T_2 V_14 ;
struct V_3 V_4 ;
V_10 = V_15 -> V_10 ;
F_6 ( V_15 , F_7 ( V_11 ) ) ;
F_8 ( V_11 != F_9 () ) ;
V_14 = F_10 ( V_16 + V_17 ) ;
if ( F_11 () )
V_4 . V_18 = ( V_14 >> 8 ) & 7 ;
else
V_4 . V_18 = 1 ;
V_4 . V_19 = V_14 & 255 ;
V_4 . V_20 = 22 ;
V_25 = F_4 ( & V_5 , V_4 ) / 1000 ;
F_6 ( V_15 , & V_10 ) ;
return V_25 ;
}
static int F_17 ( struct V_1 * V_2 )
{
V_2 -> V_6 = V_2 -> V_26 . V_27 = 160000 ;
V_2 -> V_7 = V_2 -> V_26 . V_28 = 12000 ;
V_2 -> V_26 . V_29 = 1000000 ;
return 0 ;
}
static int T_3 F_18 ( struct V_30 * V_31 )
{
struct V_32 * V_33 ;
V_33 = F_19 ( V_31 , V_34 , 0 ) ;
if ( ! V_33 )
return - V_35 ;
V_16 = F_20 ( & V_31 -> V_36 , V_33 -> V_37 , F_21 ( V_33 ) ) ;
if ( ! V_16 )
return - V_35 ;
return F_22 ( & V_38 ) ;
}
static int T_4 F_23 ( struct V_30 * V_31 )
{
return F_24 ( & V_38 ) ;
}
