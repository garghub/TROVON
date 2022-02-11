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
F_4 ( & V_7 -> V_14 , & V_15 ) ;
}
return V_7 ;
}
static int F_5 ( struct V_1 * V_7 ,
struct V_16 * V_17 , struct V_18 * V_19 ,
unsigned V_13 )
{
struct V_18 * V_20 ;
unsigned V_21 ;
int V_22 = 0 ;
F_6 ( & V_17 -> V_23 ) ;
for ( V_21 = 0 , V_20 = V_19 ; V_21 < V_13 ; V_21 ++ , V_20 ++ ) {
struct V_24 * V_25 ;
if ( V_20 -> V_26 & V_27 ) {
F_7 ( L_1 , V_20 -> V_26 ) ;
V_22 = - V_28 ;
goto V_29;
}
V_7 -> V_9 [ V_21 ] . V_26 = V_20 -> V_26 ;
V_25 = F_8 ( & V_17 -> V_30 , V_20 -> V_31 ) ;
if ( ! V_25 ) {
F_7 ( L_2 ,
V_20 -> V_31 , V_21 ) ;
V_22 = - V_28 ;
goto V_29;
}
F_9 ( V_25 ) ;
V_7 -> V_9 [ V_21 ] . V_25 = F_10 ( V_25 ) ;
}
V_29:
V_7 -> V_13 = V_21 ;
F_11 ( & V_17 -> V_23 ) ;
return V_22 ;
}
static void F_12 ( struct V_1 * V_7 , int V_21 )
{
if ( V_7 -> V_9 [ V_21 ] . V_26 & V_32 ) {
struct V_33 * V_34 = V_7 -> V_9 [ V_21 ] . V_25 ;
F_13 ( & V_34 -> V_35 -> V_36 ) ;
V_7 -> V_9 [ V_21 ] . V_26 &= ~ V_32 ;
}
}
static int F_14 ( struct V_1 * V_7 )
{
int V_37 , V_38 = - 1 , V_21 , V_22 = 0 ;
V_39:
for ( V_21 = 0 ; V_21 < V_7 -> V_13 ; V_21 ++ ) {
struct V_33 * V_34 = V_7 -> V_9 [ V_21 ] . V_25 ;
if ( V_38 == V_21 )
V_38 = - 1 ;
V_37 = V_21 ;
if ( ! ( V_7 -> V_9 [ V_21 ] . V_26 & V_32 ) ) {
V_22 = F_15 ( & V_34 -> V_35 -> V_36 ,
& V_7 -> V_14 ) ;
if ( V_22 == - V_40 )
F_7 ( L_3 ,
V_21 ) ;
if ( V_22 )
goto V_41;
V_7 -> V_9 [ V_21 ] . V_26 |= V_32 ;
}
}
F_16 ( & V_7 -> V_14 ) ;
return 0 ;
V_41:
for (; V_21 >= 0 ; V_21 -- )
F_12 ( V_7 , V_21 ) ;
if ( V_38 > 0 )
F_12 ( V_7 , V_38 ) ;
if ( V_22 == - V_42 ) {
struct V_33 * V_34 ;
V_34 = V_7 -> V_9 [ V_37 ] . V_25 ;
V_22 = F_17 ( & V_34 -> V_35 -> V_36 ,
& V_7 -> V_14 ) ;
if ( ! V_22 ) {
V_7 -> V_9 [ V_37 ] . V_26 |= V_32 ;
V_38 = V_37 ;
goto V_39;
}
}
return V_22 ;
}
static int F_18 ( const struct V_1 * V_7 )
{
unsigned int V_43 = V_7 -> V_5 -> V_44 ;
int V_21 , V_22 = 0 ;
for ( V_21 = 0 ; V_21 < V_7 -> V_13 ; V_21 ++ ) {
struct V_33 * V_34 = V_7 -> V_9 [ V_21 ] . V_25 ;
bool V_45 = V_7 -> V_9 [ V_21 ] . V_26 & V_46 ;
V_22 = F_19 ( V_34 , V_43 , V_45 ) ;
if ( V_22 )
break;
}
return V_22 ;
}
static void F_20 ( struct V_1 * V_7 )
{
int V_21 ;
for ( V_21 = 0 ; V_21 < V_7 -> V_13 ; V_21 ++ ) {
if ( V_7 -> V_9 [ V_21 ] . V_26 & V_47 )
F_21 ( V_7 -> V_9 [ V_21 ] . V_48 ) ;
V_7 -> V_9 [ V_21 ] . V_48 = NULL ;
V_7 -> V_9 [ V_21 ] . V_26 &= ~ V_47 ;
}
}
static int F_22 ( struct V_1 * V_7 )
{
int V_21 , V_22 = 0 ;
for ( V_21 = 0 ; V_21 < V_7 -> V_13 ; V_21 ++ ) {
struct V_33 * V_34 = V_7 -> V_9 [ V_21 ] . V_25 ;
struct V_49 * V_48 ;
V_48 = F_23 ( & V_34 -> V_50 ,
V_7 -> V_5 ) ;
if ( F_24 ( V_48 ) ) {
V_22 = F_25 ( V_48 ) ;
break;
}
V_7 -> V_9 [ V_21 ] . V_26 |= V_47 ;
V_7 -> V_9 [ V_21 ] . V_48 = V_48 ;
}
return V_22 ;
}
static int F_26 ( struct V_1 * V_7 , T_2 V_51 ,
struct V_52 * * V_20 )
{
if ( V_51 >= V_7 -> V_13 ) {
F_7 ( L_4 ,
V_51 , V_7 -> V_13 ) ;
return - V_28 ;
}
* V_20 = & V_7 -> V_9 [ V_51 ] ;
return 0 ;
}
static int F_27 ( struct V_1 * V_7 , void * V_53 ,
T_2 V_54 , const struct V_55 * V_56 ,
T_2 V_57 )
{
T_2 V_21 , V_58 = 0 ;
T_2 * V_59 = V_53 ;
int V_22 ;
for ( V_21 = 0 ; V_21 < V_57 ; V_21 ++ ) {
const struct V_55 * V_60 = V_56 + V_21 ;
struct V_52 * V_20 ;
T_2 V_61 ;
if ( F_28 ( V_60 -> V_26 ) ) {
F_7 ( L_5 ) ;
return - V_28 ;
}
if ( V_60 -> V_62 % 4 ) {
F_7 ( L_6 ,
V_60 -> V_62 ) ;
return - V_28 ;
}
V_61 = V_60 -> V_62 / 4 ;
if ( ( V_61 >= V_54 ) ||
( V_61 < V_58 ) ) {
F_7 ( L_7 , V_61 , V_21 ) ;
return - V_28 ;
}
V_22 = F_26 ( V_7 , V_60 -> V_63 , & V_20 ) ;
if ( V_22 )
return V_22 ;
if ( V_60 -> V_64 >= V_20 -> V_25 -> V_50 . V_54 - sizeof( * V_59 ) ) {
F_7 ( L_8 , V_21 ) ;
return - V_28 ;
}
V_59 [ V_61 ] = V_20 -> V_48 -> V_65 + V_60 -> V_64 ;
V_58 = V_61 ;
}
return 0 ;
}
static void F_29 ( struct V_1 * V_7 )
{
unsigned V_21 ;
for ( V_21 = 0 ; V_21 < V_7 -> V_13 ; V_21 ++ ) {
struct V_33 * V_34 = V_7 -> V_9 [ V_21 ] . V_25 ;
F_12 ( V_7 , V_21 ) ;
F_30 ( & V_34 -> V_50 ) ;
}
F_31 ( & V_7 -> V_14 ) ;
F_32 ( V_7 ) ;
}
int F_33 ( struct V_2 * V_3 , void * V_66 ,
struct V_16 * V_17 )
{
struct V_67 * V_68 = V_3 -> V_69 ;
struct V_70 * args = V_66 ;
struct V_55 * V_56 ;
struct V_18 * V_9 ;
struct V_1 * V_7 ;
struct V_71 * V_72 ;
struct V_4 * V_5 ;
void * V_53 ;
int V_22 ;
if ( args -> V_73 >= V_74 )
return - V_28 ;
V_5 = V_68 -> V_5 [ args -> V_73 ] ;
if ( ! V_5 )
return - V_75 ;
if ( args -> V_76 % 4 ) {
F_7 ( L_9 ,
args -> V_76 ) ;
return - V_28 ;
}
if ( args -> V_77 != V_78 &&
args -> V_77 != V_79 &&
args -> V_77 != V_80 ) {
F_7 ( L_10 , args -> V_77 ) ;
return - V_28 ;
}
V_9 = F_34 ( args -> V_13 , sizeof( * V_9 ) ) ;
V_56 = F_34 ( args -> V_57 , sizeof( * V_56 ) ) ;
V_53 = F_34 ( 1 , args -> V_76 ) ;
V_72 = F_35 ( V_5 -> V_81 ,
F_36 ( args -> V_76 , 8 ) + 8 ,
args -> V_13 ) ;
if ( ! V_9 || ! V_56 || ! V_53 || ! V_72 ) {
V_22 = - V_82 ;
goto V_83;
}
V_72 -> V_77 = args -> V_77 ;
V_72 -> V_84 = V_17 -> V_85 ;
V_22 = F_37 ( V_9 , F_38 ( args -> V_9 ) ,
args -> V_13 * sizeof( * V_9 ) ) ;
if ( V_22 ) {
V_22 = - V_86 ;
goto V_83;
}
V_22 = F_37 ( V_56 , F_38 ( args -> V_56 ) ,
args -> V_57 * sizeof( * V_56 ) ) ;
if ( V_22 ) {
V_22 = - V_86 ;
goto V_83;
}
V_22 = F_37 ( V_53 , F_38 ( args -> V_53 ) ,
args -> V_76 ) ;
if ( V_22 ) {
V_22 = - V_86 ;
goto V_83;
}
V_7 = F_1 ( V_3 , V_5 , args -> V_13 ) ;
if ( ! V_7 ) {
V_22 = - V_82 ;
goto V_83;
}
V_22 = F_5 ( V_7 , V_17 , V_9 , args -> V_13 ) ;
if ( V_22 )
goto V_87;
V_22 = F_14 ( V_7 ) ;
if ( V_22 )
goto V_87;
if ( ! F_39 ( V_5 , V_53 , args -> V_76 / 4 ,
V_56 , args -> V_57 ) ) {
V_22 = - V_28 ;
goto V_87;
}
V_22 = F_18 ( V_7 ) ;
if ( V_22 )
goto V_87;
V_22 = F_22 ( V_7 ) ;
if ( V_22 )
goto V_88;
V_22 = F_27 ( V_7 , V_53 , args -> V_76 / 4 ,
V_56 , args -> V_57 ) ;
if ( V_22 )
goto V_88;
memcpy ( V_72 -> V_89 , V_53 , args -> V_76 ) ;
V_72 -> V_90 = F_36 ( args -> V_76 , 8 ) ;
V_22 = F_40 ( V_5 , V_7 , V_72 ) ;
if ( V_22 == 0 )
V_72 = NULL ;
args -> V_91 = V_7 -> V_91 ;
V_88:
F_20 ( V_7 ) ;
if ( V_22 == - V_92 )
F_41 ( V_68 -> V_93 ) ;
V_87:
F_29 ( V_7 ) ;
V_83:
if ( V_72 )
F_42 ( V_72 ) ;
if ( V_53 )
F_43 ( V_53 ) ;
if ( V_9 )
F_43 ( V_9 ) ;
if ( V_56 )
F_43 ( V_56 ) ;
return V_22 ;
}
