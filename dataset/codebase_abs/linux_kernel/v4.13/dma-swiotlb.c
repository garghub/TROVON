static void * F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_2 * V_4 , T_3 V_5 , unsigned long V_6 )
{
void * V_7 ;
V_5 &= ~ ( V_8 | V_9 | V_10 ) ;
if ( ( F_2 ( V_11 ) && V_2 == NULL ) ||
( F_2 ( V_12 ) &&
V_2 -> V_13 < F_3 ( 32 ) ) )
V_5 |= V_8 ;
else if ( F_2 ( V_14 ) &&
V_2 -> V_13 < F_3 ( 40 ) )
V_5 |= V_9 ;
V_5 |= V_15 ;
V_7 = F_4 ( V_2 , V_3 , V_4 , V_5 ) ;
F_5 () ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 ,
void * V_16 , T_2 V_4 , unsigned long V_6 )
{
F_7 ( V_2 , V_3 , V_16 , V_4 ) ;
}
static T_2 F_8 ( struct V_1 * V_2 , struct V_17 * V_17 ,
unsigned long V_18 , T_1 V_3 ,
enum V_19 V_20 ,
unsigned long V_6 )
{
T_2 V_21 = F_9 ( V_2 , V_17 , V_18 , V_3 ,
V_20 , V_6 ) ;
F_5 () ;
return V_21 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_22 * V_23 ,
int V_24 , enum V_19 V_20 ,
unsigned long V_6 )
{
int V_25 = F_11 ( V_2 , V_23 , V_24 , V_20 , V_6 ) ;
F_5 () ;
return V_25 ;
}
static void F_12 ( struct V_1 * V_2 ,
T_2 V_4 , T_1 V_3 ,
enum V_19 V_20 )
{
F_13 ( V_2 , V_4 , V_3 , V_20 ) ;
F_5 () ;
}
static void F_14 ( struct V_1 * V_2 ,
struct V_22 * V_23 , int V_24 ,
enum V_19 V_20 )
{
F_15 ( V_2 , V_23 , V_24 , V_20 ) ;
F_5 () ;
}
static int F_16 ( struct V_1 * V_2 , T_4 V_26 )
{
if ( V_26 > F_3 ( V_27 . V_28 ) )
return 0 ;
return F_17 ( V_2 , V_26 ) ;
}
T_2 F_18 ( struct V_1 * V_2 , T_5 V_29 )
{
long V_30 ;
#ifdef F_19
V_30 = ( V_29 >> 44 ) & 0x3 ;
V_29 = ( ( V_30 << 44 ) ^ V_29 ) | ( V_30 << 37 ) ;
#endif
return V_29 ;
}
T_5 F_20 ( struct V_1 * V_2 , T_2 V_21 )
{
long V_30 ;
#ifdef F_19
V_30 = ( V_21 >> 37 ) & 0x3 ;
V_21 = ( ( V_30 << 37 ) ^ V_21 ) | ( V_30 << 44 ) ;
#endif
return V_21 ;
}
void T_6 F_21 ( void )
{
F_22 ( 1 ) ;
V_31 = & V_32 ;
}
