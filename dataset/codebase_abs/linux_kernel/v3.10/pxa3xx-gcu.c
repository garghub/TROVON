static inline unsigned long
F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void
F_3 ( struct V_1 * V_2 , unsigned int V_3 , unsigned long V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void
F_5 ( struct V_1 * V_2 )
{
F_6 ( L_1 ) ;
F_3 ( V_2 , V_6 , 0 ) ;
F_3 ( V_2 , V_7 , V_8 ) ;
F_3 ( V_2 , V_7 , 0 ) ;
memset ( V_2 -> V_9 , 0 , V_10 ) ;
V_2 -> V_9 -> V_11 = V_2 -> V_12 ;
V_2 -> V_9 -> V_13 = V_14 ;
F_7 ( & V_2 -> V_15 ) ;
F_3 ( V_2 , V_16 , 0 ) ;
F_3 ( V_2 , V_17 , V_2 -> V_12 ) ;
F_3 ( V_2 , V_18 , V_2 -> V_12 ) ;
F_3 ( V_2 , V_6 , V_19 & ~ V_20 ) ;
}
static void
F_8 ( struct V_1 * V_2 )
{
struct V_21 * V_22 = V_2 -> V_9 ;
T_1 V_23 = F_1 ( V_2 , V_17 ) ;
F_6 ( L_2 ) ;
F_9 ( V_24 L_3
L_4 ,
V_22 -> V_25 ? L_5 : L_6 ,
F_1 ( V_2 , V_26 ) ,
F_1 ( V_2 , V_17 ) ,
F_1 ( V_2 , V_16 ) ,
( F_1 ( V_2 , V_27 ) - V_23 ) / 4 ,
( F_1 ( V_2 , V_28 ) - V_23 ) / 4 ,
( F_1 ( V_2 , V_18 ) - V_23 ) / 4 ) ;
}
static void
F_10 ( struct V_1 * V_2 )
{
struct V_29 * V_30 = V_2 -> V_30 ;
struct V_29 * V_31 ;
while ( V_30 ) {
V_31 = V_30 -> V_31 ;
V_30 -> V_31 = V_2 -> free ;
V_2 -> free = V_30 ;
V_30 = V_31 ;
}
V_2 -> V_30 = NULL ;
}
static void
F_11 ( struct V_1 * V_2 )
{
unsigned int V_32 = 0 ;
struct V_21 * V_9 = V_2 -> V_9 ;
struct V_29 * V_33 = V_2 -> V_33 ;
F_6 ( L_7 ) ;
F_12 ( ! V_33 ) ;
V_9 -> V_34 [ V_32 ++ ] = 0x05000000 ;
while ( V_33 ) {
V_9 -> V_34 [ V_32 ++ ] = 0x00000001 ;
V_9 -> V_34 [ V_32 ++ ] = V_33 -> V_35 ;
V_33 = V_33 -> V_31 ;
}
V_9 -> V_34 [ V_32 ++ ] = 0x05000000 ;
V_2 -> V_30 = V_2 -> V_33 ;
V_2 -> V_33 = V_2 -> V_36 = NULL ;
F_3 ( V_2 , V_16 , 0 ) ;
V_9 -> V_25 = 1 ;
F_3 ( V_2 , V_17 , V_9 -> V_11 ) ;
F_3 ( V_2 , V_18 , V_9 -> V_11 + V_32 * 4 ) ;
F_3 ( V_2 , V_16 , ( ( V_32 + 63 ) & ~ 63 ) * 4 ) ;
}
static T_2
F_13 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
struct V_21 * V_9 = V_2 -> V_9 ;
T_1 V_39 = F_1 ( V_2 , V_26 ) & V_19 ;
F_6 ( L_8 ) ;
if ( ! V_39 )
return V_40 ;
F_14 ( & V_2 -> V_41 ) ;
V_9 -> V_42 ++ ;
if ( V_39 & V_43 ) {
F_6 ( L_9 ) ;
F_10 ( V_2 ) ;
F_15 ( & V_2 -> V_44 ) ;
if ( V_2 -> V_33 ) {
F_11 ( V_2 ) ;
} else {
V_9 -> V_45 ++ ;
V_9 -> V_25 = 0 ;
F_6 ( L_10 ) ;
F_3 ( V_2 , V_16 , 0 ) ;
F_15 ( & V_2 -> V_46 ) ;
}
V_9 -> V_47 ++ ;
} else {
F_16 ( L_11 ) ;
F_8 ( V_2 ) ;
}
F_3 ( V_2 , V_26 , V_39 ) ;
F_17 ( & V_2 -> V_41 ) ;
return V_48 ;
}
static int
F_18 ( struct V_1 * V_2 )
{
int V_49 = 0 ;
F_6 ( L_12 ) ;
V_2 -> V_9 -> V_50 ++ ;
while ( V_2 -> V_9 -> V_25 ) {
int V_32 = V_2 -> V_9 -> V_42 ;
T_1 V_51 = F_1 ( V_2 , V_27 ) ;
V_49 = F_19 ( V_2 -> V_46 ,
! V_2 -> V_9 -> V_25 , V_52 * 4 ) ;
if ( V_49 != 0 )
break;
if ( F_1 ( V_2 , V_27 ) == V_51 &&
V_2 -> V_9 -> V_42 == V_32 ) {
F_16 ( L_13 ) ;
V_49 = - V_53 ;
break;
}
}
F_6 ( L_14 ) ;
return V_49 ;
}
static int
F_20 ( struct V_1 * V_2 )
{
int V_49 = 0 ;
F_6 ( L_15 ) ;
V_2 -> V_9 -> V_54 ++ ;
while ( ! V_2 -> free ) {
T_1 V_51 = F_1 ( V_2 , V_27 ) ;
V_49 = F_19 ( V_2 -> V_44 ,
V_2 -> free , V_52 * 4 ) ;
if ( V_49 < 0 )
break;
if ( V_49 > 0 )
continue;
if ( F_1 ( V_2 , V_27 ) == V_51 ) {
F_16 ( L_13 ) ;
V_49 = - V_53 ;
break;
}
}
F_6 ( L_14 ) ;
return V_49 ;
}
static inline struct V_1 * F_21 ( struct V_55 * V_55 )
{
struct V_56 * V_57 = V_55 -> V_58 ;
return F_22 ( V_57 , struct V_1 , V_59 ) ;
}
static T_3
F_23 ( struct V_55 * V_55 , const char * V_60 ,
T_4 V_61 , T_5 * V_62 )
{
int V_49 ;
unsigned long V_63 ;
struct V_29 * V_34 ;
struct V_1 * V_2 = F_21 ( V_55 ) ;
int V_64 = V_61 / 4 ;
V_2 -> V_9 -> V_65 ++ ;
V_2 -> V_9 -> V_66 += V_64 ;
if ( V_64 >= V_67 )
return - V_68 ;
if ( ! V_2 -> free ) {
V_49 = F_20 ( V_2 ) ;
if ( V_49 < 0 )
return V_49 ;
}
F_24 ( & V_2 -> V_41 , V_63 ) ;
V_34 = V_2 -> free ;
V_2 -> free = V_34 -> V_31 ;
F_25 ( & V_2 -> V_41 , V_63 ) ;
V_49 = F_26 ( V_34 -> V_69 , V_60 , V_64 * 4 ) ;
if ( V_49 ) {
F_24 ( & V_2 -> V_41 , V_63 ) ;
V_34 -> V_31 = V_2 -> free ;
V_2 -> free = V_34 ;
F_25 ( & V_2 -> V_41 , V_63 ) ;
return - V_70 ;
}
V_34 -> V_71 = V_64 ;
V_34 -> V_69 [ V_64 ] = 0x01000000 ;
F_24 ( & V_2 -> V_41 , V_63 ) ;
V_34 -> V_31 = NULL ;
if ( V_2 -> V_33 ) {
F_12 ( V_2 -> V_36 == NULL ) ;
V_2 -> V_36 -> V_31 = V_34 ;
} else
V_2 -> V_33 = V_34 ;
V_2 -> V_36 = V_34 ;
if ( ! V_2 -> V_9 -> V_25 )
F_11 ( V_2 ) ;
F_25 ( & V_2 -> V_41 , V_63 ) ;
return V_64 * 4 ;
}
static long
F_27 ( struct V_55 * V_55 , unsigned int V_72 , unsigned long V_73 )
{
unsigned long V_63 ;
struct V_1 * V_2 = F_21 ( V_55 ) ;
switch ( V_72 ) {
case V_74 :
F_24 ( & V_2 -> V_41 , V_63 ) ;
F_5 ( V_2 ) ;
F_25 ( & V_2 -> V_41 , V_63 ) ;
return 0 ;
case V_75 :
return F_18 ( V_2 ) ;
}
return - V_76 ;
}
static int
F_28 ( struct V_55 * V_55 , struct V_77 * V_78 )
{
unsigned int V_79 = V_78 -> V_80 - V_78 -> V_81 ;
struct V_1 * V_2 = F_21 ( V_55 ) ;
switch ( V_78 -> V_82 ) {
case 0 :
if ( V_79 != V_10 )
return - V_83 ;
return F_29 ( NULL , V_78 ,
V_2 -> V_9 , V_2 -> V_12 , V_79 ) ;
case V_10 >> V_84 :
if ( V_79 != F_30 ( V_2 -> V_85 ) )
return - V_83 ;
V_78 -> V_86 |= V_87 ;
V_78 -> V_88 = F_31 ( V_78 -> V_88 ) ;
return F_32 ( V_78 , V_78 -> V_81 ,
V_2 -> V_85 -> V_89 >> V_84 ,
V_79 , V_78 -> V_88 ) ;
}
return - V_83 ;
}
static void F_33 ( unsigned long V_69 )
{
struct V_1 * V_2 = (struct V_1 * ) V_69 ;
F_16 ( L_16 ) ;
F_34 ( & V_90 ) ;
V_90 . V_91 = F_33 ;
V_90 . V_92 = V_69 ;
V_90 . V_93 = V_94 + 5 * V_52 ;
F_35 ( & V_90 ) ;
}
static void F_36 ( void )
{
F_33 ( ( unsigned long ) & V_90 ) ;
}
static inline void F_36 ( void ) {}
static int
F_37 ( struct V_95 * V_57 ,
struct V_1 * V_2 )
{
struct V_29 * V_34 ;
V_34 = F_38 ( sizeof( struct V_29 ) , V_96 ) ;
if ( ! V_34 )
return - V_97 ;
V_34 -> V_69 = F_39 ( & V_57 -> V_57 , V_67 * 4 ,
& V_34 -> V_35 , V_96 ) ;
if ( ! V_34 -> V_69 ) {
F_40 ( V_34 ) ;
return - V_97 ;
}
V_34 -> V_31 = V_2 -> free ;
V_2 -> free = V_34 ;
return 0 ;
}
static void
F_41 ( struct V_95 * V_57 ,
struct V_1 * V_2 )
{
struct V_29 * V_31 , * V_34 = V_2 -> free ;
while ( V_34 ) {
V_31 = V_34 -> V_31 ;
F_42 ( & V_57 -> V_57 , V_67 * 4 ,
V_34 -> V_69 , V_34 -> V_35 ) ;
F_40 ( V_34 ) ;
V_34 = V_31 ;
}
V_2 -> free = NULL ;
}
static int F_43 ( struct V_95 * V_57 )
{
int V_98 , V_49 , V_37 ;
struct V_99 * V_100 ;
struct V_1 * V_2 ;
V_2 = F_38 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ ) {
V_49 = F_37 ( V_57 , V_2 ) ;
if ( V_49 ) {
F_44 ( & V_57 -> V_57 , L_17 ) ;
goto V_101;
}
}
F_45 ( & V_2 -> V_46 ) ;
F_45 ( & V_2 -> V_44 ) ;
F_46 ( & V_2 -> V_41 ) ;
V_2 -> V_59 . V_102 = V_103 ,
V_2 -> V_59 . V_104 = V_105 ,
V_2 -> V_59 . V_106 = & V_107 ,
V_49 = F_47 ( & V_2 -> V_59 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_57 -> V_57 , L_18 ,
V_103 ) ;
goto V_101;
}
V_100 = F_48 ( V_57 , V_108 , 0 ) ;
if ( V_100 == NULL ) {
F_44 ( & V_57 -> V_57 , L_19 ) ;
V_49 = - V_109 ;
goto V_110;
}
if ( ! F_49 ( V_100 -> V_89 , F_30 ( V_100 ) , V_57 -> V_104 ) ) {
F_44 ( & V_57 -> V_57 , L_20 ) ;
V_49 = - V_111 ;
goto V_110;
}
V_2 -> V_4 = F_50 ( V_100 -> V_89 , F_30 ( V_100 ) ) ;
if ( ! V_2 -> V_4 ) {
F_44 ( & V_57 -> V_57 , L_21 ) ;
V_49 = - V_111 ;
goto V_112;
}
V_2 -> V_9 = F_39 ( & V_57 -> V_57 , V_10 ,
& V_2 -> V_12 , V_96 ) ;
if ( ! V_2 -> V_9 ) {
F_44 ( & V_57 -> V_57 , L_17 ) ;
V_49 = - V_97 ;
goto V_113;
}
V_2 -> V_114 = F_51 ( & V_57 -> V_57 , NULL ) ;
if ( F_52 ( V_2 -> V_114 ) ) {
F_44 ( & V_57 -> V_57 , L_22 ) ;
V_49 = - V_109 ;
goto V_115;
}
V_49 = F_53 ( V_2 -> V_114 ) ;
if ( V_49 < 0 ) {
F_44 ( & V_57 -> V_57 , L_23 ) ;
goto V_116;
}
V_37 = F_54 ( V_57 , 0 ) ;
if ( V_37 < 0 ) {
F_44 ( & V_57 -> V_57 , L_24 ) ;
V_49 = - V_109 ;
goto V_116;
}
V_49 = F_55 ( V_37 , F_13 ,
0 , V_105 , V_2 ) ;
if ( V_49 ) {
F_44 ( & V_57 -> V_57 , L_25 ) ;
V_49 = - V_111 ;
goto V_116;
}
F_56 ( V_57 , V_2 ) ;
V_2 -> V_85 = V_100 ;
F_5 ( V_2 ) ;
F_36 () ;
F_57 ( & V_57 -> V_57 , L_26 ,
( void * ) V_100 -> V_89 , ( void * ) V_2 -> V_12 ,
V_10 , V_37 ) ;
return 0 ;
V_116:
F_58 ( V_2 -> V_114 ) ;
F_59 ( V_2 -> V_114 ) ;
V_115:
F_42 ( & V_57 -> V_57 , V_10 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
V_113:
F_60 ( V_2 -> V_4 ) ;
V_112:
F_61 ( V_100 -> V_89 , F_30 ( V_100 ) ) ;
V_110:
F_62 ( & V_2 -> V_59 ) ;
V_101:
F_56 ( V_57 , NULL ) ;
F_41 ( V_57 , V_2 ) ;
F_40 ( V_2 ) ;
return V_49 ;
}
static int F_63 ( struct V_95 * V_57 )
{
struct V_1 * V_2 = F_64 ( V_57 ) ;
struct V_99 * V_100 = V_2 -> V_85 ;
F_18 ( V_2 ) ;
F_62 ( & V_2 -> V_59 ) ;
F_42 ( & V_57 -> V_57 , V_10 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
F_60 ( V_2 -> V_4 ) ;
F_61 ( V_100 -> V_89 , F_30 ( V_100 ) ) ;
F_56 ( V_57 , NULL ) ;
F_58 ( V_2 -> V_114 ) ;
F_41 ( V_57 , V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
