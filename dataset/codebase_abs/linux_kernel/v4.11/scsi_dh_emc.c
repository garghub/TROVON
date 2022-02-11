static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = V_6 ;
F_2 ( V_7 , V_2 , L_1
L_2
L_3 , V_8 , V_4 -> V_9 ,
V_4 -> V_10 , V_4 -> V_11 ) ;
if ( V_4 -> V_9 == 0x05 && V_4 -> V_10 == 0x04 &&
V_4 -> V_11 == 0x00 ) {
F_2 ( V_12 , V_2 , L_4
L_5
L_3 , V_8 ) ;
V_5 = V_13 ;
} else if ( V_4 -> V_9 == 0x02 && V_4 -> V_10 == 0x04 &&
V_4 -> V_11 == 0x03 ) {
F_2 ( V_12 , V_2 , L_6
L_7
L_8 , V_8 ) ;
V_5 = V_13 ;
} else
V_5 = V_14 ;
return V_5 ;
}
static int F_3 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_5 = V_17 ;
if ( V_16 -> V_18 [ 48 ] != 0 ) {
F_2 ( V_19 , V_2 , L_6
L_9
L_10 , V_8 ) ;
V_5 = V_13 ;
goto V_20;
}
if ( V_16 -> V_18 [ 4 ] > 2 ) {
F_2 ( V_19 , V_2 ,
L_11 ,
V_8 ) ;
V_5 = V_21 ;
goto V_20;
}
switch ( V_16 -> V_18 [ 28 ] & 0x0f ) {
case 6 :
F_2 ( V_19 , V_2 ,
L_12 ,
V_8 ) ;
break;
case 4 :
break;
default:
F_2 ( V_22 , V_2 ,
L_13 ,
V_8 , V_16 -> V_18 [ 28 ] & 0x0f ) ;
V_5 = V_21 ;
goto V_20;
}
V_16 -> V_23 = V_16 -> V_18 [ 5 ] ;
V_16 -> V_24 = V_16 -> V_18 [ 4 ] ;
V_16 -> V_25 = V_16 -> V_18 [ 8 ] ;
V_16 -> V_26 = V_16 -> V_18 [ 7 ] ;
if ( V_16 -> V_24 == V_27 )
V_2 -> V_28 = V_29 ;
else
V_2 -> V_28 = V_30 ;
if ( V_16 -> V_23 == V_16 -> V_25 )
V_2 -> V_28 |= V_31 ;
V_20:
return V_5 ;
}
static char * F_4 ( struct V_1 * V_2 , unsigned char * V_18 )
{
unsigned char V_32 = V_18 [ 4 ] + 5 ;
char * V_33 = NULL ;
unsigned char V_34 , V_35 ;
if ( V_32 < 160 ) {
F_2 ( V_22 , V_2 ,
L_14 ,
V_8 , V_32 ) ;
if ( ! strncmp ( V_18 + 8 , L_15 , 3 ) ) {
V_33 = V_36 ;
}
goto V_20;
}
V_35 = V_18 [ 160 ] ;
if ( V_35 == 0 || V_35 + 161 > V_32 ) {
F_2 ( V_22 , V_2 ,
L_16 ,
V_8 , V_35 ) ;
goto V_20;
}
V_34 = V_18 [ 99 ] ;
if ( V_34 == 0 || V_35 + V_34 + 161 > V_32 ) {
F_2 ( V_22 , V_2 ,
L_17 ,
V_8 , V_34 ) ;
goto V_20;
}
V_33 = & V_18 [ V_35 + 161 ] ;
while ( V_34 > 1 && V_33 [ V_34 - 1 ] == ' ' )
V_34 -- ;
V_33 [ V_34 ] = '\0' ;
V_20:
return V_33 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
unsigned char * V_37 ;
unsigned char V_38 [ F_6 ( V_39 ) ] ;
int V_5 , V_40 = V_17 , V_32 ;
struct V_3 V_4 ;
T_1 V_41 = V_42 | V_43 |
V_44 ;
if ( V_16 -> V_45 & V_46 ) {
V_37 = V_47 ;
if ( ! ( V_16 -> V_45 & V_48 ) )
V_37 [ 6 ] |= 0x80 ;
V_32 = sizeof( V_47 ) ;
V_38 [ 0 ] = V_39 ;
V_38 [ 1 ] = 0x10 ;
V_38 [ 4 ] = V_32 ;
} else {
V_37 = V_49 ;
if ( ! ( V_16 -> V_45 & V_48 ) )
V_37 [ 10 ] |= 0x80 ;
V_32 = sizeof( V_49 ) ;
V_38 [ 0 ] = V_50 ;
V_38 [ 8 ] = V_32 ;
}
F_7 ( ( V_32 > V_51 ) ) ;
memcpy ( V_16 -> V_18 , V_37 , V_32 ) ;
V_5 = F_8 ( V_2 , V_38 , V_52 , V_16 -> V_18 , V_32 , NULL ,
& V_4 , V_53 * V_54 , V_55 ,
V_41 , 0 , NULL ) ;
if ( V_5 ) {
if ( F_9 ( & V_4 ) )
V_40 = F_1 ( V_2 , & V_4 ) ;
else {
F_2 ( V_12 , V_2 ,
L_18 ,
V_8 , V_5 ) ;
V_40 = V_6 ;
}
}
return V_40 ;
}
static int F_10 ( struct V_1 * V_2 ,
struct V_3 * V_56 )
{
switch ( V_56 -> V_9 ) {
case V_57 :
if ( V_56 -> V_10 == 0x04 && V_56 -> V_11 == 0x03 )
return V_58 ;
break;
case V_59 :
if ( V_56 -> V_10 == 0x25 && V_56 -> V_11 == 0x01 )
return V_58 ;
break;
case V_60 :
if ( V_56 -> V_10 == 0x29 && V_56 -> V_11 == 0x00 )
return V_61 ;
break;
}
return V_62 ;
}
static int F_11 ( struct V_1 * V_2 , struct V_63 * V_64 )
{
struct V_15 * V_65 = V_2 -> V_66 ;
int V_67 = V_68 ;
if ( V_65 -> V_24 != V_27 ) {
V_67 = V_69 ;
V_64 -> V_70 |= V_71 ;
}
return V_67 ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_5 = V_17 ;
char * V_33 ;
V_33 = F_4 ( V_2 , V_2 -> V_72 ) ;
if ( ! V_33 ) {
V_5 = V_73 ;
goto V_20;
}
if ( ! strlen ( V_33 ) || ! strncmp ( V_33 , L_19 , 2 ) )
V_16 -> V_45 |= V_46 ;
F_2 ( V_12 , V_2 ,
L_20 ,
V_8 , V_33 , V_16 -> V_45 ) ;
V_20:
return V_5 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_15 * V_16 )
{
int V_5 = V_6 ;
if ( ! F_14 ( V_2 , 0xC0 , V_16 -> V_18 ,
V_51 ) )
V_5 = F_3 ( V_2 , V_16 ) ;
return V_5 ;
}
static int F_15 ( struct V_1 * V_2 ,
T_2 V_74 , void * V_75 )
{
struct V_15 * V_16 = V_2 -> V_66 ;
int V_76 ;
V_76 = F_13 ( V_2 , V_16 ) ;
if ( V_76 != V_17 )
goto V_77;
if ( V_16 -> V_24 == V_27 )
goto V_77;
V_76 = F_5 ( V_2 , V_16 ) ;
if ( V_76 != V_17 )
goto V_77;
F_2 ( V_12 , V_2 , L_21 ,
V_8 ,
V_16 -> V_45 & V_46 ? L_22 : L_23 ) ;
V_76 = F_13 ( V_2 , V_16 ) ;
if ( V_76 != V_17 )
goto V_77;
V_77:
F_2 ( V_12 , V_2 ,
L_24 ,
V_8 , V_16 -> V_25 + 'A' ,
V_16 -> V_26 , V_24 [ V_16 -> V_24 ] ,
V_16 -> V_23 + 'A' ) ;
if ( V_74 )
V_74 ( V_75 , V_76 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const char * V_78 )
{
struct V_15 * V_16 = V_2 -> V_66 ;
unsigned int V_79 = 0 , V_80 = 0 , V_81 ;
const char * V_82 = V_78 ;
int V_76 = V_17 ;
if ( ( sscanf ( V_78 , L_25 , & V_81 ) != 1 ) || ( V_81 != 2 ) )
return - V_83 ;
while ( * V_82 ++ )
;
if ( ( sscanf ( V_82 , L_25 , & V_80 ) != 1 ) || ( V_80 > 1 ) )
return - V_83 ;
while ( * V_82 ++ )
;
if ( ( sscanf ( V_82 , L_25 , & V_79 ) != 1 ) || ( V_79 > 1 ) )
return - V_83 ;
if ( V_80 )
V_16 -> V_45 |= V_46 ;
else
V_16 -> V_45 &= ~ V_46 ;
if ( V_79 )
V_16 -> V_45 |= V_48 ;
else
V_16 -> V_45 &= ~ V_48 ;
if ( V_16 -> V_24 != V_27 )
goto V_77;
V_16 -> V_24 = V_84 ;
V_76 = F_5 ( V_2 , V_16 ) ;
if ( V_76 != V_17 )
goto V_77;
V_76 = F_13 ( V_2 , V_16 ) ;
V_77:
return V_76 ;
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_15 * V_65 ;
int V_5 ;
V_65 = F_18 ( sizeof( * V_65 ) , V_85 ) ;
if ( ! V_65 )
return - V_86 ;
V_65 -> V_24 = V_84 ;
V_65 -> V_23 = V_87 ;
V_65 -> V_25 = V_87 ;
V_5 = F_12 ( V_2 , V_65 ) ;
if ( V_5 != V_17 )
goto V_88;
V_5 = F_13 ( V_2 , V_65 ) ;
if ( V_5 != V_17 )
goto V_88;
F_2 ( V_12 , V_2 ,
L_26 ,
V_8 , V_65 -> V_25 + 'A' ,
V_65 -> V_26 , V_24 [ V_65 -> V_24 ] ,
V_65 -> V_23 + 'A' ) ;
V_2 -> V_66 = V_65 ;
return 0 ;
V_88:
F_19 ( V_65 ) ;
return - V_83 ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_19 ( V_2 -> V_66 ) ;
V_2 -> V_66 = NULL ;
}
static int T_3 F_21 ( void )
{
int V_89 ;
V_89 = F_22 ( & V_90 ) ;
if ( V_89 != 0 )
F_23 ( V_7 L_27 ,
V_8 ) ;
return V_89 ;
}
static void T_4 F_24 ( void )
{
F_25 ( & V_90 ) ;
}
