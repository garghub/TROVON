static void F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_9 ,
V_10 |
V_11 |
V_12 |
V_13 ) ;
F_4 ( V_2 -> V_8 , V_14 ,
F_5 ( V_4 ) |
F_6 ( V_3 ) ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_9 ,
V_15 |
V_16 ) ;
F_4 ( V_2 -> V_8 , V_9 , F_8 ( 11 ) ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
if ( V_17 == 10 )
F_4 ( V_2 -> V_8 , V_9 ,
V_18 ) ;
else if ( V_17 == 100 )
F_4 ( V_2 -> V_8 , V_9 ,
V_19 ) ;
else if ( V_17 == 1000 )
F_4 ( V_2 -> V_8 , V_9 ,
V_20 ) ;
else
F_3 ( V_6 , L_2 , V_17 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
if ( V_17 == 10 )
F_4 ( V_2 -> V_8 , V_9 ,
V_21 |
V_22 ) ;
else if ( V_17 == 100 )
F_4 ( V_2 -> V_8 , V_9 ,
V_23 |
V_24 ) ;
else
F_3 ( V_6 , L_3 , V_17 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_25 ,
V_26 |
V_27 ) ;
F_4 ( V_2 -> V_8 , V_28 ,
V_29 |
V_30 |
F_12 ( V_4 ) |
F_13 ( V_3 ) ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_25 ,
V_31 | V_32 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
if ( V_17 == 10 )
F_4 ( V_2 -> V_8 , V_25 ,
V_33 ) ;
else if ( V_17 == 100 )
F_4 ( V_2 -> V_8 , V_25 ,
V_34 ) ;
else if ( V_17 == 1000 )
F_4 ( V_2 -> V_8 , V_25 ,
V_35 ) ;
else
F_3 ( V_6 , L_2 , V_17 ) ;
}
static void F_16 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
if ( V_17 == 10 ) {
F_4 ( V_2 -> V_8 , V_25 ,
V_36 |
V_37 ) ;
} else if ( V_17 == 100 ) {
F_4 ( V_2 -> V_8 , V_25 ,
V_38 |
V_39 ) ;
} else {
F_3 ( V_6 , L_3 , V_17 ) ;
}
}
static void F_17 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_40 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_41 ,
V_42 |
V_43 ) ;
F_4 ( V_2 -> V_8 , V_44 ,
V_45 |
V_46 |
F_18 ( V_4 ) |
F_19 ( V_3 ) ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_40 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_41 ,
V_47 | V_48 ) ;
}
static void F_21 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_40 ) ;
return;
}
if ( V_17 == 10 )
F_4 ( V_2 -> V_8 , V_41 ,
V_49 ) ;
else if ( V_17 == 100 )
F_4 ( V_2 -> V_8 , V_41 ,
V_50 ) ;
else if ( V_17 == 1000 )
F_4 ( V_2 -> V_8 , V_41 ,
V_51 ) ;
else
F_3 ( V_6 , L_2 , V_17 ) ;
}
static void F_22 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_40 ) ;
return;
}
if ( V_17 == 10 ) {
F_4 ( V_2 -> V_8 , V_41 ,
V_52 |
V_53 ) ;
} else if ( V_17 == 100 ) {
F_4 ( V_2 -> V_8 , V_41 ,
V_54 |
V_55 ) ;
} else {
F_3 ( V_6 , L_3 , V_17 ) ;
}
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
V_2 -> V_56 = false ;
V_2 -> V_57 = F_24 ( V_6 , L_5 ) ;
if ( F_2 ( V_2 -> V_57 ) )
F_3 ( V_6 , L_6 ,
L_5 ) ;
V_2 -> V_58 = F_24 ( V_6 , L_7 ) ;
if ( F_2 ( V_2 -> V_58 ) )
F_3 ( V_6 , L_6 ,
L_7 ) ;
V_2 -> V_59 = F_24 ( V_6 , L_8 ) ;
if ( F_2 ( V_2 -> V_59 ) )
F_3 ( V_6 , L_6 ,
L_8 ) ;
V_2 -> V_60 = F_24 ( V_6 , L_9 ) ;
if ( F_2 ( V_2 -> V_60 ) )
F_3 ( V_6 , L_6 ,
L_9 ) ;
V_2 -> V_61 = F_24 ( V_6 , L_10 ) ;
if ( F_2 ( V_2 -> V_61 ) )
F_3 ( V_6 , L_6 ,
L_10 ) ;
if ( V_2 -> V_62 == V_63 ) {
V_2 -> V_64 = F_24 ( V_6 , L_11 ) ;
if ( F_2 ( V_2 -> V_64 ) )
F_3 ( V_6 , L_6 ,
L_11 ) ;
if ( ! V_2 -> V_65 ) {
V_2 -> V_66 =
F_24 ( V_6 , L_12 ) ;
if ( F_2 ( V_2 -> V_66 ) )
F_3 ( V_6 , L_6 ,
L_12 ) ;
}
}
if ( V_2 -> V_65 ) {
F_25 ( V_6 , L_13 ) ;
} else {
if ( V_2 -> V_62 == V_63 )
F_26 ( V_2 -> V_61 , 50000000 ) ;
}
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , bool V_67 )
{
int V_62 = V_2 -> V_62 ;
if ( V_67 ) {
if ( ! V_2 -> V_56 ) {
if ( V_62 == V_63 ) {
if ( ! F_2 ( V_2 -> V_57 ) )
F_28 (
V_2 -> V_57 ) ;
if ( ! F_2 ( V_2 -> V_64 ) )
F_28 (
V_2 -> V_64 ) ;
if ( ! F_2 ( V_2 -> V_66 ) )
F_28 (
V_2 -> V_66 ) ;
}
if ( ! F_2 ( V_2 -> V_59 ) )
F_28 ( V_2 -> V_59 ) ;
if ( ! F_2 ( V_2 -> V_60 ) )
F_28 ( V_2 -> V_60 ) ;
if ( ! F_2 ( V_2 -> V_58 ) )
F_28 ( V_2 -> V_58 ) ;
F_29 ( 5 ) ;
V_2 -> V_56 = true ;
}
} else {
if ( V_2 -> V_56 ) {
if ( V_62 == V_63 ) {
if ( ! F_2 ( V_2 -> V_57 ) )
F_30 (
V_2 -> V_57 ) ;
if ( ! F_2 ( V_2 -> V_64 ) )
F_30 (
V_2 -> V_64 ) ;
if ( ! F_2 ( V_2 -> V_66 ) )
F_30 (
V_2 -> V_66 ) ;
}
if ( ! F_2 ( V_2 -> V_59 ) )
F_30 ( V_2 -> V_59 ) ;
if ( ! F_2 ( V_2 -> V_60 ) )
F_30 ( V_2 -> V_60 ) ;
if ( ! F_2 ( V_2 -> V_58 ) )
F_30 ( V_2 -> V_58 ) ;
V_2 -> V_56 = false ;
}
}
return 0 ;
}
static int F_31 ( struct V_1 * V_2 , bool V_67 )
{
struct V_68 * V_69 = V_2 -> V_68 ;
int V_70 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( ! V_69 ) {
F_3 ( V_6 , L_14 ) ;
return - 1 ;
}
if ( V_67 ) {
V_70 = F_32 ( V_69 ) ;
if ( V_70 )
F_3 ( V_6 , L_15 ) ;
} else {
V_70 = F_33 ( V_69 ) ;
if ( V_70 )
F_3 ( V_6 , L_16 ) ;
}
return 0 ;
}
static struct V_1 * F_34 ( struct V_71 * V_7 ,
const struct V_72 * V_73 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = & V_7 -> V_6 ;
int V_70 ;
const char * V_74 = NULL ;
int V_75 ;
V_2 = F_35 ( V_6 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 )
return F_36 ( - V_77 ) ;
V_2 -> V_62 = F_37 ( V_6 -> V_78 ) ;
V_2 -> V_73 = V_73 ;
V_2 -> V_68 = F_38 ( V_6 , L_17 ) ;
if ( F_2 ( V_2 -> V_68 ) ) {
if ( F_39 ( V_2 -> V_68 ) == - V_79 ) {
F_3 ( V_6 , L_18 ) ;
return F_36 ( - V_79 ) ;
}
F_3 ( V_6 , L_14 ) ;
V_2 -> V_68 = NULL ;
}
V_70 = F_40 ( V_6 -> V_78 , L_19 , & V_74 ) ;
if ( V_70 ) {
F_3 ( V_6 , L_20 ) ;
V_2 -> V_65 = true ;
} else {
F_25 ( V_6 , L_21 ,
V_74 ) ;
if ( ! strcmp ( V_74 , L_22 ) )
V_2 -> V_65 = true ;
else
V_2 -> V_65 = false ;
}
V_70 = F_41 ( V_6 -> V_78 , L_23 , & V_75 ) ;
if ( V_70 ) {
V_2 -> V_3 = 0x30 ;
F_3 ( V_6 , L_24 ) ;
F_3 ( V_6 , L_25 ,
V_2 -> V_3 ) ;
} else {
F_25 ( V_6 , L_26 , V_75 ) ;
V_2 -> V_3 = V_75 ;
}
V_70 = F_41 ( V_6 -> V_78 , L_27 , & V_75 ) ;
if ( V_70 ) {
V_2 -> V_4 = 0x10 ;
F_3 ( V_6 , L_28 ) ;
F_3 ( V_6 , L_29 ,
V_2 -> V_4 ) ;
} else {
F_25 ( V_6 , L_30 , V_75 ) ;
V_2 -> V_4 = V_75 ;
}
V_2 -> V_8 = F_42 ( V_6 -> V_78 ,
L_31 ) ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_62 == V_80 ) {
F_25 ( V_6 , L_32 ) ;
V_2 -> V_73 -> V_81 ( V_2 , V_2 -> V_3 ,
V_2 -> V_4 ) ;
} else if ( V_2 -> V_62 == V_63 ) {
F_25 ( V_6 , L_33 ) ;
V_2 -> V_73 -> V_82 ( V_2 ) ;
} else {
F_3 ( V_6 , L_34 ) ;
}
F_23 ( V_2 ) ;
return V_2 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_70 ;
V_70 = F_31 ( V_2 , true ) ;
if ( V_70 )
return V_70 ;
V_70 = F_27 ( V_2 , true ) ;
if ( V_70 )
return V_70 ;
return 0 ;
}
static void F_44 ( struct V_1 * V_83 )
{
F_31 ( V_83 , false ) ;
F_27 ( V_83 , false ) ;
}
static int F_45 ( struct V_71 * V_7 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
return F_43 ( V_2 ) ;
}
static void F_46 ( struct V_71 * V_7 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
F_44 ( V_2 ) ;
}
static void F_47 ( struct V_71 * V_7 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
if ( F_48 ( & V_7 -> V_6 ) )
return;
F_44 ( V_2 ) ;
V_2 -> V_85 = true ;
}
static void F_49 ( struct V_71 * V_7 , void * V_84 )
{
struct V_1 * V_2 = V_84 ;
if ( ! V_2 -> V_85 )
return;
F_43 ( V_2 ) ;
V_2 -> V_85 = false ;
}
static void F_50 ( void * V_84 , unsigned int V_17 )
{
struct V_1 * V_2 = V_84 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( V_2 -> V_62 == V_80 )
V_2 -> V_73 -> V_86 ( V_2 , V_17 ) ;
else if ( V_2 -> V_62 == V_63 )
V_2 -> V_73 -> V_87 ( V_2 , V_17 ) ;
else
F_3 ( V_6 , L_35 , V_2 -> V_62 ) ;
}
static int F_51 ( struct V_71 * V_7 )
{
struct V_88 * V_89 ;
struct V_90 V_91 ;
const struct V_72 * V_92 ;
int V_70 ;
V_92 = F_52 ( & V_7 -> V_6 ) ;
if ( ! V_92 ) {
F_3 ( & V_7 -> V_6 , L_36 ) ;
return - V_93 ;
}
V_70 = F_53 ( V_7 , & V_91 ) ;
if ( V_70 )
return V_70 ;
V_89 = F_54 ( V_7 , & V_91 . V_94 ) ;
if ( F_2 ( V_89 ) )
return F_39 ( V_89 ) ;
V_89 -> V_95 = true ;
V_89 -> V_96 = F_45 ;
V_89 -> exit = F_46 ;
V_89 -> V_97 = F_50 ;
V_89 -> V_98 = F_47 ;
V_89 -> V_99 = F_49 ;
V_89 -> V_2 = F_34 ( V_7 , V_92 ) ;
if ( F_2 ( V_89 -> V_2 ) )
return F_39 ( V_89 -> V_2 ) ;
V_70 = F_45 ( V_7 , V_89 -> V_2 ) ;
if ( V_70 )
return V_70 ;
return F_55 ( & V_7 -> V_6 , V_89 , & V_91 ) ;
}
