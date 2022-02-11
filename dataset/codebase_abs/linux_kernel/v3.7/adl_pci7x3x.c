static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
unsigned int V_10 = V_7 [ 0 ] ;
unsigned int V_11 = V_7 [ 1 ] ;
if ( V_10 ) {
V_4 -> V_12 &= ~ V_10 ;
V_4 -> V_12 |= ( V_11 & V_10 ) ;
F_2 ( V_4 -> V_12 , V_2 -> V_13 + V_8 ) ;
}
V_7 [ 1 ] = V_4 -> V_12 ;
return V_6 -> V_14 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 ,
unsigned int * V_7 )
{
unsigned long V_8 = ( unsigned long ) V_4 -> V_9 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_13 + V_8 ) ;
return V_6 -> V_14 ;
}
static const void * F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_6 ( V_20 ) ; V_19 ++ ) {
V_18 = & V_20 [ V_19 ] ;
if ( V_16 -> V_21 == V_18 -> V_21 )
return V_18 ;
}
return NULL ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_22 ;
int V_23 ;
int V_24 ;
F_8 ( V_2 , & V_16 -> V_2 ) ;
V_18 = F_5 ( V_2 , V_16 ) ;
if ( ! V_18 )
return - V_25 ;
V_2 -> V_26 = V_18 ;
V_2 -> V_27 = V_18 -> V_28 ;
V_24 = F_9 ( V_16 , V_2 -> V_27 ) ;
if ( V_24 )
return V_24 ;
V_2 -> V_13 = F_10 ( V_16 , 2 ) ;
V_24 = F_11 ( V_2 , V_18 -> V_29 ) ;
if ( V_24 )
return V_24 ;
V_22 = 0 ;
if ( V_18 -> V_30 ) {
V_23 = F_12 ( V_18 -> V_30 , 32 ) ;
V_4 = & V_2 -> V_31 [ V_22 ] ;
V_4 -> type = V_32 ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 = V_23 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = F_3 ;
V_4 -> V_38 = & V_39 ;
V_4 -> V_9 = ( void * ) V_40 ;
V_22 ++ ;
V_23 = V_18 -> V_30 - V_23 ;
if ( V_23 ) {
V_4 = & V_2 -> V_31 [ V_22 ] ;
V_4 -> type = V_32 ;
V_4 -> V_33 = V_34 ;
V_4 -> V_35 = V_23 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = F_3 ;
V_4 -> V_38 = & V_39 ;
V_4 -> V_9 = ( void * ) V_41 ;
V_22 ++ ;
}
}
if ( V_18 -> V_42 ) {
V_23 = F_12 ( V_18 -> V_42 , 32 ) ;
V_4 = & V_2 -> V_31 [ V_22 ] ;
V_4 -> type = V_43 ;
V_4 -> V_33 = V_44 ;
V_4 -> V_35 = V_23 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = F_1 ;
V_4 -> V_38 = & V_39 ;
V_4 -> V_9 = ( void * ) V_40 ;
V_22 ++ ;
V_23 = V_18 -> V_42 - V_23 ;
if ( V_23 ) {
V_4 = & V_2 -> V_31 [ V_22 ] ;
V_4 -> type = V_43 ;
V_4 -> V_33 = V_44 ;
V_4 -> V_35 = V_23 ;
V_4 -> V_36 = 1 ;
V_4 -> V_37 = F_1 ;
V_4 -> V_38 = & V_39 ;
V_4 -> V_9 = ( void * ) V_41 ;
V_22 ++ ;
}
}
F_13 ( V_2 -> V_45 , L_1 ,
V_2 -> V_27 , V_18 -> V_30 , V_18 -> V_42 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_15 ( V_2 ) ;
if ( V_16 ) {
if ( V_2 -> V_13 )
F_16 ( V_16 ) ;
}
}
static int T_1 F_17 ( struct V_15 * V_2 ,
const struct V_46 * V_47 )
{
return F_18 ( V_2 , & V_48 ) ;
}
static void T_2 F_19 ( struct V_15 * V_2 )
{
F_20 ( V_2 ) ;
}
