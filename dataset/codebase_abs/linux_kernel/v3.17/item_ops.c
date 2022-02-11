static int F_1 ( struct V_1 * V_2 , int V_3 )
{
return 0 ;
}
static void F_2 ( struct V_4 * V_5 )
{
V_5 -> V_6 . V_7 -- ;
F_3 ( V_5 , V_8 ) ;
F_4 ( V_5 , ( V_9 ) ( ~ 0ULL >> 1 ) ) ;
}
static int F_5 ( struct V_10 * V_5 , unsigned long V_11 )
{
return 0 ;
}
static char * F_6 ( T_1 V_12 )
{
static char V_13 [ 256 ] ;
sprintf ( V_13 , L_1 , V_12 ) ;
return V_13 ;
}
static void F_7 ( struct V_1 * V_2 , char * V_14 )
{
F_8 ( L_2 ) ;
if ( F_9 ( V_2 ) ) {
struct F_9 * V_15 = (struct F_9 * ) V_14 ;
F_8 ( L_3 , F_10 ( V_15 ) ,
F_11 ( V_15 ) , F_12 ( V_15 ) ,
F_13 ( V_15 ) ,
F_6 ( F_14 ( V_15 ) ) ) ;
} else {
struct V_16 * V_15 = (struct V_16 * ) V_14 ;
F_8 ( L_4 , F_15 ( V_15 ) ,
( unsigned long long ) F_16 ( V_15 ) , F_17 ( V_15 ) ,
F_18 ( V_15 ) , F_6 ( F_19 ( V_15 ) ) ) ;
}
}
static void F_20 ( struct V_1 * V_2 , char * V_14 )
{
}
static int F_21 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
int V_21 , int V_22 )
{
V_20 -> V_23 = V_24 ;
return 0 ;
}
static int F_22 ( struct V_19 * V_20 , int free ,
int V_25 , int V_26 )
{
F_23 ( V_25 || V_26 ) ;
return - 1 ;
}
static int F_24 ( struct V_19 * V_20 , int free )
{
return - 1 ;
}
static int F_25 ( struct V_19 * V_20 , int V_27 , int V_28 )
{
F_23 ( V_28 ) ;
return 0 ;
}
static int F_26 ( struct V_19 * V_20 )
{
return V_20 -> V_29 - V_30 ;
}
static void F_27 ( struct V_19 * V_20 )
{
F_28 ( NULL , L_5 ,
L_6 ,
V_20 -> V_23 , V_20 -> V_31 , V_20 -> V_32 ) ;
}
static int F_29 ( struct V_1 * V_2 , int V_3 )
{
return F_30 ( V_2 ) ;
}
static void F_31 ( struct V_4 * V_5 )
{
F_32 ( V_5 ) ;
if ( F_33 ( V_5 ) == 0 )
F_3 ( V_5 , V_24 ) ;
}
static int F_34 ( struct V_10 * V_5 ,
unsigned long V_11 )
{
int V_33 = F_35 ( V_5 ) ;
return ( ( F_36 ( V_33 , V_5 ) & ( V_11 - 1 ) ) != 1 ) ;
}
static void F_37 ( struct V_1 * V_2 , char * V_14 )
{
int V_34 = 0 ;
F_8 ( L_7 ) ;
while ( V_34 < F_30 ( V_2 ) )
F_8 ( L_8 , V_14 [ V_34 ++ ] ) ;
F_8 ( L_9 ) ;
}
static void F_38 ( struct V_1 * V_2 , char * V_14 )
{
}
static int F_39 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
int V_21 , int V_22 )
{
V_20 -> V_23 = V_35 ;
return 0 ;
}
static int F_40 ( struct V_19 * V_20 , int free ,
int V_25 , int V_26 )
{
int V_36 ;
V_36 = free - free % 8 ;
return V_36 ? : - 1 ;
}
static int F_41 ( struct V_19 * V_20 , int free )
{
return F_40 ( V_20 , free , 0 , 0 ) ;
}
static int F_42 ( struct V_19 * V_20 , int V_27 , int V_28 )
{
return V_28 ;
}
static int F_43 ( struct V_19 * V_20 )
{
return V_20 -> V_29 - V_30 ;
}
static void F_44 ( struct V_19 * V_20 )
{
F_28 ( NULL , L_10 ,
L_11 ,
V_20 -> V_23 , V_20 -> V_31 , V_20 -> V_32 ) ;
}
static int F_45 ( struct V_1 * V_2 , int V_3 )
{
return F_30 ( V_2 ) / V_37 * V_3 ;
}
static void F_46 ( struct V_4 * V_5 )
{
F_32 ( V_5 ) ;
if ( F_33 ( V_5 ) == 0 )
F_3 ( V_5 , V_24 ) ;
}
static int F_47 ( struct V_10 * V_5 ,
unsigned long V_11 )
{
int V_33 = F_35 ( V_5 ) ;
return ( F_36 ( V_33 , V_5 ) != 1 ) ;
}
static void F_48 ( T_2 * V_38 , int * V_39 , T_2 V_40 )
{
* V_38 = V_40 ;
* V_39 = 1 ;
}
static int F_49 ( T_2 V_38 , int * V_39 , T_2 V_40 )
{
if ( V_38 == V_41 )
return 1 ;
if ( V_38 == 0 && V_40 == 0 ) {
( * V_39 ) ++ ;
return 0 ;
}
if ( V_38 != 0 && ( V_38 + * V_39 ) == V_40 ) {
( * V_39 ) ++ ;
return 0 ;
}
return 1 ;
}
static void F_50 ( T_2 V_38 , int V_39 )
{
if ( V_38 == V_41 )
return;
if ( V_39 == 1 )
F_8 ( L_12 , V_38 ) ;
else
F_8 ( L_13 , V_38 , V_39 ) ;
}
static void F_51 ( struct V_1 * V_2 , char * V_14 )
{
int V_34 ;
T_3 * V_42 ;
T_2 V_43 = V_41 ;
int V_44 = 0 ;
V_42 = ( T_3 * ) V_14 ;
if ( F_30 ( V_2 ) % V_37 )
F_28 ( NULL , L_14 , L_15 ) ;
F_8 ( L_16 , ( int ) F_52 ( V_2 ) ) ;
for ( V_34 = 0 ; V_34 < F_52 ( V_2 ) ; V_34 ++ ) {
if ( F_49 ( V_43 , & V_44 , F_53 ( V_42 , V_34 ) ) ) {
F_50 ( V_43 , V_44 ) ;
F_48 ( & V_43 , & V_44 , F_53 ( V_42 , V_34 ) ) ;
}
}
F_50 ( V_43 , V_44 ) ;
F_8 ( L_17 ) ;
}
static void F_54 ( struct V_1 * V_2 , char * V_14 )
{
}
static int F_55 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
int V_21 , int V_22 )
{
V_20 -> V_23 = V_45 ;
return 0 ;
}
static int F_56 ( struct V_19 * V_20 , int free ,
int V_25 , int V_26 )
{
int V_36 ;
V_36 = free - free % V_37 ;
return V_36 ? : - 1 ;
}
static int F_57 ( struct V_19 * V_20 , int free )
{
return F_56 ( V_20 , free , 0 , 0 ) ;
}
static int F_58 ( struct V_19 * V_20 , int V_27 , int V_46 )
{
return V_46 ;
}
static int F_59 ( struct V_19 * V_20 )
{
return V_20 -> V_29 - V_30 ;
}
static void F_60 ( struct V_19 * V_20 )
{
F_28 ( NULL , L_18 ,
L_19 ,
V_20 -> V_23 , V_20 -> V_31 , V_20 -> V_32 ) ;
}
static int F_61 ( struct V_1 * V_2 , int V_3 )
{
F_28 ( NULL , L_20 ,
L_21 ) ;
return 0 ;
}
static void F_62 ( struct V_4 * V_5 )
{
F_32 ( V_5 ) ;
if ( F_33 ( V_5 ) == 0 )
F_3 ( V_5 , V_24 ) ;
}
static int F_63 ( struct V_10 * V_5 ,
unsigned long V_11 )
{
if ( F_64 ( V_5 -> V_47 . V_48 . V_49 ) == V_50 )
return 0 ;
return 1 ;
}
static void F_65 ( struct V_1 * V_2 , char * V_14 )
{
int V_51 ;
int V_52 ;
struct V_53 * V_54 ;
char * V_55 ;
static char V_56 [ 80 ] ;
F_8 ( L_22 , L_23 ,
L_24 , L_25 , L_26 , L_27 ) ;
V_54 = (struct V_53 * ) V_14 ;
for ( V_51 = 0 ; V_51 < F_66 ( V_2 ) ; V_51 ++ , V_54 ++ ) {
V_52 =
( V_51 ? ( F_67 ( V_54 - 1 ) ) : F_30 ( V_2 ) ) -
F_67 ( V_54 ) ;
V_55 = V_14 + F_67 ( V_54 ) ;
if ( V_55 [ V_52 - 1 ] == 0 )
V_52 = strlen ( V_55 ) ;
V_56 [ 0 ] = '"' ;
if ( V_52 > sizeof( V_56 ) - 3 ) {
strncpy ( V_56 + 1 , V_55 , sizeof( V_56 ) - 3 ) ;
V_56 [ sizeof( V_56 ) - 2 ] = '"' ;
V_56 [ sizeof( V_56 ) - 1 ] = 0 ;
} else {
memcpy ( V_56 + 1 , V_55 , V_52 ) ;
V_56 [ V_52 + 1 ] = '"' ;
V_56 [ V_52 + 2 ] = 0 ;
}
F_8 ( L_28 ,
V_51 , V_56 ,
F_68 ( V_54 ) , F_69 ( V_54 ) ,
F_70 ( F_71 ( V_54 ) ) ,
F_72 ( ( F_71 ( V_54 ) ) ) ,
( F_73 ( V_54 ) ) ? L_29 : L_30 ) ;
}
}
static void F_74 ( struct V_1 * V_2 , char * V_14 )
{
int V_51 ;
struct V_53 * V_54 ;
V_54 = (struct V_53 * ) V_14 ;
for ( V_51 = 0 ; V_51 < F_66 ( V_2 ) ; V_51 ++ , V_54 ++ ) {
;
}
}
static inline int F_75 ( int V_21 , int V_57 ,
int V_58 , int V_59 )
{
if ( V_59 == V_60 || V_59 == V_61 )
return V_57 ;
if ( ! V_21 )
return V_57 ;
if ( V_57 < V_58 )
return V_57 ;
if ( V_59 == V_62 )
return V_57 + 1 ;
F_76 ( V_59 != V_63 || V_57 == 0 ,
L_31 ,
V_59 ) ;
return V_57 - 1 ;
}
static int F_77 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
int V_21 , int V_22 )
{
struct V_64 * V_65 = V_20 -> V_66 ;
int V_51 , V_34 ;
int V_67 = sizeof( struct V_64 ) ;
struct V_53 * V_54 ;
V_20 -> V_23 = V_68 ;
F_23 ( ! ( V_20 -> V_32 ) || ! V_20 -> V_69 ) ;
V_65 -> V_70 = 0 ;
if ( F_78 ( V_20 -> V_32 ) == V_50 )
V_65 -> V_70 |= V_71 ;
V_54 = (struct V_53 * ) ( V_20 -> V_69 ) ;
V_65 -> V_72 = F_66 ( V_20 -> V_32 ) +
( ( V_21 ) ? ( ( V_18 -> V_73 == V_62 ) ? - 1 :
( V_18 -> V_73 == V_63 ? 1 : 0 ) ) : 0 ) ;
for ( V_51 = 0 ; V_51 < V_65 -> V_72 ; V_51 ++ ) {
V_34 = F_75 ( V_21 , V_51 , V_18 -> V_74 ,
V_18 -> V_73 ) ;
V_65 -> V_75 [ V_51 ] =
( V_34 ? F_67 ( & V_54 [ V_34 - 1 ] ) : F_30 ( V_20 -> V_32 ) ) -
F_67 ( & V_54 [ V_34 ] ) + V_76 ;
}
V_67 += ( V_65 -> V_72 * sizeof( short ) ) ;
if ( V_21 && V_18 -> V_73 == V_63 )
V_65 -> V_75 [ V_18 -> V_74 ] = V_22 ;
#ifdef F_79
{
int V_77 , V_78 ;
V_78 = 0 ;
for ( V_77 = 0 ; V_77 < V_65 -> V_72 ; V_77 ++ )
V_78 += V_65 -> V_75 [ V_77 ] ;
if ( V_78 + V_30 != V_20 -> V_29 +
( ( V_21
&& ( V_18 -> V_73 == V_63
|| V_18 -> V_73 == V_62 ) ) ? V_22 : 0 ) ) {
F_80 ( NULL , L_32 , L_33
L_34
L_35 ,
V_18 -> V_73 , V_22 ) ;
}
}
#endif
return V_67 ;
}
static int F_81 ( struct V_19 * V_20 , int free ,
int V_25 , int V_26 )
{
int V_51 ;
int V_79 = 0 ;
struct V_64 * V_65 = V_20 -> V_66 ;
for ( V_51 = V_25 ; V_51 < V_65 -> V_72 - V_26 ; V_51 ++ ) {
if ( V_65 -> V_75 [ V_51 ] > free )
break;
free -= V_65 -> V_75 [ V_51 ] ;
V_79 ++ ;
}
if ( V_79 == V_65 -> V_72 ) {
F_80 ( NULL , L_36 ,
L_37 , free ,
V_65 -> V_72 ) ;
}
if ( V_25 == 0 && ( V_65 -> V_70 & V_71 )
&& V_79 < 2 )
V_79 = 0 ;
return V_79 ? : - 1 ;
}
static int F_82 ( struct V_19 * V_20 , int free )
{
int V_51 ;
int V_79 = 0 ;
struct V_64 * V_65 = V_20 -> V_66 ;
for ( V_51 = V_65 -> V_72 - 1 ; V_51 >= 0 ; V_51 -- ) {
if ( V_65 -> V_75 [ V_51 ] > free )
break;
free -= V_65 -> V_75 [ V_51 ] ;
V_79 ++ ;
}
F_23 ( V_79 == V_65 -> V_72 ) ;
if ( ( V_65 -> V_70 & V_71 )
&& V_79 > V_65 -> V_72 - 2 )
V_79 = V_65 -> V_72 - 2 ;
return V_79 ? : - 1 ;
}
static int F_83 ( struct V_19 * V_20 , int V_27 , int V_28 )
{
int V_51 , V_80 ;
int V_81 , V_82 ;
struct V_64 * V_65 = V_20 -> V_66 ;
V_80 = 0 ;
if ( V_27 == 0 )
V_81 = 0 ;
else
V_81 = V_65 -> V_72 - V_28 ;
V_82 = V_81 + V_28 - 1 ;
for ( V_51 = V_81 ; V_51 <= V_82 ; V_51 ++ )
V_80 += V_65 -> V_75 [ V_51 ] ;
return V_80 ;
}
static int F_84 ( struct V_19 * V_20 )
{
struct V_64 * V_65 = V_20 -> V_66 ;
return V_65 -> V_72 ;
}
static void F_85 ( struct V_19 * V_20 )
{
int V_51 ;
struct V_64 * V_65 = V_20 -> V_66 ;
F_28 ( NULL , L_38 ,
L_39 ,
V_20 -> V_23 , V_20 -> V_31 , V_20 -> V_32 , V_65 -> V_70 ) ;
F_8 ( L_40 , V_65 -> V_72 ) ;
for ( V_51 = 0 ; V_51 < V_65 -> V_72 ; V_51 ++ )
F_8 ( L_41 , V_65 -> V_75 [ V_51 ] ) ;
F_8 ( L_42 ) ;
}
static int F_86 ( struct V_1 * V_2 , int V_3 )
{
F_28 ( NULL , L_43 ,
L_44 ) ;
return 0 ;
}
static void F_87 ( struct V_4 * V_5 )
{
F_28 ( NULL , L_45 ,
L_44 ) ;
}
static int F_88 ( struct V_10 * V_5 ,
unsigned long V_11 )
{
F_28 ( NULL , L_46 ,
L_44 ) ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 , char * V_14 )
{
F_28 ( NULL , L_47 ,
L_44 ) ;
}
static void F_90 ( struct V_1 * V_2 , char * V_14 )
{
F_28 ( NULL , L_48 ,
L_44 ) ;
}
static int F_91 ( struct V_17 * V_18 ,
struct V_19 * V_20 ,
int V_21 , int V_22 )
{
F_28 ( NULL , L_49 ,
L_44 ) ;
return 0 ;
}
static int F_92 ( struct V_19 * V_20 , int free ,
int V_25 , int V_26 )
{
F_28 ( NULL , L_50 ,
L_44 ) ;
return - 1 ;
}
static int F_93 ( struct V_19 * V_20 , int free )
{
F_28 ( NULL , L_51 ,
L_44 ) ;
return - 1 ;
}
static int F_94 ( struct V_19 * V_20 , int V_27 , int V_28 )
{
F_28 ( NULL , L_52 ,
L_44 ) ;
return 0 ;
}
static int F_95 ( struct V_19 * V_20 )
{
F_28 ( NULL , L_53 ,
L_44 ) ;
return 0 ;
}
static void F_96 ( struct V_19 * V_20 )
{
F_28 ( NULL , L_54 ,
L_44 ) ;
}
