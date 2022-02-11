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
int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_22 = NULL ;
const char * V_23 ;
int V_24 = 0 ;
V_23 = F_1 ( V_2 ) ;
if ( V_23 )
V_22 = F_3 ( V_23 ) ;
if ( V_22 )
V_24 = F_9 ( V_2 , V_22 ) ;
return V_24 ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_19 )
F_13 ( V_2 ) ;
}
int F_16 ( struct V_8 * V_14 )
{
if ( F_3 ( V_14 -> V_9 ) )
return - V_25 ;
if ( ! V_14 -> V_17 || ! V_14 -> V_20 )
return - V_16 ;
F_4 ( & V_12 ) ;
F_17 ( & V_14 -> V_26 , & V_27 ) ;
F_6 ( & V_12 ) ;
F_18 ( V_28 L_5 , V_14 -> V_9 ) ;
return V_29 ;
}
int F_19 ( struct V_8 * V_14 )
{
if ( ! F_3 ( V_14 -> V_9 ) )
return - V_30 ;
F_4 ( & V_12 ) ;
F_20 ( & V_14 -> V_26 ) ;
F_6 ( & V_12 ) ;
F_18 ( V_28 L_6 , V_14 -> V_9 ) ;
return V_29 ;
}
static struct V_1 * F_21 ( struct V_31 * V_32 )
{
struct V_1 * V_2 ;
unsigned long V_33 ;
F_22 ( V_32 -> V_34 , V_33 ) ;
V_2 = V_32 -> V_35 ;
if ( ! V_2 || ! F_23 ( & V_2 -> V_36 ) )
V_2 = NULL ;
F_24 ( V_32 -> V_34 , V_33 ) ;
return V_2 ;
}
int F_25 ( struct V_31 * V_32 , T_1 V_37 , void * V_38 )
{
struct V_1 * V_2 ;
int V_24 = V_39 ;
V_2 = F_21 ( V_32 ) ;
if ( ! V_2 ) {
if ( V_37 )
V_37 ( V_38 , V_24 ) ;
return V_24 ;
}
if ( ! V_2 -> V_19 )
goto V_40;
V_24 = V_41 ;
if ( V_2 -> V_42 == V_43 ||
V_2 -> V_42 == V_44 )
goto V_40;
V_24 = V_45 ;
if ( V_2 -> V_42 == V_46 )
goto V_40;
if ( V_2 -> V_19 -> V_47 )
V_24 = V_2 -> V_19 -> V_47 ( V_2 , V_37 , V_38 ) ;
V_48:
F_26 ( & V_2 -> V_36 ) ;
return V_24 ;
V_40:
if ( V_37 )
V_37 ( V_38 , V_24 ) ;
goto V_48;
}
int F_27 ( struct V_31 * V_32 , const char * V_49 )
{
struct V_1 * V_2 ;
int V_24 = - V_39 ;
V_2 = F_21 ( V_32 ) ;
if ( ! V_2 )
return V_24 ;
if ( V_2 -> V_19 && V_2 -> V_19 -> V_50 )
V_24 = V_2 -> V_19 -> V_50 ( V_2 , V_49 ) ;
F_26 ( & V_2 -> V_36 ) ;
return V_24 ;
}
int F_28 ( struct V_31 * V_32 , const char * V_9 )
{
struct V_1 * V_2 ;
struct V_8 * V_14 ;
int V_24 = 0 ;
V_2 = F_21 ( V_32 ) ;
if ( ! V_2 )
return - V_30 ;
V_14 = F_7 ( V_9 ) ;
if ( ! V_14 ) {
V_24 = - V_16 ;
goto V_48;
}
if ( V_2 -> V_19 ) {
if ( V_2 -> V_19 != V_14 )
V_24 = - V_25 ;
goto V_48;
}
V_24 = F_9 ( V_2 , V_14 ) ;
V_48:
F_26 ( & V_2 -> V_36 ) ;
return V_24 ;
}
const char * F_29 ( struct V_31 * V_32 , T_2 V_51 )
{
struct V_1 * V_2 ;
const char * V_52 = NULL ;
V_2 = F_21 ( V_32 ) ;
if ( ! V_2 )
return NULL ;
if ( V_2 -> V_19 )
V_52 = F_30 ( V_2 -> V_19 -> V_9 , V_51 ) ;
F_26 ( & V_2 -> V_36 ) ;
return V_52 ;
}
