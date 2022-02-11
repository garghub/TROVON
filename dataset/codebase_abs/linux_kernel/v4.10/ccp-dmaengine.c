static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 , * V_7 ;
F_2 (cmd, ctmp, list, entry) {
F_3 ( & V_6 -> V_8 ) ;
F_4 ( V_2 -> V_9 , V_6 ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 , * V_12 ;
F_2 (desc, dtmp, list, entry) {
F_1 ( V_2 , & V_11 -> V_13 ) ;
F_1 ( V_2 , & V_11 -> V_14 ) ;
F_3 ( & V_11 -> V_8 ) ;
F_4 ( V_2 -> V_15 , V_11 ) ;
}
}
static void F_6 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
unsigned long V_19 ;
F_8 ( V_18 -> V_2 -> V_20 , L_1 , V_21 , V_18 ) ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_23 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_13 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_14 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_24 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 , * V_12 ;
F_12 (desc, dtmp, list, entry) {
if ( ! F_13 ( & V_11 -> V_25 ) )
continue;
F_8 ( V_2 -> V_20 , L_2 , V_21 , V_11 ) ;
F_1 ( V_2 , & V_11 -> V_13 ) ;
F_1 ( V_2 , & V_11 -> V_14 ) ;
F_3 ( & V_11 -> V_8 ) ;
F_4 ( V_2 -> V_15 , V_11 ) ;
}
}
static void F_14 ( unsigned long V_26 )
{
struct V_17 * V_18 = (struct V_17 * ) V_26 ;
unsigned long V_19 ;
F_8 ( V_18 -> V_2 -> V_20 , L_3 , V_21 ,
F_15 ( & V_18 -> V_16 ) ) ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
F_11 ( V_18 -> V_2 , & V_18 -> V_23 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
}
static int F_16 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_27 ;
V_6 = F_17 ( & V_11 -> V_14 , struct V_5 , V_8 ) ;
F_18 ( & V_6 -> V_8 , & V_11 -> V_13 ) ;
F_8 ( V_11 -> V_2 -> V_20 , L_4 , V_21 ,
V_11 -> V_25 . V_28 , V_6 ) ;
V_27 = F_19 ( & V_6 -> V_29 ) ;
if ( ! V_27 || ( V_27 == - V_30 ) || ( V_27 == - V_31 ) )
return 0 ;
F_8 ( V_11 -> V_2 -> V_20 , L_5 , V_21 ,
V_27 , V_11 -> V_25 . V_28 , V_6 ) ;
return V_27 ;
}
static void F_20 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
V_6 = F_21 ( & V_11 -> V_13 , struct V_5 ,
V_8 ) ;
if ( ! V_6 )
return;
F_8 ( V_11 -> V_2 -> V_20 , L_6 ,
V_21 , V_11 -> V_25 . V_28 , V_6 ) ;
F_3 ( & V_6 -> V_8 ) ;
F_4 ( V_11 -> V_2 -> V_9 , V_6 ) ;
}
static struct V_10 * F_22 ( struct V_17 * V_18 ,
struct V_10 * V_11 )
{
if ( V_11 )
F_18 ( & V_11 -> V_8 , & V_18 -> V_23 ) ;
V_11 = F_21 ( & V_18 -> V_13 , struct V_10 ,
V_8 ) ;
return V_11 ;
}
static struct V_10 * F_23 ( struct V_17 * V_18 ,
struct V_10 * V_11 )
{
struct V_32 * V_25 ;
unsigned long V_19 ;
do {
if ( V_11 ) {
F_20 ( V_11 ) ;
if ( ! F_24 ( & V_11 -> V_14 ) ) {
if ( V_11 -> V_33 != V_34 )
return V_11 ;
F_1 ( V_11 -> V_2 ,
& V_11 -> V_14 ) ;
}
V_25 = & V_11 -> V_25 ;
} else {
V_25 = NULL ;
}
F_9 ( & V_18 -> V_22 , V_19 ) ;
if ( V_11 ) {
if ( V_11 -> V_33 != V_34 )
V_11 -> V_33 = V_35 ;
F_8 ( V_11 -> V_2 -> V_20 ,
L_7 , V_21 ,
V_11 -> V_25 . V_28 , V_11 -> V_33 ) ;
F_25 ( V_25 ) ;
}
V_11 = F_22 ( V_18 , V_11 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
if ( V_25 ) {
if ( V_25 -> V_36 &&
( V_25 -> V_19 & V_37 ) )
V_25 -> V_36 ( V_25 -> V_38 ) ;
F_26 ( V_25 ) ;
}
} while ( V_11 );
return NULL ;
}
static struct V_10 * F_27 ( struct V_17 * V_18 )
{
struct V_10 * V_11 ;
if ( F_24 ( & V_18 -> V_14 ) )
return NULL ;
V_11 = F_24 ( & V_18 -> V_13 )
? F_17 ( & V_18 -> V_14 , struct V_10 , V_8 )
: NULL ;
F_28 ( & V_18 -> V_14 , & V_18 -> V_13 ) ;
return V_11 ;
}
static void F_29 ( void * V_26 , int V_39 )
{
struct V_10 * V_11 = V_26 ;
struct V_17 * V_18 ;
int V_27 ;
if ( V_39 == - V_30 )
return;
V_18 = F_7 ( V_11 -> V_25 . V_18 , struct V_17 ,
V_16 ) ;
F_8 ( V_18 -> V_2 -> V_20 , L_8 ,
V_21 , V_11 -> V_25 . V_28 , V_39 ) ;
if ( V_39 )
V_11 -> V_33 = V_34 ;
while ( true ) {
V_11 = F_23 ( V_18 , V_11 ) ;
if ( ! V_11 || ( V_18 -> V_33 == V_40 ) )
break;
V_27 = F_16 ( V_11 ) ;
if ( ! V_27 )
break;
V_11 -> V_33 = V_34 ;
}
F_30 ( & V_18 -> V_41 ) ;
}
static T_1 F_31 ( struct V_32 * V_25 )
{
struct V_10 * V_11 = F_7 ( V_25 , struct V_10 ,
V_25 ) ;
struct V_17 * V_18 ;
T_1 V_28 ;
unsigned long V_19 ;
V_18 = F_7 ( V_25 -> V_18 , struct V_17 , V_16 ) ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
V_28 = F_32 ( V_25 ) ;
F_3 ( & V_11 -> V_8 ) ;
F_33 ( & V_11 -> V_8 , & V_18 -> V_14 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
F_8 ( V_18 -> V_2 -> V_20 , L_9 ,
V_21 , V_28 ) ;
return V_28 ;
}
static struct V_5 * F_34 ( struct V_17 * V_18 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_18 -> V_2 -> V_9 , V_42 ) ;
if ( V_6 )
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
return V_6 ;
}
static struct V_10 * F_36 ( struct V_17 * V_18 ,
unsigned long V_19 )
{
struct V_10 * V_11 ;
V_11 = F_37 ( V_18 -> V_2 -> V_15 , V_42 ) ;
if ( ! V_11 )
return NULL ;
F_38 ( & V_11 -> V_25 , & V_18 -> V_16 ) ;
V_11 -> V_25 . V_19 = V_19 ;
V_11 -> V_25 . V_43 = F_31 ;
V_11 -> V_2 = V_18 -> V_2 ;
F_39 ( & V_11 -> V_14 ) ;
F_39 ( & V_11 -> V_13 ) ;
V_11 -> V_33 = V_44 ;
return V_11 ;
}
static struct V_10 * F_40 ( struct V_16 * V_16 ,
struct V_45 * V_46 ,
unsigned int V_47 ,
struct V_45 * V_48 ,
unsigned int V_49 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_10 * V_11 ;
struct V_5 * V_6 ;
struct V_29 * V_29 ;
struct V_50 * V_51 ;
unsigned int V_52 , V_53 ;
unsigned int V_54 , V_55 ;
unsigned int V_56 ;
unsigned long V_57 ;
T_2 V_58 ;
if ( ! V_46 || ! V_48 )
return NULL ;
if ( ! V_47 || ! V_49 )
return NULL ;
V_11 = F_36 ( V_18 , V_19 ) ;
if ( ! V_11 )
return NULL ;
V_58 = 0 ;
V_53 = F_41 ( V_48 ) ;
V_52 = 0 ;
V_55 = F_41 ( V_46 ) ;
V_54 = 0 ;
while ( true ) {
if ( ! V_53 ) {
V_49 -- ;
if ( ! V_49 )
break;
V_48 = F_42 ( V_48 ) ;
if ( ! V_48 )
break;
V_53 = F_41 ( V_48 ) ;
V_52 = 0 ;
continue;
}
if ( ! V_55 ) {
V_47 -- ;
if ( ! V_47 )
break;
V_46 = F_42 ( V_46 ) ;
if ( ! V_46 )
break;
V_55 = F_41 ( V_46 ) ;
V_54 = 0 ;
continue;
}
V_56 = F_43 ( V_55 , V_53 ) ;
V_6 = F_34 ( V_18 ) ;
if ( ! V_6 )
goto V_39;
V_29 = & V_6 -> V_29 ;
V_51 = & V_29 -> V_59 . V_60 ;
V_29 -> V_19 = V_61 ;
V_29 -> V_19 |= V_62 ;
V_29 -> V_63 = V_64 ;
V_51 -> V_65 = V_66 ;
V_51 -> V_67 = V_68 ;
V_51 -> V_69 = F_44 ( V_48 ) + V_52 ;
V_51 -> V_70 = F_44 ( V_46 ) + V_54 ;
V_51 -> V_53 = V_56 ;
V_51 -> V_71 = 1 ;
V_29 -> V_36 = F_29 ;
V_29 -> V_26 = V_11 ;
F_33 ( & V_6 -> V_8 , & V_11 -> V_14 ) ;
F_8 ( V_2 -> V_20 ,
L_10 , V_21 ,
V_6 , & V_51 -> V_69 ,
& V_51 -> V_70 , V_51 -> V_53 ) ;
V_58 += V_56 ;
V_53 -= V_56 ;
V_52 += V_56 ;
V_55 -= V_56 ;
V_54 += V_56 ;
}
V_11 -> V_56 = V_58 ;
if ( F_24 ( & V_11 -> V_14 ) )
goto V_39;
F_8 ( V_2 -> V_20 , L_2 , V_21 , V_11 ) ;
F_9 ( & V_18 -> V_22 , V_57 ) ;
F_33 ( & V_11 -> V_8 , & V_18 -> V_24 ) ;
F_10 ( & V_18 -> V_22 , V_57 ) ;
return V_11 ;
V_39:
F_1 ( V_2 , & V_11 -> V_14 ) ;
F_4 ( V_2 -> V_15 , V_11 ) ;
return NULL ;
}
static struct V_32 * F_45 (
struct V_16 * V_16 , T_3 V_72 , T_3 V_73 , T_2 V_56 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
struct V_45 V_46 , V_48 ;
F_8 ( V_18 -> V_2 -> V_20 ,
L_11 ,
V_21 , & V_73 , & V_72 , V_56 , V_19 ) ;
F_46 ( & V_46 , 1 ) ;
F_44 ( & V_46 ) = V_72 ;
F_41 ( & V_46 ) = V_56 ;
F_46 ( & V_48 , 1 ) ;
F_44 ( & V_48 ) = V_73 ;
F_41 ( & V_48 ) = V_56 ;
V_11 = F_40 ( V_16 , & V_46 , 1 , & V_48 , 1 , V_19 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_25 ;
}
static struct V_32 * F_47 (
struct V_16 * V_16 , struct V_45 * V_46 ,
unsigned int V_47 , struct V_45 * V_48 ,
unsigned int V_49 , unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
F_8 ( V_18 -> V_2 -> V_20 ,
L_12 ,
V_21 , V_48 , V_49 , V_46 , V_47 , V_19 ) ;
V_11 = F_40 ( V_16 , V_46 , V_47 , V_48 , V_49 ,
V_19 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_25 ;
}
static struct V_32 * F_48 (
struct V_16 * V_16 , unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
V_11 = F_36 ( V_18 , V_19 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_25 ;
}
static void F_49 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
unsigned long V_19 ;
F_8 ( V_18 -> V_2 -> V_20 , L_13 , V_21 ) ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
V_11 = F_27 ( V_18 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
if ( V_11 )
F_29 ( V_11 , 0 ) ;
}
static enum V_74 F_50 ( struct V_16 * V_16 ,
T_1 V_28 ,
struct V_75 * V_76 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
enum V_74 V_27 ;
unsigned long V_19 ;
if ( V_18 -> V_33 == V_40 ) {
V_27 = V_40 ;
goto V_77;
}
V_27 = F_51 ( V_16 , V_28 , V_76 ) ;
if ( V_27 == V_35 ) {
F_9 ( & V_18 -> V_22 , V_19 ) ;
F_52 (desc, &chan->complete, entry) {
if ( V_11 -> V_25 . V_28 != V_28 )
continue;
V_27 = V_11 -> V_33 ;
break;
}
F_10 ( & V_18 -> V_22 , V_19 ) ;
}
V_77:
F_8 ( V_18 -> V_2 -> V_20 , L_14 , V_21 , V_27 ) ;
return V_27 ;
}
static int F_53 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
V_18 -> V_33 = V_40 ;
return 0 ;
}
static int F_54 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
unsigned long V_19 ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
V_11 = F_21 ( & V_18 -> V_13 , struct V_10 ,
V_8 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
V_18 -> V_33 = V_44 ;
if ( V_11 )
F_29 ( V_11 , 0 ) ;
return 0 ;
}
static int F_55 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
unsigned long V_19 ;
F_8 ( V_18 -> V_2 -> V_20 , L_13 , V_21 ) ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_13 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_14 ) ;
F_5 ( V_18 -> V_2 , & V_18 -> V_24 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_78 * V_79 = & V_2 -> V_79 ;
struct V_16 * V_16 ;
char * V_80 ;
char * V_81 ;
unsigned int V_82 ;
int V_27 ;
V_2 -> V_17 = F_57 ( V_2 -> V_20 , V_2 -> V_83 ,
sizeof( * ( V_2 -> V_17 ) ) ,
V_84 ) ;
if ( ! V_2 -> V_17 )
return - V_85 ;
V_80 = F_58 ( V_2 -> V_20 , V_84 ,
L_15 ,
V_2 -> V_86 ) ;
if ( ! V_80 )
return - V_85 ;
V_2 -> V_9 = F_59 ( V_80 ,
sizeof( struct V_5 ) ,
sizeof( void * ) ,
V_87 , NULL ) ;
if ( ! V_2 -> V_9 )
return - V_85 ;
V_81 = F_58 ( V_2 -> V_20 , V_84 ,
L_16 ,
V_2 -> V_86 ) ;
if ( ! V_81 ) {
V_27 = - V_85 ;
goto V_88;
}
V_2 -> V_15 = F_59 ( V_81 ,
sizeof( struct V_10 ) ,
sizeof( void * ) ,
V_87 , NULL ) ;
if ( ! V_2 -> V_15 ) {
V_27 = - V_85 ;
goto V_88;
}
V_79 -> V_20 = V_2 -> V_20 ;
V_79 -> V_89 = F_60 ( F_61 ( V_2 -> V_20 ) ) ;
V_79 -> V_90 = F_60 ( F_61 ( V_2 -> V_20 ) ) ;
V_79 -> V_91 = V_92 ;
V_79 -> V_93 = V_94 ;
F_62 ( V_95 , V_79 -> V_96 ) ;
F_62 ( V_97 , V_79 -> V_96 ) ;
F_62 ( V_98 , V_79 -> V_96 ) ;
F_39 ( & V_79 -> V_99 ) ;
for ( V_82 = 0 ; V_82 < V_2 -> V_83 ; V_82 ++ ) {
V_18 = V_2 -> V_17 + V_82 ;
V_16 = & V_18 -> V_16 ;
V_18 -> V_2 = V_2 ;
F_63 ( & V_18 -> V_22 ) ;
F_39 ( & V_18 -> V_24 ) ;
F_39 ( & V_18 -> V_14 ) ;
F_39 ( & V_18 -> V_13 ) ;
F_39 ( & V_18 -> V_23 ) ;
F_64 ( & V_18 -> V_41 , F_14 ,
( unsigned long ) V_18 ) ;
V_16 -> V_100 = V_79 ;
F_65 ( V_16 ) ;
F_33 ( & V_16 -> V_101 , & V_79 -> V_99 ) ;
}
V_79 -> V_102 = F_6 ;
V_79 -> V_103 = F_45 ;
V_79 -> V_104 = F_47 ;
V_79 -> V_105 = F_48 ;
V_79 -> V_106 = F_49 ;
V_79 -> V_107 = F_50 ;
V_79 -> V_108 = F_53 ;
V_79 -> V_109 = F_54 ;
V_79 -> V_110 = F_55 ;
V_27 = F_66 ( V_79 ) ;
if ( V_27 )
goto V_111;
return 0 ;
V_111:
F_67 ( V_2 -> V_15 ) ;
V_88:
F_67 ( V_2 -> V_9 ) ;
return V_27 ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_78 * V_79 = & V_2 -> V_79 ;
F_69 ( V_79 ) ;
F_67 ( V_2 -> V_15 ) ;
F_67 ( V_2 -> V_9 ) ;
}
