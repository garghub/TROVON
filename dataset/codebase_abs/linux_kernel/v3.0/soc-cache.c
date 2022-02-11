static int F_1 ( void * V_1 , const char * V_2 , int V_3 )
{
struct V_4 * V_5 = V_1 ;
int V_6 ;
V_6 = F_2 ( V_5 , V_2 , V_3 ) ;
if ( V_6 < 0 )
return V_6 ;
return V_3 ;
}
static int F_3 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 , const void * V_2 , int V_3 )
{
int V_6 ;
if ( ! F_4 ( V_8 , V_9 ) &&
V_9 < V_8 -> V_11 -> V_12 &&
! V_8 -> V_13 ) {
V_6 = F_5 ( V_8 , V_9 , V_10 ) ;
if ( V_6 < 0 )
return - 1 ;
}
if ( V_8 -> V_14 ) {
V_8 -> V_15 = 1 ;
return 0 ;
}
V_6 = V_8 -> V_16 ( V_8 -> V_17 , V_2 , V_3 ) ;
if ( V_6 == V_3 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
static unsigned int F_6 ( struct V_7 * V_8 , unsigned int V_9 )
{
int V_6 ;
unsigned int V_19 ;
if ( V_9 >= V_8 -> V_11 -> V_12 ||
F_4 ( V_8 , V_9 ) ||
V_8 -> V_13 ) {
if ( V_8 -> V_14 )
return - 1 ;
F_7 ( ! V_8 -> V_20 ) ;
return V_8 -> V_20 ( V_8 , V_9 ) ;
}
V_6 = F_8 ( V_8 , V_9 , & V_19 ) ;
if ( V_6 < 0 )
return - 1 ;
return V_19 ;
}
static unsigned int F_9 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
return F_6 ( V_8 , V_9 ) ;
}
static int F_10 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_1 V_2 ;
V_2 = F_11 ( ( V_9 << 12 ) | ( V_10 & 0xffffff ) ) ;
return F_3 ( V_8 , V_9 , V_10 , & V_2 , 2 ) ;
}
static unsigned int F_12 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
return F_6 ( V_8 , V_9 ) ;
}
static int F_13 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 2 ] ;
V_2 [ 0 ] = ( V_9 << 1 ) | ( ( V_10 >> 8 ) & 0x0001 ) ;
V_2 [ 1 ] = V_10 & 0x00ff ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 2 ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 2 ] ;
V_9 &= 0xff ;
V_2 [ 0 ] = V_9 ;
V_2 [ 1 ] = V_10 & 0xff ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 2 ) ;
}
static unsigned int F_15 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
return F_6 ( V_8 , V_9 ) ;
}
static int F_16 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 3 ] ;
V_2 [ 0 ] = V_9 ;
V_2 [ 1 ] = ( V_10 >> 8 ) & 0xff ;
V_2 [ 2 ] = V_10 & 0xff ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 3 ) ;
}
static unsigned int F_17 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
return F_6 ( V_8 , V_9 ) ;
}
static unsigned int F_18 ( struct V_7 * V_8 ,
void * V_9 , int V_21 ,
void * V_2 , int V_22 )
{
struct V_23 V_24 [ 2 ] ;
int V_6 ;
struct V_25 * V_26 = V_8 -> V_17 ;
V_24 [ 0 ] . V_27 = V_26 -> V_27 ;
V_24 [ 0 ] . V_28 = 0 ;
V_24 [ 0 ] . V_3 = V_21 ;
V_24 [ 0 ] . V_29 = V_9 ;
V_24 [ 1 ] . V_27 = V_26 -> V_27 ;
V_24 [ 1 ] . V_28 = V_30 ;
V_24 [ 1 ] . V_3 = V_22 ;
V_24 [ 1 ] . V_29 = V_2 ;
V_6 = F_19 ( V_26 -> V_31 , V_24 , 2 ) ;
if ( V_6 == 2 )
return 0 ;
else if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
static unsigned int F_20 ( struct V_7 * V_8 ,
unsigned int V_32 )
{
T_2 V_9 = V_32 ;
T_2 V_2 ;
int V_6 ;
V_6 = F_18 ( V_8 , & V_9 , 1 , & V_2 , 1 ) ;
if ( V_6 < 0 )
return 0 ;
return V_2 ;
}
static unsigned int F_21 ( struct V_7 * V_8 ,
unsigned int V_32 )
{
T_2 V_9 = V_32 ;
T_1 V_2 ;
int V_6 ;
V_6 = F_18 ( V_8 , & V_9 , 1 , & V_2 , 2 ) ;
if ( V_6 < 0 )
return 0 ;
return ( V_2 >> 8 ) | ( ( V_2 & 0xff ) << 8 ) ;
}
static unsigned int F_22 ( struct V_7 * V_8 ,
unsigned int V_32 )
{
T_1 V_9 = V_32 ;
T_2 V_2 ;
int V_6 ;
V_6 = F_18 ( V_8 , & V_9 , 2 , & V_2 , 1 ) ;
if ( V_6 < 0 )
return 0 ;
return V_2 ;
}
static unsigned int F_23 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
return F_6 ( V_8 , V_9 ) ;
}
static int F_24 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 3 ] ;
V_2 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_2 [ 1 ] = V_9 & 0xff ;
V_2 [ 2 ] = V_10 ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 3 ) ;
}
static unsigned int F_25 ( struct V_7 * V_8 ,
unsigned int V_32 )
{
T_1 V_9 = F_11 ( V_32 ) ;
T_1 V_2 ;
int V_6 ;
V_6 = F_18 ( V_8 , & V_9 , 2 , & V_2 , 2 ) ;
if ( V_6 < 0 )
return 0 ;
return F_26 ( V_2 ) ;
}
static unsigned int F_27 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
return F_6 ( V_8 , V_9 ) ;
}
static int F_28 ( struct V_7 * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
T_2 V_2 [ 4 ] ;
V_2 [ 0 ] = ( V_9 >> 8 ) & 0xff ;
V_2 [ 1 ] = V_9 & 0xff ;
V_2 [ 2 ] = ( V_10 >> 8 ) & 0xff ;
V_2 [ 3 ] = V_10 & 0xff ;
return F_3 ( V_8 , V_9 , V_10 , V_2 , 4 ) ;
}
static int F_29 ( struct V_7 * V_8 , unsigned int V_9 ,
const void * V_2 , T_3 V_3 )
{
int V_6 ;
if ( ! V_8 -> V_13
&& ! F_4 ( V_8 , V_9 )
&& V_9 < V_8 -> V_11 -> V_12 )
return - V_33 ;
switch ( V_8 -> V_34 ) {
#if F_30 ( V_35 ) || ( F_30 ( V_36 ) && F_30 ( V_37 ) )
case V_38 :
V_6 = F_31 ( V_8 -> V_17 , V_2 , V_3 ) ;
break;
#endif
#if F_30 ( V_39 )
case V_40 :
V_6 = F_2 ( V_8 -> V_17 , V_2 , V_3 ) ;
break;
#endif
default:
F_32 () ;
}
if ( V_6 == V_3 )
return 0 ;
if ( V_6 < 0 )
return V_6 ;
else
return - V_18 ;
}
int F_33 ( struct V_7 * V_8 ,
int V_41 , int V_42 ,
enum V_43 V_1 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_34 ( V_45 ) ; V_44 ++ )
if ( V_45 [ V_44 ] . V_41 == V_41 &&
V_45 [ V_44 ] . V_42 == V_42 )
break;
if ( V_44 == F_34 ( V_45 ) ) {
F_35 ( V_46
L_1 ,
V_41 , V_42 ) ;
return - V_33 ;
}
V_8 -> V_47 = V_45 [ V_44 ] . V_47 ;
V_8 -> V_48 = V_45 [ V_44 ] . V_48 ;
V_8 -> V_49 = F_29 ;
switch ( V_1 ) {
case V_38 :
#if F_30 ( V_35 ) || ( F_30 ( V_36 ) && F_30 ( V_37 ) )
V_8 -> V_16 = ( V_50 ) F_31 ;
#endif
if ( V_45 [ V_44 ] . V_51 )
V_8 -> V_20 = V_45 [ V_44 ] . V_51 ;
V_8 -> V_17 = F_36 ( V_8 -> V_52 ,
struct V_25 ,
V_52 ) ;
break;
case V_40 :
#ifdef V_39
V_8 -> V_16 = F_1 ;
#endif
V_8 -> V_17 = F_36 ( V_8 -> V_52 ,
struct V_4 ,
V_52 ) ;
break;
}
return 0 ;
}
static bool F_37 ( void * V_53 , unsigned int V_54 ,
unsigned int V_19 , unsigned int V_55 )
{
switch ( V_55 ) {
case 1 : {
T_2 * V_56 = V_53 ;
if ( V_56 [ V_54 ] == V_19 )
return true ;
V_56 [ V_54 ] = V_19 ;
break;
}
case 2 : {
T_1 * V_56 = V_53 ;
if ( V_56 [ V_54 ] == V_19 )
return true ;
V_56 [ V_54 ] = V_19 ;
break;
}
default:
F_32 () ;
}
return false ;
}
static unsigned int F_38 ( const void * V_53 , unsigned int V_54 ,
unsigned int V_55 )
{
if ( ! V_53 )
return - 1 ;
switch ( V_55 ) {
case 1 : {
const T_2 * V_56 = V_53 ;
return V_56 [ V_54 ] ;
}
case 2 : {
const T_1 * V_56 = V_53 ;
return V_56 [ V_54 ] ;
}
default:
F_32 () ;
}
return - 1 ;
}
static struct V_57 * F_39 (
struct V_58 * V_59 , unsigned int V_9 )
{
struct V_60 * V_61 ;
struct V_57 * V_62 ;
V_61 = V_59 -> V_60 ;
while ( V_61 ) {
V_62 = F_36 ( V_61 , struct V_57 , V_61 ) ;
if ( V_62 -> V_9 < V_9 )
V_61 = V_61 -> V_63 ;
else if ( V_62 -> V_9 > V_9 )
V_61 = V_61 -> V_64 ;
else
return V_62 ;
}
return NULL ;
}
static int F_40 ( struct V_58 * V_59 ,
struct V_57 * V_62 )
{
struct V_60 * * V_65 , * V_66 ;
struct V_57 * V_67 ;
V_66 = NULL ;
V_65 = & V_59 -> V_60 ;
while ( * V_65 ) {
V_67 = F_36 ( * V_65 , struct V_57 ,
V_61 ) ;
V_66 = * V_65 ;
if ( V_67 -> V_9 < V_62 -> V_9 )
V_65 = & ( ( * V_65 ) -> V_63 ) ;
else if ( V_67 -> V_9 > V_62 -> V_9 )
V_65 = & ( ( * V_65 ) -> V_64 ) ;
else
return 0 ;
}
F_41 ( & V_62 -> V_61 , V_66 , V_65 ) ;
F_42 ( & V_62 -> V_61 , V_59 ) ;
return 1 ;
}
static int F_43 ( struct V_7 * V_8 )
{
struct V_68 * V_69 ;
struct V_60 * V_61 ;
struct V_57 * V_62 ;
unsigned int V_19 ;
int V_6 ;
V_69 = V_8 -> V_70 ;
for ( V_61 = F_44 ( & V_69 -> V_59 ) ; V_61 ; V_61 = F_45 ( V_61 ) ) {
V_62 = F_46 ( V_61 , struct V_57 , V_61 ) ;
if ( V_62 -> V_10 == V_62 -> V_71 )
continue;
F_47 ( V_8 -> V_72 &&
V_8 -> V_72 ( V_8 , V_62 -> V_9 ) ) ;
V_6 = F_8 ( V_8 , V_62 -> V_9 , & V_19 ) ;
if ( V_6 )
return V_6 ;
V_8 -> V_13 = 1 ;
V_6 = F_48 ( V_8 , V_62 -> V_9 , V_19 ) ;
V_8 -> V_13 = 0 ;
if ( V_6 )
return V_6 ;
F_49 ( V_8 -> V_52 , L_2 ,
V_62 -> V_9 , V_19 ) ;
}
return 0 ;
}
static int F_50 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
struct V_68 * V_69 ;
struct V_57 * V_62 ;
V_69 = V_8 -> V_70 ;
V_62 = F_39 ( & V_69 -> V_59 , V_9 ) ;
if ( V_62 ) {
if ( V_62 -> V_10 == V_10 )
return 0 ;
V_62 -> V_10 = V_10 ;
} else {
if ( ! V_10 )
return 0 ;
V_62 = F_51 ( sizeof *V_62 , V_73 ) ;
if ( ! V_62 )
return - V_74 ;
V_62 -> V_9 = V_9 ;
V_62 -> V_10 = V_10 ;
F_40 ( & V_69 -> V_59 , V_62 ) ;
}
return 0 ;
}
static int F_52 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int * V_10 )
{
struct V_68 * V_69 ;
struct V_57 * V_62 ;
V_69 = V_8 -> V_70 ;
V_62 = F_39 ( & V_69 -> V_59 , V_9 ) ;
if ( V_62 ) {
* V_10 = V_62 -> V_10 ;
} else {
* V_10 = 0 ;
}
return 0 ;
}
static int F_53 ( struct V_7 * V_8 )
{
struct V_60 * V_75 ;
struct V_68 * V_69 ;
struct V_57 * V_76 ;
V_69 = V_8 -> V_70 ;
if ( ! V_69 )
return 0 ;
V_75 = F_44 ( & V_69 -> V_59 ) ;
while ( V_75 ) {
V_76 = F_46 ( V_75 , struct V_57 , V_61 ) ;
V_75 = F_45 ( & V_76 -> V_61 ) ;
F_54 ( & V_76 -> V_61 , & V_69 -> V_59 ) ;
F_55 ( V_76 ) ;
}
F_55 ( V_8 -> V_70 ) ;
V_8 -> V_70 = NULL ;
return 0 ;
}
static int F_56 ( struct V_7 * V_8 )
{
struct V_57 * V_76 ;
struct V_68 * V_69 ;
unsigned int V_19 ;
unsigned int V_55 ;
int V_44 ;
int V_6 ;
V_8 -> V_70 = F_57 ( sizeof *V_69 , V_73 ) ;
if ( ! V_8 -> V_70 )
return - V_74 ;
V_69 = V_8 -> V_70 ;
V_69 -> V_59 = V_77 ;
if ( ! V_8 -> V_78 )
return 0 ;
V_55 = V_8 -> V_11 -> V_79 ;
for ( V_44 = 0 ; V_44 < V_8 -> V_11 -> V_12 ; ++ V_44 ) {
V_19 = F_38 ( V_8 -> V_78 , V_44 , V_55 ) ;
if ( ! V_19 )
continue;
V_76 = F_51 ( sizeof *V_76 , V_73 ) ;
if ( ! V_76 ) {
V_6 = - V_74 ;
F_58 ( V_8 ) ;
break;
}
V_76 -> V_9 = V_44 ;
V_76 -> V_10 = V_19 ;
V_76 -> V_71 = V_19 ;
F_40 ( & V_69 -> V_59 , V_76 ) ;
}
return 0 ;
}
static int F_59 ( void )
{
return V_80 ;
}
static int F_60 ( struct V_81 * V_82 )
{
V_82 -> V_83 = F_57 ( V_84 , V_73 ) ;
if ( ! V_82 -> V_83 )
return - V_74 ;
return 0 ;
}
static int F_61 ( struct V_81 * V_82 )
{
T_3 V_85 ;
int V_6 ;
V_6 = F_62 ( V_82 -> V_86 , V_82 -> V_87 ,
V_82 -> V_88 , & V_85 , V_82 -> V_83 ) ;
if ( V_6 != V_89 || V_85 > V_82 -> V_90 )
return - V_33 ;
V_82 -> V_90 = V_85 ;
return 0 ;
}
static int F_63 ( struct V_81 * V_82 )
{
T_3 V_90 ;
int V_6 ;
V_90 = V_82 -> V_90 ;
V_6 = F_64 ( V_82 -> V_86 , V_82 -> V_87 ,
V_82 -> V_88 , & V_90 ) ;
if ( V_6 != V_89 || V_90 != V_82 -> V_90 )
return - V_33 ;
return 0 ;
}
static int F_65 ( struct V_7 * V_8 ,
struct V_81 * V_82 )
{
int V_6 ;
V_82 -> V_90 = F_66 ( V_91 ) ;
V_82 -> V_88 = F_57 ( V_82 -> V_90 , V_73 ) ;
if ( ! V_82 -> V_88 ) {
V_82 -> V_90 = 0 ;
return - V_74 ;
}
V_6 = F_61 ( V_82 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static int F_67 ( struct V_7 * V_8 ,
struct V_81 * V_82 )
{
int V_6 ;
V_82 -> V_90 = V_82 -> V_92 ;
V_82 -> V_88 = F_57 ( V_82 -> V_90 , V_73 ) ;
if ( ! V_82 -> V_88 ) {
V_82 -> V_90 = 0 ;
return - V_74 ;
}
V_6 = F_63 ( V_82 ) ;
if ( V_6 < 0 )
return V_6 ;
return 0 ;
}
static inline int F_68 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
const struct V_93 * V_94 ;
V_94 = V_8 -> V_11 ;
return ( V_9 * V_94 -> V_79 ) /
F_69 ( V_8 -> V_95 , F_59 () ) ;
}
static inline int F_70 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
const struct V_93 * V_94 ;
V_94 = V_8 -> V_11 ;
return V_9 % ( F_69 ( V_8 -> V_95 , F_59 () ) /
V_94 -> V_79 ) ;
}
static inline int F_71 ( struct V_7 * V_8 )
{
const struct V_93 * V_94 ;
V_94 = V_8 -> V_11 ;
return F_69 ( V_8 -> V_95 , F_59 () ) ;
}
static int F_72 ( struct V_7 * V_8 )
{
struct V_81 * * V_96 ;
unsigned int V_19 ;
int V_44 ;
int V_6 ;
V_96 = V_8 -> V_70 ;
F_73 (i, lzo_blocks[0]->sync_bmp, lzo_blocks[0]->sync_bmp_nbits) {
F_47 ( V_8 -> V_72 &&
V_8 -> V_72 ( V_8 , V_44 ) ) ;
V_6 = F_8 ( V_8 , V_44 , & V_19 ) ;
if ( V_6 )
return V_6 ;
V_8 -> V_13 = 1 ;
V_6 = F_48 ( V_8 , V_44 , V_19 ) ;
V_8 -> V_13 = 0 ;
if ( V_6 )
return V_6 ;
F_49 ( V_8 -> V_52 , L_2 ,
V_44 , V_19 ) ;
}
return 0 ;
}
static int F_74 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
struct V_81 * V_97 , * * V_96 ;
int V_6 , V_98 , V_99 ;
T_3 V_100 , V_101 ;
void * V_102 ;
V_98 = F_68 ( V_8 , V_9 ) ;
V_99 = F_70 ( V_8 , V_9 ) ;
V_100 = F_71 ( V_8 ) ;
V_96 = V_8 -> V_70 ;
V_97 = V_96 [ V_98 ] ;
V_102 = V_97 -> V_88 ;
V_101 = V_97 -> V_90 ;
V_97 -> V_86 = V_97 -> V_88 ;
V_97 -> V_87 = V_97 -> V_90 ;
V_6 = F_67 ( V_8 , V_97 ) ;
if ( V_6 < 0 ) {
F_55 ( V_97 -> V_88 ) ;
goto V_103;
}
if ( F_37 ( V_97 -> V_88 , V_99 , V_10 ,
V_8 -> V_11 -> V_79 ) ) {
F_55 ( V_97 -> V_88 ) ;
goto V_103;
}
V_97 -> V_86 = V_97 -> V_88 ;
V_97 -> V_87 = V_97 -> V_90 ;
V_6 = F_65 ( V_8 , V_97 ) ;
if ( V_6 < 0 ) {
F_55 ( V_97 -> V_88 ) ;
F_55 ( V_97 -> V_86 ) ;
goto V_103;
}
F_75 ( V_9 , V_97 -> V_104 ) ;
F_55 ( V_102 ) ;
F_55 ( V_97 -> V_86 ) ;
return 0 ;
V_103:
V_97 -> V_88 = V_102 ;
V_97 -> V_90 = V_101 ;
return V_6 ;
}
static int F_76 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int * V_10 )
{
struct V_81 * V_97 , * * V_96 ;
int V_6 , V_98 , V_99 ;
T_3 V_100 , V_101 ;
void * V_102 ;
* V_10 = 0 ;
V_98 = F_68 ( V_8 , V_9 ) ;
V_99 = F_70 ( V_8 , V_9 ) ;
V_100 = F_71 ( V_8 ) ;
V_96 = V_8 -> V_70 ;
V_97 = V_96 [ V_98 ] ;
V_102 = V_97 -> V_88 ;
V_101 = V_97 -> V_90 ;
V_97 -> V_86 = V_97 -> V_88 ;
V_97 -> V_87 = V_97 -> V_90 ;
V_6 = F_67 ( V_8 , V_97 ) ;
if ( V_6 >= 0 )
* V_10 = F_38 ( V_97 -> V_88 , V_99 ,
V_8 -> V_11 -> V_79 ) ;
F_55 ( V_97 -> V_88 ) ;
V_97 -> V_88 = V_102 ;
V_97 -> V_90 = V_101 ;
return 0 ;
}
static int F_77 ( struct V_7 * V_8 )
{
struct V_81 * * V_96 ;
int V_44 , V_105 ;
V_96 = V_8 -> V_70 ;
if ( ! V_96 )
return 0 ;
V_105 = F_59 () ;
if ( V_96 [ 0 ] )
F_55 ( V_96 [ 0 ] -> V_104 ) ;
for ( V_44 = 0 ; V_44 < V_105 ; ++ V_44 ) {
if ( V_96 [ V_44 ] ) {
F_55 ( V_96 [ V_44 ] -> V_83 ) ;
F_55 ( V_96 [ V_44 ] -> V_88 ) ;
}
F_55 ( V_96 [ V_44 ] ) ;
}
F_55 ( V_96 ) ;
V_8 -> V_70 = NULL ;
return 0 ;
}
static int F_78 ( struct V_7 * V_8 )
{
struct V_81 * * V_96 ;
T_3 V_106 ;
const struct V_93 * V_94 ;
int V_6 , V_107 , V_44 , V_100 , V_105 ;
const char * V_108 , * V_109 ;
unsigned long * V_104 ;
V_6 = 0 ;
V_94 = V_8 -> V_11 ;
V_107 = 0 ;
if ( ! V_8 -> V_78 )
V_107 = 1 ;
if ( ! V_8 -> V_78 ) {
V_8 -> V_78 = F_51 ( V_8 -> V_95 , V_73 ) ;
if ( ! V_8 -> V_78 )
return - V_74 ;
}
V_105 = F_59 () ;
V_8 -> V_70 = F_51 ( V_105 * sizeof *V_96 ,
V_73 ) ;
if ( ! V_8 -> V_70 ) {
V_6 = - V_74 ;
goto V_110;
}
V_96 = V_8 -> V_70 ;
V_106 = V_94 -> V_12 ;
V_104 = F_57 ( F_79 ( V_106 ) * sizeof( long ) ,
V_73 ) ;
if ( ! V_104 ) {
V_6 = - V_74 ;
goto V_111;
}
F_80 ( V_104 , V_106 ) ;
for ( V_44 = 0 ; V_44 < V_105 ; ++ V_44 ) {
V_96 [ V_44 ] = F_51 ( sizeof ** V_96 ,
V_73 ) ;
if ( ! V_96 [ V_44 ] ) {
F_55 ( V_104 ) ;
V_6 = - V_74 ;
goto V_111;
}
V_96 [ V_44 ] -> V_104 = V_104 ;
V_96 [ V_44 ] -> V_112 = V_106 ;
V_6 = F_60 ( V_96 [ V_44 ] ) ;
if ( V_6 < 0 )
goto V_111;
}
V_100 = F_71 ( V_8 ) ;
V_108 = V_8 -> V_78 ;
V_109 = V_8 -> V_78 + V_8 -> V_95 ;
for ( V_44 = 0 ; V_44 < V_105 ; ++ V_44 , V_108 += V_100 ) {
V_96 [ V_44 ] -> V_86 = V_108 ;
if ( V_108 + V_100 > V_109 )
V_96 [ V_44 ] -> V_87 = V_109 - V_108 ;
else
V_96 [ V_44 ] -> V_87 = V_100 ;
V_6 = F_65 ( V_8 ,
V_96 [ V_44 ] ) ;
if ( V_6 < 0 )
goto V_111;
V_96 [ V_44 ] -> V_92 =
V_96 [ V_44 ] -> V_87 ;
}
if ( V_107 ) {
F_55 ( V_8 -> V_78 ) ;
V_8 -> V_78 = NULL ;
}
return 0 ;
V_111:
F_58 ( V_8 ) ;
V_110:
if ( V_107 ) {
F_55 ( V_8 -> V_78 ) ;
V_8 -> V_78 = NULL ;
}
return V_6 ;
}
static int F_81 ( struct V_7 * V_8 )
{
int V_44 ;
int V_6 ;
const struct V_93 * V_94 ;
unsigned int V_19 ;
V_94 = V_8 -> V_11 ;
for ( V_44 = 0 ; V_44 < V_94 -> V_12 ; ++ V_44 ) {
F_47 ( V_8 -> V_72 &&
V_8 -> V_72 ( V_8 , V_44 ) ) ;
V_6 = F_8 ( V_8 , V_44 , & V_19 ) ;
if ( V_6 )
return V_6 ;
if ( V_8 -> V_78 )
if ( F_38 ( V_8 -> V_78 ,
V_44 , V_94 -> V_79 ) == V_19 )
continue;
V_6 = F_48 ( V_8 , V_44 , V_19 ) ;
if ( V_6 )
return V_6 ;
F_49 ( V_8 -> V_52 , L_2 ,
V_44 , V_19 ) ;
}
return 0 ;
}
static int F_82 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
F_37 ( V_8 -> V_70 , V_9 , V_10 ,
V_8 -> V_11 -> V_79 ) ;
return 0 ;
}
static int F_83 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int * V_10 )
{
* V_10 = F_38 ( V_8 -> V_70 , V_9 ,
V_8 -> V_11 -> V_79 ) ;
return 0 ;
}
static int F_84 ( struct V_7 * V_8 )
{
if ( ! V_8 -> V_70 )
return 0 ;
F_55 ( V_8 -> V_70 ) ;
V_8 -> V_70 = NULL ;
return 0 ;
}
static int F_85 ( struct V_7 * V_8 )
{
const struct V_93 * V_94 ;
V_94 = V_8 -> V_11 ;
if ( V_8 -> V_78 )
V_8 -> V_70 = F_86 ( V_8 -> V_78 ,
V_8 -> V_95 , V_73 ) ;
else
V_8 -> V_70 = F_51 ( V_8 -> V_95 , V_73 ) ;
if ( ! V_8 -> V_70 )
return - V_74 ;
return 0 ;
}
int F_87 ( struct V_7 * V_8 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_34 ( V_113 ) ; ++ V_44 )
if ( V_113 [ V_44 ] . V_114 == V_8 -> V_115 )
break;
if ( V_44 == F_34 ( V_113 ) ) {
F_88 ( V_8 -> V_52 , L_3 ,
V_8 -> V_115 ) ;
V_44 = 0 ;
}
F_89 ( & V_8 -> V_116 ) ;
V_8 -> V_117 = & V_113 [ V_44 ] ;
if ( V_8 -> V_117 -> V_118 ) {
if ( V_8 -> V_117 -> V_119 )
F_49 ( V_8 -> V_52 , L_4 ,
V_8 -> V_117 -> V_119 , V_8 -> V_119 ) ;
return V_8 -> V_117 -> V_118 ( V_8 ) ;
}
return - V_120 ;
}
int F_58 ( struct V_7 * V_8 )
{
if ( V_8 -> V_117 && V_8 -> V_117 -> exit ) {
if ( V_8 -> V_117 -> V_119 )
F_49 ( V_8 -> V_52 , L_5 ,
V_8 -> V_117 -> V_119 , V_8 -> V_119 ) ;
return V_8 -> V_117 -> exit ( V_8 ) ;
}
return - V_120 ;
}
int F_8 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int * V_10 )
{
int V_6 ;
F_90 ( & V_8 -> V_116 ) ;
if ( V_10 && V_8 -> V_117 && V_8 -> V_117 -> V_48 ) {
V_6 = V_8 -> V_117 -> V_48 ( V_8 , V_9 , V_10 ) ;
F_91 ( & V_8 -> V_116 ) ;
return V_6 ;
}
F_91 ( & V_8 -> V_116 ) ;
return - V_120 ;
}
int F_5 ( struct V_7 * V_8 ,
unsigned int V_9 , unsigned int V_10 )
{
int V_6 ;
F_90 ( & V_8 -> V_116 ) ;
if ( V_8 -> V_117 && V_8 -> V_117 -> V_47 ) {
V_6 = V_8 -> V_117 -> V_47 ( V_8 , V_9 , V_10 ) ;
F_91 ( & V_8 -> V_116 ) ;
return V_6 ;
}
F_91 ( & V_8 -> V_116 ) ;
return - V_120 ;
}
int F_92 ( struct V_7 * V_8 )
{
int V_6 ;
const char * V_119 ;
if ( ! V_8 -> V_15 ) {
return 0 ;
}
if ( ! V_8 -> V_117 || ! V_8 -> V_117 -> V_121 )
return - V_120 ;
if ( V_8 -> V_117 -> V_119 )
V_119 = V_8 -> V_117 -> V_119 ;
else
V_119 = L_6 ;
if ( V_8 -> V_117 -> V_119 )
F_49 ( V_8 -> V_52 , L_7 ,
V_8 -> V_117 -> V_119 , V_8 -> V_119 ) ;
F_93 ( V_8 , V_119 , L_8 ) ;
V_6 = V_8 -> V_117 -> V_121 ( V_8 ) ;
if ( ! V_6 )
V_8 -> V_15 = 0 ;
F_93 ( V_8 , V_119 , L_9 ) ;
return V_6 ;
}
static int F_94 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
const struct V_93 * V_94 ;
unsigned int V_122 , V_123 , V_124 ;
V_94 = V_8 -> V_11 ;
V_122 = 0 ;
V_123 = V_94 -> V_125 - 1 ;
do {
V_124 = ( V_122 + V_123 ) / 2 ;
if ( V_94 -> V_126 [ V_124 ] . V_9 == V_9 )
return V_124 ;
if ( V_94 -> V_126 [ V_124 ] . V_9 < V_9 )
V_122 = V_124 + 1 ;
else
V_123 = V_124 ;
} while ( V_122 <= V_123 );
return - 1 ;
}
int F_95 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
int V_124 ;
if ( V_9 >= V_8 -> V_11 -> V_12 )
return 1 ;
V_124 = F_94 ( V_8 , V_9 ) ;
if ( V_124 < 0 )
return 0 ;
return V_8 -> V_11 -> V_126 [ V_124 ] . V_127 ;
}
int F_96 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
int V_124 ;
if ( V_9 >= V_8 -> V_11 -> V_12 )
return 1 ;
V_124 = F_94 ( V_8 , V_9 ) ;
if ( V_124 < 0 )
return 0 ;
return V_8 -> V_11 -> V_126 [ V_124 ] . V_48 ;
}
int F_97 ( struct V_7 * V_8 ,
unsigned int V_9 )
{
int V_124 ;
if ( V_9 >= V_8 -> V_11 -> V_12 )
return 1 ;
V_124 = F_94 ( V_8 , V_9 ) ;
if ( V_124 < 0 )
return 0 ;
return V_8 -> V_11 -> V_126 [ V_124 ] . V_47 ;
}
