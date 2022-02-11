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
F_10 ( V_2 -> V_34 , L_1 ,
V_35 , type , V_26 , V_2 -> V_34 ) ;
if ( V_4 == NULL ) {
F_11 ( V_2 -> V_34 , L_2 ) ;
return NULL ;
}
V_28 = F_12 ( V_32 + sizeof( struct V_29 ) ) ;
if ( V_28 == NULL )
return NULL ;
memset ( V_28 -> V_36 , 0 , sizeof( struct V_29 ) ) ;
F_13 ( V_28 , V_2 -> V_33 ) ;
V_30 = (struct V_29 * ) F_14 ( V_28 ,
sizeof( struct V_29 ) ) ;
F_15 ( V_30 -> V_37 , V_26 ) ;
F_15 ( V_30 -> V_38 , V_2 -> V_34 -> V_39 ) ;
F_15 ( V_30 -> V_40 , V_2 -> V_41 . V_42 ) ;
V_30 -> V_43 = F_16 ( V_44 ) ;
V_31 = ( T_2 * ) F_14 ( V_28 , 9 ) ;
* V_31 ++ = V_45 ;
* V_31 ++ = type ;
* V_31 ++ = V_4 -> V_22 ;
if ( V_46 == type ) {
F_17 ( V_47 , L_3 ) ;
F_18 ( V_27 , V_31 ) ;
V_31 += 2 ;
}
F_18 ( V_4 -> V_19 . V_20 , V_31 ) ;
V_31 += 2 ;
F_18 ( V_4 -> V_21 , V_31 ) ;
V_31 += 2 ;
if ( V_48 == type ) {
memcpy ( V_31 , ( T_2 * ) & ( V_4 -> V_23 ) , 2 ) ;
V_31 += 2 ;
}
#ifdef F_19
F_20 ( L_4 , V_49 , V_28 -> V_36 ,
V_28 -> V_32 ) ;
#endif
return V_28 ;
}
static struct V_25 * F_21 ( struct V_1 * V_2 , T_2 * V_50 ,
struct V_3 * V_4 ,
enum V_51 V_52 , T_1 V_53 )
{
union V_54 V_55 ;
struct V_25 * V_28 = NULL ;
struct V_29 * V_56 = NULL ;
T_2 * V_31 = NULL ;
T_1 V_32 = 6 + V_2 -> V_33 ;
if ( F_22 () )
F_10 ( V_2 -> V_34 , L_5 ,
V_35 , V_53 , V_50 ) ;
memset ( & V_55 , 0 , 2 ) ;
V_55 . V_57 . V_58 = ( V_52 == V_59 ) ? 1 : 0 ;
V_55 . V_57 . V_60 = V_4 -> V_19 . V_57 . V_60 ;
V_28 = F_12 ( V_32 + sizeof( struct V_29 ) ) ;
if ( V_28 == NULL )
return NULL ;
F_13 ( V_28 , V_2 -> V_33 ) ;
V_56 = (struct V_29 * ) F_14 ( V_28 ,
sizeof( struct V_29 ) ) ;
F_15 ( V_56 -> V_37 , V_50 ) ;
F_15 ( V_56 -> V_38 , V_2 -> V_34 -> V_39 ) ;
F_15 ( V_56 -> V_40 , V_2 -> V_41 . V_42 ) ;
V_56 -> V_43 = F_16 ( V_44 ) ;
V_31 = ( T_2 * ) F_14 ( V_28 , 6 ) ;
* V_31 ++ = V_45 ;
* V_31 ++ = V_61 ;
F_18 ( V_55 . V_20 , V_31 ) ;
V_31 += 2 ;
F_18 ( V_53 , V_31 ) ;
V_31 += 2 ;
#ifdef F_19
F_20 ( L_6 , V_49 , V_28 -> V_36 ,
V_28 -> V_32 ) ;
#endif
return V_28 ;
}
static void F_23 ( struct V_1 * V_2 , T_2 * V_50 ,
struct V_3 * V_4 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_9 ( V_2 , V_50 , V_4 , 0 , V_48 ) ;
if ( V_28 ) {
F_17 ( V_47 , L_7 ) ;
F_24 ( V_28 , V_2 ) ;
} else {
F_10 ( V_2 -> V_34 , L_8 ) ;
}
}
static void F_25 ( struct V_1 * V_2 , T_2 * V_50 ,
struct V_3 * V_4 , T_1 V_27 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_9 ( V_2 , V_50 , V_4 , V_27 , V_46 ) ;
if ( V_28 )
F_24 ( V_28 , V_2 ) ;
else
F_10 ( V_2 -> V_34 , L_9 ) ;
}
static void F_26 ( struct V_1 * V_2 , T_2 * V_50 ,
struct V_3 * V_4 , enum V_51 V_52 ,
T_1 V_53 )
{
struct V_25 * V_28 = NULL ;
V_28 = F_21 ( V_2 , V_50 , V_4 , V_52 , V_53 ) ;
if ( V_28 )
F_24 ( V_28 , V_2 ) ;
else
F_10 ( V_2 -> V_34 , L_10 ) ;
}
int F_27 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_62 = NULL ;
T_1 V_63 = 0 ;
T_2 * V_50 = NULL , * V_64 = NULL , * V_31 = NULL ;
struct V_3 * V_4 = NULL ;
union V_65 * V_66 = NULL ;
T_1 * V_67 = NULL ;
union V_68 * V_69 = NULL ;
struct V_15 * V_70 = NULL ;
if ( V_28 -> V_32 < sizeof( struct V_29 ) + 9 ) {
F_11 ( V_2 -> V_34 , L_11 ,
( int ) V_28 -> V_32 ,
( int ) ( sizeof( struct V_29 ) + 9 ) ) ;
return - 1 ;
}
#ifdef F_19
F_20 ( L_12 , V_49 ,
V_28 -> V_36 , V_28 -> V_32 ) ;
#endif
V_62 = (struct V_29 * ) V_28 -> V_36 ;
V_31 = ( T_2 * ) V_62 ;
V_50 = ( T_2 * ) ( & V_62 -> V_38 [ 0 ] ) ;
V_31 += sizeof( struct V_29 ) ;
V_64 = V_31 + 2 ;
V_66 = (union V_65 * ) ( V_31 + 3 ) ;
V_67 = ( T_1 * ) ( V_31 + 5 ) ;
V_69 = (union V_68 * ) ( V_62 + 7 ) ;
F_17 ( V_47 , L_13 , V_50 ) ;
if ( V_2 -> V_41 . V_71 . V_72 == 0 ||
( V_2 -> V_73 -> V_74 == false ) ||
( V_2 -> V_73 -> V_75 & V_76 ) ) {
V_63 = V_77 ;
F_11 ( V_2 -> V_34 ,
L_14 ,
V_2 -> V_41 . V_71 . V_72 ,
V_2 -> V_73 -> V_74 ) ;
goto V_78;
}
if ( ! F_28 ( V_2 , (struct V_79 * * ) ( & V_70 ) , V_50 ,
( T_2 ) ( V_66 -> V_57 . V_60 ) , V_80 , true ) ) {
V_63 = V_77 ;
F_11 ( V_2 -> V_34 , L_15 , V_35 ) ;
goto V_78;
}
V_4 = & V_70 -> V_18 ;
if ( V_66 -> V_57 . V_81 == V_82 ) {
V_63 = V_83 ;
F_11 ( V_2 -> V_34 , L_16 ,
V_35 ) ;
goto V_78;
}
F_29 ( V_2 , V_70 ) ;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_22 = * V_64 ;
V_4 -> V_19 = * V_66 ;
V_4 -> V_21 = * V_67 ;
V_4 -> V_23 = * V_69 ;
if ( V_2 -> V_84 ( V_2 -> V_34 ) ||
( V_2 -> V_73 -> V_75 & V_85 ) )
V_4 -> V_19 . V_57 . V_86 = 1 ;
else
V_4 -> V_19 . V_57 . V_86 = 32 ;
F_1 ( V_2 , V_4 , 0 ) ;
F_25 ( V_2 , V_50 , V_4 , V_87 ) ;
return 0 ;
V_78:
{
struct V_3 V_88 ;
V_88 . V_19 = * V_66 ;
V_88 . V_21 = * V_67 ;
V_88 . V_22 = * V_64 ;
V_88 . V_19 . V_57 . V_81 = V_89 ;
F_25 ( V_2 , V_50 , & V_88 , V_63 ) ;
return 0 ;
}
}
int F_30 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_90 = NULL ;
struct V_3 * V_91 , * V_92 ;
struct V_8 * V_70 = NULL ;
T_2 * V_50 = NULL , * V_64 = NULL , * V_31 = NULL ;
T_1 * V_93 = NULL , * V_67 = NULL ;
union V_65 * V_66 = NULL ;
T_1 V_53 ;
if ( V_28 -> V_32 < sizeof( struct V_29 ) + 9 ) {
F_11 ( V_2 -> V_34 , L_17 ,
( int ) V_28 -> V_32 ,
( int ) ( sizeof( struct V_29 ) + 9 ) ) ;
return - 1 ;
}
V_90 = (struct V_29 * ) V_28 -> V_36 ;
V_31 = ( T_2 * ) V_90 ;
V_50 = ( T_2 * ) ( & V_90 -> V_38 [ 0 ] ) ;
V_31 += sizeof( struct V_29 ) ;
V_64 = V_31 + 2 ;
V_93 = ( T_1 * ) ( V_31 + 3 ) ;
V_66 = (union V_65 * ) ( V_31 + 5 ) ;
V_67 = ( T_1 * ) ( V_31 + 7 ) ;
F_17 ( V_47 , L_18 , V_50 ) ;
if ( V_2 -> V_41 . V_71 . V_72 == 0 ||
V_2 -> V_73 -> V_74 == false ||
V_2 -> V_73 -> V_94 == false ) {
F_11 ( V_2 -> V_34 ,
L_19 ,
V_2 -> V_41 . V_71 . V_72 ,
V_2 -> V_73 -> V_74 ,
V_2 -> V_73 -> V_94 ) ;
V_53 = V_95 ;
goto V_96;
}
if ( ! F_28 ( V_2 , (struct V_79 * * ) ( & V_70 ) , V_50 ,
( T_2 ) ( V_66 -> V_57 . V_60 ) , V_59 , false ) ) {
F_11 ( V_2 -> V_34 , L_15 , V_35 ) ;
V_53 = V_95 ;
goto V_96;
}
V_70 -> V_97 = false ;
V_91 = & V_70 -> V_13 ;
V_92 = & V_70 -> V_11 ;
if ( V_92 -> V_5 == true ) {
F_10 ( V_2 -> V_34 , L_20 ,
V_35 ) ;
return - 1 ;
} else if ( ( V_91 -> V_5 == false ) ||
( * V_64 != V_91 -> V_22 ) ) {
F_11 ( V_2 -> V_34 ,
L_21 ,
V_35 ) ;
V_53 = V_95 ;
goto V_96;
} else {
F_10 ( V_2 -> V_34 ,
L_22 ,
V_35 , * V_93 ) ;
F_4 ( V_2 , V_91 ) ;
}
if ( * V_93 == V_87 ) {
if ( V_66 -> V_57 . V_81 == V_82 ) {
V_70 -> V_98 = true ;
F_4 ( V_2 , V_92 ) ;
V_53 = V_99 ;
goto V_96;
}
V_92 -> V_22 = * V_64 ;
V_92 -> V_21 = * V_67 ;
V_92 -> V_23 = V_91 -> V_23 ;
V_92 -> V_19 = * V_66 ;
F_4 ( V_2 , V_92 ) ;
F_1 ( V_2 , V_92 , * V_67 ) ;
} else {
V_70 -> V_98 = true ;
V_70 -> V_100 = true ;
V_53 = V_99 ;
goto V_96;
}
return 0 ;
V_96:
{
struct V_3 V_88 ;
V_88 . V_19 = * V_66 ;
F_26 ( V_2 , V_50 , & V_88 , V_59 , V_53 ) ;
return 0 ;
}
}
int F_31 ( struct V_1 * V_2 , struct V_25 * V_28 )
{
struct V_29 * V_101 = NULL ;
union V_54 * V_102 = NULL ;
T_2 * V_50 = NULL ;
if ( V_28 -> V_32 < sizeof( struct V_29 ) + 6 ) {
F_11 ( V_2 -> V_34 , L_23 ,
( int ) V_28 -> V_32 ,
( int ) ( sizeof( struct V_29 ) + 6 ) ) ;
return - 1 ;
}
if ( V_2 -> V_41 . V_71 . V_72 == 0 ||
V_2 -> V_73 -> V_74 == false ) {
F_11 ( V_2 -> V_34 ,
L_24 ,
V_2 -> V_41 . V_71 . V_72 ,
V_2 -> V_73 -> V_74 ) ;
return - 1 ;
}
#ifdef F_19
F_20 ( L_25 , V_49 , V_28 -> V_36 ,
V_28 -> V_32 ) ;
#endif
V_101 = (struct V_29 * ) V_28 -> V_36 ;
V_50 = ( T_2 * ) ( & V_101 -> V_38 [ 0 ] ) ;
V_102 = (union V_54 * ) & V_101 -> V_103 [ 2 ] ;
if ( V_102 -> V_57 . V_58 == 1 ) {
struct V_15 * V_16 ;
if ( ! F_28 ( V_2 , (struct V_79 * * ) & V_16 , V_50 ,
( T_2 ) V_102 -> V_57 . V_60 , V_80 , false ) ) {
F_11 ( V_2 -> V_34 ,
L_26 ,
V_35 , V_50 ,
( T_2 ) V_102 -> V_57 . V_60 ) ;
return - 1 ;
}
F_7 ( V_2 , V_16 ) ;
} else {
struct V_8 * V_9 ;
if ( ! F_28 ( V_2 , (struct V_79 * * ) & V_9 , V_50 ,
( T_2 ) V_102 -> V_57 . V_60 , V_59 , false ) ) {
F_11 ( V_2 -> V_34 , L_27 ,
V_35 ) ;
return - 1 ;
}
V_9 -> V_104 = false ;
V_9 -> V_97 = false ;
V_9 -> V_98 = false ;
F_5 ( & V_9 -> V_105 ) ;
F_6 ( V_2 , V_9 ) ;
}
return 0 ;
}
void F_32 ( struct V_1 * V_2 , struct V_8 * V_70 ,
T_2 V_106 , T_2 V_107 )
{
struct V_3 * V_4 = & V_70 -> V_13 ;
if ( V_4 -> V_5 == true && V_107 == false )
return;
F_4 ( V_2 , V_4 ) ;
V_4 -> V_22 ++ ;
V_4 -> V_19 . V_57 . V_108 = 0 ;
V_4 -> V_19 . V_57 . V_81 = V_106 ;
V_4 -> V_19 . V_57 . V_60 =
V_70 -> V_109 . V_110 . V_111 . V_112 . V_57 . V_113 ;
V_4 -> V_19 . V_57 . V_86 = 32 ;
V_4 -> V_21 = 0 ;
V_4 -> V_23 . V_57 . V_114 = ( V_70 -> V_115 + 3 ) % 4096 ;
F_1 ( V_2 , V_4 , V_116 ) ;
F_23 ( V_2 , V_70 -> V_109 . V_117 , V_4 ) ;
}
void F_33 ( struct V_1 * V_2 ,
struct V_79 * V_118 ,
enum V_51 V_52 )
{
if ( V_52 == V_59 ) {
struct V_8 * V_9 =
(struct V_8 * ) V_118 ;
if ( F_6 ( V_2 , V_9 ) )
F_26 ( V_2 , V_118 -> V_117 ,
( V_9 -> V_11 . V_5 ) ?
( & V_9 -> V_11 ) :
( & V_9 -> V_13 ) ,
V_52 , V_99 ) ;
} else if ( V_52 == V_80 ) {
struct V_15 * V_16 =
(struct V_15 * ) V_118 ;
if ( F_7 ( V_2 , V_16 ) )
F_26 ( V_2 , V_118 -> V_117 ,
& V_16 -> V_18 ,
V_52 , V_99 ) ;
}
}
void F_34 ( unsigned long V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 ;
V_9 -> V_97 = false ;
V_9 -> V_98 = true ;
V_9 -> V_13 . V_5 = false ;
}
void F_35 ( unsigned long V_36 )
{
struct V_8 * V_9 = (struct V_8 * ) V_36 ;
struct V_1 * V_2 = F_36 ( V_9 , struct V_1 ,
V_119 [ V_9 -> V_120 ] ) ;
F_6 ( V_2 , V_9 ) ;
F_26 ( V_2 , V_9 -> V_109 . V_117 ,
& V_9 -> V_11 , V_59 ,
V_121 ) ;
}
void F_37 ( unsigned long V_36 )
{
struct V_15 * V_16 = (struct V_15 * ) V_36 ;
struct V_1 * V_2 = F_36 ( V_16 , struct V_1 ,
V_122 [ V_16 -> V_120 ] ) ;
F_7 ( V_2 , V_16 ) ;
F_26 ( V_2 , V_16 -> V_109 . V_117 ,
& V_16 -> V_18 , V_80 ,
V_121 ) ;
}
