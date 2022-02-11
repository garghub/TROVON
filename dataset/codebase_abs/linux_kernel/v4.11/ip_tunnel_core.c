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
int F_17 ( struct V_5 * V_6 , int V_29 ,
T_3 V_30 , bool V_31 , bool V_13 )
{
if ( F_14 ( ! F_18 ( V_6 , V_29 ) ) )
return - V_32 ;
F_19 ( V_6 , V_29 ) ;
if ( ! V_31 && V_30 == F_20 ( V_33 ) ) {
struct V_34 * V_35 ;
if ( F_14 ( ! F_18 ( V_6 , V_36 ) ) )
return - V_32 ;
V_35 = (struct V_34 * ) V_6 -> V_37 ;
if ( F_21 ( F_22 ( V_35 -> V_38 ) ) )
V_6 -> V_25 = V_35 -> V_38 ;
else
V_6 -> V_25 = F_20 ( V_39 ) ;
} else {
V_6 -> V_25 = V_30 ;
}
F_5 ( V_6 ) ;
V_6 -> V_40 = 0 ;
F_23 ( V_6 , 0 ) ;
F_4 ( V_6 , V_13 ) ;
return F_24 ( V_6 ) ;
}
struct V_41 * F_25 ( struct V_41 * V_42 ,
T_4 V_43 )
{
struct V_41 * V_44 ;
struct V_45 * V_8 , * V_7 ;
if ( ! V_42 || V_42 -> V_46 . V_47 . V_48 & V_49 )
return NULL ;
V_44 = F_26 ( 0 , V_43 ) ;
if ( ! V_44 )
return NULL ;
V_8 = & V_44 -> V_46 . V_47 ;
V_7 = & V_42 -> V_46 . V_47 ;
V_8 -> V_50 . V_51 = V_7 -> V_50 . V_51 ;
if ( V_7 -> V_48 & V_52 )
memcpy ( & V_8 -> V_50 . V_46 . V_53 . V_8 , & V_7 -> V_50 . V_46 . V_53 . V_7 ,
sizeof( struct V_54 ) ) ;
else
V_8 -> V_50 . V_46 . V_55 . V_8 = V_7 -> V_50 . V_46 . V_55 . V_7 ;
V_8 -> V_48 = V_7 -> V_48 | V_49 ;
return V_44 ;
}
int F_27 ( struct V_5 * V_6 ,
int V_56 )
{
int V_21 ;
if ( F_21 ( ! V_6 -> V_57 ) ) {
F_28 ( V_6 ) ;
V_6 -> V_57 = 1 ;
}
if ( F_29 ( V_6 ) ) {
V_21 = F_30 ( V_6 , V_58 ) ;
if ( F_14 ( V_21 ) )
return V_21 ;
F_12 ( V_6 ) -> V_59 |= V_56 ;
return 0 ;
}
if ( V_6 -> V_60 != V_61 ) {
V_6 -> V_60 = V_62 ;
V_6 -> V_57 = 0 ;
}
return 0 ;
}
void F_31 ( struct V_18 * V_17 ,
struct V_63 * V_64 )
{
int V_65 ;
F_32 ( V_64 , & V_17 -> V_66 ) ;
F_33 (i) {
const struct V_67 * V_68 =
F_34 ( V_17 -> V_68 , V_65 ) ;
T_5 V_69 , V_70 , V_71 , V_72 ;
unsigned int V_73 ;
do {
V_73 = F_35 ( & V_68 -> V_74 ) ;
V_69 = V_68 -> V_69 ;
V_71 = V_68 -> V_71 ;
V_70 = V_68 -> V_70 ;
V_72 = V_68 -> V_72 ;
} while ( F_36 ( & V_68 -> V_74 , V_73 ) );
V_64 -> V_69 += V_69 ;
V_64 -> V_71 += V_71 ;
V_64 -> V_70 += V_70 ;
V_64 -> V_72 += V_72 ;
}
}
static int F_37 ( struct V_75 * V_76 ,
unsigned int V_77 , const void * V_78 ,
struct V_79 * * V_80 )
{
struct V_45 * V_47 ;
struct V_79 * V_81 ;
struct V_75 * V_82 [ V_83 + 1 ] ;
int V_21 ;
V_21 = F_38 ( V_82 , V_83 , V_76 , V_84 ) ;
if ( V_21 < 0 )
return V_21 ;
V_81 = F_39 ( sizeof( * V_47 ) ) ;
if ( ! V_81 )
return - V_32 ;
V_81 -> type = V_85 ;
V_47 = F_40 ( V_81 ) ;
if ( V_82 [ V_86 ] )
V_47 -> V_50 . V_51 = F_41 ( V_82 [ V_86 ] ) ;
if ( V_82 [ V_87 ] )
V_47 -> V_50 . V_46 . V_55 . V_8 = F_42 ( V_82 [ V_87 ] ) ;
if ( V_82 [ V_88 ] )
V_47 -> V_50 . V_46 . V_55 . V_7 = F_42 ( V_82 [ V_88 ] ) ;
if ( V_82 [ V_89 ] )
V_47 -> V_50 . V_11 = F_43 ( V_82 [ V_89 ] ) ;
if ( V_82 [ V_90 ] )
V_47 -> V_50 . V_10 = F_43 ( V_82 [ V_90 ] ) ;
if ( V_82 [ V_91 ] )
V_47 -> V_50 . V_92 = F_44 ( V_82 [ V_91 ] ) ;
V_47 -> V_48 = V_49 ;
V_47 -> V_93 = 0 ;
* V_80 = V_81 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_79 * V_94 )
{
struct V_45 * V_47 = F_40 ( V_94 ) ;
if ( F_46 ( V_6 , V_86 , V_47 -> V_50 . V_51 ,
V_95 ) ||
F_47 ( V_6 , V_87 , V_47 -> V_50 . V_46 . V_55 . V_8 ) ||
F_47 ( V_6 , V_88 , V_47 -> V_50 . V_46 . V_55 . V_7 ) ||
F_48 ( V_6 , V_90 , V_47 -> V_50 . V_10 ) ||
F_48 ( V_6 , V_89 , V_47 -> V_50 . V_11 ) ||
F_49 ( V_6 , V_91 , V_47 -> V_50 . V_92 ) )
return - V_32 ;
return 0 ;
}
static int F_50 ( struct V_79 * V_94 )
{
return F_51 ( 8 )
+ F_52 ( 4 )
+ F_52 ( 4 )
+ F_52 ( 1 )
+ F_52 ( 1 )
+ F_52 ( 2 ) ;
}
static int F_53 ( struct V_79 * V_96 , struct V_79 * V_97 )
{
return memcmp ( F_40 ( V_96 ) , F_40 ( V_97 ) ,
sizeof( struct V_45 ) ) ;
}
static int F_54 ( struct V_75 * V_76 ,
unsigned int V_77 , const void * V_78 ,
struct V_79 * * V_80 )
{
struct V_45 * V_47 ;
struct V_79 * V_81 ;
struct V_75 * V_82 [ V_98 + 1 ] ;
int V_21 ;
V_21 = F_38 ( V_82 , V_98 , V_76 , V_99 ) ;
if ( V_21 < 0 )
return V_21 ;
V_81 = F_39 ( sizeof( * V_47 ) ) ;
if ( ! V_81 )
return - V_32 ;
V_81 -> type = V_100 ;
V_47 = F_40 ( V_81 ) ;
if ( V_82 [ V_101 ] )
V_47 -> V_50 . V_51 = F_41 ( V_82 [ V_101 ] ) ;
if ( V_82 [ V_102 ] )
V_47 -> V_50 . V_46 . V_53 . V_8 = F_55 ( V_82 [ V_102 ] ) ;
if ( V_82 [ V_103 ] )
V_47 -> V_50 . V_46 . V_53 . V_7 = F_55 ( V_82 [ V_103 ] ) ;
if ( V_82 [ V_104 ] )
V_47 -> V_50 . V_11 = F_43 ( V_82 [ V_104 ] ) ;
if ( V_82 [ V_105 ] )
V_47 -> V_50 . V_10 = F_43 ( V_82 [ V_105 ] ) ;
if ( V_82 [ V_106 ] )
V_47 -> V_50 . V_92 = F_44 ( V_82 [ V_106 ] ) ;
V_47 -> V_48 = V_49 | V_52 ;
V_47 -> V_93 = 0 ;
* V_80 = V_81 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_79 * V_94 )
{
struct V_45 * V_47 = F_40 ( V_94 ) ;
if ( F_46 ( V_6 , V_101 , V_47 -> V_50 . V_51 ,
V_107 ) ||
F_57 ( V_6 , V_102 , & V_47 -> V_50 . V_46 . V_53 . V_8 ) ||
F_57 ( V_6 , V_103 , & V_47 -> V_50 . V_46 . V_53 . V_7 ) ||
F_48 ( V_6 , V_105 , V_47 -> V_50 . V_10 ) ||
F_48 ( V_6 , V_104 , V_47 -> V_50 . V_11 ) ||
F_49 ( V_6 , V_106 , V_47 -> V_50 . V_92 ) )
return - V_32 ;
return 0 ;
}
static int F_58 ( struct V_79 * V_94 )
{
return F_51 ( 8 )
+ F_52 ( 16 )
+ F_52 ( 16 )
+ F_52 ( 1 )
+ F_52 ( 1 )
+ F_52 ( 2 ) ;
}
void T_6 F_59 ( void )
{
F_60 ( V_108 != 255 ) ;
F_61 ( & V_109 , V_85 ) ;
F_61 ( & V_110 , V_100 ) ;
}
void F_62 ( void )
{
F_63 ( & V_111 ) ;
}
void F_64 ( void )
{
F_65 ( & V_111 ) ;
}
