static bool F_1 ( struct V_1 * V_2 , void * V_3 )
{
if ( ! F_2 ( V_2 ) )
return false ;
V_2 -> V_4 = V_3 ;
return true ;
}
static void F_3 ( void * V_5 )
{
struct V_6 * V_7 = V_5 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_13 += F_4 ( V_7 ) ;
if ( V_11 -> V_13 >= F_5 ( V_7 ) )
V_11 -> V_13 = 0 ;
F_6 ( V_7 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
T_1 V_14 = V_7 -> V_15 == V_16 ? V_17 : V_18 ;
struct V_19 * V_20 = V_7 -> V_12 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
unsigned long V_24 = V_25 ;
if ( ! V_7 -> V_9 -> V_26 )
V_24 |= V_27 ;
V_11 -> V_13 = 0 ;
V_11 -> V_28 [ ! V_14 ] = F_8 (
V_11 -> V_1 [ ! V_14 ] , V_9 -> V_29 ,
F_5 ( V_7 ) ,
F_4 ( V_7 ) ,
V_14 == V_17 ? V_30 : V_31 , V_24 ) ;
if ( ! V_11 -> V_28 [ ! V_14 ] ) {
F_9 ( V_22 , L_1 ) ;
return - V_32 ;
}
V_11 -> V_28 [ ! V_14 ] -> V_33 = F_3 ;
V_11 -> V_28 [ ! V_14 ] -> V_34 = V_7 ;
F_10 ( V_11 -> V_28 [ ! V_14 ] ) ;
V_11 -> V_28 [ V_14 ] = F_8 (
V_11 -> V_1 [ V_14 ] , 0xffff , 64 , 64 , V_35 , 0 ) ;
if ( ! V_11 -> V_28 [ V_14 ] ) {
F_9 ( V_22 , L_2 ) ;
return - V_32 ;
}
F_10 ( V_11 -> V_28 [ V_14 ] ) ;
return 0 ;
}
static int F_11 ( struct V_6 * V_7 , int V_36 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_37 ;
switch ( V_36 ) {
case V_38 :
case V_39 :
case V_40 :
V_37 = F_7 ( V_7 ) ;
if ( V_37 )
return V_37 ;
F_12 ( V_11 -> V_1 [ V_18 ] ) ;
F_12 ( V_11 -> V_1 [ V_17 ] ) ;
break;
case V_41 :
case V_42 :
case V_43 :
F_13 ( V_11 -> V_1 [ V_17 ] ) ;
F_13 ( V_11 -> V_1 [ V_18 ] ) ;
break;
default:
return - V_44 ;
}
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_45 * V_46 )
{
enum V_47 V_48 = V_49 ;
struct V_19 * V_20 = V_7 -> V_12 ;
bool V_50 = V_7 -> V_15 == V_16 ;
struct V_51 * V_52 = NULL ;
struct V_51 * V_53 = NULL ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_54 * V_55 = V_11 -> V_55 ;
struct V_56 V_57 , V_58 ;
enum V_59 V_60 = V_11 -> V_60 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
int V_15 = V_7 -> V_15 ;
struct V_61 * V_62 ;
struct V_63 * V_64 ;
struct V_1 * V_65 ;
struct V_21 * V_66 ;
T_1 V_14 = V_50 ? V_17 : V_18 ;
T_2 V_67 ;
int V_37 ;
F_15 (dpcm, &rtd->dpcm[stream].be_clients, list_be) {
struct V_19 * V_68 = V_64 -> V_68 ;
struct V_6 * V_69 ;
struct V_70 * V_71 = V_68 -> V_72 ;
if ( V_64 -> V_73 != V_20 )
continue;
V_69 = F_16 ( V_68 , V_15 ) ;
V_53 = F_17 ( V_71 , V_69 ) ;
V_66 = V_71 -> V_22 ;
break;
}
if ( ! V_53 ) {
F_9 ( V_22 , L_3 ) ;
return - V_44 ;
}
V_52 = F_17 ( V_20 -> V_72 , V_7 ) ;
V_52 -> V_74 = V_55 -> V_75 + F_18 ( ! V_14 , V_60 ) ;
V_52 -> V_76 = V_53 -> V_76 ;
V_11 -> V_1 [ ! V_14 ] = F_19 ( V_11 , ! V_14 ) ;
if ( ! V_11 -> V_1 [ ! V_14 ] ) {
F_9 ( V_22 , L_4 ) ;
return - V_44 ;
}
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_37 = F_20 ( V_7 , V_46 , & V_57 ) ;
if ( V_37 ) {
F_9 ( V_22 , L_5 ) ;
return V_37 ;
}
V_37 = F_21 ( V_11 -> V_1 [ ! V_14 ] , & V_57 ) ;
if ( V_37 ) {
F_9 ( V_22 , L_6 ) ;
return V_37 ;
}
F_22 ( V_67 ) ;
F_23 ( V_77 , V_67 ) ;
F_23 ( V_78 , V_67 ) ;
V_65 = F_24 ( V_66 , V_50 ? L_7 : L_8 ) ;
V_62 = V_65 -> V_4 ;
V_11 -> V_79 . V_80 = V_62 -> V_80 ;
F_25 ( V_65 ) ;
V_65 = F_19 ( V_11 , V_14 ) ;
V_62 = V_65 -> V_4 ;
V_11 -> V_79 . V_81 = V_62 -> V_80 ;
V_11 -> V_79 . V_82 = V_62 -> V_82 ;
V_11 -> V_79 . V_83 = V_62 -> V_83 ;
F_25 ( V_65 ) ;
V_11 -> V_1 [ V_14 ] = F_26 ( V_67 , F_1 , & V_11 -> V_79 ) ;
if ( ! V_11 -> V_1 [ V_14 ] ) {
F_9 ( V_22 , L_9 ) ;
return - V_44 ;
}
if ( V_55 -> V_84 == 16 )
V_48 = V_49 ;
else
V_48 = V_85 ;
V_58 . V_86 = V_35 ;
V_58 . V_87 = V_48 ;
V_58 . V_88 = V_53 -> V_76 ;
V_58 . V_89 = V_48 ;
V_58 . V_90 = V_53 -> V_76 ;
if ( V_50 ) {
V_58 . V_91 = V_55 -> V_75 + F_27 ( V_60 ) ;
V_58 . V_92 = V_53 -> V_74 ;
} else {
V_58 . V_92 = V_55 -> V_75 + F_28 ( V_60 ) ;
V_58 . V_91 = V_53 -> V_74 ;
}
V_37 = F_21 ( V_11 -> V_1 [ V_14 ] , & V_58 ) ;
if ( V_37 ) {
F_9 ( V_22 , L_10 ) ;
return V_37 ;
}
F_29 ( V_7 , & V_7 -> V_93 ) ;
return 0 ;
}
static int F_30 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
F_29 ( V_7 , NULL ) ;
if ( V_11 -> V_1 [ V_18 ] )
F_25 ( V_11 -> V_1 [ V_18 ] ) ;
if ( V_11 -> V_1 [ V_17 ] )
F_25 ( V_11 -> V_1 [ V_17 ] ) ;
V_11 -> V_1 [ V_18 ] = NULL ;
V_11 -> V_1 [ V_17 ] = NULL ;
return 0 ;
}
static int F_31 ( struct V_6 * V_7 )
{
struct V_19 * V_20 = V_7 -> V_12 ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_21 * V_22 = V_20 -> V_23 -> V_22 ;
struct V_54 * V_55 = F_32 ( V_22 ) ;
struct V_10 * V_11 ;
V_11 = F_33 ( sizeof( struct V_10 ) , V_94 ) ;
if ( ! V_11 )
return - V_32 ;
V_11 -> V_55 = V_55 ;
V_9 -> V_12 = V_11 ;
F_34 ( V_7 -> V_9 ,
V_95 ) ;
F_35 ( V_7 , & V_96 ) ;
return 0 ;
}
static int F_36 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
struct V_54 * V_55 ;
if ( ! V_11 )
return 0 ;
V_55 = V_11 -> V_55 ;
if ( V_55 -> V_11 [ V_11 -> V_60 ] == V_11 )
V_55 -> V_11 [ V_11 -> V_60 ] = NULL ;
F_37 ( V_11 ) ;
return 0 ;
}
static T_3 F_38 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_10 * V_11 = V_9 -> V_12 ;
return F_39 ( V_7 -> V_9 , V_11 -> V_13 ) ;
}
static int F_40 ( struct V_19 * V_20 )
{
struct V_97 * V_98 = V_20 -> V_98 -> V_97 ;
struct V_6 * V_7 ;
struct V_99 * V_100 = V_20 -> V_100 ;
int V_37 , V_101 ;
V_37 = F_41 ( V_98 -> V_22 , F_42 ( 32 ) ) ;
if ( V_37 ) {
F_9 ( V_98 -> V_22 , L_11 ) ;
return V_37 ;
}
for ( V_101 = V_16 ; V_101 <= V_102 ; V_101 ++ ) {
V_7 = V_100 -> V_103 [ V_101 ] . V_7 ;
if ( ! V_7 )
continue;
V_37 = F_43 ( V_104 , V_100 -> V_98 -> V_22 ,
V_105 , & V_7 -> V_93 ) ;
if ( V_37 ) {
F_9 ( V_98 -> V_22 , L_12 ) ;
goto V_106;
}
}
return 0 ;
V_106:
if ( -- V_101 == 0 && V_100 -> V_103 [ V_101 ] . V_7 )
F_44 ( & V_100 -> V_103 [ V_101 ] . V_7 -> V_93 ) ;
return V_37 ;
}
static void F_45 ( struct V_99 * V_100 )
{
struct V_6 * V_7 ;
int V_101 ;
for ( V_101 = V_16 ; V_101 <= V_102 ; V_101 ++ ) {
V_7 = V_100 -> V_103 [ V_101 ] . V_7 ;
if ( ! V_7 )
continue;
F_44 ( & V_7 -> V_93 ) ;
V_7 -> V_93 . V_107 = NULL ;
V_7 -> V_93 . V_74 = 0 ;
}
}
