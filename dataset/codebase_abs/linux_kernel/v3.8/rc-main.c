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
int V_6 = F_7 ( V_2 ) ;
if ( V_6 < 0 ) {
F_8 ( V_7 L_1 , V_2 ) ;
return NULL ;
}
F_9 ( 20 ) ;
V_3 = F_1 ( V_2 ) ;
}
#endif
if ( ! V_3 ) {
F_8 ( V_7 L_2 , V_2 ) ;
return NULL ;
}
F_8 ( V_8 L_3 , V_3 -> V_3 . V_2 ) ;
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
F_17 ( 1 , L_4 ,
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
F_17 ( 1 , L_5 , V_19 ) ;
}
if ( ( V_5 -> V_22 * 3 < V_5 -> V_11 ) && ( V_18 > V_24 ) ) {
V_19 /= 2 ;
F_17 ( 1 , L_6 , V_19 ) ;
}
if ( V_19 == V_18 )
return 0 ;
V_21 = F_16 ( V_19 , V_17 ) ;
if ( ! V_21 ) {
F_17 ( 1 , L_7 , V_19 ) ;
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
F_17 ( 1 , L_8 ,
V_27 , V_5 -> V_14 [ V_27 ] . V_34 ) ;
V_5 -> V_22 -- ;
memmove ( & V_5 -> V_14 [ V_27 ] , & V_5 -> V_14 [ V_27 + 1 ] ,
( V_5 -> V_22 - V_27 ) * sizeof( struct V_13 ) ) ;
} else {
F_17 ( 1 , L_9 ,
V_27 ,
V_29 == V_32 ? L_10 : L_11 ,
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
F_17 ( 1 , L_4 ,
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
F_17 ( 1 , L_12 ,
V_26 -> V_55 , V_34 , V_30 ) ;
return V_30 ;
}
static void F_34 ( struct V_25 * V_26 , bool V_56 )
{
if ( ! V_26 -> V_57 )
return;
F_17 ( 1 , L_13 , V_26 -> V_58 ) ;
F_35 ( V_26 -> V_35 , V_26 -> V_58 , 0 ) ;
if ( V_56 )
F_36 ( V_26 -> V_35 ) ;
V_26 -> V_57 = false ;
}
void F_37 ( struct V_25 * V_26 )
{
unsigned long V_45 ;
F_27 ( & V_26 -> V_59 , V_45 ) ;
F_34 ( V_26 , true ) ;
F_29 ( & V_26 -> V_59 , V_45 ) ;
}
static void F_38 ( unsigned long V_60 )
{
struct V_25 * V_26 = (struct V_25 * ) V_60 ;
unsigned long V_45 ;
F_27 ( & V_26 -> V_59 , V_45 ) ;
if ( F_39 ( V_26 -> V_61 ) )
F_34 ( V_26 , true ) ;
F_29 ( & V_26 -> V_59 , V_45 ) ;
}
void F_40 ( struct V_25 * V_26 )
{
unsigned long V_45 ;
F_27 ( & V_26 -> V_59 , V_45 ) ;
F_41 ( V_26 -> V_35 , V_62 , V_63 , V_26 -> V_64 ) ;
F_36 ( V_26 -> V_35 ) ;
if ( ! V_26 -> V_57 )
goto V_49;
V_26 -> V_61 = V_65 + F_42 ( V_66 ) ;
F_43 ( & V_26 -> V_67 , V_26 -> V_61 ) ;
V_49:
F_29 ( & V_26 -> V_59 , V_45 ) ;
}
static void F_44 ( struct V_25 * V_26 , int V_34 ,
T_4 V_30 , T_5 V_68 )
{
bool V_69 = ! V_26 -> V_57 ||
V_26 -> V_64 != V_34 ||
V_26 -> V_70 != V_68 ;
if ( V_69 && V_26 -> V_57 )
F_34 ( V_26 , false ) ;
F_41 ( V_26 -> V_35 , V_62 , V_63 , V_34 ) ;
if ( V_69 && V_30 != V_32 ) {
V_26 -> V_57 = true ;
V_26 -> V_64 = V_34 ;
V_26 -> V_70 = V_68 ;
V_26 -> V_58 = V_30 ;
F_17 ( 1 , L_14
L_15 ,
V_26 -> V_55 , V_30 , V_34 ) ;
F_35 ( V_26 -> V_35 , V_30 , 1 ) ;
}
F_36 ( V_26 -> V_35 ) ;
}
void F_45 ( struct V_25 * V_26 , int V_34 , T_5 V_68 )
{
unsigned long V_45 ;
T_4 V_30 = F_33 ( V_26 , V_34 ) ;
F_27 ( & V_26 -> V_59 , V_45 ) ;
F_44 ( V_26 , V_34 , V_30 , V_68 ) ;
if ( V_26 -> V_57 ) {
V_26 -> V_61 = V_65 + F_42 ( V_66 ) ;
F_43 ( & V_26 -> V_67 , V_26 -> V_61 ) ;
}
F_29 ( & V_26 -> V_59 , V_45 ) ;
}
void F_46 ( struct V_25 * V_26 , int V_34 , T_5 V_68 )
{
unsigned long V_45 ;
T_4 V_30 = F_33 ( V_26 , V_34 ) ;
F_27 ( & V_26 -> V_59 , V_45 ) ;
F_44 ( V_26 , V_34 , V_30 , V_68 ) ;
F_29 ( & V_26 -> V_59 , V_45 ) ;
}
static int F_47 ( struct V_35 * V_40 )
{
struct V_25 * V_43 = F_26 ( V_40 ) ;
return V_43 -> V_71 ( V_43 ) ;
}
static void F_48 ( struct V_35 * V_40 )
{
struct V_25 * V_43 = F_26 ( V_40 ) ;
if ( V_43 )
V_43 -> V_72 ( V_43 ) ;
}
static char * F_49 ( struct V_73 * V_26 , T_6 * V_74 )
{
return F_50 ( V_15 , L_16 , F_51 ( V_26 ) ) ;
}
static T_7 F_52 ( struct V_73 * V_73 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_25 * V_26 = F_53 ( V_73 ) ;
T_1 V_78 , V_79 ;
char * V_80 = V_77 ;
int V_31 ;
if ( ! V_26 )
return - V_48 ;
F_54 ( & V_26 -> V_46 ) ;
if ( V_26 -> V_81 == V_82 ) {
V_79 = V_26 -> V_5 . V_10 ;
V_78 = V_26 -> V_83 ;
} else if ( V_26 -> V_84 ) {
V_79 = V_26 -> V_84 -> V_85 ;
V_78 = F_55 () ;
} else
return - V_86 ;
F_17 ( 1 , L_17 ,
( long long ) V_78 ,
( long long ) V_79 ) ;
for ( V_31 = 0 ; V_31 < F_56 ( V_87 ) ; V_31 ++ ) {
if ( V_78 & V_79 & V_87 [ V_31 ] . type )
V_80 += sprintf ( V_80 , L_18 , V_87 [ V_31 ] . V_2 ) ;
else if ( V_78 & V_87 [ V_31 ] . type )
V_80 += sprintf ( V_80 , L_19 , V_87 [ V_31 ] . V_2 ) ;
if ( V_78 & V_87 [ V_31 ] . type )
V_78 &= ~ V_87 [ V_31 ] . type ;
}
if ( V_80 != V_77 )
V_80 -- ;
* V_80 = '\n' ;
F_57 ( & V_26 -> V_46 ) ;
return V_80 + 1 - V_77 ;
}
static T_7 F_58 ( struct V_73 * V_73 ,
struct V_75 * V_76 ,
const char * V_88 ,
T_2 V_22 )
{
struct V_25 * V_26 = F_53 ( V_73 ) ;
bool V_89 , V_90 ;
const char * V_80 ;
T_1 type ;
T_1 V_91 ;
int V_6 , V_31 , V_92 = 0 ;
unsigned long V_45 ;
T_7 V_93 ;
if ( ! V_26 )
return - V_48 ;
F_54 ( & V_26 -> V_46 ) ;
if ( V_26 -> V_81 == V_82 )
type = V_26 -> V_5 . V_10 ;
else if ( V_26 -> V_84 )
type = V_26 -> V_84 -> V_85 ;
else {
F_17 ( 1 , L_20 ) ;
V_93 = - V_48 ;
goto V_49;
}
while ( ( V_80 = F_59 ( ( char * * ) & V_88 , L_21 ) ) != NULL ) {
if ( ! * V_80 )
break;
if ( * V_80 == '+' ) {
V_89 = true ;
V_90 = false ;
V_80 ++ ;
} else if ( * V_80 == '-' ) {
V_89 = false ;
V_90 = true ;
V_80 ++ ;
} else {
V_89 = false ;
V_90 = false ;
}
for ( V_31 = 0 ; V_31 < F_56 ( V_87 ) ; V_31 ++ ) {
if ( ! strcasecmp ( V_80 , V_87 [ V_31 ] . V_2 ) ) {
V_91 = V_87 [ V_31 ] . type ;
break;
}
}
if ( V_31 == F_56 ( V_87 ) ) {
F_17 ( 1 , L_22 , V_80 ) ;
return - V_48 ;
}
V_92 ++ ;
if ( V_89 )
type |= V_91 ;
else if ( V_90 )
type &= ~ V_91 ;
else
type = V_91 ;
}
if ( ! V_92 ) {
F_17 ( 1 , L_23 ) ;
V_93 = - V_48 ;
goto V_49;
}
if ( V_26 -> V_94 ) {
V_6 = V_26 -> V_94 ( V_26 , & type ) ;
if ( V_6 < 0 ) {
F_17 ( 1 , L_24 ,
( long long ) type ) ;
V_93 = - V_48 ;
goto V_49;
}
}
if ( V_26 -> V_81 == V_82 ) {
F_27 ( & V_26 -> V_5 . V_46 , V_45 ) ;
V_26 -> V_5 . V_10 = type ;
F_29 ( & V_26 -> V_5 . V_46 , V_45 ) ;
} else {
V_26 -> V_84 -> V_85 = type ;
}
F_17 ( 1 , L_25 ,
( long long ) type ) ;
V_93 = V_22 ;
V_49:
F_57 ( & V_26 -> V_46 ) ;
return V_93 ;
}
static void F_60 ( struct V_73 * V_73 )
{
}
static int F_61 ( struct V_73 * V_73 , struct V_95 * V_96 )
{
struct V_25 * V_26 = F_53 ( V_73 ) ;
if ( ! V_26 || ! V_26 -> V_35 )
return - V_86 ;
if ( V_26 -> V_5 . V_2 )
F_62 ( L_26 , V_26 -> V_5 . V_2 ) ;
if ( V_26 -> V_97 )
F_62 ( L_27 , V_26 -> V_97 ) ;
return 0 ;
}
struct V_25 * F_63 ( void )
{
struct V_25 * V_26 ;
V_26 = F_64 ( sizeof( * V_26 ) , V_15 ) ;
if ( ! V_26 )
return NULL ;
V_26 -> V_35 = F_65 () ;
if ( ! V_26 -> V_35 ) {
F_19 ( V_26 ) ;
return NULL ;
}
V_26 -> V_35 -> V_98 = F_32 ;
V_26 -> V_35 -> V_99 = F_25 ;
F_66 ( V_26 -> V_35 , V_26 ) ;
F_67 ( & V_26 -> V_5 . V_46 ) ;
F_67 ( & V_26 -> V_59 ) ;
F_68 ( & V_26 -> V_46 ) ;
F_69 ( & V_26 -> V_67 , F_38 , ( unsigned long ) V_26 ) ;
V_26 -> V_26 . type = & V_100 ;
V_26 -> V_26 . V_101 = & V_102 ;
F_70 ( & V_26 -> V_26 ) ;
F_71 ( V_103 ) ;
return V_26 ;
}
void F_72 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
if ( V_26 -> V_35 )
F_73 ( V_26 -> V_35 ) ;
F_74 ( & V_26 -> V_26 ) ;
F_19 ( V_26 ) ;
F_75 ( V_103 ) ;
}
int F_76 ( struct V_25 * V_26 )
{
static bool V_104 = false ;
static T_8 V_105 = F_77 ( 0 ) ;
struct V_5 * V_5 ;
const char * V_106 ;
int V_6 ;
if ( ! V_26 || ! V_26 -> V_107 )
return - V_48 ;
V_5 = F_5 ( V_26 -> V_107 ) ;
if ( ! V_5 )
V_5 = F_5 ( V_108 ) ;
if ( ! V_5 || ! V_5 -> V_14 || V_5 -> V_11 == 0 )
return - V_48 ;
F_78 ( V_109 , V_26 -> V_35 -> V_110 ) ;
F_78 ( V_111 , V_26 -> V_35 -> V_110 ) ;
F_78 ( V_62 , V_26 -> V_35 -> V_110 ) ;
F_78 ( V_63 , V_26 -> V_35 -> V_112 ) ;
if ( V_26 -> V_71 )
V_26 -> V_35 -> V_71 = F_47 ;
if ( V_26 -> V_72 )
V_26 -> V_35 -> V_72 = F_48 ;
F_54 ( & V_26 -> V_46 ) ;
V_26 -> V_105 = ( unsigned long ) ( F_79 ( & V_105 ) - 1 ) ;
F_80 ( & V_26 -> V_26 , L_28 , V_26 -> V_105 ) ;
F_81 ( & V_26 -> V_26 , V_26 ) ;
V_6 = F_82 ( & V_26 -> V_26 ) ;
if ( V_6 )
goto V_113;
V_6 = F_30 ( V_26 , V_5 ) ;
if ( V_6 )
goto V_114;
V_26 -> V_35 -> V_26 . V_115 = & V_26 -> V_26 ;
memcpy ( & V_26 -> V_35 -> V_116 , & V_26 -> V_117 , sizeof( V_26 -> V_117 ) ) ;
V_26 -> V_35 -> V_118 = V_26 -> V_119 ;
V_26 -> V_35 -> V_2 = V_26 -> V_55 ;
V_6 = F_83 ( V_26 -> V_35 ) ;
if ( V_6 )
goto V_120;
V_26 -> V_35 -> V_121 [ V_122 ] = 500 ;
V_26 -> V_35 -> V_121 [ V_123 ] = 125 ;
V_106 = F_84 ( & V_26 -> V_26 . V_124 , V_15 ) ;
F_8 ( V_8 L_29 ,
F_51 ( & V_26 -> V_26 ) ,
V_26 -> V_55 ? V_26 -> V_55 : L_30 ,
V_106 ? V_106 : L_31 ) ;
F_19 ( V_106 ) ;
if ( V_26 -> V_81 == V_125 ) {
if ( ! V_104 ) {
F_17 ( 1 , L_32 ) ;
F_85 () ;
V_104 = true ;
}
V_6 = F_86 ( V_26 ) ;
if ( V_6 < 0 )
goto V_126;
}
if ( V_26 -> V_94 ) {
T_1 V_10 = ( 1 << V_5 -> V_10 ) ;
V_6 = V_26 -> V_94 ( V_26 , & V_10 ) ;
if ( V_6 < 0 )
goto V_127;
}
F_57 ( & V_26 -> V_46 ) ;
F_17 ( 1 , L_33 ,
V_26 -> V_105 ,
V_26 -> V_97 ? V_26 -> V_97 : L_34 ,
V_5 -> V_2 ? V_5 -> V_2 : L_34 ,
V_26 -> V_81 == V_125 ? L_35 : L_36 ) ;
return 0 ;
V_127:
if ( V_26 -> V_81 == V_125 )
F_87 ( V_26 ) ;
V_126:
F_88 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
V_120:
F_18 ( & V_26 -> V_5 ) ;
V_114:
F_89 ( & V_26 -> V_26 ) ;
V_113:
F_57 ( & V_26 -> V_46 ) ;
return V_6 ;
}
void F_90 ( struct V_25 * V_26 )
{
if ( ! V_26 )
return;
F_91 ( & V_26 -> V_67 ) ;
if ( V_26 -> V_81 == V_125 )
F_87 ( V_26 ) ;
F_18 ( & V_26 -> V_5 ) ;
F_17 ( 1 , L_37 ) ;
F_88 ( V_26 -> V_35 ) ;
V_26 -> V_35 = NULL ;
F_89 ( & V_26 -> V_26 ) ;
F_72 ( V_26 ) ;
}
static int T_9 F_92 ( void )
{
int V_6 = F_93 ( & V_102 ) ;
if ( V_6 ) {
F_8 ( V_7 L_38 ) ;
return V_6 ;
}
F_10 ( & V_128 ) ;
return 0 ;
}
static void T_10 F_94 ( void )
{
F_95 ( & V_102 ) ;
F_12 ( & V_128 ) ;
}
