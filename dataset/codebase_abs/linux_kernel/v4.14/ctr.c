static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_9 ;
F_3 ( V_8 , V_10 ) ;
F_4 ( V_8 , F_5 ( V_2 ) &
V_10 ) ;
V_9 = F_6 ( V_8 , V_3 , V_4 ) ;
F_7 ( V_2 , F_8 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static void F_9 ( struct V_12 * V_13 ,
struct V_7 * V_14 )
{
unsigned int V_15 = F_10 ( V_14 ) ;
unsigned long V_16 = F_11 ( V_14 ) ;
T_1 * V_17 = V_13 -> V_18 ;
T_1 V_19 [ V_15 + V_16 ] ;
T_1 * V_20 = F_12 ( V_19 + 0 , V_16 + 1 ) ;
T_1 * V_21 = V_13 -> V_21 . V_22 . V_23 ;
T_1 * V_24 = V_13 -> V_24 . V_22 . V_23 ;
unsigned int V_25 = V_13 -> V_25 ;
F_13 ( V_14 , V_20 , V_17 ) ;
F_14 ( V_24 , V_20 , V_21 , V_25 ) ;
F_15 ( V_17 , V_15 ) ;
}
static int F_16 ( struct V_12 * V_13 ,
struct V_7 * V_14 )
{
void (* F_17)( struct V_1 * , T_1 * , const T_1 * ) =
F_18 ( V_14 ) -> V_26 ;
unsigned int V_15 = F_10 ( V_14 ) ;
T_1 * V_17 = V_13 -> V_18 ;
T_1 * V_21 = V_13 -> V_21 . V_22 . V_23 ;
T_1 * V_24 = V_13 -> V_24 . V_22 . V_23 ;
unsigned int V_25 = V_13 -> V_25 ;
do {
F_17 ( F_19 ( V_14 ) , V_24 , V_17 ) ;
F_20 ( V_24 , V_21 , V_15 ) ;
F_15 ( V_17 , V_15 ) ;
V_21 += V_15 ;
V_24 += V_15 ;
} while ( ( V_25 -= V_15 ) >= V_15 );
return V_25 ;
}
static int F_21 ( struct V_12 * V_13 ,
struct V_7 * V_14 )
{
void (* F_17)( struct V_1 * , T_1 * , const T_1 * ) =
F_18 ( V_14 ) -> V_26 ;
unsigned int V_15 = F_10 ( V_14 ) ;
unsigned long V_16 = F_11 ( V_14 ) ;
unsigned int V_25 = V_13 -> V_25 ;
T_1 * V_17 = V_13 -> V_18 ;
T_1 * V_21 = V_13 -> V_21 . V_22 . V_23 ;
T_1 V_19 [ V_15 + V_16 ] ;
T_1 * V_20 = F_12 ( V_19 + 0 , V_16 + 1 ) ;
do {
F_17 ( F_19 ( V_14 ) , V_20 , V_17 ) ;
F_20 ( V_21 , V_20 , V_15 ) ;
F_15 ( V_17 , V_15 ) ;
V_21 += V_15 ;
} while ( ( V_25 -= V_15 ) >= V_15 );
return V_25 ;
}
static int F_22 ( struct V_27 * V_28 ,
struct V_29 * V_24 , struct V_29 * V_21 ,
unsigned int V_25 )
{
struct V_12 V_13 ;
struct V_30 * V_14 = V_28 -> V_14 ;
struct V_5 * V_6 = F_23 ( V_14 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_15 = F_10 ( V_8 ) ;
int V_9 ;
F_24 ( & V_13 , V_24 , V_21 , V_25 ) ;
V_9 = F_25 ( V_28 , & V_13 , V_15 ) ;
while ( V_13 . V_25 >= V_15 ) {
if ( V_13 . V_21 . V_22 . V_23 == V_13 . V_24 . V_22 . V_23 )
V_25 = F_21 ( & V_13 , V_8 ) ;
else
V_25 = F_16 ( & V_13 , V_8 ) ;
V_9 = F_26 ( V_28 , & V_13 , V_25 ) ;
}
if ( V_13 . V_25 ) {
F_9 ( & V_13 , V_8 ) ;
V_9 = F_26 ( V_28 , & V_13 , 0 ) ;
}
return V_9 ;
}
static int F_27 ( struct V_1 * V_14 )
{
struct V_31 * V_32 = ( void * ) V_14 -> V_33 ;
struct V_34 * V_35 = F_28 ( V_32 ) ;
struct V_5 * V_6 = F_2 ( V_14 ) ;
struct V_7 * V_36 ;
V_36 = F_29 ( V_35 ) ;
if ( F_30 ( V_36 ) )
return F_31 ( V_36 ) ;
V_6 -> V_8 = V_36 ;
return 0 ;
}
static void F_32 ( struct V_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
F_33 ( V_6 -> V_8 ) ;
}
static struct V_31 * F_34 ( struct V_37 * * V_38 )
{
struct V_31 * V_32 ;
struct V_39 * V_40 ;
struct V_41 * V_42 ;
T_2 V_43 ;
int V_9 ;
V_9 = F_35 ( V_38 , V_44 ) ;
if ( V_9 )
return F_36 ( V_9 ) ;
V_40 = F_37 ( V_38 ) ;
if ( F_30 ( V_40 ) )
return F_38 ( V_40 ) ;
V_43 = V_45 |
F_39 ( V_40 -> type , V_40 -> V_43 ,
V_46 ) ;
V_42 = F_40 ( V_38 [ 1 ] , V_47 , V_43 ) ;
if ( F_30 ( V_42 ) )
return F_38 ( V_42 ) ;
V_9 = - V_48 ;
if ( V_42 -> V_49 < 4 )
goto V_50;
if ( V_42 -> V_49 % 4 )
goto V_50;
V_32 = F_41 ( L_1 , V_42 ) ;
if ( F_30 ( V_32 ) )
goto V_51;
V_32 -> V_42 . V_52 = V_44 ;
V_32 -> V_42 . V_53 = V_42 -> V_53 ;
V_32 -> V_42 . V_49 = 1 ;
V_32 -> V_42 . V_54 = V_42 -> V_54 ;
V_32 -> V_42 . V_55 = & V_56 ;
V_32 -> V_42 . V_57 . V_58 = V_42 -> V_49 ;
V_32 -> V_42 . V_57 . V_59 = V_42 -> V_60 . V_61 ;
V_32 -> V_42 . V_57 . V_62 = V_42 -> V_60 . V_63 ;
V_32 -> V_42 . V_64 = sizeof( struct V_5 ) ;
V_32 -> V_42 . V_65 = F_27 ;
V_32 -> V_42 . V_66 = F_32 ;
V_32 -> V_42 . V_57 . V_67 = F_1 ;
V_32 -> V_42 . V_57 . V_68 = F_22 ;
V_32 -> V_42 . V_57 . V_69 = F_22 ;
V_32 -> V_42 . V_57 . V_70 = L_2 ;
V_51:
F_42 ( V_42 ) ;
return V_32 ;
V_50:
V_32 = F_36 ( V_9 ) ;
goto V_51;
}
static void F_43 ( struct V_31 * V_32 )
{
F_44 ( F_28 ( V_32 ) ) ;
F_45 ( V_32 ) ;
}
static int F_46 ( struct V_71 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
struct V_72 * V_6 = F_47 ( V_2 ) ;
struct V_71 * V_8 = V_6 -> V_8 ;
int V_9 ;
if ( V_4 < V_73 )
return - V_48 ;
memcpy ( V_6 -> V_74 , V_3 + ( V_4 - V_73 ) ,
V_73 ) ;
V_4 -= V_73 ;
F_48 ( V_8 , V_10 ) ;
F_49 ( V_8 , F_50 ( V_2 ) &
V_10 ) ;
V_9 = F_51 ( V_8 , V_3 , V_4 ) ;
F_49 ( V_2 , F_50 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static int F_52 ( struct V_75 * V_76 )
{
struct V_71 * V_14 = F_53 ( V_76 ) ;
struct V_72 * V_6 = F_47 ( V_14 ) ;
struct V_71 * V_8 = V_6 -> V_8 ;
unsigned long V_77 = F_54 ( V_14 ) ;
struct V_78 * V_79 =
( void * ) F_12 ( ( T_1 * ) F_55 ( V_76 ) , V_77 + 1 ) ;
struct V_75 * V_80 = & V_79 -> V_80 ;
T_1 * V_18 = V_79 -> V_18 ;
memcpy ( V_18 , V_6 -> V_74 , V_73 ) ;
memcpy ( V_18 + V_73 , V_76 -> V_18 , V_81 ) ;
* ( V_82 * ) ( V_18 + V_73 + V_81 ) =
F_56 ( 1 ) ;
F_57 ( V_80 , V_8 ) ;
F_58 ( V_80 , V_76 -> V_83 . V_84 ,
V_76 -> V_83 . V_85 , V_76 -> V_83 . V_86 ) ;
F_59 ( V_80 , V_76 -> V_21 , V_76 -> V_24 ,
V_76 -> V_87 , V_18 ) ;
return F_60 ( V_80 ) ;
}
static int F_61 ( struct V_71 * V_14 )
{
struct V_88 * V_32 = F_62 ( V_14 ) ;
struct V_89 * V_35 = F_63 ( V_32 ) ;
struct V_72 * V_6 = F_47 ( V_14 ) ;
struct V_71 * V_36 ;
unsigned long V_77 ;
unsigned int V_90 ;
V_36 = F_64 ( V_35 ) ;
if ( F_30 ( V_36 ) )
return F_31 ( V_36 ) ;
V_6 -> V_8 = V_36 ;
V_77 = F_54 ( V_14 ) ;
V_77 &= ~ ( F_65 () - 1 ) ;
V_90 = V_77 + sizeof( struct V_78 ) +
F_66 ( V_36 ) ;
F_67 ( V_14 , V_90 ) ;
return 0 ;
}
static void F_68 ( struct V_71 * V_14 )
{
struct V_72 * V_6 = F_47 ( V_14 ) ;
F_69 ( V_6 -> V_8 ) ;
}
static void F_70 ( struct V_88 * V_32 )
{
struct V_89 * V_35 = F_63 ( V_32 ) ;
F_71 ( V_35 ) ;
F_45 ( V_32 ) ;
}
static int F_72 ( struct V_91 * V_92 ,
struct V_37 * * V_38 )
{
struct V_39 * V_40 ;
struct V_88 * V_32 ;
struct V_93 * V_42 ;
struct V_89 * V_35 ;
const char * V_94 ;
T_2 V_43 ;
int V_9 ;
V_40 = F_37 ( V_38 ) ;
if ( F_30 ( V_40 ) )
return F_31 ( V_40 ) ;
if ( ( V_40 -> type ^ V_95 ) & V_40 -> V_43 )
return - V_48 ;
V_94 = F_73 ( V_38 [ 1 ] ) ;
if ( F_30 ( V_94 ) )
return F_31 ( V_94 ) ;
V_32 = F_74 ( sizeof( * V_32 ) + sizeof( * V_35 ) , V_96 ) ;
if ( ! V_32 )
return - V_97 ;
V_43 = F_75 ( V_40 -> type , V_40 -> V_43 ) |
F_39 ( V_40 -> type , V_40 -> V_43 ,
V_46 ) ;
V_35 = F_63 ( V_32 ) ;
F_76 ( V_35 , F_77 ( V_32 ) ) ;
V_9 = F_78 ( V_35 , V_94 , 0 , V_43 ) ;
if ( V_9 )
goto V_98;
V_42 = F_79 ( V_35 ) ;
V_9 = - V_48 ;
if ( F_80 ( V_42 ) != V_99 )
goto V_100;
if ( V_42 -> V_83 . V_49 != 1 )
goto V_100;
V_9 = - V_101 ;
if ( snprintf ( V_32 -> V_42 . V_83 . V_102 , V_103 ,
L_3 , V_42 -> V_83 . V_102 ) >= V_103 )
goto V_100;
if ( snprintf ( V_32 -> V_42 . V_83 . V_104 , V_103 ,
L_3 , V_42 -> V_83 . V_104 ) >=
V_103 )
goto V_100;
V_32 -> V_42 . V_83 . V_53 = V_42 -> V_83 . V_53 ;
V_32 -> V_42 . V_83 . V_49 = 1 ;
V_32 -> V_42 . V_83 . V_54 = V_42 -> V_83 . V_54 ;
V_32 -> V_42 . V_83 . V_52 = V_42 -> V_83 . V_52 & V_105 ;
V_32 -> V_42 . V_58 = V_81 ;
V_32 -> V_42 . V_106 = F_81 ( V_42 ) ;
V_32 -> V_42 . V_59 = F_82 ( V_42 ) +
V_73 ;
V_32 -> V_42 . V_62 = F_83 ( V_42 ) +
V_73 ;
V_32 -> V_42 . V_67 = F_46 ;
V_32 -> V_42 . V_68 = F_52 ;
V_32 -> V_42 . V_69 = F_52 ;
V_32 -> V_42 . V_83 . V_64 = sizeof( struct V_72 ) ;
V_32 -> V_42 . V_107 = F_61 ;
V_32 -> V_42 . exit = F_68 ;
V_32 -> free = F_70 ;
V_9 = F_84 ( V_92 , V_32 ) ;
if ( V_9 )
goto V_100;
V_51:
return V_9 ;
V_100:
F_71 ( V_35 ) ;
V_98:
F_45 ( V_32 ) ;
goto V_51;
}
static int T_3 F_85 ( void )
{
int V_9 ;
V_9 = F_86 ( & V_108 ) ;
if ( V_9 )
goto V_51;
V_9 = F_86 ( & V_109 ) ;
if ( V_9 )
goto V_110;
V_51:
return V_9 ;
V_110:
F_87 ( & V_108 ) ;
goto V_51;
}
static void T_4 F_88 ( void )
{
F_87 ( & V_109 ) ;
F_87 ( & V_108 ) ;
}
