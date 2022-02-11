static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_3 ( V_3 -> V_4 ) ;
F_4 ( V_3 ) ;
}
static int F_5 ( struct V_5 * V_5 , struct V_6 * V_7 )
{
struct V_8 * V_9 ;
struct V_2 * V_3 ;
int V_10 = 0 ;
V_9 = F_6 ( & V_11 , F_7 ( V_5 ) ) ;
if ( ! V_9 ) {
F_8 (KERN_ERR KBUILD_MODNAME
L_1 , iminor(inode)) ;
V_10 = - V_12 ;
goto exit;
}
V_3 = F_9 ( V_9 ) ;
F_10 ( & V_3 -> V_1 ) ;
V_7 -> V_13 = V_3 ;
exit:
return V_10 ;
}
static int F_11 ( struct V_5 * V_5 , struct V_6 * V_6 )
{
struct V_2 * V_3 = V_6 -> V_13 ;
F_12 ( & V_3 -> V_1 , F_1 ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
T_1 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
int V_19 ;
struct V_20 * V_21 ;
int V_22 ;
V_16 = & V_3 -> V_9 -> V_16 ;
V_14 = F_14 ( V_23 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_26 ,
V_27 | V_28 | V_29 ,
V_3 -> V_30 , V_3 -> V_31 ,
V_14 , 2 , V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_3 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] == V_33 ) {
V_17 = 0 ;
goto exit;
}
if ( V_14 [ 0 ] != V_34 ) {
F_17 ( V_16 , L_3 ,
V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto exit;
}
V_22 = 0 ;
V_21 = V_3 -> V_9 -> V_36 ;
for ( V_18 = 0 ; V_18 < V_21 -> V_37 . V_38 ; V_18 ++ )
if ( V_21 -> V_39 [ V_18 ] . V_37 . V_40 ==
V_3 -> V_31 )
V_22 = F_19 ( & V_21 -> V_39 [ V_18 ] . V_37 ) ;
if ( V_22 == 0 ) {
F_17 ( V_16 , L_4 ) ;
V_17 = - V_35 ;
goto exit;
}
F_18 ( & V_3 -> V_9 -> V_16 , L_5 , V_22 ) ;
V_18 = 0 ;
do {
F_18 ( V_16 , L_6 ) ;
V_17 = F_20 ( V_3 -> V_4 ,
F_21 ( V_3 -> V_4 ,
V_3 -> V_31 ) ,
V_14 , V_23 ,
& V_19 , V_32 ) ;
V_18 ++ ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_7 , V_17 ) ;
goto exit;
}
} while ( ( V_19 == V_22 ) &&
( V_18 < V_41 ) );
if ( V_19 == V_22 ) {
F_17 ( V_16 , L_8 ,
V_41 ) ;
V_17 = - V_35 ;
goto exit;
}
V_18 = 0 ;
V_42:
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_43 ,
V_27 | V_28 | V_29 ,
0 , V_3 -> V_31 , V_14 , 0x08 ,
V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_3 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] == V_34 ) {
V_17 = 0 ;
goto exit;
}
if ( V_14 [ 0 ] != V_44 ) {
F_17 ( V_16 , L_3 , V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto exit;
}
if ( V_14 [ 1 ] == 1 )
do {
F_18 ( V_16 , L_6 ) ;
V_17 = F_20 ( V_3 -> V_4 ,
F_21 ( V_3 -> V_4 ,
V_3 -> V_31 ) ,
V_14 , V_23 ,
& V_19 , V_32 ) ;
V_18 ++ ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_7 , V_17 ) ;
goto exit;
}
} while ( ( V_19 == V_22 ) &&
( V_18 < V_41 ) );
if ( V_19 == V_22 ) {
F_17 ( V_16 , L_8 ,
V_41 ) ;
V_17 = - V_35 ;
goto exit;
}
goto V_42;
exit:
F_4 ( V_14 ) ;
return V_17 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
T_1 * V_14 ;
int V_17 ;
int V_18 ;
V_16 = & V_3 -> V_9 -> V_16 ;
V_14 = F_14 ( 8 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_45 ,
V_27 | V_28 | V_29 ,
V_3 -> V_46 , V_3 -> V_47 ,
V_14 , 2 , V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_9 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] != V_34 ) {
F_17 ( V_16 , L_9 ,
V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto exit;
}
V_18 = 0 ;
V_48:
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_49 ,
V_27 | V_28 | V_29 ,
0 , V_3 -> V_47 , V_14 , 0x08 ,
V_32 ) ;
V_18 ++ ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_10 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] == V_34 )
goto V_50;
if ( ( V_14 [ 0 ] == V_44 ) &&
( V_18 < V_41 ) )
goto V_48;
V_17 = - V_35 ;
goto exit;
V_50:
V_17 = F_23 ( V_3 -> V_4 ,
F_24 ( V_3 -> V_4 , V_3 -> V_47 ) ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
V_17 = 0 ;
exit:
F_4 ( V_14 ) ;
return V_17 ;
}
static T_2 F_25 ( struct V_6 * V_7 , char T_3 * V_51 ,
T_4 V_52 , T_5 * V_53 )
{
struct V_2 * V_3 ;
struct V_15 * V_16 ;
T_6 V_54 ;
T_1 * V_14 ;
int V_19 ;
T_4 V_55 ;
T_4 V_56 ;
int V_10 ;
T_4 V_57 ;
V_3 = V_7 -> V_13 ;
V_16 = & V_3 -> V_9 -> V_16 ;
V_14 = F_14 ( V_23 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
F_26 ( & V_3 -> V_58 ) ;
if ( V_3 -> V_59 ) {
V_10 = - V_12 ;
goto exit;
}
V_56 = V_52 ;
V_55 = 0 ;
while ( V_56 > 0 ) {
if ( V_56 > V_23 - 12 - 3 )
V_57 = V_23 - 12 - 3 ;
else
V_57 = V_56 ;
V_14 [ 0 ] = 2 ;
V_14 [ 1 ] = V_3 -> V_60 ;
V_14 [ 2 ] = ~ ( V_3 -> V_60 ) ;
V_14 [ 3 ] = 0 ;
V_14 [ 4 ] = ( V_57 ) & 255 ;
V_14 [ 5 ] = ( ( V_57 ) >> 8 ) & 255 ;
V_14 [ 6 ] = ( ( V_57 ) >> 16 ) & 255 ;
V_14 [ 7 ] = ( ( V_57 ) >> 24 ) & 255 ;
V_14 [ 8 ] = V_3 -> V_61 * 2 ;
V_14 [ 9 ] = V_3 -> V_62 ;
V_14 [ 10 ] = 0 ;
V_14 [ 11 ] = 0 ;
V_10 = F_20 ( V_3 -> V_4 ,
F_24 ( V_3 -> V_4 ,
V_3 -> V_47 ) ,
V_14 , 12 , & V_19 , V_32 ) ;
V_3 -> V_46 = V_3 -> V_60 ;
V_3 -> V_60 ++ ;
if ( ! V_3 -> V_60 )
( V_3 -> V_60 ) ++ ;
if ( V_10 < 0 ) {
F_17 ( V_16 , L_7 , V_10 ) ;
if ( V_3 -> V_63 )
F_22 ( V_3 ) ;
goto exit;
}
V_10 = F_20 ( V_3 -> V_4 ,
F_21 ( V_3 -> V_4 ,
V_3 -> V_31 ) ,
V_14 , V_23 , & V_19 ,
V_32 ) ;
V_3 -> V_30 = V_3 -> V_60 ;
if ( V_10 < 0 ) {
F_17 ( V_16 , L_11 , V_10 ) ;
if ( V_3 -> V_63 )
F_13 ( V_3 ) ;
goto exit;
}
V_54 = V_14 [ 4 ] +
( V_14 [ 5 ] << 8 ) +
( V_14 [ 6 ] << 16 ) +
( V_14 [ 7 ] << 24 ) ;
if( V_54 > V_19 - 12 ) {
F_17 ( V_16 , L_12 , V_54 , V_19 - 12 ) ;
V_54 = V_19 - 12 ;
}
if( V_54 > V_57 ) {
F_17 ( V_16 , L_13 , V_55 + V_54 , V_55 + V_57 ) ;
V_54 = V_57 ;
}
if ( V_54 > V_57 )
V_54 = V_57 ;
if ( F_27 ( V_51 + V_55 , & V_14 [ 12 ] , V_54 ) ) {
V_10 = - V_64 ;
goto exit;
}
V_55 += V_54 ;
if ( ( V_14 [ 8 ] & 0x01 ) && ( V_19 >= V_54 + 12 ) )
V_56 = 0 ;
else
V_56 -= V_54 ;
}
* V_53 = * V_53 + V_55 ;
V_10 = V_55 ;
exit:
F_28 ( & V_3 -> V_58 ) ;
F_4 ( V_14 ) ;
return V_10 ;
}
static T_2 F_29 ( struct V_6 * V_7 , const char T_3 * V_51 ,
T_4 V_52 , T_5 * V_53 )
{
struct V_2 * V_3 ;
T_1 * V_14 ;
int V_10 ;
int V_19 ;
unsigned long int V_65 ;
int V_56 ;
int V_55 ;
int V_57 ;
V_3 = V_7 -> V_13 ;
V_14 = F_14 ( V_23 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
F_26 ( & V_3 -> V_58 ) ;
if ( V_3 -> V_59 ) {
V_10 = - V_12 ;
goto exit;
}
V_56 = V_52 ;
V_55 = 0 ;
while ( V_56 > 0 ) {
if ( V_56 > V_23 - 12 ) {
V_57 = V_23 - 12 ;
V_14 [ 8 ] = 0 ;
} else {
V_57 = V_56 ;
V_14 [ 8 ] = 1 ;
}
V_14 [ 0 ] = 1 ;
V_14 [ 1 ] = V_3 -> V_60 ;
V_14 [ 2 ] = ~ ( V_3 -> V_60 ) ;
V_14 [ 3 ] = 0 ;
V_14 [ 4 ] = V_57 & 255 ;
V_14 [ 5 ] = ( V_57 >> 8 ) & 255 ;
V_14 [ 6 ] = ( V_57 >> 16 ) & 255 ;
V_14 [ 7 ] = ( V_57 >> 24 ) & 255 ;
V_14 [ 9 ] = 0 ;
V_14 [ 10 ] = 0 ;
V_14 [ 11 ] = 0 ;
if ( F_30 ( & V_14 [ 12 ] , V_51 + V_55 , V_57 ) ) {
V_10 = - V_64 ;
goto exit;
}
V_65 = F_31 ( 12 + V_57 , 4 ) ;
memset ( V_14 + 12 + V_57 , 0 , V_65 - ( 12 + V_57 ) ) ;
do {
V_10 = F_20 ( V_3 -> V_4 ,
F_24 ( V_3 -> V_4 ,
V_3 -> V_47 ) ,
V_14 , V_65 ,
& V_19 , V_32 ) ;
if ( V_10 != 0 )
break;
V_65 -= V_19 ;
} while ( V_65 );
V_3 -> V_46 = V_3 -> V_60 ;
V_3 -> V_60 ++ ;
if ( ! V_3 -> V_60 )
V_3 -> V_60 ++ ;
if ( V_10 < 0 ) {
F_17 ( & V_3 -> V_9 -> V_16 ,
L_14 , V_10 ) ;
if ( V_3 -> V_63 )
F_22 ( V_3 ) ;
goto exit;
}
V_56 -= V_57 ;
V_55 += V_57 ;
}
V_10 = V_52 ;
exit:
F_28 ( & V_3 -> V_58 ) ;
F_4 ( V_14 ) ;
return V_10 ;
}
static int F_32 ( struct V_2 * V_3 )
{
struct V_20 * V_21 ;
struct V_66 * V_37 ;
struct V_15 * V_16 ;
T_1 * V_14 ;
int V_17 ;
int V_18 ;
int V_19 ;
int V_22 ;
V_16 = & V_3 -> V_9 -> V_16 ;
F_18 ( V_16 , L_15 ) ;
V_14 = F_14 ( V_23 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_67 ,
V_27 | V_28 | V_68 ,
0 , 0 , V_14 , 1 , V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_16 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] != V_34 ) {
F_17 ( V_16 , L_16 , V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto exit;
}
V_22 = 0 ;
V_21 = V_3 -> V_9 -> V_36 ;
for ( V_18 = 0 ; V_18 < V_21 -> V_37 . V_38 ; V_18 ++ ) {
V_37 = & V_21 -> V_39 [ V_18 ] . V_37 ;
if ( V_37 -> V_40 == V_3 -> V_31 )
V_22 = F_19 ( V_37 ) ;
}
if ( V_22 == 0 ) {
F_17 ( V_16 , L_4 ) ;
V_17 = - V_35 ;
goto exit;
}
F_18 ( V_16 , L_5 , V_22 ) ;
V_18 = 0 ;
V_69:
F_18 ( V_16 , L_17 ) ;
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_70 ,
V_27 | V_28 | V_68 ,
0 , 0 , V_14 , 2 , V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_18 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] == V_34 )
goto V_71;
if ( V_14 [ 0 ] != V_44 ) {
F_17 ( V_16 , L_18 , V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto exit;
}
if ( V_14 [ 1 ] == 1 )
do {
F_18 ( V_16 , L_6 ) ;
V_17 = F_20 ( V_3 -> V_4 ,
F_21 ( V_3 -> V_4 ,
V_3 -> V_31 ) ,
V_14 , V_23 ,
& V_19 , V_32 ) ;
V_18 ++ ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 ,
V_17 ) ;
goto exit;
}
} while ( ( V_19 == V_22 ) &&
( V_18 < V_41 ) );
if ( V_19 == V_22 ) {
F_17 ( V_16 , L_8 ,
V_41 ) ;
V_17 = - V_35 ;
goto exit;
}
goto V_69;
V_71:
V_17 = F_23 ( V_3 -> V_4 ,
F_24 ( V_3 -> V_4 , V_3 -> V_47 ) ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
V_17 = 0 ;
exit:
F_4 ( V_14 ) ;
return V_17 ;
}
static int F_33 ( struct V_2 * V_3 )
{
int V_17 ;
V_17 = F_23 ( V_3 -> V_4 ,
F_24 ( V_3 -> V_4 , V_3 -> V_47 ) ) ;
if ( V_17 < 0 ) {
F_17 ( & V_3 -> V_4 -> V_16 , L_2 ,
V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
int V_17 ;
V_17 = F_23 ( V_3 -> V_4 ,
F_21 ( V_3 -> V_4 , V_3 -> V_31 ) ) ;
if ( V_17 < 0 ) {
F_17 ( & V_3 -> V_4 -> V_16 , L_2 ,
V_17 ) ;
return V_17 ;
}
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_15 * V_16 = & V_3 -> V_4 -> V_16 ;
char * V_14 ;
int V_17 = 0 ;
V_14 = F_14 ( 0x18 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
V_17 = F_15 ( V_3 -> V_4 , F_16 ( V_3 -> V_4 , 0 ) ,
V_72 ,
V_27 | V_28 | V_68 ,
0 , 0 , V_14 , 0x18 , V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto V_73;
}
F_18 ( V_16 , L_19 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] != V_34 ) {
F_17 ( V_16 , L_19 , V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto V_73;
}
F_18 ( V_16 , L_20 , V_14 [ 4 ] ) ;
F_18 ( V_16 , L_21 , V_14 [ 5 ] ) ;
F_18 ( V_16 , L_22 , V_14 [ 14 ] ) ;
F_18 ( V_16 , L_23 , V_14 [ 15 ] ) ;
V_3 -> V_74 . V_75 = V_14 [ 4 ] ;
V_3 -> V_74 . V_76 = V_14 [ 5 ] ;
V_3 -> V_74 . V_77 = V_14 [ 14 ] ;
V_3 -> V_74 . V_78 = V_14 [ 15 ] ;
V_17 = 0 ;
V_73:
F_4 ( V_14 ) ;
return V_17 ;
}
static T_2 F_36 ( struct V_15 * V_16 ,
struct V_79 * V_80 , char * V_51 )
{
struct V_8 * V_9 = F_37 ( V_16 ) ;
struct V_2 * V_3 = F_9 ( V_9 ) ;
return sprintf ( V_51 , L_24 , V_3 -> V_62 ) ;
}
static T_2 F_38 ( struct V_15 * V_16 ,
struct V_79 * V_80 ,
const char * V_51 , T_4 V_52 )
{
struct V_8 * V_9 = F_37 ( V_16 ) ;
struct V_2 * V_3 = F_9 ( V_9 ) ;
if ( V_52 < 1 )
return - V_81 ;
V_3 -> V_62 = V_51 [ 0 ] ;
return V_52 ;
}
static int F_39 ( struct V_2 * V_3 )
{
struct V_15 * V_16 ;
T_1 * V_14 ;
int V_17 ;
V_16 = & V_3 -> V_9 -> V_16 ;
V_14 = F_14 ( 2 , V_24 ) ;
if ( ! V_14 )
return - V_25 ;
V_17 = F_15 ( V_3 -> V_4 ,
F_16 ( V_3 -> V_4 , 0 ) ,
V_82 ,
V_27 | V_28 | V_68 ,
0 , 0 , V_14 , 0x01 , V_32 ) ;
if ( V_17 < 0 ) {
F_17 ( V_16 , L_2 , V_17 ) ;
goto exit;
}
F_18 ( V_16 , L_25 , V_14 [ 0 ] ) ;
if ( V_14 [ 0 ] != V_34 ) {
F_17 ( V_16 , L_25 , V_14 [ 0 ] ) ;
V_17 = - V_35 ;
goto exit;
}
V_17 = 0 ;
exit:
F_4 ( V_14 ) ;
return V_17 ;
}
static long F_40 ( struct V_6 * V_6 , unsigned int V_83 , unsigned long V_84 )
{
struct V_2 * V_3 ;
int V_10 = - V_85 ;
V_3 = V_6 -> V_13 ;
F_26 ( & V_3 -> V_58 ) ;
if ( V_3 -> V_59 ) {
V_10 = - V_12 ;
goto V_86;
}
switch ( V_83 ) {
case V_87 :
V_10 = F_33 ( V_3 ) ;
break;
case V_88 :
V_10 = F_34 ( V_3 ) ;
break;
case V_89 :
V_10 = F_39 ( V_3 ) ;
break;
case V_90 :
V_10 = F_32 ( V_3 ) ;
break;
case V_91 :
V_10 = F_22 ( V_3 ) ;
break;
case V_92 :
V_10 = F_13 ( V_3 ) ;
break;
}
V_86:
F_28 ( & V_3 -> V_58 ) ;
return V_10 ;
}
static int F_41 ( struct V_8 * V_9 ,
const struct V_93 * V_94 )
{
struct V_2 * V_3 ;
struct V_20 * V_95 ;
struct V_66 * V_39 ;
int V_18 ;
int V_96 ;
F_18 ( & V_9 -> V_16 , L_26 , V_97 ) ;
V_3 = F_14 ( sizeof( struct V_2 ) , V_24 ) ;
if ( ! V_3 ) {
F_17 ( & V_9 -> V_16 , L_27 ) ;
return - V_25 ;
}
V_3 -> V_9 = V_9 ;
V_3 -> V_94 = V_94 ;
V_3 -> V_4 = F_42 ( F_43 ( V_9 ) ) ;
F_44 ( V_9 , V_3 ) ;
F_45 ( & V_3 -> V_1 ) ;
F_46 ( & V_3 -> V_58 ) ;
V_3 -> V_59 = 0 ;
V_3 -> V_60 = 1 ;
V_3 -> V_61 = 0 ;
V_3 -> V_62 = '\n' ;
V_95 = V_3 -> V_9 -> V_36 ;
for ( V_18 = 0 ; V_18 < V_95 -> V_37 . V_38 ; V_18 ++ ) {
V_39 = & V_95 -> V_39 [ V_18 ] . V_37 ;
if ( F_47 ( V_39 ) ) {
V_3 -> V_31 = V_39 -> V_40 ;
F_18 ( & V_9 -> V_16 , L_28 ,
V_3 -> V_31 ) ;
break;
}
}
for ( V_18 = 0 ; V_18 < V_95 -> V_37 . V_38 ; V_18 ++ ) {
V_39 = & V_95 -> V_39 [ V_18 ] . V_37 ;
if ( F_48 ( V_39 ) ) {
V_3 -> V_47 = V_39 -> V_40 ;
F_18 ( & V_9 -> V_16 , L_29 ,
V_3 -> V_47 ) ;
break;
}
}
V_96 = F_35 ( V_3 ) ;
if ( V_96 )
F_17 ( & V_9 -> V_16 , L_30 ) ;
else
V_96 = F_49 ( & V_9 -> V_16 . V_98 ,
& V_99 ) ;
V_96 = F_49 ( & V_9 -> V_16 . V_98 , & V_100 ) ;
V_96 = F_50 ( V_9 , & V_101 ) ;
if ( V_96 ) {
F_17 ( & V_9 -> V_16 , L_31
L_32 , V_102 ,
V_96 ) ;
goto V_103;
}
F_18 ( & V_9 -> V_16 , L_33 , V_9 -> V_104 ) ;
return 0 ;
V_103:
F_51 ( & V_9 -> V_16 . V_98 , & V_99 ) ;
F_51 ( & V_9 -> V_16 . V_98 , & V_100 ) ;
F_12 ( & V_3 -> V_1 , F_1 ) ;
return V_96 ;
}
static void F_52 ( struct V_8 * V_9 )
{
struct V_2 * V_3 ;
F_18 ( & V_9 -> V_16 , L_34 ) ;
V_3 = F_9 ( V_9 ) ;
F_53 ( V_9 , & V_101 ) ;
F_51 ( & V_9 -> V_16 . V_98 , & V_99 ) ;
F_51 ( & V_9 -> V_16 . V_98 , & V_100 ) ;
F_26 ( & V_3 -> V_58 ) ;
V_3 -> V_59 = 1 ;
F_28 ( & V_3 -> V_58 ) ;
F_12 ( & V_3 -> V_1 , F_1 ) ;
}
static int F_54 ( struct V_8 * V_9 , T_7 V_105 )
{
return 0 ;
}
static int F_55 ( struct V_8 * V_9 )
{
return 0 ;
}
