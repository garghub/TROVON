static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_6 = V_2 -> V_7 ;
int V_8 = 0xffff ;
while ( V_8 -- ) {
if ( ( V_3 & F_2 ( V_6 ) ) == V_3 )
return 0 ;
F_3 ( 100 ) ;
}
F_4 ( V_5 -> V_5 , L_1 ,
F_2 ( V_6 ) ) ;
return - V_9 ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( 1 << 2 ) | ( 1 << 10 ) | ( 1 << 18 )
| ( 1 << 26 ) | ( 1 << 27 ) | ( 1 << 28 ) ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( 1 << 10 ) | ( 1 << 26 ) ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( 1 << 2 ) | ( 1 << 18 ) ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
return F_1 ( V_2 , ( 1 << 27 ) ) ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
T_1 V_10 = V_2 -> V_11 ;
struct V_4 * V_5 = V_2 -> V_5 ;
switch ( V_3 ) {
case ( 1 << 0 ) :
case ( 1 << 1 ) :
case ( 1 << 2 ) :
case ( 1 << 3 ) :
case ( 1 << 4 ) :
case ( 1 << 5 ) :
case ( 1 << 6 ) :
case ( 1 << 7 ) :
case ( 1 << 8 ) :
case ( 1 << 9 ) :
case ( 1 << 10 ) :
case ( 1 << 11 ) :
case ( 1 << 12 ) :
case ( 1 << 13 ) :
break;
case ( 1 << 14 ) :
;
break;
case ( 1 << 15 ) :
break;
case ( 1 << 16 ) :
break;
case ( 1 << 17 ) :
break;
case ( 1 << 18 ) :
case ( 1 << 19 ) :
if ( 0 )
F_5 ( V_2 ) ;
break;
case ( 1 << 20 ) :
break;
case ( 1 << 21 ) :
break;
case ( 1 << 22 ) :
break;
case ( 1 << 23 ) :
case ( 1 << 24 ) :
case ( 1 << 25 ) :
case ( 1 << 26 ) :
case ( 1 << 27 ) :
F_10 ( V_10 , V_3 ) ;
F_7 ( V_2 ) ;
break;
case ( 1 << 28 ) :
F_10 ( V_10 , V_3 ) ;
F_6 ( V_2 ) ;
break;
case ( 1 << 29 ) :
case ( 1 << 30 ) :
case ( 1 << 31 ) :
break;
}
if ( V_3 & F_2 ( V_10 ) )
F_11 ( V_5 -> V_5 , L_2 , V_3 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_10 = V_2 -> V_11 ;
T_1 V_3 ;
T_1 V_12 ;
int V_13 ;
int V_14 = 0 ;
V_12 = F_2 ( V_10 ) ;
for ( V_13 = 0 ; V_13 < 32 ; V_13 ++ ) {
V_3 = ( 0x00000001UL ) << V_13 ;
if ( V_12 & V_3 ) {
F_13 ( V_5 -> V_5 , L_3 , V_15 [ V_13 ] ) ;
V_14 = F_9 ( V_2 , V_3 ) ;
if ( V_14 )
F_4 ( V_5 -> V_5 , L_4 ) ;
}
}
return V_14 ;
}
static inline int F_14 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_8 = 0xffff ;
T_1 V_16 = V_2 -> V_17 ;
while ( V_8 -- ) {
if ( ! ( F_2 ( V_16 ) & ( 1 << 0 ) ) )
break;
}
if ( ! V_8 ) {
F_4 ( V_5 -> V_5 , L_5 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_21 * V_22 = & V_20 -> V_20 . V_22 ;
T_1 V_23 = V_2 -> V_24 ;
T_1 V_16 = V_2 -> V_17 ;
T_1 V_25 = V_2 -> V_26 ;
T_1 V_27 = 0 ;
T_2 * V_28 = ( T_2 * ) V_2 -> V_29 ;
int V_13 ;
int V_30 ;
if ( ! V_2 -> V_31 ) {
F_4 ( V_5 -> V_5 , L_6 ) ;
return - V_32 ;
}
F_8 ( V_2 ) ;
* ( V_28 + ( V_27 ++ ) ) = V_22 -> V_33 ;
if ( V_22 -> V_34 ) {
for ( V_13 = 0 ; V_13 < V_22 -> V_34 ; V_13 ++ )
* ( V_28 + ( V_27 ++ ) ) = * ( V_22 -> V_35 + V_13 ) ;
}
F_10 ( V_23 , ( 1 + V_22 -> V_34 ) ) ;
F_10 ( V_16 ,
( V_25 << V_36 )
| ( 1 << 0 )
| ( ( V_22 -> V_37 == V_38 ) ? ( 1 << 1 ) : 0 ) ) ;
V_30 = F_14 ( V_2 ) ;
if ( V_30 ) {
F_4 ( V_5 -> V_5 , L_7 , V_22 -> V_33 ) ;
return - V_18 ;
}
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_39 = V_2 -> V_40 ;
T_1 V_41 = V_2 -> V_42 ;
T_1 V_43 = 0 ;
struct V_44 * V_45 = & V_20 -> V_20 . V_45 ;
V_43 |= V_45 -> V_33 << V_46 ;
V_43 |= 0 << V_47 ;
V_43 |= V_20 -> V_48 ;
V_43 |= V_45 -> V_35 << V_49 ;
if ( V_20 -> V_50 == V_51 ) {
F_10 ( V_39 , V_43 ) ;
} else if ( V_20 -> V_50 == V_52 ) {
F_10 ( V_41 , V_43 ) ;
} else {
F_4 ( V_5 -> V_5 , L_8 ,
V_20 -> V_50 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_39 = V_2 -> V_40 ;
T_1 V_54 = V_2 -> V_55 ;
T_1 V_41 = V_2 -> V_42 ;
T_1 V_56 = V_2 -> V_57 ;
T_1 V_43 = 0 ;
T_1 * V_58 ;
int V_13 ;
struct V_59 * V_60 = & V_20 -> V_20 . V_60 ;
V_58 = V_60 -> V_61 ;
V_43 |= ( V_60 -> V_62 << 2 ) << V_63 ;
V_43 |= 0 << V_47 ;
V_43 |= V_20 -> V_48 ;
if ( V_20 -> V_50 == V_51 ) {
for ( V_13 = 0 ; V_13 < V_60 -> V_62 ; V_13 ++ )
F_10 ( V_54 , * ( V_58 + V_13 ) ) ;
F_10 ( V_39 , V_43 ) ;
} else if ( V_20 -> V_50 == V_52 ) {
for ( V_13 = 0 ; V_13 < V_60 -> V_62 ; V_13 ++ )
F_10 ( V_56 , * ( V_58 + V_13 ) ) ;
F_10 ( V_41 , V_43 ) ;
} else {
F_4 ( V_5 -> V_5 , L_8 ,
V_20 -> V_50 ) ;
return - V_53 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
return F_16 ( V_2 , V_20 ) ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
return F_17 ( V_2 , V_20 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
return F_16 ( V_2 , V_20 ) ;
}
static int F_21 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
return F_17 ( V_2 , V_20 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_2 V_33 ;
T_2 * V_61 ;
switch ( V_20 -> V_48 ) {
case V_64 :
V_33 = V_20 -> V_20 . V_22 . V_33 ;
break;
case V_65 :
case V_66 :
V_33 = V_20 -> V_20 . V_45 . V_33 ;
break;
case V_67 :
V_61 = ( T_2 * ) V_20 -> V_20 . V_60 . V_61 ;
V_33 = * V_61 ;
break;
default:
return 0 ;
}
V_2 -> V_68 = V_69 ;
if ( ( V_2 -> V_70 & V_71 ) &&
V_33 != V_72 ) {
F_4 ( V_2 -> V_5 -> V_5 ,
L_9 , V_33 ) ;
V_2 -> V_68 = V_73 ;
return - V_53 ;
}
if ( V_33 == V_74 ) {
F_23 ( 120 ) ;
}
return 0 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
T_2 V_33 ;
T_2 * V_61 ;
switch ( V_20 -> V_48 ) {
case V_64 :
V_33 = V_20 -> V_20 . V_22 . V_33 ;
break;
case V_65 :
case V_66 :
V_33 = V_20 -> V_20 . V_45 . V_33 ;
break;
case V_67 :
V_61 = ( T_2 * ) V_20 -> V_20 . V_60 . V_61 ;
V_33 = * V_61 ;
break;
default:
return 0 ;
}
if ( V_33 == V_74 ) {
V_2 -> V_70 |= V_71 ;
F_23 ( 120 ) ;
} else if ( V_33 == V_75 ) {
V_2 -> V_70 &= ~ V_71 ;
F_23 ( 120 ) ;
} else if ( F_25 ( V_33 == V_76 ) ) {
F_23 ( 5 ) ;
}
V_2 -> V_68 = V_73 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_30 ;
if ( V_2 -> V_68 == V_69 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_10 ) ;
return - V_18 ;
}
V_30 = F_22 ( V_2 , V_20 ) ;
if ( V_30 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_11 ) ;
return V_30 ;
}
switch ( V_20 -> V_48 ) {
case V_64 :
V_30 = F_15 ( V_2 , V_20 ) ;
break;
case V_77 :
case V_78 :
case V_79 :
case V_80 :
case V_81 :
case V_82 :
V_30 = F_20 ( V_2 , V_20 ) ;
break;
case V_83 :
V_30 = F_21 ( V_2 , V_20 ) ;
break;
case V_65 :
case V_66 :
case V_84 :
V_30 = F_18 ( V_2 , V_20 ) ;
break;
case V_67 :
V_30 = F_19 ( V_2 , V_20 ) ;
break;
default:
F_4 ( V_2 -> V_5 -> V_5 , L_12 ,
V_20 -> V_48 ) ;
V_30 = - V_53 ;
}
F_24 ( V_2 , V_20 ) ;
return V_30 ;
}
static int F_27 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
int V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_13 ) ;
V_14 = - V_18 ;
goto V_85;
}
V_14 = F_26 ( V_2 , V_20 ) ;
if ( V_14 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_14 ) ;
V_14 = - V_18 ;
goto V_85;
}
V_85:
return V_14 ;
}
static struct V_19 * F_28 (
struct V_1 * V_2 )
{
struct V_19 * V_20 ;
if ( F_29 ( & V_2 -> V_86 ) ) {
F_4 ( V_2 -> V_5 -> V_5 , L_15 ) ;
return NULL ;
}
V_20 = F_30 ( & V_2 -> V_86 , struct V_19 , V_87 ) ;
F_31 ( & V_20 -> V_87 ) ;
return V_20 ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_19 * V_20 )
{
memset ( V_20 , 0 , sizeof( struct V_19 ) ) ;
F_33 ( & V_20 -> V_87 ) ;
F_34 ( & V_20 -> V_87 , & V_2 -> V_86 ) ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_88 * V_89 , int V_90 )
{
unsigned long V_91 ;
void * V_92 = NULL ;
switch ( V_90 ) {
case 0 :
V_91 = V_89 -> V_93 - 0x1000 ;
break;
case 2 :
V_91 = V_89 -> V_93 - 0x800 ;
break;
default:
F_4 ( V_2 -> V_5 -> V_5 , L_16 , V_90 ) ;
return - V_53 ;
}
V_92 = F_36 ( V_91 , 0x800 ) ;
if ( ! V_92 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_17 ) ;
return - V_94 ;
}
V_2 -> V_26 = V_91 ;
V_2 -> V_29 = V_92 ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 )
{
if ( V_2 && V_2 -> V_29 )
F_38 ( V_2 -> V_29 ) ;
}
static void F_39 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
int V_95 )
{
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_95 ) {
F_27 ( V_2 , V_20 ) ;
F_32 ( V_2 , V_20 ) ;
} else {
F_34 ( & V_20 -> V_87 , & V_2 -> V_98 ) ;
}
F_41 ( & V_2 -> V_97 , V_96 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
while ( ! F_29 ( & V_2 -> V_98 ) ) {
V_20 = F_30 ( & V_2 -> V_98 ,
struct V_19 , V_87 ) ;
F_27 ( V_2 , V_20 ) ;
F_31 ( & V_20 -> V_87 ) ;
F_32 ( V_2 , V_20 ) ;
}
F_41 ( & V_2 -> V_97 , V_96 ) ;
}
static int F_43 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_62 , T_2 V_99 , int V_95 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_18 ) ;
return - V_94 ;
}
V_20 -> V_48 = V_67 ;
V_20 -> V_50 = V_99 ;
V_20 -> V_20 . V_60 . V_61 = V_61 ;
V_20 -> V_20 . V_60 . V_62 = V_62 ;
F_33 ( & V_20 -> V_87 ) ;
F_39 ( V_2 , V_20 , V_95 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
T_2 V_33 , T_2 V_35 , T_2 V_34 ,
T_2 V_99 ,
int V_95 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_18 ) ;
return - V_94 ;
}
if ( V_34 ) {
V_20 -> V_48 = V_66 ;
V_20 -> V_20 . V_45 . V_35 = V_35 ;
} else {
V_20 -> V_48 = V_65 ;
V_20 -> V_20 . V_45 . V_35 = 0 ;
}
V_20 -> V_50 = V_99 ;
V_20 -> V_20 . V_45 . V_33 = V_33 ;
F_33 ( & V_20 -> V_87 ) ;
F_39 ( V_2 , V_20 , V_95 ) ;
return 0 ;
}
static int F_45 ( struct V_1 * V_2 ,
T_2 V_100 , T_2 V_101 , T_2 V_34 ,
T_2 V_99 ,
int V_95 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_19 ) ;
return - V_94 ;
}
switch ( V_34 ) {
case 0 :
V_20 -> V_48 = V_77 ;
V_20 -> V_20 . V_45 . V_33 = 0 ;
V_20 -> V_20 . V_45 . V_35 = 0 ;
break;
case 1 :
V_20 -> V_48 = V_78 ;
V_20 -> V_20 . V_45 . V_33 = V_100 ;
V_20 -> V_20 . V_45 . V_35 = 0 ;
break;
case 2 :
V_20 -> V_48 = V_79 ;
V_20 -> V_20 . V_45 . V_33 = V_100 ;
V_20 -> V_20 . V_45 . V_35 = V_101 ;
break;
}
V_20 -> V_50 = V_99 ;
F_33 ( & V_20 -> V_87 ) ;
F_39 ( V_2 , V_20 , V_95 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
T_1 * V_61 , T_1 V_62 , T_2 V_99 , int V_95 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_19 ) ;
return - V_94 ;
}
V_20 -> V_48 = V_83 ;
V_20 -> V_50 = V_99 ;
V_20 -> V_20 . V_60 . V_61 = V_61 ;
V_20 -> V_20 . V_60 . V_62 = V_62 ;
F_33 ( & V_20 -> V_87 ) ;
F_39 ( V_2 , V_20 , V_95 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_19 * V_20 ,
T_1 * V_61 ,
T_3 V_62 )
{
unsigned long V_96 ;
struct V_4 * V_5 = V_2 -> V_5 ;
int V_13 ;
T_1 V_102 ;
int V_8 = V_103 ;
T_2 V_99 = V_20 -> V_50 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
F_10 ( V_2 -> V_11 , 1 << 29 ) ;
if ( ( F_2 ( V_2 -> V_11 ) & ( 1 << 29 ) ) )
F_48 ( L_20 ) ;
F_27 ( V_2 , V_20 ) ;
F_32 ( V_2 , V_20 ) ;
while ( V_8 && ! ( F_2 ( V_2 -> V_11 ) & ( 1 << 29 ) ) ) {
F_3 ( 100 ) ;
V_8 -- ;
}
if ( ! V_8 ) {
F_41 ( & V_2 -> V_97 , V_96 ) ;
return - V_104 ;
}
F_10 ( V_2 -> V_11 , ( 1 << 29 ) ) ;
if ( V_99 == V_51 )
V_102 = V_2 -> V_55 ;
else if ( V_99 == V_52 )
V_102 = V_2 -> V_57 ;
else {
F_48 ( L_21 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
return - V_53 ;
}
for ( V_13 = 0 ; V_13 < V_62 ; V_13 ++ )
* ( V_61 + V_13 ) = F_2 ( V_102 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
T_2 V_100 ,
T_2 V_101 ,
T_2 V_34 ,
T_1 * V_61 ,
T_3 V_62 ,
T_2 V_99 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_19 ) ;
return - V_94 ;
}
switch ( V_34 ) {
case 0 :
V_20 -> V_48 = V_80 ;
V_20 -> V_20 . V_45 . V_33 = 0 ;
V_20 -> V_20 . V_45 . V_35 = 0 ;
break;
case 1 :
V_20 -> V_48 = V_81 ;
V_20 -> V_20 . V_45 . V_33 = V_100 ;
V_20 -> V_20 . V_45 . V_35 = 0 ;
break;
case 2 :
V_20 -> V_48 = V_82 ;
V_20 -> V_20 . V_45 . V_33 = V_100 ;
V_20 -> V_20 . V_45 . V_35 = V_101 ;
break;
}
V_20 -> V_50 = V_99 ;
F_33 ( & V_20 -> V_87 ) ;
return F_47 ( V_2 , V_20 , V_61 , V_62 ) ;
}
static int F_50 ( struct V_1 * V_2 ,
T_2 V_33 ,
T_1 * V_61 ,
T_3 V_62 ,
T_2 V_99 )
{
struct V_19 * V_20 ;
unsigned long V_96 ;
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_2 -> V_5 -> V_5 , L_19 ) ;
return - V_94 ;
}
V_20 -> V_48 = V_84 ;
V_20 -> V_20 . V_45 . V_33 = V_33 ;
V_20 -> V_20 . V_45 . V_35 = 0 ;
V_20 -> V_50 = V_99 ;
F_33 ( & V_20 -> V_87 ) ;
return F_47 ( V_2 , V_20 , V_61 , V_62 ) ;
}
void F_51 ( struct V_105 * V_106 , int V_90 )
{
struct V_4 * V_5 = V_106 -> V_5 ;
T_1 V_107 = V_90 ? V_108 : 0 ;
int V_109 = V_106 -> V_109 ;
T_1 V_110 = 0 ;
F_10 ( ( V_111 + V_107 ) , 0x00000000 ) ;
F_10 ( ( V_112 + V_107 ) , 0x00000018 ) ;
F_10 ( ( V_113 + V_107 ) , 0x150c3408 ) ;
F_10 ( ( V_114 + V_107 ) , 0x000a0014 ) ;
F_10 ( ( V_115 + V_107 ) , 0x00000400 ) ;
F_10 ( ( V_116 + V_107 ) , 0x00000001 ) ;
F_10 ( ( V_117 + V_107 ) , 0x00000000 ) ;
F_10 ( ( V_118 + V_107 ) , 0xffffffff ) ;
F_10 ( ( V_119 + V_107 ) , 0x0000001f ) ;
F_10 ( ( V_120 + V_107 ) , 0x0000ffff ) ;
F_10 ( ( V_121 + V_107 ) , 0x00000fa0 ) ;
F_10 ( ( V_122 + V_107 ) ,
V_123 ) ;
V_110 |= V_109 ;
V_110 |= ( V_106 -> V_124 << V_125 ) ;
V_110 |= V_126 ;
F_10 ( ( V_127 + V_107 ) , V_110 ) ;
F_10 ( ( V_128 + V_107 ) , 0x3fffff ) ;
F_10 ( ( V_129 + V_107 ) , 0xffff ) ;
F_10 ( ( V_130 + V_107 ) , 0x46 ) ;
F_10 ( ( V_131 + V_107 ) , 0x00000000 ) ;
F_10 ( ( V_132 + V_107 ) , 0x00000004 ) ;
F_10 ( ( V_111 + V_107 ) , 0x00000001 ) ;
}
void F_52 ( struct V_105 * V_106 , int V_90 )
{
struct V_4 * V_5 = V_106 -> V_5 ;
T_1 V_107 = V_90 ? V_108 : 0 ;
int V_109 = V_106 -> V_109 ;
struct V_133 V_134 ;
struct V_135 * V_136 = V_106 -> V_136 ;
T_1 V_110 = 0 ;
F_10 ( ( V_111 + V_107 ) , 0x00000000 ) ;
F_10 ( ( V_112 + V_107 ) , 0x00000018 ) ;
F_10 ( ( V_118 + V_107 ) , 0xffffffff ) ;
V_110 |= V_109 ;
V_110 |= V_106 -> V_124 << V_137 ;
switch( V_106 -> V_138 ) {
case 16 :
V_110 |= V_139 ;
break;
case 18 :
V_110 |= V_140 ;
break;
case 24 :
V_110 |= V_141 ;
break;
default:
F_48 ( L_22 , V_106 -> V_138 ) ;
}
F_10 ( ( V_127 + V_107 ) , V_110 ) ;
F_10 ( ( V_128 + V_107 ) ,
( V_136 -> V_142 * V_136 -> V_143 * V_106 -> V_138 / ( 8 * V_109 ) ) & V_144 ) ;
F_10 ( ( V_129 + V_107 ) , 0xffff & V_145 ) ;
F_10 ( ( V_119 + V_107 ) , 0x14 & V_146 ) ;
F_10 ( ( V_120 + V_107 ) , 0xffff & V_147 ) ;
F_10 ( ( V_148 + V_107 ) , V_136 -> V_149 << 16 | V_136 -> V_150 ) ;
F_53 ( V_136 , & V_134 , V_106 -> V_109 , V_106 -> V_138 ) ;
F_10 ( ( V_151 + V_107 ) , V_134 . V_152 & V_153 ) ;
F_10 ( ( V_154 + V_107 ) , V_134 . V_155 & V_153 ) ;
F_10 ( ( V_156 + V_107 ) , V_134 . V_157 & V_153 ) ;
F_10 ( ( V_158 + V_107 ) , V_134 . V_159 & V_153 ) ;
F_10 ( ( V_160 + V_107 ) , V_134 . V_161 & V_153 ) ;
F_10 ( ( V_162 + V_107 ) , V_134 . V_163 & V_153 ) ;
F_10 ( ( V_164 + V_107 ) , V_134 . V_165 & V_153 ) ;
F_10 ( ( V_130 + V_107 ) , 0x46 ) ;
F_10 ( ( V_121 + V_107 ) , 0x000007d0 ) ;
V_110 = V_106 -> V_166 | V_167 ;
F_10 ( ( V_168 + V_107 ) , V_110 ) ;
F_10 ( ( V_131 + V_107 ) , 0x00000000 ) ;
F_10 ( ( V_132 + V_107 ) , 0x00000004 ) ;
F_10 ( ( V_113 + V_107 ) , 0x150c3408 ) ;
F_10 ( ( V_114 + V_107 ) , ( 0xa << 16 ) | 0x14 ) ;
F_10 ( ( V_111 + V_107 ) , 0x00000001 ) ;
}
static void F_54 ( struct V_105 * V_106 , int V_90 )
{
if ( ! V_106 || ( ( V_90 != 0 ) && ( V_90 != 2 ) ) ) {
F_48 ( L_23 ) ;
return;
}
if ( V_106 -> type == V_169 )
F_52 ( V_106 , V_90 ) ;
else if ( V_106 -> type == V_170 )
F_51 ( V_106 , V_90 ) ;
else
F_48 ( L_24 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
F_42 ( V_2 ) ;
}
int F_56 ( struct V_1 * V_2 ,
T_2 V_171 , T_2 * V_35 , T_1 V_34 , T_2 V_37 ,
int V_95 )
{
struct V_19 * V_20 ;
T_1 V_25 = V_2 -> V_26 ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_27 = 0 ;
T_2 * V_28 = ( T_2 * ) V_2 -> V_29 ;
unsigned long V_96 ;
int V_8 ;
T_2 * V_172 = NULL ;
T_1 V_62 ;
if ( ! V_2 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
if ( ! V_2 -> V_31 ) {
F_4 ( V_5 -> V_5 , L_25 ) ;
return - V_32 ;
}
if ( V_34 > V_173 ) {
F_4 ( V_5 -> V_5 , L_26 ,
V_173 ) ;
return - V_53 ;
}
if ( V_171 == V_174 ) {
if ( ! F_58 ( & V_2 -> V_97 ) )
return - V_18 ;
V_8 = V_175 ;
while ( V_8 &&
! ( F_2 ( V_2 -> V_7 ) & ( 1 << 27 ) ) ) {
F_3 ( 500 ) ;
V_8 -- ;
}
if ( ! V_8 ) {
F_59 ( & V_2 -> V_97 ) ;
return 0 ;
}
* ( V_28 + ( V_27 ++ ) ) = V_176 ;
F_10 ( V_2 -> V_24 , 1 ) ;
F_10 ( V_2 -> V_17 ,
V_25 | ( 1 << 0 ) | ( 1 << 1 ) ) ;
V_8 = V_175 ;
while ( V_8 &&
( F_2 ( V_2 -> V_17 ) & ( 1 << 0 ) ) ) {
F_3 ( 1 ) ;
V_8 -- ;
}
F_59 ( & V_2 -> V_97 ) ;
return 0 ;
}
F_40 ( & V_2 -> V_97 , V_96 ) ;
V_20 = F_28 ( V_2 ) ;
F_41 ( & V_2 -> V_97 , V_96 ) ;
if ( ! V_20 ) {
F_4 ( V_5 -> V_5 , L_27 ) ;
return - V_94 ;
}
V_172 = V_20 -> V_20 . V_22 . V_35 ;
memcpy ( V_172 , V_35 , V_34 ) ;
V_20 -> V_48 = V_64 ;
V_20 -> V_50 = V_177 ;
V_20 -> V_20 . V_22 . V_33 = V_171 ;
V_20 -> V_20 . V_22 . V_34 = V_34 ;
V_20 -> V_20 . V_22 . V_37 = V_37 ;
F_33 ( & V_20 -> V_87 ) ;
if ( V_34 == 0 )
return F_60 ( V_2 , V_171 , 0 , 0 , V_95 ) ;
else if ( V_34 == 1 )
return F_60 ( V_2 , V_171 ,
V_35 [ 0 ] , 1 , V_95 ) ;
else if ( V_34 > 1 ) {
V_62 = ( V_34 + 1 ) / 4 ;
if ( ( V_34 + 1 ) % 4 )
V_62 ++ ;
return F_61 ( V_2 ,
( T_1 * ) & V_20 -> V_20 . V_22 , V_62 , V_95 ) ;
}
return 0 ;
}
int F_60 ( struct V_1 * V_2 ,
T_2 V_33 , T_2 V_35 , T_2 V_34 , int V_95 )
{
if ( ! V_2 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_44 ( V_2 , V_33 , V_35 , V_34 ,
V_51 , V_95 ) ;
}
int F_62 ( struct V_1 * V_2 ,
T_2 V_33 , T_2 V_35 , T_2 V_34 , int V_95 )
{
if ( ! V_2 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_44 ( V_2 , V_33 , V_35 , V_34 ,
V_52 , V_95 ) ;
}
int F_61 ( struct V_1 * V_2 ,
T_1 * V_61 ,
T_1 V_62 ,
int V_95 )
{
if ( ! V_2 || ! V_61 || ! V_62 ) {
F_48 ( L_23 ) ;
return - V_53 ;
}
return F_43 ( V_2 , V_61 , V_62 ,
V_51 , V_95 ) ;
}
int F_63 ( struct V_1 * V_2 ,
T_1 * V_61 ,
T_1 V_62 ,
int V_95 )
{
if ( ! V_2 || ! V_61 || ! V_62 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_43 ( V_2 , V_61 , V_62 ,
V_52 , V_95 ) ;
}
int F_64 ( struct V_1 * V_2 ,
T_2 V_100 , T_2 V_101 , T_2 V_34 , int V_95 )
{
if ( ! V_2 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_45 ( V_2 , V_100 , V_101 , V_34 ,
V_51 , V_95 ) ;
}
int F_65 ( struct V_1 * V_2 ,
T_2 V_100 , T_2 V_101 , T_2 V_34 , int V_95 )
{
if ( ! V_2 || V_34 < 0 || V_34 > 2 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_45 ( V_2 , V_100 , V_101 , V_34 ,
V_52 , V_95 ) ;
}
int F_66 ( struct V_1 * V_2 ,
T_1 * V_61 ,
T_1 V_62 ,
int V_95 )
{
if ( ! V_2 || ! V_61 || ! V_62 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_46 ( V_2 , V_61 , V_62 ,
V_51 , V_95 ) ;
}
int F_67 ( struct V_1 * V_2 ,
T_1 * V_61 ,
T_1 V_62 ,
int V_95 )
{
if ( ! V_2 || ! V_61 || ! V_62 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_46 ( V_2 , V_61 , V_62 ,
V_52 , V_95 ) ;
}
int F_68 ( struct V_1 * V_2 ,
T_2 V_100 ,
T_2 V_101 ,
T_2 V_34 ,
T_1 * V_61 ,
T_3 V_62 )
{
if ( ! V_2 || ! V_61 || V_34 < 0 || V_34 > 2
|| ! V_61 || ! V_62 ) {
F_48 ( L_23 ) ;
return - V_53 ;
}
return F_49 ( V_2 , V_100 , V_101 , V_34 ,
V_61 , V_62 , V_51 ) ;
}
int F_69 ( struct V_1 * V_2 ,
T_2 V_100 ,
T_2 V_101 ,
T_2 V_34 ,
T_1 * V_61 ,
T_3 V_62 )
{
if ( ! V_2 || ! V_61 || V_34 < 0 || V_34 > 2
|| ! V_61 || ! V_62 ) {
F_48 ( L_23 ) ;
return - V_53 ;
}
return F_49 ( V_2 , V_100 , V_101 , V_34 ,
V_61 , V_62 , V_52 ) ;
}
int F_70 ( struct V_1 * V_2 ,
T_2 V_33 ,
T_1 * V_61 ,
T_3 V_62 )
{
if ( ! V_2 || ! V_61 || ! V_62 ) {
F_48 ( L_23 ) ;
return - V_53 ;
}
return F_50 ( V_2 , V_33 , V_61 , V_62 ,
V_51 ) ;
}
int F_71 ( struct V_1 * V_2 ,
T_2 V_33 ,
T_1 * V_61 ,
T_3 V_62 )
{
if ( ! V_2 || ! V_61 || ! V_62 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
return F_50 ( V_2 , V_33 , V_61 , V_62 ,
V_52 ) ;
}
int F_72 ( struct V_178 * V_179 ,
int V_90 )
{
int V_30 ;
struct V_1 * V_180 ;
struct V_105 * V_106 =
F_73 ( V_179 ) ;
struct V_4 * V_5 = V_106 -> V_5 ;
struct V_181 * V_182 = V_5 -> V_183 ;
struct V_88 * V_89 = & V_182 -> V_184 ;
int V_13 ;
struct V_19 * V_20 , * V_185 ;
T_1 V_186 = 0 ;
if ( ! V_179 ) {
F_57 ( 1 ) ;
return - V_53 ;
}
V_180 = V_179 -> V_180 ;
if ( ! V_180 || F_74 ( V_180 ) ) {
V_180 = F_75 ( sizeof( struct V_1 ) ,
V_187 ) ;
if ( ! V_180 ) {
F_4 ( V_5 -> V_5 , L_28 ) ;
return - V_94 ;
}
V_179 -> V_180 = ( void * ) V_180 ;
}
V_180 -> V_5 = V_5 ;
V_180 -> V_179 = V_179 ;
V_180 -> V_90 = V_90 ;
V_180 -> V_188 = 0 ;
V_180 -> V_70 = 0 ;
V_180 -> V_68 = V_73 ;
if ( V_106 -> type == V_170 ) {
V_180 -> V_31 = 1 ;
V_30 = F_35 ( V_180 , V_89 , V_90 ) ;
if ( V_30 ) {
F_4 ( V_5 -> V_5 , L_29 ) ;
goto V_189;
}
}
if ( V_90 == 0 ) {
V_180 -> V_190 = V_191 ;
V_180 -> V_192 = V_193 ;
V_180 -> V_194 = V_195 ;
V_180 -> V_196 = V_197 ;
V_180 -> V_198 = V_199 ;
V_180 -> V_200 = V_201 ;
V_180 -> V_11 = V_202 ;
V_180 -> V_57 = V_203 ;
V_180 -> V_55 = V_204 ;
V_180 -> V_42 = V_205 ;
V_180 -> V_40 = V_206 ;
V_180 -> V_7 = V_207 ;
V_180 -> V_208 = V_209 ;
V_180 -> V_210 = V_211 ;
V_180 -> V_17 = V_212 ;
V_180 -> V_24 = V_213 ;
} else if ( V_90 == 2 ) {
V_180 -> V_190 = V_191 ;
V_180 -> V_192 = V_214 ;
V_180 -> V_194 = V_215 ;
V_180 -> V_196 = V_216 ;
V_180 -> V_198 = V_217 ;
V_180 -> V_200 = V_218 ;
V_180 -> V_11 =
V_202 + V_108 ;
V_180 -> V_57 =
V_203 + V_108 ;
V_180 -> V_55 =
V_204 + V_108 ;
V_180 -> V_42 =
V_205 + V_108 ;
V_180 -> V_40 =
V_206 + V_108 ;
V_180 -> V_7 =
V_207 + V_108 ;
V_180 -> V_208 =
V_209 + V_108 ;
V_180 -> V_210 =
V_211 + V_108 ;
V_180 -> V_17 =
V_212 + V_108 ;
V_180 -> V_24 =
V_213 + V_108 ;
}
F_33 ( & V_180 -> V_98 ) ;
F_33 ( & V_180 -> V_86 ) ;
F_76 ( & V_180 -> V_97 ) ;
for ( V_13 = 0 ; V_13 < V_219 ; V_13 ++ ) {
V_20 = F_75 ( sizeof( struct V_19 ) , V_187 ) ;
if ( ! V_20 ) {
F_4 ( V_5 -> V_5 , L_30 ) ;
V_30 = - V_94 ;
goto V_220;
}
F_33 ( & V_20 -> V_87 ) ;
F_34 ( & V_20 -> V_87 , & V_180 -> V_86 ) ;
}
if ( V_106 -> type == V_169 )
V_186 = V_221 | V_222 ;
else if ( V_106 -> type == V_170 )
V_186 = V_221 | V_222
| V_223 ;
else
F_48 ( L_24 ) ;
if ( V_90 == 0 ) {
V_186 |= 0x2 ;
F_10 ( V_224 , V_186 ) ;
F_2 ( V_224 ) ;
} else if ( V_90 == 2 ) {
F_10 ( V_225 , V_186 ) ;
F_2 ( V_225 ) ;
}
F_54 ( V_106 , V_90 ) ;
return 0 ;
V_220:
F_77 (pkg, tmp, &pkg_sender->free_list, entry) {
F_78 ( & V_20 -> V_87 ) ;
F_79 ( V_20 ) ;
}
F_37 ( V_180 ) ;
V_189:
F_79 ( V_180 ) ;
V_179 -> V_180 = NULL ;
return V_30 ;
}
void F_80 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_185 ;
if ( ! V_2 || F_74 ( V_2 ) )
return;
F_77 (pkg, tmp, &sender->free_list, entry) {
F_78 ( & V_20 -> V_87 ) ;
F_79 ( V_20 ) ;
}
F_77 (pkg, tmp, &sender->pkg_list, entry) {
F_78 ( & V_20 -> V_87 ) ;
F_79 ( V_20 ) ;
}
F_37 ( V_2 ) ;
F_79 ( V_2 ) ;
}
