static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 . V_6 . V_4 ;
T_1 V_7 = V_2 -> V_8 ? V_2 -> V_7 : 0 , V_9 ;
for ( V_9 = 0 ; V_9 < 2 ; V_9 ++ ) {
F_2 ( V_4 , 0x000180 + ( V_9 * 0x04 ) , ~ V_7 ) ;
F_2 ( V_4 , 0x000160 + ( V_9 * 0x04 ) , V_7 ) ;
}
}
void
F_3 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
unsigned long V_11 ;
F_4 ( & V_2 -> V_12 , V_11 ) ;
V_2 -> V_8 = false ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_12 , V_11 ) ;
}
void
F_6 ( struct V_10 * V_5 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
unsigned long V_11 ;
F_4 ( & V_2 -> V_12 , V_11 ) ;
V_2 -> V_8 = true ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_12 , V_11 ) ;
}
void
F_7 ( struct V_10 * V_5 , T_1 V_7 , T_1 V_8 )
{
struct V_1 * V_2 = V_1 ( V_5 ) ;
unsigned long V_11 ;
F_4 ( & V_2 -> V_12 , V_11 ) ;
V_2 -> V_7 = ( V_2 -> V_7 & ~ V_7 ) | V_8 ;
F_1 ( V_2 ) ;
F_5 ( & V_2 -> V_12 , V_11 ) ;
}
int
F_8 ( const struct V_13 * V_14 , struct V_3 * V_4 ,
int V_15 , struct V_10 * * V_16 )
{
struct V_1 * V_2 ;
if ( ! ( V_2 = F_9 ( sizeof( * V_2 ) , V_17 ) ) )
return - V_18 ;
F_10 ( V_14 , V_4 , V_15 , & V_2 -> V_5 ) ;
* V_16 = & V_2 -> V_5 ;
F_11 ( & V_2 -> V_12 ) ;
V_2 -> V_8 = false ;
V_2 -> V_7 = 0x7fffffff ;
return 0 ;
}
int
F_12 ( struct V_3 * V_4 , int V_15 , struct V_10 * * V_16 )
{
return F_8 ( & V_1 , V_4 , V_15 , V_16 ) ;
}
