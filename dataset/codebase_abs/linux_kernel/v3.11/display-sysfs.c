static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = NULL ;
F_2 (dssdev) {
if ( V_4 -> V_3 == V_3 ) {
F_3 ( V_4 ) ;
return V_4 ;
}
}
return NULL ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_8 , L_1 ,
V_4 -> V_9 ?
V_4 -> V_9 : L_2 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_8 , L_3 ,
F_6 ( V_4 ) ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
struct V_5 * V_6 ,
const char * V_7 , T_2 V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 ;
bool V_12 ;
V_11 = F_8 ( V_7 , & V_12 ) ;
if ( V_11 )
return V_11 ;
if ( V_12 == F_6 ( V_4 ) )
return V_10 ;
if ( F_9 ( V_4 ) == false )
return - V_13 ;
if ( V_12 ) {
V_11 = V_4 -> V_14 -> V_12 ( V_4 ) ;
if ( V_11 )
return V_11 ;
} else {
V_4 -> V_14 -> V_15 ( V_4 ) ;
}
return V_10 ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return snprintf ( V_7 , V_8 , L_3 ,
V_4 -> V_14 -> V_16 ?
V_4 -> V_14 -> V_16 ( V_4 ) : 0 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_2 V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 ;
bool V_17 ;
if ( ! V_4 -> V_14 -> V_18 || ! V_4 -> V_14 -> V_16 )
return - V_19 ;
V_11 = F_8 ( V_7 , & V_17 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_4 -> V_14 -> V_18 ( V_4 , V_17 ) ;
if ( V_11 )
return V_11 ;
return V_10 ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 V_21 ;
if ( ! V_4 -> V_14 -> V_22 )
return - V_19 ;
V_4 -> V_14 -> V_22 ( V_4 , & V_21 ) ;
return snprintf ( V_7 , V_8 , L_4 ,
V_21 . V_23 ,
V_21 . V_24 , V_21 . V_25 , V_21 . V_26 , V_21 . V_27 ,
V_21 . V_28 , V_21 . V_29 , V_21 . V_30 , V_21 . V_31 ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_2 V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_20 V_21 = V_4 -> V_32 . V_33 ;
int V_11 , V_34 ;
if ( ! V_4 -> V_14 -> V_35 || ! V_4 -> V_14 -> V_36 )
return - V_19 ;
V_34 = 0 ;
#ifdef F_14
if ( strncmp ( L_5 , V_7 , 3 ) == 0 ) {
V_21 = V_37 ;
V_34 = 1 ;
} else if ( strncmp ( L_6 , V_7 , 4 ) == 0 ) {
V_21 = V_38 ;
V_34 = 1 ;
}
#endif
if ( ! V_34 && sscanf ( V_7 , L_7 ,
& V_21 . V_23 ,
& V_21 . V_24 , & V_21 . V_25 , & V_21 . V_26 , & V_21 . V_27 ,
& V_21 . V_28 , & V_21 . V_29 , & V_21 . V_30 , & V_21 . V_31 ) != 9 )
return - V_39 ;
V_11 = V_4 -> V_14 -> V_36 ( V_4 , & V_21 ) ;
if ( V_11 )
return V_11 ;
V_4 -> V_14 -> V_15 ( V_4 ) ;
V_4 -> V_14 -> V_35 ( V_4 , & V_21 ) ;
V_11 = V_4 -> V_14 -> V_12 ( V_4 ) ;
if ( V_11 )
return V_11 ;
return V_10 ;
}
static T_1 F_15 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_40 ;
if ( ! V_4 -> V_14 -> V_41 )
return - V_19 ;
V_40 = V_4 -> V_14 -> V_41 ( V_4 ) ;
return snprintf ( V_7 , V_8 , L_8 , V_40 ) ;
}
static T_1 F_16 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_2 V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_42 , V_11 ;
if ( ! V_4 -> V_14 -> V_43 || ! V_4 -> V_14 -> V_41 )
return - V_19 ;
V_11 = F_17 ( V_7 , 0 , & V_42 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_4 -> V_14 -> V_43 ( V_4 , V_42 ) ;
if ( V_11 )
return V_11 ;
return V_10 ;
}
static T_1 F_18 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_44 ;
if ( ! V_4 -> V_14 -> V_45 )
return - V_19 ;
V_44 = V_4 -> V_14 -> V_45 ( V_4 ) ;
return snprintf ( V_7 , V_8 , L_8 , V_44 ) ;
}
static T_1 F_19 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_2 V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_11 ;
bool V_44 ;
if ( ! V_4 -> V_14 -> V_46 || ! V_4 -> V_14 -> V_45 )
return - V_19 ;
V_11 = F_8 ( V_7 , & V_44 ) ;
if ( V_11 )
return V_11 ;
V_11 = V_4 -> V_14 -> V_46 ( V_4 , V_44 ) ;
if ( V_11 )
return V_11 ;
return V_10 ;
}
static T_1 F_20 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
unsigned int V_47 ;
if ( ! V_4 -> V_14 -> V_48 )
return - V_19 ;
V_47 = V_4 -> V_14 -> V_48 ( V_4 ) ;
return snprintf ( V_7 , V_8 , L_9 , V_47 ) ;
}
static T_1 F_21 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_2 V_10 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_3 V_47 ;
int V_11 ;
if ( ! V_4 -> V_14 -> V_48 || ! V_4 -> V_14 -> V_49 )
return - V_19 ;
V_11 = F_22 ( V_7 , 0 , & V_47 ) ;
if ( V_11 )
return V_11 ;
if ( V_47 > 0xfffff )
return - V_39 ;
V_11 = V_4 -> V_14 -> V_49 ( V_4 , V_47 ) ;
if ( V_11 )
return V_11 ;
return V_10 ;
}
int F_23 ( struct V_50 * V_51 )
{
struct V_1 * V_4 = NULL ;
int V_11 ;
F_2 (dssdev) {
struct V_52 * V_53 = & V_4 -> V_3 -> V_53 ;
V_11 = F_24 ( V_53 , V_54 ) ;
if ( V_11 ) {
F_25 ( L_10 ) ;
goto V_55;
}
V_11 = F_26 ( & V_51 -> V_3 . V_53 , V_53 , V_4 -> V_56 ) ;
if ( V_11 ) {
F_27 ( V_53 , V_54 ) ;
F_25 ( L_11 ) ;
goto V_55;
}
}
return 0 ;
V_55:
F_28 ( V_51 ) ;
return V_11 ;
}
void F_28 ( struct V_50 * V_51 )
{
struct V_1 * V_4 = NULL ;
F_2 (dssdev) {
F_29 ( & V_51 -> V_3 . V_53 , V_4 -> V_56 ) ;
F_27 ( & V_4 -> V_3 -> V_53 ,
V_54 ) ;
}
}
