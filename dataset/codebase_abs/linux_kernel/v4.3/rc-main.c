static struct V_1 * F_1 ( const char * V_2 )
{
struct V_1 * V_3 = NULL ;
F_2 ( & V_4 ) ;
F_3 (map, &rc_map_list, list) {
if ( ! strcmp ( V_2 , V_3 -> V_3 . V_2 ) ) {
F_4 ( & V_4 ) ;
return V_3 ;
}
}
F_4 ( & V_4 ) ;
return NULL ;
}
struct V_5 * F_5 ( const char * V_2 )
{
struct V_1 * V_3 ;
V_3 = F_1 ( V_2 ) ;
#ifdef F_6
if ( ! V_3 ) {
int V_6 = F_7 ( L_1 , V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_7 L_2 , V_2 ) ;
return NULL ;
}
F_9 ( 20 ) ;
V_3 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_3 ) {
F_8 ( V_7 L_3 , V_2 ) ;
return NULL ;
}
F_8 ( V_8 L_4 , V_3 -> V_3 . V_2 ) ;
return & V_3 -> V_3 ;
}
int F_10 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_11 ( & V_3 -> V_9 , & V_1 ) ;
F_4 ( & V_4 ) ;
return 0 ;
}
void F_12 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_13 ( & V_3 -> V_9 ) ;
F_4 ( & V_4 ) ;
}
static int F_14 ( struct V_5 * V_5 ,
const char * V_2 , T_1 V_10 , T_2 V_11 )
{
V_5 -> V_2 = V_2 ;
V_5 -> V_10 = V_10 ;
V_5 -> V_12 = F_15 ( V_11 * sizeof( struct V_13 ) ) ;
V_5 -> V_11 = V_5 -> V_12 / sizeof( struct V_13 ) ;
V_5 -> V_14 = F_16 ( V_5 -> V_12 , V_15 ) ;
if ( ! V_5 -> V_14 )
return - V_16 ;
F_17 ( 1 , L_5 ,
V_5 -> V_11 , V_5 -> V_12 ) ;
return 0 ;
}
static void F_18 ( struct V_5 * V_5 )
{
V_5 -> V_11 = 0 ;
F_19 ( V_5 -> V_14 ) ;
V_5 -> V_14 = NULL ;
}
static int F_20 ( struct V_5 * V_5 , T_3 V_17 )
{
unsigned int V_18 = V_5 -> V_12 ;
unsigned int V_19 = V_18 ;
struct V_13 * V_20 = V_5 -> V_14 ;
struct V_13 * V_21 ;
if ( V_5 -> V_11 == V_5 -> V_22 ) {
if ( V_5 -> V_12 >= V_23 )
return - V_16 ;
V_19 *= 2 ;
F_17 ( 1 , L_6 , V_19 ) ;
}
if ( ( V_5 -> V_22 * 3 < V_5 -> V_11 ) && ( V_18 > V_24 ) ) {
V_19 /= 2 ;
F_17 ( 1 , L_7 , V_19 ) ;
}
if ( V_19 == V_18 )
return 0 ;
V_21 = F_16 ( V_19 , V_17 ) ;
if ( ! V_21 ) {
F_17 ( 1 , L_8 , V_19 ) ;
return - V_16 ;
}
memcpy ( V_21 , V_5 -> V_14 , V_5 -> V_22 * sizeof( struct V_13 ) ) ;
V_5 -> V_14 = V_21 ;
V_5 -> V_12 = V_19 ;
V_5 -> V_11 = V_5 -> V_12 / sizeof( struct V_13 ) ;
F_19 ( V_20 ) ;
return 0 ;
}
static unsigned int F_21 ( struct V_25 * V_26 ,
struct V_5 * V_5 ,
unsigned int V_27 ,
unsigned int V_28 )
{
int V_29 = V_5 -> V_14 [ V_27 ] . V_30 ;
int V_31 ;
if ( V_28 == V_32 || V_28 == V_33 ) {
F_17 ( 1 , L_9 ,
V_27 , V_5 -> V_14 [ V_27 ] . V_34 ) ;
V_5 -> V_22 -- ;
memmove ( & V_5 -> V_14 [ V_27 ] , & V_5 -> V_14 [ V_27 + 1 ] ,
( V_5 -> V_22 - V_27 ) * sizeof( struct V_13 ) ) ;
} else {
F_17 ( 1 , L_10 ,
V_27 ,
V_29 == V_32 ? L_11 : L_12 ,
V_5 -> V_14 [ V_27 ] . V_34 , V_28 ) ;
V_5 -> V_14 [ V_27 ] . V_30 = V_28 ;
F_22 ( V_28 , V_26 -> V_35 -> V_36 ) ;
}
if ( V_29 != V_32 ) {
F_23 ( V_29 , V_26 -> V_35 -> V_36 ) ;
for ( V_31 = 0 ; V_31 < V_5 -> V_22 ; V_31 ++ ) {
if ( V_5 -> V_14 [ V_31 ] . V_30 == V_29 ) {
F_22 ( V_29 , V_26 -> V_35 -> V_36 ) ;
break;
}
}
F_20 ( V_5 , V_37 ) ;
}
return V_29 ;
}
static unsigned int F_24 ( struct V_25 * V_26 ,
struct V_5 * V_5 ,
unsigned int V_34 ,
bool V_38 )
{
unsigned int V_31 ;
if ( V_26 -> V_39 )
V_34 &= V_26 -> V_39 ;
for ( V_31 = 0 ; V_31 < V_5 -> V_22 ; V_31 ++ ) {
if ( V_5 -> V_14 [ V_31 ] . V_34 == V_34 )
return V_31 ;
if ( V_5 -> V_14 [ V_31 ] . V_34 >= V_34 )
break;
}
if ( V_5 -> V_11 == V_5 -> V_22 ) {
if ( ! V_38 || F_20 ( V_5 , V_37 ) )
return - 1U ;
}
if ( V_31 < V_5 -> V_22 )
memmove ( & V_5 -> V_14 [ V_31 + 1 ] , & V_5 -> V_14 [ V_31 ] ,
( V_5 -> V_22 - V_31 ) * sizeof( struct V_13 ) ) ;
V_5 -> V_14 [ V_31 ] . V_34 = V_34 ;
V_5 -> V_14 [ V_31 ] . V_30 = V_32 ;
V_5 -> V_22 ++ ;
return V_31 ;
}
static int F_25 ( struct V_35 * V_40 ,
const struct V_41 * V_42 ,
unsigned int * V_29 )
{
struct V_25 * V_43 = F_26 ( V_40 ) ;
struct V_5 * V_5 = & V_43 -> V_5 ;
unsigned int V_27 ;
unsigned int V_34 ;
int V_44 = 0 ;
unsigned long V_45 ;
F_27 ( & V_5 -> V_46 , V_45 ) ;
if ( V_42 -> V_45 & V_47 ) {
V_27 = V_42 -> V_27 ;
if ( V_27 >= V_5 -> V_22 ) {
V_44 = - V_48 ;
goto V_49;
}
} else {
V_44 = F_28 ( V_42 , & V_34 ) ;
if ( V_44 )
goto V_49;
V_27 = F_24 ( V_43 , V_5 , V_34 , true ) ;
if ( V_27 >= V_5 -> V_22 ) {
V_44 = - V_16 ;
goto V_49;
}
}
* V_29 = F_21 ( V_43 , V_5 , V_27 , V_42 -> V_30 ) ;
V_49:
F_29 ( & V_5 -> V_46 , V_45 ) ;
return V_44 ;
}
static int F_30 ( struct V_25 * V_26 ,
const struct V_5 * V_50 )
{
struct V_5 * V_5 = & V_26 -> V_5 ;
unsigned int V_31 , V_27 ;
int V_6 ;
V_6 = F_14 ( V_5 , V_50 -> V_2 ,
V_50 -> V_10 , V_50 -> V_11 ) ;
if ( V_6 )
return V_6 ;
F_17 ( 1 , L_5 ,
V_5 -> V_11 , V_5 -> V_12 ) ;
for ( V_31 = 0 ; V_31 < V_50 -> V_11 ; V_31 ++ ) {
V_27 = F_24 ( V_26 , V_5 ,
V_50 -> V_14 [ V_31 ] . V_34 , false ) ;
if ( V_27 >= V_5 -> V_22 ) {
V_6 = - V_16 ;
break;
}
F_21 ( V_26 , V_5 , V_27 ,
V_50 -> V_14 [ V_31 ] . V_30 ) ;
}
if ( V_6 )
F_18 ( V_5 ) ;
return V_6 ;
}
static unsigned int F_31 ( const struct V_5 * V_5 ,
unsigned int V_34 )
{
int V_51 = 0 ;
int V_52 = V_5 -> V_22 - 1 ;
int V_53 ;
while ( V_51 <= V_52 ) {
V_53 = ( V_51 + V_52 ) / 2 ;
if ( V_5 -> V_14 [ V_53 ] . V_34 < V_34 )
V_51 = V_53 + 1 ;
else if ( V_5 -> V_14 [ V_53 ] . V_34 > V_34 )
V_52 = V_53 - 1 ;
else
return V_53 ;
}
return - 1U ;
}
static int F_32 ( struct V_35 * V_40 ,
struct V_41 * V_42 )
{
struct V_25 * V_43 = F_26 ( V_40 ) ;
struct V_5 * V_5 = & V_43 -> V_5 ;
struct V_13 * V_54 ;
unsigned long V_45 ;
unsigned int V_27 ;
unsigned int V_34 ;
int V_44 ;
F_27 ( & V_5 -> V_46 , V_45 ) ;
if ( V_42 -> V_45 & V_47 ) {
V_27 = V_42 -> V_27 ;
} else {
V_44 = F_28 ( V_42 , & V_34 ) ;
if ( V_44 )
goto V_49;
V_27 = F_31 ( V_5 , V_34 ) ;
}
if ( V_27 < V_5 -> V_22 ) {
V_54 = & V_5 -> V_14 [ V_27 ] ;
V_42 -> V_27 = V_27 ;
V_42 -> V_30 = V_54 -> V_30 ;
V_42 -> V_22 = sizeof( V_54 -> V_34 ) ;
memcpy ( V_42 -> V_34 , & V_54 -> V_34 , sizeof( V_54 -> V_34 ) ) ;
} else if ( ! ( V_42 -> V_45 & V_47 ) ) {
V_42 -> V_27 = V_27 ;
V_42 -> V_30 = V_32 ;
} else {
V_44 = - V_48 ;
goto V_49;
}
V_44 = 0 ;
V_49:
F_29 ( & V_5 -> V_46 , V_45 ) ;
return V_44 ;
}
T_4 F_33 ( struct V_25 * V_26 , T_4 V_34 )
{
struct V_5 * V_5 = & V_26 -> V_5 ;
unsigned int V_30 ;
unsigned int V_27 ;
unsigned long V_45 ;
F_27 ( & V_5 -> V_46 , V_45 ) ;
V_27 = F_31 ( V_5 , V_34 ) ;
V_30 = V_27 < V_5 -> V_22 ?
V_5 -> V_14 [ V_27 ] . V_30 : V_32 ;
F_29 ( & V_5 -> V_46 , V_45 ) ;
if ( V_30 != V_32 )
F_17 ( 1 , L_13 ,
V_26 -> V_55 , V_34 , V_30 ) ;
return V_30 ;
}
static void F_34 ( struct V_25 * V_26 , bool V_56 )
{
if ( ! V_26 -> V_57 )
return;
F_17 ( 1 , L_14 , V_26 -> V_58 ) ;
F_35 ( V_26 -> V_35 , V_26 -> V_58 , 0 ) ;
F_36 ( V_59 , V_60 ) ;
if ( V_56 )
F_37 ( V_26 -> V_35 ) ;
V_26 -> V_57 = false ;
}
void F_38 ( struct V_25 * V_26 )
{
unsigned long V_45 ;
F_27 ( & V_26 -> V_61 , V_45 ) ;
F_34 ( V_26 , true ) ;
F_29 ( & V_26 -> V_61 , V_45 ) ;
}
static void F_39 ( unsigned long V_62 )
{
struct V_25 * V_26 = (struct V_25 * ) V_62 ;
unsigned long V_45 ;
F_27 ( & V_26 -> V_61 , V_45 ) ;
if ( F_40 ( V_26 -> V_63 ) )
F_34 ( V_26 , true ) ;
F_29 ( & V_26 -> V_61 , V_45 ) ;
}
void F_41 ( struct V_25 * V_26 )
{
unsigned long V_45 ;
F_27 ( & V_26 -> V_61 , V_45 ) ;
F_42 ( V_26 -> V_35 , V_64 , V_65 , V_26 -> V_66 ) ;
F_37 ( V_26 -> V_35 ) ;
if ( ! V_26 -> V_57 )
goto V_49;
V_26 -> V_63 = V_67 + F_43 ( V_68 ) ;
F_44 ( & V_26 -> V_69 , V_26 -> V_63 ) ;
V_49:
F_29 ( & V_26 -> V_61 , V_45 ) ;
}
static void F_45 ( struct V_25 * V_26 , enum V_10 V_70 ,
T_4 V_34 , T_4 V_30 , T_5 V_71 )
{
bool V_72 = ( ! V_26 -> V_57 ||
V_26 -> V_73 != V_70 ||
V_26 -> V_66 != V_34 ||
V_26 -> V_74 != V_71 ) ;
if ( V_72 && V_26 -> V_57 )
F_34 ( V_26 , false ) ;
F_42 ( V_26 -> V_35 , V_64 , V_65 , V_34 ) ;
if ( V_72 && V_30 != V_32 ) {
V_26 -> V_57 = true ;
V_26 -> V_73 = V_70 ;
V_26 -> V_66 = V_34 ;
V_26 -> V_74 = V_71 ;
V_26 -> V_58 = V_30 ;
F_17 ( 1 , L_15
L_16 ,
V_26 -> V_55 , V_30 , V_70 , V_34 ) ;
F_35 ( V_26 -> V_35 , V_30 , 1 ) ;
F_36 ( V_59 , V_75 ) ;
}
F_37 ( V_26 -> V_35 ) ;
}
void F_46 ( struct V_25 * V_26 , enum V_10 V_70 , T_4 V_34 , T_5 V_71 )
{
unsigned long V_45 ;
T_4 V_30 = F_33 ( V_26 , V_34 ) ;
F_27 ( & V_26 -> V_61 , V_45 ) ;
F_45 ( V_26 , V_70 , V_34 , V_30 , V_71 ) ;
if ( V_26 -> V_57 ) {
V_26 -> V_63 = V_67 + F_43 ( V_68 ) ;
F_44 ( & V_26 -> V_69 , V_26 -> V_63 ) ;
}
F_29 ( & V_26 -> V_61 , V_45 ) ;
}
void F_47 ( struct V_25 * V_26 , enum V_10 V_70 ,
T_4 V_34 , T_5 V_71 )
{
unsigned long V_45 ;
T_4 V_30 = F_33 ( V_26 , V_34 ) ;
F_27 ( & V_26 -> V_61 , V_45 ) ;
F_45 ( V_26 , V_70 , V_34 , V_30 , V_71 ) ;
F_29 ( & V_26 -> V_61 , V_45 ) ;
}
int F_48 ( struct V_25 * V_43 )
{
int V_76 = 0 ;
if ( ! V_43 )
return - V_48 ;
F_49 ( & V_43 -> V_46 ) ;
if ( ! V_43 -> V_77 ++ && V_43 -> V_78 != NULL )
V_76 = V_43 -> V_78 ( V_43 ) ;
if ( V_76 )
V_43 -> V_77 -- ;
F_50 ( & V_43 -> V_46 ) ;
return V_76 ;
}
static int F_51 ( struct V_35 * V_40 )
{
struct V_25 * V_43 = F_26 ( V_40 ) ;
return F_48 ( V_43 ) ;
}
void F_52 ( struct V_25 * V_43 )
{
if ( V_43 ) {
F_49 ( & V_43 -> V_46 ) ;
if ( ! -- V_43 -> V_77 && V_43 -> V_79 != NULL )
V_43 -> V_79 ( V_43 ) ;
F_50 ( & V_43 -> V_46 ) ;
}
}
static void F_53 ( struct V_35 * V_40 )
{
struct V_25 * V_43 = F_26 ( V_40 ) ;
F_52 ( V_43 ) ;
}
static char * F_54 ( struct V_80 * V_26 , T_6 * V_81 )
{
return F_55 ( V_15 , L_17 , F_56 ( V_26 ) ) ;
}
static bool F_57 ( void )
{
#if F_58 ( V_82 )
struct V_83 * V_84 ;
F_49 ( & V_85 ) ;
V_84 = F_59 ( L_18 ) ;
F_50 ( & V_85 ) ;
return V_84 ? true : false ;
#elif F_58 ( V_86 )
return true ;
#else
return false ;
#endif
}
static T_7 F_60 ( struct V_80 * V_80 ,
struct V_87 * V_88 , char * V_89 )
{
struct V_25 * V_26 = F_61 ( V_80 ) ;
struct V_90 * V_91 = F_62 ( V_88 ) ;
T_1 V_92 , V_93 ;
char * V_94 = V_89 ;
int V_31 ;
if ( ! V_26 )
return - V_48 ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_91 -> type == V_95 ) {
V_93 = V_26 -> V_96 ;
V_92 = V_26 -> V_97 ;
if ( V_26 -> V_98 && ! V_92 )
V_92 = F_63 () ;
} else {
V_93 = V_26 -> V_99 ;
V_92 = V_26 -> V_100 ;
}
F_50 ( & V_26 -> V_46 ) ;
F_17 ( 1 , L_19 ,
V_101 , ( long long ) V_92 , ( long long ) V_93 ) ;
for ( V_31 = 0 ; V_31 < F_64 ( V_102 ) ; V_31 ++ ) {
if ( V_92 & V_93 & V_102 [ V_31 ] . type )
V_94 += sprintf ( V_94 , L_20 , V_102 [ V_31 ] . V_2 ) ;
else if ( V_92 & V_102 [ V_31 ] . type )
V_94 += sprintf ( V_94 , L_21 , V_102 [ V_31 ] . V_2 ) ;
if ( V_92 & V_102 [ V_31 ] . type )
V_92 &= ~ V_102 [ V_31 ] . type ;
}
if ( V_26 -> V_103 == V_104 && F_57 () )
V_94 += sprintf ( V_94 , L_22 ) ;
if ( V_94 != V_89 )
V_94 -- ;
* V_94 = '\n' ;
return V_94 + 1 - V_89 ;
}
static int F_65 ( T_1 * V_105 , const char * V_89 )
{
const char * V_94 ;
unsigned V_106 = 0 ;
bool V_107 , V_108 ;
T_1 V_109 ;
int V_31 ;
while ( ( V_94 = F_66 ( ( char * * ) & V_89 , L_23 ) ) != NULL ) {
if ( ! * V_94 )
break;
if ( * V_94 == '+' ) {
V_107 = true ;
V_108 = false ;
V_94 ++ ;
} else if ( * V_94 == '-' ) {
V_107 = false ;
V_108 = true ;
V_94 ++ ;
} else {
V_107 = false ;
V_108 = false ;
}
for ( V_31 = 0 ; V_31 < F_64 ( V_102 ) ; V_31 ++ ) {
if ( ! strcasecmp ( V_94 , V_102 [ V_31 ] . V_2 ) ) {
V_109 = V_102 [ V_31 ] . type ;
break;
}
}
if ( V_31 == F_64 ( V_102 ) ) {
if ( ! strcasecmp ( V_94 , L_24 ) )
V_109 = 0 ;
else {
F_17 ( 1 , L_25 , V_94 ) ;
return - V_48 ;
}
}
V_106 ++ ;
if ( V_107 )
* V_105 |= V_109 ;
else if ( V_108 )
* V_105 &= ~ V_109 ;
else
* V_105 = V_109 ;
}
if ( ! V_106 ) {
F_17 ( 1 , L_26 ) ;
return - V_48 ;
}
return V_106 ;
}
static T_7 F_67 ( struct V_80 * V_80 ,
struct V_87 * V_88 ,
const char * V_89 , T_2 V_22 )
{
struct V_25 * V_26 = F_61 ( V_80 ) ;
struct V_90 * V_91 = F_62 ( V_88 ) ;
T_1 * V_110 ;
int (* F_68)( struct V_25 * V_26 , T_1 * V_10 );
struct V_111 * V_112 ;
int (* F_69)( struct V_25 * V_26 , struct V_111 * V_112 );
T_1 V_113 , V_114 ;
T_7 V_6 ;
if ( ! V_26 )
return - V_48 ;
if ( V_91 -> type == V_95 ) {
F_17 ( 1 , L_27 ) ;
V_110 = & V_26 -> V_96 ;
F_68 = V_26 -> F_68 ;
V_112 = & V_26 -> V_115 ;
F_69 = V_26 -> V_116 ;
} else {
F_17 ( 1 , L_28 ) ;
V_110 = & V_26 -> V_99 ;
F_68 = V_26 -> V_117 ;
V_112 = & V_26 -> V_118 ;
F_69 = V_26 -> V_119 ;
}
if ( ! F_68 ) {
F_17 ( 1 , L_29 ) ;
return - V_48 ;
}
F_49 ( & V_26 -> V_46 ) ;
V_113 = * V_110 ;
V_114 = V_113 ;
V_6 = F_65 ( & V_114 , V_89 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_68 ( V_26 , & V_114 ) ;
if ( V_6 < 0 ) {
F_17 ( 1 , L_30 ,
( long long ) V_114 ) ;
goto V_49;
}
if ( V_114 != V_113 ) {
* V_110 = V_114 ;
F_17 ( 1 , L_31 ,
( long long ) V_114 ) ;
}
if ( F_69 && V_112 -> V_109 ) {
if ( V_114 )
V_6 = F_69 ( V_26 , V_112 ) ;
else
V_6 = - 1 ;
if ( V_6 < 0 ) {
V_112 -> V_120 = 0 ;
V_112 -> V_109 = 0 ;
F_69 ( V_26 , V_112 ) ;
}
}
V_6 = V_22 ;
V_49:
F_50 ( & V_26 -> V_46 ) ;
return V_6 ;
}
static T_7 F_70 ( struct V_80 * V_80 ,
struct V_87 * V_121 ,
char * V_89 )
{
struct V_25 * V_26 = F_61 ( V_80 ) ;
struct V_90 * V_91 = F_62 ( V_121 ) ;
struct V_111 * V_112 ;
T_4 V_122 ;
if ( ! V_26 )
return - V_48 ;
if ( V_91 -> type == V_95 )
V_112 = & V_26 -> V_115 ;
else
V_112 = & V_26 -> V_118 ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_91 -> V_109 )
V_122 = V_112 -> V_109 ;
else
V_122 = V_112 -> V_120 ;
F_50 ( & V_26 -> V_46 ) ;
return sprintf ( V_89 , L_32 , V_122 ) ;
}
static T_7 F_71 ( struct V_80 * V_80 ,
struct V_87 * V_121 ,
const char * V_89 , T_2 V_22 )
{
struct V_25 * V_26 = F_61 ( V_80 ) ;
struct V_90 * V_91 = F_62 ( V_121 ) ;
struct V_111 V_123 , * V_112 ;
int V_124 ;
unsigned long V_122 ;
int (* F_69)( struct V_25 * V_26 , struct V_111 * V_112 );
T_1 * V_96 ;
if ( ! V_26 )
return - V_48 ;
V_124 = F_72 ( V_89 , 0 , & V_122 ) ;
if ( V_124 < 0 )
return V_124 ;
if ( V_91 -> type == V_95 ) {
F_69 = V_26 -> V_116 ;
V_96 = & V_26 -> V_96 ;
V_112 = & V_26 -> V_115 ;
} else {
F_69 = V_26 -> V_119 ;
V_96 = & V_26 -> V_99 ;
V_112 = & V_26 -> V_118 ;
}
if ( ! F_69 )
return - V_48 ;
F_49 ( & V_26 -> V_46 ) ;
V_123 = * V_112 ;
if ( V_91 -> V_109 )
V_123 . V_109 = V_122 ;
else
V_123 . V_120 = V_122 ;
if ( ! * V_96 && V_122 ) {
V_124 = - V_48 ;
goto V_125;
}
V_124 = F_69 ( V_26 , & V_123 ) ;
if ( V_124 < 0 )
goto V_125;
* V_112 = V_123 ;
V_125:
F_50 ( & V_26 -> V_46 ) ;
return ( V_124 < 0 ) ? V_124 : V_22 ;
}
static void F_73 ( struct V_80 * V_80 )
{
}
static int F_74 ( struct V_80 * V_80 , struct V_126 * V_127 )
{
struct V_25 * V_26 = F_61 ( V_80 ) ;
if ( V_26 -> V_5 . V_2 )
F_75 ( L_33 , V_26 -> V_5 . V_2 ) ;
if ( V_26 -> V_128 )
F_75 ( L_34 , V_26 -> V_128 ) ;
return 0 ;
}
struct V_25 * F_76 ( void )
{
struct V_25 * V_26 ;
V_26 = F_77 ( sizeof( * V_26 ) , V_15 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_35 = F_78 () ;
if ( ! V_26 -> V_35 ) {
F_19 ( V_26 ) ;
return NULL ;
}
V_26 -> V_35 -> V_129 = F_32 ;
V_26 -> V_35 -> V_130 = F_25 ;
F_79 ( V_26 -> V_35 , V_26 ) ;
F_80 ( & V_26 -> V_5 . V_46 ) ;
F_80 ( & V_26 -> V_61 ) ;
F_81 ( & V_26 -> V_46 ) ;
F_82 ( & V_26 -> V_69 , F_39 , ( unsigned long ) V_26 ) ;
V_26 -> V_26 . type = & V_131 ;
V_26 -> V_26 . V_132 = & V_133 ;
F_83 ( & V_26 -> V_26 ) ;
F_84 ( V_134 ) ;
return V_26 ;
}
void F_85 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
F_86 ( V_26 -> V_35 ) ;
F_87 ( & V_26 -> V_26 ) ;
F_19 ( V_26 ) ;
F_88 ( V_134 ) ;
}
int F_89 ( struct V_25 * V_26 )
{
static bool V_135 = false ;
struct V_5 * V_5 ;
const char * V_136 ;
int V_121 = 0 ;
int V_137 ;
int V_6 ;
if ( ! V_26 || ! V_26 -> V_138 )
return - V_48 ;
V_5 = F_5 ( V_26 -> V_138 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_139 ) ;
if ( ! V_5 || ! V_5 -> V_14 || V_5 -> V_11 == 0 )
return - V_48 ;
F_90 ( V_140 , V_26 -> V_35 -> V_141 ) ;
F_90 ( V_142 , V_26 -> V_35 -> V_141 ) ;
F_90 ( V_64 , V_26 -> V_35 -> V_141 ) ;
F_90 ( V_65 , V_26 -> V_35 -> V_143 ) ;
if ( V_26 -> V_78 )
V_26 -> V_35 -> V_78 = F_51 ;
if ( V_26 -> V_79 )
V_26 -> V_35 -> V_79 = F_53 ;
V_137 = F_91 ( & V_144 , 0 , V_145 , V_15 ) ;
if ( V_137 < 0 )
return V_137 ;
V_26 -> V_137 = V_137 ;
F_92 ( & V_26 -> V_26 , L_35 , V_26 -> V_137 ) ;
F_93 ( & V_26 -> V_26 , V_26 ) ;
V_26 -> V_26 . V_146 = V_26 -> V_147 ;
V_26 -> V_147 [ V_121 ++ ] = & V_148 ;
if ( V_26 -> V_116 )
V_26 -> V_147 [ V_121 ++ ] = & V_149 ;
if ( V_26 -> V_119 )
V_26 -> V_147 [ V_121 ++ ] = & V_150 ;
if ( V_26 -> V_117 )
V_26 -> V_147 [ V_121 ++ ] = & V_151 ;
V_26 -> V_147 [ V_121 ++ ] = NULL ;
F_49 ( & V_26 -> V_46 ) ;
V_6 = F_94 ( & V_26 -> V_26 ) ;
if ( V_6 )
goto V_152;
V_6 = F_30 ( V_26 , V_5 ) ;
if ( V_6 )
goto V_153;
V_26 -> V_35 -> V_26 . V_154 = & V_26 -> V_26 ;
memcpy ( & V_26 -> V_35 -> V_155 , & V_26 -> V_156 , sizeof( V_26 -> V_156 ) ) ;
V_26 -> V_35 -> V_157 = V_26 -> V_158 ;
V_26 -> V_35 -> V_2 = V_26 -> V_55 ;
F_50 ( & V_26 -> V_46 ) ;
V_6 = F_95 ( V_26 -> V_35 ) ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_6 )
goto V_159;
V_26 -> V_35 -> V_160 [ V_161 ] = 500 ;
V_26 -> V_35 -> V_160 [ V_162 ] = 125 ;
V_136 = F_96 ( & V_26 -> V_26 . V_163 , V_15 ) ;
F_8 ( V_8 L_36 ,
F_56 ( & V_26 -> V_26 ) ,
V_26 -> V_55 ? V_26 -> V_55 : L_37 ,
V_136 ? V_136 : L_38 ) ;
F_19 ( V_136 ) ;
if ( V_26 -> V_103 == V_104 ) {
if ( ! V_135 ) {
F_17 ( 1 , L_39 ) ;
F_97 () ;
V_135 = true ;
}
F_50 ( & V_26 -> V_46 ) ;
V_6 = F_98 ( V_26 ) ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_6 < 0 )
goto V_164;
}
if ( V_26 -> F_68 ) {
T_1 V_10 = ( 1ll << V_5 -> V_10 ) ;
V_6 = V_26 -> F_68 ( V_26 , & V_10 ) ;
if ( V_6 < 0 )
goto V_165;
V_26 -> V_96 = V_10 ;
}
F_50 ( & V_26 -> V_46 ) ;
F_17 ( 1 , L_40 ,
V_26 -> V_137 ,
V_26 -> V_128 ? V_26 -> V_128 : L_41 ,
V_5 -> V_2 ? V_5 -> V_2 : L_41 ,
V_26 -> V_103 == V_104 ? L_42 : L_43 ) ;
return 0 ;
V_165:
if ( V_26 -> V_103 == V_104 )
F_99 ( V_26 ) ;
V_164:
F_100 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
V_159:
F_18 ( & V_26 -> V_5 ) ;
V_153:
F_101 ( & V_26 -> V_26 ) ;
V_152:
F_50 ( & V_26 -> V_46 ) ;
F_102 ( & V_144 , V_137 ) ;
return V_6 ;
}
void F_103 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
F_104 ( & V_26 -> V_69 ) ;
if ( V_26 -> V_103 == V_104 )
F_99 ( V_26 ) ;
F_18 ( & V_26 -> V_5 ) ;
F_17 ( 1 , L_44 ) ;
F_100 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
F_101 ( & V_26 -> V_26 ) ;
F_102 ( & V_144 , V_26 -> V_137 ) ;
F_85 ( V_26 ) ;
}
static int T_8 F_105 ( void )
{
int V_6 = F_106 ( & V_133 ) ;
if ( V_6 ) {
F_8 ( V_7 L_45 ) ;
return V_6 ;
}
F_107 ( L_46 , & V_59 ) ;
F_10 ( & V_166 ) ;
return 0 ;
}
static void T_9 F_108 ( void )
{
F_109 ( & V_133 ) ;
F_110 ( V_59 ) ;
F_12 ( & V_166 ) ;
}
