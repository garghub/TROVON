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
args [ 0 ] . V_14 = args [ 0 ] . V_15 = NULL ;
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
char * V_8 ;
if ( V_21 & V_26 ) {
V_7 = (struct V_6 * ) V_3 ;
V_8 = NULL ;
} else {
V_7 = F_14 ( V_27 ) ;
V_8 = V_3 ;
if ( ! F_10 () -> V_28 )
return F_15 ( - V_29 ) ;
}
V_2 = F_16 ( V_24 , F_1 , F_2 , V_21 , V_7 ) ;
if ( F_17 ( V_2 ) )
return F_18 ( V_2 ) ;
if ( ! F_5 ( V_8 , V_7 ) ) {
F_19 ( V_2 ) ;
return F_15 ( - V_30 ) ;
}
if ( ! V_2 -> V_31 ) {
V_5 = F_20 ( V_2 ) ;
if ( V_5 ) {
F_19 ( V_2 ) ;
return F_15 ( V_5 ) ;
}
V_2 -> V_32 |= V_33 ;
}
return F_21 ( V_2 -> V_31 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) V_2 -> V_4 ;
F_23 ( V_2 ) ;
F_24 ( V_7 ) ;
}
void T_2 F_25 ( void )
{
int V_5 ;
F_26 () ;
V_5 = F_27 ( & V_34 ) ;
if ( V_5 )
return;
F_28 () ;
F_29 ( L_5 , NULL , L_6 ) ;
F_30 () ;
#ifdef F_31
F_32 ( L_7 , NULL ) ;
#endif
F_32 ( L_8 , NULL ) ;
F_32 ( L_9 , NULL ) ;
F_32 ( L_10 , NULL ) ;
#if F_33 ( V_35 ) || F_33 ( V_36 )
F_32 ( L_11 , NULL ) ;
#endif
F_34 () ;
#ifdef F_35
F_36 () ;
#endif
F_32 ( L_12 , NULL ) ;
F_37 () ;
}
static int F_38 ( struct V_37 * V_38 , struct V_22 * V_22 , struct V_39 * V_40
)
{
F_39 ( V_22 -> V_41 , V_40 ) ;
V_40 -> V_42 = V_43 . V_42 + F_40 () ;
return 0 ;
}
static struct V_22 * F_41 ( struct V_44 * V_45 , struct V_22 * V_22 , unsigned int V_21 )
{
if ( ! F_42 ( V_45 , V_22 , V_21 ) )
return NULL ;
return F_43 ( V_45 , V_22 , V_21 ) ;
}
static int F_44 ( struct V_46 * V_47 ,
void * V_48 , T_3 V_49 )
{
unsigned int V_50 = V_47 -> V_51 ;
int V_52 ;
if ( V_50 < V_53 ) {
int error = F_45 ( V_47 , V_48 , V_49 ) ;
if ( error <= 0 )
return error ;
V_47 -> V_51 = V_53 ;
}
V_52 = F_46 ( V_47 , V_48 , V_49 ) ;
return V_52 ;
}
int F_47 ( struct V_6 * V_7 )
{
struct V_37 * V_38 ;
V_38 = F_48 ( & V_34 , V_7 ) ;
if ( F_17 ( V_38 ) )
return F_49 ( V_38 ) ;
V_7 -> V_54 = V_38 ;
return 0 ;
}
void F_50 ( struct V_6 * V_7 )
{
F_51 ( V_7 -> V_54 ) ;
}
