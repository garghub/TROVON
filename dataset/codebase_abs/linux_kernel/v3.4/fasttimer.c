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
static int F_30 ( char * V_72 , char * * V_73 , T_10 V_74 , int V_75
, int * V_76 , void * V_77 )
{
unsigned long V_40 ;
int V_78 = 0 ;
int V_79 ;
struct V_1 V_2 ;
struct V_35 * V_36 , * V_80 ;
static char * V_81 = NULL ;
static unsigned long V_82 ;
if ( ! V_81 ) {
V_81 = F_31 ( V_83 ) ;
if ( ! V_81 ) {
V_82 = 0 ;
if ( V_72 )
V_72 [ 0 ] = '\0' ;
return 0 ;
}
}
if ( ! V_74 || ! V_82 ) {
F_1 ( & V_2 ) ;
V_82 = 0 ;
V_82 += sprintf ( V_81 + V_82 , L_14 ,
V_51 ) ;
V_82 += sprintf ( V_81 + V_82 , L_15 ,
V_23 ) ;
V_82 += sprintf ( V_81 + V_82 , L_16 ,
V_64 ) ;
V_82 += sprintf ( V_81 + V_82 , L_17 ,
V_68 ) ;
V_82 += sprintf ( V_81 + V_82 , L_18 ,
V_54 ) ;
V_82 += sprintf ( V_81 + V_82 , L_19 ,
V_31 ? L_20 : L_21 ) ;
V_82 += sprintf ( V_81 + V_82 , L_22 ,
( unsigned long ) V_2 . V_3 ,
( unsigned long ) V_2 . V_5 ) ;
#ifdef F_15
V_82 += sprintf ( V_81 + V_82 , L_23 ,
V_45 ) ;
#endif
V_82 += sprintf ( V_81 + V_82 , L_24 ) ;
#ifdef F_32
{
int V_84 = V_85 ;
V_78 = 0 ;
if ( V_86 )
V_78 = V_85 ;
while ( ( V_78 != V_84 || ( V_86 && ! V_82 ) ) &&
V_82 + 100 < V_83 )
{
V_82 += sprintf ( V_81 + V_82 , V_87 [ V_78 ] ,
V_88 [ V_78 ] ) ;
V_78 = ( V_78 + 1 ) % V_89 ;
}
}
V_82 += sprintf ( V_81 + V_82 , L_24 ) ;
#endif
V_79 = ( V_23 < V_24 ? V_23 :
V_24 ) ;
V_82 += sprintf ( V_81 + V_82 , L_25 , V_23 ) ;
for ( V_78 = 0 ; V_78 < V_79 && ( V_82 + 100 < V_83 ) ; V_78 ++ )
{
int V_90 = ( V_23 - V_78 - 1 ) % V_24 ;
#if 1
V_82 += sprintf ( V_81 + V_82 , L_26
L_24 ,
V_22 [ V_90 ] ,
V_25 [ V_90 ]
) ;
#endif
#ifdef F_16
V_36 = & V_53 [ V_90 ] ;
V_82 += sprintf ( V_81 + V_82 , L_27
L_28
L_24 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38
) ;
#endif
}
V_82 += sprintf ( V_81 + V_82 , L_24 ) ;
#ifdef F_16
V_79 = ( V_51 < V_24 ? V_51 :
V_24 ) ;
V_82 += sprintf ( V_81 + V_82 , L_29 , V_51 ) ;
for ( V_78 = 0 ; V_78 < V_79 && ( V_82 + 100 < V_83 ) ; V_78 ++ )
{
V_36 = & V_50 [ ( V_51 - V_78 - 1 ) % V_24 ] ;
V_82 += sprintf ( V_81 + V_82 , L_27
L_28
L_24 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38
) ;
}
V_82 += sprintf ( V_81 + V_82 , L_24 ) ;
V_79 = ( V_68 < V_24 ? V_68 :
V_24 ) ;
V_82 += sprintf ( V_81 + V_82 , L_30 , V_68 ) ;
for ( V_78 = 0 ; V_78 < V_79 && ( V_82 + 100 < V_83 ) ; V_78 ++ )
{
V_36 = & V_67 [ ( V_68 - V_78 - 1 ) % V_24 ] ;
V_82 += sprintf ( V_81 + V_82 , L_27
L_28
L_24 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38
) ;
}
V_82 += sprintf ( V_81 + V_82 , L_24 ) ;
#endif
V_82 += sprintf ( V_81 + V_82 , L_31 ) ;
F_14 ( V_40 ) ;
V_36 = V_43 ;
while ( V_36 != NULL && ( V_82 + 100 < V_83 ) )
{
V_80 = V_36 -> V_47 ;
F_18 ( V_40 ) ;
V_82 += sprintf ( V_81 + V_82 , L_27
L_28
L_24 ,
V_36 -> V_39 ,
( unsigned long ) V_36 -> V_42 . V_3 ,
( unsigned long ) V_36 -> V_42 . V_5 ,
( unsigned long ) V_36 -> V_48 . V_3 ,
( unsigned long ) V_36 -> V_48 . V_5 ,
V_36 -> V_8 ,
V_36 -> V_38
) ;
F_14 ( V_40 ) ;
if ( V_36 -> V_47 != V_80 )
{
F_9 ( L_32 ) ;
}
V_36 = V_80 ;
}
F_18 ( V_40 ) ;
}
if ( V_82 - V_74 < V_75 )
{
V_75 = V_82 - V_74 ;
}
memcpy ( V_72 , V_81 + V_74 , V_75 ) ;
* V_73 = V_72 ;
* V_76 = 1 ;
return V_75 ;
}
static void F_33 ( unsigned long V_38 )
{
F_1 ( & V_91 [ V_38 ] ) ;
V_92 [ V_38 ] = V_93 ;
V_93 ++ ;
}
static void F_34 ( unsigned long V_38 )
{
F_1 ( & V_91 [ V_38 ] ) ;
V_92 [ V_38 ] = V_93 ;
if ( V_38 < 7 )
{
F_13 ( & V_94 [ V_78 ] , F_34 , V_78 , 1000 , L_33 ) ;
V_78 ++ ;
}
V_93 ++ ;
}
static void F_35 ( void )
{
int V_95 ;
int V_96 ;
struct V_1 V_2 , V_97 , V_98 , V_99 ;
F_9 ( L_34 ) ;
F_1 ( & V_2 ) ;
for ( V_96 = 0 ; V_96 < 1000 ; V_96 ++ )
{
V_100 [ V_96 ] = F_2 () ;
}
for ( V_96 = 0 ; V_96 < 100 ; V_96 ++ )
{
F_1 ( & V_91 [ V_96 ] ) ;
}
F_9 ( V_44 L_35 , V_2 . V_3 , V_2 . V_5 ) ;
for ( V_96 = 0 ; V_96 < 1000 ; V_96 ++ )
{
F_9 ( V_44 L_36 ,
V_100 [ V_96 ] , V_100 [ V_96 + 1 ] , V_100 [ V_96 + 2 ] , V_100 [ V_96 + 3 ] , V_100 [ V_96 + 4 ] ) ;
V_96 += 4 ;
}
for ( V_96 = 0 ; V_96 < 100 ; V_96 ++ )
{
F_9 ( V_44 L_37 ,
V_91 [ V_96 ] . V_3 , V_91 [ V_96 ] . V_5 ,
V_91 [ V_96 + 1 ] . V_3 , V_91 [ V_96 + 1 ] . V_5 ,
V_91 [ V_96 + 2 ] . V_3 , V_91 [ V_96 + 2 ] . V_5 ,
V_91 [ V_96 + 3 ] . V_3 , V_91 [ V_96 + 3 ] . V_5 ,
V_91 [ V_96 + 4 ] . V_3 , V_91 [ V_96 + 4 ] . V_5 ) ;
V_96 += 4 ;
}
F_1 ( & V_97 ) ;
F_13 ( & V_94 [ V_78 ] , F_33 , V_78 , 50000 , L_38 ) ;
F_36 ( F_30 ( V_101 , NULL , 0 , 0 , 0 ) ) ;
V_78 ++ ;
F_13 ( & V_94 [ V_78 ] , F_33 , V_78 , 70000 , L_39 ) ;
F_36 ( F_30 ( V_102 , NULL , 0 , 0 , 0 ) ) ;
V_78 ++ ;
F_13 ( & V_94 [ V_78 ] , F_33 , V_78 , 40000 , L_40 ) ;
F_36 ( F_30 ( V_103 , NULL , 0 , 0 , 0 ) ) ;
V_78 ++ ;
F_13 ( & V_94 [ V_78 ] , F_33 , V_78 , 60000 , L_41 ) ;
F_36 ( F_30 ( V_104 , NULL , 0 , 0 , 0 ) ) ;
V_78 ++ ;
F_13 ( & V_94 [ V_78 ] , F_34 , V_78 , 55000 , L_42 ) ;
F_36 ( F_30 ( V_105 , NULL , 0 , 0 , 0 ) ) ;
V_78 ++ ;
F_1 ( & V_98 ) ;
F_30 ( V_106 , NULL , 0 , 0 , 0 ) ;
V_95 = V_93 ;
while ( V_93 < V_78 )
{
if ( V_93 != V_95 )
V_95 = V_93 ;
}
F_1 ( & V_99 ) ;
F_9 ( V_107 L_43 ,
V_97 . V_3 , V_97 . V_5 ) ;
F_9 ( V_107 L_44 ,
V_98 . V_3 , V_98 . V_5 ) ;
F_9 ( V_107 L_45 ,
V_99 . V_3 , V_99 . V_5 ) ;
F_36 (printk(L_46);
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
F_9 ( V_106 ) ;
F_9 ( L_52 ) ;
for( V_96 = 0 ; V_96 < V_78 ; V_96 ++ )
{
struct V_35 * V_36 = & V_94 [ V_96 ] ;
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
V_91 [ V_96 ] . V_3 ,
V_91 [ V_96 ] . V_5 ,
V_92 [ V_96 ] ,
( V_91 [ V_96 ] . V_3 - V_36 -> V_48 . V_3 ) *
1000000 + V_91 [ V_96 ] . V_5 -
V_36 -> V_48 . V_5 ) ;
}
F_30 ( V_106 , NULL , 0 , 0 , 0 ) ;
F_9 ( L_56 ) ;
F_9 ( V_106 ) ;
F_9 ( L_57 ) ;
}
int F_37 ( void )
{
if ( ! V_108 )
{
F_9 ( L_58 ) ;
#ifdef F_38
V_109 = F_39 ( L_59 , 0 , 0 ) ;
if ( V_109 )
V_109 -> V_110 = F_30 ;
#endif
if ( F_40 ( V_111 , F_22 ,
V_112 | V_113 ,
L_60 , & V_43 ) )
F_9 ( V_114 L_61 ) ;
V_108 = 1 ;
#ifdef F_41
F_9 ( L_62 ) ;
F_35 () ;
#endif
}
return 0 ;
}
