static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 ,
int V_6 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
enum V_9 V_10 = V_11 ;
int V_12 = 0 ;
char * V_13 ;
if ( ! V_8 )
return - V_14 ;
if ( F_3 ( V_8 ) &&
V_8 -> V_15 . V_16 . V_17 )
V_12 = F_4 ( V_8 ,
& V_8 -> V_15 . V_16 . V_18 , & V_10 ) ;
if ( ! V_12 ) {
if ( V_6 )
switch ( V_10 ) {
case V_11 :
V_13 = L_1 ; break;
case V_19 :
V_13 = L_2 ; break;
case V_20 :
V_13 = L_3 ; break;
default:
V_12 = - V_21 ;
}
else
switch ( V_8 -> V_15 . V_16 . V_18 ) {
case V_22 :
V_13 = L_4 ; break;
case V_23 :
V_13 = L_5 ; break;
case V_24 :
V_13 = L_6 ; break;
default:
V_12 = - V_21 ;
}
if ( V_12 )
F_5 ( V_8 , 2 , L_7 ,
V_8 -> V_15 . V_16 . V_18 , V_10 ) ;
else
V_12 = sprintf ( V_5 , L_8 , V_13 ) ;
}
return V_12 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , 0 ) ;
}
static T_1 F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_25 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_12 = 0 ;
enum V_26 V_18 ;
if ( ! V_8 )
return - V_14 ;
if ( F_8 ( V_5 , L_5 ) )
V_18 = V_23 ;
else if ( F_8 ( V_5 , L_6 ) )
V_18 = V_24 ;
else if ( F_8 ( V_5 , L_4 ) )
V_18 = V_22 ;
else
return - V_14 ;
F_9 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_15 . V_16 . V_28 )
V_12 = - V_29 ;
else if ( F_3 ( V_8 ) ) {
V_12 = F_10 ( V_8 , V_18 ) ;
if ( ! V_12 )
V_8 -> V_15 . V_16 . V_18 = V_18 ;
} else
V_8 -> V_15 . V_16 . V_18 = V_18 ;
F_11 ( & V_8 -> V_27 ) ;
return V_12 ? V_12 : V_25 ;
}
static T_1 F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , 1 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_30 ;
if ( ! V_8 )
return - V_14 ;
V_30 = V_8 -> V_15 . V_16 . V_31 ;
return sprintf ( V_5 , L_9 , V_30 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_25 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_32 ;
if ( ! V_8 )
return - V_14 ;
if ( F_8 ( V_5 , L_10 ) )
V_32 = 0 ;
else if ( F_8 ( V_5 , L_11 ) )
V_32 = 1 ;
else
return - V_14 ;
F_9 ( & V_8 -> V_27 ) ;
if ( F_3 ( V_8 ) ) {
V_12 = F_15 ( V_8 , V_32 ) ;
if ( ! V_12 )
V_8 -> V_15 . V_16 . V_31 = V_32 ;
} else
V_8 -> V_15 . V_16 . V_31 = V_32 ;
F_11 ( & V_8 -> V_27 ) ;
return V_12 ? V_12 : V_25 ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
char * V_10 ;
if ( ! V_8 )
return - V_14 ;
if ( V_8 -> V_15 . V_16 . V_28 ) {
if ( V_8 -> V_15 . V_16 . V_33 )
V_10 = L_5 ;
else
V_10 = L_6 ;
} else
V_10 = L_4 ;
return sprintf ( V_5 , L_8 , V_10 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_25 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_32 , V_34 ;
int V_12 = 0 ;
if ( ! V_8 )
return - V_14 ;
if ( F_8 ( V_5 , L_4 ) ) {
V_32 = 0 ;
V_34 = 0 ;
} else if ( F_8 ( V_5 , L_5 ) ) {
V_32 = 1 ;
V_34 = 1 ;
} else if ( F_8 ( V_5 , L_6 ) ) {
V_32 = 1 ;
V_34 = 0 ;
} else
return - V_14 ;
F_9 ( & V_8 -> V_27 ) ;
if ( V_8 -> V_15 . V_16 . V_18 != V_22 )
V_12 = - V_29 ;
else {
V_8 -> V_15 . V_16 . V_28 = V_32 ;
V_8 -> V_15 . V_16 . V_33 = V_34 ;
V_12 = 0 ;
}
F_11 ( & V_8 -> V_27 ) ;
return V_12 ? V_12 : V_25 ;
}
int F_18 ( struct V_1 * V_2 )
{
return F_19 ( & V_2 -> V_35 , & V_36 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_35 , & V_36 ) ;
}
void F_22 ( struct V_7 * V_8 )
{
int V_12 ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_15 . V_16 . V_17 )
return;
if ( V_8 -> V_15 . V_16 . V_18 != V_22 ) {
F_10 ( V_8 , V_8 -> V_15 . V_16 . V_18 ) ;
F_4 ( V_8 ,
& V_8 -> V_15 . V_16 . V_18 , NULL ) ;
}
if ( V_8 -> V_15 . V_16 . V_31 ) {
V_12 = F_15 ( V_8 , 1 ) ;
if ( V_12 )
V_8 -> V_15 . V_16 . V_31 = 0 ;
} else
F_15 ( V_8 , 0 ) ;
}
