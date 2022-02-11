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
F_6 ( L_2 ,
V_4 -> V_9 -> V_10 , V_6 -> free , V_6 -> V_8 , V_4 -> free ,
V_4 -> V_8 ) ;
}
V_6 = F_8 ( V_2 , V_6 , V_4 -> free , V_8 + V_4 -> V_8 ,
V_6 -> V_14 | V_15 , 0 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
V_7 = F_9 ( & V_2 -> V_16 [ V_4 -> V_9 -> V_17 ] . V_18 ,
V_4 -> V_9 -> V_10 , V_2 -> V_13 - V_4 -> free ) ;
V_11:
F_10 ( V_2 ) ;
return V_7 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
F_12 (b, &c->replay_buds, list) {
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
unsigned V_21 , V_22 ;
union V_23 V_24 , V_25 ;
T_1 V_26 ;
V_21 = V_20 -> V_27 / V_28 ;
if ( V_20 -> V_27 & ( V_28 - 1 ) )
V_21 += 1 ;
V_22 = V_20 -> V_29 / V_28 ;
if ( ( V_20 -> V_29 & ( V_28 - 1 ) ) == 0 )
V_22 -= 1 ;
V_26 = F_14 ( V_2 , & V_20 -> V_30 ) ;
F_15 ( V_2 , & V_24 , V_26 , V_21 ) ;
F_15 ( V_2 , & V_25 , V_26 , V_22 ) ;
return F_16 ( V_2 , & V_24 , & V_25 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
int V_7 ;
F_18 ( & V_20 -> V_30 , L_3 ,
V_20 -> V_10 , V_20 -> V_31 , V_20 -> V_32 , V_20 -> V_33 , V_20 -> V_34 ) ;
V_2 -> V_35 = V_20 -> V_34 ;
if ( F_19 ( V_2 , & V_20 -> V_30 ) ) {
if ( V_20 -> V_33 )
V_7 = F_20 ( V_2 , & V_20 -> V_30 , & V_20 -> V_36 ) ;
else
V_7 = F_21 ( V_2 , & V_20 -> V_30 , V_20 -> V_10 , V_20 -> V_31 ,
V_20 -> V_32 , & V_20 -> V_36 ) ;
} else {
if ( V_20 -> V_33 )
switch ( F_22 ( V_2 , & V_20 -> V_30 ) ) {
case V_37 :
{
T_1 V_38 = F_14 ( V_2 , & V_20 -> V_30 ) ;
V_7 = F_23 ( V_2 , V_38 ) ;
break;
}
case V_39 :
V_7 = F_13 ( V_2 , V_20 ) ;
break;
default:
V_7 = F_24 ( V_2 , & V_20 -> V_30 ) ;
break;
}
else
V_7 = F_25 ( V_2 , & V_20 -> V_30 , V_20 -> V_10 , V_20 -> V_31 ,
V_20 -> V_32 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_40 )
V_7 = F_26 ( V_2 , & V_20 -> V_30 , V_20 -> V_33 ,
V_20 -> V_27 ) ;
}
return V_7 ;
}
static int F_27 ( void * V_41 , struct V_42 * V_43 ,
struct V_42 * V_4 )
{
struct V_19 * V_44 , * V_45 ;
F_28 () ;
if ( V_43 == V_4 )
return 0 ;
V_44 = F_29 ( V_43 , struct V_19 , V_46 ) ;
V_45 = F_29 ( V_4 , struct V_19 , V_46 ) ;
F_30 ( V_44 -> V_34 != V_45 -> V_34 ) ;
if ( V_44 -> V_34 > V_45 -> V_34 )
return 1 ;
return - 1 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
int V_7 ;
F_32 ( V_2 , & V_2 -> V_47 , & F_27 ) ;
F_12 (r, &c->replay_list, list) {
F_28 () ;
V_7 = F_17 ( V_2 , V_20 ) ;
if ( V_7 )
return V_7 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_48 ;
F_34 (r, tmp, &c->replay_list, list) {
if ( F_19 ( V_2 , & V_20 -> V_30 ) )
F_35 ( V_20 -> V_36 . V_49 ) ;
F_36 ( & V_20 -> V_46 ) ;
F_35 ( V_20 ) ;
}
}
static int F_37 ( struct V_1 * V_2 , int V_10 , int V_31 , int V_32 ,
union V_23 * V_30 , unsigned long long V_34 ,
int V_33 , int * V_50 , T_2 V_29 ,
T_2 V_27 )
{
struct V_19 * V_20 ;
F_18 ( V_30 , L_4 , V_10 , V_31 ) ;
if ( F_14 ( V_2 , V_30 ) >= V_2 -> V_51 )
V_2 -> V_51 = F_14 ( V_2 , V_30 ) ;
V_20 = F_38 ( sizeof( struct V_19 ) , V_52 ) ;
if ( ! V_20 )
return - V_53 ;
if ( ! V_33 )
* V_50 += F_39 ( V_32 , 8 ) ;
V_20 -> V_10 = V_10 ;
V_20 -> V_31 = V_31 ;
V_20 -> V_32 = V_32 ;
V_20 -> V_33 = ! ! V_33 ;
V_20 -> V_34 = V_34 ;
F_40 ( V_2 , V_30 , & V_20 -> V_30 ) ;
V_20 -> V_29 = V_29 ;
V_20 -> V_27 = V_27 ;
F_41 ( & V_20 -> V_46 , & V_2 -> V_47 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , int V_10 , int V_31 , int V_32 ,
union V_23 * V_30 , const char * V_49 , int V_54 ,
unsigned long long V_34 , int V_33 , int * V_50 )
{
struct V_19 * V_20 ;
char * V_55 ;
F_18 ( V_30 , L_4 , V_10 , V_31 ) ;
if ( F_14 ( V_2 , V_30 ) >= V_2 -> V_51 )
V_2 -> V_51 = F_14 ( V_2 , V_30 ) ;
V_20 = F_38 ( sizeof( struct V_19 ) , V_52 ) ;
if ( ! V_20 )
return - V_53 ;
V_55 = F_43 ( V_54 + 1 , V_52 ) ;
if ( ! V_55 ) {
F_35 ( V_20 ) ;
return - V_53 ;
}
if ( ! V_33 )
* V_50 += F_39 ( V_32 , 8 ) ;
V_20 -> V_10 = V_10 ;
V_20 -> V_31 = V_31 ;
V_20 -> V_32 = V_32 ;
V_20 -> V_33 = ! ! V_33 ;
V_20 -> V_34 = V_34 ;
F_40 ( V_2 , V_30 , & V_20 -> V_30 ) ;
V_20 -> V_36 . V_32 = V_54 ;
memcpy ( V_55 , V_49 , V_54 ) ;
V_55 [ V_54 ] = '\0' ;
V_20 -> V_36 . V_49 = V_55 ;
F_41 ( & V_20 -> V_46 , & V_2 -> V_47 ) ;
return 0 ;
}
int F_44 ( struct V_1 * V_2 ,
const struct V_56 * V_57 )
{
int F_22 = F_45 ( V_2 , V_57 -> V_30 ) ;
int V_54 = F_46 ( V_57 -> V_54 ) ;
if ( F_47 ( V_57 -> V_58 . V_32 ) != V_54 + V_59 + 1 ||
V_57 -> type >= V_60 ||
V_54 > V_61 || V_57 -> V_49 [ V_54 ] != 0 ||
F_48 ( V_57 -> V_49 , V_54 ) != V_54 ||
F_49 ( V_57 -> V_38 ) > V_62 ) {
F_50 ( L_5 , F_22 == V_63 ?
L_6 : L_7 ) ;
return - V_64 ;
}
if ( F_22 != V_63 && F_22 != V_65 ) {
F_50 ( L_8 , F_22 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 , struct V_66 * V_9 )
{
struct V_67 * V_68 = & V_2 -> V_16 [ V_9 -> V_17 ] ;
struct V_66 * V_69 ;
T_3 V_70 ;
int V_7 ;
if ( F_52 ( & V_9 -> V_46 , & V_68 -> V_71 ) )
return 1 ;
V_69 = F_29 ( V_9 -> V_46 . V_69 , struct V_66 , V_46 ) ;
if ( ! F_52 ( & V_69 -> V_46 , & V_68 -> V_71 ) )
return 0 ;
V_7 = F_53 ( V_2 , V_69 -> V_10 , ( char * ) & V_70 , V_69 -> V_12 , 4 , 1 ) ;
if ( V_7 )
return 0 ;
return V_70 == 0xFFFFFFFF ;
}
static int F_54 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_72 = F_51 ( V_2 , V_4 -> V_9 ) ;
int V_7 = 0 , V_50 = 0 , V_10 = V_4 -> V_9 -> V_10 , V_31 = V_4 -> V_9 -> V_12 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
F_6 ( L_9 ,
V_10 , V_4 -> V_9 -> V_17 , V_31 , V_72 ) ;
if ( V_2 -> V_40 && V_72 )
V_74 = F_55 ( V_2 , V_10 , V_31 , V_2 -> V_77 , V_4 -> V_9 -> V_17 ) ;
else
V_74 = F_56 ( V_2 , V_10 , V_31 , V_2 -> V_77 , 0 ) ;
if ( F_4 ( V_74 ) )
return F_5 ( V_74 ) ;
F_12 (snod, &sleb->nodes, list) {
int V_33 = 0 ;
F_28 () ;
if ( V_76 -> V_34 >= V_78 ) {
F_50 ( L_10 ) ;
goto V_79;
}
if ( V_76 -> V_34 > V_2 -> V_80 )
V_2 -> V_80 = V_76 -> V_34 ;
switch ( V_76 -> type ) {
case V_81 :
{
struct V_82 * V_26 = V_76 -> V_83 ;
T_2 V_27 = F_49 ( V_26 -> V_84 ) ;
if ( F_47 ( V_26 -> V_85 ) == 0 )
V_33 = 1 ;
V_7 = F_37 ( V_2 , V_10 , V_76 -> V_31 , V_76 -> V_32 ,
& V_76 -> V_30 , V_76 -> V_34 , V_33 ,
& V_50 , 0 , V_27 ) ;
break;
}
case V_86 :
{
struct V_87 * V_88 = V_76 -> V_83 ;
T_2 V_27 = F_47 ( V_88 -> V_84 ) +
F_57 ( V_2 , & V_76 -> V_30 ) *
V_28 ;
V_7 = F_37 ( V_2 , V_10 , V_76 -> V_31 , V_76 -> V_32 ,
& V_76 -> V_30 , V_76 -> V_34 , V_33 ,
& V_50 , 0 , V_27 ) ;
break;
}
case V_89 :
case V_90 :
{
struct V_56 * V_57 = V_76 -> V_83 ;
V_7 = F_44 ( V_2 , V_57 ) ;
if ( V_7 )
goto V_79;
V_7 = F_42 ( V_2 , V_10 , V_76 -> V_31 , V_76 -> V_32 ,
& V_76 -> V_30 , V_57 -> V_49 ,
F_46 ( V_57 -> V_54 ) , V_76 -> V_34 ,
! F_49 ( V_57 -> V_38 ) , & V_50 ) ;
break;
}
case V_91 :
{
struct V_92 * V_93 = V_76 -> V_83 ;
T_2 V_29 = F_49 ( V_93 -> V_29 ) ;
T_2 V_27 = F_49 ( V_93 -> V_27 ) ;
union V_23 V_30 ;
if ( V_29 < 0 || V_29 > V_2 -> V_94 ||
V_27 < 0 || V_27 > V_2 -> V_94 ||
V_29 <= V_27 ) {
F_50 ( L_11 ) ;
goto V_79;
}
F_58 ( V_2 , & V_30 , F_47 ( V_93 -> V_38 ) ) ;
V_7 = F_37 ( V_2 , V_10 , V_76 -> V_31 , V_76 -> V_32 ,
& V_30 , V_76 -> V_34 , 1 , & V_50 ,
V_29 , V_27 ) ;
break;
}
default:
F_50 ( L_12 ,
V_76 -> type , V_10 , V_76 -> V_31 ) ;
V_7 = - V_64 ;
goto V_79;
}
if ( V_7 )
goto V_11;
}
F_30 ( F_59 ( V_2 , V_10 ) ) ;
F_30 ( V_74 -> V_95 - V_31 >= V_50 ) ;
F_30 ( V_74 -> V_95 % V_2 -> V_96 == 0 ) ;
V_4 -> V_8 = V_74 -> V_95 - V_31 - V_50 ;
V_4 -> free = V_2 -> V_13 - V_74 -> V_95 ;
F_6 ( L_13 ,
V_10 , V_4 -> V_8 , V_4 -> free ) ;
V_11:
F_60 ( V_74 ) ;
return V_7 ;
V_79:
F_50 ( L_14 , V_10 , V_76 -> V_31 ) ;
F_61 ( V_2 , V_76 -> V_83 ) ;
F_60 ( V_74 ) ;
return - V_64 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_7 ;
unsigned long long V_97 = 0 ;
F_12 (b, &c->replay_buds, list) {
V_7 = F_54 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
F_30 ( V_4 -> V_34 > V_97 ) ;
V_97 = V_4 -> V_34 ;
}
return 0 ;
}
static void F_63 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
while ( ! F_64 ( & V_2 -> F_62 ) ) {
V_4 = F_29 ( V_2 -> F_62 . V_69 , struct V_3 , V_46 ) ;
F_36 ( & V_4 -> V_46 ) ;
F_35 ( V_4 ) ;
}
}
static int F_65 ( struct V_1 * V_2 , int V_10 , int V_31 , int V_17 ,
unsigned long long V_34 )
{
struct V_66 * V_9 ;
struct V_3 * V_4 ;
F_6 ( L_15 , V_10 , V_31 , V_17 ) ;
V_9 = F_43 ( sizeof( struct V_66 ) , V_52 ) ;
if ( ! V_9 )
return - V_53 ;
V_4 = F_43 ( sizeof( struct V_3 ) , V_52 ) ;
if ( ! V_4 ) {
F_35 ( V_9 ) ;
return - V_53 ;
}
V_9 -> V_10 = V_10 ;
V_9 -> V_12 = V_31 ;
V_9 -> V_17 = V_17 ;
F_66 ( V_2 , V_9 ) ;
V_4 -> V_9 = V_9 ;
V_4 -> V_34 = V_34 ;
F_41 ( & V_4 -> V_46 , & V_2 -> F_62 ) ;
return 0 ;
}
static int F_67 ( struct V_1 * V_2 , const struct V_98 * V_99 )
{
struct V_66 * V_9 ;
int V_10 = F_47 ( V_99 -> V_10 ) ;
unsigned int V_31 = F_47 ( V_99 -> V_31 ) ;
unsigned int V_17 = F_47 ( V_99 -> V_17 ) ;
if ( V_17 >= V_2 -> V_100 || V_10 >= V_2 -> V_101 ||
V_10 < V_2 -> V_102 || V_31 > V_2 -> V_13 ||
V_31 & ( V_2 -> V_96 - 1 ) )
return - V_64 ;
V_9 = F_59 ( V_2 , V_10 ) ;
if ( V_9 ) {
if ( V_9 -> V_17 == V_17 && V_9 -> V_12 <= V_31 )
return 1 ;
F_50 ( L_16 , V_10 , V_31 ) ;
return - V_64 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 , int V_10 , int V_31 , void * V_77 )
{
int V_7 ;
struct V_73 * V_74 ;
struct V_75 * V_76 ;
const struct V_103 * V_83 ;
F_6 ( L_17 , V_10 , V_31 ) ;
V_74 = F_56 ( V_2 , V_10 , V_31 , V_77 , V_2 -> V_40 ) ;
if ( F_4 ( V_74 ) ) {
if ( F_5 ( V_74 ) != - V_104 || ! V_2 -> V_40 )
return F_5 ( V_74 ) ;
V_74 = F_69 ( V_2 , V_10 , V_31 , V_77 ) ;
if ( F_4 ( V_74 ) )
return F_5 ( V_74 ) ;
}
if ( V_74 -> V_105 == 0 ) {
V_7 = 1 ;
goto V_11;
}
V_83 = V_74 -> V_106 ;
V_76 = F_29 ( V_74 -> V_107 . V_69 , struct V_75 , V_46 ) ;
if ( V_2 -> V_108 == 0 ) {
if ( V_76 -> type != V_109 ) {
F_50 ( L_18 ,
V_10 , V_31 ) ;
goto V_79;
}
if ( F_49 ( V_83 -> V_110 ) != V_2 -> V_110 ) {
F_50 ( L_19 ,
V_10 , V_31 ,
( unsigned long long ) F_49 ( V_83 -> V_110 ) ,
V_2 -> V_110 ) ;
goto V_79;
}
V_2 -> V_108 = F_49 ( V_83 -> V_58 . V_34 ) ;
F_6 ( L_20 , V_2 -> V_108 ) ;
}
if ( V_76 -> V_34 < V_2 -> V_108 ) {
V_7 = 1 ;
goto V_11;
}
if ( V_76 -> V_31 != 0 ) {
F_50 ( L_21 ) ;
goto V_79;
}
F_12 (snod, &sleb->nodes, list) {
F_28 () ;
if ( V_76 -> V_34 >= V_78 ) {
F_50 ( L_10 ) ;
goto V_79;
}
if ( V_76 -> V_34 < V_2 -> V_108 ) {
F_50 ( L_22 ,
V_76 -> V_34 , V_2 -> V_108 ) ;
goto V_79;
}
if ( V_76 -> V_34 > V_2 -> V_80 )
V_2 -> V_80 = V_76 -> V_34 ;
switch ( V_76 -> type ) {
case V_111 : {
const struct V_98 * V_99 = V_76 -> V_83 ;
V_7 = F_67 ( V_2 , V_99 ) ;
if ( V_7 == 1 )
break;
if ( V_7 )
goto V_79;
V_7 = F_65 ( V_2 , F_47 ( V_99 -> V_10 ) ,
F_47 ( V_99 -> V_31 ) ,
F_47 ( V_99 -> V_17 ) ,
V_76 -> V_34 ) ;
if ( V_7 )
goto V_11;
break;
}
case V_109 :
if ( V_76 -> V_31 != 0 ) {
F_50 ( L_23 ) ;
goto V_79;
}
break;
default:
F_50 ( L_23 ) ;
goto V_79;
}
}
if ( V_74 -> V_95 || V_2 -> V_112 >= V_2 -> V_13 ) {
V_2 -> V_113 = V_10 ;
V_2 -> V_112 = V_74 -> V_95 ;
}
V_7 = ! V_74 -> V_95 ;
V_11:
F_60 ( V_74 ) ;
return V_7 ;
V_79:
F_50 ( L_24 ,
V_10 , V_31 + V_76 -> V_31 ) ;
F_61 ( V_2 , V_76 -> V_83 ) ;
F_60 ( V_74 ) ;
return - V_64 ;
}
static int F_70 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 ;
int V_7 , free ;
F_2 ( V_2 ) ;
V_6 = F_3 ( V_2 , V_2 -> V_114 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
free = V_6 -> free ;
V_6 = F_8 ( V_2 , V_6 , V_115 , V_115 ,
V_6 -> V_14 | V_15 , 0 ) ;
if ( F_4 ( V_6 ) ) {
V_7 = F_5 ( V_6 ) ;
goto V_11;
}
V_7 = free ;
V_11:
F_10 ( V_2 ) ;
return V_7 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_7 , V_10 , free ;
F_72 ( V_39 > 5 ) ;
free = F_70 ( V_2 ) ;
if ( free < 0 )
return free ;
if ( V_2 -> V_116 != V_2 -> V_13 - free ) {
F_50 ( L_25 , V_2 -> V_114 ,
V_2 -> V_116 ) ;
return - V_64 ;
}
F_6 ( L_26 ) ;
V_2 -> V_117 = 1 ;
V_10 = V_2 -> V_118 = V_2 -> V_113 ;
do {
V_7 = F_68 ( V_2 , V_10 , 0 , V_2 -> V_77 ) ;
if ( V_7 == 1 )
break;
if ( V_7 )
goto V_11;
V_10 = F_73 ( V_2 , V_10 ) ;
} while ( V_10 != V_2 -> V_118 );
V_7 = F_62 ( V_2 ) ;
if ( V_7 )
goto V_11;
V_7 = F_31 ( V_2 ) ;
if ( V_7 )
goto V_11;
V_7 = F_11 ( V_2 ) ;
if ( V_7 )
goto V_11;
V_2 -> V_119 . V_120 = F_74 ( & V_2 -> V_121 ) ;
V_2 -> V_119 . V_120 *= V_2 -> V_122 ;
F_30 ( V_2 -> V_123 <= V_2 -> V_124 || V_2 -> V_40 ) ;
F_6 ( L_27 ,
V_2 -> V_113 , V_2 -> V_112 , V_2 -> V_80 ,
( unsigned long ) V_2 -> V_51 ) ;
V_11:
F_33 ( V_2 ) ;
F_63 ( V_2 ) ;
V_2 -> V_117 = 0 ;
return V_7 ;
}
