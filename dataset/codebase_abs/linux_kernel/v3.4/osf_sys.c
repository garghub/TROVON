static int
F_1 ( void * V_1 , const char * V_2 , int V_3 , T_1 V_4 ,
T_2 V_5 , unsigned int V_6 )
{
struct V_7 T_3 * V_8 ;
struct V_9 * V_10 = (struct V_9 * ) V_1 ;
unsigned int V_11 = F_2 ( V_12 + V_3 + 1 , sizeof( V_13 ) ) ;
unsigned int V_14 ;
V_10 -> error = - V_15 ;
if ( V_11 > V_10 -> V_16 )
return - V_15 ;
V_14 = V_5 ;
if ( sizeof( V_14 ) < sizeof( V_5 ) && V_14 != V_5 ) {
V_10 -> error = - V_17 ;
return - V_17 ;
}
if ( V_10 -> V_18 ) {
if ( F_3 ( V_4 , V_10 -> V_18 ) )
goto V_19;
V_10 -> V_18 = NULL ;
}
V_8 = V_10 -> V_8 ;
if ( F_3 ( V_14 , & V_8 -> V_14 ) ||
F_3 ( V_3 , & V_8 -> V_20 ) ||
F_3 ( V_11 , & V_8 -> V_21 ) ||
F_4 ( V_8 -> V_22 , V_2 , V_3 ) ||
F_3 ( 0 , V_8 -> V_22 + V_3 ) )
goto V_19;
V_8 = ( void T_3 * ) V_8 + V_11 ;
V_10 -> V_8 = V_8 ;
V_10 -> V_16 -= V_11 ;
return 0 ;
V_19:
V_10 -> error = - V_23 ;
return - V_23 ;
}
static int
F_5 ( struct V_24 * V_25 , struct V_26 T_3 * V_27 ,
unsigned long V_28 )
{
struct V_26 V_29 ;
V_29 . V_30 = V_25 -> V_30 ;
V_29 . V_31 = 0 ;
V_29 . V_32 = V_25 -> V_33 ;
V_29 . V_34 = V_25 -> V_34 ;
V_29 . V_35 = V_25 -> V_35 ;
V_29 . V_36 = V_25 -> V_36 ;
V_29 . V_37 = V_25 -> V_37 ;
V_29 . V_38 = V_25 -> V_38 ;
V_29 . V_39 = V_25 -> V_39 ;
V_29 . V_40 = V_25 -> V_40 ;
if ( V_28 > sizeof( V_29 ) )
V_28 = sizeof( V_29 ) ;
return F_4 ( V_27 , & V_29 , V_28 ) ? - V_23 : 0 ;
}
static int
F_6 ( char * V_41 , struct V_42 T_3 * args , int V_43 )
{
int V_44 ;
struct V_45 V_46 ;
char * V_47 ;
V_44 = - V_23 ;
if ( F_7 ( & V_46 , args , sizeof( V_46 ) ) )
goto V_48;
V_47 = F_8 ( V_46 . V_47 ) ;
V_44 = F_9 ( V_47 ) ;
if ( F_10 ( V_47 ) )
goto V_48;
V_44 = F_11 ( V_47 , V_41 , L_1 , V_43 , NULL ) ;
F_12 ( V_47 ) ;
V_48:
return V_44 ;
}
static int
F_13 ( char * V_41 , struct V_45 T_3 * args , int V_43 )
{
int V_44 ;
struct V_45 V_46 ;
char * V_47 ;
V_44 = - V_23 ;
if ( F_7 ( & V_46 , args , sizeof( V_46 ) ) )
goto V_48;
V_47 = F_8 ( V_46 . V_47 ) ;
V_44 = F_9 ( V_47 ) ;
if ( F_10 ( V_47 ) )
goto V_48;
V_44 = F_11 ( V_47 , V_41 , L_2 , V_43 , NULL ) ;
F_12 ( V_47 ) ;
V_48:
return V_44 ;
}
static int
F_14 ( char * V_41 , struct V_49 T_3 * args , int V_43 )
{
struct V_49 V_46 ;
if ( F_7 ( & V_46 , args , sizeof( V_46 ) ) )
return - V_23 ;
return F_11 ( L_3 , V_41 , L_4 , V_43 , NULL ) ;
}
static inline long
F_15 ( struct V_50 * V_51 , struct V_52 T_3 * V_53 )
{
return ( ! F_16 ( V_54 , V_53 , sizeof( * V_53 ) ) ||
( F_17 ( V_51 -> V_55 , & V_53 -> V_55 ) |
F_17 ( V_51 -> V_56 , & V_53 -> V_56 ) ) ) ;
}
static inline long
F_18 ( struct V_52 T_3 * V_51 , struct V_50 * V_53 )
{
return ( ! F_16 ( V_57 , V_51 , sizeof( * V_51 ) ) ||
( F_19 ( V_53 -> V_55 , & V_51 -> V_55 ) |
F_19 ( V_53 -> V_56 , & V_51 -> V_56 ) ) ) ;
}
static inline long
F_20 ( struct V_58 * V_51 , struct V_59 T_3 * V_53 )
{
return ( ! F_16 ( V_54 , V_53 , sizeof( * V_53 ) ) ||
( F_17 ( V_51 -> V_60 . V_55 , & V_53 -> V_60 . V_55 ) |
F_17 ( V_51 -> V_60 . V_56 , & V_53 -> V_60 . V_56 ) |
F_17 ( V_51 -> V_61 . V_55 , & V_53 -> V_61 . V_55 ) |
F_17 ( V_51 -> V_61 . V_56 , & V_53 -> V_61 . V_56 ) ) ) ;
}
static inline long
F_21 ( struct V_59 T_3 * V_51 , struct V_58 * V_53 )
{
return ( ! F_16 ( V_57 , V_51 , sizeof( * V_51 ) ) ||
( F_19 ( V_53 -> V_60 . V_55 , & V_51 -> V_60 . V_55 ) |
F_19 ( V_53 -> V_60 . V_56 , & V_51 -> V_60 . V_56 ) |
F_19 ( V_53 -> V_61 . V_55 , & V_51 -> V_61 . V_55 ) |
F_19 ( V_53 -> V_61 . V_56 , & V_51 -> V_61 . V_56 ) ) ) ;
}
static inline void
F_22 ( unsigned long V_62 , struct V_52 * V_63 )
{
V_63 -> V_56 = ( V_62 % V_64 ) * ( 1000000L / V_64 ) ;
V_63 -> V_55 = V_62 / V_64 ;
}
static unsigned long
F_23 ( unsigned long V_65 , unsigned long V_66 ,
unsigned long V_67 )
{
struct V_68 * V_69 = F_24 ( V_70 -> V_71 , V_65 ) ;
while ( 1 ) {
if ( V_67 - V_66 < V_65 )
return - V_72 ;
if ( ! V_69 || V_65 + V_66 <= V_69 -> V_73 )
return V_65 ;
V_65 = V_69 -> V_74 ;
V_69 = V_69 -> V_75 ;
}
}
unsigned long
F_25 ( struct V_76 * V_77 , unsigned long V_65 ,
unsigned long V_66 , unsigned long V_78 ,
unsigned long V_43 )
{
unsigned long V_67 ;
if ( V_70 -> V_79 & V_80 )
V_67 = 0x80000000 ;
else
V_67 = V_81 ;
if ( V_66 > V_67 )
return - V_72 ;
if ( V_43 & V_82 )
return V_65 ;
if ( V_65 ) {
V_65 = F_23 ( F_26 ( V_65 ) , V_66 , V_67 ) ;
if ( V_65 != ( unsigned long ) - V_72 )
return V_65 ;
}
V_65 = F_23 ( F_26 ( V_83 ) ,
V_66 , V_67 ) ;
if ( V_65 != ( unsigned long ) - V_72 )
return V_65 ;
V_65 = F_23 ( V_84 , V_66 , V_67 ) ;
return V_65 ;
}
static int
F_27 ( const struct V_85 T_3 * V_86 , unsigned long V_16 )
{
unsigned long V_53 ;
for ( V_53 = 0 ; V_53 < V_16 ; V_53 ++ ) {
int T_3 * V_87 = ( int T_3 * ) & V_86 [ V_53 ] . V_88 + 1 ;
if ( F_3 ( 0 , V_87 ) )
return - V_23 ;
}
return 0 ;
}
