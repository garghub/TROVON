static inline int F_1 ( struct V_1 * V_2 )
{
static const char V_3 [] = L_1 ;
char * V_4 = V_2 -> V_5 ;
int V_6 ;
if ( * V_4 )
return 0 ;
V_6 = F_2 ( V_4 , V_2 -> V_7 , V_8 ) ;
if ( V_6 + sizeof( V_3 ) > V_8 )
return - V_9 ;
memcpy ( V_4 + V_6 , V_3 , sizeof( V_3 ) ) ;
return 0 ;
}
static inline void F_3 ( struct V_10 * V_11 )
{
#ifdef F_4
if ( V_12 && V_11 && ! V_11 -> V_13 )
F_5 ( L_2 ,
V_11 -> V_14 ) ;
#endif
return;
}
static int F_6 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_15 ) ;
if ( V_2 -> V_16 & ( V_2 -> V_16 + 1 ) )
return - V_17 ;
if ( V_2 -> V_18 > V_19 / 8 )
return - V_17 ;
if ( V_2 -> V_20 < 0 )
return - V_17 ;
F_7 ( & V_2 -> V_21 , 1 ) ;
return F_1 ( V_2 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_22 * V_23 = ( void * ) V_2 ;
struct V_24 * V_25 = V_23 -> V_25 ;
V_25 -> free ( V_23 ) ;
F_9 ( V_25 ) ;
}
static struct V_26 * F_10 ( struct V_1 * V_2 ,
struct V_26 * V_27 ,
struct V_26 * V_28 ,
struct V_26 * V_29 )
{
struct V_30 * V_31 , * V_32 ;
if ( F_11 ( V_27 ) )
return NULL ;
V_31 = F_12 ( V_27 , struct V_30 , V_33 ) ;
V_32 = F_13 ( V_31 -> V_33 . V_34 , struct V_30 , V_33 ) ;
if ( V_31 -> V_2 && & V_32 -> V_33 != V_27 && ! V_32 -> V_2 )
V_32 -> V_2 = ( V_32 -> V_33 . V_34 == V_27 ) ? V_2 :
& F_13 ( V_32 -> V_33 . V_34 , struct V_30 ,
V_33 ) -> V_23 -> V_2 ;
F_14 ( & V_31 -> V_33 , V_29 ) ;
return & V_32 -> V_33 == V_27 ? V_28 : & V_32 -> V_23 -> V_2 . V_35 ;
}
static void F_15 ( struct V_22 * V_23 ,
struct V_26 * V_33 )
{
struct V_24 * V_25 = V_23 -> V_25 ;
if ( F_16 ( & V_23 -> V_2 ) )
return;
V_23 -> V_2 . V_36 |= V_37 ;
if ( F_17 ( & V_23 -> V_33 ) )
return;
if ( ! V_25 || ! F_18 ( V_25 ) )
return;
F_19 ( V_38 , & V_23 -> V_2 ) ;
F_14 ( & V_23 -> V_2 . V_39 , V_33 ) ;
F_20 ( & V_23 -> V_33 ) ;
V_23 -> V_2 . V_40 = F_8 ;
F_21 ( ! F_11 ( & V_23 -> V_2 . V_35 ) ) ;
}
void F_22 ( struct V_1 * V_2 , struct V_26 * V_33 ,
struct V_1 * V_41 )
{
T_1 V_42 = ( V_41 ? : V_2 ) -> V_36 ;
struct V_30 * V_31 , * V_32 ;
F_23 ( V_29 ) ;
struct V_26 * V_43 ;
F_23 ( V_27 ) ;
F_23 ( V_28 ) ;
V_43 = & V_2 -> V_35 ;
F_24 (spawn, n, spawns, list) {
if ( ( V_31 -> V_2 -> V_36 ^ V_42 ) & V_31 -> V_44 )
continue;
F_14 ( & V_31 -> V_33 , & V_28 ) ;
}
V_43 = & V_28 ;
do {
while ( ! F_11 ( V_43 ) ) {
struct V_22 * V_23 ;
V_31 = F_12 ( V_43 , struct V_30 ,
V_33 ) ;
V_23 = V_31 -> V_23 ;
F_21 ( & V_23 -> V_2 == V_2 ) ;
F_14 ( & V_31 -> V_33 , & V_27 ) ;
if ( & V_23 -> V_2 == V_41 )
break;
V_31 -> V_2 = NULL ;
V_43 = & V_23 -> V_2 . V_35 ;
}
} while ( ( V_43 = F_10 ( V_2 , & V_27 , & V_28 ,
& V_29 ) ) );
F_24 (spawn, n, &secondary_spawns, list) {
if ( V_31 -> V_2 )
F_14 ( & V_31 -> V_33 , & V_31 -> V_2 -> V_35 ) ;
else
F_15 ( V_31 -> V_23 , V_33 ) ;
}
}
static struct V_45 * F_25 ( struct V_1 * V_2 )
{
struct V_1 * V_46 ;
struct V_45 * V_47 ;
int V_48 = - V_49 ;
if ( F_16 ( V_2 ) )
goto V_50;
F_26 ( & V_2 -> V_35 ) ;
V_2 -> V_36 &= ~ V_51 ;
V_48 = - V_52 ;
F_27 (q, &crypto_alg_list, cra_list) {
if ( V_46 == V_2 )
goto V_50;
if ( F_28 ( V_46 ) )
continue;
if ( F_29 ( V_46 ) ) {
if ( ! strcmp ( V_2 -> V_5 , V_46 -> V_5 ) )
goto V_50;
continue;
}
if ( ! strcmp ( V_46 -> V_5 , V_2 -> V_7 ) ||
! strcmp ( V_46 -> V_7 , V_2 -> V_5 ) )
goto V_50;
}
V_47 = F_30 ( V_2 -> V_7 ,
V_2 -> V_36 | V_51 , 0 ) ;
if ( F_31 ( V_47 ) )
goto V_53;
V_48 = - V_54 ;
V_47 -> V_55 = F_32 ( V_2 ) ;
if ( ! V_47 -> V_55 )
goto V_56;
F_7 ( & V_47 -> V_2 . V_21 , 1 ) ;
memcpy ( V_47 -> V_2 . V_5 , V_2 -> V_5 ,
V_8 ) ;
V_47 -> V_2 . V_20 = V_2 -> V_20 ;
F_33 ( & V_2 -> V_39 , & V_57 ) ;
F_33 ( & V_47 -> V_2 . V_39 , & V_57 ) ;
V_53:
return V_47 ;
V_56:
F_34 ( V_47 ) ;
V_50:
V_47 = F_35 ( V_48 ) ;
goto V_53;
}
void F_36 ( const char * V_14 , int V_50 )
{
struct V_45 * V_58 ;
struct V_1 * V_2 ;
struct V_1 * V_46 ;
F_23 ( V_33 ) ;
F_37 ( & V_59 ) ;
F_27 (q, &crypto_alg_list, cra_list) {
if ( F_28 ( V_46 ) || ! F_29 ( V_46 ) )
continue;
V_58 = (struct V_45 * ) V_46 ;
if ( ! strcmp ( V_46 -> V_5 , V_14 ) )
goto V_60;
}
F_38 ( V_61 L_3 , V_14 , V_50 ) ;
goto V_62;
V_60:
V_46 -> V_36 |= V_37 ;
V_2 = V_58 -> V_55 ;
if ( V_50 || F_11 ( & V_2 -> V_39 ) )
goto V_63;
V_2 -> V_36 |= V_51 ;
F_27 (q, &crypto_alg_list, cra_list) {
if ( V_46 == V_2 )
continue;
if ( F_28 ( V_46 ) )
continue;
if ( F_29 ( V_46 ) ) {
struct V_45 * V_47 = ( void * ) V_46 ;
if ( strcmp ( V_2 -> V_7 , V_46 -> V_7 ) &&
strcmp ( V_2 -> V_5 , V_46 -> V_7 ) )
continue;
if ( V_47 -> V_55 )
continue;
if ( ( V_46 -> V_36 ^ V_2 -> V_36 ) & V_47 -> V_44 )
continue;
if ( ! F_32 ( V_2 ) )
continue;
V_47 -> V_55 = V_2 ;
continue;
}
if ( strcmp ( V_2 -> V_7 , V_46 -> V_7 ) )
continue;
if ( strcmp ( V_2 -> V_5 , V_46 -> V_5 ) &&
V_46 -> V_20 > V_2 -> V_20 )
continue;
F_22 ( V_46 , & V_33 , V_2 ) ;
}
V_63:
F_39 ( & V_58 -> V_64 ) ;
V_62:
F_40 ( & V_59 ) ;
F_41 ( & V_33 ) ;
}
void F_41 ( struct V_26 * V_33 )
{
struct V_1 * V_2 ;
struct V_1 * V_32 ;
F_24 (alg, n, list, cra_list) {
F_42 ( & V_2 -> V_39 ) ;
F_43 ( V_2 ) ;
}
}
static void F_44 ( struct V_45 * V_47 )
{
int V_50 ;
V_50 = F_45 ( V_65 , V_47 -> V_55 ) ;
if ( V_50 != V_66 ) {
if ( F_46 ( V_50 != V_67 ) )
goto V_53;
F_36 ( V_47 -> V_2 . V_5 , 0 ) ;
}
V_50 = F_47 ( & V_47 -> V_64 ) ;
F_46 ( V_50 ) ;
V_53:
F_48 ( & V_47 -> V_2 ) ;
}
int F_49 ( struct V_1 * V_2 )
{
struct V_45 * V_47 ;
int V_50 ;
V_50 = F_6 ( V_2 ) ;
if ( V_50 )
return V_50 ;
F_37 ( & V_59 ) ;
V_47 = F_25 ( V_2 ) ;
F_40 ( & V_59 ) ;
if ( F_31 ( V_47 ) )
return F_50 ( V_47 ) ;
F_44 ( V_47 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_26 * V_33 )
{
if ( F_52 ( F_11 ( & V_2 -> V_39 ) ) )
return - V_54 ;
V_2 -> V_36 |= V_37 ;
F_19 ( V_38 , V_2 ) ;
F_42 ( & V_2 -> V_39 ) ;
F_22 ( V_2 , V_33 , NULL ) ;
return 0 ;
}
int F_53 ( struct V_1 * V_2 )
{
int V_48 ;
F_23 ( V_33 ) ;
F_37 ( & V_59 ) ;
V_48 = F_51 ( V_2 , & V_33 ) ;
F_40 ( & V_59 ) ;
if ( V_48 )
return V_48 ;
F_21 ( F_54 ( & V_2 -> V_21 ) != 1 ) ;
if ( V_2 -> V_40 )
V_2 -> V_40 ( V_2 ) ;
F_41 ( & V_33 ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_68 , int V_69 )
{
int V_70 , V_48 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
V_48 = F_49 ( & V_68 [ V_70 ] ) ;
if ( V_48 )
goto V_50;
}
return 0 ;
V_50:
for ( -- V_70 ; V_70 >= 0 ; -- V_70 )
F_53 ( & V_68 [ V_70 ] ) ;
return V_48 ;
}
int F_56 ( struct V_1 * V_68 , int V_69 )
{
int V_70 , V_48 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
V_48 = F_53 ( & V_68 [ V_70 ] ) ;
if ( V_48 )
F_57 ( L_4 ,
V_68 [ V_70 ] . V_5 , V_68 [ V_70 ] . V_7 , V_48 ) ;
}
return 0 ;
}
int F_58 ( struct V_24 * V_25 )
{
struct V_24 * V_46 ;
int V_50 = - V_52 ;
F_37 ( & V_59 ) ;
F_3 ( V_25 -> V_10 ) ;
F_27 (q, &crypto_template_list, list) {
if ( V_46 == V_25 )
goto V_53;
}
F_33 ( & V_25 -> V_33 , & V_71 ) ;
F_19 ( V_72 , V_25 ) ;
V_50 = 0 ;
V_53:
F_40 ( & V_59 ) ;
return V_50 ;
}
void F_59 ( struct V_24 * V_25 )
{
struct V_22 * V_23 ;
struct V_73 * V_32 ;
struct V_74 * V_33 ;
F_23 ( V_75 ) ;
F_37 ( & V_59 ) ;
F_21 ( F_11 ( & V_25 -> V_33 ) ) ;
F_42 ( & V_25 -> V_33 ) ;
V_33 = & V_25 -> V_76 ;
F_60 (inst, list, list) {
int V_50 = F_51 ( & V_23 -> V_2 , & V_75 ) ;
F_21 ( V_50 ) ;
}
F_19 ( V_77 , V_25 ) ;
F_40 ( & V_59 ) ;
F_61 (inst, n, list, list) {
F_21 ( F_54 ( & V_23 -> V_2 . V_21 ) != 1 ) ;
V_25 -> free ( V_23 ) ;
}
F_41 ( & V_75 ) ;
}
static struct V_24 * F_62 ( const char * V_14 )
{
struct V_24 * V_46 , * V_25 = NULL ;
F_63 ( & V_59 ) ;
F_27 (q, &crypto_template_list, list) {
if ( strcmp ( V_46 -> V_14 , V_14 ) )
continue;
if ( F_52 ( ! F_18 ( V_46 ) ) )
continue;
V_25 = V_46 ;
break;
}
F_64 ( & V_59 ) ;
return V_25 ;
}
struct V_24 * F_65 ( const char * V_14 )
{
return F_66 ( F_62 ( V_14 ) ,
L_5 , V_14 ) ;
}
int F_67 ( struct V_24 * V_25 ,
struct V_22 * V_23 )
{
struct V_45 * V_47 ;
int V_50 ;
V_50 = F_6 ( & V_23 -> V_2 ) ;
if ( V_50 )
return V_50 ;
V_23 -> V_2 . V_15 = V_25 -> V_10 ;
V_23 -> V_2 . V_36 |= V_78 ;
if ( F_52 ( ! F_32 ( & V_23 -> V_2 ) ) )
return - V_49 ;
F_37 ( & V_59 ) ;
V_47 = F_25 ( & V_23 -> V_2 ) ;
if ( F_31 ( V_47 ) )
goto V_62;
F_68 ( & V_23 -> V_33 , & V_25 -> V_76 ) ;
V_23 -> V_25 = V_25 ;
V_62:
F_40 ( & V_59 ) ;
V_50 = F_50 ( V_47 ) ;
if ( F_31 ( V_47 ) )
goto V_50;
F_44 ( V_47 ) ;
if ( ! ( V_23 -> V_2 . V_36 & V_51 ) )
F_69 ( V_23 ) ;
V_50 = 0 ;
V_50:
F_70 ( & V_23 -> V_2 ) ;
return V_50 ;
}
int F_69 ( struct V_22 * V_23 )
{
F_23 ( V_33 ) ;
F_37 ( & V_59 ) ;
F_22 ( & V_23 -> V_2 , & V_33 , NULL ) ;
F_15 ( V_23 , & V_33 ) ;
F_40 ( & V_59 ) ;
F_41 ( & V_33 ) ;
return 0 ;
}
int F_71 ( struct V_30 * V_31 , struct V_1 * V_2 ,
struct V_22 * V_23 , T_1 V_44 )
{
int V_50 = - V_49 ;
V_31 -> V_23 = V_23 ;
V_31 -> V_44 = V_44 ;
F_37 ( & V_59 ) ;
if ( ! F_28 ( V_2 ) ) {
F_33 ( & V_31 -> V_33 , & V_2 -> V_35 ) ;
V_31 -> V_2 = V_2 ;
V_50 = 0 ;
}
F_40 ( & V_59 ) ;
return V_50 ;
}
int F_72 ( struct V_30 * V_31 , struct V_1 * V_2 ,
struct V_22 * V_23 ,
const struct V_79 * V_80 )
{
int V_50 = - V_17 ;
if ( ( V_2 -> V_36 ^ V_80 -> type ) & V_80 -> V_81 )
goto V_53;
V_31 -> V_80 = V_80 ;
V_50 = F_71 ( V_31 , V_2 , V_23 , V_80 -> V_81 ) ;
V_53:
return V_50 ;
}
void F_73 ( struct V_30 * V_31 )
{
if ( ! V_31 -> V_2 )
return;
F_37 ( & V_59 ) ;
F_74 ( & V_31 -> V_33 ) ;
F_40 ( & V_59 ) ;
}
static struct V_1 * F_75 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_82 ;
F_63 ( & V_59 ) ;
V_2 = V_31 -> V_2 ;
V_82 = V_2 ;
if ( V_82 )
V_82 = F_32 ( V_82 ) ;
F_64 ( & V_59 ) ;
if ( ! V_82 ) {
if ( V_2 )
F_76 ( V_2 ) ;
return F_35 ( - V_49 ) ;
}
return V_2 ;
}
struct V_83 * F_77 ( struct V_30 * V_31 , T_1 type ,
T_1 V_44 )
{
struct V_1 * V_2 ;
struct V_83 * V_84 ;
V_2 = F_75 ( V_31 ) ;
if ( F_31 ( V_2 ) )
return F_78 ( V_2 ) ;
V_84 = F_35 ( - V_17 ) ;
if ( F_52 ( ( V_2 -> V_36 ^ type ) & V_44 ) )
goto V_85;
V_84 = F_79 ( V_2 , type , V_44 ) ;
if ( F_31 ( V_84 ) )
goto V_85;
return V_84 ;
V_85:
F_70 ( V_2 ) ;
return V_84 ;
}
void * F_80 ( struct V_30 * V_31 )
{
struct V_1 * V_2 ;
struct V_83 * V_84 ;
V_2 = F_75 ( V_31 ) ;
if ( F_31 ( V_2 ) )
return F_78 ( V_2 ) ;
V_84 = F_81 ( V_2 , V_31 -> V_80 ) ;
if ( F_31 ( V_84 ) )
goto V_85;
return V_84 ;
V_85:
F_70 ( V_2 ) ;
return V_84 ;
}
int F_82 ( struct V_86 * V_87 )
{
return F_83 ( & V_88 , V_87 ) ;
}
int F_84 ( struct V_86 * V_87 )
{
return F_85 ( & V_88 , V_87 ) ;
}
struct V_89 * F_86 ( struct V_90 * * V_91 )
{
struct V_90 * V_92 = V_91 [ 0 ] ;
struct V_89 * V_93 ;
if ( ! V_92 )
return F_35 ( - V_54 ) ;
if ( F_87 ( V_92 ) < sizeof( * V_93 ) )
return F_35 ( - V_17 ) ;
if ( V_92 -> V_94 != V_95 )
return F_35 ( - V_17 ) ;
V_93 = F_88 ( V_92 ) ;
return V_93 ;
}
int F_89 ( struct V_90 * * V_91 , T_1 type )
{
struct V_89 * V_93 ;
V_93 = F_86 ( V_91 ) ;
if ( F_31 ( V_93 ) )
return F_50 ( V_93 ) ;
if ( ( V_93 -> type ^ type ) & V_93 -> V_44 )
return - V_17 ;
return 0 ;
}
const char * F_90 ( struct V_90 * V_92 )
{
struct V_96 * V_97 ;
if ( ! V_92 )
return F_35 ( - V_54 ) ;
if ( F_87 ( V_92 ) < sizeof( * V_97 ) )
return F_35 ( - V_17 ) ;
if ( V_92 -> V_94 != V_98 )
return F_35 ( - V_17 ) ;
V_97 = F_88 ( V_92 ) ;
V_97 -> V_14 [ V_8 - 1 ] = 0 ;
return V_97 -> V_14 ;
}
struct V_1 * F_91 ( struct V_90 * V_92 ,
const struct V_79 * V_80 ,
T_1 type , T_1 V_44 )
{
const char * V_14 ;
V_14 = F_90 ( V_92 ) ;
if ( F_31 ( V_14 ) )
return F_78 ( V_14 ) ;
return F_92 ( V_14 , V_80 , type , V_44 ) ;
}
int F_93 ( struct V_90 * V_92 , T_1 * V_99 )
{
struct F_93 * V_100 ;
if ( ! V_92 )
return - V_54 ;
if ( F_87 ( V_92 ) < sizeof( * V_100 ) )
return - V_17 ;
if ( V_92 -> V_94 != V_101 )
return - V_17 ;
V_100 = F_88 ( V_92 ) ;
* V_99 = V_100 -> V_99 ;
return 0 ;
}
void * F_94 ( const char * V_14 , struct V_1 * V_2 ,
unsigned int V_102 )
{
struct V_22 * V_23 ;
char * V_103 ;
int V_50 ;
V_103 = F_95 ( V_102 + sizeof( * V_23 ) + sizeof( struct V_30 ) ,
V_104 ) ;
if ( ! V_103 )
return F_35 ( - V_105 ) ;
V_23 = ( void * ) ( V_103 + V_102 ) ;
V_50 = - V_9 ;
if ( snprintf ( V_23 -> V_2 . V_7 , V_8 , L_6 , V_14 ,
V_2 -> V_7 ) >= V_8 )
goto V_106;
if ( snprintf ( V_23 -> V_2 . V_5 , V_8 , L_6 ,
V_14 , V_2 -> V_5 ) >= V_8 )
goto V_106;
return V_103 ;
V_106:
F_34 ( V_103 ) ;
return F_35 ( V_50 ) ;
}
struct V_22 * F_96 ( const char * V_14 ,
struct V_1 * V_2 )
{
struct V_22 * V_23 ;
struct V_30 * V_31 ;
int V_50 ;
V_23 = F_94 ( V_14 , V_2 , 0 ) ;
if ( F_31 ( V_23 ) )
goto V_53;
V_31 = F_97 ( V_23 ) ;
V_50 = F_71 ( V_31 , V_2 , V_23 ,
V_107 | V_108 ) ;
if ( V_50 )
goto V_106;
return V_23 ;
V_106:
F_34 ( V_23 ) ;
V_23 = F_35 ( V_50 ) ;
V_53:
return V_23 ;
}
void F_98 ( struct V_109 * V_110 , unsigned int V_111 )
{
F_26 ( & V_110 -> V_33 ) ;
V_110 -> V_112 = & V_110 -> V_33 ;
V_110 -> V_113 = 0 ;
V_110 -> V_111 = V_111 ;
}
int F_99 ( struct V_109 * V_110 ,
struct V_114 * V_115 )
{
int V_50 = - V_116 ;
if ( F_52 ( V_110 -> V_113 >= V_110 -> V_111 ) ) {
V_50 = - V_117 ;
if ( ! ( V_115 -> V_118 & V_119 ) )
goto V_53;
if ( V_110 -> V_112 == & V_110 -> V_33 )
V_110 -> V_112 = & V_115 -> V_33 ;
}
V_110 -> V_113 ++ ;
F_100 ( & V_115 -> V_33 , & V_110 -> V_33 ) ;
V_53:
return V_50 ;
}
void * F_101 ( struct V_109 * V_110 , unsigned int V_120 )
{
struct V_26 * V_115 ;
if ( F_52 ( ! V_110 -> V_113 ) )
return NULL ;
V_110 -> V_113 -- ;
if ( V_110 -> V_112 != & V_110 -> V_33 )
V_110 -> V_112 = V_110 -> V_112 -> V_34 ;
V_115 = V_110 -> V_33 . V_34 ;
F_74 ( V_115 ) ;
return ( char * ) F_13 ( V_115 , struct V_114 , V_33 ) -
V_120 ;
}
struct V_114 * F_102 ( struct V_109 * V_110 )
{
return F_101 ( V_110 , 0 ) ;
}
int F_103 ( struct V_109 * V_110 , struct V_83 * V_84 )
{
struct V_114 * V_121 ;
F_27 (req, &queue->list, list) {
if ( V_121 -> V_84 == V_84 )
return 1 ;
}
return 0 ;
}
static inline void F_104 ( T_2 * V_122 , unsigned int V_123 )
{
T_2 * V_124 = ( V_122 + V_123 ) ;
T_2 V_125 ;
for (; V_123 ; V_123 -- ) {
V_125 = * -- V_124 + 1 ;
* V_124 = V_125 ;
if ( V_125 )
break;
}
}
void F_105 ( T_2 * V_122 , unsigned int V_123 )
{
T_3 * V_124 = ( T_3 * ) ( V_122 + V_123 ) ;
T_1 V_125 ;
for (; V_123 >= 4 ; V_123 -= 4 ) {
V_125 = F_106 ( * -- V_124 ) + 1 ;
* V_124 = F_107 ( V_125 ) ;
if ( V_125 )
return;
}
F_104 ( V_122 , V_123 ) ;
}
static inline void F_108 ( T_2 * V_122 , const T_2 * V_124 , unsigned int V_123 )
{
for (; V_123 ; V_123 -- )
* V_122 ++ ^= * V_124 ++ ;
}
void F_109 ( T_2 * V_126 , const T_2 * V_127 , unsigned int V_123 )
{
T_1 * V_122 = ( T_1 * ) V_126 ;
T_1 * V_124 = ( T_1 * ) V_127 ;
for (; V_123 >= 4 ; V_123 -= 4 )
* V_122 ++ ^= * V_124 ++ ;
F_108 ( ( T_2 * ) V_122 , ( T_2 * ) V_124 , V_123 ) ;
}
static int T_4 F_110 ( void )
{
F_111 () ;
return 0 ;
}
static void T_5 F_112 ( void )
{
F_113 () ;
}
