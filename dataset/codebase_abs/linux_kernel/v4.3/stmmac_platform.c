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
struct V_5 *
F_4 ( struct V_6 * V_7 , const char * * V_8 )
{
struct V_9 * V_10 = V_7 -> V_11 . V_12 ;
struct V_5 * V_13 ;
struct V_14 * V_15 ;
V_13 = F_5 ( & V_7 -> V_11 , sizeof( * V_13 ) , V_16 ) ;
if ( ! V_13 )
return F_6 ( - V_17 ) ;
* V_8 = F_7 ( V_10 ) ;
V_13 -> V_18 = F_8 ( V_10 ) ;
if ( F_9 ( V_10 , L_3 , & V_13 -> V_19 ) )
V_13 -> V_19 = - 1 ;
V_13 -> V_20 = F_10 ( V_10 , L_4 ) ;
if ( V_13 -> V_20 < 0 )
V_13 -> V_20 = 0 ;
V_13 -> V_21 = - 1 ;
V_13 -> V_22 = F_11 ( V_10 , L_5 , 0 ) ;
if ( ! V_13 -> V_22 && F_12 ( V_10 ) ) {
if ( ( F_13 ( V_10 ) < 0 ) )
return F_6 ( - V_23 ) ;
V_13 -> V_22 = F_14 ( V_10 ) ;
}
if ( F_9 ( V_10 , L_6 , & V_13 -> V_21 ) == 0 )
F_15 ( & V_7 -> V_11 , L_7 ) ;
if ( V_13 -> V_22 || V_13 -> V_24 )
V_13 -> V_25 = NULL ;
else
V_13 -> V_25 =
F_5 ( & V_7 -> V_11 ,
sizeof( struct V_26 ) ,
V_16 ) ;
F_9 ( V_10 , L_8 , & V_13 -> V_27 ) ;
F_9 ( V_10 , L_9 , & V_13 -> V_28 ) ;
V_13 -> V_29 =
F_16 ( V_10 , L_10 ) ;
V_13 -> V_30 = V_31 ;
V_13 -> V_32 = V_3 ;
V_13 -> V_33 = 1 ;
if ( F_17 ( V_10 , L_11 ) ||
F_17 ( V_10 , L_12 ) ||
F_17 ( V_10 , L_13 ) ) {
F_9 ( V_10 , L_14 , & V_13 -> V_30 ) ;
F_9 ( V_10 , L_15 ,
& V_13 -> V_32 ) ;
F_9 ( V_10 , L_16 ,
& V_13 -> V_33 ) ;
V_13 -> V_33 = F_3 (
V_13 -> V_33 ) ;
V_13 -> V_32 = F_1 (
V_13 -> V_32 ) ;
V_13 -> V_34 = 1 ;
V_13 -> V_35 = 1 ;
}
if ( F_17 ( V_10 , L_17 ) ||
F_17 ( V_10 , L_18 ) ) {
V_13 -> V_36 = 1 ;
V_13 -> V_37 = 1 ;
V_13 -> V_29 = 1 ;
}
if ( F_18 ( V_10 , L_19 , NULL ) ) {
V_15 = F_5 ( & V_7 -> V_11 , sizeof( * V_15 ) ,
V_16 ) ;
if ( ! V_15 ) {
F_19 ( V_10 ) ;
return F_6 ( - V_17 ) ;
}
V_13 -> V_15 = V_15 ;
F_9 ( V_10 , L_19 , & V_15 -> V_38 ) ;
V_15 -> V_39 =
F_16 ( V_10 , L_20 ) ;
V_15 -> V_40 =
F_16 ( V_10 , L_21 ) ;
F_9 ( V_10 , L_22 , & V_15 -> V_41 ) ;
if ( V_15 -> V_41 < 0 || V_15 -> V_41 > 256 )
V_15 -> V_41 = 0 ;
}
V_13 -> V_42 = F_16 ( V_10 , L_23 ) ;
if ( V_13 -> V_42 ) {
V_13 -> V_29 = 0 ;
F_20 ( L_24 ) ;
}
return V_13 ;
}
struct V_5 *
F_4 ( struct V_6 * V_7 , const char * * V_8 )
{
return F_6 ( - V_43 ) ;
}
int F_21 ( struct V_6 * V_7 ,
struct V_44 * V_45 )
{
struct V_46 * V_47 ;
memset ( V_45 , 0 , sizeof( * V_45 ) ) ;
V_45 -> V_48 = F_22 ( V_7 , L_25 ) ;
if ( V_45 -> V_48 < 0 ) {
if ( V_45 -> V_48 != - V_49 ) {
F_23 ( & V_7 -> V_11 ,
L_26 ) ;
}
return V_45 -> V_48 ;
}
V_45 -> V_50 = F_22 ( V_7 , L_27 ) ;
if ( V_45 -> V_50 < 0 ) {
if ( V_45 -> V_50 == - V_49 )
return - V_49 ;
V_45 -> V_50 = V_45 -> V_48 ;
}
V_45 -> V_51 = F_22 ( V_7 , L_28 ) ;
if ( V_45 -> V_51 == - V_49 )
return - V_49 ;
V_47 = F_24 ( V_7 , V_52 , 0 ) ;
V_45 -> V_53 = F_25 ( & V_7 -> V_11 , V_47 ) ;
return F_26 ( V_45 -> V_53 ) ;
}
int F_27 ( struct V_6 * V_7 )
{
struct V_54 * V_55 = F_28 ( V_7 ) ;
struct V_56 * V_57 = F_29 ( V_55 ) ;
int V_58 = F_30 ( V_55 ) ;
if ( V_57 -> V_13 -> exit )
V_57 -> V_13 -> exit ( V_7 , V_57 -> V_13 -> V_59 ) ;
return V_58 ;
}
static int F_31 ( struct V_60 * V_11 )
{
int V_58 ;
struct V_54 * V_55 = F_32 ( V_11 ) ;
struct V_56 * V_57 = F_29 ( V_55 ) ;
struct V_6 * V_7 = F_33 ( V_11 ) ;
V_58 = F_34 ( V_55 ) ;
if ( V_57 -> V_13 -> exit )
V_57 -> V_13 -> exit ( V_7 , V_57 -> V_13 -> V_59 ) ;
return V_58 ;
}
static int F_35 ( struct V_60 * V_11 )
{
struct V_54 * V_55 = F_32 ( V_11 ) ;
struct V_56 * V_57 = F_29 ( V_55 ) ;
struct V_6 * V_7 = F_33 ( V_11 ) ;
if ( V_57 -> V_13 -> V_61 )
V_57 -> V_13 -> V_61 ( V_7 , V_57 -> V_13 -> V_59 ) ;
return F_36 ( V_55 ) ;
}
