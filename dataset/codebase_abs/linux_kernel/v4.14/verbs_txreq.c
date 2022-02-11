void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
unsigned long V_7 ;
unsigned int V_8 ;
struct V_9 * V_10 ;
V_6 = V_2 -> V_6 ;
V_4 = F_2 ( V_6 -> V_11 . V_12 ) ;
if ( V_2 -> V_13 )
F_3 ( V_2 -> V_13 ) ;
F_4 ( F_5 ( V_4 ) , & V_2 -> V_14 ) ;
F_6 ( V_4 -> V_15 , V_2 ) ;
do {
V_8 = F_7 ( & V_4 -> V_16 ) ;
if ( ! F_8 ( & V_4 -> V_17 ) ) {
struct V_18 * V_19 ;
F_9 ( & V_4 -> V_16 , V_7 ) ;
V_19 = F_10 ( & V_4 -> V_17 , struct V_18 ,
V_20 ) ;
V_6 = F_11 ( V_19 ) ;
V_10 = V_6 -> V_10 ;
F_12 ( & V_10 -> V_21 . V_20 ) ;
F_13 ( & V_4 -> V_16 , V_7 ) ;
F_14 ( V_6 , V_22 ) ;
break;
}
} while ( F_15 ( & V_4 -> V_16 , V_8 ) );
}
struct V_1 * F_16 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
__must_hold( &qp->s_lock
int F_17 ( struct V_3 * V_4 )
{
char V_23 [ V_24 ] ;
struct V_25 * V_26 = F_5 ( V_4 ) ;
snprintf ( V_23 , sizeof( V_23 ) , L_1 , V_26 -> V_27 ) ;
V_4 -> V_15 = F_18 ( V_23 ,
sizeof( struct V_1 ) ,
0 , V_28 ,
NULL ) ;
if ( ! V_4 -> V_15 )
return - V_29 ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 )
{
F_20 ( V_4 -> V_15 ) ;
V_4 -> V_15 = NULL ;
}
