static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 ,
V_2 -> V_5 ?
V_2 -> V_5 : L_2 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 ,
F_3 ( V_2 ) ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_6 )
{
int V_7 ;
bool V_8 ;
V_7 = F_5 ( V_3 , & V_8 ) ;
if ( V_7 )
return V_7 ;
if ( V_8 == F_3 ( V_2 ) )
return V_6 ;
if ( F_6 ( V_2 ) == false )
return - V_9 ;
if ( V_8 ) {
V_7 = V_2 -> V_10 -> V_8 ( V_2 ) ;
if ( V_7 )
return V_7 ;
} else {
V_2 -> V_10 -> V_11 ( V_2 ) ;
}
return V_6 ;
}
static T_1 F_7 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_3 ,
V_2 -> V_10 -> V_12 ?
V_2 -> V_10 -> V_12 ( V_2 ) : 0 ) ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_6 )
{
int V_7 ;
bool V_13 ;
if ( ! V_2 -> V_10 -> V_14 || ! V_2 -> V_10 -> V_12 )
return - V_15 ;
V_7 = F_5 ( V_3 , & V_13 ) ;
if ( V_7 )
return V_7 ;
V_7 = V_2 -> V_10 -> V_14 ( V_2 , V_13 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static T_1 F_9 ( struct V_1 * V_2 , char * V_3 )
{
struct V_16 V_17 ;
if ( ! V_2 -> V_10 -> V_18 )
return - V_15 ;
V_2 -> V_10 -> V_18 ( V_2 , & V_17 ) ;
return snprintf ( V_3 , V_4 , L_4 ,
V_17 . V_19 ,
V_17 . V_20 , V_17 . V_21 , V_17 . V_22 , V_17 . V_23 ,
V_17 . V_24 , V_17 . V_25 , V_17 . V_26 , V_17 . V_27 ) ;
}
static T_1 F_10 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_6 )
{
struct V_16 V_17 = V_2 -> V_28 . V_29 ;
int V_7 , V_30 ;
if ( ! V_2 -> V_10 -> V_31 || ! V_2 -> V_10 -> V_32 )
return - V_15 ;
V_30 = 0 ;
#ifdef F_11
if ( strncmp ( L_5 , V_3 , 3 ) == 0 ) {
V_17 = V_33 ;
V_30 = 1 ;
} else if ( strncmp ( L_6 , V_3 , 4 ) == 0 ) {
V_17 = V_34 ;
V_30 = 1 ;
}
#endif
if ( ! V_30 && sscanf ( V_3 , L_7 ,
& V_17 . V_19 ,
& V_17 . V_20 , & V_17 . V_21 , & V_17 . V_22 , & V_17 . V_23 ,
& V_17 . V_24 , & V_17 . V_25 , & V_17 . V_26 , & V_17 . V_27 ) != 9 )
return - V_35 ;
V_7 = V_2 -> V_10 -> V_32 ( V_2 , & V_17 ) ;
if ( V_7 )
return V_7 ;
V_2 -> V_10 -> V_11 ( V_2 ) ;
V_2 -> V_10 -> V_31 ( V_2 , & V_17 ) ;
V_7 = V_2 -> V_10 -> V_8 ( V_2 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static T_1 F_12 ( struct V_1 * V_2 , char * V_3 )
{
int V_36 ;
if ( ! V_2 -> V_10 -> V_37 )
return - V_15 ;
V_36 = V_2 -> V_10 -> V_37 ( V_2 ) ;
return snprintf ( V_3 , V_4 , L_8 , V_36 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_6 )
{
int V_38 , V_7 ;
if ( ! V_2 -> V_10 -> V_39 || ! V_2 -> V_10 -> V_37 )
return - V_15 ;
V_7 = F_14 ( V_3 , 0 , & V_38 ) ;
if ( V_7 )
return V_7 ;
V_7 = V_2 -> V_10 -> V_39 ( V_2 , V_38 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static T_1 F_15 ( struct V_1 * V_2 , char * V_3 )
{
int V_40 ;
if ( ! V_2 -> V_10 -> V_41 )
return - V_15 ;
V_40 = V_2 -> V_10 -> V_41 ( V_2 ) ;
return snprintf ( V_3 , V_4 , L_8 , V_40 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_6 )
{
int V_7 ;
bool V_40 ;
if ( ! V_2 -> V_10 -> V_42 || ! V_2 -> V_10 -> V_41 )
return - V_15 ;
V_7 = F_5 ( V_3 , & V_40 ) ;
if ( V_7 )
return V_7 ;
V_7 = V_2 -> V_10 -> V_42 ( V_2 , V_40 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static T_1 F_17 ( struct V_1 * V_2 , char * V_3 )
{
unsigned int V_43 ;
if ( ! V_2 -> V_10 -> V_44 )
return - V_15 ;
V_43 = V_2 -> V_10 -> V_44 ( V_2 ) ;
return snprintf ( V_3 , V_4 , L_9 , V_43 ) ;
}
static T_1 F_18 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_6 )
{
T_3 V_43 ;
int V_7 ;
if ( ! V_2 -> V_10 -> V_44 || ! V_2 -> V_10 -> V_45 )
return - V_15 ;
V_7 = F_19 ( V_3 , 0 , & V_43 ) ;
if ( V_7 )
return V_7 ;
if ( V_43 > 0xfffff )
return - V_35 ;
V_7 = V_2 -> V_10 -> V_45 ( V_2 , V_43 ) ;
if ( V_7 )
return V_7 ;
return V_6 ;
}
static T_1 F_20 ( struct V_46 * V_47 , struct V_48 * V_49 ,
char * V_3 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_2 = F_21 ( V_47 , struct V_1 , V_47 ) ;
V_51 = F_21 ( V_49 , struct V_50 , V_49 ) ;
if ( ! V_51 -> V_52 )
return - V_15 ;
return V_51 -> V_52 ( V_2 , V_3 ) ;
}
static T_1 F_22 ( struct V_46 * V_47 , struct V_48 * V_49 ,
const char * V_3 , T_2 V_6 )
{
struct V_1 * V_2 ;
struct V_50 * V_51 ;
V_2 = F_21 ( V_47 , struct V_1 , V_47 ) ;
V_51 = F_21 ( V_49 , struct V_50 , V_49 ) ;
if ( ! V_51 -> V_53 )
return - V_15 ;
return V_51 -> V_53 ( V_2 , V_3 , V_6 ) ;
}
int F_23 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = NULL ;
int V_7 ;
F_24 (dssdev) {
V_7 = F_25 ( & V_2 -> V_47 , & V_56 ,
& V_55 -> V_57 . V_47 , L_10 , V_2 -> V_58 ) ;
if ( V_7 ) {
F_26 ( L_11 ) ;
F_27 ( V_2 ) ;
goto V_59;
}
}
return 0 ;
V_59:
F_28 ( V_55 ) ;
return V_7 ;
}
void F_28 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = NULL ;
F_24 (dssdev) {
if ( F_29 ( & V_2 -> V_47 ) == NULL )
continue;
F_30 ( & V_2 -> V_47 ) ;
F_31 ( & V_2 -> V_47 ) ;
memset ( & V_2 -> V_47 , 0 , sizeof( V_2 -> V_47 ) ) ;
}
}
