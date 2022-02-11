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
if ( V_12 && V_11 && ! F_4 ( V_11 ) )
F_5 ( L_2 ,
F_6 ( V_11 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
F_3 ( V_2 -> V_13 ) ;
if ( V_2 -> V_14 & ( V_2 -> V_14 + 1 ) )
return - V_15 ;
if ( V_2 -> V_16 > V_17 / 8 )
return - V_15 ;
if ( V_2 -> V_18 < 0 )
return - V_15 ;
F_8 ( & V_2 -> V_19 , 1 ) ;
return F_1 ( V_2 ) ;
}
static void F_9 ( struct V_20 * V_21 )
{
if ( ! V_21 -> V_2 . V_22 -> free ) {
V_21 -> V_23 -> free ( V_21 ) ;
return;
}
V_21 -> V_2 . V_22 -> free ( V_21 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = ( void * ) V_2 ;
struct V_24 * V_23 = V_21 -> V_23 ;
F_9 ( V_21 ) ;
F_11 ( V_23 ) ;
}
static struct V_25 * F_12 ( struct V_1 * V_2 ,
struct V_25 * V_26 ,
struct V_25 * V_27 ,
struct V_25 * V_28 )
{
struct V_29 * V_30 , * V_31 ;
if ( F_13 ( V_26 ) )
return NULL ;
V_30 = F_14 ( V_26 , struct V_29 , V_32 ) ;
V_31 = F_15 ( V_30 -> V_32 . V_33 , struct V_29 , V_32 ) ;
if ( V_30 -> V_2 && & V_31 -> V_32 != V_26 && ! V_31 -> V_2 )
V_31 -> V_2 = ( V_31 -> V_32 . V_33 == V_26 ) ? V_2 :
& F_15 ( V_31 -> V_32 . V_33 , struct V_29 ,
V_32 ) -> V_21 -> V_2 ;
F_16 ( & V_30 -> V_32 , V_28 ) ;
return & V_31 -> V_32 == V_26 ? V_27 : & V_31 -> V_21 -> V_2 . V_34 ;
}
static void F_17 ( struct V_20 * V_21 ,
struct V_25 * V_32 )
{
struct V_24 * V_23 = V_21 -> V_23 ;
if ( F_18 ( & V_21 -> V_2 ) )
return;
V_21 -> V_2 . V_35 |= V_36 ;
if ( F_19 ( & V_21 -> V_32 ) )
return;
if ( ! V_23 || ! F_20 ( V_23 ) )
return;
F_21 ( V_37 , & V_21 -> V_2 ) ;
F_16 ( & V_21 -> V_2 . V_38 , V_32 ) ;
F_22 ( & V_21 -> V_32 ) ;
V_21 -> V_2 . V_39 = F_10 ;
F_23 ( ! F_13 ( & V_21 -> V_2 . V_34 ) ) ;
}
void F_24 ( struct V_1 * V_2 , struct V_25 * V_32 ,
struct V_1 * V_40 )
{
T_1 V_41 = ( V_40 ? : V_2 ) -> V_35 ;
struct V_29 * V_30 , * V_31 ;
F_25 ( V_28 ) ;
struct V_25 * V_42 ;
F_25 ( V_26 ) ;
F_25 ( V_27 ) ;
V_42 = & V_2 -> V_34 ;
F_26 (spawn, n, spawns, list) {
if ( ( V_30 -> V_2 -> V_35 ^ V_41 ) & V_30 -> V_43 )
continue;
F_16 ( & V_30 -> V_32 , & V_27 ) ;
}
V_42 = & V_27 ;
do {
while ( ! F_13 ( V_42 ) ) {
struct V_20 * V_21 ;
V_30 = F_14 ( V_42 , struct V_29 ,
V_32 ) ;
V_21 = V_30 -> V_21 ;
F_23 ( & V_21 -> V_2 == V_2 ) ;
F_16 ( & V_30 -> V_32 , & V_26 ) ;
if ( & V_21 -> V_2 == V_40 )
break;
V_30 -> V_2 = NULL ;
V_42 = & V_21 -> V_2 . V_34 ;
}
} while ( ( V_42 = F_12 ( V_2 , & V_26 , & V_27 ,
& V_28 ) ) );
F_26 (spawn, n, &secondary_spawns, list) {
if ( V_30 -> V_2 )
F_16 ( & V_30 -> V_32 , & V_30 -> V_2 -> V_34 ) ;
else
F_17 ( V_30 -> V_21 , V_32 ) ;
}
}
static struct V_44 * F_27 ( struct V_1 * V_2 )
{
struct V_1 * V_45 ;
struct V_44 * V_46 ;
int V_47 = - V_48 ;
if ( F_18 ( V_2 ) )
goto V_49;
F_28 ( & V_2 -> V_34 ) ;
V_2 -> V_35 &= ~ V_50 ;
V_47 = - V_51 ;
F_29 (q, &crypto_alg_list, cra_list) {
if ( V_45 == V_2 )
goto V_49;
if ( F_30 ( V_45 ) )
continue;
if ( F_31 ( V_45 ) ) {
if ( ! strcmp ( V_2 -> V_5 , V_45 -> V_5 ) )
goto V_49;
continue;
}
if ( ! strcmp ( V_45 -> V_5 , V_2 -> V_7 ) ||
! strcmp ( V_45 -> V_7 , V_2 -> V_5 ) )
goto V_49;
}
V_46 = F_32 ( V_2 -> V_7 ,
V_2 -> V_35 | V_50 , 0 ) ;
if ( F_33 ( V_46 ) )
goto V_52;
V_47 = - V_53 ;
V_46 -> V_54 = F_34 ( V_2 ) ;
if ( ! V_46 -> V_54 )
goto V_55;
F_8 ( & V_46 -> V_2 . V_19 , 1 ) ;
memcpy ( V_46 -> V_2 . V_5 , V_2 -> V_5 ,
V_8 ) ;
V_46 -> V_2 . V_18 = V_2 -> V_18 ;
F_35 ( & V_2 -> V_38 , & V_56 ) ;
F_35 ( & V_46 -> V_2 . V_38 , & V_56 ) ;
V_52:
return V_46 ;
V_55:
F_36 ( V_46 ) ;
V_49:
V_46 = F_37 ( V_47 ) ;
goto V_52;
}
void F_38 ( const char * V_57 , int V_49 )
{
struct V_44 * V_58 ;
struct V_1 * V_2 ;
struct V_1 * V_45 ;
F_25 ( V_32 ) ;
F_39 ( & V_59 ) ;
F_29 (q, &crypto_alg_list, cra_list) {
if ( F_30 ( V_45 ) || ! F_31 ( V_45 ) )
continue;
V_58 = (struct V_44 * ) V_45 ;
if ( ! strcmp ( V_45 -> V_5 , V_57 ) )
goto V_60;
}
F_40 ( V_61 L_3 , V_57 , V_49 ) ;
goto V_62;
V_60:
V_45 -> V_35 |= V_36 ;
V_2 = V_58 -> V_54 ;
if ( V_49 || F_13 ( & V_2 -> V_38 ) )
goto V_63;
V_2 -> V_35 |= V_50 ;
F_29 (q, &crypto_alg_list, cra_list) {
if ( V_45 == V_2 )
continue;
if ( F_30 ( V_45 ) )
continue;
if ( F_31 ( V_45 ) ) {
struct V_44 * V_46 = ( void * ) V_45 ;
if ( strcmp ( V_2 -> V_7 , V_45 -> V_7 ) &&
strcmp ( V_2 -> V_5 , V_45 -> V_7 ) )
continue;
if ( V_46 -> V_54 )
continue;
if ( ( V_45 -> V_35 ^ V_2 -> V_35 ) & V_46 -> V_43 )
continue;
if ( ! F_34 ( V_2 ) )
continue;
V_46 -> V_54 = V_2 ;
continue;
}
if ( strcmp ( V_2 -> V_7 , V_45 -> V_7 ) )
continue;
if ( strcmp ( V_2 -> V_5 , V_45 -> V_5 ) &&
V_45 -> V_18 > V_2 -> V_18 )
continue;
F_24 ( V_45 , & V_32 , V_2 ) ;
}
V_63:
F_41 ( & V_58 -> V_64 ) ;
V_62:
F_42 ( & V_59 ) ;
F_43 ( & V_32 ) ;
}
void F_43 ( struct V_25 * V_32 )
{
struct V_1 * V_2 ;
struct V_1 * V_31 ;
F_26 (alg, n, list, cra_list) {
F_44 ( & V_2 -> V_38 ) ;
F_45 ( V_2 ) ;
}
}
static void F_46 ( struct V_44 * V_46 )
{
int V_49 ;
V_49 = F_47 ( V_65 , V_46 -> V_54 ) ;
if ( V_49 != V_66 ) {
if ( F_48 ( V_49 != V_67 ) )
goto V_52;
F_38 ( V_46 -> V_2 . V_5 , 0 ) ;
}
V_49 = F_49 ( & V_46 -> V_64 ) ;
F_48 ( V_49 ) ;
V_52:
F_50 ( & V_46 -> V_2 ) ;
}
int F_51 ( struct V_1 * V_2 )
{
struct V_44 * V_46 ;
int V_49 ;
V_49 = F_7 ( V_2 ) ;
if ( V_49 )
return V_49 ;
F_39 ( & V_59 ) ;
V_46 = F_27 ( V_2 ) ;
F_42 ( & V_59 ) ;
if ( F_33 ( V_46 ) )
return F_52 ( V_46 ) ;
F_46 ( V_46 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 , struct V_25 * V_32 )
{
if ( F_54 ( F_13 ( & V_2 -> V_38 ) ) )
return - V_53 ;
V_2 -> V_35 |= V_36 ;
F_21 ( V_37 , V_2 ) ;
F_44 ( & V_2 -> V_38 ) ;
F_24 ( V_2 , V_32 , NULL ) ;
return 0 ;
}
int F_55 ( struct V_1 * V_2 )
{
int V_47 ;
F_25 ( V_32 ) ;
F_39 ( & V_59 ) ;
V_47 = F_53 ( V_2 , & V_32 ) ;
F_42 ( & V_59 ) ;
if ( V_47 )
return V_47 ;
F_23 ( F_56 ( & V_2 -> V_19 ) != 1 ) ;
if ( V_2 -> V_39 )
V_2 -> V_39 ( V_2 ) ;
F_43 ( & V_32 ) ;
return 0 ;
}
int F_57 ( struct V_1 * V_68 , int V_69 )
{
int V_70 , V_47 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
V_47 = F_51 ( & V_68 [ V_70 ] ) ;
if ( V_47 )
goto V_49;
}
return 0 ;
V_49:
for ( -- V_70 ; V_70 >= 0 ; -- V_70 )
F_55 ( & V_68 [ V_70 ] ) ;
return V_47 ;
}
int F_58 ( struct V_1 * V_68 , int V_69 )
{
int V_70 , V_47 ;
for ( V_70 = 0 ; V_70 < V_69 ; V_70 ++ ) {
V_47 = F_55 ( & V_68 [ V_70 ] ) ;
if ( V_47 )
F_59 ( L_4 ,
V_68 [ V_70 ] . V_5 , V_68 [ V_70 ] . V_7 , V_47 ) ;
}
return 0 ;
}
int F_60 ( struct V_24 * V_23 )
{
struct V_24 * V_45 ;
int V_49 = - V_51 ;
F_39 ( & V_59 ) ;
F_3 ( V_23 -> V_10 ) ;
F_29 (q, &crypto_template_list, list) {
if ( V_45 == V_23 )
goto V_52;
}
F_35 ( & V_23 -> V_32 , & V_71 ) ;
F_21 ( V_72 , V_23 ) ;
V_49 = 0 ;
V_52:
F_42 ( & V_59 ) ;
return V_49 ;
}
void F_61 ( struct V_24 * V_23 )
{
struct V_20 * V_21 ;
struct V_73 * V_31 ;
struct V_74 * V_32 ;
F_25 ( V_75 ) ;
F_39 ( & V_59 ) ;
F_23 ( F_13 ( & V_23 -> V_32 ) ) ;
F_44 ( & V_23 -> V_32 ) ;
V_32 = & V_23 -> V_76 ;
F_62 (inst, list, list) {
int V_49 = F_53 ( & V_21 -> V_2 , & V_75 ) ;
F_23 ( V_49 ) ;
}
F_21 ( V_77 , V_23 ) ;
F_42 ( & V_59 ) ;
F_63 (inst, n, list, list) {
F_23 ( F_56 ( & V_21 -> V_2 . V_19 ) != 1 ) ;
F_9 ( V_21 ) ;
}
F_43 ( & V_75 ) ;
}
static struct V_24 * F_64 ( const char * V_57 )
{
struct V_24 * V_45 , * V_23 = NULL ;
F_65 ( & V_59 ) ;
F_29 (q, &crypto_template_list, list) {
if ( strcmp ( V_45 -> V_57 , V_57 ) )
continue;
if ( F_54 ( ! F_20 ( V_45 ) ) )
continue;
V_23 = V_45 ;
break;
}
F_66 ( & V_59 ) ;
return V_23 ;
}
struct V_24 * F_67 ( const char * V_57 )
{
return F_68 ( F_64 ( V_57 ) ,
L_5 , V_57 ) ;
}
int F_69 ( struct V_24 * V_23 ,
struct V_20 * V_21 )
{
struct V_44 * V_46 ;
int V_49 ;
V_49 = F_7 ( & V_21 -> V_2 ) ;
if ( V_49 )
return V_49 ;
V_21 -> V_2 . V_13 = V_23 -> V_10 ;
V_21 -> V_2 . V_35 |= V_78 ;
if ( F_54 ( ! F_34 ( & V_21 -> V_2 ) ) )
return - V_48 ;
F_39 ( & V_59 ) ;
V_46 = F_27 ( & V_21 -> V_2 ) ;
if ( F_33 ( V_46 ) )
goto V_62;
F_70 ( & V_21 -> V_32 , & V_23 -> V_76 ) ;
V_21 -> V_23 = V_23 ;
V_62:
F_42 ( & V_59 ) ;
V_49 = F_52 ( V_46 ) ;
if ( F_33 ( V_46 ) )
goto V_49;
F_46 ( V_46 ) ;
if ( ! ( V_21 -> V_2 . V_35 & V_50 ) )
F_71 ( V_21 ) ;
V_49 = 0 ;
V_49:
F_72 ( & V_21 -> V_2 ) ;
return V_49 ;
}
int F_71 ( struct V_20 * V_21 )
{
F_25 ( V_32 ) ;
F_39 ( & V_59 ) ;
F_24 ( & V_21 -> V_2 , & V_32 , NULL ) ;
F_17 ( V_21 , & V_32 ) ;
F_42 ( & V_59 ) ;
F_43 ( & V_32 ) ;
return 0 ;
}
int F_73 ( struct V_29 * V_30 , struct V_1 * V_2 ,
struct V_20 * V_21 , T_1 V_43 )
{
int V_49 = - V_48 ;
V_30 -> V_21 = V_21 ;
V_30 -> V_43 = V_43 ;
F_39 ( & V_59 ) ;
if ( ! F_30 ( V_2 ) ) {
F_35 ( & V_30 -> V_32 , & V_2 -> V_34 ) ;
V_30 -> V_2 = V_2 ;
V_49 = 0 ;
}
F_42 ( & V_59 ) ;
return V_49 ;
}
int F_74 ( struct V_29 * V_30 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
const struct V_79 * V_80 )
{
int V_49 = - V_15 ;
if ( ( V_2 -> V_35 ^ V_80 -> type ) & V_80 -> V_81 )
goto V_52;
V_30 -> V_80 = V_80 ;
V_49 = F_73 ( V_30 , V_2 , V_21 , V_80 -> V_81 ) ;
V_52:
return V_49 ;
}
int F_75 ( struct V_29 * V_30 , const char * V_57 ,
T_1 type , T_1 V_43 )
{
struct V_1 * V_2 ;
int V_49 ;
V_2 = F_76 ( V_57 , V_30 -> V_80 , type , V_43 ) ;
if ( F_33 ( V_2 ) )
return F_52 ( V_2 ) ;
V_49 = F_73 ( V_30 , V_2 , V_30 -> V_21 , V_43 ) ;
F_72 ( V_2 ) ;
return V_49 ;
}
void F_77 ( struct V_29 * V_30 )
{
if ( ! V_30 -> V_2 )
return;
F_39 ( & V_59 ) ;
F_78 ( & V_30 -> V_32 ) ;
F_42 ( & V_59 ) ;
}
static struct V_1 * F_79 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_1 * V_82 ;
F_65 ( & V_59 ) ;
V_2 = V_30 -> V_2 ;
V_82 = V_2 ;
if ( V_82 )
V_82 = F_34 ( V_82 ) ;
F_66 ( & V_59 ) ;
if ( ! V_82 ) {
if ( V_2 )
F_80 ( V_2 ) ;
return F_37 ( - V_48 ) ;
}
return V_2 ;
}
struct V_83 * F_81 ( struct V_29 * V_30 , T_1 type ,
T_1 V_43 )
{
struct V_1 * V_2 ;
struct V_83 * V_84 ;
V_2 = F_79 ( V_30 ) ;
if ( F_33 ( V_2 ) )
return F_82 ( V_2 ) ;
V_84 = F_37 ( - V_15 ) ;
if ( F_54 ( ( V_2 -> V_35 ^ type ) & V_43 ) )
goto V_85;
V_84 = F_83 ( V_2 , type , V_43 ) ;
if ( F_33 ( V_84 ) )
goto V_85;
return V_84 ;
V_85:
F_72 ( V_2 ) ;
return V_84 ;
}
void * F_84 ( struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_83 * V_84 ;
V_2 = F_79 ( V_30 ) ;
if ( F_33 ( V_2 ) )
return F_82 ( V_2 ) ;
V_84 = F_85 ( V_2 , V_30 -> V_80 ) ;
if ( F_33 ( V_84 ) )
goto V_85;
return V_84 ;
V_85:
F_72 ( V_2 ) ;
return V_84 ;
}
int F_86 ( struct V_86 * V_87 )
{
return F_87 ( & V_88 , V_87 ) ;
}
int F_88 ( struct V_86 * V_87 )
{
return F_89 ( & V_88 , V_87 ) ;
}
struct V_89 * F_90 ( struct V_90 * * V_91 )
{
struct V_90 * V_92 = V_91 [ 0 ] ;
struct V_89 * V_93 ;
if ( ! V_92 )
return F_37 ( - V_53 ) ;
if ( F_91 ( V_92 ) < sizeof( * V_93 ) )
return F_37 ( - V_15 ) ;
if ( V_92 -> V_94 != V_95 )
return F_37 ( - V_15 ) ;
V_93 = F_92 ( V_92 ) ;
return V_93 ;
}
int F_93 ( struct V_90 * * V_91 , T_1 type )
{
struct V_89 * V_93 ;
V_93 = F_90 ( V_91 ) ;
if ( F_33 ( V_93 ) )
return F_52 ( V_93 ) ;
if ( ( V_93 -> type ^ type ) & V_93 -> V_43 )
return - V_15 ;
return 0 ;
}
const char * F_94 ( struct V_90 * V_92 )
{
struct V_96 * V_97 ;
if ( ! V_92 )
return F_37 ( - V_53 ) ;
if ( F_91 ( V_92 ) < sizeof( * V_97 ) )
return F_37 ( - V_15 ) ;
if ( V_92 -> V_94 != V_98 )
return F_37 ( - V_15 ) ;
V_97 = F_92 ( V_92 ) ;
V_97 -> V_57 [ V_8 - 1 ] = 0 ;
return V_97 -> V_57 ;
}
struct V_1 * F_95 ( struct V_90 * V_92 ,
const struct V_79 * V_80 ,
T_1 type , T_1 V_43 )
{
const char * V_57 ;
V_57 = F_94 ( V_92 ) ;
if ( F_33 ( V_57 ) )
return F_82 ( V_57 ) ;
return F_76 ( V_57 , V_80 , type , V_43 ) ;
}
int F_96 ( struct V_90 * V_92 , T_1 * V_99 )
{
struct F_96 * V_100 ;
if ( ! V_92 )
return - V_53 ;
if ( F_91 ( V_92 ) < sizeof( * V_100 ) )
return - V_15 ;
if ( V_92 -> V_94 != V_101 )
return - V_15 ;
V_100 = F_92 ( V_92 ) ;
* V_99 = V_100 -> V_99 ;
return 0 ;
}
void * F_97 ( const char * V_57 , struct V_1 * V_2 ,
unsigned int V_102 )
{
struct V_20 * V_21 ;
char * V_103 ;
int V_49 ;
V_103 = F_98 ( V_102 + sizeof( * V_21 ) + sizeof( struct V_29 ) ,
V_104 ) ;
if ( ! V_103 )
return F_37 ( - V_105 ) ;
V_21 = ( void * ) ( V_103 + V_102 ) ;
V_49 = - V_9 ;
if ( snprintf ( V_21 -> V_2 . V_7 , V_8 , L_6 , V_57 ,
V_2 -> V_7 ) >= V_8 )
goto V_106;
if ( snprintf ( V_21 -> V_2 . V_5 , V_8 , L_6 ,
V_57 , V_2 -> V_5 ) >= V_8 )
goto V_106;
return V_103 ;
V_106:
F_36 ( V_103 ) ;
return F_37 ( V_49 ) ;
}
struct V_20 * F_99 ( const char * V_57 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_29 * V_30 ;
int V_49 ;
V_21 = F_97 ( V_57 , V_2 , 0 ) ;
if ( F_33 ( V_21 ) )
goto V_52;
V_30 = F_100 ( V_21 ) ;
V_49 = F_73 ( V_30 , V_2 , V_21 ,
V_107 | V_108 ) ;
if ( V_49 )
goto V_106;
return V_21 ;
V_106:
F_36 ( V_21 ) ;
V_21 = F_37 ( V_49 ) ;
V_52:
return V_21 ;
}
void F_101 ( struct V_109 * V_110 , unsigned int V_111 )
{
F_28 ( & V_110 -> V_32 ) ;
V_110 -> V_112 = & V_110 -> V_32 ;
V_110 -> V_113 = 0 ;
V_110 -> V_111 = V_111 ;
}
int F_102 ( struct V_109 * V_110 ,
struct V_114 * V_115 )
{
int V_49 = - V_116 ;
if ( F_54 ( V_110 -> V_113 >= V_110 -> V_111 ) ) {
V_49 = - V_117 ;
if ( ! ( V_115 -> V_118 & V_119 ) )
goto V_52;
if ( V_110 -> V_112 == & V_110 -> V_32 )
V_110 -> V_112 = & V_115 -> V_32 ;
}
V_110 -> V_113 ++ ;
F_103 ( & V_115 -> V_32 , & V_110 -> V_32 ) ;
V_52:
return V_49 ;
}
struct V_114 * F_104 ( struct V_109 * V_110 )
{
struct V_25 * V_115 ;
if ( F_54 ( ! V_110 -> V_113 ) )
return NULL ;
V_110 -> V_113 -- ;
if ( V_110 -> V_112 != & V_110 -> V_32 )
V_110 -> V_112 = V_110 -> V_112 -> V_33 ;
V_115 = V_110 -> V_32 . V_33 ;
F_78 ( V_115 ) ;
return F_15 ( V_115 , struct V_114 , V_32 ) ;
}
int F_105 ( struct V_109 * V_110 , struct V_83 * V_84 )
{
struct V_114 * V_120 ;
F_29 (req, &queue->list, list) {
if ( V_120 -> V_84 == V_84 )
return 1 ;
}
return 0 ;
}
static inline void F_106 ( T_2 * V_121 , unsigned int V_122 )
{
T_2 * V_123 = ( V_121 + V_122 ) ;
T_2 V_124 ;
for (; V_122 ; V_122 -- ) {
V_124 = * -- V_123 + 1 ;
* V_123 = V_124 ;
if ( V_124 )
break;
}
}
void F_107 ( T_2 * V_121 , unsigned int V_122 )
{
T_3 * V_123 = ( T_3 * ) ( V_121 + V_122 ) ;
T_1 V_124 ;
for (; V_122 >= 4 ; V_122 -= 4 ) {
V_124 = F_108 ( * -- V_123 ) + 1 ;
* V_123 = F_109 ( V_124 ) ;
if ( V_124 )
return;
}
F_106 ( V_121 , V_122 ) ;
}
static inline void F_110 ( T_2 * V_121 , const T_2 * V_123 , unsigned int V_122 )
{
for (; V_122 ; V_122 -- )
* V_121 ++ ^= * V_123 ++ ;
}
void F_111 ( T_2 * V_125 , const T_2 * V_126 , unsigned int V_122 )
{
T_1 * V_121 = ( T_1 * ) V_125 ;
T_1 * V_123 = ( T_1 * ) V_126 ;
for (; V_122 >= 4 ; V_122 -= 4 )
* V_121 ++ ^= * V_123 ++ ;
F_110 ( ( T_2 * ) V_121 , ( T_2 * ) V_123 , V_122 ) ;
}
unsigned int F_112 ( struct V_1 * V_2 )
{
return V_2 -> V_127 +
( V_2 -> V_14 & ~ ( F_113 () - 1 ) ) ;
}
static int T_4 F_114 ( void )
{
F_115 () ;
return 0 ;
}
static void T_5 F_116 ( void )
{
F_117 () ;
}
