static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 * V_4 , T_1 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 V_10 = { 0 } ;
int V_11 ;
F_2 ( V_2 , & V_10 , V_12 , - 1 , - 1 ) ;
V_10 . V_13 = F_3 ( V_3 ) ;
sprintf ( V_10 . V_14 , L_1 , V_3 ) ;
F_4 ( & V_2 -> V_15 ) ;
V_11 = F_5 ( V_2 , & V_10 , sizeof( V_10 ) , V_16 ) ;
if ( ! V_11 ) {
* V_4 = F_6 ( V_7 -> V_4 ) ;
* V_5 = F_6 ( V_7 -> V_5 ) ;
F_7 ( V_2 -> V_17 , L_2 ,
* V_4 , * V_5 ) ;
} else {
F_8 ( V_2 -> V_17 , L_3 , V_18 , V_11 ) ;
}
F_9 ( & V_2 -> V_15 ) ;
return V_11 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_19 V_10 = { 0 } ;
int V_11 ;
F_2 ( V_2 , & V_10 , V_20 , - 1 , - 1 ) ;
sprintf ( V_10 . V_14 , L_1 , V_3 ) ;
V_11 = F_11 ( V_2 , & V_10 , sizeof( V_10 ) , V_16 ) ;
if ( V_11 )
F_8 ( V_2 -> V_17 , L_3 , V_18 , V_11 ) ;
return V_11 ;
}
static int F_12 ( struct V_21 * V_17 )
{
struct V_22 * V_23 = F_13 ( V_17 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
if ( F_14 ( V_2 -> V_17 ) ) {
F_15 ( V_17 ) ;
F_16 ( V_17 ) ;
}
return 0 ;
}
static int F_17 ( struct V_21 * V_17 )
{
F_18 ( V_17 ) ;
F_19 ( V_17 ) ;
return 0 ;
}
static T_2 F_20 ( struct V_24 * V_25 ,
struct V_21 * V_17 )
{
struct V_22 * V_23 = F_13 ( V_17 ) ;
int V_11 , V_26 = V_25 -> V_26 ;
F_21 ( V_25 ) ;
F_22 ( (struct V_27 * ) V_23 -> V_28 ) ;
F_23 ( V_25 , (struct V_27 * ) V_23 -> V_28 ) ;
V_25 -> V_17 = V_23 -> V_28 -> V_29 . V_30 . V_31 ;
V_11 = F_24 ( V_25 ) ;
if ( ! V_11 ) {
V_23 -> V_32 . V_33 ++ ;
V_23 -> V_32 . V_34 += V_26 ;
}
return V_11 ;
}
static void
F_25 ( struct V_21 * V_17 ,
struct V_35 * V_36 )
{
struct V_22 * V_23 = F_13 ( V_17 ) ;
V_36 -> V_37 = V_23 -> V_38 . V_33 ;
V_36 -> V_39 = V_23 -> V_38 . V_34 ;
V_36 -> V_40 = V_23 -> V_32 . V_33 ;
V_36 -> V_41 = V_23 -> V_32 . V_34 ;
}
static int F_26 ( struct V_21 * V_17 , enum V_42 type ,
void * V_43 )
{
struct V_22 * V_23 = F_13 ( V_17 ) ;
struct V_1 * V_2 = V_23 -> V_2 ;
int V_44 = V_2 -> V_45 . V_46 [ V_23 -> V_3 ] . V_47 ;
switch ( type ) {
case V_48 :
return F_27 ( V_2 , V_44 , V_43 ) ;
default:
return - V_49 ;
}
}
struct V_21 * F_28 ( struct V_1 * V_2 , T_1 V_50 )
{
T_1 V_3 ;
if ( V_50 && V_2 -> V_51 && F_29 ( V_2 ) ) {
V_3 = V_2 -> V_51 [ V_50 ] ;
if ( V_3 != V_52 )
return V_2 -> V_53 [ V_3 ] -> V_17 ;
}
return NULL ;
}
void F_30 ( struct V_1 * V_2 , struct V_24 * V_25 )
{
struct V_22 * V_23 = F_13 ( V_25 -> V_17 ) ;
struct V_54 * V_38 ;
V_38 = & V_23 -> V_38 ;
V_23 -> V_38 . V_34 += V_25 -> V_26 ;
V_23 -> V_38 . V_33 ++ ;
F_31 ( V_25 ) ;
}
static int F_32 ( struct V_21 * V_17 , char * V_55 ,
T_3 V_26 )
{
struct V_22 * V_23 = F_13 ( V_17 ) ;
struct V_56 * V_57 = V_23 -> V_2 -> V_58 ;
int V_11 ;
V_11 = snprintf ( V_55 , V_26 , L_4 , F_33 ( V_57 -> V_59 ) ,
V_23 -> V_3 ) ;
if ( V_11 >= V_26 )
return - V_49 ;
return 0 ;
}
static void F_34 ( struct V_21 * V_17 ,
struct V_60 * V_61 )
{
F_35 ( V_61 -> V_62 , V_63 , sizeof( V_61 -> V_62 ) ) ;
F_35 ( V_61 -> V_64 , V_65 , sizeof( V_61 -> V_64 ) ) ;
}
static int F_36 ( struct V_21 * V_17 ,
struct V_66 * V_67 )
{
struct V_22 * V_23 = F_13 ( V_17 ) ;
return F_37 ( V_23 -> V_2 , V_67 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
struct V_22 * V_23 ;
T_1 V_68 , V_69 ;
if ( V_2 -> V_70 != V_71 )
return;
V_68 = F_39 ( V_2 -> V_58 ) ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
V_23 = V_2 -> V_53 [ V_69 ] ;
if ( F_14 ( V_23 -> V_17 ) )
F_17 ( V_23 -> V_17 ) ;
}
}
void F_40 ( struct V_1 * V_2 )
{
int V_69 ;
if ( V_2 -> V_70 != V_71 )
return;
for ( V_69 = 0 ; V_69 < F_39 ( V_2 -> V_58 ) ; V_69 ++ )
F_12 ( V_2 -> V_53 [ V_69 ] -> V_17 ) ;
}
static void F_41 ( struct V_1 * V_2 )
{
T_1 V_68 = F_39 ( V_2 -> V_58 ) ;
struct V_22 * V_23 ;
int V_69 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
V_23 = V_2 -> V_53 [ V_69 ] ;
if ( V_23 ) {
F_42 ( (struct V_27 * ) V_23 -> V_28 ) ;
if ( V_23 -> V_4 != V_72 )
F_10 ( V_2 , V_23 -> V_3 ) ;
if ( V_23 -> V_17 ) {
if ( V_23 -> V_17 -> V_73 )
F_43 ( V_23 -> V_17 ) ;
F_44 ( V_23 -> V_17 ) ;
}
}
}
F_45 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
}
void F_46 ( struct V_1 * V_2 )
{
bool V_74 = false ;
if ( V_2 -> V_70 != V_71 )
return;
if ( ! V_2 -> V_53 )
return;
F_47 () ;
if ( F_14 ( V_2 -> V_17 ) ) {
F_48 ( V_2 , false , false ) ;
V_74 = true ;
}
F_45 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
V_2 -> V_70 = V_75 ;
if ( V_74 )
F_49 ( V_2 , false , false ) ;
F_50 () ;
F_41 ( V_2 ) ;
}
static void F_51 ( T_4 * V_76 , T_1 V_3 , T_4 * V_77 )
{
T_5 V_78 ;
F_52 ( V_77 , V_76 ) ;
V_78 = F_53 ( V_76 , V_79 , 0 ) + V_3 ;
V_77 [ 3 ] = ( T_4 ) ( V_78 & 0xFF ) ;
V_77 [ 4 ] = ( T_4 ) ( ( V_78 >> 8 ) & 0xFF ) ;
V_77 [ 5 ] = ( T_4 ) ( ( V_78 >> 16 ) & 0xFF ) ;
}
static void F_54 ( struct V_1 * V_2 , struct V_22 * V_23 ,
struct V_21 * V_17 )
{
struct V_21 * V_80 = V_2 -> V_17 ;
V_17 -> V_73 = & V_81 ;
V_17 -> V_82 = & V_83 ;
F_55 ( V_17 , & V_84 ) ;
V_17 -> V_85 = V_80 -> V_85 ;
V_17 -> V_86 = V_80 -> V_86 ;
V_17 -> V_87 = V_80 -> V_87 ;
V_17 -> V_88 = V_80 -> V_88 ;
V_17 -> V_89 |= V_80 -> V_89 ;
F_51 ( V_2 -> V_45 . V_90 , V_23 -> V_3 ,
V_17 -> V_91 ) ;
F_52 ( V_17 -> V_92 , V_17 -> V_91 ) ;
}
static int F_56 ( struct V_1 * V_2 )
{
T_1 * V_51 = NULL , V_68 = F_39 ( V_2 -> V_58 ) ;
struct V_22 * V_23 ;
struct V_21 * V_17 ;
int V_11 , V_69 ;
V_2 -> V_53 = F_57 ( V_68 , sizeof( V_23 ) , V_93 ) ;
if ( ! V_2 -> V_53 )
return - V_94 ;
V_51 = F_58 ( sizeof( * V_2 -> V_51 ) * V_95 ,
V_93 ) ;
if ( ! V_51 ) {
V_11 = - V_94 ;
goto V_96;
}
for ( V_69 = 0 ; V_69 < V_95 ; V_69 ++ )
V_51 [ V_69 ] = V_52 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
V_17 = F_59 ( sizeof( * V_23 ) ) ;
if ( ! V_17 ) {
V_11 = - V_94 ;
goto V_96;
}
V_23 = F_13 ( V_17 ) ;
V_2 -> V_53 [ V_69 ] = V_23 ;
V_23 -> V_17 = V_17 ;
V_23 -> V_2 = V_2 ;
V_23 -> V_3 = V_69 ;
V_23 -> V_4 = V_72 ;
V_11 = F_1 ( V_2 , V_23 -> V_3 ,
& V_23 -> V_4 ,
& V_23 -> V_5 ) ;
if ( V_11 ) {
V_11 = - V_97 ;
goto V_96;
}
V_51 [ V_23 -> V_5 ] = V_23 -> V_3 ;
V_23 -> V_28 = F_60 ( 0 , V_98 ,
V_93 ) ;
if ( ! V_23 -> V_28 ) {
V_11 = - V_94 ;
goto V_96;
}
V_23 -> V_28 -> V_29 . V_30 . V_99 = V_23 -> V_4 ;
V_23 -> V_28 -> V_29 . V_30 . V_31 = V_2 -> V_17 ;
F_54 ( V_2 , V_23 , V_17 ) ;
V_11 = F_61 ( V_17 ) ;
if ( V_11 ) {
V_17 -> V_73 = NULL ;
goto V_96;
}
}
V_2 -> V_51 = V_51 ;
V_2 -> V_70 = V_71 ;
F_62 ( V_2 -> V_17 ) ;
return 0 ;
V_96:
F_8 ( V_2 -> V_17 , L_5 , V_18 , V_11 ) ;
F_45 ( V_51 ) ;
F_41 ( V_2 ) ;
return V_11 ;
}
static int F_63 ( struct V_100 * V_100 , T_1 * V_101 )
{
struct V_1 * V_2 = F_64 ( V_100 ) ;
* V_101 = V_2 -> V_70 ;
return 0 ;
}
static int F_65 ( struct V_100 * V_100 , T_1 V_101 )
{
struct V_1 * V_2 = F_64 ( V_100 ) ;
int V_11 = 0 ;
F_4 ( & V_2 -> V_102 ) ;
if ( V_2 -> V_70 == V_101 ) {
F_8 ( V_2 -> V_17 , L_6 ,
V_101 == V_75 ?
L_7 : L_8 ) ;
V_11 = - V_103 ;
goto V_104;
}
switch ( V_101 ) {
case V_75 :
F_46 ( V_2 ) ;
break;
case V_71 :
if ( F_39 ( V_2 -> V_58 ) == 0 ) {
F_8 ( V_2 -> V_17 ,
L_9 ) ;
V_11 = - V_105 ;
goto V_104;
}
V_11 = F_56 ( V_2 ) ;
break;
default:
V_11 = - V_103 ;
goto V_104;
}
V_104:
F_9 ( & V_2 -> V_102 ) ;
return V_11 ;
}
int F_66 ( struct V_1 * V_2 )
{
struct V_100 * V_106 ;
int V_11 ;
if ( ! F_67 ( V_2 -> V_58 , V_107 ) )
return 0 ;
if ( V_2 -> V_108 < 0x10800 ) {
F_68 ( V_2 -> V_17 , L_10 ) ;
return - V_109 ;
}
V_106 = F_69 ( & V_110 , sizeof( struct V_111 ) ) ;
if ( ! V_106 ) {
F_68 ( V_2 -> V_17 , L_11 ) ;
return - V_94 ;
}
F_70 ( V_2 , V_106 ) ;
V_2 -> V_70 = V_75 ;
V_11 = F_71 ( V_106 , & V_2 -> V_58 -> V_17 ) ;
if ( V_11 ) {
F_70 ( V_2 , NULL ) ;
F_72 ( V_106 ) ;
F_68 ( V_2 -> V_17 , L_12 , V_11 ) ;
return V_11 ;
}
return 0 ;
}
void F_73 ( struct V_1 * V_2 )
{
struct V_100 * V_106 = V_2 -> V_106 ;
if ( ! V_106 )
return;
F_74 ( V_106 ) ;
F_72 ( V_106 ) ;
}
