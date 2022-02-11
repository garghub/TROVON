struct V_1 *
F_1 ( int V_2 , int V_3 )
{
register short V_4 ;
register struct V_5 * V_6 ;
struct V_1 * V_7 ;
V_7 = F_2 ( sizeof( struct V_1 ) , V_8 ) ;
if ( ! V_7 )
goto V_9;
if ( V_2 > 0 && V_2 < 256 ) {
T_1 V_10 = V_2 * sizeof( struct V_5 ) ;
V_7 -> V_11 = F_2 ( V_10 , V_8 ) ;
if ( ! V_7 -> V_11 )
goto V_12;
V_7 -> V_13 = V_2 - 1 ;
}
if ( V_3 > 0 && V_3 < 256 ) {
T_1 V_14 = V_3 * sizeof( struct V_5 ) ;
V_7 -> V_15 = F_2 ( V_14 , V_8 ) ;
if ( ! V_7 -> V_15 )
goto V_16;
V_7 -> V_17 = V_3 - 1 ;
}
V_7 -> V_18 = 0 ;
V_7 -> V_19 = 255 ;
V_7 -> V_20 = 255 ;
V_7 -> V_21 |= V_22 ;
if ( V_3 > 0 ) {
V_6 = V_7 -> V_15 ;
for( V_4 = V_7 -> V_17 ; V_4 > 0 ; -- V_4 ) {
V_6 [ V_4 ] . V_23 = V_4 ;
V_6 [ V_4 ] . V_24 = & ( V_6 [ V_4 - 1 ] ) ;
}
V_6 [ 0 ] . V_24 = & ( V_6 [ V_7 -> V_17 ] ) ;
V_6 [ 0 ] . V_23 = 0 ;
}
return V_7 ;
V_16:
F_3 ( V_7 -> V_11 ) ;
V_12:
F_3 ( V_7 ) ;
V_9:
return NULL ;
}
void
F_4 ( struct V_1 * V_7 )
{
if ( V_7 == V_25 )
return;
if ( V_7 -> V_15 != V_26 )
F_3 ( V_7 -> V_15 ) ;
if ( V_7 -> V_11 != V_26 )
F_3 ( V_7 -> V_11 ) ;
F_3 ( V_7 ) ;
}
static inline unsigned char *
F_5 ( unsigned char * V_27 , unsigned short V_28 )
{
* V_27 ++ = V_28 >> 8 ;
* V_27 ++ = V_28 ;
return V_27 ;
}
static unsigned char *
F_6 ( unsigned char * V_27 , unsigned short V_29 )
{
if( V_29 >= 256 || V_29 == 0 ) {
* V_27 ++ = 0 ;
V_27 = F_5 ( V_27 , V_29 ) ;
} else {
* V_27 ++ = V_29 ;
}
return V_27 ;
}
static unsigned short
F_7 ( unsigned char * * V_30 )
{
short V_31 ;
V_31 = * ( * V_30 ) ++ ;
V_31 <<= 8 ;
V_31 |= * ( * V_30 ) ++ ;
return V_31 ;
}
static long
F_8 ( unsigned char * * V_30 )
{
register int V_28 ;
V_28 = * ( * V_30 ) ++ ;
if( V_28 == 0 ) {
return F_7 ( V_30 ) & 0xffff ;
} else {
return V_28 & 0xff ;
}
}
int
F_9 ( struct V_1 * V_7 , unsigned char * V_32 , int V_33 ,
unsigned char * V_34 , unsigned char * * V_30 , int V_35 )
{
register struct V_5 * V_36 = & ( V_7 -> V_15 [ V_7 -> V_18 ] ) ;
register struct V_5 * V_37 = V_36 ;
register struct V_5 * V_38 = V_37 -> V_24 ;
register unsigned long V_39 , V_40 ;
register short V_41 = 0 ;
int V_42 ;
unsigned char V_43 [ 16 ] ;
register unsigned char * V_27 = V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 , * V_48 ;
T_2 V_49 ;
if( V_33 < sizeof( struct V_44 ) )
return V_33 ;
V_45 = (struct V_44 * ) V_32 ;
if ( V_45 -> V_50 != V_51 || ( F_10 ( V_45 -> V_52 ) & 0x3fff ) ) {
if( V_45 -> V_50 != V_51 )
V_7 -> V_53 ++ ;
else
V_7 -> V_54 ++ ;
return V_33 ;
}
V_47 = (struct V_46 * ) ( ( ( unsigned char * ) V_45 ) + V_45 -> V_55 * 4 ) ;
V_42 = V_45 -> V_55 * 4 + V_47 -> V_56 * 4 ;
if( V_42 > V_33 || V_47 -> V_57 || V_47 -> V_58 || V_47 -> V_59 ||
! ( V_47 -> V_60 ) ) {
V_7 -> V_54 ++ ;
return V_33 ;
}
for ( ; ; ) {
if( V_45 -> V_61 == V_38 -> V_62 . V_61
&& V_45 -> V_63 == V_38 -> V_62 . V_63
&& V_47 -> V_64 == V_38 -> V_65 . V_64
&& V_47 -> V_66 == V_38 -> V_65 . V_66 )
goto V_67;
if ( V_38 == V_36 )
break;
V_37 = V_38 ;
V_38 = V_38 -> V_24 ;
V_7 -> V_68 ++ ;
}
V_7 -> V_69 ++ ;
V_7 -> V_18 = V_37 -> V_23 ;
goto V_70;
V_67:
if( V_37 == V_36 ) {
} else if ( V_38 == V_36 ) {
V_7 -> V_18 = V_37 -> V_23 ;
} else {
V_37 -> V_24 = V_38 -> V_24 ;
V_38 -> V_24 = V_36 -> V_24 ;
V_36 -> V_24 = V_38 ;
}
V_48 = & V_38 -> V_65 ;
if( V_45 -> V_71 != V_38 -> V_62 . V_71 || V_45 -> V_55 != V_38 -> V_62 . V_55
|| V_45 -> V_72 != V_38 -> V_62 . V_72
|| ( V_45 -> V_52 & F_11 ( 0x4000 ) ) != ( V_38 -> V_62 . V_52 & F_11 ( 0x4000 ) )
|| V_45 -> V_73 != V_38 -> V_62 . V_73
|| V_47 -> V_56 != V_38 -> V_65 . V_56
|| ( V_45 -> V_55 > 5 && memcmp ( V_45 + 1 , V_38 -> V_74 , ( ( V_45 -> V_55 ) - 5 ) * 4 ) != 0 )
|| ( V_47 -> V_56 > 5 && memcmp ( V_47 + 1 , V_38 -> V_75 , ( ( V_47 -> V_56 ) - 5 ) * 4 ) != 0 ) ) {
goto V_70;
}
if( V_47 -> V_76 ) {
V_39 = F_10 ( V_47 -> V_77 ) ;
V_27 = F_6 ( V_27 , V_39 ) ;
V_41 |= V_78 ;
} else if( V_47 -> V_77 != V_48 -> V_77 ) {
goto V_70;
}
if( ( V_39 = F_10 ( V_47 -> V_79 ) - F_10 ( V_48 -> V_79 ) ) != 0 ) {
V_27 = F_6 ( V_27 , V_39 ) ;
V_41 |= V_80 ;
}
if( ( V_40 = F_12 ( V_47 -> V_81 ) - F_12 ( V_48 -> V_81 ) ) != 0L ) {
if( V_40 > 0x0000ffff )
goto V_70;
V_27 = F_6 ( V_27 , V_40 ) ;
V_41 |= V_82 ;
}
if( ( V_39 = F_12 ( V_47 -> V_83 ) - F_12 ( V_48 -> V_83 ) ) != 0L ) {
if( V_39 > 0x0000ffff )
goto V_70;
V_27 = F_6 ( V_27 , V_39 ) ;
V_41 |= V_84 ;
}
switch( V_41 ) {
case 0 :
if( V_45 -> V_85 != V_38 -> V_62 . V_85 &&
F_10 ( V_38 -> V_62 . V_85 ) == V_42 )
break;
goto V_70;
case V_86 :
case V_87 :
goto V_70;
case V_84 | V_82 :
if( V_39 == V_40 &&
V_39 == F_10 ( V_38 -> V_62 . V_85 ) - V_42 ) {
V_41 = V_86 ;
V_27 = V_43 ;
}
break;
case V_84 :
if( V_39 == F_10 ( V_38 -> V_62 . V_85 ) - V_42 ) {
V_41 = V_87 ;
V_27 = V_43 ;
}
break;
}
V_39 = F_10 ( V_45 -> V_88 ) - F_10 ( V_38 -> V_62 . V_88 ) ;
if( V_39 != 1 ) {
V_27 = F_6 ( V_27 , V_39 ) ;
V_41 |= V_89 ;
}
if( V_47 -> V_90 )
V_41 |= V_91 ;
V_49 = V_47 -> V_92 ;
memcpy ( & V_38 -> V_62 , V_45 , 20 ) ;
memcpy ( & V_38 -> V_65 , V_47 , 20 ) ;
V_39 = V_27 - V_43 ;
if( V_35 == 0 || V_7 -> V_19 != V_38 -> V_23 ) {
V_27 = V_34 ;
* V_30 = V_34 ;
* V_27 ++ = V_41 | V_93 ;
* V_27 ++ = V_38 -> V_23 ;
V_7 -> V_19 = V_38 -> V_23 ;
} else {
V_27 = V_34 ;
* V_30 = V_34 ;
* V_27 ++ = V_41 ;
}
* ( T_2 * ) V_27 = V_49 ;
V_27 += 2 ;
memcpy ( V_27 , V_43 , V_39 ) ;
memcpy ( V_27 + V_39 , V_32 + V_42 , V_33 - V_42 ) ;
V_7 -> V_94 ++ ;
V_34 [ 0 ] |= V_95 ;
return V_33 - V_42 + V_39 + ( V_27 - V_34 ) ;
V_70:
memcpy ( & V_38 -> V_62 , V_45 , 20 ) ;
memcpy ( & V_38 -> V_65 , V_47 , 20 ) ;
if ( V_45 -> V_55 > 5 )
memcpy ( V_38 -> V_74 , V_45 + 1 , ( ( V_45 -> V_55 ) - 5 ) * 4 ) ;
if ( V_47 -> V_56 > 5 )
memcpy ( V_38 -> V_75 , V_47 + 1 , ( ( V_47 -> V_56 ) - 5 ) * 4 ) ;
V_7 -> V_19 = V_38 -> V_23 ;
V_7 -> V_96 ++ ;
memcpy ( V_34 , V_32 , V_33 ) ;
* V_30 = V_34 ;
V_34 [ 9 ] = V_38 -> V_23 ;
V_34 [ 0 ] |= V_97 ;
return V_33 ;
}
int
F_13 ( struct V_1 * V_7 , unsigned char * V_32 , int V_33 )
{
register int V_41 ;
long V_28 ;
register struct V_46 * V_98 ;
register struct V_44 * V_45 ;
register struct V_5 * V_38 ;
int V_99 , V_100 ;
unsigned char * V_27 = V_32 ;
V_7 -> V_101 ++ ;
if( V_33 < 3 ) {
V_7 -> V_102 ++ ;
return 0 ;
}
V_41 = * V_27 ++ ;
if( V_41 & V_93 ) {
V_28 = * V_27 ++ ;
if( V_28 < 0 || V_28 > V_7 -> V_13 )
goto V_103;
V_7 -> V_21 &= ~ V_22 ;
V_7 -> V_20 = V_28 ;
} else {
if( V_7 -> V_21 & V_22 ) {
V_7 -> V_104 ++ ;
return 0 ;
}
}
V_38 = & V_7 -> V_11 [ V_7 -> V_20 ] ;
V_98 = & V_38 -> V_65 ;
V_45 = & V_38 -> V_62 ;
V_98 -> V_92 = * ( T_2 * ) V_27 ;
V_27 += 2 ;
V_98 -> V_90 = ( V_41 & V_91 ) ? 1 : 0 ;
V_100 = V_45 -> V_55 * 4 + V_98 -> V_56 * 4 ;
switch( V_41 & V_105 ) {
case V_86 :
{
register short V_4 ;
V_4 = F_10 ( V_45 -> V_85 ) - V_100 ;
V_98 -> V_81 = F_14 ( F_12 ( V_98 -> V_81 ) + V_4 ) ;
V_98 -> V_83 = F_14 ( F_12 ( V_98 -> V_83 ) + V_4 ) ;
}
break;
case V_87 :
V_98 -> V_83 = F_14 ( F_12 ( V_98 -> V_83 ) +
F_10 ( V_45 -> V_85 ) - V_100 ) ;
break;
default:
if( V_41 & V_78 ) {
V_98 -> V_76 = 1 ;
if( ( V_28 = F_8 ( & V_27 ) ) == - 1 ) {
goto V_103;
}
V_98 -> V_77 = F_11 ( V_28 ) ;
} else
V_98 -> V_76 = 0 ;
if( V_41 & V_80 ) {
if( ( V_28 = F_8 ( & V_27 ) ) == - 1 ) {
goto V_103;
}
V_98 -> V_79 = F_11 ( F_10 ( V_98 -> V_79 ) + V_28 ) ;
}
if( V_41 & V_82 ) {
if( ( V_28 = F_8 ( & V_27 ) ) == - 1 ) {
goto V_103;
}
V_98 -> V_81 = F_14 ( F_12 ( V_98 -> V_81 ) + V_28 ) ;
}
if( V_41 & V_84 ) {
if( ( V_28 = F_8 ( & V_27 ) ) == - 1 ) {
goto V_103;
}
V_98 -> V_83 = F_14 ( F_12 ( V_98 -> V_83 ) + V_28 ) ;
}
break;
}
if( V_41 & V_89 ) {
if( ( V_28 = F_8 ( & V_27 ) ) == - 1 ) {
goto V_103;
}
V_45 -> V_88 = F_11 ( F_10 ( V_45 -> V_88 ) + V_28 ) ;
} else
V_45 -> V_88 = F_11 ( F_10 ( V_45 -> V_88 ) + 1 ) ;
V_99 = V_33 - ( V_27 - V_32 ) ;
if ( V_99 < 0 )
goto V_103;
V_99 += V_100 ;
V_45 -> V_85 = F_11 ( V_99 ) ;
V_45 -> V_92 = 0 ;
memmove ( V_32 + V_100 , V_27 , V_99 - V_100 ) ;
V_27 = V_32 ;
memcpy ( V_27 , V_45 , 20 ) ;
V_27 += 20 ;
if ( V_45 -> V_55 > 5 ) {
memcpy ( V_27 , V_38 -> V_74 , ( V_45 -> V_55 - 5 ) * 4 ) ;
V_27 += ( V_45 -> V_55 - 5 ) * 4 ;
}
F_15 ( F_16 ( V_32 , V_45 -> V_55 ) ,
& ( (struct V_44 * ) V_32 ) -> V_92 ) ;
memcpy ( V_27 , V_98 , 20 ) ;
V_27 += 20 ;
if ( V_98 -> V_56 > 5 ) {
memcpy ( V_27 , V_38 -> V_75 , ( ( V_98 -> V_56 ) - 5 ) * 4 ) ;
V_27 += ( ( V_98 -> V_56 ) - 5 ) * 4 ;
}
return V_99 ;
V_103:
V_7 -> V_102 ++ ;
return F_17 ( V_7 ) ;
}
int
F_18 ( struct V_1 * V_7 , unsigned char * V_32 , int V_33 )
{
register struct V_5 * V_38 ;
unsigned V_55 ;
unsigned char V_106 ;
if( V_33 < 20 ) {
V_7 -> V_107 ++ ;
return F_17 ( V_7 ) ;
}
V_55 = V_32 [ 0 ] & 0xf ;
if( V_55 < 20 / 4 ) {
V_7 -> V_107 ++ ;
return F_17 ( V_7 ) ;
}
V_106 = V_32 [ 9 ] ;
V_32 [ 9 ] = V_51 ;
if ( F_16 ( V_32 , V_55 ) ) {
V_7 -> V_108 ++ ;
return F_17 ( V_7 ) ;
}
if( V_106 > V_7 -> V_13 ) {
V_7 -> V_102 ++ ;
return F_17 ( V_7 ) ;
}
V_38 = & V_7 -> V_11 [ V_7 -> V_20 = V_106 ] ;
V_7 -> V_21 &= ~ V_22 ;
memcpy ( & V_38 -> V_62 , V_32 , 20 ) ;
memcpy ( & V_38 -> V_65 , V_32 + V_55 * 4 , 20 ) ;
if ( V_55 > 5 )
memcpy ( V_38 -> V_74 , V_32 + sizeof( struct V_44 ) , ( V_55 - 5 ) * 4 ) ;
if ( V_38 -> V_65 . V_56 > 5 )
memcpy ( V_38 -> V_75 , V_32 + V_55 * 4 + sizeof( struct V_46 ) , ( V_38 -> V_65 . V_56 - 5 ) * 4 ) ;
V_38 -> V_109 = V_55 * 2 + V_38 -> V_65 . V_56 * 2 ;
V_7 -> V_110 ++ ;
return V_33 ;
}
int
F_17 ( struct V_1 * V_7 )
{
if ( V_7 == V_25 )
return 0 ;
V_7 -> V_21 |= V_22 ;
return 0 ;
}
int
F_17 ( struct V_1 * V_7 )
{
F_19 ( V_111 L_1 ) ;
return - V_112 ;
}
int
F_13 ( struct V_1 * V_7 , unsigned char * V_32 , int V_33 )
{
F_19 ( V_111 L_2 ) ;
return - V_112 ;
}
int
F_9 ( struct V_1 * V_7 , unsigned char * V_32 , int V_33 ,
unsigned char * V_34 , unsigned char * * V_30 , int V_35 )
{
F_19 ( V_111 L_3 ) ;
return - V_112 ;
}
int
F_18 ( struct V_1 * V_7 , unsigned char * V_32 , int V_33 )
{
F_19 ( V_111 L_4 ) ;
return - V_112 ;
}
void
F_4 ( struct V_1 * V_7 )
{
F_19 ( V_111 L_5 ) ;
}
struct V_1 *
F_1 ( int V_2 , int V_3 )
{
F_19 ( V_111 L_6 ) ;
return NULL ;
}
