static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 ++ ;
V_7 = F_4 ( V_4 , 0 ) ;
F_5 ( & V_4 -> V_8 ) ;
if ( V_7 < 0 )
F_6 ( V_4 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 -- ;
F_8 ( V_4 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_10 , int V_11 )
{
struct V_3 * V_4 = V_10 -> V_5 -> V_6 ;
unsigned long V_12 ;
F_10 ( & V_4 -> V_13 , V_12 ) ;
if ( V_11 )
F_11 ( & V_4 -> V_14 [ 0 ] ,
V_10 -> V_15 , V_10 ) ;
else
F_11 ( & V_4 -> V_14 [ 0 ] ,
V_10 -> V_15 , NULL ) ;
F_12 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_13 ( struct V_1 * V_10 , int V_11 )
{
struct V_3 * V_4 = V_10 -> V_5 -> V_6 ;
unsigned long V_12 ;
F_10 ( & V_4 -> V_13 , V_12 ) ;
if ( V_11 )
F_11 ( & V_4 -> V_16 [ 0 ] ,
V_10 -> V_15 , V_10 ) ;
else
F_11 ( & V_4 -> V_16 [ 0 ] ,
V_10 -> V_15 , NULL ) ;
F_12 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_14 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
struct V_1 * V_19 ;
F_15 (subs, &str->substreams, list) {
snprintf ( V_19 -> V_20 , sizeof( V_19 -> V_20 ) ,
L_1 , V_4 -> V_21 -> V_22 , V_19 -> V_15 + 1 ) ;
}
}
int F_16 ( struct V_3 * V_4 )
{
T_1 V_23 ;
struct V_24 * V_5 ;
struct V_17 * V_18 ;
unsigned int V_25 , V_26 ;
int V_7 ;
V_7 = F_17 ( V_4 , V_27 ,
& V_23 , sizeof( V_23 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_25 = F_18 ( V_23 ) ;
V_7 = F_19 ( V_4 , V_28 ,
& V_23 , sizeof( V_23 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_26 = F_18 ( V_23 ) ;
if ( V_25 + V_26 == 0 )
return 0 ;
V_7 = F_20 ( V_4 -> V_21 , V_4 -> V_21 -> V_29 , 0 ,
V_26 , V_25 ,
& V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 -> V_20 , sizeof( V_5 -> V_20 ) ,
L_2 , V_4 -> V_21 -> V_22 ) ;
V_5 -> V_6 = V_4 ;
if ( V_25 > 0 ) {
V_5 -> V_30 |= V_31 ;
F_21 ( V_5 , V_32 ,
& V_33 ) ;
V_18 = & V_5 -> V_34 [ V_32 ] ;
F_14 ( V_4 , V_18 ) ;
}
if ( V_26 > 0 ) {
V_5 -> V_30 |= V_35 ;
F_21 ( V_5 , V_36 ,
& V_37 ) ;
V_18 = & V_5 -> V_34 [ V_36 ] ;
F_14 ( V_4 , V_18 ) ;
}
if ( ( V_26 > 0 ) && ( V_25 > 0 ) )
V_5 -> V_30 |= V_38 ;
return 0 ;
}
