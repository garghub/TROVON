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
F_10 ( V_16 , V_2 -> V_17 ,
V_2 -> V_18 + V_15 -> V_19 ,
sizeof( V_16 ) , 0 ) ;
if ( F_11 ( V_16 , V_15 -> V_16 , sizeof( V_16 ) ) )
return - V_20 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
F_10 ( V_15 -> V_16 , V_2 -> V_21 ,
V_2 -> V_18 + V_15 -> V_19 ,
sizeof( V_15 -> V_16 ) , 1 ) ;
return 0 ;
}
static void F_13 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_8 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_25 * V_26 = & V_15 -> V_27 . V_28 ;
struct V_29 * V_17 , * V_21 ;
int V_3 ;
if ( V_15 -> V_19 == 0 )
goto V_30;
F_4 ( V_26 -> V_6 , V_2 , 1 ) ;
F_15 ( V_15 -> V_17 , 2 ) ;
V_17 = F_16 ( V_15 -> V_17 , V_2 -> V_17 , V_2 -> V_18 ) ;
V_21 = V_17 ;
if ( V_2 -> V_17 != V_2 -> V_21 ) {
F_15 ( V_15 -> V_21 , 2 ) ;
V_21 = F_16 ( V_15 -> V_21 , V_2 -> V_21 , V_2 -> V_18 ) ;
}
F_17 ( & V_26 -> V_2 , F_18 ( V_2 ) ,
F_13 , V_2 ) ;
F_19 ( & V_26 -> V_2 , V_9 -> V_28 ) ;
F_20 ( & V_26 -> V_2 , V_17 , V_21 ,
V_15 -> V_19 , V_26 -> V_6 ) ;
V_3 = F_21 ( & V_26 -> V_2 ) ;
if ( V_3 )
return V_3 ;
V_30:
return F_8 ( V_2 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
if ( V_15 -> V_19 == V_2 -> V_19 )
return F_12 ( V_2 ) ;
return F_14 ( V_2 ) ;
}
static void F_23 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_22 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_32 ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
T_4 V_36 ;
int V_3 ;
F_15 ( V_34 -> V_17 , 1 ) ;
V_36 = F_25 ( V_15 -> V_18 ) ;
memcpy ( & V_34 -> V_37 . V_18 , & V_36 , sizeof( V_36 ) ) ;
V_36 = F_25 ( V_15 -> V_19 ) ;
memcpy ( & V_34 -> V_37 . V_19 , & V_36 , sizeof( V_36 ) ) ;
F_26 ( V_34 -> V_17 , & V_34 -> V_37 , sizeof( V_34 -> V_37 ) ) ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_23 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
F_29 ( & V_34 -> V_2 , V_34 -> V_17 ,
V_15 -> V_16 , sizeof( V_34 -> V_37 ) ) ;
V_3 = F_30 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_22 ( V_2 ) ;
}
static void F_31 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_24 ) ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
unsigned int V_38 , V_39 = V_40 ;
int V_3 ;
V_38 = ( V_39 - ( V_15 -> V_19 % V_39 ) ) % V_39 ;
memset ( V_34 -> V_41 , 0 , sizeof( V_34 -> V_41 ) ) ;
F_15 ( V_34 -> V_17 , 1 ) ;
F_26 ( V_34 -> V_17 , & V_34 -> V_41 , V_38 ) ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_31 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
F_29 ( & V_34 -> V_2 , V_34 -> V_17 , NULL , V_38 ) ;
V_3 = F_33 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_24 ( V_2 ) ;
}
static void F_34 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_32 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
struct V_29 * V_42 = V_2 -> V_17 ;
int V_3 ;
if ( V_15 -> V_19 == V_2 -> V_19 )
V_42 = V_2 -> V_21 ;
F_15 ( V_15 -> V_17 , 2 ) ;
V_42 = F_16 ( V_15 -> V_17 , V_42 , V_2 -> V_18 ) ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_34 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
F_29 ( & V_34 -> V_2 , V_42 , NULL , V_15 -> V_19 ) ;
V_3 = F_33 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_32 ( V_2 ) ;
}
static void F_36 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_35 ) ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
unsigned int V_38 , V_39 = V_40 ;
int V_3 ;
V_38 = ( V_39 - ( V_15 -> V_18 % V_39 ) ) % V_39 ;
memset ( V_34 -> V_41 , 0 , sizeof( V_34 -> V_41 ) ) ;
F_15 ( V_34 -> V_17 , 1 ) ;
F_26 ( V_34 -> V_17 , V_34 -> V_41 , V_38 ) ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_36 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
F_29 ( & V_34 -> V_2 , V_34 -> V_17 , NULL , V_38 ) ;
V_3 = F_33 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_35 ( V_2 ) ;
}
static void F_38 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_37 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
int V_3 ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_38 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
F_29 ( & V_34 -> V_2 , V_2 -> V_17 , NULL , V_15 -> V_18 ) ;
V_3 = F_33 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_37 ( V_2 ) ;
}
static void F_40 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_39 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
int V_3 ;
F_15 ( V_34 -> V_17 , 1 ) ;
F_26 ( V_34 -> V_17 , V_15 -> V_43 , sizeof( V_15 -> V_43 ) ) ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_40 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
F_29 ( & V_34 -> V_2 , V_34 -> V_17 , NULL , sizeof( V_15 -> V_43 ) ) ;
V_3 = F_33 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_39 ( V_2 ) ;
}
static void F_42 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_41 ) ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_33 * V_34 = & V_15 -> V_27 . V_35 ;
int V_3 ;
F_27 ( & V_34 -> V_2 , F_18 ( V_2 ) ,
F_42 , V_2 ) ;
F_28 ( & V_34 -> V_2 , V_9 -> V_35 ) ;
V_3 = F_44 ( & V_34 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_41 ( V_2 ) ;
}
static void F_45 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_43 ) ;
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_32 ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_25 * V_26 = & V_15 -> V_27 . V_28 ;
int V_3 ;
V_15 -> V_18 = V_2 -> V_18 ;
if ( F_47 ( V_32 ) == 8 ) {
if ( V_15 -> V_18 < 8 )
return - V_44 ;
V_15 -> V_18 -= 8 ;
}
F_15 ( V_26 -> V_17 , 1 ) ;
memset ( V_15 -> V_43 , 0 , sizeof( V_15 -> V_43 ) ) ;
F_26 ( V_26 -> V_17 , V_15 -> V_43 , sizeof( V_15 -> V_43 ) ) ;
F_4 ( V_26 -> V_6 , V_2 , 0 ) ;
F_17 ( & V_26 -> V_2 , F_18 ( V_2 ) ,
F_45 , V_2 ) ;
F_19 ( & V_26 -> V_2 , V_9 -> V_28 ) ;
F_20 ( & V_26 -> V_2 , V_26 -> V_17 , V_26 -> V_17 ,
V_45 , V_26 -> V_6 ) ;
V_3 = F_21 ( & V_26 -> V_2 ) ;
if ( V_3 )
return V_3 ;
return F_43 ( V_2 ) ;
}
static void F_48 ( struct V_22 * V_23 , int V_3 )
{
F_1 ( V_23 -> V_24 , V_3 , F_46 ) ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( F_6 ( V_2 ) ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_25 * V_26 = & V_15 -> V_27 . V_28 ;
struct V_29 * V_17 , * V_21 ;
int V_3 ;
if ( V_2 -> V_19 == 0 )
goto V_30;
F_4 ( V_26 -> V_6 , V_2 , 1 ) ;
F_15 ( V_15 -> V_17 , 2 ) ;
V_17 = F_16 ( V_15 -> V_17 , V_2 -> V_17 , V_2 -> V_18 ) ;
V_21 = V_17 ;
if ( V_2 -> V_17 != V_2 -> V_21 ) {
F_15 ( V_15 -> V_21 , 2 ) ;
V_21 = F_16 ( V_15 -> V_21 , V_2 -> V_21 , V_2 -> V_18 ) ;
}
F_17 ( & V_26 -> V_2 , F_18 ( V_2 ) ,
F_48 , V_2 ) ;
F_19 ( & V_26 -> V_2 , V_9 -> V_28 ) ;
F_20 ( & V_26 -> V_2 , V_17 , V_21 ,
V_2 -> V_19 , V_26 -> V_6 ) ;
V_3 = F_50 ( & V_26 -> V_2 ) ;
if ( V_3 )
return V_3 ;
V_30:
return F_46 ( V_2 ) ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
V_15 -> V_19 = V_2 -> V_19 ;
return F_49 ( V_2 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_9 ( V_2 ) ;
V_15 -> V_19 = V_2 -> V_19 - V_46 ;
return F_46 ( V_2 ) ;
}
static int F_53 ( struct V_31 * V_47 , const T_1 * V_43 ,
unsigned int V_48 )
{
struct V_8 * V_9 = F_5 ( V_47 ) ;
int V_3 ;
if ( V_48 != V_9 -> V_12 + V_49 )
return - V_44 ;
V_48 -= V_9 -> V_12 ;
memcpy ( V_9 -> V_11 , V_43 + V_48 , V_9 -> V_12 ) ;
F_54 ( V_9 -> V_28 , V_50 ) ;
F_55 ( V_9 -> V_28 , F_56 ( V_47 ) &
V_50 ) ;
V_3 = F_57 ( V_9 -> V_28 , V_43 , V_48 ) ;
F_58 ( V_47 , F_59 ( V_9 -> V_28 ) &
V_51 ) ;
return V_3 ;
}
static int F_60 ( struct V_31 * V_32 ,
unsigned int V_52 )
{
if ( V_52 != V_46 )
return - V_44 ;
return 0 ;
}
static int F_61 ( struct V_31 * V_32 )
{
struct V_53 * V_54 = F_62 ( V_32 ) ;
struct V_55 * V_56 = F_63 ( V_54 ) ;
struct V_8 * V_9 = F_5 ( V_32 ) ;
struct V_57 * V_28 ;
struct V_58 * V_35 ;
unsigned long V_59 ;
V_35 = F_64 ( & V_56 -> V_35 ) ;
if ( F_65 ( V_35 ) )
return F_66 ( V_35 ) ;
V_28 = F_67 ( & V_56 -> V_28 ) ;
if ( F_65 ( V_28 ) ) {
F_68 ( V_35 ) ;
return F_66 ( V_28 ) ;
}
V_9 -> V_28 = V_28 ;
V_9 -> V_35 = V_35 ;
V_9 -> V_12 = V_56 -> V_12 ;
V_59 = F_69 ( V_32 ) ;
V_59 &= ~ ( F_70 () - 1 ) ;
F_71 (
V_32 ,
V_59 + F_72 ( struct V_14 , V_27 ) +
F_73 ( F_72 ( struct V_25 , V_2 ) +
sizeof( struct V_60 ) +
F_74 ( V_28 ) ,
F_72 ( struct V_33 , V_2 ) +
sizeof( struct V_61 ) +
F_75 ( V_35 ) ) ) ;
return 0 ;
}
static void F_76 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = F_5 ( V_32 ) ;
F_68 ( V_9 -> V_35 ) ;
F_77 ( V_9 -> V_28 ) ;
}
static void F_78 ( struct V_53 * V_54 )
{
struct V_55 * V_9 = F_63 ( V_54 ) ;
F_79 ( & V_9 -> V_28 ) ;
F_80 ( & V_9 -> V_35 ) ;
F_81 ( V_54 ) ;
}
static int F_82 ( struct V_62 * V_63 , struct V_64 * * V_65 ,
const char * V_66 , unsigned int V_67 )
{
struct V_68 * V_69 ;
struct V_53 * V_54 ;
struct V_70 * V_28 ;
struct V_71 * V_35 ;
struct V_72 * V_73 ;
struct V_55 * V_9 ;
const char * V_74 , * V_75 ;
int V_3 ;
if ( V_67 > V_76 )
return - V_44 ;
V_69 = F_83 ( V_65 ) ;
if ( F_65 ( V_69 ) )
return F_66 ( V_69 ) ;
if ( ( V_69 -> type ^ V_77 ) & V_69 -> V_78 )
return - V_44 ;
V_74 = F_84 ( V_65 [ 1 ] ) ;
if ( F_65 ( V_74 ) )
return F_66 ( V_74 ) ;
V_75 = F_84 ( V_65 [ 2 ] ) ;
if ( F_65 ( V_75 ) )
return F_66 ( V_75 ) ;
V_35 = F_85 ( V_75 , & V_79 ,
V_80 ,
V_81 |
F_86 ( V_69 -> type ,
V_69 -> V_78 ) ) ;
if ( F_65 ( V_35 ) )
return F_66 ( V_35 ) ;
V_3 = - V_82 ;
V_54 = F_87 ( sizeof( * V_54 ) + sizeof( * V_9 ) , V_83 ) ;
if ( ! V_54 )
goto V_84;
V_9 = F_63 ( V_54 ) ;
V_9 -> V_12 = V_76 - V_67 ;
V_73 = F_88 ( V_35 ) ;
V_3 = F_89 ( & V_9 -> V_35 , V_73 ,
F_90 ( V_54 ) ) ;
if ( V_3 )
goto V_85;
F_91 ( & V_9 -> V_28 , F_90 ( V_54 ) ) ;
V_3 = F_92 ( & V_9 -> V_28 , V_74 , 0 ,
F_86 ( V_69 -> type ,
V_69 -> V_78 ) ) ;
if ( V_3 )
goto V_86;
V_28 = F_93 ( & V_9 -> V_28 ) ;
V_3 = - V_44 ;
if ( F_94 ( V_28 ) != V_13 )
goto V_87;
if ( V_28 -> V_88 . V_89 != 1 )
goto V_87;
V_3 = - V_90 ;
if ( snprintf ( V_54 -> V_91 . V_88 . V_92 , V_93 ,
L_1 , V_66 , V_74 ,
V_75 ) >= V_93 )
goto V_87;
if ( snprintf ( V_54 -> V_91 . V_88 . V_94 , V_93 ,
L_1 , V_66 , V_28 -> V_88 . V_94 ,
V_35 -> V_94 ) >= V_93 )
goto V_87;
V_54 -> V_91 . V_88 . V_95 = ( V_28 -> V_88 . V_95 | V_35 -> V_95 ) &
V_96 ;
V_54 -> V_91 . V_88 . V_97 = ( V_28 -> V_88 . V_97 +
V_35 -> V_97 ) / 2 ;
V_54 -> V_91 . V_88 . V_89 = 1 ;
V_54 -> V_91 . V_88 . V_98 = V_28 -> V_88 . V_98 |
V_35 -> V_98 ;
V_54 -> V_91 . V_88 . V_99 = sizeof( struct V_8 ) +
V_9 -> V_12 ;
V_54 -> V_91 . V_67 = V_67 ;
V_54 -> V_91 . V_100 = F_95 ( V_28 ) ;
V_54 -> V_91 . V_101 = V_46 ;
V_54 -> V_91 . V_102 = F_61 ;
V_54 -> V_91 . exit = F_76 ;
V_54 -> V_91 . V_103 = F_51 ;
V_54 -> V_91 . V_104 = F_52 ;
V_54 -> V_91 . V_105 = F_53 ;
V_54 -> V_91 . V_106 = F_60 ;
V_54 -> free = F_78 ;
V_3 = F_96 ( V_63 , V_54 ) ;
if ( V_3 )
goto V_87;
V_84:
F_97 ( V_35 ) ;
return V_3 ;
V_87:
F_79 ( & V_9 -> V_28 ) ;
V_86:
F_80 ( & V_9 -> V_35 ) ;
V_85:
F_81 ( V_54 ) ;
goto V_84;
}
static int F_98 ( struct V_62 * V_63 , struct V_64 * * V_65 )
{
return F_82 ( V_63 , V_65 , L_2 , 12 ) ;
}
static int F_99 ( struct V_62 * V_63 , struct V_64 * * V_65 )
{
return F_82 ( V_63 , V_65 , L_3 , 8 ) ;
}
static int T_5 F_100 ( void )
{
int V_3 ;
V_3 = F_101 ( & V_107 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_101 ( & V_108 ) ;
if ( V_3 )
F_102 ( & V_107 ) ;
return V_3 ;
}
static void T_6 F_103 ( void )
{
F_102 ( & V_108 ) ;
F_102 ( & V_107 ) ;
}
