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
F_13 ( V_2 ) ;
return ! F_5 ( V_3 , V_9 ) ;
}
static struct V_22 * F_14 ( struct V_23 * V_24 ,
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
V_7 = F_15 ( V_27 ) ;
V_8 = V_3 ;
if ( ! F_16 ( V_7 -> V_28 , V_29 ) )
return F_17 ( - V_30 ) ;
}
V_2 = F_18 ( V_24 , F_1 , F_2 , V_21 , V_7 ) ;
if ( F_19 ( V_2 ) )
return F_20 ( V_2 ) ;
if ( ! F_5 ( V_8 , V_7 ) ) {
F_21 ( V_2 ) ;
return F_17 ( - V_31 ) ;
}
if ( ! V_2 -> V_32 ) {
V_5 = F_22 ( V_2 ) ;
if ( V_5 ) {
F_21 ( V_2 ) ;
return F_17 ( V_5 ) ;
}
V_2 -> V_33 |= V_34 ;
}
return F_23 ( V_2 -> V_32 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) V_2 -> V_4 ;
if ( V_7 -> V_35 )
F_25 ( V_7 -> V_35 ) ;
if ( V_7 -> V_36 )
F_25 ( V_7 -> V_36 ) ;
F_26 ( V_2 ) ;
F_27 ( V_7 ) ;
}
void T_2 F_28 ( void )
{
int V_5 ;
F_29 () ;
V_5 = F_30 ( & V_37 ) ;
if ( V_5 )
return;
F_31 () ;
F_32 () ;
F_33 ( L_5 , NULL , L_6 ) ;
F_34 () ;
#ifdef F_35
F_36 ( L_7 , NULL ) ;
#endif
F_36 ( L_8 , NULL ) ;
F_36 ( L_9 , NULL ) ;
F_37 ( L_10 ) ;
#if F_38 ( V_38 ) || F_38 ( V_39 )
F_37 ( L_11 ) ;
#endif
F_39 () ;
F_36 ( L_12 , NULL ) ;
F_40 () ;
}
static int F_41 ( struct V_40 * V_41 , struct V_22 * V_22 , struct V_42 * V_43
)
{
F_42 ( F_43 ( V_22 ) , V_43 ) ;
V_43 -> V_44 = V_45 . V_44 + F_44 () ;
return 0 ;
}
static struct V_22 * F_45 ( struct V_46 * V_47 , struct V_22 * V_22 , unsigned int V_21 )
{
if ( ! F_46 ( V_47 , V_22 , V_21 ) )
return NULL ;
return F_47 ( V_47 , V_22 , V_21 ) ;
}
static int F_48 ( struct V_48 * V_48 , struct V_49 * V_50 )
{
if ( V_50 -> V_51 < V_52 ) {
int error = F_49 ( V_48 , V_50 ) ;
if ( F_50 ( error <= 0 ) )
return error ;
V_50 -> V_51 = V_52 ;
}
return F_51 ( V_48 , V_50 ) ;
}
int F_52 ( struct V_6 * V_7 )
{
struct V_40 * V_41 ;
V_41 = F_53 ( & V_37 , V_7 ) ;
if ( F_19 ( V_41 ) )
return F_54 ( V_41 ) ;
V_7 -> V_53 = V_41 ;
return 0 ;
}
void F_55 ( struct V_6 * V_7 )
{
F_56 ( V_7 -> V_53 ) ;
}
