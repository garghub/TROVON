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
if ( V_1 >= V_9 )
return - V_8 ;
return 0 ;
}
static void F_8 ( unsigned V_1 , unsigned short V_10 )
{
#if F_9 ( V_11 )
if ( V_1 < V_9 || V_1 >= V_12 )
return;
V_1 -= V_9 ;
if ( V_10 == V_13 )
* V_14 [ F_10 ( V_1 ) ] |= F_11 ( V_1 ) ;
else
* V_14 [ F_10 ( V_1 ) ] &= ~ F_11 ( V_1 ) ;
F_12 () ;
return;
#endif
if ( F_7 ( V_1 ) )
return;
#if F_9 ( V_15 ) || F_9 ( V_16 ) || F_9 ( V_17 )
if ( V_10 == V_13 )
* V_14 [ F_10 ( V_1 ) ] &= ~ F_11 ( V_1 ) ;
else
* V_14 [ F_10 ( V_1 ) ] |= F_11 ( V_1 ) ;
F_12 () ;
#endif
}
static int F_13 ( unsigned short V_18 )
{
T_1 V_3 = F_14 ( V_18 ) ;
T_1 V_19 = F_15 ( V_18 ) ;
T_2 V_20 = V_21 [ V_3 ] ;
T_1 V_22 , V_23 , V_24 , V_25 ;
if ( V_20 < 0 )
return 0 ;
V_23 = F_16 () ;
for ( V_22 = 0 ; V_22 < F_17 ( V_21 ) ; ++ V_22 ) {
if ( V_22 == V_3 )
continue;
if ( V_21 [ V_22 ] != V_20 )
continue;
if ( ! F_18 ( V_26 , V_22 , 1 ) )
continue;
if ( V_20 == 1 )
V_25 = 3 ;
else
V_25 = 1 ;
V_24 = ( V_23 >> V_20 ) & V_25 ;
if ( V_24 != ( V_19 & V_25 ) ) {
F_19 ( L_4 ,
V_3 , V_19 , V_22 , V_24 ) ;
return - V_8 ;
}
}
return 0 ;
}
static void F_20 ( unsigned short V_18 )
{
T_1 V_3 = F_14 ( V_18 ) ;
T_1 V_19 = F_15 ( V_18 ) ;
T_2 V_20 = V_21 [ V_3 ] ;
T_1 V_23 , V_25 ;
if ( V_20 == - 1 )
return;
V_23 = F_16 () ;
if ( V_20 == 1 )
V_25 = 3 ;
else
V_25 = 1 ;
V_23 &= ~ ( V_25 << V_20 ) ;
V_23 |= ( ( V_19 & V_25 ) << V_20 ) ;
F_21 ( V_23 ) ;
}
static int F_13 ( unsigned short V_18 )
{
T_1 V_3 = F_14 ( V_18 ) ;
T_1 V_19 = F_15 ( V_18 ) ;
T_3 V_20 = V_27 [ F_10 ( V_3 ) ] [ F_22 ( V_3 ) ] ;
T_1 V_28 , V_29 , V_24 ;
for ( V_28 = 0 ; V_28 < V_30 ; ++ V_28 ) {
if ( V_20 != V_27 [ F_10 ( V_3 ) ] [ V_28 ] )
continue;
V_29 = F_10 ( V_3 ) * V_30 + V_28 ;
if ( V_29 == V_3 )
continue;
if ( ! F_18 ( V_26 , V_29 , 1 ) )
continue;
V_24 = * V_21 [ F_10 ( V_3 ) ] ;
V_24 = ( V_24 >> V_20 ) & 3 ;
if ( V_24 != V_19 ) {
F_19 ( L_4 ,
V_3 , V_19 , V_29 , V_24 ) ;
return - V_8 ;
}
}
return 0 ;
}
inline void F_20 ( unsigned short V_18 )
{
T_1 V_3 = F_14 ( V_18 ) ;
T_1 V_19 = F_15 ( V_18 ) ;
T_3 V_20 = V_27 [ F_10 ( V_3 ) ] [ F_22 ( V_3 ) ] ;
T_1 V_23 ;
V_23 = * V_21 [ F_10 ( V_3 ) ] ;
if ( ( ( V_23 >> V_20 ) & 3 ) == V_19 )
return;
V_23 &= ~ ( 3 << V_20 ) ;
V_23 |= ( V_19 & 3 ) << V_20 ;
* V_21 [ F_10 ( V_3 ) ] = V_23 ;
F_12 () ;
}
static int F_13 ( unsigned short V_18 )
{
return 0 ;
}
void F_23 ( unsigned V_1 )
{
unsigned long V_31 ;
if ( V_32 || V_33 )
V_31 = F_24 () ;
V_34 [ F_10 ( V_1 ) ] -> V_35 = F_11 ( V_1 ) ;
if ( V_32 || V_33 ) {
F_25 ( V_35 ) ;
F_26 ( V_31 ) ;
}
}
int F_27 ( unsigned V_1 , unsigned V_36 )
{
unsigned long V_31 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_31 = F_24 () ;
if ( V_36 )
F_28 ( V_37 , V_1 ) ;
else
F_29 ( V_37 , V_1 ) ;
F_30 ( V_1 , V_36 ) ;
F_26 ( V_31 ) ;
return 0 ;
}
int F_31 ( unsigned V_36 )
{
T_1 V_38 , V_25 , V_39 ;
for ( V_39 = 0 ; V_39 < V_9 ; V_39 += V_30 ) {
V_25 = F_32 ( V_37 , V_39 ) ;
V_38 = F_10 ( V_39 ) ;
if ( V_25 )
F_33 ( V_40 [ V_38 ] , V_36 ) ;
}
return 0 ;
}
void F_34 ( void )
{
int V_39 , V_38 ;
#ifdef V_11
for ( V_39 = 0 ; V_39 < F_17 ( V_41 ) ; ++ V_39 )
V_41 [ V_39 ] = * V_14 [ V_39 ] ;
#endif
for ( V_39 = 0 ; V_39 < V_9 ; V_39 += V_30 ) {
V_38 = F_10 ( V_39 ) ;
#if F_9 ( V_15 ) || F_9 ( V_16 ) || F_9 ( V_17 )
V_42 [ V_38 ] . V_43 = * V_14 [ V_38 ] ;
#if F_9 ( V_15 ) || F_9 ( V_17 )
V_42 [ V_38 ] . V_44 = * V_21 [ V_38 ] ;
#else
if ( V_38 == 0 )
V_42 [ V_38 ] . V_44 = F_16 () ;
#endif
#endif
V_42 [ V_38 ] . V_45 = V_34 [ V_38 ] -> V_45 ;
V_42 [ V_38 ] . V_46 = V_34 [ V_38 ] -> V_46 ;
V_42 [ V_38 ] . V_47 = V_34 [ V_38 ] -> V_47 ;
V_42 [ V_38 ] . V_48 = V_34 [ V_38 ] -> V_48 ;
V_42 [ V_38 ] . V_49 = V_34 [ V_38 ] -> V_49 ;
V_42 [ V_38 ] . V_50 = V_34 [ V_38 ] -> V_50 ;
V_42 [ V_38 ] . V_51 = V_34 [ V_38 ] -> V_51 ;
}
#ifdef F_35
F_36 () ;
#endif
F_25 ( V_51 ) ;
}
void F_37 ( void )
{
int V_39 , V_38 ;
#ifdef V_11
for ( V_39 = 0 ; V_39 < F_17 ( V_41 ) ; ++ V_39 )
* V_14 [ V_39 ] = V_41 [ V_39 ] ;
#endif
for ( V_39 = 0 ; V_39 < V_9 ; V_39 += V_30 ) {
V_38 = F_10 ( V_39 ) ;
#if F_9 ( V_15 ) || F_9 ( V_16 ) || F_9 ( V_17 )
#if F_9 ( V_15 ) || F_9 ( V_17 )
* V_21 [ V_38 ] = V_42 [ V_38 ] . V_44 ;
#else
if ( V_38 == 0 )
F_21 ( V_42 [ V_38 ] . V_44 ) ;
#endif
* V_14 [ V_38 ] = V_42 [ V_38 ] . V_43 ;
#endif
V_34 [ V_38 ] -> V_46 = V_42 [ V_38 ] . V_46 ;
V_34 [ V_38 ] -> V_52 = V_42 [ V_38 ] . V_45
& V_42 [ V_38 ] . V_48 ;
V_34 [ V_38 ] -> V_48 = V_42 [ V_38 ] . V_48 ;
V_34 [ V_38 ] -> V_47 = V_42 [ V_38 ] . V_47 ;
V_34 [ V_38 ] -> V_49 = V_42 [ V_38 ] . V_49 ;
V_34 [ V_38 ] -> V_50 = V_42 [ V_38 ] . V_50 ;
V_34 [ V_38 ] -> V_51 = V_42 [ V_38 ] . V_51 ;
}
#ifdef F_35
F_38 () ;
#endif
F_25 ( V_51 ) ;
}
int F_39 ( unsigned short V_18 , const char * V_4 )
{
unsigned long V_31 ;
unsigned short V_3 = F_14 ( V_18 ) ;
if ( V_18 & V_53 )
return 0 ;
if ( ! ( V_18 & V_54 ) )
return - V_55 ;
F_40 ( V_3 >= V_12 ) ;
V_31 = F_24 () ;
if ( F_41 ( ! F_7 ( V_3 ) && F_18 ( V_1 , V_3 , 1 ) ) ) {
if ( V_56 == V_57 )
F_6 () ;
F_2 ( V_2
L_5 ,
V_58 , V_3 , F_4 ( V_3 ) ) ;
F_26 ( V_31 ) ;
return - V_59 ;
}
if ( F_41 ( F_18 ( V_26 , V_3 , 1 ) ) ) {
if ( ! ( V_18 & V_60 ) ) {
if ( F_5 ( V_3 , V_4 ) == 0 )
goto V_61;
if ( V_56 == V_57 )
F_6 () ;
F_2 ( V_2
L_6 ,
V_58 , V_3 , F_15 ( V_18 ) , F_4 ( V_3 ) ) ;
F_26 ( V_31 ) ;
return - V_59 ;
}
}
if ( F_41 ( F_13 ( V_18 ) ) ) {
F_26 ( V_31 ) ;
return - V_59 ;
}
V_61:
F_28 ( V_26 , V_3 ) ;
F_20 ( V_18 ) ;
F_8 ( V_3 , V_62 ) ;
F_26 ( V_31 ) ;
F_3 ( V_3 , V_4 ) ;
return 0 ;
}
int F_42 ( const unsigned short V_18 [] , const char * V_4 )
{
T_1 V_63 ;
int V_64 ;
for ( V_63 = 0 ; V_18 [ V_63 ] != 0 ; V_63 ++ ) {
V_64 = F_39 ( V_18 [ V_63 ] , V_4 ) ;
if ( V_64 < 0 ) {
for ( ; V_63 > 0 ; V_63 -- )
F_43 ( V_18 [ V_63 - 1 ] ) ;
return V_64 ;
}
}
return 0 ;
}
void F_43 ( unsigned short V_18 )
{
unsigned long V_31 ;
unsigned short V_3 = F_14 ( V_18 ) ;
if ( V_18 & V_53 )
return;
if ( ! ( V_18 & V_54 ) )
return;
V_31 = F_24 () ;
if ( F_41 ( ! F_18 ( V_26 , V_3 , 0 ) ) ) {
F_26 ( V_31 ) ;
return;
}
if ( ! ( V_18 & V_60 ) )
F_8 ( V_3 , V_13 ) ;
F_29 ( V_26 , V_3 ) ;
F_3 ( V_3 , L_7 ) ;
F_26 ( V_31 ) ;
}
void F_44 ( const unsigned short V_18 [] )
{
T_1 V_63 ;
for ( V_63 = 0 ; V_18 [ V_63 ] != 0 ; V_63 ++ )
F_43 ( V_18 [ V_63 ] ) ;
}
int F_45 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_31 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_31 = F_24 () ;
if ( F_5 ( V_1 , V_4 ) == 0 ) {
F_26 ( V_31 ) ;
return 0 ;
}
if ( F_41 ( F_18 ( V_1 , V_1 , 1 ) ) ) {
if ( V_56 == V_57 )
F_6 () ;
F_2 ( V_2 L_8 ,
V_1 , F_4 ( V_1 ) ) ;
F_26 ( V_31 ) ;
return - V_59 ;
}
if ( F_41 ( F_18 ( V_26 , V_1 , 1 ) ) ) {
if ( V_56 == V_57 )
F_6 () ;
F_2 ( V_2
L_9 ,
V_1 , F_4 ( V_1 ) ) ;
F_26 ( V_31 ) ;
return - V_59 ;
}
if ( F_41 ( F_18 ( V_65 , V_1 , 1 ) ) ) {
F_2 ( V_66 L_10
L_11 , V_1 ) ;
} else {
F_46 ( V_1 , 0 ) ;
}
F_28 ( V_1 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_26 ( V_31 ) ;
F_8 ( V_1 , V_13 ) ;
return 0 ;
}
void F_47 ( unsigned V_1 )
{
unsigned long V_31 ;
if ( F_7 ( V_1 ) < 0 )
return;
F_48 () ;
V_31 = F_24 () ;
if ( F_41 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
if ( V_56 == V_57 )
F_6 () ;
F_1 ( V_1 ) ;
F_26 ( V_31 ) ;
return;
}
F_29 ( V_1 , V_1 ) ;
F_3 ( V_1 , L_7 ) ;
F_26 ( V_31 ) ;
}
int F_49 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_31 ;
V_31 = F_24 () ;
if ( F_5 ( V_1 , V_4 ) == 0 ) {
F_26 ( V_31 ) ;
return 0 ;
}
if ( F_41 ( F_18 ( V_67 , V_1 , 1 ) ) ) {
F_26 ( V_31 ) ;
F_2 ( V_2 L_8 ,
V_1 , F_4 ( V_1 ) ) ;
return - V_59 ;
}
if ( F_41 ( F_18 ( V_26 , V_1 , 1 ) ) ) {
F_26 ( V_31 ) ;
F_2 ( V_2
L_9 ,
V_1 , F_4 ( V_1 ) ) ;
return - V_59 ;
}
F_28 ( V_67 , V_1 ) ;
F_28 ( V_26 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_26 ( V_31 ) ;
F_8 ( V_1 , V_13 ) ;
return 0 ;
}
void F_50 ( unsigned V_1 )
{
unsigned long V_31 ;
F_48 () ;
V_31 = F_24 () ;
if ( F_41 ( ! F_18 ( V_67 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
F_26 ( V_31 ) ;
return;
}
F_29 ( V_67 , V_1 ) ;
F_29 ( V_26 , V_1 ) ;
F_3 ( V_1 , L_7 ) ;
F_26 ( V_31 ) ;
}
int F_51 ( unsigned V_1 , const char * V_4 )
{
unsigned long V_31 ;
if ( F_7 ( V_1 ) < 0 )
return - V_8 ;
V_31 = F_24 () ;
if ( F_41 ( F_18 ( V_26 , V_1 , 1 ) ) ) {
if ( V_56 == V_57 )
F_6 () ;
F_2 ( V_2
L_9 ,
V_1 , F_4 ( V_1 ) ) ;
F_26 ( V_31 ) ;
return - V_59 ;
}
if ( F_41 ( F_18 ( V_1 , V_1 , 1 ) ) )
F_2 ( V_66 L_12
L_13 ,
V_1 , F_4 ( V_1 ) ) ;
F_28 ( V_65 , V_1 ) ;
F_3 ( V_1 , V_4 ) ;
F_26 ( V_31 ) ;
F_8 ( V_1 , V_13 ) ;
return 0 ;
}
void F_52 ( unsigned V_1 )
{
unsigned long V_31 ;
if ( F_7 ( V_1 ) < 0 )
return;
V_31 = F_24 () ;
if ( F_41 ( ! F_18 ( V_65 , V_1 , 0 ) ) ) {
if ( V_56 == V_57 )
F_6 () ;
F_1 ( V_1 ) ;
F_26 ( V_31 ) ;
return;
}
F_29 ( V_65 , V_1 ) ;
F_3 ( V_1 , L_7 ) ;
F_26 ( V_31 ) ;
}
static inline void F_53 ( unsigned V_1 )
{
V_34 [ F_10 ( V_1 ) ] -> V_48 &= ~ F_11 ( V_1 ) ;
V_34 [ F_10 ( V_1 ) ] -> V_46 |= F_11 ( V_1 ) ;
}
int F_54 ( unsigned V_1 )
{
unsigned long V_31 ;
if ( F_41 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
return - V_8 ;
}
V_31 = F_24 () ;
F_53 ( V_1 ) ;
F_25 ( V_46 ) ;
F_26 ( V_31 ) ;
return 0 ;
}
void F_55 ( unsigned V_1 )
{
F_8 ( V_1 , V_13 ) ;
}
void F_56 ( unsigned V_1 , int V_68 )
{
if ( V_68 )
V_34 [ F_10 ( V_1 ) ] -> V_52 = F_11 ( V_1 ) ;
else
V_34 [ F_10 ( V_1 ) ] -> V_69 = F_11 ( V_1 ) ;
}
int F_57 ( unsigned V_1 , int V_70 )
{
unsigned long V_31 ;
if ( F_41 ( ! F_18 ( V_1 , V_1 , 0 ) ) ) {
F_1 ( V_1 ) ;
return - V_8 ;
}
V_31 = F_24 () ;
V_34 [ F_10 ( V_1 ) ] -> V_46 &= ~ F_11 ( V_1 ) ;
F_58 ( V_1 , V_70 ) ;
V_34 [ F_10 ( V_1 ) ] -> V_48 |= F_11 ( V_1 ) ;
F_25 ( V_48 ) ;
F_26 ( V_31 ) ;
return 0 ;
}
int F_59 ( unsigned V_1 )
{
unsigned long V_31 ;
if ( F_41 ( F_60 ( V_1 ) ) ) {
int V_64 ;
V_31 = F_24 () ;
F_61 ( V_1 , 0 ) ;
V_64 = F_62 ( V_1 ) ;
F_61 ( V_1 , 1 ) ;
F_26 ( V_31 ) ;
return V_64 ;
} else
return F_62 ( V_1 ) ;
}
void F_63 ( unsigned short V_28 )
{
unsigned short V_1 = F_14 ( V_28 ) ;
F_8 ( V_1 , V_13 ) ;
V_34 [ F_10 ( V_1 ) ] -> V_52 = F_11 ( V_1 ) ;
F_25 ( V_52 ) ;
F_64 ( 1 ) ;
}
static int F_65 ( struct V_71 * V_22 , void * V_72 )
{
int V_73 , V_74 , V_1 ;
for ( V_73 = 0 ; V_73 < V_12 ; V_73 ++ ) {
V_74 = F_18 ( V_65 , V_73 , 1 ) ;
V_1 = F_18 ( V_1 , V_73 , 1 ) ;
if ( ! F_7 ( V_73 ) && ( V_1 || V_74 ) )
F_66 ( V_22 , L_14 , V_73 ,
F_4 ( V_73 ) , ( V_1 && V_74 ) ? L_15 : L_16 ,
F_67 ( V_73 ) ? L_17 : L_18 ) ;
else if ( F_18 ( V_26 , V_73 , 1 ) )
F_66 ( V_22 , L_19 , V_73 , F_4 ( V_73 ) ) ;
else
continue;
}
return 0 ;
}
static int F_68 ( struct V_75 * V_75 , struct V_76 * V_76 )
{
return F_69 ( V_76 , F_65 , NULL ) ;
}
static T_4 int F_70 ( void )
{
struct V_77 * V_78 ;
V_78 = F_71 ( L_20 , 0 , NULL , & V_79 ) ;
return V_78 == NULL ;
}
static int F_72 ( struct V_80 * V_81 , unsigned V_1 )
{
return F_54 ( V_1 ) ;
}
static int F_73 ( struct V_80 * V_81 , unsigned V_1 , int V_82 )
{
return F_57 ( V_1 , V_82 ) ;
}
static int F_74 ( struct V_80 * V_81 , unsigned V_1 )
{
return F_59 ( V_1 ) ;
}
static void F_75 ( struct V_80 * V_81 , unsigned V_1 , int V_70 )
{
return F_56 ( V_1 , V_70 ) ;
}
static int F_76 ( struct V_80 * V_81 , unsigned V_1 )
{
return F_45 ( V_1 , V_81 -> V_4 ) ;
}
static void F_77 ( struct V_80 * V_81 , unsigned V_1 )
{
return F_47 ( V_1 ) ;
}
static int F_78 ( struct V_80 * V_81 , unsigned V_1 )
{
return V_1 + V_83 ;
}
static int T_4 F_79 ( void )
{
return F_80 ( & V_84 ) ;
}
