void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_10 ;
F_2 ( & V_6 -> V_11 ) ;
V_10 = F_3 ( & V_6 -> V_12 , V_3 ) ;
if ( V_10 )
F_4 ( & V_10 -> V_13 ) ;
F_5 ( & V_6 -> V_11 ) ;
if ( ! V_10 ) {
F_6 ( V_2 , L_1 , V_3 ) ;
return;
}
V_10 -> V_14 ( V_10 , V_4 ) ;
if ( F_7 ( & V_10 -> V_13 ) )
F_8 ( & V_10 -> free ) ;
}
static int F_9 ( struct V_15 * V_16 )
{
T_1 V_17 = V_16 -> V_17 + 12 ;
T_1 V_18 = V_16 -> V_19 ;
T_1 V_20 = V_16 -> V_21 ;
T_1 V_22 = V_16 -> V_22 ;
T_1 V_23 = 1 << ( V_17 - 6 ) ;
T_1 V_24 = 1 << ( V_18 + 4 + V_20 ) ;
T_1 V_25 = 1 << V_17 ;
T_1 V_26 = V_24 + ( V_22 * V_23 ) ;
T_1 V_27 = ( V_26 + V_25 - 1 ) / V_25 ;
return V_27 * sizeof( V_28 ) ;
}
static void F_10 ( void * V_29 , struct V_15 * V_16 )
{
F_11 ( V_29 , V_29 , V_30 , ! ! ( V_16 -> V_31
& V_32 ) ) ;
F_11 ( V_29 , V_29 , V_33 , V_16 -> V_17 ) ;
F_11 ( V_29 , V_29 , V_34 , V_16 -> V_21 + 4 ) ;
F_11 ( V_29 , V_29 , V_35 , V_16 -> V_19 ) ;
F_11 ( V_29 , V_29 , V_22 , V_16 -> V_22 ) ;
F_11 ( V_29 , V_29 , V_36 , V_16 -> V_36 ) ;
F_11 ( V_29 , V_29 , V_37 , V_16 -> V_37 ) ;
F_12 ( V_29 , V_29 , V_38 , V_16 -> V_39 ) ;
}
static void F_13 ( void * V_40 , struct V_15 * V_16 )
{
F_11 ( V_40 , V_40 , V_30 , ! ! ( V_16 -> V_31
& V_32 ) ) ;
F_11 ( V_40 , V_40 , V_17 , V_16 -> V_17 ) ;
F_11 ( V_40 , V_40 , V_20 , V_16 -> V_21 ) ;
F_11 ( V_40 , V_40 , V_18 , V_16 -> V_19 ) ;
F_11 ( V_40 , V_40 , V_22 , V_16 -> V_22 ) ;
F_11 ( V_40 , V_40 , V_36 , V_16 -> V_36 ) ;
F_11 ( V_40 , V_40 , V_37 , V_16 -> V_37 ) ;
F_12 ( V_40 , V_40 , V_38 , V_16 -> V_39 ) ;
F_11 ( V_40 , V_40 , V_41 , V_16 -> V_41 ) ;
F_11 ( V_40 , V_40 , V_42 , V_16 -> V_42 ) ;
}
static void F_14 ( void * V_29 , struct V_15 * V_16 )
{
if ( F_15 ( V_29 , V_29 , V_30 ) )
V_16 -> V_31 &= V_32 ;
V_16 -> V_17 = F_15 ( V_29 , V_29 , V_33 ) ;
V_16 -> V_21 = F_15 ( V_29 , V_29 , V_34 ) - 4 ;
V_16 -> V_19 = F_15 ( V_29 , V_29 , V_35 ) ;
V_16 -> V_22 = F_15 ( V_29 , V_29 , V_22 ) ;
V_16 -> V_36 = F_15 ( V_29 , V_29 , V_36 ) ;
V_16 -> V_37 = F_15 ( V_29 , V_29 , V_37 ) ;
V_16 -> V_39 = F_16 ( V_29 , V_29 , V_38 ) ;
}
static void F_17 ( void * V_40 , struct V_15 * V_16 )
{
if ( F_15 ( V_40 , V_40 , V_30 ) )
V_16 -> V_31 &= V_32 ;
V_16 -> V_17 = F_15 ( V_40 , V_40 , V_17 ) ;
V_16 -> V_21 = F_15 ( V_40 , V_40 , V_20 ) ;
V_16 -> V_19 = F_15 ( V_40 , V_40 , V_18 ) ;
V_16 -> V_22 = F_15 ( V_40 , V_40 , V_22 ) ;
V_16 -> V_36 = F_15 ( V_40 , V_40 , V_36 ) ;
V_16 -> V_37 = F_15 ( V_40 , V_40 , V_37 ) ;
V_16 -> V_39 = F_16 ( V_40 , V_40 , V_38 ) ;
}
struct V_9 * F_18 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_10 ;
F_2 ( & V_6 -> V_11 ) ;
V_10 = F_3 ( & V_6 -> V_12 , V_3 ) ;
if ( V_10 )
F_4 ( & V_10 -> V_13 ) ;
F_5 ( & V_6 -> V_11 ) ;
return V_10 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_16 )
{
T_1 V_43 [ F_20 ( V_44 ) ] = { 0 } ;
void * V_45 ;
void * V_40 ;
void * V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
V_47 = F_9 ( V_16 ) ;
V_48 = F_21 ( V_50 ) + V_47 ;
V_45 = F_22 ( V_48 , V_51 ) ;
if ( ! V_45 )
return - V_52 ;
V_40 = F_23 ( V_50 , V_45 , V_53 ) ;
V_46 = F_23 ( V_50 , V_45 , V_46 ) ;
F_13 ( V_40 , V_16 ) ;
memcpy ( V_46 , V_16 -> V_46 , V_47 ) ;
F_11 ( V_50 , V_45 , V_54 ,
V_55 ) ;
V_49 = F_24 ( V_2 , V_45 , V_48 , V_43 ,
sizeof( V_43 ) ) ;
F_25 ( V_45 ) ;
if ( ! V_49 )
V_10 -> V_3 = F_15 ( V_44 , V_43 , V_3 ) ;
return V_49 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_56 [ F_20 ( V_57 ) ] = { 0 } ;
T_1 V_58 [ F_20 ( V_59 ) ] = { 0 } ;
F_11 ( V_57 , V_56 , V_54 ,
V_60 ) ;
F_11 ( V_57 , V_56 , V_3 , V_10 -> V_3 ) ;
return F_24 ( V_2 , V_56 , sizeof( V_56 ) ,
V_58 , sizeof( V_58 ) ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_36 , int V_61 )
{
T_1 V_56 [ F_20 ( V_62 ) ] = { 0 } ;
T_1 V_58 [ F_20 ( V_63 ) ] = { 0 } ;
F_11 ( V_62 , V_56 , V_54 , V_64 ) ;
F_11 ( V_62 , V_56 , V_65 , V_66 ) ;
F_11 ( V_62 , V_56 , V_67 , V_10 -> V_3 ) ;
F_11 ( V_62 , V_56 , V_36 , V_36 ) ;
return F_24 ( V_2 , V_56 , sizeof( V_56 ) ,
V_58 , sizeof( V_58 ) ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_68 )
{
T_1 V_56 [ F_20 ( V_69 ) ] = { 0 } ;
T_1 * V_58 ;
void * V_40 ;
int V_49 ;
V_58 = F_22 ( F_21 ( V_70 ) , V_51 ) ;
if ( ! V_58 )
return - V_52 ;
F_11 ( V_69 , V_56 , V_54 ,
V_71 ) ;
F_11 ( V_69 , V_56 , V_3 , V_10 -> V_3 ) ;
V_49 = F_24 ( V_2 , V_56 , sizeof( V_56 ) ,
V_58 , F_21 ( V_70 ) ) ;
if ( V_49 )
goto V_68;
V_40 = F_23 ( V_70 , V_58 , V_53 ) ;
F_17 ( V_40 , V_68 ) ;
if ( F_15 ( V_40 , V_40 , V_72 ) != V_73 )
V_68 -> V_31 |= V_74 ;
V_68:
F_25 ( V_58 ) ;
return V_49 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_15 * V_16 )
{
T_1 V_43 [ F_20 ( V_75 ) ] ;
void * V_45 ;
void * V_76 ;
void * V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
V_47 = F_9 ( V_16 ) ;
V_48 = F_21 ( V_77 ) + V_47 ;
V_45 = F_22 ( V_48 , V_51 ) ;
if ( ! V_45 )
return - V_52 ;
V_76 = F_23 ( V_77 , V_45 ,
V_78 ) ;
V_46 = F_23 ( V_77 , V_45 , V_46 ) ;
F_13 ( V_76 , V_16 ) ;
F_11 ( V_76 , V_76 , V_79 , V_16 -> V_79 ) ;
memcpy ( V_46 , V_16 -> V_46 , V_47 ) ;
F_11 ( V_77 , V_45 , V_54 ,
V_80 ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_49 = F_24 ( V_2 , V_45 , V_48 , V_43 ,
sizeof( V_43 ) ) ;
if ( V_49 )
goto V_68;
V_10 -> V_3 = F_15 ( V_75 , V_43 , V_81 ) ;
V_68:
F_25 ( V_45 ) ;
return V_49 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_82 [ F_20 ( V_83 ) ] = { 0 } ;
T_1 V_84 [ F_20 ( V_85 ) ] = { 0 } ;
F_11 ( V_83 , V_82 , V_54 ,
V_86 ) ;
F_11 ( V_83 , V_82 , V_81 , V_10 -> V_3 ) ;
return F_24 ( V_2 , V_82 , sizeof( V_82 ) ,
V_84 , sizeof( V_84 ) ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 V_36 )
{
T_1 V_82 [ F_20 ( V_87 ) ] = { 0 } ;
T_1 V_84 [ F_20 ( V_88 ) ] = { 0 } ;
F_11 ( V_87 , V_82 , V_54 , V_89 ) ;
F_11 ( V_87 , V_82 , V_65 , V_90 ) ;
F_11 ( V_87 , V_82 , V_81 , V_10 -> V_3 ) ;
F_11 ( V_87 , V_82 , V_36 , V_36 ) ;
return F_24 ( V_2 , V_82 , sizeof( V_82 ) ,
V_84 , sizeof( V_84 ) ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_15 * V_68 )
{
T_1 V_82 [ F_20 ( V_91 ) ] ;
T_1 * V_84 ;
void * V_76 ;
int V_49 ;
V_84 = F_22 ( F_21 ( V_92 ) , V_51 ) ;
if ( ! V_84 )
return - V_52 ;
memset ( V_82 , 0 , sizeof( V_82 ) ) ;
F_11 ( V_91 , V_82 , V_54 ,
V_93 ) ;
F_11 ( V_91 , V_82 , V_81 , V_10 -> V_3 ) ;
V_49 = F_24 ( V_2 , V_82 , sizeof( V_82 ) , V_84 ,
F_21 ( V_92 ) ) ;
if ( V_49 )
goto V_68;
V_76 = F_23 ( V_92 , V_84 ,
V_78 ) ;
F_17 ( V_76 , V_68 ) ;
if ( F_15 ( V_76 , V_76 , V_72 ) != V_94 )
V_68 -> V_31 |= V_74 ;
V_68:
F_25 ( V_84 ) ;
return V_49 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_16 )
{
void * V_45 ;
void * V_95 ;
void * V_29 ;
int V_47 ;
int V_48 ;
int V_49 ;
V_47 = F_9 ( V_16 ) ;
V_48 = F_21 ( V_96 ) + V_47 ;
V_45 = F_22 ( V_48 , V_51 ) ;
if ( ! V_45 )
return - V_52 ;
V_95 = F_23 ( V_96 , V_45 , V_97 ) ;
V_29 = F_23 ( V_95 , V_95 , V_29 ) ;
F_11 ( V_95 , V_95 , V_72 , V_98 ) ;
F_10 ( V_29 , V_16 ) ;
memcpy ( F_23 ( V_95 , V_95 , V_29 . V_46 ) , V_16 -> V_46 , V_47 ) ;
V_49 = F_34 ( V_2 , V_45 , V_48 , & V_10 -> V_3 ) ;
F_25 ( V_45 ) ;
return V_49 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
return F_36 ( V_2 , V_10 -> V_3 ) ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
T_2 V_36 )
{
void * V_16 ;
void * V_95 ;
void * V_29 ;
void * V_99 ;
int V_49 ;
V_16 = F_22 ( F_21 ( V_100 ) , V_51 ) ;
if ( ! V_16 )
return - V_52 ;
V_95 = F_23 ( V_100 , V_16 , V_97 ) ;
V_99 = F_23 ( V_100 , V_16 , V_99 ) ;
V_29 = F_23 ( V_95 , V_95 , V_29 ) ;
F_11 ( V_100 , V_16 , V_101 , V_98 ) ;
F_11 ( V_100 , V_16 , V_102 , V_10 -> V_3 ) ;
F_11 ( V_29 , V_29 , V_36 , V_36 ) ;
F_11 ( V_103 , V_99 , V_36 , 1 ) ;
F_11 ( V_95 , V_95 , V_72 , V_98 ) ;
V_49 = F_38 ( V_2 , V_16 , F_21 ( V_100 ) ) ;
F_25 ( V_16 ) ;
return V_49 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_68 )
{
T_1 * V_104 ;
void * V_95 ;
int V_49 ;
V_104 = F_22 ( F_21 ( V_105 ) , V_51 ) ;
if ( ! V_104 )
return - V_52 ;
V_49 = F_40 ( V_2 , V_10 -> V_3 , V_104 ) ;
if ( V_49 )
goto V_68;
V_95 = F_23 ( V_105 , V_104 , V_106 ) ;
F_14 ( F_23 ( V_95 , V_95 , V_29 ) , V_68 ) ;
if ( F_15 ( V_95 , V_95 , V_72 ) != V_98 )
V_68 -> V_31 |= V_74 ;
V_68:
F_25 ( V_104 ) ;
return V_49 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_15 * V_16 )
{
if ( ! V_2 -> V_107 )
return F_19 ( V_2 , V_10 , V_16 ) ;
else if ( V_10 -> V_108 . V_109 == V_110 )
return F_29 ( V_2 , V_10 , V_16 ) ;
else
return F_33 ( V_2 , V_10 , V_16 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( ! V_2 -> V_107 )
return F_26 ( V_2 , V_10 ) ;
else if ( V_10 -> V_108 . V_109 == V_110 )
return F_30 ( V_2 , V_10 ) ;
else
return F_35 ( V_2 , V_10 ) ;
}
int F_43 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_16 )
{
int V_49 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
if ( V_16 -> type == V_111 )
V_10 -> V_108 . V_109 = V_110 ;
else
V_10 -> V_108 . V_109 = V_112 ;
V_49 = F_41 ( V_2 , V_10 , V_16 ) ;
if ( V_49 )
return V_49 ;
F_44 ( & V_10 -> V_13 , 1 ) ;
F_45 ( & V_10 -> free ) ;
F_46 ( & V_6 -> V_11 ) ;
V_49 = F_47 ( & V_6 -> V_12 , V_10 -> V_3 , V_10 ) ;
F_48 ( & V_6 -> V_11 ) ;
if ( V_49 ) {
F_6 ( V_2 , L_2 , V_49 , V_10 -> V_3 ) ;
goto V_113;
}
return 0 ;
V_113:
F_42 ( V_2 , V_10 ) ;
return V_49 ;
}
int F_49 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_114 ;
int V_49 ;
F_46 ( & V_6 -> V_11 ) ;
V_114 = F_50 ( & V_6 -> V_12 , V_10 -> V_3 ) ;
F_48 ( & V_6 -> V_11 ) ;
if ( ! V_114 ) {
F_6 ( V_2 , L_3 , V_10 -> V_3 ) ;
return - V_115 ;
}
if ( V_114 != V_10 ) {
F_6 ( V_2 , L_4 , V_10 -> V_3 ) ;
return - V_115 ;
}
V_49 = F_42 ( V_2 , V_10 ) ;
if ( V_49 )
return V_49 ;
if ( F_7 ( & V_10 -> V_13 ) )
F_8 ( & V_10 -> free ) ;
F_51 ( & V_10 -> free ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_68 )
{
if ( ! V_2 -> V_107 )
return F_28 ( V_2 , V_10 , V_68 ) ;
else if ( V_10 -> V_108 . V_109 == V_110 )
return F_32 ( V_2 , V_10 , V_68 ) ;
else
return F_39 ( V_2 , V_10 , V_68 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_36 , int V_61 )
{
if ( ! V_2 -> V_107 )
return F_27 ( V_2 , V_10 , V_36 , V_61 ) ;
else if ( V_10 -> V_108 . V_109 == V_110 )
return F_31 ( V_2 , V_10 , V_36 ) ;
else
return F_37 ( V_2 , V_10 , V_36 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_55 ( & V_6 -> V_11 ) ;
F_56 ( & V_6 -> V_12 , V_116 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
}
