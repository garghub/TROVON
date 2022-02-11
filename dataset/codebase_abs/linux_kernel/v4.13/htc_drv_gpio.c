static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_2 ( V_6 , V_6 -> V_7 . V_8 ) )
V_4 -> V_9 ++ ;
if ( F_3 ( V_10 , V_4 -> V_11 +
F_4 ( V_12 ) ) ) {
F_5 ( V_13 , & V_2 -> V_14 ) ;
F_5 ( V_15 , & V_2 -> V_14 ) ;
if ( V_4 -> V_9 >= V_16 ) {
F_6 ( F_7 ( V_6 ) , V_17 ,
L_1 ) ;
F_8 ( V_13 , & V_2 -> V_14 ) ;
F_8 ( V_15 , & V_2 -> V_14 ) ;
} else if ( V_4 -> V_9 >= V_18 ) {
F_6 ( F_7 ( V_6 ) , V_17 ,
L_2 ) ;
F_8 ( V_13 , & V_2 -> V_14 ) ;
}
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
}
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 , struct V_1 ,
V_21 . V_20 ) ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_7 ( V_2 -> V_6 ) ;
T_1 V_24 ;
int V_25 ;
F_1 ( V_2 ) ;
V_25 = F_11 ( V_2 ,
F_12 ( V_13 , & V_2 -> V_14 ) ) ;
if ( V_25 ) {
F_13 ( V_23 , L_3 ) ;
return;
}
F_14 ( V_2 -> V_6 , F_12 ( V_15 , & V_2 -> V_14 ) ?
V_26 : V_4 -> V_27 ) ;
F_15 ( V_2 -> V_6 ) ;
V_24 = F_12 ( V_15 , & V_2 -> V_14 ) ?
V_4 -> V_28 : V_4 -> V_29 ;
F_16 ( V_2 -> V_30 , & V_2 -> V_31 ,
F_4 ( V_24 ) ) ;
F_16 ( V_2 -> V_30 , & V_2 -> V_21 ,
F_4 ( V_4 -> V_32 ) ) ;
}
static void F_17 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 , struct V_1 ,
V_31 . V_20 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_22 * V_23 = F_7 ( V_6 ) ;
F_6 ( V_23 , V_17 , L_4 ) ;
if ( V_4 -> V_27 == V_33 ||
F_12 ( V_15 , & V_2 -> V_14 ) )
F_14 ( V_6 , V_34 ) ;
else if ( V_4 -> V_27 == V_26 )
F_14 ( V_6 , V_33 ) ;
F_15 ( V_2 -> V_6 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
V_4 -> V_32 = V_35 ;
V_4 -> V_29 = ( 100 - V_36 ) *
V_4 -> V_32 / 100 ;
V_4 -> V_28 = ( 100 - V_37 ) *
V_4 -> V_32 / 100 ;
F_19 ( & V_2 -> V_21 , F_9 ) ;
F_19 ( & V_2 -> V_31 , F_17 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_6 ( F_7 ( V_6 ) , V_17 , L_5 ) ;
V_4 -> V_9 = 0 ;
V_4 -> V_11 = V_10 ;
F_5 ( V_13 , & V_2 -> V_14 ) ;
F_5 ( V_15 , & V_2 -> V_14 ) ;
F_16 ( V_2 -> V_30 , & V_2 -> V_21 , 0 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( & V_2 -> V_21 ) ;
F_22 ( & V_2 -> V_31 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( F_24 ( V_6 ) == V_38 ) {
F_25 ( V_6 , V_39 ,
V_40 , 0 ) ;
F_15 ( V_6 ) ;
F_20 ( V_2 ) ;
}
}
void F_26 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
if ( V_6 -> V_7 . V_41 &&
F_24 ( V_6 ) != V_42 ) {
if ( V_6 -> V_7 . V_43 == V_38 )
F_21 ( V_2 ) ;
F_27 ( V_6 ) ;
}
}
void F_28 ( struct V_1 * V_2 , char * V_44 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
struct V_22 * V_23 = F_7 ( V_6 ) ;
int V_45 ;
if ( ! V_23 -> V_46 ) {
V_6 -> V_7 . V_43 = V_42 ;
return;
}
if ( V_44 && strncmp ( V_44 , V_47 , 5 ) == 0 ) {
V_6 -> V_7 . V_43 = V_38 ;
}
switch ( F_24 ( V_2 -> V_6 ) ) {
case V_42 :
break;
case V_38 :
V_2 -> V_6 -> V_7 . V_48 = 7 ;
V_2 -> V_6 -> V_7 . V_8 = 6 ;
V_2 -> V_6 -> V_7 . V_49 = 8 ;
V_2 -> V_4 . V_27 = V_33 ;
F_29 ( V_2 -> V_6 ) ;
F_18 ( V_2 ) ;
V_45 = V_2 -> V_50 [ V_51 ] ;
F_30 ( V_2 -> V_6 , V_45 ) ;
break;
default:
F_31 ( 1 ) ;
break;
}
}
void F_32 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_10 ( V_20 ,
struct V_1 ,
V_52 ) ;
F_33 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 ,
( V_2 -> V_54 == V_55 ) ) ;
}
static void F_34 ( struct V_56 * V_57 ,
enum V_58 V_54 )
{
struct V_1 * V_2 = F_10 ( V_57 ,
struct V_1 ,
V_57 ) ;
V_2 -> V_54 = V_54 ;
F_35 ( V_2 -> V_30 , & V_2 -> V_52 ) ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 )
return;
F_34 ( & V_2 -> V_57 , V_55 ) ;
F_37 ( & V_2 -> V_57 ) ;
F_38 ( & V_2 -> V_52 ) ;
F_39 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 ) ;
}
void F_40 ( struct V_1 * V_2 )
{
F_41 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 ,
L_6 ,
V_60 ) ;
F_33 ( V_2 -> V_6 , V_2 -> V_6 -> V_53 , 1 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
int V_25 ;
if ( F_43 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_53 = V_61 ;
else if ( F_44 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_53 = V_62 ;
else if ( F_45 ( V_2 -> V_6 ) )
V_2 -> V_6 -> V_53 = V_63 ;
else
V_2 -> V_6 -> V_53 = V_64 ;
if ( ! V_65 )
V_2 -> V_57 . V_66 =
F_46 ( V_2 -> V_30 ) ;
F_40 ( V_2 ) ;
snprintf ( V_2 -> V_67 , sizeof( V_2 -> V_67 ) ,
L_7 , F_47 ( V_2 -> V_30 -> V_68 ) ) ;
V_2 -> V_57 . V_69 = V_2 -> V_67 ;
V_2 -> V_57 . V_70 = F_34 ;
V_25 = F_48 ( F_49 ( V_2 -> V_30 -> V_68 ) , & V_2 -> V_57 ) ;
if ( V_25 < 0 )
return;
F_50 ( & V_2 -> V_52 , F_32 ) ;
V_2 -> V_59 = true ;
return;
}
static bool F_51 ( struct V_1 * V_2 )
{
bool V_71 ;
F_52 ( V_2 ) ;
V_71 = F_2 ( V_2 -> V_6 , V_2 -> V_6 -> V_72 ) ==
V_2 -> V_6 -> V_73 ;
F_53 ( V_2 ) ;
return V_71 ;
}
void F_54 ( struct V_74 * V_30 )
{
struct V_1 * V_2 = V_30 -> V_2 ;
bool V_75 = ! ! F_51 ( V_2 ) ;
F_55 ( V_30 -> V_68 , V_75 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_6 -> V_76 . V_77 & V_78 )
F_57 ( V_2 -> V_30 -> V_68 ) ;
}
