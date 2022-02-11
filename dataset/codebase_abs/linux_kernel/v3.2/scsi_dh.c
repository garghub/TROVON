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
static struct V_1 * F_5 ( int V_6 )
{
struct V_1 * V_3 , * V_4 = NULL ;
F_2 ( & V_5 ) ;
F_3 (tmp, &scsi_dh_list, list) {
if ( V_3 -> V_6 == V_6 ) {
V_4 = V_3 ;
break;
}
}
F_4 ( & V_5 ) ;
return V_4 ;
}
static struct V_1 *
F_6 ( struct V_7 * V_8 )
{
struct V_1 * V_9 , * V_10 = NULL ;
F_2 ( & V_5 ) ;
F_3 (tmp_dh, &scsi_dh_list, list) {
if ( V_9 -> V_11 && V_9 -> V_11 ( V_8 ) ) {
V_10 = V_9 ;
break;
}
}
F_4 ( & V_5 ) ;
return V_10 ;
}
static struct V_1 *
F_7 ( struct V_7 * V_8 )
{
int V_6 ;
V_6 = F_8 ( V_8 , V_8 -> V_12 , V_8 -> V_13 ,
V_14 ) ;
return F_5 ( V_6 ) ;
}
static struct V_1 *
F_9 ( struct V_1 * V_15 ,
struct V_7 * V_8 )
{
struct V_1 * V_10 ;
V_10 = F_6 ( V_8 ) ;
if ( ! V_10 )
V_10 = F_7 ( V_8 ) ;
if ( V_15 && V_10 != V_15 )
V_10 = NULL ;
return V_10 ;
}
static int F_10 ( struct V_7 * V_8 ,
struct V_1 * V_15 )
{
int V_16 = 0 ;
if ( V_8 -> V_17 ) {
if ( V_8 -> V_17 -> V_15 != V_15 )
V_16 = - V_18 ;
else
F_11 ( & V_8 -> V_17 -> V_19 ) ;
} else if ( V_15 -> V_20 ) {
V_16 = V_15 -> V_20 ( V_8 ) ;
if ( ! V_16 ) {
F_12 ( & V_8 -> V_17 -> V_19 ) ;
V_8 -> V_17 -> V_8 = V_8 ;
}
}
return V_16 ;
}
static void F_13 ( struct V_19 * V_19 )
{
struct V_17 * V_17 = F_14 ( V_19 , struct V_17 , V_19 ) ;
V_17 -> V_15 -> V_21 ( V_17 -> V_8 ) ;
}
static void F_15 ( struct V_7 * V_8 ,
struct V_1 * V_15 )
{
if ( ! V_8 -> V_17 )
return;
if ( V_15 && V_15 != V_8 -> V_17 -> V_15 )
return;
if ( ! V_15 )
V_15 = V_8 -> V_17 -> V_15 ;
if ( V_15 && V_15 -> V_21 )
F_16 ( & V_8 -> V_17 -> V_19 , F_13 ) ;
}
static T_1
F_17 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_2 V_27 )
{
struct V_7 * V_8 = F_18 ( V_23 ) ;
struct V_1 * V_15 ;
int V_16 = - V_28 ;
if ( V_8 -> V_29 == V_30 ||
V_8 -> V_29 == V_31 )
return - V_32 ;
if ( ! V_8 -> V_17 ) {
if ( ! ( V_15 = F_1 ( V_26 ) ) )
return V_16 ;
V_16 = F_10 ( V_8 , V_15 ) ;
} else {
V_15 = V_8 -> V_17 -> V_15 ;
if ( ! strncmp ( V_26 , L_1 , 6 ) ) {
F_15 ( V_8 , V_15 ) ;
V_16 = 0 ;
} else if ( ! strncmp ( V_26 , L_2 , 8 ) ) {
if ( V_15 -> V_33 )
V_16 = V_15 -> V_33 ( V_8 , NULL , NULL ) ;
else
V_16 = 0 ;
}
}
return V_16 < 0 ? V_16 : V_27 ;
}
static T_1
F_19 ( struct V_22 * V_23 , struct V_24 * V_25 , char * V_26 )
{
struct V_7 * V_8 = F_18 ( V_23 ) ;
if ( ! V_8 -> V_17 )
return snprintf ( V_26 , 20 , L_3 ) ;
return snprintf ( V_26 , 20 , L_4 , V_8 -> V_17 -> V_15 -> V_2 ) ;
}
static int F_20 ( struct V_22 * V_23 , void * V_34 )
{
struct V_7 * V_8 ;
int V_16 ;
if ( ! F_21 ( V_23 ) )
return 0 ;
V_8 = F_18 ( V_23 ) ;
V_16 = F_22 ( & V_8 -> V_35 ,
& V_36 ) ;
return 0 ;
}
static int F_23 ( struct V_22 * V_23 , void * V_34 )
{
struct V_7 * V_8 ;
if ( ! F_21 ( V_23 ) )
return 0 ;
V_8 = F_18 ( V_23 ) ;
F_24 ( & V_8 -> V_35 ,
& V_36 ) ;
return 0 ;
}
static int F_25 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_34 )
{
struct V_22 * V_23 = V_34 ;
struct V_7 * V_8 ;
int V_16 = 0 ;
struct V_1 * V_40 = NULL ;
if ( ! F_21 ( V_23 ) )
return 0 ;
V_8 = F_18 ( V_23 ) ;
if ( V_39 == V_41 ) {
V_16 = F_22 ( V_23 , & V_36 ) ;
V_40 = F_9 ( NULL , V_8 ) ;
if ( V_40 )
V_16 = F_10 ( V_8 , V_40 ) ;
} else if ( V_39 == V_42 ) {
F_24 ( V_23 , & V_36 ) ;
F_15 ( V_8 , NULL ) ;
}
return V_16 ;
}
static int F_26 ( struct V_22 * V_23 , void * V_34 )
{
struct V_1 * V_15 = V_34 ;
struct V_7 * V_8 ;
if ( ! F_21 ( V_23 ) )
return 0 ;
if ( ! F_27 ( V_23 ) )
return 0 ;
V_8 = F_18 ( V_23 ) ;
if ( F_9 ( V_15 , V_8 ) )
F_10 ( V_8 , V_15 ) ;
F_28 ( V_23 ) ;
return 0 ;
}
static int F_29 ( struct V_22 * V_23 , void * V_34 )
{
struct V_1 * V_15 = V_34 ;
struct V_7 * V_8 ;
if ( ! F_21 ( V_23 ) )
return 0 ;
if ( ! F_27 ( V_23 ) )
return 0 ;
V_8 = F_18 ( V_23 ) ;
F_15 ( V_8 , V_15 ) ;
F_28 ( V_23 ) ;
return 0 ;
}
int F_30 ( struct V_1 * V_15 )
{
int V_43 ;
if ( F_1 ( V_15 -> V_2 ) )
return - V_18 ;
F_2 ( & V_5 ) ;
V_15 -> V_6 = V_44 ++ ;
F_31 ( & V_15 -> V_45 , & V_46 ) ;
F_4 ( & V_5 ) ;
for ( V_43 = 0 ; V_15 -> V_47 && V_15 -> V_47 [ V_43 ] . V_12 ; V_43 ++ ) {
F_32 ( 0 ,
V_15 -> V_47 [ V_43 ] . V_12 ,
V_15 -> V_47 [ V_43 ] . V_13 ,
NULL ,
V_15 -> V_6 ,
V_14 ) ;
}
F_33 ( & V_48 , NULL , V_15 , F_26 ) ;
F_34 ( V_49 L_5 , V_15 -> V_2 ) ;
return V_50 ;
}
int F_35 ( struct V_1 * V_15 )
{
int V_43 ;
if ( ! F_1 ( V_15 -> V_2 ) )
return - V_32 ;
F_33 ( & V_48 , NULL , V_15 ,
F_29 ) ;
for ( V_43 = 0 ; V_15 -> V_47 && V_15 -> V_47 [ V_43 ] . V_12 ; V_43 ++ ) {
F_36 ( V_15 -> V_47 [ V_43 ] . V_12 ,
V_15 -> V_47 [ V_43 ] . V_13 ,
V_14 ) ;
}
F_2 ( & V_5 ) ;
F_37 ( & V_15 -> V_45 ) ;
F_4 ( & V_5 ) ;
F_34 ( V_49 L_6 , V_15 -> V_2 ) ;
return V_50 ;
}
int F_38 ( struct V_51 * V_52 , T_3 V_53 , void * V_34 )
{
int V_16 = 0 ;
unsigned long V_54 ;
struct V_7 * V_8 ;
struct V_1 * V_15 = NULL ;
struct V_22 * V_23 = NULL ;
F_39 ( V_52 -> V_55 , V_54 ) ;
V_8 = V_52 -> V_56 ;
if ( ! V_8 ) {
F_40 ( V_52 -> V_55 , V_54 ) ;
V_16 = V_57 ;
if ( V_53 )
V_53 ( V_34 , V_16 ) ;
return V_16 ;
}
if ( V_8 -> V_17 )
V_15 = V_8 -> V_17 -> V_15 ;
V_23 = F_27 ( & V_8 -> V_35 ) ;
if ( ! V_15 || ! V_23 ||
V_8 -> V_29 == V_30 ||
V_8 -> V_29 == V_31 )
V_16 = V_57 ;
if ( V_8 -> V_29 == V_58 )
V_16 = V_59 ;
F_40 ( V_52 -> V_55 , V_54 ) ;
if ( V_16 ) {
if ( V_53 )
V_53 ( V_34 , V_16 ) ;
goto V_60;
}
if ( V_15 -> V_33 )
V_16 = V_15 -> V_33 ( V_8 , V_53 , V_34 ) ;
V_60:
F_28 ( V_23 ) ;
return V_16 ;
}
int F_41 ( struct V_51 * V_52 , const char * V_61 )
{
int V_16 = - V_57 ;
unsigned long V_54 ;
struct V_7 * V_8 ;
struct V_1 * V_15 = NULL ;
F_39 ( V_52 -> V_55 , V_54 ) ;
V_8 = V_52 -> V_56 ;
if ( V_8 && V_8 -> V_17 )
V_15 = V_8 -> V_17 -> V_15 ;
if ( V_15 && V_15 -> V_62 && F_27 ( & V_8 -> V_35 ) )
V_16 = 0 ;
F_40 ( V_52 -> V_55 , V_54 ) ;
if ( V_16 )
return V_16 ;
V_16 = V_15 -> V_62 ( V_8 , V_61 ) ;
F_28 ( & V_8 -> V_35 ) ;
return V_16 ;
}
int F_42 ( const char * V_2 )
{
return ( F_1 ( V_2 ) != NULL ) ;
}
int F_43 ( struct V_51 * V_52 , const char * V_2 )
{
unsigned long V_54 ;
struct V_7 * V_8 ;
struct V_1 * V_15 ;
int V_16 = 0 ;
V_15 = F_1 ( V_2 ) ;
if ( ! V_15 )
return - V_28 ;
F_39 ( V_52 -> V_55 , V_54 ) ;
V_8 = V_52 -> V_56 ;
if ( ! V_8 || ! F_27 ( & V_8 -> V_35 ) )
V_16 = - V_32 ;
F_40 ( V_52 -> V_55 , V_54 ) ;
if ( ! V_16 ) {
V_16 = F_10 ( V_8 , V_15 ) ;
F_28 ( & V_8 -> V_35 ) ;
}
return V_16 ;
}
void F_44 ( struct V_51 * V_52 )
{
unsigned long V_54 ;
struct V_7 * V_8 ;
struct V_1 * V_15 = NULL ;
F_39 ( V_52 -> V_55 , V_54 ) ;
V_8 = V_52 -> V_56 ;
if ( ! V_8 || ! F_27 ( & V_8 -> V_35 ) )
V_8 = NULL ;
F_40 ( V_52 -> V_55 , V_54 ) ;
if ( ! V_8 )
return;
if ( V_8 -> V_17 ) {
V_15 = V_8 -> V_17 -> V_15 ;
F_15 ( V_8 , V_15 ) ;
}
F_28 ( & V_8 -> V_35 ) ;
}
static int T_4 F_45 ( void )
{
int V_63 ;
V_63 = F_46 ( V_14 , L_7 ) ;
if ( V_63 )
return V_63 ;
V_63 = F_47 ( & V_48 , & V_64 ) ;
if ( ! V_63 )
F_33 ( & V_48 , NULL , NULL ,
F_20 ) ;
return V_63 ;
}
static void T_5 F_48 ( void )
{
F_33 ( & V_48 , NULL , NULL ,
F_23 ) ;
F_49 ( & V_48 , & V_64 ) ;
F_50 ( V_14 ) ;
}
