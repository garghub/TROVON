static inline int
F_1 ( int V_1 , int V_2 )
{
return V_1 - ( V_2 % V_1 ) ;
}
static inline void
F_2 ( struct V_3 * V_4 , int V_5 , int V_1 )
{
int V_6 = F_1 ( V_1 , V_4 -> V_7 - V_5 ) ;
char * V_8 ;
struct V_9 * V_10 ;
if ( V_4 -> V_11 || V_4 -> V_12 [ 0 ] . V_13 )
V_10 = & V_4 -> V_12 [ 0 ] ;
else
V_10 = & V_4 -> V_14 [ 0 ] ;
V_8 = V_10 -> V_15 + V_10 -> V_13 ;
V_10 -> V_13 += V_6 ;
V_4 -> V_7 += V_6 ;
memset ( V_8 , V_6 , V_6 ) ;
}
static inline int
F_3 ( struct V_3 * V_4 , int V_1 )
{
T_1 * V_16 ;
T_1 V_17 ;
T_2 V_7 = V_4 -> V_7 ;
if ( V_7 <= V_4 -> V_14 [ 0 ] . V_13 ) {
V_17 = * ( T_1 * ) ( V_4 -> V_14 [ 0 ] . V_15 + V_7 - 1 ) ;
if ( V_17 > V_4 -> V_14 [ 0 ] . V_13 )
return - V_18 ;
V_4 -> V_14 [ 0 ] . V_13 -= V_17 ;
goto V_19;
} else
V_7 -= V_4 -> V_14 [ 0 ] . V_13 ;
if ( V_7 <= V_4 -> V_11 ) {
unsigned int V_20 = ( V_4 -> V_21 + V_7 - 1 )
>> V_22 ;
unsigned int V_5 = ( V_4 -> V_21 + V_7 - 1 )
& ( V_23 - 1 ) ;
V_16 = F_4 ( V_4 -> V_24 [ V_20 ] , V_25 ) ;
V_17 = * ( V_16 + V_5 ) ;
F_5 ( V_16 , V_25 ) ;
goto V_19;
} else
V_7 -= V_4 -> V_11 ;
F_6 ( V_7 > V_4 -> V_12 [ 0 ] . V_13 ) ;
V_17 = * ( T_1 * ) ( V_4 -> V_12 [ 0 ] . V_15 + V_7 - 1 ) ;
V_19:
if ( V_17 > V_1 )
return - V_18 ;
if ( V_4 -> V_7 > V_17 )
V_4 -> V_7 -= V_17 ;
else
return - V_18 ;
return 0 ;
}
void
F_7 ( char * V_8 , T_3 V_26 )
{
static T_4 V_27 = 0 ;
T_4 * V_28 = ( T_4 * ) V_8 ;
if ( V_27 == 0 ) {
V_27 = F_8 () ;
V_27 = ( V_27 << 32 ) | F_8 () ;
}
switch ( V_26 ) {
case 16 :
* V_28 ++ = V_27 ++ ;
case 8 :
* V_28 ++ = V_27 ++ ;
break;
default:
F_9 () ;
}
}
static T_3
F_10 ( struct V_29 * V_30 , int V_5 ,
struct V_3 * V_4 , struct V_31 * * V_24 )
{
char V_32 [ V_33 ] ;
struct V_34 V_35 = { . V_7 = sizeof( V_32 ) ,
. V_36 = V_32 } ;
int V_1 = 0 , V_37 ;
unsigned char * V_16 , * V_38 ;
T_5 V_39 ;
int V_40 ;
struct V_31 * * V_41 ;
T_3 V_42 ;
T_1 * V_43 ;
T_3 V_26 = V_30 -> V_44 -> V_26 ;
F_11 ( L_1 , V_45 ) ;
V_39 = F_12 () ;
V_1 = F_13 ( V_30 -> V_46 ) ;
F_2 ( V_4 , V_5 , V_1 ) ;
F_6 ( ( V_4 -> V_7 - V_5 ) % V_1 ) ;
V_37 = V_26 + V_4 -> V_7 - V_5 ;
V_40 = F_14 ( & V_30 -> V_47 ,
V_48 + V_30 -> V_44 -> V_49 + V_37 ) -
( V_4 -> V_7 - V_5 ) ;
V_16 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
F_15 ( V_4 , V_5 , V_40 ) ;
F_6 ( ( V_4 -> V_7 - V_5 - V_40 ) % V_1 ) ;
F_16 ( & V_30 -> V_47 ,
V_48 +
V_30 -> V_44 -> V_49 + V_37 , & V_16 ) ;
V_16 [ 0 ] = ( unsigned char ) ( ( V_50 >> 8 ) & 0xff ) ;
V_16 [ 1 ] = ( unsigned char ) ( V_50 & 0xff ) ;
V_38 = V_16 + V_48 + V_30 -> V_44 -> V_49 ;
* ( V_51 * ) ( V_16 + 2 ) = F_17 ( V_30 -> V_44 -> V_52 ) ;
memset ( V_16 + 4 , 0xff , 4 ) ;
* ( V_51 * ) ( V_16 + 4 ) = F_17 ( V_30 -> V_44 -> V_53 ) ;
F_7 ( V_38 , V_26 ) ;
if ( V_30 -> V_44 -> V_54 )
V_43 = V_30 -> V_55 ;
else
V_43 = NULL ;
V_41 = V_4 -> V_24 ;
V_4 -> V_24 = V_24 ;
if ( F_18 ( V_30 , V_16 , 8 , V_4 , V_5 + V_40 - V_26 ,
V_43 , V_56 , & V_35 ) )
return V_57 ;
V_4 -> V_24 = V_41 ;
memcpy ( V_16 + V_48 , V_35 . V_36 , V_35 . V_7 ) ;
F_19 ( & V_58 ) ;
V_42 = V_30 -> V_42 ++ ;
F_20 ( & V_58 ) ;
if ( ( F_21 ( V_30 , V_30 -> V_59 , V_30 -> V_60 ? 0 : 0xff ,
V_42 , V_16 + V_48 , V_16 + 8 ) ) )
return V_57 ;
if ( V_30 -> V_61 == V_62 ) {
struct V_63 * V_64 ;
int V_65 ;
V_64 = F_22 ( V_30 -> V_44 -> V_66 , 0 ,
V_67 ) ;
if ( F_23 ( V_64 ) )
return V_57 ;
F_24 ( V_30 , V_64 , V_42 ) ;
V_65 = F_25 ( V_64 , V_4 ,
V_5 + V_40 - V_26 , V_24 ) ;
F_26 ( V_64 ) ;
if ( V_65 )
return V_57 ;
} else {
if ( F_25 ( V_30 -> V_46 , V_4 ,
V_5 + V_40 - V_26 , V_24 ) )
return V_57 ;
}
return ( V_30 -> V_68 < V_39 ) ? V_69 : V_70 ;
}
static T_3
F_27 ( struct V_29 * V_30 , int V_5 , struct V_3 * V_4 )
{
int V_52 ;
int V_53 ;
char V_32 [ V_33 ] ;
struct V_34 V_35 = { . V_7 = sizeof( V_32 ) ,
. V_36 = V_32 } ;
T_5 V_39 ;
int V_71 ;
T_5 V_72 ;
unsigned char * V_16 ;
int V_73 ;
void * V_74 , * V_75 ;
int V_76 ;
int V_1 ;
T_3 V_26 = V_30 -> V_44 -> V_26 ;
int V_77 ;
T_1 * V_43 ;
F_11 ( L_2 ) ;
V_16 = ( T_1 * ) V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
if ( F_28 ( & V_30 -> V_47 , & V_73 , & V_16 ,
V_4 -> V_7 - V_5 ) )
return V_78 ;
if ( ( V_16 [ 0 ] != ( ( V_50 >> 8 ) & 0xff ) ) ||
( V_16 [ 1 ] != ( V_50 & 0xff ) ) )
return V_78 ;
V_52 = V_16 [ 2 ] + ( V_16 [ 3 ] << 8 ) ;
if ( V_52 != V_30 -> V_44 -> V_52 )
return V_78 ;
V_53 = V_16 [ 4 ] + ( V_16 [ 5 ] << 8 ) ;
if ( V_53 != V_30 -> V_44 -> V_53 )
return V_78 ;
if ( ( V_16 [ 6 ] != 0xff ) || ( V_16 [ 7 ] != 0xff ) )
return V_78 ;
V_77 = V_16 + ( V_48 + V_30 -> V_44 -> V_49 ) -
( unsigned char * ) V_4 -> V_14 [ 0 ] . V_15 ;
if ( F_29 ( V_30 , V_16 + V_48 ,
V_16 + 8 , & V_71 , & V_72 ) )
return V_79 ;
if ( ( V_30 -> V_60 && V_71 != 0xff ) ||
( ! V_30 -> V_60 && V_71 != 0 ) )
return V_79 ;
if ( V_30 -> V_61 == V_62 ) {
struct V_63 * V_64 ;
int V_65 ;
V_64 = F_22 ( V_30 -> V_44 -> V_66 , 0 ,
V_67 ) ;
if ( F_23 ( V_64 ) )
return V_57 ;
F_24 ( V_30 , V_64 , V_72 ) ;
V_65 = F_30 ( V_64 , V_4 , V_77 ) ;
F_26 ( V_64 ) ;
if ( V_65 )
return V_78 ;
} else {
if ( F_30 ( V_30 -> V_46 , V_4 , V_77 ) )
return V_78 ;
}
if ( V_30 -> V_44 -> V_54 )
V_43 = V_30 -> V_55 ;
else
V_43 = NULL ;
if ( F_18 ( V_30 , V_16 , 8 , V_4 , V_77 ,
V_43 , V_56 , & V_35 ) )
return V_57 ;
if ( memcmp ( V_35 . V_36 , V_16 + V_48 ,
V_30 -> V_44 -> V_49 ) )
return V_79 ;
V_39 = F_12 () ;
if ( V_39 > V_30 -> V_68 )
return V_69 ;
V_1 = F_13 ( V_30 -> V_46 ) ;
V_74 = V_16 + ( V_48 + V_30 -> V_44 -> V_49 ) +
V_26 ;
V_75 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
V_76 = ( V_4 -> V_14 [ 0 ] . V_15 + V_4 -> V_14 [ 0 ] . V_13 ) - V_74 ;
memmove ( V_75 , V_74 , V_76 ) ;
V_4 -> V_14 [ 0 ] . V_13 -= ( V_74 - V_75 ) ;
V_4 -> V_7 -= ( V_74 - V_75 ) ;
if ( F_3 ( V_4 , V_1 ) )
return V_78 ;
return V_70 ;
}
static T_3
F_31 ( struct V_29 * V_30 , T_3 V_5 , struct V_3 * V_4 , T_6 V_80 )
{
unsigned int V_81 = V_80 % ( V_4 -> V_7 - V_5 - V_48 ) ;
if ( V_81 == 0 )
return 0 ;
F_11 ( L_3
L_4 , V_45 , V_80 , V_81 ) ;
return 1 ;
}
static T_3
F_32 ( struct V_29 * V_30 , T_3 V_5 ,
struct V_3 * V_4 , struct V_31 * * V_24 )
{
int V_1 ;
T_1 * V_16 , * V_82 ;
T_5 V_39 ;
T_1 V_83 = 0x00 ;
V_51 * V_84 , V_85 = 0 ;
T_7 * V_86 ;
T_3 V_65 ;
F_11 ( L_1 , V_45 ) ;
if ( V_30 -> V_44 -> V_87 == NULL )
return V_57 ;
if ( F_15 ( V_4 , V_5 , V_48 ) )
return V_57 ;
V_16 = V_82 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
* V_16 ++ = ( unsigned char ) ( ( V_88 >> 8 ) & 0xff ) ;
* V_16 ++ = ( unsigned char ) ( V_88 & 0xff ) ;
if ( ( V_30 -> V_83 & V_89 ) == 0 )
V_83 |= V_90 ;
if ( ( V_30 -> V_83 & V_91 ) != 0 )
V_83 |= V_92 ;
V_83 |= V_93 ;
* V_16 ++ = V_83 ;
* V_16 ++ = 0xff ;
V_84 = ( V_51 * ) V_16 ;
V_1 = F_13 ( V_30 -> V_94 ) ;
* V_84 ++ = F_33 ( V_85 ) ;
* V_84 ++ = F_33 ( 0 ) ;
V_86 = ( T_7 * ) V_84 ;
F_19 ( & V_58 ) ;
* V_86 = F_34 ( V_30 -> V_95 ++ ) ;
F_20 ( & V_58 ) ;
V_65 = (* V_30 -> V_44 -> V_87 )( V_30 , V_5 , V_4 , V_85 , V_24 ) ;
if ( V_65 )
return V_65 ;
V_39 = F_12 () ;
return ( V_30 -> V_68 < V_39 ) ? V_69 : V_70 ;
}
static T_3
F_35 ( struct V_29 * V_30 , int V_5 , struct V_3 * V_4 )
{
T_5 V_39 ;
T_4 V_72 ;
T_1 * V_16 ;
T_1 V_83 = 0x00 ;
T_6 V_85 , V_80 ;
int V_65 ;
T_3 V_96 , V_97 ;
T_1 V_98 [ V_48 ] ;
unsigned int V_99 ;
F_11 ( L_1 , V_45 ) ;
if ( V_30 -> V_44 -> V_100 == NULL )
return V_57 ;
V_16 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
if ( F_36 ( * ( ( V_51 * ) V_16 ) ) != V_88 )
return V_78 ;
V_83 = V_16 [ 2 ] ;
if ( ( ! V_30 -> V_60 && ( V_83 & V_90 ) ) ||
( V_30 -> V_60 && ! ( V_83 & V_90 ) ) )
return V_79 ;
if ( ( V_83 & V_93 ) == 0 ) {
F_11 ( L_5 , V_45 ) ;
return V_78 ;
}
if ( V_16 [ 3 ] != 0xff )
return V_78 ;
V_85 = F_37 ( ( V_51 * ) ( V_16 + 4 ) ) ;
V_80 = F_37 ( ( V_51 * ) ( V_16 + 6 ) ) ;
V_72 = F_38 ( ( T_7 * ) ( V_16 + 8 ) ) ;
if ( V_80 != 0 ) {
V_65 = F_31 ( V_30 , V_5 , V_4 , V_80 ) ;
if ( V_65 )
return V_57 ;
}
V_65 = (* V_30 -> V_44 -> V_100 )( V_30 , V_5 , V_4 ,
& V_96 , & V_97 ) ;
if ( V_65 )
return V_57 ;
V_65 = F_39 ( V_4 ,
V_4 -> V_7 - V_48 - V_97 ,
V_98 , V_48 ) ;
if ( V_65 ) {
F_11 ( L_6 , V_45 , V_65 ) ;
return V_57 ;
}
if ( memcmp ( V_16 , V_98 , 6 )
|| memcmp ( V_16 + 8 , V_98 + 8 , 8 ) ) {
F_11 ( L_7 , V_45 ) ;
return V_57 ;
}
V_39 = F_12 () ;
if ( V_39 > V_30 -> V_68 )
return V_69 ;
V_99 = F_40 (unsigned int, buf->head[0].iov_len, buf->len) ;
V_99 -= V_5 + V_48 + V_96 ;
F_6 ( V_5 + V_48 + V_96 + V_99 >
V_4 -> V_14 [ 0 ] . V_13 ) ;
memmove ( V_16 , V_16 + V_48 + V_96 , V_99 ) ;
V_4 -> V_14 [ 0 ] . V_13 -= V_48 + V_96 ;
V_4 -> V_7 -= V_48 + V_96 ;
return V_70 ;
}
T_3
F_41 ( struct V_101 * V_102 , int V_5 ,
struct V_3 * V_4 , struct V_31 * * V_24 )
{
struct V_29 * V_30 = V_102 -> V_103 ;
switch ( V_30 -> V_61 ) {
default:
F_9 () ;
case V_104 :
case V_105 :
case V_62 :
return F_10 ( V_30 , V_5 , V_4 , V_24 ) ;
case V_106 :
case V_107 :
return F_32 ( V_30 , V_5 , V_4 , V_24 ) ;
}
}
T_3
F_42 ( struct V_101 * V_102 , int V_5 , struct V_3 * V_4 )
{
struct V_29 * V_30 = V_102 -> V_103 ;
switch ( V_30 -> V_61 ) {
default:
F_9 () ;
case V_104 :
case V_105 :
case V_62 :
return F_27 ( V_30 , V_5 , V_4 ) ;
case V_106 :
case V_107 :
return F_35 ( V_30 , V_5 , V_4 ) ;
}
}
