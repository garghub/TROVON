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
T_4 V_17 ;
if ( ! ( V_11 -> V_18 & V_19 ) )
return - V_20 ;
if ( ! V_11 -> V_21 -> V_22 && ! V_11 -> V_21 -> V_23 )
return - V_7 ;
V_15 = F_5 () ;
F_6 ( F_7 () ) ;
if ( V_11 -> V_21 -> V_22 )
V_17 = V_11 -> V_21 -> V_22 ( V_11 , V_16 , V_14 , & V_12 ) ;
else
V_17 = F_8 ( V_11 , V_16 , V_14 , & V_12 ) ;
F_6 ( V_15 ) ;
return V_17 ;
}
int F_9 ( void )
{
long V_24 ;
V_25 = F_10 ( V_26 [ V_27 ] , 0 , 0 ) ;
if ( F_11 ( V_25 ) ) {
V_24 = F_12 ( V_25 ) ;
F_13 ( L_1 ,
V_26 [ V_27 ] , V_24 ) ;
return V_24 ;
}
return 0 ;
}
static struct V_28 * F_14 ( enum V_29 V_30 )
{
struct V_28 * V_31 = V_25 ;
int V_24 ;
if ( V_30 != V_27 && V_30 < V_32 ) {
V_31 = F_10 ( V_26 [ V_30 ] , 0 , 0 ) ;
if ( F_11 ( V_31 ) ) {
V_24 = F_12 ( V_31 ) ;
F_13 ( L_2 ,
V_26 [ V_30 ] , V_24 ) ;
}
}
return V_31 ;
}
static void F_15 ( struct V_28 * V_31 )
{
if ( V_31 != V_25 )
F_16 ( V_31 ) ;
}
static void * F_17 ( T_1 V_33 , T_5 * V_34 ,
int V_35 )
{
void * V_36 ;
int V_5 = V_8 ;
T_6 V_37 = V_38 | V_39 | V_40 ;
if ( V_5 )
V_5 = F_18 ( F_3 ( V_33 ) , V_5 ) ;
for (; V_5 ; V_5 -- ) {
V_36 = ( void * ) F_19 ( V_37 , V_5 ) ;
if ( V_36 ) {
* V_34 = V_10 << V_5 ;
return V_36 ;
}
}
V_37 = V_41 ;
if ( ! V_35 )
V_37 |= V_39 ;
V_36 = ( void * ) F_19 ( V_37 , 0 ) ;
if ( V_36 ) {
* V_34 = V_10 ;
return V_36 ;
}
* V_34 = 0 ;
return NULL ;
}
static void F_20 ( void * V_36 , T_5 V_4 )
{
if ( ! V_36 )
return;
F_21 ( ( unsigned long ) V_36 , F_3 ( V_4 ) ) ;
}
static struct V_42 * F_22 ( enum V_29 V_30 )
{
struct V_42 * V_31 = V_43 ;
int V_24 ;
if ( ( V_30 != V_27 && V_30 < V_32 ) || ! V_31 ) {
V_31 = F_23 ( V_26 [ V_30 ] , 0 , 0 ) ;
if ( ! F_11 ( V_31 ) ) {
if ( V_30 == V_27 )
V_43 = V_31 ;
} else {
V_24 = F_12 ( V_31 ) ;
F_13 ( L_2 ,
V_26 [ V_30 ] , V_24 ) ;
}
}
return V_31 ;
}
static void F_24 ( struct V_42 * V_31 )
{
if ( V_31 != V_43 )
F_25 ( V_31 ) ;
}
static void F_26 ( struct V_44 * V_45 , int V_46 )
{
struct V_47 * V_48 = V_45 -> V_49 ;
if ( V_46 == - V_50 )
return;
V_48 -> V_46 = V_46 ;
F_27 ( & V_48 -> V_51 ) ;
}
static int F_28 ( int V_46 , struct V_47 * V_48 )
{
switch ( V_46 ) {
case 0 :
break;
case - V_50 :
case - V_52 :
F_29 ( & V_48 -> V_51 ) ;
F_30 ( & V_48 -> V_51 ) ;
V_46 = V_48 -> V_46 ;
default:
F_31 ( L_3 , V_46 ) ;
}
return V_46 ;
}
static int F_32 ( struct V_11 * V_11 ,
struct V_53 * V_54 ,
struct V_42 * V_31 )
{
T_1 V_55 , V_12 ;
char * V_56 [ 2 ] = { NULL , } ;
int V_24 , V_22 = 0 , V_57 , V_58 = 0 , V_59 = 0 ;
struct V_60 * V_45 ;
struct V_61 V_62 [ 1 ] ;
struct V_47 V_48 ;
T_5 V_63 [ 2 ] ;
V_54 -> V_64 = F_33 ( V_31 ) ;
V_45 = F_34 ( V_31 , V_41 ) ;
if ( ! V_45 )
return - V_65 ;
F_35 ( & V_48 . V_51 ) ;
F_36 ( V_45 , V_66 |
V_67 ,
F_26 , & V_48 ) ;
V_24 = F_28 ( F_37 ( V_45 ) , & V_48 ) ;
if ( V_24 )
goto V_68;
V_55 = F_38 ( F_39 ( V_11 ) ) ;
if ( V_55 == 0 )
goto V_69;
V_56 [ 0 ] = F_17 ( V_55 , & V_63 [ 0 ] , 1 ) ;
if ( ! V_56 [ 0 ] ) {
V_24 = - V_65 ;
goto V_68;
}
if ( V_55 > V_63 [ 0 ] ) {
V_56 [ 1 ] = F_17 ( V_55 - V_63 [ 0 ] ,
& V_63 [ 1 ] , 0 ) ;
}
if ( ! ( V_11 -> V_18 & V_19 ) ) {
V_11 -> V_18 |= V_19 ;
V_22 = 1 ;
}
for ( V_12 = 0 ; V_12 < V_55 ; V_12 += V_57 ) {
if ( ! V_56 [ 1 ] && V_12 ) {
V_24 = F_28 ( V_59 , & V_48 ) ;
if ( V_24 )
goto V_70;
}
V_57 = F_40 ( T_1 , V_55 - V_12 , V_63 [ V_58 ] ) ;
V_24 = F_4 ( V_11 , V_12 , V_56 [ V_58 ] , V_57 ) ;
if ( V_24 != V_57 )
goto V_70;
if ( V_56 [ 1 ] && V_12 ) {
V_24 = F_28 ( V_59 , & V_48 ) ;
if ( V_24 )
goto V_70;
}
F_41 ( & V_62 [ 0 ] , V_56 [ V_58 ] , V_57 ) ;
F_42 ( V_45 , V_62 , NULL , V_57 ) ;
V_59 = F_43 ( V_45 ) ;
if ( V_56 [ 1 ] )
V_58 = ! V_58 ;
}
V_24 = F_28 ( V_59 , & V_48 ) ;
V_70:
if ( V_22 )
V_11 -> V_18 &= ~ V_19 ;
F_20 ( V_56 [ 0 ] , V_63 [ 0 ] ) ;
F_20 ( V_56 [ 1 ] , V_63 [ 1 ] ) ;
V_69:
if ( ! V_24 ) {
F_42 ( V_45 , NULL , V_54 -> V_71 , 0 ) ;
V_24 = F_28 ( F_44 ( V_45 ) , & V_48 ) ;
}
V_68:
F_45 ( V_45 ) ;
return V_24 ;
}
static int F_46 ( struct V_11 * V_11 , struct V_53 * V_54 )
{
struct V_42 * V_31 ;
int V_24 ;
V_31 = F_22 ( V_54 -> V_30 ) ;
if ( F_11 ( V_31 ) )
return F_12 ( V_31 ) ;
V_24 = F_32 ( V_11 , V_54 , V_31 ) ;
F_24 ( V_31 ) ;
return V_24 ;
}
static int F_47 ( struct V_11 * V_11 ,
struct V_53 * V_54 ,
struct V_28 * V_31 )
{
T_1 V_55 , V_12 = 0 ;
char * V_56 ;
int V_24 , V_22 = 0 ;
struct {
struct V_72 V_73 ;
char V_74 [ F_48 ( V_31 ) ] ;
} V_75 ;
V_75 . V_73 . V_31 = V_31 ;
V_75 . V_73 . V_76 = 0 ;
V_54 -> V_64 = F_49 ( V_31 ) ;
V_24 = F_50 ( & V_75 . V_73 ) ;
if ( V_24 != 0 )
return V_24 ;
V_55 = F_38 ( F_39 ( V_11 ) ) ;
if ( V_55 == 0 )
goto V_77;
V_56 = F_51 ( V_10 , V_41 ) ;
if ( ! V_56 )
return - V_65 ;
if ( ! ( V_11 -> V_18 & V_19 ) ) {
V_11 -> V_18 |= V_19 ;
V_22 = 1 ;
}
while ( V_12 < V_55 ) {
int V_57 ;
V_57 = F_4 ( V_11 , V_12 , V_56 , V_10 ) ;
if ( V_57 < 0 ) {
V_24 = V_57 ;
break;
}
if ( V_57 == 0 )
break;
V_12 += V_57 ;
V_24 = F_52 ( & V_75 . V_73 , V_56 , V_57 ) ;
if ( V_24 )
break;
}
if ( V_22 )
V_11 -> V_18 &= ~ V_19 ;
F_53 ( V_56 ) ;
V_77:
if ( ! V_24 )
V_24 = F_54 ( & V_75 . V_73 , V_54 -> V_71 ) ;
return V_24 ;
}
static int F_55 ( struct V_11 * V_11 , struct V_53 * V_54 )
{
struct V_28 * V_31 ;
int V_24 ;
V_31 = F_14 ( V_54 -> V_30 ) ;
if ( F_11 ( V_31 ) )
return F_12 ( V_31 ) ;
V_24 = F_47 ( V_11 , V_54 , V_31 ) ;
F_15 ( V_31 ) ;
return V_24 ;
}
int F_56 ( struct V_11 * V_11 , struct V_53 * V_54 )
{
T_1 V_55 ;
int V_24 ;
V_55 = F_38 ( F_39 ( V_11 ) ) ;
if ( V_78 && V_55 >= V_78 ) {
V_24 = F_46 ( V_11 , V_54 ) ;
if ( ! V_24 )
return 0 ;
}
return F_55 ( V_11 , V_54 ) ;
}
static int F_57 ( struct V_79 * V_80 ,
struct V_81 * V_82 ,
int V_83 ,
struct V_53 * V_54 ,
struct V_28 * V_31 )
{
struct {
struct V_72 V_73 ;
char V_74 [ F_48 ( V_31 ) ] ;
} V_75 ;
int V_24 , V_84 ;
V_75 . V_73 . V_31 = V_31 ;
V_75 . V_73 . V_76 = 0 ;
V_54 -> V_64 = F_49 ( V_31 ) ;
V_24 = F_50 ( & V_75 . V_73 ) ;
if ( V_24 != 0 )
return V_24 ;
for ( V_84 = 0 ; V_84 < V_83 ; V_84 ++ ) {
T_7 V_85 [ V_86 + 1 ] = { 0 } ;
T_7 * V_87 = V_80 [ V_84 ] . V_49 ;
T_8 V_88 = V_80 [ V_84 ] . V_89 ;
if ( strcmp ( V_82 -> V_90 , V_91 ) != 0 ) {
V_24 = F_52 ( & V_75 . V_73 ,
( const T_7 * ) & V_80 [ V_84 ] . V_89 ,
sizeof( V_80 [ V_84 ] . V_89 ) ) ;
if ( V_24 )
break;
} else if ( strcmp ( V_82 -> V_92 [ V_84 ] -> V_93 , L_4 ) == 0 ) {
memcpy ( V_85 , V_87 , V_88 ) ;
V_87 = V_85 ;
V_88 = V_86 + 1 ;
}
V_24 = F_52 ( & V_75 . V_73 , V_87 , V_88 ) ;
if ( V_24 )
break;
}
if ( ! V_24 )
V_24 = F_54 ( & V_75 . V_73 , V_54 -> V_71 ) ;
return V_24 ;
}
int F_58 ( struct V_79 * V_80 ,
struct V_81 * V_75 , int V_83 ,
struct V_53 * V_54 )
{
struct V_28 * V_31 ;
int V_24 ;
V_31 = F_14 ( V_54 -> V_30 ) ;
if ( F_11 ( V_31 ) )
return F_12 ( V_31 ) ;
V_24 = F_57 ( V_80 , V_75 , V_83 ,
V_54 , V_31 ) ;
F_15 ( V_31 ) ;
return V_24 ;
}
static void T_9 F_59 ( int V_94 , T_7 * V_95 )
{
if ( ! V_96 )
return;
if ( F_60 ( V_97 , V_94 , V_95 ) != 0 )
F_13 ( L_5 ) ;
}
static int T_9 F_61 ( char * V_71 ,
struct V_28 * V_31 )
{
T_7 V_98 [ V_99 ] ;
int V_24 , V_84 ;
struct {
struct V_72 V_73 ;
char V_74 [ F_48 ( V_31 ) ] ;
} V_75 ;
V_75 . V_73 . V_31 = V_31 ;
V_75 . V_73 . V_76 = 0 ;
V_24 = F_50 ( & V_75 . V_73 ) ;
if ( V_24 != 0 )
return V_24 ;
for ( V_84 = V_100 ; V_84 < V_101 ; V_84 ++ ) {
F_59 ( V_84 , V_98 ) ;
V_24 = F_52 ( & V_75 . V_73 , V_98 , V_99 ) ;
}
if ( ! V_24 )
F_54 ( & V_75 . V_73 , V_71 ) ;
return V_24 ;
}
int T_9 F_62 ( struct V_53 * V_54 )
{
struct V_28 * V_31 ;
int V_24 ;
V_31 = F_14 ( V_54 -> V_30 ) ;
if ( F_11 ( V_31 ) )
return F_12 ( V_31 ) ;
V_54 -> V_64 = F_49 ( V_31 ) ;
V_24 = F_61 ( V_54 -> V_71 , V_31 ) ;
F_15 ( V_31 ) ;
return V_24 ;
}
