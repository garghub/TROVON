static const struct V_1 * F_1 ( void )
{
return & V_2 [
F_2 ( V_2 ) - 1 ] ;
}
bool F_3 ( struct V_3 * V_4 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
return true ;
default:
return false ;
}
}
bool F_4 ( struct V_3 * V_4 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_6 :
case V_7 :
case V_8 :
case V_16 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_17 :
case V_14 :
case V_15 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
return true ;
default:
return false ;
}
}
bool F_5 ( struct V_3 * V_4 , unsigned int V_5 )
{
switch ( V_5 ) {
case V_17 :
case V_21 :
return true ;
default:
return false ;
}
}
static int F_6 ( const struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_7 ( ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ,
V_10 , V_29 ) ;
if ( V_26 ) {
F_9 ( V_25 , L_1 , V_26 ) ;
return V_26 ;
}
F_10 ( V_25 , L_2 ) ;
return 0 ;
}
static int F_11 ( const struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_7 ( ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ,
V_10 , 0 ) ;
if ( V_26 ) {
F_9 ( V_25 , L_3 , V_26 ) ;
return V_26 ;
}
F_10 ( V_25 , L_4 ) ;
return 0 ;
}
static int F_12 ( const struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_7 ( ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ,
V_12 , V_30 ) ;
if ( V_26 ) {
F_9 ( V_25 , L_5 , V_26 ) ;
return V_26 ;
}
F_13 ( V_31 , V_32 ) ;
F_10 ( V_25 , L_6 ) ;
return 0 ;
}
static int F_14 ( const struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_7 ( ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ,
V_10 ,
V_29 |
V_33 ) ;
if ( V_26 ) {
F_9 ( V_25 , L_7 ,
V_26 ) ;
return V_26 ;
}
F_10 ( V_25 , L_8 ) ;
return 0 ;
}
static int F_15 ( const struct V_24 * V_25 ,
const struct V_27 * V_34 )
{
int V_26 ;
V_26 = F_16 ( V_34 -> V_35 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_16 ( V_34 -> V_36 ) ;
if ( V_26 )
goto V_35;
F_10 ( V_25 , L_9 ) ;
V_26 = F_6 ( V_25 ) ;
if ( V_26 )
goto V_36;
V_26 = F_12 ( V_25 ) ;
if ( V_26 )
goto V_37;
return 0 ;
V_37:
F_11 ( V_25 ) ;
V_36:
F_17 ( V_34 -> V_36 ) ;
V_35:
F_17 ( V_34 -> V_35 ) ;
F_10 ( V_25 , L_10 ) ;
return V_26 ;
}
static void F_18 ( const struct V_24 * V_25 ,
const struct V_27 * V_34 )
{
F_17 ( V_34 -> V_36 ) ;
F_17 ( V_34 -> V_35 ) ;
F_10 ( V_25 , L_10 ) ;
}
static int F_19 ( const struct V_24 * V_25 ,
int V_38 )
{
struct V_28 * V_39 = ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ;
const struct V_1 * V_40 = F_1 () ;
int V_26 ;
V_26 = F_7 ( V_39 , V_13 , V_40 -> V_41 ) ;
if ( V_26 )
return V_26 ;
if ( V_38 > 0 ) {
V_26 = F_7 ( V_39 , V_11 ,
( V_42 ) ~ V_43 ) ;
if ( V_26 ) {
F_20 ( V_25 -> V_4 . V_44 ,
L_11 , V_26 ) ;
return V_26 ;
}
}
F_10 ( V_25 , L_12 , V_40 -> V_45 ) ;
return 0 ;
}
static int F_21 ( const struct V_24 * V_25 ,
unsigned int V_46 )
{
struct V_28 * V_39 = ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ;
int V_26 ;
unsigned int V_47 ;
if ( ! V_46 ) {
V_26 = F_22 ( V_39 , V_18 , & V_47 ) ;
if ( V_26 < 0 )
goto V_26;
if ( V_47 & V_48 )
return 0 ;
}
do {
V_26 = F_22 ( V_39 , V_21 , & V_47 ) ;
if ( V_26 < 0 )
goto V_26;
if ( V_46 ) {
V_46 -- ;
continue;
}
V_26 = F_22 ( V_39 , V_18 , & V_47 ) ;
if ( V_26 < 0 )
goto V_26;
} while ( ! ( V_47 & V_48 ) );
F_10 ( V_25 , L_13 ) ;
return 0 ;
V_26:
F_9 ( V_25 , L_14 , V_26 ) ;
return V_26 ;
}
static int F_23 ( const struct V_24 * V_25 ,
T_1 * V_49 )
{
struct V_28 * V_39 = ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ;
unsigned int V_47 ;
int V_26 ;
int V_50 = - 1 ;
V_26 = F_22 ( V_39 , V_18 , & V_47 ) ;
if ( V_26 < 0 )
return V_26 ;
* V_49 = 0 ;
if ( V_47 & V_51 ) {
F_24 ( V_25 , L_15 ) ;
V_26 = F_25 ( V_39 , V_19 , V_49 ,
3 ) ;
if ( V_26 )
return V_26 ;
#define F_26 (16U)
return F_21 ( V_25 , F_26 - 1 ) ;
}
do {
V_26 = F_25 ( V_39 , V_19 , V_49 ,
3 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_22 ( V_39 , V_18 , & V_47 ) ;
if ( V_26 < 0 )
return V_26 ;
V_50 ++ ;
} while ( ! ( V_47 & V_48 ) );
if ( V_50 )
F_10 ( V_25 , L_16 , V_50 ) ;
return 0 ;
}
static int F_27 ( struct V_24 * V_25 ,
const struct V_27 * V_34 )
{
struct {
T_1 V_49 ;
T_2 V_52 ;
T_3 V_53 ;
} V_54 ;
int V_26 ;
if ( F_28 ( 0 , V_25 -> V_55 ) ) {
V_26 = F_23 ( V_25 , & V_54 . V_49 ) ;
if ( V_26 ) {
F_24 ( V_25 , L_17 ,
V_26 ) ;
return V_26 ;
}
}
if ( F_28 ( 1 , V_25 -> V_55 ) ) {
V_26 = F_25 ( V_34 -> V_28 , V_22 ,
& V_54 . V_52 , 2 ) ;
if ( V_26 ) {
F_24 ( V_25 ,
L_18 , V_26 ) ;
return V_26 ;
}
}
F_10 ( V_25 , L_19 ) ;
F_29 ( V_25 , & V_54 ,
V_34 -> V_53 ) ;
return 0 ;
}
static int F_30 ( struct V_3 * V_44 )
{
const struct V_24 * V_25 = F_31 ( V_44 ) ;
if ( F_32 ( V_44 ) )
return - V_56 ;
F_18 ( V_25 , F_8 ( V_25 ) ) ;
return 0 ;
}
static int F_33 ( struct V_3 * V_44 )
{
const struct V_24 * V_25 = F_31 ( V_44 ) ;
return F_15 ( V_25 , F_8 ( V_25 ) ) ;
}
static int F_34 ( const struct V_24 * V_25 )
{
int V_26 ;
V_26 = F_35 ( V_25 -> V_4 . V_44 ) ;
if ( V_26 < 0 )
return V_26 ;
if ( V_26 > 0 ) {
F_6 ( V_25 ) ;
return 1 ;
}
return 0 ;
}
static void F_36 ( struct V_24 * V_25 )
{
struct V_3 * V_44 = V_25 -> V_4 . V_44 ;
F_11 ( V_25 ) ;
F_37 ( V_44 ) ;
F_38 ( V_44 ) ;
}
static void F_39 ( struct V_3 * V_44 )
{
F_40 ( V_44 ) ;
F_41 ( V_44 ) ;
F_42 ( V_44 ) ;
F_43 ( V_44 , 1000 ) ;
F_44 ( V_44 ) ;
F_37 ( V_44 ) ;
F_38 ( V_44 ) ;
}
static void F_45 ( struct V_3 * V_44 )
{
F_46 ( V_44 ) ;
F_47 ( V_44 ) ;
}
static int F_34 ( const struct V_24 * V_25 )
{
F_6 ( V_25 ) ;
return 0 ;
}
static void F_36 ( struct V_24 * V_25 )
{
F_11 ( V_25 ) ;
}
static T_4 F_48 ( int V_38 , void * V_57 )
{
struct V_24 * V_25 = V_57 ;
if ( F_49 ( V_25 ) ) {
( (struct V_27 * )
F_8 ( V_25 ) ) -> V_53 = F_50 ( V_25 ) ;
}
return V_58 ;
}
static T_4 F_51 ( int V_38 , void * V_57 )
{
struct V_24 * V_25 = V_57 ;
struct V_27 * V_59 = F_8 ( V_25 ) ;
unsigned int V_47 ;
bool V_60 ;
T_4 V_61 = V_62 ;
V_60 = ( F_49 ( V_25 ) &&
F_52 ( V_25 ) ) ;
V_59 -> V_63 = F_22 ( V_59 -> V_28 , V_17 , & V_47 ) ;
if ( V_59 -> V_63 < 0 ) {
if ( V_60 )
return V_62 ;
goto V_64;
}
if ( ! ( V_47 & V_65 ) ) {
F_24 ( V_25 , L_20 ,
V_47 ) ;
if ( V_60 )
return V_62 ;
V_59 -> V_63 = - V_66 ;
goto V_64;
}
F_53 ( V_59 -> V_67 ) ;
if ( V_60 )
return V_68 ;
V_61 = V_68 ;
V_64:
V_64 ( & V_59 -> V_69 ) ;
return V_61 ;
}
static int F_54 ( const struct V_24 * V_25 ,
struct V_27 * V_34 )
{
unsigned int V_47 ;
long V_70 ;
F_10 ( V_25 , L_21 ) ;
V_70 = F_55 (
& V_34 -> V_69 , V_71 ) ;
if ( V_70 > 0 )
return V_34 -> V_63 ;
F_22 ( V_34 -> V_28 , V_17 , & V_47 ) ;
if ( ! V_70 ) {
F_24 ( V_25 , L_22 ,
V_70 ) ;
return - V_72 ;
}
F_24 ( V_25 , L_23 ) ;
return - V_73 ;
}
static int F_56 ( struct V_3 * V_44 ,
struct V_24 * V_25 ,
struct V_27 * V_34 ,
int V_38 )
{
int V_26 ;
V_34 -> V_38 = V_38 ;
if ( V_38 <= 0 ) {
F_57 ( V_44 , L_24 ) ;
return 0 ;
}
F_58 ( & V_34 -> V_69 ) ;
V_26 = F_59 ( V_44 , V_38 , F_48 ,
F_51 ,
V_74 | V_75 ,
F_60 ( V_44 ) , V_25 ) ;
if ( V_26 ) {
F_20 ( V_44 , L_25 , V_38 ,
V_26 ) ;
return V_26 ;
}
F_57 ( V_44 , L_26 , V_38 ) ;
return 0 ;
}
static int F_61 ( const struct V_24 * V_25 )
{
unsigned long V_76 = V_77 + V_71 ;
struct V_28 * V_39 = ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ;
unsigned int V_47 ;
int V_26 ;
F_10 ( V_25 , L_27 ) ;
if ( F_62 ( 100 ) )
return - V_73 ;
while ( true ) {
V_26 = F_22 ( V_39 , V_10 , & V_47 ) ;
if ( V_26 < 0 )
goto V_26;
if ( ! ( V_47 & V_33 ) )
break;
if ( F_63 ( V_77 , V_76 ) ) {
V_26 = - V_72 ;
goto V_26;
}
F_13 ( 10000 , 20000 ) ;
}
V_26 = F_22 ( V_39 , V_18 , & V_47 ) ;
if ( V_26 < 0 )
goto V_26;
if ( ! ( V_47 & V_78 ) ) {
V_26 = - V_66 ;
goto V_26;
}
return 0 ;
V_26:
F_24 ( V_25 , L_28 , V_26 ) ;
return V_26 ;
}
static int F_64 ( const struct V_24 * V_25 ,
enum V_79 type ,
int * V_80 )
{
struct V_28 * V_39 = ( (struct V_27 * )
F_8 ( V_25 ) ) -> V_28 ;
int V_26 ;
switch ( type ) {
case V_81 :
F_10 ( V_25 , L_29 ) ;
V_26 = F_25 ( V_39 , V_19 , V_80 ,
3 ) ;
if ( V_26 ) {
F_24 ( V_25 , L_17 ,
V_26 ) ;
return V_26 ;
}
* V_80 = ( ( ( V_42 * ) V_80 ) [ 2 ] << 16 ) | ( ( ( V_42 * ) V_80 ) [ 1 ] << 8 ) |
( ( V_42 * ) V_80 ) [ 0 ] ;
return V_82 ;
case V_83 :
F_10 ( V_25 , L_30 ) ;
V_26 = F_25 ( V_39 , V_22 , V_80 , 2 ) ;
if ( V_26 ) {
F_24 ( V_25 ,
L_18 , V_26 ) ;
return V_26 ;
}
* V_80 = ( int ) F_65 ( ( V_84 * ) V_80 ) ;
return V_82 ;
default:
return - V_85 ;
}
}
static int F_66 ( struct V_24 * V_25 ,
enum V_79 type ,
int * V_80 )
{
int V_61 ;
struct V_27 * V_59 ;
V_61 = F_67 ( V_25 ) ;
if ( V_61 )
return V_61 ;
V_61 = F_34 ( V_25 ) ;
if ( V_61 < 0 )
goto V_86;
V_59 = F_8 ( V_25 ) ;
if ( V_61 > 0 ) {
if ( type == V_81 ) {
V_61 = F_21 ( V_25 , 0 ) ;
if ( V_61 )
goto V_87;
}
} else {
V_61 = F_19 ( V_25 , V_59 -> V_38 ) ;
if ( V_61 )
goto V_87;
}
V_61 = F_14 ( V_25 ) ;
if ( V_61 )
goto V_87;
if ( V_59 -> V_38 > 0 )
V_61 = F_54 ( V_25 , V_59 ) ;
else
V_61 = F_61 ( V_25 ) ;
if ( V_61 )
goto V_87;
V_61 = F_64 ( V_25 , type , V_80 ) ;
V_87:
F_36 ( V_25 ) ;
V_86:
F_68 ( V_25 ) ;
return V_61 ;
}
static T_4 F_69 ( int V_38 , void * V_57 )
{
struct V_24 * V_25 = ( (struct V_88 * )
V_57 ) -> V_25 ;
struct V_27 * V_59 = F_8 ( V_25 ) ;
bool V_60 ;
V_60 = F_52 ( V_25 ) ;
if ( ! V_60 ) {
if ( F_14 ( V_25 ) )
goto V_89;
if ( V_59 -> V_38 <= 0 ) {
if ( F_61 ( V_25 ) )
goto V_89;
V_59 -> V_53 = F_50 ( V_25 ) ;
} else {
if ( F_54 ( V_25 , V_59 ) )
goto V_89;
}
}
F_27 ( V_25 , V_59 ) ;
V_89:
if ( ! V_60 )
F_11 ( V_25 ) ;
F_70 ( V_25 -> V_90 ) ;
return V_68 ;
}
static int F_71 ( struct V_24 * V_25 )
{
int V_61 = F_34 ( V_25 ) ;
if ( V_61 < 0 )
return V_61 ;
( (struct V_27 * )
F_8 ( V_25 ) ) -> V_91 = F_8 ( V_25 ) ;
return 0 ;
}
static int F_72 ( struct V_24 * V_25 )
{
const struct V_27 * V_59 = F_8 ( V_25 ) ;
int V_26 ;
if ( ! V_59 -> V_91 ) {
V_26 = F_21 ( V_25 , 0 ) ;
if ( V_26 )
goto V_26;
}
if ( ! F_52 ( V_25 ) && V_59 -> V_91 ) {
V_26 = F_19 ( V_25 , V_59 -> V_38 ) ;
if ( V_26 )
goto V_26;
}
V_26 = F_73 ( V_25 ) ;
if ( V_26 )
goto V_26;
return 0 ;
V_26:
F_9 ( V_25 , L_31 , V_26 ) ;
return V_26 ;
}
static int F_74 ( struct V_24 * V_25 )
{
F_36 ( V_25 ) ;
return 0 ;
}
static int F_75 ( struct V_92 * V_90 , bool V_93 )
{
const struct V_24 * V_25 = F_31 (
V_90 -> V_4 . V_44 ) ;
const struct V_27 * V_59 = F_8 ( V_25 ) ;
int V_26 ;
if ( ! V_93 ) {
unsigned int V_47 ;
F_76 ( V_59 -> V_38 ) ;
V_26 = F_7 ( V_59 -> V_28 , V_13 ,
F_1 () -> V_41 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_22 ( V_59 -> V_28 , V_17 , & V_47 ) ;
if ( V_26 < 0 )
return V_26 ;
F_77 ( V_59 -> V_38 ) ;
F_10 ( V_25 , L_32 ) ;
} else {
if ( V_59 -> V_91 ) {
V_26 = F_7 ( V_59 -> V_28 , V_11 ,
( V_42 )
~ V_43 ) ;
if ( V_26 )
return V_26 ;
}
V_26 = F_7 ( V_59 -> V_28 , V_13 ,
V_94 |
V_59 -> V_95 -> V_41 ) ;
if ( V_26 )
return V_26 ;
F_10 ( V_25 , L_33 ,
V_59 -> V_95 -> V_45 ) ;
}
return 0 ;
}
static int F_78 ( struct V_3 * V_44 ,
struct V_24 * V_25 ,
struct V_27 * V_34 ,
int V_38 )
{
struct V_92 * V_67 ;
int V_61 ;
if ( V_38 <= 0 )
return 0 ;
V_67 = F_79 ( V_44 , L_34 ,
V_25 -> V_96 , V_25 -> V_97 ) ;
if ( ! V_67 )
return - V_98 ;
V_67 -> V_4 . V_44 = V_44 ;
V_67 -> V_99 = & V_100 ;
V_34 -> V_67 = V_67 ;
V_61 = F_80 ( V_44 , V_67 ) ;
if ( V_61 )
F_20 ( V_44 , L_35 ,
V_61 ) ;
return V_61 ;
}
static int F_81 ( const struct V_24 * V_25 )
{
return ( (struct V_27 * ) F_8 ( V_25 ) ) -> V_95 -> V_45 ;
}
static int F_82 ( struct V_24 * V_25 , int V_45 )
{
struct V_27 * V_59 = F_8 ( V_25 ) ;
int V_40 ;
int V_26 ;
for ( V_40 = 0 ; V_40 < F_2 ( V_2 ) ; V_40 ++ )
if ( V_2 [ V_40 ] . V_45 == V_45 )
break;
if ( V_40 == F_2 ( V_2 ) )
return - V_85 ;
V_26 = F_67 ( V_25 ) ;
if ( V_26 )
return V_26 ;
V_59 -> V_95 = & V_2 [ V_40 ] ;
F_68 ( V_25 ) ;
return 0 ;
}
static int F_83 ( struct V_24 * V_25 ,
struct V_101 const * V_102 ,
int * V_47 ,
int * V_103 ,
long V_104 )
{
switch ( V_104 ) {
case V_105 :
return F_66 ( V_25 , V_102 -> type , V_47 ) ;
case V_106 :
switch ( V_102 -> type ) {
case V_81 :
* V_47 = 1 ;
* V_103 = 64000 ;
return V_107 ;
case V_83 :
* V_47 = 6 ;
* V_103 = 490000 ;
return V_108 ;
default:
return - V_85 ;
}
case V_109 :
switch ( V_102 -> type ) {
case V_83 :
* V_47 = - 17683000 ;
* V_103 = 649 ;
return V_107 ;
default:
return - V_85 ;
}
case V_110 :
* V_47 = F_81 ( V_25 ) ;
return V_82 ;
default:
return - V_85 ;
}
}
static int F_84 ( struct V_24 * V_25 ,
const struct V_101 * V_102 ,
int V_47 ,
int V_103 ,
long V_104 )
{
if ( ( V_104 != V_110 ) || V_103 )
return - V_85 ;
return F_82 ( V_25 , V_47 ) ;
}
static struct V_24 * F_85 ( struct V_3 * V_3 ,
const char * V_96 ,
struct V_28 * V_28 )
{
struct V_24 * V_25 ;
V_25 = F_86 ( V_3 ,
sizeof( struct V_27 ) ) ;
if ( ! V_25 )
return NULL ;
V_25 -> V_111 = V_112 ;
V_25 -> V_4 . V_44 = V_3 ;
V_25 -> V_113 = V_114 ;
V_25 -> V_115 = F_2 ( V_114 ) ;
V_25 -> V_96 = V_96 ;
V_25 -> V_116 = & V_117 ;
return V_25 ;
}
int F_87 ( struct V_3 * V_44 ,
const char * V_96 ,
int V_38 ,
unsigned int V_118 ,
struct V_28 * V_28 )
{
struct V_24 * V_25 ;
struct V_27 * V_59 ;
int V_26 ;
unsigned int V_97 ;
V_25 = F_85 ( V_44 , V_96 , V_28 ) ;
if ( ! V_25 )
return - V_98 ;
V_59 = F_8 ( V_25 ) ;
V_59 -> V_35 = F_88 ( V_44 , L_36 ) ;
if ( F_89 ( V_59 -> V_35 ) )
return F_90 ( V_59 -> V_35 ) ;
V_59 -> V_36 = F_88 ( V_44 , L_37 ) ;
if ( F_89 ( V_59 -> V_36 ) )
return F_90 ( V_59 -> V_36 ) ;
V_59 -> V_95 = F_1 () ;
V_59 -> V_28 = V_28 ;
V_26 = F_91 ( V_44 , V_25 , NULL ,
F_69 ,
& V_119 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_78 ( V_44 , V_25 , V_59 , V_38 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_56 ( V_44 , V_25 , V_59 , V_38 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_15 ( V_25 , V_59 ) ;
if ( V_26 )
return V_26 ;
V_26 = F_22 ( V_28 , V_16 , & V_97 ) ;
if ( V_26 )
goto V_37;
if ( V_97 != V_118 ) {
F_20 ( V_44 , L_38 , V_97 ) ;
V_26 = - V_120 ;
goto V_37;
}
V_26 = F_19 ( V_25 , V_38 ) ;
if ( V_26 )
goto V_37;
V_26 = F_11 ( V_25 ) ;
if ( V_26 )
goto V_121;
F_92 ( V_44 , V_25 ) ;
F_39 ( V_44 ) ;
V_26 = F_93 ( V_25 ) ;
if ( V_26 ) {
F_45 ( V_44 ) ;
goto V_121;
}
return 0 ;
V_37:
F_11 ( V_25 ) ;
V_121:
F_18 ( V_25 , V_59 ) ;
return V_26 ;
}
void F_94 ( const struct V_3 * V_44 )
{
struct V_24 * V_25 = F_31 ( V_44 ) ;
F_95 ( V_25 ) ;
F_45 ( V_25 -> V_4 . V_44 ) ;
F_11 ( V_25 ) ;
F_18 ( V_25 , F_8 ( V_25 ) ) ;
}
