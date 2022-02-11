static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_3 (flow, &p->flows, list) {
if ( V_7 -> V_8 . V_4 == V_4 )
return V_7 ;
}
return NULL ;
}
static int F_4 ( struct V_2 * V_3 , unsigned long V_9 ,
struct V_2 * V_10 , struct V_2 * * V_11 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_9 ;
F_5 ( L_1 ,
V_3 , V_6 , V_7 , V_10 , V_11 ) ;
if ( F_6 ( & V_7 -> V_12 ) )
return - V_13 ;
if ( ! V_10 )
V_10 = & V_14 ;
* V_11 = V_7 -> V_15 ;
V_7 -> V_15 = V_10 ;
if ( * V_11 )
F_7 ( * V_11 ) ;
return 0 ;
}
static struct V_2 * F_8 ( struct V_2 * V_3 , unsigned long V_16 )
{
struct V_1 * V_7 = (struct V_1 * ) V_16 ;
F_5 ( L_2 , V_3 , V_7 ) ;
return V_7 ? V_7 -> V_15 : NULL ;
}
static unsigned long F_9 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 V_17 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_3 , V_18 , V_3 , V_6 , V_4 ) ;
V_7 = F_1 ( V_3 , V_4 ) ;
F_5 ( L_4 , V_18 , V_7 ) ;
return ( unsigned long ) V_7 ;
}
static unsigned long F_10 ( struct V_2 * V_3 ,
unsigned long V_19 , T_1 V_4 )
{
struct V_5 * V_6 V_17 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_3 , V_18 , V_3 , V_6 , V_4 ) ;
V_7 = F_1 ( V_3 , V_4 ) ;
if ( V_7 )
V_7 -> V_20 ++ ;
F_5 ( L_4 , V_18 , V_7 ) ;
return ( unsigned long ) V_7 ;
}
static void F_11 ( struct V_2 * V_3 , unsigned long V_16 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_16 ;
F_5 ( L_5 , V_3 , V_6 , V_7 ) ;
if ( -- V_7 -> V_20 )
return;
F_5 ( L_6 ) ;
F_12 ( & V_7 -> V_12 ) ;
F_5 ( L_7 , V_7 -> V_15 ) ;
F_13 ( V_7 -> V_15 ) ;
F_14 ( V_7 -> V_21 ) ;
if ( V_7 -> V_22 ) {
F_5 ( L_8 ,
F_15 ( V_7 -> V_22 -> V_23 ) ) ;
V_7 -> V_24 -> V_25 = V_7 -> V_26 ;
F_16 ( V_7 -> V_22 ) ;
}
if ( V_7 -> V_27 )
F_11 ( V_3 , ( unsigned long ) V_7 -> V_27 ) ;
if ( V_7 != & V_6 -> V_28 )
F_17 ( V_7 ) ;
}
static void F_18 ( struct V_29 * V_24 , struct V_30 * V_31 )
{
struct V_5 * V_6 = F_19 ( V_24 ) -> V_19 ;
F_5 ( L_9 , V_24 , V_31 , V_6 ) ;
F_19 ( V_24 ) -> V_26 ( V_24 , V_31 ) ;
F_20 ( & V_6 -> V_32 ) ;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_19 ,
struct V_33 * * V_34 , unsigned long * V_9 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) * V_9 ;
struct V_1 * V_27 = NULL ;
struct V_33 * V_35 = V_34 [ V_36 ] ;
struct V_33 * V_37 [ V_38 + 1 ] ;
struct V_39 * V_22 ;
int V_40 , error , V_41 ;
void * V_42 ;
F_5 ( L_10
L_11 , V_3 , V_6 , V_4 , V_19 , V_7 , V_35 ) ;
if ( V_19 && V_19 != V_43 && V_19 != V_3 -> V_44 )
return - V_13 ;
if ( V_7 )
return - V_45 ;
if ( V_35 == NULL )
return - V_13 ;
error = F_22 ( V_37 , V_38 , V_35 , V_46 , NULL ) ;
if ( error < 0 )
return error ;
if ( ! V_37 [ V_47 ] )
return - V_13 ;
V_40 = F_23 ( V_37 [ V_47 ] ) ;
F_5 ( L_12 , V_40 ) ;
if ( V_37 [ V_48 ] ) {
V_41 = F_24 ( V_37 [ V_48 ] ) ;
V_42 = F_25 ( V_37 [ V_48 ] ) ;
} else {
V_41 = V_49 ;
V_42 = NULL ;
}
if ( ! V_37 [ V_50 ] )
V_27 = NULL ;
else {
V_27 = (struct V_1 * )
F_9 ( V_3 , F_23 ( V_37 [ V_50 ] ) ) ;
if ( ! V_27 )
return - V_51 ;
}
F_5 ( L_13 ,
V_35 -> V_52 , F_24 ( V_35 ) , V_41 ) ;
V_22 = F_26 ( V_40 , & error ) ;
if ( ! V_22 )
return error ;
F_5 ( L_14 , F_15 ( V_22 -> V_23 ) ) ;
if ( V_22 -> V_53 -> V_54 != V_55 && V_22 -> V_53 -> V_54 != V_56 ) {
error = - V_57 ;
goto V_58;
}
if ( V_4 ) {
if ( F_27 ( V_4 ^ V_3 -> V_44 ) ) {
F_5 ( L_15 ) ;
error = - V_13 ;
goto V_58;
}
} else {
int V_59 ;
unsigned long V_16 ;
for ( V_59 = 1 ; V_59 < 0x8000 ; V_59 ++ ) {
V_4 = F_28 ( V_3 -> V_44 , 0x8000 | V_59 ) ;
V_16 = F_9 ( V_3 , V_4 ) ;
if ( ! V_16 )
break;
}
}
F_5 ( L_16 , V_4 ) ;
V_7 = F_29 ( sizeof( struct V_1 ) + V_41 , V_60 ) ;
F_5 ( L_17 , V_7 ) ;
if ( ! V_7 ) {
error = - V_61 ;
goto V_58;
}
error = F_30 ( & V_7 -> V_21 , & V_7 -> V_62 ) ;
if ( error ) {
F_17 ( V_7 ) ;
goto V_58;
}
V_7 -> V_15 = F_31 ( V_3 -> V_63 , & V_64 , V_4 ) ;
if ( ! V_7 -> V_15 )
V_7 -> V_15 = & V_14 ;
F_5 ( L_18 , V_7 -> V_15 ) ;
V_7 -> V_22 = V_22 ;
V_7 -> V_24 = F_32 ( V_22 ) ;
V_7 -> V_24 -> V_65 = V_7 ;
F_5 ( L_19 , V_7 -> V_24 ) ;
V_7 -> V_26 = V_7 -> V_24 -> V_25 ;
V_7 -> V_19 = V_6 ;
V_7 -> V_24 -> V_25 = F_18 ;
V_7 -> V_8 . V_4 = V_4 ;
V_7 -> V_20 = 1 ;
V_7 -> V_27 = V_27 ;
F_33 ( & V_7 -> V_12 , & V_6 -> V_28 . V_12 ) ;
V_7 -> V_41 = V_41 ;
if ( V_42 )
memcpy ( V_7 -> V_42 , V_42 , V_41 ) ;
else
memcpy ( V_7 -> V_42 , V_66 , sizeof( V_66 ) ) ;
* V_9 = ( unsigned long ) V_7 ;
return 0 ;
V_58:
F_16 ( V_22 ) ;
return error ;
}
static int F_34 ( struct V_2 * V_3 , unsigned long V_9 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_9 ;
F_5 ( L_20 , V_3 , V_6 , V_7 ) ;
if ( F_6 ( & V_7 -> V_12 ) )
return - V_13 ;
if ( F_35 ( V_7 -> V_62 ) || V_7 == & V_6 -> V_28 )
return - V_45 ;
if ( V_7 -> V_20 < 2 ) {
F_36 ( L_21 , V_7 -> V_20 ) ;
return - V_13 ;
}
if ( V_7 -> V_20 > 2 )
return - V_45 ;
F_11 ( V_3 , V_9 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_22 , V_3 , V_6 , V_68 ) ;
if ( V_68 -> V_69 )
return;
F_3 (flow, &p->flows, list) {
if ( V_68 -> V_70 >= V_68 -> V_71 &&
V_68 -> V_72 ( V_3 , ( unsigned long ) V_7 , V_68 ) < 0 ) {
V_68 -> V_69 = 1 ;
break;
}
V_68 -> V_70 ++ ;
}
}
static struct V_73 * F_38 ( struct V_2 * V_3 , unsigned long V_16 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_16 ;
F_5 ( L_23 , V_3 , V_6 , V_7 ) ;
return V_7 ? V_7 -> V_21 : V_6 -> V_28 . V_21 ;
}
static int F_39 ( struct V_30 * V_31 , struct V_2 * V_3 ,
struct V_30 * * V_74 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_75 V_76 ;
int V_77 ;
int V_78 = V_79 | V_80 ;
F_5 ( L_24 , V_31 , V_3 , V_6 ) ;
V_77 = V_81 ;
V_7 = NULL ;
if ( F_27 ( V_31 -> V_82 ) != V_3 -> V_44 ||
! ( V_7 = (struct V_1 * ) F_9 ( V_3 , V_31 -> V_82 ) ) ) {
struct V_83 * V_84 ;
F_3 (flow, &p->flows, list) {
V_84 = F_40 ( V_7 -> V_62 ) ;
if ( V_84 ) {
V_77 = F_41 ( V_31 , V_84 , & V_76 , true ) ;
if ( V_77 < 0 )
continue;
V_7 = (struct V_1 * ) V_76 . V_85 ;
if ( ! V_7 )
V_7 = F_1 ( V_3 , V_76 . V_4 ) ;
goto V_86;
}
}
V_7 = NULL ;
V_86:
;
}
if ( ! V_7 ) {
V_7 = & V_6 -> V_28 ;
} else {
if ( V_7 -> V_24 )
F_42 ( V_31 ) -> V_87 = V_7 -> V_24 -> V_87 ;
#ifdef F_43
switch ( V_77 ) {
case V_88 :
case V_89 :
case V_90 :
F_44 ( V_31 , V_74 ) ;
return V_79 | V_91 ;
case V_92 :
F_44 ( V_31 , V_74 ) ;
goto V_93;
case V_94 :
if ( V_7 -> V_27 )
V_7 = V_7 -> V_27 ;
else
F_42 ( V_31 ) -> V_87 |= V_95 ;
break;
}
#endif
}
V_78 = F_45 ( V_31 , V_7 -> V_15 , V_74 ) ;
if ( V_78 != V_79 ) {
V_93: V_17
if ( F_46 ( V_78 ) ) {
F_47 ( V_3 ) ;
if ( V_7 )
V_7 -> V_96 . V_97 ++ ;
}
return V_78 ;
}
if ( V_7 == & V_6 -> V_28 ) {
V_3 -> V_15 . V_98 ++ ;
return V_79 ;
}
F_20 ( & V_6 -> V_32 ) ;
return V_79 | V_80 ;
}
static void F_48 ( unsigned long V_99 )
{
struct V_2 * V_3 = (struct V_2 * ) V_99 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_30 * V_31 ;
F_5 ( L_25 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list) {
if ( V_7 == & V_6 -> V_28 )
continue;
while ( ( V_31 = V_7 -> V_15 -> V_53 -> V_100 ( V_7 -> V_15 ) ) ) {
if ( ! F_49 ( V_7 -> V_24 , V_31 -> V_101 ) )
break;
V_31 = F_50 ( V_7 -> V_15 ) ;
if ( F_51 ( ! V_31 ) )
break;
F_52 ( V_3 , V_31 ) ;
F_53 ( & V_7 -> V_102 , V_31 ) ;
F_5 ( L_26 , V_7 ) ;
F_54 ( V_31 , F_55 ( V_31 ) ) ;
if ( F_56 ( V_31 ) < V_7 -> V_41 ) {
struct V_30 * V_10 ;
V_10 = F_57 ( V_31 , V_7 -> V_41 ) ;
F_58 ( V_31 ) ;
if ( ! V_10 )
continue;
V_31 = V_10 ;
}
F_5 ( L_27 ,
F_59 ( V_31 ) , V_31 -> V_99 ) ;
F_42 ( V_31 ) -> V_24 = V_7 -> V_24 ;
memcpy ( F_60 ( V_31 , V_7 -> V_41 ) , V_7 -> V_42 ,
V_7 -> V_41 ) ;
F_61 ( V_31 -> V_101 ,
& F_62 ( V_7 -> V_24 ) -> V_103 ) ;
V_7 -> V_24 -> V_104 ( V_7 -> V_24 , V_31 ) ;
}
}
}
static struct V_30 * F_63 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_30 * V_31 ;
F_5 ( L_28 , V_3 , V_6 ) ;
F_20 ( & V_6 -> V_32 ) ;
V_31 = F_50 ( V_6 -> V_28 . V_15 ) ;
if ( V_31 )
V_3 -> V_15 . V_98 -- ;
return V_31 ;
}
static struct V_30 * F_64 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_5 ( L_29 , V_3 , V_6 ) ;
return V_6 -> V_28 . V_15 -> V_53 -> V_100 ( V_6 -> V_28 . V_15 ) ;
}
static int F_65 ( struct V_2 * V_3 , struct V_33 * V_35 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
int V_105 ;
F_5 ( L_30 , V_3 , V_6 , V_35 ) ;
F_66 ( & V_6 -> V_106 ) ;
F_66 ( & V_6 -> V_28 . V_12 ) ;
F_33 ( & V_6 -> V_28 . V_12 , & V_6 -> V_106 ) ;
V_6 -> V_28 . V_15 = F_31 ( V_3 -> V_63 ,
& V_64 , V_3 -> V_44 ) ;
if ( ! V_6 -> V_28 . V_15 )
V_6 -> V_28 . V_15 = & V_14 ;
F_5 ( L_31 , & V_6 -> V_28 , V_6 -> V_28 . V_15 ) ;
V_105 = F_30 ( & V_6 -> V_28 . V_21 , & V_6 -> V_28 . V_62 ) ;
if ( V_105 )
return V_105 ;
V_6 -> V_28 . V_24 = NULL ;
V_6 -> V_28 . V_22 = NULL ;
V_6 -> V_28 . V_8 . V_4 = V_3 -> V_44 ;
V_6 -> V_28 . V_20 = 1 ;
F_67 ( & V_6 -> V_32 , F_48 , ( unsigned long ) V_3 ) ;
return 0 ;
}
static void F_68 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_32 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list)
F_7 ( V_7 -> V_15 ) ;
V_3 -> V_15 . V_98 = 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 , * V_107 ;
F_5 ( L_33 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list) {
F_14 ( V_7 -> V_21 ) ;
V_7 -> V_21 = NULL ;
}
F_70 (flow, tmp, &p->flows, list) {
if ( V_7 -> V_20 > 1 )
F_36 ( L_34 , V_7 , V_7 -> V_20 ) ;
F_11 ( V_3 , ( unsigned long ) V_7 ) ;
}
F_71 ( & V_6 -> V_32 ) ;
}
static int F_72 ( struct V_2 * V_3 , unsigned long V_16 ,
struct V_30 * V_31 , struct V_108 * V_109 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_16 ;
struct V_33 * V_110 ;
F_5 ( L_35 ,
V_3 , V_6 , V_7 , V_31 , V_109 ) ;
if ( F_6 ( & V_7 -> V_12 ) )
return - V_13 ;
V_109 -> V_111 = V_7 -> V_8 . V_4 ;
V_109 -> V_112 = V_7 -> V_15 -> V_44 ;
V_110 = F_73 ( V_31 , V_36 ) ;
if ( V_110 == NULL )
goto V_113;
if ( F_74 ( V_31 , V_48 , V_7 -> V_41 , V_7 -> V_42 ) )
goto V_113;
if ( V_7 -> V_24 ) {
struct V_114 V_115 ;
int V_116 ;
memset ( & V_115 , 0 , sizeof( V_115 ) ) ;
V_115 . V_117 = V_118 ;
V_115 . V_119 . V_120 = V_7 -> V_24 -> V_121 ? V_7 -> V_24 -> V_121 -> V_122 : - 1 ;
V_115 . V_119 . V_123 = V_7 -> V_24 -> V_123 ;
V_115 . V_119 . V_124 = V_7 -> V_24 -> V_124 ;
if ( F_74 ( V_31 , V_125 , sizeof( V_115 ) , & V_115 ) )
goto V_113;
V_116 = F_75 ( V_7 -> V_24 -> V_126 ) ;
if ( F_76 ( V_31 , V_127 , V_116 ) )
goto V_113;
}
if ( V_7 -> V_27 ) {
if ( F_76 ( V_31 , V_50 , V_7 -> V_8 . V_4 ) )
goto V_113;
} else {
if ( F_76 ( V_31 , V_50 , 0 ) )
goto V_113;
}
return F_77 ( V_31 , V_110 ) ;
V_113:
F_78 ( V_31 , V_110 ) ;
return - 1 ;
}
static int
F_79 ( struct V_2 * V_3 , unsigned long V_9 ,
struct V_128 * V_129 )
{
struct V_1 * V_7 = (struct V_1 * ) V_9 ;
if ( F_80 ( F_81 ( V_3 ) ,
V_129 , NULL , & V_7 -> V_102 ) < 0 ||
F_82 ( V_129 , NULL , & V_7 -> V_96 , V_7 -> V_15 -> V_15 . V_98 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_30 * V_31 )
{
return 0 ;
}
static int T_2 F_84 ( void )
{
return F_85 ( & V_130 ) ;
}
static void T_3 F_86 ( void )
{
F_87 ( & V_130 ) ;
}
