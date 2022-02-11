static inline void F_1 ( struct V_1 * V_2 , int V_3 ,
int (* F_2)( struct V_1 * ) )
{
if ( ! V_3 )
V_3 = F_2 ( V_2 ) ;
if ( V_3 != - V_4 && V_3 != - V_5 )
F_3 ( V_2 , V_3 ) ;
}
static void F_4 ( T_1 * V_6 , struct V_1 * V_2 , T_2 V_7 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
T_3 V_10 = F_7 ( V_7 ) ;
memcpy ( V_6 , & V_10 , sizeof( V_10 ) ) ;
memcpy ( V_6 + sizeof( V_10 ) , V_9 -> V_11 , V_9 -> V_12 ) ;
memcpy ( V_6 + sizeof( V_10 ) + V_9 -> V_12 , V_2 -> V_6 ,
V_13 - sizeof( V_10 ) - V_9 -> V_12 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
T_1 V_16 [ sizeof( V_15 -> V_16 ) ] ;
F_10 ( V_16 , V_2 -> V_17 , V_15 -> V_18 , sizeof( V_16 ) , 0 ) ;
if ( F_11 ( V_16 , V_15 -> V_16 , sizeof( V_16 ) ) )
return - V_19 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
F_10 ( V_15 -> V_16 , V_2 -> V_20 , V_15 -> V_18 ,
sizeof( V_15 -> V_16 ) , 1 ) ;
return 0 ;
}
static void F_13 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_8 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_24 * V_25 = & V_15 -> V_26 . V_27 ;
int V_3 ;
F_4 ( V_25 -> V_6 , V_2 , 1 ) ;
F_15 ( & V_25 -> V_2 , F_16 ( V_2 ) ,
F_13 , V_2 ) ;
F_17 ( & V_25 -> V_2 , V_9 -> V_27 ) ;
F_18 ( & V_25 -> V_2 , V_2 -> V_17 , V_2 -> V_20 ,
V_15 -> V_18 , V_25 -> V_6 ) ;
V_3 = F_19 ( & V_25 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_8 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
if ( V_15 -> V_18 == V_2 -> V_18 )
return F_12 ( V_2 ) ;
return F_14 ( V_2 ) ;
}
static void F_21 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_20 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
T_4 V_31 ;
int V_3 ;
F_23 ( V_29 -> V_17 , 1 ) ;
V_31 = F_24 ( V_2 -> V_32 ) ;
memcpy ( & V_29 -> V_33 . V_32 , & V_31 , sizeof( V_31 ) ) ;
V_31 = F_24 ( V_15 -> V_18 ) ;
memcpy ( & V_29 -> V_33 . V_18 , & V_31 , sizeof( V_31 ) ) ;
F_25 ( V_29 -> V_17 , & V_29 -> V_33 , sizeof( V_29 -> V_33 ) ) ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_21 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
F_28 ( & V_29 -> V_2 , V_29 -> V_17 ,
V_15 -> V_16 , sizeof( V_29 -> V_33 ) ) ;
V_3 = F_29 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_20 ( V_2 ) ;
}
static void F_30 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_22 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
unsigned int V_34 , V_35 = V_36 ;
int V_3 ;
V_34 = ( V_35 - ( V_15 -> V_18 % V_35 ) ) % V_35 ;
memset ( V_29 -> V_37 , 0 , sizeof( V_29 -> V_37 ) ) ;
F_23 ( V_29 -> V_17 , 1 ) ;
F_25 ( V_29 -> V_17 , & V_29 -> V_37 , V_34 ) ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_30 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
F_28 ( & V_29 -> V_2 , V_29 -> V_17 , NULL , V_34 ) ;
V_3 = F_32 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_22 ( V_2 ) ;
}
static void F_33 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_31 ) ;
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
struct V_38 * V_39 = V_2 -> V_17 ;
int V_3 ;
if ( V_15 -> V_18 == V_2 -> V_18 )
V_39 = V_2 -> V_20 ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_33 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
F_28 ( & V_29 -> V_2 , V_39 , NULL , V_15 -> V_18 ) ;
V_3 = F_32 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_31 ( V_2 ) ;
}
static void F_35 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_34 ) ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
unsigned int V_34 , V_35 = V_36 ;
int V_3 ;
V_34 = ( V_35 - ( V_2 -> V_32 % V_35 ) ) % V_35 ;
memset ( V_29 -> V_37 , 0 , sizeof( V_29 -> V_37 ) ) ;
F_23 ( V_29 -> V_17 , 1 ) ;
F_25 ( V_29 -> V_17 , V_29 -> V_37 , V_34 ) ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_35 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
F_28 ( & V_29 -> V_2 , V_29 -> V_17 , NULL , V_34 ) ;
V_3 = F_32 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_34 ( V_2 ) ;
}
static void F_37 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_36 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
int V_3 ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_37 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
F_28 ( & V_29 -> V_2 , V_2 -> V_40 , NULL , V_2 -> V_32 ) ;
V_3 = F_32 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_36 ( V_2 ) ;
}
static void F_39 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_38 ) ;
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
int V_3 ;
F_23 ( V_29 -> V_17 , 1 ) ;
F_25 ( V_29 -> V_17 , V_15 -> V_41 , sizeof( V_15 -> V_41 ) ) ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_39 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
F_28 ( & V_29 -> V_2 , V_29 -> V_17 , NULL , sizeof( V_15 -> V_41 ) ) ;
V_3 = F_32 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_38 ( V_2 ) ;
}
static void F_41 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_40 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_28 * V_29 = & V_15 -> V_26 . V_30 ;
int V_3 ;
F_26 ( & V_29 -> V_2 , F_16 ( V_2 ) ,
F_41 , V_2 ) ;
F_27 ( & V_29 -> V_2 , V_9 -> V_30 ) ;
V_3 = F_43 ( & V_29 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_40 ( V_2 ) ;
}
static void F_44 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_42 ) ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_24 * V_25 = & V_15 -> V_26 . V_27 ;
int V_3 ;
F_23 ( V_25 -> V_17 , 1 ) ;
memset ( V_15 -> V_41 , 0 , sizeof( V_15 -> V_41 ) ) ;
F_25 ( V_25 -> V_17 , V_15 -> V_41 , sizeof( V_15 -> V_41 ) ) ;
F_4 ( V_25 -> V_6 , V_2 , 0 ) ;
F_15 ( & V_25 -> V_2 , F_16 ( V_2 ) ,
F_44 , V_2 ) ;
F_17 ( & V_25 -> V_2 , V_9 -> V_27 ) ;
F_18 ( & V_25 -> V_2 , V_25 -> V_17 , V_25 -> V_17 ,
V_42 , V_25 -> V_6 ) ;
V_3 = F_19 ( & V_25 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_42 ( V_2 ) ;
}
static void F_46 ( struct V_21 * V_22 , int V_3 )
{
F_1 ( V_22 -> V_23 , V_3 , F_45 ) ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_24 * V_25 = & V_15 -> V_26 . V_27 ;
int V_3 ;
F_4 ( V_25 -> V_6 , V_2 , 1 ) ;
F_15 ( & V_25 -> V_2 , F_16 ( V_2 ) ,
F_46 , V_2 ) ;
F_17 ( & V_25 -> V_2 , V_9 -> V_27 ) ;
F_18 ( & V_25 -> V_2 , V_2 -> V_17 , V_2 -> V_20 ,
V_2 -> V_18 , V_25 -> V_6 ) ;
V_3 = F_48 ( & V_25 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_45 ( V_2 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
V_15 -> V_18 = V_2 -> V_18 ;
return F_47 ( V_2 ) ;
}
static int F_50 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
if ( V_2 -> V_18 < V_43 )
return - V_44 ;
V_15 -> V_18 = V_2 -> V_18 - V_43 ;
return F_45 ( V_2 ) ;
}
static int F_51 ( struct V_45 * V_46 , const T_1 * V_41 ,
unsigned int V_47 )
{
struct V_8 * V_9 = F_5 ( V_46 ) ;
int V_3 ;
if ( V_47 != V_9 -> V_12 + V_48 )
return - V_44 ;
V_47 -= V_9 -> V_12 ;
memcpy ( V_9 -> V_11 , V_41 + V_47 , V_9 -> V_12 ) ;
F_52 ( V_9 -> V_27 , V_49 ) ;
F_53 ( V_9 -> V_27 , F_54 ( V_46 ) &
V_49 ) ;
V_3 = F_55 ( V_9 -> V_27 , V_41 , V_47 ) ;
F_56 ( V_46 , F_57 ( V_9 -> V_27 ) &
V_50 ) ;
return V_3 ;
}
static int F_58 ( struct V_45 * V_51 ,
unsigned int V_52 )
{
if ( V_52 != V_43 )
return - V_44 ;
return 0 ;
}
static int F_59 ( struct V_53 * V_51 )
{
struct V_54 * V_55 = ( void * ) V_51 -> V_56 ;
struct V_57 * V_58 = F_60 ( V_55 ) ;
struct V_8 * V_9 = F_61 ( V_51 ) ;
struct V_59 * V_27 ;
struct V_60 * V_30 ;
unsigned long V_61 ;
V_30 = F_62 ( & V_58 -> V_30 ) ;
if ( F_63 ( V_30 ) )
return F_64 ( V_30 ) ;
V_27 = F_65 ( & V_58 -> V_27 ) ;
if ( F_63 ( V_27 ) ) {
F_66 ( V_30 ) ;
return F_64 ( V_27 ) ;
}
V_9 -> V_27 = V_27 ;
V_9 -> V_30 = V_30 ;
V_9 -> V_12 = V_58 -> V_12 ;
V_61 = F_67 ( V_51 ) ;
V_61 &= ~ ( F_68 () - 1 ) ;
F_69 ( F_70 ( V_51 ) ,
V_61 + F_71 ( struct V_14 , V_26 ) +
F_72 ( F_71 ( struct V_24 , V_2 ) +
sizeof( struct V_62 ) +
F_73 ( V_27 ) ,
F_71 ( struct V_28 , V_2 ) +
sizeof( struct V_63 ) +
F_74 ( V_30 ) ) ) ;
return 0 ;
}
static void F_75 ( struct V_53 * V_51 )
{
struct V_8 * V_9 = F_61 ( V_51 ) ;
F_66 ( V_9 -> V_30 ) ;
F_76 ( V_9 -> V_27 ) ;
}
static struct V_54 * F_77 ( struct V_64 * * V_65 ,
const char * V_66 ,
unsigned int V_67 )
{
struct V_68 * V_69 ;
struct V_54 * V_55 ;
struct V_70 * V_27 ;
struct V_70 * V_30 ;
struct V_71 * V_72 ;
struct V_57 * V_9 ;
const char * V_73 , * V_74 ;
int V_3 ;
if ( V_67 > V_75 )
return F_78 ( - V_44 ) ;
V_69 = F_79 ( V_65 ) ;
if ( F_63 ( V_69 ) )
return F_80 ( V_69 ) ;
if ( ( V_69 -> type ^ V_76 ) & V_69 -> V_77 )
return F_78 ( - V_44 ) ;
V_73 = F_81 ( V_65 [ 1 ] ) ;
if ( F_63 ( V_73 ) )
return F_80 ( V_73 ) ;
V_74 = F_81 ( V_65 [ 2 ] ) ;
if ( F_63 ( V_74 ) )
return F_80 ( V_74 ) ;
V_30 = F_82 ( V_74 , & V_78 ,
V_79 ,
V_80 ) ;
if ( F_63 ( V_30 ) )
return F_80 ( V_30 ) ;
V_3 = - V_81 ;
V_55 = F_83 ( sizeof( * V_55 ) + sizeof( * V_9 ) , V_82 ) ;
if ( ! V_55 )
goto V_83;
V_9 = F_60 ( V_55 ) ;
V_9 -> V_12 = V_75 - V_67 ;
V_72 = F_84 ( V_30 , struct V_71 , V_84 . V_85 ) ;
V_3 = F_85 ( & V_9 -> V_30 , & V_72 -> V_84 , V_55 ) ;
if ( V_3 )
goto V_86;
F_86 ( & V_9 -> V_27 , V_55 ) ;
V_3 = F_87 ( & V_9 -> V_27 , V_73 , 0 ,
F_88 ( V_69 -> type ,
V_69 -> V_77 ) ) ;
if ( V_3 )
goto V_87;
V_27 = F_89 ( & V_9 -> V_27 ) ;
V_3 = - V_44 ;
if ( V_27 -> V_88 . V_67 != V_13 )
goto V_89;
if ( V_27 -> V_90 != 1 )
goto V_89;
V_3 = - V_91 ;
if ( snprintf ( V_55 -> V_92 . V_93 , V_94 ,
L_1 , V_66 , V_73 ,
V_74 ) >= V_94 )
goto V_89;
if ( snprintf ( V_55 -> V_92 . V_95 , V_94 ,
L_1 , V_66 , V_27 -> V_95 ,
V_30 -> V_95 ) >= V_94 )
goto V_89;
V_55 -> V_92 . V_96 = V_76 ;
V_55 -> V_92 . V_96 |= ( V_27 -> V_96 |
V_30 -> V_96 ) & V_97 ;
V_55 -> V_92 . V_98 = ( V_27 -> V_98 +
V_30 -> V_98 ) / 2 ;
V_55 -> V_92 . V_90 = 1 ;
V_55 -> V_92 . V_99 = V_27 -> V_99 | V_30 -> V_99 ;
V_55 -> V_92 . V_100 = & V_101 ;
V_55 -> V_92 . V_102 . V_67 = V_67 ;
V_55 -> V_92 . V_102 . V_103 = V_43 ;
V_55 -> V_92 . V_104 = sizeof( struct V_8 ) + V_9 -> V_12 ;
V_55 -> V_92 . V_105 = F_59 ;
V_55 -> V_92 . V_106 = F_75 ;
V_55 -> V_92 . V_102 . V_107 = F_49 ;
V_55 -> V_92 . V_102 . V_108 = F_50 ;
V_55 -> V_92 . V_102 . V_109 = F_51 ;
V_55 -> V_92 . V_102 . V_110 = F_58 ;
V_55 -> V_92 . V_102 . V_111 = L_2 ;
V_112:
F_90 ( V_30 ) ;
return V_55 ;
V_89:
F_91 ( & V_9 -> V_27 ) ;
V_87:
F_92 ( & V_9 -> V_30 ) ;
V_86:
F_93 ( V_55 ) ;
V_83:
V_55 = F_78 ( V_3 ) ;
goto V_112;
}
static struct V_54 * F_94 ( struct V_64 * * V_65 )
{
return F_77 ( V_65 , L_3 , 12 ) ;
}
static struct V_54 * F_95 ( struct V_64 * * V_65 )
{
return F_77 ( V_65 , L_4 , 8 ) ;
}
static void F_96 ( struct V_54 * V_55 )
{
struct V_57 * V_9 = F_60 ( V_55 ) ;
F_91 ( & V_9 -> V_27 ) ;
F_92 ( & V_9 -> V_30 ) ;
F_93 ( V_55 ) ;
}
static int T_5 F_97 ( void )
{
int V_3 ;
V_3 = F_98 ( & V_113 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_98 ( & V_114 ) ;
if ( V_3 )
F_99 ( & V_113 ) ;
return V_3 ;
}
static void T_6 F_100 ( void )
{
F_99 ( & V_114 ) ;
F_99 ( & V_113 ) ;
}
