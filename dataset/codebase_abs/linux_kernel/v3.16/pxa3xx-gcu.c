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
static int F_23 ( struct V_60 * V_60 , struct V_55 * V_55 )
{
return 0 ;
}
static T_3
F_24 ( struct V_55 * V_55 , const char * V_61 ,
T_4 V_62 , T_5 * V_63 )
{
int V_49 ;
unsigned long V_64 ;
struct V_29 * V_34 ;
struct V_1 * V_2 = F_21 ( V_55 ) ;
int V_65 = V_62 / 4 ;
V_2 -> V_9 -> V_66 ++ ;
V_2 -> V_9 -> V_67 += V_65 ;
if ( V_65 >= V_68 )
return - V_69 ;
if ( ! V_2 -> free ) {
V_49 = F_20 ( V_2 ) ;
if ( V_49 < 0 )
return V_49 ;
}
F_25 ( & V_2 -> V_41 , V_64 ) ;
V_34 = V_2 -> free ;
V_2 -> free = V_34 -> V_31 ;
F_26 ( & V_2 -> V_41 , V_64 ) ;
V_49 = F_27 ( V_34 -> V_70 , V_61 , V_65 * 4 ) ;
if ( V_49 ) {
F_25 ( & V_2 -> V_41 , V_64 ) ;
V_34 -> V_31 = V_2 -> free ;
V_2 -> free = V_34 ;
F_26 ( & V_2 -> V_41 , V_64 ) ;
return - V_71 ;
}
V_34 -> V_72 = V_65 ;
V_34 -> V_70 [ V_65 ] = 0x01000000 ;
F_25 ( & V_2 -> V_41 , V_64 ) ;
V_34 -> V_31 = NULL ;
if ( V_2 -> V_33 ) {
F_12 ( V_2 -> V_36 == NULL ) ;
V_2 -> V_36 -> V_31 = V_34 ;
} else
V_2 -> V_33 = V_34 ;
V_2 -> V_36 = V_34 ;
if ( ! V_2 -> V_9 -> V_25 )
F_11 ( V_2 ) ;
F_26 ( & V_2 -> V_41 , V_64 ) ;
return V_65 * 4 ;
}
static long
F_28 ( struct V_55 * V_55 , unsigned int V_73 , unsigned long V_74 )
{
unsigned long V_64 ;
struct V_1 * V_2 = F_21 ( V_55 ) ;
switch ( V_73 ) {
case V_75 :
F_25 ( & V_2 -> V_41 , V_64 ) ;
F_5 ( V_2 ) ;
F_26 ( & V_2 -> V_41 , V_64 ) ;
return 0 ;
case V_76 :
return F_18 ( V_2 ) ;
}
return - V_77 ;
}
static int
F_29 ( struct V_55 * V_55 , struct V_78 * V_79 )
{
unsigned int V_80 = V_79 -> V_81 - V_79 -> V_82 ;
struct V_1 * V_2 = F_21 ( V_55 ) ;
switch ( V_79 -> V_83 ) {
case 0 :
if ( V_80 != V_10 )
return - V_84 ;
return F_30 ( NULL , V_79 ,
V_2 -> V_9 , V_2 -> V_12 , V_80 ) ;
case V_10 >> V_85 :
if ( V_80 != F_31 ( V_2 -> V_86 ) )
return - V_84 ;
V_79 -> V_87 = F_32 ( V_79 -> V_87 ) ;
return F_33 ( V_79 , V_79 -> V_82 ,
V_2 -> V_86 -> V_88 >> V_85 ,
V_80 , V_79 -> V_87 ) ;
}
return - V_84 ;
}
static void F_34 ( unsigned long V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
F_16 ( L_16 ) ;
F_35 ( & V_89 ) ;
V_89 . V_90 = F_34 ;
V_89 . V_91 = V_70 ;
V_89 . V_92 = V_93 + 5 * V_52 ;
F_36 ( & V_89 ) ;
}
static void F_37 ( void )
{
F_34 ( ( unsigned long ) & V_89 ) ;
}
static inline void F_37 ( void ) {}
static int
F_38 ( struct V_94 * V_57 ,
struct V_1 * V_2 )
{
struct V_29 * V_34 ;
V_34 = F_39 ( sizeof( struct V_29 ) , V_95 ) ;
if ( ! V_34 )
return - V_96 ;
V_34 -> V_70 = F_40 ( V_57 , V_68 * 4 ,
& V_34 -> V_35 , V_95 ) ;
if ( ! V_34 -> V_70 ) {
F_41 ( V_34 ) ;
return - V_96 ;
}
V_34 -> V_31 = V_2 -> free ;
V_2 -> free = V_34 ;
return 0 ;
}
static void
F_42 ( struct V_94 * V_57 ,
struct V_1 * V_2 )
{
struct V_29 * V_31 , * V_34 = V_2 -> free ;
while ( V_34 ) {
V_31 = V_34 -> V_31 ;
F_43 ( V_57 , V_68 * 4 ,
V_34 -> V_70 , V_34 -> V_35 ) ;
F_41 ( V_34 ) ;
V_34 = V_31 ;
}
V_2 -> free = NULL ;
}
static int F_44 ( struct V_97 * V_98 )
{
int V_99 , V_49 , V_37 ;
struct V_100 * V_101 ;
struct V_1 * V_2 ;
struct V_94 * V_57 = & V_98 -> V_57 ;
V_2 = F_45 ( V_57 , sizeof( struct V_1 ) , V_95 ) ;
if ( ! V_2 )
return - V_96 ;
F_46 ( & V_2 -> V_46 ) ;
F_46 ( & V_2 -> V_44 ) ;
F_47 ( & V_2 -> V_41 ) ;
V_2 -> V_59 . V_102 = V_103 ,
V_2 -> V_59 . V_104 = V_105 ,
V_2 -> V_59 . V_106 = & V_107 ;
V_101 = F_48 ( V_98 , V_108 , 0 ) ;
V_2 -> V_4 = F_49 ( V_57 , V_101 ) ;
if ( F_50 ( V_2 -> V_4 ) )
return F_51 ( V_2 -> V_4 ) ;
V_2 -> V_109 = F_52 ( V_57 , NULL ) ;
if ( F_50 ( V_2 -> V_109 ) ) {
F_53 ( V_57 , L_17 ) ;
return F_51 ( V_2 -> V_109 ) ;
}
V_37 = F_54 ( V_98 , 0 ) ;
if ( V_37 < 0 ) {
F_53 ( V_57 , L_18 ) ;
return - V_110 ;
}
V_49 = F_55 ( V_57 , V_37 , F_13 ,
0 , V_105 , V_2 ) ;
if ( V_49 < 0 ) {
F_53 ( V_57 , L_19 ) ;
return V_49 ;
}
V_2 -> V_9 = F_40 ( V_57 , V_10 ,
& V_2 -> V_12 , V_95 ) ;
if ( ! V_2 -> V_9 ) {
F_53 ( V_57 , L_20 ) ;
return - V_96 ;
}
V_49 = F_56 ( & V_2 -> V_59 ) ;
if ( V_49 < 0 ) {
F_53 ( V_57 , L_21 ,
V_103 ) ;
goto V_111;
}
V_49 = F_57 ( V_2 -> V_109 ) ;
if ( V_49 < 0 ) {
F_53 ( V_57 , L_22 ) ;
goto V_112;
}
for ( V_99 = 0 ; V_99 < 8 ; V_99 ++ ) {
V_49 = F_38 ( V_57 , V_2 ) ;
if ( V_49 ) {
F_53 ( V_57 , L_20 ) ;
goto V_113;
}
}
F_58 ( V_98 , V_2 ) ;
V_2 -> V_86 = V_101 ;
F_5 ( V_2 ) ;
F_37 () ;
F_59 ( V_57 , L_23 ,
( void * ) V_101 -> V_88 , ( void * ) V_2 -> V_12 ,
V_10 , V_37 ) ;
return 0 ;
V_111:
F_43 ( V_57 , V_10 ,
V_2 -> V_9 , V_2 -> V_12 ) ;
V_112:
F_60 ( & V_2 -> V_59 ) ;
V_113:
F_61 ( V_2 -> V_109 ) ;
return V_49 ;
}
static int F_62 ( struct V_97 * V_98 )
{
struct V_1 * V_2 = F_63 ( V_98 ) ;
struct V_94 * V_57 = & V_98 -> V_57 ;
F_18 ( V_2 ) ;
F_60 ( & V_2 -> V_59 ) ;
F_43 ( V_57 , V_10 , V_2 -> V_9 , V_2 -> V_12 ) ;
F_42 ( V_57 , V_2 ) ;
return 0 ;
}
