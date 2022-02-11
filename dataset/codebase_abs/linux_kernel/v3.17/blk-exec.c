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
F_4 ( V_2 -> V_16 == V_17 ) ;
V_2 -> V_18 = V_9 ;
V_2 -> V_19 = V_11 ;
if ( V_7 -> V_20 ) {
F_6 ( V_2 , V_10 , true , false ) ;
return;
}
V_15 = V_2 -> V_16 == V_21 ;
F_7 ( V_7 -> V_22 ) ;
if ( F_8 ( F_9 ( V_7 ) ) ) {
V_2 -> V_23 |= V_24 ;
V_2 -> V_25 = - V_26 ;
F_10 ( V_2 , V_2 -> V_25 ) ;
F_11 ( V_7 -> V_22 ) ;
return;
}
F_12 ( V_7 , V_2 , V_12 ) ;
F_13 ( V_7 ) ;
if ( V_15 )
F_14 ( V_7 ) ;
F_11 ( V_7 -> V_22 ) ;
}
int F_15 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_1 * V_2 , int V_10 )
{
F_16 ( V_27 ) ;
char V_28 [ V_29 ] ;
int V_30 = 0 ;
unsigned long V_31 ;
if ( ! V_2 -> V_28 ) {
memset ( V_28 , 0 , sizeof( V_28 ) ) ;
V_2 -> V_28 = V_28 ;
V_2 -> V_32 = 0 ;
}
V_2 -> V_5 = & V_27 ;
F_3 ( V_7 , V_9 , V_2 , V_10 , F_1 ) ;
V_31 = V_33 ;
if ( V_31 )
while ( ! F_17 ( & V_27 , V_31 * ( V_34 / 2 ) ) ) ;
else
F_18 ( & V_27 ) ;
if ( V_2 -> V_25 )
V_30 = - V_35 ;
if ( V_2 -> V_28 == V_28 ) {
V_2 -> V_28 = NULL ;
V_2 -> V_32 = 0 ;
}
return V_30 ;
}
