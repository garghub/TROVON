static int F_1 ( char V_1 [ V_2 ] , const char * V_3 )
{
V_3 = strchr ( V_3 , '/' ) ;
if ( ! V_3 || strlen ( V_3 + 1 ) >= V_2 ) {
F_2 ( V_4 L_1 , V_3 ) ;
return - V_5 ;
}
F_3 ( V_1 , V_3 + 1 , V_2 ) ;
if ( ! strchr ( V_1 , '/' ) ) {
F_2 ( V_4 L_2 , V_1 ) ;
return - V_5 ;
}
* strchr ( V_1 , '/' ) = '-' ;
return 0 ;
}
static int F_4 ( struct V_6 * V_7 , const char * type ,
const char * V_8 )
{
char * V_3 ;
int V_9 ;
V_3 = F_5 ( V_10 , L_3 , V_7 -> V_11 , type , V_8 ) ;
if ( ! V_3 )
return - V_12 ;
F_6 ( L_4 , V_3 ) ;
V_9 = F_7 ( V_7 , type , V_3 ) ;
F_8 ( V_3 ) ;
return V_9 ;
}
static int F_9 ( struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = F_10 ( V_14 ) ;
if ( F_11 ( V_16 , L_5 , V_18 -> V_19 ) )
return - V_12 ;
return 0 ;
}
static void F_12 ( struct V_20 * V_21 ,
const char * * V_22 , unsigned int V_23 )
{
F_13 ( V_21 , V_22 , V_23 , 1 ) ;
}
static void F_14 ( struct V_20 * V_21 ,
const char * * V_22 , unsigned int V_23 )
{
F_6 ( L_6 ) ;
F_15 ( V_22 [ V_24 ] , & V_25 ) ;
}
static int F_16 ( struct V_17 * V_26 )
{
return F_17 ( V_26 , L_7 , L_8 ) ;
}
static int F_18 ( struct V_13 * V_18 , void * V_27 )
{
struct V_17 * V_26 = F_10 ( V_18 ) ;
struct V_28 * V_29 = V_27 ;
struct V_30 * V_31 ;
if ( ! V_18 -> V_32 )
return 0 ;
if ( V_29 && ( V_18 -> V_32 != V_29 ) )
return 0 ;
V_31 = F_19 ( V_18 -> V_32 ) ;
return ( V_26 -> V_33 < V_34 ||
( V_26 -> V_33 == V_34 &&
V_31 -> V_35 && ! V_31 -> V_35 ( V_26 ) ) ) ;
}
static int F_20 ( struct V_28 * V_29 )
{
return F_21 ( & V_25 . V_7 , NULL , V_29 ,
F_18 ) ;
}
static int F_22 ( struct V_13 * V_18 , void * V_27 )
{
struct V_17 * V_26 = F_10 ( V_18 ) ;
struct V_28 * V_29 = V_27 ;
if ( V_29 && ( V_18 -> V_32 != V_29 ) )
return 0 ;
if ( ! V_18 -> V_32 ) {
F_2 ( V_36 L_9 ,
V_26 -> V_3 ) ;
} else if ( V_26 -> V_33 < V_34 ) {
enum V_37 V_38 = V_39 ;
if ( V_26 -> V_40 )
V_38 = F_23 ( V_26 -> V_40 ) ;
F_2 ( V_4 L_10
L_11 ,
V_26 -> V_3 , V_26 -> V_33 , V_38 ) ;
}
return 0 ;
}
static void F_24 ( struct V_30 * V_31 )
{
unsigned long V_41 = V_42 ;
struct V_28 * V_29 = V_31 ? & V_31 -> V_32 : NULL ;
unsigned int V_43 = 0 ;
if ( ! V_44 || ! F_25 () )
return;
while ( F_20 ( V_29 ) ) {
if ( F_26 ( V_42 , V_41 + ( V_43 + 5 ) * V_45 ) ) {
if ( ! V_43 )
F_2 ( V_4 L_12
L_13 ) ;
V_43 += 5 ;
F_2 ( L_14 , 300 - V_43 ) ;
if ( V_43 == 300 )
break;
}
F_27 ( V_45 / 10 ) ;
}
if ( V_43 )
F_2 ( L_15 ) ;
F_21 ( & V_25 . V_7 , NULL , V_29 ,
F_22 ) ;
}
int F_28 ( struct V_30 * V_29 ,
struct V_46 * V_47 , const char * V_48 )
{
int V_49 ;
V_29 -> V_50 = F_16 ;
V_49 = F_29 ( V_29 , & V_25 ,
V_47 , V_48 ) ;
if ( V_49 )
return V_49 ;
F_24 ( V_29 ) ;
return 0 ;
}
static int F_30 ( struct V_51 * V_52 ,
unsigned long V_53 ,
void * V_27 )
{
F_31 ( & V_25 ) ;
F_32 ( & V_54 ) ;
return V_55 ;
}
static int T_1 F_33 ( void )
{
static struct V_51 V_56 = {
. V_57 = F_30
} ;
int V_9 ;
F_6 ( L_6 ) ;
V_9 = F_34 ( & V_25 . V_7 ) ;
if ( V_9 )
return V_9 ;
F_35 ( & V_56 ) ;
return 0 ;
}
static int T_1 F_36 ( void )
{
if ( F_37 () && ! V_58 )
return - V_59 ;
V_44 = 1 ;
F_24 ( NULL ) ;
return 0 ;
}
