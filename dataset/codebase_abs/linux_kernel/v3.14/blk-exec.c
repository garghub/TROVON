static void F_1 ( struct V_1 * V_2 , int error )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_2 -> V_5 = NULL ;
F_2 ( V_4 ) ;
}
void F_3 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 ,
T_1 * V_11 )
{
int V_12 = V_10 ? V_13 : V_14 ;
bool V_15 ;
F_4 ( F_5 () ) ;
V_2 -> V_16 = V_9 ;
V_2 -> V_17 = V_11 ;
if ( V_7 -> V_18 ) {
F_6 ( V_2 , V_10 , true , false ) ;
return;
}
V_15 = V_2 -> V_19 == V_20 ;
F_7 ( V_7 -> V_21 ) ;
if ( F_8 ( F_9 ( V_7 ) ) ) {
V_2 -> V_22 |= V_23 ;
V_2 -> V_24 = - V_25 ;
F_10 ( V_2 , V_2 -> V_24 ) ;
F_11 ( V_7 -> V_21 ) ;
return;
}
F_12 ( V_7 , V_2 , V_12 ) ;
F_13 ( V_7 ) ;
if ( V_15 )
F_14 ( V_7 ) ;
F_11 ( V_7 -> V_21 ) ;
}
int F_15 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 )
{
F_16 ( V_26 ) ;
char V_27 [ V_28 ] ;
int V_29 = 0 ;
unsigned long V_30 ;
if ( ! V_2 -> V_27 ) {
memset ( V_27 , 0 , sizeof( V_27 ) ) ;
V_2 -> V_27 = V_27 ;
V_2 -> V_31 = 0 ;
}
V_2 -> V_5 = & V_26 ;
F_3 ( V_7 , V_9 , V_2 , V_10 , F_1 ) ;
V_30 = V_32 ;
if ( V_30 )
while ( ! F_17 ( & V_26 , V_30 * ( V_33 / 2 ) ) ) ;
else
F_18 ( & V_26 ) ;
if ( V_2 -> V_24 )
V_29 = - V_34 ;
return V_29 ;
}
