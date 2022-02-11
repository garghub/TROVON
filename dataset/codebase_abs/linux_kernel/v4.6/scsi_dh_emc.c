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
if ( V_18 -> V_26 == V_29 )
V_2 -> V_30 = V_31 ;
else
V_2 -> V_30 = V_32 ;
if ( V_18 -> V_25 == V_18 -> V_27 )
V_2 -> V_30 |= V_33 ;
V_22:
return V_4 ;
}
static char * F_5 ( struct V_1 * V_2 , unsigned char * V_20 )
{
unsigned char V_34 = V_20 [ 4 ] + 5 ;
char * V_35 = NULL ;
unsigned char V_36 , V_37 ;
if ( V_34 < 160 ) {
F_3 ( V_24 , V_2 ,
L_15 ,
V_10 , V_34 ) ;
if ( ! strncmp ( V_20 + 8 , L_16 , 3 ) ) {
V_35 = V_38 ;
}
goto V_22;
}
V_37 = V_20 [ 160 ] ;
if ( V_37 == 0 || V_37 + 161 > V_34 ) {
F_3 ( V_24 , V_2 ,
L_17 ,
V_10 , V_37 ) ;
goto V_22;
}
V_36 = V_20 [ 99 ] ;
if ( V_36 == 0 || V_37 + V_36 + 161 > V_34 ) {
F_3 ( V_24 , V_2 ,
L_18 ,
V_10 , V_36 ) ;
goto V_22;
}
V_35 = & V_20 [ V_37 + 161 ] ;
while ( V_36 > 1 && V_35 [ V_36 - 1 ] == ' ' )
V_36 -- ;
V_35 [ V_36 ] = '\0' ;
V_22:
return V_35 ;
}
static struct V_39 * F_6 ( struct V_1 * V_2 , int V_40 ,
unsigned char * V_20 )
{
struct V_39 * V_41 ;
int V_34 = 0 ;
V_41 = F_7 ( V_2 -> V_42 ,
( V_40 != V_43 ) ? V_44 : V_45 , V_46 ) ;
if ( F_8 ( V_41 ) ) {
F_3 ( V_14 , V_2 , L_19 ) ;
return NULL ;
}
F_9 ( V_41 ) ;
V_41 -> V_47 = F_10 ( V_40 ) ;
V_41 -> V_40 [ 0 ] = V_40 ;
switch ( V_40 ) {
case V_48 :
V_34 = sizeof( V_49 ) ;
V_41 -> V_40 [ 1 ] = 0x10 ;
V_41 -> V_40 [ 4 ] = V_34 ;
break;
case V_50 :
V_34 = sizeof( V_51 ) ;
V_41 -> V_40 [ 1 ] = 0x10 ;
V_41 -> V_40 [ 8 ] = V_34 ;
break;
case V_43 :
V_34 = V_52 ;
V_41 -> V_40 [ 4 ] = V_34 ;
memset ( V_20 , 0 , V_34 ) ;
break;
default:
F_11 ( 1 ) ;
break;
}
V_41 -> V_53 |= V_54 | V_55 |
V_56 ;
V_41 -> V_57 = V_58 ;
V_41 -> V_59 = V_60 ;
if ( F_12 ( V_41 -> V_61 , V_41 , V_20 , V_34 , V_46 ) ) {
F_13 ( V_41 ) ;
return NULL ;
}
return V_41 ;
}
static int F_14 ( struct V_1 * V_2 , int V_62 ,
struct V_17 * V_18 )
{
struct V_39 * V_41 = F_6 ( V_2 , V_43 , V_18 -> V_20 ) ;
int V_4 ;
if ( ! V_41 )
return V_63 ;
V_41 -> V_3 = V_18 -> V_3 ;
memset ( V_41 -> V_3 , 0 , V_8 ) ;
V_41 -> V_64 = V_18 -> V_65 = 0 ;
V_41 -> V_40 [ 0 ] = V_43 ;
if ( V_62 != 0 ) {
V_41 -> V_40 [ 1 ] = 1 ;
V_41 -> V_40 [ 2 ] = V_62 ;
}
V_4 = F_15 ( V_2 -> V_42 , NULL , V_41 , 1 ) ;
if ( V_4 == - V_66 ) {
F_3 ( V_14 , V_2 ,
L_20 ,
V_10 , V_62 ? L_21 : L_22 ,
V_41 -> V_67 ) ;
V_18 -> V_65 = V_41 -> V_64 ;
V_4 = V_5 ;
}
F_13 ( V_41 ) ;
return V_4 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_39 * V_41 ;
unsigned char * V_68 ;
int V_4 , V_34 , V_40 ;
if ( V_18 -> V_69 & V_70 ) {
V_68 = V_49 ;
if ( ! ( V_18 -> V_69 & V_71 ) )
V_68 [ 6 ] |= 0x80 ;
V_34 = sizeof( V_49 ) ;
V_40 = V_48 ;
} else {
V_68 = V_51 ;
if ( ! ( V_18 -> V_69 & V_71 ) )
V_68 [ 10 ] |= 0x80 ;
V_34 = sizeof( V_51 ) ;
V_40 = V_50 ;
}
F_11 ( ( V_34 > V_52 ) ) ;
memcpy ( V_18 -> V_20 , V_68 , V_34 ) ;
V_41 = F_6 ( V_2 , V_40 , V_18 -> V_20 ) ;
if ( ! V_41 )
return V_63 ;
V_41 -> V_3 = V_18 -> V_3 ;
memset ( V_41 -> V_3 , 0 , V_8 ) ;
V_41 -> V_64 = V_18 -> V_65 = 0 ;
V_4 = F_15 ( V_2 -> V_42 , NULL , V_41 , 1 ) ;
if ( V_4 == - V_66 ) {
if ( V_41 -> V_64 ) {
V_4 = F_1 ( V_2 , V_18 -> V_3 ) ;
} else {
F_3 ( V_14 , V_2 ,
L_23 ,
V_10 , V_41 -> V_67 ) ;
}
}
F_13 ( V_41 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_6 * V_72 )
{
switch ( V_72 -> V_11 ) {
case V_73 :
if ( V_72 -> V_12 == 0x04 && V_72 -> V_13 == 0x03 )
return V_74 ;
break;
case V_75 :
if ( V_72 -> V_12 == 0x25 && V_72 -> V_13 == 0x01 )
return V_74 ;
break;
case V_76 :
if ( V_72 -> V_12 == 0x29 && V_72 -> V_13 == 0x00 )
return V_77 ;
break;
}
return V_78 ;
}
static int F_18 ( struct V_1 * V_2 , struct V_39 * V_79 )
{
struct V_17 * V_80 = V_2 -> V_81 ;
int V_82 = V_83 ;
if ( V_80 -> V_26 != V_29 ) {
V_82 = V_84 ;
V_79 -> V_53 |= V_85 ;
}
return V_82 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_4 ;
char * V_35 ;
V_4 = F_14 ( V_2 , 0 , V_18 ) ;
if ( V_4 != V_19 && V_18 -> V_65 ) {
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
V_35 = F_5 ( V_2 , V_18 -> V_20 ) ;
if ( ! V_35 ) {
V_4 = V_86 ;
goto V_22;
}
if ( ! strlen ( V_35 ) || ! strncmp ( V_35 , L_26 , 2 ) )
V_18 -> V_69 |= V_70 ;
F_3 ( V_14 , V_2 ,
L_27 ,
V_10 , V_35 , V_18 -> V_69 ) ;
V_22:
return V_4 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
int V_4 , V_87 = V_60 ;
V_87:
V_4 = F_14 ( V_2 , 0xC0 , V_18 ) ;
if ( V_4 != V_19 && V_18 -> V_65 ) {
struct V_6 V_7 ;
V_4 = F_2 ( V_18 -> V_3 , V_8 ,
& V_7 ) ;
if ( ! V_4 )
return V_5 ;
V_4 = F_17 ( V_2 , & V_7 ) ;
if ( V_87 > 0 && V_4 == V_77 ) {
V_87 -- ;
goto V_87;
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
T_1 V_88 , void * V_89 )
{
struct V_17 * V_18 = V_2 -> V_81 ;
int V_90 ;
V_90 = F_20 ( V_2 , V_18 ) ;
if ( V_90 != V_19 )
goto V_91;
if ( V_18 -> V_26 == V_29 )
goto V_91;
V_90 = F_16 ( V_2 , V_18 ) ;
if ( V_90 != V_19 )
goto V_91;
F_3 ( V_14 , V_2 , L_28 ,
V_10 ,
V_18 -> V_69 & V_70 ? L_29 : L_30 ) ;
V_90 = F_20 ( V_2 , V_18 ) ;
if ( V_90 != V_19 )
goto V_91;
V_91:
F_3 ( V_14 , V_2 ,
L_31 ,
V_10 , V_18 -> V_27 + 'A' ,
V_18 -> V_28 , V_26 [ V_18 -> V_26 ] ,
V_18 -> V_25 + 'A' ) ;
if ( V_88 )
V_88 ( V_89 , V_90 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , const char * V_92 )
{
struct V_17 * V_18 = V_2 -> V_81 ;
unsigned int V_93 = 0 , V_94 = 0 , V_95 ;
const char * V_96 = V_92 ;
int V_90 = V_19 ;
if ( ( sscanf ( V_92 , L_32 , & V_95 ) != 1 ) || ( V_95 != 2 ) )
return - V_97 ;
while ( * V_96 ++ )
;
if ( ( sscanf ( V_96 , L_32 , & V_94 ) != 1 ) || ( V_94 > 1 ) )
return - V_97 ;
while ( * V_96 ++ )
;
if ( ( sscanf ( V_96 , L_32 , & V_93 ) != 1 ) || ( V_93 > 1 ) )
return - V_97 ;
if ( V_94 )
V_18 -> V_69 |= V_70 ;
else
V_18 -> V_69 &= ~ V_70 ;
if ( V_93 )
V_18 -> V_69 |= V_71 ;
else
V_18 -> V_69 &= ~ V_71 ;
if ( V_18 -> V_26 != V_29 )
goto V_91;
V_18 -> V_26 = V_98 ;
V_90 = F_16 ( V_2 , V_18 ) ;
if ( V_90 != V_19 )
goto V_91;
V_90 = F_20 ( V_2 , V_18 ) ;
V_91:
return V_90 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_80 ;
int V_4 ;
V_80 = F_24 ( sizeof( * V_80 ) , V_99 ) ;
if ( ! V_80 )
return - V_100 ;
V_80 -> V_26 = V_98 ;
V_80 -> V_25 = V_101 ;
V_80 -> V_27 = V_101 ;
V_4 = F_19 ( V_2 , V_80 ) ;
if ( V_4 != V_19 )
goto V_102;
V_4 = F_20 ( V_2 , V_80 ) ;
if ( V_4 != V_19 )
goto V_102;
F_3 ( V_14 , V_2 ,
L_33 ,
V_10 , V_80 -> V_27 + 'A' ,
V_80 -> V_28 , V_26 [ V_80 -> V_26 ] ,
V_80 -> V_25 + 'A' ) ;
V_2 -> V_81 = V_80 ;
return 0 ;
V_102:
F_25 ( V_80 ) ;
return - V_97 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_25 ( V_2 -> V_81 ) ;
V_2 -> V_81 = NULL ;
}
static int T_2 F_27 ( void )
{
int V_103 ;
V_103 = F_28 ( & V_104 ) ;
if ( V_103 != 0 )
F_29 ( V_9 L_34 ,
V_10 ) ;
return V_103 ;
}
static void T_3 F_30 ( void )
{
F_31 ( & V_104 ) ;
}
