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
static struct V_4 * F_9 ( const char * V_5 ,
struct V_6 * V_7 , int V_8 , void * V_9 ,
T_4 V_10 , struct V_11 * V_12 )
{
struct V_4 * V_13 ;
int V_14 ;
V_13 = F_10 ( V_5 , 0 ) ;
if ( ! V_13 ) {
F_11 ( V_12 , L_1 , V_5 ) ;
goto V_15;
}
V_14 = F_12 ( V_13 , V_7 , V_8 ) ;
if ( V_14 ) {
F_11 ( V_12 , L_2 ) ;
goto V_16;
}
V_14 = F_13 ( V_13 , V_9 , V_10 ) ;
if ( V_14 ) {
F_11 ( V_12 , L_3 ) ;
goto V_16;
}
V_13 -> V_12 . V_17 = & V_18 ;
F_14 ( & V_13 -> V_12 , F_15 ( 32 ) ) ;
V_13 -> V_12 . V_19 = V_12 ;
V_14 = F_16 ( V_13 ) ;
if ( V_14 ) {
F_11 ( V_12 , L_4 ) ;
goto V_16;
}
return V_13 ;
V_16:
F_17 ( V_13 ) ;
V_15:
return NULL ;
}
static int F_18 ( struct V_4 * V_20 )
{
struct V_11 * V_12 = & V_20 -> V_12 ;
struct V_21 * V_9 = V_12 -> V_22 ;
struct V_4 * V_23 ;
struct V_4 * V_24 ;
struct V_6 * V_7 ;
struct V_6 V_25 [ 2 ] ;
int V_14 ;
V_7 = F_19 ( V_20 , V_26 , L_5 ) ;
if ( ! V_7 ) {
F_11 ( V_12 , L_6 ) ;
V_14 = - V_27 ;
goto V_15;
}
V_25 [ 0 ] = * V_7 ;
V_7 = F_19 ( V_20 , V_28 , L_7 ) ;
if ( ! V_7 ) {
F_11 ( V_12 , L_8 ) ;
V_14 = - V_27 ;
goto V_15;
}
V_25 [ 1 ] = * V_7 ;
V_23 = F_9 ( V_29 , V_25 , 2 , V_9 ,
sizeof( * V_9 ) , V_12 ) ;
if ( ! V_23 ) {
F_11 ( V_12 , L_9 ) ;
V_14 = - V_30 ;
goto V_15;
}
V_7 = F_19 ( V_20 , V_26 , L_10 ) ;
if ( ! V_7 ) {
F_11 ( V_12 , L_11 ) ;
V_14 = - V_27 ;
goto V_31;
}
V_25 [ 0 ] = * V_7 ;
V_7 = F_19 ( V_20 , V_28 , L_12 ) ;
if ( ! V_7 ) {
F_11 ( V_12 , L_13 ) ;
V_14 = - V_27 ;
goto V_31;
}
V_25 [ 1 ] = * V_7 ;
V_24 = F_9 ( V_32 , V_25 , 2 , V_9 ,
sizeof( * V_9 ) , V_12 ) ;
if ( ! V_24 ) {
F_11 ( V_12 , L_9 ) ;
V_14 = - V_30 ;
goto V_31;
}
return 0 ;
V_31:
F_20 ( V_23 ) ;
V_15:
return V_14 ;
}
static bool F_21 ( enum V_33 V_34 )
{
switch ( V_34 ) {
case V_35 :
case V_36 :
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return true ;
default:
return false ;
}
}
static int F_22 ( struct V_11 * V_12 )
{
struct V_45 * V_46 = F_23 ( V_12 ) ;
struct V_21 * V_9 = V_46 -> V_9 ;
int V_47 , V_48 ;
F_24 ( V_12 , L_14 ) ;
F_25 () ;
if ( ! F_26 ( V_46 -> V_49 ) )
F_27 ( V_46 -> V_49 ) ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
switch ( V_9 -> V_51 [ V_47 ] ) {
case V_52 :
if ( ! F_26 ( V_46 -> V_53 [ V_47 ] ) ) {
V_48 = F_27 ( V_46 -> V_53 [ V_47 ] ) ;
if ( V_48 ) {
F_11 ( V_12 ,
L_15 ,
V_47 , V_48 ) ;
}
}
if ( ! F_26 ( V_46 -> V_54 [ V_47 ] ) ) {
V_48 = F_27 ( V_46 -> V_54 [ V_47 ] ) ;
if ( V_48 ) {
F_11 ( V_12 ,
L_16 ,
V_47 , V_48 ) ;
}
}
case V_55 :
if ( ! F_26 ( V_46 -> V_56 [ V_47 ] ) ) {
V_48 = F_27 ( V_46 -> V_56 [ V_47 ] ) ;
if ( V_48 ) {
F_11 ( V_12 ,
L_17 ,
V_47 , V_48 ) ;
}
}
break;
default:
break;
}
}
return 0 ;
}
static int F_28 ( struct V_11 * V_12 )
{
struct V_45 * V_46 = F_23 ( V_12 ) ;
struct V_21 * V_9 = V_46 -> V_9 ;
int V_47 ;
F_24 ( V_12 , L_18 ) ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
switch ( V_9 -> V_51 [ V_47 ] ) {
case V_52 :
if ( ! F_26 ( V_46 -> V_53 [ V_47 ] ) )
F_29 ( V_46 -> V_53 [ V_47 ] ) ;
if ( ! F_26 ( V_46 -> V_54 [ V_47 ] ) )
F_29 ( V_46 -> V_54 [ V_47 ] ) ;
case V_55 :
if ( ! F_26 ( V_46 -> V_56 [ V_47 ] ) )
F_29 ( V_46 -> V_56 [ V_47 ] ) ;
break;
default:
break;
}
}
if ( ! F_26 ( V_46 -> V_49 ) )
F_29 ( V_46 -> V_49 ) ;
F_30 () ;
return 0 ;
}
static unsigned F_31 ( struct V_45 * V_46 ,
unsigned V_2 )
{
struct V_21 * V_9 = V_46 -> V_9 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
switch ( V_9 -> V_51 [ V_47 ] ) {
case V_57 :
V_2 &= ~ ( V_58 << V_47 ) ;
break;
case V_59 :
if ( V_9 -> V_60 )
break;
if ( V_47 == 0 )
V_2 &= ~ V_61 ;
else
V_2 &= ~ ( V_62
<< ( V_47 - 1 ) ) ;
break;
default:
if ( V_9 -> V_60 )
break;
if ( V_47 == 0 )
V_2 |= V_61 ;
else
V_2 |= V_62
<< ( V_47 - 1 ) ;
break;
}
}
if ( V_9 -> V_60 ) {
V_2 |= V_63 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
if ( F_32 ( V_9 -> V_51 [ V_47 ] ) ) {
V_2 &= V_63 ;
break;
}
}
}
return V_2 ;
}
static unsigned F_33 ( struct V_45 * V_46 ,
unsigned V_2 )
{
struct V_21 * V_9 = V_46 -> V_9 ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
V_2 &= ~ ( V_64 << 2 * V_47 ) ;
if ( F_34 ( V_9 -> V_51 [ V_47 ] ) ||
( F_21 ( V_9 -> V_51 [ V_47 ] ) ) )
V_2 |= V_65 << 2 * V_47 ;
else if ( F_35 ( V_9 -> V_51 [ V_47 ] ) )
V_2 |= V_66 << 2 * V_47 ;
}
return V_2 ;
}
static void F_36 ( struct V_11 * V_12 )
{
struct V_45 * V_46 = F_23 ( V_12 ) ;
struct V_21 * V_9 = V_46 -> V_9 ;
unsigned V_2 ;
F_24 ( V_12 , L_19 ) ;
if ( V_9 -> V_67 ) {
if ( F_37 ( V_9 -> V_68 [ 0 ] ) )
F_38 ( V_9 -> V_68 [ 0 ] ,
V_69 , L_20 ) ;
if ( F_37 ( V_9 -> V_68 [ 1 ] ) )
F_38 ( V_9 -> V_68 [ 1 ] ,
V_69 , L_21 ) ;
F_39 ( 10 ) ;
}
F_40 ( V_12 ) ;
V_2 = F_3 ( V_46 -> V_70 , V_71 ) ;
V_2 |= ( V_72
| V_73
| V_74 ) ;
V_2 |= V_75 ;
V_2 &= ~ V_76 ;
switch ( V_46 -> V_77 ) {
case V_78 :
V_2 = F_31 ( V_46 , V_2 ) ;
break;
case V_79 :
V_2 = F_33 ( V_46 , V_2 ) ;
break;
default:
V_2 = F_33 ( V_46 , V_2 ) ;
break;
}
F_1 ( V_46 -> V_70 , V_71 , V_2 ) ;
F_24 ( V_12 , L_22 , V_2 ) ;
F_41 ( V_12 ) ;
if ( V_9 -> V_67 ) {
F_39 ( 10 ) ;
if ( F_37 ( V_9 -> V_68 [ 0 ] ) )
F_42
( V_9 -> V_68 [ 0 ] , 1 ) ;
if ( F_37 ( V_9 -> V_68 [ 1 ] ) )
F_42
( V_9 -> V_68 [ 1 ] , 1 ) ;
}
}
static void F_43 ( struct V_11 * V_12 )
{
struct V_45 * V_46 = F_23 ( V_12 ) ;
struct V_21 * V_9 = V_46 -> V_9 ;
if ( V_9 -> V_67 ) {
if ( F_37 ( V_9 -> V_68 [ 0 ] ) )
F_44 ( V_9 -> V_68 [ 0 ] ) ;
if ( F_37 ( V_9 -> V_68 [ 1 ] ) )
F_44 ( V_9 -> V_68 [ 1 ] ) ;
}
}
static int F_45 ( struct V_4 * V_20 )
{
struct V_11 * V_12 = & V_20 -> V_12 ;
struct V_21 * V_9 = V_12 -> V_22 ;
struct V_45 * V_46 ;
struct V_6 * V_7 ;
int V_14 = 0 ;
int V_47 ;
bool V_80 ;
if ( ! V_9 ) {
F_11 ( V_12 , L_23 ) ;
return - V_27 ;
}
V_46 = F_46 ( V_12 , sizeof( * V_46 ) , V_81 ) ;
if ( ! V_46 ) {
F_11 ( V_12 , L_24 ) ;
return - V_30 ;
}
V_7 = F_19 ( V_20 , V_26 , L_25 ) ;
V_46 -> V_70 = F_47 ( V_12 , V_7 ) ;
if ( ! V_46 -> V_70 ) {
F_11 ( V_12 , L_26 ) ;
return - V_82 ;
}
V_46 -> V_9 = V_9 ;
F_48 ( V_12 ) ;
F_49 ( V_20 , V_46 ) ;
F_40 ( V_12 ) ;
V_46 -> V_77 = F_3 ( V_46 -> V_70 , V_83 ) ;
F_41 ( V_12 ) ;
if ( V_9 -> V_50 ) {
V_46 -> V_50 = V_9 -> V_50 ;
} else {
switch ( V_46 -> V_77 ) {
case V_78 :
V_46 -> V_50 = 3 ;
break;
case V_79 :
V_46 -> V_50 = 2 ;
break;
default:
V_46 -> V_50 = V_84 ;
F_24 ( V_12 ,
L_27 ,
V_46 -> V_77 , V_46 -> V_50 ) ;
break;
}
}
V_47 = sizeof( struct V_85 * ) * V_46 -> V_50 ;
V_46 -> V_56 = F_46 ( V_12 , V_47 , V_81 ) ;
V_46 -> V_54 = F_46 ( V_12 , V_47 , V_81 ) ;
V_46 -> V_53 = F_46 ( V_12 , V_47 , V_81 ) ;
if ( ! V_46 -> V_56 || ! V_46 -> V_54 || ! V_46 -> V_53 ) {
F_11 ( V_12 , L_24 ) ;
V_14 = - V_30 ;
goto V_86;
}
V_80 = false ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
if ( F_32 ( V_47 ) || F_34 ( V_47 ) ||
F_35 ( V_47 ) )
V_80 |= true ;
}
V_46 -> V_49 = F_50 ( - V_87 ) ;
if ( V_80 ) {
V_46 -> V_49 = F_51 ( V_12 , L_28 ) ;
if ( F_26 ( V_46 -> V_49 ) ) {
V_14 = F_52 ( V_46 -> V_49 ) ;
F_24 ( V_12 , L_29 , V_14 ) ;
}
}
V_46 -> V_88 = F_51 ( V_12 , L_30 ) ;
if ( F_26 ( V_46 -> V_88 ) ) {
V_14 = F_52 ( V_46 -> V_88 ) ;
F_11 ( V_12 , L_31 , V_14 ) ;
goto V_89;
}
V_46 -> V_90 = F_51 ( V_12 , L_32 ) ;
if ( F_26 ( V_46 -> V_90 ) ) {
V_14 = F_52 ( V_46 -> V_90 ) ;
F_11 ( V_12 , L_33 , V_14 ) ;
goto V_91;
}
V_46 -> V_92 = F_51 ( V_12 , L_34 ) ;
if ( F_26 ( V_46 -> V_92 ) ) {
V_14 = F_52 ( V_46 -> V_92 ) ;
F_11 ( V_12 , L_35 , V_14 ) ;
goto V_93;
}
V_46 -> V_94 = F_51 ( V_12 , L_36 ) ;
if ( F_26 ( V_46 -> V_94 ) ) {
V_14 = F_52 ( V_46 -> V_94 ) ;
F_11 ( V_12 , L_37 , V_14 ) ;
goto V_95;
}
V_46 -> V_96 = F_51 ( V_12 , L_38 ) ;
if ( F_26 ( V_46 -> V_96 ) ) {
V_14 = F_52 ( V_46 -> V_96 ) ;
F_11 ( V_12 , L_39 , V_14 ) ;
goto V_97;
}
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
char V_98 [ 30 ] ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_40 , V_47 + 1 ) ;
V_46 -> V_56 [ V_47 ] = F_51 ( V_12 , V_98 ) ;
if ( F_26 ( V_46 -> V_56 [ V_47 ] ) )
F_24 ( V_12 , L_41 ,
V_98 , F_52 ( V_46 -> V_56 [ V_47 ] ) ) ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_42 , V_47 + 1 ) ;
V_46 -> V_54 [ V_47 ] = F_51 ( V_12 , V_98 ) ;
if ( F_26 ( V_46 -> V_54 [ V_47 ] ) )
F_24 ( V_12 , L_41 ,
V_98 , F_52 ( V_46 -> V_54 [ V_47 ] ) ) ;
snprintf ( V_98 , sizeof( V_98 ) ,
L_43 , V_47 + 1 ) ;
V_46 -> V_53 [ V_47 ] = F_51 ( V_12 , V_98 ) ;
if ( F_26 ( V_46 -> V_53 [ V_47 ] ) )
F_24 ( V_12 , L_41 ,
V_98 , F_52 ( V_46 -> V_53 [ V_47 ] ) ) ;
}
if ( F_32 ( V_9 -> V_51 [ 0 ] ) ) {
V_14 = F_53 ( V_46 -> V_88 ,
V_46 -> V_92 ) ;
if ( V_14 != 0 )
F_24 ( V_12 , L_44 ,
V_14 ) ;
} else if ( F_34 ( V_9 -> V_51 [ 0 ] ) ) {
V_14 = F_53 ( V_46 -> V_88 ,
V_46 -> V_96 ) ;
if ( V_14 != 0 )
F_24 ( V_12 , L_45 ,
V_14 ) ;
}
if ( F_32 ( V_9 -> V_51 [ 1 ] ) ) {
V_14 = F_53 ( V_46 -> V_90 ,
V_46 -> V_94 ) ;
if ( V_14 != 0 )
F_24 ( V_12 , L_46 ,
V_14 ) ;
} else if ( F_34 ( V_9 -> V_51 [ 1 ] ) ) {
V_14 = F_53 ( V_46 -> V_90 ,
V_46 -> V_96 ) ;
if ( V_14 != 0 )
F_24 ( V_12 , L_47 ,
V_14 ) ;
}
F_36 ( V_12 ) ;
V_14 = F_18 ( V_20 ) ;
if ( V_14 ) {
F_11 ( V_12 , L_48 ) ;
goto V_16;
}
return 0 ;
V_16:
F_43 ( & V_20 -> V_12 ) ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
if ( ! F_26 ( V_46 -> V_56 [ V_47 ] ) )
F_54 ( V_46 -> V_56 [ V_47 ] ) ;
if ( ! F_26 ( V_46 -> V_53 [ V_47 ] ) )
F_54 ( V_46 -> V_53 [ V_47 ] ) ;
if ( ! F_26 ( V_46 -> V_54 [ V_47 ] ) )
F_54 ( V_46 -> V_54 [ V_47 ] ) ;
}
F_54 ( V_46 -> V_96 ) ;
V_97:
F_54 ( V_46 -> V_94 ) ;
V_95:
F_54 ( V_46 -> V_92 ) ;
V_93:
F_54 ( V_46 -> V_90 ) ;
V_91:
F_54 ( V_46 -> V_88 ) ;
V_89:
if ( ! F_26 ( V_46 -> V_49 ) )
F_54 ( V_46 -> V_49 ) ;
V_86:
F_55 ( V_12 ) ;
return V_14 ;
}
static int F_56 ( struct V_4 * V_20 )
{
struct V_45 * V_46 = F_57 ( V_20 ) ;
int V_47 ;
F_43 ( & V_20 -> V_12 ) ;
for ( V_47 = 0 ; V_47 < V_46 -> V_50 ; V_47 ++ ) {
if ( ! F_26 ( V_46 -> V_56 [ V_47 ] ) )
F_54 ( V_46 -> V_56 [ V_47 ] ) ;
if ( ! F_26 ( V_46 -> V_53 [ V_47 ] ) )
F_54 ( V_46 -> V_53 [ V_47 ] ) ;
if ( ! F_26 ( V_46 -> V_54 [ V_47 ] ) )
F_54 ( V_46 -> V_54 [ V_47 ] ) ;
}
F_54 ( V_46 -> V_96 ) ;
F_54 ( V_46 -> V_88 ) ;
F_54 ( V_46 -> V_90 ) ;
F_54 ( V_46 -> V_94 ) ;
F_54 ( V_46 -> V_92 ) ;
if ( ! F_26 ( V_46 -> V_49 ) )
F_54 ( V_46 -> V_49 ) ;
F_55 ( & V_20 -> V_12 ) ;
return 0 ;
}
static int T_5 F_58 ( void )
{
return F_59 ( & V_99 , F_45 ) ;
}
static void T_6 F_60 ( void )
{
F_61 ( & V_99 ) ;
}
