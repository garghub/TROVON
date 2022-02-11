static inline struct V_1 *
F_1 ( struct V_2 * V_3 , int V_4 )
{
return & V_5 [ V_4 - V_3 -> V_6 ] ;
}
static void F_2 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
F_4 ( & V_3 -> V_9 ) ;
}
static void F_5 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
int V_10 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_3 -> V_11 ) ; V_10 ++ ) {
if ( V_3 -> V_11 [ V_10 ] != V_3 -> V_12 [ V_10 ] ) {
V_3 -> V_12 [ V_10 ] = V_3 -> V_11 [ V_10 ] ;
F_7 ( V_3 -> V_13 , V_14 + V_10 ,
V_3 -> V_11 [ V_10 ] ) ;
}
}
F_8 ( & V_3 -> V_9 ) ;
}
static void F_9 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_7 = F_1 ( V_3 ,
V_8 -> V_4 ) ;
V_3 -> V_11 [ V_7 -> V_15 - 1 ] &= ~ V_7 -> V_16 ;
}
static void F_10 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_3 ( V_8 ) ;
struct V_1 * V_7 = F_1 ( V_3 ,
V_8 -> V_4 ) ;
V_3 -> V_11 [ V_7 -> V_15 - 1 ] |= V_7 -> V_16 ;
}
static T_1 F_11 ( int V_4 , void * V_8 )
{
struct V_2 * V_3 = V_8 ;
T_2 V_17 [ V_18 ] ;
int V_19 ;
int V_10 ;
V_19 = F_12 ( V_3 -> V_13 , V_20 ,
V_18 , V_17 ) ;
if ( V_19 < 0 ) {
F_13 ( V_3 -> V_21 , L_1 ,
V_19 ) ;
return V_22 ;
}
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ )
V_17 [ V_10 ] &= ~ V_3 -> V_11 [ V_10 ] ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
if ( V_17 [ V_5 [ V_10 ] . V_15 - 1 ] & V_5 [ V_10 ] . V_16 )
F_14 ( V_3 -> V_6 + V_10 ) ;
}
return V_24 ;
}
int F_15 ( struct V_2 * V_3 )
{
if ( V_3 -> V_4 && V_3 -> V_6 )
F_11 ( V_3 -> V_6 , V_3 ) ;
return 0 ;
}
int F_16 ( struct V_2 * V_3 )
{
int V_10 ;
int V_25 ;
int V_19 ;
if ( ! V_3 -> V_4 ) {
F_17 ( V_3 -> V_21 ,
L_2 ) ;
V_3 -> V_6 = 0 ;
return 0 ;
}
if ( ! V_3 -> V_6 ) {
F_13 ( V_3 -> V_21 ,
L_3 ) ;
return 0 ;
}
F_18 ( & V_3 -> V_9 ) ;
for ( V_10 = 0 ; V_10 < V_18 ; V_10 ++ ) {
V_3 -> V_11 [ V_10 ] = 0xff ;
V_3 -> V_12 [ V_10 ] = 0xff ;
F_7 ( V_3 -> V_13 , V_14 + V_10 , 0xff ) ;
}
F_7 ( V_3 -> V_13 , V_26 , 0xff ) ;
F_7 ( V_3 -> V_13 , V_27 , 0xff ) ;
for ( V_10 = 0 ; V_10 < V_23 ; V_10 ++ ) {
V_25 = V_10 + V_3 -> V_6 ;
F_19 ( V_25 , V_3 ) ;
F_20 ( V_25 , & V_28 ,
V_29 ) ;
F_21 ( V_25 , 1 ) ;
#ifdef F_22
F_23 ( V_25 , V_30 ) ;
#else
F_24 ( V_25 ) ;
#endif
}
V_19 = F_25 ( V_3 -> V_4 , NULL , F_11 ,
V_31 | V_32 ,
L_4 , V_3 ) ;
if ( V_19 ) {
F_13 ( V_3 -> V_21 , L_5 ,
V_3 -> V_4 , V_19 ) ;
return V_19 ;
}
if ( ! V_3 -> V_33 )
return 0 ;
V_19 = F_25 ( V_3 -> V_33 , NULL , F_11 ,
V_31 | V_34 |
V_32 , L_6 , V_3 ) ;
if ( V_19 )
F_13 ( V_3 -> V_21 , L_5 ,
V_3 -> V_33 , V_19 ) ;
return 0 ;
}
void F_26 ( struct V_2 * V_3 )
{
if ( V_3 -> V_33 )
F_27 ( V_3 -> V_33 , V_3 ) ;
if ( V_3 -> V_4 )
F_27 ( V_3 -> V_4 , V_3 ) ;
}
