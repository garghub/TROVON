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
V_38 -> V_44 = F_10 ( V_37 ) ;
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
V_38 -> V_50 = V_51 ;
V_38 -> V_52 |= V_53 | V_54 |
V_55 ;
V_38 -> V_56 = V_57 ;
V_38 -> V_58 = V_59 ;
if ( F_11 ( V_38 -> V_60 , V_38 , V_22 , V_31 , V_43 ) ) {
F_12 ( V_38 ) ;
return NULL ;
}
return V_38 ;
}
static int F_13 ( struct V_2 * V_3 , int V_61 ,
struct V_1 * V_20 )
{
struct V_36 * V_38 = F_8 ( V_3 , V_40 , V_20 -> V_22 ) ;
int V_7 ;
if ( ! V_38 )
return V_62 ;
V_38 -> V_6 = V_20 -> V_6 ;
memset ( V_38 -> V_6 , 0 , V_11 ) ;
V_38 -> V_63 = V_20 -> V_64 = 0 ;
V_38 -> V_37 [ 0 ] = V_40 ;
if ( V_61 != 0 ) {
V_38 -> V_37 [ 1 ] = 1 ;
V_38 -> V_37 [ 2 ] = V_61 ;
}
V_7 = F_14 ( V_3 -> V_39 , NULL , V_38 , 1 ) ;
if ( V_7 == - V_65 ) {
F_5 ( V_17 , V_3 ,
L_20 ,
V_13 , V_61 ? L_21 : L_22 ,
V_38 -> V_66 ) ;
V_20 -> V_64 = V_38 -> V_63 ;
V_7 = V_8 ;
}
F_12 ( V_38 ) ;
return V_7 ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
struct V_36 * V_38 ;
unsigned char * V_67 ;
int V_7 , V_31 , V_37 ;
if ( V_20 -> V_68 & V_69 ) {
V_67 = V_46 ;
if ( ! ( V_20 -> V_68 & V_70 ) )
V_67 [ 6 ] |= 0x80 ;
V_31 = sizeof( V_46 ) ;
V_37 = V_45 ;
} else {
V_67 = V_48 ;
if ( ! ( V_20 -> V_68 & V_70 ) )
V_67 [ 10 ] |= 0x80 ;
V_31 = sizeof( V_48 ) ;
V_37 = V_47 ;
}
F_2 ( ( V_31 > V_49 ) ) ;
memcpy ( V_20 -> V_22 , V_67 , V_31 ) ;
V_38 = F_8 ( V_3 , V_37 , V_20 -> V_22 ) ;
if ( ! V_38 )
return V_62 ;
V_38 -> V_6 = V_20 -> V_6 ;
memset ( V_38 -> V_6 , 0 , V_11 ) ;
V_38 -> V_63 = V_20 -> V_64 = 0 ;
V_7 = F_14 ( V_3 -> V_39 , NULL , V_38 , 1 ) ;
if ( V_7 == - V_65 ) {
if ( V_38 -> V_63 ) {
V_7 = F_3 ( V_3 , V_20 -> V_6 ) ;
} else {
F_5 ( V_17 , V_3 ,
L_23 ,
V_13 , V_38 -> V_66 ) ;
}
}
F_12 ( V_38 ) ;
return V_7 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_9 * V_71 )
{
switch ( V_71 -> V_14 ) {
case V_72 :
if ( V_71 -> V_15 == 0x04 && V_71 -> V_16 == 0x03 )
return V_73 ;
break;
case V_74 :
if ( V_71 -> V_15 == 0x25 && V_71 -> V_16 == 0x01 )
return V_73 ;
break;
case V_75 :
if ( V_71 -> V_15 == 0x29 && V_71 -> V_16 == 0x00 )
return V_76 ;
break;
}
return V_77 ;
}
static int F_17 ( struct V_2 * V_3 , struct V_36 * V_78 )
{
struct V_1 * V_79 = F_1 ( V_3 ) ;
int V_80 = V_81 ;
if ( V_79 -> V_28 != V_82 ) {
V_80 = V_83 ;
V_78 -> V_52 |= V_84 ;
}
return V_80 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
int V_7 ;
char * V_32 ;
V_7 = F_13 ( V_3 , 0 , V_20 ) ;
if ( V_7 != V_21 && V_20 -> V_64 ) {
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
V_7 = V_85 ;
goto V_24;
}
if ( ! strlen ( V_32 ) || ! strncmp ( V_32 , L_26 , 2 ) )
V_20 -> V_68 |= V_69 ;
F_5 ( V_17 , V_3 ,
L_27 ,
V_13 , V_32 , V_20 -> V_68 ) ;
V_24:
return V_7 ;
}
static int F_19 ( struct V_2 * V_3 ,
struct V_1 * V_20 )
{
int V_7 , V_86 = V_59 ;
V_86:
V_7 = F_13 ( V_3 , 0xC0 , V_20 ) ;
if ( V_7 != V_21 && V_20 -> V_64 ) {
struct V_9 V_10 ;
V_7 = F_4 ( V_20 -> V_6 , V_11 ,
& V_10 ) ;
if ( ! V_7 )
return V_8 ;
V_7 = F_16 ( V_3 , & V_10 ) ;
if ( V_86 > 0 && V_7 == V_76 ) {
V_86 -- ;
goto V_86;
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
static int F_20 ( struct V_2 * V_3 ,
T_1 V_87 , void * V_88 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
int V_89 ;
V_89 = F_19 ( V_3 , V_20 ) ;
if ( V_89 != V_21 )
goto V_90;
if ( V_20 -> V_28 == V_82 )
goto V_90;
V_89 = F_15 ( V_3 , V_20 ) ;
if ( V_89 != V_21 )
goto V_90;
F_5 ( V_17 , V_3 , L_28 ,
V_13 ,
V_20 -> V_68 & V_69 ? L_29 : L_30 ) ;
V_89 = F_19 ( V_3 , V_20 ) ;
if ( V_89 != V_21 )
goto V_90;
V_90:
F_5 ( V_17 , V_3 ,
L_31 ,
V_13 , V_20 -> V_29 + 'A' ,
V_20 -> V_30 , V_28 [ V_20 -> V_28 ] ,
V_20 -> V_27 + 'A' ) ;
if ( V_87 )
V_87 ( V_88 , V_89 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 , const char * V_91 )
{
struct V_1 * V_20 = F_1 ( V_3 ) ;
unsigned int V_92 = 0 , V_93 = 0 , V_94 ;
const char * V_95 = V_91 ;
int V_89 = V_21 ;
if ( ( sscanf ( V_91 , L_32 , & V_94 ) != 1 ) || ( V_94 != 2 ) )
return - V_96 ;
while ( * V_95 ++ )
;
if ( ( sscanf ( V_95 , L_32 , & V_93 ) != 1 ) || ( V_93 > 1 ) )
return - V_96 ;
while ( * V_95 ++ )
;
if ( ( sscanf ( V_95 , L_32 , & V_92 ) != 1 ) || ( V_92 > 1 ) )
return - V_96 ;
if ( V_93 )
V_20 -> V_68 |= V_69 ;
else
V_20 -> V_68 &= ~ V_69 ;
if ( V_92 )
V_20 -> V_68 |= V_70 ;
else
V_20 -> V_68 &= ~ V_70 ;
if ( V_20 -> V_28 != V_82 )
goto V_90;
V_20 -> V_28 = V_97 ;
V_89 = F_15 ( V_3 , V_20 ) ;
if ( V_89 != V_21 )
goto V_90;
V_89 = F_19 ( V_3 , V_20 ) ;
V_90:
return V_89 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_79 ;
unsigned long V_68 ;
int V_7 ;
V_4 = F_23 ( sizeof( * V_4 )
+ sizeof( * V_79 ) , V_98 ) ;
if ( ! V_4 ) {
F_5 ( V_12 , V_3 , L_33 ,
V_13 ) ;
return - V_99 ;
}
V_4 -> V_100 = & V_101 ;
V_79 = (struct V_1 * ) V_4 -> V_5 ;
V_79 -> V_28 = V_97 ;
V_79 -> V_27 = V_102 ;
V_79 -> V_29 = V_102 ;
V_7 = F_18 ( V_3 , V_79 ) ;
if ( V_7 != V_21 )
goto V_103;
V_7 = F_19 ( V_3 , V_79 ) ;
if ( V_7 != V_21 )
goto V_103;
if ( ! F_24 ( V_104 ) )
goto V_103;
F_25 ( V_3 -> V_39 -> V_105 , V_68 ) ;
V_3 -> V_4 = V_4 ;
F_26 ( V_3 -> V_39 -> V_105 , V_68 ) ;
F_5 ( V_17 , V_3 ,
L_34 ,
V_13 , V_79 -> V_29 + 'A' ,
V_79 -> V_30 , V_28 [ V_79 -> V_28 ] ,
V_79 -> V_27 + 'A' ) ;
return 0 ;
V_103:
F_27 ( V_4 ) ;
F_5 ( V_12 , V_3 , L_35 ,
V_13 ) ;
return - V_96 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
unsigned long V_68 ;
F_25 ( V_3 -> V_39 -> V_105 , V_68 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_26 ( V_3 -> V_39 -> V_105 , V_68 ) ;
F_5 ( V_23 , V_3 , L_36 ,
V_13 ) ;
F_27 ( V_4 ) ;
F_29 ( V_104 ) ;
}
static int T_2 F_30 ( void )
{
int V_106 ;
V_106 = F_31 ( & V_101 ) ;
if ( V_106 != 0 )
F_32 ( V_12 L_37 ,
V_13 ) ;
return V_106 ;
}
static void T_3 F_33 ( void )
{
F_34 ( & V_101 ) ;
}
