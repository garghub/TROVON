static T_1 F_1 ( int V_1 , void * V_2 )
{
struct V_3 * V_4 = V_2 ;
F_2 ( V_4 ) ;
return V_5 ;
}
static inline struct V_6 * F_3 ( struct V_3 * V_7 )
{
return F_4 ( V_7 ) ;
}
static int F_5 ( struct V_3 * V_7 ,
enum V_8 V_9 , union V_10 * V_11 )
{
struct V_6 * V_6 = F_3 ( V_7 ) ;
const struct V_12 * V_13 = V_6 -> V_13 ;
switch ( V_9 ) {
case V_14 :
V_11 -> V_15 = F_6 ( V_6 -> V_16 ) ;
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
int V_25 ;
if ( ! V_22 )
return F_8 ( - V_26 ) ;
V_13 = F_9 ( V_20 , sizeof( * V_13 ) , V_27 ) ;
if ( ! V_13 )
return F_8 ( - V_28 ) ;
V_13 -> V_29 = V_22 -> V_29 ;
V_13 -> type = V_30 ;
V_25 = F_10 ( V_22 , L_1 , & V_24 ) ;
if ( V_25 >= 0 ) {
if ( ! strncmp ( L_2 , V_24 , 7 ) )
V_13 -> type = V_30 ;
else if ( ! strncmp ( L_3 , V_24 , 7 ) )
V_13 -> type = V_31 ;
else if ( ! strncmp ( L_4 , V_24 , 3 ) )
V_13 -> type = V_32 ;
else if ( ! strncmp ( L_5 , V_24 , 5 ) )
V_13 -> type = V_33 ;
else if ( ! strncmp ( L_6 , V_24 , 7 ) )
V_13 -> type = V_34 ;
else if ( ! strncmp ( L_7 , V_24 , 7 ) )
V_13 -> type = V_35 ;
else if ( ! strncmp ( L_8 , V_24 , 7 ) )
V_13 -> type = V_36 ;
else if ( ! strncmp ( L_9 , V_24 , 7 ) )
V_13 -> type = V_37 ;
else
F_11 ( V_20 , L_10 , V_24 ) ;
}
return V_13 ;
}
static int F_12 ( struct V_38 * V_39 )
{
const struct V_12 * V_13 = V_39 -> V_20 . V_40 ;
struct V_41 V_42 = {} ;
struct V_6 * V_6 ;
struct V_43 * V_44 ;
int V_25 ;
int V_1 ;
if ( ! V_13 ) {
V_13 = F_7 ( & V_39 -> V_20 ) ;
if ( F_13 ( V_13 ) ) {
V_25 = F_14 ( V_13 ) ;
if ( V_25 != - V_45 )
F_15 ( & V_39 -> V_20 , L_11 ) ;
return V_25 ;
}
}
V_6 = F_9 ( & V_39 -> V_20 , sizeof( * V_6 ) ,
V_27 ) ;
if ( ! V_6 ) {
F_15 ( & V_39 -> V_20 , L_12 ) ;
return - V_28 ;
}
V_6 -> V_16 = F_16 ( & V_39 -> V_20 , NULL , V_46 ) ;
if ( F_13 ( V_6 -> V_16 ) && ! V_39 -> V_20 . V_23 ) {
if ( ! F_17 ( V_13 -> V_47 ) ) {
F_15 ( & V_39 -> V_20 , L_13 ) ;
return - V_18 ;
}
V_25 = F_18 ( V_13 -> V_47 , F_19 ( & V_39 -> V_20 ) ) ;
if ( V_25 ) {
F_15 ( & V_39 -> V_20 , L_14 ,
V_25 ) ;
return V_25 ;
}
V_6 -> V_48 = true ;
V_25 = F_20 ( V_13 -> V_47 ) ;
if ( V_25 ) {
F_15 ( & V_39 -> V_20 , L_15 ,
V_25 ) ;
goto V_49;
}
V_6 -> V_16 = F_21 ( V_13 -> V_47 ) ;
} else if ( F_13 ( V_6 -> V_16 ) ) {
if ( F_14 ( V_6 -> V_16 ) == - V_45 )
return - V_45 ;
F_15 ( & V_39 -> V_20 , L_16 ) ;
return F_14 ( V_6 -> V_16 ) ;
}
V_44 = & V_6 -> V_44 ;
V_44 -> V_29 = V_13 -> V_29 ? V_13 -> V_29 : L_17 ;
V_44 -> type = V_13 -> type ;
V_44 -> V_50 = V_51 ;
V_44 -> V_52 = F_22 ( V_51 ) ;
V_44 -> V_53 = F_5 ;
V_42 . V_54 = V_13 -> V_54 ;
V_42 . V_55 = V_13 -> V_55 ;
V_42 . V_23 = V_39 -> V_20 . V_23 ;
V_42 . V_56 = V_6 ;
V_6 -> V_13 = V_13 ;
V_6 -> V_4 = F_23 ( & V_39 -> V_20 ,
V_44 , & V_42 ) ;
if ( F_13 ( V_6 -> V_4 ) ) {
V_25 = F_14 ( V_6 -> V_4 ) ;
F_15 ( & V_39 -> V_20 , L_18 ,
V_25 ) ;
goto V_49;
}
V_1 = F_24 ( V_6 -> V_16 ) ;
if ( V_1 > 0 ) {
V_25 = F_25 ( V_1 , F_1 ,
V_57 | V_58 ,
F_19 ( & V_39 -> V_20 ) , V_6 -> V_4 ) ;
if ( V_25 < 0 )
F_11 ( & V_39 -> V_20 , L_19 , V_25 ) ;
else
V_6 -> V_1 = V_1 ;
}
F_26 ( V_39 , V_6 ) ;
F_27 ( & V_39 -> V_20 , 1 ) ;
return 0 ;
V_49:
if ( V_6 -> V_48 )
F_28 ( V_13 -> V_47 ) ;
return V_25 ;
}
static int F_29 ( struct V_38 * V_39 )
{
struct V_6 * V_6 = F_30 ( V_39 ) ;
if ( V_6 -> V_1 )
F_31 ( V_6 -> V_1 , V_6 -> V_4 ) ;
F_32 ( V_6 -> V_4 ) ;
if ( V_6 -> V_48 )
F_28 ( V_6 -> V_13 -> V_47 ) ;
return 0 ;
}
static int F_33 ( struct V_19 * V_20 )
{
struct V_6 * V_6 = F_34 ( V_20 ) ;
if ( F_35 ( V_20 ) )
V_6 -> V_59 =
! F_36 ( V_6 -> V_1 ) ;
return 0 ;
}
static int F_37 ( struct V_19 * V_20 )
{
struct V_38 * V_39 = F_38 ( V_20 ) ;
struct V_6 * V_6 = F_30 ( V_39 ) ;
if ( F_35 ( V_20 ) && V_6 -> V_59 )
F_39 ( V_6 -> V_1 ) ;
F_2 ( V_6 -> V_4 ) ;
return 0 ;
}
