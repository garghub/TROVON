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
F_18 ( V_26 ) ;
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
goto V_43;
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
if ( ! V_13 -> V_21 )
V_13 -> V_21 = F_28 ( V_2 -> V_3 -> V_58 , V_59 ) ;
F_29 (n) {
if ( V_13 -> V_35 [ V_41 ] )
continue;
V_13 -> V_35 [ V_41 ] = F_28 ( V_2 -> V_3 -> V_60 , V_61 ) ;
if ( F_10 ( ! V_13 -> V_35 [ V_41 ] ) ) {
F_12 ( L_5 ) ;
return - V_62 ;
}
}
F_30 (fio, n) {
if ( V_13 -> V_35 [ V_41 ] )
continue;
V_13 -> V_35 [ V_41 ] = F_28 ( V_2 -> V_3 -> V_63 , V_61 ) ;
if ( F_10 ( ! V_13 -> V_35 [ V_41 ] ) )
break;
}
V_13 -> V_64 = V_41 ;
if ( ! V_13 -> V_42 )
V_13 -> V_42 = F_28 ( V_2 -> V_3 -> V_65 , V_59 ) ;
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
bool V_66 )
{
int V_39 , V_15 = 0 ;
unsigned V_67 ;
V_39 = F_27 ( V_2 , V_13 ) ;
if ( F_10 ( V_39 < 0 ) )
return V_39 ;
for ( V_67 = 0 ; V_67 < 1 << V_2 -> V_12 ; ) {
F_31 ( V_2 , V_13 ) ;
V_39 = F_25 ( V_2 , V_7 , V_23 , V_8 , V_67 ,
V_66 ? & V_15 : NULL ) ;
if ( F_10 ( V_39 < 0 ) )
return V_39 ;
V_39 = F_16 ( V_2 , V_13 , V_23 , V_39 , V_67 , V_15 ) ;
if ( V_39 < 0 )
return V_39 ;
V_67 += V_13 -> V_64 << V_36 ;
}
V_39 = F_22 ( V_2 , F_23 ( V_2 , V_7 ) , V_13 -> V_42 ,
1 << V_2 -> V_12 ,
F_24 ( V_2 , V_7 ) ) ;
if ( F_10 ( V_39 < 0 ) )
return V_39 ;
if ( memcmp ( F_24 ( V_2 , V_7 ) , F_34 ( V_2 , V_7 ) ,
V_2 -> V_45 ) ) {
F_19 ( L_6 ,
V_2 -> V_32 -> V_33 , ( unsigned long long ) V_23 , V_15 ) ;
return - V_68 ;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , struct V_6 * V_7 , T_3 * V_14 ,
T_5 V_69 )
{
struct V_5 * V_13 = F_2 ( V_7 ) ;
memcpy ( V_14 , & V_13 -> V_42 [ V_13 -> V_70 ] , V_69 ) ;
V_13 -> V_70 += V_69 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , struct V_6 * V_7 ,
enum V_71 type , T_6 V_28 , T_3 * V_72 ,
struct V_73 * V_74 )
{
int V_39 ;
struct V_5 * V_13 = F_2 ( V_7 ) ;
T_1 V_8 , V_29 , V_23 ;
if ( ! F_1 ( V_2 ) )
return - V_75 ;
if ( V_13 -> V_76 >= V_77 ) {
F_20 ( L_7 , V_2 -> V_32 -> V_33 ) ;
return - V_78 ;
}
V_13 -> V_76 ++ ;
if ( type == V_79 )
V_28 += V_2 -> V_55 ;
V_8 = V_28 << V_2 -> V_12 ;
V_29 = F_37 ( V_8 , V_2 -> V_3 -> V_11 << V_2 -> V_12 ) ;
V_23 = V_8 - V_29 * ( V_2 -> V_3 -> V_11 << V_2 -> V_12 ) ;
V_39 = F_33 ( V_2 , V_7 , V_13 , V_23 , V_8 , false ) ;
if ( V_39 < 0 ) {
V_39 = F_33 ( V_2 , V_7 , V_13 , V_23 , V_8 , true ) ;
if ( V_39 < 0 )
goto V_43;
}
if ( V_72 )
memcpy ( V_72 , V_13 -> V_42 , 1 << V_2 -> V_12 ) ;
else if ( V_74 ) {
V_13 -> V_70 = 0 ;
V_39 = F_38 ( V_2 , V_7 , V_74 , F_35 ) ;
}
V_43:
V_13 -> V_76 -- ;
return V_39 ;
}
void F_39 ( struct V_6 * V_7 )
{
unsigned V_41 ;
struct V_80 * V_81 = V_7 -> V_2 -> V_3 ;
struct V_5 * V_13 = F_2 ( V_7 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
return;
F_40 ( V_13 -> V_21 , V_81 -> V_58 ) ;
F_29 (n)
F_40 ( V_13 -> V_35 [ V_41 ] , V_81 -> V_60 ) ;
F_30 (fio, n)
F_40 ( V_13 -> V_35 [ V_41 ] , V_81 -> V_63 ) ;
F_40 ( V_13 -> V_42 , V_81 -> V_65 ) ;
}
void F_41 ( struct V_6 * V_7 )
{
struct V_5 * V_13 = F_2 ( V_7 ) ;
if ( ! F_1 ( V_7 -> V_2 ) )
return;
V_13 -> V_21 = NULL ;
memset ( V_13 -> V_35 , 0 , sizeof( V_13 -> V_35 ) ) ;
V_13 -> V_64 = 0 ;
V_13 -> V_42 = NULL ;
V_13 -> V_76 = 0 ;
}
unsigned F_42 ( struct V_1 * V_2 , unsigned V_82 ,
char * V_83 , unsigned V_84 )
{
if ( ! F_1 ( V_2 ) )
return V_82 ;
F_43 ( L_8 V_85 L_9
V_86 L_10
V_87 L_10
V_88 L_11 ,
V_2 -> V_3 -> V_4 -> V_33 ,
( unsigned long long ) V_2 -> V_3 -> V_89 ,
( unsigned long long ) V_2 -> V_3 -> V_31 ,
V_2 -> V_3 -> V_20 ) ;
return V_82 ;
}
void F_44 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_3 ;
if ( ! F_1 ( V_2 ) )
goto V_90;
F_45 ( V_81 -> V_58 ) ;
F_45 ( V_81 -> V_60 ) ;
F_45 ( V_81 -> V_63 ) ;
F_46 ( V_81 -> V_91 ) ;
if ( V_81 -> V_54 )
F_47 ( V_81 -> V_54 ) ;
if ( V_81 -> V_30 )
F_47 ( V_81 -> V_30 ) ;
if ( V_81 -> V_4 )
F_48 ( V_2 -> V_92 , V_81 -> V_4 ) ;
V_90:
F_49 ( V_81 ) ;
V_2 -> V_3 = NULL ;
}
static void * F_50 ( T_7 V_93 , void * V_94 )
{
struct V_1 * V_2 = (struct V_1 * ) V_94 ;
return F_51 ( 8 , 0x11d , 0 , 1 , V_2 -> V_3 -> V_20 ) ;
}
static void F_52 ( void * V_95 , void * V_94 )
{
struct V_96 * V_21 = (struct V_96 * ) V_95 ;
if ( V_21 )
F_53 ( V_21 ) ;
}
bool F_54 ( const char * V_97 )
{
return ( ! strcasecmp ( V_97 , V_85 ) ||
! strcasecmp ( V_97 , V_86 ) ||
! strcasecmp ( V_97 , V_87 ) ||
! strcasecmp ( V_97 , V_88 ) ) ;
}
int F_55 ( struct V_98 * V_99 , struct V_1 * V_2 ,
unsigned * V_100 , const char * V_97 )
{
int V_39 ;
struct V_101 * V_92 = V_2 -> V_92 ;
const char * V_102 ;
unsigned long long V_103 ;
unsigned char V_104 ;
char V_105 ;
if ( ! * V_100 ) {
V_92 -> error = L_12 ;
return - V_106 ;
}
V_102 = F_56 ( V_99 ) ;
( * V_100 ) -- ;
if ( ! strcasecmp ( V_97 , V_85 ) ) {
V_39 = F_57 ( V_92 , V_102 , V_107 , & V_2 -> V_3 -> V_4 ) ;
if ( V_39 ) {
V_92 -> error = L_13 ;
return V_39 ;
}
} else if ( ! strcasecmp ( V_97 , V_86 ) ) {
if ( sscanf ( V_102 , L_14 , & V_103 , & V_105 ) != 1 ||
( ( T_6 ) ( V_103 << ( V_2 -> V_12 - V_108 ) )
>> ( V_2 -> V_12 - V_108 ) != V_103 ) ) {
V_92 -> error = L_15 V_86 ;
return - V_106 ;
}
V_2 -> V_3 -> V_89 = V_103 ;
} else if ( ! strcasecmp ( V_97 , V_87 ) ) {
if ( sscanf ( V_102 , L_14 , & V_103 , & V_105 ) != 1 ||
( ( T_6 ) ( V_103 << ( V_2 -> V_12 - V_108 ) ) >>
( V_2 -> V_12 - V_108 ) != V_103 ) ) {
V_92 -> error = L_15 V_87 ;
return - V_106 ;
}
V_2 -> V_3 -> V_31 = V_103 ;
} else if ( ! strcasecmp ( V_97 , V_88 ) ) {
if ( sscanf ( V_102 , L_16 , & V_104 , & V_105 ) != 1 || ! V_104 ||
V_104 < ( V_18 - V_109 ) ||
V_104 > ( V_18 - V_19 ) ) {
V_92 -> error = L_15 V_88 ;
return - V_106 ;
}
V_2 -> V_3 -> V_20 = V_104 ;
} else {
V_92 -> error = L_17 ;
return - V_106 ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 )
{
struct V_80 * V_81 ;
V_81 = F_59 ( sizeof( struct V_80 ) , V_110 ) ;
if ( ! V_81 ) {
V_2 -> V_92 -> error = L_18 ;
return - V_62 ;
}
V_2 -> V_3 = V_81 ;
return 0 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_80 * V_81 = V_2 -> V_3 ;
struct V_101 * V_92 = V_2 -> V_92 ;
T_1 V_56 ;
if ( ! F_1 ( V_2 ) ) {
F_44 ( V_2 ) ;
return 0 ;
}
V_56 = V_2 -> V_56 - V_2 -> V_57 ;
if ( V_2 -> V_12 != V_2 -> V_111 ) {
V_92 -> error = L_19 ;
return - V_106 ;
}
if ( ! V_81 -> V_20 ) {
V_92 -> error = L_20 V_88 ;
return - V_106 ;
}
V_81 -> V_10 = V_18 - V_81 -> V_20 ;
if ( ! V_81 -> V_89 ) {
V_92 -> error = L_20 V_86 ;
return - V_106 ;
}
V_81 -> V_11 = V_81 -> V_89 ;
if ( F_61 ( V_81 -> V_11 , V_81 -> V_10 ) )
V_81 -> V_11 ++ ;
if ( V_81 -> V_89 < V_2 -> V_55 + V_56 || ! V_81 -> V_11 ) {
V_92 -> error = L_15 V_86 ;
return - V_106 ;
}
V_81 -> V_56 = V_81 -> V_89 - V_2 -> V_55 ;
if ( F_62 ( V_2 -> V_30 ) < V_81 -> V_56 ) {
V_92 -> error = L_21
V_86 ;
return - V_112 ;
}
V_81 -> V_30 = F_63 ( V_81 -> V_4 -> V_113 ,
1 << V_2 -> V_12 ,
1 , 0 , NULL , NULL ) ;
if ( F_11 ( V_81 -> V_30 ) ) {
V_92 -> error = L_22 ;
return F_13 ( V_81 -> V_30 ) ;
}
if ( F_62 ( V_81 -> V_30 ) <
( ( V_81 -> V_31 + V_81 -> V_11 * V_81 -> V_20 ) >> V_2 -> V_12 ) ) {
V_92 -> error = L_23 ;
return - V_112 ;
}
V_81 -> V_54 = F_63 ( V_2 -> V_32 -> V_113 ,
1 << V_2 -> V_12 ,
1 , 0 , NULL , NULL ) ;
if ( F_11 ( V_81 -> V_54 ) ) {
V_92 -> error = L_24 ;
return F_13 ( V_81 -> V_54 ) ;
}
if ( F_62 ( V_81 -> V_54 ) < V_2 -> V_55 ) {
V_92 -> error = L_25 ;
return - V_112 ;
}
V_81 -> V_58 = F_64 ( F_65 () , F_50 ,
F_52 , ( void * ) V_2 ) ;
if ( ! V_81 -> V_58 ) {
V_92 -> error = L_26 ;
return - V_62 ;
}
V_81 -> V_91 = F_66 ( L_27 ,
V_81 -> V_10 << V_36 ,
0 , 0 , NULL ) ;
if ( ! V_81 -> V_91 ) {
V_92 -> error = L_28 ;
return - V_62 ;
}
V_81 -> V_60 = F_67 ( F_65 () *
V_114 ,
V_81 -> V_91 ) ;
if ( ! V_81 -> V_60 ) {
V_92 -> error = L_29 ;
return - V_62 ;
}
V_81 -> V_63 = F_67 ( 0 , V_81 -> V_91 ) ;
if ( ! V_81 -> V_63 ) {
V_92 -> error = L_30 ;
return - V_62 ;
}
V_81 -> V_65 = F_68 ( F_65 () ,
1 << V_2 -> V_12 ) ;
if ( ! V_81 -> V_65 ) {
V_92 -> error = L_31 ;
return - V_62 ;
}
V_92 -> V_115 += sizeof( struct V_5 ) ;
return 0 ;
}
