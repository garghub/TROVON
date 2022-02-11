int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = F_2 ( V_2 , V_4 ) ;
if ( ! ( V_3 & V_5 ) )
return - V_6 ;
F_3 ( V_2 , V_4 , V_7 ) ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_8 = V_9 ;
F_3 ( V_2 , V_4 , V_10 ) ;
do {
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 & V_5 )
break;
F_5 ( V_11 ) ;
V_8 -- ;
} while ( V_8 );
return ( V_8 == 0 ) ? - V_12 : 0 ;
}
int F_6 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_8 = V_9 ;
F_3 ( V_2 , V_4 , V_13 ) ;
do {
V_3 = F_2 ( V_2 , V_4 ) ;
if ( V_3 & V_14 ) {
F_3 ( V_2 , V_4 , V_15 ) ;
break;
}
F_5 ( V_11 ) ;
V_8 -- ;
} while ( V_8 );
return ( V_8 == 0 ) ? - V_12 : 0 ;
}
int F_7 ( struct V_1 * V_2 , T_1 V_16 , T_1 * V_17 )
{
int V_18 ;
V_18 = F_8 ( V_2 , V_19 , V_20 , V_21 ) ;
if ( V_18 )
goto exit;
F_3 ( V_2 , V_19 , V_16 | V_22 ) ;
V_18 = F_8 ( V_2 , V_19 , V_20 , V_21 ) ;
if ( V_18 )
goto exit;
* V_17 = F_2 ( V_2 , V_23 ) ;
exit:
return V_18 ;
}
int F_9 ( struct V_1 * V_2 , T_1 V_16 , T_1 V_17 )
{
int V_18 = 0 ;
V_18 = F_8 ( V_2 , V_19 , V_20 , V_21 ) ;
if ( V_18 )
goto exit;
F_3 ( V_2 , V_23 , V_17 ) ;
F_3 ( V_2 , V_19 , V_16 ) ;
V_18 = F_8 ( V_2 , V_19 , V_20 , V_21 ) ;
if ( V_18 )
goto exit;
exit:
return V_18 ;
}
int F_10 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_9 ( V_2 , 0x00001010 , 1 ) ;
return V_18 ;
}
int F_11 ( struct V_1 * V_2 )
{
T_1 V_24 ;
if ( V_2 -> V_25 < V_2 -> V_26 )
return 1 ;
V_24 = F_2 ( V_2 , V_27 ) ;
if ( ! ( V_24 & ( 1 << ( 8 + V_2 -> V_26 ) ) ) )
return 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_30 , V_18 ;
V_18 = F_13 ( V_2 , V_31 ) ;
if ( V_18 )
return - V_32 ;
for ( V_30 = 0 ; V_30 < V_29 -> V_33 ; V_30 ++ ) {
V_18 =
F_7 ( V_2 , V_2 -> V_34 + V_30 ,
& V_29 -> V_35 [ V_30 ] ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_1 ) ;
break;
}
}
F_15 ( V_2 , V_31 ) ;
return V_18 ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_8 = 100 ;
T_1 V_38 ;
do {
V_38 = F_2 ( V_2 , V_27 ) ;
if ( V_38 & V_39 )
return 0 ;
F_5 ( V_11 ) ;
} while ( -- V_8 );
return - V_12 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_30 , V_18 ;
if ( F_2 ( V_2 , V_4 ) & V_40 )
return - V_6 ;
V_18 = F_13 ( V_2 , V_31 ) ;
if ( V_18 )
return V_18 ;
for ( V_30 = 0 ; V_30 < V_29 -> V_41 ; V_30 ++ ) {
V_18 = F_9 ( V_2 , V_2 -> V_42 + V_30 ,
V_29 -> V_43 [ V_30 ] ) ;
if ( V_18 )
goto V_44;
}
F_3 ( V_2 , V_4 , V_45 ) ;
V_44:
F_15 ( V_2 , V_31 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_28 * V_29 = & V_2 -> V_46 ;
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_2 ) ;
V_29 = & V_2 -> V_46 ;
V_29 -> V_33 = 4 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_3 ) ;
F_19 ( V_2 ) ;
} else {
F_3 ( V_2 , V_47 , ( V_48 << 16 ) ) ;
F_20 ( V_2 -> V_49 , & V_2 -> V_50 , 0 ) ;
}
return V_18 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_18 ;
struct V_28 * V_29 = & V_2 -> V_46 ;
V_29 -> V_33 = 4 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_4 ) ;
F_22 ( V_2 ) ;
} else
F_23 ( & V_2 -> V_51 ) ;
return V_18 ;
}
static void F_24 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
V_29 -> V_33 = 2 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_5 , V_52 ) ;
return;
}
V_2 -> V_53 = V_29 -> V_35 [ 1 ] ;
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_6 ) ;
if ( F_25 ( V_54 , & V_2 -> V_55 ) ) {
V_18 = F_26 ( V_2 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_56 , V_2 -> V_37 ,
L_7 ) ;
return;
} else
F_27 ( V_54 , & V_2 -> V_55 ) ;
}
if ( ! F_25 ( V_57 , & V_2 -> V_55 ) ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_8 ) ;
F_28 ( V_57 , & V_2 -> V_55 ) ;
F_3 ( V_2 , V_47 , ( V_48 << 16 ) ) ;
F_20 ( V_2 -> V_49 ,
& V_2 -> V_58 , 0 ) ;
}
F_29 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
V_29 -> V_33 = 3 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_9 ) ;
F_31 ( V_2 ) ;
}
static int F_32 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
V_29 -> V_33 = 5 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_10 ) ;
else
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_11 ) ;
return V_18 ;
}
static int F_33 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
V_29 -> V_33 = 1 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_12 ) ;
else
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_13 ) ;
return V_18 ;
}
static int F_34 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
V_29 -> V_33 = 6 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_14 ) ;
else {
int V_30 ;
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_15 ) ;
for ( V_30 = 0 ; V_30 < V_29 -> V_33 ; V_30 ++ )
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_16 ,
V_30 , V_29 -> V_35 [ V_30 ] ) ;
}
return V_18 ;
}
static void F_35 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
V_29 -> V_33 = 2 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_17 ) ;
} else {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_18 ,
V_29 -> V_35 [ 1 ] ) ;
V_2 -> V_59 = V_29 -> V_35 [ 1 ] ;
V_18 = F_26 ( V_2 ) ;
if ( V_18 )
F_14 ( V_2 , V_56 , V_2 -> V_37 ,
L_7 ) ;
}
}
static int F_36 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
int V_60 = V_29 -> V_33 ;
V_29 -> V_33 = 1 ;
V_18 = F_12 ( V_2 , V_29 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_3 ) ;
F_19 ( V_2 ) ;
goto V_44;
}
switch ( V_29 -> V_35 [ 0 ] ) {
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_29 -> V_33 = V_60 ;
V_18 = F_12 ( V_2 , V_29 ) ;
return V_18 ;
case V_68 :
V_18 = F_18 ( V_2 ) ;
break;
case V_69 :
case V_70 :
V_18 = F_21 ( V_2 ) ;
break;
case V_71 :
F_24 ( V_2 , V_29 ) ;
break;
case V_72 :
F_30 ( V_2 , V_29 ) ;
break;
case V_73 :
if ( V_29 -> V_43 [ 0 ] == V_74 ) {
V_29 -> V_33 = V_60 ;
V_18 = F_12 ( V_2 , V_29 ) ;
V_29 -> V_35 [ 0 ] = V_62 ;
return V_18 ;
}
F_35 ( V_2 , V_29 ) ;
break;
case V_75 :
F_32 ( V_2 , V_29 ) ;
break;
case V_76 :
F_33 ( V_2 , V_29 ) ;
break;
case V_77 :
if ( V_29 -> V_43 [ 0 ] == V_74 ) {
V_29 -> V_33 = V_60 ;
V_18 = F_12 ( V_2 , V_29 ) ;
V_29 -> V_35 [ 0 ] = V_66 ;
return V_18 ;
}
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_19 ) ;
V_18 = - V_6 ;
F_22 ( V_2 ) ;
break;
case V_78 :
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_20 ) ;
F_22 ( V_2 ) ;
V_18 = - V_6 ;
break;
case V_79 :
F_34 ( V_2 , V_29 ) ;
break;
case V_80 :
break;
default:
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_21 , V_29 -> V_35 [ 0 ] ) ;
}
V_44:
F_3 ( V_2 , V_4 , V_81 ) ;
V_29 -> V_33 = V_60 ;
return V_18 ;
}
static int F_37 ( struct V_1 * V_2 , struct V_28 * V_29 )
{
int V_18 ;
unsigned long V_8 ;
F_38 ( & V_2 -> V_82 ) ;
F_3 ( V_2 , V_47 , ( V_48 << 16 ) ) ;
V_18 = F_17 ( V_2 , V_29 ) ;
if ( V_18 )
goto V_44;
if ( V_29 -> V_43 [ 0 ] == V_83 )
goto V_44;
V_8 = V_84 + V_85 * V_86 ;
do {
V_18 = F_16 ( V_2 ) ;
if ( V_18 )
continue;
V_18 = F_36 ( V_2 , V_29 ) ;
if ( V_18 )
goto V_44;
if ( ( ( V_29 -> V_35 [ 0 ] & 0x0000f000 ) ==
V_62 ) ||
( ( V_29 -> V_35 [ 0 ] & 0x0000f000 ) ==
V_61 ) )
goto V_87;
} while ( F_39 ( V_84 , V_8 ) );
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_22 ) ;
V_18 = - V_12 ;
goto V_44;
V_87:
F_3 ( V_2 , V_4 , V_81 ) ;
if ( ( ( V_29 -> V_35 [ 0 ] & 0x0000f000 ) !=
V_62 ) &&
( ( V_29 -> V_35 [ 0 ] & 0x0000f000 ) !=
V_61 ) ) {
V_18 = - V_6 ;
}
V_44:
F_3 ( V_2 , V_47 , ( V_48 << 16 ) | V_48 ) ;
F_40 ( & V_2 -> V_82 ) ;
return V_18 ;
}
int F_41 ( struct V_1 * V_2 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 = 0 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 1 ;
V_29 -> V_33 = 3 ;
V_29 -> V_43 [ 0 ] = V_89 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_23 ) ;
V_18 = - V_6 ;
}
V_2 -> V_59 = V_29 -> V_35 [ 1 ] ;
return V_18 ;
}
int F_42 ( struct V_1 * V_2 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 = 0 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 1 ;
V_29 -> V_33 = 2 ;
V_29 -> V_43 [ 0 ] = V_90 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_24 ) ;
V_18 = - V_6 ;
}
if ( V_29 -> V_35 [ 1 ] & 1 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_25 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
static int F_43 ( struct V_1 * V_2 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 = 0 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 5 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_91 ;
V_29 -> V_43 [ 1 ] = V_2 -> V_46 . V_35 [ 1 ] ;
V_29 -> V_43 [ 2 ] = V_2 -> V_46 . V_35 [ 2 ] ;
V_29 -> V_43 [ 3 ] = V_2 -> V_46 . V_35 [ 3 ] ;
V_29 -> V_43 [ 4 ] = V_2 -> V_46 . V_35 [ 4 ] ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_26 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
int F_44 ( struct V_1 * V_2 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 = 0 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 3 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_92 ;
V_29 -> V_43 [ 1 ] = V_2 -> V_93 ;
V_29 -> V_43 [ 2 ] = V_2 -> V_94 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] == V_61 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_27 ) ;
} else if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_28 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
static int F_45 ( struct V_1 * V_2 , T_2 V_95 , T_1 V_96 ,
T_1 V_97 )
{
int V_18 = 0 ;
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 9 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_98 ;
V_29 -> V_43 [ 1 ] = F_46 ( V_96 ) ;
V_29 -> V_43 [ 2 ] = F_47 ( V_95 ) ;
V_29 -> V_43 [ 3 ] = F_46 ( V_95 ) ;
V_29 -> V_43 [ 4 ] = F_47 ( V_97 ) ;
V_29 -> V_43 [ 5 ] = F_46 ( V_97 ) ;
V_29 -> V_43 [ 6 ] = F_47 ( F_48 ( V_95 ) ) ;
V_29 -> V_43 [ 7 ] = F_46 ( F_48 ( V_95 ) ) ;
V_29 -> V_43 [ 8 ] = F_47 ( V_96 ) ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_29 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
int F_49 ( struct V_1 * V_2 , void * V_99 ,
T_1 V_100 , int V_101 )
{
int V_18 ;
char * V_102 ;
T_3 V_103 ;
V_102 = F_50 ( V_2 -> V_104 , V_101 * sizeof( T_1 ) ,
& V_103 ) ;
if ( ! V_102 )
return - V_6 ;
V_18 = F_45 ( V_2 , V_103 , V_100 , V_101 ) ;
if ( ! V_18 )
memcpy ( V_99 , V_102 , V_101 * sizeof( T_1 ) ) ;
F_51 ( V_2 -> V_104 , V_101 * sizeof( T_1 ) , V_102 ,
V_103 ) ;
return V_18 ;
}
int F_52 ( struct V_1 * V_2 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 = 0 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 1 ;
V_29 -> V_33 = 3 ;
V_29 -> V_43 [ 0 ] = V_105 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_30 ) ;
V_18 = - V_6 ;
} else {
F_53 ( V_2 , V_36 , V_106 , V_2 -> V_37 ,
L_31 ) ;
V_2 -> V_93 = V_29 -> V_35 [ 1 ] ;
V_2 -> V_94 = V_29 -> V_35 [ 2 ] ;
}
return V_18 ;
}
int F_54 ( struct V_1 * V_2 , T_1 V_107 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 2 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_108 ;
V_29 -> V_43 [ 1 ] = V_107 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_32 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
int F_55 ( struct V_1 * V_2 , T_1 V_109 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 ;
T_4 * V_96 = V_2 -> V_37 -> V_110 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 8 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_111 ;
if ( V_109 ) {
V_29 -> V_43 [ 1 ] = ( T_1 ) V_96 [ 0 ] ;
V_29 -> V_43 [ 2 ] = ( T_1 ) V_96 [ 1 ] ;
V_29 -> V_43 [ 3 ] = ( T_1 ) V_96 [ 2 ] ;
V_29 -> V_43 [ 4 ] = ( T_1 ) V_96 [ 3 ] ;
V_29 -> V_43 [ 5 ] = ( T_1 ) V_96 [ 4 ] ;
V_29 -> V_43 [ 6 ] = ( T_1 ) V_96 [ 5 ] ;
V_29 -> V_43 [ 7 ] = 0 ;
} else {
V_29 -> V_43 [ 1 ] = 0 ;
V_29 -> V_43 [ 2 ] = 1 ;
V_29 -> V_43 [ 3 ] = 1 ;
V_29 -> V_43 [ 4 ] = 1 ;
V_29 -> V_43 [ 5 ] = 1 ;
V_29 -> V_43 [ 6 ] = 1 ;
V_29 -> V_43 [ 7 ] = 0 ;
}
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_32 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
static int F_56 ( struct V_1 * V_2 )
{
int V_18 = - V_12 ;
long V_112 = 1 * V_85 ;
struct V_28 * V_29 = & V_2 -> V_46 ;
do {
V_112 =
F_57 ( & V_2 -> V_51 ,
V_112 ) ;
if ( ! V_112 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_33 ) ;
break;
}
if ( V_29 -> V_35 [ 0 ] == V_70 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_34 ) ;
V_112 += ( V_29 -> V_35 [ 1 ] >> 8 ) & 0x0000000f ;
} else if ( V_29 -> V_35 [ 0 ] == V_69 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_35 ) ;
V_18 = 0 ;
break;
} else {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_36 ,
V_29 -> V_35 [ 0 ] ) ;
V_18 = - V_6 ;
break;
}
} while ( V_112 );
return V_18 ;
}
int F_58 ( struct V_1 * V_2 , T_1 V_113 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 2 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_114 ;
V_29 -> V_43 [ 1 ] = V_113 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_37 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
int F_59 ( struct V_1 * V_2 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 1 ;
V_29 -> V_33 = 2 ;
V_29 -> V_43 [ 0 ] = V_115 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] != V_62 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_38 ) ;
V_18 = - V_6 ;
} else
V_2 -> V_113 = V_29 -> V_35 [ 1 ] ;
return V_18 ;
}
int F_60 ( struct V_1 * V_2 , T_1 V_116 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_41 = 1 ;
V_29 -> V_33 = 2 ;
V_29 -> V_43 [ 0 ] = V_117 ;
V_29 -> V_43 [ 1 ] = V_116 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] == V_62 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] == V_63 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_39 ) ;
V_18 = - V_118 ;
} else if ( V_29 -> V_35 [ 0 ] == V_66 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_40 ) ;
}
return V_18 ;
}
static int F_61 ( struct V_1 * V_2 , T_1 * V_116 )
{
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_18 ;
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
* V_116 = 0 ;
V_29 -> V_41 = 1 ;
V_29 -> V_33 = 1 ;
V_29 -> V_43 [ 0 ] = V_119 ;
V_18 = F_37 ( V_2 , V_29 ) ;
if ( V_18 )
return V_18 ;
if ( V_29 -> V_35 [ 0 ] == V_62 ) {
* V_116 = V_29 -> V_43 [ 1 ] ;
return V_18 ;
}
if ( V_29 -> V_35 [ 0 ] == V_63 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_39 ) ;
V_18 = - V_118 ;
} else if ( V_29 -> V_35 [ 0 ] == V_66 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_41 ) ;
V_18 = - V_6 ;
}
return V_18 ;
}
int F_62 ( struct V_1 * V_2 )
{
int V_8 = 5 ;
T_1 V_120 ;
T_1 V_121 ;
do {
V_121 = F_2 ( V_2 , V_27 ) & V_122 ;
F_61 ( V_2 , & V_120 ) ;
V_120 &= V_123 ;
if ( V_121 && V_120 )
return 0 ;
F_63 ( 100 ) ;
} while ( V_8 -- > 0 );
return - V_12 ;
}
static int F_64 ( struct V_1 * V_2 )
{
int V_18 ;
V_18 = F_44 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_56 ( V_2 ) ;
return V_18 ;
}
void F_65 ( struct V_124 * V_125 )
{
struct V_1 * V_2 =
F_66 ( V_125 , struct V_1 , V_58 . V_125 ) ;
int V_18 ;
V_18 = F_52 ( V_2 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_42 ) ;
goto V_126;
}
if ( V_2 -> V_93 & V_127 &&
V_2 -> V_94 ==
V_128 )
goto V_44;
V_2 -> V_93 |= V_127 ;
V_2 -> V_94 = V_128 ;
V_18 = F_64 ( V_2 ) ;
if ( V_18 ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_43 ) ;
goto V_126;
}
V_44:
F_27 ( V_57 , & V_2 -> V_55 ) ;
return;
V_126:
F_22 ( V_2 ) ;
goto V_44;
}
void F_67 ( struct V_124 * V_125 )
{
struct V_1 * V_2 =
F_66 ( V_125 , struct V_1 , V_50 . V_125 ) ;
int V_18 ;
struct V_28 * V_29 = & V_2 -> V_46 ;
T_1 V_129 ;
int V_130 ;
V_129 = V_29 -> V_35 [ 1 ] >> 16 ;
V_130 = ( V_29 -> V_35 [ 1 ] >> 8 ) & 0xf ;
switch ( V_129 ) {
default:
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_44 ) ;
break;
case V_131 :
case V_132 :
F_31 ( V_2 ) ;
case V_92 :
F_28 ( V_54 , & V_2 -> V_55 ) ;
if ( V_130 ) {
V_18 = F_43 ( V_2 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_45 ) ;
} else {
F_53 ( V_2 , V_36 , V_106 , V_2 -> V_37 ,
L_46 ) ;
V_18 = 0 ;
}
break;
case V_133 :
case V_134 :
F_31 ( V_2 ) ;
F_28 ( V_54 , & V_2 -> V_55 ) ;
case V_135 :
case V_136 :
case V_137 :
case V_138 :
case V_139 :
case V_140 :
if ( V_130 ) {
V_18 = F_43 ( V_2 ) ;
if ( V_18 )
F_14 ( V_2 , V_36 , V_2 -> V_37 ,
L_45 ) ;
} else {
F_53 ( V_2 , V_36 , V_106 , V_2 -> V_37 ,
L_46 ) ;
V_18 = 0 ;
}
break;
}
}
void F_68 ( struct V_124 * V_125 )
{
struct V_1 * V_2 =
F_66 ( V_125 , struct V_1 , V_141 . V_125 ) ;
struct V_28 V_88 ;
struct V_28 * V_29 = & V_88 ;
int V_126 = 0 ;
F_38 ( & V_2 -> V_82 ) ;
F_3 ( V_2 , V_47 , ( V_48 << 16 ) ) ;
while ( F_2 ( V_2 , V_27 ) & V_39 ) {
memset ( V_29 , 0 , sizeof( struct V_28 ) ) ;
V_29 -> V_33 = 1 ;
V_126 = F_36 ( V_2 , V_29 ) ;
if ( V_126 )
break;
}
F_3 ( V_2 , V_47 , ( V_48 << 16 ) | V_48 ) ;
F_40 ( & V_2 -> V_82 ) ;
F_69 ( V_2 , 0 ) ;
}
void F_70 ( struct V_124 * V_125 )
{
struct V_1 * V_2 =
F_66 ( V_125 , struct V_1 , V_142 . V_125 ) ;
F_71 ( & V_2 -> V_141 ) ;
F_71 ( & V_2 -> V_58 ) ;
F_71 ( & V_2 -> V_50 ) ;
if ( ! F_11 ( V_2 ) ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_47 ) ;
return;
}
if ( ! F_72 ( V_2 , V_2 -> V_143 ) ) {
F_14 ( V_2 , V_36 , V_2 -> V_37 , L_48 ) ;
V_2 -> V_144 = 1 ;
F_20 ( V_2 -> V_49 ,
& V_2 -> V_145 , 5 * V_85 ) ;
}
F_10 ( V_2 ) ;
}
