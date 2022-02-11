static unsigned long F_1 ( unsigned long V_1 ,
unsigned long V_2 ,
unsigned long V_3 )
{
F_2 ( L_1 ,
V_1 ,
V_2 ,
V_3 ) ;
F_3 ( ! F_4 ( V_1 , 4096 ) ) ;
return F_5 ( V_4 ,
V_1 ,
V_2 ,
V_3 ) ;
}
static unsigned long F_6 ( char V_5 [] ,
T_1 V_2 , T_2 V_3 )
{
return F_1 ( F_7 ( V_5 ) ,
V_2 , V_3 ) ;
}
static T_3 F_8 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_10 * V_11 , char * V_12 ,
T_4 V_13 , T_5 V_14 )
{
unsigned long V_15 ;
T_3 V_16 = 0 ;
T_5 V_17 = 0 , V_18 = 0 ;
T_4 V_19 = 0 ;
T_4 V_20 ;
T_5 V_21 ;
T_6 V_22 = 0 ;
void * V_5 = F_9 ( V_23 , V_24 ) ;
struct V_25 * V_26 = V_5 ;
if ( ! V_5 )
return - V_27 ;
V_15 = F_6 ( V_5 , 0 , 0 ) ;
if ( V_15 ) {
V_16 = - V_28 ;
goto V_29;
}
V_22 = F_10 ( V_26 -> V_2 ) ;
V_18 = F_11 ( V_26 -> V_30 ) ;
V_17 = V_18 * 4096 ;
V_19 = V_13 / 4096 ;
V_20 = V_13 % 4096 ;
if ( V_19 >= V_18 )
goto V_29;
if ( V_19 != 0 ) {
V_15 = F_6 ( V_5 , V_22 ,
V_19 ) ;
if ( V_15 ) {
V_16 = - V_28 ;
goto V_29;
}
}
V_21 = 4096 - V_20 ;
if ( V_21 > V_14 )
V_21 = V_14 ;
memcpy ( V_12 , V_5 + V_20 , V_21 ) ;
V_16 = V_21 ;
V_29:
if ( V_15 )
F_12 ( L_2
L_3 ,
V_22 , V_19 , V_15 ) ;
F_13 ( V_23 , V_5 ) ;
F_2 ( L_4
L_5 , V_13 , V_19 ,
V_14 , V_17 , V_18 , V_16 ) ;
return V_16 ;
}
static bool F_14 ( int V_31 )
{
return V_31 == V_32 ||
V_31 == V_33 ;
}
static unsigned long F_15 ( T_7 V_31 , T_2 V_13 , T_8 V_34 ,
T_8 V_35 , T_1 * V_36 ,
bool V_37 )
{
unsigned long V_16 ;
struct V_38 {
struct V_39 V_12 ;
struct V_40 V_41 ;
} V_42 * V_43 ;
struct {
struct V_44 V_12 ;
struct V_45 V_36 ;
struct V_46 V_47 ;
T_9 V_48 ;
} V_42 * V_49 ;
F_16 ( sizeof( * V_43 ) > 4096 ) ;
F_16 ( sizeof( * V_49 ) > 4096 ) ;
V_43 = ( void * ) F_17 ( V_50 ) ;
V_49 = ( void * ) F_17 ( V_51 ) ;
memset ( V_43 , 0 , 4096 ) ;
memset ( V_49 , 0 , 4096 ) ;
* V_43 = (struct V_38 ) {
. V_12 = {
. V_52 = V_53 ,
. V_54 = 1 ,
} ,
. V_41 = {
. V_55 = V_31 ,
. V_56 = F_18 ( 8 ) ,
. V_57 = F_19 ( V_13 ) ,
. V_58 = F_18 ( V_35 ) ,
. V_59 = F_18 ( 1 ) ,
. V_60 = F_18 ( V_34 ) ,
. V_61 = F_18 ( 1 ) ,
}
} ;
V_16 = F_5 ( V_62 ,
F_7 ( V_43 ) , sizeof( * V_43 ) ,
F_7 ( V_49 ) , sizeof( * V_49 ) ) ;
if ( V_16 ) {
if ( V_37 )
F_20 ( L_6
L_7 ,
V_31 , V_13 , V_34 , V_35 , V_16 , V_16 ,
V_49 -> V_12 . V_63 ,
V_49 -> V_12 . V_64 ) ;
goto V_65;
}
* V_36 = F_10 ( V_49 -> V_48 ) ;
V_65:
return V_16 ;
}
static unsigned long F_21 ( struct V_66 * V_67 , T_1 * V_36 ,
bool V_37 )
{
return F_15 ( F_22 ( V_67 ) ,
F_23 ( V_67 ) ,
F_24 ( V_67 ) ,
F_25 ( V_67 ) ,
V_36 ,
V_37 ) ;
}
static int F_26 ( struct V_66 * V_67 )
{
struct V_68 V_69 ;
unsigned V_31 ;
unsigned long V_15 ;
T_1 V_70 ;
if ( V_67 -> V_71 . type != V_67 -> V_72 -> type )
return - V_73 ;
if ( F_27 ( V_67 ) ||
F_28 ( V_67 ) ||
F_29 ( V_67 ) ) {
F_2 ( L_8 ,
V_67 -> V_71 . V_74 ,
F_27 ( V_67 ) ,
V_67 -> V_71 . V_75 ,
F_28 ( V_67 ) ,
V_67 -> V_71 . V_76 ,
F_29 ( V_67 ) ) ;
return - V_77 ;
}
if ( V_67 -> V_71 . V_78 ||
V_67 -> V_71 . V_79 ||
V_67 -> V_71 . V_80 ||
V_67 -> V_71 . V_81 ||
V_67 -> V_71 . V_82 ||
V_67 -> V_71 . V_83 )
return - V_77 ;
if ( F_30 ( V_67 ) )
return - V_84 ;
if ( F_23 ( V_67 ) % 8 ) {
F_2 ( L_9 ) ;
return - V_77 ;
}
V_31 = F_22 ( V_67 ) ;
if ( V_31 > 6 ) {
F_2 ( L_10 , V_31 ) ;
return - V_77 ;
}
V_15 = F_31 ( & V_69 ) ;
if ( V_15 ) {
F_2 ( L_11 , V_15 ) ;
return - V_28 ;
}
if ( ! V_69 . V_85 && ( F_14 ( V_31 ) ||
( F_25 ( V_67 ) != F_32 () ) ) ) {
F_2 ( L_12 ,
F_14 ( V_31 ) ,
F_25 ( V_67 ) ) ;
return - V_86 ;
}
if ( F_21 ( V_67 , & V_70 , false ) ) {
F_2 ( L_13 ) ;
return - V_28 ;
}
return 0 ;
}
static T_1 F_33 ( struct V_66 * V_67 )
{
unsigned long V_16 ;
T_1 V_70 ;
V_16 = F_21 ( V_67 , & V_70 , true ) ;
if ( V_16 )
return 0 ;
return V_70 ;
}
static void F_34 ( struct V_66 * V_67 )
{
T_10 V_87 ;
T_1 V_88 ;
V_88 = F_33 ( V_67 ) ;
V_87 = F_35 ( & V_67 -> V_89 . V_90 , V_88 ) ;
F_36 ( V_88 - V_87 , & V_67 -> V_14 ) ;
}
static void F_37 ( struct V_66 * V_67 , int V_91 )
{
if ( V_91 & V_92 )
F_38 ( & V_67 -> V_89 . V_90 , F_33 ( V_67 ) ) ;
}
static void F_39 ( struct V_66 * V_67 , int V_91 )
{
F_34 ( V_67 ) ;
}
static int F_40 ( struct V_66 * V_67 , int V_91 )
{
if ( V_91 & V_93 )
F_37 ( V_67 , V_91 ) ;
return 0 ;
}
static int F_41 ( void )
{
int V_94 ;
unsigned long V_15 ;
struct V_68 V_69 ;
if ( ! F_42 ( V_95 ) ) {
F_43 ( L_14 ) ;
return - V_96 ;
}
V_15 = F_31 ( & V_69 ) ;
if ( V_15 ) {
F_43 ( L_15 ,
V_15 ) ;
return - V_96 ;
}
V_23 = F_44 ( L_16 , 4096 , 4096 , 0 , NULL ) ;
if ( ! V_23 )
return - V_27 ;
V_97 . V_98 |= V_99 ;
V_94 = F_45 ( & V_97 , V_97 . V_100 , - 1 ) ;
if ( V_94 )
return V_94 ;
return 0 ;
}
