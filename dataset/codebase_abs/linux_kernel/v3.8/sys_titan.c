static void
F_1 ( unsigned long V_1 )
{
register T_1 * V_2 = V_3 ;
unsigned long V_4 = 1UL << 55 ;
register int V_5 = V_6 ;
#ifdef F_2
T_2 V_7 ;
volatile unsigned long * V_8 , * V_9 , * V_10 , * V_11 ;
unsigned long V_12 , V_13 , V_14 , V_15 , V_16 ;
F_3 ( & V_7 , V_17 ) ;
V_1 &= ~ V_4 ;
V_12 = V_1 & V_18 [ 0 ] ;
V_13 = V_1 & V_18 [ 1 ] ;
V_14 = V_1 & V_18 [ 2 ] ;
V_15 = V_1 & V_18 [ 3 ] ;
if ( V_5 == 0 ) V_12 |= V_4 ;
else if ( V_5 == 1 ) V_13 |= V_4 ;
else if ( V_5 == 2 ) V_14 |= V_4 ;
else V_15 |= V_4 ;
V_8 = & V_2 -> V_8 . V_19 ;
V_9 = & V_2 -> V_9 . V_19 ;
V_10 = & V_2 -> V_10 . V_19 ;
V_11 = & V_2 -> V_11 . V_19 ;
if ( ! F_4 ( 0 , & V_7 ) ) V_8 = & V_16 ;
if ( ! F_4 ( 1 , & V_7 ) ) V_9 = & V_16 ;
if ( ! F_4 ( 2 , & V_7 ) ) V_10 = & V_16 ;
if ( ! F_4 ( 3 , & V_7 ) ) V_11 = & V_16 ;
* V_8 = V_12 ;
* V_9 = V_13 ;
* V_10 = V_14 ;
* V_11 = V_15 ;
F_5 () ;
* V_8 ;
* V_9 ;
* V_10 ;
* V_11 ;
#else
volatile unsigned long * V_20 ;
V_20 = & V_2 -> V_8 . V_19 ;
if ( V_5 == 1 ) V_20 = & V_2 -> V_9 . V_19 ;
else if ( V_5 == 2 ) V_20 = & V_2 -> V_10 . V_19 ;
else if ( V_5 == 3 ) V_20 = & V_2 -> V_11 . V_19 ;
* V_20 = V_1 | V_4 ;
F_5 () ;
* V_20 ;
#endif
}
static inline void
F_6 ( struct V_21 * V_22 )
{
unsigned int V_23 = V_22 -> V_23 ;
F_7 ( & V_24 ) ;
V_25 |= 1UL << ( V_23 - 16 ) ;
F_1 ( V_25 ) ;
F_8 ( & V_24 ) ;
}
static inline void
F_9 ( struct V_21 * V_22 )
{
unsigned int V_23 = V_22 -> V_23 ;
F_7 ( & V_24 ) ;
V_25 &= ~ ( 1UL << ( V_23 - 16 ) ) ;
F_1 ( V_25 ) ;
F_8 ( & V_24 ) ;
}
static void
F_10 ( unsigned int V_23 , T_2 V_26 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < 4 ; V_27 ++ ) {
if ( F_4 ( V_27 , & V_26 ) )
V_18 [ V_27 ] |= 1UL << V_23 ;
else
V_18 [ V_27 ] &= ~ ( 1UL << V_23 ) ;
}
}
static int
F_11 ( struct V_21 * V_22 , const struct V_28 * V_26 ,
bool V_29 )
{
unsigned int V_23 = V_22 -> V_23 ;
F_7 ( & V_24 ) ;
F_10 ( V_23 - 16 , * V_26 ) ;
F_1 ( V_25 ) ;
F_8 ( & V_24 ) ;
return 0 ;
}
static void
F_12 ( unsigned long V_30 )
{
F_13 ( L_1 ) ;
}
static void
F_14 ( unsigned long V_30 )
{
int V_23 ;
V_23 = ( V_30 - 0x800 ) >> 4 ;
F_15 ( V_23 ) ;
}
static void T_3
F_16 ( struct V_31 * V_32 , int V_33 , int V_34 )
{
long V_35 ;
for ( V_35 = V_33 ; V_35 <= V_34 ; ++ V_35 ) {
F_17 ( V_35 , V_32 , V_36 ) ;
F_18 ( V_35 , V_37 ) ;
}
}
static T_4
F_19 ( int V_23 , void * V_38 )
{
return V_39 ;
}
static void T_3
F_20 ( void )
{
if ( V_40 && ! V_41 . V_42 )
V_41 . V_42 = F_14 ;
if ( ! V_41 . V_42 )
V_41 . V_42 = F_12 ;
F_1 ( 0 ) ;
F_16 ( & V_43 , 16 , 63 + 16 ) ;
}
static void T_3
F_21 ( void )
{
F_22 ( 0 , V_44 ) ;
F_22 ( 0 , V_45 ) ;
F_22 ( V_46 , V_47 ) ;
F_22 ( 0 , V_48 ) ;
F_23 () ;
F_20 () ;
}
void
F_24 ( T_5 V_1 )
{
unsigned long V_30 ;
V_1 &= V_18 [ F_25 () ] ;
while ( V_1 ) {
V_30 = 63 - F_26 ( V_1 ) ;
V_1 &= ~ ( 1UL << V_30 ) ;
V_30 = 0x900 + ( V_30 << 4 ) ;
V_41 . V_42 ( V_30 ) ;
}
}
static void T_3
F_27 ( unsigned int V_23 , T_6 V_49 ,
unsigned long V_50 , const char * V_51 ,
void * V_38 )
{
int V_52 ;
V_52 = F_28 ( V_23 , V_49 , V_50 , V_51 , V_38 ) ;
if ( V_52 ) {
F_13 ( L_2 ,
V_23 , V_52 ) ;
}
}
static void T_3
F_29 ( void )
{
F_27 ( 63 + 16 , F_19 , V_53 ,
L_3 , NULL ) ;
F_27 ( 62 + 16 , F_19 , V_53 ,
L_4 , NULL ) ;
F_27 ( 61 + 16 , F_19 , V_53 ,
L_5 , NULL ) ;
F_27 ( 60 + 16 , F_19 , V_53 ,
L_6 , NULL ) ;
F_27 ( 59 + 16 , F_19 , V_53 ,
L_7 , NULL ) ;
F_30 () ;
F_31 () ;
}
static int
F_32 ( const struct V_54 * V_55 , T_7 V_56 , T_7 V_57 )
{
T_7 V_58 ;
int V_23 ;
F_33 ( V_55 , V_59 , & V_58 ) ;
V_23 = V_58 ;
if ( ( V_23 & 0xF0 ) == 0xE0 )
return V_23 ;
return V_23 + 16 ;
}
static void T_3
F_34 ( void )
{
F_29 () ;
F_35 ( V_60 ) ;
F_36 () ;
F_37 ( 0 ) ;
F_38 ( NULL ) ;
}
static void T_3
F_39 ( void )
{
F_27 ( 53 + 16 , F_19 , V_53 ,
L_8 , NULL ) ;
F_27 ( 50 + 16 , F_19 , V_53 ,
L_9 , NULL ) ;
return F_34 () ;
}
