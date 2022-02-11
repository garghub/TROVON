T_1 *
F_1 ( void )
{
const char * * V_1 ;
T_1 * V_2 ;
V_2 = NULL ;
for ( V_1 = & V_3 [ 0 ] ; * V_1 != NULL ;
V_1 ++ )
V_2 = F_2 ( V_2 , ( V_4 ) ( * V_1 ) ) ;
return V_2 ;
}
static int
F_3 ( T_2 V_5 , unsigned char * V_6 , unsigned int V_7 , T_3 * V_8 )
{
T_4 V_9 ;
* V_8 = 0 ;
do {
V_9 = F_4 ( V_5 -> V_10 , V_6 + * V_8 , V_7 - * V_8 ) ;
if ( V_9 <= 0 )
break;
* V_8 += ( unsigned ) V_9 ;
V_5 -> V_11 += V_9 ;
} while ( * V_8 < V_7 );
if ( V_9 < 0 ) {
V_5 -> V_12 = V_13 ;
V_5 -> V_14 = NULL ;
return - 1 ;
}
if ( V_9 == 0 )
V_5 -> V_15 = TRUE ;
return 0 ;
}
static int
F_5 ( T_2 V_5 )
{
if ( V_5 -> V_12 )
return - 1 ;
if ( V_5 -> V_15 == 0 ) {
if ( F_3 ( V_5 , V_5 -> V_16 , V_5 -> V_17 , & ( V_5 -> V_18 ) ) == - 1 )
return - 1 ;
V_5 -> V_19 = V_5 -> V_16 ;
}
return 0 ;
}
static struct V_20 *
F_6 ( T_2 V_21 , T_5 V_22 )
{
struct V_20 * V_23 = NULL ;
struct V_20 * V_24 ;
T_3 V_25 , V_26 , V_27 ;
if ( ! V_21 -> V_28 )
return NULL ;
for ( V_25 = 0 , V_27 = V_21 -> V_28 -> V_29 ; V_25 < V_27 ; ) {
V_26 = ( V_25 + V_27 ) / 2 ;
V_24 = (struct V_20 * ) V_21 -> V_28 -> V_30 [ V_26 ] ;
if ( V_22 < V_24 -> V_31 )
V_27 = V_26 ;
else if ( V_22 > V_24 -> V_31 ) {
V_23 = V_24 ;
V_25 = V_26 + 1 ;
} else {
return V_24 ;
}
}
return V_23 ;
}
static void
F_7 ( T_2 V_21 , T_5 V_32 , T_5 V_33 ,
T_6 V_34 )
{
struct V_20 * V_24 = NULL ;
if ( V_21 -> V_28 -> V_29 != 0 )
V_24 = (struct V_20 * ) V_21 -> V_28 -> V_30 [ V_21 -> V_28 -> V_29 - 1 ] ;
if ( ! V_24 || V_24 -> V_31 < V_33 ) {
struct V_20 * V_35 = F_8 ( struct V_20 , 1 ) ;
V_35 -> V_16 = V_32 ;
V_35 -> V_31 = V_33 ;
V_35 -> V_34 = V_34 ;
F_9 ( V_21 -> V_28 , V_35 ) ;
}
}
static void
F_10 ( T_2 V_5 V_36 )
{
#ifdef F_11
if ( V_5 -> V_34 == V_37 && V_5 -> V_38 ) {
struct V_39 * V_40 = (struct V_39 * ) V_5 -> V_38 ;
V_40 -> V_8 = 0 ;
}
#endif
}
static int
F_12 ( T_2 V_5 , T_7 * V_9 )
{
int V_41 ;
V_41 = F_13 () ;
if ( V_41 == - 1 ) {
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_12 = V_42 ;
V_5 -> V_14 = NULL ;
}
return - 1 ;
}
* V_9 = V_41 ;
return 0 ;
}
static int
F_14 ( T_2 V_5 , T_8 * V_9 )
{
T_8 V_35 ;
int V_41 ;
V_35 = F_13 () ;
V_41 = F_13 () ;
if ( V_41 == - 1 ) {
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_12 = V_42 ;
V_5 -> V_14 = NULL ;
}
return - 1 ;
}
V_35 += ( T_8 ) V_41 << 8 ;
* V_9 = V_35 ;
return 0 ;
}
static int
F_15 ( T_2 V_5 , T_9 * V_9 )
{
T_9 V_35 ;
int V_41 ;
V_35 = F_13 () ;
V_35 += ( unsigned ) F_13 () << 8 ;
V_35 += ( T_9 ) F_13 () << 16 ;
V_41 = F_13 () ;
if ( V_41 == - 1 ) {
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_12 = V_42 ;
V_5 -> V_14 = NULL ;
}
return - 1 ;
}
V_35 += ( T_9 ) V_41 << 24 ;
* V_9 = V_35 ;
return 0 ;
}
static int
F_16 ( T_2 V_5 , T_10 V_43 )
{
while ( V_43 != 0 ) {
if ( F_13 () == - 1 ) {
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_12 = V_42 ;
V_5 -> V_14 = NULL ;
}
return - 1 ;
}
V_43 -- ;
}
return 0 ;
}
static int
F_17 ( T_2 V_5 )
{
int V_41 ;
while ( ( V_41 = F_13 () ) > 0 )
;
if ( V_41 == - 1 ) {
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_12 = V_42 ;
V_5 -> V_14 = NULL ;
}
return - 1 ;
}
return 0 ;
}
static void
F_18 ( T_2 V_21 , struct V_39 * V_44 , int V_45 , T_5 V_32 , T_5 V_33 )
{
struct V_20 * V_24 = (struct V_20 * ) V_21 -> V_28 -> V_30 [ V_21 -> V_28 -> V_29 - 1 ] ;
#ifndef F_19
if ( V_45 )
return;
#endif
if ( V_24 -> V_31 + V_46 < V_33 ) {
struct V_20 * V_35 = F_8 ( struct V_20 , 1 ) ;
V_35 -> V_16 = V_32 ;
V_35 -> V_31 = V_33 ;
V_35 -> V_34 = V_37 ;
#ifdef F_19
V_35 -> V_47 . V_48 . V_45 = V_45 ;
#endif
if ( V_44 -> V_22 != 0 ) {
unsigned int V_49 = V_50 - V_44 -> V_22 ;
memcpy ( V_35 -> V_47 . V_48 . V_51 , V_44 -> V_51 + V_44 -> V_22 , V_49 ) ;
memcpy ( V_35 -> V_47 . V_48 . V_51 + V_49 , V_44 -> V_51 , V_44 -> V_22 ) ;
} else
memcpy ( V_35 -> V_47 . V_48 . V_51 , V_44 -> V_51 , V_50 ) ;
V_35 -> V_47 . V_48 . V_52 = ( T_9 ) V_21 -> V_53 . V_52 ;
V_35 -> V_47 . V_48 . V_54 = ( T_9 ) V_21 -> V_53 . V_54 ;
F_9 ( V_21 -> V_28 , V_35 ) ;
}
}
static void
F_20 ( T_2 V_5 , unsigned char * V_6 , unsigned int V_7 )
{
int V_9 = 0 ;
T_9 V_55 , V_29 ;
T_11 V_53 = & ( V_5 -> V_53 ) ;
unsigned char * V_56 = V_6 ;
unsigned int V_57 = V_7 ;
V_53 -> V_58 = V_7 ;
V_53 -> V_59 = V_6 ;
do {
if ( V_5 -> V_18 == 0 && F_5 ( V_5 ) == - 1 )
break;
if ( V_5 -> V_18 == 0 ) {
V_5 -> V_12 = V_42 ;
V_5 -> V_14 = NULL ;
break;
}
V_53 -> V_18 = V_5 -> V_18 ;
V_53 -> V_19 = V_5 -> V_19 ;
#ifdef F_21
V_9 = F_22 ( V_53 , F_21 ) ;
#else
V_9 = F_22 ( V_53 , V_60 ) ;
#endif
V_5 -> V_18 = V_53 -> V_18 ;
V_5 -> V_19 = V_53 -> V_19 ;
if ( V_9 == V_61 ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = V_53 -> V_63 ;
break;
}
if ( V_9 == V_64 ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = L_1 ;
break;
}
if ( V_9 == V_65 ) {
V_5 -> V_12 = V_66 ;
V_5 -> V_14 = NULL ;
break;
}
if ( V_9 == V_67 ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = V_53 -> V_63 ;
break;
}
V_53 -> V_52 = F_23 ( V_53 -> V_52 , V_56 , V_57 - V_53 -> V_58 ) ;
#ifdef F_21
if ( V_5 -> V_38 ) {
struct V_39 * V_40 = (struct V_39 * ) V_5 -> V_38 ;
unsigned int V_68 = V_57 - V_53 -> V_58 ;
if ( V_68 < V_50 ) {
T_3 V_49 = V_50 - V_40 -> V_22 ;
if ( V_68 >= V_49 ) {
memcpy ( V_40 -> V_51 + V_40 -> V_22 , V_56 , V_49 ) ;
if ( V_68 != V_49 )
memcpy ( V_40 -> V_51 , V_56 + V_49 , V_68 - V_49 ) ;
V_40 -> V_22 = V_68 - V_49 ;
V_40 -> V_8 += V_68 ;
} else {
memcpy ( V_40 -> V_51 + V_40 -> V_22 , V_56 , V_68 ) ;
V_40 -> V_22 += V_68 ;
V_40 -> V_8 += V_68 ;
}
if ( V_40 -> V_8 >= V_50 )
V_40 -> V_8 = V_50 ;
} else {
memcpy ( V_40 -> V_51 , V_56 + ( V_68 - V_50 ) , V_50 ) ;
V_40 -> V_22 = 0 ;
V_40 -> V_8 = V_50 ;
}
if ( V_40 -> V_8 >= V_50 && V_9 != V_69 && ( V_53 -> V_70 & 128 ) && ! ( V_53 -> V_70 & 64 ) )
F_18 ( V_5 , V_40 , ( V_53 -> V_70 & 7 ) , V_5 -> V_11 - V_53 -> V_18 , V_5 -> V_22 + ( V_7 - V_53 -> V_58 ) ) ;
}
#endif
V_56 = ( V_56 + V_57 - V_53 -> V_58 ) ;
V_57 = V_53 -> V_58 ;
} while ( V_53 -> V_58 && V_9 != V_69 );
V_5 -> V_71 = V_6 ;
V_5 -> V_8 = V_7 - V_53 -> V_58 ;
if ( V_9 == V_69 ) {
if ( F_15 ( V_5 , & V_55 ) != - 1 &&
F_15 ( V_5 , & V_29 ) != - 1 ) {
if ( V_55 != V_53 -> V_52 && ! V_5 -> V_72 ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = L_2 ;
} else if ( V_29 != ( V_53 -> V_54 & 0xffffffffL ) ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = L_3 ;
}
}
V_5 -> V_34 = V_73 ;
F_24 ( V_5 -> V_38 ) ;
V_5 -> V_38 = NULL ;
}
}
static int
F_25 ( T_2 V_5 )
{
if ( V_5 -> V_18 == 0 ) {
if ( F_5 ( V_5 ) == - 1 )
return - 1 ;
if ( V_5 -> V_18 == 0 )
return 0 ;
}
#ifdef F_11
if ( V_5 -> V_19 [ 0 ] == 31 ) {
V_5 -> V_18 -- ;
V_5 -> V_19 ++ ;
if ( V_5 -> V_18 == 0 && F_5 ( V_5 ) == - 1 )
return - 1 ;
if ( V_5 -> V_18 && V_5 -> V_19 [ 0 ] == 139 ) {
T_7 V_74 ;
T_7 V_75 ;
T_8 V_29 ;
T_8 V_76 ;
V_5 -> V_18 -- ;
V_5 -> V_19 ++ ;
if ( F_12 ( V_5 , & V_74 ) == - 1 )
return - 1 ;
if ( V_74 != 8 ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = L_4 ;
return - 1 ;
}
if ( F_12 ( V_5 , & V_75 ) == - 1 )
return - 1 ;
if ( V_75 & 0xe0 ) {
V_5 -> V_12 = V_62 ;
V_5 -> V_14 = L_5 ;
return - 1 ;
}
if ( F_16 ( V_5 , 4 ) == - 1 )
return - 1 ;
if ( F_16 ( V_5 , 1 ) == - 1 )
return - 1 ;
if ( F_16 ( V_5 , 1 ) == - 1 )
return - 1 ;
if ( V_75 & 4 ) {
if ( F_14 ( V_5 , & V_29 ) == - 1 )
return - 1 ;
if ( F_16 ( V_5 , V_29 ) == - 1 )
return - 1 ;
}
if ( V_75 & 8 ) {
if ( F_17 ( V_5 ) == - 1 )
return - 1 ;
}
if ( V_75 & 16 ) {
if ( F_17 ( V_5 ) == - 1 )
return - 1 ;
}
if ( V_75 & 2 ) {
if ( F_14 ( V_5 , & V_76 ) == - 1 )
return - 1 ;
}
F_26 ( & ( V_5 -> V_53 ) ) ;
V_5 -> V_53 . V_52 = F_23 ( 0L , V_77 , 0 ) ;
V_5 -> V_34 = V_37 ;
V_5 -> V_78 = TRUE ;
#ifdef F_21
if ( V_5 -> V_28 ) {
struct V_39 * V_40 = F_8 ( struct V_39 , 1 ) ;
V_40 -> V_22 = V_40 -> V_8 = 0 ;
F_24 ( V_5 -> V_38 ) ;
V_5 -> V_38 = V_40 ;
F_7 ( V_5 , V_5 -> V_11 - V_5 -> V_18 , V_5 -> V_22 , V_79 ) ;
}
#endif
return 0 ;
}
else {
V_5 -> V_31 [ 0 ] = 31 ;
V_5 -> V_8 = 1 ;
}
}
#endif
#ifdef F_27
#endif
if ( V_5 -> V_28 )
F_7 ( V_5 , V_5 -> V_11 - V_5 -> V_18 - V_5 -> V_8 , V_5 -> V_22 , V_80 ) ;
V_5 -> V_81 = V_5 -> V_22 ;
V_5 -> V_71 = V_5 -> V_31 ;
if ( V_5 -> V_18 ) {
memcpy ( V_5 -> V_71 + V_5 -> V_8 , V_5 -> V_19 , V_5 -> V_18 ) ;
V_5 -> V_8 += V_5 -> V_18 ;
V_5 -> V_18 = 0 ;
}
V_5 -> V_34 = V_80 ;
return 0 ;
}
static int
F_28 ( T_2 V_5 )
{
if ( V_5 -> V_34 == V_73 ) {
if ( F_25 ( V_5 ) == - 1 )
return - 1 ;
if ( V_5 -> V_8 )
return 0 ;
}
if ( V_5 -> V_34 == V_80 ) {
if ( F_3 ( V_5 , V_5 -> V_31 , V_5 -> V_17 , & ( V_5 -> V_8 ) ) == - 1 )
return - 1 ;
V_5 -> V_71 = V_5 -> V_31 ;
}
#ifdef F_11
else if ( V_5 -> V_34 == V_37 ) {
F_20 ( V_5 , V_5 -> V_31 , V_5 -> V_17 << 1 ) ;
}
#endif
return 0 ;
}
static int
F_29 ( T_2 V_5 , T_5 V_29 )
{
T_3 V_43 ;
while ( V_29 )
if ( V_5 -> V_8 ) {
V_43 = ( T_5 ) V_5 -> V_8 > V_29 ? ( unsigned ) V_29 : V_5 -> V_8 ;
V_5 -> V_8 -= V_43 ;
V_5 -> V_71 += V_43 ;
V_5 -> V_22 += V_43 ;
V_29 -= V_43 ;
} else if ( V_5 -> V_12 ) {
return - 1 ;
} else if ( V_5 -> V_15 && V_5 -> V_18 == 0 ) {
break;
} else {
if ( F_28 ( V_5 ) == - 1 )
return - 1 ;
}
return 0 ;
}
static void
F_30 ( T_2 V_5 )
{
V_5 -> V_8 = 0 ;
V_5 -> V_15 = FALSE ;
V_5 -> V_34 = V_73 ;
V_5 -> V_82 = FALSE ;
V_5 -> V_12 = 0 ;
V_5 -> V_14 = NULL ;
V_5 -> V_22 = 0 ;
V_5 -> V_18 = 0 ;
}
T_2
F_31 ( int V_10 )
{
#ifdef F_32
struct V_83 V_84 ;
#endif
int V_85 = V_86 ;
T_2 V_5 ;
if ( V_10 == - 1 )
return NULL ;
V_5 = ( T_2 ) F_33 ( sizeof *V_5 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_38 = NULL ;
V_5 -> V_28 = NULL ;
V_5 -> V_10 = V_10 ;
V_5 -> V_78 = FALSE ;
V_5 -> V_87 = F_34 ( V_5 -> V_10 , 0 , V_88 ) ;
if ( V_5 -> V_87 == - 1 ) V_5 -> V_87 = 0 ;
V_5 -> V_11 = V_5 -> V_87 ;
F_30 ( V_5 ) ;
#ifdef F_32
if ( F_35 ( V_10 , & V_84 ) >= 0 ) {
if ( V_84 . V_89 <= V_90 )
V_85 = ( int ) V_84 . V_89 ;
}
#endif
V_5 -> V_16 = ( unsigned char * ) F_33 ( V_85 ) ;
V_5 -> V_31 = ( unsigned char * ) F_33 ( V_85 << 1 ) ;
V_5 -> V_17 = V_85 ;
if ( V_5 -> V_16 == NULL || V_5 -> V_31 == NULL ) {
F_24 ( V_5 -> V_31 ) ;
F_24 ( V_5 -> V_16 ) ;
F_24 ( V_5 ) ;
V_13 = V_66 ;
return NULL ;
}
#ifdef F_11
V_5 -> V_53 . V_91 = V_77 ;
V_5 -> V_53 . V_92 = V_77 ;
V_5 -> V_53 . V_93 = V_77 ;
V_5 -> V_53 . V_18 = 0 ;
V_5 -> V_53 . V_19 = V_77 ;
if ( F_36 ( & ( V_5 -> V_53 ) , - 15 ) != V_94 ) {
F_24 ( V_5 -> V_31 ) ;
F_24 ( V_5 -> V_16 ) ;
F_24 ( V_5 ) ;
V_13 = V_66 ;
return NULL ;
}
V_5 -> V_72 = FALSE ;
#endif
return V_5 ;
}
T_2
F_37 ( const char * V_95 )
{
int V_10 ;
T_2 V_96 ;
#ifdef F_11
const char * V_97 ;
#endif
if ( ( V_10 = F_38 ( V_95 , V_98 | V_99 , 0000 ) ) == - 1 )
return NULL ;
V_96 = F_31 ( V_10 ) ;
if ( V_96 == NULL ) {
F_39 ( V_10 ) ;
return NULL ;
}
#ifdef F_11
V_97 = strrchr ( V_95 , '.' ) ;
if ( V_97 != NULL ) {
if ( F_40 ( V_97 , L_6 ) == 0 )
V_96 -> V_72 = TRUE ;
}
#endif
return V_96 ;
}
void
F_41 ( T_2 V_100 , T_12 T_13 V_36 , T_14 * V_101 )
{
V_100 -> V_28 = V_101 ;
}
T_5
F_42 ( T_2 V_21 , T_5 V_102 , int V_103 , int * V_12 )
{
struct V_20 * V_104 ;
T_3 V_43 ;
if ( V_103 != V_105 && V_103 != V_88 ) {
F_43 () ;
}
if ( V_103 == V_105 )
V_102 -= V_21 -> V_22 ;
else if ( V_21 -> V_82 )
V_102 += V_21 -> V_106 ;
V_21 -> V_82 = FALSE ;
if ( V_102 < 0 && V_21 -> V_71 ) {
T_3 V_107 = ( unsigned ) ( V_21 -> V_71 - V_21 -> V_31 ) ;
if ( - V_102 <= V_107 ) {
T_3 V_108 = ( unsigned ) ( - V_102 ) ;
V_21 -> V_8 += V_108 ;
V_21 -> V_71 -= V_108 ;
V_21 -> V_22 -= V_108 ;
return V_21 -> V_22 ;
}
}
if ( ( V_104 = F_6 ( V_21 , V_21 -> V_22 + V_102 ) ) && ( V_102 < 0 || V_102 > V_46 || V_104 -> V_34 == V_80 ) ) {
T_5 V_109 , V_110 ;
#ifdef F_11
if ( V_104 -> V_34 == V_37 ) {
#ifdef F_19
V_109 = V_104 -> V_16 - ( V_104 -> V_47 . V_48 . V_45 ? 1 : 0 ) ;
#else
V_109 = V_104 -> V_16 ;
#endif
V_110 = V_104 -> V_31 ;
} else if ( V_104 -> V_34 == V_79 ) {
V_109 = V_104 -> V_16 ;
V_110 = V_104 -> V_31 ;
} else
#endif
{
V_110 = ( V_21 -> V_22 + V_102 ) ;
V_109 = V_104 -> V_16 + ( V_110 - V_104 -> V_31 ) ;
}
if ( F_34 ( V_21 -> V_10 , V_109 , V_105 ) == - 1 ) {
* V_12 = V_13 ;
return - 1 ;
}
F_10 ( V_21 ) ;
V_21 -> V_11 = V_109 ;
V_21 -> V_8 = 0 ;
V_21 -> V_15 = FALSE ;
V_21 -> V_82 = FALSE ;
V_21 -> V_12 = 0 ;
V_21 -> V_14 = NULL ;
V_21 -> V_18 = 0 ;
#ifdef F_11
if ( V_104 -> V_34 == V_37 ) {
T_15 * V_53 = & V_21 -> V_53 ;
F_26 ( V_53 ) ;
V_53 -> V_52 = V_104 -> V_47 . V_48 . V_52 ;
V_53 -> V_54 = V_104 -> V_47 . V_48 . V_54 ;
#ifdef F_19
if ( V_104 -> V_47 . V_48 . V_45 ) {
T_2 V_5 = V_21 ;
int V_9 = F_13 () ;
if ( V_9 == - 1 ) {
if ( V_5 -> V_12 == 0 ) {
* V_12 = V_42 ;
} else
* V_12 = V_5 -> V_12 ;
return - 1 ;
}
( void ) F_44 ( V_53 , V_104 -> V_47 . V_48 . V_45 , V_9 >> ( 8 - V_104 -> V_47 . V_48 . V_45 ) ) ;
}
#endif
( void ) F_45 ( V_53 , V_104 -> V_47 . V_48 . V_51 , V_50 ) ;
V_21 -> V_34 = V_37 ;
} else if ( V_104 -> V_34 == V_79 ) {
T_15 * V_53 = & V_21 -> V_53 ;
F_26 ( V_53 ) ;
V_53 -> V_52 = F_23 ( 0L , V_77 , 0 ) ;
V_21 -> V_34 = V_37 ;
} else
#endif
V_21 -> V_34 = V_104 -> V_34 ;
V_102 = ( V_21 -> V_22 + V_102 ) - V_110 ;
V_21 -> V_22 = V_110 ;
if ( V_102 ) {
V_21 -> V_82 = TRUE ;
V_21 -> V_106 = V_102 ;
}
return V_21 -> V_22 + V_102 ;
}
if ( V_21 -> V_34 == V_80 && V_21 -> V_22 + V_102 >= V_21 -> V_81
&& ( V_102 < 0 || V_102 >= V_21 -> V_8 ) )
{
if ( F_34 ( V_21 -> V_10 , V_102 - V_21 -> V_8 , V_88 ) == - 1 ) {
* V_12 = V_13 ;
return - 1 ;
}
V_21 -> V_11 += ( V_102 - V_21 -> V_8 ) ;
V_21 -> V_8 = 0 ;
V_21 -> V_15 = FALSE ;
V_21 -> V_82 = FALSE ;
V_21 -> V_12 = 0 ;
V_21 -> V_14 = NULL ;
V_21 -> V_18 = 0 ;
V_21 -> V_22 += V_102 ;
return V_21 -> V_22 ;
}
if ( V_102 < 0 ) {
V_102 += V_21 -> V_22 ;
if ( V_102 < 0 ) {
* V_12 = V_111 ;
return - 1 ;
}
if ( F_34 ( V_21 -> V_10 , V_21 -> V_87 , V_105 ) == - 1 ) {
* V_12 = V_13 ;
return - 1 ;
}
F_10 ( V_21 ) ;
V_21 -> V_11 = V_21 -> V_87 ;
F_30 ( V_21 ) ;
}
V_43 = ( T_5 ) V_21 -> V_8 > V_102 ? ( unsigned ) V_102 : V_21 -> V_8 ;
V_21 -> V_8 -= V_43 ;
V_21 -> V_71 += V_43 ;
V_21 -> V_22 += V_43 ;
V_102 -= V_43 ;
if ( V_102 ) {
V_21 -> V_82 = TRUE ;
V_21 -> V_106 = V_102 ;
}
return V_21 -> V_22 + V_102 ;
}
T_12
F_46 ( T_2 V_21 , T_5 V_112 , int * V_12 )
{
if ( F_42 ( V_21 , V_112 , V_88 , V_12 ) == - 1 )
return FALSE ;
return TRUE ;
}
T_5
F_47 ( T_2 V_100 )
{
return V_100 -> V_22 + ( V_100 -> V_82 ? V_100 -> V_106 : 0 ) ;
}
T_5
F_48 ( T_2 V_100 )
{
return V_100 -> V_11 ;
}
int
F_49 ( T_2 V_100 , T_16 * V_113 , int * V_12 )
{
if ( F_50 ( V_100 -> V_10 , V_113 ) == - 1 ) {
if ( V_12 != NULL )
* V_12 = V_13 ;
return - 1 ;
}
return 0 ;
}
T_12
F_51 ( T_2 V_100 )
{
return V_100 -> V_78 ;
}
int
F_52 ( void * V_6 , unsigned int V_29 , T_2 V_21 )
{
T_3 V_114 , V_43 ;
if ( V_29 == 0 )
return 0 ;
if ( V_21 -> V_82 ) {
V_21 -> V_82 = FALSE ;
if ( F_29 ( V_21 , V_21 -> V_106 ) == - 1 )
return - 1 ;
}
V_114 = 0 ;
do {
if ( V_21 -> V_8 ) {
V_43 = V_21 -> V_8 > V_29 ? V_29 : V_21 -> V_8 ;
memcpy ( V_6 , V_21 -> V_71 , V_43 ) ;
V_21 -> V_71 += V_43 ;
V_21 -> V_8 -= V_43 ;
} else if ( V_21 -> V_12 ) {
return - 1 ;
} else if ( V_21 -> V_15 && V_21 -> V_18 == 0 ) {
break;
} else {
if ( F_28 ( V_21 ) == - 1 )
return - 1 ;
continue;
}
V_29 -= V_43 ;
V_6 = ( char * ) V_6 + V_43 ;
V_114 += V_43 ;
V_21 -> V_22 += V_43 ;
} while ( V_29 );
return ( int ) V_114 ;
}
int
F_53 ( T_2 V_21 )
{
unsigned char V_6 [ 1 ] ;
int V_9 ;
if ( V_21 -> V_12 )
return - 1 ;
if ( V_21 -> V_8 ) {
V_21 -> V_8 -- ;
V_21 -> V_22 ++ ;
return * ( V_21 -> V_71 ) ++ ;
}
V_9 = F_52 ( V_6 , 1 , V_21 ) ;
return V_9 < 1 ? - 1 : V_6 [ 0 ] ;
}
char *
F_54 ( char * V_6 , int V_29 , T_2 V_21 )
{
T_3 V_49 , V_43 ;
char * V_115 ;
unsigned char * V_116 ;
if ( V_6 == NULL || V_29 < 1 )
return NULL ;
if ( V_21 -> V_12 )
return NULL ;
if ( V_21 -> V_82 ) {
V_21 -> V_82 = FALSE ;
if ( F_29 ( V_21 , V_21 -> V_106 ) == - 1 )
return NULL ;
}
V_115 = V_6 ;
V_49 = ( unsigned ) V_29 - 1 ;
if ( V_49 ) do {
if ( V_21 -> V_8 == 0 ) {
if ( V_21 -> V_12 ) {
return NULL ;
}
if ( F_28 ( V_21 ) == - 1 )
return NULL ;
if ( V_21 -> V_8 == 0 ) {
if ( V_6 == V_115 )
return NULL ;
break;
}
}
V_43 = V_21 -> V_8 > V_49 ? V_49 : V_21 -> V_8 ;
V_116 = ( unsigned char * ) memchr ( V_21 -> V_71 , '\n' , V_43 ) ;
if ( V_116 != NULL )
V_43 = ( unsigned ) ( V_116 - V_21 -> V_71 ) + 1 ;
memcpy ( V_6 , V_21 -> V_71 , V_43 ) ;
V_21 -> V_8 -= V_43 ;
V_21 -> V_71 += V_43 ;
V_21 -> V_22 += V_43 ;
V_49 -= V_43 ;
V_6 += V_43 ;
} while ( V_49 && V_116 == NULL );
V_6 [ 0 ] = 0 ;
return V_115 ;
}
int
F_55 ( T_2 V_21 )
{
return ( V_21 -> V_15 && V_21 -> V_18 == 0 && V_21 -> V_8 == 0 ) ;
}
int
F_56 ( T_2 V_117 , T_17 * * V_14 )
{
if ( V_117 -> V_12 != 0 && V_14 ) {
* V_14 = F_57 ( V_117 -> V_14 ) ;
}
return V_117 -> V_12 ;
}
void
F_58 ( T_2 V_100 )
{
V_100 -> V_12 = 0 ;
V_100 -> V_14 = NULL ;
V_100 -> V_15 = FALSE ;
}
void
F_59 ( T_2 V_21 )
{
F_39 ( V_21 -> V_10 ) ;
V_21 -> V_10 = - 1 ;
}
T_12
F_60 ( T_2 V_21 , const char * V_95 )
{
int V_10 ;
if ( ( V_10 = F_38 ( V_95 , V_98 | V_99 , 0000 ) ) == - 1 )
return FALSE ;
V_21 -> V_10 = V_10 ;
return TRUE ;
}
void
F_61 ( T_2 V_21 )
{
int V_10 = V_21 -> V_10 ;
if ( V_21 -> V_17 ) {
#ifdef F_11
F_62 ( & ( V_21 -> V_53 ) ) ;
#endif
F_24 ( V_21 -> V_31 ) ;
F_24 ( V_21 -> V_16 ) ;
}
F_24 ( V_21 -> V_38 ) ;
V_21 -> V_12 = 0 ;
V_21 -> V_14 = NULL ;
F_24 ( V_21 ) ;
if ( V_10 != - 1 )
F_39 ( V_10 ) ;
}
T_18
F_63 ( const char * V_95 )
{
int V_10 ;
T_18 V_5 ;
int V_118 ;
V_10 = F_38 ( V_95 , V_99 | V_119 | V_120 | V_121 , 0666 ) ;
if ( V_10 == - 1 )
return NULL ;
V_5 = F_64 ( V_10 ) ;
if ( V_5 == NULL ) {
V_118 = V_13 ;
F_65 ( V_10 ) ;
V_13 = V_118 ;
}
return V_5 ;
}
T_18
F_64 ( int V_10 )
{
T_18 V_5 ;
V_5 = ( T_18 ) F_33 ( sizeof *V_5 ) ;
if ( V_5 == NULL )
return NULL ;
V_5 -> V_10 = V_10 ;
V_5 -> V_17 = 0 ;
V_5 -> V_85 = V_86 ;
V_5 -> V_122 = V_123 ;
V_5 -> V_124 = V_125 ;
V_5 -> V_12 = V_94 ;
V_5 -> V_22 = 0 ;
V_5 -> V_53 . V_18 = 0 ;
return V_5 ;
}
static int
F_66 ( T_18 V_5 )
{
int V_9 ;
T_11 V_53 = & ( V_5 -> V_53 ) ;
V_5 -> V_16 = ( unsigned char * ) F_33 ( V_5 -> V_85 ) ;
V_5 -> V_31 = ( unsigned char * ) F_33 ( V_5 -> V_85 ) ;
if ( V_5 -> V_16 == NULL || V_5 -> V_31 == NULL ) {
F_24 ( V_5 -> V_31 ) ;
F_24 ( V_5 -> V_16 ) ;
V_5 -> V_12 = V_66 ;
return - 1 ;
}
V_53 -> V_91 = V_77 ;
V_53 -> V_92 = V_77 ;
V_53 -> V_93 = V_77 ;
V_9 = F_67 ( V_53 , V_5 -> V_122 , V_126 ,
15 + 16 , 8 , V_5 -> V_124 ) ;
if ( V_9 != V_94 ) {
F_24 ( V_5 -> V_31 ) ;
F_24 ( V_5 -> V_16 ) ;
if ( V_9 == V_65 ) {
V_5 -> V_12 = V_66 ;
} else {
V_5 -> V_12 = V_127 ;
}
return - 1 ;
}
V_5 -> V_17 = V_5 -> V_85 ;
V_53 -> V_58 = V_5 -> V_17 ;
V_53 -> V_59 = V_5 -> V_31 ;
V_5 -> V_71 = V_53 -> V_59 ;
return 0 ;
}
static int
F_68 ( T_18 V_5 , int V_128 )
{
int V_9 ;
T_4 V_114 ;
T_19 V_8 ;
T_11 V_53 = & ( V_5 -> V_53 ) ;
if ( V_5 -> V_17 == 0 && F_66 ( V_5 ) == - 1 )
return - 1 ;
V_9 = V_94 ;
do {
if ( V_53 -> V_58 == 0 || ( V_128 != V_60 &&
( V_128 != V_129 || V_9 == V_69 ) ) ) {
V_8 = V_53 -> V_59 - V_5 -> V_71 ;
if ( V_8 ) {
V_114 = F_69 ( V_5 -> V_10 , V_5 -> V_71 , ( unsigned int ) V_8 ) ;
if ( V_114 < 0 ) {
V_5 -> V_12 = V_13 ;
return - 1 ;
}
if ( ( T_19 ) V_114 != V_8 ) {
V_5 -> V_12 = V_130 ;
return - 1 ;
}
}
if ( V_53 -> V_58 == 0 ) {
V_53 -> V_58 = V_5 -> V_17 ;
V_53 -> V_59 = V_5 -> V_31 ;
}
V_5 -> V_71 = V_53 -> V_59 ;
}
V_8 = V_53 -> V_58 ;
V_9 = F_70 ( V_53 , V_128 ) ;
if ( V_9 == V_61 ) {
V_5 -> V_12 = V_127 ;
return - 1 ;
}
V_8 -= V_53 -> V_58 ;
} while ( V_8 );
if ( V_128 == V_129 )
F_71 ( V_53 ) ;
return 0 ;
}
unsigned
F_72 ( T_18 V_5 , const void * V_6 , T_3 V_29 )
{
T_3 V_131 = V_29 ;
T_3 V_43 ;
T_11 V_53 ;
V_53 = & ( V_5 -> V_53 ) ;
if ( V_5 -> V_12 != V_94 )
return 0 ;
if ( V_29 == 0 )
return 0 ;
if ( V_5 -> V_17 == 0 && F_66 ( V_5 ) == - 1 )
return 0 ;
if ( V_29 < V_5 -> V_17 ) {
do {
if ( V_53 -> V_18 == 0 )
V_53 -> V_19 = V_5 -> V_16 ;
V_43 = V_5 -> V_17 - V_53 -> V_18 ;
if ( V_43 > V_29 )
V_43 = V_29 ;
memcpy ( V_53 -> V_19 + V_53 -> V_18 , V_6 , V_43 ) ;
V_53 -> V_18 += V_43 ;
V_5 -> V_22 += V_43 ;
V_6 = ( const char * ) V_6 + V_43 ;
V_29 -= V_43 ;
if ( V_29 && F_68 ( V_5 , V_60 ) == - 1 )
return 0 ;
} while ( V_29 );
}
else {
if ( V_53 -> V_18 && F_68 ( V_5 , V_60 ) == - 1 )
return 0 ;
V_53 -> V_18 = V_29 ;
V_53 -> V_19 = ( V_132 * ) V_6 ;
V_5 -> V_22 += V_29 ;
if ( F_68 ( V_5 , V_60 ) == - 1 )
return 0 ;
}
return ( int ) V_131 ;
}
int
F_73 ( T_18 V_5 )
{
if ( V_5 -> V_12 != V_94 )
return - 1 ;
F_68 ( V_5 , V_133 ) ;
if ( V_5 -> V_12 != V_94 )
return - 1 ;
return 0 ;
}
int
F_74 ( T_18 V_5 )
{
int V_9 = 0 ;
if ( F_68 ( V_5 , V_129 ) == - 1 && V_9 == 0 )
V_9 = V_5 -> V_12 ;
( void ) F_75 ( & ( V_5 -> V_53 ) ) ;
F_24 ( V_5 -> V_31 ) ;
F_24 ( V_5 -> V_16 ) ;
V_5 -> V_12 = V_94 ;
if ( F_65 ( V_5 -> V_10 ) == - 1 && V_9 == 0 )
V_9 = V_13 ;
F_24 ( V_5 ) ;
return V_9 ;
}
int
F_76 ( T_18 V_5 )
{
return V_5 -> V_12 ;
}
