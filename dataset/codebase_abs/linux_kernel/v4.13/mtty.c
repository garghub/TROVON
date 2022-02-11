static struct V_1 * F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 (mds, &mdev_devices_list, next) {
if ( F_3 ( F_4 ( V_3 -> V_4 ) , V_2 ) == 0 )
return V_3 ;
}
return NULL ;
}
void F_5 ( char * V_5 , T_2 V_6 )
{
#if F_6 ( V_7 )
int V_8 ;
F_7 ( L_1 ) ;
for ( V_8 = 0 ; V_8 < V_6 ; V_8 ++ ) {
F_7 ( L_2 , * ( V_5 + V_8 ) ) ;
if ( ( V_8 + 1 ) % 16 == 0 )
F_7 ( L_3 ) ;
}
#endif
}
static void F_8 ( struct V_1 * V_1 )
{
F_9 ( ( V_9 * ) & V_1 -> V_10 [ 0x0 ] , 0x32534348 ) ;
F_10 ( ( V_11 * ) & V_1 -> V_10 [ 0x4 ] , 0x0001 ) ;
F_10 ( ( V_11 * ) & V_1 -> V_10 [ 0x6 ] , 0x0200 ) ;
V_1 -> V_10 [ 0x8 ] = 0x10 ;
V_1 -> V_10 [ 0x9 ] = 0x02 ;
V_1 -> V_10 [ 0xa ] = 0x00 ;
V_1 -> V_10 [ 0xb ] = 0x07 ;
F_9 ( ( V_9 * ) & V_1 -> V_10 [ 0x10 ] , 0x000001 ) ;
V_1 -> V_12 [ 0 ] = ~ ( V_13 ) + 1 ;
if ( V_1 -> V_14 == 2 ) {
F_9 ( ( V_9 * ) & V_1 -> V_10 [ 0x14 ] , 0x000001 ) ;
V_1 -> V_12 [ 1 ] = ~ ( V_13 ) + 1 ;
}
F_9 ( ( V_9 * ) & V_1 -> V_10 [ 0x2c ] , 0x32534348 ) ;
V_1 -> V_10 [ 0x34 ] = 0x00 ;
V_1 -> V_10 [ 0x3d ] = 0x01 ;
V_1 -> V_10 [ 0x40 ] = 0x23 ;
V_1 -> V_10 [ 0x43 ] = 0x80 ;
V_1 -> V_10 [ 0x44 ] = 0x23 ;
V_1 -> V_10 [ 0x48 ] = 0x23 ;
V_1 -> V_10 [ 0x4c ] = 0x23 ;
V_1 -> V_10 [ 0x60 ] = 0x50 ;
V_1 -> V_10 [ 0x61 ] = 0x43 ;
V_1 -> V_10 [ 0x62 ] = 0x49 ;
V_1 -> V_10 [ 0x63 ] = 0x20 ;
V_1 -> V_10 [ 0x64 ] = 0x53 ;
V_1 -> V_10 [ 0x65 ] = 0x65 ;
V_1 -> V_10 [ 0x66 ] = 0x72 ;
V_1 -> V_10 [ 0x67 ] = 0x69 ;
V_1 -> V_10 [ 0x68 ] = 0x61 ;
V_1 -> V_10 [ 0x69 ] = 0x6c ;
V_1 -> V_10 [ 0x6a ] = 0x2f ;
V_1 -> V_10 [ 0x6b ] = 0x55 ;
V_1 -> V_10 [ 0x6c ] = 0x41 ;
V_1 -> V_10 [ 0x6d ] = 0x52 ;
V_1 -> V_10 [ 0x6e ] = 0x54 ;
}
static void F_11 ( struct V_1 * V_1 , V_11 V_15 ,
char * V_5 , V_9 V_6 )
{
V_9 V_16 , V_12 , V_17 = 0 ;
switch ( V_15 ) {
case 0x04 :
case 0x06 :
break;
case 0x3c :
V_1 -> V_10 [ 0x3c ] = V_5 [ 0 ] ;
break;
case 0x3d :
break;
case 0x10 :
case 0x14 :
if ( V_15 == 0x10 )
V_17 = 0 ;
else if ( V_15 == 0x14 )
V_17 = 1 ;
if ( ( V_1 -> V_14 == 1 ) && ( V_17 == 1 ) ) {
F_9 ( & V_1 -> V_10 [ V_15 ] , 0 ) ;
break;
}
V_16 = * ( V_9 * ) V_5 ;
F_7 ( L_4 , V_17 , V_16 ) ;
if ( V_16 == 0xffffffff ) {
V_12 = V_1 -> V_12 [ V_17 ] ;
V_16 = ( V_16 & V_12 ) ;
}
V_16 |= ( V_1 -> V_10 [ V_15 ] & 0x3ul ) ;
F_9 ( & V_1 -> V_10 [ V_15 ] , V_16 ) ;
break;
case 0x18 :
case 0x1c :
case 0x20 :
F_9 ( & V_1 -> V_10 [ V_15 ] , 0 ) ;
break;
default:
F_7 ( L_5 ,
V_15 , V_6 ) ;
break;
}
}
static void F_12 ( unsigned int V_18 , struct V_1 * V_1 ,
V_11 V_15 , char * V_5 , V_9 V_6 )
{
T_3 V_19 = * V_5 ;
switch ( V_15 ) {
case V_20 :
if ( V_1 -> V_21 [ V_18 ] . V_22 ) {
V_1 -> V_21 [ V_18 ] . V_23 |= V_19 ;
break;
}
F_13 ( & V_1 -> V_24 ) ;
if ( V_1 -> V_21 [ V_18 ] . V_25 . V_6 <
V_1 -> V_21 [ V_18 ] . V_26 ) {
V_1 -> V_21 [ V_18 ] . V_25 . V_27 [
V_1 -> V_21 [ V_18 ] . V_25 . V_28 ] = V_19 ;
V_1 -> V_21 [ V_18 ] . V_25 . V_6 ++ ;
F_14 ( V_1 -> V_21 [ V_18 ] . V_25 . V_28 ) ;
V_1 -> V_21 [ V_18 ] . V_29 = false ;
if ( ( V_1 -> V_21 [ V_18 ] . V_30 [ V_31 ] &
V_32 ) &&
( V_1 -> V_21 [ V_18 ] . V_25 . V_6 ==
V_1 -> V_21 [ V_18 ] . V_33 ) ) {
#if F_6 ( V_34 )
F_15 ( L_6 ,
V_18 ) ;
#endif
F_16 (
F_4 ( V_1 -> V_4 ) ) ;
}
} else {
#if F_6 ( V_34 )
F_15 ( L_7 , V_18 ) ;
#endif
V_1 -> V_21 [ V_18 ] . V_29 = true ;
if ( V_1 -> V_21 [ V_18 ] . V_30 [ V_31 ] &
V_35 )
F_16 (
F_4 ( V_1 -> V_4 ) ) ;
}
F_17 ( & V_1 -> V_24 ) ;
break;
case V_31 :
if ( V_1 -> V_21 [ V_18 ] . V_22 )
V_1 -> V_21 [ V_18 ] . V_23 |= ( V_11 ) V_19 << 8 ;
else {
V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] = V_19 ;
F_13 ( & V_1 -> V_24 ) ;
if ( ( V_19 & V_36 ) &&
( V_1 -> V_21 [ V_18 ] . V_25 . V_28 ==
V_1 -> V_21 [ V_18 ] . V_25 . V_37 ) ) {
#if F_6 ( V_34 )
F_15 ( L_8 ,
V_18 ) ;
#endif
F_16 (
F_4 ( V_1 -> V_4 ) ) ;
}
F_17 ( & V_1 -> V_24 ) ;
}
break;
case V_38 :
V_1 -> V_21 [ V_18 ] . V_39 = V_19 ;
F_13 ( & V_1 -> V_24 ) ;
if ( V_19 & ( V_40 | V_41 ) ) {
V_1 -> V_21 [ V_18 ] . V_25 . V_6 = 0 ;
V_1 -> V_21 [ V_18 ] . V_25 . V_28 = 0 ;
V_1 -> V_21 [ V_18 ] . V_25 . V_37 = 0 ;
}
F_17 ( & V_1 -> V_24 ) ;
switch ( V_19 & V_42 ) {
case V_43 :
V_1 -> V_21 [ V_18 ] . V_33 = 1 ;
break;
case V_44 :
V_1 -> V_21 [ V_18 ] . V_33 = 4 ;
break;
case V_45 :
V_1 -> V_21 [ V_18 ] . V_33 = 8 ;
break;
case V_46 :
V_1 -> V_21 [ V_18 ] . V_33 = 14 ;
break;
}
V_1 -> V_21 [ V_18 ] . V_33 = 1 ;
if ( V_19 & V_47 )
V_1 -> V_21 [ V_18 ] . V_26 = V_48 ;
else {
V_1 -> V_21 [ V_18 ] . V_26 = 1 ;
V_1 -> V_21 [ V_18 ] . V_33 = 1 ;
}
break;
case V_49 :
if ( V_19 & V_50 ) {
V_1 -> V_21 [ V_18 ] . V_22 = true ;
V_1 -> V_21 [ V_18 ] . V_23 = 0 ;
} else
V_1 -> V_21 [ V_18 ] . V_22 = false ;
V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] = V_19 ;
break;
case V_51 :
V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] = V_19 ;
if ( ( V_1 -> V_21 [ V_18 ] . V_30 [ V_31 ] & V_52 ) &&
( V_19 & V_53 ) ) {
#if F_6 ( V_34 )
F_15 ( L_9 , V_18 ) ;
#endif
F_16 ( F_4 ( V_1 -> V_4 ) ) ;
}
if ( ( V_1 -> V_21 [ V_18 ] . V_30 [ V_31 ] & V_52 ) &&
( V_19 & ( V_54 | V_55 ) ) ) {
#if F_6 ( V_34 )
F_15 ( L_10 , V_18 ) ;
#endif
F_16 ( F_4 ( V_1 -> V_4 ) ) ;
}
break;
case V_56 :
case V_57 :
break;
case V_58 :
V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] = V_19 ;
break;
default:
break;
}
}
static void F_18 ( unsigned int V_18 , struct V_1 * V_1 ,
V_11 V_15 , char * V_5 , V_9 V_6 )
{
switch ( V_15 ) {
case V_59 :
if ( V_1 -> V_21 [ V_18 ] . V_22 ) {
* V_5 = ( T_3 ) V_1 -> V_21 [ V_18 ] . V_23 ;
break;
}
F_13 ( & V_1 -> V_24 ) ;
if ( V_1 -> V_21 [ V_18 ] . V_25 . V_28 !=
V_1 -> V_21 [ V_18 ] . V_25 . V_37 ) {
* V_5 = V_1 -> V_21 [ V_18 ] . V_25 . V_27 [
V_1 -> V_21 [ V_18 ] . V_25 . V_37 ] ;
V_1 -> V_21 [ V_18 ] . V_25 . V_6 -- ;
F_14 ( V_1 -> V_21 [ V_18 ] . V_25 . V_37 ) ;
}
if ( V_1 -> V_21 [ V_18 ] . V_25 . V_28 ==
V_1 -> V_21 [ V_18 ] . V_25 . V_37 ) {
#if F_6 ( V_34 )
F_15 ( L_11 , V_18 ) ;
#endif
if ( V_1 -> V_21 [ V_18 ] . V_30 [ V_31 ] &
V_36 )
F_16 (
F_4 ( V_1 -> V_4 ) ) ;
}
F_17 ( & V_1 -> V_24 ) ;
break;
case V_31 :
if ( V_1 -> V_21 [ V_18 ] . V_22 ) {
* V_5 = ( T_3 ) ( V_1 -> V_21 [ V_18 ] . V_23 >> 8 ) ;
break;
}
* V_5 = V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] & 0x0f ;
break;
case V_60 :
{
T_3 V_61 = V_1 -> V_21 [ V_18 ] . V_30 [ V_31 ] ;
* V_5 = 0 ;
F_13 ( & V_1 -> V_24 ) ;
if ( ( V_61 & V_35 ) && V_1 -> V_21 [ V_18 ] . V_29 )
* V_5 |= V_62 ;
if ( ( V_61 & V_32 ) &&
( V_1 -> V_21 [ V_18 ] . V_25 . V_6 ==
V_1 -> V_21 [ V_18 ] . V_33 ) )
* V_5 |= V_63 ;
if ( ( V_61 & V_36 ) &&
( V_1 -> V_21 [ V_18 ] . V_25 . V_28 ==
V_1 -> V_21 [ V_18 ] . V_25 . V_37 ) )
* V_5 |= V_64 ;
if ( ( V_61 & V_52 ) &&
( V_1 -> V_21 [ V_18 ] . V_30 [ V_51 ] &
( V_54 | V_55 ) ) )
* V_5 |= V_65 ;
if ( * V_5 == 0 )
* V_5 = V_66 ;
* V_5 |= 0xC0 ;
F_17 ( & V_1 -> V_24 ) ;
}
break;
case V_49 :
case V_51 :
* V_5 = V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] ;
break;
case V_56 :
{
T_3 V_67 = 0 ;
F_13 ( & V_1 -> V_24 ) ;
if ( V_1 -> V_21 [ V_18 ] . V_25 . V_28 !=
V_1 -> V_21 [ V_18 ] . V_25 . V_37 )
V_67 |= V_68 ;
if ( V_1 -> V_21 [ V_18 ] . V_29 )
V_67 |= V_69 ;
if ( V_1 -> V_21 [ V_18 ] . V_25 . V_28 ==
V_1 -> V_21 [ V_18 ] . V_25 . V_37 )
V_67 |= V_70 | V_71 ;
F_17 ( & V_1 -> V_24 ) ;
* V_5 = V_67 ;
break;
}
case V_57 :
* V_5 = V_72 | V_73 | V_74 ;
F_13 ( & V_1 -> V_24 ) ;
if ( V_1 -> V_21 [ V_18 ] . V_30 [ V_51 ] &
V_75 ) {
if ( V_1 -> V_21 [ V_18 ] . V_25 . V_6 <
V_1 -> V_21 [ V_18 ] . V_26 )
* V_5 |= V_76 | V_77 ;
} else
* V_5 |= V_76 | V_77 ;
F_17 ( & V_1 -> V_24 ) ;
break;
case V_58 :
* V_5 = V_1 -> V_21 [ V_18 ] . V_30 [ V_15 ] ;
break;
default:
break;
}
}
static void F_19 ( struct V_1 * V_1 )
{
int V_18 , V_78 ;
V_9 V_79 , V_80 ;
V_9 V_81 ;
V_78 = V_82 ;
for ( V_18 = 0 ; V_18 <= V_83 ; V_18 ++ ) {
if ( ! V_1 -> V_84 [ V_18 ] . V_85 )
continue;
V_79 = ( * ( V_9 * ) ( V_1 -> V_10 + V_78 ) ) &
V_86 ;
V_81 = ( * ( V_9 * ) ( V_1 -> V_10 + V_78 ) ) &
V_87 ;
switch ( V_81 ) {
case V_88 :
V_80 = ( * ( V_9 * ) ( V_1 -> V_10 + V_78 + 4 ) ) ;
V_78 += 4 ;
break;
case V_89 :
case V_90 :
default:
V_80 = 0 ;
break;
}
V_78 += 4 ;
V_1 -> V_84 [ V_18 ] . V_91 = ( ( V_92 ) V_80 << 32 ) |
V_79 ;
}
}
static T_4 F_20 ( struct V_93 * V_4 , char * V_5 , T_5 V_6 ,
T_6 V_78 , bool V_94 )
{
struct V_1 * V_1 ;
unsigned int V_18 ;
T_6 V_15 ;
int V_95 = 0 ;
if ( ! V_4 || ! V_5 )
return - V_96 ;
V_1 = F_21 ( V_4 ) ;
if ( ! V_1 ) {
F_15 ( L_12 , V_97 ) ;
return - V_96 ;
}
F_13 ( & V_1 -> V_98 ) ;
V_18 = F_22 ( V_78 ) ;
V_15 = V_78 & V_99 ;
switch ( V_18 ) {
case V_100 :
#if F_6 ( V_7 )
F_7 ( L_13 ,
V_97 , V_94 ? L_14 : L_15 , V_15 ) ;
#endif
if ( V_94 ) {
F_5 ( V_5 , V_6 ) ;
F_11 ( V_1 , V_15 , V_5 , V_6 ) ;
} else {
memcpy ( V_5 , ( V_1 -> V_10 + V_15 ) , V_6 ) ;
F_5 ( V_5 , V_6 ) ;
}
break;
case V_101 ... V_83 :
if ( ! V_1 -> V_84 [ V_18 ] . V_91 )
F_19 ( V_1 ) ;
if ( V_94 ) {
F_5 ( V_5 , V_6 ) ;
#if F_6 ( V_102 )
F_7 ( L_16 ,
V_97 , V_18 , V_15 , V_103 [ V_15 ] ,
( T_3 ) * V_5 , V_1 -> V_21 [ V_18 ] . V_22 ) ;
#endif
F_12 ( V_18 , V_1 , V_15 , V_5 , V_6 ) ;
} else {
F_18 ( V_18 , V_1 , V_15 , V_5 , V_6 ) ;
F_5 ( V_5 , V_6 ) ;
#if F_6 ( V_102 )
F_7 ( L_17 ,
V_97 , V_18 , V_15 , V_104 [ V_15 ] ,
( T_3 ) * V_5 , V_1 -> V_21 [ V_18 ] . V_22 ) ;
#endif
}
break;
default:
V_95 = - 1 ;
goto V_105;
}
V_95 = V_6 ;
V_105:
F_17 ( & V_1 -> V_98 ) ;
return V_95 ;
}
int F_23 ( struct V_106 * V_107 , struct V_93 * V_4 )
{
struct V_1 * V_1 ;
char V_108 [ V_109 ] ;
int V_14 = 0 , V_8 ;
if ( ! V_4 )
return - V_96 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
snprintf ( V_108 , V_109 , L_18 ,
F_24 ( F_25 ( V_4 ) ) , V_8 + 1 ) ;
if ( ! strcmp ( V_107 -> V_108 , V_108 ) ) {
V_14 = V_8 + 1 ;
break;
}
}
if ( ! V_14 )
return - V_96 ;
V_1 = F_26 ( sizeof( struct V_1 ) , V_110 ) ;
if ( V_1 == NULL )
return - V_111 ;
V_1 -> V_14 = V_14 ;
V_1 -> V_112 = - 1 ;
V_1 -> V_21 [ 0 ] . V_26 = V_48 ;
V_1 -> V_21 [ 1 ] . V_26 = V_48 ;
F_27 ( & V_1 -> V_24 ) ;
V_1 -> V_10 = F_26 ( V_113 , V_110 ) ;
if ( V_1 -> V_10 == NULL ) {
F_28 ( V_1 ) ;
return - V_111 ;
}
F_27 ( & V_1 -> V_98 ) ;
V_1 -> V_4 = V_4 ;
F_29 ( V_4 , V_1 ) ;
F_8 ( V_1 ) ;
F_13 ( & V_114 ) ;
F_30 ( & V_1 -> V_115 , & V_116 ) ;
F_17 ( & V_114 ) ;
return 0 ;
}
int F_31 ( struct V_93 * V_4 )
{
struct V_1 * V_3 , * V_117 ;
struct V_1 * V_1 = F_21 ( V_4 ) ;
int V_95 = - V_96 ;
F_13 ( & V_114 ) ;
F_32 (mds, tmp_mds, &mdev_devices_list, next) {
if ( V_1 == V_3 ) {
F_33 ( & V_1 -> V_115 ) ;
F_29 ( V_4 , NULL ) ;
F_28 ( V_1 -> V_10 ) ;
F_28 ( V_1 ) ;
V_95 = 0 ;
break;
}
}
F_17 ( & V_114 ) ;
return V_95 ;
}
int F_34 ( struct V_93 * V_4 )
{
struct V_1 * V_1 ;
if ( ! V_4 )
return - V_96 ;
V_1 = F_21 ( V_4 ) ;
if ( ! V_1 )
return - V_96 ;
F_7 ( L_19 , V_97 ) ;
return 0 ;
}
T_4 F_35 ( struct V_93 * V_4 , char T_7 * V_5 , T_5 V_6 ,
T_6 * V_118 )
{
unsigned int V_119 = 0 ;
int V_95 ;
while ( V_6 ) {
T_5 V_120 ;
if ( V_6 >= 4 && ! ( * V_118 % 4 ) ) {
V_9 V_121 ;
V_95 = F_20 ( V_4 , ( char * ) & V_121 , sizeof( V_121 ) ,
* V_118 , false ) ;
if ( V_95 <= 0 )
goto V_122;
if ( F_36 ( V_5 , & V_121 , sizeof( V_121 ) ) )
goto V_122;
V_120 = 4 ;
} else if ( V_6 >= 2 && ! ( * V_118 % 2 ) ) {
V_11 V_121 ;
V_95 = F_20 ( V_4 , ( char * ) & V_121 , sizeof( V_121 ) ,
* V_118 , false ) ;
if ( V_95 <= 0 )
goto V_122;
if ( F_36 ( V_5 , & V_121 , sizeof( V_121 ) ) )
goto V_122;
V_120 = 2 ;
} else {
T_3 V_121 ;
V_95 = F_20 ( V_4 , ( char * ) & V_121 , sizeof( V_121 ) ,
* V_118 , false ) ;
if ( V_95 <= 0 )
goto V_122;
if ( F_36 ( V_5 , & V_121 , sizeof( V_121 ) ) )
goto V_122;
V_120 = 1 ;
}
V_6 -= V_120 ;
V_119 += V_120 ;
* V_118 += V_120 ;
V_5 += V_120 ;
}
return V_119 ;
V_122:
return - V_123 ;
}
T_4 F_37 ( struct V_93 * V_4 , const char T_7 * V_5 ,
T_5 V_6 , T_6 * V_118 )
{
unsigned int V_119 = 0 ;
int V_95 ;
while ( V_6 ) {
T_5 V_120 ;
if ( V_6 >= 4 && ! ( * V_118 % 4 ) ) {
V_9 V_121 ;
if ( F_38 ( & V_121 , V_5 , sizeof( V_121 ) ) )
goto V_124;
V_95 = F_20 ( V_4 , ( char * ) & V_121 , sizeof( V_121 ) ,
* V_118 , true ) ;
if ( V_95 <= 0 )
goto V_124;
V_120 = 4 ;
} else if ( V_6 >= 2 && ! ( * V_118 % 2 ) ) {
V_11 V_121 ;
if ( F_38 ( & V_121 , V_5 , sizeof( V_121 ) ) )
goto V_124;
V_95 = F_20 ( V_4 , ( char * ) & V_121 , sizeof( V_121 ) ,
* V_118 , true ) ;
if ( V_95 <= 0 )
goto V_124;
V_120 = 2 ;
} else {
T_3 V_121 ;
if ( F_38 ( & V_121 , V_5 , sizeof( V_121 ) ) )
goto V_124;
V_95 = F_20 ( V_4 , ( char * ) & V_121 , sizeof( V_121 ) ,
* V_118 , true ) ;
if ( V_95 <= 0 )
goto V_124;
V_120 = 1 ;
}
V_6 -= V_120 ;
V_119 += V_120 ;
* V_118 += V_120 ;
V_5 += V_120 ;
}
return V_119 ;
V_124:
return - V_123 ;
}
static int F_39 ( struct V_93 * V_4 , T_2 V_125 ,
unsigned int V_18 , unsigned int V_91 ,
unsigned int V_6 , void * V_19 )
{
int V_95 = 0 ;
struct V_1 * V_1 ;
if ( ! V_4 )
return - V_96 ;
V_1 = F_21 ( V_4 ) ;
if ( ! V_1 )
return - V_96 ;
F_13 ( & V_1 -> V_98 ) ;
switch ( V_18 ) {
case V_126 :
switch ( V_125 & V_127 ) {
case V_128 :
case V_129 :
break;
case V_130 :
{
if ( V_125 & V_131 ) {
F_7 ( L_20 , V_97 ) ;
if ( V_1 -> V_132 )
F_40 ( V_1 -> V_132 ) ;
break;
}
if ( V_125 & V_133 ) {
int V_134 = * ( int * ) V_19 ;
if ( V_134 > 0 ) {
struct V_135 * V_136 ;
V_136 = F_41 ( V_134 ) ;
if ( F_42 ( V_136 ) ) {
V_95 = F_43 ( V_136 ) ;
break;
}
V_1 -> V_132 = V_136 ;
V_1 -> V_137 = V_134 ;
V_1 -> V_112 = V_18 ;
break;
}
}
break;
}
}
break;
case V_138 :
switch ( V_125 & V_127 ) {
case V_128 :
case V_129 :
break;
case V_130 :
if ( V_125 & V_131 ) {
if ( V_1 -> V_139 )
F_40 ( V_1 -> V_139 ) ;
F_7 ( L_21 , V_97 ) ;
V_1 -> V_112 = V_126 ;
break;
}
if ( V_125 & V_133 ) {
int V_134 = * ( int * ) V_19 ;
struct V_135 * V_136 ;
if ( V_134 <= 0 )
break;
if ( V_1 -> V_139 )
break;
V_136 = F_41 ( V_134 ) ;
if ( F_42 ( V_136 ) ) {
V_95 = F_43 ( V_136 ) ;
break;
}
V_1 -> V_139 = V_136 ;
V_1 -> V_137 = V_134 ;
V_1 -> V_112 = V_18 ;
}
break;
}
break;
case V_140 :
F_7 ( L_22 , V_97 ) ;
break;
case V_141 :
F_7 ( L_23 , V_97 ) ;
break;
case V_142 :
F_7 ( L_24 , V_97 ) ;
break;
}
F_17 ( & V_1 -> V_98 ) ;
return V_95 ;
}
static int F_16 ( T_1 V_2 )
{
int V_95 = - 1 ;
struct V_1 * V_1 ;
V_1 = F_1 ( V_2 ) ;
if ( ! V_1 ) {
F_7 ( L_25 , V_97 ) ;
return - V_96 ;
}
if ( ( V_1 -> V_112 == V_138 ) &&
( ! V_1 -> V_139 ) )
return - V_96 ;
else if ( ( V_1 -> V_112 == V_126 ) &&
( ! V_1 -> V_132 ) ) {
F_7 ( L_26 , V_97 ) ;
return - V_96 ;
}
if ( V_1 -> V_112 == V_138 )
V_95 = F_44 ( V_1 -> V_139 , 1 ) ;
else
V_95 = F_44 ( V_1 -> V_132 , 1 ) ;
#if F_6 ( V_34 )
F_7 ( L_27 ) ;
#endif
if ( V_95 != 1 )
F_15 ( L_28 , V_97 , V_95 ) ;
return V_95 ;
}
int F_45 ( struct V_93 * V_4 ,
struct V_143 * V_84 ,
V_11 * V_144 , void * * V_145 )
{
unsigned int V_85 = 0 ;
struct V_1 * V_1 ;
V_9 V_17 ;
if ( ! V_4 )
return - V_96 ;
V_1 = F_21 ( V_4 ) ;
if ( ! V_1 )
return - V_96 ;
V_17 = V_84 -> V_18 ;
if ( V_17 >= V_146 )
return - V_96 ;
F_13 ( & V_1 -> V_98 ) ;
switch ( V_17 ) {
case V_100 :
V_85 = V_113 ;
break;
case V_101 :
V_85 = V_13 ;
break;
case V_147 :
if ( V_1 -> V_14 == 2 )
V_85 = V_13 ;
break;
default:
V_85 = 0 ;
break;
}
V_1 -> V_84 [ V_17 ] . V_85 = V_85 ;
V_1 -> V_84 [ V_17 ] . V_148 =
F_46 ( V_17 ) ;
V_84 -> V_85 = V_85 ;
V_84 -> V_15 = F_46 ( V_17 ) ;
V_84 -> V_125 = V_149 |
V_150 ;
F_17 ( & V_1 -> V_98 ) ;
return 0 ;
}
int F_47 ( struct V_93 * V_4 , struct V_151 * V_152 )
{
switch ( V_152 -> V_18 ) {
case V_126 :
case V_138 :
case V_142 :
break;
default:
return - V_96 ;
}
V_152 -> V_125 = V_153 ;
V_152 -> V_6 = 1 ;
if ( V_152 -> V_18 == V_126 )
V_152 -> V_125 |= ( V_154 |
V_155 ) ;
else
V_152 -> V_125 |= V_156 ;
return 0 ;
}
int F_48 ( struct V_93 * V_4 ,
struct V_157 * V_158 )
{
V_158 -> V_125 = V_159 ;
V_158 -> V_160 = V_146 ;
V_158 -> V_161 = V_162 ;
return 0 ;
}
static long F_49 ( struct V_93 * V_4 , unsigned int V_163 ,
unsigned long V_164 )
{
int V_95 = 0 ;
unsigned long V_165 ;
struct V_1 * V_1 ;
if ( ! V_4 )
return - V_96 ;
V_1 = F_21 ( V_4 ) ;
if ( ! V_1 )
return - V_166 ;
switch ( V_163 ) {
case V_167 :
{
struct V_157 V_168 ;
V_165 = F_50 ( struct V_157 , V_161 ) ;
if ( F_38 ( & V_168 , ( void T_7 * ) V_164 , V_165 ) )
return - V_123 ;
if ( V_168 . V_169 < V_165 )
return - V_96 ;
V_95 = F_48 ( V_4 , & V_168 ) ;
if ( V_95 )
return V_95 ;
memcpy ( & V_1 -> V_158 , & V_168 , sizeof( V_168 ) ) ;
if ( F_36 ( ( void T_7 * ) V_164 , & V_168 , V_165 ) )
return - V_123 ;
return 0 ;
}
case V_170 :
{
struct V_143 V_168 ;
V_11 V_144 = 0 ;
void * V_145 = NULL ;
V_165 = F_50 ( struct V_143 , V_15 ) ;
if ( F_38 ( & V_168 , ( void T_7 * ) V_164 , V_165 ) )
return - V_123 ;
if ( V_168 . V_169 < V_165 )
return - V_96 ;
V_95 = F_45 ( V_4 , & V_168 , & V_144 ,
& V_145 ) ;
if ( V_95 )
return V_95 ;
if ( F_36 ( ( void T_7 * ) V_164 , & V_168 , V_165 ) )
return - V_123 ;
return 0 ;
}
case V_171 :
{
struct V_151 V_168 ;
V_165 = F_50 ( struct V_151 , V_6 ) ;
if ( F_38 ( & V_168 , ( void T_7 * ) V_164 , V_165 ) )
return - V_123 ;
if ( ( V_168 . V_169 < V_165 ) ||
( V_168 . V_18 >= V_1 -> V_158 . V_161 ) )
return - V_96 ;
V_95 = F_47 ( V_4 , & V_168 ) ;
if ( V_95 )
return V_95 ;
if ( F_36 ( ( void T_7 * ) V_164 , & V_168 , V_165 ) )
return - V_123 ;
return 0 ;
}
case V_172 :
{
struct V_173 V_174 ;
T_3 * V_19 = NULL , * V_175 = NULL ;
T_5 V_176 = 0 ;
V_165 = F_50 ( struct V_173 , V_6 ) ;
if ( F_38 ( & V_174 , ( void T_7 * ) V_164 , V_165 ) )
return - V_123 ;
V_95 = F_51 ( & V_174 ,
V_1 -> V_158 . V_161 ,
V_162 ,
& V_176 ) ;
if ( V_95 )
return V_95 ;
if ( V_176 ) {
V_175 = V_19 = F_52 ( ( void T_7 * ) ( V_164 + V_165 ) ,
V_176 ) ;
if ( F_42 ( V_19 ) )
return F_43 ( V_19 ) ;
}
V_95 = F_39 ( V_4 , V_174 . V_125 , V_174 . V_18 , V_174 . V_91 ,
V_174 . V_6 , V_19 ) ;
F_28 ( V_175 ) ;
return V_95 ;
}
case V_177 :
return F_34 ( V_4 ) ;
}
return - V_178 ;
}
int F_53 ( struct V_93 * V_4 )
{
F_7 ( L_29 , V_97 ) ;
return 0 ;
}
void F_54 ( struct V_93 * V_4 )
{
F_7 ( L_29 , V_97 ) ;
}
static T_4
F_55 ( struct V_179 * V_180 , struct V_181 * V_182 ,
char * V_5 )
{
return sprintf ( V_5 , L_30 ) ;
}
static T_4
F_56 ( struct V_179 * V_180 , struct V_181 * V_182 ,
char * V_5 )
{
if ( F_57 ( V_180 ) )
return sprintf ( V_5 , L_31 , F_58 ( V_180 ) ) ;
return sprintf ( V_5 , L_3 ) ;
}
static T_4
F_59 ( struct V_106 * V_107 , struct V_179 * V_180 , char * V_5 )
{
char V_108 [ V_109 ] ;
int V_8 ;
const char * V_183 [ 2 ] = { L_32 , L_33 } ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
snprintf ( V_108 , V_109 , L_18 ,
F_24 ( V_180 ) , V_8 + 1 ) ;
if ( ! strcmp ( V_107 -> V_108 , V_108 ) )
return sprintf ( V_5 , L_29 , V_183 [ V_8 ] ) ;
}
return - V_96 ;
}
static T_4
F_60 ( struct V_106 * V_107 , struct V_179 * V_180 , char * V_5 )
{
char V_108 [ V_109 ] ;
int V_8 ;
struct V_1 * V_3 ;
int V_184 = 0 , V_185 = 0 ;
for ( V_8 = 0 ; V_8 < 2 ; V_8 ++ ) {
snprintf ( V_108 , V_109 , L_18 ,
F_24 ( V_180 ) , V_8 + 1 ) ;
if ( ! strcmp ( V_107 -> V_108 , V_108 ) ) {
V_184 = V_8 + 1 ;
break;
}
}
if ( ! V_184 )
return - V_96 ;
F_2 (mds, &mdev_devices_list, next)
V_185 += V_3 -> V_14 ;
return sprintf ( V_5 , L_34 , ( V_186 - V_185 ) / V_184 ) ;
}
static T_4 F_61 ( struct V_106 * V_107 , struct V_179 * V_180 ,
char * V_5 )
{
return sprintf ( V_5 , L_29 , V_187 ) ;
}
static void F_62 ( struct V_179 * V_180 )
{
F_63 ( V_180 , L_35 ) ;
}
static int T_8 F_64 ( void )
{
int V_95 = 0 ;
F_7 ( L_36 , V_97 ) ;
memset ( & V_188 , 0 , sizeof( V_188 ) ) ;
F_65 ( & V_188 . V_189 ) ;
V_95 = F_66 ( & V_188 . V_190 , 0 , V_191 , V_192 ) ;
if ( V_95 < 0 ) {
F_15 ( L_37 , V_95 ) ;
return V_95 ;
}
F_67 ( & V_188 . V_193 , & V_194 ) ;
F_68 ( & V_188 . V_193 , V_188 . V_190 , V_191 ) ;
F_7 ( L_38 , F_69 ( V_188 . V_190 ) ) ;
V_188 . V_195 = F_70 ( V_196 , V_197 ) ;
if ( F_42 ( V_188 . V_195 ) ) {
F_15 ( L_39 ) ;
V_95 = F_43 ( V_188 . V_195 ) ;
goto V_198;
}
V_188 . V_180 . V_199 = V_188 . V_195 ;
V_188 . V_180 . V_200 = F_62 ;
F_71 ( & V_188 . V_180 , L_40 , V_192 ) ;
V_95 = F_72 ( & V_188 . V_180 ) ;
if ( V_95 )
goto V_201;
V_95 = F_73 ( & V_188 . V_180 , & V_202 ) ;
if ( V_95 )
goto V_203;
F_27 ( & V_114 ) ;
F_74 ( & V_116 ) ;
goto V_204;
V_203:
F_75 ( & V_188 . V_180 ) ;
V_201:
F_76 ( V_188 . V_195 ) ;
V_198:
F_77 ( & V_188 . V_193 ) ;
F_78 ( V_188 . V_190 , V_191 ) ;
V_204:
return V_95 ;
}
static void T_9 F_79 ( void )
{
V_188 . V_180 . V_205 = NULL ;
F_80 ( & V_188 . V_180 ) ;
F_75 ( & V_188 . V_180 ) ;
F_81 ( & V_188 . V_189 ) ;
F_77 ( & V_188 . V_193 ) ;
F_78 ( V_188 . V_190 , V_191 ) ;
F_76 ( V_188 . V_195 ) ;
V_188 . V_195 = NULL ;
F_7 ( L_41 ) ;
}
