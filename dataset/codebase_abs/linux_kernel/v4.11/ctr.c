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
F_14 ( V_20 , V_21 , V_25 ) ;
memcpy ( V_24 , V_20 , V_25 ) ;
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
F_14 ( V_24 , V_21 , V_15 ) ;
F_15 ( V_17 , V_15 ) ;
V_21 += V_15 ;
V_24 += V_15 ;
} while ( ( V_25 -= V_15 ) >= V_15 );
return V_25 ;
}
static int F_20 ( struct V_12 * V_13 ,
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
F_14 ( V_21 , V_20 , V_15 ) ;
F_15 ( V_17 , V_15 ) ;
V_21 += V_15 ;
} while ( ( V_25 -= V_15 ) >= V_15 );
return V_25 ;
}
static int F_21 ( struct V_27 * V_28 ,
struct V_29 * V_24 , struct V_29 * V_21 ,
unsigned int V_25 )
{
struct V_12 V_13 ;
struct V_30 * V_14 = V_28 -> V_14 ;
struct V_5 * V_6 = F_22 ( V_14 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned int V_15 = F_10 ( V_8 ) ;
int V_9 ;
F_23 ( & V_13 , V_24 , V_21 , V_25 ) ;
V_9 = F_24 ( V_28 , & V_13 , V_15 ) ;
while ( V_13 . V_25 >= V_15 ) {
if ( V_13 . V_21 . V_22 . V_23 == V_13 . V_24 . V_22 . V_23 )
V_25 = F_20 ( & V_13 , V_8 ) ;
else
V_25 = F_16 ( & V_13 , V_8 ) ;
V_9 = F_25 ( V_28 , & V_13 , V_25 ) ;
}
if ( V_13 . V_25 ) {
F_9 ( & V_13 , V_8 ) ;
V_9 = F_25 ( V_28 , & V_13 , 0 ) ;
}
return V_9 ;
}
static int F_26 ( struct V_1 * V_14 )
{
struct V_31 * V_32 = ( void * ) V_14 -> V_33 ;
struct V_34 * V_35 = F_27 ( V_32 ) ;
struct V_5 * V_6 = F_2 ( V_14 ) ;
struct V_7 * V_36 ;
V_36 = F_28 ( V_35 ) ;
if ( F_29 ( V_36 ) )
return F_30 ( V_36 ) ;
V_6 -> V_8 = V_36 ;
return 0 ;
}
static void F_31 ( struct V_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_14 ) ;
F_32 ( V_6 -> V_8 ) ;
}
static struct V_31 * F_33 ( struct V_37 * * V_38 )
{
struct V_31 * V_32 ;
struct V_39 * V_40 ;
int V_9 ;
V_9 = F_34 ( V_38 , V_41 ) ;
if ( V_9 )
return F_35 ( V_9 ) ;
V_40 = F_36 ( V_38 [ 1 ] , V_42 ,
V_43 ) ;
if ( F_29 ( V_40 ) )
return F_37 ( V_40 ) ;
V_9 = - V_44 ;
if ( V_40 -> V_45 < 4 )
goto V_46;
if ( V_40 -> V_45 % 4 )
goto V_46;
V_32 = F_38 ( L_1 , V_40 ) ;
if ( F_29 ( V_32 ) )
goto V_47;
V_32 -> V_40 . V_48 = V_41 ;
V_32 -> V_40 . V_49 = V_40 -> V_49 ;
V_32 -> V_40 . V_45 = 1 ;
V_32 -> V_40 . V_50 = V_40 -> V_50 ;
V_32 -> V_40 . V_51 = & V_52 ;
V_32 -> V_40 . V_53 . V_54 = V_40 -> V_45 ;
V_32 -> V_40 . V_53 . V_55 = V_40 -> V_56 . V_57 ;
V_32 -> V_40 . V_53 . V_58 = V_40 -> V_56 . V_59 ;
V_32 -> V_40 . V_60 = sizeof( struct V_5 ) ;
V_32 -> V_40 . V_61 = F_26 ;
V_32 -> V_40 . V_62 = F_31 ;
V_32 -> V_40 . V_53 . V_63 = F_1 ;
V_32 -> V_40 . V_53 . V_64 = F_21 ;
V_32 -> V_40 . V_53 . V_65 = F_21 ;
V_32 -> V_40 . V_53 . V_66 = L_2 ;
V_47:
F_39 ( V_40 ) ;
return V_32 ;
V_46:
V_32 = F_35 ( V_9 ) ;
goto V_47;
}
static void F_40 ( struct V_31 * V_32 )
{
F_41 ( F_27 ( V_32 ) ) ;
F_42 ( V_32 ) ;
}
static int F_43 ( struct V_67 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
struct V_68 * V_6 = F_44 ( V_2 ) ;
struct V_67 * V_8 = V_6 -> V_8 ;
int V_9 ;
if ( V_4 < V_69 )
return - V_44 ;
memcpy ( V_6 -> V_70 , V_3 + ( V_4 - V_69 ) ,
V_69 ) ;
V_4 -= V_69 ;
F_45 ( V_8 , V_10 ) ;
F_46 ( V_8 , F_47 ( V_2 ) &
V_10 ) ;
V_9 = F_48 ( V_8 , V_3 , V_4 ) ;
F_46 ( V_2 , F_47 ( V_8 ) &
V_11 ) ;
return V_9 ;
}
static int F_49 ( struct V_71 * V_72 )
{
struct V_67 * V_14 = F_50 ( V_72 ) ;
struct V_68 * V_6 = F_44 ( V_14 ) ;
struct V_67 * V_8 = V_6 -> V_8 ;
unsigned long V_73 = F_51 ( V_14 ) ;
struct V_74 * V_75 =
( void * ) F_12 ( ( T_1 * ) F_52 ( V_72 ) , V_73 + 1 ) ;
struct V_71 * V_76 = & V_75 -> V_76 ;
T_1 * V_18 = V_75 -> V_18 ;
memcpy ( V_18 , V_6 -> V_70 , V_69 ) ;
memcpy ( V_18 + V_69 , V_72 -> V_18 , V_77 ) ;
* ( V_78 * ) ( V_18 + V_69 + V_77 ) =
F_53 ( 1 ) ;
F_54 ( V_76 , V_8 ) ;
F_55 ( V_76 , V_72 -> V_79 . V_80 ,
V_72 -> V_79 . V_81 , V_72 -> V_79 . V_82 ) ;
F_56 ( V_76 , V_72 -> V_21 , V_72 -> V_24 ,
V_72 -> V_83 , V_18 ) ;
return F_57 ( V_76 ) ;
}
static int F_58 ( struct V_67 * V_14 )
{
struct V_84 * V_32 = F_59 ( V_14 ) ;
struct V_85 * V_35 = F_60 ( V_32 ) ;
struct V_68 * V_6 = F_44 ( V_14 ) ;
struct V_67 * V_36 ;
unsigned long V_73 ;
unsigned int V_86 ;
V_36 = F_61 ( V_35 ) ;
if ( F_29 ( V_36 ) )
return F_30 ( V_36 ) ;
V_6 -> V_8 = V_36 ;
V_73 = F_51 ( V_14 ) ;
V_73 &= ~ ( F_62 () - 1 ) ;
V_86 = V_73 + sizeof( struct V_74 ) +
F_63 ( V_36 ) ;
F_64 ( V_14 , V_86 ) ;
return 0 ;
}
static void F_65 ( struct V_67 * V_14 )
{
struct V_68 * V_6 = F_44 ( V_14 ) ;
F_66 ( V_6 -> V_8 ) ;
}
static void F_67 ( struct V_84 * V_32 )
{
struct V_85 * V_35 = F_60 ( V_32 ) ;
F_68 ( V_35 ) ;
F_42 ( V_32 ) ;
}
static int F_69 ( struct V_87 * V_88 ,
struct V_37 * * V_38 )
{
struct V_89 * V_90 ;
struct V_84 * V_32 ;
struct V_91 * V_40 ;
struct V_85 * V_35 ;
const char * V_92 ;
int V_9 ;
V_90 = F_70 ( V_38 ) ;
if ( F_29 ( V_90 ) )
return F_30 ( V_90 ) ;
if ( ( V_90 -> type ^ V_93 ) & V_90 -> V_94 )
return - V_44 ;
V_92 = F_71 ( V_38 [ 1 ] ) ;
if ( F_29 ( V_92 ) )
return F_30 ( V_92 ) ;
V_32 = F_72 ( sizeof( * V_32 ) + sizeof( * V_35 ) , V_95 ) ;
if ( ! V_32 )
return - V_96 ;
V_35 = F_60 ( V_32 ) ;
F_73 ( V_35 , F_74 ( V_32 ) ) ;
V_9 = F_75 ( V_35 , V_92 , 0 ,
F_76 ( V_90 -> type ,
V_90 -> V_94 ) ) ;
if ( V_9 )
goto V_97;
V_40 = F_77 ( V_35 ) ;
V_9 = - V_44 ;
if ( F_78 ( V_40 ) != V_98 )
goto V_99;
if ( V_40 -> V_79 . V_45 != 1 )
goto V_99;
V_9 = - V_100 ;
if ( snprintf ( V_32 -> V_40 . V_79 . V_101 , V_102 ,
L_3 , V_40 -> V_79 . V_101 ) >= V_102 )
goto V_99;
if ( snprintf ( V_32 -> V_40 . V_79 . V_103 , V_102 ,
L_3 , V_40 -> V_79 . V_103 ) >=
V_102 )
goto V_99;
V_32 -> V_40 . V_79 . V_49 = V_40 -> V_79 . V_49 ;
V_32 -> V_40 . V_79 . V_45 = 1 ;
V_32 -> V_40 . V_79 . V_50 = V_40 -> V_79 . V_50 ;
V_32 -> V_40 . V_79 . V_48 = V_40 -> V_79 . V_48 & V_104 ;
V_32 -> V_40 . V_54 = V_77 ;
V_32 -> V_40 . V_105 = F_79 ( V_40 ) ;
V_32 -> V_40 . V_55 = F_80 ( V_40 ) +
V_69 ;
V_32 -> V_40 . V_58 = F_81 ( V_40 ) +
V_69 ;
V_32 -> V_40 . V_63 = F_43 ;
V_32 -> V_40 . V_64 = F_49 ;
V_32 -> V_40 . V_65 = F_49 ;
V_32 -> V_40 . V_79 . V_60 = sizeof( struct V_68 ) ;
V_32 -> V_40 . V_106 = F_58 ;
V_32 -> V_40 . exit = F_65 ;
V_32 -> free = F_67 ;
V_9 = F_82 ( V_88 , V_32 ) ;
if ( V_9 )
goto V_99;
V_47:
return V_9 ;
V_99:
F_68 ( V_35 ) ;
V_97:
F_42 ( V_32 ) ;
goto V_47;
}
static int T_2 F_83 ( void )
{
int V_9 ;
V_9 = F_84 ( & V_107 ) ;
if ( V_9 )
goto V_47;
V_9 = F_84 ( & V_108 ) ;
if ( V_9 )
goto V_109;
V_47:
return V_9 ;
V_109:
F_85 ( & V_107 ) ;
goto V_47;
}
static void T_3 F_86 ( void )
{
F_85 ( & V_108 ) ;
F_85 ( & V_107 ) ;
}
