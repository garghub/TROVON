static int F_1 ( char * V_1 )
{
if ( ! V_1 )
return - V_2 ;
if ( strcmp ( V_1 , L_1 ) == 0 )
V_3 = false ;
return 0 ;
}
static bool F_2 ( void )
{
if ( V_3 )
return false ;
return true ;
}
static T_1 void F_3 ( void )
{
unsigned long V_4 [ 4 ] ;
struct V_5 V_6 ;
V_6 . V_7 = 0 ;
V_6 . V_8 = F_4 ( V_4 ) ;
V_6 . V_4 = & V_4 [ 0 ] ;
V_6 . V_9 = 0 ;
F_5 ( & V_6 ) ;
V_10 = F_6 ( & V_6 , V_11 ) ;
}
static T_1 void F_7 ( void )
{
unsigned long V_4 [ 4 ] ;
struct V_5 V_12 ;
V_12 . V_7 = 0 ;
V_12 . V_8 = F_4 ( V_4 ) ;
V_12 . V_4 = & V_4 [ 0 ] ;
V_12 . V_9 = 0 ;
F_5 ( & V_12 ) ;
V_13 = F_6 ( & V_12 , V_11 ) ;
}
static void F_8 ( void )
{
if ( V_3 )
return;
F_3 () ;
F_7 () ;
F_9 ( & V_14 ) ;
F_10 () ;
}
static inline struct V_15 * F_11 ( struct V_16 * V_16 )
{
return ( void * ) V_16 + V_17 . V_18 ;
}
void F_12 ( struct V_19 * V_19 , unsigned int V_20 )
{
int V_21 ;
struct V_16 * V_16 ;
for ( V_21 = 0 ; V_21 < ( 1 << V_20 ) ; V_21 ++ ) {
V_16 = F_13 ( V_19 + V_21 ) ;
if ( F_14 ( ! V_16 ) )
continue;
F_15 ( V_22 , & V_16 -> V_23 ) ;
}
}
static inline bool F_16 ( struct V_5 * V_24 ,
unsigned long V_25 )
{
int V_21 , V_26 ;
if ( ! V_24 -> V_7 )
return false ;
for ( V_21 = 0 , V_26 = 0 ; V_21 < V_24 -> V_7 ; V_21 ++ ) {
if ( V_24 -> V_4 [ V_21 ] == V_25 && ++ V_26 == 2 )
return true ;
}
return false ;
}
static T_1 T_2 F_17 ( T_3 V_23 )
{
unsigned long V_4 [ V_27 ] ;
struct V_5 V_24 = {
. V_7 = 0 ,
. V_4 = V_4 ,
. V_8 = V_27 ,
. V_9 = 0
} ;
T_2 V_28 ;
F_5 ( & V_24 ) ;
if ( V_24 . V_7 != 0 &&
V_24 . V_4 [ V_24 . V_7 - 1 ] == V_29 )
V_24 . V_7 -- ;
if ( F_16 ( & V_24 , V_30 ) )
return V_10 ;
V_28 = F_6 ( & V_24 , V_23 ) ;
if ( ! V_28 )
V_28 = V_13 ;
return V_28 ;
}
T_1 void F_18 ( struct V_19 * V_19 , unsigned int V_20 ,
T_3 V_31 )
{
struct V_16 * V_16 = F_13 ( V_19 ) ;
struct V_15 * V_15 ;
if ( F_14 ( ! V_16 ) )
return;
V_15 = F_11 ( V_16 ) ;
V_15 -> V_28 = F_17 ( V_31 ) ;
V_15 -> V_20 = V_20 ;
V_15 -> V_31 = V_31 ;
V_15 -> V_32 = - 1 ;
F_19 ( V_22 , & V_16 -> V_23 ) ;
}
void F_20 ( struct V_19 * V_19 , int V_33 )
{
struct V_16 * V_16 = F_13 ( V_19 ) ;
struct V_15 * V_15 ;
if ( F_14 ( ! V_16 ) )
return;
V_15 = F_11 ( V_16 ) ;
V_15 -> V_32 = V_33 ;
}
void F_21 ( struct V_19 * V_19 , unsigned int V_20 )
{
int V_21 ;
struct V_16 * V_16 = F_13 ( V_19 ) ;
struct V_15 * V_15 ;
if ( F_14 ( ! V_16 ) )
return;
V_15 = F_11 ( V_16 ) ;
V_15 -> V_20 = 0 ;
for ( V_21 = 1 ; V_21 < ( 1 << V_20 ) ; V_21 ++ )
F_22 ( V_19 , V_19 + V_21 ) ;
}
void F_22 ( struct V_19 * V_34 , struct V_19 * V_35 )
{
struct V_16 * V_36 = F_13 ( V_34 ) ;
struct V_16 * V_37 = F_13 ( V_35 ) ;
struct V_15 * V_38 , * V_39 ;
if ( F_14 ( ! V_36 || ! V_37 ) )
return;
V_38 = F_11 ( V_36 ) ;
V_39 = F_11 ( V_37 ) ;
V_39 -> V_20 = V_38 -> V_20 ;
V_39 -> V_31 = V_38 -> V_31 ;
V_39 -> V_32 =
V_38 -> V_32 ;
V_39 -> V_28 = V_38 -> V_28 ;
F_19 ( V_22 , & V_37 -> V_23 ) ;
}
void F_23 ( struct V_40 * V_41 ,
T_4 * V_42 , struct V_43 * V_43 )
{
struct V_19 * V_19 ;
struct V_16 * V_16 ;
struct V_15 * V_15 ;
unsigned long V_44 = V_43 -> V_45 , V_46 ;
unsigned long V_47 = V_44 + V_43 -> V_48 ;
unsigned long V_26 [ V_49 ] = { 0 , } ;
int V_50 , V_51 ;
int V_21 ;
V_44 = V_43 -> V_45 ;
for (; V_44 < V_47 ; ) {
if ( ! F_24 ( V_44 ) ) {
V_44 = F_25 ( V_44 + 1 , V_52 ) ;
continue;
}
V_46 = F_25 ( V_44 + 1 , V_53 ) ;
V_46 = F_26 ( V_46 , V_47 ) ;
V_19 = F_27 ( V_44 ) ;
V_50 = F_28 ( V_19 ) ;
for (; V_44 < V_46 ; V_44 ++ ) {
if ( ! F_29 ( V_44 ) )
continue;
V_19 = F_27 ( V_44 ) ;
if ( F_30 ( V_19 ) != V_43 )
continue;
if ( F_31 ( V_19 ) ) {
V_44 += ( 1UL << F_32 ( V_19 ) ) - 1 ;
continue;
}
if ( F_33 ( V_19 ) )
continue;
V_16 = F_13 ( V_19 ) ;
if ( F_14 ( ! V_16 ) )
continue;
if ( ! F_34 ( V_22 , & V_16 -> V_23 ) )
continue;
V_15 = F_11 ( V_16 ) ;
V_51 = F_35 (
V_15 -> V_31 ) ;
if ( V_50 != V_51 ) {
if ( F_36 ( V_50 ) )
V_26 [ V_54 ] ++ ;
else
V_26 [ V_50 ] ++ ;
V_44 = V_46 ;
break;
}
V_44 += ( 1UL << V_15 -> V_20 ) - 1 ;
}
}
F_37 ( V_41 , L_2 , V_42 -> V_55 , V_43 -> V_56 ) ;
for ( V_21 = 0 ; V_21 < V_49 ; V_21 ++ )
F_37 ( V_41 , L_3 , V_26 [ V_21 ] ) ;
F_38 ( V_41 , '\n' ) ;
}
static T_5
F_39 ( char T_6 * V_1 , T_7 V_26 , unsigned long V_44 ,
struct V_19 * V_19 , struct V_15 * V_15 ,
T_2 V_28 )
{
int V_57 ;
int V_50 , V_51 ;
char * V_58 ;
unsigned long V_4 [ V_27 ] ;
struct V_5 V_24 = {
. V_7 = 0 ,
. V_4 = V_4 ,
. V_8 = V_27 ,
. V_9 = 0
} ;
V_58 = F_40 ( V_26 , V_11 ) ;
if ( ! V_58 )
return - V_59 ;
V_57 = snprintf ( V_58 , V_26 ,
L_4 ,
V_15 -> V_20 , V_15 -> V_31 ,
& V_15 -> V_31 ) ;
if ( V_57 >= V_26 )
goto V_60;
V_50 = F_28 ( V_19 ) ;
V_51 = F_35 ( V_15 -> V_31 ) ;
V_57 += snprintf ( V_58 + V_57 , V_26 - V_57 ,
L_5 ,
V_44 ,
V_61 [ V_51 ] ,
V_44 >> V_62 ,
V_61 [ V_50 ] ,
V_19 -> V_23 , & V_19 -> V_23 ) ;
if ( V_57 >= V_26 )
goto V_60;
F_41 ( V_28 , & V_24 ) ;
V_57 += F_42 ( V_58 + V_57 , V_26 - V_57 , & V_24 , 0 ) ;
if ( V_57 >= V_26 )
goto V_60;
if ( V_15 -> V_32 != - 1 ) {
V_57 += snprintf ( V_58 + V_57 , V_26 - V_57 ,
L_6 ,
V_63 [ V_15 -> V_32 ] ) ;
if ( V_57 >= V_26 )
goto V_60;
}
V_57 += snprintf ( V_58 + V_57 , V_26 - V_57 , L_7 ) ;
if ( V_57 >= V_26 )
goto V_60;
if ( F_43 ( V_1 , V_58 , V_57 ) )
V_57 = - V_64 ;
F_44 ( V_58 ) ;
return V_57 ;
V_60:
F_44 ( V_58 ) ;
return - V_59 ;
}
void F_45 ( struct V_19 * V_19 )
{
struct V_16 * V_16 = F_13 ( V_19 ) ;
struct V_15 * V_15 ;
unsigned long V_4 [ V_27 ] ;
struct V_5 V_24 = {
. V_7 = 0 ,
. V_4 = V_4 ,
. V_8 = V_27 ,
. V_9 = 0
} ;
T_2 V_28 ;
T_3 V_31 ;
int V_65 ;
if ( F_14 ( ! V_16 ) ) {
F_46 ( L_8 ) ;
return;
}
V_15 = F_11 ( V_16 ) ;
V_31 = V_15 -> V_31 ;
V_65 = F_35 ( V_31 ) ;
if ( ! F_34 ( V_22 , & V_16 -> V_23 ) ) {
F_46 ( L_9 ) ;
return;
}
V_28 = F_47 ( V_15 -> V_28 ) ;
if ( ! V_28 ) {
F_46 ( L_9 ) ;
return;
}
F_41 ( V_28 , & V_24 ) ;
F_46 ( L_10 ,
V_15 -> V_20 , V_61 [ V_65 ] , V_31 , & V_31 ) ;
F_48 ( & V_24 , 0 ) ;
if ( V_15 -> V_32 != - 1 )
F_46 ( L_11 ,
V_63 [ V_15 -> V_32 ] ) ;
}
static T_5
F_49 ( struct V_66 * V_66 , char T_6 * V_1 , T_7 V_26 , T_8 * V_67 )
{
unsigned long V_44 ;
struct V_19 * V_19 ;
struct V_16 * V_16 ;
struct V_15 * V_15 ;
T_2 V_28 ;
if ( ! F_50 ( & V_14 ) )
return - V_2 ;
V_19 = NULL ;
V_44 = V_68 + * V_67 ;
while ( ! F_24 ( V_44 ) && ( V_44 & ( V_52 - 1 ) ) != 0 )
V_44 ++ ;
F_51 ( NULL ) ;
for (; V_44 < V_69 ; V_44 ++ ) {
if ( ( V_44 & ( V_52 - 1 ) ) == 0 && ! F_24 ( V_44 ) ) {
V_44 += V_52 - 1 ;
continue;
}
if ( ! F_29 ( V_44 ) )
continue;
V_19 = F_27 ( V_44 ) ;
if ( F_31 ( V_19 ) ) {
unsigned long V_70 = F_52 ( V_19 ) ;
if ( V_70 < V_71 )
V_44 += ( 1UL << V_70 ) - 1 ;
continue;
}
V_16 = F_13 ( V_19 ) ;
if ( F_14 ( ! V_16 ) )
continue;
if ( ! F_34 ( V_22 , & V_16 -> V_23 ) )
continue;
V_15 = F_11 ( V_16 ) ;
V_28 = F_47 ( V_15 -> V_28 ) ;
if ( ! V_28 )
continue;
* V_67 = ( V_44 - V_68 ) + 1 ;
return F_39 ( V_1 , V_26 , V_44 , V_19 ,
V_15 , V_28 ) ;
}
return 0 ;
}
static void F_53 ( T_4 * V_42 , struct V_43 * V_43 )
{
struct V_19 * V_19 ;
struct V_16 * V_16 ;
unsigned long V_44 = V_43 -> V_45 , V_46 ;
unsigned long V_47 = V_44 + V_43 -> V_48 ;
unsigned long V_26 = 0 ;
V_44 = V_43 -> V_45 ;
for (; V_44 < V_47 ; ) {
if ( ! F_24 ( V_44 ) ) {
V_44 = F_25 ( V_44 + 1 , V_52 ) ;
continue;
}
V_46 = F_25 ( V_44 + 1 , V_53 ) ;
V_46 = F_26 ( V_46 , V_47 ) ;
V_19 = F_27 ( V_44 ) ;
for (; V_44 < V_46 ; V_44 ++ ) {
if ( ! F_29 ( V_44 ) )
continue;
V_19 = F_27 ( V_44 ) ;
if ( F_30 ( V_19 ) != V_43 )
continue;
if ( F_31 ( V_19 ) ) {
V_44 += ( 1UL << F_32 ( V_19 ) ) - 1 ;
continue;
}
if ( F_33 ( V_19 ) )
continue;
V_16 = F_13 ( V_19 ) ;
if ( F_14 ( ! V_16 ) )
continue;
if ( F_34 ( V_22 , & V_16 -> V_23 ) )
continue;
F_54 ( V_19 , 0 , 0 ) ;
V_26 ++ ;
}
}
F_55 ( L_12 ,
V_42 -> V_55 , V_43 -> V_56 , V_26 ) ;
}
static void F_56 ( T_4 * V_42 )
{
struct V_43 * V_43 ;
struct V_43 * V_72 = V_42 -> V_72 ;
unsigned long V_23 ;
for ( V_43 = V_72 ; V_43 - V_72 < V_73 ; ++ V_43 ) {
if ( ! F_57 ( V_43 ) )
continue;
F_58 ( & V_43 -> V_74 , V_23 ) ;
F_53 ( V_42 , V_43 ) ;
F_59 ( & V_43 -> V_74 , V_23 ) ;
}
}
static void F_10 ( void )
{
T_4 * V_42 ;
F_51 ( NULL ) ;
F_60 (pgdat)
F_56 ( V_42 ) ;
}
static int T_9 F_61 ( void )
{
struct V_75 * V_75 ;
if ( ! F_50 ( & V_14 ) ) {
F_55 ( L_13 ) ;
return 0 ;
}
V_75 = F_62 ( L_14 , V_76 , NULL ,
NULL , & V_77 ) ;
if ( F_63 ( V_75 ) )
return F_64 ( V_75 ) ;
return 0 ;
}
