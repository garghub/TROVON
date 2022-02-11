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
V_4 = true ;
F_4 () ;
}
void F_5 ( struct V_5 * V_5 , unsigned int V_6 )
{
int V_7 ;
struct V_8 * V_8 ;
for ( V_7 = 0 ; V_7 < ( 1 << V_6 ) ; V_7 ++ ) {
V_8 = F_6 ( V_5 + V_7 ) ;
F_7 ( V_9 , & V_8 -> V_10 ) ;
}
}
void F_8 ( struct V_5 * V_5 , unsigned int V_6 , T_1 V_11 )
{
struct V_8 * V_8 = F_6 ( V_5 ) ;
struct V_12 V_13 = {
. V_14 = 0 ,
. V_15 = F_9 ( V_8 -> V_16 ) ,
. V_17 = & V_8 -> V_16 [ 0 ] ,
. V_18 = 3 ,
} ;
F_10 ( & V_13 ) ;
V_8 -> V_6 = V_6 ;
V_8 -> V_11 = V_11 ;
V_8 -> V_14 = V_13 . V_14 ;
F_11 ( V_9 , & V_8 -> V_10 ) ;
}
T_1 F_12 ( struct V_5 * V_5 )
{
struct V_8 * V_8 = F_6 ( V_5 ) ;
return V_8 -> V_11 ;
}
static T_2
F_13 ( char T_3 * V_1 , T_4 V_19 , unsigned long V_20 ,
struct V_5 * V_5 , struct V_8 * V_8 )
{
int V_21 ;
int V_22 , V_23 ;
char * V_24 ;
struct V_12 V_13 = {
. V_14 = V_8 -> V_14 ,
. V_17 = & V_8 -> V_16 [ 0 ] ,
} ;
V_24 = F_14 ( V_19 , V_25 ) ;
if ( ! V_24 )
return - V_26 ;
V_21 = snprintf ( V_24 , V_19 ,
L_2 ,
V_8 -> V_6 , V_8 -> V_11 ) ;
if ( V_21 >= V_19 )
goto V_27;
V_22 = F_15 ( V_5 , V_20 ) ;
V_23 = F_16 ( V_8 -> V_11 ) ;
V_21 += snprintf ( V_24 + V_21 , V_19 - V_21 ,
L_3 ,
V_20 ,
V_20 >> V_28 ,
V_22 ,
V_22 != V_23 ? L_4 : L_5 ,
F_17 ( V_5 ) ? L_6 : L_7 ,
F_18 ( V_5 ) ? L_8 : L_7 ,
F_19 ( V_5 ) ? L_9 : L_7 ,
F_20 ( V_5 ) ? L_10 : L_7 ,
F_21 ( V_5 ) ? L_11 : L_7 ,
F_22 ( V_5 ) ? L_12 : L_7 ,
F_23 ( V_5 ) ? L_13 : L_7 ,
F_24 ( V_5 ) ? L_14 : L_7 ,
F_25 ( V_5 ) ? L_15 : L_7 ,
F_26 ( V_5 ) ? L_16 : L_7 ,
F_27 ( V_5 ) ? L_17 : L_7 ,
F_28 ( V_5 ) ? L_18 : L_7 ) ;
if ( V_21 >= V_19 )
goto V_27;
V_21 += F_29 ( V_24 + V_21 , V_19 - V_21 , & V_13 , 0 ) ;
if ( V_21 >= V_19 )
goto V_27;
V_21 += snprintf ( V_24 + V_21 , V_19 - V_21 , L_19 ) ;
if ( V_21 >= V_19 )
goto V_27;
if ( F_30 ( V_1 , V_24 , V_21 ) )
V_21 = - V_29 ;
F_31 ( V_24 ) ;
return V_21 ;
V_27:
F_31 ( V_24 ) ;
return - V_26 ;
}
static T_2
F_32 ( struct V_30 * V_30 , char T_3 * V_1 , T_4 V_19 , T_5 * V_31 )
{
unsigned long V_20 ;
struct V_5 * V_5 ;
struct V_8 * V_8 ;
if ( ! V_4 )
return - V_2 ;
V_5 = NULL ;
V_20 = V_32 + * V_31 ;
while ( ! F_33 ( V_20 ) && ( V_20 & ( V_33 - 1 ) ) != 0 )
V_20 ++ ;
F_34 ( NULL ) ;
for (; V_20 < V_34 ; V_20 ++ ) {
if ( ( V_20 & ( V_33 - 1 ) ) == 0 && ! F_33 ( V_20 ) ) {
V_20 += V_33 - 1 ;
continue;
}
if ( ! F_35 ( V_20 ) )
continue;
V_5 = F_36 ( V_20 ) ;
if ( F_37 ( V_5 ) ) {
unsigned long V_35 = F_38 ( V_5 ) ;
if ( V_35 < V_36 )
V_20 += ( 1UL << V_35 ) - 1 ;
continue;
}
V_8 = F_6 ( V_5 ) ;
if ( ! F_39 ( V_9 , & V_8 -> V_10 ) )
continue;
* V_31 = ( V_20 - V_32 ) + 1 ;
return F_13 ( V_1 , V_19 , V_20 , V_5 , V_8 ) ;
}
return 0 ;
}
static void F_40 ( T_6 * V_37 , struct V_38 * V_38 )
{
struct V_5 * V_5 ;
struct V_8 * V_8 ;
unsigned long V_20 = V_38 -> V_39 , V_40 ;
unsigned long V_41 = V_20 + V_38 -> V_42 ;
unsigned long V_19 = 0 ;
V_20 = V_38 -> V_39 ;
for (; V_20 < V_41 ; ) {
if ( ! F_33 ( V_20 ) ) {
V_20 = F_41 ( V_20 + 1 , V_33 ) ;
continue;
}
V_40 = F_41 ( V_20 + 1 , V_43 ) ;
V_40 = F_42 ( V_40 , V_41 ) ;
V_5 = F_36 ( V_20 ) ;
for (; V_20 < V_40 ; V_20 ++ ) {
if ( ! F_35 ( V_20 ) )
continue;
V_5 = F_36 ( V_20 ) ;
if ( F_37 ( V_5 ) ) {
V_20 += ( 1UL << F_43 ( V_5 ) ) - 1 ;
continue;
}
if ( F_44 ( V_5 ) )
continue;
V_8 = F_6 ( V_5 ) ;
if ( F_39 ( V_9 , & V_8 -> V_10 ) )
continue;
F_45 ( V_5 , 0 , 0 ) ;
V_19 ++ ;
}
}
F_46 ( L_20 ,
V_37 -> V_44 , V_38 -> V_45 , V_19 ) ;
}
static void F_47 ( T_6 * V_37 )
{
struct V_38 * V_38 ;
struct V_38 * V_46 = V_37 -> V_46 ;
unsigned long V_10 ;
for ( V_38 = V_46 ; V_38 - V_46 < V_47 ; ++ V_38 ) {
if ( ! F_48 ( V_38 ) )
continue;
F_49 ( & V_38 -> V_48 , V_10 ) ;
F_40 ( V_37 , V_38 ) ;
F_50 ( & V_38 -> V_48 , V_10 ) ;
}
}
static void F_4 ( void )
{
T_6 * V_37 ;
F_34 ( NULL ) ;
F_51 (pgdat)
F_47 ( V_37 ) ;
}
static int T_7 F_52 ( void )
{
struct V_49 * V_49 ;
if ( ! V_4 ) {
F_46 ( L_21 ) ;
return 0 ;
}
V_49 = F_53 ( L_22 , V_50 , NULL ,
NULL , & V_51 ) ;
if ( F_54 ( V_49 ) )
return F_55 ( V_49 ) ;
return 0 ;
}
