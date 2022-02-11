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
static int F_22 ( struct V_5 * V_5 )
{
struct V_31 * V_32 ;
struct V_23 * V_23 ;
int V_33 = 0 , V_13 = 0 ;
do {
if ( F_23 ( V_5 ) ||
! F_24 ( & V_5 -> V_34 ) ) {
V_33 = - V_35 ;
goto V_29;
}
F_25 (h) {
F_26 ( & V_36 ) ;
F_27 (page, &h->hugepage_activelist, lru)
F_16 ( V_13 , V_5 , V_23 ) ;
F_28 ( & V_36 ) ;
V_13 ++ ;
}
F_29 () ;
} while ( F_8 ( V_5 ) );
V_29:
return V_33 ;
}
int F_30 ( int V_13 , unsigned long V_37 ,
struct V_1 * * V_38 )
{
int V_33 = 0 ;
struct V_25 * V_27 ;
struct V_1 * V_9 = NULL ;
unsigned long V_24 = V_37 * V_30 ;
if ( F_31 () )
goto V_39;
if ( F_32 ( & V_40 [ V_13 ] ) < V_41 )
goto V_39;
V_42:
F_33 () ;
V_9 = F_4 ( V_43 ) ;
if ( ! F_34 ( & V_9 -> V_4 ) ) {
F_35 () ;
goto V_42;
}
F_35 () ;
V_33 = F_36 ( & V_9 -> V_15 [ V_13 ] , V_24 , & V_27 ) ;
F_37 ( & V_9 -> V_4 ) ;
V_39:
* V_38 = V_9 ;
return V_33 ;
}
void F_38 ( int V_13 , unsigned long V_37 ,
struct V_1 * V_9 ,
struct V_23 * V_23 )
{
if ( F_31 () || ! V_9 )
return;
F_21 ( V_23 , V_9 ) ;
return;
}
void F_39 ( int V_13 , unsigned long V_37 ,
struct V_23 * V_23 )
{
struct V_1 * V_9 ;
unsigned long V_24 = V_37 * V_30 ;
if ( F_31 () )
return;
F_40 ( ! F_41 ( & V_36 ) ) ;
V_9 = F_17 ( V_23 ) ;
if ( F_42 ( ! V_9 ) )
return;
F_21 ( V_23 , NULL ) ;
F_43 ( & V_9 -> V_15 [ V_13 ] , V_24 ) ;
return;
}
void F_44 ( int V_13 , unsigned long V_37 ,
struct V_1 * V_9 )
{
unsigned long V_24 = V_37 * V_30 ;
if ( F_31 () || ! V_9 )
return;
if ( F_32 ( & V_40 [ V_13 ] ) < V_41 )
return;
F_43 ( & V_9 -> V_15 [ V_13 ] , V_24 ) ;
return;
}
static T_1 F_45 ( struct V_5 * V_5 , struct V_44 * V_45 ,
struct V_46 * V_46 , char T_2 * V_47 ,
T_3 V_48 , T_4 * V_49 )
{
T_5 V_50 ;
char V_51 [ 64 ] ;
int V_13 , V_52 , V_53 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
V_13 = F_46 ( V_45 -> V_54 ) ;
V_52 = F_47 ( V_45 -> V_54 ) ;
V_50 = F_9 ( & V_9 -> V_15 [ V_13 ] , V_52 ) ;
V_53 = F_48 ( V_51 , sizeof( V_51 ) , L_1 , ( unsigned long long ) V_50 ) ;
return F_49 ( V_47 , V_48 , V_49 , V_51 , V_53 ) ;
}
static int F_50 ( struct V_5 * V_5 , struct V_44 * V_45 ,
const char * V_55 )
{
int V_13 , V_52 , V_33 ;
unsigned long long V_50 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
V_13 = F_46 ( V_45 -> V_54 ) ;
V_52 = F_47 ( V_45 -> V_54 ) ;
switch ( V_52 ) {
case V_56 :
if ( F_6 ( V_9 ) ) {
V_33 = - V_57 ;
break;
}
V_33 = F_51 ( V_55 , & V_50 ) ;
if ( V_33 )
break;
V_33 = F_52 ( & V_9 -> V_15 [ V_13 ] , V_50 ) ;
break;
default:
V_33 = - V_57 ;
break;
}
return V_33 ;
}
static int F_53 ( struct V_5 * V_5 , unsigned int V_58 )
{
int V_13 , V_52 , V_33 = 0 ;
struct V_1 * V_9 = F_3 ( V_5 ) ;
V_13 = F_46 ( V_58 ) ;
V_52 = F_47 ( V_58 ) ;
switch ( V_52 ) {
case V_59 :
F_54 ( & V_9 -> V_15 [ V_13 ] ) ;
break;
case V_60 :
F_55 ( & V_9 -> V_15 [ V_13 ] ) ;
break;
default:
V_33 = - V_57 ;
break;
}
return V_33 ;
}
static char * F_56 ( char * V_47 , int V_61 , unsigned long V_62 )
{
if ( V_62 >= ( 1UL << 30 ) )
snprintf ( V_47 , V_61 , L_2 , V_62 >> 30 ) ;
else if ( V_62 >= ( 1UL << 20 ) )
snprintf ( V_47 , V_61 , L_3 , V_62 >> 20 ) ;
else
snprintf ( V_47 , V_61 , L_4 , V_62 >> 10 ) ;
return V_47 ;
}
int T_6 F_57 ( int V_13 )
{
char V_47 [ 32 ] ;
struct V_44 * V_45 ;
struct V_31 * V_32 = & V_40 [ V_13 ] ;
F_56 ( V_47 , 32 , F_58 ( V_32 ) ) ;
V_45 = & V_32 -> V_63 [ 0 ] ;
snprintf ( V_45 -> V_52 , V_64 , L_5 , V_47 ) ;
V_45 -> V_54 = F_59 ( V_13 , V_56 ) ;
V_45 -> V_65 = F_45 ;
V_45 -> V_66 = F_50 ;
V_45 = & V_32 -> V_63 [ 1 ] ;
snprintf ( V_45 -> V_52 , V_64 , L_6 , V_47 ) ;
V_45 -> V_54 = F_59 ( V_13 , V_16 ) ;
V_45 -> V_65 = F_45 ;
V_45 = & V_32 -> V_63 [ 2 ] ;
snprintf ( V_45 -> V_52 , V_64 , L_7 , V_47 ) ;
V_45 -> V_54 = F_59 ( V_13 , V_59 ) ;
V_45 -> V_67 = F_53 ;
V_45 -> V_65 = F_45 ;
V_45 = & V_32 -> V_63 [ 3 ] ;
snprintf ( V_45 -> V_52 , V_64 , L_8 , V_47 ) ;
V_45 -> V_54 = F_59 ( V_13 , V_60 ) ;
V_45 -> V_67 = F_53 ;
V_45 -> V_65 = F_45 ;
V_45 = & V_32 -> V_63 [ 4 ] ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
F_60 ( F_61 ( & V_68 , V_32 -> V_63 ) ) ;
return 0 ;
}
void F_62 ( struct V_23 * V_69 , struct V_23 * V_70 )
{
struct V_1 * V_9 ;
struct V_31 * V_32 = F_63 ( V_69 ) ;
if ( F_31 () )
return;
F_40 ( ! F_64 ( V_69 ) ) ;
F_26 ( & V_36 ) ;
V_9 = F_17 ( V_69 ) ;
F_21 ( V_69 , NULL ) ;
F_21 ( V_70 , V_9 ) ;
F_65 ( & V_70 -> V_71 , & V_32 -> V_72 ) ;
F_28 ( & V_36 ) ;
return;
}
