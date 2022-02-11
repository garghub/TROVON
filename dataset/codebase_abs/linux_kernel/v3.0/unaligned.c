static void
F_1 ( const char * V_1 , void * V_2 , T_1 V_3 )
{
unsigned char * V_4 = V_2 ;
int V_5 ;
F_2 ( L_1 , V_1 ) ;
for ( V_5 = 0 ; V_5 < V_3 ; ++ V_5 )
F_2 ( L_2 , * V_4 ++ ) ;
F_2 ( L_3 ) ;
}
static void
F_3 ( int V_6 )
{
# define F_4 ( T_2 ) case reg: ia64_invala_gr(reg); break
switch ( V_6 ) {
F_4 ( 0 ) ; F_4 ( 1 ) ; F_4 ( 2 ) ; F_4 ( 3 ) ; F_4 ( 4 ) ; F_4 ( 5 ) ; F_4 ( 6 ) ; F_4 ( 7 ) ;
F_4 ( 8 ) ; F_4 ( 9 ) ; F_4 ( 10 ) ; F_4 ( 11 ) ; F_4 ( 12 ) ; F_4 ( 13 ) ; F_4 ( 14 ) ; F_4 ( 15 ) ;
F_4 ( 16 ) ; F_4 ( 17 ) ; F_4 ( 18 ) ; F_4 ( 19 ) ; F_4 ( 20 ) ; F_4 ( 21 ) ; F_4 ( 22 ) ; F_4 ( 23 ) ;
F_4 ( 24 ) ; F_4 ( 25 ) ; F_4 ( 26 ) ; F_4 ( 27 ) ; F_4 ( 28 ) ; F_4 ( 29 ) ; F_4 ( 30 ) ; F_4 ( 31 ) ;
F_4 ( 32 ) ; F_4 ( 33 ) ; F_4 ( 34 ) ; F_4 ( 35 ) ; F_4 ( 36 ) ; F_4 ( 37 ) ; F_4 ( 38 ) ; F_4 ( 39 ) ;
F_4 ( 40 ) ; F_4 ( 41 ) ; F_4 ( 42 ) ; F_4 ( 43 ) ; F_4 ( 44 ) ; F_4 ( 45 ) ; F_4 ( 46 ) ; F_4 ( 47 ) ;
F_4 ( 48 ) ; F_4 ( 49 ) ; F_4 ( 50 ) ; F_4 ( 51 ) ; F_4 ( 52 ) ; F_4 ( 53 ) ; F_4 ( 54 ) ; F_4 ( 55 ) ;
F_4 ( 56 ) ; F_4 ( 57 ) ; F_4 ( 58 ) ; F_4 ( 59 ) ; F_4 ( 60 ) ; F_4 ( 61 ) ; F_4 ( 62 ) ; F_4 ( 63 ) ;
F_4 ( 64 ) ; F_4 ( 65 ) ; F_4 ( 66 ) ; F_4 ( 67 ) ; F_4 ( 68 ) ; F_4 ( 69 ) ; F_4 ( 70 ) ; F_4 ( 71 ) ;
F_4 ( 72 ) ; F_4 ( 73 ) ; F_4 ( 74 ) ; F_4 ( 75 ) ; F_4 ( 76 ) ; F_4 ( 77 ) ; F_4 ( 78 ) ; F_4 ( 79 ) ;
F_4 ( 80 ) ; F_4 ( 81 ) ; F_4 ( 82 ) ; F_4 ( 83 ) ; F_4 ( 84 ) ; F_4 ( 85 ) ; F_4 ( 86 ) ; F_4 ( 87 ) ;
F_4 ( 88 ) ; F_4 ( 89 ) ; F_4 ( 90 ) ; F_4 ( 91 ) ; F_4 ( 92 ) ; F_4 ( 93 ) ; F_4 ( 94 ) ; F_4 ( 95 ) ;
F_4 ( 96 ) ; F_4 ( 97 ) ; F_4 ( 98 ) ; F_4 ( 99 ) ; F_4 ( 100 ) ; F_4 ( 101 ) ; F_4 ( 102 ) ; F_4 ( 103 ) ;
F_4 ( 104 ) ; F_4 ( 105 ) ; F_4 ( 106 ) ; F_4 ( 107 ) ; F_4 ( 108 ) ; F_4 ( 109 ) ; F_4 ( 110 ) ; F_4 ( 111 ) ;
F_4 ( 112 ) ; F_4 ( 113 ) ; F_4 ( 114 ) ; F_4 ( 115 ) ; F_4 ( 116 ) ; F_4 ( 117 ) ; F_4 ( 118 ) ; F_4 ( 119 ) ;
F_4 ( 120 ) ; F_4 ( 121 ) ; F_4 ( 122 ) ; F_4 ( 123 ) ; F_4 ( 124 ) ; F_4 ( 125 ) ; F_4 ( 126 ) ; F_4 ( 127 ) ;
}
# undef F_4
}
static void
F_5 ( int V_6 )
{
# define F_4 ( T_2 ) case reg: ia64_invala_fr(reg); break
switch ( V_6 ) {
F_4 ( 0 ) ; F_4 ( 1 ) ; F_4 ( 2 ) ; F_4 ( 3 ) ; F_4 ( 4 ) ; F_4 ( 5 ) ; F_4 ( 6 ) ; F_4 ( 7 ) ;
F_4 ( 8 ) ; F_4 ( 9 ) ; F_4 ( 10 ) ; F_4 ( 11 ) ; F_4 ( 12 ) ; F_4 ( 13 ) ; F_4 ( 14 ) ; F_4 ( 15 ) ;
F_4 ( 16 ) ; F_4 ( 17 ) ; F_4 ( 18 ) ; F_4 ( 19 ) ; F_4 ( 20 ) ; F_4 ( 21 ) ; F_4 ( 22 ) ; F_4 ( 23 ) ;
F_4 ( 24 ) ; F_4 ( 25 ) ; F_4 ( 26 ) ; F_4 ( 27 ) ; F_4 ( 28 ) ; F_4 ( 29 ) ; F_4 ( 30 ) ; F_4 ( 31 ) ;
F_4 ( 32 ) ; F_4 ( 33 ) ; F_4 ( 34 ) ; F_4 ( 35 ) ; F_4 ( 36 ) ; F_4 ( 37 ) ; F_4 ( 38 ) ; F_4 ( 39 ) ;
F_4 ( 40 ) ; F_4 ( 41 ) ; F_4 ( 42 ) ; F_4 ( 43 ) ; F_4 ( 44 ) ; F_4 ( 45 ) ; F_4 ( 46 ) ; F_4 ( 47 ) ;
F_4 ( 48 ) ; F_4 ( 49 ) ; F_4 ( 50 ) ; F_4 ( 51 ) ; F_4 ( 52 ) ; F_4 ( 53 ) ; F_4 ( 54 ) ; F_4 ( 55 ) ;
F_4 ( 56 ) ; F_4 ( 57 ) ; F_4 ( 58 ) ; F_4 ( 59 ) ; F_4 ( 60 ) ; F_4 ( 61 ) ; F_4 ( 62 ) ; F_4 ( 63 ) ;
F_4 ( 64 ) ; F_4 ( 65 ) ; F_4 ( 66 ) ; F_4 ( 67 ) ; F_4 ( 68 ) ; F_4 ( 69 ) ; F_4 ( 70 ) ; F_4 ( 71 ) ;
F_4 ( 72 ) ; F_4 ( 73 ) ; F_4 ( 74 ) ; F_4 ( 75 ) ; F_4 ( 76 ) ; F_4 ( 77 ) ; F_4 ( 78 ) ; F_4 ( 79 ) ;
F_4 ( 80 ) ; F_4 ( 81 ) ; F_4 ( 82 ) ; F_4 ( 83 ) ; F_4 ( 84 ) ; F_4 ( 85 ) ; F_4 ( 86 ) ; F_4 ( 87 ) ;
F_4 ( 88 ) ; F_4 ( 89 ) ; F_4 ( 90 ) ; F_4 ( 91 ) ; F_4 ( 92 ) ; F_4 ( 93 ) ; F_4 ( 94 ) ; F_4 ( 95 ) ;
F_4 ( 96 ) ; F_4 ( 97 ) ; F_4 ( 98 ) ; F_4 ( 99 ) ; F_4 ( 100 ) ; F_4 ( 101 ) ; F_4 ( 102 ) ; F_4 ( 103 ) ;
F_4 ( 104 ) ; F_4 ( 105 ) ; F_4 ( 106 ) ; F_4 ( 107 ) ; F_4 ( 108 ) ; F_4 ( 109 ) ; F_4 ( 110 ) ; F_4 ( 111 ) ;
F_4 ( 112 ) ; F_4 ( 113 ) ; F_4 ( 114 ) ; F_4 ( 115 ) ; F_4 ( 116 ) ; F_4 ( 117 ) ; F_4 ( 118 ) ; F_4 ( 119 ) ;
F_4 ( 120 ) ; F_4 ( 121 ) ; F_4 ( 122 ) ; F_4 ( 123 ) ; F_4 ( 124 ) ; F_4 ( 125 ) ; F_4 ( 126 ) ; F_4 ( 127 ) ;
}
# undef F_4
}
static inline unsigned long
F_6 ( unsigned long V_7 , unsigned long V_8 , unsigned long T_2 )
{
T_2 += V_8 ;
if ( T_2 >= V_7 )
T_2 -= V_7 ;
return T_2 ;
}
static void
F_7 ( struct V_9 * V_10 , unsigned long V_11 , unsigned long V_12 , int V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_10 - 1 ;
unsigned long * V_16 , * V_17 , * V_18 , * V_19 , * V_20 ;
unsigned long * V_21 = ( void * ) V_22 + V_23 ;
unsigned long V_24 , V_25 ;
unsigned long V_26 ;
long V_27 = ( V_10 -> V_28 ) & 0x7f ;
long V_7 = 8 * ( ( V_10 -> V_28 >> 14 ) & 0xf ) ;
long V_29 = ( V_10 -> V_28 >> 18 ) & 0x7f ;
long V_30 = V_11 - 32 ;
if ( V_30 >= V_27 ) {
F_8 ( L_4 , V_11 , V_27 ) ;
return;
}
if ( V_30 < V_7 )
V_30 = F_6 ( V_7 , V_29 , V_30 ) ;
F_8 ( L_5 ,
V_11 , V_15 -> V_31 , V_10 -> V_31 , V_27 , ( V_10 -> V_28 >> 7 ) & 0x7f , V_30 ) ;
V_26 = F_9 ( V_21 , ( unsigned long * ) V_15 -> V_31 ) ;
V_18 = F_10 ( ( unsigned long * ) V_15 -> V_31 , - V_27 + V_30 ) ;
if ( V_18 >= V_21 ) {
V_19 = F_11 ( V_18 ) ;
if ( ( unsigned long ) V_19 >= V_15 -> V_31 )
V_19 = & V_15 -> V_32 ;
V_25 = 1UL << F_12 ( V_18 ) ;
* V_18 = V_12 ;
if ( V_13 )
* V_19 |= V_25 ;
else
* V_19 &= ~ V_25 ;
return;
}
if ( ! F_13 ( V_22 , V_10 ) ) {
F_8 ( L_6 , V_11 ) ;
return;
}
V_17 = ( unsigned long * ) V_10 -> V_31 ;
V_20 = F_10 ( V_17 , V_26 ) ;
V_16 = F_10 ( V_20 , - V_27 ) ;
V_18 = F_10 ( V_16 , V_30 ) ;
F_8 ( L_7 , ( void * ) V_20 , ( void * ) V_16 , ( void * ) V_18 ) ;
F_14 ( V_22 , V_15 , ( unsigned long ) V_20 , ( unsigned long ) V_18 , V_12 ) ;
V_19 = F_11 ( V_18 ) ;
F_15 ( V_22 , V_15 , ( unsigned long ) V_20 , ( unsigned long ) V_19 , & V_24 ) ;
F_8 ( L_8 ,
( void * ) V_19 , V_24 , V_13 , ( V_24 >> F_12 ( V_18 ) ) & 1 ) ;
V_25 = 1UL << F_12 ( V_18 ) ;
if ( V_13 )
V_24 |= V_25 ;
else
V_24 &= ~ V_25 ;
F_14 ( V_22 , V_15 , ( unsigned long ) V_20 , ( unsigned long ) V_19 , V_24 ) ;
F_8 ( L_9 , ( void * ) V_19 , V_24 ) ;
}
static void
F_16 ( struct V_9 * V_10 , unsigned long V_11 , unsigned long * V_12 , int * V_13 )
{
struct V_14 * V_15 = (struct V_14 * ) V_10 - 1 ;
unsigned long * V_16 , * V_18 , * V_19 , * V_20 , * V_17 ;
unsigned long * V_21 = ( void * ) V_22 + V_23 ;
unsigned long V_24 , V_25 ;
unsigned long V_26 ;
long V_27 = ( V_10 -> V_28 ) & 0x7f ;
long V_7 = 8 * ( ( V_10 -> V_28 >> 14 ) & 0xf ) ;
long V_29 = ( V_10 -> V_28 >> 18 ) & 0x7f ;
long V_30 = V_11 - 32 ;
if ( V_30 >= V_27 ) {
F_8 ( L_10 , V_11 , V_27 ) ;
goto V_33;
}
if ( V_30 < V_7 )
V_30 = F_6 ( V_7 , V_29 , V_30 ) ;
F_8 ( L_5 ,
V_11 , V_15 -> V_31 , V_10 -> V_31 , V_27 , ( V_10 -> V_28 >> 7 ) & 0x7f , V_30 ) ;
V_26 = F_9 ( V_21 , ( unsigned long * ) V_15 -> V_31 ) ;
V_18 = F_10 ( ( unsigned long * ) V_15 -> V_31 , - V_27 + V_30 ) ;
if ( V_18 >= V_21 ) {
* V_12 = * V_18 ;
if ( V_13 ) {
V_19 = F_11 ( V_18 ) ;
if ( ( unsigned long ) V_19 >= V_15 -> V_31 )
V_19 = & V_15 -> V_32 ;
V_25 = 1UL << F_12 ( V_18 ) ;
* V_13 = ( * V_19 & V_25 ) != 0 ;
}
return;
}
if ( ! F_13 ( V_22 , V_10 ) ) {
F_8 ( L_11 , V_11 ) ;
goto V_33;
}
V_17 = ( unsigned long * ) V_10 -> V_31 ;
V_20 = F_10 ( V_17 , V_26 ) ;
V_16 = F_10 ( V_20 , - V_27 ) ;
V_18 = F_10 ( V_16 , V_30 ) ;
F_8 ( L_7 , ( void * ) V_20 , ( void * ) V_16 , ( void * ) V_18 ) ;
F_15 ( V_22 , V_15 , ( unsigned long ) V_20 , ( unsigned long ) V_18 , V_12 ) ;
if ( V_13 ) {
V_19 = F_11 ( V_18 ) ;
V_25 = 1UL << F_12 ( V_18 ) ;
F_8 ( L_12 , ( void * ) V_19 , V_24 ) ;
F_15 ( V_22 , V_15 , ( unsigned long ) V_20 , ( unsigned long ) V_19 , & V_24 ) ;
* V_13 = ( V_24 & V_25 ) != 0 ;
}
return;
V_33:
* V_12 = 0 ;
if ( V_13 )
* V_13 = 0 ;
return;
}
static void
F_17 ( unsigned long V_34 , unsigned long V_12 , int V_13 , struct V_9 * V_10 )
{
struct V_14 * V_15 = (struct V_14 * ) V_10 - 1 ;
unsigned long V_18 ;
unsigned long V_35 ;
unsigned long * V_36 ;
if ( V_34 >= V_37 ) {
F_7 ( V_10 , V_34 , V_12 , V_13 ) ;
return;
}
if ( F_18 ( V_34 ) ) {
V_18 = ( unsigned long ) V_15 ;
V_36 = & V_15 -> V_38 ;
} else {
V_18 = ( unsigned long ) V_10 ;
V_36 = & V_15 -> V_39 ;
}
F_8 ( L_13 ,
V_18 , V_36 == & V_15 -> V_38 ? L_14 : L_15 , F_19 ( V_34 ) ) ;
V_18 += F_19 ( V_34 ) ;
* ( unsigned long * ) V_18 = V_12 ;
V_35 = 1UL << ( V_18 >> 3 & 0x3f ) ;
F_8 ( L_16 , V_18 , V_12 , V_13 , ( void * ) V_36 , * V_36 ) ;
if ( V_13 ) {
* V_36 |= V_35 ;
} else {
* V_36 &= ~ V_35 ;
}
F_8 ( L_17 , V_18 , V_12 , V_13 , ( void * ) V_36 , * V_36 ) ;
}
static inline unsigned long
F_20 ( struct V_9 * V_10 , long V_34 )
{
unsigned long V_40 = ( V_10 -> V_28 >> 25 ) & 0x7f ;
return F_6 ( 96 , V_40 , ( V_34 - V_41 ) ) ;
}
static void
F_21 ( unsigned long V_34 , struct V_42 * V_43 , struct V_9 * V_10 )
{
struct V_14 * V_15 = (struct V_14 * ) V_10 - 1 ;
unsigned long V_18 ;
if ( V_34 >= V_41 ) {
F_22 ( V_22 ) ;
V_22 -> V_44 . V_45 [ F_20 ( V_10 , V_34 ) ] = * V_43 ;
} else {
if ( F_23 ( V_34 ) ) {
V_18 = ( unsigned long ) V_15 ;
} else {
V_18 = ( unsigned long ) V_10 ;
}
F_8 ( L_18 , V_18 , F_24 ( V_34 ) ) ;
V_18 += F_24 ( V_34 ) ;
* (struct V_42 * ) V_18 = * V_43 ;
V_10 -> V_46 |= V_47 ;
}
}
static inline void
F_25 ( struct V_42 * V_48 )
{
F_26 ( V_48 , 0 ) ;
}
static inline void
F_27 ( struct V_42 * V_48 )
{
F_26 ( V_48 , 1 ) ;
}
static void
F_28 ( unsigned long V_34 , struct V_42 * V_43 , struct V_9 * V_10 )
{
struct V_14 * V_15 = (struct V_14 * ) V_10 - 1 ;
unsigned long V_18 ;
if ( V_34 >= V_41 ) {
F_29 ( V_22 ) ;
* V_43 = V_22 -> V_44 . V_45 [ F_20 ( V_10 , V_34 ) ] ;
} else {
switch( V_34 ) {
case 0 :
F_25 ( V_43 ) ;
break;
case 1 :
F_27 ( V_43 ) ;
break;
default:
V_18 = F_23 ( V_34 ) ? ( unsigned long ) V_15
: ( unsigned long ) V_10 ;
F_8 ( L_19 ,
F_23 ( V_34 ) , V_18 , F_24 ( V_34 ) ) ;
V_18 += F_24 ( V_34 ) ;
* V_43 = * (struct V_42 * ) V_18 ;
}
}
}
static void
F_30 ( unsigned long V_34 , unsigned long * V_12 , int * V_13 , struct V_9 * V_10 )
{
struct V_14 * V_15 = (struct V_14 * ) V_10 - 1 ;
unsigned long V_18 , * V_36 ;
if ( V_34 >= V_37 ) {
F_16 ( V_10 , V_34 , V_12 , V_13 ) ;
return;
}
if ( V_34 == 0 ) {
* V_12 = 0 ;
if ( V_13 )
* V_13 = 0 ;
return;
}
if ( F_18 ( V_34 ) ) {
V_18 = ( unsigned long ) V_15 ;
V_36 = & V_15 -> V_38 ;
} else {
V_18 = ( unsigned long ) V_10 ;
V_36 = & V_15 -> V_39 ;
}
F_8 ( L_20 , V_18 , F_19 ( V_34 ) ) ;
V_18 += F_19 ( V_34 ) ;
* V_12 = * ( unsigned long * ) V_18 ;
if ( V_13 )
* V_13 = ( * V_36 >> ( V_18 >> 3 & 0x3f ) ) & 0x1UL ;
}
static void
F_31 ( T_3 type , T_4 V_49 , struct V_9 * V_10 , unsigned long V_50 )
{
if ( V_49 . V_51 == 1 || V_49 . V_51 == 3 ) {
F_2 ( V_52 L_21 , V_53 ) ;
if ( F_32 ( L_22 ,
V_10 , 30 ) )
return;
}
if ( type == V_54 ) {
unsigned long V_55 ;
V_55 = V_49 . V_56 << 7 | V_49 . V_55 ;
if ( V_49 . V_57 ) V_55 |= V_58 ;
V_50 += V_55 ;
F_17 ( V_49 . V_59 , V_50 , 0 , V_10 ) ;
F_8 ( L_23 , V_49 . V_56 , V_49 . V_57 , V_55 , V_50 ) ;
} else if ( V_49 . V_57 ) {
unsigned long V_60 ;
int V_61 ;
F_30 ( V_49 . V_55 , & V_60 , & V_61 , V_10 ) ;
V_50 += V_60 ;
F_17 ( V_49 . V_59 , V_50 , V_61 , V_10 ) ;
F_8 ( L_24 , V_49 . V_55 , V_60 , V_50 , V_61 ) ;
}
}
static int
F_33 ( unsigned long V_50 , T_4 V_49 , struct V_9 * V_10 )
{
unsigned int V_3 = 1 << V_49 . V_62 ;
unsigned long V_12 = 0 ;
if ( V_3 != 2 && V_3 != 4 && V_3 != 8 ) {
F_8 ( L_25 , V_49 . V_62 ) ;
return - 1 ;
}
if ( F_34 ( & V_12 , ( void V_63 * ) V_50 , V_3 ) )
return - 1 ;
F_17 ( V_49 . V_11 , V_12 , 0 , V_10 ) ;
if ( V_49 . V_64 == 0x5 || V_49 . V_57 )
F_31 ( V_49 . V_64 == 0x5 ? V_54 : V_65 , V_49 , V_10 , V_50 ) ;
if ( V_49 . V_51 == 0x5 || V_49 . V_51 == 0xa )
F_35 () ;
if ( V_49 . V_51 == 0x2 )
F_3 ( V_49 . V_11 ) ;
return 0 ;
}
static int
F_36 ( unsigned long V_50 , T_4 V_49 , struct V_9 * V_10 )
{
unsigned long V_60 ;
unsigned int V_3 = 1 << V_49 . V_62 ;
F_30 ( V_49 . V_55 , & V_60 , NULL , V_10 ) ;
F_8 ( L_26 , V_3 , V_50 , V_60 ) ;
if ( V_3 != 2 && V_3 != 4 && V_3 != 8 ) {
F_8 ( L_25 , V_49 . V_62 ) ;
return - 1 ;
}
if ( F_37 ( ( void V_63 * ) V_50 , & V_60 , V_3 ) )
return - 1 ;
if ( V_49 . V_64 == 0x5 ) {
unsigned long V_55 ;
V_55 = V_49 . V_56 << 7 | V_49 . V_11 ;
if ( V_49 . V_57 ) V_55 |= V_58 ;
V_50 += V_55 ;
F_8 ( L_27 , V_55 , V_50 ) ;
F_17 ( V_49 . V_59 , V_50 , 0 , V_10 ) ;
}
F_38 () ;
if ( V_49 . V_51 == 0xd )
F_35 () ;
return 0 ;
}
static inline void
F_39 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_40 ( 6 , V_66 ) ;
F_41 () ;
F_26 ( V_48 , 6 ) ;
}
static inline void
F_42 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_43 ( 6 , V_66 ) ;
F_41 () ;
F_26 ( V_48 , 6 ) ;
}
static inline void
F_44 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_45 ( 6 , V_66 ) ;
F_41 () ;
F_26 ( V_48 , 6 ) ;
}
static inline void
F_46 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_47 ( 6 , V_66 ) ;
F_41 () ;
F_26 ( V_48 , 6 ) ;
}
static inline void
F_48 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_49 ( 6 , V_66 ) ;
F_41 () ;
F_50 ( V_48 , 6 ) ;
}
static inline void
F_51 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_49 ( 6 , V_66 ) ;
F_41 () ;
F_52 ( V_48 , 6 ) ;
}
static inline void
F_53 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_49 ( 6 , V_66 ) ;
F_41 () ;
F_54 ( V_48 , 6 ) ;
}
static inline void
F_55 ( struct V_42 * V_66 , struct V_42 * V_48 )
{
F_49 ( 6 , V_66 ) ;
F_41 () ;
F_56 ( V_48 , 6 ) ;
}
static int
F_57 ( unsigned long V_50 , T_4 V_49 , struct V_9 * V_10 )
{
struct V_42 V_67 [ 2 ] ;
struct V_42 V_68 [ 2 ] ;
unsigned long V_3 = V_69 [ V_49 . V_62 ] ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( V_49 . V_51 != 0x2 ) {
if ( F_34 ( & V_67 [ 0 ] , ( void V_63 * ) V_50 , V_3 )
|| F_34 ( & V_67 [ 1 ] , ( void V_63 * ) ( V_50 + V_3 ) , V_3 ) )
return - 1 ;
F_8 ( L_28 , V_49 . V_11 , V_49 . V_55 , V_49 . V_62 ) ;
F_58 ( L_29 , & V_67 , 2 * V_3 ) ;
switch( V_49 . V_62 ) {
case 0 :
F_39 ( & V_67 [ 0 ] , & V_68 [ 0 ] ) ;
F_39 ( & V_67 [ 1 ] , & V_68 [ 1 ] ) ;
break;
case 1 :
F_42 ( & V_67 [ 0 ] , & V_68 [ 0 ] ) ;
F_42 ( & V_67 [ 1 ] , & V_68 [ 1 ] ) ;
break;
case 2 :
F_44 ( & V_67 [ 0 ] , & V_68 [ 0 ] ) ;
F_44 ( & V_67 [ 1 ] , & V_68 [ 1 ] ) ;
break;
case 3 :
F_46 ( & V_67 [ 0 ] , & V_68 [ 0 ] ) ;
F_46 ( & V_67 [ 1 ] , & V_68 [ 1 ] ) ;
break;
}
F_58 ( L_30 , & V_68 , 2 * V_3 ) ;
F_21 ( V_49 . V_11 , & V_68 [ 0 ] , V_10 ) ;
F_21 ( V_49 . V_55 , & V_68 [ 1 ] , V_10 ) ;
}
if ( V_49 . V_57 ) {
V_50 += V_3 << 1 ;
if ( V_49 . V_51 == 1 || V_49 . V_51 == 3 )
F_2 ( V_52 L_31 ,
V_53 ) ;
F_17 ( V_49 . V_59 , V_50 , 0 , V_10 ) ;
}
if ( V_49 . V_51 == 0x2 ) {
F_5 ( V_49 . V_11 ) ;
F_5 ( V_49 . V_55 ) ;
}
return 0 ;
}
static int
F_59 ( unsigned long V_50 , T_4 V_49 , struct V_9 * V_10 )
{
struct V_42 V_67 ;
struct V_42 V_68 ;
unsigned long V_3 = V_69 [ V_49 . V_62 ] ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( V_49 . V_51 != 0x2 ) {
if ( F_34 ( & V_67 , ( void V_63 * ) V_50 , V_3 ) )
return - 1 ;
F_8 ( L_32 , V_49 . V_11 , V_49 . V_62 ) ;
F_58 ( L_33 , & V_67 , V_3 ) ;
switch( V_49 . V_62 ) {
case 0 :
F_39 ( & V_67 , & V_68 ) ;
break;
case 1 :
F_42 ( & V_67 , & V_68 ) ;
break;
case 2 :
F_44 ( & V_67 , & V_68 ) ;
break;
case 3 :
F_46 ( & V_67 , & V_68 ) ;
break;
}
F_58 ( L_30 , & V_68 , V_3 ) ;
F_21 ( V_49 . V_11 , & V_68 , V_10 ) ;
}
if ( V_49 . V_64 == 0x7 || V_49 . V_57 )
F_31 ( V_49 . V_64 == 0x7 ? V_54 : V_65 , V_49 , V_10 , V_50 ) ;
if ( V_49 . V_51 == 0x2 )
F_5 ( V_49 . V_11 ) ;
return 0 ;
}
static int
F_60 ( unsigned long V_50 , T_4 V_49 , struct V_9 * V_10 )
{
struct V_42 V_67 ;
struct V_42 V_68 ;
unsigned long V_3 = V_69 [ V_49 . V_62 ] ;
memset ( & V_67 , 0 , sizeof( V_67 ) ) ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
F_28 ( V_49 . V_55 , & V_67 , V_10 ) ;
switch( V_49 . V_62 ) {
case 0 :
F_48 ( & V_67 , & V_68 ) ;
break;
case 1 :
F_51 ( & V_67 , & V_68 ) ;
break;
case 2 :
F_53 ( & V_67 , & V_68 ) ;
break;
case 3 :
F_55 ( & V_67 , & V_68 ) ;
break;
}
F_8 ( L_32 , V_49 . V_11 , V_49 . V_62 ) ;
F_58 ( L_33 , & V_67 , V_3 ) ;
F_58 ( L_30 , & V_68 , V_3 ) ;
if ( F_37 ( ( void V_63 * ) V_50 , & V_68 , V_3 ) )
return - 1 ;
if ( V_49 . V_64 == 0x7 ) {
unsigned long V_55 ;
V_55 = V_49 . V_56 << 7 | V_49 . V_11 ;
if ( V_49 . V_57 )
V_55 |= V_58 ;
V_50 += V_55 ;
F_8 ( L_27 , V_55 , V_50 ) ;
F_17 ( V_49 . V_59 , V_50 , 0 , V_10 ) ;
}
F_38 () ;
return 0 ;
}
void
F_61 ( unsigned long V_50 , struct V_9 * V_10 )
{
struct V_70 * V_71 = V_70 ( V_10 ) ;
T_5 V_72 = F_62 () ;
unsigned long V_73 [ 2 ] ;
unsigned long V_74 ;
struct V_75 V_76 ;
const struct V_77 * V_78 = NULL ;
union {
unsigned long V_79 ;
T_4 V_80 ;
} V_81 ;
int V_82 = - 1 ;
if ( V_70 ( V_10 ) -> V_83 ) {
if ( F_32 ( L_34 , V_10 , 0 ) )
return;
goto V_84;
}
if ( ! F_63 ( V_10 ) )
V_78 = F_64 ( V_10 -> V_85 + V_70 ( V_10 ) -> V_86 ) ;
if ( F_63 ( V_10 ) || V_78 ) {
if ( ( V_22 -> V_44 . V_87 & V_88 ) != 0 )
goto V_84;
if ( ! V_89 &&
! ( V_22 -> V_44 . V_87 & V_90 ) &&
F_65 ( & V_91 ) )
{
char V_92 [ 200 ] ;
T_1 V_3 ;
V_3 = sprintf ( V_92 , L_35
L_36 , V_22 -> V_93 ,
F_66 ( V_22 ) ,
V_50 , V_10 -> V_85 + V_71 -> V_86 ) ;
if ( F_63 ( V_10 ) )
F_67 ( V_22 -> signal -> V_94 , V_92 ) ;
V_92 [ V_3 - 1 ] = '\0' ;
F_2 ( V_95 L_1 , V_92 ) ;
} else {
if ( V_89 ) {
F_68 ( V_95 L_37
L_38
L_39
L_40
L_41
L_42
L_43
L_44
L_45 ,
V_22 -> V_93 , F_66 ( V_22 ) ) ;
}
}
} else {
if ( F_65 ( & V_91 ) ) {
F_2 ( V_95 L_46 ,
V_50 , V_10 -> V_85 + V_71 -> V_86 ) ;
if ( V_96 )
F_69 () ;
}
F_70 ( V_97 ) ;
}
F_8 ( L_47 ,
V_10 -> V_85 , V_50 , V_10 -> V_46 , V_71 -> V_86 , V_71 -> V_98 ) ;
if ( F_71 ( V_73 , ( void V_63 * ) V_10 -> V_85 , 16 ) )
goto V_99;
switch ( V_71 -> V_86 ) {
case 0 : V_81 . V_79 = ( V_73 [ 0 ] >> 5 ) ; break;
case 1 : V_81 . V_79 = ( V_73 [ 0 ] >> 46 ) | ( V_73 [ 1 ] << 18 ) ; break;
case 2 : V_81 . V_79 = ( V_73 [ 1 ] >> 23 ) ; break;
}
V_74 = ( V_81 . V_79 >> V_100 ) & V_101 ;
F_8 ( L_48
L_49 , V_74 , V_81 . V_80 . V_102 , V_81 . V_80 . V_11 , V_81 . V_80 . V_55 ,
V_81 . V_80 . V_59 , V_81 . V_80 . V_56 , V_81 . V_80 . V_103 , V_81 . V_80 . V_62 , V_81 . V_80 . V_57 , V_81 . V_80 . V_64 ) ;
switch ( V_74 ) {
case V_104 :
case V_105 :
if ( V_81 . V_80 . V_56 )
goto V_99;
case V_106 :
case V_107 :
case V_108 :
case V_109 :
case V_110 :
F_8 ( L_50 ) ;
V_10 -> V_46 |= V_111 ;
goto V_112;
case V_113 :
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
if ( V_81 . V_80 . V_56 )
goto V_99;
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
V_82 = F_33 ( V_50 , V_81 . V_80 , V_10 ) ;
break;
case V_127 :
case V_128 :
if ( V_81 . V_80 . V_56 )
goto V_99;
case V_129 :
case V_130 :
V_82 = F_36 ( V_50 , V_81 . V_80 , V_10 ) ;
break;
case V_131 :
case V_132 :
case V_133 :
case V_134 :
if ( V_81 . V_80 . V_56 )
V_82 = F_57 ( V_50 , V_81 . V_80 , V_10 ) ;
else
V_82 = F_59 ( V_50 , V_81 . V_80 , V_10 ) ;
break;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
V_82 = F_59 ( V_50 , V_81 . V_80 , V_10 ) ;
break;
case V_139 :
case V_140 :
V_82 = F_60 ( V_50 , V_81 . V_80 , V_10 ) ;
break;
default:
goto V_99;
}
F_8 ( L_51 , V_82 ) ;
if ( V_82 )
goto V_99;
if ( V_71 -> V_86 == 2 )
V_10 -> V_85 += 16 ;
V_71 -> V_86 = ( V_71 -> V_86 + 1 ) & 0x3 ;
F_8 ( L_52 , V_71 -> V_86 , V_10 -> V_85 ) ;
V_112:
F_70 ( V_72 ) ;
return;
V_99:
if ( ! F_63 ( V_10 ) ) {
if ( V_78 ) {
F_72 ( V_10 , V_78 ) ;
goto V_112;
}
if ( F_32 ( L_53 , V_10 , V_82 ) )
return;
}
V_84:
V_76 . V_141 = V_142 ;
V_76 . V_143 = 0 ;
V_76 . V_144 = V_145 ;
V_76 . V_146 = ( void V_63 * ) V_50 ;
V_76 . V_147 = 0 ;
V_76 . V_148 = 0 ;
V_76 . V_149 = 0 ;
F_73 ( V_142 , & V_76 , V_22 ) ;
goto V_112;
}
