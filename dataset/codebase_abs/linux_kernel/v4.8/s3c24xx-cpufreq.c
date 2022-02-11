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
static inline void F_16 ( struct V_38 * V_38 ,
unsigned int V_10 )
{
F_17 ( V_38 , V_10 ) ;
}
static int F_18 ( struct V_39 * V_40 ,
unsigned int V_41 ,
struct V_42 * V_15 )
{
struct V_43 V_44 ;
struct V_1 V_45 ;
unsigned long V_46 ;
V_45 = V_2 ;
F_8 ( L_2 , & V_2 ) ;
V_45 . V_15 = V_15 ? * V_15 : V_2 . V_15 ;
if ( V_15 )
V_44 . V_47 = 1 ;
V_45 . V_10 . V_9 = V_41 ;
V_45 . V_10 . V_6 = V_45 . V_15 . V_18 ;
if ( F_14 ( & V_45 ) < 0 ) {
F_19 ( L_3 , V_41 ) ;
goto V_48;
}
F_9 ( L_4 , V_49 ) ;
F_6 ( & V_45 ) ;
F_9 ( L_5 , V_49 ) ;
if ( V_45 . V_10 . V_8 != V_2 . V_10 . V_8 ) {
if ( F_11 ( & V_45 ) < 0 ) {
F_19 ( L_6 , V_49 ) ;
goto V_48;
}
}
F_8 ( L_7 , & V_45 ) ;
V_44 . V_50 = V_2 . V_10 ;
V_44 . V_51 = V_45 . V_10 ;
V_44 . V_44 . V_50 = V_2 . V_10 . V_9 / 1000 ;
V_44 . V_44 . V_51 = V_45 . V_10 . V_9 / 1000 ;
F_16 ( V_36 , V_45 . V_15 . V_18 ) ;
F_16 ( V_11 , V_45 . V_10 . V_6 ) ;
F_16 ( V_12 , V_45 . V_10 . V_8 ) ;
F_16 ( V_13 , V_45 . V_10 . V_7 ) ;
F_20 ( V_40 , & V_44 . V_44 ) ;
F_21 ( V_46 ) ;
if ( V_45 . V_10 . V_8 < V_2 . V_10 . V_8 ) {
F_12 ( & V_45 ) ;
F_10 ( & V_45 ) ;
}
if ( V_45 . V_10 . V_6 == V_2 . V_10 . V_6 ) {
F_13 ( & V_45 ) ;
} else {
if ( V_45 . V_10 . V_6 < V_2 . V_10 . V_6 ) {
F_15 ( & V_45 ) ;
F_13 ( & V_45 ) ;
} else {
F_13 ( & V_45 ) ;
F_15 ( & V_45 ) ;
}
}
if ( V_45 . V_10 . V_8 > V_2 . V_10 . V_8 ) {
F_12 ( & V_45 ) ;
F_10 ( & V_45 ) ;
}
V_2 = V_45 ;
F_22 ( V_46 ) ;
F_23 ( V_40 , & V_44 . V_44 , 0 ) ;
F_9 ( L_8 , V_49 ) ;
return 0 ;
V_48:
F_19 ( L_9 , V_41 ) ;
return - V_52 ;
}
static int F_24 ( struct V_39 * V_40 ,
unsigned int V_41 ,
unsigned int V_53 )
{
struct V_42 * V_15 ;
unsigned int V_54 ;
if ( V_41 == V_55 )
return 0 ;
V_55 = V_41 ;
F_9 ( L_10 ,
V_49 , V_40 , V_41 , V_53 ) ;
if ( V_56 ) {
V_54 = F_25 ( V_40 , V_41 ,
V_53 ) ;
F_9 ( L_11 , V_49 ,
V_41 , V_54 , V_56 [ V_54 ] . V_18 ) ;
V_41 = V_56 [ V_54 ] . V_18 ;
}
V_41 *= 1000 ;
if ( ! V_57 || V_2 . V_58 ) {
V_15 = NULL ;
} else {
struct V_39 V_59 ;
V_59 . V_60 = V_40 -> V_60 * 1000 ;
V_59 . V_61 = V_40 -> V_61 * 1000 ;
V_59 . V_62 = V_40 -> V_62 ;
V_59 . V_63 = V_57 ;
V_54 = F_25 ( & V_59 , V_41 ,
V_53 ) ;
V_15 = V_57 + V_54 ;
F_9 ( L_12 ,
V_49 , V_41 , V_15 -> V_18 ) ;
V_41 = V_15 -> V_18 ;
}
return F_18 ( V_40 , V_41 , V_15 ) ;
}
struct V_38 * F_26 ( struct V_64 * V_65 , const char * V_66 )
{
struct V_38 * V_38 ;
V_38 = F_27 ( V_65 , V_66 ) ;
if ( F_28 ( V_38 ) )
F_19 ( L_13 , V_66 ) ;
return V_38 ;
}
static int F_29 ( struct V_39 * V_40 )
{
V_40 -> V_38 = V_14 ;
return F_30 ( V_40 , V_56 , V_2 . V_29 -> V_67 ) ;
}
static int T_1 F_31 ( void )
{
V_36 = F_26 ( NULL , L_14 ) ;
V_68 = F_26 ( NULL , L_15 ) ;
V_11 = F_26 ( NULL , L_16 ) ;
V_12 = F_26 ( NULL , L_17 ) ;
V_13 = F_26 ( NULL , L_18 ) ;
V_14 = F_26 ( NULL , L_19 ) ;
if ( F_28 ( V_11 ) || F_28 ( V_12 ) || F_28 ( V_13 ) ||
F_28 ( V_36 ) || F_28 ( V_14 ) || F_28 ( V_68 ) ) {
F_19 ( L_20 , V_49 ) ;
return - V_69 ;
}
F_32 ( L_21 ,
V_49 ,
F_4 ( V_11 ) / 1000 ,
F_4 ( V_12 ) / 1000 ,
F_4 ( V_13 ) / 1000 ,
F_4 ( V_14 ) / 1000 ) ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 )
{
V_70 . V_18 = F_4 ( V_36 ) ;
V_70 . V_16 = F_5 ( V_17 ) ;
V_71 = F_4 ( V_14 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_40 )
{
int V_72 ;
F_9 ( L_22 , V_49 , V_40 ) ;
V_55 = ~ 0 ;
V_72 = F_18 ( NULL , V_71 , & V_70 ) ;
if ( V_72 ) {
F_19 ( L_23 , V_49 ) ;
return V_72 ;
}
return 0 ;
}
int F_35 ( struct V_73 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_66 ) {
F_19 ( L_24 , V_49 ) ;
return - V_52 ;
}
F_32 ( L_25 ,
V_29 -> V_66 ) ;
F_36 ( V_29 -> V_32 == NULL ) ;
F_36 ( V_29 -> V_33 == NULL ) ;
F_36 ( V_29 -> V_34 == NULL ) ;
V_2 . V_29 = V_29 ;
return 0 ;
}
int T_1 F_37 ( struct V_74 * V_75 )
{
struct V_74 * V_76 ;
if ( ! V_75 ) {
F_32 ( L_26 , V_49 ) ;
return - V_52 ;
}
V_76 = F_38 ( sizeof( * V_76 ) , V_77 ) ;
if ( V_76 == NULL ) {
F_19 ( L_27 , V_49 ) ;
return - V_78 ;
}
* V_76 = * V_75 ;
V_2 . V_75 = V_76 ;
return 0 ;
}
static int T_1 F_39 ( void )
{
int V_72 ;
if ( ! V_2 . V_29 -> V_79 ) {
F_19 ( L_28 , V_49 ) ;
return - V_69 ;
}
F_32 ( L_29 , V_49 ) ;
V_72 = ( V_2 . V_29 -> V_79 ) ( & V_2 , & V_4 ) ;
if ( V_72 )
F_19 ( L_30 , V_49 ) ;
return V_72 ;
}
static void F_40 ( struct V_80 * V_81 ,
struct V_80 * V_82 , struct V_80 * V_83 )
{
V_81 -> V_6 = F_41 ( V_82 -> V_6 , V_83 -> V_6 ) ;
V_81 -> V_8 = F_41 ( V_82 -> V_8 , V_83 -> V_8 ) ;
V_81 -> V_7 = F_41 ( V_82 -> V_7 , V_83 -> V_7 ) ;
V_81 -> V_9 = F_41 ( V_82 -> V_9 , V_83 -> V_9 ) ;
}
static inline T_2 F_42 ( T_2 V_10 , T_2 V_84 )
{
T_2 V_85 ;
V_85 = V_10 * V_84 ;
V_85 = F_43 ( V_85 , 1000 * 1000 ) ;
return V_85 ;
}
static void F_44 ( void )
{
unsigned int V_86 = V_2 . V_29 -> V_87 ;
T_2 V_88 = ( T_2 ) F_4 ( V_68 ) ;
T_2 V_89 ;
if ( V_86 == 0 ) {
F_45 ( 1 ) ;
return;
}
V_89 = F_42 ( V_88 , V_2 . V_29 -> V_90 ) << V_86 ;
V_89 |= F_42 ( V_88 , V_2 . V_29 -> V_91 ) ;
F_32 ( L_31 , V_49 , V_89 ) ;
F_46 ( V_89 , V_92 ) ;
}
static int F_47 ( void )
{
int V_93 , V_72 ;
F_48 ( V_56 ) ;
V_93 = V_2 . V_29 -> V_94 ( & V_2 , NULL , 0 ) ;
V_93 ++ ;
V_56 = F_38 ( sizeof( * V_56 ) * V_93 , V_77 ) ;
if ( ! V_56 ) {
F_19 ( L_32 , V_49 ) ;
return - V_78 ;
}
V_95 = V_93 ;
V_72 = V_2 . V_29 -> V_94 ( & V_2 , V_56 , V_93 ) ;
F_49 ( V_56 , V_72 , V_93 , V_96 ) ;
return 0 ;
}
static int T_1 F_50 ( void )
{
int V_72 = 0 ;
if ( V_2 . V_29 && V_2 . V_75 ) {
V_72 = F_31 () ;
if ( V_72 )
goto V_97;
F_3 ( & V_2 ) ;
F_8 ( L_2 , & V_2 ) ;
if ( V_2 . V_75 -> V_98 ) {
V_72 = F_39 () ;
if ( V_72 ) {
F_19 ( L_33 ,
V_49 ) ;
goto V_97;
}
}
if ( V_2 . V_75 -> V_99 && ! V_2 . V_29 -> V_30 ) {
F_19 ( L_34 , V_49 ) ;
V_72 = - V_52 ;
goto V_97;
}
if ( ! V_2 . V_29 -> V_100 )
V_2 . V_58 = 1 ;
F_44 () ;
F_40 ( & V_2 . V_61 , & V_2 . V_75 -> V_61 ,
& V_2 . V_29 -> V_61 ) ;
if ( V_2 . V_29 -> V_94 )
F_47 () ;
V_72 = F_51 ( & V_101 ) ;
}
V_97:
return V_72 ;
}
int F_52 ( struct V_42 * V_102 ,
unsigned int V_103 )
{
struct V_42 * V_104 ;
unsigned int V_93 ;
V_93 = sizeof( * V_104 ) * ( V_103 + 1 ) ;
V_104 = F_38 ( V_93 , V_77 ) ;
if ( V_104 ) {
memcpy ( V_104 , V_102 , V_93 ) ;
V_57 = V_104 ;
V_104 += V_103 ;
V_104 -> V_18 = V_96 ;
F_32 ( L_35 , V_103 ) ;
} else
F_19 ( L_36 ) ;
return V_104 ? 0 : - V_78 ;
}
