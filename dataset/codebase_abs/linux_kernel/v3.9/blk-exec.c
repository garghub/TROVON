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
bool V_15 ;
F_5 ( F_6 () ) ;
V_2 -> V_16 = V_9 ;
V_2 -> V_17 = V_11 ;
V_15 = V_2 -> V_18 == V_19 ;
F_7 ( V_6 -> V_20 ) ;
if ( F_8 ( F_9 ( V_6 ) ) ) {
V_2 -> V_21 = - V_22 ;
if ( V_2 -> V_17 )
V_2 -> V_17 ( V_2 , V_2 -> V_21 ) ;
F_10 ( V_6 -> V_20 ) ;
return;
}
F_11 ( V_6 , V_2 , V_12 ) ;
F_12 ( V_6 ) ;
if ( V_15 )
F_13 ( V_6 ) ;
F_10 ( V_6 -> V_20 ) ;
}
int F_14 ( struct V_7 * V_6 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 )
{
F_15 ( V_23 ) ;
char V_24 [ V_25 ] ;
int V_26 = 0 ;
unsigned long V_27 ;
V_2 -> V_28 ++ ;
if ( ! V_2 -> V_24 ) {
memset ( V_24 , 0 , sizeof( V_24 ) ) ;
V_2 -> V_24 = V_24 ;
V_2 -> V_29 = 0 ;
}
V_2 -> V_5 = & V_23 ;
F_4 ( V_6 , V_9 , V_2 , V_10 , F_1 ) ;
V_27 = V_30 ;
if ( V_27 )
while ( ! F_16 ( & V_23 , V_27 * ( V_31 / 2 ) ) ) ;
else
F_17 ( & V_23 ) ;
if ( V_2 -> V_21 )
V_26 = - V_32 ;
return V_26 ;
}
