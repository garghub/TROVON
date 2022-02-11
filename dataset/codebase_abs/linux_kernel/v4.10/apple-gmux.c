static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static T_2 F_5 ( struct V_1 * V_2 , int V_3 )
{
return F_6 ( V_2 -> V_4 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , int V_3 ,
T_2 V_5 )
{
int V_6 ;
T_1 V_7 ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_7 = ( V_5 >> ( V_6 * 8 ) ) & 0xff ;
F_4 ( V_7 , V_2 -> V_4 + V_3 + V_6 ) ;
}
}
static int F_8 ( struct V_1 * V_2 )
{
int V_6 = 200 ;
T_1 V_8 = F_2 ( V_2 -> V_4 + V_9 ) ;
while ( V_6 && ( V_8 & 0x01 ) ) {
F_2 ( V_2 -> V_4 + V_10 ) ;
V_8 = F_2 ( V_2 -> V_4 + V_9 ) ;
F_9 ( 100 ) ;
V_6 -- ;
}
return ! ! V_6 ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_6 = 200 ;
T_1 V_8 = F_2 ( V_2 -> V_4 + V_9 ) ;
while ( V_6 && ! ( V_8 & 0x01 ) ) {
V_8 = F_2 ( V_2 -> V_4 + V_9 ) ;
F_9 ( 100 ) ;
V_6 -- ;
}
if ( V_8 & 0x01 )
F_2 ( V_2 -> V_4 + V_10 ) ;
return ! ! V_6 ;
}
static T_1 F_11 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_5 ;
F_12 ( & V_2 -> V_11 ) ;
F_8 ( V_2 ) ;
F_4 ( ( V_3 & 0xff ) , V_2 -> V_4 + V_10 ) ;
F_10 ( V_2 ) ;
V_5 = F_2 ( V_2 -> V_4 + V_12 ) ;
F_13 ( & V_2 -> V_11 ) ;
return V_5 ;
}
static void F_14 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_12 ( & V_2 -> V_11 ) ;
F_4 ( V_5 , V_2 -> V_4 + V_12 ) ;
F_8 ( V_2 ) ;
F_4 ( V_3 & 0xff , V_2 -> V_4 + V_9 ) ;
F_10 ( V_2 ) ;
F_13 ( & V_2 -> V_11 ) ;
}
static T_2 F_15 ( struct V_1 * V_2 , int V_3 )
{
T_2 V_5 ;
F_12 ( & V_2 -> V_11 ) ;
F_8 ( V_2 ) ;
F_4 ( ( V_3 & 0xff ) , V_2 -> V_4 + V_10 ) ;
F_10 ( V_2 ) ;
V_5 = F_6 ( V_2 -> V_4 + V_12 ) ;
F_13 ( & V_2 -> V_11 ) ;
return V_5 ;
}
static void F_16 ( struct V_1 * V_2 , int V_3 ,
T_2 V_5 )
{
int V_6 ;
T_1 V_7 ;
F_12 ( & V_2 -> V_11 ) ;
for ( V_6 = 0 ; V_6 < 4 ; V_6 ++ ) {
V_7 = ( V_5 >> ( V_6 * 8 ) ) & 0xff ;
F_4 ( V_7 , V_2 -> V_4 + V_12 + V_6 ) ;
}
F_8 ( V_2 ) ;
F_4 ( V_3 & 0xff , V_2 -> V_4 + V_9 ) ;
F_10 ( V_2 ) ;
F_13 ( & V_2 -> V_11 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_13 )
return F_11 ( V_2 , V_3 ) ;
else
return F_1 ( V_2 , V_3 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_3 , T_1 V_5 )
{
if ( V_2 -> V_13 )
F_14 ( V_2 , V_3 , V_5 ) ;
else
F_3 ( V_2 , V_3 , V_5 ) ;
}
static T_2 F_19 ( struct V_1 * V_2 , int V_3 )
{
if ( V_2 -> V_13 )
return F_15 ( V_2 , V_3 ) ;
else
return F_5 ( V_2 , V_3 ) ;
}
static void F_20 ( struct V_1 * V_2 , int V_3 ,
T_2 V_5 )
{
if ( V_2 -> V_13 )
F_16 ( V_2 , V_3 , V_5 ) ;
else
F_7 ( V_2 , V_3 , V_5 ) ;
}
static bool F_21 ( struct V_1 * V_2 )
{
T_3 V_5 ;
F_4 ( 0xaa , V_2 -> V_4 + 0xcc ) ;
F_4 ( 0x55 , V_2 -> V_4 + 0xcd ) ;
F_4 ( 0x00 , V_2 -> V_4 + 0xce ) ;
V_5 = F_2 ( V_2 -> V_4 + 0xcc ) |
( F_2 ( V_2 -> V_4 + 0xcd ) << 8 ) ;
if ( V_5 == 0x55aa )
return true ;
return false ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
return F_19 ( V_2 , V_16 ) &
V_17 ;
}
static int F_24 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
T_2 V_18 = V_15 -> V_19 . V_18 ;
if ( V_15 -> V_19 . V_20 & V_21 )
return 0 ;
F_20 ( V_2 , V_16 , V_18 ) ;
return 0 ;
}
static void F_25 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 , V_22 ) == 1 )
V_2 -> V_23 = V_24 ;
else
V_2 -> V_23 = V_25 ;
if ( F_17 ( V_2 , V_26 ) == 2 )
V_2 -> V_27 = V_24 ;
else
V_2 -> V_27 = V_25 ;
if ( F_17 ( V_2 , V_28 ) == 2 )
V_2 -> V_29 = V_24 ;
else
V_2 -> V_29 = V_25 ;
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 == V_24 )
F_18 ( V_2 , V_22 , 1 ) ;
else
F_18 ( V_2 , V_22 , 2 ) ;
if ( V_2 -> V_27 == V_24 )
F_18 ( V_2 , V_26 , 2 ) ;
else
F_18 ( V_2 , V_26 , 3 ) ;
if ( V_2 -> V_29 == V_24 )
F_18 ( V_2 , V_28 , 2 ) ;
else
F_18 ( V_2 , V_28 , 3 ) ;
}
static int F_27 ( enum V_30 V_31 )
{
V_1 -> V_23 = V_31 ;
V_1 -> V_27 = V_31 ;
V_1 -> V_29 = V_31 ;
F_26 ( V_1 ) ;
return 0 ;
}
static int F_28 ( enum V_30 V_31 )
{
enum V_30 V_32 =
V_1 -> V_23 ;
if ( V_31 == V_32 )
return V_31 ;
F_29 ( L_1 , V_32 , V_31 ) ;
V_1 -> V_23 = V_31 ;
if ( V_31 == V_24 )
F_18 ( V_1 , V_22 , 1 ) ;
else
F_18 ( V_1 , V_22 , 2 ) ;
return V_32 ;
}
static int F_30 ( struct V_1 * V_2 ,
enum V_33 V_20 )
{
F_31 ( & V_2 -> V_34 ) ;
if ( V_20 == V_35 ) {
F_18 ( V_2 , V_36 , 1 ) ;
F_18 ( V_2 , V_36 , 3 ) ;
F_29 ( L_2 ) ;
} else {
F_18 ( V_2 , V_36 , 1 ) ;
F_18 ( V_2 , V_36 , 0 ) ;
F_29 ( L_3 ) ;
}
V_2 -> V_37 = V_20 ;
if ( V_2 -> V_38 >= 0 &&
! F_32 ( & V_2 -> V_34 ,
F_33 ( 200 ) ) )
F_34 ( L_4 ) ;
return 0 ;
}
static int F_35 ( enum V_30 V_31 ,
enum V_33 V_20 )
{
if ( V_31 == V_24 )
return 0 ;
return F_30 ( V_1 , V_20 ) ;
}
static int F_36 ( struct V_39 * V_40 )
{
if ( V_40 -> V_41 == V_42 )
return V_24 ;
else if ( V_40 -> V_41 == V_43 &&
V_40 -> V_44 == 0x0863 )
return V_24 ;
else
return V_25 ;
}
static inline void F_37 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_45 ,
V_46 ) ;
}
static inline void F_38 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_45 ,
V_47 ) ;
}
static inline T_1 F_39 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_48 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
T_1 V_49 ;
V_49 = F_39 ( V_2 ) ;
F_18 ( V_2 , V_48 , V_49 ) ;
}
static void F_41 ( T_4 V_44 , T_2 V_50 , void * V_51 )
{
T_1 V_49 ;
struct V_52 * V_53 = (struct V_52 * ) V_51 ;
struct V_1 * V_2 = F_42 ( V_53 ) ;
V_49 = F_39 ( V_2 ) ;
F_37 ( V_2 ) ;
F_29 ( L_5 , V_49 ) ;
F_40 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( V_49 & V_54 )
F_43 ( & V_2 -> V_34 ) ;
}
static int F_44 ( struct V_44 * V_55 )
{
struct V_52 * V_53 = F_45 ( V_55 ) ;
struct V_1 * V_2 = F_42 ( V_53 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_46 ( struct V_44 * V_55 )
{
struct V_52 * V_53 = F_45 ( V_55 ) ;
struct V_1 * V_2 = F_42 ( V_53 ) ;
F_38 ( V_2 ) ;
F_26 ( V_2 ) ;
if ( V_2 -> V_37 == V_56 )
F_30 ( V_2 , V_2 -> V_37 ) ;
return 0 ;
}
static struct V_39 * F_47 ( void )
{
struct V_39 * V_40 = NULL ;
while ( ( V_40 = F_48 ( V_57 << 8 , V_40 ) ) ) {
T_3 V_58 ;
F_49 ( V_40 , V_59 , & V_58 ) ;
if ( ! ( V_58 & V_60 ) )
continue;
return V_40 ;
}
return NULL ;
}
static int F_50 ( struct V_52 * V_53 , const struct V_61 * V_31 )
{
struct V_1 * V_2 ;
struct V_62 * V_63 ;
struct V_64 V_19 ;
struct V_14 * V_65 ;
T_1 V_66 , V_67 , V_68 ;
int V_69 = - V_70 ;
T_5 V_49 ;
unsigned long long V_38 ;
struct V_39 * V_40 = NULL ;
if ( V_1 )
return - V_71 ;
V_2 = F_51 ( sizeof( * V_2 ) , V_72 ) ;
if ( ! V_2 )
return - V_73 ;
F_52 ( V_53 , V_2 ) ;
V_63 = F_53 ( V_53 , V_74 , 0 ) ;
if ( ! V_63 ) {
F_54 ( L_6 ) ;
goto V_75;
}
V_2 -> V_4 = V_63 -> V_76 ;
V_2 -> V_77 = V_63 -> V_78 - V_63 -> V_76 ;
if ( V_2 -> V_77 < V_79 ) {
F_54 ( L_7 ,
V_2 -> V_77 , V_79 ) ;
goto V_75;
}
if ( ! F_55 ( V_2 -> V_4 , V_2 -> V_77 ,
L_8 ) ) {
F_54 ( L_9 ) ;
goto V_75;
}
V_66 = F_17 ( V_2 , V_80 ) ;
V_67 = F_17 ( V_2 , V_81 ) ;
V_68 = F_17 ( V_2 , V_82 ) ;
if ( V_66 == 0xff && V_67 == 0xff && V_68 == 0xff ) {
if ( F_21 ( V_2 ) ) {
T_2 V_83 ;
F_56 ( & V_2 -> V_11 ) ;
V_2 -> V_13 = true ;
V_83 = F_19 ( V_2 ,
V_80 ) ;
V_66 = ( V_83 >> 24 ) & 0xff ;
V_67 = ( V_83 >> 16 ) & 0xff ;
V_68 = ( V_83 >> 8 ) & 0xff ;
} else {
F_57 ( L_10 ) ;
V_69 = - V_84 ;
goto V_85;
}
}
F_57 ( L_11 , V_66 , V_67 ,
V_68 , ( V_2 -> V_13 ? L_12 : L_13 ) ) ;
V_40 = F_47 () ;
if ( V_40 && F_58 ( V_40 ,
V_86 | V_87 ) ) {
F_54 ( L_14 ,
F_59 ( V_40 ) ) ;
V_69 = - V_71 ;
goto V_85;
} else if ( V_40 )
F_57 ( L_15 , F_59 ( V_40 ) ) ;
V_2 -> V_40 = V_40 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . type = V_88 ;
V_19 . V_89 = F_19 ( V_2 , V_90 ) ;
if ( F_60 ( V_19 . V_89 > V_91 ) )
V_19 . V_89 = V_91 ;
V_65 = F_61 ( L_16 , & V_53 -> V_55 ,
V_2 , & V_92 , & V_19 ) ;
if ( F_62 ( V_65 ) ) {
V_69 = F_63 ( V_65 ) ;
goto V_85;
}
V_2 -> V_65 = V_65 ;
V_65 -> V_19 . V_18 = F_22 ( V_65 ) ;
F_64 ( V_65 ) ;
F_65 ( V_93 ) ;
F_66 () ;
V_2 -> V_37 = V_35 ;
V_2 -> V_94 = F_67 ( & V_53 -> V_55 ) ;
if ( ! V_2 -> V_94 ) {
F_54 ( L_17 ,
F_68 ( & V_53 -> V_55 ) ) ;
V_69 = - V_84 ;
goto V_95;
}
V_49 = F_69 ( V_2 -> V_94 , L_18 , NULL , & V_38 ) ;
if ( F_70 ( V_49 ) ) {
V_2 -> V_38 = ( int ) V_38 ;
V_49 = F_71 ( V_2 -> V_94 ,
V_96 ,
& F_41 , V_53 ) ;
if ( F_72 ( V_49 ) ) {
F_54 ( L_19 ,
F_73 ( V_49 ) ) ;
V_69 = - V_84 ;
goto V_95;
}
V_49 = F_74 ( NULL , V_2 -> V_38 ) ;
if ( F_72 ( V_49 ) ) {
F_54 ( L_20 ,
F_73 ( V_49 ) ) ;
goto V_97;
}
} else {
F_34 ( L_21 ) ;
V_2 -> V_38 = - 1 ;
}
V_1 = V_2 ;
F_75 ( & V_2 -> V_34 ) ;
F_38 ( V_2 ) ;
F_25 ( V_2 ) ;
if ( V_2 -> V_13 )
V_69 = F_76 ( & V_98 ,
V_99 ) ;
else
V_69 = F_76 ( & V_100 ,
V_101 ) ;
if ( V_69 ) {
F_54 ( L_22 ) ;
goto V_102;
}
return 0 ;
V_102:
F_37 ( V_2 ) ;
V_1 = NULL ;
if ( V_2 -> V_38 >= 0 )
F_77 ( NULL , V_2 -> V_38 ) ;
V_97:
if ( V_2 -> V_38 >= 0 )
F_78 ( V_2 -> V_94 ,
V_96 ,
& F_41 ) ;
V_95:
F_79 ( V_65 ) ;
V_85:
if ( V_2 -> V_40 )
F_80 ( V_2 -> V_40 ,
V_86 | V_87 ) ;
F_81 ( V_40 ) ;
F_82 ( V_2 -> V_4 , V_2 -> V_77 ) ;
V_75:
F_83 ( V_2 ) ;
return V_69 ;
}
static void F_84 ( struct V_52 * V_53 )
{
struct V_1 * V_2 = F_42 ( V_53 ) ;
F_85 () ;
F_37 ( V_2 ) ;
if ( V_2 -> V_38 >= 0 ) {
F_77 ( NULL , V_2 -> V_38 ) ;
F_78 ( V_2 -> V_94 ,
V_96 ,
& F_41 ) ;
}
if ( V_2 -> V_40 ) {
F_80 ( V_2 -> V_40 ,
V_86 | V_87 ) ;
F_81 ( V_2 -> V_40 ) ;
}
F_79 ( V_2 -> V_65 ) ;
F_82 ( V_2 -> V_4 , V_2 -> V_77 ) ;
V_1 = NULL ;
F_83 ( V_2 ) ;
F_86 () ;
F_87 () ;
}
