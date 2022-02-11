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
static inline int F_27 ( struct V_52 * V_53 ,
const struct V_39 * V_54 ,
const struct V_39 * V_55 , int V_56 )
{
int V_57 = 0 ;
F_24 ( & V_58 . V_37 ) ;
if ( V_58 . V_53 . V_59 != V_53 -> V_59 ||
V_58 . V_53 . V_60 != V_53 -> V_60 ||
V_58 . V_56 != V_56 ||
! F_15 ( & V_58 . V_55 , V_55 ) ||
! F_15 ( & V_58 . V_54 , V_54 ) ) {
V_58 . V_53 . V_59 = V_53 -> V_59 ;
V_58 . V_53 . V_60 = V_53 -> V_60 ;
V_58 . V_56 = V_56 ;
V_58 . V_55 = * V_55 ;
V_58 . V_54 = * V_54 ;
V_57 = 1 ;
}
F_25 ( & V_58 . V_37 ) ;
return V_57 ;
}
static int F_28 ( struct V_29 * V_30 , struct V_7 * V_8 ,
const struct V_61 * V_62 )
{
struct V_63 * V_63 = F_29 ( V_30 ) ;
struct V_64 * V_65 = (struct V_64 * ) V_8 -> V_66 ;
const struct V_67 * V_68 = & V_62 -> V_69 . V_70 ;
struct V_43 * V_44 = NULL ;
struct V_71 V_72 ;
int V_73 ;
struct V_52 V_53 ;
int V_35 = 0 ;
if ( F_30 ( V_68 -> V_74 == V_75 &&
V_68 -> V_76 <= V_77 ) )
goto V_78;
if ( F_31 ( V_65 -> V_79 ) ) {
V_73 = F_32 ( V_8 , V_65 -> V_79 , V_46 ) ;
if ( F_31 ( V_73 >= 0 ) )
V_44 = (struct V_43 * )
( F_33 ( V_8 ) + V_73 ) ;
}
F_34 ( V_8 , & V_53 ) ;
if ( ! F_27 ( & V_53 , & F_13 ( V_8 ) -> V_80 ,
V_44 ? & V_44 -> V_48 : & F_13 ( V_8 ) -> V_38 ,
V_65 -> V_56 ) )
goto V_78;
memset ( & V_72 , 0 , sizeof( V_72 ) ) ;
memcpy ( & V_72 . V_80 , ( V_81 * ) & F_13 ( V_8 ) -> V_80 ,
sizeof( V_72 . V_80 ) ) ;
V_72 . V_82 = 128 ;
memcpy ( & V_72 . V_38 , ( V_81 * ) & F_13 ( V_8 ) -> V_38 ,
sizeof( V_72 . V_38 ) ) ;
V_72 . V_83 = 128 ;
V_72 . V_84 = V_85 ;
V_72 . V_86 = V_68 -> V_74 ;
V_72 . V_87 = F_35 ( V_62 , & V_68 -> V_88 ) ;
if ( V_72 . V_87 )
V_72 . V_89 = F_36 ( ~ 0 ) ;
V_72 . V_90 = F_37 ( V_62 , & V_68 -> V_88 ) ;
if ( V_72 . V_90 )
V_72 . V_91 = F_36 ( ~ 0 ) ;
V_72 . V_92 = V_68 -> V_93 ;
V_35 = F_38 ( V_63 , V_45 , & V_72 ,
( V_44 ? ( V_81 * ) & V_44 -> V_48 : NULL ) ) ;
V_78:
return V_35 ;
}
static int F_39 ( struct V_29 * V_30 , struct V_7 * V_8 ,
T_2 * * V_36 )
{
T_3 V_73 = sizeof( struct V_31 ) ;
struct V_94 * V_95 =
(struct V_94 * ) ( F_13 ( V_8 ) + 1 ) ;
const unsigned char * V_96 = F_33 ( V_8 ) ;
unsigned int V_97 = F_40 ( V_8 ) -
F_33 ( V_8 ) ;
int V_98 = 0 ;
* V_36 = & F_13 ( V_8 ) -> V_36 ;
while ( V_73 + 1 <= V_97 ) {
switch ( * * V_36 ) {
case V_99 :
break;
case V_100 :
V_98 = 1 ;
break;
case V_101 :
if ( F_32 ( V_8 , V_73 , V_46 ) >= 0 ) {
F_9 ( L_3 ) ;
return V_73 ;
}
if ( V_98 )
return V_73 ;
break;
default:
return V_73 ;
}
V_73 += F_41 ( V_95 ) ;
* V_36 = & V_95 -> V_36 ;
V_95 = (struct V_94 * ) ( V_96 + V_73 ) ;
}
return V_73 ;
}
static int F_42 ( struct V_29 * V_30 )
{
if ( V_30 -> V_102 . V_103 ) {
F_43 ( L_4 , V_104 , V_30 -> V_102 . V_103 ) ;
return - V_105 ;
}
if ( V_30 -> V_49 . V_106 != V_107 ) {
F_43 ( L_5 ,
V_104 , V_107 , V_30 -> V_49 . V_106 ) ;
return - V_105 ;
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
struct V_108 * V_109 = (struct V_108 * ) V_8 -> V_3 ;
int V_35 = V_109 -> V_110 . V_36 ;
F_14 ( & V_30 -> V_37 ) ;
if ( ! F_15 ( & V_32 -> V_80 , (struct V_39 * ) V_30 -> V_40 ) &&
! F_16 ( (struct V_39 * ) V_30 -> V_40 ) )
V_35 = - V_41 ;
F_17 ( & V_30 -> V_37 ) ;
return V_35 ;
}
static int F_46 ( struct V_29 * V_30 , struct V_7 * V_8 )
{
struct V_31 * V_32 ;
struct V_108 * V_109 ;
T_2 V_36 ;
F_19 ( V_8 , - F_20 ( V_8 ) ) ;
V_32 = F_13 ( V_8 ) ;
V_36 = * F_21 ( V_8 ) ;
* F_21 ( V_8 ) = V_111 ;
V_109 = (struct V_108 * ) F_22 ( V_8 ) ;
V_109 -> V_110 . V_36 = V_36 ;
V_109 -> V_110 . V_51 = ( V_30 -> V_49 . V_50 >> 3 ) - 1 ;
V_109 -> V_110 . type = V_112 ;
V_109 -> V_110 . V_113 = 1 ;
memset ( & V_109 -> V_114 , 0 , sizeof( V_109 -> V_114 ) ) ;
F_26 ( V_109 -> V_110 . V_51 != 2 ) ;
memcpy ( & V_109 -> V_48 , & V_32 -> V_80 , sizeof( V_109 -> V_48 ) ) ;
F_24 ( & V_30 -> V_37 ) ;
memcpy ( & V_32 -> V_80 , V_30 -> V_40 , sizeof( V_32 -> V_80 ) ) ;
F_25 ( & V_30 -> V_37 ) ;
return 0 ;
}
static int F_47 ( struct V_29 * V_30 , struct V_7 * V_8 ,
T_2 * * V_36 )
{
T_3 V_73 = sizeof( struct V_31 ) ;
struct V_94 * V_95 =
(struct V_94 * ) ( F_13 ( V_8 ) + 1 ) ;
const unsigned char * V_96 = F_33 ( V_8 ) ;
unsigned int V_97 = F_40 ( V_8 ) -
F_33 ( V_8 ) ;
int V_98 = 0 ;
* V_36 = & F_13 ( V_8 ) -> V_36 ;
while ( V_73 + 1 <= V_97 ) {
switch ( * * V_36 ) {
case V_99 :
break;
case V_100 :
if ( V_73 + 3 <= V_97 ) {
struct V_115 * V_116 ;
V_116 = (struct V_115 * ) ( V_96 + V_73 ) ;
if ( V_116 -> type != 0 )
return V_73 ;
}
V_98 = 1 ;
break;
case V_101 :
if ( F_32 ( V_8 , V_73 , V_46 ) >= 0 )
return V_73 ;
if ( V_98 )
return V_73 ;
break;
default:
return V_73 ;
}
V_73 += F_41 ( V_95 ) ;
* V_36 = & V_95 -> V_36 ;
V_95 = (struct V_94 * ) ( V_96 + V_73 ) ;
}
return V_73 ;
}
static int F_48 ( struct V_29 * V_30 )
{
if ( V_30 -> V_102 . V_103 ) {
F_43 ( L_4 , V_104 , V_30 -> V_102 . V_103 ) ;
return - V_105 ;
}
if ( V_30 -> V_49 . V_106 != V_107 ) {
F_43 ( L_5 ,
V_104 , V_107 , V_30 -> V_49 . V_106 ) ;
return - V_105 ;
}
V_30 -> V_49 . V_50 = sizeof( struct V_108 ) ;
return 0 ;
}
static void F_49 ( struct V_29 * V_30 )
{
}
static int T_4 F_50 ( void )
{
F_43 ( L_6 ) ;
if ( F_51 ( & V_117 , V_85 ) < 0 ) {
F_43 ( L_7 , V_104 ) ;
goto V_118;
}
if ( F_51 ( & V_119 , V_85 ) < 0 ) {
F_43 ( L_8 , V_104 ) ;
goto V_120;
}
if ( F_52 ( F_6 ) < 0 ) {
F_43 ( L_9 , V_104 ) ;
goto V_121;
}
return 0 ;
V_121:
F_53 ( & V_119 , V_85 ) ;
V_120:
F_53 ( & V_117 , V_85 ) ;
V_118:
return - V_122 ;
}
static void T_5 F_54 ( void )
{
if ( F_55 ( F_6 ) < 0 )
F_43 ( L_10 , V_104 ) ;
if ( F_53 ( & V_119 , V_85 ) < 0 )
F_43 ( L_11 , V_104 ) ;
if ( F_53 ( & V_117 , V_85 ) < 0 )
F_43 ( L_12 , V_104 ) ;
}
