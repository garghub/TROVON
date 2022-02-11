static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_4 ( & V_4 -> V_5 , F_5 ( 0 ) ) ;
}
static bool F_6 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
bool V_8 = F_7 ( V_7 -> V_9 ) ;
bool V_10 = V_7 -> V_11 ;
if ( ! F_8 ( V_7 -> V_9 ) )
return false ;
return V_8 ^ V_10 ;
}
static int F_9 ( struct V_1 * V_4 )
{
struct V_6 * V_7 = V_4 -> V_7 ;
struct V_12 * V_13 ;
V_13 = & V_7 -> V_14 ;
if ( V_4 -> V_15 == V_13 -> V_16 )
return V_17 ;
return V_4 -> V_18 ;
}
static enum V_19 F_10 ( enum V_20 V_21 )
{
switch ( V_21 ) {
case V_22 :
return V_23 ;
case V_24 :
return V_25 ;
case V_26 :
return V_27 ;
default:
F_11 ( 1 ) ;
break;
}
return V_23 ;
}
static int F_12 ( struct V_1 * V_4 , enum V_20 V_21 ,
int * V_28 )
{
int V_8 ;
int V_29 ;
V_29 = F_10 ( V_21 ) ;
V_8 = F_13 ( V_4 -> V_30 [ V_29 ] ,
V_28 ) ;
if ( V_8 < 0 )
F_14 ( L_1 ) ;
return V_8 ;
}
static int F_15 ( struct V_2 * V_3 ,
enum V_20 V_21 , union V_31 * V_32 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_28 = 0 ;
int V_8 = 0 ;
V_4 = F_1 ( V_3 ) ;
if ( ! V_4 ) {
F_16 ( V_3 -> V_33 , L_2 ) ;
return - V_34 ;
}
V_7 = V_4 -> V_7 ;
V_13 = & V_7 -> V_14 ;
switch ( V_21 ) {
case V_35 :
F_9 ( V_4 ) ;
break;
case V_36 :
V_32 -> V_37 = 0 ;
break;
case V_38 :
V_32 -> V_37 = V_7 -> V_39 ( V_28 ) ;
break;
case V_24 :
case V_26 :
case V_22 :
V_8 = F_12 ( V_4 , V_21 , & V_28 ) ;
if ( V_8 < 0 )
goto V_40;
V_32 -> V_37 = V_28 ;
break;
case V_41 :
V_32 -> V_37 = V_13 -> V_42 ;
break;
case V_43 :
V_32 -> V_37 = V_13 -> V_44 ;
break;
case V_45 :
V_32 -> V_37 = V_13 -> V_46 ;
break;
case V_47 :
V_32 -> V_37 = V_13 -> V_16 ;
break;
case V_48 :
V_32 -> V_49 = V_13 -> V_50 ;
break;
default:
return - V_34 ;
}
V_40:
return V_8 ;
}
static void F_17 ( struct V_51 * V_52 )
{
struct V_1 * V_4 ;
struct V_6 * V_7 ;
struct V_53 * V_53 ;
bool V_54 ;
int V_18 ;
V_53 = F_2 ( V_52 , struct V_53 , V_52 ) ;
V_4 = F_2 ( V_53 , struct V_1 , V_5 ) ;
V_7 = V_4 -> V_7 ;
V_18 = V_4 -> V_18 ;
V_54 = F_18 ( & V_4 -> V_3 ) ;
V_4 -> V_55 = V_54 ;
if ( ! V_54 )
V_4 -> V_18 = V_56 ;
else if ( F_6 ( V_4 ) )
V_4 -> V_18 = V_57 ;
else
V_4 -> V_18 = V_58 ;
if ( V_18 != V_4 -> V_18 )
F_19 ( & V_4 -> V_3 ) ;
}
static T_1 F_20 ( int V_59 , void * V_60 )
{
struct V_1 * V_4 = V_60 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_61 ;
V_61 = V_7 -> V_62 ? V_7 -> V_62 : V_63 ;
F_4 ( & V_4 -> V_5 ,
F_5 ( V_61 ) ) ;
return V_64 ;
}
static int F_21 ( struct V_65 * V_66 )
{
struct V_1 * V_4 ;
struct V_2 * V_3 ;
struct V_6 * V_7 = V_66 -> V_33 . V_67 ;
enum V_20 * V_68 ;
int V_8 = 0 ;
int V_69 ;
int V_70 = 0 ;
V_4 = F_22 ( & V_66 -> V_33 , sizeof( * V_4 ) , V_71 ) ;
if ( ! V_4 ) {
F_16 ( & V_66 -> V_33 , L_3 ) ;
return - V_72 ;
}
V_3 = & V_4 -> V_3 ;
V_3 -> V_50 = V_7 -> V_14 . V_50 ;
V_4 -> V_55 = false ;
V_4 -> V_18 = V_56 ;
V_3 -> type = V_73 ;
V_3 -> V_74 = F_15 ;
V_3 -> V_75 = F_3 ;
V_4 -> V_7 = V_7 ;
V_3 -> V_68 = F_23 ( F_24 ( V_76 ) +
F_24 ( V_77 ) ,
sizeof( * V_3 -> V_68 ) , V_71 ) ;
if ( ! V_3 -> V_68 ) {
V_8 = - V_72 ;
goto V_78;
}
memcpy ( V_3 -> V_68 , V_76 , sizeof( V_76 ) ) ;
V_68 = (enum V_20 * )
( ( char * ) V_3 -> V_68 + sizeof( V_76 ) ) ;
for ( V_69 = 0 ; V_69 < F_24 ( V_77 ) ; V_69 ++ ) {
V_4 -> V_30 [ V_69 ] = F_25 ( & V_66 -> V_33 ,
V_77 [ V_69 ] ) ;
if ( F_26 ( V_4 -> V_30 [ V_69 ] ) ) {
V_8 = F_27 ( V_4 -> V_30 [ V_69 ] ) ;
V_4 -> V_30 [ V_69 ] = NULL ;
} else {
memcpy ( V_68 + sizeof( * ( V_3 -> V_68 ) ) * V_70 ,
& V_79 [ V_69 ] ,
sizeof( V_79 [ V_69 ] ) ) ;
V_70 ++ ;
}
}
if ( V_70 == 0 ) {
V_8 = - V_80 ;
goto V_81;
}
V_3 -> V_82 = F_24 ( V_76 ) + V_70 ;
V_8 = F_28 ( & V_66 -> V_33 , V_3 ) ;
if ( V_8 )
goto V_83;
F_29 ( & V_4 -> V_5 , F_17 ) ;
if ( F_8 ( V_7 -> V_9 ) ) {
int V_59 ;
V_8 = F_30 ( V_7 -> V_9 , L_4 ) ;
if ( V_8 )
goto V_84;
V_59 = F_31 ( V_7 -> V_9 ) ;
V_8 = F_32 ( V_59 , F_20 ,
V_85 | V_86 ,
L_5 , V_4 ) ;
if ( V_8 < 0 )
goto V_87;
}
F_33 ( V_66 , V_4 ) ;
F_4 ( & V_4 -> V_5 ,
F_5 ( 0 ) ) ;
return 0 ;
V_87:
F_34 ( V_7 -> V_9 ) ;
V_84:
F_35 ( V_3 ) ;
V_83:
for ( V_69 = 0 ; V_69 < F_24 ( V_77 ) ; V_69 ++ ) {
if ( V_4 -> V_30 [ V_69 ] )
F_36 ( V_4 -> V_30 [ V_69 ] ) ;
}
V_81:
F_37 ( V_3 -> V_68 ) ;
V_78:
return V_8 ;
}
static int F_38 ( struct V_65 * V_66 )
{
int V_69 ;
struct V_1 * V_4 = F_39 ( V_66 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_35 ( & V_4 -> V_3 ) ;
if ( F_8 ( V_7 -> V_9 ) ) {
F_40 ( F_31 ( V_7 -> V_9 ) , V_4 ) ;
F_34 ( V_7 -> V_9 ) ;
}
for ( V_69 = 0 ; V_69 < F_24 ( V_77 ) ; V_69 ++ ) {
if ( V_4 -> V_30 [ V_69 ] )
F_36 ( V_4 -> V_30 [ V_69 ] ) ;
}
F_37 ( V_4 -> V_3 . V_68 ) ;
F_41 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int F_42 ( struct V_88 * V_33 )
{
struct V_1 * V_4 = F_43 ( V_33 ) ;
F_44 ( & V_4 -> V_5 ) ;
V_4 -> V_18 = V_89 ;
return 0 ;
}
static int F_45 ( struct V_88 * V_33 )
{
struct V_1 * V_4 = F_43 ( V_33 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_61 ;
V_61 = V_7 -> V_62 ? V_7 -> V_62 : V_63 ;
F_4 ( & V_4 -> V_5 ,
F_5 ( V_61 ) ) ;
return 0 ;
}
