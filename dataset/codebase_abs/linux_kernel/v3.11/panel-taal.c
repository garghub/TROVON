static void F_1 ( struct V_1 * V_2 , int V_3 )
{
V_2 -> V_4 = F_2 ( V_3 ) ;
V_2 -> V_5 = V_6 + V_2 -> V_4 ;
}
static void V_4 ( struct V_1 * V_2 )
{
unsigned long V_7 = V_2 -> V_5 - V_6 ;
if ( ( long ) V_7 > 0 && V_7 <= V_2 -> V_4 ) {
F_3 ( V_8 ) ;
F_4 ( V_7 ) ;
}
}
static int F_5 ( struct V_1 * V_2 , T_1 V_9 , T_1 * V_10 )
{
int V_11 ;
T_1 V_12 [ 1 ] ;
V_11 = F_6 ( V_2 -> V_13 , V_2 -> V_14 , V_9 , V_12 , 1 ) ;
if ( V_11 < 0 )
return V_11 ;
* V_10 = V_12 [ 0 ] ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 V_9 )
{
return F_8 ( V_2 -> V_13 , V_2 -> V_14 , & V_9 , 1 ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_9 , T_1 V_15 )
{
T_1 V_12 [ 2 ] ;
V_12 [ 0 ] = V_9 ;
V_12 [ 1 ] = V_15 ;
return F_8 ( V_2 -> V_13 , V_2 -> V_14 , V_12 , 2 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_16 ;
int V_11 ;
V_4 ( V_2 ) ;
V_16 = V_17 ;
V_11 = F_11 ( V_2 -> V_13 , V_2 -> V_14 , & V_16 , 1 ) ;
if ( V_11 )
return V_11 ;
F_1 ( V_2 , 120 ) ;
F_12 ( 5 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
int V_11 ;
V_4 ( V_2 ) ;
V_11 = F_7 ( V_2 , V_18 ) ;
if ( V_11 )
return V_11 ;
F_1 ( V_2 , 120 ) ;
F_12 ( 5 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_19 , T_1 * V_20 , T_1 * V_21 )
{
int V_11 ;
V_11 = F_5 ( V_2 , V_22 , V_19 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_2 , V_23 , V_20 ) ;
if ( V_11 )
return V_11 ;
V_11 = F_5 ( V_2 , V_24 , V_21 ) ;
if ( V_11 )
return V_11 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_2 V_25 , T_2 V_26 , T_2 V_27 , T_2 V_28 )
{
int V_11 ;
T_2 V_29 = V_25 ;
T_2 V_30 = V_25 + V_27 - 1 ;
T_2 y1 = V_26 ;
T_2 V_31 = V_26 + V_28 - 1 ;
T_1 V_12 [ 5 ] ;
V_12 [ 0 ] = V_32 ;
V_12 [ 1 ] = ( V_29 >> 8 ) & 0xff ;
V_12 [ 2 ] = ( V_29 >> 0 ) & 0xff ;
V_12 [ 3 ] = ( V_30 >> 8 ) & 0xff ;
V_12 [ 4 ] = ( V_30 >> 0 ) & 0xff ;
V_11 = F_11 ( V_2 -> V_13 , V_2 -> V_14 , V_12 , sizeof( V_12 ) ) ;
if ( V_11 )
return V_11 ;
V_12 [ 0 ] = V_33 ;
V_12 [ 1 ] = ( y1 >> 8 ) & 0xff ;
V_12 [ 2 ] = ( y1 >> 0 ) & 0xff ;
V_12 [ 3 ] = ( V_31 >> 8 ) & 0xff ;
V_12 [ 4 ] = ( V_31 >> 0 ) & 0xff ;
V_11 = F_11 ( V_2 -> V_13 , V_2 -> V_14 , V_12 , sizeof( V_12 ) ) ;
if ( V_11 )
return V_11 ;
F_16 ( V_2 -> V_13 , V_2 -> V_14 ) ;
return V_11 ;
}
static void F_17 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
if ( V_2 -> V_36 > 0 )
F_19 ( V_2 -> V_37 , & V_2 -> V_38 ,
F_2 ( V_2 -> V_36 ) ) ;
}
static void F_20 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
F_21 ( & V_2 -> V_38 ) ;
}
static void F_22 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
if ( V_2 -> V_39 > 0 )
F_19 ( V_2 -> V_37 , & V_2 -> V_40 ,
F_2 ( V_2 -> V_39 ) ) ;
}
static void F_23 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
F_21 ( & V_2 -> V_40 ) ;
}
static int F_24 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
if ( V_2 -> V_41 )
return 0 ;
F_23 ( V_13 ) ;
V_11 = F_25 ( V_13 , false ) ;
if ( V_11 )
goto V_42;
if ( F_26 ( V_2 -> V_43 ) )
F_27 ( F_28 ( V_2 -> V_43 ) ) ;
F_29 ( V_13 , false , true ) ;
V_2 -> V_41 = true ;
return 0 ;
V_42:
F_30 ( V_13 -> V_35 , L_1 ) ;
F_31 ( V_13 ) ;
V_2 -> V_41 = false ;
F_22 ( V_13 ) ;
return V_11 ;
}
static int F_32 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
if ( ! V_2 -> V_41 )
return 0 ;
V_11 = F_33 ( V_13 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_2 ) ;
goto V_44;
}
F_34 ( V_13 , V_2 -> V_14 , true ) ;
V_11 = F_25 ( V_13 , true ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_3 ) ;
goto V_45;
}
if ( F_26 ( V_2 -> V_43 ) )
F_35 ( F_28 ( V_2 -> V_43 ) ) ;
F_22 ( V_13 ) ;
V_2 -> V_41 = false ;
return 0 ;
V_45:
F_30 ( V_13 -> V_35 , L_4 ) ;
V_11 = F_31 ( V_13 ) ;
if ( ! V_11 ) {
if ( F_26 ( V_2 -> V_43 ) )
F_35 ( F_28 ( V_2 -> V_43 ) ) ;
V_2 -> V_41 = false ;
}
V_44:
F_22 ( V_13 ) ;
return V_11 ;
}
static int F_36 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
if ( V_2 -> V_41 )
return F_32 ( V_13 ) ;
F_23 ( V_13 ) ;
F_22 ( V_13 ) ;
return 0 ;
}
static int F_37 ( struct V_46 * V_35 )
{
struct V_34 * V_13 = F_18 ( & V_35 -> V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
int V_47 ;
if ( V_35 -> V_48 . V_49 == V_50 &&
V_35 -> V_48 . V_51 == V_50 )
V_47 = V_35 -> V_48 . V_52 ;
else
V_47 = 0 ;
F_38 ( V_13 -> V_35 , L_5 , V_47 ) ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ) {
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( ! V_11 )
V_11 = F_9 ( V_2 , V_55 , V_47 ) ;
F_41 ( V_13 ) ;
} else {
V_11 = 0 ;
}
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static int F_43 ( struct V_46 * V_35 )
{
if ( V_35 -> V_48 . V_49 == V_50 &&
V_35 -> V_48 . V_51 == V_50 )
return V_35 -> V_48 . V_52 ;
return 0 ;
}
static void F_44 ( struct V_34 * V_13 ,
T_2 * V_56 , T_2 * V_57 )
{
* V_56 = V_13 -> V_58 . V_59 . V_60 ;
* V_57 = V_13 -> V_58 . V_59 . V_61 ;
}
static T_3 F_45 ( struct V_62 * V_35 ,
struct V_63 * V_64 , char * V_12 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
T_1 V_65 = 0 ;
int V_11 ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ) {
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( ! V_11 )
V_11 = F_5 ( V_2 , V_66 , & V_65 ) ;
F_41 ( V_13 ) ;
} else {
V_11 = - V_67 ;
}
F_42 ( & V_2 -> V_53 ) ;
if ( V_11 )
return V_11 ;
return snprintf ( V_12 , V_68 , L_6 , V_65 ) ;
}
static T_3 F_47 ( struct V_62 * V_35 ,
struct V_63 * V_64 , char * V_12 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
T_1 V_19 , V_20 , V_21 ;
int V_11 ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ) {
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( ! V_11 )
V_11 = F_14 ( V_2 , & V_19 , & V_20 , & V_21 ) ;
F_41 ( V_13 ) ;
} else {
V_11 = - V_67 ;
}
F_42 ( & V_2 -> V_53 ) ;
if ( V_11 )
return V_11 ;
return snprintf ( V_12 , V_68 , L_7 , V_19 , V_20 , V_21 ) ;
}
static T_3 F_48 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
char * V_12 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
const char * V_69 ;
int V_70 ;
int V_71 ;
V_70 = V_2 -> V_72 ;
V_69 = L_8 ;
if ( V_70 >= 0 && V_70 < F_49 ( V_73 ) )
V_69 = V_73 [ V_70 ] ;
V_71 = snprintf ( V_12 , V_68 , L_9 , V_69 ) ;
return V_71 < V_68 - 1 ? V_71 : V_68 - 1 ;
}
static T_3 F_50 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
const char * V_12 , T_4 V_74 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_75 ;
int V_11 ;
for ( V_75 = 0 ; V_75 < F_49 ( V_73 ) ; V_75 ++ ) {
if ( F_51 ( V_73 [ V_75 ] , V_12 ) )
break;
}
if ( V_75 == F_49 ( V_73 ) )
return - V_76 ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ) {
F_40 ( V_13 ) ;
if ( ! V_2 -> V_77 ) {
V_11 = F_36 ( V_13 ) ;
if ( V_11 )
goto V_42;
V_11 = F_9 ( V_2 , V_78 , V_75 ) ;
if ( V_11 )
goto V_42;
}
F_41 ( V_13 ) ;
}
V_2 -> V_72 = V_75 ;
F_42 ( & V_2 -> V_53 ) ;
return V_74 ;
V_42:
F_41 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static T_3 F_52 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
char * V_12 )
{
int V_71 ;
int V_75 ;
for ( V_75 = 0 , V_71 = 0 ;
V_71 < V_68 && V_75 < F_49 ( V_73 ) ; V_75 ++ )
V_71 += snprintf ( & V_12 [ V_71 ] , V_68 - V_71 , L_10 ,
V_75 ? L_11 : L_12 , V_73 [ V_75 ] ,
V_75 == F_49 ( V_73 ) - 1 ? L_13 : L_12 ) ;
return V_71 < V_68 ? V_71 : V_68 - 1 ;
}
static T_3 F_53 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
const char * V_12 , T_4 V_74 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
unsigned long V_79 ;
int V_11 ;
V_11 = F_54 ( V_12 , 10 , & V_79 ) ;
if ( V_11 )
return V_11 ;
F_39 ( & V_2 -> V_53 ) ;
F_20 ( V_13 ) ;
V_2 -> V_36 = V_79 ;
if ( V_2 -> V_54 )
F_17 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
return V_74 ;
}
static T_3 F_55 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
char * V_12 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
unsigned V_79 ;
F_39 ( & V_2 -> V_53 ) ;
V_79 = V_2 -> V_36 ;
F_42 ( & V_2 -> V_53 ) ;
return snprintf ( V_12 , V_68 , L_14 , V_79 ) ;
}
static T_3 F_56 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
const char * V_12 , T_4 V_74 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
unsigned long V_79 ;
int V_11 ;
V_11 = F_54 ( V_12 , 10 , & V_79 ) ;
if ( V_11 )
return V_11 ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_54 ) {
F_40 ( V_13 ) ;
if ( V_79 )
V_11 = F_24 ( V_13 ) ;
else
V_11 = F_36 ( V_13 ) ;
F_41 ( V_13 ) ;
}
F_42 ( & V_2 -> V_53 ) ;
if ( V_11 )
return V_11 ;
return V_74 ;
}
static T_3 F_57 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
char * V_12 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
unsigned V_79 ;
F_39 ( & V_2 -> V_53 ) ;
V_79 = V_2 -> V_41 ;
F_42 ( & V_2 -> V_53 ) ;
return snprintf ( V_12 , V_68 , L_14 , V_79 ) ;
}
static T_3 F_58 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
const char * V_12 , T_4 V_74 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
unsigned long V_79 ;
int V_11 ;
V_11 = F_54 ( V_12 , 10 , & V_79 ) ;
if ( V_11 )
return V_11 ;
F_39 ( & V_2 -> V_53 ) ;
V_2 -> V_39 = V_79 ;
if ( V_2 -> V_54 ) {
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
F_41 ( V_13 ) ;
}
F_42 ( & V_2 -> V_53 ) ;
if ( V_11 )
return V_11 ;
return V_74 ;
}
static T_3 F_59 ( struct V_62 * V_35 ,
struct V_63 * V_64 ,
char * V_12 )
{
struct V_34 * V_13 = F_46 ( V_35 ) ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
unsigned V_79 ;
F_39 ( & V_2 -> V_53 ) ;
V_79 = V_2 -> V_39 ;
F_42 ( & V_2 -> V_53 ) ;
return snprintf ( V_12 , V_68 , L_14 , V_79 ) ;
}
static void F_60 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
if ( ! F_26 ( V_2 -> V_80 ) )
return;
F_61 ( V_2 -> V_80 , 1 ) ;
F_62 ( 10 ) ;
F_61 ( V_2 -> V_80 , 0 ) ;
F_62 ( 10 ) ;
F_61 ( V_2 -> V_80 , 1 ) ;
F_12 ( 5 ) ;
}
static void F_63 ( struct V_1 * V_2 ,
const struct V_81 * V_82 )
{
V_2 -> V_80 = V_82 -> V_80 ;
if ( V_82 -> V_83 )
V_2 -> V_43 = V_82 -> V_43 ;
else
V_2 -> V_43 = - 1 ;
V_2 -> V_36 = V_82 -> V_36 ;
V_2 -> V_39 = V_82 -> V_39 ;
V_2 -> V_84 = V_82 -> V_84 ;
V_2 -> V_85 = V_82 -> V_85 ;
}
static int F_64 ( struct V_34 * V_13 )
{
struct V_86 V_48 ;
struct V_1 * V_2 ;
struct V_46 * V_87 = NULL ;
int V_11 ;
F_38 ( V_13 -> V_35 , L_15 ) ;
V_2 = F_65 ( V_13 -> V_35 , sizeof( * V_2 ) , V_88 ) ;
if ( ! V_2 )
return - V_89 ;
F_66 ( V_13 -> V_35 , V_2 ) ;
V_2 -> V_13 = V_13 ;
if ( V_13 -> V_10 ) {
const struct V_81 * V_82 = V_13 -> V_10 ;
F_63 ( V_2 , V_82 ) ;
} else {
return - V_67 ;
}
V_13 -> V_58 . V_59 . V_60 = 864 ;
V_13 -> V_58 . V_59 . V_61 = 480 ;
V_13 -> V_58 . V_59 . V_90 = F_67 ( 864 * 480 * 60 , 1000 ) ;
V_13 -> V_58 . V_91 = V_92 ;
V_13 -> V_93 = V_94 |
V_95 ;
F_68 ( & V_2 -> V_53 ) ;
F_69 ( & V_2 -> V_96 , 0 ) ;
if ( F_26 ( V_2 -> V_80 ) ) {
V_11 = F_70 ( V_13 -> V_35 , V_2 -> V_80 ,
V_97 , L_16 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_17 ) ;
return V_11 ;
}
}
if ( F_26 ( V_2 -> V_43 ) ) {
V_11 = F_70 ( V_13 -> V_35 , V_2 -> V_43 ,
V_98 , L_18 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_19 ) ;
return V_11 ;
}
V_11 = F_71 ( V_13 -> V_35 , F_28 ( V_2 -> V_43 ) ,
V_99 ,
V_100 ,
L_20 , V_13 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_21 ) ;
return V_11 ;
}
F_72 ( & V_2 -> V_101 ,
V_102 ) ;
F_38 ( V_13 -> V_35 , L_22 ) ;
}
V_2 -> V_37 = F_73 ( L_23 ) ;
if ( V_2 -> V_37 == NULL ) {
F_30 ( V_13 -> V_35 , L_24 ) ;
return - V_89 ;
}
F_72 ( & V_2 -> V_38 , V_103 ) ;
F_74 ( & V_2 -> V_40 , V_104 ) ;
F_60 ( V_13 ) ;
if ( V_2 -> V_84 ) {
memset ( & V_48 , 0 , sizeof( struct V_86 ) ) ;
V_48 . V_105 = 255 ;
V_48 . type = V_106 ;
V_87 = F_75 ( F_76 ( V_13 -> V_35 ) ,
V_13 -> V_35 , V_13 , & V_107 , & V_48 ) ;
if ( F_77 ( V_87 ) ) {
V_11 = F_78 ( V_87 ) ;
goto V_108;
}
V_2 -> V_87 = V_87 ;
V_87 -> V_48 . V_49 = V_50 ;
V_87 -> V_48 . V_51 = V_50 ;
V_87 -> V_48 . V_52 = 255 ;
F_37 ( V_87 ) ;
}
V_11 = F_79 ( V_13 , & V_2 -> V_14 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_25 ) ;
goto V_109;
}
V_11 = F_80 ( V_13 , V_2 -> V_14 , V_110 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_26 ) ;
goto V_111;
}
V_11 = F_81 ( & V_13 -> V_35 -> V_112 , & V_113 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_27 ) ;
goto V_111;
}
return 0 ;
V_111:
F_82 ( V_13 , V_2 -> V_14 ) ;
V_109:
if ( V_87 != NULL )
F_83 ( V_87 ) ;
V_108:
F_84 ( V_2 -> V_37 ) ;
return V_11 ;
}
static void T_5 F_85 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
struct V_46 * V_87 ;
F_38 ( V_13 -> V_35 , L_28 ) ;
F_86 ( & V_13 -> V_35 -> V_112 , & V_113 ) ;
F_82 ( V_13 , V_2 -> V_14 ) ;
V_87 = V_2 -> V_87 ;
if ( V_87 != NULL ) {
V_87 -> V_48 . V_51 = V_114 ;
F_37 ( V_87 ) ;
F_83 ( V_87 ) ;
}
F_23 ( V_13 ) ;
F_20 ( V_13 ) ;
F_84 ( V_2 -> V_37 ) ;
F_60 ( V_13 ) ;
}
static int F_87 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
T_1 V_19 , V_20 , V_21 ;
int V_11 ;
struct V_115 V_116 = {
. V_70 = V_117 ,
. V_118 = V_92 ,
. V_59 = & V_13 -> V_58 . V_59 ,
. V_119 = 150000000 ,
. V_120 = 300000000 ,
. V_121 = 7000000 ,
. V_122 = 10000000 ,
} ;
V_11 = F_88 ( V_13 , & V_2 -> V_85 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_29 ) ;
goto V_123;
} ;
V_11 = F_89 ( V_13 , & V_116 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_30 ) ;
goto V_123;
}
V_11 = F_33 ( V_13 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_2 ) ;
goto V_123;
}
F_60 ( V_13 ) ;
F_34 ( V_13 , V_2 -> V_14 , false ) ;
V_11 = F_13 ( V_2 ) ;
if ( V_11 )
goto V_42;
V_11 = F_14 ( V_2 , & V_19 , & V_20 , & V_21 ) ;
if ( V_11 )
goto V_42;
if ( V_20 == 0x00 || V_20 == 0xff || V_20 == 0x81 )
V_2 -> V_77 = true ;
V_11 = F_9 ( V_2 , V_55 , 0xff ) ;
if ( V_11 )
goto V_42;
V_11 = F_9 ( V_2 , V_124 ,
( 1 << 2 ) | ( 1 << 5 ) ) ;
if ( V_11 )
goto V_42;
V_11 = F_9 ( V_2 , V_125 ,
V_126 ) ;
if ( V_11 )
goto V_42;
if ( ! V_2 -> V_77 ) {
V_11 = F_9 ( V_2 , V_78 , V_2 -> V_72 ) ;
if ( V_11 )
goto V_42;
}
V_11 = F_7 ( V_2 , V_127 ) ;
if ( V_11 )
goto V_42;
V_11 = F_25 ( V_13 , V_2 -> V_128 ) ;
if ( V_11 )
goto V_42;
V_11 = F_90 ( V_13 , V_2 -> V_14 ) ;
if ( V_11 )
goto V_42;
V_2 -> V_54 = 1 ;
if ( ! V_2 -> V_129 ) {
F_91 ( V_13 -> V_35 , L_31 ,
V_19 , V_20 , V_21 ) ;
if ( V_2 -> V_77 )
F_91 ( V_13 -> V_35 ,
L_32 ) ;
V_2 -> V_129 = true ;
}
F_34 ( V_13 , V_2 -> V_14 , true ) ;
return 0 ;
V_42:
F_30 ( V_13 -> V_35 , L_33 ) ;
F_60 ( V_13 ) ;
F_29 ( V_13 , true , false ) ;
V_123:
return V_11 ;
}
static void F_92 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
F_93 ( V_13 , V_2 -> V_14 ) ;
V_11 = F_7 ( V_2 , V_130 ) ;
if ( ! V_11 )
V_11 = F_10 ( V_2 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 ,
L_34 ) ;
F_60 ( V_13 ) ;
}
F_29 ( V_13 , true , false ) ;
V_2 -> V_54 = 0 ;
}
static int F_31 ( struct V_34 * V_13 )
{
F_30 ( V_13 -> V_35 , L_35 ) ;
F_92 ( V_13 ) ;
F_60 ( V_13 ) ;
return F_87 ( V_13 ) ;
}
static int F_94 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
F_38 ( V_13 -> V_35 , L_36 ) ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_13 -> V_131 != V_132 ) {
V_11 = - V_76 ;
goto V_42;
}
F_40 ( V_13 ) ;
V_11 = F_87 ( V_13 ) ;
F_41 ( V_13 ) ;
if ( V_11 )
goto V_42;
F_17 ( V_13 ) ;
V_13 -> V_131 = V_133 ;
F_42 ( & V_2 -> V_53 ) ;
return 0 ;
V_42:
F_38 ( V_13 -> V_35 , L_37 ) ;
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static void F_95 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
F_38 ( V_13 -> V_35 , L_38 ) ;
F_39 ( & V_2 -> V_53 ) ;
F_23 ( V_13 ) ;
F_20 ( V_13 ) ;
F_40 ( V_13 ) ;
if ( V_13 -> V_131 == V_133 ) {
int V_11 ;
V_11 = F_36 ( V_13 ) ;
if ( ! V_11 )
F_92 ( V_13 ) ;
}
F_41 ( V_13 ) ;
V_13 -> V_131 = V_132 ;
F_42 ( & V_2 -> V_53 ) ;
}
static void F_96 ( int V_42 , void * V_10 )
{
struct V_34 * V_13 = V_10 ;
F_38 ( V_13 -> V_35 , L_39 , V_42 ) ;
F_41 ( V_13 ) ;
}
static T_6 V_99 ( int V_134 , void * V_10 )
{
struct V_34 * V_13 = V_10 ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_135 ;
int V_11 ;
V_135 = F_97 ( & V_2 -> V_96 , 1 , 0 ) ;
if ( V_135 ) {
F_21 ( & V_2 -> V_101 ) ;
V_11 = F_98 ( V_13 , V_2 -> V_14 , F_96 ,
V_13 ) ;
if ( V_11 )
goto V_42;
}
return V_136 ;
V_42:
F_30 ( V_13 -> V_35 , L_40 ) ;
F_41 ( V_13 ) ;
return V_136 ;
}
static void V_102 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_99 ( V_138 , struct V_1 ,
V_101 . V_138 ) ;
struct V_34 * V_13 = V_2 -> V_13 ;
F_30 ( V_13 -> V_35 , L_41 ) ;
F_69 ( & V_2 -> V_96 , 0 ) ;
F_41 ( V_13 ) ;
}
static int F_100 ( struct V_34 * V_13 ,
T_2 V_25 , T_2 V_26 , T_2 V_27 , T_2 V_28 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
F_38 ( V_13 -> V_35 , L_42 , V_25 , V_26 , V_27 , V_28 ) ;
F_39 ( & V_2 -> V_53 ) ;
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( V_11 )
goto V_42;
if ( ! V_2 -> V_54 ) {
V_11 = 0 ;
goto V_42;
}
V_11 = F_15 ( V_2 , 0 , 0 ,
V_13 -> V_58 . V_59 . V_60 ,
V_13 -> V_58 . V_59 . V_61 ) ;
if ( V_11 )
goto V_42;
if ( V_2 -> V_128 && F_26 ( V_2 -> V_43 ) ) {
F_101 ( & V_2 -> V_101 ,
F_2 ( 250 ) ) ;
F_69 ( & V_2 -> V_96 , 1 ) ;
} else {
V_11 = F_98 ( V_13 , V_2 -> V_14 , F_96 ,
V_13 ) ;
if ( V_11 )
goto V_42;
}
F_42 ( & V_2 -> V_53 ) ;
return 0 ;
V_42:
F_41 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static int F_102 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
F_38 ( V_13 -> V_35 , L_43 ) ;
F_39 ( & V_2 -> V_53 ) ;
F_40 ( V_13 ) ;
F_41 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
F_38 ( V_13 -> V_35 , L_44 ) ;
return 0 ;
}
static int F_25 ( struct V_34 * V_13 , bool V_139 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
if ( V_139 )
V_11 = F_9 ( V_2 , V_140 , 0 ) ;
else
V_11 = F_7 ( V_2 , V_141 ) ;
if ( ! F_26 ( V_2 -> V_43 ) )
F_103 ( V_13 , V_139 ) ;
F_12 ( 100 ) ;
return V_11 ;
}
static int F_104 ( struct V_34 * V_13 , bool V_139 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_2 -> V_128 == V_139 )
goto V_142;
F_40 ( V_13 ) ;
if ( V_2 -> V_54 ) {
V_11 = F_36 ( V_13 ) ;
if ( V_11 )
goto V_42;
V_11 = F_25 ( V_13 , V_139 ) ;
if ( V_11 )
goto V_42;
}
V_2 -> V_128 = V_139 ;
F_41 ( V_13 ) ;
V_142:
F_42 ( & V_2 -> V_53 ) ;
return 0 ;
V_42:
F_41 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static int F_105 ( struct V_34 * V_13 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
int V_11 ;
F_39 ( & V_2 -> V_53 ) ;
V_11 = V_2 -> V_128 ;
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static int F_106 ( struct V_34 * V_13 , int V_143 )
{
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
T_1 V_19 , V_20 , V_21 ;
int V_11 ;
F_39 ( & V_2 -> V_53 ) ;
if ( ! V_2 -> V_54 ) {
V_11 = - V_67 ;
goto V_44;
}
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( V_11 )
goto V_45;
V_11 = F_5 ( V_2 , V_22 , & V_19 ) ;
if ( V_11 )
goto V_45;
V_11 = F_5 ( V_2 , V_23 , & V_20 ) ;
if ( V_11 )
goto V_45;
V_11 = F_5 ( V_2 , V_24 , & V_21 ) ;
if ( V_11 )
goto V_45;
F_41 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
return 0 ;
V_45:
F_41 ( V_13 ) ;
V_44:
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static int F_107 ( struct V_34 * V_13 ,
void * V_12 , T_4 V_144 ,
T_2 V_25 , T_2 V_26 , T_2 V_27 , T_2 V_28 )
{
int V_11 ;
int V_145 = 1 ;
int V_146 ;
unsigned V_147 = 0 ;
struct V_1 * V_2 = F_18 ( V_13 -> V_35 ) ;
if ( V_144 < V_27 * V_28 * 3 )
return - V_89 ;
F_39 ( & V_2 -> V_53 ) ;
if ( ! V_2 -> V_54 ) {
V_11 = - V_67 ;
goto V_44;
}
V_144 = F_108 ( V_27 * V_28 * 3 ,
V_13 -> V_58 . V_59 . V_60 *
V_13 -> V_58 . V_59 . V_61 * 3 ) ;
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( V_11 )
goto V_45;
if ( V_144 % 2 )
V_146 = 1 ;
else
V_146 = 2 ;
F_15 ( V_2 , V_25 , V_26 , V_27 , V_28 ) ;
V_11 = F_109 ( V_13 , V_2 -> V_14 , V_146 ) ;
if ( V_11 )
goto V_45;
while ( V_147 < V_144 ) {
T_1 V_9 = V_145 ? 0x2e : 0x3e ;
V_145 = 0 ;
V_11 = F_6 ( V_13 , V_2 -> V_14 , V_9 ,
V_12 + V_147 , V_144 - V_147 ) ;
if ( V_11 < 0 ) {
F_30 ( V_13 -> V_35 , L_45 ) ;
goto V_148;
}
V_147 += V_11 ;
if ( V_11 < V_146 ) {
F_30 ( V_13 -> V_35 , L_46 ) ;
break;
}
if ( F_110 ( V_149 ) ) {
F_30 ( V_13 -> V_35 , L_47
L_48 ) ;
V_11 = - V_150 ;
goto V_148;
}
}
V_11 = V_147 ;
V_148:
F_109 ( V_13 , V_2 -> V_14 , 1 ) ;
V_45:
F_41 ( V_13 ) ;
V_44:
F_42 ( & V_2 -> V_53 ) ;
return V_11 ;
}
static void V_104 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_99 ( V_138 , struct V_1 ,
V_40 . V_138 ) ;
struct V_34 * V_13 = V_2 -> V_13 ;
F_39 ( & V_2 -> V_53 ) ;
if ( V_13 -> V_131 != V_133 || ! V_2 -> V_54 ) {
F_42 ( & V_2 -> V_53 ) ;
return;
}
F_40 ( V_13 ) ;
F_24 ( V_13 ) ;
F_41 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
}
static void V_103 ( struct V_137 * V_138 )
{
struct V_1 * V_2 = F_99 ( V_138 , struct V_1 ,
V_38 . V_138 ) ;
struct V_34 * V_13 = V_2 -> V_13 ;
T_1 V_151 , V_152 ;
int V_11 ;
F_39 ( & V_2 -> V_53 ) ;
if ( ! V_2 -> V_54 ) {
F_42 ( & V_2 -> V_53 ) ;
return;
}
F_40 ( V_13 ) ;
V_11 = F_36 ( V_13 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_49 ) ;
goto V_42;
}
V_11 = F_5 ( V_2 , V_153 , & V_151 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_50 ) ;
goto V_42;
}
V_11 = F_13 ( V_2 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_51 ) ;
goto V_42;
}
V_11 = F_5 ( V_2 , V_153 , & V_152 ) ;
if ( V_11 ) {
F_30 ( V_13 -> V_35 , L_50 ) ;
goto V_42;
}
if ( ! ( ( V_151 ^ V_152 ) & ( 1 << 6 ) ) ) {
F_30 ( V_13 -> V_35 , L_52 ) ;
goto V_42;
}
if ( V_2 -> V_128 && F_26 ( V_2 -> V_43 ) ) {
V_11 = F_9 ( V_2 , V_140 , 0 ) ;
if ( V_11 )
goto V_42;
}
F_41 ( V_13 ) ;
F_17 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
return;
V_42:
F_30 ( V_13 -> V_35 , L_35 ) ;
F_31 ( V_13 ) ;
F_41 ( V_13 ) ;
F_17 ( V_13 ) ;
F_42 ( & V_2 -> V_53 ) ;
}
static int T_7 F_111 ( void )
{
F_112 ( & V_154 ) ;
return 0 ;
}
static void T_5 F_113 ( void )
{
F_114 ( & V_154 ) ;
}
