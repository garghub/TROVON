inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
V_2 -> V_5 = F_2 () ;
}
inline int F_3 ( struct V_1 * V_6 , struct V_1 * V_7 )
{
if ( F_4 ( V_6 -> V_3 , V_7 -> V_3 ) )
return - 1 ;
else if ( F_5 ( V_6 -> V_3 , V_7 -> V_3 ) )
return 1 ;
if ( V_6 -> V_5 < V_7 -> V_5 )
return - 1 ;
else if ( V_6 -> V_5 > V_7 -> V_5 )
return 1 ;
return 0 ;
}
inline void F_6 ( unsigned long V_8 )
{
T_1 V_9 = { 0 } ;
T_2 V_10 ;
T_3 V_11 ;
T_4 V_12 = { 0 } ;
T_5 V_13 ;
T_5 V_14 ;
unsigned char V_15 ;
unsigned char V_16 ;
V_13 = F_7 ( V_17 , V_18 , V_19 ) ;
F_8 ( F_9 ( L_1 ,
V_8 , V_20 , div ) ) ;
V_10 = F_7 ( V_17 , V_18 , V_21 ) ;
V_10 . V_11 = 0 ;
F_10 ( V_17 , V_18 , V_21 , V_10 ) ;
V_15 = ( V_11 = V_13 + V_8 * ( 1000 / 10 ) ) < V_13 ;
V_22 [ V_23 % V_24 ] = V_11 ;
V_25 [ V_23 % V_24 ] = V_8 ;
V_9 . V_11 = 1 ;
F_10 ( V_17 , V_18 , V_26 , V_9 ) ;
F_10 ( V_17 , V_18 , V_27 , V_11 ) ;
V_12 . V_28 = V_29 ;
F_10 ( V_17 , V_18 , V_30 , V_12 ) ;
V_14 = F_7 ( V_17 , V_18 , V_19 ) ;
V_16 = V_14 < V_13 ;
if ( ( V_15 && ! V_16 ) || ( V_14 < V_11 ) ) {
V_10 = F_7 ( V_17 , V_18 , V_21 ) ;
V_10 . V_11 = 1 ;
F_10 ( V_17 , V_18 , V_21 , V_10 ) ;
V_23 ++ ;
V_31 = 1 ;
} else {
V_12 . V_28 = V_32 ;
F_10 ( V_17 , V_18 , V_30 , V_12 ) ;
F_10 ( V_17 , V_18 , V_26 , V_9 ) ;
F_11 ( & V_33 , V_34 ) ;
F_12 ( & V_33 ) ;
}
}
void F_13 ( struct V_35 * V_36 ,
T_6 * V_37 ,
unsigned long V_38 ,
unsigned long V_8 ,
const char * V_39 )
{
unsigned long V_40 ;
struct V_35 * V_41 ;
F_8 ( F_9 ( L_2 , V_39 , V_8 ) ) ;
F_14 ( V_40 ) ;
F_1 ( & V_36 -> V_42 ) ;
V_41 = V_43 ;
#ifdef F_15
while ( V_41 != NULL ) {
if ( V_41 == V_36 ) {
F_9 ( V_44
L_3
L_4 , V_39 , V_38 ) ;
V_45 ++ ;
goto V_46;
} else
V_41 = V_41 -> V_47 ;
}
V_41 = V_43 ;
#endif
V_36 -> V_8 = V_8 ;
V_36 -> V_37 = V_37 ;
V_36 -> V_38 = V_38 ;
V_36 -> V_39 = V_39 ;
V_36 -> V_48 . V_5 = V_36 -> V_42 . V_5 + V_8 % 1000000 ;
V_36 -> V_48 . V_3 = V_36 -> V_42 . V_3 + V_8 / 1000000 / V_49 ;
if ( V_36 -> V_48 . V_5 > 1000000 ) {
V_36 -> V_48 . V_5 -= 1000000 ;
V_36 -> V_48 . V_3 += V_49 ;
}
#ifdef F_16
V_50 [ V_51 % V_24 ] = * V_36 ;
#endif
V_51 ++ ;
if ( V_41 == NULL || F_3 ( & V_36 -> V_48 , & V_41 -> V_48 ) < 0 ) {
V_36 -> V_52 = NULL ;
V_36 -> V_47 = V_43 ;
if ( V_43 )
V_43 -> V_52 = V_36 ;
V_43 = V_36 ;
#ifdef F_16
V_53 [ V_23 % V_24 ] = * V_36 ;
#endif
F_6 ( V_8 ) ;
} else {
while ( V_41 -> V_47 &&
F_3 ( & V_36 -> V_48 , & V_41 -> V_47 -> V_48 ) > 0 )
V_41 = V_41 -> V_47 ;
V_36 -> V_52 = V_41 ;
V_36 -> V_47 = V_41 -> V_47 ;
if ( V_41 -> V_47 )
{
V_41 -> V_47 -> V_52 = V_36 ;
}
V_41 -> V_47 = V_36 ;
}
F_17 ( F_9 ( L_5 , V_8 ) ) ;
V_46:
F_18 ( V_40 ) ;
}
static inline int F_19 ( const struct V_35 * V_36 )
{
return ( V_36 -> V_47 != NULL ) || ( V_36 -> V_52 != NULL ) || ( V_36 == V_43 ) ;
}
static inline int F_20 ( struct V_35 * V_36 )
{
struct V_35 * V_47 , * V_52 ;
if ( ! F_19 ( V_36 ) )
return 0 ;
V_47 = V_36 -> V_47 ;
V_52 = V_36 -> V_52 ;
if ( V_47 )
V_47 -> V_52 = V_52 ;
if ( V_52 )
V_52 -> V_47 = V_47 ;
else
V_43 = V_47 ;
V_54 ++ ;
return 1 ;
}
int F_21 ( struct V_35 * V_36 )
{
unsigned long V_40 ;
int V_55 ;
F_14 ( V_40 ) ;
V_55 = F_20 ( V_36 ) ;
V_36 -> V_47 = V_36 -> V_52 = NULL ;
F_18 ( V_40 ) ;
return V_55 ;
}
static T_7
F_22 ( int V_56 , void * V_57 )
{
T_8 V_58 ;
V_58 = F_7 ( V_17 , V_18 , V_59 ) ;
if ( ! V_58 . V_11 )
return V_60 ;
V_34 ( NULL ) ;
return V_61 ;
}
static void V_34 ( struct V_62 * V_63 )
{
T_1 V_9 = { 0 } ;
T_2 V_10 ;
T_4 V_12 = { 0 } ;
struct V_35 * V_36 ;
unsigned long V_40 ;
F_14 ( V_40 ) ;
V_10 = F_7 ( V_17 , V_18 , V_21 ) ;
V_10 . V_11 = 0 ;
F_10 ( V_17 , V_18 , V_21 , V_10 ) ;
V_12 . V_28 = V_32 ;
F_10 ( V_17 , V_18 , V_30 , V_12 ) ;
V_9 . V_11 = 1 ;
F_10 ( V_17 , V_18 , V_26 , V_9 ) ;
V_31 = 0 ;
V_64 ++ ;
T_6 * V_65 ;
unsigned long V_66 ;
V_36 = V_43 ;
while ( V_36 ) {
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
F_8 ( F_9 ( V_44
L_6 , V_2 . V_3 , V_2 . V_5 ) ) ;
if ( F_3 ( & V_36 -> V_48 , & V_2 ) <= 0 ) {
#ifdef F_16
V_67 [ V_68 % V_24 ] = * V_36 ;
#endif
V_68 ++ ;
if ( V_36 -> V_52 )
V_36 -> V_52 -> V_47 = V_36 -> V_47 ;
else
V_43 = V_36 -> V_47 ;
if ( V_36 -> V_47 )
V_36 -> V_47 -> V_52 = V_36 -> V_52 ;
V_36 -> V_52 = NULL ;
V_36 -> V_47 = NULL ;
V_65 = V_36 -> V_37 ;
V_66 = V_36 -> V_38 ;
if ( V_65 != NULL ) {
F_18 ( V_40 ) ;
V_65 ( V_66 ) ;
F_14 ( V_40 ) ;
} else
F_23 ( L_7 , V_64 ) ;
} else {
F_8 ( F_9 ( L_8 ) ) ;
}
V_36 = V_43 ;
if ( V_36 != NULL ) {
long V_69 = 0 ;
struct V_1 V_2 ;
F_1 ( & V_2 ) ;
if ( F_24 ( V_36 -> V_48 . V_3 , V_2 . V_3 ) )
V_69 = ( ( V_36 -> V_48 . V_3 - V_2 . V_3 ) *
1000000 / V_49 + V_36 -> V_48 . V_5 -
V_2 . V_5 ) ;
if ( V_69 > 0 ) {
if ( ! V_31 ) {
#ifdef F_16
V_53 [ V_23 % V_24 ] = * V_36 ;
#endif
F_6 ( V_69 ) ;
}
break;
} else {
F_8 ( F_9 ( L_9 , V_69 ) ) ;
}
}
}
F_18 ( V_40 ) ;
if ( ! V_36 )
F_8 ( F_9 ( L_10 ) ) ;
}
static void F_25 ( unsigned long V_38 )
{
T_9 * V_70 = ( T_9 * ) V_38 ;
F_26 ( V_70 ) ;
}
void F_27 ( unsigned long V_69 )
{
struct V_35 V_36 ;
T_9 V_71 ;
F_28 ( & V_71 ) ;
F_8 ( F_9 ( L_11 , V_69 ) ) ;
F_13 ( & V_36 , F_25 , ( unsigned long ) & V_71 , V_69 ,
L_12 ) ;
F_29 ( V_71 , ! F_19 ( & V_36 ) ) ;
F_8 ( F_9 ( L_13 , V_69 ) ) ;
}
static int F_30 ( struct V_72 * V_73 , void * V_74 )
{
unsigned long V_40 ;
int V_75 = 0 ;
int V_76 ;
struct V_1 V_2 ;
struct V_35 * V_36 , * V_77 ;
F_1 ( & V_2 ) ;
F_31 ( V_73 , L_14 , V_51 ) ;
F_31 ( V_73 , L_15 , V_23 ) ;
F_31 ( V_73 , L_16 , V_64 ) ;
F_31 ( V_73 , L_17 , V_68 ) ;
F_31 ( V_73 , L_18 , V_54 ) ;
F_31 ( V_73 , L_19 ,
V_31 ? L_20 : L_21 ) ;
F_31 ( V_73 , L_22 ,
( unsigned long ) V_2 . V_3 ,
( unsigned long ) V_2 . V_5 ) ;
#ifdef F_15
F_31 ( V_73 , L_23 , V_45 ) ;
#endif
F_32 ( V_73 , '\n' ) ;
#ifdef F_33
{
int V_78 = V_79 ;
V_75 = 0 ;
if ( V_80 )
V_75 = V_79 ;
while ( ( V_75 != V_78 || V_80 ) ) {
if ( F_31 ( V_73 , V_81 [ V_75 ] , V_82 [ V_75 ] ) < 0 )
return 0 ;
V_75 = ( V_75 + 1 ) % V_83 ;
}
}
F_32 ( V_73 , '\n' ) ;
#endif
V_76 = ( V_23 < V_24 ? V_23 :
V_24 ) ;
F_31 ( V_73 , L_24 , V_23 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
int V_84 = ( V_23 - V_75 - 1 ) % V_24 ;
#if 1
F_31 ( V_73 , L_25
L_26 ,
V_22 [ V_84 ] ,
V_25 [ V_84 ] ) ;
#endif
#ifdef F_16
V_36 = & V_53 [ V_84 ] ;
if ( F_31 ( V_73 , L_27
L_28
L_26 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38 ) < 0 )
return 0 ;
#endif
}
F_32 ( V_73 , '\n' ) ;
#ifdef F_16
V_76 = ( V_51 < V_24 ? V_51 :
V_24 ) ;
F_31 ( V_73 , L_29 , V_51 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
V_36 = & V_50 [ ( V_51 - V_75 - 1 ) % V_24 ] ;
if ( F_31 ( V_73 , L_27
L_28
L_26 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38 ) < 0 )
return 0 ;
}
F_32 ( V_73 , '\n' ) ;
V_76 = ( V_68 < V_24 ? V_68 :
V_24 ) ;
F_31 ( V_73 , L_30 , V_68 ) ;
for ( V_75 = 0 ; V_75 < V_76 ; V_75 ++ ) {
V_36 = & V_67 [ ( V_68 - V_75 - 1 ) % V_24 ] ;
if ( F_31 ( V_73 , L_27
L_28
L_26 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38 ) < 0 )
return 0 ;
}
F_32 ( V_73 , '\n' ) ;
#endif
F_34 ( V_73 , L_31 ) ;
F_14 ( V_40 ) ;
V_36 = V_43 ;
while ( V_36 != NULL ) {
V_77 = V_36 -> V_47 ;
F_18 ( V_40 ) ;
if ( F_31 ( V_73 , L_27
L_28
L_26 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38
) < 0 )
return 0 ;
F_14 ( V_40 ) ;
if ( V_36 -> V_47 != V_77 )
F_9 ( L_32 ) ;
V_36 = V_77 ;
}
F_18 ( V_40 ) ;
return 0 ;
}
static int F_35 ( struct V_85 * V_85 , struct V_86 * V_86 )
{
return F_36 ( V_86 , F_30 , F_37 ( V_85 ) , V_87 ) ;
}
static void F_38 ( unsigned long V_38 )
{
F_1 ( & V_88 [ V_38 ] ) ;
V_89 [ V_38 ] = V_90 ;
V_90 ++ ;
}
static void F_39 ( unsigned long V_38 )
{
F_1 ( & V_88 [ V_38 ] ) ;
V_89 [ V_38 ] = V_90 ;
if ( V_38 < 7 )
{
F_13 ( & V_91 [ V_75 ] , F_39 , V_75 , 1000 , L_33 ) ;
V_75 ++ ;
}
V_90 ++ ;
}
static void F_40 ( void )
{
int V_92 ;
int V_93 ;
struct V_1 V_2 , V_94 , V_95 , V_96 ;
F_9 ( L_34 ) ;
F_1 ( & V_2 ) ;
for ( V_93 = 0 ; V_93 < 1000 ; V_93 ++ )
{
V_97 [ V_93 ] = F_2 () ;
}
for ( V_93 = 0 ; V_93 < 100 ; V_93 ++ )
{
F_1 ( & V_88 [ V_93 ] ) ;
}
F_9 ( V_44 L_35 , V_2 . V_3 , V_2 . V_5 ) ;
for ( V_93 = 0 ; V_93 < 1000 ; V_93 ++ )
{
F_9 ( V_44 L_36 ,
V_97 [ V_93 ] , V_97 [ V_93 + 1 ] , V_97 [ V_93 + 2 ] , V_97 [ V_93 + 3 ] , V_97 [ V_93 + 4 ] ) ;
V_93 += 4 ;
}
for ( V_93 = 0 ; V_93 < 100 ; V_93 ++ )
{
F_9 ( V_44 L_37 ,
V_88 [ V_93 ] . V_3 , V_88 [ V_93 ] . V_5 ,
V_88 [ V_93 + 1 ] . V_3 , V_88 [ V_93 + 1 ] . V_5 ,
V_88 [ V_93 + 2 ] . V_3 , V_88 [ V_93 + 2 ] . V_5 ,
V_88 [ V_93 + 3 ] . V_3 , V_88 [ V_93 + 3 ] . V_5 ,
V_88 [ V_93 + 4 ] . V_3 , V_88 [ V_93 + 4 ] . V_5 ) ;
V_93 += 4 ;
}
F_1 ( & V_94 ) ;
F_13 ( & V_91 [ V_75 ] , F_38 , V_75 , 50000 , L_38 ) ;
F_41 ( F_42 ( V_98 , NULL , 0 , 0 , 0 ) ) ;
V_75 ++ ;
F_13 ( & V_91 [ V_75 ] , F_38 , V_75 , 70000 , L_39 ) ;
F_41 ( F_42 ( V_99 , NULL , 0 , 0 , 0 ) ) ;
V_75 ++ ;
F_13 ( & V_91 [ V_75 ] , F_38 , V_75 , 40000 , L_40 ) ;
F_41 ( F_42 ( V_100 , NULL , 0 , 0 , 0 ) ) ;
V_75 ++ ;
F_13 ( & V_91 [ V_75 ] , F_38 , V_75 , 60000 , L_41 ) ;
F_41 ( F_42 ( V_101 , NULL , 0 , 0 , 0 ) ) ;
V_75 ++ ;
F_13 ( & V_91 [ V_75 ] , F_39 , V_75 , 55000 , L_42 ) ;
F_41 ( F_42 ( V_102 , NULL , 0 , 0 , 0 ) ) ;
V_75 ++ ;
F_1 ( & V_95 ) ;
F_42 ( V_103 , NULL , 0 , 0 , 0 ) ;
V_92 = V_90 ;
while ( V_90 < V_75 )
{
if ( V_90 != V_92 )
V_92 = V_90 ;
}
F_1 ( & V_96 ) ;
F_9 ( V_104 L_43 ,
V_94 . V_3 , V_94 . V_5 ) ;
F_9 ( V_104 L_44 ,
V_95 . V_3 , V_95 . V_5 ) ;
F_9 ( V_104 L_45 ,
V_96 . V_3 , V_96 . V_5 ) ;
F_41 (printk(L_46);
printk(buf0);
printk(L_47);
printk(buf1);
printk(L_48);
printk(buf2);
printk(L_49);
printk(buf3);
printk(L_50);
printk(buf4);
) ;
F_9 ( L_51 ) ;
F_9 ( V_103 ) ;
F_9 ( L_52 ) ;
for( V_93 = 0 ; V_93 < V_75 ; V_93 ++ )
{
struct V_35 * V_36 = & V_91 [ V_93 ] ;
F_9 ( L_53
L_54 ,
V_36 -> V_39 ,
V_36 -> V_42 . V_3 ,
V_36 -> V_42 . V_5 ,
V_36 -> V_48 . V_3 ,
V_36 -> V_48 . V_5 ,
V_36 -> V_38 ,
V_36 -> V_37
) ;
F_9 ( L_55 ,
V_36 -> V_8 ,
V_88 [ V_93 ] . V_3 ,
V_88 [ V_93 ] . V_5 ,
V_89 [ V_93 ] ,
( V_88 [ V_93 ] . V_3 - V_36 -> V_48 . V_3 ) *
1000000 + V_88 [ V_93 ] . V_5 -
V_36 -> V_48 . V_5 ) ;
}
F_42 ( V_103 , NULL , 0 , 0 , 0 ) ;
F_9 ( L_56 ) ;
F_9 ( V_103 ) ;
F_9 ( L_57 ) ;
}
int F_43 ( void )
{
if ( ! V_105 )
{
F_9 ( L_58 ) ;
#ifdef F_44
F_45 ( L_59 , 0 , NULL , & V_106 ) ;
#endif
if ( F_46 ( V_107 , F_22 ,
V_108 ,
L_60 , & V_43 ) )
F_9 ( V_109 L_61 ) ;
V_105 = 1 ;
#ifdef F_47
F_9 ( L_62 ) ;
F_40 () ;
#endif
}
return 0 ;
}
