static int F_1 ( struct V_1 * V_2 )
{
int V_3 = 500 ;
while ( ( F_2 ( V_2 -> V_4 + V_5 ) & V_6 ) && -- V_3 )
F_3 ( 1 ) ;
if ( ! V_3 ) {
F_4 ( & V_2 -> V_7 -> V_7 ,
L_1 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_3 = 500 ;
while ( ( ~ F_2 ( V_2 -> V_4 + V_5 ) & V_9 ) && -- V_3 )
F_3 ( 1 ) ;
if ( ! V_3 ) {
F_4 ( & V_2 -> V_7 -> V_7 ,
L_2 ) ;
return - V_8 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char * V_11 )
{
int V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_13 , V_2 -> V_4 + V_14 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_10 , V_2 -> V_4 + V_15 ) ;
V_12 = F_5 ( V_2 ) ;
if ( V_12 )
return V_12 ;
* V_11 = F_2 ( V_2 -> V_4 + V_15 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned char V_10 ,
unsigned char V_11 )
{
int V_12 ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_16 , V_2 -> V_4 + V_14 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_10 , V_2 -> V_4 + V_15 ) ;
V_12 = F_1 ( V_2 ) ;
if ( V_12 )
return V_12 ;
F_7 ( V_11 , V_2 -> V_4 + V_15 ) ;
return 0 ;
}
static T_1 F_9 ( struct V_17 * V_18 , T_2 V_19 ,
unsigned short V_20 , char V_21 , T_3 V_22 , int V_23 ,
union V_24 * V_11 )
{
struct V_1 * V_2 = V_18 -> V_25 ;
unsigned char V_26 , V_27 , V_28 , V_29 [ 2 ] ;
int V_30 , V_12 ;
V_26 = ( V_21 == V_31 ) ? V_32
: V_33 ;
V_28 = ( V_20 & V_34 ) ? V_35 : 0 ;
switch ( V_23 ) {
case V_36 :
V_26 |= V_37 ;
V_21 = V_38 ;
break;
case V_39 :
if ( V_21 == V_38 ) {
V_12 = F_8 ( V_2 , V_40 ,
V_22 ) ;
if ( V_12 )
return V_12 ;
}
V_26 |= V_41 ;
break;
case V_42 :
V_12 = F_8 ( V_2 , V_40 , V_22 ) ;
if ( V_12 )
return V_12 ;
if ( V_21 == V_38 ) {
V_12 = F_8 ( V_2 , V_43 ,
V_11 -> V_44 ) ;
if ( V_12 )
return V_12 ;
}
V_26 |= V_45 ;
break;
case V_46 :
V_12 = F_8 ( V_2 , V_40 , V_22 ) ;
if ( V_12 )
return V_12 ;
if ( V_21 == V_38 ) {
V_12 = F_8 ( V_2 , V_43 ,
V_11 -> V_47 & 0xff ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 , V_43 + 1 ,
V_11 -> V_47 >> 8 ) ;
if ( V_12 )
return V_12 ;
}
V_26 |= V_48 | V_28 ;
break;
case V_49 :
V_12 = F_8 ( V_2 , V_40 , V_22 ) ;
if ( V_12 )
return V_12 ;
if ( V_21 == V_38 ) {
V_27 = F_10 ( T_3 , V_11 -> V_50 [ 0 ] ,
V_51 ) ;
V_12 = F_8 ( V_2 , V_52 , V_27 ) ;
if ( V_12 )
return V_12 ;
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
V_12 =
F_8 ( V_2 , V_43 + V_30 ,
V_11 -> V_50 [ V_30 + 1 ] ) ;
if ( V_12 )
return V_12 ;
}
}
V_26 |= V_53 | V_28 ;
break;
case V_54 :
V_27 = F_10 ( T_3 , V_11 -> V_50 [ 0 ] ,
V_51 ) ;
V_12 = F_8 ( V_2 , V_40 , V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 , V_52 , V_27 ) ;
if ( V_12 )
return V_12 ;
if ( V_21 == V_38 )
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
V_12 =
F_8 ( V_2 , V_43 + V_30 ,
V_11 -> V_50 [ V_30 + 1 ] ) ;
if ( V_12 )
return V_12 ;
}
V_26 |= V_55 ;
break;
case V_56 :
V_12 = F_8 ( V_2 , V_40 , V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 , V_43 ,
V_11 -> V_47 & 0xff ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 , V_43 + 1 ,
V_11 -> V_47 >> 8 ) ;
if ( V_12 )
return V_12 ;
V_26 = V_57 | V_28 ;
V_21 = V_31 ;
break;
case V_58 :
V_27 = F_10 ( T_3 , V_11 -> V_50 [ 0 ] ,
V_51 - 1 ) ;
V_12 = F_8 ( V_2 , V_40 , V_22 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 , V_52 , V_27 ) ;
if ( V_12 )
return V_12 ;
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
V_12 = F_8 ( V_2 , V_43 + V_30 ,
V_11 -> V_50 [ V_30 + 1 ] ) ;
if ( V_12 )
return V_12 ;
}
V_26 = V_59 | V_28 ;
V_21 = V_31 ;
break;
default:
F_4 ( & V_18 -> V_7 , L_3 , V_23 ) ;
return - V_60 ;
}
V_12 = F_8 ( V_2 , V_61 , V_19 << 1 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_8 ( V_2 , V_62 , V_26 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_2 , V_63 , V_29 + 0 ) ;
if ( V_12 )
return V_12 ;
if ( ~ V_29 [ 0 ] & V_64 ) {
F_3 ( 500 ) ;
V_12 = F_6 ( V_2 , V_63 , V_29 + 0 ) ;
if ( V_12 )
return V_12 ;
}
if ( ~ V_29 [ 0 ] & V_64 ) {
F_11 ( 1 ) ;
V_12 = F_6 ( V_2 , V_63 , V_29 + 0 ) ;
if ( V_12 )
return V_12 ;
}
if ( ( ~ V_29 [ 0 ] & V_64 ) || ( V_29 [ 0 ] & V_65 ) )
return - V_66 ;
if ( V_21 == V_38 )
return 0 ;
switch ( V_23 ) {
case V_39 :
case V_42 :
V_12 = F_6 ( V_2 , V_43 , & V_11 -> V_44 ) ;
if ( V_12 )
return V_12 ;
break;
case V_46 :
case V_56 :
V_12 = F_6 ( V_2 , V_43 , V_29 + 0 ) ;
if ( V_12 )
return V_12 ;
V_12 = F_6 ( V_2 , V_43 + 1 , V_29 + 1 ) ;
if ( V_12 )
return V_12 ;
V_11 -> V_47 = ( V_29 [ 1 ] << 8 ) | V_29 [ 0 ] ;
break;
case V_49 :
case V_58 :
V_12 = F_6 ( V_2 , V_52 , & V_27 ) ;
if ( V_12 )
return V_12 ;
V_27 = F_10 ( T_3 , V_27 , V_51 ) ;
case V_54 :
for ( V_30 = 0 ; V_30 < V_27 ; V_30 ++ ) {
V_12 = F_6 ( V_2 , V_43 + V_30 ,
V_11 -> V_50 + V_30 + 1 ) ;
if ( V_12 )
return V_12 ;
}
V_11 -> V_50 [ 0 ] = V_27 ;
break;
}
return 0 ;
}
static T_4 F_12 ( struct V_17 * V_67 )
{
return V_68 | V_69 |
V_70 |
V_71 | V_72 |
V_73 | V_74 |
V_75 | V_76 ;
}
static int F_13 ( struct V_77 * V_7 , const struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int error ;
if ( ! ( F_14 ( V_7 , 0 ) & V_80 ) )
return - V_81 ;
V_2 = F_15 ( sizeof( struct V_1 ) , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_4 = F_16 ( V_7 , 0 ) ;
V_2 -> V_23 = F_17 ( V_7 , 0 ) ;
error = F_18 ( & V_7 -> V_84 [ 0 ] ) ;
if ( error ) {
error = - V_81 ;
goto V_85;
}
if ( ! F_19 ( V_2 -> V_4 , V_2 -> V_23 , V_86 . V_87 ) ) {
error = - V_88 ;
goto V_85;
}
V_2 -> V_67 . V_89 = V_90 ;
snprintf ( V_2 -> V_67 . V_87 , sizeof( V_2 -> V_67 . V_87 ) ,
L_4 , V_2 -> V_4 ) ;
V_2 -> V_67 . V_91 = V_92 | V_93 ;
V_2 -> V_67 . V_94 = & V_95 ;
V_2 -> V_67 . V_25 = V_2 ;
V_2 -> V_67 . V_7 . V_96 = & V_7 -> V_7 ;
F_20 ( V_2 -> V_7 , V_97 , 0 ) ;
error = F_21 ( & V_2 -> V_67 ) ;
if ( error )
goto V_98;
F_22 ( V_7 , V_2 ) ;
return 0 ;
V_98:
F_23 ( V_2 -> V_4 , V_2 -> V_23 ) ;
V_85:
F_24 ( V_2 ) ;
return error ;
}
static void F_25 ( struct V_77 * V_7 )
{
struct V_1 * V_2 = F_26 ( V_7 ) ;
F_27 ( & V_2 -> V_67 ) ;
F_23 ( V_2 -> V_4 , V_2 -> V_23 ) ;
F_24 ( V_2 ) ;
}
