struct V_1 * F_1 ( unsigned int V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 ,
T_1 V_9 )
{
struct V_1 * V_10 ;
#ifdef F_2
static struct V_11 V_12 ;
#endif
V_10 = F_3 ( sizeof( * V_10 ) + V_2 , V_13 ) ;
if ( ! V_10 )
return NULL ;
#ifdef F_2
F_4 ( & V_10 -> V_14 , L_1 ,
& V_12 , 0 ) ;
#endif
V_10 -> V_4 = V_4 ;
V_10 -> V_6 = V_6 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_9 = V_9 ;
V_10 -> V_15 = 1 ;
snprintf ( V_10 -> V_16 , sizeof( V_10 -> V_16 ) ,
L_2 , F_5 ( V_10 -> V_4 ) ) ;
V_10 -> V_17 =
F_6 ( V_10 -> V_16 ,
sizeof( struct V_18 )
+ V_10 -> V_9 ,
sizeof( void * ) ,
V_19 ,
NULL ) ;
if ( ! V_10 -> V_17 )
goto free;
return V_10 ;
free:
F_7 ( V_10 ) ;
return NULL ;
}
void F_8 ( struct V_1 * V_10 )
{
F_9 ( V_10 -> V_17 ) ;
F_7 ( V_10 ) ;
}
