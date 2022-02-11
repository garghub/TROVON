void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_3 ( & V_2 -> V_4 , & V_5 ) ;
F_4 ( & V_3 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
F_2 ( & V_3 ) ;
F_6 ( & V_2 -> V_4 ) ;
F_4 ( & V_3 ) ;
}
static struct V_1 *
F_7 ( struct V_6 * V_7 , int V_8 , char * * V_9 )
{
struct V_1 * V_10 ;
struct V_11 * V_4 ;
char * V_12 ;
V_10 = NULL ;
V_12 = NULL ;
F_2 ( & V_3 ) ;
F_8 (list, &dsa_switch_drivers) {
struct V_1 * V_2 ;
V_2 = F_9 ( V_4 , struct V_1 , V_4 ) ;
V_12 = V_2 -> V_13 ( V_7 , V_8 ) ;
if ( V_12 != NULL ) {
V_10 = V_2 ;
break;
}
}
F_4 ( & V_3 ) ;
* V_9 = V_12 ;
return V_10 ;
}
static struct V_14 *
F_10 ( struct V_15 * V_16 , int V_17 ,
struct V_18 * V_19 , struct V_6 * V_7 )
{
struct V_20 * V_21 = V_16 -> V_21 -> V_22 + V_17 ;
struct V_1 * V_2 ;
struct V_14 * V_23 ;
int V_10 ;
char * V_12 ;
int V_24 ;
bool V_25 = false ;
V_2 = F_7 ( V_7 , V_21 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_11 ( V_26 L_1 ,
V_16 -> V_27 -> V_12 , V_17 ) ;
return F_12 ( - V_28 ) ;
}
F_11 ( V_29 L_2 ,
V_16 -> V_27 -> V_12 , V_17 , V_12 ) ;
V_23 = F_13 ( sizeof( * V_23 ) + V_2 -> V_30 , V_31 ) ;
if ( V_23 == NULL )
return F_12 ( - V_32 ) ;
V_23 -> V_16 = V_16 ;
V_23 -> V_17 = V_17 ;
V_23 -> V_21 = V_16 -> V_21 -> V_22 + V_17 ;
V_23 -> V_2 = V_2 ;
V_23 -> V_33 = V_7 ;
for ( V_24 = 0 ; V_24 < V_34 ; V_24 ++ ) {
char * V_12 ;
V_12 = V_21 -> V_35 [ V_24 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_3 ) ) {
if ( V_16 -> V_36 != - 1 ) {
F_11 ( V_26 L_4 ) ;
V_10 = - V_28 ;
goto V_37;
}
V_16 -> V_36 = V_17 ;
V_16 -> V_38 = V_24 ;
} else if ( ! strcmp ( V_12 , L_5 ) ) {
V_23 -> V_39 |= 1 << V_24 ;
} else {
V_23 -> V_40 |= 1 << V_24 ;
}
V_25 = true ;
}
if ( ! V_25 && V_24 == V_34 ) {
V_10 = - V_28 ;
goto V_37;
}
if ( V_23 -> V_16 -> V_36 == V_17 )
V_23 -> V_16 -> V_41 = V_2 -> V_41 ;
V_10 = V_2 -> V_42 ( V_23 ) ;
if ( V_10 < 0 )
goto V_37;
V_10 = V_2 -> V_43 ( V_23 , V_16 -> V_27 -> V_44 ) ;
if ( V_10 < 0 )
goto V_37;
V_23 -> V_45 = F_14 () ;
if ( V_23 -> V_45 == NULL ) {
V_10 = - V_32 ;
goto V_37;
}
F_15 ( V_23 ) ;
V_10 = F_16 ( V_23 -> V_45 ) ;
if ( V_10 < 0 )
goto V_46;
for ( V_24 = 0 ; V_24 < V_34 ; V_24 ++ ) {
struct V_47 * V_48 ;
if ( ! ( V_23 -> V_40 & ( 1 << V_24 ) ) )
continue;
V_48 = F_17 ( V_23 , V_19 , V_24 , V_21 -> V_35 [ V_24 ] ) ;
if ( V_48 == NULL ) {
F_11 ( V_26 L_6
L_7 ,
V_16 -> V_27 -> V_12 ,
V_17 , V_24 , V_21 -> V_35 [ V_24 ] ) ;
continue;
}
V_23 -> V_49 [ V_24 ] = V_48 ;
}
return V_23 ;
V_46:
F_18 ( V_23 -> V_45 ) ;
V_37:
F_19 ( V_23 ) ;
return F_12 ( V_10 ) ;
}
static void F_20 ( struct V_14 * V_23 )
{
}
static void F_21 ( struct V_50 * V_51 )
{
struct V_15 * V_16 ;
int V_24 ;
V_16 = F_22 ( V_51 , struct V_15 , V_52 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_21 -> V_53 ; V_24 ++ ) {
struct V_14 * V_23 = V_16 -> V_23 [ V_24 ] ;
if ( V_23 != NULL && V_23 -> V_2 -> V_54 != NULL )
V_23 -> V_2 -> V_54 ( V_23 ) ;
}
F_23 ( & V_16 -> V_55 , F_24 ( V_56 + V_57 ) ) ;
}
static void F_25 ( unsigned long V_58 )
{
struct V_15 * V_16 = ( void * ) V_58 ;
F_26 ( & V_16 -> V_52 ) ;
}
static int F_27 ( struct V_18 * V_59 , void * V_60 )
{
if ( V_59 -> V_60 != NULL && ! strcmp ( V_59 -> V_60 -> V_12 , V_60 ) )
return 1 ;
return 0 ;
}
static struct V_18 * F_28 ( struct V_18 * V_19 , char * V_60 )
{
if ( F_27 ( V_19 , V_60 ) ) {
F_29 ( V_19 ) ;
return V_19 ;
}
return F_30 ( V_19 , V_60 , F_27 ) ;
}
static struct V_6 * F_31 ( struct V_18 * V_59 )
{
struct V_18 * V_61 ;
V_61 = F_28 ( V_59 , L_8 ) ;
if ( V_61 != NULL ) {
struct V_6 * V_7 ;
V_7 = F_32 ( V_61 ) ;
F_33 ( V_61 ) ;
return V_7 ;
}
return NULL ;
}
static struct V_47 * F_34 ( struct V_18 * V_59 )
{
struct V_18 * V_61 ;
V_61 = F_28 ( V_59 , L_9 ) ;
if ( V_61 != NULL ) {
struct V_47 * V_62 ;
V_62 = F_35 ( V_61 ) ;
F_36 ( V_62 ) ;
F_33 ( V_61 ) ;
return V_62 ;
}
return NULL ;
}
static int F_37 ( struct V_63 * V_64 )
{
static int V_65 ;
struct V_66 * V_21 = V_64 -> V_59 . V_67 ;
struct V_47 * V_59 ;
struct V_15 * V_16 ;
int V_24 ;
if ( ! V_65 ++ )
F_11 ( V_68 L_10
L_11 , V_69 ) ;
if ( V_21 == NULL || V_21 -> V_70 == NULL )
return - V_28 ;
V_59 = F_34 ( V_21 -> V_70 ) ;
if ( V_59 == NULL )
return - V_28 ;
if ( V_59 -> V_71 != NULL ) {
F_38 ( V_59 ) ;
return - V_72 ;
}
V_16 = F_13 ( sizeof( * V_16 ) , V_31 ) ;
if ( V_16 == NULL ) {
F_38 ( V_59 ) ;
return - V_32 ;
}
F_39 ( V_64 , V_16 ) ;
V_16 -> V_21 = V_21 ;
V_16 -> V_27 = V_59 ;
V_16 -> V_36 = - 1 ;
V_16 -> V_38 = - 1 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_53 ; V_24 ++ ) {
struct V_6 * V_7 ;
struct V_14 * V_23 ;
V_7 = F_31 ( V_21 -> V_22 [ V_24 ] . V_6 ) ;
if ( V_7 == NULL ) {
F_11 ( V_26 L_12
L_13 , V_59 -> V_12 , V_24 ) ;
continue;
}
V_23 = F_10 ( V_16 , V_24 , & V_64 -> V_59 , V_7 ) ;
if ( F_40 ( V_23 ) ) {
F_11 ( V_26 L_14
L_15 , V_59 -> V_12 , V_24 ,
F_41 ( V_23 ) ) ;
continue;
}
V_16 -> V_23 [ V_24 ] = V_23 ;
if ( V_23 -> V_2 -> V_54 != NULL )
V_16 -> V_73 = 1 ;
}
F_42 () ;
V_59 -> V_71 = ( void * ) V_16 ;
if ( V_16 -> V_73 ) {
F_43 ( & V_16 -> V_52 , F_21 ) ;
F_44 ( & V_16 -> V_55 ) ;
V_16 -> V_55 . V_74 = ( unsigned long ) V_16 ;
V_16 -> V_55 . V_75 = F_25 ;
V_16 -> V_55 . V_76 = F_24 ( V_56 + V_57 ) ;
F_45 ( & V_16 -> V_55 ) ;
}
return 0 ;
}
static int F_46 ( struct V_63 * V_64 )
{
struct V_15 * V_16 = F_47 ( V_64 ) ;
int V_24 ;
if ( V_16 -> V_73 )
F_48 ( & V_16 -> V_55 ) ;
F_49 ( & V_16 -> V_52 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_21 -> V_53 ; V_24 ++ ) {
struct V_14 * V_23 = V_16 -> V_23 [ V_24 ] ;
if ( V_23 != NULL )
F_20 ( V_23 ) ;
}
return 0 ;
}
static void F_50 ( struct V_63 * V_64 )
{
}
static int T_1 F_51 ( void )
{
int V_77 ;
V_77 = F_52 ( & V_78 ) ;
if ( V_77 )
return V_77 ;
#ifdef F_53
F_54 ( & V_79 ) ;
#endif
#ifdef F_55
F_54 ( & V_80 ) ;
#endif
#ifdef F_56
F_54 ( & V_81 ) ;
#endif
return 0 ;
}
static void T_2 F_57 ( void )
{
#ifdef F_56
F_58 ( & V_81 ) ;
#endif
#ifdef F_55
F_58 ( & V_80 ) ;
#endif
#ifdef F_53
F_58 ( & V_79 ) ;
#endif
F_59 ( & V_78 ) ;
}
