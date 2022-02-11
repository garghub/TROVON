static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 ;
int V_7 = 0 , V_8 ;
F_2 ( V_2 ) ;
V_6 = F_3 ( V_2 , V_4 -> V_9 -> V_10 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
V_8 = V_6 -> V_8 ;
if ( V_4 -> V_9 -> V_12 == 0 && ( V_6 -> free != V_2 -> V_13 || V_6 -> V_8 != 0 ) ) {
F_6 ( L_1 , V_4 -> V_9 -> V_10 ,
V_6 -> free , V_6 -> V_8 ) ;
F_7 ( L_1 , V_4 -> V_9 -> V_10 ,
V_6 -> free , V_6 -> V_8 ) ;
V_8 -= V_2 -> V_13 - V_6 -> free ;
if ( V_8 != 0 )
F_8 ( L_2
L_3 , V_4 -> V_9 -> V_10 ,
V_6 -> free , V_6 -> V_8 , V_4 -> free , V_4 -> V_8 ) ;
}
V_6 = F_9 ( V_2 , V_6 , V_4 -> free , V_8 + V_4 -> V_8 ,
V_6 -> V_14 | V_15 , 0 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
V_7 = F_10 ( & V_2 -> V_16 [ V_4 -> V_9 -> V_17 ] . V_18 ,
V_4 -> V_9 -> V_10 , V_2 -> V_13 - V_4 -> free ,
V_19 ) ;
V_11:
F_11 ( V_2 ) ;
return V_7 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
F_13 (b, &c->replay_buds, list) {
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
unsigned V_22 , V_23 ;
union V_24 V_25 , V_26 ;
T_1 V_27 ;
V_22 = V_21 -> V_28 / V_29 ;
if ( V_21 -> V_28 & ( V_29 - 1 ) )
V_22 += 1 ;
V_23 = V_21 -> V_30 / V_29 ;
if ( ( V_21 -> V_30 & ( V_29 - 1 ) ) == 0 )
V_23 -= 1 ;
V_27 = F_15 ( V_2 , & V_21 -> V_31 ) ;
F_16 ( V_2 , & V_25 , V_27 , V_22 ) ;
F_16 ( V_2 , & V_26 , V_27 , V_23 ) ;
return F_17 ( V_2 , & V_25 , & V_26 ) ;
}
static int F_18 ( struct V_1 * V_2 , struct V_20 * V_21 )
{
int V_7 ;
F_19 ( & V_21 -> V_31 , L_4 ,
V_21 -> V_10 , V_21 -> V_32 , V_21 -> V_33 , V_21 -> V_34 , V_21 -> V_35 ) ;
V_2 -> V_36 = V_21 -> V_35 ;
if ( F_20 ( V_2 , & V_21 -> V_31 ) ) {
if ( V_21 -> V_34 )
V_7 = F_21 ( V_2 , & V_21 -> V_31 , & V_21 -> V_37 ) ;
else
V_7 = F_22 ( V_2 , & V_21 -> V_31 , V_21 -> V_10 , V_21 -> V_32 ,
V_21 -> V_33 , & V_21 -> V_37 ) ;
} else {
if ( V_21 -> V_34 )
switch ( F_23 ( V_2 , & V_21 -> V_31 ) ) {
case V_38 :
{
T_1 V_39 = F_15 ( V_2 , & V_21 -> V_31 ) ;
V_7 = F_24 ( V_2 , V_39 ) ;
break;
}
case V_40 :
V_7 = F_14 ( V_2 , V_21 ) ;
break;
default:
V_7 = F_25 ( V_2 , & V_21 -> V_31 ) ;
break;
}
else
V_7 = F_26 ( V_2 , & V_21 -> V_31 , V_21 -> V_10 , V_21 -> V_32 ,
V_21 -> V_33 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_41 )
V_7 = F_27 ( V_2 , & V_21 -> V_31 , V_21 -> V_34 ,
V_21 -> V_28 ) ;
}
return V_7 ;
}
static int F_28 ( void * V_42 , struct V_43 * V_44 ,
struct V_43 * V_4 )
{
struct V_20 * V_45 , * V_46 ;
F_29 () ;
if ( V_44 == V_4 )
return 0 ;
V_45 = F_30 ( V_44 , struct V_20 , V_47 ) ;
V_46 = F_30 ( V_4 , struct V_20 , V_47 ) ;
F_31 ( V_45 -> V_35 != V_46 -> V_35 ) ;
if ( V_45 -> V_35 > V_46 -> V_35 )
return 1 ;
return - 1 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_20 * V_21 ;
int V_7 ;
F_33 ( V_2 , & V_2 -> V_48 , & F_28 ) ;
F_13 (r, &c->replay_list, list) {
F_29 () ;
V_7 = F_18 ( V_2 , V_21 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_20 * V_21 , * V_49 ;
F_35 (r, tmp, &c->replay_list, list) {
if ( F_20 ( V_2 , & V_21 -> V_31 ) )
F_36 ( V_21 -> V_37 . V_50 ) ;
F_37 ( & V_21 -> V_47 ) ;
F_36 ( V_21 ) ;
}
}
static int F_38 ( struct V_1 * V_2 , int V_10 , int V_32 , int V_33 ,
union V_24 * V_31 , unsigned long long V_35 ,
int V_34 , int * V_51 , T_2 V_30 ,
T_2 V_28 )
{
struct V_20 * V_21 ;
F_19 ( V_31 , L_5 , V_10 , V_32 ) ;
if ( F_15 ( V_2 , V_31 ) >= V_2 -> V_52 )
V_2 -> V_52 = F_15 ( V_2 , V_31 ) ;
V_21 = F_39 ( sizeof( struct V_20 ) , V_53 ) ;
if ( ! V_21 )
return - V_54 ;
if ( ! V_34 )
* V_51 += F_40 ( V_33 , 8 ) ;
V_21 -> V_10 = V_10 ;
V_21 -> V_32 = V_32 ;
V_21 -> V_33 = V_33 ;
V_21 -> V_34 = ! ! V_34 ;
V_21 -> V_35 = V_35 ;
F_41 ( V_2 , V_31 , & V_21 -> V_31 ) ;
V_21 -> V_30 = V_30 ;
V_21 -> V_28 = V_28 ;
F_42 ( & V_21 -> V_47 , & V_2 -> V_48 ) ;
return 0 ;
}
static int F_43 ( struct V_1 * V_2 , int V_10 , int V_32 , int V_33 ,
union V_24 * V_31 , const char * V_50 , int V_55 ,
unsigned long long V_35 , int V_34 , int * V_51 )
{
struct V_20 * V_21 ;
char * V_56 ;
F_19 ( V_31 , L_5 , V_10 , V_32 ) ;
if ( F_15 ( V_2 , V_31 ) >= V_2 -> V_52 )
V_2 -> V_52 = F_15 ( V_2 , V_31 ) ;
V_21 = F_39 ( sizeof( struct V_20 ) , V_53 ) ;
if ( ! V_21 )
return - V_54 ;
V_56 = F_44 ( V_55 + 1 , V_53 ) ;
if ( ! V_56 ) {
F_36 ( V_21 ) ;
return - V_54 ;
}
if ( ! V_34 )
* V_51 += F_40 ( V_33 , 8 ) ;
V_21 -> V_10 = V_10 ;
V_21 -> V_32 = V_32 ;
V_21 -> V_33 = V_33 ;
V_21 -> V_34 = ! ! V_34 ;
V_21 -> V_35 = V_35 ;
F_41 ( V_2 , V_31 , & V_21 -> V_31 ) ;
V_21 -> V_37 . V_33 = V_55 ;
memcpy ( V_56 , V_50 , V_55 ) ;
V_56 [ V_55 ] = '\0' ;
V_21 -> V_37 . V_50 = V_56 ;
F_42 ( & V_21 -> V_47 , & V_2 -> V_48 ) ;
return 0 ;
}
int F_45 ( struct V_1 * V_2 ,
const struct V_57 * V_58 )
{
int F_23 = F_46 ( V_2 , V_58 -> V_31 ) ;
int V_55 = F_47 ( V_58 -> V_55 ) ;
if ( F_48 ( V_58 -> V_59 . V_33 ) != V_55 + V_60 + 1 ||
V_58 -> type >= V_61 ||
V_55 > V_62 || V_58 -> V_50 [ V_55 ] != 0 ||
F_49 ( V_58 -> V_50 , V_55 ) != V_55 ||
F_50 ( V_58 -> V_39 ) > V_63 ) {
F_51 ( L_6 , F_23 == V_64 ?
L_7 : L_8 ) ;
return - V_65 ;
}
if ( F_23 != V_64 && F_23 != V_66 ) {
F_51 ( L_9 , F_23 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , struct V_67 * V_9 )
{
struct V_68 * V_69 = & V_2 -> V_16 [ V_9 -> V_17 ] ;
struct V_67 * V_70 ;
T_3 V_71 ;
int V_7 ;
if ( F_53 ( & V_9 -> V_47 , & V_69 -> V_72 ) )
return 1 ;
V_70 = F_30 ( V_9 -> V_47 . V_70 , struct V_67 , V_47 ) ;
if ( ! F_53 ( & V_70 -> V_47 , & V_69 -> V_72 ) )
return 0 ;
V_7 = F_54 ( V_2 , V_70 -> V_10 , ( char * ) & V_71 , V_70 -> V_12 , 4 , 1 ) ;
if ( V_7 )
return 0 ;
return V_71 == 0xFFFFFFFF ;
}
static int F_55 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_73 = F_52 ( V_2 , V_4 -> V_9 ) ;
int V_7 = 0 , V_51 = 0 , V_10 = V_4 -> V_9 -> V_10 , V_32 = V_4 -> V_9 -> V_12 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
F_6 ( L_10 ,
V_10 , V_4 -> V_9 -> V_17 , V_32 , V_73 ) ;
if ( V_2 -> V_41 && V_73 )
V_75 = F_56 ( V_2 , V_10 , V_32 , V_2 -> V_78 , V_4 -> V_9 -> V_17 ) ;
else
V_75 = F_57 ( V_2 , V_10 , V_32 , V_2 -> V_78 , 0 ) ;
if ( F_4 ( V_75 ) )
return F_5 ( V_75 ) ;
F_13 (snod, &sleb->nodes, list) {
int V_34 = 0 ;
F_29 () ;
if ( V_77 -> V_35 >= V_79 ) {
F_51 ( L_11 ) ;
goto V_80;
}
if ( V_77 -> V_35 > V_2 -> V_81 )
V_2 -> V_81 = V_77 -> V_35 ;
switch ( V_77 -> type ) {
case V_82 :
{
struct V_83 * V_27 = V_77 -> V_84 ;
T_2 V_28 = F_50 ( V_27 -> V_85 ) ;
if ( F_48 ( V_27 -> V_86 ) == 0 )
V_34 = 1 ;
V_7 = F_38 ( V_2 , V_10 , V_77 -> V_32 , V_77 -> V_33 ,
& V_77 -> V_31 , V_77 -> V_35 , V_34 ,
& V_51 , 0 , V_28 ) ;
break;
}
case V_87 :
{
struct V_88 * V_89 = V_77 -> V_84 ;
T_2 V_28 = F_48 ( V_89 -> V_85 ) +
F_58 ( V_2 , & V_77 -> V_31 ) *
V_29 ;
V_7 = F_38 ( V_2 , V_10 , V_77 -> V_32 , V_77 -> V_33 ,
& V_77 -> V_31 , V_77 -> V_35 , V_34 ,
& V_51 , 0 , V_28 ) ;
break;
}
case V_90 :
case V_91 :
{
struct V_57 * V_58 = V_77 -> V_84 ;
V_7 = F_45 ( V_2 , V_58 ) ;
if ( V_7 )
goto V_80;
V_7 = F_43 ( V_2 , V_10 , V_77 -> V_32 , V_77 -> V_33 ,
& V_77 -> V_31 , V_58 -> V_50 ,
F_47 ( V_58 -> V_55 ) , V_77 -> V_35 ,
! F_50 ( V_58 -> V_39 ) , & V_51 ) ;
break;
}
case V_92 :
{
struct V_93 * V_94 = V_77 -> V_84 ;
T_2 V_30 = F_50 ( V_94 -> V_30 ) ;
T_2 V_28 = F_50 ( V_94 -> V_28 ) ;
union V_24 V_31 ;
if ( V_30 < 0 || V_30 > V_2 -> V_95 ||
V_28 < 0 || V_28 > V_2 -> V_95 ||
V_30 <= V_28 ) {
F_51 ( L_12 ) ;
goto V_80;
}
F_59 ( V_2 , & V_31 , F_48 ( V_94 -> V_39 ) ) ;
V_7 = F_38 ( V_2 , V_10 , V_77 -> V_32 , V_77 -> V_33 ,
& V_31 , V_77 -> V_35 , 1 , & V_51 ,
V_30 , V_28 ) ;
break;
}
default:
F_51 ( L_13 ,
V_77 -> type , V_10 , V_77 -> V_32 ) ;
V_7 = - V_65 ;
goto V_80;
}
if ( V_7 )
goto V_11;
}
F_31 ( F_60 ( V_2 , V_10 ) ) ;
F_31 ( V_75 -> V_96 - V_32 >= V_51 ) ;
F_31 ( V_75 -> V_96 % V_2 -> V_97 == 0 ) ;
V_4 -> V_8 = V_75 -> V_96 - V_32 - V_51 ;
V_4 -> free = V_2 -> V_13 - V_75 -> V_96 ;
F_6 ( L_14 , V_10 , V_4 -> V_8 , V_4 -> free ) ;
V_11:
F_61 ( V_75 ) ;
return V_7 ;
V_80:
F_51 ( L_15 , V_10 , V_77 -> V_32 ) ;
F_62 ( V_2 , V_77 -> V_84 ) ;
F_61 ( V_75 ) ;
return - V_65 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
unsigned long long V_98 = 0 ;
F_13 (b, &c->replay_buds, list) {
V_7 = F_55 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
F_31 ( V_4 -> V_35 > V_98 ) ;
V_98 = V_4 -> V_35 ;
}
return 0 ;
}
static void F_64 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_65 ( & V_2 -> F_63 ) ) {
V_4 = F_30 ( V_2 -> F_63 . V_70 , struct V_3 , V_47 ) ;
F_37 ( & V_4 -> V_47 ) ;
F_36 ( V_4 ) ;
}
}
static int F_66 ( struct V_1 * V_2 , int V_10 , int V_32 , int V_17 ,
unsigned long long V_35 )
{
struct V_67 * V_9 ;
struct V_3 * V_4 ;
F_6 ( L_16 , V_10 , V_32 , V_17 ) ;
V_9 = F_44 ( sizeof( struct V_67 ) , V_53 ) ;
if ( ! V_9 )
return - V_54 ;
V_4 = F_44 ( sizeof( struct V_3 ) , V_53 ) ;
if ( ! V_4 ) {
F_36 ( V_9 ) ;
return - V_54 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_12 = V_32 ;
V_9 -> V_17 = V_17 ;
F_67 ( V_2 , V_9 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_35 = V_35 ;
F_42 ( & V_4 -> V_47 , & V_2 -> F_63 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , const struct V_99 * V_100 )
{
struct V_67 * V_9 ;
int V_10 = F_48 ( V_100 -> V_10 ) ;
unsigned int V_32 = F_48 ( V_100 -> V_32 ) ;
unsigned int V_17 = F_48 ( V_100 -> V_17 ) ;
if ( V_17 >= V_2 -> V_101 || V_10 >= V_2 -> V_102 ||
V_10 < V_2 -> V_103 || V_32 > V_2 -> V_13 ||
V_32 & ( V_2 -> V_97 - 1 ) )
return - V_65 ;
V_9 = F_60 ( V_2 , V_10 ) ;
if ( V_9 ) {
if ( V_9 -> V_17 == V_17 && V_9 -> V_12 <= V_32 )
return 1 ;
F_51 ( L_17 , V_10 , V_32 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 , int V_10 , int V_32 , void * V_78 )
{
int V_7 ;
struct V_74 * V_75 ;
struct V_76 * V_77 ;
const struct V_104 * V_84 ;
F_6 ( L_18 , V_10 , V_32 ) ;
V_75 = F_57 ( V_2 , V_10 , V_32 , V_78 , V_2 -> V_41 ) ;
if ( F_4 ( V_75 ) ) {
if ( F_5 ( V_75 ) != - V_105 || ! V_2 -> V_41 )
return F_5 ( V_75 ) ;
V_75 = F_70 ( V_2 , V_10 , V_32 , V_78 ) ;
if ( F_4 ( V_75 ) )
return F_5 ( V_75 ) ;
}
if ( V_75 -> V_106 == 0 ) {
V_7 = 1 ;
goto V_11;
}
V_84 = V_75 -> V_107 ;
V_77 = F_30 ( V_75 -> V_108 . V_70 , struct V_76 , V_47 ) ;
if ( V_2 -> V_109 == 0 ) {
if ( V_77 -> type != V_110 ) {
F_71 ( L_19 ,
V_10 , V_32 ) ;
goto V_80;
}
if ( F_50 ( V_84 -> V_111 ) != V_2 -> V_111 ) {
F_71 ( L_20
L_21 ,
V_10 , V_32 ,
( unsigned long long ) F_50 ( V_84 -> V_111 ) ,
V_2 -> V_111 ) ;
goto V_80;
}
V_2 -> V_109 = F_50 ( V_84 -> V_59 . V_35 ) ;
F_6 ( L_22 , V_2 -> V_109 ) ;
}
if ( V_77 -> V_35 < V_2 -> V_109 ) {
V_7 = 1 ;
goto V_11;
}
if ( V_77 -> V_32 != 0 ) {
F_71 ( L_23 ) ;
goto V_80;
}
F_13 (snod, &sleb->nodes, list) {
F_29 () ;
if ( V_77 -> V_35 >= V_79 ) {
F_51 ( L_11 ) ;
goto V_80;
}
if ( V_77 -> V_35 < V_2 -> V_109 ) {
F_71 ( L_24 ,
V_77 -> V_35 , V_2 -> V_109 ) ;
goto V_80;
}
if ( V_77 -> V_35 > V_2 -> V_81 )
V_2 -> V_81 = V_77 -> V_35 ;
switch ( V_77 -> type ) {
case V_112 : {
const struct V_99 * V_100 = V_77 -> V_84 ;
V_7 = F_68 ( V_2 , V_100 ) ;
if ( V_7 == 1 )
break;
if ( V_7 )
goto V_80;
V_7 = F_66 ( V_2 , F_48 ( V_100 -> V_10 ) ,
F_48 ( V_100 -> V_32 ) ,
F_48 ( V_100 -> V_17 ) ,
V_77 -> V_35 ) ;
if ( V_7 )
goto V_11;
break;
}
case V_110 :
if ( V_77 -> V_32 != 0 ) {
F_51 ( L_25 ) ;
goto V_80;
}
break;
default:
F_51 ( L_25 ) ;
goto V_80;
}
}
if ( V_75 -> V_96 || V_2 -> V_113 >= V_2 -> V_13 ) {
V_2 -> V_114 = V_10 ;
V_2 -> V_113 = V_75 -> V_96 ;
}
V_7 = ! V_75 -> V_96 ;
V_11:
F_61 ( V_75 ) ;
return V_7 ;
V_80:
F_51 ( L_26 ,
V_10 , V_32 + V_77 -> V_32 ) ;
F_62 ( V_2 , V_77 -> V_84 ) ;
F_61 ( V_75 ) ;
return - V_65 ;
}
static int F_72 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 ;
int V_7 , free ;
F_2 ( V_2 ) ;
V_6 = F_3 ( V_2 , V_2 -> V_115 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
free = V_6 -> free ;
V_6 = F_9 ( V_2 , V_6 , V_116 , V_116 ,
V_6 -> V_14 | V_15 , 0 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
V_7 = free ;
V_11:
F_11 ( V_2 ) ;
return V_7 ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_7 , V_117 , V_10 , V_32 , free ;
F_74 ( V_40 > 5 ) ;
free = F_72 ( V_2 ) ;
if ( free < 0 )
return free ;
if ( V_2 -> V_118 != V_2 -> V_13 - free ) {
F_51 ( L_27 , V_2 -> V_115 ,
V_2 -> V_118 ) ;
return - V_65 ;
}
F_6 ( L_28 ) ;
V_2 -> V_119 = 1 ;
V_10 = V_2 -> V_120 = V_2 -> V_114 ;
V_32 = V_2 -> V_113 ;
for ( V_117 = 0 ; V_117 < V_2 -> V_121 ; V_117 ++ , V_10 ++ ) {
if ( V_10 >= V_122 + V_2 -> V_121 ) {
V_10 = V_122 ;
V_32 = 0 ;
}
V_7 = F_69 ( V_2 , V_10 , V_32 , V_2 -> V_78 ) ;
if ( V_7 == 1 )
break;
if ( V_7 )
goto V_11;
V_32 = 0 ;
}
V_7 = F_63 ( V_2 ) ;
if ( V_7 )
goto V_11;
V_7 = F_32 ( V_2 ) ;
if ( V_7 )
goto V_11;
V_7 = F_12 ( V_2 ) ;
if ( V_7 )
goto V_11;
V_2 -> V_123 . V_124 = F_75 ( & V_2 -> V_125 ) ;
V_2 -> V_123 . V_124 *= V_2 -> V_126 ;
F_31 ( V_2 -> V_127 <= V_2 -> V_128 || V_2 -> V_41 ) ;
F_6 ( L_29
L_30 , V_2 -> V_114 , V_2 -> V_113 , V_2 -> V_81 ,
( unsigned long ) V_2 -> V_52 ) ;
V_11:
F_34 ( V_2 ) ;
F_64 ( V_2 ) ;
V_2 -> V_119 = 0 ;
return V_7 ;
}
