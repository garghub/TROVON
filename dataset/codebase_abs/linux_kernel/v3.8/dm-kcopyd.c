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
V_24 . V_9 = & V_24 ;
V_24 . V_8 = F_19 ( 0 ) ;
return 0 ;
}
void F_20 ( void )
{
F_21 ( V_21 ) ;
V_21 = NULL ;
}
static struct V_22 * F_22 ( struct V_25 * V_26 ,
struct V_1 * V_2 )
{
struct V_22 * V_27 = NULL ;
unsigned long V_28 ;
F_23 ( & V_2 -> V_29 , V_28 ) ;
if ( ! F_24 ( V_26 ) ) {
V_27 = F_25 ( V_26 -> V_9 , struct V_22 , V_30 ) ;
F_26 ( & V_27 -> V_30 ) ;
}
F_27 ( & V_2 -> V_29 , V_28 ) ;
return V_27 ;
}
static void F_28 ( struct V_25 * V_26 , struct V_22 * V_27 )
{
unsigned long V_28 ;
struct V_1 * V_2 = V_27 -> V_2 ;
F_23 ( & V_2 -> V_29 , V_28 ) ;
F_29 ( & V_27 -> V_30 , V_26 ) ;
F_27 ( & V_2 -> V_29 , V_28 ) ;
}
static void F_30 ( struct V_25 * V_26 , struct V_22 * V_27 )
{
unsigned long V_28 ;
struct V_1 * V_2 = V_27 -> V_2 ;
F_23 ( & V_2 -> V_29 , V_28 ) ;
F_31 ( & V_27 -> V_30 , V_26 ) ;
F_27 ( & V_2 -> V_29 , V_28 ) ;
}
static int F_32 ( struct V_22 * V_27 )
{
void * V_31 = V_27 -> V_31 ;
int V_32 = V_27 -> V_32 ;
unsigned long V_33 = V_27 -> V_33 ;
T_3 V_34 = V_27 -> V_34 ;
struct V_1 * V_2 = V_27 -> V_2 ;
if ( V_27 -> V_12 && V_27 -> V_12 != & V_24 )
F_9 ( V_2 , V_27 -> V_12 ) ;
if ( V_27 -> V_35 == V_27 )
F_33 ( V_27 , V_2 -> V_36 ) ;
V_34 ( V_32 , V_33 , V_31 ) ;
if ( F_34 ( & V_2 -> V_37 ) )
F_35 ( & V_2 -> V_38 ) ;
return 0 ;
}
static void F_36 ( unsigned long error , void * V_31 )
{
struct V_22 * V_27 = (struct V_22 * ) V_31 ;
struct V_1 * V_2 = V_27 -> V_2 ;
if ( error ) {
if ( V_27 -> V_39 & V_40 )
V_27 -> V_33 |= error ;
else
V_27 -> V_32 = 1 ;
if ( ! F_37 ( V_41 , & V_27 -> V_28 ) ) {
F_28 ( & V_2 -> V_42 , V_27 ) ;
F_1 ( V_2 ) ;
return;
}
}
if ( V_27 -> V_39 & V_40 )
F_28 ( & V_2 -> V_42 , V_27 ) ;
else {
V_27 -> V_39 = V_40 ;
F_28 ( & V_2 -> V_43 , V_27 ) ;
}
F_1 ( V_2 ) ;
}
static int F_38 ( struct V_22 * V_27 )
{
int V_44 ;
struct V_45 V_46 = {
. V_47 = V_27 -> V_39 ,
. V_48 . type = V_49 ,
. V_48 . V_50 . V_7 = V_27 -> V_12 ,
. V_48 . V_51 = 0 ,
. V_52 . V_34 = F_36 ,
. V_52 . V_31 = V_27 ,
. V_53 = V_27 -> V_2 -> V_54 ,
} ;
if ( V_27 -> V_39 == V_55 )
V_44 = F_39 ( & V_46 , 1 , & V_27 -> V_56 , NULL ) ;
else
V_44 = F_39 ( & V_46 , V_27 -> V_57 , V_27 -> V_58 , NULL ) ;
return V_44 ;
}
static int F_40 ( struct V_22 * V_27 )
{
int V_44 ;
unsigned V_18 = F_41 ( V_27 -> V_58 [ 0 ] . V_59 , V_60 >> 9 ) ;
V_44 = F_10 ( V_27 -> V_2 , V_18 , & V_27 -> V_12 ) ;
if ( ! V_44 ) {
F_28 ( & V_27 -> V_2 -> V_43 , V_27 ) ;
return 0 ;
}
if ( V_44 == - V_17 )
return 1 ;
return V_44 ;
}
static int F_42 ( struct V_25 * V_26 , struct V_1 * V_2 ,
int (* V_34) ( struct V_22 * ) )
{
struct V_22 * V_27 ;
int V_44 , V_59 = 0 ;
while ( ( V_27 = F_22 ( V_26 , V_2 ) ) ) {
V_44 = V_34 ( V_27 ) ;
if ( V_44 < 0 ) {
if ( V_27 -> V_39 & V_40 )
V_27 -> V_33 = ( unsigned long ) - 1L ;
else
V_27 -> V_32 = 1 ;
F_28 ( & V_2 -> V_42 , V_27 ) ;
break;
}
if ( V_44 > 0 ) {
F_30 ( V_26 , V_27 ) ;
break;
}
V_59 ++ ;
}
return V_59 ;
}
static void F_43 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = F_44 ( V_62 ,
struct V_1 , V_4 ) ;
struct V_63 V_64 ;
F_45 ( & V_64 ) ;
F_42 ( & V_2 -> V_42 , V_2 , F_32 ) ;
F_42 ( & V_2 -> V_65 , V_2 , F_40 ) ;
F_42 ( & V_2 -> V_43 , V_2 , F_38 ) ;
F_46 ( & V_64 ) ;
}
static void F_47 ( struct V_22 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_2 ;
F_48 ( & V_2 -> V_37 ) ;
if ( F_11 ( ! V_27 -> V_56 . V_59 ) )
F_28 ( & V_2 -> V_42 , V_27 ) ;
else if ( V_27 -> V_12 == & V_24 )
F_28 ( & V_2 -> V_43 , V_27 ) ;
else
F_28 ( & V_2 -> V_65 , V_27 ) ;
F_1 ( V_2 ) ;
}
static void F_49 ( int V_32 , unsigned long V_33 ,
void * V_31 )
{
T_4 V_66 = 0 ;
T_4 V_59 = 0 ;
struct V_22 * V_67 = (struct V_22 * ) V_31 ;
struct V_22 * V_27 = V_67 -> V_35 ;
struct V_1 * V_2 = V_27 -> V_2 ;
F_50 ( & V_27 -> V_68 ) ;
if ( V_32 )
V_27 -> V_32 = 1 ;
if ( V_33 )
V_27 -> V_33 |= V_33 ;
if ( ( ! V_27 -> V_32 && ! V_27 -> V_33 ) ||
F_37 ( V_41 , & V_27 -> V_28 ) ) {
V_66 = V_27 -> V_66 ;
V_59 = V_27 -> V_56 . V_59 - V_66 ;
if ( V_59 ) {
if ( V_59 > V_69 )
V_59 = V_69 ;
V_27 -> V_66 += V_59 ;
}
}
F_51 ( & V_27 -> V_68 ) ;
if ( V_59 ) {
int V_19 ;
* V_67 = * V_27 ;
V_67 -> V_56 . V_70 += V_66 ;
V_67 -> V_56 . V_59 = V_59 ;
for ( V_19 = 0 ; V_19 < V_27 -> V_57 ; V_19 ++ ) {
V_67 -> V_58 [ V_19 ] . V_70 += V_66 ;
V_67 -> V_58 [ V_19 ] . V_59 = V_59 ;
}
V_67 -> V_34 = F_49 ;
V_67 -> V_31 = V_67 ;
F_47 ( V_67 ) ;
} else if ( F_34 ( & V_27 -> V_71 ) ) {
F_28 ( & V_2 -> V_42 , V_27 ) ;
F_1 ( V_2 ) ;
}
}
static void F_52 ( struct V_22 * V_35 )
{
int V_19 ;
F_48 ( & V_35 -> V_2 -> V_37 ) ;
F_53 ( & V_35 -> V_71 , V_23 ) ;
for ( V_19 = 0 ; V_19 < V_23 ; V_19 ++ ) {
V_35 [ V_19 + 1 ] . V_35 = V_35 ;
F_49 ( 0 , 0u , & V_35 [ V_19 + 1 ] ) ;
}
}
int F_54 ( struct V_1 * V_2 , struct V_72 * V_73 ,
unsigned int V_57 , struct V_72 * V_58 ,
unsigned int V_28 , T_3 V_34 , void * V_31 )
{
struct V_22 * V_27 ;
int V_19 ;
V_27 = F_55 ( V_2 -> V_36 , V_74 ) ;
V_27 -> V_2 = V_2 ;
V_27 -> V_28 = V_28 ;
V_27 -> V_32 = 0 ;
V_27 -> V_33 = 0 ;
V_27 -> V_57 = V_57 ;
memcpy ( & V_27 -> V_58 , V_58 , sizeof( * V_58 ) * V_57 ) ;
if ( V_73 ) {
V_27 -> V_56 = * V_73 ;
V_27 -> V_12 = NULL ;
V_27 -> V_39 = V_55 ;
} else {
memset ( & V_27 -> V_56 , 0 , sizeof V_27 -> V_56 ) ;
V_27 -> V_56 . V_59 = V_27 -> V_58 [ 0 ] . V_59 ;
V_27 -> V_12 = & V_24 ;
V_27 -> V_39 = V_40 | V_75 ;
for ( V_19 = 0 ; V_19 < V_27 -> V_57 ; V_19 ++ )
if ( ! F_56 ( V_27 -> V_58 [ V_19 ] . V_76 ) ) {
V_27 -> V_39 = V_40 ;
break;
}
}
V_27 -> V_34 = V_34 ;
V_27 -> V_31 = V_31 ;
V_27 -> V_35 = V_27 ;
if ( V_27 -> V_56 . V_59 <= V_69 )
F_47 ( V_27 ) ;
else {
F_57 ( & V_27 -> V_68 ) ;
V_27 -> V_66 = 0 ;
F_52 ( V_27 ) ;
}
return 0 ;
}
int F_58 ( struct V_1 * V_2 ,
unsigned V_57 , struct V_72 * V_58 ,
unsigned V_28 , T_3 V_34 , void * V_31 )
{
return F_54 ( V_2 , NULL , V_57 , V_58 , V_28 , V_34 , V_31 ) ;
}
void * F_59 ( struct V_1 * V_2 ,
T_3 V_34 , void * V_31 )
{
struct V_22 * V_27 ;
V_27 = F_55 ( V_2 -> V_36 , V_74 ) ;
memset ( V_27 , 0 , sizeof( struct V_22 ) ) ;
V_27 -> V_2 = V_2 ;
V_27 -> V_34 = V_34 ;
V_27 -> V_31 = V_31 ;
V_27 -> V_35 = V_27 ;
F_48 ( & V_2 -> V_37 ) ;
return V_27 ;
}
void F_60 ( void * V_77 , int V_32 , unsigned long V_33 )
{
struct V_22 * V_27 = V_77 ;
struct V_1 * V_2 = V_27 -> V_2 ;
V_27 -> V_32 = V_32 ;
V_27 -> V_33 = V_33 ;
F_28 ( & V_2 -> V_42 , V_27 ) ;
F_1 ( V_2 ) ;
}
struct V_1 * F_61 ( void )
{
int V_44 = - V_17 ;
struct V_1 * V_2 ;
V_2 = F_4 ( sizeof( * V_2 ) , V_20 ) ;
if ( ! V_2 )
return F_62 ( - V_17 ) ;
F_63 ( & V_2 -> V_29 ) ;
F_64 ( & V_2 -> V_42 ) ;
F_64 ( & V_2 -> V_43 ) ;
F_64 ( & V_2 -> V_65 ) ;
V_2 -> V_36 = F_65 ( V_78 , V_21 ) ;
if ( ! V_2 -> V_36 )
goto V_79;
F_66 ( & V_2 -> V_4 , F_43 ) ;
V_2 -> V_3 = F_67 ( L_2 ,
V_80 | V_81 , 0 ) ;
if ( ! V_2 -> V_3 )
goto V_82;
V_2 -> V_12 = NULL ;
V_2 -> V_11 = V_2 -> V_10 = 0 ;
V_44 = F_13 ( V_2 , V_83 ) ;
if ( V_44 )
goto V_84;
V_2 -> V_54 = F_68 () ;
if ( F_69 ( V_2 -> V_54 ) ) {
V_44 = F_70 ( V_2 -> V_54 ) ;
goto V_85;
}
F_71 ( & V_2 -> V_38 ) ;
F_53 ( & V_2 -> V_37 , 0 ) ;
return V_2 ;
V_85:
F_14 ( V_2 ) ;
V_84:
F_72 ( V_2 -> V_3 ) ;
V_82:
F_73 ( V_2 -> V_36 ) ;
V_79:
F_6 ( V_2 ) ;
return F_62 ( V_44 ) ;
}
void F_74 ( struct V_1 * V_2 )
{
F_75 ( V_2 -> V_38 , ! F_76 ( & V_2 -> V_37 ) ) ;
F_15 ( ! F_24 ( & V_2 -> V_42 ) ) ;
F_15 ( ! F_24 ( & V_2 -> V_43 ) ) ;
F_15 ( ! F_24 ( & V_2 -> V_65 ) ) ;
F_72 ( V_2 -> V_3 ) ;
F_77 ( V_2 -> V_54 ) ;
F_14 ( V_2 ) ;
F_73 ( V_2 -> V_36 ) ;
F_6 ( V_2 ) ;
}
