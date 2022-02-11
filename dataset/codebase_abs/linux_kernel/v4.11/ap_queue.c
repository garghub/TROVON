static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 V_5 ;
V_5 = F_2 ( V_2 -> V_6 , V_3 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
case V_9 :
return 0 ;
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_3 ( L_1 ,
F_4 ( V_2 -> V_6 ) ,
F_5 ( V_2 -> V_6 ) ) ;
return - V_14 ;
case V_15 :
case V_16 :
default:
return - V_17 ;
}
}
static inline struct V_4
F_6 ( T_1 V_6 , unsigned long long V_18 , void * V_19 , T_2 V_20 ,
unsigned int V_21 )
{
if ( V_21 == 1 )
V_6 |= 0x400000UL ;
return F_7 ( V_6 , V_18 , V_19 , V_20 ) ;
}
int F_8 ( T_1 V_6 , unsigned long long V_18 , void * V_19 , T_2 V_20 )
{
struct V_4 V_5 ;
V_5 = F_6 ( V_6 , V_18 , V_19 , V_20 , 0 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
return 0 ;
case V_22 :
case V_15 :
return - V_17 ;
case V_23 :
return - V_24 ;
default:
return - V_25 ;
}
}
int F_9 ( T_1 V_6 , unsigned long long * V_18 , void * V_19 , T_2 V_20 )
{
struct V_4 V_5 ;
if ( V_19 == NULL )
return - V_24 ;
V_5 = F_10 ( V_6 , V_18 , V_19 , V_20 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
return 0 ;
case V_26 :
if ( V_5 . V_27 )
return - V_28 ;
return - V_17 ;
case V_15 :
return - V_17 ;
default:
return - V_25 ;
}
}
static enum V_29 F_11 ( struct V_1 * V_2 )
{
return V_30 ;
}
static struct V_4 F_12 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
struct V_31 * V_32 ;
V_5 = F_10 ( V_2 -> V_6 , & V_2 -> V_33 -> V_18 ,
V_2 -> V_33 -> V_34 , V_2 -> V_33 -> V_20 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
V_2 -> V_35 -- ;
if ( V_2 -> V_35 > 0 )
F_13 ( & V_2 -> V_36 ,
V_37 + V_2 -> V_38 ) ;
F_14 (ap_msg, &aq->pendingq, list) {
if ( V_32 -> V_18 != V_2 -> V_33 -> V_18 )
continue;
F_15 ( & V_32 -> V_39 ) ;
V_2 -> V_40 -- ;
V_32 -> V_41 ( V_2 , V_32 , V_2 -> V_33 ) ;
break;
}
case V_26 :
if ( ! V_5 . V_27 || V_2 -> V_35 <= 0 )
break;
V_2 -> V_35 = 0 ;
F_16 ( & V_2 -> V_42 , & V_2 -> V_43 ) ;
V_2 -> V_44 += V_2 -> V_40 ;
V_2 -> V_40 = 0 ;
break;
default:
break;
}
return V_5 ;
}
static enum V_29 F_17 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
if ( ! V_2 -> V_33 )
return V_30 ;
V_5 = F_12 ( V_2 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
if ( V_2 -> V_35 > 0 ) {
V_2 -> V_45 = V_46 ;
return V_47 ;
}
V_2 -> V_45 = V_48 ;
return V_30 ;
case V_26 :
if ( V_2 -> V_35 > 0 )
return V_49 ;
V_2 -> V_45 = V_48 ;
return V_30 ;
default:
V_2 -> V_45 = V_50 ;
return V_30 ;
}
}
static enum V_29 F_18 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
if ( ! V_2 -> V_33 )
return V_30 ;
V_5 = F_12 ( V_2 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
if ( V_2 -> V_35 > 0 )
return V_47 ;
default:
return V_30 ;
}
}
static enum V_29 F_19 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
struct V_31 * V_32 ;
if ( V_2 -> V_44 <= 0 )
return V_30 ;
V_32 = F_20 ( V_2 -> V_43 . V_51 , struct V_31 , V_39 ) ;
V_5 = F_6 ( V_2 -> V_6 , V_32 -> V_18 ,
V_32 -> V_34 , V_32 -> V_20 , V_32 -> V_21 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
V_2 -> V_35 ++ ;
if ( V_2 -> V_35 == 1 )
F_13 ( & V_2 -> V_36 , V_37 + V_2 -> V_38 ) ;
F_21 ( & V_32 -> V_39 , & V_2 -> V_42 ) ;
V_2 -> V_44 -- ;
V_2 -> V_40 ++ ;
if ( V_2 -> V_35 < V_2 -> V_52 -> V_53 ) {
V_2 -> V_45 = V_46 ;
return V_47 ;
}
case V_22 :
V_2 -> V_45 = V_54 ;
return V_49 ;
case V_15 :
V_2 -> V_45 = V_55 ;
return V_56 ;
case V_57 :
case V_23 :
F_15 ( & V_32 -> V_39 ) ;
V_2 -> V_44 -- ;
V_32 -> V_58 = - V_24 ;
V_32 -> V_41 ( V_2 , V_32 , NULL ) ;
return V_47 ;
default:
V_2 -> V_45 = V_50 ;
return V_30 ;
}
}
static enum V_29 F_22 ( struct V_1 * V_2 )
{
return F_23 ( F_17 ( V_2 ) , F_19 ( V_2 ) ) ;
}
static enum V_29 F_24 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
V_5 = F_25 ( V_2 -> V_6 ) ;
switch ( V_5 . V_7 ) {
case V_8 :
case V_15 :
V_2 -> V_45 = V_55 ;
V_2 -> V_59 = V_60 ;
return V_56 ;
case V_16 :
return V_56 ;
case V_10 :
case V_11 :
case V_12 :
default:
V_2 -> V_45 = V_50 ;
return V_30 ;
}
}
static enum V_29 F_26 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
void * V_61 ;
if ( V_2 -> V_35 > 0 && V_2 -> V_33 )
V_5 = F_12 ( V_2 ) ;
else
V_5 = F_27 ( V_2 -> V_6 , NULL ) ;
switch ( V_5 . V_7 ) {
case V_8 :
V_61 = F_28 () ;
if ( V_61 && F_1 ( V_2 , V_61 ) == 0 )
V_2 -> V_45 = V_62 ;
else
V_2 -> V_45 = ( V_2 -> V_35 > 0 ) ?
V_46 : V_48 ;
return V_47 ;
case V_16 :
case V_15 :
return V_56 ;
case V_10 :
case V_11 :
case V_12 :
default:
V_2 -> V_45 = V_50 ;
return V_30 ;
}
}
static enum V_29 F_29 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
if ( V_2 -> V_35 > 0 && V_2 -> V_33 )
V_5 = F_12 ( V_2 ) ;
else
V_5 = F_27 ( V_2 -> V_6 , NULL ) ;
if ( V_5 . V_63 == 1 ) {
V_2 -> V_59 = V_64 ;
V_2 -> V_45 = ( V_2 -> V_35 > 0 ) ?
V_46 : V_48 ;
}
switch ( V_5 . V_7 ) {
case V_8 :
if ( V_2 -> V_35 > 0 )
return V_47 ;
case V_26 :
return V_56 ;
default:
V_2 -> V_45 = V_50 ;
return V_30 ;
}
}
enum V_29 F_30 ( struct V_1 * V_2 , enum V_65 V_66 )
{
return V_67 [ V_2 -> V_45 ] [ V_66 ] ( V_2 ) ;
}
enum V_29 F_31 ( struct V_1 * V_2 , enum V_65 V_66 )
{
enum V_29 V_68 ;
while ( ( V_68 = F_30 ( V_2 , V_66 ) ) == V_47 )
;
return V_68 ;
}
void F_32 ( struct V_69 * V_70 )
{
struct V_1 * V_2 = F_33 ( & V_70 -> V_71 ) ;
F_34 ( & V_2 -> V_72 ) ;
V_2 -> V_45 = V_73 ;
while ( F_30 ( V_2 , V_74 ) != V_30 )
;
V_2 -> V_45 = V_50 ;
F_35 ( & V_2 -> V_72 ) ;
}
void F_36 ( struct V_69 * V_70 )
{
}
static T_3 F_37 ( struct V_71 * V_75 ,
struct V_76 * V_77 ,
char * V_78 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
unsigned int V_79 ;
F_34 ( & V_2 -> V_72 ) ;
V_79 = V_2 -> V_80 ;
F_35 ( & V_2 -> V_72 ) ;
return snprintf ( V_78 , V_81 , L_2 , V_79 ) ;
}
static T_3 F_38 ( struct V_71 * V_75 ,
struct V_76 * V_77 ,
const char * V_78 , T_2 V_82 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
F_34 ( & V_2 -> V_72 ) ;
V_2 -> V_80 = 0 ;
F_35 ( & V_2 -> V_72 ) ;
return V_82 ;
}
static T_3 F_39 ( struct V_71 * V_75 ,
struct V_76 * V_77 , char * V_78 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
unsigned int V_83 = 0 ;
F_34 ( & V_2 -> V_72 ) ;
V_83 = V_2 -> V_44 ;
F_35 ( & V_2 -> V_72 ) ;
return snprintf ( V_78 , V_81 , L_2 , V_83 ) ;
}
static T_3 F_40 ( struct V_71 * V_75 ,
struct V_76 * V_77 , char * V_78 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
unsigned int V_84 = 0 ;
F_34 ( & V_2 -> V_72 ) ;
V_84 = V_2 -> V_40 ;
F_35 ( & V_2 -> V_72 ) ;
return snprintf ( V_78 , V_81 , L_2 , V_84 ) ;
}
static T_3 F_41 ( struct V_71 * V_75 ,
struct V_76 * V_77 , char * V_78 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
int V_58 = 0 ;
F_34 ( & V_2 -> V_72 ) ;
switch ( V_2 -> V_45 ) {
case V_85 :
case V_55 :
V_58 = snprintf ( V_78 , V_81 , L_3 ) ;
break;
case V_46 :
case V_54 :
V_58 = snprintf ( V_78 , V_81 , L_4 ) ;
break;
default:
V_58 = snprintf ( V_78 , V_81 , L_5 ) ;
}
F_35 ( & V_2 -> V_72 ) ;
return V_58 ;
}
static T_3 F_42 ( struct V_71 * V_75 ,
struct V_76 * V_77 , char * V_78 )
{
struct V_1 * V_2 = F_33 ( V_75 ) ;
int V_58 = 0 ;
F_34 ( & V_2 -> V_72 ) ;
if ( V_2 -> V_45 == V_62 )
V_58 = snprintf ( V_78 , V_81 , L_6 ) ;
else if ( V_2 -> V_59 == V_64 )
V_58 = snprintf ( V_78 , V_81 , L_7 ) ;
else
V_58 = snprintf ( V_78 , V_81 , L_8 ) ;
F_35 ( & V_2 -> V_72 ) ;
return V_58 ;
}
static void F_43 ( struct V_71 * V_75 )
{
F_44 ( F_33 ( V_75 ) ) ;
}
struct V_1 * F_45 ( T_1 V_6 , int V_86 )
{
struct V_1 * V_2 ;
V_2 = F_46 ( sizeof( * V_2 ) , V_87 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_70 . V_71 . V_88 = F_43 ;
V_2 -> V_70 . V_71 . type = & V_89 ;
V_2 -> V_70 . V_86 = V_86 ;
if ( V_86 == V_90 )
V_2 -> V_70 . V_86 = V_91 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_45 = V_85 ;
V_2 -> V_59 = V_60 ;
F_47 ( & V_2 -> V_72 ) ;
F_48 ( & V_2 -> V_42 ) ;
F_48 ( & V_2 -> V_43 ) ;
F_49 ( & V_2 -> V_36 , V_92 , ( unsigned long ) V_2 ) ;
return V_2 ;
}
void F_50 ( struct V_1 * V_2 , struct V_31 * V_33 )
{
V_2 -> V_33 = V_33 ;
F_34 ( & V_2 -> V_72 ) ;
V_29 ( F_30 ( V_2 , V_74 ) ) ;
F_35 ( & V_2 -> V_72 ) ;
}
void F_51 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
F_52 ( ! V_32 -> V_41 ) ;
F_34 ( & V_2 -> V_72 ) ;
F_53 ( & V_32 -> V_39 , & V_2 -> V_43 ) ;
V_2 -> V_44 ++ ;
V_2 -> V_80 ++ ;
F_54 ( & V_2 -> V_52 -> V_80 ) ;
V_29 ( F_31 ( V_2 , V_74 ) ) ;
F_35 ( & V_2 -> V_72 ) ;
}
void F_55 ( struct V_1 * V_2 , struct V_31 * V_32 )
{
struct V_31 * V_93 ;
F_34 ( & V_2 -> V_72 ) ;
if ( ! F_56 ( & V_32 -> V_39 ) ) {
F_14 (tmp, &aq->pendingq, list)
if ( V_93 -> V_18 == V_32 -> V_18 ) {
V_2 -> V_40 -- ;
goto V_94;
}
V_2 -> V_44 -- ;
V_94:
F_15 ( & V_32 -> V_39 ) ;
}
F_35 ( & V_2 -> V_72 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
struct V_31 * V_32 , * V_51 ;
F_58 (ap_msg, next, &aq->pendingq, list) {
F_15 ( & V_32 -> V_39 ) ;
V_2 -> V_40 -- ;
V_32 -> V_58 = - V_95 ;
V_32 -> V_41 ( V_2 , V_32 , NULL ) ;
}
F_58 (ap_msg, next, &aq->requestq, list) {
F_15 ( & V_32 -> V_39 ) ;
V_2 -> V_44 -- ;
V_32 -> V_58 = - V_95 ;
V_32 -> V_41 ( V_2 , V_32 , NULL ) ;
}
}
void F_59 ( struct V_1 * V_2 )
{
F_34 ( & V_2 -> V_72 ) ;
F_57 ( V_2 ) ;
F_35 ( & V_2 -> V_72 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
F_59 ( V_2 ) ;
F_61 ( & V_2 -> V_36 ) ;
}
