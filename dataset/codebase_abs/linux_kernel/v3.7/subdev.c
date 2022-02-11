void
F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 , L_1 ) ;
F_3 ( V_2 ) -> F_4 ( V_2 , false ) ;
F_5 ( V_2 , L_2 ) ;
}
int
F_6 ( struct V_3 * V_2 )
{
int V_4 = F_7 ( & V_2 -> V_5 ) ;
if ( V_4 )
return V_4 ;
F_1 ( & V_2 -> V_5 ) ;
return 0 ;
}
int
F_8 ( struct V_1 * V_6 )
{
return F_6 ( F_9 ( V_6 ) ) ;
}
int
F_10 ( struct V_3 * V_2 , bool V_7 )
{
if ( V_2 -> V_8 ) {
F_11 ( V_2 , 0x000200 , V_2 -> V_8 , 0x00000000 ) ;
F_11 ( V_2 , 0x000200 , V_2 -> V_8 , V_2 -> V_8 ) ;
}
return F_12 ( & V_2 -> V_5 , V_7 ) ;
}
int
F_13 ( struct V_1 * V_6 , bool V_7 )
{
return F_10 ( F_9 ( V_6 ) , V_7 ) ;
}
void
F_14 ( struct V_3 * V_2 )
{
int V_9 = F_15 ( V_2 ) & 0xff ;
F_16 ( V_2 ) -> V_2 [ V_9 ] = NULL ;
F_17 ( & V_2 -> V_5 ) ;
}
void
F_18 ( struct V_1 * V_6 )
{
F_14 ( F_9 ( V_6 ) ) ;
}
int
F_19 ( struct V_1 * V_10 ,
struct V_1 * V_11 ,
struct V_12 * V_13 , T_1 V_14 ,
const char * V_15 , const char * V_16 ,
int V_17 , void * * V_18 )
{
struct V_3 * V_2 ;
int V_4 ;
V_4 = F_20 ( V_10 , V_11 , V_13 , V_14 |
V_19 , V_17 , V_18 ) ;
V_2 = * V_18 ;
if ( V_4 )
return V_4 ;
F_21 ( & V_2 -> V_20 ) ;
V_2 -> V_21 = V_15 ;
if ( V_10 ) {
struct V_22 * V_23 = F_16 ( V_10 ) ;
int V_9 = F_15 ( V_2 ) & 0xff ;
V_2 -> V_24 = F_22 ( V_23 -> V_25 , V_15 ) ;
V_2 -> V_26 = F_9 ( V_23 ) -> V_26 ;
V_23 -> V_2 [ V_9 ] = * V_18 ;
}
return 0 ;
}
