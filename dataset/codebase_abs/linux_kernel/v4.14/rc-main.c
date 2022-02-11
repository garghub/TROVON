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
unsigned int V_63 = V_64 [ V_25 -> V_65 ] . V_66 ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
if ( ! V_25 -> V_56 )
goto V_48;
F_44 ( V_25 -> V_34 , V_67 , V_68 , V_25 -> V_69 ) ;
F_39 ( V_25 -> V_34 ) ;
V_25 -> V_62 = V_70 + F_45 ( V_63 ) ;
F_46 ( & V_25 -> V_71 , V_25 -> V_62 ) ;
V_48:
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static void F_47 ( struct V_24 * V_25 , enum V_9 V_72 ,
T_4 V_33 , T_4 V_29 , T_5 V_73 )
{
bool V_74 = ( ! V_25 -> V_56 ||
V_25 -> V_65 != V_72 ||
V_25 -> V_69 != V_33 ||
V_25 -> V_75 != V_73 ) ;
if ( V_74 && V_25 -> V_56 )
F_36 ( V_25 , false ) ;
F_44 ( V_25 -> V_34 , V_67 , V_68 , V_33 ) ;
if ( V_74 && V_29 != V_31 ) {
V_25 -> V_56 = true ;
V_25 -> V_65 = V_72 ;
V_25 -> V_69 = V_33 ;
V_25 -> V_75 = V_73 ;
V_25 -> V_57 = V_29 ;
F_20 ( 1 , L_15 ,
V_25 -> V_54 , V_29 , V_72 , V_33 ) ;
F_37 ( V_25 -> V_34 , V_29 , 1 ) ;
F_38 ( V_58 , V_76 ) ;
}
F_39 ( V_25 -> V_34 ) ;
}
void F_48 ( struct V_24 * V_25 , enum V_9 V_72 , T_4 V_33 ,
T_5 V_73 )
{
unsigned long V_44 ;
T_4 V_29 = F_35 ( V_25 , V_33 ) ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_47 ( V_25 , V_72 , V_33 , V_29 , V_73 ) ;
if ( V_25 -> V_56 ) {
V_25 -> V_62 = V_70 +
F_45 ( V_64 [ V_72 ] . V_66 ) ;
F_46 ( & V_25 -> V_71 , V_25 -> V_62 ) ;
}
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
void F_49 ( struct V_24 * V_25 , enum V_9 V_72 ,
T_4 V_33 , T_5 V_73 )
{
unsigned long V_44 ;
T_4 V_29 = F_35 ( V_25 , V_33 ) ;
F_29 ( & V_25 -> V_60 , V_44 ) ;
F_47 ( V_25 , V_72 , V_33 , V_29 , V_73 ) ;
F_31 ( & V_25 -> V_60 , V_44 ) ;
}
static int F_50 ( struct V_24 * V_25 ,
struct V_77 * V_78 )
{
T_4 V_79 , V_80 = V_78 -> V_81 ;
enum V_9 V_72 = V_25 -> V_82 ;
if ( V_72 >= F_51 ( V_64 ) )
return - V_47 ;
V_79 = V_64 [ V_72 ] . V_83 ;
switch ( V_72 ) {
case V_84 :
if ( ( ( ( V_80 >> 16 ) ^ ~ ( V_80 >> 8 ) ) & 0xff ) == 0 )
return - V_47 ;
break;
case V_85 :
if ( ( ( ( V_80 >> 24 ) ^ ~ ( V_80 >> 16 ) ) & 0xff ) == 0 )
return - V_47 ;
break;
case V_86 :
if ( ( V_80 & 0xffff0000 ) != 0x800f0000 )
return - V_47 ;
break;
case V_87 :
if ( ( V_80 & 0xffff0000 ) == 0x800f0000 )
return - V_47 ;
break;
default:
break;
}
V_78 -> V_81 &= V_79 ;
V_78 -> V_79 &= V_79 ;
if ( V_25 -> V_88 && V_78 -> V_79 != 0 && V_78 -> V_79 != V_79 )
return - V_47 ;
return 0 ;
}
int F_52 ( struct V_24 * V_42 )
{
int V_89 = 0 ;
if ( ! V_42 )
return - V_47 ;
F_53 ( & V_42 -> V_45 ) ;
if ( ! V_42 -> V_90 ++ && V_42 -> V_91 != NULL )
V_89 = V_42 -> V_91 ( V_42 ) ;
if ( V_89 )
V_42 -> V_90 -- ;
F_54 ( & V_42 -> V_45 ) ;
return V_89 ;
}
static int F_55 ( struct V_34 * V_39 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
return F_52 ( V_42 ) ;
}
void F_56 ( struct V_24 * V_42 )
{
if ( V_42 ) {
F_53 ( & V_42 -> V_45 ) ;
if ( ! -- V_42 -> V_90 && V_42 -> V_92 != NULL )
V_42 -> V_92 ( V_42 ) ;
F_54 ( & V_42 -> V_45 ) ;
}
}
static void F_57 ( struct V_34 * V_39 )
{
struct V_24 * V_42 = F_28 ( V_39 ) ;
F_56 ( V_42 ) ;
}
static char * F_58 ( struct V_93 * V_25 , T_6 * V_94 )
{
return F_59 ( V_11 , L_16 , F_60 ( V_25 ) ) ;
}
static bool F_61 ( void )
{
#if F_62 ( V_95 )
struct V_96 * V_97 ;
F_53 ( & V_98 ) ;
V_97 = F_63 ( L_17 ) ;
F_54 ( & V_98 ) ;
return V_97 ? true : false ;
#elif F_62 ( V_99 )
return true ;
#else
return false ;
#endif
}
static T_7 F_64 ( struct V_93 * V_93 ,
struct V_100 * V_101 , char * V_102 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
T_1 V_103 , V_104 ;
char * V_105 = V_102 ;
int V_30 ;
F_53 ( & V_25 -> V_45 ) ;
V_104 = V_25 -> V_106 ;
V_103 = V_25 -> V_107 ;
if ( V_25 -> V_108 && ! V_103 )
V_103 = F_66 () ;
F_54 ( & V_25 -> V_45 ) ;
F_20 ( 1 , L_18 ,
V_109 , ( long long ) V_103 , ( long long ) V_104 ) ;
for ( V_30 = 0 ; V_30 < F_51 ( V_110 ) ; V_30 ++ ) {
if ( V_103 & V_104 & V_110 [ V_30 ] . type )
V_105 += sprintf ( V_105 , L_19 , V_110 [ V_30 ] . V_2 ) ;
else if ( V_103 & V_110 [ V_30 ] . type )
V_105 += sprintf ( V_105 , L_20 , V_110 [ V_30 ] . V_2 ) ;
if ( V_103 & V_110 [ V_30 ] . type )
V_103 &= ~ V_110 [ V_30 ] . type ;
}
if ( V_25 -> V_111 == V_112 && F_61 () )
V_105 += sprintf ( V_105 , L_21 ) ;
if ( V_105 != V_102 )
V_105 -- ;
* V_105 = '\n' ;
return V_105 + 1 - V_102 ;
}
static int F_67 ( T_1 * V_64 , const char * V_102 )
{
const char * V_105 ;
unsigned V_113 = 0 ;
bool V_114 , V_115 ;
T_1 V_79 ;
int V_30 ;
while ( ( V_105 = F_68 ( ( char * * ) & V_102 , L_22 ) ) != NULL ) {
if ( ! * V_105 )
break;
if ( * V_105 == '+' ) {
V_114 = true ;
V_115 = false ;
V_105 ++ ;
} else if ( * V_105 == '-' ) {
V_114 = false ;
V_115 = true ;
V_105 ++ ;
} else {
V_114 = false ;
V_115 = false ;
}
for ( V_30 = 0 ; V_30 < F_51 ( V_110 ) ; V_30 ++ ) {
if ( ! strcasecmp ( V_105 , V_110 [ V_30 ] . V_2 ) ) {
V_79 = V_110 [ V_30 ] . type ;
break;
}
}
if ( V_30 == F_51 ( V_110 ) ) {
if ( ! strcasecmp ( V_105 , L_23 ) )
V_79 = 0 ;
else {
F_20 ( 1 , L_24 , V_105 ) ;
return - V_47 ;
}
}
V_113 ++ ;
if ( V_114 )
* V_64 |= V_79 ;
else if ( V_115 )
* V_64 &= ~ V_79 ;
else
* V_64 = V_79 ;
}
if ( ! V_113 ) {
F_20 ( 1 , L_25 ) ;
return - V_47 ;
}
return V_113 ;
}
static void F_69 ( T_1 * V_64 )
{
T_1 V_116 ;
int V_30 , V_117 ;
for ( V_30 = 0 ; V_30 < F_51 ( V_110 ) ; V_30 ++ ) {
if ( V_110 [ V_30 ] . type == V_118 ||
V_110 [ V_30 ] . type & ( V_119 |
V_120 ) )
continue;
V_116 = F_66 () ;
if ( ! ( * V_64 & V_110 [ V_30 ] . type & ~ V_116 ) )
continue;
if ( ! V_110 [ V_30 ] . V_121 ) {
F_8 ( L_26 ,
V_110 [ V_30 ] . V_2 ) ;
* V_64 &= ~ V_110 [ V_30 ] . type ;
continue;
}
V_117 = F_7 ( L_1 , V_110 [ V_30 ] . V_121 ) ;
if ( V_117 < 0 ) {
F_8 ( L_27 ,
V_110 [ V_30 ] . V_121 ) ;
* V_64 &= ~ V_110 [ V_30 ] . type ;
continue;
}
F_9 ( 20 ) ;
V_116 = F_66 () ;
if ( ! ( * V_64 & V_110 [ V_30 ] . type & ~ V_116 ) )
continue;
F_8 ( L_28 ,
V_110 [ V_30 ] . V_121 ,
V_110 [ V_30 ] . V_2 ) ;
* V_64 &= ~ V_110 [ V_30 ] . type ;
}
}
static T_7 F_70 ( struct V_93 * V_93 ,
struct V_100 * V_101 ,
const char * V_102 , T_2 V_21 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
T_1 * V_122 ;
struct V_77 * V_78 ;
T_1 V_123 , V_124 ;
T_7 V_6 ;
F_20 ( 1 , L_29 ) ;
V_122 = & V_25 -> V_106 ;
V_78 = & V_25 -> V_125 ;
if ( ! V_25 -> V_126 ) {
F_20 ( 1 , L_30 ) ;
return - V_47 ;
}
F_53 ( & V_25 -> V_45 ) ;
V_123 = * V_122 ;
V_124 = V_123 ;
V_6 = F_67 ( & V_124 , V_102 ) ;
if ( V_6 < 0 )
goto V_48;
V_6 = V_25 -> V_126 ( V_25 , & V_124 ) ;
if ( V_6 < 0 ) {
F_20 ( 1 , L_31 ,
( long long ) V_124 ) ;
goto V_48;
}
if ( V_25 -> V_111 == V_112 )
F_69 ( & V_124 ) ;
if ( V_124 != V_123 ) {
* V_122 = V_124 ;
F_20 ( 1 , L_32 ,
( long long ) V_124 ) ;
}
if ( V_25 -> V_127 && V_78 -> V_79 ) {
if ( V_124 )
V_6 = V_25 -> V_127 ( V_25 , V_78 ) ;
else
V_6 = - 1 ;
if ( V_6 < 0 ) {
V_78 -> V_81 = 0 ;
V_78 -> V_79 = 0 ;
V_25 -> V_127 ( V_25 , V_78 ) ;
}
}
V_6 = V_21 ;
V_48:
F_54 ( & V_25 -> V_45 ) ;
return V_6 ;
}
static T_7 F_71 ( struct V_93 * V_93 ,
struct V_100 * V_128 ,
char * V_102 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
struct V_129 * V_130 = F_72 ( V_128 ) ;
struct V_77 * V_78 ;
T_4 V_131 ;
F_53 ( & V_25 -> V_45 ) ;
if ( V_130 -> type == V_132 )
V_78 = & V_25 -> V_125 ;
else
V_78 = & V_25 -> V_133 ;
if ( V_130 -> V_79 )
V_131 = V_78 -> V_79 ;
else
V_131 = V_78 -> V_81 ;
F_54 ( & V_25 -> V_45 ) ;
return sprintf ( V_102 , L_33 , V_131 ) ;
}
static T_7 F_73 ( struct V_93 * V_93 ,
struct V_100 * V_128 ,
const char * V_102 , T_2 V_21 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
struct V_129 * V_130 = F_72 ( V_128 ) ;
struct V_77 V_134 , * V_78 ;
int V_117 ;
unsigned long V_131 ;
int (* F_74)( struct V_24 * V_25 , struct V_77 * V_78 );
V_117 = F_75 ( V_102 , 0 , & V_131 ) ;
if ( V_117 < 0 )
return V_117 ;
if ( V_130 -> type == V_132 ) {
F_74 = V_25 -> V_127 ;
V_78 = & V_25 -> V_125 ;
} else {
F_74 = V_25 -> V_135 ;
V_78 = & V_25 -> V_133 ;
}
if ( ! F_74 )
return - V_47 ;
F_53 ( & V_25 -> V_45 ) ;
V_134 = * V_78 ;
if ( V_130 -> V_79 )
V_134 . V_79 = V_131 ;
else
V_134 . V_81 = V_131 ;
if ( V_130 -> type == V_136 ) {
if ( V_25 -> V_82 != V_137 )
V_117 = F_50 ( V_25 , & V_134 ) ;
else
V_117 = - V_47 ;
if ( V_117 != 0 )
goto V_138;
}
if ( V_130 -> type == V_132 && ! V_25 -> V_106 &&
V_131 ) {
V_117 = - V_47 ;
goto V_138;
}
V_117 = F_74 ( V_25 , & V_134 ) ;
if ( V_117 < 0 )
goto V_138;
* V_78 = V_134 ;
V_138:
F_54 ( & V_25 -> V_45 ) ;
return ( V_117 < 0 ) ? V_117 : V_21 ;
}
static T_7 F_76 ( struct V_93 * V_93 ,
struct V_100 * V_101 ,
char * V_102 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
T_1 V_103 ;
enum V_9 V_104 ;
char * V_105 = V_102 ;
int V_30 ;
F_53 ( & V_25 -> V_45 ) ;
V_103 = V_25 -> V_139 ;
V_104 = V_25 -> V_82 ;
F_54 ( & V_25 -> V_45 ) ;
F_20 ( 1 , L_34 ,
V_109 , ( long long ) V_103 , V_104 ) ;
for ( V_30 = 0 ; V_30 < F_51 ( V_64 ) ; V_30 ++ ) {
if ( V_103 & ( 1ULL << V_30 ) ) {
if ( V_30 == V_104 )
V_105 += sprintf ( V_105 , L_19 , V_64 [ V_30 ] . V_2 ) ;
else
V_105 += sprintf ( V_105 , L_20 , V_64 [ V_30 ] . V_2 ) ;
}
}
if ( V_105 != V_102 )
V_105 -- ;
* V_105 = '\n' ;
return V_105 + 1 - V_102 ;
}
static T_7 F_77 ( struct V_93 * V_93 ,
struct V_100 * V_101 ,
const char * V_102 , T_2 V_21 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
enum V_9 V_72 ;
T_7 V_6 ;
T_1 V_103 ;
int V_30 ;
F_53 ( & V_25 -> V_45 ) ;
V_103 = V_25 -> V_139 ;
if ( F_78 ( V_102 , L_35 ) ) {
V_72 = V_137 ;
} else {
for ( V_30 = 0 ; V_30 < F_51 ( V_64 ) ; V_30 ++ ) {
if ( ( V_103 & ( 1ULL << V_30 ) ) &&
F_78 ( V_102 , V_64 [ V_30 ] . V_2 ) ) {
V_72 = V_30 ;
break;
}
}
if ( V_30 == F_51 ( V_64 ) ) {
V_6 = - V_47 ;
goto V_48;
}
if ( V_25 -> V_88 ) {
T_1 V_79 = 1ULL << V_72 ;
F_69 ( & V_79 ) ;
if ( ! V_79 ) {
V_6 = - V_47 ;
goto V_48;
}
}
}
if ( V_25 -> V_82 != V_72 ) {
V_25 -> V_82 = V_72 ;
F_20 ( 1 , L_36 , V_72 ) ;
if ( V_72 == V_86 )
V_25 -> V_133 . V_81 = 0x800f0000 ;
else
V_25 -> V_133 . V_81 = 0 ;
V_25 -> V_133 . V_79 = 0 ;
V_6 = V_25 -> V_135 ( V_25 , & V_25 -> V_133 ) ;
if ( V_6 == 0 )
V_6 = V_21 ;
} else {
V_6 = V_21 ;
}
V_48:
F_54 ( & V_25 -> V_45 ) ;
return V_6 ;
}
static void F_79 ( struct V_93 * V_93 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
F_19 ( V_25 ) ;
}
static int F_80 ( struct V_93 * V_93 , struct V_140 * V_141 )
{
struct V_24 * V_25 = F_65 ( V_93 ) ;
if ( V_25 -> V_5 . V_2 )
F_81 ( L_37 , V_25 -> V_5 . V_2 ) ;
if ( V_25 -> V_142 )
F_81 ( L_38 , V_25 -> V_142 ) ;
return 0 ;
}
struct V_24 * F_82 ( enum V_143 type )
{
struct V_24 * V_25 ;
V_25 = F_83 ( sizeof( * V_25 ) , V_11 ) ;
if ( ! V_25 )
return NULL ;
if ( type != V_144 ) {
V_25 -> V_34 = F_84 () ;
if ( ! V_25 -> V_34 ) {
F_19 ( V_25 ) ;
return NULL ;
}
V_25 -> V_34 -> V_145 = F_34 ;
V_25 -> V_34 -> V_146 = F_27 ;
F_85 ( V_25 -> V_34 , V_25 ) ;
F_86 ( & V_25 -> V_71 , F_41 ,
( unsigned long ) V_25 ) ;
F_87 ( & V_25 -> V_5 . V_45 ) ;
F_87 ( & V_25 -> V_60 ) ;
}
F_88 ( & V_25 -> V_45 ) ;
V_25 -> V_25 . type = & V_147 ;
V_25 -> V_25 . V_148 = & V_149 ;
F_89 ( & V_25 -> V_25 ) ;
V_25 -> V_111 = type ;
F_90 ( V_150 ) ;
return V_25 ;
}
void F_91 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_92 ( V_25 -> V_34 ) ;
F_93 ( & V_25 -> V_25 ) ;
F_94 ( V_150 ) ;
}
static void F_95 ( struct V_93 * V_25 , void * V_151 )
{
F_91 ( * (struct V_24 * * ) V_151 ) ;
}
struct V_24 * F_96 ( struct V_93 * V_25 ,
enum V_143 type )
{
struct V_24 * * V_152 , * V_6 ;
V_152 = F_97 ( F_95 , sizeof( * V_152 ) , V_11 ) ;
if ( ! V_152 )
return NULL ;
V_6 = F_82 ( type ) ;
if ( ! V_6 ) {
F_98 ( V_152 ) ;
return NULL ;
}
V_6 -> V_25 . V_153 = V_25 ;
V_6 -> V_154 = true ;
* V_152 = V_6 ;
F_99 ( V_25 , V_152 ) ;
return V_6 ;
}
static int F_100 ( struct V_24 * V_25 )
{
int V_6 ;
struct V_5 * V_5 ;
T_1 V_9 ;
if ( ! V_25 -> V_155 )
return - V_47 ;
V_5 = F_5 ( V_25 -> V_155 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_156 ) ;
if ( ! V_5 || ! V_5 -> V_15 || V_5 -> V_10 == 0 )
return - V_47 ;
V_6 = F_32 ( V_25 , V_5 ) ;
if ( V_6 )
return V_6 ;
V_9 = F_101 ( V_5 -> V_9 ) ;
if ( V_25 -> V_126 ) {
V_6 = V_25 -> V_126 ( V_25 , & V_9 ) ;
if ( V_6 < 0 )
goto V_157;
V_25 -> V_106 = V_9 ;
}
if ( V_25 -> V_111 == V_112 )
F_69 ( & V_9 ) ;
F_102 ( V_158 , V_25 -> V_34 -> V_159 ) ;
F_102 ( V_160 , V_25 -> V_34 -> V_159 ) ;
F_102 ( V_67 , V_25 -> V_34 -> V_159 ) ;
F_102 ( V_68 , V_25 -> V_34 -> V_161 ) ;
if ( V_25 -> V_91 )
V_25 -> V_34 -> V_91 = F_55 ;
if ( V_25 -> V_92 )
V_25 -> V_34 -> V_92 = F_57 ;
V_25 -> V_34 -> V_25 . V_153 = & V_25 -> V_25 ;
memcpy ( & V_25 -> V_34 -> V_162 , & V_25 -> V_163 , sizeof( V_25 -> V_163 ) ) ;
V_25 -> V_34 -> V_164 = V_25 -> V_165 ;
V_25 -> V_34 -> V_2 = V_25 -> V_54 ;
return 0 ;
V_157:
F_21 ( & V_25 -> V_5 ) ;
return V_6 ;
}
static int F_103 ( struct V_24 * V_25 )
{
int V_6 ;
V_6 = F_104 ( V_25 -> V_34 ) ;
if ( V_6 )
return V_6 ;
V_25 -> V_34 -> V_166 [ V_167 ] = 500 ;
V_25 -> V_34 -> V_166 [ V_168 ] = 125 ;
return 0 ;
}
static void F_105 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
if ( V_25 -> V_34 ) {
F_106 ( V_25 -> V_34 ) ;
V_25 -> V_34 = NULL ;
}
F_21 ( & V_25 -> V_5 ) ;
}
int F_107 ( struct V_24 * V_25 )
{
const char * V_169 ;
int V_128 = 0 ;
int V_170 ;
int V_6 ;
if ( ! V_25 )
return - V_47 ;
V_170 = F_108 ( & V_171 , 0 , V_172 , V_11 ) ;
if ( V_170 < 0 )
return V_170 ;
V_25 -> V_170 = V_170 ;
F_109 ( & V_25 -> V_25 , L_39 , V_25 -> V_170 ) ;
F_110 ( & V_25 -> V_25 , V_25 ) ;
V_25 -> V_25 . V_173 = V_25 -> V_174 ;
if ( V_25 -> V_111 != V_144 )
V_25 -> V_174 [ V_128 ++ ] = & V_175 ;
if ( V_25 -> V_127 )
V_25 -> V_174 [ V_128 ++ ] = & V_176 ;
if ( V_25 -> V_135 )
V_25 -> V_174 [ V_128 ++ ] = & V_177 ;
V_25 -> V_174 [ V_128 ++ ] = NULL ;
if ( V_25 -> V_111 == V_112 ||
V_25 -> V_111 == V_144 ) {
V_6 = F_111 ( V_25 ) ;
if ( V_6 < 0 )
goto V_178;
}
if ( V_25 -> V_111 != V_144 ) {
V_6 = F_100 ( V_25 ) ;
if ( V_6 )
goto V_179;
}
V_6 = F_112 ( & V_25 -> V_25 ) ;
if ( V_6 )
goto V_180;
V_169 = F_113 ( & V_25 -> V_25 . V_181 , V_11 ) ;
F_114 ( & V_25 -> V_25 , L_40 ,
V_25 -> V_54 ? : L_41 , V_169 ? : L_42 ) ;
F_19 ( V_169 ) ;
if ( V_25 -> V_111 != V_144 ) {
V_6 = F_103 ( V_25 ) ;
if ( V_6 )
goto V_182;
}
if ( V_25 -> V_111 == V_112 ||
V_25 -> V_111 == V_144 ) {
V_6 = F_115 ( V_25 ) ;
if ( V_6 < 0 )
goto V_183;
}
F_20 ( 1 , L_43 ,
V_25 -> V_170 ,
V_25 -> V_142 ? V_25 -> V_142 : L_44 ) ;
return 0 ;
V_183:
F_105 ( V_25 ) ;
V_182:
F_116 ( & V_25 -> V_25 ) ;
V_180:
F_21 ( & V_25 -> V_5 ) ;
V_179:
F_117 ( V_25 ) ;
V_178:
F_118 ( & V_171 , V_170 ) ;
return V_6 ;
}
static void F_119 ( struct V_93 * V_25 , void * V_151 )
{
F_120 ( * (struct V_24 * * ) V_151 ) ;
}
int F_121 ( struct V_93 * V_153 , struct V_24 * V_25 )
{
struct V_24 * * V_152 ;
int V_117 ;
V_152 = F_97 ( F_119 , sizeof( * V_152 ) , V_11 ) ;
if ( ! V_152 )
return - V_12 ;
V_117 = F_107 ( V_25 ) ;
if ( V_117 ) {
F_98 ( V_152 ) ;
return V_117 ;
}
* V_152 = V_25 ;
F_99 ( V_153 , V_152 ) ;
return 0 ;
}
void F_120 ( struct V_24 * V_25 )
{
if ( ! V_25 )
return;
F_122 ( & V_25 -> V_71 ) ;
if ( V_25 -> V_111 == V_112 )
F_123 ( V_25 ) ;
F_105 ( V_25 ) ;
F_116 ( & V_25 -> V_25 ) ;
F_118 ( & V_171 , V_25 -> V_170 ) ;
if ( ! V_25 -> V_154 )
F_91 ( V_25 ) ;
}
static int T_8 F_124 ( void )
{
int V_6 = F_125 ( & V_149 ) ;
if ( V_6 ) {
F_8 ( L_45 ) ;
return V_6 ;
}
F_126 ( L_46 , & V_58 ) ;
F_11 ( & V_184 ) ;
return 0 ;
}
static void T_9 F_127 ( void )
{
F_128 ( & V_149 ) ;
F_129 ( V_58 ) ;
F_13 ( & V_184 ) ;
}
