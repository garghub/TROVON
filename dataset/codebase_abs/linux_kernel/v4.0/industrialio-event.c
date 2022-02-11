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
int V_55 , V_58 , V_59 [ 2 ] ;
int V_28 ;
V_28 = V_2 -> V_22 -> V_60 ( V_2 ,
V_54 -> V_44 , F_22 ( V_54 ) ,
F_21 ( V_54 ) , F_23 ( V_54 ) ,
& V_55 , & V_58 ) ;
if ( V_28 < 0 )
return V_28 ;
V_59 [ 0 ] = V_55 ;
V_59 [ 1 ] = V_58 ;
return F_30 ( V_25 , V_28 , 2 , V_59 ) ;
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
if ( ! V_2 -> V_22 -> V_61 )
return - V_29 ;
V_28 = F_32 ( V_25 , 100000 , & V_55 , & V_58 ) ;
if ( V_28 )
return V_28 ;
V_28 = V_2 -> V_22 -> V_61 ( V_2 ,
V_54 -> V_44 , F_22 ( V_54 ) ,
F_21 ( V_54 ) , F_23 ( V_54 ) ,
V_55 , V_58 ) ;
if ( V_28 < 0 )
return V_28 ;
return V_53 ;
}
static int F_33 ( struct V_1 * V_2 ,
const struct V_62 * V_63 , unsigned int V_64 ,
enum V_48 type , enum V_41 V_47 ,
enum V_65 V_66 , const unsigned long * V_67 )
{
T_3 (* F_34)( struct V_50 * , struct V_52 * , char * );
T_3 (* F_35)( struct V_50 * , struct V_52 * ,
const char * , T_5 );
unsigned int V_68 = 0 ;
unsigned int V_69 ;
char * V_70 ;
int V_28 ;
F_36 (i, mask, sizeof(*mask)*8 ) {
if ( V_69 >= F_37 ( V_71 ) )
return - V_29 ;
if ( V_47 != V_72 )
V_70 = F_38 ( V_73 , L_3 ,
V_74 [ type ] ,
V_75 [ V_47 ] ,
V_71 [ V_69 ] ) ;
else
V_70 = F_38 ( V_73 , L_4 ,
V_74 [ type ] ,
V_71 [ V_69 ] ) ;
if ( V_70 == NULL )
return - V_76 ;
if ( V_69 == V_77 ) {
F_34 = F_28 ;
F_35 = F_24 ;
} else {
F_34 = F_29 ;
F_35 = F_31 ;
}
V_28 = F_39 ( V_70 , V_63 , F_34 , F_35 ,
( V_69 << 16 ) | V_64 , V_66 , & V_2 -> V_51 ,
& V_2 -> V_7 -> V_78 ) ;
F_40 ( V_70 ) ;
if ( ( V_28 == - V_37 ) && ( V_66 != V_79 ) )
continue;
if ( V_28 )
return V_28 ;
V_68 ++ ;
}
return V_68 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_62 const * V_63 )
{
int V_28 = 0 , V_69 , V_68 = 0 ;
enum V_41 V_47 ;
enum V_48 type ;
for ( V_69 = 0 ; V_69 < V_63 -> V_80 ; V_69 ++ ) {
type = V_63 -> V_45 [ V_69 ] . type ;
V_47 = V_63 -> V_45 [ V_69 ] . V_47 ;
V_28 = F_33 ( V_2 , V_63 , V_69 , type , V_47 ,
V_79 , & V_63 -> V_45 [ V_69 ] . V_81 ) ;
if ( V_28 < 0 )
return V_28 ;
V_68 += V_28 ;
V_28 = F_33 ( V_2 , V_63 , V_69 , type , V_47 ,
V_82 ,
& V_63 -> V_45 [ V_69 ] . V_83 ) ;
if ( V_28 < 0 )
return V_28 ;
V_68 += V_28 ;
V_28 = F_33 ( V_2 , V_63 , V_69 , type , V_47 ,
V_84 ,
& V_63 -> V_45 [ V_69 ] . V_85 ) ;
if ( V_28 < 0 )
return V_28 ;
V_68 += V_28 ;
V_28 = F_33 ( V_2 , V_63 , V_69 , type , V_47 ,
V_86 ,
& V_63 -> V_45 [ V_69 ] . V_87 ) ;
if ( V_28 < 0 )
return V_28 ;
V_68 += V_28 ;
}
V_28 = V_68 ;
return V_28 ;
}
static inline int F_42 ( struct V_1 * V_2 )
{
int V_88 , V_28 , V_68 = 0 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_89 ; V_88 ++ ) {
V_28 = F_41 ( V_2 ,
& V_2 -> V_90 [ V_88 ] ) ;
if ( V_28 < 0 )
return V_28 ;
V_68 += V_28 ;
}
return V_68 ;
}
static bool F_43 ( struct V_1 * V_2 )
{
int V_88 ;
for ( V_88 = 0 ; V_88 < V_2 -> V_89 ; V_88 ++ ) {
if ( V_2 -> V_90 [ V_88 ] . V_80 != 0 )
return true ;
}
return false ;
}
static void F_44 ( struct V_5 * V_6 )
{
F_45 ( V_6 -> V_14 ) ;
F_46 ( & V_6 -> V_15 ) ;
F_47 ( & V_6 -> V_33 ) ;
}
int F_48 ( struct V_1 * V_2 )
{
struct V_42 * V_91 ;
int V_28 = 0 , V_92 = 0 , V_68 , V_93 ;
struct V_94 * * V_43 ;
if ( ! ( V_2 -> V_22 -> V_95 ||
F_43 ( V_2 ) ) )
return 0 ;
V_2 -> V_7 =
F_49 ( sizeof( struct V_5 ) , V_73 ) ;
if ( V_2 -> V_7 == NULL )
return - V_76 ;
F_50 ( & V_2 -> V_7 -> V_78 ) ;
F_44 ( V_2 -> V_7 ) ;
if ( V_2 -> V_22 -> V_95 != NULL ) {
V_43 = V_2 -> V_22 -> V_95 -> V_96 ;
while ( * V_43 ++ != NULL )
V_92 ++ ;
}
V_68 = V_92 ;
if ( V_2 -> V_90 ) {
V_28 = F_42 ( V_2 ) ;
if ( V_28 < 0 )
goto V_97;
V_68 += V_28 ;
}
V_2 -> V_7 -> V_98 . V_99 = V_100 ;
V_2 -> V_7 -> V_98 . V_96 = F_51 ( V_68 + 1 ,
sizeof( V_2 -> V_7 -> V_98 . V_96 [ 0 ] ) ,
V_73 ) ;
if ( V_2 -> V_7 -> V_98 . V_96 == NULL ) {
V_28 = - V_76 ;
goto V_97;
}
if ( V_2 -> V_22 -> V_95 )
memcpy ( V_2 -> V_7 -> V_98 . V_96 ,
V_2 -> V_22 -> V_95 -> V_96 ,
sizeof( V_2 -> V_7 -> V_98 . V_96 [ 0 ] )
* V_92 ) ;
V_93 = V_92 ;
F_52 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_2 -> V_7 -> V_98 . V_96 [ V_93 ++ ] =
& V_91 -> V_101 . V_43 ;
V_2 -> V_102 [ V_2 -> V_103 ++ ] =
& V_2 -> V_7 -> V_98 ;
return 0 ;
V_97:
F_53 ( & V_2 -> V_7 -> V_78 ) ;
F_40 ( V_2 -> V_7 ) ;
V_2 -> V_7 = NULL ;
return V_28 ;
}
void F_54 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_55 ( & V_2 -> V_7 -> V_15 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_53 ( & V_2 -> V_7 -> V_78 ) ;
F_40 ( V_2 -> V_7 -> V_98 . V_96 ) ;
F_40 ( V_2 -> V_7 ) ;
}
