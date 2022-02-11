static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
int V_11 = 0 ;
F_3 ( & V_7 -> V_12 ) ;
if ( V_7 -> V_13 == 0 ) {
V_7 -> V_14 = F_4 ( V_4 -> V_15 , L_1 ) ;
if ( F_5 ( V_7 -> V_14 ) ) {
F_6 ( V_4 -> V_15 , L_2 , V_16 ) ;
V_11 = F_7 ( V_7 -> V_14 ) ;
} else {
V_7 -> V_17 = F_4 ( V_10 -> V_15 , L_3 ) ;
if ( F_5 ( V_7 -> V_17 ) ) {
F_6 ( V_4 -> V_15 , L_4 ,
V_16 ) ;
F_8 ( V_7 -> V_14 ) ;
V_11 = F_7 ( V_7 -> V_17 ) ;
}
}
if ( ! V_11 ) {
int V_18 , V_19 ;
for ( V_18 = 0 ; V_18 < 2 ; V_18 ++ ) {
int V_20 = V_18 ? 256 : 384 ;
V_21 [ V_18 * 33 ] = F_9 ( V_7 -> V_14 ) / V_20 ;
for ( V_19 = 1 ; V_19 < 33 ; V_19 ++ )
V_21 [ V_18 * 33 + V_19 ] = F_9 ( V_7 -> V_17 ) /
( V_19 * V_20 ) ;
}
}
}
V_7 -> V_13 += 1 ;
F_10 ( & V_7 -> V_12 ) ;
if ( ! V_11 ) {
#ifdef F_11
V_11 = F_12 ( V_2 -> V_22 , 0 ,
V_23 ,
& V_24 ) ;
if ( V_11 < 0 )
F_6 ( V_4 -> V_15 , L_5 ,
V_16 ) ;
#endif
}
return V_11 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = F_2 ( V_4 -> V_8 ) ;
F_3 ( & V_7 -> V_12 ) ;
V_7 -> V_13 -= 1 ;
if ( V_7 -> V_13 == 0 ) {
F_8 ( V_7 -> V_14 ) ;
V_7 -> V_14 = NULL ;
F_8 ( V_7 -> V_17 ) ;
V_7 -> V_17 = NULL ;
}
F_10 ( & V_7 -> V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_9 * V_27 = V_4 -> V_27 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned int V_28 = 0 ;
int V_11 = 0 ;
int V_29 , V_30 ;
unsigned long V_31 = F_15 ( V_26 ) ;
long V_32 , V_33 ;
unsigned int div ;
int V_18 , V_34 ;
V_32 = 999999 ;
V_34 = 0 ;
for ( V_18 = 0 ; V_18 < 2 * 33 ; V_18 ++ ) {
V_33 = V_21 [ V_18 ] - V_31 ;
if ( V_33 < 0 )
V_33 = - V_33 ;
if ( V_33 < V_32 ) {
V_32 = V_33 ;
V_34 = V_18 ;
}
}
if ( V_34 / 33 == 1 )
V_30 = V_35 ;
else
V_30 = V_36 ;
if ( V_34 % 33 == 0 ) {
V_29 = V_37 ;
div = 1 ;
} else {
V_29 = V_38 ;
div = V_34 % 33 ;
}
F_16 ( V_4 -> V_15 , L_6 , V_16 , V_31 , V_34 ) ;
V_28 = ( V_30 == V_36 ? 384 : 256 ) * V_31 ;
F_16 ( V_4 -> V_15 , L_7 , V_16 ,
V_30 == V_36 ? L_8 : L_9 ,
V_29 == V_37 ? L_10 : L_11 ,
div , V_28 , V_32 ) ;
if ( ( V_32 * 100 / V_31 ) > 5 ) {
F_6 ( V_4 -> V_15 , L_12
L_13 , V_32 * 100 / V_31 ) ;
return - V_39 ;
}
V_11 = F_17 ( V_10 , V_29 , V_28 ,
V_40 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_18 ( V_10 , V_41 , V_30 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_18 ( V_10 , V_42 ,
V_43 ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_18 ( V_10 , V_44 ,
F_19 ( div , div ) ) ;
if ( V_11 < 0 )
return V_11 ;
V_11 = F_17 ( V_27 , 0 , V_28 ,
V_45 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_20 ( struct V_46 * V_47 )
{
struct V_48 * V_8 = & V_49 ;
struct V_6 * V_7 ;
int V_11 ;
V_7 = F_21 ( & V_47 -> V_15 , sizeof( * V_7 ) , V_50 ) ;
if ( ! V_7 )
return - V_51 ;
F_22 ( & V_7 -> V_12 ) ;
V_8 -> V_15 = & V_47 -> V_15 ;
F_23 ( V_47 , V_8 ) ;
F_24 ( V_8 , V_7 ) ;
V_11 = F_25 ( & V_47 -> V_15 , V_8 ) ;
if ( V_11 )
F_6 ( & V_47 -> V_15 , L_14 , V_11 ) ;
return V_11 ;
}
