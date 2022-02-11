static int F_1 ( const struct V_1 * V_2 , const struct V_3 * V_4 ,
int V_5 , const struct V_6 * V_7 )
{
if ( F_2 ( V_2 -> V_8 ) != V_5 )
return - 1 ;
if ( F_3 ( V_2 , V_4 ) == 0 )
return - 1 ;
if ( V_2 -> V_9 != V_10 )
return - 1 ;
if ( V_4 -> V_11 || V_4 -> V_12 || V_4 -> V_13 || ! V_4 -> V_14 ||
V_4 -> V_15 || V_4 -> V_16 || V_4 -> V_17 )
return - 1 ;
if ( F_4 ( F_5 ( V_2 ) ) )
return - 1 ;
if ( V_4 -> V_18 != V_19 &&
V_4 -> V_18 != V_20 )
return - 1 ;
if ( V_4 -> V_18 == V_20 ) {
T_1 * V_21 = ( T_1 * ) ( V_4 + 1 ) ;
if ( * V_21 != F_6 ( ( V_22 << 24 ) | ( V_22 << 16 )
| ( V_23 << 8 )
| V_24 ) )
return - 1 ;
V_21 ++ ;
if ( V_7 && F_7 ( F_8 ( V_7 -> V_25 ) ,
F_8 ( * V_21 ) ) )
return - 1 ;
V_21 ++ ;
if ( * V_21 == 0 )
return - 1 ;
}
return 0 ;
}
static void F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_2 ;
struct V_3 * V_4 = V_7 -> V_4 ;
T_1 * V_26 ;
T_2 V_27 ;
V_4 -> V_28 = V_7 -> V_29 ;
V_4 -> V_30 = V_7 -> V_31 ;
if ( V_7 -> V_32 ) {
V_26 = ( T_1 * ) ( V_4 + 1 ) ;
* ( V_26 + 2 ) = V_7 -> V_33 ;
}
V_2 -> V_8 = F_10 ( V_7 -> V_34 ) ;
V_2 -> V_35 = 0 ;
V_2 -> V_35 = F_11 ( ( V_36 * ) V_7 -> V_2 , V_2 -> V_9 ) ;
V_4 -> V_35 = 0 ;
V_27 = F_12 ( V_4 , F_13 ( V_4 ) , 0 ) ;
V_7 -> V_37 = F_14 ( V_7 -> V_37 , V_27 ) ;
V_4 -> V_35 = F_15 ( V_2 -> V_38 , V_2 -> V_39 ,
V_7 -> V_34 -
F_16 ( V_2 ) , V_40 ,
V_7 -> V_37 ) ;
}
static T_2 F_17 ( struct V_1 * V_2 , struct V_3 * V_4 , int V_5 )
{
T_2 V_41 ;
T_2 V_27 ;
T_2 V_42 ;
V_41 = ~ F_18 ( V_4 -> V_35 ) ;
V_27 = F_12 ( V_4 , F_13 ( V_4 ) , V_41 ) ;
V_42 = F_19 ( V_2 -> V_38 , V_2 -> V_39 ,
V_5 + F_13 ( V_4 ) ,
V_40 , 0 ) ;
return F_20 ( F_20 ( V_41 , V_27 ) ,
V_42 ) ;
}
static void F_21 ( struct V_6 * V_7 , struct V_43 * V_44 ,
struct V_1 * V_2 , struct V_3 * V_4 ,
T_3 V_45 , struct V_46 * V_47 )
{
int V_48 ;
T_1 * V_49 ;
T_4 V_50 = F_3 ( V_2 , V_4 ) ;
V_48 = F_22 ( V_44 ) -> V_48 ;
V_7 -> V_51 = V_44 ;
V_7 -> V_52 = & ( F_22 ( V_44 ) -> V_53 [ V_48 ] ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_54 = F_8 ( V_4 -> V_55 ) + V_50 ;
V_7 -> V_29 = V_4 -> V_28 ;
V_7 -> V_31 = V_4 -> V_30 ;
V_7 -> V_56 = 1 ;
V_7 -> V_34 = F_2 ( V_2 -> V_8 ) ;
if ( V_4 -> V_18 == 8 ) {
V_49 = ( T_1 * ) ( V_4 + 1 ) ;
V_7 -> V_32 = 1 ;
V_7 -> V_25 = * ( V_49 + 1 ) ;
V_7 -> V_33 = * ( V_49 + 2 ) ;
}
V_7 -> V_57 = V_50 ;
V_7 -> V_47 = V_47 ;
V_7 -> V_45 = V_45 ;
V_7 -> V_58 = 1 ;
V_7 -> V_37 = F_17 ( V_2 , V_4 ,
V_50 ) ;
}
static inline void F_23 ( struct V_6 * V_7 )
{
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
}
static void F_24 ( struct V_6 * V_7 , struct V_1 * V_2 ,
struct V_3 * V_4 , int V_50 )
{
struct V_43 * V_51 = V_7 -> V_51 ;
T_1 * V_21 ;
V_7 -> V_56 ++ ;
V_7 -> V_34 += V_50 ;
V_7 -> V_54 += V_50 ;
V_7 -> V_31 = V_4 -> V_30 ;
V_7 -> V_29 = V_4 -> V_28 ;
if ( V_7 -> V_32 ) {
V_21 = ( T_1 * ) ( V_4 + 1 ) ;
V_7 -> V_33 = * ( V_21 + 2 ) ;
}
V_7 -> V_37 = F_25 ( V_7 -> V_37 ,
F_17 ( V_2 , V_4 ,
V_50 ) ,
V_51 -> V_5 ) ;
V_51 -> V_5 += V_50 ;
V_51 -> V_59 += V_50 ;
if ( V_50 > V_7 -> V_57 )
V_7 -> V_57 = V_50 ;
}
static void F_26 ( struct V_6 * V_7 , struct V_43 * V_44 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_43 * V_51 = V_7 -> V_51 ;
int V_50 = F_3 ( V_2 , V_4 ) ;
F_24 ( V_7 , V_2 , V_4 , V_50 ) ;
F_27 ( V_44 , ( V_44 -> V_5 - V_50 ) ) ;
V_51 -> V_60 += V_44 -> V_60 ;
if ( V_7 -> V_61 )
V_7 -> V_61 -> V_62 = V_44 ;
else
F_22 ( V_51 ) -> V_63 = V_44 ;
V_7 -> V_61 = V_44 ;
}
static void F_28 ( struct V_6 * V_7 ,
int V_5 , int V_64 , int V_60 ,
struct V_65 * V_66 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_43 * V_44 = V_7 -> V_51 ;
int V_50 = F_3 ( V_2 , V_4 ) ;
F_24 ( V_7 , V_2 , V_4 , V_50 ) ;
V_44 -> V_60 += V_60 ;
V_66 [ 0 ] . V_67 += V_64 ;
V_66 [ 0 ] . V_68 -= V_64 ;
while ( V_50 > 0 ) {
* ( V_7 -> V_52 ) = * V_66 ;
V_50 -= V_66 -> V_68 ;
V_7 -> V_52 ++ ;
V_66 ++ ;
F_22 ( V_44 ) -> V_48 ++ ;
}
}
static int F_29 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ( V_7 -> V_2 -> V_38 != V_2 -> V_38 ) ||
( V_7 -> V_2 -> V_39 != V_2 -> V_39 ) ||
( V_7 -> V_4 -> V_69 != V_4 -> V_69 ) ||
( V_7 -> V_4 -> V_70 != V_4 -> V_70 ) )
return - 1 ;
return 0 ;
}
static struct V_6 * F_30 ( struct V_71 * V_72 ,
struct V_6 * V_73 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = NULL ;
struct V_6 * V_74 ;
int V_75 = V_72 -> V_75 ;
int V_76 ;
for ( V_76 = 0 ; V_76 < V_75 ; V_76 ++ ) {
V_74 = & V_73 [ V_76 ] ;
if ( V_74 -> V_58 )
if ( ! F_29 ( V_74 , V_2 , V_4 ) ) {
V_7 = V_74 ;
goto V_77;
}
}
for ( V_76 = 0 ; V_76 < V_75 ; V_76 ++ ) {
if ( ! V_73 [ V_76 ] . V_58 ) {
V_7 = & V_73 [ V_76 ] ;
goto V_77;
}
}
F_31 ( V_72 , V_78 ) ;
V_77:
return V_7 ;
}
static void F_32 ( struct V_71 * V_72 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_56 > 1 )
F_9 ( V_7 ) ;
F_22 ( V_7 -> V_51 ) -> V_79 = V_7 -> V_57 ;
if ( V_7 -> V_47 ) {
if ( V_72 -> V_80 & V_81 )
F_33 ( V_7 -> V_51 ,
V_7 -> V_47 ,
V_7 -> V_45 ) ;
else
F_34 ( V_7 -> V_51 ,
V_7 -> V_47 ,
V_7 -> V_45 ) ;
} else {
if ( V_72 -> V_80 & V_81 )
F_35 ( V_7 -> V_51 ) ;
else
F_36 ( V_7 -> V_51 ) ;
}
F_31 ( V_72 , V_82 ) ;
F_23 ( V_7 ) ;
}
static int F_37 ( struct V_71 * V_72 , struct V_43 * V_44 ,
struct V_46 * V_47 , T_3 V_45 , void * V_83 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_5 V_84 ;
int V_85 = 0 ;
if ( ! V_72 -> V_86 ||
V_72 -> V_86 ( V_44 , ( void * ) & V_2 , ( void * ) & V_4 ,
& V_84 , V_83 ) )
goto V_77;
if ( ! ( V_84 & V_87 ) || ! ( V_84 & V_88 ) )
goto V_77;
V_7 = F_30 ( V_72 , V_72 -> V_73 , V_2 , V_4 ) ;
if ( ! V_7 )
goto V_77;
if ( ( V_44 -> V_89 == F_10 ( V_90 ) ) &&
! ( V_72 -> V_80 & V_91 ) )
V_85 = V_92 ;
if ( ! V_7 -> V_58 ) {
if ( F_1 ( V_2 , V_4 , V_44 -> V_5 - V_85 , NULL ) )
goto V_77;
V_44 -> V_93 = V_72 -> V_94 ;
F_21 ( V_7 , V_44 , V_2 , V_4 , V_45 , V_47 ) ;
F_31 ( V_72 , V_95 ) ;
return 0 ;
}
if ( V_7 -> V_54 != F_8 ( V_4 -> V_55 ) )
goto V_96;
if ( F_1 ( V_2 , V_4 , V_44 -> V_5 , V_7 ) )
goto V_96;
F_26 ( V_7 , V_44 , V_2 , V_4 ) ;
F_31 ( V_72 , V_95 ) ;
if ( ( V_7 -> V_56 >= V_72 -> V_97 ) ||
V_7 -> V_51 -> V_5 > ( 0xFFFF - V_72 -> V_98 -> V_99 ) )
F_32 ( V_72 , V_7 ) ;
return 0 ;
V_96:
F_32 ( V_72 , V_7 ) ;
V_77:
return 1 ;
}
static struct V_43 * F_38 ( struct V_71 * V_72 ,
struct V_65 * V_53 ,
int V_5 , int V_100 ,
void * V_101 ,
int V_64 , T_2 V_102 ,
T_4 V_93 )
{
struct V_43 * V_44 ;
struct V_65 * V_66 ;
int V_59 = V_5 ;
int V_103 = F_39 ( V_5 , V_64 ) ;
V_44 = F_40 ( V_72 -> V_98 , V_64 + V_72 -> V_104 ) ;
if ( ! V_44 )
return NULL ;
F_41 ( V_44 , V_72 -> V_104 ) ;
V_44 -> V_5 = V_5 ;
V_44 -> V_59 = V_5 - V_103 ;
V_44 -> V_60 += V_100 ;
V_44 -> V_105 += V_103 ;
memcpy ( V_44 -> V_106 , V_101 , V_103 ) ;
V_66 = F_22 ( V_44 ) -> V_53 ;
while ( V_59 > 0 ) {
* V_66 = * V_53 ;
V_59 -= V_53 -> V_68 ;
V_66 ++ ;
V_53 ++ ;
F_22 ( V_44 ) -> V_48 ++ ;
}
F_22 ( V_44 ) -> V_53 [ 0 ] . V_67 += V_103 ;
F_22 ( V_44 ) -> V_53 [ 0 ] . V_68 -= V_103 ;
V_44 -> V_93 = V_93 ;
V_44 -> V_107 = V_102 ;
V_44 -> V_89 = F_42 ( V_44 , V_72 -> V_98 ) ;
return V_44 ;
}
static struct V_43 * F_43 ( struct V_71 * V_72 ,
struct V_65 * V_53 ,
int V_5 , int V_100 ,
struct V_46 * V_47 ,
T_3 V_45 , void * V_83 , T_2 V_102 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
T_5 V_84 ;
void * V_101 ;
int V_108 ;
int V_103 = V_109 ;
int V_85 = 0 ;
if ( ! V_72 -> V_110 ||
V_72 -> V_110 ( V_53 , ( void * ) & V_101 , ( void * ) & V_2 ,
( void * ) & V_4 , & V_84 , V_83 ) ) {
V_101 = F_44 ( V_53 -> V_111 ) + V_53 -> V_67 ;
goto V_112;
}
if ( ! ( V_84 & V_87 ) || ! ( V_84 & V_88 ) )
goto V_112;
V_103 = ( int ) ( ( void * ) ( V_4 ) + F_13 ( V_4 ) - V_101 ) ;
V_108 = ( int ) ( ( void * ) ( V_2 ) - V_101 ) ;
V_7 = F_30 ( V_72 , V_72 -> V_73 , V_2 , V_4 ) ;
if ( ! V_7 )
goto V_112;
if ( ! V_7 -> V_58 ) {
if ( F_1 ( V_2 , V_4 , V_5 - V_108 , NULL ) )
goto V_112;
V_44 = F_38 ( V_72 , V_53 , V_5 , V_100 , V_101 ,
V_103 , 0 , V_72 -> V_94 ) ;
if ( ! V_44 )
goto V_77;
if ( ( V_44 -> V_89 == F_10 ( V_90 ) ) &&
! ( V_72 -> V_80 & V_91 ) )
V_85 = V_92 ;
V_2 = ( void * ) ( V_44 -> V_106 + V_85 ) ;
V_4 = ( void * ) ( ( V_36 * ) V_44 -> V_106 + V_85
+ F_16 ( V_2 ) ) ;
F_21 ( V_7 , V_44 , V_2 , V_4 , 0 , NULL ) ;
F_31 ( V_72 , V_95 ) ;
return NULL ;
}
if ( V_7 -> V_54 != F_8 ( V_4 -> V_55 ) )
goto V_96;
if ( F_1 ( V_2 , V_4 , V_5 - V_108 , V_7 ) )
goto V_96;
F_28 ( V_7 , V_5 , V_103 , V_100 , V_53 , V_2 , V_4 ) ;
F_31 ( V_72 , V_95 ) ;
if ( ( F_22 ( V_7 -> V_51 ) -> V_48 >= V_72 -> V_97 ) ||
V_7 -> V_51 -> V_5 > ( 0xFFFF - V_72 -> V_98 -> V_99 ) )
F_32 ( V_72 , V_7 ) ;
return NULL ;
V_96:
F_32 ( V_72 , V_7 ) ;
V_112:
V_44 = F_38 ( V_72 , V_53 , V_5 , V_100 , V_101 ,
V_103 , V_102 , V_72 -> V_93 ) ;
V_77:
return V_44 ;
}
void F_45 ( struct V_71 * V_72 ,
struct V_43 * V_44 ,
void * V_83 )
{
if ( F_37 ( V_72 , V_44 , NULL , 0 , V_83 ) ) {
if ( V_72 -> V_80 & V_81 )
F_35 ( V_44 ) ;
else
F_36 ( V_44 ) ;
}
}
void F_46 ( struct V_71 * V_72 ,
struct V_43 * V_44 ,
struct V_46 * V_47 ,
T_3 V_45 ,
void * V_83 )
{
if ( F_37 ( V_72 , V_44 , V_47 , V_45 , V_83 ) ) {
if ( V_72 -> V_80 & V_81 )
F_33 ( V_44 , V_47 , V_45 ) ;
else
F_34 ( V_44 , V_47 , V_45 ) ;
}
}
void F_47 ( struct V_71 * V_72 ,
struct V_65 * V_53 ,
int V_5 , int V_100 , void * V_83 , T_2 V_102 )
{
struct V_43 * V_44 ;
V_44 = F_43 ( V_72 , V_53 , V_5 , V_100 , NULL , 0 ,
V_83 , V_102 ) ;
if ( ! V_44 )
return;
if ( V_72 -> V_80 & V_81 )
F_35 ( V_44 ) ;
else
F_36 ( V_44 ) ;
}
void F_48 ( struct V_71 * V_72 ,
struct V_65 * V_53 ,
int V_5 , int V_100 ,
struct V_46 * V_47 ,
T_3 V_45 , void * V_83 , T_2 V_102 )
{
struct V_43 * V_44 ;
V_44 = F_43 ( V_72 , V_53 , V_5 , V_100 , V_47 ,
V_45 , V_83 , V_102 ) ;
if ( ! V_44 )
return;
if ( V_72 -> V_80 & V_81 )
F_33 ( V_44 , V_47 , V_45 ) ;
else
F_34 ( V_44 , V_47 , V_45 ) ;
}
void F_49 ( struct V_71 * V_72 )
{
int V_76 ;
struct V_6 * V_7 = V_72 -> V_73 ;
for ( V_76 = 0 ; V_76 < V_72 -> V_75 ; V_76 ++ ) {
if ( V_7 [ V_76 ] . V_58 )
F_32 ( V_72 , & V_7 [ V_76 ] ) ;
}
}
void F_50 ( struct V_71 * V_72 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
V_7 = F_30 ( V_72 , V_72 -> V_73 , V_2 , V_4 ) ;
if ( V_7 -> V_58 )
F_32 ( V_72 , V_7 ) ;
}
