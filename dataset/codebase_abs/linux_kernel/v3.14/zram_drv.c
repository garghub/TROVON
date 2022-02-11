static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return (struct V_1 * ) F_2 ( V_3 ) -> V_4 ;
}
static T_1 F_3 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 , V_1 -> V_8 ) ;
}
static T_1 F_4 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_2 , V_1 -> V_9 ) ;
}
static T_1 F_5 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) F_6 ( & V_1 -> V_11 . V_12 ) ) ;
}
static T_1 F_7 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) F_6 ( & V_1 -> V_11 . V_13 ) ) ;
}
static T_1 F_8 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) F_6 ( & V_1 -> V_11 . V_14 ) ) ;
}
static T_1 F_9 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) F_6 ( & V_1 -> V_11 . V_15 ) ) ;
}
static T_1 F_10 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_2 , F_11 ( & V_1 -> V_11 . V_16 ) ) ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) ( F_11 ( & V_1 -> V_11 . V_17 ) ) << V_18 ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) F_6 ( & V_1 -> V_11 . V_19 ) ) ;
}
static T_1 F_14 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
V_10 V_20 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_1 -> V_22 ;
F_15 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_9 )
V_20 = F_16 ( V_22 -> V_24 ) ;
F_17 ( & V_1 -> V_23 ) ;
return sprintf ( V_7 , L_1 , V_20 ) ;
}
static int F_18 ( struct V_21 * V_22 , T_2 V_25 ,
enum V_26 V_27 )
{
return V_22 -> V_28 [ V_25 ] . V_29 & F_19 ( V_27 ) ;
}
static void F_20 ( struct V_21 * V_22 , T_2 V_25 ,
enum V_26 V_27 )
{
V_22 -> V_28 [ V_25 ] . V_29 |= F_19 ( V_27 ) ;
}
static void F_21 ( struct V_21 * V_22 , T_2 V_25 ,
enum V_26 V_27 )
{
V_22 -> V_28 [ V_25 ] . V_29 &= ~ F_19 ( V_27 ) ;
}
static inline int F_22 ( struct V_30 * V_31 )
{
return V_31 -> V_32 != V_33 ;
}
static inline int F_23 ( struct V_1 * V_1 , struct V_34 * V_34 )
{
V_10 V_35 , V_36 , V_37 ;
if ( F_24 ( V_34 -> V_38 . V_39 &
( V_40 - 1 ) ) )
return 0 ;
if ( F_24 ( V_34 -> V_38 . V_41 & ( V_42 - 1 ) ) )
return 0 ;
V_35 = V_34 -> V_38 . V_39 ;
V_36 = V_35 + ( V_34 -> V_38 . V_41 >> V_43 ) ;
V_37 = V_1 -> V_8 >> V_43 ;
if ( F_24 ( V_35 >= V_37 || V_36 > V_37 || V_35 > V_36 ) )
return 0 ;
return 1 ;
}
static void F_25 ( struct V_21 * V_22 )
{
F_26 ( V_22 -> V_24 ) ;
F_27 ( V_22 -> V_44 ) ;
F_28 ( ( unsigned long ) V_22 -> V_45 , 1 ) ;
F_29 ( V_22 -> V_28 ) ;
F_27 ( V_22 ) ;
}
static struct V_21 * F_30 ( V_10 V_8 )
{
T_3 V_46 ;
struct V_21 * V_22 = F_31 ( sizeof( * V_22 ) , V_47 ) ;
if ( ! V_22 )
goto V_48;
V_22 -> V_44 = F_32 ( V_49 , V_47 ) ;
if ( ! V_22 -> V_44 )
goto V_50;
V_22 -> V_45 =
( void * ) F_33 ( V_47 | V_51 , 1 ) ;
if ( ! V_22 -> V_45 ) {
F_34 ( L_3 ) ;
goto V_52;
}
V_46 = V_8 >> V_18 ;
V_22 -> V_28 = F_35 ( V_46 * sizeof( * V_22 -> V_28 ) ) ;
if ( ! V_22 -> V_28 ) {
F_34 ( L_4 ) ;
goto V_53;
}
V_22 -> V_24 = F_36 ( V_54 | V_55 ) ;
if ( ! V_22 -> V_24 ) {
F_34 ( L_5 ) ;
goto V_56;
}
F_37 ( & V_22 -> V_57 ) ;
F_38 ( & V_22 -> V_58 ) ;
return V_22 ;
V_56:
F_29 ( V_22 -> V_28 ) ;
V_53:
F_28 ( ( unsigned long ) V_22 -> V_45 , 1 ) ;
V_52:
F_27 ( V_22 -> V_44 ) ;
V_50:
F_27 ( V_22 ) ;
V_22 = NULL ;
V_48:
return V_22 ;
}
static void F_39 ( T_2 * V_25 , int * V_59 , struct V_30 * V_31 )
{
if ( * V_59 + V_31 -> V_32 >= V_33 )
( * V_25 ) ++ ;
* V_59 = ( * V_59 + V_31 -> V_32 ) % V_33 ;
}
static int F_40 ( void * V_60 )
{
unsigned int V_61 ;
unsigned long * V_62 ;
V_62 = ( unsigned long * ) V_60 ;
for ( V_61 = 0 ; V_61 != V_33 / sizeof( * V_62 ) ; V_61 ++ ) {
if ( V_62 [ V_61 ] )
return 0 ;
}
return 1 ;
}
static void F_41 ( struct V_30 * V_31 )
{
struct V_62 * V_62 = V_31 -> V_63 ;
void * V_64 ;
V_64 = F_42 ( V_62 ) ;
if ( F_22 ( V_31 ) )
memset ( V_64 + V_31 -> V_65 , 0 , V_31 -> V_32 ) ;
else
F_43 ( V_64 ) ;
F_44 ( V_64 ) ;
F_45 ( V_62 ) ;
}
static void F_46 ( struct V_1 * V_1 , T_3 V_25 )
{
struct V_21 * V_22 = V_1 -> V_22 ;
unsigned long V_66 = V_22 -> V_28 [ V_25 ] . V_66 ;
T_4 V_67 = V_22 -> V_28 [ V_25 ] . V_67 ;
if ( F_24 ( ! V_66 ) ) {
if ( F_18 ( V_22 , V_25 , V_68 ) ) {
F_21 ( V_22 , V_25 , V_68 ) ;
F_47 ( & V_1 -> V_11 . V_16 ) ;
}
return;
}
if ( F_24 ( V_67 > V_69 ) )
F_47 ( & V_1 -> V_11 . V_70 ) ;
F_48 ( V_22 -> V_24 , V_66 ) ;
if ( V_67 <= V_33 / 2 )
F_47 ( & V_1 -> V_11 . V_71 ) ;
F_49 ( V_22 -> V_28 [ V_25 ] . V_67 , & V_1 -> V_11 . V_19 ) ;
F_47 ( & V_1 -> V_11 . V_17 ) ;
V_22 -> V_28 [ V_25 ] . V_66 = 0 ;
V_22 -> V_28 [ V_25 ] . V_67 = 0 ;
}
static int F_50 ( struct V_1 * V_1 , char * V_72 , T_2 V_25 )
{
int V_73 = V_74 ;
T_3 V_75 = V_33 ;
unsigned char * V_76 ;
struct V_21 * V_22 = V_1 -> V_22 ;
unsigned long V_66 ;
T_4 V_67 ;
F_51 ( & V_22 -> V_57 ) ;
V_66 = V_22 -> V_28 [ V_25 ] . V_66 ;
V_67 = V_22 -> V_28 [ V_25 ] . V_67 ;
if ( ! V_66 || F_18 ( V_22 , V_25 , V_68 ) ) {
F_52 ( & V_22 -> V_57 ) ;
F_43 ( V_72 ) ;
return 0 ;
}
V_76 = F_53 ( V_22 -> V_24 , V_66 , V_77 ) ;
if ( V_67 == V_33 )
F_54 ( V_72 , V_76 ) ;
else
V_73 = F_55 ( V_76 , V_67 , V_72 , & V_75 ) ;
F_56 ( V_22 -> V_24 , V_66 ) ;
F_52 ( & V_22 -> V_57 ) ;
if ( F_24 ( V_73 != V_74 ) ) {
F_34 ( L_6 , V_73 , V_25 ) ;
F_57 ( & V_1 -> V_11 . V_78 ) ;
return V_73 ;
}
return 0 ;
}
static int F_58 ( struct V_1 * V_1 , struct V_30 * V_31 ,
T_2 V_25 , int V_59 , struct V_34 * V_34 )
{
int V_73 ;
struct V_62 * V_62 ;
unsigned char * V_64 , * V_79 = NULL ;
struct V_21 * V_22 = V_1 -> V_22 ;
V_62 = V_31 -> V_63 ;
F_51 ( & V_22 -> V_57 ) ;
if ( F_24 ( ! V_22 -> V_28 [ V_25 ] . V_66 ) ||
F_18 ( V_22 , V_25 , V_68 ) ) {
F_52 ( & V_22 -> V_57 ) ;
F_41 ( V_31 ) ;
return 0 ;
}
F_52 ( & V_22 -> V_57 ) ;
if ( F_22 ( V_31 ) )
V_79 = F_31 ( V_33 , V_54 ) ;
V_64 = F_42 ( V_62 ) ;
if ( ! F_22 ( V_31 ) )
V_79 = V_64 ;
if ( ! V_79 ) {
F_59 ( L_7 ) ;
V_73 = - V_80 ;
goto V_81;
}
V_73 = F_50 ( V_1 , V_79 , V_25 ) ;
if ( F_24 ( V_73 != V_74 ) )
goto V_81;
if ( F_22 ( V_31 ) )
memcpy ( V_64 + V_31 -> V_65 , V_79 + V_59 ,
V_31 -> V_32 ) ;
F_45 ( V_62 ) ;
V_73 = 0 ;
V_81:
F_44 ( V_64 ) ;
if ( F_22 ( V_31 ) )
F_27 ( V_79 ) ;
return V_73 ;
}
static int F_60 ( struct V_1 * V_1 , struct V_30 * V_31 , T_2 V_25 ,
int V_59 )
{
int V_73 = 0 ;
T_3 V_75 ;
unsigned long V_66 ;
struct V_62 * V_62 ;
unsigned char * V_64 , * V_76 , * V_82 , * V_79 = NULL ;
struct V_21 * V_22 = V_1 -> V_22 ;
bool V_83 = false ;
V_62 = V_31 -> V_63 ;
V_82 = V_22 -> V_45 ;
if ( F_22 ( V_31 ) ) {
V_79 = F_31 ( V_33 , V_54 ) ;
if ( ! V_79 ) {
V_73 = - V_80 ;
goto V_48;
}
V_73 = F_50 ( V_1 , V_79 , V_25 ) ;
if ( V_73 )
goto V_48;
}
F_61 ( & V_22 -> V_58 ) ;
V_83 = true ;
V_64 = F_42 ( V_62 ) ;
if ( F_22 ( V_31 ) ) {
memcpy ( V_79 + V_59 , V_64 + V_31 -> V_65 ,
V_31 -> V_32 ) ;
F_44 ( V_64 ) ;
V_64 = NULL ;
} else {
V_79 = V_64 ;
}
if ( F_40 ( V_79 ) ) {
F_44 ( V_64 ) ;
F_62 ( & V_1 -> V_22 -> V_57 ) ;
F_46 ( V_1 , V_25 ) ;
F_20 ( V_22 , V_25 , V_68 ) ;
F_63 ( & V_1 -> V_22 -> V_57 ) ;
F_64 ( & V_1 -> V_11 . V_16 ) ;
V_73 = 0 ;
goto V_48;
}
V_73 = F_65 ( V_79 , V_33 , V_82 , & V_75 ,
V_22 -> V_44 ) ;
if ( ! F_22 ( V_31 ) ) {
F_44 ( V_64 ) ;
V_64 = NULL ;
V_79 = NULL ;
}
if ( F_24 ( V_73 != V_74 ) ) {
F_34 ( L_8 , V_73 ) ;
goto V_48;
}
if ( F_24 ( V_75 > V_69 ) ) {
F_64 ( & V_1 -> V_11 . V_70 ) ;
V_75 = V_33 ;
V_82 = NULL ;
if ( F_22 ( V_31 ) )
V_82 = V_79 ;
}
V_66 = F_66 ( V_22 -> V_24 , V_75 ) ;
if ( ! V_66 ) {
F_59 ( L_9 ,
V_25 , V_75 ) ;
V_73 = - V_80 ;
goto V_48;
}
V_76 = F_53 ( V_22 -> V_24 , V_66 , V_84 ) ;
if ( ( V_75 == V_33 ) && ! F_22 ( V_31 ) ) {
V_82 = F_42 ( V_62 ) ;
F_54 ( V_76 , V_82 ) ;
F_44 ( V_82 ) ;
} else {
memcpy ( V_76 , V_82 , V_75 ) ;
}
F_56 ( V_22 -> V_24 , V_66 ) ;
F_62 ( & V_1 -> V_22 -> V_57 ) ;
F_46 ( V_1 , V_25 ) ;
V_22 -> V_28 [ V_25 ] . V_66 = V_66 ;
V_22 -> V_28 [ V_25 ] . V_67 = V_75 ;
F_63 ( & V_1 -> V_22 -> V_57 ) ;
F_67 ( V_75 , & V_1 -> V_11 . V_19 ) ;
F_64 ( & V_1 -> V_11 . V_17 ) ;
if ( V_75 <= V_33 / 2 )
F_64 ( & V_1 -> V_11 . V_71 ) ;
V_48:
if ( V_83 )
F_68 ( & V_22 -> V_58 ) ;
if ( F_22 ( V_31 ) )
F_27 ( V_79 ) ;
if ( V_73 )
F_57 ( & V_1 -> V_11 . V_85 ) ;
return V_73 ;
}
static int F_69 ( struct V_1 * V_1 , struct V_30 * V_31 , T_2 V_25 ,
int V_59 , struct V_34 * V_34 , int V_86 )
{
int V_73 ;
if ( V_86 == V_87 )
V_73 = F_58 ( V_1 , V_31 , V_25 , V_59 , V_34 ) ;
else
V_73 = F_60 ( V_1 , V_31 , V_25 , V_59 ) ;
return V_73 ;
}
static void F_70 ( struct V_1 * V_1 , bool V_88 )
{
T_3 V_25 ;
struct V_21 * V_22 ;
F_71 ( & V_1 -> V_23 ) ;
if ( ! V_1 -> V_9 ) {
F_72 ( & V_1 -> V_23 ) ;
return;
}
V_22 = V_1 -> V_22 ;
V_1 -> V_9 = 0 ;
for ( V_25 = 0 ; V_25 < V_1 -> V_8 > > V_18 ; V_25 ++ ) {
unsigned long V_66 = V_22 -> V_28 [ V_25 ] . V_66 ;
if ( ! V_66 )
continue;
F_48 ( V_22 -> V_24 , V_66 ) ;
}
F_25 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
memset ( & V_1 -> V_11 , 0 , sizeof( V_1 -> V_11 ) ) ;
V_1 -> V_8 = 0 ;
if ( V_88 )
F_73 ( V_1 -> V_89 , 0 ) ;
F_72 ( & V_1 -> V_23 ) ;
}
static void F_74 ( struct V_1 * V_1 , struct V_21 * V_22 )
{
if ( V_1 -> V_8 > 2 * ( V_90 << V_18 ) ) {
F_59 (
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17 ,
( V_90 << V_18 ) >> 10 , V_1 -> V_8 >> 10
) ;
}
F_75 ( V_91 , V_1 -> V_89 -> V_92 ) ;
V_1 -> V_22 = V_22 ;
V_1 -> V_9 = 1 ;
F_76 ( L_18 ) ;
}
static T_1 F_77 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_3 V_93 )
{
V_10 V_8 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_8 = F_78 ( V_7 , NULL ) ;
if ( ! V_8 )
return - V_94 ;
V_8 = F_79 ( V_8 ) ;
V_22 = F_30 ( V_8 ) ;
if ( ! V_22 )
return - V_80 ;
F_71 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_9 ) {
F_72 ( & V_1 -> V_23 ) ;
F_25 ( V_22 ) ;
F_59 ( L_19 ) ;
return - V_95 ;
}
V_1 -> V_8 = V_8 ;
F_73 ( V_1 -> V_89 , V_1 -> V_8 >> V_43 ) ;
F_74 ( V_1 , V_22 ) ;
F_72 ( & V_1 -> V_23 ) ;
return V_93 ;
}
static T_1 F_80 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_3 V_93 )
{
int V_73 ;
unsigned short V_96 ;
struct V_1 * V_1 ;
struct V_97 * V_98 ;
V_1 = F_1 ( V_3 ) ;
V_98 = F_81 ( V_1 -> V_89 , 0 ) ;
if ( ! V_98 )
return - V_80 ;
if ( V_98 -> V_99 ) {
V_73 = - V_95 ;
goto V_48;
}
V_73 = F_82 ( V_7 , 10 , & V_96 ) ;
if ( V_73 )
goto V_48;
if ( ! V_96 ) {
V_73 = - V_94 ;
goto V_48;
}
F_83 ( V_98 ) ;
F_84 ( V_98 ) ;
F_70 ( V_1 , true ) ;
return V_93 ;
V_48:
F_84 ( V_98 ) ;
return V_73 ;
}
static void F_85 ( struct V_1 * V_1 , struct V_34 * V_34 , int V_86 )
{
int V_59 ;
T_2 V_25 ;
struct V_30 V_31 ;
struct V_100 V_101 ;
switch ( V_86 ) {
case V_87 :
F_57 ( & V_1 -> V_11 . V_12 ) ;
break;
case V_102 :
F_57 ( & V_1 -> V_11 . V_13 ) ;
break;
}
V_25 = V_34 -> V_38 . V_39 >> V_103 ;
V_59 = ( V_34 -> V_38 . V_39 &
( V_104 - 1 ) ) << V_43 ;
F_86 (bvec, bio, iter) {
int V_105 = V_33 - V_59 ;
if ( V_31 . V_32 > V_105 ) {
struct V_30 V_106 ;
V_106 . V_63 = V_31 . V_63 ;
V_106 . V_32 = V_105 ;
V_106 . V_65 = V_31 . V_65 ;
if ( F_69 ( V_1 , & V_106 , V_25 , V_59 , V_34 , V_86 ) < 0 )
goto V_48;
V_106 . V_32 = V_31 . V_32 - V_105 ;
V_106 . V_65 += V_105 ;
if ( F_69 ( V_1 , & V_106 , V_25 + 1 , 0 , V_34 , V_86 ) < 0 )
goto V_48;
} else
if ( F_69 ( V_1 , & V_31 , V_25 , V_59 , V_34 , V_86 )
< 0 )
goto V_48;
F_39 ( & V_25 , & V_59 , & V_31 ) ;
}
F_87 ( V_107 , & V_34 -> V_108 ) ;
F_88 ( V_34 , 0 ) ;
return;
V_48:
F_89 ( V_34 ) ;
}
static void F_90 ( struct V_109 * V_92 , struct V_34 * V_34 )
{
struct V_1 * V_1 = V_92 -> V_110 ;
F_15 ( & V_1 -> V_23 ) ;
if ( F_24 ( ! V_1 -> V_9 ) )
goto error;
if ( ! F_23 ( V_1 , V_34 ) ) {
F_57 ( & V_1 -> V_11 . V_14 ) ;
goto error;
}
F_85 ( V_1 , V_34 , F_91 ( V_34 ) ) ;
F_17 ( & V_1 -> V_23 ) ;
return;
error:
F_17 ( & V_1 -> V_23 ) ;
F_89 ( V_34 ) ;
}
static void F_92 ( struct V_97 * V_98 ,
unsigned long V_25 )
{
struct V_1 * V_1 ;
struct V_21 * V_22 ;
V_1 = V_98 -> V_111 -> V_4 ;
V_22 = V_1 -> V_22 ;
F_62 ( & V_22 -> V_57 ) ;
F_46 ( V_1 , V_25 ) ;
F_63 ( & V_22 -> V_57 ) ;
F_57 ( & V_1 -> V_11 . V_15 ) ;
}
static int F_93 ( struct V_1 * V_1 , int V_112 )
{
int V_73 = - V_80 ;
F_94 ( & V_1 -> V_23 ) ;
V_1 -> V_92 = F_95 ( V_47 ) ;
if ( ! V_1 -> V_92 ) {
F_34 ( L_20 ,
V_112 ) ;
goto V_48;
}
F_96 ( V_1 -> V_92 , F_90 ) ;
V_1 -> V_92 -> V_110 = V_1 ;
V_1 -> V_89 = F_97 ( 1 ) ;
if ( ! V_1 -> V_89 ) {
F_98 ( L_21 ,
V_112 ) ;
goto V_113;
}
V_1 -> V_89 -> V_114 = V_115 ;
V_1 -> V_89 -> V_116 = V_112 ;
V_1 -> V_89 -> V_117 = & V_118 ;
V_1 -> V_89 -> V_92 = V_1 -> V_92 ;
V_1 -> V_89 -> V_4 = V_1 ;
snprintf ( V_1 -> V_89 -> V_119 , 16 , L_22 , V_112 ) ;
F_73 ( V_1 -> V_89 , 0 ) ;
F_99 ( V_1 -> V_89 -> V_92 , V_33 ) ;
F_100 ( V_1 -> V_89 -> V_92 ,
V_42 ) ;
F_101 ( V_1 -> V_89 -> V_92 , V_33 ) ;
F_102 ( V_1 -> V_89 -> V_92 , V_33 ) ;
F_103 ( V_1 -> V_89 ) ;
V_73 = F_104 ( & F_105 ( V_1 -> V_89 ) -> V_120 ,
& V_121 ) ;
if ( V_73 < 0 ) {
F_98 ( L_23 ) ;
goto V_122;
}
V_1 -> V_9 = 0 ;
return 0 ;
V_122:
F_106 ( V_1 -> V_89 ) ;
F_107 ( V_1 -> V_89 ) ;
V_113:
F_108 ( V_1 -> V_92 ) ;
V_48:
return V_73 ;
}
static void F_109 ( struct V_1 * V_1 )
{
F_110 ( & F_105 ( V_1 -> V_89 ) -> V_120 ,
& V_121 ) ;
F_106 ( V_1 -> V_89 ) ;
F_107 ( V_1 -> V_89 ) ;
F_108 ( V_1 -> V_92 ) ;
}
static int T_5 F_111 ( void )
{
int V_73 , V_123 ;
if ( V_124 > V_125 ) {
F_98 ( L_24 ,
V_124 ) ;
V_73 = - V_94 ;
goto V_48;
}
V_115 = F_112 ( 0 , L_25 ) ;
if ( V_115 <= 0 ) {
F_98 ( L_26 ) ;
V_73 = - V_95 ;
goto V_48;
}
V_126 = F_32 ( V_124 * sizeof( struct V_1 ) , V_47 ) ;
if ( ! V_126 ) {
V_73 = - V_80 ;
goto V_127;
}
for ( V_123 = 0 ; V_123 < V_124 ; V_123 ++ ) {
V_73 = F_93 ( & V_126 [ V_123 ] , V_123 ) ;
if ( V_73 )
goto V_128;
}
F_59 ( L_27 , V_124 ) ;
return 0 ;
V_128:
while ( V_123 )
F_109 ( & V_126 [ -- V_123 ] ) ;
F_27 ( V_126 ) ;
V_127:
F_113 ( V_115 , L_25 ) ;
V_48:
return V_73 ;
}
static void T_6 F_114 ( void )
{
int V_129 ;
struct V_1 * V_1 ;
for ( V_129 = 0 ; V_129 < V_124 ; V_129 ++ ) {
V_1 = & V_126 [ V_129 ] ;
F_109 ( V_1 ) ;
F_70 ( V_1 , false ) ;
}
F_113 ( V_115 , L_25 ) ;
F_27 ( V_126 ) ;
F_76 ( L_28 ) ;
}
