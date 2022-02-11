static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline
struct V_1 * F_3 ( struct V_5 * V_5 )
{
return F_1 ( V_2 ( V_5 ,
V_6 ) ) ;
}
static inline
struct V_1 * F_4 ( struct V_7 * V_8 )
{
return F_1 ( F_5 ( V_8 ,
V_6 ) ) ;
}
static inline bool F_6 ( struct V_1 * V_9 )
{
return ( V_9 == V_10 ) ;
}
static inline struct V_1 * F_7 ( struct V_5 * V_11 )
{
if ( ! V_11 -> V_12 )
return NULL ;
return F_3 ( V_11 -> V_12 ) ;
}
static inline bool F_8 ( struct V_5 * V_11 )
{
int V_13 ;
struct V_1 * V_9 = F_3 ( V_11 ) ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( ( F_9 ( & V_9 -> V_15 [ V_13 ] , V_16 ) ) > 0 )
return true ;
}
return false ;
}
static struct V_2 * F_10 ( struct V_5 * V_5 )
{
int V_13 ;
struct V_5 * V_17 ;
struct V_1 * V_18 , * V_19 ;
V_18 = F_11 ( sizeof( * V_18 ) , V_20 ) ;
if ( ! V_18 )
return F_12 ( - V_21 ) ;
V_17 = V_5 -> V_12 ;
if ( V_17 ) {
V_19 = F_3 ( V_17 ) ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_13 ( & V_18 -> V_15 [ V_13 ] ,
& V_19 -> V_15 [ V_13 ] ) ;
} else {
V_10 = V_18 ;
for ( V_13 = 0 ; V_13 < V_22 ; V_13 ++ )
F_13 ( & V_18 -> V_15 [ V_13 ] , NULL ) ;
}
return & V_18 -> V_4 ;
}
static void F_14 ( struct V_5 * V_5 )
{
struct V_1 * V_18 ;
V_18 = F_3 ( V_5 ) ;
F_15 ( V_18 ) ;
}
static void F_16 ( int V_13 , struct V_5 * V_5 ,
struct V_23 * V_23 )
{
int V_24 ;
struct V_25 * V_26 ;
struct V_25 * V_27 ;
struct V_1 * V_28 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
struct V_1 * V_12 = F_7 ( V_5 ) ;
V_28 = F_17 ( V_23 ) ;
if ( ! V_28 || V_28 != V_9 )
goto V_29;
V_24 = V_30 << F_18 ( V_23 ) ;
if ( ! V_12 ) {
V_12 = V_10 ;
F_19 ( & V_12 -> V_15 [ V_13 ] ,
V_24 , & V_27 ) ;
}
V_26 = & V_9 -> V_15 [ V_13 ] ;
F_20 ( V_26 , V_26 -> V_12 , V_24 ) ;
F_21 ( V_23 , V_12 ) ;
V_29:
return;
}
static void F_22 ( struct V_5 * V_5 )
{
struct V_31 * V_32 ;
struct V_23 * V_23 ;
int V_13 = 0 ;
do {
F_23 (h) {
F_24 ( & V_33 ) ;
F_25 (page, &h->hugepage_activelist, lru)
F_16 ( V_13 , V_5 , V_23 ) ;
F_26 ( & V_33 ) ;
V_13 ++ ;
}
F_27 () ;
} while ( F_8 ( V_5 ) );
}
int F_28 ( int V_13 , unsigned long V_34 ,
struct V_1 * * V_35 )
{
int V_36 = 0 ;
struct V_25 * V_27 ;
struct V_1 * V_9 = NULL ;
unsigned long V_24 = V_34 * V_30 ;
if ( F_29 () )
goto V_37;
if ( F_30 ( & V_38 [ V_13 ] ) < V_39 )
goto V_37;
V_40:
F_31 () ;
V_9 = F_4 ( V_41 ) ;
if ( ! F_32 ( & V_9 -> V_4 ) ) {
F_33 () ;
goto V_40;
}
F_33 () ;
V_36 = F_34 ( & V_9 -> V_15 [ V_13 ] , V_24 , & V_27 ) ;
F_35 ( & V_9 -> V_4 ) ;
V_37:
* V_35 = V_9 ;
return V_36 ;
}
void F_36 ( int V_13 , unsigned long V_34 ,
struct V_1 * V_9 ,
struct V_23 * V_23 )
{
if ( F_29 () || ! V_9 )
return;
F_21 ( V_23 , V_9 ) ;
return;
}
void F_37 ( int V_13 , unsigned long V_34 ,
struct V_23 * V_23 )
{
struct V_1 * V_9 ;
unsigned long V_24 = V_34 * V_30 ;
if ( F_29 () )
return;
F_38 ( ! F_39 ( & V_33 ) ) ;
V_9 = F_17 ( V_23 ) ;
if ( F_40 ( ! V_9 ) )
return;
F_21 ( V_23 , NULL ) ;
F_41 ( & V_9 -> V_15 [ V_13 ] , V_24 ) ;
return;
}
void F_42 ( int V_13 , unsigned long V_34 ,
struct V_1 * V_9 )
{
unsigned long V_24 = V_34 * V_30 ;
if ( F_29 () || ! V_9 )
return;
if ( F_30 ( & V_38 [ V_13 ] ) < V_39 )
return;
F_41 ( & V_9 -> V_15 [ V_13 ] , V_24 ) ;
return;
}
static T_1 F_43 ( struct V_5 * V_5 , struct V_42 * V_43 ,
struct V_44 * V_44 , char T_2 * V_45 ,
T_3 V_46 , T_4 * V_47 )
{
T_5 V_48 ;
char V_49 [ 64 ] ;
int V_13 , V_50 , V_51 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
V_13 = F_44 ( V_43 -> V_52 ) ;
V_50 = F_45 ( V_43 -> V_52 ) ;
V_48 = F_9 ( & V_9 -> V_15 [ V_13 ] , V_50 ) ;
V_51 = F_46 ( V_49 , sizeof( V_49 ) , L_1 , ( unsigned long long ) V_48 ) ;
return F_47 ( V_45 , V_46 , V_47 , V_49 , V_51 ) ;
}
static int F_48 ( struct V_5 * V_5 , struct V_42 * V_43 ,
const char * V_53 )
{
int V_13 , V_50 , V_36 ;
unsigned long long V_48 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
V_13 = F_44 ( V_43 -> V_52 ) ;
V_50 = F_45 ( V_43 -> V_52 ) ;
switch ( V_50 ) {
case V_54 :
if ( F_6 ( V_9 ) ) {
V_36 = - V_55 ;
break;
}
V_36 = F_49 ( V_53 , & V_48 ) ;
if ( V_36 )
break;
V_36 = F_50 ( & V_9 -> V_15 [ V_13 ] , V_48 ) ;
break;
default:
V_36 = - V_55 ;
break;
}
return V_36 ;
}
static int F_51 ( struct V_5 * V_5 , unsigned int V_56 )
{
int V_13 , V_50 , V_36 = 0 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
V_13 = F_44 ( V_56 ) ;
V_50 = F_45 ( V_56 ) ;
switch ( V_50 ) {
case V_57 :
F_52 ( & V_9 -> V_15 [ V_13 ] ) ;
break;
case V_58 :
F_53 ( & V_9 -> V_15 [ V_13 ] ) ;
break;
default:
V_36 = - V_55 ;
break;
}
return V_36 ;
}
static char * F_54 ( char * V_45 , int V_59 , unsigned long V_60 )
{
if ( V_60 >= ( 1UL << 30 ) )
snprintf ( V_45 , V_59 , L_2 , V_60 >> 30 ) ;
else if ( V_60 >= ( 1UL << 20 ) )
snprintf ( V_45 , V_59 , L_3 , V_60 >> 20 ) ;
else
snprintf ( V_45 , V_59 , L_4 , V_60 >> 10 ) ;
return V_45 ;
}
static void T_6 F_55 ( int V_13 )
{
char V_45 [ 32 ] ;
struct V_42 * V_43 ;
struct V_31 * V_32 = & V_38 [ V_13 ] ;
F_54 ( V_45 , 32 , F_56 ( V_32 ) ) ;
V_43 = & V_32 -> V_61 [ 0 ] ;
snprintf ( V_43 -> V_50 , V_62 , L_5 , V_45 ) ;
V_43 -> V_52 = F_57 ( V_13 , V_54 ) ;
V_43 -> V_63 = F_43 ;
V_43 -> V_64 = F_48 ;
V_43 = & V_32 -> V_61 [ 1 ] ;
snprintf ( V_43 -> V_50 , V_62 , L_6 , V_45 ) ;
V_43 -> V_52 = F_57 ( V_13 , V_16 ) ;
V_43 -> V_63 = F_43 ;
V_43 = & V_32 -> V_61 [ 2 ] ;
snprintf ( V_43 -> V_50 , V_62 , L_7 , V_45 ) ;
V_43 -> V_52 = F_57 ( V_13 , V_57 ) ;
V_43 -> V_65 = F_51 ;
V_43 -> V_63 = F_43 ;
V_43 = & V_32 -> V_61 [ 3 ] ;
snprintf ( V_43 -> V_50 , V_62 , L_8 , V_45 ) ;
V_43 -> V_52 = F_57 ( V_13 , V_58 ) ;
V_43 -> V_65 = F_51 ;
V_43 -> V_63 = F_43 ;
V_43 = & V_32 -> V_61 [ 4 ] ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
F_58 ( F_59 ( & V_66 , V_32 -> V_61 ) ) ;
return;
}
void T_6 F_60 ( void )
{
struct V_31 * V_32 ;
F_23 (h) {
if ( F_30 ( V_32 ) >= V_39 )
F_55 ( F_61 ( V_32 ) ) ;
}
}
void F_62 ( struct V_23 * V_67 , struct V_23 * V_68 )
{
struct V_1 * V_9 ;
struct V_31 * V_32 = F_63 ( V_67 ) ;
if ( F_29 () )
return;
F_38 ( ! F_64 ( V_67 ) ) ;
F_24 ( & V_33 ) ;
V_9 = F_17 ( V_67 ) ;
F_21 ( V_67 , NULL ) ;
F_21 ( V_68 , V_9 ) ;
F_65 ( & V_68 -> V_69 , & V_32 -> V_70 ) ;
F_26 ( & V_33 ) ;
return;
}
