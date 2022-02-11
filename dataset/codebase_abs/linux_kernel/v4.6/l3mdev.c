int F_1 ( const struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_2 ( V_2 ) ) {
V_3 = V_2 -> V_3 ;
} else if ( F_3 ( V_2 ) ) {
struct V_1 * V_4 ;
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
V_4 = F_4 ( V_5 ) ;
if ( V_4 )
V_3 = V_4 -> V_3 ;
}
return V_3 ;
}
T_1 F_5 ( const struct V_1 * V_2 )
{
T_1 V_6 = 0 ;
if ( ! V_2 )
return 0 ;
if ( F_2 ( V_2 ) ) {
if ( V_2 -> V_7 -> V_8 )
V_6 = V_2 -> V_7 -> V_8 ( V_2 ) ;
} else if ( F_3 ( V_2 ) ) {
struct V_1 * V_5 = (struct V_1 * ) V_2 ;
const struct V_1 * V_4 ;
V_4 = F_4 ( V_5 ) ;
if ( V_4 &&
V_4 -> V_7 -> V_8 )
V_6 = V_4 -> V_7 -> V_8 ( V_4 ) ;
}
return V_6 ;
}
T_1 F_6 ( struct V_9 * V_9 , int V_3 )
{
struct V_1 * V_2 ;
T_1 V_6 = 0 ;
if ( ! V_3 )
return 0 ;
F_7 () ;
V_2 = F_8 ( V_9 , V_3 ) ;
if ( V_2 )
V_6 = F_5 ( V_2 ) ;
F_9 () ;
return V_6 ;
}
