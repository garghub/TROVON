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
V_2 -> V_9 -> V_10 . V_11 . V_12 = ! ! ( V_6 & V_13 ) ;
F_4 ( V_2 -> V_9 ) ;
return true ;
}
return false ;
}
static bool F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
V_6 = ( F_6 ( V_2 -> V_9 -> V_10 . V_11 . V_18 , 1024 ) >> 5 ) - 1 ;
V_6 |= ( V_19 - 1 ) << 19 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
V_6 = ( V_20 << 24 ) | ( V_21 << 0 ) ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_9 ( V_5 >= V_22 / 8 ) )
return F_10 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_23 ,
V_24 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_9 ( V_5 >= V_22 / 8 ) )
return F_10 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_23 ,
V_26 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_9 ( V_5 >= V_22 / 8 ) )
return F_13 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_23 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_9 ( V_5 >= V_22 / 8 ) )
return F_15 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_23 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_9 ( V_5 >= V_22 / 8 ) )
return F_17 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_23 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
if ( F_9 ( V_5 >= V_22 / 8 ) )
return F_19 ( V_2 -> V_9 , V_4 , V_5 ,
V_2 -> V_23 ) ;
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 * V_6 ;
if ( F_21 ( V_5 < V_22 ) ) {
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
V_6 = F_22 ( & V_2 -> V_9 -> V_10 . V_11 . V_27 ,
V_2 -> V_23 , V_5 ) ;
F_2 ( V_4 , V_6 , V_5 ,
V_7 | V_16 ) ;
return false ;
}
static bool F_23 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 * V_6 ;
if ( F_21 ( V_5 < V_22 / 4 ) ) {
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
V_6 = F_24 ( & V_2 -> V_9 -> V_10 . V_11 . V_28 ,
V_2 -> V_23 , V_5 >> 1 ) ;
return F_25 ( V_6 , V_4 , V_5 ) ;
}
static T_2 F_26 ( unsigned long V_29 )
{
T_2 V_30 ;
V_30 = F_27 ( V_29 , 0 ) ;
V_30 |= F_27 ( V_29 , 1 ) << 8 ;
V_30 |= F_27 ( V_29 , 2 ) << 16 ;
V_30 |= F_27 ( V_29 , 3 ) << 24 ;
return V_30 ;
}
static unsigned long F_28 ( T_2 V_31 )
{
unsigned long V_29 ;
V_29 = ( ( V_31 >> 0 ) & 0xFF ) << F_29 ( 0 ) ;
V_29 |= ( ( V_31 >> 8 ) & 0xFF ) << F_29 ( 1 ) ;
V_29 |= ( ( V_31 >> 16 ) & 0xFF ) << F_29 ( 2 ) ;
V_29 |= ( V_32 ) ( ( V_31 >> 24 ) & 0xFF ) << F_29 ( 3 ) ;
return V_29 ;
}
static bool F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_9 * V_9 = V_2 -> V_9 ;
struct V_33 * V_34 = & V_9 -> V_10 . V_11 ;
int V_35 ;
T_2 V_6 ;
int V_23 ;
unsigned long * V_36 , V_29 ;
if ( ( V_5 & 4 ) ) {
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
V_35 = V_5 / 8 ;
V_29 = F_28 ( V_34 -> V_37 [ V_35 ] ) ;
V_6 = V_29 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_16 ) ;
if ( ! V_4 -> V_17 )
return false ;
V_2 = F_31 ( V_9 , V_29 ) ;
if ( F_9 ( V_2 ) ) {
V_23 = V_2 -> V_23 ;
V_36 = F_32 ( & V_34 -> V_38 [ V_23 ] ) ;
F_33 ( V_35 , V_36 ) ;
}
V_34 -> V_37 [ V_35 ] = F_26 ( V_6 ) ;
V_2 = F_31 ( V_9 , V_6 & V_39 ) ;
if ( F_9 ( V_2 ) ) {
V_23 = V_2 -> V_23 ;
V_34 -> V_40 [ V_35 ] = V_23 ;
V_36 = F_32 ( & V_34 -> V_38 [ V_23 ] ) ;
F_34 ( V_35 , V_36 ) ;
} else {
V_34 -> V_40 [ V_35 ] = V_41 ;
}
F_4 ( V_9 ) ;
return true ;
}
static bool F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 = 0 ;
switch ( V_5 + V_42 ) {
case V_43 :
V_6 = 0x3b ;
break;
}
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_36 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
F_2 ( V_4 , NULL , V_5 ,
V_25 | V_8 ) ;
return false ;
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
T_2 V_6 ;
V_32 V_29 ;
struct V_1 * V_44 = V_4 -> V_45 ;
int V_46 = V_44 -> V_23 ;
if ( ( V_5 & ~ 3 ) == 4 ) {
V_29 = F_38 ( V_44 ) ;
V_6 = F_26 ( V_29 ) ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
V_6 = V_44 -> V_23 << 8 ;
if ( V_46 == F_39 ( & V_2 -> V_9 -> V_47 ) - 1 )
V_6 |= V_48 ;
F_2 ( V_4 , & V_6 , V_5 ,
V_7 | V_8 ) ;
return false ;
}
static bool F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
return F_10 ( V_2 -> V_9 , V_4 , V_5 ,
V_44 -> V_23 ,
V_24 ) ;
}
static bool F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
return F_10 ( V_2 -> V_9 , V_4 , V_5 ,
V_44 -> V_23 ,
V_26 ) ;
}
static bool F_42 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
return F_17 ( V_2 -> V_9 , V_4 , V_5 ,
V_44 -> V_23 ) ;
}
static bool F_43 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
return F_19 ( V_2 -> V_9 , V_4 , V_5 ,
V_44 -> V_23 ) ;
}
static bool F_44 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
return F_13 ( V_2 -> V_9 , V_4 , V_5 ,
V_44 -> V_23 ) ;
}
static bool F_45 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
return F_15 ( V_2 -> V_9 , V_4 , V_5 ,
V_44 -> V_23 ) ;
}
static bool F_46 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
T_2 * V_6 ;
V_6 = F_22 ( & V_2 -> V_9 -> V_10 . V_11 . V_27 ,
V_44 -> V_23 , V_5 ) ;
F_2 ( V_4 , V_6 , V_5 ,
V_7 | V_16 ) ;
return false ;
}
static bool F_47 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_1 * V_44 = V_4 -> V_45 ;
T_2 * V_6 = F_24 ( & V_2 -> V_9 -> V_10 . V_11 . V_28 ,
V_44 -> V_23 , V_5 >> 1 ) ;
return F_25 ( V_6 , V_4 , V_5 ) ;
}
static bool F_48 ( struct V_1 * V_2 , int V_49 )
{
if ( F_49 ( V_2 , 0 , V_49 ) ) {
F_50 ( V_2 , V_49 ) ;
F_51 ( V_2 , V_49 ) ;
return true ;
}
return false ;
}
static int F_52 ( struct V_9 * V_9 ,
const struct V_50 * V_51 )
{
int V_30 = 0 ;
struct V_33 * V_34 = & V_9 -> V_10 . V_11 ;
T_3 V_52 = V_34 -> V_53 ;
struct V_54 * V_55 = NULL ;
int V_56 ;
if ( ! F_53 ( V_9 ) )
return 0 ;
F_54 ( & V_9 -> V_57 ) ;
if ( F_55 ( V_9 ) )
goto V_58;
if ( F_56 ( V_34 -> V_59 ) ||
F_56 ( V_34 -> V_53 ) ) {
F_57 ( L_1 ) ;
V_30 = - V_60 ;
goto V_58;
}
if ( ! F_58 ( V_9 ) ) {
V_30 = - V_61 ;
goto V_58;
}
V_30 = F_59 ( V_9 , V_34 -> V_59 ,
V_62 , V_63 ,
- 1 , & V_34 -> V_64 ) ;
if ( V_30 )
goto V_58;
V_55 = F_60 ( V_34 -> V_65 , sizeof( V_55 [ 0 ] ) , V_66 ) ;
if ( ! V_55 ) {
V_30 = - V_67 ;
goto V_68;
}
for ( V_56 = 0 ; V_56 < V_34 -> V_65 ; V_56 ++ ) {
V_30 = F_59 ( V_9 , V_52 ,
V_69 , V_70 ,
V_56 , & V_55 [ V_56 ] ) ;
if ( V_30 )
goto V_68;
V_52 += V_71 ;
}
V_34 -> V_72 = V_55 ;
V_34 -> V_73 = true ;
goto V_58;
V_68:
F_61 ( V_9 , V_74 , & V_34 -> V_64 . V_75 ) ;
if ( V_55 ) {
for ( V_56 = 0 ; V_56 < V_34 -> V_65 ; V_56 ++ ) {
if ( V_55 [ V_56 ] . V_75 . V_76 )
F_61 ( V_9 , V_74 ,
& V_55 [ V_56 ] . V_75 ) ;
}
}
V_58:
if ( V_30 )
F_62 ( V_9 ) ;
F_63 ( & V_9 -> V_57 ) ;
return V_30 ;
}
static int F_64 ( struct V_9 * V_9 )
{
int V_56 ;
T_2 V_29 ;
struct V_33 * V_34 = & V_9 -> V_10 . V_11 ;
int V_77 = V_34 -> V_18 - V_22 ;
V_34 -> V_37 = F_60 ( V_77 , sizeof( V_34 -> V_37 [ 0 ] ) ,
V_66 ) ;
if ( ! V_34 -> V_37 )
return - V_67 ;
V_29 = F_26 ( F_38 ( F_65 ( V_9 , 0 ) ) ) ;
for ( V_56 = V_22 ; V_56 < V_34 -> V_18 ; V_56 ++ ) {
V_34 -> V_40 [ V_56 - V_22 ] = 0 ;
V_34 -> V_37 [ V_56 - V_22 ] = V_29 ;
F_66 ( V_34 -> V_38 , 0 , V_56 , 1 ) ;
}
return 0 ;
}
static void F_67 ( struct V_1 * V_2 , int V_49 , int V_78 )
{
}
void F_68 ( struct V_9 * V_9 )
{
struct V_33 * V_34 = & V_9 -> V_10 . V_11 ;
V_34 -> V_79 . V_80 = F_48 ;
V_34 -> V_79 . V_81 = F_67 ;
V_34 -> V_79 . V_82 = F_64 ;
V_34 -> V_79 . V_83 = F_52 ;
V_9 -> V_10 . V_84 = V_85 ;
}
static int F_69 ( V_32 V_86 , T_4 V_87 , struct V_1 * V_2 )
{
unsigned long V_88 ;
int V_89 ;
V_88 = F_38 ( V_2 ) ;
V_89 = F_27 ( V_88 , 0 ) ;
V_88 &= ~ V_90 ;
if ( V_86 != V_88 )
return - 1 ;
if ( ! ( V_87 & F_70 ( V_89 ) ) )
return - 1 ;
return V_89 ;
}
void F_71 ( struct V_1 * V_2 , V_32 V_6 )
{
struct V_9 * V_9 = V_2 -> V_9 ;
struct V_1 * V_91 ;
struct V_33 * V_34 = & V_9 -> V_10 . V_11 ;
T_4 V_92 ;
V_32 V_29 ;
int V_93 , V_94 ;
int V_23 = V_2 -> V_23 ;
bool V_95 ;
int V_96 = 0 ;
V_93 = ( V_6 & V_97 ) >> V_98 ;
V_95 = V_6 & F_70 ( V_99 ) ;
V_92 = ( V_6 & V_100 ) >> V_101 ;
V_29 = F_72 ( V_6 , 3 ) ;
V_29 |= F_72 ( V_6 , 2 ) ;
V_29 |= F_72 ( V_6 , 1 ) ;
F_73 ( & V_34 -> V_57 ) ;
F_74 (c, c_vcpu, kvm) {
if ( ! V_95 && V_92 == 0 )
break;
if ( V_95 && V_94 == V_23 )
continue;
if ( ! V_95 ) {
int V_89 ;
V_89 = F_69 ( V_29 , V_92 , V_91 ) ;
if ( V_89 == - 1 )
continue;
V_92 &= ~ F_70 ( V_89 ) ;
}
F_75 ( V_91 , V_93 ) ;
V_96 = 1 ;
F_76 ( L_2 , V_93 , V_23 , V_94 ) ;
}
if ( V_96 )
F_4 ( V_2 -> V_9 ) ;
F_77 ( & V_34 -> V_57 ) ;
if ( V_96 )
F_78 ( V_2 -> V_9 ) ;
}
static int F_79 ( struct V_102 * V_75 , T_2 type )
{
return F_80 ( V_75 -> V_9 , type ) ;
}
static void F_81 ( struct V_102 * V_75 )
{
F_82 ( V_75 ) ;
}
static int F_83 ( struct V_102 * V_75 ,
struct V_103 * V_104 )
{
int V_30 ;
V_30 = F_84 ( V_75 , V_104 ) ;
if ( V_30 != - V_60 )
return V_30 ;
switch ( V_104 -> V_105 ) {
case V_106 :
case V_107 :
return - V_60 ;
}
return - V_60 ;
}
static int F_85 ( struct V_102 * V_75 ,
struct V_103 * V_104 )
{
int V_30 ;
V_30 = F_86 ( V_75 , V_104 ) ;
if ( V_30 != - V_60 )
return V_30 ;
switch ( V_104 -> V_105 ) {
case V_106 :
case V_107 :
return - V_60 ;
}
return - V_60 ;
}
static int F_87 ( struct V_102 * V_75 ,
struct V_103 * V_104 )
{
switch ( V_104 -> V_105 ) {
case V_108 :
switch ( V_104 -> V_104 ) {
case V_109 :
case V_110 :
return - V_60 ;
case V_111 :
case V_112 :
return 0 ;
}
break;
case V_106 :
case V_107 :
return - V_60 ;
case V_113 :
return 0 ;
case V_114 :
switch ( V_104 -> V_104 ) {
case V_115 :
return 0 ;
}
}
return - V_60 ;
}
