static inline void F_1 ( void T_1 * V_1 , T_2 V_2 , T_2 V_3 )
{
F_2 ( V_3 , V_1 + V_2 ) ;
}
static inline T_2 F_3 ( void T_1 * V_1 , T_2 V_2 )
{
return F_4 ( V_1 + V_2 ) ;
}
static int F_5 ( const char * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_5 < F_6 ( V_6 ) ; V_5 ++ ) {
if ( ! strcmp ( V_4 , V_6 [ V_5 ] ) )
return V_5 ;
}
return - V_7 ;
}
static struct V_8 * F_7 ( const char * V_9 ,
struct V_10 * V_11 , int V_12 , void * V_13 ,
T_3 V_14 , struct V_15 * V_16 )
{
struct V_8 * V_17 ;
int V_18 ;
V_17 = F_8 ( V_9 , 0 ) ;
if ( ! V_17 ) {
F_9 ( V_16 , L_1 , V_9 ) ;
goto V_19;
}
V_18 = F_10 ( V_17 , V_11 , V_12 ) ;
if ( V_18 ) {
F_9 ( V_16 , L_2 ) ;
goto V_20;
}
V_18 = F_11 ( V_17 , V_13 , V_14 ) ;
if ( V_18 ) {
F_9 ( V_16 , L_3 ) ;
goto V_20;
}
V_17 -> V_16 . V_21 = & V_22 ;
F_12 ( & V_17 -> V_16 , F_13 ( 32 ) ) ;
V_17 -> V_16 . V_23 = V_16 ;
V_18 = F_14 ( V_17 ) ;
if ( V_18 ) {
F_9 ( V_16 , L_4 ) ;
goto V_20;
}
return V_17 ;
V_20:
F_15 ( V_17 ) ;
V_19:
return NULL ;
}
static int F_16 ( struct V_8 * V_24 )
{
struct V_15 * V_16 = & V_24 -> V_16 ;
struct V_25 * V_13 = F_17 ( V_16 ) ;
struct V_8 * V_26 ;
struct V_8 * V_27 ;
struct V_10 * V_11 ;
struct V_10 V_28 [ 2 ] ;
int V_18 ;
V_11 = F_18 ( V_24 , V_29 , L_5 ) ;
if ( ! V_11 ) {
F_9 ( V_16 , L_6 ) ;
V_18 = - V_7 ;
goto V_19;
}
V_28 [ 0 ] = * V_11 ;
V_11 = F_18 ( V_24 , V_30 , L_7 ) ;
if ( ! V_11 ) {
F_9 ( V_16 , L_8 ) ;
V_18 = - V_7 ;
goto V_19;
}
V_28 [ 1 ] = * V_11 ;
V_26 = F_7 ( V_31 , V_28 , 2 , V_13 ,
sizeof( * V_13 ) , V_16 ) ;
if ( ! V_26 ) {
F_9 ( V_16 , L_9 ) ;
V_18 = - V_32 ;
goto V_19;
}
V_11 = F_18 ( V_24 , V_29 , L_10 ) ;
if ( ! V_11 ) {
F_9 ( V_16 , L_11 ) ;
V_18 = - V_7 ;
goto V_33;
}
V_28 [ 0 ] = * V_11 ;
V_11 = F_18 ( V_24 , V_30 , L_12 ) ;
if ( ! V_11 ) {
F_9 ( V_16 , L_13 ) ;
V_18 = - V_7 ;
goto V_33;
}
V_28 [ 1 ] = * V_11 ;
V_27 = F_7 ( V_34 , V_28 , 2 , V_13 ,
sizeof( * V_13 ) , V_16 ) ;
if ( ! V_27 ) {
F_9 ( V_16 , L_9 ) ;
V_18 = - V_32 ;
goto V_33;
}
return 0 ;
V_33:
F_19 ( V_26 ) ;
V_19:
return V_18 ;
}
static bool F_20 ( enum V_35 V_36 )
{
switch ( V_36 ) {
case V_37 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
case V_45 :
case V_46 :
return true ;
default:
return false ;
}
}
static int F_21 ( struct V_15 * V_16 )
{
struct V_47 * V_48 = F_22 ( V_16 ) ;
struct V_25 * V_13 = V_48 -> V_13 ;
int V_5 , V_49 ;
F_23 ( V_16 , L_14 ) ;
F_24 ( V_13 ) ;
if ( ! F_25 ( V_48 -> V_50 ) )
F_26 ( V_48 -> V_50 ) ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
switch ( V_13 -> V_52 [ V_5 ] ) {
case V_53 :
if ( ! F_25 ( V_48 -> V_54 [ V_5 ] ) ) {
V_49 = F_26 ( V_48 -> V_54 [ V_5 ] ) ;
if ( V_49 ) {
F_9 ( V_16 ,
L_15 ,
V_5 , V_49 ) ;
}
}
if ( ! F_25 ( V_48 -> V_55 [ V_5 ] ) ) {
V_49 = F_26 ( V_48 -> V_55 [ V_5 ] ) ;
if ( V_49 ) {
F_9 ( V_16 ,
L_16 ,
V_5 , V_49 ) ;
}
}
case V_56 :
if ( ! F_25 ( V_48 -> V_57 [ V_5 ] ) ) {
V_49 = F_26 ( V_48 -> V_57 [ V_5 ] ) ;
if ( V_49 ) {
F_9 ( V_16 ,
L_17 ,
V_5 , V_49 ) ;
}
}
break;
default:
break;
}
}
return 0 ;
}
static int F_27 ( struct V_15 * V_16 )
{
struct V_47 * V_48 = F_22 ( V_16 ) ;
struct V_25 * V_13 = V_48 -> V_13 ;
int V_5 ;
F_23 ( V_16 , L_18 ) ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
switch ( V_13 -> V_52 [ V_5 ] ) {
case V_53 :
if ( ! F_25 ( V_48 -> V_54 [ V_5 ] ) )
F_28 ( V_48 -> V_54 [ V_5 ] ) ;
if ( ! F_25 ( V_48 -> V_55 [ V_5 ] ) )
F_28 ( V_48 -> V_55 [ V_5 ] ) ;
case V_56 :
if ( ! F_25 ( V_48 -> V_57 [ V_5 ] ) )
F_28 ( V_48 -> V_57 [ V_5 ] ) ;
break;
default:
break;
}
}
if ( ! F_25 ( V_48 -> V_50 ) )
F_28 ( V_48 -> V_50 ) ;
F_29 ( V_13 ) ;
return 0 ;
}
static unsigned F_30 ( struct V_47 * V_48 ,
unsigned V_2 )
{
struct V_25 * V_13 = V_48 -> V_13 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
switch ( V_13 -> V_52 [ V_5 ] ) {
case V_58 :
V_2 &= ~ ( V_59 << V_5 ) ;
break;
case V_60 :
if ( V_13 -> V_61 )
break;
if ( V_5 == 0 )
V_2 &= ~ V_62 ;
else
V_2 &= ~ ( V_63
<< ( V_5 - 1 ) ) ;
break;
default:
if ( V_13 -> V_61 )
break;
if ( V_5 == 0 )
V_2 |= V_62 ;
else
V_2 |= V_63
<< ( V_5 - 1 ) ;
break;
}
}
if ( V_13 -> V_61 ) {
V_2 |= V_64 ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
if ( F_31 ( V_13 -> V_52 [ V_5 ] ) ) {
V_2 &= ~ V_64 ;
break;
}
}
}
return V_2 ;
}
static unsigned F_32 ( struct V_47 * V_48 ,
unsigned V_2 )
{
struct V_25 * V_13 = V_48 -> V_13 ;
int V_5 ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
V_2 &= ~ ( V_65 << 2 * V_5 ) ;
if ( F_33 ( V_13 -> V_52 [ V_5 ] ) ||
( F_20 ( V_13 -> V_52 [ V_5 ] ) ) )
V_2 |= V_66 << 2 * V_5 ;
else if ( F_34 ( V_13 -> V_52 [ V_5 ] ) )
V_2 |= V_67 << 2 * V_5 ;
}
return V_2 ;
}
static void F_35 ( struct V_15 * V_16 )
{
struct V_47 * V_48 = F_22 ( V_16 ) ;
unsigned V_2 ;
F_23 ( V_16 , L_19 ) ;
F_36 ( V_16 ) ;
V_2 = F_3 ( V_48 -> V_68 , V_69 ) ;
V_2 |= ( V_70
| V_71
| V_72 ) ;
V_2 |= V_73 ;
V_2 &= ~ V_74 ;
switch ( V_48 -> V_75 ) {
case V_76 :
V_2 = F_30 ( V_48 , V_2 ) ;
break;
case V_77 :
V_2 = F_32 ( V_48 , V_2 ) ;
break;
default:
V_2 = F_32 ( V_48 , V_2 ) ;
break;
}
F_1 ( V_48 -> V_68 , V_69 , V_2 ) ;
F_23 ( V_16 , L_20 , V_2 ) ;
F_37 ( V_16 ) ;
}
static int F_38 ( struct V_15 * V_16 ,
struct V_25 * V_13 )
{
int V_18 , V_5 ;
struct V_78 * V_79 = V_16 -> V_80 ;
V_18 = F_39 ( V_79 , L_21 , & V_13 -> V_51 ) ;
if ( V_18 )
V_13 -> V_51 = 0 ;
if ( V_13 -> V_51 > V_81 ) {
F_40 ( V_16 , L_22 ,
V_13 -> V_51 , V_81 ) ;
return - V_7 ;
}
for ( V_5 = 0 ; V_5 < V_81 ; V_5 ++ ) {
char V_82 [ 11 ] ;
const char * V_4 ;
V_13 -> V_52 [ V_5 ] = V_58 ;
snprintf ( V_82 , sizeof( V_82 ) , L_23 , V_5 + 1 ) ;
V_18 = F_41 ( V_79 , V_82 , & V_4 ) ;
if ( V_18 < 0 )
continue;
V_18 = F_5 ( V_4 ) ;
if ( V_18 < 0 ) {
F_40 ( V_16 , L_24 ,
V_5 , V_4 ) ;
return - V_7 ;
}
F_23 ( V_16 , L_25 , V_5 , V_4 , V_18 ) ;
V_13 -> V_52 [ V_5 ] = V_18 ;
}
V_13 -> V_61 = F_42 ( V_79 ,
L_26 ) ;
return 0 ;
}
static int F_43 ( struct V_8 * V_24 )
{
struct V_15 * V_16 = & V_24 -> V_16 ;
struct V_25 * V_13 = F_17 ( V_16 ) ;
struct V_47 * V_48 ;
struct V_10 * V_11 ;
int V_18 = 0 ;
int V_5 ;
bool V_83 ;
if ( V_16 -> V_80 ) {
V_13 = F_44 ( V_16 , sizeof( * V_13 ) , V_84 ) ;
if ( ! V_13 )
return - V_32 ;
V_18 = F_38 ( V_16 , V_13 ) ;
if ( V_18 )
return V_18 ;
V_16 -> V_85 = V_13 ;
}
if ( ! V_13 ) {
F_9 ( V_16 , L_27 ) ;
return - V_7 ;
}
if ( V_13 -> V_51 > V_81 ) {
F_45 ( V_16 , L_28 ,
V_13 -> V_51 , V_81 ) ;
return - V_7 ;
}
V_48 = F_44 ( V_16 , sizeof( * V_48 ) , V_84 ) ;
if ( ! V_48 ) {
F_9 ( V_16 , L_29 ) ;
return - V_32 ;
}
V_11 = F_46 ( V_24 , V_29 , 0 ) ;
V_48 -> V_68 = F_47 ( V_16 , V_11 ) ;
if ( F_25 ( V_48 -> V_68 ) )
return F_48 ( V_48 -> V_68 ) ;
V_48 -> V_13 = V_13 ;
F_49 ( V_13 ) ;
F_50 ( V_16 ) ;
F_51 ( V_24 , V_48 ) ;
F_36 ( V_16 ) ;
V_48 -> V_75 = F_3 ( V_48 -> V_68 , V_86 ) ;
F_37 ( V_16 ) ;
if ( V_13 -> V_51 ) {
V_48 -> V_51 = V_13 -> V_51 ;
} else {
switch ( V_48 -> V_75 ) {
case V_76 :
V_48 -> V_51 = 3 ;
break;
case V_77 :
V_48 -> V_51 = 2 ;
break;
default:
V_48 -> V_51 = V_81 ;
F_23 ( V_16 ,
L_30 ,
V_48 -> V_75 , V_48 -> V_51 ) ;
break;
}
V_13 -> V_51 = V_48 -> V_51 ;
}
V_5 = sizeof( struct V_87 * ) * V_48 -> V_51 ;
V_48 -> V_57 = F_44 ( V_16 , V_5 , V_84 ) ;
V_48 -> V_55 = F_44 ( V_16 , V_5 , V_84 ) ;
V_48 -> V_54 = F_44 ( V_16 , V_5 , V_84 ) ;
if ( ! V_48 -> V_57 || ! V_48 -> V_55 || ! V_48 -> V_54 ) {
F_9 ( V_16 , L_29 ) ;
V_18 = - V_32 ;
goto V_88;
}
V_48 -> V_50 = F_52 ( - V_7 ) ;
V_48 -> V_89 = F_52 ( - V_7 ) ;
V_48 -> V_90 = F_52 ( - V_7 ) ;
V_48 -> V_91 = F_52 ( - V_7 ) ;
V_48 -> V_92 = F_52 ( - V_7 ) ;
V_48 -> V_93 = F_52 ( - V_7 ) ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
V_48 -> V_57 [ V_5 ] = F_52 ( - V_7 ) ;
V_48 -> V_55 [ V_5 ] = F_52 ( - V_7 ) ;
V_48 -> V_54 [ V_5 ] = F_52 ( - V_7 ) ;
}
if ( V_48 -> V_75 == V_76 ) {
V_83 = false ;
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
if ( F_31 ( V_13 -> V_52 [ V_5 ] ) ||
F_33 ( V_13 -> V_52 [ V_5 ] ) ||
F_34 ( V_13 -> V_52 [ V_5 ] ) )
V_83 |= true ;
}
if ( V_83 ) {
V_48 -> V_50 = F_53 ( V_16 ,
L_31 ) ;
if ( F_25 ( V_48 -> V_50 ) ) {
V_18 = F_48 ( V_48 -> V_50 ) ;
F_9 ( V_16 , L_32 ,
V_18 ) ;
goto V_88;
}
}
goto V_94;
}
V_48 -> V_90 = F_53 ( V_16 , L_33 ) ;
if ( F_25 ( V_48 -> V_90 ) ) {
V_18 = F_48 ( V_48 -> V_90 ) ;
F_9 ( V_16 , L_34 , V_18 ) ;
goto V_88;
}
V_48 -> V_91 = F_53 ( V_16 , L_35 ) ;
if ( F_25 ( V_48 -> V_91 ) ) {
V_18 = F_48 ( V_48 -> V_91 ) ;
F_9 ( V_16 , L_36 , V_18 ) ;
goto V_88;
}
V_48 -> V_92 = F_53 ( V_16 , L_37 ) ;
if ( F_25 ( V_48 -> V_92 ) ) {
V_18 = F_48 ( V_48 -> V_92 ) ;
F_9 ( V_16 , L_38 , V_18 ) ;
goto V_88;
}
V_48 -> V_93 = F_53 ( V_16 , L_39 ) ;
if ( F_25 ( V_48 -> V_93 ) ) {
V_18 = F_48 ( V_48 -> V_93 ) ;
F_9 ( V_16 , L_40 , V_18 ) ;
goto V_88;
}
V_48 -> V_89 = F_53 ( V_16 , L_41 ) ;
if ( F_25 ( V_48 -> V_89 ) ) {
V_18 = F_48 ( V_48 -> V_89 ) ;
F_9 ( V_16 , L_42 , V_18 ) ;
goto V_88;
}
for ( V_5 = 0 ; V_5 < V_48 -> V_51 ; V_5 ++ ) {
char V_95 [ 30 ] ;
snprintf ( V_95 , sizeof( V_95 ) ,
L_43 , V_5 + 1 ) ;
V_48 -> V_57 [ V_5 ] = F_53 ( V_16 , V_95 ) ;
if ( F_25 ( V_48 -> V_57 [ V_5 ] ) ) {
V_18 = F_48 ( V_48 -> V_57 [ V_5 ] ) ;
F_9 ( V_16 , L_44 ,
V_95 , V_18 ) ;
goto V_88;
}
snprintf ( V_95 , sizeof( V_95 ) ,
L_45 , V_5 + 1 ) ;
V_48 -> V_55 [ V_5 ] = F_53 ( V_16 , V_95 ) ;
if ( F_25 ( V_48 -> V_55 [ V_5 ] ) ) {
V_18 = F_48 ( V_48 -> V_55 [ V_5 ] ) ;
F_9 ( V_16 , L_44 ,
V_95 , V_18 ) ;
goto V_88;
}
snprintf ( V_95 , sizeof( V_95 ) ,
L_46 , V_5 + 1 ) ;
V_48 -> V_54 [ V_5 ] = F_53 ( V_16 , V_95 ) ;
if ( F_25 ( V_48 -> V_54 [ V_5 ] ) ) {
V_18 = F_48 ( V_48 -> V_54 [ V_5 ] ) ;
F_9 ( V_16 , L_44 ,
V_95 , V_18 ) ;
goto V_88;
}
}
if ( F_31 ( V_13 -> V_52 [ 0 ] ) ) {
V_18 = F_54 ( V_48 -> V_90 ,
V_48 -> V_92 ) ;
if ( V_18 != 0 ) {
F_9 ( V_16 , L_47 ,
V_18 ) ;
goto V_88;
}
} else if ( F_33 ( V_13 -> V_52 [ 0 ] ) ) {
V_18 = F_54 ( V_48 -> V_90 ,
V_48 -> V_89 ) ;
if ( V_18 != 0 ) {
F_9 ( V_16 , L_48 ,
V_18 ) ;
goto V_88;
}
}
if ( F_31 ( V_13 -> V_52 [ 1 ] ) ) {
V_18 = F_54 ( V_48 -> V_91 ,
V_48 -> V_93 ) ;
if ( V_18 != 0 ) {
F_9 ( V_16 , L_49 ,
V_18 ) ;
goto V_88;
}
} else if ( F_33 ( V_13 -> V_52 [ 1 ] ) ) {
V_18 = F_54 ( V_48 -> V_91 ,
V_48 -> V_89 ) ;
if ( V_18 != 0 ) {
F_9 ( V_16 , L_50 ,
V_18 ) ;
goto V_88;
}
}
V_94:
F_35 ( V_16 ) ;
if ( V_16 -> V_80 ) {
V_18 = F_55 ( V_16 -> V_80 ,
V_96 , NULL , V_16 ) ;
if ( V_18 ) {
F_9 ( V_16 , L_51 , V_18 ) ;
goto V_88;
}
} else {
V_18 = F_16 ( V_24 ) ;
if ( V_18 ) {
F_9 ( V_16 , L_52 ,
V_18 ) ;
goto V_88;
}
}
return 0 ;
V_88:
F_56 ( V_16 ) ;
return V_18 ;
}
static int F_57 ( struct V_15 * V_16 , void * V_97 )
{
F_45 ( V_16 , L_53 ) ;
F_19 ( F_58 ( V_16 ) ) ;
return 0 ;
}
static int F_59 ( struct V_8 * V_24 )
{
F_56 ( & V_24 -> V_16 ) ;
F_60 ( & V_24 -> V_16 , NULL , F_57 ) ;
return 0 ;
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_98 , F_43 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_98 ) ;
}
