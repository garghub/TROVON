static inline int F_1 ( struct V_1 * V_1 )
{
return V_1 -> V_2 != NULL ;
}
static inline struct V_1 * F_2 ( struct V_3 * V_4 )
{
return (struct V_1 * ) F_3 ( V_4 ) -> V_5 ;
}
static T_1 F_4 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_1 -> V_10 ) ;
}
static T_1 F_6 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
T_2 V_11 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_11 = F_1 ( V_1 ) ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_2 , V_11 ) ;
}
static T_1 F_9 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
return F_5 ( V_8 , V_9 , L_1 ,
( V_13 ) ( F_10 ( & V_1 -> V_14 . V_15 ) ) << V_16 ) ;
}
static T_1 F_11 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
V_13 V_11 = 0 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
struct V_17 * V_2 = V_1 -> V_2 ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) )
V_11 = F_12 ( V_2 -> V_18 ) ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_1 , V_11 ) ;
}
static T_1 F_13 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
int V_11 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_11 = V_1 -> V_19 ;
F_8 ( & V_1 -> V_12 ) ;
return F_5 ( V_8 , V_9 , L_3 , V_11 ) ;
}
static T_1 F_14 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_20 )
{
int V_21 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_22 ;
V_22 = F_15 ( V_8 , 0 , & V_21 ) ;
if ( V_22 < 0 )
return V_22 ;
if ( V_21 < 1 )
return - V_23 ;
F_16 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
if ( ! F_17 ( V_1 -> V_24 , V_21 ) ) {
F_18 ( L_4 ) ;
V_22 = - V_23 ;
goto V_25;
}
}
V_1 -> V_19 = V_21 ;
V_22 = V_20 ;
V_25:
F_19 ( & V_1 -> V_12 ) ;
return V_22 ;
}
static T_1 F_20 ( struct V_3 * V_4 ,
struct V_6 * V_7 , char * V_8 )
{
T_3 V_26 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_7 ( & V_1 -> V_12 ) ;
V_26 = F_21 ( V_1 -> V_27 , V_8 ) ;
F_8 ( & V_1 -> V_12 ) ;
return V_26 ;
}
static T_1 F_22 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_20 )
{
struct V_1 * V_1 = F_2 ( V_4 ) ;
F_16 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
F_19 ( & V_1 -> V_12 ) ;
F_18 ( L_5 ) ;
return - V_28 ;
}
F_23 ( V_1 -> V_27 , V_8 , sizeof( V_1 -> V_27 ) ) ;
F_19 ( & V_1 -> V_12 ) ;
return V_20 ;
}
static int F_24 ( struct V_17 * V_2 , T_2 V_29 ,
enum V_30 V_31 )
{
return V_2 -> V_32 [ V_29 ] . V_33 & F_25 ( V_31 ) ;
}
static void F_26 ( struct V_17 * V_2 , T_2 V_29 ,
enum V_30 V_31 )
{
V_2 -> V_32 [ V_29 ] . V_33 |= F_25 ( V_31 ) ;
}
static void F_27 ( struct V_17 * V_2 , T_2 V_29 ,
enum V_30 V_31 )
{
V_2 -> V_32 [ V_29 ] . V_33 &= ~ F_25 ( V_31 ) ;
}
static T_3 F_28 ( struct V_17 * V_2 , T_2 V_29 )
{
return V_2 -> V_32 [ V_29 ] . V_33 & ( F_25 ( V_34 ) - 1 ) ;
}
static void F_29 ( struct V_17 * V_2 ,
T_2 V_29 , T_3 V_35 )
{
unsigned long V_36 = V_2 -> V_32 [ V_29 ] . V_33 >> V_34 ;
V_2 -> V_32 [ V_29 ] . V_33 = ( V_36 << V_34 ) | V_35 ;
}
static inline int F_30 ( struct V_37 * V_38 )
{
return V_38 -> V_39 != V_9 ;
}
static inline int F_31 ( struct V_1 * V_1 , struct V_40 * V_40 )
{
V_13 V_41 , V_42 , V_43 ;
if ( F_32 ( V_40 -> V_44 . V_45 &
( V_46 - 1 ) ) )
return 0 ;
if ( F_32 ( V_40 -> V_44 . V_47 & ( V_48 - 1 ) ) )
return 0 ;
V_41 = V_40 -> V_44 . V_45 ;
V_42 = V_41 + ( V_40 -> V_44 . V_47 >> V_49 ) ;
V_43 = V_1 -> V_10 >> V_49 ;
if ( F_32 ( V_41 >= V_43 || V_42 > V_43 || V_41 > V_42 ) )
return 0 ;
return 1 ;
}
static void F_33 ( struct V_17 * V_2 )
{
F_34 ( V_2 -> V_18 ) ;
F_35 ( V_2 -> V_32 ) ;
F_36 ( V_2 ) ;
}
static struct V_17 * F_37 ( V_13 V_10 )
{
T_3 V_50 ;
struct V_17 * V_2 = F_38 ( sizeof( * V_2 ) , V_51 ) ;
if ( ! V_2 )
goto V_25;
V_50 = V_10 >> V_16 ;
V_2 -> V_32 = F_39 ( V_50 * sizeof( * V_2 -> V_32 ) ) ;
if ( ! V_2 -> V_32 ) {
F_40 ( L_6 ) ;
goto V_52;
}
V_2 -> V_18 = F_41 ( V_53 | V_54 ) ;
if ( ! V_2 -> V_18 ) {
F_40 ( L_7 ) ;
goto V_55;
}
return V_2 ;
V_55:
F_35 ( V_2 -> V_32 ) ;
V_52:
F_36 ( V_2 ) ;
V_2 = NULL ;
V_25:
return V_2 ;
}
static void F_42 ( T_2 * V_29 , int * V_56 , struct V_37 * V_38 )
{
if ( * V_56 + V_38 -> V_39 >= V_9 )
( * V_29 ) ++ ;
* V_56 = ( * V_56 + V_38 -> V_39 ) % V_9 ;
}
static int F_43 ( void * V_57 )
{
unsigned int V_58 ;
unsigned long * V_59 ;
V_59 = ( unsigned long * ) V_57 ;
for ( V_58 = 0 ; V_58 != V_9 / sizeof( * V_59 ) ; V_58 ++ ) {
if ( V_59 [ V_58 ] )
return 0 ;
}
return 1 ;
}
static void F_44 ( struct V_37 * V_38 )
{
struct V_59 * V_59 = V_38 -> V_60 ;
void * V_61 ;
V_61 = F_45 ( V_59 ) ;
if ( F_30 ( V_38 ) )
memset ( V_61 + V_38 -> V_62 , 0 , V_38 -> V_39 ) ;
else
F_46 ( V_61 ) ;
F_47 ( V_61 ) ;
F_48 ( V_59 ) ;
}
static void F_49 ( struct V_1 * V_1 , T_3 V_29 )
{
struct V_17 * V_2 = V_1 -> V_2 ;
unsigned long V_63 = V_2 -> V_32 [ V_29 ] . V_63 ;
if ( F_32 ( ! V_63 ) ) {
if ( F_24 ( V_2 , V_29 , V_64 ) ) {
F_27 ( V_2 , V_29 , V_64 ) ;
F_50 ( & V_1 -> V_14 . V_65 ) ;
}
return;
}
F_51 ( V_2 -> V_18 , V_63 ) ;
F_52 ( F_28 ( V_2 , V_29 ) ,
& V_1 -> V_14 . V_66 ) ;
F_50 ( & V_1 -> V_14 . V_15 ) ;
V_2 -> V_32 [ V_29 ] . V_63 = 0 ;
F_29 ( V_2 , V_29 , 0 ) ;
}
static int F_53 ( struct V_1 * V_1 , char * V_67 , T_2 V_29 )
{
int V_22 = 0 ;
unsigned char * V_68 ;
struct V_17 * V_2 = V_1 -> V_2 ;
unsigned long V_63 ;
T_3 V_35 ;
F_54 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
V_63 = V_2 -> V_32 [ V_29 ] . V_63 ;
V_35 = F_28 ( V_2 , V_29 ) ;
if ( ! V_63 || F_24 ( V_2 , V_29 , V_64 ) ) {
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_46 ( V_67 ) ;
return 0 ;
}
V_68 = F_56 ( V_2 -> V_18 , V_63 , V_70 ) ;
if ( V_35 == V_9 )
F_57 ( V_67 , V_68 ) ;
else
V_22 = F_58 ( V_1 -> V_24 , V_68 , V_35 , V_67 ) ;
F_59 ( V_2 -> V_18 , V_63 ) ;
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
if ( F_32 ( V_22 ) ) {
F_40 ( L_8 , V_22 , V_29 ) ;
return V_22 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_1 , struct V_37 * V_38 ,
T_2 V_29 , int V_56 , struct V_40 * V_40 )
{
int V_22 ;
struct V_59 * V_59 ;
unsigned char * V_61 , * V_71 = NULL ;
struct V_17 * V_2 = V_1 -> V_2 ;
V_59 = V_38 -> V_60 ;
F_54 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
if ( F_32 ( ! V_2 -> V_32 [ V_29 ] . V_63 ) ||
F_24 ( V_2 , V_29 , V_64 ) ) {
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_44 ( V_38 ) ;
return 0 ;
}
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
if ( F_30 ( V_38 ) )
V_71 = F_38 ( V_9 , V_53 ) ;
V_61 = F_45 ( V_59 ) ;
if ( ! F_30 ( V_38 ) )
V_71 = V_61 ;
if ( ! V_71 ) {
F_18 ( L_9 ) ;
V_22 = - V_72 ;
goto V_73;
}
V_22 = F_53 ( V_1 , V_71 , V_29 ) ;
if ( F_32 ( V_22 ) )
goto V_73;
if ( F_30 ( V_38 ) )
memcpy ( V_61 + V_38 -> V_62 , V_71 + V_56 ,
V_38 -> V_39 ) ;
F_48 ( V_59 ) ;
V_22 = 0 ;
V_73:
F_47 ( V_61 ) ;
if ( F_30 ( V_38 ) )
F_36 ( V_71 ) ;
return V_22 ;
}
static int F_61 ( struct V_1 * V_1 , struct V_37 * V_38 , T_2 V_29 ,
int V_56 )
{
int V_22 = 0 ;
T_3 V_74 ;
unsigned long V_63 ;
struct V_59 * V_59 ;
unsigned char * V_61 , * V_68 , * V_75 , * V_71 = NULL ;
struct V_17 * V_2 = V_1 -> V_2 ;
struct V_76 * V_77 ;
bool V_78 = false ;
V_59 = V_38 -> V_60 ;
if ( F_30 ( V_38 ) ) {
V_71 = F_38 ( V_9 , V_53 ) ;
if ( ! V_71 ) {
V_22 = - V_72 ;
goto V_25;
}
V_22 = F_53 ( V_1 , V_71 , V_29 ) ;
if ( V_22 )
goto V_25;
}
V_77 = F_62 ( V_1 -> V_24 ) ;
V_78 = true ;
V_61 = F_45 ( V_59 ) ;
if ( F_30 ( V_38 ) ) {
memcpy ( V_71 + V_56 , V_61 + V_38 -> V_62 ,
V_38 -> V_39 ) ;
F_47 ( V_61 ) ;
V_61 = NULL ;
} else {
V_71 = V_61 ;
}
if ( F_43 ( V_71 ) ) {
F_47 ( V_61 ) ;
F_54 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_49 ( V_1 , V_29 ) ;
F_26 ( V_2 , V_29 , V_64 ) ;
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_63 ( & V_1 -> V_14 . V_65 ) ;
V_22 = 0 ;
goto V_25;
}
V_22 = F_64 ( V_1 -> V_24 , V_77 , V_71 , & V_74 ) ;
if ( ! F_30 ( V_38 ) ) {
F_47 ( V_61 ) ;
V_61 = NULL ;
V_71 = NULL ;
}
if ( F_32 ( V_22 ) ) {
F_40 ( L_10 , V_22 ) ;
goto V_25;
}
V_75 = V_77 -> V_79 ;
if ( F_32 ( V_74 > V_80 ) ) {
V_74 = V_9 ;
if ( F_30 ( V_38 ) )
V_75 = V_71 ;
}
V_63 = F_65 ( V_2 -> V_18 , V_74 ) ;
if ( ! V_63 ) {
F_18 ( L_11 ,
V_29 , V_74 ) ;
V_22 = - V_72 ;
goto V_25;
}
V_68 = F_56 ( V_2 -> V_18 , V_63 , V_81 ) ;
if ( ( V_74 == V_9 ) && ! F_30 ( V_38 ) ) {
V_75 = F_45 ( V_59 ) ;
F_57 ( V_68 , V_75 ) ;
F_47 ( V_75 ) ;
} else {
memcpy ( V_68 , V_75 , V_74 ) ;
}
F_66 ( V_1 -> V_24 , V_77 ) ;
V_78 = false ;
F_59 ( V_2 -> V_18 , V_63 ) ;
F_54 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_49 ( V_1 , V_29 ) ;
V_2 -> V_32 [ V_29 ] . V_63 = V_63 ;
F_29 ( V_2 , V_29 , V_74 ) ;
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_67 ( V_74 , & V_1 -> V_14 . V_66 ) ;
F_63 ( & V_1 -> V_14 . V_15 ) ;
V_25:
if ( V_78 )
F_66 ( V_1 -> V_24 , V_77 ) ;
if ( F_30 ( V_38 ) )
F_36 ( V_71 ) ;
return V_22 ;
}
static int F_68 ( struct V_1 * V_1 , struct V_37 * V_38 , T_2 V_29 ,
int V_56 , struct V_40 * V_40 )
{
int V_22 ;
int V_82 = F_69 ( V_40 ) ;
if ( V_82 == V_83 ) {
F_63 ( & V_1 -> V_14 . V_84 ) ;
V_22 = F_60 ( V_1 , V_38 , V_29 , V_56 , V_40 ) ;
} else {
F_63 ( & V_1 -> V_14 . V_85 ) ;
V_22 = F_61 ( V_1 , V_38 , V_29 , V_56 ) ;
}
if ( F_32 ( V_22 ) ) {
if ( V_82 == V_83 )
F_63 ( & V_1 -> V_14 . V_86 ) ;
else
F_63 ( & V_1 -> V_14 . V_87 ) ;
}
return V_22 ;
}
static void F_70 ( struct V_1 * V_1 , T_2 V_29 ,
int V_56 , struct V_40 * V_40 )
{
T_3 V_88 = V_40 -> V_44 . V_47 ;
struct V_17 * V_2 = V_1 -> V_2 ;
if ( V_56 ) {
if ( V_88 <= ( V_9 - V_56 ) )
return;
V_88 -= ( V_9 - V_56 ) ;
V_29 ++ ;
}
while ( V_88 >= V_9 ) {
F_54 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_49 ( V_1 , V_29 ) ;
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
V_29 ++ ;
V_88 -= V_9 ;
}
}
static void F_71 ( struct V_1 * V_1 , bool V_89 )
{
T_3 V_29 ;
struct V_17 * V_2 ;
F_16 ( & V_1 -> V_12 ) ;
if ( ! F_1 ( V_1 ) ) {
F_19 ( & V_1 -> V_12 ) ;
return;
}
V_2 = V_1 -> V_2 ;
for ( V_29 = 0 ; V_29 < V_1 -> V_10 > > V_16 ; V_29 ++ ) {
unsigned long V_63 = V_2 -> V_32 [ V_29 ] . V_63 ;
if ( ! V_63 )
continue;
F_51 ( V_2 -> V_18 , V_63 ) ;
}
F_72 ( V_1 -> V_24 ) ;
V_1 -> V_19 = 1 ;
F_33 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
memset ( & V_1 -> V_14 , 0 , sizeof( V_1 -> V_14 ) ) ;
V_1 -> V_10 = 0 ;
if ( V_89 )
F_73 ( V_1 -> V_90 , 0 ) ;
F_19 ( & V_1 -> V_12 ) ;
if ( V_89 )
F_74 ( V_1 -> V_90 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_20 )
{
V_13 V_10 ;
struct V_91 * V_24 ;
struct V_17 * V_2 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_92 ;
V_10 = F_76 ( V_8 , NULL ) ;
if ( ! V_10 )
return - V_23 ;
V_10 = F_77 ( V_10 ) ;
V_2 = F_37 ( V_10 ) ;
if ( ! V_2 )
return - V_72 ;
V_24 = F_78 ( V_1 -> V_27 , V_1 -> V_19 ) ;
if ( F_79 ( V_24 ) ) {
F_18 ( L_12 ,
V_1 -> V_27 ) ;
V_92 = F_80 ( V_24 ) ;
goto V_93;
}
F_16 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
F_18 ( L_13 ) ;
V_92 = - V_28 ;
goto V_94;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_10 = V_10 ;
F_73 ( V_1 -> V_90 , V_1 -> V_10 >> V_49 ) ;
F_19 ( & V_1 -> V_12 ) ;
F_74 ( V_1 -> V_90 ) ;
return V_20 ;
V_94:
F_19 ( & V_1 -> V_12 ) ;
F_72 ( V_24 ) ;
V_93:
F_33 ( V_2 ) ;
return V_92 ;
}
static T_1 F_81 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_20 )
{
int V_22 ;
unsigned short V_95 ;
struct V_1 * V_1 ;
struct V_96 * V_97 ;
V_1 = F_2 ( V_4 ) ;
V_97 = F_82 ( V_1 -> V_90 , 0 ) ;
if ( ! V_97 )
return - V_72 ;
if ( V_97 -> V_98 ) {
V_22 = - V_28 ;
goto V_25;
}
V_22 = F_83 ( V_8 , 10 , & V_95 ) ;
if ( V_22 )
goto V_25;
if ( ! V_95 ) {
V_22 = - V_23 ;
goto V_25;
}
F_84 ( V_97 ) ;
F_85 ( V_97 ) ;
F_71 ( V_1 , true ) ;
return V_20 ;
V_25:
F_85 ( V_97 ) ;
return V_22 ;
}
static void F_86 ( struct V_1 * V_1 , struct V_40 * V_40 )
{
int V_56 ;
T_2 V_29 ;
struct V_37 V_38 ;
struct V_99 V_100 ;
V_29 = V_40 -> V_44 . V_45 >> V_101 ;
V_56 = ( V_40 -> V_44 . V_45 &
( V_102 - 1 ) ) << V_49 ;
if ( F_32 ( V_40 -> V_103 & V_104 ) ) {
F_70 ( V_1 , V_29 , V_56 , V_40 ) ;
F_87 ( V_40 , 0 ) ;
return;
}
F_88 (bvec, bio, iter) {
int V_105 = V_9 - V_56 ;
if ( V_38 . V_39 > V_105 ) {
struct V_37 V_106 ;
V_106 . V_60 = V_38 . V_60 ;
V_106 . V_39 = V_105 ;
V_106 . V_62 = V_38 . V_62 ;
if ( F_68 ( V_1 , & V_106 , V_29 , V_56 , V_40 ) < 0 )
goto V_25;
V_106 . V_39 = V_38 . V_39 - V_105 ;
V_106 . V_62 += V_105 ;
if ( F_68 ( V_1 , & V_106 , V_29 + 1 , 0 , V_40 ) < 0 )
goto V_25;
} else
if ( F_68 ( V_1 , & V_38 , V_29 , V_56 , V_40 ) < 0 )
goto V_25;
F_42 ( & V_29 , & V_56 , & V_38 ) ;
}
F_89 ( V_107 , & V_40 -> V_108 ) ;
F_87 ( V_40 , 0 ) ;
return;
V_25:
F_90 ( V_40 ) ;
}
static void F_91 ( struct V_109 * V_110 , struct V_40 * V_40 )
{
struct V_1 * V_1 = V_110 -> V_111 ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_32 ( ! F_1 ( V_1 ) ) )
goto error;
if ( ! F_31 ( V_1 , V_40 ) ) {
F_63 ( & V_1 -> V_14 . V_112 ) ;
goto error;
}
F_86 ( V_1 , V_40 ) ;
F_8 ( & V_1 -> V_12 ) ;
return;
error:
F_8 ( & V_1 -> V_12 ) ;
F_90 ( V_40 ) ;
}
static void F_92 ( struct V_96 * V_97 ,
unsigned long V_29 )
{
struct V_1 * V_1 ;
struct V_17 * V_2 ;
V_1 = V_97 -> V_113 -> V_5 ;
V_2 = V_1 -> V_2 ;
F_54 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_49 ( V_1 , V_29 ) ;
F_55 ( V_69 , & V_2 -> V_32 [ V_29 ] . V_33 ) ;
F_63 ( & V_1 -> V_14 . V_114 ) ;
}
static int F_93 ( struct V_1 * V_1 , int V_115 )
{
int V_22 = - V_72 ;
F_94 ( & V_1 -> V_12 ) ;
V_1 -> V_110 = F_95 ( V_51 ) ;
if ( ! V_1 -> V_110 ) {
F_40 ( L_14 ,
V_115 ) ;
goto V_25;
}
F_96 ( V_1 -> V_110 , F_91 ) ;
V_1 -> V_110 -> V_111 = V_1 ;
V_1 -> V_90 = F_97 ( 1 ) ;
if ( ! V_1 -> V_90 ) {
F_98 ( L_15 ,
V_115 ) ;
goto V_116;
}
V_1 -> V_90 -> V_117 = V_118 ;
V_1 -> V_90 -> V_119 = V_115 ;
V_1 -> V_90 -> V_120 = & V_121 ;
V_1 -> V_90 -> V_110 = V_1 -> V_110 ;
V_1 -> V_90 -> V_5 = V_1 ;
snprintf ( V_1 -> V_90 -> V_122 , 16 , L_16 , V_115 ) ;
F_73 ( V_1 -> V_90 , 0 ) ;
F_99 ( V_123 , V_1 -> V_90 -> V_110 ) ;
F_100 ( V_1 -> V_90 -> V_110 , V_9 ) ;
F_101 ( V_1 -> V_90 -> V_110 ,
V_48 ) ;
F_102 ( V_1 -> V_90 -> V_110 , V_9 ) ;
F_103 ( V_1 -> V_90 -> V_110 , V_9 ) ;
V_1 -> V_90 -> V_110 -> V_124 . V_125 = V_9 ;
V_1 -> V_90 -> V_110 -> V_124 . V_126 = V_127 ;
if ( V_48 == V_9 )
V_1 -> V_90 -> V_110 -> V_124 . V_128 = 1 ;
else
V_1 -> V_90 -> V_110 -> V_124 . V_128 = 0 ;
F_99 ( V_129 , V_1 -> V_90 -> V_110 ) ;
F_104 ( V_1 -> V_90 ) ;
V_22 = F_105 ( & F_106 ( V_1 -> V_90 ) -> V_130 ,
& V_131 ) ;
if ( V_22 < 0 ) {
F_98 ( L_17 ) ;
goto V_132;
}
F_23 ( V_1 -> V_27 , V_133 , sizeof( V_1 -> V_27 ) ) ;
V_1 -> V_2 = NULL ;
V_1 -> V_19 = 1 ;
return 0 ;
V_132:
F_107 ( V_1 -> V_90 ) ;
F_108 ( V_1 -> V_90 ) ;
V_116:
F_109 ( V_1 -> V_110 ) ;
V_25:
return V_22 ;
}
static void F_110 ( struct V_1 * V_1 )
{
F_111 ( & F_106 ( V_1 -> V_90 ) -> V_130 ,
& V_131 ) ;
F_107 ( V_1 -> V_90 ) ;
F_108 ( V_1 -> V_90 ) ;
F_109 ( V_1 -> V_110 ) ;
}
static int T_4 F_112 ( void )
{
int V_22 , V_134 ;
if ( V_135 > V_136 ) {
F_98 ( L_18 ,
V_135 ) ;
V_22 = - V_23 ;
goto V_25;
}
V_118 = F_113 ( 0 , L_19 ) ;
if ( V_118 <= 0 ) {
F_98 ( L_20 ) ;
V_22 = - V_28 ;
goto V_25;
}
V_137 = F_114 ( V_135 * sizeof( struct V_1 ) , V_51 ) ;
if ( ! V_137 ) {
V_22 = - V_72 ;
goto V_138;
}
for ( V_134 = 0 ; V_134 < V_135 ; V_134 ++ ) {
V_22 = F_93 ( & V_137 [ V_134 ] , V_134 ) ;
if ( V_22 )
goto V_139;
}
F_18 ( L_21 , V_135 ) ;
return 0 ;
V_139:
while ( V_134 )
F_110 ( & V_137 [ -- V_134 ] ) ;
F_36 ( V_137 ) ;
V_138:
F_115 ( V_118 , L_19 ) ;
V_25:
return V_22 ;
}
static void T_5 F_116 ( void )
{
int V_140 ;
struct V_1 * V_1 ;
for ( V_140 = 0 ; V_140 < V_135 ; V_140 ++ ) {
V_1 = & V_137 [ V_140 ] ;
F_110 ( V_1 ) ;
F_71 ( V_1 , false ) ;
}
F_115 ( V_118 , L_19 ) ;
F_36 ( V_137 ) ;
F_117 ( L_22 ) ;
}
