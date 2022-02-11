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
static void F_13 ( struct V_6 * V_7 , unsigned long * V_18 ,
unsigned long * V_19 )
{
unsigned long V_13 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_14 = F_1 ( V_2 , 0 ) ;
int V_15 , V_20 ;
F_10 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
for ( V_20 = 0 ; V_20 < V_7 -> V_21 ; V_20 ++ ) {
if ( * V_18 == 0 )
break;
if ( V_14 != F_1 ( V_2 , V_20 ) ) {
F_11 ( V_9 -> V_11 + V_12 +
F_2 ( V_2 , V_20 ) ,
V_2 -> V_17 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
V_14 = F_1 ( V_2 , V_20 ) ;
F_10 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
}
if ( F_14 ( V_20 , V_18 ) ) {
V_15 = F_3 ( V_2 , V_20 ) ;
if ( F_15 ( V_20 , V_19 ) )
V_2 -> V_17 [ V_14 ] |= F_8 ( V_15 ) ;
else
V_2 -> V_17 [ V_14 ] &= ~ F_8 ( V_15 ) ;
}
}
F_11 ( V_9 -> V_11 + V_12 +
F_2 ( V_2 , V_20 ) , V_2 -> V_17 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
}
static int F_16 ( struct V_6 * V_7 , unsigned int V_3 )
{
unsigned long V_13 ;
struct V_8 * V_9 = F_5 ( V_7 ) ;
struct V_1 * V_2 = F_6 ( V_7 ) ;
int V_14 = F_1 ( V_2 , V_3 ) ;
int V_15 = F_3 ( V_2 , V_3 ) ;
F_10 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
V_2 -> V_22 [ V_14 ] |= F_8 ( V_15 ) ;
F_11 ( V_9 -> V_11 + V_23 +
F_2 ( V_2 , V_3 ) , V_2 -> V_22 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , unsigned int V_3 , int V_10 )
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
V_2 -> V_22 [ V_14 ] &= ~ F_8 ( V_15 ) ;
F_11 ( V_9 -> V_11 + V_23 +
F_2 ( V_2 , V_3 ) , V_2 -> V_22 [ V_14 ] ) ;
F_12 ( & V_2 -> V_16 [ V_14 ] , V_13 ) ;
return 0 ;
}
static void F_18 ( struct V_8 * V_9 )
{
struct V_1 * V_2 =
F_19 ( V_9 , struct V_1 , V_24 ) ;
F_11 ( V_9 -> V_11 + V_12 , V_2 -> V_17 [ 0 ] ) ;
F_11 ( V_9 -> V_11 + V_23 , V_2 -> V_22 [ 0 ] ) ;
if ( ! V_2 -> V_4 [ 1 ] )
return;
F_11 ( V_9 -> V_11 + V_12 + V_5 ,
V_2 -> V_17 [ 1 ] ) ;
F_11 ( V_9 -> V_11 + V_23 + V_5 ,
V_2 -> V_22 [ 1 ] ) ;
}
static int F_20 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_21 ( V_26 ) ;
F_22 ( & V_2 -> V_24 ) ;
return 0 ;
}
static int F_23 ( struct V_25 * V_26 )
{
struct V_1 * V_2 ;
int V_27 = 0 ;
struct V_28 * V_29 = V_26 -> V_30 . V_31 ;
T_1 V_32 ;
V_2 = F_24 ( & V_26 -> V_30 , sizeof( * V_2 ) , V_33 ) ;
if ( ! V_2 )
return - V_34 ;
F_25 ( V_26 , V_2 ) ;
F_26 ( V_29 , L_1 , & V_2 -> V_17 [ 0 ] ) ;
if ( F_26 ( V_29 , L_2 , & V_2 -> V_22 [ 0 ] ) )
V_2 -> V_22 [ 0 ] = 0xFFFFFFFF ;
if ( F_26 ( V_29 , L_3 , & V_2 -> V_4 [ 0 ] ) )
V_2 -> V_4 [ 0 ] = 32 ;
F_27 ( & V_2 -> V_16 [ 0 ] ) ;
if ( F_26 ( V_29 , L_4 , & V_32 ) )
V_32 = 0 ;
if ( V_32 ) {
F_26 ( V_29 , L_5 ,
& V_2 -> V_17 [ 1 ] ) ;
if ( F_26 ( V_29 , L_6 ,
& V_2 -> V_22 [ 1 ] ) )
V_2 -> V_22 [ 1 ] = 0xFFFFFFFF ;
if ( F_26 ( V_29 , L_7 ,
& V_2 -> V_4 [ 1 ] ) )
V_2 -> V_4 [ 1 ] = 32 ;
F_27 ( & V_2 -> V_16 [ 1 ] ) ;
}
V_2 -> V_24 . V_7 . V_21 = V_2 -> V_4 [ 0 ] + V_2 -> V_4 [ 1 ] ;
V_2 -> V_24 . V_7 . V_35 = & V_26 -> V_30 ;
V_2 -> V_24 . V_7 . V_36 = F_16 ;
V_2 -> V_24 . V_7 . V_37 = F_17 ;
V_2 -> V_24 . V_7 . V_38 = F_4 ;
V_2 -> V_24 . V_7 . V_39 = F_9 ;
V_2 -> V_24 . V_7 . V_40 = F_13 ;
V_2 -> V_24 . V_41 = F_18 ;
V_27 = F_28 ( V_29 , & V_2 -> V_24 , V_2 ) ;
if ( V_27 ) {
F_29 ( L_8 ,
V_29 -> V_42 , V_27 ) ;
return V_27 ;
}
return 0 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_43 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_43 ) ;
}
