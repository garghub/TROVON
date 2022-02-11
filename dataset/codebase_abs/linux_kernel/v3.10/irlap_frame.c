static inline void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = (struct V_5 * ) V_4 -> V_6 ;
V_6 -> V_7 = V_8 ;
V_6 -> V_9 = V_2 -> V_10 ;
V_6 -> V_11 = V_2 -> V_12 ;
V_2 -> V_10 = 0 ;
V_6 -> V_13 = V_2 -> V_14 ;
V_6 -> V_15 = V_2 -> V_16 ;
V_6 -> V_17 = V_2 -> V_17 ;
V_2 -> V_17 = 0 ;
V_2 -> V_14 = V_2 -> V_16 ;
}
void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
V_4 -> V_18 = V_2 -> V_19 ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
F_5 ( V_4 ) ;
V_4 -> V_20 = F_6 ( V_21 ) ;
V_4 -> V_22 = V_23 ;
F_1 ( V_2 , V_4 ) ;
if ( F_7 ( V_2 -> V_24 & V_25 ) ) {
F_8 ( 3 , L_1 , V_26 ,
V_2 -> V_19 -> V_27 ) ;
F_9 ( V_4 ) ;
return;
}
F_10 ( V_4 ) ;
}
void F_11 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_30 ;
struct V_31 * V_32 ;
int V_33 ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
V_30 = F_13 ( sizeof( struct V_31 ) +
V_34 ,
V_35 ) ;
if ( ! V_30 )
return;
V_32 = (struct V_31 * ) F_14 ( V_30 , 2 ) ;
if ( V_29 )
V_32 -> V_36 = V_37 | V_38 ;
else
V_32 -> V_36 = V_37 | V_2 -> V_36 ;
V_32 -> V_39 = V_40 | V_41 ;
if ( V_29 ) {
F_14 ( V_30 , 9 ) ;
V_32 -> V_42 = F_15 ( V_2 -> V_42 ) ;
V_32 -> V_43 = F_15 ( V_2 -> V_43 ) ;
V_32 -> V_44 = V_2 -> V_36 ;
V_33 = F_16 ( V_2 , V_30 ) ;
if ( V_33 < 0 ) {
F_9 ( V_30 ) ;
return;
}
}
F_2 ( V_2 , V_30 ) ;
}
static void F_17 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 )
{
struct V_31 * V_32 ;
if ( F_18 ( V_4 , sizeof( struct V_31 ) ) ) {
V_32 = (struct V_31 * ) V_4 -> V_47 ;
V_46 -> V_36 = V_32 -> V_44 & 0xFE ;
if ( ( V_46 -> V_36 == 0x00 ) || ( V_46 -> V_36 == 0xfe ) ) {
F_8 ( 3 , L_2 ,
V_26 ) ;
return;
}
V_46 -> V_43 = F_19 ( V_32 -> V_42 ) ;
V_46 -> V_42 = F_19 ( V_32 -> V_43 ) ;
if ( V_46 -> V_42 != V_2 -> V_42 ) {
F_8 ( 2 , L_3 ,
V_26 ) ;
return;
}
F_20 ( V_2 , V_48 , V_4 , V_46 ) ;
} else {
F_20 ( V_2 , V_48 , V_4 , NULL ) ;
}
}
void F_21 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
struct V_3 * V_30 ;
struct V_49 * V_32 ;
int V_33 ;
F_8 ( 2 , L_4 , V_26 , V_50 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
V_30 = F_13 ( sizeof( struct V_49 ) +
V_34 ,
V_35 ) ;
if ( ! V_30 )
return;
V_32 = (struct V_49 * ) F_14 ( V_30 , 10 ) ;
V_32 -> V_36 = V_2 -> V_36 ;
V_32 -> V_39 = V_51 | V_41 ;
V_32 -> V_42 = F_15 ( V_2 -> V_42 ) ;
V_32 -> V_43 = F_15 ( V_2 -> V_43 ) ;
if ( V_29 ) {
V_33 = F_16 ( V_2 , V_30 ) ;
if ( V_33 < 0 ) {
F_9 ( V_30 ) ;
return;
}
}
F_2 ( V_2 , V_30 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_3 * V_30 = NULL ;
struct V_52 * V_32 ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
V_30 = F_13 ( sizeof( struct V_52 ) , V_35 ) ;
if ( ! V_30 )
return;
V_32 = (struct V_52 * ) F_14 ( V_30 , 2 ) ;
if ( V_2 -> V_53 == V_54 )
V_32 -> V_36 = V_38 ;
else
V_32 -> V_36 = V_2 -> V_36 ;
V_32 -> V_39 = V_55 | V_41 ;
F_2 ( V_2 , V_30 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
struct V_3 * V_30 = NULL ;
struct V_56 * V_32 ;
F_8 ( 3 , L_5 , V_26 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
V_30 = F_13 ( sizeof( struct V_56 ) , V_35 ) ;
if ( ! V_30 )
return;
V_32 = (struct V_56 * ) F_14 ( V_30 , 2 ) ;
V_32 -> V_36 = V_2 -> V_36 | V_37 ;
V_32 -> V_39 = V_57 | V_41 ;
F_2 ( V_2 , V_30 ) ;
}
void F_24 ( struct V_1 * V_2 , int V_58 , T_1 V_59 ,
T_1 V_60 , T_2 * V_61 )
{
struct V_3 * V_30 = NULL ;
struct V_62 * V_32 ;
T_3 V_63 = V_64 ;
T_1 * V_46 ;
F_8 ( 4 , L_6 , V_26 ,
V_59 , V_58 , V_60 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
F_12 (discovery != NULL, return;) ;
V_30 = F_13 ( sizeof( struct V_62 ) + V_65 ,
V_35 ) ;
if ( ! V_30 )
return;
F_14 ( V_30 , 14 ) ;
V_32 = (struct V_62 * ) V_30 -> V_47 ;
if ( V_60 ) {
V_32 -> V_36 = V_38 | V_37 ;
V_32 -> V_39 = V_66 | V_41 ;
} else {
V_32 -> V_36 = V_38 ;
V_32 -> V_39 = V_67 | V_41 ;
}
V_32 -> V_68 = V_69 ;
V_32 -> V_42 = F_15 ( V_2 -> V_42 ) ;
if ( V_60 )
V_32 -> V_43 = F_15 ( V_63 ) ;
else
V_32 -> V_43 = F_15 ( V_61 -> V_47 . V_43 ) ;
switch ( V_58 ) {
case 1 :
V_32 -> V_70 = 0x00 ;
break;
case 6 :
V_32 -> V_70 = 0x01 ;
break;
case 8 :
V_32 -> V_70 = 0x02 ;
break;
case 16 :
V_32 -> V_70 = 0x03 ;
break;
default:
V_32 -> V_70 = 0x02 ;
break;
}
V_32 -> V_71 = V_59 ;
V_32 -> V_72 = 0x00 ;
if ( ! V_60 || ( V_32 -> V_71 == 0xff ) ) {
int V_73 ;
if ( V_61 -> V_47 . V_74 [ 0 ] & V_75 ) {
V_46 = F_14 ( V_30 , 2 ) ;
V_46 [ 0 ] = V_61 -> V_47 . V_74 [ 0 ] ;
V_46 [ 1 ] = V_61 -> V_47 . V_74 [ 1 ] ;
} else {
V_46 = F_14 ( V_30 , 1 ) ;
V_46 [ 0 ] = V_61 -> V_47 . V_74 [ 0 ] ;
}
V_46 = F_14 ( V_30 , 1 ) ;
V_46 [ 0 ] = V_61 -> V_47 . V_76 ;
V_73 = F_25 ( V_61 -> V_77 , F_26 ( V_30 ) ) ;
V_46 = F_14 ( V_30 , V_73 ) ;
memcpy ( V_46 , V_61 -> V_47 . V_46 , V_73 ) ;
}
F_2 ( V_2 , V_30 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_45 * V_46 )
{
struct V_62 * V_78 ;
T_2 * V_61 = NULL ;
T_1 * V_79 ;
char * V_80 ;
F_8 ( 4 , L_5 , V_26 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
if ( ! F_18 ( V_4 , sizeof( struct V_62 ) ) ) {
F_28 ( L_7 , V_26 ) ;
return;
}
V_78 = (struct V_62 * ) V_4 -> V_47 ;
V_46 -> V_43 = F_19 ( V_78 -> V_42 ) ;
V_46 -> V_42 = F_19 ( V_78 -> V_43 ) ;
if ( ( V_46 -> V_42 != V_2 -> V_42 ) && ( V_46 -> V_42 != V_64 ) ) {
F_8 ( 0 , L_8 ,
V_26 ) ;
return;
}
if ( ( V_61 = F_29 ( sizeof( T_2 ) , V_35 ) ) == NULL ) {
F_30 ( L_9 , V_26 ) ;
return;
}
V_61 -> V_47 . V_43 = V_46 -> V_43 ;
V_61 -> V_47 . V_42 = V_2 -> V_42 ;
V_61 -> V_81 = V_50 ;
F_8 ( 4 , L_10 , V_26 ,
V_61 -> V_47 . V_43 ) ;
V_79 = F_31 ( V_4 , sizeof( struct V_62 ) ) ;
V_61 -> V_47 . V_74 [ 0 ] = V_79 [ 0 ] ;
if ( V_79 [ 0 ] & V_75 ) {
F_8 ( 4 , L_11 ) ;
V_61 -> V_47 . V_74 [ 1 ] = V_79 [ 1 ] ;
V_61 -> V_47 . V_76 = V_79 [ 2 ] ;
V_80 = ( char * ) & V_79 [ 3 ] ;
} else {
V_61 -> V_47 . V_74 [ 1 ] = 0 ;
V_61 -> V_47 . V_76 = V_79 [ 1 ] ;
V_80 = ( char * ) & V_79 [ 2 ] ;
}
V_4 -> V_47 [ V_4 -> V_73 ] = '\0' ;
strncpy ( V_61 -> V_47 . V_46 , V_80 , V_82 ) ;
V_61 -> V_77 = strlen ( V_61 -> V_47 . V_46 ) ;
V_46 -> V_61 = V_61 ;
F_20 ( V_2 , V_83 , V_4 , V_46 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_45 * V_46 )
{
struct V_62 * V_78 ;
T_2 * V_61 = NULL ;
T_1 * V_79 ;
char * V_80 ;
if ( ! F_18 ( V_4 , sizeof( struct V_62 ) ) ) {
F_28 ( L_7 , V_26 ) ;
return;
}
V_78 = (struct V_62 * ) V_4 -> V_47 ;
V_46 -> V_43 = F_19 ( V_78 -> V_42 ) ;
V_46 -> V_42 = F_19 ( V_78 -> V_43 ) ;
if ( ( V_46 -> V_42 != V_2 -> V_42 ) && ( V_46 -> V_42 != V_64 ) ) {
F_8 ( 0 , L_8 ,
V_26 ) ;
return;
}
switch ( V_78 -> V_70 & 0x03 ) {
case 0x00 :
V_46 -> V_58 = 1 ;
break;
case 0x01 :
V_46 -> V_58 = 6 ;
break;
case 0x02 :
V_46 -> V_58 = 8 ;
break;
case 0x03 :
V_46 -> V_58 = 16 ;
break;
default:
return;
}
V_46 -> V_59 = V_78 -> V_71 ;
V_79 = F_31 ( V_4 , sizeof( struct V_62 ) ) ;
if ( V_46 -> V_59 == 0xff ) {
if( ( V_79 == NULL ) ||
! F_18 ( V_4 , 3 ) ) {
F_28 ( L_12 ,
V_26 ) ;
return;
}
V_61 = F_29 ( sizeof( T_2 ) , V_35 ) ;
if ( ! V_61 ) {
F_30 ( L_13 , V_26 ) ;
return;
}
V_61 -> V_47 . V_43 = V_46 -> V_43 ;
V_61 -> V_47 . V_42 = V_2 -> V_42 ;
V_61 -> V_81 = V_50 ;
V_61 -> V_47 . V_74 [ 0 ] = V_79 [ 0 ] ;
if ( V_79 [ 0 ] & V_75 ) {
V_61 -> V_47 . V_74 [ 1 ] = V_79 [ 1 ] ;
V_61 -> V_47 . V_76 = V_79 [ 2 ] ;
V_80 = ( char * ) & V_79 [ 3 ] ;
} else {
V_61 -> V_47 . V_74 [ 1 ] = 0 ;
V_61 -> V_47 . V_76 = V_79 [ 1 ] ;
V_80 = ( char * ) & V_79 [ 2 ] ;
}
V_4 -> V_47 [ V_4 -> V_73 ] = '\0' ;
strncpy ( V_61 -> V_47 . V_46 , V_80 , V_82 ) ;
V_61 -> V_77 = strlen ( V_61 -> V_47 . V_46 ) ;
V_46 -> V_61 = V_61 ;
} else
V_46 -> V_61 = NULL ;
F_20 ( V_2 , V_84 , V_4 , V_46 ) ;
}
void F_33 ( struct V_1 * V_2 , int V_60 )
{
struct V_3 * V_30 ;
struct V_85 * V_32 ;
V_30 = F_13 ( sizeof( struct V_85 ) , V_35 ) ;
if ( ! V_30 )
return;
V_32 = (struct V_85 * ) F_14 ( V_30 , 2 ) ;
V_32 -> V_36 = V_2 -> V_36 ;
V_32 -> V_36 |= ( V_60 ) ? V_37 : 0 ;
V_32 -> V_39 = V_86 | V_41 | ( V_2 -> V_87 << 5 ) ;
F_2 ( V_2 , V_30 ) ;
}
void F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_30 ;
struct V_88 * V_32 ;
V_30 = F_13 ( sizeof( struct V_88 ) , V_35 ) ;
if ( ! V_30 )
return;
V_32 = (struct V_88 * ) F_14 ( V_30 , 2 ) ;
V_32 -> V_36 = V_2 -> V_36 ;
V_32 -> V_36 = V_89 | V_41 ;
F_2 ( V_2 , V_30 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
V_46 -> V_90 = V_4 -> V_47 [ 1 ] >> 5 ;
if ( V_60 )
F_20 ( V_2 , V_91 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_92 , V_4 , V_46 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
V_46 -> V_90 = V_4 -> V_47 [ 1 ] >> 5 ;
F_8 ( 4 , L_14 , V_26 , V_46 -> V_90 , V_50 ) ;
if ( V_60 )
F_20 ( V_2 , V_93 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_94 , V_4 , V_46 ) ;
}
static void F_37 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
F_8 ( 0 , L_5 , V_26 ) ;
V_46 -> V_90 = V_4 -> V_47 [ 1 ] >> 5 ;
if ( V_60 )
F_20 ( V_2 , V_95 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_96 , V_4 , V_46 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
F_8 ( 0 , L_5 , V_26 ) ;
V_46 -> V_90 = V_4 -> V_47 [ 1 ] >> 5 ;
if ( V_60 )
F_20 ( V_2 , V_97 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_98 , V_4 , V_46 ) ;
}
static void F_39 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
F_8 ( 2 , L_5 , V_26 ) ;
if ( V_60 )
F_20 ( V_2 , V_99 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_100 , V_4 , V_46 ) ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_45 * V_46 )
{
F_20 ( V_2 , V_101 , V_4 , V_46 ) ;
}
void F_41 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_30 ;
if ( V_4 -> V_47 [ 1 ] == V_102 ) {
V_4 -> V_47 [ 1 ] = V_102 | ( V_2 -> V_103 << 1 ) ;
F_42 ( V_4 ) ;
F_43 ( & V_2 -> V_104 , V_4 ) ;
V_30 = F_44 ( V_4 , V_35 ) ;
if ( V_30 == NULL ) {
return;
}
V_2 -> V_103 = ( V_2 -> V_103 + 1 ) % 8 ;
V_2 -> V_105 = FALSE ;
V_2 -> V_106 -= 1 ;
F_45 ( V_2 , V_30 , V_37 ) ;
} else {
F_8 ( 4 , L_15 , V_26 ) ;
F_46 ( V_2 , F_42 ( V_4 ) , V_2 -> V_36 , V_37 ) ;
V_2 -> V_106 -= 1 ;
}
}
void F_47 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_30 ;
int V_107 ;
F_48 ( & V_2 -> V_108 ) ;
if ( V_4 -> V_47 [ 1 ] == V_102 ) {
V_4 -> V_47 [ 1 ] = V_102 | ( V_2 -> V_103 << 1 ) ;
F_42 ( V_4 ) ;
F_43 ( & V_2 -> V_104 , V_4 ) ;
V_30 = F_44 ( V_4 , V_35 ) ;
if ( V_30 == NULL ) {
return;
}
V_30 -> V_47 [ 1 ] |= V_41 ;
V_2 -> V_103 = ( V_2 -> V_103 + 1 ) % 8 ;
V_2 -> V_105 = FALSE ;
F_49 ( V_2 , V_109 ) ;
F_45 ( V_2 , V_30 , V_37 ) ;
} else {
F_8 ( 4 , L_15 , V_26 ) ;
if ( V_2 -> V_105 ) {
F_46 ( V_2 , F_42 ( V_4 ) , V_2 -> V_36 , V_37 ) ;
F_49 ( V_2 , V_109 ) ;
F_33 ( V_2 , V_37 ) ;
V_2 -> V_105 = FALSE ;
} else {
V_4 -> V_47 [ 1 ] |= V_41 ;
F_49 ( V_2 , V_109 ) ;
F_46 ( V_2 , F_42 ( V_4 ) , V_2 -> V_36 , V_37 ) ;
}
}
V_107 = V_2 -> V_110 ;
V_2 -> V_106 = V_2 -> V_111 ;
#ifdef F_50
V_107 -= ( V_2 -> V_110 * V_2 -> V_112
/ V_2 -> V_113 ) ;
F_8 ( 4 , L_16 , V_26 , V_2 -> V_110 , V_2 -> V_112 , V_2 -> V_113 , V_107 ) ;
V_2 -> V_112 = V_2 -> V_113 ;
#endif
F_51 ( V_2 , V_2 -> V_110 + V_107 ) ;
}
void F_52 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_3 * V_30 = NULL ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
F_12 (skb != NULL, return;) ;
if ( V_4 -> V_47 [ 1 ] == V_102 ) {
V_4 -> V_47 [ 1 ] = V_102 | ( V_2 -> V_103 << 1 ) ;
F_42 ( V_4 ) ;
F_43 ( & V_2 -> V_104 , V_4 ) ;
V_30 = F_44 ( V_4 , V_35 ) ;
if ( V_30 == NULL ) {
return;
}
V_30 -> V_47 [ 1 ] |= V_41 ;
V_2 -> V_103 = ( V_2 -> V_103 + 1 ) % 8 ;
V_2 -> V_105 = FALSE ;
F_45 ( V_2 , V_30 , V_114 ) ;
} else {
if ( V_2 -> V_105 ) {
F_46 ( V_2 , F_42 ( V_4 ) , V_2 -> V_36 , V_114 ) ;
F_33 ( V_2 , V_114 ) ;
V_2 -> V_105 = FALSE ;
} else {
V_4 -> V_47 [ 1 ] |= V_41 ;
F_46 ( V_2 , F_42 ( V_4 ) , V_2 -> V_36 , V_114 ) ;
}
}
V_2 -> V_106 = V_2 -> V_111 ;
#ifdef F_50
V_2 -> V_112 = V_2 -> V_113 ;
#endif
F_53 ( V_2 , V_2 -> V_115 ) ;
}
void F_54 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_3 * V_30 = NULL ;
if ( V_4 -> V_47 [ 1 ] == V_102 ) {
V_4 -> V_47 [ 1 ] = V_102 | ( V_2 -> V_103 << 1 ) ;
F_42 ( V_4 ) ;
F_43 ( & V_2 -> V_104 , V_4 ) ;
V_30 = F_44 ( V_4 , V_35 ) ;
if ( V_30 == NULL ) {
return;
}
V_2 -> V_103 = ( V_2 -> V_103 + 1 ) % 8 ;
V_2 -> V_105 = FALSE ;
V_2 -> V_106 -= 1 ;
F_45 ( V_2 , V_30 , V_114 ) ;
} else {
F_46 ( V_2 , F_42 ( V_4 ) , V_2 -> V_36 , V_114 ) ;
V_2 -> V_106 -= 1 ;
}
}
void F_55 ( struct V_1 * V_2 , int V_60 )
{
struct V_3 * V_30 ;
struct V_3 * V_4 ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
F_56 (&self->wx_list, skb) {
F_57 ( V_2 , & V_2 -> V_116 ) ;
V_30 = F_58 ( V_4 , V_35 ) ;
if ( ! V_30 ) {
F_8 ( 0 , L_17 , V_26 ) ;
return;
}
V_30 -> V_47 [ 1 ] &= 0x0f ;
if ( F_59 ( & V_2 -> V_104 , V_4 ) )
V_30 -> V_47 [ 1 ] |= V_41 ;
else
V_30 -> V_47 [ 1 ] &= ~ V_41 ;
F_45 ( V_2 , V_30 , V_60 ) ;
}
#if 0
while (!skb_queue_empty(&self->txq)) {
IRDA_DEBUG(0, "%s(), sending additional frames!\n", __func__);
if (self->window > 0) {
skb = skb_dequeue( &self->txq);
IRDA_ASSERT(skb != NULL, return;);
if ((self->window > 1) &&
!skb_queue_empty(&self->txq)) {
irlap_send_data_primary(self, skb);
} else {
irlap_send_data_primary_poll(self, skb);
}
kfree_skb(skb);
}
}
#endif
}
void F_60 ( struct V_1 * V_2 , int V_60 )
{
struct V_3 * V_30 ;
struct V_3 * V_4 ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
V_4 = F_61 ( & V_2 -> V_104 ) ;
if ( V_4 != NULL ) {
F_57 ( V_2 , & V_2 -> V_116 ) ;
V_30 = F_58 ( V_4 , V_35 ) ;
if ( ! V_30 ) {
F_8 ( 0 , L_17 , V_26 ) ;
return;
}
V_30 -> V_47 [ 1 ] &= 0x0f ;
V_30 -> V_47 [ 1 ] |= V_41 ;
F_45 ( V_2 , V_30 , V_60 ) ;
}
}
void F_46 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_36 , int V_60 )
{
F_8 ( 4 , L_5 , V_26 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
F_12 (skb != NULL, return;) ;
V_4 -> V_47 [ 0 ] = V_36 | ( ( V_60 ) ? V_37 : 0 ) ;
F_2 ( V_2 , V_4 ) ;
}
static void F_45 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_60 )
{
V_4 -> V_47 [ 0 ] = V_2 -> V_36 ;
V_4 -> V_47 [ 0 ] |= ( V_60 ) ? V_37 : 0 ;
V_4 -> V_47 [ 1 ] |= ( V_2 -> V_87 << 5 ) ;
F_2 ( V_2 , V_4 ) ;
}
static inline void F_62 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
V_46 -> V_90 = V_4 -> V_47 [ 1 ] >> 5 ;
V_46 -> V_117 = V_4 -> V_47 [ 1 ] & V_41 ;
V_46 -> V_118 = ( V_4 -> V_47 [ 1 ] >> 1 ) & 0x07 ;
if ( V_60 )
F_20 ( V_2 , V_119 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_120 , V_4 , V_46 ) ;
}
static void F_63 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 )
{
F_8 ( 4 , L_5 , V_26 ) ;
V_46 -> V_117 = V_4 -> V_47 [ 1 ] & V_41 ;
F_20 ( V_2 , V_121 , V_4 , V_46 ) ;
}
static void F_64 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 )
{
T_1 * V_32 ;
int V_122 , V_123 , V_124 , V_125 ;
F_8 ( 0 , L_5 , V_26 ) ;
F_12 (self != NULL, return;) ;
F_12 (self->magic == LAP_MAGIC, return;) ;
F_12 (skb != NULL, return;) ;
F_12 (info != NULL, return;) ;
if ( ! F_18 ( V_4 , 4 ) ) {
F_28 ( L_7 , V_26 ) ;
return;
}
V_32 = V_4 -> V_47 ;
V_46 -> V_90 = V_32 [ 2 ] >> 5 ;
V_46 -> V_117 = V_32 [ 2 ] & V_41 ;
V_46 -> V_118 = ( V_32 [ 2 ] >> 1 ) & 0x07 ;
V_122 = V_32 [ 3 ] & 0x01 ;
V_123 = V_32 [ 3 ] & 0x02 ;
V_124 = V_32 [ 3 ] & 0x04 ;
V_125 = V_32 [ 3 ] & 0x08 ;
if ( V_122 ) {
F_8 ( 0 , L_18
L_19 ) ;
}
if ( V_123 ) {
F_8 ( 0 , L_20
L_21 ) ;
}
if ( V_124 ) {
F_8 ( 0 , L_22
L_23
L_24 ) ;
}
if ( V_125 ) {
F_8 ( 0 , L_25
L_26 ) ;
}
F_20 ( V_2 , V_126 , V_4 , V_46 ) ;
}
void F_65 ( struct V_1 * V_2 , T_1 V_36 , T_3 V_43 ,
struct V_3 * V_127 )
{
struct V_3 * V_30 ;
struct V_128 * V_32 ;
T_1 * V_46 ;
V_30 = F_13 ( V_127 -> V_73 + sizeof( struct V_128 ) , V_35 ) ;
if ( ! V_30 )
return;
if ( V_36 == V_38 ) {
V_32 = (struct V_128 * )
F_14 ( V_30 , sizeof( struct V_128 ) ) ;
V_32 -> V_42 = F_15 ( V_2 -> V_42 ) ;
V_32 -> V_43 = F_15 ( V_43 ) ;
} else
V_32 = (struct V_128 * ) F_14 ( V_30 , V_129 + V_130 ) ;
V_32 -> V_36 = V_36 ;
V_32 -> V_39 = V_131 | V_41 ;
V_46 = F_14 ( V_30 , V_127 -> V_73 ) ;
memcpy ( V_46 , V_127 -> V_47 , V_127 -> V_73 ) ;
F_57 ( V_2 , & V_2 -> V_116 ) ;
F_2 ( V_2 , V_30 ) ;
}
static void F_66 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_45 * V_46 , int V_60 )
{
struct V_128 * V_32 ;
F_8 ( 2 , L_5 , V_26 ) ;
if ( ! F_18 ( V_4 , sizeof( * V_32 ) ) ) {
F_28 ( L_7 , V_26 ) ;
return;
}
V_32 = (struct V_128 * ) V_4 -> V_47 ;
if ( V_46 -> V_36 == V_38 ) {
if ( V_4 -> V_73 < sizeof( struct V_128 ) ) {
F_8 ( 0 , L_27 ,
V_26 ) ;
return;
}
V_46 -> V_43 = F_19 ( V_32 -> V_42 ) ;
V_46 -> V_42 = F_19 ( V_32 -> V_43 ) ;
if ( ( V_46 -> V_42 != V_2 -> V_42 ) &&
( V_46 -> V_42 != V_64 ) ) {
return;
}
}
if ( V_60 )
F_20 ( V_2 , V_132 , V_4 , V_46 ) ;
else
F_20 ( V_2 , V_133 , V_4 , V_46 ) ;
}
int F_67 ( struct V_3 * V_4 , struct V_134 * V_18 ,
struct V_135 * V_136 , struct V_134 * V_137 )
{
struct V_45 V_46 ;
struct V_1 * V_2 ;
int V_60 ;
T_1 V_39 ;
int V_33 = - 1 ;
if ( ! F_68 ( F_69 ( V_18 ) , & V_138 ) )
goto V_139;
V_2 = (struct V_1 * ) V_18 -> V_140 ;
if ( ! V_2 || V_2 -> V_7 != V_8 )
goto V_141;
if ( ( V_4 = F_70 ( V_4 , V_35 ) ) == NULL ) {
F_28 ( L_28 , V_26 ) ;
goto V_141;
}
if ( ! F_18 ( V_4 , 2 ) ) {
F_28 ( L_7 , V_26 ) ;
goto V_141;
}
V_60 = V_4 -> V_47 [ 0 ] & V_37 ;
V_46 . V_36 = V_4 -> V_47 [ 0 ] & V_38 ;
V_46 . V_117 = V_4 -> V_47 [ 1 ] & V_41 ;
V_46 . V_39 = V_4 -> V_47 [ 1 ] & ~ V_41 ;
V_39 = V_46 . V_39 ;
if ( ( V_46 . V_36 != V_2 -> V_36 ) && ( V_46 . V_36 != V_38 ) ) {
F_8 ( 0 , L_29 ,
V_26 ) ;
goto V_139;
}
if ( ~ V_39 & 0x01 ) {
F_62 ( V_2 , V_4 , & V_46 , V_60 ) ;
goto V_139;
}
if ( ~ V_39 & 0x02 ) {
switch ( V_39 & 0x0f ) {
case V_86 :
F_35 ( V_2 , V_4 , & V_46 , V_60 ) ;
break;
case V_142 :
F_36 ( V_2 , V_4 , & V_46 , V_60 ) ;
break;
case V_143 :
F_37 ( V_2 , V_4 , & V_46 , V_60 ) ;
break;
case V_144 :
F_38 ( V_2 , V_4 , & V_46 , V_60 ) ;
break;
default:
F_30 ( L_30 ,
V_26 , V_46 . V_39 ) ;
break;
}
goto V_139;
}
switch ( V_39 ) {
case V_67 :
F_27 ( V_2 , V_4 , & V_46 ) ;
break;
case V_66 :
F_32 ( V_2 , V_4 , & V_46 ) ;
break;
case V_40 :
F_17 ( V_2 , V_4 , & V_46 ) ;
break;
case V_55 :
F_20 ( V_2 , V_145 , V_4 , & V_46 ) ;
break;
case V_57 :
F_39 ( V_2 , V_4 , & V_46 , V_60 ) ;
break;
case V_146 :
F_66 ( V_2 , V_4 , & V_46 , V_60 ) ;
break;
case V_51 :
F_40 ( V_2 , V_4 , & V_46 ) ;
break;
case V_147 :
F_64 ( V_2 , V_4 , & V_46 ) ;
break;
case V_148 :
F_63 ( V_2 , V_4 , & V_46 ) ;
break;
default:
F_30 ( L_31 ,
V_26 , V_46 . V_39 ) ;
break;
}
V_139:
V_33 = 0 ;
V_141:
F_9 ( V_4 ) ;
return V_33 ;
}
