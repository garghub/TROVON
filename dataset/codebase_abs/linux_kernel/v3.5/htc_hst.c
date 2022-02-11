static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , T_2 V_6 , T_2 V_7 )
{
struct V_8 * V_9 ;
struct V_10 * V_11 = & V_2 -> V_11 [ V_7 ] ;
int V_12 ;
V_9 = (struct V_8 * )
F_2 ( V_4 , sizeof( struct V_8 ) ) ;
V_9 -> V_13 = V_7 ;
V_9 -> V_6 = V_6 ;
V_9 -> V_14 = F_3 ( V_5 ) ;
V_12 = V_2 -> V_15 -> V_16 ( V_2 -> V_17 , V_11 -> V_18 , V_4 ) ;
return V_12 ;
}
static struct V_10 * F_4 ( struct V_10 * V_11 )
{
enum V_19 V_20 ;
for ( V_20 = ( V_21 - 1 ) ; V_20 > V_22 ; V_20 -- )
if ( V_11 [ V_20 ] . V_23 == 0 )
return & V_11 [ V_20 ] ;
return NULL ;
}
static T_2 F_5 ( T_1 V_23 )
{
switch ( V_23 ) {
case V_24 :
return 4 ;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return 1 ;
default:
return 0 ;
}
}
static T_2 F_6 ( T_1 V_23 )
{
switch ( V_23 ) {
case V_24 :
return 3 ;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
case V_32 :
return 2 ;
default:
return 0 ;
}
}
static void F_7 ( struct V_1 * V_2 ,
void * V_33 )
{
struct V_10 * V_11 ;
struct V_34 * V_34 = (struct V_34 * ) V_33 ;
V_2 -> V_35 = F_8 ( V_34 -> V_35 ) ;
V_11 = & V_2 -> V_11 [ V_22 ] ;
V_11 -> V_23 = V_36 ;
V_11 -> V_37 = V_38 ;
F_9 ( & V_2 -> V_39 ) ;
F_10 ( & V_2 -> V_40 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_8 * V_41 )
{
struct V_42 * V_43 ;
struct V_10 * V_11 , * V_44 = NULL ;
T_1 V_23 ;
T_1 V_37 ;
enum V_19 V_7 , V_45 ;
V_43 = (struct V_42 * )
( ( void * ) V_41 + sizeof( struct V_8 ) ) ;
if ( V_43 -> V_12 == V_46 ) {
V_7 = V_43 -> V_13 ;
V_23 = F_8 ( V_43 -> V_23 ) ;
V_37 = F_8 ( V_43 -> V_47 ) ;
V_11 = & V_2 -> V_11 [ V_7 ] ;
for ( V_45 = ( V_21 - 1 ) ; V_45 > V_22 ; V_45 -- ) {
V_44 = & V_2 -> V_11 [ V_45 ] ;
if ( V_44 -> V_23 == V_23 ) {
V_44 -> V_23 = 0 ;
break;
}
}
if ( V_45 == V_22 )
return;
V_11 -> V_23 = V_23 ;
V_11 -> V_48 = V_44 -> V_48 ;
V_11 -> V_49 = V_44 -> V_49 ;
V_11 -> V_18 = V_44 -> V_18 ;
V_11 -> V_50 = V_44 -> V_50 ;
V_11 -> V_37 = V_37 ;
V_2 -> V_51 = V_7 ;
F_10 ( & V_2 -> V_52 ) ;
} else {
V_2 -> V_51 = V_53 ;
}
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_54 * V_55 ;
int V_56 , V_57 ;
V_4 = F_13 ( 50 + sizeof( struct V_8 ) , V_58 ) ;
if ( ! V_4 ) {
F_14 ( V_2 -> V_59 , L_1 ) ;
return - V_60 ;
}
F_15 ( V_4 , sizeof( struct V_8 ) ) ;
V_55 = (struct V_54 * )
F_16 ( V_4 , sizeof( struct V_54 ) ) ;
V_55 -> V_61 = F_3 ( V_62 ) ;
V_55 -> V_63 = V_64 ;
V_55 -> V_65 = V_2 -> V_65 ;
V_2 -> V_66 |= V_67 ;
V_56 = F_1 ( V_2 , V_4 , V_4 -> V_5 , 0 , V_22 ) ;
if ( V_56 )
goto V_68;
V_57 = F_17 ( & V_2 -> V_52 , V_69 ) ;
if ( ! V_57 ) {
F_14 ( V_2 -> V_59 , L_2 ) ;
return - V_70 ;
}
return 0 ;
V_68:
F_18 ( V_4 ) ;
return - V_71 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_72 * V_73 ;
int V_56 = 0 , V_57 ;
V_4 = F_13 ( 50 + sizeof( struct V_8 ) , V_58 ) ;
if ( ! V_4 ) {
F_14 ( V_2 -> V_59 , L_1 ) ;
return - V_60 ;
}
F_15 ( V_4 , sizeof( struct V_8 ) ) ;
V_73 = (struct V_72 * )
F_16 ( V_4 , sizeof( struct V_72 ) ) ;
V_73 -> V_74 = F_3 ( V_75 ) ;
V_2 -> V_66 |= V_76 ;
V_56 = F_1 ( V_2 , V_4 , V_4 -> V_5 , 0 , V_22 ) ;
if ( V_56 )
goto V_68;
V_57 = F_17 ( & V_2 -> V_52 , V_69 ) ;
if ( ! V_57 ) {
F_14 ( V_2 -> V_59 , L_3 ) ;
return - V_70 ;
}
return 0 ;
V_68:
F_18 ( V_4 ) ;
return - V_71 ;
}
int F_20 ( struct V_1 * V_2 )
{
int V_56 ;
V_56 = F_12 ( V_2 ) ;
if ( V_56 )
return V_56 ;
return F_19 ( V_2 ) ;
}
int F_21 ( struct V_1 * V_2 ,
struct V_77 * V_78 ,
enum V_19 * V_51 )
{
struct V_3 * V_4 ;
struct V_10 * V_11 ;
struct V_79 * V_80 ;
int V_56 , V_57 ;
V_11 = F_4 ( V_2 -> V_11 ) ;
if ( ! V_11 ) {
F_14 ( V_2 -> V_59 , L_4
L_5 , V_78 -> V_23 ) ;
return - V_71 ;
}
V_11 -> V_23 = V_78 -> V_23 ;
V_11 -> V_48 = V_78 -> V_81 ;
V_11 -> V_18 = F_5 ( V_78 -> V_23 ) ;
V_11 -> V_50 = F_6 ( V_78 -> V_23 ) ;
V_11 -> V_49 = V_78 -> V_49 ;
V_4 = F_13 ( sizeof( struct V_79 ) +
sizeof( struct V_8 ) , V_58 ) ;
if ( ! V_4 ) {
F_14 ( V_2 -> V_59 , L_6
L_7 ) ;
return - V_60 ;
}
F_15 ( V_4 , sizeof( struct V_8 ) ) ;
V_80 = (struct V_79 * )
F_16 ( V_4 , sizeof( struct V_79 ) ) ;
V_80 -> V_23 = F_3 ( V_78 -> V_23 ) ;
V_80 -> V_74 = F_3 ( V_82 ) ;
V_80 -> V_83 = F_3 ( V_78 -> V_83 ) ;
V_80 -> V_50 = V_11 -> V_50 ;
V_80 -> V_18 = V_11 -> V_18 ;
V_56 = F_1 ( V_2 , V_4 , V_4 -> V_5 , 0 , V_22 ) ;
if ( V_56 )
goto V_68;
V_57 = F_17 ( & V_2 -> V_52 , V_69 ) ;
if ( ! V_57 ) {
F_14 ( V_2 -> V_59 , L_8 ,
V_78 -> V_23 ) ;
return - V_70 ;
}
* V_51 = V_2 -> V_51 ;
return 0 ;
V_68:
F_18 ( V_4 ) ;
return V_56 ;
}
int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_84 * V_85 ;
V_85 = F_23 ( V_4 ) ;
return F_1 ( V_2 , V_4 , V_4 -> V_5 , 0 , V_85 -> V_7 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_3 * V_4 ,
enum V_19 V_7 )
{
return F_1 ( V_2 , V_4 , V_4 -> V_5 , 0 , V_7 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
V_2 -> V_15 -> V_86 ( V_2 -> V_17 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
V_2 -> V_15 -> V_87 ( V_2 -> V_17 ) ;
}
void F_27 ( struct V_1 * V_2 , T_2 V_88 )
{
V_2 -> V_15 -> V_89 ( V_2 -> V_17 , V_88 ) ;
}
void F_28 ( struct V_1 * V_90 ,
struct V_3 * V_4 , bool V_91 )
{
struct V_10 * V_11 ;
struct V_8 * V_41 = NULL ;
if ( V_90 -> V_66 & V_67 ) {
F_10 ( & V_90 -> V_52 ) ;
V_90 -> V_66 &= ~ V_67 ;
goto V_56;
}
if ( V_90 -> V_66 & V_76 ) {
F_10 ( & V_90 -> V_52 ) ;
V_90 -> V_66 &= ~ V_76 ;
goto V_56;
}
if ( V_4 ) {
V_41 = (struct V_8 * ) V_4 -> V_92 ;
V_11 = & V_90 -> V_11 [ V_41 -> V_13 ] ;
F_29 ( V_4 , sizeof( struct V_8 ) ) ;
if ( V_11 -> V_49 . V_93 ) {
V_11 -> V_49 . V_93 ( V_11 -> V_49 . V_94 ,
V_4 , V_41 -> V_13 ,
V_91 ) ;
}
}
return;
V_56:
if ( V_41 && V_41 -> V_13 != V_22 )
F_30 ( V_4 ) ;
else
F_18 ( V_4 ) ;
}
void F_31 ( struct V_1 * V_90 ,
struct V_3 * V_4 , T_3 V_5 , T_2 V_63 )
{
struct V_8 * V_41 ;
enum V_19 V_7 ;
struct V_10 * V_11 ;
T_4 * V_74 ;
if ( ! V_90 || ! V_4 )
return;
V_41 = (struct V_8 * ) V_4 -> V_92 ;
V_7 = V_41 -> V_13 ;
if ( V_7 >= V_21 ) {
if ( V_63 != V_95 )
F_30 ( V_4 ) ;
else
F_18 ( V_4 ) ;
return;
}
if ( V_7 == V_22 ) {
if ( V_41 -> V_6 & V_96 ) {
if ( F_32 ( * ( V_97 * ) V_4 -> V_92 ) == 0x00C60000 )
V_41 = (struct V_8 * ) ( V_4 -> V_92 + 4 ) ;
}
V_74 = ( T_4 * ) ( ( void * ) V_41 +
sizeof( struct V_8 ) ) ;
switch ( F_8 ( * V_74 ) ) {
case V_98 :
F_7 ( V_90 , V_41 ) ;
break;
case V_99 :
F_11 ( V_90 , V_41 ) ;
break;
default:
break;
}
F_18 ( V_4 ) ;
} else {
if ( V_41 -> V_6 & V_96 )
F_33 ( V_4 , V_5 - V_41 -> V_100 [ 0 ] ) ;
F_29 ( V_4 , sizeof( struct V_8 ) ) ;
V_11 = & V_90 -> V_11 [ V_7 ] ;
if ( V_11 -> V_49 . V_101 )
V_11 -> V_49 . V_101 ( V_11 -> V_49 . V_94 ,
V_4 , V_7 ) ;
}
}
struct V_1 * F_34 ( void * V_102 ,
struct V_103 * V_15 ,
struct V_104 * V_59 )
{
struct V_10 * V_11 ;
struct V_1 * V_2 ;
V_2 = F_35 ( sizeof( struct V_1 ) , V_105 ) ;
if ( ! V_2 )
return NULL ;
F_36 ( & V_2 -> V_40 ) ;
F_36 ( & V_2 -> V_52 ) ;
V_2 -> V_15 = V_15 ;
V_2 -> V_17 = V_102 ;
V_2 -> V_59 = V_59 ;
V_11 = & V_2 -> V_11 [ V_22 ] ;
V_11 -> V_18 = V_15 -> V_106 ;
V_11 -> V_50 = V_15 -> V_107 ;
F_37 ( & V_2 -> V_39 , 0 ) ;
return V_2 ;
}
void F_38 ( struct V_1 * V_108 )
{
F_39 ( V_108 ) ;
}
int F_40 ( struct V_1 * V_2 ,
struct V_104 * V_59 , T_1 V_109 ,
char * V_110 , T_3 V_111 )
{
if ( F_41 ( V_2 , V_59 , V_109 , V_110 , V_111 ) ) {
F_42 ( L_9 ) ;
return - V_112 ;
}
return 0 ;
}
void F_43 ( struct V_1 * V_2 , bool V_113 )
{
if ( V_2 )
F_44 ( V_2 , V_113 ) ;
}
