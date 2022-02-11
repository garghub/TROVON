static void
F_1 ( struct V_1 * V_2 , char * V_3 , ... )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 V_8 ;
T_1 V_9 ;
if ( ! ( * V_10 & V_11 ) )
return;
va_start ( V_9 , V_3 ) ;
V_8 . V_3 = V_3 ;
V_8 . V_9 = & V_9 ;
F_2 ( V_12 L_1 , V_5 -> V_13 . V_14 -> V_15 -> V_16 , & V_8 ) ;
va_end ( V_9 ) ;
}
static void
F_3 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( V_2 -> V_19 == V_20 )
F_4 ( & V_5 -> V_21 , 1 ) ;
F_5 ( V_2 , V_22 ) ;
}
static void
F_6 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
F_5 ( V_2 , V_23 ) ;
}
static void
F_7 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_24 * V_25 ;
T_2 V_26 ;
F_8 ( & V_5 -> V_27 , V_26 ) ;
F_9 (l2, &mgr->layer2, list) {
if ( V_25 -> V_28 . V_19 > V_29 ) {
F_10 ( & V_5 -> V_27 , V_26 ) ;
return;
}
}
F_10 ( & V_5 -> V_27 , V_26 ) ;
if ( ! F_11 ( V_30 , & V_5 -> V_31 ) ) {
F_12 ( & V_5 -> V_21 , V_32 , V_33 ,
NULL , 1 ) ;
F_5 ( V_2 , V_20 ) ;
}
}
static void
F_13 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
if ( ! F_11 ( V_30 , & V_5 -> V_31 ) ) {
F_4 ( & V_5 -> V_21 , 2 ) ;
F_12 ( & V_5 -> V_21 , V_32 , V_33 ,
NULL , 2 ) ;
}
}
static void
F_14 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_24 * V_25 ;
T_2 V_26 ;
F_8 ( & V_5 -> V_27 , V_26 ) ;
F_9 (l2, &mgr->layer2, list) {
if ( V_25 -> V_28 . V_19 > V_29 ) {
F_10 ( & V_5 -> V_27 , V_26 ) ;
F_5 ( V_2 , V_22 ) ;
return;
}
}
F_10 ( & V_5 -> V_27 , V_26 ) ;
F_5 ( V_2 , V_23 ) ;
F_15 ( & V_5 -> V_13 , V_34 , V_35 , 0 , NULL ,
V_36 ) ;
}
static void
F_16 ( struct V_1 * V_2 , char * V_3 , ... )
{
struct V_37 * V_38 = V_2 -> V_6 ;
struct V_7 V_8 ;
T_1 V_9 ;
if ( ! ( * V_10 & V_11 ) )
return;
va_start ( V_9 , V_3 ) ;
V_8 . V_3 = V_3 ;
V_8 . V_9 = & V_9 ;
F_2 ( V_12 L_2 ,
V_38 -> V_25 -> V_39 , V_38 -> V_25 -> V_40 , & V_8 ) ;
va_end ( V_9 ) ;
}
static int
F_17 ( struct V_4 * V_5 )
{
F_18 ( V_41 , 64 ) = { [ 0 ... F_19 ( 64 ) - 1 ] = 0 } ;
int V_42 ;
struct V_24 * V_25 ;
F_9 (l2, &mgr->layer2, list) {
if ( V_25 -> V_13 . V_43 > 63 ) {
F_2 ( V_44
L_3 ,
V_45 ) ;
return - V_46 ;
}
F_20 ( V_25 -> V_13 . V_43 , V_41 ) ;
}
V_42 = F_21 ( V_41 , 64 , 1 ) ;
if ( V_42 < 64 )
return V_42 ;
F_2 ( V_44 L_3 ,
V_45 ) ;
return - V_46 ;
}
static int
F_22 ( struct V_4 * V_5 )
{
F_18 ( V_41 , 64 ) = { [ 0 ... F_19 ( 64 ) - 1 ] = 0 } ;
int V_42 ;
struct V_24 * V_25 ;
F_9 (l2, &mgr->layer2, list) {
if ( V_25 -> V_13 . V_43 == 0 )
continue;
if ( ( V_25 -> V_13 . V_47 & 0xff ) != 0 )
continue;
V_42 = V_25 -> V_13 . V_47 >> 8 ;
if ( V_42 < 64 )
continue;
V_42 -= 64 ;
F_20 ( V_42 , V_41 ) ;
}
V_42 = F_23 ( V_41 , 64 ) ;
if ( V_42 < 64 )
return V_42 + 64 ;
F_2 ( V_44 L_4 ,
V_45 ) ;
return - 1 ;
}
static void
F_24 ( struct V_4 * V_5 , T_3 V_48 , int V_49 , void * V_18 )
{
struct V_50 * V_51 ;
struct V_52 * V_53 ;
int V_54 ;
V_51 = F_25 ( V_49 , V_36 ) ;
if ( ! V_51 )
return;
V_53 = F_26 ( V_51 ) ;
V_53 -> V_48 = V_48 ;
V_53 -> V_16 = ( V_5 -> V_13 . V_43 << 16 ) | V_5 -> V_13 . V_47 ;
if ( V_49 )
memcpy ( F_27 ( V_51 , V_49 ) , V_18 , V_49 ) ;
V_54 = V_5 -> V_55 -> V_56 ( V_5 -> V_55 , V_51 ) ;
if ( V_54 ) {
F_2 ( V_44 L_5 , V_45 , V_54 ) ;
F_28 ( V_51 ) ;
}
}
static T_3
F_29 ( struct V_4 * V_5 )
{
T_3 V_16 ;
V_16 = V_5 -> V_57 ++ ;
if ( V_16 == 0x7fff )
V_5 -> V_57 = 1 ;
V_16 <<= 16 ;
V_16 |= V_58 << 8 ;
V_16 |= V_59 ;
return V_16 ;
}
static void
F_30 ( struct V_4 * V_5 )
{
if ( ! F_11 ( V_60 , & V_5 -> V_31 ) )
return;
if ( ! F_31 ( V_61 , & V_5 -> V_31 ) ) {
struct V_50 * V_51 = F_32 ( & V_5 -> V_62 ) ;
if ( ! V_51 ) {
F_33 ( V_61 , & V_5 -> V_31 ) ;
return;
}
V_5 -> V_63 = F_34 ( V_51 ) ;
F_35 ( & V_5 -> V_64 , V_65 , NULL ) ;
if ( V_5 -> V_13 . V_66 ( V_5 -> V_13 . V_67 , V_51 ) ) {
F_28 ( V_51 ) ;
F_33 ( V_61 , & V_5 -> V_31 ) ;
V_5 -> V_63 = V_68 ;
}
}
}
static void
F_36 ( struct V_4 * V_5 , T_3 V_16 )
{
if ( F_11 ( V_61 , & V_5 -> V_31 ) ) {
if ( V_16 == V_5 -> V_63 ) {
if ( F_11 ( V_60 , & V_5 -> V_31 ) ) {
struct V_50 * V_51 ;
V_51 = F_32 ( & V_5 -> V_62 ) ;
if ( V_51 ) {
V_5 -> V_63 = F_34 ( V_51 ) ;
if ( ! V_5 -> V_13 . V_66 ( V_5 -> V_13 . V_67 , V_51 ) )
return;
F_28 ( V_51 ) ;
}
}
V_5 -> V_63 = V_68 ;
F_33 ( V_61 , & V_5 -> V_31 ) ;
}
}
}
static void
F_37 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
F_38 ( & V_5 -> V_62 , V_51 ) ;
if ( ! F_11 ( V_60 , & V_5 -> V_31 ) ) {
F_15 ( & V_5 -> V_13 , V_69 , V_35 , 0 ,
NULL , V_70 ) ;
} else {
F_30 ( V_5 ) ;
}
}
static int
F_39 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
if ( ! F_11 ( V_71 , & V_5 -> V_31 ) )
return - V_72 ;
if ( ! F_11 ( V_60 , & V_5 -> V_31 ) )
F_15 ( & V_5 -> V_13 , V_69 , V_35 , 0 ,
NULL , V_70 ) ;
F_40 ( V_51 , 3 ) ;
V_51 -> V_73 [ 0 ] = 0x02 ;
V_51 -> V_73 [ 1 ] = 0xff ;
V_51 -> V_73 [ 2 ] = V_74 ;
F_41 ( V_51 ) = V_75 ;
F_34 ( V_51 ) = F_29 ( V_5 ) ;
F_38 ( & V_5 -> V_62 , V_51 ) ;
F_30 ( V_5 ) ;
return 0 ;
}
static unsigned int
F_42 ( void )
{
T_4 V_76 ;
F_43 ( & V_76 , sizeof( V_76 ) ) ;
return V_76 ;
}
static struct V_24 *
F_44 ( struct V_4 * V_5 , int V_40 )
{
struct V_24 * V_25 ;
T_2 V_26 ;
F_8 ( & V_5 -> V_27 , V_26 ) ;
F_9 (l2, &mgr->layer2, list) {
if ( ( V_25 -> V_39 == 0 ) && ( V_25 -> V_40 > 0 ) &&
( V_25 -> V_40 != V_58 ) && ( V_25 -> V_40 == V_40 ) )
goto V_77;
}
V_25 = NULL ;
V_77:
F_10 ( & V_5 -> V_27 , V_26 ) ;
return V_25 ;
}
static void
F_45 ( struct V_4 * V_5 , T_5 V_78 , unsigned int V_79 , int V_40 )
{
struct V_50 * V_51 ;
T_5 V_80 [ 8 ] ;
V_80 [ 0 ] = ( V_59 << 2 ) ;
if ( F_11 ( V_71 , & V_5 -> V_31 ) )
V_80 [ 0 ] |= 2 ;
V_80 [ 1 ] = ( V_58 << 1 ) | 0x1 ;
V_80 [ 2 ] = V_74 ;
V_80 [ 3 ] = V_81 ;
V_80 [ 4 ] = V_79 >> 8 ;
V_80 [ 5 ] = V_79 & 0xff ;
V_80 [ 6 ] = V_78 ;
V_80 [ 7 ] = ( ( V_40 << 1 ) & 0xff ) | 1 ;
V_51 = F_46 ( V_75 , F_29 ( V_5 ) , 8 , V_80 , V_36 ) ;
if ( ! V_51 ) {
F_2 ( V_44 L_6 , V_45 ) ;
return;
}
F_37 ( V_5 , V_51 ) ;
}
static void
F_47 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
if ( V_38 -> V_25 -> V_40 != V_58 ) {
V_38 -> V_82 . V_83 ( & V_38 -> V_82 ,
L_7 ,
V_38 -> V_25 -> V_40 ) ;
return;
}
V_38 -> V_79 = F_42 () ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( & V_38 -> V_82 ,
L_8 , V_38 -> V_79 ) ;
F_45 ( V_38 -> V_5 , V_85 , V_38 -> V_79 , V_58 ) ;
F_5 ( V_2 , V_86 ) ;
F_12 ( & V_38 -> V_87 , V_38 -> V_88 , V_89 , NULL , 1 ) ;
V_38 -> V_90 = 3 ;
}
static void
F_48 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
struct V_24 * V_25 ;
T_5 * V_91 = V_18 ;
int V_79 , V_40 ;
V_79 = ( ( unsigned int ) * V_91 ++ << 8 ) ;
V_79 += * V_91 ++ ;
V_91 ++ ;
V_40 = * V_91 >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_9 ,
V_79 , V_40 ) ;
V_25 = F_44 ( V_38 -> V_5 , V_40 ) ;
if ( V_25 ) {
if ( V_79 != V_25 -> V_38 -> V_79 ) {
V_38 -> V_82 . V_83 ( V_2 ,
L_10 , V_40 ) ;
F_49 ( V_25 , V_92 , 0 ) ;
}
} else if ( V_79 == V_38 -> V_79 ) {
F_4 ( & V_38 -> V_87 , 1 ) ;
F_5 ( V_2 , V_93 ) ;
F_49 ( V_38 -> V_25 , V_94 , V_40 ) ;
}
}
static void
F_50 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
struct V_24 * V_25 ;
T_5 * V_91 = V_18 ;
int V_40 , V_79 ;
V_79 = ( ( unsigned int ) * V_91 ++ << 8 ) ;
V_79 += * V_91 ++ ;
V_91 ++ ;
V_40 = * V_91 >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_11 ,
V_79 , V_40 ) ;
V_25 = F_44 ( V_38 -> V_5 , V_40 ) ;
if ( V_25 ) {
if ( V_79 != V_25 -> V_38 -> V_79 ) {
V_38 -> V_82 . V_83 ( V_2 ,
L_10 , V_40 ) ;
F_35 ( & V_25 -> V_38 -> V_82 , V_95 , NULL ) ;
}
}
}
static void
F_51 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
T_5 * V_91 = V_18 ;
int V_79 , V_40 ;
V_79 = ( ( unsigned int ) * V_91 ++ << 8 ) ;
V_79 += * V_91 ++ ;
V_91 ++ ;
V_40 = * V_91 >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_12 ,
V_79 , V_40 ) ;
}
static void
F_52 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
T_5 * V_91 = V_18 ;
int V_40 ;
V_40 = * ( V_91 + 3 ) >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_13 , V_40 ) ;
if ( ( V_38 -> V_25 -> V_40 != V_58 ) && ( ( V_40 == V_58 ) ||
( V_40 == V_38 -> V_25 -> V_40 ) ) ) {
F_4 ( & V_38 -> V_87 , 4 ) ;
F_5 ( & V_38 -> V_82 , V_93 ) ;
F_45 ( V_38 -> V_5 , V_96 , F_42 () , V_38 -> V_25 -> V_40 ) ;
}
}
static void
F_53 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
T_5 * V_91 = V_18 ;
int V_40 ;
V_40 = * ( V_91 + 3 ) >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_14 , V_40 ) ;
if ( ( V_38 -> V_25 -> V_40 != V_58 ) &&
( ( V_40 == V_58 ) || ( V_40 == V_38 -> V_25 -> V_40 ) ) ) {
F_4 ( & V_38 -> V_87 , 5 ) ;
F_5 ( & V_38 -> V_82 , V_93 ) ;
F_49 ( V_38 -> V_25 , V_97 , 0 ) ;
}
}
static void
F_54 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_15 ,
V_38 -> V_25 -> V_40 ) ;
F_45 ( V_38 -> V_5 , V_98 , 0 , V_38 -> V_25 -> V_40 ) ;
F_5 ( & V_38 -> V_82 , V_99 ) ;
F_12 ( & V_38 -> V_87 , V_38 -> V_88 , V_89 , NULL , 2 ) ;
V_38 -> V_90 = 2 ;
}
static void
F_55 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
if ( -- V_38 -> V_90 ) {
V_38 -> V_79 = F_42 () ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_16 ,
4 - V_38 -> V_90 , V_38 -> V_79 ) ;
F_45 ( V_38 -> V_5 , V_85 , V_38 -> V_79 , V_58 ) ;
F_12 ( & V_38 -> V_87 , V_38 -> V_88 , V_89 , NULL , 3 ) ;
} else {
V_38 -> V_82 . V_83 ( V_2 , L_17 ) ;
F_49 ( V_38 -> V_25 , V_92 , 0 ) ;
F_5 ( V_2 , V_93 ) ;
}
}
static void
F_56 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
if ( -- V_38 -> V_90 ) {
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 ,
L_18 ,
3 - V_38 -> V_90 , V_38 -> V_25 -> V_40 ) ;
F_45 ( V_38 -> V_5 , V_98 , 0 , V_38 -> V_25 -> V_40 ) ;
F_12 ( & V_38 -> V_87 , V_38 -> V_88 , V_89 , NULL , 4 ) ;
} else {
V_38 -> V_82 . V_83 ( V_2 , L_19 ,
V_38 -> V_25 -> V_40 ) ;
F_49 ( V_38 -> V_25 , V_97 , 0 ) ;
F_5 ( V_2 , V_93 ) ;
}
}
static void
F_57 ( struct V_24 * V_25 )
{
F_45 ( V_25 -> V_38 -> V_5 , V_100 , 0 , V_25 -> V_40 ) ;
F_49 ( V_25 , V_97 , 0 ) ;
F_58 ( & V_25 -> V_13 . V_101 ) ;
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_103 , NULL ) ;
}
static void
F_59 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
T_5 * V_91 = V_18 ;
if ( V_38 -> V_25 -> V_40 == V_58 ) {
V_38 -> V_82 . V_83 ( & V_38 -> V_82 ,
L_20 ) ;
return;
}
V_38 -> V_79 = ( ( unsigned int ) * V_91 ++ << 8 ) ;
V_38 -> V_79 += * V_91 ++ ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( & V_38 -> V_82 ,
L_21 , V_38 -> V_79 , * V_91 ) ;
F_45 ( V_38 -> V_5 , V_104 , V_38 -> V_79 , V_38 -> V_25 -> V_40 ) ;
F_5 ( V_2 , V_93 ) ;
}
static void
F_60 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_22 ,
V_38 -> V_25 -> V_40 ) ;
V_38 -> V_105 = 0 ;
F_45 ( V_38 -> V_5 , V_106 , 0 , V_38 -> V_25 -> V_40 ) ;
F_5 ( & V_38 -> V_82 , V_99 ) ;
F_12 ( & V_38 -> V_87 , V_38 -> V_88 , V_89 , NULL , 2 ) ;
V_38 -> V_90 = 2 ;
}
static void
F_61 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
T_5 * V_91 = V_18 ;
int V_40 ;
V_40 = V_91 [ 3 ] >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_23 , V_40 ) ;
if ( V_40 == V_38 -> V_25 -> V_40 )
V_38 -> V_105 ++ ;
}
static void
F_62 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
T_5 * V_91 = V_18 ;
int V_40 ;
V_40 = V_91 [ 3 ] >> 1 ;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 , L_24 ,
V_40 , V_38 -> V_25 -> V_40 ) ;
if ( V_40 == V_38 -> V_25 -> V_40 )
F_60 ( V_2 , V_17 , V_18 ) ;
}
static void
F_63 ( struct V_1 * V_2 , int V_17 , void * V_18 )
{
struct V_37 * V_38 = V_2 -> V_6 ;
if ( V_38 -> V_105 == 1 ) {
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 ,
L_25 , V_38 -> V_25 -> V_40 ) ;
F_5 ( V_2 , V_93 ) ;
} else if ( V_38 -> V_105 > 1 ) {
F_57 ( V_38 -> V_25 ) ;
} else if ( -- V_38 -> V_90 ) {
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( V_2 ,
L_26 ,
3 - V_38 -> V_90 , V_38 -> V_25 -> V_40 ) ;
F_45 ( V_38 -> V_5 , V_106 , 0 , V_38 -> V_25 -> V_40 ) ;
F_12 ( & V_38 -> V_87 , V_38 -> V_88 , V_89 , NULL , 4 ) ;
} else {
V_38 -> V_82 . V_83 ( V_2 , L_27 ,
V_38 -> V_25 -> V_40 ) ;
F_5 ( V_2 , V_93 ) ;
F_57 ( V_38 -> V_25 ) ;
}
}
static void
F_64 ( struct V_37 * V_38 , T_3 V_107 , T_5 * V_91 , int V_49 )
{
if ( F_11 ( V_108 , & V_38 -> V_25 -> V_109 ) )
return;
if ( * V_10 & V_84 )
V_38 -> V_82 . V_83 ( & V_38 -> V_82 , L_28 , V_107 ) ;
if ( V_107 == V_104 )
F_35 ( & V_38 -> V_82 , V_110 , V_91 ) ;
else if ( V_107 == V_111 )
F_35 ( & V_38 -> V_82 , V_112 , V_91 ) ;
else if ( V_107 == V_106 )
F_35 ( & V_38 -> V_82 , V_113 , V_91 ) ;
else if ( V_107 == V_100 )
F_35 ( & V_38 -> V_82 , V_114 , V_91 ) ;
else if ( V_107 == V_98 )
F_35 ( & V_38 -> V_82 , V_95 , V_91 ) ;
else if ( V_107 == V_96 )
F_35 ( & V_38 -> V_82 , V_115 , V_91 ) ;
}
static struct V_24 *
F_65 ( struct V_4 * V_5 , int V_40 , int V_39 )
{
unsigned long V_116 = 0 ;
unsigned long V_26 ;
int V_16 ;
struct V_24 * V_25 ;
struct V_117 V_118 ;
if ( ! V_5 -> V_55 )
return NULL ;
if ( ( V_40 >= 0 ) && ( V_40 < 64 ) )
F_31 ( V_119 , & V_116 ) ;
if ( V_5 -> V_13 . V_14 -> V_15 -> V_120 & ( ( 1 << V_121 ) |
( 1 << V_122 ) ) ) {
F_31 ( V_123 , & V_116 ) ;
V_118 . V_124 = V_122 ;
} else {
V_118 . V_124 = V_125 ;
}
V_25 = F_66 ( V_5 -> V_55 , V_126 , V_116 , V_40 , V_39 ) ;
if ( ! V_25 ) {
F_2 ( V_44 L_29 , V_45 ) ;
return NULL ;
}
V_25 -> V_38 = F_67 ( sizeof( struct V_37 ) , V_70 ) ;
if ( ! V_25 -> V_38 ) {
F_68 ( V_25 ) ;
F_2 ( V_44 L_30 , V_45 ) ;
return NULL ;
}
V_25 -> V_38 -> V_5 = V_5 ;
V_25 -> V_38 -> V_25 = V_25 ;
V_25 -> V_38 -> V_82 . V_10 = * V_10 & V_11 ;
V_25 -> V_38 -> V_82 . V_6 = V_25 -> V_38 ;
V_25 -> V_38 -> V_82 . V_83 = F_16 ;
V_25 -> V_38 -> V_82 . V_127 = & V_128 ;
V_25 -> V_38 -> V_82 . V_19 = V_93 ;
V_25 -> V_38 -> V_88 = 2000 ;
F_69 ( & V_25 -> V_38 -> V_82 , & V_25 -> V_38 -> V_87 ) ;
F_70 ( & V_5 -> V_27 , V_26 ) ;
V_16 = F_17 ( V_5 ) ;
F_71 ( & V_25 -> V_101 , & V_5 -> V_24 ) ;
F_72 ( & V_5 -> V_27 , V_26 ) ;
if ( V_16 < 0 ) {
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_103 , NULL ) ;
F_2 ( V_44 L_31 , V_45 ) ;
return NULL ;
} else {
V_25 -> V_13 . V_43 = V_16 ;
F_73 ( & V_25 -> V_13 , V_5 -> V_13 . V_14 ) ;
V_25 -> V_13 . V_66 = V_5 -> V_13 . V_66 ;
V_25 -> V_13 . V_67 = V_5 -> V_13 . V_67 ;
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_129 , NULL ) ;
V_118 . V_130 . V_15 = V_5 -> V_13 . V_14 -> V_15 -> V_16 ;
V_16 = V_5 -> V_13 . V_14 -> V_131 . V_102 ( & V_5 -> V_13 . V_14 -> V_131 , V_129 , & V_118 ) ;
if ( V_16 < 0 ) {
F_2 ( V_44 L_32 , V_45 ) ;
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_103 , NULL ) ;
V_25 = NULL ;
}
}
return V_25 ;
}
static void
F_74 ( struct V_4 * V_5 , T_5 * V_91 )
{
int V_40 , V_79 ;
struct V_24 * V_25 ;
V_79 = V_91 [ 0 ] << 8 ;
V_79 += V_91 [ 1 ] ;
if ( ! V_5 -> V_55 )
goto V_132;
if ( ! ( V_91 [ 3 ] & 1 ) )
goto V_132;
if ( V_91 [ 3 ] != 0xff )
V_40 = V_91 [ 3 ] >> 1 ;
else
V_40 = F_22 ( V_5 ) ;
if ( V_40 < 0 ) {
F_2 ( V_44 L_33 , V_45 ) ;
goto V_132;
}
V_25 = F_65 ( V_5 , V_40 , V_133 ) ;
if ( ! V_25 )
goto V_132;
else
F_35 ( & V_25 -> V_38 -> V_82 , V_134 , V_91 ) ;
return;
V_132:
F_45 ( V_5 , V_111 , V_79 , V_58 ) ;
}
static int
F_75 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
int V_135 = - V_72 ;
struct V_24 * V_25 , * V_136 ;
T_5 V_107 ;
if ( V_51 -> V_49 < 8 ) {
if ( * V_10 & V_84 )
F_2 ( V_12 L_34 ,
V_45 , V_51 -> V_49 ) ;
goto V_77;
}
if ( ( V_51 -> V_73 [ 0 ] >> 2 ) != V_59 )
goto V_77;
if ( V_51 -> V_73 [ 0 ] & 1 )
goto V_77;
if ( ! ( V_51 -> V_73 [ 1 ] & 1 ) )
goto V_77;
if ( ( V_51 -> V_73 [ 1 ] >> 1 ) != V_58 )
goto V_77;
if ( ( V_51 -> V_73 [ 2 ] & 0xef ) != V_74 )
goto V_77;
if ( V_51 -> V_73 [ 3 ] != V_81 )
goto V_77;
V_107 = V_51 -> V_73 [ 6 ] ;
switch ( V_107 ) {
case V_85 :
case V_96 :
case V_98 :
if ( ! F_11 ( V_71 , & V_5 -> V_31 ) )
goto V_77;
break;
case V_104 :
case V_111 :
case V_106 :
case V_100 :
if ( F_11 ( V_71 , & V_5 -> V_31 ) )
goto V_77;
break;
default:
goto V_77;
}
V_135 = 0 ;
if ( V_107 == V_85 ) {
F_74 ( V_5 , & V_51 -> V_73 [ 4 ] ) ;
goto V_77;
}
F_76 (l2, nl2, &mgr->layer2, list) {
F_64 ( V_25 -> V_38 , V_107 , & V_51 -> V_73 [ 4 ] , V_51 -> V_49 - 4 ) ;
}
V_77:
return V_135 ;
}
int
F_77 ( struct V_24 * V_25 , T_3 V_137 , T_2 V_18 )
{
struct V_37 * V_38 = V_25 -> V_38 ;
if ( F_11 ( V_108 , & V_25 -> V_109 ) )
return 0 ;
if ( * V_10 & V_84 )
F_2 ( V_12 L_35 , V_45 , V_137 ) ;
switch ( V_137 ) {
case V_138 :
F_35 ( & V_38 -> V_82 , V_139 , NULL ) ;
break;
case V_140 :
if ( F_11 ( V_71 , & V_38 -> V_5 -> V_31 ) )
F_35 ( & V_38 -> V_82 , V_113 , & V_25 -> V_40 ) ;
if ( F_11 ( V_141 , & V_38 -> V_5 -> V_31 ) )
F_35 ( & V_38 -> V_82 , V_95 , NULL ) ;
break;
case V_142 :
if ( F_11 ( V_71 , & V_38 -> V_5 -> V_31 ) )
F_35 ( & V_38 -> V_5 -> V_64 , V_143 , NULL ) ;
break;
case V_144 :
if ( F_11 ( V_71 , & V_38 -> V_5 -> V_31 ) )
F_35 ( & V_38 -> V_5 -> V_64 , V_145 , NULL ) ;
break;
case V_146 :
if ( F_11 ( V_71 , & V_38 -> V_5 -> V_31 ) )
F_35 ( & V_38 -> V_5 -> V_64 , V_65 , NULL ) ;
break;
}
return 0 ;
}
void
F_78 ( struct V_24 * V_25 )
{
struct V_37 * V_38 = V_25 -> V_38 ;
T_2 V_26 ;
F_4 ( & V_38 -> V_87 , 1 ) ;
F_70 ( & V_38 -> V_5 -> V_27 , V_26 ) ;
F_58 ( & V_25 -> V_101 ) ;
F_72 ( & V_38 -> V_5 -> V_27 , V_26 ) ;
V_25 -> V_38 = NULL ;
F_68 ( V_38 ) ;
}
static int
F_79 ( struct V_4 * V_5 , struct V_117 * V_147 )
{
struct V_24 * V_25 ;
unsigned long V_116 = 0 ;
unsigned long V_26 ;
int V_16 ;
struct V_117 V_148 ;
if ( * V_10 & V_84 )
F_2 ( V_12 L_36 ,
V_45 , F_80 ( & V_5 -> V_13 . V_14 -> V_15 -> V_15 ) ,
V_147 -> V_124 , V_147 -> V_130 . V_15 , V_147 -> V_130 . V_149 ,
V_147 -> V_130 . V_39 , V_147 -> V_130 . V_40 ) ;
if ( V_147 -> V_130 . V_40 > V_58 )
return - V_72 ;
if ( V_147 -> V_130 . V_40 < 64 )
F_31 ( V_119 , & V_116 ) ;
if ( V_147 -> V_130 . V_40 == 0 )
F_31 ( V_150 , & V_116 ) ;
if ( F_11 ( V_71 , & V_5 -> V_31 ) ) {
if ( V_147 -> V_124 == V_151 )
return - V_152 ;
if ( ( V_147 -> V_130 . V_40 != 0 ) && ( V_147 -> V_130 . V_40 != 127 ) )
return - V_72 ;
if ( V_5 -> V_55 ) {
F_2 ( V_44
L_37 ,
V_45 ) ;
return - V_46 ;
}
} else if ( F_11 ( V_141 , & V_5 -> V_31 ) ) {
if ( V_147 -> V_124 == V_126 )
return - V_152 ;
if ( ( V_147 -> V_130 . V_40 >= 64 ) && ( V_147 -> V_130 . V_40 < V_58 ) )
return - V_72 ;
} else {
if ( V_147 -> V_124 == V_126 )
F_31 ( V_71 , & V_5 -> V_31 ) ;
if ( V_147 -> V_124 == V_151 )
F_31 ( V_141 , & V_5 -> V_31 ) ;
}
V_148 . V_130 = V_147 -> V_130 ;
if ( V_5 -> V_13 . V_14 -> V_15 -> V_120
& ( ( 1 << V_121 ) | ( 1 << V_122 ) ) )
F_31 ( V_123 , & V_116 ) ;
if ( ( V_147 -> V_124 == V_126 ) && ( V_147 -> V_130 . V_40 == 127 ) ) {
V_5 -> V_55 = V_147 -> V_13 ;
V_16 = V_153 ;
F_24 ( V_5 , V_154 , sizeof( V_16 ) , & V_16 ) ;
if ( F_11 ( V_60 , & V_5 -> V_31 ) )
F_24 ( V_5 , V_155 , 0 , NULL ) ;
V_147 -> V_13 = NULL ;
if ( ! F_81 ( & V_5 -> V_24 ) ) {
F_8 ( & V_5 -> V_27 , V_26 ) ;
F_9 (l2, &mgr->layer2, list) {
V_25 -> V_55 = V_5 -> V_55 ;
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_129 , NULL ) ;
}
F_10 ( & V_5 -> V_27 , V_26 ) ;
}
return 0 ;
}
V_25 = F_66 ( V_147 -> V_13 , V_147 -> V_124 , V_116 ,
V_147 -> V_130 . V_40 , V_147 -> V_130 . V_39 ) ;
if ( ! V_25 )
return - V_156 ;
V_25 -> V_38 = F_67 ( sizeof( struct V_37 ) , V_70 ) ;
if ( ! V_25 -> V_38 ) {
F_68 ( V_25 ) ;
F_2 ( V_157 L_38 ) ;
return - V_156 ;
}
V_25 -> V_38 -> V_5 = V_5 ;
V_25 -> V_38 -> V_25 = V_25 ;
V_25 -> V_38 -> V_82 . V_10 = * V_10 & V_11 ;
V_25 -> V_38 -> V_82 . V_6 = V_25 -> V_38 ;
V_25 -> V_38 -> V_82 . V_83 = F_16 ;
if ( V_147 -> V_124 == V_151 ) {
V_25 -> V_38 -> V_82 . V_127 = & V_158 ;
V_25 -> V_38 -> V_82 . V_19 = V_93 ;
V_25 -> V_38 -> V_88 = 1000 ;
if ( F_11 ( V_123 , & V_116 ) )
V_148 . V_124 = V_121 ;
else
V_148 . V_124 = V_159 ;
} else {
V_25 -> V_38 -> V_82 . V_127 = & V_128 ;
V_25 -> V_38 -> V_82 . V_19 = V_93 ;
V_25 -> V_38 -> V_88 = 2000 ;
if ( F_11 ( V_123 , & V_116 ) )
V_148 . V_124 = V_122 ;
else
V_148 . V_124 = V_125 ;
}
F_69 ( & V_25 -> V_38 -> V_82 , & V_25 -> V_38 -> V_87 ) ;
F_70 ( & V_5 -> V_27 , V_26 ) ;
V_16 = F_17 ( V_5 ) ;
F_71 ( & V_25 -> V_101 , & V_5 -> V_24 ) ;
F_72 ( & V_5 -> V_27 , V_26 ) ;
if ( V_16 >= 0 ) {
V_25 -> V_13 . V_43 = V_16 ;
V_25 -> V_55 -> V_43 = V_16 ;
V_147 -> V_13 = & V_25 -> V_13 ;
V_16 = V_5 -> V_13 . V_14 -> V_131 . V_102 ( & V_5 -> V_13 . V_14 -> V_131 , V_129 ,
& V_148 ) ;
}
if ( V_16 < 0 )
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_103 , NULL ) ;
return V_16 ;
}
static int
F_82 ( struct V_160 * V_13 , struct V_50 * V_51 )
{
struct V_4 * V_5 ;
struct V_52 * V_53 = F_26 ( V_51 ) ;
int V_135 = - V_72 ;
V_5 = F_83 ( V_13 , struct V_4 , V_13 ) ;
if ( * V_10 & V_161 )
F_2 ( V_12 L_39 ,
V_45 , V_53 -> V_48 , V_53 -> V_16 ) ;
switch ( V_53 -> V_48 ) {
case V_162 :
F_35 ( & V_5 -> V_64 , V_65 , NULL ) ;
V_135 = F_75 ( V_5 , V_51 ) ;
break;
case V_163 :
F_36 ( V_5 , V_53 -> V_16 ) ;
V_135 = 0 ;
break;
case V_155 :
F_31 ( V_60 , & V_5 -> V_31 ) ;
if ( V_5 -> V_55 )
F_24 ( V_5 , V_155 , 0 , NULL ) ;
F_35 ( & V_5 -> V_64 , V_164 , NULL ) ;
F_30 ( V_5 ) ;
V_135 = 0 ;
break;
case V_165 :
F_33 ( V_60 , & V_5 -> V_31 ) ;
if ( V_5 -> V_55 )
F_24 ( V_5 , V_165 , 0 , NULL ) ;
F_35 ( & V_5 -> V_64 , V_166 , NULL ) ;
V_135 = 0 ;
break;
case V_167 :
return F_39 ( V_5 , V_51 ) ;
}
if ( ! V_135 )
F_28 ( V_51 ) ;
return V_135 ;
}
static int
F_84 ( struct V_4 * V_5 )
{
struct V_24 * V_25 , * V_136 ;
F_33 ( V_30 , & V_5 -> V_31 ) ;
if ( F_11 ( V_71 , & V_5 -> V_31 ) ) {
V_5 -> V_55 = NULL ;
if ( F_11 ( V_168 , & V_5 -> V_31 ) ) {
F_76 (l2, nl2, &mgr->layer2, list) {
F_45 ( V_5 , V_100 , 0 , V_25 -> V_40 ) ;
F_85 ( & V_5 -> V_13 . V_14 -> V_169 ) ;
F_58 ( & V_25 -> V_13 . V_101 ) ;
F_86 ( & V_5 -> V_13 . V_14 -> V_169 ) ;
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_103 , NULL ) ;
}
F_33 ( V_71 , & V_5 -> V_31 ) ;
} else {
F_76 (l2, nl2, &mgr->layer2, list) {
V_25 -> V_55 = NULL ;
}
}
}
if ( F_11 ( V_141 , & V_5 -> V_31 ) ) {
if ( F_81 ( & V_5 -> V_24 ) )
F_33 ( V_141 , & V_5 -> V_31 ) ;
}
V_5 -> V_13 . V_14 -> V_15 -> V_170 . V_102 ( & V_5 -> V_13 . V_14 -> V_15 -> V_170 , V_103 , NULL ) ;
return 0 ;
}
static int
F_87 ( struct V_4 * V_5 , void * V_18 )
{
int * V_171 = ( int * ) V_18 ;
int V_135 = 0 ;
switch ( V_171 [ 0 ] ) {
case V_172 :
if ( V_171 [ 1 ] )
F_31 ( V_168 , & V_5 -> V_31 ) ;
else
F_33 ( V_168 , & V_5 -> V_31 ) ;
break;
case V_173 :
if ( V_171 [ 1 ] )
F_31 ( V_30 , & V_5 -> V_31 ) ;
else
F_33 ( V_30 , & V_5 -> V_31 ) ;
break;
default:
V_135 = - V_72 ;
}
return V_135 ;
}
static int
F_88 ( struct V_4 * V_5 , struct V_50 * V_51 )
{
struct V_52 * V_53 = F_26 ( V_51 ) ;
int V_135 , V_40 , V_39 ;
struct V_24 * V_25 ;
if ( * V_10 & V_174 )
F_2 ( V_12 L_39 ,
V_45 , V_53 -> V_48 , V_53 -> V_16 ) ;
if ( F_11 ( V_141 , & V_5 -> V_31 ) )
return - V_175 ;
if ( V_53 -> V_48 != V_162 )
return - V_175 ;
if ( V_51 -> V_49 != 3 )
return - V_175 ;
if ( V_51 -> V_73 [ 0 ] & 3 )
return - V_72 ;
V_39 = V_51 -> V_73 [ 0 ] >> 2 ;
if ( ! ( V_51 -> V_73 [ 1 ] & 1 ) )
return - V_72 ;
V_40 = V_51 -> V_73 [ 1 ] >> 1 ;
if ( V_40 > 63 )
return - V_175 ;
if ( ( V_51 -> V_73 [ 2 ] & ~ 0x10 ) != V_176 )
return - V_175 ;
if ( * V_10 & V_174 )
F_2 ( V_12 L_40 ,
V_45 , V_39 , V_40 ) ;
V_25 = F_65 ( V_5 , V_40 , V_39 ) ;
if ( ! V_25 ) {
if ( * V_10 & V_174 )
F_2 ( V_12 L_41 ,
V_45 ) ;
return - V_156 ;
}
V_135 = V_25 -> V_13 . V_56 ( & V_25 -> V_13 , V_51 ) ;
return V_135 ;
}
void
F_89 ( struct V_160 * V_13 )
{
struct V_4 * V_5 ;
struct V_24 * V_25 , * V_136 ;
V_5 = F_83 ( V_13 , struct V_4 , V_13 ) ;
F_76 (l2, nl2, &mgr->layer2, list) {
F_85 ( & V_5 -> V_13 . V_14 -> V_169 ) ;
F_58 ( & V_25 -> V_13 . V_101 ) ;
F_86 ( & V_5 -> V_13 . V_14 -> V_169 ) ;
V_25 -> V_13 . V_102 ( & V_25 -> V_13 , V_103 , NULL ) ;
}
F_58 ( & V_5 -> V_13 . V_101 ) ;
F_58 ( & V_5 -> V_177 . V_101 ) ;
F_90 ( & V_5 -> V_62 ) ;
F_68 ( V_5 ) ;
}
static int
F_91 ( struct V_160 * V_13 , T_3 V_137 , void * V_18 )
{
struct V_4 * V_5 ;
int V_135 = - V_72 ;
V_5 = F_83 ( V_13 , struct V_4 , V_13 ) ;
if ( * V_10 & V_174 )
F_2 ( V_12 L_42 , V_45 , V_137 , V_18 ) ;
switch ( V_137 ) {
case V_129 :
V_135 = F_79 ( V_5 , V_18 ) ;
break;
case V_103 :
V_135 = F_84 ( V_5 ) ;
break;
case V_178 :
V_135 = F_87 ( V_5 , V_18 ) ;
break;
case V_179 :
V_135 = F_88 ( V_5 , V_18 ) ;
break;
}
return V_135 ;
}
static int
F_92 ( struct V_160 * V_13 , struct V_50 * V_51 )
{
struct V_4 * V_5 = F_83 ( V_13 , struct V_4 , V_177 ) ;
struct V_52 * V_180 , * V_53 = F_26 ( V_51 ) ;
struct V_50 * V_181 = NULL ;
struct V_24 * V_25 ;
T_2 V_26 ;
int V_135 ;
F_8 ( & V_5 -> V_27 , V_26 ) ;
F_9 (l2, &mgr->layer2, list) {
if ( ( V_53 -> V_16 & V_182 ) ==
( V_25 -> V_13 . V_47 & V_182 ) ) {
if ( F_93 ( & V_25 -> V_101 , & V_5 -> V_24 ) ) {
V_181 = V_51 ;
V_51 = NULL ;
} else {
if ( ! V_181 )
V_181 = F_94 ( V_51 , V_36 ) ;
}
if ( V_181 ) {
V_180 = F_26 ( V_181 ) ;
V_180 ++ ;
* V_180 = * V_53 ;
V_180 -- ;
V_180 -> V_48 = V_183 ;
V_180 -> V_16 = V_25 -> V_13 . V_43 ;
V_135 = V_13 -> V_14 -> V_131 . V_66 ( & V_13 -> V_14 -> V_131 , V_181 ) ;
if ( V_135 ) {
if ( * V_10 & V_184 )
F_2 ( V_12
L_43
L_44 ,
V_45 , V_25 -> V_13 . V_43 ,
V_53 -> V_48 , V_25 -> V_13 . V_47 , V_135 ) ;
} else
V_181 = NULL ;
} else {
F_2 ( V_44 L_45 ,
V_45 , V_13 -> V_43 , V_13 -> V_47 ) ;
goto V_185;
}
}
}
V_185:
F_10 ( & V_5 -> V_27 , V_26 ) ;
if ( V_181 )
F_28 ( V_181 ) ;
if ( V_51 )
F_28 ( V_51 ) ;
return 0 ;
}
static int
F_95 ( struct V_160 * V_13 , T_3 V_137 , void * V_18 )
{
return - V_72 ;
}
int
F_96 ( struct V_186 * V_15 )
{
struct V_4 * V_5 ;
V_5 = F_67 ( sizeof( struct V_4 ) , V_70 ) ;
if ( ! V_5 )
return - V_156 ;
F_97 ( & V_5 -> V_24 ) ;
F_98 ( & V_5 -> V_27 ) ;
F_99 ( & V_5 -> V_62 ) ;
V_5 -> V_57 = 1 ;
V_5 -> V_63 = V_68 ;
V_5 -> V_13 . V_56 = F_82 ;
V_5 -> V_13 . V_102 = F_91 ;
V_5 -> V_13 . V_14 = V_15 -> V_170 . V_14 ;
F_100 ( & V_5 -> V_13 , V_59 , V_58 ) ;
F_101 ( & V_5 -> V_13 , V_15 -> V_170 . V_14 ) ;
V_5 -> V_177 . V_56 = F_92 ;
V_5 -> V_177 . V_102 = F_95 ;
V_5 -> V_177 . V_14 = V_15 -> V_170 . V_14 ;
F_100 ( & V_5 -> V_177 , 0 , V_58 ) ;
F_101 ( & V_5 -> V_177 , V_15 -> V_170 . V_14 ) ;
V_5 -> V_64 . V_10 = * V_10 & V_187 ;
V_5 -> V_64 . V_6 = V_5 ;
V_5 -> V_64 . V_83 = F_1 ;
V_5 -> V_64 . V_127 = & V_188 ;
V_5 -> V_64 . V_19 = V_23 ;
F_69 ( & V_5 -> V_64 , & V_5 -> V_21 ) ;
V_15 -> V_37 = & V_5 -> V_13 ;
return 0 ;
}
int F_102 ( T_3 * V_189 )
{
V_10 = V_189 ;
V_158 . V_190 = V_191 ;
V_158 . V_192 = V_193 ;
V_158 . V_194 = V_195 ;
V_158 . V_196 = V_197 ;
F_103 ( & V_158 , V_198 , F_104 ( V_198 ) ) ;
V_128 . V_190 = V_191 ;
V_128 . V_192 = V_193 ;
V_128 . V_194 = V_195 ;
V_128 . V_196 = V_197 ;
F_103 ( & V_128 , V_199 , F_104 ( V_199 ) ) ;
V_188 . V_190 = V_200 ;
V_188 . V_192 = V_201 ;
V_188 . V_194 = V_202 ;
V_188 . V_196 = V_203 ;
F_103 ( & V_188 , V_204 , F_104 ( V_204 ) ) ;
return 0 ;
}
void F_105 ( void )
{
F_106 ( & V_158 ) ;
F_106 ( & V_128 ) ;
F_106 ( & V_188 ) ;
}
