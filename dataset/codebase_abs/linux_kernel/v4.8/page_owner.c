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
void F_11 ( struct V_15 * V_15 , unsigned int V_16 )
{
int V_17 ;
struct V_18 * V_18 ;
for ( V_17 = 0 ; V_17 < ( 1 << V_16 ) ; V_17 ++ ) {
V_18 = F_12 ( V_15 + V_17 ) ;
if ( F_13 ( ! V_18 ) )
continue;
F_14 ( V_19 , & V_18 -> V_20 ) ;
}
}
static inline bool F_15 ( struct V_5 * V_21 ,
unsigned long V_22 )
{
int V_17 , V_23 ;
if ( ! V_21 -> V_7 )
return false ;
for ( V_17 = 0 , V_23 = 0 ; V_17 < V_21 -> V_7 ; V_17 ++ ) {
if ( V_21 -> V_4 [ V_17 ] == V_22 && ++ V_23 == 2 )
return true ;
}
return false ;
}
static T_1 T_2 F_16 ( T_3 V_20 )
{
unsigned long V_4 [ V_24 ] ;
struct V_5 V_21 = {
. V_7 = 0 ,
. V_4 = V_4 ,
. V_8 = V_24 ,
. V_9 = 0
} ;
T_2 V_25 ;
F_5 ( & V_21 ) ;
if ( V_21 . V_7 != 0 &&
V_21 . V_4 [ V_21 . V_7 - 1 ] == V_26 )
V_21 . V_7 -- ;
if ( F_15 ( & V_21 , V_27 ) )
return V_10 ;
V_25 = F_6 ( & V_21 , V_20 ) ;
if ( ! V_25 )
V_25 = V_13 ;
return V_25 ;
}
T_1 void F_17 ( struct V_15 * V_15 , unsigned int V_16 ,
T_3 V_28 )
{
struct V_18 * V_18 = F_12 ( V_15 ) ;
if ( F_13 ( ! V_18 ) )
return;
V_18 -> V_25 = F_16 ( V_28 ) ;
V_18 -> V_16 = V_16 ;
V_18 -> V_28 = V_28 ;
V_18 -> V_29 = - 1 ;
F_18 ( V_19 , & V_18 -> V_20 ) ;
}
void F_19 ( struct V_15 * V_15 , int V_30 )
{
struct V_18 * V_18 = F_12 ( V_15 ) ;
if ( F_13 ( ! V_18 ) )
return;
V_18 -> V_29 = V_30 ;
}
void F_20 ( struct V_15 * V_15 , unsigned int V_16 )
{
int V_17 ;
struct V_18 * V_18 = F_12 ( V_15 ) ;
if ( F_13 ( ! V_18 ) )
return;
V_18 -> V_16 = 0 ;
for ( V_17 = 1 ; V_17 < ( 1 << V_16 ) ; V_17 ++ )
F_21 ( V_15 , V_15 + V_17 ) ;
}
void F_21 ( struct V_15 * V_31 , struct V_15 * V_32 )
{
struct V_18 * V_33 = F_12 ( V_31 ) ;
struct V_18 * V_34 = F_12 ( V_32 ) ;
if ( F_13 ( ! V_33 || ! V_34 ) )
return;
V_34 -> V_16 = V_33 -> V_16 ;
V_34 -> V_28 = V_33 -> V_28 ;
V_34 -> V_29 = V_33 -> V_29 ;
V_34 -> V_25 = V_33 -> V_25 ;
F_18 ( V_19 , & V_34 -> V_20 ) ;
}
static T_4
F_22 ( char T_5 * V_1 , T_6 V_23 , unsigned long V_35 ,
struct V_15 * V_15 , struct V_18 * V_18 ,
T_2 V_25 )
{
int V_36 ;
int V_37 , V_38 ;
char * V_39 ;
unsigned long V_4 [ V_24 ] ;
struct V_5 V_21 = {
. V_7 = 0 ,
. V_4 = V_4 ,
. V_8 = V_24 ,
. V_9 = 0
} ;
V_39 = F_23 ( V_23 , V_11 ) ;
if ( ! V_39 )
return - V_40 ;
V_36 = snprintf ( V_39 , V_23 ,
L_2 ,
V_18 -> V_16 , V_18 -> V_28 ,
& V_18 -> V_28 ) ;
if ( V_36 >= V_23 )
goto V_41;
V_37 = F_24 ( V_15 ) ;
V_38 = F_25 ( V_18 -> V_28 ) ;
V_36 += snprintf ( V_39 + V_36 , V_23 - V_36 ,
L_3 ,
V_35 ,
V_42 [ V_38 ] ,
V_35 >> V_43 ,
V_42 [ V_37 ] ,
V_15 -> V_20 , & V_15 -> V_20 ) ;
if ( V_36 >= V_23 )
goto V_41;
F_26 ( V_25 , & V_21 ) ;
V_36 += F_27 ( V_39 + V_36 , V_23 - V_36 , & V_21 , 0 ) ;
if ( V_36 >= V_23 )
goto V_41;
if ( V_18 -> V_29 != - 1 ) {
V_36 += snprintf ( V_39 + V_36 , V_23 - V_36 ,
L_4 ,
V_44 [ V_18 -> V_29 ] ) ;
if ( V_36 >= V_23 )
goto V_41;
}
V_36 += snprintf ( V_39 + V_36 , V_23 - V_36 , L_5 ) ;
if ( V_36 >= V_23 )
goto V_41;
if ( F_28 ( V_1 , V_39 , V_36 ) )
V_36 = - V_45 ;
F_29 ( V_39 ) ;
return V_36 ;
V_41:
F_29 ( V_39 ) ;
return - V_40 ;
}
void F_30 ( struct V_15 * V_15 )
{
struct V_18 * V_18 = F_12 ( V_15 ) ;
unsigned long V_4 [ V_24 ] ;
struct V_5 V_21 = {
. V_7 = 0 ,
. V_4 = V_4 ,
. V_8 = V_24 ,
. V_9 = 0
} ;
T_2 V_25 ;
T_3 V_28 ;
int V_46 ;
if ( F_13 ( ! V_18 ) ) {
F_31 ( L_6 ) ;
return;
}
V_28 = V_18 -> V_28 ;
V_46 = F_25 ( V_28 ) ;
if ( ! F_32 ( V_19 , & V_18 -> V_20 ) ) {
F_31 ( L_7 ) ;
return;
}
V_25 = F_33 ( V_18 -> V_25 ) ;
if ( ! V_25 ) {
F_31 ( L_7 ) ;
return;
}
F_26 ( V_25 , & V_21 ) ;
F_31 ( L_8 ,
V_18 -> V_16 , V_42 [ V_46 ] , V_28 , & V_28 ) ;
F_34 ( & V_21 , 0 ) ;
if ( V_18 -> V_29 != - 1 )
F_31 ( L_9 ,
V_44 [ V_18 -> V_29 ] ) ;
}
static T_4
F_35 ( struct V_47 * V_47 , char T_5 * V_1 , T_6 V_23 , T_7 * V_48 )
{
unsigned long V_35 ;
struct V_15 * V_15 ;
struct V_18 * V_18 ;
T_2 V_25 ;
if ( ! F_36 ( & V_14 ) )
return - V_2 ;
V_15 = NULL ;
V_35 = V_49 + * V_48 ;
while ( ! F_37 ( V_35 ) && ( V_35 & ( V_50 - 1 ) ) != 0 )
V_35 ++ ;
F_38 ( NULL ) ;
for (; V_35 < V_51 ; V_35 ++ ) {
if ( ( V_35 & ( V_50 - 1 ) ) == 0 && ! F_37 ( V_35 ) ) {
V_35 += V_50 - 1 ;
continue;
}
if ( ! F_39 ( V_35 ) )
continue;
V_15 = F_40 ( V_35 ) ;
if ( F_41 ( V_15 ) ) {
unsigned long V_52 = F_42 ( V_15 ) ;
if ( V_52 < V_53 )
V_35 += ( 1UL << V_52 ) - 1 ;
continue;
}
V_18 = F_12 ( V_15 ) ;
if ( F_13 ( ! V_18 ) )
continue;
if ( ! F_32 ( V_19 , & V_18 -> V_20 ) )
continue;
V_25 = F_33 ( V_18 -> V_25 ) ;
if ( ! V_25 )
continue;
* V_48 = ( V_35 - V_49 ) + 1 ;
return F_22 ( V_1 , V_23 , V_35 , V_15 ,
V_18 , V_25 ) ;
}
return 0 ;
}
static void F_43 ( T_8 * V_54 , struct V_55 * V_55 )
{
struct V_15 * V_15 ;
struct V_18 * V_18 ;
unsigned long V_35 = V_55 -> V_56 , V_57 ;
unsigned long V_58 = V_35 + V_55 -> V_59 ;
unsigned long V_23 = 0 ;
V_35 = V_55 -> V_56 ;
for (; V_35 < V_58 ; ) {
if ( ! F_37 ( V_35 ) ) {
V_35 = F_44 ( V_35 + 1 , V_50 ) ;
continue;
}
V_57 = F_44 ( V_35 + 1 , V_60 ) ;
V_57 = F_45 ( V_57 , V_58 ) ;
V_15 = F_40 ( V_35 ) ;
for (; V_35 < V_57 ; V_35 ++ ) {
if ( ! F_39 ( V_35 ) )
continue;
V_15 = F_40 ( V_35 ) ;
if ( F_46 ( V_15 ) != V_55 )
continue;
if ( F_41 ( V_15 ) ) {
V_35 += ( 1UL << F_47 ( V_15 ) ) - 1 ;
continue;
}
if ( F_48 ( V_15 ) )
continue;
V_18 = F_12 ( V_15 ) ;
if ( F_13 ( ! V_18 ) )
continue;
if ( F_32 ( V_19 , & V_18 -> V_20 ) )
continue;
F_49 ( V_15 , 0 , 0 ) ;
V_23 ++ ;
}
}
F_50 ( L_10 ,
V_54 -> V_61 , V_55 -> V_62 , V_23 ) ;
}
static void F_51 ( T_8 * V_54 )
{
struct V_55 * V_55 ;
struct V_55 * V_63 = V_54 -> V_63 ;
unsigned long V_20 ;
for ( V_55 = V_63 ; V_55 - V_63 < V_64 ; ++ V_55 ) {
if ( ! F_52 ( V_55 ) )
continue;
F_53 ( & V_55 -> V_65 , V_20 ) ;
F_43 ( V_54 , V_55 ) ;
F_54 ( & V_55 -> V_65 , V_20 ) ;
}
}
static void F_10 ( void )
{
T_8 * V_54 ;
F_38 ( NULL ) ;
F_55 (pgdat)
F_51 ( V_54 ) ;
}
static int T_9 F_56 ( void )
{
struct V_66 * V_66 ;
if ( ! F_36 ( & V_14 ) ) {
F_50 ( L_11 ) ;
return 0 ;
}
V_66 = F_57 ( L_12 , V_67 , NULL ,
NULL , & V_68 ) ;
if ( F_58 ( V_66 ) )
return F_59 ( V_66 ) ;
return 0 ;
}
