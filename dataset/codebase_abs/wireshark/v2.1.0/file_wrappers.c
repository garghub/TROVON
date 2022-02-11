static int
F_1 ( T_1 V_1 , unsigned char * V_2 , unsigned int V_3 , T_2 * V_4 )
{
T_3 V_5 ;
* V_4 = 0 ;
do {
V_5 = F_2 ( V_1 -> V_6 , V_2 + * V_4 , V_3 - * V_4 ) ;
if ( V_5 <= 0 )
break;
* V_4 += ( unsigned ) V_5 ;
V_1 -> V_7 += V_5 ;
} while ( * V_4 < V_3 );
if ( V_5 < 0 ) {
V_1 -> V_8 = V_9 ;
V_1 -> V_10 = NULL ;
return - 1 ;
}
if ( V_5 == 0 )
V_1 -> V_11 = TRUE ;
return 0 ;
}
static int
F_3 ( T_1 V_1 )
{
if ( V_1 -> V_8 )
return - 1 ;
if ( V_1 -> V_11 == 0 ) {
if ( F_1 ( V_1 , V_1 -> V_12 , V_1 -> V_13 , & ( V_1 -> V_14 ) ) == - 1 )
return - 1 ;
V_1 -> V_15 = V_1 -> V_12 ;
}
return 0 ;
}
static struct V_16 *
F_4 ( T_1 V_17 , T_4 V_18 )
{
struct V_16 * V_19 = NULL ;
struct V_16 * V_20 ;
T_2 V_21 , V_22 , V_23 ;
if ( ! V_17 -> V_24 )
return NULL ;
for ( V_21 = 0 , V_23 = V_17 -> V_24 -> V_25 ; V_21 < V_23 ; ) {
V_22 = ( V_21 + V_23 ) / 2 ;
V_20 = (struct V_16 * ) V_17 -> V_24 -> V_26 [ V_22 ] ;
if ( V_18 < V_20 -> V_27 )
V_23 = V_22 ;
else if ( V_18 > V_20 -> V_27 ) {
V_19 = V_20 ;
V_21 = V_22 + 1 ;
} else {
return V_20 ;
}
}
return V_19 ;
}
static void
F_5 ( T_1 V_17 , T_4 V_28 , T_4 V_29 ,
T_5 V_30 )
{
struct V_16 * V_20 = NULL ;
if ( V_17 -> V_24 -> V_25 != 0 )
V_20 = (struct V_16 * ) V_17 -> V_24 -> V_26 [ V_17 -> V_24 -> V_25 - 1 ] ;
if ( ! V_20 || V_20 -> V_27 < V_29 ) {
struct V_16 * V_31 = F_6 ( struct V_16 , 1 ) ;
V_31 -> V_12 = V_28 ;
V_31 -> V_27 = V_29 ;
V_31 -> V_30 = V_30 ;
F_7 ( V_17 -> V_24 , V_31 ) ;
}
}
static int
F_8 ( T_1 V_1 , T_6 * V_5 )
{
int V_32 ;
V_32 = F_9 () ;
if ( V_32 == - 1 ) {
if ( V_1 -> V_8 == 0 ) {
V_1 -> V_8 = V_33 ;
V_1 -> V_10 = NULL ;
}
return - 1 ;
}
* V_5 = V_32 ;
return 0 ;
}
static int
F_10 ( T_1 V_1 , T_7 * V_5 )
{
T_7 V_31 ;
int V_32 ;
V_31 = F_9 () ;
V_32 = F_9 () ;
if ( V_32 == - 1 ) {
if ( V_1 -> V_8 == 0 ) {
V_1 -> V_8 = V_33 ;
V_1 -> V_10 = NULL ;
}
return - 1 ;
}
V_31 += ( T_7 ) V_32 << 8 ;
* V_5 = V_31 ;
return 0 ;
}
static int
F_11 ( T_1 V_1 , T_8 * V_5 )
{
T_8 V_31 ;
int V_32 ;
V_31 = F_9 () ;
V_31 += ( unsigned ) F_9 () << 8 ;
V_31 += ( T_8 ) F_9 () << 16 ;
V_32 = F_9 () ;
if ( V_32 == - 1 ) {
if ( V_1 -> V_8 == 0 ) {
V_1 -> V_8 = V_33 ;
V_1 -> V_10 = NULL ;
}
return - 1 ;
}
V_31 += ( T_8 ) V_32 << 24 ;
* V_5 = V_31 ;
return 0 ;
}
static int
F_12 ( T_1 V_1 , T_9 V_34 )
{
while ( V_34 != 0 ) {
if ( F_9 () == - 1 ) {
if ( V_1 -> V_8 == 0 ) {
V_1 -> V_8 = V_33 ;
V_1 -> V_10 = NULL ;
}
return - 1 ;
}
V_34 -- ;
}
return 0 ;
}
static int
F_13 ( T_1 V_1 )
{
int V_32 ;
while ( ( V_32 = F_9 () ) > 0 )
;
if ( V_32 == - 1 ) {
if ( V_1 -> V_8 == 0 ) {
V_1 -> V_8 = V_33 ;
V_1 -> V_10 = NULL ;
}
return - 1 ;
}
return 0 ;
}
static void
F_14 ( T_1 V_17 , struct V_35 * V_36 , int V_37 , T_4 V_28 , T_4 V_29 )
{
struct V_16 * V_20 = (struct V_16 * ) V_17 -> V_24 -> V_26 [ V_17 -> V_24 -> V_25 - 1 ] ;
#ifndef F_15
if ( V_37 )
return;
#endif
if ( V_20 -> V_27 + V_38 < V_29 ) {
struct V_16 * V_31 = F_6 ( struct V_16 , 1 ) ;
V_31 -> V_12 = V_28 ;
V_31 -> V_27 = V_29 ;
V_31 -> V_30 = V_39 ;
#ifdef F_15
V_31 -> V_40 . V_41 . V_37 = V_37 ;
#endif
if ( V_36 -> V_18 != 0 ) {
unsigned int V_42 = V_43 - V_36 -> V_18 ;
memcpy ( V_31 -> V_40 . V_41 . V_44 , V_36 -> V_44 + V_36 -> V_18 , V_42 ) ;
memcpy ( V_31 -> V_40 . V_41 . V_44 + V_42 , V_36 -> V_44 , V_36 -> V_18 ) ;
} else
memcpy ( V_31 -> V_40 . V_41 . V_44 , V_36 -> V_44 , V_43 ) ;
V_31 -> V_40 . V_41 . V_45 = ( T_8 ) V_17 -> V_46 . V_45 ;
V_31 -> V_40 . V_41 . V_47 = ( T_8 ) V_17 -> V_46 . V_47 ;
F_7 ( V_17 -> V_24 , V_31 ) ;
}
}
static void
F_16 ( T_1 V_1 , unsigned char * V_2 , unsigned int V_3 )
{
int V_5 = 0 ;
T_8 V_48 , V_25 ;
T_10 V_46 = & ( V_1 -> V_46 ) ;
unsigned char * V_49 = V_2 ;
unsigned int V_50 = V_3 ;
V_46 -> V_51 = V_3 ;
V_46 -> V_52 = V_2 ;
do {
if ( V_1 -> V_14 == 0 && F_3 ( V_1 ) == - 1 )
break;
if ( V_1 -> V_14 == 0 ) {
V_1 -> V_8 = V_33 ;
V_1 -> V_10 = NULL ;
break;
}
V_46 -> V_14 = V_1 -> V_14 ;
V_46 -> V_15 = V_1 -> V_15 ;
#ifdef F_17
V_5 = F_18 ( V_46 , F_17 ) ;
#else
V_5 = F_18 ( V_46 , V_53 ) ;
#endif
V_1 -> V_14 = V_46 -> V_14 ;
#ifdef F_19
F_20 (cast-qual)
V_1 -> V_15 = ( unsigned char * ) V_46 -> V_15 ;
F_21 (cast-qual)
#else
V_1 -> V_15 = V_46 -> V_15 ;
#endif
if ( V_5 == V_54 ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = V_46 -> V_56 ;
break;
}
if ( V_5 == V_57 ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = L_1 ;
break;
}
if ( V_5 == V_58 ) {
V_1 -> V_8 = V_59 ;
V_1 -> V_10 = NULL ;
break;
}
if ( V_5 == V_60 ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = V_46 -> V_56 ;
break;
}
V_46 -> V_45 = F_22 ( V_46 -> V_45 , V_49 , V_50 - V_46 -> V_51 ) ;
#ifdef F_17
if ( V_1 -> V_61 ) {
struct V_35 * V_62 = (struct V_35 * ) V_1 -> V_61 ;
unsigned int V_63 = V_50 - V_46 -> V_51 ;
if ( V_63 < V_43 ) {
T_2 V_42 = V_43 - V_62 -> V_18 ;
if ( V_63 >= V_42 ) {
memcpy ( V_62 -> V_44 + V_62 -> V_18 , V_49 , V_42 ) ;
if ( V_63 != V_42 )
memcpy ( V_62 -> V_44 , V_49 + V_42 , V_63 - V_42 ) ;
V_62 -> V_18 = V_63 - V_42 ;
V_62 -> V_4 += V_63 ;
} else {
memcpy ( V_62 -> V_44 + V_62 -> V_18 , V_49 , V_63 ) ;
V_62 -> V_18 += V_63 ;
V_62 -> V_4 += V_63 ;
}
if ( V_62 -> V_4 >= V_43 )
V_62 -> V_4 = V_43 ;
} else {
memcpy ( V_62 -> V_44 , V_49 + ( V_63 - V_43 ) , V_43 ) ;
V_62 -> V_18 = 0 ;
V_62 -> V_4 = V_43 ;
}
if ( V_62 -> V_4 >= V_43 && V_5 != V_64 && ( V_46 -> V_65 & 128 ) && ! ( V_46 -> V_65 & 64 ) )
F_14 ( V_1 , V_62 , ( V_46 -> V_65 & 7 ) , V_1 -> V_7 - V_46 -> V_14 , V_1 -> V_18 + ( V_3 - V_46 -> V_51 ) ) ;
}
#endif
V_49 = ( V_49 + V_50 - V_46 -> V_51 ) ;
V_50 = V_46 -> V_51 ;
} while ( V_46 -> V_51 && V_5 != V_64 );
V_1 -> V_66 = V_2 ;
V_1 -> V_4 = V_3 - V_46 -> V_51 ;
if ( V_5 == V_64 ) {
if ( F_11 ( V_1 , & V_48 ) != - 1 &&
F_11 ( V_1 , & V_25 ) != - 1 ) {
if ( V_48 != V_46 -> V_45 && ! V_1 -> V_67 ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = L_2 ;
} else if ( V_25 != ( V_46 -> V_47 & 0xffffffffUL ) ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = L_3 ;
}
}
V_1 -> V_30 = V_68 ;
F_23 ( V_1 -> V_61 ) ;
V_1 -> V_61 = NULL ;
}
}
static int
F_24 ( T_1 V_1 )
{
if ( V_1 -> V_14 == 0 ) {
if ( F_3 ( V_1 ) == - 1 )
return - 1 ;
if ( V_1 -> V_14 == 0 )
return 0 ;
}
#ifdef F_25
if ( V_1 -> V_15 [ 0 ] == 31 ) {
V_1 -> V_14 -- ;
V_1 -> V_15 ++ ;
if ( V_1 -> V_14 == 0 && F_3 ( V_1 ) == - 1 )
return - 1 ;
if ( V_1 -> V_14 && V_1 -> V_15 [ 0 ] == 139 ) {
T_6 V_69 ;
T_6 V_70 ;
T_7 V_25 ;
T_7 V_71 ;
V_1 -> V_14 -- ;
V_1 -> V_15 ++ ;
if ( F_8 ( V_1 , & V_69 ) == - 1 )
return - 1 ;
if ( V_69 != 8 ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = L_4 ;
return - 1 ;
}
if ( F_8 ( V_1 , & V_70 ) == - 1 )
return - 1 ;
if ( V_70 & 0xe0 ) {
V_1 -> V_8 = V_55 ;
V_1 -> V_10 = L_5 ;
return - 1 ;
}
if ( F_12 ( V_1 , 4 ) == - 1 )
return - 1 ;
if ( F_12 ( V_1 , 1 ) == - 1 )
return - 1 ;
if ( F_12 ( V_1 , 1 ) == - 1 )
return - 1 ;
if ( V_70 & 4 ) {
if ( F_10 ( V_1 , & V_25 ) == - 1 )
return - 1 ;
if ( F_12 ( V_1 , V_25 ) == - 1 )
return - 1 ;
}
if ( V_70 & 8 ) {
if ( F_13 ( V_1 ) == - 1 )
return - 1 ;
}
if ( V_70 & 16 ) {
if ( F_13 ( V_1 ) == - 1 )
return - 1 ;
}
if ( V_70 & 2 ) {
if ( F_10 ( V_1 , & V_71 ) == - 1 )
return - 1 ;
}
F_26 ( & ( V_1 -> V_46 ) ) ;
V_1 -> V_46 . V_45 = F_22 ( 0L , V_72 , 0 ) ;
V_1 -> V_30 = V_39 ;
V_1 -> V_73 = TRUE ;
#ifdef F_17
if ( V_1 -> V_24 ) {
struct V_35 * V_62 = F_6 ( struct V_35 , 1 ) ;
V_62 -> V_18 = V_62 -> V_4 = 0 ;
F_23 ( V_1 -> V_61 ) ;
V_1 -> V_61 = V_62 ;
F_5 ( V_1 , V_1 -> V_7 - V_1 -> V_14 , V_1 -> V_18 , V_74 ) ;
}
#endif
return 0 ;
}
else {
V_1 -> V_27 [ 0 ] = 31 ;
V_1 -> V_4 = 1 ;
}
}
#endif
#ifdef F_27
#endif
if ( V_1 -> V_24 )
F_5 ( V_1 , V_1 -> V_7 - V_1 -> V_14 - V_1 -> V_4 , V_1 -> V_18 , V_75 ) ;
V_1 -> V_76 = V_1 -> V_18 ;
V_1 -> V_66 = V_1 -> V_27 ;
if ( V_1 -> V_14 ) {
memcpy ( V_1 -> V_66 + V_1 -> V_4 , V_1 -> V_15 , V_1 -> V_14 ) ;
V_1 -> V_4 += V_1 -> V_14 ;
V_1 -> V_14 = 0 ;
}
V_1 -> V_30 = V_75 ;
return 0 ;
}
static int
F_28 ( T_1 V_1 )
{
if ( V_1 -> V_30 == V_68 ) {
if ( F_24 ( V_1 ) == - 1 )
return - 1 ;
if ( V_1 -> V_4 )
return 0 ;
}
if ( V_1 -> V_30 == V_75 ) {
if ( F_1 ( V_1 , V_1 -> V_27 , V_1 -> V_13 , & ( V_1 -> V_4 ) ) == - 1 )
return - 1 ;
V_1 -> V_66 = V_1 -> V_27 ;
}
#ifdef F_25
else if ( V_1 -> V_30 == V_39 ) {
F_16 ( V_1 , V_1 -> V_27 , V_1 -> V_13 << 1 ) ;
}
#endif
return 0 ;
}
static int
F_29 ( T_1 V_1 , T_4 V_25 )
{
T_2 V_34 ;
while ( V_25 )
if ( V_1 -> V_4 ) {
V_34 = ( T_4 ) V_1 -> V_4 > V_25 ? ( unsigned ) V_25 : V_1 -> V_4 ;
V_1 -> V_4 -= V_34 ;
V_1 -> V_66 += V_34 ;
V_1 -> V_18 += V_34 ;
V_25 -= V_34 ;
} else if ( V_1 -> V_8 ) {
return - 1 ;
} else if ( V_1 -> V_11 && V_1 -> V_14 == 0 ) {
break;
} else {
if ( F_28 ( V_1 ) == - 1 )
return - 1 ;
}
return 0 ;
}
static void
F_30 ( T_1 V_1 )
{
V_1 -> V_4 = 0 ;
V_1 -> V_11 = FALSE ;
V_1 -> V_30 = V_68 ;
V_1 -> V_77 = FALSE ;
V_1 -> V_8 = 0 ;
V_1 -> V_10 = NULL ;
V_1 -> V_18 = 0 ;
V_1 -> V_14 = 0 ;
}
T_1
F_31 ( int V_6 )
{
#ifdef F_32
T_11 V_78 ;
#endif
int V_79 = V_80 ;
T_1 V_1 ;
if ( V_6 == - 1 )
return NULL ;
V_1 = ( T_1 ) F_33 ( sizeof *V_1 ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_61 = NULL ;
V_1 -> V_24 = NULL ;
V_1 -> V_6 = V_6 ;
V_1 -> V_73 = FALSE ;
V_1 -> V_81 = F_34 ( V_1 -> V_6 , 0 , V_82 ) ;
if ( V_1 -> V_81 == - 1 ) V_1 -> V_81 = 0 ;
V_1 -> V_7 = V_1 -> V_81 ;
F_30 ( V_1 ) ;
#ifdef F_32
if ( F_35 ( V_6 , & V_78 ) >= 0 ) {
if ( V_78 . V_83 <= V_84 )
V_79 = ( int ) V_78 . V_83 ;
}
#endif
V_1 -> V_12 = ( unsigned char * ) F_33 ( V_79 ) ;
V_1 -> V_27 = ( unsigned char * ) F_33 ( V_79 << 1 ) ;
V_1 -> V_13 = V_79 ;
if ( V_1 -> V_12 == NULL || V_1 -> V_27 == NULL ) {
F_23 ( V_1 -> V_27 ) ;
F_23 ( V_1 -> V_12 ) ;
F_23 ( V_1 ) ;
V_9 = V_59 ;
return NULL ;
}
#ifdef F_25
V_1 -> V_46 . V_85 = V_72 ;
V_1 -> V_46 . V_86 = V_72 ;
V_1 -> V_46 . V_87 = V_72 ;
V_1 -> V_46 . V_14 = 0 ;
V_1 -> V_46 . V_15 = V_72 ;
if ( F_36 ( & ( V_1 -> V_46 ) , - 15 ) != V_88 ) {
F_23 ( V_1 -> V_27 ) ;
F_23 ( V_1 -> V_12 ) ;
F_23 ( V_1 ) ;
V_9 = V_59 ;
return NULL ;
}
V_1 -> V_67 = FALSE ;
#endif
return V_1 ;
}
T_1
F_37 ( const char * V_89 )
{
int V_6 ;
T_1 V_90 ;
#ifdef F_25
const char * V_91 ;
#endif
if ( ( V_6 = F_38 ( V_89 , V_92 | V_93 , 0000 ) ) == - 1 )
return NULL ;
V_90 = F_31 ( V_6 ) ;
if ( V_90 == NULL ) {
F_39 ( V_6 ) ;
return NULL ;
}
#ifdef F_25
V_91 = strrchr ( V_89 , '.' ) ;
if ( V_91 != NULL ) {
if ( F_40 ( V_91 , L_6 ) == 0 )
V_90 -> V_67 = TRUE ;
}
#endif
return V_90 ;
}
void
F_41 ( T_1 V_94 , T_12 T_13 V_95 , T_14 * V_96 )
{
V_94 -> V_24 = V_96 ;
}
T_4
F_42 ( T_1 V_17 , T_4 V_97 , int V_98 , int * V_8 )
{
struct V_16 * V_99 ;
T_2 V_34 ;
if ( V_98 != V_100 && V_98 != V_82 && V_98 != V_101 ) {
F_43 () ;
}
if ( V_98 == V_101 ) {
if ( F_29 ( V_17 , V_102 ) == - 1 ) {
* V_8 = V_17 -> V_8 ;
return - 1 ;
}
if ( V_97 == 0 ) {
return V_17 -> V_18 ;
}
} else if ( V_98 == V_100 )
V_97 -= V_17 -> V_18 ;
else if ( V_17 -> V_77 )
V_97 += V_17 -> V_103 ;
V_17 -> V_77 = FALSE ;
if ( V_97 < 0 && V_17 -> V_66 ) {
T_2 V_104 = ( unsigned ) ( V_17 -> V_66 - V_17 -> V_27 ) ;
if ( - V_97 <= V_104 ) {
T_2 V_105 = ( unsigned ) ( - V_97 ) ;
V_17 -> V_4 += V_105 ;
V_17 -> V_66 -= V_105 ;
V_17 -> V_18 -= V_105 ;
return V_17 -> V_18 ;
}
}
if ( ( V_99 = F_4 ( V_17 , V_17 -> V_18 + V_97 ) ) && ( V_97 < 0 || V_97 > V_38 || V_99 -> V_30 == V_75 ) ) {
T_4 V_106 , V_107 ;
#ifdef F_25
if ( V_99 -> V_30 == V_39 ) {
#ifdef F_15
V_106 = V_99 -> V_12 - ( V_99 -> V_40 . V_41 . V_37 ? 1 : 0 ) ;
#else
V_106 = V_99 -> V_12 ;
#endif
V_107 = V_99 -> V_27 ;
} else if ( V_99 -> V_30 == V_74 ) {
V_106 = V_99 -> V_12 ;
V_107 = V_99 -> V_27 ;
} else
#endif
{
V_107 = ( V_17 -> V_18 + V_97 ) ;
V_106 = V_99 -> V_12 + ( V_107 - V_99 -> V_27 ) ;
}
if ( F_34 ( V_17 -> V_6 , V_106 , V_100 ) == - 1 ) {
* V_8 = V_9 ;
return - 1 ;
}
F_44 ( V_17 ) ;
V_17 -> V_7 = V_106 ;
V_17 -> V_4 = 0 ;
V_17 -> V_11 = FALSE ;
V_17 -> V_77 = FALSE ;
V_17 -> V_8 = 0 ;
V_17 -> V_10 = NULL ;
V_17 -> V_14 = 0 ;
#ifdef F_25
if ( V_99 -> V_30 == V_39 ) {
T_15 * V_46 = & V_17 -> V_46 ;
F_26 ( V_46 ) ;
V_46 -> V_45 = V_99 -> V_40 . V_41 . V_45 ;
V_46 -> V_47 = V_99 -> V_40 . V_41 . V_47 ;
#ifdef F_15
if ( V_99 -> V_40 . V_41 . V_37 ) {
T_1 V_1 = V_17 ;
int V_5 = F_9 () ;
if ( V_5 == - 1 ) {
if ( V_1 -> V_8 == 0 ) {
* V_8 = V_33 ;
} else
* V_8 = V_1 -> V_8 ;
return - 1 ;
}
( void ) F_45 ( V_46 , V_99 -> V_40 . V_41 . V_37 , V_5 >> ( 8 - V_99 -> V_40 . V_41 . V_37 ) ) ;
}
#endif
( void ) F_46 ( V_46 , V_99 -> V_40 . V_41 . V_44 , V_43 ) ;
V_17 -> V_30 = V_39 ;
} else if ( V_99 -> V_30 == V_74 ) {
T_15 * V_46 = & V_17 -> V_46 ;
F_26 ( V_46 ) ;
V_46 -> V_45 = F_22 ( 0L , V_72 , 0 ) ;
V_17 -> V_30 = V_39 ;
} else
#endif
V_17 -> V_30 = V_99 -> V_30 ;
V_97 = ( V_17 -> V_18 + V_97 ) - V_107 ;
V_17 -> V_18 = V_107 ;
if ( V_97 ) {
V_17 -> V_77 = TRUE ;
V_17 -> V_103 = V_97 ;
}
return V_17 -> V_18 + V_97 ;
}
if ( V_17 -> V_30 == V_75 && V_17 -> V_18 + V_97 >= V_17 -> V_76
&& ( V_97 < 0 || V_97 >= V_17 -> V_4 )
&& ( V_17 -> V_24 ) )
{
if ( F_34 ( V_17 -> V_6 , V_97 - V_17 -> V_4 , V_82 ) == - 1 ) {
* V_8 = V_9 ;
return - 1 ;
}
V_17 -> V_7 += ( V_97 - V_17 -> V_4 ) ;
V_17 -> V_4 = 0 ;
V_17 -> V_11 = FALSE ;
V_17 -> V_77 = FALSE ;
V_17 -> V_8 = 0 ;
V_17 -> V_10 = NULL ;
V_17 -> V_14 = 0 ;
V_17 -> V_18 += V_97 ;
return V_17 -> V_18 ;
}
if ( V_97 < 0 ) {
V_97 += V_17 -> V_18 ;
if ( V_97 < 0 ) {
* V_8 = V_108 ;
return - 1 ;
}
if ( F_34 ( V_17 -> V_6 , V_17 -> V_81 , V_100 ) == - 1 ) {
* V_8 = V_9 ;
return - 1 ;
}
F_44 ( V_17 ) ;
V_17 -> V_7 = V_17 -> V_81 ;
F_30 ( V_17 ) ;
}
V_34 = ( T_4 ) V_17 -> V_4 > V_97 ? ( unsigned ) V_97 : V_17 -> V_4 ;
V_17 -> V_4 -= V_34 ;
V_17 -> V_66 += V_34 ;
V_17 -> V_18 += V_34 ;
V_97 -= V_34 ;
if ( V_97 ) {
V_17 -> V_77 = TRUE ;
V_17 -> V_103 = V_97 ;
}
return V_17 -> V_18 + V_97 ;
}
T_12
F_47 ( T_1 V_17 , T_4 V_109 , int * V_8 )
{
if ( F_42 ( V_17 , V_109 , V_82 , V_8 ) == - 1 )
return FALSE ;
return TRUE ;
}
T_4
F_48 ( T_1 V_94 )
{
return V_94 -> V_18 + ( V_94 -> V_77 ? V_94 -> V_103 : 0 ) ;
}
T_4
F_49 ( T_1 V_94 )
{
return V_94 -> V_7 ;
}
int
F_50 ( T_1 V_94 , T_11 * V_110 , int * V_8 )
{
if ( F_35 ( V_94 -> V_6 , V_110 ) == - 1 ) {
if ( V_8 != NULL )
* V_8 = V_9 ;
return - 1 ;
}
return 0 ;
}
T_12
F_51 ( T_1 V_94 )
{
return V_94 -> V_73 ;
}
int
F_52 ( void * V_2 , unsigned int V_25 , T_1 V_17 )
{
T_2 V_111 , V_34 ;
if ( V_25 == 0 )
return 0 ;
if ( V_17 -> V_77 ) {
V_17 -> V_77 = FALSE ;
if ( F_29 ( V_17 , V_17 -> V_103 ) == - 1 )
return - 1 ;
}
V_111 = 0 ;
do {
if ( V_17 -> V_4 ) {
V_34 = V_17 -> V_4 > V_25 ? V_25 : V_17 -> V_4 ;
memcpy ( V_2 , V_17 -> V_66 , V_34 ) ;
V_17 -> V_66 += V_34 ;
V_17 -> V_4 -= V_34 ;
} else if ( V_17 -> V_8 ) {
return - 1 ;
} else if ( V_17 -> V_11 && V_17 -> V_14 == 0 ) {
break;
} else {
if ( F_28 ( V_17 ) == - 1 )
return - 1 ;
continue;
}
V_25 -= V_34 ;
V_2 = ( char * ) V_2 + V_34 ;
V_111 += V_34 ;
V_17 -> V_18 += V_34 ;
} while ( V_25 );
return ( int ) V_111 ;
}
int
F_53 ( T_1 V_17 )
{
int V_5 = 0 ;
if ( V_17 -> V_8 )
return - 1 ;
if ( V_17 -> V_4 ) {
return * ( V_17 -> V_66 ) ;
}
if ( V_17 -> V_77 ) {
V_17 -> V_77 = FALSE ;
if ( F_29 ( V_17 , V_17 -> V_103 ) == - 1 )
return - 1 ;
}
while ( 1 ) {
if ( V_17 -> V_4 ) {
return * ( V_17 -> V_66 ) ;
}
else if ( V_17 -> V_8 ) {
return - 1 ;
}
else if ( V_17 -> V_11 && V_17 -> V_14 == 0 ) {
return - 1 ;
}
else if ( F_28 ( V_17 ) == - 1 ) {
return - 1 ;
}
}
return V_5 ;
}
int
F_54 ( T_1 V_17 )
{
unsigned char V_2 [ 1 ] ;
int V_5 ;
if ( V_17 -> V_8 )
return - 1 ;
if ( V_17 -> V_4 ) {
V_17 -> V_4 -- ;
V_17 -> V_18 ++ ;
return * ( V_17 -> V_66 ) ++ ;
}
V_5 = F_52 ( V_2 , 1 , V_17 ) ;
return V_5 < 1 ? - 1 : V_2 [ 0 ] ;
}
char *
F_55 ( char * V_2 , int V_25 , T_1 V_17 )
{
T_2 V_42 , V_34 ;
char * V_112 ;
unsigned char * V_113 ;
if ( V_2 == NULL || V_25 < 1 )
return NULL ;
if ( V_17 -> V_8 )
return NULL ;
if ( V_17 -> V_77 ) {
V_17 -> V_77 = FALSE ;
if ( F_29 ( V_17 , V_17 -> V_103 ) == - 1 )
return NULL ;
}
V_112 = V_2 ;
V_42 = ( unsigned ) V_25 - 1 ;
if ( V_42 ) do {
if ( V_17 -> V_4 == 0 ) {
if ( V_17 -> V_8 ) {
return NULL ;
}
if ( F_28 ( V_17 ) == - 1 )
return NULL ;
if ( V_17 -> V_4 == 0 ) {
if ( V_2 == V_112 )
return NULL ;
break;
}
}
V_34 = V_17 -> V_4 > V_42 ? V_42 : V_17 -> V_4 ;
V_113 = ( unsigned char * ) memchr ( V_17 -> V_66 , '\n' , V_34 ) ;
if ( V_113 != NULL )
V_34 = ( unsigned ) ( V_113 - V_17 -> V_66 ) + 1 ;
memcpy ( V_2 , V_17 -> V_66 , V_34 ) ;
V_17 -> V_4 -= V_34 ;
V_17 -> V_66 += V_34 ;
V_17 -> V_18 += V_34 ;
V_42 -= V_34 ;
V_2 += V_34 ;
} while ( V_42 && V_113 == NULL );
V_2 [ 0 ] = 0 ;
return V_112 ;
}
int
F_56 ( T_1 V_17 )
{
return ( V_17 -> V_11 && V_17 -> V_14 == 0 && V_17 -> V_4 == 0 ) ;
}
int
F_57 ( T_1 V_114 , T_16 * * V_10 )
{
if ( V_114 -> V_8 != 0 && V_10 ) {
* V_10 = F_58 ( V_114 -> V_10 ) ;
}
return V_114 -> V_8 ;
}
void
F_59 ( T_1 V_94 )
{
V_94 -> V_8 = 0 ;
V_94 -> V_10 = NULL ;
V_94 -> V_11 = FALSE ;
}
void
F_60 ( T_1 V_17 )
{
F_39 ( V_17 -> V_6 ) ;
V_17 -> V_6 = - 1 ;
}
T_12
F_61 ( T_1 V_17 , const char * V_89 )
{
int V_6 ;
if ( ( V_6 = F_38 ( V_89 , V_92 | V_93 , 0000 ) ) == - 1 )
return FALSE ;
V_17 -> V_6 = V_6 ;
return TRUE ;
}
void
F_62 ( T_1 V_17 )
{
int V_6 = V_17 -> V_6 ;
if ( V_17 -> V_13 ) {
#ifdef F_25
F_63 ( & ( V_17 -> V_46 ) ) ;
#endif
F_23 ( V_17 -> V_27 ) ;
F_23 ( V_17 -> V_12 ) ;
}
F_23 ( V_17 -> V_61 ) ;
V_17 -> V_8 = 0 ;
V_17 -> V_10 = NULL ;
F_23 ( V_17 ) ;
if ( V_6 != - 1 )
F_39 ( V_6 ) ;
}
T_17
F_64 ( const char * V_89 )
{
int V_6 ;
T_17 V_1 ;
int V_115 ;
V_6 = F_38 ( V_89 , V_93 | V_116 | V_117 | V_118 , 0666 ) ;
if ( V_6 == - 1 )
return NULL ;
V_1 = F_65 ( V_6 ) ;
if ( V_1 == NULL ) {
V_115 = V_9 ;
F_39 ( V_6 ) ;
V_9 = V_115 ;
}
return V_1 ;
}
T_17
F_65 ( int V_6 )
{
T_17 V_1 ;
V_1 = ( T_17 ) F_33 ( sizeof *V_1 ) ;
if ( V_1 == NULL )
return NULL ;
V_1 -> V_6 = V_6 ;
V_1 -> V_13 = 0 ;
V_1 -> V_79 = V_80 ;
V_1 -> V_119 = V_120 ;
V_1 -> V_121 = V_122 ;
V_1 -> V_8 = V_88 ;
V_1 -> V_18 = 0 ;
V_1 -> V_46 . V_14 = 0 ;
return V_1 ;
}
static int
F_66 ( T_17 V_1 )
{
int V_5 ;
T_10 V_46 = & ( V_1 -> V_46 ) ;
V_1 -> V_12 = ( unsigned char * ) F_33 ( V_1 -> V_79 ) ;
V_1 -> V_27 = ( unsigned char * ) F_33 ( V_1 -> V_79 ) ;
if ( V_1 -> V_12 == NULL || V_1 -> V_27 == NULL ) {
F_23 ( V_1 -> V_27 ) ;
F_23 ( V_1 -> V_12 ) ;
V_1 -> V_8 = V_59 ;
return - 1 ;
}
V_46 -> V_85 = V_72 ;
V_46 -> V_86 = V_72 ;
V_46 -> V_87 = V_72 ;
V_5 = F_67 ( V_46 , V_1 -> V_119 , V_123 ,
15 + 16 , 8 , V_1 -> V_121 ) ;
if ( V_5 != V_88 ) {
F_23 ( V_1 -> V_27 ) ;
F_23 ( V_1 -> V_12 ) ;
if ( V_5 == V_58 ) {
V_1 -> V_8 = V_59 ;
} else {
V_1 -> V_8 = V_124 ;
}
return - 1 ;
}
V_1 -> V_13 = V_1 -> V_79 ;
V_46 -> V_51 = V_1 -> V_13 ;
V_46 -> V_52 = V_1 -> V_27 ;
V_1 -> V_66 = V_46 -> V_52 ;
return 0 ;
}
static int
F_68 ( T_17 V_1 , int V_125 )
{
int V_5 ;
T_3 V_111 ;
T_18 V_4 ;
T_10 V_46 = & ( V_1 -> V_46 ) ;
if ( V_1 -> V_13 == 0 && F_66 ( V_1 ) == - 1 )
return - 1 ;
V_5 = V_88 ;
do {
if ( V_46 -> V_51 == 0 || ( V_125 != V_53 &&
( V_125 != V_126 || V_5 == V_64 ) ) ) {
V_4 = V_46 -> V_52 - V_1 -> V_66 ;
if ( V_4 ) {
V_111 = F_69 ( V_1 -> V_6 , V_1 -> V_66 , ( unsigned int ) V_4 ) ;
if ( V_111 < 0 ) {
V_1 -> V_8 = V_9 ;
return - 1 ;
}
if ( ( T_18 ) V_111 != V_4 ) {
V_1 -> V_8 = V_127 ;
return - 1 ;
}
}
if ( V_46 -> V_51 == 0 ) {
V_46 -> V_51 = V_1 -> V_13 ;
V_46 -> V_52 = V_1 -> V_27 ;
}
V_1 -> V_66 = V_46 -> V_52 ;
}
V_4 = V_46 -> V_51 ;
V_5 = F_70 ( V_46 , V_125 ) ;
if ( V_5 == V_54 ) {
V_1 -> V_8 = V_124 ;
return - 1 ;
}
V_4 -= V_46 -> V_51 ;
} while ( V_4 );
if ( V_125 == V_126 )
F_71 ( V_46 ) ;
return 0 ;
}
unsigned
F_72 ( T_17 V_1 , const void * V_2 , T_2 V_25 )
{
T_2 V_128 = V_25 ;
T_2 V_34 ;
T_10 V_46 ;
V_46 = & ( V_1 -> V_46 ) ;
if ( V_1 -> V_8 != V_88 )
return 0 ;
if ( V_25 == 0 )
return 0 ;
if ( V_1 -> V_13 == 0 && F_66 ( V_1 ) == - 1 )
return 0 ;
if ( V_25 < V_1 -> V_13 ) {
do {
if ( V_46 -> V_14 == 0 )
V_46 -> V_15 = V_1 -> V_12 ;
V_34 = V_1 -> V_13 - V_46 -> V_14 ;
if ( V_34 > V_25 )
V_34 = V_25 ;
#ifdef F_19
F_20 (cast-qual)
memcpy ( ( V_129 * ) V_46 -> V_15 + V_46 -> V_14 , V_2 , V_34 ) ;
F_21 (cast-qual)
#else
memcpy ( V_46 -> V_15 + V_46 -> V_14 , V_2 , V_34 ) ;
#endif
V_46 -> V_14 += V_34 ;
V_1 -> V_18 += V_34 ;
V_2 = ( const char * ) V_2 + V_34 ;
V_25 -= V_34 ;
if ( V_25 && F_68 ( V_1 , V_53 ) == - 1 )
return 0 ;
} while ( V_25 );
}
else {
if ( V_46 -> V_14 && F_68 ( V_1 , V_53 ) == - 1 )
return 0 ;
V_46 -> V_14 = V_25 ;
#ifdef F_19
V_46 -> V_15 = ( F_19 V_129 * ) V_2 ;
#else
F_20 (cast-qual)
V_46 -> V_15 = ( V_129 * ) V_2 ;
F_21 (cast-qual)
#endif
V_1 -> V_18 += V_25 ;
if ( F_68 ( V_1 , V_53 ) == - 1 )
return 0 ;
}
return ( int ) V_128 ;
}
int
F_73 ( T_17 V_1 )
{
if ( V_1 -> V_8 != V_88 )
return - 1 ;
F_68 ( V_1 , V_130 ) ;
if ( V_1 -> V_8 != V_88 )
return - 1 ;
return 0 ;
}
int
F_74 ( T_17 V_1 , T_12 V_131 )
{
int V_5 = 0 ;
if ( F_68 ( V_1 , V_126 ) == - 1 && V_5 == 0 )
V_5 = V_1 -> V_8 ;
( void ) F_75 ( & ( V_1 -> V_46 ) ) ;
F_23 ( V_1 -> V_27 ) ;
F_23 ( V_1 -> V_12 ) ;
V_1 -> V_8 = V_88 ;
if ( ! V_131 ) {
if ( F_39 ( V_1 -> V_6 ) == - 1 && V_5 == 0 )
V_5 = V_9 ;
}
F_23 ( V_1 ) ;
return V_5 ;
}
int
F_76 ( T_17 V_1 )
{
return V_1 -> V_8 ;
}
