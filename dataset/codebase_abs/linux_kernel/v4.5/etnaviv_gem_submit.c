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
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
if ( V_9 -> V_11 [ V_23 ] . V_28 & V_49 )
F_22 ( V_9 -> V_7 , & V_36 -> V_50 ) ;
V_9 -> V_11 [ V_23 ] . V_51 = 0 ;
V_9 -> V_11 [ V_23 ] . V_28 &= ~ V_49 ;
}
}
static int F_23 ( struct V_3 * V_9 )
{
int V_23 , V_24 = 0 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
T_4 V_51 ;
V_24 = F_24 ( V_9 -> V_7 , & V_36 -> V_50 ,
& V_51 ) ;
if ( V_24 )
break;
V_9 -> V_11 [ V_23 ] . V_28 |= V_49 ;
V_9 -> V_11 [ V_23 ] . V_51 = V_51 ;
}
return V_24 ;
}
static int F_25 ( struct V_3 * V_9 , T_4 V_52 ,
struct V_35 * * V_27 , T_4 * V_51 )
{
if ( V_52 >= V_9 -> V_15 ) {
F_8 ( L_4 ,
V_52 , V_9 -> V_15 ) ;
return - V_30 ;
}
if ( V_27 )
* V_27 = V_9 -> V_11 [ V_52 ] . V_27 ;
if ( V_51 )
* V_51 = V_9 -> V_11 [ V_52 ] . V_51 ;
return 0 ;
}
static int F_26 ( struct V_3 * V_9 , void * V_53 ,
T_4 V_54 , const struct V_55 * V_56 ,
T_4 V_57 )
{
T_4 V_23 , V_58 = 0 ;
T_4 * V_59 = V_53 ;
int V_24 ;
for ( V_23 = 0 ; V_23 < V_57 ; V_23 ++ ) {
const struct V_55 * V_60 = V_56 + V_23 ;
struct V_35 * V_61 ;
T_4 V_51 , V_62 ;
if ( F_27 ( V_60 -> V_28 ) ) {
F_8 ( L_5 ) ;
return - V_30 ;
}
if ( V_60 -> V_63 % 4 ) {
F_8 ( L_6 ,
V_60 -> V_63 ) ;
return - V_30 ;
}
V_62 = V_60 -> V_63 / 4 ;
if ( ( V_62 >= V_54 ) ||
( V_62 < V_58 ) ) {
F_8 ( L_7 , V_62 , V_23 ) ;
return - V_30 ;
}
V_24 = F_25 ( V_9 , V_60 -> V_64 , & V_61 , & V_51 ) ;
if ( V_24 )
return V_24 ;
if ( V_60 -> V_65 >=
V_61 -> V_50 . V_54 - sizeof( * V_59 ) ) {
F_8 ( L_8 , V_23 ) ;
return - V_30 ;
}
V_59 [ V_62 ] = V_51 + V_60 -> V_65 ;
V_58 = V_62 ;
}
return 0 ;
}
static void F_28 ( struct V_3 * V_9 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_35 * V_36 = V_9 -> V_11 [ V_23 ] . V_27 ;
F_13 ( V_9 , V_23 ) ;
F_29 ( & V_36 -> V_50 ) ;
}
F_30 ( & V_9 -> V_16 ) ;
F_31 ( V_9 ) ;
}
int F_32 ( struct V_4 * V_5 , void * V_66 ,
struct V_18 * V_19 )
{
struct V_67 * V_68 = V_5 -> V_69 ;
struct V_70 * args = V_66 ;
struct V_55 * V_56 ;
struct V_20 * V_11 ;
struct V_3 * V_9 ;
struct V_71 * V_72 ;
struct V_6 * V_7 ;
void * V_53 ;
int V_24 ;
if ( args -> V_73 >= V_74 )
return - V_30 ;
V_7 = V_68 -> V_7 [ args -> V_73 ] ;
if ( ! V_7 )
return - V_75 ;
if ( args -> V_76 % 4 ) {
F_8 ( L_9 ,
args -> V_76 ) ;
return - V_30 ;
}
if ( args -> V_77 != V_78 &&
args -> V_77 != V_79 &&
args -> V_77 != V_80 ) {
F_8 ( L_10 , args -> V_77 ) ;
return - V_30 ;
}
V_11 = F_33 ( args -> V_15 , sizeof( * V_11 ) ) ;
V_56 = F_33 ( args -> V_57 , sizeof( * V_56 ) ) ;
V_53 = F_33 ( 1 , args -> V_76 ) ;
V_72 = F_34 ( V_7 , F_35 ( args -> V_76 , 8 ) + 8 ,
args -> V_15 ) ;
if ( ! V_11 || ! V_56 || ! V_53 || ! V_72 ) {
V_24 = - V_81 ;
goto V_82;
}
V_72 -> V_77 = args -> V_77 ;
V_72 -> V_83 = V_19 -> V_84 ;
V_24 = F_36 ( V_11 , F_1 ( args -> V_11 ) ,
args -> V_15 * sizeof( * V_11 ) ) ;
if ( V_24 ) {
V_24 = - V_85 ;
goto V_82;
}
V_24 = F_36 ( V_56 , F_1 ( args -> V_56 ) ,
args -> V_57 * sizeof( * V_56 ) ) ;
if ( V_24 ) {
V_24 = - V_85 ;
goto V_82;
}
V_24 = F_36 ( V_53 , F_1 ( args -> V_53 ) ,
args -> V_76 ) ;
if ( V_24 ) {
V_24 = - V_85 ;
goto V_82;
}
V_9 = F_2 ( V_5 , V_7 , args -> V_15 ) ;
if ( ! V_9 ) {
V_24 = - V_81 ;
goto V_82;
}
V_24 = F_6 ( V_9 , V_19 , V_11 , args -> V_15 ) ;
if ( V_24 )
goto V_86;
V_24 = F_15 ( V_9 ) ;
if ( V_24 )
goto V_86;
if ( ! F_37 ( V_7 , V_53 , args -> V_76 / 4 ,
V_56 , args -> V_57 ) ) {
V_24 = - V_30 ;
goto V_86;
}
V_24 = F_19 ( V_9 ) ;
if ( V_24 )
goto V_86;
V_24 = F_23 ( V_9 ) ;
if ( V_24 )
goto V_87;
V_24 = F_26 ( V_9 , V_53 , args -> V_76 / 4 ,
V_56 , args -> V_57 ) ;
if ( V_24 )
goto V_87;
memcpy ( V_72 -> V_88 , V_53 , args -> V_76 ) ;
V_72 -> V_89 = F_35 ( args -> V_76 , 8 ) ;
V_24 = F_38 ( V_7 , V_9 , V_72 ) ;
if ( V_24 == 0 )
V_72 = NULL ;
args -> V_90 = V_9 -> V_90 ;
V_87:
F_21 ( V_9 ) ;
if ( V_24 == - V_91 )
F_39 ( V_68 -> V_92 ) ;
V_86:
F_28 ( V_9 ) ;
V_82:
if ( V_72 )
F_40 ( V_72 ) ;
if ( V_53 )
F_41 ( V_53 ) ;
if ( V_11 )
F_41 ( V_11 ) ;
if ( V_56 )
F_41 ( V_56 ) ;
return V_24 ;
}
