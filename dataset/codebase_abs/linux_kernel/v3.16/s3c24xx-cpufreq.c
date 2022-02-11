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
V_5 -> V_35 = V_36 ;
( V_5 -> V_29 -> V_37 ) ( V_5 ) ;
}
static inline void F_16 ( void )
{
V_2 . V_29 -> V_38 () ;
}
static inline void F_17 ( struct V_39 * V_39 ,
unsigned int V_10 )
{
F_18 ( V_39 , V_10 ) ;
}
static int F_19 ( struct V_40 * V_41 ,
unsigned int V_42 ,
struct V_43 * V_15 )
{
struct V_44 V_45 ;
struct V_1 V_46 ;
unsigned long V_47 ;
V_46 = V_2 ;
F_8 ( L_2 , & V_2 ) ;
V_46 . V_15 = V_15 ? * V_15 : V_2 . V_15 ;
if ( V_15 )
V_45 . V_48 = 1 ;
V_46 . V_10 . V_9 = V_42 ;
V_46 . V_10 . V_6 = V_46 . V_15 . V_18 ;
if ( F_14 ( & V_46 ) < 0 ) {
F_20 ( V_49 L_3 , V_42 ) ;
goto V_50;
}
F_9 ( L_4 , V_51 ) ;
F_6 ( & V_46 ) ;
F_9 ( L_5 , V_51 ) ;
if ( V_46 . V_10 . V_8 != V_2 . V_10 . V_8 ) {
if ( F_11 ( & V_46 ) < 0 ) {
F_20 ( V_49 L_6 , V_51 ) ;
goto V_50;
}
}
F_8 ( L_7 , & V_46 ) ;
V_45 . V_52 = V_2 . V_10 ;
V_45 . V_53 = V_46 . V_10 ;
V_45 . V_45 . V_52 = V_2 . V_10 . V_9 / 1000 ;
V_45 . V_45 . V_53 = V_46 . V_10 . V_9 / 1000 ;
F_17 ( V_36 , V_46 . V_15 . V_18 ) ;
F_17 ( V_11 , V_46 . V_10 . V_6 ) ;
F_17 ( V_12 , V_46 . V_10 . V_8 ) ;
F_17 ( V_13 , V_46 . V_10 . V_7 ) ;
F_21 ( V_41 , & V_45 . V_45 ) ;
F_22 ( V_47 ) ;
if ( V_46 . V_10 . V_8 < V_2 . V_10 . V_8 ) {
F_12 ( & V_46 ) ;
F_10 ( & V_46 ) ;
}
if ( V_46 . V_10 . V_6 == V_2 . V_10 . V_6 ) {
F_13 ( & V_46 ) ;
} else {
if ( V_46 . V_10 . V_6 < V_2 . V_10 . V_6 ) {
F_15 ( & V_46 ) ;
F_13 ( & V_46 ) ;
} else {
F_13 ( & V_46 ) ;
F_15 ( & V_46 ) ;
}
}
if ( V_46 . V_10 . V_8 > V_2 . V_10 . V_8 ) {
F_12 ( & V_46 ) ;
F_10 ( & V_46 ) ;
}
V_2 = V_46 ;
F_23 ( V_47 ) ;
F_24 ( V_41 , & V_45 . V_45 , 0 ) ;
F_9 ( L_8 , V_51 ) ;
return 0 ;
V_50:
F_20 ( V_49 L_9 , V_42 ) ;
return - V_54 ;
}
static int F_25 ( struct V_40 * V_41 ,
unsigned int V_42 ,
unsigned int V_55 )
{
struct V_43 * V_15 ;
unsigned int V_56 ;
if ( V_42 == V_57 )
return 0 ;
V_57 = V_42 ;
F_9 ( L_10 ,
V_51 , V_41 , V_42 , V_55 ) ;
if ( V_58 ) {
if ( F_26 ( V_41 , V_58 ,
V_42 , V_55 ,
& V_56 ) ) {
F_9 ( L_11 , V_51 ) ;
return - V_54 ;
}
F_9 ( L_12 , V_51 ,
V_42 , V_56 , V_58 [ V_56 ] . V_18 ) ;
V_42 = V_58 [ V_56 ] . V_18 ;
}
V_42 *= 1000 ;
if ( ! V_59 || V_2 . V_60 ) {
V_15 = NULL ;
} else {
struct V_40 V_61 ;
int V_62 ;
V_61 . V_63 = V_41 -> V_63 * 1000 ;
V_61 . V_64 = V_41 -> V_64 * 1000 ;
V_61 . V_65 = V_41 -> V_65 ;
V_62 = F_26 ( & V_61 , V_59 ,
V_42 , V_55 ,
& V_56 ) ;
if ( V_62 < 0 ) {
F_20 ( V_49 L_13 , V_51 ) ;
goto V_50;
}
V_15 = V_59 + V_56 ;
F_9 ( L_14 ,
V_51 , V_42 , V_15 -> V_18 ) ;
V_42 = V_15 -> V_18 ;
}
return F_19 ( V_41 , V_42 , V_15 ) ;
V_50:
F_20 ( V_49 L_9 , V_42 ) ;
return - V_54 ;
}
struct V_39 * F_27 ( struct V_66 * V_67 , const char * V_68 )
{
struct V_39 * V_39 ;
V_39 = F_28 ( V_67 , V_68 ) ;
if ( F_29 ( V_39 ) )
F_20 ( V_49 L_15 , V_68 ) ;
return V_39 ;
}
static int F_30 ( struct V_40 * V_41 )
{
V_41 -> V_39 = V_14 ;
return F_31 ( V_41 , V_58 , V_2 . V_29 -> V_69 ) ;
}
static int T_1 F_32 ( void )
{
V_36 = F_27 ( NULL , L_16 ) ;
V_70 = F_27 ( NULL , L_17 ) ;
V_11 = F_27 ( NULL , L_18 ) ;
V_12 = F_27 ( NULL , L_19 ) ;
V_13 = F_27 ( NULL , L_20 ) ;
V_14 = F_27 ( NULL , L_21 ) ;
if ( F_29 ( V_11 ) || F_29 ( V_12 ) || F_29 ( V_13 ) ||
F_29 ( V_36 ) || F_29 ( V_14 ) || F_29 ( V_70 ) ) {
F_20 ( V_49 L_22 , V_51 ) ;
return - V_71 ;
}
F_20 ( V_72 L_23 , V_51 ,
F_4 ( V_11 ) / 1000 ,
F_4 ( V_12 ) / 1000 ,
F_4 ( V_13 ) / 1000 ,
F_4 ( V_14 ) / 1000 ) ;
return 0 ;
}
static int F_33 ( struct V_40 * V_41 )
{
V_73 . V_18 = F_4 ( V_36 ) ;
V_73 . V_16 = F_5 ( V_17 ) ;
V_74 = F_4 ( V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_40 * V_41 )
{
int V_62 ;
F_9 ( L_24 , V_51 , V_41 ) ;
V_57 = ~ 0 ;
F_16 () ;
V_62 = F_19 ( NULL , V_74 , & V_73 ) ;
if ( V_62 ) {
F_20 ( V_49 L_25 , V_51 ) ;
return V_62 ;
}
return 0 ;
}
int T_1 F_35 ( struct V_75 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_68 ) {
F_20 ( V_49 L_26 ,
V_51 ) ;
return - V_54 ;
}
F_20 ( V_72 L_27 ,
V_29 -> V_68 ) ;
F_36 ( V_29 -> V_32 == NULL ) ;
F_36 ( V_29 -> V_33 == NULL ) ;
F_36 ( V_29 -> V_34 == NULL ) ;
V_2 . V_29 = V_29 ;
return 0 ;
}
int T_1 F_37 ( struct V_76 * V_77 )
{
struct V_76 * V_78 ;
if ( ! V_77 ) {
F_20 ( V_72 L_28 , V_51 ) ;
return - V_54 ;
}
V_78 = F_38 ( sizeof( * V_78 ) , V_79 ) ;
if ( V_78 == NULL ) {
F_20 ( V_49 L_29 , V_51 ) ;
return - V_80 ;
}
* V_78 = * V_77 ;
V_2 . V_77 = V_78 ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_62 ;
if ( ! V_2 . V_29 -> V_81 ) {
F_20 ( V_49 L_30 , V_51 ) ;
return - V_71 ;
}
F_20 ( V_72 L_31 , V_51 ) ;
V_62 = ( V_2 . V_29 -> V_81 ) ( & V_2 , & V_4 ) ;
if ( V_62 )
F_20 ( V_49 L_32 , V_51 ) ;
return V_62 ;
}
static void F_40 ( struct V_82 * V_83 ,
struct V_82 * V_84 , struct V_82 * V_85 )
{
V_83 -> V_6 = F_41 ( V_84 -> V_6 , V_85 -> V_6 ) ;
V_83 -> V_8 = F_41 ( V_84 -> V_8 , V_85 -> V_8 ) ;
V_83 -> V_7 = F_41 ( V_84 -> V_7 , V_85 -> V_7 ) ;
V_83 -> V_9 = F_41 ( V_84 -> V_9 , V_85 -> V_9 ) ;
}
static inline T_2 F_42 ( T_2 V_10 , T_2 V_86 )
{
T_2 V_87 ;
V_87 = V_10 * V_86 ;
V_87 = F_43 ( V_87 , 1000 * 1000 ) ;
return V_87 ;
}
static void F_44 ( void )
{
unsigned int V_88 = V_2 . V_29 -> V_89 ;
T_2 V_90 = ( T_2 ) F_4 ( V_70 ) ;
T_2 V_91 ;
if ( V_88 == 0 ) {
F_45 ( 1 ) ;
return;
}
V_91 = F_42 ( V_90 , V_2 . V_29 -> V_92 ) << V_88 ;
V_91 |= F_42 ( V_90 , V_2 . V_29 -> V_93 ) ;
F_20 ( V_72 L_33 , V_51 , V_91 ) ;
F_46 ( V_91 , V_94 ) ;
}
static int F_47 ( void )
{
int V_95 , V_62 ;
if ( ! V_2 . V_29 -> V_96 )
return - V_54 ;
F_48 ( V_58 ) ;
V_58 = NULL ;
V_95 = V_2 . V_29 -> V_96 ( & V_2 , NULL , 0 ) ;
V_95 ++ ;
V_58 = F_38 ( sizeof( * V_58 ) * V_95 , V_79 ) ;
if ( ! V_58 ) {
F_20 ( V_49 L_34 , V_51 ) ;
return - V_80 ;
}
V_97 = V_95 ;
V_62 = V_2 . V_29 -> V_96 ( & V_2 , V_58 , V_95 ) ;
F_49 ( V_58 , V_62 , V_95 , V_98 ) ;
return 0 ;
}
static int T_1 F_50 ( void )
{
int V_62 = 0 ;
if ( V_2 . V_29 && V_2 . V_77 ) {
V_62 = F_32 () ;
if ( V_62 )
goto V_99;
F_3 ( & V_2 ) ;
F_8 ( L_2 , & V_2 ) ;
if ( V_2 . V_77 -> V_100 ) {
V_62 = F_39 () ;
if ( V_62 ) {
F_20 ( V_49 L_35 ,
V_51 ) ;
goto V_99;
}
}
if ( V_2 . V_77 -> V_101 && ! V_2 . V_29 -> V_30 ) {
F_20 ( V_49 L_36 ,
V_51 ) ;
V_62 = - V_54 ;
goto V_99;
}
if ( ! V_2 . V_29 -> V_102 )
V_2 . V_60 = 1 ;
F_44 () ;
F_40 ( & V_2 . V_64 , & V_2 . V_77 -> V_64 ,
& V_2 . V_29 -> V_64 ) ;
if ( V_2 . V_29 -> V_96 )
F_47 () ;
V_62 = F_51 ( & V_103 ) ;
}
V_99:
return V_62 ;
}
int T_1 F_52 ( struct V_43 * V_104 ,
unsigned int V_105 )
{
struct V_43 * V_106 ;
unsigned int V_95 ;
V_95 = sizeof( * V_106 ) * ( V_105 + 1 ) ;
V_106 = F_38 ( V_95 , V_79 ) ;
if ( V_106 ) {
memcpy ( V_106 , V_104 , V_95 ) ;
V_59 = V_106 ;
V_106 += V_105 ;
V_106 -> V_18 = V_98 ;
F_20 ( V_72 L_37 , V_105 ) ;
} else
F_20 ( V_49 L_38 ) ;
return V_106 ? 0 : - V_80 ;
}
