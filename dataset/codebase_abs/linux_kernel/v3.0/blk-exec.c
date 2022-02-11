static void F_1 ( struct V_1 * V_2 , int error )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_2 ( V_2 -> V_6 , V_2 ) ;
F_3 ( V_4 ) ;
}
void F_4 ( struct V_7 * V_6 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 ,
T_1 * V_11 )
{
int V_12 = V_10 ? V_13 : V_14 ;
V_2 -> V_15 = V_9 ;
V_2 -> V_16 = V_11 ;
F_5 ( F_6 () ) ;
F_7 ( V_6 -> V_17 ) ;
F_8 ( V_6 , V_2 , V_12 ) ;
F_9 ( V_6 ) ;
if ( V_2 -> V_18 == V_19 )
V_6 -> V_20 ( V_6 ) ;
F_10 ( V_6 -> V_17 ) ;
}
int F_11 ( struct V_7 * V_6 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 )
{
F_12 ( V_21 ) ;
char V_22 [ V_23 ] ;
int V_24 = 0 ;
unsigned long V_25 ;
V_2 -> V_26 ++ ;
if ( ! V_2 -> V_22 ) {
memset ( V_22 , 0 , sizeof( V_22 ) ) ;
V_2 -> V_22 = V_22 ;
V_2 -> V_27 = 0 ;
}
V_2 -> V_5 = & V_21 ;
F_4 ( V_6 , V_9 , V_2 , V_10 , F_1 ) ;
V_25 = V_28 ;
if ( V_25 )
while ( ! F_13 ( & V_21 , V_25 * ( V_29 / 2 ) ) ) ;
else
F_14 ( & V_21 ) ;
if ( V_2 -> V_30 )
V_24 = - V_31 ;
return V_24 ;
}
