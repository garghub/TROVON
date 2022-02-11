static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = (struct V_3 * ) V_2 ;
F_2 ( & V_4 -> V_5 ) ;
F_3 ( V_4 -> V_1 ) ;
return V_6 ;
}
static int F_4 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 = F_6 ( V_12 ) | V_13 |
V_14 | V_15 ;
F_7 ( V_10 , V_12 , V_11 ) ;
while ( ! ( F_8 ( V_10 , V_16 ) & V_17 ) ) {
F_9 ( V_4 -> V_1 ) ;
F_10 ( V_4 -> V_5 ,
F_8 ( V_10 , V_16 ) & V_17 ) ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
return ! ! ( F_8 ( V_10 , V_16 ) & V_17 ) ;
}
static void F_12 ( struct V_7 * V_8 )
{
struct V_3 * V_4 = F_5 ( V_8 ) ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_11 = F_6 ( V_12 ) & ~ V_13 ;
F_7 ( V_10 , V_12 , V_11 ) ;
}
static unsigned long F_13 ( struct V_7 * V_8 ,
unsigned long V_18 )
{
return V_18 * V_19 ;
}
static struct V_20 * T_3
F_14 ( struct V_9 * V_10 , unsigned int V_1 ,
const char * V_21 , const char * V_22 )
{
int V_23 ;
struct V_3 * V_4 ;
struct V_20 * V_20 = NULL ;
struct V_24 V_25 ;
V_4 = F_15 ( sizeof( * V_4 ) , V_26 ) ;
if ( ! V_4 )
return F_16 ( - V_27 ) ;
V_25 . V_21 = V_21 ;
V_25 . V_28 = & V_29 ;
V_25 . V_30 = V_22 ? & V_22 : NULL ;
V_25 . V_31 = V_22 ? 1 : 0 ;
V_25 . V_32 = V_33 ;
V_4 -> V_8 . V_25 = & V_25 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_1 = V_1 ;
F_17 ( & V_4 -> V_5 ) ;
F_18 ( V_4 -> V_1 , V_34 ) ;
V_23 = F_19 ( V_4 -> V_1 , F_1 ,
V_35 , L_1 , V_4 ) ;
if ( V_23 ) {
F_20 ( V_4 ) ;
return F_16 ( V_23 ) ;
}
V_20 = F_21 ( NULL , & V_4 -> V_8 ) ;
if ( F_22 ( V_20 ) ) {
F_23 ( V_4 -> V_1 , V_4 ) ;
F_20 ( V_4 ) ;
}
return V_20 ;
}
static void T_3
F_24 ( struct V_36 * V_37 , struct V_9 * V_10 )
{
unsigned int V_1 ;
struct V_20 * V_20 ;
const char * V_22 ;
const char * V_21 = V_37 -> V_21 ;
V_22 = F_25 ( V_37 , 0 ) ;
F_26 ( V_37 , L_2 , & V_21 ) ;
V_1 = F_27 ( V_37 , 0 ) ;
if ( ! V_1 )
return;
V_20 = F_14 ( V_10 , V_1 , V_21 , V_22 ) ;
if ( F_22 ( V_20 ) )
return;
F_28 ( V_37 , V_38 , V_20 ) ;
return;
}
void T_3 F_29 ( struct V_36 * V_37 ,
struct V_9 * V_10 )
{
F_24 ( V_37 , V_10 ) ;
}
