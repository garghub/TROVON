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
#elif F_8 ( V_9 )
if ( V_18 == V_21 )
V_26 [ F_10 ( V_1 ) ] -> V_22 &= ~ F_11 ( V_1 ) ;
else
V_26 [ F_10 ( V_1 ) ] -> V_22 |= F_11 ( V_1 ) ;
F_12 () ;
#endif
}
static int F_13 ( unsigned short V_27 )
{
T_1 V_3 = F_14 ( V_27 ) ;
T_1 V_28 = F_15 ( V_27 ) ;
T_2 V_29 = V_30 [ V_3 ] ;
T_1 V_31 , V_32 , V_33 ;
if ( V_29 < 0 )
return 0 ;
V_32 = F_16 () ;
for ( V_31 = 0 ; V_31 < F_17 ( V_30 ) ; ++ V_31 ) {
if ( V_31 == V_3 )
continue;
if ( V_30 [ V_31 ] != V_29 )
continue;
if ( ! F_18 ( V_34 , V_31 , 1 ) )
continue;
if ( V_29 == 1 )
V_33 = ( V_32 >> V_29 ) & 3 ;
else
V_33 = ( V_32 >> V_29 ) & 1 ;
if ( V_33 != V_28 ) {
F_19 ( L_4 ,
V_3 , V_28 , V_31 , V_33 ) ;
return - V_8 ;
}
}
return 0 ;
}
static void F_20 ( unsigned short V_27 )
{
T_1 V_3 = F_14 ( V_27 ) ;
T_1 V_28 = F_15 ( V_27 ) ;
T_2 V_29 = V_30 [ V_3 ] ;
T_1 V_32 ;
if ( V_29 == - 1 )
return;
V_32 = F_16 () ;
if ( V_29 != 1 )
V_32 &= ~ ( 1 << V_29 ) ;
else
V_32 &= ~ ( 3 << 1 ) ;
V_32 |= ( V_28 << V_29 ) ;
F_21 ( V_32 ) ;
}
inline void F_20 ( unsigned short V_27 )
{
T_1 V_3 = F_14 ( V_27 ) ;
T_1 V_28 = F_15 ( V_27 ) ;
T_3 V_32 ;
V_32 = V_26 [ F_10 ( V_3 ) ] -> V_30 ;
V_32 &= ~ ( 0x3 << ( 2 * F_22 ( V_3 ) ) ) ;
V_32 |= ( V_28 & 0x3 ) << ( 2 * F_22 ( V_3 ) ) ;
V_26 [ F_10 ( V_3 ) ] -> V_30 = V_32 ;
}
inline T_1 F_23 ( unsigned short V_27 )
{
T_1 V_3 = F_14 ( V_27 ) ;
T_3 V_32 = V_26 [ F_10 ( V_3 ) ] -> V_30 ;
return ( V_32 >> ( 2 * F_22 ( V_3 ) ) & 0x3 ) ;
}
static int F_13 ( unsigned short V_27 )
{
return 0 ;
}
static int F_13 ( unsigned short V_27 )
{
T_1 V_3 = F_14 ( V_27 ) ;
T_1 V_28 = F_15 ( V_27 ) ;
T_4 V_29 = V_35 [ F_10 ( V_3 ) ] [ F_22 ( V_3 ) ] ;
T_1 V_36 , V_37 , V_33 ;
for ( V_36 = 0 ; V_36 < V_38 ; ++ V_36 ) {
if ( V_29 != V_35 [ F_10 ( V_3 ) ] [ V_36 ] )
continue;
V_37 = F_10 ( V_3 ) * V_38 + V_36 ;
if ( V_37 == V_3 )
continue;
if ( ! F_18 ( V_34 , V_37 , 1 ) )
continue;
V_33 = * V_30 [ F_10 ( V_3 ) ] ;
V_33 = ( V_33 >> V_29 ) & 3 ;
if ( V_33 != V_28 ) {
F_19 ( L_4 ,
V_3 , V_28 , V_37 , V_33 ) ;
return - V_8 ;
}
}
return 0 ;
}
inline void F_20 ( unsigned short V_27 )
{
T_1 V_3 = F_14 ( V_27 ) ;
T_1 V_28 = F_15 ( V_27 ) ;
T_4 V_29 = V_35 [ F_10 ( V_3 ) ] [ F_22 ( V_3 ) ] ;
T_1 V_32 ;
V_32 = * V_30 [ F_10 ( V_3 ) ] ;
if ( ( ( V_32 >> V_29 ) & 3 ) == V_28 )
return;
V_32 &= ~ ( 3 << V_29 ) ;
V_32 |= ( V_28 & 3 ) << V_29 ;
* V_30 [ F_10 ( V_3 ) ] = V_32 ;
F_12 () ;
}
static int F_13 ( unsigned short V_27 )
{
return 0 ;
}
void F_24 ( unsigned V_1 )
{
unsigned long V_39 ;
if ( V_40 || V_41 )
V_39 = F_25 () ;
V_26 [ F_10 ( V_1 ) ] -> V_42 = F_11 ( V_1 ) ;
if ( V_40 || V_41 ) {
F_26 ( V_42 ) ;
F_27 ( V_39 ) ;
}
}
int F_28 ( unsigned V_1 , unsigned V_43 )
{
unsigned long V_39 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_39 = F_25 () ;
if ( V_43 )
F_29 ( V_44 , V_1 ) ;
else
F_30 ( V_44 , V_1 ) ;
F_31 ( V_1 , V_43 ) ;
F_27 ( V_39 ) ;
return 0 ;
}
int F_32 ( unsigned V_43 )
{
T_1 V_45 , V_46 , V_47 ;
for ( V_47 = 0 ; V_47 < V_17 ; V_47 += V_38 ) {
V_46 = F_33 ( V_44 , V_47 ) ;
V_45 = F_10 ( V_47 ) ;
if ( V_46 )
F_34 ( V_48 [ V_45 ] , V_43 ) ;
}
return 0 ;
}
void F_35 ( void )
{
int V_47 , V_45 ;
for ( V_47 = 0 ; V_47 < V_17 ; V_47 += V_38 ) {
V_45 = F_10 ( V_47 ) ;
#if F_8 ( V_23 ) || F_8 ( V_24 ) || F_8 ( V_25 )
V_49 [ V_45 ] . V_50 = * V_22 [ V_45 ] ;
#if F_8 ( V_23 ) || F_8 ( V_25 )
V_49 [ V_45 ] . V_51 = * V_30 [ V_45 ] ;
#else
if ( V_45 == 0 )
V_49 [ V_45 ] . V_51 = F_16 () ;
#endif
#endif
V_49 [ V_45 ] . V_52 = V_26 [ V_45 ] -> V_52 ;
V_49 [ V_45 ] . V_53 = V_26 [ V_45 ] -> V_53 ;
V_49 [ V_45 ] . V_54 = V_26 [ V_45 ] -> V_54 ;
V_49 [ V_45 ] . V_55 = V_26 [ V_45 ] -> V_55 ;
V_49 [ V_45 ] . V_56 = V_26 [ V_45 ] -> V_56 ;
V_49 [ V_45 ] . V_57 = V_26 [ V_45 ] -> V_57 ;
V_49 [ V_45 ] . V_58 = V_26 [ V_45 ] -> V_58 ;
}
F_26 ( V_58 ) ;
}
void F_36 ( void )
{
int V_47 , V_45 ;
for ( V_47 = 0 ; V_47 < V_17 ; V_47 += V_38 ) {
V_45 = F_10 ( V_47 ) ;
#if F_8 ( V_23 ) || F_8 ( V_24 ) || F_8 ( V_25 )
#if F_8 ( V_23 ) || F_8 ( V_25 )
* V_30 [ V_45 ] = V_49 [ V_45 ] . V_51 ;
#else
if ( V_45 == 0 )
F_21 ( V_49 [ V_45 ] . V_51 ) ;
#endif
* V_22 [ V_45 ] = V_49 [ V_45 ] . V_50 ;
#endif
V_26 [ V_45 ] -> V_53 = V_49 [ V_45 ] . V_53 ;
V_26 [ V_45 ] -> V_59 = V_49 [ V_45 ] . V_52
& V_49 [ V_45 ] . V_55 ;
V_26 [ V_45 ] -> V_55 = V_49 [ V_45 ] . V_55 ;
V_26 [ V_45 ] -> V_54 = V_49 [ V_45 ] . V_54 ;
V_26 [ V_45 ] -> V_56 = V_49 [ V_45 ] . V_56 ;
V_26 [ V_45 ] -> V_57 = V_49 [ V_45 ] . V_57 ;
V_26 [ V_45 ] -> V_58 = V_49 [ V_45 ] . V_58 ;
}
F_26 ( V_58 ) ;
}
int F_32 ( unsigned V_43 )
{
return 0 ;
}
void F_35 ( void )
{
int V_47 , V_45 ;
for ( V_47 = 0 ; V_47 < V_17 ; V_47 += V_38 ) {
V_45 = F_10 ( V_47 ) ;
V_49 [ V_45 ] . V_50 = V_26 [ V_45 ] -> V_22 ;
V_49 [ V_45 ] . V_51 = V_26 [ V_45 ] -> V_30 ;
V_49 [ V_45 ] . V_52 = V_26 [ V_45 ] -> V_52 ;
V_49 [ V_45 ] . V_53 = V_26 [ V_45 ] -> V_53 ;
V_49 [ V_45 ] . V_55 = V_26 [ V_45 ] -> V_60 ;
}
}
void F_36 ( void )
{
int V_47 , V_45 ;
for ( V_47 = 0 ; V_47 < V_17 ; V_47 += V_38 ) {
V_45 = F_10 ( V_47 ) ;
V_26 [ V_45 ] -> V_30 = V_49 [ V_45 ] . V_51 ;
V_26 [ V_45 ] -> V_22 = V_49 [ V_45 ] . V_50 ;
V_26 [ V_45 ] -> V_53 = V_49 [ V_45 ] . V_53 ;
V_26 [ V_45 ] -> V_60 = V_49 [ V_45 ] . V_55 ;
V_26 [ V_45 ] -> V_59 = V_49 [ V_45 ] . V_52
| V_49 [ V_45 ] . V_55 ;
}
}
unsigned short F_37 ( unsigned V_1 )
{
return ( 0x01 & ( V_26 [ F_10 ( V_1 ) ] -> V_61 >> F_22 ( V_1 ) ) ) ;
}
int F_38 ( const unsigned short V_27 [] , const char * V_4 )
{
T_1 V_62 ;
int V_63 ;
for ( V_62 = 0 ; V_27 [ V_62 ] != 0 ; V_62 ++ ) {
V_63 = F_39 ( V_27 [ V_62 ] , V_4 ) ;
if ( V_63 < 0 ) {
for ( ; V_62 > 0 ; V_62 -- )
F_40 ( V_27 [ V_62 - 1 ] ) ;
return V_63 ;
}
}
return 0 ;
}
void F_40 ( unsigned short V_27 )
{
unsigned long V_39 ;
unsigned short V_3 = F_14 ( V_27 ) ;
if ( V_27 & V_64 )
return;
if ( ! ( V_27 & V_65 ) )
return;
V_39 = F_25 () ;
if ( F_41 ( ! F_18 ( V_34 , V_3 , 0 ) ) ) {
F_27 ( V_39 ) ;
return;
}
if ( ! ( V_27 & V_66 ) )
F_9 ( V_3 , V_21 ) ;
F_30 ( V_34 , V_3 ) ;
F_3 ( V_3 , L_5 ) ;
F_27 ( V_39 ) ;
}
void F_42 ( const unsigned short V_27 [] )
{
T_1 V_62 ;
for ( V_62 = 0 ; V_27 [ V_62 ] != 0 ; V_62 ++ )
F_40 ( V_27 [ V_62 ] ) ;
}
int F_43 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_39 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_39 = F_25 () ;
if ( F_5 ( V_1 , V_4 ) == 0 ) {
F_27 ( V_39 ) ;
return 0 ;
}
if ( F_41 ( F_18 ( V_1 , V_1 , 1 ) ) ) {
if ( V_67 == V_68 )
F_6 () ;
F_2 ( V_2 L_6 ,
V_1 , F_4 ( V_1 ) ) ;
F_27 ( V_39 ) ;
return - V_69 ;
}
if ( F_41 ( F_18 ( V_34 , V_1 , 1 ) ) ) {
if ( V_67 == V_68 )
F_6 () ;
F_2 ( V_2
L_7 ,
V_1 , F_4 ( V_1 ) ) ;
F_27 ( V_39 ) ;
return - V_69 ;
}
if ( F_41 ( F_18 ( V_70 , V_1 , 1 ) ) ) {
F_2 ( V_71 L_8
L_9 , V_1 ) ;
}
#ifndef V_9
else {
F_44 ( V_1 , 0 ) ;
}
#endif
F_29 ( V_1 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_27 ( V_39 ) ;
F_9 ( V_1 , V_21 ) ;
return 0 ;
}
void F_45 ( unsigned V_1 )
{
unsigned long V_39 ;
if ( F_7 ( V_1 ) < 0 )
return;
F_46 () ;
V_39 = F_25 () ;
if ( F_41 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
if ( V_67 == V_68 )
F_6 () ;
F_1 ( V_1 ) ;
F_27 ( V_39 ) ;
return;
}
F_30 ( V_1 , V_1 ) ;
F_3 ( V_1 , L_5 ) ;
F_27 ( V_39 ) ;
}
int F_47 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_39 ;
V_39 = F_25 () ;
if ( F_5 ( V_1 , V_4 ) == 0 ) {
F_27 ( V_39 ) ;
return 0 ;
}
if ( F_41 ( F_18 ( V_72 , V_1 , 1 ) ) ) {
F_27 ( V_39 ) ;
F_2 ( V_2 L_6 ,
V_1 , F_4 ( V_1 ) ) ;
return - V_69 ;
}
if ( F_41 ( F_18 ( V_34 , V_1 , 1 ) ) ) {
F_27 ( V_39 ) ;
F_2 ( V_2
L_7 ,
V_1 , F_4 ( V_1 ) ) ;
return - V_69 ;
}
F_29 ( V_72 , V_1 ) ;
F_29 ( V_34 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_27 ( V_39 ) ;
F_9 ( V_1 , V_21 ) ;
return 0 ;
}
void F_48 ( unsigned V_1 )
{
unsigned long V_39 ;
F_46 () ;
V_39 = F_25 () ;
if ( F_41 ( ! F_18 ( V_72 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
F_27 ( V_39 ) ;
return;
}
F_30 ( V_72 , V_1 ) ;
F_30 ( V_34 , V_1 ) ;
F_3 ( V_1 , L_5 ) ;
F_27 ( V_39 ) ;
}
int F_49 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_39 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_39 = F_25 () ;
if ( F_41 ( F_18 ( V_34 , V_1 , 1 ) ) ) {
if ( V_67 == V_68 )
F_6 () ;
F_2 ( V_2
L_7 ,
V_1 , F_4 ( V_1 ) ) ;
F_27 ( V_39 ) ;
return - V_69 ;
}
if ( F_41 ( F_18 ( V_1 , V_1 , 1 ) ) )
F_2 ( V_71 L_10
L_11 ,
V_1 , F_4 ( V_1 ) ) ;
F_29 ( V_70 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_27 ( V_39 ) ;
F_9 ( V_1 , V_21 ) ;
return 0 ;
}
void F_50 ( unsigned V_1 )
{
unsigned long V_39 ;
if ( F_7 ( V_1 ) < 0 )
return;
V_39 = F_25 () ;
if ( F_41 ( ! F_18 ( V_70 , V_1 , 0 ) ) ) {
if ( V_67 == V_68 )
F_6 () ;
F_1 ( V_1 ) ;
F_27 ( V_39 ) ;
return;
}
F_30 ( V_70 , V_1 ) ;
F_3 ( V_1 , L_5 ) ;
F_27 ( V_39 ) ;
}
static inline void F_51 ( unsigned V_1 )
{
#ifdef V_9
V_26 [ F_10 ( V_1 ) ] -> V_61 = F_11 ( V_1 ) ;
#else
V_26 [ F_10 ( V_1 ) ] -> V_55 &= ~ F_11 ( V_1 ) ;
#endif
V_26 [ F_10 ( V_1 ) ] -> V_53 |= F_11 ( V_1 ) ;
}
int F_52 ( unsigned V_1 )
{
unsigned long V_39 ;
if ( F_41 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
return - V_8 ;
}
V_39 = F_25 () ;
F_51 ( V_1 ) ;
F_26 ( V_53 ) ;
F_27 ( V_39 ) ;
return 0 ;
}
void F_53 ( unsigned V_1 )
{
#ifdef V_9
unsigned long V_39 ;
#endif
F_9 ( V_1 , V_21 ) ;
#ifdef V_9
V_39 = F_25 () ;
F_51 ( V_1 ) ;
F_27 ( V_39 ) ;
#endif
}
void F_54 ( unsigned V_1 , int V_73 )
{
if ( V_73 )
V_26 [ F_10 ( V_1 ) ] -> V_59 = F_11 ( V_1 ) ;
else
V_26 [ F_10 ( V_1 ) ] -> V_74 = F_11 ( V_1 ) ;
}
int F_55 ( unsigned V_1 , int V_75 )
{
unsigned long V_39 ;
if ( F_41 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
return - V_8 ;
}
V_39 = F_25 () ;
V_26 [ F_10 ( V_1 ) ] -> V_53 &= ~ F_11 ( V_1 ) ;
F_56 ( V_1 , V_75 ) ;
#ifdef V_9
V_26 [ F_10 ( V_1 ) ] -> V_60 = F_11 ( V_1 ) ;
#else
V_26 [ F_10 ( V_1 ) ] -> V_55 |= F_11 ( V_1 ) ;
#endif
F_26 ( V_55 ) ;
F_27 ( V_39 ) ;
return 0 ;
}
int F_57 ( unsigned V_1 )
{
#ifdef V_9
return ( 1 & ( V_26 [ F_10 ( V_1 ) ] -> V_52 >> F_22 ( V_1 ) ) ) ;
#else
unsigned long V_39 ;
if ( F_41 ( F_58 ( V_1 ) ) ) {
int V_63 ;
V_39 = F_25 () ;
F_59 ( V_1 , 0 ) ;
V_63 = F_60 ( V_1 ) ;
F_59 ( V_1 , 1 ) ;
F_27 ( V_39 ) ;
return V_63 ;
} else
return F_60 ( V_1 ) ;
#endif
}
void F_61 ( unsigned short V_36 )
{
unsigned short V_1 = F_14 ( V_36 ) ;
F_9 ( V_1 , V_21 ) ;
V_26 [ F_10 ( V_1 ) ] -> V_59 = F_11 ( V_1 ) ;
F_26 ( V_59 ) ;
F_62 ( 1 ) ;
}
static int F_63 ( struct V_76 * V_31 , void * V_77 )
{
int V_78 , V_79 , V_1 ;
for ( V_78 = 0 ; V_78 < V_20 ; V_78 ++ ) {
V_79 = F_18 ( V_70 , V_78 , 1 ) ;
V_1 = F_18 ( V_1 , V_78 , 1 ) ;
if ( ! F_7 ( V_78 ) && ( V_1 || V_79 ) )
F_64 ( V_31 , L_12 , V_78 ,
F_4 ( V_78 ) , ( V_1 && V_79 ) ? L_13 : L_14 ,
F_37 ( V_78 ) ? L_15 : L_16 ) ;
else if ( F_18 ( V_34 , V_78 , 1 ) )
F_64 ( V_31 , L_17 , V_78 , F_4 ( V_78 ) ) ;
else
continue;
}
return 0 ;
}
static int F_65 ( struct V_80 * V_80 , struct V_81 * V_81 )
{
return F_66 ( V_81 , F_63 , NULL ) ;
}
static T_5 int F_67 ( void )
{
struct V_82 * V_83 ;
V_83 = F_68 ( L_18 , V_84 , NULL , & V_85 ) ;
return V_83 != NULL ;
}
static int F_69 ( struct V_86 * V_87 , unsigned V_1 )
{
return F_52 ( V_1 ) ;
}
static int F_70 ( struct V_86 * V_87 , unsigned V_1 , int V_88 )
{
return F_55 ( V_1 , V_88 ) ;
}
static int F_71 ( struct V_86 * V_87 , unsigned V_1 )
{
return F_57 ( V_1 ) ;
}
static void F_72 ( struct V_86 * V_87 , unsigned V_1 , int V_75 )
{
return F_54 ( V_1 , V_75 ) ;
}
static int F_73 ( struct V_86 * V_87 , unsigned V_1 )
{
return F_43 ( V_1 , V_87 -> V_4 ) ;
}
static void F_74 ( struct V_86 * V_87 , unsigned V_1 )
{
return F_45 ( V_1 ) ;
}
static int F_75 ( struct V_86 * V_87 , unsigned V_1 )
{
return V_1 + V_89 ;
}
static int T_5 F_76 ( void )
{
return F_77 ( & V_90 ) ;
}
