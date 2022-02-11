static void
F_1 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , L_1 , ( V_4 == V_5 ) ? L_2 :
( V_4 == V_6 ) ? L_3 : L_4 ) ;
if ( V_2 -> V_7 -> V_4 )
V_2 -> V_7 -> V_4 ( V_2 , V_4 ) ;
}
void
V_3 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , L_5 , V_4 ) ;
F_3 ( & V_2 -> V_8 ) ;
F_1 ( V_2 , V_4 ) ;
V_2 -> V_4 = V_4 ;
F_4 ( & V_2 -> V_8 ) ;
}
void
F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_6 ) ;
if ( V_2 -> V_4 == V_9 )
F_1 ( V_2 , V_2 -> V_4 ) ;
F_4 ( & V_2 -> V_8 ) ;
}
int
F_6 ( struct V_1 * V_2 , enum V_3 V_4 )
{
F_2 ( V_2 , L_7 ) ;
F_3 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_4 != V_4 ) {
if ( V_2 -> V_4 != V_9 ) {
F_4 ( & V_2 -> V_8 ) ;
return - V_10 ;
}
F_1 ( V_2 , V_4 ) ;
}
return 0 ;
}
void
F_7 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_8 ) ;
F_1 ( V_2 , V_9 ) ;
}
void
F_8 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_9 ) ;
F_1 ( V_2 , V_2 -> V_4 ) ;
}
void
F_9 ( struct V_1 * * V_11 )
{
struct V_1 * V_2 = * V_11 ;
if ( V_2 ) {
F_2 ( V_2 , L_10 ) ;
F_10 ( & V_2 -> V_12 ) ;
F_11 ( V_2 ) ;
V_2 = NULL ;
}
}
void
F_12 ( const struct V_13 * V_7 , struct V_14 * V_15 ,
int V_16 , struct V_1 * V_2 )
{
V_2 -> V_7 = V_7 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_4 = V_9 ;
F_13 ( & V_2 -> V_8 ) ;
F_14 ( & V_2 -> V_12 , & V_15 -> V_2 ) ;
F_2 ( V_2 , L_11 ) ;
}
int
F_15 ( const struct V_13 * V_7 , struct V_14 * V_15 ,
int V_16 , struct V_1 * * V_11 )
{
if ( ! ( * V_11 = F_16 ( sizeof( * * V_11 ) , V_17 ) ) )
return - V_18 ;
F_12 ( V_7 , V_15 , V_16 , * V_11 ) ;
return 0 ;
}
