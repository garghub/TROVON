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
if ( ! V_42 || V_42 -> type != V_46 ||
V_42 -> V_47 . V_48 . V_49 & V_50 )
return NULL ;
V_44 = F_26 ( 0 , V_46 , V_43 ) ;
if ( ! V_44 )
return NULL ;
V_8 = & V_44 -> V_47 . V_48 ;
V_7 = & V_42 -> V_47 . V_48 ;
V_8 -> V_51 . V_52 = V_7 -> V_51 . V_52 ;
if ( V_7 -> V_49 & V_53 )
memcpy ( & V_8 -> V_51 . V_47 . V_54 . V_8 , & V_7 -> V_51 . V_47 . V_54 . V_7 ,
sizeof( struct V_55 ) ) ;
else
V_8 -> V_51 . V_47 . V_56 . V_8 = V_7 -> V_51 . V_47 . V_56 . V_7 ;
V_8 -> V_49 = V_7 -> V_49 | V_50 ;
return V_44 ;
}
int F_27 ( struct V_5 * V_6 ,
int V_57 )
{
int V_21 ;
if ( F_21 ( ! V_6 -> V_58 ) ) {
F_28 ( V_6 ) ;
V_6 -> V_58 = 1 ;
}
if ( F_29 ( V_6 ) ) {
V_21 = F_30 ( V_6 , V_59 ) ;
if ( F_14 ( V_21 ) )
return V_21 ;
F_12 ( V_6 ) -> V_60 |= V_57 ;
return 0 ;
}
if ( V_6 -> V_61 != V_62 ) {
V_6 -> V_61 = V_63 ;
V_6 -> V_58 = 0 ;
}
return 0 ;
}
void F_31 ( struct V_18 * V_17 ,
struct V_64 * V_65 )
{
int V_66 ;
F_32 ( V_65 , & V_17 -> V_67 ) ;
F_33 (i) {
const struct V_68 * V_69 =
F_34 ( V_17 -> V_69 , V_66 ) ;
T_5 V_70 , V_71 , V_72 , V_73 ;
unsigned int V_74 ;
do {
V_74 = F_35 ( & V_69 -> V_75 ) ;
V_70 = V_69 -> V_70 ;
V_72 = V_69 -> V_72 ;
V_71 = V_69 -> V_71 ;
V_73 = V_69 -> V_73 ;
} while ( F_36 ( & V_69 -> V_75 , V_74 ) );
V_65 -> V_70 += V_70 ;
V_65 -> V_72 += V_72 ;
V_65 -> V_71 += V_71 ;
V_65 -> V_73 += V_73 ;
}
}
static int F_37 ( struct V_76 * V_77 ,
unsigned int V_78 , const void * V_79 ,
struct V_80 * * V_81 ,
struct V_82 * V_83 )
{
struct V_45 * V_48 ;
struct V_80 * V_84 ;
struct V_76 * V_85 [ V_86 + 1 ] ;
int V_21 ;
V_21 = F_38 ( V_85 , V_86 , V_77 , V_87 ,
V_83 ) ;
if ( V_21 < 0 )
return V_21 ;
V_84 = F_39 ( sizeof( * V_48 ) ) ;
if ( ! V_84 )
return - V_32 ;
V_84 -> type = V_88 ;
V_48 = F_40 ( V_84 ) ;
if ( V_85 [ V_89 ] )
V_48 -> V_51 . V_52 = F_41 ( V_85 [ V_89 ] ) ;
if ( V_85 [ V_90 ] )
V_48 -> V_51 . V_47 . V_56 . V_8 = F_42 ( V_85 [ V_90 ] ) ;
if ( V_85 [ V_91 ] )
V_48 -> V_51 . V_47 . V_56 . V_7 = F_42 ( V_85 [ V_91 ] ) ;
if ( V_85 [ V_92 ] )
V_48 -> V_51 . V_11 = F_43 ( V_85 [ V_92 ] ) ;
if ( V_85 [ V_93 ] )
V_48 -> V_51 . V_10 = F_43 ( V_85 [ V_93 ] ) ;
if ( V_85 [ V_94 ] )
V_48 -> V_51 . V_95 = F_44 ( V_85 [ V_94 ] ) ;
V_48 -> V_49 = V_50 ;
V_48 -> V_96 = 0 ;
* V_81 = V_84 ;
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_80 * V_97 )
{
struct V_45 * V_48 = F_40 ( V_97 ) ;
if ( F_46 ( V_6 , V_89 , V_48 -> V_51 . V_52 ,
V_98 ) ||
F_47 ( V_6 , V_90 , V_48 -> V_51 . V_47 . V_56 . V_8 ) ||
F_47 ( V_6 , V_91 , V_48 -> V_51 . V_47 . V_56 . V_7 ) ||
F_48 ( V_6 , V_93 , V_48 -> V_51 . V_10 ) ||
F_48 ( V_6 , V_92 , V_48 -> V_51 . V_11 ) ||
F_49 ( V_6 , V_94 , V_48 -> V_51 . V_95 ) )
return - V_32 ;
return 0 ;
}
static int F_50 ( struct V_80 * V_97 )
{
return F_51 ( 8 )
+ F_52 ( 4 )
+ F_52 ( 4 )
+ F_52 ( 1 )
+ F_52 ( 1 )
+ F_52 ( 2 ) ;
}
static int F_53 ( struct V_80 * V_99 , struct V_80 * V_100 )
{
return memcmp ( F_40 ( V_99 ) , F_40 ( V_100 ) ,
sizeof( struct V_45 ) ) ;
}
static int F_54 ( struct V_76 * V_77 ,
unsigned int V_78 , const void * V_79 ,
struct V_80 * * V_81 ,
struct V_82 * V_83 )
{
struct V_45 * V_48 ;
struct V_80 * V_84 ;
struct V_76 * V_85 [ V_101 + 1 ] ;
int V_21 ;
V_21 = F_38 ( V_85 , V_101 , V_77 , V_102 ,
V_83 ) ;
if ( V_21 < 0 )
return V_21 ;
V_84 = F_39 ( sizeof( * V_48 ) ) ;
if ( ! V_84 )
return - V_32 ;
V_84 -> type = V_103 ;
V_48 = F_40 ( V_84 ) ;
if ( V_85 [ V_104 ] )
V_48 -> V_51 . V_52 = F_41 ( V_85 [ V_104 ] ) ;
if ( V_85 [ V_105 ] )
V_48 -> V_51 . V_47 . V_54 . V_8 = F_55 ( V_85 [ V_105 ] ) ;
if ( V_85 [ V_106 ] )
V_48 -> V_51 . V_47 . V_54 . V_7 = F_55 ( V_85 [ V_106 ] ) ;
if ( V_85 [ V_107 ] )
V_48 -> V_51 . V_11 = F_43 ( V_85 [ V_107 ] ) ;
if ( V_85 [ V_108 ] )
V_48 -> V_51 . V_10 = F_43 ( V_85 [ V_108 ] ) ;
if ( V_85 [ V_109 ] )
V_48 -> V_51 . V_95 = F_44 ( V_85 [ V_109 ] ) ;
V_48 -> V_49 = V_50 | V_53 ;
V_48 -> V_96 = 0 ;
* V_81 = V_84 ;
return 0 ;
}
static int F_56 ( struct V_5 * V_6 ,
struct V_80 * V_97 )
{
struct V_45 * V_48 = F_40 ( V_97 ) ;
if ( F_46 ( V_6 , V_104 , V_48 -> V_51 . V_52 ,
V_110 ) ||
F_57 ( V_6 , V_105 , & V_48 -> V_51 . V_47 . V_54 . V_8 ) ||
F_57 ( V_6 , V_106 , & V_48 -> V_51 . V_47 . V_54 . V_7 ) ||
F_48 ( V_6 , V_108 , V_48 -> V_51 . V_10 ) ||
F_48 ( V_6 , V_107 , V_48 -> V_51 . V_11 ) ||
F_49 ( V_6 , V_109 , V_48 -> V_51 . V_95 ) )
return - V_32 ;
return 0 ;
}
static int F_58 ( struct V_80 * V_97 )
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
F_60 ( V_111 != 255 ) ;
F_61 ( & V_112 , V_88 ) ;
F_61 ( & V_113 , V_103 ) ;
}
void F_62 ( void )
{
F_63 ( & V_114 ) ;
}
void F_64 ( void )
{
F_65 ( & V_114 ) ;
}
