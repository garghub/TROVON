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
V_4 -> V_28 = F_9 ( V_7 , L_11 ) ;
if ( V_4 -> V_28 ) {
V_4 -> V_23 = 0 ;
F_10 ( L_12 ) ;
}
return 0 ;
}
static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
return - V_29 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_30 = 0 ;
struct V_31 * V_32 ;
struct V_33 * V_8 = & V_2 -> V_8 ;
void T_1 * V_34 = NULL ;
struct V_35 * V_36 = NULL ;
struct V_3 * V_37 = NULL ;
const char * V_5 = NULL ;
V_32 = F_12 ( V_2 , V_38 , 0 ) ;
V_34 = F_13 ( V_8 , V_32 ) ;
if ( F_14 ( V_34 ) )
return F_15 ( V_34 ) ;
V_37 = F_16 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_8 . V_9 ) {
if ( ! V_37 )
V_37 = F_6 ( & V_2 -> V_8 ,
sizeof( struct V_3 ) ,
V_18 ) ;
if ( ! V_37 ) {
F_17 ( L_13 , V_39 ) ;
return - V_24 ;
}
V_30 = F_1 ( V_2 , V_37 , & V_5 ) ;
if ( V_30 ) {
F_17 ( L_14 , V_39 ) ;
return V_30 ;
}
}
if ( V_37 -> V_40 ) {
V_30 = V_37 -> V_40 ( V_2 ) ;
if ( F_18 ( V_30 ) )
return V_30 ;
}
V_36 = F_19 ( & ( V_2 -> V_8 ) , V_37 , V_34 ) ;
if ( ! V_36 ) {
F_17 ( L_15 , V_39 ) ;
return - V_12 ;
}
if ( V_5 )
memcpy ( V_36 -> V_8 -> V_41 , V_5 , V_42 ) ;
V_36 -> V_8 -> V_43 = F_20 ( V_2 , L_16 ) ;
if ( V_36 -> V_8 -> V_43 == - V_44 ) {
F_17 ( L_17
L_18 , V_39 ) ;
return - V_44 ;
}
V_36 -> V_45 = F_20 ( V_2 , L_19 ) ;
if ( V_36 -> V_45 == - V_44 )
V_36 -> V_45 = V_36 -> V_8 -> V_43 ;
V_36 -> V_46 = F_20 ( V_2 , L_20 ) ;
F_21 ( V_2 , V_36 -> V_8 ) ;
F_22 ( L_21 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_47 * V_48 = F_24 ( V_2 ) ;
struct V_35 * V_36 = F_25 ( V_48 ) ;
int V_30 = F_26 ( V_48 ) ;
if ( V_36 -> V_4 -> exit )
V_36 -> V_4 -> exit ( V_2 ) ;
return V_30 ;
}
static int F_27 ( struct V_33 * V_8 )
{
struct V_47 * V_48 = F_28 ( V_8 ) ;
return F_29 ( V_48 ) ;
}
static int F_30 ( struct V_33 * V_8 )
{
struct V_47 * V_48 = F_28 ( V_8 ) ;
return F_31 ( V_48 ) ;
}
int F_32 ( struct V_33 * V_8 )
{
int V_30 ;
struct V_3 * V_37 = F_16 ( V_8 ) ;
struct V_47 * V_48 = F_28 ( V_8 ) ;
struct V_1 * V_2 = F_33 ( V_8 ) ;
V_30 = F_34 ( V_48 ) ;
if ( V_37 -> exit )
V_37 -> exit ( V_2 ) ;
return V_30 ;
}
int F_35 ( struct V_33 * V_8 )
{
struct V_3 * V_37 = F_16 ( V_8 ) ;
struct V_47 * V_48 = F_28 ( V_8 ) ;
struct V_1 * V_2 = F_33 ( V_8 ) ;
if ( V_37 -> V_40 )
V_37 -> V_40 ( V_2 ) ;
return F_36 ( V_48 ) ;
}
