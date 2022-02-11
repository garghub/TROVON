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
struct V_30 * V_31 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_31 ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
T_4 V_35 ;
int V_3 ;
F_15 ( V_33 -> V_17 , 1 ) ;
V_35 = F_25 ( V_15 -> V_18 ) ;
memcpy ( & V_33 -> V_36 . V_18 , & V_35 , sizeof( V_35 ) ) ;
V_35 = F_25 ( V_15 -> V_19 ) ;
memcpy ( & V_33 -> V_36 . V_19 , & V_35 , sizeof( V_35 ) ) ;
F_26 ( V_33 -> V_17 , & V_33 -> V_36 , sizeof( V_33 -> V_36 ) ) ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_23 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
F_29 ( & V_33 -> V_2 , V_33 -> V_17 ,
V_15 -> V_16 , sizeof( V_33 -> V_36 ) ) ;
V_3 = F_30 ( & V_33 -> V_2 ) ;
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
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
unsigned int V_37 , V_38 = V_39 ;
int V_3 ;
V_37 = ( V_38 - ( V_15 -> V_19 % V_38 ) ) % V_38 ;
memset ( V_33 -> V_40 , 0 , sizeof( V_33 -> V_40 ) ) ;
F_15 ( V_33 -> V_17 , 1 ) ;
F_26 ( V_33 -> V_17 , & V_33 -> V_40 , V_37 ) ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_31 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
F_29 ( & V_33 -> V_2 , V_33 -> V_17 , NULL , V_37 ) ;
V_3 = F_33 ( & V_33 -> V_2 ) ;
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
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
struct V_29 * V_41 = V_2 -> V_17 ;
int V_3 ;
if ( V_15 -> V_19 == V_2 -> V_19 )
V_41 = V_2 -> V_21 ;
F_15 ( V_15 -> V_17 , 2 ) ;
V_41 = F_16 ( V_15 -> V_17 , V_41 , V_2 -> V_18 ) ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_34 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
F_29 ( & V_33 -> V_2 , V_41 , NULL , V_15 -> V_19 ) ;
V_3 = F_33 ( & V_33 -> V_2 ) ;
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
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
unsigned int V_37 , V_38 = V_39 ;
int V_3 ;
V_37 = ( V_38 - ( V_15 -> V_18 % V_38 ) ) % V_38 ;
memset ( V_33 -> V_40 , 0 , sizeof( V_33 -> V_40 ) ) ;
F_15 ( V_33 -> V_17 , 1 ) ;
F_26 ( V_33 -> V_17 , V_33 -> V_40 , V_37 ) ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_36 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
F_29 ( & V_33 -> V_2 , V_33 -> V_17 , NULL , V_37 ) ;
V_3 = F_33 ( & V_33 -> V_2 ) ;
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
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
int V_3 ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_38 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
F_29 ( & V_33 -> V_2 , V_2 -> V_17 , NULL , V_15 -> V_18 ) ;
V_3 = F_33 ( & V_33 -> V_2 ) ;
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
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
int V_3 ;
F_15 ( V_33 -> V_17 , 1 ) ;
F_26 ( V_33 -> V_17 , V_15 -> V_42 , sizeof( V_15 -> V_42 ) ) ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_40 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
F_29 ( & V_33 -> V_2 , V_33 -> V_17 , NULL , sizeof( V_15 -> V_42 ) ) ;
V_3 = F_33 ( & V_33 -> V_2 ) ;
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
struct V_32 * V_33 = & V_15 -> V_27 . V_34 ;
int V_3 ;
F_27 ( & V_33 -> V_2 , F_18 ( V_2 ) ,
F_42 , V_2 ) ;
F_28 ( & V_33 -> V_2 , V_9 -> V_34 ) ;
V_3 = F_44 ( & V_33 -> V_2 ) ;
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
struct V_30 * V_31 = F_6 ( V_2 ) ;
struct V_8 * V_9 = F_5 ( V_31 ) ;
struct V_14 * V_15 = F_9 ( V_2 ) ;
struct V_25 * V_26 = & V_15 -> V_27 . V_28 ;
int V_3 ;
V_15 -> V_18 = V_2 -> V_18 ;
if ( F_47 ( V_31 ) == 8 ) {
if ( V_15 -> V_18 < 8 )
return - V_43 ;
V_15 -> V_18 -= 8 ;
}
F_15 ( V_26 -> V_17 , 1 ) ;
memset ( V_15 -> V_42 , 0 , sizeof( V_15 -> V_42 ) ) ;
F_26 ( V_26 -> V_17 , V_15 -> V_42 , sizeof( V_15 -> V_42 ) ) ;
F_4 ( V_26 -> V_6 , V_2 , 0 ) ;
F_17 ( & V_26 -> V_2 , F_18 ( V_2 ) ,
F_45 , V_2 ) ;
F_19 ( & V_26 -> V_2 , V_9 -> V_28 ) ;
F_20 ( & V_26 -> V_2 , V_26 -> V_17 , V_26 -> V_17 ,
V_44 , V_26 -> V_6 ) ;
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
V_15 -> V_19 = V_2 -> V_19 - V_45 ;
return F_46 ( V_2 ) ;
}
static int F_53 ( struct V_30 * V_46 , const T_1 * V_42 ,
unsigned int V_47 )
{
struct V_8 * V_9 = F_5 ( V_46 ) ;
int V_3 ;
if ( V_47 != V_9 -> V_12 + V_48 )
return - V_43 ;
V_47 -= V_9 -> V_12 ;
memcpy ( V_9 -> V_11 , V_42 + V_47 , V_9 -> V_12 ) ;
F_54 ( V_9 -> V_28 , V_49 ) ;
F_55 ( V_9 -> V_28 , F_56 ( V_46 ) &
V_49 ) ;
V_3 = F_57 ( V_9 -> V_28 , V_42 , V_47 ) ;
F_58 ( V_46 , F_59 ( V_9 -> V_28 ) &
V_50 ) ;
return V_3 ;
}
static int F_60 ( struct V_30 * V_31 ,
unsigned int V_51 )
{
if ( V_51 != V_45 )
return - V_43 ;
return 0 ;
}
static int F_61 ( struct V_30 * V_31 )
{
struct V_52 * V_53 = F_62 ( V_31 ) ;
struct V_54 * V_55 = F_63 ( V_53 ) ;
struct V_8 * V_9 = F_5 ( V_31 ) ;
struct V_56 * V_28 ;
struct V_57 * V_34 ;
unsigned long V_58 ;
V_34 = F_64 ( & V_55 -> V_34 ) ;
if ( F_65 ( V_34 ) )
return F_66 ( V_34 ) ;
V_28 = F_67 ( & V_55 -> V_28 ) ;
if ( F_65 ( V_28 ) ) {
F_68 ( V_34 ) ;
return F_66 ( V_28 ) ;
}
V_9 -> V_28 = V_28 ;
V_9 -> V_34 = V_34 ;
V_9 -> V_12 = V_55 -> V_12 ;
V_58 = F_69 ( V_31 ) ;
V_58 &= ~ ( F_70 () - 1 ) ;
F_71 (
V_31 ,
V_58 + F_72 ( struct V_14 , V_27 ) +
F_73 ( F_72 ( struct V_25 , V_2 ) +
sizeof( struct V_59 ) +
F_74 ( V_28 ) ,
F_72 ( struct V_32 , V_2 ) +
sizeof( struct V_60 ) +
F_75 ( V_34 ) ) ) ;
return 0 ;
}
static void F_76 ( struct V_30 * V_31 )
{
struct V_8 * V_9 = F_5 ( V_31 ) ;
F_68 ( V_9 -> V_34 ) ;
F_77 ( V_9 -> V_28 ) ;
}
static void F_78 ( struct V_52 * V_53 )
{
struct V_54 * V_9 = F_63 ( V_53 ) ;
F_79 ( & V_9 -> V_28 ) ;
F_80 ( & V_9 -> V_34 ) ;
F_81 ( V_53 ) ;
}
static int F_82 ( struct V_61 * V_62 , struct V_63 * * V_64 ,
const char * V_65 , unsigned int V_66 )
{
struct V_67 * V_68 ;
struct V_52 * V_53 ;
struct V_69 * V_28 ;
struct V_69 * V_34 ;
struct V_70 * V_71 ;
struct V_54 * V_9 ;
const char * V_72 , * V_73 ;
int V_3 ;
if ( V_66 > V_74 )
return - V_43 ;
V_68 = F_83 ( V_64 ) ;
if ( F_65 ( V_68 ) )
return F_66 ( V_68 ) ;
if ( ( V_68 -> type ^ V_75 ) & V_68 -> V_76 )
return - V_43 ;
V_72 = F_84 ( V_64 [ 1 ] ) ;
if ( F_65 ( V_72 ) )
return F_66 ( V_72 ) ;
V_73 = F_84 ( V_64 [ 2 ] ) ;
if ( F_65 ( V_73 ) )
return F_66 ( V_73 ) ;
V_34 = F_85 ( V_73 , & V_77 ,
V_78 ,
V_79 ) ;
if ( F_65 ( V_34 ) )
return F_66 ( V_34 ) ;
V_3 = - V_80 ;
V_53 = F_86 ( sizeof( * V_53 ) + sizeof( * V_9 ) , V_81 ) ;
if ( ! V_53 )
goto V_82;
V_9 = F_63 ( V_53 ) ;
V_9 -> V_12 = V_74 - V_66 ;
V_71 = F_87 ( V_34 ) ;
V_3 = F_88 ( & V_9 -> V_34 , V_71 ,
F_89 ( V_53 ) ) ;
if ( V_3 )
goto V_83;
F_90 ( & V_9 -> V_28 , F_89 ( V_53 ) ) ;
V_3 = F_91 ( & V_9 -> V_28 , V_72 , 0 ,
F_92 ( V_68 -> type ,
V_68 -> V_76 ) ) ;
if ( V_3 )
goto V_84;
V_28 = F_93 ( & V_9 -> V_28 ) ;
V_3 = - V_43 ;
if ( V_28 -> V_85 . V_66 != V_13 )
goto V_86;
if ( V_28 -> V_87 != 1 )
goto V_86;
V_3 = - V_88 ;
if ( snprintf ( V_53 -> V_89 . V_90 . V_91 , V_92 ,
L_1 , V_65 , V_72 ,
V_73 ) >= V_92 )
goto V_86;
if ( snprintf ( V_53 -> V_89 . V_90 . V_93 , V_92 ,
L_1 , V_65 , V_28 -> V_93 ,
V_34 -> V_93 ) >= V_92 )
goto V_86;
V_53 -> V_89 . V_90 . V_94 = ( V_28 -> V_94 | V_34 -> V_94 ) &
V_95 ;
V_53 -> V_89 . V_90 . V_96 = ( V_28 -> V_96 +
V_34 -> V_96 ) / 2 ;
V_53 -> V_89 . V_90 . V_87 = 1 ;
V_53 -> V_89 . V_90 . V_97 = V_28 -> V_97 |
V_34 -> V_97 ;
V_53 -> V_89 . V_90 . V_98 = sizeof( struct V_8 ) +
V_9 -> V_12 ;
V_53 -> V_89 . V_66 = V_66 ;
V_53 -> V_89 . V_99 = V_45 ;
V_53 -> V_89 . V_100 = F_61 ;
V_53 -> V_89 . exit = F_76 ;
V_53 -> V_89 . V_101 = F_51 ;
V_53 -> V_89 . V_102 = F_52 ;
V_53 -> V_89 . V_103 = F_53 ;
V_53 -> V_89 . V_104 = F_60 ;
V_53 -> free = F_78 ;
V_3 = F_94 ( V_62 , V_53 ) ;
if ( V_3 )
goto V_86;
V_82:
F_95 ( V_34 ) ;
return V_3 ;
V_86:
F_79 ( & V_9 -> V_28 ) ;
V_84:
F_80 ( & V_9 -> V_34 ) ;
V_83:
F_81 ( V_53 ) ;
goto V_82;
}
static int F_96 ( struct V_61 * V_62 , struct V_63 * * V_64 )
{
return F_82 ( V_62 , V_64 , L_2 , 12 ) ;
}
static int F_97 ( struct V_61 * V_62 , struct V_63 * * V_64 )
{
return F_82 ( V_62 , V_64 , L_3 , 8 ) ;
}
static int T_5 F_98 ( void )
{
int V_3 ;
V_3 = F_99 ( & V_105 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_99 ( & V_106 ) ;
if ( V_3 )
F_100 ( & V_105 ) ;
return V_3 ;
}
static void T_6 F_101 ( void )
{
F_100 ( & V_106 ) ;
F_100 ( & V_105 ) ;
}
