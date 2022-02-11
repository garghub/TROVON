static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
if ( F_2 ( V_3 ) ) {
F_3 ( L_1 , V_5 ) ;
return F_4 ( - V_6 ) ;
}
F_5 ( ! F_6 ( & V_7 ) ,
L_2 ) ;
F_7 (tmp_devfreq, &devfreq_list, node) {
if ( V_4 -> V_3 . V_8 == V_3 )
return V_4 ;
}
return F_4 ( - V_9 ) ;
}
static int F_8 ( struct V_1 * V_1 , unsigned long V_10 )
{
int V_11 ;
for ( V_11 = 0 ; V_11 < V_1 -> V_12 -> V_13 ; V_11 ++ )
if ( V_10 == V_1 -> V_12 -> V_14 [ V_11 ] )
return V_11 ;
return - V_6 ;
}
static void F_9 ( struct V_1 * V_1 )
{
struct V_15 * V_12 = V_1 -> V_12 ;
struct V_16 * V_17 ;
unsigned long V_10 ;
int V_18 , V_19 ;
V_19 = F_10 ( V_1 -> V_3 . V_8 ) ;
if ( V_19 <= 0 )
return;
V_12 -> V_13 = V_19 ;
V_12 -> V_14 = F_11 ( V_1 -> V_3 . V_8 ,
V_12 -> V_13 ,
sizeof( * V_12 -> V_14 ) ,
V_20 ) ;
if ( ! V_12 -> V_14 ) {
V_12 -> V_13 = 0 ;
return;
}
for ( V_18 = 0 , V_10 = 0 ; V_18 < V_12 -> V_13 ; V_18 ++ , V_10 ++ ) {
V_17 = F_12 ( V_1 -> V_3 . V_8 , & V_10 ) ;
if ( F_13 ( V_17 ) ) {
F_14 ( V_1 -> V_3 . V_8 , V_12 -> V_14 ) ;
V_12 -> V_13 = 0 ;
return;
}
F_15 ( V_17 ) ;
V_12 -> V_14 [ V_18 ] = V_10 ;
}
}
int F_16 ( struct V_1 * V_1 , unsigned long V_10 )
{
int V_11 , V_21 , V_22 = 0 ;
unsigned long V_23 ;
V_23 = V_24 ;
if ( ! V_1 -> V_25 )
goto V_26;
V_21 = F_8 ( V_1 , V_1 -> V_25 ) ;
if ( V_21 < 0 ) {
V_22 = V_21 ;
goto V_26;
}
V_1 -> V_27 [ V_21 ] +=
V_23 - V_1 -> V_28 ;
V_11 = F_8 ( V_1 , V_10 ) ;
if ( V_11 < 0 ) {
V_22 = V_11 ;
goto V_26;
}
if ( V_11 != V_21 ) {
V_1 -> V_29 [ ( V_21 *
V_1 -> V_12 -> V_13 ) + V_11 ] ++ ;
V_1 -> V_30 ++ ;
}
V_26:
V_1 -> V_28 = V_23 ;
return V_22 ;
}
static struct V_31 * F_17 ( const char * V_32 )
{
struct V_31 * V_33 ;
if ( F_2 ( V_32 ) ) {
F_3 ( L_1 , V_5 ) ;
return F_4 ( - V_6 ) ;
}
F_5 ( ! F_6 ( & V_7 ) ,
L_2 ) ;
F_7 (tmp_governor, &devfreq_governor_list, node) {
if ( ! strncmp ( V_33 -> V_32 , V_32 , V_34 ) )
return V_33 ;
}
return F_4 ( - V_9 ) ;
}
static int F_18 ( struct V_1 * V_1 ,
struct V_35 * V_36 , unsigned int V_37 )
{
if ( ! V_1 )
return - V_6 ;
switch ( V_37 ) {
case V_38 :
F_19 ( & V_1 -> V_39 ,
V_38 , V_36 ) ;
break;
case V_40 :
F_19 ( & V_1 -> V_39 ,
V_40 , V_36 ) ;
break;
default:
return - V_6 ;
}
return 0 ;
}
int F_20 ( struct V_1 * V_1 )
{
struct V_35 V_36 ;
unsigned long V_10 , V_41 ;
int V_42 = 0 ;
T_1 V_43 = 0 ;
if ( ! F_6 ( & V_1 -> V_44 ) ) {
F_5 ( true , L_3 ) ;
return - V_6 ;
}
if ( ! V_1 -> V_45 )
return - V_6 ;
V_42 = V_1 -> V_45 -> V_46 ( V_1 , & V_10 ) ;
if ( V_42 )
return V_42 ;
if ( V_1 -> V_47 && V_10 < V_1 -> V_47 ) {
V_10 = V_1 -> V_47 ;
V_43 &= ~ V_48 ;
}
if ( V_1 -> V_49 && V_10 > V_1 -> V_49 ) {
V_10 = V_1 -> V_49 ;
V_43 |= V_48 ;
}
if ( V_1 -> V_12 -> V_50 )
V_1 -> V_12 -> V_50 ( V_1 -> V_3 . V_8 , & V_41 ) ;
else
V_41 = V_1 -> V_25 ;
V_36 . V_51 = V_41 ;
V_36 . V_52 = V_10 ;
F_18 ( V_1 , & V_36 , V_38 ) ;
V_42 = V_1 -> V_12 -> V_53 ( V_1 -> V_3 . V_8 , & V_10 , V_43 ) ;
if ( V_42 ) {
V_36 . V_52 = V_41 ;
F_18 ( V_1 , & V_36 , V_40 ) ;
return V_42 ;
}
V_36 . V_52 = V_10 ;
F_18 ( V_1 , & V_36 , V_40 ) ;
if ( V_1 -> V_12 -> V_14 )
if ( F_16 ( V_1 , V_10 ) )
F_21 ( & V_1 -> V_3 ,
L_4 ) ;
V_1 -> V_25 = V_10 ;
return V_42 ;
}
static void F_22 ( struct V_54 * V_55 )
{
int V_42 ;
struct V_1 * V_1 = F_23 ( V_55 ,
struct V_1 , V_55 . V_55 ) ;
F_24 ( & V_1 -> V_44 ) ;
V_42 = F_20 ( V_1 ) ;
if ( V_42 )
F_21 ( & V_1 -> V_3 , L_5 , V_42 ) ;
F_25 ( V_56 , & V_1 -> V_55 ,
F_26 ( V_1 -> V_12 -> V_57 ) ) ;
F_27 ( & V_1 -> V_44 ) ;
}
void F_28 ( struct V_1 * V_1 )
{
F_29 ( & V_1 -> V_55 , F_22 ) ;
if ( V_1 -> V_12 -> V_57 )
F_25 ( V_56 , & V_1 -> V_55 ,
F_26 ( V_1 -> V_12 -> V_57 ) ) ;
}
void F_30 ( struct V_1 * V_1 )
{
F_31 ( & V_1 -> V_55 ) ;
}
void F_32 ( struct V_1 * V_1 )
{
F_24 ( & V_1 -> V_44 ) ;
if ( V_1 -> V_58 ) {
F_27 ( & V_1 -> V_44 ) ;
return;
}
F_16 ( V_1 , V_1 -> V_25 ) ;
V_1 -> V_58 = true ;
F_27 ( & V_1 -> V_44 ) ;
F_31 ( & V_1 -> V_55 ) ;
}
void F_33 ( struct V_1 * V_1 )
{
unsigned long V_10 ;
F_24 ( & V_1 -> V_44 ) ;
if ( ! V_1 -> V_58 )
goto V_26;
if ( ! F_34 ( & V_1 -> V_55 ) &&
V_1 -> V_12 -> V_57 )
F_25 ( V_56 , & V_1 -> V_55 ,
F_26 ( V_1 -> V_12 -> V_57 ) ) ;
V_1 -> V_28 = V_24 ;
V_1 -> V_58 = false ;
if ( V_1 -> V_12 -> V_50 &&
! V_1 -> V_12 -> V_50 ( V_1 -> V_3 . V_8 , & V_10 ) )
V_1 -> V_25 = V_10 ;
V_26:
F_27 ( & V_1 -> V_44 ) ;
}
void F_35 ( struct V_1 * V_1 , unsigned int * V_59 )
{
unsigned int V_60 = V_1 -> V_12 -> V_57 ;
unsigned int V_61 = * V_59 ;
F_24 ( & V_1 -> V_44 ) ;
V_1 -> V_12 -> V_57 = V_61 ;
if ( V_1 -> V_58 )
goto V_26;
if ( ! V_61 ) {
F_27 ( & V_1 -> V_44 ) ;
F_31 ( & V_1 -> V_55 ) ;
return;
}
if ( ! V_60 ) {
F_25 ( V_56 , & V_1 -> V_55 ,
F_26 ( V_1 -> V_12 -> V_57 ) ) ;
goto V_26;
}
if ( V_60 > V_61 ) {
F_27 ( & V_1 -> V_44 ) ;
F_31 ( & V_1 -> V_55 ) ;
F_24 ( & V_1 -> V_44 ) ;
if ( ! V_1 -> V_58 )
F_25 ( V_56 , & V_1 -> V_55 ,
F_26 ( V_1 -> V_12 -> V_57 ) ) ;
}
V_26:
F_27 ( & V_1 -> V_44 ) ;
}
static int F_36 ( struct V_62 * V_63 , unsigned long type ,
void * V_64 )
{
struct V_1 * V_1 = F_23 ( V_63 , struct V_1 , V_63 ) ;
int V_22 ;
F_24 ( & V_1 -> V_44 ) ;
V_22 = F_20 ( V_1 ) ;
F_27 ( & V_1 -> V_44 ) ;
return V_22 ;
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_38 ( V_3 ) ;
F_24 ( & V_7 ) ;
if ( F_13 ( F_1 ( V_1 -> V_3 . V_8 ) ) ) {
F_27 ( & V_7 ) ;
F_39 ( & V_1 -> V_3 , L_6 ) ;
return;
}
F_40 ( & V_1 -> V_65 ) ;
F_27 ( & V_7 ) ;
if ( V_1 -> V_45 )
V_1 -> V_45 -> V_66 ( V_1 ,
V_67 , NULL ) ;
if ( V_1 -> V_12 -> exit )
V_1 -> V_12 -> exit ( V_1 -> V_3 . V_8 ) ;
F_41 ( & V_1 -> V_44 ) ;
F_42 ( V_1 ) ;
}
struct V_1 * F_43 ( struct V_2 * V_3 ,
struct V_15 * V_12 ,
const char * V_68 ,
void * V_69 )
{
struct V_1 * V_1 ;
struct V_31 * V_45 ;
static T_2 V_70 = F_44 ( - 1 ) ;
int V_42 = 0 ;
if ( ! V_3 || ! V_12 || ! V_68 ) {
F_21 ( V_3 , L_7 , V_5 ) ;
return F_4 ( - V_6 ) ;
}
F_24 ( & V_7 ) ;
V_1 = F_1 ( V_3 ) ;
F_27 ( & V_7 ) ;
if ( ! F_13 ( V_1 ) ) {
F_21 ( V_3 , L_8 ,
V_5 ) ;
V_42 = - V_6 ;
goto V_71;
}
V_1 = F_45 ( sizeof( struct V_1 ) , V_20 ) ;
if ( ! V_1 ) {
V_42 = - V_72 ;
goto V_71;
}
F_46 ( & V_1 -> V_44 ) ;
F_24 ( & V_1 -> V_44 ) ;
V_1 -> V_3 . V_8 = V_3 ;
V_1 -> V_3 . V_73 = V_74 ;
V_1 -> V_3 . V_75 = F_37 ;
V_1 -> V_12 = V_12 ;
strncpy ( V_1 -> V_68 , V_68 , V_34 ) ;
V_1 -> V_25 = V_12 -> V_76 ;
V_1 -> V_77 . V_78 = V_12 -> V_76 ;
V_1 -> V_69 = V_69 ;
V_1 -> V_63 . V_79 = F_36 ;
if ( ! V_1 -> V_12 -> V_13 && ! V_1 -> V_12 -> V_14 ) {
F_27 ( & V_1 -> V_44 ) ;
F_9 ( V_1 ) ;
F_24 ( & V_1 -> V_44 ) ;
}
F_47 ( & V_1 -> V_3 , L_9 ,
F_48 ( & V_70 ) ) ;
V_42 = F_49 ( & V_1 -> V_3 ) ;
if ( V_42 ) {
F_27 ( & V_1 -> V_44 ) ;
goto V_80;
}
V_1 -> V_29 = F_50 ( & V_1 -> V_3 ,
sizeof( unsigned int ) *
V_1 -> V_12 -> V_13 *
V_1 -> V_12 -> V_13 ,
V_20 ) ;
V_1 -> V_27 = F_50 ( & V_1 -> V_3 ,
sizeof( unsigned long ) *
V_1 -> V_12 -> V_13 ,
V_20 ) ;
V_1 -> V_28 = V_24 ;
F_51 ( & V_1 -> V_39 ) ;
F_27 ( & V_1 -> V_44 ) ;
F_24 ( & V_7 ) ;
F_52 ( & V_1 -> V_65 , & V_81 ) ;
V_45 = F_17 ( V_1 -> V_68 ) ;
if ( F_13 ( V_45 ) ) {
F_21 ( V_3 , L_10 ,
V_5 ) ;
V_42 = F_53 ( V_45 ) ;
goto V_82;
}
V_1 -> V_45 = V_45 ;
V_42 = V_1 -> V_45 -> V_66 ( V_1 , V_83 ,
NULL ) ;
if ( V_42 ) {
F_21 ( V_3 , L_11 ,
V_5 ) ;
goto V_82;
}
F_27 ( & V_7 ) ;
return V_1 ;
V_82:
F_40 ( & V_1 -> V_65 ) ;
F_27 ( & V_7 ) ;
F_54 ( & V_1 -> V_3 ) ;
V_80:
if ( V_1 )
F_42 ( V_1 ) ;
V_71:
return F_4 ( V_42 ) ;
}
int F_55 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
F_54 ( & V_1 -> V_3 ) ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 , void * V_84 , void * V_69 )
{
struct V_1 * * V_85 = V_84 ;
if ( F_57 ( ! V_85 || ! * V_85 ) )
return 0 ;
return * V_85 == V_69 ;
}
static void F_58 ( struct V_2 * V_3 , void * V_84 )
{
F_55 ( * (struct V_1 * * ) V_84 ) ;
}
struct V_1 * F_59 ( struct V_2 * V_3 ,
struct V_15 * V_12 ,
const char * V_68 ,
void * V_69 )
{
struct V_1 * * V_86 , * V_1 ;
V_86 = F_60 ( F_58 , sizeof( * V_86 ) , V_20 ) ;
if ( ! V_86 )
return F_4 ( - V_72 ) ;
V_1 = F_43 ( V_3 , V_12 , V_68 , V_69 ) ;
if ( F_13 ( V_1 ) ) {
F_61 ( V_86 ) ;
return F_4 ( - V_72 ) ;
}
* V_86 = V_1 ;
F_62 ( V_3 , V_86 ) ;
return V_1 ;
}
struct V_1 * F_63 ( struct V_2 * V_3 , int V_87 )
{
struct V_88 * V_65 ;
struct V_1 * V_1 ;
if ( ! V_3 )
return F_4 ( - V_6 ) ;
if ( ! V_3 -> V_89 )
return F_4 ( - V_6 ) ;
V_65 = F_64 ( V_3 -> V_89 , L_12 , V_87 ) ;
if ( ! V_65 )
return F_4 ( - V_9 ) ;
F_24 ( & V_7 ) ;
F_7 (devfreq, &devfreq_list, node) {
if ( V_1 -> V_3 . V_8
&& V_1 -> V_3 . V_8 -> V_89 == V_65 ) {
F_27 ( & V_7 ) ;
F_65 ( V_65 ) ;
return V_1 ;
}
}
F_27 ( & V_7 ) ;
F_65 ( V_65 ) ;
return F_4 ( - V_90 ) ;
}
struct V_1 * F_63 ( struct V_2 * V_3 , int V_87 )
{
return F_4 ( - V_9 ) ;
}
void F_66 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
F_57 ( F_67 ( V_3 , F_58 ,
F_56 , V_1 ) ) ;
}
int F_68 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_45 )
return 0 ;
return V_1 -> V_45 -> V_66 ( V_1 ,
V_91 , NULL ) ;
}
int F_69 ( struct V_1 * V_1 )
{
if ( ! V_1 )
return - V_6 ;
if ( ! V_1 -> V_45 )
return 0 ;
return V_1 -> V_45 -> V_66 ( V_1 ,
V_92 , NULL ) ;
}
int F_70 ( struct V_31 * V_45 )
{
struct V_31 * V_93 ;
struct V_1 * V_1 ;
int V_42 = 0 ;
if ( ! V_45 ) {
F_3 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_24 ( & V_7 ) ;
V_93 = F_17 ( V_45 -> V_32 ) ;
if ( ! F_13 ( V_93 ) ) {
F_3 ( L_13 , V_5 ,
V_93 -> V_32 ) ;
V_42 = - V_6 ;
goto V_71;
}
F_52 ( & V_45 -> V_65 , & V_94 ) ;
F_7 (devfreq, &devfreq_list, node) {
int V_22 = 0 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_68 , V_45 -> V_32 ,
V_34 ) ) {
if ( V_1 -> V_45 ) {
F_39 ( V_3 ,
L_14 ,
V_5 , V_1 -> V_45 -> V_32 ) ;
V_22 = V_1 -> V_45 -> V_66 ( V_1 ,
V_67 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 ,
L_15 ,
V_5 ,
V_1 -> V_45 -> V_32 , V_22 ) ;
}
}
V_1 -> V_45 = V_45 ;
V_22 = V_1 -> V_45 -> V_66 ( V_1 ,
V_83 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 , L_16 ,
V_5 , V_1 -> V_45 -> V_32 ,
V_22 ) ;
}
}
}
V_71:
F_27 ( & V_7 ) ;
return V_42 ;
}
int F_71 ( struct V_31 * V_45 )
{
struct V_31 * V_93 ;
struct V_1 * V_1 ;
int V_42 = 0 ;
if ( ! V_45 ) {
F_3 ( L_7 , V_5 ) ;
return - V_6 ;
}
F_24 ( & V_7 ) ;
V_93 = F_17 ( V_45 -> V_32 ) ;
if ( F_13 ( V_93 ) ) {
F_3 ( L_17 , V_5 ,
V_45 -> V_32 ) ;
V_42 = F_53 ( V_93 ) ;
goto V_71;
}
F_7 (devfreq, &devfreq_list, node) {
int V_22 ;
struct V_2 * V_3 = V_1 -> V_3 . V_8 ;
if ( ! strncmp ( V_1 -> V_68 , V_45 -> V_32 ,
V_34 ) ) {
if ( ! V_1 -> V_45 ) {
F_39 ( V_3 , L_18 ,
V_5 , V_45 -> V_32 ) ;
continue;
}
V_22 = V_1 -> V_45 -> V_66 ( V_1 ,
V_67 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 , L_19 ,
V_5 , V_1 -> V_45 -> V_32 ,
V_22 ) ;
}
V_1 -> V_45 = NULL ;
}
}
F_40 ( & V_45 -> V_65 ) ;
V_71:
F_27 ( & V_7 ) ;
return V_42 ;
}
static T_3 F_72 ( struct V_2 * V_3 ,
struct V_95 * V_96 , char * V_97 )
{
if ( ! F_38 ( V_3 ) -> V_45 )
return - V_6 ;
return sprintf ( V_97 , L_20 , F_38 ( V_3 ) -> V_45 -> V_32 ) ;
}
static T_3 F_73 ( struct V_2 * V_3 , struct V_95 * V_96 ,
const char * V_97 , T_4 V_19 )
{
struct V_1 * V_98 = F_38 ( V_3 ) ;
int V_22 ;
char V_99 [ V_34 + 1 ] ;
struct V_31 * V_45 ;
V_22 = sscanf ( V_97 , L_21 F_74 ( V_34 ) L_22 , V_99 ) ;
if ( V_22 != 1 )
return - V_6 ;
F_24 ( & V_7 ) ;
V_45 = F_17 ( V_99 ) ;
if ( F_13 ( V_45 ) ) {
V_22 = F_53 ( V_45 ) ;
goto V_26;
}
if ( V_98 -> V_45 == V_45 ) {
V_22 = 0 ;
goto V_26;
} else if ( V_98 -> V_45 -> V_100 || V_45 -> V_100 ) {
V_22 = - V_6 ;
goto V_26;
}
if ( V_98 -> V_45 ) {
V_22 = V_98 -> V_45 -> V_66 ( V_98 , V_67 , NULL ) ;
if ( V_22 ) {
F_39 ( V_3 , L_23 ,
V_5 , V_98 -> V_45 -> V_32 , V_22 ) ;
goto V_26;
}
}
V_98 -> V_45 = V_45 ;
strncpy ( V_98 -> V_68 , V_45 -> V_32 , V_34 ) ;
V_22 = V_98 -> V_45 -> V_66 ( V_98 , V_83 , NULL ) ;
if ( V_22 )
F_39 ( V_3 , L_24 ,
V_5 , V_98 -> V_45 -> V_32 , V_22 ) ;
V_26:
F_27 ( & V_7 ) ;
if ( ! V_22 )
V_22 = V_19 ;
return V_22 ;
}
static T_3 F_75 ( struct V_2 * V_101 ,
struct V_95 * V_96 ,
char * V_97 )
{
struct V_1 * V_98 = F_38 ( V_101 ) ;
T_3 V_19 = 0 ;
F_24 ( & V_7 ) ;
if ( V_98 -> V_45 -> V_100 ) {
V_19 = F_76 ( & V_97 [ V_19 ] , V_34 ,
L_25 , V_98 -> V_68 ) ;
} else {
struct V_31 * V_45 ;
F_7 (governor, &devfreq_governor_list, node) {
if ( V_45 -> V_100 )
continue;
V_19 += F_76 ( & V_97 [ V_19 ] , ( V_102 - V_19 - 2 ) ,
L_25 , V_45 -> V_32 ) ;
}
}
F_27 ( & V_7 ) ;
if ( V_19 )
V_19 -- ;
V_19 += sprintf ( & V_97 [ V_19 ] , L_26 ) ;
return V_19 ;
}
static T_3 F_77 ( struct V_2 * V_3 , struct V_95 * V_96 ,
char * V_97 )
{
unsigned long V_10 ;
struct V_1 * V_1 = F_38 ( V_3 ) ;
if ( V_1 -> V_12 -> V_50 &&
! V_1 -> V_12 -> V_50 ( V_1 -> V_3 . V_8 , & V_10 ) )
return sprintf ( V_97 , L_27 , V_10 ) ;
return sprintf ( V_97 , L_27 , V_1 -> V_25 ) ;
}
static T_3 F_78 ( struct V_2 * V_3 ,
struct V_95 * V_96 , char * V_97 )
{
return sprintf ( V_97 , L_27 , F_38 ( V_3 ) -> V_25 ) ;
}
static T_3 F_79 ( struct V_2 * V_3 ,
struct V_95 * V_96 , char * V_97 )
{
return sprintf ( V_97 , L_28 , F_38 ( V_3 ) -> V_12 -> V_57 ) ;
}
static T_3 F_80 ( struct V_2 * V_3 ,
struct V_95 * V_96 ,
const char * V_97 , T_4 V_19 )
{
struct V_1 * V_98 = F_38 ( V_3 ) ;
unsigned int V_103 ;
int V_22 ;
if ( ! V_98 -> V_45 )
return - V_6 ;
V_22 = sscanf ( V_97 , L_29 , & V_103 ) ;
if ( V_22 != 1 )
return - V_6 ;
V_98 -> V_45 -> V_66 ( V_98 , V_104 , & V_103 ) ;
V_22 = V_19 ;
return V_22 ;
}
static T_3 F_81 ( struct V_2 * V_3 , struct V_95 * V_96 ,
const char * V_97 , T_4 V_19 )
{
struct V_1 * V_98 = F_38 ( V_3 ) ;
unsigned long V_103 ;
int V_22 ;
unsigned long V_105 ;
V_22 = sscanf ( V_97 , L_30 , & V_103 ) ;
if ( V_22 != 1 )
return - V_6 ;
F_24 ( & V_98 -> V_44 ) ;
V_105 = V_98 -> V_49 ;
if ( V_103 && V_105 && V_103 > V_105 ) {
V_22 = - V_6 ;
goto V_106;
}
V_98 -> V_47 = V_103 ;
F_20 ( V_98 ) ;
V_22 = V_19 ;
V_106:
F_27 ( & V_98 -> V_44 ) ;
return V_22 ;
}
static T_3 F_82 ( struct V_2 * V_3 , struct V_95 * V_96 ,
const char * V_97 , T_4 V_19 )
{
struct V_1 * V_98 = F_38 ( V_3 ) ;
unsigned long V_103 ;
int V_22 ;
unsigned long V_107 ;
V_22 = sscanf ( V_97 , L_30 , & V_103 ) ;
if ( V_22 != 1 )
return - V_6 ;
F_24 ( & V_98 -> V_44 ) ;
V_107 = V_98 -> V_47 ;
if ( V_103 && V_107 && V_103 < V_107 ) {
V_22 = - V_6 ;
goto V_106;
}
V_98 -> V_49 = V_103 ;
F_20 ( V_98 ) ;
V_22 = V_19 ;
V_106:
F_27 ( & V_98 -> V_44 ) ;
return V_22 ;
}
static T_3 F_83 ( struct V_2 * V_101 ,
struct V_95 * V_96 ,
char * V_97 )
{
struct V_1 * V_98 = F_38 ( V_101 ) ;
struct V_2 * V_3 = V_98 -> V_3 . V_8 ;
struct V_16 * V_17 ;
T_3 V_19 = 0 ;
unsigned long V_10 = 0 ;
do {
V_17 = F_12 ( V_3 , & V_10 ) ;
if ( F_13 ( V_17 ) )
break;
F_15 ( V_17 ) ;
V_19 += F_76 ( & V_97 [ V_19 ] , ( V_102 - V_19 - 2 ) ,
L_31 , V_10 ) ;
V_10 ++ ;
} while ( 1 );
if ( V_19 )
V_19 -- ;
V_19 += sprintf ( & V_97 [ V_19 ] , L_26 ) ;
return V_19 ;
}
static T_3 F_84 ( struct V_2 * V_3 ,
struct V_95 * V_96 , char * V_97 )
{
struct V_1 * V_1 = F_38 ( V_3 ) ;
T_3 V_108 ;
int V_18 , V_109 ;
unsigned int V_13 = V_1 -> V_12 -> V_13 ;
if ( ! V_1 -> V_58 &&
F_16 ( V_1 , V_1 -> V_25 ) )
return 0 ;
if ( V_13 == 0 )
return sprintf ( V_97 , L_32 ) ;
V_108 = sprintf ( V_97 , L_33 ) ;
V_108 += sprintf ( V_97 + V_108 , L_34 ) ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ )
V_108 += sprintf ( V_97 + V_108 , L_35 ,
V_1 -> V_12 -> V_14 [ V_18 ] ) ;
V_108 += sprintf ( V_97 + V_108 , L_36 ) ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ ) {
if ( V_1 -> V_12 -> V_14 [ V_18 ]
== V_1 -> V_25 ) {
V_108 += sprintf ( V_97 + V_108 , L_37 ) ;
} else {
V_108 += sprintf ( V_97 + V_108 , L_38 ) ;
}
V_108 += sprintf ( V_97 + V_108 , L_39 ,
V_1 -> V_12 -> V_14 [ V_18 ] ) ;
for ( V_109 = 0 ; V_109 < V_13 ; V_109 ++ )
V_108 += sprintf ( V_97 + V_108 , L_40 ,
V_1 -> V_29 [ ( V_18 * V_13 ) + V_109 ] ) ;
V_108 += sprintf ( V_97 + V_108 , L_41 ,
F_85 ( V_1 -> V_27 [ V_18 ] ) ) ;
}
V_108 += sprintf ( V_97 + V_108 , L_42 ,
V_1 -> V_30 ) ;
return V_108 ;
}
static int T_5 F_86 ( void )
{
V_74 = F_87 ( V_110 , L_12 ) ;
if ( F_13 ( V_74 ) ) {
F_3 ( L_43 , __FILE__ ) ;
return F_53 ( V_74 ) ;
}
V_56 = F_88 ( L_44 ) ;
if ( ! V_56 ) {
F_89 ( V_74 ) ;
F_3 ( L_45 , __FILE__ ) ;
return - V_72 ;
}
V_74 -> V_111 = V_112 ;
return 0 ;
}
struct V_16 * F_90 ( struct V_2 * V_3 ,
unsigned long * V_10 ,
T_1 V_43 )
{
struct V_16 * V_17 ;
if ( V_43 & V_48 ) {
V_17 = F_91 ( V_3 , V_10 ) ;
if ( V_17 == F_4 ( - V_113 ) )
V_17 = F_12 ( V_3 , V_10 ) ;
} else {
V_17 = F_12 ( V_3 , V_10 ) ;
if ( V_17 == F_4 ( - V_113 ) )
V_17 = F_91 ( V_3 , V_10 ) ;
}
return V_17 ;
}
int F_92 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
return F_93 ( V_3 , & V_1 -> V_63 ) ;
}
int F_94 ( struct V_2 * V_3 , struct V_1 * V_1 )
{
return F_95 ( V_3 , & V_1 -> V_63 ) ;
}
static void F_96 ( struct V_2 * V_3 , void * V_84 )
{
F_94 ( V_3 , * (struct V_1 * * ) V_84 ) ;
}
int F_97 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
struct V_1 * * V_86 ;
int V_22 ;
V_86 = F_60 ( F_96 , sizeof( * V_86 ) , V_20 ) ;
if ( ! V_86 )
return - V_72 ;
V_22 = F_92 ( V_3 , V_1 ) ;
if ( V_22 ) {
F_61 ( V_86 ) ;
return V_22 ;
}
* V_86 = V_1 ;
F_62 ( V_3 , V_86 ) ;
return 0 ;
}
void F_98 ( struct V_2 * V_3 ,
struct V_1 * V_1 )
{
F_57 ( F_67 ( V_3 , F_96 ,
F_56 , V_1 ) ) ;
}
int F_99 ( struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_114 )
{
int V_22 = 0 ;
if ( ! V_1 )
return - V_6 ;
switch ( V_114 ) {
case V_115 :
V_22 = F_100 (
& V_1 -> V_39 , V_63 ) ;
break;
default:
V_22 = - V_6 ;
}
return V_22 ;
}
int F_101 ( struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_114 )
{
int V_22 = 0 ;
if ( ! V_1 )
return - V_6 ;
switch ( V_114 ) {
case V_115 :
V_22 = F_102 (
& V_1 -> V_39 , V_63 ) ;
break;
default:
V_22 = - V_6 ;
}
return V_22 ;
}
static void F_103 ( struct V_2 * V_3 , void * V_84 )
{
struct V_116 * V_117 = V_84 ;
F_101 ( V_117 -> V_1 , V_117 -> V_63 , V_117 -> V_114 ) ;
}
int F_104 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_114 )
{
struct V_116 * V_86 ;
int V_22 ;
V_86 = F_60 ( F_103 , sizeof( * V_86 ) ,
V_20 ) ;
if ( ! V_86 )
return - V_72 ;
V_22 = F_99 ( V_1 , V_63 , V_114 ) ;
if ( V_22 ) {
F_61 ( V_86 ) ;
return V_22 ;
}
V_86 -> V_1 = V_1 ;
V_86 -> V_63 = V_63 ;
V_86 -> V_114 = V_114 ;
F_62 ( V_3 , V_86 ) ;
return 0 ;
}
void F_105 ( struct V_2 * V_3 ,
struct V_1 * V_1 ,
struct V_62 * V_63 ,
unsigned int V_114 )
{
F_57 ( F_67 ( V_3 , F_103 ,
F_56 , V_1 ) ) ;
}
