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
static inline int F_28 ( struct V_34 * V_35 )
{
return V_35 -> V_36 != V_9 ;
}
static inline int F_29 ( struct V_1 * V_1 , struct V_37 * V_37 )
{
V_13 V_38 , V_39 , V_40 ;
if ( F_30 ( V_37 -> V_41 . V_42 &
( V_43 - 1 ) ) )
return 0 ;
if ( F_30 ( V_37 -> V_41 . V_44 & ( V_45 - 1 ) ) )
return 0 ;
V_38 = V_37 -> V_41 . V_42 ;
V_39 = V_38 + ( V_37 -> V_41 . V_44 >> V_46 ) ;
V_40 = V_1 -> V_10 >> V_46 ;
if ( F_30 ( V_38 >= V_40 || V_39 > V_40 || V_38 > V_39 ) )
return 0 ;
return 1 ;
}
static void F_31 ( struct V_17 * V_2 )
{
F_32 ( V_2 -> V_18 ) ;
F_33 ( V_2 -> V_32 ) ;
F_34 ( V_2 ) ;
}
static struct V_17 * F_35 ( V_13 V_10 )
{
T_3 V_47 ;
struct V_17 * V_2 = F_36 ( sizeof( * V_2 ) , V_48 ) ;
if ( ! V_2 )
goto V_25;
V_47 = V_10 >> V_16 ;
V_2 -> V_32 = F_37 ( V_47 * sizeof( * V_2 -> V_32 ) ) ;
if ( ! V_2 -> V_32 ) {
F_38 ( L_6 ) ;
goto V_49;
}
V_2 -> V_18 = F_39 ( V_50 | V_51 ) ;
if ( ! V_2 -> V_18 ) {
F_38 ( L_7 ) ;
goto V_52;
}
F_40 ( & V_2 -> V_53 ) ;
return V_2 ;
V_52:
F_33 ( V_2 -> V_32 ) ;
V_49:
F_34 ( V_2 ) ;
V_2 = NULL ;
V_25:
return V_2 ;
}
static void F_41 ( T_2 * V_29 , int * V_54 , struct V_34 * V_35 )
{
if ( * V_54 + V_35 -> V_36 >= V_9 )
( * V_29 ) ++ ;
* V_54 = ( * V_54 + V_35 -> V_36 ) % V_9 ;
}
static int F_42 ( void * V_55 )
{
unsigned int V_56 ;
unsigned long * V_57 ;
V_57 = ( unsigned long * ) V_55 ;
for ( V_56 = 0 ; V_56 != V_9 / sizeof( * V_57 ) ; V_56 ++ ) {
if ( V_57 [ V_56 ] )
return 0 ;
}
return 1 ;
}
static void F_43 ( struct V_34 * V_35 )
{
struct V_57 * V_57 = V_35 -> V_58 ;
void * V_59 ;
V_59 = F_44 ( V_57 ) ;
if ( F_28 ( V_35 ) )
memset ( V_59 + V_35 -> V_60 , 0 , V_35 -> V_36 ) ;
else
F_45 ( V_59 ) ;
F_46 ( V_59 ) ;
F_47 ( V_57 ) ;
}
static void F_48 ( struct V_1 * V_1 , T_3 V_29 )
{
struct V_17 * V_2 = V_1 -> V_2 ;
unsigned long V_61 = V_2 -> V_32 [ V_29 ] . V_61 ;
if ( F_30 ( ! V_61 ) ) {
if ( F_24 ( V_2 , V_29 , V_62 ) ) {
F_27 ( V_2 , V_29 , V_62 ) ;
F_49 ( & V_1 -> V_14 . V_63 ) ;
}
return;
}
F_50 ( V_2 -> V_18 , V_61 ) ;
F_51 ( V_2 -> V_32 [ V_29 ] . V_64 , & V_1 -> V_14 . V_65 ) ;
F_49 ( & V_1 -> V_14 . V_15 ) ;
V_2 -> V_32 [ V_29 ] . V_61 = 0 ;
V_2 -> V_32 [ V_29 ] . V_64 = 0 ;
}
static int F_52 ( struct V_1 * V_1 , char * V_66 , T_2 V_29 )
{
int V_22 = 0 ;
unsigned char * V_67 ;
struct V_17 * V_2 = V_1 -> V_2 ;
unsigned long V_61 ;
T_4 V_64 ;
F_53 ( & V_2 -> V_53 ) ;
V_61 = V_2 -> V_32 [ V_29 ] . V_61 ;
V_64 = V_2 -> V_32 [ V_29 ] . V_64 ;
if ( ! V_61 || F_24 ( V_2 , V_29 , V_62 ) ) {
F_54 ( & V_2 -> V_53 ) ;
F_45 ( V_66 ) ;
return 0 ;
}
V_67 = F_55 ( V_2 -> V_18 , V_61 , V_68 ) ;
if ( V_64 == V_9 )
F_56 ( V_66 , V_67 ) ;
else
V_22 = F_57 ( V_1 -> V_24 , V_67 , V_64 , V_66 ) ;
F_58 ( V_2 -> V_18 , V_61 ) ;
F_54 ( & V_2 -> V_53 ) ;
if ( F_30 ( V_22 ) ) {
F_38 ( L_8 , V_22 , V_29 ) ;
F_59 ( & V_1 -> V_14 . V_69 ) ;
return V_22 ;
}
return 0 ;
}
static int F_60 ( struct V_1 * V_1 , struct V_34 * V_35 ,
T_2 V_29 , int V_54 , struct V_37 * V_37 )
{
int V_22 ;
struct V_57 * V_57 ;
unsigned char * V_59 , * V_70 = NULL ;
struct V_17 * V_2 = V_1 -> V_2 ;
V_57 = V_35 -> V_58 ;
F_53 ( & V_2 -> V_53 ) ;
if ( F_30 ( ! V_2 -> V_32 [ V_29 ] . V_61 ) ||
F_24 ( V_2 , V_29 , V_62 ) ) {
F_54 ( & V_2 -> V_53 ) ;
F_43 ( V_35 ) ;
return 0 ;
}
F_54 ( & V_2 -> V_53 ) ;
if ( F_28 ( V_35 ) )
V_70 = F_36 ( V_9 , V_50 ) ;
V_59 = F_44 ( V_57 ) ;
if ( ! F_28 ( V_35 ) )
V_70 = V_59 ;
if ( ! V_70 ) {
F_18 ( L_9 ) ;
V_22 = - V_71 ;
goto V_72;
}
V_22 = F_52 ( V_1 , V_70 , V_29 ) ;
if ( F_30 ( V_22 ) )
goto V_72;
if ( F_28 ( V_35 ) )
memcpy ( V_59 + V_35 -> V_60 , V_70 + V_54 ,
V_35 -> V_36 ) ;
F_47 ( V_57 ) ;
V_22 = 0 ;
V_72:
F_46 ( V_59 ) ;
if ( F_28 ( V_35 ) )
F_34 ( V_70 ) ;
return V_22 ;
}
static int F_61 ( struct V_1 * V_1 , struct V_34 * V_35 , T_2 V_29 ,
int V_54 )
{
int V_22 = 0 ;
T_3 V_73 ;
unsigned long V_61 ;
struct V_57 * V_57 ;
unsigned char * V_59 , * V_67 , * V_74 , * V_70 = NULL ;
struct V_17 * V_2 = V_1 -> V_2 ;
struct V_75 * V_76 ;
bool V_77 = false ;
V_57 = V_35 -> V_58 ;
if ( F_28 ( V_35 ) ) {
V_70 = F_36 ( V_9 , V_50 ) ;
if ( ! V_70 ) {
V_22 = - V_71 ;
goto V_25;
}
V_22 = F_52 ( V_1 , V_70 , V_29 ) ;
if ( V_22 )
goto V_25;
}
V_76 = F_62 ( V_1 -> V_24 ) ;
V_77 = true ;
V_59 = F_44 ( V_57 ) ;
if ( F_28 ( V_35 ) ) {
memcpy ( V_70 + V_54 , V_59 + V_35 -> V_60 ,
V_35 -> V_36 ) ;
F_46 ( V_59 ) ;
V_59 = NULL ;
} else {
V_70 = V_59 ;
}
if ( F_42 ( V_70 ) ) {
F_46 ( V_59 ) ;
F_63 ( & V_1 -> V_2 -> V_53 ) ;
F_48 ( V_1 , V_29 ) ;
F_26 ( V_2 , V_29 , V_62 ) ;
F_64 ( & V_1 -> V_2 -> V_53 ) ;
F_59 ( & V_1 -> V_14 . V_63 ) ;
V_22 = 0 ;
goto V_25;
}
V_22 = F_65 ( V_1 -> V_24 , V_76 , V_70 , & V_73 ) ;
if ( ! F_28 ( V_35 ) ) {
F_46 ( V_59 ) ;
V_59 = NULL ;
V_70 = NULL ;
}
if ( F_30 ( V_22 ) ) {
F_38 ( L_10 , V_22 ) ;
goto V_25;
}
V_74 = V_76 -> V_78 ;
if ( F_30 ( V_73 > V_79 ) ) {
V_73 = V_9 ;
if ( F_28 ( V_35 ) )
V_74 = V_70 ;
}
V_61 = F_66 ( V_2 -> V_18 , V_73 ) ;
if ( ! V_61 ) {
F_18 ( L_11 ,
V_29 , V_73 ) ;
V_22 = - V_71 ;
goto V_25;
}
V_67 = F_55 ( V_2 -> V_18 , V_61 , V_80 ) ;
if ( ( V_73 == V_9 ) && ! F_28 ( V_35 ) ) {
V_74 = F_44 ( V_57 ) ;
F_56 ( V_67 , V_74 ) ;
F_46 ( V_74 ) ;
} else {
memcpy ( V_67 , V_74 , V_73 ) ;
}
F_67 ( V_1 -> V_24 , V_76 ) ;
V_77 = false ;
F_58 ( V_2 -> V_18 , V_61 ) ;
F_63 ( & V_1 -> V_2 -> V_53 ) ;
F_48 ( V_1 , V_29 ) ;
V_2 -> V_32 [ V_29 ] . V_61 = V_61 ;
V_2 -> V_32 [ V_29 ] . V_64 = V_73 ;
F_64 ( & V_1 -> V_2 -> V_53 ) ;
F_68 ( V_73 , & V_1 -> V_14 . V_65 ) ;
F_59 ( & V_1 -> V_14 . V_15 ) ;
V_25:
if ( V_77 )
F_67 ( V_1 -> V_24 , V_76 ) ;
if ( F_28 ( V_35 ) )
F_34 ( V_70 ) ;
if ( V_22 )
F_59 ( & V_1 -> V_14 . V_81 ) ;
return V_22 ;
}
static int F_69 ( struct V_1 * V_1 , struct V_34 * V_35 , T_2 V_29 ,
int V_54 , struct V_37 * V_37 )
{
int V_22 ;
int V_82 = F_70 ( V_37 ) ;
if ( V_82 == V_83 ) {
F_59 ( & V_1 -> V_14 . V_84 ) ;
V_22 = F_60 ( V_1 , V_35 , V_29 , V_54 , V_37 ) ;
} else {
F_59 ( & V_1 -> V_14 . V_85 ) ;
V_22 = F_61 ( V_1 , V_35 , V_29 , V_54 ) ;
}
return V_22 ;
}
static void F_71 ( struct V_1 * V_1 , T_2 V_29 ,
int V_54 , struct V_37 * V_37 )
{
T_3 V_86 = V_37 -> V_41 . V_44 ;
if ( V_54 ) {
if ( V_86 < V_54 )
return;
V_86 -= V_54 ;
V_29 ++ ;
}
while ( V_86 >= V_9 ) {
F_63 ( & V_1 -> V_2 -> V_53 ) ;
F_48 ( V_1 , V_29 ) ;
F_64 ( & V_1 -> V_2 -> V_53 ) ;
V_29 ++ ;
V_86 -= V_9 ;
}
}
static void F_72 ( struct V_1 * V_1 , bool V_87 )
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
unsigned long V_61 = V_2 -> V_32 [ V_29 ] . V_61 ;
if ( ! V_61 )
continue;
F_50 ( V_2 -> V_18 , V_61 ) ;
}
F_73 ( V_1 -> V_24 ) ;
V_1 -> V_19 = 1 ;
F_31 ( V_1 -> V_2 ) ;
V_1 -> V_2 = NULL ;
memset ( & V_1 -> V_14 , 0 , sizeof( V_1 -> V_14 ) ) ;
V_1 -> V_10 = 0 ;
if ( V_87 )
F_74 ( V_1 -> V_88 , 0 ) ;
F_19 ( & V_1 -> V_12 ) ;
}
static T_1 F_75 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_20 )
{
V_13 V_10 ;
struct V_89 * V_24 ;
struct V_17 * V_2 ;
struct V_1 * V_1 = F_2 ( V_4 ) ;
int V_90 ;
V_10 = F_76 ( V_8 , NULL ) ;
if ( ! V_10 )
return - V_23 ;
V_10 = F_77 ( V_10 ) ;
V_2 = F_35 ( V_10 ) ;
if ( ! V_2 )
return - V_71 ;
V_24 = F_78 ( V_1 -> V_27 , V_1 -> V_19 ) ;
if ( F_79 ( V_24 ) ) {
F_18 ( L_12 ,
V_1 -> V_27 ) ;
V_90 = F_80 ( V_24 ) ;
goto V_91;
}
F_16 ( & V_1 -> V_12 ) ;
if ( F_1 ( V_1 ) ) {
F_18 ( L_13 ) ;
V_90 = - V_28 ;
goto V_92;
}
V_1 -> V_2 = V_2 ;
V_1 -> V_24 = V_24 ;
V_1 -> V_10 = V_10 ;
F_74 ( V_1 -> V_88 , V_1 -> V_10 >> V_46 ) ;
F_19 ( & V_1 -> V_12 ) ;
return V_20 ;
V_92:
F_19 ( & V_1 -> V_12 ) ;
F_73 ( V_24 ) ;
V_91:
F_31 ( V_2 ) ;
return V_90 ;
}
static T_1 F_81 ( struct V_3 * V_4 ,
struct V_6 * V_7 , const char * V_8 , T_3 V_20 )
{
int V_22 ;
unsigned short V_93 ;
struct V_1 * V_1 ;
struct V_94 * V_95 ;
V_1 = F_2 ( V_4 ) ;
V_95 = F_82 ( V_1 -> V_88 , 0 ) ;
if ( ! V_95 )
return - V_71 ;
if ( V_95 -> V_96 ) {
V_22 = - V_28 ;
goto V_25;
}
V_22 = F_83 ( V_8 , 10 , & V_93 ) ;
if ( V_22 )
goto V_25;
if ( ! V_93 ) {
V_22 = - V_23 ;
goto V_25;
}
F_84 ( V_95 ) ;
F_85 ( V_95 ) ;
F_72 ( V_1 , true ) ;
return V_20 ;
V_25:
F_85 ( V_95 ) ;
return V_22 ;
}
static void F_86 ( struct V_1 * V_1 , struct V_37 * V_37 )
{
int V_54 ;
T_2 V_29 ;
struct V_34 V_35 ;
struct V_97 V_98 ;
V_29 = V_37 -> V_41 . V_42 >> V_99 ;
V_54 = ( V_37 -> V_41 . V_42 &
( V_100 - 1 ) ) << V_46 ;
if ( F_30 ( V_37 -> V_101 & V_102 ) ) {
F_71 ( V_1 , V_29 , V_54 , V_37 ) ;
F_87 ( V_37 , 0 ) ;
return;
}
F_88 (bvec, bio, iter) {
int V_103 = V_9 - V_54 ;
if ( V_35 . V_36 > V_103 ) {
struct V_34 V_104 ;
V_104 . V_58 = V_35 . V_58 ;
V_104 . V_36 = V_103 ;
V_104 . V_60 = V_35 . V_60 ;
if ( F_69 ( V_1 , & V_104 , V_29 , V_54 , V_37 ) < 0 )
goto V_25;
V_104 . V_36 = V_35 . V_36 - V_103 ;
V_104 . V_60 += V_103 ;
if ( F_69 ( V_1 , & V_104 , V_29 + 1 , 0 , V_37 ) < 0 )
goto V_25;
} else
if ( F_69 ( V_1 , & V_35 , V_29 , V_54 , V_37 ) < 0 )
goto V_25;
F_41 ( & V_29 , & V_54 , & V_35 ) ;
}
F_89 ( V_105 , & V_37 -> V_106 ) ;
F_87 ( V_37 , 0 ) ;
return;
V_25:
F_90 ( V_37 ) ;
}
static void F_91 ( struct V_107 * V_108 , struct V_37 * V_37 )
{
struct V_1 * V_1 = V_108 -> V_109 ;
F_7 ( & V_1 -> V_12 ) ;
if ( F_30 ( ! F_1 ( V_1 ) ) )
goto error;
if ( ! F_29 ( V_1 , V_37 ) ) {
F_59 ( & V_1 -> V_14 . V_110 ) ;
goto error;
}
F_86 ( V_1 , V_37 ) ;
F_8 ( & V_1 -> V_12 ) ;
return;
error:
F_8 ( & V_1 -> V_12 ) ;
F_90 ( V_37 ) ;
}
static void F_92 ( struct V_94 * V_95 ,
unsigned long V_29 )
{
struct V_1 * V_1 ;
struct V_17 * V_2 ;
V_1 = V_95 -> V_111 -> V_5 ;
V_2 = V_1 -> V_2 ;
F_63 ( & V_2 -> V_53 ) ;
F_48 ( V_1 , V_29 ) ;
F_64 ( & V_2 -> V_53 ) ;
F_59 ( & V_1 -> V_14 . V_112 ) ;
}
static int F_93 ( struct V_1 * V_1 , int V_113 )
{
int V_22 = - V_71 ;
F_94 ( & V_1 -> V_12 ) ;
V_1 -> V_108 = F_95 ( V_48 ) ;
if ( ! V_1 -> V_108 ) {
F_38 ( L_14 ,
V_113 ) ;
goto V_25;
}
F_96 ( V_1 -> V_108 , F_91 ) ;
V_1 -> V_108 -> V_109 = V_1 ;
V_1 -> V_88 = F_97 ( 1 ) ;
if ( ! V_1 -> V_88 ) {
F_98 ( L_15 ,
V_113 ) ;
goto V_114;
}
V_1 -> V_88 -> V_115 = V_116 ;
V_1 -> V_88 -> V_117 = V_113 ;
V_1 -> V_88 -> V_118 = & V_119 ;
V_1 -> V_88 -> V_108 = V_1 -> V_108 ;
V_1 -> V_88 -> V_5 = V_1 ;
snprintf ( V_1 -> V_88 -> V_120 , 16 , L_16 , V_113 ) ;
F_74 ( V_1 -> V_88 , 0 ) ;
F_99 ( V_121 , V_1 -> V_88 -> V_108 ) ;
F_100 ( V_1 -> V_88 -> V_108 , V_9 ) ;
F_101 ( V_1 -> V_88 -> V_108 ,
V_45 ) ;
F_102 ( V_1 -> V_88 -> V_108 , V_9 ) ;
F_103 ( V_1 -> V_88 -> V_108 , V_9 ) ;
V_1 -> V_88 -> V_108 -> V_122 . V_123 = V_9 ;
V_1 -> V_88 -> V_108 -> V_122 . V_124 = V_125 ;
if ( V_45 == V_9 )
V_1 -> V_88 -> V_108 -> V_122 . V_126 = 1 ;
else
V_1 -> V_88 -> V_108 -> V_122 . V_126 = 0 ;
F_99 ( V_127 , V_1 -> V_88 -> V_108 ) ;
F_104 ( V_1 -> V_88 ) ;
V_22 = F_105 ( & F_106 ( V_1 -> V_88 ) -> V_128 ,
& V_129 ) ;
if ( V_22 < 0 ) {
F_98 ( L_17 ) ;
goto V_130;
}
F_23 ( V_1 -> V_27 , V_131 , sizeof( V_1 -> V_27 ) ) ;
V_1 -> V_2 = NULL ;
V_1 -> V_19 = 1 ;
return 0 ;
V_130:
F_107 ( V_1 -> V_88 ) ;
F_108 ( V_1 -> V_88 ) ;
V_114:
F_109 ( V_1 -> V_108 ) ;
V_25:
return V_22 ;
}
static void F_110 ( struct V_1 * V_1 )
{
F_111 ( & F_106 ( V_1 -> V_88 ) -> V_128 ,
& V_129 ) ;
F_107 ( V_1 -> V_88 ) ;
F_108 ( V_1 -> V_88 ) ;
F_109 ( V_1 -> V_108 ) ;
}
static int T_5 F_112 ( void )
{
int V_22 , V_132 ;
if ( V_133 > V_134 ) {
F_98 ( L_18 ,
V_133 ) ;
V_22 = - V_23 ;
goto V_25;
}
V_116 = F_113 ( 0 , L_19 ) ;
if ( V_116 <= 0 ) {
F_98 ( L_20 ) ;
V_22 = - V_28 ;
goto V_25;
}
V_135 = F_114 ( V_133 * sizeof( struct V_1 ) , V_48 ) ;
if ( ! V_135 ) {
V_22 = - V_71 ;
goto V_136;
}
for ( V_132 = 0 ; V_132 < V_133 ; V_132 ++ ) {
V_22 = F_93 ( & V_135 [ V_132 ] , V_132 ) ;
if ( V_22 )
goto V_137;
}
F_18 ( L_21 , V_133 ) ;
return 0 ;
V_137:
while ( V_132 )
F_110 ( & V_135 [ -- V_132 ] ) ;
F_34 ( V_135 ) ;
V_136:
F_115 ( V_116 , L_19 ) ;
V_25:
return V_22 ;
}
static void T_6 F_116 ( void )
{
int V_138 ;
struct V_1 * V_1 ;
for ( V_138 = 0 ; V_138 < V_133 ; V_138 ++ ) {
V_1 = & V_135 [ V_138 ] ;
F_110 ( V_1 ) ;
F_72 ( V_1 , false ) ;
}
F_115 ( V_116 , L_19 ) ;
F_34 ( V_135 ) ;
F_117 ( L_22 ) ;
}
