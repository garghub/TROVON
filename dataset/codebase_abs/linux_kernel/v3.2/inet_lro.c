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
struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_45 ;
T_1 * V_46 ;
T_3 V_47 = F_3 ( V_2 , V_4 ) ;
V_45 = F_22 ( V_44 ) -> V_45 ;
V_7 -> V_48 = V_44 ;
V_7 -> V_49 = & ( F_22 ( V_44 ) -> V_50 [ V_45 ] ) ;
V_7 -> V_2 = V_2 ;
V_7 -> V_4 = V_4 ;
V_7 -> V_51 = F_8 ( V_4 -> V_52 ) + V_47 ;
V_7 -> V_29 = V_4 -> V_28 ;
V_7 -> V_31 = V_4 -> V_30 ;
V_7 -> V_53 = 1 ;
V_7 -> V_34 = F_2 ( V_2 -> V_8 ) ;
if ( V_4 -> V_18 == 8 ) {
V_46 = ( T_1 * ) ( V_4 + 1 ) ;
V_7 -> V_32 = 1 ;
V_7 -> V_25 = * ( V_46 + 1 ) ;
V_7 -> V_33 = * ( V_46 + 2 ) ;
}
V_7 -> V_54 = V_47 ;
V_7 -> V_55 = 1 ;
V_7 -> V_37 = F_17 ( V_2 , V_4 ,
V_47 ) ;
}
static inline void F_23 ( struct V_6 * V_7 )
{
memset ( V_7 , 0 , sizeof( struct V_6 ) ) ;
}
static void F_24 ( struct V_6 * V_7 , struct V_1 * V_2 ,
struct V_3 * V_4 , int V_47 )
{
struct V_43 * V_48 = V_7 -> V_48 ;
T_1 * V_21 ;
V_7 -> V_53 ++ ;
V_7 -> V_34 += V_47 ;
V_7 -> V_51 += V_47 ;
V_7 -> V_31 = V_4 -> V_30 ;
V_7 -> V_29 = V_4 -> V_28 ;
if ( V_7 -> V_32 ) {
V_21 = ( T_1 * ) ( V_4 + 1 ) ;
V_7 -> V_33 = * ( V_21 + 2 ) ;
}
V_7 -> V_37 = F_25 ( V_7 -> V_37 ,
F_17 ( V_2 , V_4 ,
V_47 ) ,
V_48 -> V_5 ) ;
V_48 -> V_5 += V_47 ;
V_48 -> V_56 += V_47 ;
if ( V_47 > V_7 -> V_54 )
V_7 -> V_54 = V_47 ;
}
static void F_26 ( struct V_6 * V_7 , struct V_43 * V_44 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_43 * V_48 = V_7 -> V_48 ;
int V_47 = F_3 ( V_2 , V_4 ) ;
F_24 ( V_7 , V_2 , V_4 , V_47 ) ;
F_27 ( V_44 , ( V_44 -> V_5 - V_47 ) ) ;
V_48 -> V_57 += V_44 -> V_57 ;
if ( V_7 -> V_58 )
V_7 -> V_58 -> V_59 = V_44 ;
else
F_22 ( V_48 ) -> V_60 = V_44 ;
V_7 -> V_58 = V_44 ;
}
static void F_28 ( struct V_6 * V_7 ,
int V_5 , int V_61 , int V_57 ,
struct V_62 * V_63 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_43 * V_44 = V_7 -> V_48 ;
int V_47 = F_3 ( V_2 , V_4 ) ;
F_24 ( V_7 , V_2 , V_4 , V_47 ) ;
V_44 -> V_57 += V_57 ;
V_63 [ 0 ] . V_64 += V_61 ;
F_29 ( & V_63 [ 0 ] , V_61 ) ;
while ( V_47 > 0 ) {
* ( V_7 -> V_49 ) = * V_63 ;
V_47 -= F_30 ( V_63 ) ;
V_7 -> V_49 ++ ;
V_63 ++ ;
F_22 ( V_44 ) -> V_45 ++ ;
}
}
static int F_31 ( struct V_6 * V_7 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( ( V_7 -> V_2 -> V_38 != V_2 -> V_38 ) ||
( V_7 -> V_2 -> V_39 != V_2 -> V_39 ) ||
( V_7 -> V_4 -> V_65 != V_4 -> V_65 ) ||
( V_7 -> V_4 -> V_66 != V_4 -> V_66 ) )
return - 1 ;
return 0 ;
}
static struct V_6 * F_32 ( struct V_67 * V_68 ,
struct V_6 * V_69 ,
struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_6 * V_7 = NULL ;
struct V_6 * V_70 ;
int V_71 = V_68 -> V_71 ;
int V_72 ;
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
V_70 = & V_69 [ V_72 ] ;
if ( V_70 -> V_55 )
if ( ! F_31 ( V_70 , V_2 , V_4 ) ) {
V_7 = V_70 ;
goto V_73;
}
}
for ( V_72 = 0 ; V_72 < V_71 ; V_72 ++ ) {
if ( ! V_69 [ V_72 ] . V_55 ) {
V_7 = & V_69 [ V_72 ] ;
goto V_73;
}
}
F_33 ( V_68 , V_74 ) ;
V_73:
return V_7 ;
}
static void F_34 ( struct V_67 * V_68 ,
struct V_6 * V_7 )
{
if ( V_7 -> V_53 > 1 )
F_9 ( V_7 ) ;
F_22 ( V_7 -> V_48 ) -> V_75 = V_7 -> V_54 ;
if ( V_68 -> V_76 & V_77 )
F_35 ( V_7 -> V_48 ) ;
else
F_36 ( V_7 -> V_48 ) ;
F_33 ( V_68 , V_78 ) ;
F_23 ( V_7 ) ;
}
static int F_37 ( struct V_67 * V_68 , struct V_43 * V_44 ,
void * V_79 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
T_4 V_80 ;
int V_81 = 0 ;
if ( ! V_68 -> V_82 ||
V_68 -> V_82 ( V_44 , ( void * ) & V_2 , ( void * ) & V_4 ,
& V_80 , V_79 ) )
goto V_73;
if ( ! ( V_80 & V_83 ) || ! ( V_80 & V_84 ) )
goto V_73;
V_7 = F_32 ( V_68 , V_68 -> V_69 , V_2 , V_4 ) ;
if ( ! V_7 )
goto V_73;
if ( ( V_44 -> V_85 == F_10 ( V_86 ) ) &&
! ( V_68 -> V_76 & V_87 ) )
V_81 = V_88 ;
if ( ! V_7 -> V_55 ) {
if ( F_1 ( V_2 , V_4 , V_44 -> V_5 - V_81 , NULL ) )
goto V_73;
V_44 -> V_89 = V_68 -> V_90 ;
F_21 ( V_7 , V_44 , V_2 , V_4 ) ;
F_33 ( V_68 , V_91 ) ;
return 0 ;
}
if ( V_7 -> V_51 != F_8 ( V_4 -> V_52 ) )
goto V_92;
if ( F_1 ( V_2 , V_4 , V_44 -> V_5 , V_7 ) )
goto V_92;
F_26 ( V_7 , V_44 , V_2 , V_4 ) ;
F_33 ( V_68 , V_91 ) ;
if ( ( V_7 -> V_53 >= V_68 -> V_93 ) ||
V_7 -> V_48 -> V_5 > ( 0xFFFF - V_68 -> V_94 -> V_95 ) )
F_34 ( V_68 , V_7 ) ;
return 0 ;
V_92:
F_34 ( V_68 , V_7 ) ;
V_73:
return 1 ;
}
static struct V_43 * F_38 ( struct V_67 * V_68 ,
struct V_62 * V_50 ,
int V_5 , int V_96 ,
void * V_97 ,
int V_61 , T_2 V_98 ,
T_3 V_89 )
{
struct V_43 * V_44 ;
struct V_62 * V_63 ;
int V_56 = V_5 ;
int V_99 = F_39 ( V_5 , V_61 ) ;
V_44 = F_40 ( V_68 -> V_94 , V_61 + V_68 -> V_100 ) ;
if ( ! V_44 )
return NULL ;
F_41 ( V_44 , V_68 -> V_100 ) ;
V_44 -> V_5 = V_5 ;
V_44 -> V_56 = V_5 - V_99 ;
V_44 -> V_57 += V_96 ;
V_44 -> V_101 += V_99 ;
memcpy ( V_44 -> V_102 , V_97 , V_99 ) ;
V_63 = F_22 ( V_44 ) -> V_50 ;
while ( V_56 > 0 ) {
* V_63 = * V_50 ;
V_56 -= F_30 ( V_50 ) ;
V_63 ++ ;
V_50 ++ ;
F_22 ( V_44 ) -> V_45 ++ ;
}
F_22 ( V_44 ) -> V_50 [ 0 ] . V_64 += V_99 ;
F_29 ( & F_22 ( V_44 ) -> V_50 [ 0 ] , V_99 ) ;
V_44 -> V_89 = V_89 ;
V_44 -> V_103 = V_98 ;
V_44 -> V_85 = F_42 ( V_44 , V_68 -> V_94 ) ;
return V_44 ;
}
static struct V_43 * F_43 ( struct V_67 * V_68 ,
struct V_62 * V_50 ,
int V_5 , int V_96 ,
void * V_79 , T_2 V_98 )
{
struct V_6 * V_7 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_43 * V_44 ;
T_4 V_80 ;
void * V_97 ;
int V_104 ;
int V_99 = V_105 ;
int V_81 = 0 ;
if ( ! V_68 -> V_106 ||
V_68 -> V_106 ( V_50 , ( void * ) & V_97 , ( void * ) & V_2 ,
( void * ) & V_4 , & V_80 , V_79 ) ) {
V_97 = F_44 ( V_50 ) ;
goto V_107;
}
if ( ! ( V_80 & V_83 ) || ! ( V_80 & V_84 ) )
goto V_107;
V_99 = ( int ) ( ( void * ) ( V_4 ) + F_13 ( V_4 ) - V_97 ) ;
V_104 = ( int ) ( ( void * ) ( V_2 ) - V_97 ) ;
V_7 = F_32 ( V_68 , V_68 -> V_69 , V_2 , V_4 ) ;
if ( ! V_7 )
goto V_107;
if ( ! V_7 -> V_55 ) {
if ( F_1 ( V_2 , V_4 , V_5 - V_104 , NULL ) )
goto V_107;
V_44 = F_38 ( V_68 , V_50 , V_5 , V_96 , V_97 ,
V_99 , 0 , V_68 -> V_90 ) ;
if ( ! V_44 )
goto V_73;
if ( ( V_44 -> V_85 == F_10 ( V_86 ) ) &&
! ( V_68 -> V_76 & V_87 ) )
V_81 = V_88 ;
V_2 = ( void * ) ( V_44 -> V_102 + V_81 ) ;
V_4 = ( void * ) ( ( V_36 * ) V_44 -> V_102 + V_81
+ F_16 ( V_2 ) ) ;
F_21 ( V_7 , V_44 , V_2 , V_4 ) ;
F_33 ( V_68 , V_91 ) ;
return NULL ;
}
if ( V_7 -> V_51 != F_8 ( V_4 -> V_52 ) )
goto V_92;
if ( F_1 ( V_2 , V_4 , V_5 - V_104 , V_7 ) )
goto V_92;
F_28 ( V_7 , V_5 , V_99 , V_96 , V_50 , V_2 , V_4 ) ;
F_33 ( V_68 , V_91 ) ;
if ( ( F_22 ( V_7 -> V_48 ) -> V_45 >= V_68 -> V_93 ) ||
V_7 -> V_48 -> V_5 > ( 0xFFFF - V_68 -> V_94 -> V_95 ) )
F_34 ( V_68 , V_7 ) ;
return NULL ;
V_92:
F_34 ( V_68 , V_7 ) ;
V_107:
V_44 = F_38 ( V_68 , V_50 , V_5 , V_96 , V_97 ,
V_99 , V_98 , V_68 -> V_89 ) ;
V_73:
return V_44 ;
}
void F_45 ( struct V_67 * V_68 ,
struct V_43 * V_44 ,
void * V_79 )
{
if ( F_37 ( V_68 , V_44 , V_79 ) ) {
if ( V_68 -> V_76 & V_77 )
F_35 ( V_44 ) ;
else
F_36 ( V_44 ) ;
}
}
void F_46 ( struct V_67 * V_68 ,
struct V_62 * V_50 ,
int V_5 , int V_96 , void * V_79 , T_2 V_98 )
{
struct V_43 * V_44 ;
V_44 = F_43 ( V_68 , V_50 , V_5 , V_96 , V_79 , V_98 ) ;
if ( ! V_44 )
return;
if ( V_68 -> V_76 & V_77 )
F_35 ( V_44 ) ;
else
F_36 ( V_44 ) ;
}
void F_47 ( struct V_67 * V_68 )
{
int V_72 ;
struct V_6 * V_7 = V_68 -> V_69 ;
for ( V_72 = 0 ; V_72 < V_68 -> V_71 ; V_72 ++ ) {
if ( V_7 [ V_72 ] . V_55 )
F_34 ( V_68 , & V_7 [ V_72 ] ) ;
}
}
void F_48 ( struct V_67 * V_68 ,
struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 ;
V_7 = F_32 ( V_68 , V_68 -> V_69 , V_2 , V_4 ) ;
if ( V_7 -> V_55 )
F_34 ( V_68 , V_7 ) ;
}
