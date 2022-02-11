static int F_1 ( struct V_1 * V_2 )
{
if ( V_3 & V_4 )
return V_5 ;
else
return V_6 ;
}
static int F_2 ( struct V_1 * V_2 )
{
int V_7 ;
if ( F_1 ( V_2 ) != V_5 )
return 0 ;
F_3 () ;
if ( F_4 ( V_8 ) != V_9 ) {
F_5 ( V_10 L_1 ) ;
F_6 () ;
return - V_11 ;
} else {
V_7 = F_4 ( V_9 ) ;
F_6 () ;
return V_7 ;
}
}
static int F_7 ( struct V_1 * V_2 , int V_12 )
{
int V_7 ;
F_3 () ;
V_7 = F_4 ( V_13 ) ;
if ( F_4 ( V_12 ) != V_9 ) {
F_5 ( V_10 L_2 ) ;
F_6 () ;
return - V_11 ;
}
F_6 () ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , int V_14 )
{
if ( V_14 != V_5 ) {
V_3 &= ~ V_4 ;
V_15 |= V_4 ;
} else
V_3 |= V_4 ;
return 0 ;
}
static int F_9 ( struct V_16 * V_17 )
{
struct V_1 * V_1 ;
int V_7 ;
V_1 = F_10 ( V_18 , & V_17 -> V_2 , NULL , & V_19 ) ;
if ( F_11 ( V_1 ) ) {
V_7 = F_12 ( V_1 ) ;
F_5 ( V_10 L_3 ) ;
return V_7 ;
}
F_13 ( V_17 , V_1 ) ;
F_7 ( V_1 , V_20 ) ;
F_8 ( V_1 , V_5 ) ;
F_14 ( 100 ) ;
return 0 ;
}
static int F_15 ( struct V_16 * V_17 )
{
struct V_1 * V_1 = F_16 ( V_17 ) ;
F_17 ( V_1 ) ;
return 0 ;
}
