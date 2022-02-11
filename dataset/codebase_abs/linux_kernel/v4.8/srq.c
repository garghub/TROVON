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
V_45 = F_22 ( V_48 ) ;
if ( ! V_45 )
return - V_51 ;
V_40 = F_23 ( V_50 , V_45 , V_52 ) ;
V_46 = F_23 ( V_50 , V_45 , V_46 ) ;
F_13 ( V_40 , V_16 ) ;
memcpy ( V_46 , V_16 -> V_46 , V_47 ) ;
F_11 ( V_50 , V_45 , V_53 ,
V_54 ) ;
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
T_1 V_55 [ F_20 ( V_56 ) ] = { 0 } ;
T_1 V_57 [ F_20 ( V_58 ) ] = { 0 } ;
F_11 ( V_56 , V_55 , V_53 ,
V_59 ) ;
F_11 ( V_56 , V_55 , V_3 , V_10 -> V_3 ) ;
return F_24 ( V_2 , V_55 , sizeof( V_55 ) ,
V_57 , sizeof( V_57 ) ) ;
}
static int F_27 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_36 , int V_60 )
{
T_1 V_55 [ F_20 ( V_61 ) ] = { 0 } ;
T_1 V_57 [ F_20 ( V_62 ) ] = { 0 } ;
F_11 ( V_61 , V_55 , V_53 , V_63 ) ;
F_11 ( V_61 , V_55 , V_64 , V_10 -> V_3 ) ;
F_11 ( V_61 , V_55 , V_36 , V_36 ) ;
return F_24 ( V_2 , V_55 , sizeof( V_55 ) ,
V_57 , sizeof( V_57 ) ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_65 )
{
T_1 V_55 [ F_20 ( V_66 ) ] = { 0 } ;
T_1 * V_57 ;
void * V_40 ;
int V_49 ;
V_57 = F_22 ( F_21 ( V_67 ) ) ;
if ( ! V_57 )
return - V_51 ;
F_11 ( V_66 , V_55 , V_53 ,
V_68 ) ;
F_11 ( V_66 , V_55 , V_3 , V_10 -> V_3 ) ;
V_49 = F_24 ( V_2 , V_55 , sizeof( V_55 ) ,
V_57 ,
F_21 ( V_67 ) ) ;
if ( V_49 )
goto V_65;
V_40 = F_23 ( V_67 , V_57 , V_52 ) ;
F_17 ( V_40 , V_65 ) ;
if ( F_15 ( V_40 , V_40 , V_69 ) != V_70 )
V_65 -> V_31 |= V_71 ;
V_65:
F_25 ( V_57 ) ;
return V_49 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_15 * V_16 )
{
T_1 V_43 [ F_20 ( V_72 ) ] ;
void * V_45 ;
void * V_73 ;
void * V_46 ;
int V_47 ;
int V_48 ;
int V_49 ;
V_47 = F_9 ( V_16 ) ;
V_48 = F_21 ( V_74 ) + V_47 ;
V_45 = F_22 ( V_48 ) ;
if ( ! V_45 )
return - V_51 ;
V_73 = F_23 ( V_74 , V_45 ,
V_75 ) ;
V_46 = F_23 ( V_74 , V_45 , V_46 ) ;
F_13 ( V_73 , V_16 ) ;
F_11 ( V_73 , V_73 , V_76 , V_16 -> V_76 ) ;
memcpy ( V_46 , V_16 -> V_46 , V_47 ) ;
F_11 ( V_74 , V_45 , V_53 ,
V_77 ) ;
memset ( V_43 , 0 , sizeof( V_43 ) ) ;
V_49 = F_24 ( V_2 , V_45 , V_48 , V_43 ,
sizeof( V_43 ) ) ;
if ( V_49 )
goto V_65;
V_10 -> V_3 = F_15 ( V_72 , V_43 , V_64 ) ;
V_65:
F_25 ( V_45 ) ;
return V_49 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_78 [ F_20 ( V_79 ) ] ;
T_1 V_80 [ F_20 ( V_81 ) ] ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
F_11 ( V_79 , V_78 , V_53 ,
V_82 ) ;
F_11 ( V_79 , V_78 , V_64 , V_10 -> V_3 ) ;
return F_24 ( V_2 , V_78 , sizeof( V_78 ) ,
V_80 , sizeof( V_80 ) ) ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 V_36 )
{
T_1 V_78 [ F_20 ( V_61 ) ] ;
T_1 V_80 [ F_20 ( V_62 ) ] ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
memset ( V_80 , 0 , sizeof( V_80 ) ) ;
F_11 ( V_61 , V_78 , V_53 , V_63 ) ;
F_11 ( V_61 , V_78 , V_83 , V_84 ) ;
F_11 ( V_61 , V_78 , V_64 , V_10 -> V_3 ) ;
F_11 ( V_61 , V_78 , V_36 , V_36 ) ;
return F_24 ( V_2 , V_78 , sizeof( V_78 ) ,
V_80 , sizeof( V_80 ) ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_15 * V_65 )
{
T_1 V_78 [ F_20 ( V_85 ) ] ;
T_1 * V_80 ;
void * V_73 ;
int V_49 ;
V_80 = F_22 ( F_21 ( V_86 ) ) ;
if ( ! V_80 )
return - V_51 ;
memset ( V_78 , 0 , sizeof( V_78 ) ) ;
F_11 ( V_85 , V_78 , V_53 ,
V_87 ) ;
F_11 ( V_85 , V_78 , V_64 , V_10 -> V_3 ) ;
V_49 = F_24 ( V_2 , V_78 , sizeof( V_78 ) ,
V_80 ,
F_21 ( V_86 ) ) ;
if ( V_49 )
goto V_65;
V_73 = F_23 ( V_86 , V_80 ,
V_75 ) ;
F_17 ( V_73 , V_65 ) ;
if ( F_15 ( V_73 , V_73 , V_69 ) != V_88 )
V_65 -> V_31 |= V_71 ;
V_65:
F_25 ( V_80 ) ;
return V_49 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_16 )
{
void * V_45 ;
void * V_89 ;
void * V_29 ;
int V_47 ;
int V_48 ;
int V_49 ;
V_47 = F_9 ( V_16 ) ;
V_48 = F_21 ( V_90 ) + V_47 ;
V_45 = F_22 ( V_48 ) ;
if ( ! V_45 )
return - V_51 ;
V_89 = F_23 ( V_90 , V_45 , V_91 ) ;
V_29 = F_23 ( V_89 , V_89 , V_29 ) ;
F_11 ( V_89 , V_89 , V_69 , V_92 ) ;
F_10 ( V_29 , V_16 ) ;
memcpy ( F_23 ( V_89 , V_89 , V_29 . V_46 ) , V_16 -> V_46 , V_47 ) ;
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
void * V_89 ;
void * V_29 ;
void * V_93 ;
int V_49 ;
V_16 = F_22 ( F_21 ( V_94 ) ) ;
if ( ! V_16 )
return - V_51 ;
V_89 = F_23 ( V_94 , V_16 , V_91 ) ;
V_93 = F_23 ( V_94 , V_16 , V_93 ) ;
V_29 = F_23 ( V_89 , V_89 , V_29 ) ;
F_11 ( V_94 , V_16 , V_95 , V_92 ) ;
F_11 ( V_94 , V_16 , V_96 , V_10 -> V_3 ) ;
F_11 ( V_29 , V_29 , V_36 , V_36 ) ;
F_11 ( V_97 , V_93 , V_36 , 1 ) ;
F_11 ( V_89 , V_89 , V_69 , V_92 ) ;
V_49 = F_38 ( V_2 , V_16 , F_21 ( V_94 ) ) ;
F_25 ( V_16 ) ;
return V_49 ;
}
static int F_39 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_65 )
{
T_1 * V_98 ;
void * V_89 ;
int V_49 ;
V_98 = F_22 ( F_21 ( V_99 ) ) ;
if ( ! V_98 )
return - V_51 ;
V_49 = F_40 ( V_2 , V_10 -> V_3 , V_98 ) ;
if ( V_49 )
goto V_65;
V_89 = F_23 ( V_99 , V_98 , V_100 ) ;
F_14 ( F_23 ( V_89 , V_89 , V_29 ) , V_65 ) ;
if ( F_15 ( V_89 , V_89 , V_69 ) != V_92 )
V_65 -> V_31 |= V_71 ;
V_65:
F_25 ( V_98 ) ;
return V_49 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_15 * V_16 )
{
if ( ! V_2 -> V_101 )
return F_19 ( V_2 , V_10 , V_16 ) ;
else if ( V_10 -> V_102 . V_103 == V_104 )
return F_29 ( V_2 , V_10 , V_16 ) ;
else
return F_33 ( V_2 , V_10 , V_16 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( ! V_2 -> V_101 )
return F_26 ( V_2 , V_10 ) ;
else if ( V_10 -> V_102 . V_103 == V_104 )
return F_30 ( V_2 , V_10 ) ;
else
return F_35 ( V_2 , V_10 ) ;
}
int F_43 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_15 * V_16 )
{
int V_49 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
if ( V_16 -> type == V_105 )
V_10 -> V_102 . V_103 = V_104 ;
else
V_10 -> V_102 . V_103 = V_106 ;
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
goto V_107;
}
return 0 ;
V_107:
F_42 ( V_2 , V_10 ) ;
return V_49 ;
}
int F_49 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_108 ;
int V_49 ;
F_46 ( & V_6 -> V_11 ) ;
V_108 = F_50 ( & V_6 -> V_12 , V_10 -> V_3 ) ;
F_48 ( & V_6 -> V_11 ) ;
if ( ! V_108 ) {
F_6 ( V_2 , L_3 , V_10 -> V_3 ) ;
return - V_109 ;
}
if ( V_108 != V_10 ) {
F_6 ( V_2 , L_4 , V_10 -> V_3 ) ;
return - V_109 ;
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
struct V_15 * V_65 )
{
if ( ! V_2 -> V_101 )
return F_28 ( V_2 , V_10 , V_65 ) ;
else if ( V_10 -> V_102 . V_103 == V_104 )
return F_32 ( V_2 , V_10 , V_65 ) ;
else
return F_39 ( V_2 , V_10 , V_65 ) ;
}
int F_53 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_36 , int V_60 )
{
if ( ! V_2 -> V_101 )
return F_27 ( V_2 , V_10 , V_36 , V_60 ) ;
else if ( V_10 -> V_102 . V_103 == V_104 )
return F_31 ( V_2 , V_10 , V_36 ) ;
else
return F_37 ( V_2 , V_10 , V_36 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_55 ( & V_6 -> V_11 ) ;
F_56 ( & V_6 -> V_12 , V_110 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
}
