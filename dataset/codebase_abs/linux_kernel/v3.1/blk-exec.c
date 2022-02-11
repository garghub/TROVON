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
if ( F_5 ( F_6 ( V_15 , & V_6 -> V_16 ) ) ) {
V_2 -> V_17 = - V_18 ;
if ( V_2 -> V_19 )
V_2 -> V_19 ( V_2 , V_2 -> V_17 ) ;
return;
}
V_2 -> V_20 = V_9 ;
V_2 -> V_19 = V_11 ;
F_7 ( F_8 () ) ;
F_9 ( V_6 -> V_21 ) ;
F_10 ( V_6 , V_2 , V_12 ) ;
F_11 ( V_6 ) ;
if ( V_2 -> V_22 == V_23 )
V_6 -> V_24 ( V_6 ) ;
F_12 ( V_6 -> V_21 ) ;
}
int F_13 ( struct V_7 * V_6 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 )
{
F_14 ( V_25 ) ;
char V_26 [ V_27 ] ;
int V_28 = 0 ;
unsigned long V_29 ;
V_2 -> V_30 ++ ;
if ( ! V_2 -> V_26 ) {
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_31 = 0 ;
}
V_2 -> V_5 = & V_25 ;
F_4 ( V_6 , V_9 , V_2 , V_10 , F_1 ) ;
V_29 = V_32 ;
if ( V_29 )
while ( ! F_15 ( & V_25 , V_29 * ( V_33 / 2 ) ) ) ;
else
F_16 ( & V_25 ) ;
if ( V_2 -> V_17 )
V_28 = - V_34 ;
return V_28 ;
}
