int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned int V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_7 = V_2 -> V_8 ;
V_3 = F_2 ( V_2 -> V_9 ) ;
if ( ! V_3 )
return 1 ;
V_4 = F_3 ( V_7 -> V_10 ) ;
V_11 . V_12 = F_4 ( V_4 ) ;
V_6 = F_5 ( V_2 -> V_9 , V_3 ) ;
F_6 ( & V_6 -> V_11 , & V_11 , sizeof( struct V_13 ) ) ;
F_6 ( & V_6 -> V_14 , V_7 -> V_10 , V_4 ) ;
F_7 ( V_2 -> V_9 , V_3 ) ;
return 0 ;
}
T_2 F_8 ( int V_15 , void * V_16 )
{
T_1 V_3 ;
struct V_1 * V_2 = (struct V_1 * ) V_16 ;
void T_3 * V_9 = V_2 -> V_9 ;
char V_17 [ 32 ] ;
if ( ! F_9 ( V_9 ) )
return V_18 ;
F_10 ( L_1 , F_11 ( V_17 ) ) ;
if ( F_12 ( V_2 ) ) {
F_13 ( V_2 ) ;
F_14 ( V_2 ) ;
}
V_3 = F_15 ( V_9 ) ;
if ( F_16 ( V_3 ) ) {
struct V_5 * V_19 = F_5 ( V_9 , V_3 ) ;
F_17 ( V_2 , & V_19 -> V_14 , F_18 ( V_19 ) ) ;
} else
F_10 ( L_2 ) ;
F_19 ( V_9 , V_3 ) ;
F_10 ( L_3 , F_11 ( V_17 ) ) ;
return V_20 ;
}
