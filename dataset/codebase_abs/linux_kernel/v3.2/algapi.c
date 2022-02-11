void F_1 ( const char * V_1 , T_1 type , T_1 V_2 )
{
struct V_3 * V_4 ;
V_4 = F_2 ( V_1 , type , V_2 ) ;
if ( V_4 ) {
if ( F_3 ( V_4 ) ) {
struct V_5 * V_6 = ( void * ) V_4 ;
F_4 ( & V_6 -> V_7 ) ;
}
F_5 ( V_4 ) ;
}
}
static inline int F_6 ( struct V_3 * V_4 )
{
static const char V_8 [] = L_1 ;
char * V_9 = V_4 -> V_10 ;
int V_11 ;
if ( * V_9 )
return 0 ;
V_11 = F_7 ( V_9 , V_4 -> V_12 , V_13 ) ;
if ( V_11 + sizeof( V_8 ) > V_13 )
return - V_14 ;
memcpy ( V_9 + V_11 , V_8 , sizeof( V_8 ) ) ;
return 0 ;
}
static int F_8 ( struct V_3 * V_4 )
{
if ( V_4 -> V_15 & ( V_4 -> V_15 + 1 ) )
return - V_16 ;
if ( V_4 -> V_17 > V_18 / 8 )
return - V_16 ;
if ( V_4 -> V_19 < 0 )
return - V_16 ;
return F_6 ( V_4 ) ;
}
static void F_9 ( struct V_3 * V_4 )
{
struct V_20 * V_21 = ( void * ) V_4 ;
struct V_22 * V_23 = V_21 -> V_23 ;
V_23 -> free ( V_21 ) ;
F_10 ( V_23 ) ;
}
static struct V_24 * F_11 ( struct V_3 * V_4 ,
struct V_24 * V_25 ,
struct V_24 * V_26 ,
struct V_24 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
if ( F_12 ( V_25 ) )
return NULL ;
V_29 = F_13 ( V_25 , struct V_28 , V_31 ) ;
V_30 = F_14 ( V_29 -> V_31 . V_32 , struct V_28 , V_31 ) ;
if ( V_29 -> V_4 && & V_30 -> V_31 != V_25 && ! V_30 -> V_4 )
V_30 -> V_4 = ( V_30 -> V_31 . V_32 == V_25 ) ? V_4 :
& F_14 ( V_30 -> V_31 . V_32 , struct V_28 ,
V_31 ) -> V_21 -> V_4 ;
F_15 ( & V_29 -> V_31 , V_27 ) ;
return & V_30 -> V_31 == V_25 ? V_26 : & V_30 -> V_21 -> V_4 . V_33 ;
}
static void F_16 ( struct V_28 * V_29 ,
struct V_24 * V_31 )
{
struct V_20 * V_21 = V_29 -> V_21 ;
struct V_22 * V_23 = V_21 -> V_23 ;
if ( F_17 ( & V_21 -> V_4 ) )
return;
V_21 -> V_4 . V_34 |= V_35 ;
if ( F_18 ( & V_21 -> V_31 ) )
return;
if ( ! V_23 || ! F_19 ( V_23 ) )
return;
F_20 ( V_36 , & V_21 -> V_4 ) ;
F_15 ( & V_21 -> V_4 . V_37 , V_31 ) ;
F_21 ( & V_21 -> V_31 ) ;
V_21 -> V_4 . V_38 = F_9 ;
F_22 ( ! F_12 ( & V_21 -> V_4 . V_33 ) ) ;
}
void F_23 ( struct V_3 * V_4 , struct V_24 * V_31 ,
struct V_3 * V_39 )
{
T_1 V_40 = ( V_39 ? : V_4 ) -> V_34 ;
struct V_28 * V_29 , * V_30 ;
F_24 ( V_27 ) ;
struct V_24 * V_41 ;
F_24 ( V_25 ) ;
F_24 ( V_26 ) ;
V_41 = & V_4 -> V_33 ;
F_25 (spawn, n, spawns, list) {
if ( ( V_29 -> V_4 -> V_34 ^ V_40 ) & V_29 -> V_2 )
continue;
F_15 ( & V_29 -> V_31 , & V_26 ) ;
}
V_41 = & V_26 ;
do {
while ( ! F_12 ( V_41 ) ) {
struct V_20 * V_21 ;
V_29 = F_13 ( V_41 , struct V_28 ,
V_31 ) ;
V_21 = V_29 -> V_21 ;
F_22 ( & V_21 -> V_4 == V_4 ) ;
F_15 ( & V_29 -> V_31 , & V_25 ) ;
if ( & V_21 -> V_4 == V_39 )
break;
V_29 -> V_4 = NULL ;
V_41 = & V_21 -> V_4 . V_33 ;
}
} while ( ( V_41 = F_11 ( V_4 , & V_25 , & V_26 ,
& V_27 ) ) );
F_25 (spawn, n, &secondary_spawns, list) {
if ( V_29 -> V_4 )
F_15 ( & V_29 -> V_31 , & V_29 -> V_4 -> V_33 ) ;
else
F_16 ( V_29 , V_31 ) ;
}
}
static struct V_5 * F_26 ( struct V_3 * V_4 )
{
struct V_3 * V_42 ;
struct V_5 * V_6 ;
int V_43 = - V_44 ;
if ( F_17 ( V_4 ) )
goto V_45;
F_27 ( & V_4 -> V_33 ) ;
V_4 -> V_34 &= ~ V_46 ;
V_43 = - V_47 ;
F_28 ( & V_4 -> V_48 , 1 ) ;
F_29 (q, &crypto_alg_list, cra_list) {
if ( V_42 == V_4 )
goto V_45;
if ( F_30 ( V_42 ) )
continue;
if ( F_3 ( V_42 ) ) {
if ( ! strcmp ( V_4 -> V_10 , V_42 -> V_10 ) )
goto V_45;
continue;
}
if ( ! strcmp ( V_42 -> V_10 , V_4 -> V_12 ) ||
! strcmp ( V_42 -> V_12 , V_4 -> V_10 ) )
goto V_45;
}
V_6 = F_31 ( V_4 -> V_12 ,
V_4 -> V_34 | V_46 , 0 ) ;
if ( F_32 ( V_6 ) )
goto V_49;
V_43 = - V_50 ;
V_6 -> V_51 = F_33 ( V_4 ) ;
if ( ! V_6 -> V_51 )
goto V_52;
F_28 ( & V_6 -> V_4 . V_48 , 1 ) ;
memcpy ( V_6 -> V_4 . V_10 , V_4 -> V_10 ,
V_13 ) ;
V_6 -> V_4 . V_19 = V_4 -> V_19 ;
F_34 ( & V_4 -> V_37 , & V_53 ) ;
F_34 ( & V_6 -> V_4 . V_37 , & V_53 ) ;
V_49:
return V_6 ;
V_52:
F_35 ( V_6 ) ;
V_45:
V_6 = F_36 ( V_43 ) ;
goto V_49;
}
void F_37 ( const char * V_1 , int V_45 )
{
struct V_5 * V_54 ;
struct V_3 * V_4 ;
struct V_3 * V_42 ;
F_24 ( V_31 ) ;
F_38 ( & V_55 ) ;
F_29 (q, &crypto_alg_list, cra_list) {
if ( F_30 ( V_42 ) || ! F_3 ( V_42 ) )
continue;
V_54 = (struct V_5 * ) V_42 ;
if ( ! strcmp ( V_42 -> V_10 , V_1 ) )
goto V_56;
}
F_39 ( V_57 L_2 , V_1 , V_45 ) ;
goto V_58;
V_56:
V_42 -> V_34 |= V_35 ;
V_4 = V_54 -> V_51 ;
if ( V_45 || F_12 ( & V_4 -> V_37 ) )
goto V_59;
V_4 -> V_34 |= V_46 ;
F_29 (q, &crypto_alg_list, cra_list) {
if ( V_42 == V_4 )
continue;
if ( F_30 ( V_42 ) )
continue;
if ( F_3 ( V_42 ) ) {
struct V_5 * V_6 = ( void * ) V_42 ;
if ( strcmp ( V_4 -> V_12 , V_42 -> V_12 ) &&
strcmp ( V_4 -> V_10 , V_42 -> V_12 ) )
continue;
if ( V_6 -> V_51 )
continue;
if ( ( V_42 -> V_34 ^ V_4 -> V_34 ) & V_6 -> V_2 )
continue;
if ( ! F_33 ( V_4 ) )
continue;
V_6 -> V_51 = V_4 ;
F_4 ( & V_6 -> V_7 ) ;
continue;
}
if ( strcmp ( V_4 -> V_12 , V_42 -> V_12 ) )
continue;
if ( strcmp ( V_4 -> V_10 , V_42 -> V_10 ) &&
V_42 -> V_19 > V_4 -> V_19 )
continue;
F_23 ( V_42 , & V_31 , V_4 ) ;
}
V_59:
F_4 ( & V_54 -> V_7 ) ;
V_58:
F_40 ( & V_55 ) ;
F_41 ( & V_31 ) ;
}
void F_41 ( struct V_24 * V_31 )
{
struct V_3 * V_4 ;
struct V_3 * V_30 ;
F_25 (alg, n, list, cra_list) {
F_42 ( & V_4 -> V_37 ) ;
F_43 ( V_4 ) ;
}
}
static void F_44 ( struct V_5 * V_6 )
{
int V_45 ;
V_45 = F_45 ( V_60 , V_6 -> V_51 ) ;
if ( V_45 != V_61 ) {
if ( F_46 ( V_45 != V_62 ) )
goto V_49;
F_37 ( V_6 -> V_4 . V_10 , 0 ) ;
}
V_45 = F_47 ( & V_6 -> V_7 ) ;
F_46 ( V_45 ) ;
V_49:
F_48 ( & V_6 -> V_4 ) ;
}
int F_49 ( struct V_3 * V_4 )
{
struct V_5 * V_6 ;
int V_45 ;
V_45 = F_8 ( V_4 ) ;
if ( V_45 )
return V_45 ;
F_38 ( & V_55 ) ;
V_6 = F_26 ( V_4 ) ;
F_40 ( & V_55 ) ;
if ( F_32 ( V_6 ) )
return F_50 ( V_6 ) ;
F_44 ( V_6 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 , struct V_24 * V_31 )
{
if ( F_52 ( F_12 ( & V_4 -> V_37 ) ) )
return - V_50 ;
V_4 -> V_34 |= V_35 ;
F_20 ( V_36 , V_4 ) ;
F_42 ( & V_4 -> V_37 ) ;
F_23 ( V_4 , V_31 , NULL ) ;
return 0 ;
}
int F_53 ( struct V_3 * V_4 )
{
int V_43 ;
F_24 ( V_31 ) ;
F_38 ( & V_55 ) ;
V_43 = F_51 ( V_4 , & V_31 ) ;
F_40 ( & V_55 ) ;
if ( V_43 )
return V_43 ;
F_22 ( F_54 ( & V_4 -> V_48 ) != 1 ) ;
if ( V_4 -> V_38 )
V_4 -> V_38 ( V_4 ) ;
F_41 ( & V_31 ) ;
return 0 ;
}
int F_55 ( struct V_22 * V_23 )
{
struct V_22 * V_42 ;
int V_45 = - V_47 ;
F_38 ( & V_55 ) ;
F_29 (q, &crypto_template_list, list) {
if ( V_42 == V_23 )
goto V_49;
}
F_34 ( & V_23 -> V_31 , & V_63 ) ;
F_20 ( V_64 , V_23 ) ;
V_45 = 0 ;
V_49:
F_40 ( & V_55 ) ;
return V_45 ;
}
void F_56 ( struct V_22 * V_23 )
{
struct V_20 * V_21 ;
struct V_65 * V_66 , * V_30 ;
struct V_67 * V_31 ;
F_24 ( V_68 ) ;
F_38 ( & V_55 ) ;
F_22 ( F_12 ( & V_23 -> V_31 ) ) ;
F_42 ( & V_23 -> V_31 ) ;
V_31 = & V_23 -> V_69 ;
F_57 (inst, p, list, list) {
int V_45 = F_51 ( & V_21 -> V_4 , & V_68 ) ;
F_22 ( V_45 ) ;
}
F_20 ( V_70 , V_23 ) ;
F_40 ( & V_55 ) ;
F_58 (inst, p, n, list, list) {
F_22 ( F_54 ( & V_21 -> V_4 . V_48 ) != 1 ) ;
V_23 -> free ( V_21 ) ;
}
F_41 ( & V_68 ) ;
}
static struct V_22 * F_59 ( const char * V_1 )
{
struct V_22 * V_42 , * V_23 = NULL ;
F_60 ( & V_55 ) ;
F_29 (q, &crypto_template_list, list) {
if ( strcmp ( V_42 -> V_1 , V_1 ) )
continue;
if ( F_52 ( ! F_19 ( V_42 ) ) )
continue;
V_23 = V_42 ;
break;
}
F_61 ( & V_55 ) ;
return V_23 ;
}
struct V_22 * F_62 ( const char * V_1 )
{
return F_63 ( F_59 ( V_1 ) , V_1 ) ;
}
int F_64 ( struct V_22 * V_23 ,
struct V_20 * V_21 )
{
struct V_5 * V_6 ;
int V_45 ;
V_45 = F_8 ( & V_21 -> V_4 ) ;
if ( V_45 )
goto V_45;
V_21 -> V_4 . V_71 = V_23 -> V_72 ;
V_21 -> V_4 . V_34 |= V_73 ;
F_38 ( & V_55 ) ;
V_6 = F_26 ( & V_21 -> V_4 ) ;
if ( F_32 ( V_6 ) )
goto V_58;
F_65 ( & V_21 -> V_31 , & V_23 -> V_69 ) ;
V_21 -> V_23 = V_23 ;
V_58:
F_40 ( & V_55 ) ;
V_45 = F_50 ( V_6 ) ;
if ( F_32 ( V_6 ) )
goto V_45;
F_44 ( V_6 ) ;
V_45 = 0 ;
V_45:
return V_45 ;
}
int F_66 ( struct V_28 * V_29 , struct V_3 * V_4 ,
struct V_20 * V_21 , T_1 V_2 )
{
int V_45 = - V_44 ;
V_29 -> V_21 = V_21 ;
V_29 -> V_2 = V_2 ;
F_38 ( & V_55 ) ;
if ( ! F_30 ( V_4 ) ) {
F_34 ( & V_29 -> V_31 , & V_4 -> V_33 ) ;
V_29 -> V_4 = V_4 ;
V_45 = 0 ;
}
F_40 ( & V_55 ) ;
return V_45 ;
}
int F_67 ( struct V_28 * V_29 , struct V_3 * V_4 ,
struct V_20 * V_21 ,
const struct V_74 * V_75 )
{
int V_45 = - V_16 ;
if ( ( V_4 -> V_34 ^ V_75 -> type ) & V_75 -> V_76 )
goto V_49;
V_29 -> V_75 = V_75 ;
V_45 = F_66 ( V_29 , V_4 , V_21 , V_75 -> V_76 ) ;
V_49:
return V_45 ;
}
void F_68 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_4 )
return;
F_38 ( & V_55 ) ;
F_69 ( & V_29 -> V_31 ) ;
F_40 ( & V_55 ) ;
}
static struct V_3 * F_70 ( struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_3 * V_77 ;
F_60 ( & V_55 ) ;
V_4 = V_29 -> V_4 ;
V_77 = V_4 ;
if ( V_77 )
V_77 = F_33 ( V_77 ) ;
F_61 ( & V_55 ) ;
if ( ! V_77 ) {
if ( V_4 )
F_71 ( V_4 ) ;
return F_36 ( - V_44 ) ;
}
return V_4 ;
}
struct V_78 * F_72 ( struct V_28 * V_29 , T_1 type ,
T_1 V_2 )
{
struct V_3 * V_4 ;
struct V_78 * V_79 ;
V_4 = F_70 ( V_29 ) ;
if ( F_32 ( V_4 ) )
return F_73 ( V_4 ) ;
V_79 = F_36 ( - V_16 ) ;
if ( F_52 ( ( V_4 -> V_34 ^ type ) & V_2 ) )
goto V_80;
V_79 = F_74 ( V_4 , type , V_2 ) ;
if ( F_32 ( V_79 ) )
goto V_80;
return V_79 ;
V_80:
F_5 ( V_4 ) ;
return V_79 ;
}
void * F_75 ( struct V_28 * V_29 )
{
struct V_3 * V_4 ;
struct V_78 * V_79 ;
V_4 = F_70 ( V_29 ) ;
if ( F_32 ( V_4 ) )
return F_73 ( V_4 ) ;
V_79 = F_76 ( V_4 , V_29 -> V_75 ) ;
if ( F_32 ( V_79 ) )
goto V_80;
return V_79 ;
V_80:
F_5 ( V_4 ) ;
return V_79 ;
}
int F_77 ( struct V_81 * V_82 )
{
return F_78 ( & V_83 , V_82 ) ;
}
int F_79 ( struct V_81 * V_82 )
{
return F_80 ( & V_83 , V_82 ) ;
}
struct V_84 * F_81 ( struct V_85 * * V_86 )
{
struct V_85 * V_87 = V_86 [ 0 ] ;
struct V_84 * V_88 ;
if ( ! V_87 )
return F_36 ( - V_50 ) ;
if ( F_82 ( V_87 ) < sizeof( * V_88 ) )
return F_36 ( - V_16 ) ;
if ( V_87 -> V_89 != V_90 )
return F_36 ( - V_16 ) ;
V_88 = F_83 ( V_87 ) ;
return V_88 ;
}
int F_84 ( struct V_85 * * V_86 , T_1 type )
{
struct V_84 * V_88 ;
V_88 = F_81 ( V_86 ) ;
if ( F_32 ( V_88 ) )
return F_50 ( V_88 ) ;
if ( ( V_88 -> type ^ type ) & V_88 -> V_2 )
return - V_16 ;
return 0 ;
}
const char * F_85 ( struct V_85 * V_87 )
{
struct V_91 * V_92 ;
if ( ! V_87 )
return F_36 ( - V_50 ) ;
if ( F_82 ( V_87 ) < sizeof( * V_92 ) )
return F_36 ( - V_16 ) ;
if ( V_87 -> V_89 != V_93 )
return F_36 ( - V_16 ) ;
V_92 = F_83 ( V_87 ) ;
V_92 -> V_1 [ V_13 - 1 ] = 0 ;
return V_92 -> V_1 ;
}
struct V_3 * F_86 ( struct V_85 * V_87 ,
const struct V_74 * V_75 ,
T_1 type , T_1 V_2 )
{
const char * V_1 ;
int V_45 ;
V_1 = F_85 ( V_87 ) ;
V_45 = F_50 ( V_1 ) ;
if ( F_32 ( V_1 ) )
return F_36 ( V_45 ) ;
return F_87 ( V_1 , V_75 , type , V_2 ) ;
}
int F_88 ( struct V_85 * V_87 , T_1 * V_94 )
{
struct F_88 * V_95 ;
if ( ! V_87 )
return - V_50 ;
if ( F_82 ( V_87 ) < sizeof( * V_95 ) )
return - V_16 ;
if ( V_87 -> V_89 != V_96 )
return - V_16 ;
V_95 = F_83 ( V_87 ) ;
* V_94 = V_95 -> V_94 ;
return 0 ;
}
void * F_89 ( const char * V_1 , struct V_3 * V_4 ,
unsigned int V_97 )
{
struct V_20 * V_21 ;
char * V_66 ;
int V_45 ;
V_66 = F_90 ( V_97 + sizeof( * V_21 ) + sizeof( struct V_28 ) ,
V_98 ) ;
if ( ! V_66 )
return F_36 ( - V_99 ) ;
V_21 = ( void * ) ( V_66 + V_97 ) ;
V_45 = - V_14 ;
if ( snprintf ( V_21 -> V_4 . V_12 , V_13 , L_3 , V_1 ,
V_4 -> V_12 ) >= V_13 )
goto V_100;
if ( snprintf ( V_21 -> V_4 . V_10 , V_13 , L_3 ,
V_1 , V_4 -> V_10 ) >= V_13 )
goto V_100;
return V_66 ;
V_100:
F_35 ( V_66 ) ;
return F_36 ( V_45 ) ;
}
struct V_20 * F_91 ( const char * V_1 ,
struct V_3 * V_4 )
{
struct V_20 * V_21 ;
struct V_28 * V_29 ;
int V_45 ;
V_21 = F_89 ( V_1 , V_4 , 0 ) ;
if ( F_32 ( V_21 ) )
goto V_49;
V_29 = F_92 ( V_21 ) ;
V_45 = F_66 ( V_29 , V_4 , V_21 ,
V_101 | V_102 ) ;
if ( V_45 )
goto V_100;
return V_21 ;
V_100:
F_35 ( V_21 ) ;
V_21 = F_36 ( V_45 ) ;
V_49:
return V_21 ;
}
void F_93 ( struct V_103 * V_104 , unsigned int V_105 )
{
F_27 ( & V_104 -> V_31 ) ;
V_104 -> V_106 = & V_104 -> V_31 ;
V_104 -> V_107 = 0 ;
V_104 -> V_105 = V_105 ;
}
int F_94 ( struct V_103 * V_104 ,
struct V_108 * V_109 )
{
int V_45 = - V_110 ;
if ( F_52 ( V_104 -> V_107 >= V_104 -> V_105 ) ) {
V_45 = - V_111 ;
if ( ! ( V_109 -> V_112 & V_113 ) )
goto V_49;
if ( V_104 -> V_106 == & V_104 -> V_31 )
V_104 -> V_106 = & V_109 -> V_31 ;
}
V_104 -> V_107 ++ ;
F_95 ( & V_109 -> V_31 , & V_104 -> V_31 ) ;
V_49:
return V_45 ;
}
void * F_96 ( struct V_103 * V_104 , unsigned int V_114 )
{
struct V_24 * V_109 ;
if ( F_52 ( ! V_104 -> V_107 ) )
return NULL ;
V_104 -> V_107 -- ;
if ( V_104 -> V_106 != & V_104 -> V_31 )
V_104 -> V_106 = V_104 -> V_106 -> V_32 ;
V_109 = V_104 -> V_31 . V_32 ;
F_69 ( V_109 ) ;
return ( char * ) F_14 ( V_109 , struct V_108 , V_31 ) -
V_114 ;
}
struct V_108 * F_97 ( struct V_103 * V_104 )
{
return F_96 ( V_104 , 0 ) ;
}
int F_98 ( struct V_103 * V_104 , struct V_78 * V_79 )
{
struct V_108 * V_115 ;
F_29 (req, &queue->list, list) {
if ( V_115 -> V_79 == V_79 )
return 1 ;
}
return 0 ;
}
static inline void F_99 ( T_2 * V_116 , unsigned int V_117 )
{
T_2 * V_118 = ( V_116 + V_117 ) ;
T_2 V_119 ;
for (; V_117 ; V_117 -- ) {
V_119 = * -- V_118 + 1 ;
* V_118 = V_119 ;
if ( V_119 )
break;
}
}
void F_100 ( T_2 * V_116 , unsigned int V_117 )
{
T_3 * V_118 = ( T_3 * ) ( V_116 + V_117 ) ;
T_1 V_119 ;
for (; V_117 >= 4 ; V_117 -= 4 ) {
V_119 = F_101 ( * -- V_118 ) + 1 ;
* V_118 = F_102 ( V_119 ) ;
if ( V_119 )
return;
}
F_99 ( V_116 , V_117 ) ;
}
static inline void F_103 ( T_2 * V_116 , const T_2 * V_118 , unsigned int V_117 )
{
for (; V_117 ; V_117 -- )
* V_116 ++ ^= * V_118 ++ ;
}
void F_104 ( T_2 * V_120 , const T_2 * V_121 , unsigned int V_117 )
{
T_1 * V_116 = ( T_1 * ) V_120 ;
T_1 * V_118 = ( T_1 * ) V_121 ;
for (; V_117 >= 4 ; V_117 -= 4 )
* V_116 ++ ^= * V_118 ++ ;
F_103 ( ( T_2 * ) V_116 , ( T_2 * ) V_118 , V_117 ) ;
}
static int T_4 F_105 ( void )
{
F_106 () ;
return 0 ;
}
static void T_5 F_107 ( void )
{
F_108 () ;
}
