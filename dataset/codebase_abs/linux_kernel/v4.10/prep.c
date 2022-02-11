static void F_1 ( struct V_1 * V_2 [ 2 ] ,
T_1 V_3 , T_2 V_4 , int V_5 )
{
struct V_1 * V_6 = V_2 [ V_7 >> V_5 & 1 ] ;
V_6 -> V_8 [ V_9 [ V_5 ] ] = V_3 + V_4 ;
}
static T_1 F_2 ( struct V_1 * V_2 [ 2 ] , int V_5 )
{
struct V_1 * V_6 = V_2 [ V_10 >> V_5 & 1 ] ;
return V_6 -> V_8 [ V_11 [ V_5 ] ] ;
}
static T_1 F_3 ( struct V_1 * V_12 [ 3 ] , int V_5 )
{
struct V_1 * V_6 = V_12 [ V_13 [ V_5 ] ] ;
return V_6 -> V_8 [ V_14 [ V_5 ] ] ;
}
static void F_4 ( struct V_1 * V_2 [ 2 ] ,
T_1 V_3 , T_2 V_4 , T_3 V_15 , int V_5 )
{
struct V_16 * V_17 = (struct V_16 * ) V_2 [ 0 ] ;
struct V_1 * V_6 = V_2 [ V_10 >> V_5 & 1 ] ;
V_6 -> V_8 [ V_11 [ V_5 ] ] = V_3 + V_4 ;
V_17 -> V_15 [ V_5 ] = V_15 ;
}
static void F_5 ( struct V_1 * V_12 [ 3 ] ,
T_1 V_3 , T_2 V_4 , T_3 V_15 , unsigned V_5 )
{
struct V_16 * V_17 = (struct V_16 * ) V_12 [ 0 ] ;
struct V_18 * V_19 =
(struct V_18 * ) V_12 [ 1 ] ;
struct V_1 * V_6 = V_12 [ V_13 [ V_5 ] ] ;
V_6 -> V_8 [ V_14 [ V_5 ] ] = V_3 + V_4 ;
if ( V_5 < 8 )
V_17 -> V_15 [ V_5 ] = V_15 ;
else
V_19 -> V_15 [ V_5 - 8 ] = V_15 ;
}
static struct V_20 *
F_6 ( struct V_21 * V_22 , unsigned int V_23 )
{
struct V_20 * V_24 ;
T_4 V_25 = V_26 | V_27 ;
V_24 = F_7 ( V_28 , V_25 ) ;
if ( ! V_24 )
return NULL ;
V_24 -> V_23 = V_23 ;
V_24 -> V_29 = F_8 ( V_22 -> V_30 [ V_23 ] ,
V_25 , & V_24 -> V_31 ) ;
if ( ! V_24 -> V_29 ) {
F_9 ( V_28 , V_24 ) ;
return NULL ;
}
return V_24 ;
}
struct V_32 *
F_10 ( struct V_33 * V_34 , T_1 V_35 ,
T_1 V_36 , T_5 V_37 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_34 ) ;
struct V_40 * V_29 ;
struct V_41 * V_12 ;
T_1 V_42 = V_35 ;
T_1 V_43 = V_36 ;
T_5 V_44 = V_37 ;
int V_45 , V_5 , V_46 ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
V_45 = F_13 ( V_39 , V_37 ) ;
if ( F_14 ( V_45 ) &&
F_15 ( V_39 , V_45 ) == 0 )
V_5 = V_39 -> V_49 ;
else
return NULL ;
V_46 = 0 ;
do {
T_5 V_50 = F_16 ( T_5 , V_37 , 1 << V_39 -> V_51 ) ;
V_12 = F_17 ( V_39 , V_5 + V_46 ) ;
V_29 = V_12 -> V_29 ;
V_29 -> V_52 = V_50 ;
V_29 -> V_53 = 0 ;
V_29 -> V_54 = V_43 ;
V_29 -> V_55 = V_42 ;
V_37 -= V_50 ;
V_42 += V_50 ;
V_43 += V_50 ;
F_18 ( V_39 , V_12 ) ;
} while ( ++ V_46 < V_45 );
V_12 -> V_56 . V_25 = V_25 ;
V_12 -> V_37 = V_44 ;
V_29 -> V_57 . V_58 = ! ! ( V_25 & V_59 ) ;
V_29 -> V_57 . V_60 = ! ! ( V_25 & V_61 ) ;
V_29 -> V_57 . V_62 = 1 ;
F_18 ( V_39 , V_12 ) ;
return & V_12 -> V_56 ;
}
static struct V_32 *
F_19 ( struct V_33 * V_34 , enum V_63 * V_64 ,
T_1 V_65 , T_1 * V_43 , unsigned int V_66 ,
T_5 V_37 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_34 ) ;
struct V_41 * V_67 ;
struct V_41 * V_12 ;
struct V_41 * V_68 ;
T_5 V_44 = V_37 ;
struct V_69 * V_70 ;
struct V_71 * V_72 = NULL ;
struct V_40 * V_29 ;
int V_45 , V_73 , V_5 , V_46 ;
T_2 V_4 = 0 ;
T_3 V_74 = V_64 ? V_75 : V_76 ;
F_20 ( V_66 < 2 ) ;
V_45 = F_13 ( V_39 , V_37 ) ;
if ( V_66 > 5 ) {
V_73 = 1 ;
V_45 *= 2 ;
} else
V_73 = 0 ;
if ( F_14 ( V_45 ) &&
F_15 ( V_39 , V_45 + 1 ) == 0 )
V_5 = V_39 -> V_49 ;
else
return NULL ;
V_46 = 0 ;
do {
struct V_1 * V_2 [ 2 ] ;
T_5 V_77 = F_16 ( T_5 ,
V_37 , 1 << V_39 -> V_51 ) ;
int V_78 ;
V_12 = F_17 ( V_39 , V_5 + V_46 ) ;
V_70 = V_12 -> V_70 ;
V_68 = F_17 ( V_39 , V_5 + V_46 + 1 ) ;
V_72 = V_68 -> V_72 ;
V_2 [ 0 ] = (struct V_1 * ) V_70 ;
V_2 [ 1 ] = (struct V_1 * ) V_72 ;
for ( V_78 = 0 ; V_78 < V_66 ; V_78 ++ )
F_1 ( V_2 , V_43 [ V_78 ] , V_4 , V_78 ) ;
V_70 -> V_52 = V_77 ;
V_70 -> V_55 = V_65 + V_4 ;
V_70 -> V_53 = 0 ;
V_70 -> V_57 . V_74 = V_74 ;
V_70 -> V_57 . V_66 = F_21 ( V_66 ) ;
V_37 -= V_77 ;
V_4 += V_77 ;
F_18 ( V_39 , V_12 ) ;
} while ( ( V_46 += 1 + V_73 ) < V_45 );
V_12 -> V_56 . V_25 = V_25 ;
V_12 -> V_37 = V_44 ;
if ( V_64 )
V_12 -> V_64 = V_64 ;
V_70 -> V_57 . V_60 = ! ! ( V_25 & V_61 ) ;
V_67 = F_17 ( V_39 , V_5 + V_46 ) ;
V_67 -> V_56 . V_25 = V_25 & V_59 ;
V_29 = V_67 -> V_29 ;
V_29 -> V_53 = 0 ;
V_29 -> V_57 . null = 1 ;
V_29 -> V_57 . V_58 = ! ! ( V_25 & V_59 ) ;
V_29 -> V_57 . V_62 = 1 ;
V_29 -> V_52 = V_79 ;
F_18 ( V_39 , V_67 ) ;
return & V_67 -> V_56 ;
}
struct V_32 *
F_22 ( struct V_33 * V_80 , T_1 V_65 , T_1 * V_43 ,
unsigned int V_66 , T_5 V_37 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_80 ) ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
return F_19 ( V_80 , NULL , V_65 , V_43 , V_66 , V_37 , V_25 ) ;
}
struct V_32 *
F_23 ( struct V_33 * V_80 , T_1 * V_43 ,
unsigned int V_66 , T_5 V_37 ,
enum V_63 * V_64 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_80 ) ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
* V_64 = 0 ;
return F_19 ( V_80 , V_64 , V_43 [ 0 ] , & V_43 [ 1 ] ,
V_66 - 1 , V_37 , V_25 ) ;
}
static void
F_24 ( struct V_38 * V_39 , struct V_41 * V_12 ,
struct V_41 * V_68 )
{
struct V_81 * V_82 = F_25 ( V_39 ) ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_83 * V_84 = V_68 ? V_68 -> V_84 : NULL ;
struct V_1 * V_2 [] = { ( void * ) V_17 , ( void * ) V_84 } ;
int V_66 = F_26 ( V_17 -> V_57 . V_66 ) ;
int V_46 ;
F_27 ( V_82 , L_1
L_2
L_3 ,
F_28 ( V_12 ) , ( unsigned long long ) V_12 -> V_56 . V_85 ,
( unsigned long long ) ( V_84 ? V_84 -> V_86 : V_17 -> V_86 ) ,
V_12 -> V_56 . V_25 , V_17 -> V_52 , V_17 -> V_53 , V_17 -> V_57 . V_74 ,
V_17 -> V_57 . V_58 , V_17 -> V_57 . V_62 ,
V_17 -> V_57 . V_87 ? L_4 : L_5 , V_17 -> V_57 . V_88 ? L_4 : L_6 ,
V_17 -> V_57 . V_66 ) ;
for ( V_46 = 0 ; V_46 < V_66 ; V_46 ++ )
F_27 ( V_82 , L_7 , V_46 ,
( unsigned long long ) F_2 ( V_2 , V_46 ) , V_17 -> V_15 [ V_46 ] ) ;
F_27 ( V_82 , L_8 , V_17 -> V_89 ) ;
F_27 ( V_82 , L_9 , V_17 -> V_90 ) ;
F_27 ( V_82 , L_10 , V_17 -> V_86 ) ;
}
static void F_29 ( struct V_38 * V_39 ,
struct V_41 * V_12 )
{
struct V_81 * V_82 = F_25 ( V_39 ) ;
struct V_16 * V_17 = V_12 -> V_17 ;
struct V_1 * V_2 [] = { ( void * ) V_17 ,
( void * ) V_17 ,
( void * ) V_17 } ;
int V_66 = F_30 ( V_17 -> V_57 . V_66 ) ;
int V_46 ;
if ( V_12 -> V_24 ) {
V_2 [ 1 ] = ( void * ) V_12 -> V_24 -> V_29 ;
V_2 [ 2 ] = ( void * ) V_12 -> V_24 -> V_29 + 64 ;
}
F_27 ( V_82 , L_1
L_11
L_3 ,
F_28 ( V_12 ) , ( unsigned long long ) V_12 -> V_56 . V_85 ,
( unsigned long long ) V_17 -> V_86 ,
V_12 -> V_56 . V_25 , V_17 -> V_52 , V_17 -> V_53 ,
V_17 -> V_57 . V_74 , V_17 -> V_57 . V_58 ,
V_17 -> V_57 . V_62 ,
V_17 -> V_57 . V_87 ? L_4 : L_5 , V_17 -> V_57 . V_88 ? L_4 : L_6 ,
V_17 -> V_57 . V_66 ) ;
for ( V_46 = 0 ; V_46 < V_66 ; V_46 ++ ) {
F_27 ( V_82 , L_7 , V_46 ,
( unsigned long long ) F_3 ( V_2 , V_46 ) ,
V_17 -> V_15 [ V_46 ] ) ;
}
F_27 ( V_82 , L_8 , V_17 -> V_89 ) ;
F_27 ( V_82 , L_9 , V_17 -> V_90 ) ;
}
static struct V_32 *
F_31 ( struct V_33 * V_34 , enum V_63 * V_64 ,
const T_1 * V_42 , const T_1 * V_43 ,
unsigned int V_66 , const unsigned char * V_91 ,
T_5 V_37 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_34 ) ;
struct V_21 * V_22 = V_39 -> V_22 ;
struct V_41 * V_67 ;
struct V_41 * V_12 ;
struct V_41 * V_68 ;
T_5 V_44 = V_37 ;
struct V_16 * V_17 ;
struct V_83 * V_84 = NULL ;
struct V_40 * V_29 ;
T_2 V_4 = 0 ;
T_3 V_74 = V_64 ? V_92 : V_93 ;
int V_46 , V_78 , V_5 , V_73 , V_45 ;
int V_94 = ( V_22 -> V_95 < V_96 ) ? 1 : 0 ;
F_27 ( F_25 ( V_39 ) , L_12 , V_97 ) ;
F_20 ( V_66 + F_32 ( V_25 ) < 2 ) ;
V_45 = F_13 ( V_39 , V_37 ) ;
if ( V_66 + F_33 ( V_25 ) > 3 ||
( F_32 ( V_25 ) && ! F_33 ( V_25 ) ) ) {
V_73 = 1 ;
V_45 *= 2 ;
} else
V_73 = 0 ;
if ( F_14 ( V_45 ) &&
F_15 ( V_39 , V_45 + V_94 ) == 0 )
V_5 = V_39 -> V_49 ;
else
return NULL ;
V_46 = 0 ;
do {
struct V_1 * V_2 [ 2 ] ;
T_5 V_77 = F_16 ( T_5 , V_37 ,
1 << V_39 -> V_51 ) ;
V_12 = F_17 ( V_39 , V_5 + V_46 ) ;
V_17 = V_12 -> V_17 ;
V_68 = F_17 ( V_39 , V_5 + V_46 + V_73 ) ;
V_84 = V_68 -> V_84 ;
V_2 [ 0 ] = (struct V_1 * ) V_17 ;
V_2 [ 1 ] = (struct V_1 * ) V_84 ;
for ( V_78 = 0 ; V_78 < V_66 ; V_78 ++ )
F_4 ( V_2 , V_43 [ V_78 ] , V_4 , V_91 [ V_78 ] , V_78 ) ;
if ( F_33 ( V_25 ) )
F_4 ( V_2 , V_42 [ 1 ] , V_4 , 1 , V_78 ++ ) ;
else if ( F_32 ( V_25 ) ) {
F_4 ( V_2 , V_42 [ 0 ] , V_4 , 0 , V_78 ++ ) ;
F_4 ( V_2 , V_42 [ 1 ] , V_4 , 1 , V_78 ++ ) ;
F_4 ( V_2 , V_42 [ 1 ] , V_4 , 0 , V_78 ++ ) ;
}
V_17 -> V_52 = V_77 ;
V_17 -> V_89 = V_42 [ 0 ] + V_4 ;
V_17 -> V_90 = V_42 [ 1 ] + V_4 ;
V_17 -> V_53 = 0 ;
V_17 -> V_57 . V_74 = V_74 ;
if ( V_22 -> V_98 & V_99 )
V_17 -> V_57 . V_100 = V_64 ? 1 : 0 ;
V_17 -> V_57 . V_66 = F_21 ( V_78 ) ;
V_17 -> V_57 . V_87 = ! ! ( V_25 & V_101 ) ;
V_17 -> V_57 . V_88 = ! ! ( V_25 & V_102 ) ;
V_37 -= V_77 ;
V_4 += V_77 ;
} while ( ( V_46 += 1 + V_73 ) < V_45 );
V_12 -> V_56 . V_25 = V_25 ;
V_12 -> V_37 = V_44 ;
if ( V_64 )
V_12 -> V_64 = V_64 ;
V_17 -> V_57 . V_60 = ! ! ( V_25 & V_61 ) ;
F_24 ( V_39 , V_12 , V_68 ) ;
if ( ! V_94 ) {
V_17 -> V_57 . V_58 = ! ! ( V_25 & V_59 ) ;
V_17 -> V_57 . V_62 = 1 ;
V_67 = V_12 ;
} else {
V_67 = F_17 ( V_39 , V_5 + V_46 ) ;
V_67 -> V_56 . V_25 = V_25 & V_59 ;
V_29 = V_67 -> V_29 ;
V_29 -> V_53 = 0 ;
V_29 -> V_57 . null = 1 ;
V_29 -> V_57 . V_58 = ! ! ( V_25 & V_59 ) ;
V_29 -> V_57 . V_62 = 1 ;
V_29 -> V_52 = V_79 ;
F_18 ( V_39 , V_67 ) ;
}
return & V_67 -> V_56 ;
}
static struct V_32 *
F_34 ( struct V_33 * V_34 , enum V_63 * V_64 ,
const T_1 * V_42 , const T_1 * V_43 ,
unsigned int V_66 , const unsigned char * V_91 ,
T_5 V_37 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_34 ) ;
struct V_21 * V_22 = V_39 -> V_22 ;
struct V_41 * V_12 ;
T_5 V_44 = V_37 ;
struct V_16 * V_17 ;
T_2 V_4 = 0 ;
T_3 V_74 ;
int V_46 , V_78 , V_5 , V_45 ;
V_74 = V_64 ? V_103 : V_104 ;
F_27 ( F_25 ( V_39 ) , L_12 , V_97 ) ;
V_45 = F_13 ( V_39 , V_37 ) ;
if ( V_45 && F_15 ( V_39 , V_45 ) == 0 )
V_5 = V_39 -> V_49 ;
else
return NULL ;
V_46 = 0 ;
do {
struct V_1 * V_2 [ 4 ] ;
T_5 V_77 = F_16 ( T_5 , V_37 ,
1 << V_39 -> V_51 ) ;
V_12 = F_17 ( V_39 , V_5 + V_46 ) ;
V_17 = V_12 -> V_17 ;
V_2 [ 0 ] = (struct V_1 * ) V_17 ;
V_12 -> V_24 = F_6 ( V_22 , ( V_66 - 2 ) >> 3 ) ;
if ( ! V_12 -> V_24 ) {
F_35 ( F_25 ( V_39 ) ,
L_13 , V_97 ) ;
return NULL ;
}
V_17 -> V_105 = V_12 -> V_24 -> V_31 ;
V_12 -> V_24 -> V_106 = V_12 ;
V_2 [ 1 ] = (struct V_1 * ) V_12 -> V_24 -> V_29 ;
V_2 [ 2 ] = ( void * ) V_2 [ 1 ] + 64 ;
for ( V_78 = 0 ; V_78 < V_66 ; V_78 ++ )
F_5 ( V_2 , V_43 [ V_78 ] , V_4 , V_91 [ V_78 ] , V_78 ) ;
if ( F_33 ( V_25 ) )
F_5 ( V_2 , V_42 [ 1 ] , V_4 , 1 , V_78 ++ ) ;
else if ( F_32 ( V_25 ) ) {
F_5 ( V_2 , V_42 [ 0 ] , V_4 , 0 , V_78 ++ ) ;
F_5 ( V_2 , V_42 [ 1 ] , V_4 , 1 , V_78 ++ ) ;
F_5 ( V_2 , V_42 [ 1 ] , V_4 , 0 , V_78 ++ ) ;
}
V_17 -> V_52 = V_77 ;
V_17 -> V_89 = V_42 [ 0 ] + V_4 ;
V_17 -> V_90 = V_42 [ 1 ] + V_4 ;
V_17 -> V_53 = 0 ;
V_17 -> V_57 . V_74 = V_74 ;
V_17 -> V_57 . V_66 = F_36 ( V_78 ) ;
if ( V_22 -> V_98 & V_99 )
V_17 -> V_57 . V_100 = V_64 ? 1 : 0 ;
V_17 -> V_57 . V_87 = ! ! ( V_25 & V_101 ) ;
V_17 -> V_57 . V_88 = ! ! ( V_25 & V_102 ) ;
V_37 -= V_77 ;
V_4 += V_77 ;
} while ( ++ V_46 < V_45 );
V_12 -> V_56 . V_25 = V_25 ;
V_12 -> V_37 = V_44 ;
if ( V_64 )
V_12 -> V_64 = V_64 ;
V_17 -> V_57 . V_60 = ! ! ( V_25 & V_61 ) ;
V_17 -> V_57 . V_58 = ! ! ( V_25 & V_59 ) ;
V_17 -> V_57 . V_62 = 1 ;
F_29 ( V_39 , V_12 ) ;
return & V_12 -> V_56 ;
}
static int F_37 ( unsigned int V_66 , unsigned long V_25 )
{
if ( F_33 ( V_25 ) )
return V_66 + 1 ;
else if ( F_32 ( V_25 ) )
return V_66 + 3 ;
else
return V_66 ;
}
struct V_32 *
F_38 ( struct V_33 * V_80 , T_1 * V_42 , T_1 * V_43 ,
unsigned int V_66 , const unsigned char * V_91 , T_5 V_37 ,
unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_80 ) ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
if ( V_25 & V_101 )
V_42 [ 0 ] = V_42 [ 1 ] ;
if ( V_25 & V_102 )
V_42 [ 1 ] = V_42 [ 0 ] ;
if ( ( V_25 & V_101 ) && V_66 == 1 ) {
T_1 V_107 [ 2 ] ;
unsigned char V_108 [ 2 ] ;
F_20 ( V_25 & V_102 ) ;
V_107 [ 0 ] = V_43 [ 0 ] ;
V_107 [ 1 ] = V_43 [ 0 ] ;
V_108 [ 0 ] = V_91 [ 0 ] ;
V_108 [ 1 ] = 0 ;
return F_37 ( V_66 , V_25 ) > 8 ?
F_34 ( V_80 , NULL , V_42 , V_107 ,
2 , V_108 , V_37 ,
V_25 ) :
F_31 ( V_80 , NULL , V_42 , V_107 , 2 ,
V_108 , V_37 , V_25 ) ;
} else {
return F_37 ( V_66 , V_25 ) > 8 ?
F_34 ( V_80 , NULL , V_42 , V_43 , V_66 ,
V_91 , V_37 , V_25 ) :
F_31 ( V_80 , NULL , V_42 , V_43 , V_66 ,
V_91 , V_37 , V_25 ) ;
}
}
struct V_32 *
F_39 ( struct V_33 * V_80 , T_1 * V_17 , T_1 * V_43 ,
unsigned int V_66 , const unsigned char * V_91 , T_5 V_37 ,
enum V_63 * V_109 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_80 ) ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
if ( V_25 & V_101 )
V_17 [ 0 ] = V_17 [ 1 ] ;
if ( V_25 & V_102 )
V_17 [ 1 ] = V_17 [ 0 ] ;
* V_109 = 0 ;
return F_37 ( V_66 , V_25 ) > 8 ?
F_34 ( V_80 , V_109 , V_17 , V_43 , V_66 , V_91 , V_37 ,
V_25 ) :
F_31 ( V_80 , V_109 , V_17 , V_43 , V_66 , V_91 , V_37 ,
V_25 ) ;
}
struct V_32 *
F_40 ( struct V_33 * V_80 , T_1 V_42 , T_1 * V_43 ,
unsigned int V_66 , T_5 V_37 , unsigned long V_25 )
{
unsigned char V_91 [ V_110 ] ;
T_1 V_17 [ 2 ] ;
struct V_38 * V_39 = F_11 ( V_80 ) ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
if ( V_66 > V_110 )
return NULL ;
memset ( V_91 , 0 , V_66 ) ;
V_17 [ 0 ] = V_42 ;
V_25 |= V_102 ;
V_17 [ 1 ] = V_42 ;
return F_37 ( V_66 , V_25 ) > 8 ?
F_34 ( V_80 , NULL , V_17 , V_43 , V_66 , V_91 , V_37 ,
V_25 ) :
F_31 ( V_80 , NULL , V_17 , V_43 , V_66 , V_91 , V_37 ,
V_25 ) ;
}
struct V_32 *
F_41 ( struct V_33 * V_80 , T_1 * V_43 ,
unsigned int V_66 , T_5 V_37 ,
enum V_63 * V_64 , unsigned long V_25 )
{
unsigned char V_91 [ V_110 ] ;
T_1 V_17 [ 2 ] ;
struct V_38 * V_39 = F_11 ( V_80 ) ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
if ( V_66 > V_110 )
return NULL ;
* V_64 = 0 ;
memset ( V_91 , 0 , V_66 ) ;
V_17 [ 0 ] = V_43 [ 0 ] ;
V_25 |= V_102 ;
V_17 [ 1 ] = V_17 [ 0 ] ;
return F_37 ( V_66 , V_25 ) > 8 ?
F_34 ( V_80 , V_64 , V_17 , & V_43 [ 1 ] , V_66 - 1 ,
V_91 , V_37 , V_25 ) :
F_31 ( V_80 , V_64 , V_17 , & V_43 [ 1 ] , V_66 - 1 ,
V_91 , V_37 , V_25 ) ;
}
struct V_32 *
F_42 ( struct V_33 * V_34 , unsigned long V_25 )
{
struct V_38 * V_39 = F_11 ( V_34 ) ;
struct V_41 * V_12 ;
struct V_40 * V_29 ;
if ( F_12 ( V_47 , & V_39 -> V_48 ) )
return NULL ;
if ( F_15 ( V_39 , 1 ) == 0 )
V_12 = F_17 ( V_39 , V_39 -> V_49 ) ;
else
return NULL ;
V_29 = V_12 -> V_29 ;
V_29 -> V_53 = 0 ;
V_29 -> V_57 . null = 1 ;
V_29 -> V_57 . V_58 = 1 ;
V_29 -> V_57 . V_60 = ! ! ( V_25 & V_61 ) ;
V_29 -> V_57 . V_62 = 1 ;
V_29 -> V_52 = V_79 ;
V_29 -> V_54 = 0 ;
V_29 -> V_55 = 0 ;
V_12 -> V_56 . V_25 = V_25 ;
V_12 -> V_37 = 1 ;
F_18 ( V_39 , V_12 ) ;
return & V_12 -> V_56 ;
}
