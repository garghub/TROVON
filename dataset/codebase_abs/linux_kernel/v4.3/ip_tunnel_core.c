int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_2 V_9 ,
T_2 V_10 , T_2 V_11 , T_3 V_12 , bool V_13 )
{
int V_14 = V_6 -> V_15 - F_2 ( V_6 ) ;
struct V_16 * V_17 ;
int V_18 ;
F_3 ( V_6 , V_13 ) ;
F_4 ( V_6 ) ;
F_5 ( V_6 , & V_4 -> V_8 ) ;
memset ( F_6 ( V_6 ) , 0 , sizeof( * F_6 ( V_6 ) ) ) ;
F_7 ( V_6 , sizeof( struct V_16 ) ) ;
F_8 ( V_6 ) ;
V_17 = F_9 ( V_6 ) ;
V_17 -> V_19 = 4 ;
V_17 -> V_20 = sizeof( struct V_16 ) >> 2 ;
V_17 -> V_21 = V_12 ;
V_17 -> V_22 = V_9 ;
V_17 -> V_10 = V_10 ;
V_17 -> V_23 = V_8 ;
V_17 -> V_24 = V_7 ;
V_17 -> V_11 = V_11 ;
F_10 ( F_11 ( V_4 -> V_8 . V_25 ) , V_17 ,
F_12 ( V_6 ) -> V_26 ? : 1 ) ;
V_18 = F_13 ( V_2 , V_6 ) ;
if ( F_14 ( F_15 ( V_18 ) ) )
V_14 = 0 ;
return V_14 ;
}
int F_16 ( struct V_5 * V_6 , int V_27 , T_3 V_28 )
{
if ( F_14 ( ! F_17 ( V_6 , V_27 ) ) )
return - V_29 ;
F_18 ( V_6 , V_27 ) ;
if ( V_28 == F_19 ( V_30 ) ) {
struct V_31 * V_32 ;
if ( F_14 ( ! F_17 ( V_6 , V_33 ) ) )
return - V_29 ;
V_32 = (struct V_31 * ) V_6 -> V_34 ;
if ( F_20 ( F_21 ( V_32 -> V_35 ) ) )
V_6 -> V_22 = V_32 -> V_35 ;
else
V_6 -> V_22 = F_19 ( V_36 ) ;
} else {
V_6 -> V_22 = V_28 ;
}
F_22 ( V_6 ) ;
F_23 ( V_6 ) ;
F_24 ( V_6 ) ;
F_25 ( V_6 ) ;
V_6 -> V_37 = 0 ;
F_26 ( V_6 , 0 ) ;
V_6 -> V_38 = V_39 ;
return 0 ;
}
struct V_40 * F_27 ( struct V_40 * V_41 ,
T_4 V_42 )
{
struct V_40 * V_43 ;
struct V_44 * V_8 , * V_7 ;
if ( ! V_41 || V_41 -> V_45 . V_46 . V_47 & V_48 )
return NULL ;
V_43 = F_28 ( 0 , V_42 ) ;
if ( ! V_43 )
return NULL ;
V_8 = & V_43 -> V_45 . V_46 ;
V_7 = & V_41 -> V_45 . V_46 ;
V_8 -> V_49 . V_50 = V_7 -> V_49 . V_50 ;
if ( V_7 -> V_47 & V_51 )
memcpy ( & V_8 -> V_49 . V_45 . V_52 . V_8 , & V_7 -> V_49 . V_45 . V_52 . V_7 ,
sizeof( struct V_53 ) ) ;
else
V_8 -> V_49 . V_45 . V_54 . V_8 = V_7 -> V_49 . V_45 . V_54 . V_7 ;
V_8 -> V_47 = V_7 -> V_47 | V_48 ;
return V_43 ;
}
struct V_5 * F_29 ( struct V_5 * V_6 ,
bool V_55 ,
int V_56 )
{
int V_18 ;
if ( F_20 ( ! V_6 -> V_57 ) ) {
F_30 ( V_6 ) ;
V_6 -> V_57 = 1 ;
}
if ( F_31 ( V_6 ) ) {
V_18 = F_32 ( V_6 , V_58 ) ;
if ( F_14 ( V_18 ) )
goto error;
F_12 ( V_6 ) -> V_59 |= V_56 ;
return V_6 ;
}
if ( V_55 )
V_6 -> V_57 = 0 ;
if ( V_6 -> V_60 == V_61 && V_55 ) {
V_18 = F_33 ( V_6 ) ;
if ( F_14 ( V_18 ) )
goto error;
} else if ( V_6 -> V_60 != V_61 )
V_6 -> V_60 = V_62 ;
return V_6 ;
error:
F_34 ( V_6 ) ;
return F_35 ( V_18 ) ;
}
struct V_63 * F_36 ( struct V_64 * V_25 ,
struct V_63 * V_65 )
{
int V_66 ;
F_37 ( V_65 , & V_25 -> V_67 ) ;
F_38 (i) {
const struct V_68 * V_69 =
F_39 ( V_25 -> V_69 , V_66 ) ;
T_5 V_70 , V_71 , V_72 , V_73 ;
unsigned int V_74 ;
do {
V_74 = F_40 ( & V_69 -> V_75 ) ;
V_70 = V_69 -> V_70 ;
V_72 = V_69 -> V_72 ;
V_71 = V_69 -> V_71 ;
V_73 = V_69 -> V_73 ;
} while ( F_41 ( & V_69 -> V_75 , V_74 ) );
V_65 -> V_70 += V_70 ;
V_65 -> V_72 += V_72 ;
V_65 -> V_71 += V_71 ;
V_65 -> V_73 += V_73 ;
}
return V_65 ;
}
static int F_42 ( struct V_64 * V_25 , struct V_76 * V_77 ,
unsigned int V_78 , const void * V_79 ,
struct V_80 * * V_81 )
{
struct V_44 * V_46 ;
struct V_80 * V_82 ;
struct V_76 * V_83 [ V_84 + 1 ] ;
int V_18 ;
V_18 = F_43 ( V_83 , V_84 , V_77 , V_85 ) ;
if ( V_18 < 0 )
return V_18 ;
V_82 = F_44 ( sizeof( * V_46 ) ) ;
if ( ! V_82 )
return - V_29 ;
V_82 -> type = V_86 ;
V_46 = F_45 ( V_82 ) ;
if ( V_83 [ V_87 ] )
V_46 -> V_49 . V_50 = F_46 ( V_83 [ V_87 ] ) ;
if ( V_83 [ V_88 ] )
V_46 -> V_49 . V_45 . V_54 . V_8 = F_47 ( V_83 [ V_88 ] ) ;
if ( V_83 [ V_89 ] )
V_46 -> V_49 . V_45 . V_54 . V_7 = F_47 ( V_83 [ V_89 ] ) ;
if ( V_83 [ V_90 ] )
V_46 -> V_49 . V_11 = F_48 ( V_83 [ V_90 ] ) ;
if ( V_83 [ V_91 ] )
V_46 -> V_49 . V_10 = F_48 ( V_83 [ V_91 ] ) ;
if ( V_83 [ V_92 ] )
V_46 -> V_49 . V_93 = F_49 ( V_83 [ V_92 ] ) ;
V_46 -> V_47 = V_48 ;
V_46 -> V_94 = 0 ;
* V_81 = V_82 ;
return 0 ;
}
static int F_50 ( struct V_5 * V_6 ,
struct V_80 * V_95 )
{
struct V_44 * V_46 = F_45 ( V_95 ) ;
if ( F_51 ( V_6 , V_87 , V_46 -> V_49 . V_50 ) ||
F_52 ( V_6 , V_88 , V_46 -> V_49 . V_45 . V_54 . V_8 ) ||
F_52 ( V_6 , V_89 , V_46 -> V_49 . V_45 . V_54 . V_7 ) ||
F_53 ( V_6 , V_91 , V_46 -> V_49 . V_10 ) ||
F_53 ( V_6 , V_90 , V_46 -> V_49 . V_11 ) ||
F_54 ( V_6 , V_92 , V_46 -> V_49 . V_93 ) )
return - V_29 ;
return 0 ;
}
static int F_55 ( struct V_80 * V_95 )
{
return F_56 ( 8 )
+ F_56 ( 4 )
+ F_56 ( 4 )
+ F_56 ( 1 )
+ F_56 ( 1 )
+ F_56 ( 2 ) ;
}
static int F_57 ( struct V_80 * V_96 , struct V_80 * V_97 )
{
return memcmp ( F_45 ( V_96 ) , F_45 ( V_97 ) ,
sizeof( struct V_44 ) ) ;
}
static int F_58 ( struct V_64 * V_25 , struct V_76 * V_77 ,
unsigned int V_78 , const void * V_79 ,
struct V_80 * * V_81 )
{
struct V_44 * V_46 ;
struct V_80 * V_82 ;
struct V_76 * V_83 [ V_98 + 1 ] ;
int V_18 ;
V_18 = F_43 ( V_83 , V_98 , V_77 , V_99 ) ;
if ( V_18 < 0 )
return V_18 ;
V_82 = F_44 ( sizeof( * V_46 ) ) ;
if ( ! V_82 )
return - V_29 ;
V_82 -> type = V_100 ;
V_46 = F_45 ( V_82 ) ;
if ( V_83 [ V_101 ] )
V_46 -> V_49 . V_50 = F_46 ( V_83 [ V_101 ] ) ;
if ( V_83 [ V_102 ] )
V_46 -> V_49 . V_45 . V_52 . V_8 = F_59 ( V_83 [ V_102 ] ) ;
if ( V_83 [ V_103 ] )
V_46 -> V_49 . V_45 . V_52 . V_7 = F_59 ( V_83 [ V_103 ] ) ;
if ( V_83 [ V_104 ] )
V_46 -> V_49 . V_11 = F_48 ( V_83 [ V_104 ] ) ;
if ( V_83 [ V_105 ] )
V_46 -> V_49 . V_10 = F_48 ( V_83 [ V_105 ] ) ;
if ( V_83 [ V_106 ] )
V_46 -> V_49 . V_93 = F_49 ( V_83 [ V_106 ] ) ;
V_46 -> V_47 = V_48 | V_51 ;
V_46 -> V_94 = 0 ;
* V_81 = V_82 ;
return 0 ;
}
static int F_60 ( struct V_5 * V_6 ,
struct V_80 * V_95 )
{
struct V_44 * V_46 = F_45 ( V_95 ) ;
if ( F_51 ( V_6 , V_101 , V_46 -> V_49 . V_50 ) ||
F_61 ( V_6 , V_102 , & V_46 -> V_49 . V_45 . V_52 . V_8 ) ||
F_61 ( V_6 , V_103 , & V_46 -> V_49 . V_45 . V_52 . V_7 ) ||
F_53 ( V_6 , V_104 , V_46 -> V_49 . V_10 ) ||
F_53 ( V_6 , V_105 , V_46 -> V_49 . V_11 ) ||
F_54 ( V_6 , V_106 , V_46 -> V_49 . V_93 ) )
return - V_29 ;
return 0 ;
}
static int F_62 ( struct V_80 * V_95 )
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
F_64 ( & V_107 , V_86 ) ;
F_64 ( & V_108 , V_100 ) ;
}
void F_65 ( void )
{
F_66 ( & V_109 ) ;
}
void F_67 ( void )
{
F_68 ( & V_109 ) ;
}
