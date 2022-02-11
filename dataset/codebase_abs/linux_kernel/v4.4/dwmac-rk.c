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
V_11 ) ;
F_4 ( V_2 -> V_8 , V_12 ,
V_13 |
V_14 |
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
V_15 | V_16 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_17 )
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
static void F_9 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_1 ) ;
return;
}
if ( V_17 == 10 ) {
F_4 ( V_2 -> V_8 , V_9 ,
V_21 |
V_22 ) ;
} else if ( V_17 == 100 ) {
F_4 ( V_2 -> V_8 , V_9 ,
V_23 |
V_24 ) ;
} else {
F_3 ( V_6 , L_3 , V_17 ) ;
}
}
static void F_10 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_25 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_26 ,
V_27 |
V_28 ) ;
F_4 ( V_2 -> V_8 , V_29 ,
V_30 |
V_31 |
F_11 ( V_4 ) |
F_12 ( V_3 ) ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_25 ) ;
return;
}
F_4 ( V_2 -> V_8 , V_26 ,
V_32 | V_33 ) ;
}
static void F_14 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_25 ) ;
return;
}
if ( V_17 == 10 )
F_4 ( V_2 -> V_8 , V_26 ,
V_34 ) ;
else if ( V_17 == 100 )
F_4 ( V_2 -> V_8 , V_26 ,
V_35 ) ;
else if ( V_17 == 1000 )
F_4 ( V_2 -> V_8 , V_26 ,
V_36 ) ;
else
F_3 ( V_6 , L_2 , V_17 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( F_2 ( V_2 -> V_8 ) ) {
F_3 ( V_6 , L_4 , V_25 ) ;
return;
}
if ( V_17 == 10 ) {
F_4 ( V_2 -> V_8 , V_26 ,
V_37 |
V_38 ) ;
} else if ( V_17 == 100 ) {
F_4 ( V_2 -> V_8 , V_26 ,
V_39 |
V_40 ) ;
} else {
F_3 ( V_6 , L_3 , V_17 ) ;
}
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
V_2 -> V_41 = false ;
V_2 -> V_42 = F_17 ( V_6 , L_5 ) ;
if ( F_2 ( V_2 -> V_42 ) )
F_3 ( V_6 , L_6 ,
L_5 ) ;
V_2 -> V_43 = F_17 ( V_6 , L_7 ) ;
if ( F_2 ( V_2 -> V_43 ) )
F_3 ( V_6 , L_6 ,
L_7 ) ;
V_2 -> V_44 = F_17 ( V_6 , L_8 ) ;
if ( F_2 ( V_2 -> V_44 ) )
F_3 ( V_6 , L_6 ,
L_8 ) ;
V_2 -> V_45 = F_17 ( V_6 , L_9 ) ;
if ( F_2 ( V_2 -> V_45 ) )
F_3 ( V_6 , L_6 ,
L_9 ) ;
V_2 -> V_46 = F_17 ( V_6 , L_10 ) ;
if ( F_2 ( V_2 -> V_46 ) )
F_3 ( V_6 , L_6 ,
L_10 ) ;
if ( V_2 -> V_47 == V_48 ) {
V_2 -> V_49 = F_17 ( V_6 , L_11 ) ;
if ( F_2 ( V_2 -> V_49 ) )
F_3 ( V_6 , L_6 ,
L_11 ) ;
if ( ! V_2 -> V_50 ) {
V_2 -> V_51 =
F_17 ( V_6 , L_12 ) ;
if ( F_2 ( V_2 -> V_51 ) )
F_3 ( V_6 , L_6 ,
L_12 ) ;
}
}
if ( V_2 -> V_50 ) {
F_18 ( V_6 , L_13 ) ;
} else {
if ( V_2 -> V_47 == V_48 )
F_19 ( V_2 -> V_46 , 50000000 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , bool V_52 )
{
int V_47 = V_2 -> V_47 ;
if ( V_52 ) {
if ( ! V_2 -> V_41 ) {
if ( V_47 == V_48 ) {
if ( ! F_2 ( V_2 -> V_42 ) )
F_21 (
V_2 -> V_42 ) ;
if ( ! F_2 ( V_2 -> V_49 ) )
F_21 (
V_2 -> V_49 ) ;
if ( ! F_2 ( V_2 -> V_51 ) )
F_21 (
V_2 -> V_51 ) ;
}
if ( ! F_2 ( V_2 -> V_44 ) )
F_21 ( V_2 -> V_44 ) ;
if ( ! F_2 ( V_2 -> V_45 ) )
F_21 ( V_2 -> V_45 ) ;
if ( ! F_2 ( V_2 -> V_43 ) )
F_21 ( V_2 -> V_43 ) ;
F_22 ( 5 ) ;
V_2 -> V_41 = true ;
}
} else {
if ( V_2 -> V_41 ) {
if ( V_47 == V_48 ) {
if ( ! F_2 ( V_2 -> V_42 ) )
F_23 (
V_2 -> V_42 ) ;
if ( ! F_2 ( V_2 -> V_49 ) )
F_23 (
V_2 -> V_49 ) ;
if ( ! F_2 ( V_2 -> V_51 ) )
F_23 (
V_2 -> V_51 ) ;
}
if ( ! F_2 ( V_2 -> V_44 ) )
F_23 ( V_2 -> V_44 ) ;
if ( ! F_2 ( V_2 -> V_45 ) )
F_23 ( V_2 -> V_45 ) ;
if ( ! F_2 ( V_2 -> V_43 ) )
F_23 ( V_2 -> V_43 ) ;
V_2 -> V_41 = false ;
}
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , bool V_52 )
{
struct V_53 * V_54 = V_2 -> V_53 ;
int V_55 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( ! V_54 ) {
F_3 ( V_6 , L_14 ) ;
return - 1 ;
}
if ( V_52 ) {
V_55 = F_25 ( V_54 ) ;
if ( V_55 )
F_3 ( V_6 , L_15 ) ;
} else {
V_55 = F_26 ( V_54 ) ;
if ( V_55 )
F_3 ( V_6 , L_16 ) ;
}
return 0 ;
}
static struct V_1 * F_27 ( struct V_56 * V_7 ,
const struct V_57 * V_58 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 = & V_7 -> V_6 ;
int V_55 ;
const char * V_59 = NULL ;
int V_60 ;
V_2 = F_28 ( V_6 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 )
return F_29 ( - V_62 ) ;
V_2 -> V_47 = F_30 ( V_6 -> V_63 ) ;
V_2 -> V_58 = V_58 ;
V_2 -> V_53 = F_31 ( V_6 , L_17 ) ;
if ( F_2 ( V_2 -> V_53 ) ) {
if ( F_32 ( V_2 -> V_53 ) == - V_64 ) {
F_3 ( V_6 , L_18 ) ;
return F_29 ( - V_64 ) ;
}
F_3 ( V_6 , L_14 ) ;
V_2 -> V_53 = NULL ;
}
V_55 = F_33 ( V_6 -> V_63 , L_19 , & V_59 ) ;
if ( V_55 ) {
F_3 ( V_6 , L_20 ) ;
V_2 -> V_50 = true ;
} else {
F_18 ( V_6 , L_21 ,
V_59 ) ;
if ( ! strcmp ( V_59 , L_22 ) )
V_2 -> V_50 = true ;
else
V_2 -> V_50 = false ;
}
V_55 = F_34 ( V_6 -> V_63 , L_23 , & V_60 ) ;
if ( V_55 ) {
V_2 -> V_3 = 0x30 ;
F_3 ( V_6 , L_24 ) ;
F_3 ( V_6 , L_25 ,
V_2 -> V_3 ) ;
} else {
F_18 ( V_6 , L_26 , V_60 ) ;
V_2 -> V_3 = V_60 ;
}
V_55 = F_34 ( V_6 -> V_63 , L_27 , & V_60 ) ;
if ( V_55 ) {
V_2 -> V_4 = 0x10 ;
F_3 ( V_6 , L_28 ) ;
F_3 ( V_6 , L_29 ,
V_2 -> V_4 ) ;
} else {
F_18 ( V_6 , L_30 , V_60 ) ;
V_2 -> V_4 = V_60 ;
}
V_2 -> V_8 = F_35 ( V_6 -> V_63 ,
L_31 ) ;
V_2 -> V_7 = V_7 ;
if ( V_2 -> V_47 == V_65 ) {
F_18 ( V_6 , L_32 ) ;
V_2 -> V_58 -> V_66 ( V_2 , V_2 -> V_3 ,
V_2 -> V_4 ) ;
} else if ( V_2 -> V_47 == V_48 ) {
F_18 ( V_6 , L_33 ) ;
V_2 -> V_58 -> V_67 ( V_2 ) ;
} else {
F_3 ( V_6 , L_34 ) ;
}
F_16 ( V_2 ) ;
return V_2 ;
}
static int F_36 ( struct V_56 * V_7 , void * V_68 )
{
struct V_1 * V_2 = V_68 ;
int V_55 ;
V_55 = F_24 ( V_2 , true ) ;
if ( V_55 )
return V_55 ;
V_55 = F_20 ( V_2 , true ) ;
if ( V_55 )
return V_55 ;
return 0 ;
}
static void F_37 ( struct V_56 * V_7 , void * V_68 )
{
struct V_1 * V_69 = V_68 ;
F_24 ( V_69 , false ) ;
F_20 ( V_69 , false ) ;
}
static void F_38 ( void * V_68 , unsigned int V_17 )
{
struct V_1 * V_2 = V_68 ;
struct V_5 * V_6 = & V_2 -> V_7 -> V_6 ;
if ( V_2 -> V_47 == V_65 )
V_2 -> V_58 -> V_70 ( V_2 , V_17 ) ;
else if ( V_2 -> V_47 == V_48 )
V_2 -> V_58 -> V_71 ( V_2 , V_17 ) ;
else
F_3 ( V_6 , L_35 , V_2 -> V_47 ) ;
}
static int F_39 ( struct V_56 * V_7 )
{
struct V_72 * V_73 ;
struct V_74 V_75 ;
const struct V_57 * V_76 ;
int V_55 ;
V_76 = F_40 ( & V_7 -> V_6 ) ;
if ( ! V_76 ) {
F_3 ( & V_7 -> V_6 , L_36 ) ;
return - V_77 ;
}
V_55 = F_41 ( V_7 , & V_75 ) ;
if ( V_55 )
return V_55 ;
V_73 = F_42 ( V_7 , & V_75 . V_78 ) ;
if ( F_2 ( V_73 ) )
return F_32 ( V_73 ) ;
V_73 -> V_79 = true ;
V_73 -> V_80 = F_36 ;
V_73 -> exit = F_37 ;
V_73 -> V_81 = F_38 ;
V_73 -> V_2 = F_27 ( V_7 , V_76 ) ;
if ( F_2 ( V_73 -> V_2 ) )
return F_32 ( V_73 -> V_2 ) ;
V_55 = F_36 ( V_7 , V_73 -> V_2 ) ;
if ( V_55 )
return V_55 ;
return F_43 ( & V_7 -> V_6 , V_73 , & V_75 ) ;
}
