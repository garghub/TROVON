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
int T_1 F_4 ( void )
{
long V_11 ;
V_12 = F_5 ( V_13 [ V_14 ] , 0 , 0 ) ;
if ( F_6 ( V_12 ) ) {
V_11 = F_7 ( V_12 ) ;
F_8 ( L_1 ,
V_13 [ V_14 ] , V_11 ) ;
return V_11 ;
}
return 0 ;
}
static struct V_15 * F_9 ( enum V_16 V_17 )
{
struct V_15 * V_18 = V_12 ;
int V_11 ;
if ( V_17 < 0 || V_17 >= V_19 )
V_17 = V_14 ;
if ( V_17 != V_14 ) {
V_18 = F_5 ( V_13 [ V_17 ] , 0 , 0 ) ;
if ( F_6 ( V_18 ) ) {
V_11 = F_7 ( V_18 ) ;
F_8 ( L_2 ,
V_13 [ V_17 ] , V_11 ) ;
}
}
return V_18 ;
}
static void F_10 ( struct V_15 * V_18 )
{
if ( V_18 != V_12 )
F_11 ( V_18 ) ;
}
static void * F_12 ( T_2 V_20 , T_3 * V_21 ,
int V_22 )
{
void * V_23 ;
int V_5 = V_8 ;
T_4 V_24 = V_25 | V_26 | V_27 ;
if ( V_5 )
V_5 = F_13 ( F_3 ( V_20 ) , V_5 ) ;
for (; V_5 ; V_5 -- ) {
V_23 = ( void * ) F_14 ( V_24 , V_5 ) ;
if ( V_23 ) {
* V_21 = V_10 << V_5 ;
return V_23 ;
}
}
V_24 = V_28 ;
if ( ! V_22 )
V_24 |= V_26 ;
V_23 = ( void * ) F_14 ( V_24 , 0 ) ;
if ( V_23 ) {
* V_21 = V_10 ;
return V_23 ;
}
* V_21 = 0 ;
return NULL ;
}
static void F_15 ( void * V_23 , T_3 V_4 )
{
if ( ! V_23 )
return;
F_16 ( ( unsigned long ) V_23 , F_3 ( V_4 ) ) ;
}
static struct V_29 * F_17 ( enum V_16 V_17 )
{
struct V_29 * V_18 = V_30 ;
int V_11 ;
if ( V_17 < 0 || V_17 >= V_19 )
V_17 = V_14 ;
if ( V_17 != V_14 || ! V_18 ) {
V_18 = F_18 ( V_13 [ V_17 ] , 0 , 0 ) ;
if ( ! F_6 ( V_18 ) ) {
if ( V_17 == V_14 )
V_30 = V_18 ;
} else {
V_11 = F_7 ( V_18 ) ;
F_8 ( L_2 ,
V_13 [ V_17 ] , V_11 ) ;
}
}
return V_18 ;
}
static void F_19 ( struct V_29 * V_18 )
{
if ( V_18 != V_30 )
F_20 ( V_18 ) ;
}
static void F_21 ( struct V_31 * V_32 , int V_33 )
{
struct V_34 * V_35 = V_32 -> V_36 ;
if ( V_33 == - V_37 )
return;
V_35 -> V_33 = V_33 ;
F_22 ( & V_35 -> V_38 ) ;
}
static int F_23 ( int V_33 , struct V_34 * V_35 )
{
switch ( V_33 ) {
case 0 :
break;
case - V_37 :
case - V_39 :
F_24 ( & V_35 -> V_38 ) ;
F_25 ( & V_35 -> V_38 ) ;
V_33 = V_35 -> V_33 ;
default:
F_26 ( L_3 , V_33 ) ;
}
return V_33 ;
}
static int F_27 ( struct V_40 * V_40 ,
struct V_41 * V_42 ,
struct V_29 * V_18 )
{
T_2 V_43 , V_44 ;
char * V_45 [ 2 ] = { NULL , } ;
int V_11 , V_46 = 0 , V_47 , V_48 = 0 , V_49 = 0 ;
struct V_50 * V_32 ;
struct V_51 V_52 [ 1 ] ;
struct V_34 V_35 ;
T_3 V_53 [ 2 ] ;
V_42 -> V_54 = F_28 ( V_18 ) ;
V_32 = F_29 ( V_18 , V_28 ) ;
if ( ! V_32 )
return - V_55 ;
F_30 ( & V_35 . V_38 ) ;
F_31 ( V_32 , V_56 |
V_57 ,
F_21 , & V_35 ) ;
V_11 = F_23 ( F_32 ( V_32 ) , & V_35 ) ;
if ( V_11 )
goto V_58;
V_43 = F_33 ( F_34 ( V_40 ) ) ;
if ( V_43 == 0 )
goto V_59;
V_45 [ 0 ] = F_12 ( V_43 , & V_53 [ 0 ] , 1 ) ;
if ( ! V_45 [ 0 ] ) {
V_11 = - V_55 ;
goto V_58;
}
if ( V_43 > V_53 [ 0 ] ) {
V_45 [ 1 ] = F_12 ( V_43 - V_53 [ 0 ] ,
& V_53 [ 1 ] , 0 ) ;
}
if ( ! ( V_40 -> V_60 & V_61 ) ) {
V_40 -> V_60 |= V_61 ;
V_46 = 1 ;
}
for ( V_44 = 0 ; V_44 < V_43 ; V_44 += V_47 ) {
if ( ! V_45 [ 1 ] && V_44 ) {
V_11 = F_23 ( V_49 , & V_35 ) ;
if ( V_11 )
goto V_62;
}
V_47 = F_35 ( T_2 , V_43 - V_44 , V_53 [ V_48 ] ) ;
V_11 = F_36 ( V_40 , V_44 , V_45 [ V_48 ] ,
V_47 ) ;
if ( V_11 != V_47 )
goto V_62;
if ( V_45 [ 1 ] && V_44 ) {
V_11 = F_23 ( V_49 , & V_35 ) ;
if ( V_11 )
goto V_62;
}
F_37 ( & V_52 [ 0 ] , V_45 [ V_48 ] , V_47 ) ;
F_38 ( V_32 , V_52 , NULL , V_47 ) ;
V_49 = F_39 ( V_32 ) ;
if ( V_45 [ 1 ] )
V_48 = ! V_48 ;
}
V_11 = F_23 ( V_49 , & V_35 ) ;
V_62:
if ( V_46 )
V_40 -> V_60 &= ~ V_61 ;
F_15 ( V_45 [ 0 ] , V_53 [ 0 ] ) ;
F_15 ( V_45 [ 1 ] , V_53 [ 1 ] ) ;
V_59:
if ( ! V_11 ) {
F_38 ( V_32 , NULL , V_42 -> V_63 , 0 ) ;
V_11 = F_23 ( F_40 ( V_32 ) , & V_35 ) ;
}
V_58:
F_41 ( V_32 ) ;
return V_11 ;
}
static int F_42 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_29 * V_18 ;
int V_11 ;
V_18 = F_17 ( V_42 -> V_17 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_11 = F_27 ( V_40 , V_42 , V_18 ) ;
F_19 ( V_18 ) ;
return V_11 ;
}
static int F_43 ( struct V_40 * V_40 ,
struct V_41 * V_42 ,
struct V_15 * V_18 )
{
T_2 V_43 , V_44 = 0 ;
char * V_45 ;
int V_11 , V_46 = 0 ;
F_44 ( V_64 , V_18 ) ;
V_64 -> V_18 = V_18 ;
V_64 -> V_65 = 0 ;
V_42 -> V_54 = F_45 ( V_18 ) ;
V_11 = F_46 ( V_64 ) ;
if ( V_11 != 0 )
return V_11 ;
V_43 = F_33 ( F_34 ( V_40 ) ) ;
if ( V_43 == 0 )
goto V_66;
V_45 = F_47 ( V_10 , V_28 ) ;
if ( ! V_45 )
return - V_55 ;
if ( ! ( V_40 -> V_60 & V_61 ) ) {
V_40 -> V_60 |= V_61 ;
V_46 = 1 ;
}
while ( V_44 < V_43 ) {
int V_47 ;
V_47 = F_36 ( V_40 , V_44 , V_45 , V_10 ) ;
if ( V_47 < 0 ) {
V_11 = V_47 ;
break;
}
if ( V_47 == 0 )
break;
V_44 += V_47 ;
V_11 = F_48 ( V_64 , V_45 , V_47 ) ;
if ( V_11 )
break;
}
if ( V_46 )
V_40 -> V_60 &= ~ V_61 ;
F_49 ( V_45 ) ;
V_66:
if ( ! V_11 )
V_11 = F_50 ( V_64 , V_42 -> V_63 ) ;
return V_11 ;
}
static int F_51 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
struct V_15 * V_18 ;
int V_11 ;
V_18 = F_9 ( V_42 -> V_17 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_11 = F_43 ( V_40 , V_42 , V_18 ) ;
F_10 ( V_18 ) ;
return V_11 ;
}
int F_52 ( struct V_40 * V_40 , struct V_41 * V_42 )
{
T_2 V_43 ;
int V_11 ;
V_43 = F_33 ( F_34 ( V_40 ) ) ;
if ( V_67 && V_43 >= V_67 ) {
V_11 = F_42 ( V_40 , V_42 ) ;
if ( ! V_11 )
return 0 ;
}
return F_51 ( V_40 , V_42 ) ;
}
static int F_53 ( struct V_68 * V_69 ,
struct V_70 * V_71 ,
int V_72 ,
struct V_41 * V_42 ,
struct V_15 * V_18 )
{
F_44 ( V_64 , V_18 ) ;
int V_11 , V_73 ;
V_64 -> V_18 = V_18 ;
V_64 -> V_65 = 0 ;
V_42 -> V_54 = F_45 ( V_18 ) ;
V_11 = F_46 ( V_64 ) ;
if ( V_11 != 0 )
return V_11 ;
for ( V_73 = 0 ; V_73 < V_72 ; V_73 ++ ) {
T_5 V_74 [ V_75 + 1 ] = { 0 } ;
T_5 * V_76 = V_69 [ V_73 ] . V_36 ;
T_6 V_77 = V_69 [ V_73 ] . V_78 ;
T_6 V_79 =
! V_80 ? V_77 : F_54 ( V_77 ) ;
if ( strcmp ( V_71 -> V_81 , V_82 ) != 0 ) {
V_11 = F_48 ( V_64 ,
( const T_5 * ) & V_79 ,
sizeof( V_79 ) ) ;
if ( V_11 )
break;
} else if ( strcmp ( V_71 -> V_83 [ V_73 ] -> V_84 , L_4 ) == 0 ) {
memcpy ( V_74 , V_76 , V_77 ) ;
V_76 = V_74 ;
V_77 = V_75 + 1 ;
}
V_11 = F_48 ( V_64 , V_76 , V_77 ) ;
if ( V_11 )
break;
}
if ( ! V_11 )
V_11 = F_50 ( V_64 , V_42 -> V_63 ) ;
return V_11 ;
}
int F_55 ( struct V_68 * V_69 ,
struct V_70 * V_85 , int V_72 ,
struct V_41 * V_42 )
{
struct V_15 * V_18 ;
int V_11 ;
V_18 = F_9 ( V_42 -> V_17 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_11 = F_53 ( V_69 , V_85 , V_72 ,
V_42 , V_18 ) ;
F_10 ( V_18 ) ;
return V_11 ;
}
static int F_56 ( const void * V_86 , T_2 V_78 ,
struct V_41 * V_42 ,
struct V_29 * V_18 )
{
struct V_50 * V_32 ;
struct V_51 V_52 ;
struct V_34 V_35 ;
int V_11 , V_49 = 0 ;
V_42 -> V_54 = F_28 ( V_18 ) ;
V_32 = F_29 ( V_18 , V_28 ) ;
if ( ! V_32 )
return - V_55 ;
F_30 ( & V_35 . V_38 ) ;
F_31 ( V_32 , V_56 |
V_57 ,
F_21 , & V_35 ) ;
V_11 = F_23 ( F_32 ( V_32 ) , & V_35 ) ;
if ( V_11 )
goto V_66;
F_37 ( & V_52 , V_86 , V_78 ) ;
F_38 ( V_32 , & V_52 , NULL , V_78 ) ;
V_49 = F_39 ( V_32 ) ;
V_11 = F_23 ( V_49 , & V_35 ) ;
if ( ! V_11 ) {
F_38 ( V_32 , NULL , V_42 -> V_63 , 0 ) ;
V_11 = F_23 ( F_40 ( V_32 ) , & V_35 ) ;
}
V_66:
F_41 ( V_32 ) ;
return V_11 ;
}
static int F_57 ( const void * V_86 , T_2 V_78 ,
struct V_41 * V_42 )
{
struct V_29 * V_18 ;
int V_11 ;
V_18 = F_17 ( V_42 -> V_17 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_11 = F_56 ( V_86 , V_78 , V_42 , V_18 ) ;
F_19 ( V_18 ) ;
return V_11 ;
}
static int F_58 ( const void * V_86 , T_2 V_4 ,
struct V_41 * V_42 ,
struct V_15 * V_18 )
{
F_44 ( V_64 , V_18 ) ;
unsigned int V_78 ;
int V_11 ;
V_64 -> V_18 = V_18 ;
V_64 -> V_65 = 0 ;
V_42 -> V_54 = F_45 ( V_18 ) ;
V_11 = F_46 ( V_64 ) ;
if ( V_11 != 0 )
return V_11 ;
while ( V_4 ) {
V_78 = V_4 < V_10 ? V_4 : V_10 ;
V_11 = F_48 ( V_64 , V_86 , V_78 ) ;
if ( V_11 )
break;
V_86 += V_78 ;
V_4 -= V_78 ;
}
if ( ! V_11 )
V_11 = F_50 ( V_64 , V_42 -> V_63 ) ;
return V_11 ;
}
static int F_59 ( const void * V_86 , T_2 V_78 ,
struct V_41 * V_42 )
{
struct V_15 * V_18 ;
int V_11 ;
V_18 = F_9 ( V_42 -> V_17 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_11 = F_58 ( V_86 , V_78 , V_42 , V_18 ) ;
F_10 ( V_18 ) ;
return V_11 ;
}
int F_60 ( const void * V_86 , T_2 V_78 ,
struct V_41 * V_42 )
{
int V_11 ;
if ( V_67 && V_78 >= V_67 ) {
V_11 = F_57 ( V_86 , V_78 , V_42 ) ;
if ( ! V_11 )
return 0 ;
}
return F_59 ( V_86 , V_78 , V_42 ) ;
}
static void T_1 F_61 ( int V_87 , T_5 * V_88 )
{
if ( ! V_89 )
return;
if ( F_62 ( V_90 , V_87 , V_88 ) != 0 )
F_8 ( L_5 ) ;
}
static int T_1 F_63 ( char * V_63 ,
struct V_15 * V_18 )
{
T_5 V_91 [ V_92 ] ;
int V_11 , V_73 ;
F_44 ( V_64 , V_18 ) ;
V_64 -> V_18 = V_18 ;
V_64 -> V_65 = 0 ;
V_11 = F_46 ( V_64 ) ;
if ( V_11 != 0 )
return V_11 ;
for ( V_73 = V_93 ; V_73 < V_94 ; V_73 ++ ) {
F_61 ( V_73 , V_91 ) ;
V_11 = F_48 ( V_64 , V_91 , V_92 ) ;
}
if ( ! V_11 )
F_50 ( V_64 , V_63 ) ;
return V_11 ;
}
int T_1 F_64 ( struct V_41 * V_42 )
{
struct V_15 * V_18 ;
int V_11 ;
V_18 = F_9 ( V_42 -> V_17 ) ;
if ( F_6 ( V_18 ) )
return F_7 ( V_18 ) ;
V_42 -> V_54 = F_45 ( V_18 ) ;
V_11 = F_63 ( V_42 -> V_63 , V_18 ) ;
F_10 ( V_18 ) ;
return V_11 ;
}
