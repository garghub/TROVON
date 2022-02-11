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
struct V_1 * V_2 = F_6 ( V_7 ) ;
T_1 V_10 ;
V_10 = F_7 ( V_9 -> V_11 + V_12 +
F_2 ( V_2 , V_3 ) ) ;
return ! ! ( V_10 & F_8 ( F_3 ( V_2 , V_3 ) ) ) ;
}
static void F_9 ( struct V_6 * V_7 , unsigned int V_3 , int V_10 )
{
unsigned long V_13 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_14 = F_1 ( V_2 , V_3 ) ;
int V_15 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
if ( V_10 )
V_2 -> V_17 [ V_14 ] |= F_8 ( V_15 ) ;
else
V_2 -> V_17 [ V_14 ] &= ~ F_8 ( V_15 ) ;
F_11 ( V_9 -> V_11 + V_12 +
F_2 ( V_2 , V_3 ) , V_2 -> V_17 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
}
static int F_13 ( struct V_6 * V_7 , unsigned int V_3 )
{
unsigned long V_13 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_14 = F_1 ( V_2 , V_3 ) ;
int V_15 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
V_2 -> V_18 [ V_14 ] |= F_8 ( V_15 ) ;
F_11 ( V_9 -> V_11 + V_19 +
F_2 ( V_2 , V_3 ) , V_2 -> V_18 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 , unsigned int V_3 , int V_10 )
{
unsigned long V_13 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_14 = F_1 ( V_2 , V_3 ) ;
int V_15 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
if ( V_10 )
V_2 -> V_17 [ V_14 ] |= F_8 ( V_15 ) ;
else
V_2 -> V_17 [ V_14 ] &= ~ F_8 ( V_15 ) ;
F_11 ( V_9 -> V_11 + V_12 +
F_2 ( V_2 , V_3 ) , V_2 -> V_17 [ V_14 ] ) ;
V_2 -> V_18 [ V_14 ] &= ~ F_8 ( V_15 ) ;
F_11 ( V_9 -> V_11 + V_19 +
F_2 ( V_2 , V_3 ) , V_2 -> V_18 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
return 0 ;
}
static void F_15 ( struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_16 ( V_9 , struct V_1 , V_20 ) ;
F_11 ( V_9 -> V_11 + V_12 , V_2 -> V_17 [ 0 ] ) ;
F_11 ( V_9 -> V_11 + V_19 , V_2 -> V_18 [ 0 ] ) ;
if ( ! V_2 -> V_4 [ 1 ] )
return;
F_11 ( V_9 -> V_11 + V_12 + V_5 ,
V_2 -> V_17 [ 1 ] ) ;
F_11 ( V_9 -> V_11 + V_19 + V_5 ,
V_2 -> V_18 [ 1 ] ) ;
}
static int F_17 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_18 ( V_22 ) ;
F_19 ( & V_2 -> V_20 ) ;
return 0 ;
}
static int F_20 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
int V_23 = 0 ;
struct V_24 * V_25 = V_22 -> V_26 . V_27 ;
T_1 V_28 ;
V_2 = F_21 ( & V_22 -> V_26 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
F_22 ( V_22 , V_2 ) ;
F_23 ( V_25 , L_1 , & V_2 -> V_17 [ 0 ] ) ;
if ( F_23 ( V_25 , L_2 , & V_2 -> V_18 [ 0 ] ) )
V_2 -> V_18 [ 0 ] = 0xFFFFFFFF ;
if ( F_23 ( V_25 , L_3 , & V_2 -> V_4 [ 0 ] ) )
V_2 -> V_4 [ 0 ] = 32 ;
F_24 ( & V_2 -> V_16 [ 0 ] ) ;
if ( F_23 ( V_25 , L_4 , & V_28 ) )
V_28 = 0 ;
if ( V_28 ) {
F_23 ( V_25 , L_5 ,
& V_2 -> V_17 [ 1 ] ) ;
if ( F_23 ( V_25 , L_6 ,
& V_2 -> V_18 [ 1 ] ) )
V_2 -> V_18 [ 1 ] = 0xFFFFFFFF ;
if ( F_23 ( V_25 , L_7 ,
& V_2 -> V_4 [ 1 ] ) )
V_2 -> V_4 [ 1 ] = 32 ;
F_24 ( & V_2 -> V_16 [ 1 ] ) ;
}
V_2 -> V_20 . V_7 . V_31 = V_2 -> V_4 [ 0 ] + V_2 -> V_4 [ 1 ] ;
V_2 -> V_20 . V_7 . V_32 = & V_22 -> V_26 ;
V_2 -> V_20 . V_7 . V_33 = F_13 ;
V_2 -> V_20 . V_7 . V_34 = F_14 ;
V_2 -> V_20 . V_7 . V_35 = F_4 ;
V_2 -> V_20 . V_7 . V_36 = F_9 ;
V_2 -> V_20 . V_37 = F_15 ;
V_23 = F_25 ( V_25 , & V_2 -> V_20 , V_2 ) ;
if ( V_23 ) {
F_26 ( L_8 ,
V_25 -> V_38 , V_23 ) ;
return V_23 ;
}
return 0 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_39 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_39 ) ;
}
