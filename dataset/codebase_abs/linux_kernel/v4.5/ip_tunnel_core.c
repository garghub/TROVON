void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_2 V_9 ,
T_2 V_10 , T_2 V_11 , T_3 V_12 , bool V_13 )
{
int V_14 = V_6 -> V_15 - F_2 ( V_6 ) ;
struct V_16 * V_16 = F_3 ( V_4 -> V_8 . V_17 ) ;
struct V_18 * V_17 = V_6 -> V_17 ;
struct V_19 * V_20 ;
int V_21 ;
F_4 ( V_6 , V_13 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 , & V_4 -> V_8 ) ;
memset ( F_7 ( V_6 ) , 0 , sizeof( * F_7 ( V_6 ) ) ) ;
F_8 ( V_6 , sizeof( struct V_19 ) ) ;
F_9 ( V_6 ) ;
V_20 = F_10 ( V_6 ) ;
V_20 -> V_22 = 4 ;
V_20 -> V_23 = sizeof( struct V_19 ) >> 2 ;
V_20 -> V_24 = V_12 ;
V_20 -> V_25 = V_9 ;
V_20 -> V_10 = V_10 ;
V_20 -> V_26 = V_8 ;
V_20 -> V_27 = V_7 ;
V_20 -> V_11 = V_11 ;
F_11 ( V_16 , V_20 , F_12 ( V_6 ) -> V_28 ? : 1 ) ;
V_21 = F_13 ( V_16 , V_2 , V_6 ) ;
if ( F_14 ( F_15 ( V_21 ) ) )
V_14 = 0 ;
F_16 ( V_17 , V_14 ) ;
}
int F_17 ( struct V_5 * V_6 , int V_29 , T_3 V_30 )
{
if ( F_14 ( ! F_18 ( V_6 , V_29 ) ) )
return - V_31 ;
F_19 ( V_6 , V_29 ) ;
if ( V_30 == F_20 ( V_32 ) ) {
struct V_33 * V_34 ;
if ( F_14 ( ! F_18 ( V_6 , V_35 ) ) )
return - V_31 ;
V_34 = (struct V_33 * ) V_6 -> V_36 ;
if ( F_21 ( F_22 ( V_34 -> V_37 ) ) )
V_6 -> V_25 = V_34 -> V_37 ;
else
V_6 -> V_25 = F_20 ( V_38 ) ;
} else {
V_6 -> V_25 = V_30 ;
}
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
F_26 ( V_6 ) ;
V_6 -> V_39 = 0 ;
F_27 ( V_6 , 0 ) ;
V_6 -> V_40 = V_41 ;
return 0 ;
}
struct V_42 * F_28 ( struct V_42 * V_43 ,
T_4 V_44 )
{
struct V_42 * V_45 ;
struct V_46 * V_8 , * V_7 ;
if ( ! V_43 || V_43 -> V_47 . V_48 . V_49 & V_50 )
return NULL ;
V_45 = F_29 ( 0 , V_44 ) ;
if ( ! V_45 )
return NULL ;
V_8 = & V_45 -> V_47 . V_48 ;
V_7 = & V_43 -> V_47 . V_48 ;
V_8 -> V_51 . V_52 = V_7 -> V_51 . V_52 ;
if ( V_7 -> V_49 & V_53 )
memcpy ( & V_8 -> V_51 . V_47 . V_54 . V_8 , & V_7 -> V_51 . V_47 . V_54 . V_7 ,
sizeof( struct V_55 ) ) ;
else
V_8 -> V_51 . V_47 . V_56 . V_8 = V_7 -> V_51 . V_47 . V_56 . V_7 ;
V_8 -> V_49 = V_7 -> V_49 | V_50 ;
return V_45 ;
}
struct V_5 * F_30 ( struct V_5 * V_6 ,
bool V_57 ,
int V_58 )
{
int V_21 ;
if ( F_21 ( ! V_6 -> V_59 ) ) {
F_31 ( V_6 ) ;
V_6 -> V_59 = 1 ;
}
if ( F_32 ( V_6 ) ) {
V_21 = F_33 ( V_6 , V_60 ) ;
if ( F_14 ( V_21 ) )
goto error;
F_12 ( V_6 ) -> V_61 |= V_58 ;
return V_6 ;
}
if ( V_57 )
V_6 -> V_59 = 0 ;
if ( V_6 -> V_62 == V_63 && V_57 ) {
V_21 = F_34 ( V_6 ) ;
if ( F_14 ( V_21 ) )
goto error;
} else if ( V_6 -> V_62 != V_63 )
V_6 -> V_62 = V_64 ;
return V_6 ;
error:
F_35 ( V_6 ) ;
return F_36 ( V_21 ) ;
}
struct V_65 * F_37 ( struct V_18 * V_17 ,
struct V_65 * V_66 )
{
int V_67 ;
F_38 ( V_66 , & V_17 -> V_68 ) ;
F_39 (i) {
const struct V_69 * V_70 =
F_40 ( V_17 -> V_70 , V_67 ) ;
T_5 V_71 , V_72 , V_73 , V_74 ;
unsigned int V_75 ;
do {
V_75 = F_41 ( & V_70 -> V_76 ) ;
V_71 = V_70 -> V_71 ;
V_73 = V_70 -> V_73 ;
V_72 = V_70 -> V_72 ;
V_74 = V_70 -> V_74 ;
} while ( F_42 ( & V_70 -> V_76 , V_75 ) );
V_66 -> V_71 += V_71 ;
V_66 -> V_73 += V_73 ;
V_66 -> V_72 += V_72 ;
V_66 -> V_74 += V_74 ;
}
return V_66 ;
}
static int F_43 ( struct V_18 * V_17 , struct V_77 * V_78 ,
unsigned int V_79 , const void * V_80 ,
struct V_81 * * V_82 )
{
struct V_46 * V_48 ;
struct V_81 * V_83 ;
struct V_77 * V_84 [ V_85 + 1 ] ;
int V_21 ;
V_21 = F_44 ( V_84 , V_85 , V_78 , V_86 ) ;
if ( V_21 < 0 )
return V_21 ;
V_83 = F_45 ( sizeof( * V_48 ) ) ;
if ( ! V_83 )
return - V_31 ;
V_83 -> type = V_87 ;
V_48 = F_46 ( V_83 ) ;
if ( V_84 [ V_88 ] )
V_48 -> V_51 . V_52 = F_47 ( V_84 [ V_88 ] ) ;
if ( V_84 [ V_89 ] )
V_48 -> V_51 . V_47 . V_56 . V_8 = F_48 ( V_84 [ V_89 ] ) ;
if ( V_84 [ V_90 ] )
V_48 -> V_51 . V_47 . V_56 . V_7 = F_48 ( V_84 [ V_90 ] ) ;
if ( V_84 [ V_91 ] )
V_48 -> V_51 . V_11 = F_49 ( V_84 [ V_91 ] ) ;
if ( V_84 [ V_92 ] )
V_48 -> V_51 . V_10 = F_49 ( V_84 [ V_92 ] ) ;
if ( V_84 [ V_93 ] )
V_48 -> V_51 . V_94 = F_50 ( V_84 [ V_93 ] ) ;
V_48 -> V_49 = V_50 ;
V_48 -> V_95 = 0 ;
* V_82 = V_83 ;
return 0 ;
}
static int F_51 ( struct V_5 * V_6 ,
struct V_81 * V_96 )
{
struct V_46 * V_48 = F_46 ( V_96 ) ;
if ( F_52 ( V_6 , V_88 , V_48 -> V_51 . V_52 ) ||
F_53 ( V_6 , V_89 , V_48 -> V_51 . V_47 . V_56 . V_8 ) ||
F_53 ( V_6 , V_90 , V_48 -> V_51 . V_47 . V_56 . V_7 ) ||
F_54 ( V_6 , V_92 , V_48 -> V_51 . V_10 ) ||
F_54 ( V_6 , V_91 , V_48 -> V_51 . V_11 ) ||
F_55 ( V_6 , V_93 , V_48 -> V_51 . V_94 ) )
return - V_31 ;
return 0 ;
}
static int F_56 ( struct V_81 * V_96 )
{
return F_57 ( 8 )
+ F_57 ( 4 )
+ F_57 ( 4 )
+ F_57 ( 1 )
+ F_57 ( 1 )
+ F_57 ( 2 ) ;
}
static int F_58 ( struct V_81 * V_97 , struct V_81 * V_98 )
{
return memcmp ( F_46 ( V_97 ) , F_46 ( V_98 ) ,
sizeof( struct V_46 ) ) ;
}
static int F_59 ( struct V_18 * V_17 , struct V_77 * V_78 ,
unsigned int V_79 , const void * V_80 ,
struct V_81 * * V_82 )
{
struct V_46 * V_48 ;
struct V_81 * V_83 ;
struct V_77 * V_84 [ V_99 + 1 ] ;
int V_21 ;
V_21 = F_44 ( V_84 , V_99 , V_78 , V_100 ) ;
if ( V_21 < 0 )
return V_21 ;
V_83 = F_45 ( sizeof( * V_48 ) ) ;
if ( ! V_83 )
return - V_31 ;
V_83 -> type = V_101 ;
V_48 = F_46 ( V_83 ) ;
if ( V_84 [ V_102 ] )
V_48 -> V_51 . V_52 = F_47 ( V_84 [ V_102 ] ) ;
if ( V_84 [ V_103 ] )
V_48 -> V_51 . V_47 . V_54 . V_8 = F_60 ( V_84 [ V_103 ] ) ;
if ( V_84 [ V_104 ] )
V_48 -> V_51 . V_47 . V_54 . V_7 = F_60 ( V_84 [ V_104 ] ) ;
if ( V_84 [ V_105 ] )
V_48 -> V_51 . V_11 = F_49 ( V_84 [ V_105 ] ) ;
if ( V_84 [ V_106 ] )
V_48 -> V_51 . V_10 = F_49 ( V_84 [ V_106 ] ) ;
if ( V_84 [ V_107 ] )
V_48 -> V_51 . V_94 = F_50 ( V_84 [ V_107 ] ) ;
V_48 -> V_49 = V_50 | V_53 ;
V_48 -> V_95 = 0 ;
* V_82 = V_83 ;
return 0 ;
}
static int F_61 ( struct V_5 * V_6 ,
struct V_81 * V_96 )
{
struct V_46 * V_48 = F_46 ( V_96 ) ;
if ( F_52 ( V_6 , V_102 , V_48 -> V_51 . V_52 ) ||
F_62 ( V_6 , V_103 , & V_48 -> V_51 . V_47 . V_54 . V_8 ) ||
F_62 ( V_6 , V_104 , & V_48 -> V_51 . V_47 . V_54 . V_7 ) ||
F_54 ( V_6 , V_105 , V_48 -> V_51 . V_10 ) ||
F_54 ( V_6 , V_106 , V_48 -> V_51 . V_11 ) ||
F_55 ( V_6 , V_107 , V_48 -> V_51 . V_94 ) )
return - V_31 ;
return 0 ;
}
static int F_63 ( struct V_81 * V_96 )
{
return F_57 ( 8 )
+ F_57 ( 16 )
+ F_57 ( 16 )
+ F_57 ( 1 )
+ F_57 ( 1 )
+ F_57 ( 2 ) ;
}
void T_6 F_64 ( void )
{
F_65 ( & V_108 , V_87 ) ;
F_65 ( & V_109 , V_101 ) ;
}
void F_66 ( void )
{
F_67 ( & V_110 ) ;
}
void F_68 ( void )
{
F_69 ( & V_110 ) ;
}
