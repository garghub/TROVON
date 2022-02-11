static int F_1 ( int V_1 )
{
int V_2 = V_1 ;
switch ( V_2 ) {
case V_3 :
case 128 :
case 256 :
break;
default:
V_2 = 0 ;
F_2 ( L_1 ,
V_1 ) ;
break;
}
return V_2 ;
}
static int F_3 ( int V_4 )
{
int V_2 = V_4 ;
switch ( V_2 ) {
case 1 :
case 32 :
case 64 :
case 128 :
break;
default:
V_2 = 1 ;
F_2 ( L_2 ,
V_4 ) ;
break;
}
return V_2 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * * V_9 )
{
struct V_10 * V_11 = V_6 -> V_12 . V_13 ;
struct V_14 * V_15 ;
const struct V_16 * V_17 ;
if ( ! V_11 )
return - V_18 ;
V_17 = F_5 ( V_19 , & V_6 -> V_12 ) ;
if ( ! V_17 )
return - V_18 ;
if ( V_17 -> V_20 ) {
const struct V_21 * V_20 = V_17 -> V_20 ;
V_8 -> V_22 = V_20 -> V_22 ;
V_8 -> V_23 = V_20 -> V_23 ;
V_8 -> V_24 = V_20 -> V_24 ;
V_8 -> V_25 = V_20 -> V_25 ;
V_8 -> V_26 = V_20 -> V_26 ;
V_8 -> V_27 = V_20 -> V_27 ;
V_8 -> V_28 = V_20 -> V_28 ;
V_8 -> V_29 = V_20 -> V_29 ;
V_8 -> V_30 = V_20 -> V_30 ;
V_8 -> V_31 = V_20 -> V_31 ;
V_8 -> free = V_20 -> free ;
V_8 -> V_32 = V_20 -> V_32 ;
V_8 -> exit = V_20 -> exit ;
}
* V_9 = F_6 ( V_11 ) ;
V_8 -> V_33 = F_7 ( V_11 ) ;
if ( F_8 ( V_11 , L_3 , & V_8 -> V_34 ) )
V_8 -> V_34 = - 1 ;
V_8 -> V_35 = F_9 ( V_11 , L_4 ) ;
if ( V_8 -> V_35 < 0 )
V_8 -> V_35 = 0 ;
V_8 -> V_36 = - 1 ;
if ( F_8 ( V_11 , L_5 , & V_8 -> V_36 ) == 0 )
F_10 ( & V_6 -> V_12 , L_6 ) ;
if ( V_8 -> V_37 )
V_8 -> V_38 = NULL ;
else
V_8 -> V_38 =
F_11 ( & V_6 -> V_12 ,
sizeof( struct V_39 ) ,
V_40 ) ;
F_8 ( V_11 , L_7 , & V_8 -> V_41 ) ;
F_8 ( V_11 , L_8 , & V_8 -> V_42 ) ;
V_8 -> V_43 =
F_12 ( V_11 , L_9 ) ;
V_8 -> V_44 = V_45 ;
if ( F_13 ( V_11 , L_10 ) ||
F_13 ( V_11 , L_11 ) ||
F_13 ( V_11 , L_12 ) ) {
F_8 ( V_11 , L_13 , & V_8 -> V_44 ) ;
F_8 ( V_11 , L_14 ,
& V_8 -> V_46 ) ;
F_8 ( V_11 , L_15 ,
& V_8 -> V_47 ) ;
V_8 -> V_47 = F_3 (
V_8 -> V_47 ) ;
V_8 -> V_46 = F_1 (
V_8 -> V_46 ) ;
V_8 -> V_22 = 1 ;
V_8 -> V_27 = 1 ;
}
if ( F_13 ( V_11 , L_16 ) ||
F_13 ( V_11 , L_17 ) ) {
V_8 -> V_23 = 1 ;
V_8 -> V_26 = 1 ;
V_8 -> V_43 = 1 ;
}
if ( F_14 ( V_11 , L_18 , NULL ) ) {
V_15 = F_11 ( & V_6 -> V_12 , sizeof( * V_15 ) ,
V_40 ) ;
if ( ! V_15 )
return - V_48 ;
V_8 -> V_15 = V_15 ;
F_8 ( V_11 , L_18 , & V_15 -> V_49 ) ;
V_15 -> V_50 =
F_12 ( V_11 , L_19 ) ;
V_15 -> V_51 =
F_12 ( V_11 , L_20 ) ;
F_8 ( V_11 , L_21 , & V_15 -> V_52 ) ;
if ( V_15 -> V_52 < 0 || V_15 -> V_52 > 256 )
V_15 -> V_52 = 0 ;
}
V_8 -> V_53 = F_12 ( V_11 , L_22 ) ;
if ( V_8 -> V_53 ) {
V_8 -> V_43 = 0 ;
F_15 ( L_23 ) ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * * V_9 )
{
return - V_54 ;
}
static int F_16 ( struct V_5 * V_6 )
{
int V_55 = 0 ;
struct V_56 * V_57 ;
struct V_17 * V_12 = & V_6 -> V_12 ;
void T_1 * V_58 = NULL ;
struct V_59 * V_60 = NULL ;
struct V_7 * V_61 = NULL ;
const char * V_9 = NULL ;
int V_62 , V_63 , V_64 ;
V_62 = F_17 ( V_6 , L_24 ) ;
if ( V_62 < 0 ) {
if ( V_62 != - V_65 ) {
F_18 ( V_12 ,
L_25 ) ;
}
return V_62 ;
}
V_63 = F_17 ( V_6 , L_26 ) ;
if ( V_63 < 0 ) {
if ( V_63 == - V_65 )
return - V_65 ;
V_63 = V_62 ;
}
V_64 = F_17 ( V_6 , L_27 ) ;
if ( V_64 == - V_65 )
return - V_65 ;
V_57 = F_19 ( V_6 , V_66 , 0 ) ;
V_58 = F_20 ( V_12 , V_57 ) ;
if ( F_21 ( V_58 ) )
return F_22 ( V_58 ) ;
V_61 = F_23 ( & V_6 -> V_12 ) ;
if ( ! V_61 )
V_61 = F_11 ( & V_6 -> V_12 ,
sizeof( struct V_7 ) ,
V_40 ) ;
if ( ! V_61 ) {
F_24 ( L_28 , V_67 ) ;
return - V_48 ;
}
V_61 -> V_46 = V_3 ;
V_61 -> V_47 = 1 ;
if ( V_6 -> V_12 . V_13 ) {
V_55 = F_4 ( V_6 , V_61 , & V_9 ) ;
if ( V_55 ) {
F_24 ( L_29 , V_67 ) ;
return V_55 ;
}
}
if ( V_61 -> V_31 ) {
V_61 -> V_68 = V_61 -> V_31 ( V_6 ) ;
if ( F_21 ( V_61 -> V_68 ) )
return F_22 ( V_61 -> V_68 ) ;
}
if ( V_61 -> V_32 ) {
V_55 = V_61 -> V_32 ( V_6 , V_61 -> V_68 ) ;
if ( F_25 ( V_55 ) )
return V_55 ;
}
V_60 = F_26 ( & ( V_6 -> V_12 ) , V_61 , V_58 ) ;
if ( F_21 ( V_60 ) ) {
F_24 ( L_30 , V_67 ) ;
return F_22 ( V_60 ) ;
}
V_60 -> V_12 -> V_62 = V_62 ;
V_60 -> V_63 = V_63 ;
V_60 -> V_64 = V_64 ;
if ( V_9 )
memcpy ( V_60 -> V_12 -> V_69 , V_9 , V_70 ) ;
F_27 ( V_6 , V_60 -> V_12 ) ;
F_28 ( L_31 ) ;
return 0 ;
}
static int F_29 ( struct V_5 * V_6 )
{
struct V_71 * V_72 = F_30 ( V_6 ) ;
struct V_59 * V_60 = F_31 ( V_72 ) ;
int V_55 = F_32 ( V_72 ) ;
if ( V_60 -> V_8 -> exit )
V_60 -> V_8 -> exit ( V_6 , V_60 -> V_8 -> V_68 ) ;
if ( V_60 -> V_8 -> free )
V_60 -> V_8 -> free ( V_6 , V_60 -> V_8 -> V_68 ) ;
return V_55 ;
}
static int F_33 ( struct V_17 * V_12 )
{
int V_55 ;
struct V_71 * V_72 = F_34 ( V_12 ) ;
struct V_59 * V_60 = F_31 ( V_72 ) ;
struct V_5 * V_6 = F_35 ( V_12 ) ;
V_55 = F_36 ( V_72 ) ;
if ( V_60 -> V_8 -> exit )
V_60 -> V_8 -> exit ( V_6 , V_60 -> V_8 -> V_68 ) ;
return V_55 ;
}
static int F_37 ( struct V_17 * V_12 )
{
struct V_71 * V_72 = F_34 ( V_12 ) ;
struct V_59 * V_60 = F_31 ( V_72 ) ;
struct V_5 * V_6 = F_35 ( V_12 ) ;
if ( V_60 -> V_8 -> V_32 )
V_60 -> V_8 -> V_32 ( V_6 , V_60 -> V_8 -> V_68 ) ;
return F_38 ( V_72 ) ;
}
