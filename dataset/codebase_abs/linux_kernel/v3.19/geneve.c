static inline struct V_1 * F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) ( F_2 ( V_3 ) + 1 ) ;
}
static struct V_4 * F_3 ( struct V_5 * V_5 , T_1 V_6 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
return & V_8 -> V_10 [ F_5 ( F_6 ( V_6 ) , V_11 ) ] ;
}
static struct V_12 * F_7 ( struct V_5 * V_5 , T_1 V_6 )
{
struct V_12 * V_13 ;
F_8 (gs, gs_head(net, port), hlist) {
if ( F_9 ( V_13 -> V_14 -> V_15 ) -> V_16 == V_6 )
return V_13 ;
}
return NULL ;
}
static void F_10 ( struct V_1 * V_17 ,
T_1 V_18 , T_2 V_19 [ 3 ] ,
T_2 V_20 , T_2 * V_21 )
{
V_17 -> V_22 = V_23 ;
V_17 -> V_24 = V_20 / 4 ;
V_17 -> V_25 = ! ! ( V_18 & V_26 ) ;
V_17 -> V_27 = ! ! ( V_18 & V_28 ) ;
V_17 -> V_29 = 0 ;
memcpy ( V_17 -> V_19 , V_19 , 3 ) ;
V_17 -> V_30 = F_11 ( V_31 ) ;
V_17 -> V_32 = 0 ;
memcpy ( V_17 -> V_21 , V_21 , V_20 ) ;
}
int F_12 ( struct V_12 * V_13 , struct V_33 * V_34 ,
struct V_2 * V_3 , T_3 V_35 , T_3 V_36 , T_4 V_37 ,
T_4 V_38 , T_1 V_39 , T_1 V_40 , T_1 V_41 ,
T_1 V_18 , T_2 V_19 [ 3 ] , T_2 V_24 , T_2 * V_42 ,
bool V_43 )
{
struct V_1 * V_44 ;
int V_45 ;
int V_46 ;
V_3 = F_13 ( V_3 , ! V_13 -> V_14 -> V_15 -> V_47 ) ;
if ( F_14 ( V_3 ) )
return F_15 ( V_3 ) ;
V_45 = F_16 ( V_34 -> V_36 . V_48 ) + V_34 -> V_36 . V_49
+ V_50 + V_24 + sizeof( struct V_51 )
+ ( F_17 ( V_3 ) ? V_52 : 0 ) ;
V_46 = F_18 ( V_3 , V_45 ) ;
if ( F_19 ( V_46 ) ) {
F_20 ( V_3 ) ;
return V_46 ;
}
V_3 = F_21 ( V_3 ) ;
if ( F_19 ( ! V_3 ) )
return - V_53 ;
V_44 = (struct V_1 * ) F_22 ( V_3 , sizeof( * V_44 ) + V_24 ) ;
F_10 ( V_44 , V_18 , V_19 , V_24 , V_42 ) ;
F_23 ( V_3 , F_11 ( V_31 ) ) ;
return F_24 ( V_13 -> V_14 , V_34 , V_3 , V_35 , V_36 ,
V_37 , V_38 , V_39 , V_40 , V_41 , V_43 ) ;
}
static void F_25 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_14 -> V_15 ;
T_5 V_54 = V_15 -> V_55 ;
int V_46 ;
if ( V_54 == V_56 ) {
V_46 = F_26 ( & V_13 -> V_57 ) ;
if ( V_46 )
F_27 ( L_1 ,
V_46 ) ;
}
}
static void F_28 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_14 -> V_15 ;
T_5 V_54 = V_15 -> V_55 ;
if ( V_54 == V_56 )
F_29 ( & V_13 -> V_57 ) ;
}
static int F_30 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
struct V_1 * V_17 ;
struct V_12 * V_13 ;
int V_58 ;
if ( F_19 ( ! F_31 ( V_3 , V_50 ) ) )
goto error;
V_17 = F_1 ( V_3 ) ;
if ( F_19 ( V_17 -> V_22 != V_23 ) )
goto error;
if ( F_19 ( V_17 -> V_30 != F_11 ( V_31 ) ) )
goto error;
V_58 = V_17 -> V_24 * 4 ;
if ( F_32 ( V_3 , V_50 + V_58 ,
F_11 ( V_31 ) ) )
goto V_59;
V_13 = F_33 ( V_15 ) ;
if ( ! V_13 )
goto V_59;
V_13 -> V_60 ( V_13 , V_3 ) ;
return 0 ;
V_59:
F_20 ( V_3 ) ;
return 0 ;
error:
return 1 ;
}
static void F_34 ( struct V_61 * V_62 )
{
struct V_12 * V_13 = F_35 ( V_62 , struct V_12 ,
V_63 ) ;
F_36 ( V_13 -> V_14 ) ;
F_37 ( V_13 , V_64 ) ;
}
static struct V_65 * F_38 ( struct V_5 * V_5 , bool V_66 ,
T_1 V_6 )
{
struct V_65 * V_14 ;
struct V_67 V_68 ;
int V_46 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( V_66 ) {
V_68 . V_69 = V_70 ;
} else {
V_68 . V_69 = V_56 ;
V_68 . V_71 . V_72 = F_39 ( V_73 ) ;
}
V_68 . V_74 = V_6 ;
V_46 = F_40 ( V_5 , & V_68 , & V_14 ) ;
if ( V_46 < 0 )
return F_41 ( V_46 ) ;
return V_14 ;
}
static struct V_12 * F_42 ( struct V_5 * V_5 , T_1 V_6 ,
T_6 * V_60 , void * V_75 ,
bool V_66 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
struct V_12 * V_13 ;
struct V_65 * V_14 ;
struct V_76 V_77 ;
V_13 = F_43 ( sizeof( * V_13 ) , V_78 ) ;
if ( ! V_13 )
return F_41 ( - V_53 ) ;
F_44 ( & V_13 -> V_63 , F_34 ) ;
V_14 = F_38 ( V_5 , V_66 , V_6 ) ;
if ( F_14 ( V_14 ) ) {
F_45 ( V_13 ) ;
return F_46 ( V_14 ) ;
}
V_13 -> V_14 = V_14 ;
F_47 ( & V_13 -> V_79 , 1 ) ;
V_13 -> V_60 = V_60 ;
V_13 -> V_80 = V_75 ;
V_13 -> V_57 . V_6 = V_6 ;
V_13 -> V_57 . V_81 . V_82 = NULL ;
V_13 -> V_57 . V_81 . V_83 = NULL ;
F_48 ( & V_8 -> V_84 ) ;
F_49 ( & V_13 -> V_85 , F_3 ( V_5 , V_6 ) ) ;
F_25 ( V_13 ) ;
F_50 ( & V_8 -> V_84 ) ;
V_77 . V_86 = V_13 ;
V_77 . V_87 = 1 ;
V_77 . V_88 = F_30 ;
V_77 . V_89 = NULL ;
F_51 ( V_5 , V_14 , & V_77 ) ;
return V_13 ;
}
struct V_12 * F_52 ( struct V_5 * V_5 , T_1 V_6 ,
T_6 * V_60 , void * V_75 ,
bool V_90 , bool V_66 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
struct V_12 * V_13 ;
V_13 = F_42 ( V_5 , V_6 , V_60 , V_75 , V_66 ) ;
if ( ! F_14 ( V_13 ) )
return V_13 ;
if ( V_90 )
return F_41 ( - V_91 ) ;
F_48 ( & V_8 -> V_84 ) ;
V_13 = F_7 ( V_5 , V_6 ) ;
if ( V_13 && ( ( V_13 -> V_60 != V_60 ) ||
! F_53 ( & V_13 -> V_79 , 1 , 0 ) ) )
V_13 = F_41 ( - V_92 ) ;
F_50 ( & V_8 -> V_84 ) ;
if ( ! V_13 )
V_13 = F_41 ( - V_91 ) ;
return V_13 ;
}
void F_54 ( struct V_12 * V_13 )
{
struct V_5 * V_5 = F_55 ( V_13 -> V_14 -> V_15 ) ;
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
if ( ! F_56 ( & V_13 -> V_79 ) )
return;
F_48 ( & V_8 -> V_84 ) ;
F_57 ( & V_13 -> V_85 ) ;
F_28 ( V_13 ) ;
F_50 ( & V_8 -> V_84 ) ;
F_58 ( V_93 , & V_13 -> V_63 ) ;
}
static T_7 int F_59 ( struct V_5 * V_5 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
unsigned int V_94 ;
F_60 ( & V_8 -> V_84 ) ;
for ( V_94 = 0 ; V_94 < V_95 ; ++ V_94 )
F_61 ( & V_8 -> V_10 [ V_94 ] ) ;
return 0 ;
}
static int T_8 F_62 ( void )
{
int V_96 ;
V_93 = F_63 ( L_2 , 0 , 0 ) ;
if ( ! V_93 )
return - V_53 ;
V_96 = F_64 ( & V_97 ) ;
if ( V_96 )
return V_96 ;
F_65 ( L_3 ) ;
return 0 ;
}
static void T_9 F_66 ( void )
{
F_67 ( V_93 ) ;
F_68 ( & V_97 ) ;
}
