struct V_1 F_1 ( T_1 V_2 ,
struct V_3 V_4 ,
void * V_5 )
{
return F_2 ( V_2 , V_4 , V_5 ) ;
}
static int F_3 ( struct V_6 * V_7 , void * V_5 )
{
struct V_1 V_8 ;
struct V_3 V_4 = { 0 } ;
V_4 . V_9 = 1 ;
V_4 . V_10 = V_11 ;
V_8 = F_2 ( V_7 -> V_2 , V_4 , V_5 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
case V_14 :
return 0 ;
case V_15 :
case V_16 :
case V_17 :
case V_18 :
F_4 ( L_1 ,
F_5 ( V_7 -> V_2 ) ,
F_6 ( V_7 -> V_2 ) ) ;
return - V_19 ;
case V_20 :
case V_21 :
default:
return - V_22 ;
}
}
static inline struct V_1
F_7 ( T_1 V_2 , unsigned long long V_23 , void * V_24 , T_2 V_25 ,
unsigned int V_26 )
{
if ( V_26 == 1 )
V_2 |= 0x400000UL ;
return F_8 ( V_2 , V_23 , V_24 , V_25 ) ;
}
int F_9 ( T_1 V_2 , unsigned long long V_23 , void * V_24 , T_2 V_25 )
{
struct V_1 V_8 ;
V_8 = F_7 ( V_2 , V_23 , V_24 , V_25 , 0 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
return 0 ;
case V_27 :
case V_20 :
return - V_22 ;
case V_28 :
return - V_29 ;
default:
return - V_30 ;
}
}
int F_10 ( T_1 V_2 , unsigned long long * V_23 , void * V_24 , T_2 V_25 )
{
struct V_1 V_8 ;
if ( V_24 == NULL )
return - V_29 ;
V_8 = F_11 ( V_2 , V_23 , V_24 , V_25 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
return 0 ;
case V_31 :
if ( V_8 . V_32 )
return - V_33 ;
return - V_22 ;
case V_20 :
return - V_22 ;
default:
return - V_30 ;
}
}
static enum V_34 F_12 ( struct V_6 * V_7 )
{
return V_35 ;
}
static struct V_1 F_13 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
struct V_36 * V_37 ;
V_8 = F_11 ( V_7 -> V_2 , & V_7 -> V_38 -> V_23 ,
V_7 -> V_38 -> V_39 , V_7 -> V_38 -> V_25 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
V_7 -> V_40 -- ;
if ( V_7 -> V_40 > 0 )
F_14 ( & V_7 -> V_41 ,
V_42 + V_7 -> V_43 ) ;
F_15 (ap_msg, &aq->pendingq, list) {
if ( V_37 -> V_23 != V_7 -> V_38 -> V_23 )
continue;
F_16 ( & V_37 -> V_44 ) ;
V_7 -> V_45 -- ;
V_37 -> V_46 ( V_7 , V_37 , V_7 -> V_38 ) ;
break;
}
case V_31 :
if ( ! V_8 . V_32 || V_7 -> V_40 <= 0 )
break;
V_7 -> V_40 = 0 ;
F_17 ( & V_7 -> V_47 , & V_7 -> V_48 ) ;
V_7 -> V_49 += V_7 -> V_45 ;
V_7 -> V_45 = 0 ;
break;
default:
break;
}
return V_8 ;
}
static enum V_34 F_18 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
if ( ! V_7 -> V_38 )
return V_35 ;
V_8 = F_13 ( V_7 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
if ( V_7 -> V_40 > 0 ) {
V_7 -> V_50 = V_51 ;
return V_52 ;
}
V_7 -> V_50 = V_53 ;
return V_35 ;
case V_31 :
if ( V_7 -> V_40 > 0 )
return V_54 ;
V_7 -> V_50 = V_53 ;
return V_35 ;
default:
V_7 -> V_50 = V_55 ;
return V_35 ;
}
}
static enum V_34 F_19 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
if ( ! V_7 -> V_38 )
return V_35 ;
V_8 = F_13 ( V_7 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
if ( V_7 -> V_40 > 0 )
return V_52 ;
default:
return V_35 ;
}
}
static enum V_34 F_20 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
struct V_36 * V_37 ;
if ( V_7 -> V_49 <= 0 )
return V_35 ;
V_37 = F_21 ( V_7 -> V_48 . V_56 , struct V_36 , V_44 ) ;
V_8 = F_7 ( V_7 -> V_2 , V_37 -> V_23 ,
V_37 -> V_39 , V_37 -> V_25 , V_37 -> V_26 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
V_7 -> V_40 ++ ;
if ( V_7 -> V_40 == 1 )
F_14 ( & V_7 -> V_41 , V_42 + V_7 -> V_43 ) ;
F_22 ( & V_37 -> V_44 , & V_7 -> V_47 ) ;
V_7 -> V_49 -- ;
V_7 -> V_45 ++ ;
if ( V_7 -> V_40 < V_7 -> V_57 -> V_58 ) {
V_7 -> V_50 = V_51 ;
return V_52 ;
}
case V_27 :
V_7 -> V_50 = V_59 ;
return V_54 ;
case V_20 :
V_7 -> V_50 = V_60 ;
return V_61 ;
case V_62 :
case V_28 :
F_16 ( & V_37 -> V_44 ) ;
V_7 -> V_49 -- ;
V_37 -> V_63 = - V_29 ;
V_37 -> V_46 ( V_7 , V_37 , NULL ) ;
return V_52 ;
default:
V_7 -> V_50 = V_55 ;
return V_35 ;
}
}
static enum V_34 F_23 ( struct V_6 * V_7 )
{
return F_24 ( F_18 ( V_7 ) , F_20 ( V_7 ) ) ;
}
static enum V_34 F_25 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
V_8 = F_26 ( V_7 -> V_2 ) ;
switch ( V_8 . V_12 ) {
case V_13 :
case V_20 :
V_7 -> V_50 = V_60 ;
V_7 -> V_64 = V_65 ;
return V_61 ;
case V_21 :
return V_61 ;
case V_15 :
case V_16 :
case V_17 :
default:
V_7 -> V_50 = V_55 ;
return V_35 ;
}
}
static enum V_34 F_27 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
void * V_66 ;
if ( V_7 -> V_40 > 0 && V_7 -> V_38 )
V_8 = F_13 ( V_7 ) ;
else
V_8 = F_28 ( V_7 -> V_2 , NULL ) ;
switch ( V_8 . V_12 ) {
case V_13 :
V_66 = F_29 () ;
if ( V_66 && F_3 ( V_7 , V_66 ) == 0 )
V_7 -> V_50 = V_67 ;
else
V_7 -> V_50 = ( V_7 -> V_40 > 0 ) ?
V_51 : V_53 ;
return V_52 ;
case V_21 :
case V_20 :
return V_61 ;
case V_15 :
case V_16 :
case V_17 :
default:
V_7 -> V_50 = V_55 ;
return V_35 ;
}
}
static enum V_34 F_30 ( struct V_6 * V_7 )
{
struct V_1 V_8 ;
if ( V_7 -> V_40 > 0 && V_7 -> V_38 )
V_8 = F_13 ( V_7 ) ;
else
V_8 = F_28 ( V_7 -> V_2 , NULL ) ;
if ( V_8 . V_68 == 1 ) {
V_7 -> V_64 = V_69 ;
V_7 -> V_50 = ( V_7 -> V_40 > 0 ) ?
V_51 : V_53 ;
}
switch ( V_8 . V_12 ) {
case V_13 :
if ( V_7 -> V_40 > 0 )
return V_52 ;
case V_31 :
return V_61 ;
default:
V_7 -> V_50 = V_55 ;
return V_35 ;
}
}
enum V_34 F_31 ( struct V_6 * V_7 , enum V_70 V_71 )
{
return V_72 [ V_7 -> V_50 ] [ V_71 ] ( V_7 ) ;
}
enum V_34 F_32 ( struct V_6 * V_7 , enum V_70 V_71 )
{
enum V_34 V_73 ;
while ( ( V_73 = F_31 ( V_7 , V_71 ) ) == V_52 )
;
return V_73 ;
}
void F_33 ( struct V_74 * V_75 )
{
struct V_6 * V_7 = F_34 ( & V_75 -> V_76 ) ;
F_35 ( & V_7 -> V_77 ) ;
V_7 -> V_50 = V_78 ;
while ( F_31 ( V_7 , V_79 ) != V_35 )
;
V_7 -> V_50 = V_55 ;
F_36 ( & V_7 -> V_77 ) ;
}
void F_37 ( struct V_74 * V_75 )
{
}
static T_3 F_38 ( struct V_76 * V_80 ,
struct V_81 * V_82 ,
char * V_83 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
unsigned int V_84 ;
F_35 ( & V_7 -> V_77 ) ;
V_84 = V_7 -> V_85 ;
F_36 ( & V_7 -> V_77 ) ;
return snprintf ( V_83 , V_86 , L_2 , V_84 ) ;
}
static T_3 F_39 ( struct V_76 * V_80 ,
struct V_81 * V_82 ,
const char * V_83 , T_2 V_87 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
F_35 ( & V_7 -> V_77 ) ;
V_7 -> V_85 = 0 ;
F_36 ( & V_7 -> V_77 ) ;
return V_87 ;
}
static T_3 F_40 ( struct V_76 * V_80 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
unsigned int V_88 = 0 ;
F_35 ( & V_7 -> V_77 ) ;
V_88 = V_7 -> V_49 ;
F_36 ( & V_7 -> V_77 ) ;
return snprintf ( V_83 , V_86 , L_2 , V_88 ) ;
}
static T_3 F_41 ( struct V_76 * V_80 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
unsigned int V_89 = 0 ;
F_35 ( & V_7 -> V_77 ) ;
V_89 = V_7 -> V_45 ;
F_36 ( & V_7 -> V_77 ) ;
return snprintf ( V_83 , V_86 , L_2 , V_89 ) ;
}
static T_3 F_42 ( struct V_76 * V_80 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
int V_63 = 0 ;
F_35 ( & V_7 -> V_77 ) ;
switch ( V_7 -> V_50 ) {
case V_90 :
case V_60 :
V_63 = snprintf ( V_83 , V_86 , L_3 ) ;
break;
case V_51 :
case V_59 :
V_63 = snprintf ( V_83 , V_86 , L_4 ) ;
break;
default:
V_63 = snprintf ( V_83 , V_86 , L_5 ) ;
}
F_36 ( & V_7 -> V_77 ) ;
return V_63 ;
}
static T_3 F_43 ( struct V_76 * V_80 ,
struct V_81 * V_82 , char * V_83 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
int V_63 = 0 ;
F_35 ( & V_7 -> V_77 ) ;
if ( V_7 -> V_50 == V_67 )
V_63 = snprintf ( V_83 , V_86 , L_6 ) ;
else if ( V_7 -> V_64 == V_69 )
V_63 = snprintf ( V_83 , V_86 , L_7 ) ;
else
V_63 = snprintf ( V_83 , V_86 , L_8 ) ;
F_36 ( & V_7 -> V_77 ) ;
return V_63 ;
}
static void F_44 ( struct V_76 * V_80 )
{
struct V_6 * V_7 = F_34 ( V_80 ) ;
if ( ! F_45 ( & V_7 -> V_44 ) ) {
F_35 ( & V_91 ) ;
F_16 ( & V_7 -> V_44 ) ;
F_36 ( & V_91 ) ;
}
F_46 ( V_7 ) ;
}
struct V_6 * F_47 ( T_1 V_2 , int V_92 )
{
struct V_6 * V_7 ;
V_7 = F_48 ( sizeof( * V_7 ) , V_93 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_75 . V_76 . V_94 = F_44 ;
V_7 -> V_75 . V_76 . type = & V_95 ;
V_7 -> V_75 . V_92 = V_92 ;
if ( V_92 == V_96 )
V_7 -> V_75 . V_92 = V_97 ;
V_7 -> V_2 = V_2 ;
V_7 -> V_50 = V_90 ;
V_7 -> V_64 = V_65 ;
F_49 ( & V_7 -> V_77 ) ;
F_50 ( & V_7 -> V_47 ) ;
F_50 ( & V_7 -> V_48 ) ;
F_51 ( & V_7 -> V_41 , V_98 , ( unsigned long ) V_7 ) ;
return V_7 ;
}
void F_52 ( struct V_6 * V_7 , struct V_36 * V_38 )
{
V_7 -> V_38 = V_38 ;
F_35 ( & V_7 -> V_77 ) ;
V_34 ( F_31 ( V_7 , V_79 ) ) ;
F_36 ( & V_7 -> V_77 ) ;
}
void F_53 ( struct V_6 * V_7 , struct V_36 * V_37 )
{
F_54 ( ! V_37 -> V_46 ) ;
F_35 ( & V_7 -> V_77 ) ;
F_55 ( & V_37 -> V_44 , & V_7 -> V_48 ) ;
V_7 -> V_49 ++ ;
V_7 -> V_85 ++ ;
F_56 ( & V_7 -> V_57 -> V_85 ) ;
V_34 ( F_32 ( V_7 , V_79 ) ) ;
F_36 ( & V_7 -> V_77 ) ;
}
void F_57 ( struct V_6 * V_7 , struct V_36 * V_37 )
{
struct V_36 * V_99 ;
F_35 ( & V_7 -> V_77 ) ;
if ( ! F_45 ( & V_37 -> V_44 ) ) {
F_15 (tmp, &aq->pendingq, list)
if ( V_99 -> V_23 == V_37 -> V_23 ) {
V_7 -> V_45 -- ;
goto V_100;
}
V_7 -> V_49 -- ;
V_100:
F_16 ( & V_37 -> V_44 ) ;
}
F_36 ( & V_7 -> V_77 ) ;
}
static void F_58 ( struct V_6 * V_7 )
{
struct V_36 * V_37 , * V_56 ;
F_59 (ap_msg, next, &aq->pendingq, list) {
F_16 ( & V_37 -> V_44 ) ;
V_7 -> V_45 -- ;
V_37 -> V_63 = - V_101 ;
V_37 -> V_46 ( V_7 , V_37 , NULL ) ;
}
F_59 (ap_msg, next, &aq->requestq, list) {
F_16 ( & V_37 -> V_44 ) ;
V_7 -> V_49 -- ;
V_37 -> V_63 = - V_101 ;
V_37 -> V_46 ( V_7 , V_37 , NULL ) ;
}
}
void F_60 ( struct V_6 * V_7 )
{
F_35 ( & V_7 -> V_77 ) ;
F_58 ( V_7 ) ;
F_36 ( & V_7 -> V_77 ) ;
}
void F_61 ( struct V_6 * V_7 )
{
F_60 ( V_7 ) ;
F_62 ( & V_7 -> V_41 ) ;
}
