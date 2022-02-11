static inline struct V_1 * F_1 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_3 (flow, &p->flows, list) {
if ( V_7 -> V_4 == V_4 )
return V_7 ;
}
return NULL ;
}
static int F_4 ( struct V_2 * V_3 , unsigned long V_8 ,
struct V_2 * V_9 , struct V_2 * * V_10 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_8 ;
F_5 ( L_1 ,
V_3 , V_6 , V_7 , V_9 , V_10 ) ;
if ( F_6 ( & V_7 -> V_11 ) )
return - V_12 ;
if ( ! V_9 )
V_9 = & V_13 ;
* V_10 = V_7 -> V_14 ;
V_7 -> V_14 = V_9 ;
if ( * V_10 )
F_7 ( * V_10 ) ;
return 0 ;
}
static struct V_2 * F_8 ( struct V_2 * V_3 , unsigned long V_15 )
{
struct V_1 * V_7 = (struct V_1 * ) V_15 ;
F_5 ( L_2 , V_3 , V_7 ) ;
return V_7 ? V_7 -> V_14 : NULL ;
}
static unsigned long F_9 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_5 * V_6 V_16 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_3 , V_3 , V_6 , V_4 ) ;
V_7 = F_1 ( V_3 , V_4 ) ;
if ( V_7 )
V_7 -> V_17 ++ ;
F_5 ( L_4 , V_7 ) ;
return ( unsigned long ) V_7 ;
}
static unsigned long F_10 ( struct V_2 * V_3 ,
unsigned long V_18 , T_1 V_4 )
{
return F_9 ( V_3 , V_4 ) ;
}
static void F_11 ( struct V_2 * V_3 , unsigned long V_15 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_15 ;
F_5 ( L_5 , V_3 , V_6 , V_7 ) ;
if ( -- V_7 -> V_17 )
return;
F_5 ( L_6 ) ;
F_12 ( & V_7 -> V_11 ) ;
F_5 ( L_7 , V_7 -> V_14 ) ;
F_13 ( V_7 -> V_14 ) ;
F_14 ( & V_7 -> V_19 ) ;
if ( V_7 -> V_20 ) {
F_5 ( L_8 ,
F_15 ( V_7 -> V_20 -> V_21 ) ) ;
V_7 -> V_22 -> V_23 = V_7 -> V_24 ;
F_16 ( V_7 -> V_20 ) ;
}
if ( V_7 -> V_25 )
F_11 ( V_3 , ( unsigned long ) V_7 -> V_25 ) ;
if ( V_7 != & V_6 -> V_26 )
F_17 ( V_7 ) ;
}
static void F_18 ( struct V_27 * V_22 , struct V_28 * V_29 )
{
struct V_5 * V_6 = F_19 ( V_22 ) -> V_18 ;
F_5 ( L_9 , V_22 , V_29 , V_6 ) ;
F_19 ( V_22 ) -> V_24 ( V_22 , V_29 ) ;
F_20 ( & V_6 -> V_30 ) ;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_18 ,
struct V_31 * * V_32 , unsigned long * V_8 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) * V_8 ;
struct V_1 * V_25 = NULL ;
struct V_31 * V_33 = V_32 [ V_34 ] ;
struct V_31 * V_35 [ V_36 + 1 ] ;
struct V_37 * V_20 ;
int V_38 , error , V_39 ;
void * V_40 ;
F_5 ( L_10
L_11 , V_3 , V_6 , V_4 , V_18 , V_7 , V_33 ) ;
if ( V_18 && V_18 != V_41 && V_18 != V_3 -> V_42 )
return - V_12 ;
if ( V_7 )
return - V_43 ;
if ( V_33 == NULL )
return - V_12 ;
error = F_22 ( V_35 , V_36 , V_33 , V_44 ) ;
if ( error < 0 )
return error ;
if ( ! V_35 [ V_45 ] )
return - V_12 ;
V_38 = F_23 ( V_35 [ V_45 ] ) ;
F_5 ( L_12 , V_38 ) ;
if ( V_35 [ V_46 ] ) {
V_39 = F_24 ( V_35 [ V_46 ] ) ;
V_40 = F_25 ( V_35 [ V_46 ] ) ;
} else {
V_39 = V_47 ;
V_40 = NULL ;
}
if ( ! V_35 [ V_48 ] )
V_25 = NULL ;
else {
V_25 = (struct V_1 * )
F_9 ( V_3 , F_23 ( V_35 [ V_48 ] ) ) ;
if ( ! V_25 )
return - V_49 ;
}
F_5 ( L_13 ,
V_33 -> V_50 , F_24 ( V_33 ) , V_39 ) ;
V_20 = F_26 ( V_38 , & error ) ;
if ( ! V_20 )
return error ;
F_5 ( L_14 , F_15 ( V_20 -> V_21 ) ) ;
if ( V_20 -> V_51 -> V_52 != V_53 && V_20 -> V_51 -> V_52 != V_54 ) {
error = - V_55 ;
goto V_56;
}
if ( V_4 ) {
if ( F_27 ( V_4 ^ V_3 -> V_42 ) ) {
F_5 ( L_15 ) ;
error = - V_12 ;
goto V_56;
}
} else {
int V_57 ;
unsigned long V_15 ;
for ( V_57 = 1 ; V_57 < 0x8000 ; V_57 ++ ) {
V_4 = F_28 ( V_3 -> V_42 , 0x8000 | V_57 ) ;
V_15 = F_9 ( V_3 , V_4 ) ;
if ( ! V_15 )
break;
F_11 ( V_3 , V_15 ) ;
}
}
F_5 ( L_16 , V_4 ) ;
V_7 = F_29 ( sizeof( struct V_1 ) + V_39 , V_58 ) ;
F_5 ( L_17 , V_7 ) ;
if ( ! V_7 ) {
error = - V_59 ;
goto V_56;
}
F_30 ( V_7 -> V_19 , NULL ) ;
V_7 -> V_14 = F_31 ( V_3 -> V_60 , & V_61 , V_4 ) ;
if ( ! V_7 -> V_14 )
V_7 -> V_14 = & V_13 ;
F_5 ( L_18 , V_7 -> V_14 ) ;
V_7 -> V_20 = V_20 ;
V_7 -> V_22 = F_32 ( V_20 ) ;
V_7 -> V_22 -> V_62 = V_7 ;
F_5 ( L_19 , V_7 -> V_22 ) ;
V_7 -> V_24 = V_7 -> V_22 -> V_23 ;
V_7 -> V_18 = V_6 ;
V_7 -> V_22 -> V_23 = F_18 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_17 = 1 ;
V_7 -> V_25 = V_25 ;
F_33 ( & V_7 -> V_11 , & V_6 -> V_26 . V_11 ) ;
V_7 -> V_39 = V_39 ;
if ( V_40 )
memcpy ( V_7 -> V_40 , V_40 , V_39 ) ;
else
memcpy ( V_7 -> V_40 , V_63 , sizeof( V_63 ) ) ;
* V_8 = ( unsigned long ) V_7 ;
return 0 ;
V_56:
if ( V_25 )
F_11 ( V_3 , ( unsigned long ) V_25 ) ;
F_16 ( V_20 ) ;
return error ;
}
static int F_34 ( struct V_2 * V_3 , unsigned long V_8 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_8 ;
F_5 ( L_20 , V_3 , V_6 , V_7 ) ;
if ( F_6 ( & V_7 -> V_11 ) )
return - V_12 ;
if ( F_35 ( V_7 -> V_19 ) || V_7 == & V_6 -> V_26 )
return - V_43 ;
if ( V_7 -> V_17 < 2 ) {
F_36 ( L_21 , V_7 -> V_17 ) ;
return - V_12 ;
}
if ( V_7 -> V_17 > 2 )
return - V_43 ;
F_11 ( V_3 , V_8 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 , struct V_64 * V_65 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_22 , V_3 , V_6 , V_65 ) ;
if ( V_65 -> V_66 )
return;
F_3 (flow, &p->flows, list) {
if ( V_65 -> V_67 >= V_65 -> V_68 &&
V_65 -> V_69 ( V_3 , ( unsigned long ) V_7 , V_65 ) < 0 ) {
V_65 -> V_66 = 1 ;
break;
}
V_65 -> V_67 ++ ;
}
}
static struct V_70 T_2 * * F_38 ( struct V_2 * V_3 ,
unsigned long V_15 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_15 ;
F_5 ( L_23 , V_3 , V_6 , V_7 ) ;
return V_7 ? & V_7 -> V_19 : & V_6 -> V_26 . V_19 ;
}
static int F_39 ( struct V_28 * V_29 , struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_71 V_72 ;
int V_73 ;
int V_74 = V_75 ;
F_5 ( L_24 , V_29 , V_3 , V_6 ) ;
V_73 = V_76 ;
V_7 = NULL ;
if ( F_27 ( V_29 -> V_77 ) != V_3 -> V_42 ||
! ( V_7 = (struct V_1 * ) F_9 ( V_3 , V_29 -> V_77 ) ) ) {
struct V_70 * V_78 ;
F_3 (flow, &p->flows, list) {
V_78 = F_40 ( V_7 -> V_19 ) ;
if ( V_78 ) {
V_73 = F_41 ( V_29 , V_78 , & V_72 , true ) ;
if ( V_73 < 0 )
continue;
V_7 = (struct V_1 * ) V_72 . V_79 ;
if ( ! V_7 )
V_7 = F_1 ( V_3 , V_72 . V_4 ) ;
goto V_80;
}
}
V_7 = NULL ;
V_80:
;
}
if ( ! V_7 ) {
V_7 = & V_6 -> V_26 ;
} else {
if ( V_7 -> V_22 )
F_42 ( V_29 ) -> V_81 = V_7 -> V_22 -> V_81 ;
#ifdef F_43
switch ( V_73 ) {
case V_82 :
case V_83 :
F_44 ( V_29 ) ;
return V_84 | V_85 ;
case V_86 :
F_44 ( V_29 ) ;
goto V_87;
case V_88 :
if ( V_7 -> V_25 )
V_7 = V_7 -> V_25 ;
else
F_42 ( V_29 ) -> V_81 |= V_89 ;
break;
}
#endif
}
V_74 = F_45 ( V_29 , V_7 -> V_14 ) ;
if ( V_74 != V_84 ) {
V_87: V_16
if ( F_46 ( V_74 ) ) {
F_47 ( V_3 ) ;
if ( V_7 )
V_7 -> V_90 . V_91 ++ ;
}
return V_74 ;
}
if ( V_7 == & V_6 -> V_26 ) {
V_3 -> V_14 . V_92 ++ ;
return V_84 ;
}
F_20 ( & V_6 -> V_30 ) ;
return V_84 | V_93 ;
}
static void F_48 ( unsigned long V_94 )
{
struct V_2 * V_3 = (struct V_2 * ) V_94 ;
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
struct V_28 * V_29 ;
F_5 ( L_25 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list) {
if ( V_7 == & V_6 -> V_26 )
continue;
while ( ( V_29 = V_7 -> V_14 -> V_51 -> V_95 ( V_7 -> V_14 ) ) ) {
if ( ! F_49 ( V_7 -> V_22 , V_29 -> V_96 ) )
break;
V_29 = F_50 ( V_7 -> V_14 ) ;
if ( F_51 ( ! V_29 ) )
break;
F_52 ( V_3 , V_29 ) ;
F_53 ( & V_7 -> V_97 , V_29 ) ;
F_5 ( L_26 , V_7 ) ;
F_54 ( V_29 , F_55 ( V_29 ) ) ;
if ( F_56 ( V_29 ) < V_7 -> V_39 ) {
struct V_28 * V_9 ;
V_9 = F_57 ( V_29 , V_7 -> V_39 ) ;
F_58 ( V_29 ) ;
if ( ! V_9 )
continue;
V_29 = V_9 ;
}
F_5 ( L_27 ,
F_59 ( V_29 ) , V_29 -> V_94 ) ;
F_42 ( V_29 ) -> V_22 = V_7 -> V_22 ;
memcpy ( F_60 ( V_29 , V_7 -> V_39 ) , V_7 -> V_40 ,
V_7 -> V_39 ) ;
F_61 ( V_29 -> V_96 ,
& F_62 ( V_7 -> V_22 ) -> V_98 ) ;
V_7 -> V_22 -> V_99 ( V_7 -> V_22 , V_29 ) ;
}
}
}
static struct V_28 * F_63 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_28 * V_29 ;
F_5 ( L_28 , V_3 , V_6 ) ;
F_20 ( & V_6 -> V_30 ) ;
V_29 = F_50 ( V_6 -> V_26 . V_14 ) ;
if ( V_29 )
V_3 -> V_14 . V_92 -- ;
return V_29 ;
}
static struct V_28 * F_64 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_5 ( L_29 , V_3 , V_6 ) ;
return V_6 -> V_26 . V_14 -> V_51 -> V_95 ( V_6 -> V_26 . V_14 ) ;
}
static unsigned int F_65 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
unsigned int V_100 ;
F_5 ( L_30 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list) {
if ( V_7 -> V_14 -> V_51 -> V_87 && ( V_100 = V_7 -> V_14 -> V_51 -> V_87 ( V_7 -> V_14 ) ) )
return V_100 ;
}
return 0 ;
}
static int F_66 ( struct V_2 * V_3 , struct V_31 * V_33 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
F_5 ( L_31 , V_3 , V_6 , V_33 ) ;
F_67 ( & V_6 -> V_101 ) ;
F_67 ( & V_6 -> V_26 . V_11 ) ;
F_33 ( & V_6 -> V_26 . V_11 , & V_6 -> V_101 ) ;
V_6 -> V_26 . V_14 = F_31 ( V_3 -> V_60 ,
& V_61 , V_3 -> V_42 ) ;
if ( ! V_6 -> V_26 . V_14 )
V_6 -> V_26 . V_14 = & V_13 ;
F_5 ( L_32 , & V_6 -> V_26 , V_6 -> V_26 . V_14 ) ;
F_30 ( V_6 -> V_26 . V_19 , NULL ) ;
V_6 -> V_26 . V_22 = NULL ;
V_6 -> V_26 . V_20 = NULL ;
V_6 -> V_26 . V_4 = V_3 -> V_42 ;
V_6 -> V_26 . V_17 = 1 ;
F_68 ( & V_6 -> V_30 , F_48 , ( unsigned long ) V_3 ) ;
return 0 ;
}
static void F_69 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 ;
F_5 ( L_33 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list)
F_7 ( V_7 -> V_14 ) ;
V_3 -> V_14 . V_92 = 0 ;
}
static void F_70 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 , * V_102 ;
F_5 ( L_34 , V_3 , V_6 ) ;
F_3 (flow, &p->flows, list)
F_14 ( & V_7 -> V_19 ) ;
F_71 (flow, tmp, &p->flows, list) {
if ( V_7 -> V_17 > 1 )
F_36 ( L_35 , V_7 , V_7 -> V_17 ) ;
F_11 ( V_3 , ( unsigned long ) V_7 ) ;
}
F_72 ( & V_6 -> V_30 ) ;
}
static int F_73 ( struct V_2 * V_3 , unsigned long V_15 ,
struct V_28 * V_29 , struct V_103 * V_104 )
{
struct V_5 * V_6 = F_2 ( V_3 ) ;
struct V_1 * V_7 = (struct V_1 * ) V_15 ;
struct V_31 * V_105 ;
F_5 ( L_36 ,
V_3 , V_6 , V_7 , V_29 , V_104 ) ;
if ( F_6 ( & V_7 -> V_11 ) )
return - V_12 ;
V_104 -> V_106 = V_7 -> V_4 ;
V_104 -> V_107 = V_7 -> V_14 -> V_42 ;
V_105 = F_74 ( V_29 , V_34 ) ;
if ( V_105 == NULL )
goto V_108;
if ( F_75 ( V_29 , V_46 , V_7 -> V_39 , V_7 -> V_40 ) )
goto V_108;
if ( V_7 -> V_22 ) {
struct V_109 V_110 ;
int V_111 ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_112 = V_113 ;
V_110 . V_114 . V_115 = V_7 -> V_22 -> V_116 ? V_7 -> V_22 -> V_116 -> V_117 : - 1 ;
V_110 . V_114 . V_118 = V_7 -> V_22 -> V_118 ;
V_110 . V_114 . V_119 = V_7 -> V_22 -> V_119 ;
if ( F_75 ( V_29 , V_120 , sizeof( V_110 ) , & V_110 ) )
goto V_108;
V_111 = F_76 ( V_7 -> V_22 -> V_121 ) ;
if ( F_77 ( V_29 , V_122 , V_111 ) )
goto V_108;
}
if ( V_7 -> V_25 ) {
if ( F_77 ( V_29 , V_48 , V_7 -> V_4 ) )
goto V_108;
} else {
if ( F_77 ( V_29 , V_48 , 0 ) )
goto V_108;
}
return F_78 ( V_29 , V_105 ) ;
V_108:
F_79 ( V_29 , V_105 ) ;
return - 1 ;
}
static int
F_80 ( struct V_2 * V_3 , unsigned long V_8 ,
struct V_123 * V_124 )
{
struct V_1 * V_7 = (struct V_1 * ) V_8 ;
if ( F_81 ( V_124 , NULL , & V_7 -> V_97 ) < 0 ||
F_82 ( V_124 , NULL , & V_7 -> V_90 , V_7 -> V_14 -> V_14 . V_92 ) < 0 )
return - 1 ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 , struct V_28 * V_29 )
{
return 0 ;
}
static int T_3 F_84 ( void )
{
return F_85 ( & V_125 ) ;
}
static void T_4 F_86 ( void )
{
F_87 ( & V_125 ) ;
}
