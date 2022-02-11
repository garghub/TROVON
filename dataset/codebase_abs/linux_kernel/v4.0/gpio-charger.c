static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static inline struct V_6 * F_3 ( struct V_3 * V_7 )
{
return F_4 ( V_7 , struct V_6 , V_4 ) ;
}
static int F_5 ( struct V_3 * V_7 ,
enum V_8 V_9 , union V_10 * V_11 )
{
struct V_6 * V_6 = F_3 ( V_7 ) ;
const struct V_12 * V_13 = V_6 -> V_13 ;
switch ( V_9 ) {
case V_14 :
V_11 -> V_15 = ! ! F_6 ( V_13 -> V_16 ) ;
V_11 -> V_15 ^= V_13 -> V_17 ;
break;
default:
return - V_18 ;
}
return 0 ;
}
static
struct V_12 * F_7 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_12 * V_13 ;
const char * V_24 ;
enum V_25 V_26 ;
int V_27 ;
if ( ! V_22 )
return F_8 ( - V_28 ) ;
V_13 = F_9 ( V_20 , sizeof( * V_13 ) , V_29 ) ;
if ( ! V_13 )
return F_8 ( - V_30 ) ;
V_13 -> V_31 = V_22 -> V_31 ;
V_13 -> V_16 = F_10 ( V_22 , 0 , & V_26 ) ;
if ( V_13 -> V_16 < 0 ) {
if ( V_13 -> V_16 != - V_32 )
F_11 ( V_20 , L_1 ) ;
return F_8 ( V_13 -> V_16 ) ;
}
V_13 -> V_17 = ! ! ( V_26 & V_33 ) ;
V_13 -> type = V_34 ;
V_27 = F_12 ( V_22 , L_2 , & V_24 ) ;
if ( V_27 >= 0 ) {
if ( ! strncmp ( L_3 , V_24 , 7 ) )
V_13 -> type = V_34 ;
else if ( ! strncmp ( L_4 , V_24 , 7 ) )
V_13 -> type = V_35 ;
else if ( ! strncmp ( L_5 , V_24 , 3 ) )
V_13 -> type = V_36 ;
else if ( ! strncmp ( L_6 , V_24 , 5 ) )
V_13 -> type = V_37 ;
else if ( ! strncmp ( L_7 , V_24 , 7 ) )
V_13 -> type = V_38 ;
else if ( ! strncmp ( L_8 , V_24 , 7 ) )
V_13 -> type = V_39 ;
else if ( ! strncmp ( L_9 , V_24 , 7 ) )
V_13 -> type = V_40 ;
else if ( ! strncmp ( L_10 , V_24 , 7 ) )
V_13 -> type = V_41 ;
else
F_13 ( V_20 , L_11 , V_24 ) ;
}
return V_13 ;
}
static int F_14 ( struct V_42 * V_43 )
{
const struct V_12 * V_13 = V_43 -> V_20 . V_44 ;
struct V_6 * V_6 ;
struct V_3 * V_4 ;
int V_27 ;
int V_1 ;
if ( ! V_13 ) {
V_13 = F_7 ( & V_43 -> V_20 ) ;
if ( F_15 ( V_13 ) ) {
V_27 = F_16 ( V_13 ) ;
if ( V_27 != - V_32 )
F_11 ( & V_43 -> V_20 , L_12 ) ;
return V_27 ;
}
}
if ( ! F_17 ( V_13 -> V_16 ) ) {
F_11 ( & V_43 -> V_20 , L_13 ) ;
return - V_18 ;
}
V_6 = F_9 ( & V_43 -> V_20 , sizeof( * V_6 ) ,
V_29 ) ;
if ( ! V_6 ) {
F_11 ( & V_43 -> V_20 , L_14 ) ;
return - V_30 ;
}
V_4 = & V_6 -> V_4 ;
V_4 -> V_31 = V_13 -> V_31 ? V_13 -> V_31 : L_15 ;
V_4 -> type = V_13 -> type ;
V_4 -> V_45 = V_46 ;
V_4 -> V_47 = F_18 ( V_46 ) ;
V_4 -> V_48 = F_5 ;
V_4 -> V_49 = V_13 -> V_49 ;
V_4 -> V_50 = V_13 -> V_50 ;
V_4 -> V_23 = V_43 -> V_20 . V_23 ;
V_27 = F_19 ( V_13 -> V_16 , F_20 ( & V_43 -> V_20 ) ) ;
if ( V_27 ) {
F_11 ( & V_43 -> V_20 , L_16 , V_27 ) ;
goto V_51;
}
V_27 = F_21 ( V_13 -> V_16 ) ;
if ( V_27 ) {
F_11 ( & V_43 -> V_20 , L_17 , V_27 ) ;
goto V_52;
}
V_6 -> V_13 = V_13 ;
V_27 = F_22 ( & V_43 -> V_20 , V_4 ) ;
if ( V_27 < 0 ) {
F_11 ( & V_43 -> V_20 , L_18 ,
V_27 ) ;
goto V_52;
}
V_1 = F_23 ( V_13 -> V_16 ) ;
if ( V_1 > 0 ) {
V_27 = F_24 ( V_1 , F_1 ,
V_53 | V_54 ,
F_20 ( & V_43 -> V_20 ) , V_4 ) ;
if ( V_27 < 0 )
F_13 ( & V_43 -> V_20 , L_19 , V_27 ) ;
else
V_6 -> V_1 = V_1 ;
}
F_25 ( V_43 , V_6 ) ;
F_26 ( & V_43 -> V_20 , 1 ) ;
return 0 ;
V_52:
F_27 ( V_13 -> V_16 ) ;
V_51:
return V_27 ;
}
static int F_28 ( struct V_42 * V_43 )
{
struct V_6 * V_6 = F_29 ( V_43 ) ;
if ( V_6 -> V_1 )
F_30 ( V_6 -> V_1 , & V_6 -> V_4 ) ;
F_31 ( & V_6 -> V_4 ) ;
F_27 ( V_6 -> V_13 -> V_16 ) ;
return 0 ;
}
static int F_32 ( struct V_19 * V_20 )
{
struct V_6 * V_6 = F_33 ( V_20 ) ;
if ( F_34 ( V_20 ) )
V_6 -> V_55 =
! F_35 ( V_6 -> V_1 ) ;
return 0 ;
}
static int F_36 ( struct V_19 * V_20 )
{
struct V_42 * V_43 = F_37 ( V_20 ) ;
struct V_6 * V_6 = F_29 ( V_43 ) ;
if ( F_34 ( V_20 ) && V_6 -> V_55 )
F_38 ( V_6 -> V_1 ) ;
F_2 ( & V_6 -> V_4 ) ;
return 0 ;
}
