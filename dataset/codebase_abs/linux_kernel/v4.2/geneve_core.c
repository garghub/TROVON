static struct V_1 * F_1 ( struct V_2 * V_2 ,
T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 , V_7 ) ;
struct V_1 * V_8 ;
F_3 (gs, &gn->sock_list, list) {
if ( F_4 ( V_8 -> V_9 -> V_10 ) -> V_11 == V_4 &&
F_4 ( V_8 -> V_9 -> V_10 ) -> V_10 . V_12 == V_3 )
return V_8 ;
}
return NULL ;
}
static void F_5 ( struct V_13 * V_14 ,
T_2 V_15 , T_3 V_16 [ 3 ] ,
T_3 V_17 , T_3 * V_18 )
{
V_14 -> V_19 = V_20 ;
V_14 -> V_21 = V_17 / 4 ;
V_14 -> V_22 = ! ! ( V_15 & V_23 ) ;
V_14 -> V_24 = ! ! ( V_15 & V_25 ) ;
V_14 -> V_26 = 0 ;
memcpy ( V_14 -> V_16 , V_16 , 3 ) ;
V_14 -> V_27 = F_6 ( V_28 ) ;
V_14 -> V_29 = 0 ;
memcpy ( V_14 -> V_18 , V_18 , V_17 ) ;
}
int F_7 ( struct V_1 * V_8 , struct V_30 * V_31 ,
struct V_32 * V_33 , T_4 V_34 , T_4 V_35 , T_5 V_36 ,
T_5 V_37 , T_2 V_38 , T_2 V_39 , T_2 V_40 ,
T_2 V_15 , T_3 V_16 [ 3 ] , T_3 V_21 , T_3 * V_41 ,
bool V_42 , bool V_43 )
{
struct V_13 * V_44 ;
int V_45 ;
int V_46 ;
V_45 = F_8 ( V_31 -> V_35 . V_47 ) + V_31 -> V_35 . V_48
+ V_49 + V_21 + sizeof( struct V_50 )
+ ( F_9 ( V_33 ) ? V_51 : 0 ) ;
V_46 = F_10 ( V_33 , V_45 ) ;
if ( F_11 ( V_46 ) ) {
F_12 ( V_33 ) ;
return V_46 ;
}
V_33 = F_13 ( V_33 ) ;
if ( F_11 ( ! V_33 ) )
return - V_52 ;
V_33 = F_14 ( V_33 , V_42 ) ;
if ( F_15 ( V_33 ) )
return F_16 ( V_33 ) ;
V_44 = (struct V_13 * ) F_17 ( V_33 , sizeof( * V_44 ) + V_21 ) ;
F_5 ( V_44 , V_15 , V_16 , V_21 , V_41 ) ;
F_18 ( V_33 , F_6 ( V_28 ) ) ;
return F_19 ( V_31 , V_8 -> V_9 -> V_10 , V_33 , V_34 , V_35 ,
V_36 , V_37 , V_38 , V_39 , V_40 , V_43 ,
! V_42 ) ;
}
static int F_20 ( struct V_13 * V_53 )
{
return sizeof( * V_53 ) + V_53 -> V_21 * 4 ;
}
static struct V_32 * * F_21 ( struct V_32 * * V_54 ,
struct V_32 * V_33 ,
struct V_55 * V_56 )
{
struct V_32 * V_57 , * * V_58 = NULL ;
struct V_13 * V_53 , * V_59 ;
unsigned int V_60 , V_61 , V_62 ;
const struct V_63 * V_64 ;
T_2 type ;
int V_65 = 1 ;
V_62 = F_22 ( V_33 ) ;
V_60 = V_62 + sizeof( * V_53 ) ;
V_53 = F_23 ( V_33 , V_62 ) ;
if ( F_24 ( V_33 , V_60 ) ) {
V_53 = F_25 ( V_33 , V_60 , V_62 ) ;
if ( F_11 ( ! V_53 ) )
goto V_66;
}
if ( V_53 -> V_19 != V_20 || V_53 -> V_22 )
goto V_66;
V_61 = F_20 ( V_53 ) ;
V_60 = V_62 + V_61 ;
if ( F_24 ( V_33 , V_60 ) ) {
V_53 = F_25 ( V_33 , V_60 , V_62 ) ;
if ( F_11 ( ! V_53 ) )
goto V_66;
}
V_65 = 0 ;
for ( V_57 = * V_54 ; V_57 ; V_57 = V_57 -> V_67 ) {
if ( ! F_26 ( V_57 ) -> V_68 )
continue;
V_59 = (struct V_13 * ) ( V_57 -> V_69 + V_62 ) ;
if ( V_53 -> V_21 != V_59 -> V_21 ||
memcmp ( V_53 , V_59 , V_61 ) ) {
F_26 ( V_57 ) -> V_68 = 0 ;
continue;
}
}
type = V_53 -> V_27 ;
F_27 () ;
V_64 = F_28 ( type ) ;
if ( ! V_64 ) {
V_65 = 1 ;
goto V_70;
}
F_29 ( V_33 , V_61 ) ;
F_30 ( V_33 , V_53 , V_61 ) ;
V_58 = V_64 -> V_71 . V_72 ( V_54 , V_33 ) ;
V_70:
F_31 () ;
V_66:
F_26 ( V_33 ) -> V_65 |= V_65 ;
return V_58 ;
}
static int F_32 ( struct V_32 * V_33 , int V_73 ,
struct V_55 * V_56 )
{
struct V_13 * V_53 ;
struct V_63 * V_64 ;
T_2 type ;
int V_61 ;
int V_46 = - V_74 ;
F_33 ( V_33 , V_73 ) ;
V_53 = (struct V_13 * ) ( V_33 -> V_69 + V_73 ) ;
V_61 = F_20 ( V_53 ) ;
type = V_53 -> V_27 ;
F_27 () ;
V_64 = F_34 ( type ) ;
if ( V_64 )
V_46 = V_64 -> V_71 . V_75 ( V_33 , V_73 + V_61 ) ;
F_31 () ;
return V_46 ;
}
static void F_35 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 -> V_10 ;
T_1 V_76 = V_10 -> V_12 ;
int V_46 ;
if ( V_76 == V_77 ) {
V_46 = F_36 ( & V_8 -> V_78 ) ;
if ( V_46 )
F_37 ( L_1 ,
V_46 ) ;
}
}
static void F_38 ( struct V_1 * V_8 )
{
struct V_9 * V_10 = V_8 -> V_9 -> V_10 ;
T_1 V_76 = V_10 -> V_12 ;
if ( V_76 == V_77 )
F_39 ( & V_8 -> V_78 ) ;
}
static int F_40 ( struct V_9 * V_10 , struct V_32 * V_33 )
{
struct V_13 * V_14 ;
struct V_1 * V_8 ;
int V_79 ;
if ( F_11 ( ! F_41 ( V_33 , V_49 ) ) )
goto error;
V_14 = F_42 ( V_33 ) ;
if ( F_11 ( V_14 -> V_19 != V_20 ) )
goto error;
if ( F_11 ( V_14 -> V_27 != F_6 ( V_28 ) ) )
goto error;
V_79 = V_14 -> V_21 * 4 ;
if ( F_43 ( V_33 , V_49 + V_79 ,
F_6 ( V_28 ) ) )
goto V_80;
V_8 = F_44 ( V_10 ) ;
if ( ! V_8 )
goto V_80;
V_8 -> V_81 ( V_8 , V_33 ) ;
return 0 ;
V_80:
F_12 ( V_33 ) ;
return 0 ;
error:
return 1 ;
}
static struct V_82 * F_45 ( struct V_2 * V_2 , bool V_83 ,
T_2 V_4 )
{
struct V_82 * V_9 ;
struct V_84 V_85 ;
int V_46 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
if ( V_83 ) {
V_85 . V_3 = V_86 ;
} else {
V_85 . V_3 = V_77 ;
V_85 . V_87 . V_88 = F_46 ( V_89 ) ;
}
V_85 . V_90 = V_4 ;
V_46 = F_47 ( V_2 , & V_85 , & V_9 ) ;
if ( V_46 < 0 )
return F_48 ( V_46 ) ;
return V_9 ;
}
static struct V_1 * F_49 ( struct V_2 * V_2 , T_2 V_4 ,
T_6 * V_81 , void * V_69 ,
bool V_83 )
{
struct V_5 * V_6 = F_2 ( V_2 , V_7 ) ;
struct V_1 * V_8 ;
struct V_82 * V_9 ;
struct V_91 V_92 ;
V_8 = F_50 ( sizeof( * V_8 ) , V_93 ) ;
if ( ! V_8 )
return F_48 ( - V_52 ) ;
V_9 = F_45 ( V_2 , V_83 , V_4 ) ;
if ( F_15 ( V_9 ) ) {
F_51 ( V_8 ) ;
return F_52 ( V_9 ) ;
}
V_8 -> V_9 = V_9 ;
V_8 -> V_94 = 1 ;
V_8 -> V_81 = V_81 ;
V_8 -> V_95 = V_69 ;
V_8 -> V_78 . V_4 = V_4 ;
V_8 -> V_78 . V_71 . V_72 = F_21 ;
V_8 -> V_78 . V_71 . V_75 = F_32 ;
F_35 ( V_8 ) ;
V_92 . V_96 = V_8 ;
V_92 . V_97 = 1 ;
V_92 . V_98 = F_40 ;
V_92 . V_99 = NULL ;
F_53 ( V_2 , V_9 , & V_92 ) ;
F_54 ( & V_8 -> V_100 , & V_6 -> V_101 ) ;
return V_8 ;
}
struct V_1 * F_55 ( struct V_2 * V_2 , T_2 V_4 ,
T_6 * V_81 , void * V_69 ,
bool V_102 , bool V_83 )
{
struct V_1 * V_8 ;
F_56 ( & V_103 ) ;
V_8 = F_1 ( V_2 , V_83 ? V_86 : V_77 , V_4 ) ;
if ( V_8 ) {
if ( ! V_102 && V_8 -> V_81 == V_81 )
V_8 -> V_94 ++ ;
else
V_8 = F_48 ( - V_104 ) ;
} else {
V_8 = F_49 ( V_2 , V_4 , V_81 , V_69 , V_83 ) ;
}
F_57 ( & V_103 ) ;
return V_8 ;
}
void F_58 ( struct V_1 * V_8 )
{
F_56 ( & V_103 ) ;
if ( -- V_8 -> V_94 )
goto V_105;
F_59 ( & V_8 -> V_100 ) ;
F_38 ( V_8 ) ;
F_60 ( V_8 -> V_9 ) ;
F_61 ( V_8 , V_106 ) ;
V_105:
F_57 ( & V_103 ) ;
}
static T_7 int F_62 ( struct V_2 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 , V_7 ) ;
F_63 ( & V_6 -> V_101 ) ;
return 0 ;
}
static int T_8 F_64 ( void )
{
int V_107 ;
V_107 = F_65 ( & V_108 ) ;
if ( V_107 )
return V_107 ;
F_66 ( L_2 ) ;
return 0 ;
}
static void T_9 F_67 ( void )
{
F_68 ( & V_108 ) ;
}
