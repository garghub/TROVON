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
V_16 = F_4 ( V_4 -> V_24 [ V_20 ] ) ;
V_17 = * ( V_16 + V_5 ) ;
F_5 ( V_16 ) ;
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
F_7 ( char * V_8 , T_3 V_25 )
{
static T_4 V_26 = 0 ;
T_4 * V_27 = ( T_4 * ) V_8 ;
if ( V_26 == 0 ) {
V_26 = F_8 () ;
V_26 = ( V_26 << 32 ) | F_8 () ;
}
switch ( V_25 ) {
case 16 :
* V_27 ++ = V_26 ++ ;
case 8 :
* V_27 ++ = V_26 ++ ;
break;
default:
F_9 () ;
}
}
static T_3
F_10 ( struct V_28 * V_29 , int V_5 ,
struct V_3 * V_4 , struct V_30 * * V_24 )
{
char V_31 [ V_32 ] ;
struct V_33 V_34 = { . V_7 = sizeof( V_31 ) ,
. V_35 = V_31 } ;
int V_1 = 0 , V_36 ;
unsigned char * V_16 , * V_37 ;
T_5 V_38 ;
int V_39 ;
struct V_30 * * V_40 ;
T_3 V_41 ;
T_1 * V_42 ;
T_3 V_25 = V_29 -> V_43 -> V_25 ;
F_11 ( L_1 , V_44 ) ;
V_38 = F_12 () ;
V_1 = F_13 ( V_29 -> V_45 ) ;
F_2 ( V_4 , V_5 , V_1 ) ;
F_6 ( ( V_4 -> V_7 - V_5 ) % V_1 ) ;
V_36 = V_25 + V_4 -> V_7 - V_5 ;
V_39 = F_14 ( & V_29 -> V_46 ,
V_47 + V_29 -> V_43 -> V_48 + V_36 ) -
( V_4 -> V_7 - V_5 ) ;
V_16 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
F_15 ( V_4 , V_5 , V_39 ) ;
F_6 ( ( V_4 -> V_7 - V_5 - V_39 ) % V_1 ) ;
F_16 ( & V_29 -> V_46 ,
V_47 +
V_29 -> V_43 -> V_48 + V_36 , & V_16 ) ;
V_16 [ 0 ] = ( unsigned char ) ( ( V_49 >> 8 ) & 0xff ) ;
V_16 [ 1 ] = ( unsigned char ) ( V_49 & 0xff ) ;
V_37 = V_16 + V_47 + V_29 -> V_43 -> V_48 ;
* ( V_50 * ) ( V_16 + 2 ) = F_17 ( V_29 -> V_43 -> V_51 ) ;
* ( V_50 * ) ( V_16 + 4 ) = F_17 ( V_29 -> V_43 -> V_52 ) ;
V_16 [ 6 ] = 0xff ;
V_16 [ 7 ] = 0xff ;
F_7 ( V_37 , V_25 ) ;
if ( V_29 -> V_43 -> V_53 )
V_42 = V_29 -> V_54 ;
else
V_42 = NULL ;
V_40 = V_4 -> V_24 ;
V_4 -> V_24 = V_24 ;
if ( F_18 ( V_29 , V_16 , 8 , V_4 , V_5 + V_39 - V_25 ,
V_42 , V_55 , & V_34 ) )
return V_56 ;
V_4 -> V_24 = V_40 ;
memcpy ( V_16 + V_47 , V_34 . V_35 , V_34 . V_7 ) ;
F_19 ( & V_57 ) ;
V_41 = V_29 -> V_41 ++ ;
F_20 ( & V_57 ) ;
if ( ( F_21 ( V_29 , V_29 -> V_58 , V_29 -> V_59 ? 0 : 0xff ,
V_41 , V_16 + V_47 , V_16 + 8 ) ) )
return V_56 ;
if ( V_29 -> V_60 == V_61 ) {
struct V_62 * V_63 ;
int V_64 ;
V_63 = F_22 ( V_29 -> V_43 -> V_65 , 0 ,
V_66 ) ;
if ( F_23 ( V_63 ) )
return V_56 ;
F_24 ( V_29 , V_63 , V_41 ) ;
V_64 = F_25 ( V_63 , V_4 ,
V_5 + V_39 - V_25 , V_24 ) ;
F_26 ( V_63 ) ;
if ( V_64 )
return V_56 ;
} else {
if ( F_25 ( V_29 -> V_45 , V_4 ,
V_5 + V_39 - V_25 , V_24 ) )
return V_56 ;
}
return ( V_29 -> V_67 < V_38 ) ? V_68 : V_69 ;
}
static T_3
F_27 ( struct V_28 * V_29 , int V_5 , struct V_3 * V_4 )
{
int V_51 ;
int V_52 ;
char V_31 [ V_32 ] ;
struct V_33 V_34 = { . V_7 = sizeof( V_31 ) ,
. V_35 = V_31 } ;
T_5 V_38 ;
int V_70 ;
T_5 V_71 ;
unsigned char * V_16 ;
int V_72 ;
void * V_73 , * V_74 ;
int V_75 ;
int V_1 ;
T_3 V_25 = V_29 -> V_43 -> V_25 ;
int V_76 ;
T_1 * V_42 ;
F_11 ( L_2 ) ;
V_16 = ( T_1 * ) V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
if ( F_28 ( & V_29 -> V_46 , & V_72 , & V_16 ,
V_4 -> V_7 - V_5 ) )
return V_77 ;
if ( ( V_16 [ 0 ] != ( ( V_49 >> 8 ) & 0xff ) ) ||
( V_16 [ 1 ] != ( V_49 & 0xff ) ) )
return V_77 ;
V_51 = V_16 [ 2 ] + ( V_16 [ 3 ] << 8 ) ;
if ( V_51 != V_29 -> V_43 -> V_51 )
return V_77 ;
V_52 = V_16 [ 4 ] + ( V_16 [ 5 ] << 8 ) ;
if ( V_52 != V_29 -> V_43 -> V_52 )
return V_77 ;
if ( ( V_16 [ 6 ] != 0xff ) || ( V_16 [ 7 ] != 0xff ) )
return V_77 ;
V_76 = V_16 + ( V_47 + V_29 -> V_43 -> V_48 ) -
( unsigned char * ) V_4 -> V_14 [ 0 ] . V_15 ;
if ( F_29 ( V_29 , V_16 + V_47 ,
V_16 + 8 , & V_70 , & V_71 ) )
return V_78 ;
if ( ( V_29 -> V_59 && V_70 != 0xff ) ||
( ! V_29 -> V_59 && V_70 != 0 ) )
return V_78 ;
if ( V_29 -> V_60 == V_61 ) {
struct V_62 * V_63 ;
int V_64 ;
V_63 = F_22 ( V_29 -> V_43 -> V_65 , 0 ,
V_66 ) ;
if ( F_23 ( V_63 ) )
return V_56 ;
F_24 ( V_29 , V_63 , V_71 ) ;
V_64 = F_30 ( V_63 , V_4 , V_76 ) ;
F_26 ( V_63 ) ;
if ( V_64 )
return V_77 ;
} else {
if ( F_30 ( V_29 -> V_45 , V_4 , V_76 ) )
return V_77 ;
}
if ( V_29 -> V_43 -> V_53 )
V_42 = V_29 -> V_54 ;
else
V_42 = NULL ;
if ( F_18 ( V_29 , V_16 , 8 , V_4 , V_76 ,
V_42 , V_55 , & V_34 ) )
return V_56 ;
if ( memcmp ( V_34 . V_35 , V_16 + V_47 ,
V_29 -> V_43 -> V_48 ) )
return V_78 ;
V_38 = F_12 () ;
if ( V_38 > V_29 -> V_67 )
return V_68 ;
V_1 = F_13 ( V_29 -> V_45 ) ;
V_73 = V_16 + ( V_47 + V_29 -> V_43 -> V_48 ) +
V_25 ;
V_74 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
V_75 = ( V_4 -> V_14 [ 0 ] . V_15 + V_4 -> V_14 [ 0 ] . V_13 ) - V_73 ;
memmove ( V_74 , V_73 , V_75 ) ;
V_4 -> V_14 [ 0 ] . V_13 -= ( V_73 - V_74 ) ;
V_4 -> V_7 -= ( V_73 - V_74 ) ;
if ( F_3 ( V_4 , V_1 ) )
return V_77 ;
return V_69 ;
}
static void F_31 ( struct V_3 * V_4 , unsigned int V_79 )
{
char V_14 [ V_80 ] ;
char V_81 [ V_80 ] ;
unsigned int V_82 , V_26 ;
F_6 ( V_79 > V_80 ) ;
F_32 ( V_4 , 0 , V_14 , V_79 ) ;
for ( V_26 = 0 ; V_26 + V_79 < V_4 -> V_7 ; V_26 += V_80 ) {
V_82 = F_33 ( V_80 , V_4 -> V_7 - ( V_26 + V_79 ) ) ;
F_32 ( V_4 , V_26 + V_79 , V_81 , V_82 ) ;
F_34 ( V_4 , V_26 , V_81 , V_82 ) ;
}
F_34 ( V_4 , V_4 -> V_7 - V_79 , V_14 , V_79 ) ;
}
static void F_35 ( struct V_3 * V_4 , unsigned int V_79 )
{
int V_83 = 0 ;
int V_84 ;
V_79 %= V_4 -> V_7 ;
while ( V_83 < V_79 ) {
V_84 = F_33 ( V_79 - V_83 , V_80 ) ;
F_31 ( V_4 , V_84 ) ;
V_83 += V_84 ;
}
}
static void F_36 ( T_3 V_85 , struct V_3 * V_4 , unsigned int V_79 )
{
struct V_3 V_86 ;
F_37 ( V_4 , & V_86 , V_85 , V_4 -> V_7 - V_85 ) ;
F_35 ( & V_86 , V_79 ) ;
}
static T_3
F_38 ( struct V_28 * V_29 , T_3 V_5 ,
struct V_3 * V_4 , struct V_30 * * V_24 )
{
int V_1 ;
T_1 * V_16 , * V_87 ;
T_5 V_38 ;
T_1 V_88 = 0x00 ;
T_6 * V_89 ;
T_7 * V_90 ;
T_3 V_64 ;
F_11 ( L_1 , V_44 ) ;
if ( V_29 -> V_43 -> V_91 == NULL )
return V_56 ;
if ( F_15 ( V_4 , V_5 , V_47 ) )
return V_56 ;
V_16 = V_87 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
* V_16 ++ = ( unsigned char ) ( ( V_92 >> 8 ) & 0xff ) ;
* V_16 ++ = ( unsigned char ) ( V_92 & 0xff ) ;
if ( ( V_29 -> V_88 & V_93 ) == 0 )
V_88 |= V_94 ;
if ( ( V_29 -> V_88 & V_95 ) != 0 )
V_88 |= V_96 ;
V_88 |= V_97 ;
* V_16 ++ = V_88 ;
* V_16 ++ = 0xff ;
V_89 = ( T_6 * ) V_16 ;
V_1 = F_13 ( V_29 -> V_98 ) ;
* V_89 ++ = 0 ;
* V_89 ++ = 0 ;
V_90 = ( T_7 * ) V_89 ;
F_19 ( & V_57 ) ;
* V_90 = F_39 ( V_29 -> V_99 ++ ) ;
F_20 ( & V_57 ) ;
V_64 = (* V_29 -> V_43 -> V_91 )( V_29 , V_5 , V_4 , V_24 ) ;
if ( V_64 )
return V_64 ;
V_38 = F_12 () ;
return ( V_29 -> V_67 < V_38 ) ? V_68 : V_69 ;
}
static T_3
F_40 ( struct V_28 * V_29 , int V_5 , struct V_3 * V_4 )
{
T_5 V_38 ;
T_1 * V_16 ;
T_1 V_88 = 0x00 ;
T_8 V_100 , V_101 ;
int V_64 ;
T_3 V_102 , V_103 ;
T_1 V_104 [ V_47 ] ;
unsigned int V_105 ;
F_11 ( L_1 , V_44 ) ;
if ( V_29 -> V_43 -> V_106 == NULL )
return V_56 ;
V_16 = V_4 -> V_14 [ 0 ] . V_15 + V_5 ;
if ( F_41 ( * ( ( T_6 * ) V_16 ) ) != V_92 )
return V_77 ;
V_88 = V_16 [ 2 ] ;
if ( ( ! V_29 -> V_59 && ( V_88 & V_94 ) ) ||
( V_29 -> V_59 && ! ( V_88 & V_94 ) ) )
return V_78 ;
if ( ( V_88 & V_97 ) == 0 ) {
F_11 ( L_3 , V_44 ) ;
return V_77 ;
}
if ( V_16 [ 3 ] != 0xff )
return V_77 ;
V_100 = F_42 ( ( T_6 * ) ( V_16 + 4 ) ) ;
V_101 = F_42 ( ( T_6 * ) ( V_16 + 6 ) ) ;
if ( V_101 != 0 )
F_36 ( V_5 + 16 , V_4 , V_101 ) ;
V_64 = (* V_29 -> V_43 -> V_106 )( V_29 , V_5 , V_4 ,
& V_102 , & V_103 ) ;
if ( V_64 )
return V_56 ;
V_64 = F_32 ( V_4 ,
V_4 -> V_7 - V_47 - V_103 ,
V_104 , V_47 ) ;
if ( V_64 ) {
F_11 ( L_4 , V_44 , V_64 ) ;
return V_56 ;
}
if ( memcmp ( V_16 , V_104 , 6 )
|| memcmp ( V_16 + 8 , V_104 + 8 , 8 ) ) {
F_11 ( L_5 , V_44 ) ;
return V_56 ;
}
V_38 = F_12 () ;
if ( V_38 > V_29 -> V_67 )
return V_68 ;
V_105 = F_43 (unsigned int, buf->head[0].iov_len, buf->len) ;
V_105 -= V_5 + V_47 + V_102 ;
F_6 ( V_5 + V_47 + V_102 + V_105 >
V_4 -> V_14 [ 0 ] . V_13 ) ;
memmove ( V_16 , V_16 + V_47 + V_102 , V_105 ) ;
V_4 -> V_14 [ 0 ] . V_13 -= V_47 + V_102 ;
V_4 -> V_7 -= V_47 + V_102 ;
F_44 ( V_4 , V_100 + V_47 + V_103 ) ;
return V_69 ;
}
T_3
F_45 ( struct V_107 * V_108 , int V_5 ,
struct V_3 * V_4 , struct V_30 * * V_24 )
{
struct V_28 * V_29 = V_108 -> V_109 ;
switch ( V_29 -> V_60 ) {
default:
F_9 () ;
case V_110 :
case V_111 :
case V_61 :
return F_10 ( V_29 , V_5 , V_4 , V_24 ) ;
case V_112 :
case V_113 :
return F_38 ( V_29 , V_5 , V_4 , V_24 ) ;
}
}
T_3
F_46 ( struct V_107 * V_108 , int V_5 , struct V_3 * V_4 )
{
struct V_28 * V_29 = V_108 -> V_109 ;
switch ( V_29 -> V_60 ) {
default:
F_9 () ;
case V_110 :
case V_111 :
case V_61 :
return F_27 ( V_29 , V_5 , V_4 ) ;
case V_112 :
case V_113 :
return F_40 ( V_29 , V_5 , V_4 ) ;
}
}
