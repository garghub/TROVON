int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_2 V_9 ,
T_2 V_10 , T_2 V_11 , T_3 V_12 , bool V_13 )
{
int V_14 = V_6 -> V_15 - F_2 ( V_6 ) ;
struct V_16 * V_16 = F_3 ( V_4 -> V_8 . V_17 ) ;
struct V_18 * V_19 ;
int V_20 ;
F_4 ( V_6 , V_13 ) ;
F_5 ( V_6 ) ;
F_6 ( V_6 , & V_4 -> V_8 ) ;
memset ( F_7 ( V_6 ) , 0 , sizeof( * F_7 ( V_6 ) ) ) ;
F_8 ( V_6 , sizeof( struct V_18 ) ) ;
F_9 ( V_6 ) ;
V_19 = F_10 ( V_6 ) ;
V_19 -> V_21 = 4 ;
V_19 -> V_22 = sizeof( struct V_18 ) >> 2 ;
V_19 -> V_23 = V_12 ;
V_19 -> V_24 = V_9 ;
V_19 -> V_10 = V_10 ;
V_19 -> V_25 = V_8 ;
V_19 -> V_26 = V_7 ;
V_19 -> V_11 = V_11 ;
F_11 ( V_16 , V_19 , F_12 ( V_6 ) -> V_27 ? : 1 ) ;
V_20 = F_13 ( V_16 , V_2 , V_6 ) ;
if ( F_14 ( F_15 ( V_20 ) ) )
V_14 = 0 ;
return V_14 ;
}
int F_16 ( struct V_5 * V_6 , int V_28 , T_3 V_29 )
{
if ( F_14 ( ! F_17 ( V_6 , V_28 ) ) )
return - V_30 ;
F_18 ( V_6 , V_28 ) ;
if ( V_29 == F_19 ( V_31 ) ) {
struct V_32 * V_33 ;
if ( F_14 ( ! F_17 ( V_6 , V_34 ) ) )
return - V_30 ;
V_33 = (struct V_32 * ) V_6 -> V_35 ;
if ( F_20 ( F_21 ( V_33 -> V_36 ) ) )
V_6 -> V_24 = V_33 -> V_36 ;
else
V_6 -> V_24 = F_19 ( V_37 ) ;
} else {
V_6 -> V_24 = V_29 ;
}
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
V_6 -> V_38 = 0 ;
F_26 ( V_6 , 0 ) ;
V_6 -> V_39 = V_40 ;
return 0 ;
}
struct V_41 * F_27 ( struct V_41 * V_42 ,
T_4 V_43 )
{
struct V_41 * V_44 ;
struct V_45 * V_8 , * V_7 ;
if ( ! V_42 || V_42 -> V_46 . V_47 . V_48 & V_49 )
return NULL ;
V_44 = F_28 ( 0 , V_43 ) ;
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
struct V_5 * F_29 ( struct V_5 * V_6 ,
bool V_56 ,
int V_57 )
{
int V_20 ;
if ( F_20 ( ! V_6 -> V_58 ) ) {
F_30 ( V_6 ) ;
V_6 -> V_58 = 1 ;
}
if ( F_31 ( V_6 ) ) {
V_20 = F_32 ( V_6 , V_59 ) ;
if ( F_14 ( V_20 ) )
goto error;
F_12 ( V_6 ) -> V_60 |= V_57 ;
return V_6 ;
}
if ( V_56 )
V_6 -> V_58 = 0 ;
if ( V_6 -> V_61 == V_62 && V_56 ) {
V_20 = F_33 ( V_6 ) ;
if ( F_14 ( V_20 ) )
goto error;
} else if ( V_6 -> V_61 != V_62 )
V_6 -> V_61 = V_63 ;
return V_6 ;
error:
F_34 ( V_6 ) ;
return F_35 ( V_20 ) ;
}
struct V_64 * F_36 ( struct V_65 * V_17 ,
struct V_64 * V_66 )
{
int V_67 ;
F_37 ( V_66 , & V_17 -> V_68 ) ;
F_38 (i) {
const struct V_69 * V_70 =
F_39 ( V_17 -> V_70 , V_67 ) ;
T_5 V_71 , V_72 , V_73 , V_74 ;
unsigned int V_75 ;
do {
V_75 = F_40 ( & V_70 -> V_76 ) ;
V_71 = V_70 -> V_71 ;
V_73 = V_70 -> V_73 ;
V_72 = V_70 -> V_72 ;
V_74 = V_70 -> V_74 ;
} while ( F_41 ( & V_70 -> V_76 , V_75 ) );
V_66 -> V_71 += V_71 ;
V_66 -> V_73 += V_73 ;
V_66 -> V_72 += V_72 ;
V_66 -> V_74 += V_74 ;
}
return V_66 ;
}
static int F_42 ( struct V_65 * V_17 , struct V_77 * V_78 ,
unsigned int V_79 , const void * V_80 ,
struct V_81 * * V_82 )
{
struct V_45 * V_47 ;
struct V_81 * V_83 ;
struct V_77 * V_84 [ V_85 + 1 ] ;
int V_20 ;
V_20 = F_43 ( V_84 , V_85 , V_78 , V_86 ) ;
if ( V_20 < 0 )
return V_20 ;
V_83 = F_44 ( sizeof( * V_47 ) ) ;
if ( ! V_83 )
return - V_30 ;
V_83 -> type = V_87 ;
V_47 = F_45 ( V_83 ) ;
if ( V_84 [ V_88 ] )
V_47 -> V_50 . V_51 = F_46 ( V_84 [ V_88 ] ) ;
if ( V_84 [ V_89 ] )
V_47 -> V_50 . V_46 . V_55 . V_8 = F_47 ( V_84 [ V_89 ] ) ;
if ( V_84 [ V_90 ] )
V_47 -> V_50 . V_46 . V_55 . V_7 = F_47 ( V_84 [ V_90 ] ) ;
if ( V_84 [ V_91 ] )
V_47 -> V_50 . V_11 = F_48 ( V_84 [ V_91 ] ) ;
if ( V_84 [ V_92 ] )
V_47 -> V_50 . V_10 = F_48 ( V_84 [ V_92 ] ) ;
if ( V_84 [ V_93 ] )
V_47 -> V_50 . V_94 = F_49 ( V_84 [ V_93 ] ) ;
V_47 -> V_48 = V_49 ;
V_47 -> V_95 = 0 ;
* V_82 = V_83 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_81 * V_96 )
{
struct V_45 * V_47 = F_45 ( V_96 ) ;
if ( F_51 ( V_6 , V_88 , V_47 -> V_50 . V_51 ) ||
F_52 ( V_6 , V_89 , V_47 -> V_50 . V_46 . V_55 . V_8 ) ||
F_52 ( V_6 , V_90 , V_47 -> V_50 . V_46 . V_55 . V_7 ) ||
F_53 ( V_6 , V_92 , V_47 -> V_50 . V_10 ) ||
F_53 ( V_6 , V_91 , V_47 -> V_50 . V_11 ) ||
F_54 ( V_6 , V_93 , V_47 -> V_50 . V_94 ) )
return - V_30 ;
return 0 ;
}
static int F_55 ( struct V_81 * V_96 )
{
return F_56 ( 8 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( 1 )
+ F_56 ( 1 )
+ F_56 ( 2 ) ;
}
static int F_57 ( struct V_81 * V_97 , struct V_81 * V_98 )
{
return memcmp ( F_45 ( V_97 ) , F_45 ( V_98 ) ,
sizeof( struct V_45 ) ) ;
}
static int F_58 ( struct V_65 * V_17 , struct V_77 * V_78 ,
unsigned int V_79 , const void * V_80 ,
struct V_81 * * V_82 )
{
struct V_45 * V_47 ;
struct V_81 * V_83 ;
struct V_77 * V_84 [ V_99 + 1 ] ;
int V_20 ;
V_20 = F_43 ( V_84 , V_99 , V_78 , V_100 ) ;
if ( V_20 < 0 )
return V_20 ;
V_83 = F_44 ( sizeof( * V_47 ) ) ;
if ( ! V_83 )
return - V_30 ;
V_83 -> type = V_101 ;
V_47 = F_45 ( V_83 ) ;
if ( V_84 [ V_102 ] )
V_47 -> V_50 . V_51 = F_46 ( V_84 [ V_102 ] ) ;
if ( V_84 [ V_103 ] )
V_47 -> V_50 . V_46 . V_53 . V_8 = F_59 ( V_84 [ V_103 ] ) ;
if ( V_84 [ V_104 ] )
V_47 -> V_50 . V_46 . V_53 . V_7 = F_59 ( V_84 [ V_104 ] ) ;
if ( V_84 [ V_105 ] )
V_47 -> V_50 . V_11 = F_48 ( V_84 [ V_105 ] ) ;
if ( V_84 [ V_106 ] )
V_47 -> V_50 . V_10 = F_48 ( V_84 [ V_106 ] ) ;
if ( V_84 [ V_107 ] )
V_47 -> V_50 . V_94 = F_49 ( V_84 [ V_107 ] ) ;
V_47 -> V_48 = V_49 | V_52 ;
V_47 -> V_95 = 0 ;
* V_82 = V_83 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_81 * V_96 )
{
struct V_45 * V_47 = F_45 ( V_96 ) ;
if ( F_51 ( V_6 , V_102 , V_47 -> V_50 . V_51 ) ||
F_61 ( V_6 , V_103 , & V_47 -> V_50 . V_46 . V_53 . V_8 ) ||
F_61 ( V_6 , V_104 , & V_47 -> V_50 . V_46 . V_53 . V_7 ) ||
F_53 ( V_6 , V_105 , V_47 -> V_50 . V_10 ) ||
F_53 ( V_6 , V_106 , V_47 -> V_50 . V_11 ) ||
F_54 ( V_6 , V_107 , V_47 -> V_50 . V_94 ) )
return - V_30 ;
return 0 ;
}
static int F_62 ( struct V_81 * V_96 )
{
return F_56 ( 8 )
+ F_56 ( 16 )
+ F_56 ( 16 )
+ F_56 ( 1 )
+ F_56 ( 1 )
+ F_56 ( 2 ) ;
}
void T_6 F_63 ( void )
{
F_64 ( & V_108 , V_87 ) ;
F_64 ( & V_109 , V_101 ) ;
}
void F_65 ( void )
{
F_66 ( & V_110 ) ;
}
void F_67 ( void )
{
F_68 ( & V_110 ) ;
}
