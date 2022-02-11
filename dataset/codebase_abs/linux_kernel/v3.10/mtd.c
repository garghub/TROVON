static int
F_1 ( struct V_1 * V_2 , bool V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 . V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_1 V_11 ;
int V_12 , V_13 ;
for ( V_13 = 0 ; V_13 < 40 ; V_13 ++ ) {
F_2 ( V_3 ?
V_14 : V_15 ) ;
F_3 ( V_16 / 10 ) ;
V_12 = F_4 ( V_10 , V_8 , V_17 , - 1 , NULL ,
& V_11 , sizeof( V_11 ) ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_11 & V_18 ) )
return 0 ;
if ( F_5 ( V_19 ) )
return - V_20 ;
}
F_6 ( L_1 , V_2 -> V_21 , V_4 -> V_21 ) ;
return - V_22 ;
}
static int
F_7 ( struct V_9 * V_10 , const struct V_7 * V_8 )
{
const T_1 V_23 = ( V_24 | V_25 |
V_26 ) ;
T_1 V_11 ;
int V_12 ;
V_12 = F_4 ( V_10 , V_8 , V_17 , - 1 , NULL ,
& V_11 , sizeof( V_11 ) ) ;
if ( V_12 )
return V_12 ;
if ( ! ( V_11 & V_23 ) )
return 0 ;
V_12 = F_4 ( V_10 , V_8 , V_27 , - 1 , NULL , NULL , 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_10 , V_8 , V_28 , - 1 , NULL , NULL , 0 ) ;
if ( V_12 )
return V_12 ;
V_11 &= ~ V_23 ;
V_12 = F_4 ( V_10 , V_8 , V_29 , - 1 , & V_11 ,
NULL , sizeof( V_11 ) ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_10 , V_8 ) ;
if ( V_12 )
return V_12 ;
return 0 ;
}
static int
F_9 ( struct V_1 * V_2 , T_2 V_30 , T_3 V_31 )
{
struct V_4 * V_4 = V_2 -> V_5 . V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
unsigned V_32 , V_33 ;
T_1 V_34 [ V_35 ] ;
T_1 V_36 [ V_35 ] ;
int V_12 ;
if ( V_31 != V_8 -> V_37 )
return - V_38 ;
if ( V_8 -> V_39 == 0 )
return - V_40 ;
V_12 = F_7 ( V_10 , V_8 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_10 , V_8 , V_27 , - 1 , NULL , NULL , 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_4 ( V_10 , V_8 , V_8 -> V_39 , V_30 , NULL ,
NULL , 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_1 ( V_2 , false ) ;
memset ( V_34 , 0xff , sizeof( V_34 ) ) ;
for ( V_32 = 0 ; V_32 < V_31 ; V_32 += V_33 ) {
V_33 = F_10 ( V_31 - V_32 , sizeof( V_36 ) ) ;
V_12 = F_11 ( V_10 , V_8 , V_30 + V_32 , V_33 ,
NULL , V_36 ) ;
if ( V_12 )
return V_12 ;
if ( memcmp ( V_34 , V_36 , V_33 ) )
return - V_41 ;
F_12 () ;
if ( F_5 ( V_19 ) )
return - V_20 ;
}
return V_12 ;
}
static int F_13 ( struct V_42 * V_5 , struct V_43 * V_44 )
{
struct V_4 * V_4 = V_5 -> V_6 ;
int V_12 ;
V_12 = V_4 -> V_45 -> V_44 ( V_5 , V_44 -> V_46 , V_44 -> V_31 ) ;
if ( V_12 == 0 ) {
V_44 -> V_47 = V_48 ;
} else {
V_44 -> V_47 = V_49 ;
V_44 -> V_50 = V_51 ;
}
F_14 ( V_44 ) ;
return V_12 ;
}
static void F_15 ( struct V_42 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
int V_12 ;
V_12 = V_4 -> V_45 -> V_52 ( V_5 ) ;
if ( V_12 )
F_6 ( L_2 ,
V_2 -> V_21 , V_4 -> V_21 , V_12 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
int V_12 ;
for (; ; ) {
V_12 = F_18 ( & V_2 -> V_5 ) ;
if ( V_12 != - V_53 )
break;
F_19 ( 1 ) ;
}
F_20 ( V_12 ) ;
}
static void F_21 ( struct V_4 * V_4 )
{
struct V_1 * V_2 ;
F_22 (part, efx_mtd)
F_17 ( V_2 ) ;
F_23 ( & V_4 -> V_54 ) ;
F_24 ( V_4 ) ;
}
static void F_25 ( struct V_4 * V_4 )
{
struct V_1 * V_2 ;
F_22 (part, efx_mtd)
if ( F_26 ( V_4 -> V_10 ) >= V_55 )
snprintf ( V_2 -> V_21 , sizeof( V_2 -> V_21 ) ,
L_3 , V_4 -> V_10 -> V_21 ,
V_2 -> V_56 , V_2 -> V_57 . V_58 ) ;
else
snprintf ( V_2 -> V_21 , sizeof( V_2 -> V_21 ) ,
L_4 , V_4 -> V_10 -> V_21 ,
V_2 -> V_56 ) ;
}
static int F_27 ( struct V_9 * V_10 , struct V_4 * V_4 )
{
struct V_1 * V_2 ;
V_4 -> V_10 = V_10 ;
F_25 ( V_4 ) ;
F_22 (part, efx_mtd) {
V_2 -> V_5 . V_59 = 1 ;
V_2 -> V_5 . V_60 = V_61 ;
V_2 -> V_5 . V_6 = V_4 ;
V_2 -> V_5 . V_21 = V_2 -> V_21 ;
V_2 -> V_5 . V_62 = F_13 ;
V_2 -> V_5 . V_63 = V_4 -> V_45 -> V_64 ;
V_2 -> V_5 . V_65 = V_4 -> V_45 -> V_66 ;
V_2 -> V_5 . V_67 = F_15 ;
if ( F_28 ( & V_2 -> V_5 , NULL , 0 ) )
goto V_68;
}
F_29 ( & V_4 -> V_54 , & V_10 -> V_69 ) ;
return 0 ;
V_68:
while ( V_2 != & V_4 -> V_2 [ 0 ] ) {
-- V_2 ;
F_17 ( V_2 ) ;
}
return - V_70 ;
}
void F_30 ( struct V_9 * V_10 )
{
struct V_4 * V_4 , * V_71 ;
F_20 ( F_31 ( V_10 ) ) ;
F_32 (efx_mtd, next, &efx->mtd_list, node)
F_21 ( V_4 ) ;
}
void F_33 ( struct V_9 * V_10 )
{
struct V_4 * V_4 ;
F_34 () ;
F_35 (efx_mtd, &efx->mtd_list, node)
F_25 ( V_4 ) ;
}
int F_36 ( struct V_9 * V_10 )
{
if ( F_26 ( V_10 ) >= V_55 )
return F_37 ( V_10 ) ;
else
return F_38 ( V_10 ) ;
}
static int F_39 ( struct V_42 * V_5 , T_2 V_30 ,
T_3 V_31 , T_3 * V_72 , T_1 * V_36 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_12 ;
V_12 = F_40 ( & V_74 -> V_75 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_11 ( V_10 , V_8 , V_2 -> V_76 + V_30 , V_31 ,
V_72 , V_36 ) ;
F_41 ( & V_74 -> V_75 ) ;
return V_12 ;
}
static int F_42 ( struct V_42 * V_5 , T_2 V_30 , T_3 V_31 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_12 ;
V_12 = F_40 ( & V_74 -> V_75 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_9 ( V_2 , V_2 -> V_76 + V_30 , V_31 ) ;
F_41 ( & V_74 -> V_75 ) ;
return V_12 ;
}
static int F_43 ( struct V_42 * V_5 , T_2 V_30 ,
T_3 V_31 , T_3 * V_72 , const T_1 * V_36 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
const struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_12 ;
V_12 = F_40 ( & V_74 -> V_75 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_44 ( V_10 , V_8 , V_2 -> V_76 + V_30 , V_31 ,
V_72 , V_36 ) ;
F_41 ( & V_74 -> V_75 ) ;
return V_12 ;
}
static int F_45 ( struct V_42 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
struct V_9 * V_10 = V_4 -> V_10 ;
struct V_73 * V_74 = V_10 -> V_74 ;
int V_12 ;
F_46 ( & V_74 -> V_75 ) ;
V_12 = F_1 ( V_2 , true ) ;
F_41 ( & V_74 -> V_75 ) ;
return V_12 ;
}
static int F_38 ( struct V_9 * V_10 )
{
struct V_73 * V_74 = V_10 -> V_74 ;
struct V_7 * V_8 ;
struct V_4 * V_4 ;
int V_12 = - V_77 ;
F_34 () ;
V_8 = & V_74 -> V_78 ;
if ( F_47 ( V_8 ) && V_8 -> V_79 > V_80 ) {
V_4 = F_48 ( sizeof( * V_4 ) + sizeof( V_4 -> V_2 [ 0 ] ) ,
V_81 ) ;
if ( ! V_4 )
return - V_70 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_21 = L_5 ;
V_4 -> V_45 = & V_82 ;
V_4 -> V_83 = 1 ;
V_4 -> V_2 [ 0 ] . V_5 . type = V_84 ;
V_4 -> V_2 [ 0 ] . V_5 . V_85 = V_86 ;
V_4 -> V_2 [ 0 ] . V_5 . V_79 = V_8 -> V_79 - V_80 ;
V_4 -> V_2 [ 0 ] . V_5 . V_87 = V_8 -> V_37 ;
V_4 -> V_2 [ 0 ] . V_76 = V_80 ;
V_4 -> V_2 [ 0 ] . V_56 = L_6 ;
V_12 = F_27 ( V_10 , V_4 ) ;
if ( V_12 ) {
F_24 ( V_4 ) ;
return V_12 ;
}
}
V_8 = & V_74 -> V_88 ;
if ( F_47 ( V_8 ) && V_8 -> V_79 > V_89 ) {
V_4 = F_48 ( sizeof( * V_4 ) + sizeof( V_4 -> V_2 [ 0 ] ) ,
V_81 ) ;
if ( ! V_4 )
return - V_70 ;
V_4 -> V_8 = V_8 ;
V_4 -> V_21 = L_7 ;
V_4 -> V_45 = & V_82 ;
V_4 -> V_83 = 1 ;
V_4 -> V_2 [ 0 ] . V_5 . type = V_90 ;
V_4 -> V_2 [ 0 ] . V_5 . V_85 = V_91 ;
V_4 -> V_2 [ 0 ] . V_5 . V_79 =
F_10 ( V_8 -> V_79 , V_92 ) -
V_89 ;
V_4 -> V_2 [ 0 ] . V_5 . V_87 = V_8 -> V_37 ;
V_4 -> V_2 [ 0 ] . V_76 = V_89 ;
V_4 -> V_2 [ 0 ] . V_56 = L_8 ;
V_12 = F_27 ( V_10 , V_4 ) ;
if ( V_12 ) {
F_24 ( V_4 ) ;
return V_12 ;
}
}
return V_12 ;
}
static int F_49 ( struct V_42 * V_5 , T_2 V_30 ,
T_3 V_31 , T_3 * V_72 , T_1 * V_36 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_76 = V_30 ;
T_2 V_93 = F_50 ( T_2 , V_30 + V_31 , V_5 -> V_79 ) ;
T_3 V_94 ;
int V_12 = 0 ;
while ( V_76 < V_93 ) {
V_94 = F_50 ( T_3 , V_93 - V_76 , V_95 ) ;
V_12 = F_51 ( V_10 , V_2 -> V_57 . V_96 , V_76 ,
V_36 , V_94 ) ;
if ( V_12 )
goto V_97;
V_76 += V_94 ;
V_36 += V_94 ;
}
V_97:
* V_72 = V_76 - V_30 ;
return V_12 ;
}
static int F_52 ( struct V_42 * V_5 , T_2 V_30 , T_3 V_31 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_76 = V_30 & ~ ( ( T_2 ) ( V_5 -> V_87 - 1 ) ) ;
T_2 V_93 = F_50 ( T_2 , V_30 + V_31 , V_5 -> V_79 ) ;
T_3 V_94 = V_2 -> V_5 . V_87 ;
int V_12 = 0 ;
if ( ! V_2 -> V_57 . V_98 ) {
V_12 = F_53 ( V_10 , V_2 -> V_57 . V_96 ) ;
if ( V_12 )
goto V_97;
V_2 -> V_57 . V_98 = true ;
}
while ( V_76 < V_93 ) {
V_12 = F_54 ( V_10 , V_2 -> V_57 . V_96 , V_76 ,
V_94 ) ;
if ( V_12 )
goto V_97;
V_76 += V_94 ;
}
V_97:
return V_12 ;
}
static int F_55 ( struct V_42 * V_5 , T_2 V_30 ,
T_3 V_31 , T_3 * V_72 , const T_1 * V_36 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
struct V_9 * V_10 = V_4 -> V_10 ;
T_2 V_76 = V_30 ;
T_2 V_93 = F_50 ( T_2 , V_30 + V_31 , V_5 -> V_79 ) ;
T_3 V_94 ;
int V_12 = 0 ;
if ( ! V_2 -> V_57 . V_98 ) {
V_12 = F_53 ( V_10 , V_2 -> V_57 . V_96 ) ;
if ( V_12 )
goto V_97;
V_2 -> V_57 . V_98 = true ;
}
while ( V_76 < V_93 ) {
V_94 = F_50 ( T_3 , V_93 - V_76 , V_95 ) ;
V_12 = F_56 ( V_10 , V_2 -> V_57 . V_96 , V_76 ,
V_36 , V_94 ) ;
if ( V_12 )
goto V_97;
V_76 += V_94 ;
V_36 += V_94 ;
}
V_97:
* V_72 = V_76 - V_30 ;
return V_12 ;
}
static int F_57 ( struct V_42 * V_5 )
{
struct V_1 * V_2 = F_16 ( V_5 ) ;
struct V_4 * V_4 = V_5 -> V_6 ;
struct V_9 * V_10 = V_4 -> V_10 ;
int V_12 = 0 ;
if ( V_2 -> V_57 . V_98 ) {
V_2 -> V_57 . V_98 = false ;
V_12 = F_58 ( V_10 , V_2 -> V_57 . V_96 ) ;
}
return V_12 ;
}
static int F_59 ( struct V_9 * V_10 ,
struct V_4 * V_4 ,
unsigned int V_99 ,
unsigned int type )
{
struct V_1 * V_2 = & V_4 -> V_2 [ V_99 ] ;
const struct V_100 * V_101 ;
T_3 V_79 , V_37 ;
bool V_102 ;
int V_12 ;
if ( type >= F_60 ( V_103 ) ||
V_103 [ type ] . V_21 == NULL )
return - V_77 ;
V_101 = & V_103 [ type ] ;
if ( V_101 -> V_104 != F_61 ( V_10 ) )
return - V_77 ;
V_12 = F_62 ( V_10 , type , & V_79 , & V_37 , & V_102 ) ;
if ( V_12 )
return V_12 ;
if ( V_102 )
return - V_77 ;
V_2 -> V_57 . V_96 = type ;
V_2 -> V_56 = V_101 -> V_21 ;
V_2 -> V_5 . type = V_84 ;
V_2 -> V_5 . V_85 = V_86 ;
V_2 -> V_5 . V_79 = V_79 ;
V_2 -> V_5 . V_87 = V_37 ;
return 0 ;
}
static int F_63 ( struct V_9 * V_10 ,
struct V_4 * V_4 )
{
struct V_1 * V_2 ;
T_4 V_105 [
V_106 ] ;
int V_12 ;
V_12 = F_64 ( V_10 , NULL , V_105 , NULL ) ;
if ( V_12 )
return V_12 ;
F_22 (part, efx_mtd)
V_2 -> V_57 . V_58 = V_105 [ V_2 -> V_57 . V_96 ] ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 )
{
struct V_4 * V_4 ;
int V_12 = - V_77 ;
T_5 V_107 ;
unsigned int type ;
F_34 () ;
V_12 = F_65 ( V_10 , & V_107 ) ;
if ( V_12 )
return V_12 ;
V_4 = F_48 ( sizeof( * V_4 ) +
F_66 ( V_107 ) * sizeof( V_4 -> V_2 [ 0 ] ) ,
V_81 ) ;
if ( ! V_4 )
return - V_70 ;
V_4 -> V_21 = L_9 ;
V_4 -> V_45 = & V_108 ;
type = 0 ;
V_4 -> V_83 = 0 ;
while ( V_107 != 0 ) {
if ( V_107 & 1 ) {
V_12 = F_59 ( V_10 , V_4 ,
V_4 -> V_83 , type ) ;
if ( V_12 == 0 )
V_4 -> V_83 ++ ;
else if ( V_12 != - V_77 )
goto V_68;
}
type ++ ;
V_107 >>= 1 ;
}
V_12 = F_63 ( V_10 , V_4 ) ;
if ( V_12 )
goto V_68;
V_12 = F_27 ( V_10 , V_4 ) ;
V_68:
if ( V_12 )
F_24 ( V_4 ) ;
return V_12 ;
}
