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
F_8 ( L_2 , V_2 ) ;
return NULL ;
}
F_9 ( 20 ) ;
V_3 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_3 ) {
F_8 ( L_3 , V_2 ) ;
return NULL ;
}
F_10 ( V_7 L_4 , V_3 -> V_3 . V_2 ) ;
return & V_3 -> V_3 ;
}
int F_11 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_12 ( & V_3 -> V_8 , & V_1 ) ;
F_4 ( & V_4 ) ;
return 0 ;
}
void F_13 ( struct V_1 * V_3 )
{
F_2 ( & V_4 ) ;
F_14 ( & V_3 -> V_8 ) ;
F_4 ( & V_4 ) ;
}
static int F_15 ( struct V_5 * V_5 ,
const char * V_2 , T_1 V_9 , T_2 V_10 )
{
V_5 -> V_2 = F_16 ( V_2 , V_11 ) ;
if ( ! V_5 -> V_2 )
return - V_12 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_13 = F_17 ( V_10 * sizeof( struct V_14 ) ) ;
V_5 -> V_10 = V_5 -> V_13 / sizeof( struct V_14 ) ;
V_5 -> V_15 = F_18 ( V_5 -> V_13 , V_11 ) ;
if ( ! V_5 -> V_15 ) {
F_19 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
return - V_12 ;
}
F_20 ( 1 , L_5 ,
V_5 -> V_10 , V_5 -> V_13 ) ;
return 0 ;
}
static void F_21 ( struct V_5 * V_5 )
{
V_5 -> V_10 = 0 ;
F_19 ( V_5 -> V_2 ) ;
V_5 -> V_2 = NULL ;
F_19 ( V_5 -> V_15 ) ;
V_5 -> V_15 = NULL ;
}
static int F_22 ( struct V_5 * V_5 , T_3 V_16 )
{
unsigned int V_17 = V_5 -> V_13 ;
unsigned int V_18 = V_17 ;
struct V_14 * V_19 = V_5 -> V_15 ;
struct V_14 * V_20 ;
if ( V_5 -> V_10 == V_5 -> V_21 ) {
if ( V_5 -> V_13 >= V_22 )
return - V_12 ;
V_18 *= 2 ;
F_20 ( 1 , L_6 , V_18 ) ;
}
if ( ( V_5 -> V_21 * 3 < V_5 -> V_10 ) && ( V_17 > V_23 ) ) {
V_18 /= 2 ;
F_20 ( 1 , L_7 , V_18 ) ;
}
if ( V_18 == V_17 )
return 0 ;
V_20 = F_18 ( V_18 , V_16 ) ;
if ( ! V_20 ) {
F_20 ( 1 , L_8 , V_18 ) ;
return - V_12 ;
}
memcpy ( V_20 , V_5 -> V_15 , V_5 -> V_21 * sizeof( struct V_14 ) ) ;
V_5 -> V_15 = V_20 ;
V_5 -> V_13 = V_18 ;
V_5 -> V_10 = V_5 -> V_13 / sizeof( struct V_14 ) ;
F_19 ( V_19 ) ;
return 0 ;
}
static unsigned int F_23 ( struct V_24 * V_25 ,
struct V_5 * V_5 ,
unsigned int V_26 ,
unsigned int V_27 )
{
int V_28 = V_5 -> V_15 [ V_26 ] . V_29 ;
int V_30 ;
if ( V_27 == V_31 || V_27 == V_32 ) {
F_20 ( 1 , L_9 ,
V_26 , V_5 -> V_15 [ V_26 ] . V_33 ) ;
V_5 -> V_21 -- ;
memmove ( & V_5 -> V_15 [ V_26 ] , & V_5 -> V_15 [ V_26 + 1 ] ,
( V_5 -> V_21 - V_26 ) * sizeof( struct V_14 ) ) ;
} else {
F_20 ( 1 , L_10 ,
V_26 ,
V_28 == V_31 ? L_11 : L_12 ,
V_5 -> V_15 [ V_26 ] . V_33 , V_27 ) ;
V_5 -> V_15 [ V_26 ] . V_29 = V_27 ;
F_24 ( V_27 , V_25 -> V_34 -> V_35 ) ;
}
if ( V_28 != V_31 ) {
F_25 ( V_28 , V_25 -> V_34 -> V_35 ) ;
for ( V_30 = 0 ; V_30 < V_5 -> V_21 ; V_30 ++ ) {
if ( V_5 -> V_15 [ V_30 ] . V_29 == V_28 ) {
F_24 ( V_28 , V_25 -> V_34 -> V_35 ) ;
break;
}
}
F_22 ( V_5 , V_36 ) ;
}
return V_28 ;
}
static unsigned int F_26 ( struct V_24 * V_25 ,
struct V_5 * V_5 ,
unsigned int V_33 ,
bool V_37 )
{
unsigned int V_30 ;
if ( V_25 -> V_38 )
V_33 &= V_25 -> V_38 ;
for ( V_30 = 0 ; V_30 < V_5 -> V_21 ; V_30 ++ ) {
if ( V_5 -> V_15 [ V_30 ] . V_33 == V_33 )
return V_30 ;
if ( V_5 -> V_15 [ V_30 ] . V_33 >= V_33 )
break;
}
if ( V_5 -> V_10 == V_5 -> V_21 ) {
if ( ! V_37 || F_22 ( V_5 , V_36 ) )
return - 1U ;
}
if ( V_30 < V_5 -> V_21 )
memmove ( & V_5 -> V_15 [ V_30 + 1 ] , & V_5 -> V_15 [ V_30 ] ,
( V_5 -> V_21 - V_30 ) * sizeof( struct V_14 ) ) ;
V_5 -> V_15 [ V_30 ] . V_33 = V_33 ;
V_5 -> V_15 [ V_30 ] . V_29 = V_31 ;
V_5 -> V_21 ++ ;
return V_30 ;
}
static int F_27 ( struct V_34 * V_39 ,
const struct V_40 * V_41 ,
unsigned int * V_28 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
struct V_5 * V_5 = & V_42 -> V_5 ;
unsigned int V_26 ;
unsigned int V_33 ;
int V_43 = 0 ;
unsigned long V_44 ;
F_29 ( & V_5 -> V_45 , V_44 ) ;
if ( V_41 -> V_44 & V_46 ) {
V_26 = V_41 -> V_26 ;
if ( V_26 >= V_5 -> V_21 ) {
V_43 = - V_47 ;
goto V_48;
}
} else {
V_43 = F_30 ( V_41 , & V_33 ) ;
if ( V_43 )
goto V_48;
V_26 = F_26 ( V_42 , V_5 , V_33 , true ) ;
if ( V_26 >= V_5 -> V_21 ) {
V_43 = - V_12 ;
goto V_48;
}
}
* V_28 = F_23 ( V_42 , V_5 , V_26 , V_41 -> V_29 ) ;
V_48:
F_31 ( & V_5 -> V_45 , V_44 ) ;
return V_43 ;
}
static int F_32 ( struct V_24 * V_25 ,
const struct V_5 * V_49 )
{
struct V_5 * V_5 = & V_25 -> V_5 ;
unsigned int V_30 , V_26 ;
int V_6 ;
V_6 = F_15 ( V_5 , V_49 -> V_2 ,
V_49 -> V_9 , V_49 -> V_10 ) ;
if ( V_6 )
return V_6 ;
F_20 ( 1 , L_5 ,
V_5 -> V_10 , V_5 -> V_13 ) ;
for ( V_30 = 0 ; V_30 < V_49 -> V_10 ; V_30 ++ ) {
V_26 = F_26 ( V_25 , V_5 ,
V_49 -> V_15 [ V_30 ] . V_33 , false ) ;
if ( V_26 >= V_5 -> V_21 ) {
V_6 = - V_12 ;
break;
}
F_23 ( V_25 , V_5 , V_26 ,
V_49 -> V_15 [ V_30 ] . V_29 ) ;
}
if ( V_6 )
F_21 ( V_5 ) ;
return V_6 ;
}
static unsigned int F_33 ( const struct V_5 * V_5 ,
unsigned int V_33 )
{
int V_50 = 0 ;
int V_51 = V_5 -> V_21 - 1 ;
int V_52 ;
while ( V_50 <= V_51 ) {
V_52 = ( V_50 + V_51 ) / 2 ;
if ( V_5 -> V_15 [ V_52 ] . V_33 < V_33 )
V_50 = V_52 + 1 ;
else if ( V_5 -> V_15 [ V_52 ] . V_33 > V_33 )
V_51 = V_52 - 1 ;
else
return V_52 ;
}
return - 1U ;
}
static int F_34 ( struct V_34 * V_39 ,
struct V_40 * V_41 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
struct V_5 * V_5 = & V_42 -> V_5 ;
struct V_14 * V_53 ;
unsigned long V_44 ;
unsigned int V_26 ;
unsigned int V_33 ;
int V_43 ;
F_29 ( & V_5 -> V_45 , V_44 ) ;
if ( V_41 -> V_44 & V_46 ) {
V_26 = V_41 -> V_26 ;
} else {
V_43 = F_30 ( V_41 , & V_33 ) ;
if ( V_43 )
goto V_48;
V_26 = F_33 ( V_5 , V_33 ) ;
}
if ( V_26 < V_5 -> V_21 ) {
V_53 = & V_5 -> V_15 [ V_26 ] ;
V_41 -> V_26 = V_26 ;
V_41 -> V_29 = V_53 -> V_29 ;
V_41 -> V_21 = sizeof( V_53 -> V_33 ) ;
memcpy ( V_41 -> V_33 , & V_53 -> V_33 , sizeof( V_53 -> V_33 ) ) ;
} else if ( ! ( V_41 -> V_44 & V_46 ) ) {
V_41 -> V_26 = V_26 ;
V_41 -> V_29 = V_31 ;
} else {
V_43 = - V_47 ;
goto V_48;
}
V_43 = 0 ;
V_48:
F_31 ( & V_5 -> V_45 , V_44 ) ;
return V_43 ;
}
T_4 F_35 ( struct V_24 * V_25 , T_4 V_33 )
{
struct V_5 * V_5 = & V_25 -> V_5 ;
unsigned int V_29 ;
unsigned int V_26 ;
unsigned long V_44 ;
F_29 ( & V_5 -> V_45 , V_44 ) ;
V_26 = F_33 ( V_5 , V_33 ) ;
V_29 = V_26 < V_5 -> V_21 ?
V_5 -> V_15 [ V_26 ] . V_29 : V_31 ;
F_31 ( & V_5 -> V_45 , V_44 ) ;
if ( V_29 != V_31 )
F_20 ( 1 , L_13 ,
V_25 -> V_54 , V_33 , V_29 ) ;
return V_29 ;
}
static void F_36 ( struct V_24 * V_25 , bool V_55 )
{
if ( ! V_25 -> V_56 )
return;
F_20 ( 1 , L_14 , V_25 -> V_57 ) ;
F_37 ( V_25 -> V_34 , V_25 -> V_57 , 0 ) ;
F_38 ( V_58 , V_59 ) ;
if ( V_55 )
F_39 ( V_25 -> V_34 ) ;
V_25 -> V_56 = false ;
}
void F_40 ( struct V_24 * V_25 )
{
unsigned long V_44 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_36 ( V_25 , true ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static void F_41 ( unsigned long V_61 )
{
struct V_24 * V_25 = (struct V_24 * ) V_61 ;
unsigned long V_44 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
if ( F_42 ( V_25 -> V_62 ) )
F_36 ( V_25 , true ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
void F_43 ( struct V_24 * V_25 )
{
unsigned long V_44 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_44 ( V_25 -> V_34 , V_63 , V_64 , V_25 -> V_65 ) ;
F_39 ( V_25 -> V_34 ) ;
if ( ! V_25 -> V_56 )
goto V_48;
V_25 -> V_62 = V_66 + F_45 ( V_67 ) ;
F_46 ( & V_25 -> V_68 , V_25 -> V_62 ) ;
V_48:
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static void F_47 ( struct V_24 * V_25 , enum V_9 V_69 ,
T_4 V_33 , T_4 V_29 , T_5 V_70 )
{
bool V_71 = ( ! V_25 -> V_56 ||
V_25 -> V_72 != V_69 ||
V_25 -> V_65 != V_33 ||
V_25 -> V_73 != V_70 ) ;
if ( V_71 && V_25 -> V_56 )
F_36 ( V_25 , false ) ;
F_44 ( V_25 -> V_34 , V_63 , V_64 , V_33 ) ;
if ( V_71 && V_29 != V_31 ) {
V_25 -> V_56 = true ;
V_25 -> V_72 = V_69 ;
V_25 -> V_65 = V_33 ;
V_25 -> V_73 = V_70 ;
V_25 -> V_57 = V_29 ;
F_20 ( 1 , L_15 ,
V_25 -> V_54 , V_29 , V_69 , V_33 ) ;
F_37 ( V_25 -> V_34 , V_29 , 1 ) ;
F_38 ( V_58 , V_74 ) ;
}
F_39 ( V_25 -> V_34 ) ;
}
void F_48 ( struct V_24 * V_25 , enum V_9 V_69 , T_4 V_33 , T_5 V_70 )
{
unsigned long V_44 ;
T_4 V_29 = F_35 ( V_25 , V_33 ) ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_47 ( V_25 , V_69 , V_33 , V_29 , V_70 ) ;
if ( V_25 -> V_56 ) {
V_25 -> V_62 = V_66 + F_45 ( V_67 ) ;
F_46 ( & V_25 -> V_68 , V_25 -> V_62 ) ;
}
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
void F_49 ( struct V_24 * V_25 , enum V_9 V_69 ,
T_4 V_33 , T_5 V_70 )
{
unsigned long V_44 ;
T_4 V_29 = F_35 ( V_25 , V_33 ) ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_47 ( V_25 , V_69 , V_33 , V_29 , V_70 ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
int F_50 ( struct V_24 * V_42 )
{
int V_75 = 0 ;
if ( ! V_42 )
return - V_47 ;
F_51 ( & V_42 -> V_45 ) ;
if ( ! V_42 -> V_76 ++ && V_42 -> V_77 != NULL )
V_75 = V_42 -> V_77 ( V_42 ) ;
if ( V_75 )
V_42 -> V_76 -- ;
F_52 ( & V_42 -> V_45 ) ;
return V_75 ;
}
static int F_53 ( struct V_34 * V_39 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
return F_50 ( V_42 ) ;
}
void F_54 ( struct V_24 * V_42 )
{
if ( V_42 ) {
F_51 ( & V_42 -> V_45 ) ;
if ( ! -- V_42 -> V_76 && V_42 -> V_78 != NULL )
V_42 -> V_78 ( V_42 ) ;
F_52 ( & V_42 -> V_45 ) ;
}
}
static void F_55 ( struct V_34 * V_39 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
F_54 ( V_42 ) ;
}
static char * F_56 ( struct V_79 * V_25 , T_6 * V_80 )
{
return F_57 ( V_11 , L_16 , F_58 ( V_25 ) ) ;
}
static bool F_59 ( void )
{
#if F_60 ( V_81 )
struct V_82 * V_83 ;
F_51 ( & V_84 ) ;
V_83 = F_61 ( L_17 ) ;
F_52 ( & V_84 ) ;
return V_83 ? true : false ;
#elif F_60 ( V_85 )
return true ;
#else
return false ;
#endif
}
static T_7 F_62 ( struct V_79 * V_79 ,
struct V_86 * V_87 , char * V_88 )
{
struct V_24 * V_25 = F_63 ( V_79 ) ;
struct V_89 * V_90 = F_64 ( V_87 ) ;
T_1 V_91 , V_92 ;
char * V_93 = V_88 ;
int V_30 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_94 ) )
return - V_95 ;
F_51 ( & V_25 -> V_45 ) ;
if ( V_90 -> type == V_96 ) {
V_92 = V_25 -> V_97 ;
V_91 = V_25 -> V_98 ;
if ( V_25 -> V_99 && ! V_91 )
V_91 = F_66 () ;
} else {
V_92 = V_25 -> V_100 ;
V_91 = V_25 -> V_101 ;
}
F_52 ( & V_25 -> V_45 ) ;
F_20 ( 1 , L_18 ,
V_102 , ( long long ) V_91 , ( long long ) V_92 ) ;
for ( V_30 = 0 ; V_30 < F_67 ( V_103 ) ; V_30 ++ ) {
if ( V_91 & V_92 & V_103 [ V_30 ] . type )
V_93 += sprintf ( V_93 , L_19 , V_103 [ V_30 ] . V_2 ) ;
else if ( V_91 & V_103 [ V_30 ] . type )
V_93 += sprintf ( V_93 , L_20 , V_103 [ V_30 ] . V_2 ) ;
if ( V_91 & V_103 [ V_30 ] . type )
V_91 &= ~ V_103 [ V_30 ] . type ;
}
if ( V_25 -> V_104 == V_105 && F_59 () )
V_93 += sprintf ( V_93 , L_21 ) ;
if ( V_93 != V_88 )
V_93 -- ;
* V_93 = '\n' ;
return V_93 + 1 - V_88 ;
}
static int F_68 ( T_1 * V_106 , const char * V_88 )
{
const char * V_93 ;
unsigned V_107 = 0 ;
bool V_108 , V_109 ;
T_1 V_110 ;
int V_30 ;
while ( ( V_93 = F_69 ( ( char * * ) & V_88 , L_22 ) ) != NULL ) {
if ( ! * V_93 )
break;
if ( * V_93 == '+' ) {
V_108 = true ;
V_109 = false ;
V_93 ++ ;
} else if ( * V_93 == '-' ) {
V_108 = false ;
V_109 = true ;
V_93 ++ ;
} else {
V_108 = false ;
V_109 = false ;
}
for ( V_30 = 0 ; V_30 < F_67 ( V_103 ) ; V_30 ++ ) {
if ( ! strcasecmp ( V_93 , V_103 [ V_30 ] . V_2 ) ) {
V_110 = V_103 [ V_30 ] . type ;
break;
}
}
if ( V_30 == F_67 ( V_103 ) ) {
if ( ! strcasecmp ( V_93 , L_23 ) )
V_110 = 0 ;
else {
F_20 ( 1 , L_24 , V_93 ) ;
return - V_47 ;
}
}
V_107 ++ ;
if ( V_108 )
* V_106 |= V_110 ;
else if ( V_109 )
* V_106 &= ~ V_110 ;
else
* V_106 = V_110 ;
}
if ( ! V_107 ) {
F_20 ( 1 , L_25 ) ;
return - V_47 ;
}
return V_107 ;
}
static void F_70 ( T_1 * V_106 )
{
T_1 V_111 ;
int V_30 , V_112 ;
for ( V_30 = 0 ; V_30 < F_67 ( V_103 ) ; V_30 ++ ) {
if ( V_103 [ V_30 ] . type == V_113 ||
V_103 [ V_30 ] . type & ( V_114 | V_115 ) )
continue;
V_111 = F_66 () ;
if ( ! ( * V_106 & V_103 [ V_30 ] . type & ~ V_111 ) )
continue;
if ( ! V_103 [ V_30 ] . V_116 ) {
F_8 ( L_26 ,
V_103 [ V_30 ] . V_2 ) ;
* V_106 &= ~ V_103 [ V_30 ] . type ;
continue;
}
V_112 = F_7 ( L_1 , V_103 [ V_30 ] . V_116 ) ;
if ( V_112 < 0 ) {
F_8 ( L_27 ,
V_103 [ V_30 ] . V_116 ) ;
* V_106 &= ~ V_103 [ V_30 ] . type ;
continue;
}
F_9 ( 20 ) ;
V_111 = F_66 () ;
if ( ! ( * V_106 & V_103 [ V_30 ] . type & ~ V_111 ) )
continue;
F_8 ( L_28 ,
V_103 [ V_30 ] . V_116 ,
V_103 [ V_30 ] . V_2 ) ;
* V_106 &= ~ V_103 [ V_30 ] . type ;
}
}
static T_7 F_71 ( struct V_79 * V_79 ,
struct V_86 * V_87 ,
const char * V_88 , T_2 V_21 )
{
struct V_24 * V_25 = F_63 ( V_79 ) ;
struct V_89 * V_90 = F_64 ( V_87 ) ;
T_1 * V_117 ;
int (* F_72)( struct V_24 * V_25 , T_1 * V_9 );
struct V_118 * V_119 ;
int (* F_73)( struct V_24 * V_25 , struct V_118 * V_119 );
T_1 V_120 , V_121 ;
T_7 V_6 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_94 ) )
return - V_95 ;
if ( V_90 -> type == V_96 ) {
F_20 ( 1 , L_29 ) ;
V_117 = & V_25 -> V_97 ;
F_72 = V_25 -> F_72 ;
V_119 = & V_25 -> V_122 ;
F_73 = V_25 -> V_123 ;
} else {
F_20 ( 1 , L_30 ) ;
V_117 = & V_25 -> V_100 ;
F_72 = V_25 -> V_124 ;
V_119 = & V_25 -> V_125 ;
F_73 = V_25 -> V_126 ;
}
if ( ! F_72 ) {
F_20 ( 1 , L_31 ) ;
return - V_47 ;
}
F_51 ( & V_25 -> V_45 ) ;
V_120 = * V_117 ;
V_121 = V_120 ;
V_6 = F_68 ( & V_121 , V_88 ) ;
if ( V_6 < 0 )
goto V_48;
V_6 = F_72 ( V_25 , & V_121 ) ;
if ( V_6 < 0 ) {
F_20 ( 1 , L_32 ,
( long long ) V_121 ) ;
goto V_48;
}
if ( V_25 -> V_104 == V_105 )
F_70 ( & V_121 ) ;
if ( V_121 != V_120 ) {
* V_117 = V_121 ;
F_20 ( 1 , L_33 ,
( long long ) V_121 ) ;
}
if ( F_73 && V_119 -> V_110 ) {
if ( V_121 )
V_6 = F_73 ( V_25 , V_119 ) ;
else
V_6 = - 1 ;
if ( V_6 < 0 ) {
V_119 -> V_127 = 0 ;
V_119 -> V_110 = 0 ;
F_73 ( V_25 , V_119 ) ;
}
}
V_6 = V_21 ;
V_48:
F_52 ( & V_25 -> V_45 ) ;
return V_6 ;
}
static T_7 F_74 ( struct V_79 * V_79 ,
struct V_86 * V_128 ,
char * V_88 )
{
struct V_24 * V_25 = F_63 ( V_79 ) ;
struct V_89 * V_90 = F_64 ( V_128 ) ;
struct V_118 * V_119 ;
T_4 V_129 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_94 ) )
return - V_95 ;
F_51 ( & V_25 -> V_45 ) ;
if ( V_90 -> type == V_96 )
V_119 = & V_25 -> V_122 ;
else
V_119 = & V_25 -> V_125 ;
if ( V_90 -> V_110 )
V_129 = V_119 -> V_110 ;
else
V_129 = V_119 -> V_127 ;
F_52 ( & V_25 -> V_45 ) ;
return sprintf ( V_88 , L_34 , V_129 ) ;
}
static T_7 F_75 ( struct V_79 * V_79 ,
struct V_86 * V_128 ,
const char * V_88 , T_2 V_21 )
{
struct V_24 * V_25 = F_63 ( V_79 ) ;
struct V_89 * V_90 = F_64 ( V_128 ) ;
struct V_118 V_130 , * V_119 ;
int V_112 ;
unsigned long V_129 ;
int (* F_73)( struct V_24 * V_25 , struct V_118 * V_119 );
T_1 * V_97 ;
if ( ! V_25 )
return - V_47 ;
if ( ! F_65 ( & V_25 -> V_94 ) )
return - V_95 ;
V_112 = F_76 ( V_88 , 0 , & V_129 ) ;
if ( V_112 < 0 )
return V_112 ;
if ( V_90 -> type == V_96 ) {
F_73 = V_25 -> V_123 ;
V_97 = & V_25 -> V_97 ;
V_119 = & V_25 -> V_122 ;
} else {
F_73 = V_25 -> V_126 ;
V_97 = & V_25 -> V_100 ;
V_119 = & V_25 -> V_125 ;
}
if ( ! F_73 )
return - V_47 ;
F_51 ( & V_25 -> V_45 ) ;
V_130 = * V_119 ;
if ( V_90 -> V_110 )
V_130 . V_110 = V_129 ;
else
V_130 . V_127 = V_129 ;
if ( ! * V_97 && V_129 ) {
V_112 = - V_47 ;
goto V_131;
}
V_112 = F_73 ( V_25 , & V_130 ) ;
if ( V_112 < 0 )
goto V_131;
* V_119 = V_130 ;
V_131:
F_52 ( & V_25 -> V_45 ) ;
return ( V_112 < 0 ) ? V_112 : V_21 ;
}
static void F_77 ( struct V_79 * V_79 )
{
struct V_24 * V_25 = F_63 ( V_79 ) ;
F_19 ( V_25 ) ;
}
static int F_78 ( struct V_79 * V_79 , struct V_132 * V_133 )
{
struct V_24 * V_25 = F_63 ( V_79 ) ;
if ( V_25 -> V_5 . V_2 )
F_79 ( L_35 , V_25 -> V_5 . V_2 ) ;
if ( V_25 -> V_134 )
F_79 ( L_36 , V_25 -> V_134 ) ;
return 0 ;
}
struct V_24 * F_80 ( void )
{
struct V_24 * V_25 ;
V_25 = F_81 ( sizeof( * V_25 ) , V_11 ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_34 = F_82 () ;
if ( ! V_25 -> V_34 ) {
F_19 ( V_25 ) ;
return NULL ;
}
V_25 -> V_34 -> V_135 = F_34 ;
V_25 -> V_34 -> V_136 = F_27 ;
F_83 ( V_25 -> V_34 , V_25 ) ;
F_84 ( & V_25 -> V_5 . V_45 ) ;
F_84 ( & V_25 -> V_60 ) ;
F_85 ( & V_25 -> V_45 ) ;
F_86 ( & V_25 -> V_68 , F_41 , ( unsigned long ) V_25 ) ;
V_25 -> V_25 . type = & V_137 ;
V_25 -> V_25 . V_138 = & V_139 ;
F_87 ( & V_25 -> V_25 ) ;
F_88 ( V_140 ) ;
return V_25 ;
}
void F_89 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_90 ( V_25 -> V_34 ) ;
F_91 ( & V_25 -> V_25 ) ;
F_92 ( V_140 ) ;
}
static void F_93 ( struct V_79 * V_25 , void * V_141 )
{
F_89 ( * (struct V_24 * * ) V_141 ) ;
}
struct V_24 * F_94 ( struct V_79 * V_25 )
{
struct V_24 * * V_142 , * V_6 ;
V_142 = F_95 ( F_93 , sizeof( * V_142 ) , V_11 ) ;
if ( ! V_142 )
return NULL ;
V_6 = F_80 () ;
if ( ! V_6 ) {
F_96 ( V_142 ) ;
return NULL ;
}
V_6 -> V_25 . V_143 = V_25 ;
V_6 -> V_144 = true ;
* V_142 = V_6 ;
F_97 ( V_25 , V_142 ) ;
return V_6 ;
}
int F_98 ( struct V_24 * V_25 )
{
static bool V_145 = false ;
struct V_5 * V_5 ;
const char * V_146 ;
int V_128 = 0 ;
int V_147 ;
int V_6 ;
if ( ! V_25 || ! V_25 -> V_148 )
return - V_47 ;
V_5 = F_5 ( V_25 -> V_148 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_149 ) ;
if ( ! V_5 || ! V_5 -> V_15 || V_5 -> V_10 == 0 )
return - V_47 ;
F_99 ( V_150 , V_25 -> V_34 -> V_151 ) ;
F_99 ( V_152 , V_25 -> V_34 -> V_151 ) ;
F_99 ( V_63 , V_25 -> V_34 -> V_151 ) ;
F_99 ( V_64 , V_25 -> V_34 -> V_153 ) ;
if ( V_25 -> V_77 )
V_25 -> V_34 -> V_77 = F_53 ;
if ( V_25 -> V_78 )
V_25 -> V_34 -> V_78 = F_55 ;
V_147 = F_100 ( & V_154 , 0 , V_155 , V_11 ) ;
if ( V_147 < 0 )
return V_147 ;
V_25 -> V_147 = V_147 ;
F_101 ( & V_25 -> V_25 , L_37 , V_25 -> V_147 ) ;
F_102 ( & V_25 -> V_25 , V_25 ) ;
F_103 ( & V_25 -> V_94 , 0 ) ;
V_25 -> V_25 . V_156 = V_25 -> V_157 ;
V_25 -> V_157 [ V_128 ++ ] = & V_158 ;
if ( V_25 -> V_123 )
V_25 -> V_157 [ V_128 ++ ] = & V_159 ;
if ( V_25 -> V_126 )
V_25 -> V_157 [ V_128 ++ ] = & V_160 ;
if ( V_25 -> V_124 )
V_25 -> V_157 [ V_128 ++ ] = & V_161 ;
V_25 -> V_157 [ V_128 ++ ] = NULL ;
V_6 = F_104 ( & V_25 -> V_25 ) ;
if ( V_6 )
goto V_162;
V_6 = F_32 ( V_25 , V_5 ) ;
if ( V_6 )
goto V_163;
V_25 -> V_34 -> V_25 . V_143 = & V_25 -> V_25 ;
memcpy ( & V_25 -> V_34 -> V_164 , & V_25 -> V_165 , sizeof( V_25 -> V_165 ) ) ;
V_25 -> V_34 -> V_166 = V_25 -> V_167 ;
V_25 -> V_34 -> V_2 = V_25 -> V_54 ;
V_6 = F_105 ( V_25 -> V_34 ) ;
if ( V_6 )
goto V_168;
V_25 -> V_34 -> V_169 [ V_170 ] = 500 ;
V_25 -> V_34 -> V_169 [ V_171 ] = 125 ;
V_146 = F_106 ( & V_25 -> V_25 . V_172 , V_11 ) ;
F_107 ( & V_25 -> V_25 , L_38 ,
V_25 -> V_54 ? : L_39 , V_146 ? : L_40 ) ;
F_19 ( V_146 ) ;
if ( V_25 -> V_104 == V_105 ) {
if ( ! V_145 ) {
F_108 ( L_41 ) ;
V_145 = true ;
}
V_6 = F_109 ( V_25 ) ;
if ( V_6 < 0 )
goto V_173;
}
if ( V_25 -> F_72 ) {
T_1 V_9 = ( 1ll << V_5 -> V_9 ) ;
V_6 = V_25 -> F_72 ( V_25 , & V_9 ) ;
if ( V_6 < 0 )
goto V_174;
V_25 -> V_97 = V_9 ;
}
F_103 ( & V_25 -> V_94 , 1 ) ;
F_20 ( 1 , L_42 ,
V_25 -> V_147 ,
V_25 -> V_134 ? V_25 -> V_134 : L_43 ,
V_5 -> V_2 ? V_5 -> V_2 : L_43 ,
V_25 -> V_104 == V_105 ? L_44 : L_45 ) ;
return 0 ;
V_174:
if ( V_25 -> V_104 == V_105 )
F_110 ( V_25 ) ;
V_173:
F_111 ( V_25 -> V_34 ) ;
V_25 -> V_34 = NULL ;
V_168:
F_21 ( & V_25 -> V_5 ) ;
V_163:
F_112 ( & V_25 -> V_25 ) ;
V_162:
F_113 ( & V_154 , V_147 ) ;
return V_6 ;
}
static void F_114 ( struct V_79 * V_25 , void * V_141 )
{
F_115 ( * (struct V_24 * * ) V_141 ) ;
}
int F_116 ( struct V_79 * V_143 , struct V_24 * V_25 )
{
struct V_24 * * V_142 ;
int V_112 ;
V_142 = F_95 ( F_114 , sizeof( * V_142 ) , V_11 ) ;
if ( ! V_142 )
return - V_12 ;
V_112 = F_98 ( V_25 ) ;
if ( V_112 ) {
F_96 ( V_142 ) ;
return V_112 ;
}
* V_142 = V_25 ;
F_97 ( V_143 , V_142 ) ;
return 0 ;
}
void F_115 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_117 ( & V_25 -> V_68 ) ;
if ( V_25 -> V_104 == V_105 )
F_110 ( V_25 ) ;
F_21 ( & V_25 -> V_5 ) ;
F_20 ( 1 , L_46 ) ;
F_111 ( V_25 -> V_34 ) ;
V_25 -> V_34 = NULL ;
F_112 ( & V_25 -> V_25 ) ;
F_113 ( & V_154 , V_25 -> V_147 ) ;
if ( ! V_25 -> V_144 )
F_89 ( V_25 ) ;
}
static int T_8 F_118 ( void )
{
int V_6 = F_119 ( & V_139 ) ;
if ( V_6 ) {
F_8 ( L_47 ) ;
return V_6 ;
}
F_120 ( L_48 , & V_58 ) ;
F_11 ( & V_175 ) ;
return 0 ;
}
static void T_9 F_121 ( void )
{
F_122 ( & V_139 ) ;
F_123 ( V_58 ) ;
F_13 ( & V_175 ) ;
}
