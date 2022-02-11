static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 ++ ;
V_7 = F_4 ( V_4 , & V_4 -> V_10 , 0 , 0 ) ;
F_5 ( & V_4 -> V_8 ) ;
if ( V_7 < 0 )
F_6 ( V_4 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
return V_7 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_11 ++ ;
V_7 = F_4 ( V_4 , & V_4 -> V_12 , 0 , 0 ) ;
F_5 ( & V_4 -> V_8 ) ;
if ( V_7 < 0 )
F_6 ( V_4 ) ;
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_9 -- ;
F_9 ( V_4 , & V_4 -> V_10 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_8 ) ;
V_4 -> V_11 -- ;
F_9 ( V_4 , & V_4 -> V_12 ) ;
F_5 ( & V_4 -> V_8 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_13 , int V_14 )
{
struct V_3 * V_4 = V_13 -> V_5 -> V_6 ;
unsigned long V_15 ;
F_12 ( & V_4 -> V_16 , V_15 ) ;
if ( V_14 )
F_13 ( & V_4 -> V_10 ,
V_13 -> V_17 , V_13 ) ;
else
F_13 ( & V_4 -> V_10 ,
V_13 -> V_17 , NULL ) ;
F_14 ( & V_4 -> V_16 , V_15 ) ;
}
static void F_15 ( struct V_1 * V_13 , int V_14 )
{
struct V_3 * V_4 = V_13 -> V_5 -> V_6 ;
unsigned long V_15 ;
F_12 ( & V_4 -> V_16 , V_15 ) ;
if ( V_14 )
F_13 ( & V_4 -> V_12 ,
V_13 -> V_17 , V_13 ) ;
else
F_13 ( & V_4 -> V_12 ,
V_13 -> V_17 , NULL ) ;
F_14 ( & V_4 -> V_16 , V_15 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_1 * V_20 ;
F_17 (subs, &str->substreams, list) {
snprintf ( V_20 -> V_21 , sizeof( V_20 -> V_21 ) ,
L_1 ,
V_4 -> V_22 -> V_23 , V_20 -> V_17 + 1 ) ;
}
}
int F_18 ( struct V_3 * V_4 )
{
static const struct V_24 V_25 = {
. V_26 = F_1 ,
. V_27 = F_8 ,
. V_28 = F_11 ,
} ;
static const struct V_24 V_29 = {
. V_26 = F_7 ,
. V_27 = F_10 ,
. V_28 = F_15 ,
} ;
struct V_30 * V_5 ;
struct V_18 * V_19 ;
int V_7 ;
if ( V_4 -> V_31 == 0 && V_4 -> V_32 == 0 )
return 0 ;
V_7 = F_19 ( V_4 -> V_22 , V_4 -> V_22 -> V_33 , 0 ,
V_4 -> V_32 , V_4 -> V_31 ,
& V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 -> V_21 , sizeof( V_5 -> V_21 ) ,
L_2 , V_4 -> V_22 -> V_23 ) ;
V_5 -> V_6 = V_4 ;
if ( V_4 -> V_31 > 0 ) {
V_5 -> V_34 |= V_35 ;
F_20 ( V_5 , V_36 ,
& V_25 ) ;
V_19 = & V_5 -> V_37 [ V_36 ] ;
F_16 ( V_4 , V_19 ) ;
}
if ( V_4 -> V_32 > 0 ) {
V_5 -> V_34 |= V_38 ;
F_20 ( V_5 , V_39 ,
& V_29 ) ;
V_19 = & V_5 -> V_37 [ V_39 ] ;
F_16 ( V_4 , V_19 ) ;
}
if ( ( V_4 -> V_32 > 0 ) && ( V_4 -> V_31 > 0 ) )
V_5 -> V_34 |= V_40 ;
return 0 ;
}
