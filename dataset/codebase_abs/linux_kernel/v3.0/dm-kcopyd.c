static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , & V_2 -> V_4 ) ;
}
static struct V_5 * F_3 ( T_1 V_6 )
{
struct V_5 * V_7 ;
V_7 = F_4 ( sizeof( * V_7 ) , V_6 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_8 = F_5 ( V_6 ) ;
if ( ! V_7 -> V_8 ) {
F_6 ( V_7 ) ;
return NULL ;
}
return V_7 ;
}
static void F_7 ( struct V_5 * V_7 )
{
F_8 ( V_7 -> V_8 ) ;
F_6 ( V_7 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_5 * V_7 )
{
struct V_5 * V_9 ;
do {
V_9 = V_7 -> V_9 ;
if ( V_2 -> V_10 >= V_2 -> V_11 )
F_7 ( V_7 ) ;
else {
V_7 -> V_9 = V_2 -> V_12 ;
V_2 -> V_12 = V_7 ;
V_2 -> V_10 ++ ;
}
V_7 = V_9 ;
} while ( V_7 );
}
static int F_10 ( struct V_1 * V_2 ,
unsigned int V_13 , struct V_5 * * V_12 )
{
struct V_5 * V_7 ;
* V_12 = NULL ;
do {
V_7 = F_3 ( V_14 | V_15 ) ;
if ( F_11 ( ! V_7 ) ) {
V_7 = V_2 -> V_12 ;
if ( F_11 ( ! V_7 ) )
goto V_16;
V_2 -> V_12 = V_7 -> V_9 ;
V_2 -> V_10 -- ;
}
V_7 -> V_9 = * V_12 ;
* V_12 = V_7 ;
} while ( -- V_13 );
return 0 ;
V_16:
if ( * V_12 )
F_9 ( V_2 , * V_12 ) ;
return - V_17 ;
}
static void F_12 ( struct V_5 * V_7 )
{
struct V_5 * V_9 ;
while ( V_7 ) {
V_9 = V_7 -> V_9 ;
F_7 ( V_7 ) ;
V_7 = V_9 ;
}
}
static int F_13 ( struct V_1 * V_2 , unsigned V_18 )
{
unsigned V_19 ;
struct V_5 * V_7 = NULL , * V_9 ;
for ( V_19 = 0 ; V_19 < V_18 ; V_19 ++ ) {
V_9 = F_3 ( V_20 ) ;
if ( ! V_9 ) {
if ( V_7 )
F_12 ( V_7 ) ;
return - V_17 ;
}
V_9 -> V_9 = V_7 ;
V_7 = V_9 ;
}
V_2 -> V_11 += V_18 ;
F_9 ( V_2 , V_7 ) ;
return 0 ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( V_2 -> V_10 != V_2 -> V_11 ) ;
F_12 ( V_2 -> V_12 ) ;
V_2 -> V_12 = NULL ;
V_2 -> V_10 = V_2 -> V_11 = 0 ;
}
int T_2 F_16 ( void )
{
V_21 = F_17 ( L_1 ,
sizeof( struct V_22 ) * ( V_23 + 1 ) ,
F_18 ( struct V_22 ) , 0 , NULL ) ;
if ( ! V_21 )
return - V_17 ;
return 0 ;
}
void F_19 ( void )
{
F_20 ( V_21 ) ;
V_21 = NULL ;
}
static struct V_22 * F_21 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
struct V_22 * V_26 = NULL ;
unsigned long V_27 ;
F_22 ( & V_2 -> V_28 , V_27 ) ;
if ( ! F_23 ( V_25 ) ) {
V_26 = F_24 ( V_25 -> V_9 , struct V_22 , V_29 ) ;
F_25 ( & V_26 -> V_29 ) ;
}
F_26 ( & V_2 -> V_28 , V_27 ) ;
return V_26 ;
}
static void F_27 ( struct V_24 * V_25 , struct V_22 * V_26 )
{
unsigned long V_27 ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_22 ( & V_2 -> V_28 , V_27 ) ;
F_28 ( & V_26 -> V_29 , V_25 ) ;
F_26 ( & V_2 -> V_28 , V_27 ) ;
}
static void F_29 ( struct V_24 * V_25 , struct V_22 * V_26 )
{
unsigned long V_27 ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_22 ( & V_2 -> V_28 , V_27 ) ;
F_30 ( & V_26 -> V_29 , V_25 ) ;
F_26 ( & V_2 -> V_28 , V_27 ) ;
}
static int F_31 ( struct V_22 * V_26 )
{
void * V_30 = V_26 -> V_30 ;
int V_31 = V_26 -> V_31 ;
unsigned long V_32 = V_26 -> V_32 ;
T_3 V_33 = V_26 -> V_33 ;
struct V_1 * V_2 = V_26 -> V_2 ;
if ( V_26 -> V_12 )
F_9 ( V_2 , V_26 -> V_12 ) ;
if ( V_26 -> V_34 == V_26 )
F_32 ( V_26 , V_2 -> V_35 ) ;
V_33 ( V_31 , V_32 , V_30 ) ;
if ( F_33 ( & V_2 -> V_36 ) )
F_34 ( & V_2 -> V_37 ) ;
return 0 ;
}
static void F_35 ( unsigned long error , void * V_30 )
{
struct V_22 * V_26 = (struct V_22 * ) V_30 ;
struct V_1 * V_2 = V_26 -> V_2 ;
if ( error ) {
if ( V_26 -> V_38 == V_39 )
V_26 -> V_32 |= error ;
else
V_26 -> V_31 = 1 ;
if ( ! F_36 ( V_40 , & V_26 -> V_27 ) ) {
F_27 ( & V_2 -> V_41 , V_26 ) ;
F_1 ( V_2 ) ;
return;
}
}
if ( V_26 -> V_38 == V_39 )
F_27 ( & V_2 -> V_41 , V_26 ) ;
else {
V_26 -> V_38 = V_39 ;
F_27 ( & V_2 -> V_42 , V_26 ) ;
}
F_1 ( V_2 ) ;
}
static int F_37 ( struct V_22 * V_26 )
{
int V_43 ;
struct V_44 V_45 = {
. V_46 = V_26 -> V_38 ,
. V_47 . type = V_48 ,
. V_47 . V_49 . V_7 = V_26 -> V_12 ,
. V_47 . V_50 = V_26 -> V_50 ,
. V_51 . V_33 = F_35 ,
. V_51 . V_30 = V_26 ,
. V_52 = V_26 -> V_2 -> V_53 ,
} ;
if ( V_26 -> V_38 == V_54 )
V_43 = F_38 ( & V_45 , 1 , & V_26 -> V_55 , NULL ) ;
else
V_43 = F_38 ( & V_45 , V_26 -> V_56 , V_26 -> V_57 , NULL ) ;
return V_43 ;
}
static int F_39 ( struct V_22 * V_26 )
{
int V_43 ;
V_26 -> V_18 = F_40 ( V_26 -> V_57 [ 0 ] . V_58 + V_26 -> V_50 ,
V_59 >> 9 ) ;
V_43 = F_10 ( V_26 -> V_2 , V_26 -> V_18 , & V_26 -> V_12 ) ;
if ( ! V_43 ) {
F_27 ( & V_26 -> V_2 -> V_42 , V_26 ) ;
return 0 ;
}
if ( V_43 == - V_17 )
return 1 ;
return V_43 ;
}
static int F_41 ( struct V_24 * V_25 , struct V_1 * V_2 ,
int (* V_33) ( struct V_22 * ) )
{
struct V_22 * V_26 ;
int V_43 , V_58 = 0 ;
while ( ( V_26 = F_21 ( V_25 , V_2 ) ) ) {
V_43 = V_33 ( V_26 ) ;
if ( V_43 < 0 ) {
if ( V_26 -> V_38 == V_39 )
V_26 -> V_32 = ( unsigned long ) - 1L ;
else
V_26 -> V_31 = 1 ;
F_27 ( & V_2 -> V_41 , V_26 ) ;
break;
}
if ( V_43 > 0 ) {
F_29 ( V_25 , V_26 ) ;
break;
}
V_58 ++ ;
}
return V_58 ;
}
static void F_42 ( struct V_60 * V_61 )
{
struct V_1 * V_2 = F_43 ( V_61 ,
struct V_1 , V_4 ) ;
struct V_62 V_63 ;
F_44 ( & V_63 ) ;
F_41 ( & V_2 -> V_41 , V_2 , F_31 ) ;
F_41 ( & V_2 -> V_64 , V_2 , F_39 ) ;
F_41 ( & V_2 -> V_42 , V_2 , F_37 ) ;
F_45 ( & V_63 ) ;
}
static void F_46 ( struct V_22 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_2 ;
F_47 ( & V_2 -> V_36 ) ;
if ( F_11 ( ! V_26 -> V_55 . V_58 ) )
F_27 ( & V_2 -> V_41 , V_26 ) ;
else
F_27 ( & V_2 -> V_64 , V_26 ) ;
F_1 ( V_2 ) ;
}
static void F_48 ( int V_31 , unsigned long V_32 ,
void * V_30 )
{
T_4 V_65 = 0 ;
T_4 V_58 = 0 ;
struct V_22 * V_66 = (struct V_22 * ) V_30 ;
struct V_22 * V_26 = V_66 -> V_34 ;
struct V_1 * V_2 = V_26 -> V_2 ;
F_49 ( & V_26 -> V_67 ) ;
if ( V_31 )
V_26 -> V_31 = 1 ;
if ( V_32 )
V_26 -> V_32 |= V_32 ;
if ( ( ! V_26 -> V_31 && ! V_26 -> V_32 ) ||
F_36 ( V_40 , & V_26 -> V_27 ) ) {
V_65 = V_26 -> V_65 ;
V_58 = V_26 -> V_55 . V_58 - V_65 ;
if ( V_58 ) {
if ( V_58 > V_68 )
V_58 = V_68 ;
V_26 -> V_65 += V_58 ;
}
}
F_50 ( & V_26 -> V_67 ) ;
if ( V_58 ) {
int V_19 ;
* V_66 = * V_26 ;
V_66 -> V_55 . V_69 += V_65 ;
V_66 -> V_55 . V_58 = V_58 ;
for ( V_19 = 0 ; V_19 < V_26 -> V_56 ; V_19 ++ ) {
V_66 -> V_57 [ V_19 ] . V_69 += V_65 ;
V_66 -> V_57 [ V_19 ] . V_58 = V_58 ;
}
V_66 -> V_33 = F_48 ;
V_66 -> V_30 = V_66 ;
F_46 ( V_66 ) ;
} else if ( F_33 ( & V_26 -> V_70 ) ) {
F_27 ( & V_2 -> V_41 , V_26 ) ;
F_1 ( V_2 ) ;
}
}
static void F_51 ( struct V_22 * V_34 )
{
int V_19 ;
F_47 ( & V_34 -> V_2 -> V_36 ) ;
F_52 ( & V_34 -> V_70 , V_23 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
V_34 [ V_19 + 1 ] . V_34 = V_34 ;
F_48 ( 0 , 0u , & V_34 [ V_19 + 1 ] ) ;
}
}
int F_53 ( struct V_1 * V_2 , struct V_71 * V_72 ,
unsigned int V_56 , struct V_71 * V_57 ,
unsigned int V_27 , T_3 V_33 , void * V_30 )
{
struct V_22 * V_26 ;
V_26 = F_54 ( V_2 -> V_35 , V_73 ) ;
V_26 -> V_2 = V_2 ;
V_26 -> V_27 = V_27 ;
V_26 -> V_31 = 0 ;
V_26 -> V_32 = 0 ;
V_26 -> V_38 = V_54 ;
V_26 -> V_55 = * V_72 ;
V_26 -> V_56 = V_56 ;
memcpy ( & V_26 -> V_57 , V_57 , sizeof( * V_57 ) * V_56 ) ;
V_26 -> V_50 = 0 ;
V_26 -> V_18 = 0 ;
V_26 -> V_12 = NULL ;
V_26 -> V_33 = V_33 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_34 = V_26 ;
if ( V_26 -> V_55 . V_58 <= V_68 )
F_46 ( V_26 ) ;
else {
F_55 ( & V_26 -> V_67 ) ;
V_26 -> V_65 = 0 ;
F_51 ( V_26 ) ;
}
return 0 ;
}
struct V_1 * F_56 ( void )
{
int V_43 = - V_17 ;
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return F_57 ( - V_17 ) ;
F_58 ( & V_2 -> V_28 ) ;
F_59 ( & V_2 -> V_41 ) ;
F_59 ( & V_2 -> V_42 ) ;
F_59 ( & V_2 -> V_64 ) ;
V_2 -> V_35 = F_60 ( V_74 , V_21 ) ;
if ( ! V_2 -> V_35 )
goto V_75;
F_61 ( & V_2 -> V_4 , F_42 ) ;
V_2 -> V_3 = F_62 ( L_2 ,
V_76 | V_77 , 0 ) ;
if ( ! V_2 -> V_3 )
goto V_78;
V_2 -> V_12 = NULL ;
V_2 -> V_11 = V_2 -> V_10 = 0 ;
V_43 = F_13 ( V_2 , V_79 ) ;
if ( V_43 )
goto V_80;
V_2 -> V_53 = F_63 () ;
if ( F_64 ( V_2 -> V_53 ) ) {
V_43 = F_65 ( V_2 -> V_53 ) ;
goto V_81;
}
F_66 ( & V_2 -> V_37 ) ;
F_52 ( & V_2 -> V_36 , 0 ) ;
return V_2 ;
V_81:
F_14 ( V_2 ) ;
V_80:
F_67 ( V_2 -> V_3 ) ;
V_78:
F_68 ( V_2 -> V_35 ) ;
V_75:
F_6 ( V_2 ) ;
return F_57 ( V_43 ) ;
}
void F_69 ( struct V_1 * V_2 )
{
F_70 ( V_2 -> V_37 , ! F_71 ( & V_2 -> V_36 ) ) ;
F_15 ( ! F_23 ( & V_2 -> V_41 ) ) ;
F_15 ( ! F_23 ( & V_2 -> V_42 ) ) ;
F_15 ( ! F_23 ( & V_2 -> V_64 ) ) ;
F_67 ( V_2 -> V_3 ) ;
F_72 ( V_2 -> V_53 ) ;
F_14 ( V_2 ) ;
F_68 ( V_2 -> V_35 ) ;
F_6 ( V_2 ) ;
}
