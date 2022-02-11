static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 ? F_2 ( V_3 , struct V_1 , V_4 ) : NULL ;
}
static inline
struct V_1 * F_3 ( struct V_5 * V_6 )
{
return F_1 ( F_4 ( V_6 , V_7 ) ) ;
}
static inline bool F_5 ( struct V_1 * V_8 )
{
return ( V_8 == V_9 ) ;
}
static inline struct V_1 *
F_6 ( struct V_1 * V_8 )
{
return F_1 ( F_7 ( & V_8 -> V_4 ) ) ;
}
static inline bool F_8 ( struct V_1 * V_8 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( ( F_9 ( & V_8 -> V_12 [ V_10 ] , V_13 ) ) > 0 )
return true ;
}
return false ;
}
static struct V_2 *
F_10 ( struct V_2 * V_14 )
{
struct V_1 * V_15 = F_1 ( V_14 ) ;
struct V_1 * V_16 ;
int V_10 ;
V_16 = F_11 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return F_12 ( - V_18 ) ;
if ( V_15 ) {
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ )
F_13 ( & V_16 -> V_12 [ V_10 ] ,
& V_15 -> V_12 [ V_10 ] ) ;
} else {
V_9 = V_16 ;
for ( V_10 = 0 ; V_10 < V_19 ; V_10 ++ )
F_13 ( & V_16 -> V_12 [ V_10 ] , NULL ) ;
}
return & V_16 -> V_4 ;
}
static void F_14 ( struct V_2 * V_4 )
{
struct V_1 * V_16 ;
V_16 = F_1 ( V_4 ) ;
F_15 ( V_16 ) ;
}
static void F_16 ( int V_10 , struct V_1 * V_8 ,
struct V_20 * V_20 )
{
int V_21 ;
struct V_22 * V_23 ;
struct V_22 * V_24 ;
struct V_1 * V_25 ;
struct V_1 * V_26 = F_6 ( V_8 ) ;
V_25 = F_17 ( V_20 ) ;
if ( ! V_25 || V_25 != V_8 )
goto V_27;
V_21 = V_28 << F_18 ( V_20 ) ;
if ( ! V_26 ) {
V_26 = V_9 ;
F_19 ( & V_26 -> V_12 [ V_10 ] ,
V_21 , & V_24 ) ;
}
V_23 = & V_8 -> V_12 [ V_10 ] ;
F_20 ( V_23 , V_23 -> V_26 , V_21 ) ;
F_21 ( V_20 , V_26 ) ;
V_27:
return;
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_29 * V_30 ;
struct V_20 * V_20 ;
int V_10 = 0 ;
do {
F_23 (h) {
F_24 ( & V_31 ) ;
F_25 (page, &h->hugepage_activelist, lru)
F_16 ( V_10 , V_8 , V_20 ) ;
F_26 ( & V_31 ) ;
V_10 ++ ;
}
F_27 () ;
} while ( F_8 ( V_8 ) );
}
int F_28 ( int V_10 , unsigned long V_32 ,
struct V_1 * * V_33 )
{
int V_34 = 0 ;
struct V_22 * V_24 ;
struct V_1 * V_8 = NULL ;
unsigned long V_21 = V_32 * V_28 ;
if ( F_29 () )
goto V_35;
if ( F_30 ( & V_36 [ V_10 ] ) < V_37 )
goto V_35;
V_38:
F_31 () ;
V_8 = F_3 ( V_39 ) ;
if ( ! F_32 ( & V_8 -> V_4 ) ) {
F_33 () ;
goto V_38;
}
F_33 () ;
V_34 = F_34 ( & V_8 -> V_12 [ V_10 ] , V_21 , & V_24 ) ;
F_35 ( & V_8 -> V_4 ) ;
V_35:
* V_33 = V_8 ;
return V_34 ;
}
void F_36 ( int V_10 , unsigned long V_32 ,
struct V_1 * V_8 ,
struct V_20 * V_20 )
{
if ( F_29 () || ! V_8 )
return;
F_21 ( V_20 , V_8 ) ;
return;
}
void F_37 ( int V_10 , unsigned long V_32 ,
struct V_20 * V_20 )
{
struct V_1 * V_8 ;
unsigned long V_21 = V_32 * V_28 ;
if ( F_29 () )
return;
F_38 ( ! F_39 ( & V_31 ) ) ;
V_8 = F_17 ( V_20 ) ;
if ( F_40 ( ! V_8 ) )
return;
F_21 ( V_20 , NULL ) ;
F_41 ( & V_8 -> V_12 [ V_10 ] , V_21 ) ;
return;
}
void F_42 ( int V_10 , unsigned long V_32 ,
struct V_1 * V_8 )
{
unsigned long V_21 = V_32 * V_28 ;
if ( F_29 () || ! V_8 )
return;
if ( F_30 ( & V_36 [ V_10 ] ) < V_37 )
return;
F_41 ( & V_8 -> V_12 [ V_10 ] , V_21 ) ;
return;
}
static T_1 F_43 ( struct V_2 * V_4 ,
struct V_40 * V_41 , struct V_42 * V_42 ,
char T_2 * V_43 , T_3 V_44 ,
T_4 * V_45 )
{
T_5 V_46 ;
char V_47 [ 64 ] ;
int V_10 , V_48 , V_49 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_10 = F_44 ( V_41 -> V_50 ) ;
V_48 = F_45 ( V_41 -> V_50 ) ;
V_46 = F_9 ( & V_8 -> V_12 [ V_10 ] , V_48 ) ;
V_49 = F_46 ( V_47 , sizeof( V_47 ) , L_1 , ( unsigned long long ) V_46 ) ;
return F_47 ( V_43 , V_44 , V_45 , V_47 , V_49 ) ;
}
static int F_48 ( struct V_2 * V_4 ,
struct V_40 * V_41 , const char * V_51 )
{
int V_10 , V_48 , V_34 ;
unsigned long long V_46 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_10 = F_44 ( V_41 -> V_50 ) ;
V_48 = F_45 ( V_41 -> V_50 ) ;
switch ( V_48 ) {
case V_52 :
if ( F_5 ( V_8 ) ) {
V_34 = - V_53 ;
break;
}
V_34 = F_49 ( V_51 , & V_46 ) ;
if ( V_34 )
break;
V_34 = F_50 ( & V_8 -> V_12 [ V_10 ] , V_46 ) ;
break;
default:
V_34 = - V_53 ;
break;
}
return V_34 ;
}
static int F_51 ( struct V_2 * V_4 ,
unsigned int V_54 )
{
int V_10 , V_48 , V_34 = 0 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_10 = F_44 ( V_54 ) ;
V_48 = F_45 ( V_54 ) ;
switch ( V_48 ) {
case V_55 :
F_52 ( & V_8 -> V_12 [ V_10 ] ) ;
break;
case V_56 :
F_53 ( & V_8 -> V_12 [ V_10 ] ) ;
break;
default:
V_34 = - V_53 ;
break;
}
return V_34 ;
}
static char * F_54 ( char * V_43 , int V_57 , unsigned long V_58 )
{
if ( V_58 >= ( 1UL << 30 ) )
snprintf ( V_43 , V_57 , L_2 , V_58 >> 30 ) ;
else if ( V_58 >= ( 1UL << 20 ) )
snprintf ( V_43 , V_57 , L_3 , V_58 >> 20 ) ;
else
snprintf ( V_43 , V_57 , L_4 , V_58 >> 10 ) ;
return V_43 ;
}
static void T_6 F_55 ( int V_10 )
{
char V_43 [ 32 ] ;
struct V_40 * V_41 ;
struct V_29 * V_30 = & V_36 [ V_10 ] ;
F_54 ( V_43 , 32 , F_56 ( V_30 ) ) ;
V_41 = & V_30 -> V_59 [ 0 ] ;
snprintf ( V_41 -> V_48 , V_60 , L_5 , V_43 ) ;
V_41 -> V_50 = F_57 ( V_10 , V_52 ) ;
V_41 -> V_61 = F_43 ;
V_41 -> V_62 = F_48 ;
V_41 = & V_30 -> V_59 [ 1 ] ;
snprintf ( V_41 -> V_48 , V_60 , L_6 , V_43 ) ;
V_41 -> V_50 = F_57 ( V_10 , V_13 ) ;
V_41 -> V_61 = F_43 ;
V_41 = & V_30 -> V_59 [ 2 ] ;
snprintf ( V_41 -> V_48 , V_60 , L_7 , V_43 ) ;
V_41 -> V_50 = F_57 ( V_10 , V_55 ) ;
V_41 -> V_63 = F_51 ;
V_41 -> V_61 = F_43 ;
V_41 = & V_30 -> V_59 [ 3 ] ;
snprintf ( V_41 -> V_48 , V_60 , L_8 , V_43 ) ;
V_41 -> V_50 = F_57 ( V_10 , V_56 ) ;
V_41 -> V_63 = F_51 ;
V_41 -> V_61 = F_43 ;
V_41 = & V_30 -> V_59 [ 4 ] ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
F_58 ( F_59 ( & V_64 , V_30 -> V_59 ) ) ;
return;
}
void T_6 F_60 ( void )
{
struct V_29 * V_30 ;
F_23 (h) {
if ( F_30 ( V_30 ) >= V_37 )
F_55 ( F_61 ( V_30 ) ) ;
}
}
void F_62 ( struct V_20 * V_65 , struct V_20 * V_66 )
{
struct V_1 * V_8 ;
struct V_29 * V_30 = F_63 ( V_65 ) ;
if ( F_29 () )
return;
F_38 ( ! F_64 ( V_65 ) ) ;
F_24 ( & V_31 ) ;
V_8 = F_17 ( V_65 ) ;
F_21 ( V_65 , NULL ) ;
F_21 ( V_66 , V_8 ) ;
F_65 ( & V_66 -> V_67 , & V_30 -> V_68 ) ;
F_26 ( & V_31 ) ;
return;
}
