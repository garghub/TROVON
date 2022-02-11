static inline bool F_1 ( int V_1 )
{
return ( V_1 == 4 ) ;
}
static const char * const F_2 ( struct V_2 * V_3 )
{
switch ( V_3 -> V_4 ) {
case 0x00000413 :
return L_1 ;
case 0xc0000408 :
return L_2 ;
case 0xc0000409 :
return L_3 ;
default:
F_3 ( 1 , L_4 , V_3 -> V_4 ) ;
return L_5 ;
}
}
static bool F_4 ( unsigned int V_1 , T_1 V_5 )
{
if ( V_1 == 4 )
return true ;
return V_5 & F_5 ( 28 ) ;
}
static int F_6 ( struct V_2 * V_3 , int V_6 , T_1 V_7 , T_1 V_8 )
{
int V_9 = ( V_8 & V_10 ) >> 20 ;
if ( V_6 < 0 ) {
F_7 ( V_11 L_6
L_7 , V_3 -> V_12 ,
V_3 -> V_1 , V_3 -> V_13 , V_3 -> V_4 , V_8 , V_7 ) ;
return 0 ;
}
if ( V_6 != V_9 ) {
F_7 ( V_11 L_8
L_7 ,
V_3 -> V_12 , V_6 , V_3 -> V_1 , V_3 -> V_13 , V_3 -> V_4 , V_8 , V_7 ) ;
return 0 ;
}
return 1 ;
}
static void F_8 ( void * V_14 )
{
struct V_15 * V_16 = V_14 ;
T_1 V_8 , V_7 ;
F_9 ( V_16 -> V_3 -> V_4 , V_7 , V_8 ) ;
if ( V_16 -> V_3 -> V_17 < ( V_8 & V_18 ) )
V_16 -> V_19 = 1 ;
if ( V_16 -> V_19 ) {
V_8 =
( V_8 & ~ ( V_20 | V_21 ) ) |
( V_18 - V_16 -> V_3 -> V_17 ) ;
} else if ( V_16 -> V_22 ) {
int V_23 = ( V_8 & V_18 ) +
( V_16 -> V_22 - V_16 -> V_3 -> V_17 ) ;
V_8 = ( V_8 & ~ V_20 ) |
( V_23 & V_18 ) ;
}
V_8 &= ~ V_24 ;
if ( ! V_16 -> V_3 -> V_25 )
goto V_26;
if ( V_16 -> V_27 ) {
if ( F_6 ( V_16 -> V_3 , V_16 -> V_28 , V_7 , V_8 ) ) {
V_8 &= ~ V_10 ;
V_8 |= V_16 -> V_28 << 20 ;
}
}
if ( V_16 -> V_3 -> V_29 )
V_8 |= V_30 ;
V_26:
V_8 |= V_31 ;
F_10 ( V_16 -> V_3 -> V_4 , V_7 , V_8 ) ;
}
static void F_11 ( struct V_2 * V_3 , int V_32 )
{
struct V_15 V_16 = {
. V_3 = V_3 ,
. V_27 = 1 ,
. V_28 = V_32 ,
} ;
V_3 -> V_17 = V_18 ;
F_8 ( & V_16 ) ;
}
static int F_12 ( int V_33 , int V_34 )
{
if ( V_33 < 0 && ! F_13 ( V_34 , V_35 ,
V_36 , 0 ) )
return V_34 ;
return V_33 ;
}
void F_14 ( struct V_37 * V_38 )
{
struct V_2 V_3 ;
unsigned int V_12 = F_15 () ;
T_1 V_39 = 0 , V_40 = 0 , V_4 = 0 ;
unsigned int V_1 , V_13 ;
int V_32 = - 1 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
for ( V_13 = 0 ; V_13 < V_43 ; ++ V_13 ) {
if ( V_13 == 0 )
V_4 = V_44 + V_1 * 4 ;
else if ( V_13 == 1 ) {
V_4 = ( V_39 & V_45 ) >> 21 ;
if ( ! V_4 )
break;
V_4 += V_46 ;
} else
++ V_4 ;
if ( F_16 ( V_4 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_47 ) )
continue;
if ( ! ( V_40 & V_48 ) ||
( V_40 & V_49 ) )
continue;
if ( ! V_13 )
F_17 ( V_50 , V_12 ) |= ( 1 << V_1 ) ;
memset ( & V_3 , 0 , sizeof( V_3 ) ) ;
V_3 . V_12 = V_12 ;
V_3 . V_1 = V_1 ;
V_3 . V_13 = V_13 ;
V_3 . V_4 = V_4 ;
V_3 . V_25 = F_4 ( V_1 , V_40 ) ;
if ( V_3 . V_25 ) {
int V_34 = ( V_40 & V_10 ) >> 20 ;
V_32 = F_12 ( V_32 , V_34 ) ;
}
F_11 ( & V_3 , V_32 ) ;
V_51 = V_52 ;
}
}
}
static void V_52 ( void )
{
T_1 V_39 = 0 , V_40 = 0 , V_4 = 0 ;
unsigned int V_1 , V_13 ;
struct V_53 V_54 ;
F_18 ( & V_54 ) ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
if ( ! ( F_17 ( V_50 , V_54 . V_12 ) & ( 1 << V_1 ) ) )
continue;
for ( V_13 = 0 ; V_13 < V_43 ; ++ V_13 ) {
if ( V_13 == 0 ) {
V_4 = V_44 + V_1 * 4 ;
} else if ( V_13 == 1 ) {
V_4 = ( V_39 & V_45 ) >> 21 ;
if ( ! V_4 )
break;
V_4 += V_46 ;
} else {
++ V_4 ;
}
if ( F_16 ( V_4 , & V_39 , & V_40 ) )
break;
if ( ! ( V_40 & V_47 ) ) {
if ( V_13 )
continue;
else
break;
}
if ( ! ( V_40 & V_48 ) ||
( V_40 & V_49 ) )
continue;
F_19 ( V_55 ,
F_20 ( & V_56 ) ) ;
if ( V_40 & V_21 ) {
F_21 ( V_4 , V_54 . V_57 ) ;
F_21 ( V_58 + V_1 * 4 ,
V_54 . V_59 ) ;
V_54 . V_1 = V_60
+ V_1 * V_43
+ V_13 ;
F_22 ( & V_54 ) ;
return;
}
}
}
}
static T_2
F_23 ( struct V_2 * V_3 , const char * V_61 , T_3 V_62 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( ! V_3 -> V_25 )
return - V_63 ;
if ( F_24 ( V_61 , 0 , & V_34 ) < 0 )
return - V_63 ;
V_3 -> V_29 = ! ! V_34 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_3 = V_3 ;
F_25 ( V_3 -> V_12 , F_8 , & V_16 , 1 ) ;
return V_62 ;
}
static T_2
F_26 ( struct V_2 * V_3 , const char * V_61 , T_3 V_62 )
{
struct V_15 V_16 ;
unsigned long V_34 ;
if ( F_24 ( V_61 , 0 , & V_34 ) < 0 )
return - V_63 ;
if ( V_34 > V_18 )
V_34 = V_18 ;
if ( V_34 < 1 )
V_34 = 1 ;
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
V_16 . V_22 = V_3 -> V_17 ;
V_3 -> V_17 = V_34 ;
V_16 . V_3 = V_3 ;
F_25 ( V_3 -> V_12 , F_8 , & V_16 , 1 ) ;
return V_62 ;
}
static T_2 F_27 ( struct V_2 * V_3 , char * V_61 )
{
T_1 V_7 , V_8 ;
F_28 ( V_3 -> V_12 , V_3 -> V_4 , & V_7 , & V_8 ) ;
return sprintf ( V_61 , L_9 , ( ( V_8 & V_18 ) -
( V_18 - V_3 -> V_17 ) ) ) ;
}
static T_2 F_29 ( struct V_64 * V_65 , struct V_66 * V_67 , char * V_61 )
{
struct V_2 * V_3 = F_30 ( V_65 ) ;
struct V_68 * V_69 = F_31 ( V_67 ) ;
T_2 V_70 ;
V_70 = V_69 -> F_29 ? V_69 -> F_29 ( V_3 , V_61 ) : - V_71 ;
return V_70 ;
}
static T_2 F_32 ( struct V_64 * V_65 , struct V_66 * V_67 ,
const char * V_61 , T_3 V_72 )
{
struct V_2 * V_3 = F_30 ( V_65 ) ;
struct V_68 * V_69 = F_31 ( V_67 ) ;
T_2 V_70 ;
V_70 = V_69 -> F_32 ? V_69 -> F_32 ( V_3 , V_61 , V_72 ) : - V_71 ;
return V_70 ;
}
static int F_33 ( unsigned int V_12 , unsigned int V_1 ,
unsigned int V_13 , T_1 V_4 )
{
struct V_2 * V_3 = NULL ;
T_1 V_39 , V_40 ;
int V_73 ;
if ( ( V_1 >= V_41 . V_42 ) || ( V_13 >= V_43 ) )
return 0 ;
if ( F_34 ( V_12 , V_4 , & V_39 , & V_40 ) )
return 0 ;
if ( ! ( V_40 & V_47 ) ) {
if ( V_13 )
goto V_74;
else
return 0 ;
}
if ( ! ( V_40 & V_48 ) ||
( V_40 & V_49 ) )
goto V_74;
V_3 = F_35 ( sizeof( struct V_2 ) , V_75 ) ;
if ( ! V_3 )
return - V_76 ;
V_3 -> V_13 = V_13 ;
V_3 -> V_1 = V_1 ;
V_3 -> V_12 = V_12 ;
V_3 -> V_4 = V_4 ;
V_3 -> V_29 = 0 ;
V_3 -> V_25 = F_4 ( V_1 , V_40 ) ;
V_3 -> V_17 = V_18 ;
if ( V_3 -> V_25 )
V_77 . V_78 [ 2 ] = & V_29 . V_67 ;
else
V_77 . V_78 [ 2 ] = NULL ;
F_36 ( & V_3 -> V_79 ) ;
if ( F_17 ( V_80 , V_12 ) [ V_1 ] -> V_81 ) {
F_37 ( & V_3 -> V_79 ,
& F_17 ( V_80 , V_12 ) [ V_1 ] -> V_81 -> V_79 ) ;
} else {
F_17 ( V_80 , V_12 ) [ V_1 ] -> V_81 = V_3 ;
}
V_73 = F_38 ( & V_3 -> V_65 , & V_77 ,
F_17 ( V_80 , V_12 ) [ V_1 ] -> V_65 ,
( V_1 == 4 ? F_2 ( V_3 ) : V_82 [ V_1 ] ) ) ;
if ( V_73 )
goto V_83;
V_74:
if ( ! V_13 ) {
V_4 = ( V_39 & V_45 ) >> 21 ;
if ( ! V_4 )
return 0 ;
V_4 += V_46 ;
} else {
++ V_4 ;
}
V_73 = F_33 ( V_12 , V_1 , ++ V_13 , V_4 ) ;
if ( V_73 )
goto V_83;
if ( V_3 )
F_39 ( & V_3 -> V_65 , V_84 ) ;
return V_73 ;
V_83:
if ( V_3 ) {
F_40 ( & V_3 -> V_65 ) ;
F_41 ( & V_3 -> V_79 ) ;
F_42 ( V_3 ) ;
}
return V_73 ;
}
static int F_43 ( struct V_85 * V_3 )
{
struct V_86 * V_87 = & V_3 -> V_81 -> V_79 ;
struct V_2 * V_88 = NULL ;
struct V_2 * V_89 = NULL ;
int V_73 = 0 ;
V_73 = F_44 ( & V_3 -> V_81 -> V_65 , V_3 -> V_65 , V_3 -> V_81 -> V_65 . V_90 ) ;
if ( V_73 )
return V_73 ;
F_45 (pos, tmp, head, miscj) {
V_73 = F_44 ( & V_88 -> V_65 , V_3 -> V_65 , V_88 -> V_65 . V_90 ) ;
if ( V_73 ) {
F_46 (pos, tmp, head, miscj)
F_47 ( & V_88 -> V_65 ) ;
return V_73 ;
}
}
return V_73 ;
}
static int F_48 ( unsigned int V_12 , unsigned int V_1 )
{
struct V_91 * V_92 = F_17 ( V_93 , V_12 ) ;
struct V_94 * V_95 = NULL ;
struct V_85 * V_3 = NULL ;
const char * V_90 = V_82 [ V_1 ] ;
int V_73 = 0 ;
if ( F_1 ( V_1 ) ) {
V_95 = F_49 ( F_50 ( V_12 ) ) ;
if ( V_95 && V_95 -> V_96 ) {
V_3 = V_95 -> V_96 ;
V_73 = F_44 ( V_3 -> V_65 , & V_92 -> V_65 , V_90 ) ;
if ( V_73 )
goto V_97;
F_17 ( V_80 , V_12 ) [ V_1 ] = V_3 ;
F_51 ( & V_3 -> V_98 ) ;
V_73 = F_43 ( V_3 ) ;
goto V_97;
}
}
V_3 = F_35 ( sizeof( struct V_85 ) , V_75 ) ;
if ( ! V_3 ) {
V_73 = - V_76 ;
goto V_97;
}
V_3 -> V_65 = F_52 ( V_90 , & V_92 -> V_65 ) ;
if ( ! V_3 -> V_65 ) {
V_73 = - V_63 ;
goto V_83;
}
F_17 ( V_80 , V_12 ) [ V_1 ] = V_3 ;
if ( F_1 ( V_1 ) ) {
F_53 ( & V_3 -> V_98 , 1 ) ;
if ( V_95 ) {
F_54 ( V_95 -> V_96 ) ;
V_95 -> V_96 = V_3 ;
}
}
V_73 = F_33 ( V_12 , V_1 , 0 ,
V_44 + V_1 * 4 ) ;
if ( ! V_73 )
goto V_97;
V_83:
F_42 ( V_3 ) ;
V_97:
return V_73 ;
}
static int F_55 ( unsigned int V_12 )
{
unsigned int V_1 ;
struct V_85 * * V_99 ;
int V_73 = 0 ;
V_99 = F_35 ( sizeof( struct V_85 * ) * V_41 . V_42 ,
V_75 ) ;
if ( ! V_99 )
return - V_76 ;
F_17 ( V_80 , V_12 ) = V_99 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
if ( ! ( F_17 ( V_50 , V_12 ) & ( 1 << V_1 ) ) )
continue;
V_73 = F_48 ( V_12 , V_1 ) ;
if ( V_73 )
return V_73 ;
}
return V_73 ;
}
static void F_56 ( unsigned int V_12 ,
unsigned int V_1 )
{
struct V_2 * V_88 = NULL ;
struct V_2 * V_89 = NULL ;
struct V_85 * V_87 = F_17 ( V_80 , V_12 ) [ V_1 ] ;
if ( ! V_87 )
return;
F_45 (pos, tmp, &head->blocks->miscj, miscj) {
F_40 ( & V_88 -> V_65 ) ;
F_41 ( & V_88 -> V_79 ) ;
F_42 ( V_88 ) ;
}
F_42 ( F_17 ( V_80 , V_12 ) [ V_1 ] -> V_81 ) ;
F_17 ( V_80 , V_12 ) [ V_1 ] -> V_81 = NULL ;
}
static void F_57 ( struct V_85 * V_3 )
{
struct V_2 * V_88 = NULL ;
struct V_2 * V_89 = NULL ;
F_47 ( V_3 -> V_65 ) ;
F_45 (pos, tmp, &b->blocks->miscj, miscj)
F_47 ( & V_88 -> V_65 ) ;
}
static void F_58 ( unsigned int V_12 , int V_1 )
{
struct V_94 * V_95 ;
struct V_85 * V_3 ;
V_3 = F_17 ( V_80 , V_12 ) [ V_1 ] ;
if ( ! V_3 )
return;
if ( ! V_3 -> V_81 )
goto V_100;
if ( F_1 ( V_1 ) ) {
if ( ! F_59 ( & V_3 -> V_98 ) ) {
F_57 ( V_3 ) ;
F_17 ( V_80 , V_12 ) [ V_1 ] = NULL ;
return;
} else {
V_95 = F_49 ( F_50 ( V_12 ) ) ;
V_95 -> V_96 = NULL ;
}
}
F_56 ( V_12 , V_1 ) ;
V_100:
F_47 ( V_3 -> V_65 ) ;
F_40 ( V_3 -> V_65 ) ;
F_42 ( V_3 ) ;
F_17 ( V_80 , V_12 ) [ V_1 ] = NULL ;
}
static void F_60 ( unsigned int V_12 )
{
unsigned int V_1 ;
for ( V_1 = 0 ; V_1 < V_41 . V_42 ; ++ V_1 ) {
if ( ! ( F_17 ( V_50 , V_12 ) & ( 1 << V_1 ) ) )
continue;
F_58 ( V_12 , V_1 ) ;
}
F_42 ( F_17 ( V_80 , V_12 ) ) ;
}
static void
F_61 ( unsigned long V_101 , unsigned int V_12 )
{
switch ( V_101 ) {
case V_102 :
case V_103 :
F_55 ( V_12 ) ;
break;
case V_104 :
case V_105 :
F_60 ( V_12 ) ;
break;
default:
break;
}
}
static T_4 int F_62 ( void )
{
unsigned V_106 = 0 ;
F_63 (lcpu) {
int V_73 = F_55 ( V_106 ) ;
if ( V_73 )
return V_73 ;
}
V_107 = F_61 ;
return 0 ;
}
