static struct V_1 *
F_1 ( struct V_2 * V_3 , const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_6 ; V_5 ++ ) {
struct V_1 * V_7 = V_3 -> V_8 + V_5 ;
if ( ! strcmp ( V_7 -> V_9 , V_4 ) )
return V_7 ;
}
return NULL ;
}
static struct V_10 *
F_2 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_13 ; V_5 ++ ) {
if ( ! V_11 [ V_5 ] . V_9 )
break;
if ( ! strcmp ( V_11 [ V_5 ] . V_9 , V_9 ) )
return V_11 + V_5 ;
}
return NULL ;
}
static struct V_14 *
F_3 ( struct V_2 * V_3 ,
const char * V_15 ,
const char * V_16 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
if ( ! strcmp ( V_20 -> V_20 . V_9 , V_15 ) ) {
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( ! strcmp ( V_11 -> V_9 , V_16 ) )
return V_11 ;
V_11 ++ ;
}
}
}
return NULL ;
}
static int F_4 ( struct V_22 * V_23 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
return V_3 -> V_6 ;
}
static const char * F_6 ( struct V_22 * V_23 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
return V_3 -> V_8 [ V_4 ] . V_9 ;
}
static int F_7 ( struct V_22 * V_23 ,
unsigned V_4 ,
const unsigned * * V_21 ,
unsigned * V_24 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
* V_21 = ( unsigned * ) & V_3 -> V_8 [ V_4 ] . V_20 ;
* V_24 = 1 ;
return 0 ;
}
static int F_8 ( struct V_22 * V_23 ,
struct V_25 * V_26 ,
struct V_27 * * V_28 ,
unsigned * V_29 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
unsigned long * V_30 ;
struct V_31 * V_32 ;
const char * V_33 ;
const char * V_4 ;
int V_34 , V_35 , V_5 = 0 ;
T_1 V_36 ;
* V_28 = NULL ;
* V_29 = 0 ;
V_34 = F_9 ( V_26 , L_1 , & V_33 ) ;
if ( V_34 ) {
F_10 ( V_3 -> V_37 ,
L_2 ,
V_26 -> V_9 ) ;
return - V_38 ;
}
V_35 = F_11 ( V_26 , L_3 ) * 2 ;
if ( V_35 < 0 ) {
F_10 ( V_3 -> V_37 ,
L_4 ,
V_26 -> V_9 ) ;
return - V_38 ;
}
* V_28 = F_12 ( V_35 * sizeof( struct V_27 ) , V_39 ) ;
if ( ! V_28 )
return - V_40 ;
F_13 (node, L_3 , prop, group) {
struct V_1 * V_7 =
F_1 ( V_3 , V_4 ) ;
int V_41 = 0 , V_42 = 0 ;
if ( ! V_7 ) {
F_10 ( V_3 -> V_37 , L_5 , V_4 ) ;
continue;
}
if ( ! F_3 ( V_3 ,
V_7 -> V_9 ,
V_33 ) ) {
F_10 ( V_3 -> V_37 , L_6 ,
V_33 , V_4 ) ;
continue;
}
( * V_28 ) [ V_5 ] . type = V_43 ;
( * V_28 ) [ V_5 ] . V_44 . V_45 . V_4 = V_4 ;
( * V_28 ) [ V_5 ] . V_44 . V_45 . V_33 = V_33 ;
V_5 ++ ;
( * V_28 ) [ V_5 ] . type = V_46 ;
( * V_28 ) [ V_5 ] . V_44 . V_47 . V_48 = V_4 ;
if ( F_14 ( V_26 , L_7 , NULL ) )
V_42 ++ ;
if ( F_14 ( V_26 , L_8 , NULL ) )
V_42 ++ ;
V_30 = F_15 ( V_42 * sizeof( * V_30 ) , V_39 ) ;
if ( ! F_16 ( V_26 , L_7 , & V_36 ) ) {
T_2 V_49 = ( V_36 + 1 ) * 10 ;
V_30 [ V_41 ++ ] =
F_17 ( V_50 ,
V_49 ) ;
}
if ( ! F_16 ( V_26 , L_8 , & V_36 ) ) {
enum V_51 V_52 = V_53 ;
if ( V_36 == 1 )
V_52 = V_54 ;
else if ( V_36 == 2 )
V_52 = V_55 ;
V_30 [ V_41 ++ ] = F_17 ( V_52 , 0 ) ;
}
( * V_28 ) [ V_5 ] . V_44 . V_47 . V_47 = V_30 ;
( * V_28 ) [ V_5 ] . V_44 . V_47 . V_56 = V_42 ;
V_5 ++ ;
}
* V_29 = V_35 ;
return 0 ;
}
static void F_18 ( struct V_22 * V_23 ,
struct V_27 * V_28 ,
unsigned V_29 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < V_29 ; V_5 ++ ) {
if ( V_28 [ V_5 ] . type == V_46 )
F_19 ( V_28 [ V_5 ] . V_44 . V_47 . V_47 ) ;
}
F_19 ( V_28 ) ;
}
static int F_20 ( struct V_22 * V_23 ,
unsigned V_4 ,
unsigned long * V_57 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
* V_57 = V_3 -> V_8 [ V_4 ] . V_57 ;
return 0 ;
}
static int F_21 ( struct V_22 * V_23 ,
unsigned V_4 ,
unsigned long V_57 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
struct V_1 * V_58 = & V_3 -> V_8 [ V_4 ] ;
T_1 V_36 , V_59 ;
T_2 V_49 ;
T_3 V_60 ;
switch ( F_22 ( V_57 ) ) {
case V_50 :
V_49 = F_23 ( V_57 ) ;
if ( V_49 > 40 )
return - V_38 ;
V_60 = V_49 / 10 - 1 ;
V_36 = F_24 ( V_3 -> V_61 + F_25 ( V_58 -> V_20 ) ) ;
V_59 = V_62 << F_26 ( V_58 -> V_20 ) ;
F_27 ( ( V_36 & ~ V_59 ) | V_60 << F_26 ( V_58 -> V_20 ) ,
V_3 -> V_61 + F_25 ( V_58 -> V_20 ) ) ;
break;
case V_54 :
V_36 = F_24 ( V_3 -> V_61 + F_28 ( V_58 -> V_20 ) ) ;
V_59 = V_63 << F_29 ( V_58 -> V_20 ) ;
F_27 ( ( V_36 & ~ V_59 ) | 1 << F_29 ( V_58 -> V_20 ) ,
V_3 -> V_61 + F_28 ( V_58 -> V_20 ) ) ;
break;
case V_55 :
V_36 = F_24 ( V_3 -> V_61 + F_28 ( V_58 -> V_20 ) ) ;
V_59 = V_63 << F_29 ( V_58 -> V_20 ) ;
F_27 ( ( V_36 & ~ V_59 ) | 2 << F_29 ( V_58 -> V_20 ) ,
V_3 -> V_61 + F_28 ( V_58 -> V_20 ) ) ;
break;
default:
break;
}
V_58 -> V_57 = V_57 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
return V_3 -> V_13 ;
}
static const char * F_31 ( struct V_22 * V_23 ,
unsigned V_33 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
return V_3 -> V_12 [ V_33 ] . V_9 ;
}
static int F_32 ( struct V_22 * V_23 ,
unsigned V_33 ,
const char * const * * V_8 ,
unsigned * const V_64 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
* V_8 = V_3 -> V_12 [ V_33 ] . V_8 ;
* V_64 = V_3 -> V_12 [ V_33 ] . V_6 ;
return 0 ;
}
static void F_33 ( struct V_22 * V_23 ,
unsigned V_20 ,
T_3 V_57 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
T_1 V_36 = F_24 ( V_3 -> V_61 + F_34 ( V_20 ) ) ;
T_1 V_59 = V_65 << F_35 ( V_20 ) ;
F_27 ( ( V_36 & ~ V_59 ) | V_57 << F_35 ( V_20 ) ,
V_3 -> V_61 + F_34 ( V_20 ) ) ;
}
static int F_36 ( struct V_22 * V_23 ,
unsigned V_33 ,
unsigned V_4 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
struct V_1 * V_58 = V_3 -> V_8 + V_4 ;
struct V_10 * V_11 = V_3 -> V_12 + V_33 ;
struct V_14 * V_17 =
F_3 ( V_3 ,
V_58 -> V_9 ,
V_11 -> V_9 ) ;
if ( ! V_17 )
return - V_38 ;
F_33 ( V_23 , V_58 -> V_20 , V_17 -> V_66 ) ;
return 0 ;
}
static int
F_37 ( struct V_22 * V_23 ,
struct V_67 * V_68 ,
unsigned V_69 ,
bool V_70 )
{
struct V_2 * V_3 = F_5 ( V_23 ) ;
struct V_14 * V_17 ;
char V_15 [ V_71 ] ;
const char * V_11 ;
T_3 V_72 , V_20 ;
int V_34 ;
V_72 = ( V_69 ) / V_73 ;
V_20 = ( V_69 ) % V_73 ;
V_34 = sprintf ( V_15 , L_9 , 'A' + V_72 , V_20 ) ;
if ( ! V_34 )
goto error;
if ( V_70 )
V_11 = L_10 ;
else
V_11 = L_11 ;
V_17 = F_3 ( V_3 ,
V_15 ,
V_11 ) ;
if ( ! V_17 ) {
V_34 = - V_38 ;
goto error;
}
F_33 ( V_23 , V_69 , V_17 -> V_66 ) ;
V_34 = 0 ;
error:
return V_34 ;
}
static int F_38 ( struct V_74 * V_75 , unsigned V_69 )
{
return F_39 ( V_75 -> V_76 + V_69 ) ;
}
static void F_40 ( struct V_74 * V_75 , unsigned V_69 )
{
F_41 ( V_75 -> V_76 + V_69 ) ;
}
static int F_42 ( struct V_74 * V_75 ,
unsigned V_69 )
{
return F_43 ( V_75 -> V_76 + V_69 ) ;
}
static int F_44 ( struct V_74 * V_75 , unsigned V_69 )
{
struct V_2 * V_3 = F_45 ( V_75 -> V_37 ) ;
T_1 V_77 = F_46 ( V_69 ) ;
T_3 V_78 = F_47 ( V_69 ) ;
T_1 V_36 = ( F_24 ( V_3 -> V_61 + V_77 ) >> V_78 ) & V_79 ;
return V_36 ;
}
static int F_48 ( struct V_74 * V_75 ,
unsigned V_69 , int V_80 )
{
return F_49 ( V_75 -> V_76 + V_69 ) ;
}
static void F_50 ( struct V_74 * V_75 ,
unsigned V_69 , int V_80 )
{
struct V_2 * V_3 = F_45 ( V_75 -> V_37 ) ;
T_1 V_77 = F_46 ( V_69 ) ;
T_3 V_78 = F_47 ( V_69 ) ;
F_27 ( ( V_80 & V_79 ) << V_78 , V_3 -> V_61 + V_77 ) ;
}
static int F_51 ( struct V_74 * V_81 ,
const struct V_82 * V_83 ,
T_1 * V_84 )
{
int V_20 , V_76 ;
V_76 = V_73 * V_83 -> args [ 0 ] ;
V_20 = V_76 + V_83 -> args [ 1 ] ;
if ( V_20 > ( V_81 -> V_76 + V_81 -> V_85 ) )
return - V_38 ;
if ( V_84 )
* V_84 = V_83 -> args [ 2 ] ;
return V_20 ;
}
static int F_52 ( struct V_2 * V_3 ,
const char * V_9 )
{
struct V_10 * V_11 = V_3 -> V_12 ;
while ( V_11 -> V_9 ) {
if ( strcmp ( V_11 -> V_9 , V_9 ) == 0 ) {
V_11 -> V_6 ++ ;
return - V_86 ;
}
V_11 ++ ;
}
V_11 -> V_9 = V_9 ;
V_11 -> V_6 = 1 ;
V_3 -> V_13 ++ ;
return 0 ;
}
static int F_53 ( struct V_87 * V_88 )
{
struct V_2 * V_3 = F_54 ( V_88 ) ;
int V_5 ;
V_3 -> V_6 = V_3 -> V_17 -> V_18 ;
V_3 -> V_8 = F_55 ( & V_88 -> V_37 ,
V_3 -> V_6 * sizeof( * V_3 -> V_8 ) ,
V_39 ) ;
if ( ! V_3 -> V_8 )
return - V_40 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_1 * V_4 = V_3 -> V_8 + V_5 ;
V_4 -> V_9 = V_20 -> V_20 . V_9 ;
V_4 -> V_20 = V_20 -> V_20 . V_89 ;
}
V_3 -> V_12 = F_55 ( & V_88 -> V_37 ,
V_3 -> V_17 -> V_18 * sizeof( * V_3 -> V_12 ) ,
V_39 ) ;
if ( ! V_3 -> V_12 )
return - V_40 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
F_52 ( V_3 , V_11 -> V_9 ) ;
V_11 ++ ;
}
}
V_3 -> V_12 = F_56 ( V_3 -> V_12 ,
V_3 -> V_13 * sizeof( * V_3 -> V_12 ) ,
V_39 ) ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
struct V_14 * V_11 = V_20 -> V_12 ;
while ( V_11 -> V_9 ) {
struct V_10 * V_90 ;
const char * * V_91 ;
V_90 = F_2 ( V_3 ,
V_11 -> V_9 ) ;
if ( ! V_90 )
return - V_38 ;
if ( ! V_90 -> V_8 ) {
V_90 -> V_8 =
F_55 ( & V_88 -> V_37 ,
V_90 -> V_6 * sizeof( * V_90 -> V_8 ) ,
V_39 ) ;
if ( ! V_90 -> V_8 )
return - V_40 ;
}
V_91 = V_90 -> V_8 ;
while ( * V_91 )
V_91 ++ ;
* V_91 = V_20 -> V_20 . V_9 ;
V_11 ++ ;
}
}
return 0 ;
}
static int F_57 ( struct V_87 * V_88 )
{
struct V_25 * V_26 = V_88 -> V_37 . V_92 ;
const struct V_93 * V_94 ;
struct V_95 * V_21 ;
struct V_2 * V_3 ;
int V_5 , V_34 , V_96 ;
struct V_97 * V_97 ;
V_3 = F_55 ( & V_88 -> V_37 , sizeof( * V_3 ) , V_39 ) ;
if ( ! V_3 )
return - V_40 ;
F_58 ( V_88 , V_3 ) ;
V_3 -> V_61 = F_59 ( V_26 , 0 ) ;
if ( ! V_3 -> V_61 )
return - V_40 ;
V_94 = F_60 ( V_98 , & V_88 -> V_37 ) ;
if ( ! V_94 )
return - V_99 ;
V_3 -> V_17 = (struct V_100 * ) V_94 -> V_44 ;
V_34 = F_53 ( V_88 ) ;
if ( V_34 ) {
F_10 ( & V_88 -> V_37 , L_12 , V_34 ) ;
return V_34 ;
}
V_21 = F_55 ( & V_88 -> V_37 ,
V_3 -> V_17 -> V_18 * sizeof( * V_21 ) ,
V_39 ) ;
if ( ! V_21 )
return - V_40 ;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ )
V_21 [ V_5 ] = V_3 -> V_17 -> V_21 [ V_5 ] . V_20 ;
V_101 . V_9 = F_61 ( & V_88 -> V_37 ) ;
V_101 . V_102 = V_103 ;
V_101 . V_21 = V_21 ;
V_101 . V_18 = V_3 -> V_17 -> V_18 ;
V_3 -> V_37 = & V_88 -> V_37 ;
V_3 -> V_104 = F_62 ( & V_101 ,
& V_88 -> V_37 , V_3 ) ;
if ( ! V_3 -> V_104 ) {
F_10 ( & V_88 -> V_37 , L_13 ) ;
return - V_38 ;
}
V_3 -> V_75 = F_55 ( & V_88 -> V_37 , sizeof( * V_3 -> V_75 ) , V_39 ) ;
if ( ! V_3 -> V_75 ) {
V_34 = - V_40 ;
goto V_105;
}
V_96 = V_3 -> V_17 -> V_21 [ V_3 -> V_17 -> V_18 - 1 ] . V_20 . V_89 ;
V_3 -> V_75 = & V_106 ;
V_3 -> V_75 -> V_85 = F_63 ( V_96 , V_73 ) ;
V_3 -> V_75 -> V_107 = F_61 ( & V_88 -> V_37 ) ;
V_3 -> V_75 -> V_37 = & V_88 -> V_37 ;
V_3 -> V_75 -> V_76 = 0 ;
V_34 = F_64 ( V_3 -> V_75 ) ;
if ( V_34 )
goto V_105;
for ( V_5 = 0 ; V_5 < V_3 -> V_17 -> V_18 ; V_5 ++ ) {
const struct V_19 * V_20 = V_3 -> V_17 -> V_21 + V_5 ;
V_34 = F_65 ( V_3 -> V_75 , F_61 ( & V_88 -> V_37 ) ,
V_20 -> V_20 . V_89 ,
V_20 -> V_20 . V_89 , 1 ) ;
if ( V_34 )
goto V_108;
}
V_97 = F_66 ( & V_88 -> V_37 , NULL ) ;
if ( F_67 ( V_97 ) ) {
V_34 = F_68 ( V_97 ) ;
goto V_108;
}
F_69 ( V_97 ) ;
F_70 ( & V_88 -> V_37 , L_14 ) ;
return 0 ;
V_108:
if ( F_71 ( V_3 -> V_75 ) )
F_10 ( & V_88 -> V_37 , L_15 ) ;
V_105:
F_72 ( V_3 -> V_104 ) ;
return V_34 ;
}
