static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned long V_6 = 0 ;
F_3 ( V_4 -> V_7 , V_6 ) ;
if ( V_4 -> V_8 && ( * V_4 -> V_8 ) ++ > 0 )
goto V_9;
V_5 = F_4 ( V_4 -> V_5 ) ;
V_5 &= ~ ( 3 << V_4 -> V_10 ) ;
V_5 |= V_4 -> V_11 << V_4 -> V_10 ;
F_5 ( V_5 , V_4 -> V_5 ) ;
V_9:
F_6 ( V_4 -> V_7 , V_6 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_5 ;
unsigned long V_6 = 0 ;
F_3 ( V_4 -> V_7 , V_6 ) ;
if ( V_4 -> V_8 ) {
if ( F_8 ( * V_4 -> V_8 == 0 ) )
goto V_9;
else if ( -- ( * V_4 -> V_8 ) > 0 )
goto V_9;
}
V_5 = F_4 ( V_4 -> V_5 ) ;
V_5 &= ~ ( 3 << V_4 -> V_10 ) ;
F_5 ( V_5 , V_4 -> V_5 ) ;
V_9:
F_6 ( V_4 -> V_7 , V_6 ) ;
}
static int F_9 ( void T_2 * V_5 , T_3 V_10 )
{
T_1 V_12 = F_4 ( V_5 ) ;
if ( ( ( V_12 >> V_10 ) & 1 ) == 1 )
return 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return F_9 ( V_4 -> V_5 , V_4 -> V_10 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_6 = 0 ;
T_1 V_5 ;
F_3 ( V_4 -> V_7 , V_6 ) ;
if ( ! V_4 -> V_8 || * V_4 -> V_8 == 0 ) {
V_5 = F_4 ( V_4 -> V_5 ) ;
V_5 &= ~ ( 3 << V_4 -> V_10 ) ;
F_5 ( V_5 , V_4 -> V_5 ) ;
}
F_6 ( V_4 -> V_7 , V_6 ) ;
}
struct V_13 * F_12 ( struct V_14 * V_15 , const char * V_16 ,
const char * V_17 , unsigned long V_6 ,
void T_2 * V_5 , T_3 V_10 , T_3 V_11 ,
T_3 V_18 , T_4 * V_7 ,
unsigned int * V_8 )
{
struct V_3 * V_4 ;
struct V_13 * V_13 ;
struct V_19 V_20 ;
V_4 = F_13 ( sizeof( struct V_3 ) , V_21 ) ;
if ( ! V_4 )
return F_14 ( - V_22 ) ;
V_4 -> V_5 = V_5 ;
V_4 -> V_10 = V_10 ;
V_4 -> V_11 = V_11 ;
V_4 -> V_6 = V_18 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_8 = V_8 ;
V_20 . V_16 = V_16 ;
V_20 . V_23 = & V_24 ;
V_20 . V_6 = V_6 ;
V_20 . V_25 = V_17 ? & V_17 : NULL ;
V_20 . V_26 = V_17 ? 1 : 0 ;
V_4 -> V_2 . V_20 = & V_20 ;
V_13 = F_15 ( V_15 , & V_4 -> V_2 ) ;
if ( F_16 ( V_13 ) )
F_17 ( V_4 ) ;
return V_13 ;
}
