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
F_10 ( & V_18 -> V_22 , V_19 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 , * V_12 ;
F_12 (desc, dtmp, list, entry) {
if ( ! F_13 ( & V_11 -> V_24 ) )
continue;
F_8 ( V_2 -> V_20 , L_2 , V_21 , V_11 ) ;
F_1 ( V_2 , & V_11 -> V_13 ) ;
F_1 ( V_2 , & V_11 -> V_14 ) ;
F_3 ( & V_11 -> V_8 ) ;
F_4 ( V_2 -> V_15 , V_11 ) ;
}
}
static void F_14 ( unsigned long V_25 )
{
struct V_17 * V_18 = (struct V_17 * ) V_25 ;
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
int V_26 ;
V_6 = F_17 ( & V_11 -> V_14 , struct V_5 , V_8 ) ;
F_18 ( & V_6 -> V_8 , & V_11 -> V_13 ) ;
F_8 ( V_11 -> V_2 -> V_20 , L_4 , V_21 ,
V_11 -> V_24 . V_27 , V_6 ) ;
V_26 = F_19 ( & V_6 -> V_28 ) ;
if ( ! V_26 || ( V_26 == - V_29 ) || ( V_26 == - V_30 ) )
return 0 ;
F_8 ( V_11 -> V_2 -> V_20 , L_5 , V_21 ,
V_26 , V_11 -> V_24 . V_27 , V_6 ) ;
return V_26 ;
}
static void F_20 ( struct V_10 * V_11 )
{
struct V_5 * V_6 ;
V_6 = F_21 ( & V_11 -> V_13 , struct V_5 ,
V_8 ) ;
if ( ! V_6 )
return;
F_8 ( V_11 -> V_2 -> V_20 , L_6 ,
V_21 , V_11 -> V_24 . V_27 , V_6 ) ;
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
struct V_31 * V_24 ;
unsigned long V_19 ;
do {
if ( V_11 ) {
F_20 ( V_11 ) ;
if ( ! F_24 ( & V_11 -> V_14 ) ) {
if ( V_11 -> V_32 != V_33 )
return V_11 ;
F_1 ( V_11 -> V_2 ,
& V_11 -> V_14 ) ;
}
V_24 = & V_11 -> V_24 ;
} else {
V_24 = NULL ;
}
F_9 ( & V_18 -> V_22 , V_19 ) ;
if ( V_11 ) {
if ( V_11 -> V_32 != V_33 )
V_11 -> V_32 = V_34 ;
F_8 ( V_11 -> V_2 -> V_20 ,
L_7 , V_21 ,
V_11 -> V_24 . V_27 , V_11 -> V_32 ) ;
F_25 ( V_24 ) ;
}
V_11 = F_22 ( V_18 , V_11 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
if ( V_24 ) {
if ( V_24 -> V_35 &&
( V_24 -> V_19 & V_36 ) )
V_24 -> V_35 ( V_24 -> V_37 ) ;
F_26 ( V_24 ) ;
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
static void F_29 ( void * V_25 , int V_38 )
{
struct V_10 * V_11 = V_25 ;
struct V_17 * V_18 ;
int V_26 ;
if ( V_38 == - V_29 )
return;
V_18 = F_7 ( V_11 -> V_24 . V_18 , struct V_17 ,
V_16 ) ;
F_8 ( V_18 -> V_2 -> V_20 , L_8 ,
V_21 , V_11 -> V_24 . V_27 , V_38 ) ;
if ( V_38 )
V_11 -> V_32 = V_33 ;
while ( true ) {
V_11 = F_23 ( V_18 , V_11 ) ;
if ( ! V_11 || ( V_18 -> V_32 == V_39 ) )
break;
V_26 = F_16 ( V_11 ) ;
if ( ! V_26 )
break;
V_11 -> V_32 = V_33 ;
}
F_30 ( & V_18 -> V_40 ) ;
}
static T_1 F_31 ( struct V_31 * V_24 )
{
struct V_10 * V_11 = F_7 ( V_24 , struct V_10 ,
V_24 ) ;
struct V_17 * V_18 ;
T_1 V_27 ;
unsigned long V_19 ;
V_18 = F_7 ( V_24 -> V_18 , struct V_17 , V_16 ) ;
F_9 ( & V_18 -> V_22 , V_19 ) ;
V_27 = F_32 ( V_24 ) ;
F_33 ( & V_11 -> V_8 , & V_18 -> V_14 ) ;
F_10 ( & V_18 -> V_22 , V_19 ) ;
F_8 ( V_18 -> V_2 -> V_20 , L_9 ,
V_21 , V_27 ) ;
return V_27 ;
}
static struct V_5 * F_34 ( struct V_17 * V_18 )
{
struct V_5 * V_6 ;
V_6 = F_35 ( V_18 -> V_2 -> V_9 , V_41 ) ;
if ( V_6 )
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
return V_6 ;
}
static struct V_10 * F_36 ( struct V_17 * V_18 ,
unsigned long V_19 )
{
struct V_10 * V_11 ;
V_11 = F_37 ( V_18 -> V_2 -> V_15 , V_41 ) ;
if ( ! V_11 )
return NULL ;
F_38 ( & V_11 -> V_24 , & V_18 -> V_16 ) ;
V_11 -> V_24 . V_19 = V_19 ;
V_11 -> V_24 . V_42 = F_31 ;
V_11 -> V_2 = V_18 -> V_2 ;
F_39 ( & V_11 -> V_14 ) ;
F_39 ( & V_11 -> V_13 ) ;
V_11 -> V_32 = V_43 ;
return V_11 ;
}
static struct V_10 * F_40 ( struct V_16 * V_16 ,
struct V_44 * V_45 ,
unsigned int V_46 ,
struct V_44 * V_47 ,
unsigned int V_48 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_1 * V_2 = V_18 -> V_2 ;
struct V_10 * V_11 ;
struct V_5 * V_6 ;
struct V_28 * V_28 ;
struct V_49 * V_50 ;
unsigned int V_51 , V_52 ;
unsigned int V_53 , V_54 ;
unsigned int V_55 ;
unsigned long V_56 ;
T_2 V_57 ;
if ( ! V_45 || ! V_47 )
return NULL ;
if ( ! V_46 || ! V_48 )
return NULL ;
V_11 = F_36 ( V_18 , V_19 ) ;
if ( ! V_11 )
return NULL ;
V_57 = 0 ;
V_52 = F_41 ( V_47 ) ;
V_51 = 0 ;
V_54 = F_41 ( V_45 ) ;
V_53 = 0 ;
while ( true ) {
if ( ! V_52 ) {
V_48 -- ;
if ( ! V_48 )
break;
V_47 = F_42 ( V_47 ) ;
if ( ! V_47 )
break;
V_52 = F_41 ( V_47 ) ;
V_51 = 0 ;
continue;
}
if ( ! V_54 ) {
V_46 -- ;
if ( ! V_46 )
break;
V_45 = F_42 ( V_45 ) ;
if ( ! V_45 )
break;
V_54 = F_41 ( V_45 ) ;
V_53 = 0 ;
continue;
}
V_55 = F_43 ( V_54 , V_52 ) ;
V_6 = F_34 ( V_18 ) ;
if ( ! V_6 )
goto V_38;
V_28 = & V_6 -> V_28 ;
V_50 = & V_28 -> V_58 . V_59 ;
V_28 -> V_19 = V_60 ;
V_28 -> V_19 |= V_61 ;
V_28 -> V_62 = V_63 ;
V_50 -> V_64 = V_65 ;
V_50 -> V_66 = V_67 ;
V_50 -> V_68 = F_44 ( V_47 ) + V_51 ;
V_50 -> V_69 = F_44 ( V_45 ) + V_53 ;
V_50 -> V_52 = V_55 ;
V_50 -> V_70 = 1 ;
V_28 -> V_35 = F_29 ;
V_28 -> V_25 = V_11 ;
F_33 ( & V_6 -> V_8 , & V_11 -> V_14 ) ;
F_8 ( V_2 -> V_20 ,
L_10 , V_21 ,
V_6 , & V_50 -> V_68 ,
& V_50 -> V_69 , V_50 -> V_52 ) ;
V_57 += V_55 ;
V_52 -= V_55 ;
V_51 += V_55 ;
V_54 -= V_55 ;
V_53 += V_55 ;
}
V_11 -> V_55 = V_57 ;
if ( F_24 ( & V_11 -> V_14 ) )
goto V_38;
F_8 ( V_2 -> V_20 , L_2 , V_21 , V_11 ) ;
F_9 ( & V_18 -> V_22 , V_56 ) ;
F_33 ( & V_11 -> V_8 , & V_18 -> V_14 ) ;
F_10 ( & V_18 -> V_22 , V_56 ) ;
return V_11 ;
V_38:
F_1 ( V_2 , & V_11 -> V_14 ) ;
F_4 ( V_2 -> V_15 , V_11 ) ;
return NULL ;
}
static struct V_31 * F_45 (
struct V_16 * V_16 , T_3 V_71 , T_3 V_72 , T_2 V_55 ,
unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
struct V_44 V_45 , V_47 ;
F_8 ( V_18 -> V_2 -> V_20 ,
L_11 ,
V_21 , & V_72 , & V_71 , V_55 , V_19 ) ;
F_46 ( & V_45 , 1 ) ;
F_44 ( & V_45 ) = V_71 ;
F_41 ( & V_45 ) = V_55 ;
F_46 ( & V_47 , 1 ) ;
F_44 ( & V_47 ) = V_72 ;
F_41 ( & V_47 ) = V_55 ;
V_11 = F_40 ( V_16 , & V_45 , 1 , & V_47 , 1 , V_19 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_24 ;
}
static struct V_31 * F_47 (
struct V_16 * V_16 , struct V_44 * V_45 ,
unsigned int V_46 , struct V_44 * V_47 ,
unsigned int V_48 , unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
F_8 ( V_18 -> V_2 -> V_20 ,
L_12 ,
V_21 , V_47 , V_48 , V_45 , V_46 , V_19 ) ;
V_11 = F_40 ( V_16 , V_45 , V_46 , V_47 , V_48 ,
V_19 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_24 ;
}
static struct V_31 * F_48 (
struct V_16 * V_16 , unsigned long V_19 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
V_11 = F_36 ( V_18 , V_19 ) ;
if ( ! V_11 )
return NULL ;
return & V_11 -> V_24 ;
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
static enum V_73 F_50 ( struct V_16 * V_16 ,
T_1 V_27 ,
struct V_74 * V_75 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
struct V_10 * V_11 ;
enum V_73 V_26 ;
unsigned long V_19 ;
if ( V_18 -> V_32 == V_39 ) {
V_26 = V_39 ;
goto V_76;
}
V_26 = F_51 ( V_16 , V_27 , V_75 ) ;
if ( V_26 == V_34 ) {
F_9 ( & V_18 -> V_22 , V_19 ) ;
F_52 (desc, &chan->complete, entry) {
if ( V_11 -> V_24 . V_27 != V_27 )
continue;
V_26 = V_11 -> V_32 ;
break;
}
F_10 ( & V_18 -> V_22 , V_19 ) ;
}
V_76:
F_8 ( V_18 -> V_2 -> V_20 , L_14 , V_21 , V_26 ) ;
return V_26 ;
}
static int F_53 ( struct V_16 * V_16 )
{
struct V_17 * V_18 = F_7 ( V_16 , struct V_17 ,
V_16 ) ;
V_18 -> V_32 = V_39 ;
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
V_18 -> V_32 = V_43 ;
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
F_10 ( & V_18 -> V_22 , V_19 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_2 )
{
struct V_17 * V_18 ;
struct V_77 * V_78 = & V_2 -> V_78 ;
struct V_16 * V_16 ;
char * V_79 ;
char * V_80 ;
unsigned int V_81 ;
int V_26 ;
V_2 -> V_17 = F_57 ( V_2 -> V_20 , V_2 -> V_82 ,
sizeof( * ( V_2 -> V_17 ) ) ,
V_83 ) ;
if ( ! V_2 -> V_17 )
return - V_84 ;
V_79 = F_58 ( V_2 -> V_20 , V_83 ,
L_15 ,
V_2 -> V_85 ) ;
if ( ! V_79 )
return - V_84 ;
V_2 -> V_9 = F_59 ( V_79 ,
sizeof( struct V_5 ) ,
sizeof( void * ) ,
V_86 , NULL ) ;
if ( ! V_2 -> V_9 )
return - V_84 ;
V_80 = F_58 ( V_2 -> V_20 , V_83 ,
L_16 ,
V_2 -> V_85 ) ;
if ( ! V_80 ) {
V_26 = - V_84 ;
goto V_87;
}
V_2 -> V_15 = F_59 ( V_80 ,
sizeof( struct V_10 ) ,
sizeof( void * ) ,
V_86 , NULL ) ;
if ( ! V_2 -> V_15 ) {
V_26 = - V_84 ;
goto V_87;
}
V_78 -> V_20 = V_2 -> V_20 ;
V_78 -> V_88 = F_60 ( F_61 ( V_2 -> V_20 ) ) ;
V_78 -> V_89 = F_60 ( F_61 ( V_2 -> V_20 ) ) ;
V_78 -> V_90 = V_91 ;
V_78 -> V_92 = V_93 ;
F_62 ( V_94 , V_78 -> V_95 ) ;
F_62 ( V_96 , V_78 -> V_95 ) ;
F_62 ( V_97 , V_78 -> V_95 ) ;
F_39 ( & V_78 -> V_98 ) ;
for ( V_81 = 0 ; V_81 < V_2 -> V_82 ; V_81 ++ ) {
V_18 = V_2 -> V_17 + V_81 ;
V_16 = & V_18 -> V_16 ;
V_18 -> V_2 = V_2 ;
F_63 ( & V_18 -> V_22 ) ;
F_39 ( & V_18 -> V_14 ) ;
F_39 ( & V_18 -> V_13 ) ;
F_39 ( & V_18 -> V_23 ) ;
F_64 ( & V_18 -> V_40 , F_14 ,
( unsigned long ) V_18 ) ;
V_16 -> V_99 = V_78 ;
F_65 ( V_16 ) ;
F_33 ( & V_16 -> V_100 , & V_78 -> V_98 ) ;
}
V_78 -> V_101 = F_6 ;
V_78 -> V_102 = F_45 ;
V_78 -> V_103 = F_47 ;
V_78 -> V_104 = F_48 ;
V_78 -> V_105 = F_49 ;
V_78 -> V_106 = F_50 ;
V_78 -> V_107 = F_53 ;
V_78 -> V_108 = F_54 ;
V_78 -> V_109 = F_55 ;
V_26 = F_66 ( V_78 ) ;
if ( V_26 )
goto V_110;
return 0 ;
V_110:
F_67 ( V_2 -> V_15 ) ;
V_87:
F_67 ( V_2 -> V_9 ) ;
return V_26 ;
}
void F_68 ( struct V_1 * V_2 )
{
struct V_77 * V_78 = & V_2 -> V_78 ;
F_69 ( V_78 ) ;
F_67 ( V_2 -> V_15 ) ;
F_67 ( V_2 -> V_9 ) ;
}
