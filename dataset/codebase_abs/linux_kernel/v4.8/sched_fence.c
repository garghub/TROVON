struct V_1 * F_1 ( struct V_2 * V_3 ,
void * V_4 )
{
struct V_1 * V_5 = NULL ;
unsigned V_6 ;
V_5 = F_2 ( V_7 , V_8 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_4 = V_4 ;
V_5 -> V_9 = V_3 -> V_9 ;
F_3 ( & V_5 -> V_10 ) ;
V_6 = F_4 ( & V_3 -> V_11 ) ;
F_5 ( & V_5 -> V_12 , & V_13 ,
& V_5 -> V_10 , V_3 -> V_14 , V_6 ) ;
F_5 ( & V_5 -> V_15 , & V_16 ,
& V_5 -> V_10 , V_3 -> V_14 + 1 , V_6 ) ;
return V_5 ;
}
void F_6 ( struct V_1 * V_5 )
{
int V_17 = F_7 ( & V_5 -> V_12 ) ;
if ( ! V_17 )
F_8 ( & V_5 -> V_12 , L_1 ) ;
else
F_8 ( & V_5 -> V_12 , L_2 ) ;
}
void F_9 ( struct V_1 * V_5 )
{
int V_17 = F_7 ( & V_5 -> V_15 ) ;
if ( ! V_17 )
F_8 ( & V_5 -> V_15 , L_1 ) ;
else
F_8 ( & V_5 -> V_15 , L_2 ) ;
}
static const char * F_10 ( struct V_5 * V_5 )
{
return L_3 ;
}
static const char * F_11 ( struct V_5 * V_18 )
{
struct V_1 * V_5 = F_12 ( V_18 ) ;
return ( const char * ) V_5 -> V_9 -> V_19 ;
}
static bool F_13 ( struct V_5 * V_18 )
{
return true ;
}
static void F_14 ( struct V_20 * V_21 )
{
struct V_5 * V_18 = F_15 ( V_21 , struct V_5 , V_21 ) ;
struct V_1 * V_5 = F_12 ( V_18 ) ;
F_16 ( V_5 -> V_22 ) ;
F_17 ( V_7 , V_5 ) ;
}
static void F_18 ( struct V_5 * V_18 )
{
struct V_1 * V_5 = F_12 ( V_18 ) ;
F_19 ( & V_5 -> V_15 . V_21 , F_14 ) ;
}
static void F_20 ( struct V_5 * V_18 )
{
struct V_1 * V_5 = F_12 ( V_18 ) ;
F_16 ( & V_5 -> V_12 ) ;
}
