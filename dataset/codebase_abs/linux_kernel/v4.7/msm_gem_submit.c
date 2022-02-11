static struct V_1 * F_1 ( struct V_2 * V_3 ,
struct V_4 * V_5 , int V_6 )
{
struct V_1 * V_7 ;
int V_8 = sizeof( * V_7 ) + ( V_6 * sizeof( V_7 -> V_9 [ 0 ] ) ) ;
V_7 = F_2 ( V_8 , V_10 | V_11 | V_12 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_3 = V_3 ;
V_7 -> V_5 = V_5 ;
V_7 -> V_13 = NULL ;
V_7 -> V_14 = F_3 ( F_4 ( V_15 ) ) ;
V_7 -> V_16 = 0 ;
V_7 -> V_17 = 0 ;
F_5 ( & V_7 -> V_18 ) ;
F_5 ( & V_7 -> V_19 ) ;
F_6 ( & V_7 -> V_20 , & V_21 ) ;
return V_7 ;
}
void F_7 ( struct V_1 * V_7 )
{
F_8 ( V_7 -> V_13 ) ;
F_9 ( & V_7 -> V_18 ) ;
F_10 ( V_7 -> V_14 ) ;
F_11 ( V_7 ) ;
}
static int F_12 ( struct V_1 * V_7 ,
struct V_22 * args , struct V_23 * V_24 )
{
unsigned V_25 ;
int V_26 = 0 ;
F_13 ( & V_24 -> V_27 ) ;
for ( V_25 = 0 ; V_25 < args -> V_16 ; V_25 ++ ) {
struct V_28 V_29 ;
struct V_30 * V_31 ;
struct V_32 * V_33 ;
void T_1 * V_34 =
F_14 ( args -> V_9 + ( V_25 * sizeof( V_29 ) ) ) ;
V_7 -> V_9 [ V_25 ] . V_35 = 0 ;
V_26 = F_15 ( & V_29 , V_34 , sizeof( V_29 ) ) ;
if ( V_26 ) {
V_26 = - V_36 ;
goto V_37;
}
if ( V_29 . V_35 & ~ V_38 ) {
F_16 ( L_1 , V_29 . V_35 ) ;
V_26 = - V_39 ;
goto V_37;
}
V_7 -> V_9 [ V_25 ] . V_35 = V_29 . V_35 ;
V_7 -> V_9 [ V_25 ] . V_40 = V_29 . V_41 ;
V_31 = F_17 ( & V_24 -> V_42 , V_29 . V_43 ) ;
if ( ! V_31 ) {
F_16 ( L_2 , V_29 . V_43 , V_25 ) ;
V_26 = - V_39 ;
goto V_37;
}
V_33 = F_18 ( V_31 ) ;
if ( ! F_19 ( & V_33 -> V_44 ) ) {
F_16 ( L_3 ,
V_29 . V_43 , V_25 ) ;
V_26 = - V_39 ;
goto V_37;
}
F_20 ( V_31 ) ;
V_7 -> V_9 [ V_25 ] . V_31 = V_33 ;
F_21 ( & V_33 -> V_44 , & V_7 -> V_19 ) ;
}
V_37:
V_7 -> V_16 = V_25 ;
F_22 ( & V_24 -> V_27 ) ;
return V_26 ;
}
static void F_23 ( struct V_1 * V_7 , int V_25 )
{
struct V_32 * V_33 = V_7 -> V_9 [ V_25 ] . V_31 ;
if ( V_7 -> V_9 [ V_25 ] . V_35 & V_45 )
F_24 ( & V_33 -> V_46 , V_7 -> V_5 -> V_47 ) ;
if ( V_7 -> V_9 [ V_25 ] . V_35 & V_48 )
F_25 ( & V_33 -> V_49 -> V_50 ) ;
if ( ! ( V_7 -> V_9 [ V_25 ] . V_35 & V_51 ) )
V_7 -> V_9 [ V_25 ] . V_40 = 0 ;
V_7 -> V_9 [ V_25 ] . V_35 &= ~ ( V_48 | V_45 ) ;
}
static int F_26 ( struct V_1 * V_7 )
{
int V_52 , V_53 = - 1 , V_25 , V_26 = 0 ;
V_54:
for ( V_25 = 0 ; V_25 < V_7 -> V_16 ; V_25 ++ ) {
struct V_32 * V_33 = V_7 -> V_9 [ V_25 ] . V_31 ;
if ( V_53 == V_25 )
V_53 = - 1 ;
V_52 = V_25 ;
if ( ! ( V_7 -> V_9 [ V_25 ] . V_35 & V_48 ) ) {
V_26 = F_27 ( & V_33 -> V_49 -> V_50 ,
& V_7 -> V_20 ) ;
if ( V_26 )
goto V_55;
V_7 -> V_9 [ V_25 ] . V_35 |= V_48 ;
}
}
F_28 ( & V_7 -> V_20 ) ;
return 0 ;
V_55:
for (; V_25 >= 0 ; V_25 -- )
F_23 ( V_7 , V_25 ) ;
if ( V_53 > 0 )
F_23 ( V_7 , V_53 ) ;
if ( V_26 == - V_56 ) {
struct V_32 * V_33 = V_7 -> V_9 [ V_52 ] . V_31 ;
V_26 = F_29 ( & V_33 -> V_49 -> V_50 ,
& V_7 -> V_20 ) ;
if ( ! V_26 ) {
V_7 -> V_9 [ V_52 ] . V_35 |= V_48 ;
V_53 = V_52 ;
goto V_54;
}
}
return V_26 ;
}
static int F_30 ( struct V_1 * V_7 )
{
int V_25 , V_26 = 0 ;
for ( V_25 = 0 ; V_25 < V_7 -> V_16 ; V_25 ++ ) {
struct V_32 * V_33 = V_7 -> V_9 [ V_25 ] . V_31 ;
bool V_57 = V_7 -> V_9 [ V_25 ] . V_35 & V_58 ;
V_26 = F_31 ( & V_33 -> V_46 , V_7 -> V_5 -> V_59 , V_57 ) ;
if ( V_26 )
break;
}
return V_26 ;
}
static int F_32 ( struct V_1 * V_7 )
{
int V_25 , V_26 = 0 ;
V_7 -> V_60 = true ;
for ( V_25 = 0 ; V_25 < V_7 -> V_16 ; V_25 ++ ) {
struct V_32 * V_33 = V_7 -> V_9 [ V_25 ] . V_31 ;
T_2 V_40 ;
V_26 = F_33 ( & V_33 -> V_46 ,
V_7 -> V_5 -> V_47 , & V_40 ) ;
if ( V_26 )
break;
V_7 -> V_9 [ V_25 ] . V_35 |= V_45 ;
if ( V_40 == V_7 -> V_9 [ V_25 ] . V_40 ) {
V_7 -> V_9 [ V_25 ] . V_35 |= V_51 ;
} else {
V_7 -> V_9 [ V_25 ] . V_40 = V_40 ;
V_7 -> V_9 [ V_25 ] . V_35 &= ~ V_51 ;
V_7 -> V_60 = false ;
}
}
return V_26 ;
}
static int V_29 ( struct V_1 * V_7 , T_2 V_61 ,
struct V_32 * * V_31 , T_2 * V_40 , bool * V_60 )
{
if ( V_61 >= V_7 -> V_16 ) {
F_16 ( L_4 ,
V_61 , V_7 -> V_16 ) ;
return - V_39 ;
}
if ( V_31 )
* V_31 = V_7 -> V_9 [ V_61 ] . V_31 ;
if ( V_40 )
* V_40 = V_7 -> V_9 [ V_61 ] . V_40 ;
if ( V_60 )
* V_60 = ! ! ( V_7 -> V_9 [ V_61 ] . V_35 & V_51 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_7 , struct V_32 * V_31 ,
T_2 V_62 , T_2 V_63 , T_3 V_64 )
{
T_2 V_25 , V_65 = 0 ;
T_2 * V_66 ;
int V_26 ;
if ( V_62 % 4 ) {
F_16 ( L_5 , V_62 ) ;
return - V_39 ;
}
V_66 = F_35 ( & V_31 -> V_46 ) ;
if ( F_36 ( V_66 ) ) {
V_26 = F_37 ( V_66 ) ;
F_38 ( L_6 , V_26 ) ;
return V_26 ;
}
for ( V_25 = 0 ; V_25 < V_63 ; V_25 ++ ) {
struct V_67 F_34 ;
void T_1 * V_34 =
F_14 ( V_64 + ( V_25 * sizeof( F_34 ) ) ) ;
T_2 V_40 , V_68 ;
bool V_60 ;
V_26 = F_15 ( & F_34 , V_34 , sizeof( F_34 ) ) ;
if ( V_26 )
return - V_36 ;
if ( F_34 . V_69 % 4 ) {
F_16 ( L_7 ,
F_34 . V_69 ) ;
return - V_39 ;
}
V_68 = F_34 . V_69 / 4 ;
if ( ( V_68 >= ( V_31 -> V_46 . V_70 / 4 ) ) ||
( V_68 < V_65 ) ) {
F_16 ( L_8 , V_68 , V_25 ) ;
return - V_39 ;
}
V_26 = V_29 ( V_7 , F_34 . V_71 , NULL , & V_40 , & V_60 ) ;
if ( V_26 )
return V_26 ;
if ( V_60 )
continue;
V_40 += F_34 . V_72 ;
if ( F_34 . V_73 < 0 )
V_40 >>= - F_34 . V_73 ;
else
V_40 <<= F_34 . V_73 ;
V_66 [ V_68 ] = V_40 | F_34 . V_74 ;
V_65 = V_68 ;
}
return 0 ;
}
static void F_39 ( struct V_1 * V_7 )
{
unsigned V_25 ;
for ( V_25 = 0 ; V_25 < V_7 -> V_16 ; V_25 ++ ) {
struct V_32 * V_33 = V_7 -> V_9 [ V_25 ] . V_31 ;
F_23 ( V_7 , V_25 ) ;
F_40 ( & V_33 -> V_44 ) ;
F_41 ( & V_33 -> V_46 ) ;
}
F_42 ( & V_7 -> V_20 ) ;
}
int F_43 ( struct V_2 * V_3 , void * V_75 ,
struct V_23 * V_24 )
{
struct V_76 * V_77 = V_3 -> V_78 ;
struct V_22 * args = V_75 ;
struct V_79 * V_80 = V_24 -> V_81 ;
struct V_1 * V_7 ;
struct V_4 * V_5 = V_77 -> V_5 ;
unsigned V_25 ;
int V_26 ;
if ( ! V_5 )
return - V_82 ;
if ( args -> V_83 != V_84 )
return - V_39 ;
if ( args -> V_17 > V_85 )
return - V_39 ;
V_7 = F_1 ( V_3 , V_5 , args -> V_16 ) ;
if ( ! V_7 )
return - V_86 ;
F_44 ( & V_3 -> V_87 ) ;
V_26 = F_12 ( V_7 , args , V_24 ) ;
if ( V_26 )
goto V_88;
V_26 = F_26 ( V_7 ) ;
if ( V_26 )
goto V_88;
V_26 = F_30 ( V_7 ) ;
if ( V_26 )
goto V_88;
V_26 = F_32 ( V_7 ) ;
if ( V_26 )
goto V_88;
for ( V_25 = 0 ; V_25 < args -> V_17 ; V_25 ++ ) {
struct V_89 V_90 ;
void T_1 * V_34 =
F_14 ( args -> V_91 + ( V_25 * sizeof( V_90 ) ) ) ;
struct V_32 * V_33 ;
T_2 V_40 ;
V_26 = F_15 ( & V_90 , V_34 , sizeof( V_90 ) ) ;
if ( V_26 ) {
V_26 = - V_36 ;
goto V_88;
}
switch ( V_90 . type ) {
case V_92 :
case V_93 :
case V_94 :
break;
default:
F_16 ( L_9 , V_90 . type ) ;
V_26 = - V_39 ;
goto V_88;
}
V_26 = V_29 ( V_7 , V_90 . V_95 ,
& V_33 , & V_40 , NULL ) ;
if ( V_26 )
goto V_88;
if ( V_90 . V_70 % 4 ) {
F_16 ( L_10 ,
V_90 . V_70 ) ;
V_26 = - V_39 ;
goto V_88;
}
if ( ( V_90 . V_70 + V_90 . V_69 ) >=
V_33 -> V_46 . V_70 ) {
F_16 ( L_11 , V_90 . V_70 ) ;
V_26 = - V_39 ;
goto V_88;
}
V_7 -> V_96 [ V_25 ] . type = V_90 . type ;
V_7 -> V_96 [ V_25 ] . V_70 = V_90 . V_70 / 4 ;
V_7 -> V_96 [ V_25 ] . V_40 = V_40 + V_90 . V_69 ;
V_7 -> V_96 [ V_25 ] . V_61 = V_90 . V_95 ;
if ( V_7 -> V_60 )
continue;
V_26 = F_34 ( V_7 , V_33 , V_90 . V_69 ,
V_90 . V_63 , V_90 . V_64 ) ;
if ( V_26 )
goto V_88;
}
V_7 -> V_17 = V_25 ;
V_26 = F_45 ( V_5 , V_7 , V_80 ) ;
args -> V_13 = V_7 -> V_13 -> V_97 ;
V_88:
F_39 ( V_7 ) ;
if ( V_26 )
F_7 ( V_7 ) ;
F_46 ( & V_3 -> V_87 ) ;
return V_26 ;
}
