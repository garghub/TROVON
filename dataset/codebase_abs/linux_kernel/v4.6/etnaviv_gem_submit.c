static inline void T_1 * F_1 ( T_2 V_1 )
{
return ( void T_1 * ) ( V_2 ) V_1 ;
}
static struct V_3 * F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 , T_3 V_8 )
{
struct V_3 * V_9 ;
T_3 V_10 = F_3 ( V_8 , sizeof( V_9 -> V_11 [ 0 ] ) , sizeof( * V_9 ) ) ;
V_9 = F_4 ( V_10 , V_12 | V_13 | V_14 ) ;
if ( V_9 ) {
V_9 -> V_5 = V_5 ;
V_9 -> V_7 = V_7 ;
V_9 -> V_15 = 0 ;
F_5 ( & V_9 -> V_16 , & V_17 ) ;
}
return V_9 ;
}
static int F_6 ( struct V_3 * V_9 ,
struct V_18 * V_19 , struct V_20 * V_21 ,
unsigned V_15 )
{
struct V_20 * V_22 ;
unsigned V_23 ;
int V_24 = 0 ;
F_7 ( & V_19 -> V_25 ) ;
for ( V_23 = 0 , V_22 = V_21 ; V_23 < V_15 ; V_23 ++ , V_22 ++ ) {
struct V_26 * V_27 ;
if ( V_22 -> V_28 & V_29 ) {
F_8 ( L_1 , V_22 -> V_28 ) ;
V_24 = - V_30 ;
goto V_31;
}
V_9 -> V_11 [ V_23 ] . V_28 = V_22 -> V_28 ;
V_27 = F_9 ( & V_19 -> V_32 , V_22 -> V_33 ) ;
if ( ! V_27 ) {
F_8 ( L_2 ,
V_22 -> V_33 , V_23 ) ;
V_24 = - V_30 ;
goto V_31;
}
F_10 ( V_27 ) ;
V_9 -> V_11 [ V_23 ] . V_27 = F_11 ( V_27 ) ;
}
V_31:
V_9 -> V_15 = V_23 ;
F_12 ( & V_19 -> V_25 ) ;
return V_24 ;
}
static void F_13 ( struct V_3 * V_9 , int V_23 )
{
if ( V_9 -> V_11 [ V_23 ] . V_28 & V_34 ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
F_14 ( & V_36 -> V_37 -> V_38 ) ;
V_9 -> V_11 [ V_23 ] . V_28 &= ~ V_34 ;
}
}
static int F_15 ( struct V_3 * V_9 )
{
int V_39 , V_40 = - 1 , V_23 , V_24 = 0 ;
V_41:
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
if ( V_40 == V_23 )
V_40 = - 1 ;
V_39 = V_23 ;
if ( ! ( V_9 -> V_11 [ V_23 ] . V_28 & V_34 ) ) {
V_24 = F_16 ( & V_36 -> V_37 -> V_38 ,
& V_9 -> V_16 ) ;
if ( V_24 == - V_42 )
F_8 ( L_3 ,
V_23 ) ;
if ( V_24 )
goto V_43;
V_9 -> V_11 [ V_23 ] . V_28 |= V_34 ;
}
}
F_17 ( & V_9 -> V_16 ) ;
return 0 ;
V_43:
for (; V_23 >= 0 ; V_23 -- )
F_13 ( V_9 , V_23 ) ;
if ( V_40 > 0 )
F_13 ( V_9 , V_40 ) ;
if ( V_24 == - V_44 ) {
struct V_35 * V_36 ;
V_36 = V_9 -> V_11 [ V_39 ] . V_27 ;
V_24 = F_18 ( & V_36 -> V_37 -> V_38 ,
& V_9 -> V_16 ) ;
if ( ! V_24 ) {
V_9 -> V_11 [ V_39 ] . V_28 |= V_34 ;
V_40 = V_39 ;
goto V_41;
}
}
return V_24 ;
}
static int F_19 ( const struct V_3 * V_9 )
{
unsigned int V_45 = V_9 -> V_7 -> V_46 ;
int V_23 , V_24 = 0 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
bool V_47 = V_9 -> V_11 [ V_23 ] . V_28 & V_48 ;
V_24 = F_20 ( V_36 , V_45 , V_47 ) ;
if ( V_24 )
break;
}
return V_24 ;
}
static void F_21 ( struct V_3 * V_9 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
if ( V_9 -> V_11 [ V_23 ] . V_28 & V_49 )
F_22 ( V_9 -> V_11 [ V_23 ] . V_50 ) ;
V_9 -> V_11 [ V_23 ] . V_50 = NULL ;
V_9 -> V_11 [ V_23 ] . V_28 &= ~ V_49 ;
}
}
static int F_23 ( struct V_3 * V_9 )
{
int V_23 , V_24 = 0 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
struct V_51 * V_50 ;
V_50 = F_24 ( & V_36 -> V_52 ,
V_9 -> V_7 ) ;
if ( F_25 ( V_50 ) ) {
V_24 = F_26 ( V_50 ) ;
break;
}
V_9 -> V_11 [ V_23 ] . V_28 |= V_49 ;
V_9 -> V_11 [ V_23 ] . V_50 = V_50 ;
}
return V_24 ;
}
static int F_27 ( struct V_3 * V_9 , T_4 V_53 ,
struct V_54 * * V_22 )
{
if ( V_53 >= V_9 -> V_15 ) {
F_8 ( L_4 ,
V_53 , V_9 -> V_15 ) ;
return - V_30 ;
}
* V_22 = & V_9 -> V_11 [ V_53 ] ;
return 0 ;
}
static int F_28 ( struct V_3 * V_9 , void * V_55 ,
T_4 V_56 , const struct V_57 * V_58 ,
T_4 V_59 )
{
T_4 V_23 , V_60 = 0 ;
T_4 * V_61 = V_55 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < V_59 ; V_23 ++ ) {
const struct V_57 * V_62 = V_58 + V_23 ;
struct V_54 * V_22 ;
T_4 V_63 ;
if ( F_29 ( V_62 -> V_28 ) ) {
F_8 ( L_5 ) ;
return - V_30 ;
}
if ( V_62 -> V_64 % 4 ) {
F_8 ( L_6 ,
V_62 -> V_64 ) ;
return - V_30 ;
}
V_63 = V_62 -> V_64 / 4 ;
if ( ( V_63 >= V_56 ) ||
( V_63 < V_60 ) ) {
F_8 ( L_7 , V_63 , V_23 ) ;
return - V_30 ;
}
V_24 = F_27 ( V_9 , V_62 -> V_65 , & V_22 ) ;
if ( V_24 )
return V_24 ;
if ( V_62 -> V_66 >= V_22 -> V_27 -> V_52 . V_56 - sizeof( * V_61 ) ) {
F_8 ( L_8 , V_23 ) ;
return - V_30 ;
}
V_61 [ V_63 ] = V_22 -> V_50 -> V_67 + V_62 -> V_66 ;
V_60 = V_63 ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_9 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
F_13 ( V_9 , V_23 ) ;
F_31 ( & V_36 -> V_52 ) ;
}
F_32 ( & V_9 -> V_16 ) ;
F_33 ( V_9 ) ;
}
int F_34 ( struct V_4 * V_5 , void * V_68 ,
struct V_18 * V_19 )
{
struct V_69 * V_70 = V_5 -> V_71 ;
struct V_72 * args = V_68 ;
struct V_57 * V_58 ;
struct V_20 * V_11 ;
struct V_3 * V_9 ;
struct V_73 * V_74 ;
struct V_6 * V_7 ;
void * V_55 ;
int V_24 ;
if ( args -> V_75 >= V_76 )
return - V_30 ;
V_7 = V_70 -> V_7 [ args -> V_75 ] ;
if ( ! V_7 )
return - V_77 ;
if ( args -> V_78 % 4 ) {
F_8 ( L_9 ,
args -> V_78 ) ;
return - V_30 ;
}
if ( args -> V_79 != V_80 &&
args -> V_79 != V_81 &&
args -> V_79 != V_82 ) {
F_8 ( L_10 , args -> V_79 ) ;
return - V_30 ;
}
V_11 = F_35 ( args -> V_15 , sizeof( * V_11 ) ) ;
V_58 = F_35 ( args -> V_59 , sizeof( * V_58 ) ) ;
V_55 = F_35 ( 1 , args -> V_78 ) ;
V_74 = F_36 ( V_7 , F_37 ( args -> V_78 , 8 ) + 8 ,
args -> V_15 ) ;
if ( ! V_11 || ! V_58 || ! V_55 || ! V_74 ) {
V_24 = - V_83 ;
goto V_84;
}
V_74 -> V_79 = args -> V_79 ;
V_74 -> V_85 = V_19 -> V_86 ;
V_24 = F_38 ( V_11 , F_1 ( args -> V_11 ) ,
args -> V_15 * sizeof( * V_11 ) ) ;
if ( V_24 ) {
V_24 = - V_87 ;
goto V_84;
}
V_24 = F_38 ( V_58 , F_1 ( args -> V_58 ) ,
args -> V_59 * sizeof( * V_58 ) ) ;
if ( V_24 ) {
V_24 = - V_87 ;
goto V_84;
}
V_24 = F_38 ( V_55 , F_1 ( args -> V_55 ) ,
args -> V_78 ) ;
if ( V_24 ) {
V_24 = - V_87 ;
goto V_84;
}
V_9 = F_2 ( V_5 , V_7 , args -> V_15 ) ;
if ( ! V_9 ) {
V_24 = - V_83 ;
goto V_84;
}
V_24 = F_6 ( V_9 , V_19 , V_11 , args -> V_15 ) ;
if ( V_24 )
goto V_88;
V_24 = F_15 ( V_9 ) ;
if ( V_24 )
goto V_88;
if ( ! F_39 ( V_7 , V_55 , args -> V_78 / 4 ,
V_58 , args -> V_59 ) ) {
V_24 = - V_30 ;
goto V_88;
}
V_24 = F_19 ( V_9 ) ;
if ( V_24 )
goto V_88;
V_24 = F_23 ( V_9 ) ;
if ( V_24 )
goto V_89;
V_24 = F_28 ( V_9 , V_55 , args -> V_78 / 4 ,
V_58 , args -> V_59 ) ;
if ( V_24 )
goto V_89;
memcpy ( V_74 -> V_90 , V_55 , args -> V_78 ) ;
V_74 -> V_91 = F_37 ( args -> V_78 , 8 ) ;
V_24 = F_40 ( V_7 , V_9 , V_74 ) ;
if ( V_24 == 0 )
V_74 = NULL ;
args -> V_92 = V_9 -> V_92 ;
V_89:
F_21 ( V_9 ) ;
if ( V_24 == - V_93 )
F_41 ( V_70 -> V_94 ) ;
V_88:
F_30 ( V_9 ) ;
V_84:
if ( V_74 )
F_42 ( V_74 ) ;
if ( V_55 )
F_43 ( V_55 ) ;
if ( V_11 )
F_43 ( V_11 ) ;
if ( V_58 )
F_43 ( V_58 ) ;
return V_24 ;
}
