bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 && V_2 -> V_3 -> V_4 ;
}
static inline struct V_5 * F_2 ( struct V_6 * V_7 )
{
return (struct V_5 * ) F_3 ( V_7 -> V_2 , V_7 ) ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_8 )
{
T_2 V_9 ;
V_9 = F_5 ( V_8 , V_2 -> V_3 -> V_10 ) ;
return V_8 + V_9 * ( V_2 -> V_3 -> V_11 << V_2 -> V_12 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_5 * V_13 ,
T_3 * V_14 , T_3 * V_3 , int V_15 )
{
int V_16 ;
T_4 V_17 [ V_18 - V_19 ] ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 -> V_20 ; V_16 ++ )
V_17 [ V_16 ] = V_3 [ V_16 ] ;
return F_7 ( V_13 -> V_21 , V_14 , V_17 , V_2 -> V_3 -> V_10 , NULL , V_15 ,
V_13 -> V_22 , 0 , NULL ) ;
}
static T_3 * F_8 ( struct V_1 * V_2 , T_1 V_23 , int V_24 ,
unsigned * V_8 , struct V_25 * * V_26 )
{
T_1 V_27 , V_28 ;
T_3 * V_29 ;
V_27 = ( V_24 + V_23 ) * V_2 -> V_3 -> V_20 ;
V_28 = V_27 >> V_2 -> V_12 ;
* V_8 = ( unsigned ) ( V_27 - ( V_28 << V_2 -> V_12 ) ) ;
V_29 = F_9 ( V_2 -> V_3 -> V_30 , V_2 -> V_3 -> V_31 + V_28 , V_26 ) ;
if ( F_10 ( F_11 ( V_29 ) ) ) {
F_12 ( L_1 ,
V_2 -> V_32 -> V_33 , ( unsigned long long ) V_23 ,
( unsigned long long ) ( V_2 -> V_3 -> V_31 + V_28 ) ,
F_13 ( V_29 ) ) ;
* V_26 = NULL ;
}
return V_29 ;
}
static inline T_3 * F_14 ( struct V_1 * V_2 ,
struct V_5 * V_13 ,
unsigned V_16 , unsigned V_34 )
{
return & V_13 -> V_35 [ V_16 ] [ V_34 * V_2 -> V_3 -> V_10 ] ;
}
static inline unsigned F_15 ( unsigned V_16 , unsigned V_34 )
{
return ( V_16 << V_36 ) + V_34 ;
}
static int F_16 ( struct V_1 * V_2 , struct V_5 * V_13 ,
T_1 V_23 , int V_37 , unsigned V_38 ,
int V_15 )
{
int V_39 , V_40 = 0 , V_29 ;
struct V_25 * V_26 ;
unsigned V_41 , V_16 , V_8 ;
T_3 * V_17 , * V_28 ;
V_17 = F_8 ( V_2 , V_23 , V_38 , & V_8 , & V_26 ) ;
if ( F_11 ( V_17 ) )
return F_13 ( V_17 ) ;
F_17 (fio, n, i) {
V_28 = F_14 ( V_2 , V_13 , V_41 , V_16 ) ;
V_29 = F_6 ( V_2 , V_13 , V_28 , & V_17 [ V_8 ] , V_15 ) ;
if ( V_29 < 0 ) {
F_18 ( V_26 ) ;
V_39 = V_29 ;
goto error;
}
V_40 += V_29 ;
V_13 -> V_42 [ V_38 ] = V_28 [ V_37 ] ;
V_38 ++ ;
if ( V_38 >= 1 << V_2 -> V_12 )
goto V_43;
V_8 += V_2 -> V_3 -> V_20 ;
if ( V_8 >= 1 << V_2 -> V_12 ) {
F_18 ( V_26 ) ;
V_17 = F_8 ( V_2 , V_23 , V_38 , & V_8 , & V_26 ) ;
if ( F_10 ( F_11 ( V_17 ) ) )
return F_13 ( V_17 ) ;
}
}
V_43:
V_39 = V_40 ;
error:
if ( V_39 < 0 && V_15 )
F_19 ( L_2 ,
V_2 -> V_32 -> V_33 , ( unsigned long long ) V_23 , V_39 ) ;
else if ( V_39 > 0 )
F_20 ( L_3 ,
V_2 -> V_32 -> V_33 , ( unsigned long long ) V_23 , V_39 ) ;
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_3 * V_44 , T_3 * V_14 )
{
if ( F_10 ( F_22 ( V_2 , F_23 ( V_2 , V_7 ) ,
V_14 , 1 << V_2 -> V_12 ,
F_24 ( V_2 , V_7 ) ) ) )
return 0 ;
return memcmp ( F_24 ( V_2 , V_7 ) , V_44 ,
V_2 -> V_45 ) != 0 ;
}
static int F_25 ( struct V_1 * V_2 , struct V_6 * V_7 ,
T_1 V_23 , T_1 V_46 , unsigned V_38 ,
int * V_15 )
{
bool V_47 ;
int V_16 , V_34 , V_48 = - 1 ;
struct V_25 * V_26 ;
struct V_49 * V_30 ;
struct V_5 * V_13 = F_2 ( V_7 ) ;
T_1 V_28 , V_50 ;
T_3 * V_51 , * V_52 ;
T_3 V_44 [ V_2 -> V_45 ] ;
unsigned V_41 , V_53 ;
if ( V_15 )
* V_15 = 0 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_3 -> V_10 ; V_16 ++ ) {
V_50 = F_4 ( V_2 , V_23 * V_2 -> V_3 -> V_10 + V_16 ) ;
if ( V_50 == V_46 )
V_48 = V_16 ;
V_28 = V_50 >> V_2 -> V_12 ;
V_30 = V_2 -> V_3 -> V_54 ;
if ( V_28 >= V_2 -> V_55 ) {
V_28 -= V_2 -> V_55 ;
if ( F_10 ( V_28 >= V_2 -> V_3 -> V_56 ) )
continue;
V_28 += V_2 -> V_57 ;
V_30 = V_2 -> V_30 ;
}
V_51 = F_9 ( V_30 , V_28 , & V_26 ) ;
if ( F_10 ( F_11 ( V_51 ) ) ) {
F_20 ( L_4 ,
V_2 -> V_32 -> V_33 ,
( unsigned long long ) V_23 ,
( unsigned long long ) V_28 , F_13 ( V_51 ) ) ;
if ( V_15 && * V_15 <= V_2 -> V_3 -> V_20 )
V_13 -> V_22 [ ( * V_15 ) ++ ] = V_16 ;
continue;
}
if ( V_30 == V_2 -> V_3 -> V_54 &&
F_26 ( V_2 , V_7 , V_28 , V_44 ,
& V_47 ) == 0 ) {
if ( V_47 )
continue;
if ( V_15 && * V_15 <= V_2 -> V_3 -> V_20 &&
F_21 ( V_2 , V_7 , V_44 , V_51 ) )
V_13 -> V_22 [ ( * V_15 ) ++ ] = V_16 ;
}
F_17 (fio, n, j) {
V_53 = F_15 ( V_41 , V_34 ) + V_38 ;
if ( V_53 >= 1 << V_2 -> V_12 )
goto V_43;
V_52 = F_14 ( V_2 , V_13 , V_41 , V_34 ) ;
V_52 [ V_16 ] = V_51 [ V_53 ] ;
}
V_43:
F_18 ( V_26 ) ;
}
return V_48 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_5 * V_13 )
{
unsigned V_41 ;
if ( ! V_13 -> V_21 ) {
V_13 -> V_21 = F_28 ( V_2 -> V_3 -> V_58 , 0 ) ;
if ( F_10 ( ! V_13 -> V_21 ) ) {
F_12 ( L_5 ) ;
return - V_59 ;
}
}
F_29 (n) {
if ( V_13 -> V_35 [ V_41 ] )
continue;
V_13 -> V_35 [ V_41 ] = F_28 ( V_2 -> V_3 -> V_60 , V_61 ) ;
if ( F_10 ( ! V_13 -> V_35 [ V_41 ] ) ) {
F_12 ( L_6 ) ;
return - V_59 ;
}
}
F_30 (fio, n) {
if ( V_13 -> V_35 [ V_41 ] )
continue;
V_13 -> V_35 [ V_41 ] = F_28 ( V_2 -> V_3 -> V_62 , V_61 ) ;
if ( F_10 ( ! V_13 -> V_35 [ V_41 ] ) )
break;
}
V_13 -> V_63 = V_41 ;
if ( ! V_13 -> V_42 ) {
V_13 -> V_42 = F_28 ( V_2 -> V_3 -> V_64 , V_61 ) ;
if ( ! V_13 -> V_42 ) {
F_12 ( L_7 ) ;
return - V_59 ;
}
}
return 0 ;
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_13 )
{
unsigned V_41 ;
F_32 (fio, n)
memset ( V_13 -> V_35 [ V_41 ] , 0 , V_2 -> V_3 -> V_10 << V_36 ) ;
memset ( V_13 -> V_22 , 0 , sizeof( V_13 -> V_22 ) ) ;
}
static int F_33 ( struct V_1 * V_2 , struct V_6 * V_7 ,
struct V_5 * V_13 , T_1 V_23 , T_1 V_8 ,
bool V_65 )
{
int V_39 , V_15 = 0 ;
unsigned V_66 ;
V_39 = F_27 ( V_2 , V_13 ) ;
if ( F_10 ( V_39 < 0 ) )
return V_39 ;
for ( V_66 = 0 ; V_66 < 1 << V_2 -> V_12 ; ) {
F_31 ( V_2 , V_13 ) ;
V_39 = F_25 ( V_2 , V_7 , V_23 , V_8 , V_66 ,
V_65 ? & V_15 : NULL ) ;
if ( F_10 ( V_39 < 0 ) )
return V_39 ;
V_39 = F_16 ( V_2 , V_13 , V_23 , V_39 , V_66 , V_15 ) ;
if ( V_39 < 0 )
return V_39 ;
V_66 += V_13 -> V_63 << V_36 ;
}
V_39 = F_22 ( V_2 , F_23 ( V_2 , V_7 ) , V_13 -> V_42 ,
1 << V_2 -> V_12 ,
F_24 ( V_2 , V_7 ) ) ;
if ( F_10 ( V_39 < 0 ) )
return V_39 ;
if ( memcmp ( F_24 ( V_2 , V_7 ) , F_34 ( V_2 , V_7 ) ,
V_2 -> V_45 ) ) {
F_19 ( L_8 ,
V_2 -> V_32 -> V_33 , ( unsigned long long ) V_23 , V_15 ) ;
return - V_67 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_6 * V_7 , T_3 * V_14 ,
T_5 V_68 )
{
struct V_5 * V_13 = F_2 ( V_7 ) ;
memcpy ( V_14 , & V_13 -> V_42 [ V_13 -> V_69 ] , V_68 ) ;
V_13 -> V_69 += V_68 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_6 * V_7 ,
enum V_70 type , T_6 V_28 , T_3 * V_71 ,
struct V_72 * V_73 )
{
int V_39 ;
struct V_5 * V_13 = F_2 ( V_7 ) ;
T_1 V_8 , V_29 , V_23 ;
if ( ! F_1 ( V_2 ) )
return - V_74 ;
if ( type == V_75 )
V_28 += V_2 -> V_55 ;
V_8 = V_28 << V_2 -> V_12 ;
V_29 = V_8 ;
F_37 ( V_29 , V_2 -> V_3 -> V_11 << V_2 -> V_12 ) ;
V_23 = V_8 - V_29 * ( V_2 -> V_3 -> V_11 << V_2 -> V_12 ) ;
V_39 = F_33 ( V_2 , V_7 , V_13 , V_23 , V_8 , false ) ;
if ( V_39 < 0 ) {
V_39 = F_33 ( V_2 , V_7 , V_13 , V_23 , V_8 , true ) ;
if ( V_39 < 0 )
return V_39 ;
}
if ( V_71 )
memcpy ( V_71 , V_13 -> V_42 , 1 << V_2 -> V_12 ) ;
else if ( V_73 ) {
V_13 -> V_69 = 0 ;
V_39 = F_38 ( V_2 , V_7 , V_73 , F_35 ) ;
}
return V_39 ;
}
void F_39 ( struct V_6 * V_7 )
{
unsigned V_41 ;
struct V_76 * V_77 = V_7 -> V_2 -> V_3 ;
struct V_5 * V_13 = F_2 ( V_7 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
return;
F_40 ( V_13 -> V_21 , V_77 -> V_58 ) ;
F_29 (n)
F_40 ( V_13 -> V_35 [ V_41 ] , V_77 -> V_60 ) ;
F_30 (fio, n)
F_40 ( V_13 -> V_35 [ V_41 ] , V_77 -> V_62 ) ;
F_40 ( V_13 -> V_42 , V_77 -> V_64 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
struct V_5 * V_13 = F_2 ( V_7 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
return;
V_13 -> V_21 = NULL ;
memset ( V_13 -> V_35 , 0 , sizeof( V_13 -> V_35 ) ) ;
V_13 -> V_63 = 0 ;
V_13 -> V_42 = NULL ;
}
unsigned F_42 ( struct V_1 * V_2 , unsigned V_78 ,
char * V_79 , unsigned V_80 )
{
if ( ! F_1 ( V_2 ) )
return V_78 ;
F_43 ( L_9 V_81 L_10
V_82 L_11
V_83 L_11
V_84 L_12 ,
V_2 -> V_3 -> V_4 -> V_33 ,
( unsigned long long ) V_2 -> V_3 -> V_85 ,
( unsigned long long ) V_2 -> V_3 -> V_31 ,
V_2 -> V_3 -> V_20 ) ;
return V_78 ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_3 ;
if ( ! F_1 ( V_2 ) )
goto V_86;
F_45 ( V_77 -> V_58 ) ;
F_45 ( V_77 -> V_60 ) ;
F_45 ( V_77 -> V_62 ) ;
F_46 ( V_77 -> V_87 ) ;
if ( V_77 -> V_54 )
F_47 ( V_77 -> V_54 ) ;
if ( V_77 -> V_30 )
F_47 ( V_77 -> V_30 ) ;
if ( V_77 -> V_4 )
F_48 ( V_2 -> V_88 , V_77 -> V_4 ) ;
V_86:
F_49 ( V_77 ) ;
V_2 -> V_3 = NULL ;
}
static void * F_50 ( T_7 V_89 , void * V_90 )
{
struct V_1 * V_2 = (struct V_1 * ) V_90 ;
return F_51 ( 8 , 0x11d , 0 , 1 , V_2 -> V_3 -> V_20 ) ;
}
static void F_52 ( void * V_91 , void * V_90 )
{
struct V_92 * V_21 = (struct V_92 * ) V_91 ;
if ( V_21 )
F_53 ( V_21 ) ;
}
bool F_54 ( const char * V_93 )
{
return ( ! strcasecmp ( V_93 , V_81 ) ||
! strcasecmp ( V_93 , V_82 ) ||
! strcasecmp ( V_93 , V_83 ) ||
! strcasecmp ( V_93 , V_84 ) ) ;
}
int F_55 ( struct V_94 * V_95 , struct V_1 * V_2 ,
unsigned * V_96 , const char * V_93 )
{
int V_39 ;
struct V_97 * V_88 = V_2 -> V_88 ;
const char * V_98 ;
unsigned long long V_99 ;
unsigned char V_100 ;
char V_101 ;
if ( ! * V_96 ) {
V_88 -> error = L_13 ;
return - V_102 ;
}
V_98 = F_56 ( V_95 ) ;
( * V_96 ) -- ;
if ( ! strcasecmp ( V_93 , V_81 ) ) {
V_39 = F_57 ( V_88 , V_98 , V_103 , & V_2 -> V_3 -> V_4 ) ;
if ( V_39 ) {
V_88 -> error = L_14 ;
return V_39 ;
}
} else if ( ! strcasecmp ( V_93 , V_82 ) ) {
if ( sscanf ( V_98 , L_15 , & V_99 , & V_101 ) != 1 ||
( ( T_6 ) ( V_99 << ( V_2 -> V_12 - V_104 ) )
>> ( V_2 -> V_12 - V_104 ) != V_99 ) ) {
V_88 -> error = L_16 V_82 ;
return - V_102 ;
}
V_2 -> V_3 -> V_85 = V_99 ;
} else if ( ! strcasecmp ( V_93 , V_83 ) ) {
if ( sscanf ( V_98 , L_15 , & V_99 , & V_101 ) != 1 ||
( ( T_6 ) ( V_99 << ( V_2 -> V_12 - V_104 ) ) >>
( V_2 -> V_12 - V_104 ) != V_99 ) ) {
V_88 -> error = L_16 V_83 ;
return - V_102 ;
}
V_2 -> V_3 -> V_31 = V_99 ;
} else if ( ! strcasecmp ( V_93 , V_84 ) ) {
if ( sscanf ( V_98 , L_17 , & V_100 , & V_101 ) != 1 || ! V_100 ||
V_100 < ( V_18 - V_105 ) ||
V_100 > ( V_18 - V_19 ) ) {
V_88 -> error = L_16 V_84 ;
return - V_102 ;
}
V_2 -> V_3 -> V_20 = V_100 ;
} else {
V_88 -> error = L_18 ;
return - V_102 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_76 * V_77 ;
V_77 = F_59 ( sizeof( struct V_76 ) , V_106 ) ;
if ( ! V_77 ) {
V_2 -> V_88 -> error = L_19 ;
return - V_59 ;
}
V_2 -> V_3 = V_77 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_76 * V_77 = V_2 -> V_3 ;
struct V_97 * V_88 = V_2 -> V_88 ;
T_1 V_56 ;
if ( ! F_1 ( V_2 ) ) {
F_44 ( V_2 ) ;
return 0 ;
}
V_56 = V_2 -> V_56 - V_2 -> V_57 ;
if ( V_2 -> V_12 != V_2 -> V_107 ) {
V_88 -> error = L_20 ;
return - V_102 ;
}
if ( ! V_77 -> V_20 ) {
V_88 -> error = L_21 V_84 ;
return - V_102 ;
}
V_77 -> V_10 = V_18 - V_77 -> V_20 ;
if ( ! V_77 -> V_85 ) {
V_88 -> error = L_21 V_82 ;
return - V_102 ;
}
V_77 -> V_11 = V_77 -> V_85 ;
if ( F_61 ( V_77 -> V_11 , V_77 -> V_10 ) )
V_77 -> V_11 ++ ;
if ( V_77 -> V_85 < V_2 -> V_55 + V_56 || ! V_77 -> V_11 ) {
V_88 -> error = L_16 V_82 ;
return - V_102 ;
}
V_77 -> V_56 = V_77 -> V_85 - V_2 -> V_55 ;
if ( F_62 ( V_2 -> V_30 ) < V_77 -> V_56 ) {
V_88 -> error = L_22
V_82 ;
return - V_108 ;
}
V_77 -> V_30 = F_63 ( V_77 -> V_4 -> V_109 ,
1 << V_2 -> V_12 ,
1 , 0 , NULL , NULL ) ;
if ( F_11 ( V_77 -> V_30 ) ) {
V_88 -> error = L_23 ;
return F_13 ( V_77 -> V_30 ) ;
}
if ( F_62 ( V_77 -> V_30 ) <
( ( V_77 -> V_31 + V_77 -> V_11 * V_77 -> V_20 ) >> V_2 -> V_12 ) ) {
V_88 -> error = L_24 ;
return - V_108 ;
}
V_77 -> V_54 = F_63 ( V_2 -> V_32 -> V_109 ,
1 << V_2 -> V_12 ,
1 , 0 , NULL , NULL ) ;
if ( F_11 ( V_77 -> V_54 ) ) {
V_88 -> error = L_25 ;
return F_13 ( V_77 -> V_54 ) ;
}
if ( F_62 ( V_77 -> V_54 ) < V_2 -> V_55 ) {
V_88 -> error = L_26 ;
return - V_108 ;
}
V_77 -> V_58 = F_64 ( F_65 () , F_50 ,
F_52 , ( void * ) V_2 ) ;
if ( ! V_77 -> V_58 ) {
V_88 -> error = L_27 ;
return - V_59 ;
}
V_77 -> V_87 = F_66 ( L_28 ,
V_77 -> V_10 << V_36 ,
0 , 0 , NULL ) ;
if ( ! V_77 -> V_87 ) {
V_88 -> error = L_29 ;
return - V_59 ;
}
V_77 -> V_60 = F_67 ( F_65 () *
V_110 ,
V_77 -> V_87 ) ;
if ( ! V_77 -> V_60 ) {
V_88 -> error = L_30 ;
return - V_59 ;
}
V_77 -> V_62 = F_67 ( 0 , V_77 -> V_87 ) ;
if ( ! V_77 -> V_62 ) {
V_88 -> error = L_31 ;
return - V_59 ;
}
V_77 -> V_64 = F_68 ( F_65 () ,
1 << V_2 -> V_12 ) ;
if ( ! V_77 -> V_64 ) {
V_88 -> error = L_32 ;
return - V_59 ;
}
V_88 -> V_111 += sizeof( struct V_5 ) ;
return 0 ;
}
