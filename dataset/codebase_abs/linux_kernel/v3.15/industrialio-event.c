int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
int V_10 ;
if ( F_2 ( V_11 , & V_6 -> V_12 ) ) {
V_9 . V_13 = V_3 ;
V_9 . V_4 = V_4 ;
V_10 = F_3 ( & V_6 -> V_14 , V_9 ) ;
if ( V_10 != 0 )
F_4 ( & V_6 -> V_15 , V_16 ) ;
}
return 0 ;
}
static unsigned int F_5 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_21 = 0 ;
if ( ! V_2 -> V_22 )
return - V_23 ;
F_6 ( V_18 , & V_6 -> V_15 , V_15 ) ;
if ( ! F_7 ( & V_6 -> V_14 ) )
V_21 = V_16 | V_24 ;
return V_21 ;
}
static T_3 F_8 ( struct V_17 * V_18 ,
char T_4 * V_25 ,
T_5 V_26 ,
T_6 * V_27 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_10 ;
int V_28 ;
if ( ! V_2 -> V_22 )
return - V_23 ;
if ( V_26 < sizeof( struct V_8 ) )
return - V_29 ;
do {
if ( F_7 ( & V_6 -> V_14 ) ) {
if ( V_18 -> V_30 & V_31 )
return - V_32 ;
V_28 = F_9 ( V_6 -> V_15 ,
! F_7 ( & V_6 -> V_14 ) ||
V_2 -> V_22 == NULL ) ;
if ( V_28 )
return V_28 ;
if ( V_2 -> V_22 == NULL )
return - V_23 ;
}
if ( F_10 ( & V_6 -> V_33 ) )
return - V_34 ;
V_28 = F_11 ( & V_6 -> V_14 , V_25 , V_26 , & V_10 ) ;
F_12 ( & V_6 -> V_33 ) ;
if ( V_28 )
return V_28 ;
if ( V_10 == 0 && ( V_18 -> V_30 & V_31 ) )
return - V_32 ;
} while ( V_10 == 0 );
return V_10 ;
}
static int F_13 ( struct V_35 * V_35 , struct V_17 * V_18 )
{
struct V_1 * V_2 = V_18 -> V_20 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_14 ( V_11 , & V_6 -> V_12 ) ;
F_15 ( V_2 ) ;
return 0 ;
}
int F_16 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_36 ;
if ( V_6 == NULL )
return - V_23 ;
if ( F_17 ( V_11 , & V_6 -> V_12 ) )
return - V_37 ;
F_18 ( V_2 ) ;
V_36 = F_19 ( L_1 , & V_38 ,
V_2 , V_39 | V_40 ) ;
if ( V_36 < 0 ) {
F_14 ( V_11 , & V_6 -> V_12 ) ;
F_15 ( V_2 ) ;
} else {
F_20 ( & V_6 -> V_14 ) ;
}
return V_36 ;
}
static enum V_41 F_21 ( struct V_42 * V_43 )
{
return V_43 -> V_44 -> V_45 [ V_43 -> V_46 & 0xffff ] . V_47 ;
}
static enum V_48 F_22 ( struct V_42 * V_43 )
{
return V_43 -> V_44 -> V_45 [ V_43 -> V_46 & 0xffff ] . type ;
}
static enum V_49 F_23 ( struct V_42 * V_43 )
{
return ( V_43 -> V_46 >> 16 ) & 0xffff ;
}
static T_3 F_24 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
const char * V_25 ,
T_5 V_53 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
struct V_42 * V_54 = F_26 ( V_43 ) ;
int V_28 ;
bool V_55 ;
V_28 = F_27 ( V_25 , & V_55 ) ;
if ( V_28 < 0 )
return V_28 ;
V_28 = V_2 -> V_22 -> V_56 ( V_2 ,
V_54 -> V_44 , F_22 ( V_54 ) ,
F_21 ( V_54 ) , V_55 ) ;
return ( V_28 < 0 ) ? V_28 : V_53 ;
}
static T_3 F_28 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
char * V_25 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
struct V_42 * V_54 = F_26 ( V_43 ) ;
int V_55 ;
V_55 = V_2 -> V_22 -> V_57 ( V_2 ,
V_54 -> V_44 , F_22 ( V_54 ) ,
F_21 ( V_54 ) ) ;
if ( V_55 < 0 )
return V_55 ;
else
return sprintf ( V_25 , L_2 , V_55 ) ;
}
static T_3 F_29 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
char * V_25 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
struct V_42 * V_54 = F_26 ( V_43 ) ;
int V_55 , V_58 ;
int V_28 ;
V_28 = V_2 -> V_22 -> V_59 ( V_2 ,
V_54 -> V_44 , F_22 ( V_54 ) ,
F_21 ( V_54 ) , F_23 ( V_54 ) ,
& V_55 , & V_58 ) ;
if ( V_28 < 0 )
return V_28 ;
return F_30 ( V_25 , V_28 , V_55 , V_58 ) ;
}
static T_3 F_31 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
const char * V_25 ,
T_5 V_53 )
{
struct V_1 * V_2 = F_25 ( V_51 ) ;
struct V_42 * V_54 = F_26 ( V_43 ) ;
int V_55 , V_58 ;
int V_28 ;
if ( ! V_2 -> V_22 -> V_60 )
return - V_29 ;
V_28 = F_32 ( V_25 , 100000 , & V_55 , & V_58 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_22 -> V_60 ( V_2 ,
V_54 -> V_44 , F_22 ( V_54 ) ,
F_21 ( V_54 ) , F_23 ( V_54 ) ,
V_55 , V_58 ) ;
if ( V_28 < 0 )
return V_28 ;
return V_53 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_61 * V_62 , unsigned int V_63 ,
enum V_48 type , enum V_41 V_47 ,
enum V_64 V_65 , const unsigned long * V_66 )
{
T_3 (* F_34)( struct V_50 * , struct V_52 * , char * );
T_3 (* F_35)( struct V_50 * , struct V_52 * ,
const char * , T_5 );
unsigned int V_67 = 0 ;
unsigned int V_68 ;
char * V_69 ;
int V_28 ;
F_36 (i, mask, sizeof(*mask)) {
V_69 = F_37 ( V_70 , L_3 ,
V_71 [ type ] , V_72 [ V_47 ] ,
V_73 [ V_68 ] ) ;
if ( V_69 == NULL )
return - V_74 ;
if ( V_68 == V_75 ) {
F_34 = F_28 ;
F_35 = F_24 ;
} else {
F_34 = F_29 ;
F_35 = F_31 ;
}
V_28 = F_38 ( V_69 , V_62 , F_34 , F_35 ,
( V_68 << 16 ) | V_63 , V_65 , & V_2 -> V_51 ,
& V_2 -> V_7 -> V_76 ) ;
F_39 ( V_69 ) ;
if ( V_28 )
return V_28 ;
V_67 ++ ;
}
return V_67 ;
}
static int F_40 ( struct V_1 * V_2 ,
struct V_61 const * V_62 )
{
int V_28 = 0 , V_68 , V_67 = 0 ;
enum V_41 V_47 ;
enum V_48 type ;
for ( V_68 = 0 ; V_68 < V_62 -> V_77 ; V_68 ++ ) {
type = V_62 -> V_45 [ V_68 ] . type ;
V_47 = V_62 -> V_45 [ V_68 ] . V_47 ;
V_28 = F_33 ( V_2 , V_62 , V_68 , type , V_47 ,
V_78 , & V_62 -> V_45 [ V_68 ] . V_79 ) ;
if ( V_28 < 0 )
return V_28 ;
V_67 += V_28 ;
V_28 = F_33 ( V_2 , V_62 , V_68 , type , V_47 ,
V_80 ,
& V_62 -> V_45 [ V_68 ] . V_81 ) ;
if ( V_28 < 0 )
return V_28 ;
V_67 += V_28 ;
V_28 = F_33 ( V_2 , V_62 , V_68 , type , V_47 ,
V_82 ,
& V_62 -> V_45 [ V_68 ] . V_83 ) ;
if ( V_28 < 0 )
return V_28 ;
V_67 += V_28 ;
V_28 = F_33 ( V_2 , V_62 , V_68 , type , V_47 ,
V_84 ,
& V_62 -> V_45 [ V_68 ] . V_85 ) ;
if ( V_28 < 0 )
return V_28 ;
V_67 += V_28 ;
}
V_28 = V_67 ;
return V_28 ;
}
static inline int F_41 ( struct V_1 * V_2 )
{
int V_86 , V_28 , V_67 = 0 ;
for ( V_86 = 0 ; V_86 < V_2 -> V_87 ; V_86 ++ ) {
V_28 = F_40 ( V_2 ,
& V_2 -> V_88 [ V_86 ] ) ;
if ( V_28 < 0 )
return V_28 ;
V_67 += V_28 ;
}
return V_67 ;
}
static bool F_42 ( struct V_1 * V_2 )
{
int V_86 ;
for ( V_86 = 0 ; V_86 < V_2 -> V_87 ; V_86 ++ ) {
if ( V_2 -> V_88 [ V_86 ] . V_77 != 0 )
return true ;
}
return false ;
}
static void F_43 ( struct V_5 * V_6 )
{
F_44 ( V_6 -> V_14 ) ;
F_45 ( & V_6 -> V_15 ) ;
F_46 ( & V_6 -> V_33 ) ;
}
int F_47 ( struct V_1 * V_2 )
{
struct V_42 * V_89 ;
int V_28 = 0 , V_90 = 0 , V_67 , V_91 ;
struct V_92 * * V_43 ;
if ( ! ( V_2 -> V_22 -> V_93 ||
F_42 ( V_2 ) ) )
return 0 ;
V_2 -> V_7 =
F_48 ( sizeof( struct V_5 ) , V_70 ) ;
if ( V_2 -> V_7 == NULL )
return - V_74 ;
F_49 ( & V_2 -> V_7 -> V_76 ) ;
F_43 ( V_2 -> V_7 ) ;
if ( V_2 -> V_22 -> V_93 != NULL ) {
V_43 = V_2 -> V_22 -> V_93 -> V_94 ;
while ( * V_43 ++ != NULL )
V_90 ++ ;
}
V_67 = V_90 ;
if ( V_2 -> V_88 ) {
V_28 = F_41 ( V_2 ) ;
if ( V_28 < 0 )
goto V_95;
V_67 += V_28 ;
}
V_2 -> V_7 -> V_96 . V_97 = V_98 ;
V_2 -> V_7 -> V_96 . V_94 = F_50 ( V_67 + 1 ,
sizeof( V_2 -> V_7 -> V_96 . V_94 [ 0 ] ) ,
V_70 ) ;
if ( V_2 -> V_7 -> V_96 . V_94 == NULL ) {
V_28 = - V_74 ;
goto V_95;
}
if ( V_2 -> V_22 -> V_93 )
memcpy ( V_2 -> V_7 -> V_96 . V_94 ,
V_2 -> V_22 -> V_93 -> V_94 ,
sizeof( V_2 -> V_7 -> V_96 . V_94 [ 0 ] )
* V_90 ) ;
V_91 = V_90 ;
F_51 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_2 -> V_7 -> V_96 . V_94 [ V_91 ++ ] =
& V_89 -> V_99 . V_43 ;
V_2 -> V_100 [ V_2 -> V_101 ++ ] =
& V_2 -> V_7 -> V_96 ;
return 0 ;
V_95:
F_52 ( & V_2 -> V_7 -> V_76 ) ;
F_39 ( V_2 -> V_7 ) ;
return V_28 ;
}
void F_53 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_54 ( & V_2 -> V_7 -> V_15 ) ;
}
void F_55 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_52 ( & V_2 -> V_7 -> V_76 ) ;
F_39 ( V_2 -> V_7 -> V_96 . V_94 ) ;
F_39 ( V_2 -> V_7 ) ;
}
