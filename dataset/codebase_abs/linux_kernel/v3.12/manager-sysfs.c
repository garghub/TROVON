static T_1 F_1 ( struct V_1 * V_2 , char * V_3 )
{
return snprintf ( V_3 , V_4 , L_1 , V_2 -> V_5 ) ;
}
static T_1 F_2 ( struct V_1 * V_2 , char * V_3 )
{
struct V_6 * V_7 = V_2 -> V_8 ( V_2 ) ;
return snprintf ( V_3 , V_4 , L_1 , V_7 ?
V_7 -> V_5 : L_2 ) ;
}
int F_3 ( struct V_6 * V_7 , void * V_9 )
{
const char * V_10 = V_9 ;
return F_4 ( V_7 -> V_5 , V_10 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_3 , V_12 . V_14 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
T_3 V_16 ;
int V_17 ;
V_17 = F_7 ( V_3 , 0 , & V_16 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_14 = V_16 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
char * V_3 )
{
enum V_20 V_21 ;
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_21 = V_12 . V_22 ;
F_9 ( V_21 >= F_10 ( V_23 ) ) ;
return snprintf ( V_3 , V_4 , L_1 , V_23 [ V_21 ] ) ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
enum V_20 V_21 ;
struct V_11 V_12 ;
int V_17 ;
for ( V_21 = V_24 ;
V_21 < F_10 ( V_23 ) ; V_21 ++ ) {
if ( F_4 ( V_3 , V_23 [ V_21 ] ) )
break;
}
if ( V_21 == F_10 ( V_23 ) )
return - V_25 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_22 = V_21 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_3 , V_12 . V_26 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
T_3 V_27 ;
int V_17 ;
V_17 = F_7 ( V_3 , 0 , & V_27 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_26 = V_27 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_12 . V_28 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
bool V_29 ;
int V_17 ;
V_17 = F_16 ( V_3 , & V_29 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_28 = V_29 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_17 (
struct V_1 * V_2 , char * V_3 )
{
struct V_11 V_12 ;
if( ! F_18 ( V_30 ) )
return - V_31 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_4 ,
V_12 . V_32 ) ;
}
static T_1 F_19 (
struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
bool V_29 ;
int V_17 ;
if( ! F_18 ( V_30 ) )
return - V_31 ;
V_17 = F_16 ( V_3 , & V_29 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_32 = V_29 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_20 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 , L_4 , V_12 . V_33 ) ;
}
static T_1 F_21 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
int V_17 ;
bool V_29 ;
if ( ! F_18 ( V_34 ) )
return - V_31 ;
V_17 = F_16 ( V_3 , & V_29 ) ;
if ( V_17 )
return V_17 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
if ( V_12 . V_33 == V_29 )
return V_15 ;
V_12 . V_33 = V_29 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_22 ( struct V_1 * V_2 ,
char * V_3 )
{
struct V_11 V_12 ;
V_2 -> V_13 ( V_2 , & V_12 ) ;
return snprintf ( V_3 , V_4 ,
L_5 ,
V_12 . V_35 . V_36 ,
V_12 . V_35 . V_37 ,
V_12 . V_35 . V_38 ,
V_12 . V_35 . V_39 ,
V_12 . V_35 . V_40 ,
V_12 . V_35 . V_41 ,
V_12 . V_35 . V_42 ,
V_12 . V_35 . V_43 ,
V_12 . V_35 . V_44 ) ;
}
static T_1 F_23 ( struct V_1 * V_2 ,
const char * V_3 , T_2 V_15 )
{
struct V_11 V_12 ;
struct V_45 V_46 ;
int V_17 , V_47 ;
T_4 * V_48 ;
if ( ! F_18 ( V_34 ) )
return - V_31 ;
if ( sscanf ( V_3 , L_6 ,
& V_46 . V_36 , & V_46 . V_37 , & V_46 . V_38 ,
& V_46 . V_39 , & V_46 . V_40 , & V_46 . V_41 ,
& V_46 . V_42 , & V_46 . V_43 , & V_46 . V_44 ) != 9 )
return - V_25 ;
V_48 = ( T_4 [] ) { V_46 . V_36 , V_46 . V_37 , V_46 . V_38 ,
V_46 . V_39 , V_46 . V_40 , V_46 . V_41 ,
V_46 . V_42 , V_46 . V_43 , V_46 . V_44 } ;
for ( V_47 = 0 ; V_47 < 9 ; ++ V_47 ) {
if ( V_48 [ V_47 ] < - 512 || V_48 [ V_47 ] > 511 )
return - V_25 ;
}
V_2 -> V_13 ( V_2 , & V_12 ) ;
V_12 . V_35 = V_46 ;
V_17 = V_2 -> V_18 ( V_2 , & V_12 ) ;
if ( V_17 )
return V_17 ;
V_17 = V_2 -> V_19 ( V_2 ) ;
if ( V_17 )
return V_17 ;
return V_15 ;
}
static T_1 F_24 ( struct V_49 * V_50 , struct V_51 * V_52 ,
char * V_3 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_25 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_25 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_56 )
return - V_57 ;
return V_55 -> V_56 ( V_53 , V_3 ) ;
}
static T_1 F_26 ( struct V_49 * V_50 , struct V_51 * V_52 ,
const char * V_3 , T_2 V_15 )
{
struct V_1 * V_53 ;
struct V_54 * V_55 ;
V_53 = F_25 ( V_50 , struct V_1 , V_50 ) ;
V_55 = F_25 ( V_52 , struct V_54 , V_52 ) ;
if ( ! V_55 -> V_58 )
return - V_57 ;
return V_55 -> V_58 ( V_53 , V_3 , V_15 ) ;
}
int F_27 ( struct V_1 * V_2 ,
struct V_59 * V_60 )
{
return F_28 ( & V_2 -> V_50 , & V_61 ,
& V_60 -> V_62 . V_50 , L_7 , V_2 -> V_63 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( & V_2 -> V_50 ) ;
F_31 ( & V_2 -> V_50 ) ;
memset ( & V_2 -> V_50 , 0 , sizeof( V_2 -> V_50 ) ) ;
}
