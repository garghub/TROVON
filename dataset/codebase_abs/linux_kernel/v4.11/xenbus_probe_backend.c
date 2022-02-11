static int F_1 ( char V_1 [ V_2 ] , const char * V_3 )
{
int V_4 , V_5 ;
const char * V_6 , * type , * V_7 ;
unsigned int V_8 ;
type = strchr ( V_3 , '/' ) ;
if ( ! type )
return - V_9 ;
type ++ ;
V_8 = strcspn ( type , L_1 ) ;
if ( ! V_8 || type [ V_8 ] != '/' )
return - V_9 ;
V_6 = strrchr ( V_3 , '/' ) + 1 ;
V_5 = F_2 ( V_10 , V_3 , L_2 , L_3 , & V_4 ,
L_4 , NULL , & V_7 ,
NULL ) ;
if ( V_5 )
return V_5 ;
if ( strlen ( V_7 ) == 0 )
V_5 = - V_11 ;
if ( ! V_5 && ! F_3 ( V_10 , V_7 , L_5 ) )
V_5 = - V_12 ;
F_4 ( V_7 ) ;
if ( V_5 )
return V_5 ;
if ( snprintf ( V_1 , V_2 , L_6 ,
V_8 , type , V_4 , V_6 ) >= V_2 )
return - V_13 ;
return 0 ;
}
static int F_5 ( struct V_14 * V_15 ,
struct V_16 * V_17 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
F_6 ( L_5 ) ;
if ( V_15 == NULL )
return - V_24 ;
V_19 = F_7 ( V_15 ) ;
V_23 = F_8 ( V_19 -> V_15 . V_23 , struct V_22 , V_23 ) ;
if ( F_9 ( V_17 , L_7 , V_19 -> V_25 ) )
return - V_26 ;
if ( F_9 ( V_17 , L_8 , V_19 -> V_25 ) )
return - V_26 ;
if ( F_9 ( V_17 , L_9 , V_19 -> V_3 ) )
return - V_26 ;
if ( F_9 ( V_17 , L_10 , V_23 -> V_27 ) )
return - V_26 ;
if ( V_15 -> V_28 ) {
V_21 = F_10 ( V_15 -> V_28 ) ;
if ( V_21 && V_21 -> V_29 )
return V_21 -> V_29 ( V_19 , V_17 ) ;
}
return 0 ;
}
static int F_11 ( struct V_22 * V_23 ,
const char * V_30 ,
const char * type ,
const char * V_31 )
{
char * V_3 ;
int V_5 ;
V_3 = F_12 ( V_32 , L_11 , V_30 , V_31 ) ;
if ( ! V_3 )
return - V_26 ;
F_6 ( L_12 , V_3 ) ;
V_5 = F_13 ( V_23 , type , V_3 ) ;
F_4 ( V_3 ) ;
return V_5 ;
}
static int F_14 ( struct V_22 * V_23 , const char * type ,
const char * V_4 )
{
char * V_3 ;
int V_5 = 0 ;
char * * V_30 ;
unsigned int V_33 , V_34 = 0 ;
F_6 ( L_5 ) ;
V_3 = F_12 ( V_32 , L_13 , V_23 -> V_27 , type , V_4 ) ;
if ( ! V_3 )
return - V_26 ;
V_30 = F_15 ( V_10 , V_3 , L_5 , & V_34 ) ;
if ( F_16 ( V_30 ) ) {
F_4 ( V_3 ) ;
return F_17 ( V_30 ) ;
}
for ( V_33 = 0 ; V_33 < V_34 ; V_33 ++ ) {
V_5 = F_11 ( V_23 , V_3 , type , V_30 [ V_33 ] ) ;
if ( V_5 )
break;
}
F_4 ( V_30 ) ;
F_4 ( V_3 ) ;
return V_5 ;
}
static void F_18 ( struct V_35 * V_36 ,
const char * V_37 , const char * V_38 )
{
F_19 ( V_36 , V_37 , V_38 , 0 ) ;
}
static void F_20 ( struct V_35 * V_36 ,
const char * V_37 , const char * V_38 )
{
F_6 ( L_5 ) ;
F_21 ( V_37 , & V_39 ) ;
}
static int F_22 ( struct V_18 * V_40 )
{
return F_23 ( V_40 , L_2 , L_4 ) ;
}
int F_24 ( struct V_18 * V_15 )
{
return ! ! F_25 ( V_15 -> V_3 , L_14 , 0 ) ;
}
int F_26 ( struct V_20 * V_21 , struct V_41 * V_42 ,
const char * V_43 )
{
V_21 -> V_44 = F_22 ;
return F_27 ( V_21 , & V_39 ,
V_42 , V_43 ) ;
}
static int F_28 ( struct V_45 * V_46 ,
unsigned long V_47 ,
void * V_48 )
{
F_29 ( & V_39 ) ;
F_30 ( & V_49 ) ;
return V_50 ;
}
static int T_1 F_31 ( void )
{
static struct V_45 V_51 = {
. V_52 = F_28
} ;
int V_5 ;
F_6 ( L_5 ) ;
V_5 = F_32 ( & V_39 . V_23 ) ;
if ( V_5 )
return V_5 ;
F_33 ( & V_51 ) ;
return 0 ;
}
