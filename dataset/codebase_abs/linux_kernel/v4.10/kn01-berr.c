static inline void F_1 ( void )
{
volatile T_1 * V_1 = ( void * ) F_2 ( V_2 + V_3 ) ;
unsigned long V_4 ;
F_3 ( & V_5 , V_4 ) ;
* V_1 = V_6 | V_7 ;
F_4 () ;
F_5 ( & V_5 , V_4 ) ;
}
static int F_6 ( struct V_8 * V_9 , int V_10 , int V_11 )
{
volatile T_2 * V_12 = ( void * ) F_2 ( V_2 +
V_13 ) ;
static const char V_14 [] = L_1 ;
static const char V_15 [] = L_2 ;
static const char V_16 [] = L_3 ;
static const char V_17 [] = L_4 ;
static const char V_18 [] = L_5 ;
static const char V_19 [] = L_6 ;
static const char V_20 [] = L_7 ;
static const char V_21 [] = L_8 ;
int V_22 = V_9 -> V_23 & 4 ;
unsigned int T_3 * V_24 = ( unsigned int T_3 * ) V_9 -> V_25 +
( ( V_9 -> V_23 & V_26 ) != 0 ) ;
union V_27 V_28 ;
unsigned long V_29 , V_30 ;
long V_31 , V_32 , V_33 ;
const char * V_34 , * V_35 , * V_36 , * V_37 ;
unsigned long V_38 ;
T_2 V_39 = * V_12 ;
int V_40 = V_41 ;
F_1 () ;
V_34 = V_11 ? V_15 : V_14 ;
V_35 = V_16 ;
if ( V_11 )
V_38 = V_39 ;
else {
if ( V_22 ) {
F_7 ( V_28 . V_42 , V_24 ) ;
V_33 = V_9 -> V_9 [ V_28 . V_43 . V_44 ] +
V_28 . V_43 . V_45 ;
} else
V_33 = ( long ) V_24 ;
if ( F_8 ( V_33 ) == V_46 || F_8 ( V_33 ) == V_47 )
V_38 = F_9 ( V_33 ) ;
else {
V_31 = F_10 () ;
V_32 = V_31 & ( V_48 - 1 ) ;
V_32 |= V_33 & ~ ( V_48 - 1 ) ;
F_11 ( V_32 ) ;
V_49 ;
F_12 () ;
F_13 () ;
V_29 = F_14 () ;
F_11 ( V_31 ) ;
V_30 = V_33 & ( V_48 - 1 ) ;
V_38 = ( V_29 & ~ ( V_48 - 1 ) ) | V_30 ;
}
}
if ( V_38 < 0x10000000 ) {
V_36 = V_17 ;
V_37 = V_21 ;
} else {
V_36 = V_11 ? V_19 : V_18 ;
V_37 = V_20 ;
}
if ( V_10 )
V_40 = V_50 ;
if ( V_40 != V_50 )
F_15 ( V_51 L_9 ,
V_34 , V_35 , V_36 , V_37 , V_38 ) ;
return V_40 ;
}
int F_16 ( struct V_8 * V_9 , int V_10 )
{
return F_6 ( V_9 , V_10 , 0 ) ;
}
T_4 F_17 ( int V_52 , void * V_53 )
{
volatile T_1 * V_1 = ( void * ) F_2 ( V_2 + V_3 ) ;
struct V_8 * V_9 = F_18 () ;
int V_40 ;
if ( ! ( * V_1 & V_7 ) )
return V_54 ;
V_40 = F_6 ( V_9 , 0 , 1 ) ;
if ( V_40 == V_55 )
return V_56 ;
F_15 ( V_51 L_10 ,
V_9 -> V_25 , V_9 -> V_9 [ 31 ] ) ;
F_19 ( L_11 , V_9 ) ;
}
void T_5 F_20 ( void )
{
volatile T_1 * V_1 = ( void * ) F_2 ( V_2 + V_3 ) ;
unsigned long V_4 ;
F_3 ( & V_5 , V_4 ) ;
V_6 = * V_1 ;
V_6 &= V_57 | V_58 | V_59 ;
V_6 |= V_60 ;
V_6 &= ~ V_58 ;
* V_1 = V_6 ;
F_4 () ;
F_5 ( & V_5 , V_4 ) ;
F_1 () ;
}
