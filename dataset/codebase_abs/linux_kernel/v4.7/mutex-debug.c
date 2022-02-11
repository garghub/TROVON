void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
memset ( V_4 , V_5 , sizeof( * V_4 ) ) ;
V_4 -> V_6 = V_4 ;
F_2 ( & V_4 -> V_7 ) ;
}
void F_3 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_4 ( ! F_5 ( & V_2 -> V_8 ) ) ;
F_6 ( F_7 ( & V_2 -> V_9 ) ) ;
F_6 ( V_4 -> V_6 != V_4 ) ;
F_6 ( F_7 ( & V_4 -> V_7 ) ) ;
}
void F_8 ( struct V_3 * V_4 )
{
F_6 ( ! F_7 ( & V_4 -> V_7 ) ) ;
memset ( V_4 , V_10 , sizeof( * V_4 ) ) ;
}
void F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_11 * V_12 )
{
F_4 ( ! F_5 ( & V_2 -> V_8 ) ) ;
V_12 -> V_13 = V_4 ;
}
void F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_11 * V_12 )
{
F_6 ( F_7 ( & V_4 -> V_7 ) ) ;
F_6 ( V_4 -> V_12 != V_12 ) ;
F_6 ( V_12 -> V_13 != V_4 ) ;
V_12 -> V_13 = NULL ;
F_11 ( & V_4 -> V_7 ) ;
V_4 -> V_12 = NULL ;
}
void F_12 ( struct V_1 * V_2 )
{
if ( F_13 ( V_14 ) ) {
F_6 ( V_2 -> V_6 != V_2 ) ;
if ( ! V_2 -> V_15 )
F_6 ( ! V_2 -> V_15 ) ;
else
F_6 ( V_2 -> V_15 != V_16 ) ;
F_6 ( ! V_2 -> V_9 . V_17 && ! V_2 -> V_9 . V_18 ) ;
}
F_14 ( V_2 ) ;
F_15 ( & V_2 -> V_19 , 1 ) ;
}
void F_16 ( struct V_1 * V_2 , const char * V_20 ,
struct V_21 * V_22 )
{
#ifdef F_17
F_18 ( ( void * ) V_2 , sizeof( * V_2 ) ) ;
F_19 ( & V_2 -> V_23 , V_20 , V_22 , 0 ) ;
#endif
V_2 -> V_6 = V_2 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_6 ( F_21 ( V_2 ) ) ;
V_2 -> V_6 = NULL ;
}
