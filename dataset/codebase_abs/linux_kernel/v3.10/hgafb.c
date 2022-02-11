static inline T_1 T_2 * F_1 ( struct V_1 * V_2 , T_3 V_3 )
{
return V_2 -> V_4 + F_2 ( V_3 ) ;
}
static void F_3 ( unsigned int V_5 , unsigned char V_6 )
{
F_4 ( V_6 , V_7 ) ;
F_4 ( V_5 , V_8 ) ;
}
static void F_5 ( unsigned int V_5 , unsigned char V_6 )
{
F_4 ( V_6 , V_7 ) ; F_4 ( V_5 >> 8 , V_8 ) ;
F_4 ( V_6 + 1 , V_7 ) ; F_4 ( V_5 & 0xff , V_8 ) ;
}
static int F_6 ( unsigned char V_5 , unsigned char V_6 )
{
F_4 ( V_6 , V_7 ) ;
F_7 ( V_5 , V_8 ) ;
F_8 ( 20 ) ; V_5 = ( F_9 ( V_8 ) == V_5 ) ;
return V_5 ;
}
static void F_10 ( void )
{
unsigned char V_9 = 0xbf ;
unsigned long V_10 ;
F_11 ( & V_11 , V_10 ) ;
if ( V_12 == V_13 )
V_9 = ' ' ;
else if ( V_12 == V_14 )
V_9 = 0x00 ;
F_12 ( & V_11 , V_10 ) ;
if ( V_9 != 0xbf )
F_13 ( V_15 , V_9 , V_16 ) ;
}
static void F_14 ( void )
{
unsigned long V_10 ;
F_11 ( & V_11 , V_10 ) ;
F_4 ( V_17 | V_18 , V_19 ) ;
F_4 ( 0x00 , V_20 ) ;
F_4 ( 0x00 , V_21 ) ;
F_3 ( 0x61 , 0x00 ) ;
F_3 ( 0x50 , 0x01 ) ;
F_3 ( 0x52 , 0x02 ) ;
F_3 ( 0x0f , 0x03 ) ;
F_3 ( 0x19 , 0x04 ) ;
F_3 ( 0x06 , 0x05 ) ;
F_3 ( 0x19 , 0x06 ) ;
F_3 ( 0x19 , 0x07 ) ;
F_3 ( 0x02 , 0x08 ) ;
F_3 ( 0x0d , 0x09 ) ;
F_3 ( 0x0c , 0x0a ) ;
F_3 ( 0x0d , 0x0b ) ;
F_5 ( 0x0000 , 0x0c ) ;
F_5 ( 0x0000 , 0x0e ) ;
V_12 = V_13 ;
F_12 ( & V_11 , V_10 ) ;
}
static void F_15 ( void )
{
unsigned long V_10 ;
F_11 ( & V_11 , V_10 ) ;
F_4 ( 0x00 , V_21 ) ;
F_4 ( V_22 , V_20 ) ;
F_4 ( V_17 | V_23 , V_19 ) ;
F_3 ( 0x35 , 0x00 ) ;
F_3 ( 0x2d , 0x01 ) ;
F_3 ( 0x2e , 0x02 ) ;
F_3 ( 0x07 , 0x03 ) ;
F_3 ( 0x5b , 0x04 ) ;
F_3 ( 0x02 , 0x05 ) ;
F_3 ( 0x57 , 0x06 ) ;
F_3 ( 0x57 , 0x07 ) ;
F_3 ( 0x02 , 0x08 ) ;
F_3 ( 0x03 , 0x09 ) ;
F_3 ( 0x00 , 0x0a ) ;
F_3 ( 0x00 , 0x0b ) ;
F_5 ( 0x0000 , 0x0c ) ;
F_5 ( 0x0000 , 0x0e ) ;
V_12 = V_14 ;
F_12 ( & V_11 , V_10 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
}
static void F_17 ( unsigned int V_24 , unsigned int V_25 )
{
unsigned int V_26 ;
unsigned long V_10 ;
V_26 = ( V_25 / 8 ) * 90 + V_24 ;
F_11 ( & V_11 , V_10 ) ;
F_5 ( V_26 , 0x0c ) ;
F_12 ( & V_11 , V_10 ) ;
F_18 ( L_1 , V_26 ) ;
}
static void F_19 ( int V_27 )
{
unsigned long V_10 ;
F_11 ( & V_11 , V_10 ) ;
if ( V_27 ) {
F_4 ( 0x00 , V_19 ) ;
} else {
F_4 ( V_17 | V_23 , V_19 ) ;
}
F_12 ( & V_11 , V_10 ) ;
}
static int F_20 ( void )
{
int V_28 = 0 ;
void T_2 * V_29 , * V_30 ;
unsigned short V_31 , V_32 ;
V_16 = 0x08000 ;
V_15 = F_21 ( 0xb0000 , V_16 ) ;
if ( F_22 ( 0x3b0 , 12 , L_2 ) )
V_33 = 1 ;
if ( F_22 ( 0x3bf , 1 , L_2 ) )
V_34 = 1 ;
V_29 = V_15 ;
V_30 = V_15 + 0x01000 ;
V_31 = F_23 ( V_29 ) ; V_32 = F_23 ( V_30 ) ;
F_24 ( 0xaa55 , V_29 ) ; if ( F_23 ( V_29 ) == 0xaa55 ) V_28 ++ ;
F_24 ( 0x55aa , V_29 ) ; if ( F_23 ( V_29 ) == 0x55aa ) V_28 ++ ;
F_24 ( V_31 , V_29 ) ;
if ( V_28 != 2 )
goto error;
if ( ! F_6 ( 0x66 , 0x0f ) )
goto error;
if ( ! F_6 ( 0x99 , 0x0f ) )
goto error;
V_31 = V_32 = F_9 ( V_21 ) & V_35 ;
for ( V_28 = 0 ; V_28 < 50000 && V_31 == V_32 ; V_28 ++ ) {
V_32 = F_25 ( V_21 ) & V_35 ;
F_8 ( 2 ) ;
}
if ( V_31 == V_32 )
goto error;
switch ( F_9 ( V_21 ) & 0x70 ) {
case 0x10 :
V_36 = V_37 ;
V_38 = L_3 ;
break;
case 0x50 :
V_36 = V_39 ;
V_38 = L_4 ;
break;
default:
V_36 = V_40 ;
V_38 = L_5 ;
break;
}
return 1 ;
error:
if ( V_33 )
F_26 ( 0x3b0 , 12 ) ;
if ( V_34 )
F_26 ( 0x3bf , 1 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , int V_41 )
{
F_15 () ;
F_10 () ;
if ( ! V_42 ) F_16 ( V_2 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 , int V_41 )
{
F_14 () ;
F_10 () ;
return 0 ;
}
static int F_29 ( T_3 V_43 , T_3 V_44 , T_3 V_45 , T_3 V_46 ,
T_3 V_47 , struct V_1 * V_2 )
{
if ( V_43 > 1 )
return 1 ;
return 0 ;
}
static int F_30 ( struct V_48 * V_49 ,
struct V_1 * V_2 )
{
if ( V_49 -> V_50 & V_51 ) {
if ( V_49 -> V_25 < 0 ||
V_49 -> V_25 >= V_2 -> V_49 . V_52 ||
V_49 -> V_24 )
return - V_53 ;
} else {
if ( V_49 -> V_24 + V_2 -> V_49 . V_54 > V_2 -> V_49 . V_55
|| V_49 -> V_25 + V_2 -> V_49 . V_56 > V_2 -> V_49 . V_52
|| V_49 -> V_25 % 8 )
return - V_53 ;
}
F_17 ( V_49 -> V_24 , V_49 -> V_25 ) ;
return 0 ;
}
static int F_31 ( int V_27 , struct V_1 * V_2 )
{
F_19 ( V_27 ) ;
return 0 ;
}
static void F_32 ( struct V_1 * V_2 , const struct V_57 * V_58 )
{
T_3 V_59 , V_60 ;
T_1 T_2 * V_61 ;
V_60 = V_58 -> V_62 ;
for ( V_59 = V_58 -> V_63 ; V_59 -- ; V_60 ++ ) {
V_61 = F_1 ( V_2 , V_60 ) + ( V_58 -> V_64 >> 3 ) ;
switch ( V_58 -> V_65 ) {
case V_66 :
F_13 ( V_61 , V_58 -> V_67 , ( V_58 -> V_68 >> 3 ) ) ;
break;
case V_69 :
F_33 ( ~ ( F_34 ( V_61 ) ) , V_61 ) ;
break;
}
}
}
static void F_35 ( struct V_1 * V_2 , const struct V_70 * V_71 )
{
T_3 V_59 , y1 , V_72 ;
T_1 T_2 * V_73 ;
T_1 T_2 * V_61 ;
if ( V_71 -> V_62 <= V_71 -> V_74 ) {
y1 = V_71 -> V_74 ;
V_72 = V_71 -> V_62 ;
for ( V_59 = V_71 -> V_63 ; V_59 -- ; ) {
V_73 = F_1 ( V_2 , y1 ) + ( V_71 -> V_75 >> 3 ) ;
V_61 = F_1 ( V_2 , V_72 ) + ( V_71 -> V_64 >> 3 ) ;
memmove ( V_61 , V_73 , ( V_71 -> V_68 >> 3 ) ) ;
y1 ++ ;
V_72 ++ ;
}
} else {
y1 = V_71 -> V_74 + V_71 -> V_63 - 1 ;
V_72 = V_71 -> V_62 + V_71 -> V_63 - 1 ;
for ( V_59 = V_71 -> V_63 ; V_59 -- ; ) {
V_73 = F_1 ( V_2 , y1 ) + ( V_71 -> V_75 >> 3 ) ;
V_61 = F_1 ( V_2 , V_72 ) + ( V_71 -> V_64 >> 3 ) ;
memmove ( V_61 , V_73 , ( V_71 -> V_68 >> 3 ) ) ;
y1 -- ;
V_72 -- ;
}
}
}
static void F_36 ( struct V_1 * V_2 , const struct V_76 * V_77 )
{
T_1 T_2 * V_61 ;
T_1 * V_78 = ( T_1 * ) V_77 -> V_79 ;
T_3 V_59 , V_60 = V_77 -> V_62 ;
T_3 V_80 ;
T_1 V_81 ;
for ( V_59 = V_77 -> V_63 ; V_59 -- ; V_60 ++ ) {
for ( V_80 = 0 ; V_80 < V_77 -> V_68 ; V_80 += 8 ) {
V_81 = * V_78 ++ ;
V_61 = F_1 ( V_2 , V_60 ) + ( ( V_77 -> V_64 + V_80 ) >> 3 ) ;
F_33 ( V_81 , V_61 ) ;
}
}
}
static int F_37 ( struct V_82 * V_83 )
{
struct V_1 * V_2 ;
if ( ! F_20 () ) {
F_38 ( V_84 L_6 ) ;
if ( V_15 )
F_39 ( V_15 ) ;
return - V_53 ;
}
F_38 ( V_84 L_7 ,
V_38 , V_16 / 1024 ) ;
V_2 = F_40 ( 0 , & V_83 -> V_85 ) ;
if ( ! V_2 ) {
F_39 ( V_15 ) ;
return - V_86 ;
}
V_87 . V_88 = ( unsigned long ) V_15 ;
V_87 . V_89 = V_16 ;
V_2 -> V_10 = V_90 | V_91 ;
V_2 -> V_49 = V_92 ;
V_2 -> V_93 = V_87 ;
V_2 -> V_94 . V_95 = 0 ;
V_2 -> V_94 . V_96 = 0 ;
V_2 -> V_94 . V_97 = 10000 ;
V_2 -> V_94 . V_98 = 10000 ;
V_2 -> V_94 . V_99 = 0 ;
V_2 -> V_100 = & V_101 ;
V_2 -> V_4 = V_15 ;
if ( F_41 ( V_2 ) < 0 ) {
F_42 ( V_2 ) ;
F_39 ( V_15 ) ;
return - V_53 ;
}
F_38 ( V_84 L_8 ,
V_2 -> V_102 , V_2 -> V_93 . V_103 ) ;
F_43 ( V_83 , V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_82 * V_83 )
{
struct V_1 * V_2 = F_45 ( V_83 ) ;
F_14 () ;
F_10 () ;
if ( V_2 ) {
F_46 ( V_2 ) ;
F_42 ( V_2 ) ;
}
F_39 ( V_15 ) ;
if ( V_33 )
F_26 ( 0x3b0 , 12 ) ;
if ( V_34 )
F_26 ( 0x3bf , 1 ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
int V_104 ;
if ( F_48 ( L_2 , NULL ) )
return - V_105 ;
V_104 = F_49 ( & V_106 ) ;
if ( ! V_104 ) {
V_107 = F_50 ( L_2 , 0 , NULL , 0 ) ;
if ( F_51 ( V_107 ) ) {
F_52 ( & V_106 ) ;
V_104 = F_53 ( V_107 ) ;
}
}
return V_104 ;
}
static void T_5 F_54 ( void )
{
F_55 ( V_107 ) ;
F_52 ( & V_106 ) ;
}
