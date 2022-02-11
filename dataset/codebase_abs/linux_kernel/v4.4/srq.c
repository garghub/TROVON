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
static int F_9 ( void * V_15 )
{
T_1 V_16 = F_10 ( V_15 , V_15 , V_16 ) + 12 ;
T_1 V_17 = F_10 ( V_15 , V_15 , V_17 ) ;
T_1 V_18 = F_10 ( V_15 , V_15 , V_18 ) ;
T_1 V_19 = F_10 ( V_15 , V_15 , V_19 ) ;
T_1 V_20 = 1 << ( V_16 - 6 ) ;
T_1 V_21 = 1 << ( V_17 + 4 + V_18 ) ;
T_1 V_22 = 1 << V_16 ;
T_1 V_23 = V_21 + ( V_19 * V_20 ) ;
T_1 V_24 = ( V_23 + V_22 - 1 ) / V_22 ;
return V_24 * sizeof( V_25 ) ;
}
static void F_11 ( void * V_15 , void * V_26 , bool V_27 )
{
void * V_28 = F_12 ( V_26 , V_26 , V_28 ) ;
if ( V_27 ) {
switch ( F_10 ( V_15 , V_15 , V_29 ) ) {
case V_30 :
F_13 ( V_26 , V_26 , V_29 , V_31 ) ;
break;
case V_32 :
F_13 ( V_26 , V_26 , V_29 , V_33 ) ;
break;
default:
F_14 ( L_2 , V_34 ,
__LINE__ , F_10 ( V_15 , V_15 , V_29 ) ) ;
F_13 ( V_26 , V_26 , V_29 , F_10 ( V_15 , V_15 , V_29 ) ) ;
}
F_13 ( V_28 , V_28 , V_35 , F_10 ( V_15 , V_15 , V_35 ) ) ;
F_13 ( V_28 , V_28 , V_36 , F_10 ( V_15 , V_15 , V_16 ) ) ;
F_13 ( V_28 , V_28 , V_37 , F_10 ( V_15 , V_15 , V_18 ) + 4 ) ;
F_13 ( V_28 , V_28 , V_38 , F_10 ( V_15 , V_15 , V_17 ) ) ;
F_13 ( V_28 , V_28 , V_19 , F_10 ( V_15 , V_15 , V_19 ) ) ;
F_13 ( V_28 , V_28 , V_39 , F_10 ( V_15 , V_15 , V_39 ) ) ;
F_13 ( V_28 , V_28 , V_40 , F_10 ( V_15 , V_15 , V_40 ) ) ;
F_15 ( V_28 , V_28 , V_41 , F_16 ( V_15 , V_15 , V_41 ) ) ;
} else {
switch ( F_10 ( V_26 , V_26 , V_29 ) ) {
case V_31 :
F_13 ( V_15 , V_15 , V_29 , V_30 ) ;
break;
case V_33 :
F_13 ( V_15 , V_15 , V_29 , V_32 ) ;
break;
default:
F_14 ( L_3 ,
V_34 , __LINE__ ,
F_10 ( V_26 , V_26 , V_29 ) ) ;
F_13 ( V_15 , V_15 , V_29 ,
F_10 ( V_26 , V_26 , V_29 ) ) ;
}
F_13 ( V_15 , V_15 , V_35 , F_10 ( V_28 , V_28 , V_35 ) ) ;
F_13 ( V_15 , V_15 , V_16 , F_10 ( V_28 , V_28 , V_36 ) ) ;
F_13 ( V_15 , V_15 , V_18 , F_10 ( V_28 , V_28 , V_37 ) - 4 ) ;
F_13 ( V_15 , V_15 , V_17 , F_10 ( V_28 , V_28 , V_38 ) ) ;
F_13 ( V_15 , V_15 , V_19 , F_10 ( V_28 , V_28 , V_19 ) ) ;
F_13 ( V_15 , V_15 , V_39 , F_10 ( V_28 , V_28 , V_39 ) ) ;
F_13 ( V_15 , V_15 , V_40 , F_10 ( V_28 , V_28 , V_40 ) ) ;
F_15 ( V_15 , V_15 , V_41 , F_16 ( V_28 , V_28 , V_41 ) ) ;
}
}
struct V_9 * F_17 ( struct V_1 * V_2 , T_1 V_3 )
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
static int F_18 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_42 * V_43 , int V_44 )
{
struct V_45 V_46 ;
int V_47 ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_43 -> V_48 . V_49 = F_19 ( V_50 ) ;
V_47 = F_20 ( V_2 , ( T_1 * ) V_43 , V_44 , ( T_1 * ) ( & V_46 ) ,
sizeof( V_46 ) ) ;
V_10 -> V_3 = F_21 ( V_46 . V_3 ) & 0xffffff ;
return V_47 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
struct V_51 V_43 ;
struct V_52 V_46 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_43 . V_48 . V_49 = F_19 ( V_53 ) ;
V_43 . V_3 = F_23 ( V_10 -> V_3 ) ;
return F_20 ( V_2 , ( T_1 * ) ( & V_43 ) , sizeof( V_43 ) ,
( T_1 * ) ( & V_46 ) , sizeof( V_46 ) ) ;
}
static int F_24 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_39 , int V_54 )
{
struct V_55 V_43 ;
struct V_56 V_46 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
memset ( & V_46 , 0 , sizeof( V_46 ) ) ;
V_43 . V_48 . V_49 = F_19 ( V_57 ) ;
V_43 . V_48 . V_58 = F_19 ( ! ! V_54 ) ;
V_43 . V_3 = F_23 ( V_10 -> V_3 ) ;
V_43 . V_39 = F_19 ( V_39 ) ;
return F_20 ( V_2 , ( T_1 * ) ( & V_43 ) ,
sizeof( V_43 ) , ( T_1 * ) ( & V_46 ) ,
sizeof( V_46 ) ) ;
}
static int F_25 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_59 * V_46 )
{
struct V_60 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_48 . V_49 = F_19 ( V_61 ) ;
V_43 . V_3 = F_23 ( V_10 -> V_3 ) ;
return F_20 ( V_2 , ( T_1 * ) ( & V_43 ) , sizeof( V_43 ) ,
( T_1 * ) V_46 , sizeof( * V_46 ) ) ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_42 * V_43 ,
int V_62 )
{
T_1 V_63 [ F_27 ( V_64 ) ] ;
void * V_65 ;
void * V_15 ;
void * V_66 ;
void * V_67 ;
int V_68 ;
int V_44 ;
int V_47 ;
V_15 = F_12 ( V_69 , V_43 , V_70 ) ;
V_68 = F_9 ( V_15 ) ;
V_44 = F_28 ( V_71 ) + V_68 ;
V_65 = F_29 ( V_44 ) ;
if ( ! V_65 )
return - V_72 ;
V_66 = F_12 ( V_71 , V_65 ,
V_73 ) ;
V_67 = F_12 ( V_71 , V_65 , V_67 ) ;
memcpy ( V_66 , V_15 , F_28 ( V_15 ) ) ;
memcpy ( V_67 , V_43 -> V_67 , V_68 ) ;
F_13 ( V_66 , V_66 , V_74 , 0xffffff ) ;
F_13 ( V_71 , V_65 , V_49 ,
V_75 ) ;
memset ( V_63 , 0 , sizeof( V_63 ) ) ;
V_47 = F_20 ( V_2 , V_65 , V_44 , V_63 ,
sizeof( V_63 ) ) ;
if ( V_47 )
goto V_46;
V_10 -> V_3 = F_10 ( V_64 , V_63 , V_76 ) ;
V_46:
F_30 ( V_65 ) ;
return V_47 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
T_1 V_77 [ F_27 ( V_78 ) ] ;
T_1 V_79 [ F_27 ( V_80 ) ] ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
F_13 ( V_78 , V_77 , V_49 ,
V_81 ) ;
F_13 ( V_78 , V_77 , V_76 , V_10 -> V_3 ) ;
return F_20 ( V_2 , V_77 , sizeof( V_77 ) ,
V_79 , sizeof( V_79 ) ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_9 * V_10 , T_2 V_39 )
{
T_1 V_77 [ F_27 ( V_82 ) ] ;
T_1 V_79 [ F_27 ( V_83 ) ] ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
memset ( V_79 , 0 , sizeof( V_79 ) ) ;
F_13 ( V_82 , V_77 , V_49 , V_84 ) ;
F_13 ( V_82 , V_77 , V_85 , V_86 ) ;
F_13 ( V_82 , V_77 , V_76 , V_10 -> V_3 ) ;
F_13 ( V_82 , V_77 , V_39 , V_39 ) ;
return F_20 ( V_2 , V_77 , sizeof( V_77 ) ,
V_79 , sizeof( V_79 ) ) ;
}
static int F_33 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_59 * V_46 )
{
T_1 V_77 [ F_27 ( V_87 ) ] ;
T_1 * V_79 ;
void * V_15 ;
void * V_66 ;
int V_47 ;
V_79 = F_29 ( F_28 ( V_88 ) ) ;
if ( ! V_79 )
return - V_72 ;
memset ( V_77 , 0 , sizeof( V_77 ) ) ;
F_13 ( V_87 , V_77 , V_49 ,
V_89 ) ;
F_13 ( V_87 , V_77 , V_76 , V_10 -> V_3 ) ;
V_47 = F_20 ( V_2 , V_77 , sizeof( V_77 ) ,
V_79 ,
F_28 ( V_88 ) ) ;
if ( V_47 )
goto V_46;
V_66 = F_12 ( V_88 , V_79 ,
V_73 ) ;
V_15 = F_12 ( V_90 , V_46 , V_70 ) ;
memcpy ( V_15 , V_66 , F_28 ( V_15 ) ) ;
V_46:
F_30 ( V_79 ) ;
return V_47 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_42 * V_43 , int V_62 )
{
void * V_65 ;
void * V_26 ;
void * V_15 ;
int V_68 ;
int V_44 ;
int V_47 ;
V_15 = F_12 ( V_69 , V_43 , V_70 ) ;
V_68 = F_9 ( V_15 ) ;
V_44 = F_28 ( V_91 ) + V_68 ;
V_65 = F_29 ( V_44 ) ;
if ( ! V_65 )
return - V_72 ;
V_26 = F_12 ( V_91 , V_65 , V_92 ) ;
memcpy ( F_12 ( V_26 , V_26 , V_28 . V_67 ) , V_43 -> V_67 , V_68 ) ;
F_11 ( V_15 , V_26 , true ) ;
V_47 = F_35 ( V_2 , V_65 , V_44 , & V_10 -> V_3 ) ;
F_30 ( V_65 ) ;
return V_47 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
return F_37 ( V_2 , V_10 -> V_3 ) ;
}
static int F_38 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
T_2 V_39 )
{
void * V_43 ;
void * V_26 ;
void * V_28 ;
void * V_93 ;
int V_47 ;
V_43 = F_29 ( F_28 ( V_94 ) ) ;
if ( ! V_43 )
return - V_72 ;
V_26 = F_12 ( V_94 , V_43 , V_92 ) ;
V_93 = F_12 ( V_94 , V_43 , V_93 ) ;
V_28 = F_12 ( V_26 , V_26 , V_28 ) ;
F_13 ( V_94 , V_43 , V_95 , V_31 ) ;
F_13 ( V_94 , V_43 , V_96 , V_10 -> V_3 ) ;
F_13 ( V_28 , V_28 , V_39 , V_39 ) ;
F_13 ( V_97 , V_93 , V_39 , 1 ) ;
F_13 ( V_26 , V_26 , V_29 , V_31 ) ;
V_47 = F_39 ( V_2 , V_43 , F_28 ( V_94 ) ) ;
F_30 ( V_43 ) ;
return V_47 ;
}
static int F_40 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_59 * V_46 )
{
T_1 * V_98 ;
void * V_26 ;
void * V_15 ;
int V_47 ;
V_98 = F_29 ( F_28 ( V_99 ) ) ;
if ( ! V_98 )
return - V_72 ;
V_47 = F_41 ( V_2 , V_10 -> V_3 , V_98 ) ;
if ( V_47 )
goto V_46;
V_15 = F_12 ( V_90 , V_46 , V_70 ) ;
V_26 = F_12 ( V_99 , V_98 , V_100 ) ;
F_11 ( V_15 , V_26 , false ) ;
V_46:
F_30 ( V_98 ) ;
return V_47 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
struct V_42 * V_43 ,
int V_44 , int V_101 )
{
if ( ! V_2 -> V_102 )
return F_18 ( V_2 , V_10 , V_43 , V_44 ) ;
else if ( V_10 -> V_103 . V_104 == V_105 )
return F_26 ( V_2 , V_10 , V_43 , V_44 ) ;
else
return F_34 ( V_2 , V_10 , V_43 , V_44 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_9 * V_10 )
{
if ( ! V_2 -> V_102 )
return F_22 ( V_2 , V_10 ) ;
else if ( V_10 -> V_103 . V_104 == V_105 )
return F_31 ( V_2 , V_10 ) ;
else
return F_36 ( V_2 , V_10 ) ;
}
int F_44 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_42 * V_43 , int V_44 ,
int V_101 )
{
int V_47 ;
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
V_10 -> V_103 . V_104 = V_101 ? V_105 : V_106 ;
V_47 = F_42 ( V_2 , V_10 , V_43 , V_44 , V_101 ) ;
if ( V_47 )
return V_47 ;
F_45 ( & V_10 -> V_13 , 1 ) ;
F_46 ( & V_10 -> free ) ;
F_47 ( & V_6 -> V_11 ) ;
V_47 = F_48 ( & V_6 -> V_12 , V_10 -> V_3 , V_10 ) ;
F_49 ( & V_6 -> V_11 ) ;
if ( V_47 ) {
F_6 ( V_2 , L_4 , V_47 , V_10 -> V_3 ) ;
goto V_107;
}
return 0 ;
V_107:
F_43 ( V_2 , V_10 ) ;
return V_47 ;
}
int F_50 ( struct V_1 * V_2 , struct V_9 * V_10 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
struct V_9 * V_108 ;
int V_47 ;
F_47 ( & V_6 -> V_11 ) ;
V_108 = F_51 ( & V_6 -> V_12 , V_10 -> V_3 ) ;
F_49 ( & V_6 -> V_11 ) ;
if ( ! V_108 ) {
F_6 ( V_2 , L_5 , V_10 -> V_3 ) ;
return - V_109 ;
}
if ( V_108 != V_10 ) {
F_6 ( V_2 , L_6 , V_10 -> V_3 ) ;
return - V_109 ;
}
V_47 = F_43 ( V_2 , V_10 ) ;
if ( V_47 )
return V_47 ;
if ( F_7 ( & V_10 -> V_13 ) )
F_8 ( & V_10 -> free ) ;
F_52 ( & V_10 -> free ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 , struct V_9 * V_10 ,
struct V_59 * V_46 )
{
if ( ! V_2 -> V_102 )
return F_25 ( V_2 , V_10 , V_46 ) ;
else if ( V_10 -> V_103 . V_104 == V_105 )
return F_33 ( V_2 , V_10 , V_46 ) ;
else
return F_40 ( V_2 , V_10 , V_46 ) ;
}
int F_54 ( struct V_1 * V_2 , struct V_9 * V_10 ,
T_2 V_39 , int V_54 )
{
if ( ! V_2 -> V_102 )
return F_24 ( V_2 , V_10 , V_39 , V_54 ) ;
else if ( V_10 -> V_103 . V_104 == V_105 )
return F_32 ( V_2 , V_10 , V_39 ) ;
else
return F_38 ( V_2 , V_10 , V_39 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = & V_2 -> V_7 . V_8 ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_56 ( & V_6 -> V_11 ) ;
F_57 ( & V_6 -> V_12 , V_110 ) ;
}
void F_58 ( struct V_1 * V_2 )
{
}
