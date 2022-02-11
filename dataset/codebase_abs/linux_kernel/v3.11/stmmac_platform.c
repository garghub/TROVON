static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
struct V_10 * V_11 ;
if ( ! V_7 )
return - V_12 ;
* V_5 = F_2 ( V_7 ) ;
V_4 -> V_13 = F_3 ( V_7 ) ;
V_4 -> V_14 = F_4 ( V_7 , L_1 ) ;
if ( V_4 -> V_14 < 0 )
V_4 -> V_14 = 0 ;
F_5 ( V_7 , L_2 , & V_4 -> V_15 ) ;
V_4 -> V_16 = F_6 ( & V_2 -> V_8 ,
sizeof( struct V_17 ) ,
V_18 ) ;
if ( F_7 ( V_7 , L_3 ) ||
F_7 ( V_7 , L_4 ) ||
F_7 ( V_7 , L_5 ) ) {
V_4 -> V_19 = 1 ;
V_4 -> V_20 = 1 ;
}
if ( F_7 ( V_7 , L_6 ) ||
F_7 ( V_7 , L_7 ) ) {
V_4 -> V_21 = 1 ;
V_4 -> V_22 = 1 ;
V_4 -> V_23 = 1 ;
}
if ( F_8 ( V_7 , L_8 , NULL ) ) {
V_11 = F_6 ( & V_2 -> V_8 , sizeof( * V_11 ) ,
V_18 ) ;
if ( ! V_11 )
return - V_24 ;
V_4 -> V_11 = V_11 ;
F_5 ( V_7 , L_8 , & V_11 -> V_25 ) ;
V_11 -> V_26 =
F_9 ( V_7 , L_9 ) ;
V_11 -> V_27 =
F_9 ( V_7 , L_10 ) ;
}
return 0 ;
}
static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
return - V_28 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_29 = 0 ;
struct V_30 * V_31 ;
struct V_32 * V_8 = & V_2 -> V_8 ;
void T_1 * V_33 = NULL ;
struct V_34 * V_35 = NULL ;
struct V_3 * V_36 = NULL ;
const char * V_5 = NULL ;
V_31 = F_11 ( V_2 , V_37 , 0 ) ;
if ( ! V_31 )
return - V_12 ;
V_33 = F_12 ( V_8 , V_31 ) ;
if ( F_13 ( V_33 ) )
return F_14 ( V_33 ) ;
V_36 = V_2 -> V_8 . V_38 ;
if ( V_2 -> V_8 . V_9 ) {
if ( ! V_36 )
V_36 = F_6 ( & V_2 -> V_8 ,
sizeof( struct V_3 ) ,
V_18 ) ;
if ( ! V_36 ) {
F_15 ( L_11 , V_39 ) ;
return - V_24 ;
}
V_29 = F_1 ( V_2 , V_36 , & V_5 ) ;
if ( V_29 ) {
F_15 ( L_12 , V_39 ) ;
return V_29 ;
}
}
if ( V_36 -> V_40 ) {
V_29 = V_36 -> V_40 ( V_2 ) ;
if ( F_16 ( V_29 ) )
return V_29 ;
}
V_35 = F_17 ( & ( V_2 -> V_8 ) , V_36 , V_33 ) ;
if ( ! V_35 ) {
F_15 ( L_13 , V_39 ) ;
return - V_12 ;
}
if ( V_5 )
memcpy ( V_35 -> V_8 -> V_41 , V_5 , V_42 ) ;
V_35 -> V_8 -> V_43 = F_18 ( V_2 , L_14 ) ;
if ( V_35 -> V_8 -> V_43 == - V_44 ) {
F_15 ( L_15
L_16 , V_39 ) ;
return - V_44 ;
}
V_35 -> V_45 = F_18 ( V_2 , L_17 ) ;
if ( V_35 -> V_45 == - V_44 )
V_35 -> V_45 = V_35 -> V_8 -> V_43 ;
V_35 -> V_46 = F_18 ( V_2 , L_18 ) ;
F_19 ( V_2 , V_35 -> V_8 ) ;
F_20 ( L_19 ) ;
return 0 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_22 ( V_2 ) ;
struct V_34 * V_35 = F_23 ( V_48 ) ;
int V_29 = F_24 ( V_48 ) ;
if ( V_35 -> V_4 -> exit )
V_35 -> V_4 -> exit ( V_2 ) ;
return V_29 ;
}
static int F_25 ( struct V_32 * V_8 )
{
struct V_47 * V_48 = F_26 ( V_8 ) ;
return F_27 ( V_48 ) ;
}
static int F_28 ( struct V_32 * V_8 )
{
struct V_47 * V_48 = F_26 ( V_8 ) ;
return F_29 ( V_48 ) ;
}
int F_30 ( struct V_32 * V_8 )
{
int V_29 ;
struct V_3 * V_36 = F_31 ( V_8 ) ;
struct V_47 * V_48 = F_26 ( V_8 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
V_29 = F_33 ( V_48 ) ;
if ( V_36 -> exit )
V_36 -> exit ( V_2 ) ;
return V_29 ;
}
int F_34 ( struct V_32 * V_8 )
{
struct V_3 * V_36 = F_31 ( V_8 ) ;
struct V_47 * V_48 = F_26 ( V_8 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
if ( V_36 -> V_40 )
V_36 -> V_40 ( V_2 ) ;
return F_35 ( V_48 ) ;
}
