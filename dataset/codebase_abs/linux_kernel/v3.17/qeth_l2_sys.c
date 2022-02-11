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
F_3 ( & V_8 -> V_15 ) ;
if ( F_4 ( V_8 ) &&
V_8 -> V_16 . V_17 . V_18 )
V_12 = F_5 ( V_8 ,
& V_8 -> V_16 . V_17 . V_19 , & V_10 ) ;
if ( ! V_12 ) {
if ( V_6 )
switch ( V_10 ) {
case V_11 :
V_13 = L_1 ; break;
case V_20 :
V_13 = L_2 ; break;
case V_21 :
V_13 = L_3 ; break;
default:
V_12 = - V_22 ;
}
else
switch ( V_8 -> V_16 . V_17 . V_19 ) {
case V_23 :
V_13 = L_4 ; break;
case V_24 :
V_13 = L_5 ; break;
case V_25 :
V_13 = L_6 ; break;
default:
V_12 = - V_22 ;
}
if ( V_12 )
F_6 ( V_8 , 2 , L_7 ,
V_8 -> V_16 . V_17 . V_19 , V_10 ) ;
else
V_12 = sprintf ( V_5 , L_8 , V_13 ) ;
}
F_7 ( & V_8 -> V_15 ) ;
return V_12 ;
}
static T_1 F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
return F_1 ( V_2 , V_4 , V_5 , 0 ) ;
}
static T_1 F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_26 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_12 = 0 ;
enum V_27 V_19 ;
if ( ! V_8 )
return - V_14 ;
if ( F_10 ( V_5 , L_5 ) )
V_19 = V_24 ;
else if ( F_10 ( V_5 , L_6 ) )
V_19 = V_25 ;
else if ( F_10 ( V_5 , L_4 ) )
V_19 = V_23 ;
else
return - V_14 ;
F_3 ( & V_8 -> V_15 ) ;
if ( F_4 ( V_8 ) ) {
V_12 = F_11 ( V_8 , V_19 ) ;
if ( ! V_12 )
V_8 -> V_16 . V_17 . V_19 = V_19 ;
} else
V_8 -> V_16 . V_17 . V_19 = V_19 ;
F_7 ( & V_8 -> V_15 ) ;
return V_12 ? V_12 : V_26 ;
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
int V_28 ;
if ( ! V_8 )
return - V_14 ;
F_3 ( & V_8 -> V_15 ) ;
V_28 = V_8 -> V_16 . V_17 . V_29 ;
F_7 ( & V_8 -> V_15 ) ;
return sprintf ( V_5 , L_9 , V_28 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 , const char * V_5 , T_2 V_26 )
{
struct V_7 * V_8 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_30 ;
if ( ! V_8 )
return - V_14 ;
if ( F_10 ( V_5 , L_10 ) )
V_30 = 0 ;
else if ( F_10 ( V_5 , L_11 ) )
V_30 = 1 ;
else
return - V_14 ;
F_3 ( & V_8 -> V_15 ) ;
if ( F_4 ( V_8 ) ) {
V_12 = F_15 ( V_8 , V_30 ) ;
if ( ! V_12 )
V_8 -> V_16 . V_17 . V_29 = V_30 ;
} else
V_8 -> V_16 . V_17 . V_29 = V_30 ;
F_7 ( & V_8 -> V_15 ) ;
return V_12 ? V_12 : V_26 ;
}
int F_16 ( struct V_1 * V_2 )
{
return F_17 ( & V_2 -> V_31 , & V_32 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
F_19 ( & V_2 -> V_31 , & V_32 ) ;
}
void F_20 ( struct V_7 * V_8 )
{
int V_12 ;
if ( ! V_8 )
return;
if ( ! V_8 -> V_16 . V_17 . V_18 )
return;
if ( V_8 -> V_16 . V_17 . V_19 != V_23 ) {
F_11 ( V_8 , V_8 -> V_16 . V_17 . V_19 ) ;
F_5 ( V_8 ,
& V_8 -> V_16 . V_17 . V_19 , NULL ) ;
}
if ( V_8 -> V_16 . V_17 . V_29 ) {
V_12 = F_15 ( V_8 , 1 ) ;
if ( V_12 )
V_8 -> V_16 . V_17 . V_29 = 0 ;
} else
F_15 ( V_8 , 0 ) ;
}
