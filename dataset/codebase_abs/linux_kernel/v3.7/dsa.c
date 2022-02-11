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
V_2 = F_7 ( V_7 , V_21 -> V_8 , & V_12 ) ;
if ( V_2 == NULL ) {
F_11 ( V_25 L_1 ,
V_16 -> V_26 -> V_12 , V_17 ) ;
return F_12 ( - V_27 ) ;
}
F_11 ( V_28 L_2 ,
V_16 -> V_26 -> V_12 , V_17 , V_12 ) ;
V_23 = F_13 ( sizeof( * V_23 ) + V_2 -> V_29 , V_30 ) ;
if ( V_23 == NULL )
return F_12 ( - V_31 ) ;
V_23 -> V_16 = V_16 ;
V_23 -> V_17 = V_17 ;
V_23 -> V_21 = V_16 -> V_21 -> V_22 + V_17 ;
V_23 -> V_2 = V_2 ;
V_23 -> V_32 = V_7 ;
for ( V_24 = 0 ; V_24 < V_33 ; V_24 ++ ) {
char * V_12 ;
V_12 = V_21 -> V_34 [ V_24 ] ;
if ( V_12 == NULL )
continue;
if ( ! strcmp ( V_12 , L_3 ) ) {
if ( V_16 -> V_35 != - 1 ) {
F_11 ( V_25 L_4 ) ;
V_10 = - V_27 ;
goto V_36;
}
V_16 -> V_35 = V_17 ;
V_16 -> V_37 = V_24 ;
} else if ( ! strcmp ( V_12 , L_5 ) ) {
V_23 -> V_38 |= 1 << V_24 ;
} else {
V_23 -> V_39 |= 1 << V_24 ;
}
}
if ( V_23 -> V_16 -> V_35 == V_17 )
V_23 -> V_16 -> V_40 = V_2 -> V_40 ;
V_10 = V_2 -> V_41 ( V_23 ) ;
if ( V_10 < 0 )
goto V_36;
V_10 = V_2 -> V_42 ( V_23 , V_16 -> V_26 -> V_43 ) ;
if ( V_10 < 0 )
goto V_36;
V_23 -> V_44 = F_14 () ;
if ( V_23 -> V_44 == NULL ) {
V_10 = - V_31 ;
goto V_36;
}
F_15 ( V_23 ) ;
V_10 = F_16 ( V_23 -> V_44 ) ;
if ( V_10 < 0 )
goto V_45;
for ( V_24 = 0 ; V_24 < V_33 ; V_24 ++ ) {
struct V_46 * V_47 ;
if ( ! ( V_23 -> V_39 & ( 1 << V_24 ) ) )
continue;
V_47 = F_17 ( V_23 , V_19 , V_24 , V_21 -> V_34 [ V_24 ] ) ;
if ( V_47 == NULL ) {
F_11 ( V_25 L_6
L_7 ,
V_16 -> V_26 -> V_12 ,
V_17 , V_24 , V_21 -> V_34 [ V_24 ] ) ;
continue;
}
V_23 -> V_48 [ V_24 ] = V_47 ;
}
return V_23 ;
V_45:
F_18 ( V_23 -> V_44 ) ;
V_36:
F_19 ( V_23 ) ;
return F_12 ( V_10 ) ;
}
static void F_20 ( struct V_14 * V_23 )
{
}
static void F_21 ( struct V_49 * V_50 )
{
struct V_15 * V_16 ;
int V_24 ;
V_16 = F_22 ( V_50 , struct V_15 , V_51 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_21 -> V_52 ; V_24 ++ ) {
struct V_14 * V_23 = V_16 -> V_23 [ V_24 ] ;
if ( V_23 != NULL && V_23 -> V_2 -> V_53 != NULL )
V_23 -> V_2 -> V_53 ( V_23 ) ;
}
F_23 ( & V_16 -> V_54 , F_24 ( V_55 + V_56 ) ) ;
}
static void F_25 ( unsigned long V_57 )
{
struct V_15 * V_16 = ( void * ) V_57 ;
F_26 ( & V_16 -> V_51 ) ;
}
static int F_27 ( struct V_18 * V_58 , void * V_59 )
{
if ( V_58 -> V_59 != NULL && ! strcmp ( V_58 -> V_59 -> V_12 , V_59 ) )
return 1 ;
return 0 ;
}
static struct V_18 * F_28 ( struct V_18 * V_19 , char * V_59 )
{
if ( F_27 ( V_19 , V_59 ) ) {
F_29 ( V_19 ) ;
return V_19 ;
}
return F_30 ( V_19 , V_59 , F_27 ) ;
}
static struct V_6 * F_31 ( struct V_18 * V_58 )
{
struct V_18 * V_60 ;
V_60 = F_28 ( V_58 , L_8 ) ;
if ( V_60 != NULL ) {
struct V_6 * V_7 ;
V_7 = F_32 ( V_60 ) ;
F_33 ( V_60 ) ;
return V_7 ;
}
return NULL ;
}
static struct V_46 * F_34 ( struct V_18 * V_58 )
{
struct V_18 * V_60 ;
V_60 = F_28 ( V_58 , L_9 ) ;
if ( V_60 != NULL ) {
struct V_46 * V_61 ;
V_61 = F_35 ( V_60 ) ;
F_36 ( V_61 ) ;
F_33 ( V_60 ) ;
return V_61 ;
}
return NULL ;
}
static int F_37 ( struct V_62 * V_63 )
{
static int V_64 ;
struct V_65 * V_21 = V_63 -> V_58 . V_66 ;
struct V_46 * V_58 ;
struct V_15 * V_16 ;
int V_24 ;
if ( ! V_64 ++ )
F_11 ( V_67 L_10
L_11 , V_68 ) ;
if ( V_21 == NULL || V_21 -> V_69 == NULL )
return - V_27 ;
V_58 = F_34 ( V_21 -> V_69 ) ;
if ( V_58 == NULL )
return - V_27 ;
if ( V_58 -> V_70 != NULL ) {
F_38 ( V_58 ) ;
return - V_71 ;
}
V_16 = F_13 ( sizeof( * V_16 ) , V_30 ) ;
if ( V_16 == NULL ) {
F_38 ( V_58 ) ;
return - V_31 ;
}
F_39 ( V_63 , V_16 ) ;
V_16 -> V_21 = V_21 ;
V_16 -> V_26 = V_58 ;
V_16 -> V_35 = - 1 ;
V_16 -> V_37 = - 1 ;
for ( V_24 = 0 ; V_24 < V_21 -> V_52 ; V_24 ++ ) {
struct V_6 * V_7 ;
struct V_14 * V_23 ;
V_7 = F_31 ( V_21 -> V_22 [ V_24 ] . V_6 ) ;
if ( V_7 == NULL ) {
F_11 ( V_25 L_12
L_13 , V_58 -> V_12 , V_24 ) ;
continue;
}
V_23 = F_10 ( V_16 , V_24 , & V_63 -> V_58 , V_7 ) ;
if ( F_40 ( V_23 ) ) {
F_11 ( V_25 L_14
L_15 , V_58 -> V_12 , V_24 ,
F_41 ( V_23 ) ) ;
continue;
}
V_16 -> V_23 [ V_24 ] = V_23 ;
if ( V_23 -> V_2 -> V_53 != NULL )
V_16 -> V_72 = 1 ;
}
F_42 () ;
V_58 -> V_70 = ( void * ) V_16 ;
if ( V_16 -> V_72 ) {
F_43 ( & V_16 -> V_51 , F_21 ) ;
F_44 ( & V_16 -> V_54 ) ;
V_16 -> V_54 . V_73 = ( unsigned long ) V_16 ;
V_16 -> V_54 . V_74 = F_25 ;
V_16 -> V_54 . V_75 = F_24 ( V_55 + V_56 ) ;
F_45 ( & V_16 -> V_54 ) ;
}
return 0 ;
}
static int F_46 ( struct V_62 * V_63 )
{
struct V_15 * V_16 = F_47 ( V_63 ) ;
int V_24 ;
if ( V_16 -> V_72 )
F_48 ( & V_16 -> V_54 ) ;
F_49 ( & V_16 -> V_51 ) ;
for ( V_24 = 0 ; V_24 < V_16 -> V_21 -> V_52 ; V_24 ++ ) {
struct V_14 * V_23 = V_16 -> V_23 [ V_24 ] ;
if ( V_23 != NULL )
F_20 ( V_23 ) ;
}
return 0 ;
}
static void F_50 ( struct V_62 * V_63 )
{
}
static int T_1 F_51 ( void )
{
int V_76 ;
V_76 = F_52 ( & V_77 ) ;
if ( V_76 )
return V_76 ;
#ifdef F_53
F_54 ( & V_78 ) ;
#endif
#ifdef F_55
F_54 ( & V_79 ) ;
#endif
#ifdef F_56
F_54 ( & V_80 ) ;
#endif
return 0 ;
}
static void T_2 F_57 ( void )
{
#ifdef F_56
F_58 ( & V_80 ) ;
#endif
#ifdef F_55
F_58 ( & V_79 ) ;
#endif
#ifdef F_53
F_58 ( & V_78 ) ;
#endif
F_59 ( & V_77 ) ;
}
