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
F_6 ( struct V_1 * V_7 ,
struct V_8 * V_9 )
{
struct V_1 * V_10 = NULL ;
int V_6 ;
V_6 = F_7 ( V_9 , V_9 -> V_11 , V_9 -> V_12 ,
V_13 ) ;
V_10 = F_5 ( V_6 ) ;
if ( V_7 && V_10 != V_7 )
V_10 = NULL ;
return V_10 ;
}
static int F_8 ( struct V_8 * V_9 ,
struct V_1 * V_7 )
{
int V_14 = 0 ;
if ( V_9 -> V_15 ) {
if ( V_9 -> V_15 -> V_7 != V_7 )
V_14 = - V_16 ;
else
F_9 ( & V_9 -> V_15 -> V_17 ) ;
} else if ( V_7 -> V_18 ) {
V_14 = V_7 -> V_18 ( V_9 ) ;
if ( ! V_14 ) {
F_10 ( & V_9 -> V_15 -> V_17 ) ;
V_9 -> V_15 -> V_9 = V_9 ;
}
}
return V_14 ;
}
static void F_11 ( struct V_17 * V_17 )
{
struct V_15 * V_15 = F_12 ( V_17 , struct V_15 , V_17 ) ;
V_15 -> V_7 -> V_19 ( V_15 -> V_9 ) ;
}
static void F_13 ( struct V_8 * V_9 ,
struct V_1 * V_7 )
{
if ( ! V_9 -> V_15 )
return;
if ( V_7 && V_7 != V_9 -> V_15 -> V_7 )
return;
if ( ! V_7 )
V_7 = V_9 -> V_15 -> V_7 ;
if ( V_7 && V_7 -> V_19 )
F_14 ( & V_9 -> V_15 -> V_17 , F_11 ) ;
}
static T_1
F_15 ( struct V_20 * V_21 , struct V_22 * V_23 ,
const char * V_24 , T_2 V_25 )
{
struct V_8 * V_9 = F_16 ( V_21 ) ;
struct V_1 * V_7 ;
int V_14 = - V_26 ;
if ( ! V_9 -> V_15 ) {
if ( ! ( V_7 = F_1 ( V_24 ) ) )
return V_14 ;
V_14 = F_8 ( V_9 , V_7 ) ;
} else {
V_7 = V_9 -> V_15 -> V_7 ;
if ( ! strncmp ( V_24 , L_1 , 6 ) ) {
F_13 ( V_9 , V_7 ) ;
V_14 = 0 ;
} else if ( ! strncmp ( V_24 , L_2 , 8 ) ) {
if ( V_7 -> V_27 )
V_14 = V_7 -> V_27 ( V_9 , NULL , NULL ) ;
else
V_14 = 0 ;
}
}
return V_14 < 0 ? V_14 : V_25 ;
}
static T_1
F_17 ( struct V_20 * V_21 , struct V_22 * V_23 , char * V_24 )
{
struct V_8 * V_9 = F_16 ( V_21 ) ;
if ( ! V_9 -> V_15 )
return snprintf ( V_24 , 20 , L_3 ) ;
return snprintf ( V_24 , 20 , L_4 , V_9 -> V_15 -> V_7 -> V_2 ) ;
}
static int F_18 ( struct V_20 * V_21 , void * V_28 )
{
struct V_8 * V_9 ;
int V_14 ;
if ( ! F_19 ( V_21 ) )
return 0 ;
V_9 = F_16 ( V_21 ) ;
V_14 = F_20 ( & V_9 -> V_29 ,
& V_30 ) ;
return 0 ;
}
static int F_21 ( struct V_20 * V_21 , void * V_28 )
{
struct V_8 * V_9 ;
if ( ! F_19 ( V_21 ) )
return 0 ;
V_9 = F_16 ( V_21 ) ;
F_22 ( & V_9 -> V_29 ,
& V_30 ) ;
return 0 ;
}
static int F_23 ( struct V_31 * V_32 ,
unsigned long V_33 , void * V_28 )
{
struct V_20 * V_21 = V_28 ;
struct V_8 * V_9 ;
int V_14 = 0 ;
struct V_1 * V_34 = NULL ;
if ( ! F_19 ( V_21 ) )
return 0 ;
V_9 = F_16 ( V_21 ) ;
if ( V_33 == V_35 ) {
V_14 = F_20 ( V_21 , & V_30 ) ;
V_34 = F_6 ( NULL , V_9 ) ;
if ( V_34 )
V_14 = F_8 ( V_9 , V_34 ) ;
} else if ( V_33 == V_36 ) {
F_22 ( V_21 , & V_30 ) ;
F_13 ( V_9 , NULL ) ;
}
return V_14 ;
}
static int F_24 ( struct V_20 * V_21 , void * V_28 )
{
struct V_1 * V_7 = V_28 ;
struct V_8 * V_9 ;
if ( ! F_19 ( V_21 ) )
return 0 ;
if ( ! F_25 ( V_21 ) )
return 0 ;
V_9 = F_16 ( V_21 ) ;
if ( F_6 ( V_7 , V_9 ) )
F_8 ( V_9 , V_7 ) ;
F_26 ( V_21 ) ;
return 0 ;
}
static int F_27 ( struct V_20 * V_21 , void * V_28 )
{
struct V_1 * V_7 = V_28 ;
struct V_8 * V_9 ;
if ( ! F_19 ( V_21 ) )
return 0 ;
if ( ! F_25 ( V_21 ) )
return 0 ;
V_9 = F_16 ( V_21 ) ;
F_13 ( V_9 , V_7 ) ;
F_26 ( V_21 ) ;
return 0 ;
}
int F_28 ( struct V_1 * V_7 )
{
int V_37 ;
if ( F_1 ( V_7 -> V_2 ) )
return - V_16 ;
F_2 ( & V_5 ) ;
V_7 -> V_6 = V_38 ++ ;
F_29 ( & V_7 -> V_39 , & V_40 ) ;
F_4 ( & V_5 ) ;
for ( V_37 = 0 ; V_7 -> V_41 [ V_37 ] . V_11 ; V_37 ++ ) {
F_30 ( 0 ,
V_7 -> V_41 [ V_37 ] . V_11 ,
V_7 -> V_41 [ V_37 ] . V_12 ,
NULL ,
V_7 -> V_6 ,
V_13 ) ;
}
F_31 ( & V_42 , NULL , V_7 , F_24 ) ;
F_32 ( V_43 L_5 , V_7 -> V_2 ) ;
return V_44 ;
}
int F_33 ( struct V_1 * V_7 )
{
int V_37 ;
if ( ! F_1 ( V_7 -> V_2 ) )
return - V_45 ;
F_31 ( & V_42 , NULL , V_7 ,
F_27 ) ;
for ( V_37 = 0 ; V_7 -> V_41 [ V_37 ] . V_11 ; V_37 ++ ) {
F_34 ( V_7 -> V_41 [ V_37 ] . V_11 ,
V_7 -> V_41 [ V_37 ] . V_12 ,
V_13 ) ;
}
F_2 ( & V_5 ) ;
F_35 ( & V_7 -> V_39 ) ;
F_4 ( & V_5 ) ;
F_32 ( V_43 L_6 , V_7 -> V_2 ) ;
return V_44 ;
}
int F_36 ( struct V_46 * V_47 , T_3 V_48 , void * V_28 )
{
int V_14 = 0 ;
unsigned long V_49 ;
struct V_8 * V_9 ;
struct V_1 * V_7 = NULL ;
struct V_20 * V_21 = NULL ;
F_37 ( V_47 -> V_50 , V_49 ) ;
V_9 = V_47 -> V_51 ;
if ( V_9 && V_9 -> V_15 )
V_7 = V_9 -> V_15 -> V_7 ;
V_21 = F_25 ( & V_9 -> V_29 ) ;
if ( ! V_7 || ! V_21 ||
V_9 -> V_52 == V_53 ||
V_9 -> V_52 == V_54 )
V_14 = V_55 ;
if ( V_9 -> V_52 == V_56 )
V_14 = V_57 ;
F_38 ( V_47 -> V_50 , V_49 ) ;
if ( V_14 ) {
if ( V_48 )
V_48 ( V_28 , V_14 ) ;
goto V_58;
}
if ( V_7 -> V_27 )
V_14 = V_7 -> V_27 ( V_9 , V_48 , V_28 ) ;
V_58:
F_26 ( V_21 ) ;
return V_14 ;
}
int F_39 ( struct V_46 * V_47 , const char * V_59 )
{
int V_14 = - V_55 ;
unsigned long V_49 ;
struct V_8 * V_9 ;
struct V_1 * V_7 = NULL ;
F_37 ( V_47 -> V_50 , V_49 ) ;
V_9 = V_47 -> V_51 ;
if ( V_9 && V_9 -> V_15 )
V_7 = V_9 -> V_15 -> V_7 ;
if ( V_7 && V_7 -> V_60 && F_25 ( & V_9 -> V_29 ) )
V_14 = 0 ;
F_38 ( V_47 -> V_50 , V_49 ) ;
if ( V_14 )
return V_14 ;
V_14 = V_7 -> V_60 ( V_9 , V_59 ) ;
F_26 ( & V_9 -> V_29 ) ;
return V_14 ;
}
int F_40 ( const char * V_2 )
{
return ( F_1 ( V_2 ) != NULL ) ;
}
int F_41 ( struct V_46 * V_47 , const char * V_2 )
{
unsigned long V_49 ;
struct V_8 * V_9 ;
struct V_1 * V_7 ;
int V_14 = 0 ;
V_7 = F_1 ( V_2 ) ;
if ( ! V_7 )
return - V_26 ;
F_37 ( V_47 -> V_50 , V_49 ) ;
V_9 = V_47 -> V_51 ;
if ( ! V_9 || ! F_25 ( & V_9 -> V_29 ) )
V_14 = - V_45 ;
F_38 ( V_47 -> V_50 , V_49 ) ;
if ( ! V_14 ) {
V_14 = F_8 ( V_9 , V_7 ) ;
F_26 ( & V_9 -> V_29 ) ;
}
return V_14 ;
}
void F_42 ( struct V_46 * V_47 )
{
unsigned long V_49 ;
struct V_8 * V_9 ;
struct V_1 * V_7 = NULL ;
F_37 ( V_47 -> V_50 , V_49 ) ;
V_9 = V_47 -> V_51 ;
if ( ! V_9 || ! F_25 ( & V_9 -> V_29 ) )
V_9 = NULL ;
F_38 ( V_47 -> V_50 , V_49 ) ;
if ( ! V_9 )
return;
if ( V_9 -> V_15 ) {
V_7 = V_9 -> V_15 -> V_7 ;
F_13 ( V_9 , V_7 ) ;
}
F_26 ( & V_9 -> V_29 ) ;
}
static int T_4 F_43 ( void )
{
int V_61 ;
V_61 = F_44 ( V_13 , L_7 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_45 ( & V_42 , & V_62 ) ;
if ( ! V_61 )
F_31 ( & V_42 , NULL , NULL ,
F_18 ) ;
return V_61 ;
}
static void T_5 F_46 ( void )
{
F_31 ( & V_42 , NULL , NULL ,
F_21 ) ;
F_47 ( & V_42 , & V_62 ) ;
F_48 ( V_13 ) ;
}
