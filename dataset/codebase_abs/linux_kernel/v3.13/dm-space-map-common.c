static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_7 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_7 -> V_9 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_7 -> V_8 ) ) {
F_9 ( L_1 ,
F_8 ( V_7 -> V_8 ) , F_4 ( V_4 ) ) ;
return - V_14 ;
}
V_13 = F_5 ( F_6 ( & V_7 -> V_10 ,
V_5 - sizeof( V_11 ) ,
V_12 ) ) ;
if ( V_13 != V_7 -> V_9 ) {
F_9 ( L_2 ,
F_10 ( V_13 ) , F_10 ( V_7 -> V_9 ) ) ;
return - V_15 ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_16 * V_17 = F_2 ( V_4 ) ;
V_17 -> V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_17 -> V_9 = F_5 ( F_6 ( & V_17 -> V_18 ,
V_5 - sizeof( V_11 ) ,
V_19 ) ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 )
{
struct V_16 * V_17 = F_2 ( V_4 ) ;
V_11 V_13 ;
if ( F_4 ( V_4 ) != F_8 ( V_17 -> V_8 ) ) {
F_9 ( L_3 ,
F_8 ( V_17 -> V_8 ) , F_4 ( V_4 ) ) ;
return - V_14 ;
}
V_13 = F_5 ( F_6 ( & V_17 -> V_18 ,
V_5 - sizeof( V_11 ) ,
V_19 ) ) ;
if ( V_13 != V_17 -> V_9 ) {
F_9 ( L_4 ,
F_10 ( V_13 ) , F_10 ( V_17 -> V_9 ) ) ;
return - V_15 ;
}
return 0 ;
}
static void * F_13 ( struct V_3 * V_4 )
{
return F_2 ( V_4 ) + sizeof( struct V_16 ) ;
}
static unsigned F_14 ( void * V_20 , unsigned V_4 )
{
T_2 * V_21 = V_20 ;
T_2 * V_22 = V_21 + ( V_4 >> V_23 ) ;
T_3 V_24 = F_8 ( * V_22 ) ;
T_3 V_25 = ( V_24 + V_26 + 1 ) & V_26 ;
return ! ( ~ V_24 & V_25 ) ;
}
static unsigned F_15 ( void * V_20 , unsigned V_4 )
{
T_2 * V_21 = V_20 ;
T_2 * V_22 = V_21 + ( V_4 >> V_23 ) ;
unsigned V_27 , V_28 ;
V_4 = ( V_4 & ( V_29 - 1 ) ) << 1 ;
V_27 = ! ! F_16 ( V_4 , ( void * ) V_22 ) ;
V_28 = ! ! F_16 ( V_4 + 1 , ( void * ) V_22 ) ;
return ( V_27 << 1 ) | V_28 ;
}
static void F_17 ( void * V_20 , unsigned V_4 , unsigned V_30 )
{
T_2 * V_21 = V_20 ;
T_2 * V_22 = V_21 + ( V_4 >> V_23 ) ;
V_4 = ( V_4 & ( V_29 - 1 ) ) << 1 ;
if ( V_30 & 2 )
F_18 ( V_4 , ( void * ) V_22 ) ;
else
F_19 ( V_4 , ( void * ) V_22 ) ;
if ( V_30 & 1 )
F_18 ( V_4 + 1 , ( void * ) V_22 ) ;
else
F_19 ( V_4 + 1 , ( void * ) V_22 ) ;
}
static int F_20 ( void * V_20 , unsigned V_31 , unsigned V_32 ,
unsigned * V_33 )
{
while ( V_31 < V_32 ) {
if ( ! ( V_31 & ( V_29 - 1 ) ) &&
F_14 ( V_20 , V_31 ) ) {
V_31 += V_29 ;
continue;
}
if ( ! F_15 ( V_20 , V_31 ) ) {
* V_33 = V_31 ;
return 0 ;
}
V_31 ++ ;
}
return - V_34 ;
}
static int F_21 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
V_36 -> V_38 = V_38 ;
V_36 -> V_39 . V_38 = V_38 ;
V_36 -> V_39 . V_40 = 1 ;
V_36 -> V_39 . V_41 . V_42 = sizeof( struct V_43 ) ;
V_36 -> V_39 . V_41 . V_44 = NULL ;
V_36 -> V_39 . V_41 . V_45 = NULL ;
V_36 -> V_39 . V_41 . V_46 = NULL ;
V_36 -> V_47 . V_38 = V_38 ;
V_36 -> V_47 . V_40 = 1 ;
V_36 -> V_47 . V_41 . V_42 = sizeof( V_48 ) ;
V_36 -> V_47 . V_41 . V_44 = NULL ;
V_36 -> V_47 . V_41 . V_45 = NULL ;
V_36 -> V_47 . V_41 . V_46 = NULL ;
V_36 -> V_5 = F_22 ( F_23 ( V_38 ) ) ;
if ( V_36 -> V_5 > ( 1 << 30 ) ) {
F_24 ( L_5 ) ;
return - V_49 ;
}
V_36 -> V_50 = ( V_36 -> V_5 - sizeof( struct V_16 ) ) *
V_51 ;
V_36 -> V_52 = 0 ;
V_36 -> V_53 = 0 ;
V_36 -> V_54 = 0 ;
V_36 -> V_55 = false ;
return 0 ;
}
int F_25 ( struct V_35 * V_36 , T_4 V_56 )
{
int V_57 ;
T_4 V_58 , V_52 , V_59 ;
unsigned V_60 , V_61 ;
V_52 = V_36 -> V_52 + V_56 ;
V_60 = F_26 ( V_36 -> V_52 , V_36 -> V_50 ) ;
V_61 = F_26 ( V_52 , V_36 -> V_50 ) ;
V_59 = F_26 ( V_52 , V_36 -> V_50 ) ;
if ( V_59 > V_36 -> V_62 ( V_36 ) ) {
F_24 ( L_6 ) ;
return - V_49 ;
}
for ( V_58 = V_60 ; V_58 < V_61 ; V_58 ++ ) {
struct V_3 * V_4 ;
struct V_43 V_63 ;
V_57 = F_27 ( V_36 -> V_38 , & V_64 , & V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
V_63 . V_8 = F_3 ( F_4 ( V_4 ) ) ;
V_57 = F_28 ( V_36 -> V_38 , V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
V_63 . V_65 = F_5 ( V_36 -> V_50 ) ;
V_63 . V_66 = 0 ;
V_57 = V_36 -> V_67 ( V_36 , V_58 , & V_63 ) ;
if ( V_57 < 0 )
return V_57 ;
}
V_36 -> V_52 = V_52 ;
return 0 ;
}
int F_29 ( struct V_35 * V_36 , T_4 V_4 , V_48 * V_33 )
{
int V_57 ;
T_4 V_68 = V_4 ;
struct V_43 V_69 ;
struct V_3 * V_70 ;
V_4 = F_30 ( V_68 , V_36 -> V_50 ) ;
V_57 = V_36 -> V_71 ( V_36 , V_68 , & V_69 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_31 ( V_36 -> V_38 , F_8 ( V_69 . V_8 ) ,
& V_64 , & V_70 ) ;
if ( V_57 < 0 )
return V_57 ;
* V_33 = F_15 ( F_13 ( V_70 ) , V_4 ) ;
return F_28 ( V_36 -> V_38 , V_70 ) ;
}
static int F_32 ( struct V_35 * V_36 , T_4 V_4 ,
V_48 * V_33 )
{
V_11 V_72 ;
int V_57 ;
V_57 = F_33 ( & V_36 -> V_47 , V_36 -> V_54 , & V_4 , & V_72 ) ;
if ( V_57 < 0 )
return V_57 ;
* V_33 = F_10 ( V_72 ) ;
return V_57 ;
}
int F_34 ( struct V_35 * V_36 , T_4 V_4 , V_48 * V_33 )
{
int V_57 = F_29 ( V_36 , V_4 , V_33 ) ;
if ( V_57 )
return V_57 ;
if ( * V_33 != 3 )
return V_57 ;
return F_32 ( V_36 , V_4 , V_33 ) ;
}
int F_35 ( struct V_35 * V_36 , T_4 V_31 ,
T_4 V_32 , T_4 * V_33 )
{
int V_57 ;
struct V_43 V_69 ;
T_4 V_58 , V_73 = V_31 ;
T_4 V_74 = F_26 ( V_32 , V_36 -> V_50 ) ;
V_31 = F_30 ( V_73 , V_36 -> V_50 ) ;
V_32 = F_30 ( V_32 , V_36 -> V_50 ) ;
for ( V_58 = V_73 ; V_58 < V_74 ; V_58 ++ , V_31 = 0 ) {
struct V_3 * V_70 ;
unsigned V_75 ;
V_48 V_76 ;
V_57 = V_36 -> V_71 ( V_36 , V_58 , & V_69 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( F_10 ( V_69 . V_65 ) == 0 )
continue;
V_57 = F_31 ( V_36 -> V_38 , F_8 ( V_69 . V_8 ) ,
& V_64 , & V_70 ) ;
if ( V_57 < 0 )
return V_57 ;
V_76 = ( V_58 == V_74 - 1 ) ? V_32 : V_36 -> V_50 ;
V_57 = F_20 ( F_13 ( V_70 ) ,
F_36 ( unsigned , V_31 , F_10 ( V_69 . V_66 ) ) ,
V_76 , & V_75 ) ;
if ( V_57 == - V_34 ) {
F_28 ( V_36 -> V_38 , V_70 ) ;
continue;
} else if ( V_57 < 0 ) {
F_28 ( V_36 -> V_38 , V_70 ) ;
return V_57 ;
}
V_57 = F_28 ( V_36 -> V_38 , V_70 ) ;
if ( V_57 < 0 )
return V_57 ;
* V_33 = V_58 * V_36 -> V_50 + ( T_4 ) V_75 ;
return 0 ;
}
return - V_34 ;
}
static int F_37 ( struct V_35 * V_36 , T_4 V_4 ,
int (* F_38)( void * V_77 , V_48 V_78 , V_48 * V_79 ) ,
void * V_77 , enum V_80 * V_81 )
{
int V_57 ;
V_48 V_82 , V_78 , V_83 ;
struct V_3 * V_84 ;
T_4 V_68 = V_4 ;
struct V_43 V_69 ;
void * V_85 ;
int V_44 ;
V_82 = F_30 ( V_68 , V_36 -> V_50 ) ;
V_57 = V_36 -> V_71 ( V_36 , V_68 , & V_69 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_39 ( V_36 -> V_38 , F_8 ( V_69 . V_8 ) ,
& V_64 , & V_84 , & V_44 ) ;
if ( V_57 < 0 ) {
F_24 ( L_7 ) ;
return V_57 ;
}
V_69 . V_8 = F_3 ( F_4 ( V_84 ) ) ;
V_85 = F_13 ( V_84 ) ;
V_78 = F_15 ( V_85 , V_82 ) ;
if ( V_78 > 2 ) {
V_57 = F_32 ( V_36 , V_4 , & V_78 ) ;
if ( V_57 < 0 ) {
F_28 ( V_36 -> V_38 , V_84 ) ;
return V_57 ;
}
}
V_57 = F_38 ( V_77 , V_78 , & V_83 ) ;
if ( V_57 ) {
F_28 ( V_36 -> V_38 , V_84 ) ;
return V_57 ;
}
if ( V_83 <= 2 ) {
F_17 ( V_85 , V_82 , V_83 ) ;
V_57 = F_28 ( V_36 -> V_38 , V_84 ) ;
if ( V_57 < 0 )
return V_57 ;
if ( V_78 > 2 ) {
V_57 = F_40 ( & V_36 -> V_47 ,
V_36 -> V_54 ,
& V_4 , & V_36 -> V_54 ) ;
if ( V_57 )
return V_57 ;
}
} else {
V_11 V_72 = F_5 ( V_83 ) ;
F_17 ( V_85 , V_82 , 3 ) ;
V_57 = F_28 ( V_36 -> V_38 , V_84 ) ;
if ( V_57 < 0 )
return V_57 ;
F_41 ( & V_72 ) ;
V_57 = F_42 ( & V_36 -> V_47 , V_36 -> V_54 ,
& V_4 , & V_72 , & V_36 -> V_54 ) ;
if ( V_57 < 0 ) {
F_24 ( L_8 ) ;
return V_57 ;
}
}
if ( V_83 && ! V_78 ) {
* V_81 = V_86 ;
V_36 -> V_87 ++ ;
F_43 ( & V_69 . V_65 , - 1 ) ;
if ( F_10 ( V_69 . V_66 ) == V_82 )
V_69 . V_66 = F_5 ( V_82 + 1 ) ;
} else if ( V_78 && ! V_83 ) {
* V_81 = V_88 ;
V_36 -> V_87 -- ;
F_43 ( & V_69 . V_65 , 1 ) ;
V_69 . V_66 = F_5 ( F_44 ( F_10 ( V_69 . V_66 ) , V_82 ) ) ;
}
return V_36 -> V_67 ( V_36 , V_68 , & V_69 ) ;
}
static int F_45 ( void * V_77 , V_48 V_78 , V_48 * V_79 )
{
* V_79 = * ( ( V_48 * ) V_77 ) ;
return 0 ;
}
int F_46 ( struct V_35 * V_36 , T_4 V_4 ,
V_48 V_83 , enum V_80 * V_81 )
{
return F_37 ( V_36 , V_4 , F_45 , & V_83 , V_81 ) ;
}
static int F_47 ( void * V_77 , V_48 V_78 , V_48 * V_79 )
{
* V_79 = V_78 + 1 ;
return 0 ;
}
int F_48 ( struct V_35 * V_36 , T_4 V_4 , enum V_80 * V_81 )
{
return F_37 ( V_36 , V_4 , F_47 , NULL , V_81 ) ;
}
static int F_49 ( void * V_77 , V_48 V_78 , V_48 * V_79 )
{
if ( ! V_78 ) {
F_9 ( L_9 ) ;
return - V_49 ;
}
* V_79 = V_78 - 1 ;
return 0 ;
}
int F_50 ( struct V_35 * V_36 , T_4 V_4 , enum V_80 * V_81 )
{
return F_37 ( V_36 , V_4 , F_49 , NULL , V_81 ) ;
}
int F_51 ( struct V_35 * V_36 )
{
int V_57 = 0 ;
if ( V_36 -> V_55 ) {
V_57 = V_36 -> V_89 ( V_36 ) ;
if ( ! V_57 )
V_36 -> V_55 = false ;
}
return V_57 ;
}
static int F_52 ( struct V_35 * V_36 , T_4 V_68 ,
struct V_43 * V_90 )
{
memcpy ( V_90 , V_36 -> V_7 . V_68 + V_68 , sizeof( * V_90 ) ) ;
return 0 ;
}
static int F_53 ( struct V_35 * V_36 , T_4 V_68 ,
struct V_43 * V_90 )
{
V_36 -> V_55 = true ;
memcpy ( V_36 -> V_7 . V_68 + V_68 , V_90 , sizeof( * V_90 ) ) ;
return 0 ;
}
static int F_54 ( struct V_35 * V_36 )
{
int V_57 ;
struct V_3 * V_4 ;
V_57 = F_27 ( V_36 -> V_38 , & V_91 , & V_4 ) ;
if ( V_57 < 0 )
return V_57 ;
memcpy ( F_2 ( V_4 ) , & V_36 -> V_7 , sizeof( V_36 -> V_7 ) ) ;
V_36 -> V_53 = F_4 ( V_4 ) ;
return F_28 ( V_36 -> V_38 , V_4 ) ;
}
static int F_55 ( struct V_35 * V_36 )
{
int V_57 ;
struct V_3 * V_92 ;
V_57 = F_31 ( V_36 -> V_38 , V_36 -> V_53 ,
& V_91 , & V_92 ) ;
if ( V_57 )
return V_57 ;
memcpy ( & V_36 -> V_7 , F_2 ( V_92 ) , sizeof( V_36 -> V_7 ) ) ;
return F_28 ( V_36 -> V_38 , V_92 ) ;
}
static T_4 F_56 ( struct V_35 * V_36 )
{
return V_93 ;
}
static int F_57 ( struct V_35 * V_36 )
{
int V_57 , V_44 ;
struct V_3 * V_4 ;
V_57 = F_39 ( V_36 -> V_38 , V_36 -> V_53 , & V_91 , & V_4 , & V_44 ) ;
if ( V_57 )
return V_57 ;
memcpy ( F_2 ( V_4 ) , & V_36 -> V_7 , sizeof( V_36 -> V_7 ) ) ;
V_36 -> V_53 = F_4 ( V_4 ) ;
return F_28 ( V_36 -> V_38 , V_4 ) ;
}
int F_58 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
int V_57 ;
V_57 = F_21 ( V_36 , V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
V_36 -> V_71 = F_52 ;
V_36 -> V_67 = F_53 ;
V_36 -> V_94 = F_54 ;
V_36 -> V_95 = F_55 ;
V_36 -> V_62 = F_56 ;
V_36 -> V_89 = F_57 ;
V_36 -> V_52 = 0 ;
V_36 -> V_87 = 0 ;
V_57 = V_36 -> V_94 ( V_36 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_59 ( & V_36 -> V_47 , & V_36 -> V_54 ) ;
if ( V_57 < 0 )
return V_57 ;
return 0 ;
}
int F_60 ( struct V_35 * V_36 , struct V_37 * V_38 ,
void * V_96 , T_1 V_97 )
{
int V_57 ;
struct V_98 * V_99 = V_96 ;
if ( V_97 < sizeof( struct V_98 ) ) {
F_24 ( L_10 ) ;
return - V_100 ;
}
V_57 = F_21 ( V_36 , V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
V_36 -> V_71 = F_52 ;
V_36 -> V_67 = F_53 ;
V_36 -> V_94 = F_54 ;
V_36 -> V_95 = F_55 ;
V_36 -> V_62 = F_56 ;
V_36 -> V_89 = F_57 ;
V_36 -> V_52 = F_8 ( V_99 -> V_52 ) ;
V_36 -> V_87 = F_8 ( V_99 -> V_87 ) ;
V_36 -> V_53 = F_8 ( V_99 -> V_53 ) ;
V_36 -> V_54 = F_8 ( V_99 -> V_54 ) ;
return V_36 -> V_95 ( V_36 ) ;
}
static int F_61 ( struct V_35 * V_36 , T_4 V_68 ,
struct V_43 * V_90 )
{
return F_33 ( & V_36 -> V_39 , V_36 -> V_53 , & V_68 , V_90 ) ;
}
static int F_62 ( struct V_35 * V_36 , T_4 V_68 ,
struct V_43 * V_90 )
{
F_41 ( V_90 ) ;
return F_42 ( & V_36 -> V_39 , V_36 -> V_53 ,
& V_68 , V_90 , & V_36 -> V_53 ) ;
}
static int F_63 ( struct V_35 * V_36 )
{
return F_59 ( & V_36 -> V_39 , & V_36 -> V_53 ) ;
}
static int F_64 ( struct V_35 * V_36 )
{
return 0 ;
}
static T_4 F_65 ( struct V_35 * V_36 )
{
return - 1ULL ;
}
static int F_66 ( struct V_35 * V_36 )
{
return 0 ;
}
int F_67 ( struct V_35 * V_36 , struct V_37 * V_38 )
{
int V_57 ;
V_57 = F_21 ( V_36 , V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
V_36 -> V_71 = F_61 ;
V_36 -> V_67 = F_62 ;
V_36 -> V_94 = F_63 ;
V_36 -> V_95 = F_64 ;
V_36 -> V_62 = F_65 ;
V_36 -> V_89 = F_66 ;
V_36 -> V_52 = 0 ;
V_36 -> V_87 = 0 ;
V_57 = V_36 -> V_94 ( V_36 ) ;
if ( V_57 < 0 )
return V_57 ;
V_57 = F_59 ( & V_36 -> V_47 , & V_36 -> V_54 ) ;
if ( V_57 < 0 )
return V_57 ;
return 0 ;
}
int F_68 ( struct V_35 * V_36 , struct V_37 * V_38 ,
void * V_96 , T_1 V_97 )
{
int V_57 ;
struct V_98 * V_99 = V_96 ;
if ( V_97 < sizeof( struct V_98 ) ) {
F_24 ( L_10 ) ;
return - V_100 ;
}
V_57 = F_21 ( V_36 , V_38 ) ;
if ( V_57 < 0 )
return V_57 ;
V_36 -> V_71 = F_61 ;
V_36 -> V_67 = F_62 ;
V_36 -> V_94 = F_63 ;
V_36 -> V_95 = F_64 ;
V_36 -> V_62 = F_65 ;
V_36 -> V_89 = F_66 ;
V_36 -> V_52 = F_8 ( V_99 -> V_52 ) ;
V_36 -> V_87 = F_8 ( V_99 -> V_87 ) ;
V_36 -> V_53 = F_8 ( V_99 -> V_53 ) ;
V_36 -> V_54 = F_8 ( V_99 -> V_54 ) ;
return V_36 -> V_95 ( V_36 ) ;
}
