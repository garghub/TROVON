static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 , struct V_6 * V_7 )
{
void * V_8 ;
if ( F_2 ( V_2 , V_3 , V_4 , & V_8 ) )
return V_8 ;
V_5 &= ~ ( V_9 | V_10 | V_11 ) ;
#ifdef F_3
if ( V_2 == NULL )
V_5 |= V_9 ;
else
#endif
#ifdef F_4
if ( V_2 -> V_12 < F_5 ( 32 ) )
V_5 |= V_9 ;
else
#endif
#ifdef F_6
if ( V_2 -> V_12 < F_5 ( 40 ) )
V_5 |= V_10 ;
else
#endif
;
V_5 |= V_13 ;
V_8 = F_7 ( V_2 , V_3 , V_4 , V_5 ) ;
F_8 () ;
return V_8 ;
}
static void F_9 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_14 , T_2 V_4 , struct V_6 * V_7 )
{
int V_15 = F_10 ( V_3 ) ;
if ( F_11 ( V_2 , V_15 , V_14 ) )
return;
F_12 ( V_2 , V_3 , V_14 , V_4 ) ;
}
static T_2 F_13 ( struct V_1 * V_2 , struct V_16 * V_16 ,
unsigned long V_17 , T_1 V_3 ,
enum V_18 V_19 ,
struct V_6 * V_7 )
{
T_2 V_20 = F_14 ( V_2 , V_16 , V_17 , V_3 ,
V_19 , V_7 ) ;
F_8 () ;
return V_20 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_21 * V_22 ,
int V_23 , enum V_18 V_19 ,
struct V_6 * V_7 )
{
int V_24 = F_16 ( V_2 , V_22 , V_23 , V_19 , NULL ) ;
F_8 () ;
return V_24 ;
}
static void F_17 ( struct V_1 * V_2 ,
T_2 V_4 , T_1 V_3 ,
enum V_18 V_19 )
{
F_18 ( V_2 , V_4 , V_3 , V_19 ) ;
F_8 () ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_21 * V_22 , int V_23 ,
enum V_18 V_19 )
{
F_20 ( V_2 , V_22 , V_23 , V_19 ) ;
F_8 () ;
}
static int F_21 ( struct V_1 * V_2 , T_4 V_25 )
{
if ( V_25 > F_5 ( V_26 . V_27 ) ) {
* V_2 -> V_28 = F_5 ( V_26 . V_27 ) ;
return - V_29 ;
}
* V_2 -> V_28 = V_25 ;
return 0 ;
}
T_2 F_22 ( struct V_1 * V_2 , T_5 V_30 )
{
long V_31 ;
#ifdef F_23
V_31 = ( V_30 >> 44 ) & 0x3 ;
V_30 = ( ( V_31 << 44 ) ^ V_30 ) | ( V_31 << 37 ) ;
#endif
return V_30 ;
}
T_5 F_24 ( struct V_1 * V_2 , T_2 V_20 )
{
long V_31 ;
#ifdef F_23
V_31 = ( V_20 >> 37 ) & 0x3 ;
V_20 = ( ( V_31 << 37 ) ^ V_20 ) | ( V_31 << 44 ) ;
#endif
return V_20 ;
}
void T_6 F_25 ( void )
{
F_26 ( 1 ) ;
V_32 = & V_33 ;
}
