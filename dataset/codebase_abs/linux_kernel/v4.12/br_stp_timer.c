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
if ( V_2 -> V_14 == V_15 )
F_7 ( & V_2 -> V_16 ,
F_8 ( V_17 + V_2 -> V_18 ) ) ;
}
F_9 ( & V_2 -> V_10 ) ;
}
static void F_10 ( unsigned long V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_9 ;
struct V_1 * V_2 = V_4 -> V_2 ;
const V_8 * V_19 = & V_4 -> V_7 ;
int V_20 ;
if ( V_4 -> V_5 == V_6 )
return;
F_11 ( V_2 , L_2 ,
( unsigned int ) V_4 -> V_21 , V_4 -> V_11 -> V_22 ,
V_19 -> V_23 [ 0 ] , V_19 -> V_23 [ 1 ] , & V_19 -> V_24 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_4 -> V_5 == V_6 )
goto V_25;
V_20 = F_12 ( V_2 ) ;
F_13 ( V_4 ) ;
F_14 ( V_2 ) ;
F_15 ( V_2 ) ;
if ( F_12 ( V_2 ) && ! V_20 )
F_16 ( V_2 ) ;
V_25:
F_9 ( & V_2 -> V_10 ) ;
}
static void F_17 ( unsigned long V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_9 ;
struct V_1 * V_2 = V_4 -> V_2 ;
F_4 ( V_2 , L_3 ,
( unsigned int ) V_4 -> V_21 , V_4 -> V_11 -> V_22 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( V_4 -> V_5 == V_26 ) {
F_18 ( V_4 , V_27 ) ;
F_7 ( & V_4 -> V_28 ,
V_17 + V_2 -> V_29 ) ;
} else if ( V_4 -> V_5 == V_27 ) {
F_18 ( V_4 , V_30 ) ;
if ( F_1 ( V_2 ) )
F_19 ( V_2 ) ;
F_20 ( V_2 -> V_11 ) ;
}
F_21 () ;
F_22 ( V_31 , V_4 ) ;
F_23 () ;
F_9 ( & V_2 -> V_10 ) ;
}
static void F_24 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_4 ( V_2 , L_4 ) ;
F_5 ( & V_2 -> V_10 ) ;
if ( ! F_12 ( V_2 ) && ( V_2 -> V_11 -> V_12 & V_13 ) ) {
F_25 ( V_2 ) ;
F_7 ( & V_2 -> V_32 , V_17 + V_2 -> V_33 ) ;
}
F_9 ( & V_2 -> V_10 ) ;
}
static void F_26 ( unsigned long V_9 )
{
struct V_1 * V_2 = (struct V_1 * ) V_9 ;
F_4 ( V_2 , L_5 ) ;
F_5 ( & V_2 -> V_10 ) ;
V_2 -> V_34 = 0 ;
F_27 ( V_2 , 0 ) ;
F_9 ( & V_2 -> V_10 ) ;
}
static void F_28 ( unsigned long V_9 )
{
struct V_3 * V_4 = (struct V_3 * ) V_9 ;
F_4 ( V_4 -> V_2 , L_6 ,
( unsigned int ) V_4 -> V_21 , V_4 -> V_11 -> V_22 ) ;
F_5 ( & V_4 -> V_2 -> V_10 ) ;
if ( V_4 -> V_35 )
F_29 ( V_4 ) ;
F_9 ( & V_4 -> V_2 -> V_10 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
F_31 ( & V_2 -> V_16 , F_3 ,
( unsigned long ) V_2 ) ;
F_31 ( & V_2 -> V_32 , F_24 ,
( unsigned long ) V_2 ) ;
F_31 ( & V_2 -> V_36 ,
F_26 ,
( unsigned long ) V_2 ) ;
}
void F_32 ( struct V_3 * V_4 )
{
F_31 ( & V_4 -> V_37 , F_10 ,
( unsigned long ) V_4 ) ;
F_31 ( & V_4 -> V_28 , F_17 ,
( unsigned long ) V_4 ) ;
F_31 ( & V_4 -> V_38 , F_28 ,
( unsigned long ) V_4 ) ;
}
unsigned long F_33 ( const struct V_39 * V_40 )
{
return F_34 ( V_40 )
? F_35 ( V_40 -> V_41 - V_17 ) : 0 ;
}
