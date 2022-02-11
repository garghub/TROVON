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
static void F_3 ( void )
{
if ( V_3 )
return;
F_4 ( & V_4 ) ;
F_5 () ;
}
void F_6 ( struct V_5 * V_5 , unsigned int V_6 )
{
int V_7 ;
struct V_8 * V_8 ;
for ( V_7 = 0 ; V_7 < ( 1 << V_6 ) ; V_7 ++ ) {
V_8 = F_7 ( V_5 + V_7 ) ;
if ( F_8 ( ! V_8 ) )
continue;
F_9 ( V_9 , & V_8 -> V_10 ) ;
}
}
void F_10 ( struct V_5 * V_5 , unsigned int V_6 , T_1 V_11 )
{
struct V_8 * V_8 = F_7 ( V_5 ) ;
struct V_12 V_13 = {
. V_14 = 0 ,
. V_15 = F_11 ( V_8 -> V_16 ) ,
. V_17 = & V_8 -> V_16 [ 0 ] ,
. V_18 = 3 ,
} ;
if ( F_8 ( ! V_8 ) )
return;
F_12 ( & V_13 ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_14 = V_13 . V_14 ;
V_8 -> V_19 = - 1 ;
F_13 ( V_9 , & V_8 -> V_10 ) ;
}
void F_14 ( struct V_5 * V_5 , int V_20 )
{
struct V_8 * V_8 = F_7 ( V_5 ) ;
if ( F_8 ( ! V_8 ) )
return;
V_8 -> V_19 = V_20 ;
}
T_1 F_15 ( struct V_5 * V_5 )
{
struct V_8 * V_8 = F_7 ( V_5 ) ;
if ( F_8 ( ! V_8 ) )
return 0 ;
return V_8 -> V_11 ;
}
void F_16 ( struct V_5 * V_21 , struct V_5 * V_22 )
{
struct V_8 * V_23 = F_7 ( V_21 ) ;
struct V_8 * V_24 = F_7 ( V_22 ) ;
int V_7 ;
if ( F_8 ( ! V_23 || ! V_24 ) )
return;
V_24 -> V_6 = V_23 -> V_6 ;
V_24 -> V_11 = V_23 -> V_11 ;
V_24 -> V_14 = V_23 -> V_14 ;
for ( V_7 = 0 ; V_7 < F_11 ( V_24 -> V_16 ) ; V_7 ++ )
V_24 -> V_16 [ V_7 ] = V_23 -> V_16 [ V_7 ] ;
F_13 ( V_9 , & V_24 -> V_10 ) ;
}
static T_2
F_17 ( char T_3 * V_1 , T_4 V_25 , unsigned long V_26 ,
struct V_5 * V_5 , struct V_8 * V_8 )
{
int V_27 ;
int V_28 , V_29 ;
char * V_30 ;
struct V_12 V_13 = {
. V_14 = V_8 -> V_14 ,
. V_17 = & V_8 -> V_16 [ 0 ] ,
} ;
V_30 = F_18 ( V_25 , V_31 ) ;
if ( ! V_30 )
return - V_32 ;
V_27 = snprintf ( V_30 , V_25 ,
L_2 ,
V_8 -> V_6 , V_8 -> V_11 ,
& V_8 -> V_11 ) ;
if ( V_27 >= V_25 )
goto V_33;
V_28 = F_19 ( V_5 ) ;
V_29 = F_20 ( V_8 -> V_11 ) ;
V_27 += snprintf ( V_30 + V_27 , V_25 - V_27 ,
L_3 ,
V_26 ,
V_34 [ V_29 ] ,
V_26 >> V_35 ,
V_34 [ V_28 ] ,
V_5 -> V_10 , & V_5 -> V_10 ) ;
if ( V_27 >= V_25 )
goto V_33;
V_27 += F_21 ( V_30 + V_27 , V_25 - V_27 , & V_13 , 0 ) ;
if ( V_27 >= V_25 )
goto V_33;
if ( V_8 -> V_19 != - 1 ) {
V_27 += snprintf ( V_30 + V_27 , V_25 - V_27 ,
L_4 ,
V_36 [ V_8 -> V_19 ] ) ;
if ( V_27 >= V_25 )
goto V_33;
}
V_27 += snprintf ( V_30 + V_27 , V_25 - V_27 , L_5 ) ;
if ( V_27 >= V_25 )
goto V_33;
if ( F_22 ( V_1 , V_30 , V_27 ) )
V_27 = - V_37 ;
F_23 ( V_30 ) ;
return V_27 ;
V_33:
F_23 ( V_30 ) ;
return - V_32 ;
}
void F_24 ( struct V_5 * V_5 )
{
struct V_8 * V_8 = F_7 ( V_5 ) ;
struct V_12 V_13 = {
. V_14 = V_8 -> V_14 ,
. V_17 = & V_8 -> V_16 [ 0 ] ,
} ;
T_1 V_11 ;
int V_38 ;
if ( F_8 ( ! V_8 ) ) {
F_25 ( L_6 ) ;
return;
}
V_11 = V_8 -> V_11 ;
V_38 = F_20 ( V_11 ) ;
if ( ! F_26 ( V_9 , & V_8 -> V_10 ) ) {
F_25 ( L_7 ) ;
return;
}
F_25 ( L_8 ,
V_8 -> V_6 , V_34 [ V_38 ] , V_11 , & V_11 ) ;
F_27 ( & V_13 , 0 ) ;
if ( V_8 -> V_19 != - 1 )
F_25 ( L_9 ,
V_36 [ V_8 -> V_19 ] ) ;
}
static T_2
F_28 ( struct V_39 * V_39 , char T_3 * V_1 , T_4 V_25 , T_5 * V_40 )
{
unsigned long V_26 ;
struct V_5 * V_5 ;
struct V_8 * V_8 ;
if ( ! F_29 ( & V_4 ) )
return - V_2 ;
V_5 = NULL ;
V_26 = V_41 + * V_40 ;
while ( ! F_30 ( V_26 ) && ( V_26 & ( V_42 - 1 ) ) != 0 )
V_26 ++ ;
F_31 ( NULL ) ;
for (; V_26 < V_43 ; V_26 ++ ) {
if ( ( V_26 & ( V_42 - 1 ) ) == 0 && ! F_30 ( V_26 ) ) {
V_26 += V_42 - 1 ;
continue;
}
if ( ! F_32 ( V_26 ) )
continue;
V_5 = F_33 ( V_26 ) ;
if ( F_34 ( V_5 ) ) {
unsigned long V_44 = F_35 ( V_5 ) ;
if ( V_44 < V_45 )
V_26 += ( 1UL << V_44 ) - 1 ;
continue;
}
V_8 = F_7 ( V_5 ) ;
if ( F_8 ( ! V_8 ) )
continue;
if ( ! F_26 ( V_9 , & V_8 -> V_10 ) )
continue;
* V_40 = ( V_26 - V_41 ) + 1 ;
return F_17 ( V_1 , V_25 , V_26 , V_5 , V_8 ) ;
}
return 0 ;
}
static void F_36 ( T_6 * V_46 , struct V_47 * V_47 )
{
struct V_5 * V_5 ;
struct V_8 * V_8 ;
unsigned long V_26 = V_47 -> V_48 , V_49 ;
unsigned long V_50 = V_26 + V_47 -> V_51 ;
unsigned long V_25 = 0 ;
V_26 = V_47 -> V_48 ;
for (; V_26 < V_50 ; ) {
if ( ! F_30 ( V_26 ) ) {
V_26 = F_37 ( V_26 + 1 , V_42 ) ;
continue;
}
V_49 = F_37 ( V_26 + 1 , V_52 ) ;
V_49 = F_38 ( V_49 , V_50 ) ;
V_5 = F_33 ( V_26 ) ;
for (; V_26 < V_49 ; V_26 ++ ) {
if ( ! F_32 ( V_26 ) )
continue;
V_5 = F_33 ( V_26 ) ;
if ( F_39 ( V_5 ) != V_47 )
continue;
if ( F_34 ( V_5 ) ) {
V_26 += ( 1UL << F_40 ( V_5 ) ) - 1 ;
continue;
}
if ( F_41 ( V_5 ) )
continue;
V_8 = F_7 ( V_5 ) ;
if ( F_8 ( ! V_8 ) )
continue;
if ( F_26 ( V_9 , & V_8 -> V_10 ) )
continue;
F_42 ( V_5 , 0 , 0 ) ;
V_25 ++ ;
}
}
F_43 ( L_10 ,
V_46 -> V_53 , V_47 -> V_54 , V_25 ) ;
}
static void F_44 ( T_6 * V_46 )
{
struct V_47 * V_47 ;
struct V_47 * V_55 = V_46 -> V_55 ;
unsigned long V_10 ;
for ( V_47 = V_55 ; V_47 - V_55 < V_56 ; ++ V_47 ) {
if ( ! F_45 ( V_47 ) )
continue;
F_46 ( & V_47 -> V_57 , V_10 ) ;
F_36 ( V_46 , V_47 ) ;
F_47 ( & V_47 -> V_57 , V_10 ) ;
}
}
static void F_5 ( void )
{
T_6 * V_46 ;
F_31 ( NULL ) ;
F_48 (pgdat)
F_44 ( V_46 ) ;
}
static int T_7 F_49 ( void )
{
struct V_58 * V_58 ;
if ( ! F_29 ( & V_4 ) ) {
F_43 ( L_11 ) ;
return 0 ;
}
V_58 = F_50 ( L_12 , V_59 , NULL ,
NULL , & V_60 ) ;
if ( F_51 ( V_58 ) )
return F_52 ( V_58 ) ;
return 0 ;
}
