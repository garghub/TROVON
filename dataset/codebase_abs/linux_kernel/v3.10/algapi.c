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
static int F_3 ( struct V_1 * V_2 )
{
if ( V_2 -> V_10 & ( V_2 -> V_10 + 1 ) )
return - V_11 ;
if ( V_2 -> V_12 > V_13 / 8 )
return - V_11 ;
if ( V_2 -> V_14 < 0 )
return - V_11 ;
return F_1 ( V_2 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = ( void * ) V_2 ;
struct V_17 * V_18 = V_16 -> V_18 ;
V_18 -> free ( V_16 ) ;
F_5 ( V_18 ) ;
}
static struct V_19 * F_6 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
struct V_19 * V_21 ,
struct V_19 * V_22 )
{
struct V_23 * V_24 , * V_25 ;
if ( F_7 ( V_20 ) )
return NULL ;
V_24 = F_8 ( V_20 , struct V_23 , V_26 ) ;
V_25 = F_9 ( V_24 -> V_26 . V_27 , struct V_23 , V_26 ) ;
if ( V_24 -> V_2 && & V_25 -> V_26 != V_20 && ! V_25 -> V_2 )
V_25 -> V_2 = ( V_25 -> V_26 . V_27 == V_20 ) ? V_2 :
& F_9 ( V_25 -> V_26 . V_27 , struct V_23 ,
V_26 ) -> V_16 -> V_2 ;
F_10 ( & V_24 -> V_26 , V_22 ) ;
return & V_25 -> V_26 == V_20 ? V_21 : & V_25 -> V_16 -> V_2 . V_28 ;
}
static void F_11 ( struct V_23 * V_24 ,
struct V_19 * V_26 )
{
struct V_15 * V_16 = V_24 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_18 ;
if ( F_12 ( & V_16 -> V_2 ) )
return;
V_16 -> V_2 . V_29 |= V_30 ;
if ( F_13 ( & V_16 -> V_26 ) )
return;
if ( ! V_18 || ! F_14 ( V_18 ) )
return;
F_15 ( V_31 , & V_16 -> V_2 ) ;
F_10 ( & V_16 -> V_2 . V_32 , V_26 ) ;
F_16 ( & V_16 -> V_26 ) ;
V_16 -> V_2 . V_33 = F_4 ;
F_17 ( ! F_7 ( & V_16 -> V_2 . V_28 ) ) ;
}
void F_18 ( struct V_1 * V_2 , struct V_19 * V_26 ,
struct V_1 * V_34 )
{
T_1 V_35 = ( V_34 ? : V_2 ) -> V_29 ;
struct V_23 * V_24 , * V_25 ;
F_19 ( V_22 ) ;
struct V_19 * V_36 ;
F_19 ( V_20 ) ;
F_19 ( V_21 ) ;
V_36 = & V_2 -> V_28 ;
F_20 (spawn, n, spawns, list) {
if ( ( V_24 -> V_2 -> V_29 ^ V_35 ) & V_24 -> V_37 )
continue;
F_10 ( & V_24 -> V_26 , & V_21 ) ;
}
V_36 = & V_21 ;
do {
while ( ! F_7 ( V_36 ) ) {
struct V_15 * V_16 ;
V_24 = F_8 ( V_36 , struct V_23 ,
V_26 ) ;
V_16 = V_24 -> V_16 ;
F_17 ( & V_16 -> V_2 == V_2 ) ;
F_10 ( & V_24 -> V_26 , & V_20 ) ;
if ( & V_16 -> V_2 == V_34 )
break;
V_24 -> V_2 = NULL ;
V_36 = & V_16 -> V_2 . V_28 ;
}
} while ( ( V_36 = F_6 ( V_2 , & V_20 , & V_21 ,
& V_22 ) ) );
F_20 (spawn, n, &secondary_spawns, list) {
if ( V_24 -> V_2 )
F_10 ( & V_24 -> V_26 , & V_24 -> V_2 -> V_28 ) ;
else
F_11 ( V_24 , V_26 ) ;
}
}
static struct V_38 * F_21 ( struct V_1 * V_2 )
{
struct V_1 * V_39 ;
struct V_38 * V_40 ;
int V_41 = - V_42 ;
if ( F_12 ( V_2 ) )
goto V_43;
F_22 ( & V_2 -> V_28 ) ;
V_2 -> V_29 &= ~ V_44 ;
V_41 = - V_45 ;
F_23 ( & V_2 -> V_46 , 1 ) ;
F_24 (q, &crypto_alg_list, cra_list) {
if ( V_39 == V_2 )
goto V_43;
if ( F_25 ( V_39 ) )
continue;
if ( F_26 ( V_39 ) ) {
if ( ! strcmp ( V_2 -> V_5 , V_39 -> V_5 ) )
goto V_43;
continue;
}
if ( ! strcmp ( V_39 -> V_5 , V_2 -> V_7 ) ||
! strcmp ( V_39 -> V_7 , V_2 -> V_5 ) )
goto V_43;
}
V_40 = F_27 ( V_2 -> V_7 ,
V_2 -> V_29 | V_44 , 0 ) ;
if ( F_28 ( V_40 ) )
goto V_47;
V_41 = - V_48 ;
V_40 -> V_49 = F_29 ( V_2 ) ;
if ( ! V_40 -> V_49 )
goto V_50;
F_23 ( & V_40 -> V_2 . V_46 , 1 ) ;
memcpy ( V_40 -> V_2 . V_5 , V_2 -> V_5 ,
V_8 ) ;
V_40 -> V_2 . V_14 = V_2 -> V_14 ;
F_30 ( & V_2 -> V_32 , & V_51 ) ;
F_30 ( & V_40 -> V_2 . V_32 , & V_51 ) ;
V_47:
return V_40 ;
V_50:
F_31 ( V_40 ) ;
V_43:
V_40 = F_32 ( V_41 ) ;
goto V_47;
}
void F_33 ( const char * V_52 , int V_43 )
{
struct V_38 * V_53 ;
struct V_1 * V_2 ;
struct V_1 * V_39 ;
F_19 ( V_26 ) ;
F_34 ( & V_54 ) ;
F_24 (q, &crypto_alg_list, cra_list) {
if ( F_25 ( V_39 ) || ! F_26 ( V_39 ) )
continue;
V_53 = (struct V_38 * ) V_39 ;
if ( ! strcmp ( V_39 -> V_5 , V_52 ) )
goto V_55;
}
F_35 ( V_56 L_2 , V_52 , V_43 ) ;
goto V_57;
V_55:
V_39 -> V_29 |= V_30 ;
V_2 = V_53 -> V_49 ;
if ( V_43 || F_7 ( & V_2 -> V_32 ) )
goto V_58;
V_2 -> V_29 |= V_44 ;
F_24 (q, &crypto_alg_list, cra_list) {
if ( V_39 == V_2 )
continue;
if ( F_25 ( V_39 ) )
continue;
if ( F_26 ( V_39 ) ) {
struct V_38 * V_40 = ( void * ) V_39 ;
if ( strcmp ( V_2 -> V_7 , V_39 -> V_7 ) &&
strcmp ( V_2 -> V_5 , V_39 -> V_7 ) )
continue;
if ( V_40 -> V_49 )
continue;
if ( ( V_39 -> V_29 ^ V_2 -> V_29 ) & V_40 -> V_37 )
continue;
if ( ! F_29 ( V_2 ) )
continue;
V_40 -> V_49 = V_2 ;
continue;
}
if ( strcmp ( V_2 -> V_7 , V_39 -> V_7 ) )
continue;
if ( strcmp ( V_2 -> V_5 , V_39 -> V_5 ) &&
V_39 -> V_14 > V_2 -> V_14 )
continue;
F_18 ( V_39 , & V_26 , V_2 ) ;
}
V_58:
F_36 ( & V_53 -> V_59 ) ;
V_57:
F_37 ( & V_54 ) ;
F_38 ( & V_26 ) ;
}
void F_38 ( struct V_19 * V_26 )
{
struct V_1 * V_2 ;
struct V_1 * V_25 ;
F_20 (alg, n, list, cra_list) {
F_39 ( & V_2 -> V_32 ) ;
F_40 ( V_2 ) ;
}
}
static void F_41 ( struct V_38 * V_40 )
{
int V_43 ;
V_43 = F_42 ( V_60 , V_40 -> V_49 ) ;
if ( V_43 != V_61 ) {
if ( F_43 ( V_43 != V_62 ) )
goto V_47;
F_33 ( V_40 -> V_2 . V_5 , 0 ) ;
}
V_43 = F_44 ( & V_40 -> V_59 ) ;
F_43 ( V_43 ) ;
V_47:
F_45 ( & V_40 -> V_2 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
struct V_38 * V_40 ;
int V_43 ;
V_43 = F_3 ( V_2 ) ;
if ( V_43 )
return V_43 ;
F_34 ( & V_54 ) ;
V_40 = F_21 ( V_2 ) ;
F_37 ( & V_54 ) ;
if ( F_28 ( V_40 ) )
return F_47 ( V_40 ) ;
F_41 ( V_40 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , struct V_19 * V_26 )
{
if ( F_49 ( F_7 ( & V_2 -> V_32 ) ) )
return - V_48 ;
V_2 -> V_29 |= V_30 ;
F_15 ( V_31 , V_2 ) ;
F_39 ( & V_2 -> V_32 ) ;
F_18 ( V_2 , V_26 , NULL ) ;
return 0 ;
}
int F_50 ( struct V_1 * V_2 )
{
int V_41 ;
F_19 ( V_26 ) ;
F_34 ( & V_54 ) ;
V_41 = F_48 ( V_2 , & V_26 ) ;
F_37 ( & V_54 ) ;
if ( V_41 )
return V_41 ;
F_17 ( F_51 ( & V_2 -> V_46 ) != 1 ) ;
if ( V_2 -> V_33 )
V_2 -> V_33 ( V_2 ) ;
F_38 ( & V_26 ) ;
return 0 ;
}
int F_52 ( struct V_1 * V_63 , int V_64 )
{
int V_65 , V_41 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
V_41 = F_46 ( & V_63 [ V_65 ] ) ;
if ( V_41 )
goto V_43;
}
return 0 ;
V_43:
for ( -- V_65 ; V_65 >= 0 ; -- V_65 )
F_50 ( & V_63 [ V_65 ] ) ;
return V_41 ;
}
int F_53 ( struct V_1 * V_63 , int V_64 )
{
int V_65 , V_41 ;
for ( V_65 = 0 ; V_65 < V_64 ; V_65 ++ ) {
V_41 = F_50 ( & V_63 [ V_65 ] ) ;
if ( V_41 )
F_54 ( L_3 ,
V_63 [ V_65 ] . V_5 , V_63 [ V_65 ] . V_7 , V_41 ) ;
}
return 0 ;
}
int F_55 ( struct V_17 * V_18 )
{
struct V_17 * V_39 ;
int V_43 = - V_45 ;
F_34 ( & V_54 ) ;
F_24 (q, &crypto_template_list, list) {
if ( V_39 == V_18 )
goto V_47;
}
F_30 ( & V_18 -> V_26 , & V_66 ) ;
F_15 ( V_67 , V_18 ) ;
V_43 = 0 ;
V_47:
F_37 ( & V_54 ) ;
return V_43 ;
}
void F_56 ( struct V_17 * V_18 )
{
struct V_15 * V_16 ;
struct V_68 * V_25 ;
struct V_69 * V_26 ;
F_19 ( V_70 ) ;
F_34 ( & V_54 ) ;
F_17 ( F_7 ( & V_18 -> V_26 ) ) ;
F_39 ( & V_18 -> V_26 ) ;
V_26 = & V_18 -> V_71 ;
F_57 (inst, list, list) {
int V_43 = F_48 ( & V_16 -> V_2 , & V_70 ) ;
F_17 ( V_43 ) ;
}
F_15 ( V_72 , V_18 ) ;
F_37 ( & V_54 ) ;
F_58 (inst, n, list, list) {
F_17 ( F_51 ( & V_16 -> V_2 . V_46 ) != 1 ) ;
V_18 -> free ( V_16 ) ;
}
F_38 ( & V_70 ) ;
}
static struct V_17 * F_59 ( const char * V_52 )
{
struct V_17 * V_39 , * V_18 = NULL ;
F_60 ( & V_54 ) ;
F_24 (q, &crypto_template_list, list) {
if ( strcmp ( V_39 -> V_52 , V_52 ) )
continue;
if ( F_49 ( ! F_14 ( V_39 ) ) )
continue;
V_18 = V_39 ;
break;
}
F_61 ( & V_54 ) ;
return V_18 ;
}
struct V_17 * F_62 ( const char * V_52 )
{
return F_63 ( F_59 ( V_52 ) , V_52 ) ;
}
int F_64 ( struct V_17 * V_18 ,
struct V_15 * V_16 )
{
struct V_38 * V_40 ;
int V_43 ;
V_43 = F_3 ( & V_16 -> V_2 ) ;
if ( V_43 )
goto V_43;
V_16 -> V_2 . V_73 = V_18 -> V_74 ;
V_16 -> V_2 . V_29 |= V_75 ;
F_34 ( & V_54 ) ;
V_40 = F_21 ( & V_16 -> V_2 ) ;
if ( F_28 ( V_40 ) )
goto V_57;
F_65 ( & V_16 -> V_26 , & V_18 -> V_71 ) ;
V_16 -> V_18 = V_18 ;
V_57:
F_37 ( & V_54 ) ;
V_43 = F_47 ( V_40 ) ;
if ( F_28 ( V_40 ) )
goto V_43;
F_41 ( V_40 ) ;
V_43 = 0 ;
V_43:
return V_43 ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_43 ;
struct V_15 * V_16 = ( void * ) V_2 ;
struct V_17 * V_18 = V_16 -> V_18 ;
F_19 ( V_70 ) ;
if ( ! ( V_2 -> V_29 & V_75 ) )
return - V_11 ;
F_17 ( F_51 ( & V_2 -> V_46 ) != 1 ) ;
F_34 ( & V_54 ) ;
F_67 ( & V_16 -> V_26 ) ;
V_43 = F_48 ( V_2 , & V_70 ) ;
F_37 ( & V_54 ) ;
if ( V_43 )
return V_43 ;
V_18 -> free ( V_16 ) ;
F_38 ( & V_70 ) ;
return 0 ;
}
int F_68 ( struct V_23 * V_24 , struct V_1 * V_2 ,
struct V_15 * V_16 , T_1 V_37 )
{
int V_43 = - V_42 ;
V_24 -> V_16 = V_16 ;
V_24 -> V_37 = V_37 ;
F_34 ( & V_54 ) ;
if ( ! F_25 ( V_2 ) ) {
F_30 ( & V_24 -> V_26 , & V_2 -> V_28 ) ;
V_24 -> V_2 = V_2 ;
V_43 = 0 ;
}
F_37 ( & V_54 ) ;
return V_43 ;
}
int F_69 ( struct V_23 * V_24 , struct V_1 * V_2 ,
struct V_15 * V_16 ,
const struct V_76 * V_77 )
{
int V_43 = - V_11 ;
if ( ( V_2 -> V_29 ^ V_77 -> type ) & V_77 -> V_78 )
goto V_47;
V_24 -> V_77 = V_77 ;
V_43 = F_68 ( V_24 , V_2 , V_16 , V_77 -> V_78 ) ;
V_47:
return V_43 ;
}
void F_70 ( struct V_23 * V_24 )
{
if ( ! V_24 -> V_2 )
return;
F_34 ( & V_54 ) ;
F_71 ( & V_24 -> V_26 ) ;
F_37 ( & V_54 ) ;
}
static struct V_1 * F_72 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
struct V_1 * V_79 ;
F_60 ( & V_54 ) ;
V_2 = V_24 -> V_2 ;
V_79 = V_2 ;
if ( V_79 )
V_79 = F_29 ( V_79 ) ;
F_61 ( & V_54 ) ;
if ( ! V_79 ) {
if ( V_2 )
F_73 ( V_2 ) ;
return F_32 ( - V_42 ) ;
}
return V_2 ;
}
struct V_80 * F_74 ( struct V_23 * V_24 , T_1 type ,
T_1 V_37 )
{
struct V_1 * V_2 ;
struct V_80 * V_81 ;
V_2 = F_72 ( V_24 ) ;
if ( F_28 ( V_2 ) )
return F_75 ( V_2 ) ;
V_81 = F_32 ( - V_11 ) ;
if ( F_49 ( ( V_2 -> V_29 ^ type ) & V_37 ) )
goto V_82;
V_81 = F_76 ( V_2 , type , V_37 ) ;
if ( F_28 ( V_81 ) )
goto V_82;
return V_81 ;
V_82:
F_77 ( V_2 ) ;
return V_81 ;
}
void * F_78 ( struct V_23 * V_24 )
{
struct V_1 * V_2 ;
struct V_80 * V_81 ;
V_2 = F_72 ( V_24 ) ;
if ( F_28 ( V_2 ) )
return F_75 ( V_2 ) ;
V_81 = F_79 ( V_2 , V_24 -> V_77 ) ;
if ( F_28 ( V_81 ) )
goto V_82;
return V_81 ;
V_82:
F_77 ( V_2 ) ;
return V_81 ;
}
int F_80 ( struct V_83 * V_84 )
{
return F_81 ( & V_85 , V_84 ) ;
}
int F_82 ( struct V_83 * V_84 )
{
return F_83 ( & V_85 , V_84 ) ;
}
struct V_86 * F_84 ( struct V_87 * * V_88 )
{
struct V_87 * V_89 = V_88 [ 0 ] ;
struct V_86 * V_90 ;
if ( ! V_89 )
return F_32 ( - V_48 ) ;
if ( F_85 ( V_89 ) < sizeof( * V_90 ) )
return F_32 ( - V_11 ) ;
if ( V_89 -> V_91 != V_92 )
return F_32 ( - V_11 ) ;
V_90 = F_86 ( V_89 ) ;
return V_90 ;
}
int F_87 ( struct V_87 * * V_88 , T_1 type )
{
struct V_86 * V_90 ;
V_90 = F_84 ( V_88 ) ;
if ( F_28 ( V_90 ) )
return F_47 ( V_90 ) ;
if ( ( V_90 -> type ^ type ) & V_90 -> V_37 )
return - V_11 ;
return 0 ;
}
const char * F_88 ( struct V_87 * V_89 )
{
struct V_93 * V_94 ;
if ( ! V_89 )
return F_32 ( - V_48 ) ;
if ( F_85 ( V_89 ) < sizeof( * V_94 ) )
return F_32 ( - V_11 ) ;
if ( V_89 -> V_91 != V_95 )
return F_32 ( - V_11 ) ;
V_94 = F_86 ( V_89 ) ;
V_94 -> V_52 [ V_8 - 1 ] = 0 ;
return V_94 -> V_52 ;
}
struct V_1 * F_89 ( struct V_87 * V_89 ,
const struct V_76 * V_77 ,
T_1 type , T_1 V_37 )
{
const char * V_52 ;
V_52 = F_88 ( V_89 ) ;
if ( F_28 ( V_52 ) )
return F_75 ( V_52 ) ;
return F_90 ( V_52 , V_77 , type , V_37 ) ;
}
int F_91 ( struct V_87 * V_89 , T_1 * V_96 )
{
struct F_91 * V_97 ;
if ( ! V_89 )
return - V_48 ;
if ( F_85 ( V_89 ) < sizeof( * V_97 ) )
return - V_11 ;
if ( V_89 -> V_91 != V_98 )
return - V_11 ;
V_97 = F_86 ( V_89 ) ;
* V_96 = V_97 -> V_96 ;
return 0 ;
}
void * F_92 ( const char * V_52 , struct V_1 * V_2 ,
unsigned int V_99 )
{
struct V_15 * V_16 ;
char * V_100 ;
int V_43 ;
V_100 = F_93 ( V_99 + sizeof( * V_16 ) + sizeof( struct V_23 ) ,
V_101 ) ;
if ( ! V_100 )
return F_32 ( - V_102 ) ;
V_16 = ( void * ) ( V_100 + V_99 ) ;
V_43 = - V_9 ;
if ( snprintf ( V_16 -> V_2 . V_7 , V_8 , L_4 , V_52 ,
V_2 -> V_7 ) >= V_8 )
goto V_103;
if ( snprintf ( V_16 -> V_2 . V_5 , V_8 , L_4 ,
V_52 , V_2 -> V_5 ) >= V_8 )
goto V_103;
return V_100 ;
V_103:
F_31 ( V_100 ) ;
return F_32 ( V_43 ) ;
}
struct V_15 * F_94 ( const char * V_52 ,
struct V_1 * V_2 )
{
struct V_15 * V_16 ;
struct V_23 * V_24 ;
int V_43 ;
V_16 = F_92 ( V_52 , V_2 , 0 ) ;
if ( F_28 ( V_16 ) )
goto V_47;
V_24 = F_95 ( V_16 ) ;
V_43 = F_68 ( V_24 , V_2 , V_16 ,
V_104 | V_105 ) ;
if ( V_43 )
goto V_103;
return V_16 ;
V_103:
F_31 ( V_16 ) ;
V_16 = F_32 ( V_43 ) ;
V_47:
return V_16 ;
}
void F_96 ( struct V_106 * V_107 , unsigned int V_108 )
{
F_22 ( & V_107 -> V_26 ) ;
V_107 -> V_109 = & V_107 -> V_26 ;
V_107 -> V_110 = 0 ;
V_107 -> V_108 = V_108 ;
}
int F_97 ( struct V_106 * V_107 ,
struct V_111 * V_112 )
{
int V_43 = - V_113 ;
if ( F_49 ( V_107 -> V_110 >= V_107 -> V_108 ) ) {
V_43 = - V_114 ;
if ( ! ( V_112 -> V_115 & V_116 ) )
goto V_47;
if ( V_107 -> V_109 == & V_107 -> V_26 )
V_107 -> V_109 = & V_112 -> V_26 ;
}
V_107 -> V_110 ++ ;
F_98 ( & V_112 -> V_26 , & V_107 -> V_26 ) ;
V_47:
return V_43 ;
}
void * F_99 ( struct V_106 * V_107 , unsigned int V_117 )
{
struct V_19 * V_112 ;
if ( F_49 ( ! V_107 -> V_110 ) )
return NULL ;
V_107 -> V_110 -- ;
if ( V_107 -> V_109 != & V_107 -> V_26 )
V_107 -> V_109 = V_107 -> V_109 -> V_27 ;
V_112 = V_107 -> V_26 . V_27 ;
F_71 ( V_112 ) ;
return ( char * ) F_9 ( V_112 , struct V_111 , V_26 ) -
V_117 ;
}
struct V_111 * F_100 ( struct V_106 * V_107 )
{
return F_99 ( V_107 , 0 ) ;
}
int F_101 ( struct V_106 * V_107 , struct V_80 * V_81 )
{
struct V_111 * V_118 ;
F_24 (req, &queue->list, list) {
if ( V_118 -> V_81 == V_81 )
return 1 ;
}
return 0 ;
}
static inline void F_102 ( T_2 * V_119 , unsigned int V_120 )
{
T_2 * V_121 = ( V_119 + V_120 ) ;
T_2 V_122 ;
for (; V_120 ; V_120 -- ) {
V_122 = * -- V_121 + 1 ;
* V_121 = V_122 ;
if ( V_122 )
break;
}
}
void F_103 ( T_2 * V_119 , unsigned int V_120 )
{
T_3 * V_121 = ( T_3 * ) ( V_119 + V_120 ) ;
T_1 V_122 ;
for (; V_120 >= 4 ; V_120 -= 4 ) {
V_122 = F_104 ( * -- V_121 ) + 1 ;
* V_121 = F_105 ( V_122 ) ;
if ( V_122 )
return;
}
F_102 ( V_119 , V_120 ) ;
}
static inline void F_106 ( T_2 * V_119 , const T_2 * V_121 , unsigned int V_120 )
{
for (; V_120 ; V_120 -- )
* V_119 ++ ^= * V_121 ++ ;
}
void F_107 ( T_2 * V_123 , const T_2 * V_124 , unsigned int V_120 )
{
T_1 * V_119 = ( T_1 * ) V_123 ;
T_1 * V_121 = ( T_1 * ) V_124 ;
for (; V_120 >= 4 ; V_120 -= 4 )
* V_119 ++ ^= * V_121 ++ ;
F_106 ( ( T_2 * ) V_119 , ( T_2 * ) V_121 , V_120 ) ;
}
static int T_4 F_108 ( void )
{
F_109 () ;
return 0 ;
}
static void T_5 F_110 ( void )
{
F_111 () ;
}
