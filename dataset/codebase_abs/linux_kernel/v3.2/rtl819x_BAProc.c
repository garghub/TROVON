static void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 Time )
{
V_4 -> V_5 = true ;
if ( Time != 0 )
F_2 ( & V_4 -> V_6 , V_7 + F_3 ( Time ) ) ;
}
static void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_5 = false ;
F_5 ( & V_4 -> V_6 ) ;
}
static T_2 F_6 ( struct V_1 * V_2 , struct V_8 * V_9 )
{
struct V_3 * V_10 = & V_9 -> V_11 ;
struct V_3 * V_12 = & V_9 -> V_13 ;
T_2 V_14 = false ;
if ( V_12 -> V_5 ) {
F_4 ( V_2 , V_12 ) ;
V_14 = true ;
}
if ( V_10 -> V_5 ) {
F_4 ( V_2 , V_10 ) ;
V_14 = true ;
}
return V_14 ;
}
static T_2 F_7 ( struct V_1 * V_2 , struct V_15 * V_16 )
{
struct V_3 * V_17 = & V_16 -> V_18 ;
T_2 V_14 = false ;
if ( V_17 -> V_5 ) {
F_4 ( V_2 , V_17 ) ;
V_14 = true ;
}
return V_14 ;
}
void F_8 ( struct V_3 * V_4 )
{
V_4 -> V_5 = false ;
V_4 -> V_19 . V_20 = 0 ;
V_4 -> V_21 = 0 ;
V_4 -> V_22 = 0 ;
V_4 -> V_23 . V_24 = 0 ;
}
static struct V_25 * F_9 ( struct V_1 * V_2 , T_2 * V_26 ,
struct V_3 * V_4 ,
T_1 V_27 , T_2 type )
{
struct V_25 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
T_2 * V_31 = NULL ;
T_1 V_32 = 0 ;
T_1 V_33 = V_2 -> V_34 + 9 ;
F_10 ( V_35 | V_36 , L_1
L_2 , V_37 ,
type , V_26 , V_2 -> V_38 ) ;
if ( V_4 == NULL ) {
F_10 ( V_39 , L_3 ) ;
return NULL ;
}
V_28 = F_11 ( V_33 + sizeof( struct V_29 ) ) ;
if ( V_28 == NULL ) {
F_10 ( V_39 , L_4 ) ;
return NULL ;
}
memset ( V_28 -> V_40 , 0 , sizeof( struct V_29 ) ) ;
F_12 ( V_28 , V_2 -> V_34 ) ;
V_30 = (struct V_29 * ) F_13 ( V_28 ,
sizeof( struct V_29 ) ) ;
memcpy ( V_30 -> V_41 , V_26 , V_42 ) ;
memcpy ( V_30 -> V_43 , V_2 -> V_38 -> V_44 , V_42 ) ;
memcpy ( V_30 -> V_45 , V_2 -> V_46 . V_47 , V_42 ) ;
V_30 -> V_48 = F_14 ( V_49 ) ;
V_31 = ( T_2 * ) F_13 ( V_28 , 9 ) ;
* V_31 ++ = V_50 ;
* V_31 ++ = type ;
* V_31 ++ = V_4 -> V_22 ;
if ( V_51 == type ) {
F_15 ( V_52 , L_5 ) ;
V_32 = F_14 ( V_27 ) ;
memcpy ( V_31 , ( T_2 * ) & V_32 , 2 ) ;
V_31 += 2 ;
}
V_32 = F_14 ( V_4 -> V_19 . V_20 ) ;
memcpy ( V_31 , ( T_2 * ) & V_32 , 2 ) ;
V_31 += 2 ;
V_32 = F_14 ( V_4 -> V_21 ) ;
memcpy ( V_31 , ( T_2 * ) & V_32 , 2 ) ;
V_31 += 2 ;
if ( V_53 == type ) {
memcpy ( V_31 , ( T_2 * ) & ( V_4 -> V_23 ) , 2 ) ;
V_31 += 2 ;
}
F_16 ( V_54 | V_36 , V_28 -> V_40 , V_28 -> V_33 ) ;
return V_28 ;
}
static struct V_25 * F_17 ( struct V_1 * V_2 , T_2 * V_55 ,
struct V_3 * V_4 ,
enum V_56 V_57 , T_1 V_58 )
{
union V_59 V_60 ;
struct V_25 * V_28 = NULL ;
struct V_29 * V_61 = NULL ;
T_2 * V_31 = NULL ;
T_1 V_32 = 0 ;
T_1 V_33 = 6 + V_2 -> V_34 ;
if ( F_18 () )
F_10 ( V_35 | V_36 ,
L_6
L_7 , V_37 ,
V_58 , V_55 ) ;
memset ( & V_60 , 0 , 2 ) ;
V_60 . V_62 . V_63 = ( V_57 == V_64 ) ? 1 : 0 ;
V_60 . V_62 . V_65 = V_4 -> V_19 . V_62 . V_65 ;
V_28 = F_11 ( V_33 + sizeof( struct V_29 ) ) ;
if ( V_28 == NULL ) {
F_10 ( V_39 , L_4 ) ;
return NULL ;
}
F_12 ( V_28 , V_2 -> V_34 ) ;
V_61 = (struct V_29 * ) F_13 ( V_28 ,
sizeof( struct V_29 ) ) ;
memcpy ( V_61 -> V_41 , V_55 , V_42 ) ;
memcpy ( V_61 -> V_43 , V_2 -> V_38 -> V_44 , V_42 ) ;
memcpy ( V_61 -> V_45 , V_2 -> V_46 . V_47 , V_42 ) ;
V_61 -> V_48 = F_14 ( V_49 ) ;
V_31 = ( T_2 * ) F_13 ( V_28 , 6 ) ;
* V_31 ++ = V_50 ;
* V_31 ++ = V_66 ;
V_32 = F_14 ( V_60 . V_20 ) ;
memcpy ( V_31 , ( T_2 * ) & V_32 , 2 ) ;
V_31 += 2 ;
V_32 = F_14 ( V_58 ) ;
memcpy ( V_31 , ( T_2 * ) & V_32 , 2 ) ;
V_31 += 2 ;
F_16 ( V_54 | V_36 , V_28 -> V_40 , V_28 -> V_33 ) ;
if ( F_18 () )
F_10 ( V_35 | V_36 , L_8 ,
V_37 ) ;
return V_28 ;
}
static void F_19 ( struct V_1 * V_2 , T_2 * V_55 ,
struct V_3 * V_4 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_9 ( V_2 , V_55 , V_4 , 0 , V_53 ) ;
if ( V_28 ) {
F_15 ( V_52 , L_9 ) ;
F_20 ( V_28 , V_2 ) ;
} else {
F_10 ( V_39 , L_10
L_11 , V_37 ) ;
}
return;
}
static void F_21 ( struct V_1 * V_2 , T_2 * V_55 ,
struct V_3 * V_4 , T_1 V_27 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_9 ( V_2 , V_55 , V_4 , V_27 , V_51 ) ;
if ( V_28 )
F_20 ( V_28 , V_2 ) ;
else
F_10 ( V_39 , L_10
L_11 , V_37 ) ;
return;
}
static void F_22 ( struct V_1 * V_2 , T_2 * V_55 ,
struct V_3 * V_4 , enum V_56 V_57 ,
T_1 V_58 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_17 ( V_2 , V_55 , V_4 , V_57 , V_58 ) ;
if ( V_28 )
F_20 ( V_28 , V_2 ) ;
else
F_10 ( V_39 , L_12
L_13 , V_37 ) ;
return ;
}
int F_23 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_67 = NULL ;
T_1 V_68 = 0 ;
T_2 * V_55 = NULL , * V_69 = NULL , * V_31 = NULL ;
struct V_3 * V_4 = NULL ;
union V_70 * V_71 = NULL ;
T_1 * V_72 = NULL ;
union V_73 * V_74 = NULL ;
struct V_15 * V_75 = NULL ;
if ( V_28 -> V_33 < sizeof( struct V_29 ) + 9 ) {
F_10 ( V_39 , L_14
L_15 , ( int ) V_28 -> V_33 ,
( int ) ( sizeof( struct V_29 ) + 9 ) ) ;
return - 1 ;
}
F_16 ( V_54 | V_36 , V_28 -> V_40 , V_28 -> V_33 ) ;
V_67 = (struct V_29 * ) V_28 -> V_40 ;
V_31 = ( T_2 * ) V_67 ;
V_55 = ( T_2 * ) ( & V_67 -> V_43 [ 0 ] ) ;
V_31 += sizeof( struct V_29 ) ;
V_69 = V_31 + 2 ;
V_71 = (union V_70 * ) ( V_31 + 3 ) ;
V_72 = ( T_1 * ) ( V_31 + 5 ) ;
V_74 = (union V_73 * ) ( V_67 + 7 ) ;
F_15 ( V_52 , L_16 , V_55 ) ;
if ( V_2 -> V_46 . V_76 . V_77 == 0 ||
( V_2 -> V_78 -> V_79 == false ) ||
( V_2 -> V_78 -> V_80 & V_81 ) ) {
V_68 = V_82 ;
F_10 ( V_39 , L_17
L_18 ,
V_2 -> V_46 . V_76 . V_77 ,
V_2 -> V_78 -> V_79 ) ;
goto V_83;
}
if ( ! F_24 ( V_2 , (struct V_84 * * ) ( & V_75 ) , V_55 ,
( T_2 ) ( V_71 -> V_62 . V_65 ) , V_85 , true ) ) {
V_68 = V_82 ;
F_10 ( V_39 , L_19 , V_37 ) ;
goto V_83;
}
V_4 = & V_75 -> V_18 ;
if ( V_71 -> V_62 . V_86 == V_87 ) {
V_68 = V_88 ;
F_10 ( V_39 , L_20
L_21 , V_37 ) ;
goto V_83;
}
F_25 ( V_2 , V_75 ) ;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_22 = * V_69 ;
V_4 -> V_19 = * V_71 ;
V_4 -> V_21 = * V_72 ;
V_4 -> V_23 = * V_74 ;
if ( V_2 -> V_89 ( V_2 -> V_38 ) ||
( V_2 -> V_78 -> V_80 & V_90 ) )
V_4 -> V_19 . V_62 . V_91 = 1 ;
else
V_4 -> V_19 . V_62 . V_91 = 32 ;
F_1 ( V_2 , V_4 , 0 ) ;
F_21 ( V_2 , V_55 , V_4 , V_92 ) ;
return 0 ;
V_83:
{
struct V_3 V_93 ;
V_93 . V_19 = * V_71 ;
V_93 . V_21 = * V_72 ;
V_93 . V_22 = * V_69 ;
V_93 . V_19 . V_62 . V_86 = V_94 ;
F_21 ( V_2 , V_55 , & V_93 , V_68 ) ;
return 0 ;
}
}
int F_26 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_95 = NULL ;
struct V_3 * V_96 , * V_97 ;
struct V_8 * V_75 = NULL ;
T_2 * V_55 = NULL , * V_69 = NULL , * V_31 = NULL ;
T_1 * V_98 = NULL , * V_72 = NULL ;
union V_70 * V_71 = NULL ;
T_1 V_58 ;
if ( V_28 -> V_33 < sizeof( struct V_29 ) + 9 ) {
F_10 ( V_39 , L_22
L_15 , ( int ) V_28 -> V_33 ,
( int ) ( sizeof( struct V_29 ) + 9 ) ) ;
return - 1 ;
}
V_95 = (struct V_29 * ) V_28 -> V_40 ;
V_31 = ( T_2 * ) V_95 ;
V_55 = ( T_2 * ) ( & V_95 -> V_43 [ 0 ] ) ;
V_31 += sizeof( struct V_29 ) ;
V_69 = V_31 + 2 ;
V_98 = ( T_1 * ) ( V_31 + 3 ) ;
V_71 = (union V_70 * ) ( V_31 + 5 ) ;
V_72 = ( T_1 * ) ( V_31 + 7 ) ;
F_15 ( V_52 , L_23 , V_55 ) ;
if ( V_2 -> V_46 . V_76 . V_77 == 0 ||
V_2 -> V_78 -> V_79 == false ||
V_2 -> V_78 -> V_99 == false ) {
F_10 ( V_39 , L_24
L_25 ,
V_2 -> V_46 . V_76 . V_77 ,
V_2 -> V_78 -> V_79 ,
V_2 -> V_78 -> V_99 ) ;
V_58 = V_100 ;
goto V_101;
}
if ( ! F_24 ( V_2 , (struct V_84 * * ) ( & V_75 ) , V_55 ,
( T_2 ) ( V_71 -> V_62 . V_65 ) , V_64 , false ) ) {
F_10 ( V_39 , L_19 , V_37 ) ;
V_58 = V_100 ;
goto V_101;
}
V_75 -> V_102 = false ;
V_96 = & V_75 -> V_13 ;
V_97 = & V_75 -> V_11 ;
if ( ( V_97 -> V_5 == true ) ) {
F_10 ( V_36 , L_26
L_27 ) ;
return - 1 ;
} else if ( ( V_96 -> V_5 == false ) ||
( * V_69 != V_96 -> V_22 ) ) {
F_10 ( V_39 , L_28
L_29 ) ;
V_58 = V_100 ;
goto V_101;
} else {
F_10 ( V_36 , L_30
L_31 , * V_98 ) ;
F_4 ( V_2 , V_96 ) ;
}
if ( * V_98 == V_92 ) {
if ( V_71 -> V_62 . V_86 == V_87 ) {
V_75 -> V_103 = true ;
F_4 ( V_2 , V_97 ) ;
V_58 = V_104 ;
goto V_101;
}
V_97 -> V_22 = * V_69 ;
V_97 -> V_21 = * V_72 ;
V_97 -> V_23 = V_96 -> V_23 ;
V_97 -> V_19 = * V_71 ;
F_4 ( V_2 , V_97 ) ;
F_1 ( V_2 , V_97 , * V_72 ) ;
} else {
V_75 -> V_103 = true ;
V_75 -> V_105 = true ;
V_58 = V_104 ;
goto V_101;
}
return 0 ;
V_101:
{
struct V_3 V_93 ;
V_93 . V_19 = * V_71 ;
F_22 ( V_2 , V_55 , & V_93 , V_64 , V_58 ) ;
return 0 ;
}
}
int F_27 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_106 = NULL ;
union V_59 * V_107 = NULL ;
T_1 * V_108 = NULL ;
T_2 * V_55 = NULL ;
if ( V_28 -> V_33 < sizeof( struct V_29 ) + 6 ) {
F_10 ( V_39 , L_32
L_33 , ( int ) V_28 -> V_33 ,
( int ) ( sizeof( struct V_29 ) + 6 ) ) ;
return - 1 ;
}
if ( V_2 -> V_46 . V_76 . V_77 == 0 ||
V_2 -> V_78 -> V_79 == false ) {
F_10 ( V_39 , L_34
L_35 ,
V_2 -> V_46 . V_76 . V_77 ,
V_2 -> V_78 -> V_79 ) ;
return - 1 ;
}
F_16 ( V_54 | V_36 , V_28 -> V_40 , V_28 -> V_33 ) ;
V_106 = (struct V_29 * ) V_28 -> V_40 ;
V_55 = ( T_2 * ) ( & V_106 -> V_43 [ 0 ] ) ;
V_106 += sizeof( struct V_29 ) ;
V_107 = (union V_59 * ) ( V_106 + 2 ) ;
V_108 = ( T_1 * ) ( V_106 + 4 ) ;
if ( V_107 -> V_62 . V_63 == 1 ) {
struct V_15 * V_16 ;
if ( ! F_24 ( V_2 , (struct V_84 * * ) & V_16 , V_55 ,
( T_2 ) V_107 -> V_62 . V_65 , V_85 , false ) ) {
F_10 ( V_39 , L_36
L_37 , V_37 , V_55 ,
( T_2 ) V_107 -> V_62 . V_65 ) ;
return - 1 ;
}
F_7 ( V_2 , V_16 ) ;
} else {
struct V_8 * V_9 ;
if ( ! F_24 ( V_2 , (struct V_84 * * ) & V_9 , V_55 ,
( T_2 ) V_107 -> V_62 . V_65 , V_64 , false ) ) {
F_10 ( V_39 , L_38
L_21 , V_37 ) ;
return - 1 ;
}
V_9 -> V_109 = false ;
V_9 -> V_102 = false ;
V_9 -> V_103 = false ;
F_5 ( & V_9 -> V_110 ) ;
F_6 ( V_2 , V_9 ) ;
}
return 0 ;
}
void F_28 ( struct V_1 * V_2 , struct V_8 * V_75 ,
T_2 V_111 , T_2 V_112 )
{
struct V_3 * V_4 = & V_75 -> V_13 ;
if ( V_4 -> V_5 == true && V_112 == false )
return;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_22 ++ ;
V_4 -> V_19 . V_62 . V_113 = 0 ;
V_4 -> V_19 . V_62 . V_86 = V_111 ;
V_4 -> V_19 . V_62 . V_65 =
V_75 -> V_114 . V_115 . V_116 . V_117 . V_62 . V_118 ;
V_4 -> V_19 . V_62 . V_91 = 32 ;
V_4 -> V_21 = 0 ;
V_4 -> V_23 . V_62 . V_119 = ( V_75 -> V_120 + 3 ) % 4096 ;
F_1 ( V_2 , V_4 , V_121 ) ;
F_19 ( V_2 , V_75 -> V_114 . V_122 , V_4 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_84 * V_123 ,
enum V_56 V_57 )
{
if ( V_57 == V_64 ) {
struct V_8 * V_9 =
(struct V_8 * ) V_123 ;
if ( F_6 ( V_2 , V_9 ) )
F_22 ( V_2 , V_123 -> V_122 ,
( V_9 -> V_11 . V_5 ) ?
( & V_9 -> V_11 ) :
( & V_9 -> V_13 ) ,
V_57 , V_104 ) ;
} else if ( V_57 == V_85 ) {
struct V_15 * V_16 =
(struct V_15 * ) V_123 ;
if ( F_7 ( V_2 , V_16 ) )
F_22 ( V_2 , V_123 -> V_122 ,
& V_16 -> V_18 ,
V_57 , V_104 ) ;
}
}
void F_30 ( unsigned long V_40 )
{
struct V_8 * V_9 = (struct V_8 * ) V_40 ;
V_9 -> V_102 = false ;
V_9 -> V_103 = true ;
V_9 -> V_13 . V_5 = false ;
}
void F_31 ( unsigned long V_40 )
{
struct V_8 * V_9 = (struct V_8 * ) V_40 ;
struct V_1 * V_2 = F_32 ( V_9 , struct V_1 ,
V_124 [ V_9 -> V_125 ] ) ;
F_6 ( V_2 , V_9 ) ;
F_22 ( V_2 , V_9 -> V_114 . V_122 ,
& V_9 -> V_11 , V_64 ,
V_126 ) ;
}
void F_33 ( unsigned long V_40 )
{
struct V_15 * V_16 = (struct V_15 * ) V_40 ;
struct V_1 * V_2 = F_32 ( V_16 , struct V_1 ,
V_127 [ V_16 -> V_125 ] ) ;
F_7 ( V_2 , V_16 ) ;
F_22 ( V_2 , V_16 -> V_114 . V_122 ,
& V_16 -> V_18 , V_85 ,
V_126 ) ;
return ;
}
