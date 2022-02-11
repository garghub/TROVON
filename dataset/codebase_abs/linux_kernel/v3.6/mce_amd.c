static const char * const F_1 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_3 ) {
case 0x00000413 :
return L_1 ;
case 0xc0000408 :
return L_2 ;
case 0xc0000409 :
return L_3 ;
default:
F_2 ( 1 , L_4 , V_2 -> V_3 ) ;
return L_5 ;
}
}
static bool F_3 ( unsigned int V_4 , T_1 V_5 )
{
if ( V_4 == 4 )
return true ;
return V_5 & F_4 ( 28 ) ;
}
static int F_5 ( struct V_1 * V_2 , int V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 = ( V_8 & V_10 ) >> 20 ;
if ( V_6 < 0 ) {
F_6 ( V_11 L_6
L_7 , V_2 -> V_12 ,
V_2 -> V_4 , V_2 -> V_13 , V_2 -> V_3 , V_8 , V_7 ) ;
return 0 ;
}
if ( V_6 != V_9 ) {
F_6 ( V_11 L_8
L_7 ,
V_2 -> V_12 , V_6 , V_2 -> V_4 , V_2 -> V_13 , V_2 -> V_3 , V_8 , V_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_7 ( void * V_14 )
{
struct V_15 * V_16 = V_14 ;
T_1 V_8 , V_7 ;
F_8 ( V_16 -> V_2 -> V_3 , V_7 , V_8 ) ;
if ( V_16 -> V_2 -> V_17 < ( V_8 & V_18 ) )
V_16 -> V_19 = 1 ;
if ( V_16 -> V_19 ) {
V_8 =
( V_8 & ~ ( V_20 | V_21 ) ) |
( V_18 - V_16 -> V_2 -> V_17 ) ;
} else if ( V_16 -> V_22 ) {
int V_23 = ( V_8 & V_18 ) +
( V_16 -> V_22 - V_16 -> V_2 -> V_17 ) ;
V_8 = ( V_8 & ~ V_20 ) |
( V_23 & V_18 ) ;
}
V_8 &= ~ V_24 ;
if ( ! V_16 -> V_2 -> V_25 )
goto V_26;
if ( V_16 -> V_27 ) {
if ( F_5 ( V_16 -> V_2 , V_16 -> V_28 , V_7 , V_8 ) ) {
V_8 &= ~ V_10 ;
V_8 |= V_16 -> V_28 << 20 ;
}
}
if ( V_16 -> V_2 -> V_29 )
V_8 |= V_30 ;
V_26:
V_8 |= V_31 ;
F_9 ( V_16 -> V_2 -> V_3 , V_7 , V_8 ) ;
}
static void F_10 ( struct V_1 * V_2 , int V_32 )
{
struct V_15 V_16 = {
. V_2 = V_2 ,
. V_27 = 1 ,
. V_28 = V_32 ,
} ;
V_2 -> V_17 = V_18 ;
F_7 ( & V_16 ) ;
}
static int F_11 ( int V_33 , int V_34 )
{
if ( V_33 < 0 && ! F_12 ( V_34 , V_35 ,
V_36 , 0 ) )
return V_34 ;
return V_33 ;
}
void F_13 ( struct V_37 * V_38 )
{
struct V_1 V_2 ;
unsigned int V_12 = F_14 () ;
T_1 V_39 = 0 , V_40 = 0 , V_3 = 0 ;
unsigned int V_4 , V_13 ;
int V_32 = - 1 ;
for ( V_4 = 0 ; V_4 < V_41 ; ++ V_4 ) {
for ( V_13 = 0 ; V_13 < V_42 ; ++ V_13 ) {
if ( V_13 == 0 )
V_3 = V_43 + V_4 * 4 ;
else if ( V_13 == 1 ) {
V_3 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_3 )
break;
V_3 += V_45 ;
} else
++ V_3 ;
if ( F_15 ( V_3 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_46 ) )
continue;
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
continue;
if ( ! V_13 )
F_16 ( V_49 , V_12 ) |= ( 1 << V_4 ) ;
memset ( & V_2 , 0 , sizeof( V_2 ) ) ;
V_2 . V_12 = V_12 ;
V_2 . V_4 = V_4 ;
V_2 . V_13 = V_13 ;
V_2 . V_3 = V_3 ;
V_2 . V_25 = F_3 ( V_4 , V_40 ) ;
if ( V_2 . V_25 ) {
int V_34 = ( V_40 & V_10 ) >> 20 ;
V_32 = F_11 ( V_32 , V_34 ) ;
}
F_10 ( & V_2 , V_32 ) ;
V_50 = V_51 ;
}
}
}
static void V_51 ( void )
{
T_1 V_39 = 0 , V_40 = 0 , V_3 = 0 ;
unsigned int V_4 , V_13 ;
struct V_52 V_53 ;
F_17 ( & V_53 ) ;
for ( V_4 = 0 ; V_4 < V_41 ; ++ V_4 ) {
if ( ! ( F_16 ( V_49 , V_53 . V_12 ) & ( 1 << V_4 ) ) )
continue;
for ( V_13 = 0 ; V_13 < V_42 ; ++ V_13 ) {
if ( V_13 == 0 ) {
V_3 = V_43 + V_4 * 4 ;
} else if ( V_13 == 1 ) {
V_3 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_3 )
break;
V_3 += V_45 ;
} else {
++ V_3 ;
}
if ( F_15 ( V_3 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_46 ) ) {
if ( V_13 )
continue;
else
break;
}
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
continue;
F_18 ( V_54 ,
& F_19 ( V_55 ) ) ;
if ( V_40 & V_21 ) {
F_20 ( V_3 , V_53 . V_56 ) ;
F_20 ( V_57 + V_4 * 4 ,
V_53 . V_58 ) ;
V_53 . V_4 = V_59
+ V_4 * V_42
+ V_13 ;
F_21 ( & V_53 ) ;
return;
}
}
}
}
static T_2
F_22 ( struct V_1 * V_2 , const char * V_60 , T_3 V_61 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( ! V_2 -> V_25 )
return - V_62 ;
if ( F_23 ( V_60 , 0 , & V_34 ) < 0 )
return - V_62 ;
V_2 -> V_29 = ! ! V_34 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_2 = V_2 ;
F_24 ( V_2 -> V_12 , F_7 , & V_16 , 1 ) ;
return V_61 ;
}
static T_2
F_25 ( struct V_1 * V_2 , const char * V_60 , T_3 V_61 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( F_23 ( V_60 , 0 , & V_34 ) < 0 )
return - V_62 ;
if ( V_34 > V_18 )
V_34 = V_18 ;
if ( V_34 < 1 )
V_34 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_22 = V_2 -> V_17 ;
V_2 -> V_17 = V_34 ;
V_16 . V_2 = V_2 ;
F_24 ( V_2 -> V_12 , F_7 , & V_16 , 1 ) ;
return V_61 ;
}
static T_2 F_26 ( struct V_1 * V_2 , char * V_60 )
{
T_1 V_7 , V_8 ;
F_27 ( V_2 -> V_12 , V_2 -> V_3 , & V_7 , & V_8 ) ;
return sprintf ( V_60 , L_9 , ( ( V_8 & V_18 ) -
( V_18 - V_2 -> V_17 ) ) ) ;
}
static T_2 F_28 ( struct V_63 * V_64 , struct V_65 * V_66 , char * V_60 )
{
struct V_1 * V_2 = F_29 ( V_64 ) ;
struct V_67 * V_68 = F_30 ( V_66 ) ;
T_2 V_69 ;
V_69 = V_68 -> F_28 ? V_68 -> F_28 ( V_2 , V_60 ) : - V_70 ;
return V_69 ;
}
static T_2 F_31 ( struct V_63 * V_64 , struct V_65 * V_66 ,
const char * V_60 , T_3 V_71 )
{
struct V_1 * V_2 = F_29 ( V_64 ) ;
struct V_67 * V_68 = F_30 ( V_66 ) ;
T_2 V_69 ;
V_69 = V_68 -> F_31 ? V_68 -> F_31 ( V_2 , V_60 , V_71 ) : - V_70 ;
return V_69 ;
}
static T_4 int F_32 ( unsigned int V_12 ,
unsigned int V_4 ,
unsigned int V_13 ,
T_1 V_3 )
{
struct V_1 * V_2 = NULL ;
T_1 V_39 , V_40 ;
int V_72 ;
if ( ( V_4 >= V_41 ) || ( V_13 >= V_42 ) )
return 0 ;
if ( F_33 ( V_12 , V_3 , & V_39 , & V_40 ) )
return 0 ;
if ( ! ( V_40 & V_46 ) ) {
if ( V_13 )
goto V_73;
else
return 0 ;
}
if ( ! ( V_40 & V_47 ) ||
( V_40 & V_48 ) )
goto V_73;
V_2 = F_34 ( sizeof( struct V_1 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_2 -> V_13 = V_13 ;
V_2 -> V_4 = V_4 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_29 = 0 ;
V_2 -> V_25 = F_3 ( V_4 , V_40 ) ;
V_2 -> V_17 = V_18 ;
if ( V_2 -> V_25 )
V_76 . V_77 [ 2 ] = & V_29 . V_66 ;
else
V_76 . V_77 [ 2 ] = NULL ;
F_35 ( & V_2 -> V_78 ) ;
if ( F_16 ( V_79 , V_12 ) [ V_4 ] -> V_80 ) {
F_36 ( & V_2 -> V_78 ,
& F_16 ( V_79 , V_12 ) [ V_4 ] -> V_80 -> V_78 ) ;
} else {
F_16 ( V_79 , V_12 ) [ V_4 ] -> V_80 = V_2 ;
}
V_72 = F_37 ( & V_2 -> V_64 , & V_76 ,
F_16 ( V_79 , V_12 ) [ V_4 ] -> V_64 ,
( V_4 == 4 ? F_1 ( V_2 ) : V_81 [ V_4 ] ) ) ;
if ( V_72 )
goto V_82;
V_73:
if ( ! V_13 ) {
V_3 = ( V_39 & V_44 ) >> 21 ;
if ( ! V_3 )
return 0 ;
V_3 += V_45 ;
} else {
++ V_3 ;
}
V_72 = F_32 ( V_12 , V_4 , ++ V_13 , V_3 ) ;
if ( V_72 )
goto V_82;
if ( V_2 )
F_38 ( & V_2 -> V_64 , V_83 ) ;
return V_72 ;
V_82:
if ( V_2 ) {
F_39 ( & V_2 -> V_64 ) ;
F_40 ( & V_2 -> V_78 ) ;
F_41 ( V_2 ) ;
}
return V_72 ;
}
static T_4 int F_42 ( struct V_84 * V_2 )
{
struct V_85 * V_86 = & V_2 -> V_80 -> V_78 ;
struct V_1 * V_87 = NULL ;
struct V_1 * V_88 = NULL ;
int V_72 = 0 ;
V_72 = F_43 ( & V_2 -> V_80 -> V_64 , V_2 -> V_64 , V_2 -> V_80 -> V_64 . V_89 ) ;
if ( V_72 )
return V_72 ;
F_44 (pos, tmp, head, miscj) {
V_72 = F_43 ( & V_87 -> V_64 , V_2 -> V_64 , V_87 -> V_64 . V_89 ) ;
if ( V_72 ) {
F_45 (pos, tmp, head, miscj)
F_46 ( & V_87 -> V_64 ) ;
return V_72 ;
}
}
return V_72 ;
}
static T_4 int F_47 ( unsigned int V_12 , unsigned int V_4 )
{
struct V_90 * V_91 = F_16 ( V_92 , V_12 ) ;
struct V_93 * V_94 = NULL ;
struct V_84 * V_2 = NULL ;
const char * V_89 = V_81 [ V_4 ] ;
int V_72 = 0 ;
if ( V_95 [ V_4 ] ) {
V_94 = F_48 ( F_49 ( V_12 ) ) ;
F_50 ( ! V_94 ) ;
if ( V_94 -> V_96 ) {
V_2 = V_94 -> V_96 ;
V_72 = F_43 ( V_2 -> V_64 , & V_91 -> V_64 , V_89 ) ;
if ( V_72 )
goto V_97;
F_16 ( V_79 , V_12 ) [ V_4 ] = V_2 ;
F_51 ( & V_2 -> V_98 ) ;
V_72 = F_42 ( V_2 ) ;
goto V_97;
}
}
V_2 = F_34 ( sizeof( struct V_84 ) , V_74 ) ;
if ( ! V_2 ) {
V_72 = - V_75 ;
goto V_97;
}
V_2 -> V_64 = F_52 ( V_89 , & V_91 -> V_64 ) ;
if ( ! V_2 -> V_64 ) {
V_72 = - V_62 ;
goto V_82;
}
F_16 ( V_79 , V_12 ) [ V_4 ] = V_2 ;
if ( V_95 [ V_4 ] ) {
F_53 ( & V_2 -> V_98 , 1 ) ;
F_50 ( V_94 -> V_96 ) ;
V_94 -> V_96 = V_2 ;
}
V_72 = F_32 ( V_12 , V_4 , 0 ,
V_43 + V_4 * 4 ) ;
if ( ! V_72 )
goto V_97;
V_82:
F_41 ( V_2 ) ;
V_97:
return V_72 ;
}
static T_4 int F_54 ( unsigned int V_12 )
{
unsigned int V_4 ;
int V_72 = 0 ;
for ( V_4 = 0 ; V_4 < V_41 ; ++ V_4 ) {
if ( ! ( F_16 ( V_49 , V_12 ) & ( 1 << V_4 ) ) )
continue;
V_72 = F_47 ( V_12 , V_4 ) ;
if ( V_72 )
return V_72 ;
}
return V_72 ;
}
static void F_55 ( unsigned int V_12 ,
unsigned int V_4 )
{
struct V_1 * V_87 = NULL ;
struct V_1 * V_88 = NULL ;
struct V_84 * V_86 = F_16 ( V_79 , V_12 ) [ V_4 ] ;
if ( ! V_86 )
return;
F_44 (pos, tmp, &head->blocks->miscj, miscj) {
F_39 ( & V_87 -> V_64 ) ;
F_40 ( & V_87 -> V_78 ) ;
F_41 ( V_87 ) ;
}
F_41 ( F_16 ( V_79 , V_12 ) [ V_4 ] -> V_80 ) ;
F_16 ( V_79 , V_12 ) [ V_4 ] -> V_80 = NULL ;
}
static void F_56 ( struct V_84 * V_2 )
{
struct V_1 * V_87 = NULL ;
struct V_1 * V_88 = NULL ;
F_46 ( V_2 -> V_64 ) ;
F_44 (pos, tmp, &b->blocks->miscj, miscj)
F_46 ( & V_87 -> V_64 ) ;
}
static void F_57 ( unsigned int V_12 , int V_4 )
{
struct V_93 * V_94 ;
struct V_84 * V_2 ;
V_2 = F_16 ( V_79 , V_12 ) [ V_4 ] ;
if ( ! V_2 )
return;
if ( ! V_2 -> V_80 )
goto V_99;
if ( V_95 [ V_4 ] ) {
if ( ! F_58 ( & V_2 -> V_98 ) ) {
F_56 ( V_2 ) ;
F_16 ( V_79 , V_12 ) [ V_4 ] = NULL ;
return;
} else {
V_94 = F_48 ( F_49 ( V_12 ) ) ;
V_94 -> V_96 = NULL ;
}
}
F_55 ( V_12 , V_4 ) ;
V_99:
F_46 ( V_2 -> V_64 ) ;
F_39 ( V_2 -> V_64 ) ;
F_41 ( V_2 ) ;
F_16 ( V_79 , V_12 ) [ V_4 ] = NULL ;
}
static void F_59 ( unsigned int V_12 )
{
unsigned int V_4 ;
for ( V_4 = 0 ; V_4 < V_41 ; ++ V_4 ) {
if ( ! ( F_16 ( V_49 , V_12 ) & ( 1 << V_4 ) ) )
continue;
F_57 ( V_12 , V_4 ) ;
}
}
static void T_4
F_60 ( unsigned long V_100 , unsigned int V_12 )
{
switch ( V_100 ) {
case V_101 :
case V_102 :
F_54 ( V_12 ) ;
break;
case V_103 :
case V_104 :
F_59 ( V_12 ) ;
break;
default:
break;
}
}
static T_5 int F_61 ( void )
{
unsigned V_105 = 0 ;
F_62 (lcpu) {
int V_72 = F_54 ( V_105 ) ;
if ( V_72 )
return V_72 ;
}
V_106 = F_60 ;
return 0 ;
}
