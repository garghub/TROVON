struct V_1 * F_1 ( struct V_2 * V_2 ,
const struct V_3 * V_4 ,
int * V_5 )
{
static struct V_1 V_6 = { . V_7 = 1 , } ;
* V_5 = sizeof( V_6 ) ;
return & V_6 ;
}
static int F_2 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
V_11 -> V_12 = F_4 ( V_11 -> V_13 , V_11 -> V_14 ) ;
return F_5 ( V_11 -> V_12 ) ? F_6 ( V_11 -> V_12 ) : 0 ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_3 ( V_9 ) ;
F_8 ( V_11 -> V_12 ) ;
V_11 -> V_12 = NULL ;
}
void F_9 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
struct V_15 * V_13 = & V_2 -> V_13 ;
V_11 -> V_14 = F_10 ( V_13 -> V_16 -> V_17 , L_1 ) ;
if ( ! V_11 -> V_14 )
return;
V_11 -> V_13 = V_13 ;
F_11 ( V_2 , & V_11 -> V_9 , F_2 , F_7 ) ;
}
void F_12 ( struct V_2 * V_2 , struct V_10 * V_11 )
{
F_13 ( V_2 , & V_11 -> V_9 ) ;
F_14 ( V_11 -> V_14 ) ;
}
static int F_15 ( struct V_8 * V_9 )
{
struct V_18 * V_19 = F_16 ( V_9 ) ;
V_19 -> V_12 = F_17 ( V_19 -> V_13 , V_19 -> V_14 ) ;
return F_18 ( V_19 -> V_12 ) ;
}
static void F_19 ( struct V_8 * V_9 )
{
struct V_18 * V_19 = F_16 ( V_9 ) ;
F_20 ( V_19 -> V_12 ) ;
V_19 -> V_12 = NULL ;
}
void F_21 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
struct V_15 * V_13 = & V_2 -> V_13 ;
V_19 -> V_14 = F_10 ( V_13 -> V_16 -> V_17 , L_2 ) ;
if ( ! V_19 -> V_14 )
return;
V_19 -> V_13 = V_13 ;
F_11 ( V_2 , & V_19 -> V_9 , F_15 , F_19 ) ;
}
void F_22 ( struct V_2 * V_2 , struct V_18 * V_19 )
{
F_13 ( V_2 , & V_19 -> V_9 ) ;
F_14 ( V_19 -> V_14 ) ;
}
int F_23 ( struct V_20 * V_21 )
{
return F_24 ( & V_22 , V_21 ) ;
}
void F_25 ( struct V_20 * V_21 )
{
F_26 ( & V_22 , V_21 ) ;
}
static int F_27 ( struct V_8 * V_9 )
{
return 0 ;
}
static void F_28 ( struct V_8 * V_9 )
{
struct V_23 * V_24 = F_29 ( V_9 ) ;
F_30 ( & V_22 , 0 , ( void * ) V_24 -> V_25 ) ;
}
void F_31 ( struct V_2 * V_2 , struct V_23 * V_24 ,
const char * V_26 )
{
V_24 -> V_25 = V_26 ;
F_11 ( V_2 , & V_24 -> V_9 , F_27 , F_28 ) ;
}
void F_32 ( struct V_2 * V_2 , struct V_23 * V_24 )
{
F_13 ( V_2 , & V_24 -> V_9 ) ;
}
