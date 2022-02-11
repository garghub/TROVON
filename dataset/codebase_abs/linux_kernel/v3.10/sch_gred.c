static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 , & V_2 -> V_4 ) ;
}
static inline void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_3 , & V_2 -> V_4 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_6 ( V_3 , & V_2 -> V_4 ) ;
}
static inline int F_7 ( struct V_1 * V_2 )
{
return F_2 ( V_5 , & V_2 -> V_4 ) ;
}
static inline void F_8 ( struct V_1 * V_2 )
{
F_4 ( V_5 , & V_2 -> V_4 ) ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_6 ( V_5 , & V_2 -> V_4 ) ;
}
static inline int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
int V_13 ;
if ( V_11 == NULL )
continue;
for ( V_13 = V_8 + 1 ; V_13 < V_2 -> V_9 ; V_13 ++ )
if ( V_2 -> V_12 [ V_13 ] && V_2 -> V_12 [ V_13 ] -> V_14 == V_11 -> V_14 )
return 1 ;
}
return 0 ;
}
static inline unsigned int F_12 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_6 * V_7 )
{
if ( F_1 ( V_2 ) )
return V_7 -> V_15 . V_16 ;
else
return V_11 -> V_16 ;
}
static inline T_1 F_13 ( struct V_17 * V_18 )
{
return V_18 -> V_19 & V_20 ;
}
static inline void F_14 ( const struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_11 -> V_21 . V_22 = V_2 -> V_23 . V_22 ;
V_11 -> V_21 . V_24 = V_2 -> V_23 . V_24 ;
}
static inline void F_15 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
V_2 -> V_23 . V_22 = V_11 -> V_21 . V_22 ;
V_2 -> V_23 . V_24 = V_11 -> V_21 . V_24 ;
}
static inline int F_16 ( struct V_1 * V_25 )
{
return V_25 -> V_26 & V_27 ;
}
static inline int F_17 ( struct V_1 * V_25 )
{
return V_25 -> V_26 & V_28 ;
}
static int F_18 ( struct V_17 * V_18 , struct V_6 * V_7 )
{
struct V_10 * V_11 = NULL ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
unsigned long V_22 = 0 ;
T_1 V_29 = F_13 ( V_18 ) ;
if ( V_29 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_29 ] ) == NULL ) {
V_29 = V_25 -> V_30 ;
V_11 = V_25 -> V_12 [ V_29 ] ;
if ( ! V_11 ) {
if ( F_19 ( & V_7 -> V_11 ) < F_20 ( V_7 ) -> V_31 )
return F_21 ( V_18 , V_7 ) ;
else
goto V_32;
}
V_18 -> V_19 = ( V_18 -> V_19 & ~ V_20 ) | V_29 ;
}
if ( ! F_1 ( V_25 ) && F_7 ( V_25 ) ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_25 -> V_9 ; V_8 ++ ) {
if ( V_25 -> V_12 [ V_8 ] && V_25 -> V_12 [ V_8 ] -> V_14 < V_11 -> V_14 &&
! F_22 ( & V_25 -> V_12 [ V_8 ] -> V_21 ) )
V_22 += V_25 -> V_12 [ V_8 ] -> V_21 . V_22 ;
}
}
V_11 -> V_33 ++ ;
V_11 -> V_34 += F_23 ( V_18 ) ;
if ( F_1 ( V_25 ) )
F_14 ( V_25 , V_11 ) ;
V_11 -> V_21 . V_22 = F_24 ( & V_11 -> V_35 ,
& V_11 -> V_21 ,
F_12 ( V_25 , V_11 , V_7 ) ) ;
if ( F_22 ( & V_11 -> V_21 ) )
F_25 ( & V_11 -> V_21 ) ;
if ( F_1 ( V_25 ) )
F_15 ( V_25 , V_11 ) ;
switch ( F_26 ( & V_11 -> V_35 , & V_11 -> V_21 , V_11 -> V_21 . V_22 + V_22 ) ) {
case V_36 :
break;
case V_37 :
V_7 -> V_15 . V_38 ++ ;
if ( ! F_16 ( V_25 ) || ! F_27 ( V_18 ) ) {
V_11 -> V_39 . V_40 ++ ;
goto V_41;
}
V_11 -> V_39 . V_42 ++ ;
break;
case V_43 :
V_7 -> V_15 . V_38 ++ ;
if ( F_17 ( V_25 ) || ! F_16 ( V_25 ) ||
! F_27 ( V_18 ) ) {
V_11 -> V_39 . V_44 ++ ;
goto V_41;
}
V_11 -> V_39 . V_45 ++ ;
break;
}
if ( V_11 -> V_16 + F_23 ( V_18 ) <= V_11 -> V_46 ) {
V_11 -> V_16 += F_23 ( V_18 ) ;
return F_21 ( V_18 , V_7 ) ;
}
V_11 -> V_39 . V_47 ++ ;
V_32:
return F_28 ( V_18 , V_7 ) ;
V_41:
F_28 ( V_18 , V_7 ) ;
return V_48 ;
}
static struct V_17 * F_29 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
V_18 = F_30 ( V_7 ) ;
if ( V_18 ) {
struct V_10 * V_11 ;
T_1 V_29 = F_13 ( V_18 ) ;
if ( V_29 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_29 ] ) == NULL ) {
F_31 ( L_1 ,
F_13 ( V_18 ) ) ;
} else {
V_11 -> V_16 -= F_23 ( V_18 ) ;
if ( F_1 ( V_25 ) ) {
if ( ! V_7 -> V_15 . V_16 )
F_32 ( & V_25 -> V_23 ) ;
} else {
if ( ! V_11 -> V_16 )
F_32 ( & V_11 -> V_21 ) ;
}
}
return V_18 ;
}
return NULL ;
}
static unsigned int F_33 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
V_18 = F_34 ( V_7 ) ;
if ( V_18 ) {
unsigned int V_49 = F_23 ( V_18 ) ;
struct V_10 * V_11 ;
T_1 V_29 = F_13 ( V_18 ) ;
if ( V_29 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_29 ] ) == NULL ) {
F_31 ( L_2 ,
F_13 ( V_18 ) ) ;
} else {
V_11 -> V_16 -= V_49 ;
V_11 -> V_39 . V_50 ++ ;
if ( F_1 ( V_25 ) ) {
if ( ! V_7 -> V_15 . V_16 )
F_32 ( & V_25 -> V_23 ) ;
} else {
if ( ! V_11 -> V_16 )
F_32 ( & V_11 -> V_21 ) ;
}
}
F_28 ( V_18 , V_7 ) ;
return V_49 ;
}
return 0 ;
}
static void F_35 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
F_36 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < V_25 -> V_9 ; V_8 ++ ) {
struct V_10 * V_11 = V_25 -> V_12 [ V_8 ] ;
if ( ! V_11 )
continue;
F_37 ( & V_11 -> V_21 ) ;
V_11 -> V_16 = 0 ;
}
}
static inline void F_38 ( struct V_10 * V_11 )
{
F_39 ( V_11 ) ;
}
static inline int F_40 ( struct V_6 * V_7 , struct V_51 * V_52 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_53 * V_54 ;
int V_8 ;
if ( V_52 == NULL )
return - V_55 ;
V_54 = F_41 ( V_52 ) ;
if ( V_54 -> V_9 > V_56 || V_54 -> V_9 == 0 || V_54 -> V_57 >= V_54 -> V_9 )
return - V_55 ;
F_42 ( V_7 ) ;
V_2 -> V_9 = V_54 -> V_9 ;
V_2 -> V_30 = V_54 -> V_57 ;
V_2 -> V_26 = V_54 -> V_4 ;
F_43 ( V_7 ) ;
if ( V_54 -> V_58 ) {
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
}
for ( V_8 = V_2 -> V_9 ; V_8 < V_56 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] ) {
F_44 ( L_3
L_4 , V_8 ) ;
F_38 ( V_2 -> V_12 [ V_8 ] ) ;
V_2 -> V_12 [ V_8 ] = NULL ;
}
}
return 0 ;
}
static inline int F_45 ( struct V_6 * V_7 , int V_29 ,
struct V_59 * V_60 , int V_14 ,
T_2 * V_61 , T_3 V_62 ,
struct V_10 * * V_63 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_12 [ V_29 ] ;
if ( ! V_11 ) {
V_2 -> V_12 [ V_29 ] = V_11 = * V_63 ;
* V_63 = NULL ;
if ( ! V_11 )
return - V_64 ;
}
V_11 -> V_65 = V_29 ;
V_11 -> V_14 = V_14 ;
V_11 -> V_46 = V_60 -> V_46 ;
if ( V_11 -> V_16 == 0 )
F_25 ( & V_11 -> V_21 ) ;
F_46 ( & V_11 -> V_35 ,
V_60 -> V_66 , V_60 -> V_67 , V_60 -> V_68 , V_60 -> V_69 ,
V_60 -> V_70 , V_61 , V_62 ) ;
F_47 ( & V_11 -> V_21 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_51 * V_71 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_59 * V_60 ;
struct V_51 * V_72 [ V_73 + 1 ] ;
int V_74 , V_14 = V_75 ;
T_2 * V_61 ;
T_3 V_62 ;
struct V_10 * V_63 ;
if ( V_71 == NULL )
return - V_55 ;
V_74 = F_49 ( V_72 , V_73 , V_71 , V_76 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_72 [ V_77 ] == NULL && V_72 [ V_78 ] == NULL )
return F_40 ( V_7 , V_71 ) ;
if ( V_72 [ V_77 ] == NULL ||
V_72 [ V_78 ] == NULL )
return - V_55 ;
V_62 = V_72 [ V_79 ] ? F_50 ( V_72 [ V_79 ] ) : 0 ;
V_74 = - V_55 ;
V_60 = F_41 ( V_72 [ V_77 ] ) ;
V_61 = F_41 ( V_72 [ V_78 ] ) ;
if ( V_60 -> V_65 >= V_2 -> V_9 )
goto V_80;
if ( F_7 ( V_2 ) ) {
if ( V_60 -> V_14 == 0 ) {
int V_81 = V_75 ;
if ( V_2 -> V_12 [ V_2 -> V_30 ] )
V_81 = V_2 -> V_12 [ V_2 -> V_30 ] -> V_14 ;
F_51 ( V_82 L_5
L_6 , V_60 -> V_65 , V_81 ) ;
V_14 = V_81 ;
} else
V_14 = V_60 -> V_14 ;
}
V_63 = F_52 ( sizeof( * V_63 ) , V_83 ) ;
F_42 ( V_7 ) ;
V_74 = F_45 ( V_7 , V_60 -> V_65 , V_60 , V_14 , V_61 , V_62 , & V_63 ) ;
if ( V_74 < 0 )
goto V_84;
if ( F_7 ( V_2 ) ) {
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
}
V_74 = 0 ;
V_84:
F_43 ( V_7 ) ;
F_39 ( V_63 ) ;
V_80:
return V_74 ;
}
static int F_53 ( struct V_6 * V_7 , struct V_51 * V_71 )
{
struct V_51 * V_72 [ V_73 + 1 ] ;
int V_74 ;
if ( V_71 == NULL )
return - V_55 ;
V_74 = F_49 ( V_72 , V_73 , V_71 , V_76 ) ;
if ( V_74 < 0 )
return V_74 ;
if ( V_72 [ V_77 ] || V_72 [ V_78 ] )
return - V_55 ;
return F_40 ( V_7 , V_72 [ V_85 ] ) ;
}
static int F_54 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_51 * V_35 , * V_86 = NULL ;
int V_8 ;
T_3 V_87 [ V_56 ] ;
struct V_53 V_54 = {
. V_9 = V_2 -> V_9 ,
. V_57 = V_2 -> V_30 ,
. V_58 = F_7 ( V_2 ) ,
. V_4 = V_2 -> V_26 ,
} ;
V_86 = F_55 ( V_18 , V_88 ) ;
if ( V_86 == NULL )
goto V_89;
if ( F_56 ( V_18 , V_85 , sizeof( V_54 ) , & V_54 ) )
goto V_89;
for ( V_8 = 0 ; V_8 < V_56 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
V_87 [ V_8 ] = V_11 ? V_11 -> V_35 . V_62 : 0 ;
}
if ( F_56 ( V_18 , V_79 , sizeof( V_87 ) , V_87 ) )
goto V_89;
V_35 = F_55 ( V_18 , V_77 ) ;
if ( V_35 == NULL )
goto V_89;
for ( V_8 = 0 ; V_8 < V_56 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
struct V_59 V_71 ;
unsigned long V_22 ;
memset ( & V_71 , 0 , sizeof( V_71 ) ) ;
if ( ! V_11 ) {
V_71 . V_65 = V_56 + V_8 ;
goto V_90;
}
V_71 . V_46 = V_11 -> V_46 ;
V_71 . V_65 = V_11 -> V_65 ;
V_71 . V_16 = V_11 -> V_16 ;
V_71 . V_14 = V_11 -> V_14 ;
V_71 . V_66 = V_11 -> V_35 . V_66 >> V_11 -> V_35 . V_68 ;
V_71 . V_67 = V_11 -> V_35 . V_67 >> V_11 -> V_35 . V_68 ;
V_71 . V_68 = V_11 -> V_35 . V_68 ;
V_71 . V_69 = V_11 -> V_35 . V_69 ;
V_71 . V_70 = V_11 -> V_35 . V_70 ;
V_71 . V_50 = V_11 -> V_39 . V_50 ;
V_71 . V_91 = V_11 -> V_39 . V_40 ;
V_71 . V_92 = V_11 -> V_39 . V_44 ;
V_71 . V_47 = V_11 -> V_39 . V_47 ;
V_71 . V_93 = V_11 -> V_33 ;
V_71 . V_34 = V_11 -> V_34 ;
if ( F_1 ( V_2 ) )
F_14 ( V_2 , V_11 ) ;
V_22 = F_24 ( & V_11 -> V_35 , & V_11 -> V_21 ,
V_11 -> V_21 . V_22 >> V_11 -> V_35 . V_68 ) ;
V_71 . V_94 = V_22 >> V_11 -> V_35 . V_68 ;
V_90:
if ( F_57 ( V_18 , sizeof( V_71 ) , & V_71 ) < 0 )
goto V_89;
}
F_58 ( V_18 , V_35 ) ;
return F_58 ( V_18 , V_86 ) ;
V_89:
F_59 ( V_18 , V_86 ) ;
return - V_95 ;
}
static void F_60 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] )
F_38 ( V_2 -> V_12 [ V_8 ] ) ;
}
}
static int T_4 F_61 ( void )
{
return F_62 ( & V_96 ) ;
}
static void T_5 F_63 ( void )
{
F_64 ( & V_96 ) ;
}
