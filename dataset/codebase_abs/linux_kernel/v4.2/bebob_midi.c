static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
goto V_8;
F_3 ( & V_4 -> V_9 ) ;
V_7 = F_4 ( V_4 , 0 ) ;
if ( V_7 < 0 )
F_5 ( V_4 ) ;
V_8:
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
goto V_8;
F_3 ( & V_4 -> V_9 ) ;
V_7 = F_4 ( V_4 , 0 ) ;
if ( V_7 < 0 )
F_5 ( V_4 ) ;
V_8:
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_4 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_8 ( & V_4 -> V_9 ) ;
F_9 ( V_4 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_10 , int V_11 )
{
struct V_3 * V_4 = V_10 -> V_5 -> V_6 ;
unsigned long V_12 ;
F_12 ( & V_4 -> V_13 , V_12 ) ;
if ( V_11 )
F_13 ( & V_4 -> V_14 ,
V_10 -> V_15 , V_10 ) ;
else
F_13 ( & V_4 -> V_14 ,
V_10 -> V_15 , NULL ) ;
F_14 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_15 ( struct V_1 * V_10 , int V_11 )
{
struct V_3 * V_4 = V_10 -> V_5 -> V_6 ;
unsigned long V_12 ;
F_12 ( & V_4 -> V_13 , V_12 ) ;
if ( V_11 )
F_13 ( & V_4 -> V_16 ,
V_10 -> V_15 , V_10 ) ;
else
F_13 ( & V_4 -> V_16 ,
V_10 -> V_15 , NULL ) ;
F_14 ( & V_4 -> V_13 , V_12 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
struct V_17 * V_18 )
{
struct V_1 * V_19 ;
F_17 (subs, &str->substreams, list) {
snprintf ( V_19 -> V_20 , sizeof( V_19 -> V_20 ) ,
L_1 ,
V_4 -> V_21 -> V_22 , V_19 -> V_15 + 1 ) ;
}
}
int F_18 ( struct V_3 * V_4 )
{
struct V_23 * V_5 ;
struct V_17 * V_18 ;
int V_7 ;
V_7 = F_19 ( V_4 -> V_21 , V_4 -> V_21 -> V_24 , 0 ,
V_4 -> V_25 , V_4 -> V_26 ,
& V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 -> V_20 , sizeof( V_5 -> V_20 ) ,
L_2 , V_4 -> V_21 -> V_22 ) ;
V_5 -> V_6 = V_4 ;
if ( V_4 -> V_26 > 0 ) {
V_5 -> V_27 |= V_28 ;
F_20 ( V_5 , V_29 ,
& V_30 ) ;
V_18 = & V_5 -> V_31 [ V_29 ] ;
F_16 ( V_4 , V_18 ) ;
}
if ( V_4 -> V_25 > 0 ) {
V_5 -> V_27 |= V_32 ;
F_20 ( V_5 , V_33 ,
& V_34 ) ;
V_18 = & V_5 -> V_31 [ V_33 ] ;
F_16 ( V_4 , V_18 ) ;
}
if ( ( V_4 -> V_25 > 0 ) && ( V_4 -> V_26 > 0 ) )
V_5 -> V_27 |= V_35 ;
return 0 ;
}
