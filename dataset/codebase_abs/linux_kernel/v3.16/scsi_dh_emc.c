static inline struct V_1
* F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
F_2 ( V_4 == NULL ) ;
return ( (struct V_1 * ) V_4 -> V_5 ) ;
}
static int F_3 ( struct V_2 * V_3 , char * V_6 )
{
int V_7 = V_8 ;
struct V_9 V_10 ;
if ( ! F_4 ( V_6 , V_11 , & V_10 ) ) {
F_5 ( V_12 , V_3 , L_1
L_2
L_3 , V_13 , V_10 . V_14 ,
V_10 . V_15 , V_10 . V_16 ) ;
if ( ( V_10 . V_14 == 0x05 ) && ( V_10 . V_15 == 0x04 ) &&
( V_10 . V_16 == 0x00 ) ) {
F_5 ( V_17 , V_3 , L_4
L_5
L_3 , V_13 ) ;
V_7 = V_18 ;
} else if ( ( V_10 . V_14 == 0x02 ) && ( V_10 . V_15 == 0x04 ) &&
( V_10 . V_16 == 0x03 ) ) {
F_5 ( V_17 , V_3 , L_6
L_7
L_8 , V_13 ) ;
V_7 = V_18 ;
} else
V_7 = V_19 ;
} else {
F_5 ( V_17 , V_3 ,
L_9 ,
V_13 ) ;
}
return V_7 ;
}
static int F_6 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
int V_7 = V_21 ;
if ( V_20 -> V_22 [ 48 ] != 0 ) {
F_5 ( V_23 , V_3 , L_6
L_10
L_11 , V_13 ) ;
V_7 = V_18 ;
goto V_24;
}
if ( V_20 -> V_22 [ 4 ] > 2 ) {
F_5 ( V_23 , V_3 ,
L_12 ,
V_13 ) ;
V_7 = V_25 ;
goto V_24;
}
switch ( V_20 -> V_22 [ 28 ] & 0x0f ) {
case 6 :
F_5 ( V_23 , V_3 ,
L_13 ,
V_13 ) ;
break;
case 4 :
break;
default:
F_5 ( V_26 , V_3 ,
L_14 ,
V_13 , V_20 -> V_22 [ 28 ] & 0x0f ) ;
V_7 = V_25 ;
goto V_24;
}
V_20 -> V_27 = V_20 -> V_22 [ 5 ] ;
V_20 -> V_28 = V_20 -> V_22 [ 4 ] ;
V_20 -> V_29 = V_20 -> V_22 [ 8 ] ;
V_20 -> V_30 = V_20 -> V_22 [ 7 ] ;
V_24:
return V_7 ;
}
static char * F_7 ( struct V_2 * V_3 , unsigned char * V_22 )
{
unsigned char V_31 = V_22 [ 4 ] + 5 ;
char * V_32 = NULL ;
unsigned char V_33 , V_34 ;
if ( V_31 < 160 ) {
F_5 ( V_26 , V_3 ,
L_15 ,
V_13 , V_31 ) ;
if ( ! strncmp ( V_22 + 8 , L_16 , 3 ) ) {
V_32 = V_35 ;
}
goto V_24;
}
V_34 = V_22 [ 160 ] ;
if ( V_34 == 0 || V_34 + 161 > V_31 ) {
F_5 ( V_26 , V_3 ,
L_17 ,
V_13 , V_34 ) ;
goto V_24;
}
V_33 = V_22 [ 99 ] ;
if ( V_33 == 0 || V_34 + V_33 + 161 > V_31 ) {
F_5 ( V_26 , V_3 ,
L_18 ,
V_13 , V_33 ) ;
goto V_24;
}
V_32 = & V_22 [ V_34 + 161 ] ;
while ( V_33 > 1 && V_32 [ V_33 - 1 ] == ' ' )
V_33 -- ;
V_32 [ V_33 ] = '\0' ;
V_24:
return V_32 ;
}
static struct V_36 * F_8 ( struct V_2 * V_3 , int V_37 ,
unsigned char * V_22 )
{
struct V_36 * V_38 ;
int V_31 = 0 ;
V_38 = F_9 ( V_3 -> V_39 ,
( V_37 != V_40 ) ? V_41 : V_42 , V_43 ) ;
if ( ! V_38 ) {
F_5 ( V_17 , V_3 , L_19 ) ;
return NULL ;
}
F_10 ( V_38 ) ;
V_38 -> V_44 = F_11 ( V_37 ) ;
V_38 -> V_37 [ 0 ] = V_37 ;
switch ( V_37 ) {
case V_45 :
V_31 = sizeof( V_46 ) ;
V_38 -> V_37 [ 1 ] = 0x10 ;
V_38 -> V_37 [ 4 ] = V_31 ;
break;
case V_47 :
V_31 = sizeof( V_48 ) ;
V_38 -> V_37 [ 1 ] = 0x10 ;
V_38 -> V_37 [ 8 ] = V_31 ;
break;
case V_40 :
V_31 = V_49 ;
V_38 -> V_37 [ 4 ] = V_31 ;
memset ( V_22 , 0 , V_31 ) ;
break;
default:
F_2 ( 1 ) ;
break;
}
V_38 -> V_50 |= V_51 | V_52 |
V_53 ;
V_38 -> V_54 = V_55 ;
V_38 -> V_56 = V_57 ;
if ( F_12 ( V_38 -> V_58 , V_38 , V_22 , V_31 , V_43 ) ) {
F_13 ( V_38 ) ;
return NULL ;
}
return V_38 ;
}
static int F_14 ( struct V_2 * V_3 , int V_59 ,
struct V_1 * V_20 )
{
struct V_36 * V_38 = F_8 ( V_3 , V_40 , V_20 -> V_22 ) ;
int V_7 ;
if ( ! V_38 )
return V_60 ;
V_38 -> V_6 = V_20 -> V_6 ;
memset ( V_38 -> V_6 , 0 , V_11 ) ;
V_38 -> V_61 = V_20 -> V_62 = 0 ;
V_38 -> V_37 [ 0 ] = V_40 ;
if ( V_59 != 0 ) {
V_38 -> V_37 [ 1 ] = 1 ;
V_38 -> V_37 [ 2 ] = V_59 ;
}
V_7 = F_15 ( V_3 -> V_39 , NULL , V_38 , 1 ) ;
if ( V_7 == - V_63 ) {
F_5 ( V_17 , V_3 ,
L_20 ,
V_13 , V_59 ? L_21 : L_22 ,
V_38 -> V_64 ) ;
V_20 -> V_62 = V_38 -> V_61 ;
V_7 = V_8 ;
}
F_13 ( V_38 ) ;
return V_7 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
struct V_36 * V_38 ;
unsigned char * V_65 ;
int V_7 , V_31 , V_37 ;
if ( V_20 -> V_66 & V_67 ) {
V_65 = V_46 ;
if ( ! ( V_20 -> V_66 & V_68 ) )
V_65 [ 6 ] |= 0x80 ;
V_31 = sizeof( V_46 ) ;
V_37 = V_45 ;
} else {
V_65 = V_48 ;
if ( ! ( V_20 -> V_66 & V_68 ) )
V_65 [ 10 ] |= 0x80 ;
V_31 = sizeof( V_48 ) ;
V_37 = V_47 ;
}
F_2 ( ( V_31 > V_49 ) ) ;
memcpy ( V_20 -> V_22 , V_65 , V_31 ) ;
V_38 = F_8 ( V_3 , V_37 , V_20 -> V_22 ) ;
if ( ! V_38 )
return V_60 ;
V_38 -> V_6 = V_20 -> V_6 ;
memset ( V_38 -> V_6 , 0 , V_11 ) ;
V_38 -> V_61 = V_20 -> V_62 = 0 ;
V_7 = F_15 ( V_3 -> V_39 , NULL , V_38 , 1 ) ;
if ( V_7 == - V_63 ) {
if ( V_38 -> V_61 ) {
V_7 = F_3 ( V_3 , V_20 -> V_6 ) ;
} else {
F_5 ( V_17 , V_3 ,
L_23 ,
V_13 , V_38 -> V_64 ) ;
}
}
F_13 ( V_38 ) ;
return V_7 ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_9 * V_69 )
{
switch ( V_69 -> V_14 ) {
case V_70 :
if ( V_69 -> V_15 == 0x04 && V_69 -> V_16 == 0x03 )
return V_71 ;
break;
case V_72 :
if ( V_69 -> V_15 == 0x25 && V_69 -> V_16 == 0x01 )
return V_71 ;
break;
case V_73 :
if ( V_69 -> V_15 == 0x29 && V_69 -> V_16 == 0x00 )
return V_74 ;
break;
}
return V_75 ;
}
static int F_18 ( struct V_2 * V_3 , struct V_36 * V_76 )
{
struct V_1 * V_77 = F_1 ( V_3 ) ;
int V_78 = V_79 ;
if ( V_77 -> V_28 != V_80 ) {
V_78 = V_81 ;
V_76 -> V_50 |= V_82 ;
}
return V_78 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
int V_7 ;
char * V_32 ;
V_7 = F_14 ( V_3 , 0 , V_20 ) ;
if ( V_7 != V_21 && V_20 -> V_62 ) {
struct V_9 V_10 ;
if ( F_4 ( V_20 -> V_6 , V_11 ,
& V_10 ) ) {
F_5 ( V_12 , V_3 , L_24
L_25 , V_13 ,
V_10 . V_14 , V_10 . V_15 , V_10 . V_16 ) ;
}
V_7 = V_8 ;
goto V_24;
}
V_32 = F_7 ( V_3 , V_20 -> V_22 ) ;
if ( ! V_32 ) {
V_7 = V_83 ;
goto V_24;
}
if ( ! strlen ( V_32 ) || ! strncmp ( V_32 , L_26 , 2 ) )
V_20 -> V_66 |= V_67 ;
F_5 ( V_17 , V_3 ,
L_27 ,
V_13 , V_32 , V_20 -> V_66 ) ;
V_24:
return V_7 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
int V_7 , V_84 = V_57 ;
V_84:
V_7 = F_14 ( V_3 , 0xC0 , V_20 ) ;
if ( V_7 != V_21 && V_20 -> V_62 ) {
struct V_9 V_10 ;
V_7 = F_4 ( V_20 -> V_6 , V_11 ,
& V_10 ) ;
if ( ! V_7 )
return V_8 ;
V_7 = F_17 ( V_3 , & V_10 ) ;
if ( V_84 > 0 && V_7 == V_74 ) {
V_84 -- ;
goto V_84;
}
F_5 ( V_12 , V_3 , L_24
L_25 , V_13 ,
V_10 . V_14 , V_10 . V_15 , V_10 . V_16 ) ;
V_7 = V_8 ;
} else {
V_7 = F_6 ( V_3 , V_20 ) ;
}
return V_7 ;
}
static int F_21 ( struct V_2 * V_3 ,
T_1 V_85 , void * V_86 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_87 ;
V_87 = F_20 ( V_3 , V_20 ) ;
if ( V_87 != V_21 )
goto V_88;
if ( V_20 -> V_28 == V_80 )
goto V_88;
V_87 = F_16 ( V_3 , V_20 ) ;
if ( V_87 != V_21 )
goto V_88;
F_5 ( V_17 , V_3 , L_28 ,
V_13 ,
V_20 -> V_66 & V_67 ? L_29 : L_30 ) ;
V_87 = F_20 ( V_3 , V_20 ) ;
if ( V_87 != V_21 )
goto V_88;
V_88:
F_5 ( V_17 , V_3 ,
L_31 ,
V_13 , V_20 -> V_29 + 'A' ,
V_20 -> V_30 , V_28 [ V_20 -> V_28 ] ,
V_20 -> V_27 + 'A' ) ;
if ( V_85 )
V_85 ( V_86 , V_87 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 , const char * V_89 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
unsigned int V_90 = 0 , V_91 = 0 , V_92 ;
const char * V_93 = V_89 ;
int V_87 = V_21 ;
if ( ( sscanf ( V_89 , L_32 , & V_92 ) != 1 ) || ( V_92 != 2 ) )
return - V_94 ;
while ( * V_93 ++ )
;
if ( ( sscanf ( V_93 , L_32 , & V_91 ) != 1 ) || ( V_91 > 1 ) )
return - V_94 ;
while ( * V_93 ++ )
;
if ( ( sscanf ( V_93 , L_32 , & V_90 ) != 1 ) || ( V_90 > 1 ) )
return - V_94 ;
if ( V_91 )
V_20 -> V_66 |= V_67 ;
else
V_20 -> V_66 &= ~ V_67 ;
if ( V_90 )
V_20 -> V_66 |= V_68 ;
else
V_20 -> V_66 &= ~ V_68 ;
if ( V_20 -> V_28 != V_80 )
goto V_88;
V_20 -> V_28 = V_95 ;
V_87 = F_16 ( V_3 , V_20 ) ;
if ( V_87 != V_21 )
goto V_88;
V_87 = F_20 ( V_3 , V_20 ) ;
V_88:
return V_87 ;
}
static bool F_23 ( struct V_2 * V_3 )
{
int V_96 ;
if ( F_24 ( V_3 ) )
return false ;
for ( V_96 = 0 ; V_97 [ V_96 ] . V_98 ; V_96 ++ ) {
if ( ! strncmp ( V_3 -> V_98 , V_97 [ V_96 ] . V_98 ,
strlen ( V_97 [ V_96 ] . V_98 ) ) &&
! strncmp ( V_3 -> V_99 , V_97 [ V_96 ] . V_99 ,
strlen ( V_97 [ V_96 ] . V_99 ) ) ) {
return true ;
}
}
return false ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_77 ;
unsigned long V_66 ;
int V_7 ;
V_4 = F_26 ( sizeof( * V_4 )
+ sizeof( * V_77 ) , V_100 ) ;
if ( ! V_4 ) {
F_5 ( V_12 , V_3 , L_33 ,
V_13 ) ;
return - V_101 ;
}
V_4 -> V_102 = & V_103 ;
V_77 = (struct V_1 * ) V_4 -> V_5 ;
V_77 -> V_28 = V_95 ;
V_77 -> V_27 = V_104 ;
V_77 -> V_29 = V_104 ;
V_7 = F_19 ( V_3 , V_77 ) ;
if ( V_7 != V_21 )
goto V_105;
V_7 = F_20 ( V_3 , V_77 ) ;
if ( V_7 != V_21 )
goto V_105;
if ( ! F_27 ( V_106 ) )
goto V_105;
F_28 ( V_3 -> V_39 -> V_107 , V_66 ) ;
V_3 -> V_4 = V_4 ;
F_29 ( V_3 -> V_39 -> V_107 , V_66 ) ;
F_5 ( V_17 , V_3 ,
L_34 ,
V_13 , V_77 -> V_29 + 'A' ,
V_77 -> V_30 , V_28 [ V_77 -> V_28 ] ,
V_77 -> V_27 + 'A' ) ;
return 0 ;
V_105:
F_30 ( V_4 ) ;
F_5 ( V_12 , V_3 , L_35 ,
V_13 ) ;
return - V_94 ;
}
static void F_31 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
unsigned long V_66 ;
F_28 ( V_3 -> V_39 -> V_107 , V_66 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_29 ( V_3 -> V_39 -> V_107 , V_66 ) ;
F_5 ( V_23 , V_3 , L_36 ,
V_13 ) ;
F_30 ( V_4 ) ;
F_32 ( V_106 ) ;
}
static int T_2 F_33 ( void )
{
int V_108 ;
V_108 = F_34 ( & V_103 ) ;
if ( V_108 != 0 )
F_35 ( V_12 L_37 ,
V_13 ) ;
return V_108 ;
}
static void T_3 F_36 ( void )
{
F_37 ( & V_103 ) ;
}
