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
if ( ! F_17 )
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
if ( ! F_17 )
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
if ( ! F_17 )
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
if ( ! F_17 )
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
if ( ! F_17 )
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
if ( ! F_17 )
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
if ( ! V_27 )
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
F_28 ( & V_2 -> V_44 . F_28 ) ;
F_29 ( V_2 , V_47 ) ;
F_30 ( & V_2 -> V_44 . F_28 ) ;
}
V_35 = V_27 ;
break;
case V_48 :
F_14 ( V_2 , V_27 -> V_49 ) ;
F_18 ( V_27 ) ;
V_35 = NULL ;
break;
default:
V_35 = V_27 ;
break;
}
return V_35 ;
}
static T_1 F_31 ( struct V_1 * V_2 , T_3 V_50 )
{
return V_51 ;
}
T_1 F_32 ( struct V_1 * V_52 , T_2 V_53 )
{
int V_13 = 50 ;
F_9 ( V_52 , V_16 , V_53 ) ;
F_10 ( 100 ) ;
while ( ( F_11 ( V_52 , V_16 != 0 ) ) &&
( V_13 > 0 ) ) {
V_13 -- ;
F_10 ( 20 ) ;
}
if ( V_13 == 0 )
return false ;
return true ;
}
void F_33 ( struct V_1 * V_52 , T_2 * V_54 , T_1 V_55 )
{
if ( V_55 == 0 )
F_9 ( V_52 , V_17 , * V_54 ) ;
else
* V_54 = F_11 ( V_52 , V_17 ) ;
}
int F_34 ( void * V_56 )
{
struct V_26 * V_27 ;
unsigned int V_57 , V_58 ;
T_4 * V_59 ;
struct V_60 * V_61 ;
void (* F_17)( struct V_1 * V_25 , struct V_26 * V_27 );
struct V_1 * V_2 = V_56 ;
struct V_62 * V_63 = & ( V_2 -> V_64 ) ;
F_35 ( V_65 ) ;
while ( 1 ) {
if ( F_36 ( & V_63 -> V_66 ) )
break;
if ( V_2 -> V_67 || V_2 -> V_68 )
break;
if ( F_37 ( V_2 ) != V_51 )
continue;
V_69:
V_27 = F_38 ( & ( V_63 -> V_70 ) ) ;
if ( ! ( V_27 ) ) {
F_39 ( V_2 ) ;
continue;
}
V_59 = ( T_4 * ) V_63 -> V_71 ;
V_61 = (struct V_60 * ) V_59 ;
memset ( V_61 , 0 , V_72 ) ;
V_27 = F_25 ( V_2 , V_27 ) ;
if ( V_27 ) {
struct V_73 * V_74 = & V_2 -> V_75 ;
T_1 V_76 = 0 ;
V_63 -> V_77 ++ ;
V_57 = F_40 ( V_27 -> V_57 , 8 ) ;
V_58 = V_72 + 8 + V_57 ;
V_61 -> V_78 |= F_41 ( ( V_58 - V_72 ) &
0x0000ffff ) ;
if ( V_74 -> V_79 ) {
if ( ( V_58 % 512 ) == 0 )
V_76 = 1 ;
} else {
if ( ( V_58 % 64 ) == 0 )
V_76 = 1 ;
}
if ( V_76 )
V_61 -> V_78 |= F_41 ( ( ( V_72 +
V_80 + 8 ) << V_81 ) &
0x00ff0000 ) ;
else {
V_61 -> V_78 |= F_41 ( ( ( V_72 +
V_80 ) <<
V_81 ) &
0x00ff0000 ) ;
}
V_61 -> V_78 |= F_41 ( V_82 | V_83 | V_84 ) ;
V_61 -> V_85 |= F_41 ( ( 0x13 << V_86 ) &
0x00001f00 ) ;
V_59 += ( V_72 >> 2 ) ;
* V_59 = F_41 ( ( V_57 & 0x0000ffff ) |
( V_27 -> V_29 << 16 ) |
( V_63 -> V_87 << 24 ) ) ;
V_59 += 2 ;
memcpy ( ( T_1 * ) V_59 , V_27 -> V_49 , V_27 -> V_57 ) ;
while ( F_31 ( V_2 , V_58 ) == V_88 ) {
if ( V_2 -> V_67 ||
V_2 -> V_68 )
break;
F_10 ( 100 ) ;
continue;
}
if ( V_76 )
V_58 += 8 ;
F_42 ( V_2 , V_89 , V_58 ,
( T_1 * ) V_61 ) ;
V_63 -> V_87 ++ ;
if ( V_27 -> V_29 == F_26 ( V_90 ) ) {
V_27 -> V_91 = V_31 ;
F_17 = V_28 [ V_27 ->
V_29 ] . V_30 ;
if ( F_17 )
F_17 ( V_2 , V_27 ) ;
continue;
}
if ( V_27 -> V_29 == F_26 ( V_92 ) ) {
if ( V_2 -> V_44 . V_93 ) {
F_28 ( & V_2 ->
V_44 . F_28 ) ;
F_29 ( V_2 , V_94 ) ;
F_30 ( & V_2 -> V_44 . F_28 ) ;
}
}
F_18 ( V_27 ) ;
if ( F_43 ( & V_63 -> V_70 . V_95 ) ) {
F_39 ( V_2 ) ;
continue;
} else {
goto V_69;
}
} else {
goto V_69;
}
F_44 () ;
}
do {
V_27 = F_38 ( & ( V_63 -> V_70 ) ) ;
if ( ! V_27 )
break;
F_18 ( V_27 ) ;
} while ( 1 );
F_45 ( & V_63 -> V_96 ) ;
F_46 () ;
}
void F_47 ( struct V_1 * V_2 , T_4 * V_97 )
{
T_1 V_98 , V_99 ;
T_5 V_100 ;
void (* F_48)( struct V_1 * V_25 , T_1 * V_20 );
struct V_101 * V_102 = & ( V_2 -> V_103 ) ;
if ( ! V_97 )
goto V_104;
V_100 = ( T_5 ) ( F_49 ( * V_97 ) & 0xffff ) ;
V_99 = ( T_1 ) ( ( F_49 ( * V_97 ) >> 24 ) & 0x7f ) ;
V_98 = ( T_1 ) ( ( F_49 ( * V_97 ) >> 16 ) & 0xff ) ;
if ( ( V_99 & 0x7f ) != V_102 -> V_105 ) {
V_102 -> V_105 = ( ( V_99 + 1 ) & 0x7f ) ;
goto V_104;
}
if ( V_98 >= V_106 ) {
V_102 -> V_105 = ( ( V_99 + 1 ) & 0x7f ) ;
goto V_104;
} else if ( ( V_98 == F_50 ( V_107 ) ) &&
( V_100 > sizeof( struct V_108 ) ) ) {
V_102 -> V_105 = ( ( V_99 + 1 ) & 0x7f ) ;
goto V_104;
}
if ( ( V_109 [ V_98 ] . V_110 ) &&
( V_109 [ V_98 ] . V_110 != V_100 ) ) {
V_102 -> V_105 = ( ( V_99 + 1 ) & 0x7f ) ;
goto V_104;
} else if ( ( V_100 == 0 ) && ( V_98 != F_50 ( V_111 ) ) ) {
V_102 -> V_105 = ( ( V_99 + 1 ) & 0x7f ) ;
goto V_104;
}
V_102 -> V_105 ++ ;
if ( V_102 -> V_105 > 127 )
V_102 -> V_105 = 0 ;
V_97 = V_97 + 2 ;
F_48 = V_109 [ V_98 ] . F_48 ;
if ( F_48 )
F_48 ( V_2 , ( T_1 * ) V_97 ) ;
V_102 -> V_112 ++ ;
V_104:
return;
}
