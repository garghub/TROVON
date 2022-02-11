static int F_1 ( const void * V_1 , unsigned int V_2 ,
struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_1 ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 ;
const struct V_13 * V_14 ;
const struct V_15 * V_16 ;
const struct V_17 * V_18 , * V_19 ;
T_1 V_20 , V_21 = V_2 ;
F_2 ( L_1 ) ;
#define F_3 ( T_2 , T_3 , T_4 ) \
do { \
if ((x) < base || (s) >= datalen || (x) > datalen - (s)) \
return -ELIBBAD; \
} while (0)
F_3 ( 0 , 0 , sizeof( * V_6 ) ) ;
if ( V_6 -> V_22 != V_23 )
return - V_24 ;
V_20 = sizeof( * V_6 ) ;
F_3 ( V_20 , V_6 -> V_25 , sizeof( * V_8 ) ) ;
V_8 = V_1 + V_6 -> V_25 ;
if ( V_8 -> V_22 != V_26 )
return - V_24 ;
V_20 = V_6 -> V_25 + sizeof( * V_8 ) ;
F_3 ( 0 , V_20 , sizeof( V_10 -> V_22 ) ) ;
V_10 = V_1 + V_20 ;
V_12 = V_1 + V_20 ;
switch ( V_10 -> V_22 ) {
case V_27 :
F_3 ( 0 , V_20 , sizeof( * V_10 ) ) ;
V_4 -> V_28 =
( unsigned long ) & V_10 -> V_29 - ( unsigned long ) V_1 ;
V_4 -> V_30 = V_10 -> V_30 ;
V_20 += sizeof( * V_10 ) ;
V_4 -> V_31 = V_10 -> V_32 ;
break;
case V_33 :
F_3 ( 0 , V_20 , sizeof( * V_12 ) ) ;
V_4 -> V_28 =
( unsigned long ) & V_12 -> V_29 - ( unsigned long ) V_1 ;
V_4 -> V_30 = V_12 -> V_30 ;
V_20 += sizeof( * V_12 ) ;
V_4 -> V_31 = V_12 -> V_32 ;
break;
default:
F_4 ( L_2 , V_10 -> V_22 ) ;
return - V_24 ;
}
F_4 ( L_3 , V_4 -> V_28 ) ;
F_4 ( L_4 , V_4 -> V_30 ) ;
if ( V_20 >= V_4 -> V_30 || V_4 -> V_30 >= V_21 )
return - V_24 ;
if ( V_4 -> V_31 > ( V_4 -> V_30 - V_20 ) / sizeof( * V_16 ) )
return - V_24 ;
V_14 = V_1 + V_20 ;
V_20 += sizeof( * V_16 ) * V_4 -> V_31 ;
V_4 -> V_34 =
( unsigned long ) & V_14 -> V_35 - ( unsigned long ) V_1 ;
V_4 -> V_36 = V_14 -> V_35 . V_37 ;
if ( ! V_14 -> V_35 . V_38 || ! V_14 -> V_35 . V_37 ) {
F_4 ( L_5 ) ;
return - V_39 ;
}
F_3 ( V_4 -> V_30 , V_14 -> V_35 . V_38 ,
V_14 -> V_35 . V_37 ) ;
V_4 -> V_40 = V_14 -> V_35 . V_38 ;
V_4 -> V_41 = V_14 -> V_35 . V_37 ;
F_4 ( L_6 ,
V_4 -> V_41 , V_4 -> V_40 ,
V_4 -> V_41 , V_1 + V_4 -> V_40 ) ;
V_4 -> V_42 = V_8 -> V_43 ;
if ( V_4 -> V_42 > ( V_4 -> V_30 - V_20 ) / sizeof( * V_19 ) )
return - V_24 ;
V_4 -> V_18 = V_18 = V_1 + V_20 ;
return 0 ;
}
static int F_5 ( const void * V_1 ,
struct V_3 * V_4 )
{
struct V_44 V_45 ;
const T_5 * V_46 ;
unsigned V_47 ;
if ( V_4 -> V_41 < sizeof( V_45 ) ) {
F_4 ( L_7 ) ;
return - V_24 ;
}
memcpy ( & V_45 , V_1 + V_4 -> V_40 , sizeof( V_45 ) ) ;
F_4 ( L_8 ,
V_45 . V_48 , V_45 . V_49 , V_45 . V_50 ) ;
if ( F_6 ( V_45 . V_48 , 8 ) != V_4 -> V_41 ) {
F_4 ( L_9 ) ;
return - V_24 ;
}
if ( V_45 . V_49 != V_51 ) {
F_4 ( L_10 ) ;
return - V_52 ;
}
if ( V_45 . V_50 != V_53 ) {
F_4 ( L_11 ) ;
return - V_52 ;
}
V_4 -> V_41 = V_45 . V_48 ;
V_4 -> V_40 += sizeof( V_45 ) ;
V_4 -> V_41 -= sizeof( V_45 ) ;
if ( V_4 -> V_41 < 4 ) {
F_4 ( L_12 ) ;
return - V_39 ;
}
V_46 = V_1 + V_4 -> V_40 ;
if ( V_46 [ 0 ] != ( V_54 | V_55 ) )
goto V_56;
switch ( V_46 [ 1 ] ) {
case 0 ... 0x7f :
V_47 = V_46 [ 1 ] + 2 ;
goto V_57;
case V_58 :
return 0 ;
case 0x81 :
V_47 = V_46 [ 2 ] + 3 ;
goto V_57;
case 0x82 :
V_47 = ( ( V_46 [ 2 ] << 8 ) | V_46 [ 3 ] ) + 4 ;
goto V_57;
case 0x83 ... 0xff :
return - V_59 ;
default:
goto V_56;
}
V_57:
if ( V_47 <= V_4 -> V_41 ) {
V_4 -> V_41 = V_47 ;
return 0 ;
}
V_56:
F_4 ( L_13 ) ;
return - V_24 ;
}
static int F_7 ( const void * V_60 , const void * V_61 )
{
const struct V_17 * V_62 = V_60 ;
const struct V_17 * V_63 = V_61 ;
int V_64 ;
if ( V_62 -> V_65 > V_63 -> V_65 )
return 1 ;
if ( V_63 -> V_65 > V_62 -> V_65 )
return - 1 ;
if ( V_62 -> V_38 > V_63 -> V_38 )
return 1 ;
if ( V_63 -> V_38 > V_62 -> V_38 )
return - 1 ;
V_64 = strcmp ( V_62 -> V_66 , V_63 -> V_66 ) ;
if ( V_64 != 0 )
return V_64 ;
if ( V_62 -> V_67 > V_63 -> V_67 )
return 1 ;
if ( V_63 -> V_67 > V_62 -> V_67 )
return - 1 ;
if ( V_62 -> V_68 > V_63 -> V_68 )
return 1 ;
if ( V_63 -> V_68 > V_62 -> V_68 )
return - 1 ;
return 0 ;
}
static int F_8 ( const void * V_1 , unsigned int V_2 ,
struct V_3 * V_4 ,
struct V_69 * V_70 )
{
unsigned * V_71 , V_72 , V_73 , V_74 , V_75 ;
int V_76 ;
V_76 = F_9 ( V_70 , V_1 , V_4 -> V_28 ) ;
if ( V_76 < 0 )
return V_76 ;
V_72 = V_4 -> V_28 + sizeof( V_77 ) ;
V_76 = F_9 ( V_70 , V_1 + V_72 ,
V_4 -> V_34 - V_72 ) ;
if ( V_76 < 0 )
return V_76 ;
V_72 = V_4 -> V_34 + sizeof( struct V_15 ) ;
V_76 = F_9 ( V_70 , V_1 + V_72 , V_4 -> V_30 - V_72 ) ;
if ( V_76 < 0 )
return V_76 ;
V_71 = F_10 ( V_4 -> V_42 , sizeof( unsigned ) , V_78 ) ;
if ( ! V_71 )
return - V_79 ;
V_71 [ 0 ] = 0 ;
for ( V_73 = 1 ; V_73 < V_4 -> V_42 ; V_73 ++ ) {
for ( V_74 = 0 ; V_74 < V_73 ; V_74 ++ ) {
if ( F_7 ( & V_4 -> V_18 [ V_71 [ V_74 ] ] ,
& V_4 -> V_18 [ V_73 ] ) > 0 ) {
memmove ( & V_71 [ V_74 + 1 ] , & V_71 [ V_74 ] ,
( V_73 - V_74 ) * sizeof( V_71 [ 0 ] ) ) ;
break;
}
}
V_71 [ V_74 ] = V_73 ;
}
V_75 = V_4 -> V_30 ;
for ( V_73 = 0 ; V_73 < V_4 -> V_42 ; V_73 ++ ) {
V_74 = V_71 [ V_73 ] ;
if ( V_4 -> V_18 [ V_74 ] . V_68 == 0 )
continue;
V_76 = F_9 ( V_70 ,
V_1 + V_4 -> V_18 [ V_74 ] . V_65 ,
V_4 -> V_18 [ V_74 ] . V_68 ) ;
if ( V_76 < 0 ) {
F_11 ( V_71 ) ;
return V_76 ;
}
V_75 += V_4 -> V_18 [ V_74 ] . V_68 ;
}
F_11 ( V_71 ) ;
if ( V_2 > V_75 ) {
V_72 = V_75 + V_4 -> V_36 ;
V_76 = F_9 ( V_70 ,
V_1 + V_75 ,
V_2 - V_72 ) ;
if ( V_76 < 0 )
return V_76 ;
}
return 0 ;
}
static int F_12 ( const void * V_1 , unsigned int V_2 ,
struct V_3 * V_4 )
{
struct V_80 * V_81 ;
struct V_69 * V_70 ;
T_1 V_82 , V_83 ;
void * V_84 ;
int V_76 ;
F_2 ( L_14 , V_4 -> V_85 ) ;
V_81 = F_13 ( V_4 -> V_85 , 0 , 0 ) ;
if ( F_14 ( V_81 ) )
return ( F_15 ( V_81 ) == - V_86 ) ? - V_87 : F_15 ( V_81 ) ;
V_83 = F_16 ( V_81 ) + sizeof( * V_70 ) ;
V_82 = F_17 ( V_81 ) ;
if ( V_82 != V_4 -> V_88 ) {
F_4 ( L_15 ,
V_82 , V_4 -> V_88 ) ;
V_76 = - V_89 ;
goto V_90;
}
F_4 ( L_16 , V_83 , V_82 ) ;
V_76 = - V_79 ;
V_70 = F_18 ( V_83 + V_82 , V_78 ) ;
if ( ! V_70 )
goto V_90;
V_70 -> V_81 = V_81 ;
V_70 -> V_91 = V_92 ;
V_76 = F_19 ( V_70 ) ;
if ( V_76 < 0 )
goto error;
V_76 = F_8 ( V_1 , V_2 , V_4 , V_70 ) ;
if ( V_76 < 0 )
goto error;
V_84 = ( void * ) V_70 + V_83 ;
V_76 = F_20 ( V_70 , V_84 ) ;
if ( V_76 < 0 )
goto error;
F_4 ( L_17 , V_4 -> V_88 , V_84 ) ;
if ( memcmp ( V_84 , V_4 -> V_84 , V_4 -> V_88 ) != 0 ) {
F_4 ( L_18 ) ;
V_76 = - V_39 ;
} else {
F_4 ( L_19 ) ;
}
error:
F_11 ( V_70 ) ;
V_90:
F_21 ( V_81 ) ;
F_22 ( L_20 , V_76 ) ;
return V_76 ;
}
int F_23 ( const void * V_1 , unsigned V_2 ,
struct V_93 * V_94 ,
enum V_95 V_96 ,
bool * V_97 )
{
struct V_98 * V_46 ;
struct V_3 V_4 ;
const void * V_99 ;
T_1 V_21 ;
int V_76 ;
F_2 ( L_1 ) ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_76 = F_1 ( V_1 , V_2 , & V_4 ) ;
if ( V_76 < 0 )
return V_76 ;
V_76 = F_5 ( V_1 , & V_4 ) ;
if ( V_76 < 0 )
return V_76 ;
V_46 = F_24 ( V_1 + V_4 . V_40 , V_4 . V_41 ) ;
if ( F_14 ( V_46 ) )
return F_15 ( V_46 ) ;
V_4 . V_46 = V_46 ;
V_76 = F_25 ( V_4 . V_46 , & V_99 , & V_21 , false ) ;
if ( V_76 < 0 || V_21 == 0 ) {
F_26 ( L_21 ) ;
V_76 = - V_89 ;
goto error;
}
V_76 = F_27 ( & V_4 ) ;
if ( V_76 < 0 )
goto error;
F_4 ( L_22 ,
V_4 . V_88 , V_4 . V_88 , V_4 . V_84 ) ;
V_76 = F_12 ( V_1 , V_2 , & V_4 ) ;
if ( V_76 < 0 )
goto error;
V_76 = F_28 ( V_46 , V_96 ) ;
if ( V_76 < 0 )
goto error;
V_76 = F_29 ( V_46 , V_94 , V_97 ) ;
error:
F_30 ( V_4 . V_46 ) ;
return V_76 ;
}
