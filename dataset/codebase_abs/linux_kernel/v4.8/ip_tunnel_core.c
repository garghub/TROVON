void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_2 V_9 ,
T_2 V_10 , T_2 V_11 , T_3 V_12 , bool V_13 )
{
int V_14 = V_6 -> V_15 - F_2 ( V_6 ) ;
struct V_16 * V_16 = F_3 ( V_4 -> V_8 . V_17 ) ;
struct V_18 * V_17 = V_6 -> V_17 ;
int V_19 = V_6 -> V_19 ;
struct V_20 * V_21 ;
int V_22 ;
F_4 ( V_6 , V_13 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 , & V_4 -> V_8 ) ;
memset ( F_7 ( V_6 ) , 0 , sizeof( * F_7 ( V_6 ) ) ) ;
if ( V_19 && ! ( V_12 & F_8 ( V_23 ) ) ) {
F_7 ( V_6 ) -> V_24 |= V_25 ;
}
F_9 ( V_6 , sizeof( struct V_20 ) ) ;
F_10 ( V_6 ) ;
V_21 = F_11 ( V_6 ) ;
V_21 -> V_26 = 4 ;
V_21 -> V_27 = sizeof( struct V_20 ) >> 2 ;
V_21 -> V_28 = V_12 ;
V_21 -> V_29 = V_9 ;
V_21 -> V_10 = V_10 ;
V_21 -> V_30 = V_8 ;
V_21 -> V_31 = V_7 ;
V_21 -> V_11 = V_11 ;
F_12 ( V_16 , V_21 , F_13 ( V_6 ) -> V_32 ? : 1 ) ;
V_22 = F_14 ( V_16 , V_2 , V_6 ) ;
if ( F_15 ( F_16 ( V_22 ) ) )
V_14 = 0 ;
F_17 ( V_17 , V_14 ) ;
}
int F_18 ( struct V_5 * V_6 , int V_33 ,
T_3 V_34 , bool V_35 , bool V_13 )
{
if ( F_15 ( ! F_19 ( V_6 , V_33 ) ) )
return - V_36 ;
F_20 ( V_6 , V_33 ) ;
if ( ! V_35 && V_34 == F_8 ( V_37 ) ) {
struct V_38 * V_39 ;
if ( F_15 ( ! F_19 ( V_6 , V_40 ) ) )
return - V_36 ;
V_39 = (struct V_38 * ) V_6 -> V_41 ;
if ( F_21 ( F_22 ( V_39 -> V_42 ) ) )
V_6 -> V_29 = V_39 -> V_42 ;
else
V_6 -> V_29 = F_8 ( V_43 ) ;
} else {
V_6 -> V_29 = V_34 ;
}
F_23 ( V_6 ) ;
V_6 -> V_44 = 0 ;
F_24 ( V_6 , 0 ) ;
F_4 ( V_6 , V_13 ) ;
return F_25 ( V_6 ) ;
}
struct V_45 * F_26 ( struct V_45 * V_46 ,
T_4 V_24 )
{
struct V_45 * V_47 ;
struct V_48 * V_8 , * V_7 ;
if ( ! V_46 || V_46 -> V_49 . V_50 . V_51 & V_52 )
return NULL ;
V_47 = F_27 ( 0 , V_24 ) ;
if ( ! V_47 )
return NULL ;
V_8 = & V_47 -> V_49 . V_50 ;
V_7 = & V_46 -> V_49 . V_50 ;
V_8 -> V_53 . V_54 = V_7 -> V_53 . V_54 ;
if ( V_7 -> V_51 & V_55 )
memcpy ( & V_8 -> V_53 . V_49 . V_56 . V_8 , & V_7 -> V_53 . V_49 . V_56 . V_7 ,
sizeof( struct V_57 ) ) ;
else
V_8 -> V_53 . V_49 . V_58 . V_8 = V_7 -> V_53 . V_49 . V_58 . V_7 ;
V_8 -> V_51 = V_7 -> V_51 | V_52 ;
return V_47 ;
}
int F_28 ( struct V_5 * V_6 ,
int V_59 )
{
int V_22 ;
if ( F_21 ( ! V_6 -> V_60 ) ) {
F_29 ( V_6 ) ;
V_6 -> V_60 = 1 ;
}
if ( F_30 ( V_6 ) ) {
V_22 = F_31 ( V_6 , V_61 ) ;
if ( F_15 ( V_22 ) )
return V_22 ;
F_13 ( V_6 ) -> V_62 |= V_59 ;
return 0 ;
}
if ( V_6 -> V_63 != V_64 ) {
V_6 -> V_63 = V_65 ;
V_6 -> V_60 = 0 ;
}
return 0 ;
}
struct V_66 * F_32 ( struct V_18 * V_17 ,
struct V_66 * V_67 )
{
int V_68 ;
F_33 ( V_67 , & V_17 -> V_69 ) ;
F_34 (i) {
const struct V_70 * V_71 =
F_35 ( V_17 -> V_71 , V_68 ) ;
T_5 V_72 , V_73 , V_74 , V_75 ;
unsigned int V_76 ;
do {
V_76 = F_36 ( & V_71 -> V_77 ) ;
V_72 = V_71 -> V_72 ;
V_74 = V_71 -> V_74 ;
V_73 = V_71 -> V_73 ;
V_75 = V_71 -> V_75 ;
} while ( F_37 ( & V_71 -> V_77 , V_76 ) );
V_67 -> V_72 += V_72 ;
V_67 -> V_74 += V_74 ;
V_67 -> V_73 += V_73 ;
V_67 -> V_75 += V_75 ;
}
return V_67 ;
}
static int F_38 ( struct V_18 * V_17 , struct V_78 * V_79 ,
unsigned int V_80 , const void * V_81 ,
struct V_82 * * V_83 )
{
struct V_48 * V_50 ;
struct V_82 * V_84 ;
struct V_78 * V_85 [ V_86 + 1 ] ;
int V_22 ;
V_22 = F_39 ( V_85 , V_86 , V_79 , V_87 ) ;
if ( V_22 < 0 )
return V_22 ;
V_84 = F_40 ( sizeof( * V_50 ) ) ;
if ( ! V_84 )
return - V_36 ;
V_84 -> type = V_88 ;
V_50 = F_41 ( V_84 ) ;
if ( V_85 [ V_89 ] )
V_50 -> V_53 . V_54 = F_42 ( V_85 [ V_89 ] ) ;
if ( V_85 [ V_90 ] )
V_50 -> V_53 . V_49 . V_58 . V_8 = F_43 ( V_85 [ V_90 ] ) ;
if ( V_85 [ V_91 ] )
V_50 -> V_53 . V_49 . V_58 . V_7 = F_43 ( V_85 [ V_91 ] ) ;
if ( V_85 [ V_92 ] )
V_50 -> V_53 . V_11 = F_44 ( V_85 [ V_92 ] ) ;
if ( V_85 [ V_93 ] )
V_50 -> V_53 . V_10 = F_44 ( V_85 [ V_93 ] ) ;
if ( V_85 [ V_94 ] )
V_50 -> V_53 . V_95 = F_45 ( V_85 [ V_94 ] ) ;
V_50 -> V_51 = V_52 ;
V_50 -> V_96 = 0 ;
* V_83 = V_84 ;
return 0 ;
}
static int F_46 ( struct V_5 * V_6 ,
struct V_82 * V_97 )
{
struct V_48 * V_50 = F_41 ( V_97 ) ;
if ( F_47 ( V_6 , V_89 , V_50 -> V_53 . V_54 ,
V_98 ) ||
F_48 ( V_6 , V_90 , V_50 -> V_53 . V_49 . V_58 . V_8 ) ||
F_48 ( V_6 , V_91 , V_50 -> V_53 . V_49 . V_58 . V_7 ) ||
F_49 ( V_6 , V_93 , V_50 -> V_53 . V_10 ) ||
F_49 ( V_6 , V_92 , V_50 -> V_53 . V_11 ) ||
F_50 ( V_6 , V_94 , V_50 -> V_53 . V_95 ) )
return - V_36 ;
return 0 ;
}
static int F_51 ( struct V_82 * V_97 )
{
return F_52 ( 8 )
+ F_53 ( 4 )
+ F_53 ( 4 )
+ F_53 ( 1 )
+ F_53 ( 1 )
+ F_53 ( 2 ) ;
}
static int F_54 ( struct V_82 * V_99 , struct V_82 * V_100 )
{
return memcmp ( F_41 ( V_99 ) , F_41 ( V_100 ) ,
sizeof( struct V_48 ) ) ;
}
static int F_55 ( struct V_18 * V_17 , struct V_78 * V_79 ,
unsigned int V_80 , const void * V_81 ,
struct V_82 * * V_83 )
{
struct V_48 * V_50 ;
struct V_82 * V_84 ;
struct V_78 * V_85 [ V_101 + 1 ] ;
int V_22 ;
V_22 = F_39 ( V_85 , V_101 , V_79 , V_102 ) ;
if ( V_22 < 0 )
return V_22 ;
V_84 = F_40 ( sizeof( * V_50 ) ) ;
if ( ! V_84 )
return - V_36 ;
V_84 -> type = V_103 ;
V_50 = F_41 ( V_84 ) ;
if ( V_85 [ V_104 ] )
V_50 -> V_53 . V_54 = F_42 ( V_85 [ V_104 ] ) ;
if ( V_85 [ V_105 ] )
V_50 -> V_53 . V_49 . V_56 . V_8 = F_56 ( V_85 [ V_105 ] ) ;
if ( V_85 [ V_106 ] )
V_50 -> V_53 . V_49 . V_56 . V_7 = F_56 ( V_85 [ V_106 ] ) ;
if ( V_85 [ V_107 ] )
V_50 -> V_53 . V_11 = F_44 ( V_85 [ V_107 ] ) ;
if ( V_85 [ V_108 ] )
V_50 -> V_53 . V_10 = F_44 ( V_85 [ V_108 ] ) ;
if ( V_85 [ V_109 ] )
V_50 -> V_53 . V_95 = F_45 ( V_85 [ V_109 ] ) ;
V_50 -> V_51 = V_52 | V_55 ;
V_50 -> V_96 = 0 ;
* V_83 = V_84 ;
return 0 ;
}
static int F_57 ( struct V_5 * V_6 ,
struct V_82 * V_97 )
{
struct V_48 * V_50 = F_41 ( V_97 ) ;
if ( F_47 ( V_6 , V_104 , V_50 -> V_53 . V_54 ,
V_110 ) ||
F_58 ( V_6 , V_105 , & V_50 -> V_53 . V_49 . V_56 . V_8 ) ||
F_58 ( V_6 , V_106 , & V_50 -> V_53 . V_49 . V_56 . V_7 ) ||
F_49 ( V_6 , V_108 , V_50 -> V_53 . V_10 ) ||
F_49 ( V_6 , V_107 , V_50 -> V_53 . V_11 ) ||
F_50 ( V_6 , V_109 , V_50 -> V_53 . V_95 ) )
return - V_36 ;
return 0 ;
}
static int F_59 ( struct V_82 * V_97 )
{
return F_52 ( 8 )
+ F_53 ( 16 )
+ F_53 ( 16 )
+ F_53 ( 1 )
+ F_53 ( 1 )
+ F_53 ( 2 ) ;
}
void T_6 F_60 ( void )
{
F_61 ( V_111 != 255 ) ;
F_62 ( & V_112 , V_88 ) ;
F_62 ( & V_113 , V_103 ) ;
}
void F_63 ( void )
{
F_64 ( & V_114 ) ;
}
void F_65 ( void )
{
F_66 ( & V_114 ) ;
}
