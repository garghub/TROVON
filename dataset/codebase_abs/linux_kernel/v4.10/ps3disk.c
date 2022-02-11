static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
unsigned int V_6 = 0 ;
struct V_7 V_8 ;
struct V_9 V_10 ;
unsigned int V_11 = 0 ;
T_1 V_12 ;
void * V_13 ;
F_2 (bvec, req, iter) {
unsigned long V_14 ;
F_3 ( & V_2 -> V_15 . V_16 , L_1 ,
V_17 , __LINE__ , V_11 , F_4 ( V_8 . V_18 ) ,
V_8 . V_18 -> V_19 . V_20 ) ;
V_12 = V_10 . V_21 ;
V_13 = F_5 ( & V_10 , & V_14 ) ;
if ( V_5 )
memcpy ( V_2 -> V_22 + V_6 , V_13 , V_12 ) ;
else
memcpy ( V_13 , V_2 -> V_22 + V_6 , V_12 ) ;
V_6 += V_12 ;
F_6 ( V_10 . V_23 ) ;
F_7 ( V_13 , & V_14 ) ;
V_11 ++ ;
}
}
static int F_8 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_24 * V_25 = F_9 ( & V_2 -> V_15 ) ;
int V_26 = F_10 ( V_4 ) , V_27 ;
const char * V_28 = V_26 ? L_2 : L_3 ;
T_2 V_29 , V_30 ;
unsigned int V_31 = V_2 -> V_32 [ V_2 -> V_33 ] . V_34 ;
#ifdef F_11
unsigned int V_35 = 0 ;
struct V_9 V_36 ;
struct V_7 V_8 ;
F_2 (bv, req, iter)
V_35 ++ ;
F_3 ( & V_2 -> V_15 . V_16 ,
L_4 ,
V_17 , __LINE__ , V_28 , V_35 , F_12 ( V_4 ) ) ;
#endif
V_29 = F_13 ( V_4 ) * V_25 -> V_37 ;
V_30 = F_12 ( V_4 ) * V_25 -> V_37 ;
F_3 ( & V_2 -> V_15 . V_16 , L_5 ,
V_17 , __LINE__ , V_28 , V_30 , V_29 ) ;
if ( V_26 ) {
F_1 ( V_2 , V_4 , 1 ) ;
V_27 = F_14 ( V_2 -> V_15 . V_38 , V_31 ,
V_29 , V_30 , 0 ,
V_2 -> V_39 , & V_2 -> V_40 ) ;
} else {
V_27 = F_15 ( V_2 -> V_15 . V_38 , V_31 ,
V_29 , V_30 , 0 ,
V_2 -> V_39 , & V_2 -> V_40 ) ;
}
if ( V_27 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_6 , V_17 ,
__LINE__ , V_28 , V_27 ) ;
F_17 ( V_4 , - V_41 ) ;
return 0 ;
}
V_25 -> V_4 = V_4 ;
return 1 ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_24 * V_25 = F_9 ( & V_2 -> V_15 ) ;
T_2 V_27 ;
F_3 ( & V_2 -> V_15 . V_16 , L_7 , V_17 , __LINE__ ) ;
V_27 = F_19 ( V_2 -> V_15 . V_38 ,
V_42 , 0 , 0 , 0 ,
0 , & V_2 -> V_40 ) ;
if ( V_27 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_8 ,
V_17 , __LINE__ , V_27 ) ;
F_17 ( V_4 , - V_41 ) ;
return 0 ;
}
V_25 -> V_4 = V_4 ;
return 1 ;
}
static void F_20 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
struct V_3 * V_4 ;
F_3 ( & V_2 -> V_15 . V_16 , L_9 , V_17 , __LINE__ ) ;
while ( ( V_4 = F_21 ( V_44 ) ) ) {
if ( F_22 ( V_4 ) == V_45 ) {
if ( F_18 ( V_2 , V_4 ) )
break;
} else if ( V_4 -> V_46 == V_47 ) {
if ( F_8 ( V_2 , V_4 ) )
break;
} else {
F_23 ( V_4 , V_48 L_10 ) ;
F_17 ( V_4 , - V_41 ) ;
continue;
}
}
}
static void F_24 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_49 ;
struct V_24 * V_25 = F_9 ( & V_2 -> V_15 ) ;
if ( V_25 -> V_4 ) {
F_3 ( & V_2 -> V_15 . V_16 , L_11 , V_17 , __LINE__ ) ;
return;
}
F_20 ( V_2 , V_44 ) ;
}
static T_3 F_25 ( int V_50 , void * V_51 )
{
struct V_1 * V_2 = V_51 ;
struct V_24 * V_25 ;
struct V_3 * V_4 ;
int V_27 , V_52 , error ;
T_2 V_40 , V_53 ;
const char * V_28 ;
V_27 = F_26 ( V_2 -> V_15 . V_38 , & V_40 , & V_53 ) ;
if ( V_40 != V_2 -> V_40 )
F_16 ( & V_2 -> V_15 . V_16 ,
L_12 ,
V_17 , __LINE__ , V_40 , V_2 -> V_40 ) ;
if ( V_27 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_13 ,
V_17 , __LINE__ , V_27 , V_53 ) ;
return V_54 ;
}
V_25 = F_9 ( & V_2 -> V_15 ) ;
V_4 = V_25 -> V_4 ;
if ( ! V_4 ) {
F_3 ( & V_2 -> V_15 . V_16 ,
L_14 , V_17 ,
__LINE__ ) ;
V_2 -> V_55 = V_53 ;
F_27 ( & V_2 -> V_56 ) ;
return V_54 ;
}
if ( F_22 ( V_4 ) == V_45 ) {
V_52 = 0 ;
V_28 = L_15 ;
} else {
V_52 = ! F_10 ( V_4 ) ;
V_28 = V_52 ? L_3 : L_2 ;
}
if ( V_53 ) {
F_3 ( & V_2 -> V_15 . V_16 , L_16 , V_17 ,
__LINE__ , V_28 , V_53 ) ;
error = - V_41 ;
} else {
F_3 ( & V_2 -> V_15 . V_16 , L_17 , V_17 ,
__LINE__ , V_28 ) ;
error = 0 ;
if ( V_52 )
F_1 ( V_2 , V_4 , 0 ) ;
}
F_28 ( & V_25 -> V_57 ) ;
F_17 ( V_4 , error ) ;
V_25 -> V_4 = NULL ;
F_20 ( V_2 , V_25 -> V_58 ) ;
F_29 ( & V_25 -> V_57 ) ;
return V_54 ;
}
static int F_30 ( struct V_1 * V_2 )
{
T_2 V_27 ;
F_3 ( & V_2 -> V_15 . V_16 , L_18 , V_17 , __LINE__ ) ;
V_27 = F_31 ( V_2 , V_42 , 0 , 0 , 0 , 0 ) ;
if ( V_27 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_8 ,
V_17 , __LINE__ , V_27 ) ;
return - V_41 ;
}
return 0 ;
}
static void F_32 ( T_4 * V_13 , unsigned int V_59 )
{
#ifdef F_33
unsigned int V_11 ;
for ( V_11 = 0 ; V_11 < V_59 ; V_11 ++ )
V_13 [ V_11 ] = F_34 ( V_13 [ V_11 ] ) ;
#endif
}
static T_2 F_35 ( const T_4 * V_34 )
{
if ( F_36 ( V_34 ) ) {
if ( F_37 ( V_34 ) )
return F_38 ( V_34 , 100 ) ;
else
return F_39 ( V_34 , 60 ) ;
} else {
if ( F_40 ( V_34 ) )
return F_39 ( V_34 , 57 ) ;
else
return V_34 [ 1 ] * V_34 [ 3 ] * V_34 [ 6 ] ;
}
}
static void F_41 ( const T_4 * V_34 , unsigned char * V_60 , unsigned int V_61 ,
unsigned int V_62 )
{
unsigned int V_63 ;
while ( V_62 > 0 ) {
V_63 = V_34 [ V_61 ] >> 8 ;
* V_60 = V_63 ;
V_60 ++ ;
V_63 = V_34 [ V_61 ] & 0xff ;
* V_60 = V_63 ;
V_60 ++ ;
V_61 ++ ;
V_62 -= 2 ;
}
}
static void F_42 ( const T_4 * V_34 , unsigned char * V_60 , unsigned int V_61 ,
unsigned int V_62 )
{
unsigned char * V_64 ;
F_43 ( ! ( V_62 & 1 ) ) ;
F_41 ( V_34 , V_60 , V_61 , V_62 - 1 ) ;
V_64 = V_60 + F_44 ( V_60 , V_62 - 1 ) ;
while ( V_64 > V_60 && V_64 [ - 1 ] == ' ' )
V_64 -- ;
* V_64 = '\0' ;
}
static int F_45 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = F_9 ( & V_2 -> V_15 ) ;
struct V_65 V_66 ;
T_4 * V_34 = V_2 -> V_22 ;
T_2 V_27 ;
F_3 ( & V_2 -> V_15 . V_16 , L_19 , V_17 , __LINE__ ) ;
memset ( & V_66 , 0 , sizeof( struct V_65 ) ) ;
V_66 . V_67 = V_68 ;
V_66 . V_69 = 1 ;
V_66 . V_12 = V_66 . V_70 = V_71 * 2 ;
V_66 . V_72 = V_2 -> V_39 ;
V_66 . V_73 = V_74 ;
V_66 . V_75 = V_76 ;
V_27 = F_31 ( V_2 , V_77 ,
F_46 ( F_47 ( & V_66 ) ) ,
sizeof( V_66 ) , V_66 . V_72 ,
V_66 . V_70 ) ;
if ( V_27 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_20 ,
V_17 , __LINE__ , V_27 ) ;
return - V_41 ;
}
F_32 ( V_34 , V_71 ) ;
V_25 -> V_78 = F_35 ( V_34 ) ;
F_42 ( V_34 , V_25 -> V_79 , V_80 , sizeof( V_25 -> V_79 ) ) ;
return 0 ;
}
static int F_48 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( & V_82 -> V_16 ) ;
struct V_24 * V_25 ;
int error ;
unsigned int V_83 ;
struct V_43 * V_58 ;
struct V_84 * V_84 ;
if ( V_2 -> V_85 < 512 ) {
F_16 ( & V_2 -> V_15 . V_16 ,
L_21 , V_17 ,
__LINE__ , V_2 -> V_85 ) ;
return - V_86 ;
}
F_50 ( V_87 > V_88 ) ;
F_51 ( & V_89 ) ;
V_83 = F_52 ( & V_90 , V_87 ) ;
if ( V_83 >= V_87 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_22 , V_17 ,
__LINE__ ) ;
F_53 ( & V_89 ) ;
return - V_91 ;
}
F_54 ( V_83 , & V_90 ) ;
F_53 ( & V_89 ) ;
V_25 = F_55 ( sizeof( * V_25 ) , V_92 ) ;
if ( ! V_25 ) {
error = - V_93 ;
goto V_94;
}
F_56 ( V_82 , V_25 ) ;
F_57 ( & V_25 -> V_57 ) ;
V_2 -> V_95 = V_96 ;
V_2 -> V_22 = F_58 ( V_96 , V_97 ) ;
if ( ! V_2 -> V_22 ) {
error = - V_93 ;
goto V_98;
}
error = F_59 ( V_2 , F_25 ) ;
if ( error )
goto V_99;
F_45 ( V_2 ) ;
V_58 = F_60 ( F_24 , & V_25 -> V_57 ) ;
if ( ! V_58 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_23 ,
V_17 , __LINE__ ) ;
error = - V_93 ;
goto V_100;
}
V_25 -> V_58 = V_58 ;
V_58 -> V_49 = V_2 ;
F_61 ( V_58 , V_101 ) ;
F_62 ( V_58 , V_2 -> V_95 >> 9 ) ;
F_63 ( V_58 , - 1UL ) ;
F_64 ( V_58 , V_2 -> V_85 - 1 ) ;
F_65 ( V_58 , V_2 -> V_85 ) ;
F_66 ( V_58 , true , false ) ;
F_67 ( V_58 , - 1 ) ;
F_68 ( V_58 , V_2 -> V_95 ) ;
V_84 = F_69 ( V_102 ) ;
if ( ! V_84 ) {
F_16 ( & V_2 -> V_15 . V_16 , L_24 , V_17 ,
__LINE__ ) ;
error = - V_93 ;
goto V_103;
}
V_25 -> V_84 = V_84 ;
V_84 -> V_104 = V_105 ;
V_84 -> V_106 = V_83 * V_102 ;
V_84 -> V_107 = & V_108 ;
V_84 -> V_58 = V_58 ;
V_84 -> V_109 = V_2 ;
snprintf ( V_84 -> V_110 , sizeof( V_84 -> V_110 ) , V_111 ,
V_83 + 'a' ) ;
V_25 -> V_37 = V_2 -> V_85 >> 9 ;
F_70 ( V_84 ,
V_2 -> V_32 [ V_2 -> V_33 ] . V_12 * V_25 -> V_37 ) ;
F_71 ( & V_2 -> V_15 . V_16 ,
L_25 ,
V_84 -> V_110 , V_25 -> V_79 , V_25 -> V_78 >> 11 ,
F_72 ( V_84 ) >> 11 ) ;
F_73 ( & V_2 -> V_15 . V_16 , V_84 ) ;
return 0 ;
V_103:
F_74 ( V_58 ) ;
V_100:
F_75 ( V_2 ) ;
V_99:
F_76 ( V_2 -> V_22 ) ;
V_98:
F_76 ( V_25 ) ;
F_56 ( V_82 , NULL ) ;
V_94:
F_51 ( & V_89 ) ;
F_77 ( V_83 , & V_90 ) ;
F_53 ( & V_89 ) ;
return error ;
}
static int F_78 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( & V_82 -> V_16 ) ;
struct V_24 * V_25 = F_9 ( & V_2 -> V_15 ) ;
F_51 ( & V_89 ) ;
F_77 ( F_79 ( F_80 ( V_25 -> V_84 ) ) / V_102 ,
& V_90 ) ;
F_53 ( & V_89 ) ;
F_81 ( V_25 -> V_84 ) ;
F_74 ( V_25 -> V_58 ) ;
F_82 ( V_25 -> V_84 ) ;
F_83 ( & V_2 -> V_15 . V_16 , L_26 ) ;
F_30 ( V_2 ) ;
F_75 ( V_2 ) ;
F_76 ( V_2 -> V_22 ) ;
F_76 ( V_25 ) ;
F_56 ( V_82 , NULL ) ;
return 0 ;
}
static int T_5 F_84 ( void )
{
int error ;
if ( ! F_85 ( V_112 ) )
return - V_113 ;
error = F_86 ( 0 , V_48 ) ;
if ( error <= 0 ) {
F_87 ( V_114 L_27 , V_17 ,
__LINE__ , error ) ;
return error ;
}
V_105 = error ;
F_88 ( L_28 , V_17 ,
__LINE__ , V_105 ) ;
error = F_89 ( & V_115 ) ;
if ( error )
F_90 ( V_105 , V_48 ) ;
return error ;
}
static void T_6 F_91 ( void )
{
F_92 ( & V_115 ) ;
F_90 ( V_105 , V_48 ) ;
}
