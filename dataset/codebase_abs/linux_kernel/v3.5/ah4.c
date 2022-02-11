static void * F_1 ( struct V_1 * V_2 , int V_3 ,
unsigned int V_4 )
{
unsigned int V_5 ;
V_5 = V_4 + F_2 ( V_2 ) +
( F_3 ( V_2 ) &
~ ( F_4 () - 1 ) ) ;
V_5 = F_5 ( V_5 , F_4 () ) ;
V_5 += sizeof( struct V_6 ) + F_6 ( V_2 ) ;
V_5 = F_5 ( V_5 , F_7 ( struct V_7 ) ) ;
V_5 += sizeof( struct V_7 ) * V_3 ;
return F_8 ( V_5 , V_8 ) ;
}
static inline T_1 * F_9 ( void * V_9 , unsigned int V_10 )
{
return V_9 + V_10 ;
}
static inline T_1 * F_10 ( struct V_1 * V_2 , void * V_9 ,
unsigned int V_10 )
{
return F_11 ( ( T_1 * ) V_9 + V_10 , F_3 ( V_2 ) + 1 ) ;
}
static inline struct V_6 * F_12 ( struct V_1 * V_2 ,
T_1 * V_11 )
{
struct V_6 * V_12 ;
V_12 = ( void * ) F_11 ( V_11 + F_2 ( V_2 ) ,
F_4 () ) ;
F_13 ( V_12 , V_2 ) ;
return V_12 ;
}
static inline struct V_7 * F_14 ( struct V_1 * V_2 ,
struct V_6 * V_12 )
{
return ( void * ) F_5 ( ( unsigned long ) ( V_12 + 1 ) +
F_6 ( V_2 ) ,
F_7 ( struct V_7 ) ) ;
}
static int F_15 ( const struct V_13 * V_14 , T_2 * V_15 )
{
unsigned char * V_16 = ( unsigned char * ) ( V_14 + 1 ) ;
int V_17 = V_14 -> V_18 * 4 - sizeof( struct V_13 ) ;
int V_19 ;
while ( V_17 > 0 ) {
switch ( * V_16 ) {
case V_20 :
return 0 ;
case V_21 :
V_17 -- ;
V_16 ++ ;
continue;
}
V_19 = V_16 [ 1 ] ;
if ( V_19 < 2 || V_19 > V_17 )
return - V_22 ;
switch ( * V_16 ) {
case V_23 :
case 0x85 :
case V_24 :
case V_25 :
case 0x80 | 21 :
break;
case V_26 :
case V_27 :
if ( V_19 < 6 )
return - V_22 ;
memcpy ( V_15 , V_16 + V_19 - 4 , 4 ) ;
default:
memset ( V_16 , 0 , V_19 ) ;
}
V_17 -= V_19 ;
V_16 += V_19 ;
}
return 0 ;
}
static void F_16 ( struct V_28 * V_29 , int V_30 )
{
T_1 * V_11 ;
struct V_13 * V_14 ;
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_34 * V_35 = F_17 ( V_32 ) -> V_36 ;
struct V_37 * V_38 = V_35 -> V_33 ;
struct V_13 * V_39 = F_18 ( V_32 ) ;
struct V_40 * V_41 = V_40 ( V_32 ) ;
int V_18 = F_19 ( V_32 ) ;
V_14 = F_20 ( V_32 ) -> V_9 ;
V_11 = F_10 ( V_38 -> V_2 , V_14 , V_18 ) ;
memcpy ( V_41 -> V_42 , V_11 , V_38 -> V_43 ) ;
V_39 -> V_44 = V_14 -> V_44 ;
V_39 -> V_45 = V_14 -> V_45 ;
V_39 -> V_46 = V_14 -> V_46 ;
if ( V_39 -> V_18 != 5 ) {
V_39 -> V_15 = V_14 -> V_15 ;
memcpy ( V_39 + 1 , V_14 + 1 , V_39 -> V_18 * 4 - sizeof( struct V_13 ) ) ;
}
F_21 ( F_20 ( V_32 ) -> V_9 ) ;
F_22 ( V_32 , V_30 ) ;
}
static int F_23 ( struct V_34 * V_35 , struct V_31 * V_32 )
{
int V_30 ;
int V_3 ;
int V_18 ;
T_1 * V_11 ;
struct V_31 * V_47 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_48 ;
struct V_13 * V_14 , * V_39 ;
struct V_40 * V_41 ;
struct V_37 * V_38 ;
V_38 = V_35 -> V_33 ;
V_2 = V_38 -> V_2 ;
if ( ( V_30 = F_24 ( V_32 , 0 , & V_47 ) ) < 0 )
goto V_49;
V_3 = V_30 ;
F_25 ( V_32 , - F_26 ( V_32 ) ) ;
V_41 = V_40 ( V_32 ) ;
V_18 = F_19 ( V_32 ) ;
V_30 = - V_50 ;
V_14 = F_1 ( V_2 , V_3 , V_18 ) ;
if ( ! V_14 )
goto V_49;
V_11 = F_10 ( V_2 , V_14 , V_18 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_48 = F_14 ( V_2 , V_12 ) ;
memset ( V_41 -> V_42 , 0 , V_38 -> V_43 ) ;
V_39 = F_18 ( V_32 ) ;
V_14 -> V_44 = V_39 -> V_44 ;
V_14 -> V_45 = V_39 -> V_45 ;
V_14 -> V_46 = V_39 -> V_46 ;
if ( V_39 -> V_18 != 5 ) {
V_14 -> V_15 = V_39 -> V_15 ;
memcpy ( V_14 + 1 , V_39 + 1 , V_39 -> V_18 * 4 - sizeof( struct V_13 ) ) ;
V_30 = F_15 ( V_39 , & V_39 -> V_15 ) ;
if ( V_30 )
goto V_51;
}
V_41 -> V_52 = * F_27 ( V_32 ) ;
* F_27 ( V_32 ) = V_53 ;
V_39 -> V_44 = 0 ;
V_39 -> V_54 = F_28 ( V_32 -> V_5 ) ;
V_39 -> V_46 = 0 ;
V_39 -> V_45 = 0 ;
V_39 -> V_55 = 0 ;
if ( V_35 -> V_56 . V_57 & V_58 )
V_41 -> V_59 = ( F_29 ( sizeof( * V_41 ) + V_38 -> V_43 ) >> 2 ) - 2 ;
else
V_41 -> V_59 = ( F_30 ( sizeof( * V_41 ) + V_38 -> V_43 ) >> 2 ) - 2 ;
V_41 -> V_60 = 0 ;
V_41 -> V_61 = V_35 -> V_62 . V_61 ;
V_41 -> V_63 = F_31 ( F_32 ( V_32 ) -> V_64 . V_65 . V_66 ) ;
F_33 ( V_48 , V_3 ) ;
F_34 ( V_32 , V_48 , 0 , V_32 -> V_5 ) ;
F_35 ( V_12 , V_48 , V_11 , V_32 -> V_5 ) ;
F_36 ( V_12 , 0 , F_16 , V_32 ) ;
F_20 ( V_32 ) -> V_9 = V_14 ;
V_30 = F_37 ( V_12 ) ;
if ( V_30 ) {
if ( V_30 == - V_67 )
goto V_49;
if ( V_30 == - V_68 )
V_30 = V_69 ;
goto V_51;
}
memcpy ( V_41 -> V_42 , V_11 , V_38 -> V_43 ) ;
V_39 -> V_44 = V_14 -> V_44 ;
V_39 -> V_45 = V_14 -> V_45 ;
V_39 -> V_46 = V_14 -> V_46 ;
if ( V_39 -> V_18 != 5 ) {
V_39 -> V_15 = V_14 -> V_15 ;
memcpy ( V_39 + 1 , V_14 + 1 , V_39 -> V_18 * 4 - sizeof( struct V_13 ) ) ;
}
V_51:
F_21 ( V_14 ) ;
V_49:
return V_30 ;
}
static void F_38 ( struct V_28 * V_29 , int V_30 )
{
T_1 * V_42 ;
T_1 * V_11 ;
struct V_13 * V_70 ;
struct V_31 * V_32 = V_29 -> V_33 ;
struct V_34 * V_35 = F_39 ( V_32 ) ;
struct V_37 * V_38 = V_35 -> V_33 ;
struct V_40 * V_41 = V_40 ( V_32 ) ;
int V_18 = F_19 ( V_32 ) ;
int V_71 = ( V_41 -> V_59 + 2 ) << 2 ;
V_70 = F_20 ( V_32 ) -> V_9 ;
V_42 = F_9 ( V_70 , V_18 ) ;
V_11 = F_10 ( V_38 -> V_2 , V_42 , V_38 -> V_43 ) ;
V_30 = memcmp ( V_11 , V_42 , V_38 -> V_43 ) ? - V_72 : 0 ;
if ( V_30 )
goto V_49;
V_30 = V_41 -> V_52 ;
V_32 -> V_73 += V_71 ;
memcpy ( F_40 ( V_32 ) , V_70 , V_18 ) ;
F_41 ( V_32 , V_71 + V_18 ) ;
F_42 ( V_32 , - V_18 ) ;
V_49:
F_21 ( F_20 ( V_32 ) -> V_9 ) ;
F_43 ( V_32 , V_30 ) ;
}
static int F_44 ( struct V_34 * V_35 , struct V_31 * V_32 )
{
int V_71 ;
int V_18 ;
int V_52 ;
int V_3 ;
T_1 * V_42 ;
T_1 * V_11 ;
struct V_31 * V_47 ;
struct V_1 * V_2 ;
struct V_6 * V_12 ;
struct V_7 * V_48 ;
struct V_13 * V_14 , * V_70 ;
struct V_40 * V_41 ;
struct V_37 * V_38 ;
int V_30 = - V_50 ;
if ( ! F_45 ( V_32 , sizeof( * V_41 ) ) )
goto V_49;
V_41 = (struct V_40 * ) V_32 -> V_33 ;
V_38 = V_35 -> V_33 ;
V_2 = V_38 -> V_2 ;
V_52 = V_41 -> V_52 ;
V_71 = ( V_41 -> V_59 + 2 ) << 2 ;
if ( V_35 -> V_56 . V_57 & V_58 ) {
if ( V_71 != F_29 ( sizeof( * V_41 ) + V_38 -> V_74 ) &&
V_71 != F_29 ( sizeof( * V_41 ) + V_38 -> V_43 ) )
goto V_49;
} else {
if ( V_71 != F_30 ( sizeof( * V_41 ) + V_38 -> V_74 ) &&
V_71 != F_30 ( sizeof( * V_41 ) + V_38 -> V_43 ) )
goto V_49;
}
if ( ! F_45 ( V_32 , V_71 ) )
goto V_49;
if ( F_46 ( V_32 ) &&
F_47 ( V_32 , 0 , 0 , V_8 ) )
goto V_49;
V_32 -> V_75 = V_76 ;
if ( ( V_30 = F_24 ( V_32 , 0 , & V_47 ) ) < 0 )
goto V_49;
V_3 = V_30 ;
V_41 = (struct V_40 * ) V_32 -> V_33 ;
V_14 = F_18 ( V_32 ) ;
V_18 = F_19 ( V_32 ) ;
V_70 = F_1 ( V_2 , V_3 , V_18 + V_38 -> V_43 ) ;
if ( ! V_70 )
goto V_49;
V_42 = F_9 ( V_70 , V_18 ) ;
V_11 = F_10 ( V_2 , V_42 , V_38 -> V_43 ) ;
V_12 = F_12 ( V_2 , V_11 ) ;
V_48 = F_14 ( V_2 , V_12 ) ;
memcpy ( V_70 , V_14 , V_18 ) ;
memcpy ( V_42 , V_41 -> V_42 , V_38 -> V_43 ) ;
memset ( V_41 -> V_42 , 0 , V_38 -> V_43 ) ;
V_14 -> V_45 = 0 ;
V_14 -> V_44 = 0 ;
V_14 -> V_46 = 0 ;
V_14 -> V_55 = 0 ;
if ( V_18 > sizeof( * V_14 ) ) {
T_2 V_77 ;
V_30 = F_15 ( V_14 , & V_77 ) ;
if ( V_30 )
goto V_51;
}
F_25 ( V_32 , V_18 ) ;
F_33 ( V_48 , V_3 ) ;
F_34 ( V_32 , V_48 , 0 , V_32 -> V_5 ) ;
F_35 ( V_12 , V_48 , V_11 , V_32 -> V_5 ) ;
F_36 ( V_12 , 0 , F_38 , V_32 ) ;
F_20 ( V_32 ) -> V_9 = V_70 ;
V_30 = F_37 ( V_12 ) ;
if ( V_30 ) {
if ( V_30 == - V_67 )
goto V_49;
goto V_51;
}
V_30 = memcmp ( V_11 , V_42 , V_38 -> V_43 ) ? - V_72 : 0 ;
if ( V_30 )
goto V_51;
V_32 -> V_73 += V_71 ;
memcpy ( F_40 ( V_32 ) , V_70 , V_18 ) ;
F_41 ( V_32 , V_71 + V_18 ) ;
F_42 ( V_32 , - V_18 ) ;
V_30 = V_52 ;
V_51:
F_21 ( V_70 ) ;
V_49:
return V_30 ;
}
static void F_48 ( struct V_31 * V_32 , T_3 V_78 )
{
struct V_79 * V_79 = F_49 ( V_32 -> V_80 ) ;
const struct V_13 * V_14 = ( const struct V_13 * ) V_32 -> V_33 ;
struct V_40 * V_41 = (struct V_40 * ) ( V_32 -> V_33 + ( V_14 -> V_18 << 2 ) ) ;
struct V_34 * V_35 ;
if ( F_50 ( V_32 ) -> type != V_81 ||
F_50 ( V_32 ) -> V_82 != V_83 )
return;
V_35 = F_51 ( V_79 , V_32 -> V_84 , ( const V_85 * ) & V_14 -> V_15 ,
V_41 -> V_61 , V_53 , V_86 ) ;
if ( ! V_35 )
return;
F_52 ( L_1 ,
F_53 ( V_41 -> V_61 ) , F_53 ( V_14 -> V_15 ) ) ;
F_54 ( V_35 ) ;
}
static int F_55 ( struct V_34 * V_35 )
{
struct V_37 * V_38 = NULL ;
struct V_87 * V_88 ;
struct V_1 * V_2 ;
if ( ! V_35 -> V_89 )
goto error;
if ( V_35 -> V_90 )
goto error;
V_38 = F_56 ( sizeof( * V_38 ) , V_91 ) ;
if ( ! V_38 )
return - V_50 ;
V_2 = F_57 ( V_35 -> V_89 -> V_92 , 0 , 0 ) ;
if ( F_58 ( V_2 ) )
goto error;
V_38 -> V_2 = V_2 ;
if ( F_59 ( V_2 , V_35 -> V_89 -> V_93 ,
( V_35 -> V_89 -> V_94 + 7 ) / 8 ) )
goto error;
V_88 = F_60 ( V_35 -> V_89 -> V_92 , 0 ) ;
F_61 ( ! V_88 ) ;
if ( V_88 -> V_95 . V_96 . V_97 / 8 !=
F_2 ( V_2 ) ) {
F_62 ( L_2 ,
V_98 , V_35 -> V_89 -> V_92 ,
F_2 ( V_2 ) ,
V_88 -> V_95 . V_96 . V_97 / 8 ) ;
goto error;
}
V_38 -> V_74 = V_88 -> V_95 . V_96 . V_97 / 8 ;
V_38 -> V_43 = V_35 -> V_89 -> V_99 / 8 ;
F_61 ( V_38 -> V_43 > V_100 ) ;
if ( V_35 -> V_56 . V_57 & V_58 )
V_35 -> V_56 . V_101 = F_29 ( sizeof( struct V_40 ) +
V_38 -> V_43 ) ;
else
V_35 -> V_56 . V_101 = F_30 ( sizeof( struct V_40 ) +
V_38 -> V_43 ) ;
if ( V_35 -> V_56 . V_102 == V_103 )
V_35 -> V_56 . V_101 += sizeof( struct V_13 ) ;
V_35 -> V_33 = V_38 ;
return 0 ;
error:
if ( V_38 ) {
F_63 ( V_38 -> V_2 ) ;
F_21 ( V_38 ) ;
}
return - V_22 ;
}
static void F_64 ( struct V_34 * V_35 )
{
struct V_37 * V_38 = V_35 -> V_33 ;
if ( ! V_38 )
return;
F_63 ( V_38 -> V_2 ) ;
F_21 ( V_38 ) ;
}
static int T_4 F_65 ( void )
{
if ( F_66 ( & V_104 , V_86 ) < 0 ) {
F_62 ( L_3 , V_98 ) ;
return - V_105 ;
}
if ( F_67 ( & V_106 , V_53 ) < 0 ) {
F_62 ( L_4 , V_98 ) ;
F_68 ( & V_104 , V_86 ) ;
return - V_105 ;
}
return 0 ;
}
static void T_5 F_69 ( void )
{
if ( F_70 ( & V_106 , V_53 ) < 0 )
F_62 ( L_5 , V_98 ) ;
if ( F_68 ( & V_104 , V_86 ) < 0 )
F_62 ( L_6 , V_98 ) ;
}
