T_1 int T_2 F_1 ( char * V_1 )
{
if ( V_1 && strncmp ( V_1 , L_1 , 1 ) != 0 )
V_2 = 1 ;
return 0 ;
}
int T_2 F_2 ( char * V_1 )
{
unsigned long V_3 ;
if ( V_1 ) {
if ( ! F_3 ( V_1 , 0 , & V_3 ) )
V_4 = V_3 ;
}
return 0 ;
}
static unsigned long long F_4 ( unsigned int V_5 )
{
unsigned long long V_6 = 1ULL << ( 64 - V_5 ) ;
unsigned long V_7 = V_8 ;
V_7 = V_7 / 5 * 2 ;
F_5 ( V_6 , V_7 ) ;
return V_6 ;
}
static unsigned int F_6 ( unsigned int V_9 )
{
unsigned int V_5 ;
for ( V_5 = 63 ; V_5 > 0 ; V_5 -- ) {
if ( F_4 ( V_5 ) >= V_9 )
return V_5 ;
}
return 0 ;
}
static unsigned long long F_4 ( unsigned int V_5 )
{
return V_5 ;
}
static unsigned int F_6 ( unsigned int V_9 )
{
return V_9 ;
}
static void F_7 ( void * V_10 )
{
T_3 V_11 ;
struct V_12 * V_13 = V_10 ;
V_11 = F_8 ( V_14 ) ;
V_11 &= ~ V_15 ;
V_11 |= F_9 ( F_6 ( V_13 -> V_16 ) ) ;
F_10 ( V_14 , V_11 ) ;
}
static void F_11 ( void * V_10 )
{
F_12 ( F_7 , V_10 , 0 ) ;
}
static void F_13 ( void * V_10 )
{
F_10 ( V_17 , V_18 | V_19 ) ;
}
static int F_14 ( struct V_12 * V_13 )
{
F_12 ( F_13 , NULL , 0 ) ;
return 0 ;
}
static void F_15 ( void * V_10 )
{
T_3 V_11 ;
struct V_12 * V_13 = V_10 ;
F_13 ( NULL ) ;
V_11 = F_8 ( V_14 ) ;
V_11 &= ~ V_15 ;
V_11 |= ( V_20 | F_16 ( V_21 ) | F_9 ( F_6 ( V_13 -> V_16 ) ) ) ;
F_10 ( V_14 , V_11 ) ;
}
static void F_17 ( void * V_10 )
{
T_3 V_11 ;
V_11 = F_8 ( V_14 ) ;
V_11 &= ~ ( V_20 | V_15 ) ;
F_10 ( V_14 , V_11 ) ;
F_13 ( NULL ) ;
}
static int F_18 ( struct V_12 * V_13 )
{
F_12 ( F_15 , V_13 , 0 ) ;
F_19 ( L_2 , V_13 -> V_16 ) ;
return 0 ;
}
static int F_20 ( struct V_12 * V_13 )
{
F_12 ( F_17 , NULL , 0 ) ;
F_19 ( L_3 ) ;
return 0 ;
}
static int F_21 ( struct V_12 * V_22 ,
unsigned int V_16 )
{
if ( V_16 > V_23 )
return - V_24 ;
V_22 -> V_16 = V_16 ;
F_11 ( V_22 ) ;
return 0 ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_25 ) ;
}
static int T_2 F_24 ( void )
{
int V_3 = 0 ;
bool V_26 = V_27 ;
F_25 ( L_4 ) ;
V_28 . V_29 = V_30 -> V_31 ;
F_21 ( & V_25 ,
F_4 ( V_4 ) ) ;
F_26 ( & V_25 , V_26 ) ;
if ( V_2 )
F_18 ( & V_25 ) ;
V_3 = F_27 ( & V_25 ) ;
return V_3 ;
}
