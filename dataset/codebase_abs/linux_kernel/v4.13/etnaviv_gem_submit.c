static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , T_1 V_6 )
{
struct V_1 * V_7 ;
T_1 V_8 = F_2 ( V_6 , sizeof( V_7 -> V_9 [ 0 ] ) , sizeof( * V_7 ) ) ;
V_7 = F_3 ( V_8 , V_10 | V_11 | V_12 ) ;
if ( V_7 ) {
V_7 -> V_3 = V_3 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_13 = 0 ;
V_7 -> V_14 = NULL ;
F_4 ( & V_7 -> V_15 , & V_16 ) ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_7 ,
struct V_17 * V_18 , struct V_19 * V_20 ,
unsigned V_13 )
{
struct V_19 * V_21 ;
unsigned V_22 ;
int V_23 = 0 ;
F_6 ( & V_18 -> V_24 ) ;
for ( V_22 = 0 , V_21 = V_20 ; V_22 < V_13 ; V_22 ++ , V_21 ++ ) {
struct V_25 * V_26 ;
if ( V_21 -> V_27 & V_28 ) {
F_7 ( L_1 , V_21 -> V_27 ) ;
V_23 = - V_29 ;
goto V_30;
}
V_7 -> V_9 [ V_22 ] . V_27 = V_21 -> V_27 ;
V_26 = F_8 ( & V_18 -> V_31 , V_21 -> V_32 ) ;
if ( ! V_26 ) {
F_7 ( L_2 ,
V_21 -> V_32 , V_22 ) ;
V_23 = - V_29 ;
goto V_30;
}
F_9 ( V_26 ) ;
V_7 -> V_9 [ V_22 ] . V_26 = F_10 ( V_26 ) ;
}
V_30:
V_7 -> V_13 = V_22 ;
F_11 ( & V_18 -> V_24 ) ;
return V_23 ;
}
static void F_12 ( struct V_1 * V_7 , int V_22 )
{
if ( V_7 -> V_9 [ V_22 ] . V_27 & V_33 ) {
struct V_34 * V_35 = V_7 -> V_9 [ V_22 ] . V_26 ;
F_13 ( & V_35 -> V_36 -> V_37 ) ;
V_7 -> V_9 [ V_22 ] . V_27 &= ~ V_33 ;
}
}
static int F_14 ( struct V_1 * V_7 )
{
int V_38 , V_39 = - 1 , V_22 , V_23 = 0 ;
V_40:
for ( V_22 = 0 ; V_22 < V_7 -> V_13 ; V_22 ++ ) {
struct V_34 * V_35 = V_7 -> V_9 [ V_22 ] . V_26 ;
if ( V_39 == V_22 )
V_39 = - 1 ;
V_38 = V_22 ;
if ( ! ( V_7 -> V_9 [ V_22 ] . V_27 & V_33 ) ) {
V_23 = F_15 ( & V_35 -> V_36 -> V_37 ,
& V_7 -> V_15 ) ;
if ( V_23 == - V_41 )
F_7 ( L_3 ,
V_22 ) ;
if ( V_23 )
goto V_42;
V_7 -> V_9 [ V_22 ] . V_27 |= V_33 ;
}
}
F_16 ( & V_7 -> V_15 ) ;
return 0 ;
V_42:
for (; V_22 >= 0 ; V_22 -- )
F_12 ( V_7 , V_22 ) ;
if ( V_39 > 0 )
F_12 ( V_7 , V_39 ) ;
if ( V_23 == - V_43 ) {
struct V_34 * V_35 ;
V_35 = V_7 -> V_9 [ V_38 ] . V_26 ;
V_23 = F_17 ( & V_35 -> V_36 -> V_37 ,
& V_7 -> V_15 ) ;
if ( ! V_23 ) {
V_7 -> V_9 [ V_38 ] . V_27 |= V_33 ;
V_39 = V_38 ;
goto V_40;
}
}
return V_23 ;
}
static int F_18 ( const struct V_1 * V_7 )
{
unsigned int V_44 = V_7 -> V_5 -> V_45 ;
int V_22 , V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_7 -> V_13 ; V_22 ++ ) {
struct V_34 * V_35 = V_7 -> V_9 [ V_22 ] . V_26 ;
bool V_46 = V_7 -> V_9 [ V_22 ] . V_27 & V_47 ;
bool V_48 = ! ! ( V_7 -> V_27 & V_49 ) ;
V_23 = F_19 ( V_35 , V_44 , V_46 ,
V_48 ) ;
if ( V_23 )
break;
}
return V_23 ;
}
static void F_20 ( struct V_1 * V_7 )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_7 -> V_13 ; V_22 ++ ) {
if ( V_7 -> V_9 [ V_22 ] . V_27 & V_50 )
F_21 ( V_7 -> V_9 [ V_22 ] . V_51 ) ;
V_7 -> V_9 [ V_22 ] . V_51 = NULL ;
V_7 -> V_9 [ V_22 ] . V_27 &= ~ V_50 ;
}
}
static int F_22 ( struct V_1 * V_7 )
{
int V_22 , V_23 = 0 ;
for ( V_22 = 0 ; V_22 < V_7 -> V_13 ; V_22 ++ ) {
struct V_34 * V_35 = V_7 -> V_9 [ V_22 ] . V_26 ;
struct V_52 * V_51 ;
V_51 = F_23 ( & V_35 -> V_53 ,
V_7 -> V_5 ) ;
if ( F_24 ( V_51 ) ) {
V_23 = F_25 ( V_51 ) ;
break;
}
V_7 -> V_9 [ V_22 ] . V_27 |= V_50 ;
V_7 -> V_9 [ V_22 ] . V_51 = V_51 ;
}
return V_23 ;
}
static int F_26 ( struct V_1 * V_7 , T_2 V_54 ,
struct V_55 * * V_21 )
{
if ( V_54 >= V_7 -> V_13 ) {
F_7 ( L_4 ,
V_54 , V_7 -> V_13 ) ;
return - V_29 ;
}
* V_21 = & V_7 -> V_9 [ V_54 ] ;
return 0 ;
}
static int F_27 ( struct V_1 * V_7 , void * V_56 ,
T_2 V_57 , const struct V_58 * V_59 ,
T_2 V_60 )
{
T_2 V_22 , V_61 = 0 ;
T_2 * V_62 = V_56 ;
int V_23 ;
for ( V_22 = 0 ; V_22 < V_60 ; V_22 ++ ) {
const struct V_58 * V_63 = V_59 + V_22 ;
struct V_55 * V_21 ;
T_2 V_64 ;
if ( F_28 ( V_63 -> V_27 ) ) {
F_7 ( L_5 ) ;
return - V_29 ;
}
if ( V_63 -> V_65 % 4 ) {
F_7 ( L_6 ,
V_63 -> V_65 ) ;
return - V_29 ;
}
V_64 = V_63 -> V_65 / 4 ;
if ( ( V_64 >= V_57 ) ||
( V_64 < V_61 ) ) {
F_7 ( L_7 , V_64 , V_22 ) ;
return - V_29 ;
}
V_23 = F_26 ( V_7 , V_63 -> V_66 , & V_21 ) ;
if ( V_23 )
return V_23 ;
if ( V_63 -> V_67 > V_21 -> V_26 -> V_53 . V_57 - sizeof( * V_62 ) ) {
F_7 ( L_8 , V_22 ) ;
return - V_29 ;
}
V_62 [ V_64 ] = V_21 -> V_51 -> V_68 + V_63 -> V_67 ;
V_61 = V_64 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_7 )
{
unsigned V_22 ;
for ( V_22 = 0 ; V_22 < V_7 -> V_13 ; V_22 ++ ) {
struct V_34 * V_35 = V_7 -> V_9 [ V_22 ] . V_26 ;
F_12 ( V_7 , V_22 ) ;
F_30 ( & V_35 -> V_53 ) ;
}
F_31 ( & V_7 -> V_15 ) ;
if ( V_7 -> V_14 )
F_32 ( V_7 -> V_14 ) ;
F_33 ( V_7 ) ;
}
int F_34 ( struct V_2 * V_3 , void * V_69 ,
struct V_17 * V_18 )
{
struct V_70 * V_71 = V_3 -> V_72 ;
struct V_73 * args = V_69 ;
struct V_58 * V_59 ;
struct V_19 * V_9 ;
struct V_1 * V_7 ;
struct V_74 * V_75 ;
struct V_4 * V_5 ;
struct V_76 * V_77 = NULL ;
struct V_78 * V_78 = NULL ;
int V_79 = - 1 ;
void * V_56 ;
int V_23 ;
if ( args -> V_80 >= V_81 )
return - V_29 ;
V_5 = V_71 -> V_5 [ args -> V_80 ] ;
if ( ! V_5 )
return - V_82 ;
if ( args -> V_83 % 4 ) {
F_7 ( L_9 ,
args -> V_83 ) ;
return - V_29 ;
}
if ( args -> V_84 != V_85 &&
args -> V_84 != V_86 &&
args -> V_84 != V_87 ) {
F_7 ( L_10 , args -> V_84 ) ;
return - V_29 ;
}
if ( args -> V_27 & ~ V_88 ) {
F_7 ( L_11 , args -> V_27 ) ;
return - V_29 ;
}
V_9 = F_35 ( args -> V_13 , sizeof( * V_9 ) , V_89 ) ;
V_59 = F_35 ( args -> V_60 , sizeof( * V_59 ) , V_89 ) ;
V_56 = F_35 ( 1 , args -> V_83 , V_89 ) ;
V_75 = F_36 ( V_5 -> V_90 ,
F_37 ( args -> V_83 , 8 ) + 8 ,
args -> V_13 ) ;
if ( ! V_9 || ! V_59 || ! V_56 || ! V_75 ) {
V_23 = - V_91 ;
goto V_92;
}
V_75 -> V_84 = args -> V_84 ;
V_75 -> V_93 = V_18 -> V_94 ;
V_23 = F_38 ( V_9 , F_39 ( args -> V_9 ) ,
args -> V_13 * sizeof( * V_9 ) ) ;
if ( V_23 ) {
V_23 = - V_95 ;
goto V_92;
}
V_23 = F_38 ( V_59 , F_39 ( args -> V_59 ) ,
args -> V_60 * sizeof( * V_59 ) ) ;
if ( V_23 ) {
V_23 = - V_95 ;
goto V_92;
}
V_23 = F_38 ( V_56 , F_39 ( args -> V_56 ) ,
args -> V_83 ) ;
if ( V_23 ) {
V_23 = - V_95 ;
goto V_92;
}
if ( args -> V_27 & V_96 ) {
V_79 = F_40 ( V_97 ) ;
if ( V_79 < 0 ) {
V_23 = V_79 ;
goto V_92;
}
}
V_7 = F_1 ( V_3 , V_5 , args -> V_13 ) ;
if ( ! V_7 ) {
V_23 = - V_91 ;
goto V_92;
}
V_7 -> V_27 = args -> V_27 ;
V_23 = F_5 ( V_7 , V_18 , V_9 , args -> V_13 ) ;
if ( V_23 )
goto V_98;
V_23 = F_14 ( V_7 ) ;
if ( V_23 )
goto V_98;
if ( ! F_41 ( V_5 , V_56 , args -> V_83 / 4 ,
V_59 , args -> V_60 ) ) {
V_23 = - V_29 ;
goto V_98;
}
if ( args -> V_27 & V_99 ) {
V_77 = F_42 ( args -> V_100 ) ;
if ( ! V_77 ) {
V_23 = - V_29 ;
goto V_98;
}
if ( ! F_43 ( V_77 , V_5 -> V_45 ) ) {
V_23 = F_44 ( V_77 , true ) ;
if ( V_23 )
goto V_98;
}
}
V_23 = F_18 ( V_7 ) ;
if ( V_23 )
goto V_98;
V_23 = F_22 ( V_7 ) ;
if ( V_23 )
goto V_101;
V_23 = F_27 ( V_7 , V_56 , args -> V_83 / 4 ,
V_59 , args -> V_60 ) ;
if ( V_23 )
goto V_101;
memcpy ( V_75 -> V_102 , V_56 , args -> V_83 ) ;
V_75 -> V_103 = F_37 ( args -> V_83 , 8 ) ;
V_23 = F_45 ( V_5 , V_7 , V_75 ) ;
if ( V_23 == 0 )
V_75 = NULL ;
if ( args -> V_27 & V_96 ) {
V_78 = F_46 ( V_7 -> V_14 ) ;
if ( ! V_78 ) {
V_23 = - V_91 ;
goto V_101;
}
F_47 ( V_79 , V_78 -> V_18 ) ;
}
args -> V_100 = V_79 ;
args -> V_14 = V_7 -> V_14 -> V_104 ;
V_101:
F_20 ( V_7 ) ;
if ( V_23 == - V_105 )
F_48 ( V_71 -> V_106 ) ;
V_98:
if ( V_77 )
F_32 ( V_77 ) ;
F_29 ( V_7 ) ;
V_92:
if ( V_23 && ( V_79 >= 0 ) )
F_49 ( V_79 ) ;
if ( V_75 )
F_50 ( V_75 ) ;
if ( V_56 )
F_51 ( V_56 ) ;
if ( V_9 )
F_51 ( V_9 ) ;
if ( V_59 )
F_51 ( V_59 ) ;
return V_23 ;
}
