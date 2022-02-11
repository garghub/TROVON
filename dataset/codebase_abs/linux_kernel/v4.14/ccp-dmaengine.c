unsigned int F_1 ( struct V_1 * V_2 )
{
switch ( V_3 ) {
case V_4 :
return V_2 -> V_5 -> V_3 ;
case V_6 :
return V_7 ;
case V_8 :
return 0 ;
default:
F_2 ( V_2 -> V_9 , L_1 ,
V_3 ) ;
return V_2 -> V_5 -> V_3 ;
}
}
static void F_3 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 , * V_14 ;
F_4 (cmd, ctmp, list, entry) {
F_5 ( & V_13 -> V_15 ) ;
F_6 ( V_2 -> V_16 , V_13 ) ;
}
}
static void F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_17 * V_18 , * V_19 ;
F_4 (desc, dtmp, list, entry) {
F_3 ( V_2 , & V_18 -> V_20 ) ;
F_3 ( V_2 , & V_18 -> V_21 ) ;
F_5 ( & V_18 -> V_15 ) ;
F_6 ( V_2 -> V_22 , V_18 ) ;
}
}
static void F_8 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
unsigned long V_26 ;
F_10 ( V_25 -> V_2 -> V_9 , L_2 , V_27 , V_25 ) ;
F_11 ( & V_25 -> V_28 , V_26 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_29 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_20 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_21 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_30 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_17 * V_18 , * V_19 ;
F_14 (desc, dtmp, list, entry) {
if ( ! F_15 ( & V_18 -> V_31 ) )
continue;
F_10 ( V_2 -> V_9 , L_3 , V_27 , V_18 ) ;
F_3 ( V_2 , & V_18 -> V_20 ) ;
F_3 ( V_2 , & V_18 -> V_21 ) ;
F_5 ( & V_18 -> V_15 ) ;
F_6 ( V_2 -> V_22 , V_18 ) ;
}
}
static void F_16 ( unsigned long V_32 )
{
struct V_24 * V_25 = (struct V_24 * ) V_32 ;
unsigned long V_26 ;
F_10 ( V_25 -> V_2 -> V_9 , L_4 , V_27 ,
F_17 ( & V_25 -> V_23 ) ) ;
F_11 ( & V_25 -> V_28 , V_26 ) ;
F_13 ( V_25 -> V_2 , & V_25 -> V_29 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
}
static int F_18 ( struct V_17 * V_18 )
{
struct V_12 * V_13 ;
int V_33 ;
V_13 = F_19 ( & V_18 -> V_21 , struct V_12 , V_15 ) ;
F_20 ( & V_13 -> V_15 , & V_18 -> V_20 ) ;
F_10 ( V_18 -> V_2 -> V_9 , L_5 , V_27 ,
V_18 -> V_31 . V_34 , V_13 ) ;
V_33 = F_21 ( & V_13 -> V_35 ) ;
if ( ! V_33 || ( V_33 == - V_36 ) || ( V_33 == - V_37 ) )
return 0 ;
F_10 ( V_18 -> V_2 -> V_9 , L_6 , V_27 ,
V_33 , V_18 -> V_31 . V_34 , V_13 ) ;
return V_33 ;
}
static void F_22 ( struct V_17 * V_18 )
{
struct V_12 * V_13 ;
V_13 = F_23 ( & V_18 -> V_20 , struct V_12 ,
V_15 ) ;
if ( ! V_13 )
return;
F_10 ( V_18 -> V_2 -> V_9 , L_7 ,
V_27 , V_18 -> V_31 . V_34 , V_13 ) ;
F_5 ( & V_13 -> V_15 ) ;
F_6 ( V_18 -> V_2 -> V_16 , V_13 ) ;
}
static struct V_17 * F_24 ( struct V_24 * V_25 ,
struct V_17 * V_18 )
{
if ( V_18 )
F_20 ( & V_18 -> V_15 , & V_25 -> V_29 ) ;
V_18 = F_23 ( & V_25 -> V_20 , struct V_17 ,
V_15 ) ;
return V_18 ;
}
static struct V_17 * F_25 ( struct V_24 * V_25 ,
struct V_17 * V_18 )
{
struct V_38 * V_31 ;
unsigned long V_26 ;
do {
if ( V_18 ) {
F_22 ( V_18 ) ;
if ( ! F_26 ( & V_18 -> V_21 ) ) {
if ( V_18 -> V_39 != V_40 )
return V_18 ;
F_3 ( V_18 -> V_2 ,
& V_18 -> V_21 ) ;
}
V_31 = & V_18 -> V_31 ;
} else {
V_31 = NULL ;
}
F_11 ( & V_25 -> V_28 , V_26 ) ;
if ( V_18 ) {
if ( V_18 -> V_39 != V_40 )
V_18 -> V_39 = V_41 ;
F_10 ( V_18 -> V_2 -> V_9 ,
L_8 , V_27 ,
V_18 -> V_31 . V_34 , V_18 -> V_39 ) ;
F_27 ( V_31 ) ;
}
V_18 = F_24 ( V_25 , V_18 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
if ( V_31 ) {
if ( V_31 -> V_42 &&
( V_31 -> V_26 & V_43 ) )
V_31 -> V_42 ( V_31 -> V_44 ) ;
F_28 ( V_31 ) ;
}
} while ( V_18 );
return NULL ;
}
static struct V_17 * F_29 ( struct V_24 * V_25 )
{
struct V_17 * V_18 ;
if ( F_26 ( & V_25 -> V_21 ) )
return NULL ;
V_18 = F_26 ( & V_25 -> V_20 )
? F_19 ( & V_25 -> V_21 , struct V_17 , V_15 )
: NULL ;
F_30 ( & V_25 -> V_21 , & V_25 -> V_20 ) ;
return V_18 ;
}
static void F_31 ( void * V_32 , int V_45 )
{
struct V_17 * V_18 = V_32 ;
struct V_24 * V_25 ;
int V_33 ;
if ( V_45 == - V_36 )
return;
V_25 = F_9 ( V_18 -> V_31 . V_25 , struct V_24 ,
V_23 ) ;
F_10 ( V_25 -> V_2 -> V_9 , L_9 ,
V_27 , V_18 -> V_31 . V_34 , V_45 ) ;
if ( V_45 )
V_18 -> V_39 = V_40 ;
while ( true ) {
V_18 = F_25 ( V_25 , V_18 ) ;
if ( ! V_18 || ( V_25 -> V_39 == V_46 ) )
break;
V_33 = F_18 ( V_18 ) ;
if ( ! V_33 )
break;
V_18 -> V_39 = V_40 ;
}
F_32 ( & V_25 -> V_47 ) ;
}
static T_1 F_33 ( struct V_38 * V_31 )
{
struct V_17 * V_18 = F_9 ( V_31 , struct V_17 ,
V_31 ) ;
struct V_24 * V_25 ;
T_1 V_34 ;
unsigned long V_26 ;
V_25 = F_9 ( V_31 -> V_25 , struct V_24 , V_23 ) ;
F_11 ( & V_25 -> V_28 , V_26 ) ;
V_34 = F_34 ( V_31 ) ;
F_5 ( & V_18 -> V_15 ) ;
F_35 ( & V_18 -> V_15 , & V_25 -> V_21 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
F_10 ( V_25 -> V_2 -> V_9 , L_10 ,
V_27 , V_34 ) ;
return V_34 ;
}
static struct V_12 * F_36 ( struct V_24 * V_25 )
{
struct V_12 * V_13 ;
V_13 = F_37 ( V_25 -> V_2 -> V_16 , V_48 ) ;
if ( V_13 )
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
return V_13 ;
}
static struct V_17 * F_38 ( struct V_24 * V_25 ,
unsigned long V_26 )
{
struct V_17 * V_18 ;
V_18 = F_39 ( V_25 -> V_2 -> V_22 , V_48 ) ;
if ( ! V_18 )
return NULL ;
F_40 ( & V_18 -> V_31 , & V_25 -> V_23 ) ;
V_18 -> V_31 . V_26 = V_26 ;
V_18 -> V_31 . V_49 = F_33 ;
V_18 -> V_2 = V_25 -> V_2 ;
F_41 ( & V_18 -> V_21 ) ;
F_41 ( & V_18 -> V_20 ) ;
V_18 -> V_39 = V_50 ;
return V_18 ;
}
static struct V_17 * F_42 ( struct V_23 * V_23 ,
struct V_51 * V_52 ,
unsigned int V_53 ,
struct V_51 * V_54 ,
unsigned int V_55 ,
unsigned long V_26 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
struct V_1 * V_2 = V_25 -> V_2 ;
struct V_17 * V_18 ;
struct V_12 * V_13 ;
struct V_35 * V_35 ;
struct V_56 * V_57 ;
unsigned int V_58 , V_59 ;
unsigned int V_60 , V_61 ;
unsigned int V_62 ;
unsigned long V_63 ;
T_2 V_64 ;
if ( ! V_52 || ! V_54 )
return NULL ;
if ( ! V_53 || ! V_55 )
return NULL ;
V_18 = F_38 ( V_25 , V_26 ) ;
if ( ! V_18 )
return NULL ;
V_64 = 0 ;
V_59 = F_43 ( V_54 ) ;
V_58 = 0 ;
V_61 = F_43 ( V_52 ) ;
V_60 = 0 ;
while ( true ) {
if ( ! V_59 ) {
V_55 -- ;
if ( ! V_55 )
break;
V_54 = F_44 ( V_54 ) ;
if ( ! V_54 )
break;
V_59 = F_43 ( V_54 ) ;
V_58 = 0 ;
continue;
}
if ( ! V_61 ) {
V_53 -- ;
if ( ! V_53 )
break;
V_52 = F_44 ( V_52 ) ;
if ( ! V_52 )
break;
V_61 = F_43 ( V_52 ) ;
V_60 = 0 ;
continue;
}
V_62 = F_45 ( V_61 , V_59 ) ;
V_13 = F_36 ( V_25 ) ;
if ( ! V_13 )
goto V_45;
V_35 = & V_13 -> V_35 ;
V_35 -> V_2 = V_25 -> V_2 ;
V_57 = & V_35 -> V_65 . V_66 ;
V_35 -> V_26 = V_67 ;
V_35 -> V_26 |= V_68 ;
V_35 -> V_69 = V_70 ;
V_57 -> V_71 = V_72 ;
V_57 -> V_73 = V_74 ;
V_57 -> V_75 = F_46 ( V_54 ) + V_58 ;
V_57 -> V_76 = F_46 ( V_52 ) + V_60 ;
V_57 -> V_59 = V_62 ;
V_57 -> V_77 = 1 ;
V_35 -> V_42 = F_31 ;
V_35 -> V_32 = V_18 ;
F_35 ( & V_13 -> V_15 , & V_18 -> V_21 ) ;
F_10 ( V_2 -> V_9 ,
L_11 , V_27 ,
V_13 , & V_57 -> V_75 ,
& V_57 -> V_76 , V_57 -> V_59 ) ;
V_64 += V_62 ;
V_59 -= V_62 ;
V_58 += V_62 ;
V_61 -= V_62 ;
V_60 += V_62 ;
}
V_18 -> V_62 = V_64 ;
if ( F_26 ( & V_18 -> V_21 ) )
goto V_45;
F_10 ( V_2 -> V_9 , L_3 , V_27 , V_18 ) ;
F_11 ( & V_25 -> V_28 , V_63 ) ;
F_35 ( & V_18 -> V_15 , & V_25 -> V_30 ) ;
F_12 ( & V_25 -> V_28 , V_63 ) ;
return V_18 ;
V_45:
F_3 ( V_2 , & V_18 -> V_21 ) ;
F_6 ( V_2 -> V_22 , V_18 ) ;
return NULL ;
}
static struct V_38 * F_47 (
struct V_23 * V_23 , T_3 V_78 , T_3 V_79 , T_2 V_62 ,
unsigned long V_26 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
struct V_17 * V_18 ;
struct V_51 V_52 , V_54 ;
F_10 ( V_25 -> V_2 -> V_9 ,
L_12 ,
V_27 , & V_79 , & V_78 , V_62 , V_26 ) ;
F_48 ( & V_52 , 1 ) ;
F_46 ( & V_52 ) = V_78 ;
F_43 ( & V_52 ) = V_62 ;
F_48 ( & V_54 , 1 ) ;
F_46 ( & V_54 ) = V_79 ;
F_43 ( & V_54 ) = V_62 ;
V_18 = F_42 ( V_23 , & V_52 , 1 , & V_54 , 1 , V_26 ) ;
if ( ! V_18 )
return NULL ;
return & V_18 -> V_31 ;
}
static struct V_38 * F_49 (
struct V_23 * V_23 , unsigned long V_26 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
struct V_17 * V_18 ;
V_18 = F_38 ( V_25 , V_26 ) ;
if ( ! V_18 )
return NULL ;
return & V_18 -> V_31 ;
}
static void F_50 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
struct V_17 * V_18 ;
unsigned long V_26 ;
F_10 ( V_25 -> V_2 -> V_9 , L_13 , V_27 ) ;
F_11 ( & V_25 -> V_28 , V_26 ) ;
V_18 = F_29 ( V_25 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
if ( V_18 )
F_31 ( V_18 , 0 ) ;
}
static enum V_80 F_51 ( struct V_23 * V_23 ,
T_1 V_34 ,
struct V_81 * V_82 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
struct V_17 * V_18 ;
enum V_80 V_33 ;
unsigned long V_26 ;
if ( V_25 -> V_39 == V_46 ) {
V_33 = V_46 ;
goto V_83;
}
V_33 = F_52 ( V_23 , V_34 , V_82 ) ;
if ( V_33 == V_41 ) {
F_11 ( & V_25 -> V_28 , V_26 ) ;
F_53 (desc, &chan->complete, entry) {
if ( V_18 -> V_31 . V_34 != V_34 )
continue;
V_33 = V_18 -> V_39 ;
break;
}
F_12 ( & V_25 -> V_28 , V_26 ) ;
}
V_83:
F_10 ( V_25 -> V_2 -> V_9 , L_14 , V_27 , V_33 ) ;
return V_33 ;
}
static int F_54 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
V_25 -> V_39 = V_46 ;
return 0 ;
}
static int F_55 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
struct V_17 * V_18 ;
unsigned long V_26 ;
F_11 ( & V_25 -> V_28 , V_26 ) ;
V_18 = F_23 ( & V_25 -> V_20 , struct V_17 ,
V_15 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
V_25 -> V_39 = V_50 ;
if ( V_18 )
F_31 ( V_18 , 0 ) ;
return 0 ;
}
static int F_56 ( struct V_23 * V_23 )
{
struct V_24 * V_25 = F_9 ( V_23 , struct V_24 ,
V_23 ) ;
unsigned long V_26 ;
F_10 ( V_25 -> V_2 -> V_9 , L_13 , V_27 ) ;
F_11 ( & V_25 -> V_28 , V_26 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_20 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_21 ) ;
F_7 ( V_25 -> V_2 , & V_25 -> V_30 ) ;
F_12 ( & V_25 -> V_28 , V_26 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_2 )
{
struct V_24 * V_25 ;
struct V_84 * V_85 = & V_2 -> V_85 ;
struct V_23 * V_23 ;
char * V_86 ;
char * V_87 ;
unsigned int V_88 ;
int V_33 ;
V_2 -> V_24 = F_58 ( V_2 -> V_9 , V_2 -> V_89 ,
sizeof( * ( V_2 -> V_24 ) ) ,
V_90 ) ;
if ( ! V_2 -> V_24 )
return - V_91 ;
V_86 = F_59 ( V_2 -> V_9 , V_90 ,
L_15 ,
V_2 -> V_92 ) ;
if ( ! V_86 )
return - V_91 ;
V_2 -> V_16 = F_60 ( V_86 ,
sizeof( struct V_12 ) ,
sizeof( void * ) ,
V_93 , NULL ) ;
if ( ! V_2 -> V_16 )
return - V_91 ;
V_87 = F_59 ( V_2 -> V_9 , V_90 ,
L_16 ,
V_2 -> V_92 ) ;
if ( ! V_87 ) {
V_33 = - V_91 ;
goto V_94;
}
V_2 -> V_22 = F_60 ( V_87 ,
sizeof( struct V_17 ) ,
sizeof( void * ) ,
V_93 , NULL ) ;
if ( ! V_2 -> V_22 ) {
V_33 = - V_91 ;
goto V_94;
}
V_85 -> V_9 = V_2 -> V_9 ;
V_85 -> V_95 = F_61 ( F_62 ( V_2 -> V_9 ) ) ;
V_85 -> V_96 = F_61 ( F_62 ( V_2 -> V_9 ) ) ;
V_85 -> V_97 = V_98 ;
V_85 -> V_99 = V_100 ;
F_63 ( V_101 , V_85 -> V_102 ) ;
F_63 ( V_103 , V_85 -> V_102 ) ;
if ( F_1 ( V_2 ) == V_7 )
F_63 ( V_7 , V_85 -> V_102 ) ;
F_41 ( & V_85 -> V_104 ) ;
for ( V_88 = 0 ; V_88 < V_2 -> V_89 ; V_88 ++ ) {
V_25 = V_2 -> V_24 + V_88 ;
V_23 = & V_25 -> V_23 ;
V_25 -> V_2 = V_2 ;
F_64 ( & V_25 -> V_28 ) ;
F_41 ( & V_25 -> V_30 ) ;
F_41 ( & V_25 -> V_21 ) ;
F_41 ( & V_25 -> V_20 ) ;
F_41 ( & V_25 -> V_29 ) ;
F_65 ( & V_25 -> V_47 , F_16 ,
( unsigned long ) V_25 ) ;
V_23 -> V_105 = V_85 ;
F_66 ( V_23 ) ;
F_35 ( & V_23 -> V_106 , & V_85 -> V_104 ) ;
}
V_85 -> V_107 = F_8 ;
V_85 -> V_108 = F_47 ;
V_85 -> V_109 = F_49 ;
V_85 -> V_110 = F_50 ;
V_85 -> V_111 = F_51 ;
V_85 -> V_112 = F_54 ;
V_85 -> V_113 = F_55 ;
V_85 -> V_114 = F_56 ;
V_33 = F_67 ( V_85 ) ;
if ( V_33 )
goto V_115;
return 0 ;
V_115:
F_68 ( V_2 -> V_22 ) ;
V_94:
F_68 ( V_2 -> V_16 ) ;
return V_33 ;
}
void F_69 ( struct V_1 * V_2 )
{
struct V_84 * V_85 = & V_2 -> V_85 ;
F_70 ( V_85 ) ;
F_68 ( V_2 -> V_22 ) ;
F_68 ( V_2 -> V_16 ) ;
}
