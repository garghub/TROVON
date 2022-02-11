static inline unsigned F_1 ( unsigned long V_1 )
{
F_2 ( V_1 >= V_2 ) ;
return V_1 / ( V_3 * V_4 ) ;
}
static inline unsigned F_3 ( unsigned long V_1 )
{
return ( V_1 / V_4 ) % V_3 ;
}
static inline unsigned F_4 ( unsigned long V_1 )
{
return V_1 % V_4 ;
}
static void F_5 ( unsigned long * * * V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 [ V_6 ] = V_8 ;
}
static void F_6 ( unsigned long * V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 [ V_6 ] = F_7 ( V_9 ) ;
}
static void F_8 ( unsigned long * * V_5 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_7 ; V_6 ++ )
V_5 [ V_6 ] = V_9 ;
}
static void F_9 ( unsigned long * * V_10 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
V_10 [ V_6 ] = V_11 ;
}
static void F_10 ( unsigned long * V_10 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
V_10 [ V_6 ] = F_7 ( V_11 ) ;
}
static void F_11 ( unsigned long * V_12 )
{
unsigned V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; V_6 ++ )
V_12 [ V_6 ] = V_13 ;
}
void T_1 F_12 ( void )
{
unsigned long V_1 ;
if ( V_14 == NULL ) {
V_9 = F_13 ( V_15 , V_15 ) ;
F_10 ( V_9 ) ;
V_16 = F_13 ( V_15 , V_15 ) ;
F_8 ( V_16 ) ;
V_14 = F_13 ( V_15 , V_15 ) ;
F_6 ( V_14 ) ;
} else {
F_10 ( V_9 ) ;
}
for ( V_1 = 0 ; V_1 < V_17 ; V_1 += V_4 ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 = F_3 ( V_1 ) ;
unsigned long * * V_10 ;
unsigned long * V_20 ;
V_10 = V_21 [ V_18 ] ;
V_20 = V_16 [ V_18 ] ;
if ( V_10 == V_8 ) {
F_2 ( V_19 ) ;
F_2 ( V_20 != V_9 ) ;
V_14 [ V_18 ] = F_7 ( V_9 ) ;
V_1 += ( V_3 - 1 ) * V_4 ;
continue;
}
if ( V_20 == V_9 ) {
V_20 = F_13 ( V_15 , V_15 ) ;
F_10 ( V_20 ) ;
V_16 [ V_18 ] = V_20 ;
}
V_14 [ V_18 ] = F_7 ( V_20 ) ;
V_20 [ V_19 ] = F_7 ( V_10 [ V_19 ] ) ;
}
}
void F_14 ( void )
{
F_2 ( V_22 == & V_23 ) ;
V_22 -> V_24 . V_25 =
F_7 ( V_14 ) ;
V_22 -> V_24 . V_26 = V_17 ;
}
void T_2 F_15 ( void )
{
unsigned long * V_27 = ( unsigned long * ) V_28 -> V_27 ;
unsigned long V_26 = F_16 ( V_29 , V_28 -> V_30 ) ;
unsigned long V_1 ;
V_17 = V_26 ;
V_11 = F_13 ( V_15 , V_15 ) ;
F_11 ( V_11 ) ;
V_8 = F_13 ( V_15 , V_15 ) ;
F_9 ( V_8 ) ;
V_21 = F_13 ( V_15 , V_15 ) ;
F_5 ( V_21 ) ;
V_31 = F_13 ( V_15 , V_15 ) ;
F_11 ( V_31 ) ;
for ( V_1 = 0 ; V_1 < V_26 ; V_1 += V_4 ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 = F_3 ( V_1 ) ;
if ( V_21 [ V_18 ] == V_8 ) {
unsigned long * * V_10 = F_13 ( V_15 , V_15 ) ;
F_9 ( V_10 ) ;
V_21 [ V_18 ] = V_10 ;
}
if ( F_17 ( V_1 + V_4 > V_26 ) ) {
unsigned long V_32 ;
V_32 = V_26 % V_4 ;
for ( ; V_32 < V_4 ; V_32 ++ )
V_27 [ V_1 + V_32 ] = V_13 ;
}
V_21 [ V_18 ] [ V_19 ] = & V_27 [ V_1 ] ;
}
F_18 () ;
}
unsigned long F_19 ( unsigned long V_1 )
{
unsigned V_18 , V_19 , V_33 ;
if ( F_17 ( V_1 >= V_2 ) )
return V_13 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_33 = F_4 ( V_1 ) ;
if ( V_21 [ V_18 ] [ V_19 ] == V_31 )
return F_20 ( V_1 ) ;
return V_21 [ V_18 ] [ V_19 ] [ V_33 ] ;
}
static void * F_21 ( void )
{
return ( void * ) F_22 ( V_34 | V_35 ) ;
}
static void F_23 ( void * V_36 )
{
F_24 ( ( unsigned long ) V_36 ) ;
}
static bool F_25 ( unsigned long V_1 )
{
unsigned V_18 , V_19 ;
unsigned long * * * V_37 , * * V_10 ;
unsigned long * V_38 , * V_39 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_37 = & V_21 [ V_18 ] ;
V_10 = * V_37 ;
if ( V_10 == V_8 ) {
V_10 = F_21 () ;
if ( ! V_10 )
return false ;
F_9 ( V_10 ) ;
if ( F_26 ( V_37 , V_8 , V_10 ) != V_8 )
F_23 ( V_10 ) ;
}
V_38 = & V_14 [ V_18 ] ;
V_39 = V_16 [ V_18 ] ;
F_2 ( F_7 ( V_39 ) != * V_38 ) ;
if ( V_39 == V_9 ) {
unsigned long V_40 ;
unsigned long V_41 ;
V_39 = F_21 () ;
if ( ! V_39 )
return false ;
F_10 ( V_39 ) ;
V_40 = F_7 ( V_9 ) ;
V_41 = F_7 ( V_39 ) ;
if ( F_26 ( V_38 , V_40 , V_41 ) != V_40 )
F_23 ( V_39 ) ;
else
V_16 [ V_18 ] = V_39 ;
}
if ( V_21 [ V_18 ] [ V_19 ] == V_31 ||
V_21 [ V_18 ] [ V_19 ] == V_11 ) {
unsigned long * V_12 ;
unsigned long * V_42 = V_21 [ V_18 ] [ V_19 ] ;
V_12 = F_21 () ;
if ( ! V_12 )
return false ;
F_11 ( V_12 ) ;
if ( F_26 ( & V_10 [ V_19 ] , V_42 , V_12 ) != V_42 )
F_23 ( V_12 ) ;
else
V_39 [ V_19 ] = F_7 ( V_12 ) ;
}
return true ;
}
static bool T_2 F_27 ( unsigned long V_1 )
{
unsigned V_18 , V_19 , V_33 ;
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_33 = F_4 ( V_1 ) ;
if ( ! V_33 )
return false ;
F_28 ( V_21 [ V_18 ] [ V_19 ] == V_31 ,
L_1 ,
V_18 , V_19 ) ;
if ( V_21 [ V_18 ] [ V_19 ] != V_11 )
return false ;
if ( V_33 ) {
unsigned long * V_12 = F_13 ( V_15 , V_15 ) ;
unsigned long * V_20 ;
F_11 ( V_12 ) ;
V_21 [ V_18 ] [ V_19 ] = V_12 ;
V_20 = V_16 [ V_18 ] ;
F_28 ( V_20 [ V_19 ] != F_7 ( V_11 ) ,
L_2 ,
V_18 , V_19 ) ;
V_20 [ V_19 ] = F_7 ( V_12 ) ;
}
return V_33 != 0 ;
}
unsigned long T_2 F_29 ( unsigned long V_43 ,
unsigned long V_44 )
{
unsigned long V_1 ;
if ( F_17 ( V_43 >= V_2 || V_44 >= V_2 ) )
return 0 ;
if ( F_17 ( F_30 ( V_45 ) ) )
return V_44 - V_43 ;
if ( V_43 > V_44 )
return 0 ;
for ( V_1 = ( V_43 & ~ ( V_3 * V_4 - 1 ) ) ;
V_1 < F_31 ( V_44 , ( V_3 * V_4 ) ) ;
V_1 += V_3 * V_4 )
{
unsigned V_18 = F_1 ( V_1 ) ;
unsigned long * V_20 ;
unsigned long * * V_10 ;
V_10 = V_21 [ V_18 ] ;
V_20 = V_16 [ V_18 ] ;
if ( V_10 == V_8 ) {
V_10 = F_13 ( V_15 , V_15 ) ;
F_9 ( V_10 ) ;
V_21 [ V_18 ] = V_10 ;
F_2 ( V_20 != V_9 ) ;
}
if ( V_20 == V_9 ) {
V_20 = F_13 ( V_15 , V_15 ) ;
F_10 ( V_20 ) ;
V_16 [ V_18 ] = V_20 ;
V_14 [ V_18 ] = F_7 ( V_20 ) ;
}
}
F_27 ( V_43 ) ;
F_27 ( V_44 ) ;
for ( V_1 = V_43 ; V_1 < V_44 ; V_1 ++ )
if ( ! F_32 ( V_1 , F_20 ( V_1 ) ) )
break;
if ( ! F_28 ( ( V_1 - V_43 ) != ( V_44 - V_43 ) ,
L_3 ,
( V_44 - V_43 ) - ( V_1 - V_43 ) ) )
F_33 ( V_46 L_4 , V_43 , V_1 ) ;
return V_1 - V_43 ;
}
bool F_32 ( unsigned long V_1 , unsigned long V_47 )
{
unsigned V_18 , V_19 , V_33 ;
if ( F_17 ( F_30 ( V_45 ) ) ) {
F_2 ( V_1 != V_47 && V_47 != V_13 ) ;
return true ;
}
if ( F_17 ( V_1 >= V_2 ) ) {
F_2 ( V_47 != V_13 ) ;
return true ;
}
V_18 = F_1 ( V_1 ) ;
V_19 = F_3 ( V_1 ) ;
V_33 = F_4 ( V_1 ) ;
if ( V_47 != V_13 && ( V_47 & V_48 ) ) {
if ( V_21 [ V_18 ] [ V_19 ] == V_31 )
return true ;
if ( V_21 [ V_18 ] [ V_19 ] == V_11 ) {
F_34 ( F_26 ( & V_21 [ V_18 ] [ V_19 ] , V_11 ,
V_31 ) != V_11 ) ;
return true ;
}
}
if ( V_21 [ V_18 ] [ V_19 ] == V_11 )
return V_47 == V_13 ;
V_21 [ V_18 ] [ V_19 ] [ V_33 ] = V_47 ;
return true ;
}
bool F_35 ( unsigned long V_1 , unsigned long V_47 )
{
if ( F_17 ( ! F_32 ( V_1 , V_47 ) ) ) {
if ( ! F_25 ( V_1 ) )
return false ;
if ( ! F_32 ( V_1 , V_47 ) )
return false ;
}
return true ;
}
static void T_2 F_18 ( void )
{
unsigned V_6 ;
V_49 = F_13 ( sizeof( * V_49 ) * V_50 ,
sizeof( unsigned long ) ) ;
for ( V_6 = 0 ; V_6 < V_50 ; V_6 ++ )
F_36 ( & V_49 [ V_6 ] ) ;
}
static unsigned long F_37 ( unsigned long V_47 )
{
return F_38 ( V_47 , V_51 ) ;
}
int F_39 ( unsigned long V_47 , struct V_52 * V_52 , bool V_53 )
{
unsigned long V_54 ;
unsigned long V_1 ;
unsigned long V_55 ( V_56 ) ;
unsigned V_57 ;
T_3 * V_58 = NULL ;
V_1 = F_40 ( V_52 ) ;
if ( ! F_41 ( V_52 ) ) {
V_56 = ( unsigned long ) F_42 ( V_1 << V_59 ) ;
V_58 = F_43 ( V_56 , & V_57 ) ;
if ( F_28 ( V_58 == NULL || V_57 != V_60 ,
L_5 , V_1 ) )
return - V_61 ;
}
V_52 -> V_62 = V_47 ;
V_52 -> V_63 = F_44 ( V_1 ) ;
if ( F_17 ( ! F_35 ( V_1 , F_45 ( V_47 ) ) ) )
return - V_64 ;
if ( V_53 && ! F_41 ( V_52 ) )
F_46 ( & V_65 , V_56 , V_58 ) ;
F_47 ( & V_66 , V_54 ) ;
F_48 ( & V_52 -> V_67 , & V_49 [ F_37 ( V_47 ) ] ) ;
F_49 ( & V_66 , V_54 ) ;
return 0 ;
}
int F_50 ( struct V_52 * V_52 , bool V_53 )
{
unsigned long V_54 ;
unsigned long V_47 ;
unsigned long V_1 ;
unsigned long V_55 ( V_56 ) ;
unsigned V_57 ;
T_3 * V_58 = NULL ;
V_1 = F_40 ( V_52 ) ;
V_47 = F_19 ( V_1 ) ;
if ( V_47 == V_13 || ! ( V_47 & V_68 ) )
return - V_61 ;
if ( ! F_41 ( V_52 ) ) {
V_56 = ( unsigned long ) F_42 ( V_1 << V_59 ) ;
V_58 = F_43 ( V_56 , & V_57 ) ;
if ( F_28 ( V_58 == NULL || V_57 != V_60 ,
L_6 , V_1 ) )
return - V_61 ;
}
F_47 ( & V_66 , V_54 ) ;
F_51 ( & V_52 -> V_67 ) ;
F_49 ( & V_66 , V_54 ) ;
F_35 ( V_1 , V_52 -> V_63 ) ;
if ( V_53 && ! F_41 ( V_52 ) )
F_52 ( & V_65 , V_56 , V_58 ,
F_53 ( V_1 , V_69 ) ) ;
return 0 ;
}
struct V_52 * F_54 ( unsigned long V_47 )
{
unsigned long V_54 ;
struct V_70 * V_71 = & V_49 [ F_37 ( V_47 ) ] ;
struct V_52 * V_36 , * V_72 ;
V_72 = NULL ;
F_47 ( & V_66 , V_54 ) ;
F_55 (p, bucket, lru) {
if ( V_36 -> V_62 == V_47 ) {
V_72 = V_36 ;
break;
}
}
F_49 ( & V_66 , V_54 ) ;
return V_72 ;
}
unsigned long F_56 ( unsigned long V_47 , unsigned long V_1 )
{
struct V_52 * V_36 = F_54 ( V_47 ) ;
unsigned long V_72 = V_1 ;
if ( V_36 )
V_72 = F_40 ( V_36 ) ;
return V_72 ;
}
int F_57 ( struct V_73 * V_74 , void * V_75 )
{
static const char * const V_76 [] = { L_7 , L_8 ,
L_9 , L_10 } ;
static const char * const V_77 [] = { L_11 , L_12 ,
L_13 , L_10 } ;
#define F_58 0
#define F_59 1
#define F_60 2
#define F_61 3
unsigned long V_1 , V_78 = 0 , V_79 = 0 ;
unsigned int V_55 ( V_80 ) ;
unsigned int V_55 ( V_81 ) ;
if ( ! V_21 )
return 0 ;
for ( V_1 = 0 ; V_1 < V_29 ; V_1 ++ ) {
unsigned V_18 = F_1 ( V_1 ) ;
unsigned V_19 = F_3 ( V_1 ) ;
unsigned V_33 = F_4 ( V_1 ) ;
unsigned V_82 , type ;
V_82 = 4 ;
type = F_61 ;
if ( V_21 [ V_18 ] == V_8 ) {
V_82 = 0 ; type = F_59 ;
} else if ( V_21 [ V_18 ] == NULL ) {
V_82 = 0 ; type = F_61 ;
} else if ( V_21 [ V_18 ] [ V_19 ] == NULL ) {
V_82 = 1 ; type = F_61 ;
} else if ( V_21 [ V_18 ] [ V_19 ] == V_31 ) {
V_82 = 1 ; type = F_58 ;
} else if ( V_21 [ V_18 ] [ V_19 ] == V_11 ) {
V_82 = 1 ; type = F_59 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_33 ] == 0 ) {
V_82 = 2 ; type = F_61 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_33 ] == F_20 ( V_1 ) ) {
V_82 = 2 ; type = F_58 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_33 ] == V_13 ) {
V_82 = 2 ; type = F_59 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_33 ] == V_1 ) {
V_82 = 2 ; type = F_60 ;
} else if ( V_21 [ V_18 ] [ V_19 ] [ V_33 ] != V_1 ) {
V_82 = 2 ; type = F_60 ;
}
if ( V_1 == 0 ) {
V_80 = V_82 ;
V_81 = type ;
}
if ( V_1 == V_29 - 1 ) {
V_82 = 3 ;
type = F_61 ;
}
if ( V_81 != type ) {
F_62 ( V_74 , L_14 ,
V_78 , V_1 , V_77 [ V_81 ] ) ;
V_78 = V_1 ;
V_81 = type ;
}
if ( V_80 != V_82 ) {
F_62 ( V_74 , L_15 ,
V_79 , V_1 , V_76 [ V_80 ] ) ;
V_79 = V_1 ;
V_80 = V_82 ;
}
}
return 0 ;
#undef F_58
#undef F_59
#undef F_60
#undef F_61
}
