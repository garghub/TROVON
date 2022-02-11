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
V_27 = F_14 ( V_34 | V_35 ) ;
if ( F_2 ( ! V_27 ) ) {
V_27 = V_22 -> V_32 ;
if ( F_2 ( ! V_27 ) )
goto V_36;
V_22 -> V_32 = V_27 -> V_29 ;
V_22 -> V_30 -- ;
}
V_27 -> V_29 = * V_32 ;
* V_32 = V_27 ;
} while ( -- V_33 );
return 0 ;
V_36:
if ( * V_32 )
F_20 ( V_22 , * V_32 ) ;
return - V_37 ;
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
static int F_23 ( struct V_21 * V_22 , unsigned V_38 )
{
unsigned V_39 ;
struct V_25 * V_27 = NULL , * V_29 ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ ) {
V_29 = F_14 ( V_40 ) ;
if ( ! V_29 ) {
if ( V_27 )
F_22 ( V_27 ) ;
return - V_37 ;
}
V_29 -> V_29 = V_27 ;
V_27 = V_29 ;
}
V_22 -> V_31 += V_38 ;
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
V_41 = F_27 ( L_1 ,
sizeof( struct V_42 ) * ( V_43 + 1 ) ,
F_28 ( struct V_42 ) , 0 , NULL ) ;
if ( ! V_41 )
return - V_37 ;
V_44 . V_29 = & V_44 ;
V_44 . V_28 = F_29 ( 0 ) ;
return 0 ;
}
void F_30 ( void )
{
F_31 ( V_41 ) ;
V_41 = NULL ;
}
static struct V_42 * F_32 ( struct V_45 * V_46 ,
struct V_21 * V_22 )
{
struct V_42 * V_47 = NULL ;
unsigned long V_20 ;
F_10 ( & V_22 -> V_48 , V_20 ) ;
if ( ! F_33 ( V_46 ) ) {
V_47 = F_34 ( V_46 -> V_29 , struct V_42 , V_49 ) ;
F_35 ( & V_47 -> V_49 ) ;
}
F_11 ( & V_22 -> V_48 , V_20 ) ;
return V_47 ;
}
static void F_36 ( struct V_45 * V_46 , struct V_42 * V_47 )
{
unsigned long V_20 ;
struct V_21 * V_22 = V_47 -> V_22 ;
F_10 ( & V_22 -> V_48 , V_20 ) ;
F_37 ( & V_47 -> V_49 , V_46 ) ;
F_11 ( & V_22 -> V_48 , V_20 ) ;
}
static void F_38 ( struct V_45 * V_46 , struct V_42 * V_47 )
{
unsigned long V_20 ;
struct V_21 * V_22 = V_47 -> V_22 ;
F_10 ( & V_22 -> V_48 , V_20 ) ;
F_39 ( & V_47 -> V_49 , V_46 ) ;
F_11 ( & V_22 -> V_48 , V_20 ) ;
}
static int F_40 ( struct V_42 * V_47 )
{
void * V_50 = V_47 -> V_50 ;
int V_51 = V_47 -> V_51 ;
unsigned long V_52 = V_47 -> V_52 ;
T_3 V_53 = V_47 -> V_53 ;
struct V_21 * V_22 = V_47 -> V_22 ;
if ( V_47 -> V_32 && V_47 -> V_32 != & V_44 )
F_20 ( V_22 , V_47 -> V_32 ) ;
if ( V_47 -> V_54 == V_47 )
F_41 ( V_47 , V_22 -> V_55 ) ;
V_53 ( V_51 , V_52 , V_50 ) ;
if ( F_42 ( & V_22 -> V_56 ) )
F_43 ( & V_22 -> V_57 ) ;
return 0 ;
}
static void F_44 ( unsigned long error , void * V_50 )
{
struct V_42 * V_47 = (struct V_42 * ) V_50 ;
struct V_21 * V_22 = V_47 -> V_22 ;
F_9 ( V_22 -> V_3 ) ;
if ( error ) {
if ( V_47 -> V_58 & V_59 )
V_47 -> V_52 |= error ;
else
V_47 -> V_51 = 1 ;
if ( ! F_45 ( V_60 , & V_47 -> V_20 ) ) {
F_36 ( & V_22 -> V_61 , V_47 ) ;
F_12 ( V_22 ) ;
return;
}
}
if ( V_47 -> V_58 & V_59 )
F_36 ( & V_22 -> V_61 , V_47 ) ;
else {
V_47 -> V_58 = V_59 ;
F_36 ( & V_22 -> V_62 , V_47 ) ;
}
F_12 ( V_22 ) ;
}
static int F_46 ( struct V_42 * V_47 )
{
int V_63 ;
struct V_64 V_65 = {
. V_66 = V_47 -> V_58 ,
. V_67 . type = V_68 ,
. V_67 . V_69 . V_27 = V_47 -> V_32 ,
. V_67 . V_70 = 0 ,
. V_71 . V_53 = F_44 ,
. V_71 . V_50 = V_47 ,
. V_72 = V_47 -> V_22 -> V_73 ,
} ;
F_1 ( V_47 -> V_22 -> V_3 ) ;
if ( V_47 -> V_58 == V_74 )
V_63 = F_47 ( & V_65 , 1 , & V_47 -> V_75 , NULL ) ;
else
V_63 = F_47 ( & V_65 , V_47 -> V_76 , V_47 -> V_77 , NULL ) ;
return V_63 ;
}
static int F_48 ( struct V_42 * V_47 )
{
int V_63 ;
unsigned V_38 = F_49 ( V_47 -> V_77 [ 0 ] . V_78 , V_79 >> 9 ) ;
V_63 = F_21 ( V_47 -> V_22 , V_38 , & V_47 -> V_32 ) ;
if ( ! V_63 ) {
F_36 ( & V_47 -> V_22 -> V_62 , V_47 ) ;
return 0 ;
}
if ( V_63 == - V_37 )
return 1 ;
return V_63 ;
}
static int F_50 ( struct V_45 * V_46 , struct V_21 * V_22 ,
int (* V_53) ( struct V_42 * ) )
{
struct V_42 * V_47 ;
int V_63 , V_78 = 0 ;
while ( ( V_47 = F_32 ( V_46 , V_22 ) ) ) {
V_63 = V_53 ( V_47 ) ;
if ( V_63 < 0 ) {
if ( V_47 -> V_58 & V_59 )
V_47 -> V_52 = ( unsigned long ) - 1L ;
else
V_47 -> V_51 = 1 ;
F_36 ( & V_22 -> V_61 , V_47 ) ;
break;
}
if ( V_63 > 0 ) {
F_38 ( V_46 , V_47 ) ;
break;
}
V_78 ++ ;
}
return V_78 ;
}
static void F_51 ( struct V_80 * V_81 )
{
struct V_21 * V_22 = F_52 ( V_81 ,
struct V_21 , V_24 ) ;
struct V_82 V_83 ;
F_53 ( & V_83 ) ;
F_50 ( & V_22 -> V_61 , V_22 , F_40 ) ;
F_50 ( & V_22 -> V_84 , V_22 , F_48 ) ;
F_50 ( & V_22 -> V_62 , V_22 , F_46 ) ;
F_54 ( & V_83 ) ;
}
static void F_55 ( struct V_42 * V_47 )
{
struct V_21 * V_22 = V_47 -> V_22 ;
F_56 ( & V_22 -> V_56 ) ;
if ( F_2 ( ! V_47 -> V_75 . V_78 ) )
F_36 ( & V_22 -> V_61 , V_47 ) ;
else if ( V_47 -> V_32 == & V_44 )
F_36 ( & V_22 -> V_62 , V_47 ) ;
else
F_36 ( & V_22 -> V_84 , V_47 ) ;
F_12 ( V_22 ) ;
}
static void F_57 ( int V_51 , unsigned long V_52 ,
void * V_50 )
{
T_4 V_85 = 0 ;
T_4 V_78 = 0 ;
struct V_42 * V_86 = (struct V_42 * ) V_50 ;
struct V_42 * V_47 = V_86 -> V_54 ;
struct V_21 * V_22 = V_47 -> V_22 ;
F_58 ( & V_47 -> V_87 ) ;
if ( V_51 )
V_47 -> V_51 = 1 ;
if ( V_52 )
V_47 -> V_52 |= V_52 ;
if ( ( ! V_47 -> V_51 && ! V_47 -> V_52 ) ||
F_45 ( V_60 , & V_47 -> V_20 ) ) {
V_85 = V_47 -> V_85 ;
V_78 = V_47 -> V_75 . V_78 - V_85 ;
if ( V_78 ) {
if ( V_78 > V_88 )
V_78 = V_88 ;
V_47 -> V_85 += V_78 ;
}
}
F_59 ( & V_47 -> V_87 ) ;
if ( V_78 ) {
int V_39 ;
* V_86 = * V_47 ;
V_86 -> V_75 . V_89 += V_85 ;
V_86 -> V_75 . V_78 = V_78 ;
for ( V_39 = 0 ; V_39 < V_47 -> V_76 ; V_39 ++ ) {
V_86 -> V_77 [ V_39 ] . V_89 += V_85 ;
V_86 -> V_77 [ V_39 ] . V_78 = V_78 ;
}
V_86 -> V_53 = F_57 ;
V_86 -> V_50 = V_86 ;
F_55 ( V_86 ) ;
} else if ( F_42 ( & V_47 -> V_90 ) ) {
F_36 ( & V_22 -> V_61 , V_47 ) ;
F_12 ( V_22 ) ;
}
}
static void F_60 ( struct V_42 * V_54 )
{
int V_39 ;
F_56 ( & V_54 -> V_22 -> V_56 ) ;
F_61 ( & V_54 -> V_90 , V_43 ) ;
for ( V_39 = 0 ; V_39 < V_43 ; V_39 ++ ) {
V_54 [ V_39 + 1 ] . V_54 = V_54 ;
F_57 ( 0 , 0u , & V_54 [ V_39 + 1 ] ) ;
}
}
int F_62 ( struct V_21 * V_22 , struct V_91 * V_92 ,
unsigned int V_76 , struct V_91 * V_77 ,
unsigned int V_20 , T_3 V_53 , void * V_50 )
{
struct V_42 * V_47 ;
int V_39 ;
V_47 = F_63 ( V_22 -> V_55 , V_93 ) ;
V_47 -> V_22 = V_22 ;
V_47 -> V_20 = V_20 ;
V_47 -> V_51 = 0 ;
V_47 -> V_52 = 0 ;
V_47 -> V_76 = V_76 ;
memcpy ( & V_47 -> V_77 , V_77 , sizeof( * V_77 ) * V_76 ) ;
if ( V_92 ) {
V_47 -> V_75 = * V_92 ;
V_47 -> V_32 = NULL ;
V_47 -> V_58 = V_74 ;
} else {
memset ( & V_47 -> V_75 , 0 , sizeof V_47 -> V_75 ) ;
V_47 -> V_75 . V_78 = V_47 -> V_77 [ 0 ] . V_78 ;
V_47 -> V_32 = & V_44 ;
V_47 -> V_58 = V_59 | V_94 ;
for ( V_39 = 0 ; V_39 < V_47 -> V_76 ; V_39 ++ )
if ( ! F_64 ( V_47 -> V_77 [ V_39 ] . V_95 ) ) {
V_47 -> V_58 = V_59 ;
break;
}
}
V_47 -> V_53 = V_53 ;
V_47 -> V_50 = V_50 ;
V_47 -> V_54 = V_47 ;
if ( V_47 -> V_75 . V_78 <= V_88 )
F_55 ( V_47 ) ;
else {
F_65 ( & V_47 -> V_87 ) ;
V_47 -> V_85 = 0 ;
F_60 ( V_47 ) ;
}
return 0 ;
}
int F_66 ( struct V_21 * V_22 ,
unsigned V_76 , struct V_91 * V_77 ,
unsigned V_20 , T_3 V_53 , void * V_50 )
{
return F_62 ( V_22 , NULL , V_76 , V_77 , V_20 , V_53 , V_50 ) ;
}
void * F_67 ( struct V_21 * V_22 ,
T_3 V_53 , void * V_50 )
{
struct V_42 * V_47 ;
V_47 = F_63 ( V_22 -> V_55 , V_93 ) ;
memset ( V_47 , 0 , sizeof( struct V_42 ) ) ;
V_47 -> V_22 = V_22 ;
V_47 -> V_53 = V_53 ;
V_47 -> V_50 = V_50 ;
V_47 -> V_54 = V_47 ;
F_56 ( & V_22 -> V_56 ) ;
return V_47 ;
}
void F_68 ( void * V_96 , int V_51 , unsigned long V_52 )
{
struct V_42 * V_47 = V_96 ;
struct V_21 * V_22 = V_47 -> V_22 ;
V_47 -> V_51 = V_51 ;
V_47 -> V_52 = V_52 ;
F_36 ( & V_22 -> V_61 , V_47 ) ;
F_12 ( V_22 ) ;
}
struct V_21 * F_69 ( struct V_1 * V_3 )
{
int V_63 = - V_37 ;
struct V_21 * V_22 ;
V_22 = F_15 ( sizeof( * V_22 ) , V_40 ) ;
if ( ! V_22 )
return F_70 ( - V_37 ) ;
F_71 ( & V_22 -> V_48 ) ;
F_72 ( & V_22 -> V_61 ) ;
F_72 ( & V_22 -> V_62 ) ;
F_72 ( & V_22 -> V_84 ) ;
V_22 -> V_3 = V_3 ;
V_22 -> V_55 = F_73 ( V_97 , V_41 ) ;
if ( ! V_22 -> V_55 )
goto V_98;
F_74 ( & V_22 -> V_24 , F_51 ) ;
V_22 -> V_23 = F_75 ( L_2 ,
V_99 | V_100 , 0 ) ;
if ( ! V_22 -> V_23 )
goto V_101;
V_22 -> V_32 = NULL ;
V_22 -> V_31 = V_22 -> V_30 = 0 ;
V_63 = F_23 ( V_22 , V_102 ) ;
if ( V_63 )
goto V_103;
V_22 -> V_73 = F_76 () ;
if ( F_77 ( V_22 -> V_73 ) ) {
V_63 = F_78 ( V_22 -> V_73 ) ;
goto V_104;
}
F_79 ( & V_22 -> V_57 ) ;
F_61 ( & V_22 -> V_56 , 0 ) ;
return V_22 ;
V_104:
F_24 ( V_22 ) ;
V_103:
F_80 ( V_22 -> V_23 ) ;
V_101:
F_81 ( V_22 -> V_55 ) ;
V_98:
F_17 ( V_22 ) ;
return F_70 ( V_63 ) ;
}
void F_82 ( struct V_21 * V_22 )
{
F_83 ( V_22 -> V_57 , ! F_84 ( & V_22 -> V_56 ) ) ;
F_25 ( ! F_33 ( & V_22 -> V_61 ) ) ;
F_25 ( ! F_33 ( & V_22 -> V_62 ) ) ;
F_25 ( ! F_33 ( & V_22 -> V_84 ) ) ;
F_80 ( V_22 -> V_23 ) ;
F_85 ( V_22 -> V_73 ) ;
F_24 ( V_22 ) ;
F_81 ( V_22 -> V_55 ) ;
F_17 ( V_22 ) ;
}
