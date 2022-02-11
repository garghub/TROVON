static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
goto V_8;
F_3 ( & V_4 -> V_9 ) ;
V_4 -> V_10 ++ ;
V_7 = F_4 ( V_4 , 0 ) ;
F_5 ( & V_4 -> V_9 ) ;
if ( V_7 < 0 )
F_6 ( V_4 ) ;
V_8:
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
int V_7 ;
V_7 = F_2 ( V_4 ) ;
if ( V_7 < 0 )
goto V_8;
F_3 ( & V_4 -> V_9 ) ;
V_4 -> V_11 ++ ;
V_7 = F_4 ( V_4 , 0 ) ;
F_5 ( & V_4 -> V_9 ) ;
if ( V_7 < 0 )
F_6 ( V_4 ) ;
V_8:
return V_7 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_9 ) ;
V_4 -> V_10 -- ;
F_9 ( V_4 ) ;
F_5 ( & V_4 -> V_9 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
F_3 ( & V_4 -> V_9 ) ;
V_4 -> V_11 -- ;
F_9 ( V_4 ) ;
F_5 ( & V_4 -> V_9 ) ;
F_6 ( V_4 ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_12 , int V_13 )
{
struct V_3 * V_4 = V_12 -> V_5 -> V_6 ;
unsigned long V_14 ;
F_12 ( & V_4 -> V_15 , V_14 ) ;
if ( V_13 )
F_13 ( & V_4 -> V_16 ,
V_12 -> V_17 , V_12 ) ;
else
F_13 ( & V_4 -> V_16 ,
V_12 -> V_17 , NULL ) ;
F_14 ( & V_4 -> V_15 , V_14 ) ;
}
static void F_15 ( struct V_1 * V_12 , int V_13 )
{
struct V_3 * V_4 = V_12 -> V_5 -> V_6 ;
unsigned long V_14 ;
F_12 ( & V_4 -> V_15 , V_14 ) ;
if ( V_13 )
F_13 ( & V_4 -> V_18 ,
V_12 -> V_17 , V_12 ) ;
else
F_13 ( & V_4 -> V_18 ,
V_12 -> V_17 , NULL ) ;
F_14 ( & V_4 -> V_15 , V_14 ) ;
}
static void F_16 ( struct V_3 * V_4 ,
struct V_19 * V_20 )
{
struct V_1 * V_21 ;
F_17 (subs, &str->substreams, list) {
snprintf ( V_21 -> V_22 , sizeof( V_21 -> V_22 ) ,
L_1 , V_4 -> V_23 -> V_24 , V_21 -> V_17 + 1 ) ;
}
}
int F_18 ( struct V_3 * V_4 )
{
struct V_25 * V_5 ;
struct V_19 * V_20 ;
int V_7 ;
V_7 = F_19 ( V_4 -> V_23 , V_4 -> V_23 -> V_26 , 0 ,
V_4 -> V_27 , V_4 -> V_28 ,
& V_5 ) ;
if ( V_7 < 0 )
return V_7 ;
snprintf ( V_5 -> V_22 , sizeof( V_5 -> V_22 ) ,
L_2 , V_4 -> V_23 -> V_24 ) ;
V_5 -> V_6 = V_4 ;
if ( V_4 -> V_28 > 0 ) {
V_5 -> V_29 |= V_30 ;
F_20 ( V_5 , V_31 ,
& V_32 ) ;
V_20 = & V_5 -> V_33 [ V_31 ] ;
F_16 ( V_4 , V_20 ) ;
}
if ( V_4 -> V_27 > 0 ) {
V_5 -> V_29 |= V_34 ;
F_20 ( V_5 , V_35 ,
& V_36 ) ;
V_20 = & V_5 -> V_33 [ V_35 ] ;
F_16 ( V_4 , V_20 ) ;
}
if ( ( V_4 -> V_27 > 0 ) && ( V_4 -> V_28 > 0 ) )
V_5 -> V_29 |= V_37 ;
return 0 ;
}
