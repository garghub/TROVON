static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
return sprintf ( V_5 , L_1 , F_2 ( V_2 ) -> V_6 ) ;
}
static T_2 F_3 ( struct V_7 * V_8 ,
struct V_9 * V_4 , int V_10 )
{
struct V_1 * V_2 = F_4 ( V_8 , struct V_1 , V_8 ) ;
if ( F_2 ( V_2 ) -> V_6 == NULL )
return 0 ;
return V_4 -> V_11 ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_6 ( F_2 ( V_2 ) ) ;
}
static int F_7 ( void * V_12 , int * V_13 )
{
struct V_14 * V_15 = V_12 ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_18 ;
long V_19 ;
V_18 = V_17 -> V_20 -> V_21 -> V_22 ( & V_17 -> V_2 , V_23 , V_24 ,
V_15 -> V_25 , & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_13 = V_19 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_25 )
{
struct V_14 * V_15 ;
V_15 = F_9 ( V_2 , sizeof( * V_15 ) , V_26 ) ;
if ( ! V_15 )
return - V_27 ;
V_15 -> V_17 = V_17 ;
V_15 -> V_25 = V_25 ;
F_10 ( & V_17 -> V_2 , V_25 , V_15 ,
& V_28 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_16 * V_17 , int V_25 )
{
return 0 ;
}
static T_1 F_11 ( struct V_1 * V_2 ,
struct V_3 * V_29 , char * V_5 )
{
struct V_30 * V_31 = F_12 ( V_29 ) ;
long V_32 ;
int V_18 ;
V_18 = V_31 -> V_21 -> V_22 ( V_2 , V_31 -> type , V_31 -> V_4 , V_31 -> V_25 ,
& V_32 ) ;
if ( V_18 < 0 )
return V_18 ;
return sprintf ( V_5 , L_2 , V_32 ) ;
}
static T_1 F_13 ( struct V_1 * V_2 ,
struct V_3 * V_29 ,
char * V_5 )
{
struct V_30 * V_31 = F_12 ( V_29 ) ;
char * V_33 ;
int V_18 ;
V_18 = V_31 -> V_21 -> V_34 ( V_2 , V_31 -> type , V_31 -> V_4 ,
V_31 -> V_25 , & V_33 ) ;
if ( V_18 < 0 )
return V_18 ;
return sprintf ( V_5 , L_1 , V_33 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_3 * V_29 ,
const char * V_5 , T_3 V_35 )
{
struct V_30 * V_31 = F_12 ( V_29 ) ;
long V_32 ;
int V_18 ;
V_18 = F_15 ( V_5 , 10 , & V_32 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = V_31 -> V_21 -> V_36 ( V_2 , V_31 -> type , V_31 -> V_4 , V_31 -> V_25 ,
V_32 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_35 ;
}
static int F_16 ( enum V_37 type )
{
if ( type == V_38 )
return 0 ;
return 1 ;
}
static bool F_17 ( enum V_37 type , T_4 V_4 )
{
return ( type == V_23 && V_4 == V_39 ) ||
( type == V_38 && V_4 == V_40 ) ||
( type == V_41 && V_4 == V_42 ) ||
( type == V_43 && V_4 == V_44 ) ||
( type == V_45 && V_4 == V_46 ) ||
( type == V_47 && V_4 == V_48 ) ||
( type == V_49 && V_4 == V_50 ) ;
}
static struct V_9 * F_18 ( struct V_1 * V_2 ,
const void * V_51 ,
enum V_37 type ,
T_4 V_4 ,
int V_25 ,
const char * V_52 ,
const struct V_53 * V_21 )
{
struct V_30 * V_31 ;
struct V_3 * V_54 ;
struct V_9 * V_55 ;
T_2 V_11 ;
char * V_6 ;
bool V_56 = F_17 ( type , V_4 ) ;
if ( ! V_52 )
return F_19 ( - V_57 ) ;
V_11 = V_21 -> V_58 ( V_51 , type , V_4 , V_25 ) ;
if ( ! V_11 )
return F_19 ( - V_57 ) ;
if ( ( V_11 & V_59 ) && ( ( V_56 && ! V_21 -> V_34 ) ||
( ! V_56 && ! V_21 -> V_22 ) ) )
return F_19 ( - V_60 ) ;
if ( ( V_11 & V_61 ) && ! V_21 -> V_36 )
return F_19 ( - V_60 ) ;
V_31 = F_9 ( V_2 , sizeof( * V_31 ) , V_26 ) ;
if ( ! V_31 )
return F_19 ( - V_27 ) ;
if ( type == V_62 ) {
V_6 = ( char * ) V_52 ;
} else {
F_20 ( V_31 -> V_6 , sizeof( V_31 -> V_6 ) , V_52 ,
V_25 + F_16 ( type ) ) ;
V_6 = V_31 -> V_6 ;
}
V_31 -> type = type ;
V_31 -> V_4 = V_4 ;
V_31 -> V_25 = V_25 ;
V_31 -> V_21 = V_21 ;
V_54 = & V_31 -> V_63 ;
V_54 -> V_64 = V_56 ? F_13 : F_11 ;
V_54 -> V_65 = F_14 ;
V_55 = & V_54 -> V_4 ;
F_21 ( V_55 ) ;
V_55 -> V_6 = V_6 ;
V_55 -> V_11 = V_11 ;
return V_55 ;
}
static int F_22 ( const struct V_66 * V_67 )
{
int V_68 , V_10 ;
for ( V_68 = V_10 = 0 ; V_67 -> V_69 [ V_68 ] ; V_68 ++ )
V_10 += F_23 ( V_67 -> V_69 [ V_68 ] ) ;
return V_10 ;
}
static int F_24 ( struct V_1 * V_2 ,
const void * V_51 ,
struct V_9 * * V_70 ,
const struct V_53 * V_21 ,
const struct V_66 * V_67 )
{
const char * const * V_71 ;
int V_72 ;
int V_68 , V_73 = 0 ;
if ( V_67 -> type >= F_25 ( V_74 ) )
return - V_60 ;
V_71 = V_74 [ V_67 -> type ] ;
V_72 = V_75 [ V_67 -> type ] ;
for ( V_68 = 0 ; V_67 -> V_69 [ V_68 ] ; V_68 ++ ) {
T_4 V_76 = V_67 -> V_69 [ V_68 ] ;
T_4 V_4 ;
while ( V_76 ) {
struct V_9 * V_55 ;
V_4 = F_26 ( V_76 ) ;
V_76 &= ~ F_27 ( V_4 ) ;
if ( V_4 >= V_72 )
return - V_60 ;
V_55 = F_18 ( V_2 , V_51 , V_67 -> type , V_4 , V_68 ,
V_71 [ V_4 ] , V_21 ) ;
if ( F_28 ( V_55 ) ) {
if ( F_29 ( V_55 ) != - V_57 )
return F_29 ( V_55 ) ;
continue;
}
V_70 [ V_73 ++ ] = V_55 ;
}
}
return V_73 ;
}
static struct V_9 * *
F_30 ( struct V_1 * V_2 , const void * V_51 ,
const struct V_77 * V_20 )
{
int V_18 , V_68 , V_73 = 0 , V_78 = 0 ;
struct V_9 * * V_70 ;
for ( V_68 = 0 ; V_20 -> V_67 [ V_68 ] ; V_68 ++ )
V_78 += F_22 ( V_20 -> V_67 [ V_68 ] ) ;
if ( V_78 == 0 )
return F_19 ( - V_60 ) ;
V_70 = F_31 ( V_2 , V_78 + 1 , sizeof( * V_70 ) , V_26 ) ;
if ( ! V_70 )
return F_19 ( - V_27 ) ;
for ( V_68 = 0 ; V_20 -> V_67 [ V_68 ] ; V_68 ++ ) {
V_18 = F_24 ( V_2 , V_51 , & V_70 [ V_73 ] , V_20 -> V_21 ,
V_20 -> V_67 [ V_68 ] ) ;
if ( V_18 < 0 )
return F_19 ( V_18 ) ;
V_73 += V_18 ;
}
return V_70 ;
}
static struct V_1 *
F_32 ( struct V_1 * V_2 , const char * V_6 , void * V_51 ,
const struct V_77 * V_20 ,
const struct V_79 * * V_80 )
{
struct V_16 * V_17 ;
struct V_1 * V_81 ;
int V_68 , V_82 , V_83 , V_84 ;
if ( V_6 && ( ! strlen ( V_6 ) || strpbrk ( V_6 , L_3 ) ) )
return F_19 ( - V_60 ) ;
V_84 = F_33 ( & V_85 , 0 , 0 , V_26 ) ;
if ( V_84 < 0 )
return F_19 ( V_84 ) ;
V_17 = F_34 ( sizeof( * V_17 ) , V_26 ) ;
if ( V_17 == NULL ) {
V_83 = - V_27 ;
goto V_86;
}
V_81 = & V_17 -> V_2 ;
if ( V_20 ) {
struct V_9 * * V_70 ;
int V_87 = 2 ;
if ( V_80 )
for ( V_68 = 0 ; V_80 [ V_68 ] ; V_68 ++ )
V_87 ++ ;
V_17 -> V_80 = F_31 ( V_2 , V_87 , sizeof( * V_80 ) ,
V_26 ) ;
if ( ! V_17 -> V_80 ) {
V_83 = - V_27 ;
goto V_88;
}
V_70 = F_30 ( V_2 , V_51 , V_20 ) ;
if ( F_28 ( V_70 ) ) {
V_83 = F_29 ( V_70 ) ;
goto V_88;
}
V_17 -> V_89 . V_70 = V_70 ;
V_87 = 0 ;
V_17 -> V_80 [ V_87 ++ ] = & V_17 -> V_89 ;
if ( V_80 ) {
for ( V_68 = 0 ; V_80 [ V_68 ] ; V_68 ++ )
V_17 -> V_80 [ V_87 ++ ] = V_80 [ V_68 ] ;
}
V_81 -> V_80 = V_17 -> V_80 ;
} else {
V_81 -> V_80 = V_80 ;
}
V_17 -> V_6 = V_6 ;
V_81 -> V_90 = & V_91 ;
V_81 -> V_92 = V_2 ;
V_81 -> V_93 = V_2 ? V_2 -> V_93 : NULL ;
V_17 -> V_20 = V_20 ;
F_35 ( V_81 , V_51 ) ;
F_36 ( V_81 , V_94 , V_84 ) ;
V_83 = F_37 ( V_81 ) ;
if ( V_83 )
goto V_88;
if ( V_20 && V_20 -> V_21 -> V_22 &&
V_20 -> V_67 [ 0 ] -> type == V_62 &&
( V_20 -> V_67 [ 0 ] -> V_69 [ 0 ] & V_95 ) ) {
const struct V_66 * * V_67 = V_20 -> V_67 ;
for ( V_68 = 1 ; V_67 [ V_68 ] ; V_68 ++ ) {
if ( V_67 [ V_68 ] -> type != V_23 )
continue;
for ( V_82 = 0 ; V_67 [ V_68 ] -> V_69 [ V_82 ] ; V_82 ++ ) {
if ( ! V_20 -> V_21 -> V_58 ( V_51 , V_23 ,
V_24 , V_82 ) )
continue;
if ( V_67 [ V_68 ] -> V_69 [ V_82 ] & V_96 )
F_8 ( V_2 , V_17 , V_82 ) ;
}
}
}
return V_81 ;
V_88:
F_6 ( V_17 ) ;
V_86:
F_38 ( & V_85 , V_84 ) ;
return F_19 ( V_83 ) ;
}
struct V_1 *
F_39 ( struct V_1 * V_2 , const char * V_6 ,
void * V_51 ,
const struct V_79 * * V_80 )
{
return F_32 ( V_2 , V_6 , V_51 , NULL , V_80 ) ;
}
struct V_1 *
F_40 ( struct V_1 * V_2 , const char * V_6 ,
void * V_51 ,
const struct V_77 * V_20 ,
const struct V_79 * * V_97 )
{
if ( V_20 && ( ! V_20 -> V_21 || ! V_20 -> V_21 -> V_58 || ! V_20 -> V_67 ) )
return F_19 ( - V_60 ) ;
return F_32 ( V_2 , V_6 , V_51 , V_20 , V_97 ) ;
}
struct V_1 * F_41 ( struct V_1 * V_2 )
{
F_42 ( V_2 ,
L_4 ) ;
return F_39 ( V_2 , NULL , NULL , NULL ) ;
}
void F_43 ( struct V_1 * V_2 )
{
int V_84 ;
if ( F_44 ( sscanf ( F_45 ( V_2 ) , V_94 , & V_84 ) == 1 ) ) {
F_46 ( V_2 ) ;
F_38 ( & V_85 , V_84 ) ;
} else
F_47 ( V_2 -> V_92 ,
L_5 ) ;
}
static void F_48 ( struct V_1 * V_2 , void * V_98 )
{
struct V_1 * V_17 = * (struct V_1 * * ) V_98 ;
F_43 ( V_17 ) ;
}
struct V_1 *
F_49 ( struct V_1 * V_2 , const char * V_6 ,
void * V_51 ,
const struct V_79 * * V_80 )
{
struct V_1 * * V_99 , * V_17 ;
if ( ! V_2 )
return F_19 ( - V_60 ) ;
V_99 = F_50 ( F_48 , sizeof( * V_99 ) , V_26 ) ;
if ( ! V_99 )
return F_19 ( - V_27 ) ;
V_17 = F_39 ( V_2 , V_6 , V_51 , V_80 ) ;
if ( F_28 ( V_17 ) )
goto error;
* V_99 = V_17 ;
F_51 ( V_2 , V_99 ) ;
return V_17 ;
error:
F_52 ( V_99 ) ;
return V_17 ;
}
struct V_1 *
F_53 ( struct V_1 * V_2 , const char * V_6 ,
void * V_51 ,
const struct V_77 * V_20 ,
const struct V_79 * * V_80 )
{
struct V_1 * * V_99 , * V_17 ;
if ( ! V_2 )
return F_19 ( - V_60 ) ;
V_99 = F_50 ( F_48 , sizeof( * V_99 ) , V_26 ) ;
if ( ! V_99 )
return F_19 ( - V_27 ) ;
V_17 = F_40 ( V_2 , V_6 , V_51 , V_20 ,
V_80 ) ;
if ( F_28 ( V_17 ) )
goto error;
* V_99 = V_17 ;
F_51 ( V_2 , V_99 ) ;
return V_17 ;
error:
F_52 ( V_99 ) ;
return V_17 ;
}
static int F_54 ( struct V_1 * V_2 , void * V_98 , void * V_12 )
{
struct V_1 * * V_17 = V_98 ;
return * V_17 == V_12 ;
}
void F_55 ( struct V_1 * V_2 )
{
F_56 ( F_57 ( V_2 , F_48 , F_54 , V_2 ) ) ;
}
static void T_5 F_58 ( void )
{
#if V_100 V_101 && V_100 V_102
struct V_103 * V_104 ;
T_6 V_105 ;
T_7 V_106 ;
V_104 = F_59 ( V_107 , 0x436c , NULL ) ;
if ( V_104 ) {
if ( V_104 -> V_108 == 0x1462 &&
V_104 -> V_109 == 0x0031 ) {
F_60 ( V_104 , 0x48 , & V_106 ) ;
F_61 ( V_104 , 0x64 , & V_105 ) ;
if ( V_105 == 0 && ! ( V_106 & F_27 ( 2 ) ) ) {
F_62 ( & V_104 -> V_2 ,
L_6 ) ;
F_63 ( V_104 , 0x64 , 0x295 ) ;
F_64 ( V_104 , 0x48 ,
V_106 | F_27 ( 2 ) ) ;
}
}
F_65 ( V_104 ) ;
}
#endif
}
static int T_5 F_66 ( void )
{
int V_83 ;
F_58 () ;
V_83 = F_67 ( & V_91 ) ;
if ( V_83 ) {
F_68 ( L_7 ) ;
return V_83 ;
}
return 0 ;
}
static void T_8 F_69 ( void )
{
F_70 ( & V_91 ) ;
}
