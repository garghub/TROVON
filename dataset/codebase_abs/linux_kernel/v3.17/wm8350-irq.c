static inline struct V_1 * F_1 ( struct V_2 * V_2 ,
int V_3 )
{
return & V_4 [ V_3 - V_2 -> V_5 ] ;
}
static T_1 F_2 ( int V_3 , void * V_6 )
{
struct V_2 * V_2 = V_6 ;
T_2 V_7 ;
T_2 V_8 [ V_9 ] ;
int V_10 [ V_9 ] ;
struct V_1 * V_11 ;
int V_12 ;
V_7 = F_3 ( V_2 , V_13 )
& ~ F_3 ( V_2 , V_14 ) ;
if ( ! V_7 )
return V_15 ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
for ( V_12 = 0 ; V_12 < F_4 ( V_4 ) ; V_12 ++ ) {
V_11 = & V_4 [ V_12 ] ;
if ( ! ( V_7 & V_11 -> V_16 ) )
continue;
if ( ! V_10 [ V_11 -> V_17 ] ) {
V_8 [ V_11 -> V_17 ] =
F_3 ( V_2 , V_18 +
V_11 -> V_17 ) ;
V_8 [ V_11 -> V_17 ] &= ~ V_2 -> V_19 [ V_11 -> V_17 ] ;
V_10 [ V_11 -> V_17 ] = 1 ;
}
if ( V_8 [ V_11 -> V_17 ] & V_11 -> V_20 )
F_5 ( V_2 -> V_5 + V_12 ) ;
}
return V_21 ;
}
static void F_6 ( struct V_6 * V_11 )
{
struct V_2 * V_2 = F_7 ( V_11 ) ;
F_8 ( & V_2 -> V_22 ) ;
}
static void F_9 ( struct V_6 * V_11 )
{
struct V_2 * V_2 = F_7 ( V_11 ) ;
int V_12 ;
for ( V_12 = 0 ; V_12 < F_4 ( V_2 -> V_19 ) ; V_12 ++ ) {
F_10 ( F_11 ( V_2 -> V_23 ,
V_24 + V_12 ,
0xffff , V_2 -> V_19 [ V_12 ] ) ) ;
}
F_12 ( & V_2 -> V_22 ) ;
}
static void F_13 ( struct V_6 * V_11 )
{
struct V_2 * V_2 = F_7 ( V_11 ) ;
struct V_1 * V_6 = F_1 ( V_2 ,
V_11 -> V_3 ) ;
V_2 -> V_19 [ V_6 -> V_17 ] &= ~ V_6 -> V_20 ;
}
static void F_14 ( struct V_6 * V_11 )
{
struct V_2 * V_2 = F_7 ( V_11 ) ;
struct V_1 * V_6 = F_1 ( V_2 ,
V_11 -> V_3 ) ;
V_2 -> V_19 [ V_6 -> V_17 ] |= V_6 -> V_20 ;
}
int F_15 ( struct V_2 * V_2 , int V_3 ,
struct V_25 * V_26 )
{
int V_27 , V_28 , V_12 ;
int V_29 = V_30 ;
int V_5 = - 1 ;
if ( ! V_3 ) {
F_16 ( V_2 -> V_31 , L_1 ) ;
return 0 ;
}
F_17 ( V_2 , V_14 , 0xFFFF ) ;
for ( V_12 = 0 ; V_12 < F_4 ( V_2 -> V_19 ) ; V_12 ++ ) {
F_17 ( V_2 , V_24 + V_12 ,
0xFFFF ) ;
V_2 -> V_19 [ V_12 ] =
F_3 ( V_2 ,
V_24 + V_12 ) ;
}
F_18 ( & V_2 -> V_22 ) ;
V_2 -> V_32 = V_3 ;
if ( V_26 && V_26 -> V_5 > 0 )
V_5 = V_26 -> V_5 ;
V_2 -> V_5 =
F_19 ( V_5 , 0 , F_4 ( V_4 ) , 0 ) ;
if ( V_2 -> V_5 < 0 ) {
F_16 ( V_2 -> V_31 , L_2 ,
V_2 -> V_5 ) ;
return 0 ;
}
if ( V_26 && V_26 -> V_33 ) {
V_29 |= V_34 ;
F_20 ( V_2 , V_35 ,
V_36 ) ;
} else {
V_29 |= V_37 ;
F_21 ( V_2 , V_35 ,
V_36 ) ;
}
for ( V_28 = V_2 -> V_5 ;
V_28 < F_4 ( V_4 ) + V_2 -> V_5 ;
V_28 ++ ) {
F_22 ( V_28 , V_2 ) ;
F_23 ( V_28 , & V_38 ,
V_39 ) ;
F_24 ( V_28 , 1 ) ;
#ifdef F_25
F_26 ( V_28 , V_40 ) ;
#else
F_27 ( V_28 ) ;
#endif
}
V_27 = F_28 ( V_3 , NULL , F_2 , V_29 ,
L_3 , V_2 ) ;
if ( V_27 != 0 )
F_29 ( V_2 -> V_31 , L_4 , V_27 ) ;
F_17 ( V_2 , V_14 , 0 ) ;
return V_27 ;
}
int F_30 ( struct V_2 * V_2 )
{
F_31 ( V_2 -> V_32 , V_2 ) ;
return 0 ;
}
