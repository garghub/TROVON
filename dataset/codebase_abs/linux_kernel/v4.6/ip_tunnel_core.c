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
int F_17 ( struct V_5 * V_6 , int V_29 , T_3 V_30 ,
bool V_13 )
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
V_6 -> V_39 = 0 ;
F_24 ( V_6 , 0 ) ;
F_4 ( V_6 , V_13 ) ;
return F_25 ( V_6 ) ;
}
struct V_40 * F_26 ( struct V_40 * V_41 ,
T_4 V_42 )
{
struct V_40 * V_43 ;
struct V_44 * V_8 , * V_7 ;
if ( ! V_41 || V_41 -> V_45 . V_46 . V_47 & V_48 )
return NULL ;
V_43 = F_27 ( 0 , V_42 ) ;
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
struct V_5 * F_28 ( struct V_5 * V_6 ,
int V_55 )
{
int V_21 ;
if ( F_21 ( ! V_6 -> V_56 ) ) {
F_29 ( V_6 ) ;
V_6 -> V_56 = 1 ;
}
if ( F_30 ( V_6 ) ) {
V_21 = F_31 ( V_6 , V_57 ) ;
if ( F_14 ( V_21 ) )
goto error;
F_12 ( V_6 ) -> V_58 |= V_55 ;
return V_6 ;
}
if ( V_6 -> V_59 != V_60 ) {
V_6 -> V_59 = V_61 ;
V_6 -> V_56 = 0 ;
}
return V_6 ;
error:
F_32 ( V_6 ) ;
return F_33 ( V_21 ) ;
}
struct V_62 * F_34 ( struct V_18 * V_17 ,
struct V_62 * V_63 )
{
int V_64 ;
F_35 ( V_63 , & V_17 -> V_65 ) ;
F_36 (i) {
const struct V_66 * V_67 =
F_37 ( V_17 -> V_67 , V_64 ) ;
T_5 V_68 , V_69 , V_70 , V_71 ;
unsigned int V_72 ;
do {
V_72 = F_38 ( & V_67 -> V_73 ) ;
V_68 = V_67 -> V_68 ;
V_70 = V_67 -> V_70 ;
V_69 = V_67 -> V_69 ;
V_71 = V_67 -> V_71 ;
} while ( F_39 ( & V_67 -> V_73 , V_72 ) );
V_63 -> V_68 += V_68 ;
V_63 -> V_70 += V_70 ;
V_63 -> V_69 += V_69 ;
V_63 -> V_71 += V_71 ;
}
return V_63 ;
}
static int F_40 ( struct V_18 * V_17 , struct V_74 * V_75 ,
unsigned int V_76 , const void * V_77 ,
struct V_78 * * V_79 )
{
struct V_44 * V_46 ;
struct V_78 * V_80 ;
struct V_74 * V_81 [ V_82 + 1 ] ;
int V_21 ;
V_21 = F_41 ( V_81 , V_82 , V_75 , V_83 ) ;
if ( V_21 < 0 )
return V_21 ;
V_80 = F_42 ( sizeof( * V_46 ) ) ;
if ( ! V_80 )
return - V_31 ;
V_80 -> type = V_84 ;
V_46 = F_43 ( V_80 ) ;
if ( V_81 [ V_85 ] )
V_46 -> V_49 . V_50 = F_44 ( V_81 [ V_85 ] ) ;
if ( V_81 [ V_86 ] )
V_46 -> V_49 . V_45 . V_54 . V_8 = F_45 ( V_81 [ V_86 ] ) ;
if ( V_81 [ V_87 ] )
V_46 -> V_49 . V_45 . V_54 . V_7 = F_45 ( V_81 [ V_87 ] ) ;
if ( V_81 [ V_88 ] )
V_46 -> V_49 . V_11 = F_46 ( V_81 [ V_88 ] ) ;
if ( V_81 [ V_89 ] )
V_46 -> V_49 . V_10 = F_46 ( V_81 [ V_89 ] ) ;
if ( V_81 [ V_90 ] )
V_46 -> V_49 . V_91 = F_47 ( V_81 [ V_90 ] ) ;
V_46 -> V_47 = V_48 ;
V_46 -> V_92 = 0 ;
* V_79 = V_80 ;
return 0 ;
}
static int F_48 ( struct V_5 * V_6 ,
struct V_78 * V_93 )
{
struct V_44 * V_46 = F_43 ( V_93 ) ;
if ( F_49 ( V_6 , V_85 , V_46 -> V_49 . V_50 ) ||
F_50 ( V_6 , V_86 , V_46 -> V_49 . V_45 . V_54 . V_8 ) ||
F_50 ( V_6 , V_87 , V_46 -> V_49 . V_45 . V_54 . V_7 ) ||
F_51 ( V_6 , V_89 , V_46 -> V_49 . V_10 ) ||
F_51 ( V_6 , V_88 , V_46 -> V_49 . V_11 ) ||
F_52 ( V_6 , V_90 , V_46 -> V_49 . V_91 ) )
return - V_31 ;
return 0 ;
}
static int F_53 ( struct V_78 * V_93 )
{
return F_54 ( 8 )
+ F_54 ( 4 )
+ F_54 ( 4 )
+ F_54 ( 1 )
+ F_54 ( 1 )
+ F_54 ( 2 ) ;
}
static int F_55 ( struct V_78 * V_94 , struct V_78 * V_95 )
{
return memcmp ( F_43 ( V_94 ) , F_43 ( V_95 ) ,
sizeof( struct V_44 ) ) ;
}
static int F_56 ( struct V_18 * V_17 , struct V_74 * V_75 ,
unsigned int V_76 , const void * V_77 ,
struct V_78 * * V_79 )
{
struct V_44 * V_46 ;
struct V_78 * V_80 ;
struct V_74 * V_81 [ V_96 + 1 ] ;
int V_21 ;
V_21 = F_41 ( V_81 , V_96 , V_75 , V_97 ) ;
if ( V_21 < 0 )
return V_21 ;
V_80 = F_42 ( sizeof( * V_46 ) ) ;
if ( ! V_80 )
return - V_31 ;
V_80 -> type = V_98 ;
V_46 = F_43 ( V_80 ) ;
if ( V_81 [ V_99 ] )
V_46 -> V_49 . V_50 = F_44 ( V_81 [ V_99 ] ) ;
if ( V_81 [ V_100 ] )
V_46 -> V_49 . V_45 . V_52 . V_8 = F_57 ( V_81 [ V_100 ] ) ;
if ( V_81 [ V_101 ] )
V_46 -> V_49 . V_45 . V_52 . V_7 = F_57 ( V_81 [ V_101 ] ) ;
if ( V_81 [ V_102 ] )
V_46 -> V_49 . V_11 = F_46 ( V_81 [ V_102 ] ) ;
if ( V_81 [ V_103 ] )
V_46 -> V_49 . V_10 = F_46 ( V_81 [ V_103 ] ) ;
if ( V_81 [ V_104 ] )
V_46 -> V_49 . V_91 = F_47 ( V_81 [ V_104 ] ) ;
V_46 -> V_47 = V_48 | V_51 ;
V_46 -> V_92 = 0 ;
* V_79 = V_80 ;
return 0 ;
}
static int F_58 ( struct V_5 * V_6 ,
struct V_78 * V_93 )
{
struct V_44 * V_46 = F_43 ( V_93 ) ;
if ( F_49 ( V_6 , V_99 , V_46 -> V_49 . V_50 ) ||
F_59 ( V_6 , V_100 , & V_46 -> V_49 . V_45 . V_52 . V_8 ) ||
F_59 ( V_6 , V_101 , & V_46 -> V_49 . V_45 . V_52 . V_7 ) ||
F_51 ( V_6 , V_103 , V_46 -> V_49 . V_10 ) ||
F_51 ( V_6 , V_102 , V_46 -> V_49 . V_11 ) ||
F_52 ( V_6 , V_104 , V_46 -> V_49 . V_91 ) )
return - V_31 ;
return 0 ;
}
static int F_60 ( struct V_78 * V_93 )
{
return F_54 ( 8 )
+ F_54 ( 16 )
+ F_54 ( 16 )
+ F_54 ( 1 )
+ F_54 ( 1 )
+ F_54 ( 2 ) ;
}
void T_6 F_61 ( void )
{
F_62 ( V_105 != 255 ) ;
F_63 ( & V_106 , V_84 ) ;
F_63 ( & V_107 , V_98 ) ;
}
void F_64 ( void )
{
F_65 ( & V_108 ) ;
}
void F_66 ( void )
{
F_67 ( & V_108 ) ;
}
