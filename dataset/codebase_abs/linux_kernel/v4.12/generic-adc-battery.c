static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
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
F_16 ( & V_3 -> V_33 , L_2 ) ;
return - V_34 ;
}
V_7 = V_4 -> V_7 ;
V_13 = & V_7 -> V_14 ;
switch ( V_21 ) {
case V_35 :
V_32 -> V_36 = F_9 ( V_4 ) ;
break;
case V_37 :
V_32 -> V_36 = 0 ;
break;
case V_38 :
V_32 -> V_36 = V_7 -> V_39 ( V_28 ) ;
break;
case V_24 :
case V_26 :
case V_22 :
V_8 = F_12 ( V_4 , V_21 , & V_28 ) ;
if ( V_8 < 0 )
goto V_40;
V_32 -> V_36 = V_28 ;
break;
case V_41 :
V_32 -> V_36 = V_13 -> V_42 ;
break;
case V_43 :
V_32 -> V_36 = V_13 -> V_44 ;
break;
case V_45 :
V_32 -> V_36 = V_13 -> V_46 ;
break;
case V_47 :
V_32 -> V_36 = V_13 -> V_16 ;
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
V_53 = F_18 ( V_52 ) ;
V_4 = F_19 ( V_53 , struct V_1 , V_5 ) ;
V_7 = V_4 -> V_7 ;
V_18 = V_4 -> V_18 ;
V_54 = F_20 ( V_4 -> V_3 ) ;
V_4 -> V_55 = V_54 ;
if ( ! V_54 )
V_4 -> V_18 = V_56 ;
else if ( F_6 ( V_4 ) )
V_4 -> V_18 = V_57 ;
else
V_4 -> V_18 = V_58 ;
if ( V_18 != V_4 -> V_18 )
F_21 ( V_4 -> V_3 ) ;
}
static T_1 F_22 ( int V_59 , void * V_60 )
{
struct V_1 * V_4 = V_60 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_61 ;
V_61 = V_7 -> V_62 ? V_7 -> V_62 : V_63 ;
F_4 ( & V_4 -> V_5 ,
F_5 ( V_61 ) ) ;
return V_64 ;
}
static int F_23 ( struct V_65 * V_66 )
{
struct V_1 * V_4 ;
struct V_67 * V_68 ;
struct V_69 V_70 = {} ;
struct V_6 * V_7 = V_66 -> V_33 . V_71 ;
enum V_20 * V_72 ;
int V_8 = 0 ;
int V_73 ;
int V_74 = 0 ;
V_4 = F_24 ( & V_66 -> V_33 , sizeof( * V_4 ) , V_75 ) ;
if ( ! V_4 ) {
F_16 ( & V_66 -> V_33 , L_3 ) ;
return - V_76 ;
}
V_70 . V_77 = V_4 ;
V_68 = & V_4 -> V_68 ;
V_68 -> V_50 = V_7 -> V_14 . V_50 ;
V_4 -> V_55 = false ;
V_4 -> V_18 = V_56 ;
V_68 -> type = V_78 ;
V_68 -> V_79 = F_15 ;
V_68 -> V_80 = F_3 ;
V_4 -> V_7 = V_7 ;
V_68 -> V_72 = F_25 ( F_26 ( V_81 ) +
F_26 ( V_82 ) ,
sizeof( * V_68 -> V_72 ) ,
V_75 ) ;
if ( ! V_68 -> V_72 ) {
V_8 = - V_76 ;
goto V_83;
}
memcpy ( V_68 -> V_72 , V_81 , sizeof( V_81 ) ) ;
V_72 = (enum V_20 * )
( ( char * ) V_68 -> V_72 + sizeof( V_81 ) ) ;
for ( V_73 = 0 ; V_73 < F_26 ( V_82 ) ; V_73 ++ ) {
V_4 -> V_30 [ V_73 ] = F_27 ( & V_66 -> V_33 ,
V_82 [ V_73 ] ) ;
if ( F_28 ( V_4 -> V_30 [ V_73 ] ) ) {
V_8 = F_29 ( V_4 -> V_30 [ V_73 ] ) ;
V_4 -> V_30 [ V_73 ] = NULL ;
} else {
memcpy ( V_72 + sizeof( * ( V_68 -> V_72 ) ) * V_74 ,
& V_84 [ V_73 ] ,
sizeof( V_84 [ V_73 ] ) ) ;
V_74 ++ ;
}
}
if ( V_74 == 0 ) {
V_8 = - V_85 ;
goto V_86;
}
V_68 -> V_87 = F_26 ( V_81 ) + V_74 ;
V_4 -> V_3 = F_30 ( & V_66 -> V_33 , V_68 , & V_70 ) ;
if ( F_28 ( V_4 -> V_3 ) ) {
V_8 = F_29 ( V_4 -> V_3 ) ;
goto V_88;
}
F_31 ( & V_4 -> V_5 , F_17 ) ;
if ( F_8 ( V_7 -> V_9 ) ) {
int V_59 ;
V_8 = F_32 ( V_7 -> V_9 , L_4 ) ;
if ( V_8 )
goto V_89;
V_59 = F_33 ( V_7 -> V_9 ) ;
V_8 = F_34 ( V_59 , F_22 ,
V_90 | V_91 ,
L_5 , V_4 ) ;
if ( V_8 < 0 )
goto V_92;
}
F_35 ( V_66 , V_4 ) ;
F_4 ( & V_4 -> V_5 ,
F_5 ( 0 ) ) ;
return 0 ;
V_92:
F_36 ( V_7 -> V_9 ) ;
V_89:
F_37 ( V_4 -> V_3 ) ;
V_88:
for ( V_73 = 0 ; V_73 < F_26 ( V_82 ) ; V_73 ++ ) {
if ( V_4 -> V_30 [ V_73 ] )
F_38 ( V_4 -> V_30 [ V_73 ] ) ;
}
V_86:
F_39 ( V_68 -> V_72 ) ;
V_83:
return V_8 ;
}
static int F_40 ( struct V_65 * V_66 )
{
int V_73 ;
struct V_1 * V_4 = F_41 ( V_66 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
F_37 ( V_4 -> V_3 ) ;
if ( F_8 ( V_7 -> V_9 ) ) {
F_42 ( F_33 ( V_7 -> V_9 ) , V_4 ) ;
F_36 ( V_7 -> V_9 ) ;
}
for ( V_73 = 0 ; V_73 < F_26 ( V_82 ) ; V_73 ++ ) {
if ( V_4 -> V_30 [ V_73 ] )
F_38 ( V_4 -> V_30 [ V_73 ] ) ;
}
F_39 ( V_4 -> V_68 . V_72 ) ;
F_43 ( & V_4 -> V_5 ) ;
return 0 ;
}
static int T_2 F_44 ( struct V_93 * V_33 )
{
struct V_1 * V_4 = F_45 ( V_33 ) ;
F_46 ( & V_4 -> V_5 ) ;
V_4 -> V_18 = V_94 ;
return 0 ;
}
static int T_2 F_47 ( struct V_93 * V_33 )
{
struct V_1 * V_4 = F_45 ( V_33 ) ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_61 ;
V_61 = V_7 -> V_62 ? V_7 -> V_62 : V_63 ;
F_4 ( & V_4 -> V_5 ,
F_5 ( V_61 ) ) ;
return 0 ;
}
