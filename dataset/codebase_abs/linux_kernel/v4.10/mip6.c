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
F_9 ( L_1 ,
V_24 -> V_25 ,
F_5 ( V_24 -> V_26 ) ) ;
F_3 ( V_8 , 0 , F_10 ( struct V_22 , V_25 ) +
F_11 ( V_8 ) ) ;
return - 1 ;
}
if ( V_24 -> V_27 != V_28 ) {
F_9 ( L_2 ,
V_24 -> V_27 ) ;
F_3 ( V_8 , 0 , F_10 ( struct V_22 , V_27 ) +
F_11 ( V_8 ) ) ;
return - 1 ;
}
return 0 ;
}
static int F_12 ( struct V_29 * V_30 , struct V_7 * V_8 )
{
const struct V_31 * V_32 = F_13 ( V_8 ) ;
struct V_33 * V_34 = (struct V_33 * ) V_8 -> V_3 ;
int V_35 = V_34 -> V_36 ;
F_14 ( & V_30 -> V_37 ) ;
if ( ! F_15 ( & V_32 -> V_38 , (struct V_39 * ) V_30 -> V_40 ) &&
! F_16 ( (struct V_39 * ) V_30 -> V_40 ) )
V_35 = - V_41 ;
F_17 ( & V_30 -> V_37 ) ;
return V_35 ;
}
static int F_18 ( struct V_29 * V_30 , struct V_7 * V_8 )
{
struct V_31 * V_32 ;
struct V_33 * V_42 ;
struct V_43 * V_44 ;
T_2 V_36 ;
int V_1 ;
F_19 ( V_8 , - F_20 ( V_8 ) ) ;
V_32 = F_13 ( V_8 ) ;
V_36 = * F_21 ( V_8 ) ;
* F_21 ( V_8 ) = V_45 ;
V_42 = (struct V_33 * ) F_22 ( V_8 ) ;
V_42 -> V_36 = V_36 ;
V_44 = F_2 ( ( char * ) ( V_42 + 1 ) ,
F_1 ( sizeof( * V_42 ) , 6 ) ) ;
V_44 -> type = V_46 ;
F_23 ( sizeof( * V_44 ) != 18 ) ;
V_44 -> V_47 = sizeof( * V_44 ) - 2 ;
V_1 = ( ( char * ) V_44 - ( char * ) V_42 ) + sizeof( * V_44 ) ;
memcpy ( & V_44 -> V_48 , & V_32 -> V_38 , sizeof( V_44 -> V_48 ) ) ;
F_24 ( & V_30 -> V_37 ) ;
memcpy ( & V_32 -> V_38 , V_30 -> V_40 , sizeof( V_32 -> V_38 ) ) ;
F_25 ( & V_30 -> V_37 ) ;
F_26 ( V_1 != V_30 -> V_49 . V_50 ) ;
V_42 -> V_51 = ( V_30 -> V_49 . V_50 >> 3 ) - 1 ;
return 0 ;
}
static inline int F_27 ( T_3 V_52 ,
const struct V_39 * V_53 ,
const struct V_39 * V_54 , int V_55 )
{
int V_56 = 0 ;
F_24 ( & V_57 . V_37 ) ;
if ( V_57 . V_52 != V_52 ||
V_57 . V_55 != V_55 ||
! F_15 ( & V_57 . V_54 , V_54 ) ||
! F_15 ( & V_57 . V_53 , V_53 ) ) {
V_57 . V_52 = V_52 ;
V_57 . V_55 = V_55 ;
V_57 . V_54 = * V_54 ;
V_57 . V_53 = * V_53 ;
V_56 = 1 ;
}
F_25 ( & V_57 . V_37 ) ;
return V_56 ;
}
static int F_28 ( struct V_29 * V_30 , struct V_7 * V_8 ,
const struct V_58 * V_59 )
{
struct V_60 * V_60 = F_29 ( V_30 ) ;
struct V_61 * V_62 = (struct V_61 * ) V_8 -> V_63 ;
const struct V_64 * V_65 = & V_59 -> V_66 . V_67 ;
struct V_43 * V_44 = NULL ;
struct V_68 V_69 ;
int V_70 ;
T_3 V_52 ;
int V_35 = 0 ;
if ( F_30 ( V_65 -> V_71 == V_72 &&
V_65 -> V_73 <= V_74 ) )
goto V_75;
if ( F_31 ( V_62 -> V_76 ) ) {
V_70 = F_32 ( V_8 , V_62 -> V_76 , V_46 ) ;
if ( F_31 ( V_70 >= 0 ) )
V_44 = (struct V_43 * )
( F_33 ( V_8 ) + V_70 ) ;
}
V_52 = F_34 ( V_8 ) ;
if ( ! F_27 ( V_52 , & F_13 ( V_8 ) -> V_77 ,
V_44 ? & V_44 -> V_48 : & F_13 ( V_8 ) -> V_38 ,
V_62 -> V_55 ) )
goto V_75;
memset ( & V_69 , 0 , sizeof( V_69 ) ) ;
memcpy ( & V_69 . V_77 , ( V_78 * ) & F_13 ( V_8 ) -> V_77 ,
sizeof( V_69 . V_77 ) ) ;
V_69 . V_79 = 128 ;
memcpy ( & V_69 . V_38 , ( V_78 * ) & F_13 ( V_8 ) -> V_38 ,
sizeof( V_69 . V_38 ) ) ;
V_69 . V_80 = 128 ;
V_69 . V_81 = V_82 ;
V_69 . V_83 = V_65 -> V_71 ;
V_69 . V_84 = F_35 ( V_59 , & V_65 -> V_85 ) ;
if ( V_69 . V_84 )
V_69 . V_86 = F_36 ( ~ 0 ) ;
V_69 . V_87 = F_37 ( V_59 , & V_65 -> V_85 ) ;
if ( V_69 . V_87 )
V_69 . V_88 = F_36 ( ~ 0 ) ;
V_69 . V_89 = V_65 -> V_90 ;
V_35 = F_38 ( V_60 , V_45 , & V_69 ,
( V_44 ? ( V_78 * ) & V_44 -> V_48 : NULL ) ) ;
V_75:
return V_35 ;
}
static int F_39 ( struct V_29 * V_30 , struct V_7 * V_8 ,
T_2 * * V_36 )
{
T_4 V_70 = sizeof( struct V_31 ) ;
struct V_91 * V_92 =
(struct V_91 * ) ( F_13 ( V_8 ) + 1 ) ;
const unsigned char * V_93 = F_33 ( V_8 ) ;
unsigned int V_94 = F_40 ( V_8 ) -
F_33 ( V_8 ) ;
int V_95 = 0 ;
* V_36 = & F_13 ( V_8 ) -> V_36 ;
while ( V_70 + 1 <= V_94 ) {
switch ( * * V_36 ) {
case V_96 :
break;
case V_97 :
V_95 = 1 ;
break;
case V_98 :
if ( F_32 ( V_8 , V_70 , V_46 ) >= 0 ) {
F_9 ( L_3 ) ;
return V_70 ;
}
if ( V_95 )
return V_70 ;
break;
default:
return V_70 ;
}
V_70 += F_41 ( V_92 ) ;
* V_36 = & V_92 -> V_36 ;
V_92 = (struct V_91 * ) ( V_93 + V_70 ) ;
}
return V_70 ;
}
static int F_42 ( struct V_29 * V_30 )
{
if ( V_30 -> V_99 . V_100 ) {
F_43 ( L_4 , V_101 , V_30 -> V_99 . V_100 ) ;
return - V_102 ;
}
if ( V_30 -> V_49 . V_103 != V_104 ) {
F_43 ( L_5 ,
V_101 , V_104 , V_30 -> V_49 . V_103 ) ;
return - V_102 ;
}
V_30 -> V_49 . V_50 = sizeof( struct V_33 ) +
F_1 ( sizeof( struct V_33 ) , 6 ) +
sizeof( struct V_43 ) ;
F_26 ( V_30 -> V_49 . V_50 != 24 ) ;
return 0 ;
}
static void F_44 ( struct V_29 * V_30 )
{
}
static int F_45 ( struct V_29 * V_30 , struct V_7 * V_8 )
{
const struct V_31 * V_32 = F_13 ( V_8 ) ;
struct V_105 * V_106 = (struct V_105 * ) V_8 -> V_3 ;
int V_35 = V_106 -> V_107 . V_36 ;
F_14 ( & V_30 -> V_37 ) ;
if ( ! F_15 ( & V_32 -> V_77 , (struct V_39 * ) V_30 -> V_40 ) &&
! F_16 ( (struct V_39 * ) V_30 -> V_40 ) )
V_35 = - V_41 ;
F_17 ( & V_30 -> V_37 ) ;
return V_35 ;
}
static int F_46 ( struct V_29 * V_30 , struct V_7 * V_8 )
{
struct V_31 * V_32 ;
struct V_105 * V_106 ;
T_2 V_36 ;
F_19 ( V_8 , - F_20 ( V_8 ) ) ;
V_32 = F_13 ( V_8 ) ;
V_36 = * F_21 ( V_8 ) ;
* F_21 ( V_8 ) = V_108 ;
V_106 = (struct V_105 * ) F_22 ( V_8 ) ;
V_106 -> V_107 . V_36 = V_36 ;
V_106 -> V_107 . V_51 = ( V_30 -> V_49 . V_50 >> 3 ) - 1 ;
V_106 -> V_107 . type = V_109 ;
V_106 -> V_107 . V_110 = 1 ;
memset ( & V_106 -> V_111 , 0 , sizeof( V_106 -> V_111 ) ) ;
F_26 ( V_106 -> V_107 . V_51 != 2 ) ;
memcpy ( & V_106 -> V_48 , & V_32 -> V_77 , sizeof( V_106 -> V_48 ) ) ;
F_24 ( & V_30 -> V_37 ) ;
memcpy ( & V_32 -> V_77 , V_30 -> V_40 , sizeof( V_32 -> V_77 ) ) ;
F_25 ( & V_30 -> V_37 ) ;
return 0 ;
}
static int F_47 ( struct V_29 * V_30 , struct V_7 * V_8 ,
T_2 * * V_36 )
{
T_4 V_70 = sizeof( struct V_31 ) ;
struct V_91 * V_92 =
(struct V_91 * ) ( F_13 ( V_8 ) + 1 ) ;
const unsigned char * V_93 = F_33 ( V_8 ) ;
unsigned int V_94 = F_40 ( V_8 ) -
F_33 ( V_8 ) ;
int V_95 = 0 ;
* V_36 = & F_13 ( V_8 ) -> V_36 ;
while ( V_70 + 1 <= V_94 ) {
switch ( * * V_36 ) {
case V_96 :
break;
case V_97 :
if ( V_70 + 3 <= V_94 ) {
struct V_112 * V_113 ;
V_113 = (struct V_112 * ) ( V_93 + V_70 ) ;
if ( V_113 -> type != 0 )
return V_70 ;
}
V_95 = 1 ;
break;
case V_98 :
if ( F_32 ( V_8 , V_70 , V_46 ) >= 0 )
return V_70 ;
if ( V_95 )
return V_70 ;
break;
default:
return V_70 ;
}
V_70 += F_41 ( V_92 ) ;
* V_36 = & V_92 -> V_36 ;
V_92 = (struct V_91 * ) ( V_93 + V_70 ) ;
}
return V_70 ;
}
static int F_48 ( struct V_29 * V_30 )
{
if ( V_30 -> V_99 . V_100 ) {
F_43 ( L_4 , V_101 , V_30 -> V_99 . V_100 ) ;
return - V_102 ;
}
if ( V_30 -> V_49 . V_103 != V_104 ) {
F_43 ( L_5 ,
V_101 , V_104 , V_30 -> V_49 . V_103 ) ;
return - V_102 ;
}
V_30 -> V_49 . V_50 = sizeof( struct V_105 ) ;
return 0 ;
}
static void F_49 ( struct V_29 * V_30 )
{
}
static int T_5 F_50 ( void )
{
F_43 ( L_6 ) ;
if ( F_51 ( & V_114 , V_82 ) < 0 ) {
F_43 ( L_7 , V_101 ) ;
goto V_115;
}
if ( F_51 ( & V_116 , V_82 ) < 0 ) {
F_43 ( L_8 , V_101 ) ;
goto V_117;
}
if ( F_52 ( F_6 ) < 0 ) {
F_43 ( L_9 , V_101 ) ;
goto V_118;
}
return 0 ;
V_118:
F_53 ( & V_116 , V_82 ) ;
V_117:
F_53 ( & V_114 , V_82 ) ;
V_115:
return - V_119 ;
}
static void T_6 F_54 ( void )
{
if ( F_55 ( F_6 ) < 0 )
F_43 ( L_10 , V_101 ) ;
if ( F_53 ( & V_116 , V_82 ) < 0 )
F_43 ( L_11 , V_101 ) ;
if ( F_53 ( & V_114 , V_82 ) < 0 )
F_43 ( L_12 , V_101 ) ;
}
