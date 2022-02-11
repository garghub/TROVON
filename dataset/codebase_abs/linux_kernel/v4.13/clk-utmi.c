static inline bool F_1 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
F_2 ( V_1 , V_3 , & V_2 ) ;
return V_2 & V_4 ;
}
static int F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
unsigned int V_9 = V_10 | V_11 |
V_12 ;
F_5 ( V_8 -> V_1 , V_13 , V_9 , V_9 ) ;
while ( ! F_1 ( V_8 -> V_1 ) )
F_6 () ;
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
return F_1 ( V_8 -> V_1 ) ;
}
static void F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = F_4 ( V_6 ) ;
F_5 ( V_8 -> V_1 , V_13 , V_10 , 0 ) ;
}
static unsigned long F_9 ( struct V_5 * V_6 ,
unsigned long V_14 )
{
return V_14 * V_15 ;
}
static struct V_5 * T_1
F_10 ( struct V_1 * V_1 ,
const char * V_16 , const char * V_17 )
{
struct V_7 * V_8 ;
struct V_5 * V_6 ;
struct V_18 V_19 ;
int V_20 ;
V_8 = F_11 ( sizeof( * V_8 ) , V_21 ) ;
if ( ! V_8 )
return F_12 ( - V_22 ) ;
V_19 . V_16 = V_16 ;
V_19 . V_23 = & V_24 ;
V_19 . V_25 = V_17 ? & V_17 : NULL ;
V_19 . V_26 = V_17 ? 1 : 0 ;
V_19 . V_27 = V_28 ;
V_8 -> V_6 . V_19 = & V_19 ;
V_8 -> V_1 = V_1 ;
V_6 = & V_8 -> V_6 ;
V_20 = F_13 ( NULL , & V_8 -> V_6 ) ;
if ( V_20 ) {
F_14 ( V_8 ) ;
V_6 = F_12 ( V_20 ) ;
}
return V_6 ;
}
static void T_1 F_15 ( struct V_29 * V_30 )
{
struct V_5 * V_6 ;
const char * V_17 ;
const char * V_16 = V_30 -> V_16 ;
struct V_1 * V_1 ;
V_17 = F_16 ( V_30 , 0 ) ;
F_17 ( V_30 , L_1 , & V_16 ) ;
V_1 = F_18 ( F_19 ( V_30 ) ) ;
if ( F_20 ( V_1 ) )
return;
V_6 = F_10 ( V_1 , V_16 , V_17 ) ;
if ( F_20 ( V_6 ) )
return;
F_21 ( V_30 , V_31 , V_6 ) ;
return;
}
