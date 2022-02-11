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
if ( V_6 < V_14 ||
V_6 > V_15 ) {
F_7 ( L_2 ) ;
return 0 ;
}
V_3 -> V_16 = V_6 ;
break;
default:
F_7 ( L_3
L_4 , V_4 ) ;
return 0 ;
}
}
return 1 ;
}
int F_8 ( struct V_17 * V_18 , int * V_19 , char * V_20 )
{
struct V_2 * V_3 = V_18 -> V_21 ;
F_9 ( V_18 ) ;
return ! F_1 ( V_20 , V_3 ) ;
}
static struct V_22 * F_10 ( struct V_23 * V_24 ,
int V_19 , const char * V_25 , void * V_20 )
{
struct V_2 * V_26 ;
if ( V_19 & V_27 ) {
V_26 = V_20 ;
V_20 = NULL ;
} else {
V_26 = F_11 ( V_28 ) ;
}
return F_12 ( V_24 , V_19 , V_20 , V_26 , V_26 -> V_29 , V_30 ) ;
}
static void F_13 ( struct V_17 * V_18 )
{
struct V_2 * V_26 ;
V_26 = (struct V_2 * ) V_18 -> V_21 ;
if ( V_26 -> V_31 )
F_14 ( V_26 -> V_31 ) ;
if ( V_26 -> V_32 )
F_14 ( V_26 -> V_32 ) ;
F_15 ( V_18 ) ;
F_16 ( V_26 ) ;
}
void T_2 F_17 ( void )
{
int V_33 ;
F_18 () ;
F_19 () ;
V_33 = F_20 ( & V_34 ) ;
if ( V_33 )
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
#if F_28 ( V_35 ) || F_28 ( V_36 )
F_27 ( L_11 ) ;
#endif
F_29 () ;
F_26 ( L_12 , NULL ) ;
F_30 () ;
}
static int F_31 ( const struct V_37 * V_37 , struct V_38 * V_39 ,
T_3 V_40 , unsigned int V_41 )
{
F_32 ( F_33 ( V_37 -> V_22 ) , V_39 ) ;
V_39 -> V_42 = V_43 . V_42 + F_34 () ;
return 0 ;
}
static struct V_22 * F_35 ( struct V_44 * V_45 , struct V_22 * V_22 , unsigned int V_19 )
{
if ( ! F_36 ( V_45 , V_22 , V_19 ) )
return NULL ;
return F_37 ( V_45 , V_22 , V_19 ) ;
}
static int F_38 ( struct V_46 * V_46 , struct V_47 * V_48 )
{
if ( V_48 -> V_49 < V_50 ) {
int error = F_39 ( V_46 , V_48 ) ;
if ( F_40 ( error <= 0 ) )
return error ;
V_48 -> V_49 = V_50 ;
}
return F_41 ( V_46 , V_48 ) ;
}
int F_42 ( struct V_2 * V_26 )
{
struct V_51 * V_52 ;
V_52 = F_43 ( & V_34 , V_26 ) ;
if ( F_44 ( V_52 ) )
return F_45 ( V_52 ) ;
V_26 -> V_53 = V_52 ;
return 0 ;
}
void F_46 ( struct V_2 * V_26 )
{
F_47 ( V_26 -> V_53 ) ;
}
