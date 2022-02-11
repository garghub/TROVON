static inline unsigned int F_1 ( unsigned int V_1 , unsigned int V_2 )
{
return ( V_2 - V_1 + 16 ) & 0x7 ;
}
static inline void * F_2 ( T_1 * V_3 , T_1 V_4 )
{
if ( ! V_3 )
return NULL ;
if ( V_4 == 1 ) {
V_3 [ 0 ] = V_5 ;
} else if ( V_4 > 1 ) {
V_3 [ 0 ] = V_6 ;
V_3 [ 1 ] = V_4 - 2 ;
if ( V_4 > 2 )
memset ( V_3 + 2 , 0 , V_3 [ 1 ] ) ;
}
return V_3 + V_4 ;
}
static inline void F_3 ( struct V_7 * V_8 , T_2 V_9 , int V_10 )
{
F_4 ( V_8 , V_11 , V_9 , V_10 ) ;
}
static int F_5 ( int type )
{
int V_1 = 0 ;
switch ( type ) {
case V_12 :
V_1 = 0 ;
break;
case V_13 :
case V_14 :
case V_15 :
case V_16 :
V_1 = 1 ;
break;
case V_17 :
case V_18 :
case V_19 :
V_1 = 2 ;
break;
}
return V_1 ;
}
static int F_6 ( struct V_20 * V_21 , struct V_7 * V_8 )
{
struct V_22 V_23 ;
const struct V_22 * V_24 ;
V_24 = F_7 ( V_8 , F_8 ( V_8 ) ,
sizeof( V_23 ) , & V_23 ) ;
if ( ! V_24 )
return - 1 ;
if ( ( ( V_24 -> V_25 + 1 ) << 3 ) > V_8 -> V_1 )
return - 1 ;
if ( V_24 -> V_25 < F_5 ( V_24 -> V_26 ) ) {
F_9 ( V_27 L_1 ,
V_24 -> V_25 , F_5 ( V_24 -> V_26 ) ) ;
F_3 ( V_8 , 0 , F_10 ( struct V_22 , V_25 ) +
F_11 ( V_8 ) ) ;
return - 1 ;
}
if ( V_24 -> V_28 != V_29 ) {
F_9 ( V_27 L_2 ,
V_24 -> V_28 ) ;
F_3 ( V_8 , 0 , F_10 ( struct V_22 , V_28 ) +
F_11 ( V_8 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_12 ( struct V_30 * V_31 , struct V_7 * V_8 )
{
const struct V_32 * V_33 = F_13 ( V_8 ) ;
struct V_34 * V_35 = (struct V_34 * ) V_8 -> V_3 ;
int V_36 = V_35 -> V_37 ;
F_14 ( & V_31 -> V_38 ) ;
if ( ! F_15 ( & V_33 -> V_39 , (struct V_40 * ) V_31 -> V_41 ) &&
! F_16 ( (struct V_40 * ) V_31 -> V_41 ) )
V_36 = - V_42 ;
F_17 ( & V_31 -> V_38 ) ;
return V_36 ;
}
static int F_18 ( struct V_30 * V_31 , struct V_7 * V_8 )
{
struct V_32 * V_33 ;
struct V_34 * V_43 ;
struct V_44 * V_45 ;
T_2 V_37 ;
int V_1 ;
F_19 ( V_8 , - F_20 ( V_8 ) ) ;
V_33 = F_13 ( V_8 ) ;
V_37 = * F_21 ( V_8 ) ;
* F_21 ( V_8 ) = V_46 ;
V_43 = (struct V_34 * ) F_22 ( V_8 ) ;
V_43 -> V_37 = V_37 ;
V_45 = F_2 ( ( char * ) ( V_43 + 1 ) ,
F_1 ( sizeof( * V_43 ) , 6 ) ) ;
V_45 -> type = V_47 ;
F_23 ( sizeof( * V_45 ) != 18 ) ;
V_45 -> V_48 = sizeof( * V_45 ) - 2 ;
V_1 = ( ( char * ) V_45 - ( char * ) V_43 ) + sizeof( * V_45 ) ;
memcpy ( & V_45 -> V_49 , & V_33 -> V_39 , sizeof( V_45 -> V_49 ) ) ;
F_24 ( & V_31 -> V_38 ) ;
memcpy ( & V_33 -> V_39 , V_31 -> V_41 , sizeof( V_33 -> V_39 ) ) ;
F_25 ( & V_31 -> V_38 ) ;
F_26 ( V_1 != V_31 -> V_50 . V_51 ) ;
V_43 -> V_52 = ( V_31 -> V_50 . V_51 >> 3 ) - 1 ;
return 0 ;
}
static inline int F_27 ( struct V_53 * V_54 ,
const struct V_40 * V_55 ,
const struct V_40 * V_56 , int V_57 )
{
int V_58 = 0 ;
F_24 ( & V_59 . V_38 ) ;
if ( V_59 . V_54 . V_60 != V_54 -> V_60 ||
V_59 . V_54 . V_61 != V_54 -> V_61 ||
V_59 . V_57 != V_57 ||
! F_15 ( & V_59 . V_56 , V_56 ) ||
! F_15 ( & V_59 . V_55 , V_55 ) ) {
V_59 . V_54 . V_60 = V_54 -> V_60 ;
V_59 . V_54 . V_61 = V_54 -> V_61 ;
V_59 . V_57 = V_57 ;
V_59 . V_56 = * V_56 ;
V_59 . V_55 = * V_55 ;
V_58 = 1 ;
}
F_25 ( & V_59 . V_38 ) ;
return V_58 ;
}
static int F_28 ( struct V_30 * V_31 , struct V_7 * V_8 ,
const struct V_62 * V_63 )
{
struct V_64 * V_64 = F_29 ( V_31 ) ;
struct V_65 * V_66 = (struct V_65 * ) V_8 -> V_67 ;
const struct V_68 * V_69 = & V_63 -> V_70 . V_71 ;
struct V_44 * V_45 = NULL ;
struct V_72 V_73 ;
int V_74 ;
struct V_53 V_54 ;
int V_36 = 0 ;
if ( F_30 ( V_69 -> V_75 == V_76 &&
V_69 -> V_77 <= V_78 ) )
goto V_79;
if ( F_31 ( V_66 -> V_80 ) ) {
V_74 = F_32 ( V_8 , V_66 -> V_80 , V_47 ) ;
if ( F_31 ( V_74 >= 0 ) )
V_45 = (struct V_44 * )
( F_33 ( V_8 ) + V_74 ) ;
}
F_34 ( V_8 , & V_54 ) ;
if ( ! F_27 ( & V_54 , & F_13 ( V_8 ) -> V_81 ,
V_45 ? & V_45 -> V_49 : & F_13 ( V_8 ) -> V_39 ,
V_66 -> V_57 ) )
goto V_79;
memset ( & V_73 , 0 , sizeof( V_73 ) ) ;
memcpy ( & V_73 . V_81 , ( V_82 * ) & F_13 ( V_8 ) -> V_81 ,
sizeof( V_73 . V_81 ) ) ;
V_73 . V_83 = 128 ;
memcpy ( & V_73 . V_39 , ( V_82 * ) & F_13 ( V_8 ) -> V_39 ,
sizeof( V_73 . V_39 ) ) ;
V_73 . V_84 = 128 ;
V_73 . V_85 = V_86 ;
V_73 . V_87 = V_69 -> V_75 ;
V_73 . V_88 = F_35 ( V_63 , & V_69 -> V_89 ) ;
if ( V_73 . V_88 )
V_73 . V_90 = F_36 ( ~ 0 ) ;
V_73 . V_91 = F_37 ( V_63 , & V_69 -> V_89 ) ;
if ( V_73 . V_91 )
V_73 . V_92 = F_36 ( ~ 0 ) ;
V_73 . V_93 = V_69 -> V_94 ;
V_36 = F_38 ( V_64 , V_46 , & V_73 ,
( V_45 ? ( V_82 * ) & V_45 -> V_49 : NULL ) ) ;
V_79:
return V_36 ;
}
static int F_39 ( struct V_30 * V_31 , struct V_7 * V_8 ,
T_2 * * V_37 )
{
T_3 V_74 = sizeof( struct V_32 ) ;
struct V_95 * V_96 =
(struct V_95 * ) ( F_13 ( V_8 ) + 1 ) ;
const unsigned char * V_97 = F_33 ( V_8 ) ;
unsigned int V_98 = F_40 ( V_8 ) -
F_33 ( V_8 ) ;
int V_99 = 0 ;
* V_37 = & F_13 ( V_8 ) -> V_37 ;
while ( V_74 + 1 <= V_98 ) {
switch ( * * V_37 ) {
case V_100 :
break;
case V_101 :
V_99 = 1 ;
break;
case V_102 :
if ( F_32 ( V_8 , V_74 , V_47 ) >= 0 ) {
F_9 ( V_103 L_3 ) ;
return V_74 ;
}
if ( V_99 )
return V_74 ;
break;
default:
return V_74 ;
}
V_74 += F_41 ( V_96 ) ;
* V_37 = & V_96 -> V_37 ;
V_96 = (struct V_95 * ) ( V_97 + V_74 ) ;
}
return V_74 ;
}
static int F_42 ( struct V_30 * V_31 )
{
if ( V_31 -> V_104 . V_105 ) {
F_43 ( L_4 , V_106 , V_31 -> V_104 . V_105 ) ;
return - V_107 ;
}
if ( V_31 -> V_50 . V_108 != V_109 ) {
F_43 ( L_5 ,
V_106 , V_109 , V_31 -> V_50 . V_108 ) ;
return - V_107 ;
}
V_31 -> V_50 . V_51 = sizeof( struct V_34 ) +
F_1 ( sizeof( struct V_34 ) , 6 ) +
sizeof( struct V_44 ) ;
F_26 ( V_31 -> V_50 . V_51 != 24 ) ;
return 0 ;
}
static void F_44 ( struct V_30 * V_31 )
{
}
static int F_45 ( struct V_30 * V_31 , struct V_7 * V_8 )
{
const struct V_32 * V_33 = F_13 ( V_8 ) ;
struct V_110 * V_111 = (struct V_110 * ) V_8 -> V_3 ;
int V_36 = V_111 -> V_112 . V_37 ;
F_14 ( & V_31 -> V_38 ) ;
if ( ! F_15 ( & V_33 -> V_81 , (struct V_40 * ) V_31 -> V_41 ) &&
! F_16 ( (struct V_40 * ) V_31 -> V_41 ) )
V_36 = - V_42 ;
F_17 ( & V_31 -> V_38 ) ;
return V_36 ;
}
static int F_46 ( struct V_30 * V_31 , struct V_7 * V_8 )
{
struct V_32 * V_33 ;
struct V_110 * V_111 ;
T_2 V_37 ;
F_19 ( V_8 , - F_20 ( V_8 ) ) ;
V_33 = F_13 ( V_8 ) ;
V_37 = * F_21 ( V_8 ) ;
* F_21 ( V_8 ) = V_113 ;
V_111 = (struct V_110 * ) F_22 ( V_8 ) ;
V_111 -> V_112 . V_37 = V_37 ;
V_111 -> V_112 . V_52 = ( V_31 -> V_50 . V_51 >> 3 ) - 1 ;
V_111 -> V_112 . type = V_114 ;
V_111 -> V_112 . V_115 = 1 ;
memset ( & V_111 -> V_116 , 0 , sizeof( V_111 -> V_116 ) ) ;
F_26 ( V_111 -> V_112 . V_52 != 2 ) ;
memcpy ( & V_111 -> V_49 , & V_33 -> V_81 , sizeof( V_111 -> V_49 ) ) ;
F_24 ( & V_31 -> V_38 ) ;
memcpy ( & V_33 -> V_81 , V_31 -> V_41 , sizeof( V_33 -> V_81 ) ) ;
F_25 ( & V_31 -> V_38 ) ;
return 0 ;
}
static int F_47 ( struct V_30 * V_31 , struct V_7 * V_8 ,
T_2 * * V_37 )
{
T_3 V_74 = sizeof( struct V_32 ) ;
struct V_95 * V_96 =
(struct V_95 * ) ( F_13 ( V_8 ) + 1 ) ;
const unsigned char * V_97 = F_33 ( V_8 ) ;
unsigned int V_98 = F_40 ( V_8 ) -
F_33 ( V_8 ) ;
int V_99 = 0 ;
* V_37 = & F_13 ( V_8 ) -> V_37 ;
while ( V_74 + 1 <= V_98 ) {
switch ( * * V_37 ) {
case V_100 :
break;
case V_101 :
if ( V_74 + 3 <= V_98 ) {
struct V_117 * V_118 ;
V_118 = (struct V_117 * ) ( V_97 + V_74 ) ;
if ( V_118 -> type != 0 )
return V_74 ;
}
V_99 = 1 ;
break;
case V_102 :
if ( F_32 ( V_8 , V_74 , V_47 ) >= 0 )
return V_74 ;
if ( V_99 )
return V_74 ;
break;
default:
return V_74 ;
}
V_74 += F_41 ( V_96 ) ;
* V_37 = & V_96 -> V_37 ;
V_96 = (struct V_95 * ) ( V_97 + V_74 ) ;
}
return V_74 ;
}
static int F_48 ( struct V_30 * V_31 )
{
if ( V_31 -> V_104 . V_105 ) {
F_43 ( L_4 , V_106 , V_31 -> V_104 . V_105 ) ;
return - V_107 ;
}
if ( V_31 -> V_50 . V_108 != V_109 ) {
F_43 ( L_5 ,
V_106 , V_109 , V_31 -> V_50 . V_108 ) ;
return - V_107 ;
}
V_31 -> V_50 . V_51 = sizeof( struct V_110 ) ;
return 0 ;
}
static void F_49 ( struct V_30 * V_31 )
{
}
static int T_4 F_50 ( void )
{
F_43 ( L_6 ) ;
if ( F_51 ( & V_119 , V_86 ) < 0 ) {
F_43 ( L_7 , V_106 ) ;
goto V_120;
}
if ( F_51 ( & V_121 , V_86 ) < 0 ) {
F_43 ( L_8 , V_106 ) ;
goto V_122;
}
if ( F_52 ( F_6 ) < 0 ) {
F_43 ( L_9 , V_106 ) ;
goto V_123;
}
return 0 ;
V_123:
F_53 ( & V_121 , V_86 ) ;
V_122:
F_53 ( & V_119 , V_86 ) ;
V_120:
return - V_124 ;
}
static void T_5 F_54 ( void )
{
if ( F_55 ( F_6 ) < 0 )
F_43 ( L_10 , V_106 ) ;
if ( F_53 ( & V_121 , V_86 ) < 0 )
F_43 ( L_11 , V_106 ) ;
if ( F_53 ( & V_119 , V_86 ) < 0 )
F_43 ( L_12 , V_106 ) ;
}
