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
F_4 ( F_5 () ) ;
F_4 ( V_2 -> V_15 == V_16 ) ;
V_2 -> V_17 = V_9 ;
V_2 -> V_18 = V_11 ;
if ( V_7 -> V_19 ) {
F_6 ( V_2 , V_10 , true , false ) ;
return;
}
F_7 ( V_7 -> V_20 ) ;
if ( F_8 ( F_9 ( V_7 ) ) ) {
V_2 -> V_21 |= V_22 ;
V_2 -> V_23 = - V_24 ;
F_10 ( V_2 , V_2 -> V_23 ) ;
F_11 ( V_7 -> V_20 ) ;
return;
}
F_12 ( V_7 , V_2 , V_12 ) ;
F_13 ( V_7 ) ;
F_11 ( V_7 -> V_20 ) ;
}
int F_14 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 )
{
F_15 ( V_25 ) ;
char V_26 [ V_27 ] ;
int V_28 = 0 ;
unsigned long V_29 ;
if ( ! V_2 -> V_26 ) {
memset ( V_26 , 0 , sizeof( V_26 ) ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_30 = 0 ;
}
V_2 -> V_5 = & V_25 ;
F_3 ( V_7 , V_9 , V_2 , V_10 , F_1 ) ;
V_29 = V_31 ;
if ( V_29 )
while ( ! F_16 ( & V_25 , V_29 * ( V_32 / 2 ) ) ) ;
else
F_17 ( & V_25 ) ;
if ( V_2 -> V_23 )
V_28 = - V_33 ;
if ( V_2 -> V_26 == V_26 ) {
V_2 -> V_26 = NULL ;
V_2 -> V_30 = 0 ;
}
return V_28 ;
}
