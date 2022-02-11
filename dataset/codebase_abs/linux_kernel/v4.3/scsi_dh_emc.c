static int F_1 ( struct V_1 * V_2 , char * V_3 )
{
int V_4 = V_5 ;
struct V_6 V_7 ;
if ( ! F_2 ( V_3 , V_8 , & V_7 ) ) {
F_3 ( V_9 , V_2 , L_1
L_2
L_3 , V_10 , V_7 . V_11 ,
V_7 . V_12 , V_7 . V_13 ) ;
if ( ( V_7 . V_11 == 0x05 ) && ( V_7 . V_12 == 0x04 ) &&
( V_7 . V_13 == 0x00 ) ) {
F_3 ( V_14 , V_2 , L_4
L_5
L_3 , V_10 ) ;
V_4 = V_15 ;
} else if ( ( V_7 . V_11 == 0x02 ) && ( V_7 . V_12 == 0x04 ) &&
( V_7 . V_13 == 0x03 ) ) {
F_3 ( V_14 , V_2 , L_6
L_7
L_8 , V_10 ) ;
V_4 = V_15 ;
} else
V_4 = V_16 ;
} else {
F_3 ( V_14 , V_2 ,
L_9 ,
V_10 ) ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_4 = V_19 ;
if ( V_18 -> V_20 [ 48 ] != 0 ) {
F_3 ( V_21 , V_2 , L_6
L_10
L_11 , V_10 ) ;
V_4 = V_15 ;
goto V_22;
}
if ( V_18 -> V_20 [ 4 ] > 2 ) {
F_3 ( V_21 , V_2 ,
L_12 ,
V_10 ) ;
V_4 = V_23 ;
goto V_22;
}
switch ( V_18 -> V_20 [ 28 ] & 0x0f ) {
case 6 :
F_3 ( V_21 , V_2 ,
L_13 ,
V_10 ) ;
break;
case 4 :
break;
default:
F_3 ( V_24 , V_2 ,
L_14 ,
V_10 , V_18 -> V_20 [ 28 ] & 0x0f ) ;
V_4 = V_23 ;
goto V_22;
}
V_18 -> V_25 = V_18 -> V_20 [ 5 ] ;
V_18 -> V_26 = V_18 -> V_20 [ 4 ] ;
V_18 -> V_27 = V_18 -> V_20 [ 8 ] ;
V_18 -> V_28 = V_18 -> V_20 [ 7 ] ;
V_22:
return V_4 ;
}
static char * F_5 ( struct V_1 * V_2 , unsigned char * V_20 )
{
unsigned char V_29 = V_20 [ 4 ] + 5 ;
char * V_30 = NULL ;
unsigned char V_31 , V_32 ;
if ( V_29 < 160 ) {
F_3 ( V_24 , V_2 ,
L_15 ,
V_10 , V_29 ) ;
if ( ! strncmp ( V_20 + 8 , L_16 , 3 ) ) {
V_30 = V_33 ;
}
goto V_22;
}
V_32 = V_20 [ 160 ] ;
if ( V_32 == 0 || V_32 + 161 > V_29 ) {
F_3 ( V_24 , V_2 ,
L_17 ,
V_10 , V_32 ) ;
goto V_22;
}
V_31 = V_20 [ 99 ] ;
if ( V_31 == 0 || V_32 + V_31 + 161 > V_29 ) {
F_3 ( V_24 , V_2 ,
L_18 ,
V_10 , V_31 ) ;
goto V_22;
}
V_30 = & V_20 [ V_32 + 161 ] ;
while ( V_31 > 1 && V_30 [ V_31 - 1 ] == ' ' )
V_31 -- ;
V_30 [ V_31 ] = '\0' ;
V_22:
return V_30 ;
}
static struct V_34 * F_6 ( struct V_1 * V_2 , int V_35 ,
unsigned char * V_20 )
{
struct V_34 * V_36 ;
int V_29 = 0 ;
V_36 = F_7 ( V_2 -> V_37 ,
( V_35 != V_38 ) ? V_39 : V_40 , V_41 ) ;
if ( F_8 ( V_36 ) ) {
F_3 ( V_14 , V_2 , L_19 ) ;
return NULL ;
}
F_9 ( V_36 ) ;
V_36 -> V_42 = F_10 ( V_35 ) ;
V_36 -> V_35 [ 0 ] = V_35 ;
switch ( V_35 ) {
case V_43 :
V_29 = sizeof( V_44 ) ;
V_36 -> V_35 [ 1 ] = 0x10 ;
V_36 -> V_35 [ 4 ] = V_29 ;
break;
case V_45 :
V_29 = sizeof( V_46 ) ;
V_36 -> V_35 [ 1 ] = 0x10 ;
V_36 -> V_35 [ 8 ] = V_29 ;
break;
case V_38 :
V_29 = V_47 ;
V_36 -> V_35 [ 4 ] = V_29 ;
memset ( V_20 , 0 , V_29 ) ;
break;
default:
F_11 ( 1 ) ;
break;
}
V_36 -> V_48 |= V_49 | V_50 |
V_51 ;
V_36 -> V_52 = V_53 ;
V_36 -> V_54 = V_55 ;
if ( F_12 ( V_36 -> V_56 , V_36 , V_20 , V_29 , V_41 ) ) {
F_13 ( V_36 ) ;
return NULL ;
}
return V_36 ;
}
static int F_14 ( struct V_1 * V_2 , int V_57 ,
struct V_17 * V_18 )
{
struct V_34 * V_36 = F_6 ( V_2 , V_38 , V_18 -> V_20 ) ;
int V_4 ;
if ( ! V_36 )
return V_58 ;
V_36 -> V_3 = V_18 -> V_3 ;
memset ( V_36 -> V_3 , 0 , V_8 ) ;
V_36 -> V_59 = V_18 -> V_60 = 0 ;
V_36 -> V_35 [ 0 ] = V_38 ;
if ( V_57 != 0 ) {
V_36 -> V_35 [ 1 ] = 1 ;
V_36 -> V_35 [ 2 ] = V_57 ;
}
V_4 = F_15 ( V_2 -> V_37 , NULL , V_36 , 1 ) ;
if ( V_4 == - V_61 ) {
F_3 ( V_14 , V_2 ,
L_20 ,
V_10 , V_57 ? L_21 : L_22 ,
V_36 -> V_62 ) ;
V_18 -> V_60 = V_36 -> V_59 ;
V_4 = V_5 ;
}
F_13 ( V_36 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_34 * V_36 ;
unsigned char * V_63 ;
int V_4 , V_29 , V_35 ;
if ( V_18 -> V_64 & V_65 ) {
V_63 = V_44 ;
if ( ! ( V_18 -> V_64 & V_66 ) )
V_63 [ 6 ] |= 0x80 ;
V_29 = sizeof( V_44 ) ;
V_35 = V_43 ;
} else {
V_63 = V_46 ;
if ( ! ( V_18 -> V_64 & V_66 ) )
V_63 [ 10 ] |= 0x80 ;
V_29 = sizeof( V_46 ) ;
V_35 = V_45 ;
}
F_11 ( ( V_29 > V_47 ) ) ;
memcpy ( V_18 -> V_20 , V_63 , V_29 ) ;
V_36 = F_6 ( V_2 , V_35 , V_18 -> V_20 ) ;
if ( ! V_36 )
return V_58 ;
V_36 -> V_3 = V_18 -> V_3 ;
memset ( V_36 -> V_3 , 0 , V_8 ) ;
V_36 -> V_59 = V_18 -> V_60 = 0 ;
V_4 = F_15 ( V_2 -> V_37 , NULL , V_36 , 1 ) ;
if ( V_4 == - V_61 ) {
if ( V_36 -> V_59 ) {
V_4 = F_1 ( V_2 , V_18 -> V_3 ) ;
} else {
F_3 ( V_14 , V_2 ,
L_23 ,
V_10 , V_36 -> V_62 ) ;
}
}
F_13 ( V_36 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_6 * V_67 )
{
switch ( V_67 -> V_11 ) {
case V_68 :
if ( V_67 -> V_12 == 0x04 && V_67 -> V_13 == 0x03 )
return V_69 ;
break;
case V_70 :
if ( V_67 -> V_12 == 0x25 && V_67 -> V_13 == 0x01 )
return V_69 ;
break;
case V_71 :
if ( V_67 -> V_12 == 0x29 && V_67 -> V_13 == 0x00 )
return V_72 ;
break;
}
return V_73 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_34 * V_74 )
{
struct V_17 * V_75 = V_2 -> V_76 ;
int V_77 = V_78 ;
if ( V_75 -> V_26 != V_79 ) {
V_77 = V_80 ;
V_74 -> V_48 |= V_81 ;
}
return V_77 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_4 ;
char * V_30 ;
V_4 = F_14 ( V_2 , 0 , V_18 ) ;
if ( V_4 != V_19 && V_18 -> V_60 ) {
struct V_6 V_7 ;
if ( F_2 ( V_18 -> V_3 , V_8 ,
& V_7 ) ) {
F_3 ( V_9 , V_2 , L_24
L_25 , V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_13 ) ;
}
V_4 = V_5 ;
goto V_22;
}
V_30 = F_5 ( V_2 , V_18 -> V_20 ) ;
if ( ! V_30 ) {
V_4 = V_82 ;
goto V_22;
}
if ( ! strlen ( V_30 ) || ! strncmp ( V_30 , L_26 , 2 ) )
V_18 -> V_64 |= V_65 ;
F_3 ( V_14 , V_2 ,
L_27 ,
V_10 , V_30 , V_18 -> V_64 ) ;
V_22:
return V_4 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_4 , V_83 = V_55 ;
V_83:
V_4 = F_14 ( V_2 , 0xC0 , V_18 ) ;
if ( V_4 != V_19 && V_18 -> V_60 ) {
struct V_6 V_7 ;
V_4 = F_2 ( V_18 -> V_3 , V_8 ,
& V_7 ) ;
if ( ! V_4 )
return V_5 ;
V_4 = F_17 ( V_2 , & V_7 ) ;
if ( V_83 > 0 && V_4 == V_72 ) {
V_83 -- ;
goto V_83;
}
F_3 ( V_9 , V_2 , L_24
L_25 , V_10 ,
V_7 . V_11 , V_7 . V_12 , V_7 . V_13 ) ;
V_4 = V_5 ;
} else {
V_4 = F_4 ( V_2 , V_18 ) ;
}
return V_4 ;
}
static int F_21 ( struct V_1 * V_2 ,
T_1 V_84 , void * V_85 )
{
struct V_17 * V_18 = V_2 -> V_76 ;
int V_86 ;
V_86 = F_20 ( V_2 , V_18 ) ;
if ( V_86 != V_19 )
goto V_87;
if ( V_18 -> V_26 == V_79 )
goto V_87;
V_86 = F_16 ( V_2 , V_18 ) ;
if ( V_86 != V_19 )
goto V_87;
F_3 ( V_14 , V_2 , L_28 ,
V_10 ,
V_18 -> V_64 & V_65 ? L_29 : L_30 ) ;
V_86 = F_20 ( V_2 , V_18 ) ;
if ( V_86 != V_19 )
goto V_87;
V_87:
F_3 ( V_14 , V_2 ,
L_31 ,
V_10 , V_18 -> V_27 + 'A' ,
V_18 -> V_28 , V_26 [ V_18 -> V_26 ] ,
V_18 -> V_25 + 'A' ) ;
if ( V_84 )
V_84 ( V_85 , V_86 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , const char * V_88 )
{
struct V_17 * V_18 = V_2 -> V_76 ;
unsigned int V_89 = 0 , V_90 = 0 , V_91 ;
const char * V_92 = V_88 ;
int V_86 = V_19 ;
if ( ( sscanf ( V_88 , L_32 , & V_91 ) != 1 ) || ( V_91 != 2 ) )
return - V_93 ;
while ( * V_92 ++ )
;
if ( ( sscanf ( V_92 , L_32 , & V_90 ) != 1 ) || ( V_90 > 1 ) )
return - V_93 ;
while ( * V_92 ++ )
;
if ( ( sscanf ( V_92 , L_32 , & V_89 ) != 1 ) || ( V_89 > 1 ) )
return - V_93 ;
if ( V_90 )
V_18 -> V_64 |= V_65 ;
else
V_18 -> V_64 &= ~ V_65 ;
if ( V_89 )
V_18 -> V_64 |= V_66 ;
else
V_18 -> V_64 &= ~ V_66 ;
if ( V_18 -> V_26 != V_79 )
goto V_87;
V_18 -> V_26 = V_94 ;
V_86 = F_16 ( V_2 , V_18 ) ;
if ( V_86 != V_19 )
goto V_87;
V_86 = F_20 ( V_2 , V_18 ) ;
V_87:
return V_86 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_75 ;
int V_4 ;
V_75 = F_24 ( sizeof( * V_75 ) , V_95 ) ;
if ( ! V_75 )
return - V_96 ;
V_75 -> V_26 = V_94 ;
V_75 -> V_25 = V_97 ;
V_75 -> V_27 = V_97 ;
V_4 = F_19 ( V_2 , V_75 ) ;
if ( V_4 != V_19 )
goto V_98;
V_4 = F_20 ( V_2 , V_75 ) ;
if ( V_4 != V_19 )
goto V_98;
F_3 ( V_14 , V_2 ,
L_33 ,
V_10 , V_75 -> V_27 + 'A' ,
V_75 -> V_28 , V_26 [ V_75 -> V_26 ] ,
V_75 -> V_25 + 'A' ) ;
V_2 -> V_76 = V_75 ;
return 0 ;
V_98:
F_25 ( V_75 ) ;
return - V_93 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_76 ) ;
V_2 -> V_76 = NULL ;
}
static int T_2 F_27 ( void )
{
int V_99 ;
V_99 = F_28 ( & V_100 ) ;
if ( V_99 != 0 )
F_29 ( V_9 L_34 ,
V_10 ) ;
return V_99 ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_100 ) ;
}
