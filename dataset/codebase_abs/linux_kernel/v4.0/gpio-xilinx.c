static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 >= V_2 -> V_4 [ 0 ] )
return 1 ;
return 0 ;
}
static inline int F_2 ( struct V_1 * V_2 , int V_3 )
{
if ( F_1 ( V_2 , V_3 ) )
return V_5 ;
return 0 ;
}
static inline int F_3 ( struct V_1 * V_2 , int V_3 )
{
if ( F_1 ( V_2 , V_3 ) )
return V_3 - V_2 -> V_4 [ 0 ] ;
return V_3 ;
}
static int F_4 ( struct V_6 * V_7 , unsigned int V_3 )
{
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 =
F_6 ( V_9 , struct V_1 , V_10 ) ;
T_1 V_11 ;
V_11 = F_7 ( V_9 -> V_12 + V_13 +
F_2 ( V_2 , V_3 ) ) ;
return ! ! ( V_11 & F_8 ( F_3 ( V_2 , V_3 ) ) ) ;
}
static void F_9 ( struct V_6 * V_7 , unsigned int V_3 , int V_11 )
{
unsigned long V_14 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 =
F_6 ( V_9 , struct V_1 , V_10 ) ;
int V_15 = F_1 ( V_2 , V_3 ) ;
int V_16 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_17 [ V_15 ] , V_14 ) ;
if ( V_11 )
V_2 -> V_18 [ V_15 ] |= F_8 ( V_16 ) ;
else
V_2 -> V_18 [ V_15 ] &= ~ F_8 ( V_16 ) ;
F_11 ( V_9 -> V_12 + V_13 +
F_2 ( V_2 , V_3 ) , V_2 -> V_18 [ V_15 ] ) ;
F_12 ( & V_2 -> V_17 [ V_15 ] , V_14 ) ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_3 )
{
unsigned long V_14 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 =
F_6 ( V_9 , struct V_1 , V_10 ) ;
int V_15 = F_1 ( V_2 , V_3 ) ;
int V_16 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_17 [ V_15 ] , V_14 ) ;
V_2 -> V_19 [ V_15 ] |= F_8 ( V_16 ) ;
F_11 ( V_9 -> V_12 + V_20 +
F_2 ( V_2 , V_3 ) , V_2 -> V_19 [ V_15 ] ) ;
F_12 ( & V_2 -> V_17 [ V_15 ] , V_14 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , unsigned int V_3 , int V_11 )
{
unsigned long V_14 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 =
F_6 ( V_9 , struct V_1 , V_10 ) ;
int V_15 = F_1 ( V_2 , V_3 ) ;
int V_16 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_17 [ V_15 ] , V_14 ) ;
if ( V_11 )
V_2 -> V_18 [ V_15 ] |= F_8 ( V_16 ) ;
else
V_2 -> V_18 [ V_15 ] &= ~ F_8 ( V_16 ) ;
F_11 ( V_9 -> V_12 + V_13 +
F_2 ( V_2 , V_3 ) , V_2 -> V_18 [ V_15 ] ) ;
V_2 -> V_19 [ V_15 ] &= ~ F_8 ( V_16 ) ;
F_11 ( V_9 -> V_12 + V_20 +
F_2 ( V_2 , V_3 ) , V_2 -> V_19 [ V_15 ] ) ;
F_12 ( & V_2 -> V_17 [ V_15 ] , V_14 ) ;
return 0 ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_6 ( V_9 , struct V_1 , V_10 ) ;
F_11 ( V_9 -> V_12 + V_13 , V_2 -> V_18 [ 0 ] ) ;
F_11 ( V_9 -> V_12 + V_20 , V_2 -> V_19 [ 0 ] ) ;
if ( ! V_2 -> V_4 [ 1 ] )
return;
F_11 ( V_9 -> V_12 + V_13 + V_20 ,
V_2 -> V_18 [ 1 ] ) ;
F_11 ( V_9 -> V_12 + V_20 + V_20 ,
V_2 -> V_19 [ 1 ] ) ;
}
static int F_16 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_17 ( V_22 ) ;
F_18 ( & V_2 -> V_10 ) ;
return 0 ;
}
static int F_19 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_23 = 0 ;
struct V_24 * V_25 = V_22 -> V_26 . V_27 ;
T_1 V_28 ;
V_2 = F_20 ( & V_22 -> V_26 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
F_21 ( V_22 , V_2 ) ;
F_22 ( V_25 , L_1 , & V_2 -> V_18 [ 0 ] ) ;
if ( F_22 ( V_25 , L_2 , & V_2 -> V_19 [ 0 ] ) )
V_2 -> V_19 [ 0 ] = 0xFFFFFFFF ;
if ( F_22 ( V_25 , L_3 , & V_2 -> V_4 [ 0 ] ) )
V_2 -> V_4 [ 0 ] = 32 ;
F_23 ( & V_2 -> V_17 [ 0 ] ) ;
if ( F_22 ( V_25 , L_4 , & V_28 ) )
V_28 = 0 ;
if ( V_28 ) {
F_22 ( V_25 , L_5 ,
& V_2 -> V_18 [ 1 ] ) ;
if ( F_22 ( V_25 , L_6 ,
& V_2 -> V_19 [ 1 ] ) )
V_2 -> V_19 [ 1 ] = 0xFFFFFFFF ;
if ( F_22 ( V_25 , L_7 ,
& V_2 -> V_4 [ 1 ] ) )
V_2 -> V_4 [ 1 ] = 32 ;
F_23 ( & V_2 -> V_17 [ 1 ] ) ;
}
V_2 -> V_10 . V_7 . V_31 = V_2 -> V_4 [ 0 ] + V_2 -> V_4 [ 1 ] ;
V_2 -> V_10 . V_7 . V_26 = & V_22 -> V_26 ;
V_2 -> V_10 . V_7 . V_32 = F_13 ;
V_2 -> V_10 . V_7 . V_33 = F_14 ;
V_2 -> V_10 . V_7 . V_34 = F_4 ;
V_2 -> V_10 . V_7 . V_35 = F_9 ;
V_2 -> V_10 . V_36 = F_15 ;
V_23 = F_24 ( V_25 , & V_2 -> V_10 ) ;
if ( V_23 ) {
F_25 ( L_8 ,
V_25 -> V_37 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_38 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_38 ) ;
}
