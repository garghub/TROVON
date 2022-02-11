static inline void T_1 * F_1 ( T_2 V_1 )
{
return ( void T_1 * ) ( V_2 ) V_1 ;
}
static struct V_3 * F_2 ( struct V_4 * V_5 ,
struct V_6 * V_7 , int V_8 )
{
struct V_3 * V_9 ;
int V_10 = sizeof( * V_9 ) + ( V_8 * sizeof( V_9 -> V_11 [ 0 ] ) ) ;
V_9 = F_3 ( V_10 , V_12 | V_13 | V_14 ) ;
if ( V_9 ) {
V_9 -> V_5 = V_5 ;
V_9 -> V_7 = V_7 ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
F_4 ( & V_9 -> V_17 ) ;
F_5 ( & V_9 -> V_18 , & V_19 ) ;
}
return V_9 ;
}
static int F_6 ( struct V_3 * V_9 ,
struct V_20 * args , struct V_21 * V_22 )
{
unsigned V_23 ;
int V_24 = 0 ;
F_7 ( & V_22 -> V_25 ) ;
for ( V_23 = 0 ; V_23 < args -> V_15 ; V_23 ++ ) {
struct V_26 V_27 ;
struct V_28 * V_29 ;
struct V_30 * V_31 ;
void T_1 * V_32 =
F_1 ( args -> V_11 + ( V_23 * sizeof( V_27 ) ) ) ;
V_24 = F_8 ( & V_27 , V_32 , sizeof( V_27 ) ) ;
if ( V_24 ) {
V_24 = - V_33 ;
goto V_34;
}
if ( V_27 . V_35 & ~ V_36 ) {
F_9 ( L_1 , V_27 . V_35 ) ;
V_24 = - V_37 ;
goto V_34;
}
V_9 -> V_11 [ V_23 ] . V_35 = V_27 . V_35 ;
V_9 -> V_11 [ V_23 ] . V_38 = V_27 . V_39 ;
V_29 = F_10 ( & V_22 -> V_40 , V_27 . V_41 ) ;
if ( ! V_29 ) {
F_9 ( L_2 , V_27 . V_41 , V_23 ) ;
V_24 = - V_37 ;
goto V_34;
}
V_31 = F_11 ( V_29 ) ;
if ( ! F_12 ( & V_31 -> V_42 ) ) {
F_9 ( L_3 ,
V_27 . V_41 , V_23 ) ;
V_24 = - V_37 ;
goto V_34;
}
F_13 ( V_29 ) ;
V_9 -> V_11 [ V_23 ] . V_29 = V_31 ;
F_14 ( & V_31 -> V_42 , & V_9 -> V_17 ) ;
}
V_34:
V_9 -> V_15 = V_23 ;
F_15 ( & V_22 -> V_25 ) ;
return V_24 ;
}
static void F_16 ( struct V_3 * V_9 , int V_23 )
{
struct V_30 * V_31 = V_9 -> V_11 [ V_23 ] . V_29 ;
if ( V_9 -> V_11 [ V_23 ] . V_35 & V_43 )
F_17 ( & V_31 -> V_44 , V_9 -> V_7 -> V_45 ) ;
if ( V_9 -> V_11 [ V_23 ] . V_35 & V_46 )
F_18 ( & V_31 -> V_47 -> V_48 ) ;
if ( ! ( V_9 -> V_11 [ V_23 ] . V_35 & V_49 ) )
V_9 -> V_11 [ V_23 ] . V_38 = 0 ;
V_9 -> V_11 [ V_23 ] . V_35 &= ~ ( V_46 | V_43 ) ;
}
static int F_19 ( struct V_3 * V_9 )
{
int V_50 , V_51 = - 1 , V_23 , V_24 = 0 ;
V_52:
V_9 -> V_53 = true ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_30 * V_31 = V_9 -> V_11 [ V_23 ] . V_29 ;
T_3 V_38 ;
if ( V_51 == V_23 )
V_51 = - 1 ;
V_50 = V_23 ;
if ( ! ( V_9 -> V_11 [ V_23 ] . V_35 & V_46 ) ) {
V_24 = F_20 ( & V_31 -> V_47 -> V_48 ,
& V_9 -> V_18 ) ;
if ( V_24 )
goto V_54;
V_9 -> V_11 [ V_23 ] . V_35 |= V_46 ;
}
V_24 = F_21 ( & V_31 -> V_44 ,
V_9 -> V_7 -> V_45 , & V_38 ) ;
F_22 ( V_24 == - V_55 ) ;
if ( V_24 )
goto V_54;
V_9 -> V_11 [ V_23 ] . V_35 |= V_43 ;
if ( V_38 == V_9 -> V_11 [ V_23 ] . V_38 ) {
V_9 -> V_11 [ V_23 ] . V_35 |= V_49 ;
} else {
V_9 -> V_11 [ V_23 ] . V_38 = V_38 ;
V_9 -> V_11 [ V_23 ] . V_35 &= ~ V_49 ;
V_9 -> V_53 = false ;
}
}
F_23 ( & V_9 -> V_18 ) ;
return 0 ;
V_54:
for (; V_23 >= 0 ; V_23 -- )
F_16 ( V_9 , V_23 ) ;
if ( V_51 > 0 )
F_16 ( V_9 , V_51 ) ;
if ( V_24 == - V_55 ) {
struct V_30 * V_31 = V_9 -> V_11 [ V_50 ] . V_29 ;
V_24 = F_24 ( & V_31 -> V_47 -> V_48 ,
& V_9 -> V_18 ) ;
if ( ! V_24 ) {
V_9 -> V_11 [ V_50 ] . V_35 |= V_46 ;
V_51 = V_50 ;
goto V_52;
}
}
return V_24 ;
}
static int V_27 ( struct V_3 * V_9 , T_3 V_56 ,
struct V_30 * * V_29 , T_3 * V_38 , bool * V_53 )
{
if ( V_56 >= V_9 -> V_15 ) {
F_9 ( L_4 ,
V_56 , V_9 -> V_15 ) ;
return - V_37 ;
}
if ( V_29 )
* V_29 = V_9 -> V_11 [ V_56 ] . V_29 ;
if ( V_38 )
* V_38 = V_9 -> V_11 [ V_56 ] . V_38 ;
if ( V_53 )
* V_53 = ! ! ( V_9 -> V_11 [ V_56 ] . V_35 & V_49 ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_9 , struct V_30 * V_29 ,
T_3 V_57 , T_3 V_58 , T_4 V_59 )
{
T_3 V_23 , V_60 = 0 ;
T_3 * V_61 ;
int V_24 ;
if ( V_57 % 4 ) {
F_9 ( L_5 , V_57 ) ;
return - V_37 ;
}
V_61 = F_26 ( & V_29 -> V_44 ) ;
if ( F_27 ( V_61 ) ) {
V_24 = F_28 ( V_61 ) ;
F_29 ( L_6 , V_24 ) ;
return V_24 ;
}
for ( V_23 = 0 ; V_23 < V_58 ; V_23 ++ ) {
struct V_62 F_25 ;
void T_1 * V_32 =
F_1 ( V_59 + ( V_23 * sizeof( F_25 ) ) ) ;
T_3 V_38 , V_63 ;
bool V_53 ;
V_24 = F_8 ( & F_25 , V_32 , sizeof( F_25 ) ) ;
if ( V_24 )
return - V_33 ;
if ( F_25 . V_64 % 4 ) {
F_9 ( L_7 ,
F_25 . V_64 ) ;
return - V_37 ;
}
V_63 = F_25 . V_64 / 4 ;
if ( ( V_63 >= ( V_29 -> V_44 . V_65 / 4 ) ) ||
( V_63 < V_60 ) ) {
F_9 ( L_8 , V_63 , V_23 ) ;
return - V_37 ;
}
V_24 = V_27 ( V_9 , F_25 . V_66 , NULL , & V_38 , & V_53 ) ;
if ( V_24 )
return V_24 ;
if ( V_53 )
continue;
V_38 += F_25 . V_67 ;
if ( F_25 . V_68 < 0 )
V_38 >>= - F_25 . V_68 ;
else
V_38 <<= F_25 . V_68 ;
V_61 [ V_63 ] = V_38 | F_25 . V_69 ;
V_60 = V_63 ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_9 , bool V_54 )
{
unsigned V_23 ;
for ( V_23 = 0 ; V_23 < V_9 -> V_15 ; V_23 ++ ) {
struct V_30 * V_31 = V_9 -> V_11 [ V_23 ] . V_29 ;
F_16 ( V_9 , V_23 ) ;
F_31 ( & V_31 -> V_42 ) ;
F_32 ( & V_31 -> V_44 ) ;
}
F_33 ( & V_9 -> V_18 ) ;
F_34 ( V_9 ) ;
}
int F_35 ( struct V_4 * V_5 , void * V_70 ,
struct V_21 * V_22 )
{
struct V_71 * V_72 = V_5 -> V_73 ;
struct V_20 * args = V_70 ;
struct V_74 * V_75 = V_22 -> V_76 ;
struct V_3 * V_9 ;
struct V_6 * V_7 ;
unsigned V_23 ;
int V_24 ;
if ( args -> V_77 != V_78 )
return - V_37 ;
V_7 = V_72 -> V_7 ;
if ( args -> V_16 > V_79 )
return - V_37 ;
F_36 ( & V_5 -> V_80 ) ;
V_9 = F_2 ( V_5 , V_7 , args -> V_15 ) ;
if ( ! V_9 ) {
V_24 = - V_81 ;
goto V_82;
}
V_24 = F_6 ( V_9 , args , V_22 ) ;
if ( V_24 )
goto V_82;
V_24 = F_19 ( V_9 ) ;
if ( V_24 )
goto V_82;
for ( V_23 = 0 ; V_23 < args -> V_16 ; V_23 ++ ) {
struct V_83 V_84 ;
void T_1 * V_32 =
F_1 ( args -> V_85 + ( V_23 * sizeof( V_84 ) ) ) ;
struct V_30 * V_31 ;
T_3 V_38 ;
V_24 = F_8 ( & V_84 , V_32 , sizeof( V_84 ) ) ;
if ( V_24 ) {
V_24 = - V_33 ;
goto V_82;
}
switch ( V_84 . type ) {
case V_86 :
case V_87 :
case V_88 :
break;
default:
F_9 ( L_9 , V_84 . type ) ;
V_24 = - V_37 ;
goto V_82;
}
V_24 = V_27 ( V_9 , V_84 . V_89 ,
& V_31 , & V_38 , NULL ) ;
if ( V_24 )
goto V_82;
if ( V_84 . V_65 % 4 ) {
F_9 ( L_10 ,
V_84 . V_65 ) ;
V_24 = - V_37 ;
goto V_82;
}
if ( ( V_84 . V_65 + V_84 . V_64 ) >=
V_31 -> V_44 . V_65 ) {
F_9 ( L_11 , V_84 . V_65 ) ;
V_24 = - V_37 ;
goto V_82;
}
V_9 -> V_90 [ V_23 ] . type = V_84 . type ;
V_9 -> V_90 [ V_23 ] . V_65 = V_84 . V_65 / 4 ;
V_9 -> V_90 [ V_23 ] . V_38 = V_38 + V_84 . V_64 ;
if ( V_9 -> V_53 )
continue;
V_24 = F_25 ( V_9 , V_31 , V_84 . V_64 ,
V_84 . V_58 , V_84 . V_59 ) ;
if ( V_24 )
goto V_82;
}
V_9 -> V_16 = V_23 ;
V_24 = F_37 ( V_7 , V_9 , V_75 ) ;
args -> V_91 = V_9 -> V_91 ;
V_82:
if ( V_9 )
F_30 ( V_9 , ! ! V_24 ) ;
F_38 ( & V_5 -> V_80 ) ;
return V_24 ;
}
