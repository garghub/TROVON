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
if ( F_8 ( & V_8 -> V_13 [ V_11 ] ) )
return true ;
}
return false ;
}
static void F_9 ( struct V_1 * V_14 ,
struct V_1 * V_15 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_16 ; V_11 ++ ) {
struct V_17 * V_18 = & V_14 -> V_13 [ V_11 ] ;
struct V_17 * V_10 = NULL ;
unsigned long V_19 ;
int V_20 ;
if ( V_15 )
V_10 = & V_15 -> V_13 [ V_11 ] ;
F_10 ( V_18 , V_10 ) ;
V_19 = F_11 ( V_21 ,
1 << F_12 ( & V_22 [ V_11 ] ) ) ;
V_20 = F_13 ( V_18 , V_19 ) ;
F_14 ( V_20 ) ;
}
}
static struct V_2 *
F_15 ( struct V_2 * V_23 )
{
struct V_1 * V_15 = F_1 ( V_23 ) ;
struct V_1 * V_14 ;
V_14 = F_16 ( sizeof( * V_14 ) , V_24 ) ;
if ( ! V_14 )
return F_17 ( - V_25 ) ;
if ( ! V_15 )
V_9 = V_14 ;
F_9 ( V_14 , V_15 ) ;
return & V_14 -> V_4 ;
}
static void F_18 ( struct V_2 * V_4 )
{
struct V_1 * V_14 ;
V_14 = F_1 ( V_4 ) ;
F_19 ( V_14 ) ;
}
static void F_20 ( int V_11 , struct V_1 * V_8 ,
struct V_26 * V_26 )
{
unsigned int V_27 ;
struct V_17 * V_18 ;
struct V_1 * V_28 ;
struct V_1 * V_10 = F_6 ( V_8 ) ;
V_28 = F_21 ( V_26 ) ;
if ( ! V_28 || V_28 != V_8 )
goto V_29;
V_27 = 1 << F_22 ( V_26 ) ;
if ( ! V_10 ) {
V_10 = V_9 ;
F_23 ( & V_10 -> V_13 [ V_11 ] , V_27 ) ;
}
V_18 = & V_8 -> V_13 [ V_11 ] ;
F_24 ( V_18 , V_27 ) ;
F_25 ( V_26 , V_10 ) ;
V_29:
return;
}
static void F_26 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_30 * V_31 ;
struct V_26 * V_26 ;
int V_11 = 0 ;
do {
F_27 (h) {
F_28 ( & V_32 ) ;
F_29 (page, &h->hugepage_activelist, lru)
F_20 ( V_11 , V_8 , V_26 ) ;
F_30 ( & V_32 ) ;
V_11 ++ ;
}
F_31 () ;
} while ( F_7 ( V_8 ) );
}
int F_32 ( int V_11 , unsigned long V_27 ,
struct V_1 * * V_33 )
{
int V_20 = 0 ;
struct V_17 * V_18 ;
struct V_1 * V_8 = NULL ;
if ( F_33 () )
goto V_34;
if ( F_12 ( & V_22 [ V_11 ] ) < V_35 )
goto V_34;
V_36:
F_34 () ;
V_8 = F_3 ( V_37 ) ;
if ( ! F_35 ( & V_8 -> V_4 ) ) {
F_36 () ;
goto V_36;
}
F_36 () ;
if ( ! F_37 ( & V_8 -> V_13 [ V_11 ] , V_27 , & V_18 ) )
V_20 = - V_25 ;
F_38 ( & V_8 -> V_4 ) ;
V_34:
* V_33 = V_8 ;
return V_20 ;
}
void F_39 ( int V_11 , unsigned long V_27 ,
struct V_1 * V_8 ,
struct V_26 * V_26 )
{
if ( F_33 () || ! V_8 )
return;
F_25 ( V_26 , V_8 ) ;
return;
}
void F_40 ( int V_11 , unsigned long V_27 ,
struct V_26 * V_26 )
{
struct V_1 * V_8 ;
if ( F_33 () )
return;
F_41 ( & V_32 ) ;
V_8 = F_21 ( V_26 ) ;
if ( F_42 ( ! V_8 ) )
return;
F_25 ( V_26 , NULL ) ;
F_43 ( & V_8 -> V_13 [ V_11 ] , V_27 ) ;
return;
}
void F_44 ( int V_11 , unsigned long V_27 ,
struct V_1 * V_8 )
{
if ( F_33 () || ! V_8 )
return;
if ( F_12 ( & V_22 [ V_11 ] ) < V_35 )
return;
F_43 ( & V_8 -> V_13 [ V_11 ] , V_27 ) ;
return;
}
static T_1 F_45 ( struct V_2 * V_4 ,
struct V_38 * V_39 )
{
struct V_17 * V_18 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_18 = & V_8 -> V_13 [ F_46 ( V_39 -> V_40 ) ] ;
switch ( F_47 ( V_39 -> V_40 ) ) {
case V_41 :
return ( T_1 ) F_8 ( V_18 ) * V_42 ;
case V_43 :
return ( T_1 ) V_18 -> V_19 * V_42 ;
case V_44 :
return ( T_1 ) V_18 -> V_45 * V_42 ;
case V_46 :
return V_18 -> V_47 ;
default:
F_48 () ;
}
}
static T_2 F_49 ( struct V_48 * V_49 ,
char * V_50 , T_3 V_51 , T_4 V_52 )
{
int V_20 , V_11 ;
unsigned long V_27 ;
struct V_1 * V_8 = F_1 ( F_50 ( V_49 ) ) ;
if ( F_5 ( V_8 ) )
return - V_53 ;
V_50 = F_51 ( V_50 ) ;
V_20 = F_52 ( V_50 , L_1 , & V_27 ) ;
if ( V_20 )
return V_20 ;
V_11 = F_46 ( F_53 ( V_49 ) -> V_40 ) ;
V_27 = F_11 ( V_27 , 1 << F_12 ( & V_22 [ V_11 ] ) ) ;
switch ( F_47 ( F_53 ( V_49 ) -> V_40 ) ) {
case V_43 :
F_54 ( & V_54 ) ;
V_20 = F_13 ( & V_8 -> V_13 [ V_11 ] , V_27 ) ;
F_55 ( & V_54 ) ;
break;
default:
V_20 = - V_53 ;
break;
}
return V_20 ? : V_51 ;
}
static T_2 F_56 ( struct V_48 * V_49 ,
char * V_50 , T_3 V_51 , T_4 V_52 )
{
int V_20 = 0 ;
struct V_17 * V_18 ;
struct V_1 * V_8 = F_1 ( F_50 ( V_49 ) ) ;
V_18 = & V_8 -> V_13 [ F_46 ( F_53 ( V_49 ) -> V_40 ) ] ;
switch ( F_47 ( F_53 ( V_49 ) -> V_40 ) ) {
case V_44 :
F_57 ( V_18 ) ;
break;
case V_46 :
V_18 -> V_47 = 0 ;
break;
default:
V_20 = - V_53 ;
break;
}
return V_20 ? : V_51 ;
}
static char * F_58 ( char * V_50 , int V_55 , unsigned long V_56 )
{
if ( V_56 >= ( 1UL << 30 ) )
snprintf ( V_50 , V_55 , L_2 , V_56 >> 30 ) ;
else if ( V_56 >= ( 1UL << 20 ) )
snprintf ( V_50 , V_55 , L_3 , V_56 >> 20 ) ;
else
snprintf ( V_50 , V_55 , L_4 , V_56 >> 10 ) ;
return V_50 ;
}
static void T_5 F_59 ( int V_11 )
{
char V_50 [ 32 ] ;
struct V_38 * V_39 ;
struct V_30 * V_31 = & V_22 [ V_11 ] ;
F_58 ( V_50 , 32 , F_60 ( V_31 ) ) ;
V_39 = & V_31 -> V_57 [ 0 ] ;
snprintf ( V_39 -> V_58 , V_59 , L_5 , V_50 ) ;
V_39 -> V_40 = F_61 ( V_11 , V_43 ) ;
V_39 -> V_60 = F_45 ;
V_39 -> V_61 = F_49 ;
V_39 = & V_31 -> V_57 [ 1 ] ;
snprintf ( V_39 -> V_58 , V_59 , L_6 , V_50 ) ;
V_39 -> V_40 = F_61 ( V_11 , V_41 ) ;
V_39 -> V_60 = F_45 ;
V_39 = & V_31 -> V_57 [ 2 ] ;
snprintf ( V_39 -> V_58 , V_59 , L_7 , V_50 ) ;
V_39 -> V_40 = F_61 ( V_11 , V_44 ) ;
V_39 -> V_61 = F_56 ;
V_39 -> V_60 = F_45 ;
V_39 = & V_31 -> V_57 [ 3 ] ;
snprintf ( V_39 -> V_58 , V_59 , L_8 , V_50 ) ;
V_39 -> V_40 = F_61 ( V_11 , V_46 ) ;
V_39 -> V_61 = F_56 ;
V_39 -> V_60 = F_45 ;
V_39 = & V_31 -> V_57 [ 4 ] ;
memset ( V_39 , 0 , sizeof( * V_39 ) ) ;
F_62 ( F_63 ( & V_62 ,
V_31 -> V_57 ) ) ;
}
void T_5 F_64 ( void )
{
struct V_30 * V_31 ;
F_27 (h) {
if ( F_12 ( V_31 ) >= V_35 )
F_59 ( F_65 ( V_31 ) ) ;
}
}
void F_66 ( struct V_26 * V_63 , struct V_26 * V_64 )
{
struct V_1 * V_8 ;
struct V_30 * V_31 = F_67 ( V_63 ) ;
if ( F_33 () )
return;
F_68 ( ! F_69 ( V_63 ) , V_63 ) ;
F_28 ( & V_32 ) ;
V_8 = F_21 ( V_63 ) ;
F_25 ( V_63 , NULL ) ;
F_25 ( V_64 , V_8 ) ;
F_70 ( & V_64 -> V_65 , & V_31 -> V_66 ) ;
F_30 ( & V_32 ) ;
return;
}
