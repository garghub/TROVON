static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 , unsigned int V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 , unsigned int V_4 )
{
return F_4 ( V_2 -> V_5 + V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_6 )
{
if ( ! V_2 -> V_5 )
return;
while ( F_3 ( V_2 , V_7 ) & V_8 )
F_6 () ;
F_1 ( V_2 , V_6 , V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 , const char * V_10 ,
T_2 V_11 )
{
T_1 V_12 , V_3 ;
unsigned long V_13 ;
int V_14 ;
F_8 ( V_13 ) ;
if ( V_2 -> V_15 )
V_14 = 0 ;
else if ( V_16 )
V_14 = F_9 ( & V_2 -> V_17 ) ;
else {
F_10 ( & V_2 -> V_17 ) ;
V_14 = 1 ;
}
V_12 = F_3 ( V_2 , V_18 ) ;
V_3 = V_12 | V_19 ;
V_3 &= ~ ( V_20 | V_21 ) ;
F_1 ( V_2 , V_3 , V_18 ) ;
F_11 ( V_2 , V_10 , V_11 , F_5 ) ;
while ( F_3 ( V_2 , V_7 ) & V_22 )
F_6 () ;
V_3 = F_3 ( V_2 , V_7 ) ;
V_3 |= V_23 | V_24 ;
F_1 ( V_2 , V_3 , V_7 ) ;
F_1 ( V_2 , V_12 , V_18 ) ;
if ( V_14 )
F_12 ( & V_2 -> V_17 ) ;
F_13 ( V_13 ) ;
}
static void F_14 ( struct V_25 * V_26 ,
const char * V_10 ,
T_2 V_11 )
{
struct V_27 * V_28 = V_26 -> V_29 ;
F_7 ( & V_28 -> V_2 , V_10 , V_11 ) ;
}
static int T_3
F_15 ( struct V_27 * V_30 , const char * V_31 )
{
if ( ! V_30 -> V_2 . V_5 )
return - V_32 ;
V_30 -> V_33 -> V_34 = F_14 ;
return 0 ;
}
