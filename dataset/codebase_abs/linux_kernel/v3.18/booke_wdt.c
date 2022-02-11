static unsigned long long F_1 ( unsigned int V_1 )
{
unsigned long long V_2 = 1ULL << ( 64 - V_1 ) ;
unsigned long V_3 = V_4 ;
V_3 = V_3 / 5 * 2 ;
F_2 ( V_2 , V_3 ) ;
return V_2 ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
unsigned int V_1 ;
for ( V_1 = 63 ; V_1 > 0 ; V_1 -- ) {
if ( F_1 ( V_1 ) >= V_5 )
return V_1 ;
}
return 0 ;
}
static unsigned long long F_1 ( unsigned int V_1 )
{
return V_1 ;
}
static unsigned int F_3 ( unsigned int V_5 )
{
return V_5 ;
}
static void F_4 ( void * V_6 )
{
T_1 V_7 ;
struct V_8 * V_9 = V_6 ;
V_7 = F_5 ( V_10 ) ;
V_7 &= ~ V_11 ;
V_7 |= F_6 ( F_3 ( V_9 -> V_12 ) ) ;
F_7 ( V_10 , V_7 ) ;
}
static void F_8 ( void * V_6 )
{
F_9 ( F_4 , V_6 , 0 ) ;
}
static void F_10 ( void * V_6 )
{
F_7 ( V_13 , V_14 | V_15 ) ;
}
static int F_11 ( struct V_8 * V_9 )
{
F_9 ( F_10 , NULL , 0 ) ;
return 0 ;
}
static void F_12 ( void * V_6 )
{
T_1 V_7 ;
struct V_8 * V_9 = V_6 ;
F_10 ( NULL ) ;
V_7 = F_5 ( V_10 ) ;
V_7 &= ~ V_11 ;
V_7 |= ( V_16 | F_13 ( V_17 ) | F_6 ( F_3 ( V_9 -> V_12 ) ) ) ;
F_7 ( V_10 , V_7 ) ;
}
static void F_14 ( void * V_6 )
{
T_1 V_7 ;
V_7 = F_5 ( V_10 ) ;
V_7 &= ~ ( V_16 | V_11 ) ;
F_7 ( V_10 , V_7 ) ;
F_10 ( NULL ) ;
}
static int F_15 ( struct V_8 * V_9 )
{
F_9 ( F_12 , V_9 , 0 ) ;
F_16 ( L_1 , V_9 -> V_12 ) ;
return 0 ;
}
static int F_17 ( struct V_8 * V_9 )
{
F_9 ( F_14 , NULL , 0 ) ;
F_16 ( L_2 ) ;
return 0 ;
}
static int F_18 ( struct V_8 * V_18 ,
unsigned int V_12 )
{
if ( V_12 > V_19 )
return - V_20 ;
V_18 -> V_12 = V_12 ;
F_8 ( V_18 ) ;
return 0 ;
}
static void T_2 F_19 ( void )
{
F_20 ( & V_21 ) ;
}
static int T_3 F_21 ( void )
{
int V_22 = 0 ;
bool V_23 = V_24 ;
F_22 ( L_3 ) ;
V_25 . V_26 = V_27 -> V_28 ;
F_18 ( & V_21 ,
F_1 ( V_29 ) ) ;
F_23 ( & V_21 , V_23 ) ;
if ( V_30 )
F_15 ( & V_21 ) ;
V_22 = F_24 ( & V_21 ) ;
return V_22 ;
}
