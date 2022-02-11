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
return F_1 ( V_8 -> V_4 . V_10 ) ;
}
static inline bool F_7 ( struct V_1 * V_8 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_12 ; V_11 ++ ) {
if ( ( F_8 ( & V_8 -> V_13 [ V_11 ] , V_14 ) ) > 0 )
return true ;
}
return false ;
}
static struct V_2 *
F_9 ( struct V_2 * V_15 )
{
struct V_1 * V_16 = F_1 ( V_15 ) ;
struct V_1 * V_17 ;
int V_11 ;
V_17 = F_10 ( sizeof( * V_17 ) , V_18 ) ;
if ( ! V_17 )
return F_11 ( - V_19 ) ;
if ( V_16 ) {
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ )
F_12 ( & V_17 -> V_13 [ V_11 ] ,
& V_16 -> V_13 [ V_11 ] ) ;
} else {
V_9 = V_17 ;
for ( V_11 = 0 ; V_11 < V_20 ; V_11 ++ )
F_12 ( & V_17 -> V_13 [ V_11 ] , NULL ) ;
}
return & V_17 -> V_4 ;
}
static void F_13 ( struct V_2 * V_4 )
{
struct V_1 * V_17 ;
V_17 = F_1 ( V_4 ) ;
F_14 ( V_17 ) ;
}
static void F_15 ( int V_11 , struct V_1 * V_8 ,
struct V_21 * V_21 )
{
int V_22 ;
struct V_23 * V_24 ;
struct V_23 * V_25 ;
struct V_1 * V_26 ;
struct V_1 * V_10 = F_6 ( V_8 ) ;
V_26 = F_16 ( V_21 ) ;
if ( ! V_26 || V_26 != V_8 )
goto V_27;
V_22 = V_28 << F_17 ( V_21 ) ;
if ( ! V_10 ) {
V_10 = V_9 ;
F_18 ( & V_10 -> V_13 [ V_11 ] ,
V_22 , & V_25 ) ;
}
V_24 = & V_8 -> V_13 [ V_11 ] ;
F_19 ( V_24 , V_24 -> V_10 , V_22 ) ;
F_20 ( V_21 , V_10 ) ;
V_27:
return;
}
static void F_21 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_29 * V_30 ;
struct V_21 * V_21 ;
int V_11 = 0 ;
do {
F_22 (h) {
F_23 ( & V_31 ) ;
F_24 (page, &h->hugepage_activelist, lru)
F_15 ( V_11 , V_8 , V_21 ) ;
F_25 ( & V_31 ) ;
V_11 ++ ;
}
F_26 () ;
} while ( F_7 ( V_8 ) );
}
int F_27 ( int V_11 , unsigned long V_32 ,
struct V_1 * * V_33 )
{
int V_34 = 0 ;
struct V_23 * V_25 ;
struct V_1 * V_8 = NULL ;
unsigned long V_22 = V_32 * V_28 ;
if ( F_28 () )
goto V_35;
if ( F_29 ( & V_36 [ V_11 ] ) < V_37 )
goto V_35;
V_38:
F_30 () ;
V_8 = F_3 ( V_39 ) ;
if ( ! F_31 ( & V_8 -> V_4 ) ) {
F_32 () ;
goto V_38;
}
F_32 () ;
V_34 = F_33 ( & V_8 -> V_13 [ V_11 ] , V_22 , & V_25 ) ;
F_34 ( & V_8 -> V_4 ) ;
V_35:
* V_33 = V_8 ;
return V_34 ;
}
void F_35 ( int V_11 , unsigned long V_32 ,
struct V_1 * V_8 ,
struct V_21 * V_21 )
{
if ( F_28 () || ! V_8 )
return;
F_20 ( V_21 , V_8 ) ;
return;
}
void F_36 ( int V_11 , unsigned long V_32 ,
struct V_21 * V_21 )
{
struct V_1 * V_8 ;
unsigned long V_22 = V_32 * V_28 ;
if ( F_28 () )
return;
F_37 ( & V_31 ) ;
V_8 = F_16 ( V_21 ) ;
if ( F_38 ( ! V_8 ) )
return;
F_20 ( V_21 , NULL ) ;
F_39 ( & V_8 -> V_13 [ V_11 ] , V_22 ) ;
return;
}
void F_40 ( int V_11 , unsigned long V_32 ,
struct V_1 * V_8 )
{
unsigned long V_22 = V_32 * V_28 ;
if ( F_28 () || ! V_8 )
return;
if ( F_29 ( & V_36 [ V_11 ] ) < V_37 )
return;
F_39 ( & V_8 -> V_13 [ V_11 ] , V_22 ) ;
return;
}
static T_1 F_41 ( struct V_2 * V_4 ,
struct V_40 * V_41 )
{
int V_11 , V_42 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_11 = F_42 ( V_41 -> V_43 ) ;
V_42 = F_43 ( V_41 -> V_43 ) ;
return F_8 ( & V_8 -> V_13 [ V_11 ] , V_42 ) ;
}
static T_2 F_44 ( struct V_44 * V_45 ,
char * V_46 , T_3 V_47 , T_4 V_48 )
{
int V_11 , V_42 , V_34 ;
unsigned long long V_49 ;
struct V_1 * V_8 = F_1 ( F_45 ( V_45 ) ) ;
V_46 = F_46 ( V_46 ) ;
V_11 = F_42 ( F_47 ( V_45 ) -> V_43 ) ;
V_42 = F_43 ( F_47 ( V_45 ) -> V_43 ) ;
switch ( V_42 ) {
case V_50 :
if ( F_5 ( V_8 ) ) {
V_34 = - V_51 ;
break;
}
V_34 = F_48 ( V_46 , & V_49 ) ;
if ( V_34 )
break;
V_49 = F_49 ( V_49 , 1ULL << F_50 ( & V_36 [ V_11 ] ) ) ;
V_34 = F_51 ( & V_8 -> V_13 [ V_11 ] , V_49 ) ;
break;
default:
V_34 = - V_51 ;
break;
}
return V_34 ? : V_47 ;
}
static T_2 F_52 ( struct V_44 * V_45 ,
char * V_46 , T_3 V_47 , T_4 V_48 )
{
int V_11 , V_42 , V_34 = 0 ;
struct V_1 * V_8 = F_1 ( F_45 ( V_45 ) ) ;
V_11 = F_42 ( F_47 ( V_45 ) -> V_43 ) ;
V_42 = F_43 ( F_47 ( V_45 ) -> V_43 ) ;
switch ( V_42 ) {
case V_52 :
F_53 ( & V_8 -> V_13 [ V_11 ] ) ;
break;
case V_53 :
F_54 ( & V_8 -> V_13 [ V_11 ] ) ;
break;
default:
V_34 = - V_51 ;
break;
}
return V_34 ? : V_47 ;
}
static char * F_55 ( char * V_46 , int V_54 , unsigned long V_55 )
{
if ( V_55 >= ( 1UL << 30 ) )
snprintf ( V_46 , V_54 , L_1 , V_55 >> 30 ) ;
else if ( V_55 >= ( 1UL << 20 ) )
snprintf ( V_46 , V_54 , L_2 , V_55 >> 20 ) ;
else
snprintf ( V_46 , V_54 , L_3 , V_55 >> 10 ) ;
return V_46 ;
}
static void T_5 F_56 ( int V_11 )
{
char V_46 [ 32 ] ;
struct V_40 * V_41 ;
struct V_29 * V_30 = & V_36 [ V_11 ] ;
F_55 ( V_46 , 32 , F_57 ( V_30 ) ) ;
V_41 = & V_30 -> V_56 [ 0 ] ;
snprintf ( V_41 -> V_42 , V_57 , L_4 , V_46 ) ;
V_41 -> V_43 = F_58 ( V_11 , V_50 ) ;
V_41 -> V_58 = F_41 ;
V_41 -> V_59 = F_44 ;
V_41 = & V_30 -> V_56 [ 1 ] ;
snprintf ( V_41 -> V_42 , V_57 , L_5 , V_46 ) ;
V_41 -> V_43 = F_58 ( V_11 , V_14 ) ;
V_41 -> V_58 = F_41 ;
V_41 = & V_30 -> V_56 [ 2 ] ;
snprintf ( V_41 -> V_42 , V_57 , L_6 , V_46 ) ;
V_41 -> V_43 = F_58 ( V_11 , V_52 ) ;
V_41 -> V_59 = F_52 ;
V_41 -> V_58 = F_41 ;
V_41 = & V_30 -> V_56 [ 3 ] ;
snprintf ( V_41 -> V_42 , V_57 , L_7 , V_46 ) ;
V_41 -> V_43 = F_58 ( V_11 , V_53 ) ;
V_41 -> V_59 = F_52 ;
V_41 -> V_58 = F_41 ;
V_41 = & V_30 -> V_56 [ 4 ] ;
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
F_59 ( F_60 ( & V_60 ,
V_30 -> V_56 ) ) ;
}
void T_5 F_61 ( void )
{
struct V_29 * V_30 ;
F_22 (h) {
if ( F_29 ( V_30 ) >= V_37 )
F_56 ( F_62 ( V_30 ) ) ;
}
}
void F_63 ( struct V_21 * V_61 , struct V_21 * V_62 )
{
struct V_1 * V_8 ;
struct V_29 * V_30 = F_64 ( V_61 ) ;
if ( F_28 () )
return;
F_65 ( ! F_66 ( V_61 ) , V_61 ) ;
F_23 ( & V_31 ) ;
V_8 = F_16 ( V_61 ) ;
F_20 ( V_61 , NULL ) ;
F_20 ( V_62 , V_8 ) ;
F_67 ( & V_62 -> V_63 , & V_30 -> V_64 ) ;
F_25 ( & V_31 ) ;
return;
}
