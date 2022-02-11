static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static inline void F_5 ( void T_1 * V_1 , T_3 V_2 , T_3 V_3 )
{
F_6 ( V_3 , V_1 + V_2 ) ;
}
static inline T_3 F_7 ( void T_1 * V_1 , T_3 V_2 )
{
return F_8 ( V_1 + V_2 ) ;
}
static const int F_9 ( const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_10 ( V_6 ) ; V_5 ++ ) {
if ( ! strcmp ( V_4 , V_6 [ V_5 ] ) )
return V_5 ;
}
return - V_7 ;
}
static struct V_8 * F_11 ( const char * V_9 ,
struct V_10 * V_11 , int V_12 , void * V_13 ,
T_4 V_14 , struct V_15 * V_16 )
{
struct V_8 * V_17 ;
int V_18 ;
V_17 = F_12 ( V_9 , 0 ) ;
if ( ! V_17 ) {
F_13 ( V_16 , L_1 , V_9 ) ;
goto V_19;
}
V_18 = F_14 ( V_17 , V_11 , V_12 ) ;
if ( V_18 ) {
F_13 ( V_16 , L_2 ) ;
goto V_20;
}
V_18 = F_15 ( V_17 , V_13 , V_14 ) ;
if ( V_18 ) {
F_13 ( V_16 , L_3 ) ;
goto V_20;
}
V_17 -> V_16 . V_21 = & V_22 ;
F_16 ( & V_17 -> V_16 , F_17 ( 32 ) ) ;
V_17 -> V_16 . V_23 = V_16 ;
V_18 = F_18 ( V_17 ) ;
if ( V_18 ) {
F_13 ( V_16 , L_4 ) ;
goto V_20;
}
return V_17 ;
V_20:
F_19 ( V_17 ) ;
V_19:
return NULL ;
}
static int F_20 ( struct V_8 * V_24 )
{
struct V_15 * V_16 = & V_24 -> V_16 ;
struct V_25 * V_13 = V_16 -> V_26 ;
struct V_8 * V_27 ;
struct V_8 * V_28 ;
struct V_10 * V_11 ;
struct V_10 V_29 [ 2 ] ;
int V_18 ;
V_11 = F_21 ( V_24 , V_30 , L_5 ) ;
if ( ! V_11 ) {
F_13 ( V_16 , L_6 ) ;
V_18 = - V_7 ;
goto V_19;
}
V_29 [ 0 ] = * V_11 ;
V_11 = F_21 ( V_24 , V_31 , L_7 ) ;
if ( ! V_11 ) {
F_13 ( V_16 , L_8 ) ;
V_18 = - V_7 ;
goto V_19;
}
V_29 [ 1 ] = * V_11 ;
V_27 = F_11 ( V_32 , V_29 , 2 , V_13 ,
sizeof( * V_13 ) , V_16 ) ;
if ( ! V_27 ) {
F_13 ( V_16 , L_9 ) ;
V_18 = - V_33 ;
goto V_19;
}
V_11 = F_21 ( V_24 , V_30 , L_10 ) ;
if ( ! V_11 ) {
F_13 ( V_16 , L_11 ) ;
V_18 = - V_7 ;
goto V_34;
}
V_29 [ 0 ] = * V_11 ;
V_11 = F_21 ( V_24 , V_31 , L_12 ) ;
if ( ! V_11 ) {
F_13 ( V_16 , L_13 ) ;
V_18 = - V_7 ;
goto V_34;
}
V_29 [ 1 ] = * V_11 ;
V_28 = F_11 ( V_35 , V_29 , 2 , V_13 ,
sizeof( * V_13 ) , V_16 ) ;
if ( ! V_28 ) {
F_13 ( V_16 , L_9 ) ;
V_18 = - V_33 ;
goto V_34;
}
return 0 ;
V_34:
F_22 ( V_27 ) ;
V_19:
return V_18 ;
}
static bool F_23 ( enum V_36 V_37 )
{
switch ( V_37 ) {
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
return true ;
default:
return false ;
}
}
static int F_24 ( struct V_15 * V_16 )
{
struct V_48 * V_49 = F_25 ( V_16 ) ;
struct V_25 * V_13 = V_49 -> V_13 ;
int V_5 , V_50 ;
F_26 ( V_16 , L_14 ) ;
F_27 ( V_13 ) ;
if ( ! F_28 ( V_49 -> V_51 ) )
F_29 ( V_49 -> V_51 ) ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
switch ( V_13 -> V_53 [ V_5 ] ) {
case V_54 :
if ( ! F_28 ( V_49 -> V_55 [ V_5 ] ) ) {
V_50 = F_29 ( V_49 -> V_55 [ V_5 ] ) ;
if ( V_50 ) {
F_13 ( V_16 ,
L_15 ,
V_5 , V_50 ) ;
}
}
if ( ! F_28 ( V_49 -> V_56 [ V_5 ] ) ) {
V_50 = F_29 ( V_49 -> V_56 [ V_5 ] ) ;
if ( V_50 ) {
F_13 ( V_16 ,
L_16 ,
V_5 , V_50 ) ;
}
}
case V_57 :
if ( ! F_28 ( V_49 -> V_58 [ V_5 ] ) ) {
V_50 = F_29 ( V_49 -> V_58 [ V_5 ] ) ;
if ( V_50 ) {
F_13 ( V_16 ,
L_17 ,
V_5 , V_50 ) ;
}
}
break;
default:
break;
}
}
return 0 ;
}
static int F_30 ( struct V_15 * V_16 )
{
struct V_48 * V_49 = F_25 ( V_16 ) ;
struct V_25 * V_13 = V_49 -> V_13 ;
int V_5 ;
F_26 ( V_16 , L_18 ) ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
switch ( V_13 -> V_53 [ V_5 ] ) {
case V_54 :
if ( ! F_28 ( V_49 -> V_55 [ V_5 ] ) )
F_31 ( V_49 -> V_55 [ V_5 ] ) ;
if ( ! F_28 ( V_49 -> V_56 [ V_5 ] ) )
F_31 ( V_49 -> V_56 [ V_5 ] ) ;
case V_57 :
if ( ! F_28 ( V_49 -> V_58 [ V_5 ] ) )
F_31 ( V_49 -> V_58 [ V_5 ] ) ;
break;
default:
break;
}
}
if ( ! F_28 ( V_49 -> V_51 ) )
F_31 ( V_49 -> V_51 ) ;
F_32 ( V_13 ) ;
return 0 ;
}
static unsigned F_33 ( struct V_48 * V_49 ,
unsigned V_2 )
{
struct V_25 * V_13 = V_49 -> V_13 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
switch ( V_13 -> V_53 [ V_5 ] ) {
case V_59 :
V_2 &= ~ ( V_60 << V_5 ) ;
break;
case V_61 :
if ( V_13 -> V_62 )
break;
if ( V_5 == 0 )
V_2 &= ~ V_63 ;
else
V_2 &= ~ ( V_64
<< ( V_5 - 1 ) ) ;
break;
default:
if ( V_13 -> V_62 )
break;
if ( V_5 == 0 )
V_2 |= V_63 ;
else
V_2 |= V_64
<< ( V_5 - 1 ) ;
break;
}
}
if ( V_13 -> V_62 ) {
V_2 |= V_65 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
if ( F_34 ( V_13 -> V_53 [ V_5 ] ) ) {
V_2 &= V_65 ;
break;
}
}
}
return V_2 ;
}
static unsigned F_35 ( struct V_48 * V_49 ,
unsigned V_2 )
{
struct V_25 * V_13 = V_49 -> V_13 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
V_2 &= ~ ( V_66 << 2 * V_5 ) ;
if ( F_36 ( V_13 -> V_53 [ V_5 ] ) ||
( F_23 ( V_13 -> V_53 [ V_5 ] ) ) )
V_2 |= V_67 << 2 * V_5 ;
else if ( F_37 ( V_13 -> V_53 [ V_5 ] ) )
V_2 |= V_68 << 2 * V_5 ;
}
return V_2 ;
}
static void F_38 ( struct V_15 * V_16 )
{
struct V_48 * V_49 = F_25 ( V_16 ) ;
unsigned V_2 ;
F_26 ( V_16 , L_19 ) ;
F_39 ( V_16 ) ;
V_2 = F_3 ( V_49 -> V_69 , V_70 ) ;
V_2 |= ( V_71
| V_72
| V_73 ) ;
V_2 |= V_74 ;
V_2 &= ~ V_75 ;
switch ( V_49 -> V_76 ) {
case V_77 :
V_2 = F_33 ( V_49 , V_2 ) ;
break;
case V_78 :
V_2 = F_35 ( V_49 , V_2 ) ;
break;
default:
V_2 = F_35 ( V_49 , V_2 ) ;
break;
}
F_1 ( V_49 -> V_69 , V_70 , V_2 ) ;
F_26 ( V_16 , L_20 , V_2 ) ;
F_40 ( V_16 ) ;
}
static int F_41 ( struct V_15 * V_16 ,
struct V_25 * V_13 )
{
int V_18 , V_5 ;
struct V_79 * V_80 = V_16 -> V_81 ;
V_18 = F_42 ( V_80 , L_21 , & V_13 -> V_52 ) ;
if ( V_18 )
V_13 -> V_52 = 0 ;
if ( V_13 -> V_52 > V_82 ) {
F_43 ( V_16 , L_22 ,
V_13 -> V_52 , V_82 ) ;
return - V_7 ;
}
for ( V_5 = 0 ; V_5 < V_82 ; V_5 ++ ) {
char V_83 [ 11 ] ;
const char * V_4 ;
V_13 -> V_53 [ V_5 ] = V_59 ;
snprintf ( V_83 , sizeof( V_83 ) , L_23 , V_5 + 1 ) ;
V_18 = F_44 ( V_80 , V_83 , & V_4 ) ;
if ( V_18 < 0 )
continue;
V_18 = F_9 ( V_4 ) ;
if ( V_18 < 0 ) {
F_43 ( V_16 , L_24 ,
V_5 , V_4 ) ;
return - V_7 ;
}
F_26 ( V_16 , L_25 , V_5 , V_4 , V_18 ) ;
V_13 -> V_53 [ V_5 ] = V_18 ;
}
V_13 -> V_62 = F_45 ( V_80 ,
L_26 ) ;
return 0 ;
}
static int F_46 ( struct V_8 * V_24 )
{
struct V_15 * V_16 = & V_24 -> V_16 ;
struct V_25 * V_13 = V_16 -> V_26 ;
struct V_48 * V_49 ;
struct V_10 * V_11 ;
int V_18 = 0 ;
int V_5 ;
bool V_84 ;
if ( V_16 -> V_81 ) {
V_13 = F_47 ( V_16 , sizeof( * V_13 ) , V_85 ) ;
if ( ! V_13 )
return - V_33 ;
V_18 = F_41 ( V_16 , V_13 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_26 = V_13 ;
}
if ( ! V_13 ) {
F_13 ( V_16 , L_27 ) ;
return - V_7 ;
}
if ( V_13 -> V_52 > V_82 ) {
F_48 ( V_16 , L_28 ,
V_13 -> V_52 , V_82 ) ;
return - V_7 ;
}
V_49 = F_47 ( V_16 , sizeof( * V_49 ) , V_85 ) ;
if ( ! V_49 ) {
F_13 ( V_16 , L_29 ) ;
return - V_33 ;
}
V_11 = F_49 ( V_24 , V_30 , 0 ) ;
V_49 -> V_69 = F_50 ( V_16 , V_11 ) ;
if ( F_28 ( V_49 -> V_69 ) )
return F_51 ( V_49 -> V_69 ) ;
V_49 -> V_13 = V_13 ;
F_52 ( V_13 ) ;
F_53 ( V_16 ) ;
F_54 ( V_24 , V_49 ) ;
F_39 ( V_16 ) ;
V_49 -> V_76 = F_3 ( V_49 -> V_69 , V_86 ) ;
F_40 ( V_16 ) ;
if ( V_13 -> V_52 ) {
V_49 -> V_52 = V_13 -> V_52 ;
} else {
switch ( V_49 -> V_76 ) {
case V_77 :
V_49 -> V_52 = 3 ;
break;
case V_78 :
V_49 -> V_52 = 2 ;
break;
default:
V_49 -> V_52 = V_82 ;
F_26 ( V_16 ,
L_30 ,
V_49 -> V_76 , V_49 -> V_52 ) ;
break;
}
V_13 -> V_52 = V_49 -> V_52 ;
}
V_5 = sizeof( struct V_87 * ) * V_49 -> V_52 ;
V_49 -> V_58 = F_47 ( V_16 , V_5 , V_85 ) ;
V_49 -> V_56 = F_47 ( V_16 , V_5 , V_85 ) ;
V_49 -> V_55 = F_47 ( V_16 , V_5 , V_85 ) ;
if ( ! V_49 -> V_58 || ! V_49 -> V_56 || ! V_49 -> V_55 ) {
F_13 ( V_16 , L_29 ) ;
V_18 = - V_33 ;
goto V_88;
}
V_84 = false ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
if ( F_34 ( V_5 ) || F_36 ( V_5 ) ||
F_37 ( V_5 ) )
V_84 |= true ;
}
V_49 -> V_51 = F_55 ( - V_89 ) ;
if ( V_84 ) {
V_49 -> V_51 = F_56 ( V_16 , L_31 ) ;
if ( F_28 ( V_49 -> V_51 ) ) {
V_18 = F_51 ( V_49 -> V_51 ) ;
F_26 ( V_16 , L_32 , V_18 ) ;
}
}
V_49 -> V_90 = F_56 ( V_16 , L_33 ) ;
if ( F_28 ( V_49 -> V_90 ) ) {
V_18 = F_51 ( V_49 -> V_90 ) ;
F_13 ( V_16 , L_34 , V_18 ) ;
goto V_91;
}
V_49 -> V_92 = F_56 ( V_16 , L_35 ) ;
if ( F_28 ( V_49 -> V_92 ) ) {
V_18 = F_51 ( V_49 -> V_92 ) ;
F_13 ( V_16 , L_36 , V_18 ) ;
goto V_93;
}
V_49 -> V_94 = F_56 ( V_16 , L_37 ) ;
if ( F_28 ( V_49 -> V_94 ) ) {
V_18 = F_51 ( V_49 -> V_94 ) ;
F_13 ( V_16 , L_38 , V_18 ) ;
goto V_95;
}
V_49 -> V_96 = F_56 ( V_16 , L_39 ) ;
if ( F_28 ( V_49 -> V_96 ) ) {
V_18 = F_51 ( V_49 -> V_96 ) ;
F_13 ( V_16 , L_40 , V_18 ) ;
goto V_97;
}
V_49 -> V_98 = F_56 ( V_16 , L_41 ) ;
if ( F_28 ( V_49 -> V_98 ) ) {
V_18 = F_51 ( V_49 -> V_98 ) ;
F_13 ( V_16 , L_42 , V_18 ) ;
goto V_99;
}
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
char V_100 [ 30 ] ;
snprintf ( V_100 , sizeof( V_100 ) ,
L_43 , V_5 + 1 ) ;
V_49 -> V_58 [ V_5 ] = F_56 ( V_16 , V_100 ) ;
if ( F_28 ( V_49 -> V_58 [ V_5 ] ) )
F_26 ( V_16 , L_44 ,
V_100 , F_51 ( V_49 -> V_58 [ V_5 ] ) ) ;
snprintf ( V_100 , sizeof( V_100 ) ,
L_45 , V_5 + 1 ) ;
V_49 -> V_56 [ V_5 ] = F_56 ( V_16 , V_100 ) ;
if ( F_28 ( V_49 -> V_56 [ V_5 ] ) )
F_26 ( V_16 , L_44 ,
V_100 , F_51 ( V_49 -> V_56 [ V_5 ] ) ) ;
snprintf ( V_100 , sizeof( V_100 ) ,
L_46 , V_5 + 1 ) ;
V_49 -> V_55 [ V_5 ] = F_56 ( V_16 , V_100 ) ;
if ( F_28 ( V_49 -> V_55 [ V_5 ] ) )
F_26 ( V_16 , L_44 ,
V_100 , F_51 ( V_49 -> V_55 [ V_5 ] ) ) ;
}
if ( F_34 ( V_13 -> V_53 [ 0 ] ) ) {
V_18 = F_57 ( V_49 -> V_90 ,
V_49 -> V_94 ) ;
if ( V_18 != 0 )
F_26 ( V_16 , L_47 ,
V_18 ) ;
} else if ( F_36 ( V_13 -> V_53 [ 0 ] ) ) {
V_18 = F_57 ( V_49 -> V_90 ,
V_49 -> V_98 ) ;
if ( V_18 != 0 )
F_26 ( V_16 , L_48 ,
V_18 ) ;
}
if ( F_34 ( V_13 -> V_53 [ 1 ] ) ) {
V_18 = F_57 ( V_49 -> V_92 ,
V_49 -> V_96 ) ;
if ( V_18 != 0 )
F_26 ( V_16 , L_49 ,
V_18 ) ;
} else if ( F_36 ( V_13 -> V_53 [ 1 ] ) ) {
V_18 = F_57 ( V_49 -> V_92 ,
V_49 -> V_98 ) ;
if ( V_18 != 0 )
F_26 ( V_16 , L_50 ,
V_18 ) ;
}
F_38 ( V_16 ) ;
if ( V_16 -> V_81 ) {
V_18 = F_58 ( V_16 -> V_81 ,
V_101 , NULL , V_16 ) ;
if ( V_18 ) {
F_13 ( V_16 , L_51 , V_18 ) ;
goto V_20;
}
} else {
V_18 = F_20 ( V_24 ) ;
if ( V_18 ) {
F_13 ( V_16 , L_52 ,
V_18 ) ;
goto V_20;
}
}
return 0 ;
V_20:
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
if ( ! F_28 ( V_49 -> V_58 [ V_5 ] ) )
F_59 ( V_49 -> V_58 [ V_5 ] ) ;
if ( ! F_28 ( V_49 -> V_55 [ V_5 ] ) )
F_59 ( V_49 -> V_55 [ V_5 ] ) ;
if ( ! F_28 ( V_49 -> V_56 [ V_5 ] ) )
F_59 ( V_49 -> V_56 [ V_5 ] ) ;
}
F_59 ( V_49 -> V_98 ) ;
V_99:
F_59 ( V_49 -> V_96 ) ;
V_97:
F_59 ( V_49 -> V_94 ) ;
V_95:
F_59 ( V_49 -> V_92 ) ;
V_93:
F_59 ( V_49 -> V_90 ) ;
V_91:
if ( ! F_28 ( V_49 -> V_51 ) )
F_59 ( V_49 -> V_51 ) ;
V_88:
F_60 ( V_16 ) ;
return V_18 ;
}
static int F_61 ( struct V_15 * V_16 , void * V_102 )
{
F_48 ( V_16 , L_53 ) ;
F_22 ( F_62 ( V_16 ) ) ;
return 0 ;
}
static int F_63 ( struct V_8 * V_24 )
{
struct V_48 * V_49 = F_64 ( V_24 ) ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_49 -> V_52 ; V_5 ++ ) {
if ( ! F_28 ( V_49 -> V_58 [ V_5 ] ) )
F_59 ( V_49 -> V_58 [ V_5 ] ) ;
if ( ! F_28 ( V_49 -> V_55 [ V_5 ] ) )
F_59 ( V_49 -> V_55 [ V_5 ] ) ;
if ( ! F_28 ( V_49 -> V_56 [ V_5 ] ) )
F_59 ( V_49 -> V_56 [ V_5 ] ) ;
}
F_59 ( V_49 -> V_98 ) ;
F_59 ( V_49 -> V_90 ) ;
F_59 ( V_49 -> V_92 ) ;
F_59 ( V_49 -> V_96 ) ;
F_59 ( V_49 -> V_94 ) ;
if ( ! F_28 ( V_49 -> V_51 ) )
F_59 ( V_49 -> V_51 ) ;
F_60 ( & V_24 -> V_16 ) ;
F_65 ( & V_24 -> V_16 , NULL , F_61 ) ;
return 0 ;
}
static int T_5 F_66 ( void )
{
return F_67 ( & V_103 , F_46 ) ;
}
static void T_6 F_68 ( void )
{
F_69 ( & V_103 ) ;
}
