static struct V_1 * F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_4 , struct V_1 , V_3 ) ;
}
static struct V_1 * F_3 ( struct V_1 * V_2 )
{
return F_2 ( V_2 -> V_3 . V_5 , struct V_1 , V_3 ) ;
}
static T_1 F_4 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
if ( F_5 ( & V_2 -> V_3 , & V_7 -> V_8 ) )
return ( V_9 * ) V_7 -> V_2 +
V_7 -> V_10 - ( V_9 * ) V_2 -> V_11 ;
return ( V_9 * ) F_1 ( V_2 ) -> V_11 - ( V_9 * ) V_2 -> V_11 ;
}
static void F_6 ( struct V_6 * V_7 ,
struct V_1 * V_12 )
{
struct V_13 * * V_14 = & V_7 -> V_15 . V_13 ;
struct V_13 * V_16 = NULL ;
struct V_1 * V_2 ;
T_1 V_10 ;
T_1 V_17 ;
F_7 ( ! V_12 -> free ) ;
V_17 = F_4 ( V_7 , V_12 ) ;
F_8 ( V_18 ,
L_1 ,
V_7 -> V_19 , V_17 , V_12 ) ;
while ( * V_14 ) {
V_16 = * V_14 ;
V_2 = F_9 ( V_16 , struct V_1 , V_13 ) ;
F_7 ( ! V_2 -> free ) ;
V_10 = F_4 ( V_7 , V_2 ) ;
if ( V_17 < V_10 )
V_14 = & V_16 -> V_20 ;
else
V_14 = & V_16 -> V_21 ;
}
F_10 ( & V_12 -> V_13 , V_16 , V_14 ) ;
F_11 ( & V_12 -> V_13 , & V_7 -> V_15 ) ;
}
static void F_12 (
struct V_6 * V_7 , struct V_1 * V_12 )
{
struct V_13 * * V_14 = & V_7 -> V_22 . V_13 ;
struct V_13 * V_16 = NULL ;
struct V_1 * V_2 ;
F_7 ( V_12 -> free ) ;
while ( * V_14 ) {
V_16 = * V_14 ;
V_2 = F_9 ( V_16 , struct V_1 , V_13 ) ;
F_7 ( V_2 -> free ) ;
if ( V_12 -> V_11 < V_2 -> V_11 )
V_14 = & V_16 -> V_20 ;
else if ( V_12 -> V_11 > V_2 -> V_11 )
V_14 = & V_16 -> V_21 ;
else
F_13 () ;
}
F_10 ( & V_12 -> V_13 , V_16 , V_14 ) ;
F_11 ( & V_12 -> V_13 , & V_7 -> V_22 ) ;
}
static struct V_1 * F_14 (
struct V_6 * V_7 ,
T_2 V_23 )
{
struct V_13 * V_24 = V_7 -> V_22 . V_13 ;
struct V_1 * V_2 ;
void * V_25 ;
V_25 = ( void * ) ( V_23 - V_7 -> V_26 ) ;
while ( V_24 ) {
V_2 = F_9 ( V_24 , struct V_1 , V_13 ) ;
F_7 ( V_2 -> free ) ;
if ( V_25 < V_2 -> V_11 )
V_24 = V_24 -> V_20 ;
else if ( V_25 > V_2 -> V_11 )
V_24 = V_24 -> V_21 ;
else {
if ( V_2 -> V_27 ) {
F_15 ( L_2 ,
V_7 -> V_19 , V_28 -> V_19 , ( V_29 ) V_23 ) ;
return NULL ;
}
V_2 -> V_27 = 1 ;
return V_2 ;
}
}
return NULL ;
}
struct V_1 * F_16 ( struct V_6 * V_7 ,
T_2 V_23 )
{
struct V_1 * V_2 ;
F_17 ( & V_7 -> V_30 ) ;
V_2 = F_14 ( V_7 , V_23 ) ;
F_18 ( & V_7 -> V_30 ) ;
return V_2 ;
}
static int F_19 ( struct V_6 * V_7 , int V_31 ,
void * V_32 , void * V_33 ,
struct V_34 * V_35 )
{
void * V_36 ;
unsigned long V_37 ;
struct V_38 * V_39 ;
struct V_40 * V_41 = NULL ;
bool V_42 = false ;
F_8 ( V_18 ,
L_3 , V_7 -> V_19 ,
V_31 ? L_4 : L_5 , V_32 , V_33 ) ;
if ( V_33 <= V_32 )
return 0 ;
F_20 ( V_7 , V_31 , V_32 , V_33 ) ;
if ( V_31 == 0 )
goto V_43;
for ( V_36 = V_32 ; V_36 < V_33 ; V_36 += V_44 ) {
V_39 = & V_7 -> V_45 [ ( V_36 - V_7 -> V_2 ) / V_44 ] ;
if ( ! V_39 -> V_46 ) {
V_42 = true ;
break;
}
}
if ( ! V_35 && V_42 && F_21 ( V_7 -> V_47 ) )
V_41 = V_7 -> V_47 ;
if ( V_41 ) {
F_22 ( & V_41 -> V_48 ) ;
V_35 = V_7 -> V_35 ;
}
if ( ! V_35 && V_42 ) {
F_15 ( L_6 ,
V_7 -> V_19 ) ;
goto V_49;
}
for ( V_36 = V_32 ; V_36 < V_33 ; V_36 += V_44 ) {
int V_50 ;
bool V_51 ;
T_1 V_52 ;
V_52 = ( V_36 - V_7 -> V_2 ) / V_44 ;
V_39 = & V_7 -> V_45 [ V_52 ] ;
if ( V_39 -> V_46 ) {
F_23 ( V_7 , V_52 ) ;
V_51 = F_24 ( & V_53 , & V_39 -> V_54 ) ;
F_25 ( ! V_51 ) ;
F_26 ( V_7 , V_52 ) ;
continue;
}
if ( F_25 ( ! V_35 ) )
goto V_55;
F_27 ( V_7 , V_52 ) ;
V_39 -> V_46 = F_28 ( V_56 |
V_57 |
V_58 ) ;
if ( ! V_39 -> V_46 ) {
F_15 ( L_7 ,
V_7 -> V_19 , V_36 ) ;
goto V_59;
}
V_39 -> V_7 = V_7 ;
F_29 ( & V_39 -> V_54 ) ;
V_50 = F_30 ( ( unsigned long ) V_36 ,
V_44 , V_60 ,
& V_39 -> V_46 ) ;
F_31 ( ( unsigned long ) V_36 ,
( unsigned long ) V_36 + V_44 ) ;
if ( V_50 != 1 ) {
F_15 ( L_8 ,
V_7 -> V_19 , V_36 ) ;
goto V_61;
}
V_37 =
( T_2 ) V_36 + V_7 -> V_26 ;
V_50 = F_32 ( V_35 , V_37 , V_39 [ 0 ] . V_46 ) ;
if ( V_50 ) {
F_15 ( L_9 ,
V_7 -> V_19 , V_37 ) ;
goto V_62;
}
F_33 ( V_7 , V_52 ) ;
}
if ( V_41 ) {
F_34 ( & V_41 -> V_48 ) ;
F_35 ( V_41 ) ;
}
return 0 ;
V_43:
for ( V_36 = V_33 - V_44 ; V_36 >= V_32 ;
V_36 -= V_44 ) {
bool V_50 ;
T_1 V_52 ;
V_52 = ( V_36 - V_7 -> V_2 ) / V_44 ;
V_39 = & V_7 -> V_45 [ V_52 ] ;
F_36 ( V_7 , V_52 ) ;
V_50 = F_37 ( & V_53 , & V_39 -> V_54 ) ;
F_25 ( ! V_50 ) ;
F_38 ( V_7 , V_52 ) ;
continue;
V_62:
F_39 ( ( unsigned long ) V_36 , V_44 ) ;
V_61:
F_40 ( V_39 -> V_46 ) ;
V_39 -> V_46 = NULL ;
V_59:
V_55:
;
}
V_49:
if ( V_41 ) {
F_34 ( & V_41 -> V_48 ) ;
F_35 ( V_41 ) ;
}
return V_35 ? - V_63 : - V_64 ;
}
struct V_1 * F_41 ( struct V_6 * V_7 ,
T_1 V_65 ,
T_1 V_66 ,
T_1 V_67 ,
int V_68 )
{
struct V_13 * V_24 = V_7 -> V_15 . V_13 ;
struct V_1 * V_2 ;
T_1 V_10 ;
struct V_13 * V_69 = NULL ;
void * V_70 ;
void * V_71 ;
T_1 V_72 , V_73 ;
int V_50 ;
if ( V_7 -> V_35 == NULL ) {
F_15 ( L_10 ,
V_7 -> V_19 ) ;
return F_42 ( - V_64 ) ;
}
V_73 = F_43 ( V_65 , sizeof( void * ) ) +
F_43 ( V_66 , sizeof( void * ) ) ;
if ( V_73 < V_65 || V_73 < V_66 ) {
F_8 ( V_18 ,
L_11 ,
V_7 -> V_19 , V_65 , V_66 ) ;
return F_42 ( - V_74 ) ;
}
V_72 = V_73 + F_43 ( V_67 , sizeof( void * ) ) ;
if ( V_72 < V_73 || V_72 < V_67 ) {
F_8 ( V_18 ,
L_12 ,
V_7 -> V_19 , V_67 ) ;
return F_42 ( - V_74 ) ;
}
if ( V_68 &&
V_7 -> V_75 < V_72 + sizeof( struct V_1 ) ) {
F_8 ( V_18 ,
L_13 ,
V_7 -> V_19 , V_72 ) ;
return F_42 ( - V_76 ) ;
}
V_72 = F_44 ( V_72 , sizeof( void * ) ) ;
while ( V_24 ) {
V_2 = F_9 ( V_24 , struct V_1 , V_13 ) ;
F_7 ( ! V_2 -> free ) ;
V_10 = F_4 ( V_7 , V_2 ) ;
if ( V_72 < V_10 ) {
V_69 = V_24 ;
V_24 = V_24 -> V_20 ;
} else if ( V_72 > V_10 )
V_24 = V_24 -> V_21 ;
else {
V_69 = V_24 ;
break;
}
}
if ( V_69 == NULL ) {
T_1 V_22 = 0 ;
T_1 V_77 = 0 ;
T_1 V_78 = 0 ;
T_1 V_15 = 0 ;
T_1 V_79 = 0 ;
T_1 V_80 = 0 ;
for ( V_24 = F_45 ( & V_7 -> V_22 ) ; V_24 != NULL ;
V_24 = F_46 ( V_24 ) ) {
V_2 = F_9 ( V_24 , struct V_1 , V_13 ) ;
V_10 = F_4 ( V_7 , V_2 ) ;
V_22 ++ ;
V_78 += V_10 ;
if ( V_10 > V_77 )
V_77 = V_10 ;
}
for ( V_24 = F_45 ( & V_7 -> V_15 ) ; V_24 != NULL ;
V_24 = F_46 ( V_24 ) ) {
V_2 = F_9 ( V_24 , struct V_1 , V_13 ) ;
V_10 = F_4 ( V_7 , V_2 ) ;
V_15 ++ ;
V_80 += V_10 ;
if ( V_10 > V_79 )
V_79 = V_10 ;
}
F_15 ( L_14 ,
V_7 -> V_19 , V_72 ) ;
F_15 ( L_15 ,
V_78 , V_22 , V_77 ,
V_80 , V_15 , V_79 ) ;
return F_42 ( - V_76 ) ;
}
if ( V_24 == NULL ) {
V_2 = F_9 ( V_69 , struct V_1 , V_13 ) ;
V_10 = F_4 ( V_7 , V_2 ) ;
}
F_8 ( V_18 ,
L_16 ,
V_7 -> V_19 , V_72 , V_2 , V_10 ) ;
V_70 =
( void * ) ( ( ( T_2 ) V_2 -> V_11 + V_10 ) & V_81 ) ;
F_25 ( V_24 && V_10 != V_72 ) ;
V_71 =
( void * ) F_47 ( ( T_2 ) V_2 -> V_11 + V_72 ) ;
if ( V_71 > V_70 )
V_71 = V_70 ;
V_50 = F_19 ( V_7 , 1 ,
( void * ) F_47 ( ( T_2 ) V_2 -> V_11 ) , V_71 , NULL ) ;
if ( V_50 )
return F_42 ( V_50 ) ;
if ( V_10 != V_72 ) {
struct V_1 * V_12 ;
V_12 = F_48 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_12 ) {
F_15 ( L_17 ,
V_82 , V_7 -> V_19 ) ;
goto V_83;
}
V_12 -> V_11 = ( V_9 * ) V_2 -> V_11 + V_72 ;
F_49 ( & V_12 -> V_3 , & V_2 -> V_3 ) ;
V_12 -> free = 1 ;
F_6 ( V_7 , V_12 ) ;
}
F_50 ( V_69 , & V_7 -> V_15 ) ;
V_2 -> free = 0 ;
V_2 -> V_27 = 0 ;
F_12 ( V_7 , V_2 ) ;
F_8 ( V_18 ,
L_18 ,
V_7 -> V_19 , V_72 , V_2 ) ;
V_2 -> V_65 = V_65 ;
V_2 -> V_66 = V_66 ;
V_2 -> V_84 = V_68 ;
V_2 -> V_67 = V_67 ;
if ( V_68 ) {
V_7 -> V_75 -= V_72 + sizeof( struct V_1 ) ;
F_8 ( V_85 ,
L_19 ,
V_7 -> V_19 , V_72 , V_7 -> V_75 ) ;
}
return V_2 ;
V_83:
F_19 ( V_7 , 0 ,
( void * ) F_47 ( ( T_2 ) V_2 -> V_11 ) ,
V_71 , NULL ) ;
return F_42 ( - V_63 ) ;
}
struct V_1 * F_51 ( struct V_6 * V_7 ,
T_1 V_65 ,
T_1 V_66 ,
T_1 V_67 ,
int V_68 )
{
struct V_1 * V_2 ;
F_17 ( & V_7 -> V_30 ) ;
V_2 = F_41 ( V_7 , V_65 , V_66 ,
V_67 , V_68 ) ;
F_18 ( & V_7 -> V_30 ) ;
return V_2 ;
}
static void * F_52 ( struct V_1 * V_2 )
{
return ( void * ) ( ( T_2 ) V_2 -> V_11 & V_81 ) ;
}
static void * F_53 ( struct V_1 * V_2 )
{
return ( void * ) ( ( ( T_2 ) ( V_2 -> V_11 ) - 1 ) & V_81 ) ;
}
static void F_54 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_1 * V_5 , * V_4 = NULL ;
bool V_86 = true ;
F_7 ( V_7 -> V_8 . V_4 == & V_2 -> V_3 ) ;
V_5 = F_3 ( V_2 ) ;
F_7 ( ! V_5 -> free ) ;
if ( F_53 ( V_5 ) == F_52 ( V_2 ) ) {
V_86 = false ;
F_8 ( V_18 ,
L_20 ,
V_7 -> V_19 , V_2 -> V_11 , V_5 -> V_11 ) ;
}
if ( ! F_5 ( & V_2 -> V_3 , & V_7 -> V_8 ) ) {
V_4 = F_1 ( V_2 ) ;
if ( F_52 ( V_4 ) == F_52 ( V_2 ) ) {
V_86 = false ;
F_8 ( V_18 ,
L_20 ,
V_7 -> V_19 ,
V_2 -> V_11 ,
V_4 -> V_11 ) ;
}
}
if ( F_55 ( V_2 -> V_11 ) ) {
F_8 ( V_18 ,
L_21 ,
V_7 -> V_19 , V_2 -> V_11 ) ;
V_86 = false ;
}
if ( V_86 ) {
F_8 ( V_18 ,
L_22 ,
V_7 -> V_19 , V_2 -> V_11 ,
V_5 -> V_11 , V_4 ? V_4 -> V_11 : NULL ) ;
F_19 ( V_7 , 0 , F_52 ( V_2 ) ,
F_52 ( V_2 ) + V_44 ,
NULL ) ;
}
F_56 ( & V_2 -> V_3 ) ;
F_57 ( V_2 ) ;
}
static void F_58 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
T_1 V_72 , V_10 ;
V_10 = F_4 ( V_7 , V_2 ) ;
V_72 = F_43 ( V_2 -> V_65 , sizeof( void * ) ) +
F_43 ( V_2 -> V_66 , sizeof( void * ) ) +
F_43 ( V_2 -> V_67 , sizeof( void * ) ) ;
F_8 ( V_18 ,
L_23 ,
V_7 -> V_19 , V_2 , V_72 , V_10 ) ;
F_7 ( V_2 -> free ) ;
F_7 ( V_72 > V_10 ) ;
F_7 ( V_2 -> V_87 != NULL ) ;
F_7 ( V_2 -> V_11 < V_7 -> V_2 ) ;
F_7 ( V_2 -> V_11 > V_7 -> V_2 + V_7 -> V_10 ) ;
if ( V_2 -> V_84 ) {
V_7 -> V_75 += V_72 + sizeof( struct V_1 ) ;
F_8 ( V_85 ,
L_24 ,
V_7 -> V_19 , V_72 , V_7 -> V_75 ) ;
}
F_19 ( V_7 , 0 ,
( void * ) F_47 ( ( T_2 ) V_2 -> V_11 ) ,
( void * ) ( ( ( T_2 ) V_2 -> V_11 + V_10 ) & V_81 ) ,
NULL ) ;
F_50 ( & V_2 -> V_13 , & V_7 -> V_22 ) ;
V_2 -> free = 1 ;
if ( ! F_5 ( & V_2 -> V_3 , & V_7 -> V_8 ) ) {
struct V_1 * V_4 = F_1 ( V_2 ) ;
if ( V_4 -> free ) {
F_50 ( & V_4 -> V_13 , & V_7 -> V_15 ) ;
F_54 ( V_7 , V_4 ) ;
}
}
if ( V_7 -> V_8 . V_4 != & V_2 -> V_3 ) {
struct V_1 * V_5 = F_3 ( V_2 ) ;
if ( V_5 -> free ) {
F_54 ( V_7 , V_2 ) ;
F_50 ( & V_5 -> V_13 , & V_7 -> V_15 ) ;
V_2 = V_5 ;
}
}
F_6 ( V_7 , V_2 ) ;
}
void F_59 ( struct V_6 * V_7 ,
struct V_1 * V_2 )
{
F_17 ( & V_7 -> V_30 ) ;
F_58 ( V_7 , V_2 ) ;
F_18 ( & V_7 -> V_30 ) ;
}
int F_60 ( struct V_6 * V_7 ,
struct V_34 * V_35 )
{
int V_50 ;
struct V_88 * V_89 ;
const char * V_90 ;
struct V_1 * V_2 ;
F_17 ( & V_91 ) ;
if ( V_7 -> V_2 ) {
V_50 = - V_92 ;
V_90 = L_25 ;
goto V_93;
}
V_89 = F_61 ( V_35 -> V_94 - V_35 -> V_95 , V_96 ) ;
if ( V_89 == NULL ) {
V_50 = - V_63 ;
V_90 = L_26 ;
goto V_97;
}
V_7 -> V_2 = V_89 -> V_98 ;
V_7 -> V_26 =
V_35 -> V_95 - ( T_2 ) V_7 -> V_2 ;
F_18 ( & V_91 ) ;
#ifdef F_62
if ( F_63 () ) {
while ( F_64 (
( V_35 -> V_95 ^ ( V_99 ) V_7 -> V_2 ) ) ) {
F_65 ( L_27 ,
V_82 , V_7 -> V_19 , V_35 -> V_95 ,
V_35 -> V_94 , V_7 -> V_2 ) ;
V_35 -> V_95 += V_44 ;
}
}
#endif
V_7 -> V_45 = F_48 ( sizeof( V_7 -> V_45 [ 0 ] ) *
( ( V_35 -> V_94 - V_35 -> V_95 ) / V_44 ) ,
V_56 ) ;
if ( V_7 -> V_45 == NULL ) {
V_50 = - V_63 ;
V_90 = L_28 ;
goto V_100;
}
V_7 -> V_10 = V_35 -> V_94 - V_35 -> V_95 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_56 ) ;
if ( ! V_2 ) {
V_50 = - V_63 ;
V_90 = L_29 ;
goto V_83;
}
V_2 -> V_11 = V_7 -> V_2 ;
F_49 ( & V_2 -> V_3 , & V_7 -> V_8 ) ;
V_2 -> free = 1 ;
F_6 ( V_7 , V_2 ) ;
V_7 -> V_75 = V_7 -> V_10 / 2 ;
F_66 () ;
V_7 -> V_35 = V_35 ;
V_7 -> V_47 = V_35 -> V_101 ;
F_67 ( V_7 -> V_47 ) ;
return 0 ;
V_83:
F_57 ( V_7 -> V_45 ) ;
V_7 -> V_45 = NULL ;
V_100:
F_17 ( & V_91 ) ;
F_68 ( V_7 -> V_2 ) ;
V_7 -> V_2 = NULL ;
V_97:
V_93:
F_18 ( & V_91 ) ;
F_15 ( L_30 , V_82 ,
V_7 -> V_19 , V_35 -> V_95 , V_35 -> V_94 , V_90 , V_50 ) ;
return V_50 ;
}
void F_69 ( struct V_6 * V_7 )
{
struct V_13 * V_24 ;
int V_8 , V_102 ;
struct V_1 * V_2 ;
F_7 ( V_7 -> V_35 ) ;
V_8 = 0 ;
F_17 ( & V_7 -> V_30 ) ;
while ( ( V_24 = F_45 ( & V_7 -> V_22 ) ) ) {
V_2 = F_9 ( V_24 , struct V_1 , V_13 ) ;
F_7 ( V_2 -> V_87 ) ;
F_58 ( V_7 , V_2 ) ;
V_8 ++ ;
}
while ( ! F_70 ( & V_7 -> V_8 ) ) {
V_2 = F_71 ( & V_7 -> V_8 ,
struct V_1 , V_3 ) ;
F_25 ( ! V_2 -> free ) ;
F_56 ( & V_2 -> V_3 ) ;
F_72 ( ! F_70 ( & V_7 -> V_8 ) ) ;
F_57 ( V_2 ) ;
}
V_102 = 0 ;
if ( V_7 -> V_45 ) {
int V_103 ;
for ( V_103 = 0 ; V_103 < V_7 -> V_10 / V_44 ; V_103 ++ ) {
void * V_36 ;
bool V_51 ;
if ( ! V_7 -> V_45 [ V_103 ] . V_46 )
continue;
V_51 = F_24 ( & V_53 ,
& V_7 -> V_45 [ V_103 ] . V_54 ) ;
V_36 = V_7 -> V_2 + V_103 * V_44 ;
F_8 ( V_18 ,
L_31 ,
V_82 , V_7 -> V_19 , V_103 , V_36 ,
V_51 ? L_32 : L_33 ) ;
F_39 ( ( unsigned long ) V_36 , V_44 ) ;
F_40 ( V_7 -> V_45 [ V_103 ] . V_46 ) ;
V_102 ++ ;
}
F_57 ( V_7 -> V_45 ) ;
F_68 ( V_7 -> V_2 ) ;
}
F_18 ( & V_7 -> V_30 ) ;
if ( V_7 -> V_47 )
F_73 ( V_7 -> V_47 ) ;
F_8 ( V_104 ,
L_34 ,
V_82 , V_7 -> V_19 , V_8 , V_102 ) ;
}
static void F_74 ( struct V_105 * V_106 , const char * V_107 ,
struct V_1 * V_2 )
{
F_75 ( V_106 , L_35 ,
V_107 , V_2 -> V_108 , V_2 -> V_11 ,
V_2 -> V_65 , V_2 -> V_66 ,
V_2 -> V_67 ,
V_2 -> V_87 ? L_33 : L_36 ) ;
}
void F_76 ( struct V_105 * V_106 ,
struct V_6 * V_7 )
{
struct V_13 * V_24 ;
F_17 ( & V_7 -> V_30 ) ;
for ( V_24 = F_45 ( & V_7 -> V_22 ) ; V_24 != NULL ; V_24 = F_46 ( V_24 ) )
F_74 ( V_106 , L_37 ,
F_9 ( V_24 , struct V_1 , V_13 ) ) ;
F_18 ( & V_7 -> V_30 ) ;
}
void F_77 ( struct V_105 * V_106 ,
struct V_6 * V_7 )
{
struct V_38 * V_39 ;
int V_103 ;
int V_109 = 0 ;
int V_54 = 0 ;
int free = 0 ;
F_17 ( & V_7 -> V_30 ) ;
for ( V_103 = 0 ; V_103 < V_7 -> V_10 / V_44 ; V_103 ++ ) {
V_39 = & V_7 -> V_45 [ V_103 ] ;
if ( ! V_39 -> V_46 )
free ++ ;
else if ( F_70 ( & V_39 -> V_54 ) )
V_109 ++ ;
else
V_54 ++ ;
}
F_18 ( & V_7 -> V_30 ) ;
F_75 ( V_106 , L_38 , V_109 , V_54 , free ) ;
}
int F_78 ( struct V_6 * V_7 )
{
struct V_13 * V_24 ;
int V_110 = 0 ;
F_17 ( & V_7 -> V_30 ) ;
for ( V_24 = F_45 ( & V_7 -> V_22 ) ; V_24 != NULL ; V_24 = F_46 ( V_24 ) )
V_110 ++ ;
F_18 ( & V_7 -> V_30 ) ;
return V_110 ;
}
void F_79 ( struct V_6 * V_7 )
{
F_80 ( V_7 -> V_35 , NULL ) ;
}
enum V_111 F_81 ( struct V_112 * V_113 ,
struct V_114 * V_54 ,
T_3 * V_115 ,
void * V_116 )
{
struct V_40 * V_41 = NULL ;
struct V_38 * V_39 = F_82 ( V_113 ,
struct V_38 ,
V_54 ) ;
struct V_6 * V_7 ;
T_2 V_36 ;
T_1 V_52 ;
struct V_34 * V_35 ;
V_7 = V_39 -> V_7 ;
if ( ! F_83 ( & V_7 -> V_30 ) )
goto V_117;
if ( ! V_39 -> V_46 )
goto V_118;
V_52 = V_39 - V_7 -> V_45 ;
V_36 = ( T_2 ) V_7 -> V_2 + V_52 * V_44 ;
V_35 = V_7 -> V_35 ;
if ( V_35 ) {
if ( ! F_21 ( V_7 -> V_47 ) )
goto V_119;
V_41 = V_7 -> V_47 ;
if ( ! F_84 ( & V_41 -> V_48 ) )
goto V_120;
}
F_85 ( V_54 , V_113 ) ;
F_86 ( V_115 ) ;
if ( V_35 ) {
F_87 ( V_7 , V_52 ) ;
F_88 ( V_35 ,
V_36 + V_7 -> V_26 ,
V_44 ) ;
F_89 ( V_7 , V_52 ) ;
F_34 ( & V_41 -> V_48 ) ;
F_35 ( V_41 ) ;
}
F_90 ( V_7 , V_52 ) ;
F_39 ( V_36 , V_44 ) ;
F_40 ( V_39 -> V_46 ) ;
V_39 -> V_46 = NULL ;
F_91 ( V_7 , V_52 ) ;
F_92 ( V_115 ) ;
F_18 ( & V_7 -> V_30 ) ;
return V_121 ;
V_120:
F_93 ( V_41 ) ;
V_119:
V_118:
F_18 ( & V_7 -> V_30 ) ;
V_117:
return V_122 ;
}
static unsigned long
F_94 ( struct V_123 * V_124 , struct V_125 * V_126 )
{
unsigned long V_50 = F_95 ( & V_53 ) ;
return V_50 ;
}
static unsigned long
F_96 ( struct V_123 * V_124 , struct V_125 * V_126 )
{
unsigned long V_50 ;
V_50 = F_97 ( & V_53 , F_81 ,
NULL , V_126 -> V_127 ) ;
return V_50 ;
}
void F_98 ( struct V_6 * V_7 )
{
V_7 -> V_19 = V_28 -> V_128 -> V_19 ;
F_99 ( & V_7 -> V_30 ) ;
F_29 ( & V_7 -> V_8 ) ;
}
void F_100 ( void )
{
F_101 ( & V_53 ) ;
F_102 ( & V_129 ) ;
}
