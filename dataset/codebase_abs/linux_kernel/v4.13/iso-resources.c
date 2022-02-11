int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_2 -> V_5 = ~ 0uLL ;
V_2 -> V_4 = V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_7 = false ;
return 0 ;
}
void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 -> V_7 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
static unsigned int F_6 ( unsigned int V_8 , int V_9 )
{
unsigned int V_10 , V_11 ;
V_10 = 3 * 4 + F_7 ( V_8 , 4 ) ;
if ( V_9 <= V_12 )
V_11 = V_10 * ( 1 << ( V_12 - V_9 ) ) ;
else
V_11 = F_8 ( V_10 , 1 << ( V_9 - V_12 ) ) ;
return V_11 ;
}
static int F_9 ( struct V_13 * V_14 )
{
return V_14 -> V_15 < 63 ? V_14 -> V_15 * 97 / 10 + 89 : 512 ;
}
static int F_10 ( struct V_13 * V_14 )
{
for (; ; ) {
T_1 V_16 = ( V_14 -> V_17 + V_18 ) - F_11 () ;
if ( V_16 <= 0 )
return 0 ;
if ( F_12 ( V_16 ) > 0 )
return - V_19 ;
}
}
int F_13 ( struct V_1 * V_2 ,
unsigned int V_8 , int V_9 )
{
struct V_13 * V_14 = F_14 ( V_2 -> V_4 ) -> V_14 ;
int V_20 , V_21 , V_22 ;
if ( F_4 ( V_2 -> V_7 ) )
return - V_23 ;
V_2 -> V_20 = F_6 ( V_8 , V_9 ) ;
V_24:
F_15 ( & V_14 -> V_25 ) ;
V_2 -> V_26 = V_14 -> V_26 ;
V_2 -> V_27 = F_9 ( V_14 ) ;
F_16 ( & V_14 -> V_25 ) ;
V_22 = F_10 ( V_14 ) ;
if ( V_22 < 0 )
return V_22 ;
F_17 ( & V_2 -> V_6 ) ;
V_20 = V_2 -> V_20 + V_2 -> V_27 ;
F_18 ( V_14 , V_2 -> V_26 , V_2 -> V_5 ,
& V_21 , & V_20 , true ) ;
if ( V_21 == - V_28 ) {
F_19 ( & V_2 -> V_6 ) ;
goto V_24;
}
if ( V_21 >= 0 ) {
V_2 -> V_21 = V_21 ;
V_2 -> V_7 = true ;
} else {
if ( V_21 == - V_29 )
F_20 ( & V_2 -> V_4 -> V_30 ,
L_1 ) ;
else
F_20 ( & V_2 -> V_4 -> V_30 ,
L_2 ) ;
}
F_19 ( & V_2 -> V_6 ) ;
return V_21 ;
}
int F_21 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = F_14 ( V_2 -> V_4 ) -> V_14 ;
int V_20 , V_21 ;
F_17 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_7 ) {
F_19 ( & V_2 -> V_6 ) ;
return 0 ;
}
F_15 ( & V_14 -> V_25 ) ;
V_2 -> V_26 = V_14 -> V_26 ;
V_2 -> V_27 = F_9 ( V_14 ) ;
F_16 ( & V_14 -> V_25 ) ;
V_20 = V_2 -> V_20 + V_2 -> V_27 ;
F_18 ( V_14 , V_2 -> V_26 , 1uLL << V_2 -> V_21 ,
& V_21 , & V_20 , true ) ;
if ( V_21 < 0 && V_21 != - V_28 ) {
V_2 -> V_7 = false ;
if ( V_21 == - V_29 )
F_20 ( & V_2 -> V_4 -> V_30 ,
L_1 ) ;
else
F_20 ( & V_2 -> V_4 -> V_30 ,
L_2 ) ;
}
F_19 ( & V_2 -> V_6 ) ;
return V_21 ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_20 , V_21 ;
if ( V_2 -> V_4 == NULL )
return;
V_14 = F_14 ( V_2 -> V_4 ) -> V_14 ;
F_17 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_7 ) {
V_20 = V_2 -> V_20 + V_2 -> V_27 ;
F_18 ( V_14 , V_2 -> V_26 , 1uLL << V_2 -> V_21 ,
& V_21 , & V_20 , false ) ;
if ( V_21 < 0 )
F_20 ( & V_2 -> V_4 -> V_30 ,
L_3 ) ;
V_2 -> V_7 = false ;
}
F_19 ( & V_2 -> V_6 ) ;
}
