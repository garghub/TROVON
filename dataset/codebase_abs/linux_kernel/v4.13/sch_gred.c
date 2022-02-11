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
static int F_18 ( struct V_17 * V_18 , struct V_6 * V_7 ,
struct V_17 * * V_29 )
{
struct V_10 * V_11 = NULL ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
unsigned long V_22 = 0 ;
T_1 V_30 = F_13 ( V_18 ) ;
if ( V_30 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_30 ] ) == NULL ) {
V_30 = V_25 -> V_31 ;
V_11 = V_25 -> V_12 [ V_30 ] ;
if ( ! V_11 ) {
if ( F_19 ( V_7 -> V_15 . V_16 + F_20 ( V_18 ) <=
V_7 -> V_32 ) )
return F_21 ( V_18 , V_7 ) ;
else
goto V_33;
}
V_18 -> V_19 = ( V_18 -> V_19 & ~ V_20 ) | V_30 ;
}
if ( ! F_1 ( V_25 ) && F_7 ( V_25 ) ) {
int V_8 ;
for ( V_8 = 0 ; V_8 < V_25 -> V_9 ; V_8 ++ ) {
if ( V_25 -> V_12 [ V_8 ] && V_25 -> V_12 [ V_8 ] -> V_14 < V_11 -> V_14 &&
! F_22 ( & V_25 -> V_12 [ V_8 ] -> V_21 ) )
V_22 += V_25 -> V_12 [ V_8 ] -> V_21 . V_22 ;
}
}
V_11 -> V_34 ++ ;
V_11 -> V_35 += F_20 ( V_18 ) ;
if ( F_1 ( V_25 ) )
F_14 ( V_25 , V_11 ) ;
V_11 -> V_21 . V_22 = F_23 ( & V_11 -> V_36 ,
& V_11 -> V_21 ,
F_12 ( V_25 , V_11 , V_7 ) ) ;
if ( F_22 ( & V_11 -> V_21 ) )
F_24 ( & V_11 -> V_21 ) ;
if ( F_1 ( V_25 ) )
F_15 ( V_25 , V_11 ) ;
switch ( F_25 ( & V_11 -> V_36 , & V_11 -> V_21 , V_11 -> V_21 . V_22 + V_22 ) ) {
case V_37 :
break;
case V_38 :
F_26 ( V_7 ) ;
if ( ! F_16 ( V_25 ) || ! F_27 ( V_18 ) ) {
V_11 -> V_39 . V_40 ++ ;
goto V_41;
}
V_11 -> V_39 . V_42 ++ ;
break;
case V_43 :
F_26 ( V_7 ) ;
if ( F_17 ( V_25 ) || ! F_16 ( V_25 ) ||
! F_27 ( V_18 ) ) {
V_11 -> V_39 . V_44 ++ ;
goto V_41;
}
V_11 -> V_39 . V_45 ++ ;
break;
}
if ( F_12 ( V_25 , V_11 , V_7 ) + F_20 ( V_18 ) <= V_11 -> V_32 ) {
V_11 -> V_16 += F_20 ( V_18 ) ;
return F_21 ( V_18 , V_7 ) ;
}
V_11 -> V_39 . V_46 ++ ;
V_33:
return F_28 ( V_18 , V_7 , V_29 ) ;
V_41:
F_28 ( V_18 , V_7 , V_29 ) ;
return V_47 ;
}
static struct V_17 * F_29 ( struct V_6 * V_7 )
{
struct V_17 * V_18 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
V_18 = F_30 ( V_7 ) ;
if ( V_18 ) {
struct V_10 * V_11 ;
T_1 V_30 = F_13 ( V_18 ) ;
if ( V_30 >= V_25 -> V_9 || ( V_11 = V_25 -> V_12 [ V_30 ] ) == NULL ) {
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
static void F_33 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_1 * V_25 = F_11 ( V_7 ) ;
F_34 ( V_7 ) ;
for ( V_8 = 0 ; V_8 < V_25 -> V_9 ; V_8 ++ ) {
struct V_10 * V_11 = V_25 -> V_12 [ V_8 ] ;
if ( ! V_11 )
continue;
F_35 ( & V_11 -> V_21 ) ;
V_11 -> V_16 = 0 ;
}
}
static inline void F_36 ( struct V_10 * V_11 )
{
F_37 ( V_11 ) ;
}
static inline int F_38 ( struct V_6 * V_7 , struct V_48 * V_49 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_50 * V_51 ;
int V_8 ;
if ( V_49 == NULL )
return - V_52 ;
V_51 = F_39 ( V_49 ) ;
if ( V_51 -> V_9 > V_53 || V_51 -> V_9 == 0 || V_51 -> V_54 >= V_51 -> V_9 )
return - V_52 ;
F_40 ( V_7 ) ;
V_2 -> V_9 = V_51 -> V_9 ;
V_2 -> V_31 = V_51 -> V_54 ;
V_2 -> V_26 = V_51 -> V_4 ;
F_41 ( V_7 ) ;
if ( V_51 -> V_55 ) {
F_8 ( V_2 ) ;
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
} else {
F_9 ( V_2 ) ;
F_5 ( V_2 ) ;
}
for ( V_8 = V_2 -> V_9 ; V_8 < V_53 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] ) {
F_42 ( L_2 ,
V_8 ) ;
F_36 ( V_2 -> V_12 [ V_8 ] ) ;
V_2 -> V_12 [ V_8 ] = NULL ;
}
}
return 0 ;
}
static inline int F_43 ( struct V_6 * V_7 , int V_30 ,
struct V_56 * V_57 , int V_14 ,
T_2 * V_58 , T_3 V_59 ,
struct V_10 * * V_60 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_10 * V_11 = V_2 -> V_12 [ V_30 ] ;
if ( ! V_11 ) {
V_2 -> V_12 [ V_30 ] = V_11 = * V_60 ;
* V_60 = NULL ;
if ( ! V_11 )
return - V_61 ;
}
V_11 -> V_62 = V_30 ;
V_11 -> V_14 = V_14 ;
if ( V_57 -> V_32 > V_7 -> V_32 )
V_11 -> V_32 = V_7 -> V_32 ;
else
V_11 -> V_32 = V_57 -> V_32 ;
if ( V_11 -> V_16 == 0 )
F_24 ( & V_11 -> V_21 ) ;
F_44 ( & V_11 -> V_36 ,
V_57 -> V_63 , V_57 -> V_64 , V_57 -> V_65 , V_57 -> V_66 ,
V_57 -> V_67 , V_58 , V_59 ) ;
F_45 ( & V_11 -> V_21 ) ;
return 0 ;
}
static int F_46 ( struct V_6 * V_7 , struct V_48 * V_68 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_56 * V_57 ;
struct V_48 * V_69 [ V_70 + 1 ] ;
int V_71 , V_14 = V_72 ;
T_2 * V_58 ;
T_3 V_59 ;
struct V_10 * V_60 ;
if ( V_68 == NULL )
return - V_52 ;
V_71 = F_47 ( V_69 , V_70 , V_68 , V_73 , NULL ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_69 [ V_74 ] == NULL && V_69 [ V_75 ] == NULL ) {
if ( V_69 [ V_76 ] != NULL )
V_7 -> V_32 = F_48 ( V_69 [ V_76 ] ) ;
return F_38 ( V_7 , V_68 ) ;
}
if ( V_69 [ V_74 ] == NULL ||
V_69 [ V_75 ] == NULL ||
V_69 [ V_76 ] != NULL )
return - V_52 ;
V_59 = V_69 [ V_77 ] ? F_48 ( V_69 [ V_77 ] ) : 0 ;
V_71 = - V_52 ;
V_57 = F_39 ( V_69 [ V_74 ] ) ;
V_58 = F_39 ( V_69 [ V_75 ] ) ;
if ( V_57 -> V_62 >= V_2 -> V_9 )
goto V_78;
if ( F_7 ( V_2 ) ) {
if ( V_57 -> V_14 == 0 ) {
int V_79 = V_72 ;
if ( V_2 -> V_12 [ V_2 -> V_31 ] )
V_79 = V_2 -> V_12 [ V_2 -> V_31 ] -> V_14 ;
F_49 ( V_80 L_3
L_4 , V_57 -> V_62 , V_79 ) ;
V_14 = V_79 ;
} else
V_14 = V_57 -> V_14 ;
}
V_60 = F_50 ( sizeof( * V_60 ) , V_81 ) ;
F_40 ( V_7 ) ;
V_71 = F_43 ( V_7 , V_57 -> V_62 , V_57 , V_14 , V_58 , V_59 , & V_60 ) ;
if ( V_71 < 0 )
goto V_82;
if ( F_7 ( V_2 ) ) {
F_5 ( V_2 ) ;
if ( F_10 ( V_7 ) )
F_3 ( V_2 ) ;
}
V_71 = 0 ;
V_82:
F_41 ( V_7 ) ;
F_37 ( V_60 ) ;
V_78:
return V_71 ;
}
static int F_51 ( struct V_6 * V_7 , struct V_48 * V_68 )
{
struct V_48 * V_69 [ V_70 + 1 ] ;
int V_71 ;
if ( V_68 == NULL )
return - V_52 ;
V_71 = F_47 ( V_69 , V_70 , V_68 , V_73 , NULL ) ;
if ( V_71 < 0 )
return V_71 ;
if ( V_69 [ V_74 ] || V_69 [ V_75 ] )
return - V_52 ;
if ( V_69 [ V_76 ] )
V_7 -> V_32 = F_48 ( V_69 [ V_76 ] ) ;
else
V_7 -> V_32 = F_52 ( V_7 ) -> V_83
* F_53 ( F_52 ( V_7 ) ) ;
return F_38 ( V_7 , V_69 [ V_84 ] ) ;
}
static int F_54 ( struct V_6 * V_7 , struct V_17 * V_18 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
struct V_48 * V_36 , * V_85 = NULL ;
int V_8 ;
T_3 V_86 [ V_53 ] ;
struct V_50 V_51 = {
. V_9 = V_2 -> V_9 ,
. V_54 = V_2 -> V_31 ,
. V_55 = F_7 ( V_2 ) ,
. V_4 = V_2 -> V_26 ,
} ;
V_85 = F_55 ( V_18 , V_87 ) ;
if ( V_85 == NULL )
goto V_88;
if ( F_56 ( V_18 , V_84 , sizeof( V_51 ) , & V_51 ) )
goto V_88;
for ( V_8 = 0 ; V_8 < V_53 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
V_86 [ V_8 ] = V_11 ? V_11 -> V_36 . V_59 : 0 ;
}
if ( F_56 ( V_18 , V_77 , sizeof( V_86 ) , V_86 ) )
goto V_88;
if ( F_57 ( V_18 , V_76 , V_7 -> V_32 ) )
goto V_88;
V_36 = F_55 ( V_18 , V_74 ) ;
if ( V_36 == NULL )
goto V_88;
for ( V_8 = 0 ; V_8 < V_53 ; V_8 ++ ) {
struct V_10 * V_11 = V_2 -> V_12 [ V_8 ] ;
struct V_56 V_68 ;
unsigned long V_22 ;
memset ( & V_68 , 0 , sizeof( V_68 ) ) ;
if ( ! V_11 ) {
V_68 . V_62 = V_53 + V_8 ;
goto V_89;
}
V_68 . V_32 = V_11 -> V_32 ;
V_68 . V_62 = V_11 -> V_62 ;
V_68 . V_16 = F_12 ( V_2 , V_11 , V_7 ) ;
V_68 . V_14 = V_11 -> V_14 ;
V_68 . V_63 = V_11 -> V_36 . V_63 >> V_11 -> V_36 . V_65 ;
V_68 . V_64 = V_11 -> V_36 . V_64 >> V_11 -> V_36 . V_65 ;
V_68 . V_65 = V_11 -> V_36 . V_65 ;
V_68 . V_66 = V_11 -> V_36 . V_66 ;
V_68 . V_67 = V_11 -> V_36 . V_67 ;
V_68 . V_90 = V_11 -> V_39 . V_90 ;
V_68 . V_91 = V_11 -> V_39 . V_40 ;
V_68 . V_92 = V_11 -> V_39 . V_44 ;
V_68 . V_46 = V_11 -> V_39 . V_46 ;
V_68 . V_93 = V_11 -> V_34 ;
V_68 . V_35 = V_11 -> V_35 ;
if ( F_1 ( V_2 ) )
F_14 ( V_2 , V_11 ) ;
V_22 = F_23 ( & V_11 -> V_36 , & V_11 -> V_21 ,
V_11 -> V_21 . V_22 >> V_11 -> V_36 . V_65 ) ;
V_68 . V_94 = V_22 >> V_11 -> V_36 . V_65 ;
V_89:
if ( F_58 ( V_18 , sizeof( V_68 ) , & V_68 ) < 0 )
goto V_88;
}
F_59 ( V_18 , V_36 ) ;
return F_59 ( V_18 , V_85 ) ;
V_88:
F_60 ( V_18 , V_85 ) ;
return - V_95 ;
}
static void F_61 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_11 ( V_7 ) ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_9 ; V_8 ++ ) {
if ( V_2 -> V_12 [ V_8 ] )
F_36 ( V_2 -> V_12 [ V_8 ] ) ;
}
}
static int T_4 F_62 ( void )
{
return F_63 ( & V_96 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_96 ) ;
}
