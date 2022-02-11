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
V_9 -> V_18 = V_12 ;
break;
case V_19 :
if ( F_8 ( & args [ 0 ] , & V_12 ) )
return 0 ;
if ( V_12 < 0 || V_12 > 2 ) {
F_9 ( L_2 ) ;
return 0 ;
}
V_9 -> V_20 = V_12 ;
break;
default:
F_9 ( L_3
L_4 , V_10 ) ;
return 0 ;
}
}
return 1 ;
}
int F_10 ( struct V_1 * V_2 , int * V_21 , char * V_3 )
{
struct V_6 * V_9 = V_2 -> V_4 ;
return ! F_5 ( V_3 , V_9 ) ;
}
static struct V_22 * F_11 ( struct V_23 * V_24 ,
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
V_2 = F_12 ( V_24 , F_1 , F_2 , V_7 ) ;
if ( F_13 ( V_2 ) )
return F_14 ( V_2 ) ;
if ( ! F_5 ( V_8 , V_7 ) ) {
F_15 ( V_2 ) ;
return F_16 ( - V_32 ) ;
}
if ( ! V_2 -> V_33 ) {
V_2 -> V_34 = V_21 ;
V_5 = F_17 ( V_2 ) ;
if ( V_5 ) {
F_15 ( V_2 ) ;
return F_16 ( V_5 ) ;
}
V_2 -> V_34 |= V_35 ;
}
V_27 = F_18 ( V_2 -> V_33 -> V_36 ) ;
if ( ! V_27 -> V_9 ) {
F_19 () ;
V_27 -> V_9 = F_20 ( F_21 ( 1 , V_7 ) ) ;
F_22 () ;
}
return F_23 ( V_2 -> V_33 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) V_2 -> V_4 ;
F_25 ( V_2 ) ;
F_26 ( V_7 ) ;
}
void T_2 F_27 ( void )
{
int V_5 ;
F_28 () ;
V_5 = F_29 ( & V_37 ) ;
if ( V_5 )
return;
V_5 = F_30 ( & V_38 ) ;
if ( V_5 ) {
F_31 ( & V_37 ) ;
return;
}
F_32 ( L_5 , NULL , L_6 ) ;
F_33 () ;
#ifdef F_34
F_35 ( L_7 , NULL ) ;
#endif
F_35 ( L_8 , NULL ) ;
F_35 ( L_9 , NULL ) ;
F_35 ( L_10 , NULL ) ;
#if F_36 ( V_39 ) || F_36 ( V_40 )
F_35 ( L_11 , NULL ) ;
#endif
F_37 () ;
#ifdef F_38
F_39 () ;
#endif
F_35 ( L_12 , NULL ) ;
F_40 () ;
}
static int F_41 ( struct V_41 * V_42 , struct V_22 * V_22 , struct V_43 * V_44
)
{
F_42 ( V_22 -> V_36 , V_44 ) ;
V_44 -> V_45 = V_46 . V_45 + F_43 () ;
return 0 ;
}
static struct V_22 * F_44 ( struct V_47 * V_48 , struct V_22 * V_22 , struct V_49 * V_50 )
{
if ( ! F_45 ( V_48 , V_22 , V_50 ) ) {
return NULL ;
}
return F_46 ( V_48 , V_22 , V_50 ) ;
}
static int F_47 ( struct V_51 * V_52 ,
void * V_53 , T_3 V_54 )
{
unsigned int V_55 = V_52 -> V_56 ;
int V_57 ;
if ( V_55 < V_58 ) {
int error = F_48 ( V_52 , V_53 , V_54 ) ;
if ( error <= 0 )
return error ;
V_52 -> V_56 = V_58 ;
}
V_57 = F_49 ( V_52 , V_53 , V_54 ) ;
return V_57 ;
}
int F_30 ( struct V_6 * V_7 )
{
struct V_41 * V_42 ;
V_42 = F_50 ( & V_37 , V_7 ) ;
if ( F_13 ( V_42 ) )
return F_51 ( V_42 ) ;
V_7 -> V_59 = V_42 ;
return 0 ;
}
void F_52 ( struct V_6 * V_7 )
{
F_53 ( V_7 -> V_59 ) ;
}
