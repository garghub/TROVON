static void F_1 ( unsigned V_1 )
{
F_2 ( V_2 L_1 , V_1 ) ;
}
static void F_3 ( unsigned short V_3 , const char * V_4 )
{
if ( V_4 ) {
strncpy ( V_5 [ V_3 ] . V_6 , V_4 ,
V_7 ) ;
V_5 [ V_3 ] . V_6 [ V_7 - 1 ] = 0 ;
}
}
static char * F_4 ( unsigned short V_3 )
{
return ( * V_5 [ V_3 ] . V_6 ? V_5 [ V_3 ] . V_6 : L_2 ) ;
}
static int F_5 ( unsigned short V_3 , const char * V_4 )
{
if ( V_4 == NULL ) {
F_6 () ;
F_2 ( V_2 L_3 ) ;
}
if ( V_4 )
return strcmp ( V_5 [ V_3 ] . V_6 , V_4 ) ;
else
return - V_8 ;
}
inline int F_7 ( unsigned V_1 )
{
#if F_8 ( V_9 )
if ( V_1 == V_10 || V_1 == V_11 || V_1 == V_12
|| V_1 == V_13 || V_1 == V_14
|| V_1 == V_15 || V_1 == V_16 )
return - V_8 ;
#endif
if ( V_1 >= V_17 )
return - V_8 ;
return 0 ;
}
static void F_9 ( unsigned V_1 , unsigned short V_18 )
{
#if F_8 ( V_19 )
if ( V_1 < V_17 || V_1 >= V_20 )
return;
V_1 -= V_17 ;
if ( V_18 == V_21 )
* V_22 [ F_10 ( V_1 ) ] |= F_11 ( V_1 ) ;
else
* V_22 [ F_10 ( V_1 ) ] &= ~ F_11 ( V_1 ) ;
F_12 () ;
return;
#endif
if ( F_7 ( V_1 ) )
return;
#if F_8 ( V_23 ) || F_8 ( V_24 ) || F_8 ( V_25 )
if ( V_18 == V_21 )
* V_22 [ F_10 ( V_1 ) ] &= ~ F_11 ( V_1 ) ;
else
* V_22 [ F_10 ( V_1 ) ] |= F_11 ( V_1 ) ;
F_12 () ;
#elif F_8 ( V_9 ) || F_8 ( V_26 )
if ( V_18 == V_21 )
V_27 [ F_10 ( V_1 ) ] -> V_22 &= ~ F_11 ( V_1 ) ;
else
V_27 [ F_10 ( V_1 ) ] -> V_22 |= F_11 ( V_1 ) ;
F_12 () ;
#endif
}
static int F_13 ( unsigned short V_28 )
{
T_1 V_3 = F_14 ( V_28 ) ;
T_1 V_29 = F_15 ( V_28 ) ;
T_2 V_30 = V_31 [ V_3 ] ;
T_1 V_32 , V_33 , V_34 ;
if ( V_30 < 0 )
return 0 ;
V_33 = F_16 () ;
for ( V_32 = 0 ; V_32 < F_17 ( V_31 ) ; ++ V_32 ) {
if ( V_32 == V_3 )
continue;
if ( V_31 [ V_32 ] != V_30 )
continue;
if ( ! F_18 ( V_35 , V_32 , 1 ) )
continue;
if ( V_30 == 1 )
V_34 = ( V_33 >> V_30 ) & 3 ;
else
V_34 = ( V_33 >> V_30 ) & 1 ;
if ( V_34 != V_29 ) {
F_19 ( L_4 ,
V_3 , V_29 , V_32 , V_34 ) ;
return - V_8 ;
}
}
return 0 ;
}
static void F_20 ( unsigned short V_28 )
{
T_1 V_3 = F_14 ( V_28 ) ;
T_1 V_29 = F_15 ( V_28 ) ;
T_2 V_30 = V_31 [ V_3 ] ;
T_1 V_33 ;
if ( V_30 == - 1 )
return;
V_33 = F_16 () ;
if ( V_30 != 1 )
V_33 &= ~ ( 1 << V_30 ) ;
else
V_33 &= ~ ( 3 << 1 ) ;
V_33 |= ( V_29 << V_30 ) ;
F_21 ( V_33 ) ;
}
inline void F_20 ( unsigned short V_28 )
{
T_1 V_3 = F_14 ( V_28 ) ;
T_1 V_29 = F_15 ( V_28 ) ;
T_3 V_33 ;
V_33 = V_27 [ F_10 ( V_3 ) ] -> V_31 ;
V_33 &= ~ ( 0x3 << ( 2 * F_22 ( V_3 ) ) ) ;
V_33 |= ( V_29 & 0x3 ) << ( 2 * F_22 ( V_3 ) ) ;
V_27 [ F_10 ( V_3 ) ] -> V_31 = V_33 ;
}
inline T_1 F_23 ( unsigned short V_28 )
{
T_1 V_3 = F_14 ( V_28 ) ;
T_3 V_33 = V_27 [ F_10 ( V_3 ) ] -> V_31 ;
return ( V_33 >> ( 2 * F_22 ( V_3 ) ) & 0x3 ) ;
}
static int F_13 ( unsigned short V_28 )
{
return 0 ;
}
static int F_13 ( unsigned short V_28 )
{
T_1 V_3 = F_14 ( V_28 ) ;
T_1 V_29 = F_15 ( V_28 ) ;
T_4 V_30 = V_36 [ F_10 ( V_3 ) ] [ F_22 ( V_3 ) ] ;
T_1 V_37 , V_38 , V_34 ;
for ( V_37 = 0 ; V_37 < V_39 ; ++ V_37 ) {
if ( V_30 != V_36 [ F_10 ( V_3 ) ] [ V_37 ] )
continue;
V_38 = F_10 ( V_3 ) * V_39 + V_37 ;
if ( V_38 == V_3 )
continue;
if ( ! F_18 ( V_35 , V_38 , 1 ) )
continue;
V_34 = * V_31 [ F_10 ( V_3 ) ] ;
V_34 = ( V_34 >> V_30 ) & 3 ;
if ( V_34 != V_29 ) {
F_19 ( L_4 ,
V_3 , V_29 , V_38 , V_34 ) ;
return - V_8 ;
}
}
return 0 ;
}
inline void F_20 ( unsigned short V_28 )
{
T_1 V_3 = F_14 ( V_28 ) ;
T_1 V_29 = F_15 ( V_28 ) ;
T_4 V_30 = V_36 [ F_10 ( V_3 ) ] [ F_22 ( V_3 ) ] ;
T_1 V_33 ;
V_33 = * V_31 [ F_10 ( V_3 ) ] ;
if ( ( ( V_33 >> V_30 ) & 3 ) == V_29 )
return;
V_33 &= ~ ( 3 << V_30 ) ;
V_33 |= ( V_29 & 3 ) << V_30 ;
* V_31 [ F_10 ( V_3 ) ] = V_33 ;
F_12 () ;
}
static int F_13 ( unsigned short V_28 )
{
return 0 ;
}
void F_24 ( unsigned V_1 )
{
unsigned long V_40 ;
if ( V_41 || V_42 )
V_40 = F_25 () ;
V_27 [ F_10 ( V_1 ) ] -> V_43 = F_11 ( V_1 ) ;
if ( V_41 || V_42 ) {
F_26 ( V_43 ) ;
F_27 ( V_40 ) ;
}
}
int F_28 ( unsigned V_1 , unsigned V_44 )
{
unsigned long V_40 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_40 = F_25 () ;
if ( V_44 )
F_29 ( V_45 , V_1 ) ;
else
F_30 ( V_45 , V_1 ) ;
F_31 ( V_1 , V_44 ) ;
F_27 ( V_40 ) ;
return 0 ;
}
int F_32 ( unsigned V_44 )
{
T_1 V_46 , V_47 , V_48 ;
for ( V_48 = 0 ; V_48 < V_17 ; V_48 += V_39 ) {
V_47 = F_33 ( V_45 , V_48 ) ;
V_46 = F_10 ( V_48 ) ;
if ( V_47 )
F_34 ( V_49 [ V_46 ] , V_44 ) ;
}
return 0 ;
}
void F_35 ( void )
{
int V_48 , V_46 ;
#ifdef V_19
for ( V_48 = 0 ; V_48 < F_17 ( V_50 ) ; ++ V_48 )
V_50 [ V_48 ] = * V_22 [ V_48 ] ;
#endif
for ( V_48 = 0 ; V_48 < V_17 ; V_48 += V_39 ) {
V_46 = F_10 ( V_48 ) ;
#if F_8 ( V_23 ) || F_8 ( V_24 ) || F_8 ( V_25 )
V_51 [ V_46 ] . V_52 = * V_22 [ V_46 ] ;
#if F_8 ( V_23 ) || F_8 ( V_25 )
V_51 [ V_46 ] . V_53 = * V_31 [ V_46 ] ;
#else
if ( V_46 == 0 )
V_51 [ V_46 ] . V_53 = F_16 () ;
#endif
#endif
V_51 [ V_46 ] . V_54 = V_27 [ V_46 ] -> V_54 ;
V_51 [ V_46 ] . V_55 = V_27 [ V_46 ] -> V_55 ;
V_51 [ V_46 ] . V_56 = V_27 [ V_46 ] -> V_56 ;
V_51 [ V_46 ] . V_57 = V_27 [ V_46 ] -> V_57 ;
V_51 [ V_46 ] . V_58 = V_27 [ V_46 ] -> V_58 ;
V_51 [ V_46 ] . V_59 = V_27 [ V_46 ] -> V_59 ;
V_51 [ V_46 ] . V_60 = V_27 [ V_46 ] -> V_60 ;
}
#ifdef F_36
F_37 () ;
#endif
F_26 ( V_60 ) ;
}
void F_38 ( void )
{
int V_48 , V_46 ;
#ifdef V_19
for ( V_48 = 0 ; V_48 < F_17 ( V_50 ) ; ++ V_48 )
* V_22 [ V_48 ] = V_50 [ V_48 ] ;
#endif
for ( V_48 = 0 ; V_48 < V_17 ; V_48 += V_39 ) {
V_46 = F_10 ( V_48 ) ;
#if F_8 ( V_23 ) || F_8 ( V_24 ) || F_8 ( V_25 )
#if F_8 ( V_23 ) || F_8 ( V_25 )
* V_31 [ V_46 ] = V_51 [ V_46 ] . V_53 ;
#else
if ( V_46 == 0 )
F_21 ( V_51 [ V_46 ] . V_53 ) ;
#endif
* V_22 [ V_46 ] = V_51 [ V_46 ] . V_52 ;
#endif
V_27 [ V_46 ] -> V_55 = V_51 [ V_46 ] . V_55 ;
V_27 [ V_46 ] -> V_61 = V_51 [ V_46 ] . V_54
& V_51 [ V_46 ] . V_57 ;
V_27 [ V_46 ] -> V_57 = V_51 [ V_46 ] . V_57 ;
V_27 [ V_46 ] -> V_56 = V_51 [ V_46 ] . V_56 ;
V_27 [ V_46 ] -> V_58 = V_51 [ V_46 ] . V_58 ;
V_27 [ V_46 ] -> V_59 = V_51 [ V_46 ] . V_59 ;
V_27 [ V_46 ] -> V_60 = V_51 [ V_46 ] . V_60 ;
}
#ifdef F_36
F_39 () ;
#endif
F_26 ( V_60 ) ;
}
int F_32 ( unsigned V_44 )
{
return 0 ;
}
void F_35 ( void )
{
int V_48 , V_46 ;
for ( V_48 = 0 ; V_48 < V_17 ; V_48 += V_39 ) {
V_46 = F_10 ( V_48 ) ;
V_51 [ V_46 ] . V_52 = V_27 [ V_46 ] -> V_22 ;
V_51 [ V_46 ] . V_53 = V_27 [ V_46 ] -> V_31 ;
V_51 [ V_46 ] . V_54 = V_27 [ V_46 ] -> V_54 ;
V_51 [ V_46 ] . V_55 = V_27 [ V_46 ] -> V_55 ;
V_51 [ V_46 ] . V_57 = V_27 [ V_46 ] -> V_62 ;
}
}
void F_38 ( void )
{
int V_48 , V_46 ;
for ( V_48 = 0 ; V_48 < V_17 ; V_48 += V_39 ) {
V_46 = F_10 ( V_48 ) ;
V_27 [ V_46 ] -> V_31 = V_51 [ V_46 ] . V_53 ;
V_27 [ V_46 ] -> V_22 = V_51 [ V_46 ] . V_52 ;
V_27 [ V_46 ] -> V_55 = V_51 [ V_46 ] . V_55 ;
V_27 [ V_46 ] -> V_61 = V_51 [ V_46 ] . V_54
& V_51 [ V_46 ] . V_57 ;
V_27 [ V_46 ] -> V_62 = V_51 [ V_46 ] . V_57 ;
}
}
unsigned short F_40 ( unsigned V_1 )
{
return ( 0x01 & ( V_27 [ F_10 ( V_1 ) ] -> V_63 >> F_22 ( V_1 ) ) ) ;
}
int F_41 ( const unsigned short V_28 [] , const char * V_4 )
{
T_1 V_64 ;
int V_65 ;
for ( V_64 = 0 ; V_28 [ V_64 ] != 0 ; V_64 ++ ) {
V_65 = F_42 ( V_28 [ V_64 ] , V_4 ) ;
if ( V_65 < 0 ) {
for ( ; V_64 > 0 ; V_64 -- )
F_43 ( V_28 [ V_64 - 1 ] ) ;
return V_65 ;
}
}
return 0 ;
}
void F_43 ( unsigned short V_28 )
{
unsigned long V_40 ;
unsigned short V_3 = F_14 ( V_28 ) ;
if ( V_28 & V_66 )
return;
if ( ! ( V_28 & V_67 ) )
return;
V_40 = F_25 () ;
if ( F_44 ( ! F_18 ( V_35 , V_3 , 0 ) ) ) {
F_27 ( V_40 ) ;
return;
}
if ( ! ( V_28 & V_68 ) )
F_9 ( V_3 , V_21 ) ;
F_30 ( V_35 , V_3 ) ;
F_3 ( V_3 , L_5 ) ;
F_27 ( V_40 ) ;
}
void F_45 ( const unsigned short V_28 [] )
{
T_1 V_64 ;
for ( V_64 = 0 ; V_28 [ V_64 ] != 0 ; V_64 ++ )
F_43 ( V_28 [ V_64 ] ) ;
}
int F_46 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_40 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_40 = F_25 () ;
if ( F_5 ( V_1 , V_4 ) == 0 ) {
F_27 ( V_40 ) ;
return 0 ;
}
if ( F_44 ( F_18 ( V_1 , V_1 , 1 ) ) ) {
if ( V_69 == V_70 )
F_6 () ;
F_2 ( V_2 L_6 ,
V_1 , F_4 ( V_1 ) ) ;
F_27 ( V_40 ) ;
return - V_71 ;
}
if ( F_44 ( F_18 ( V_35 , V_1 , 1 ) ) ) {
if ( V_69 == V_70 )
F_6 () ;
F_2 ( V_2
L_7 ,
V_1 , F_4 ( V_1 ) ) ;
F_27 ( V_40 ) ;
return - V_71 ;
}
if ( F_44 ( F_18 ( V_72 , V_1 , 1 ) ) ) {
F_2 ( V_73 L_8
L_9 , V_1 ) ;
}
#if ! ( F_8 ( V_9 ) || F_8 ( V_26 ) )
else {
F_47 ( V_1 , 0 ) ;
}
#endif
F_29 ( V_1 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_27 ( V_40 ) ;
F_9 ( V_1 , V_21 ) ;
return 0 ;
}
void F_48 ( unsigned V_1 )
{
unsigned long V_40 ;
if ( F_7 ( V_1 ) < 0 )
return;
F_49 () ;
V_40 = F_25 () ;
if ( F_44 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
if ( V_69 == V_70 )
F_6 () ;
F_1 ( V_1 ) ;
F_27 ( V_40 ) ;
return;
}
F_30 ( V_1 , V_1 ) ;
F_3 ( V_1 , L_5 ) ;
F_27 ( V_40 ) ;
}
int F_50 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_40 ;
V_40 = F_25 () ;
if ( F_5 ( V_1 , V_4 ) == 0 ) {
F_27 ( V_40 ) ;
return 0 ;
}
if ( F_44 ( F_18 ( V_74 , V_1 , 1 ) ) ) {
F_27 ( V_40 ) ;
F_2 ( V_2 L_6 ,
V_1 , F_4 ( V_1 ) ) ;
return - V_71 ;
}
if ( F_44 ( F_18 ( V_35 , V_1 , 1 ) ) ) {
F_27 ( V_40 ) ;
F_2 ( V_2
L_7 ,
V_1 , F_4 ( V_1 ) ) ;
return - V_71 ;
}
F_29 ( V_74 , V_1 ) ;
F_29 ( V_35 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_27 ( V_40 ) ;
F_9 ( V_1 , V_21 ) ;
return 0 ;
}
void F_51 ( unsigned V_1 )
{
unsigned long V_40 ;
F_49 () ;
V_40 = F_25 () ;
if ( F_44 ( ! F_18 ( V_74 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
F_27 ( V_40 ) ;
return;
}
F_30 ( V_74 , V_1 ) ;
F_30 ( V_35 , V_1 ) ;
F_3 ( V_1 , L_5 ) ;
F_27 ( V_40 ) ;
}
int F_52 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_40 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_40 = F_25 () ;
if ( F_44 ( F_18 ( V_35 , V_1 , 1 ) ) ) {
if ( V_69 == V_70 )
F_6 () ;
F_2 ( V_2
L_7 ,
V_1 , F_4 ( V_1 ) ) ;
F_27 ( V_40 ) ;
return - V_71 ;
}
if ( F_44 ( F_18 ( V_1 , V_1 , 1 ) ) )
F_2 ( V_73 L_10
L_11 ,
V_1 , F_4 ( V_1 ) ) ;
F_29 ( V_72 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_27 ( V_40 ) ;
F_9 ( V_1 , V_21 ) ;
return 0 ;
}
void F_53 ( unsigned V_1 )
{
unsigned long V_40 ;
if ( F_7 ( V_1 ) < 0 )
return;
V_40 = F_25 () ;
if ( F_44 ( ! F_18 ( V_72 , V_1 , 0 ) ) ) {
if ( V_69 == V_70 )
F_6 () ;
F_1 ( V_1 ) ;
F_27 ( V_40 ) ;
return;
}
F_30 ( V_72 , V_1 ) ;
F_3 ( V_1 , L_5 ) ;
F_27 ( V_40 ) ;
}
static inline void F_54 ( unsigned V_1 )
{
#if F_8 ( V_9 ) || F_8 ( V_26 )
V_27 [ F_10 ( V_1 ) ] -> V_63 = F_11 ( V_1 ) ;
#else
V_27 [ F_10 ( V_1 ) ] -> V_57 &= ~ F_11 ( V_1 ) ;
#endif
V_27 [ F_10 ( V_1 ) ] -> V_55 |= F_11 ( V_1 ) ;
}
int F_55 ( unsigned V_1 )
{
unsigned long V_40 ;
if ( F_44 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
return - V_8 ;
}
V_40 = F_25 () ;
F_54 ( V_1 ) ;
F_26 ( V_55 ) ;
F_27 ( V_40 ) ;
return 0 ;
}
void F_56 ( unsigned V_1 )
{
#if F_8 ( V_9 ) || F_8 ( V_26 )
unsigned long V_40 ;
#endif
F_9 ( V_1 , V_21 ) ;
#if F_8 ( V_9 ) || F_8 ( V_26 )
V_40 = F_25 () ;
F_54 ( V_1 ) ;
F_27 ( V_40 ) ;
#endif
}
void F_57 ( unsigned V_1 , int V_75 )
{
if ( V_75 )
V_27 [ F_10 ( V_1 ) ] -> V_61 = F_11 ( V_1 ) ;
else
V_27 [ F_10 ( V_1 ) ] -> V_76 = F_11 ( V_1 ) ;
}
int F_58 ( unsigned V_1 , int V_77 )
{
unsigned long V_40 ;
if ( F_44 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
return - V_8 ;
}
V_40 = F_25 () ;
V_27 [ F_10 ( V_1 ) ] -> V_55 &= ~ F_11 ( V_1 ) ;
F_59 ( V_1 , V_77 ) ;
#if F_8 ( V_9 ) || F_8 ( V_26 )
V_27 [ F_10 ( V_1 ) ] -> V_62 = F_11 ( V_1 ) ;
#else
V_27 [ F_10 ( V_1 ) ] -> V_57 |= F_11 ( V_1 ) ;
#endif
F_26 ( V_57 ) ;
F_27 ( V_40 ) ;
return 0 ;
}
int F_60 ( unsigned V_1 )
{
#if F_8 ( V_9 ) || F_8 ( V_26 )
return ( 1 & ( V_27 [ F_10 ( V_1 ) ] -> V_54 >> F_22 ( V_1 ) ) ) ;
#else
unsigned long V_40 ;
if ( F_44 ( F_61 ( V_1 ) ) ) {
int V_65 ;
V_40 = F_25 () ;
F_62 ( V_1 , 0 ) ;
V_65 = F_63 ( V_1 ) ;
F_62 ( V_1 , 1 ) ;
F_27 ( V_40 ) ;
return V_65 ;
} else
return F_63 ( V_1 ) ;
#endif
}
void F_64 ( unsigned short V_37 )
{
unsigned short V_1 = F_14 ( V_37 ) ;
F_9 ( V_1 , V_21 ) ;
V_27 [ F_10 ( V_1 ) ] -> V_61 = F_11 ( V_1 ) ;
F_26 ( V_61 ) ;
F_65 ( 1 ) ;
}
static int F_66 ( struct V_78 * V_32 , void * V_79 )
{
int V_80 , V_81 , V_1 ;
for ( V_80 = 0 ; V_80 < V_20 ; V_80 ++ ) {
V_81 = F_18 ( V_72 , V_80 , 1 ) ;
V_1 = F_18 ( V_1 , V_80 , 1 ) ;
if ( ! F_7 ( V_80 ) && ( V_1 || V_81 ) )
F_67 ( V_32 , L_12 , V_80 ,
F_4 ( V_80 ) , ( V_1 && V_81 ) ? L_13 : L_14 ,
F_40 ( V_80 ) ? L_15 : L_16 ) ;
else if ( F_18 ( V_35 , V_80 , 1 ) )
F_67 ( V_32 , L_17 , V_80 , F_4 ( V_80 ) ) ;
else
continue;
}
return 0 ;
}
static int F_68 ( struct V_82 * V_82 , struct V_83 * V_83 )
{
return F_69 ( V_83 , F_66 , NULL ) ;
}
static T_5 int F_70 ( void )
{
struct V_84 * V_85 ;
V_85 = F_71 ( L_18 , V_86 , NULL , & V_87 ) ;
return V_85 != NULL ;
}
static int F_72 ( struct V_88 * V_89 , unsigned V_1 )
{
return F_55 ( V_1 ) ;
}
static int F_73 ( struct V_88 * V_89 , unsigned V_1 , int V_90 )
{
return F_58 ( V_1 , V_90 ) ;
}
static int F_74 ( struct V_88 * V_89 , unsigned V_1 )
{
return F_60 ( V_1 ) ;
}
static void F_75 ( struct V_88 * V_89 , unsigned V_1 , int V_77 )
{
return F_57 ( V_1 , V_77 ) ;
}
static int F_76 ( struct V_88 * V_89 , unsigned V_1 )
{
return F_46 ( V_1 , V_89 -> V_4 ) ;
}
static void F_77 ( struct V_88 * V_89 , unsigned V_1 )
{
return F_48 ( V_1 ) ;
}
static int F_78 ( struct V_88 * V_89 , unsigned V_1 )
{
return V_1 + V_91 ;
}
static int T_5 F_79 ( void )
{
return F_80 ( & V_92 ) ;
}
