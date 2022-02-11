static struct V_1 * F_1 ( struct V_2 * V_3 ,
unsigned int V_4 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
V_8 = F_2 ( sizeof( * V_8 ) , V_9 ,
F_3 ( V_3 ) ) ;
if ( F_4 ( ! V_8 ) )
return NULL ;
V_8 -> V_4 = V_4 ;
V_8 -> V_6 = V_6 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_3 = F_5 ( V_3 ) ;
return V_8 ;
}
static void F_6 ( struct V_1 * V_8 )
{
F_7 ( V_8 -> V_3 ) ;
F_8 ( V_8 ) ;
}
static void F_9 ( struct V_1 * V_8 )
{
F_10 ( & V_10 ) ;
F_11 ( & V_8 -> V_11 , & V_12 ) ;
F_12 ( & V_10 ) ;
F_13 ( L_1 ,
V_8 -> V_4 , V_8 ) ;
}
void F_14 ( struct V_1 * V_8 )
{
F_10 ( & V_10 ) ;
switch ( V_8 -> V_4 ) {
case V_13 :
break;
case V_14 :
F_4 ( V_8 -> V_15 . V_16 . V_17 ) ;
break;
case V_18 :
F_8 ( V_8 -> V_15 . V_19 . V_20 ) ;
V_8 -> V_15 . V_19 . V_21 = 0 ;
break;
case V_22 :
break;
}
F_15 ( & V_8 -> V_11 ) ;
if ( F_16 ( V_23 == V_8 ) )
F_17 ( NULL ) ;
F_12 ( & V_10 ) ;
F_13 ( L_2 ,
V_8 -> V_4 , V_8 ) ;
F_6 ( V_8 ) ;
}
static unsigned int F_18 ( struct V_1 * V_8 ,
T_1 V_24 )
{
T_1 V_25 = V_8 -> V_15 . V_26 . V_25 ;
int V_21 = V_8 -> V_15 . V_26 . V_21 ;
if ( F_4 ( V_24 < V_25 || V_24 >= V_25 + V_21 ) )
return 0 ;
return V_24 - V_25 + V_8 -> V_15 . V_26 . V_27 ;
}
struct V_1 * F_19 ( struct V_2 * V_3 ,
unsigned int V_21 ,
unsigned int V_27 ,
const struct V_5 * V_6 ,
void * V_7 )
{
if ( V_27 > 0 ) {
int V_28 ;
if ( F_20 ( V_29 ) ) {
V_28 = F_21 ( V_27 , V_27 , V_21 ,
F_3 ( V_3 ) ) ;
if ( V_28 < 0 ) {
F_22 ( L_3 ,
V_27 ) ;
V_28 = V_27 ;
}
} else
V_28 = V_27 ;
return F_23 ( V_3 , V_21 , V_28 , 0 ,
V_6 , V_7 ) ;
}
return F_24 ( V_3 , V_21 , V_6 , V_7 ) ;
}
struct V_1 * F_23 ( struct V_2 * V_3 ,
unsigned int V_21 ,
unsigned int V_27 ,
T_1 V_25 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int V_30 ;
V_8 = F_1 ( V_3 , V_13 , V_6 , V_7 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_15 . V_26 . V_27 = V_27 ;
V_8 -> V_15 . V_26 . V_25 = V_25 ;
V_8 -> V_15 . V_26 . V_21 = V_21 ;
F_10 ( & V_10 ) ;
for ( V_30 = 0 ; V_30 < V_21 ; V_30 ++ ) {
int V_31 = V_27 + V_30 ;
struct V_32 * V_32 = F_25 ( V_31 ) ;
if ( F_4 ( ! V_32 || V_32 -> V_8 ) ) {
F_12 ( & V_10 ) ;
F_6 ( V_8 ) ;
return NULL ;
}
}
for ( V_30 = 0 ; V_30 < V_21 ; V_30 ++ ) {
struct V_32 * V_32 = F_25 ( V_27 + V_30 ) ;
V_32 -> V_24 = V_25 + V_30 ;
V_32 -> V_8 = V_8 ;
}
F_12 ( & V_10 ) ;
for ( V_30 = 0 ; V_30 < V_21 ; V_30 ++ ) {
int V_31 = V_27 + V_30 ;
int V_24 = V_25 + V_30 ;
if ( ! V_31 )
continue;
if ( V_6 -> V_33 )
V_6 -> V_33 ( V_8 , V_31 , V_24 ) ;
F_26 ( V_31 , V_34 ) ;
}
F_9 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_24 ( struct V_2 * V_3 ,
unsigned int V_21 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int * V_20 ;
V_20 = F_2 ( sizeof( * V_20 ) * V_21 , V_9 ,
F_3 ( V_3 ) ) ;
if ( F_4 ( ! V_20 ) )
return NULL ;
V_8 = F_1 ( V_3 , V_18 , V_6 , V_7 ) ;
if ( ! V_8 ) {
F_8 ( V_20 ) ;
return NULL ;
}
V_8 -> V_15 . V_19 . V_21 = V_21 ;
V_8 -> V_15 . V_19 . V_20 = V_20 ;
F_9 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_27 ( struct V_2 * V_3 ,
unsigned int V_35 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_22 , V_6 , V_7 ) ;
if ( V_8 ) {
V_8 -> V_15 . V_36 . V_35 = V_35 ? V_35 : ~ 0 ;
F_9 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_28 ( struct V_2 * V_3 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_14 , V_6 , V_7 ) ;
if ( V_8 ) {
F_29 ( & V_8 -> V_15 . V_16 , V_9 ) ;
F_9 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_30 ( struct V_2 * V_37 )
{
struct V_1 * V_38 , * V_39 = NULL ;
int V_40 ;
F_10 ( & V_10 ) ;
F_31 (h, &irq_domain_list, link) {
if ( V_38 -> V_6 -> V_41 )
V_40 = V_38 -> V_6 -> V_41 ( V_38 , V_37 ) ;
else
V_40 = ( V_38 -> V_3 != NULL ) && ( V_38 -> V_3 == V_37 ) ;
if ( V_40 ) {
V_39 = V_38 ;
break;
}
}
F_12 ( & V_10 ) ;
return V_39 ;
}
void F_17 ( struct V_1 * V_8 )
{
F_13 ( L_4 , V_8 ) ;
V_23 = V_8 ;
}
static void F_32 ( struct V_1 * V_8 ,
unsigned int V_28 , int V_42 )
{
while ( V_42 -- ) {
int V_31 = V_28 + V_42 ;
struct V_32 * V_32 = F_25 ( V_31 ) ;
T_1 V_24 ;
if ( F_4 ( ! V_32 || V_32 -> V_8 != V_8 ) )
continue;
V_24 = V_32 -> V_24 ;
F_33 ( V_31 , V_34 ) ;
F_34 ( V_31 , NULL , NULL ) ;
F_35 ( V_31 ) ;
if ( V_8 -> V_6 -> V_43 )
V_8 -> V_6 -> V_43 ( V_8 , V_31 ) ;
F_36 () ;
V_32 -> V_8 = NULL ;
V_32 -> V_24 = 0 ;
switch( V_8 -> V_4 ) {
case V_18 :
if ( V_24 < V_8 -> V_15 . V_19 . V_21 )
V_8 -> V_15 . V_19 . V_20 [ V_24 ] = 0 ;
break;
case V_14 :
F_10 ( & V_44 ) ;
F_37 ( & V_8 -> V_15 . V_16 , V_24 ) ;
F_12 ( & V_44 ) ;
break;
}
}
}
int F_38 ( struct V_1 * V_8 , unsigned int V_28 ,
T_1 V_45 , int V_42 )
{
unsigned int V_46 = V_28 ;
T_1 V_24 = V_45 ;
int V_30 , V_47 ;
F_13 ( L_5 , V_48 ,
F_39 ( V_8 -> V_3 ) , V_28 , ( int ) V_45 , V_42 ) ;
for ( V_30 = 0 ; V_30 < V_42 ; V_30 ++ ) {
struct V_32 * V_32 = F_25 ( V_46 + V_30 ) ;
if ( F_40 ( ! V_32 , L_6
L_7 , V_46 + V_30 , ( int ) V_24 + V_30 ) )
return - V_49 ;
if ( F_40 ( V_32 -> V_8 , L_8
L_7 , V_46 + V_30 , ( int ) V_24 + V_30 ) )
return - V_49 ;
} ;
for ( V_30 = 0 ; V_30 < V_42 ; V_30 ++ , V_46 ++ , V_24 ++ ) {
struct V_32 * V_32 = F_25 ( V_46 ) ;
V_32 -> V_24 = V_24 ;
V_32 -> V_8 = V_8 ;
if ( V_8 -> V_6 -> V_33 ) {
V_47 = V_8 -> V_6 -> V_33 ( V_8 , V_46 , V_24 ) ;
if ( V_47 != 0 ) {
if ( V_47 != - V_50 ) {
F_41 ( L_9 ,
V_46 , V_24 , V_47 ) ;
F_4 ( 1 ) ;
}
V_32 -> V_8 = NULL ;
V_32 -> V_24 = 0 ;
goto V_51;
}
}
switch ( V_8 -> V_4 ) {
case V_18 :
if ( V_24 < V_8 -> V_15 . V_19 . V_21 )
V_8 -> V_15 . V_19 . V_20 [ V_24 ] = V_46 ;
break;
case V_14 :
F_10 ( & V_44 ) ;
F_42 ( & V_8 -> V_15 . V_16 , V_24 , V_32 ) ;
F_12 ( & V_44 ) ;
break;
}
F_26 ( V_46 , V_34 ) ;
}
return 0 ;
V_51:
F_32 ( V_8 , V_28 , V_30 ) ;
return - V_49 ;
}
unsigned int F_43 ( struct V_1 * V_8 )
{
unsigned int V_46 ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( F_4 ( ! V_8 || V_8 -> V_4 != V_22 ) )
return 0 ;
V_46 = F_44 ( 1 , F_3 ( V_8 -> V_3 ) ) ;
if ( ! V_46 ) {
F_13 ( L_10 ) ;
return 0 ;
}
if ( V_46 >= V_8 -> V_15 . V_36 . V_35 ) {
F_41 ( L_11 ,
V_8 -> V_15 . V_36 . V_35 ) ;
F_45 ( V_46 ) ;
return 0 ;
}
F_13 ( L_12 , V_46 ) ;
if ( F_46 ( V_8 , V_46 , V_46 ) ) {
F_45 ( V_46 ) ;
return 0 ;
}
return V_46 ;
}
unsigned int F_47 ( struct V_1 * V_8 ,
T_1 V_24 )
{
unsigned int V_52 ;
int V_46 ;
F_13 ( L_13 , V_8 , V_24 ) ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( V_8 == NULL ) {
F_48 ( L_14
L_15 , V_24 ) ;
F_4 ( 1 ) ;
return 0 ;
}
F_13 ( L_16 , V_8 ) ;
V_46 = F_49 ( V_8 , V_24 ) ;
if ( V_46 ) {
F_13 ( L_17 , V_46 ) ;
return V_46 ;
}
if ( V_8 -> V_4 == V_13 )
return F_18 ( V_8 , V_24 ) ;
V_52 = V_24 % V_53 ;
if ( V_52 == 0 )
V_52 ++ ;
V_46 = F_44 ( V_52 , F_3 ( V_8 -> V_3 ) ) ;
if ( V_46 <= 0 )
V_46 = F_44 ( 1 , F_3 ( V_8 -> V_3 ) ) ;
if ( V_46 <= 0 ) {
F_13 ( L_18 ) ;
return 0 ;
}
if ( F_46 ( V_8 , V_46 , V_24 ) ) {
F_45 ( V_46 ) ;
return 0 ;
}
F_13 ( L_19 ,
V_24 , F_39 ( V_8 -> V_3 ) , V_46 ) ;
return V_46 ;
}
int F_50 ( struct V_1 * V_8 , unsigned int V_28 ,
T_1 V_45 , int V_42 )
{
int V_47 ;
V_47 = F_21 ( V_28 , V_28 , V_42 ,
F_3 ( V_8 -> V_3 ) ) ;
if ( F_16 ( V_47 < 0 ) )
return V_47 ;
V_47 = F_38 ( V_8 , V_28 , V_45 , V_42 ) ;
if ( F_16 ( V_47 < 0 ) ) {
F_51 ( V_28 , V_42 ) ;
return V_47 ;
}
return 0 ;
}
unsigned int F_52 ( struct V_2 * V_54 ,
const T_2 * V_55 , unsigned int V_56 )
{
struct V_1 * V_8 ;
T_1 V_24 ;
unsigned int type = V_57 ;
unsigned int V_46 ;
V_8 = V_54 ? F_30 ( V_54 ) : V_23 ;
if ( ! V_8 ) {
#ifdef F_53
if ( V_56 > 0 )
return V_55 [ 0 ] ;
#endif
F_48 ( L_20 ,
F_39 ( V_54 ) ) ;
return 0 ;
}
if ( V_8 -> V_6 -> V_58 == NULL )
V_24 = V_55 [ 0 ] ;
else {
if ( V_8 -> V_6 -> V_58 ( V_8 , V_54 , V_55 , V_56 ,
& V_24 , & type ) )
return 0 ;
}
V_46 = F_47 ( V_8 , V_24 ) ;
if ( ! V_46 )
return V_46 ;
if ( type != V_57 &&
type != ( F_54 ( F_25 ( V_46 ) ) ) )
F_55 ( V_46 , type ) ;
return V_46 ;
}
void F_56 ( unsigned int V_46 )
{
struct V_32 * V_32 = F_25 ( V_46 ) ;
struct V_1 * V_8 ;
if ( ! V_46 || ! V_32 )
return;
V_8 = V_32 -> V_8 ;
if ( F_4 ( V_8 == NULL ) )
return;
if ( V_8 -> V_4 == V_13 )
return;
F_32 ( V_8 , V_46 , 1 ) ;
F_45 ( V_46 ) ;
}
unsigned int F_49 ( struct V_1 * V_8 ,
T_1 V_24 )
{
struct V_32 * V_59 ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( V_8 == NULL )
return 0 ;
switch ( V_8 -> V_4 ) {
case V_13 :
return F_18 ( V_8 , V_24 ) ;
case V_18 :
return F_57 ( V_8 , V_24 ) ;
case V_14 :
F_58 () ;
V_59 = F_59 ( & V_8 -> V_15 . V_16 , V_24 ) ;
F_60 () ;
if ( V_59 )
return V_59 -> V_31 ;
break;
case V_22 :
V_59 = F_25 ( V_24 ) ;
if ( V_59 && ( V_59 -> V_8 == V_8 ) && ( V_59 -> V_24 == V_24 ) )
return V_24 ;
break;
}
return 0 ;
}
unsigned int F_57 ( struct V_1 * V_8 ,
T_1 V_24 )
{
F_61 ( V_8 -> V_4 != V_18 ) ;
if ( F_4 ( V_24 >= V_8 -> V_15 . V_19 . V_21 ) )
return 0 ;
return V_8 -> V_15 . V_19 . V_20 [ V_24 ] ;
}
static int F_62 ( struct V_60 * V_61 , void * V_62 )
{
unsigned long V_63 ;
struct V_64 * V_65 ;
const char * V_66 ;
static const char V_67 [] = L_21 ;
void * V_59 ;
int V_30 ;
F_63 ( V_61 , L_22 , L_23 , L_24 ,
L_25 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_26 ,
L_27 ) ;
for ( V_30 = 1 ; V_30 < V_53 ; V_30 ++ ) {
V_65 = F_64 ( V_30 ) ;
if ( ! V_65 )
continue;
F_65 ( & V_65 -> V_68 , V_63 ) ;
if ( V_65 -> V_69 && V_65 -> V_69 -> V_70 ) {
struct V_71 * V_72 ;
F_63 ( V_61 , L_28 , V_30 ) ;
F_63 ( V_61 , L_29 , V_65 -> V_32 . V_24 ) ;
V_72 = F_66 ( V_65 ) ;
if ( V_72 && V_72 -> V_73 )
V_66 = V_72 -> V_73 ;
else
V_66 = V_67 ;
F_63 ( V_61 , L_30 , V_66 ) ;
V_59 = F_67 ( V_65 ) ;
F_63 ( V_61 , V_59 ? L_31 : L_32 , V_59 ) ;
if ( V_65 -> V_32 . V_8 )
V_66 = F_39 ( V_65 -> V_32 . V_8 -> V_3 ) ;
else
V_66 = V_67 ;
F_63 ( V_61 , L_33 , V_66 ) ;
}
F_68 ( & V_65 -> V_68 , V_63 ) ;
}
return 0 ;
}
static int F_69 ( struct V_74 * V_74 , struct V_75 * V_75 )
{
return F_70 ( V_75 , F_62 , V_74 -> V_76 ) ;
}
static int T_3 F_71 ( void )
{
if ( F_72 ( L_34 , V_77 , NULL ,
NULL , & V_78 ) == NULL )
return - V_79 ;
return 0 ;
}
int F_73 ( struct V_1 * V_80 , struct V_2 * V_81 ,
const T_2 * V_55 , unsigned int V_56 ,
unsigned long * V_82 , unsigned int * V_83 )
{
if ( F_4 ( V_56 < 1 ) )
return - V_49 ;
* V_82 = V_55 [ 0 ] ;
* V_83 = V_57 ;
return 0 ;
}
int F_74 ( struct V_1 * V_80 , struct V_2 * V_81 ,
const T_2 * V_55 , unsigned int V_56 ,
T_1 * V_82 , unsigned int * V_83 )
{
if ( F_4 ( V_56 < 2 ) )
return - V_49 ;
* V_82 = V_55 [ 0 ] ;
* V_83 = V_55 [ 1 ] & V_84 ;
return 0 ;
}
int F_75 ( struct V_1 * V_80 ,
struct V_2 * V_81 ,
const T_2 * V_55 , unsigned int V_56 ,
unsigned long * V_82 , unsigned int * V_83 )
{
if ( F_4 ( V_56 < 1 ) )
return - V_49 ;
* V_82 = V_55 [ 0 ] ;
* V_83 = ( V_56 > 1 ) ? V_55 [ 1 ] : V_57 ;
return 0 ;
}
void F_76 ( const struct V_85 * V_41 ,
T_4 V_86 , unsigned int V_87 )
{
struct V_2 * V_37 ;
F_13 ( L_35 ,
( unsigned long long ) V_86 , ( int ) V_87 ) ;
V_37 = F_77 ( NULL , V_41 , V_86 ) ;
if ( V_37 )
F_23 ( V_37 , 32 , V_87 , 0 ,
& V_88 , NULL ) ;
}
