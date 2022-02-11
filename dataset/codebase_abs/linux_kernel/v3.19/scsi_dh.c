static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 , * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (tmp, &scsi_dh_list, list) {
if ( ! strncmp ( V_3 -> V_2 , V_2 , strlen ( V_3 -> V_2 ) ) ) {
V_4 = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
return V_4 ;
}
static struct V_1 *
F_5 ( struct V_6 * V_7 )
{
struct V_1 * V_8 , * V_9 = NULL ;
F_2 ( & V_5 ) ;
F_3 (tmp_dh, &scsi_dh_list, list) {
if ( V_8 -> V_10 && V_8 -> V_10 ( V_7 ) ) {
V_9 = V_8 ;
break;
}
}
F_4 ( & V_5 ) ;
return V_9 ;
}
static struct V_1 *
F_6 ( struct V_1 * V_11 ,
struct V_6 * V_7 )
{
struct V_1 * V_9 ;
V_9 = F_5 ( V_7 ) ;
if ( V_11 && V_9 != V_11 )
V_9 = NULL ;
return V_9 ;
}
static int F_7 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
struct V_12 * V_13 ;
if ( V_7 -> V_12 ) {
if ( V_7 -> V_12 -> V_11 != V_11 )
return - V_14 ;
F_8 ( & V_7 -> V_12 -> V_15 ) ;
return 0 ;
}
if ( ! F_9 ( V_11 -> V_16 ) )
return - V_17 ;
V_13 = V_11 -> V_18 ( V_7 ) ;
if ( F_10 ( V_13 ) ) {
F_11 ( V_19 , V_7 , L_1 ,
V_11 -> V_2 , F_12 ( V_13 ) ) ;
F_13 ( V_11 -> V_16 ) ;
return F_12 ( V_13 ) ;
}
V_13 -> V_11 = V_11 ;
F_14 ( & V_13 -> V_15 ) ;
V_13 -> V_7 = V_7 ;
F_15 ( V_7 -> V_20 -> V_21 ) ;
V_7 -> V_12 = V_13 ;
F_16 ( V_7 -> V_20 -> V_21 ) ;
return 0 ;
}
static void F_17 ( struct V_15 * V_15 )
{
struct V_12 * V_12 =
F_18 ( V_15 , struct V_12 , V_15 ) ;
struct V_1 * V_11 = V_12 -> V_11 ;
struct V_6 * V_7 = V_12 -> V_7 ;
V_11 -> V_22 ( V_7 ) ;
F_15 ( V_7 -> V_20 -> V_21 ) ;
V_7 -> V_12 = NULL ;
F_16 ( V_7 -> V_20 -> V_21 ) ;
F_11 ( V_23 , V_7 , L_2 , V_11 -> V_2 ) ;
F_13 ( V_11 -> V_16 ) ;
}
static void F_19 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
if ( ! V_7 -> V_12 )
return;
if ( V_11 && V_11 != V_7 -> V_12 -> V_11 )
return;
if ( ! V_11 )
V_11 = V_7 -> V_12 -> V_11 ;
if ( V_11 )
F_20 ( & V_7 -> V_12 -> V_15 , F_17 ) ;
}
static T_1
F_21 ( struct V_24 * V_25 , struct V_26 * V_27 ,
const char * V_28 , T_2 V_29 )
{
struct V_6 * V_7 = F_22 ( V_25 ) ;
struct V_1 * V_11 ;
int V_30 = - V_17 ;
if ( V_7 -> V_31 == V_32 ||
V_7 -> V_31 == V_33 )
return - V_34 ;
if ( ! V_7 -> V_12 ) {
if ( ! ( V_11 = F_1 ( V_28 ) ) )
return V_30 ;
V_30 = F_7 ( V_7 , V_11 ) ;
} else {
V_11 = V_7 -> V_12 -> V_11 ;
if ( ! strncmp ( V_28 , L_3 , 6 ) ) {
F_19 ( V_7 , V_11 ) ;
V_30 = 0 ;
} else if ( ! strncmp ( V_28 , L_4 , 8 ) ) {
if ( V_11 -> V_35 )
V_30 = V_11 -> V_35 ( V_7 , NULL , NULL ) ;
else
V_30 = 0 ;
}
}
return V_30 < 0 ? V_30 : V_29 ;
}
static T_1
F_23 ( struct V_24 * V_25 , struct V_26 * V_27 , char * V_28 )
{
struct V_6 * V_7 = F_22 ( V_25 ) ;
if ( ! V_7 -> V_12 )
return snprintf ( V_28 , 20 , L_5 ) ;
return snprintf ( V_28 , 20 , L_6 , V_7 -> V_12 -> V_11 -> V_2 ) ;
}
static int F_24 ( struct V_24 * V_25 , void * V_36 )
{
struct V_6 * V_7 ;
int V_30 ;
if ( ! F_25 ( V_25 ) )
return 0 ;
V_7 = F_22 ( V_25 ) ;
V_30 = F_26 ( & V_7 -> V_37 ,
& V_38 ) ;
return 0 ;
}
static int F_27 ( struct V_24 * V_25 , void * V_36 )
{
struct V_6 * V_7 ;
if ( ! F_25 ( V_25 ) )
return 0 ;
V_7 = F_22 ( V_25 ) ;
F_28 ( & V_7 -> V_37 ,
& V_38 ) ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
unsigned long V_41 , void * V_36 )
{
struct V_24 * V_25 = V_36 ;
struct V_6 * V_7 ;
int V_30 = 0 ;
struct V_1 * V_42 = NULL ;
if ( ! F_25 ( V_25 ) )
return 0 ;
V_7 = F_22 ( V_25 ) ;
if ( V_41 == V_43 ) {
V_30 = F_26 ( V_25 , & V_38 ) ;
V_42 = F_6 ( NULL , V_7 ) ;
if ( V_42 )
V_30 = F_7 ( V_7 , V_42 ) ;
} else if ( V_41 == V_44 ) {
F_28 ( V_25 , & V_38 ) ;
F_19 ( V_7 , NULL ) ;
}
return V_30 ;
}
static int F_30 ( struct V_24 * V_25 , void * V_36 )
{
struct V_1 * V_11 = V_36 ;
struct V_6 * V_7 ;
if ( ! F_25 ( V_25 ) )
return 0 ;
if ( ! F_31 ( V_25 ) )
return 0 ;
V_7 = F_22 ( V_25 ) ;
if ( F_6 ( V_11 , V_7 ) )
F_7 ( V_7 , V_11 ) ;
F_32 ( V_25 ) ;
return 0 ;
}
static int F_33 ( struct V_24 * V_25 , void * V_36 )
{
struct V_1 * V_11 = V_36 ;
struct V_6 * V_7 ;
if ( ! F_25 ( V_25 ) )
return 0 ;
if ( ! F_31 ( V_25 ) )
return 0 ;
V_7 = F_22 ( V_25 ) ;
F_19 ( V_7 , V_11 ) ;
F_32 ( V_25 ) ;
return 0 ;
}
int F_34 ( struct V_1 * V_11 )
{
if ( F_1 ( V_11 -> V_2 ) )
return - V_14 ;
if ( ! V_11 -> V_18 || ! V_11 -> V_22 )
return - V_17 ;
F_2 ( & V_5 ) ;
F_35 ( & V_11 -> V_45 , & V_46 ) ;
F_4 ( & V_5 ) ;
F_36 ( & V_47 , NULL , V_11 , F_30 ) ;
F_37 ( V_48 L_7 , V_11 -> V_2 ) ;
return V_49 ;
}
int F_38 ( struct V_1 * V_11 )
{
if ( ! F_1 ( V_11 -> V_2 ) )
return - V_34 ;
F_36 ( & V_47 , NULL , V_11 ,
F_33 ) ;
F_2 ( & V_5 ) ;
F_39 ( & V_11 -> V_45 ) ;
F_4 ( & V_5 ) ;
F_37 ( V_48 L_8 , V_11 -> V_2 ) ;
return V_49 ;
}
int F_40 ( struct V_20 * V_50 , T_3 V_51 , void * V_36 )
{
int V_30 = 0 ;
unsigned long V_52 ;
struct V_6 * V_7 ;
struct V_1 * V_11 = NULL ;
struct V_24 * V_25 = NULL ;
F_41 ( V_50 -> V_21 , V_52 ) ;
V_7 = V_50 -> V_53 ;
if ( ! V_7 ) {
F_42 ( V_50 -> V_21 , V_52 ) ;
V_30 = V_54 ;
if ( V_51 )
V_51 ( V_36 , V_30 ) ;
return V_30 ;
}
if ( V_7 -> V_12 )
V_11 = V_7 -> V_12 -> V_11 ;
V_25 = F_31 ( & V_7 -> V_37 ) ;
if ( ! V_11 || ! V_25 ||
V_7 -> V_31 == V_32 ||
V_7 -> V_31 == V_33 )
V_30 = V_54 ;
if ( V_7 -> V_31 == V_55 )
V_30 = V_56 ;
F_42 ( V_50 -> V_21 , V_52 ) ;
if ( V_30 ) {
if ( V_51 )
V_51 ( V_36 , V_30 ) ;
goto V_57;
}
if ( V_11 -> V_35 )
V_30 = V_11 -> V_35 ( V_7 , V_51 , V_36 ) ;
V_57:
F_32 ( V_25 ) ;
return V_30 ;
}
int F_43 ( struct V_20 * V_50 , const char * V_58 )
{
int V_30 = - V_54 ;
unsigned long V_52 ;
struct V_6 * V_7 ;
struct V_1 * V_11 = NULL ;
F_41 ( V_50 -> V_21 , V_52 ) ;
V_7 = V_50 -> V_53 ;
if ( V_7 && V_7 -> V_12 )
V_11 = V_7 -> V_12 -> V_11 ;
if ( V_11 && V_11 -> V_59 && F_31 ( & V_7 -> V_37 ) )
V_30 = 0 ;
F_42 ( V_50 -> V_21 , V_52 ) ;
if ( V_30 )
return V_30 ;
V_30 = V_11 -> V_59 ( V_7 , V_58 ) ;
F_32 ( & V_7 -> V_37 ) ;
return V_30 ;
}
int F_44 ( const char * V_2 )
{
return ( F_1 ( V_2 ) != NULL ) ;
}
int F_45 ( struct V_20 * V_50 , const char * V_2 )
{
unsigned long V_52 ;
struct V_6 * V_7 ;
struct V_1 * V_11 ;
int V_30 = 0 ;
V_11 = F_1 ( V_2 ) ;
if ( ! V_11 )
return - V_17 ;
F_41 ( V_50 -> V_21 , V_52 ) ;
V_7 = V_50 -> V_53 ;
if ( ! V_7 || ! F_31 ( & V_7 -> V_37 ) )
V_30 = - V_34 ;
F_42 ( V_50 -> V_21 , V_52 ) ;
if ( ! V_30 ) {
V_30 = F_7 ( V_7 , V_11 ) ;
F_32 ( & V_7 -> V_37 ) ;
}
return V_30 ;
}
void F_46 ( struct V_20 * V_50 )
{
unsigned long V_52 ;
struct V_6 * V_7 ;
struct V_1 * V_11 = NULL ;
F_41 ( V_50 -> V_21 , V_52 ) ;
V_7 = V_50 -> V_53 ;
if ( ! V_7 || ! F_31 ( & V_7 -> V_37 ) )
V_7 = NULL ;
F_42 ( V_50 -> V_21 , V_52 ) ;
if ( ! V_7 )
return;
if ( V_7 -> V_12 ) {
V_11 = V_7 -> V_12 -> V_11 ;
F_19 ( V_7 , V_11 ) ;
}
F_32 ( & V_7 -> V_37 ) ;
}
const char * F_47 ( struct V_20 * V_50 , T_4 V_60 )
{
unsigned long V_52 ;
struct V_6 * V_7 ;
const char * V_61 = NULL ;
F_41 ( V_50 -> V_21 , V_52 ) ;
V_7 = V_50 -> V_53 ;
if ( ! V_7 || ! F_31 ( & V_7 -> V_37 ) )
V_7 = NULL ;
F_42 ( V_50 -> V_21 , V_52 ) ;
if ( ! V_7 )
return NULL ;
if ( V_7 -> V_12 )
V_61 = F_48 ( V_7 -> V_12 -> V_11 -> V_2 , V_60 ) ;
F_32 ( & V_7 -> V_37 ) ;
return V_61 ;
}
static int T_5 F_49 ( void )
{
int V_62 ;
V_62 = F_50 ( & V_47 , & V_63 ) ;
if ( ! V_62 )
F_36 ( & V_47 , NULL , NULL ,
F_24 ) ;
return V_62 ;
}
static void T_6 F_51 ( void )
{
F_36 ( & V_47 , NULL , NULL ,
F_27 ) ;
F_52 ( & V_47 , & V_63 ) ;
}
