static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 , struct V_5 * V_6 )
{
int V_7 ;
V_7 = F_2 ( V_2 , V_3 , V_4 , V_6 , sizeof( * V_6 ) ) ;
if ( V_7 != sizeof( * V_6 ) ) {
F_3 ( V_2 , L_1 ,
V_7 , sizeof( * V_6 ) ) ;
return - V_8 ;
}
if ( V_6 -> V_9 != V_10 ) {
F_4 ( V_2 , L_2 ,
F_5 ( V_6 -> V_9 ) ) ;
return - V_11 ;
}
if ( V_6 -> V_12 != V_13 ) {
F_4 ( V_2 , L_3 ,
F_5 ( V_6 -> V_12 ) ) ;
return - V_11 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_14 * V_15 ;
T_1 V_3 ;
T_2 V_4 ;
int V_16 ;
V_15 = F_7 ( V_2 ) ;
if ( F_8 ( V_15 ) )
return F_9 ( V_15 ) ;
V_16 = F_10 ( V_15 , & V_3 , & V_4 ) ;
if ( V_16 )
goto V_17;
V_16 = F_1 ( V_2 , V_3 , V_4 , V_6 ) ;
V_17:
F_11 ( V_15 ) ;
return V_16 ;
}
const struct V_5 * F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 ;
int V_16 ;
V_6 = F_13 ( sizeof( * V_6 ) , V_18 ) ;
if ( ! V_6 )
return NULL ;
V_16 = F_6 ( V_2 , V_6 ) ;
if ( V_16 ) {
F_14 ( V_6 ) ;
return NULL ;
}
V_6 -> V_19 [ sizeof( V_6 -> V_19 ) - 1 ] = 0 ;
return V_6 ;
}
void F_15 ( const struct V_5 * V_6 )
{
F_14 ( V_6 ) ;
}
const char * F_16 ( const struct V_5 * V_6 )
{
return V_6 -> V_19 ;
}
void F_17 ( const struct V_5 * V_6 , T_1 * V_4 , T_1 * V_20 )
{
* V_4 = F_5 ( V_6 -> V_21 ) ;
* V_20 = F_5 ( V_6 -> V_22 ) ;
}
void F_18 ( const struct V_5 * V_6 , T_1 * V_4 , T_1 * V_20 )
{
* V_4 = F_5 ( V_6 -> V_23 ) ;
* V_20 = F_5 ( V_6 -> V_24 ) ;
}
