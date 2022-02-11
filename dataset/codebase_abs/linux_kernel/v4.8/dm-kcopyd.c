static void F_1 ( struct V_1 * V_2 )
{
unsigned V_3 , V_4 , V_5 ;
int V_6 = 0 , V_7 ;
if ( F_2 ( ! V_2 ) )
return;
V_8:
F_3 ( & V_9 ) ;
V_3 = F_4 ( V_2 -> V_3 ) ;
if ( F_5 ( V_3 >= 100 ) )
goto V_10;
V_4 = V_11 ;
V_5 = V_4 - V_2 -> V_12 ;
V_2 -> V_12 = V_4 ;
if ( V_2 -> V_13 )
V_2 -> V_14 += V_5 ;
V_2 -> V_15 += V_5 ;
if ( F_2 ( V_2 -> V_14 > V_2 -> V_15 ) )
V_2 -> V_14 = V_2 -> V_15 ;
if ( F_2 ( V_2 -> V_15 >= ( 1 << V_16 ) ) ) {
int V_17 = F_6 ( V_2 -> V_15 >> V_16 ) ;
V_2 -> V_15 >>= V_17 ;
V_2 -> V_14 >>= V_17 ;
}
V_7 = V_2 -> V_14 - V_3 * V_2 -> V_15 / 100 ;
if ( F_2 ( V_7 > 0 ) && V_6 < V_18 ) {
V_6 ++ ;
F_7 ( & V_9 ) ;
F_8 ( V_19 ) ;
goto V_8;
}
V_10:
V_2 -> V_13 ++ ;
F_7 ( & V_9 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
unsigned long V_20 ;
if ( F_2 ( ! V_2 ) )
return;
F_10 ( & V_9 , V_20 ) ;
V_2 -> V_13 -- ;
if ( F_5 ( F_4 ( V_2 -> V_3 ) >= 100 ) )
goto V_10;
if ( ! V_2 -> V_13 ) {
unsigned V_4 , V_5 ;
V_4 = V_11 ;
V_5 = V_4 - V_2 -> V_12 ;
V_2 -> V_12 = V_4 ;
V_2 -> V_14 += V_5 ;
V_2 -> V_15 += V_5 ;
if ( F_2 ( V_2 -> V_14 > V_2 -> V_15 ) )
V_2 -> V_14 = V_2 -> V_15 ;
}
V_10:
F_11 ( & V_9 , V_20 ) ;
}
static void F_12 ( struct V_21 * V_22 )
{
F_13 ( V_22 -> V_23 , & V_22 -> V_24 ) ;
}
static struct V_25 * F_14 ( T_1 V_26 )
{
struct V_25 * V_27 ;
V_27 = F_15 ( sizeof( * V_27 ) , V_26 ) ;
if ( ! V_27 )
return NULL ;
V_27 -> V_28 = F_16 ( V_26 ) ;
if ( ! V_27 -> V_28 ) {
F_17 ( V_27 ) ;
return NULL ;
}
return V_27 ;
}
static void F_18 ( struct V_25 * V_27 )
{
F_19 ( V_27 -> V_28 ) ;
F_17 ( V_27 ) ;
}
static void F_20 ( struct V_21 * V_22 , struct V_25 * V_27 )
{
struct V_25 * V_29 ;
do {
V_29 = V_27 -> V_29 ;
if ( V_22 -> V_30 >= V_22 -> V_31 )
F_18 ( V_27 ) ;
else {
V_27 -> V_29 = V_22 -> V_32 ;
V_22 -> V_32 = V_27 ;
V_22 -> V_30 ++ ;
}
V_27 = V_29 ;
} while ( V_27 );
}
static int F_21 ( struct V_21 * V_22 ,
unsigned int V_33 , struct V_25 * * V_32 )
{
struct V_25 * V_27 ;
* V_32 = NULL ;
do {
V_27 = F_14 ( V_34 | V_35 | V_36 ) ;
if ( F_2 ( ! V_27 ) ) {
V_27 = V_22 -> V_32 ;
if ( F_2 ( ! V_27 ) )
goto V_37;
V_22 -> V_32 = V_27 -> V_29 ;
V_22 -> V_30 -- ;
}
V_27 -> V_29 = * V_32 ;
* V_32 = V_27 ;
} while ( -- V_33 );
return 0 ;
V_37:
if ( * V_32 )
F_20 ( V_22 , * V_32 ) ;
return - V_38 ;
}
static void F_22 ( struct V_25 * V_27 )
{
struct V_25 * V_29 ;
while ( V_27 ) {
V_29 = V_27 -> V_29 ;
F_18 ( V_27 ) ;
V_27 = V_29 ;
}
}
static int F_23 ( struct V_21 * V_22 , unsigned V_39 )
{
unsigned V_40 ;
struct V_25 * V_27 = NULL , * V_29 ;
for ( V_40 = 0 ; V_40 < V_39 ; V_40 ++ ) {
V_29 = F_14 ( V_41 ) ;
if ( ! V_29 ) {
if ( V_27 )
F_22 ( V_27 ) ;
return - V_38 ;
}
V_29 -> V_29 = V_27 ;
V_27 = V_29 ;
}
V_22 -> V_31 += V_39 ;
F_20 ( V_22 , V_27 ) ;
return 0 ;
}
static void F_24 ( struct V_21 * V_22 )
{
F_25 ( V_22 -> V_30 != V_22 -> V_31 ) ;
F_22 ( V_22 -> V_32 ) ;
V_22 -> V_32 = NULL ;
V_22 -> V_30 = V_22 -> V_31 = 0 ;
}
int T_2 F_26 ( void )
{
V_42 = F_27 ( L_1 ,
sizeof( struct V_43 ) * ( V_44 + 1 ) ,
F_28 ( struct V_43 ) , 0 , NULL ) ;
if ( ! V_42 )
return - V_38 ;
V_45 . V_29 = & V_45 ;
V_45 . V_28 = F_29 ( 0 ) ;
return 0 ;
}
void F_30 ( void )
{
F_31 ( V_42 ) ;
V_42 = NULL ;
}
static struct V_43 * F_32 ( struct V_46 * V_47 ,
struct V_21 * V_22 )
{
struct V_43 * V_48 = NULL ;
unsigned long V_20 ;
F_10 ( & V_22 -> V_49 , V_20 ) ;
if ( ! F_33 ( V_47 ) ) {
V_48 = F_34 ( V_47 -> V_29 , struct V_43 , V_50 ) ;
F_35 ( & V_48 -> V_50 ) ;
}
F_11 ( & V_22 -> V_49 , V_20 ) ;
return V_48 ;
}
static void F_36 ( struct V_46 * V_47 , struct V_43 * V_48 )
{
unsigned long V_20 ;
struct V_21 * V_22 = V_48 -> V_22 ;
F_10 ( & V_22 -> V_49 , V_20 ) ;
F_37 ( & V_48 -> V_50 , V_47 ) ;
F_11 ( & V_22 -> V_49 , V_20 ) ;
}
static void F_38 ( struct V_46 * V_47 , struct V_43 * V_48 )
{
unsigned long V_20 ;
struct V_21 * V_22 = V_48 -> V_22 ;
F_10 ( & V_22 -> V_49 , V_20 ) ;
F_39 ( & V_48 -> V_50 , V_47 ) ;
F_11 ( & V_22 -> V_49 , V_20 ) ;
}
static int F_40 ( struct V_43 * V_48 )
{
void * V_51 = V_48 -> V_51 ;
int V_52 = V_48 -> V_52 ;
unsigned long V_53 = V_48 -> V_53 ;
T_3 V_54 = V_48 -> V_54 ;
struct V_21 * V_22 = V_48 -> V_22 ;
if ( V_48 -> V_32 && V_48 -> V_32 != & V_45 )
F_20 ( V_22 , V_48 -> V_32 ) ;
if ( V_48 -> V_55 == V_48 )
F_41 ( V_48 , V_22 -> V_56 ) ;
V_54 ( V_52 , V_53 , V_51 ) ;
if ( F_42 ( & V_22 -> V_57 ) )
F_43 ( & V_22 -> V_58 ) ;
return 0 ;
}
static void F_44 ( unsigned long error , void * V_51 )
{
struct V_43 * V_48 = (struct V_43 * ) V_51 ;
struct V_21 * V_22 = V_48 -> V_22 ;
F_9 ( V_22 -> V_3 ) ;
if ( error ) {
if ( F_45 ( V_48 -> V_59 ) )
V_48 -> V_53 |= error ;
else
V_48 -> V_52 = 1 ;
if ( ! F_46 ( V_60 , & V_48 -> V_20 ) ) {
F_36 ( & V_22 -> V_61 , V_48 ) ;
F_12 ( V_22 ) ;
return;
}
}
if ( F_45 ( V_48 -> V_59 ) )
F_36 ( & V_22 -> V_61 , V_48 ) ;
else {
V_48 -> V_59 = V_62 ;
F_36 ( & V_22 -> V_63 , V_48 ) ;
}
F_12 ( V_22 ) ;
}
static int F_47 ( struct V_43 * V_48 )
{
int V_64 ;
struct V_65 V_66 = {
. V_67 = V_48 -> V_59 ,
. V_68 = 0 ,
. V_69 . type = V_70 ,
. V_69 . V_71 . V_27 = V_48 -> V_32 ,
. V_69 . V_72 = 0 ,
. V_73 . V_54 = F_44 ,
. V_73 . V_51 = V_48 ,
. V_74 = V_48 -> V_22 -> V_75 ,
} ;
F_1 ( V_48 -> V_22 -> V_3 ) ;
if ( V_48 -> V_59 == V_76 )
V_64 = F_48 ( & V_66 , 1 , & V_48 -> V_77 , NULL ) ;
else
V_64 = F_48 ( & V_66 , V_48 -> V_78 , V_48 -> V_79 , NULL ) ;
return V_64 ;
}
static int F_49 ( struct V_43 * V_48 )
{
int V_64 ;
unsigned V_39 = F_50 ( V_48 -> V_79 [ 0 ] . V_80 , V_81 >> 9 ) ;
V_64 = F_21 ( V_48 -> V_22 , V_39 , & V_48 -> V_32 ) ;
if ( ! V_64 ) {
F_36 ( & V_48 -> V_22 -> V_63 , V_48 ) ;
return 0 ;
}
if ( V_64 == - V_38 )
return 1 ;
return V_64 ;
}
static int F_51 ( struct V_46 * V_47 , struct V_21 * V_22 ,
int (* V_54) ( struct V_43 * ) )
{
struct V_43 * V_48 ;
int V_64 , V_80 = 0 ;
while ( ( V_48 = F_32 ( V_47 , V_22 ) ) ) {
V_64 = V_54 ( V_48 ) ;
if ( V_64 < 0 ) {
if ( F_45 ( V_48 -> V_59 ) )
V_48 -> V_53 = ( unsigned long ) - 1L ;
else
V_48 -> V_52 = 1 ;
F_36 ( & V_22 -> V_61 , V_48 ) ;
break;
}
if ( V_64 > 0 ) {
F_38 ( V_47 , V_48 ) ;
break;
}
V_80 ++ ;
}
return V_80 ;
}
static void F_52 ( struct V_82 * V_83 )
{
struct V_21 * V_22 = F_53 ( V_83 ,
struct V_21 , V_24 ) ;
struct V_84 V_85 ;
F_54 ( & V_85 ) ;
F_51 ( & V_22 -> V_61 , V_22 , F_40 ) ;
F_51 ( & V_22 -> V_86 , V_22 , F_49 ) ;
F_51 ( & V_22 -> V_63 , V_22 , F_47 ) ;
F_55 ( & V_85 ) ;
}
static void F_56 ( struct V_43 * V_48 )
{
struct V_21 * V_22 = V_48 -> V_22 ;
F_57 ( & V_22 -> V_57 ) ;
if ( F_2 ( ! V_48 -> V_77 . V_80 ) )
F_36 ( & V_22 -> V_61 , V_48 ) ;
else if ( V_48 -> V_32 == & V_45 )
F_36 ( & V_22 -> V_63 , V_48 ) ;
else
F_36 ( & V_22 -> V_86 , V_48 ) ;
F_12 ( V_22 ) ;
}
static void F_58 ( int V_52 , unsigned long V_53 ,
void * V_51 )
{
T_4 V_87 = 0 ;
T_4 V_80 = 0 ;
struct V_43 * V_88 = (struct V_43 * ) V_51 ;
struct V_43 * V_48 = V_88 -> V_55 ;
struct V_21 * V_22 = V_48 -> V_22 ;
F_59 ( & V_48 -> V_89 ) ;
if ( V_52 )
V_48 -> V_52 = 1 ;
if ( V_53 )
V_48 -> V_53 |= V_53 ;
if ( ( ! V_48 -> V_52 && ! V_48 -> V_53 ) ||
F_46 ( V_60 , & V_48 -> V_20 ) ) {
V_87 = V_48 -> V_87 ;
V_80 = V_48 -> V_77 . V_80 - V_87 ;
if ( V_80 ) {
if ( V_80 > V_90 )
V_80 = V_90 ;
V_48 -> V_87 += V_80 ;
}
}
F_60 ( & V_48 -> V_89 ) ;
if ( V_80 ) {
int V_40 ;
* V_88 = * V_48 ;
V_88 -> V_77 . V_91 += V_87 ;
V_88 -> V_77 . V_80 = V_80 ;
for ( V_40 = 0 ; V_40 < V_48 -> V_78 ; V_40 ++ ) {
V_88 -> V_79 [ V_40 ] . V_91 += V_87 ;
V_88 -> V_79 [ V_40 ] . V_80 = V_80 ;
}
V_88 -> V_54 = F_58 ;
V_88 -> V_51 = V_88 ;
F_56 ( V_88 ) ;
} else if ( F_42 ( & V_48 -> V_92 ) ) {
F_36 ( & V_22 -> V_61 , V_48 ) ;
F_12 ( V_22 ) ;
}
}
static void F_61 ( struct V_43 * V_55 )
{
int V_40 ;
F_57 ( & V_55 -> V_22 -> V_57 ) ;
F_62 ( & V_55 -> V_92 , V_44 ) ;
for ( V_40 = 0 ; V_40 < V_44 ; V_40 ++ ) {
V_55 [ V_40 + 1 ] . V_55 = V_55 ;
F_58 ( 0 , 0u , & V_55 [ V_40 + 1 ] ) ;
}
}
int F_63 ( struct V_21 * V_22 , struct V_93 * V_94 ,
unsigned int V_78 , struct V_93 * V_79 ,
unsigned int V_20 , T_3 V_54 , void * V_51 )
{
struct V_43 * V_48 ;
int V_40 ;
V_48 = F_64 ( V_22 -> V_56 , V_95 ) ;
V_48 -> V_22 = V_22 ;
V_48 -> V_20 = V_20 ;
V_48 -> V_52 = 0 ;
V_48 -> V_53 = 0 ;
V_48 -> V_78 = V_78 ;
memcpy ( & V_48 -> V_79 , V_79 , sizeof( * V_79 ) * V_78 ) ;
if ( V_94 ) {
V_48 -> V_77 = * V_94 ;
V_48 -> V_32 = NULL ;
V_48 -> V_59 = V_76 ;
} else {
memset ( & V_48 -> V_77 , 0 , sizeof V_48 -> V_77 ) ;
V_48 -> V_77 . V_80 = V_48 -> V_79 [ 0 ] . V_80 ;
V_48 -> V_32 = & V_45 ;
V_48 -> V_59 = V_96 ;
for ( V_40 = 0 ; V_40 < V_48 -> V_78 ; V_40 ++ )
if ( ! F_65 ( V_48 -> V_79 [ V_40 ] . V_97 ) ) {
V_48 -> V_59 = V_62 ;
break;
}
}
V_48 -> V_54 = V_54 ;
V_48 -> V_51 = V_51 ;
V_48 -> V_55 = V_48 ;
if ( V_48 -> V_77 . V_80 <= V_90 )
F_56 ( V_48 ) ;
else {
F_66 ( & V_48 -> V_89 ) ;
V_48 -> V_87 = 0 ;
F_61 ( V_48 ) ;
}
return 0 ;
}
int F_67 ( struct V_21 * V_22 ,
unsigned V_78 , struct V_93 * V_79 ,
unsigned V_20 , T_3 V_54 , void * V_51 )
{
return F_63 ( V_22 , NULL , V_78 , V_79 , V_20 , V_54 , V_51 ) ;
}
void * F_68 ( struct V_21 * V_22 ,
T_3 V_54 , void * V_51 )
{
struct V_43 * V_48 ;
V_48 = F_64 ( V_22 -> V_56 , V_95 ) ;
memset ( V_48 , 0 , sizeof( struct V_43 ) ) ;
V_48 -> V_22 = V_22 ;
V_48 -> V_54 = V_54 ;
V_48 -> V_51 = V_51 ;
V_48 -> V_55 = V_48 ;
F_57 ( & V_22 -> V_57 ) ;
return V_48 ;
}
void F_69 ( void * V_98 , int V_52 , unsigned long V_53 )
{
struct V_43 * V_48 = V_98 ;
struct V_21 * V_22 = V_48 -> V_22 ;
V_48 -> V_52 = V_52 ;
V_48 -> V_53 = V_53 ;
F_36 ( & V_22 -> V_61 , V_48 ) ;
F_12 ( V_22 ) ;
}
struct V_21 * F_70 ( struct V_1 * V_3 )
{
int V_64 = - V_38 ;
struct V_21 * V_22 ;
V_22 = F_15 ( sizeof( * V_22 ) , V_41 ) ;
if ( ! V_22 )
return F_71 ( - V_38 ) ;
F_72 ( & V_22 -> V_49 ) ;
F_73 ( & V_22 -> V_61 ) ;
F_73 ( & V_22 -> V_63 ) ;
F_73 ( & V_22 -> V_86 ) ;
V_22 -> V_3 = V_3 ;
V_22 -> V_56 = F_74 ( V_99 , V_42 ) ;
if ( ! V_22 -> V_56 )
goto V_100;
F_75 ( & V_22 -> V_24 , F_52 ) ;
V_22 -> V_23 = F_76 ( L_2 , V_101 , 0 ) ;
if ( ! V_22 -> V_23 )
goto V_102;
V_22 -> V_32 = NULL ;
V_22 -> V_31 = V_22 -> V_30 = 0 ;
V_64 = F_23 ( V_22 , V_103 ) ;
if ( V_64 )
goto V_104;
V_22 -> V_75 = F_77 () ;
if ( F_78 ( V_22 -> V_75 ) ) {
V_64 = F_79 ( V_22 -> V_75 ) ;
goto V_105;
}
F_80 ( & V_22 -> V_58 ) ;
F_62 ( & V_22 -> V_57 , 0 ) ;
return V_22 ;
V_105:
F_24 ( V_22 ) ;
V_104:
F_81 ( V_22 -> V_23 ) ;
V_102:
F_82 ( V_22 -> V_56 ) ;
V_100:
F_17 ( V_22 ) ;
return F_71 ( V_64 ) ;
}
void F_83 ( struct V_21 * V_22 )
{
F_84 ( V_22 -> V_58 , ! F_85 ( & V_22 -> V_57 ) ) ;
F_25 ( ! F_33 ( & V_22 -> V_61 ) ) ;
F_25 ( ! F_33 ( & V_22 -> V_63 ) ) ;
F_25 ( ! F_33 ( & V_22 -> V_86 ) ) ;
F_81 ( V_22 -> V_23 ) ;
F_86 ( V_22 -> V_75 ) ;
F_24 ( V_22 ) ;
F_82 ( V_22 -> V_56 ) ;
F_17 ( V_22 ) ;
}
