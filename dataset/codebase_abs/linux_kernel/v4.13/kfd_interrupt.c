int F_1 ( struct V_1 * V_2 )
{
void * V_3 = F_2 ( V_4 ,
V_2 -> V_5 -> V_6 ,
V_7 ) ;
if ( ! V_3 )
return - V_8 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_9 =
V_4 * V_2 -> V_5 -> V_6 ;
F_3 ( & V_2 -> V_10 , 0 ) ;
F_3 ( & V_2 -> V_11 , 0 ) ;
F_4 ( & V_2 -> V_12 ) ;
F_5 ( & V_2 -> V_13 , V_14 ) ;
V_2 -> V_15 = true ;
F_6 () ;
return 0 ;
}
void F_7 ( struct V_1 * V_2 )
{
unsigned long V_16 ;
F_8 ( & V_2 -> V_12 , V_16 ) ;
V_2 -> V_15 = false ;
F_9 ( & V_2 -> V_12 , V_16 ) ;
F_10 () ;
F_11 ( V_2 -> V_3 ) ;
}
bool F_12 ( struct V_1 * V_2 , const void * V_17 )
{
unsigned int V_18 = F_13 ( & V_2 -> V_11 ) ;
unsigned int V_19 = F_13 ( & V_2 -> V_10 ) ;
if ( ( V_18 - V_19 ) % V_2 -> V_9 ==
V_2 -> V_5 -> V_6 ) {
F_14 ( F_15 () ,
L_1 ) ;
return false ;
}
memcpy ( V_2 -> V_3 + V_19 , V_17 ,
V_2 -> V_5 -> V_6 ) ;
V_19 = ( V_19 + V_2 -> V_5 -> V_6 ) %
V_2 -> V_9 ;
F_6 () ;
F_3 ( & V_2 -> V_10 , V_19 ) ;
return true ;
}
static bool F_16 ( struct V_1 * V_2 , void * V_17 )
{
unsigned int V_19 = F_13 ( & V_2 -> V_10 ) ;
unsigned int V_18 = F_13 ( & V_2 -> V_11 ) ;
if ( V_18 == V_19 )
return false ;
memcpy ( V_17 , V_2 -> V_3 + V_18 ,
V_2 -> V_5 -> V_6 ) ;
V_18 = ( V_18 + V_2 -> V_5 -> V_6 ) %
V_2 -> V_9 ;
F_17 () ;
F_3 ( & V_2 -> V_11 , V_18 ) ;
return true ;
}
static void V_14 ( struct V_20 * V_21 )
{
struct V_1 * V_22 = F_18 ( V_21 , struct V_1 ,
V_13 ) ;
T_1 V_17 [ F_19 (
V_22 -> V_5 -> V_6 ,
sizeof( T_1 ) ) ] ;
while ( F_16 ( V_22 , V_17 ) )
V_22 -> V_5 -> V_23 -> V_14 ( V_22 ,
V_17 ) ;
}
bool F_20 ( struct V_1 * V_22 , const T_1 * V_17 )
{
unsigned V_24 = 0 ;
V_24 |= V_22 -> V_5 -> V_23 -> V_25 ( V_22 ,
V_17 ) ;
return V_24 != 0 ;
}
