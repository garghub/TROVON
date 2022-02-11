static void F_1 ( void )
{
unsigned long V_1 , V_2 ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( V_2 & ~ V_3 ) ;
F_5 () ;
F_6 () ;
F_4 ( V_2 ) ;
F_7 ( V_1 ) ;
}
static void F_8 ( unsigned long V_4 , unsigned long V_5 )
{
F_9 ( V_5 == 0 ) ;
F_10 () ;
F_11 ( V_4 , V_4 + V_5 ) ;
}
static inline void F_12 ( unsigned long V_4 )
{
if ( F_13 () != V_6 )
F_14 ( V_4 ) ;
}
static inline void F_15 ( unsigned long V_4 )
{
F_16 ( V_4 ) ;
}
static inline void F_17 ( void )
{
F_18 () ;
}
static inline void F_19 ( unsigned long V_4 )
{
unsigned long V_1 , V_2 ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( V_2 & ~ V_3 ) ;
F_5 () ;
F_20 ( V_4 ) ;
F_4 ( V_2 ) ;
F_7 ( V_1 ) ;
}
static inline void F_21 ( unsigned long V_4 )
{
unsigned long V_1 , V_2 ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( V_2 & ~ V_3 ) ;
F_5 () ;
F_22 ( V_4 ) ;
F_4 ( V_2 ) ;
F_7 ( V_1 ) ;
}
static inline void F_23 ( void )
{
unsigned long V_1 , V_2 ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( V_2 & ~ V_3 ) ;
F_5 () ;
F_6 () ;
F_4 ( V_2 ) ;
F_7 ( V_1 ) ;
}
static void F_24 ( void )
{
F_17 () ;
}
static void F_25 ( void )
{
F_17 () ;
}
static inline void F_26 ( void )
{
if ( ! V_7 )
return;
F_17 () ;
}
static inline void F_27 ( void )
{
F_17 () ;
F_23 () ;
}
static void F_28 ( struct V_8 * V_9 )
{
if ( ! V_7 )
return;
if ( F_29 ( F_30 () , V_9 ) != 0 )
F_17 () ;
}
static void F_31 ( struct V_10 * V_11 ,
unsigned long V_12 , unsigned long V_13 )
{
if ( ! V_7 )
return;
if ( ! ( F_29 ( F_30 () , V_11 -> V_14 ) ) )
return;
F_17 () ;
}
static void F_32 ( struct V_10 * V_11 , unsigned long V_15 , unsigned long V_16 )
{
int V_17 = V_11 -> V_18 & V_19 ;
struct V_8 * V_9 = V_11 -> V_14 ;
T_1 * V_20 ;
T_2 * V_21 ;
T_3 * V_22 ;
T_4 * V_23 ;
if ( F_29 ( F_30 () , V_9 ) == 0 )
return;
V_15 &= V_24 ;
V_20 = F_33 ( V_9 , V_15 ) ;
V_21 = F_34 ( V_20 , V_15 ) ;
V_22 = F_35 ( V_21 , V_15 ) ;
V_23 = F_36 ( V_22 , V_15 ) ;
if ( ! ( F_37 ( * V_23 ) & V_25 ) )
return;
if ( ( V_9 == V_26 -> V_27 ) && ( F_37 ( * V_23 ) & V_28 ) ) {
if ( V_7 || V_17 )
F_12 ( V_15 ) ;
if ( V_17 )
F_19 ( V_15 ) ;
return;
}
if ( V_7 || V_17 )
F_15 ( V_15 ) ;
if ( V_17 )
F_21 ( V_15 ) ;
}
static void F_38 ( void * V_4 )
{
F_12 ( ( unsigned long ) V_4 ) ;
}
static void F_39 ( unsigned long V_4 )
{
F_12 ( V_4 ) ;
}
static void F_40 ( unsigned long V_12 , unsigned long V_13 )
{
if ( V_13 - V_12 > V_29 )
F_17 () ;
else
F_41 ( V_12 , V_13 ) ;
if ( V_13 - V_12 > V_30 )
F_23 () ;
else {
unsigned long V_1 , V_2 ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( V_2 & ~ V_3 ) ;
F_5 () ;
F_42 ( V_12 , V_13 ) ;
F_4 ( V_2 ) ;
F_7 ( V_1 ) ;
}
}
static void F_43 ( unsigned long V_31 , int V_5 )
{
F_44 () ;
}
static void F_45 ( unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_13 ;
if ( ( ( V_5 | V_4 ) & ( V_32 - 1 ) ) == 0 ) {
V_13 = V_4 + V_5 ;
do {
F_12 ( V_4 ) ;
V_4 += V_32 ;
} while( V_4 != V_13 );
} else if ( V_5 > V_29 ) {
F_17 () ;
} else {
F_46 ( V_4 , V_4 + V_5 ) ;
}
}
static void F_47 ( unsigned long V_4 , unsigned long V_5 )
{
unsigned long V_13 ;
if ( ( ( V_5 | V_4 ) & ( V_32 - 1 ) ) == 0 ) {
V_13 = V_4 + V_5 ;
do {
F_12 ( V_4 ) ;
V_4 += V_32 ;
} while( V_4 != V_13 );
} else if ( V_5 > V_29 ) {
F_17 () ;
} else {
F_11 ( V_4 , V_4 + V_5 ) ;
}
}
static void F_48 ( unsigned long V_4 )
{
unsigned long V_33 = V_34 . V_35 . V_36 ;
unsigned long V_37 = V_34 . V_38 . V_36 ;
unsigned long V_2 ;
unsigned long V_1 ;
F_49 ( V_4 & ~ ( V_37 - 1 ) ) ;
F_2 ( V_1 ) ;
V_2 = F_3 () ;
F_4 ( V_2 & ~ V_3 ) ;
F_5 () ;
F_50 ( V_4 & ~ ( V_33 - 1 ) ) ;
F_4 ( V_2 ) ;
F_7 ( V_1 ) ;
}
static T_5 void F_51 ( void )
{
unsigned long V_2 ;
V_2 = F_3 () ;
V_30 = 1 << ( 10 + ( ( V_2 & V_39 ) >>
V_40 ) ) ;
V_29 = 1 << ( 10 + ( ( V_2 & V_41 ) >>
V_42 ) ) ;
V_34 . V_35 . V_36 = 16 ;
switch ( F_13 () ) {
case V_6 :
V_34 . V_35 . V_43 = 1 ;
V_34 . V_38 . V_43 = 1 ;
V_34 . V_38 . V_36 = 4 ;
break;
case V_44 :
V_34 . V_35 . V_43 = 2 ;
V_34 . V_38 . V_43 = 2 ;
V_34 . V_38 . V_36 = 16 ;
break;
case V_45 :
default:
V_34 . V_35 . V_43 = 1 ;
V_34 . V_38 . V_43 = 1 ;
V_34 . V_38 . V_36 = 16 ;
break;
}
}
void F_52 ( void )
{
extern void V_46 ( void ) ;
extern void V_47 ( void ) ;
unsigned long V_2 ;
V_2 = F_3 () ;
V_2 &= ~ V_48 ;
F_4 ( V_2 ) ;
F_51 () ;
switch ( F_13 () ) {
case V_6 :
V_49 = F_24 ;
V_50 = F_25 ;
V_51 = F_1 ;
V_52 = F_1 ;
V_53 = ( void * ) F_1 ;
V_54 = ( void * ) F_1 ;
V_55 = ( void * ) F_1 ;
V_56 = ( void * ) F_1 ;
V_57 = ( void * ) F_1 ;
V_58 = ( void * ) F_1 ;
V_59 = ( void * ) F_1 ;
V_60 = ( void * ) F_1 ;
V_61 = F_8 ;
V_62 = V_32 - 1 ;
break;
case V_45 :
case V_44 :
default:
V_49 = F_24 ;
V_50 = F_25 ;
V_51 = F_26 ;
V_52 = F_27 ;
V_53 = F_28 ;
V_54 = F_31 ;
V_55 = F_32 ;
V_56 = F_40 ;
V_57 = F_40 ;
V_63 = F_43 ;
V_58 = F_48 ;
V_59 = F_38 ;
V_60 = F_39 ;
V_61 = F_45 ;
V_64 = F_45 ;
V_65 = F_47 ;
V_62 = F_53 (unsigned long,
(dcache_size / current_cpu_data.dcache.ways) - 1 ,
PAGE_SIZE - 1 ) ;
break;
}
V_66 = V_56 ;
V_67 = V_57 ;
V_34 . V_35 . V_68 = V_30 / V_34 . V_35 . V_43 ;
V_34 . V_38 . V_68 = V_29 / V_34 . V_38 . V_43 ;
V_34 . V_35 . V_69 =
V_34 . V_35 . V_68 / V_34 . V_35 . V_36 ;
V_34 . V_38 . V_69 =
V_34 . V_38 . V_68 / V_34 . V_38 . V_36 ;
if ( V_34 . V_38 . V_68 > V_32 )
V_34 . V_38 . V_1 |= V_70 ;
V_34 . V_35 . V_71 = 0 ;
V_34 . V_38 . V_71 = 0 ;
F_54 ( L_1 ,
V_30 >> 10 , V_34 . V_35 . V_36 ) ;
F_54 ( L_2 ,
V_29 >> 10 , V_34 . V_38 . V_36 ) ;
V_46 () ;
V_47 () ;
F_1 () ;
}
