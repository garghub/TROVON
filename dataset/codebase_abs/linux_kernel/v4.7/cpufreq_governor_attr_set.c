static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_4 * F_3 ( struct V_5 * V_6 )
{
return F_2 ( V_6 , struct V_4 , V_6 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 , struct V_5 * V_6 ,
char * V_7 )
{
struct V_4 * V_8 = F_3 ( V_6 ) ;
return V_8 -> V_9 ( F_1 ( V_3 ) , V_7 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 , struct V_5 * V_6 ,
const char * V_7 , T_2 V_10 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
struct V_4 * V_8 = F_3 ( V_6 ) ;
int V_12 ;
F_6 ( & V_11 -> V_13 ) ;
V_12 = V_11 -> V_14 ? V_8 -> V_15 ( V_11 , V_7 , V_10 ) : - V_16 ;
F_7 ( & V_11 -> V_13 ) ;
return V_12 ;
}
void F_8 ( struct V_1 * V_11 , struct V_17 * V_18 )
{
F_9 ( & V_11 -> V_19 ) ;
F_10 ( & V_11 -> V_13 ) ;
V_11 -> V_14 = 1 ;
F_11 ( V_18 , & V_11 -> V_19 ) ;
}
void F_12 ( struct V_1 * V_11 , struct V_17 * V_18 )
{
F_6 ( & V_11 -> V_13 ) ;
V_11 -> V_14 ++ ;
F_11 ( V_18 , & V_11 -> V_19 ) ;
F_7 ( & V_11 -> V_13 ) ;
}
unsigned int F_13 ( struct V_1 * V_11 , struct V_17 * V_18 )
{
unsigned int V_10 ;
F_6 ( & V_11 -> V_13 ) ;
F_14 ( V_18 ) ;
V_10 = -- V_11 -> V_14 ;
F_7 ( & V_11 -> V_13 ) ;
if ( V_10 )
return V_10 ;
F_15 ( & V_11 -> V_3 ) ;
F_16 ( & V_11 -> V_13 ) ;
return 0 ;
}
