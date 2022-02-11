struct V_1 * F_1 ( void )
{
return & V_2 ;
}
struct V_3 * F_2 ( void )
{
return & V_4 ;
}
static void F_3 ( struct V_1 * V_5 )
{
unsigned long V_6 , V_7 , V_8 , V_9 ;
V_5 -> V_10 . V_6 = V_6 = F_4 ( V_11 ) ;
V_5 -> V_10 . V_8 = V_8 = F_4 ( V_12 ) ;
V_5 -> V_10 . V_7 = V_7 = F_4 ( V_13 ) ;
V_5 -> V_10 . V_9 = V_9 = F_4 ( V_14 ) ;
V_5 -> V_15 . V_16 = F_5 ( V_17 ) ;
V_5 -> V_15 . V_18 = V_6 ;
V_5 -> V_10 . V_19 = 1000000000 / ( V_5 -> V_10 . V_8 / 10 ) ;
V_5 -> V_20 . V_21 = V_6 / V_8 ;
V_5 -> V_20 . V_22 = V_6 / V_7 ;
}
static inline void F_6 ( struct V_1 * V_5 )
{
unsigned long V_15 = V_5 -> V_15 . V_18 ;
V_5 -> V_10 . V_6 = V_15 ;
V_5 -> V_10 . V_8 = V_15 / V_5 -> V_20 . V_21 ;
V_5 -> V_10 . V_7 = V_15 / V_5 -> V_20 . V_22 ;
V_5 -> V_10 . V_19 = 1000000000 / ( V_5 -> V_10 . V_8 / 10 ) ;
}
static inline int F_7 ( unsigned int V_23 , unsigned int V_24 , unsigned int V_25 )
{
int V_26 = abs ( V_23 - V_25 ) ;
int V_27 = abs ( V_23 - V_24 ) ;
return ( V_27 < V_26 ) ;
}
static void F_8 ( const char * V_28 ,
struct V_1 * V_5 )
{
F_9 ( L_1 ,
V_28 , V_5 -> V_15 . V_18 , V_5 -> V_10 . V_6 , V_5 -> V_10 . V_9 ,
V_5 -> V_10 . V_8 , V_5 -> V_20 . V_21 ,
V_5 -> V_10 . V_7 , V_5 -> V_20 . V_22 ) ;
}
static void F_10 ( struct V_1 * V_5 )
{
if ( V_5 -> V_29 -> V_30 )
( V_5 -> V_29 -> V_30 ) ( V_5 , & V_4 ) ;
}
static int F_11 ( struct V_1 * V_5 )
{
if ( V_5 -> V_29 -> V_31 )
return ( V_5 -> V_29 -> V_31 ) ( V_5 , & V_4 ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_5 )
{
( V_5 -> V_29 -> V_32 ) ( V_5 ) ;
}
static void F_13 ( struct V_1 * V_5 )
{
( V_5 -> V_29 -> V_33 ) ( V_5 ) ;
}
static int F_14 ( struct V_1 * V_5 )
{
return ( V_5 -> V_29 -> V_34 ) ( V_5 ) ;
}
static void F_15 ( struct V_1 * V_5 )
{
( V_5 -> V_29 -> V_35 ) ( V_5 ) ;
}
static inline void F_16 ( void )
{
V_2 . V_29 -> V_36 () ;
}
static inline void F_17 ( struct V_37 * V_37 ,
unsigned int V_10 )
{
F_18 ( V_37 , V_10 ) ;
}
static int F_19 ( struct V_38 * V_39 ,
unsigned int V_40 ,
struct V_41 * V_15 )
{
struct V_42 V_43 ;
struct V_1 V_44 ;
unsigned long V_45 ;
V_44 = V_2 ;
F_8 ( L_2 , & V_2 ) ;
V_44 . V_15 = V_15 ? * V_15 : V_2 . V_15 ;
if ( V_15 )
V_43 . V_46 = 1 ;
V_44 . V_10 . V_9 = V_40 ;
V_44 . V_10 . V_6 = V_44 . V_15 . V_18 ;
if ( F_14 ( & V_44 ) < 0 ) {
F_20 ( V_47 L_3 , V_40 ) ;
goto V_48;
}
F_9 ( L_4 , V_49 ) ;
F_6 ( & V_44 ) ;
F_9 ( L_5 , V_49 ) ;
if ( V_44 . V_10 . V_8 != V_2 . V_10 . V_8 ) {
if ( F_11 ( & V_44 ) < 0 ) {
F_20 ( V_47 L_6 , V_49 ) ;
goto V_48;
}
}
F_8 ( L_7 , & V_44 ) ;
V_43 . V_50 = V_2 . V_10 ;
V_43 . V_51 = V_44 . V_10 ;
V_43 . V_43 . V_50 = V_2 . V_10 . V_9 / 1000 ;
V_43 . V_43 . V_51 = V_44 . V_10 . V_9 / 1000 ;
F_17 ( V_52 , V_44 . V_15 . V_18 ) ;
F_17 ( V_11 , V_44 . V_10 . V_6 ) ;
F_17 ( V_12 , V_44 . V_10 . V_8 ) ;
F_17 ( V_13 , V_44 . V_10 . V_7 ) ;
F_21 ( V_39 , & V_43 . V_43 ) ;
F_22 ( V_45 ) ;
if ( V_44 . V_10 . V_8 < V_2 . V_10 . V_8 ) {
F_12 ( & V_44 ) ;
F_10 ( & V_44 ) ;
}
if ( V_44 . V_10 . V_6 == V_2 . V_10 . V_6 ) {
F_13 ( & V_44 ) ;
} else {
if ( V_44 . V_10 . V_6 < V_2 . V_10 . V_6 ) {
F_15 ( & V_44 ) ;
F_13 ( & V_44 ) ;
} else {
F_13 ( & V_44 ) ;
F_15 ( & V_44 ) ;
}
}
if ( V_44 . V_10 . V_8 > V_2 . V_10 . V_8 ) {
F_12 ( & V_44 ) ;
F_10 ( & V_44 ) ;
}
V_2 = V_44 ;
F_23 ( V_45 ) ;
F_24 ( V_39 , & V_43 . V_43 , 0 ) ;
F_9 ( L_8 , V_49 ) ;
return 0 ;
V_48:
F_20 ( V_47 L_9 , V_40 ) ;
return - V_53 ;
}
static int F_25 ( struct V_38 * V_39 ,
unsigned int V_40 ,
unsigned int V_54 )
{
struct V_41 * V_15 ;
unsigned int V_55 ;
if ( V_40 == V_56 )
return 0 ;
V_56 = V_40 ;
F_9 ( L_10 ,
V_49 , V_39 , V_40 , V_54 ) ;
if ( V_57 ) {
if ( F_26 ( V_39 , V_57 ,
V_40 , V_54 ,
& V_55 ) ) {
F_9 ( L_11 , V_49 ) ;
return - V_53 ;
}
F_9 ( L_12 , V_49 ,
V_40 , V_55 , V_57 [ V_55 ] . V_18 ) ;
V_40 = V_57 [ V_55 ] . V_18 ;
}
V_40 *= 1000 ;
if ( ! V_58 || V_2 . V_59 ) {
V_15 = NULL ;
} else {
struct V_38 V_60 ;
int V_61 ;
V_60 . V_62 = V_39 -> V_62 * 1000 ;
V_60 . V_63 = V_39 -> V_63 * 1000 ;
V_60 . V_64 = V_39 -> V_64 ;
V_61 = F_26 ( & V_60 , V_58 ,
V_40 , V_54 ,
& V_55 ) ;
if ( V_61 < 0 ) {
F_20 ( V_47 L_13 , V_49 ) ;
goto V_48;
}
V_15 = V_58 + V_55 ;
F_9 ( L_14 ,
V_49 , V_40 , V_15 -> V_18 ) ;
V_40 = V_15 -> V_18 ;
}
return F_19 ( V_39 , V_40 , V_15 ) ;
V_48:
F_20 ( V_47 L_9 , V_40 ) ;
return - V_53 ;
}
struct V_37 * F_27 ( struct V_65 * V_66 , const char * V_67 )
{
struct V_37 * V_37 ;
V_37 = F_28 ( V_66 , V_67 ) ;
if ( F_29 ( V_37 ) )
F_20 ( V_47 L_15 , V_67 ) ;
return V_37 ;
}
static int F_30 ( struct V_38 * V_39 )
{
V_39 -> V_37 = V_14 ;
return F_31 ( V_39 , V_57 , V_2 . V_29 -> V_68 ) ;
}
static int T_1 F_32 ( void )
{
V_52 = F_27 ( NULL , L_16 ) ;
V_69 = F_27 ( NULL , L_17 ) ;
V_11 = F_27 ( NULL , L_18 ) ;
V_12 = F_27 ( NULL , L_19 ) ;
V_13 = F_27 ( NULL , L_20 ) ;
V_14 = F_27 ( NULL , L_21 ) ;
if ( F_29 ( V_11 ) || F_29 ( V_12 ) || F_29 ( V_13 ) ||
F_29 ( V_52 ) || F_29 ( V_14 ) || F_29 ( V_69 ) ) {
F_20 ( V_47 L_22 , V_49 ) ;
return - V_70 ;
}
F_20 ( V_71 L_23 , V_49 ,
F_4 ( V_11 ) / 1000 ,
F_4 ( V_12 ) / 1000 ,
F_4 ( V_13 ) / 1000 ,
F_4 ( V_14 ) / 1000 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
V_72 . V_18 = F_4 ( V_52 ) ;
V_72 . V_16 = F_5 ( V_17 ) ;
V_73 = F_4 ( V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 )
{
int V_61 ;
F_9 ( L_24 , V_49 , V_39 ) ;
V_56 = ~ 0 ;
F_16 () ;
V_61 = F_19 ( NULL , V_73 , & V_72 ) ;
if ( V_61 ) {
F_20 ( V_47 L_25 , V_49 ) ;
return V_61 ;
}
return 0 ;
}
int T_1 F_35 ( struct V_74 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_67 ) {
F_20 ( V_47 L_26 ,
V_49 ) ;
return - V_53 ;
}
F_20 ( V_71 L_27 ,
V_29 -> V_67 ) ;
F_36 ( V_29 -> V_32 == NULL ) ;
F_36 ( V_29 -> V_33 == NULL ) ;
F_36 ( V_29 -> V_34 == NULL ) ;
V_2 . V_29 = V_29 ;
return 0 ;
}
int T_1 F_37 ( struct V_75 * V_76 )
{
struct V_75 * V_77 ;
if ( ! V_76 ) {
F_20 ( V_71 L_28 , V_49 ) ;
return - V_53 ;
}
V_77 = F_38 ( sizeof( * V_77 ) , V_78 ) ;
if ( V_77 == NULL ) {
F_20 ( V_47 L_29 , V_49 ) ;
return - V_79 ;
}
* V_77 = * V_76 ;
V_2 . V_76 = V_77 ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_61 ;
if ( ! V_2 . V_29 -> V_80 ) {
F_20 ( V_47 L_30 , V_49 ) ;
return - V_70 ;
}
F_20 ( V_71 L_31 , V_49 ) ;
V_61 = ( V_2 . V_29 -> V_80 ) ( & V_2 , & V_4 ) ;
if ( V_61 )
F_20 ( V_47 L_32 , V_49 ) ;
return V_61 ;
}
static void F_40 ( struct V_81 * V_82 ,
struct V_81 * V_83 , struct V_81 * V_84 )
{
V_82 -> V_6 = F_41 ( V_83 -> V_6 , V_84 -> V_6 ) ;
V_82 -> V_8 = F_41 ( V_83 -> V_8 , V_84 -> V_8 ) ;
V_82 -> V_7 = F_41 ( V_83 -> V_7 , V_84 -> V_7 ) ;
V_82 -> V_9 = F_41 ( V_83 -> V_9 , V_84 -> V_9 ) ;
}
static inline T_2 F_42 ( T_2 V_10 , T_2 V_85 )
{
T_2 V_86 ;
V_86 = V_10 * V_85 ;
V_86 = F_43 ( V_86 , 1000 * 1000 ) ;
return V_86 ;
}
static void F_44 ( void )
{
unsigned int V_87 = V_2 . V_29 -> V_88 ;
T_2 V_89 = ( T_2 ) F_4 ( V_69 ) ;
T_2 V_90 ;
if ( V_87 == 0 ) {
F_45 ( 1 ) ;
return;
}
V_90 = F_42 ( V_89 , V_2 . V_29 -> V_91 ) << V_87 ;
V_90 |= F_42 ( V_89 , V_2 . V_29 -> V_92 ) ;
F_20 ( V_71 L_33 , V_49 , V_90 ) ;
F_46 ( V_90 , V_93 ) ;
}
static int F_47 ( void )
{
int V_94 , V_61 ;
if ( ! V_2 . V_29 -> V_95 )
return - V_53 ;
F_48 ( V_57 ) ;
V_57 = NULL ;
V_94 = V_2 . V_29 -> V_95 ( & V_2 , NULL , 0 ) ;
V_94 ++ ;
V_57 = F_38 ( sizeof( * V_57 ) * V_94 , V_78 ) ;
if ( ! V_57 ) {
F_20 ( V_47 L_34 , V_49 ) ;
return - V_79 ;
}
V_96 = V_94 ;
V_61 = V_2 . V_29 -> V_95 ( & V_2 , V_57 , V_94 ) ;
F_49 ( V_57 , V_61 , V_94 , V_97 ) ;
return 0 ;
}
static int T_1 F_50 ( void )
{
int V_61 = 0 ;
if ( V_2 . V_29 && V_2 . V_76 ) {
V_61 = F_32 () ;
if ( V_61 )
goto V_98;
F_3 ( & V_2 ) ;
F_8 ( L_2 , & V_2 ) ;
if ( V_2 . V_76 -> V_99 ) {
V_61 = F_39 () ;
if ( V_61 ) {
F_20 ( V_47 L_35 ,
V_49 ) ;
goto V_98;
}
}
if ( V_2 . V_76 -> V_100 && ! V_2 . V_29 -> V_30 ) {
F_20 ( V_47 L_36 ,
V_49 ) ;
V_61 = - V_53 ;
goto V_98;
}
if ( ! V_2 . V_29 -> V_101 )
V_2 . V_59 = 1 ;
F_44 () ;
F_40 ( & V_2 . V_63 , & V_2 . V_76 -> V_63 ,
& V_2 . V_29 -> V_63 ) ;
if ( V_2 . V_29 -> V_95 )
F_47 () ;
V_61 = F_51 ( & V_102 ) ;
}
V_98:
return V_61 ;
}
int T_1 F_52 ( struct V_41 * V_103 ,
unsigned int V_104 )
{
struct V_41 * V_105 ;
unsigned int V_94 ;
V_94 = sizeof( * V_105 ) * ( V_104 + 1 ) ;
V_105 = F_38 ( V_94 , V_78 ) ;
if ( V_105 ) {
memcpy ( V_105 , V_103 , V_94 ) ;
V_58 = V_105 ;
V_105 += V_104 ;
V_105 -> V_18 = V_97 ;
F_20 ( V_71 L_37 , V_104 ) ;
} else
F_20 ( V_47 L_38 ) ;
return V_105 ? 0 : - V_79 ;
}
