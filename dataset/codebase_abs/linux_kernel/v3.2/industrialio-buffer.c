T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 -> V_12 -> V_13 )
return - V_14 ;
return V_10 -> V_12 -> V_13 ( V_10 , V_4 , V_3 ) ;
}
unsigned int F_2 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_11 ;
F_3 ( V_2 , & V_10 -> V_17 , V_16 ) ;
if ( V_10 -> V_18 )
return V_19 | V_20 ;
return 0 ;
}
int F_4 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
if ( ! V_10 )
return - V_14 ;
if ( V_10 -> V_12 -> V_21 )
V_10 -> V_12 -> V_21 ( V_10 ) ;
return 0 ;
}
void F_5 ( struct V_6 * V_7 )
{
struct V_9 * V_10 = V_7 -> V_11 ;
F_6 ( V_22 , & V_10 -> V_23 ) ;
if ( V_10 -> V_12 -> V_24 )
V_10 -> V_12 -> V_24 ( V_10 ) ;
}
void F_7 ( struct V_9 * V_11 , struct V_6 * V_7 )
{
V_11 -> V_7 = V_7 ;
F_8 ( & V_11 -> V_17 ) ;
}
static T_1 F_9 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
return sprintf ( V_3 , L_1 , F_10 ( V_28 ) -> V_29 -> V_30 ) ;
}
static T_1 F_11 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
struct V_31 * V_32 = F_10 ( V_28 ) ;
T_5 type = V_32 -> V_29 -> V_33 . V_34 ;
if ( type == V_35 ) {
#ifdef F_12
type = V_36 ;
#else
type = V_37 ;
#endif
}
return sprintf ( V_3 , L_2 ,
V_38 [ type ] ,
V_32 -> V_29 -> V_33 . V_39 ,
V_32 -> V_29 -> V_33 . V_40 ,
V_32 -> V_29 -> V_33 . V_41 ,
V_32 -> V_29 -> V_33 . V_42 ) ;
}
static T_1 F_13 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
int V_43 ;
struct V_6 * V_7 = F_14 ( V_26 ) ;
V_43 = F_15 ( V_7 -> V_11 ,
F_10 ( V_28 ) -> V_44 ) ;
if ( V_43 < 0 )
return V_43 ;
return sprintf ( V_3 , L_3 , V_43 ) ;
}
static int F_16 ( struct V_9 * V_11 , int V_45 )
{
F_6 ( V_45 , V_11 -> V_46 ) ;
V_11 -> V_47 -- ;
return 0 ;
}
static T_1 F_17 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_3 ,
T_3 V_48 )
{
int V_43 = 0 ;
bool V_49 ;
struct V_6 * V_7 = F_14 ( V_26 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
struct V_31 * V_32 = F_10 ( V_28 ) ;
V_49 = ! ( V_3 [ 0 ] == '0' ) ;
F_18 ( & V_7 -> V_50 ) ;
if ( V_7 -> V_51 == V_52 ) {
V_43 = - V_53 ;
goto V_54;
}
V_43 = F_15 ( V_11 , V_32 -> V_44 ) ;
if ( V_43 < 0 )
goto V_54;
if ( ! V_49 && V_43 ) {
V_43 = F_16 ( V_11 , V_32 -> V_44 ) ;
if ( V_43 )
goto V_54;
} else if ( V_49 && ! V_43 ) {
V_43 = F_19 ( V_11 , V_32 -> V_44 ) ;
if ( V_43 )
goto V_54;
}
V_54:
F_20 ( & V_7 -> V_50 ) ;
return V_43 ? V_43 : V_48 ;
}
static T_1 F_21 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
struct V_6 * V_7 = F_14 ( V_26 ) ;
return sprintf ( V_3 , L_3 , V_7 -> V_11 -> V_55 ) ;
}
static T_1 F_22 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_3 ,
T_3 V_48 )
{
int V_43 = 0 ;
struct V_6 * V_7 = F_14 ( V_26 ) ;
bool V_49 ;
V_49 = ! ( V_3 [ 0 ] == '0' ) ;
F_18 ( & V_7 -> V_50 ) ;
if ( V_7 -> V_51 == V_52 ) {
V_43 = - V_53 ;
goto V_54;
}
V_7 -> V_11 -> V_55 = V_49 ;
V_54:
F_20 ( & V_7 -> V_50 ) ;
return V_43 ? V_43 : V_48 ;
}
static int F_23 ( struct V_6 * V_7 ,
const struct V_56 * V_57 )
{
int V_43 , V_58 = 0 ;
struct V_9 * V_11 = V_7 -> V_11 ;
V_43 = F_24 ( L_4 ,
V_57 ,
& F_9 ,
NULL ,
0 ,
0 ,
& V_7 -> V_26 ,
& V_11 -> V_59 ) ;
if ( V_43 )
goto V_54;
V_58 ++ ;
V_43 = F_24 ( L_5 ,
V_57 ,
& F_11 ,
NULL ,
0 ,
0 ,
& V_7 -> V_26 ,
& V_11 -> V_59 ) ;
if ( V_43 )
goto V_54;
V_58 ++ ;
if ( V_57 -> type != V_60 )
V_43 = F_24 ( L_6 ,
V_57 ,
& F_13 ,
& F_17 ,
V_57 -> V_30 ,
0 ,
& V_7 -> V_26 ,
& V_11 -> V_59 ) ;
else
V_43 = F_24 ( L_6 ,
V_57 ,
& F_21 ,
& F_22 ,
V_57 -> V_30 ,
0 ,
& V_7 -> V_26 ,
& V_11 -> V_59 ) ;
V_58 ++ ;
V_43 = V_58 ;
V_54:
return V_43 ;
}
static void F_25 ( struct V_6 * V_7 ,
struct V_31 * V_61 )
{
F_26 ( V_61 -> V_62 . V_28 . V_63 ) ;
F_26 ( V_61 ) ;
}
static void F_27 ( struct V_6 * V_7 )
{
struct V_31 * V_61 , * V_4 ;
struct V_9 * V_11 = V_7 -> V_11 ;
F_28 (p, n,
&buffer->scan_el_dev_attr_list, l)
F_25 ( V_7 , V_61 ) ;
}
int F_29 ( struct V_6 * V_7 ,
const struct V_56 * V_64 ,
int V_65 )
{
struct V_31 * V_61 ;
struct V_66 * * V_28 ;
struct V_9 * V_11 = V_7 -> V_11 ;
int V_43 , V_67 , V_68 , V_58 , V_69 = 0 ;
if ( V_11 -> V_70 )
V_7 -> V_71 [ V_7 -> V_72 ++ ] = V_11 -> V_70 ;
if ( V_11 -> V_73 != NULL ) {
V_28 = V_11 -> V_73 -> V_70 ;
while ( * V_28 ++ != NULL )
V_69 ++ ;
}
V_58 = V_69 ;
F_30 ( & V_11 -> V_59 ) ;
if ( V_64 ) {
for ( V_67 = 0 ; V_67 < V_65 ; V_67 ++ ) {
if ( V_64 [ V_67 ] . V_30 >
( int ) V_7 -> V_74 - 1 )
V_7 -> V_74
= V_7 -> V_64 [ V_67 ] . V_30 + 1 ;
V_43 = F_23 ( V_7 ,
& V_64 [ V_67 ] ) ;
if ( V_43 < 0 )
goto V_75;
V_58 += V_43 ;
}
if ( V_7 -> V_74 && V_11 -> V_46 == NULL ) {
V_11 -> V_46
= F_31 ( sizeof( * V_11 -> V_46 ) *
F_32 ( V_7 -> V_74 ) ,
V_76 ) ;
if ( V_11 -> V_46 == NULL ) {
V_43 = - V_77 ;
goto V_75;
}
}
}
V_11 -> V_78 . V_63 = V_79 ;
V_11 -> V_78 . V_70
= F_31 ( sizeof( V_11 -> V_78 . V_70 [ 0 ] ) *
( V_58 + 1 ) ,
V_76 ) ;
if ( V_11 -> V_78 . V_70 == NULL ) {
V_43 = - V_77 ;
goto V_80;
}
if ( V_11 -> V_73 )
memcpy ( V_11 -> V_78 . V_70 , V_11 -> V_73 ,
sizeof( V_11 -> V_78 . V_70 [ 0 ] ) * V_69 ) ;
V_68 = V_69 ;
F_33 (p, &buffer->scan_el_dev_attr_list, l)
V_11 -> V_78 . V_70 [ V_68 ++ ] = & V_61 -> V_62 . V_28 ;
V_7 -> V_71 [ V_7 -> V_72 ++ ] = & V_11 -> V_78 ;
return 0 ;
V_80:
F_26 ( V_11 -> V_46 ) ;
V_75:
F_27 ( V_7 ) ;
return V_43 ;
}
void F_34 ( struct V_6 * V_7 )
{
F_26 ( V_7 -> V_11 -> V_46 ) ;
F_26 ( V_7 -> V_11 -> V_78 . V_70 ) ;
F_27 ( V_7 ) ;
}
T_1 F_35 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
struct V_6 * V_7 = F_14 ( V_26 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
if ( V_11 -> V_12 -> V_81 )
return sprintf ( V_3 , L_3 ,
V_11 -> V_12 -> V_81 ( V_11 ) ) ;
return 0 ;
}
T_1 F_36 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_3 ,
T_3 V_48 )
{
int V_43 ;
T_6 V_82 ;
struct V_6 * V_7 = F_14 ( V_26 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
V_43 = F_37 ( V_3 , 10 , & V_82 ) ;
if ( V_43 )
return V_43 ;
if ( V_11 -> V_12 -> V_81 )
if ( V_82 == V_11 -> V_12 -> V_81 ( V_11 ) )
return V_48 ;
if ( V_11 -> V_12 -> V_83 ) {
V_11 -> V_12 -> V_83 ( V_11 , V_82 ) ;
if ( V_11 -> V_12 -> V_84 )
V_11 -> V_12 -> V_84 ( V_11 ) ;
}
return V_48 ;
}
T_1 F_38 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
struct V_6 * V_7 = F_14 ( V_26 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
if ( V_11 -> V_12 -> V_85 )
return sprintf ( V_3 , L_3 ,
V_11 -> V_12 -> V_85 ( V_11 ) ) ;
return 0 ;
}
T_1 F_39 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
const char * V_3 ,
T_3 V_48 )
{
int V_43 ;
bool V_86 , V_87 ;
int V_88 ;
struct V_6 * V_7 = F_14 ( V_26 ) ;
struct V_9 * V_11 = V_7 -> V_11 ;
F_18 ( & V_7 -> V_50 ) ;
V_88 = V_7 -> V_51 ;
V_86 = ! ( V_3 [ 0 ] == '0' ) ;
V_87 = ! ! ( V_88 & V_89 ) ;
if ( V_87 == V_86 ) {
F_40 ( V_90 L_7 ) ;
goto V_91;
}
if ( V_86 ) {
if ( V_11 -> V_92 -> V_93 ) {
V_43 = V_11 -> V_92 -> V_93 ( V_7 ) ;
if ( V_43 ) {
F_40 ( V_94
L_8
L_9 ) ;
goto V_54;
}
}
if ( V_11 -> V_12 -> V_95 ) {
V_43 = V_11 -> V_12 -> V_95 ( V_11 ) ;
if ( V_43 ) {
F_40 ( V_90
L_8
L_10 ) ;
goto V_54;
}
}
if ( V_11 -> V_12 -> V_21 )
V_11 -> V_12 -> V_21 ( V_11 ) ;
if ( V_7 -> V_96 & V_52 ) {
if ( ! V_7 -> V_97 ) {
F_40 ( V_90
L_11 ) ;
V_43 = - V_14 ;
if ( V_11 -> V_12 -> V_24 )
V_11 -> V_12 -> V_24 ( V_11 ) ;
goto V_54;
}
V_7 -> V_51 = V_52 ;
} else if ( V_7 -> V_96 & V_98 )
V_7 -> V_51 = V_98 ;
else {
V_43 = - V_14 ;
goto V_54;
}
if ( V_11 -> V_92 -> V_99 ) {
V_43 = V_11 -> V_92 -> V_99 ( V_7 ) ;
if ( V_43 ) {
F_40 ( V_90
L_8
L_12 ) ;
if ( V_11 -> V_12 -> V_24 )
V_11 -> V_12 -> V_24 ( V_11 ) ;
V_7 -> V_51 = V_88 ;
if ( V_11 -> V_92 -> V_100 )
V_11 -> V_92 ->
V_100 ( V_7 ) ;
goto V_54;
}
}
} else {
if ( V_11 -> V_92 -> V_101 ) {
V_43 = V_11 -> V_92 -> V_101 ( V_7 ) ;
if ( V_43 )
goto V_54;
}
if ( V_11 -> V_12 -> V_24 )
V_11 -> V_12 -> V_24 ( V_11 ) ;
V_7 -> V_51 = V_102 ;
if ( V_11 -> V_92 -> V_100 ) {
V_43 = V_11 -> V_92 -> V_100 ( V_7 ) ;
if ( V_43 )
goto V_54;
}
}
V_91:
F_20 ( & V_7 -> V_50 ) ;
return V_48 ;
V_54:
F_20 ( & V_7 -> V_50 ) ;
return V_43 ;
}
T_1 F_41 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
char * V_3 )
{
struct V_6 * V_7 = F_14 ( V_26 ) ;
return sprintf ( V_3 , L_3 , ! ! ( V_7 -> V_51
& V_89 ) ) ;
}
int F_42 ( struct V_6 * V_7 )
{
struct V_9 * V_11 = V_7 -> V_11 ;
T_3 V_103 ;
F_43 ( & V_7 -> V_26 , L_13 , V_104 ) ;
if ( ! ( V_11 -> V_47 || V_11 -> V_55 ) )
return - V_14 ;
if ( V_11 -> V_55 )
if ( V_11 -> V_47 )
V_103 = ( ( ( V_11 -> V_47 * V_11 -> V_105 )
+ sizeof( V_106 ) - 1 )
& ~ ( sizeof( V_106 ) - 1 ) )
+ sizeof( V_106 ) ;
else
V_103 = sizeof( V_106 ) ;
else
V_103 = V_11 -> V_47 * V_11 -> V_105 ;
V_11 -> V_12 -> V_107 ( V_11 , V_103 ) ;
return 0 ;
}
static unsigned long * F_44 ( unsigned long * V_108 ,
unsigned int V_74 ,
unsigned long * V_109 )
{
if ( F_45 ( V_109 , V_74 ) )
return NULL ;
while ( * V_108 ) {
if ( F_46 ( V_109 , V_108 , V_74 ) )
return V_108 ;
V_108 += F_32 ( V_74 ) ;
}
return NULL ;
}
int F_19 ( struct V_9 * V_11 , int V_45 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
unsigned long * V_109 ;
unsigned long * V_110 ;
V_110 = F_47 ( sizeof( * V_110 ) *
F_32 ( V_7 -> V_74 ) ,
V_76 ) ;
if ( V_110 == NULL )
return - V_77 ;
if ( ! V_7 -> V_74 ) {
F_48 ( L_14 ) ;
F_26 ( V_110 ) ;
return - V_14 ;
}
F_49 ( V_110 , V_11 -> V_46 , V_7 -> V_74 ) ;
F_50 ( V_45 , V_110 ) ;
if ( V_7 -> V_111 ) {
V_109 = F_44 ( V_7 -> V_111 ,
V_7 -> V_74 ,
V_110 ) ;
if ( ! V_109 ) {
F_26 ( V_110 ) ;
return - V_14 ;
}
}
F_49 ( V_11 -> V_46 , V_110 , V_7 -> V_74 ) ;
V_11 -> V_47 ++ ;
F_26 ( V_110 ) ;
return 0 ;
}
int F_15 ( struct V_9 * V_11 , int V_45 )
{
struct V_6 * V_7 = V_11 -> V_7 ;
long * V_109 ;
if ( V_45 > V_7 -> V_74 )
return - V_14 ;
if ( ! V_11 -> V_46 )
return 0 ;
if ( V_7 -> V_111 )
V_109 = F_44 ( V_7 -> V_111 ,
V_7 -> V_74 ,
V_11 -> V_46 ) ;
else
V_109 = V_11 -> V_46 ;
if ( ! V_109 )
return 0 ;
return F_51 ( V_45 , V_109 ) ;
}
