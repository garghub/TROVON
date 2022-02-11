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
static void F_9 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = ( void * ) V_2 ;
struct V_22 * V_23 = V_21 -> V_23 ;
V_23 -> free ( V_21 ) ;
F_10 ( V_23 ) ;
}
static struct V_24 * F_11 ( struct V_1 * V_2 ,
struct V_24 * V_25 ,
struct V_24 * V_26 ,
struct V_24 * V_27 )
{
struct V_28 * V_29 , * V_30 ;
if ( F_12 ( V_25 ) )
return NULL ;
V_29 = F_13 ( V_25 , struct V_28 , V_31 ) ;
V_30 = F_14 ( V_29 -> V_31 . V_32 , struct V_28 , V_31 ) ;
if ( V_29 -> V_2 && & V_30 -> V_31 != V_25 && ! V_30 -> V_2 )
V_30 -> V_2 = ( V_30 -> V_31 . V_32 == V_25 ) ? V_2 :
& F_14 ( V_30 -> V_31 . V_32 , struct V_28 ,
V_31 ) -> V_21 -> V_2 ;
F_15 ( & V_29 -> V_31 , V_27 ) ;
return & V_30 -> V_31 == V_25 ? V_26 : & V_30 -> V_21 -> V_2 . V_33 ;
}
static void F_16 ( struct V_20 * V_21 ,
struct V_24 * V_31 )
{
struct V_22 * V_23 = V_21 -> V_23 ;
if ( F_17 ( & V_21 -> V_2 ) )
return;
V_21 -> V_2 . V_34 |= V_35 ;
if ( F_18 ( & V_21 -> V_31 ) )
return;
if ( ! V_23 || ! F_19 ( V_23 ) )
return;
F_20 ( V_36 , & V_21 -> V_2 ) ;
F_15 ( & V_21 -> V_2 . V_37 , V_31 ) ;
F_21 ( & V_21 -> V_31 ) ;
V_21 -> V_2 . V_38 = F_9 ;
F_22 ( ! F_12 ( & V_21 -> V_2 . V_33 ) ) ;
}
void F_23 ( struct V_1 * V_2 , struct V_24 * V_31 ,
struct V_1 * V_39 )
{
T_1 V_40 = ( V_39 ? : V_2 ) -> V_34 ;
struct V_28 * V_29 , * V_30 ;
F_24 ( V_27 ) ;
struct V_24 * V_41 ;
F_24 ( V_25 ) ;
F_24 ( V_26 ) ;
V_41 = & V_2 -> V_33 ;
F_25 (spawn, n, spawns, list) {
if ( ( V_29 -> V_2 -> V_34 ^ V_40 ) & V_29 -> V_42 )
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
F_22 ( & V_21 -> V_2 == V_2 ) ;
F_15 ( & V_29 -> V_31 , & V_25 ) ;
if ( & V_21 -> V_2 == V_39 )
break;
V_29 -> V_2 = NULL ;
V_41 = & V_21 -> V_2 . V_33 ;
}
} while ( ( V_41 = F_11 ( V_2 , & V_25 , & V_26 ,
& V_27 ) ) );
F_25 (spawn, n, &secondary_spawns, list) {
if ( V_29 -> V_2 )
F_15 ( & V_29 -> V_31 , & V_29 -> V_2 -> V_33 ) ;
else
F_16 ( V_29 -> V_21 , V_31 ) ;
}
}
static struct V_43 * F_26 ( struct V_1 * V_2 )
{
struct V_1 * V_44 ;
struct V_43 * V_45 ;
int V_46 = - V_47 ;
if ( F_17 ( V_2 ) )
goto V_48;
F_27 ( & V_2 -> V_33 ) ;
V_2 -> V_34 &= ~ V_49 ;
V_46 = - V_50 ;
F_28 (q, &crypto_alg_list, cra_list) {
if ( V_44 == V_2 )
goto V_48;
if ( F_29 ( V_44 ) )
continue;
if ( F_30 ( V_44 ) ) {
if ( ! strcmp ( V_2 -> V_5 , V_44 -> V_5 ) )
goto V_48;
continue;
}
if ( ! strcmp ( V_44 -> V_5 , V_2 -> V_7 ) ||
! strcmp ( V_44 -> V_7 , V_2 -> V_5 ) )
goto V_48;
}
V_45 = F_31 ( V_2 -> V_7 ,
V_2 -> V_34 | V_49 , 0 ) ;
if ( F_32 ( V_45 ) )
goto V_51;
V_46 = - V_52 ;
V_45 -> V_53 = F_33 ( V_2 ) ;
if ( ! V_45 -> V_53 )
goto V_54;
F_8 ( & V_45 -> V_2 . V_19 , 1 ) ;
memcpy ( V_45 -> V_2 . V_5 , V_2 -> V_5 ,
V_8 ) ;
V_45 -> V_2 . V_18 = V_2 -> V_18 ;
F_34 ( & V_2 -> V_37 , & V_55 ) ;
F_34 ( & V_45 -> V_2 . V_37 , & V_55 ) ;
V_51:
return V_45 ;
V_54:
F_35 ( V_45 ) ;
V_48:
V_45 = F_36 ( V_46 ) ;
goto V_51;
}
void F_37 ( const char * V_56 , int V_48 )
{
struct V_43 * V_57 ;
struct V_1 * V_2 ;
struct V_1 * V_44 ;
F_24 ( V_31 ) ;
F_38 ( & V_58 ) ;
F_28 (q, &crypto_alg_list, cra_list) {
if ( F_29 ( V_44 ) || ! F_30 ( V_44 ) )
continue;
V_57 = (struct V_43 * ) V_44 ;
if ( ! strcmp ( V_44 -> V_5 , V_56 ) )
goto V_59;
}
F_39 ( V_60 L_3 , V_56 , V_48 ) ;
goto V_61;
V_59:
V_44 -> V_34 |= V_35 ;
V_2 = V_57 -> V_53 ;
if ( V_48 || F_12 ( & V_2 -> V_37 ) )
goto V_62;
V_2 -> V_34 |= V_49 ;
F_28 (q, &crypto_alg_list, cra_list) {
if ( V_44 == V_2 )
continue;
if ( F_29 ( V_44 ) )
continue;
if ( F_30 ( V_44 ) ) {
struct V_43 * V_45 = ( void * ) V_44 ;
if ( strcmp ( V_2 -> V_7 , V_44 -> V_7 ) &&
strcmp ( V_2 -> V_5 , V_44 -> V_7 ) )
continue;
if ( V_45 -> V_53 )
continue;
if ( ( V_44 -> V_34 ^ V_2 -> V_34 ) & V_45 -> V_42 )
continue;
if ( ! F_33 ( V_2 ) )
continue;
V_45 -> V_53 = V_2 ;
continue;
}
if ( strcmp ( V_2 -> V_7 , V_44 -> V_7 ) )
continue;
if ( strcmp ( V_2 -> V_5 , V_44 -> V_5 ) &&
V_44 -> V_18 > V_2 -> V_18 )
continue;
F_23 ( V_44 , & V_31 , V_2 ) ;
}
V_62:
F_40 ( & V_57 -> V_63 ) ;
V_61:
F_41 ( & V_58 ) ;
F_42 ( & V_31 ) ;
}
void F_42 ( struct V_24 * V_31 )
{
struct V_1 * V_2 ;
struct V_1 * V_30 ;
F_25 (alg, n, list, cra_list) {
F_43 ( & V_2 -> V_37 ) ;
F_44 ( V_2 ) ;
}
}
static void F_45 ( struct V_43 * V_45 )
{
int V_48 ;
V_48 = F_46 ( V_64 , V_45 -> V_53 ) ;
if ( V_48 != V_65 ) {
if ( F_47 ( V_48 != V_66 ) )
goto V_51;
F_37 ( V_45 -> V_2 . V_5 , 0 ) ;
}
V_48 = F_48 ( & V_45 -> V_63 ) ;
F_47 ( V_48 ) ;
V_51:
F_49 ( & V_45 -> V_2 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
struct V_43 * V_45 ;
int V_48 ;
V_48 = F_7 ( V_2 ) ;
if ( V_48 )
return V_48 ;
F_38 ( & V_58 ) ;
V_45 = F_26 ( V_2 ) ;
F_41 ( & V_58 ) ;
if ( F_32 ( V_45 ) )
return F_51 ( V_45 ) ;
F_45 ( V_45 ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_24 * V_31 )
{
if ( F_53 ( F_12 ( & V_2 -> V_37 ) ) )
return - V_52 ;
V_2 -> V_34 |= V_35 ;
F_20 ( V_36 , V_2 ) ;
F_43 ( & V_2 -> V_37 ) ;
F_23 ( V_2 , V_31 , NULL ) ;
return 0 ;
}
int F_54 ( struct V_1 * V_2 )
{
int V_46 ;
F_24 ( V_31 ) ;
F_38 ( & V_58 ) ;
V_46 = F_52 ( V_2 , & V_31 ) ;
F_41 ( & V_58 ) ;
if ( V_46 )
return V_46 ;
F_22 ( F_55 ( & V_2 -> V_19 ) != 1 ) ;
if ( V_2 -> V_38 )
V_2 -> V_38 ( V_2 ) ;
F_42 ( & V_31 ) ;
return 0 ;
}
int F_56 ( struct V_1 * V_67 , int V_68 )
{
int V_69 , V_46 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
V_46 = F_50 ( & V_67 [ V_69 ] ) ;
if ( V_46 )
goto V_48;
}
return 0 ;
V_48:
for ( -- V_69 ; V_69 >= 0 ; -- V_69 )
F_54 ( & V_67 [ V_69 ] ) ;
return V_46 ;
}
int F_57 ( struct V_1 * V_67 , int V_68 )
{
int V_69 , V_46 ;
for ( V_69 = 0 ; V_69 < V_68 ; V_69 ++ ) {
V_46 = F_54 ( & V_67 [ V_69 ] ) ;
if ( V_46 )
F_58 ( L_4 ,
V_67 [ V_69 ] . V_5 , V_67 [ V_69 ] . V_7 , V_46 ) ;
}
return 0 ;
}
int F_59 ( struct V_22 * V_23 )
{
struct V_22 * V_44 ;
int V_48 = - V_50 ;
F_38 ( & V_58 ) ;
F_3 ( V_23 -> V_10 ) ;
F_28 (q, &crypto_template_list, list) {
if ( V_44 == V_23 )
goto V_51;
}
F_34 ( & V_23 -> V_31 , & V_70 ) ;
F_20 ( V_71 , V_23 ) ;
V_48 = 0 ;
V_51:
F_41 ( & V_58 ) ;
return V_48 ;
}
void F_60 ( struct V_22 * V_23 )
{
struct V_20 * V_21 ;
struct V_72 * V_30 ;
struct V_73 * V_31 ;
F_24 ( V_74 ) ;
F_38 ( & V_58 ) ;
F_22 ( F_12 ( & V_23 -> V_31 ) ) ;
F_43 ( & V_23 -> V_31 ) ;
V_31 = & V_23 -> V_75 ;
F_61 (inst, list, list) {
int V_48 = F_52 ( & V_21 -> V_2 , & V_74 ) ;
F_22 ( V_48 ) ;
}
F_20 ( V_76 , V_23 ) ;
F_41 ( & V_58 ) ;
F_62 (inst, n, list, list) {
F_22 ( F_55 ( & V_21 -> V_2 . V_19 ) != 1 ) ;
V_23 -> free ( V_21 ) ;
}
F_42 ( & V_74 ) ;
}
static struct V_22 * F_63 ( const char * V_56 )
{
struct V_22 * V_44 , * V_23 = NULL ;
F_64 ( & V_58 ) ;
F_28 (q, &crypto_template_list, list) {
if ( strcmp ( V_44 -> V_56 , V_56 ) )
continue;
if ( F_53 ( ! F_19 ( V_44 ) ) )
continue;
V_23 = V_44 ;
break;
}
F_65 ( & V_58 ) ;
return V_23 ;
}
struct V_22 * F_66 ( const char * V_56 )
{
return F_67 ( F_63 ( V_56 ) ,
L_5 , V_56 ) ;
}
int F_68 ( struct V_22 * V_23 ,
struct V_20 * V_21 )
{
struct V_43 * V_45 ;
int V_48 ;
V_48 = F_7 ( & V_21 -> V_2 ) ;
if ( V_48 )
return V_48 ;
V_21 -> V_2 . V_13 = V_23 -> V_10 ;
V_21 -> V_2 . V_34 |= V_77 ;
if ( F_53 ( ! F_33 ( & V_21 -> V_2 ) ) )
return - V_47 ;
F_38 ( & V_58 ) ;
V_45 = F_26 ( & V_21 -> V_2 ) ;
if ( F_32 ( V_45 ) )
goto V_61;
F_69 ( & V_21 -> V_31 , & V_23 -> V_75 ) ;
V_21 -> V_23 = V_23 ;
V_61:
F_41 ( & V_58 ) ;
V_48 = F_51 ( V_45 ) ;
if ( F_32 ( V_45 ) )
goto V_48;
F_45 ( V_45 ) ;
if ( ! ( V_21 -> V_2 . V_34 & V_49 ) )
F_70 ( V_21 ) ;
V_48 = 0 ;
V_48:
F_71 ( & V_21 -> V_2 ) ;
return V_48 ;
}
int F_70 ( struct V_20 * V_21 )
{
F_24 ( V_31 ) ;
F_38 ( & V_58 ) ;
F_23 ( & V_21 -> V_2 , & V_31 , NULL ) ;
F_16 ( V_21 , & V_31 ) ;
F_41 ( & V_58 ) ;
F_42 ( & V_31 ) ;
return 0 ;
}
int F_72 ( struct V_28 * V_29 , struct V_1 * V_2 ,
struct V_20 * V_21 , T_1 V_42 )
{
int V_48 = - V_47 ;
V_29 -> V_21 = V_21 ;
V_29 -> V_42 = V_42 ;
F_38 ( & V_58 ) ;
if ( ! F_29 ( V_2 ) ) {
F_34 ( & V_29 -> V_31 , & V_2 -> V_33 ) ;
V_29 -> V_2 = V_2 ;
V_48 = 0 ;
}
F_41 ( & V_58 ) ;
return V_48 ;
}
int F_73 ( struct V_28 * V_29 , struct V_1 * V_2 ,
struct V_20 * V_21 ,
const struct V_78 * V_79 )
{
int V_48 = - V_15 ;
if ( ( V_2 -> V_34 ^ V_79 -> type ) & V_79 -> V_80 )
goto V_51;
V_29 -> V_79 = V_79 ;
V_48 = F_72 ( V_29 , V_2 , V_21 , V_79 -> V_80 ) ;
V_51:
return V_48 ;
}
int F_74 ( struct V_28 * V_29 , const char * V_56 ,
T_1 type , T_1 V_42 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = F_75 ( V_56 , V_29 -> V_79 , type , V_42 ) ;
if ( F_32 ( V_2 ) )
return F_51 ( V_2 ) ;
V_48 = F_72 ( V_29 , V_2 , V_29 -> V_21 , V_42 ) ;
F_71 ( V_2 ) ;
return V_48 ;
}
void F_76 ( struct V_28 * V_29 )
{
if ( ! V_29 -> V_2 )
return;
F_38 ( & V_58 ) ;
F_77 ( & V_29 -> V_31 ) ;
F_41 ( & V_58 ) ;
}
static struct V_1 * F_78 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_1 * V_81 ;
F_64 ( & V_58 ) ;
V_2 = V_29 -> V_2 ;
V_81 = V_2 ;
if ( V_81 )
V_81 = F_33 ( V_81 ) ;
F_65 ( & V_58 ) ;
if ( ! V_81 ) {
if ( V_2 )
F_79 ( V_2 ) ;
return F_36 ( - V_47 ) ;
}
return V_2 ;
}
struct V_82 * F_80 ( struct V_28 * V_29 , T_1 type ,
T_1 V_42 )
{
struct V_1 * V_2 ;
struct V_82 * V_83 ;
V_2 = F_78 ( V_29 ) ;
if ( F_32 ( V_2 ) )
return F_81 ( V_2 ) ;
V_83 = F_36 ( - V_15 ) ;
if ( F_53 ( ( V_2 -> V_34 ^ type ) & V_42 ) )
goto V_84;
V_83 = F_82 ( V_2 , type , V_42 ) ;
if ( F_32 ( V_83 ) )
goto V_84;
return V_83 ;
V_84:
F_71 ( V_2 ) ;
return V_83 ;
}
void * F_83 ( struct V_28 * V_29 )
{
struct V_1 * V_2 ;
struct V_82 * V_83 ;
V_2 = F_78 ( V_29 ) ;
if ( F_32 ( V_2 ) )
return F_81 ( V_2 ) ;
V_83 = F_84 ( V_2 , V_29 -> V_79 ) ;
if ( F_32 ( V_83 ) )
goto V_84;
return V_83 ;
V_84:
F_71 ( V_2 ) ;
return V_83 ;
}
int F_85 ( struct V_85 * V_86 )
{
return F_86 ( & V_87 , V_86 ) ;
}
int F_87 ( struct V_85 * V_86 )
{
return F_88 ( & V_87 , V_86 ) ;
}
struct V_88 * F_89 ( struct V_89 * * V_90 )
{
struct V_89 * V_91 = V_90 [ 0 ] ;
struct V_88 * V_92 ;
if ( ! V_91 )
return F_36 ( - V_52 ) ;
if ( F_90 ( V_91 ) < sizeof( * V_92 ) )
return F_36 ( - V_15 ) ;
if ( V_91 -> V_93 != V_94 )
return F_36 ( - V_15 ) ;
V_92 = F_91 ( V_91 ) ;
return V_92 ;
}
int F_92 ( struct V_89 * * V_90 , T_1 type )
{
struct V_88 * V_92 ;
V_92 = F_89 ( V_90 ) ;
if ( F_32 ( V_92 ) )
return F_51 ( V_92 ) ;
if ( ( V_92 -> type ^ type ) & V_92 -> V_42 )
return - V_15 ;
return 0 ;
}
const char * F_93 ( struct V_89 * V_91 )
{
struct V_95 * V_96 ;
if ( ! V_91 )
return F_36 ( - V_52 ) ;
if ( F_90 ( V_91 ) < sizeof( * V_96 ) )
return F_36 ( - V_15 ) ;
if ( V_91 -> V_93 != V_97 )
return F_36 ( - V_15 ) ;
V_96 = F_91 ( V_91 ) ;
V_96 -> V_56 [ V_8 - 1 ] = 0 ;
return V_96 -> V_56 ;
}
struct V_1 * F_94 ( struct V_89 * V_91 ,
const struct V_78 * V_79 ,
T_1 type , T_1 V_42 )
{
const char * V_56 ;
V_56 = F_93 ( V_91 ) ;
if ( F_32 ( V_56 ) )
return F_81 ( V_56 ) ;
return F_75 ( V_56 , V_79 , type , V_42 ) ;
}
int F_95 ( struct V_89 * V_91 , T_1 * V_98 )
{
struct F_95 * V_99 ;
if ( ! V_91 )
return - V_52 ;
if ( F_90 ( V_91 ) < sizeof( * V_99 ) )
return - V_15 ;
if ( V_91 -> V_93 != V_100 )
return - V_15 ;
V_99 = F_91 ( V_91 ) ;
* V_98 = V_99 -> V_98 ;
return 0 ;
}
void * F_96 ( const char * V_56 , struct V_1 * V_2 ,
unsigned int V_101 )
{
struct V_20 * V_21 ;
char * V_102 ;
int V_48 ;
V_102 = F_97 ( V_101 + sizeof( * V_21 ) + sizeof( struct V_28 ) ,
V_103 ) ;
if ( ! V_102 )
return F_36 ( - V_104 ) ;
V_21 = ( void * ) ( V_102 + V_101 ) ;
V_48 = - V_9 ;
if ( snprintf ( V_21 -> V_2 . V_7 , V_8 , L_6 , V_56 ,
V_2 -> V_7 ) >= V_8 )
goto V_105;
if ( snprintf ( V_21 -> V_2 . V_5 , V_8 , L_6 ,
V_56 , V_2 -> V_5 ) >= V_8 )
goto V_105;
return V_102 ;
V_105:
F_35 ( V_102 ) ;
return F_36 ( V_48 ) ;
}
struct V_20 * F_98 ( const char * V_56 ,
struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_28 * V_29 ;
int V_48 ;
V_21 = F_96 ( V_56 , V_2 , 0 ) ;
if ( F_32 ( V_21 ) )
goto V_51;
V_29 = F_99 ( V_21 ) ;
V_48 = F_72 ( V_29 , V_2 , V_21 ,
V_106 | V_107 ) ;
if ( V_48 )
goto V_105;
return V_21 ;
V_105:
F_35 ( V_21 ) ;
V_21 = F_36 ( V_48 ) ;
V_51:
return V_21 ;
}
void F_100 ( struct V_108 * V_109 , unsigned int V_110 )
{
F_27 ( & V_109 -> V_31 ) ;
V_109 -> V_111 = & V_109 -> V_31 ;
V_109 -> V_112 = 0 ;
V_109 -> V_110 = V_110 ;
}
int F_101 ( struct V_108 * V_109 ,
struct V_113 * V_114 )
{
int V_48 = - V_115 ;
if ( F_53 ( V_109 -> V_112 >= V_109 -> V_110 ) ) {
V_48 = - V_116 ;
if ( ! ( V_114 -> V_117 & V_118 ) )
goto V_51;
if ( V_109 -> V_111 == & V_109 -> V_31 )
V_109 -> V_111 = & V_114 -> V_31 ;
}
V_109 -> V_112 ++ ;
F_102 ( & V_114 -> V_31 , & V_109 -> V_31 ) ;
V_51:
return V_48 ;
}
void * F_103 ( struct V_108 * V_109 , unsigned int V_119 )
{
struct V_24 * V_114 ;
if ( F_53 ( ! V_109 -> V_112 ) )
return NULL ;
V_109 -> V_112 -- ;
if ( V_109 -> V_111 != & V_109 -> V_31 )
V_109 -> V_111 = V_109 -> V_111 -> V_32 ;
V_114 = V_109 -> V_31 . V_32 ;
F_77 ( V_114 ) ;
return ( char * ) F_14 ( V_114 , struct V_113 , V_31 ) -
V_119 ;
}
struct V_113 * F_104 ( struct V_108 * V_109 )
{
return F_103 ( V_109 , 0 ) ;
}
int F_105 ( struct V_108 * V_109 , struct V_82 * V_83 )
{
struct V_113 * V_120 ;
F_28 (req, &queue->list, list) {
if ( V_120 -> V_83 == V_83 )
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
