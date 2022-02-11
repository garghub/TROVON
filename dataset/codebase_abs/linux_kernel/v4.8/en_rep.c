static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 ,
sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 , sizeof( V_4 -> V_7 ) ) ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_9 , T_2 * V_10 )
{
int V_11 ;
switch ( V_9 ) {
case V_12 :
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
strcpy ( V_10 + ( V_11 * V_14 ) ,
V_15 [ V_11 ] . V_16 ) ;
break;
}
}
static void F_4 ( struct V_17 * V_18 )
{
struct V_19 * V_20 = & V_18 -> V_21 . V_22 ;
struct V_23 * V_24 ;
struct V_25 * V_26 ;
int V_11 , V_27 ;
memset ( V_20 , 0 , sizeof( * V_20 ) ) ;
for ( V_11 = 0 ; V_11 < V_18 -> V_28 . V_29 ; V_11 ++ ) {
V_24 = & V_18 -> V_30 [ V_11 ] -> V_31 . V_21 ;
V_20 -> V_32 += V_24 -> V_33 ;
V_20 -> V_34 += V_24 -> V_35 ;
for ( V_27 = 0 ; V_27 < V_18 -> V_28 . V_36 ; V_27 ++ ) {
V_26 = & V_18 -> V_30 [ V_11 ] -> V_37 [ V_27 ] . V_21 ;
V_20 -> V_38 += V_26 -> V_33 ;
V_20 -> V_39 += V_26 -> V_35 ;
}
}
}
static void F_5 ( struct V_1 * V_2 ,
struct V_40 * V_21 , T_3 * V_10 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
int V_11 ;
if ( ! V_10 )
return;
F_7 ( & V_18 -> V_41 ) ;
if ( F_8 ( V_42 , & V_18 -> V_43 ) )
F_4 ( V_18 ) ;
F_9 ( & V_18 -> V_41 ) ;
for ( V_11 = 0 ; V_11 < V_13 ; V_11 ++ )
V_10 [ V_11 ] = F_10 ( & V_18 -> V_21 . V_22 ,
V_15 , V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 , int V_44 )
{
switch ( V_44 ) {
case V_12 :
return V_13 ;
default:
return - V_45 ;
}
}
int F_12 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_48 * V_49 = V_18 -> V_50 ;
struct V_51 * V_52 = V_18 -> V_53 -> V_18 . V_54 ;
if ( V_52 -> V_55 == V_56 )
return - V_45 ;
switch ( V_47 -> V_57 ) {
case V_58 :
V_47 -> V_59 . V_60 . V_61 = V_62 ;
F_13 ( V_47 -> V_59 . V_60 . V_57 , V_49 -> V_63 ) ;
break;
default:
return - V_45 ;
}
return 0 ;
}
int F_14 ( struct V_17 * V_18 )
{
struct V_51 * V_52 = V_18 -> V_53 -> V_18 . V_54 ;
struct V_48 * V_49 = V_18 -> V_50 ;
struct V_64 * V_65 ;
int V_66 , V_67 , V_68 , V_69 = 0 ;
T_4 * V_70 ;
V_70 = F_15 ( V_18 -> V_28 . V_29 * V_18 -> V_28 . V_36 , sizeof( T_4 ) , V_71 ) ;
if ( ! V_70 )
return - V_72 ;
for ( V_66 = 0 ; V_66 < V_18 -> V_28 . V_29 ; V_66 ++ ) {
V_65 = V_18 -> V_30 [ V_66 ] ;
for ( V_67 = 0 ; V_67 < V_65 -> V_36 ; V_67 ++ )
V_70 [ V_69 ++ ] = V_65 -> V_37 [ V_67 ] . V_73 ;
}
V_68 = F_16 ( V_52 , V_49 , V_70 , V_69 ) ;
F_17 ( V_70 ) ;
return V_68 ;
}
int F_18 ( struct V_51 * V_52 , struct V_48 * V_49 )
{
struct V_17 * V_18 = V_49 -> V_74 ;
if ( F_8 ( V_42 , & V_18 -> V_43 ) )
return F_14 ( V_18 ) ;
return 0 ;
}
void F_19 ( struct V_17 * V_18 )
{
struct V_51 * V_52 = V_18 -> V_53 -> V_18 . V_54 ;
struct V_48 * V_49 = V_18 -> V_50 ;
F_20 ( V_52 , V_49 ) ;
}
void F_21 ( struct V_51 * V_52 ,
struct V_48 * V_49 )
{
struct V_17 * V_18 = V_49 -> V_74 ;
if ( F_8 ( V_42 , & V_18 -> V_43 ) )
F_19 ( V_18 ) ;
F_22 ( V_18 ) ;
F_23 ( V_18 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
char * V_75 , T_5 V_76 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
struct V_48 * V_49 = V_18 -> V_50 ;
int V_77 ;
V_77 = snprintf ( V_75 , V_76 , L_1 , V_49 -> V_78 - 1 ) ;
if ( V_77 >= V_76 )
return - V_45 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , T_1 V_79 ,
T_6 V_80 , struct V_81 * V_67 )
{
struct V_17 * V_18 = F_6 ( V_2 ) ;
if ( F_26 ( V_79 ) != F_26 ( V_82 ) )
return - V_45 ;
switch ( V_67 -> type ) {
case V_83 :
switch ( V_67 -> V_84 -> V_85 ) {
case V_86 :
return F_27 ( V_18 , V_80 , V_67 -> V_84 ) ;
case V_87 :
return F_28 ( V_18 , V_67 -> V_84 ) ;
case V_88 :
return F_29 ( V_18 , V_67 -> V_84 ) ;
}
default:
return - V_45 ;
}
}
static void F_30 ( struct V_89 * V_53 ,
struct V_1 * V_90 ,
const struct V_91 * V_92 ,
void * V_50 )
{
struct V_17 * V_18 = F_6 ( V_90 ) ;
T_7 V_93 = F_31 ( V_53 , V_94 ) ?
V_95 :
V_96 ;
V_18 -> V_28 . V_97 =
V_98 ;
V_18 -> V_28 . V_99 = V_100 ;
V_18 -> V_28 . V_101 = V_102 ;
V_18 -> V_28 . V_103 = F_32 ( V_18 -> V_28 . V_99 ,
F_33 ( V_18 -> V_28 . V_101 ) ) ;
V_18 -> V_28 . V_104 = F_31 ( V_53 , V_105 ) ;
F_34 ( & V_18 -> V_28 , V_93 ) ;
V_18 -> V_28 . V_106 = F_35 ( V_53 ) ;
V_18 -> V_28 . V_36 = 1 ;
V_18 -> V_28 . V_107 =
V_108 ;
V_18 -> V_53 = V_53 ;
V_18 -> V_90 = V_90 ;
V_18 -> V_28 . V_29 = V_92 -> V_109 ( V_53 ) ;
V_18 -> V_92 = V_92 ;
V_18 -> V_50 = V_50 ;
F_36 ( & V_18 -> V_41 ) ;
F_37 ( & V_18 -> V_110 , V_111 ) ;
}
static void F_38 ( struct V_1 * V_90 )
{
V_90 -> V_112 = & V_113 ;
V_90 -> V_114 = 15 * V_115 ;
V_90 -> V_116 = & V_117 ;
#ifdef F_39
V_90 -> V_118 = & V_119 ;
#endif
V_90 -> V_120 |= V_121 | V_122 ;
V_90 -> V_123 |= V_122 ;
F_40 ( V_90 ) ;
}
static void F_41 ( struct V_89 * V_53 ,
struct V_1 * V_90 ,
const struct V_91 * V_92 ,
void * V_50 )
{
F_30 ( V_53 , V_90 , V_92 , V_50 ) ;
F_38 ( V_90 ) ;
}
static int F_42 ( struct V_17 * V_18 )
{
struct V_51 * V_52 = V_18 -> V_53 -> V_18 . V_54 ;
struct V_48 * V_49 = V_18 -> V_50 ;
struct V_89 * V_53 = V_18 -> V_53 ;
struct V_124 * V_125 ;
int V_68 ;
int V_11 ;
V_68 = F_43 ( V_18 ) ;
if ( V_68 ) {
F_44 ( V_53 , L_2 , V_68 ) ;
return V_68 ;
}
V_68 = F_45 ( V_18 ) ;
if ( V_68 ) {
F_44 ( V_53 , L_3 , V_68 ) ;
goto V_126;
}
V_125 = F_46 ( V_52 ,
V_49 -> V_78 ,
V_18 -> V_127 [ 0 ] . V_128 ) ;
if ( F_47 ( V_125 ) ) {
V_68 = F_48 ( V_125 ) ;
goto V_129;
}
V_49 -> V_130 = V_125 ;
V_68 = F_23 ( V_18 ) ;
if ( V_68 )
goto V_131;
return 0 ;
V_131:
F_49 ( V_49 -> V_130 ) ;
V_129:
F_50 ( V_18 ) ;
V_126:
for ( V_11 = 0 ; V_11 < V_18 -> V_28 . V_29 ; V_11 ++ )
F_51 ( V_18 , & V_18 -> V_127 [ V_11 ] . V_132 ) ;
return V_68 ;
}
static void F_52 ( struct V_17 * V_18 )
{
struct V_48 * V_49 = V_18 -> V_50 ;
int V_11 ;
F_22 ( V_18 ) ;
F_49 ( V_49 -> V_130 ) ;
F_50 ( V_18 ) ;
for ( V_11 = 0 ; V_11 < V_18 -> V_28 . V_29 ; V_11 ++ )
F_51 ( V_18 , & V_18 -> V_127 [ V_11 ] . V_132 ) ;
}
static int F_53 ( struct V_17 * V_18 )
{
int V_68 ;
V_68 = F_54 ( V_18 ) ;
if ( V_68 ) {
F_44 ( V_18 -> V_53 , L_4 , V_68 ) ;
return V_68 ;
}
return 0 ;
}
static int F_55 ( struct V_89 * V_53 )
{
#define F_56 1
return F_56 ;
}
int F_57 ( struct V_51 * V_52 ,
struct V_48 * V_49 )
{
V_49 -> V_74 = F_58 ( V_52 -> V_2 , & V_133 , V_49 ) ;
if ( ! V_49 -> V_74 ) {
F_59 ( L_5 ,
V_49 -> V_78 ) ;
return - V_134 ;
}
return 0 ;
}
void F_60 ( struct V_51 * V_52 ,
struct V_48 * V_49 )
{
struct V_17 * V_18 = V_49 -> V_74 ;
F_61 ( V_52 -> V_2 , V_18 ) ;
}
