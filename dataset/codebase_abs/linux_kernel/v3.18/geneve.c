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
V_45 = F_14 ( V_34 -> V_36 . V_48 ) + V_34 -> V_36 . V_49
+ V_50 + V_24 + sizeof( struct V_51 )
+ ( F_15 ( V_3 ) ? V_52 : 0 ) ;
V_46 = F_16 ( V_3 , V_45 ) ;
if ( F_17 ( V_46 ) )
return V_46 ;
if ( F_15 ( V_3 ) ) {
if ( F_17 ( ! F_18 ( V_3 ,
V_3 -> V_53 ,
F_19 ( V_3 ) ) ) ) {
V_46 = - V_54 ;
return V_46 ;
}
V_3 -> V_55 = 0 ;
}
V_44 = (struct V_1 * ) F_20 ( V_3 , sizeof( * V_44 ) + V_24 ) ;
F_10 ( V_44 , V_18 , V_19 , V_24 , V_42 ) ;
F_21 ( V_3 , F_11 ( V_31 ) ) ;
return F_22 ( V_13 -> V_14 , V_34 , V_3 , V_35 , V_36 ,
V_37 , V_38 , V_39 , V_40 , V_41 , V_43 ) ;
}
static void F_23 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_14 -> V_15 ;
T_5 V_56 = V_15 -> V_57 ;
int V_46 ;
if ( V_56 == V_58 ) {
V_46 = F_24 ( & V_13 -> V_59 ) ;
if ( V_46 )
F_25 ( L_1 ,
V_46 ) ;
}
}
static int F_26 ( struct V_14 * V_15 , struct V_2 * V_3 )
{
struct V_1 * V_17 ;
struct V_12 * V_13 ;
int V_60 ;
if ( F_17 ( ! F_27 ( V_3 , V_50 ) ) )
goto error;
V_17 = F_1 ( V_3 ) ;
if ( F_17 ( V_17 -> V_22 != V_23 ) )
goto error;
if ( F_17 ( V_17 -> V_30 != F_11 ( V_31 ) ) )
goto error;
V_60 = V_17 -> V_24 * 4 ;
if ( F_28 ( V_3 , V_50 + V_60 ,
F_11 ( V_31 ) ) )
goto V_61;
V_13 = F_29 ( V_15 ) ;
if ( ! V_13 )
goto V_61;
V_13 -> V_62 ( V_13 , V_3 ) ;
return 0 ;
V_61:
F_30 ( V_3 ) ;
return 0 ;
error:
return 1 ;
}
static void F_31 ( struct V_63 * V_64 )
{
struct V_12 * V_13 = F_32 ( V_64 , struct V_12 ,
V_65 ) ;
F_33 ( V_13 -> V_14 ) ;
F_34 ( V_13 , V_66 ) ;
}
static struct V_67 * F_35 ( struct V_5 * V_5 , bool V_68 ,
T_1 V_6 )
{
struct V_67 * V_14 ;
struct V_69 V_70 ;
int V_46 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
if ( V_68 ) {
V_70 . V_71 = V_72 ;
} else {
V_70 . V_71 = V_58 ;
V_70 . V_73 . V_74 = F_36 ( V_75 ) ;
}
V_70 . V_76 = V_6 ;
V_46 = F_37 ( V_5 , & V_70 , & V_14 ) ;
if ( V_46 < 0 )
return F_38 ( V_46 ) ;
return V_14 ;
}
static struct V_12 * F_39 ( struct V_5 * V_5 , T_1 V_6 ,
T_6 * V_62 , void * V_77 ,
bool V_68 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
struct V_12 * V_13 ;
struct V_67 * V_14 ;
struct V_78 V_79 ;
V_13 = F_40 ( sizeof( * V_13 ) , V_80 ) ;
if ( ! V_13 )
return F_38 ( - V_54 ) ;
F_41 ( & V_13 -> V_65 , F_31 ) ;
V_14 = F_35 ( V_5 , V_68 , V_6 ) ;
if ( F_42 ( V_14 ) ) {
F_43 ( V_13 ) ;
return F_44 ( V_14 ) ;
}
V_13 -> V_14 = V_14 ;
F_45 ( & V_13 -> V_81 , 1 ) ;
V_13 -> V_62 = V_62 ;
V_13 -> V_82 = V_77 ;
V_13 -> V_59 . V_6 = V_6 ;
V_13 -> V_59 . V_83 . V_84 = NULL ;
V_13 -> V_59 . V_83 . V_85 = NULL ;
F_46 ( & V_8 -> V_86 ) ;
F_47 ( & V_13 -> V_87 , F_3 ( V_5 , V_6 ) ) ;
F_23 ( V_13 ) ;
F_48 ( & V_8 -> V_86 ) ;
V_79 . V_88 = V_13 ;
V_79 . V_89 = 1 ;
V_79 . V_90 = F_26 ;
V_79 . V_91 = NULL ;
F_49 ( V_5 , V_14 , & V_79 ) ;
return V_13 ;
}
struct V_12 * F_50 ( struct V_5 * V_5 , T_1 V_6 ,
T_6 * V_62 , void * V_77 ,
bool V_92 , bool V_68 )
{
struct V_12 * V_13 ;
V_13 = F_39 ( V_5 , V_6 , V_62 , V_77 , V_68 ) ;
if ( ! F_42 ( V_13 ) )
return V_13 ;
if ( V_92 )
return F_38 ( - V_93 ) ;
V_13 = F_7 ( V_5 , V_6 ) ;
if ( V_13 ) {
if ( V_13 -> V_62 == V_62 )
F_51 ( & V_13 -> V_81 ) ;
else
V_13 = F_38 ( - V_94 ) ;
} else {
V_13 = F_38 ( - V_93 ) ;
}
return V_13 ;
}
void F_52 ( struct V_12 * V_13 )
{
if ( ! F_53 ( & V_13 -> V_81 ) )
return;
F_54 ( V_95 , & V_13 -> V_65 ) ;
}
static T_7 int F_55 ( struct V_5 * V_5 )
{
struct V_7 * V_8 = F_4 ( V_5 , V_9 ) ;
unsigned int V_96 ;
F_56 ( & V_8 -> V_86 ) ;
for ( V_96 = 0 ; V_96 < V_97 ; ++ V_96 )
F_57 ( & V_8 -> V_10 [ V_96 ] ) ;
return 0 ;
}
static int T_8 F_58 ( void )
{
int V_98 ;
V_95 = F_59 ( L_2 , 0 , 0 ) ;
if ( ! V_95 )
return - V_54 ;
V_98 = F_60 ( & V_99 ) ;
if ( V_98 )
return V_98 ;
F_61 ( L_3 ) ;
return 0 ;
}
static void T_9 F_62 ( void )
{
F_63 ( V_95 ) ;
F_64 ( & V_99 ) ;
}
