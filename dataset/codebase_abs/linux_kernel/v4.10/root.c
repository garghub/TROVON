int F_1 ( char * V_1 , struct V_2 * V_3 )
{
char * V_4 ;
T_1 args [ V_5 ] ;
int V_6 ;
if ( ! V_1 )
return 1 ;
while ( ( V_4 = F_2 ( & V_1 , L_1 ) ) != NULL ) {
int V_7 ;
if ( ! * V_4 )
continue;
args [ 0 ] . V_8 = args [ 0 ] . V_9 = NULL ;
V_7 = F_3 ( V_4 , V_10 , args ) ;
switch ( V_7 ) {
case V_11 :
if ( F_4 ( & args [ 0 ] , & V_6 ) )
return 0 ;
V_3 -> V_12 = F_5 ( F_6 () , V_6 ) ;
break;
case V_13 :
if ( F_4 ( & args [ 0 ] , & V_6 ) )
return 0 ;
if ( V_6 < 0 || V_6 > 2 ) {
F_7 ( L_2 ) ;
return 0 ;
}
V_3 -> V_14 = V_6 ;
break;
default:
F_7 ( L_3
L_4 , V_4 ) ;
return 0 ;
}
}
return 1 ;
}
int F_8 ( struct V_15 * V_16 , int * V_17 , char * V_18 )
{
struct V_2 * V_3 = V_16 -> V_19 ;
F_9 ( V_16 ) ;
return ! F_1 ( V_18 , V_3 ) ;
}
static struct V_20 * F_10 ( struct V_21 * V_22 ,
int V_17 , const char * V_23 , void * V_18 )
{
struct V_2 * V_24 ;
if ( V_17 & V_25 ) {
V_24 = V_18 ;
V_18 = NULL ;
} else {
V_24 = F_11 ( V_26 ) ;
}
return F_12 ( V_22 , V_17 , V_18 , V_24 , V_24 -> V_27 , V_28 ) ;
}
static void F_13 ( struct V_15 * V_16 )
{
struct V_2 * V_24 ;
V_24 = (struct V_2 * ) V_16 -> V_19 ;
if ( V_24 -> V_29 )
F_14 ( V_24 -> V_29 ) ;
if ( V_24 -> V_30 )
F_14 ( V_24 -> V_30 ) ;
F_15 ( V_16 ) ;
F_16 ( V_24 ) ;
}
void T_2 F_17 ( void )
{
int V_31 ;
F_18 () ;
F_19 () ;
V_31 = F_20 ( & V_32 ) ;
if ( V_31 )
return;
F_21 () ;
F_22 () ;
F_23 ( L_5 , NULL , L_6 ) ;
F_24 () ;
#ifdef F_25
F_26 ( L_7 , NULL ) ;
#endif
F_26 ( L_8 , NULL ) ;
F_26 ( L_9 , NULL ) ;
F_27 ( L_10 ) ;
#if F_28 ( V_33 ) || F_28 ( V_34 )
F_27 ( L_11 ) ;
#endif
F_29 () ;
F_26 ( L_12 , NULL ) ;
F_30 () ;
}
static int F_31 ( struct V_35 * V_36 , struct V_20 * V_20 , struct V_37 * V_38
)
{
F_32 ( F_33 ( V_20 ) , V_38 ) ;
V_38 -> V_39 = V_40 . V_39 + F_34 () ;
return 0 ;
}
static struct V_20 * F_35 ( struct V_41 * V_42 , struct V_20 * V_20 , unsigned int V_17 )
{
if ( ! F_36 ( V_42 , V_20 , V_17 ) )
return NULL ;
return F_37 ( V_42 , V_20 , V_17 ) ;
}
static int F_38 ( struct V_43 * V_43 , struct V_44 * V_45 )
{
if ( V_45 -> V_46 < V_47 ) {
int error = F_39 ( V_43 , V_45 ) ;
if ( F_40 ( error <= 0 ) )
return error ;
V_45 -> V_46 = V_47 ;
}
return F_41 ( V_43 , V_45 ) ;
}
int F_42 ( struct V_2 * V_24 )
{
struct V_35 * V_36 ;
V_36 = F_43 ( & V_32 , V_24 ) ;
if ( F_44 ( V_36 ) )
return F_45 ( V_36 ) ;
V_24 -> V_48 = V_36 ;
return 0 ;
}
void F_46 ( struct V_2 * V_24 )
{
F_47 ( V_24 -> V_48 ) ;
}
