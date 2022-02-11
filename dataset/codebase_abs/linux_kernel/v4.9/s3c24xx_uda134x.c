static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
#ifdef F_2
struct V_8 * V_9 = V_2 -> V_9 ;
#endif
int V_10 = 0 ;
F_3 ( & V_11 ) ;
if ( V_12 == 0 ) {
V_13 = F_4 ( V_4 -> V_14 , L_1 ) ;
if ( F_5 ( V_13 ) ) {
F_6 ( V_4 -> V_14 , L_2 , V_15 ) ;
V_10 = F_7 ( V_13 ) ;
} else {
V_16 = F_4 ( V_7 -> V_14 , L_3 ) ;
if ( F_5 ( V_16 ) ) {
F_6 ( V_4 -> V_14 , L_4 ,
V_15 ) ;
F_8 ( V_13 ) ;
V_10 = F_7 ( V_16 ) ;
}
}
if ( ! V_10 ) {
int V_17 , V_18 ;
for ( V_17 = 0 ; V_17 < 2 ; V_17 ++ ) {
int V_19 = V_17 ? 256 : 384 ;
V_20 [ V_17 * 33 ] = F_9 ( V_13 ) / V_19 ;
for ( V_18 = 1 ; V_18 < 33 ; V_18 ++ )
V_20 [ V_17 * 33 + V_18 ] = F_9 ( V_16 ) /
( V_18 * V_19 ) ;
}
}
}
V_12 += 1 ;
F_10 ( & V_11 ) ;
if ( ! V_10 ) {
#ifdef F_2
V_10 = F_11 ( V_9 , 0 ,
V_21 ,
& V_22 ) ;
if ( V_10 < 0 )
F_6 ( V_4 -> V_14 , L_5 ,
V_15 ) ;
#endif
}
return V_10 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_3 ( & V_11 ) ;
V_12 -= 1 ;
if ( V_12 == 0 ) {
F_8 ( V_13 ) ;
V_13 = NULL ;
F_8 ( V_16 ) ;
V_16 = NULL ;
}
F_10 ( & V_11 ) ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_25 = V_4 -> V_25 ;
struct V_6 * V_7 = V_4 -> V_7 ;
unsigned int V_26 = 0 ;
int V_10 = 0 ;
int V_27 , V_28 ;
unsigned long V_29 = F_14 ( V_24 ) ;
long V_30 , V_31 ;
unsigned int div ;
int V_17 , V_32 ;
V_30 = 999999 ;
V_32 = 0 ;
for ( V_17 = 0 ; V_17 < 2 * 33 ; V_17 ++ ) {
V_31 = V_20 [ V_17 ] - V_29 ;
if ( V_31 < 0 )
V_31 = - V_31 ;
if ( V_31 < V_30 ) {
V_30 = V_31 ;
V_32 = V_17 ;
}
}
if ( V_32 / 33 == 1 )
V_28 = V_33 ;
else
V_28 = V_34 ;
if ( V_32 % 33 == 0 ) {
V_27 = V_35 ;
div = 1 ;
} else {
V_27 = V_36 ;
div = V_32 % 33 ;
}
F_15 ( V_4 -> V_14 , L_6 , V_15 , V_29 , V_32 ) ;
V_26 = ( V_28 == V_34 ? 384 : 256 ) * V_29 ;
F_15 ( V_4 -> V_14 , L_7 , V_15 ,
V_28 == V_34 ? L_8 : L_9 ,
V_27 == V_35 ? L_10 : L_11 ,
div , V_26 , V_30 ) ;
if ( ( V_30 * 100 / V_29 ) > 5 ) {
F_6 ( V_4 -> V_14 , L_12
L_13 , V_30 * 100 / V_29 ) ;
return - V_37 ;
}
V_10 = F_16 ( V_7 , V_27 , V_26 ,
V_38 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_7 , V_39 , V_28 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_7 , V_40 ,
V_41 ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_17 ( V_7 , V_42 ,
F_18 ( div , div ) ) ;
if ( V_10 < 0 )
return V_10 ;
V_10 = F_16 ( V_25 , 0 , V_26 ,
V_43 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_19 ( struct V_44 * V_45 )
{
struct V_46 * V_47 = & V_48 ;
int V_10 ;
F_20 ( V_45 , V_47 ) ;
V_47 -> V_14 = & V_45 -> V_14 ;
V_10 = F_21 ( & V_45 -> V_14 , V_47 ) ;
if ( V_10 )
F_6 ( & V_45 -> V_14 , L_14 , V_10 ) ;
return V_10 ;
}
