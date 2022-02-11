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
static const struct V_23 V_24 = {
. V_25 = F_1 ,
. V_26 = F_7 ,
. V_27 = F_9 ,
} ;
static const struct V_23 V_28 = {
. V_25 = F_1 ,
. V_26 = F_7 ,
. V_27 = F_13 ,
} ;
T_1 V_29 ;
struct V_30 * V_5 ;
struct V_17 * V_18 ;
unsigned int V_31 , V_32 ;
int V_7 ;
V_7 = F_17 ( V_4 , V_33 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_31 = F_18 ( V_29 ) ;
V_7 = F_19 ( V_4 , V_34 ,
& V_29 , sizeof( V_29 ) ) ;
if ( V_7 < 0 )
return V_7 ;
V_32 = F_18 ( V_29 ) ;
if ( V_31 + V_32 == 0 )
return 0 ;
V_7 = F_20 ( V_4 -> V_21 , V_4 -> V_21 -> V_35 , 0 ,
V_32 , V_31 ,
& V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 -> V_20 , sizeof( V_5 -> V_20 ) ,
L_2 , V_4 -> V_21 -> V_22 ) ;
V_5 -> V_6 = V_4 ;
if ( V_31 > 0 ) {
V_5 -> V_36 |= V_37 ;
F_21 ( V_5 , V_38 ,
& V_24 ) ;
V_18 = & V_5 -> V_39 [ V_38 ] ;
F_14 ( V_4 , V_18 ) ;
}
if ( V_32 > 0 ) {
V_5 -> V_36 |= V_40 ;
F_21 ( V_5 , V_41 ,
& V_28 ) ;
V_18 = & V_5 -> V_39 [ V_41 ] ;
F_14 ( V_4 , V_18 ) ;
}
if ( ( V_32 > 0 ) && ( V_31 > 0 ) )
V_5 -> V_36 |= V_42 ;
return 0 ;
}
