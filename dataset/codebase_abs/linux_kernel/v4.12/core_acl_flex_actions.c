struct V_1 * F_1 ( unsigned int V_2 ,
const struct V_3 * V_4 ,
void * V_5 )
{
struct V_1 * V_1 ;
int V_6 ;
V_1 = F_2 ( sizeof( * V_1 ) , V_7 ) ;
if ( ! V_1 )
return F_3 ( - V_8 ) ;
V_6 = F_4 ( & V_1 -> V_9 , & V_10 ) ;
if ( V_6 )
goto V_11;
V_6 = F_4 ( & V_1 -> V_12 ,
& V_13 ) ;
if ( V_6 )
goto V_14;
V_1 -> V_2 = V_2 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_5 = V_5 ;
return V_1 ;
V_14:
F_5 ( & V_1 -> V_9 ) ;
V_11:
F_6 ( V_1 ) ;
return F_3 ( V_6 ) ;
}
void F_7 ( struct V_1 * V_1 )
{
F_5 ( & V_1 -> V_12 ) ;
F_5 ( & V_1 -> V_9 ) ;
F_6 ( V_1 ) ;
}
static void F_8 ( struct V_15 * V_16 ,
enum V_17 V_18 ,
T_1 V_19 )
{
char * V_20 = V_16 -> V_21 . V_22 ;
F_9 ( V_20 , V_23 ) ;
F_10 ( V_20 , true ) ;
F_11 ( V_20 , V_18 ) ;
F_12 ( V_20 , V_19 ) ;
}
static void F_13 ( struct V_15 * V_16 ,
T_2 V_24 )
{
char * V_20 = V_16 -> V_21 . V_22 ;
F_9 ( V_20 , V_25 ) ;
F_14 ( V_20 , V_24 ) ;
}
static struct V_15 * F_15 ( bool V_26 )
{
struct V_15 * V_16 ;
V_16 = F_2 ( sizeof( * V_16 ) , V_7 ) ;
if ( ! V_16 )
return NULL ;
F_8 ( V_16 , V_27 , 0 ) ;
V_16 -> V_21 . V_26 = V_26 ;
V_16 -> V_28 = 1 ;
return V_16 ;
}
static void F_16 ( struct V_15 * V_16 )
{
F_6 ( V_16 ) ;
}
static int F_17 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
int V_6 ;
V_6 = F_18 ( & V_1 -> V_9 , & V_16 -> V_29 ,
V_10 ) ;
if ( V_6 )
return V_6 ;
V_6 = V_1 -> V_4 -> V_30 ( V_1 -> V_5 ,
& V_16 -> V_31 ,
V_16 -> V_21 . V_22 ,
V_16 -> V_21 . V_26 ) ;
if ( V_6 )
goto V_32;
V_16 -> V_33 = true ;
V_16 -> V_34 = NULL ;
return 0 ;
V_32:
F_19 ( & V_1 -> V_9 , & V_16 -> V_29 ,
V_10 ) ;
return V_6 ;
}
static void F_20 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
V_1 -> V_4 -> V_35 ( V_1 -> V_5 ,
V_16 -> V_31 ,
V_16 -> V_21 . V_26 ) ;
F_19 ( & V_1 -> V_9 , & V_16 -> V_29 ,
V_10 ) ;
V_16 -> V_33 = false ;
}
static void F_21 ( struct V_1 * V_1 ,
struct V_15 * V_16 )
{
if ( -- V_16 -> V_28 )
return;
if ( V_16 -> V_33 )
F_20 ( V_1 , V_16 ) ;
F_16 ( V_16 ) ;
}
static struct V_15 * F_22 ( struct V_1 * V_1 ,
struct V_15 * V_36 )
{
struct V_15 * V_16 ;
int V_6 ;
V_16 = F_23 ( & V_1 -> V_9 , & V_36 -> V_21 ,
V_10 ) ;
if ( V_16 ) {
V_16 -> V_28 ++ ;
F_21 ( V_1 , V_36 ) ;
} else {
V_16 = V_36 ;
V_6 = F_17 ( V_1 , V_16 ) ;
if ( V_6 )
return F_3 ( V_6 ) ;
}
return V_16 ;
}
struct V_37 * F_24 ( struct V_1 * V_1 )
{
struct V_37 * V_38 ;
V_38 = F_2 ( sizeof( * V_38 ) , V_7 ) ;
if ( ! V_38 )
return NULL ;
F_25 ( & V_38 -> V_39 ) ;
V_38 -> V_40 = V_1 ;
V_38 -> V_41 = F_15 ( true ) ;
if ( ! V_38 -> V_41 )
goto V_42;
V_38 -> V_43 = V_38 -> V_41 ;
return V_38 ;
V_42:
F_6 ( V_38 ) ;
return NULL ;
}
void F_26 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_41 ;
struct V_15 * V_44 ;
do {
V_44 = V_16 -> V_45 ;
F_21 ( V_38 -> V_40 , V_16 ) ;
V_16 = V_44 ;
} while ( V_16 );
F_27 ( V_38 ) ;
F_6 ( V_38 ) ;
}
int F_28 ( struct V_37 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_43 ;
struct V_15 * V_46 ;
V_38 -> V_43 = NULL ;
V_38 -> V_47 = true ;
do {
V_46 = V_16 -> V_34 ;
V_16 = F_22 ( V_38 -> V_40 , V_16 ) ;
if ( F_29 ( V_16 ) )
return F_30 ( V_16 ) ;
if ( V_46 ) {
V_46 -> V_45 = V_16 ;
F_13 ( V_46 , V_16 -> V_31 ) ;
V_16 = V_46 ;
}
} while ( V_46 );
V_38 -> V_41 = V_16 ;
return 0 ;
}
char * F_31 ( struct V_37 * V_38 )
{
return V_38 -> V_41 -> V_21 . V_22 ;
}
T_2 F_32 ( struct V_37 * V_38 )
{
return V_38 -> V_41 -> V_31 ;
}
void F_33 ( struct V_37 * V_38 )
{
if ( F_34 ( V_38 -> V_47 ) )
return;
F_8 ( V_38 -> V_43 ,
V_48 , 0 ) ;
V_38 -> V_47 = true ;
}
void F_35 ( struct V_37 * V_38 , T_1 V_19 )
{
if ( F_34 ( V_38 -> V_47 ) )
return;
F_8 ( V_38 -> V_43 ,
V_49 , V_19 ) ;
V_38 -> V_47 = true ;
}
static struct V_50 *
F_36 ( struct V_1 * V_1 , T_3 V_51 )
{
struct V_50 * V_52 ;
int V_6 ;
V_52 = F_2 ( sizeof( * V_52 ) , V_7 ) ;
if ( ! V_52 )
return F_3 ( - V_8 ) ;
V_52 -> V_21 . V_51 = V_51 ;
V_52 -> V_28 = 1 ;
V_6 = F_18 ( & V_1 -> V_12 ,
& V_52 -> V_29 ,
V_13 ) ;
if ( V_6 )
goto V_53;
V_6 = V_1 -> V_4 -> V_54 ( V_1 -> V_5 ,
& V_52 -> V_31 ,
V_51 ) ;
if ( V_6 )
goto V_55;
return V_52 ;
V_55:
F_19 ( & V_1 -> V_12 , & V_52 -> V_29 ,
V_13 ) ;
V_53:
F_6 ( V_52 ) ;
return F_3 ( V_6 ) ;
}
static void F_37 ( struct V_1 * V_1 ,
struct V_50 * V_52 )
{
V_1 -> V_4 -> V_56 ( V_1 -> V_5 ,
V_52 -> V_31 ) ;
F_19 ( & V_1 -> V_12 , & V_52 -> V_29 ,
V_13 ) ;
F_6 ( V_52 ) ;
}
static struct V_50 *
F_38 ( struct V_1 * V_1 , T_3 V_51 )
{
struct V_57 V_21 = { 0 } ;
struct V_50 * V_52 ;
V_21 . V_51 = V_51 ;
V_52 = F_23 ( & V_1 -> V_12 , & V_21 ,
V_13 ) ;
if ( V_52 ) {
V_52 -> V_28 ++ ;
return V_52 ;
}
return F_36 ( V_1 , V_51 ) ;
}
static void F_39 ( struct V_1 * V_1 ,
struct V_50 * V_52 )
{
if ( -- V_52 -> V_28 )
return;
F_37 ( V_1 , V_52 ) ;
}
static struct V_58 *
F_40 ( struct V_37 * V_38 , T_3 V_51 )
{
struct V_58 * V_59 ;
struct V_50 * V_52 ;
int V_6 ;
V_59 = F_2 ( sizeof( * V_59 ) , V_7 ) ;
if ( ! V_59 )
return F_3 ( - V_8 ) ;
V_52 = F_38 ( V_38 -> V_40 , V_51 ) ;
if ( F_29 ( V_52 ) ) {
V_6 = F_30 ( V_52 ) ;
goto V_60;
}
V_59 -> V_52 = V_52 ;
F_41 ( & V_59 -> V_61 , & V_38 -> V_39 ) ;
return V_59 ;
V_60:
F_6 ( V_59 ) ;
return F_3 ( V_6 ) ;
}
static void
F_42 ( struct V_37 * V_38 ,
struct V_58 * V_59 )
{
F_43 ( & V_59 -> V_61 ) ;
F_39 ( V_38 -> V_40 , V_59 -> V_52 ) ;
F_6 ( V_59 ) ;
}
static void F_27 ( struct V_37 * V_38 )
{
struct V_58 * V_59 ;
struct V_58 * V_62 ;
F_44 (fwd_entry_ref, tmp,
&block->fwd_entry_ref_list, list)
F_42 ( V_38 , V_59 ) ;
}
static char * F_45 ( struct V_37 * V_38 ,
T_3 V_63 , T_3 V_64 )
{
char * V_65 ;
char * V_20 ;
if ( F_34 ( V_38 -> V_47 ) )
return NULL ;
if ( V_38 -> V_66 + V_64 >
V_38 -> V_40 -> V_2 ) {
struct V_15 * V_16 ;
V_16 = F_15 ( false ) ;
if ( ! V_16 )
return NULL ;
V_16 -> V_34 = V_38 -> V_43 ;
V_38 -> V_66 = 0 ;
V_38 -> V_43 -> V_45 = V_16 ;
V_38 -> V_43 = V_16 ;
}
V_20 = V_38 -> V_43 -> V_21 . V_22 ;
V_65 = V_20 + V_38 -> V_66 * V_67 ;
V_38 -> V_66 += V_64 ;
F_46 ( V_65 , V_63 ) ;
return V_65 + V_68 ;
}
static inline void
F_47 ( char * V_69 ,
enum V_70 V_71 ,
enum V_72 V_73 , T_1 V_74 ,
enum V_72 V_75 , T_3 V_76 ,
enum V_72 V_77 , T_3 V_78 )
{
F_48 ( V_69 , V_71 ) ;
F_49 ( V_69 , V_73 ) ;
F_50 ( V_69 , V_74 ) ;
F_51 ( V_69 , V_75 ) ;
F_52 ( V_69 , V_76 ) ;
F_53 ( V_69 , V_77 ) ;
F_54 ( V_69 , V_78 ) ;
}
int F_55 ( struct V_37 * V_38 ,
T_1 V_74 , T_3 V_76 , T_3 V_79 )
{
char * V_80 = F_45 ( V_38 ,
V_81 ,
V_82 ) ;
if ( ! V_80 )
return - V_83 ;
F_47 ( V_80 , V_84 ,
V_85 , V_74 ,
V_85 , V_76 ,
V_85 , V_79 ) ;
return 0 ;
}
static inline void
F_56 ( char * V_69 ,
enum V_86 V_87 )
{
F_57 ( V_69 , V_87 ) ;
}
int F_58 ( struct V_37 * V_38 )
{
char * V_80 = F_45 ( V_38 ,
V_88 ,
V_89 ) ;
if ( ! V_80 )
return - V_83 ;
F_56 ( V_80 , V_90 ) ;
return 0 ;
}
static inline void
F_59 ( char * V_69 , enum V_91 type ,
T_2 V_92 , bool V_93 )
{
F_60 ( V_69 , type ) ;
F_61 ( V_69 , V_92 ) ;
F_62 ( V_69 , V_93 ) ;
}
int F_63 ( struct V_37 * V_38 ,
T_3 V_51 , bool V_93 )
{
struct V_58 * V_59 ;
T_2 V_31 ;
char * V_80 ;
int V_6 ;
if ( V_93 )
return - V_94 ;
V_59 = F_40 ( V_38 , V_51 ) ;
if ( F_29 ( V_59 ) )
return F_30 ( V_59 ) ;
V_31 = V_59 -> V_52 -> V_31 ;
V_80 = F_45 ( V_38 , V_95 ,
V_96 ) ;
if ( ! V_80 ) {
V_6 = - V_83 ;
goto V_97;
}
F_59 ( V_80 , V_98 ,
V_31 , V_93 ) ;
return 0 ;
V_97:
F_42 ( V_38 , V_59 ) ;
return V_6 ;
}
static inline void
F_64 ( char * V_69 ,
enum V_99 V_100 ,
T_2 V_101 )
{
F_65 ( V_69 , V_100 ) ;
F_66 ( V_69 , V_101 ) ;
}
int F_67 ( struct V_37 * V_38 ,
T_2 V_101 )
{
char * V_80 = F_45 ( V_38 ,
V_102 ,
V_103 ) ;
if ( ! V_80 )
return - V_83 ;
F_64 ( V_80 , V_104 ,
V_101 ) ;
return 0 ;
}
static inline void F_68 ( char * V_69 ,
enum V_105 V_106 ,
T_1 V_107 )
{
F_69 ( V_69 , V_106 ) ;
F_70 ( V_69 , V_107 ) ;
}
int F_71 ( struct V_37 * V_38 , T_1 V_107 )
{
char * V_80 = F_45 ( V_38 ,
V_108 ,
V_109 ) ;
if ( ! V_80 )
return - V_83 ;
F_68 ( V_80 , V_110 , V_107 ) ;
return 0 ;
}
