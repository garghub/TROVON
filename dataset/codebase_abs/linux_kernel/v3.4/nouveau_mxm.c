static T_1 *
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
return V_4 -> V_6 ;
}
static T_2
F_2 ( struct V_1 * V_2 )
{
T_1 * V_6 = F_1 ( V_2 ) ;
T_2 V_7 = ( V_6 [ 4 ] << 8 ) | V_6 [ 5 ] ;
switch ( V_7 ) {
case 0x0200 :
case 0x0201 :
case 0x0300 :
return V_7 ;
default:
break;
}
F_3 ( V_2 , L_1 , V_6 [ 4 ] , V_6 [ 5 ] ) ;
return 0x0000 ;
}
static T_2
F_4 ( struct V_1 * V_2 )
{
return 8 ;
}
static T_2
F_5 ( struct V_1 * V_2 )
{
return * ( T_2 * ) & F_1 ( V_2 ) [ 6 ] ;
}
static bool
F_6 ( struct V_1 * V_2 )
{
T_2 V_8 = F_4 ( V_2 ) + F_5 ( V_2 ) ;
T_1 * V_6 = F_1 ( V_2 ) , V_9 = 0 ;
while ( V_8 -- )
V_9 += * V_6 ++ ;
if ( V_9 ) {
F_3 ( V_2 , L_2 ) ;
return false ;
}
return true ;
}
static bool
F_7 ( struct V_1 * V_2 )
{
T_1 * V_6 = F_1 ( V_2 ) ;
if ( * ( V_10 * ) V_6 != 0x5f4d584d ) {
F_3 ( V_2 , L_3 ) ;
return false ;
}
if ( ! F_2 ( V_2 ) || ! F_6 ( V_2 ) )
return false ;
return true ;
}
static bool
F_8 ( struct V_1 * V_2 , T_1 V_11 ,
bool (* F_9)( struct V_1 * , T_1 * , void * ) , void * V_12 )
{
T_1 * V_6 = F_1 ( V_2 ) ;
T_1 * V_13 = V_6 + F_4 ( V_2 ) ;
T_1 * V_14 = V_13 + F_5 ( V_2 ) - 1 ;
while ( V_13 < V_14 ) {
T_1 type = V_13 [ 0 ] & 0x0f ;
T_1 V_15 = 0 ;
T_1 V_16 = 0 ;
T_1 V_17 = 0 ;
switch ( type ) {
case 0 :
if ( F_2 ( V_2 ) >= 0x0300 )
V_15 = 8 ;
else
V_15 = 6 ;
break;
case 1 :
case 2 :
case 3 :
V_15 = 4 ;
break;
case 4 :
V_15 = 4 ;
V_16 = 2 ;
V_17 = ( F_10 ( V_13 [ 0 ] ) & 0x01f00000 ) >> 20 ;
break;
case 5 :
V_15 = 8 ;
break;
case 6 :
if ( F_2 ( V_2 ) >= 0x0300 ) {
V_15 = 4 ;
V_16 = 8 ;
V_17 = ( V_13 [ 1 ] & 0xf0 ) >> 4 ;
} else {
V_15 = 8 ;
}
break;
case 7 :
V_15 = 8 ;
V_16 = 4 ;
V_17 = V_13 [ 1 ] & 0x07 ;
break;
default:
F_3 ( V_2 , L_4 , type ) ;
return false ;
}
if ( ( V_18 & V_19 ) && ( F_9 == NULL ) ) {
static const char * V_20 [] = {
L_5 , L_6 , L_7 , L_8 ,
L_9 , L_10 , L_11 , L_12 ,
} ;
T_1 * V_21 = V_13 ;
int V_22 , V_23 ;
F_3 ( V_2 , L_13 , V_20 [ type ] ) ;
for ( V_23 = V_15 - 1 ; V_23 >= 0 ; V_23 -- )
F_11 ( L_14 , V_21 [ V_23 ] ) ;
F_11 ( L_15 ) ;
V_21 += V_15 ;
for ( V_22 = 0 ; V_22 < V_17 ; V_22 ++ , V_21 += V_16 ) {
F_3 ( V_2 , L_16 ) ;
for ( V_23 = V_16 - 1 ; V_23 >= 0 ; V_23 -- )
F_11 ( L_14 , V_21 [ V_23 ] ) ;
F_11 ( L_15 ) ;
}
}
if ( V_11 & ( 1 << type ) ) {
if ( ! F_9 ( V_2 , V_13 , V_12 ) )
return false ;
}
V_13 += V_15 + ( V_17 * V_16 ) ;
}
return true ;
}
static T_1 *
F_12 ( struct V_1 * V_2 , T_1 * V_8 )
{
struct V_24 V_25 ;
if ( F_13 ( V_2 , 'x' , & V_25 ) ) {
F_3 ( V_2 , L_17 ) ;
return NULL ;
}
if ( V_25 . V_7 != 1 || V_25 . V_26 < 3 ) {
F_14 ( V_2 , L_18 ,
V_25 . V_7 , V_25 . V_26 ) ;
return NULL ;
}
* V_8 = V_25 . V_26 ;
return V_25 . V_27 ;
}
static T_1
F_15 ( struct V_1 * V_2 , T_1 V_28 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_29 , * V_30 = F_12 ( V_2 , & V_29 ) ;
if ( V_30 && V_29 >= 6 ) {
T_1 * V_31 = F_16 ( V_2 , V_30 [ 4 ] ) ;
if ( V_31 ) {
if ( V_31 [ 0 ] == 0x10 ) {
if ( V_28 < V_31 [ 3 ] )
return V_31 [ V_31 [ 1 ] + V_28 ] ;
return 0x00 ;
}
F_14 ( V_2 , L_19 , V_31 [ 0 ] ) ;
}
}
if ( V_4 -> V_32 == 0x84 || V_4 -> V_32 == 0x86 )
return V_33 [ V_28 ] ;
if ( V_4 -> V_32 == 0x92 )
return V_34 [ V_28 ] ;
if ( V_4 -> V_32 == 0x94 )
return V_35 [ V_28 ] ;
if ( V_4 -> V_32 == 0x96 )
return V_36 [ V_28 ] ;
if ( V_4 -> V_32 == 0x98 )
return V_37 [ V_28 ] ;
F_14 ( V_2 , L_20 ) ;
return 0x00 ;
}
static T_1
F_17 ( struct V_1 * V_2 , T_1 V_38 )
{
T_1 V_29 , * V_30 = F_12 ( V_2 , & V_29 ) ;
if ( V_30 && V_29 >= 8 ) {
T_1 * V_31 = F_16 ( V_2 , V_30 [ 6 ] ) ;
if ( V_31 ) {
if ( V_31 [ 0 ] == 0x10 ) {
if ( V_38 < V_31 [ 3 ] )
return V_31 [ V_31 [ 1 ] + V_38 ] ;
return 0x00 ;
}
F_14 ( V_2 , L_21 , V_31 [ 0 ] ) ;
}
}
return ( V_38 << 4 ) | V_38 ;
}
static void
F_18 ( struct V_1 * V_2 , T_1 * V_39 , struct V_40 * V_13 )
{
T_3 V_27 = F_10 ( V_39 [ 0 ] ) ;
if ( F_2 ( V_2 ) >= 0x0300 )
V_27 |= ( T_3 ) F_19 ( V_39 [ 4 ] ) << 32 ;
V_13 -> V_41 = ( V_27 & 0x00000000000000f0ULL ) >> 4 ;
V_13 -> V_42 = ( V_27 & 0x0000000000000f00ULL ) >> 8 ;
V_13 -> V_43 = ( V_27 & 0x000000000001f000ULL ) >> 12 ;
V_13 -> V_44 = ( V_27 & 0x0000000000780000ULL ) >> 19 ;
}
static bool
F_20 ( struct V_1 * V_2 , T_1 * V_27 , void * V_12 )
{
struct V_45 * V_46 = V_12 ;
struct V_40 V_13 ;
F_18 ( V_2 , V_27 , & V_13 ) ;
if ( V_13 . V_41 == 2 &&
V_13 . V_44 == V_46 -> V_13 . V_44 )
return false ;
return true ;
}
static bool
F_21 ( struct V_1 * V_2 , T_1 * V_27 , void * V_12 )
{
struct V_45 * V_46 = V_12 ;
T_3 V_13 = * ( T_3 * ) V_27 ;
F_18 ( V_2 , V_27 , & V_46 -> V_13 ) ;
if ( ( V_46 -> V_47 [ 0 ] & 0x0000000f ) != V_46 -> V_13 . V_41 )
return true ;
if ( ( V_13 & 0x00000000000000f0 ) >= 0x20 ) {
T_1 V_48 = F_15 ( V_2 , V_46 -> V_13 . V_44 ) ;
if ( ( V_46 -> V_47 [ 0 ] & 0x0f000000 ) != ( V_48 & 0x0f ) << 24 )
return true ;
V_48 = ( V_48 & 0x30 ) >> 4 ;
if ( ( V_48 & ( ( V_46 -> V_47 [ 1 ] & 0x00000030 ) >> 4 ) ) != V_48 )
return true ;
}
V_27 [ 0 ] &= ~ 0xf0 ;
if ( V_46 -> V_13 . V_41 == 6 && V_46 -> V_13 . V_43 == 6 &&
F_8 ( V_2 , 0x01 , F_20 , V_46 ) ) {
V_27 [ 0 ] |= 0x20 ;
} else {
V_27 [ 0 ] |= 0xf0 ;
}
return false ;
}
static int
F_22 ( struct V_1 * V_2 , void * V_27 , int V_49 , T_1 * V_50 )
{
struct V_45 V_46 = { . V_47 = ( V_10 * ) V_50 } ;
T_1 type , V_51 , V_48 ;
T_1 * V_28 ;
if ( F_8 ( V_2 , 0x01 , F_21 , & V_46 ) ) {
F_3 ( V_2 , L_22 ,
V_49 , V_46 . V_47 [ 0 ] , V_46 . V_47 [ 1 ] ) ;
V_46 . V_47 [ 0 ] |= 0x0000000f ;
return 0 ;
}
V_51 = F_17 ( V_2 , V_46 . V_13 . V_42 ) ;
if ( ( V_46 . V_47 [ 0 ] & 0x0000000f ) != V_52 )
V_51 = ( V_51 & 0x0f ) << 4 ;
else
V_51 = ( V_51 & 0xf0 ) ;
if ( V_51 != 0xf0 ) {
V_46 . V_47 [ 0 ] &= ~ 0x000000f0 ;
V_46 . V_47 [ 0 ] |= V_51 ;
}
switch ( V_46 . V_13 . V_41 ) {
case 0x00 :
case 0x01 :
break;
default:
V_48 = F_15 ( V_2 , V_46 . V_13 . V_44 ) & 0x30 ;
V_46 . V_47 [ 1 ] &= ~ 0x00000030 ;
V_46 . V_47 [ 1 ] |= V_48 ;
break;
}
V_28 = F_23 ( V_2 , ( V_46 . V_47 [ 0 ] & 0x0000f000 ) >> 12 ) ;
type = V_28 [ 0 ] ;
switch ( V_46 . V_13 . V_43 ) {
case 0x01 :
V_46 . V_47 [ 1 ] |= 0x00000004 ;
break;
case 0x02 :
type = V_53 ;
break;
case 0x03 :
type = V_54 ;
break;
case 0x0e :
V_46 . V_47 [ 1 ] |= 0x00010000 ;
case 0x07 :
V_46 . V_47 [ 1 ] |= 0x00000004 ;
type = V_55 ;
break;
default:
break;
}
if ( F_2 ( V_2 ) >= 0x0300 )
V_28 [ 0 ] = type ;
return 0 ;
}
static bool
F_24 ( struct V_1 * V_2 , T_1 * V_27 , void * V_12 )
{
T_3 V_13 = * ( T_3 * ) V_27 ;
if ( ( V_13 & 0xf0 ) != 0xf0 )
F_14 ( V_2 , L_23 , V_13 ) ;
return true ;
}
static void
F_25 ( struct V_1 * V_2 )
{
T_1 * V_56 = F_26 ( V_2 ) ;
if ( ! V_56 || V_56 [ 0 ] != 0x40 ) {
F_3 ( V_2 , L_24 ) ;
return;
}
F_27 ( V_2 , NULL , F_22 ) ;
F_8 ( V_2 , 0x01 , F_24 , NULL ) ;
}
static bool
F_28 ( struct V_57 * V_58 , T_1 V_59 ,
T_1 V_60 , T_1 V_8 , T_1 * V_27 )
{
struct V_61 V_62 [] = {
{ . V_59 = V_59 , . V_63 = 0 , . V_29 = 1 , . V_64 = & V_60 } ,
{ . V_59 = V_59 , . V_63 = V_65 , . V_29 = V_8 , . V_64 = V_27 , } ,
} ;
return F_29 ( & V_58 -> V_66 , V_62 , 2 ) == 2 ;
}
static bool
F_30 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_57 * V_58 = NULL ;
T_1 V_51 , V_6 [ 6 ] , V_59 , V_8 ;
V_51 = F_17 ( V_2 , 1 ) & 0x0f ;
if ( V_51 < 0x0f )
V_58 = F_31 ( V_2 , V_51 ) ;
if ( ! V_58 )
return false ;
V_59 = 0x54 ;
if ( ! F_28 ( V_58 , V_59 , 0 , 6 , V_6 ) ) {
V_59 = 0x56 ;
if ( ! F_28 ( V_58 , V_59 , 0 , 6 , V_6 ) )
return false ;
}
V_4 -> V_6 = V_6 ;
V_8 = F_4 ( V_2 ) + F_5 ( V_2 ) ;
V_4 -> V_6 = F_32 ( V_8 , V_67 ) ;
if ( V_4 -> V_6 &&
F_28 ( V_58 , V_59 , 0 , V_8 , V_4 -> V_6 ) )
return true ;
F_33 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
return false ;
}
static bool
F_34 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
static char V_68 [] = {
0x00 , 0xA4 , 0x04 , 0x40 , 0x7D , 0x91 , 0xF2 , 0x4C ,
0xB8 , 0x9C , 0x79 , 0xB6 , 0x2F , 0xD5 , 0x56 , 0x65
} ;
V_10 V_69 [] = { 0x00000000 } ;
union V_70 args [ 4 ] = {
{ . V_71 . type = 3 ,
. V_71 . V_26 = sizeof( V_68 ) ,
. V_71 . V_72 = V_68 ,
} ,
{ . integer . type = V_73 ,
. integer . V_74 = ( V_7 & 0xf0 ) << 4 | ( V_7 & 0x0f ) ,
} ,
{ . integer . type = V_73 ,
. integer . V_74 = 0x00000010 ,
} ,
{ . V_71 . type = V_75 ,
. V_71 . V_26 = sizeof( V_69 ) ,
. V_71 . V_72 = ( char * ) V_69 ,
} ,
} ;
struct V_76 V_77 = { F_35 ( args ) , args } ;
struct V_78 V_79 = { V_80 , NULL } ;
union V_70 * V_81 ;
T_4 V_82 ;
int V_83 ;
V_82 = F_36 ( & V_2 -> V_84 -> V_2 ) ;
if ( ! V_82 )
return false ;
V_83 = F_37 ( V_82 , L_25 , & V_77 , & V_79 ) ;
if ( V_83 ) {
F_3 ( V_2 , L_26 , V_83 ) ;
return false ;
}
V_81 = V_79 . V_72 ;
if ( V_81 -> type == V_75 ) {
V_4 -> V_6 = F_38 ( V_81 -> V_71 . V_72 ,
V_81 -> V_71 . V_26 , V_67 ) ;
} else
if ( V_81 -> type == V_73 ) {
F_3 ( V_2 , L_27 , V_81 -> integer . V_74 ) ;
}
F_33 ( V_81 ) ;
return V_4 -> V_6 != NULL ;
}
static T_1
F_39 ( struct V_1 * V_2 , T_1 V_7 )
{
V_10 V_85 [] = { 0x494D584D , V_7 , 0 } ;
struct V_78 args = { sizeof( V_85 ) , V_85 } ;
struct V_78 V_79 = { V_80 , NULL } ;
union V_70 * V_81 ;
T_5 V_86 ;
V_86 = F_40 ( V_87 , 0 , 0 , & args , & V_79 ) ;
if ( F_41 ( V_86 ) ) {
F_3 ( V_2 , L_28 , V_86 ) ;
return 0x00 ;
}
V_81 = V_79 . V_72 ;
if ( V_81 -> type == V_73 ) {
V_7 = V_81 -> integer . V_74 ;
F_3 ( V_2 , L_29 ,
( V_7 >> 4 ) , V_7 & 0x0f ) ;
} else {
V_7 = 0 ;
F_3 ( V_2 , L_30 ) ;
}
F_33 ( V_81 ) ;
return V_7 ;
}
static bool
F_42 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_10 V_69 [] = { 0x534D584D , V_7 , 0 } ;
struct V_78 args = { sizeof( V_69 ) , V_69 } ;
struct V_78 V_79 = { V_80 , NULL } ;
union V_70 * V_81 ;
T_5 V_86 ;
if ( ! F_43 ( V_87 ) ) {
F_3 ( V_2 , L_31 ) ;
return false ;
}
V_69 [ 1 ] = F_39 ( V_2 , 0x00 ) ;
if ( ! V_69 [ 1 ] )
V_69 [ 1 ] = F_39 ( V_2 , V_7 ) ;
if ( ! V_69 [ 1 ] )
return false ;
V_86 = F_40 ( V_87 , 0 , 0 , & args , & V_79 ) ;
if ( F_41 ( V_86 ) ) {
F_3 ( V_2 , L_32 , V_86 ) ;
return false ;
}
V_81 = V_79 . V_72 ;
if ( V_81 -> type == V_75 ) {
V_4 -> V_6 = F_38 ( V_81 -> V_71 . V_72 ,
V_81 -> V_71 . V_26 , V_67 ) ;
}
F_33 ( V_81 ) ;
return V_4 -> V_6 != NULL ;
}
static int
F_44 ( struct V_1 * V_2 , T_1 V_7 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_88 * V_89 = V_90 ;
do {
F_3 ( V_2 , L_33 , V_89 -> V_91 ) ;
if ( V_89 -> F_9 ( V_2 , V_7 ) ) {
if ( F_7 ( V_2 ) )
return 0 ;
F_33 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
} while ( ( ++ V_89 ) -> V_91 );
return - V_92 ;
}
int
F_45 ( struct V_1 * V_2 )
{
T_1 V_93 , * V_30 = F_12 ( V_2 , & V_93 ) ;
if ( ! V_30 || ! V_30 [ 0 ] ) {
F_14 ( V_2 , L_34 ) ;
return 0 ;
}
F_14 ( V_2 , L_35 , V_30 [ 0 ] >> 4 , V_30 [ 0 ] & 0x0f ) ;
if ( F_44 ( V_2 , V_30 [ 0 ] ) ) {
F_14 ( V_2 , L_36 ) ;
#if 0
return -EINVAL;
#else
return 0 ;
#endif
}
F_14 ( V_2 , L_37 ,
F_2 ( V_2 ) >> 8 , F_2 ( V_2 ) & 0xff ) ;
F_8 ( V_2 , 0 , NULL , NULL ) ;
if ( V_94 )
F_25 ( V_2 ) ;
return 0 ;
}
void
F_46 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_33 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
