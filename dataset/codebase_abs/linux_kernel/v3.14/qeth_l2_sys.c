static int F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 == V_4 ) ||
( V_2 -> V_3 == V_5 ) ;
}
static T_1 F_2 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 ,
int V_11 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
enum V_12 V_3 = V_13 ;
int V_14 = 0 ;
char * V_15 ;
if ( ! V_2 )
return - V_16 ;
F_4 ( & V_2 -> V_17 ) ;
if ( F_1 ( V_2 ) &&
V_2 -> V_18 . V_19 . V_20 )
V_14 = F_5 ( V_2 ,
& V_2 -> V_18 . V_19 . V_21 , & V_3 ) ;
if ( ! V_14 ) {
if ( V_11 )
switch ( V_3 ) {
case V_13 :
V_15 = L_1 ; break;
case V_22 :
V_15 = L_2 ; break;
case V_23 :
V_15 = L_3 ; break;
default:
V_14 = - V_24 ;
}
else
switch ( V_2 -> V_18 . V_19 . V_21 ) {
case V_25 :
V_15 = L_4 ; break;
case V_26 :
V_15 = L_5 ; break;
case V_27 :
V_15 = L_6 ; break;
default:
V_14 = - V_24 ;
}
if ( V_14 )
F_6 ( V_2 , 2 , L_7 ,
V_2 -> V_18 . V_19 . V_21 , V_3 ) ;
else
V_14 = sprintf ( V_10 , L_8 , V_15 ) ;
}
F_7 ( & V_2 -> V_17 ) ;
return V_14 ;
}
static T_1 F_8 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
return F_2 ( V_7 , V_9 , V_10 , 0 ) ;
}
static T_1 F_9 ( struct V_6 * V_7 ,
struct V_8 * V_9 , const char * V_10 , T_2 V_28 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_14 = 0 ;
enum V_29 V_21 ;
if ( ! V_2 )
return - V_16 ;
if ( F_10 ( V_10 , L_5 ) )
V_21 = V_26 ;
else if ( F_10 ( V_10 , L_6 ) )
V_21 = V_27 ;
else if ( F_10 ( V_10 , L_4 ) )
V_21 = V_25 ;
else
return - V_16 ;
F_4 ( & V_2 -> V_17 ) ;
if ( F_1 ( V_2 ) ) {
V_14 = F_11 ( V_2 , V_21 ) ;
if ( ! V_14 )
V_2 -> V_18 . V_19 . V_21 = V_21 ;
} else
V_2 -> V_18 . V_19 . V_21 = V_21 ;
F_7 ( & V_2 -> V_17 ) ;
return V_14 ? V_14 : V_28 ;
}
static T_1 F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
return F_2 ( V_7 , V_9 , V_10 , 1 ) ;
}
static T_1 F_13 ( struct V_6 * V_7 ,
struct V_8 * V_9 , char * V_10 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_30 ;
if ( ! V_2 )
return - V_16 ;
F_4 ( & V_2 -> V_17 ) ;
V_30 = V_2 -> V_18 . V_19 . V_31 ;
F_7 ( & V_2 -> V_17 ) ;
return sprintf ( V_10 , L_9 , V_30 ) ;
}
static T_1 F_14 ( struct V_6 * V_7 ,
struct V_8 * V_9 , const char * V_10 , T_2 V_28 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_14 = 0 ;
int V_32 ;
if ( ! V_2 )
return - V_16 ;
if ( F_10 ( V_10 , L_10 ) )
V_32 = 0 ;
else if ( F_10 ( V_10 , L_11 ) )
V_32 = 1 ;
else
return - V_16 ;
F_4 ( & V_2 -> V_17 ) ;
if ( F_1 ( V_2 ) ) {
V_14 = F_15 ( V_2 , V_32 ) ;
if ( ! V_14 )
V_2 -> V_18 . V_19 . V_31 = V_32 ;
} else
V_2 -> V_18 . V_19 . V_31 = V_32 ;
F_7 ( & V_2 -> V_17 ) ;
return V_14 ? V_14 : V_28 ;
}
int F_16 ( struct V_6 * V_7 )
{
return F_17 ( & V_7 -> V_33 , & V_34 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_33 , & V_34 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
int V_14 ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_18 . V_19 . V_20 )
return;
if ( V_2 -> V_18 . V_19 . V_21 != V_25 ) {
F_11 ( V_2 , V_2 -> V_18 . V_19 . V_21 ) ;
F_5 ( V_2 ,
& V_2 -> V_18 . V_19 . V_21 , NULL ) ;
}
if ( V_2 -> V_18 . V_19 . V_31 ) {
V_14 = F_15 ( V_2 , 1 ) ;
if ( V_14 )
V_2 -> V_18 . V_19 . V_31 = 0 ;
} else
F_15 ( V_2 , 0 ) ;
}
