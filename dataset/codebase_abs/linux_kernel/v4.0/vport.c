int F_1 ( void )
{
V_1 = F_2 ( V_2 * sizeof( struct V_3 ) ,
V_4 ) ;
if ( ! V_1 )
return - V_5 ;
return 0 ;
}
void F_3 ( void )
{
F_4 ( V_1 ) ;
}
static struct V_3 * F_5 ( const struct V_6 * V_6 , const char * V_7 )
{
unsigned int V_8 = F_6 ( V_7 , strlen ( V_7 ) , ( unsigned long ) V_6 ) ;
return & V_1 [ V_8 & ( V_2 - 1 ) ] ;
}
int F_7 ( struct V_9 * V_10 )
{
int V_11 = - V_12 ;
struct V_9 * V_13 ;
F_8 () ;
F_9 (o, &vport_ops_list, list)
if ( V_10 -> type == V_13 -> type )
goto V_14;
F_10 ( & V_10 -> V_15 , & V_16 ) ;
V_11 = 0 ;
V_14:
F_11 () ;
return V_11 ;
}
void F_12 ( struct V_9 * V_10 )
{
F_8 () ;
F_13 ( & V_10 -> V_15 ) ;
F_11 () ;
}
struct V_17 * F_14 ( const struct V_6 * V_6 , const char * V_7 )
{
struct V_3 * V_18 = F_5 ( V_6 , V_7 ) ;
struct V_17 * V_17 ;
F_15 (vport, bucket, hash_node)
if ( ! strcmp ( V_7 , V_17 -> V_10 -> V_19 ( V_17 ) ) &&
F_16 ( F_17 ( V_17 -> V_20 ) , V_6 ) )
return V_17 ;
return NULL ;
}
struct V_17 * F_18 ( int V_21 , const struct V_9 * V_10 ,
const struct V_22 * V_23 )
{
struct V_17 * V_17 ;
T_1 V_24 ;
V_24 = sizeof( struct V_17 ) ;
if ( V_21 ) {
V_24 = F_19 ( V_24 , V_25 ) ;
V_24 += V_21 ;
}
V_17 = F_2 ( V_24 , V_4 ) ;
if ( ! V_17 )
return F_20 ( - V_5 ) ;
V_17 -> V_20 = V_23 -> V_20 ;
V_17 -> V_26 = V_23 -> V_26 ;
V_17 -> V_10 = V_10 ;
F_21 ( & V_17 -> V_27 ) ;
if ( F_22 ( V_17 , V_23 -> V_28 ) ) {
F_4 ( V_17 ) ;
return F_20 ( - V_29 ) ;
}
V_17 -> V_30 = F_23 ( struct V_31 ) ;
if ( ! V_17 -> V_30 ) {
F_4 ( V_17 ) ;
return F_20 ( - V_5 ) ;
}
return V_17 ;
}
void F_24 ( struct V_17 * V_17 )
{
F_4 ( F_25 ( V_17 -> V_28 ) ) ;
F_26 ( V_17 -> V_30 ) ;
F_4 ( V_17 ) ;
}
static struct V_9 * F_27 ( const struct V_22 * V_23 )
{
struct V_9 * V_10 ;
F_9 (ops, &vport_ops_list, list)
if ( V_10 -> type == V_23 -> type )
return V_10 ;
return NULL ;
}
struct V_17 * F_28 ( const struct V_22 * V_23 )
{
struct V_9 * V_10 ;
struct V_17 * V_17 ;
V_10 = F_27 ( V_23 ) ;
if ( V_10 ) {
struct V_3 * V_18 ;
if ( ! F_29 ( V_10 -> V_32 ) )
return F_20 ( - V_33 ) ;
V_17 = V_10 -> V_34 ( V_23 ) ;
if ( F_30 ( V_17 ) ) {
F_31 ( V_10 -> V_32 ) ;
return V_17 ;
}
V_18 = F_5 ( F_17 ( V_17 -> V_20 ) ,
V_17 -> V_10 -> V_19 ( V_17 ) ) ;
F_32 ( & V_17 -> V_35 , V_18 ) ;
return V_17 ;
}
F_11 () ;
F_33 ( L_1 , V_23 -> type ) ;
F_8 () ;
if ( ! F_27 ( V_23 ) )
return F_20 ( - V_33 ) ;
else
return F_20 ( - V_36 ) ;
}
int F_34 ( struct V_17 * V_17 , struct V_37 * V_38 )
{
if ( ! V_17 -> V_10 -> V_39 )
return - V_40 ;
return V_17 -> V_10 -> V_39 ( V_17 , V_38 ) ;
}
void F_35 ( struct V_17 * V_17 )
{
F_36 () ;
F_37 ( & V_17 -> V_35 ) ;
F_31 ( V_17 -> V_10 -> V_32 ) ;
V_17 -> V_10 -> V_41 ( V_17 ) ;
}
void F_38 ( struct V_17 * V_17 , struct V_42 * V_43 )
{
int V_44 ;
memset ( V_43 , 0 , sizeof( * V_43 ) ) ;
V_43 -> V_45 = F_39 ( & V_17 -> V_46 . V_45 ) ;
V_43 -> V_47 = F_39 ( & V_17 -> V_46 . V_47 ) ;
V_43 -> V_48 = F_39 ( & V_17 -> V_46 . V_48 ) ;
V_43 -> V_49 = F_39 ( & V_17 -> V_46 . V_49 ) ;
F_40 (i) {
const struct V_31 * V_30 ;
struct V_31 V_50 ;
unsigned int V_51 ;
V_30 = F_41 ( V_17 -> V_30 , V_44 ) ;
do {
V_51 = F_42 ( & V_30 -> V_52 ) ;
V_50 = * V_30 ;
} while ( F_43 ( & V_30 -> V_52 , V_51 ) );
V_43 -> V_53 += V_50 . V_53 ;
V_43 -> V_54 += V_50 . V_54 ;
V_43 -> V_55 += V_50 . V_55 ;
V_43 -> V_56 += V_50 . V_56 ;
}
}
int F_44 ( const struct V_17 * V_17 , struct V_57 * V_58 )
{
struct V_37 * V_59 ;
int V_11 ;
if ( ! V_17 -> V_10 -> V_60 )
return 0 ;
V_59 = F_45 ( V_58 , V_61 ) ;
if ( ! V_59 )
return - V_62 ;
V_11 = V_17 -> V_10 -> V_60 ( V_17 , V_58 ) ;
if ( V_11 ) {
F_46 ( V_58 , V_59 ) ;
return V_11 ;
}
F_47 ( V_58 , V_59 ) ;
return 0 ;
}
int F_22 ( struct V_17 * V_17 , const struct V_37 * V_63 )
{
struct V_64 * V_65 , * V_64 ;
if ( ! F_48 ( V_63 ) || F_48 ( V_63 ) % sizeof( V_66 ) )
return - V_29 ;
V_65 = F_49 ( V_17 -> V_28 ) ;
V_64 = F_50 ( sizeof( * V_64 ) + F_48 ( V_63 ) ,
V_4 ) ;
if ( ! V_64 )
return - V_5 ;
V_64 -> V_67 = F_48 ( V_63 ) / sizeof( V_66 ) ;
V_64 -> V_68 = F_51 ( V_64 -> V_67 ) ;
F_52 ( V_64 -> V_63 , V_63 , F_48 ( V_63 ) ) ;
F_53 ( V_17 -> V_28 , V_64 ) ;
if ( V_65 )
F_54 ( V_65 , V_69 ) ;
return 0 ;
}
int F_55 ( const struct V_17 * V_17 ,
struct V_57 * V_58 )
{
struct V_64 * V_63 ;
V_63 = F_56 ( V_17 -> V_28 ) ;
if ( V_17 -> V_20 -> V_70 & V_71 )
return F_57 ( V_58 , V_72 ,
V_63 -> V_67 * sizeof( V_66 ) , ( void * ) V_63 -> V_63 ) ;
else
return F_58 ( V_58 , V_72 , V_63 -> V_63 [ 0 ] ) ;
}
V_66 F_59 ( const struct V_17 * V_17 , struct V_57 * V_58 )
{
struct V_64 * V_63 ;
V_66 V_73 ;
V_66 V_8 ;
V_63 = F_60 ( V_17 -> V_28 ) ;
if ( V_63 -> V_67 == 1 && V_63 -> V_63 [ 0 ] == 0 )
return 0 ;
V_8 = F_61 ( V_58 ) ;
V_73 = V_8 - V_63 -> V_67 * F_62 ( V_8 , V_63 -> V_68 ) ;
return V_63 -> V_63 [ V_73 ] ;
}
void F_63 ( struct V_17 * V_17 , struct V_57 * V_58 ,
const struct V_74 * V_75 )
{
struct V_31 * V_43 ;
struct V_76 V_77 ;
int error ;
V_43 = F_64 ( V_17 -> V_30 ) ;
F_65 ( & V_43 -> V_52 ) ;
V_43 -> V_54 ++ ;
V_43 -> V_53 += V_58 -> V_78 +
( F_66 ( V_58 ) ? V_79 : 0 ) ;
F_67 ( & V_43 -> V_52 ) ;
F_68 ( V_58 ) -> V_80 = V_17 ;
F_68 ( V_58 ) -> V_81 = NULL ;
error = F_69 ( V_75 , V_58 , & V_77 ) ;
if ( F_70 ( error ) ) {
F_71 ( V_58 ) ;
return;
}
F_72 ( V_58 , & V_77 ) ;
}
int F_73 ( struct V_17 * V_17 , struct V_57 * V_58 )
{
int V_82 = V_17 -> V_10 -> V_83 ( V_17 , V_58 ) ;
if ( F_74 ( V_82 > 0 ) ) {
struct V_31 * V_43 ;
V_43 = F_64 ( V_17 -> V_30 ) ;
F_65 ( & V_43 -> V_52 ) ;
V_43 -> V_56 ++ ;
V_43 -> V_55 += V_82 ;
F_67 ( & V_43 -> V_52 ) ;
} else if ( V_82 < 0 ) {
F_75 ( V_17 , V_84 ) ;
} else {
F_75 ( V_17 , V_85 ) ;
}
return V_82 ;
}
static void F_75 ( struct V_17 * V_17 ,
enum V_86 V_87 )
{
switch ( V_87 ) {
case V_88 :
F_76 ( & V_17 -> V_46 . V_49 ) ;
break;
case V_89 :
F_76 ( & V_17 -> V_46 . V_45 ) ;
break;
case V_85 :
F_76 ( & V_17 -> V_46 . V_48 ) ;
break;
case V_84 :
F_76 ( & V_17 -> V_46 . V_47 ) ;
break;
}
}
static void F_77 ( struct V_90 * V_69 )
{
struct V_17 * V_17 = F_78 ( V_69 , struct V_17 , V_69 ) ;
F_24 ( V_17 ) ;
}
void F_79 ( struct V_17 * V_17 )
{
if ( ! V_17 )
return;
F_80 ( & V_17 -> V_69 , F_77 ) ;
}
int F_81 ( struct V_74 * V_81 ,
struct V_6 * V_6 ,
const struct V_74 * V_75 ,
T_2 V_91 ,
V_66 V_92 ,
T_3 V_93 ,
T_3 V_94 )
{
const struct V_95 * V_96 ;
struct V_97 * V_98 ;
struct V_99 V_100 ;
if ( F_70 ( ! V_75 ) )
return - V_29 ;
V_96 = & V_75 -> V_101 ;
V_98 = F_82 ( V_6 , V_96 , V_92 , & V_100 , V_91 ) ;
if ( F_30 ( V_98 ) )
return F_83 ( V_98 ) ;
F_84 ( V_98 ) ;
F_85 ( V_81 ,
V_100 . V_102 , V_96 -> V_103 ,
V_96 -> V_104 ,
V_96 -> V_105 ,
V_93 , V_94 ,
V_96 -> V_106 ,
V_96 -> V_107 ,
V_75 -> V_38 ,
V_75 -> V_108 ) ;
return 0 ;
}
int F_86 ( struct V_17 * V_17 , struct V_57 * V_58 ,
struct V_74 * V_109 )
{
if ( F_70 ( ! V_17 -> V_10 -> V_110 ) )
return - V_29 ;
return V_17 -> V_10 -> V_110 ( V_17 , V_58 , V_109 ) ;
}
