static void
F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 = 1UL << ( V_2 -> V_4 - V_5 ) ;
unsigned long V_6 ;
V_6 = F_2 ( V_7 ) ;
F_3 ( V_6 | V_3 , V_7 ) ;
V_6 = F_2 ( V_8 ) ;
F_3 ( V_6 | V_3 , V_8 ) ;
}
static inline void
F_4 ( struct V_1 * V_2 )
{
unsigned long V_3 = 1UL << ( V_2 -> V_4 - V_5 ) ;
F_3 ( V_3 , V_9 ) ;
F_3 ( V_3 , V_10 ) ;
F_3 ( V_3 , V_11 ) ;
}
static inline void
F_5 ( struct V_1 * V_2 )
{
unsigned long V_3 = 1UL << ( V_2 -> V_4 - V_5 ) ;
unsigned long V_6 ;
V_6 = F_2 ( V_7 ) ;
F_3 ( V_6 | V_3 , V_7 ) ;
V_6 = F_2 ( V_8 ) ;
F_3 ( V_6 | V_3 , V_8 ) ;
F_3 ( V_3 , V_9 ) ;
F_3 ( V_3 , V_10 ) ;
F_3 ( V_3 , V_11 ) ;
}
static void
F_6 ( struct V_1 * V_2 )
{
unsigned long V_3 = 1UL << ( V_2 -> V_4 - V_5 ) ;
unsigned long V_6 ;
V_6 = F_2 ( V_8 ) ;
F_3 ( V_6 & ~ V_3 , V_8 ) ;
V_6 = F_2 ( V_7 ) ;
F_3 ( V_6 & ~ V_3 , V_7 ) ;
}
static void F_7 ( unsigned int V_4 , struct V_12 * V_13 )
{
unsigned int V_14 , V_15 ;
V_14 = F_2 ( V_16 ) ;
V_15 = F_2 ( V_17 ) ;
V_14 &= ~ V_15 ;
if ( V_14 & F_8 ( V_18 ) )
F_9 ( V_18 ) ;
if ( V_14 & F_8 ( V_19 ) )
F_9 ( V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( V_2 -> V_4 , V_20 , V_21 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_13 ( V_2 -> V_4 , V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_4 , V_20 , V_21 ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned int V_22 )
{
unsigned long V_23 ;
V_23 = F_2 ( V_24 ) ;
if ( V_22 )
V_23 &= ~ V_25 ;
else
V_23 |= V_25 ;
F_3 ( V_23 , V_24 ) ;
return V_26 . V_27 ( V_2 , V_22 ) ;
}
static int F_17 ( struct V_28 * V_29 , struct V_30 * V_31 )
{
unsigned int V_32 ;
for ( V_32 = V_5 ; V_32 <= V_33 ; V_32 ++ ) {
F_18 ( V_32 , & V_34 ,
V_35 ) ;
F_19 ( V_32 , V_36 ) ;
}
F_20 ( V_37 , F_7 ) ;
for ( V_32 = V_18 ; V_32 <= V_19 ; V_32 ++ ) {
F_18 ( V_32 , & V_38 ,
V_39 ) ;
F_19 ( V_32 , V_36 ) ;
}
V_40 = V_26 ;
V_40 . V_27 = F_16 ;
F_21 ( V_41 , & V_40 ) ;
return 0 ;
}
static int F_22 ( void )
{
return F_23 ( & V_42 ) ;
}
