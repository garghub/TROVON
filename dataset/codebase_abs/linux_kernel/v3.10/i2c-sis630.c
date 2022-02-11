static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 , int V_6 ,
T_1 * V_7 )
{
int V_8 ;
V_8 = F_1 ( V_9 ) ;
if ( ( V_8 & ( V_10 | V_11 ) ) != 0x00 ) {
F_6 ( & V_5 -> V_12 , L_1 , V_8 ) ;
F_3 ( V_13 , V_14 ) ;
V_8 = F_1 ( V_9 ) ;
if ( V_8 & ( V_10 | V_11 ) ) {
F_6 ( & V_5 -> V_12 , L_2 , V_8 ) ;
return - V_15 ;
} else {
F_6 ( & V_5 -> V_12 , L_3 ) ;
}
}
* V_7 = F_1 ( V_9 ) ;
F_6 ( & V_5 -> V_12 , L_4 , * V_7 ) ;
if ( V_16 )
F_3 ( V_9 , V_17 ) ;
else
F_3 ( V_9 , ( * V_7 & ~ V_18 ) ) ;
V_8 = F_1 ( V_19 ) ;
F_3 ( V_19 , V_8 & 0x1e ) ;
F_3 ( V_13 , V_20 | ( V_6 & 0x07 ) ) ;
return 0 ;
}
static int F_7 ( struct V_4 * V_5 , int V_6 )
{
int V_8 , V_21 = 0 , V_22 = 0 ;
do {
F_8 ( 1 ) ;
V_8 = F_1 ( V_19 ) ;
if ( V_6 == V_23 && ( V_8 & V_24 ) )
break;
} while ( ! ( V_8 & 0x0e ) && ( V_22 ++ < V_25 ) );
if ( V_22 > V_25 ) {
F_6 ( & V_5 -> V_12 , L_5 ) ;
V_21 = - V_26 ;
}
if ( V_8 & V_27 ) {
F_6 ( & V_5 -> V_12 , L_6 ) ;
V_21 = - V_28 ;
}
if ( V_8 & V_29 ) {
F_9 ( & V_5 -> V_12 , L_7 ) ;
V_21 = - V_30 ;
}
return V_21 ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_7 )
{
F_3 ( V_19 , 0xFF ) ;
F_6 ( & V_5 -> V_12 ,
L_8 , F_1 ( V_9 ) ) ;
if ( V_16 && ! ( V_7 & V_17 ) )
F_3 ( V_9 , F_1 ( V_9 ) & ~ V_17 ) ;
F_6 ( & V_5 -> V_12 ,
L_9 , F_1 ( V_9 ) ) ;
}
static int F_11 ( struct V_4 * V_5 , int V_6 )
{
int V_21 = 0 ;
T_1 V_7 = 0 ;
V_21 = F_5 ( V_5 , V_6 , & V_7 ) ;
if ( ! V_21 ) {
V_21 = F_7 ( V_5 , V_6 ) ;
F_10 ( V_5 , V_7 ) ;
}
return V_21 ;
}
static int F_12 ( struct V_4 * V_5 ,
union V_31 * V_3 , int V_32 )
{
int V_33 , V_34 = 0 , V_35 = 0 ;
T_1 V_7 = 0 ;
if ( V_32 == V_36 ) {
V_34 = V_3 -> V_37 [ 0 ] ;
if ( V_34 < 0 )
V_34 = 0 ;
else if ( V_34 > 32 )
V_34 = 32 ;
F_3 ( V_38 , V_34 ) ;
for ( V_33 = 1 ; V_33 <= V_34 ; V_33 ++ ) {
F_6 ( & V_5 -> V_12 ,
L_10 , V_3 -> V_37 [ V_33 ] ) ;
F_3 ( V_39 + ( V_33 - 1 ) % 8 , V_3 -> V_37 [ V_33 ] ) ;
if ( V_33 == 8 || ( V_34 < 8 && V_33 == V_34 ) ) {
F_6 ( & V_5 -> V_12 ,
L_11 , V_34 , V_33 ) ;
V_35 = F_5 ( V_5 ,
V_23 , & V_7 ) ;
if ( V_35 )
return V_35 ;
} else if ( ( V_33 - 1 ) % 8 == 7 || V_33 == V_34 ) {
F_6 ( & V_5 -> V_12 ,
L_12 , V_34 , V_33 ) ;
if ( V_33 > 8 ) {
F_6 ( & V_5 -> V_12 ,
L_13
L_14 , V_34 , V_33 ) ;
F_3 ( V_19 , V_24 ) ;
}
V_35 = F_7 ( V_5 ,
V_23 ) ;
if ( V_35 ) {
F_6 ( & V_5 -> V_12 ,
L_15 ) ;
break;
}
}
}
} else {
V_3 -> V_37 [ 0 ] = V_34 = 0 ;
V_35 = F_5 ( V_5 ,
V_23 , & V_7 ) ;
if ( V_35 )
return V_35 ;
do {
V_35 = F_7 ( V_5 , V_23 ) ;
if ( V_35 ) {
F_6 ( & V_5 -> V_12 , L_15 ) ;
break;
}
if ( V_34 == 0 )
V_3 -> V_37 [ 0 ] = F_1 ( V_38 ) ;
if ( V_3 -> V_37 [ 0 ] > 32 )
V_3 -> V_37 [ 0 ] = 32 ;
F_6 ( & V_5 -> V_12 ,
L_16 , V_3 -> V_37 [ 0 ] ) ;
for ( V_33 = 0 ; V_33 < 8 && V_34 < V_3 -> V_37 [ 0 ] ; V_33 ++ , V_34 ++ ) {
F_6 ( & V_5 -> V_12 ,
L_17 , V_33 , V_34 ) ;
V_3 -> V_37 [ V_34 + 1 ] = F_1 ( V_39 +
V_33 ) ;
}
F_6 ( & V_5 -> V_12 ,
L_18 , V_34 , V_33 ) ;
F_3 ( V_19 , V_24 ) ;
} while ( V_34 < V_3 -> V_37 [ 0 ] );
}
F_10 ( V_5 , V_7 ) ;
return V_35 ;
}
static T_2 F_13 ( struct V_4 * V_5 , T_3 V_40 ,
unsigned short V_41 , char V_32 ,
T_1 V_42 , int V_6 , union V_31 * V_3 )
{
int V_43 ;
switch ( V_6 ) {
case V_44 :
F_3 ( V_45 ,
( ( V_40 & 0x7f ) << 1 ) | ( V_32 & 0x01 ) ) ;
V_6 = V_46 ;
break;
case V_47 :
F_3 ( V_45 ,
( ( V_40 & 0x7f ) << 1 ) | ( V_32 & 0x01 ) ) ;
if ( V_32 == V_36 )
F_3 ( V_48 , V_42 ) ;
V_6 = V_49 ;
break;
case V_50 :
F_3 ( V_45 ,
( ( V_40 & 0x7f ) << 1 ) | ( V_32 & 0x01 ) ) ;
F_3 ( V_48 , V_42 ) ;
if ( V_32 == V_36 )
F_3 ( V_39 , V_3 -> V_51 ) ;
V_6 = V_52 ;
break;
case V_53 :
case V_54 :
F_3 ( V_45 ,
( ( V_40 & 0x7f ) << 1 ) | ( V_32 & 0x01 ) ) ;
F_3 ( V_48 , V_42 ) ;
if ( V_32 == V_36 ) {
F_3 ( V_39 , V_3 -> V_55 & 0xff ) ;
F_3 ( V_39 + 1 , ( V_3 -> V_55 & 0xff00 ) >> 8 ) ;
}
V_6 = ( V_6 == V_53 ?
V_56 : V_57 ) ;
break;
case V_58 :
F_3 ( V_45 ,
( ( V_40 & 0x7f ) << 1 ) | ( V_32 & 0x01 ) ) ;
F_3 ( V_48 , V_42 ) ;
V_6 = V_23 ;
return F_12 ( V_5 , V_3 , V_32 ) ;
default:
F_14 ( & V_5 -> V_12 , L_19 , V_6 ) ;
return - V_59 ;
}
V_43 = F_11 ( V_5 , V_6 ) ;
if ( V_43 )
return V_43 ;
if ( ( V_6 != V_56 ) &&
( ( V_32 == V_36 ) || ( V_6 == V_46 ) ) ) {
return 0 ;
}
switch ( V_6 ) {
case V_49 :
case V_52 :
V_3 -> V_51 = F_1 ( V_39 ) ;
break;
case V_56 :
case V_57 :
V_3 -> V_55 = F_1 ( V_39 ) +
( F_1 ( V_39 + 1 ) << 8 ) ;
break;
}
return 0 ;
}
static T_4 F_15 ( struct V_4 * V_60 )
{
return V_61 | V_62 |
V_63 | V_64 |
V_65 | V_66 ;
}
static int F_16 ( struct V_67 * V_68 )
{
unsigned char V_69 ;
struct V_67 * V_70 = NULL ;
int V_71 , V_33 ;
unsigned short V_72 ;
for ( V_33 = 0 ; V_73 [ V_33 ] > 0 ; V_33 ++ ) {
V_70 = F_17 ( V_74 , V_73 [ V_33 ] , V_70 ) ;
if ( V_70 )
break;
}
if ( V_70 ) {
F_18 ( V_70 ) ;
} else if ( V_75 ) {
F_9 ( & V_68 -> V_12 ,
L_20
L_21 ) ;
} else {
return - V_76 ;
}
if ( F_19 ( V_68 , V_77 , & V_69 ) ) {
F_9 ( & V_68 -> V_12 , L_22 ) ;
V_71 = - V_76 ;
goto exit;
}
if ( ! ( V_69 & 0x80 ) &&
F_20 ( V_68 , V_77 , V_69 | 0x80 ) ) {
F_9 ( & V_68 -> V_12 , L_23 ) ;
V_71 = - V_76 ;
goto exit;
}
if ( F_21 ( V_68 ,
V_78 , & V_72 ) ) {
F_9 ( & V_68 -> V_12 ,
L_24 ) ;
V_71 = - V_76 ;
goto exit;
}
F_6 ( & V_68 -> V_12 , L_25 , V_72 ) ;
if ( V_73 [ V_33 ] == V_79 )
V_2 = V_72 + 0xE0 ;
else
V_2 = V_72 + 0x80 ;
F_6 ( & V_68 -> V_12 , L_26 , V_2 ) ;
V_71 = F_22 ( V_2 + V_19 , V_80 ,
V_81 . V_82 ) ;
if ( V_71 )
goto exit;
if ( ! F_23 ( V_2 + V_19 , V_80 ,
V_81 . V_82 ) ) {
F_9 ( & V_68 -> V_12 ,
L_27 ,
V_2 + V_19 ,
V_2 + V_19 + V_80 - 1 ) ;
V_71 = - V_15 ;
goto exit;
}
V_71 = 0 ;
exit:
if ( V_71 )
V_2 = 0 ;
return V_71 ;
}
static int F_24 ( struct V_67 * V_12 , const struct V_83 * V_84 )
{
if ( F_16 ( V_12 ) ) {
F_9 ( & V_12 -> V_12 ,
L_28
L_29 ) ;
return - V_76 ;
}
V_85 . V_12 . V_86 = & V_12 -> V_12 ;
snprintf ( V_85 . V_82 , sizeof( V_85 . V_82 ) ,
L_30 , V_2 + V_19 ) ;
return F_25 ( & V_85 ) ;
}
static void F_26 ( struct V_67 * V_12 )
{
if ( V_2 ) {
F_27 ( & V_85 ) ;
F_28 ( V_2 + V_19 , V_80 ) ;
V_2 = 0 ;
}
}
