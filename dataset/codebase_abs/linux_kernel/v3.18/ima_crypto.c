static int F_1 ( const char * V_1 , const struct V_2 * V_3 )
{
unsigned long long V_4 ;
int V_5 ;
V_4 = F_2 ( V_1 , NULL ) ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 >= V_6 )
return - V_7 ;
V_8 = V_5 ;
V_9 = V_10 << V_5 ;
return 0 ;
}
static int F_4 ( struct V_11 * V_11 , T_1 V_12 ,
char * V_13 , unsigned long V_14 )
{
T_2 V_15 ;
char T_3 * V_16 = V_13 ;
T_4 V_17 = - V_7 ;
if ( ! ( V_11 -> V_18 & V_19 ) )
return - V_20 ;
V_15 = F_5 () ;
F_6 ( F_7 () ) ;
if ( V_11 -> V_21 -> V_22 )
V_17 = V_11 -> V_21 -> V_22 ( V_11 , V_16 , V_14 , & V_12 ) ;
else if ( V_11 -> V_21 -> V_23 )
V_17 = F_8 ( V_11 , V_16 , V_14 , & V_12 ) ;
else if ( V_11 -> V_21 -> V_24 )
V_17 = F_9 ( V_11 , V_16 , V_14 , & V_12 ) ;
F_6 ( V_15 ) ;
return V_17 ;
}
int T_5 F_10 ( void )
{
long V_25 ;
V_26 = F_11 ( V_27 [ V_28 ] , 0 , 0 ) ;
if ( F_12 ( V_26 ) ) {
V_25 = F_13 ( V_26 ) ;
F_14 ( L_1 ,
V_27 [ V_28 ] , V_25 ) ;
return V_25 ;
}
return 0 ;
}
static struct V_29 * F_15 ( enum V_30 V_31 )
{
struct V_29 * V_32 = V_26 ;
int V_25 ;
if ( V_31 < 0 || V_31 >= V_33 )
V_31 = V_28 ;
if ( V_31 != V_28 ) {
V_32 = F_11 ( V_27 [ V_31 ] , 0 , 0 ) ;
if ( F_12 ( V_32 ) ) {
V_25 = F_13 ( V_32 ) ;
F_14 ( L_2 ,
V_27 [ V_31 ] , V_25 ) ;
}
}
return V_32 ;
}
static void F_16 ( struct V_29 * V_32 )
{
if ( V_32 != V_26 )
F_17 ( V_32 ) ;
}
static void * F_18 ( T_1 V_34 , T_6 * V_35 ,
int V_36 )
{
void * V_37 ;
int V_5 = V_8 ;
T_7 V_38 = V_39 | V_40 | V_41 ;
if ( V_5 )
V_5 = F_19 ( F_3 ( V_34 ) , V_5 ) ;
for (; V_5 ; V_5 -- ) {
V_37 = ( void * ) F_20 ( V_38 , V_5 ) ;
if ( V_37 ) {
* V_35 = V_10 << V_5 ;
return V_37 ;
}
}
V_38 = V_42 ;
if ( ! V_36 )
V_38 |= V_40 ;
V_37 = ( void * ) F_20 ( V_38 , 0 ) ;
if ( V_37 ) {
* V_35 = V_10 ;
return V_37 ;
}
* V_35 = 0 ;
return NULL ;
}
static void F_21 ( void * V_37 , T_6 V_4 )
{
if ( ! V_37 )
return;
F_22 ( ( unsigned long ) V_37 , F_3 ( V_4 ) ) ;
}
static struct V_43 * F_23 ( enum V_30 V_31 )
{
struct V_43 * V_32 = V_44 ;
int V_25 ;
if ( V_31 < 0 || V_31 >= V_33 )
V_31 = V_28 ;
if ( V_31 != V_28 || ! V_32 ) {
V_32 = F_24 ( V_27 [ V_31 ] , 0 , 0 ) ;
if ( ! F_12 ( V_32 ) ) {
if ( V_31 == V_28 )
V_44 = V_32 ;
} else {
V_25 = F_13 ( V_32 ) ;
F_14 ( L_2 ,
V_27 [ V_31 ] , V_25 ) ;
}
}
return V_32 ;
}
static void F_25 ( struct V_43 * V_32 )
{
if ( V_32 != V_44 )
F_26 ( V_32 ) ;
}
static void F_27 ( struct V_45 * V_46 , int V_47 )
{
struct V_48 * V_49 = V_46 -> V_50 ;
if ( V_47 == - V_51 )
return;
V_49 -> V_47 = V_47 ;
F_28 ( & V_49 -> V_52 ) ;
}
static int F_29 ( int V_47 , struct V_48 * V_49 )
{
switch ( V_47 ) {
case 0 :
break;
case - V_51 :
case - V_53 :
F_30 ( & V_49 -> V_52 ) ;
F_31 ( & V_49 -> V_52 ) ;
V_47 = V_49 -> V_47 ;
default:
F_32 ( L_3 , V_47 ) ;
}
return V_47 ;
}
static int F_33 ( struct V_11 * V_11 ,
struct V_54 * V_55 ,
struct V_43 * V_32 )
{
T_1 V_56 , V_12 ;
char * V_57 [ 2 ] = { NULL , } ;
int V_25 , V_22 = 0 , V_58 , V_59 = 0 , V_60 = 0 ;
struct V_61 * V_46 ;
struct V_62 V_63 [ 1 ] ;
struct V_48 V_49 ;
T_6 V_64 [ 2 ] ;
V_55 -> V_65 = F_34 ( V_32 ) ;
V_46 = F_35 ( V_32 , V_42 ) ;
if ( ! V_46 )
return - V_66 ;
F_36 ( & V_49 . V_52 ) ;
F_37 ( V_46 , V_67 |
V_68 ,
F_27 , & V_49 ) ;
V_25 = F_29 ( F_38 ( V_46 ) , & V_49 ) ;
if ( V_25 )
goto V_69;
V_56 = F_39 ( F_40 ( V_11 ) ) ;
if ( V_56 == 0 )
goto V_70;
V_57 [ 0 ] = F_18 ( V_56 , & V_64 [ 0 ] , 1 ) ;
if ( ! V_57 [ 0 ] ) {
V_25 = - V_66 ;
goto V_69;
}
if ( V_56 > V_64 [ 0 ] ) {
V_57 [ 1 ] = F_18 ( V_56 - V_64 [ 0 ] ,
& V_64 [ 1 ] , 0 ) ;
}
if ( ! ( V_11 -> V_18 & V_19 ) ) {
V_11 -> V_18 |= V_19 ;
V_22 = 1 ;
}
for ( V_12 = 0 ; V_12 < V_56 ; V_12 += V_58 ) {
if ( ! V_57 [ 1 ] && V_12 ) {
V_25 = F_29 ( V_60 , & V_49 ) ;
if ( V_25 )
goto V_71;
}
V_58 = F_41 ( T_1 , V_56 - V_12 , V_64 [ V_59 ] ) ;
V_25 = F_4 ( V_11 , V_12 , V_57 [ V_59 ] , V_58 ) ;
if ( V_25 != V_58 )
goto V_71;
if ( V_57 [ 1 ] && V_12 ) {
V_25 = F_29 ( V_60 , & V_49 ) ;
if ( V_25 )
goto V_71;
}
F_42 ( & V_63 [ 0 ] , V_57 [ V_59 ] , V_58 ) ;
F_43 ( V_46 , V_63 , NULL , V_58 ) ;
V_60 = F_44 ( V_46 ) ;
if ( V_57 [ 1 ] )
V_59 = ! V_59 ;
}
V_25 = F_29 ( V_60 , & V_49 ) ;
V_71:
if ( V_22 )
V_11 -> V_18 &= ~ V_19 ;
F_21 ( V_57 [ 0 ] , V_64 [ 0 ] ) ;
F_21 ( V_57 [ 1 ] , V_64 [ 1 ] ) ;
V_70:
if ( ! V_25 ) {
F_43 ( V_46 , NULL , V_55 -> V_72 , 0 ) ;
V_25 = F_29 ( F_45 ( V_46 ) , & V_49 ) ;
}
V_69:
F_46 ( V_46 ) ;
return V_25 ;
}
static int F_47 ( struct V_11 * V_11 , struct V_54 * V_55 )
{
struct V_43 * V_32 ;
int V_25 ;
V_32 = F_23 ( V_55 -> V_31 ) ;
if ( F_12 ( V_32 ) )
return F_13 ( V_32 ) ;
V_25 = F_33 ( V_11 , V_55 , V_32 ) ;
F_25 ( V_32 ) ;
return V_25 ;
}
static int F_48 ( struct V_11 * V_11 ,
struct V_54 * V_55 ,
struct V_29 * V_32 )
{
T_1 V_56 , V_12 = 0 ;
char * V_57 ;
int V_25 , V_22 = 0 ;
F_49 ( V_73 , V_32 ) ;
V_73 -> V_32 = V_32 ;
V_73 -> V_74 = 0 ;
V_55 -> V_65 = F_50 ( V_32 ) ;
V_25 = F_51 ( V_73 ) ;
if ( V_25 != 0 )
return V_25 ;
V_56 = F_39 ( F_40 ( V_11 ) ) ;
if ( V_56 == 0 )
goto V_75;
V_57 = F_52 ( V_10 , V_42 ) ;
if ( ! V_57 )
return - V_66 ;
if ( ! ( V_11 -> V_18 & V_19 ) ) {
V_11 -> V_18 |= V_19 ;
V_22 = 1 ;
}
while ( V_12 < V_56 ) {
int V_58 ;
V_58 = F_4 ( V_11 , V_12 , V_57 , V_10 ) ;
if ( V_58 < 0 ) {
V_25 = V_58 ;
break;
}
if ( V_58 == 0 )
break;
V_12 += V_58 ;
V_25 = F_53 ( V_73 , V_57 , V_58 ) ;
if ( V_25 )
break;
}
if ( V_22 )
V_11 -> V_18 &= ~ V_19 ;
F_54 ( V_57 ) ;
V_75:
if ( ! V_25 )
V_25 = F_55 ( V_73 , V_55 -> V_72 ) ;
return V_25 ;
}
static int F_56 ( struct V_11 * V_11 , struct V_54 * V_55 )
{
struct V_29 * V_32 ;
int V_25 ;
V_32 = F_15 ( V_55 -> V_31 ) ;
if ( F_12 ( V_32 ) )
return F_13 ( V_32 ) ;
V_25 = F_48 ( V_11 , V_55 , V_32 ) ;
F_16 ( V_32 ) ;
return V_25 ;
}
int F_57 ( struct V_11 * V_11 , struct V_54 * V_55 )
{
T_1 V_56 ;
int V_25 ;
V_56 = F_39 ( F_40 ( V_11 ) ) ;
if ( V_76 && V_56 >= V_76 ) {
V_25 = F_47 ( V_11 , V_55 ) ;
if ( ! V_25 )
return 0 ;
}
return F_56 ( V_11 , V_55 ) ;
}
static int F_58 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
int V_81 ,
struct V_54 * V_55 ,
struct V_29 * V_32 )
{
F_49 ( V_73 , V_32 ) ;
int V_25 , V_82 ;
V_73 -> V_32 = V_32 ;
V_73 -> V_74 = 0 ;
V_55 -> V_65 = F_50 ( V_32 ) ;
V_25 = F_51 ( V_73 ) ;
if ( V_25 != 0 )
return V_25 ;
for ( V_82 = 0 ; V_82 < V_81 ; V_82 ++ ) {
T_8 V_83 [ V_84 + 1 ] = { 0 } ;
T_8 * V_85 = V_78 [ V_82 ] . V_50 ;
T_9 V_86 = V_78 [ V_82 ] . V_87 ;
if ( strcmp ( V_80 -> V_88 , V_89 ) != 0 ) {
V_25 = F_53 ( V_73 ,
( const T_8 * ) & V_78 [ V_82 ] . V_87 ,
sizeof( V_78 [ V_82 ] . V_87 ) ) ;
if ( V_25 )
break;
} else if ( strcmp ( V_80 -> V_90 [ V_82 ] -> V_91 , L_4 ) == 0 ) {
memcpy ( V_83 , V_85 , V_86 ) ;
V_85 = V_83 ;
V_86 = V_84 + 1 ;
}
V_25 = F_53 ( V_73 , V_85 , V_86 ) ;
if ( V_25 )
break;
}
if ( ! V_25 )
V_25 = F_55 ( V_73 , V_55 -> V_72 ) ;
return V_25 ;
}
int F_59 ( struct V_77 * V_78 ,
struct V_79 * V_92 , int V_81 ,
struct V_54 * V_55 )
{
struct V_29 * V_32 ;
int V_25 ;
V_32 = F_15 ( V_55 -> V_31 ) ;
if ( F_12 ( V_32 ) )
return F_13 ( V_32 ) ;
V_25 = F_58 ( V_78 , V_92 , V_81 ,
V_55 , V_32 ) ;
F_16 ( V_32 ) ;
return V_25 ;
}
static void T_5 F_60 ( int V_93 , T_8 * V_94 )
{
if ( ! V_95 )
return;
if ( F_61 ( V_96 , V_93 , V_94 ) != 0 )
F_14 ( L_5 ) ;
}
static int T_5 F_62 ( char * V_72 ,
struct V_29 * V_32 )
{
T_8 V_97 [ V_98 ] ;
int V_25 , V_82 ;
F_49 ( V_73 , V_32 ) ;
V_73 -> V_32 = V_32 ;
V_73 -> V_74 = 0 ;
V_25 = F_51 ( V_73 ) ;
if ( V_25 != 0 )
return V_25 ;
for ( V_82 = V_99 ; V_82 < V_100 ; V_82 ++ ) {
F_60 ( V_82 , V_97 ) ;
V_25 = F_53 ( V_73 , V_97 , V_98 ) ;
}
if ( ! V_25 )
F_55 ( V_73 , V_72 ) ;
return V_25 ;
}
int T_5 F_63 ( struct V_54 * V_55 )
{
struct V_29 * V_32 ;
int V_25 ;
V_32 = F_15 ( V_55 -> V_31 ) ;
if ( F_12 ( V_32 ) )
return F_13 ( V_32 ) ;
V_55 -> V_65 = F_50 ( V_32 ) ;
V_25 = F_62 ( V_55 -> V_72 , V_32 ) ;
F_16 ( V_32 ) ;
return V_25 ;
}
