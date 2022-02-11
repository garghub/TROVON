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
return sprintf ( V_7 , L_2 , V_1 -> V_11 . V_16 ) ;
}
static T_1 F_11 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) ( V_1 -> V_11 . V_17 ) << V_18 ) ;
}
static T_1 F_12 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
return sprintf ( V_7 , L_1 ,
( V_10 ) F_6 ( & V_1 -> V_11 . V_19 ) ) ;
}
static T_1 F_13 ( struct V_2 * V_3 ,
struct V_5 * V_6 , char * V_7 )
{
V_10 V_20 = 0 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_21 * V_22 = V_1 -> V_22 ;
F_14 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_9 )
V_20 = F_15 ( V_22 -> V_24 ) ;
F_16 ( & V_1 -> V_23 ) ;
return sprintf ( V_7 , L_1 , V_20 ) ;
}
static int F_17 ( struct V_21 * V_22 , T_2 V_25 ,
enum V_26 V_27 )
{
return V_22 -> V_28 [ V_25 ] . V_29 & F_18 ( V_27 ) ;
}
static void F_19 ( struct V_21 * V_22 , T_2 V_25 ,
enum V_26 V_27 )
{
V_22 -> V_28 [ V_25 ] . V_29 |= F_18 ( V_27 ) ;
}
static void F_20 ( struct V_21 * V_22 , T_2 V_25 ,
enum V_26 V_27 )
{
V_22 -> V_28 [ V_25 ] . V_29 &= ~ F_18 ( V_27 ) ;
}
static inline int F_21 ( struct V_30 * V_31 )
{
return V_31 -> V_32 != V_33 ;
}
static inline int F_22 ( struct V_1 * V_1 , struct V_34 * V_34 )
{
V_10 V_35 , V_36 , V_37 ;
if ( F_23 ( V_34 -> V_38 & ( V_39 - 1 ) ) )
return 0 ;
if ( F_23 ( V_34 -> V_40 & ( V_41 - 1 ) ) )
return 0 ;
V_35 = V_34 -> V_38 ;
V_36 = V_35 + ( V_34 -> V_40 >> V_42 ) ;
V_37 = V_1 -> V_8 >> V_42 ;
if ( F_23 ( V_35 >= V_37 || V_36 > V_37 || V_35 > V_36 ) )
return 0 ;
return 1 ;
}
static void F_24 ( struct V_21 * V_22 )
{
F_25 ( V_22 -> V_24 ) ;
F_26 ( V_22 -> V_43 ) ;
F_27 ( ( unsigned long ) V_22 -> V_44 , 1 ) ;
F_28 ( V_22 -> V_28 ) ;
F_26 ( V_22 ) ;
}
static struct V_21 * F_29 ( V_10 V_8 )
{
T_3 V_45 ;
struct V_21 * V_22 = F_30 ( sizeof( * V_22 ) , V_46 ) ;
if ( ! V_22 )
goto V_47;
V_22 -> V_43 = F_31 ( V_48 , V_46 ) ;
if ( ! V_22 -> V_43 )
goto V_49;
V_22 -> V_44 =
( void * ) F_32 ( V_46 | V_50 , 1 ) ;
if ( ! V_22 -> V_44 ) {
F_33 ( L_3 ) ;
goto V_51;
}
V_45 = V_8 >> V_18 ;
V_22 -> V_28 = F_34 ( V_45 * sizeof( * V_22 -> V_28 ) ) ;
if ( ! V_22 -> V_28 ) {
F_33 ( L_4 ) ;
goto V_52;
}
V_22 -> V_24 = F_35 ( V_53 | V_54 ) ;
if ( ! V_22 -> V_24 ) {
F_33 ( L_5 ) ;
goto V_55;
}
return V_22 ;
V_55:
F_28 ( V_22 -> V_28 ) ;
V_52:
F_27 ( ( unsigned long ) V_22 -> V_44 , 1 ) ;
V_51:
F_26 ( V_22 -> V_43 ) ;
V_49:
F_26 ( V_22 ) ;
V_22 = NULL ;
V_47:
return V_22 ;
}
static void F_36 ( T_2 * V_25 , int * V_56 , struct V_30 * V_31 )
{
if ( * V_56 + V_31 -> V_32 >= V_33 )
( * V_25 ) ++ ;
* V_56 = ( * V_56 + V_31 -> V_32 ) % V_33 ;
}
static int F_37 ( void * V_57 )
{
unsigned int V_58 ;
unsigned long * V_59 ;
V_59 = ( unsigned long * ) V_57 ;
for ( V_58 = 0 ; V_58 != V_33 / sizeof( * V_59 ) ; V_58 ++ ) {
if ( V_59 [ V_58 ] )
return 0 ;
}
return 1 ;
}
static void F_38 ( struct V_30 * V_31 )
{
struct V_59 * V_59 = V_31 -> V_60 ;
void * V_61 ;
V_61 = F_39 ( V_59 ) ;
if ( F_21 ( V_31 ) )
memset ( V_61 + V_31 -> V_62 , 0 , V_31 -> V_32 ) ;
else
F_40 ( V_61 ) ;
F_41 ( V_61 ) ;
F_42 ( V_59 ) ;
}
static void F_43 ( struct V_1 * V_1 , T_3 V_25 )
{
struct V_21 * V_22 = V_1 -> V_22 ;
unsigned long V_63 = V_22 -> V_28 [ V_25 ] . V_63 ;
T_4 V_64 = V_22 -> V_28 [ V_25 ] . V_64 ;
if ( F_23 ( ! V_63 ) ) {
if ( F_17 ( V_22 , V_25 , V_65 ) ) {
F_20 ( V_22 , V_25 , V_65 ) ;
V_1 -> V_11 . V_16 -- ;
}
return;
}
if ( F_23 ( V_64 > V_66 ) )
V_1 -> V_11 . V_67 -- ;
F_44 ( V_22 -> V_24 , V_63 ) ;
if ( V_64 <= V_33 / 2 )
V_1 -> V_11 . V_68 -- ;
F_45 ( V_22 -> V_28 [ V_25 ] . V_64 , & V_1 -> V_11 . V_19 ) ;
V_1 -> V_11 . V_17 -- ;
V_22 -> V_28 [ V_25 ] . V_63 = 0 ;
V_22 -> V_28 [ V_25 ] . V_64 = 0 ;
}
static int F_46 ( struct V_1 * V_1 , char * V_69 , T_2 V_25 )
{
int V_70 = V_71 ;
T_3 V_72 = V_33 ;
unsigned char * V_73 ;
struct V_21 * V_22 = V_1 -> V_22 ;
unsigned long V_63 = V_22 -> V_28 [ V_25 ] . V_63 ;
if ( ! V_63 || F_17 ( V_22 , V_25 , V_65 ) ) {
F_40 ( V_69 ) ;
return 0 ;
}
V_73 = F_47 ( V_22 -> V_24 , V_63 , V_74 ) ;
if ( V_22 -> V_28 [ V_25 ] . V_64 == V_33 )
F_48 ( V_69 , V_73 ) ;
else
V_70 = F_49 ( V_73 , V_22 -> V_28 [ V_25 ] . V_64 ,
V_69 , & V_72 ) ;
F_50 ( V_22 -> V_24 , V_63 ) ;
if ( F_23 ( V_70 != V_71 ) ) {
F_33 ( L_6 , V_70 , V_25 ) ;
F_51 ( & V_1 -> V_11 . V_75 ) ;
return V_70 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_1 , struct V_30 * V_31 ,
T_2 V_25 , int V_56 , struct V_34 * V_34 )
{
int V_70 ;
struct V_59 * V_59 ;
unsigned char * V_61 , * V_76 = NULL ;
struct V_21 * V_22 = V_1 -> V_22 ;
V_59 = V_31 -> V_60 ;
if ( F_23 ( ! V_22 -> V_28 [ V_25 ] . V_63 ) ||
F_17 ( V_22 , V_25 , V_65 ) ) {
F_38 ( V_31 ) ;
return 0 ;
}
if ( F_21 ( V_31 ) )
V_76 = F_30 ( V_33 , V_53 ) ;
V_61 = F_39 ( V_59 ) ;
if ( ! F_21 ( V_31 ) )
V_76 = V_61 ;
if ( ! V_76 ) {
F_53 ( L_7 ) ;
V_70 = - V_77 ;
goto V_78;
}
V_70 = F_46 ( V_1 , V_76 , V_25 ) ;
if ( F_23 ( V_70 != V_71 ) )
goto V_78;
if ( F_21 ( V_31 ) )
memcpy ( V_61 + V_31 -> V_62 , V_76 + V_56 ,
V_31 -> V_32 ) ;
F_42 ( V_59 ) ;
V_70 = 0 ;
V_78:
F_41 ( V_61 ) ;
if ( F_21 ( V_31 ) )
F_26 ( V_76 ) ;
return V_70 ;
}
static int F_54 ( struct V_1 * V_1 , struct V_30 * V_31 , T_2 V_25 ,
int V_56 )
{
int V_70 = 0 ;
T_3 V_72 ;
unsigned long V_63 ;
struct V_59 * V_59 ;
unsigned char * V_61 , * V_73 , * V_79 , * V_76 = NULL ;
struct V_21 * V_22 = V_1 -> V_22 ;
V_59 = V_31 -> V_60 ;
V_79 = V_22 -> V_44 ;
if ( F_21 ( V_31 ) ) {
V_76 = F_30 ( V_33 , V_53 ) ;
if ( ! V_76 ) {
V_70 = - V_77 ;
goto V_47;
}
V_70 = F_46 ( V_1 , V_76 , V_25 ) ;
if ( V_70 )
goto V_47;
}
V_61 = F_39 ( V_59 ) ;
if ( F_21 ( V_31 ) ) {
memcpy ( V_76 + V_56 , V_61 + V_31 -> V_62 ,
V_31 -> V_32 ) ;
F_41 ( V_61 ) ;
V_61 = NULL ;
} else {
V_76 = V_61 ;
}
if ( F_37 ( V_76 ) ) {
F_41 ( V_61 ) ;
F_43 ( V_1 , V_25 ) ;
V_1 -> V_11 . V_16 ++ ;
F_19 ( V_22 , V_25 , V_65 ) ;
V_70 = 0 ;
goto V_47;
}
if ( F_23 ( V_22 -> V_28 [ V_25 ] . V_63 ||
F_17 ( V_22 , V_25 , V_65 ) ) )
F_43 ( V_1 , V_25 ) ;
V_70 = F_55 ( V_76 , V_33 , V_79 , & V_72 ,
V_22 -> V_43 ) ;
if ( ! F_21 ( V_31 ) ) {
F_41 ( V_61 ) ;
V_61 = NULL ;
V_76 = NULL ;
}
if ( F_23 ( V_70 != V_71 ) ) {
F_33 ( L_8 , V_70 ) ;
goto V_47;
}
if ( F_23 ( V_72 > V_66 ) ) {
V_1 -> V_11 . V_67 ++ ;
V_72 = V_33 ;
V_79 = NULL ;
if ( F_21 ( V_31 ) )
V_79 = V_76 ;
}
V_63 = F_56 ( V_22 -> V_24 , V_72 ) ;
if ( ! V_63 ) {
F_53 ( L_9 ,
V_25 , V_72 ) ;
V_70 = - V_77 ;
goto V_47;
}
V_73 = F_47 ( V_22 -> V_24 , V_63 , V_80 ) ;
if ( ( V_72 == V_33 ) && ! F_21 ( V_31 ) ) {
V_79 = F_39 ( V_59 ) ;
F_48 ( V_73 , V_79 ) ;
F_41 ( V_79 ) ;
} else {
memcpy ( V_73 , V_79 , V_72 ) ;
}
F_50 ( V_22 -> V_24 , V_63 ) ;
F_43 ( V_1 , V_25 ) ;
V_22 -> V_28 [ V_25 ] . V_63 = V_63 ;
V_22 -> V_28 [ V_25 ] . V_64 = V_72 ;
F_57 ( V_72 , & V_1 -> V_11 . V_19 ) ;
V_1 -> V_11 . V_17 ++ ;
if ( V_72 <= V_33 / 2 )
V_1 -> V_11 . V_68 ++ ;
V_47:
if ( F_21 ( V_31 ) )
F_26 ( V_76 ) ;
if ( V_70 )
F_51 ( & V_1 -> V_11 . V_81 ) ;
return V_70 ;
}
static void F_58 ( struct V_1 * V_1 )
{
struct V_82 * V_83 ;
F_59 ( & V_1 -> V_84 ) ;
while ( V_1 -> V_85 ) {
V_83 = V_1 -> V_85 ;
V_1 -> V_85 = V_83 -> V_86 ;
F_43 ( V_1 , V_83 -> V_25 ) ;
F_26 ( V_83 ) ;
}
F_60 ( & V_1 -> V_84 ) ;
}
static int F_61 ( struct V_1 * V_1 , struct V_30 * V_31 , T_2 V_25 ,
int V_56 , struct V_34 * V_34 , int V_87 )
{
int V_70 ;
if ( V_87 == V_88 ) {
F_14 ( & V_1 -> V_89 ) ;
F_58 ( V_1 ) ;
V_70 = F_52 ( V_1 , V_31 , V_25 , V_56 , V_34 ) ;
F_16 ( & V_1 -> V_89 ) ;
} else {
F_62 ( & V_1 -> V_89 ) ;
F_58 ( V_1 ) ;
V_70 = F_54 ( V_1 , V_31 , V_25 , V_56 ) ;
F_63 ( & V_1 -> V_89 ) ;
}
return V_70 ;
}
static void F_64 ( struct V_1 * V_1 , bool V_90 )
{
T_3 V_25 ;
struct V_21 * V_22 ;
F_65 ( & V_1 -> V_91 ) ;
F_62 ( & V_1 -> V_23 ) ;
if ( ! V_1 -> V_9 ) {
F_63 ( & V_1 -> V_23 ) ;
return;
}
V_22 = V_1 -> V_22 ;
V_1 -> V_9 = 0 ;
for ( V_25 = 0 ; V_25 < V_1 -> V_8 > > V_18 ; V_25 ++ ) {
unsigned long V_63 = V_22 -> V_28 [ V_25 ] . V_63 ;
if ( ! V_63 )
continue;
F_44 ( V_22 -> V_24 , V_63 ) ;
}
F_24 ( V_1 -> V_22 ) ;
V_1 -> V_22 = NULL ;
memset ( & V_1 -> V_11 , 0 , sizeof( V_1 -> V_11 ) ) ;
V_1 -> V_8 = 0 ;
if ( V_90 )
F_66 ( V_1 -> V_92 , 0 ) ;
F_63 ( & V_1 -> V_23 ) ;
}
static void F_67 ( struct V_1 * V_1 , struct V_21 * V_22 )
{
if ( V_1 -> V_8 > 2 * ( V_93 << V_18 ) ) {
F_53 (
L_10
L_11
L_12
L_13
L_14
L_15
L_16
L_17 ,
( V_93 << V_18 ) >> 10 , V_1 -> V_8 >> 10
) ;
}
F_68 ( V_94 , V_1 -> V_92 -> V_95 ) ;
V_1 -> V_22 = V_22 ;
V_1 -> V_9 = 1 ;
F_69 ( L_18 ) ;
}
static T_1 F_70 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_3 V_96 )
{
V_10 V_8 ;
struct V_21 * V_22 ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_8 = F_71 ( V_7 , NULL ) ;
if ( ! V_8 )
return - V_97 ;
V_8 = F_72 ( V_8 ) ;
V_22 = F_29 ( V_8 ) ;
F_62 ( & V_1 -> V_23 ) ;
if ( V_1 -> V_9 ) {
F_63 ( & V_1 -> V_23 ) ;
F_24 ( V_22 ) ;
F_53 ( L_19 ) ;
return - V_98 ;
}
V_1 -> V_8 = V_8 ;
F_66 ( V_1 -> V_92 , V_1 -> V_8 >> V_42 ) ;
F_67 ( V_1 , V_22 ) ;
F_63 ( & V_1 -> V_23 ) ;
return V_96 ;
}
static T_1 F_73 ( struct V_2 * V_3 ,
struct V_5 * V_6 , const char * V_7 , T_3 V_96 )
{
int V_70 ;
unsigned short V_99 ;
struct V_1 * V_1 ;
struct V_100 * V_101 ;
V_1 = F_1 ( V_3 ) ;
V_101 = F_74 ( V_1 -> V_92 , 0 ) ;
if ( V_101 -> V_102 )
return - V_98 ;
V_70 = F_75 ( V_7 , 10 , & V_99 ) ;
if ( V_70 )
return V_70 ;
if ( ! V_99 )
return - V_97 ;
if ( V_101 )
F_76 ( V_101 ) ;
F_64 ( V_1 , true ) ;
return V_96 ;
}
static void F_77 ( struct V_1 * V_1 , struct V_34 * V_34 , int V_87 )
{
int V_103 , V_56 ;
T_2 V_25 ;
struct V_30 * V_31 ;
switch ( V_87 ) {
case V_88 :
F_51 ( & V_1 -> V_11 . V_12 ) ;
break;
case V_104 :
F_51 ( & V_1 -> V_11 . V_13 ) ;
break;
}
V_25 = V_34 -> V_38 >> V_105 ;
V_56 = ( V_34 -> V_38 & ( V_106 - 1 ) ) << V_42 ;
F_78 (bvec, bio, i) {
int V_107 = V_33 - V_56 ;
if ( V_31 -> V_32 > V_107 ) {
struct V_30 V_108 ;
V_108 . V_60 = V_31 -> V_60 ;
V_108 . V_32 = V_107 ;
V_108 . V_62 = V_31 -> V_62 ;
if ( F_61 ( V_1 , & V_108 , V_25 , V_56 , V_34 , V_87 ) < 0 )
goto V_47;
V_108 . V_32 = V_31 -> V_32 - V_107 ;
V_108 . V_62 += V_107 ;
if ( F_61 ( V_1 , & V_108 , V_25 + 1 , 0 , V_34 , V_87 ) < 0 )
goto V_47;
} else
if ( F_61 ( V_1 , V_31 , V_25 , V_56 , V_34 , V_87 )
< 0 )
goto V_47;
F_36 ( & V_25 , & V_56 , V_31 ) ;
}
F_79 ( V_109 , & V_34 -> V_110 ) ;
F_80 ( V_34 , 0 ) ;
return;
V_47:
F_81 ( V_34 ) ;
}
static void F_82 ( struct V_111 * V_95 , struct V_34 * V_34 )
{
struct V_1 * V_1 = V_95 -> V_112 ;
F_14 ( & V_1 -> V_23 ) ;
if ( F_23 ( ! V_1 -> V_9 ) )
goto error;
if ( ! F_22 ( V_1 , V_34 ) ) {
F_51 ( & V_1 -> V_11 . V_14 ) ;
goto error;
}
F_77 ( V_1 , V_34 , F_83 ( V_34 ) ) ;
F_16 ( & V_1 -> V_23 ) ;
return;
error:
F_16 ( & V_1 -> V_23 ) ;
F_81 ( V_34 ) ;
}
static void V_82 ( struct V_113 * V_114 )
{
struct V_1 * V_1 ;
V_1 = F_84 ( V_114 , struct V_1 , V_91 ) ;
F_62 ( & V_1 -> V_89 ) ;
F_58 ( V_1 ) ;
F_63 ( & V_1 -> V_89 ) ;
}
static void F_85 ( struct V_1 * V_1 , struct V_82 * V_83 )
{
F_59 ( & V_1 -> V_84 ) ;
V_83 -> V_86 = V_1 -> V_85 ;
V_1 -> V_85 = V_83 ;
F_60 ( & V_1 -> V_84 ) ;
}
static void F_86 ( struct V_100 * V_101 ,
unsigned long V_25 )
{
struct V_1 * V_1 ;
struct V_82 * V_83 ;
V_1 = V_101 -> V_115 -> V_4 ;
F_51 ( & V_1 -> V_11 . V_15 ) ;
V_83 = F_30 ( sizeof( struct V_82 ) , V_116 ) ;
if ( ! V_83 )
return;
V_83 -> V_25 = V_25 ;
F_85 ( V_1 , V_83 ) ;
F_87 ( & V_1 -> V_91 ) ;
}
static int F_88 ( struct V_1 * V_1 , int V_117 )
{
int V_70 = - V_77 ;
F_89 ( & V_1 -> V_89 ) ;
F_89 ( & V_1 -> V_23 ) ;
F_90 ( & V_1 -> V_91 , V_82 ) ;
F_91 ( & V_1 -> V_84 ) ;
V_1 -> V_85 = NULL ;
V_1 -> V_95 = F_92 ( V_46 ) ;
if ( ! V_1 -> V_95 ) {
F_33 ( L_20 ,
V_117 ) ;
goto V_47;
}
F_93 ( V_1 -> V_95 , F_82 ) ;
V_1 -> V_95 -> V_112 = V_1 ;
V_1 -> V_92 = F_94 ( 1 ) ;
if ( ! V_1 -> V_92 ) {
F_95 ( L_21 ,
V_117 ) ;
goto V_118;
}
V_1 -> V_92 -> V_119 = V_120 ;
V_1 -> V_92 -> V_121 = V_117 ;
V_1 -> V_92 -> V_122 = & V_123 ;
V_1 -> V_92 -> V_95 = V_1 -> V_95 ;
V_1 -> V_92 -> V_4 = V_1 ;
snprintf ( V_1 -> V_92 -> V_124 , 16 , L_22 , V_117 ) ;
F_66 ( V_1 -> V_92 , 0 ) ;
F_96 ( V_1 -> V_92 -> V_95 , V_33 ) ;
F_97 ( V_1 -> V_92 -> V_95 ,
V_41 ) ;
F_98 ( V_1 -> V_92 -> V_95 , V_33 ) ;
F_99 ( V_1 -> V_92 -> V_95 , V_33 ) ;
F_100 ( V_1 -> V_92 ) ;
V_70 = F_101 ( & F_102 ( V_1 -> V_92 ) -> V_125 ,
& V_126 ) ;
if ( V_70 < 0 ) {
F_95 ( L_23 ) ;
goto V_127;
}
V_1 -> V_9 = 0 ;
return 0 ;
V_127:
F_103 ( V_1 -> V_92 ) ;
F_104 ( V_1 -> V_92 ) ;
V_118:
F_105 ( V_1 -> V_95 ) ;
V_47:
return V_70 ;
}
static void F_106 ( struct V_1 * V_1 )
{
F_107 ( & F_102 ( V_1 -> V_92 ) -> V_125 ,
& V_126 ) ;
if ( V_1 -> V_92 ) {
F_103 ( V_1 -> V_92 ) ;
F_104 ( V_1 -> V_92 ) ;
}
if ( V_1 -> V_95 )
F_105 ( V_1 -> V_95 ) ;
}
static int T_5 F_108 ( void )
{
int V_70 , V_128 ;
if ( V_129 > V_130 ) {
F_95 ( L_24 ,
V_129 ) ;
V_70 = - V_97 ;
goto V_47;
}
V_120 = F_109 ( 0 , L_25 ) ;
if ( V_120 <= 0 ) {
F_95 ( L_26 ) ;
V_70 = - V_98 ;
goto V_47;
}
V_131 = F_31 ( V_129 * sizeof( struct V_1 ) , V_46 ) ;
if ( ! V_131 ) {
V_70 = - V_77 ;
goto V_132;
}
for ( V_128 = 0 ; V_128 < V_129 ; V_128 ++ ) {
V_70 = F_88 ( & V_131 [ V_128 ] , V_128 ) ;
if ( V_70 )
goto V_133;
}
F_53 ( L_27 , V_129 ) ;
return 0 ;
V_133:
while ( V_128 )
F_106 ( & V_131 [ -- V_128 ] ) ;
F_26 ( V_131 ) ;
V_132:
F_110 ( V_120 , L_25 ) ;
V_47:
return V_70 ;
}
static void T_6 F_111 ( void )
{
int V_103 ;
struct V_1 * V_1 ;
for ( V_103 = 0 ; V_103 < V_129 ; V_103 ++ ) {
V_1 = & V_131 [ V_103 ] ;
F_106 ( V_1 ) ;
F_64 ( V_1 , false ) ;
}
F_110 ( V_120 , L_25 ) ;
F_26 ( V_131 ) ;
F_69 ( L_28 ) ;
}
