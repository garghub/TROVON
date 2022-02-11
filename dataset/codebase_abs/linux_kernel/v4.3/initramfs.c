static T_1 T_2 F_1 ( int V_1 , const char * V_2 , T_3 V_3 )
{
T_1 V_4 = 0 ;
while ( V_3 ) {
T_1 V_5 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_5 < 0 ) {
if ( V_5 == - V_6 || V_5 == - V_7 )
continue;
return V_4 ? V_4 : V_5 ;
} else if ( V_5 == 0 )
break;
V_2 += V_5 ;
V_4 += V_5 ;
V_3 -= V_5 ;
}
return V_4 ;
}
static void T_2 error ( char * V_8 )
{
if ( ! V_9 )
V_9 = V_8 ;
}
static inline int F_3 ( int V_10 , int V_11 , int V_12 )
{
unsigned long V_13 = V_12 + V_11 + ( V_10 << 3 ) ;
V_13 += V_13 >> 5 ;
return V_13 & 31 ;
}
static char T_2 * F_4 ( int V_10 , int V_11 , int V_12 ,
T_4 V_14 , char * V_15 )
{
struct F_3 * * V_2 , * V_16 ;
for ( V_2 = V_17 + F_3 ( V_10 , V_11 , V_12 ) ; * V_2 ; V_2 = & ( * V_2 ) -> V_18 ) {
if ( ( * V_2 ) -> V_12 != V_12 )
continue;
if ( ( * V_2 ) -> V_11 != V_11 )
continue;
if ( ( * V_2 ) -> V_10 != V_10 )
continue;
if ( ( ( * V_2 ) -> V_14 ^ V_14 ) & V_19 )
continue;
return ( * V_2 ) -> V_15 ;
}
V_16 = F_5 ( sizeof( struct F_3 ) , V_20 ) ;
if ( ! V_16 )
F_6 ( L_1 ) ;
V_16 -> V_10 = V_10 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_12 = V_12 ;
V_16 -> V_14 = V_14 ;
strcpy ( V_16 -> V_15 , V_15 ) ;
V_16 -> V_18 = NULL ;
* V_2 = V_16 ;
return NULL ;
}
static void T_2 F_7 ( void )
{
struct F_3 * * V_2 , * V_16 ;
for ( V_2 = V_17 ; V_2 < V_17 + 32 ; V_2 ++ ) {
while ( * V_2 ) {
V_16 = * V_2 ;
* V_2 = V_16 -> V_18 ;
F_8 ( V_16 ) ;
}
}
}
static long T_2 F_9 ( char * V_21 , T_5 V_22 )
{
struct V_23 V_24 [ 2 ] ;
V_24 [ 0 ] . V_25 = V_22 ;
V_24 [ 0 ] . V_26 = 0 ;
V_24 [ 1 ] . V_25 = V_22 ;
V_24 [ 1 ] . V_26 = 0 ;
return F_10 ( V_27 , V_21 , V_24 , V_28 ) ;
}
static void T_2 F_11 ( const char * V_15 , T_5 V_22 )
{
struct V_29 * V_30 = F_5 ( sizeof( struct V_29 ) , V_20 ) ;
if ( ! V_30 )
F_6 ( L_2 ) ;
F_12 ( & V_30 -> V_31 ) ;
V_30 -> V_15 = F_13 ( V_15 , V_20 ) ;
V_30 -> V_22 = V_22 ;
F_14 ( & V_30 -> V_31 , & V_32 ) ;
}
static void T_2 F_15 ( void )
{
struct V_29 * V_30 , * V_13 ;
F_16 (de, tmp, &dir_list, list) {
F_17 ( & V_30 -> V_31 ) ;
F_9 ( V_30 -> V_15 , V_30 -> V_22 ) ;
F_8 ( V_30 -> V_15 ) ;
F_8 ( V_30 ) ;
}
}
static void T_2 F_18 ( char * V_33 )
{
unsigned long V_34 [ 12 ] ;
char V_35 [ 9 ] ;
int V_36 ;
V_35 [ 8 ] = '\0' ;
for ( V_36 = 0 , V_33 += 6 ; V_36 < 12 ; V_36 ++ , V_33 += 8 ) {
memcpy ( V_35 , V_33 , 8 ) ;
V_34 [ V_36 ] = F_19 ( V_35 , NULL , 16 ) ;
}
V_12 = V_34 [ 0 ] ;
V_14 = V_34 [ 1 ] ;
V_37 = V_34 [ 2 ] ;
V_38 = V_34 [ 3 ] ;
V_39 = V_34 [ 4 ] ;
V_22 = V_34 [ 5 ] ;
V_40 = V_34 [ 6 ] ;
V_10 = V_34 [ 7 ] ;
V_11 = V_34 [ 8 ] ;
V_41 = F_20 ( F_21 ( V_34 [ 9 ] , V_34 [ 10 ] ) ) ;
V_42 = V_34 [ 11 ] ;
}
static inline void T_2 F_22 ( unsigned V_43 )
{
V_44 += V_43 ;
V_45 += V_43 ;
V_46 -= V_43 ;
}
static void T_2 F_23 ( char * V_35 , unsigned V_47 , enum V_48 V_18 )
{
if ( V_46 >= V_47 ) {
V_49 = V_44 ;
F_22 ( V_47 ) ;
V_48 = V_18 ;
} else {
V_50 = V_49 = V_35 ;
V_51 = V_47 ;
V_52 = V_18 ;
V_48 = V_53 ;
}
}
static int T_2 F_24 ( void )
{
F_23 ( V_54 , 110 , V_55 ) ;
return 0 ;
}
static int T_2 F_25 ( void )
{
unsigned long V_43 = V_51 ;
if ( V_46 < V_43 )
V_43 = V_46 ;
memcpy ( V_50 , V_44 , V_43 ) ;
F_22 ( V_43 ) ;
V_50 += V_43 ;
if ( ( V_51 -= V_43 ) != 0 )
return 1 ;
V_48 = V_52 ;
return 0 ;
}
static int T_2 F_26 ( void )
{
if ( memcmp ( V_49 , L_3 , 6 ) == 0 ) {
error ( L_4 ) ;
return 1 ;
}
if ( memcmp ( V_49 , L_5 , 6 ) ) {
error ( L_6 ) ;
return 1 ;
}
F_18 ( V_49 ) ;
V_56 = V_45 + F_27 ( V_42 ) + V_40 ;
V_56 = ( V_56 + 3 ) & ~ 3 ;
V_48 = V_57 ;
if ( V_42 <= 0 || V_42 > V_58 )
return 0 ;
if ( F_28 ( V_14 ) ) {
if ( V_40 > V_58 )
return 0 ;
V_50 = V_49 = V_59 ;
V_51 = F_27 ( V_42 ) + V_40 ;
V_52 = V_60 ;
V_48 = V_53 ;
return 0 ;
}
if ( F_29 ( V_14 ) || ! V_40 )
F_23 ( V_61 , F_27 ( V_42 ) , V_62 ) ;
return 0 ;
}
static int T_2 F_30 ( void )
{
if ( V_45 + V_46 < V_56 ) {
F_22 ( V_46 ) ;
return 1 ;
} else {
F_22 ( V_56 - V_45 ) ;
V_48 = V_52 ;
return 0 ;
}
}
static int T_2 F_31 ( void )
{
while ( V_46 && * V_44 == '\0' )
F_22 ( 1 ) ;
if ( V_46 && ( V_45 & 3 ) )
error ( L_7 ) ;
return 1 ;
}
static int T_2 F_32 ( void )
{
if ( V_39 >= 2 ) {
char * V_63 = F_4 ( V_10 , V_11 , V_12 , V_14 , V_49 ) ;
if ( V_63 )
return ( F_33 ( V_63 , V_49 ) < 0 ) ? - 1 : 1 ;
}
return 0 ;
}
static void T_2 F_34 ( char * V_64 , T_4 V_65 )
{
struct V_66 V_67 ;
if ( ! F_35 ( V_64 , & V_67 ) && ( V_67 . V_68 ^ V_65 ) & V_19 ) {
if ( F_36 ( V_67 . V_68 ) )
F_37 ( V_64 ) ;
else
F_38 ( V_64 ) ;
}
}
static int T_2 F_39 ( void )
{
V_48 = V_57 ;
V_52 = V_69 ;
if ( strcmp ( V_49 , L_8 ) == 0 ) {
F_7 () ;
return 0 ;
}
F_34 ( V_49 , V_14 ) ;
if ( F_29 ( V_14 ) ) {
int V_70 = F_32 () ;
if ( V_70 >= 0 ) {
int V_71 = V_72 | V_73 ;
if ( V_70 != 1 )
V_71 |= V_74 ;
V_75 = F_40 ( V_49 , V_71 , V_14 ) ;
if ( V_75 >= 0 ) {
F_41 ( V_75 , V_37 , V_38 ) ;
F_42 ( V_75 , V_14 ) ;
if ( V_40 )
F_43 ( V_75 , V_40 ) ;
V_76 = F_13 ( V_49 , V_20 ) ;
V_48 = V_77 ;
}
}
} else if ( F_36 ( V_14 ) ) {
F_44 ( V_49 , V_14 ) ;
F_45 ( V_49 , V_37 , V_38 ) ;
F_46 ( V_49 , V_14 ) ;
F_11 ( V_49 , V_22 ) ;
} else if ( F_47 ( V_14 ) || F_48 ( V_14 ) ||
F_49 ( V_14 ) || F_50 ( V_14 ) ) {
if ( F_32 () == 0 ) {
F_51 ( V_49 , V_14 , V_41 ) ;
F_45 ( V_49 , V_37 , V_38 ) ;
F_46 ( V_49 , V_14 ) ;
F_9 ( V_49 , V_22 ) ;
}
}
return 0 ;
}
static int T_2 F_52 ( void )
{
if ( V_46 >= V_40 ) {
if ( F_1 ( V_75 , V_44 , V_40 ) != V_40 )
error ( L_9 ) ;
F_53 ( V_75 ) ;
F_9 ( V_76 , V_22 ) ;
F_8 ( V_76 ) ;
F_22 ( V_40 ) ;
V_48 = V_57 ;
return 0 ;
} else {
if ( F_1 ( V_75 , V_44 , V_46 ) != V_46 )
error ( L_9 ) ;
V_40 -= V_46 ;
F_22 ( V_46 ) ;
return 1 ;
}
}
static int T_2 F_54 ( void )
{
V_49 [ F_27 ( V_42 ) + V_40 ] = '\0' ;
F_34 ( V_49 , 0 ) ;
F_55 ( V_49 + F_27 ( V_42 ) , V_49 ) ;
F_56 ( V_49 , V_37 , V_38 ) ;
F_9 ( V_49 , V_22 ) ;
V_48 = V_57 ;
V_52 = V_69 ;
return 0 ;
}
static long T_2 F_57 ( char * V_35 , unsigned long V_78 )
{
V_46 = V_78 ;
V_44 = V_35 ;
while ( ! V_79 [ V_48 ] ( ) )
;
return V_78 - V_46 ;
}
static long T_2 F_58 ( void * V_80 , unsigned long V_78 )
{
char * V_35 = ( char * ) V_80 ;
long V_81 ;
long V_82 = V_78 ;
if ( V_9 )
return - 1 ;
while ( ( V_81 = F_57 ( V_35 , V_78 ) ) < V_78 && ! V_9 ) {
char V_83 = V_35 [ V_81 ] ;
if ( V_83 == '0' ) {
V_35 += V_81 ;
V_78 -= V_81 ;
V_48 = V_84 ;
} else if ( V_83 == 0 ) {
V_35 += V_81 ;
V_78 -= V_81 ;
V_48 = V_69 ;
} else
error ( L_10 ) ;
}
return V_82 ;
}
static char * T_2 F_59 ( char * V_35 , unsigned long V_78 )
{
long V_81 ;
T_6 V_85 ;
const char * V_86 ;
static T_7 char V_87 [ 64 ] ;
V_54 = F_5 ( 110 , V_20 ) ;
V_59 = F_5 ( V_58 + F_27 ( V_58 ) + 1 , V_20 ) ;
V_61 = F_5 ( F_27 ( V_58 ) , V_20 ) ;
if ( ! V_54 || ! V_59 || ! V_61 )
F_6 ( L_11 ) ;
V_48 = V_84 ;
V_45 = 0 ;
V_9 = NULL ;
while ( ! V_9 && V_78 ) {
T_8 V_88 = V_45 ;
if ( * V_35 == '0' && ! ( V_45 & 3 ) ) {
V_48 = V_84 ;
V_81 = F_57 ( V_35 , V_78 ) ;
V_35 += V_81 ;
V_78 -= V_81 ;
continue;
}
if ( ! * V_35 ) {
V_35 ++ ;
V_78 -- ;
V_45 ++ ;
continue;
}
V_45 = 0 ;
V_85 = F_60 ( V_35 , V_78 , & V_86 ) ;
F_61 ( L_12 , V_86 ) ;
if ( V_85 ) {
int V_89 = V_85 ( V_35 , V_78 , NULL , F_58 , NULL ,
& V_90 , error ) ;
if ( V_89 )
error ( L_13 ) ;
} else if ( V_86 ) {
if ( ! V_9 ) {
snprintf ( V_87 , sizeof V_87 ,
L_14 ,
V_86 ) ;
V_9 = V_87 ;
}
} else
error ( L_10 ) ;
if ( V_48 != V_69 )
error ( L_10 ) ;
V_45 = V_88 + V_90 ;
V_35 += V_90 ;
V_78 -= V_90 ;
}
F_15 () ;
F_8 ( V_61 ) ;
F_8 ( V_59 ) ;
F_8 ( V_54 ) ;
return V_9 ;
}
static int T_2 F_62 ( char * V_91 )
{
if ( * V_91 )
return 0 ;
V_92 = 1 ;
return 1 ;
}
static void T_2 F_63 ( void )
{
#ifdef F_64
unsigned long V_93 = ( unsigned long ) F_65 ( V_94 . V_95 ) ;
unsigned long V_96 = ( unsigned long ) F_65 ( V_94 . V_97 ) ;
#endif
if ( V_92 )
goto V_98;
#ifdef F_64
if ( V_99 < V_96 && V_100 > V_93 ) {
memset ( ( void * ) V_99 , 0 , V_100 - V_99 ) ;
if ( V_99 < V_93 )
F_66 ( V_99 , V_93 ) ;
if ( V_100 > V_96 )
F_66 ( V_96 , V_100 ) ;
} else
#endif
F_66 ( V_99 , V_100 ) ;
V_98:
V_99 = 0 ;
V_100 = 0 ;
}
static void T_2 F_67 ( void )
{
int V_1 ;
void * V_35 ;
struct V_101 * V_102 ;
int V_103 ;
V_1 = F_40 ( L_15 , V_104 , 0 ) ;
F_68 ( V_1 < 0 ) ;
if ( V_1 < 0 )
return;
V_35 = F_69 ( V_105 , V_20 ) ;
F_68 ( ! V_35 ) ;
if ( ! V_35 ) {
F_53 ( V_1 ) ;
return;
}
V_102 = V_35 ;
V_103 = F_70 ( V_1 , V_102 , V_105 ) ;
while ( V_103 > 0 ) {
while ( V_103 > 0 ) {
struct V_66 V_67 ;
int V_106 ;
V_106 = F_35 ( V_102 -> V_107 , & V_67 ) ;
F_71 ( V_106 ) ;
if ( ! V_106 ) {
if ( F_36 ( V_67 . V_68 ) )
F_37 ( V_102 -> V_107 ) ;
else
F_38 ( V_102 -> V_107 ) ;
}
V_103 -= V_102 -> V_108 ;
V_102 = ( void * ) V_102 + V_102 -> V_108 ;
}
V_102 = V_35 ;
memset ( V_35 , 0 , V_105 ) ;
V_103 = F_70 ( V_1 , V_102 , V_105 ) ;
}
F_53 ( V_1 ) ;
F_8 ( V_35 ) ;
}
static int T_2 F_72 ( void )
{
char * V_109 = F_59 ( V_110 , V_111 ) ;
if ( V_109 )
F_6 ( L_16 , V_109 ) ;
if ( V_99 ) {
#ifdef F_73
int V_1 ;
F_74 ( V_112 L_17 ) ;
V_109 = F_59 ( ( char * ) V_99 ,
V_100 - V_99 ) ;
if ( ! V_109 ) {
F_63 () ;
goto V_113;
} else {
F_67 () ;
F_59 ( V_110 , V_111 ) ;
}
F_74 ( V_112 L_18
L_19 , V_109 ) ;
V_1 = F_40 ( L_20 ,
V_72 | V_73 , 0700 ) ;
if ( V_1 >= 0 ) {
T_1 V_81 = F_1 ( V_1 , ( char * ) V_99 ,
V_100 - V_99 ) ;
if ( V_81 != V_100 - V_99 )
F_75 ( L_21 ,
V_81 , V_100 - V_99 ) ;
F_53 ( V_1 ) ;
F_63 () ;
}
V_113:
#else
F_74 ( V_112 L_22 ) ;
V_109 = F_59 ( ( char * ) V_99 ,
V_100 - V_99 ) ;
if ( V_109 )
F_74 ( V_114 L_23 , V_109 ) ;
F_63 () ;
#endif
F_76 () ;
}
return 0 ;
}
