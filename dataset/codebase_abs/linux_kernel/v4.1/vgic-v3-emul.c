static bool F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 = 0xffffffff ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 = 0 ;
if ( V_2 -> V_9 -> V_10 . V_11 . V_12 )
V_6 = V_13 ;
V_6 |= V_14 | V_15 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_16 ) ;
if ( V_4 -> V_17 ) {
if ( V_6 & V_18 )
F_4 ( L_1 ) ;
V_2 -> V_9 -> V_10 . V_11 . V_12 = ! ! ( V_6 & V_13 ) ;
F_5 ( V_2 -> V_9 ) ;
return true ;
}
return false ;
}
static bool F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
V_6 = ( F_7 ( V_2 -> V_9 -> V_10 . V_11 . V_19 , 1024 ) >> 5 ) - 1 ;
V_6 |= ( V_20 - 1 ) << 19 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
V_6 = ( V_21 << 24 ) | ( V_22 << 0 ) ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_10 ( V_5 >= V_23 / 8 ) )
return F_11 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_24 ,
V_25 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
static bool F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_10 ( V_5 >= V_23 / 8 ) )
return F_11 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_24 ,
V_27 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
static bool F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_10 ( V_5 >= V_23 / 8 ) )
return F_14 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_24 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
static bool F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_10 ( V_5 >= V_23 / 8 ) )
return F_16 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_24 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
static bool F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 * V_6 ;
if ( F_18 ( V_5 < V_23 ) ) {
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
V_6 = F_19 ( & V_2 -> V_9 -> V_10 . V_11 . V_28 ,
V_2 -> V_24 , V_5 ) ;
F_2 ( V_4 , V_6 , V_5 ,
V_7 | V_16 ) ;
return false ;
}
static bool F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 * V_6 ;
if ( F_18 ( V_5 < V_23 / 4 ) ) {
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
V_6 = F_21 ( & V_2 -> V_9 -> V_10 . V_11 . V_29 ,
V_2 -> V_24 , V_5 >> 1 ) ;
return F_22 ( V_6 , V_4 , V_5 ) ;
}
static T_2 F_23 ( unsigned long V_30 )
{
T_2 V_31 ;
V_31 = F_24 ( V_30 , 0 ) ;
V_31 |= F_24 ( V_30 , 1 ) << 8 ;
V_31 |= F_24 ( V_30 , 2 ) << 16 ;
V_31 |= F_24 ( V_30 , 3 ) << 24 ;
return V_31 ;
}
static unsigned long F_25 ( T_2 V_32 )
{
unsigned long V_30 ;
V_30 = ( ( V_32 >> 0 ) & 0xFF ) << F_26 ( 0 ) ;
V_30 |= ( ( V_32 >> 8 ) & 0xFF ) << F_26 ( 1 ) ;
V_30 |= ( ( V_32 >> 16 ) & 0xFF ) << F_26 ( 2 ) ;
V_30 |= ( V_33 ) ( ( V_32 >> 24 ) & 0xFF ) << F_26 ( 3 ) ;
return V_30 ;
}
static bool F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_9 * V_9 = V_2 -> V_9 ;
struct V_34 * V_35 = & V_9 -> V_10 . V_11 ;
int V_36 ;
T_2 V_6 ;
int V_24 ;
unsigned long * V_37 , V_30 ;
if ( ( V_5 & 4 ) ) {
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
V_36 = V_5 / 8 ;
V_30 = F_25 ( V_35 -> V_38 [ V_36 ] ) ;
V_6 = V_30 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_16 ) ;
if ( ! V_4 -> V_17 )
return false ;
V_2 = F_28 ( V_9 , V_30 ) ;
if ( F_10 ( V_2 ) ) {
V_24 = V_2 -> V_24 ;
V_37 = F_29 ( & V_35 -> V_39 [ V_24 ] ) ;
F_30 ( V_36 , V_37 ) ;
}
V_35 -> V_38 [ V_36 ] = F_23 ( V_6 ) ;
V_2 = F_28 ( V_9 , V_6 & V_40 ) ;
if ( F_10 ( V_2 ) ) {
V_24 = V_2 -> V_24 ;
V_35 -> V_41 [ V_36 ] = V_24 ;
V_37 = F_29 ( & V_35 -> V_39 [ V_24 ] ) ;
F_31 ( V_36 , V_37 ) ;
} else {
V_35 -> V_41 [ V_36 ] = V_42 ;
}
F_5 ( V_9 ) ;
return true ;
}
static bool F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 = 0 ;
switch ( V_5 + V_43 ) {
case V_44 :
V_6 = 0x3b ;
break;
}
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_33 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
F_2 ( V_4 , NULL , V_5 ,
V_26 | V_8 ) ;
return false ;
}
static bool F_34 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 ;
V_33 V_30 ;
struct V_1 * V_45 = V_4 -> V_46 ;
int V_47 = V_45 -> V_24 ;
if ( ( V_5 & ~ 3 ) == 4 ) {
V_30 = F_35 ( V_45 ) ;
V_6 = F_23 ( V_30 ) ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
V_6 = V_45 -> V_24 << 8 ;
if ( V_47 == F_36 ( & V_2 -> V_9 -> V_48 ) - 1 )
V_6 |= V_49 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_45 = V_4 -> V_46 ;
return F_11 ( V_2 -> V_9 , V_4 , V_5 ,
V_45 -> V_24 ,
V_25 ) ;
}
static bool F_38 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_45 = V_4 -> V_46 ;
return F_11 ( V_2 -> V_9 , V_4 , V_5 ,
V_45 -> V_24 ,
V_27 ) ;
}
static bool F_39 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_45 = V_4 -> V_46 ;
return F_14 ( V_2 -> V_9 , V_4 , V_5 ,
V_45 -> V_24 ) ;
}
static bool F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_45 = V_4 -> V_46 ;
return F_16 ( V_2 -> V_9 , V_4 , V_5 ,
V_45 -> V_24 ) ;
}
static bool F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_45 = V_4 -> V_46 ;
T_2 * V_6 ;
V_6 = F_19 ( & V_2 -> V_9 -> V_10 . V_11 . V_28 ,
V_45 -> V_24 , V_5 ) ;
F_2 ( V_4 , V_6 , V_5 ,
V_7 | V_16 ) ;
return false ;
}
static bool F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_45 = V_4 -> V_46 ;
T_2 * V_6 = F_21 ( & V_2 -> V_9 -> V_10 . V_11 . V_29 ,
V_45 -> V_24 , V_5 >> 1 ) ;
return F_22 ( V_6 , V_4 , V_5 ) ;
}
static bool F_43 ( struct V_1 * V_2 , int V_50 )
{
if ( F_44 ( V_2 , 0 , V_50 ) ) {
F_45 ( V_2 , V_50 ) ;
F_46 ( V_2 , V_50 ) ;
return true ;
}
return false ;
}
static int F_47 ( struct V_9 * V_9 ,
const struct V_51 * V_52 )
{
int V_31 = 0 ;
struct V_34 * V_35 = & V_9 -> V_10 . V_11 ;
T_3 V_53 = V_35 -> V_54 ;
struct V_55 * V_56 = NULL ;
int V_57 ;
if ( ! F_48 ( V_9 ) )
return 0 ;
F_49 ( & V_9 -> V_58 ) ;
if ( F_50 ( V_9 ) )
goto V_59;
if ( F_51 ( V_35 -> V_60 ) ||
F_51 ( V_35 -> V_54 ) ) {
F_52 ( L_2 ) ;
V_31 = - V_61 ;
goto V_59;
}
if ( ! F_53 ( V_9 ) ) {
V_31 = - V_62 ;
goto V_59;
}
V_31 = F_54 ( V_9 , V_35 -> V_60 ,
V_63 , V_64 ,
- 1 , & V_35 -> V_65 ) ;
if ( V_31 )
goto V_59;
V_56 = F_55 ( V_35 -> V_66 , sizeof( V_56 [ 0 ] ) , V_67 ) ;
if ( ! V_56 ) {
V_31 = - V_68 ;
goto V_69;
}
for ( V_57 = 0 ; V_57 < V_35 -> V_66 ; V_57 ++ ) {
V_31 = F_54 ( V_9 , V_53 ,
V_70 , V_71 ,
V_57 , & V_56 [ V_57 ] ) ;
if ( V_31 )
goto V_69;
V_53 += V_72 ;
}
V_35 -> V_73 = V_56 ;
V_35 -> V_74 = true ;
goto V_59;
V_69:
F_56 ( V_9 , V_75 , & V_35 -> V_65 . V_76 ) ;
if ( V_56 ) {
for ( V_57 = 0 ; V_57 < V_35 -> V_66 ; V_57 ++ ) {
if ( V_56 [ V_57 ] . V_76 . V_77 )
F_56 ( V_9 , V_75 ,
& V_56 [ V_57 ] . V_76 ) ;
}
}
V_59:
if ( V_31 )
F_57 ( V_9 ) ;
F_58 ( & V_9 -> V_58 ) ;
return V_31 ;
}
static int F_59 ( struct V_9 * V_9 )
{
int V_57 ;
T_2 V_30 ;
struct V_34 * V_35 = & V_9 -> V_10 . V_11 ;
int V_78 = V_35 -> V_19 - V_23 ;
V_35 -> V_38 = F_55 ( V_78 , sizeof( V_35 -> V_38 [ 0 ] ) ,
V_67 ) ;
if ( ! V_35 -> V_38 )
return - V_68 ;
V_30 = F_23 ( F_35 ( F_60 ( V_9 , 0 ) ) ) ;
for ( V_57 = V_23 ; V_57 < V_35 -> V_19 ; V_57 ++ ) {
V_35 -> V_41 [ V_57 - V_23 ] = 0 ;
V_35 -> V_38 [ V_57 - V_23 ] = V_30 ;
F_61 ( V_35 -> V_39 , 0 , V_57 , 1 ) ;
}
return 0 ;
}
static void F_62 ( struct V_1 * V_2 , int V_50 , int V_79 )
{
}
void F_63 ( struct V_9 * V_9 )
{
struct V_34 * V_35 = & V_9 -> V_10 . V_11 ;
V_35 -> V_80 . V_81 = F_43 ;
V_35 -> V_80 . V_82 = F_62 ;
V_35 -> V_80 . V_83 = F_59 ;
V_35 -> V_80 . V_84 = F_47 ;
V_9 -> V_10 . V_85 = V_86 ;
}
static int F_64 ( V_33 V_87 , T_4 V_88 , struct V_1 * V_2 )
{
unsigned long V_89 ;
int V_90 ;
V_89 = F_35 ( V_2 ) ;
V_90 = F_24 ( V_89 , 0 ) ;
V_89 &= ~ V_91 ;
if ( V_87 != V_89 )
return - 1 ;
if ( ! ( V_88 & F_65 ( V_90 ) ) )
return - 1 ;
return V_90 ;
}
void F_66 ( struct V_1 * V_2 , V_33 V_6 )
{
struct V_9 * V_9 = V_2 -> V_9 ;
struct V_1 * V_92 ;
struct V_34 * V_35 = & V_9 -> V_10 . V_11 ;
T_4 V_93 ;
V_33 V_30 ;
int V_94 , V_95 ;
int V_24 = V_2 -> V_24 ;
bool V_96 ;
int V_97 = 0 ;
V_94 = ( V_6 & V_98 ) >> V_99 ;
V_96 = V_6 & F_65 ( V_100 ) ;
V_93 = ( V_6 & V_101 ) >> V_102 ;
V_30 = F_67 ( V_6 , 3 ) ;
V_30 |= F_67 ( V_6 , 2 ) ;
V_30 |= F_67 ( V_6 , 1 ) ;
F_68 ( & V_35 -> V_58 ) ;
F_69 (c, c_vcpu, kvm) {
if ( ! V_96 && V_93 == 0 )
break;
if ( V_96 && V_95 == V_24 )
continue;
if ( ! V_96 ) {
int V_90 ;
V_90 = F_64 ( V_30 , V_93 , V_92 ) ;
if ( V_90 == - 1 )
continue;
V_93 &= ~ F_65 ( V_90 ) ;
}
F_70 ( V_92 , V_94 ) ;
V_97 = 1 ;
F_71 ( L_3 , V_94 , V_24 , V_95 ) ;
}
if ( V_97 )
F_5 ( V_2 -> V_9 ) ;
F_72 ( & V_35 -> V_58 ) ;
if ( V_97 )
F_73 ( V_2 -> V_9 ) ;
}
static int F_74 ( struct V_103 * V_76 , T_2 type )
{
return F_75 ( V_76 -> V_9 , type ) ;
}
static void F_76 ( struct V_103 * V_76 )
{
F_77 ( V_76 ) ;
}
static int F_78 ( struct V_103 * V_76 ,
struct V_104 * V_105 )
{
int V_31 ;
V_31 = F_79 ( V_76 , V_105 ) ;
if ( V_31 != - V_61 )
return V_31 ;
switch ( V_105 -> V_106 ) {
case V_107 :
case V_108 :
return - V_61 ;
}
return - V_61 ;
}
static int F_80 ( struct V_103 * V_76 ,
struct V_104 * V_105 )
{
int V_31 ;
V_31 = F_81 ( V_76 , V_105 ) ;
if ( V_31 != - V_61 )
return V_31 ;
switch ( V_105 -> V_106 ) {
case V_107 :
case V_108 :
return - V_61 ;
}
return - V_61 ;
}
static int F_82 ( struct V_103 * V_76 ,
struct V_104 * V_105 )
{
switch ( V_105 -> V_106 ) {
case V_109 :
switch ( V_105 -> V_105 ) {
case V_110 :
case V_111 :
return - V_61 ;
case V_112 :
case V_113 :
return 0 ;
}
break;
case V_107 :
case V_108 :
return - V_61 ;
case V_114 :
return 0 ;
case V_115 :
switch ( V_105 -> V_105 ) {
case V_116 :
return 0 ;
}
}
return - V_61 ;
}
