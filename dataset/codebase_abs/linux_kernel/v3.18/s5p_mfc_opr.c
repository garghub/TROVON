void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_3 = F_3 () ;
V_2 -> V_4 = V_5 ;
} else {
V_3 = F_4 () ;
V_2 -> V_4 = V_6 ;
}
V_2 -> V_7 = V_3 ;
}
void F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) )
V_2 -> V_8 = F_6 ( V_2 ) ;
}
int F_7 ( struct V_9 * V_2 ,
struct V_10 * V_11 )
{
F_8 ( 3 , L_1 , V_11 -> V_12 ) ;
V_11 -> V_13 = F_9 ( V_2 , V_11 -> V_12 , & V_11 -> V_14 , V_15 ) ;
if ( ! V_11 -> V_13 ) {
F_10 ( L_2 ) ;
return - V_16 ;
}
F_8 ( 3 , L_3 , V_11 -> V_13 , & V_11 -> V_14 ) ;
return 0 ;
}
void F_11 ( struct V_9 * V_2 ,
struct V_10 * V_11 )
{
if ( V_11 -> V_13 ) {
F_12 ( V_2 , V_11 -> V_12 , V_11 -> V_13 , V_11 -> V_14 ) ;
V_11 -> V_13 = NULL ;
V_11 -> V_14 = 0 ;
V_11 -> V_12 = 0 ;
}
}
