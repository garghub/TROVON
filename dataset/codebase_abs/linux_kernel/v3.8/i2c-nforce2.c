static void F_1 ( struct V_1 * V_2 )
{
V_3 = V_2 ;
}
static inline void F_1 ( struct V_1 * V_2 ) { }
static void F_2 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = 0 ;
unsigned char V_7 ;
F_3 ( & V_2 -> V_8 , L_1 ) ;
F_4 ( V_9 , V_10 ) ;
do {
F_5 ( 1 ) ;
V_7 = F_6 ( V_11 ) ;
} while ( ! ( V_7 & V_12 ) &&
( V_6 ++ < V_13 ) );
if ( ! ( V_7 & V_12 ) )
F_7 ( & V_2 -> V_8 , L_2 ) ;
F_4 ( V_12 , V_11 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = 0 ;
unsigned char V_7 ;
do {
F_5 ( 1 ) ;
V_7 = F_6 ( V_14 ) ;
} while ( ( ! V_7 ) && ( V_6 ++ < V_13 ) );
if ( V_6 > V_13 ) {
F_3 ( & V_2 -> V_8 , L_3 ) ;
if ( V_4 -> V_15 )
F_2 ( V_2 ) ;
return - V_16 ;
}
if ( ! ( V_7 & V_17 ) || ( V_7 & V_18 ) ) {
F_3 ( & V_2 -> V_8 , L_4 , V_7 ) ;
return - V_19 ;
}
return 0 ;
}
static T_1 F_9 ( struct V_1 * V_2 , T_2 V_20 ,
unsigned short V_21 , char V_22 ,
T_3 V_23 , int V_24 , union V_25 * V_26 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned char V_27 , V_28 ;
T_3 V_29 ;
int V_30 , V_31 ;
V_27 = ( V_22 == V_32 ) ? V_33 :
V_34 ;
V_28 = ( V_21 & V_35 ) ? V_36 : 0 ;
switch ( V_24 ) {
case V_37 :
V_27 |= V_38 ;
V_22 = V_39 ;
break;
case V_40 :
if ( V_22 == V_39 )
F_4 ( V_23 , V_41 ) ;
V_27 |= V_42 ;
break;
case V_43 :
F_4 ( V_23 , V_41 ) ;
if ( V_22 == V_39 )
F_4 ( V_26 -> V_44 , V_45 ) ;
V_27 |= V_46 ;
break;
case V_47 :
F_4 ( V_23 , V_41 ) ;
if ( V_22 == V_39 ) {
F_4 ( V_26 -> V_48 , V_45 ) ;
F_4 ( V_26 -> V_48 >> 8 , V_45 + 1 ) ;
}
V_27 |= V_49 | V_28 ;
break;
case V_50 :
F_4 ( V_23 , V_41 ) ;
if ( V_22 == V_39 ) {
V_29 = V_26 -> V_51 [ 0 ] ;
if ( ( V_29 == 0 ) || ( V_29 > V_52 ) ) {
F_7 ( & V_2 -> V_8 ,
L_5
L_6 ,
V_29 ) ;
return - V_53 ;
}
F_4 ( V_29 , V_54 ) ;
for ( V_30 = 0 ; V_30 < V_52 ; V_30 ++ )
F_4 ( V_26 -> V_51 [ V_30 + 1 ] ,
V_45 + V_30 ) ;
}
V_27 |= V_55 | V_28 ;
break;
default:
F_7 ( & V_2 -> V_8 , L_7 , V_24 ) ;
return - V_56 ;
}
F_4 ( ( V_20 & 0x7f ) << 1 , V_57 ) ;
F_4 ( V_27 , V_58 ) ;
V_31 = F_8 ( V_2 ) ;
if ( V_31 )
return V_31 ;
if ( V_22 == V_39 )
return 0 ;
switch ( V_24 ) {
case V_40 :
case V_43 :
V_26 -> V_44 = F_6 ( V_45 ) ;
break;
case V_47 :
V_26 -> V_48 = F_6 ( V_45 ) | ( F_6 ( V_45 + 1 ) << 8 ) ;
break;
case V_50 :
V_29 = F_6 ( V_54 ) ;
if ( ( V_29 <= 0 ) || ( V_29 > V_52 ) ) {
F_7 ( & V_2 -> V_8 , L_5
L_8 ,
V_29 ) ;
return - V_59 ;
}
for ( V_30 = 0 ; V_30 < V_29 ; V_30 ++ )
V_26 -> V_51 [ V_30 + 1 ] = F_6 ( V_45 + V_30 ) ;
V_26 -> V_51 [ 0 ] = V_29 ;
break;
}
return 0 ;
}
static T_4 F_10 ( struct V_1 * V_60 )
{
return V_61 | V_62 |
V_63 | V_64 |
V_65 |
( ( (struct V_3 * ) V_60 -> V_5 ) -> V_66 ?
V_67 : 0 ) ;
}
static int F_11 ( struct V_68 * V_8 , int V_69 , int V_70 ,
struct V_3 * V_4 , const char * V_71 )
{
int error ;
V_4 -> V_72 = F_12 ( V_8 , V_69 ) ;
if ( V_4 -> V_72 ) {
V_4 -> V_24 = F_13 ( V_8 , V_69 ) ;
} else {
T_2 V_73 ;
if ( F_14 ( V_8 , V_70 , & V_73 )
!= V_74 ) {
F_7 ( & V_8 -> V_8 , L_9 ,
V_71 ) ;
return - V_19 ;
}
V_4 -> V_72 = V_73 & V_75 ;
V_4 -> V_24 = 64 ;
}
error = F_15 ( V_4 -> V_72 , V_4 -> V_24 ,
V_76 . V_71 ) ;
if ( error )
return error ;
if ( ! F_16 ( V_4 -> V_72 , V_4 -> V_24 , V_76 . V_71 ) ) {
F_7 ( & V_4 -> V_60 . V_8 , L_10 ,
V_4 -> V_72 , V_4 -> V_72 + V_4 -> V_24 - 1 , V_71 ) ;
return - V_77 ;
}
V_4 -> V_60 . V_78 = V_79 ;
V_4 -> V_60 . V_80 = V_81 | V_82 ;
V_4 -> V_60 . V_83 = & V_84 ;
V_4 -> V_60 . V_5 = V_4 ;
V_4 -> V_60 . V_8 . V_85 = & V_8 -> V_8 ;
snprintf ( V_4 -> V_60 . V_71 , sizeof( V_4 -> V_60 . V_71 ) ,
L_11 , V_4 -> V_72 ) ;
error = F_17 ( & V_4 -> V_60 ) ;
if ( error ) {
F_7 ( & V_4 -> V_60 . V_8 , L_12 ) ;
F_18 ( V_4 -> V_72 , V_4 -> V_24 ) ;
return error ;
}
F_19 ( & V_4 -> V_60 . V_8 , L_13 , V_4 -> V_72 ) ;
return 0 ;
}
static int F_20 ( struct V_68 * V_8 , const struct V_86 * V_87 )
{
struct V_3 * V_88 ;
int V_89 , V_90 ;
if ( ! ( V_88 = F_21 ( 2 * sizeof( struct V_3 ) , V_91 ) ) )
return - V_92 ;
F_22 ( V_8 , V_88 ) ;
switch( V_8 -> V_93 ) {
case V_94 :
case V_95 :
case V_96 :
V_88 [ 0 ] . V_66 = 1 ;
V_88 [ 1 ] . V_66 = 1 ;
V_88 [ 0 ] . V_15 = 1 ;
V_88 [ 1 ] . V_15 = 1 ;
}
V_89 = F_11 ( V_8 , 4 , V_97 , & V_88 [ 0 ] , L_14 ) ;
if ( V_89 < 0 )
V_88 [ 0 ] . V_72 = 0 ;
if ( F_23 ( V_98 ) ) {
F_7 ( & V_8 -> V_8 , L_15 ) ;
V_90 = - V_99 ;
V_88 [ 1 ] . V_72 = 0 ;
} else {
V_90 = F_11 ( V_8 , 5 , V_100 , & V_88 [ 1 ] ,
L_16 ) ;
if ( V_90 < 0 )
V_88 [ 1 ] . V_72 = 0 ;
}
if ( ( V_89 < 0 ) && ( V_90 < 0 ) ) {
F_24 ( V_88 ) ;
return - V_101 ;
}
F_1 ( & V_88 [ 0 ] . V_60 ) ;
return 0 ;
}
static void F_25 ( struct V_68 * V_8 )
{
struct V_3 * V_88 = F_26 ( V_8 ) ;
F_1 ( NULL ) ;
if ( V_88 [ 0 ] . V_72 ) {
F_27 ( & V_88 [ 0 ] . V_60 ) ;
F_18 ( V_88 [ 0 ] . V_72 , V_88 [ 0 ] . V_24 ) ;
}
if ( V_88 [ 1 ] . V_72 ) {
F_27 ( & V_88 [ 1 ] . V_60 ) ;
F_18 ( V_88 [ 1 ] . V_72 , V_88 [ 1 ] . V_24 ) ;
}
F_24 ( V_88 ) ;
}
