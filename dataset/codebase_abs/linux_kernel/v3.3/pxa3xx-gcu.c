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
if ( V_49 < 0 )
break;
if ( V_49 > 0 )
continue;
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
static T_3
F_21 ( struct V_55 * V_56 , const char * V_57 ,
T_4 V_58 , T_5 * V_59 )
{
int V_49 ;
unsigned long V_60 ;
struct V_29 * V_34 ;
struct V_1 * V_2 =
F_22 ( V_56 -> V_61 , struct V_1 , V_62 ) ;
int V_63 = V_58 / 4 ;
V_2 -> V_9 -> V_64 ++ ;
V_2 -> V_9 -> V_65 += V_63 ;
if ( V_63 >= V_66 )
return - V_67 ;
if ( ! V_2 -> free ) {
V_49 = F_20 ( V_2 ) ;
if ( V_49 < 0 )
return V_49 ;
}
F_23 ( & V_2 -> V_41 , V_60 ) ;
V_34 = V_2 -> free ;
V_2 -> free = V_34 -> V_31 ;
F_24 ( & V_2 -> V_41 , V_60 ) ;
V_49 = F_25 ( V_34 -> V_68 , V_57 , V_63 * 4 ) ;
if ( V_49 ) {
F_23 ( & V_2 -> V_41 , V_60 ) ;
V_34 -> V_31 = V_2 -> free ;
V_2 -> free = V_34 ;
F_24 ( & V_2 -> V_41 , V_60 ) ;
return - V_69 ;
}
V_34 -> V_70 = V_63 ;
V_34 -> V_68 [ V_63 ] = 0x01000000 ;
F_23 ( & V_2 -> V_41 , V_60 ) ;
V_34 -> V_31 = NULL ;
if ( V_2 -> V_33 ) {
F_12 ( V_2 -> V_36 == NULL ) ;
V_2 -> V_36 -> V_31 = V_34 ;
} else
V_2 -> V_33 = V_34 ;
V_2 -> V_36 = V_34 ;
if ( ! V_2 -> V_9 -> V_25 )
F_11 ( V_2 ) ;
F_24 ( & V_2 -> V_41 , V_60 ) ;
return V_63 * 4 ;
}
static long
F_26 ( struct V_55 * V_56 , unsigned int V_71 , unsigned long V_72 )
{
unsigned long V_60 ;
struct V_1 * V_2 =
F_22 ( V_56 -> V_61 , struct V_1 , V_62 ) ;
switch ( V_71 ) {
case V_73 :
F_23 ( & V_2 -> V_41 , V_60 ) ;
F_5 ( V_2 ) ;
F_24 ( & V_2 -> V_41 , V_60 ) ;
return 0 ;
case V_74 :
return F_18 ( V_2 ) ;
}
return - V_75 ;
}
static int
F_27 ( struct V_55 * V_56 , struct V_76 * V_77 )
{
unsigned int V_78 = V_77 -> V_79 - V_77 -> V_80 ;
struct V_1 * V_2 =
F_22 ( V_56 -> V_61 , struct V_1 , V_62 ) ;
switch ( V_77 -> V_81 ) {
case 0 :
if ( V_78 != V_10 )
return - V_82 ;
return F_28 ( NULL , V_77 ,
V_2 -> V_9 , V_2 -> V_12 , V_78 ) ;
case V_10 >> V_83 :
if ( V_78 != F_29 ( V_2 -> V_84 ) )
return - V_82 ;
V_77 -> V_85 |= V_86 ;
V_77 -> V_87 = F_30 ( V_77 -> V_87 ) ;
return F_31 ( V_77 , V_77 -> V_80 ,
V_2 -> V_84 -> V_88 >> V_83 ,
V_78 , V_77 -> V_87 ) ;
}
return - V_82 ;
}
static void F_32 ( unsigned long V_68 )
{
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
F_16 ( L_16 ) ;
F_33 ( & V_89 ) ;
V_89 . V_90 = F_32 ;
V_89 . V_91 = V_68 ;
V_89 . V_92 = V_93 + 5 * V_52 ;
F_34 ( & V_89 ) ;
}
static void F_35 ( void )
{
F_32 ( ( unsigned long ) & V_89 ) ;
}
static inline void F_35 ( void ) {}
static int
F_36 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_29 * V_34 ;
V_34 = F_37 ( sizeof( struct V_29 ) , V_96 ) ;
if ( ! V_34 )
return - V_97 ;
V_34 -> V_68 = F_38 ( & V_95 -> V_95 , V_66 * 4 ,
& V_34 -> V_35 , V_96 ) ;
if ( ! V_34 -> V_68 ) {
F_39 ( V_34 ) ;
return - V_97 ;
}
V_34 -> V_31 = V_2 -> free ;
V_2 -> free = V_34 ;
return 0 ;
}
static void
F_40 ( struct V_94 * V_95 ,
struct V_1 * V_2 )
{
struct V_29 * V_31 , * V_34 = V_2 -> free ;
while ( V_34 ) {
V_31 = V_34 -> V_31 ;
F_41 ( & V_95 -> V_95 , V_66 * 4 ,
V_34 -> V_68 , V_34 -> V_35 ) ;
F_39 ( V_34 ) ;
V_34 = V_31 ;
}
V_2 -> free = NULL ;
}
static int T_6
F_42 ( struct V_94 * V_95 )
{
int V_98 , V_49 , V_37 ;
struct V_99 * V_100 ;
struct V_1 * V_2 ;
V_2 = F_37 ( sizeof( struct V_1 ) , V_96 ) ;
if ( ! V_2 )
return - V_97 ;
for ( V_98 = 0 ; V_98 < 8 ; V_98 ++ ) {
V_49 = F_36 ( V_95 , V_2 ) ;
if ( V_49 ) {
F_43 ( & V_95 -> V_95 , L_17 ) ;
goto V_101;
}
}
F_44 ( & V_2 -> V_46 ) ;
F_44 ( & V_2 -> V_44 ) ;
F_45 ( & V_2 -> V_41 ) ;
V_2 -> V_62 . V_102 = V_103 ;
V_2 -> V_62 . V_104 = F_21 ;
V_2 -> V_62 . V_105 = F_26 ;
V_2 -> V_62 . V_106 = F_27 ;
V_2 -> V_107 . V_108 = V_109 ,
V_2 -> V_107 . V_110 = V_111 ,
V_2 -> V_107 . V_112 = & V_2 -> V_62 ,
V_49 = F_46 ( & V_2 -> V_107 ) ;
if ( V_49 < 0 ) {
F_43 ( & V_95 -> V_95 , L_18 ,
V_109 ) ;
goto V_101;
}
V_100 = F_47 ( V_95 , V_113 , 0 ) ;
if ( V_100 == NULL ) {
F_43 ( & V_95 -> V_95 , L_19 ) ;
V_49 = - V_114 ;
goto V_115;
}
if ( ! F_48 ( V_100 -> V_88 , F_29 ( V_100 ) , V_95 -> V_110 ) ) {
F_43 ( & V_95 -> V_95 , L_20 ) ;
V_49 = - V_116 ;
goto V_115;
}
V_2 -> V_4 = F_49 ( V_100 -> V_88 , F_29 ( V_100 ) ) ;
if ( ! V_2 -> V_4 ) {
F_43 ( & V_95 -> V_95 , L_21 ) ;
V_49 = - V_116 ;
goto V_117;
}
V_2 -> V_9 = F_38 ( & V_95 -> V_95 , V_10 ,
& V_2 -> V_12 , V_96 ) ;
if ( ! V_2 -> V_9 ) {
F_43 ( & V_95 -> V_95 , L_17 ) ;
V_49 = - V_97 ;
goto V_118;
}
V_2 -> V_119 = F_50 ( & V_95 -> V_95 , NULL ) ;
if ( F_51 ( V_2 -> V_119 ) ) {
F_43 ( & V_95 -> V_95 , L_22 ) ;
V_49 = - V_114 ;
goto V_120;
}
V_49 = F_52 ( V_2 -> V_119 ) ;
if ( V_49 < 0 ) {
F_43 ( & V_95 -> V_95 , L_23 ) ;
goto V_121;
}
V_37 = F_53 ( V_95 , 0 ) ;
if ( V_37 < 0 ) {
F_43 ( & V_95 -> V_95 , L_24 ) ;
V_49 = - V_114 ;
goto V_121;
}
V_49 = F_54 ( V_37 , F_13 ,
0 , V_111 , V_2 ) ;
if ( V_49 ) {
F_43 ( & V_95 -> V_95 , L_25 ) ;
V_49 = - V_116 ;
goto V_121;
}
F_55 ( V_95 , V_2 ) ;
V_2 -> V_84 = V_100 ;
F_5 ( V_2 ) ;
F_35 () ;
F_56 ( & V_95 -> V_95 , L_26 ,
( void * ) V_100 -> V_88 , ( void * ) V_2 -> V_12 ,
V_10 , V_37 ) ;
return 0 ;
V_121:
F_57 ( V_2 -> V_119 ) ;
F_58 ( V_2 -> V_119 ) ;
V_120:
F_41 ( & V_95 -> V_95 , V_10 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
V_118:
F_59 ( V_2 -> V_4 ) ;
V_117:
F_60 ( V_100 -> V_88 , F_29 ( V_100 ) ) ;
V_115:
F_61 ( & V_2 -> V_107 ) ;
V_101:
F_55 ( V_95 , NULL ) ;
F_40 ( V_95 , V_2 ) ;
F_39 ( V_2 ) ;
return V_49 ;
}
static int T_7
F_62 ( struct V_94 * V_95 )
{
struct V_1 * V_2 = F_63 ( V_95 ) ;
struct V_99 * V_100 = V_2 -> V_84 ;
F_18 ( V_2 ) ;
F_61 ( & V_2 -> V_107 ) ;
F_41 ( & V_95 -> V_95 , V_10 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
F_59 ( V_2 -> V_4 ) ;
F_60 ( V_100 -> V_88 , F_29 ( V_100 ) ) ;
F_55 ( V_95 , NULL ) ;
F_57 ( V_2 -> V_119 ) ;
F_40 ( V_95 , V_2 ) ;
F_39 ( V_2 ) ;
return 0 ;
}
