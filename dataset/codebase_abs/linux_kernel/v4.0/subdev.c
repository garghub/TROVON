struct V_1 *
V_1 ( void * V_2 , int V_3 )
{
struct V_4 * V_5 = F_1 ( V_2 ) ;
while ( V_5 && ! F_2 ( V_5 , V_6 ) )
V_5 = V_5 -> V_7 ;
if ( V_5 == NULL || F_3 ( F_4 ( V_5 ) ) != V_3 )
V_5 = F_5 ( V_2 ) -> V_8 [ V_3 ] ;
return V_5 ? F_4 ( V_5 ) : NULL ;
}
void
F_6 ( struct V_4 * V_8 )
{
F_7 ( V_8 , L_1 ) ;
F_8 ( V_8 ) -> F_9 ( V_8 , false ) ;
F_10 ( V_8 , L_2 ) ;
}
int
F_11 ( struct V_1 * V_8 )
{
int V_9 = F_12 ( & V_8 -> V_5 ) ;
if ( V_9 )
return V_9 ;
F_6 ( & V_8 -> V_5 ) ;
return 0 ;
}
int
F_13 ( struct V_4 * V_5 )
{
return F_11 ( F_4 ( V_5 ) ) ;
}
int
F_14 ( struct V_1 * V_8 , bool V_10 )
{
if ( V_8 -> V_11 ) {
F_15 ( V_8 , 0x000200 , V_8 -> V_11 , 0x00000000 ) ;
F_15 ( V_8 , 0x000200 , V_8 -> V_11 , V_8 -> V_11 ) ;
}
return F_16 ( & V_8 -> V_5 , V_10 ) ;
}
int
F_17 ( struct V_4 * V_5 , bool V_10 )
{
return F_14 ( F_4 ( V_5 ) , V_10 ) ;
}
void
F_18 ( struct V_1 * V_8 )
{
int V_12 = F_19 ( V_8 ) & 0xff ;
F_5 ( V_8 ) -> V_8 [ V_12 ] = NULL ;
F_20 ( & V_8 -> V_5 ) ;
}
void
F_21 ( struct V_4 * V_5 )
{
F_18 ( F_4 ( V_5 ) ) ;
}
int
F_22 ( struct V_4 * V_7 , struct V_4 * V_13 ,
struct V_14 * V_15 , T_1 V_16 ,
const char * V_17 , const char * V_18 ,
int V_19 , void * * V_20 )
{
struct V_1 * V_8 ;
int V_9 ;
V_9 = F_23 ( V_7 , V_13 , V_15 , V_16 |
V_6 , V_19 , V_20 ) ;
V_8 = * V_20 ;
if ( V_9 )
return V_9 ;
F_24 ( & V_8 -> V_21 , V_17 , & V_15 -> V_22 ) ;
V_8 -> V_23 = V_17 ;
if ( V_7 ) {
struct V_24 * V_25 = F_5 ( V_7 ) ;
V_8 -> V_26 = F_25 ( V_25 -> V_27 , V_17 ) ;
V_8 -> V_28 = F_4 ( V_25 ) -> V_28 ;
}
return 0 ;
}
