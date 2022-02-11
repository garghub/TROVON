static inline int
F_1 ( T_1 * V_1 , struct V_2 T_2 * * V_3 ,
T_1 T_2 * V_4 , unsigned int * V_5 )
{
if ( F_2 ( * V_1 , V_4 ) )
return - V_6 ;
* V_3 = F_3 ( ( * V_1 ) & ~ 1 ) ;
* V_5 = ( unsigned int ) ( * V_1 ) & 1 ;
return 0 ;
}
static void T_2 * F_4 ( struct V_2 T_2 * V_3 ,
T_3 V_7 )
{
T_1 V_8 = F_5 ( V_3 ) ;
void T_2 * V_9 = F_3 ( V_8 + V_7 ) ;
return V_9 ;
}
void F_6 ( struct V_10 * V_11 )
{
struct V_12 T_2 * V_4 = V_11 -> V_13 ;
struct V_2 T_2 * V_3 , * V_14 , * V_15 ;
unsigned int V_16 = V_17 , V_5 , V_18 ;
unsigned int V_19 ( V_20 ) ;
T_1 V_1 , V_21 , V_22 ;
T_3 V_7 ;
int V_23 ;
if ( ! V_24 )
return;
if ( F_1 ( & V_1 , & V_3 , & V_4 -> V_25 . V_26 , & V_5 ) )
return;
if ( F_2 ( V_7 , & V_4 -> V_7 ) )
return;
if ( F_1 ( & V_22 , & V_15 ,
& V_4 -> V_27 , & V_18 ) )
return;
V_14 = NULL ;
while ( V_3 != (struct V_2 T_2 * ) & V_4 -> V_25 ) {
V_23 = F_1 ( & V_21 , & V_14 ,
( T_1 T_2 * ) & V_3 -> V_26 , & V_20 ) ;
if ( V_3 != V_15 ) {
void T_2 * V_9 = F_4 ( V_3 , V_7 ) ;
if ( F_7 ( V_9 , V_11 , V_5 ) )
return;
}
if ( V_23 )
return;
V_1 = V_21 ;
V_3 = V_14 ;
V_5 = V_20 ;
if ( ! -- V_16 )
break;
F_8 () ;
}
if ( V_15 ) {
void T_2 * V_9 = F_4 ( V_15 , V_7 ) ;
F_7 ( V_9 , V_11 , V_18 ) ;
}
}
