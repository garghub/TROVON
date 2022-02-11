int F_1 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
V_1 -> V_4 ++ ;
if ( V_1 -> V_4 == 1 ) {
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
V_2 = F_3 ( V_1 -> V_8 ) ;
if ( V_2 != 0 )
goto V_9;
break;
}
V_2 = F_4 ( V_1 -> V_10 , V_11 ,
V_12 ,
V_12 ) ;
}
V_9:
if ( V_2 != 0 )
V_1 -> V_4 -- ;
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
int F_6 ( struct V_1 * V_1 )
{
int V_2 = 0 ;
F_2 ( & V_1 -> V_3 ) ;
F_7 ( V_1 -> V_4 <= 0 ) ;
V_1 -> V_4 -- ;
if ( V_1 -> V_4 == 0 ) {
F_4 ( V_1 -> V_10 , V_11 ,
V_12 , 0 ) ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
F_8 ( V_1 -> V_8 ) ;
break;
}
}
F_5 ( & V_1 -> V_3 ) ;
return V_2 ;
}
static T_1 F_9 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
F_10 ( V_1 -> V_8 , L_1 ) ;
return V_15 ;
}
static T_1 F_11 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 ;
int V_2 ;
V_2 = F_12 ( V_1 -> V_10 , V_17 ,
& V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_2 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 & V_19 )
F_10 ( V_1 -> V_8 , L_3 ) ;
if ( V_16 & V_20 )
F_10 ( V_1 -> V_8 , L_4 ) ;
if ( V_16 & V_21 )
F_10 ( V_1 -> V_8 , L_5 ) ;
if ( V_16 & V_22 )
F_10 ( V_1 -> V_8 , L_6 ) ;
if ( V_16 & V_23 )
F_10 ( V_1 -> V_8 , L_7 ) ;
if ( V_16 & V_24 )
F_10 ( V_1 -> V_8 , L_8 ) ;
if ( V_16 & V_25 )
F_10 ( V_1 -> V_8 , L_9 ) ;
if ( V_16 & V_26 )
F_10 ( V_1 -> V_8 , L_10 ) ;
if ( V_16 & V_27 )
F_10 ( V_1 -> V_8 , L_11 ) ;
if ( V_16 & V_28 )
F_10 ( V_1 -> V_8 , L_12 ) ;
if ( V_16 & V_29 )
F_10 ( V_1 -> V_8 , L_13 ) ;
return V_15 ;
}
static T_1 F_13 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
unsigned int V_16 [ 2 ] ;
int V_2 ;
V_2 = F_14 ( V_1 -> V_10 , V_30 ,
& V_16 [ 0 ] , 2 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_14 ,
V_2 ) ;
return V_18 ;
}
if ( V_16 [ 0 ] & V_31 )
F_10 ( V_1 -> V_8 , L_15 ) ;
if ( V_16 [ 0 ] & V_32 )
F_10 ( V_1 -> V_8 , L_16 ) ;
if ( V_16 [ 0 ] & V_33 )
F_10 ( V_1 -> V_8 , L_17 ) ;
if ( V_16 [ 0 ] & V_34 )
F_10 ( V_1 -> V_8 , L_18 ) ;
if ( V_16 [ 0 ] & V_35 )
F_10 ( V_1 -> V_8 , L_19 ) ;
if ( V_16 [ 0 ] & V_36 )
F_10 ( V_1 -> V_8 , L_20 ) ;
if ( V_16 [ 0 ] & V_37 )
F_10 ( V_1 -> V_8 , L_21 ) ;
if ( V_16 [ 0 ] & V_38 )
F_10 ( V_1 -> V_8 , L_22 ) ;
if ( V_16 [ 0 ] & V_39 )
F_10 ( V_1 -> V_8 , L_23 ) ;
if ( V_16 [ 0 ] & V_40 )
F_10 ( V_1 -> V_8 , L_24 ) ;
if ( V_16 [ 1 ] & V_41 )
F_10 ( V_1 -> V_8 , L_25 ) ;
if ( V_16 [ 1 ] & V_42 )
F_10 ( V_1 -> V_8 , L_26 ) ;
if ( V_16 [ 1 ] & V_43 )
F_10 ( V_1 -> V_8 , L_27 ) ;
if ( V_16 [ 1 ] & V_44 )
F_10 ( V_1 -> V_8 , L_28 ) ;
if ( V_16 [ 1 ] & V_45 )
F_10 ( V_1 -> V_8 , L_29 ) ;
if ( V_16 [ 1 ] & V_46 )
F_10 ( V_1 -> V_8 , L_30 ) ;
if ( V_16 [ 1 ] & V_47 )
F_10 ( V_1 -> V_8 , L_31 ) ;
if ( V_16 [ 1 ] & V_48 )
F_10 ( V_1 -> V_8 , L_32 ) ;
if ( V_16 [ 1 ] & V_49 )
F_10 ( V_1 -> V_8 , L_33 ) ;
if ( V_16 [ 1 ] & V_50 )
F_10 ( V_1 -> V_8 , L_34 ) ;
if ( V_16 [ 1 ] & V_51 )
F_10 ( V_1 -> V_8 , L_35 ) ;
return V_15 ;
}
static int F_15 ( struct V_1 * V_1 ,
int V_52 , unsigned int V_53 ,
unsigned int V_54 , unsigned int V_55 )
{
unsigned int V_16 = 0 ;
int V_2 , V_56 ;
for ( V_56 = 0 ; V_56 < V_52 ; V_56 ++ ) {
V_2 = F_12 ( V_1 -> V_10 , V_53 , & V_16 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_36 ,
V_53 , V_2 ) ;
continue;
}
if ( ( V_16 & V_54 ) == V_55 )
return 0 ;
F_16 ( 1 ) ;
}
F_10 ( V_1 -> V_8 , L_37 , V_53 , V_16 ) ;
return - V_57 ;
}
static int F_17 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_15 ( V_1 , 5 , V_58 ,
V_59 , V_59 ) ;
if ( ! V_2 )
F_18 ( V_1 -> V_10 , V_60 ,
V_59 ) ;
F_19 ( V_1 -> V_8 ) ;
return V_2 ;
}
static inline void F_20 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_61 )
F_21 ( V_1 -> V_5 . V_61 , 0 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
if ( V_1 -> V_5 . V_61 ) {
switch ( V_1 -> type ) {
case V_62 :
case V_63 :
F_16 ( 5 ) ;
break;
default:
break;
}
F_21 ( V_1 -> V_5 . V_61 , 1 ) ;
F_16 ( 1 ) ;
}
}
static int F_23 ( struct V_1 * V_1 ,
struct V_64 * V_65 )
{
int V_2 , V_66 ;
V_2 = F_12 ( V_1 -> V_10 , V_67 , & V_65 -> V_68 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_38 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_12 ( V_1 -> V_10 , V_69 ,
& V_65 -> V_70 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_39 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_67 ,
V_71 | V_72 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_40 ,
V_2 ) ;
return V_2 ;
}
V_2 = F_15 ( V_1 , 25 , V_58 ,
V_73 ,
V_73 ) ;
if ( V_2 ) {
V_2 = - V_57 ;
goto V_74;
}
V_2 = F_18 ( V_1 -> V_10 , V_69 , 0x0144 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_41 , V_2 ) ;
goto V_74;
}
return 0 ;
V_74:
V_66 = F_18 ( V_1 -> V_10 , V_67 , V_65 -> V_68 ) ;
if ( V_66 )
F_10 ( V_1 -> V_8 ,
L_42 , V_66 ) ;
return V_2 ;
}
static int F_24 ( struct V_1 * V_1 ,
struct V_64 * V_65 )
{
int V_2 ;
V_2 = F_18 ( V_1 -> V_10 , V_69 ,
V_65 -> V_70 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_43 , V_2 ) ;
return V_2 ;
}
V_2 = F_18 ( V_1 -> V_10 , V_67 , V_65 -> V_68 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_42 , V_2 ) ;
return V_2 ;
}
return 0 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_64 V_65 ;
int V_66 , V_2 ;
V_2 = F_23 ( V_1 , & V_65 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_18 ( V_1 -> V_10 , V_75 ,
V_76 | V_77 | 160 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_44 ,
V_2 ) ;
goto V_66;
}
V_2 = F_15 ( V_1 , 5 , V_78 ,
V_79 , 0 ) ;
if ( V_2 ) {
F_18 ( V_1 -> V_10 , V_75 ,
V_80 ) ;
V_2 = - V_57 ;
}
V_66:
V_66 = F_24 ( V_1 , & V_65 ) ;
return V_2 ? : V_66 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_64 V_65 ;
int V_66 , V_2 ;
V_2 = F_23 ( V_1 , & V_65 ) ;
if ( V_2 )
return V_2 ;
V_2 = F_27 ( V_1 -> V_10 ,
V_81 ,
F_28 ( V_81 ) ) ;
V_66 = F_24 ( V_1 , & V_65 ) ;
return V_2 ? : V_66 ;
}
static int F_29 ( struct V_1 * V_1 )
{
int V_2 ;
V_2 = F_18 ( V_1 -> V_10 , V_82 ,
0x0 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_45 , V_2 ) ;
return V_2 ;
}
F_20 ( V_1 ) ;
F_30 ( V_1 -> V_83 ) ;
F_16 ( 20 ) ;
V_2 = F_31 ( V_1 -> V_83 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_46 , V_2 ) ;
return V_2 ;
}
F_22 ( V_1 ) ;
return 0 ;
}
static int F_32 ( struct V_84 * V_8 )
{
struct V_1 * V_1 = F_33 ( V_8 ) ;
int V_2 ;
F_34 ( V_1 -> V_8 , L_47 ) ;
if ( V_1 -> V_85 ) {
F_34 ( V_1 -> V_8 , L_48 ) ;
V_2 = F_35 ( V_1 -> V_86 ,
V_1 -> V_87 ) ;
if ( V_2 ) {
F_10 ( V_8 , L_49 ,
V_2 ) ;
return V_2 ;
}
}
V_2 = F_31 ( V_1 -> V_83 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_50 , V_2 ) ;
if ( V_1 -> V_85 )
F_36 ( V_1 -> V_86 ,
V_1 -> V_87 ) ;
return V_2 ;
}
if ( V_1 -> V_85 ) {
F_22 ( V_1 ) ;
F_37 ( V_1 -> V_13 ) ;
V_1 -> V_85 = false ;
}
F_38 ( V_1 -> V_10 , false ) ;
switch ( V_1 -> type ) {
case V_88 :
if ( V_1 -> V_89 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_90 ,
V_91 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_51 , V_2 ) ;
goto V_66;
}
}
V_2 = F_39 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_52 ,
V_2 ) ;
goto V_66;
}
V_2 = F_25 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_53 ,
V_2 ) ;
goto V_66;
}
break;
case V_62 :
case V_63 :
V_2 = F_17 ( V_1 ) ;
if ( V_2 )
goto V_66;
if ( V_1 -> V_89 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_90 ,
V_91 , 0 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_51 , V_2 ) ;
goto V_66;
}
} else {
V_2 = F_40 ( V_1 -> V_83 ,
1200000 , 1200000 ) ;
if ( V_2 < 0 ) {
F_10 ( V_1 -> V_8 ,
L_54 ,
V_2 ) ;
goto V_66;
}
}
V_2 = F_26 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_55 ,
V_2 ) ;
goto V_66;
}
break;
default:
V_2 = F_17 ( V_1 ) ;
if ( V_2 != 0 ) {
goto V_66;
}
if ( V_1 -> V_89 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_90 ,
V_91 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 ,
L_51 , V_2 ) ;
goto V_66;
}
}
break;
}
V_2 = F_41 ( V_1 -> V_10 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_56 ) ;
goto V_66;
}
return 0 ;
V_66:
F_38 ( V_1 -> V_10 , true ) ;
F_30 ( V_1 -> V_83 ) ;
return V_2 ;
}
static int F_42 ( struct V_84 * V_8 )
{
struct V_1 * V_1 = F_33 ( V_8 ) ;
unsigned int V_16 ;
int V_2 ;
F_34 ( V_1 -> V_8 , L_57 ) ;
V_2 = F_12 ( V_1 -> V_10 , V_92 , & V_16 ) ;
if ( V_2 ) {
F_10 ( V_8 , L_58 , V_2 ) ;
return V_2 ;
}
if ( V_1 -> V_89 ) {
V_2 = F_4 ( V_1 -> V_10 ,
V_90 ,
V_91 ,
V_91 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_59 ,
V_2 ) ;
return V_2 ;
}
}
switch ( V_1 -> type ) {
case V_62 :
case V_63 :
if ( V_1 -> V_89 )
break;
V_2 = F_40 ( V_1 -> V_83 , 1175000 , 1175000 ) ;
if ( V_2 < 0 ) {
F_10 ( V_1 -> V_8 ,
L_60 , V_2 ) ;
return V_2 ;
}
break;
case V_88 :
if ( ! ( V_16 & V_93 ) ) {
V_2 = F_18 ( V_1 -> V_10 ,
V_82 , 0x0 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_61 ,
V_2 ) ;
return V_2 ;
}
}
break;
default:
break;
}
F_38 ( V_1 -> V_10 , true ) ;
F_43 ( V_1 -> V_10 ) ;
F_30 ( V_1 -> V_83 ) ;
if ( ! ( V_16 & V_93 ) ) {
F_34 ( V_1 -> V_8 , L_62 ) ;
V_1 -> V_85 = true ;
F_44 ( V_1 -> V_13 ) ;
F_20 ( V_1 ) ;
F_36 ( V_1 -> V_86 ,
V_1 -> V_87 ) ;
}
return 0 ;
}
static int F_45 ( struct V_84 * V_8 )
{
struct V_1 * V_1 = F_33 ( V_8 ) ;
F_34 ( V_1 -> V_8 , L_63 ) ;
F_46 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_47 ( struct V_84 * V_8 )
{
struct V_1 * V_1 = F_33 ( V_8 ) ;
F_34 ( V_1 -> V_8 , L_64 ) ;
F_37 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_48 ( struct V_84 * V_8 )
{
struct V_1 * V_1 = F_33 ( V_8 ) ;
F_34 ( V_1 -> V_8 , L_65 ) ;
F_46 ( V_1 -> V_13 ) ;
return 0 ;
}
static int F_49 ( struct V_84 * V_8 )
{
struct V_1 * V_1 = F_33 ( V_8 ) ;
F_34 ( V_1 -> V_8 , L_66 ) ;
F_37 ( V_1 -> V_13 ) ;
return 0 ;
}
unsigned long F_50 ( struct V_84 * V_8 )
{
const struct V_94 * V_95 = F_51 ( V_96 , V_8 ) ;
if ( V_95 )
return ( unsigned long ) V_95 -> V_14 ;
else
return 0 ;
}
int F_52 ( struct V_1 * V_1 , const char * V_97 ,
bool V_98 )
{
int V_99 ;
V_99 = F_53 ( V_1 -> V_8 -> V_100 , V_97 , 0 ) ;
if ( V_99 < 0 ) {
if ( V_98 )
F_10 ( V_1 -> V_8 ,
L_67 ,
V_97 , V_99 ) ;
V_99 = 0 ;
}
return V_99 ;
}
static int F_54 ( struct V_1 * V_1 )
{
struct V_101 * V_5 = & V_1 -> V_5 ;
struct V_102 * V_97 ;
const T_2 * V_103 ;
T_3 V_16 ;
int V_2 , V_56 ;
int V_104 = 0 ;
V_5 -> V_61 = F_52 ( V_1 , L_68 , true ) ;
V_2 = F_55 ( V_1 -> V_8 -> V_100 ,
L_69 ,
V_1 -> V_5 . V_105 ,
F_28 ( V_1 -> V_5 . V_105 ) ) ;
if ( V_2 >= 0 ) {
for ( V_56 = 0 ; V_56 < F_28 ( V_1 -> V_5 . V_105 ) ; V_56 ++ ) {
if ( V_1 -> V_5 . V_105 [ V_56 ] > 0xffff )
V_1 -> V_5 . V_105 [ V_56 ] = 0 ;
else if ( V_1 -> V_5 . V_105 [ V_56 ] == 0 )
V_1 -> V_5 . V_105 [ V_56 ] = 0x10000 ;
}
} else {
F_10 ( V_1 -> V_8 , L_70 ,
V_2 ) ;
}
F_56 (arizona->dev->of_node, L_71 , prop,
cur, val) {
if ( V_104 == F_28 ( V_1 -> V_5 . V_106 ) )
break;
V_1 -> V_5 . V_106 [ V_104 ] = V_16 ;
V_104 ++ ;
}
V_104 = 0 ;
F_56 (arizona->dev->of_node, L_72 , prop,
cur, val) {
if ( V_104 == F_28 ( V_1 -> V_5 . V_107 ) )
break;
V_1 -> V_5 . V_107 [ V_104 ] = V_16 ;
V_104 ++ ;
}
return 0 ;
}
static inline int F_54 ( struct V_1 * V_1 )
{
return 0 ;
}
int F_57 ( struct V_1 * V_1 )
{
struct V_84 * V_8 = V_1 -> V_8 ;
const char * V_108 ;
unsigned int V_53 , V_16 ;
int (* F_58)( struct V_1 * ) = NULL ;
int V_2 , V_56 ;
F_59 ( V_1 -> V_8 , V_1 ) ;
F_60 ( & V_1 -> V_3 ) ;
if ( F_61 ( V_1 -> V_8 ) )
memcpy ( & V_1 -> V_5 , F_61 ( V_1 -> V_8 ) ,
sizeof( V_1 -> V_5 ) ) ;
else
F_54 ( V_1 ) ;
F_38 ( V_1 -> V_10 , true ) ;
switch ( V_1 -> type ) {
case V_88 :
case V_62 :
case V_63 :
case V_109 :
for ( V_56 = 0 ; V_56 < F_28 ( V_110 ) ; V_56 ++ )
V_1 -> V_87 [ V_56 ] . V_111
= V_110 [ V_56 ] ;
V_1 -> V_86 = F_28 ( V_110 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_73 ,
V_1 -> type ) ;
return - V_112 ;
}
V_1 -> V_89 = true ;
V_2 = F_62 ( V_1 -> V_8 , - 1 , V_113 ,
F_28 ( V_113 ) , NULL , 0 , NULL ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_74 , V_2 ) ;
return V_2 ;
}
V_2 = F_63 ( V_8 , V_1 -> V_86 ,
V_1 -> V_87 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_75 ,
V_2 ) ;
goto V_114;
}
V_1 -> V_83 = F_64 ( V_1 -> V_8 , L_76 ) ;
if ( F_65 ( V_1 -> V_83 ) ) {
V_2 = F_66 ( V_1 -> V_83 ) ;
F_10 ( V_8 , L_77 , V_2 ) ;
goto V_114;
}
if ( V_1 -> V_5 . V_61 ) {
V_2 = F_67 ( V_1 -> V_8 , V_1 -> V_5 . V_61 ,
V_115 | V_116 ,
L_78 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_79 , V_2 ) ;
goto V_117;
}
}
V_2 = F_35 ( V_1 -> V_86 ,
V_1 -> V_87 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_49 ,
V_2 ) ;
goto V_117;
}
V_2 = F_31 ( V_1 -> V_83 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_50 , V_2 ) ;
goto V_118;
}
F_22 ( V_1 ) ;
F_38 ( V_1 -> V_10 , false ) ;
V_2 = F_12 ( V_1 -> V_10 , V_119 , & V_53 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_80 , V_2 ) ;
goto V_120;
}
switch ( V_53 ) {
case 0x5102 :
case 0x5110 :
case 0x8997 :
break;
default:
F_10 ( V_1 -> V_8 , L_81 , V_53 ) ;
goto V_120;
}
if ( ! V_1 -> V_5 . V_61 ) {
V_2 = F_18 ( V_1 -> V_10 , V_119 , 0 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_82 , V_2 ) ;
goto V_120;
}
F_16 ( 1 ) ;
}
switch ( V_1 -> type ) {
case V_88 :
V_2 = F_12 ( V_1 -> V_10 ,
V_82 , & V_16 ) ;
if ( V_2 ) {
F_10 ( V_8 ,
L_83 ,
V_2 ) ;
} else if ( V_16 & 0x01 ) {
V_2 = F_29 ( V_1 ) ;
if ( V_2 )
return V_2 ;
}
break;
default:
break;
}
V_2 = F_17 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 , L_84 , V_2 ) ;
goto V_120;
}
V_2 = F_12 ( V_1 -> V_10 , V_119 , & V_53 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_80 , V_2 ) ;
goto V_120;
}
V_2 = F_12 ( V_1 -> V_10 , V_121 ,
& V_1 -> V_122 ) ;
if ( V_2 != 0 ) {
F_10 ( V_8 , L_85 , V_2 ) ;
goto V_120;
}
V_1 -> V_122 &= V_123 ;
switch ( V_53 ) {
#ifdef F_68
case 0x5102 :
V_108 = L_86 ;
if ( V_1 -> type != V_88 ) {
F_10 ( V_1 -> V_8 , L_87 ,
V_1 -> type ) ;
V_1 -> type = V_88 ;
}
F_58 = F_39 ;
V_1 -> V_122 &= 0x7 ;
break;
#endif
#ifdef F_69
case 0x5110 :
switch ( V_1 -> type ) {
case V_62 :
V_108 = L_88 ;
break;
case V_63 :
V_108 = L_89 ;
break;
default:
V_108 = L_88 ;
F_10 ( V_1 -> V_8 , L_90 ,
V_1 -> type ) ;
V_1 -> type = V_62 ;
break;
}
F_58 = V_124 ;
break;
#endif
#ifdef F_70
case 0x8997 :
V_108 = L_91 ;
if ( V_1 -> type != V_109 ) {
F_10 ( V_1 -> V_8 , L_92 ,
V_1 -> type ) ;
V_1 -> type = V_109 ;
}
F_58 = V_125 ;
break;
#endif
default:
F_10 ( V_1 -> V_8 , L_93 , V_53 ) ;
goto V_120;
}
F_71 ( V_8 , L_94 , V_108 , V_1 -> V_122 + 'A' ) ;
if ( F_58 ) {
V_2 = F_58 ( V_1 ) ;
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_52 ,
V_2 ) ;
goto V_120;
}
switch ( V_1 -> type ) {
case V_88 :
V_2 = F_25 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_53 ,
V_2 ) ;
goto V_120;
}
break;
case V_62 :
case V_63 :
V_2 = F_26 ( V_1 ) ;
if ( V_2 ) {
F_10 ( V_1 -> V_8 ,
L_95 ,
V_2 ) ;
goto V_120;
}
break;
default:
break;
}
}
for ( V_56 = 0 ; V_56 < F_28 ( V_1 -> V_5 . V_105 ) ; V_56 ++ ) {
if ( ! V_1 -> V_5 . V_105 [ V_56 ] )
continue;
F_18 ( V_1 -> V_10 , V_126 + V_56 ,
V_1 -> V_5 . V_105 [ V_56 ] ) ;
}
if ( ! V_1 -> V_5 . V_6 )
V_1 -> V_5 . V_6 = V_127 ;
switch ( V_1 -> V_5 . V_6 ) {
case V_7 :
case V_127 :
F_4 ( V_1 -> V_10 , V_11 ,
V_128 ,
V_1 -> V_5 . V_6 - 1 ) ;
F_1 ( V_1 ) ;
break;
case V_129 :
F_4 ( V_1 -> V_10 , V_11 ,
V_128 , 2 ) ;
break;
default:
F_10 ( V_1 -> V_8 , L_96 ,
V_1 -> V_5 . V_6 ) ;
V_2 = - V_112 ;
goto V_120;
}
for ( V_56 = 0 ; V_56 < V_130 ; V_56 ++ ) {
if ( ! V_1 -> V_5 . V_131 [ V_56 ] . V_132 &&
! V_1 -> V_5 . V_131 [ V_56 ] . V_133 )
continue;
if ( ! V_1 -> V_5 . V_131 [ V_56 ] . V_132 )
V_1 -> V_5 . V_131 [ V_56 ] . V_132 = 2800 ;
V_16 = ( V_1 -> V_5 . V_131 [ V_56 ] . V_132 - 1500 ) / 100 ;
V_16 <<= V_134 ;
if ( V_1 -> V_5 . V_131 [ V_56 ] . V_135 )
V_16 |= V_136 ;
if ( V_1 -> V_5 . V_131 [ V_56 ] . V_137 )
V_16 |= V_138 ;
if ( V_1 -> V_5 . V_131 [ V_56 ] . V_139 )
V_16 |= V_140 ;
if ( V_1 -> V_5 . V_131 [ V_56 ] . V_133 )
V_16 |= V_141 ;
F_4 ( V_1 -> V_10 ,
V_142 + V_56 ,
V_143 |
V_136 |
V_138 |
V_141 |
V_140 , V_16 ) ;
}
for ( V_56 = 0 ; V_56 < V_144 ; V_56 ++ ) {
V_16 = V_1 -> V_5 . V_107 [ V_56 ]
<< V_145 ;
if ( V_1 -> V_5 . V_106 [ V_56 ] & V_146 )
V_16 |= 1 << V_147 ;
if ( V_1 -> V_5 . V_106 [ V_56 ] & V_148 )
V_16 |= 1 << V_149 ;
F_4 ( V_1 -> V_10 ,
V_150 + ( V_56 * 8 ) ,
V_151 |
V_152 |
V_153 , V_16 ) ;
}
for ( V_56 = 0 ; V_56 < V_154 ; V_56 ++ ) {
if ( V_1 -> V_5 . V_155 [ V_56 ] )
V_16 = V_156 ;
else
V_16 = 0 ;
F_4 ( V_1 -> V_10 ,
V_157 + ( V_56 * 8 ) ,
V_156 , V_16 ) ;
}
for ( V_56 = 0 ; V_56 < V_158 ; V_56 ++ ) {
if ( V_1 -> V_5 . V_159 [ V_56 ] )
F_4 ( V_1 -> V_10 ,
V_160 + ( V_56 * 2 ) ,
V_161 |
V_162 ,
V_1 -> V_5 . V_159 [ V_56 ] ) ;
if ( V_1 -> V_5 . V_163 [ V_56 ] )
F_4 ( V_1 -> V_10 ,
V_164 + ( V_56 * 2 ) ,
V_165 ,
V_1 -> V_5 . V_163 [ V_56 ] ) ;
}
F_72 ( V_1 -> V_8 ) ;
F_73 ( V_1 -> V_8 ) ;
V_2 = F_74 ( V_1 ) ;
if ( V_2 != 0 )
goto V_120;
F_75 ( V_1 -> V_8 , 100 ) ;
F_76 ( V_1 -> V_8 ) ;
F_77 ( V_1 , V_166 , L_97 ,
F_9 , V_1 ) ;
F_77 ( V_1 , V_167 , L_98 ,
F_13 , V_1 ) ;
F_77 ( V_1 , V_168 , L_99 ,
F_11 , V_1 ) ;
switch ( V_1 -> type ) {
case V_88 :
V_2 = F_62 ( V_1 -> V_8 , - 1 , V_169 ,
F_28 ( V_169 ) , NULL , 0 , NULL ) ;
break;
case V_62 :
case V_63 :
V_2 = F_62 ( V_1 -> V_8 , - 1 , V_170 ,
F_28 ( V_170 ) , NULL , 0 , NULL ) ;
break;
case V_109 :
V_2 = F_62 ( V_1 -> V_8 , - 1 , V_171 ,
F_28 ( V_171 ) , NULL , 0 , NULL ) ;
break;
}
if ( V_2 != 0 ) {
F_10 ( V_1 -> V_8 , L_100 , V_2 ) ;
goto V_172;
}
return 0 ;
V_172:
F_78 ( V_1 ) ;
V_120:
F_20 ( V_1 ) ;
F_30 ( V_1 -> V_83 ) ;
V_118:
F_36 ( V_1 -> V_86 ,
V_1 -> V_87 ) ;
V_117:
F_79 ( V_1 -> V_83 ) ;
V_114:
F_80 ( V_8 ) ;
return V_2 ;
}
int F_81 ( struct V_1 * V_1 )
{
F_82 ( V_1 -> V_8 ) ;
F_30 ( V_1 -> V_83 ) ;
F_79 ( V_1 -> V_83 ) ;
F_80 ( V_1 -> V_8 ) ;
F_83 ( V_1 , V_168 , V_1 ) ;
F_83 ( V_1 , V_167 , V_1 ) ;
F_83 ( V_1 , V_166 , V_1 ) ;
F_78 ( V_1 ) ;
F_20 ( V_1 ) ;
F_36 ( V_1 -> V_86 ,
V_1 -> V_87 ) ;
return 0 ;
}
