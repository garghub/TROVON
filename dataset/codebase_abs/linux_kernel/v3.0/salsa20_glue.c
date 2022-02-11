static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_3 ( V_6 , V_3 , V_4 * 8 , V_7 * 8 ) ;
return 0 ;
}
static int F_4 ( struct V_8 * V_9 ,
struct V_10 * V_11 , struct V_10 * V_12 ,
unsigned int V_13 )
{
struct V_14 V_15 ;
struct V_16 * V_2 = V_9 -> V_2 ;
struct V_5 * V_6 = F_5 ( V_2 ) ;
int V_17 ;
F_6 ( & V_15 , V_11 , V_12 , V_13 ) ;
V_17 = F_7 ( V_9 , & V_15 , 64 ) ;
F_8 ( V_6 , V_15 . V_18 ) ;
if ( F_9 ( V_15 . V_13 == V_13 ) )
{
F_10 ( V_6 , V_15 . V_12 . V_19 . V_20 ,
V_15 . V_11 . V_19 . V_20 , V_13 ) ;
return F_11 ( V_9 , & V_15 , 0 ) ;
}
while ( V_15 . V_13 >= 64 ) {
F_10 ( V_6 , V_15 . V_12 . V_19 . V_20 ,
V_15 . V_11 . V_19 . V_20 ,
V_15 . V_13 - ( V_15 . V_13 % 64 ) ) ;
V_17 = F_11 ( V_9 , & V_15 , V_15 . V_13 % 64 ) ;
}
if ( V_15 . V_13 ) {
F_10 ( V_6 , V_15 . V_12 . V_19 . V_20 ,
V_15 . V_11 . V_19 . V_20 , V_15 . V_13 ) ;
V_17 = F_11 ( V_9 , & V_15 , 0 ) ;
}
return V_17 ;
}
static int T_2 F_12 ( void )
{
return F_13 ( & V_21 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_21 ) ;
}
