void * F_1 ( T_1 * V_1 , void * V_2 , void * V_3 )
{
T_2 * V_4 ;
V_4 = F_2 ( sizeof( T_2 ) , V_5 ) ;
if ( V_4 == NULL ) {
F_3 ( ( L_1 ) ) ;
return NULL ;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_6 = V_2 ;
if ( V_1 -> V_7 == V_8 ) {
T_3 V_9 ;
V_4 -> V_3 . V_10 = ( V_11 * ) V_3 ;
V_9 = F_4 ( V_4 -> V_6 , V_12 ,
NULL , NULL ) ;
V_4 -> V_13 = V_9 + V_14 ;
} else
V_4 -> V_3 . V_15 = (struct V_16 * ) V_3 ;
return V_4 ;
}
void F_5 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
if ( V_4 == NULL )
return;
F_6 ( V_4 ) ;
}
T_3
F_4 ( void * V_6 , T_3 V_18 ,
unsigned char * V_19 , T_4 * V_20 )
{
T_3 V_21 ;
T_3 V_9 = 0 ;
T_4 V_22 ;
T_3 V_23 ;
F_7 ( V_6 , V_24 , & V_23 ) ;
if ( ( V_23 & 0x7f ) != V_25 )
goto V_26;
F_7 ( V_6 , V_27 , & V_23 ) ;
if ( ! ( V_23 & V_28 ) )
goto V_26;
F_7 ( V_6 , V_29 , & V_9 ) ;
if ( V_9 == 0x00 )
goto V_26;
F_7 ( V_6 , V_9 , & V_21 ) ;
while ( V_21 != V_18 ) {
F_7 ( V_6 , V_9 + 1 , & V_9 ) ;
if ( V_9 == 0x00 )
break;
F_7 ( V_6 , V_9 , & V_21 ) ;
}
if ( V_21 != V_18 ) {
goto V_26;
}
if ( ( V_19 != NULL ) && ( V_20 != NULL ) ) {
T_3 V_30 ;
V_22 = * V_20 ;
if ( ! V_22 )
goto V_26;
* V_20 = 0 ;
V_30 = V_9 + 2 ;
if ( ( V_22 + V_30 ) > V_31 )
V_22 = V_31 - V_30 ;
* V_20 = V_22 ;
while ( V_22 -- ) {
F_7 ( V_6 , V_30 , V_19 ) ;
V_30 ++ ;
V_19 ++ ;
}
}
V_26:
return V_9 ;
}
T_5
F_8 ( V_11 * V_10 , T_5 V_32 ,
T_5 V_33 )
{
T_5 V_34 = 0xFFFFFFFF ;
switch ( V_32 ) {
case V_35 :
F_9 ( ( & V_10 -> V_36 ) , V_33 ) ;
( void ) F_10 ( ( & V_10 -> V_36 ) ) ;
V_34 = F_10 ( & ( V_10 -> V_37 ) ) ;
break;
case V_38 :
F_9 ( & ( V_10 -> V_39 ) , V_33 ) ;
( void ) F_10 ( ( & V_10 -> V_39 ) ) ;
V_34 = F_10 ( & ( V_10 -> V_40 ) ) ;
break;
default:
break;
}
return V_34 ;
}
T_5
F_11 ( V_11 * V_10 , T_5 V_32 ,
T_5 V_33 , T_5 V_41 )
{
switch ( V_32 ) {
case V_35 :
F_9 ( ( & V_10 -> V_36 ) , V_33 ) ;
F_9 ( ( & V_10 -> V_37 ) , V_41 ) ;
break;
case V_38 :
F_9 ( ( & V_10 -> V_39 ) , V_33 ) ;
F_9 ( ( & V_10 -> V_40 ) , V_41 ) ;
break;
default:
break;
}
return 0 ;
}
static bool F_12 ( T_2 * V_4 , T_5 V_42 )
{
V_11 * V_10 = V_4 -> V_3 . V_10 ;
T_5 V_43 , V_44 = 0 ;
T_5 V_45 = 200 ;
V_43 =
V_46 | V_47 | ( V_48 <<
V_49 ) |
( V_50 << V_51 ) | V_52 | ( V_42 <<
4 ) ;
F_9 ( & V_10 -> V_43 , V_43 ) ;
F_13 () ;
while ( V_44 < V_45 ) {
if ( F_10 ( & ( V_10 -> V_53 ) ) &
V_54 ) {
break;
}
F_14 ( 1000 ) ;
V_44 ++ ;
}
if ( V_44 >= V_45 ) {
F_3 ( ( L_2 ) ) ;
return false ;
}
return true ;
}
static int
F_15 ( T_2 * V_4 , T_5 V_55 , T_5 V_56 , bool V_57 ,
T_5 * V_41 )
{
V_11 * V_10 = V_4 -> V_3 . V_10 ;
T_5 V_43 ;
T_5 V_44 = 0 ;
T_5 V_45 = 10 ;
F_9 ( ( & V_10 -> V_53 ) ,
V_58 | V_59 ) ;
if ( V_4 -> V_1 -> V_60 >= 10 ) {
if ( ! F_12 ( V_4 , V_55 ) )
return 1 ;
V_43 = ( V_48 << V_49 ) |
( V_56 << V_51 ) ;
V_45 *= 20 ;
} else {
V_43 = ( V_55 << V_61 ) |
( V_56 << V_62 ) ;
}
if ( ! V_57 )
V_43 |= ( V_46 | V_63 | V_52 ) ;
else
V_43 |=
( V_46 | V_47 | V_52 | * V_41 ) ;
F_9 ( & V_10 -> V_43 , V_43 ) ;
F_13 () ;
while ( V_44 < V_45 ) {
if ( F_10 ( & ( V_10 -> V_53 ) ) &
V_54 ) {
if ( ! V_57 ) {
F_13 () ;
* V_41 =
( F_10 ( & ( V_10 -> V_43 ) ) &
V_64 ) ;
}
F_9 ( ( & V_10 -> V_53 ) , 0 ) ;
return 0 ;
}
F_14 ( 1000 ) ;
V_44 ++ ;
}
F_3 ( ( L_3 , V_57 ) ) ;
F_9 ( ( & V_10 -> V_53 ) , 0 ) ;
return 1 ;
}
static int
F_16 ( T_2 * V_4 , T_5 V_55 , T_5 V_56 , T_5 * V_65 )
{
return F_15 ( V_4 , V_55 , V_56 , false , V_65 ) ;
}
static int
F_17 ( T_2 * V_4 , T_5 V_55 , T_5 V_56 , T_5 V_41 )
{
return F_15 ( V_4 , V_55 , V_56 , true , & V_41 ) ;
}
T_3 F_18 ( void * V_17 , T_4 V_66 , T_4 V_41 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_4 V_67 ;
T_3 V_33 ;
V_33 = V_4 -> V_13 ;
if ( ! V_33 )
return 0 ;
F_19 ( V_4 -> V_6 , V_33 , & V_67 ) ;
if ( V_66 ) {
if ( V_41 )
V_67 |= V_68 ;
else
V_67 &= ~ V_68 ;
F_20 ( V_4 -> V_6 , V_33 , V_67 ) ;
F_19 ( V_4 -> V_6 , V_33 , & V_67 ) ;
}
if ( V_67 & V_68 )
return 1 ;
else
return 0 ;
}
static void F_21 ( T_2 * V_4 , bool V_69 )
{
T_4 V_70 ;
T_1 * V_1 = V_4 -> V_1 ;
V_11 * V_10 = V_4 -> V_3 . V_10 ;
if ( ! F_22 ( V_1 ) || V_1 -> V_60 < 7 )
return;
V_70 = F_8 ( V_10 , V_38 , V_71 ) ;
if ( V_69 )
V_70 |= V_72 ;
else
V_70 &= ~ V_72 ;
F_11 ( V_10 , V_38 , V_71 , V_70 ) ;
V_70 = F_8 ( V_10 , V_38 , V_71 ) ;
}
static void F_23 ( T_2 * V_4 , T_5 V_73 )
{
T_1 * V_1 = V_4 -> V_1 ;
switch ( V_73 ) {
case V_74 :
if ( F_24 ( V_1 ) )
F_18 ( ( void * ) V_4 , 1 , 0 ) ;
break;
case V_75 :
if ( V_1 -> V_60 == 6 ) {
F_25 ( V_1 , V_76 ,
F_26 ( V_77 , V_78 ) , ~ 0 ,
0 ) ;
F_25 ( V_1 , V_76 ,
F_26 ( V_77 , V_79 ) ,
~ 0x40 , 0 ) ;
} else if ( V_4 -> V_80 ) {
F_18 ( ( void * ) V_4 , 1 , 1 ) ;
}
break;
case V_81 :
if ( V_1 -> V_60 == 6 ) {
F_25 ( V_1 , V_76 ,
F_26 ( V_77 , V_78 ) , ~ 0 ,
0 ) ;
F_25 ( V_1 , V_76 ,
F_26 ( V_77 , V_79 ) ,
~ 0x40 , 0x40 ) ;
} else if ( F_24 ( V_1 ) ) {
F_18 ( ( void * ) V_4 , 1 , 0 ) ;
}
break;
default:
break;
}
}
static void F_27 ( T_2 * V_4 )
{
T_4 V_70 ;
if ( V_4 -> V_82 != 0 )
return;
V_70 = F_8 ( V_4 -> V_3 . V_10 , V_38 ,
V_83 ) ;
if ( ( V_70 & V_84 ) == 0 )
V_4 -> V_82 = ( V_85 ) ;
else
V_4 -> V_82 =
( V_85 | V_86 ) ;
}
static void F_28 ( T_2 * V_4 )
{
V_11 * V_10 = V_4 -> V_3 . V_10 ;
T_1 * V_1 = V_4 -> V_1 ;
T_6 V_87 , * V_88 ;
T_4 V_70 ;
if ( ! F_24 ( V_1 ) )
return;
if ( ! F_29 ( V_1 ) ) {
V_88 = & V_10 -> V_89 [ V_90 ] ;
V_87 = F_10 ( V_88 ) ;
V_87 &= ~ V_91 ;
if ( V_4 -> V_92 == V_93 )
V_87 |= V_91 ;
else if ( V_4 -> V_92 == V_94 )
V_87 |= V_95 ;
else if ( V_4 -> V_92 == V_96 )
V_87 |= V_97 ;
F_9 ( V_88 , V_87 ) ;
F_19 ( V_4 -> V_6 , V_4 -> V_13 ,
& V_70 ) ;
V_70 &= ~ V_93 ;
V_70 |= V_4 -> V_92 ;
F_20 ( V_4 -> V_6 ,
V_4 -> V_13 , V_70 ) ;
}
V_88 = & V_10 -> V_89 [ V_98 ] ;
V_87 = F_10 ( V_88 ) ;
if ( V_4 -> V_92 != V_99 ) {
V_87 |= V_100 ;
V_4 -> V_80 = true ;
} else
V_87 &= ~ V_100 ;
F_9 ( V_88 , V_87 ) ;
}
static void F_30 ( T_2 * V_4 )
{
T_4 V_70 = 0 ;
if ( V_4 -> V_82 != 0 )
F_17 ( V_4 , V_101 , V_102 ,
V_4 -> V_82 ) ;
F_16 ( V_4 , V_103 , V_104 , & V_70 ) ;
if ( V_70 & V_105 ) {
V_70 &= ~ V_105 ;
F_17 ( V_4 , V_103 , V_104 , V_70 ) ;
}
}
static void F_31 ( T_2 * V_4 )
{
V_11 * V_10 = V_4 -> V_3 . V_10 ;
T_6 V_87 , * V_88 ;
V_88 = & V_10 -> V_89 [ V_106 ] ;
V_87 = F_10 ( V_88 ) ;
if ( ( V_87 & V_107 ) == 0 ) {
V_87 |= V_107 ;
F_9 ( V_88 , V_87 ) ;
}
}
static void F_32 ( T_2 * V_4 )
{
V_11 * V_10 = V_4 -> V_3 . V_10 ;
T_6 * V_88 ;
F_25 ( V_4 -> V_1 , V_76 , F_26 ( V_77 , V_108 ) ,
V_109 , V_109 ) ;
V_88 = & V_10 -> V_89 [ V_110 ] ;
F_9 ( V_88 , 0 ) ;
}
static void F_33 ( T_2 * V_4 )
{
T_1 * V_1 = V_4 -> V_1 ;
V_11 * V_10 = V_4 -> V_3 . V_10 ;
T_4 V_70 ;
if ( ( V_1 -> V_60 == 0 ) || ( V_1 -> V_60 == 1 ) ) {
V_70 = F_8 ( V_10 , V_38 ,
V_111 ) ;
V_70 |= 0x8 ;
F_11 ( V_10 , V_38 ,
V_111 , V_70 ) ;
}
if ( V_1 -> V_60 == 1 ) {
V_70 = F_8 ( V_10 , V_38 , V_112 ) ;
V_70 |= ( 0x40 ) ;
F_11 ( V_10 , V_38 , V_112 , V_70 ) ;
}
if ( V_1 -> V_60 == 0 ) {
F_17 ( V_4 , V_101 , V_113 , 0x8128 ) ;
F_17 ( V_4 , V_101 , V_114 , 0x0100 ) ;
F_17 ( V_4 , V_101 , V_115 , 0x1466 ) ;
} else if ( F_24 ( V_1 ) ) {
V_70 = F_8 ( V_10 , V_38 ,
V_71 ) ;
V_70 &= ~ ( V_116 ) ;
V_70 |= ( V_117 << V_118 ) ;
F_11 ( V_10 , V_38 ,
V_71 , V_70 ) ;
F_30 ( V_4 ) ;
F_28 ( V_4 ) ;
} else if ( V_4 -> V_1 -> V_60 == 7 )
F_32 ( V_4 ) ;
if ( V_4 -> V_1 -> V_60 >= 6 )
F_31 ( V_4 ) ;
}
void F_34 ( void * V_17 , T_3 V_119 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
if ( ! F_24 ( V_4 -> V_1 ) )
return;
if ( V_119 > V_93 )
return;
V_4 -> V_92 = V_119 ;
F_28 ( V_4 ) ;
}
void F_35 ( void * V_17 , char * V_120 , int V_73 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_1 * V_1 = V_4 -> V_1 ;
if ( F_24 ( V_1 ) ) {
if ( ( T_4 ) F_36 ( V_120 , L_4 ) & V_121 ) {
V_4 -> V_92 = V_99 ;
} else {
V_4 -> V_92 = V_93 ;
}
}
F_27 ( V_4 ) ;
F_30 ( V_4 ) ;
F_28 ( V_4 ) ;
F_23 ( V_4 , V_73 ) ;
}
void F_37 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
if ( ! V_4 || ! F_22 ( V_4 -> V_1 ) )
return;
F_33 ( V_4 ) ;
}
void F_38 ( void * V_17 , int V_73 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
if ( ! V_4 || ! F_22 ( V_4 -> V_1 ) )
return;
F_21 ( V_4 , true ) ;
F_23 ( V_4 , V_73 ) ;
}
void F_39 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_4 V_70 ;
if ( ! V_4 || ! F_24 ( V_4 -> V_1 ) )
return;
F_19 ( V_4 -> V_6 , V_4 -> V_13 , & V_70 ) ;
V_70 &= ~ V_122 ;
F_20 ( V_4 -> V_6 , V_4 -> V_13 , V_70 ) ;
V_4 -> V_80 = false ;
}
void F_40 ( void * V_17 , int V_73 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
if ( ! V_4 || ! F_22 ( V_4 -> V_1 ) )
return;
F_23 ( V_4 , V_73 ) ;
F_21 ( V_4 , false ) ;
}
bool F_41 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_3 V_9 ;
T_4 V_123 ;
V_9 = F_4 ( V_4 -> V_6 , V_124 , NULL ,
NULL ) ;
if ( ! V_9 )
return false ;
F_19 ( V_4 -> V_6 , V_9 , & V_123 ) ;
return ( V_123 & ( V_125 << 16 ) ) != 0 ;
}
static bool F_42 ( T_2 * V_4 )
{
T_3 V_9 ;
T_4 V_123 ;
if ( ! V_4 -> V_126 ) {
V_9 = F_4 ( V_4 -> V_6 ,
V_124 ,
NULL , NULL ) ;
if ( ! V_9 )
return false ;
V_4 -> V_126 = V_9 ;
F_19 ( V_4 -> V_6 , V_4 -> V_126 ,
& V_123 ) ;
V_4 -> V_123 = ( V_123 & ( V_125 << 16 ) ) != 0 ;
}
return V_4 -> V_123 ;
}
void F_43 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_4 V_70 ;
if ( ! F_42 ( V_4 ) )
return;
F_19 ( V_4 -> V_6 , V_4 -> V_126 + V_127 ,
& V_70 ) ;
V_70 |= ( V_128 ) ;
F_20 ( V_4 -> V_6 ,
V_4 -> V_126 + V_127 , V_70 ) ;
}
bool F_44 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_4 V_70 ;
if ( ! F_42 ( V_4 ) )
return false ;
F_19 ( V_4 -> V_6 , V_4 -> V_126 + V_127 ,
& V_70 ) ;
return ( V_70 & V_129 ) == V_129 ;
}
void F_45 ( void * V_17 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_4 V_70 ;
if ( ! F_42 ( V_4 ) )
return;
F_19 ( V_4 -> V_6 , V_4 -> V_126 + V_127 ,
& V_70 ) ;
F_3 ( ( L_5 , V_70 ) ) ;
V_70 &= ~ ( V_128 ) ;
F_20 ( V_4 -> V_6 ,
V_4 -> V_126 + V_127 , V_70 ) ;
}
T_4 F_46 ( void * V_17 , T_4 V_66 , T_4 V_41 )
{
T_2 * V_4 = ( T_2 * ) V_17 ;
T_3 V_33 ;
T_4 V_130 ;
V_33 = V_4 -> V_13 ;
if ( ! V_33 )
return 0 ;
if ( V_66 )
F_20 ( V_4 -> V_6 , V_33 , V_41 ) ;
F_19 ( V_4 -> V_6 , V_33 , & V_130 ) ;
return V_130 ;
}
T_4
F_47 ( void * V_17 , T_4 V_33 , T_4 V_66 , T_4 V_41 , T_5 type )
{
T_4 V_67 = 0 ;
T_2 * V_4 = ( T_2 * ) V_17 ;
V_11 * V_10 = V_4 -> V_3 . V_10 ;
if ( V_66 ) {
F_3 ( ( L_6 , V_33 , V_41 ) ) ;
F_11 ( V_10 , type , V_33 , V_41 ) ;
}
if ( V_4 -> V_1 -> V_60 <= 5 && V_33 == V_131
&& type == V_38 )
return V_67 ;
V_67 = F_8 ( V_10 , type , V_33 ) ;
F_3 ( ( L_7 , V_33 , V_67 ) ) ;
return V_67 ;
}
T_4
F_48 ( void * V_17 , T_4 V_132 , T_4 V_33 , T_4 V_66 ,
T_4 V_41 )
{
T_4 V_67 = 0 ;
T_2 * V_4 = ( T_2 * ) V_17 ;
if ( V_66 ) {
F_3 ( ( L_8 , V_33 , V_41 ) ) ;
F_17 ( V_4 , V_132 , V_33 , V_41 ) ;
}
if ( F_16 ( V_4 , V_132 , V_33 , & V_67 ) )
V_67 = 0xFFFFFFFF ;
F_3 ( ( L_9 , V_132 ,
V_33 , V_67 ) ) ;
return V_67 ;
}
