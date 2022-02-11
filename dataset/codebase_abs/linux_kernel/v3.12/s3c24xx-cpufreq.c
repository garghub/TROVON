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
F_21 ( V_39 , & V_43 . V_43 , V_53 ) ;
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
F_21 ( V_39 , & V_43 . V_43 , V_54 ) ;
F_9 ( L_8 , V_49 ) ;
return 0 ;
V_48:
F_20 ( V_47 L_9 , V_40 ) ;
return - V_55 ;
}
static int F_24 ( struct V_38 * V_39 ,
unsigned int V_40 ,
unsigned int V_56 )
{
struct V_41 * V_15 ;
unsigned int V_57 ;
if ( V_40 == V_58 )
return 0 ;
V_58 = V_40 ;
F_9 ( L_10 ,
V_49 , V_39 , V_40 , V_56 ) ;
if ( V_59 ) {
if ( F_25 ( V_39 , V_59 ,
V_40 , V_56 ,
& V_57 ) ) {
F_9 ( L_11 , V_49 ) ;
return - V_55 ;
}
F_9 ( L_12 , V_49 ,
V_40 , V_57 , V_59 [ V_57 ] . V_18 ) ;
V_40 = V_59 [ V_57 ] . V_18 ;
}
V_40 *= 1000 ;
if ( ! V_60 || V_2 . V_61 ) {
V_15 = NULL ;
} else {
struct V_38 V_62 ;
int V_63 ;
V_62 . V_64 = V_39 -> V_64 * 1000 ;
V_62 . V_65 = V_39 -> V_65 * 1000 ;
V_62 . V_66 = V_39 -> V_66 ;
V_63 = F_25 ( & V_62 , V_60 ,
V_40 , V_56 ,
& V_57 ) ;
if ( V_63 < 0 ) {
F_20 ( V_47 L_13 , V_49 ) ;
goto V_48;
}
V_15 = V_60 + V_57 ;
F_9 ( L_14 ,
V_49 , V_40 , V_15 -> V_18 ) ;
V_40 = V_15 -> V_18 ;
}
return F_19 ( V_39 , V_40 , V_15 ) ;
V_48:
F_20 ( V_47 L_9 , V_40 ) ;
return - V_55 ;
}
static unsigned int F_26 ( unsigned int V_66 )
{
return F_4 ( V_14 ) / 1000 ;
}
struct V_37 * F_27 ( struct V_67 * V_68 , const char * V_69 )
{
struct V_37 * V_37 ;
V_37 = F_28 ( V_68 , V_69 ) ;
if ( F_29 ( V_37 ) )
F_20 ( V_47 L_15 , V_69 ) ;
return V_37 ;
}
static int F_30 ( struct V_38 * V_39 )
{
F_20 ( V_70 L_16 , V_49 , V_39 ) ;
if ( V_39 -> V_66 != 0 )
return - V_55 ;
V_39 -> V_71 = F_26 ( 0 ) ;
V_39 -> V_64 = V_39 -> V_72 . V_73 = 0 ;
V_39 -> V_65 = V_39 -> V_72 . V_74 = V_2 . V_29 -> V_65 . V_6 / 1000 ;
V_39 -> V_75 = V_76 ;
V_39 -> V_72 . V_77 = V_2 . V_29 -> V_78 ;
if ( V_59 )
F_31 ( V_39 , V_59 ) ;
return 0 ;
}
static int T_1 F_32 ( void )
{
V_52 = F_27 ( NULL , L_17 ) ;
V_79 = F_27 ( NULL , L_18 ) ;
V_11 = F_27 ( NULL , L_19 ) ;
V_12 = F_27 ( NULL , L_20 ) ;
V_13 = F_27 ( NULL , L_21 ) ;
V_14 = F_27 ( NULL , L_22 ) ;
if ( F_29 ( V_11 ) || F_29 ( V_12 ) || F_29 ( V_13 ) ||
F_29 ( V_52 ) || F_29 ( V_14 ) || F_29 ( V_79 ) ) {
F_20 ( V_47 L_23 , V_49 ) ;
return - V_80 ;
}
F_20 ( V_70 L_24 , V_49 ,
F_4 ( V_11 ) / 1000 ,
F_4 ( V_12 ) / 1000 ,
F_4 ( V_13 ) / 1000 ,
F_4 ( V_14 ) / 1000 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
if ( V_39 -> V_66 != 0 )
return - V_55 ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 )
{
V_81 . V_18 = F_4 ( V_52 ) ;
V_81 . V_16 = F_5 ( V_17 ) ;
V_82 = F_26 ( 0 ) * 1000 ;
return 0 ;
}
static int F_35 ( struct V_38 * V_39 )
{
int V_63 ;
F_9 ( L_25 , V_49 , V_39 ) ;
V_58 = ~ 0 ;
F_16 () ;
V_63 = F_19 ( NULL , V_82 , & V_81 ) ;
if ( V_63 ) {
F_20 ( V_47 L_26 , V_49 ) ;
return V_63 ;
}
return 0 ;
}
int T_1 F_36 ( struct V_83 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_69 ) {
F_20 ( V_47 L_27 ,
V_49 ) ;
return - V_55 ;
}
F_20 ( V_70 L_28 ,
V_29 -> V_69 ) ;
F_37 ( V_29 -> V_32 == NULL ) ;
F_37 ( V_29 -> V_33 == NULL ) ;
F_37 ( V_29 -> V_34 == NULL ) ;
V_2 . V_29 = V_29 ;
return 0 ;
}
int T_1 F_38 ( struct V_84 * V_85 )
{
struct V_84 * V_86 ;
if ( ! V_85 ) {
F_20 ( V_70 L_29 , V_49 ) ;
return - V_55 ;
}
V_86 = F_39 ( sizeof( * V_86 ) , V_87 ) ;
if ( V_86 == NULL ) {
F_20 ( V_47 L_30 , V_49 ) ;
return - V_88 ;
}
* V_86 = * V_85 ;
V_2 . V_85 = V_86 ;
return 0 ;
}
int T_1 F_40 ( void )
{
int V_63 ;
if ( ! V_2 . V_29 -> V_89 ) {
F_20 ( V_47 L_31 , V_49 ) ;
return - V_80 ;
}
F_20 ( V_70 L_32 , V_49 ) ;
V_63 = ( V_2 . V_29 -> V_89 ) ( & V_2 , & V_4 ) ;
if ( V_63 )
F_20 ( V_47 L_33 , V_49 ) ;
return V_63 ;
}
static void F_41 ( struct V_90 * V_91 ,
struct V_90 * V_92 , struct V_90 * V_93 )
{
V_91 -> V_6 = F_42 ( V_92 -> V_6 , V_93 -> V_6 ) ;
V_91 -> V_8 = F_42 ( V_92 -> V_8 , V_93 -> V_8 ) ;
V_91 -> V_7 = F_42 ( V_92 -> V_7 , V_93 -> V_7 ) ;
V_91 -> V_9 = F_42 ( V_92 -> V_9 , V_93 -> V_9 ) ;
}
static inline T_2 F_43 ( T_2 V_10 , T_2 V_94 )
{
T_2 V_95 ;
V_95 = V_10 * V_94 ;
V_95 = F_44 ( V_95 , 1000 * 1000 ) ;
return V_95 ;
}
static void F_45 ( void )
{
unsigned int V_96 = V_2 . V_29 -> V_97 ;
T_2 V_98 = ( T_2 ) F_4 ( V_79 ) ;
T_2 V_99 ;
if ( V_96 == 0 ) {
F_46 ( 1 ) ;
return;
}
V_99 = F_43 ( V_98 , V_2 . V_29 -> V_100 ) << V_96 ;
V_99 |= F_43 ( V_98 , V_2 . V_29 -> V_101 ) ;
F_20 ( V_70 L_34 , V_49 , V_99 ) ;
F_47 ( V_99 , V_102 ) ;
}
static int F_48 ( void )
{
int V_103 , V_63 ;
if ( ! V_2 . V_29 -> V_104 )
return - V_55 ;
F_49 ( V_59 ) ;
V_59 = NULL ;
V_103 = V_2 . V_29 -> V_104 ( & V_2 , NULL , 0 ) ;
V_103 ++ ;
V_59 = F_50 ( sizeof( * V_59 ) * V_103 , V_87 ) ;
if ( ! V_59 ) {
F_20 ( V_47 L_35 , V_49 ) ;
return - V_88 ;
}
V_105 = V_103 ;
V_63 = V_2 . V_29 -> V_104 ( & V_2 , V_59 , V_103 ) ;
F_51 ( V_59 , V_63 , V_103 , V_106 ) ;
return 0 ;
}
static int T_1 F_52 ( void )
{
int V_63 = 0 ;
if ( V_2 . V_29 && V_2 . V_85 ) {
V_63 = F_32 () ;
if ( V_63 )
goto V_107;
F_3 ( & V_2 ) ;
F_8 ( L_2 , & V_2 ) ;
if ( V_2 . V_85 -> V_108 ) {
V_63 = F_40 () ;
if ( V_63 ) {
F_20 ( V_47 L_36 ,
V_49 ) ;
goto V_107;
}
}
if ( V_2 . V_85 -> V_109 && ! V_2 . V_29 -> V_30 ) {
F_20 ( V_47 L_37 ,
V_49 ) ;
V_63 = - V_55 ;
goto V_107;
}
if ( ! V_2 . V_29 -> V_110 )
V_2 . V_61 = 1 ;
F_45 () ;
F_41 ( & V_2 . V_65 , & V_2 . V_85 -> V_65 ,
& V_2 . V_29 -> V_65 ) ;
if ( V_2 . V_29 -> V_104 )
F_48 () ;
V_63 = F_53 ( & V_111 ) ;
}
V_107:
return V_63 ;
}
int T_1 F_54 ( struct V_41 * V_112 ,
unsigned int V_113 )
{
struct V_41 * V_114 ;
unsigned int V_103 ;
V_103 = sizeof( * V_114 ) * ( V_113 + 1 ) ;
V_114 = F_50 ( V_103 , V_87 ) ;
if ( V_114 ) {
memcpy ( V_114 , V_112 , V_103 ) ;
V_60 = V_114 ;
V_114 += V_113 ;
V_114 -> V_18 = V_106 ;
F_20 ( V_70 L_38 , V_113 ) ;
} else
F_20 ( V_47 L_39 ) ;
return V_114 ? 0 : - V_88 ;
}
