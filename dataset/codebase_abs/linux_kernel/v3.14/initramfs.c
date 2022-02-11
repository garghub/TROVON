static void T_1 error ( char * V_1 )
{
if ( ! V_2 )
V_2 = V_1 ;
}
static inline int F_1 ( int V_3 , int V_4 , int V_5 )
{
unsigned long V_6 = V_5 + V_4 + ( V_3 << 3 ) ;
V_6 += V_6 >> 5 ;
return V_6 & 31 ;
}
static char T_1 * F_2 ( int V_3 , int V_4 , int V_5 ,
T_2 V_7 , char * V_8 )
{
struct F_1 * * V_9 , * V_10 ;
for ( V_9 = V_11 + F_1 ( V_3 , V_4 , V_5 ) ; * V_9 ; V_9 = & ( * V_9 ) -> V_12 ) {
if ( ( * V_9 ) -> V_5 != V_5 )
continue;
if ( ( * V_9 ) -> V_4 != V_4 )
continue;
if ( ( * V_9 ) -> V_3 != V_3 )
continue;
if ( ( ( * V_9 ) -> V_7 ^ V_7 ) & V_13 )
continue;
return ( * V_9 ) -> V_8 ;
}
V_10 = F_3 ( sizeof( struct F_1 ) , V_14 ) ;
if ( ! V_10 )
F_4 ( L_1 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_4 = V_4 ;
V_10 -> V_5 = V_5 ;
V_10 -> V_7 = V_7 ;
strcpy ( V_10 -> V_8 , V_8 ) ;
V_10 -> V_12 = NULL ;
* V_9 = V_10 ;
return NULL ;
}
static void T_1 F_5 ( void )
{
struct F_1 * * V_9 , * V_10 ;
for ( V_9 = V_11 ; V_9 < V_11 + 32 ; V_9 ++ ) {
while ( * V_9 ) {
V_10 = * V_9 ;
* V_9 = V_10 -> V_12 ;
F_6 ( V_10 ) ;
}
}
}
static long T_1 F_7 ( char * V_15 , T_3 V_16 )
{
struct V_17 V_18 [ 2 ] ;
V_18 [ 0 ] . V_19 = V_16 ;
V_18 [ 0 ] . V_20 = 0 ;
V_18 [ 1 ] . V_19 = V_16 ;
V_18 [ 1 ] . V_20 = 0 ;
return F_8 ( V_21 , V_15 , V_18 , V_22 ) ;
}
static void T_1 F_9 ( const char * V_8 , T_3 V_16 )
{
struct V_23 * V_24 = F_3 ( sizeof( struct V_23 ) , V_14 ) ;
if ( ! V_24 )
F_4 ( L_2 ) ;
F_10 ( & V_24 -> V_25 ) ;
V_24 -> V_8 = F_11 ( V_8 , V_14 ) ;
V_24 -> V_16 = V_16 ;
F_12 ( & V_24 -> V_25 , & V_26 ) ;
}
static void T_1 F_13 ( void )
{
struct V_23 * V_24 , * V_6 ;
F_14 (de, tmp, &dir_list, list) {
F_15 ( & V_24 -> V_25 ) ;
F_7 ( V_24 -> V_8 , V_24 -> V_16 ) ;
F_6 ( V_24 -> V_8 ) ;
F_6 ( V_24 ) ;
}
}
static void T_1 F_16 ( char * V_27 )
{
unsigned long V_28 [ 12 ] ;
char V_29 [ 9 ] ;
int V_30 ;
V_29 [ 8 ] = '\0' ;
for ( V_30 = 0 , V_27 += 6 ; V_30 < 12 ; V_30 ++ , V_27 += 8 ) {
memcpy ( V_29 , V_27 , 8 ) ;
V_28 [ V_30 ] = F_17 ( V_29 , NULL , 16 ) ;
}
V_5 = V_28 [ 0 ] ;
V_7 = V_28 [ 1 ] ;
V_31 = V_28 [ 2 ] ;
V_32 = V_28 [ 3 ] ;
V_33 = V_28 [ 4 ] ;
V_16 = V_28 [ 5 ] ;
V_34 = V_28 [ 6 ] ;
V_3 = V_28 [ 7 ] ;
V_4 = V_28 [ 8 ] ;
V_35 = F_18 ( F_19 ( V_28 [ 9 ] , V_28 [ 10 ] ) ) ;
V_36 = V_28 [ 11 ] ;
}
static inline void T_1 F_20 ( unsigned V_37 )
{
V_38 += V_37 ;
V_39 += V_37 ;
V_40 -= V_37 ;
}
static void T_1 F_21 ( char * V_29 , unsigned V_41 , enum V_42 V_12 )
{
if ( V_40 >= V_41 ) {
V_43 = V_38 ;
F_20 ( V_41 ) ;
V_42 = V_12 ;
} else {
V_44 = V_43 = V_29 ;
V_45 = V_41 ;
V_46 = V_12 ;
V_42 = V_47 ;
}
}
static int T_1 F_22 ( void )
{
F_21 ( V_48 , 110 , V_49 ) ;
return 0 ;
}
static int T_1 F_23 ( void )
{
unsigned V_37 = V_45 ;
if ( V_40 < V_37 )
V_37 = V_40 ;
memcpy ( V_44 , V_38 , V_37 ) ;
F_20 ( V_37 ) ;
V_44 += V_37 ;
if ( ( V_45 -= V_37 ) != 0 )
return 1 ;
V_42 = V_46 ;
return 0 ;
}
static int T_1 F_24 ( void )
{
if ( memcmp ( V_43 , L_3 , 6 ) == 0 ) {
error ( L_4 ) ;
return 1 ;
}
if ( memcmp ( V_43 , L_5 , 6 ) ) {
error ( L_6 ) ;
return 1 ;
}
F_16 ( V_43 ) ;
V_50 = V_39 + F_25 ( V_36 ) + V_34 ;
V_50 = ( V_50 + 3 ) & ~ 3 ;
V_42 = V_51 ;
if ( V_36 <= 0 || V_36 > V_52 )
return 0 ;
if ( F_26 ( V_7 ) ) {
if ( V_34 > V_52 )
return 0 ;
V_44 = V_43 = V_53 ;
V_45 = F_25 ( V_36 ) + V_34 ;
V_46 = V_54 ;
V_42 = V_47 ;
return 0 ;
}
if ( F_27 ( V_7 ) || ! V_34 )
F_21 ( V_55 , F_25 ( V_36 ) , V_56 ) ;
return 0 ;
}
static int T_1 F_28 ( void )
{
if ( V_39 + V_40 < V_50 ) {
F_20 ( V_40 ) ;
return 1 ;
} else {
F_20 ( V_50 - V_39 ) ;
V_42 = V_46 ;
return 0 ;
}
}
static int T_1 F_29 ( void )
{
while( V_40 && * V_38 == '\0' )
F_20 ( 1 ) ;
if ( V_40 && ( V_39 & 3 ) )
error ( L_7 ) ;
return 1 ;
}
static int T_1 F_30 ( void )
{
if ( V_33 >= 2 ) {
char * V_57 = F_2 ( V_3 , V_4 , V_5 , V_7 , V_43 ) ;
if ( V_57 )
return ( F_31 ( V_57 , V_43 ) < 0 ) ? - 1 : 1 ;
}
return 0 ;
}
static void T_1 F_32 ( char * V_58 , T_2 V_7 )
{
struct V_59 V_60 ;
if ( ! F_33 ( V_58 , & V_60 ) && ( V_60 . V_61 ^ V_7 ) & V_13 ) {
if ( F_34 ( V_60 . V_61 ) )
F_35 ( V_58 ) ;
else
F_36 ( V_58 ) ;
}
}
static int T_1 F_37 ( void )
{
V_42 = V_51 ;
V_46 = V_62 ;
if ( strcmp ( V_43 , L_8 ) == 0 ) {
F_5 () ;
return 0 ;
}
F_32 ( V_43 , V_7 ) ;
if ( F_27 ( V_7 ) ) {
int V_63 = F_30 () ;
if ( V_63 >= 0 ) {
int V_64 = V_65 | V_66 ;
if ( V_63 != 1 )
V_64 |= V_67 ;
V_68 = F_38 ( V_43 , V_64 , V_7 ) ;
if ( V_68 >= 0 ) {
F_39 ( V_68 , V_31 , V_32 ) ;
F_40 ( V_68 , V_7 ) ;
if ( V_34 )
F_41 ( V_68 , V_34 ) ;
V_69 = F_11 ( V_43 , V_14 ) ;
V_42 = V_70 ;
}
}
} else if ( F_34 ( V_7 ) ) {
F_42 ( V_43 , V_7 ) ;
F_43 ( V_43 , V_31 , V_32 ) ;
F_44 ( V_43 , V_7 ) ;
F_9 ( V_43 , V_16 ) ;
} else if ( F_45 ( V_7 ) || F_46 ( V_7 ) ||
F_47 ( V_7 ) || F_48 ( V_7 ) ) {
if ( F_30 () == 0 ) {
F_49 ( V_43 , V_7 , V_35 ) ;
F_43 ( V_43 , V_31 , V_32 ) ;
F_44 ( V_43 , V_7 ) ;
F_7 ( V_43 , V_16 ) ;
}
}
return 0 ;
}
static int T_1 F_50 ( void )
{
if ( V_40 >= V_34 ) {
F_51 ( V_68 , V_38 , V_34 ) ;
F_52 ( V_68 ) ;
F_7 ( V_69 , V_16 ) ;
F_6 ( V_69 ) ;
F_20 ( V_34 ) ;
V_42 = V_51 ;
return 0 ;
} else {
F_51 ( V_68 , V_38 , V_40 ) ;
V_34 -= V_40 ;
F_20 ( V_40 ) ;
return 1 ;
}
}
static int T_1 F_53 ( void )
{
V_43 [ F_25 ( V_36 ) + V_34 ] = '\0' ;
F_32 ( V_43 , 0 ) ;
F_54 ( V_43 + F_25 ( V_36 ) , V_43 ) ;
F_55 ( V_43 , V_31 , V_32 ) ;
F_7 ( V_43 , V_16 ) ;
V_42 = V_51 ;
V_46 = V_62 ;
return 0 ;
}
static int T_1 F_56 ( char * V_29 , unsigned V_71 )
{
V_40 = V_71 ;
V_38 = V_29 ;
while ( ! V_72 [ V_42 ] ( ) )
;
return V_71 - V_40 ;
}
static int T_1 F_57 ( void * V_73 , unsigned V_71 )
{
char * V_29 = ( char * ) V_73 ;
int V_74 ;
int V_75 = V_71 ;
if ( V_2 )
return - 1 ;
while ( ( V_74 = F_56 ( V_29 , V_71 ) ) < V_71 && ! V_2 ) {
char V_76 = V_29 [ V_74 ] ;
if ( V_76 == '0' ) {
V_29 += V_74 ;
V_71 -= V_74 ;
V_42 = V_77 ;
} else if ( V_76 == 0 ) {
V_29 += V_74 ;
V_71 -= V_74 ;
V_42 = V_62 ;
} else
error ( L_9 ) ;
}
return V_75 ;
}
static char * T_1 F_58 ( char * V_29 , unsigned V_71 )
{
int V_74 , V_78 ;
T_4 V_79 ;
const char * V_80 ;
static T_5 char V_81 [ 64 ] ;
V_48 = F_3 ( 110 , V_14 ) ;
V_53 = F_3 ( V_52 + F_25 ( V_52 ) + 1 , V_14 ) ;
V_55 = F_3 ( F_25 ( V_52 ) , V_14 ) ;
if ( ! V_48 || ! V_53 || ! V_55 )
F_4 ( L_10 ) ;
V_42 = V_77 ;
V_39 = 0 ;
V_2 = NULL ;
while ( ! V_2 && V_71 ) {
T_6 V_82 = V_39 ;
if ( * V_29 == '0' && ! ( V_39 & 3 ) ) {
V_42 = V_77 ;
V_74 = F_56 ( V_29 , V_71 ) ;
V_29 += V_74 ;
V_71 -= V_74 ;
continue;
}
if ( ! * V_29 ) {
V_29 ++ ;
V_71 -- ;
V_39 ++ ;
continue;
}
V_39 = 0 ;
V_79 = F_59 ( V_29 , V_71 , & V_80 ) ;
if ( V_79 ) {
V_78 = V_79 ( V_29 , V_71 , NULL , F_57 , NULL ,
& V_83 , error ) ;
if ( V_78 )
error ( L_11 ) ;
} else if ( V_80 ) {
if ( ! V_2 ) {
snprintf ( V_81 , sizeof V_81 ,
L_12 ,
V_80 ) ;
V_2 = V_81 ;
}
} else
error ( L_9 ) ;
if ( V_42 != V_62 )
error ( L_9 ) ;
V_39 = V_82 + V_83 ;
V_29 += V_83 ;
V_71 -= V_83 ;
}
F_13 () ;
F_6 ( V_55 ) ;
F_6 ( V_53 ) ;
F_6 ( V_48 ) ;
return V_2 ;
}
static int T_1 F_60 ( char * V_84 )
{
if ( * V_84 )
return 0 ;
V_85 = 1 ;
return 1 ;
}
static void T_1 F_61 ( void )
{
#ifdef F_62
unsigned long V_86 = ( unsigned long ) F_63 ( V_87 . V_88 ) ;
unsigned long V_89 = ( unsigned long ) F_63 ( V_87 . V_90 ) ;
#endif
if ( V_85 )
goto V_91;
#ifdef F_62
if ( V_92 < V_89 && V_93 > V_86 ) {
memset ( ( void * ) V_92 , 0 , V_93 - V_92 ) ;
if ( V_92 < V_86 )
F_64 ( V_92 , V_86 ) ;
if ( V_93 > V_89 )
F_64 ( V_89 , V_93 ) ;
} else
#endif
F_64 ( V_92 , V_93 ) ;
V_91:
V_92 = 0 ;
V_93 = 0 ;
}
static void T_1 F_65 ( void )
{
int V_94 ;
void * V_29 ;
struct V_95 * V_96 ;
int V_97 ;
V_94 = F_38 ( L_13 , V_98 , 0 ) ;
F_66 ( V_94 < 0 ) ;
if ( V_94 < 0 )
return;
V_29 = F_67 ( V_99 , V_14 ) ;
F_66 ( ! V_29 ) ;
if ( ! V_29 ) {
F_52 ( V_94 ) ;
return;
}
V_96 = V_29 ;
V_97 = F_68 ( V_94 , V_96 , V_99 ) ;
while ( V_97 > 0 ) {
while ( V_97 > 0 ) {
struct V_59 V_60 ;
int V_100 ;
V_100 = F_33 ( V_96 -> V_101 , & V_60 ) ;
F_69 ( V_100 ) ;
if ( ! V_100 ) {
if ( F_34 ( V_60 . V_61 ) )
F_35 ( V_96 -> V_101 ) ;
else
F_36 ( V_96 -> V_101 ) ;
}
V_97 -= V_96 -> V_102 ;
V_96 = ( void * ) V_96 + V_96 -> V_102 ;
}
V_96 = V_29 ;
memset ( V_29 , 0 , V_99 ) ;
V_97 = F_68 ( V_94 , V_96 , V_99 ) ;
}
F_52 ( V_94 ) ;
F_6 ( V_29 ) ;
}
static int T_1 F_70 ( void )
{
char * V_103 = F_58 ( V_104 , V_105 ) ;
if ( V_103 )
F_4 ( L_14 , V_103 ) ;
if ( V_92 ) {
#ifdef F_71
int V_94 ;
F_72 ( V_106 L_15 ) ;
V_103 = F_58 ( ( char * ) V_92 ,
V_93 - V_92 ) ;
if ( ! V_103 ) {
F_61 () ;
goto V_107;
} else {
F_65 () ;
F_58 ( V_104 , V_105 ) ;
}
F_72 ( V_106 L_16
L_17 , V_103 ) ;
V_94 = F_38 ( L_18 ,
V_65 | V_66 , 0700 ) ;
if ( V_94 >= 0 ) {
F_51 ( V_94 , ( char * ) V_92 ,
V_93 - V_92 ) ;
F_52 ( V_94 ) ;
F_61 () ;
}
V_107:
#else
F_72 ( V_106 L_19 ) ;
V_103 = F_58 ( ( char * ) V_92 ,
V_93 - V_92 ) ;
if ( V_103 )
F_72 ( V_108 L_20 , V_103 ) ;
F_61 () ;
#endif
F_73 () ;
}
return 0 ;
}
