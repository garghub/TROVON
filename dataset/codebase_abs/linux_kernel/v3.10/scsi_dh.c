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
int V_12 = 0 ;
if ( V_7 -> V_13 ) {
if ( V_7 -> V_13 -> V_11 != V_11 )
V_12 = - V_14 ;
else
F_8 ( & V_7 -> V_13 -> V_15 ) ;
} else if ( V_11 -> V_16 ) {
V_12 = V_11 -> V_16 ( V_7 ) ;
if ( ! V_12 ) {
F_9 ( & V_7 -> V_13 -> V_15 ) ;
V_7 -> V_13 -> V_7 = V_7 ;
}
}
return V_12 ;
}
static void F_10 ( struct V_15 * V_15 )
{
struct V_13 * V_13 = F_11 ( V_15 , struct V_13 , V_15 ) ;
V_13 -> V_11 -> V_17 ( V_13 -> V_7 ) ;
}
static void F_12 ( struct V_6 * V_7 ,
struct V_1 * V_11 )
{
if ( ! V_7 -> V_13 )
return;
if ( V_11 && V_11 != V_7 -> V_13 -> V_11 )
return;
if ( ! V_11 )
V_11 = V_7 -> V_13 -> V_11 ;
if ( V_11 && V_11 -> V_17 )
F_13 ( & V_7 -> V_13 -> V_15 , F_10 ) ;
}
static T_1
F_14 ( struct V_18 * V_19 , struct V_20 * V_21 ,
const char * V_22 , T_2 V_23 )
{
struct V_6 * V_7 = F_15 ( V_19 ) ;
struct V_1 * V_11 ;
int V_12 = - V_24 ;
if ( V_7 -> V_25 == V_26 ||
V_7 -> V_25 == V_27 )
return - V_28 ;
if ( ! V_7 -> V_13 ) {
if ( ! ( V_11 = F_1 ( V_22 ) ) )
return V_12 ;
V_12 = F_7 ( V_7 , V_11 ) ;
} else {
V_11 = V_7 -> V_13 -> V_11 ;
if ( ! strncmp ( V_22 , L_1 , 6 ) ) {
F_12 ( V_7 , V_11 ) ;
V_12 = 0 ;
} else if ( ! strncmp ( V_22 , L_2 , 8 ) ) {
if ( V_11 -> V_29 )
V_12 = V_11 -> V_29 ( V_7 , NULL , NULL ) ;
else
V_12 = 0 ;
}
}
return V_12 < 0 ? V_12 : V_23 ;
}
static T_1
F_16 ( struct V_18 * V_19 , struct V_20 * V_21 , char * V_22 )
{
struct V_6 * V_7 = F_15 ( V_19 ) ;
if ( ! V_7 -> V_13 )
return snprintf ( V_22 , 20 , L_3 ) ;
return snprintf ( V_22 , 20 , L_4 , V_7 -> V_13 -> V_11 -> V_2 ) ;
}
static int F_17 ( struct V_18 * V_19 , void * V_30 )
{
struct V_6 * V_7 ;
int V_12 ;
if ( ! F_18 ( V_19 ) )
return 0 ;
V_7 = F_15 ( V_19 ) ;
V_12 = F_19 ( & V_7 -> V_31 ,
& V_32 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 , void * V_30 )
{
struct V_6 * V_7 ;
if ( ! F_18 ( V_19 ) )
return 0 ;
V_7 = F_15 ( V_19 ) ;
F_21 ( & V_7 -> V_31 ,
& V_32 ) ;
return 0 ;
}
static int F_22 ( struct V_33 * V_34 ,
unsigned long V_35 , void * V_30 )
{
struct V_18 * V_19 = V_30 ;
struct V_6 * V_7 ;
int V_12 = 0 ;
struct V_1 * V_36 = NULL ;
if ( ! F_18 ( V_19 ) )
return 0 ;
V_7 = F_15 ( V_19 ) ;
if ( V_35 == V_37 ) {
V_12 = F_19 ( V_19 , & V_32 ) ;
V_36 = F_6 ( NULL , V_7 ) ;
if ( V_36 )
V_12 = F_7 ( V_7 , V_36 ) ;
} else if ( V_35 == V_38 ) {
F_21 ( V_19 , & V_32 ) ;
F_12 ( V_7 , NULL ) ;
}
return V_12 ;
}
static int F_23 ( struct V_18 * V_19 , void * V_30 )
{
struct V_1 * V_11 = V_30 ;
struct V_6 * V_7 ;
if ( ! F_18 ( V_19 ) )
return 0 ;
if ( ! F_24 ( V_19 ) )
return 0 ;
V_7 = F_15 ( V_19 ) ;
if ( F_6 ( V_11 , V_7 ) )
F_7 ( V_7 , V_11 ) ;
F_25 ( V_19 ) ;
return 0 ;
}
static int F_26 ( struct V_18 * V_19 , void * V_30 )
{
struct V_1 * V_11 = V_30 ;
struct V_6 * V_7 ;
if ( ! F_18 ( V_19 ) )
return 0 ;
if ( ! F_24 ( V_19 ) )
return 0 ;
V_7 = F_15 ( V_19 ) ;
F_12 ( V_7 , V_11 ) ;
F_25 ( V_19 ) ;
return 0 ;
}
int F_27 ( struct V_1 * V_11 )
{
if ( F_1 ( V_11 -> V_2 ) )
return - V_14 ;
F_2 ( & V_5 ) ;
F_28 ( & V_11 -> V_39 , & V_40 ) ;
F_4 ( & V_5 ) ;
F_29 ( & V_41 , NULL , V_11 , F_23 ) ;
F_30 ( V_42 L_5 , V_11 -> V_2 ) ;
return V_43 ;
}
int F_31 ( struct V_1 * V_11 )
{
if ( ! F_1 ( V_11 -> V_2 ) )
return - V_28 ;
F_29 ( & V_41 , NULL , V_11 ,
F_26 ) ;
F_2 ( & V_5 ) ;
F_32 ( & V_11 -> V_39 ) ;
F_4 ( & V_5 ) ;
F_30 ( V_42 L_6 , V_11 -> V_2 ) ;
return V_43 ;
}
int F_33 ( struct V_44 * V_45 , T_3 V_46 , void * V_30 )
{
int V_12 = 0 ;
unsigned long V_47 ;
struct V_6 * V_7 ;
struct V_1 * V_11 = NULL ;
struct V_18 * V_19 = NULL ;
F_34 ( V_45 -> V_48 , V_47 ) ;
V_7 = V_45 -> V_49 ;
if ( ! V_7 ) {
F_35 ( V_45 -> V_48 , V_47 ) ;
V_12 = V_50 ;
if ( V_46 )
V_46 ( V_30 , V_12 ) ;
return V_12 ;
}
if ( V_7 -> V_13 )
V_11 = V_7 -> V_13 -> V_11 ;
V_19 = F_24 ( & V_7 -> V_31 ) ;
if ( ! V_11 || ! V_19 ||
V_7 -> V_25 == V_26 ||
V_7 -> V_25 == V_27 )
V_12 = V_50 ;
if ( V_7 -> V_25 == V_51 )
V_12 = V_52 ;
F_35 ( V_45 -> V_48 , V_47 ) ;
if ( V_12 ) {
if ( V_46 )
V_46 ( V_30 , V_12 ) ;
goto V_53;
}
if ( V_11 -> V_29 )
V_12 = V_11 -> V_29 ( V_7 , V_46 , V_30 ) ;
V_53:
F_25 ( V_19 ) ;
return V_12 ;
}
int F_36 ( struct V_44 * V_45 , const char * V_54 )
{
int V_12 = - V_50 ;
unsigned long V_47 ;
struct V_6 * V_7 ;
struct V_1 * V_11 = NULL ;
F_34 ( V_45 -> V_48 , V_47 ) ;
V_7 = V_45 -> V_49 ;
if ( V_7 && V_7 -> V_13 )
V_11 = V_7 -> V_13 -> V_11 ;
if ( V_11 && V_11 -> V_55 && F_24 ( & V_7 -> V_31 ) )
V_12 = 0 ;
F_35 ( V_45 -> V_48 , V_47 ) ;
if ( V_12 )
return V_12 ;
V_12 = V_11 -> V_55 ( V_7 , V_54 ) ;
F_25 ( & V_7 -> V_31 ) ;
return V_12 ;
}
int F_37 ( const char * V_2 )
{
return ( F_1 ( V_2 ) != NULL ) ;
}
int F_38 ( struct V_44 * V_45 , const char * V_2 )
{
unsigned long V_47 ;
struct V_6 * V_7 ;
struct V_1 * V_11 ;
int V_12 = 0 ;
V_11 = F_1 ( V_2 ) ;
if ( ! V_11 )
return - V_24 ;
F_34 ( V_45 -> V_48 , V_47 ) ;
V_7 = V_45 -> V_49 ;
if ( ! V_7 || ! F_24 ( & V_7 -> V_31 ) )
V_12 = - V_28 ;
F_35 ( V_45 -> V_48 , V_47 ) ;
if ( ! V_12 ) {
V_12 = F_7 ( V_7 , V_11 ) ;
F_25 ( & V_7 -> V_31 ) ;
}
return V_12 ;
}
void F_39 ( struct V_44 * V_45 )
{
unsigned long V_47 ;
struct V_6 * V_7 ;
struct V_1 * V_11 = NULL ;
F_34 ( V_45 -> V_48 , V_47 ) ;
V_7 = V_45 -> V_49 ;
if ( ! V_7 || ! F_24 ( & V_7 -> V_31 ) )
V_7 = NULL ;
F_35 ( V_45 -> V_48 , V_47 ) ;
if ( ! V_7 )
return;
if ( V_7 -> V_13 ) {
V_11 = V_7 -> V_13 -> V_11 ;
F_12 ( V_7 , V_11 ) ;
}
F_25 ( & V_7 -> V_31 ) ;
}
const char * F_40 ( struct V_44 * V_45 , T_4 V_56 )
{
unsigned long V_47 ;
struct V_6 * V_7 ;
const char * V_57 = NULL ;
F_34 ( V_45 -> V_48 , V_47 ) ;
V_7 = V_45 -> V_49 ;
if ( ! V_7 || ! F_24 ( & V_7 -> V_31 ) )
V_7 = NULL ;
F_35 ( V_45 -> V_48 , V_47 ) ;
if ( ! V_7 )
return NULL ;
if ( V_7 -> V_13 )
V_57 = F_41 ( V_7 -> V_13 -> V_11 -> V_2 , V_56 ) ;
F_25 ( & V_7 -> V_31 ) ;
return V_57 ;
}
static int T_5 F_42 ( void )
{
int V_58 ;
V_58 = F_43 ( & V_41 , & V_59 ) ;
if ( ! V_58 )
F_29 ( & V_41 , NULL , NULL ,
F_17 ) ;
return V_58 ;
}
static void T_6 F_44 ( void )
{
F_29 ( & V_41 , NULL , NULL ,
F_20 ) ;
F_45 ( & V_41 , & V_59 ) ;
}
