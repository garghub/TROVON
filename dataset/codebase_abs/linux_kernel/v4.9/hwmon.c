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
const char * V_5 , T_3 V_33 )
{
struct V_30 * V_31 = F_12 ( V_29 ) ;
long V_32 ;
int V_18 ;
V_18 = F_14 ( V_5 , 10 , & V_32 ) ;
if ( V_18 < 0 )
return V_18 ;
V_18 = V_31 -> V_21 -> V_34 ( V_2 , V_31 -> type , V_31 -> V_4 , V_31 -> V_25 ,
V_32 ) ;
if ( V_18 < 0 )
return V_18 ;
return V_33 ;
}
static int F_15 ( enum V_35 type )
{
if ( type == V_36 )
return 0 ;
return 1 ;
}
static struct V_9 * F_16 ( struct V_1 * V_2 ,
const void * V_37 ,
enum V_35 type ,
T_4 V_4 ,
int V_25 ,
const char * V_38 ,
const struct V_39 * V_21 )
{
struct V_30 * V_31 ;
struct V_3 * V_40 ;
struct V_9 * V_41 ;
T_2 V_11 ;
char * V_6 ;
if ( ! V_38 )
return F_17 ( - V_42 ) ;
V_11 = V_21 -> V_43 ( V_37 , type , V_4 , V_25 ) ;
if ( ! V_11 )
return F_17 ( - V_42 ) ;
if ( ( V_11 & V_44 ) && ! V_21 -> V_22 )
return F_17 ( - V_45 ) ;
if ( ( V_11 & V_46 ) && ! V_21 -> V_34 )
return F_17 ( - V_45 ) ;
if ( type == V_47 ) {
V_6 = ( char * ) V_38 ;
} else {
V_6 = F_9 ( V_2 , strlen ( V_38 ) + 16 , V_26 ) ;
if ( ! V_6 )
return F_17 ( - V_27 ) ;
F_18 ( V_6 , strlen ( V_38 ) + 16 , V_38 ,
V_25 + F_15 ( type ) ) ;
}
V_31 = F_9 ( V_2 , sizeof( * V_31 ) , V_26 ) ;
if ( ! V_31 )
return F_17 ( - V_27 ) ;
V_31 -> type = type ;
V_31 -> V_4 = V_4 ;
V_31 -> V_25 = V_25 ;
V_31 -> V_21 = V_21 ;
V_40 = & V_31 -> V_48 ;
V_40 -> V_49 = F_11 ;
V_40 -> V_50 = F_13 ;
V_41 = & V_40 -> V_4 ;
F_19 ( V_41 ) ;
V_41 -> V_6 = V_6 ;
V_41 -> V_11 = V_11 ;
return V_41 ;
}
static int F_20 ( const struct V_51 * V_52 )
{
int V_53 , V_10 ;
for ( V_53 = V_10 = 0 ; V_52 -> V_54 [ V_53 ] ; V_53 ++ )
V_10 += F_21 ( V_52 -> V_54 [ V_53 ] ) ;
return V_10 ;
}
static int F_22 ( struct V_1 * V_2 ,
const void * V_37 ,
struct V_9 * * V_55 ,
const struct V_39 * V_21 ,
const struct V_51 * V_52 )
{
const char * const * V_56 ;
int V_57 ;
int V_53 , V_58 = 0 ;
if ( V_52 -> type >= F_23 ( V_59 ) )
return - V_45 ;
V_56 = V_59 [ V_52 -> type ] ;
V_57 = V_60 [ V_52 -> type ] ;
for ( V_53 = 0 ; V_52 -> V_54 [ V_53 ] ; V_53 ++ ) {
T_4 V_61 = V_52 -> V_54 [ V_53 ] ;
T_4 V_4 ;
while ( V_61 ) {
struct V_9 * V_41 ;
V_4 = F_24 ( V_61 ) ;
V_61 &= ~ F_25 ( V_4 ) ;
if ( V_4 >= V_57 )
return - V_45 ;
V_41 = F_16 ( V_2 , V_37 , V_52 -> type , V_4 , V_53 ,
V_56 [ V_4 ] , V_21 ) ;
if ( F_26 ( V_41 ) ) {
if ( F_27 ( V_41 ) != - V_42 )
return F_27 ( V_41 ) ;
continue;
}
V_55 [ V_58 ++ ] = V_41 ;
}
}
return V_58 ;
}
static struct V_9 * *
F_28 ( struct V_1 * V_2 , const void * V_37 ,
const struct V_62 * V_20 )
{
int V_18 , V_53 , V_58 = 0 , V_63 = 0 ;
struct V_9 * * V_55 ;
for ( V_53 = 0 ; V_20 -> V_52 [ V_53 ] ; V_53 ++ )
V_63 += F_20 ( V_20 -> V_52 [ V_53 ] ) ;
if ( V_63 == 0 )
return F_17 ( - V_45 ) ;
V_55 = F_29 ( V_2 , V_63 + 1 , sizeof( * V_55 ) , V_26 ) ;
if ( ! V_55 )
return F_17 ( - V_27 ) ;
for ( V_53 = 0 ; V_20 -> V_52 [ V_53 ] ; V_53 ++ ) {
V_18 = F_22 ( V_2 , V_37 , & V_55 [ V_58 ] , V_20 -> V_21 ,
V_20 -> V_52 [ V_53 ] ) ;
if ( V_18 < 0 )
return F_17 ( V_18 ) ;
V_58 += V_18 ;
}
return V_55 ;
}
static struct V_1 *
F_30 ( struct V_1 * V_2 , const char * V_6 , void * V_37 ,
const struct V_62 * V_20 ,
const struct V_64 * * V_65 )
{
struct V_16 * V_17 ;
struct V_1 * V_66 ;
int V_53 , V_67 , V_68 , V_69 ;
if ( V_6 && ( ! strlen ( V_6 ) || strpbrk ( V_6 , L_3 ) ) )
return F_17 ( - V_45 ) ;
V_69 = F_31 ( & V_70 , 0 , 0 , V_26 ) ;
if ( V_69 < 0 )
return F_17 ( V_69 ) ;
V_17 = F_32 ( sizeof( * V_17 ) , V_26 ) ;
if ( V_17 == NULL ) {
V_68 = - V_27 ;
goto V_71;
}
V_66 = & V_17 -> V_2 ;
if ( V_20 && V_20 -> V_21 -> V_43 ) {
struct V_9 * * V_55 ;
int V_72 = 2 ;
if ( V_65 )
for ( V_53 = 0 ; V_65 [ V_53 ] ; V_53 ++ )
V_72 ++ ;
V_17 -> V_65 = F_29 ( V_2 , V_72 , sizeof( * V_65 ) ,
V_26 ) ;
if ( ! V_17 -> V_65 ) {
V_68 = - V_27 ;
goto V_73;
}
V_55 = F_28 ( V_2 , V_37 , V_20 ) ;
if ( F_26 ( V_55 ) ) {
V_68 = F_27 ( V_55 ) ;
goto V_73;
}
V_17 -> V_74 . V_55 = V_55 ;
V_72 = 0 ;
V_17 -> V_65 [ V_72 ++ ] = & V_17 -> V_74 ;
if ( V_65 ) {
for ( V_53 = 0 ; V_65 [ V_53 ] ; V_53 ++ )
V_17 -> V_65 [ V_72 ++ ] = V_65 [ V_53 ] ;
}
V_66 -> V_65 = V_17 -> V_65 ;
} else {
V_66 -> V_65 = V_65 ;
}
V_17 -> V_6 = V_6 ;
V_66 -> V_75 = & V_76 ;
V_66 -> V_77 = V_2 ;
V_66 -> V_78 = V_2 ? V_2 -> V_78 : NULL ;
V_17 -> V_20 = V_20 ;
F_33 ( V_66 , V_37 ) ;
F_34 ( V_66 , V_79 , V_69 ) ;
V_68 = F_35 ( V_66 ) ;
if ( V_68 )
goto V_73;
if ( V_20 && V_20 -> V_21 -> V_43 && V_20 -> V_21 -> V_22 &&
V_20 -> V_52 [ 0 ] -> type == V_47 &&
( V_20 -> V_52 [ 0 ] -> V_54 [ 0 ] & V_80 ) ) {
const struct V_51 * * V_52 = V_20 -> V_52 ;
for ( V_53 = 1 ; V_52 [ V_53 ] ; V_53 ++ ) {
if ( V_52 [ V_53 ] -> type != V_23 )
continue;
for ( V_67 = 0 ; V_52 [ V_53 ] -> V_54 [ V_67 ] ; V_67 ++ ) {
if ( ! V_20 -> V_21 -> V_43 ( V_37 , V_23 ,
V_24 , V_67 ) )
continue;
if ( V_52 [ V_53 ] -> V_54 [ V_67 ] & V_81 )
F_8 ( V_2 , V_17 , V_67 ) ;
}
}
}
return V_66 ;
V_73:
F_6 ( V_17 ) ;
V_71:
F_36 ( & V_70 , V_69 ) ;
return F_17 ( V_68 ) ;
}
struct V_1 *
F_37 ( struct V_1 * V_2 , const char * V_6 ,
void * V_37 ,
const struct V_64 * * V_65 )
{
return F_30 ( V_2 , V_6 , V_37 , NULL , V_65 ) ;
}
struct V_1 *
F_38 ( struct V_1 * V_2 , const char * V_6 ,
void * V_37 ,
const struct V_62 * V_20 ,
const struct V_64 * * V_65 )
{
if ( V_20 && ( ! V_20 -> V_21 || ! V_20 -> V_52 ) )
return F_17 ( - V_45 ) ;
return F_30 ( V_2 , V_6 , V_37 , V_20 , V_65 ) ;
}
struct V_1 * F_39 ( struct V_1 * V_2 )
{
return F_37 ( V_2 , NULL , NULL , NULL ) ;
}
void F_40 ( struct V_1 * V_2 )
{
int V_69 ;
if ( F_41 ( sscanf ( F_42 ( V_2 ) , V_79 , & V_69 ) == 1 ) ) {
F_43 ( V_2 ) ;
F_36 ( & V_70 , V_69 ) ;
} else
F_44 ( V_2 -> V_77 ,
L_4 ) ;
}
static void F_45 ( struct V_1 * V_2 , void * V_82 )
{
struct V_1 * V_17 = * (struct V_1 * * ) V_82 ;
F_40 ( V_17 ) ;
}
struct V_1 *
F_46 ( struct V_1 * V_2 , const char * V_6 ,
void * V_37 ,
const struct V_64 * * V_65 )
{
struct V_1 * * V_83 , * V_17 ;
if ( ! V_2 )
return F_17 ( - V_45 ) ;
V_83 = F_47 ( F_45 , sizeof( * V_83 ) , V_26 ) ;
if ( ! V_83 )
return F_17 ( - V_27 ) ;
V_17 = F_37 ( V_2 , V_6 , V_37 , V_65 ) ;
if ( F_26 ( V_17 ) )
goto error;
* V_83 = V_17 ;
F_48 ( V_2 , V_83 ) ;
return V_17 ;
error:
F_49 ( V_83 ) ;
return V_17 ;
}
struct V_1 *
F_50 ( struct V_1 * V_2 , const char * V_6 ,
void * V_37 ,
const struct V_62 * V_20 ,
const struct V_64 * * V_65 )
{
struct V_1 * * V_83 , * V_17 ;
if ( ! V_2 )
return F_17 ( - V_45 ) ;
V_83 = F_47 ( F_45 , sizeof( * V_83 ) , V_26 ) ;
if ( ! V_83 )
return F_17 ( - V_27 ) ;
V_17 = F_38 ( V_2 , V_6 , V_37 , V_20 ,
V_65 ) ;
if ( F_26 ( V_17 ) )
goto error;
* V_83 = V_17 ;
F_48 ( V_2 , V_83 ) ;
return V_17 ;
error:
F_49 ( V_83 ) ;
return V_17 ;
}
static int F_51 ( struct V_1 * V_2 , void * V_82 , void * V_12 )
{
struct V_1 * * V_17 = V_82 ;
return * V_17 == V_12 ;
}
void F_52 ( struct V_1 * V_2 )
{
F_53 ( F_54 ( V_2 , F_45 , F_51 , V_2 ) ) ;
}
static void T_5 F_55 ( void )
{
#if V_84 V_85 && V_84 V_86
struct V_87 * V_88 ;
T_6 V_89 ;
T_7 V_90 ;
V_88 = F_56 ( V_91 , 0x436c , NULL ) ;
if ( V_88 ) {
if ( V_88 -> V_92 == 0x1462 &&
V_88 -> V_93 == 0x0031 ) {
F_57 ( V_88 , 0x48 , & V_90 ) ;
F_58 ( V_88 , 0x64 , & V_89 ) ;
if ( V_89 == 0 && ! ( V_90 & F_25 ( 2 ) ) ) {
F_59 ( & V_88 -> V_2 ,
L_5 ) ;
F_60 ( V_88 , 0x64 , 0x295 ) ;
F_61 ( V_88 , 0x48 ,
V_90 | F_25 ( 2 ) ) ;
}
}
F_62 ( V_88 ) ;
}
#endif
}
static int T_5 F_63 ( void )
{
int V_68 ;
F_55 () ;
V_68 = F_64 ( & V_76 ) ;
if ( V_68 ) {
F_65 ( L_6 ) ;
return V_68 ;
}
return 0 ;
}
static void T_8 F_66 ( void )
{
F_67 ( & V_76 ) ;
}
