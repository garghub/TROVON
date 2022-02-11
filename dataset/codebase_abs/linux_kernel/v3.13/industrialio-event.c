int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 V_9 ;
unsigned long V_10 ;
int V_11 ;
F_2 ( & V_6 -> V_12 . V_13 , V_10 ) ;
if ( F_3 ( V_14 , & V_6 -> V_10 ) ) {
V_9 . V_15 = V_3 ;
V_9 . V_4 = V_4 ;
V_11 = F_4 ( & V_6 -> V_16 , V_9 ) ;
if ( V_11 != 0 )
F_5 ( & V_6 -> V_12 , V_17 ) ;
}
F_6 ( & V_6 -> V_12 . V_13 , V_10 ) ;
return 0 ;
}
static unsigned int F_7 ( struct V_18 * V_19 ,
struct V_20 * V_12 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_22 = 0 ;
if ( ! V_2 -> V_23 )
return - V_24 ;
F_8 ( V_19 , & V_6 -> V_12 , V_12 ) ;
F_9 ( & V_6 -> V_12 . V_13 ) ;
if ( ! F_10 ( & V_6 -> V_16 ) )
V_22 = V_17 | V_25 ;
F_11 ( & V_6 -> V_12 . V_13 ) ;
return V_22 ;
}
static T_3 F_12 ( struct V_18 * V_19 ,
char T_4 * V_26 ,
T_5 V_27 ,
T_6 * V_28 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_11 ;
int V_29 ;
if ( ! V_2 -> V_23 )
return - V_24 ;
if ( V_27 < sizeof( struct V_8 ) )
return - V_30 ;
F_9 ( & V_6 -> V_12 . V_13 ) ;
if ( F_10 ( & V_6 -> V_16 ) ) {
if ( V_19 -> V_31 & V_32 ) {
V_29 = - V_33 ;
goto V_34;
}
V_29 = F_13 ( V_6 -> V_12 ,
! F_10 ( & V_6 -> V_16 ) ||
V_2 -> V_23 == NULL ) ;
if ( V_29 )
goto V_34;
if ( V_2 -> V_23 == NULL ) {
V_29 = - V_24 ;
goto V_34;
}
}
V_29 = F_14 ( & V_6 -> V_16 , V_26 , V_27 , & V_11 ) ;
V_34:
F_11 ( & V_6 -> V_12 . V_13 ) ;
return V_29 ? V_29 : V_11 ;
}
static int F_15 ( struct V_35 * V_35 , struct V_18 * V_19 )
{
struct V_1 * V_2 = V_19 -> V_21 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_9 ( & V_6 -> V_12 . V_13 ) ;
F_16 ( V_14 , & V_6 -> V_10 ) ;
F_17 ( & V_6 -> V_16 ) ;
F_11 ( & V_6 -> V_12 . V_13 ) ;
F_18 ( V_2 ) ;
return 0 ;
}
int F_19 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_36 ;
if ( V_6 == NULL )
return - V_24 ;
F_9 ( & V_6 -> V_12 . V_13 ) ;
if ( F_20 ( V_14 , & V_6 -> V_10 ) ) {
F_11 ( & V_6 -> V_12 . V_13 ) ;
return - V_37 ;
}
F_11 ( & V_6 -> V_12 . V_13 ) ;
F_21 ( V_2 ) ;
V_36 = F_22 ( L_1 , & V_38 ,
V_2 , V_39 | V_40 ) ;
if ( V_36 < 0 ) {
F_9 ( & V_6 -> V_12 . V_13 ) ;
F_16 ( V_14 , & V_6 -> V_10 ) ;
F_11 ( & V_6 -> V_12 . V_13 ) ;
F_18 ( V_2 ) ;
}
return V_36 ;
}
static enum V_41 F_23 ( struct V_42 * V_43 )
{
return V_43 -> V_44 -> V_45 [ V_43 -> V_46 & 0xffff ] . V_47 ;
}
static enum V_48 F_24 ( struct V_42 * V_43 )
{
return V_43 -> V_44 -> V_45 [ V_43 -> V_46 & 0xffff ] . type ;
}
static enum V_49 F_25 ( struct V_42 * V_43 )
{
return ( V_43 -> V_46 >> 16 ) & 0xffff ;
}
static T_3 F_26 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
const char * V_26 ,
T_5 V_53 )
{
struct V_1 * V_2 = F_27 ( V_51 ) ;
struct V_42 * V_54 = F_28 ( V_43 ) ;
int V_29 ;
bool V_55 ;
V_29 = F_29 ( V_26 , & V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( V_2 -> V_23 -> V_56 )
V_29 = V_2 -> V_23 -> V_56 ( V_2 ,
V_54 -> V_46 , V_55 ) ;
else
V_29 = V_2 -> V_23 -> V_57 ( V_2 ,
V_54 -> V_44 , F_24 ( V_54 ) ,
F_23 ( V_54 ) , V_55 ) ;
return ( V_29 < 0 ) ? V_29 : V_53 ;
}
static T_3 F_30 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
char * V_26 )
{
struct V_1 * V_2 = F_27 ( V_51 ) ;
struct V_42 * V_54 = F_28 ( V_43 ) ;
int V_55 ;
if ( V_2 -> V_23 -> V_58 )
V_55 = V_2 -> V_23 -> V_58 ( V_2 ,
V_54 -> V_46 ) ;
else
V_55 = V_2 -> V_23 -> V_59 ( V_2 ,
V_54 -> V_44 , F_24 ( V_54 ) ,
F_23 ( V_54 ) ) ;
if ( V_55 < 0 )
return V_55 ;
else
return sprintf ( V_26 , L_2 , V_55 ) ;
}
static T_3 F_31 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
char * V_26 )
{
struct V_1 * V_2 = F_27 ( V_51 ) ;
struct V_42 * V_54 = F_28 ( V_43 ) ;
int V_55 , V_60 ;
int V_29 ;
if ( V_2 -> V_23 -> V_61 ) {
V_29 = V_2 -> V_23 -> V_61 ( V_2 ,
V_54 -> V_46 , & V_55 ) ;
if ( V_29 < 0 )
return V_29 ;
return sprintf ( V_26 , L_2 , V_55 ) ;
} else {
V_29 = V_2 -> V_23 -> V_62 ( V_2 ,
V_54 -> V_44 , F_24 ( V_54 ) ,
F_23 ( V_54 ) , F_25 ( V_54 ) ,
& V_55 , & V_60 ) ;
if ( V_29 < 0 )
return V_29 ;
return F_32 ( V_26 , V_29 , V_55 , V_60 ) ;
}
}
static T_3 F_33 ( struct V_50 * V_51 ,
struct V_52 * V_43 ,
const char * V_26 ,
T_5 V_53 )
{
struct V_1 * V_2 = F_27 ( V_51 ) ;
struct V_42 * V_54 = F_28 ( V_43 ) ;
int V_55 , V_60 ;
int V_29 ;
if ( ! V_2 -> V_23 -> V_63 &&
! V_2 -> V_23 -> V_64 )
return - V_30 ;
if ( V_2 -> V_23 -> V_63 ) {
V_29 = F_34 ( V_26 , 10 , & V_55 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_2 -> V_23 -> V_63 ( V_2 ,
V_54 -> V_46 , V_55 ) ;
} else {
V_29 = F_35 ( V_26 , 100000 , & V_55 , & V_60 ) ;
if ( V_29 )
return V_29 ;
V_29 = V_2 -> V_23 -> V_64 ( V_2 ,
V_54 -> V_44 , F_24 ( V_54 ) ,
F_23 ( V_54 ) , F_25 ( V_54 ) ,
V_55 , V_60 ) ;
}
if ( V_29 < 0 )
return V_29 ;
return V_53 ;
}
static int F_36 ( struct V_1 * V_2 ,
const struct V_65 * V_66 , unsigned int V_67 ,
enum V_48 type , enum V_41 V_47 ,
enum V_68 V_69 , const unsigned long * V_70 )
{
T_3 (* F_37)( struct V_50 * , struct V_52 * , char * );
T_3 (* F_38)( struct V_50 * , struct V_52 * ,
const char * , T_5 );
unsigned int V_71 = 0 ;
unsigned int V_72 ;
char * V_73 ;
int V_29 ;
F_39 (i, mask, sizeof(*mask)) {
V_73 = F_40 ( V_74 , L_3 ,
V_75 [ type ] , V_76 [ V_47 ] ,
V_77 [ V_72 ] ) ;
if ( V_73 == NULL )
return - V_78 ;
if ( V_72 == V_79 ) {
F_37 = F_30 ;
F_38 = F_26 ;
} else {
F_37 = F_31 ;
F_38 = F_33 ;
}
V_29 = F_41 ( V_73 , V_66 , F_37 , F_38 ,
( V_72 << 16 ) | V_67 , V_69 , & V_2 -> V_51 ,
& V_2 -> V_7 -> V_80 ) ;
F_42 ( V_73 ) ;
if ( V_29 )
return V_29 ;
V_71 ++ ;
}
return V_71 ;
}
static int F_43 ( struct V_1 * V_2 ,
struct V_65 const * V_66 )
{
int V_29 = 0 , V_72 , V_71 = 0 ;
enum V_41 V_47 ;
enum V_48 type ;
for ( V_72 = 0 ; V_72 < V_66 -> V_81 ; V_72 ++ ) {
type = V_66 -> V_45 [ V_72 ] . type ;
V_47 = V_66 -> V_45 [ V_72 ] . V_47 ;
V_29 = F_36 ( V_2 , V_66 , V_72 , type , V_47 ,
V_82 , & V_66 -> V_45 [ V_72 ] . V_83 ) ;
if ( V_29 < 0 )
goto V_84;
V_71 += V_29 ;
V_29 = F_36 ( V_2 , V_66 , V_72 , type , V_47 ,
V_85 ,
& V_66 -> V_45 [ V_72 ] . V_86 ) ;
if ( V_29 < 0 )
goto V_84;
V_71 += V_29 ;
V_29 = F_36 ( V_2 , V_66 , V_72 , type , V_47 ,
V_87 ,
& V_66 -> V_45 [ V_72 ] . V_88 ) ;
if ( V_29 < 0 )
goto V_84;
V_71 += V_29 ;
V_29 = F_36 ( V_2 , V_66 , V_72 , type , V_47 ,
V_89 ,
& V_66 -> V_45 [ V_72 ] . V_90 ) ;
if ( V_29 < 0 )
goto V_84;
V_71 += V_29 ;
}
V_29 = V_71 ;
V_84:
return V_29 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_65 const * V_66 )
{
int V_29 = 0 , V_72 , V_71 = 0 ;
T_1 V_70 = 0 ;
char * V_73 ;
if ( ! V_66 -> V_91 )
return 0 ;
F_39 (i, &chan->event_mask, sizeof(chan->event_mask)*8 ) {
V_73 = F_40 ( V_74 , L_4 ,
V_75 [ V_72 / V_92 ] ,
V_76 [ V_72 % V_92 ] ) ;
if ( V_73 == NULL ) {
V_29 = - V_78 ;
goto V_84;
}
if ( V_66 -> V_93 )
V_70 = F_45 ( V_66 -> type , 0 , V_66 -> V_94 ,
V_72 / V_92 ,
V_72 % V_92 ) ;
else if ( V_66 -> V_95 )
V_70 = F_46 ( V_66 -> type ,
0 , 0 ,
V_72 % V_92 ,
V_72 / V_92 ,
0 ,
V_66 -> V_96 ,
V_66 -> V_94 ) ;
else
V_70 = F_47 ( V_66 -> type ,
V_66 -> V_96 ,
V_72 / V_92 ,
V_72 % V_92 ) ;
V_29 = F_41 ( V_73 ,
V_66 ,
& F_30 ,
F_26 ,
V_70 ,
0 ,
& V_2 -> V_51 ,
& V_2 -> V_7 ->
V_80 ) ;
F_42 ( V_73 ) ;
if ( V_29 )
goto V_84;
V_71 ++ ;
V_73 = F_40 ( V_74 , L_5 ,
V_75 [ V_72 / V_92 ] ,
V_76 [ V_72 % V_92 ] ) ;
if ( V_73 == NULL ) {
V_29 = - V_78 ;
goto V_84;
}
V_29 = F_41 ( V_73 , V_66 ,
F_31 ,
F_33 ,
V_70 ,
0 ,
& V_2 -> V_51 ,
& V_2 -> V_7 ->
V_80 ) ;
F_42 ( V_73 ) ;
if ( V_29 )
goto V_84;
V_71 ++ ;
}
V_29 = V_71 ;
V_84:
return V_29 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_65 const * V_66 )
{
if ( V_66 -> V_91 )
return F_44 ( V_2 , V_66 ) ;
else
return F_43 ( V_2 , V_66 ) ;
}
static inline int F_49 ( struct V_1 * V_2 )
{
int V_97 , V_29 , V_71 = 0 ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
V_29 = F_48 ( V_2 ,
& V_2 -> V_99 [ V_97 ] ) ;
if ( V_29 < 0 )
return V_29 ;
V_71 += V_29 ;
}
return V_71 ;
}
static bool F_50 ( struct V_1 * V_2 )
{
int V_97 ;
for ( V_97 = 0 ; V_97 < V_2 -> V_98 ; V_97 ++ ) {
if ( V_2 -> V_99 [ V_97 ] . V_91 != 0 )
return true ;
if ( V_2 -> V_99 [ V_97 ] . V_81 != 0 )
return true ;
}
return false ;
}
static void F_51 ( struct V_5 * V_6 )
{
F_52 ( V_6 -> V_16 ) ;
F_53 ( & V_6 -> V_12 ) ;
}
int F_54 ( struct V_1 * V_2 )
{
struct V_42 * V_100 ;
int V_29 = 0 , V_101 = 0 , V_71 , V_102 ;
struct V_103 * * V_43 ;
if ( ! ( V_2 -> V_23 -> V_104 ||
F_50 ( V_2 ) ) )
return 0 ;
V_2 -> V_7 =
F_55 ( sizeof( struct V_5 ) , V_74 ) ;
if ( V_2 -> V_7 == NULL ) {
V_29 = - V_78 ;
goto V_84;
}
F_56 ( & V_2 -> V_7 -> V_80 ) ;
F_51 ( V_2 -> V_7 ) ;
if ( V_2 -> V_23 -> V_104 != NULL ) {
V_43 = V_2 -> V_23 -> V_104 -> V_105 ;
while ( * V_43 ++ != NULL )
V_101 ++ ;
}
V_71 = V_101 ;
if ( V_2 -> V_99 ) {
V_29 = F_49 ( V_2 ) ;
if ( V_29 < 0 )
goto V_106;
V_71 += V_29 ;
}
V_2 -> V_7 -> V_107 . V_108 = V_109 ;
V_2 -> V_7 -> V_107 . V_105 = F_57 ( V_71 + 1 ,
sizeof( V_2 -> V_7 -> V_107 . V_105 [ 0 ] ) ,
V_74 ) ;
if ( V_2 -> V_7 -> V_107 . V_105 == NULL ) {
V_29 = - V_78 ;
goto V_106;
}
if ( V_2 -> V_23 -> V_104 )
memcpy ( V_2 -> V_7 -> V_107 . V_105 ,
V_2 -> V_23 -> V_104 -> V_105 ,
sizeof( V_2 -> V_7 -> V_107 . V_105 [ 0 ] )
* V_101 ) ;
V_102 = V_101 ;
F_58 (p,
&indio_dev->event_interface->dev_attr_list,
l)
V_2 -> V_7 -> V_107 . V_105 [ V_102 ++ ] =
& V_100 -> V_110 . V_43 ;
V_2 -> V_111 [ V_2 -> V_112 ++ ] =
& V_2 -> V_7 -> V_107 ;
return 0 ;
V_106:
F_59 ( & V_2 -> V_7 -> V_80 ) ;
F_42 ( V_2 -> V_7 ) ;
V_84:
return V_29 ;
}
void F_60 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_61 ( & V_2 -> V_7 -> V_12 ) ;
}
void F_62 ( struct V_1 * V_2 )
{
if ( V_2 -> V_7 == NULL )
return;
F_59 ( & V_2 -> V_7 -> V_80 ) ;
F_42 ( V_2 -> V_7 -> V_107 . V_105 ) ;
F_42 ( V_2 -> V_7 ) ;
}
