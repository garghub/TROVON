static T_1 F_1 ( struct V_1 * V_2 ,
T_2 V_3 ,
unsigned short V_4 ,
char V_5 ,
T_3 V_6 ,
int V_7 ,
union V_8 * V_9 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_13 = ( V_5 == V_14 ) ;
int V_15 = ( V_3 << 1 ) | V_13 ;
int V_16 , V_17 , V_18 ;
T_4 V_19 ;
T_3 * V_20 ;
T_3 V_21 [ 2 ] ;
if ( V_7 == V_22 || V_7 == V_23 ) {
V_16 = V_24 ;
V_17 = 0 ;
V_19 = 0 ;
} else {
V_16 = V_13 ? V_25 : V_26 ;
V_17 = 1 ;
V_19 = V_6 ;
}
switch ( V_7 ) {
case V_22 :
V_20 = NULL ;
V_18 = 0 ;
break;
case V_23 :
case V_27 :
V_20 = & V_9 -> V_28 ;
V_18 = 1 ;
break;
case V_29 :
if ( ! V_13 ) {
V_21 [ 0 ] = V_9 -> V_30 & 0xff ;
V_21 [ 1 ] = ( V_9 -> V_30 >> 8 ) & 0xff ;
}
V_20 = V_21 ;
V_18 = 2 ;
break;
case V_31 :
V_20 = V_9 -> V_32 ;
V_18 = V_9 -> V_32 [ 0 ] + 1 ;
break;
case V_33 :
V_20 = & V_9 -> V_32 [ 1 ] ;
V_18 = V_9 -> V_32 [ 0 ] ;
break;
default:
return - V_34 ;
}
V_12 = F_3 ( V_11 , 0 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_5 ( V_11 , V_16 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_2 ,
V_16 , V_12 ) ;
goto V_36;
}
V_12 = F_6 ( V_11 , V_15 , V_17 , V_19 , V_20 , V_18 ) ;
if ( V_12 ) {
if ( V_12 == - V_37 )
F_7 ( & V_2 -> V_35 ,
L_3
L_4 , V_15 >> 1 , V_7 , V_12 ) ;
else
F_4 ( & V_2 -> V_35 ,
L_3
L_4 , V_15 >> 1 , V_7 , V_12 ) ;
goto V_36;
}
if ( V_7 == V_29 && V_13 ) {
V_9 -> V_30 = ( ( T_2 ) V_21 [ 1 ] ) << 8 ;
V_9 -> V_30 |= V_21 [ 0 ] ;
}
V_36:
F_8 ( V_11 ) ;
return V_12 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_38 * V_39 ,
int V_40 )
{
struct V_10 * V_11 = F_2 ( V_2 ) ;
int V_12 = 0 ;
int V_13 ;
int V_15 ;
if ( V_40 != 1 ) {
F_4 ( & V_2 -> V_35 ,
L_5 ) ;
return - V_41 ;
}
if ( V_39 -> V_4 & V_42 )
return - V_34 ;
V_13 = ( V_39 -> V_4 & V_43 ) != 0 ;
V_15 = ( V_39 -> V_3 << 1 ) | V_13 ;
V_12 = F_3 ( V_11 , 0 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_1 , V_12 ) ;
return V_12 ;
}
V_12 = F_5 ( V_11 , V_24 ) ;
if ( V_12 ) {
F_4 ( & V_2 -> V_35 , L_2 ,
V_24 , V_12 ) ;
goto V_36;
}
V_12 = F_6 ( V_11 , V_15 , 0 , 0 , V_39 -> V_20 , V_39 -> V_18 ) ;
if ( V_12 < 0 ) {
if ( V_12 == - V_37 )
F_7 ( & V_2 -> V_35 , L_6 ,
V_15 & 1 ? L_7 : L_8 ,
V_15 >> 1 , V_12 ) ;
else
F_4 ( & V_2 -> V_35 , L_6 ,
V_15 & 1 ? L_7 : L_8 ,
V_15 >> 1 , V_12 ) ;
}
V_36:
F_8 ( V_11 ) ;
return V_12 < 0 ? V_12 : 1 ;
}
static T_4 F_10 ( struct V_1 * V_44 )
{
return V_45 | V_46 |
V_47 | V_48 |
V_49 | V_50 ;
}
static int T_5 F_11 ( struct V_51 * V_35 )
{
struct V_1 * V_44 = F_12 ( V_35 ) ;
int V_12 ;
V_12 = F_13 ( V_44 ) ;
if ( V_12 )
F_14 ( V_52
L_9 ,
V_44 -> V_53 ) ;
F_15 ( V_35 , NULL ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
return 0 ;
}
static int T_6 F_16 ( struct V_51 * V_35 )
{
struct V_10 * V_11 = V_35 -> V_35 . V_54 ;
struct V_55 * V_56 = NULL ;
struct V_1 * V_44 ;
const char * V_57 ;
int V_12 ;
if ( V_11 == NULL )
return - V_34 ;
V_44 = F_17 ( V_11 ) ;
switch( F_18 ( V_11 ) ) {
case V_58 :
V_56 = F_19 ( F_20 ( V_11 ) ) ;
if ( V_56 == NULL )
return - V_34 ;
V_57 = V_56 -> V_53 ;
break;
case V_59 :
V_57 = L_10 ;
break;
case V_60 :
V_57 = L_11 ;
break;
default:
return - V_34 ;
}
snprintf ( V_44 -> V_53 , sizeof( V_44 -> V_53 ) , L_12 , V_57 ,
F_21 ( V_11 ) ) ;
F_22 ( V_56 ) ;
F_15 ( V_35 , V_44 ) ;
V_44 -> V_61 = & V_62 ;
F_23 ( V_44 , V_11 ) ;
V_44 -> V_35 . V_56 = & V_35 -> V_35 ;
V_12 = F_24 ( V_44 ) ;
if ( V_12 ) {
F_14 ( V_63 L_13
L_14 , V_44 -> V_53 ) ;
memset ( V_44 , 0 , sizeof( * V_44 ) ) ;
}
F_14 ( V_64 L_15 , V_44 -> V_53 ) ;
if ( ! strncmp ( V_57 , L_16 , 5 ) ) {
struct V_55 * V_65 ;
const T_4 * V_66 ;
struct V_67 V_68 ;
V_65 = F_25 ( NULL , L_17 ) ;
if ( V_65 && F_26 ( V_65 , L_18 ) &&
( V_66 = F_27 ( V_65 , L_19 , NULL ) ) ) {
int V_69 ;
const char * V_70 ;
V_70 = strstr ( V_65 -> V_71 , L_20 ) ;
if ( V_70 )
V_69 = * ( V_70 + 9 ) - '0' ;
else
V_69 = ( ( * V_66 ) >> 8 ) & 0x0f ;
if ( F_21 ( V_11 ) == V_69 ) {
memset ( & V_68 , 0 , sizeof( struct V_67 ) ) ;
V_68 . V_3 = ( ( * V_66 ) & 0xff ) >> 1 ;
F_28 ( V_68 . type , L_21 , V_72 ) ;
F_29 ( V_44 , & V_68 ) ;
}
}
}
return V_12 ;
}
