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
static void F_13 ( char * V_24 , T_2 * V_8 , struct V_10 * V_11 )
{
struct V_14 * V_15 ;
char * V_20 ;
unsigned V_16 ;
F_10 ( V_11 , V_21 ) ;
V_16 = F_6 ( V_11 ) ;
V_15 = F_11 ( V_11 , struct V_14 , V_19 [ V_16 ] ) ;
F_14 ( & V_15 -> V_22 ) ;
F_2 ( V_11 -> V_8 > * V_8 ) ;
V_20 = ( char * ) V_15 ;
if ( V_16 == 0 )
V_20 += ( ( sizeof( struct V_14 ) + V_9 - 1 ) &
V_23 ) ;
else if ( V_16 == 1 )
V_20 += V_13 - ( ( V_11 -> V_8 + V_9 - 1 ) & V_23 ) ;
memcpy ( V_24 , V_20 , V_11 -> V_8 ) ;
* V_8 = V_11 -> V_8 ;
F_15 ( & V_15 -> V_22 ) ;
}
static struct V_14 * F_16 ( void )
{
struct V_14 * V_15 = NULL ;
struct V_10 * V_25 , * V_26 ;
V_15 = F_17 () ;
if ( F_18 ( V_15 != NULL ) ) {
F_19 ( & V_15 -> V_27 ) ;
V_25 = & V_15 -> V_19 [ 0 ] ; V_26 = & V_15 -> V_19 [ 1 ] ;
F_20 ( & V_15 -> V_22 ) ;
F_21 ( & V_28 ) ;
F_19 ( & V_15 -> V_27 ) ;
F_22 ( V_15 , V_29 ) ;
V_25 -> V_8 = 0 ; V_26 -> V_8 = 0 ;
F_23 ( & V_25 -> V_30 ) ;
F_23 ( & V_26 -> V_30 ) ;
}
return V_15 ;
}
static void F_24 ( struct V_14 * V_15 )
{
struct V_10 * V_25 = & V_15 -> V_19 [ 0 ] , * V_26 = & V_15 -> V_19 [ 1 ] ;
F_10 ( V_15 , V_29 ) ;
F_2 ( ! F_25 ( & V_15 -> V_27 ) ) ;
F_12 ( & V_15 -> V_22 ) ;
F_2 ( V_25 -> V_8 != 0 || F_26 ( & V_25 -> V_30 ) ) ;
F_2 ( V_26 -> V_8 != 0 || F_26 ( & V_26 -> V_30 ) ) ;
F_27 ( V_15 , V_29 ) ;
F_15 ( & V_15 -> V_22 ) ;
F_28 ( & V_28 ) ;
F_29 ( V_15 ) ;
}
static unsigned F_30 ( struct V_10 * V_11 )
{
unsigned V_8 ;
F_10 ( V_11 , V_21 ) ;
F_2 ( ! F_26 ( & V_11 -> V_30 ) ) ;
V_8 = V_11 -> V_8 ;
F_2 ( V_11 -> V_8 == 0 || V_11 -> V_8 > F_4 () ) ;
V_11 -> V_8 = 0 ;
F_23 ( & V_11 -> V_30 ) ;
F_27 ( V_11 , V_21 ) ;
V_31 -= V_8 ;
F_28 ( & V_32 ) ;
return V_8 ;
}
static void F_31 ( struct V_10 * V_11 )
{
unsigned V_33 ;
struct V_10 * V_34 ;
unsigned V_16 = F_6 ( V_11 ) , V_8 ;
struct V_14 * V_15 =
F_11 ( V_11 , struct V_14 , V_19 [ V_16 ] ) ;
F_32 ( ! F_33 () ) ;
F_14 ( & V_15 -> V_22 ) ;
if ( F_25 ( & V_15 -> V_27 ) ) {
F_15 ( & V_15 -> V_22 ) ;
return;
}
V_8 = F_30 ( V_11 ) ;
F_12 ( & V_15 -> V_22 ) ;
V_34 = & V_15 -> V_19 [ ( V_16 == 0 ) ? 1 : 0 ] ;
if ( V_34 -> V_8 == 0 ) {
V_33 = F_5 ( V_8 ) ;
F_14 ( & V_35 ) ;
F_2 ( F_25 ( & V_36 [ V_33 ] . V_37 ) ) ;
F_34 ( & V_15 -> V_27 ) ;
V_36 [ V_33 ] . V_38 -- ;
F_15 ( & V_35 ) ;
F_24 ( V_15 ) ;
} else {
V_33 = F_5 ( V_34 -> V_8 ) ;
F_14 ( & V_35 ) ;
F_34 ( & V_15 -> V_27 ) ;
V_39 -- ;
F_35 ( & V_15 -> V_27 , & V_36 [ V_33 ] . V_37 ) ;
V_36 [ V_33 ] . V_38 ++ ;
F_15 ( & V_35 ) ;
F_15 ( & V_15 -> V_22 ) ;
}
}
static struct V_10 * F_36 ( T_1 V_40 , T_1 V_41 ,
struct V_42 * V_30 ,
T_3 V_43 , struct V_44 * V_44 ,
void * V_45 , unsigned V_8 )
{
struct V_10 * V_25 , * V_26 , * V_11 = NULL ;
struct V_14 * V_15 = NULL , * V_46 ;
unsigned V_47 ;
char * V_48 ;
int V_17 , V_49 = 0 ;
V_47 = F_5 ( V_8 ) ;
for ( V_17 = V_6 - V_47 + 1 ; V_17 > 0 ; V_17 -- ) {
F_14 ( & V_35 ) ;
if ( ! F_25 ( & V_36 [ V_17 ] . V_37 ) ) {
F_37 (zbpg, ztmp,
&zbud_unbuddied[i].list, bud_list) {
if ( F_38 ( & V_15 -> V_22 ) ) {
V_49 = V_17 ;
goto V_50;
}
}
}
F_15 ( & V_35 ) ;
}
V_15 = F_16 () ;
if ( F_39 ( V_15 == NULL ) )
goto V_51;
F_14 ( & V_35 ) ;
F_14 ( & V_15 -> V_22 ) ;
F_35 ( & V_15 -> V_27 , & V_36 [ V_47 ] . V_37 ) ;
V_36 [ V_47 ] . V_38 ++ ;
V_11 = & V_15 -> V_19 [ 0 ] ;
goto V_52;
V_50:
F_12 ( & V_15 -> V_22 ) ;
V_25 = & V_15 -> V_19 [ 0 ] ; V_26 = & V_15 -> V_19 [ 1 ] ;
F_2 ( ! ( ( V_25 -> V_8 == 0 ) ^ ( V_26 -> V_8 == 0 ) ) ) ;
if ( V_25 -> V_8 != 0 ) {
F_10 ( V_25 , V_21 ) ;
V_11 = V_26 ;
} else if ( V_26 -> V_8 != 0 ) {
F_10 ( V_26 , V_21 ) ;
V_11 = V_25 ;
} else
F_40 () ;
F_34 ( & V_15 -> V_27 ) ;
V_36 [ V_49 ] . V_38 -- ;
F_35 ( & V_15 -> V_27 , & V_53 ) ;
V_39 ++ ;
V_52:
F_22 ( V_11 , V_21 ) ;
V_11 -> V_8 = V_8 ;
V_11 -> V_43 = V_43 ;
V_11 -> V_30 = * V_30 ;
V_11 -> V_41 = V_41 ;
V_11 -> V_40 = V_40 ;
V_48 = F_9 ( V_11 , V_8 ) ;
memcpy ( V_48 , V_45 , V_8 ) ;
F_15 ( & V_15 -> V_22 ) ;
F_15 ( & V_35 ) ;
V_54 [ V_47 ] ++ ;
F_21 ( & V_32 ) ;
V_55 ++ ;
V_31 += V_8 ;
V_56 += V_8 ;
V_51:
return V_11 ;
}
static int F_41 ( struct V_44 * V_44 , struct V_10 * V_11 )
{
struct V_14 * V_15 ;
unsigned V_16 = F_6 ( V_11 ) ;
T_2 V_57 = V_13 ;
char * V_58 , * V_59 ;
unsigned V_8 ;
int V_60 = 0 ;
V_15 = F_11 ( V_11 , struct V_14 , V_19 [ V_16 ] ) ;
F_14 ( & V_15 -> V_22 ) ;
if ( F_25 ( & V_15 -> V_27 ) ) {
V_60 = - V_61 ;
goto V_51;
}
F_10 ( V_11 , V_21 ) ;
F_2 ( V_11 -> V_8 == 0 || V_11 -> V_8 > F_4 () ) ;
V_58 = F_42 ( V_44 ) ;
V_8 = V_11 -> V_8 ;
V_59 = F_9 ( V_11 , V_8 ) ;
V_60 = F_43 ( V_59 , V_8 , V_58 , & V_57 ) ;
F_2 ( V_60 != V_62 ) ;
F_2 ( V_57 != V_13 ) ;
F_44 ( V_58 ) ;
V_51:
F_15 ( & V_15 -> V_22 ) ;
return V_60 ;
}
static void F_45 ( struct V_14 * V_15 )
{
struct V_10 * V_11 ;
int V_17 , V_63 ;
T_3 V_41 [ V_18 ] , V_40 [ V_18 ] ;
T_3 V_43 [ V_18 ] ;
struct V_42 V_30 [ V_18 ] ;
struct V_64 * V_65 ;
unsigned long V_66 ;
F_12 ( & V_15 -> V_22 ) ;
for ( V_17 = 0 , V_63 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_11 = & V_15 -> V_19 [ V_17 ] ;
if ( V_11 -> V_8 ) {
V_40 [ V_63 ] = V_11 -> V_40 ;
V_41 [ V_63 ] = V_11 -> V_41 ;
V_30 [ V_63 ] = V_11 -> V_30 ;
V_43 [ V_63 ] = V_11 -> V_43 ;
V_63 ++ ;
}
}
F_15 ( & V_15 -> V_22 ) ;
for ( V_17 = 0 ; V_17 < V_63 ; V_17 ++ ) {
V_65 = F_46 ( V_40 [ V_17 ] , V_41 [ V_17 ] ) ;
F_2 ( V_65 == NULL ) ;
F_47 ( V_66 ) ;
F_48 ( V_65 , & V_30 [ V_17 ] , V_43 [ V_17 ] ) ;
F_49 ( V_66 ) ;
F_50 ( V_65 ) ;
}
}
static void F_51 ( int V_67 )
{
struct V_14 * V_15 ;
int V_17 , V_68 = 0 ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
V_69:
F_52 ( & V_35 ) ;
if ( F_25 ( & V_36 [ V_17 ] . V_37 ) ) {
F_53 ( & V_35 ) ;
continue;
}
F_54 (zbpg, &zbud_unbuddied[i].list, bud_list) {
if ( F_39 ( ! F_38 ( & V_15 -> V_22 ) ) )
continue;
V_36 [ V_17 ] . V_38 -- ;
F_15 ( & V_35 ) ;
V_70 ++ ;
F_45 ( V_15 ) ;
V_68 ++ ;
F_55 () ;
if ( -- V_67 <= 0 )
goto V_71;
goto V_69;
}
F_53 ( & V_35 ) ;
}
V_72:
F_52 ( & V_35 ) ;
if ( F_25 ( & V_53 ) ) {
F_53 ( & V_35 ) ;
goto V_71;
}
F_54 (zbpg, &zbud_buddied_list, bud_list) {
if ( F_39 ( ! F_38 ( & V_15 -> V_22 ) ) )
continue;
V_39 -- ;
F_15 ( & V_35 ) ;
V_73 ++ ;
F_45 ( V_15 ) ;
V_68 ++ ;
F_55 () ;
if ( -- V_67 <= 0 )
goto V_71;
goto V_72;
}
F_53 ( & V_35 ) ;
V_71:
return;
}
static int F_56 ( struct V_74 * V_75 , char * V_24 ,
T_2 V_8 )
{
struct V_64 * V_65 ;
int V_17 , V_76 , V_60 = - 1 ;
unsigned char V_77 , * V_20 ;
unsigned long V_66 ;
for ( V_20 = V_24 , V_77 = 0 , V_17 = 0 ; V_17 < V_8 ; V_17 ++ )
V_77 += * V_20 ;
V_60 = F_57 ( V_75 , V_24 , V_8 , true , & V_76 ) ;
if ( V_60 == 0 ) {
V_65 = F_46 ( V_4 , V_75 -> V_41 ) ;
F_2 ( V_65 == NULL ) ;
F_47 ( V_66 ) ;
( void ) F_58 ( V_65 , & V_75 -> V_30 , V_75 -> V_43 ,
F_59 ( V_76 , V_8 , V_77 ) ) ;
F_49 ( V_66 ) ;
F_50 ( V_65 ) ;
V_78 ++ ;
V_60 = 0 ;
} else
V_79 ++ ;
return V_60 ;
}
static int F_60 ( struct V_14 * V_15 )
{
struct V_10 * V_26 , * V_80 = NULL ;
struct V_74 V_81 , V_82 = { 0 } ;
char * V_83 = NULL , * V_84 = NULL ;
T_2 V_85 = 0 , V_86 = 0 ;
int V_60 = 0 ;
unsigned char * V_87 = F_61 ( V_88 ) ;
F_12 ( & V_15 -> V_22 ) ;
if ( V_15 -> V_19 [ 0 ] . V_8 == 0 )
V_26 = & V_15 -> V_19 [ 1 ] ;
else if ( V_15 -> V_19 [ 1 ] . V_8 == 0 )
V_26 = & V_15 -> V_19 [ 0 ] ;
else {
V_26 = & V_15 -> V_19 [ 0 ] ;
V_80 = & V_15 -> V_19 [ 1 ] ;
}
if ( V_26 -> V_40 != V_4 )
V_26 = NULL ;
if ( ( V_80 != NULL ) && ( V_80 -> V_40 != V_4 ) )
V_80 = NULL ;
if ( V_26 != NULL ) {
V_81 . V_40 = V_26 -> V_40 ;
V_81 . V_41 = V_26 -> V_41 ;
V_81 . V_30 = V_26 -> V_30 ;
V_81 . V_43 = V_26 -> V_43 ;
V_85 = V_26 -> V_8 ;
V_83 = F_9 ( V_26 , V_85 ) ;
memcpy ( V_87 , F_9 ( V_26 , V_85 ) , V_85 ) ;
V_83 = V_87 ;
V_87 += V_85 ;
}
if ( V_80 != NULL ) {
V_82 . V_40 = V_80 -> V_40 ;
V_82 . V_41 = V_80 -> V_41 ;
V_82 . V_30 = V_80 -> V_30 ;
V_82 . V_43 = V_80 -> V_43 ;
V_86 = V_80 -> V_8 ;
memcpy ( V_87 , F_9 ( V_80 , V_86 ) , V_86 ) ;
V_84 = V_87 ;
}
F_15 ( & V_15 -> V_22 ) ;
F_62 () ;
if ( V_26 != NULL )
V_60 = F_56 ( & V_81 , V_83 , V_85 ) ;
if ( V_80 != NULL )
V_60 |= F_56 ( & V_82 , V_84 , V_86 ) ;
return V_60 ;
}
void F_63 ( int V_67 )
{
struct V_14 * V_15 ;
int V_17 , V_60 ;
for ( V_17 = 0 ; V_17 < V_6 ; V_17 ++ ) {
V_69:
F_64 () ;
F_52 ( & V_35 ) ;
if ( F_25 ( & V_36 [ V_17 ] . V_37 ) ) {
F_53 ( & V_35 ) ;
F_62 () ;
continue;
}
F_54 (zbpg, &zbud_unbuddied[i].list, bud_list) {
if ( F_39 ( ! F_38 ( & V_15 -> V_22 ) ) )
continue;
V_36 [ V_17 ] . V_38 -- ;
F_53 ( & V_35 ) ;
V_60 = F_60 ( V_15 ) ;
if ( V_60 == 0 ) {
if ( -- V_67 <= 0 )
goto V_51;
goto V_69;
}
F_65 ( L_1
L_2 ) ;
F_52 ( & V_35 ) ;
F_14 ( & V_15 -> V_22 ) ;
F_35 ( & V_15 -> V_27 , & V_36 [ V_17 ] . V_37 ) ;
V_36 [ V_17 ] . V_38 ++ ;
F_15 ( & V_15 -> V_22 ) ;
F_53 ( & V_35 ) ;
F_65 ( L_1
L_3 ) ;
goto V_51;
}
F_53 ( & V_35 ) ;
F_62 () ;
}
V_89:
F_64 () ;
F_52 ( & V_35 ) ;
if ( F_25 ( & V_53 ) )
goto V_90;
F_54 (zbpg, &zbud_buddied_list, bud_list) {
if ( F_39 ( ! F_38 ( & V_15 -> V_22 ) ) )
continue;
V_39 -- ;
F_53 ( & V_35 ) ;
V_60 = F_60 ( V_15 ) ;
if ( V_60 == 0 ) {
if ( -- V_67 <= 0 )
goto V_51;
goto V_89;
}
F_65 ( L_4
L_2 ) ;
F_52 ( & V_35 ) ;
F_14 ( & V_15 -> V_22 ) ;
F_35 ( & V_15 -> V_27 , & V_53 ) ;
V_39 ++ ;
F_15 ( & V_15 -> V_22 ) ;
F_53 ( & V_35 ) ;
F_65 ( L_4
L_3 ) ;
goto V_51;
}
V_90:
F_53 ( & V_35 ) ;
F_62 () ;
V_51:
return;
}
static void F_66 ( struct V_91 * V_92 )
{
struct V_74 * V_75 ;
int V_76 , V_60 ;
F_64 () ;
V_75 = & V_92 -> V_75 ;
V_76 = V_92 -> V_75 . V_40 ;
V_60 = F_67 ( V_75 , V_76 ) ;
if ( V_60 >= 0 )
V_93 ++ ;
else
V_94 ++ ;
F_68 () ;
F_69 ( V_92 , NULL ) ;
}
static void F_70 ( struct V_91 * V_92 )
{
struct V_74 * V_75 ;
int V_76 , V_60 ;
F_64 () ;
V_75 = & V_92 -> V_75 ;
V_76 = V_92 -> V_75 . V_40 ;
V_60 = F_71 ( V_75 , V_76 ) ;
if ( V_60 >= 0 )
V_95 ++ ;
else
V_96 ++ ;
F_68 () ;
F_69 ( V_92 , NULL ) ;
}
static void F_72 ( struct V_10 * V_97 )
{
}
static void F_73 ( struct V_98 * V_99 )
{
struct V_74 V_75 ;
T_1 V_8 ;
bool V_100 ;
int V_76 , V_60 = - 1 ;
char * V_24 ;
struct V_64 * V_65 ;
unsigned long V_66 ;
unsigned char V_77 ;
char * V_20 ;
int V_17 ;
unsigned char * V_87 = F_61 ( V_88 ) ;
F_10 ( V_99 , V_101 ) ;
F_2 ( V_99 -> V_40 != V_4 ) ;
F_74 () ;
V_75 . V_40 = V_99 -> V_40 ;
V_75 . V_41 = V_99 -> V_41 ;
V_75 . V_30 = V_99 -> V_30 ;
V_75 . V_43 = V_99 -> V_43 ;
V_8 = F_75 ( V_99 ) - sizeof( * V_99 ) ;
F_2 ( V_8 == 0 || V_8 > V_102 ) ;
V_24 = ( char * ) V_99 + sizeof( * V_99 ) ;
for ( V_20 = V_24 , V_77 = 0 , V_17 = 0 ; V_17 < V_8 ; V_17 ++ )
V_77 += * V_20 ;
memcpy ( V_87 , V_24 , V_8 ) ;
V_24 = V_87 ;
V_65 = F_46 ( V_99 -> V_40 , V_99 -> V_41 ) ;
V_100 = F_76 ( V_65 ) ;
F_50 ( V_65 ) ;
F_15 ( & V_103 ) ;
F_55 () ;
F_64 () ;
V_60 = F_57 ( & V_75 , V_24 , V_8 , V_100 , & V_76 ) ;
F_68 () ;
if ( V_60 != 0 ) {
V_104 ++ ;
goto V_51;
} else
F_21 ( & V_105 ) ;
V_106 ++ ;
F_74 () ;
V_65 = F_46 ( V_4 , V_75 . V_41 ) ;
F_47 ( V_66 ) ;
( void ) F_58 ( V_65 , & V_75 . V_30 , V_75 . V_43 ,
F_59 ( V_76 , V_8 , V_77 ) ) ;
F_49 ( V_66 ) ;
F_50 ( V_65 ) ;
F_55 () ;
V_51:
return;
}
static void F_77 ( int V_67 )
{
struct V_107 * V_108 ;
union V_109 * V_110 ;
while ( 1 ) {
if ( ! V_67 )
goto V_51;
F_14 ( & V_103 ) ;
if ( F_25 ( & V_111 ) ) {
F_15 ( & V_103 ) ;
goto V_51;
}
V_108 = F_78 ( & V_111 ,
struct V_107 , V_37 ) ;
F_34 ( & V_108 -> V_37 ) ;
if ( V_108 -> V_112 != V_113 )
F_15 ( & V_103 ) ;
V_110 = (union V_109 * ) V_108 ;
switch ( V_108 -> V_112 ) {
case V_114 :
F_40 () ;
F_72 ( (struct V_10 * ) V_108 ) ;
break;
case V_113 :
F_73 ( (struct V_98 * ) V_108 ) ;
break;
case V_115 :
F_66 ( (struct V_91 * ) V_110 ) ;
break;
case V_116 :
F_70 ( (struct V_91 * ) V_110 ) ;
break;
default:
F_40 () ;
}
}
V_51:
return;
}
static void F_79 ( unsigned long V_117 )
{
if ( ! F_80 ( V_118 ,
& V_119 , V_117 ) )
F_65 ( L_5 ) ;
}
static void F_81 ( struct V_120 * V_121 )
{
static bool V_122 ;
F_2 ( F_33 () ) ;
if ( V_122 )
F_79 ( V_123 ) ;
else if ( V_124 != - 1 ) {
V_122 = true ;
#ifdef F_82
if ( V_125 && V_126 )
F_63 ( 5000 ) ;
#endif
#ifdef F_83
if ( V_127 && V_128 )
F_77 ( 500 ) ;
#endif
V_122 = false ;
F_79 ( V_123 ) ;
}
}
static void F_84 ( void )
{
unsigned long V_129 = 60UL ;
V_118 =
F_85 ( L_6 ) ;
F_79 ( V_129 * V_123 ) ;
}
static void F_86 ( void )
{
int V_17 ;
F_19 ( & V_53 ) ;
V_39 = 0 ;
for ( V_17 = 0 ; V_17 < V_130 ; V_17 ++ ) {
F_19 ( & V_36 [ V_17 ] . V_37 ) ;
V_36 [ V_17 ] . V_38 = 0 ;
}
}
static int F_87 ( char * V_131 )
{
int V_17 ;
char * V_20 = V_131 ;
for ( V_17 = 0 ; V_17 < V_130 ; V_17 ++ )
V_20 += sprintf ( V_20 , L_7 , V_36 [ V_17 ] . V_38 ) ;
return V_20 - V_131 ;
}
static int F_88 ( char * V_131 )
{
unsigned long V_17 , V_33 = 0 , V_132 = 0 , V_133 = 0 ;
unsigned long V_134 = 0 , V_135 = 0 ;
unsigned long V_136 = 0 ;
char * V_20 = V_131 ;
for ( V_17 = 0 ; V_17 < V_130 ; V_17 ++ ) {
V_20 += sprintf ( V_20 , L_8 , V_54 [ V_17 ] ) ;
V_33 += V_54 [ V_17 ] ;
V_132 += V_54 [ V_17 ] ;
V_133 += V_17 * V_54 [ V_17 ] ;
if ( V_17 == 21 )
V_134 = V_132 ;
if ( V_17 == 32 )
V_135 = V_132 ;
if ( V_17 == 42 )
V_136 = V_132 ;
}
V_20 += sprintf ( V_20 , L_9 ,
V_134 , V_135 , V_136 ,
V_33 == 0 ? 0 : V_133 / V_33 ) ;
return V_20 - V_131 ;
}
static struct V_98 * F_89 ( struct V_1 * V_2 , T_3 V_41 ,
struct V_42 * V_30 , T_3 V_43 ,
void * V_45 , unsigned V_137 )
{
struct V_44 * V_44 ;
struct V_98 * V_99 = NULL ;
T_3 V_12 ;
int V_138 = V_137 + sizeof( struct V_98 ) ;
int V_33 = ( V_138 + ( V_9 - 1 ) ) >> V_7 ;
int V_60 ;
F_2 ( ! F_33 () ) ;
F_2 ( V_33 >= V_130 ) ;
V_60 = F_90 ( V_2 -> V_139 , V_137 + sizeof( struct V_98 ) ,
& V_44 , & V_12 , V_140 ) ;
if ( F_39 ( V_60 ) )
goto V_51;
F_21 ( & V_141 [ V_33 ] ) ;
F_21 ( & V_142 [ V_33 ] ) ;
V_99 = F_42 ( V_44 ) + V_12 ;
V_99 -> V_43 = V_43 ;
V_99 -> V_30 = * V_30 ;
V_99 -> V_41 = V_41 ;
F_22 ( V_99 , V_101 ) ;
F_19 ( & V_99 -> V_108 . V_37 ) ;
V_99 -> V_40 = F_1 ( V_2 ) ;
V_99 -> V_108 . V_112 = V_113 ;
if ( V_99 -> V_40 == V_4 ) {
F_14 ( & V_103 ) ;
F_35 ( & V_99 -> V_108 . V_37 , & V_111 ) ;
F_15 ( & V_103 ) ;
}
memcpy ( ( char * ) V_99 + sizeof( struct V_98 ) , V_45 , V_137 ) ;
F_44 ( V_99 ) ;
V_51:
return V_99 ;
}
static struct V_98 * F_91 ( struct V_64 * V_65 ,
struct V_42 * V_30 , T_3 V_43 ,
unsigned V_137 )
{
struct V_1 * V_2 = V_65 -> V_143 ;
struct V_44 * V_44 ;
struct V_98 * V_99 = NULL ;
T_3 V_12 ;
int V_60 ;
F_2 ( ! F_33 () ) ;
F_2 ( ! F_3 ( V_65 -> V_143 ) ) ;
V_60 = F_90 ( V_2 -> V_139 , V_137 + sizeof( struct V_98 ) ,
& V_44 , & V_12 , V_140 ) ;
if ( F_39 ( V_60 ) )
goto V_51;
V_99 = F_42 ( V_44 ) + V_12 ;
F_22 ( V_99 , V_101 ) ;
F_19 ( & V_99 -> V_108 . V_37 ) ;
V_99 -> V_40 = V_4 ;
V_99 -> V_108 . V_112 = V_144 ;
V_99 -> V_43 = V_43 ;
V_99 -> V_30 = * V_30 ;
V_99 -> V_41 = V_65 -> V_41 ;
F_44 ( V_99 ) ;
V_51:
return V_99 ;
}
static void F_92 ( struct V_145 * V_139 , struct V_98 * V_99 )
{
unsigned long V_66 ;
struct V_44 * V_44 ;
T_3 V_12 ;
T_1 V_8 = F_75 ( V_99 ) ;
int V_33 = ( V_8 + ( V_9 - 1 ) ) >> V_7 ;
F_10 ( V_99 , V_101 ) ;
F_2 ( V_33 >= V_130 ) ;
F_28 ( & V_141 [ V_33 ] ) ;
V_8 -= sizeof( * V_99 ) ;
F_14 ( & V_103 ) ;
V_8 = F_75 ( V_99 ) - sizeof( * V_99 ) ;
F_2 ( V_8 == 0 ) ;
F_27 ( V_99 , V_101 ) ;
if ( ! F_25 ( & V_99 -> V_108 . V_37 ) )
F_34 ( & V_99 -> V_108 . V_37 ) ;
F_15 ( & V_103 ) ;
V_44 = F_93 ( V_99 ) ;
V_12 = ( unsigned long ) V_99 & ~ V_146 ;
F_47 ( V_66 ) ;
F_94 ( V_139 , V_44 , V_12 ) ;
F_49 ( V_66 ) ;
}
static void F_95 ( struct V_44 * V_44 , struct V_98 * V_99 )
{
T_2 V_137 = V_13 ;
char * V_58 ;
unsigned V_8 ;
int V_60 ;
F_10 ( V_99 , V_101 ) ;
V_8 = F_75 ( V_99 ) - sizeof( * V_99 ) ;
F_2 ( V_8 == 0 ) ;
V_58 = F_42 ( V_44 ) ;
V_60 = F_43 ( ( char * ) V_99 + sizeof( * V_99 ) ,
V_8 , V_58 , & V_137 ) ;
F_44 ( V_58 ) ;
F_2 ( V_60 != V_62 ) ;
F_2 ( V_137 != V_13 ) ;
}
static void F_96 ( char * V_24 , T_2 * V_147 , struct V_98 * V_99 )
{
unsigned V_8 ;
F_10 ( V_99 , V_101 ) ;
V_8 = F_75 ( V_99 ) - sizeof( * V_99 ) ;
F_2 ( V_8 == 0 || V_8 > V_102 ) ;
F_2 ( V_8 > * V_147 ) ;
memcpy ( V_24 , ( char * ) V_99 + sizeof( * V_99 ) , V_8 ) ;
* V_147 = V_8 ;
}
static void F_97 ( struct V_98 * V_99 , char * V_24 , T_2 V_8 )
{
unsigned V_148 ;
F_10 ( V_99 , V_101 ) ;
V_148 = F_75 ( V_99 ) - sizeof( * V_99 ) ;
F_2 ( V_148 != V_8 ) ;
F_2 ( V_148 == 0 || V_148 > V_102 ) ;
memcpy ( ( char * ) V_99 + sizeof( * V_99 ) , V_24 , V_8 ) ;
}
static int F_98 ( char * V_131 )
{
unsigned long V_17 , V_129 , V_33 = 0 , V_133 = 0 ;
char * V_20 = V_131 ;
for ( V_17 = 0 ; V_17 < V_130 ; V_17 ++ ) {
V_129 = F_99 ( & V_141 [ V_17 ] ) ;
V_20 += sprintf ( V_20 , L_8 , V_129 ) ;
V_33 += V_129 ;
V_133 += V_17 * V_129 ;
}
V_20 += sprintf ( V_20 , L_10 ,
V_33 == 0 ? 0 : V_133 / V_33 ) ;
return V_20 - V_131 ;
}
static int F_100 ( char * V_131 )
{
unsigned long V_17 , V_129 , V_33 = 0 , V_133 = 0 ;
char * V_20 = V_131 ;
for ( V_17 = 0 ; V_17 < V_130 ; V_17 ++ ) {
V_129 = F_99 ( & V_142 [ V_17 ] ) ;
V_20 += sprintf ( V_20 , L_8 , V_129 ) ;
V_33 += V_129 ;
V_133 += V_17 * V_129 ;
}
V_20 += sprintf ( V_20 , L_10 ,
V_33 == 0 ? 0 : V_133 / V_33 ) ;
return V_20 - V_131 ;
}
static T_4 F_101 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
char * V_131 )
{
return sprintf ( V_131 , L_11 , V_153 ) ;
}
static T_4 F_102 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
const char * V_131 , T_2 V_38 )
{
unsigned long V_154 ;
int V_155 ;
if ( ! F_103 ( V_156 ) )
return - V_157 ;
V_155 = F_104 ( V_131 , 10 , & V_154 ) ;
if ( V_155 || ( V_154 == 0 ) || ( V_154 > ( V_13 / 8 ) * 7 ) )
return - V_61 ;
V_153 = V_154 ;
return V_38 ;
}
static T_4 F_105 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
char * V_131 )
{
return sprintf ( V_131 , L_11 , V_158 ) ;
}
static T_4 F_106 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
const char * V_131 , T_2 V_38 )
{
unsigned long V_154 ;
int V_155 ;
if ( ! F_103 ( V_156 ) )
return - V_157 ;
V_155 = F_104 ( V_131 , 10 , & V_154 ) ;
if ( V_155 || ( V_154 == 0 ) || ( V_154 > ( V_13 / 8 ) * 7 ) )
return - V_61 ;
V_158 = V_154 ;
return V_38 ;
}
static T_4 F_107 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
char * V_131 )
{
return sprintf ( V_131 , L_11 , V_159 ) ;
}
static T_4 F_108 ( struct V_149 * V_150 ,
struct V_151 * V_152 ,
const char * V_131 , T_2 V_38 )
{
unsigned long V_154 ;
int V_155 ;
if ( ! F_103 ( V_156 ) )
return - V_157 ;
V_155 = F_104 ( V_131 , 10 , & V_154 ) ;
if ( V_155 || ( V_154 == 0 ) || ( V_154 > 150 ) )
return - V_61 ;
V_159 = V_154 ;
return V_38 ;
}
static struct V_64 * F_46 ( T_1 V_160 , T_1 V_161 )
{
struct V_64 * V_65 = NULL ;
struct V_1 * V_2 = NULL ;
if ( V_160 == V_4 )
V_2 = & V_3 ;
else {
if ( V_160 >= V_162 )
goto V_51;
V_2 = & V_5 [ V_160 ] ;
if ( V_2 == NULL )
goto V_51;
F_21 ( & V_2 -> V_163 ) ;
}
if ( V_161 < V_164 ) {
V_65 = V_2 -> V_165 [ V_161 ] ;
if ( V_65 != NULL )
F_21 ( & V_65 -> V_163 ) ;
}
V_51:
return V_65 ;
}
static void F_50 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = NULL ;
if ( V_65 == NULL )
F_40 () ;
V_2 = V_65 -> V_143 ;
F_28 ( & V_65 -> V_163 ) ;
F_28 ( & V_2 -> V_163 ) ;
}
int F_109 ( T_1 V_160 )
{
struct V_1 * V_2 = NULL ;
int V_60 = - 1 ;
if ( V_160 == V_4 )
V_2 = & V_3 ;
else if ( ( unsigned int ) V_160 < V_162 )
V_2 = & V_5 [ V_160 ] ;
if ( V_2 == NULL )
goto V_51;
if ( V_2 -> V_166 )
goto V_51;
V_2 -> V_166 = 1 ;
#ifdef F_83
V_2 -> V_139 = F_110 () ;
if ( V_2 -> V_139 == NULL )
goto V_51;
#endif
V_60 = 0 ;
V_51:
return V_60 ;
}
static int F_111 ( struct V_64 * V_65 )
{
struct V_167 * V_168 ;
struct V_169 * V_170 ;
struct V_171 * V_172 ;
struct V_91 * V_92 ;
void * V_44 ;
int V_60 = - V_173 ;
if ( F_39 ( V_174 == NULL ) )
goto V_51;
if ( F_39 ( V_175 == NULL ) )
goto V_51;
F_64 () ;
V_168 = & F_61 ( V_176 ) ;
while ( V_168 -> V_67 < F_112 ( V_168 -> V_177 ) ) {
F_68 () ;
V_170 = F_113 ( V_174 ,
V_140 ) ;
if ( F_39 ( V_170 == NULL ) ) {
V_178 ++ ;
goto V_51;
}
F_64 () ;
V_168 = & F_61 ( V_176 ) ;
if ( V_168 -> V_67 < F_112 ( V_168 -> V_177 ) )
V_168 -> V_177 [ V_168 -> V_67 ++ ] = V_170 ;
else
F_114 ( V_174 , V_170 ) ;
}
F_68 () ;
V_172 = F_113 ( V_175 , V_140 ) ;
if ( F_39 ( V_172 == NULL ) ) {
V_178 ++ ;
goto V_51;
}
V_92 = F_113 ( V_179 , V_140 ) ;
if ( F_39 ( V_92 == NULL ) ) {
V_178 ++ ;
goto V_51;
}
if ( F_76 ( V_65 ) ) {
V_44 = ( void * ) F_115 ( V_140 ) ;
if ( F_39 ( V_44 == NULL ) ) {
V_180 ++ ;
F_114 ( V_175 , V_172 ) ;
F_114 ( V_179 , V_92 ) ;
goto V_51;
}
}
F_64 () ;
V_168 = & F_61 ( V_176 ) ;
if ( V_168 -> V_172 == NULL )
V_168 -> V_172 = V_172 ;
else
F_114 ( V_175 , V_172 ) ;
if ( V_168 -> V_92 == NULL )
V_168 -> V_92 = V_92 ;
else
F_114 ( V_179 , V_92 ) ;
if ( F_76 ( V_65 ) ) {
if ( V_168 -> V_44 == NULL )
V_168 -> V_44 = V_44 ;
else
F_116 ( ( unsigned long ) V_44 ) ;
}
V_60 = 0 ;
V_51:
return V_60 ;
}
static int F_117 ( struct V_64 * V_65 )
{
struct V_167 * V_168 ;
struct V_91 * V_92 ;
int V_60 = - V_173 ;
F_2 ( ! F_33 () ) ;
if ( F_39 ( V_179 == NULL ) )
F_40 () ;
V_168 = & F_61 ( V_176 ) ;
V_92 = F_113 ( V_179 , V_181 ) ;
if ( F_39 ( V_92 == NULL ) && V_168 -> V_92 == NULL )
F_40 () ;
else if ( V_168 -> V_92 == NULL )
V_168 -> V_92 = V_92 ;
else
F_114 ( V_179 , V_92 ) ;
return V_60 ;
}
static void * F_17 ( void )
{
struct V_167 * V_168 ;
void * V_44 ;
V_168 = & F_61 ( V_176 ) ;
V_44 = V_168 -> V_44 ;
F_2 ( V_44 == NULL ) ;
V_168 -> V_44 = NULL ;
return V_44 ;
}
static void F_29 ( void * V_20 )
{
F_116 ( ( unsigned long ) V_20 ) ;
}
static struct V_169 * F_118 ( struct V_64 * V_65 )
{
struct V_169 * V_170 = NULL ;
unsigned long V_38 ;
struct V_167 * V_168 ;
V_168 = & F_61 ( V_176 ) ;
if ( V_168 -> V_67 <= 0 )
goto V_51;
V_170 = V_168 -> V_177 [ V_168 -> V_67 - 1 ] ;
F_2 ( V_170 == NULL ) ;
V_168 -> V_177 [ V_168 -> V_67 - 1 ] = NULL ;
V_168 -> V_67 -- ;
V_38 = F_119 ( & V_182 ) ;
if ( V_38 > V_183 )
V_183 = V_38 ;
V_51:
return V_170 ;
}
static void F_120 ( struct V_169 * V_170 ,
struct V_64 * V_65 )
{
F_28 ( & V_182 ) ;
F_2 ( F_99 ( & V_182 ) < 0 ) ;
F_114 ( V_174 , V_170 ) ;
}
static struct V_171 * F_121 ( struct V_64 * V_65 )
{
struct V_171 * V_172 = NULL ;
unsigned long V_38 ;
struct V_167 * V_168 ;
V_168 = & F_61 ( V_176 ) ;
V_172 = V_168 -> V_172 ;
F_2 ( V_172 == NULL ) ;
V_168 -> V_172 = NULL ;
V_38 = F_119 ( & V_184 ) ;
if ( V_38 > V_185 )
V_185 = V_38 ;
return V_172 ;
}
static void F_122 ( struct V_171 * V_172 , struct V_64 * V_65 )
{
F_28 ( & V_184 ) ;
F_2 ( F_99 ( & V_184 ) < 0 ) ;
F_114 ( V_175 , V_172 ) ;
}
static struct V_91 * F_123 ( struct V_64 * V_65 )
{
struct V_91 * V_92 = NULL ;
struct V_167 * V_168 ;
int V_38 ;
V_168 = & F_61 ( V_176 ) ;
V_92 = V_168 -> V_92 ;
F_2 ( V_92 == NULL ) ;
V_168 -> V_92 = NULL ;
V_38 = F_119 ( & V_186 ) ;
if ( V_38 > V_187 )
V_187 = V_38 ;
return V_92 ;
}
static void F_69 ( struct V_91 * V_92 ,
struct V_64 * V_65 )
{
F_28 ( & V_186 ) ;
F_2 ( F_99 ( & V_186 ) < 0 ) ;
F_114 ( V_179 , V_92 ) ;
}
static inline void F_124 ( T_5 * V_188 )
{
F_28 ( V_188 ) ;
F_125 ( F_99 ( V_188 ) < 0 ) ;
}
static int F_126 ( char * V_24 , T_2 V_8 , bool V_189 ,
struct V_64 * V_65 , struct V_42 * V_30 ,
T_3 V_43 , void * * V_190 )
{
int V_60 = - 1 ;
void * V_45 = V_24 ;
T_2 V_137 = V_8 ;
struct V_1 * V_2 = V_65 -> V_143 ;
T_1 V_40 = F_1 ( V_2 ) ;
struct V_44 * V_44 = NULL ;
unsigned long V_38 ;
if ( ! V_189 ) {
V_44 = F_93 ( V_24 ) ;
V_60 = F_127 ( V_44 , & V_45 , & V_137 ) ;
if ( V_60 == 0 )
goto V_51;
if ( V_137 == 0 || V_137 > F_4 () ) {
V_191 ++ ;
goto V_51;
}
}
* V_190 = ( void * ) F_36 ( V_40 , V_65 -> V_41 , V_30 ,
V_43 , V_44 , V_45 , V_137 ) ;
if ( * V_190 == NULL ) {
V_60 = - V_173 ;
goto V_51;
}
V_60 = 0 ;
V_38 = F_119 ( & V_192 ) ;
if ( V_38 > V_193 )
V_193 = V_38 ;
if ( V_40 != V_4 ) {
V_38 = F_119 ( & V_194 ) ;
if ( V_38 > V_195 )
V_195 = V_38 ;
}
V_51:
return V_60 ;
}
static int F_128 ( char * V_24 , T_2 V_8 , bool V_189 ,
struct V_64 * V_65 , struct V_42 * V_30 ,
T_3 V_43 , void * * V_190 )
{
int V_60 = - 1 ;
void * V_45 = V_24 ;
T_2 V_137 = V_8 ;
struct V_1 * V_2 = V_65 -> V_143 ;
struct V_44 * V_44 ;
unsigned long V_38 ;
unsigned long V_196 ;
struct V_98 * V_99 ;
long V_197 ;
T_6 V_198 ;
#ifdef F_129
static bool V_199 ;
#endif
V_197 = F_99 ( & V_200 ) -
F_99 ( & V_105 ) ;
#ifdef F_129
if ( ! V_199 ) {
F_130 ( L_12 ) ;
V_199 = true ;
}
#endif
if ( V_197 >
( V_159 * V_201 ) / 100 ) {
V_202 ++ ;
goto V_51;
}
if ( V_189 )
goto V_203;
V_44 = F_93 ( V_24 ) ;
if ( F_127 ( V_44 , & V_45 , & V_137 ) == 0 )
goto V_51;
if ( V_137 > V_153 ) {
V_191 ++ ;
goto V_51;
}
if ( ( V_137 > V_158 ) && ( V_197 > 0 ) ) {
V_198 = F_131 ( V_2 -> V_139 ) ;
V_196 = F_132 ( V_198 , V_197 ) ;
if ( V_196 > V_158 ) {
V_204 ++ ;
goto V_51;
}
}
V_203:
* V_190 = ( void * ) F_89 ( V_2 , V_65 -> V_41 , V_30 , V_43 , V_45 , V_137 ) ;
if ( * V_190 == NULL ) {
V_60 = - V_173 ;
goto V_51;
}
V_60 = 0 ;
V_38 = F_119 ( & V_200 ) ;
if ( V_38 > V_205 )
V_205 = V_38 ;
if ( F_3 ( V_2 ) )
goto V_51;
V_99 = * (struct V_98 * * ) V_190 ;
V_38 = F_119 ( & V_206 ) ;
if ( V_38 > V_207 )
V_207 = V_38 ;
V_51:
return V_60 ;
}
static void * F_133 ( char * V_24 , T_2 V_8 , bool V_189 , int V_208 ,
struct V_64 * V_65 , struct V_42 * V_30 ,
T_3 V_43 )
{
void * V_190 = NULL ;
int V_60 ;
bool V_100 ;
F_2 ( F_134 () ) ;
V_100 = ( V_208 == 1 ) || ( ( V_208 == 0 ) && F_76 ( V_65 ) ) ;
if ( V_100 )
V_60 = F_126 ( V_24 , V_8 , V_189 , V_65 ,
V_30 , V_43 , & V_190 ) ;
else
V_60 = F_128 ( V_24 , V_8 , V_189 , V_65 ,
V_30 , V_43 , & V_190 ) ;
return V_190 ;
}
static int F_135 ( char * V_24 , T_2 * V_147 , bool V_189 ,
void * V_190 , struct V_64 * V_65 ,
struct V_42 * V_30 , T_3 V_43 )
{
int V_60 = 0 ;
F_2 ( F_134 () ) ;
F_2 ( F_76 ( V_65 ) ) ;
F_2 ( F_136 ( V_190 ) ) ;
if ( V_189 )
F_96 ( V_24 , V_147 , V_190 ) ;
else
F_95 ( F_93 ( V_24 ) , V_190 ) ;
return V_60 ;
}
static int F_137 ( char * V_24 , T_2 * V_147 , bool V_189 ,
void * V_190 , struct V_64 * V_65 ,
struct V_42 * V_30 , T_3 V_43 )
{
int V_60 = 0 ;
unsigned long V_66 ;
struct V_1 * V_2 = V_65 -> V_143 ;
F_2 ( F_134 () ) ;
F_2 ( F_136 ( V_190 ) ) ;
if ( F_76 ( V_65 ) ) {
F_47 ( V_66 ) ;
if ( V_189 )
F_13 ( V_24 , V_147 , V_190 ) ;
else
V_60 = F_41 ( F_93 ( V_24 ) , V_190 ) ;
F_31 ( (struct V_10 * ) V_190 ) ;
F_49 ( V_66 ) ;
if ( ! F_3 ( V_2 ) )
F_124 ( & V_194 ) ;
F_124 ( & V_192 ) ;
} else {
if ( F_3 ( V_2 ) )
F_40 () ;
if ( V_189 )
F_96 ( V_24 , V_147 , V_190 ) ;
else
F_95 ( F_93 ( V_24 ) , V_190 ) ;
F_92 ( V_2 -> V_139 , V_190 ) ;
if ( ! F_3 ( V_2 ) )
F_124 ( & V_206 ) ;
F_124 ( & V_200 ) ;
V_60 = 0 ;
}
return V_60 ;
}
static bool F_138 ( void * V_190 )
{
return F_136 ( V_190 ) ;
}
static void F_139 ( void * V_190 , struct V_64 * V_65 ,
struct V_42 * V_30 , T_3 V_43 , bool V_209 )
{
struct V_1 * V_2 = V_65 -> V_143 ;
bool V_208 = F_76 ( V_65 ) ;
struct V_98 * V_99 ;
F_2 ( F_134 () ) ;
if ( F_136 ( V_190 ) ) {
F_32 ( V_209 == false ) ;
if ( V_30 == NULL ) {
} else if ( V_208 ) {
F_124 ( & V_192 ) ;
} else if ( F_140 ( V_190 ) ) {
V_190 = F_141 ( V_190 ) ;
goto V_210;
} else {
struct V_91 * V_92 =
F_123 ( V_65 ) ;
V_92 -> V_75 . V_40 = F_142 ( V_190 ) ;
V_92 -> V_75 . V_41 = V_65 -> V_41 ;
V_92 -> V_75 . V_30 = * V_30 ;
V_92 -> V_75 . V_43 = V_43 ;
V_92 -> V_108 . V_112 = V_115 ;
F_14 ( & V_103 ) ;
F_143 ( & V_92 -> V_108 . V_37 , & V_111 ) ;
F_15 ( & V_103 ) ;
F_124 ( & V_200 ) ;
F_124 ( & V_105 ) ;
}
} else if ( V_208 ) {
F_31 ( (struct V_10 * ) V_190 ) ;
if ( ! F_3 ( V_65 -> V_143 ) )
F_124 ( & V_194 ) ;
if ( V_209 )
F_124 ( & V_192 ) ;
} else {
V_210:
V_99 = (struct V_98 * ) V_190 ;
if ( ! F_3 ( V_65 -> V_143 ) )
F_124 ( & V_206 ) ;
F_92 ( V_2 -> V_139 , V_99 ) ;
if ( V_209 )
F_124 ( & V_200 ) ;
}
}
static void F_144 ( struct V_64 * V_65 ,
struct V_171 * V_172 )
{
struct V_91 * V_92 ;
F_2 ( F_134 () ) ;
if ( V_172 -> V_211 == NULL )
return;
F_2 ( ! F_136 ( V_172 -> V_211 ) ) ;
V_92 = F_123 ( V_65 ) ;
V_92 -> V_75 . V_40 = F_142 ( V_172 -> V_211 ) ;
V_92 -> V_75 . V_41 = V_65 -> V_41 ;
V_92 -> V_75 . V_30 = V_172 -> V_30 ;
V_92 -> V_75 . V_43 = V_212 ;
V_92 -> V_108 . V_112 = V_116 ;
F_14 ( & V_103 ) ;
F_143 ( & V_92 -> V_108 . V_37 , & V_111 ) ;
F_15 ( & V_103 ) ;
}
void F_145 ( struct V_171 * V_172 )
{
V_172 -> V_211 = NULL ;
}
int F_146 ( void * V_213 , struct V_171 * V_172 )
{
int V_60 = - 1 ;
if ( V_213 != NULL ) {
if ( V_172 -> V_211 == NULL )
V_172 -> V_211 = V_213 ;
else if ( F_142 ( V_213 ) !=
F_142 ( ( void * ) ( V_172 -> V_211 ) ) )
F_40 () ;
V_60 = 0 ;
}
return V_60 ;
}
int F_147 ( int V_41 , struct V_42 * V_214 ,
T_3 V_43 , char * V_24 , T_2 V_8 ,
void * V_211 )
{
int V_60 = - V_215 ;
unsigned long V_66 ;
struct V_64 * V_65 ;
bool V_100 , V_216 = false ;
T_2 V_137 = V_13 ;
void * V_190 , * V_217 ;
struct V_171 * V_172 ;
V_65 = F_46 ( V_4 , V_41 ) ;
if ( F_39 ( V_65 == NULL ) )
goto V_51;
V_100 = F_76 ( V_65 ) ;
F_47 ( V_66 ) ;
V_190 = F_148 ( V_65 , V_214 , V_43 , & V_172 , & V_217 ) ;
if ( V_190 == NULL ) {
#ifdef F_129
F_65 ( L_13 ) ;
#endif
if ( V_100 )
V_218 ++ ;
else
V_219 ++ ;
V_172 = NULL ;
goto V_220;
} else if ( F_39 ( ! F_136 ( V_190 ) ) ) {
#ifdef F_129
F_65 ( L_14 ) ;
#endif
if ( V_100 )
V_218 ++ ;
else
V_219 ++ ;
V_172 = NULL ;
V_190 = NULL ;
V_60 = - V_221 ;
goto V_220;
} else if ( V_8 == 0 ) {
V_190 = NULL ;
if ( V_100 )
V_218 ++ ;
else
F_40 () ;
V_216 = true ;
goto V_220;
}
if ( ! V_100 && F_140 ( V_190 ) ) {
V_190 = F_141 ( V_190 ) ;
F_97 ( V_190 , V_24 , V_8 ) ;
} else {
V_190 = NULL ;
V_172 = NULL ;
}
if ( V_211 != NULL ) {
V_60 = F_43 ( ( char * ) V_24 , V_8 ,
( char * ) V_211 , & V_137 ) ;
F_2 ( V_60 != V_62 ) ;
F_2 ( V_137 != V_13 ) ;
}
if ( V_100 )
V_222 ++ ;
else
V_223 ++ ;
V_60 = 0 ;
V_220:
F_149 ( V_172 , V_43 , V_190 , V_217 , V_216 ) ;
F_50 ( V_65 ) ;
F_49 ( V_66 ) ;
V_51:
return V_60 ;
}
static void * F_150 ( void * V_190 ,
struct V_64 * V_65 ,
struct V_42 * V_30 ,
T_3 V_43 ,
bool * V_224 )
{
int V_137 = F_151 ( V_190 ) ;
void * V_225 = NULL ;
unsigned long V_66 ;
if ( ! F_136 ( V_190 ) )
F_40 () ;
if ( F_76 ( V_65 ) )
F_40 () ;
if ( F_140 ( V_190 ) ) {
* V_224 = true ;
goto V_51;
}
* V_224 = false ;
F_47 ( V_66 ) ;
V_225 = ( void * ) F_91 ( V_65 , V_30 , V_43 , V_137 ) ;
if ( V_225 != NULL ) {
V_225 = F_152 ( V_225 ) ;
F_124 ( & V_105 ) ;
} else
V_226 ++ ;
F_49 ( V_66 ) ;
V_51:
return V_225 ;
}
static int F_153 ( void * V_227 , void * V_228 ,
struct V_64 * V_65 ,
struct V_42 * V_30 , T_3 V_43 ,
bool free , void * V_211 )
{
struct V_74 V_75 ;
int V_60 ;
if ( F_140 ( V_228 ) )
free = true ;
V_75 = F_154 ( V_4 , V_65 , V_30 , V_43 ) ;
V_60 = F_155 ( & V_75 , free ,
F_142 ( V_227 ) ,
F_151 ( V_227 ) ,
F_156 ( V_227 ) ,
V_211 ) ;
#ifdef F_129
if ( V_60 != 0 && V_60 != - V_215 )
F_65 ( L_15 ,
V_60 ) ;
#endif
return V_60 ;
}
static int F_127 ( struct V_44 * V_229 , void * * V_230 , T_2 * V_57 )
{
int V_60 = 0 ;
unsigned char * V_231 = F_61 ( V_232 ) ;
unsigned char * V_233 = F_61 ( V_234 ) ;
char * V_59 ;
F_2 ( ! F_33 () ) ;
if ( F_39 ( V_231 == NULL || V_233 == NULL ) )
goto V_51;
V_59 = F_42 ( V_229 ) ;
F_157 () ;
V_60 = F_158 ( V_59 , V_13 , V_231 , V_57 , V_233 ) ;
F_2 ( V_60 != V_62 ) ;
* V_230 = V_231 ;
F_44 ( V_59 ) ;
V_60 = 1 ;
V_51:
return V_60 ;
}
static int F_159 ( struct V_235 * V_236 ,
unsigned long V_237 , void * V_238 )
{
int V_239 = ( long ) V_238 ;
struct V_167 * V_168 ;
switch ( V_237 ) {
case V_240 :
F_160 ( V_232 , V_239 ) = ( void * ) F_161 (
V_241 | V_242 ,
V_243 ) ,
F_160 ( V_234 , V_239 ) =
F_162 ( V_244 ,
V_241 | V_242 ) ;
F_160 ( V_88 , V_239 ) =
F_162 ( V_13 , V_241 | V_242 ) ;
break;
case V_245 :
case V_246 :
F_163 ( F_160 ( V_88 , V_239 ) ) ;
F_160 ( V_88 , V_239 ) = NULL ;
F_164 ( ( unsigned long ) F_160 ( V_232 , V_239 ) ,
V_243 ) ;
F_160 ( V_232 , V_239 ) = NULL ;
F_163 ( F_160 ( V_234 , V_239 ) ) ;
F_160 ( V_234 , V_239 ) = NULL ;
V_168 = & F_160 ( V_176 , V_239 ) ;
while ( V_168 -> V_67 ) {
F_114 ( V_174 ,
V_168 -> V_177 [ V_168 -> V_67 - 1 ] ) ;
V_168 -> V_177 [ V_168 -> V_67 - 1 ] = NULL ;
V_168 -> V_67 -- ;
}
if ( V_168 -> V_172 ) {
F_114 ( V_175 , V_168 -> V_172 ) ;
V_168 -> V_172 = NULL ;
}
if ( V_168 -> V_92 ) {
F_114 ( V_179 , V_168 -> V_92 ) ;
V_168 -> V_92 = NULL ;
}
if ( V_168 -> V_44 ) {
F_116 ( ( unsigned long ) V_168 -> V_44 ) ;
V_168 -> V_44 = NULL ;
}
break;
default:
break;
}
return V_247 ;
}
static T_4 F_165 ( struct V_149 * V_150 ,
struct V_151 * V_152 , char * V_131 )
{
int V_17 ;
char * V_20 = V_131 ;
for ( V_17 = 0 ; V_17 < V_248 ; V_17 ++ )
if ( V_249 [ V_17 ] )
V_20 += sprintf ( V_20 , L_16 , V_17 ) ;
V_20 += sprintf ( V_20 , L_17 ) ;
return V_20 - V_131 ;
}
static T_4 F_166 ( struct V_149 * V_150 ,
struct V_151 * V_152 , const char * V_131 , T_2 V_38 )
{
int V_155 ;
unsigned long V_250 ;
V_155 = F_104 ( V_131 , 10 , & V_250 ) ;
if ( V_155 ) {
F_65 ( L_18 ) ;
return - V_61 ;
}
if ( V_250 >= V_248 ) {
F_65 ( L_19 , V_250 ) ;
return - V_61 ;
}
if ( V_249 [ V_250 ] ) {
F_65 ( L_20 ,
( int ) V_250 ) ;
} else {
V_249 [ V_250 ] = true ;
F_167 ( ( int ) V_250 ) ;
}
return V_38 ;
}
static T_4 F_168 ( struct V_149 * V_150 ,
struct V_151 * V_152 , char * V_131 )
{
if ( V_124 == - 1UL )
return sprintf ( V_131 , L_21 ) ;
else
return sprintf ( V_131 , L_22 , V_124 ) ;
}
static T_4 F_169 ( struct V_149 * V_150 ,
struct V_151 * V_152 , const char * V_131 , T_2 V_38 )
{
int V_155 ;
unsigned long V_250 ;
V_155 = F_104 ( V_131 , 10 , & V_250 ) ;
if ( V_155 ) {
F_65 ( L_18 ) ;
return - V_61 ;
} else if ( V_250 == - 1UL ) {
F_65 ( L_23
L_24 ) ;
return - V_61 ;
} else if ( V_250 >= V_248 ) {
F_65 ( L_19 , V_250 ) ;
return - V_61 ;
} else if ( ! V_249 [ V_250 ] ) {
F_65 ( L_25
L_26 , ( int ) V_250 ) ;
} else if ( F_170 ( ( int ) V_250 ) >= 0 ) {
F_171 ( L_27 ,
( int ) V_250 ) ;
V_124 = ( int ) V_250 ;
} else {
F_65 ( L_28 ,
( int ) V_250 ) ;
return - V_61 ;
}
return V_38 ;
}
static int F_172 ( struct V_251 * V_252 ,
struct V_253 * V_254 )
{
int V_60 = - 1 ;
int V_67 = V_254 -> V_255 ;
T_7 V_256 = V_254 -> V_256 ;
if ( V_67 >= 0 ) {
if ( ! ( V_256 & V_257 ) )
goto V_51;
F_51 ( V_67 ) ;
}
V_60 = ( int ) F_99 ( & V_28 ) ;
V_51:
return V_60 ;
}
int F_173 ( int V_160 , int V_41 , struct V_42 * V_214 ,
T_3 V_43 , char * V_24 , T_2 V_8 ,
bool V_189 , int V_100 )
{
struct V_64 * V_65 ;
int V_60 = - 1 ;
F_2 ( ! F_33 () ) ;
V_65 = F_46 ( V_160 , V_41 ) ;
if ( F_39 ( V_65 == NULL ) )
goto V_51;
if ( ! V_258 && F_111 ( V_65 ) == 0 ) {
V_60 = F_174 ( V_65 , V_214 , V_43 , V_24 , V_8 , V_189 , V_100 ) ;
if ( V_60 < 0 ) {
if ( F_76 ( V_65 ) )
V_259 ++ ;
else
V_260 ++ ;
}
F_50 ( V_65 ) ;
F_68 () ;
} else {
V_261 ++ ;
if ( F_99 ( & V_65 -> V_262 ) > 0 )
( void ) F_48 ( V_65 , V_214 , V_43 ) ;
F_50 ( V_65 ) ;
}
V_51:
return V_60 ;
}
int F_175 ( int V_160 , int V_41 , struct V_42 * V_214 ,
T_3 V_43 , char * V_24 , T_2 * V_263 ,
bool V_189 , int V_264 )
{
struct V_64 * V_65 ;
int V_60 = - 1 ;
bool V_208 ;
if ( ! V_189 ) {
F_2 ( F_33 () ) ;
F_2 ( F_176 () ) ;
}
V_65 = F_46 ( V_160 , V_41 ) ;
V_208 = F_76 ( V_65 ) ;
if ( F_18 ( V_65 != NULL ) ) {
if ( F_99 ( & V_65 -> V_262 ) > 0 )
V_60 = F_177 ( V_65 , V_214 , V_43 , V_24 , V_263 ,
V_189 , V_264 ) ;
F_50 ( V_65 ) ;
}
F_178 ( ( ! V_208 && ( V_60 != 0 ) ) , L_29
L_30 ) ;
#ifdef F_129
if ( V_60 != 0 && V_60 != - 1 && ! ( V_60 == - V_61 && F_76 ( V_65 ) ) )
F_65 ( L_31 , V_60 ) ;
#endif
if ( V_60 == - V_265 )
F_40 () ;
return V_60 ;
}
int F_179 ( int V_160 , int V_41 ,
struct V_42 * V_214 , T_3 V_43 )
{
struct V_64 * V_65 ;
int V_60 = - 1 ;
unsigned long V_66 ;
F_47 ( V_66 ) ;
V_266 ++ ;
V_65 = F_46 ( V_160 , V_41 ) ;
F_117 ( V_65 ) ;
if ( F_18 ( V_65 != NULL ) ) {
if ( F_99 ( & V_65 -> V_262 ) > 0 )
V_60 = F_48 ( V_65 , V_214 , V_43 ) ;
F_50 ( V_65 ) ;
}
if ( V_60 >= 0 )
V_267 ++ ;
F_49 ( V_66 ) ;
return V_60 ;
}
int F_180 ( int V_160 , int V_41 , struct V_42 * V_214 )
{
struct V_64 * V_65 ;
int V_60 = - 1 ;
unsigned long V_66 ;
F_47 ( V_66 ) ;
V_268 ++ ;
V_65 = F_46 ( V_160 , V_41 ) ;
F_117 ( V_65 ) ;
if ( F_18 ( V_65 != NULL ) ) {
if ( F_99 ( & V_65 -> V_262 ) > 0 )
V_60 = F_181 ( V_65 , V_214 ) ;
F_50 ( V_65 ) ;
}
if ( V_60 >= 0 )
V_269 ++ ;
F_49 ( V_66 ) ;
return V_60 ;
}
int F_182 ( int V_160 , int V_41 )
{
struct V_64 * V_65 = NULL ;
struct V_1 * V_2 = NULL ;
int V_60 = - 1 ;
if ( V_41 < 0 )
goto V_51;
if ( V_160 == V_4 )
V_2 = & V_3 ;
else if ( ( unsigned int ) V_160 < V_162 )
V_2 = & V_5 [ V_160 ] ;
if ( V_2 == NULL )
goto V_51;
F_21 ( & V_2 -> V_163 ) ;
V_65 = V_2 -> V_165 [ V_41 ] ;
if ( V_65 == NULL )
goto V_51;
V_2 -> V_165 [ V_41 ] = NULL ;
while ( F_99 ( & V_65 -> V_163 ) != 0 )
;
F_28 ( & V_2 -> V_163 ) ;
F_74 () ;
V_60 = F_183 ( V_65 ) ;
F_55 () ;
F_163 ( V_65 ) ;
F_171 ( L_32 , V_41 , V_160 ) ;
V_51:
return V_60 ;
}
static int F_184 ( int V_41 )
{
return F_182 ( V_4 , V_41 ) ;
}
int F_185 ( T_1 V_160 , T_3 V_66 )
{
int V_161 = - 1 ;
struct V_64 * V_65 ;
struct V_1 * V_2 = NULL ;
if ( V_160 == V_4 )
V_2 = & V_3 ;
else if ( ( unsigned int ) V_160 < V_162 )
V_2 = & V_5 [ V_160 ] ;
if ( V_2 == NULL )
goto V_51;
F_21 ( & V_2 -> V_163 ) ;
V_65 = F_186 ( sizeof( struct V_64 ) , V_181 ) ;
if ( V_65 == NULL ) {
F_171 ( L_33 ) ;
goto V_51;
}
for ( V_161 = 0 ; V_161 < V_164 ; V_161 ++ )
if ( V_2 -> V_165 [ V_161 ] == NULL )
break;
if ( V_161 >= V_164 ) {
F_171 ( L_34 ) ;
F_163 ( V_65 ) ;
V_161 = - 1 ;
goto V_51;
}
F_187 ( & V_65 -> V_163 , 0 ) ;
V_65 -> V_143 = V_2 ;
V_65 -> V_41 = V_161 ;
F_188 ( V_65 , V_66 ) ;
V_2 -> V_165 [ V_161 ] = V_65 ;
if ( V_160 == V_4 )
F_171 ( L_35 ,
V_66 & V_270 ? L_36 : L_37 ,
V_161 ) ;
else
F_171 ( L_38 ,
V_66 & V_270 ? L_36 : L_37 ,
V_161 , V_160 ) ;
V_51:
if ( V_2 != NULL )
F_28 ( & V_2 -> V_163 ) ;
return V_161 ;
}
static int F_189 ( T_3 V_66 )
{
return F_185 ( V_4 , V_66 ) ;
}
int F_190 ( int V_160 , int V_41 , bool V_100 )
{
struct V_64 * V_65 ;
struct V_1 * V_2 = NULL ;
T_3 V_66 = V_100 ? 0 : V_270 ;
int V_60 = - 1 ;
if ( V_160 == V_4 )
goto V_51;
if ( V_41 >= V_164 )
goto V_51;
else if ( ( unsigned int ) V_160 < V_162 )
V_2 = & V_5 [ V_160 ] ;
if ( ( V_100 && ! V_125 ) || ( ! V_100 && ! V_127 ) )
F_40 () ;
if ( ! V_2 -> V_166 ) {
if ( F_109 ( V_160 ) )
F_40 () ;
V_2 = & V_5 [ V_160 ] ;
}
F_21 ( & V_2 -> V_163 ) ;
V_65 = V_2 -> V_165 [ V_41 ] ;
if ( V_65 != NULL ) {
if ( V_65 -> V_271 && V_100 ) {
F_65 ( L_39 ) ;
goto V_51;
}
V_60 = 0 ;
goto V_51;
}
V_65 = F_186 ( sizeof( struct V_64 ) , V_241 ) ;
if ( V_65 == NULL ) {
F_171 ( L_33 ) ;
goto V_51;
}
F_187 ( & V_65 -> V_163 , 0 ) ;
V_65 -> V_143 = V_2 ;
V_65 -> V_41 = V_41 ;
F_188 ( V_65 , V_66 ) ;
V_2 -> V_165 [ V_41 ] = V_65 ;
F_171 ( L_40 ,
V_66 & V_270 ? L_36 : L_37 ,
V_41 , V_160 ) ;
V_60 = 0 ;
V_51:
if ( V_2 == NULL )
F_40 () ;
if ( V_2 != NULL )
F_28 ( & V_2 -> V_163 ) ;
return V_60 ;
}
static void F_191 ( int V_41 ,
struct V_272 V_273 ,
T_8 V_43 , struct V_44 * V_44 )
{
T_9 V_274 = ( T_9 ) V_43 ;
struct V_42 V_30 = * (struct V_42 * ) & V_273 ;
#ifdef F_192
if ( ! F_193 ( V_44 ) ) {
V_275 ++ ;
return;
}
#endif
if ( F_18 ( V_274 == V_43 ) ) {
char * V_276 = F_194 ( V_44 ) ;
( void ) F_173 ( V_4 , V_41 , & V_30 , V_43 ,
V_276 , V_13 , 0 , 1 ) ;
}
}
static int F_195 ( int V_41 ,
struct V_272 V_273 ,
T_8 V_43 , struct V_44 * V_44 )
{
T_9 V_274 = ( T_9 ) V_43 ;
struct V_42 V_30 = * (struct V_42 * ) & V_273 ;
int V_60 = - 1 ;
F_64 () ;
if ( F_18 ( V_274 == V_43 ) ) {
char * V_276 = F_194 ( V_44 ) ;
T_2 V_8 = V_13 ;
V_60 = F_175 ( V_4 , V_41 , & V_30 , V_43 ,
V_276 , & V_8 , 0 , 0 ) ;
#ifdef F_192
if ( V_60 == 0 )
F_196 ( V_44 ) ;
#endif
}
F_62 () ;
return V_60 ;
}
static void F_197 ( int V_41 ,
struct V_272 V_273 ,
T_8 V_43 )
{
T_9 V_274 = ( T_9 ) V_43 ;
struct V_42 V_30 = * (struct V_42 * ) & V_273 ;
if ( F_18 ( V_274 == V_43 ) )
( void ) F_179 ( V_4 , V_41 , & V_30 , V_274 ) ;
}
static void F_198 ( int V_41 ,
struct V_272 V_273 )
{
struct V_42 V_30 = * (struct V_42 * ) & V_273 ;
( void ) F_180 ( V_4 , V_41 , & V_30 ) ;
}
static void F_199 ( int V_41 )
{
if ( V_41 >= 0 )
( void ) F_184 ( V_41 ) ;
}
static int F_200 ( T_2 V_277 )
{
F_2 ( sizeof( struct V_272 ) !=
sizeof( struct V_42 ) ) ;
F_2 ( V_277 != V_13 ) ;
return F_189 ( 0 ) ;
}
static int F_201 ( char * V_278 , T_2 V_277 )
{
F_2 ( sizeof( struct V_272 ) !=
sizeof( struct V_42 ) ) ;
F_2 ( V_277 != V_13 ) ;
return F_189 ( 0 ) ;
}
struct V_279 F_202 ( void )
{
struct V_279 V_280 =
F_203 ( & V_281 ) ;
return V_280 ;
}
static inline struct V_42 F_204 ( unsigned type , T_9 V_274 )
{
struct V_42 V_30 = { . V_30 = { 0 } } ;
V_30 . V_30 [ 0 ] = F_205 ( type , V_274 ) ;
return V_30 ;
}
static int F_206 ( unsigned type , T_8 V_12 ,
struct V_44 * V_44 )
{
T_6 V_282 = ( T_6 ) V_12 ;
T_9 V_274 = ( T_9 ) V_12 ;
struct V_42 V_30 = F_204 ( type , V_274 ) ;
int V_60 = - 1 ;
unsigned long V_66 ;
char * V_276 ;
F_2 ( ! F_207 ( V_44 ) ) ;
if ( F_18 ( V_282 == V_274 ) ) {
F_47 ( V_66 ) ;
V_276 = F_194 ( V_44 ) ;
V_60 = F_173 ( V_4 , V_283 ,
& V_30 , F_208 ( V_274 ) , V_276 , V_13 , 0 , 0 ) ;
F_49 ( V_66 ) ;
}
return V_60 ;
}
static int F_209 ( unsigned type , T_8 V_12 ,
struct V_44 * V_44 )
{
T_6 V_282 = ( T_6 ) V_12 ;
T_9 V_274 = ( T_9 ) V_12 ;
struct V_42 V_30 = F_204 ( type , V_274 ) ;
int V_60 = - 1 ;
F_64 () ;
F_2 ( ! F_207 ( V_44 ) ) ;
if ( F_18 ( V_282 == V_274 ) ) {
char * V_276 = F_194 ( V_44 ) ;
T_2 V_8 = V_13 ;
V_60 = F_175 ( V_4 , V_283 ,
& V_30 , F_208 ( V_274 ) , V_276 , & V_8 , 0 , - 1 ) ;
}
F_62 () ;
return V_60 ;
}
static void F_210 ( unsigned type , T_8 V_12 )
{
T_6 V_282 = ( T_6 ) V_12 ;
T_9 V_274 = ( T_9 ) V_12 ;
struct V_42 V_30 = F_204 ( type , V_274 ) ;
if ( F_18 ( V_282 == V_274 ) )
( void ) F_179 ( V_4 , V_283 ,
& V_30 , F_208 ( V_274 ) ) ;
}
static void F_211 ( unsigned type )
{
struct V_42 V_30 ;
int V_274 ;
for ( V_274 = V_284 ; V_274 >= 0 ; V_274 -- ) {
V_30 = F_204 ( type , V_274 ) ;
( void ) F_180 ( V_4 ,
V_283 , & V_30 ) ;
}
}
static void F_212 ( unsigned V_285 )
{
if ( V_283 < 0 )
V_283 =
F_189 ( V_270 ) ;
}
struct V_286 F_213 ( void )
{
struct V_286 V_280 =
F_214 ( & V_287 ) ;
return V_280 ;
}
static void F_215 ( void )
{
static unsigned long V_288 ;
static unsigned long V_289 ;
static unsigned long V_290 ;
V_289 = V_288 ;
V_288 = F_216 () ;
if ( ! V_288 ||
( V_288 > V_289 ) ) {
V_291 = V_292 ;
return;
}
if ( V_291 && -- V_291 )
return;
if ( V_288 <= V_293 )
V_290 = 0 ;
else
V_290 = V_288 -
( V_288 / V_293 ) ;
F_217 ( V_290 ) ;
}
static int T_10 F_218 ( char * V_294 )
{
V_295 = false ;
return 1 ;
}
static void F_219 ( struct V_120 * V_121 )
{
if ( V_296 && V_297 ) {
F_215 () ;
F_220 ( & V_298 ,
V_299 * V_123 ) ;
}
}
static int T_10 F_221 ( void )
{
V_296 = V_300 && V_295 ;
if ( V_296 )
F_171 ( L_41
L_42 ) ;
else
return - V_301 ;
F_220 ( & V_298 , V_299 * V_123 ) ;
return 0 ;
}
static int T_10 F_222 ( char * V_294 )
{
V_300 = 1 ;
return 1 ;
}
static int T_10 F_223 ( char * V_294 )
{
F_171 ( L_43 ) ;
V_125 = 0 ;
return 1 ;
}
static int T_10 F_224 ( char * V_294 )
{
F_171 ( L_44 ) ;
V_127 = 0 ;
return 1 ;
}
static int T_10 F_225 ( void )
{
int V_60 = 0 ;
#ifdef F_226
V_60 = F_227 ( V_302 , & V_303 ) ;
V_60 = F_227 ( V_302 , & V_304 ) ;
if ( V_60 ) {
F_65 ( L_45 ) ;
goto V_51;
}
#endif
#if F_228 ( F_82 ) || F_228 ( F_83 )
if ( V_300 ) {
unsigned int V_239 ;
( void ) F_229 () ;
F_230 ( & V_305 ) ;
F_231 ( & V_306 ) ;
V_60 = F_232 ( & V_307 ) ;
if ( V_60 ) {
F_65 ( L_46 ) ;
goto V_51;
}
F_233 (cpu) {
void * V_238 = ( void * ) ( long ) V_239 ;
F_159 ( & V_307 ,
V_240 , V_238 ) ;
}
}
V_174 = F_234 ( L_47 ,
sizeof( struct V_169 ) , 0 , 0 , NULL ) ;
V_175 = F_234 ( L_48 ,
sizeof( struct V_171 ) , 0 , 0 , NULL ) ;
V_179 = F_234 ( L_49 ,
sizeof( struct V_91 ) , 0 , 0 , NULL ) ;
#endif
#ifdef F_82
F_171 ( L_50 ,
V_300 , V_125 ) ;
if ( V_300 && V_125 ) {
struct V_279 V_280 ;
F_86 () ;
F_235 ( & V_308 ) ;
V_280 = F_202 () ;
F_171 ( L_51
L_52 ) ;
if ( V_280 . V_309 != NULL )
F_236 ( L_53 ) ;
}
#endif
#ifdef F_83
F_171 ( L_54 ,
V_300 , V_127 ) ;
if ( V_300 && V_127 ) {
struct V_286 V_280 ;
F_109 ( V_4 ) ;
V_280 = F_213 () ;
F_171 ( L_55
L_56 ) ;
if ( V_280 . V_310 != NULL )
F_236 ( L_57 ) ;
}
if ( V_300 && ( V_127 || V_125 ) )
F_84 () ;
#endif
V_51:
return V_60 ;
}
