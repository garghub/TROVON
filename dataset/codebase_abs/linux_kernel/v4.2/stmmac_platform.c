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
struct V_17 * V_12 = & V_6 -> V_12 ;
V_17 = F_5 ( V_12 -> V_18 -> V_19 , V_12 ) ;
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
V_8 -> V_37 = F_10 ( V_11 , L_5 , 0 ) ;
if ( ! V_8 -> V_37 && F_11 ( V_11 ) ) {
if ( ( F_12 ( V_11 ) < 0 ) )
return - V_38 ;
V_8 -> V_37 = F_13 ( V_11 ) ;
}
if ( F_8 ( V_11 , L_6 , & V_8 -> V_36 ) == 0 )
F_14 ( & V_6 -> V_12 , L_7 ) ;
if ( V_8 -> V_37 || V_8 -> V_39 )
V_8 -> V_40 = NULL ;
else
V_8 -> V_40 =
F_15 ( & V_6 -> V_12 ,
sizeof( struct V_41 ) ,
V_42 ) ;
F_8 ( V_11 , L_8 , & V_8 -> V_43 ) ;
F_8 ( V_11 , L_9 , & V_8 -> V_44 ) ;
V_8 -> V_45 =
F_16 ( V_11 , L_10 ) ;
V_8 -> V_46 = V_47 ;
if ( F_17 ( V_11 , L_11 ) ||
F_17 ( V_11 , L_12 ) ||
F_17 ( V_11 , L_13 ) ) {
F_8 ( V_11 , L_14 , & V_8 -> V_46 ) ;
F_8 ( V_11 , L_15 ,
& V_8 -> V_48 ) ;
F_8 ( V_11 , L_16 ,
& V_8 -> V_49 ) ;
V_8 -> V_49 = F_3 (
V_8 -> V_49 ) ;
V_8 -> V_48 = F_1 (
V_8 -> V_48 ) ;
V_8 -> V_22 = 1 ;
V_8 -> V_27 = 1 ;
}
if ( F_17 ( V_11 , L_17 ) ||
F_17 ( V_11 , L_18 ) ) {
V_8 -> V_23 = 1 ;
V_8 -> V_26 = 1 ;
V_8 -> V_45 = 1 ;
}
if ( F_18 ( V_11 , L_19 , NULL ) ) {
V_15 = F_15 ( & V_6 -> V_12 , sizeof( * V_15 ) ,
V_42 ) ;
if ( ! V_15 ) {
F_19 ( V_11 ) ;
return - V_50 ;
}
V_8 -> V_15 = V_15 ;
F_8 ( V_11 , L_19 , & V_15 -> V_51 ) ;
V_15 -> V_52 =
F_16 ( V_11 , L_20 ) ;
V_15 -> V_53 =
F_16 ( V_11 , L_21 ) ;
F_8 ( V_11 , L_22 , & V_15 -> V_54 ) ;
if ( V_15 -> V_54 < 0 || V_15 -> V_54 > 256 )
V_15 -> V_54 = 0 ;
}
V_8 -> V_55 = F_16 ( V_11 , L_23 ) ;
if ( V_8 -> V_55 ) {
V_8 -> V_45 = 0 ;
F_20 ( L_24 ) ;
}
return 0 ;
}
static int F_4 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
const char * * V_9 )
{
return - V_56 ;
}
int F_21 ( struct V_5 * V_6 )
{
struct V_57 V_58 ;
int V_59 = 0 ;
struct V_60 * V_61 ;
struct V_17 * V_12 = & V_6 -> V_12 ;
struct V_7 * V_62 = NULL ;
memset ( & V_58 , 0 , sizeof( V_58 ) ) ;
V_58 . V_63 = F_22 ( V_6 , L_25 ) ;
if ( V_58 . V_63 < 0 ) {
if ( V_58 . V_63 != - V_64 ) {
F_23 ( V_12 ,
L_26 ) ;
}
return V_58 . V_63 ;
}
V_58 . V_65 = F_22 ( V_6 , L_27 ) ;
if ( V_58 . V_65 < 0 ) {
if ( V_58 . V_65 == - V_64 )
return - V_64 ;
V_58 . V_65 = V_58 . V_63 ;
}
V_58 . V_66 = F_22 ( V_6 , L_28 ) ;
if ( V_58 . V_66 == - V_64 )
return - V_64 ;
V_61 = F_24 ( V_6 , V_67 , 0 ) ;
V_58 . V_68 = F_25 ( V_12 , V_61 ) ;
if ( F_26 ( V_58 . V_68 ) )
return F_27 ( V_58 . V_68 ) ;
V_62 = F_28 ( & V_6 -> V_12 ) ;
if ( ! V_62 )
V_62 = F_15 ( & V_6 -> V_12 ,
sizeof( struct V_7 ) ,
V_42 ) ;
if ( ! V_62 ) {
F_29 ( L_29 , V_69 ) ;
return - V_50 ;
}
V_62 -> V_48 = V_3 ;
V_62 -> V_49 = 1 ;
if ( V_6 -> V_12 . V_13 ) {
V_59 = F_4 ( V_6 , V_62 , & V_58 . V_9 ) ;
if ( V_59 ) {
F_29 ( L_30 , V_69 ) ;
return V_59 ;
}
}
if ( V_62 -> V_31 ) {
V_62 -> V_70 = V_62 -> V_31 ( V_6 ) ;
if ( F_26 ( V_62 -> V_70 ) )
return F_27 ( V_62 -> V_70 ) ;
}
if ( V_62 -> V_32 ) {
V_59 = V_62 -> V_32 ( V_6 , V_62 -> V_70 ) ;
if ( F_30 ( V_59 ) )
return V_59 ;
}
return F_31 ( & V_6 -> V_12 , V_62 , & V_58 ) ;
}
int F_32 ( struct V_5 * V_6 )
{
struct V_71 * V_72 = F_33 ( V_6 ) ;
struct V_73 * V_74 = F_34 ( V_72 ) ;
int V_59 = F_35 ( V_72 ) ;
if ( V_74 -> V_8 -> exit )
V_74 -> V_8 -> exit ( V_6 , V_74 -> V_8 -> V_70 ) ;
if ( V_74 -> V_8 -> free )
V_74 -> V_8 -> free ( V_6 , V_74 -> V_8 -> V_70 ) ;
return V_59 ;
}
static int F_36 ( struct V_17 * V_12 )
{
int V_59 ;
struct V_71 * V_72 = F_37 ( V_12 ) ;
struct V_73 * V_74 = F_34 ( V_72 ) ;
struct V_5 * V_6 = F_38 ( V_12 ) ;
V_59 = F_39 ( V_72 ) ;
if ( V_74 -> V_8 -> exit )
V_74 -> V_8 -> exit ( V_6 , V_74 -> V_8 -> V_70 ) ;
return V_59 ;
}
static int F_40 ( struct V_17 * V_12 )
{
struct V_71 * V_72 = F_37 ( V_12 ) ;
struct V_73 * V_74 = F_34 ( V_72 ) ;
struct V_5 * V_6 = F_38 ( V_12 ) ;
if ( V_74 -> V_8 -> V_32 )
V_74 -> V_8 -> V_32 ( V_6 , V_74 -> V_8 -> V_70 ) ;
return F_41 ( V_72 ) ;
}
