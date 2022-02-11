static int F_1 ( void * V_1 ,
unsigned int V_2 , void * V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_1 ;
T_3 * V_6 = V_3 ;
int V_7 = 0 , V_8 = V_4 ;
while ( V_8 -- )
* V_6 ++ = F_2 ( V_5 + V_2 + V_7 ++ ) ;
return 0 ;
}
static int F_3 ( void * V_1 ,
unsigned int V_2 , void * V_3 , T_1 V_4 )
{
void T_2 * V_5 = V_1 ;
T_3 * V_6 = V_3 ;
int V_7 = 0 , V_8 = V_4 ;
while ( V_8 -- )
F_4 ( * V_6 ++ , V_5 + V_2 + V_7 ++ ) ;
return 0 ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_12 = F_6 ( V_10 ) ;
return F_7 ( V_12 ) ;
}
static int F_8 ( struct V_9 * V_10 )
{
struct V_13 * V_14 = & V_10 -> V_14 ;
struct V_15 * V_16 ;
struct V_11 * V_12 ;
void T_2 * V_5 ;
V_16 = F_9 ( V_10 , V_17 , 0 ) ;
V_5 = F_10 ( V_14 , V_16 ) ;
if ( F_11 ( V_5 ) )
return F_12 ( V_5 ) ;
V_18 . V_19 = F_13 ( V_16 ) ;
V_18 . V_14 = V_14 ;
V_18 . V_20 = V_5 ;
V_12 = F_14 ( & V_18 ) ;
if ( F_11 ( V_12 ) )
return F_12 ( V_12 ) ;
F_15 ( V_10 , V_12 ) ;
return 0 ;
}
