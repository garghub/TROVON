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
F_27 ( V_7 ) ;
if ( ! F_16 ( V_25 ) || ! F_28 ( V_18 ) ) {
V_11 -> V_38 . V_39 ++ ;
goto V_40;
}
V_11 -> V_38 . V_41 ++ ;
break;
case V_42 :
F_27 ( V_7 ) ;
if ( F_17 ( V_25 ) || ! F_16 ( V_25 ) ||
! F_28 ( V_18 ) ) {
V_11 -> V_38 . V_43 ++ ;
goto V_40;
}
V_11 -> V_38 . V_44 ++ ;
break;
}
if ( V_11 -> V_16 + F_23 ( V_18 ) <= V_11 -> V_45 ) {
V_11 -> V_16 += F_23 ( V_18 ) ;
return F_21 ( V_18 , V_7 ) ;
}
V_11 -> V_38 . V_46 ++ ;
V_32:
return F_29 ( V_18 , V_7 ) ;
V_40:
F_29 ( V_18 , V_7 ) ;
return V_47 ;
}
static struct V_17 * F_30 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
V_18 = F_31 ( V_7 ) ;
if ( V_18 ) {
struct V_10 * V_11 ;
T_1 V_29 = F_13 ( V_18 ) ;
if ( V_29 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_29 ] ) == NULL ) {
F_32 ( L_1 ,
F_13 ( V_18 ) ) ;
} else {
V_11 -> V_16 -= F_23 ( V_18 ) ;
if ( F_1 ( V_25 ) ) {
if ( ! V_7 -> V_15 . V_16 )
F_33 ( & V_25 -> V_23 ) ;
} else {
if ( ! V_11 -> V_16 )
F_33 ( & V_11 -> V_21 ) ;
}
}
return V_18 ;
}
return NULL ;
}
static unsigned int F_34 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
V_18 = F_35 ( V_7 ) ;
if ( V_18 ) {
unsigned int V_48 = F_23 ( V_18 ) ;
struct V_10 * V_11 ;
T_1 V_29 = F_13 ( V_18 ) ;
if ( V_29 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_29 ] ) == NULL ) {
F_32 ( L_2 ,
F_13 ( V_18 ) ) ;
} else {
V_11 -> V_16 -= V_48 ;
V_11 -> V_38 . V_49 ++ ;
if ( F_1 ( V_25 ) ) {
if ( ! V_7 -> V_15 . V_16 )
F_33 ( & V_25 -> V_23 ) ;
} else {
if ( ! V_11 -> V_16 )
F_33 ( & V_11 -> V_21 ) ;
}
}
F_29 ( V_18 , V_7 ) ;
return V_48 ;
}
return 0 ;
}
static void F_36 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
F_37 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < V_25 -> V_9 ; V_8 ++ ) {
struct V_10 * V_11 = V_25 -> V_12 [ V_8 ] ;
if ( ! V_11 )
continue;
F_38 ( & V_11 -> V_21 ) ;
V_11 -> V_16 = 0 ;
}
}
static inline void F_39 ( struct V_10 * V_11 )
{
F_40 ( V_11 ) ;
}
static inline int F_41 ( struct V_6 * V_7 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_52 * V_53 ;
int V_8 ;
if ( V_51 == NULL )
return - V_54 ;
V_53 = F_42 ( V_51 ) ;
if ( V_53 -> V_9 > V_55 || V_53 -> V_9 == 0 || V_53 -> V_56 >= V_53 -> V_9 )
return - V_54 ;
F_43 ( V_7 ) ;
V_2 -> V_9 = V_53 -> V_9 ;
V_2 -> V_30 = V_53 -> V_56 ;
V_2 -> V_26 = V_53 -> V_4 ;
F_44 ( V_7 ) ;
if ( V_53 -> V_57 ) {
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
}
for ( V_8 = V_2 -> V_9 ; V_8 < V_55 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] ) {
F_45 ( L_3 ,
V_8 ) ;
F_39 ( V_2 -> V_12 [ V_8 ] ) ;
V_2 -> V_12 [ V_8 ] = NULL ;
}
}
return 0 ;
}
static inline int F_46 ( struct V_6 * V_7 , int V_29 ,
struct V_58 * V_59 , int V_14 ,
T_2 * V_60 , T_3 V_61 ,
struct V_10 * * V_62 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_12 [ V_29 ] ;
if ( ! V_11 ) {
V_2 -> V_12 [ V_29 ] = V_11 = * V_62 ;
* V_62 = NULL ;
if ( ! V_11 )
return - V_63 ;
}
V_11 -> V_64 = V_29 ;
V_11 -> V_14 = V_14 ;
V_11 -> V_45 = V_59 -> V_45 ;
if ( V_11 -> V_16 == 0 )
F_25 ( & V_11 -> V_21 ) ;
F_47 ( & V_11 -> V_35 ,
V_59 -> V_65 , V_59 -> V_66 , V_59 -> V_67 , V_59 -> V_68 ,
V_59 -> V_69 , V_60 , V_61 ) ;
F_48 ( & V_11 -> V_21 ) ;
return 0 ;
}
static int F_49 ( struct V_6 * V_7 , struct V_50 * V_70 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_58 * V_59 ;
struct V_50 * V_71 [ V_72 + 1 ] ;
int V_73 , V_14 = V_74 ;
T_2 * V_60 ;
T_3 V_61 ;
struct V_10 * V_62 ;
if ( V_70 == NULL )
return - V_54 ;
V_73 = F_50 ( V_71 , V_72 , V_70 , V_75 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_71 [ V_76 ] == NULL && V_71 [ V_77 ] == NULL )
return F_41 ( V_7 , V_70 ) ;
if ( V_71 [ V_76 ] == NULL ||
V_71 [ V_77 ] == NULL )
return - V_54 ;
V_61 = V_71 [ V_78 ] ? F_51 ( V_71 [ V_78 ] ) : 0 ;
V_73 = - V_54 ;
V_59 = F_42 ( V_71 [ V_76 ] ) ;
V_60 = F_42 ( V_71 [ V_77 ] ) ;
if ( V_59 -> V_64 >= V_2 -> V_9 )
goto V_79;
if ( F_7 ( V_2 ) ) {
if ( V_59 -> V_14 == 0 ) {
int V_80 = V_74 ;
if ( V_2 -> V_12 [ V_2 -> V_30 ] )
V_80 = V_2 -> V_12 [ V_2 -> V_30 ] -> V_14 ;
F_52 ( V_81 L_4
L_5 , V_59 -> V_64 , V_80 ) ;
V_14 = V_80 ;
} else
V_14 = V_59 -> V_14 ;
}
V_62 = F_53 ( sizeof( * V_62 ) , V_82 ) ;
F_43 ( V_7 ) ;
V_73 = F_46 ( V_7 , V_59 -> V_64 , V_59 , V_14 , V_60 , V_61 , & V_62 ) ;
if ( V_73 < 0 )
goto V_83;
if ( F_7 ( V_2 ) ) {
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
}
V_73 = 0 ;
V_83:
F_44 ( V_7 ) ;
F_40 ( V_62 ) ;
V_79:
return V_73 ;
}
static int F_54 ( struct V_6 * V_7 , struct V_50 * V_70 )
{
struct V_50 * V_71 [ V_72 + 1 ] ;
int V_73 ;
if ( V_70 == NULL )
return - V_54 ;
V_73 = F_50 ( V_71 , V_72 , V_70 , V_75 ) ;
if ( V_73 < 0 )
return V_73 ;
if ( V_71 [ V_76 ] || V_71 [ V_77 ] )
return - V_54 ;
return F_41 ( V_7 , V_71 [ V_84 ] ) ;
}
static int F_55 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_50 * V_35 , * V_85 = NULL ;
int V_8 ;
T_3 V_86 [ V_55 ] ;
struct V_52 V_53 = {
. V_9 = V_2 -> V_9 ,
. V_56 = V_2 -> V_30 ,
. V_57 = F_7 ( V_2 ) ,
. V_4 = V_2 -> V_26 ,
} ;
V_85 = F_56 ( V_18 , V_87 ) ;
if ( V_85 == NULL )
goto V_88;
if ( F_57 ( V_18 , V_84 , sizeof( V_53 ) , & V_53 ) )
goto V_88;
for ( V_8 = 0 ; V_8 < V_55 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
V_86 [ V_8 ] = V_11 ? V_11 -> V_35 . V_61 : 0 ;
}
if ( F_57 ( V_18 , V_78 , sizeof( V_86 ) , V_86 ) )
goto V_88;
V_35 = F_56 ( V_18 , V_76 ) ;
if ( V_35 == NULL )
goto V_88;
for ( V_8 = 0 ; V_8 < V_55 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
struct V_58 V_70 ;
unsigned long V_22 ;
memset ( & V_70 , 0 , sizeof( V_70 ) ) ;
if ( ! V_11 ) {
V_70 . V_64 = V_55 + V_8 ;
goto V_89;
}
V_70 . V_45 = V_11 -> V_45 ;
V_70 . V_64 = V_11 -> V_64 ;
V_70 . V_16 = V_11 -> V_16 ;
V_70 . V_14 = V_11 -> V_14 ;
V_70 . V_65 = V_11 -> V_35 . V_65 >> V_11 -> V_35 . V_67 ;
V_70 . V_66 = V_11 -> V_35 . V_66 >> V_11 -> V_35 . V_67 ;
V_70 . V_67 = V_11 -> V_35 . V_67 ;
V_70 . V_68 = V_11 -> V_35 . V_68 ;
V_70 . V_69 = V_11 -> V_35 . V_69 ;
V_70 . V_49 = V_11 -> V_38 . V_49 ;
V_70 . V_90 = V_11 -> V_38 . V_39 ;
V_70 . V_91 = V_11 -> V_38 . V_43 ;
V_70 . V_46 = V_11 -> V_38 . V_46 ;
V_70 . V_92 = V_11 -> V_33 ;
V_70 . V_34 = V_11 -> V_34 ;
if ( F_1 ( V_2 ) )
F_14 ( V_2 , V_11 ) ;
V_22 = F_24 ( & V_11 -> V_35 , & V_11 -> V_21 ,
V_11 -> V_21 . V_22 >> V_11 -> V_35 . V_67 ) ;
V_70 . V_93 = V_22 >> V_11 -> V_35 . V_67 ;
V_89:
if ( F_58 ( V_18 , sizeof( V_70 ) , & V_70 ) < 0 )
goto V_88;
}
F_59 ( V_18 , V_35 ) ;
return F_59 ( V_18 , V_85 ) ;
V_88:
F_60 ( V_18 , V_85 ) ;
return - V_94 ;
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] )
F_39 ( V_2 -> V_12 [ V_8 ] ) ;
}
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_95 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_95 ) ;
}
