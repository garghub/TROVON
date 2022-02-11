static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 . V_9 ;
struct V_10 * V_11 ;
const struct V_12 * V_13 ;
if ( ! V_7 )
return - V_14 ;
V_13 = F_2 ( V_15 , & V_2 -> V_8 ) ;
if ( ! V_13 )
return - V_14 ;
if ( V_13 -> V_16 ) {
const struct V_17 * V_16 = V_13 -> V_16 ;
V_4 -> V_18 = V_16 -> V_18 ;
V_4 -> V_19 = V_16 -> V_19 ;
V_4 -> V_20 = V_16 -> V_20 ;
V_4 -> V_21 = V_16 -> V_21 ;
V_4 -> V_22 = V_16 -> V_22 ;
V_4 -> V_23 = V_16 -> V_23 ;
V_4 -> V_24 = V_16 -> V_24 ;
V_4 -> V_25 = V_16 -> V_25 ;
V_4 -> V_26 = V_16 -> V_26 ;
V_4 -> V_27 = V_16 -> V_27 ;
V_4 -> free = V_16 -> free ;
V_4 -> V_28 = V_16 -> V_28 ;
V_4 -> exit = V_16 -> exit ;
}
* V_5 = F_3 ( V_7 ) ;
V_4 -> V_29 = F_4 ( V_7 ) ;
if ( F_5 ( V_7 , L_1 , & V_4 -> V_30 ) )
V_4 -> V_30 = - 1 ;
V_4 -> V_31 = F_6 ( V_7 , L_2 ) ;
if ( V_4 -> V_31 < 0 )
V_4 -> V_31 = 0 ;
V_4 -> V_32 = - 1 ;
if ( F_5 ( V_7 , L_3 , & V_4 -> V_32 ) == 0 )
F_7 ( & V_2 -> V_8 , L_4 ) ;
V_4 -> V_33 = F_8 ( & V_2 -> V_8 ,
sizeof( struct V_34 ) ,
V_35 ) ;
V_4 -> V_36 = F_9 ( V_7 , L_5 ) ;
V_4 -> V_37 = V_38 ;
if ( F_10 ( V_7 , L_6 ) ||
F_10 ( V_7 , L_7 ) ||
F_10 ( V_7 , L_8 ) ) {
F_5 ( V_7 , L_9 , & V_4 -> V_37 ) ;
V_4 -> V_18 = 1 ;
V_4 -> V_23 = 1 ;
}
if ( F_10 ( V_7 , L_10 ) ||
F_10 ( V_7 , L_11 ) ) {
V_4 -> V_19 = 1 ;
V_4 -> V_22 = 1 ;
V_4 -> V_36 = 1 ;
}
if ( F_11 ( V_7 , L_12 , NULL ) ) {
V_11 = F_8 ( & V_2 -> V_8 , sizeof( * V_11 ) ,
V_35 ) ;
if ( ! V_11 )
return - V_39 ;
V_4 -> V_11 = V_11 ;
F_5 ( V_7 , L_12 , & V_11 -> V_40 ) ;
V_11 -> V_41 =
F_9 ( V_7 , L_13 ) ;
V_11 -> V_42 =
F_9 ( V_7 , L_14 ) ;
}
V_4 -> V_43 = F_9 ( V_7 , L_15 ) ;
if ( V_4 -> V_43 ) {
V_4 -> V_36 = 0 ;
F_12 ( L_16 ) ;
}
return 0 ;
}
static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * * V_5 )
{
return - V_44 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_45 = 0 ;
struct V_46 * V_47 ;
struct V_13 * V_8 = & V_2 -> V_8 ;
void T_1 * V_48 = NULL ;
struct V_49 * V_50 = NULL ;
struct V_3 * V_51 = NULL ;
const char * V_5 = NULL ;
V_47 = F_14 ( V_2 , V_52 , 0 ) ;
V_48 = F_15 ( V_8 , V_47 ) ;
if ( F_16 ( V_48 ) )
return F_17 ( V_48 ) ;
V_51 = F_18 ( & V_2 -> V_8 ) ;
if ( V_2 -> V_8 . V_9 ) {
if ( ! V_51 )
V_51 = F_8 ( & V_2 -> V_8 ,
sizeof( struct V_3 ) ,
V_35 ) ;
if ( ! V_51 ) {
F_19 ( L_17 , V_53 ) ;
return - V_39 ;
}
V_45 = F_1 ( V_2 , V_51 , & V_5 ) ;
if ( V_45 ) {
F_19 ( L_18 , V_53 ) ;
return V_45 ;
}
}
if ( V_51 -> V_27 ) {
V_51 -> V_54 = V_51 -> V_27 ( V_2 ) ;
if ( F_16 ( V_51 -> V_54 ) )
return F_17 ( V_51 -> V_54 ) ;
}
if ( V_51 -> V_28 ) {
V_45 = V_51 -> V_28 ( V_2 , V_51 -> V_54 ) ;
if ( F_20 ( V_45 ) )
return V_45 ;
}
V_50 = F_21 ( & ( V_2 -> V_8 ) , V_51 , V_48 ) ;
if ( F_16 ( V_50 ) ) {
F_19 ( L_19 , V_53 ) ;
return F_17 ( V_50 ) ;
}
if ( V_5 )
memcpy ( V_50 -> V_8 -> V_55 , V_5 , V_56 ) ;
V_50 -> V_8 -> V_57 = F_22 ( V_2 , L_20 ) ;
if ( V_50 -> V_8 -> V_57 < 0 ) {
if ( V_50 -> V_8 -> V_57 != - V_58 ) {
F_23 ( V_50 -> V_8 ,
L_21 ) ;
}
return V_50 -> V_8 -> V_57 ;
}
V_50 -> V_59 = F_22 ( V_2 , L_22 ) ;
if ( V_50 -> V_59 < 0 ) {
if ( V_50 -> V_59 == - V_58 )
return - V_58 ;
V_50 -> V_59 = V_50 -> V_8 -> V_57 ;
}
V_50 -> V_60 = F_22 ( V_2 , L_23 ) ;
if ( V_50 -> V_60 == - V_58 )
return - V_58 ;
F_24 ( V_2 , V_50 -> V_8 ) ;
F_25 ( L_24 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_61 * V_62 = F_27 ( V_2 ) ;
struct V_49 * V_50 = F_28 ( V_62 ) ;
int V_45 = F_29 ( V_62 ) ;
if ( V_50 -> V_4 -> exit )
V_50 -> V_4 -> exit ( V_2 , V_50 -> V_4 -> V_54 ) ;
if ( V_50 -> V_4 -> free )
V_50 -> V_4 -> free ( V_2 , V_50 -> V_4 -> V_54 ) ;
return V_45 ;
}
static int F_30 ( struct V_13 * V_8 )
{
int V_45 ;
struct V_61 * V_62 = F_31 ( V_8 ) ;
struct V_49 * V_50 = F_28 ( V_62 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
V_45 = F_33 ( V_62 ) ;
if ( V_50 -> V_4 -> exit )
V_50 -> V_4 -> exit ( V_2 , V_50 -> V_4 -> V_54 ) ;
return V_45 ;
}
static int F_34 ( struct V_13 * V_8 )
{
struct V_61 * V_62 = F_31 ( V_8 ) ;
struct V_49 * V_50 = F_28 ( V_62 ) ;
struct V_1 * V_2 = F_32 ( V_8 ) ;
if ( V_50 -> V_4 -> V_28 )
V_50 -> V_4 -> V_28 ( V_2 , V_50 -> V_4 -> V_54 ) ;
return F_35 ( V_62 ) ;
}
