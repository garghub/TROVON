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
if ( V_27 > 0 )
return F_20 ( V_3 , V_21 , V_27 , 0 ,
V_6 , V_7 ) ;
else
return F_21 ( V_3 , V_21 , V_6 , V_7 ) ;
}
struct V_1 * F_20 ( struct V_2 * V_3 ,
unsigned int V_21 ,
unsigned int V_27 ,
T_1 V_25 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 ;
unsigned int V_28 ;
V_8 = F_1 ( V_3 , V_13 , V_6 , V_7 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_15 . V_26 . V_27 = V_27 ;
V_8 -> V_15 . V_26 . V_25 = V_25 ;
V_8 -> V_15 . V_26 . V_21 = V_21 ;
F_10 ( & V_10 ) ;
for ( V_28 = 0 ; V_28 < V_21 ; V_28 ++ ) {
int V_29 = V_27 + V_28 ;
struct V_30 * V_30 = F_22 ( V_29 ) ;
if ( F_4 ( ! V_30 || V_30 -> V_8 ) ) {
F_12 ( & V_10 ) ;
F_6 ( V_8 ) ;
return NULL ;
}
}
for ( V_28 = 0 ; V_28 < V_21 ; V_28 ++ ) {
struct V_30 * V_30 = F_22 ( V_27 + V_28 ) ;
V_30 -> V_24 = V_25 + V_28 ;
V_30 -> V_8 = V_8 ;
}
F_12 ( & V_10 ) ;
for ( V_28 = 0 ; V_28 < V_21 ; V_28 ++ ) {
int V_29 = V_27 + V_28 ;
int V_24 = V_25 + V_28 ;
if ( ! V_29 )
continue;
if ( V_6 -> V_31 )
V_6 -> V_31 ( V_8 , V_29 , V_24 ) ;
F_23 ( V_29 , V_32 ) ;
}
F_9 ( V_8 ) ;
return V_8 ;
}
struct V_1 * F_21 ( struct V_2 * V_3 ,
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
struct V_1 * F_24 ( struct V_2 * V_3 ,
unsigned int V_33 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_22 , V_6 , V_7 ) ;
if ( V_8 ) {
V_8 -> V_15 . V_34 . V_33 = V_33 ? V_33 : ~ 0 ;
F_9 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_25 ( struct V_2 * V_3 ,
const struct V_5 * V_6 ,
void * V_7 )
{
struct V_1 * V_8 = F_1 ( V_3 ,
V_14 , V_6 , V_7 ) ;
if ( V_8 ) {
F_26 ( & V_8 -> V_15 . V_16 , V_9 ) ;
F_9 ( V_8 ) ;
}
return V_8 ;
}
struct V_1 * F_27 ( struct V_2 * V_35 )
{
struct V_1 * V_36 , * V_37 = NULL ;
int V_38 ;
F_10 ( & V_10 ) ;
F_28 (h, &irq_domain_list, link) {
if ( V_36 -> V_6 -> V_39 )
V_38 = V_36 -> V_6 -> V_39 ( V_36 , V_35 ) ;
else
V_38 = ( V_36 -> V_3 != NULL ) && ( V_36 -> V_3 == V_35 ) ;
if ( V_38 ) {
V_37 = V_36 ;
break;
}
}
F_12 ( & V_10 ) ;
return V_37 ;
}
void F_17 ( struct V_1 * V_8 )
{
F_13 ( L_3 , V_8 ) ;
V_23 = V_8 ;
}
static void F_29 ( struct V_1 * V_8 ,
unsigned int V_40 , int V_41 )
{
while ( V_41 -- ) {
int V_29 = V_40 + V_41 ;
struct V_30 * V_30 = F_22 ( V_29 ) ;
T_1 V_24 = V_30 -> V_24 ;
if ( F_4 ( ! V_30 || V_30 -> V_8 != V_8 ) )
continue;
F_30 ( V_29 , V_32 ) ;
F_31 ( V_29 , NULL , NULL ) ;
F_32 ( V_29 ) ;
if ( V_8 -> V_6 -> V_42 )
V_8 -> V_6 -> V_42 ( V_8 , V_29 ) ;
F_33 () ;
V_30 -> V_8 = NULL ;
V_30 -> V_24 = 0 ;
switch( V_8 -> V_4 ) {
case V_18 :
if ( V_24 < V_8 -> V_15 . V_19 . V_21 )
V_8 -> V_15 . V_19 . V_20 [ V_24 ] = 0 ;
break;
case V_14 :
F_10 ( & V_43 ) ;
F_34 ( & V_8 -> V_15 . V_16 , V_24 ) ;
F_12 ( & V_43 ) ;
break;
}
}
}
int F_35 ( struct V_1 * V_8 , unsigned int V_40 ,
T_1 V_44 , int V_41 )
{
unsigned int V_45 = V_40 ;
T_1 V_24 = V_44 ;
int V_28 , V_46 ;
F_13 ( L_4 , V_47 ,
F_36 ( V_8 -> V_3 ) , V_40 , ( int ) V_44 , V_41 ) ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ ) {
struct V_30 * V_30 = F_22 ( V_45 + V_28 ) ;
if ( F_37 ( ! V_30 , L_5
L_6 , V_45 + V_28 , ( int ) V_24 + V_28 ) )
return - V_48 ;
if ( F_37 ( V_30 -> V_8 , L_7
L_6 , V_45 + V_28 , ( int ) V_24 + V_28 ) )
return - V_48 ;
} ;
for ( V_28 = 0 ; V_28 < V_41 ; V_28 ++ , V_45 ++ , V_24 ++ ) {
struct V_30 * V_30 = F_22 ( V_45 ) ;
V_30 -> V_24 = V_24 ;
V_30 -> V_8 = V_8 ;
if ( V_8 -> V_6 -> V_31 ) {
V_46 = V_8 -> V_6 -> V_31 ( V_8 , V_45 , V_24 ) ;
if ( V_46 != 0 ) {
F_38 ( L_8 ,
V_45 , V_24 , V_46 ) ;
F_4 ( 1 ) ;
V_30 -> V_8 = NULL ;
V_30 -> V_24 = 0 ;
goto V_49;
}
}
switch ( V_8 -> V_4 ) {
case V_18 :
if ( V_24 < V_8 -> V_15 . V_19 . V_21 )
V_8 -> V_15 . V_19 . V_20 [ V_24 ] = V_45 ;
break;
case V_14 :
F_10 ( & V_43 ) ;
F_39 ( & V_8 -> V_15 . V_16 , V_24 , V_30 ) ;
F_12 ( & V_43 ) ;
break;
}
F_23 ( V_45 , V_32 ) ;
}
return 0 ;
V_49:
F_29 ( V_8 , V_40 , V_28 ) ;
return - V_48 ;
}
unsigned int F_40 ( struct V_1 * V_8 )
{
unsigned int V_45 ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( F_4 ( ! V_8 || V_8 -> V_4 != V_22 ) )
return 0 ;
V_45 = F_41 ( 1 , F_3 ( V_8 -> V_3 ) ) ;
if ( ! V_45 ) {
F_13 ( L_9 ) ;
return 0 ;
}
if ( V_45 >= V_8 -> V_15 . V_34 . V_33 ) {
F_38 ( L_10 ,
V_8 -> V_15 . V_34 . V_33 ) ;
F_42 ( V_45 ) ;
return 0 ;
}
F_13 ( L_11 , V_45 ) ;
if ( F_43 ( V_8 , V_45 , V_45 ) ) {
F_42 ( V_45 ) ;
return 0 ;
}
return V_45 ;
}
unsigned int F_44 ( struct V_1 * V_8 ,
T_1 V_24 )
{
unsigned int V_50 ;
int V_45 ;
F_13 ( L_12 , V_8 , V_24 ) ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( V_8 == NULL ) {
F_45 ( L_13
L_14 , V_24 ) ;
F_4 ( 1 ) ;
return 0 ;
}
F_13 ( L_15 , V_8 ) ;
V_45 = F_46 ( V_8 , V_24 ) ;
if ( V_45 ) {
F_13 ( L_16 , V_45 ) ;
return V_45 ;
}
if ( V_8 -> V_4 == V_13 )
return F_18 ( V_8 , V_24 ) ;
V_50 = V_24 % V_51 ;
if ( V_50 == 0 )
V_50 ++ ;
V_45 = F_41 ( V_50 , F_3 ( V_8 -> V_3 ) ) ;
if ( V_45 <= 0 )
V_45 = F_41 ( 1 , F_3 ( V_8 -> V_3 ) ) ;
if ( V_45 <= 0 ) {
F_13 ( L_17 ) ;
return 0 ;
}
if ( F_43 ( V_8 , V_45 , V_24 ) ) {
F_42 ( V_45 ) ;
return 0 ;
}
F_13 ( L_18 ,
V_24 , F_36 ( V_8 -> V_3 ) , V_45 ) ;
return V_45 ;
}
int F_47 ( struct V_1 * V_8 , unsigned int V_40 ,
T_1 V_44 , int V_41 )
{
int V_46 ;
V_46 = F_48 ( V_40 , V_40 , V_41 ,
F_3 ( V_8 -> V_3 ) ) ;
if ( F_16 ( V_46 < 0 ) )
return V_46 ;
V_46 = F_35 ( V_8 , V_40 , V_44 , V_41 ) ;
if ( F_16 ( V_46 < 0 ) ) {
F_49 ( V_40 , V_41 ) ;
return V_46 ;
}
return 0 ;
}
unsigned int F_50 ( struct V_2 * V_52 ,
const T_2 * V_53 , unsigned int V_54 )
{
struct V_1 * V_8 ;
T_1 V_24 ;
unsigned int type = V_55 ;
unsigned int V_45 ;
V_8 = V_52 ? F_27 ( V_52 ) : V_23 ;
if ( ! V_8 ) {
#ifdef F_51
if ( V_54 > 0 )
return V_53 [ 0 ] ;
#endif
F_45 ( L_19 ,
F_36 ( V_52 ) ) ;
return 0 ;
}
if ( V_8 -> V_6 -> V_56 == NULL )
V_24 = V_53 [ 0 ] ;
else {
if ( V_8 -> V_6 -> V_56 ( V_8 , V_52 , V_53 , V_54 ,
& V_24 , & type ) )
return 0 ;
}
V_45 = F_44 ( V_8 , V_24 ) ;
if ( ! V_45 )
return V_45 ;
if ( type != V_55 &&
type != ( F_52 ( F_22 ( V_45 ) ) ) )
F_53 ( V_45 , type ) ;
return V_45 ;
}
void F_54 ( unsigned int V_45 )
{
struct V_30 * V_30 = F_22 ( V_45 ) ;
struct V_1 * V_8 ;
if ( ! V_45 || ! V_30 )
return;
V_8 = V_30 -> V_8 ;
if ( F_4 ( V_8 == NULL ) )
return;
if ( V_8 -> V_4 == V_13 )
return;
F_29 ( V_8 , V_45 , 1 ) ;
F_42 ( V_45 ) ;
}
unsigned int F_46 ( struct V_1 * V_8 ,
T_1 V_24 )
{
struct V_30 * V_57 ;
if ( V_8 == NULL )
V_8 = V_23 ;
if ( V_8 == NULL )
return 0 ;
switch ( V_8 -> V_4 ) {
case V_13 :
return F_18 ( V_8 , V_24 ) ;
case V_18 :
return F_55 ( V_8 , V_24 ) ;
case V_14 :
F_56 () ;
V_57 = F_57 ( & V_8 -> V_15 . V_16 , V_24 ) ;
F_58 () ;
if ( V_57 )
return V_57 -> V_29 ;
break;
case V_22 :
V_57 = F_22 ( V_24 ) ;
if ( V_57 && ( V_57 -> V_8 == V_8 ) && ( V_57 -> V_24 == V_24 ) )
return V_24 ;
break;
}
return 0 ;
}
unsigned int F_55 ( struct V_1 * V_8 ,
T_1 V_24 )
{
F_59 ( V_8 -> V_4 != V_18 ) ;
if ( F_4 ( V_24 >= V_8 -> V_15 . V_19 . V_21 ) )
return 0 ;
return V_8 -> V_15 . V_19 . V_20 [ V_24 ] ;
}
static int F_60 ( struct V_58 * V_59 , void * V_60 )
{
unsigned long V_61 ;
struct V_62 * V_63 ;
const char * V_64 ;
static const char V_65 [] = L_20 ;
void * V_57 ;
int V_28 ;
F_61 ( V_59 , L_21 , L_22 , L_23 ,
L_24 , ( int ) ( 2 * sizeof( void * ) + 2 ) , L_25 ,
L_26 ) ;
for ( V_28 = 1 ; V_28 < V_51 ; V_28 ++ ) {
V_63 = F_62 ( V_28 ) ;
if ( ! V_63 )
continue;
F_63 ( & V_63 -> V_66 , V_61 ) ;
if ( V_63 -> V_67 && V_63 -> V_67 -> V_68 ) {
struct V_69 * V_70 ;
F_61 ( V_59 , L_27 , V_28 ) ;
F_61 ( V_59 , L_28 , V_63 -> V_30 . V_24 ) ;
V_70 = F_64 ( V_63 ) ;
if ( V_70 && V_70 -> V_71 )
V_64 = V_70 -> V_71 ;
else
V_64 = V_65 ;
F_61 ( V_59 , L_29 , V_64 ) ;
V_57 = F_65 ( V_63 ) ;
F_61 ( V_59 , V_57 ? L_30 : L_31 , V_57 ) ;
if ( V_63 -> V_30 . V_8 )
V_64 = F_36 ( V_63 -> V_30 . V_8 -> V_3 ) ;
else
V_64 = V_65 ;
F_61 ( V_59 , L_32 , V_64 ) ;
}
F_66 ( & V_63 -> V_66 , V_61 ) ;
}
return 0 ;
}
static int F_67 ( struct V_72 * V_72 , struct V_73 * V_73 )
{
return F_68 ( V_73 , F_60 , V_72 -> V_74 ) ;
}
static int T_3 F_69 ( void )
{
if ( F_70 ( L_33 , V_75 , NULL ,
NULL , & V_76 ) == NULL )
return - V_77 ;
return 0 ;
}
int F_71 ( struct V_1 * V_78 , struct V_2 * V_79 ,
const T_2 * V_53 , unsigned int V_54 ,
unsigned long * V_80 , unsigned int * V_81 )
{
if ( F_4 ( V_54 < 1 ) )
return - V_48 ;
* V_80 = V_53 [ 0 ] ;
* V_81 = V_55 ;
return 0 ;
}
int F_72 ( struct V_1 * V_78 , struct V_2 * V_79 ,
const T_2 * V_53 , unsigned int V_54 ,
T_1 * V_80 , unsigned int * V_81 )
{
if ( F_4 ( V_54 < 2 ) )
return - V_48 ;
* V_80 = V_53 [ 0 ] ;
* V_81 = V_53 [ 1 ] & V_82 ;
return 0 ;
}
int F_73 ( struct V_1 * V_78 ,
struct V_2 * V_79 ,
const T_2 * V_53 , unsigned int V_54 ,
unsigned long * V_80 , unsigned int * V_81 )
{
if ( F_4 ( V_54 < 1 ) )
return - V_48 ;
* V_80 = V_53 [ 0 ] ;
* V_81 = ( V_54 > 1 ) ? V_53 [ 1 ] : V_55 ;
return 0 ;
}
void F_74 ( const struct V_83 * V_39 ,
T_4 V_84 , unsigned int V_85 )
{
struct V_2 * V_35 ;
F_13 ( L_34 ,
( unsigned long long ) V_84 , ( int ) V_85 ) ;
V_35 = F_75 ( NULL , V_39 , V_84 ) ;
if ( V_35 )
F_20 ( V_35 , 32 , V_85 , 0 ,
& V_86 , NULL ) ;
}
