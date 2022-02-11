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
T_1 V_32 = V_2 -> V_33 + 9 ;
F_10 ( V_34 | V_35 ,
L_1 ,
V_36 , type , V_26 , V_2 -> V_37 ) ;
if ( V_4 == NULL ) {
F_10 ( V_38 , L_2 ) ;
return NULL ;
}
V_28 = F_11 ( V_32 + sizeof( struct V_29 ) ) ;
if ( V_28 == NULL ) {
F_10 ( V_38 , L_3 ) ;
return NULL ;
}
memset ( V_28 -> V_39 , 0 , sizeof( struct V_29 ) ) ;
F_12 ( V_28 , V_2 -> V_33 ) ;
V_30 = (struct V_29 * ) F_13 ( V_28 ,
sizeof( struct V_29 ) ) ;
memcpy ( V_30 -> V_40 , V_26 , V_41 ) ;
memcpy ( V_30 -> V_42 , V_2 -> V_37 -> V_43 , V_41 ) ;
memcpy ( V_30 -> V_44 , V_2 -> V_45 . V_46 , V_41 ) ;
V_30 -> V_47 = F_14 ( V_48 ) ;
V_31 = ( T_2 * ) F_13 ( V_28 , 9 ) ;
* V_31 ++ = V_49 ;
* V_31 ++ = type ;
* V_31 ++ = V_4 -> V_22 ;
if ( V_50 == type ) {
F_15 ( V_51 , L_4 ) ;
F_16 ( V_27 , V_31 ) ;
V_31 += 2 ;
}
F_16 ( V_4 -> V_19 . V_20 , V_31 ) ;
V_31 += 2 ;
F_16 ( V_4 -> V_21 , V_31 ) ;
V_31 += 2 ;
if ( V_52 == type ) {
memcpy ( V_31 , ( T_2 * ) & ( V_4 -> V_23 ) , 2 ) ;
V_31 += 2 ;
}
F_17 ( V_53 | V_35 , V_28 -> V_39 , V_28 -> V_32 ) ;
return V_28 ;
}
static struct V_25 * F_18 ( struct V_1 * V_2 , T_2 * V_54 ,
struct V_3 * V_4 ,
enum V_55 V_56 , T_1 V_57 )
{
union V_58 V_59 ;
struct V_25 * V_28 = NULL ;
struct V_29 * V_60 = NULL ;
T_2 * V_31 = NULL ;
T_1 V_32 = 6 + V_2 -> V_33 ;
if ( F_19 () )
F_10 ( V_34 | V_35 ,
L_5 ,
V_36 , V_57 , V_54 ) ;
memset ( & V_59 , 0 , 2 ) ;
V_59 . V_61 . V_62 = ( V_56 == V_63 ) ? 1 : 0 ;
V_59 . V_61 . V_64 = V_4 -> V_19 . V_61 . V_64 ;
V_28 = F_11 ( V_32 + sizeof( struct V_29 ) ) ;
if ( V_28 == NULL ) {
F_10 ( V_38 , L_3 ) ;
return NULL ;
}
F_12 ( V_28 , V_2 -> V_33 ) ;
V_60 = (struct V_29 * ) F_13 ( V_28 ,
sizeof( struct V_29 ) ) ;
memcpy ( V_60 -> V_40 , V_54 , V_41 ) ;
memcpy ( V_60 -> V_42 , V_2 -> V_37 -> V_43 , V_41 ) ;
memcpy ( V_60 -> V_44 , V_2 -> V_45 . V_46 , V_41 ) ;
V_60 -> V_47 = F_14 ( V_48 ) ;
V_31 = ( T_2 * ) F_13 ( V_28 , 6 ) ;
* V_31 ++ = V_49 ;
* V_31 ++ = V_65 ;
F_16 ( V_59 . V_20 , V_31 ) ;
V_31 += 2 ;
F_16 ( V_57 , V_31 ) ;
V_31 += 2 ;
F_17 ( V_53 | V_35 , V_28 -> V_39 , V_28 -> V_32 ) ;
if ( F_19 () )
F_10 ( V_34 | V_35 , L_6 ,
V_36 ) ;
return V_28 ;
}
static void F_20 ( struct V_1 * V_2 , T_2 * V_54 ,
struct V_3 * V_4 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_9 ( V_2 , V_54 , V_4 , 0 , V_52 ) ;
if ( V_28 ) {
F_15 ( V_51 , L_7 ) ;
F_21 ( V_28 , V_2 ) ;
} else {
F_10 ( V_38 ,
L_8 , V_36 ) ;
}
}
static void F_22 ( struct V_1 * V_2 , T_2 * V_54 ,
struct V_3 * V_4 , T_1 V_27 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_9 ( V_2 , V_54 , V_4 , V_27 , V_50 ) ;
if ( V_28 )
F_21 ( V_28 , V_2 ) ;
else
F_10 ( V_38 ,
L_8 , V_36 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 * V_54 ,
struct V_3 * V_4 , enum V_55 V_56 ,
T_1 V_57 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_18 ( V_2 , V_54 , V_4 , V_56 , V_57 ) ;
if ( V_28 )
F_21 ( V_28 , V_2 ) ;
else
F_10 ( V_38 ,
L_8 , V_36 ) ;
}
int F_24 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_66 = NULL ;
T_1 V_67 = 0 ;
T_2 * V_54 = NULL , * V_68 = NULL , * V_31 = NULL ;
struct V_3 * V_4 = NULL ;
union V_69 * V_70 = NULL ;
T_1 * V_71 = NULL ;
union V_72 * V_73 = NULL ;
struct V_15 * V_74 = NULL ;
if ( V_28 -> V_32 < sizeof( struct V_29 ) + 9 ) {
F_10 ( V_38 ,
L_9 ,
( int ) V_28 -> V_32 ,
( int ) ( sizeof( struct V_29 ) + 9 ) ) ;
return - 1 ;
}
F_17 ( V_53 | V_35 , V_28 -> V_39 , V_28 -> V_32 ) ;
V_66 = (struct V_29 * ) V_28 -> V_39 ;
V_31 = ( T_2 * ) V_66 ;
V_54 = ( T_2 * ) ( & V_66 -> V_42 [ 0 ] ) ;
V_31 += sizeof( struct V_29 ) ;
V_68 = V_31 + 2 ;
V_70 = (union V_69 * ) ( V_31 + 3 ) ;
V_71 = ( T_1 * ) ( V_31 + 5 ) ;
V_73 = (union V_72 * ) ( V_66 + 7 ) ;
F_15 ( V_51 , L_10 , V_54 ) ;
if ( V_2 -> V_45 . V_75 . V_76 == 0 ||
( V_2 -> V_77 -> V_78 == false ) ||
( V_2 -> V_77 -> V_79 & V_80 ) ) {
V_67 = V_81 ;
F_10 ( V_38 ,
L_11 ,
V_2 -> V_45 . V_75 . V_76 ,
V_2 -> V_77 -> V_78 ) ;
goto V_82;
}
if ( ! F_25 ( V_2 , (struct V_83 * * ) ( & V_74 ) , V_54 ,
( T_2 ) ( V_70 -> V_61 . V_64 ) , V_84 , true ) ) {
V_67 = V_81 ;
F_10 ( V_38 , L_12 , V_36 ) ;
goto V_82;
}
V_4 = & V_74 -> V_18 ;
if ( V_70 -> V_61 . V_85 == V_86 ) {
V_67 = V_87 ;
F_10 ( V_38 ,
L_13 , V_36 ) ;
goto V_82;
}
F_26 ( V_2 , V_74 ) ;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_22 = * V_68 ;
V_4 -> V_19 = * V_70 ;
V_4 -> V_21 = * V_71 ;
V_4 -> V_23 = * V_73 ;
if ( V_2 -> V_88 ( V_2 -> V_37 ) ||
( V_2 -> V_77 -> V_79 & V_89 ) )
V_4 -> V_19 . V_61 . V_90 = 1 ;
else
V_4 -> V_19 . V_61 . V_90 = 32 ;
F_1 ( V_2 , V_4 , 0 ) ;
F_22 ( V_2 , V_54 , V_4 , V_91 ) ;
return 0 ;
V_82:
{
struct V_3 V_92 ;
V_92 . V_19 = * V_70 ;
V_92 . V_21 = * V_71 ;
V_92 . V_22 = * V_68 ;
V_92 . V_19 . V_61 . V_85 = V_93 ;
F_22 ( V_2 , V_54 , & V_92 , V_67 ) ;
return 0 ;
}
}
int F_27 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_94 = NULL ;
struct V_3 * V_95 , * V_96 ;
struct V_8 * V_74 = NULL ;
T_2 * V_54 = NULL , * V_68 = NULL , * V_31 = NULL ;
T_1 * V_97 = NULL , * V_71 = NULL ;
union V_69 * V_70 = NULL ;
T_1 V_57 ;
if ( V_28 -> V_32 < sizeof( struct V_29 ) + 9 ) {
F_10 ( V_38 ,
L_14 ,
( int ) V_28 -> V_32 ,
( int ) ( sizeof( struct V_29 ) + 9 ) ) ;
return - 1 ;
}
V_94 = (struct V_29 * ) V_28 -> V_39 ;
V_31 = ( T_2 * ) V_94 ;
V_54 = ( T_2 * ) ( & V_94 -> V_42 [ 0 ] ) ;
V_31 += sizeof( struct V_29 ) ;
V_68 = V_31 + 2 ;
V_97 = ( T_1 * ) ( V_31 + 3 ) ;
V_70 = (union V_69 * ) ( V_31 + 5 ) ;
V_71 = ( T_1 * ) ( V_31 + 7 ) ;
F_15 ( V_51 , L_15 , V_54 ) ;
if ( V_2 -> V_45 . V_75 . V_76 == 0 ||
V_2 -> V_77 -> V_78 == false ||
V_2 -> V_77 -> V_98 == false ) {
F_10 ( V_38 ,
L_16 ,
V_2 -> V_45 . V_75 . V_76 ,
V_2 -> V_77 -> V_78 ,
V_2 -> V_77 -> V_98 ) ;
V_57 = V_99 ;
goto V_100;
}
if ( ! F_25 ( V_2 , (struct V_83 * * ) ( & V_74 ) , V_54 ,
( T_2 ) ( V_70 -> V_61 . V_64 ) , V_63 , false ) ) {
F_10 ( V_38 , L_12 , V_36 ) ;
V_57 = V_99 ;
goto V_100;
}
V_74 -> V_101 = false ;
V_95 = & V_74 -> V_13 ;
V_96 = & V_74 -> V_11 ;
if ( V_96 -> V_5 == true ) {
F_10 ( V_35 ,
L_17 ) ;
return - 1 ;
} else if ( ( V_95 -> V_5 == false ) ||
( * V_68 != V_95 -> V_22 ) ) {
F_10 ( V_38 ,
L_18 ) ;
V_57 = V_99 ;
goto V_100;
} else {
F_10 ( V_35 ,
L_19 ,
* V_97 ) ;
F_4 ( V_2 , V_95 ) ;
}
if ( * V_97 == V_91 ) {
if ( V_70 -> V_61 . V_85 == V_86 ) {
V_74 -> V_102 = true ;
F_4 ( V_2 , V_96 ) ;
V_57 = V_103 ;
goto V_100;
}
V_96 -> V_22 = * V_68 ;
V_96 -> V_21 = * V_71 ;
V_96 -> V_23 = V_95 -> V_23 ;
V_96 -> V_19 = * V_70 ;
F_4 ( V_2 , V_96 ) ;
F_1 ( V_2 , V_96 , * V_71 ) ;
} else {
V_74 -> V_102 = true ;
V_74 -> V_104 = true ;
V_57 = V_103 ;
goto V_100;
}
return 0 ;
V_100:
{
struct V_3 V_92 ;
V_92 . V_19 = * V_70 ;
F_23 ( V_2 , V_54 , & V_92 , V_63 , V_57 ) ;
return 0 ;
}
}
int F_28 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_105 = NULL ;
union V_58 * V_106 = NULL ;
T_1 * V_107 = NULL ;
T_2 * V_54 = NULL ;
if ( V_28 -> V_32 < sizeof( struct V_29 ) + 6 ) {
F_10 ( V_38 ,
L_20 ,
( int ) V_28 -> V_32 ,
( int ) ( sizeof( struct V_29 ) + 6 ) ) ;
return - 1 ;
}
if ( V_2 -> V_45 . V_75 . V_76 == 0 ||
V_2 -> V_77 -> V_78 == false ) {
F_10 ( V_38 ,
L_21 ,
V_2 -> V_45 . V_75 . V_76 ,
V_2 -> V_77 -> V_78 ) ;
return - 1 ;
}
F_17 ( V_53 | V_35 , V_28 -> V_39 , V_28 -> V_32 ) ;
V_105 = (struct V_29 * ) V_28 -> V_39 ;
V_54 = ( T_2 * ) ( & V_105 -> V_42 [ 0 ] ) ;
V_105 += sizeof( struct V_29 ) ;
V_106 = (union V_58 * ) ( V_105 + 2 ) ;
V_107 = ( T_1 * ) ( V_105 + 4 ) ;
if ( V_106 -> V_61 . V_62 == 1 ) {
struct V_15 * V_16 ;
if ( ! F_25 ( V_2 , (struct V_83 * * ) & V_16 , V_54 ,
( T_2 ) V_106 -> V_61 . V_64 , V_84 , false ) ) {
F_10 ( V_38 ,
L_22 ,
V_36 , V_54 ,
( T_2 ) V_106 -> V_61 . V_64 ) ;
return - 1 ;
}
F_7 ( V_2 , V_16 ) ;
} else {
struct V_8 * V_9 ;
if ( ! F_25 ( V_2 , (struct V_83 * * ) & V_9 , V_54 ,
( T_2 ) V_106 -> V_61 . V_64 , V_63 , false ) ) {
F_10 ( V_38 ,
L_23 ,
V_36 ) ;
return - 1 ;
}
V_9 -> V_108 = false ;
V_9 -> V_101 = false ;
V_9 -> V_102 = false ;
F_5 ( & V_9 -> V_109 ) ;
F_6 ( V_2 , V_9 ) ;
}
return 0 ;
}
void F_29 ( struct V_1 * V_2 , struct V_8 * V_74 ,
T_2 V_110 , T_2 V_111 )
{
struct V_3 * V_4 = & V_74 -> V_13 ;
if ( V_4 -> V_5 == true && V_111 == false )
return;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_22 ++ ;
V_4 -> V_19 . V_61 . V_112 = 0 ;
V_4 -> V_19 . V_61 . V_85 = V_110 ;
V_4 -> V_19 . V_61 . V_64 =
V_74 -> V_113 . V_114 . V_115 . V_116 . V_61 . V_117 ;
V_4 -> V_19 . V_61 . V_90 = 32 ;
V_4 -> V_21 = 0 ;
V_4 -> V_23 . V_61 . V_118 = ( V_74 -> V_119 + 3 ) % 4096 ;
F_1 ( V_2 , V_4 , V_120 ) ;
F_20 ( V_2 , V_74 -> V_113 . V_121 , V_4 ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_83 * V_122 ,
enum V_55 V_56 )
{
if ( V_56 == V_63 ) {
struct V_8 * V_9 =
(struct V_8 * ) V_122 ;
if ( F_6 ( V_2 , V_9 ) )
F_23 ( V_2 , V_122 -> V_121 ,
( V_9 -> V_11 . V_5 ) ?
( & V_9 -> V_11 ) :
( & V_9 -> V_13 ) ,
V_56 , V_103 ) ;
} else if ( V_56 == V_84 ) {
struct V_15 * V_16 =
(struct V_15 * ) V_122 ;
if ( F_7 ( V_2 , V_16 ) )
F_23 ( V_2 , V_122 -> V_121 ,
& V_16 -> V_18 ,
V_56 , V_103 ) ;
}
}
void F_31 ( unsigned long V_39 )
{
struct V_8 * V_9 = (struct V_8 * ) V_39 ;
V_9 -> V_101 = false ;
V_9 -> V_102 = true ;
V_9 -> V_13 . V_5 = false ;
}
void F_32 ( unsigned long V_39 )
{
struct V_8 * V_9 = (struct V_8 * ) V_39 ;
struct V_1 * V_2 = F_33 ( V_9 , struct V_1 ,
V_123 [ V_9 -> V_124 ] ) ;
F_6 ( V_2 , V_9 ) ;
F_23 ( V_2 , V_9 -> V_113 . V_121 ,
& V_9 -> V_11 , V_63 ,
V_125 ) ;
}
void F_34 ( unsigned long V_39 )
{
struct V_15 * V_16 = (struct V_15 * ) V_39 ;
struct V_1 * V_2 = F_33 ( V_16 , struct V_1 ,
V_126 [ V_16 -> V_124 ] ) ;
F_7 ( V_2 , V_16 ) ;
F_23 ( V_2 , V_16 -> V_113 . V_121 ,
& V_16 -> V_18 , V_84 ,
V_125 ) ;
}
