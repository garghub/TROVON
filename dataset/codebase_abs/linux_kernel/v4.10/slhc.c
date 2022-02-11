struct V_1 *
F_1 ( int V_2 , int V_3 )
{
register short V_4 ;
register struct V_5 * V_6 ;
struct V_1 * V_7 ;
if ( V_2 < 0 || V_2 > 255 || V_3 < 0 || V_3 > 255 )
return F_2 ( - V_8 ) ;
V_7 = F_3 ( sizeof( struct V_1 ) , V_9 ) ;
if ( ! V_7 )
goto V_10;
if ( V_2 > 0 ) {
T_1 V_11 = V_2 * sizeof( struct V_5 ) ;
V_7 -> V_12 = F_3 ( V_11 , V_9 ) ;
if ( ! V_7 -> V_12 )
goto V_13;
V_7 -> V_14 = V_2 - 1 ;
}
if ( V_3 > 0 ) {
T_1 V_15 = V_3 * sizeof( struct V_5 ) ;
V_7 -> V_16 = F_3 ( V_15 , V_9 ) ;
if ( ! V_7 -> V_16 )
goto V_17;
V_7 -> V_18 = V_3 - 1 ;
}
V_7 -> V_19 = 0 ;
V_7 -> V_20 = 255 ;
V_7 -> V_21 = 255 ;
V_7 -> V_22 |= V_23 ;
if ( V_3 > 0 ) {
V_6 = V_7 -> V_16 ;
for( V_4 = V_7 -> V_18 ; V_4 > 0 ; -- V_4 ) {
V_6 [ V_4 ] . V_24 = V_4 ;
V_6 [ V_4 ] . V_25 = & ( V_6 [ V_4 - 1 ] ) ;
}
V_6 [ 0 ] . V_25 = & ( V_6 [ V_7 -> V_18 ] ) ;
V_6 [ 0 ] . V_24 = 0 ;
}
return V_7 ;
V_17:
F_4 ( V_7 -> V_12 ) ;
V_13:
F_4 ( V_7 ) ;
V_10:
return F_2 ( - V_26 ) ;
}
void
F_5 ( struct V_1 * V_7 )
{
if ( V_7 == V_27 )
return;
if ( V_7 -> V_16 != V_28 )
F_4 ( V_7 -> V_16 ) ;
if ( V_7 -> V_12 != V_28 )
F_4 ( V_7 -> V_12 ) ;
F_4 ( V_7 ) ;
}
static inline unsigned char *
F_6 ( unsigned char * V_29 , unsigned short V_30 )
{
* V_29 ++ = V_30 >> 8 ;
* V_29 ++ = V_30 ;
return V_29 ;
}
static unsigned char *
F_7 ( unsigned char * V_29 , unsigned short V_31 )
{
if( V_31 >= 256 || V_31 == 0 ) {
* V_29 ++ = 0 ;
V_29 = F_6 ( V_29 , V_31 ) ;
} else {
* V_29 ++ = V_31 ;
}
return V_29 ;
}
static unsigned short
F_8 ( unsigned char * * V_32 )
{
short V_33 ;
V_33 = * ( * V_32 ) ++ ;
V_33 <<= 8 ;
V_33 |= * ( * V_32 ) ++ ;
return V_33 ;
}
static long
F_9 ( unsigned char * * V_32 )
{
register int V_30 ;
V_30 = * ( * V_32 ) ++ ;
if( V_30 == 0 ) {
return F_8 ( V_32 ) & 0xffff ;
} else {
return V_30 & 0xff ;
}
}
int
F_10 ( struct V_1 * V_7 , unsigned char * V_34 , int V_35 ,
unsigned char * V_36 , unsigned char * * V_32 , int V_37 )
{
register struct V_5 * V_38 = & ( V_7 -> V_16 [ V_7 -> V_19 ] ) ;
register struct V_5 * V_39 = V_38 ;
register struct V_5 * V_40 = V_39 -> V_25 ;
register unsigned long V_41 , V_42 ;
register short V_43 = 0 ;
int V_44 ;
unsigned char V_45 [ 16 ] ;
register unsigned char * V_29 = V_45 ;
struct V_46 * V_47 ;
struct V_48 * V_49 , * V_50 ;
T_2 V_51 ;
if( V_35 < sizeof( struct V_46 ) )
return V_35 ;
V_47 = (struct V_46 * ) V_34 ;
if ( V_47 -> V_52 != V_53 || ( F_11 ( V_47 -> V_54 ) & 0x3fff ) ) {
if( V_47 -> V_52 != V_53 )
V_7 -> V_55 ++ ;
else
V_7 -> V_56 ++ ;
return V_35 ;
}
V_49 = (struct V_48 * ) ( ( ( unsigned char * ) V_47 ) + V_47 -> V_57 * 4 ) ;
V_44 = V_47 -> V_57 * 4 + V_49 -> V_58 * 4 ;
if( V_44 > V_35 || V_49 -> V_59 || V_49 -> V_60 || V_49 -> V_61 ||
! ( V_49 -> V_62 ) ) {
V_7 -> V_56 ++ ;
return V_35 ;
}
for ( ; ; ) {
if( V_47 -> V_63 == V_40 -> V_64 . V_63
&& V_47 -> V_65 == V_40 -> V_64 . V_65
&& V_49 -> V_66 == V_40 -> V_67 . V_66
&& V_49 -> V_68 == V_40 -> V_67 . V_68 )
goto V_69;
if ( V_40 == V_38 )
break;
V_39 = V_40 ;
V_40 = V_40 -> V_25 ;
V_7 -> V_70 ++ ;
}
V_7 -> V_71 ++ ;
V_7 -> V_19 = V_39 -> V_24 ;
goto V_72;
V_69:
if( V_39 == V_38 ) {
} else if ( V_40 == V_38 ) {
V_7 -> V_19 = V_39 -> V_24 ;
} else {
V_39 -> V_25 = V_40 -> V_25 ;
V_40 -> V_25 = V_38 -> V_25 ;
V_38 -> V_25 = V_40 ;
}
V_50 = & V_40 -> V_67 ;
if( V_47 -> V_73 != V_40 -> V_64 . V_73 || V_47 -> V_57 != V_40 -> V_64 . V_57
|| V_47 -> V_74 != V_40 -> V_64 . V_74
|| ( V_47 -> V_54 & F_12 ( 0x4000 ) ) != ( V_40 -> V_64 . V_54 & F_12 ( 0x4000 ) )
|| V_47 -> V_75 != V_40 -> V_64 . V_75
|| V_49 -> V_58 != V_40 -> V_67 . V_58
|| ( V_47 -> V_57 > 5 && memcmp ( V_47 + 1 , V_40 -> V_76 , ( ( V_47 -> V_57 ) - 5 ) * 4 ) != 0 )
|| ( V_49 -> V_58 > 5 && memcmp ( V_49 + 1 , V_40 -> V_77 , ( ( V_49 -> V_58 ) - 5 ) * 4 ) != 0 ) ) {
goto V_72;
}
if( V_49 -> V_78 ) {
V_41 = F_11 ( V_49 -> V_79 ) ;
V_29 = F_7 ( V_29 , V_41 ) ;
V_43 |= V_80 ;
} else if( V_49 -> V_79 != V_50 -> V_79 ) {
goto V_72;
}
if( ( V_41 = F_11 ( V_49 -> V_81 ) - F_11 ( V_50 -> V_81 ) ) != 0 ) {
V_29 = F_7 ( V_29 , V_41 ) ;
V_43 |= V_82 ;
}
if( ( V_42 = F_13 ( V_49 -> V_83 ) - F_13 ( V_50 -> V_83 ) ) != 0L ) {
if( V_42 > 0x0000ffff )
goto V_72;
V_29 = F_7 ( V_29 , V_42 ) ;
V_43 |= V_84 ;
}
if( ( V_41 = F_13 ( V_49 -> V_85 ) - F_13 ( V_50 -> V_85 ) ) != 0L ) {
if( V_41 > 0x0000ffff )
goto V_72;
V_29 = F_7 ( V_29 , V_41 ) ;
V_43 |= V_86 ;
}
switch( V_43 ) {
case 0 :
if( V_47 -> V_87 != V_40 -> V_64 . V_87 &&
F_11 ( V_40 -> V_64 . V_87 ) == V_44 )
break;
goto V_72;
case V_88 :
case V_89 :
goto V_72;
case V_86 | V_84 :
if( V_41 == V_42 &&
V_41 == F_11 ( V_40 -> V_64 . V_87 ) - V_44 ) {
V_43 = V_88 ;
V_29 = V_45 ;
}
break;
case V_86 :
if( V_41 == F_11 ( V_40 -> V_64 . V_87 ) - V_44 ) {
V_43 = V_89 ;
V_29 = V_45 ;
}
break;
}
V_41 = F_11 ( V_47 -> V_90 ) - F_11 ( V_40 -> V_64 . V_90 ) ;
if( V_41 != 1 ) {
V_29 = F_7 ( V_29 , V_41 ) ;
V_43 |= V_91 ;
}
if( V_49 -> V_92 )
V_43 |= V_93 ;
V_51 = V_49 -> V_94 ;
memcpy ( & V_40 -> V_64 , V_47 , 20 ) ;
memcpy ( & V_40 -> V_67 , V_49 , 20 ) ;
V_41 = V_29 - V_45 ;
if( V_37 == 0 || V_7 -> V_20 != V_40 -> V_24 ) {
V_29 = V_36 ;
* V_32 = V_36 ;
* V_29 ++ = V_43 | V_95 ;
* V_29 ++ = V_40 -> V_24 ;
V_7 -> V_20 = V_40 -> V_24 ;
} else {
V_29 = V_36 ;
* V_32 = V_36 ;
* V_29 ++ = V_43 ;
}
* ( T_2 * ) V_29 = V_51 ;
V_29 += 2 ;
memcpy ( V_29 , V_45 , V_41 ) ;
memcpy ( V_29 + V_41 , V_34 + V_44 , V_35 - V_44 ) ;
V_7 -> V_96 ++ ;
V_36 [ 0 ] |= V_97 ;
return V_35 - V_44 + V_41 + ( V_29 - V_36 ) ;
V_72:
memcpy ( & V_40 -> V_64 , V_47 , 20 ) ;
memcpy ( & V_40 -> V_67 , V_49 , 20 ) ;
if ( V_47 -> V_57 > 5 )
memcpy ( V_40 -> V_76 , V_47 + 1 , ( ( V_47 -> V_57 ) - 5 ) * 4 ) ;
if ( V_49 -> V_58 > 5 )
memcpy ( V_40 -> V_77 , V_49 + 1 , ( ( V_49 -> V_58 ) - 5 ) * 4 ) ;
V_7 -> V_20 = V_40 -> V_24 ;
V_7 -> V_98 ++ ;
memcpy ( V_36 , V_34 , V_35 ) ;
* V_32 = V_36 ;
V_36 [ 9 ] = V_40 -> V_24 ;
V_36 [ 0 ] |= V_99 ;
return V_35 ;
}
int
F_14 ( struct V_1 * V_7 , unsigned char * V_34 , int V_35 )
{
register int V_43 ;
long V_30 ;
register struct V_48 * V_100 ;
register struct V_46 * V_47 ;
register struct V_5 * V_40 ;
int V_101 , V_102 ;
unsigned char * V_29 = V_34 ;
V_7 -> V_103 ++ ;
if( V_35 < 3 ) {
V_7 -> V_104 ++ ;
return 0 ;
}
V_43 = * V_29 ++ ;
if( V_43 & V_95 ) {
V_30 = * V_29 ++ ;
if( V_30 < 0 || V_30 > V_7 -> V_14 )
goto V_105;
V_7 -> V_22 &= ~ V_23 ;
V_7 -> V_21 = V_30 ;
} else {
if( V_7 -> V_22 & V_23 ) {
V_7 -> V_106 ++ ;
return 0 ;
}
}
V_40 = & V_7 -> V_12 [ V_7 -> V_21 ] ;
V_100 = & V_40 -> V_67 ;
V_47 = & V_40 -> V_64 ;
V_100 -> V_94 = * ( T_2 * ) V_29 ;
V_29 += 2 ;
V_100 -> V_92 = ( V_43 & V_93 ) ? 1 : 0 ;
V_102 = V_47 -> V_57 * 4 + V_100 -> V_58 * 4 ;
switch( V_43 & V_107 ) {
case V_88 :
{
register short V_4 ;
V_4 = F_11 ( V_47 -> V_87 ) - V_102 ;
V_100 -> V_83 = F_15 ( F_13 ( V_100 -> V_83 ) + V_4 ) ;
V_100 -> V_85 = F_15 ( F_13 ( V_100 -> V_85 ) + V_4 ) ;
}
break;
case V_89 :
V_100 -> V_85 = F_15 ( F_13 ( V_100 -> V_85 ) +
F_11 ( V_47 -> V_87 ) - V_102 ) ;
break;
default:
if( V_43 & V_80 ) {
V_100 -> V_78 = 1 ;
if( ( V_30 = F_9 ( & V_29 ) ) == - 1 ) {
goto V_105;
}
V_100 -> V_79 = F_12 ( V_30 ) ;
} else
V_100 -> V_78 = 0 ;
if( V_43 & V_82 ) {
if( ( V_30 = F_9 ( & V_29 ) ) == - 1 ) {
goto V_105;
}
V_100 -> V_81 = F_12 ( F_11 ( V_100 -> V_81 ) + V_30 ) ;
}
if( V_43 & V_84 ) {
if( ( V_30 = F_9 ( & V_29 ) ) == - 1 ) {
goto V_105;
}
V_100 -> V_83 = F_15 ( F_13 ( V_100 -> V_83 ) + V_30 ) ;
}
if( V_43 & V_86 ) {
if( ( V_30 = F_9 ( & V_29 ) ) == - 1 ) {
goto V_105;
}
V_100 -> V_85 = F_15 ( F_13 ( V_100 -> V_85 ) + V_30 ) ;
}
break;
}
if( V_43 & V_91 ) {
if( ( V_30 = F_9 ( & V_29 ) ) == - 1 ) {
goto V_105;
}
V_47 -> V_90 = F_12 ( F_11 ( V_47 -> V_90 ) + V_30 ) ;
} else
V_47 -> V_90 = F_12 ( F_11 ( V_47 -> V_90 ) + 1 ) ;
V_101 = V_35 - ( V_29 - V_34 ) ;
if ( V_101 < 0 )
goto V_105;
V_101 += V_102 ;
V_47 -> V_87 = F_12 ( V_101 ) ;
V_47 -> V_94 = 0 ;
memmove ( V_34 + V_102 , V_29 , V_101 - V_102 ) ;
V_29 = V_34 ;
memcpy ( V_29 , V_47 , 20 ) ;
V_29 += 20 ;
if ( V_47 -> V_57 > 5 ) {
memcpy ( V_29 , V_40 -> V_76 , ( V_47 -> V_57 - 5 ) * 4 ) ;
V_29 += ( V_47 -> V_57 - 5 ) * 4 ;
}
F_16 ( F_17 ( V_34 , V_47 -> V_57 ) ,
& ( (struct V_46 * ) V_34 ) -> V_94 ) ;
memcpy ( V_29 , V_100 , 20 ) ;
V_29 += 20 ;
if ( V_100 -> V_58 > 5 ) {
memcpy ( V_29 , V_40 -> V_77 , ( ( V_100 -> V_58 ) - 5 ) * 4 ) ;
V_29 += ( ( V_100 -> V_58 ) - 5 ) * 4 ;
}
return V_101 ;
V_105:
V_7 -> V_104 ++ ;
return F_18 ( V_7 ) ;
}
int
F_19 ( struct V_1 * V_7 , unsigned char * V_34 , int V_35 )
{
register struct V_5 * V_40 ;
unsigned V_57 ;
unsigned char V_108 ;
if( V_35 < 20 ) {
V_7 -> V_109 ++ ;
return F_18 ( V_7 ) ;
}
V_57 = V_34 [ 0 ] & 0xf ;
if( V_57 < 20 / 4 ) {
V_7 -> V_109 ++ ;
return F_18 ( V_7 ) ;
}
V_108 = V_34 [ 9 ] ;
V_34 [ 9 ] = V_53 ;
if ( F_17 ( V_34 , V_57 ) ) {
V_7 -> V_110 ++ ;
return F_18 ( V_7 ) ;
}
if( V_108 > V_7 -> V_14 ) {
V_7 -> V_104 ++ ;
return F_18 ( V_7 ) ;
}
V_40 = & V_7 -> V_12 [ V_7 -> V_21 = V_108 ] ;
V_7 -> V_22 &= ~ V_23 ;
memcpy ( & V_40 -> V_64 , V_34 , 20 ) ;
memcpy ( & V_40 -> V_67 , V_34 + V_57 * 4 , 20 ) ;
if ( V_57 > 5 )
memcpy ( V_40 -> V_76 , V_34 + sizeof( struct V_46 ) , ( V_57 - 5 ) * 4 ) ;
if ( V_40 -> V_67 . V_58 > 5 )
memcpy ( V_40 -> V_77 , V_34 + V_57 * 4 + sizeof( struct V_48 ) , ( V_40 -> V_67 . V_58 - 5 ) * 4 ) ;
V_40 -> V_111 = V_57 * 2 + V_40 -> V_67 . V_58 * 2 ;
V_7 -> V_112 ++ ;
return V_35 ;
}
int
F_18 ( struct V_1 * V_7 )
{
if ( V_7 == V_27 )
return 0 ;
V_7 -> V_22 |= V_23 ;
return 0 ;
}
int
F_18 ( struct V_1 * V_7 )
{
F_20 ( V_113 L_1 ) ;
return - V_8 ;
}
int
F_14 ( struct V_1 * V_7 , unsigned char * V_34 , int V_35 )
{
F_20 ( V_113 L_2 ) ;
return - V_8 ;
}
int
F_10 ( struct V_1 * V_7 , unsigned char * V_34 , int V_35 ,
unsigned char * V_36 , unsigned char * * V_32 , int V_37 )
{
F_20 ( V_113 L_3 ) ;
return - V_8 ;
}
int
F_19 ( struct V_1 * V_7 , unsigned char * V_34 , int V_35 )
{
F_20 ( V_113 L_4 ) ;
return - V_8 ;
}
void
F_5 ( struct V_1 * V_7 )
{
F_20 ( V_113 L_5 ) ;
}
struct V_1 *
F_1 ( int V_2 , int V_3 )
{
F_20 ( V_113 L_6 ) ;
return NULL ;
}
