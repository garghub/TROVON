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
if ( F_19 ( V_7 -> V_15 . V_16 + F_20 ( V_18 ) <=
V_7 -> V_31 ) )
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
V_11 -> V_34 += F_20 ( V_18 ) ;
if ( F_1 ( V_25 ) )
F_14 ( V_25 , V_11 ) ;
V_11 -> V_21 . V_22 = F_23 ( & V_11 -> V_35 ,
& V_11 -> V_21 ,
F_12 ( V_25 , V_11 , V_7 ) ) ;
if ( F_22 ( & V_11 -> V_21 ) )
F_24 ( & V_11 -> V_21 ) ;
if ( F_1 ( V_25 ) )
F_15 ( V_25 , V_11 ) ;
switch ( F_25 ( & V_11 -> V_35 , & V_11 -> V_21 , V_11 -> V_21 . V_22 + V_22 ) ) {
case V_36 :
break;
case V_37 :
F_26 ( V_7 ) ;
if ( ! F_16 ( V_25 ) || ! F_27 ( V_18 ) ) {
V_11 -> V_38 . V_39 ++ ;
goto V_40;
}
V_11 -> V_38 . V_41 ++ ;
break;
case V_42 :
F_26 ( V_7 ) ;
if ( F_17 ( V_25 ) || ! F_16 ( V_25 ) ||
! F_27 ( V_18 ) ) {
V_11 -> V_38 . V_43 ++ ;
goto V_40;
}
V_11 -> V_38 . V_44 ++ ;
break;
}
if ( F_12 ( V_25 , V_11 , V_7 ) + F_20 ( V_18 ) <= V_11 -> V_31 ) {
V_11 -> V_16 += F_20 ( V_18 ) ;
return F_21 ( V_18 , V_7 ) ;
}
V_11 -> V_38 . V_45 ++ ;
V_32:
return F_28 ( V_18 , V_7 ) ;
V_40:
F_28 ( V_18 , V_7 ) ;
return V_46 ;
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
V_11 -> V_16 -= F_20 ( V_18 ) ;
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
unsigned int V_47 = F_20 ( V_18 ) ;
struct V_10 * V_11 ;
T_1 V_29 = F_13 ( V_18 ) ;
if ( V_29 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_29 ] ) == NULL ) {
F_31 ( L_2 ,
F_13 ( V_18 ) ) ;
} else {
V_11 -> V_16 -= V_47 ;
V_11 -> V_38 . V_48 ++ ;
if ( F_1 ( V_25 ) ) {
if ( ! V_7 -> V_15 . V_16 )
F_32 ( & V_25 -> V_23 ) ;
} else {
if ( ! V_11 -> V_16 )
F_32 ( & V_11 -> V_21 ) ;
}
}
F_28 ( V_18 , V_7 ) ;
return V_47 ;
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
static inline int F_40 ( struct V_6 * V_7 , struct V_49 * V_50 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_51 * V_52 ;
int V_8 ;
if ( V_50 == NULL )
return - V_53 ;
V_52 = F_41 ( V_50 ) ;
if ( V_52 -> V_9 > V_54 || V_52 -> V_9 == 0 || V_52 -> V_55 >= V_52 -> V_9 )
return - V_53 ;
F_42 ( V_7 ) ;
V_2 -> V_9 = V_52 -> V_9 ;
V_2 -> V_30 = V_52 -> V_55 ;
V_2 -> V_26 = V_52 -> V_4 ;
F_43 ( V_7 ) ;
if ( V_52 -> V_56 ) {
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
}
for ( V_8 = V_2 -> V_9 ; V_8 < V_54 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] ) {
F_44 ( L_3 ,
V_8 ) ;
F_38 ( V_2 -> V_12 [ V_8 ] ) ;
V_2 -> V_12 [ V_8 ] = NULL ;
}
}
return 0 ;
}
static inline int F_45 ( struct V_6 * V_7 , int V_29 ,
struct V_57 * V_58 , int V_14 ,
T_2 * V_59 , T_3 V_60 ,
struct V_10 * * V_61 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_12 [ V_29 ] ;
if ( ! V_11 ) {
V_2 -> V_12 [ V_29 ] = V_11 = * V_61 ;
* V_61 = NULL ;
if ( ! V_11 )
return - V_62 ;
}
V_11 -> V_63 = V_29 ;
V_11 -> V_14 = V_14 ;
if ( V_58 -> V_31 > V_7 -> V_31 )
V_11 -> V_31 = V_7 -> V_31 ;
else
V_11 -> V_31 = V_58 -> V_31 ;
if ( V_11 -> V_16 == 0 )
F_24 ( & V_11 -> V_21 ) ;
F_46 ( & V_11 -> V_35 ,
V_58 -> V_64 , V_58 -> V_65 , V_58 -> V_66 , V_58 -> V_67 ,
V_58 -> V_68 , V_59 , V_60 ) ;
F_47 ( & V_11 -> V_21 ) ;
return 0 ;
}
static int F_48 ( struct V_6 * V_7 , struct V_49 * V_69 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_57 * V_58 ;
struct V_49 * V_70 [ V_71 + 1 ] ;
int V_72 , V_14 = V_73 ;
T_2 * V_59 ;
T_3 V_60 ;
struct V_10 * V_61 ;
if ( V_69 == NULL )
return - V_53 ;
V_72 = F_49 ( V_70 , V_71 , V_69 , V_74 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_70 [ V_75 ] == NULL && V_70 [ V_76 ] == NULL ) {
if ( V_70 [ V_77 ] != NULL )
V_7 -> V_31 = F_50 ( V_70 [ V_77 ] ) ;
return F_40 ( V_7 , V_69 ) ;
}
if ( V_70 [ V_75 ] == NULL ||
V_70 [ V_76 ] == NULL ||
V_70 [ V_77 ] != NULL )
return - V_53 ;
V_60 = V_70 [ V_78 ] ? F_50 ( V_70 [ V_78 ] ) : 0 ;
V_72 = - V_53 ;
V_58 = F_41 ( V_70 [ V_75 ] ) ;
V_59 = F_41 ( V_70 [ V_76 ] ) ;
if ( V_58 -> V_63 >= V_2 -> V_9 )
goto V_79;
if ( F_7 ( V_2 ) ) {
if ( V_58 -> V_14 == 0 ) {
int V_80 = V_73 ;
if ( V_2 -> V_12 [ V_2 -> V_30 ] )
V_80 = V_2 -> V_12 [ V_2 -> V_30 ] -> V_14 ;
F_51 ( V_81 L_4
L_5 , V_58 -> V_63 , V_80 ) ;
V_14 = V_80 ;
} else
V_14 = V_58 -> V_14 ;
}
V_61 = F_52 ( sizeof( * V_61 ) , V_82 ) ;
F_42 ( V_7 ) ;
V_72 = F_45 ( V_7 , V_58 -> V_63 , V_58 , V_14 , V_59 , V_60 , & V_61 ) ;
if ( V_72 < 0 )
goto V_83;
if ( F_7 ( V_2 ) ) {
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
}
V_72 = 0 ;
V_83:
F_43 ( V_7 ) ;
F_39 ( V_61 ) ;
V_79:
return V_72 ;
}
static int F_53 ( struct V_6 * V_7 , struct V_49 * V_69 )
{
struct V_49 * V_70 [ V_71 + 1 ] ;
int V_72 ;
if ( V_69 == NULL )
return - V_53 ;
V_72 = F_49 ( V_70 , V_71 , V_69 , V_74 ) ;
if ( V_72 < 0 )
return V_72 ;
if ( V_70 [ V_75 ] || V_70 [ V_76 ] )
return - V_53 ;
if ( V_70 [ V_77 ] )
V_7 -> V_31 = F_50 ( V_70 [ V_77 ] ) ;
else {
T_3 V_84 = F_54 ( V_7 ) -> V_85 ? : 1 ;
V_7 -> V_31 = V_84 * F_55 ( F_54 ( V_7 ) ) ;
}
return F_40 ( V_7 , V_70 [ V_86 ] ) ;
}
static int F_56 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_49 * V_35 , * V_87 = NULL ;
int V_8 ;
T_3 V_88 [ V_54 ] ;
struct V_51 V_52 = {
. V_9 = V_2 -> V_9 ,
. V_55 = V_2 -> V_30 ,
. V_56 = F_7 ( V_2 ) ,
. V_4 = V_2 -> V_26 ,
} ;
V_87 = F_57 ( V_18 , V_89 ) ;
if ( V_87 == NULL )
goto V_90;
if ( F_58 ( V_18 , V_86 , sizeof( V_52 ) , & V_52 ) )
goto V_90;
for ( V_8 = 0 ; V_8 < V_54 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
V_88 [ V_8 ] = V_11 ? V_11 -> V_35 . V_60 : 0 ;
}
if ( F_58 ( V_18 , V_78 , sizeof( V_88 ) , V_88 ) )
goto V_90;
if ( F_59 ( V_18 , V_77 , V_7 -> V_31 ) )
goto V_90;
V_35 = F_57 ( V_18 , V_75 ) ;
if ( V_35 == NULL )
goto V_90;
for ( V_8 = 0 ; V_8 < V_54 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
struct V_57 V_69 ;
unsigned long V_22 ;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
if ( ! V_11 ) {
V_69 . V_63 = V_54 + V_8 ;
goto V_91;
}
V_69 . V_31 = V_11 -> V_31 ;
V_69 . V_63 = V_11 -> V_63 ;
V_69 . V_16 = F_12 ( V_2 , V_11 , V_7 ) ;
V_69 . V_14 = V_11 -> V_14 ;
V_69 . V_64 = V_11 -> V_35 . V_64 >> V_11 -> V_35 . V_66 ;
V_69 . V_65 = V_11 -> V_35 . V_65 >> V_11 -> V_35 . V_66 ;
V_69 . V_66 = V_11 -> V_35 . V_66 ;
V_69 . V_67 = V_11 -> V_35 . V_67 ;
V_69 . V_68 = V_11 -> V_35 . V_68 ;
V_69 . V_48 = V_11 -> V_38 . V_48 ;
V_69 . V_92 = V_11 -> V_38 . V_39 ;
V_69 . V_93 = V_11 -> V_38 . V_43 ;
V_69 . V_45 = V_11 -> V_38 . V_45 ;
V_69 . V_94 = V_11 -> V_33 ;
V_69 . V_34 = V_11 -> V_34 ;
if ( F_1 ( V_2 ) )
F_14 ( V_2 , V_11 ) ;
V_22 = F_23 ( & V_11 -> V_35 , & V_11 -> V_21 ,
V_11 -> V_21 . V_22 >> V_11 -> V_35 . V_66 ) ;
V_69 . V_95 = V_22 >> V_11 -> V_35 . V_66 ;
V_91:
if ( F_60 ( V_18 , sizeof( V_69 ) , & V_69 ) < 0 )
goto V_90;
}
F_61 ( V_18 , V_35 ) ;
return F_61 ( V_18 , V_87 ) ;
V_90:
F_62 ( V_18 , V_87 ) ;
return - V_96 ;
}
static void F_63 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] )
F_38 ( V_2 -> V_12 [ V_8 ] ) ;
}
}
static int T_4 F_64 ( void )
{
return F_65 ( & V_97 ) ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_97 ) ;
}
