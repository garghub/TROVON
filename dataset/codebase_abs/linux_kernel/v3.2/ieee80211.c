T_1 F_1 ( T_2 * V_1 )
{
T_3 V_2 = 0 ;
while ( V_1 [ V_2 ] != 0 ) {
if ( ( ( ( V_1 [ V_2 ] ) & 0x7f ) == 2 ) || ( ( ( V_1 [ V_2 ] ) & 0x7f ) == 4 ) ||
( ( ( V_1 [ V_2 ] ) & 0x7f ) == 11 ) || ( ( ( V_1 [ V_2 ] ) & 0x7f ) == 22 ) )
return true ;
V_2 ++ ;
}
return false ;
}
T_1 F_2 ( T_2 * V_1 )
{
T_3 V_2 = 0 ;
while ( V_1 [ V_2 ] != 0 ) {
if ( ( ( ( V_1 [ V_2 ] ) & 0x7f ) != 2 ) && ( ( ( V_1 [ V_2 ] ) & 0x7f ) != 4 ) &&
( ( ( V_1 [ V_2 ] ) & 0x7f ) != 11 ) && ( ( ( V_1 [ V_2 ] ) & 0x7f ) != 22 ) )
return false ;
V_2 ++ ;
}
return true ;
}
T_2 * F_3 ( T_2 * V_3 , T_4 V_4 , T_1 V_5 , T_2 * V_6 , T_1 * V_7 )
{
* V_3 = ( T_2 ) V_4 ;
* ( V_3 + 1 ) = ( T_2 ) V_5 ;
if ( V_5 > 0 )
memcpy ( ( void * ) ( V_3 + 2 ) , ( void * ) V_6 , V_5 ) ;
* V_7 = * V_7 + ( V_5 + 2 ) ;
return V_3 + V_5 + 2 ;
}
T_2 * F_4 ( T_2 * V_3 , T_4 V_4 , T_4 * V_5 , T_4 V_8 )
{
T_4 V_9 , V_2 ;
T_2 * V_10 ;
if ( V_8 < 1 )
return NULL ;
V_10 = V_3 ;
V_2 = 0 ;
* V_5 = 0 ;
while ( 1 ) {
if ( * V_10 == V_4 ) {
* V_5 = * ( V_10 + 1 ) ;
return V_10 ;
} else {
V_9 = * ( V_10 + 1 ) ;
V_10 += ( V_9 + 2 ) ;
V_2 += ( V_9 + 2 ) ;
}
if ( V_2 >= V_8 )
break;
}
return NULL ;
}
static void F_5 ( T_2 * V_11 , T_1 V_12 )
{
memset ( V_11 , 0 , V_13 ) ;
switch ( V_12 ) {
case V_14 :
memcpy ( V_11 , V_15 ,
V_16 ) ;
break;
case V_17 :
case V_18 :
memcpy ( V_11 , V_19 ,
V_20 ) ;
break;
case V_21 :
memcpy ( V_11 , V_15 , V_16 ) ;
memcpy ( V_11 + V_16 , V_19 ,
V_20 ) ;
break;
}
}
static T_1 F_6 ( T_2 * V_22 )
{
T_1 V_2 = 0 ;
while ( 1 ) {
if ( ( V_22 [ V_2 ] ) == 0 )
break;
if ( V_2 > 12 )
break;
V_2 ++ ;
}
return V_2 ;
}
int F_7 ( struct V_23 * V_24 )
{
int V_25 = 0 , V_26 ;
struct V_27 * V_28 = & V_24 -> V_29 ;
T_2 * V_30 = V_28 -> V_31 ;
V_25 += 8 ;
V_30 += V_25 ;
* ( V_32 * ) V_30 = F_8 ( ( V_32 ) V_28 -> V_33 . V_34 ) ;
V_25 += 2 ;
V_30 += 2 ;
* ( V_32 * ) V_30 = 0 ;
* ( V_32 * ) V_30 |= F_8 ( V_35 ) ;
if ( V_24 -> V_36 == V_37 )
* ( V_32 * ) V_30 |= F_8 ( V_38 ) ;
if ( V_28 -> V_39 )
* ( V_32 * ) V_30 |= F_8 ( V_40 ) ;
V_25 += 2 ;
V_30 += 2 ;
V_30 = F_3 ( V_30 , V_41 , V_28 -> V_42 . V_43 ,
V_28 -> V_42 . V_42 , & V_25 ) ;
F_5 ( V_28 -> V_11 ,
V_24 -> V_44 ) ;
V_26 = F_6 ( V_28 -> V_11 ) ;
if ( V_26 > 8 ) {
V_30 = F_3 ( V_30 , V_45 , 8 ,
V_28 -> V_11 , & V_25 ) ;
V_30 = F_3 ( V_30 , V_46 , ( V_26 - 8 ) ,
( V_28 -> V_11 + 8 ) , & V_25 ) ;
} else
V_30 = F_3 ( V_30 , V_45 ,
V_26 , V_28 -> V_11 , & V_25 ) ;
V_30 = F_3 ( V_30 , V_47 , 1 ,
( T_2 * ) & ( V_28 -> V_33 . V_48 ) , & V_25 ) ;
V_30 = F_3 ( V_30 , V_49 , 2 ,
( T_2 * ) & ( V_28 -> V_33 . V_50 ) , & V_25 ) ;
return V_25 ;
}
unsigned char * F_9 ( unsigned char * V_51 , int * V_52 , int V_8 )
{
int V_5 ;
V_32 V_53 ;
unsigned char V_54 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
T_2 * V_3 = V_51 ;
while ( 1 ) {
V_3 = F_4 ( V_3 , V_55 , & V_5 , V_8 ) ;
if ( V_3 ) {
if ( memcmp ( ( V_3 + 2 ) , V_54 ,
sizeof( V_54 ) ) )
goto V_56;
memcpy ( ( T_2 * ) & V_53 , ( V_3 + 6 ) , sizeof( V_53 ) ) ;
V_53 = F_10 ( V_53 ) ;
if ( V_53 != 0x0001 )
goto V_56;
* V_52 = * ( V_3 + 1 ) ;
return V_3 ;
} else {
* V_52 = 0 ;
return NULL ;
}
V_56:
V_8 = V_8 - ( V_3 - V_51 ) - 2 - V_5 ;
if ( V_8 <= 0 )
break;
V_3 += ( 2 + V_5 ) ;
}
* V_52 = 0 ;
return NULL ;
}
unsigned char * F_11 ( unsigned char * V_51 , int * V_57 , int V_8 )
{
return F_4 ( V_51 , V_58 , V_57 , V_8 ) ;
}
static int F_12 ( T_2 * V_59 )
{
if ( ! memcmp ( V_59 , ( void * ) V_60 , V_61 ) )
return V_62 ;
if ( ! memcmp ( V_59 , ( void * ) V_63 , V_61 ) )
return V_64 ;
if ( ! memcmp ( V_59 , ( void * ) V_65 , V_61 ) )
return V_66 ;
if ( ! memcmp ( V_59 , ( void * ) V_67 , V_61 ) )
return V_68 ;
if ( ! memcmp ( V_59 , ( void * ) V_69 , V_61 ) )
return V_70 ;
return 0 ;
}
static int F_13 ( T_2 * V_59 )
{
if ( ! memcmp ( V_59 , ( void * ) V_71 , V_72 ) )
return V_62 ;
if ( ! memcmp ( V_59 , ( void * ) V_73 , V_72 ) )
return V_64 ;
if ( ! memcmp ( V_59 , ( void * ) V_74 , V_72 ) )
return V_66 ;
if ( ! memcmp ( V_59 , ( void * ) V_75 , V_72 ) )
return V_68 ;
if ( ! memcmp ( V_59 , ( void * ) V_76 , V_72 ) )
return V_70 ;
return 0 ;
}
int F_14 ( T_2 * V_77 , int V_52 , int * V_78 ,
int * V_79 )
{
int V_2 , V_80 = V_81 ;
int V_82 , V_83 ;
T_2 * V_84 ;
if ( V_52 <= 0 ) {
return V_85 ;
}
if ( ( * V_77 != V_55 ) || ( * ( V_77 + 1 ) != ( T_2 ) ( V_52 - 2 ) )
|| ( memcmp ( V_77 + 2 , ( void * ) V_86 , V_61 ) ) )
return V_85 ;
V_84 = V_77 ;
V_84 += 8 ;
V_82 = V_52 - 8 ;
if ( V_82 >= V_61 ) {
* V_78 = F_12 ( V_84 ) ;
V_84 += V_61 ;
V_82 -= V_61 ;
} else if ( V_82 > 0 )
return V_85 ;
if ( V_82 >= 2 ) {
V_83 = F_10 ( * ( V_32 * ) V_84 ) ;
V_84 += 2 ;
V_82 -= 2 ;
if ( V_83 == 0 || V_82 < V_83 * V_61 )
return V_85 ;
for ( V_2 = 0 ; V_2 < V_83 ; V_2 ++ ) {
* V_79 |= F_12 ( V_84 ) ;
V_84 += V_61 ;
V_82 -= V_61 ;
}
} else if ( V_82 == 1 )
return V_85 ;
return V_80 ;
}
int F_15 ( T_2 * V_87 , int V_57 , int * V_78 ,
int * V_79 )
{
int V_2 , V_80 = V_81 ;
int V_82 , V_83 ;
T_2 * V_84 ;
if ( V_57 <= 0 ) {
return V_85 ;
}
if ( ( * V_87 != V_58 ) || ( * ( V_87 + 1 ) != ( T_2 ) ( V_57 - 2 ) ) )
return V_85 ;
V_84 = V_87 ;
V_84 += 4 ;
V_82 = V_57 - 4 ;
if ( V_82 >= V_72 ) {
* V_78 = F_13 ( V_84 ) ;
V_84 += V_72 ;
V_82 -= V_72 ;
} else if ( V_82 > 0 )
return V_85 ;
if ( V_82 >= 2 ) {
V_83 = F_10 ( * ( V_32 * ) V_84 ) ;
V_84 += 2 ;
V_82 -= 2 ;
if ( V_83 == 0 || V_82 < V_83 * V_72 )
return V_85 ;
for ( V_2 = 0 ; V_2 < V_83 ; V_2 ++ ) {
* V_79 |= F_13 ( V_84 ) ;
V_84 += V_72 ;
V_82 -= V_72 ;
}
} else if ( V_82 == 1 )
return V_85 ;
return V_80 ;
}
int F_16 ( T_2 * V_88 , T_1 V_89 , T_2 * V_87 , V_32 * V_90 ,
T_2 * V_77 , V_32 * V_91 )
{
T_2 V_92 , V_93 ;
T_2 V_94 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x01 } ;
T_1 V_95 ;
V_95 = ( V_96 + V_97 + V_98 ) ;
V_93 = 0 ;
while ( V_95 < V_89 ) {
V_92 = V_88 [ V_95 ] ;
if ( ( V_92 == V_55 ) &&
( ! memcmp ( & V_88 [ V_95 + 2 ] , & V_94 [ 0 ] , 4 ) ) ) {
memcpy ( V_77 , & V_88 [ V_95 ] , V_88 [ V_95 + 1 ] + 2 ) ;
* V_91 = V_88 [ V_95 + 1 ] + 2 ;
V_95 += V_88 [ V_95 + 1 ] + 2 ;
} else {
if ( V_92 == V_58 ) {
memcpy ( V_87 , & V_88 [ V_95 ] ,
V_88 [ V_95 + 1 ] + 2 ) ;
* V_90 = V_88 [ V_95 + 1 ] + 2 ;
V_95 += V_88 [ V_95 + 1 ] + 2 ;
} else
V_95 += V_88 [ V_95 + 1 ] + 2 ;
}
}
return * V_90 + * V_91 ;
}
int F_17 ( T_2 * V_88 , T_1 V_89 , T_2 * V_99 , T_1 * V_100 )
{
int V_101 ;
T_1 V_95 ;
T_2 V_102 , V_103 [ 4 ] = { 0x0 , 0x50 , 0xf2 , 0x04 } ;
V_95 = 12 ;
V_101 = false ;
while ( V_95 < V_89 ) {
V_102 = V_88 [ V_95 ] ;
if ( ( V_102 == V_55 ) &&
( ! memcmp ( & V_88 [ V_95 + 2 ] , V_103 , 4 ) ) ) {
memcpy ( V_99 , & V_88 [ V_95 ] , V_88 [ V_95 + 1 ] + 2 ) ;
* V_100 = V_88 [ V_95 + 1 ] + 2 ;
V_95 += V_88 [ V_95 + 1 ] + 2 ;
V_101 = true ;
break;
} else
V_95 += V_88 [ V_95 + 1 ] + 2 ;
}
return V_101 ;
}
