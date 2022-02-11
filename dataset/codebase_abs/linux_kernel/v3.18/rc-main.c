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
static T_7 F_57 ( struct V_80 * V_80 ,
struct V_82 * V_83 , char * V_84 )
{
struct V_25 * V_26 = F_58 ( V_80 ) ;
struct V_85 * V_86 = F_59 ( V_83 ) ;
T_1 V_87 , V_88 ;
char * V_89 = V_84 ;
int V_31 ;
if ( ! V_26 )
return - V_48 ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_86 -> type == V_90 ) {
V_88 = V_26 -> V_91 ;
V_87 = V_26 -> V_92 ;
if ( V_26 -> V_93 && ! V_87 )
V_87 = F_60 () ;
} else {
V_88 = V_26 -> V_94 ;
V_87 = V_26 -> V_95 ;
}
F_50 ( & V_26 -> V_46 ) ;
F_17 ( 1 , L_18 ,
V_96 , ( long long ) V_87 , ( long long ) V_88 ) ;
for ( V_31 = 0 ; V_31 < F_61 ( V_97 ) ; V_31 ++ ) {
if ( V_87 & V_88 & V_97 [ V_31 ] . type )
V_89 += sprintf ( V_89 , L_19 , V_97 [ V_31 ] . V_2 ) ;
else if ( V_87 & V_97 [ V_31 ] . type )
V_89 += sprintf ( V_89 , L_20 , V_97 [ V_31 ] . V_2 ) ;
if ( V_87 & V_97 [ V_31 ] . type )
V_87 &= ~ V_97 [ V_31 ] . type ;
}
if ( V_89 != V_84 )
V_89 -- ;
* V_89 = '\n' ;
return V_89 + 1 - V_84 ;
}
static int F_62 ( T_1 * V_98 , const char * V_84 )
{
const char * V_89 ;
unsigned V_99 = 0 ;
bool V_100 , V_101 ;
T_1 V_102 ;
int V_31 ;
while ( ( V_89 = F_63 ( ( char * * ) & V_84 , L_21 ) ) != NULL ) {
if ( ! * V_89 )
break;
if ( * V_89 == '+' ) {
V_100 = true ;
V_101 = false ;
V_89 ++ ;
} else if ( * V_89 == '-' ) {
V_100 = false ;
V_101 = true ;
V_89 ++ ;
} else {
V_100 = false ;
V_101 = false ;
}
for ( V_31 = 0 ; V_31 < F_61 ( V_97 ) ; V_31 ++ ) {
if ( ! strcasecmp ( V_89 , V_97 [ V_31 ] . V_2 ) ) {
V_102 = V_97 [ V_31 ] . type ;
break;
}
}
if ( V_31 == F_61 ( V_97 ) ) {
F_17 ( 1 , L_22 , V_89 ) ;
return - V_48 ;
}
V_99 ++ ;
if ( V_100 )
* V_98 |= V_102 ;
else if ( V_101 )
* V_98 &= ~ V_102 ;
else
* V_98 = V_102 ;
}
if ( ! V_99 ) {
F_17 ( 1 , L_23 ) ;
return - V_48 ;
}
return V_99 ;
}
static T_7 F_64 ( struct V_80 * V_80 ,
struct V_82 * V_83 ,
const char * V_84 , T_2 V_22 )
{
struct V_25 * V_26 = F_58 ( V_80 ) ;
struct V_85 * V_86 = F_59 ( V_83 ) ;
T_1 * V_103 ;
int (* F_65)( struct V_25 * V_26 , T_1 * V_10 );
struct V_104 * V_105 ;
int (* F_66)( struct V_25 * V_26 , struct V_104 * V_105 );
T_1 V_106 , V_107 ;
T_7 V_6 ;
if ( ! V_26 )
return - V_48 ;
if ( V_86 -> type == V_90 ) {
F_17 ( 1 , L_24 ) ;
V_103 = & V_26 -> V_91 ;
F_65 = V_26 -> F_65 ;
V_105 = & V_26 -> V_108 ;
F_66 = V_26 -> V_109 ;
} else {
F_17 ( 1 , L_25 ) ;
V_103 = & V_26 -> V_94 ;
F_65 = V_26 -> V_110 ;
V_105 = & V_26 -> V_111 ;
F_66 = V_26 -> V_112 ;
}
if ( ! F_65 ) {
F_17 ( 1 , L_26 ) ;
return - V_48 ;
}
F_49 ( & V_26 -> V_46 ) ;
V_106 = * V_103 ;
V_107 = V_106 ;
V_6 = F_62 ( & V_107 , V_84 ) ;
if ( V_6 < 0 )
goto V_49;
V_6 = F_65 ( V_26 , & V_107 ) ;
if ( V_6 < 0 ) {
F_17 ( 1 , L_27 ,
( long long ) V_107 ) ;
goto V_49;
}
if ( V_107 == V_106 ) {
V_6 = V_22 ;
goto V_49;
}
* V_103 = V_107 ;
F_17 ( 1 , L_28 , ( long long ) V_107 ) ;
if ( F_66 && V_105 -> V_102 ) {
if ( V_107 )
V_6 = F_66 ( V_26 , V_105 ) ;
else
V_6 = - 1 ;
if ( V_6 < 0 ) {
V_105 -> V_113 = 0 ;
V_105 -> V_102 = 0 ;
F_66 ( V_26 , V_105 ) ;
}
}
V_6 = V_22 ;
V_49:
F_50 ( & V_26 -> V_46 ) ;
return V_6 ;
}
static T_7 F_67 ( struct V_80 * V_80 ,
struct V_82 * V_114 ,
char * V_84 )
{
struct V_25 * V_26 = F_58 ( V_80 ) ;
struct V_85 * V_86 = F_59 ( V_114 ) ;
struct V_104 * V_105 ;
T_4 V_115 ;
if ( ! V_26 )
return - V_48 ;
if ( V_86 -> type == V_90 )
V_105 = & V_26 -> V_108 ;
else
V_105 = & V_26 -> V_111 ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_86 -> V_102 )
V_115 = V_105 -> V_102 ;
else
V_115 = V_105 -> V_113 ;
F_50 ( & V_26 -> V_46 ) ;
return sprintf ( V_84 , L_29 , V_115 ) ;
}
static T_7 F_68 ( struct V_80 * V_80 ,
struct V_82 * V_114 ,
const char * V_84 , T_2 V_22 )
{
struct V_25 * V_26 = F_58 ( V_80 ) ;
struct V_85 * V_86 = F_59 ( V_114 ) ;
struct V_104 V_116 , * V_105 ;
int V_117 ;
unsigned long V_115 ;
int (* F_66)( struct V_25 * V_26 , struct V_104 * V_105 );
T_1 * V_91 ;
if ( ! V_26 )
return - V_48 ;
V_117 = F_69 ( V_84 , 0 , & V_115 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_86 -> type == V_90 ) {
F_66 = V_26 -> V_109 ;
V_91 = & V_26 -> V_91 ;
V_105 = & V_26 -> V_108 ;
} else {
F_66 = V_26 -> V_112 ;
V_91 = & V_26 -> V_94 ;
V_105 = & V_26 -> V_111 ;
}
if ( ! F_66 )
return - V_48 ;
F_49 ( & V_26 -> V_46 ) ;
V_116 = * V_105 ;
if ( V_86 -> V_102 )
V_116 . V_102 = V_115 ;
else
V_116 . V_113 = V_115 ;
if ( ! * V_91 && V_115 ) {
V_117 = - V_48 ;
goto V_118;
}
V_117 = F_66 ( V_26 , & V_116 ) ;
if ( V_117 < 0 )
goto V_118;
* V_105 = V_116 ;
V_118:
F_50 ( & V_26 -> V_46 ) ;
return ( V_117 < 0 ) ? V_117 : V_22 ;
}
static void F_70 ( struct V_80 * V_80 )
{
}
static int F_71 ( struct V_80 * V_80 , struct V_119 * V_120 )
{
struct V_25 * V_26 = F_58 ( V_80 ) ;
if ( ! V_26 || ! V_26 -> V_35 )
return - V_121 ;
if ( V_26 -> V_5 . V_2 )
F_72 ( L_30 , V_26 -> V_5 . V_2 ) ;
if ( V_26 -> V_122 )
F_72 ( L_31 , V_26 -> V_122 ) ;
return 0 ;
}
struct V_25 * F_73 ( void )
{
struct V_25 * V_26 ;
V_26 = F_74 ( sizeof( * V_26 ) , V_15 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_35 = F_75 () ;
if ( ! V_26 -> V_35 ) {
F_19 ( V_26 ) ;
return NULL ;
}
V_26 -> V_35 -> V_123 = F_32 ;
V_26 -> V_35 -> V_124 = F_25 ;
F_76 ( V_26 -> V_35 , V_26 ) ;
F_77 ( & V_26 -> V_5 . V_46 ) ;
F_77 ( & V_26 -> V_61 ) ;
F_78 ( & V_26 -> V_46 ) ;
F_79 ( & V_26 -> V_69 , F_39 , ( unsigned long ) V_26 ) ;
V_26 -> V_26 . type = & V_125 ;
V_26 -> V_26 . V_126 = & V_127 ;
F_80 ( & V_26 -> V_26 ) ;
F_81 ( V_128 ) ;
return V_26 ;
}
void F_82 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
if ( V_26 -> V_35 )
F_83 ( V_26 -> V_35 ) ;
F_84 ( & V_26 -> V_26 ) ;
F_19 ( V_26 ) ;
F_85 ( V_128 ) ;
}
int F_86 ( struct V_25 * V_26 )
{
static bool V_129 = false ;
struct V_5 * V_5 ;
const char * V_130 ;
int V_6 , V_131 , V_114 = 0 ;
if ( ! V_26 || ! V_26 -> V_132 )
return - V_48 ;
V_5 = F_5 ( V_26 -> V_132 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_133 ) ;
if ( ! V_5 || ! V_5 -> V_14 || V_5 -> V_11 == 0 )
return - V_48 ;
F_87 ( V_134 , V_26 -> V_35 -> V_135 ) ;
F_87 ( V_136 , V_26 -> V_35 -> V_135 ) ;
F_87 ( V_64 , V_26 -> V_35 -> V_135 ) ;
F_87 ( V_65 , V_26 -> V_35 -> V_137 ) ;
if ( V_26 -> V_78 )
V_26 -> V_35 -> V_78 = F_51 ;
if ( V_26 -> V_79 )
V_26 -> V_35 -> V_79 = F_53 ;
do {
V_131 = F_88 ( V_138 ,
V_139 ) ;
if ( V_131 >= V_139 )
return - V_16 ;
} while ( F_89 ( V_131 , V_138 ) );
V_26 -> V_26 . V_140 = V_26 -> V_141 ;
V_26 -> V_141 [ V_114 ++ ] = & V_142 ;
if ( V_26 -> V_109 )
V_26 -> V_141 [ V_114 ++ ] = & V_143 ;
if ( V_26 -> V_112 )
V_26 -> V_141 [ V_114 ++ ] = & V_144 ;
if ( V_26 -> V_110 )
V_26 -> V_141 [ V_114 ++ ] = & V_145 ;
V_26 -> V_141 [ V_114 ++ ] = NULL ;
F_49 ( & V_26 -> V_46 ) ;
V_26 -> V_131 = V_131 ;
F_90 ( & V_26 -> V_26 , L_32 , V_26 -> V_131 ) ;
F_91 ( & V_26 -> V_26 , V_26 ) ;
V_6 = F_92 ( & V_26 -> V_26 ) ;
if ( V_6 )
goto V_146;
V_6 = F_30 ( V_26 , V_5 ) ;
if ( V_6 )
goto V_147;
V_26 -> V_35 -> V_26 . V_148 = & V_26 -> V_26 ;
memcpy ( & V_26 -> V_35 -> V_149 , & V_26 -> V_150 , sizeof( V_26 -> V_150 ) ) ;
V_26 -> V_35 -> V_151 = V_26 -> V_152 ;
V_26 -> V_35 -> V_2 = V_26 -> V_55 ;
F_50 ( & V_26 -> V_46 ) ;
V_6 = F_93 ( V_26 -> V_35 ) ;
F_49 ( & V_26 -> V_46 ) ;
if ( V_6 )
goto V_153;
V_26 -> V_35 -> V_154 [ V_155 ] = 500 ;
V_26 -> V_35 -> V_154 [ V_156 ] = 125 ;
V_130 = F_94 ( & V_26 -> V_26 . V_157 , V_15 ) ;
F_8 ( V_8 L_33 ,
F_56 ( & V_26 -> V_26 ) ,
V_26 -> V_55 ? V_26 -> V_55 : L_34 ,
V_130 ? V_130 : L_35 ) ;
F_19 ( V_130 ) ;
if ( V_26 -> V_158 == V_159 ) {
if ( ! V_129 ) {
F_17 ( 1 , L_36 ) ;
F_95 () ;
V_129 = true ;
}
V_6 = F_96 ( V_26 ) ;
if ( V_6 < 0 )
goto V_160;
}
if ( V_26 -> F_65 ) {
T_1 V_10 = ( 1 << V_5 -> V_10 ) ;
if ( V_26 -> V_158 == V_159 )
V_10 |= V_161 ;
V_6 = V_26 -> F_65 ( V_26 , & V_10 ) ;
if ( V_6 < 0 )
goto V_162;
V_26 -> V_91 = V_10 ;
}
F_50 ( & V_26 -> V_46 ) ;
F_17 ( 1 , L_37 ,
V_26 -> V_131 ,
V_26 -> V_122 ? V_26 -> V_122 : L_38 ,
V_5 -> V_2 ? V_5 -> V_2 : L_38 ,
V_26 -> V_158 == V_159 ? L_39 : L_40 ) ;
return 0 ;
V_162:
if ( V_26 -> V_158 == V_159 )
F_97 ( V_26 ) ;
V_160:
F_98 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
V_153:
F_18 ( & V_26 -> V_5 ) ;
V_147:
F_99 ( & V_26 -> V_26 ) ;
V_146:
F_50 ( & V_26 -> V_46 ) ;
F_100 ( V_26 -> V_131 , V_138 ) ;
return V_6 ;
}
void F_101 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
F_102 ( & V_26 -> V_69 ) ;
F_100 ( V_26 -> V_131 , V_138 ) ;
if ( V_26 -> V_158 == V_159 )
F_97 ( V_26 ) ;
F_18 ( & V_26 -> V_5 ) ;
F_17 ( 1 , L_41 ) ;
F_98 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
F_99 ( & V_26 -> V_26 ) ;
F_82 ( V_26 ) ;
}
static int T_8 F_103 ( void )
{
int V_6 = F_104 ( & V_127 ) ;
if ( V_6 ) {
F_8 ( V_7 L_42 ) ;
return V_6 ;
}
F_105 ( L_43 , & V_59 ) ;
F_10 ( & V_163 ) ;
return 0 ;
}
static void T_9 F_106 ( void )
{
F_107 ( & V_127 ) ;
F_108 ( V_59 ) ;
F_12 ( & V_163 ) ;
}
