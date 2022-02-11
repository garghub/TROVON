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
unsigned long V_22 )
{
struct V_15 * V_16 = F_8 ( V_2 ) ;
const struct V_17 * V_18 ;
struct V_3 * V_4 ;
int V_23 ;
int V_24 ;
int V_25 ;
V_18 = F_5 ( V_2 , V_16 ) ;
if ( ! V_18 )
return - V_26 ;
V_2 -> V_27 = V_18 ;
V_2 -> V_28 = V_18 -> V_29 ;
V_25 = F_9 ( V_16 , V_2 -> V_28 ) ;
if ( V_25 )
return V_25 ;
V_2 -> V_13 = F_10 ( V_16 , 2 ) ;
V_25 = F_11 ( V_2 , V_18 -> V_30 ) ;
if ( V_25 )
return V_25 ;
V_23 = 0 ;
if ( V_18 -> V_31 ) {
V_24 = F_12 ( V_18 -> V_31 , 32 ) ;
V_4 = & V_2 -> V_32 [ V_23 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 = V_24 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = F_3 ;
V_4 -> V_39 = & V_40 ;
V_4 -> V_9 = ( void * ) V_41 ;
V_23 ++ ;
V_24 = V_18 -> V_31 - V_24 ;
if ( V_24 ) {
V_4 = & V_2 -> V_32 [ V_23 ] ;
V_4 -> type = V_33 ;
V_4 -> V_34 = V_35 ;
V_4 -> V_36 = V_24 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = F_3 ;
V_4 -> V_39 = & V_40 ;
V_4 -> V_9 = ( void * ) V_42 ;
V_23 ++ ;
}
}
if ( V_18 -> V_43 ) {
V_24 = F_12 ( V_18 -> V_43 , 32 ) ;
V_4 = & V_2 -> V_32 [ V_23 ] ;
V_4 -> type = V_44 ;
V_4 -> V_34 = V_45 ;
V_4 -> V_36 = V_24 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = F_1 ;
V_4 -> V_39 = & V_40 ;
V_4 -> V_9 = ( void * ) V_41 ;
V_23 ++ ;
V_24 = V_18 -> V_43 - V_24 ;
if ( V_24 ) {
V_4 = & V_2 -> V_32 [ V_23 ] ;
V_4 -> type = V_44 ;
V_4 -> V_34 = V_45 ;
V_4 -> V_36 = V_24 ;
V_4 -> V_37 = 1 ;
V_4 -> V_38 = F_1 ;
V_4 -> V_39 = & V_40 ;
V_4 -> V_9 = ( void * ) V_42 ;
V_23 ++ ;
}
}
F_13 ( V_2 -> V_46 , L_1 ,
V_2 -> V_28 , V_18 -> V_31 , V_18 -> V_43 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_8 ( V_2 ) ;
if ( V_16 ) {
if ( V_2 -> V_13 )
F_15 ( V_16 ) ;
}
}
static int F_16 ( struct V_15 * V_2 ,
const struct V_47 * V_48 )
{
return F_17 ( V_2 , & V_49 ) ;
}
