static int T_1 F_1 ( void )
{
struct V_1 * V_2 = V_3 ;
struct V_4 * V_5 = & V_2 -> V_5 ;
struct V_6 T_2 * V_7 ;
T_3 V_8 , V_9 , V_10 ;
T_4 V_11 ;
V_8 = F_2 ( & V_2 -> V_5 , V_12 ) ;
V_9 = F_2 ( & V_2 -> V_5 , V_13 ) ;
V_10 = V_8 | ( V_9 << 32 ) ;
V_2 -> V_14 = F_3 ( V_5 , V_10 , V_15 ) ;
if ( ! V_2 -> V_14 ) {
F_4 ( V_2 -> V_16 , L_1 ) ;
return - V_17 ;
}
V_7 = V_2 -> V_14 ;
V_11 = F_5 ( & V_7 -> V_11 ) ;
if ( V_18 != V_11 ) {
F_4 ( V_2 -> V_16 , L_2 , V_11 ) ;
return - V_19 ;
}
return 0 ;
}
static void F_6 ( void )
{
F_7 ( & V_3 -> V_5 , V_3 -> V_14 ) ;
}
struct V_20 *
F_8 ( T_5 V_21 ,
T_5 V_22 , const char * V_23 ,
void * V_24 , int V_25 )
{
int V_26 = 0 ;
unsigned long V_27 ;
struct V_1 * V_2 = V_3 ;
V_26 = F_9 ( F_10 ( V_2 , V_25 ) , V_21 ,
V_22 , 0 , V_23 , V_24 ) ;
if ( V_26 ) {
F_4 ( V_2 -> V_16 , L_3 , V_26 ) ;
goto V_28;
}
V_2 -> V_29 . V_30 [ V_25 ] ++ ;
V_27 = V_25 ;
return (struct V_20 * ) V_27 ;
V_28:
return F_11 ( V_26 ) ;
}
void F_12 ( struct V_20 * V_27 , void * V_24 )
{
int V_25 ;
struct V_1 * V_2 = V_3 ;
V_25 = ( unsigned long ) V_27 & 0xFFFFU ;
F_13 ( F_10 ( V_2 , V_25 ) , V_24 ) ;
V_2 -> V_29 . V_30 [ V_25 ] -- ;
}
int F_14 ( void )
{
int V_31 ;
int V_25 = 0 ;
struct V_1 * V_2 = V_3 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 . V_33 ; V_31 ++ ) {
if ( V_2 -> V_29 . V_30 [ V_31 ] <
V_2 -> V_29 . V_30 [ V_25 ] )
V_25 = V_31 ;
}
return V_25 ;
}
static int F_15 ( void )
{
struct V_1 * V_2 = V_3 ;
V_2 -> V_29 . V_30 = F_16 ( ( sizeof( T_4 ) *
V_2 -> V_32 . V_33 ) ,
V_34 ) ;
if ( ! V_2 -> V_29 . V_30 )
return - V_17 ;
return 0 ;
}
static void F_17 ( void )
{
struct V_1 * V_2 = V_3 ;
F_18 ( V_2 -> V_29 . V_30 ) ;
}
static inline struct V_1 * F_19 ( struct V_35 * V_36 )
{
return F_20 ( V_36 -> V_16 . V_37 ) ;
}
static struct V_20 *
F_21 ( struct V_35 * V_36 ,
T_6 (* F_22)( int V_38 , void * V_24 ) ,
const char * V_23 , void * V_24 ,
int V_39 )
{
return F_8 ( F_22 , NULL , V_23 , V_24 , V_39 ) ;
}
static void
F_23 ( struct V_35 * V_36 ,
struct V_20 * V_27 , void * V_24 )
{
return F_12 ( V_27 , V_24 ) ;
}
static void F_24 ( struct V_35 * V_36 , int V_40 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
F_25 ( & V_2 -> V_5 ) ;
}
static int F_26 ( struct V_35 * V_36 )
{
return F_14 () ;
}
static void F_27 ( struct V_35 * V_36 , int V_39 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
F_28 ( & V_2 -> V_5 , V_39 ) ;
}
static void F_29 ( struct V_35 * V_36 , int V_39 ,
struct V_41 * V_42 )
{
F_30 ( V_39 , V_42 ) ;
}
static void T_2 *
F_31 ( struct V_35 * V_36 ,
T_7 V_43 , T_8 V_44 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
return F_3 ( & V_2 -> V_5 , V_43 , V_44 ) ;
}
static void F_32 ( struct V_35 * V_36 , void T_2 * V_45 )
{
struct V_1 * V_2 = F_19 ( V_36 ) ;
F_7 ( & V_2 -> V_5 , V_45 ) ;
}
static inline struct V_1 * F_33 ( struct V_46 * V_47 )
{
return F_20 ( V_47 -> V_16 . V_37 ) ;
}
static struct V_20 *
F_34 ( struct V_46 * V_47 ,
T_6 (* F_22)( int V_38 , void * V_24 ) ,
const char * V_23 , void * V_24 , int V_48 )
{
return F_8 ( F_22 , NULL , V_23 , V_24 , V_48 ) ;
}
static void F_35 ( struct V_46 * V_47 ,
struct V_20 * V_27 , void * V_24 )
{
return F_12 ( V_27 , V_24 ) ;
}
static void F_36 ( struct V_46 * V_47 , int V_40 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
F_25 ( & V_2 -> V_5 ) ;
}
static int F_37 ( struct V_46 * V_47 )
{
return F_14 () ;
}
static void T_2 * F_38 ( struct V_46 * V_47 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
return V_2 -> V_14 ;
}
static void F_39 ( struct V_46 * V_47 , int V_39 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
F_28 ( & V_2 -> V_5 , V_39 ) ;
}
static void T_2 * F_40 ( struct V_46 * V_47 ,
T_9 V_43 , T_8 V_44 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
return F_3 ( & V_2 -> V_5 , V_43 , V_44 ) ;
}
static void F_41 ( struct V_46 * V_47 , void T_2 * V_45 )
{
struct V_1 * V_2 = F_33 ( V_47 ) ;
F_7 ( & V_2 -> V_5 , V_45 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
T_10 V_49 ;
struct V_50 * V_51 ;
F_43 ( V_49 ) ;
F_44 ( V_52 , V_49 ) ;
do {
V_51 = F_45 ( V_49 , NULL , NULL ) ;
if ( V_51 ) {
V_2 -> V_53 [ V_2 -> V_54 ++ ] = V_51 ;
if ( V_2 -> V_54 >= V_55 )
break;
}
} while ( V_51 );
F_46 ( V_2 -> V_16 , L_4 , V_2 -> V_54 ) ;
return V_2 -> V_54 ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_31 = 0 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_54 ; V_31 ++ ) {
F_48 ( V_2 -> V_53 [ V_31 ] ) ;
V_2 -> V_53 [ V_31 ] = NULL ;
}
V_2 -> V_54 = 0 ;
}
int T_1 F_49 ( struct V_1 * V_2 )
{
int V_26 ;
struct V_6 T_2 * V_7 ;
T_11 V_56 ;
V_3 = V_2 ;
if ( ! F_50 ( V_2 -> V_16 -> V_57 -> V_58 ) ) {
V_26 = - V_59 ;
goto V_60;
}
V_26 = F_1 () ;
if ( V_26 )
goto V_61;
V_26 = F_15 () ;
if ( V_26 )
goto V_62;
if ( ! F_42 ( V_2 ) ) {
V_26 = - V_59 ;
goto V_63;
}
V_2 -> V_47 = F_51 ( V_2 -> V_16 , V_64 ,
NULL , & V_65 , 0 ,
NULL , V_2 -> V_53 [ 0 ] ) ;
if ( F_52 ( V_2 -> V_47 ) ) {
V_26 = F_53 ( V_2 -> V_47 ) ;
goto V_66;
}
V_7 = V_2 -> V_14 ;
V_56 = F_54 ( & V_7 -> V_56 ) ;
V_2 -> V_36 = F_55 ( V_2 -> V_16 , V_67 ,
NULL , & V_68 ,
0 , V_56 , & V_2 -> V_5 . V_69 , NULL ,
NULL , V_2 -> V_14 , V_2 -> V_53 ,
V_2 -> V_54 , true ) ;
if ( F_52 ( V_2 -> V_36 ) ) {
V_26 = F_53 ( V_2 -> V_36 ) ;
goto V_70;
}
F_56 ( V_2 ) ;
V_60:
return V_26 ;
V_70:
F_57 ( V_2 -> V_47 ) ;
V_66:
F_47 ( V_2 ) ;
V_63:
F_17 () ;
V_62:
F_6 () ;
V_61:
F_58 ( V_2 -> V_16 -> V_57 -> V_58 ) ;
return V_26 ;
}
void F_59 ( struct V_1 * V_2 )
{
F_60 ( V_2 ) ;
F_61 ( V_2 -> V_36 ) ;
F_57 ( V_2 -> V_47 ) ;
F_47 ( V_2 ) ;
F_17 () ;
F_6 () ;
F_58 ( V_2 -> V_16 -> V_57 -> V_58 ) ;
}
