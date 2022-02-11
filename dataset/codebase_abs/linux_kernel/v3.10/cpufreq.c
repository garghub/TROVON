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
unsigned int V_16 ;
if ( V_40 == V_57 )
return 0 ;
V_57 = V_40 ;
F_9 ( L_10 ,
V_49 , V_39 , V_40 , V_56 ) ;
if ( V_58 ) {
if ( F_25 ( V_39 , V_58 ,
V_40 , V_56 ,
& V_16 ) ) {
F_9 ( L_11 , V_49 ) ;
return - V_55 ;
}
F_9 ( L_12 , V_49 ,
V_40 , V_16 , V_58 [ V_16 ] . V_18 ) ;
V_40 = V_58 [ V_16 ] . V_18 ;
}
V_40 *= 1000 ;
if ( ! V_59 || V_2 . V_60 ) {
V_15 = NULL ;
} else {
struct V_38 V_61 ;
int V_62 ;
V_61 . V_63 = V_39 -> V_63 * 1000 ;
V_61 . V_64 = V_39 -> V_64 * 1000 ;
V_61 . V_65 = V_39 -> V_65 ;
V_62 = F_25 ( & V_61 , V_59 ,
V_40 , V_56 ,
& V_16 ) ;
if ( V_62 < 0 ) {
F_20 ( V_47 L_13 , V_49 ) ;
goto V_48;
}
V_15 = V_59 + V_16 ;
F_9 ( L_14 ,
V_49 , V_40 , V_15 -> V_18 ) ;
V_40 = V_15 -> V_18 ;
}
return F_19 ( V_39 , V_40 , V_15 ) ;
V_48:
F_20 ( V_47 L_9 , V_40 ) ;
return - V_55 ;
}
static unsigned int F_26 ( unsigned int V_65 )
{
return F_4 ( V_14 ) / 1000 ;
}
struct V_37 * F_27 ( struct V_66 * V_67 , const char * V_68 )
{
struct V_37 * V_37 ;
V_37 = F_28 ( V_67 , V_68 ) ;
if ( F_29 ( V_37 ) )
F_20 ( V_47 L_15 , V_68 ) ;
return V_37 ;
}
static int F_30 ( struct V_38 * V_39 )
{
F_20 ( V_69 L_16 , V_49 , V_39 ) ;
if ( V_39 -> V_65 != 0 )
return - V_55 ;
V_39 -> V_70 = F_26 ( 0 ) ;
V_39 -> V_63 = V_39 -> V_71 . V_72 = 0 ;
V_39 -> V_64 = V_39 -> V_71 . V_73 = V_2 . V_29 -> V_64 . V_6 / 1000 ;
V_39 -> V_74 = V_75 ;
V_39 -> V_71 . V_76 = V_2 . V_29 -> V_77 ;
if ( V_58 )
F_31 ( V_39 , V_58 ) ;
return 0 ;
}
static T_1 int F_32 ( void )
{
V_52 = F_27 ( NULL , L_17 ) ;
V_78 = F_27 ( NULL , L_18 ) ;
V_11 = F_27 ( NULL , L_19 ) ;
V_12 = F_27 ( NULL , L_20 ) ;
V_13 = F_27 ( NULL , L_21 ) ;
V_14 = F_27 ( NULL , L_22 ) ;
if ( F_29 ( V_11 ) || F_29 ( V_12 ) || F_29 ( V_13 ) ||
F_29 ( V_52 ) || F_29 ( V_14 ) || F_29 ( V_78 ) ) {
F_20 ( V_47 L_23 , V_49 ) ;
return - V_79 ;
}
F_20 ( V_69 L_24 , V_49 ,
F_4 ( V_11 ) / 1000 ,
F_4 ( V_12 ) / 1000 ,
F_4 ( V_13 ) / 1000 ,
F_4 ( V_14 ) / 1000 ) ;
return 0 ;
}
static int F_33 ( struct V_38 * V_39 )
{
if ( V_39 -> V_65 != 0 )
return - V_55 ;
return 0 ;
}
static int F_34 ( struct V_38 * V_39 )
{
V_80 . V_18 = F_4 ( V_52 ) ;
V_80 . V_16 = F_5 ( V_17 ) ;
V_81 = F_26 ( 0 ) * 1000 ;
return 0 ;
}
static int F_35 ( struct V_38 * V_39 )
{
int V_62 ;
F_9 ( L_25 , V_49 , V_39 ) ;
V_57 = ~ 0 ;
F_16 () ;
V_62 = F_19 ( NULL , V_81 , & V_80 ) ;
if ( V_62 ) {
F_20 ( V_47 L_26 , V_49 ) ;
return V_62 ;
}
return 0 ;
}
int T_1 F_36 ( struct V_82 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_68 ) {
F_20 ( V_47 L_27 ,
V_49 ) ;
return - V_55 ;
}
F_20 ( V_69 L_28 ,
V_29 -> V_68 ) ;
F_37 ( V_29 -> V_32 == NULL ) ;
F_37 ( V_29 -> V_33 == NULL ) ;
F_37 ( V_29 -> V_34 == NULL ) ;
V_2 . V_29 = V_29 ;
return 0 ;
}
int T_1 F_38 ( struct V_83 * V_84 )
{
struct V_83 * V_85 ;
if ( ! V_84 ) {
F_20 ( V_69 L_29 , V_49 ) ;
return - V_55 ;
}
V_85 = F_39 ( sizeof( struct V_83 ) , V_86 ) ;
if ( V_85 == NULL ) {
F_20 ( V_47 L_30 , V_49 ) ;
return - V_87 ;
}
* V_85 = * V_84 ;
V_2 . V_84 = V_85 ;
return 0 ;
}
int T_1 F_40 ( void )
{
int V_62 ;
if ( ! V_2 . V_29 -> V_88 ) {
F_20 ( V_47 L_31 , V_49 ) ;
return - V_79 ;
}
F_20 ( V_69 L_32 , V_49 ) ;
V_62 = ( V_2 . V_29 -> V_88 ) ( & V_2 , & V_4 ) ;
if ( V_62 )
F_20 ( V_47 L_33 , V_49 ) ;
return V_62 ;
}
static void F_41 ( struct V_89 * V_90 ,
struct V_89 * V_91 , struct V_89 * V_92 )
{
V_90 -> V_6 = F_42 ( V_91 -> V_6 , V_92 -> V_6 ) ;
V_90 -> V_8 = F_42 ( V_91 -> V_8 , V_92 -> V_8 ) ;
V_90 -> V_7 = F_42 ( V_91 -> V_7 , V_92 -> V_7 ) ;
V_90 -> V_9 = F_42 ( V_91 -> V_9 , V_92 -> V_9 ) ;
}
static inline T_2 F_43 ( T_2 V_10 , T_2 V_93 )
{
T_2 V_94 ;
V_94 = V_10 * V_93 ;
V_94 = F_44 ( V_94 , 1000 * 1000 ) ;
return V_94 ;
}
static void F_45 ( void )
{
unsigned int V_95 = V_2 . V_29 -> V_96 ;
T_2 V_97 = ( T_2 ) F_4 ( V_78 ) ;
T_2 V_98 ;
if ( V_95 == 0 ) {
F_46 ( 1 ) ;
return;
}
V_98 = F_43 ( V_97 , V_2 . V_29 -> V_99 ) << V_95 ;
V_98 |= F_43 ( V_97 , V_2 . V_29 -> V_100 ) ;
F_20 ( V_69 L_34 , V_49 , V_98 ) ;
F_47 ( V_98 , V_101 ) ;
}
static int F_48 ( void )
{
int V_102 , V_62 ;
if ( ! V_2 . V_29 -> V_103 )
return - V_55 ;
F_49 ( V_58 ) ;
V_58 = NULL ;
V_102 = V_2 . V_29 -> V_103 ( & V_2 , NULL , 0 ) ;
V_102 ++ ;
V_58 = F_50 ( sizeof( struct V_41 ) * V_102 , V_86 ) ;
if ( ! V_58 ) {
F_20 ( V_47 L_35 , V_49 ) ;
return - V_87 ;
}
V_104 = V_102 ;
V_62 = V_2 . V_29 -> V_103 ( & V_2 , V_58 , V_102 ) ;
F_51 ( V_58 , V_62 , V_102 , V_105 ) ;
return 0 ;
}
static int T_1 F_52 ( void )
{
int V_62 = 0 ;
if ( V_2 . V_29 && V_2 . V_84 ) {
V_62 = F_32 () ;
if ( V_62 )
goto V_106;
F_3 ( & V_2 ) ;
F_8 ( L_2 , & V_2 ) ;
if ( V_2 . V_84 -> V_107 ) {
V_62 = F_40 () ;
if ( V_62 ) {
F_20 ( V_47 L_36 ,
V_49 ) ;
goto V_106;
}
}
if ( V_2 . V_84 -> V_108 && ! V_2 . V_29 -> V_30 ) {
F_20 ( V_47 L_37 ,
V_49 ) ;
V_62 = - V_55 ;
goto V_106;
}
if ( ! V_2 . V_29 -> V_109 )
V_2 . V_60 = 1 ;
F_45 () ;
F_41 ( & V_2 . V_64 , & V_2 . V_84 -> V_64 ,
& V_2 . V_29 -> V_64 ) ;
if ( V_2 . V_29 -> V_103 )
F_48 () ;
V_62 = F_53 ( & V_110 ) ;
}
V_106:
return V_62 ;
}
int T_1 F_54 ( struct V_41 * V_111 ,
unsigned int V_112 )
{
struct V_41 * V_113 ;
unsigned int V_102 ;
V_102 = sizeof( struct V_41 ) * ( V_112 + 1 ) ;
V_113 = F_50 ( V_102 , V_86 ) ;
if ( V_113 ) {
memcpy ( V_113 , V_111 , V_102 ) ;
V_59 = V_113 ;
V_113 += V_112 ;
V_113 -> V_18 = V_105 ;
F_20 ( V_69 L_38 , V_112 ) ;
} else
F_20 ( V_47 L_39 ) ;
return V_113 ? 0 : - V_87 ;
}
