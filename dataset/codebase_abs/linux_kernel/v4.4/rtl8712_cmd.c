static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
F_2 ( V_2 , V_4 , ( V_5 | V_6 ) ) ;
V_3 = F_3 ( V_2 , V_7 ) ;
V_3 &= ~ ( V_8 ) ;
F_2 ( V_2 , V_7 , V_3 ) ;
V_3 = F_3 ( V_2 , V_9 ) ;
if ( V_3 == 0xff )
return;
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
if ( F_8 ( & V_2 -> V_14 , V_15 ) ) {
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
V_12 >>= 4 ;
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
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
if ( V_27 -> V_33 && V_27 -> V_34 > 0 )
memcpy ( V_27 -> V_33 , ( T_1 * ) & V_32 , V_27 -> V_34 ) ;
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
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
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
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
if ( V_27 -> V_33 && V_27 -> V_34 > 0 )
memcpy ( V_27 -> V_33 , ( T_1 * ) & V_32 , V_27 -> V_34 ) ;
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
struct V_26 * V_27 = (struct V_26 * ) V_20 ;
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
F_18 ( V_27 ) ;
return V_31 ;
}
static struct V_26 * F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_26 * V_35 ;
if ( V_27 == NULL )
return V_27 ;
V_35 = NULL ;
switch ( V_27 -> V_29 ) {
case F_26 ( V_36 ) :
F_16 ( V_2 , ( T_1 * ) V_27 ) ;
V_35 = V_27 ;
break;
case F_26 ( V_37 ) :
F_19 ( V_2 , ( T_1 * ) V_27 ) ;
V_35 = V_27 ;
break;
case F_26 ( V_38 ) :
F_20 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_39 ) :
F_21 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_40 ) :
F_22 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_41 ) :
F_23 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_42 ) :
F_24 ( V_2 , ( T_1 * ) V_27 ) ;
break;
case F_26 ( V_43 ) :
F_27 ( V_2 ) ;
if ( V_2 -> V_44 . V_45 > V_46 ) {
V_2 -> V_44 . V_45 = V_46 ;
F_28 ( & ( V_2 -> V_44 . V_47 ) ) ;
F_29 ( V_2 , V_48 ) ;
F_30 ( & ( V_2 -> V_44 . V_47 ) ) ;
}
V_35 = V_27 ;
break;
case V_49 :
F_14 ( V_2 , V_27 -> V_50 ) ;
F_18 ( V_27 ) ;
V_35 = NULL ;
break;
default:
V_35 = V_27 ;
break;
}
return V_35 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_3 V_51 )
{
return V_52 ;
}
T_1 F_32 ( struct V_1 * V_53 , T_2 V_54 )
{
int V_13 = 50 ;
F_9 ( V_53 , V_16 , V_54 ) ;
F_10 ( 100 ) ;
while ( ( 0 != F_11 ( V_53 , V_16 ) ) &&
( V_13 > 0 ) ) {
V_13 -- ;
F_10 ( 20 ) ;
}
if ( V_13 == 0 )
return false ;
return true ;
}
void F_33 ( struct V_1 * V_53 , T_2 * V_55 , T_1 V_56 )
{
if ( V_56 == 0 )
F_9 ( V_53 , V_17 , * V_55 ) ;
else
* V_55 = F_11 ( V_53 , V_17 ) ;
}
int F_34 ( void * V_57 )
{
struct V_26 * V_27 ;
unsigned int V_58 , V_59 , * V_60 ;
struct V_61 * V_62 ;
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_1 * V_2 = (struct V_1 * ) V_57 ;
struct V_63 * V_64 = & ( V_2 -> V_65 ) ;
F_35 ( V_66 ) ;
while ( 1 ) {
if ( ( F_36 ( & ( V_64 -> V_67 ) ) ) == V_68 )
break;
if ( V_2 -> V_69 || V_2 -> V_70 )
break;
if ( F_37 ( V_2 ) != V_52 )
continue;
V_71:
V_27 = F_38 ( & ( V_64 -> V_72 ) ) ;
if ( ! ( V_27 ) ) {
F_39 ( V_2 ) ;
continue;
}
V_60 = ( unsigned int * ) V_64 -> V_73 ;
V_62 = (struct V_61 * ) V_60 ;
memset ( V_62 , 0 , V_74 ) ;
V_27 = F_25 ( V_2 , V_27 ) ;
if ( V_27 ) {
struct V_75 * V_76 = & V_2 -> V_77 ;
T_1 V_78 = 0 ;
V_64 -> V_79 ++ ;
V_58 = F_40 ( V_27 -> V_58 , 8 ) ;
V_59 = V_74 + 8 + V_58 ;
V_62 -> V_80 |= F_41 ( ( V_59 - V_74 ) &
0x0000ffff ) ;
if ( V_76 -> V_81 ) {
if ( ( V_59 % 512 ) == 0 )
V_78 = 1 ;
} else {
if ( ( V_59 % 64 ) == 0 )
V_78 = 1 ;
}
if ( V_78 )
V_62 -> V_80 |= F_41 ( ( ( V_74 +
V_82 + 8 ) << V_83 ) &
0x00ff0000 ) ;
else {
V_62 -> V_80 |= F_41 ( ( ( V_74 +
V_82 ) <<
V_83 ) &
0x00ff0000 ) ;
}
V_62 -> V_80 |= F_41 ( V_84 | V_85 | V_86 ) ;
V_62 -> V_87 |= F_41 ( ( 0x13 << V_88 ) &
0x00001f00 ) ;
V_60 += ( V_74 >> 2 ) ;
* V_60 = F_41 ( ( V_58 & 0x0000ffff ) |
( V_27 -> V_29 << 16 ) |
( V_64 -> V_89 << 24 ) ) ;
V_60 += 2 ;
memcpy ( ( T_1 * ) V_60 , V_27 -> V_50 , V_27 -> V_58 ) ;
while ( F_31 ( V_2 , V_59 ) == V_68 ) {
if ( V_2 -> V_69 ||
V_2 -> V_70 )
break;
F_10 ( 100 ) ;
continue;
}
if ( V_78 )
V_59 += 8 ;
F_42 ( V_2 , V_90 , V_59 ,
( T_1 * ) V_62 ) ;
V_64 -> V_89 ++ ;
if ( V_27 -> V_29 == F_26 ( V_91 ) ) {
V_27 -> V_92 = V_31 ;
F_17 = V_28 [ V_27 ->
V_29 ] . V_30 ;
if ( F_17 )
F_17 ( V_2 , V_27 ) ;
continue;
}
if ( V_27 -> V_29 == F_26 ( V_93 ) ) {
if ( V_2 -> V_44 . V_94 ) {
F_28 ( & ( V_2 ->
V_44 . V_47 ) ) ;
F_29 ( V_2 , V_95 ) ;
F_30 ( & V_2 -> V_44 . V_47 ) ;
}
}
F_18 ( V_27 ) ;
if ( F_43 ( & V_64 -> V_72 . V_96 ) ) {
F_39 ( V_2 ) ;
continue;
} else {
goto V_71;
}
} else {
goto V_71;
}
F_44 () ;
}
do {
V_27 = F_38 ( & ( V_64 -> V_72 ) ) ;
if ( V_27 == NULL )
break;
F_18 ( V_27 ) ;
} while ( 1 );
F_30 ( & V_64 -> V_97 ) ;
F_45 () ;
}
void F_46 ( struct V_1 * V_2 , T_3 * V_98 )
{
T_1 V_99 , V_100 ;
T_4 V_101 ;
void (* F_47)( struct V_1 * V_25 , T_1 * V_20 );
struct V_102 * V_103 = & ( V_2 -> V_104 ) ;
if ( V_98 == NULL )
goto V_105;
V_101 = ( T_4 ) ( F_48 ( * V_98 ) & 0xffff ) ;
V_100 = ( T_1 ) ( ( F_48 ( * V_98 ) >> 24 ) & 0x7f ) ;
V_99 = ( T_1 ) ( ( F_48 ( * V_98 ) >> 16 ) & 0xff ) ;
if ( ( V_100 & 0x7f ) != V_103 -> V_106 ) {
V_103 -> V_106 = ( ( V_100 + 1 ) & 0x7f ) ;
goto V_105;
}
if ( V_99 >= V_107 ) {
V_103 -> V_106 = ( ( V_100 + 1 ) & 0x7f ) ;
goto V_105;
} else if ( ( V_99 == F_49 ( V_108 ) ) &&
( V_101 > sizeof( struct V_109 ) ) ) {
V_103 -> V_106 = ( ( V_100 + 1 ) & 0x7f ) ;
goto V_105;
}
if ( ( V_110 [ V_99 ] . V_111 ) &&
( V_110 [ V_99 ] . V_111 != V_101 ) ) {
V_103 -> V_106 = ( ( V_100 + 1 ) & 0x7f ) ;
goto V_105;
} else if ( ( V_101 == 0 ) && ( V_99 != F_49 ( V_112 ) ) ) {
V_103 -> V_106 = ( ( V_100 + 1 ) & 0x7f ) ;
goto V_105;
}
V_103 -> V_106 ++ ;
if ( V_103 -> V_106 > 127 )
V_103 -> V_106 = 0 ;
V_98 = V_98 + 2 ;
F_47 = V_110 [ V_99 ] . F_47 ;
if ( F_47 )
F_47 ( V_2 , ( T_1 * ) V_98 ) ;
V_103 -> V_113 ++ ;
V_105:
return;
}
