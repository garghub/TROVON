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
static int F_25 ( enum V_22 V_23 )
{
if ( V_23 == V_24 ) {
F_18 ( V_1 , V_25 , 1 ) ;
F_18 ( V_1 , V_26 , 2 ) ;
F_18 ( V_1 , V_27 , 2 ) ;
} else {
F_18 ( V_1 , V_25 , 2 ) ;
F_18 ( V_1 , V_26 , 3 ) ;
F_18 ( V_1 , V_27 , 3 ) ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
enum V_28 V_20 )
{
F_27 ( & V_2 -> V_29 ) ;
if ( V_20 == V_30 ) {
F_18 ( V_2 , V_31 , 1 ) ;
F_18 ( V_2 , V_31 , 3 ) ;
F_28 ( L_1 ) ;
} else {
F_18 ( V_2 , V_31 , 1 ) ;
F_18 ( V_2 , V_31 , 0 ) ;
F_28 ( L_2 ) ;
}
V_2 -> V_32 = V_20 ;
if ( V_2 -> V_33 >= 0 &&
! F_29 ( & V_2 -> V_29 ,
F_30 ( 200 ) ) )
F_31 ( L_3 ) ;
return 0 ;
}
static int F_32 ( enum V_22 V_23 ,
enum V_28 V_20 )
{
if ( V_23 == V_24 )
return 0 ;
return F_26 ( V_1 , V_20 ) ;
}
static int F_33 ( struct V_34 * V_35 )
{
if ( V_35 -> V_36 == V_37 )
return V_24 ;
else if ( V_35 -> V_36 == V_38 &&
V_35 -> V_39 == 0x0863 )
return V_24 ;
else
return V_40 ;
}
static enum V_22
F_34 ( struct V_1 * V_2 )
{
if ( F_17 ( V_2 , V_26 ) == 2 )
return V_24 ;
return V_40 ;
}
static inline void F_35 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_41 ,
V_42 ) ;
}
static inline void F_36 ( struct V_1 * V_2 )
{
F_18 ( V_2 , V_41 ,
V_43 ) ;
}
static inline T_1 F_37 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_44 ) ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_1 V_45 ;
V_45 = F_37 ( V_2 ) ;
F_18 ( V_2 , V_44 , V_45 ) ;
}
static void F_39 ( T_4 V_39 , T_2 V_46 , void * V_47 )
{
T_1 V_45 ;
struct V_48 * V_49 = (struct V_48 * ) V_47 ;
struct V_1 * V_2 = F_40 ( V_49 ) ;
V_45 = F_37 ( V_2 ) ;
F_35 ( V_2 ) ;
F_28 ( L_4 , V_45 ) ;
F_38 ( V_2 ) ;
F_36 ( V_2 ) ;
if ( V_45 & V_50 )
F_41 ( & V_2 -> V_29 ) ;
}
static int F_42 ( struct V_39 * V_51 )
{
struct V_48 * V_49 = F_43 ( V_51 ) ;
struct V_1 * V_2 = F_40 ( V_49 ) ;
V_2 -> V_52 = F_34 ( V_2 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_39 * V_51 )
{
struct V_48 * V_49 = F_43 ( V_51 ) ;
struct V_1 * V_2 = F_40 ( V_49 ) ;
F_36 ( V_2 ) ;
F_25 ( V_2 -> V_52 ) ;
if ( V_2 -> V_32 == V_53 )
F_26 ( V_2 , V_2 -> V_32 ) ;
return 0 ;
}
static struct V_34 * F_45 ( void )
{
struct V_34 * V_35 = NULL ;
while ( ( V_35 = F_46 ( V_54 << 8 , V_35 ) ) ) {
T_3 V_55 ;
F_47 ( V_35 , V_56 , & V_55 ) ;
if ( ! ( V_55 & V_57 ) )
continue;
return V_35 ;
}
return NULL ;
}
static int F_48 ( struct V_48 * V_49 , const struct V_58 * V_23 )
{
struct V_1 * V_2 ;
struct V_59 * V_60 ;
struct V_61 V_19 ;
struct V_14 * V_62 ;
T_1 V_63 , V_64 , V_65 ;
int V_66 = - V_67 ;
T_5 V_45 ;
unsigned long long V_33 ;
struct V_34 * V_35 = NULL ;
if ( V_1 )
return - V_68 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
F_50 ( V_49 , V_2 ) ;
V_60 = F_51 ( V_49 , V_71 , 0 ) ;
if ( ! V_60 ) {
F_52 ( L_5 ) ;
goto V_72;
}
V_2 -> V_4 = V_60 -> V_73 ;
V_2 -> V_74 = V_60 -> V_75 - V_60 -> V_73 ;
if ( V_2 -> V_74 < V_76 ) {
F_52 ( L_6 ,
V_2 -> V_74 , V_76 ) ;
goto V_72;
}
if ( ! F_53 ( V_2 -> V_4 , V_2 -> V_74 ,
L_7 ) ) {
F_52 ( L_8 ) ;
goto V_72;
}
V_63 = F_17 ( V_2 , V_77 ) ;
V_64 = F_17 ( V_2 , V_78 ) ;
V_65 = F_17 ( V_2 , V_79 ) ;
if ( V_63 == 0xff && V_64 == 0xff && V_65 == 0xff ) {
if ( F_21 ( V_2 ) ) {
T_2 V_80 ;
F_54 ( & V_2 -> V_11 ) ;
V_2 -> V_13 = true ;
V_80 = F_19 ( V_2 ,
V_77 ) ;
V_63 = ( V_80 >> 24 ) & 0xff ;
V_64 = ( V_80 >> 16 ) & 0xff ;
V_65 = ( V_80 >> 8 ) & 0xff ;
} else {
F_55 ( L_9 ) ;
V_66 = - V_81 ;
goto V_82;
}
}
F_55 ( L_10 , V_63 , V_64 ,
V_65 , ( V_2 -> V_13 ? L_11 : L_12 ) ) ;
V_35 = F_45 () ;
if ( V_35 && F_56 ( V_35 ,
V_83 | V_84 ) ) {
F_52 ( L_13 ,
F_57 ( V_35 ) ) ;
V_66 = - V_68 ;
goto V_82;
} else if ( V_35 )
F_55 ( L_14 , F_57 ( V_35 ) ) ;
V_2 -> V_35 = V_35 ;
memset ( & V_19 , 0 , sizeof( V_19 ) ) ;
V_19 . type = V_85 ;
V_19 . V_86 = F_19 ( V_2 , V_87 ) ;
if ( F_58 ( V_19 . V_86 > V_88 ) )
V_19 . V_86 = V_88 ;
V_62 = F_59 ( L_15 , & V_49 -> V_51 ,
V_2 , & V_89 , & V_19 ) ;
if ( F_60 ( V_62 ) ) {
V_66 = F_61 ( V_62 ) ;
goto V_82;
}
V_2 -> V_62 = V_62 ;
V_62 -> V_19 . V_18 = F_22 ( V_62 ) ;
F_62 ( V_62 ) ;
F_63 ( V_90 ) ;
F_64 () ;
V_2 -> V_32 = V_30 ;
V_2 -> V_91 = F_65 ( & V_49 -> V_51 ) ;
if ( ! V_2 -> V_91 ) {
F_52 ( L_16 ,
F_66 ( & V_49 -> V_51 ) ) ;
V_66 = - V_81 ;
goto V_92;
}
V_45 = F_67 ( V_2 -> V_91 , L_17 , NULL , & V_33 ) ;
if ( F_68 ( V_45 ) ) {
V_2 -> V_33 = ( int ) V_33 ;
V_45 = F_69 ( V_2 -> V_91 ,
V_93 ,
& F_39 , V_49 ) ;
if ( F_70 ( V_45 ) ) {
F_52 ( L_18 ,
F_71 ( V_45 ) ) ;
V_66 = - V_81 ;
goto V_92;
}
V_45 = F_72 ( NULL , V_2 -> V_33 ) ;
if ( F_70 ( V_45 ) ) {
F_52 ( L_19 ,
F_71 ( V_45 ) ) ;
goto V_94;
}
} else {
F_31 ( L_20 ) ;
V_2 -> V_33 = - 1 ;
}
if ( F_73 ( & V_95 ) ) {
V_66 = - V_81 ;
goto V_96;
}
F_74 ( & V_2 -> V_29 ) ;
V_1 = V_2 ;
F_36 ( V_2 ) ;
return 0 ;
V_96:
if ( V_2 -> V_33 >= 0 )
F_75 ( NULL , V_2 -> V_33 ) ;
V_94:
if ( V_2 -> V_33 >= 0 )
F_76 ( V_2 -> V_91 ,
V_93 ,
& F_39 ) ;
V_92:
F_77 ( V_62 ) ;
V_82:
if ( V_2 -> V_35 )
F_78 ( V_2 -> V_35 ,
V_83 | V_84 ) ;
F_79 ( V_35 ) ;
F_80 ( V_2 -> V_4 , V_2 -> V_74 ) ;
V_72:
F_81 ( V_2 ) ;
return V_66 ;
}
static void F_82 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_40 ( V_49 ) ;
F_83 () ;
F_35 ( V_2 ) ;
if ( V_2 -> V_33 >= 0 ) {
F_75 ( NULL , V_2 -> V_33 ) ;
F_76 ( V_2 -> V_91 ,
V_93 ,
& F_39 ) ;
}
if ( V_2 -> V_35 ) {
F_78 ( V_2 -> V_35 ,
V_83 | V_84 ) ;
F_79 ( V_2 -> V_35 ) ;
}
F_77 ( V_2 -> V_62 ) ;
F_80 ( V_2 -> V_4 , V_2 -> V_74 ) ;
V_1 = NULL ;
F_81 ( V_2 ) ;
F_84 () ;
F_85 () ;
}
