static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
return V_2 -> V_4 == V_3 ;
}
static int F_2 ( struct V_1 * V_2 , void * V_3 )
{
int V_5 = F_3 ( V_2 , NULL ) ;
if ( ! V_5 ) {
struct V_6 * V_7 = (struct V_6 * ) V_3 ;
V_2 -> V_4 = F_4 ( V_7 ) ;
}
return V_5 ;
}
static int F_5 ( char * V_8 , struct V_6 * V_9 )
{
char * V_10 ;
T_1 args [ V_11 ] ;
int V_12 ;
if ( ! V_8 )
return 1 ;
while ( ( V_10 = F_6 ( & V_8 , L_1 ) ) != NULL ) {
int V_13 ;
if ( ! * V_10 )
continue;
args [ 0 ] . V_14 = args [ 0 ] . V_15 = 0 ;
V_13 = F_7 ( V_10 , V_16 , args ) ;
switch ( V_13 ) {
case V_17 :
if ( F_8 ( & args [ 0 ] , & V_12 ) )
return 0 ;
V_9 -> V_18 = F_9 ( F_10 () , V_12 ) ;
break;
case V_19 :
if ( F_8 ( & args [ 0 ] , & V_12 ) )
return 0 ;
if ( V_12 < 0 || V_12 > 2 ) {
F_11 ( L_2 ) ;
return 0 ;
}
V_9 -> V_20 = V_12 ;
break;
default:
F_11 ( L_3
L_4 , V_10 ) ;
return 0 ;
}
}
return 1 ;
}
int F_12 ( struct V_1 * V_2 , int * V_21 , char * V_3 )
{
struct V_6 * V_9 = V_2 -> V_4 ;
return ! F_5 ( V_3 , V_9 ) ;
}
static struct V_22 * F_13 ( struct V_23 * V_24 ,
int V_21 , const char * V_25 , void * V_3 )
{
int V_5 ;
struct V_1 * V_2 ;
struct V_6 * V_7 ;
struct V_26 * V_27 ;
char * V_8 ;
if ( V_21 & V_28 ) {
V_7 = (struct V_6 * ) V_3 ;
V_8 = NULL ;
} else {
V_7 = V_29 -> V_30 -> V_31 ;
V_8 = V_3 ;
}
V_2 = F_14 ( V_24 , F_1 , F_2 , V_21 , V_7 ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
if ( ! F_5 ( V_8 , V_7 ) ) {
F_17 ( V_2 ) ;
return F_18 ( - V_32 ) ;
}
if ( ! V_2 -> V_33 ) {
V_5 = F_19 ( V_2 ) ;
if ( V_5 ) {
F_17 ( V_2 ) ;
return F_18 ( V_5 ) ;
}
V_2 -> V_34 |= V_35 ;
}
V_27 = F_20 ( V_2 -> V_33 -> V_36 ) ;
if ( ! V_27 -> V_9 ) {
F_21 () ;
V_27 -> V_9 = F_22 ( F_23 ( 1 , V_7 ) ) ;
F_24 () ;
}
return F_25 ( V_2 -> V_33 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) V_2 -> V_4 ;
F_27 ( V_2 ) ;
F_28 ( V_7 ) ;
}
void T_2 F_29 ( void )
{
int V_5 ;
F_30 () ;
V_5 = F_31 ( & V_37 ) ;
if ( V_5 )
return;
V_5 = F_32 ( & V_38 ) ;
if ( V_5 ) {
F_33 ( & V_37 ) ;
return;
}
F_34 ( L_5 , NULL , L_6 ) ;
F_35 () ;
#ifdef F_36
F_37 ( L_7 , NULL ) ;
#endif
F_37 ( L_8 , NULL ) ;
F_37 ( L_9 , NULL ) ;
F_37 ( L_10 , NULL ) ;
#if F_38 ( V_39 ) || F_38 ( V_40 )
F_37 ( L_11 , NULL ) ;
#endif
F_39 () ;
#ifdef F_40
F_41 () ;
#endif
F_37 ( L_12 , NULL ) ;
F_42 () ;
}
static int F_43 ( struct V_41 * V_42 , struct V_22 * V_22 , struct V_43 * V_44
)
{
F_44 ( V_22 -> V_36 , V_44 ) ;
V_44 -> V_45 = V_46 . V_45 + F_45 () ;
return 0 ;
}
static struct V_22 * F_46 ( struct V_47 * V_48 , struct V_22 * V_22 , unsigned int V_21 )
{
if ( ! F_47 ( V_48 , V_22 , V_21 ) )
return NULL ;
return F_48 ( V_48 , V_22 , V_21 ) ;
}
static int F_49 ( struct V_49 * V_50 ,
void * V_51 , T_3 V_52 )
{
unsigned int V_53 = V_50 -> V_54 ;
int V_55 ;
if ( V_53 < V_56 ) {
int error = F_50 ( V_50 , V_51 , V_52 ) ;
if ( error <= 0 )
return error ;
V_50 -> V_54 = V_56 ;
}
V_55 = F_51 ( V_50 , V_51 , V_52 ) ;
return V_55 ;
}
int F_32 ( struct V_6 * V_7 )
{
struct V_41 * V_42 ;
V_42 = F_52 ( & V_37 , V_7 ) ;
if ( F_15 ( V_42 ) )
return F_53 ( V_42 ) ;
V_7 -> V_57 = V_42 ;
return 0 ;
}
void F_54 ( struct V_6 * V_7 )
{
F_55 ( V_7 -> V_57 ) ;
}
