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
F_19 ( V_48 L_3 , V_41 ) ;
goto V_49;
}
F_9 ( L_4 , V_50 ) ;
F_6 ( & V_45 ) ;
F_9 ( L_5 , V_50 ) ;
if ( V_45 . V_10 . V_8 != V_2 . V_10 . V_8 ) {
if ( F_11 ( & V_45 ) < 0 ) {
F_19 ( V_48 L_6 , V_50 ) ;
goto V_49;
}
}
F_8 ( L_7 , & V_45 ) ;
V_44 . V_51 = V_2 . V_10 ;
V_44 . V_52 = V_45 . V_10 ;
V_44 . V_44 . V_51 = V_2 . V_10 . V_9 / 1000 ;
V_44 . V_44 . V_52 = V_45 . V_10 . V_9 / 1000 ;
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
F_9 ( L_8 , V_50 ) ;
return 0 ;
V_49:
F_19 ( V_48 L_9 , V_41 ) ;
return - V_53 ;
}
static int F_24 ( struct V_39 * V_40 ,
unsigned int V_41 ,
unsigned int V_54 )
{
struct V_42 * V_15 ;
unsigned int V_55 ;
if ( V_41 == V_56 )
return 0 ;
V_56 = V_41 ;
F_9 ( L_10 ,
V_50 , V_40 , V_41 , V_54 ) ;
if ( V_57 ) {
if ( F_25 ( V_40 , V_57 ,
V_41 , V_54 ,
& V_55 ) ) {
F_9 ( L_11 , V_50 ) ;
return - V_53 ;
}
F_9 ( L_12 , V_50 ,
V_41 , V_55 , V_57 [ V_55 ] . V_18 ) ;
V_41 = V_57 [ V_55 ] . V_18 ;
}
V_41 *= 1000 ;
if ( ! V_58 || V_2 . V_59 ) {
V_15 = NULL ;
} else {
struct V_39 V_60 ;
int V_61 ;
V_60 . V_62 = V_40 -> V_62 * 1000 ;
V_60 . V_63 = V_40 -> V_63 * 1000 ;
V_60 . V_64 = V_40 -> V_64 ;
V_61 = F_25 ( & V_60 , V_58 ,
V_41 , V_54 ,
& V_55 ) ;
if ( V_61 < 0 ) {
F_19 ( V_48 L_13 , V_50 ) ;
goto V_49;
}
V_15 = V_58 + V_55 ;
F_9 ( L_14 ,
V_50 , V_41 , V_15 -> V_18 ) ;
V_41 = V_15 -> V_18 ;
}
return F_18 ( V_40 , V_41 , V_15 ) ;
V_49:
F_19 ( V_48 L_9 , V_41 ) ;
return - V_53 ;
}
struct V_38 * F_26 ( struct V_65 * V_66 , const char * V_67 )
{
struct V_38 * V_38 ;
V_38 = F_27 ( V_66 , V_67 ) ;
if ( F_28 ( V_38 ) )
F_19 ( V_48 L_15 , V_67 ) ;
return V_38 ;
}
static int F_29 ( struct V_39 * V_40 )
{
V_40 -> V_38 = V_14 ;
return F_30 ( V_40 , V_57 , V_2 . V_29 -> V_68 ) ;
}
static int T_1 F_31 ( void )
{
V_36 = F_26 ( NULL , L_16 ) ;
V_69 = F_26 ( NULL , L_17 ) ;
V_11 = F_26 ( NULL , L_18 ) ;
V_12 = F_26 ( NULL , L_19 ) ;
V_13 = F_26 ( NULL , L_20 ) ;
V_14 = F_26 ( NULL , L_21 ) ;
if ( F_28 ( V_11 ) || F_28 ( V_12 ) || F_28 ( V_13 ) ||
F_28 ( V_36 ) || F_28 ( V_14 ) || F_28 ( V_69 ) ) {
F_19 ( V_48 L_22 , V_50 ) ;
return - V_70 ;
}
F_19 ( V_71 L_23 , V_50 ,
F_4 ( V_11 ) / 1000 ,
F_4 ( V_12 ) / 1000 ,
F_4 ( V_13 ) / 1000 ,
F_4 ( V_14 ) / 1000 ) ;
return 0 ;
}
static int F_32 ( struct V_39 * V_40 )
{
V_72 . V_18 = F_4 ( V_36 ) ;
V_72 . V_16 = F_5 ( V_17 ) ;
V_73 = F_4 ( V_14 ) ;
return 0 ;
}
static int F_33 ( struct V_39 * V_40 )
{
int V_61 ;
F_9 ( L_24 , V_50 , V_40 ) ;
V_56 = ~ 0 ;
V_61 = F_18 ( NULL , V_73 , & V_72 ) ;
if ( V_61 ) {
F_19 ( V_48 L_25 , V_50 ) ;
return V_61 ;
}
return 0 ;
}
int F_34 ( struct V_74 * V_29 )
{
if ( ! V_29 || ! V_29 -> V_67 ) {
F_19 ( V_48 L_26 ,
V_50 ) ;
return - V_53 ;
}
F_19 ( V_71 L_27 ,
V_29 -> V_67 ) ;
F_35 ( V_29 -> V_32 == NULL ) ;
F_35 ( V_29 -> V_33 == NULL ) ;
F_35 ( V_29 -> V_34 == NULL ) ;
V_2 . V_29 = V_29 ;
return 0 ;
}
int T_1 F_36 ( struct V_75 * V_76 )
{
struct V_75 * V_77 ;
if ( ! V_76 ) {
F_19 ( V_71 L_28 , V_50 ) ;
return - V_53 ;
}
V_77 = F_37 ( sizeof( * V_77 ) , V_78 ) ;
if ( V_77 == NULL ) {
F_19 ( V_48 L_29 , V_50 ) ;
return - V_79 ;
}
* V_77 = * V_76 ;
V_2 . V_76 = V_77 ;
return 0 ;
}
static int T_1 F_38 ( void )
{
int V_61 ;
if ( ! V_2 . V_29 -> V_80 ) {
F_19 ( V_48 L_30 , V_50 ) ;
return - V_70 ;
}
F_19 ( V_71 L_31 , V_50 ) ;
V_61 = ( V_2 . V_29 -> V_80 ) ( & V_2 , & V_4 ) ;
if ( V_61 )
F_19 ( V_48 L_32 , V_50 ) ;
return V_61 ;
}
static void F_39 ( struct V_81 * V_82 ,
struct V_81 * V_83 , struct V_81 * V_84 )
{
V_82 -> V_6 = F_40 ( V_83 -> V_6 , V_84 -> V_6 ) ;
V_82 -> V_8 = F_40 ( V_83 -> V_8 , V_84 -> V_8 ) ;
V_82 -> V_7 = F_40 ( V_83 -> V_7 , V_84 -> V_7 ) ;
V_82 -> V_9 = F_40 ( V_83 -> V_9 , V_84 -> V_9 ) ;
}
static inline T_2 F_41 ( T_2 V_10 , T_2 V_85 )
{
T_2 V_86 ;
V_86 = V_10 * V_85 ;
V_86 = F_42 ( V_86 , 1000 * 1000 ) ;
return V_86 ;
}
static void F_43 ( void )
{
unsigned int V_87 = V_2 . V_29 -> V_88 ;
T_2 V_89 = ( T_2 ) F_4 ( V_69 ) ;
T_2 V_90 ;
if ( V_87 == 0 ) {
F_44 ( 1 ) ;
return;
}
V_90 = F_41 ( V_89 , V_2 . V_29 -> V_91 ) << V_87 ;
V_90 |= F_41 ( V_89 , V_2 . V_29 -> V_92 ) ;
F_19 ( V_71 L_33 , V_50 , V_90 ) ;
F_45 ( V_90 , V_93 ) ;
}
static int F_46 ( void )
{
int V_94 , V_61 ;
if ( ! V_2 . V_29 -> V_95 )
return - V_53 ;
F_47 ( V_57 ) ;
V_57 = NULL ;
V_94 = V_2 . V_29 -> V_95 ( & V_2 , NULL , 0 ) ;
V_94 ++ ;
V_57 = F_37 ( sizeof( * V_57 ) * V_94 , V_78 ) ;
if ( ! V_57 ) {
F_19 ( V_48 L_34 , V_50 ) ;
return - V_79 ;
}
V_96 = V_94 ;
V_61 = V_2 . V_29 -> V_95 ( & V_2 , V_57 , V_94 ) ;
F_48 ( V_57 , V_61 , V_94 , V_97 ) ;
return 0 ;
}
static int T_1 F_49 ( void )
{
int V_61 = 0 ;
if ( V_2 . V_29 && V_2 . V_76 ) {
V_61 = F_31 () ;
if ( V_61 )
goto V_98;
F_3 ( & V_2 ) ;
F_8 ( L_2 , & V_2 ) ;
if ( V_2 . V_76 -> V_99 ) {
V_61 = F_38 () ;
if ( V_61 ) {
F_19 ( V_48 L_35 ,
V_50 ) ;
goto V_98;
}
}
if ( V_2 . V_76 -> V_100 && ! V_2 . V_29 -> V_30 ) {
F_19 ( V_48 L_36 ,
V_50 ) ;
V_61 = - V_53 ;
goto V_98;
}
if ( ! V_2 . V_29 -> V_101 )
V_2 . V_59 = 1 ;
F_43 () ;
F_39 ( & V_2 . V_63 , & V_2 . V_76 -> V_63 ,
& V_2 . V_29 -> V_63 ) ;
if ( V_2 . V_29 -> V_95 )
F_46 () ;
V_61 = F_50 ( & V_102 ) ;
}
V_98:
return V_61 ;
}
int F_51 ( struct V_42 * V_103 ,
unsigned int V_104 )
{
struct V_42 * V_105 ;
unsigned int V_94 ;
V_94 = sizeof( * V_105 ) * ( V_104 + 1 ) ;
V_105 = F_37 ( V_94 , V_78 ) ;
if ( V_105 ) {
memcpy ( V_105 , V_103 , V_94 ) ;
V_58 = V_105 ;
V_105 += V_104 ;
V_105 -> V_18 = V_97 ;
F_19 ( V_71 L_37 , V_104 ) ;
} else
F_19 ( V_48 L_38 ) ;
return V_105 ? 0 : - V_79 ;
}
