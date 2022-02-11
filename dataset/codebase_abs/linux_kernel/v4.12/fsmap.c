void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
V_4 -> V_7 = V_6 -> V_7 ;
V_4 -> V_8 = V_6 -> V_8 ;
V_4 -> V_9 = V_6 -> V_9 << V_2 -> V_10 ;
V_4 -> V_11 = V_6 -> V_11 ;
V_4 -> V_12 = 0 ;
V_4 -> V_13 = V_6 -> V_13 << V_2 -> V_10 ;
V_4 -> V_14 [ 0 ] = 0 ;
V_4 -> V_14 [ 1 ] = 0 ;
V_4 -> V_14 [ 2 ] = 0 ;
}
void F_2 ( struct V_1 * V_2 , struct V_5 * V_4 ,
struct V_3 * V_6 )
{
V_4 -> V_7 = V_6 -> V_7 ;
V_4 -> V_8 = V_6 -> V_8 ;
V_4 -> V_9 = V_6 -> V_9 >> V_2 -> V_10 ;
V_4 -> V_11 = V_6 -> V_11 ;
V_4 -> V_13 = V_6 -> V_13 >> V_2 -> V_10 ;
}
static int F_3 ( const void * V_15 , const void * V_16 )
{
const struct V_17 * V_18 = V_15 ;
const struct V_17 * V_19 = V_16 ;
return V_18 -> V_20 - V_19 -> V_20 ;
}
static bool F_4 ( struct V_21 * V_22 ,
struct V_5 * V_23 )
{
return V_23 -> V_9 < V_22 -> V_24 . V_9 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_21 * V_22 ,
struct V_5 * V_23 )
{
struct V_5 V_25 ;
struct V_26 * V_27 = F_6 ( V_2 ) ;
T_1 V_28 = V_23 -> V_9 ;
T_2 V_29 ;
T_3 V_30 ;
int error ;
if ( F_7 ( V_31 ) )
return - V_32 ;
if ( F_4 ( V_22 , V_23 ) ) {
V_28 += V_23 -> V_13 ;
if ( V_22 -> V_33 < V_28 )
V_22 -> V_33 = V_28 ;
return V_34 ;
}
if ( V_22 -> V_35 -> V_36 == 0 ) {
if ( V_28 > V_22 -> V_33 )
V_22 -> V_35 -> V_37 ++ ;
if ( V_22 -> V_38 )
return V_34 ;
V_22 -> V_35 -> V_37 ++ ;
V_28 += V_23 -> V_13 ;
if ( V_22 -> V_33 < V_28 )
V_22 -> V_33 = V_28 ;
return V_34 ;
}
if ( V_28 > V_22 -> V_33 ) {
if ( V_22 -> V_35 -> V_37 >= V_22 -> V_35 -> V_36 )
return V_39 ;
F_8 ( V_2 , V_22 -> V_33 ,
& V_29 , & V_30 ) ;
F_9 ( V_2 , V_22 -> V_40 , V_29 ,
F_10 ( V_27 , V_30 ) ,
V_28 - V_22 -> V_33 ,
V_41 ) ;
V_25 . V_7 = V_22 -> V_40 ;
V_25 . V_9 = V_22 -> V_33 ;
V_25 . V_11 = V_41 ;
V_25 . V_13 = V_28 - V_22 -> V_33 ;
V_25 . V_8 = V_42 ;
error = V_22 -> V_43 ( & V_25 , V_22 -> V_44 ) ;
if ( error )
return error ;
V_22 -> V_35 -> V_37 ++ ;
}
if ( V_22 -> V_38 )
goto V_45;
if ( V_22 -> V_35 -> V_37 >= V_22 -> V_35 -> V_36 )
return V_39 ;
F_8 ( V_2 , V_28 , & V_29 , & V_30 ) ;
F_9 ( V_2 , V_22 -> V_40 , V_29 , F_10 ( V_27 , V_30 ) ,
V_23 -> V_13 , V_23 -> V_11 ) ;
V_25 . V_7 = V_22 -> V_40 ;
V_25 . V_9 = V_28 ;
V_25 . V_11 = V_23 -> V_11 ;
V_25 . V_8 = V_42 ;
V_25 . V_13 = V_23 -> V_13 ;
error = V_22 -> V_43 ( & V_25 , V_22 -> V_44 ) ;
if ( error )
return error ;
V_22 -> V_35 -> V_37 ++ ;
V_45:
V_28 += V_23 -> V_13 ;
if ( V_22 -> V_33 < V_28 )
V_22 -> V_33 = V_28 ;
return V_34 ;
}
static inline T_1 F_11 ( struct V_5 * V_25 )
{
return V_25 -> V_9 + V_25 -> V_13 ;
}
static int F_12 ( struct V_1 * V_2 ,
T_2 V_29 , T_3 V_46 ,
T_3 V_47 , void * V_48 )
{
struct V_5 V_49 ;
struct V_21 * V_22 = V_48 ;
struct V_5 * V_50 ;
struct V_5 * V_51 ;
struct V_26 * V_27 = F_6 ( V_2 ) ;
T_1 V_52 ;
T_1 V_53 ;
int error ;
V_52 = ( F_10 ( V_27 , V_46 ) + F_13 ( V_2 , V_29 ) ) ;
V_53 = F_10 ( V_27 , V_47 ) ;
if ( V_22 -> V_54 . V_11 ) {
if ( F_11 ( & V_22 -> V_54 ) == V_52 ) {
V_22 -> V_54 . V_13 += V_53 ;
return 0 ;
}
error = F_5 ( V_2 , V_22 , & V_22 -> V_54 ) ;
if ( error )
return error ;
V_22 -> V_54 . V_11 = 0 ;
}
F_14 (p, tmp, &info->gfi_meta_list, fmr_list) {
if ( V_50 -> V_9 + V_50 -> V_13 <= V_22 -> V_33 ) {
F_15 ( & V_50 -> V_55 ) ;
F_16 ( V_50 ) ;
} else if ( V_50 -> V_9 < V_52 ) {
error = F_5 ( V_2 , V_22 , V_50 ) ;
if ( error )
return error ;
F_15 ( & V_50 -> V_55 ) ;
F_16 ( V_50 ) ;
}
}
V_49 . V_7 = 0 ;
V_49 . V_9 = V_52 ;
V_49 . V_13 = V_53 ;
V_49 . V_11 = V_56 ;
V_49 . V_8 = 0 ;
if ( F_11 ( & V_49 ) ==
F_13 ( V_2 , V_29 + 1 ) ) {
V_22 -> V_54 = V_49 ;
return 0 ;
}
return F_5 ( V_2 , V_22 , & V_49 ) ;
}
static int F_17 ( struct V_1 * V_2 , struct V_5 * V_57 ,
struct V_21 * V_22 )
{
T_4 * V_58 = F_6 ( V_2 ) -> V_59 ;
struct V_5 V_49 ;
V_22 -> V_24 = V_57 [ 0 ] ;
V_22 -> V_24 . V_13 = 0 ;
memset ( & V_22 -> V_60 , 0xFF , sizeof( V_22 -> V_60 ) ) ;
F_18 ( V_2 , V_22 -> V_40 , 0 ,
V_22 -> V_24 . V_9 ,
V_22 -> V_24 . V_13 ,
V_22 -> V_24 . V_11 ) ;
F_19 ( V_2 , V_22 -> V_40 , 0 ,
V_22 -> V_60 . V_9 ,
V_22 -> V_60 . V_13 ,
V_22 -> V_60 . V_11 ) ;
if ( V_57 [ 0 ] . V_9 > 0 )
return 0 ;
V_49 . V_9 = V_58 -> V_61 ;
V_49 . V_13 = V_58 -> V_62 ;
V_49 . V_11 = V_63 ;
V_49 . V_8 = 0 ;
return F_5 ( V_2 , V_22 , & V_49 ) ;
}
static inline int F_20 ( struct V_64 * V_65 ,
T_1 V_52 , T_1 V_47 ,
T_5 V_66 )
{
struct V_5 * V_67 ;
V_67 = F_21 ( sizeof( * V_67 ) , V_68 ) ;
if ( ! V_67 )
return - V_69 ;
V_67 -> V_7 = 0 ;
V_67 -> V_8 = 0 ;
V_67 -> V_9 = V_52 ;
V_67 -> V_11 = V_66 ;
V_67 -> V_13 = V_47 ;
F_22 ( & V_67 -> V_55 , V_65 ) ;
return 0 ;
}
static unsigned int F_23 ( struct V_1 * V_2 ,
T_2 V_29 ,
struct V_64 * V_65 )
{
struct V_26 * V_27 = F_6 ( V_2 ) ;
T_1 V_52 = F_13 ( V_2 , V_29 ) ;
T_1 V_47 ;
unsigned long V_70 = F_24 ( V_27 -> V_71 -> V_72 ) ;
unsigned long V_73 = V_29 / F_25 ( V_2 ) ;
int error ;
if ( F_26 ( V_2 , V_29 ) ) {
error = F_20 ( V_65 , V_52 , 1 , V_74 ) ;
if ( error )
return error ;
V_52 ++ ;
}
V_47 = F_27 ( V_2 , V_29 ) ;
if ( ! V_47 )
return 0 ;
error = F_20 ( V_65 , V_52 , V_47 ,
V_75 ) ;
if ( error )
return error ;
V_52 += V_47 ;
if ( ! F_28 ( V_2 ) || V_73 < V_70 ) {
V_47 = F_29 ( V_27 -> V_71 -> V_76 ) ;
error = F_20 ( V_65 , V_52 , V_47 ,
V_77 ) ;
if ( error )
return error ;
}
return 0 ;
}
static int F_30 ( void * V_48 ,
struct V_64 * V_78 ,
struct V_64 * V_79 )
{
struct V_5 * V_80 ;
struct V_5 * V_81 ;
V_80 = F_31 ( V_78 , struct V_5 , V_55 ) ;
V_81 = F_31 ( V_79 , struct V_5 , V_55 ) ;
if ( V_80 -> V_9 < V_81 -> V_9 )
return - 1 ;
else if ( V_80 -> V_9 > V_81 -> V_9 )
return 1 ;
return 0 ;
}
static void F_32 ( struct V_64 * V_65 )
{
struct V_5 * V_50 ;
struct V_5 * V_82 = NULL ;
struct V_5 * V_51 ;
F_14 (p, tmp, meta_list, fmr_list) {
if ( ! V_82 ) {
V_82 = V_50 ;
continue;
}
if ( V_82 -> V_11 == V_50 -> V_11 &&
V_82 -> V_9 + V_82 -> V_13 == V_50 -> V_9 ) {
V_82 -> V_13 += V_50 -> V_13 ;
F_15 ( & V_50 -> V_55 ) ;
F_16 ( V_50 ) ;
} else
V_82 = V_50 ;
}
}
static void F_33 ( struct V_64 * V_65 )
{
struct V_5 * V_50 ;
struct V_5 * V_51 ;
F_14 (p, tmp, meta_list, fmr_list) {
F_15 ( & V_50 -> V_55 ) ;
F_16 ( V_50 ) ;
}
}
int F_34 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_83 * V_84 ;
T_2 V_29 ;
int error ;
F_35 ( V_65 ) ;
for ( V_29 = 0 ; V_29 < F_6 ( V_2 ) -> V_85 ; V_29 ++ ) {
V_84 = F_36 ( V_2 , V_29 , NULL ) ;
if ( ! V_84 ) {
error = - V_86 ;
goto V_87;
}
error = F_23 ( V_2 , V_29 , V_65 ) ;
if ( error )
goto V_87;
error = F_20 ( V_65 ,
F_37 ( V_2 , V_84 ) , 1 ,
V_88 ) ;
if ( error )
goto V_87;
error = F_20 ( V_65 ,
F_38 ( V_2 , V_84 ) , 1 ,
V_89 ) ;
if ( error )
goto V_87;
error = F_20 ( V_65 ,
F_39 ( V_2 , V_84 ) ,
F_6 ( V_2 ) -> V_90 ,
V_91 ) ;
if ( error )
goto V_87;
}
F_40 ( NULL , V_65 , F_30 ) ;
F_32 ( V_65 ) ;
return 0 ;
V_87:
F_33 ( V_65 ) ;
return error ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_5 * V_57 ,
struct V_21 * V_22 )
{
struct V_26 * V_27 = F_6 ( V_2 ) ;
T_1 V_92 ;
T_1 V_93 ;
T_1 V_94 ;
T_2 V_95 ;
T_2 V_96 ;
T_3 V_97 ;
T_3 V_98 ;
int error = 0 ;
V_94 = F_42 ( V_27 -> V_71 ) ;
if ( V_57 [ 0 ] . V_9 >= V_94 )
return 0 ;
if ( V_57 [ 1 ] . V_9 >= V_94 )
V_57 [ 1 ] . V_9 = V_94 - 1 ;
V_92 = V_57 [ 0 ] . V_9 ;
V_93 = V_57 [ 1 ] . V_9 ;
F_8 ( V_2 , V_92 , & V_95 , & V_97 ) ;
F_8 ( V_2 , V_93 , & V_96 , & V_98 ) ;
V_22 -> V_24 = V_57 [ 0 ] ;
V_22 -> V_24 . V_9 = F_10 ( V_27 , V_97 ) ;
V_22 -> V_24 . V_13 = 0 ;
memset ( & V_22 -> V_60 , 0xFF , sizeof( V_22 -> V_60 ) ) ;
error = F_34 ( V_2 , & V_22 -> V_99 ) ;
if ( error )
goto V_87;
for ( V_22 -> V_100 = V_95 ;
V_22 -> V_100 <= V_96 ;
V_22 -> V_100 ++ ) {
if ( V_22 -> V_100 == V_96 ) {
V_22 -> V_60 = V_57 [ 1 ] ;
V_22 -> V_60 . V_9 = F_10 ( V_27 ,
V_98 ) ;
V_22 -> V_60 . V_13 = 0 ;
}
F_18 ( V_2 , V_22 -> V_40 , V_22 -> V_100 ,
V_22 -> V_24 . V_9 ,
V_22 -> V_24 . V_13 ,
V_22 -> V_24 . V_11 ) ;
F_19 ( V_2 , V_22 -> V_40 , V_22 -> V_100 ,
V_22 -> V_60 . V_9 ,
V_22 -> V_60 . V_13 ,
V_22 -> V_60 . V_11 ) ;
error = F_43 ( V_2 , V_22 -> V_100 ,
F_44 ( V_27 , V_22 -> V_24 . V_9 ) ,
F_44 ( V_27 , V_22 -> V_60 . V_9 ) ,
F_12 , V_22 ) ;
if ( error )
goto V_87;
if ( V_22 -> V_100 == V_95 )
memset ( & V_22 -> V_24 , 0 , sizeof( V_22 -> V_24 ) ) ;
}
if ( V_22 -> V_54 . V_11 ) {
error = F_5 ( V_2 , V_22 , & V_22 -> V_54 ) ;
if ( error )
goto V_87;
}
V_22 -> V_38 = true ;
error = F_12 ( V_2 , V_96 , V_98 , 0 , V_22 ) ;
if ( error )
goto V_87;
V_87:
F_33 ( & V_22 -> V_99 ) ;
return error ;
}
static bool F_45 ( struct V_1 * V_2 ,
struct V_5 * V_101 )
{
if ( V_101 -> V_7 == 0 || V_101 -> V_7 == V_102 ||
V_101 -> V_7 == F_46 ( V_2 -> V_103 -> V_104 ) )
return true ;
if ( F_6 ( V_2 ) -> V_105 &&
V_101 -> V_7 == F_46 ( F_6 ( V_2 ) -> V_105 -> V_104 ) )
return true ;
return false ;
}
static bool F_47 ( struct V_5 * V_106 ,
struct V_5 * V_107 )
{
if ( V_106 -> V_7 > V_107 -> V_7 )
return false ;
if ( V_106 -> V_7 < V_107 -> V_7 )
return true ;
if ( V_106 -> V_9 > V_107 -> V_9 )
return false ;
if ( V_106 -> V_9 < V_107 -> V_9 )
return true ;
if ( V_106 -> V_11 > V_107 -> V_11 )
return false ;
if ( V_106 -> V_11 < V_107 -> V_11 )
return true ;
return false ;
}
int F_48 ( struct V_1 * V_2 , struct V_108 * V_109 ,
T_6 V_110 , void * V_111 )
{
struct V_5 V_112 [ 2 ] ;
struct V_17 V_113 [ V_114 ] ;
struct V_21 V_22 = { 0 } ;
int V_115 ;
int error = 0 ;
if ( V_109 -> V_116 & ~ V_117 )
return - V_118 ;
if ( ! F_45 ( V_2 , & V_109 -> V_119 [ 0 ] ) ||
! F_45 ( V_2 , & V_109 -> V_119 [ 1 ] ) )
return - V_118 ;
V_109 -> V_37 = 0 ;
memset ( V_113 , 0 , sizeof( V_113 ) ) ;
V_113 [ 0 ] . V_20 = F_46 ( V_2 -> V_103 -> V_104 ) ;
V_113 [ 0 ] . V_120 = F_41 ;
if ( F_6 ( V_2 ) -> V_105 ) {
V_113 [ 1 ] . V_20 = F_46 (
F_6 ( V_2 ) -> V_105 -> V_104 ) ;
V_113 [ 1 ] . V_120 = F_17 ;
}
F_49 ( V_113 , V_114 , sizeof( struct V_17 ) ,
F_3 , NULL ) ;
V_112 [ 0 ] = V_109 -> V_119 [ 0 ] ;
V_112 [ 0 ] . V_9 += V_112 [ 0 ] . V_13 ;
V_112 [ 0 ] . V_11 = 0 ;
V_112 [ 0 ] . V_13 = 0 ;
memset ( & V_112 [ 1 ] , 0xFF , sizeof( struct V_5 ) ) ;
if ( ! F_47 ( V_112 , & V_109 -> V_119 [ 1 ] ) )
return - V_118 ;
V_22 . V_33 = V_109 -> V_119 [ 0 ] . V_9 +
V_109 -> V_119 [ 0 ] . V_13 ;
V_22 . V_43 = V_110 ;
V_22 . V_44 = V_111 ;
V_22 . V_35 = V_109 ;
for ( V_115 = 0 ; V_115 < V_114 ; V_115 ++ ) {
if ( ! V_113 [ V_115 ] . V_120 )
continue;
if ( V_109 -> V_119 [ 0 ] . V_7 > V_113 [ V_115 ] . V_20 )
continue;
if ( V_109 -> V_119 [ 1 ] . V_7 < V_113 [ V_115 ] . V_20 )
break;
if ( V_113 [ V_115 ] . V_20 == V_109 -> V_119 [ 1 ] . V_7 )
V_112 [ 1 ] = V_109 -> V_119 [ 1 ] ;
if ( V_113 [ V_115 ] . V_20 > V_109 -> V_119 [ 0 ] . V_7 )
memset ( & V_112 [ 0 ] , 0 , sizeof( struct V_5 ) ) ;
V_22 . V_40 = V_113 [ V_115 ] . V_20 ;
V_22 . V_38 = false ;
V_22 . V_100 = - 1 ;
error = V_113 [ V_115 ] . V_120 ( V_2 , V_112 , & V_22 ) ;
if ( error )
break;
V_22 . V_33 = 0 ;
}
V_109 -> V_121 = V_122 ;
return error ;
}
