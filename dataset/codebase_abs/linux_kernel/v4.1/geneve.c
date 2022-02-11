static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) ( F_2 ( V_3 ) + 1 ) ;
}
static struct V_4 * F_3 ( struct V_5 * V_5 ,
T_1 V_6 , T_2 V_7 )
{
struct V_8 * V_9 = F_4 ( V_5 , V_10 ) ;
struct V_4 * V_11 ;
F_5 (gs, &gn->sock_list, list) {
if ( F_6 ( V_11 -> V_12 -> V_13 ) -> V_14 == V_7 &&
F_6 ( V_11 -> V_12 -> V_13 ) -> V_13 . V_15 == V_6 )
return V_11 ;
}
return NULL ;
}
static void F_7 ( struct V_1 * V_16 ,
T_2 V_17 , T_3 V_18 [ 3 ] ,
T_3 V_19 , T_3 * V_20 )
{
V_16 -> V_21 = V_22 ;
V_16 -> V_23 = V_19 / 4 ;
V_16 -> V_24 = ! ! ( V_17 & V_25 ) ;
V_16 -> V_26 = ! ! ( V_17 & V_27 ) ;
V_16 -> V_28 = 0 ;
memcpy ( V_16 -> V_18 , V_18 , 3 ) ;
V_16 -> V_29 = F_8 ( V_30 ) ;
V_16 -> V_31 = 0 ;
memcpy ( V_16 -> V_20 , V_20 , V_19 ) ;
}
int F_9 ( struct V_4 * V_11 , struct V_32 * V_33 ,
struct V_2 * V_3 , T_4 V_34 , T_4 V_35 , T_5 V_36 ,
T_5 V_37 , T_2 V_38 , T_2 V_39 , T_2 V_40 ,
T_2 V_17 , T_3 V_18 [ 3 ] , T_3 V_23 , T_3 * V_41 ,
bool V_42 , bool V_43 )
{
struct V_1 * V_44 ;
int V_45 ;
int V_46 ;
V_45 = F_10 ( V_33 -> V_35 . V_47 ) + V_33 -> V_35 . V_48
+ V_49 + V_23 + sizeof( struct V_50 )
+ ( F_11 ( V_3 ) ? V_51 : 0 ) ;
V_46 = F_12 ( V_3 , V_45 ) ;
if ( F_13 ( V_46 ) ) {
F_14 ( V_3 ) ;
return V_46 ;
}
V_3 = F_15 ( V_3 ) ;
if ( F_13 ( ! V_3 ) )
return - V_52 ;
V_3 = F_16 ( V_3 , V_42 ) ;
if ( F_17 ( V_3 ) )
return F_18 ( V_3 ) ;
V_44 = (struct V_1 * ) F_19 ( V_3 , sizeof( * V_44 ) + V_23 ) ;
F_7 ( V_44 , V_17 , V_18 , V_23 , V_41 ) ;
F_20 ( V_3 , F_8 ( V_30 ) ) ;
return F_21 ( V_33 , V_11 -> V_12 -> V_13 , V_3 , V_34 , V_35 ,
V_36 , V_37 , V_38 , V_39 , V_40 , V_43 ,
! V_42 ) ;
}
static int F_22 ( struct V_1 * V_53 )
{
return sizeof( * V_53 ) + V_53 -> V_23 * 4 ;
}
static struct V_2 * * F_23 ( struct V_2 * * V_54 ,
struct V_2 * V_3 ,
struct V_55 * V_56 )
{
struct V_2 * V_57 , * * V_58 = NULL ;
struct V_1 * V_53 , * V_59 ;
unsigned int V_60 , V_61 , V_62 ;
const struct V_63 * V_64 ;
T_2 type ;
int V_65 = 1 ;
V_62 = F_24 ( V_3 ) ;
V_60 = V_62 + sizeof( * V_53 ) ;
V_53 = F_25 ( V_3 , V_62 ) ;
if ( F_26 ( V_3 , V_60 ) ) {
V_53 = F_27 ( V_3 , V_60 , V_62 ) ;
if ( F_13 ( ! V_53 ) )
goto V_66;
}
if ( V_53 -> V_21 != V_22 || V_53 -> V_24 )
goto V_66;
V_61 = F_22 ( V_53 ) ;
V_60 = V_62 + V_61 ;
if ( F_26 ( V_3 , V_60 ) ) {
V_53 = F_27 ( V_3 , V_60 , V_62 ) ;
if ( F_13 ( ! V_53 ) )
goto V_66;
}
V_65 = 0 ;
for ( V_57 = * V_54 ; V_57 ; V_57 = V_57 -> V_67 ) {
if ( ! F_28 ( V_57 ) -> V_68 )
continue;
V_59 = (struct V_1 * ) ( V_57 -> V_69 + V_62 ) ;
if ( V_53 -> V_23 != V_59 -> V_23 ||
memcmp ( V_53 , V_59 , V_61 ) ) {
F_28 ( V_57 ) -> V_68 = 0 ;
continue;
}
}
type = V_53 -> V_29 ;
F_29 () ;
V_64 = F_30 ( type ) ;
if ( ! V_64 ) {
V_65 = 1 ;
goto V_70;
}
F_31 ( V_3 , V_61 ) ;
F_32 ( V_3 , V_53 , V_61 ) ;
V_58 = V_64 -> V_71 . V_72 ( V_54 , V_3 ) ;
V_70:
F_33 () ;
V_66:
F_28 ( V_3 ) -> V_65 |= V_65 ;
return V_58 ;
}
static int F_34 ( struct V_2 * V_3 , int V_73 ,
struct V_55 * V_56 )
{
struct V_1 * V_53 ;
struct V_63 * V_64 ;
T_2 type ;
int V_61 ;
int V_46 = - V_74 ;
F_35 ( V_3 , V_73 ) ;
V_53 = (struct V_1 * ) ( V_3 -> V_69 + V_73 ) ;
V_61 = F_22 ( V_53 ) ;
type = V_53 -> V_29 ;
F_29 () ;
V_64 = F_36 ( type ) ;
if ( V_64 )
V_46 = V_64 -> V_71 . V_75 ( V_3 , V_73 + V_61 ) ;
F_33 () ;
return V_46 ;
}
static void F_37 ( struct V_4 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_12 -> V_13 ;
T_1 V_76 = V_13 -> V_15 ;
int V_46 ;
if ( V_76 == V_77 ) {
V_46 = F_38 ( & V_11 -> V_78 ) ;
if ( V_46 )
F_39 ( L_1 ,
V_46 ) ;
}
}
static void F_40 ( struct V_4 * V_11 )
{
struct V_12 * V_13 = V_11 -> V_12 -> V_13 ;
T_1 V_76 = V_13 -> V_15 ;
if ( V_76 == V_77 )
F_41 ( & V_11 -> V_78 ) ;
}
static int F_42 ( struct V_12 * V_13 , struct V_2 * V_3 )
{
struct V_1 * V_16 ;
struct V_4 * V_11 ;
int V_79 ;
if ( F_13 ( ! F_43 ( V_3 , V_49 ) ) )
goto error;
V_16 = F_1 ( V_3 ) ;
if ( F_13 ( V_16 -> V_21 != V_22 ) )
goto error;
if ( F_13 ( V_16 -> V_29 != F_8 ( V_30 ) ) )
goto error;
V_79 = V_16 -> V_23 * 4 ;
if ( F_44 ( V_3 , V_49 + V_79 ,
F_8 ( V_30 ) ) )
goto V_80;
V_11 = F_45 ( V_13 ) ;
if ( ! V_11 )
goto V_80;
V_11 -> V_81 ( V_11 , V_3 ) ;
return 0 ;
V_80:
F_14 ( V_3 ) ;
return 0 ;
error:
return 1 ;
}
static struct V_82 * F_46 ( struct V_5 * V_5 , bool V_83 ,
T_2 V_7 )
{
struct V_82 * V_12 ;
struct V_84 V_85 ;
int V_46 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
if ( V_83 ) {
V_85 . V_6 = V_86 ;
} else {
V_85 . V_6 = V_77 ;
V_85 . V_87 . V_88 = F_47 ( V_89 ) ;
}
V_85 . V_90 = V_7 ;
V_46 = F_48 ( V_5 , & V_85 , & V_12 ) ;
if ( V_46 < 0 )
return F_49 ( V_46 ) ;
return V_12 ;
}
static struct V_4 * F_50 ( struct V_5 * V_5 , T_2 V_7 ,
T_6 * V_81 , void * V_69 ,
bool V_83 )
{
struct V_8 * V_9 = F_4 ( V_5 , V_10 ) ;
struct V_4 * V_11 ;
struct V_82 * V_12 ;
struct V_91 V_92 ;
V_11 = F_51 ( sizeof( * V_11 ) , V_93 ) ;
if ( ! V_11 )
return F_49 ( - V_52 ) ;
V_12 = F_46 ( V_5 , V_83 , V_7 ) ;
if ( F_17 ( V_12 ) ) {
F_52 ( V_11 ) ;
return F_53 ( V_12 ) ;
}
V_11 -> V_12 = V_12 ;
V_11 -> V_94 = 1 ;
V_11 -> V_81 = V_81 ;
V_11 -> V_95 = V_69 ;
V_11 -> V_78 . V_7 = V_7 ;
V_11 -> V_78 . V_71 . V_72 = F_23 ;
V_11 -> V_78 . V_71 . V_75 = F_34 ;
F_37 ( V_11 ) ;
V_92 . V_96 = V_11 ;
V_92 . V_97 = 1 ;
V_92 . V_98 = F_42 ;
V_92 . V_99 = NULL ;
F_54 ( V_5 , V_12 , & V_92 ) ;
F_55 ( & V_11 -> V_100 , & V_9 -> V_101 ) ;
return V_11 ;
}
struct V_4 * F_56 ( struct V_5 * V_5 , T_2 V_7 ,
T_6 * V_81 , void * V_69 ,
bool V_102 , bool V_83 )
{
struct V_4 * V_11 ;
F_57 ( & V_103 ) ;
V_11 = F_3 ( V_5 , V_83 ? V_86 : V_77 , V_7 ) ;
if ( V_11 ) {
if ( ! V_102 && V_11 -> V_81 == V_81 )
V_11 -> V_94 ++ ;
else
V_11 = F_49 ( - V_104 ) ;
} else {
V_11 = F_50 ( V_5 , V_7 , V_81 , V_69 , V_83 ) ;
}
F_58 ( & V_103 ) ;
return V_11 ;
}
void F_59 ( struct V_4 * V_11 )
{
F_57 ( & V_103 ) ;
if ( -- V_11 -> V_94 )
goto V_105;
F_60 ( & V_11 -> V_100 ) ;
F_40 ( V_11 ) ;
F_61 ( V_11 -> V_12 ) ;
F_62 ( V_11 , V_106 ) ;
V_105:
F_58 ( & V_103 ) ;
}
static T_7 int F_63 ( struct V_5 * V_5 )
{
struct V_8 * V_9 = F_4 ( V_5 , V_10 ) ;
F_64 ( & V_9 -> V_101 ) ;
return 0 ;
}
static int T_8 F_65 ( void )
{
int V_107 ;
V_107 = F_66 ( & V_108 ) ;
if ( V_107 )
return V_107 ;
F_67 ( L_2 ) ;
return 0 ;
}
static void T_9 F_68 ( void )
{
F_69 ( & V_108 ) ;
}
