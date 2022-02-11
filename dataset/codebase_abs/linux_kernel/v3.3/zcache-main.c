static inline T_1 F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 == NULL ) ;
if ( V_2 == & V_3 )
return V_4 ;
return V_2 - & V_5 [ 0 ] ;
}
static inline bool F_3 ( struct V_1 * V_2 )
{
return V_2 == & V_3 ;
}
static inline unsigned F_4 ( void )
{
return V_6 << V_7 ;
}
static inline unsigned F_5 ( unsigned V_8 )
{
F_2 ( V_8 == 0 || V_8 > F_4 () ) ;
return ( V_8 + V_9 - 1 ) >> V_7 ;
}
static inline int F_6 ( struct V_10 * V_11 )
{
unsigned V_12 = ( unsigned long ) V_11 & ( V_13 - 1 ) ;
struct V_14 * V_15 = NULL ;
unsigned V_16 = - 1U ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ )
if ( V_12 == F_7 ( F_8 ( * V_15 ) , V_19 [ V_17 ] ) ) {
V_16 = V_17 ;
break;
}
F_2 ( V_16 == - 1U ) ;
return V_16 ;
}
static char * F_9 ( struct V_10 * V_11 , unsigned V_8 )
{
struct V_14 * V_15 ;
char * V_20 ;
unsigned V_16 ;
F_10 ( V_11 , V_21 ) ;
V_16 = F_6 ( V_11 ) ;
F_2 ( V_8 == 0 || V_8 > F_4 () ) ;
V_15 = F_11 ( V_11 , struct V_14 , V_19 [ V_16 ] ) ;
F_12 ( & V_15 -> V_22 ) ;
V_20 = ( char * ) V_15 ;
if ( V_16 == 0 )
V_20 += ( ( sizeof( struct V_14 ) + V_9 - 1 ) &
V_23 ) ;
else if ( V_16 == 1 )
V_20 += V_13 - ( ( V_8 + V_9 - 1 ) & V_23 ) ;
return V_20 ;
}
static struct V_14 * F_13 ( void )
{
struct V_14 * V_15 = NULL ;
struct V_10 * V_24 , * V_25 ;
bool V_26 = 0 ;
F_14 ( & V_27 ) ;
if ( ! F_15 ( & V_28 ) ) {
V_15 = F_16 ( & V_28 ,
struct V_14 , V_29 ) ;
F_17 ( & V_15 -> V_29 ) ;
V_30 -- ;
V_26 = 1 ;
}
F_18 ( & V_27 ) ;
if ( V_15 == NULL )
V_15 = F_19 () ;
if ( F_20 ( V_15 != NULL ) ) {
F_21 ( & V_15 -> V_29 ) ;
V_24 = & V_15 -> V_19 [ 0 ] ; V_25 = & V_15 -> V_19 [ 1 ] ;
F_22 ( & V_15 -> V_22 ) ;
if ( V_26 ) {
F_23 ( V_15 , V_31 ) ;
F_24 ( V_15 , V_31 ) ;
F_2 ( V_24 -> V_8 != 0 || F_25 ( & V_24 -> V_32 ) ) ;
F_2 ( V_25 -> V_8 != 0 || F_25 ( & V_25 -> V_32 ) ) ;
} else {
F_26 ( & V_33 ) ;
F_21 ( & V_15 -> V_29 ) ;
F_24 ( V_15 , V_31 ) ;
V_24 -> V_8 = 0 ; V_25 -> V_8 = 0 ;
F_27 ( & V_24 -> V_32 ) ;
F_27 ( & V_25 -> V_32 ) ;
}
}
return V_15 ;
}
static void F_28 ( struct V_14 * V_15 )
{
struct V_10 * V_24 = & V_15 -> V_19 [ 0 ] , * V_25 = & V_15 -> V_19 [ 1 ] ;
F_10 ( V_15 , V_31 ) ;
F_2 ( ! F_15 ( & V_15 -> V_29 ) ) ;
F_12 ( & V_15 -> V_22 ) ;
F_2 ( V_24 -> V_8 != 0 || F_25 ( & V_24 -> V_32 ) ) ;
F_2 ( V_25 -> V_8 != 0 || F_25 ( & V_25 -> V_32 ) ) ;
F_29 ( V_15 , V_31 ) ;
F_18 ( & V_15 -> V_22 ) ;
F_14 ( & V_27 ) ;
F_30 ( & V_15 -> V_29 , & V_28 ) ;
V_30 ++ ;
F_18 ( & V_27 ) ;
}
static unsigned F_31 ( struct V_10 * V_11 )
{
unsigned V_8 ;
F_10 ( V_11 , V_21 ) ;
F_2 ( ! F_25 ( & V_11 -> V_32 ) ) ;
V_8 = V_11 -> V_8 ;
F_2 ( V_11 -> V_8 == 0 || V_11 -> V_8 > F_4 () ) ;
V_11 -> V_8 = 0 ;
F_27 ( & V_11 -> V_32 ) ;
F_29 ( V_11 , V_21 ) ;
V_34 -= V_8 ;
F_32 ( & V_35 ) ;
return V_8 ;
}
static void F_33 ( struct V_10 * V_11 )
{
unsigned V_36 ;
struct V_10 * V_37 ;
unsigned V_16 = F_6 ( V_11 ) , V_8 ;
struct V_14 * V_15 =
F_11 ( V_11 , struct V_14 , V_19 [ V_16 ] ) ;
F_14 ( & V_15 -> V_22 ) ;
if ( F_15 ( & V_15 -> V_29 ) ) {
F_18 ( & V_15 -> V_22 ) ;
return;
}
V_8 = F_31 ( V_11 ) ;
F_12 ( & V_15 -> V_22 ) ;
V_37 = & V_15 -> V_19 [ ( V_16 == 0 ) ? 1 : 0 ] ;
if ( V_37 -> V_8 == 0 ) {
V_36 = F_5 ( V_8 ) ;
F_14 ( & V_38 ) ;
F_2 ( F_15 ( & V_39 [ V_36 ] . V_40 ) ) ;
F_17 ( & V_15 -> V_29 ) ;
V_39 [ V_36 ] . V_41 -- ;
F_18 ( & V_38 ) ;
F_28 ( V_15 ) ;
} else {
V_36 = F_5 ( V_37 -> V_8 ) ;
F_14 ( & V_38 ) ;
F_17 ( & V_15 -> V_29 ) ;
V_42 -- ;
F_34 ( & V_15 -> V_29 , & V_39 [ V_36 ] . V_40 ) ;
V_39 [ V_36 ] . V_41 ++ ;
F_18 ( & V_38 ) ;
F_18 ( & V_15 -> V_22 ) ;
}
}
static struct V_10 * F_35 ( T_1 V_43 , T_1 V_44 ,
struct V_45 * V_32 ,
T_2 V_46 , struct V_47 * V_47 ,
void * V_48 , unsigned V_8 )
{
struct V_10 * V_24 , * V_25 , * V_11 = NULL ;
struct V_14 * V_15 = NULL , * V_49 ;
unsigned V_50 ;
char * V_51 ;
int V_17 , V_52 = 0 ;
V_50 = F_5 ( V_8 ) ;
for ( V_17 = V_6 - V_50 + 1 ; V_17 > 0 ; V_17 -- ) {
F_14 ( & V_38 ) ;
if ( ! F_15 ( & V_39 [ V_17 ] . V_40 ) ) {
F_36 (zbpg, ztmp,
&zbud_unbuddied[i].list, bud_list) {
if ( F_37 ( & V_15 -> V_22 ) ) {
V_52 = V_17 ;
goto V_53;
}
}
}
F_18 ( & V_38 ) ;
}
V_15 = F_13 () ;
if ( F_38 ( V_15 == NULL ) )
goto V_54;
F_14 ( & V_38 ) ;
F_14 ( & V_15 -> V_22 ) ;
F_34 ( & V_15 -> V_29 , & V_39 [ V_50 ] . V_40 ) ;
V_39 [ V_50 ] . V_41 ++ ;
V_11 = & V_15 -> V_19 [ 0 ] ;
goto V_55;
V_53:
F_12 ( & V_15 -> V_22 ) ;
V_24 = & V_15 -> V_19 [ 0 ] ; V_25 = & V_15 -> V_19 [ 1 ] ;
F_2 ( ! ( ( V_24 -> V_8 == 0 ) ^ ( V_25 -> V_8 == 0 ) ) ) ;
if ( V_24 -> V_8 != 0 ) {
F_10 ( V_24 , V_21 ) ;
V_11 = V_25 ;
} else if ( V_25 -> V_8 != 0 ) {
F_10 ( V_25 , V_21 ) ;
V_11 = V_24 ;
} else
F_39 () ;
F_17 ( & V_15 -> V_29 ) ;
V_39 [ V_52 ] . V_41 -- ;
F_34 ( & V_15 -> V_29 , & V_56 ) ;
V_42 ++ ;
V_55:
F_24 ( V_11 , V_21 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_46 = V_46 ;
V_11 -> V_32 = * V_32 ;
V_11 -> V_44 = V_44 ;
V_11 -> V_43 = V_43 ;
V_51 = F_9 ( V_11 , V_8 ) ;
memcpy ( V_51 , V_48 , V_8 ) ;
F_18 ( & V_15 -> V_22 ) ;
F_18 ( & V_38 ) ;
V_57 [ V_50 ] ++ ;
F_26 ( & V_35 ) ;
V_58 ++ ;
V_34 += V_8 ;
V_59 += V_8 ;
V_54:
return V_11 ;
}
static int F_40 ( struct V_47 * V_47 , struct V_10 * V_11 )
{
struct V_14 * V_15 ;
unsigned V_16 = F_6 ( V_11 ) ;
T_3 V_60 = V_13 ;
char * V_61 , * V_62 ;
unsigned V_8 ;
int V_63 = 0 ;
V_15 = F_11 ( V_11 , struct V_14 , V_19 [ V_16 ] ) ;
F_14 ( & V_15 -> V_22 ) ;
if ( F_15 ( & V_15 -> V_29 ) ) {
V_63 = - V_64 ;
goto V_54;
}
F_10 ( V_11 , V_21 ) ;
F_2 ( V_11 -> V_8 == 0 || V_11 -> V_8 > F_4 () ) ;
V_61 = F_41 ( V_47 , V_65 ) ;
V_8 = V_11 -> V_8 ;
V_62 = F_9 ( V_11 , V_8 ) ;
V_63 = F_42 ( V_62 , V_8 , V_61 , & V_60 ) ;
F_2 ( V_63 != V_66 ) ;
F_2 ( V_60 != V_13 ) ;
F_43 ( V_61 , V_65 ) ;
V_54:
F_18 ( & V_15 -> V_22 ) ;
return V_63 ;
}
static void F_44 ( struct V_14 * V_15 )
{
struct V_10 * V_11 ;
int V_17 , V_67 ;
T_2 V_44 [ V_18 ] , V_43 [ V_18 ] ;
T_2 V_46 [ V_18 ] ;
struct V_45 V_32 [ V_18 ] ;
struct V_68 * V_69 ;
F_12 ( & V_15 -> V_22 ) ;
F_2 ( ! F_15 ( & V_15 -> V_29 ) ) ;
for ( V_17 = 0 , V_67 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_11 = & V_15 -> V_19 [ V_17 ] ;
if ( V_11 -> V_8 ) {
V_43 [ V_67 ] = V_11 -> V_43 ;
V_44 [ V_67 ] = V_11 -> V_44 ;
V_32 [ V_67 ] = V_11 -> V_32 ;
V_46 [ V_67 ] = V_11 -> V_46 ;
V_67 ++ ;
F_31 ( V_11 ) ;
}
}
F_18 ( & V_15 -> V_22 ) ;
for ( V_17 = 0 ; V_17 < V_67 ; V_17 ++ ) {
V_69 = F_45 ( V_43 [ V_17 ] , V_44 [ V_17 ] ) ;
if ( V_69 != NULL ) {
F_46 ( V_69 , & V_32 [ V_17 ] , V_46 [ V_17 ] ) ;
F_47 ( V_69 ) ;
}
}
F_10 ( V_15 , V_31 ) ;
F_14 ( & V_15 -> V_22 ) ;
F_28 ( V_15 ) ;
}
static void F_48 ( int V_70 )
{
struct V_14 * V_15 ;
int V_17 ;
V_71:
F_49 ( & V_27 ) ;
if ( ! F_15 ( & V_28 ) ) {
V_15 = F_16 ( & V_28 ,
struct V_14 , V_29 ) ;
F_17 ( & V_15 -> V_29 ) ;
V_30 -- ;
F_32 ( & V_33 ) ;
F_50 ( & V_27 ) ;
F_51 ( V_15 ) ;
V_72 ++ ;
if ( -- V_70 <= 0 )
goto V_54;
goto V_71;
}
F_50 ( & V_27 ) ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
V_73:
F_49 ( & V_38 ) ;
if ( F_15 ( & V_39 [ V_17 ] . V_40 ) ) {
F_50 ( & V_38 ) ;
continue;
}
F_52 (zbpg, &zbud_unbuddied[i].list, bud_list) {
if ( F_38 ( ! F_37 ( & V_15 -> V_22 ) ) )
continue;
F_17 ( & V_15 -> V_29 ) ;
V_39 [ V_17 ] . V_41 -- ;
F_18 ( & V_38 ) ;
V_74 ++ ;
F_44 ( V_15 ) ;
F_53 () ;
if ( -- V_70 <= 0 )
goto V_54;
goto V_73;
}
F_50 ( & V_38 ) ;
}
V_75:
F_49 ( & V_38 ) ;
if ( F_15 ( & V_56 ) ) {
F_50 ( & V_38 ) ;
goto V_54;
}
F_52 (zbpg, &zbud_buddied_list, bud_list) {
if ( F_38 ( ! F_37 ( & V_15 -> V_22 ) ) )
continue;
F_17 ( & V_15 -> V_29 ) ;
V_42 -- ;
F_18 ( & V_38 ) ;
V_76 ++ ;
F_44 ( V_15 ) ;
F_53 () ;
if ( -- V_70 <= 0 )
goto V_54;
goto V_75;
}
F_50 ( & V_38 ) ;
V_54:
return;
}
static void F_54 ( void )
{
int V_17 ;
F_21 ( & V_56 ) ;
V_42 = 0 ;
for ( V_17 = 0 ; V_17 < V_77 ; V_17 ++ ) {
F_21 ( & V_39 [ V_17 ] . V_40 ) ;
V_39 [ V_17 ] . V_41 = 0 ;
}
}
static int F_55 ( char * V_78 )
{
int V_17 ;
char * V_20 = V_78 ;
for ( V_17 = 0 ; V_17 < V_77 ; V_17 ++ )
V_20 += sprintf ( V_20 , L_1 , V_39 [ V_17 ] . V_41 ) ;
return V_20 - V_78 ;
}
static int F_56 ( char * V_78 )
{
unsigned long V_17 , V_36 = 0 , V_79 = 0 , V_80 = 0 ;
unsigned long V_81 = 0 , V_82 = 0 ;
unsigned long V_83 = 0 ;
char * V_20 = V_78 ;
for ( V_17 = 0 ; V_17 < V_77 ; V_17 ++ ) {
V_20 += sprintf ( V_20 , L_2 , V_57 [ V_17 ] ) ;
V_36 += V_57 [ V_17 ] ;
V_79 += V_57 [ V_17 ] ;
V_80 += V_17 * V_57 [ V_17 ] ;
if ( V_17 == 21 )
V_81 = V_79 ;
if ( V_17 == 32 )
V_82 = V_79 ;
if ( V_17 == 42 )
V_83 = V_79 ;
}
V_20 += sprintf ( V_20 , L_3 ,
V_81 , V_82 , V_83 ,
V_36 == 0 ? 0 : V_80 / V_36 ) ;
return V_20 - V_78 ;
}
static struct V_84 * F_57 ( struct V_85 * V_86 , T_2 V_44 ,
struct V_45 * V_32 , T_2 V_46 ,
void * V_48 , unsigned V_87 )
{
struct V_47 * V_47 ;
struct V_84 * V_88 = NULL ;
T_2 V_12 ;
int V_89 = V_87 + sizeof( struct V_84 ) ;
int V_36 = ( V_89 + ( V_9 - 1 ) ) >> V_7 ;
int V_63 ;
F_2 ( ! F_58 () ) ;
F_2 ( V_36 >= V_77 ) ;
V_63 = F_59 ( V_86 , V_89 ,
& V_47 , & V_12 , V_90 ) ;
if ( F_38 ( V_63 ) )
goto V_54;
F_26 ( & V_91 [ V_36 ] ) ;
F_26 ( & V_92 [ V_36 ] ) ;
V_88 = F_41 ( V_47 , V_65 ) + V_12 ;
V_88 -> V_46 = V_46 ;
V_88 -> V_32 = * V_32 ;
V_88 -> V_44 = V_44 ;
F_24 ( V_88 , V_93 ) ;
memcpy ( ( char * ) V_88 + sizeof( struct V_84 ) , V_48 , V_87 ) ;
F_43 ( V_88 , V_65 ) ;
V_54:
return V_88 ;
}
static void F_60 ( struct V_85 * V_86 , struct V_84 * V_88 )
{
unsigned long V_94 ;
struct V_47 * V_47 ;
T_2 V_12 ;
T_1 V_8 = F_61 ( V_88 ) ;
int V_36 = ( V_8 + ( V_9 - 1 ) ) >> V_7 ;
F_10 ( V_88 , V_93 ) ;
F_2 ( V_36 >= V_77 ) ;
F_32 ( & V_91 [ V_36 ] ) ;
V_8 -= sizeof( * V_88 ) ;
F_2 ( V_8 == 0 ) ;
F_29 ( V_88 , V_93 ) ;
V_47 = F_62 ( V_88 ) ;
V_12 = ( unsigned long ) V_88 & ~ V_95 ;
F_63 ( V_94 ) ;
F_64 ( V_86 , V_47 , V_12 ) ;
F_65 ( V_94 ) ;
}
static void F_66 ( struct V_47 * V_47 , struct V_84 * V_88 )
{
T_3 V_87 = V_13 ;
char * V_61 ;
unsigned V_8 ;
int V_63 ;
F_10 ( V_88 , V_93 ) ;
V_8 = F_61 ( V_88 ) - sizeof( * V_88 ) ;
F_2 ( V_8 == 0 ) ;
V_61 = F_41 ( V_47 , V_65 ) ;
V_63 = F_42 ( ( char * ) V_88 + sizeof( * V_88 ) ,
V_8 , V_61 , & V_87 ) ;
F_43 ( V_61 , V_65 ) ;
F_2 ( V_63 != V_66 ) ;
F_2 ( V_87 != V_13 ) ;
}
static int F_67 ( char * V_78 )
{
unsigned long V_17 , V_96 , V_36 = 0 , V_80 = 0 ;
char * V_20 = V_78 ;
for ( V_17 = 0 ; V_17 < V_77 ; V_17 ++ ) {
V_96 = F_68 ( & V_91 [ V_17 ] ) ;
V_20 += sprintf ( V_20 , L_2 , V_96 ) ;
V_36 += V_96 ;
V_80 += V_17 * V_96 ;
}
V_20 += sprintf ( V_20 , L_4 ,
V_36 == 0 ? 0 : V_80 / V_36 ) ;
return V_20 - V_78 ;
}
static int F_69 ( char * V_78 )
{
unsigned long V_17 , V_96 , V_36 = 0 , V_80 = 0 ;
char * V_20 = V_78 ;
for ( V_17 = 0 ; V_17 < V_77 ; V_17 ++ ) {
V_96 = F_68 ( & V_92 [ V_17 ] ) ;
V_20 += sprintf ( V_20 , L_2 , V_96 ) ;
V_36 += V_96 ;
V_80 += V_17 * V_96 ;
}
V_20 += sprintf ( V_20 , L_4 ,
V_36 == 0 ? 0 : V_80 / V_36 ) ;
return V_20 - V_78 ;
}
static T_4 F_70 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_78 )
{
return sprintf ( V_78 , L_5 , V_101 ) ;
}
static T_4 F_71 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_78 , T_3 V_41 )
{
unsigned long V_102 ;
int V_103 ;
if ( ! F_72 ( V_104 ) )
return - V_105 ;
V_103 = F_73 ( V_78 , 10 , & V_102 ) ;
if ( V_103 || ( V_102 == 0 ) || ( V_102 > ( V_13 / 8 ) * 7 ) )
return - V_64 ;
V_101 = V_102 ;
return V_41 ;
}
static T_4 F_74 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_78 )
{
return sprintf ( V_78 , L_5 , V_106 ) ;
}
static T_4 F_75 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_78 , T_3 V_41 )
{
unsigned long V_102 ;
int V_103 ;
if ( ! F_72 ( V_104 ) )
return - V_105 ;
V_103 = F_73 ( V_78 , 10 , & V_102 ) ;
if ( V_103 || ( V_102 == 0 ) || ( V_102 > ( V_13 / 8 ) * 7 ) )
return - V_64 ;
V_106 = V_102 ;
return V_41 ;
}
static T_4 F_76 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
char * V_78 )
{
return sprintf ( V_78 , L_5 , V_107 ) ;
}
static T_4 F_77 ( struct V_97 * V_98 ,
struct V_99 * V_100 ,
const char * V_78 , T_3 V_41 )
{
unsigned long V_102 ;
int V_103 ;
if ( ! F_72 ( V_104 ) )
return - V_105 ;
V_103 = F_73 ( V_78 , 10 , & V_102 ) ;
if ( V_103 || ( V_102 == 0 ) || ( V_102 > 150 ) )
return - V_64 ;
V_107 = V_102 ;
return V_41 ;
}
static struct V_68 * F_45 ( T_1 V_108 , T_1 V_109 )
{
struct V_68 * V_69 = NULL ;
struct V_1 * V_2 = NULL ;
if ( V_108 == V_4 )
V_2 = & V_3 ;
else {
if ( V_108 >= V_110 )
goto V_54;
V_2 = & V_5 [ V_108 ] ;
if ( V_2 == NULL )
goto V_54;
F_26 ( & V_2 -> V_111 ) ;
}
if ( V_109 < V_112 ) {
V_69 = V_2 -> V_113 [ V_109 ] ;
if ( V_69 != NULL )
F_26 ( & V_69 -> V_111 ) ;
}
V_54:
return V_69 ;
}
static void F_47 ( struct V_68 * V_69 )
{
struct V_1 * V_2 = NULL ;
if ( V_69 == NULL )
F_39 () ;
V_2 = V_69 -> V_114 ;
F_32 ( & V_69 -> V_111 ) ;
F_32 ( & V_2 -> V_111 ) ;
}
int F_78 ( T_1 V_108 )
{
struct V_1 * V_2 = NULL ;
int V_63 = - 1 ;
if ( V_108 == V_4 )
V_2 = & V_3 ;
else if ( ( unsigned int ) V_108 < V_110 )
V_2 = & V_5 [ V_108 ] ;
if ( V_2 == NULL )
goto V_54;
if ( V_2 -> V_115 )
goto V_54;
V_2 -> V_115 = 1 ;
#ifdef F_79
V_2 -> V_86 = F_80 () ;
if ( V_2 -> V_86 == NULL )
goto V_54;
#endif
V_63 = 0 ;
V_54:
return V_63 ;
}
static int F_81 ( struct V_68 * V_69 )
{
struct V_116 * V_117 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
void * V_47 ;
int V_63 = - V_122 ;
if ( F_38 ( V_123 == NULL ) )
goto V_54;
if ( F_38 ( V_124 == NULL ) )
goto V_54;
F_82 () ;
V_117 = & F_83 ( V_125 ) ;
while ( V_117 -> V_70 < F_84 ( V_117 -> V_126 ) ) {
F_85 () ;
V_119 = F_86 ( V_123 ,
V_90 ) ;
if ( F_38 ( V_119 == NULL ) ) {
V_127 ++ ;
goto V_54;
}
F_82 () ;
V_117 = & F_83 ( V_125 ) ;
if ( V_117 -> V_70 < F_84 ( V_117 -> V_126 ) )
V_117 -> V_126 [ V_117 -> V_70 ++ ] = V_119 ;
else
F_87 ( V_123 , V_119 ) ;
}
F_85 () ;
V_121 = F_86 ( V_124 , V_90 ) ;
if ( F_38 ( V_121 == NULL ) ) {
V_127 ++ ;
goto V_54;
}
V_47 = ( void * ) F_88 ( V_90 ) ;
if ( F_38 ( V_47 == NULL ) ) {
V_128 ++ ;
F_87 ( V_124 , V_121 ) ;
goto V_54;
}
F_82 () ;
V_117 = & F_83 ( V_125 ) ;
if ( V_117 -> V_121 == NULL )
V_117 -> V_121 = V_121 ;
else
F_87 ( V_124 , V_121 ) ;
if ( V_117 -> V_47 == NULL )
V_117 -> V_47 = V_47 ;
else
F_89 ( ( unsigned long ) V_47 ) ;
V_63 = 0 ;
V_54:
return V_63 ;
}
static void * F_19 ( void )
{
struct V_116 * V_117 ;
void * V_47 ;
V_117 = & F_83 ( V_125 ) ;
V_47 = V_117 -> V_47 ;
F_2 ( V_47 == NULL ) ;
V_117 -> V_47 = NULL ;
return V_47 ;
}
static void F_51 ( void * V_20 )
{
F_89 ( ( unsigned long ) V_20 ) ;
}
static struct V_118 * F_90 ( struct V_68 * V_69 )
{
struct V_118 * V_119 = NULL ;
unsigned long V_41 ;
struct V_116 * V_117 ;
V_117 = & F_83 ( V_125 ) ;
if ( V_117 -> V_70 <= 0 )
goto V_54;
V_119 = V_117 -> V_126 [ V_117 -> V_70 - 1 ] ;
F_2 ( V_119 == NULL ) ;
V_117 -> V_126 [ V_117 -> V_70 - 1 ] = NULL ;
V_117 -> V_70 -- ;
V_41 = F_91 ( & V_129 ) ;
if ( V_41 > V_130 )
V_130 = V_41 ;
V_54:
return V_119 ;
}
static void F_92 ( struct V_118 * V_119 ,
struct V_68 * V_69 )
{
F_32 ( & V_129 ) ;
F_2 ( F_68 ( & V_129 ) < 0 ) ;
F_87 ( V_123 , V_119 ) ;
}
static struct V_120 * F_93 ( struct V_68 * V_69 )
{
struct V_120 * V_121 = NULL ;
unsigned long V_41 ;
struct V_116 * V_117 ;
V_117 = & F_83 ( V_125 ) ;
V_121 = V_117 -> V_121 ;
F_2 ( V_121 == NULL ) ;
V_117 -> V_121 = NULL ;
V_41 = F_91 ( & V_131 ) ;
if ( V_41 > V_132 )
V_132 = V_41 ;
return V_121 ;
}
static void F_94 ( struct V_120 * V_121 , struct V_68 * V_69 )
{
F_32 ( & V_131 ) ;
F_2 ( F_68 ( & V_131 ) < 0 ) ;
F_87 ( V_124 , V_121 ) ;
}
static void * F_95 ( char * V_133 , T_3 V_8 , bool V_134 , int V_135 ,
struct V_68 * V_69 , struct V_45 * V_32 ,
T_2 V_46 )
{
void * V_136 = NULL , * V_48 ;
T_3 V_87 ;
int V_63 ;
unsigned long V_41 ;
struct V_47 * V_47 = (struct V_47 * ) ( V_133 ) ;
struct V_1 * V_2 = V_69 -> V_114 ;
T_1 V_43 = F_1 ( V_2 ) ;
unsigned long V_137 ;
unsigned long V_138 ;
T_5 V_139 ;
if ( V_135 ) {
V_63 = F_96 ( V_47 , & V_48 , & V_87 ) ;
if ( V_63 == 0 )
goto V_54;
if ( V_87 == 0 || V_87 > F_4 () ) {
V_140 ++ ;
goto V_54;
}
V_136 = ( void * ) F_35 ( V_43 , V_69 -> V_44 , V_32 ,
V_46 , V_47 , V_48 , V_87 ) ;
if ( V_136 != NULL ) {
V_41 = F_91 ( & V_141 ) ;
if ( V_41 > V_142 )
V_142 = V_41 ;
}
} else {
V_138 =
F_68 ( & V_143 ) ;
if ( V_138 >
( V_107 * V_144 ) / 100 )
goto V_54;
V_63 = F_96 ( V_47 , & V_48 , & V_87 ) ;
if ( V_63 == 0 )
goto V_54;
if ( V_87 > V_101 ) {
V_140 ++ ;
goto V_54;
}
if ( ( V_87 > V_106 ) && ( V_138 > 0 ) ) {
V_139 = F_97 ( V_2 -> V_86 ) ;
V_137 = F_98 ( V_139 ,
V_138 ) ;
if ( V_137 > V_106 ) {
V_145 ++ ;
goto V_54;
}
}
V_136 = ( void * ) F_57 ( V_2 -> V_86 , V_69 -> V_44 ,
V_32 , V_46 , V_48 , V_87 ) ;
if ( V_136 == NULL )
goto V_54;
V_41 = F_91 ( & V_143 ) ;
if ( V_41 > V_146 )
V_146 = V_41 ;
}
V_54:
return V_136 ;
}
static int F_99 ( char * V_133 , T_3 * V_147 , bool V_134 ,
void * V_136 , struct V_68 * V_69 ,
struct V_45 * V_32 , T_2 V_46 )
{
int V_63 = 0 ;
F_2 ( F_100 ( V_69 ) ) ;
F_66 ( (struct V_47 * ) ( V_133 ) , V_136 ) ;
return V_63 ;
}
static int F_101 ( char * V_133 , T_3 * V_147 , bool V_134 ,
void * V_136 , struct V_68 * V_69 ,
struct V_45 * V_32 , T_2 V_46 )
{
int V_63 = 0 ;
F_2 ( ! F_100 ( V_69 ) ) ;
F_40 ( (struct V_47 * ) ( V_133 ) , V_136 ) ;
F_33 ( (struct V_10 * ) V_136 ) ;
F_32 ( & V_141 ) ;
return V_63 ;
}
static void F_102 ( void * V_136 , struct V_68 * V_69 ,
struct V_45 * V_32 , T_2 V_46 )
{
struct V_1 * V_2 = V_69 -> V_114 ;
if ( F_100 ( V_69 ) ) {
F_33 ( (struct V_10 * ) V_136 ) ;
F_32 ( & V_141 ) ;
F_2 ( F_68 ( & V_141 ) < 0 ) ;
} else {
F_60 ( V_2 -> V_86 , (struct V_84 * ) V_136 ) ;
F_32 ( & V_143 ) ;
F_2 ( F_68 ( & V_143 ) < 0 ) ;
}
}
static void F_103 ( struct V_68 * V_69 , struct V_120 * V_121 )
{
}
static void F_104 ( struct V_120 * V_121 )
{
}
static int F_105 ( void * V_136 , struct V_120 * V_121 )
{
return - 1 ;
}
static bool F_106 ( void * V_136 )
{
return 0 ;
}
static int F_96 ( struct V_47 * V_148 , void * * V_149 , T_3 * V_60 )
{
int V_63 = 0 ;
unsigned char * V_150 = F_83 ( V_151 ) ;
unsigned char * V_152 = F_83 ( V_153 ) ;
char * V_62 ;
F_2 ( ! F_58 () ) ;
if ( F_38 ( V_150 == NULL || V_152 == NULL ) )
goto V_54;
V_62 = F_41 ( V_148 , V_65 ) ;
F_107 () ;
V_63 = F_108 ( V_62 , V_13 , V_150 , V_60 , V_152 ) ;
F_2 ( V_63 != V_66 ) ;
* V_149 = V_150 ;
F_43 ( V_62 , V_65 ) ;
V_63 = 1 ;
V_54:
return V_63 ;
}
static int F_109 ( struct V_154 * V_155 ,
unsigned long V_156 , void * V_157 )
{
int V_158 = ( long ) V_157 ;
struct V_116 * V_117 ;
switch ( V_156 ) {
case V_159 :
F_110 ( V_151 , V_158 ) = ( void * ) F_111 (
V_160 | V_161 ,
V_162 ) ,
F_110 ( V_153 , V_158 ) =
F_112 ( V_163 ,
V_160 | V_161 ) ;
break;
case V_164 :
case V_165 :
F_113 ( ( unsigned long ) F_110 ( V_151 , V_158 ) ,
V_162 ) ;
F_110 ( V_151 , V_158 ) = NULL ;
F_114 ( F_110 ( V_153 , V_158 ) ) ;
F_110 ( V_153 , V_158 ) = NULL ;
V_117 = & F_110 ( V_125 , V_158 ) ;
while ( V_117 -> V_70 ) {
F_87 ( V_123 ,
V_117 -> V_126 [ V_117 -> V_70 - 1 ] ) ;
V_117 -> V_126 [ V_117 -> V_70 - 1 ] = NULL ;
V_117 -> V_70 -- ;
}
if ( V_117 -> V_121 ) {
F_87 ( V_124 , V_117 -> V_121 ) ;
V_117 -> V_121 = NULL ;
}
if ( V_117 -> V_47 ) {
F_89 ( ( unsigned long ) V_117 -> V_47 ) ;
V_117 -> V_47 = NULL ;
}
break;
default:
break;
}
return V_166 ;
}
static int F_115 ( struct V_167 * V_168 ,
struct V_169 * V_170 )
{
int V_63 = - 1 ;
int V_70 = V_170 -> V_171 ;
T_6 V_172 = V_170 -> V_172 ;
if ( V_70 >= 0 ) {
if ( ! ( V_172 & V_173 ) )
goto V_54;
F_48 ( V_70 ) ;
}
V_63 = ( int ) F_68 ( & V_33 ) ;
V_54:
return V_63 ;
}
static int F_116 ( int V_108 , int V_44 , struct V_45 * V_174 ,
T_2 V_46 , struct V_47 * V_47 )
{
struct V_68 * V_69 ;
int V_63 = - 1 ;
F_2 ( ! F_58 () ) ;
V_69 = F_45 ( V_108 , V_44 ) ;
if ( F_38 ( V_69 == NULL ) )
goto V_54;
if ( ! V_175 && F_81 ( V_69 ) == 0 ) {
V_63 = F_117 ( V_69 , V_174 , V_46 , ( char * ) ( V_47 ) ,
V_13 , 0 , F_100 ( V_69 ) ) ;
if ( V_63 < 0 ) {
if ( F_100 ( V_69 ) )
V_176 ++ ;
else
V_177 ++ ;
}
F_47 ( V_69 ) ;
F_85 () ;
} else {
V_178 ++ ;
if ( F_68 ( & V_69 -> V_179 ) > 0 )
( void ) F_46 ( V_69 , V_174 , V_46 ) ;
F_47 ( V_69 ) ;
}
V_54:
return V_63 ;
}
static int F_118 ( int V_108 , int V_44 , struct V_45 * V_174 ,
T_2 V_46 , struct V_47 * V_47 )
{
struct V_68 * V_69 ;
int V_63 = - 1 ;
unsigned long V_94 ;
T_3 V_8 = V_13 ;
F_63 ( V_94 ) ;
V_69 = F_45 ( V_108 , V_44 ) ;
if ( F_20 ( V_69 != NULL ) ) {
if ( F_68 ( & V_69 -> V_179 ) > 0 )
V_63 = F_119 ( V_69 , V_174 , V_46 , ( char * ) ( V_47 ) ,
& V_8 , 0 , F_100 ( V_69 ) ) ;
F_47 ( V_69 ) ;
}
F_65 ( V_94 ) ;
return V_63 ;
}
static int F_120 ( int V_108 , int V_44 ,
struct V_45 * V_174 , T_2 V_46 )
{
struct V_68 * V_69 ;
int V_63 = - 1 ;
unsigned long V_94 ;
F_63 ( V_94 ) ;
V_180 ++ ;
V_69 = F_45 ( V_108 , V_44 ) ;
if ( F_20 ( V_69 != NULL ) ) {
if ( F_68 ( & V_69 -> V_179 ) > 0 )
V_63 = F_46 ( V_69 , V_174 , V_46 ) ;
F_47 ( V_69 ) ;
}
if ( V_63 >= 0 )
V_181 ++ ;
F_65 ( V_94 ) ;
return V_63 ;
}
static int F_121 ( int V_108 , int V_44 ,
struct V_45 * V_174 )
{
struct V_68 * V_69 ;
int V_63 = - 1 ;
unsigned long V_94 ;
F_63 ( V_94 ) ;
V_182 ++ ;
V_69 = F_45 ( V_108 , V_44 ) ;
if ( F_20 ( V_69 != NULL ) ) {
if ( F_68 ( & V_69 -> V_179 ) > 0 )
V_63 = F_122 ( V_69 , V_174 ) ;
F_47 ( V_69 ) ;
}
if ( V_63 >= 0 )
V_183 ++ ;
F_65 ( V_94 ) ;
return V_63 ;
}
static int F_123 ( int V_108 , int V_44 )
{
struct V_68 * V_69 = NULL ;
struct V_1 * V_2 = NULL ;
int V_63 = - 1 ;
if ( V_44 < 0 )
goto V_54;
if ( V_108 == V_4 )
V_2 = & V_3 ;
else if ( ( unsigned int ) V_108 < V_110 )
V_2 = & V_5 [ V_108 ] ;
if ( V_2 == NULL )
goto V_54;
F_26 ( & V_2 -> V_111 ) ;
V_69 = V_2 -> V_113 [ V_44 ] ;
if ( V_69 == NULL )
goto V_54;
V_2 -> V_113 [ V_44 ] = NULL ;
while ( F_68 ( & V_69 -> V_111 ) != 0 )
;
F_32 ( & V_2 -> V_111 ) ;
F_124 () ;
V_63 = F_125 ( V_69 ) ;
F_53 () ;
F_114 ( V_69 ) ;
F_126 ( L_6 ,
V_44 , V_108 ) ;
V_54:
return V_63 ;
}
static int F_127 ( T_1 V_108 , T_2 V_94 )
{
int V_109 = - 1 ;
struct V_68 * V_69 ;
struct V_1 * V_2 = NULL ;
if ( V_108 == V_4 )
V_2 = & V_3 ;
else if ( ( unsigned int ) V_108 < V_110 )
V_2 = & V_5 [ V_108 ] ;
if ( V_2 == NULL )
goto V_54;
F_26 ( & V_2 -> V_111 ) ;
V_69 = F_128 ( sizeof( struct V_68 ) , V_184 ) ;
if ( V_69 == NULL ) {
F_126 ( L_7 ) ;
goto V_54;
}
for ( V_109 = 0 ; V_109 < V_112 ; V_109 ++ )
if ( V_2 -> V_113 [ V_109 ] == NULL )
break;
if ( V_109 >= V_112 ) {
F_126 ( L_8 ) ;
F_114 ( V_69 ) ;
V_109 = - 1 ;
goto V_54;
}
F_129 ( & V_69 -> V_111 , 0 ) ;
V_69 -> V_114 = V_2 ;
V_69 -> V_44 = V_109 ;
F_130 ( V_69 , V_94 ) ;
V_2 -> V_113 [ V_109 ] = V_69 ;
F_126 ( L_9 ,
V_94 & V_185 ? L_10 : L_11 ,
V_109 , V_108 ) ;
V_54:
if ( V_2 != NULL )
F_32 ( & V_2 -> V_111 ) ;
return V_109 ;
}
static void F_131 ( int V_44 ,
struct V_186 V_187 ,
T_7 V_46 , struct V_47 * V_47 )
{
T_8 V_188 = ( T_8 ) V_46 ;
struct V_45 V_32 = * (struct V_45 * ) & V_187 ;
if ( F_20 ( V_188 == V_46 ) )
( void ) F_116 ( V_4 , V_44 , & V_32 , V_46 , V_47 ) ;
}
static int F_132 ( int V_44 ,
struct V_186 V_187 ,
T_7 V_46 , struct V_47 * V_47 )
{
T_8 V_188 = ( T_8 ) V_46 ;
struct V_45 V_32 = * (struct V_45 * ) & V_187 ;
int V_63 = - 1 ;
if ( F_20 ( V_188 == V_46 ) )
V_63 = F_118 ( V_4 , V_44 , & V_32 , V_46 , V_47 ) ;
return V_63 ;
}
static void F_133 ( int V_44 ,
struct V_186 V_187 ,
T_7 V_46 )
{
T_8 V_188 = ( T_8 ) V_46 ;
struct V_45 V_32 = * (struct V_45 * ) & V_187 ;
if ( F_20 ( V_188 == V_46 ) )
( void ) F_120 ( V_4 , V_44 , & V_32 , V_188 ) ;
}
static void F_134 ( int V_44 ,
struct V_186 V_187 )
{
struct V_45 V_32 = * (struct V_45 * ) & V_187 ;
( void ) F_121 ( V_4 , V_44 , & V_32 ) ;
}
static void F_135 ( int V_44 )
{
if ( V_44 >= 0 )
( void ) F_123 ( V_4 , V_44 ) ;
}
static int F_136 ( T_3 V_189 )
{
F_2 ( sizeof( struct V_186 ) !=
sizeof( struct V_45 ) ) ;
F_2 ( V_189 != V_13 ) ;
return F_127 ( V_4 , 0 ) ;
}
static int F_137 ( char * V_190 , T_3 V_189 )
{
F_2 ( sizeof( struct V_186 ) !=
sizeof( struct V_45 ) ) ;
F_2 ( V_189 != V_13 ) ;
return F_127 ( V_4 , 0 ) ;
}
struct V_191 F_138 ( void )
{
struct V_191 V_192 =
F_139 ( & V_193 ) ;
return V_192 ;
}
static inline struct V_45 F_140 ( unsigned type , T_8 V_188 )
{
struct V_45 V_32 = { . V_32 = { 0 } } ;
V_32 . V_32 [ 0 ] = F_141 ( type , V_188 ) ;
return V_32 ;
}
static int F_142 ( unsigned type , T_7 V_12 ,
struct V_47 * V_47 )
{
T_5 V_194 = ( T_5 ) V_12 ;
T_8 V_188 = ( T_8 ) V_12 ;
struct V_45 V_32 = F_140 ( type , V_188 ) ;
int V_63 = - 1 ;
unsigned long V_94 ;
F_2 ( ! F_143 ( V_47 ) ) ;
if ( F_20 ( V_194 == V_188 ) ) {
F_63 ( V_94 ) ;
V_63 = F_116 ( V_4 , V_195 ,
& V_32 , F_144 ( V_188 ) , V_47 ) ;
F_65 ( V_94 ) ;
}
return V_63 ;
}
static int F_145 ( unsigned type , T_7 V_12 ,
struct V_47 * V_47 )
{
T_5 V_194 = ( T_5 ) V_12 ;
T_8 V_188 = ( T_8 ) V_12 ;
struct V_45 V_32 = F_140 ( type , V_188 ) ;
int V_63 = - 1 ;
F_2 ( ! F_143 ( V_47 ) ) ;
if ( F_20 ( V_194 == V_188 ) )
V_63 = F_118 ( V_4 , V_195 ,
& V_32 , F_144 ( V_188 ) , V_47 ) ;
return V_63 ;
}
static void F_146 ( unsigned type , T_7 V_12 )
{
T_5 V_194 = ( T_5 ) V_12 ;
T_8 V_188 = ( T_8 ) V_12 ;
struct V_45 V_32 = F_140 ( type , V_188 ) ;
if ( F_20 ( V_194 == V_188 ) )
( void ) F_120 ( V_4 , V_195 ,
& V_32 , F_144 ( V_188 ) ) ;
}
static void F_147 ( unsigned type )
{
struct V_45 V_32 ;
int V_188 ;
for ( V_188 = V_196 ; V_188 >= 0 ; V_188 -- ) {
V_32 = F_140 ( type , V_188 ) ;
( void ) F_121 ( V_4 ,
V_195 , & V_32 ) ;
}
}
static void F_148 ( unsigned V_197 )
{
if ( V_195 < 0 )
V_195 =
F_127 ( V_4 , V_185 ) ;
}
struct V_198 F_149 ( void )
{
struct V_198 V_192 =
F_150 ( & V_199 ) ;
return V_192 ;
}
static int T_9 F_151 ( char * V_200 )
{
V_201 = 1 ;
return 1 ;
}
static int T_9 F_152 ( char * V_200 )
{
V_202 = 0 ;
return 1 ;
}
static int T_9 F_153 ( char * V_200 )
{
V_203 = 0 ;
return 1 ;
}
static int T_9 F_154 ( void )
{
int V_63 = 0 ;
#ifdef F_155
V_63 = F_156 ( V_204 , & V_205 ) ;
if ( V_63 ) {
F_157 ( L_12 ) ;
goto V_54;
}
#endif
#if F_158 ( V_206 ) || F_158 ( F_79 )
if ( V_201 ) {
unsigned int V_158 ;
F_159 ( & V_207 ) ;
F_160 ( & V_208 ) ;
V_63 = F_161 ( & V_209 ) ;
if ( V_63 ) {
F_157 ( L_13 ) ;
goto V_54;
}
F_162 (cpu) {
void * V_157 = ( void * ) ( long ) V_158 ;
F_109 ( & V_209 ,
V_159 , V_157 ) ;
}
}
V_123 = F_163 ( L_14 ,
sizeof( struct V_118 ) , 0 , 0 , NULL ) ;
V_124 = F_163 ( L_15 ,
sizeof( struct V_120 ) , 0 , 0 , NULL ) ;
V_63 = F_78 ( V_4 ) ;
if ( V_63 ) {
F_157 ( L_16 ) ;
goto V_54;
}
#endif
#ifdef V_206
if ( V_201 && V_202 ) {
struct V_191 V_192 ;
F_54 () ;
F_164 ( & V_210 ) ;
V_192 = F_138 () ;
F_126 ( L_17
L_18 ) ;
if ( V_192 . V_211 != NULL )
F_165 ( L_19 ) ;
}
#endif
#ifdef F_79
if ( V_201 && V_203 ) {
struct V_198 V_192 ;
V_192 = F_149 () ;
F_126 ( L_20
L_21 ) ;
if ( V_192 . V_212 != NULL )
F_165 ( L_22 ) ;
}
#endif
V_54:
return V_63 ;
}
