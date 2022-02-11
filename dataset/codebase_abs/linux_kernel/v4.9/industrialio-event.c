bool F_1 ( const struct V_1 * V_2 )
{
return ! ! F_2 ( V_3 , & V_2 -> V_4 ) ;
}
int F_3 ( struct V_5 * V_6 , T_1 V_7 , T_2 V_8 )
{
struct V_1 * V_2 = V_6 -> V_9 ;
struct V_10 V_11 ;
int V_12 ;
if ( ! V_2 )
return 0 ;
if ( F_1 ( V_2 ) ) {
V_11 . V_13 = V_7 ;
V_11 . V_8 = V_8 ;
V_12 = F_4 ( & V_2 -> V_14 , V_11 ) ;
if ( V_12 != 0 )
F_5 ( & V_2 -> V_15 , V_16 ) ;
}
return 0 ;
}
static unsigned int F_6 ( struct V_17 * V_18 ,
struct V_19 * V_15 )
{
struct V_5 * V_6 = V_18 -> V_20 ;
struct V_1 * V_2 = V_6 -> V_9 ;
unsigned int V_21 = 0 ;
if ( ! V_6 -> V_22 )
return V_21 ;
F_7 ( V_18 , & V_2 -> V_15 , V_15 ) ;
if ( ! F_8 ( & V_2 -> V_14 ) )
V_21 = V_16 | V_23 ;
return V_21 ;
}
static T_3 F_9 ( struct V_17 * V_18 ,
char T_4 * V_24 ,
T_5 V_25 ,
T_6 * V_26 )
{
struct V_5 * V_6 = V_18 -> V_20 ;
struct V_1 * V_2 = V_6 -> V_9 ;
unsigned int V_12 ;
int V_27 ;
if ( ! V_6 -> V_22 )
return - V_28 ;
if ( V_25 < sizeof( struct V_10 ) )
return - V_29 ;
do {
if ( F_8 ( & V_2 -> V_14 ) ) {
if ( V_18 -> V_30 & V_31 )
return - V_32 ;
V_27 = F_10 ( V_2 -> V_15 ,
! F_8 ( & V_2 -> V_14 ) ||
V_6 -> V_22 == NULL ) ;
if ( V_27 )
return V_27 ;
if ( V_6 -> V_22 == NULL )
return - V_28 ;
}
if ( F_11 ( & V_2 -> V_33 ) )
return - V_34 ;
V_27 = F_12 ( & V_2 -> V_14 , V_24 , V_25 , & V_12 ) ;
F_13 ( & V_2 -> V_33 ) ;
if ( V_27 )
return V_27 ;
if ( V_12 == 0 && ( V_18 -> V_30 & V_31 ) )
return - V_32 ;
} while ( V_12 == 0 );
return V_12 ;
}
static int F_14 ( struct V_35 * V_35 , struct V_17 * V_18 )
{
struct V_5 * V_6 = V_18 -> V_20 ;
struct V_1 * V_2 = V_6 -> V_9 ;
F_15 ( V_3 , & V_2 -> V_4 ) ;
F_16 ( V_6 ) ;
return 0 ;
}
int F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_9 ;
int V_36 ;
if ( V_2 == NULL )
return - V_28 ;
V_36 = F_11 ( & V_6 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( F_18 ( V_3 , & V_2 -> V_4 ) ) {
V_36 = - V_38 ;
goto V_39;
}
F_19 ( V_6 ) ;
V_36 = F_20 ( L_1 , & V_40 ,
V_6 , V_41 | V_42 ) ;
if ( V_36 < 0 ) {
F_15 ( V_3 , & V_2 -> V_4 ) ;
F_16 ( V_6 ) ;
} else {
F_21 ( & V_2 -> V_14 ) ;
}
V_39:
F_13 ( & V_6 -> V_37 ) ;
return V_36 ;
}
static enum V_43 F_22 ( struct V_44 * V_45 )
{
return V_45 -> V_46 -> V_47 [ V_45 -> V_48 & 0xffff ] . V_49 ;
}
static enum V_50 F_23 ( struct V_44 * V_45 )
{
return V_45 -> V_46 -> V_47 [ V_45 -> V_48 & 0xffff ] . type ;
}
static enum V_51 F_24 ( struct V_44 * V_45 )
{
return ( V_45 -> V_48 >> 16 ) & 0xffff ;
}
static T_3 F_25 ( struct V_52 * V_53 ,
struct V_54 * V_45 ,
const char * V_24 ,
T_5 V_55 )
{
struct V_5 * V_6 = F_26 ( V_53 ) ;
struct V_44 * V_56 = F_27 ( V_45 ) ;
int V_27 ;
bool V_57 ;
V_27 = F_28 ( V_24 , & V_57 ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = V_6 -> V_22 -> V_58 ( V_6 ,
V_56 -> V_46 , F_23 ( V_56 ) ,
F_22 ( V_56 ) , V_57 ) ;
return ( V_27 < 0 ) ? V_27 : V_55 ;
}
static T_3 F_29 ( struct V_52 * V_53 ,
struct V_54 * V_45 ,
char * V_24 )
{
struct V_5 * V_6 = F_26 ( V_53 ) ;
struct V_44 * V_56 = F_27 ( V_45 ) ;
int V_57 ;
V_57 = V_6 -> V_22 -> V_59 ( V_6 ,
V_56 -> V_46 , F_23 ( V_56 ) ,
F_22 ( V_56 ) ) ;
if ( V_57 < 0 )
return V_57 ;
else
return sprintf ( V_24 , L_2 , V_57 ) ;
}
static T_3 F_30 ( struct V_52 * V_53 ,
struct V_54 * V_45 ,
char * V_24 )
{
struct V_5 * V_6 = F_26 ( V_53 ) ;
struct V_44 * V_56 = F_27 ( V_45 ) ;
int V_57 , V_60 , V_61 [ 2 ] ;
int V_27 ;
V_27 = V_6 -> V_22 -> V_62 ( V_6 ,
V_56 -> V_46 , F_23 ( V_56 ) ,
F_22 ( V_56 ) , F_24 ( V_56 ) ,
& V_57 , & V_60 ) ;
if ( V_27 < 0 )
return V_27 ;
V_61 [ 0 ] = V_57 ;
V_61 [ 1 ] = V_60 ;
return F_31 ( V_24 , V_27 , 2 , V_61 ) ;
}
static T_3 F_32 ( struct V_52 * V_53 ,
struct V_54 * V_45 ,
const char * V_24 ,
T_5 V_55 )
{
struct V_5 * V_6 = F_26 ( V_53 ) ;
struct V_44 * V_56 = F_27 ( V_45 ) ;
int V_57 , V_60 ;
int V_27 ;
if ( ! V_6 -> V_22 -> V_63 )
return - V_29 ;
V_27 = F_33 ( V_24 , 100000 , & V_57 , & V_60 ) ;
if ( V_27 )
return V_27 ;
V_27 = V_6 -> V_22 -> V_63 ( V_6 ,
V_56 -> V_46 , F_23 ( V_56 ) ,
F_22 ( V_56 ) , F_24 ( V_56 ) ,
V_57 , V_60 ) ;
if ( V_27 < 0 )
return V_27 ;
return V_55 ;
}
static int F_34 ( struct V_5 * V_6 ,
const struct V_64 * V_65 , unsigned int V_66 ,
enum V_50 type , enum V_43 V_49 ,
enum V_67 V_68 , const unsigned long * V_69 )
{
T_3 (* F_35)( struct V_52 * , struct V_54 * , char * );
T_3 (* F_36)( struct V_52 * , struct V_54 * ,
const char * , T_5 );
unsigned int V_70 = 0 ;
unsigned int V_71 ;
char * V_72 ;
int V_27 ;
F_37 (i, mask, sizeof(*mask)*8 ) {
if ( V_71 >= F_38 ( V_73 ) )
return - V_29 ;
if ( V_49 != V_74 )
V_72 = F_39 ( V_75 , L_3 ,
V_76 [ type ] ,
V_77 [ V_49 ] ,
V_73 [ V_71 ] ) ;
else
V_72 = F_39 ( V_75 , L_4 ,
V_76 [ type ] ,
V_73 [ V_71 ] ) ;
if ( V_72 == NULL )
return - V_78 ;
if ( V_71 == V_79 ) {
F_35 = F_29 ;
F_36 = F_25 ;
} else {
F_35 = F_30 ;
F_36 = F_32 ;
}
V_27 = F_40 ( V_72 , V_65 , F_35 , F_36 ,
( V_71 << 16 ) | V_66 , V_68 , & V_6 -> V_53 ,
& V_6 -> V_9 -> V_80 ) ;
F_41 ( V_72 ) ;
if ( ( V_27 == - V_38 ) && ( V_68 != V_81 ) )
continue;
if ( V_27 )
return V_27 ;
V_70 ++ ;
}
return V_70 ;
}
static int F_42 ( struct V_5 * V_6 ,
struct V_64 const * V_65 )
{
int V_27 = 0 , V_71 , V_70 = 0 ;
enum V_43 V_49 ;
enum V_50 type ;
for ( V_71 = 0 ; V_71 < V_65 -> V_82 ; V_71 ++ ) {
type = V_65 -> V_47 [ V_71 ] . type ;
V_49 = V_65 -> V_47 [ V_71 ] . V_49 ;
V_27 = F_34 ( V_6 , V_65 , V_71 , type , V_49 ,
V_81 , & V_65 -> V_47 [ V_71 ] . V_83 ) ;
if ( V_27 < 0 )
return V_27 ;
V_70 += V_27 ;
V_27 = F_34 ( V_6 , V_65 , V_71 , type , V_49 ,
V_84 ,
& V_65 -> V_47 [ V_71 ] . V_85 ) ;
if ( V_27 < 0 )
return V_27 ;
V_70 += V_27 ;
V_27 = F_34 ( V_6 , V_65 , V_71 , type , V_49 ,
V_86 ,
& V_65 -> V_47 [ V_71 ] . V_87 ) ;
if ( V_27 < 0 )
return V_27 ;
V_70 += V_27 ;
V_27 = F_34 ( V_6 , V_65 , V_71 , type , V_49 ,
V_88 ,
& V_65 -> V_47 [ V_71 ] . V_89 ) ;
if ( V_27 < 0 )
return V_27 ;
V_70 += V_27 ;
}
V_27 = V_70 ;
return V_27 ;
}
static inline int F_43 ( struct V_5 * V_6 )
{
int V_90 , V_27 , V_70 = 0 ;
for ( V_90 = 0 ; V_90 < V_6 -> V_91 ; V_90 ++ ) {
V_27 = F_42 ( V_6 ,
& V_6 -> V_92 [ V_90 ] ) ;
if ( V_27 < 0 )
return V_27 ;
V_70 += V_27 ;
}
return V_70 ;
}
static bool F_44 ( struct V_5 * V_6 )
{
int V_90 ;
for ( V_90 = 0 ; V_90 < V_6 -> V_91 ; V_90 ++ ) {
if ( V_6 -> V_92 [ V_90 ] . V_82 != 0 )
return true ;
}
return false ;
}
static void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_2 -> V_14 ) ;
F_47 ( & V_2 -> V_15 ) ;
F_48 ( & V_2 -> V_33 ) ;
}
int F_49 ( struct V_5 * V_6 )
{
struct V_44 * V_93 ;
int V_27 = 0 , V_94 = 0 , V_70 , V_95 ;
struct V_96 * * V_45 ;
if ( ! ( V_6 -> V_22 -> V_97 ||
F_44 ( V_6 ) ) )
return 0 ;
V_6 -> V_9 =
F_50 ( sizeof( struct V_1 ) , V_75 ) ;
if ( V_6 -> V_9 == NULL )
return - V_78 ;
F_51 ( & V_6 -> V_9 -> V_80 ) ;
F_45 ( V_6 -> V_9 ) ;
if ( V_6 -> V_22 -> V_97 != NULL ) {
V_45 = V_6 -> V_22 -> V_97 -> V_98 ;
while ( * V_45 ++ != NULL )
V_94 ++ ;
}
V_70 = V_94 ;
if ( V_6 -> V_92 ) {
V_27 = F_43 ( V_6 ) ;
if ( V_27 < 0 )
goto V_99;
V_70 += V_27 ;
}
V_6 -> V_9 -> V_100 . V_101 = V_102 ;
V_6 -> V_9 -> V_100 . V_98 = F_52 ( V_70 + 1 ,
sizeof( V_6 -> V_9 -> V_100 . V_98 [ 0 ] ) ,
V_75 ) ;
if ( V_6 -> V_9 -> V_100 . V_98 == NULL ) {
V_27 = - V_78 ;
goto V_99;
}
if ( V_6 -> V_22 -> V_97 )
memcpy ( V_6 -> V_9 -> V_100 . V_98 ,
V_6 -> V_22 -> V_97 -> V_98 ,
sizeof( V_6 -> V_9 -> V_100 . V_98 [ 0 ] )
* V_94 ) ;
V_95 = V_94 ;
F_53 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_6 -> V_9 -> V_100 . V_98 [ V_95 ++ ] =
& V_93 -> V_103 . V_45 ;
V_6 -> V_104 [ V_6 -> V_105 ++ ] =
& V_6 -> V_9 -> V_100 ;
return 0 ;
V_99:
F_54 ( & V_6 -> V_9 -> V_80 ) ;
F_41 ( V_6 -> V_9 ) ;
V_6 -> V_9 = NULL ;
return V_27 ;
}
void F_55 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 == NULL )
return;
F_56 ( & V_6 -> V_9 -> V_15 ) ;
}
void F_57 ( struct V_5 * V_6 )
{
if ( V_6 -> V_9 == NULL )
return;
F_54 ( & V_6 -> V_9 -> V_80 ) ;
F_41 ( V_6 -> V_9 -> V_100 . V_98 ) ;
F_41 ( V_6 -> V_9 ) ;
}
