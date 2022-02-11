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
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= F_6 ( V_10 ) ;
F_7 ( V_8 , V_7 ) ;
}
static void F_8 ( void )
{
F_9 ( F_4 , NULL , 0 ) ;
}
static void F_10 ( void * V_6 )
{
F_7 ( V_11 , V_12 | V_13 ) ;
}
static int F_11 ( struct V_14 * V_15 )
{
F_9 ( F_10 , NULL , 0 ) ;
return 0 ;
}
static void F_12 ( void * V_6 )
{
T_1 V_7 ;
F_10 ( NULL ) ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ V_9 ;
V_7 |= ( V_16 | F_13 ( V_17 ) | F_6 ( V_10 ) ) ;
F_7 ( V_8 , V_7 ) ;
}
static void F_14 ( void * V_6 )
{
T_1 V_7 ;
V_7 = F_5 ( V_8 ) ;
V_7 &= ~ ( V_16 | V_9 ) ;
F_7 ( V_8 , V_7 ) ;
F_10 ( NULL ) ;
}
static void F_15 ( struct V_14 * V_15 )
{
F_9 ( F_12 , NULL , 0 ) ;
F_16 ( L_1 , V_15 -> V_18 ) ;
}
static int F_17 ( struct V_14 * V_15 )
{
if ( V_19 == 0 ) {
V_19 = 1 ;
F_15 ( V_15 ) ;
}
return 0 ;
}
static int F_18 ( struct V_14 * V_15 )
{
F_9 ( F_14 , NULL , 0 ) ;
V_19 = 0 ;
F_16 ( L_2 ) ;
return 0 ;
}
static int F_19 ( struct V_14 * V_20 ,
unsigned int V_18 )
{
if ( V_18 > V_21 )
return - V_22 ;
V_10 = F_3 ( V_18 ) ;
V_20 -> V_18 = V_18 ;
F_8 () ;
return 0 ;
}
static void T_2 F_20 ( void )
{
F_21 ( & V_23 ) ;
}
static int T_3 F_22 ( void )
{
int V_24 = 0 ;
bool V_25 = V_26 ;
F_23 ( L_3 ) ;
V_27 . V_28 = V_29 -> V_30 ;
F_19 ( & V_23 ,
F_1 ( V_31 ) ) ;
F_24 ( & V_23 , V_25 ) ;
if ( V_19 )
F_15 ( & V_23 ) ;
V_24 = F_25 ( & V_23 ) ;
return V_24 ;
}
