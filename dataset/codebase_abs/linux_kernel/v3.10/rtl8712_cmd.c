static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 , ( V_5 | V_6 ) ) ;
V_3 = F_3 ( V_2 , V_7 ) ;
V_3 &= ~ ( V_8 ) ;
F_2 ( V_2 , V_7 , V_3 ) ;
V_3 = F_3 ( V_2 , V_9 ) ;
if ( V_3 == 0xff )
return ;
if ( V_3 & V_8 ) {
F_4 ( L_1 ) ;
if ( V_2 -> V_10 == 0 )
return;
F_5 ( F_6 ( V_2 -> V_10 ) , V_11 , 1 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
T_2 V_12 = 0 ;
int V_13 = 50 ;
if ( F_8 ( & V_2 -> V_14 , V_15 ) == true ) {
F_9 ( V_2 , V_16 , 0xf4000001 ) ;
F_10 ( 100 ) ;
while ( ( F_11 ( V_2 , V_16 ) ) &&
( V_13 > 0 ) ) {
V_13 -- ;
F_10 ( 20 ) ;
}
if ( V_13 != 0 )
V_12 = F_11 ( V_2 , V_17 ) ;
else
V_12 = 0 ;
V_12 = V_12 >> 4 ;
V_2 -> V_18 . V_19 =
( T_1 ) F_12 ( V_12 ) ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_1 * V_20 )
{
struct V_21 * V_22 ;
if ( ! V_20 )
return;
V_22 = (struct V_21 * ) V_20 ;
switch ( V_22 -> V_23 ) {
case V_24 :
F_13 ( V_2 ) ;
break;
default:
break;
}
F_15 ( V_22 -> V_20 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 , T_1 * V_20 )
{
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
F_17 = V_28 [ V_27 -> V_29 ] . V_30 ;
if ( F_17 == NULL )
F_18 ( V_27 ) ;
else
F_17 ( V_2 , V_27 ) ;
return V_31 ;
}
static T_1 F_19 ( struct V_1 * V_2 , T_1 * V_20 )
{
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
F_17 = V_28 [ V_27 -> V_29 ] . V_30 ;
if ( F_17 == NULL )
F_18 ( V_27 ) ;
else
F_17 ( V_2 , V_27 ) ;
return V_31 ;
}
static T_1 F_20 ( struct V_1 * V_2 , T_1 * V_20 )
{
T_2 V_32 ;
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_33 * V_34 ;
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
V_34 = (struct V_33 * ) V_27 -> V_35 ;
if ( V_27 -> V_36 && V_27 -> V_37 > 0 )
memcpy ( V_27 -> V_36 , ( T_1 * ) & V_32 , V_27 -> V_37 ) ;
F_17 = V_28 [ V_27 -> V_29 ] . V_30 ;
if ( F_17 == NULL )
F_18 ( V_27 ) ;
else
F_17 ( V_2 , V_27 ) ;
return V_31 ;
}
static T_1 F_21 ( struct V_1 * V_2 , T_1 * V_20 )
{
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_38 * V_39 ;
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
V_39 = (struct V_38 * ) V_27 -> V_35 ;
F_17 = V_28 [ V_27 -> V_29 ] . V_30 ;
if ( F_17 == NULL )
F_18 ( V_27 ) ;
else
F_17 ( V_2 , V_27 ) ;
return V_31 ;
}
static T_1 F_22 ( struct V_1 * V_2 , T_1 * V_20 )
{
T_2 V_32 ;
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_40 * V_41 ;
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
V_41 = (struct V_40 * ) V_27 -> V_35 ;
if ( V_27 -> V_36 && V_27 -> V_37 > 0 )
memcpy ( V_27 -> V_36 , ( T_1 * ) & V_32 , V_27 -> V_37 ) ;
F_17 = V_28 [ V_27 -> V_29 ] . V_30 ;
if ( F_17 == NULL )
F_18 ( V_27 ) ;
else
F_17 ( V_2 , V_27 ) ;
return V_31 ;
}
static T_1 F_23 ( struct V_1 * V_2 , T_1 * V_20 )
{
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_42 * V_43 ;
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
V_43 = (struct V_42 * ) V_27 -> V_35 ;
F_17 = V_28 [ V_27 -> V_29 ] . V_30 ;
if ( F_17 == NULL )
F_18 ( V_27 ) ;
else
F_17 ( V_2 , V_27 ) ;
return V_31 ;
}
static T_1 F_24 ( struct V_1 * V_2 , T_1 * V_20 )
{
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
struct V_44 * V_45 ;
V_45 = (struct V_44 * ) V_27 -> V_35 ;
F_18 ( V_27 ) ;
return V_31 ;
}
static struct V_26 * F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_26 * V_46 ;
if ( V_27 == NULL )
return V_27 ;
V_46 = NULL ;
switch ( V_27 -> V_29 ) {
case F_26 ( V_47 ) :
F_16 ( V_2 , ( T_1 * ) V_27 ) ;
V_46 = V_27 ;
break;
case F_26 ( V_48 ) :
F_19 ( V_2 , ( T_1 * ) V_27 ) ;
V_46 = V_27 ;
break;
case F_26 ( V_49 ) :
F_20 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_50 ) :
F_21 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_51 ) :
F_22 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_52 ) :
F_23 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_53 ) :
F_24 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_54 ) :
F_27 ( V_2 ) ;
if ( V_2 -> V_55 . V_56 > V_57 ) {
V_2 -> V_55 . V_56 = V_57 ;
F_28 ( & ( V_2 -> V_55 . V_58 ) ) ;
F_29 ( V_2 , V_59 ) ;
F_30 ( & ( V_2 -> V_55 . V_58 ) ) ;
}
V_46 = V_27 ;
break;
case V_60 :
F_14 ( V_2 , V_27 -> V_35 ) ;
F_18 ( V_27 ) ;
V_46 = NULL ;
break;
default:
V_46 = V_27 ;
break;
}
return V_46 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_3 V_61 )
{
T_1 V_62 = V_63 ;
return V_62 ;
}
T_1 F_32 ( struct V_1 * V_64 , T_2 V_65 )
{
int V_13 = 50 ;
F_9 ( V_64 , V_16 , V_65 ) ;
F_10 ( 100 ) ;
while ( ( 0 != F_11 ( V_64 , V_16 ) ) &&
( V_13 > 0 ) ) {
V_13 -- ;
F_10 ( 20 ) ;
}
if ( V_13 == 0 )
return false ;
return true ;
}
void F_33 ( struct V_1 * V_64 , T_2 * V_66 , T_1 V_67 )
{
if ( V_67 == 0 )
F_9 ( V_64 , V_17 , * V_66 ) ;
else
* V_66 = F_11 ( V_64 , V_17 ) ;
}
int F_34 ( void * V_68 )
{
struct V_26 * V_27 ;
unsigned int V_69 , V_70 , * V_71 , * V_72 ;
struct V_73 * V_74 ;
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_1 * V_2 = (struct V_1 * ) V_68 ;
struct V_75 * V_76 = & ( V_2 -> V_77 ) ;
F_35 ( V_2 ) ;
while ( 1 ) {
if ( ( F_36 ( & ( V_76 -> V_78 ) ) ) == V_79 )
break;
if ( ( V_2 -> V_80 == true ) ||
( V_2 -> V_81 == true ) )
break;
if ( F_37 ( V_2 ) != V_63 )
continue;
V_82:
V_27 = F_38 ( & ( V_76 -> V_83 ) ) ;
if ( ! ( V_27 ) ) {
F_39 ( V_2 ) ;
continue;
}
V_71 = ( unsigned int * ) V_76 -> V_84 ;
V_72 = ( unsigned int * ) V_76 -> V_85 ;
V_74 = (struct V_73 * ) V_71 ;
memset ( V_74 , 0 , V_86 ) ;
V_27 = F_25 ( V_2 , V_27 ) ;
if ( V_27 ) {
struct V_87 * V_88 = (struct V_87 * )
& V_2 -> V_89 ;
T_1 V_90 = 0 ;
V_76 -> V_91 ++ ;
V_69 = F_40 ( ( V_27 -> V_69 ) ) ;
V_70 = V_86 + 8 + V_69 ;
V_74 -> V_92 |= F_41 ( ( V_70 - V_86 ) &
0x0000ffff ) ;
if ( V_88 -> V_93 ) {
if ( ( V_70 % 512 ) == 0 )
V_90 = 1 ;
} else {
if ( ( V_70 % 64 ) == 0 )
V_90 = 1 ;
}
if ( V_90 )
V_74 -> V_92 |= F_41 ( ( ( V_86 +
V_94 + 8 ) << V_95 ) &
0x00ff0000 ) ;
else {
V_74 -> V_92 |= F_41 ( ( ( V_86 +
V_94 ) <<
V_95 ) &
0x00ff0000 ) ;
}
V_74 -> V_92 |= F_41 ( V_96 | V_97 | V_98 ) ;
V_74 -> V_99 |= F_41 ( ( 0x13 << V_100 ) &
0x00001f00 ) ;
V_71 += ( V_86 >> 2 ) ;
* V_71 = F_41 ( ( V_69 & 0x0000ffff ) |
( V_27 -> V_29 << 16 ) |
( V_76 -> V_101 << 24 ) ) ;
V_71 += 2 ;
memcpy ( ( T_1 * ) V_71 , V_27 -> V_35 , V_27 -> V_69 ) ;
while ( F_31 ( V_2 , V_70 ) == V_79 ) {
if ( ( V_2 -> V_80 == true ) ||
( V_2 -> V_81 == true ) )
break;
F_10 ( 100 ) ;
continue;
}
if ( V_90 )
V_70 += 8 ;
F_42 ( V_2 , V_102 , V_70 ,
( T_1 * ) V_74 ) ;
V_76 -> V_101 ++ ;
if ( V_27 -> V_29 == F_26 ( V_103 ) ) {
V_27 -> V_62 = V_31 ;
F_17 = V_28 [ V_27 ->
V_29 ] . V_30 ;
if ( F_17 )
F_17 ( V_2 , V_27 ) ;
continue;
}
if ( V_27 -> V_29 == F_26 ( V_104 ) ) {
if ( V_2 -> V_55 . V_105 ) {
F_28 ( & ( V_2 ->
V_55 . V_58 ) ) ;
F_29 ( V_2 , V_106 ) ;
F_30 ( & V_2 -> V_55 . V_58 ) ;
}
}
F_18 ( V_27 ) ;
if ( F_43 ( & ( V_76 -> V_83 ) ) ) {
F_39 ( V_2 ) ;
continue;
} else
goto V_82;
} else
goto V_82;
F_44 () ;
}
do {
V_27 = F_38 ( & ( V_76 -> V_83 ) ) ;
if ( V_27 == NULL )
break;
F_18 ( V_27 ) ;
} while ( 1 );
F_30 ( & V_76 -> V_107 ) ;
F_45 () ;
}
void F_46 ( struct V_1 * V_2 , T_3 * V_108 )
{
T_1 V_109 , V_110 ;
T_4 V_111 ;
void (* F_47)( struct V_1 * V_25 , T_1 * V_20 );
struct V_112 * V_113 = & ( V_2 -> V_114 ) ;
if ( V_108 == NULL )
goto V_115;
V_111 = ( T_4 ) ( F_48 ( * V_108 ) & 0xffff ) ;
V_110 = ( T_1 ) ( ( F_48 ( * V_108 ) >> 24 ) & 0x7f ) ;
V_109 = ( T_1 ) ( ( F_48 ( * V_108 ) >> 16 ) & 0xff ) ;
if ( ( V_110 & 0x7f ) != V_113 -> V_116 ) {
V_113 -> V_116 = ( ( V_110 + 1 ) & 0x7f ) ;
goto V_115;
}
if ( V_109 >= V_117 ) {
V_113 -> V_116 = ( ( V_110 + 1 ) & 0x7f ) ;
goto V_115;
} else if ( ( V_109 == F_49 ( V_118 ) ) &&
( V_111 > sizeof( struct V_119 ) ) ) {
V_113 -> V_116 = ( ( V_110 + 1 ) & 0x7f ) ;
goto V_115;
}
if ( ( V_120 [ V_109 ] . V_121 ) &&
( V_120 [ V_109 ] . V_121 != V_111 ) ) {
V_113 -> V_116 = ( ( V_110 + 1 ) & 0x7f ) ;
goto V_115;
} else if ( ( V_111 == 0 ) && ( V_109 != F_49 ( V_122 ) ) ) {
V_113 -> V_116 = ( ( V_110 + 1 ) & 0x7f ) ;
goto V_115;
}
V_113 -> V_116 ++ ;
if ( V_113 -> V_116 > 127 )
V_113 -> V_116 = 0 ;
V_108 = V_108 + 2 ;
if ( V_108 ) {
F_47 = V_120 [ V_109 ] . F_47 ;
if ( F_47 )
F_47 ( V_2 , ( T_1 * ) V_108 ) ;
}
V_113 -> V_123 ++ ;
V_115:
return;
}
