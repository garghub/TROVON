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
static struct V_2 *
F_9 ( struct V_2 * V_14 )
{
struct V_1 * V_15 = F_1 ( V_14 ) ;
struct V_1 * V_16 ;
int V_11 ;
V_16 = F_10 ( sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return F_11 ( - V_18 ) ;
if ( V_15 ) {
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ )
F_12 ( & V_16 -> V_13 [ V_11 ] ,
& V_15 -> V_13 [ V_11 ] ) ;
} else {
V_9 = V_16 ;
for ( V_11 = 0 ; V_11 < V_19 ; V_11 ++ )
F_12 ( & V_16 -> V_13 [ V_11 ] , NULL ) ;
}
return & V_16 -> V_4 ;
}
static void F_13 ( struct V_2 * V_4 )
{
struct V_1 * V_16 ;
V_16 = F_1 ( V_4 ) ;
F_14 ( V_16 ) ;
}
static void F_15 ( int V_11 , struct V_1 * V_8 ,
struct V_20 * V_20 )
{
unsigned int V_21 ;
struct V_22 * V_23 ;
struct V_1 * V_24 ;
struct V_1 * V_10 = F_6 ( V_8 ) ;
V_24 = F_16 ( V_20 ) ;
if ( ! V_24 || V_24 != V_8 )
goto V_25;
V_21 = 1 << F_17 ( V_20 ) ;
if ( ! V_10 ) {
V_10 = V_9 ;
F_18 ( & V_10 -> V_13 [ V_11 ] , V_21 ) ;
}
V_23 = & V_8 -> V_13 [ V_11 ] ;
F_19 ( V_23 , V_21 ) ;
F_20 ( V_20 , V_10 ) ;
V_25:
return;
}
static void F_21 ( struct V_2 * V_4 )
{
struct V_1 * V_8 = F_1 ( V_4 ) ;
struct V_26 * V_27 ;
struct V_20 * V_20 ;
int V_11 = 0 ;
do {
F_22 (h) {
F_23 ( & V_28 ) ;
F_24 (page, &h->hugepage_activelist, lru)
F_15 ( V_11 , V_8 , V_20 ) ;
F_25 ( & V_28 ) ;
V_11 ++ ;
}
F_26 () ;
} while ( F_7 ( V_8 ) );
}
int F_27 ( int V_11 , unsigned long V_21 ,
struct V_1 * * V_29 )
{
int V_30 = 0 ;
struct V_22 * V_23 ;
struct V_1 * V_8 = NULL ;
if ( F_28 () )
goto V_31;
if ( F_29 ( & V_32 [ V_11 ] ) < V_33 )
goto V_31;
V_34:
F_30 () ;
V_8 = F_3 ( V_35 ) ;
if ( ! F_31 ( & V_8 -> V_4 ) ) {
F_32 () ;
goto V_34;
}
F_32 () ;
if ( ! F_33 ( & V_8 -> V_13 [ V_11 ] , V_21 , & V_23 ) )
V_30 = - V_18 ;
F_34 ( & V_8 -> V_4 ) ;
V_31:
* V_29 = V_8 ;
return V_30 ;
}
void F_35 ( int V_11 , unsigned long V_21 ,
struct V_1 * V_8 ,
struct V_20 * V_20 )
{
if ( F_28 () || ! V_8 )
return;
F_20 ( V_20 , V_8 ) ;
return;
}
void F_36 ( int V_11 , unsigned long V_21 ,
struct V_20 * V_20 )
{
struct V_1 * V_8 ;
if ( F_28 () )
return;
F_37 ( & V_28 ) ;
V_8 = F_16 ( V_20 ) ;
if ( F_38 ( ! V_8 ) )
return;
F_20 ( V_20 , NULL ) ;
F_39 ( & V_8 -> V_13 [ V_11 ] , V_21 ) ;
return;
}
void F_40 ( int V_11 , unsigned long V_21 ,
struct V_1 * V_8 )
{
if ( F_28 () || ! V_8 )
return;
if ( F_29 ( & V_32 [ V_11 ] ) < V_33 )
return;
F_39 ( & V_8 -> V_13 [ V_11 ] , V_21 ) ;
return;
}
static T_1 F_41 ( struct V_2 * V_4 ,
struct V_36 * V_37 )
{
struct V_22 * V_23 ;
struct V_1 * V_8 = F_1 ( V_4 ) ;
V_23 = & V_8 -> V_13 [ F_42 ( V_37 -> V_38 ) ] ;
switch ( F_43 ( V_37 -> V_38 ) ) {
case V_39 :
return ( T_1 ) F_8 ( V_23 ) * V_40 ;
case V_41 :
return ( T_1 ) V_23 -> V_42 * V_40 ;
case V_43 :
return ( T_1 ) V_23 -> V_44 * V_40 ;
case V_45 :
return V_23 -> V_46 ;
default:
F_44 () ;
}
}
static T_2 F_45 ( struct V_47 * V_48 ,
char * V_49 , T_3 V_50 , T_4 V_51 )
{
int V_30 , V_11 ;
unsigned long V_21 ;
struct V_1 * V_8 = F_1 ( F_46 ( V_48 ) ) ;
if ( F_5 ( V_8 ) )
return - V_52 ;
V_49 = F_47 ( V_49 ) ;
V_30 = F_48 ( V_49 , L_1 , & V_21 ) ;
if ( V_30 )
return V_30 ;
V_11 = F_42 ( F_49 ( V_48 ) -> V_38 ) ;
switch ( F_43 ( F_49 ( V_48 ) -> V_38 ) ) {
case V_41 :
F_50 ( & V_53 ) ;
V_30 = F_51 ( & V_8 -> V_13 [ V_11 ] , V_21 ) ;
F_52 ( & V_53 ) ;
break;
default:
V_30 = - V_52 ;
break;
}
return V_30 ? : V_50 ;
}
static T_2 F_53 ( struct V_47 * V_48 ,
char * V_49 , T_3 V_50 , T_4 V_51 )
{
int V_30 = 0 ;
struct V_22 * V_23 ;
struct V_1 * V_8 = F_1 ( F_46 ( V_48 ) ) ;
V_23 = & V_8 -> V_13 [ F_42 ( F_49 ( V_48 ) -> V_38 ) ] ;
switch ( F_43 ( F_49 ( V_48 ) -> V_38 ) ) {
case V_43 :
F_54 ( V_23 ) ;
break;
case V_45 :
V_23 -> V_46 = 0 ;
break;
default:
V_30 = - V_52 ;
break;
}
return V_30 ? : V_50 ;
}
static char * F_55 ( char * V_49 , int V_54 , unsigned long V_55 )
{
if ( V_55 >= ( 1UL << 30 ) )
snprintf ( V_49 , V_54 , L_2 , V_55 >> 30 ) ;
else if ( V_55 >= ( 1UL << 20 ) )
snprintf ( V_49 , V_54 , L_3 , V_55 >> 20 ) ;
else
snprintf ( V_49 , V_54 , L_4 , V_55 >> 10 ) ;
return V_49 ;
}
static void T_5 F_56 ( int V_11 )
{
char V_49 [ 32 ] ;
struct V_36 * V_37 ;
struct V_26 * V_27 = & V_32 [ V_11 ] ;
F_55 ( V_49 , 32 , F_57 ( V_27 ) ) ;
V_37 = & V_27 -> V_56 [ 0 ] ;
snprintf ( V_37 -> V_57 , V_58 , L_5 , V_49 ) ;
V_37 -> V_38 = F_58 ( V_11 , V_41 ) ;
V_37 -> V_59 = F_41 ;
V_37 -> V_60 = F_45 ;
V_37 = & V_27 -> V_56 [ 1 ] ;
snprintf ( V_37 -> V_57 , V_58 , L_6 , V_49 ) ;
V_37 -> V_38 = F_58 ( V_11 , V_39 ) ;
V_37 -> V_59 = F_41 ;
V_37 = & V_27 -> V_56 [ 2 ] ;
snprintf ( V_37 -> V_57 , V_58 , L_7 , V_49 ) ;
V_37 -> V_38 = F_58 ( V_11 , V_43 ) ;
V_37 -> V_60 = F_53 ;
V_37 -> V_59 = F_41 ;
V_37 = & V_27 -> V_56 [ 3 ] ;
snprintf ( V_37 -> V_57 , V_58 , L_8 , V_49 ) ;
V_37 -> V_38 = F_58 ( V_11 , V_45 ) ;
V_37 -> V_60 = F_53 ;
V_37 -> V_59 = F_41 ;
V_37 = & V_27 -> V_56 [ 4 ] ;
memset ( V_37 , 0 , sizeof( * V_37 ) ) ;
F_59 ( F_60 ( & V_61 ,
V_27 -> V_56 ) ) ;
}
void T_5 F_61 ( void )
{
struct V_26 * V_27 ;
F_22 (h) {
if ( F_29 ( V_27 ) >= V_33 )
F_56 ( F_62 ( V_27 ) ) ;
}
}
void F_63 ( struct V_20 * V_62 , struct V_20 * V_63 )
{
struct V_1 * V_8 ;
struct V_26 * V_27 = F_64 ( V_62 ) ;
if ( F_28 () )
return;
F_65 ( ! F_66 ( V_62 ) , V_62 ) ;
F_23 ( & V_28 ) ;
V_8 = F_16 ( V_62 ) ;
F_20 ( V_62 , NULL ) ;
F_20 ( V_63 , V_8 ) ;
F_67 ( & V_63 -> V_64 , & V_27 -> V_65 ) ;
F_25 ( & V_28 ) ;
return;
}
