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
F_3 ( & V_4 -> V_10 ) ;
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
F_8 ( & V_4 -> V_10 ) ;
F_9 ( V_4 ) ;
F_5 ( V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_11 , int V_12 )
{
struct V_3 * V_4 = V_11 -> V_5 -> V_6 ;
unsigned long V_13 ;
F_12 ( & V_4 -> V_14 , V_13 ) ;
if ( V_12 )
F_13 ( & V_4 -> V_15 ,
V_11 -> V_16 , V_11 ) ;
else
F_13 ( & V_4 -> V_15 ,
V_11 -> V_16 , NULL ) ;
F_14 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_15 ( struct V_1 * V_11 , int V_12 )
{
struct V_3 * V_4 = V_11 -> V_5 -> V_6 ;
unsigned long V_13 ;
F_12 ( & V_4 -> V_14 , V_13 ) ;
if ( V_12 )
F_13 ( & V_4 -> V_17 ,
V_11 -> V_16 , V_11 ) ;
else
F_13 ( & V_4 -> V_17 ,
V_11 -> V_16 , NULL ) ;
F_14 ( & V_4 -> V_14 , V_13 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
struct V_18 * V_19 )
{
struct V_1 * V_20 ;
F_17 (subs, &str->substreams, list) {
snprintf ( V_20 -> V_21 , sizeof( V_20 -> V_21 ) ,
L_1 , V_4 -> V_22 -> V_23 , V_20 -> V_16 + 1 ) ;
}
}
int F_18 ( struct V_3 * V_4 )
{
struct V_24 * V_5 ;
struct V_18 * V_19 ;
int V_7 ;
V_7 = F_19 ( V_4 -> V_22 , V_4 -> V_22 -> V_25 , 0 ,
V_4 -> V_26 , V_4 -> V_27 ,
& V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 -> V_21 , sizeof( V_5 -> V_21 ) ,
L_2 , V_4 -> V_22 -> V_23 ) ;
V_5 -> V_6 = V_4 ;
if ( V_4 -> V_27 > 0 ) {
V_5 -> V_28 |= V_29 ;
F_20 ( V_5 , V_30 ,
& V_31 ) ;
V_19 = & V_5 -> V_32 [ V_30 ] ;
F_16 ( V_4 , V_19 ) ;
}
if ( V_4 -> V_26 > 0 ) {
V_5 -> V_28 |= V_33 ;
F_20 ( V_5 , V_34 ,
& V_35 ) ;
V_19 = & V_5 -> V_32 [ V_34 ] ;
F_16 ( V_4 , V_19 ) ;
}
if ( ( V_4 -> V_26 > 0 ) && ( V_4 -> V_27 > 0 ) )
V_5 -> V_28 |= V_36 ;
return 0 ;
}
