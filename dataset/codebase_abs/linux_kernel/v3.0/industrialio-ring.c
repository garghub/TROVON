static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5
= F_2 ( V_1 -> V_6 , struct V_4 , V_7 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
V_3 -> V_11 = V_5 -> V_10 ;
if ( V_9 -> V_12 -> V_13 )
V_9 -> V_12 -> V_13 ( V_9 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_14 * V_15 = V_1 -> V_6 ;
struct V_4 * V_5 = F_4 ( V_15 ) ;
struct V_8 * V_9 = V_5 -> V_10 ;
F_5 ( V_16 , & V_9 -> V_17 . V_18 ) ;
if ( V_9 -> V_12 -> V_19 )
V_9 -> V_12 -> V_19 ( V_9 ) ;
return 0 ;
}
static T_1 F_6 ( struct V_2 * V_3 , char T_2 * V_20 ,
T_3 V_21 , T_4 * V_22 )
{
struct V_8 * V_9 = V_3 -> V_11 ;
if ( ! V_9 -> V_12 -> V_23 )
return - V_24 ;
return V_9 -> V_12 -> V_23 ( V_9 , V_21 , V_20 ) ;
}
static unsigned int F_7 ( struct V_2 * V_3 ,
struct V_25 * V_26 )
{
struct V_8 * V_9 = V_3 -> V_11 ;
F_8 ( V_3 , & V_9 -> V_27 , V_26 ) ;
if ( V_9 -> V_28 )
return V_29 | V_30 ;
return 0 ;
}
void F_9 ( struct V_31 * V_32 )
{
struct V_8 * V_20
= F_2 ( V_32 , struct V_8 , V_32 ) ;
F_10 ( & V_20 -> V_17 . V_7 ) ;
F_11 ( F_12 ( V_32 -> V_33 ) ) ;
}
static inline int
F_13 ( struct V_8 * V_20 ,
struct V_34 * V_35 ,
int V_36 )
{
int V_37 ;
V_20 -> V_17 . V_18 = 0 ;
V_20 -> V_32 . V_38 = & V_39 ;
F_14 ( & V_20 -> V_32 ) ;
V_37 = F_15 () ;
if ( V_37 < 0 )
goto V_40;
V_20 -> V_32 . V_33 = F_16 ( F_17 ( V_41 ) , V_37 ) ;
F_18 ( & V_20 -> V_32 , L_1 ,
F_19 ( V_20 -> V_32 . V_42 ) ,
V_36 ) ;
V_37 = F_20 ( & V_20 -> V_32 ) ;
if ( V_37 < 0 ) {
F_21 ( V_43 L_2 ) ;
goto V_40;
}
F_22 ( & V_20 -> V_17 . V_7 , & V_44 ) ;
V_20 -> V_17 . V_7 . V_35 = V_35 ;
V_37 = F_23 ( & V_20 -> V_17 . V_7 , V_20 -> V_32 . V_33 , 1 ) ;
if ( V_37 ) {
F_21 ( V_43 L_3 ) ;
goto V_45;
}
return 0 ;
V_45:
F_24 ( & V_20 -> V_32 ) ;
V_40:
F_25 ( & V_20 -> V_32 ) ;
return V_37 ;
}
static void F_26 ( struct V_8 * V_20 )
{
F_24 ( & V_20 -> V_32 ) ;
}
void F_27 ( struct V_8 * V_46 ,
struct V_47 * V_48 )
{
V_46 -> V_49 = V_48 ;
V_46 -> V_17 . V_10 = V_46 ;
F_28 ( & V_46 -> V_27 ) ;
}
static T_1 F_29 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
return sprintf ( V_20 , L_4 , F_30 ( V_51 ) -> V_52 -> V_53 ) ;
}
static T_1 F_31 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
struct V_54 * V_55 = F_30 ( V_51 ) ;
return sprintf ( V_20 , L_5 ,
V_55 -> V_52 -> V_56 . V_57 ,
V_55 -> V_52 -> V_56 . V_58 ,
V_55 -> V_52 -> V_56 . V_59 ,
V_55 -> V_52 -> V_56 . V_60 ) ;
}
static T_1 F_32 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
int V_37 ;
struct V_8 * V_46 = F_33 ( V_32 ) ;
V_37 = F_34 ( V_46 , F_30 ( V_51 ) -> V_61 ) ;
if ( V_37 < 0 )
return V_37 ;
return sprintf ( V_20 , L_6 , V_37 ) ;
}
static int F_35 ( struct V_8 * V_46 , int V_62 )
{
if ( V_62 > V_63 )
return - V_24 ;
V_46 -> V_64 &= ~ ( 1 << V_62 ) ;
V_46 -> V_65 -- ;
return 0 ;
}
static T_1 F_36 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
const char * V_20 ,
T_3 V_66 )
{
int V_37 = 0 ;
bool V_67 ;
struct V_8 * V_46 = F_33 ( V_32 ) ;
struct V_47 * V_49 = V_46 -> V_49 ;
struct V_54 * V_55 = F_30 ( V_51 ) ;
V_67 = ! ( V_20 [ 0 ] == '0' ) ;
F_37 ( & V_49 -> V_68 ) ;
if ( V_49 -> V_69 == V_70 ) {
V_37 = - V_71 ;
goto V_72;
}
V_37 = F_34 ( V_46 , V_55 -> V_61 ) ;
if ( V_37 < 0 )
goto V_72;
if ( ! V_67 && V_37 ) {
V_37 = F_35 ( V_46 , V_55 -> V_61 ) ;
if ( V_37 )
goto V_72;
} else if ( V_67 && ! V_37 ) {
V_37 = F_38 ( V_46 , V_55 -> V_61 ) ;
if ( V_37 )
goto V_72;
}
V_72:
F_39 ( & V_49 -> V_68 ) ;
return V_37 ? V_37 : V_66 ;
}
static T_1 F_40 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
struct V_8 * V_46 = F_33 ( V_32 ) ;
return sprintf ( V_20 , L_6 , V_46 -> V_73 ) ;
}
static T_1 F_41 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
const char * V_20 ,
T_3 V_66 )
{
int V_37 = 0 ;
struct V_8 * V_46 = F_33 ( V_32 ) ;
struct V_47 * V_49 = V_46 -> V_49 ;
bool V_67 ;
V_67 = ! ( V_20 [ 0 ] == '0' ) ;
F_37 ( & V_49 -> V_68 ) ;
if ( V_49 -> V_69 == V_70 ) {
V_37 = - V_71 ;
goto V_72;
}
V_46 -> V_73 = V_67 ;
V_72:
F_39 ( & V_49 -> V_68 ) ;
return V_37 ? V_37 : V_66 ;
}
static int F_42 ( struct V_8 * V_46 ,
const struct V_74 * V_75 )
{
int V_37 ;
V_37 = F_43 ( L_7 , L_8 ,
V_75 ,
& F_29 ,
NULL ,
0 ,
0 ,
& V_46 -> V_32 ,
& V_46 -> V_76 ) ;
if ( V_37 )
goto V_72;
V_37 = F_43 ( L_9 , L_8 ,
V_75 ,
& F_31 ,
NULL ,
0 ,
0 ,
& V_46 -> V_32 ,
& V_46 -> V_76 ) ;
if ( V_37 )
goto V_72;
if ( V_75 -> type != V_77 )
V_37 = F_43 ( L_10 , L_8 ,
V_75 ,
& F_32 ,
& F_36 ,
V_75 -> V_53 ,
0 ,
& V_46 -> V_32 ,
& V_46 -> V_76 ) ;
else
V_37 = F_43 ( L_10 , L_8 ,
V_75 ,
& F_40 ,
& F_41 ,
V_75 -> V_53 ,
0 ,
& V_46 -> V_32 ,
& V_46 -> V_76 ) ;
V_72:
return V_37 ;
}
static void F_44 ( struct V_8 * V_46 ,
struct V_54 * V_78 )
{
F_45 ( & V_46 -> V_32 . V_79 ,
& V_78 -> V_80 . V_51 , L_8 ) ;
F_46 ( V_78 -> V_80 . V_51 . V_81 ) ;
F_46 ( V_78 ) ;
}
static void F_47 ( struct V_8 * V_46 )
{
struct V_54 * V_78 , * V_21 ;
int V_82 = ! F_48 ( & V_46 -> V_76 ) ;
F_49 (p, n,
&ring->scan_el_dev_attr_list, l)
F_44 ( V_46 , V_78 ) ;
if ( V_46 -> V_83 )
F_50 ( & V_46 -> V_32 . V_79 ,
V_46 -> V_83 ) ;
else if ( V_82 )
F_50 ( & V_46 -> V_32 . V_79 ,
& V_84 ) ;
}
int F_51 ( struct V_8 * V_46 , int V_36 ,
const struct V_74 * V_85 ,
int V_86 )
{
int V_37 , V_87 ;
V_37 = F_13 ( V_46 , V_46 -> V_35 , V_36 ) ;
if ( V_37 )
goto V_72;
if ( V_46 -> V_83 ) {
V_37 = F_52 ( & V_46 -> V_32 . V_79 ,
V_46 -> V_83 ) ;
if ( V_37 ) {
F_53 ( & V_46 -> V_32 ,
L_11 ) ;
goto V_88;
}
} else if ( V_85 ) {
V_37 = F_52 ( & V_46 -> V_32 . V_79 ,
& V_84 ) ;
if ( V_37 )
goto V_88;
}
F_54 ( & V_46 -> V_76 ) ;
if ( V_85 ) {
for ( V_87 = 0 ; V_87 < V_86 ; V_87 ++ ) {
V_37 = F_42 ( V_46 , & V_85 [ V_87 ] ) ;
if ( V_37 < 0 )
goto V_89;
}
}
return 0 ;
V_89:
F_47 ( V_46 ) ;
V_88:
F_26 ( V_46 ) ;
V_72:
return V_37 ;
}
void F_55 ( struct V_8 * V_46 )
{
F_47 ( V_46 ) ;
F_26 ( V_46 ) ;
}
T_1 F_56 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
struct V_8 * V_46 = F_33 ( V_32 ) ;
if ( V_46 -> V_12 -> V_90 )
return sprintf ( V_20 , L_6 ,
V_46 -> V_12 -> V_90 ( V_46 ) ) ;
return 0 ;
}
T_1 F_57 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
const char * V_20 ,
T_3 V_66 )
{
int V_37 ;
T_5 V_91 ;
struct V_8 * V_46 = F_33 ( V_32 ) ;
V_37 = F_58 ( V_20 , 10 , & V_91 ) ;
if ( V_37 )
return V_37 ;
if ( V_46 -> V_12 -> V_90 )
if ( V_91 == V_46 -> V_12 -> V_90 ( V_46 ) )
return V_66 ;
if ( V_46 -> V_12 -> V_92 ) {
V_46 -> V_12 -> V_92 ( V_46 , V_91 ) ;
if ( V_46 -> V_12 -> V_93 )
V_46 -> V_12 -> V_93 ( V_46 ) ;
}
return V_66 ;
}
T_1 F_59 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
struct V_8 * V_46 = F_33 ( V_32 ) ;
if ( V_46 -> V_12 -> V_94 )
return sprintf ( V_20 , L_6 ,
V_46 -> V_12 -> V_94 ( V_46 ) ) ;
return 0 ;
}
T_1 F_60 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
const char * V_20 ,
T_3 V_66 )
{
int V_37 ;
bool V_95 , V_96 ;
int V_97 ;
struct V_8 * V_46 = F_33 ( V_32 ) ;
struct V_47 * V_48 = V_46 -> V_49 ;
F_37 ( & V_48 -> V_68 ) ;
V_97 = V_48 -> V_69 ;
V_95 = ! ( V_20 [ 0 ] == '0' ) ;
V_96 = ! ! ( V_97 & V_98 ) ;
if ( V_96 == V_95 ) {
F_21 ( V_99 L_12 ) ;
goto V_100;
}
if ( V_95 ) {
if ( V_46 -> V_101 -> V_102 ) {
V_37 = V_46 -> V_101 -> V_102 ( V_48 ) ;
if ( V_37 ) {
F_21 ( V_43
L_13
L_14 ) ;
goto V_72;
}
}
if ( V_46 -> V_12 -> V_103 ) {
V_37 = V_46 -> V_12 -> V_103 ( V_46 ) ;
if ( V_37 ) {
F_21 ( V_99
L_13
L_15 ) ;
goto V_72;
}
}
if ( V_46 -> V_12 -> V_13 )
V_46 -> V_12 -> V_13 ( V_46 ) ;
if ( V_48 -> V_104 & V_70 ) {
if ( ! V_48 -> V_105 ) {
F_21 ( V_99
L_16 ) ;
V_37 = - V_24 ;
if ( V_46 -> V_12 -> V_19 )
V_46 -> V_12 -> V_19 ( V_46 ) ;
goto V_72;
}
V_48 -> V_69 = V_70 ;
} else if ( V_48 -> V_104 & V_106 )
V_48 -> V_69 = V_106 ;
else {
V_37 = - V_24 ;
goto V_72;
}
if ( V_46 -> V_101 -> V_107 ) {
V_37 = V_46 -> V_101 -> V_107 ( V_48 ) ;
if ( V_37 ) {
F_21 ( V_99
L_13
L_17 ) ;
if ( V_46 -> V_12 -> V_19 )
V_46 -> V_12 -> V_19 ( V_46 ) ;
V_48 -> V_69 = V_97 ;
if ( V_46 -> V_101 -> V_108 )
V_46 -> V_101 -> V_108 ( V_48 ) ;
goto V_72;
}
}
} else {
if ( V_46 -> V_101 -> V_109 ) {
V_37 = V_46 -> V_101 -> V_109 ( V_48 ) ;
if ( V_37 )
goto V_72;
}
if ( V_46 -> V_12 -> V_19 )
V_46 -> V_12 -> V_19 ( V_46 ) ;
V_48 -> V_69 = V_110 ;
if ( V_46 -> V_101 -> V_108 ) {
V_37 = V_46 -> V_101 -> V_108 ( V_48 ) ;
if ( V_37 )
goto V_72;
}
}
V_100:
F_39 ( & V_48 -> V_68 ) ;
return V_66 ;
V_72:
F_39 ( & V_48 -> V_68 ) ;
return V_37 ;
}
T_1 F_61 ( struct V_31 * V_32 ,
struct V_50 * V_51 ,
char * V_20 )
{
struct V_8 * V_46 = F_33 ( V_32 ) ;
return sprintf ( V_20 , L_6 , ! ! ( V_46 -> V_49 -> V_69
& V_98 ) ) ;
}
int F_62 ( struct V_47 * V_49 )
{
struct V_8 * V_46 = V_49 -> V_46 ;
T_3 V_111 ;
F_63 ( & V_49 -> V_32 , L_18 , V_112 ) ;
if ( ! ( V_46 -> V_65 || V_46 -> V_73 ) )
return - V_24 ;
if ( V_46 -> V_73 )
if ( V_46 -> V_65 )
V_111 = ( ( ( V_46 -> V_65 * V_46 -> V_113 )
+ sizeof( V_114 ) - 1 )
& ~ ( sizeof( V_114 ) - 1 ) )
+ sizeof( V_114 ) ;
else
V_111 = sizeof( V_114 ) ;
else
V_111 = V_46 -> V_65 * V_46 -> V_113 ;
V_46 -> V_12 -> V_115 ( V_46 , V_111 ) ;
return 0 ;
}
