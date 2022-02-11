static const char *
F_1 ( struct V_1 * V_2 )
{
const struct V_3 * V_4 ;
if ( F_2 ( V_2 ) )
return L_1 ;
for ( V_4 = V_3 ; V_4 -> V_5 ; V_4 ++ ) {
if ( ! strncmp ( V_2 -> V_5 , V_4 -> V_5 , strlen ( V_4 -> V_5 ) ) &&
! strncmp ( V_2 -> V_6 , V_4 -> V_6 , strlen ( V_4 -> V_6 ) ) ) {
return V_4 -> V_7 ;
}
}
return NULL ;
}
static struct V_8 * F_3 ( const char * V_9 )
{
struct V_8 * V_10 , * V_11 = NULL ;
F_4 ( & V_12 ) ;
F_5 (tmp, &scsi_dh_list, list) {
if ( ! strncmp ( V_10 -> V_9 , V_9 , strlen ( V_10 -> V_9 ) ) ) {
V_11 = V_10 ;
break;
}
}
F_6 ( & V_12 ) ;
return V_11 ;
}
static struct V_8 * F_7 ( const char * V_9 )
{
struct V_8 * V_13 ;
V_13 = F_3 ( V_9 ) ;
if ( ! V_13 ) {
F_8 ( L_2 , V_9 ) ;
V_13 = F_3 ( V_9 ) ;
}
return V_13 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_8 * V_14 )
{
int error ;
if ( ! F_10 ( V_14 -> V_15 ) )
return - V_16 ;
error = V_14 -> V_17 ( V_2 ) ;
if ( error ) {
F_11 ( V_18 , V_2 , L_3 ,
V_14 -> V_9 , error ) ;
F_12 ( V_14 -> V_15 ) ;
} else
V_2 -> V_19 = V_14 ;
return error ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_19 -> V_20 ( V_2 ) ;
F_11 ( V_21 , V_2 , L_4 , V_2 -> V_19 -> V_9 ) ;
F_12 ( V_2 -> V_19 -> V_15 ) ;
}
static T_1
F_14 ( struct V_22 * V_23 , struct V_24 * V_25 ,
const char * V_26 , T_2 V_27 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
struct V_8 * V_14 ;
int V_28 = - V_16 ;
if ( V_2 -> V_29 == V_30 ||
V_2 -> V_29 == V_31 )
return - V_32 ;
if ( ! V_2 -> V_19 ) {
V_14 = F_7 ( V_26 ) ;
if ( ! V_14 )
return V_28 ;
V_28 = F_9 ( V_2 , V_14 ) ;
} else {
if ( ! strncmp ( V_26 , L_5 , 6 ) ) {
F_11 ( V_33 , V_2 ,
L_6 ,
V_2 -> V_19 -> V_9 ) ;
V_28 = - V_16 ;
} else if ( ! strncmp ( V_26 , L_7 , 8 ) ) {
if ( V_2 -> V_19 -> V_34 )
V_28 = V_2 -> V_19 -> V_34 ( V_2 , NULL , NULL ) ;
else
V_28 = 0 ;
}
}
return V_28 < 0 ? V_28 : V_27 ;
}
static T_1
F_16 ( struct V_22 * V_23 , struct V_24 * V_25 , char * V_26 )
{
struct V_1 * V_2 = F_15 ( V_23 ) ;
if ( ! V_2 -> V_19 )
return snprintf ( V_26 , 20 , L_8 ) ;
return snprintf ( V_26 , 20 , L_9 , V_2 -> V_19 -> V_9 ) ;
}
int F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_35 = NULL ;
const char * V_36 ;
int V_28 ;
V_28 = F_18 ( & V_2 -> V_37 , & V_38 ) ;
if ( V_28 )
return V_28 ;
V_36 = F_1 ( V_2 ) ;
if ( V_36 )
V_35 = F_3 ( V_36 ) ;
if ( V_35 )
V_28 = F_9 ( V_2 , V_35 ) ;
return V_28 ;
}
void F_19 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_13 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_37 , & V_38 ) ;
}
int F_22 ( struct V_8 * V_14 )
{
if ( F_3 ( V_14 -> V_9 ) )
return - V_39 ;
if ( ! V_14 -> V_17 || ! V_14 -> V_20 )
return - V_16 ;
F_4 ( & V_12 ) ;
F_23 ( & V_14 -> V_40 , & V_41 ) ;
F_6 ( & V_12 ) ;
F_24 ( V_42 L_10 , V_14 -> V_9 ) ;
return V_43 ;
}
int F_25 ( struct V_8 * V_14 )
{
if ( ! F_3 ( V_14 -> V_9 ) )
return - V_32 ;
F_4 ( & V_12 ) ;
F_26 ( & V_14 -> V_40 ) ;
F_6 ( & V_12 ) ;
F_24 ( V_42 L_11 , V_14 -> V_9 ) ;
return V_43 ;
}
static struct V_1 * F_27 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
unsigned long V_46 ;
F_28 ( V_45 -> V_47 , V_46 ) ;
V_2 = V_45 -> V_48 ;
if ( ! V_2 || ! F_29 ( & V_2 -> V_37 ) )
V_2 = NULL ;
F_30 ( V_45 -> V_47 , V_46 ) ;
return V_2 ;
}
int F_31 ( struct V_44 * V_45 , T_3 V_49 , void * V_50 )
{
struct V_1 * V_2 ;
int V_28 = V_51 ;
V_2 = F_27 ( V_45 ) ;
if ( ! V_2 ) {
if ( V_49 )
V_49 ( V_50 , V_28 ) ;
return V_28 ;
}
if ( ! V_2 -> V_19 )
goto V_52;
V_28 = V_53 ;
if ( V_2 -> V_29 == V_30 ||
V_2 -> V_29 == V_31 )
goto V_52;
V_28 = V_54 ;
if ( V_2 -> V_29 == V_55 )
goto V_52;
if ( V_2 -> V_19 -> V_34 )
V_28 = V_2 -> V_19 -> V_34 ( V_2 , V_49 , V_50 ) ;
V_56:
F_32 ( & V_2 -> V_37 ) ;
return V_28 ;
V_52:
if ( V_49 )
V_49 ( V_50 , V_28 ) ;
goto V_56;
}
int F_33 ( struct V_44 * V_45 , const char * V_57 )
{
struct V_1 * V_2 ;
int V_28 = - V_51 ;
V_2 = F_27 ( V_45 ) ;
if ( ! V_2 )
return V_28 ;
if ( V_2 -> V_19 && V_2 -> V_19 -> V_58 )
V_28 = V_2 -> V_19 -> V_58 ( V_2 , V_57 ) ;
F_32 ( & V_2 -> V_37 ) ;
return V_28 ;
}
int F_34 ( struct V_44 * V_45 , const char * V_9 )
{
struct V_1 * V_2 ;
struct V_8 * V_14 ;
int V_28 = 0 ;
V_2 = F_27 ( V_45 ) ;
if ( ! V_2 )
return - V_32 ;
V_14 = F_7 ( V_9 ) ;
if ( ! V_14 ) {
V_28 = - V_16 ;
goto V_56;
}
if ( V_2 -> V_19 ) {
if ( V_2 -> V_19 != V_14 )
V_28 = - V_39 ;
goto V_56;
}
V_28 = F_9 ( V_2 , V_14 ) ;
V_56:
F_32 ( & V_2 -> V_37 ) ;
return V_28 ;
}
const char * F_35 ( struct V_44 * V_45 , T_4 V_59 )
{
struct V_1 * V_2 ;
const char * V_60 = NULL ;
V_2 = F_27 ( V_45 ) ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_19 )
V_60 = F_36 ( V_2 -> V_19 -> V_9 , V_59 ) ;
F_32 ( & V_2 -> V_37 ) ;
return V_60 ;
}
