static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 (p, &br->port_list, list) {
if ( V_4 -> V_5 != V_6 &&
! memcmp ( & V_4 -> V_7 , & V_2 -> V_8 , 8 ) )
return 1 ;
}
return 0 ;
}
static void F_3 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_4 ( V_2 , L_1 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_11 -> V_12 & V_13 ) {
F_6 ( V_2 ) ;
F_7 ( & V_2 -> V_14 , F_8 ( V_15 + V_2 -> V_16 ) ) ;
}
F_9 ( & V_2 -> V_10 ) ;
}
static void F_10 ( unsigned long V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_9 ;
struct V_1 * V_2 = V_4 -> V_2 ;
const V_8 * V_17 = & V_4 -> V_7 ;
int V_18 ;
if ( V_4 -> V_5 == V_6 )
return;
F_11 ( V_2 , L_2 ,
( unsigned int ) V_4 -> V_19 , V_4 -> V_11 -> V_20 ,
V_17 -> V_21 [ 0 ] , V_17 -> V_21 [ 1 ] , & V_17 -> V_22 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_4 -> V_5 == V_6 )
goto V_23;
V_18 = F_12 ( V_2 ) ;
F_13 ( V_4 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( F_12 ( V_2 ) && ! V_18 )
F_16 ( V_2 ) ;
V_23:
F_9 ( & V_2 -> V_10 ) ;
}
static void F_17 ( unsigned long V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_9 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_2 , L_3 ,
( unsigned int ) V_4 -> V_19 , V_4 -> V_11 -> V_20 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_4 -> V_5 == V_24 ) {
V_4 -> V_5 = V_25 ;
F_7 ( & V_4 -> V_26 ,
V_15 + V_2 -> V_27 ) ;
} else if ( V_4 -> V_5 == V_25 ) {
V_4 -> V_5 = V_28 ;
if ( F_1 ( V_2 ) )
F_18 ( V_2 ) ;
F_19 ( V_2 -> V_11 ) ;
}
F_20 ( V_4 ) ;
F_21 ( V_29 , V_4 ) ;
F_9 ( & V_2 -> V_10 ) ;
}
static void F_22 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_4 ( V_2 , L_4 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_2 -> V_11 -> V_12 & V_13 ) {
F_23 ( V_2 ) ;
F_7 ( & V_2 -> V_30 , V_15 + V_2 -> V_31 ) ;
}
F_9 ( & V_2 -> V_10 ) ;
}
static void F_24 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_4 ( V_2 , L_5 ) ;
F_5 ( & V_2 -> V_10 ) ;
V_2 -> V_32 = 0 ;
V_2 -> V_33 = 0 ;
F_9 ( & V_2 -> V_10 ) ;
}
static void F_25 ( unsigned long V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_9 ;
F_4 ( V_4 -> V_2 , L_6 ,
( unsigned int ) V_4 -> V_19 , V_4 -> V_11 -> V_20 ) ;
F_5 ( & V_4 -> V_2 -> V_10 ) ;
if ( V_4 -> V_34 )
F_26 ( V_4 ) ;
F_9 ( & V_4 -> V_2 -> V_10 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_14 , F_3 ,
( unsigned long ) V_2 ) ;
F_28 ( & V_2 -> V_30 , F_22 ,
( unsigned long ) V_2 ) ;
F_28 ( & V_2 -> V_35 ,
F_24 ,
( unsigned long ) V_2 ) ;
F_28 ( & V_2 -> V_36 , V_37 , ( unsigned long ) V_2 ) ;
}
void F_29 ( struct V_3 * V_4 )
{
F_28 ( & V_4 -> V_38 , F_10 ,
( unsigned long ) V_4 ) ;
F_28 ( & V_4 -> V_26 , F_17 ,
( unsigned long ) V_4 ) ;
F_28 ( & V_4 -> V_39 , F_25 ,
( unsigned long ) V_4 ) ;
}
unsigned long F_30 ( const struct V_40 * V_41 )
{
return F_31 ( V_41 )
? F_32 ( V_41 -> V_42 - V_15 ) : 0 ;
}
