static void F_1 ( struct V_1 * V_2 , unsigned short V_3 , unsigned char V_4 )
{
unsigned long V_5 ;
unsigned long V_6 ;
V_6 = ( V_3 & V_7 ) ? V_2 -> V_8 : V_2 -> V_9 ;
F_2 ( & V_2 -> V_10 , V_5 ) ;
F_3 ( ( unsigned char ) V_3 , V_6 ) ;
F_4 ( 10 ) ;
F_3 ( ( unsigned char ) V_4 , V_6 + 1 ) ;
F_4 ( 30 ) ;
F_5 ( & V_2 -> V_10 , V_5 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned short V_3 , unsigned char V_4 )
{
unsigned long V_5 ;
unsigned long V_6 ;
V_6 = ( V_3 & V_7 ) ? V_2 -> V_8 : V_2 -> V_9 ;
F_2 ( & V_2 -> V_10 , V_5 ) ;
F_3 ( ( unsigned char ) V_3 , V_6 ) ;
F_7 ( V_2 -> V_9 ) ;
F_7 ( V_2 -> V_9 ) ;
F_3 ( ( unsigned char ) V_4 , V_6 + 1 ) ;
F_7 ( V_2 -> V_9 ) ;
F_7 ( V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_10 , V_5 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned char V_11 , V_12 , V_13 ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_17 | V_18 ) ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_19 ) ;
V_13 = V_11 = F_7 ( V_2 -> V_9 ) ;
if ( ( V_11 & 0xe0 ) != 0x00 ) {
F_9 ( L_1 , V_11 ) ;
return - V_20 ;
}
V_2 -> V_14 ( V_2 , V_15 | V_21 , 0xff ) ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_18 | V_22 ) ;
F_4 ( 200 ) ;
V_12 = F_7 ( V_2 -> V_9 ) ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_17 | V_18 ) ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_19 ) ;
if ( ( V_12 & 0xe0 ) != 0xc0 ) {
F_9 ( L_2 , V_12 ) ;
return - V_20 ;
}
if ( V_2 -> V_23 != V_24 )
return 0 ;
if ( V_13 == 0x06 ) {
V_2 -> V_23 = V_25 ;
} else {
if ( F_10 ( ! V_2 -> V_8 ) )
return - V_20 ;
V_2 -> V_23 = V_26 ;
}
return 0 ;
}
static int F_11 ( struct V_27 * V_28 )
{
unsigned long V_5 ;
unsigned char V_29 ;
unsigned int V_30 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_28 ) ;
F_2 ( & V_2 -> V_31 , V_5 ) ;
V_30 = V_28 -> V_32 ;
V_29 = ( V_2 -> V_33 | V_22 ) & ~ V_17 ;
V_2 -> V_33 = V_29 ;
V_2 -> V_14 ( V_2 , V_15 | V_21 , 256 - V_30 ) ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_29 ) ;
F_5 ( & V_2 -> V_31 , V_5 ) ;
return 0 ;
}
static int F_13 ( struct V_27 * V_28 )
{
unsigned long V_5 ;
unsigned char V_29 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_28 ) ;
F_2 ( & V_2 -> V_31 , V_5 ) ;
V_29 = ( V_2 -> V_33 | V_17 ) & ~ V_22 ;
V_2 -> V_33 = V_29 ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_29 ) ;
F_5 ( & V_2 -> V_31 , V_5 ) ;
return 0 ;
}
static int F_14 ( struct V_27 * V_28 )
{
unsigned long V_5 ;
unsigned char V_29 ;
unsigned int V_30 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_28 ) ;
F_2 ( & V_2 -> V_31 , V_5 ) ;
V_30 = V_28 -> V_32 ;
V_29 = ( V_2 -> V_33 | V_34 ) & ~ V_18 ;
V_2 -> V_33 = V_29 ;
V_2 -> V_14 ( V_2 , V_15 | V_35 , 256 - V_30 ) ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_29 ) ;
F_5 ( & V_2 -> V_31 , V_5 ) ;
return 0 ;
}
static int F_15 ( struct V_27 * V_28 )
{
unsigned long V_5 ;
unsigned char V_29 ;
struct V_1 * V_2 ;
V_2 = F_12 ( V_28 ) ;
F_2 ( & V_2 -> V_31 , V_5 ) ;
V_29 = ( V_2 -> V_33 | V_18 ) & ~ V_34 ;
V_2 -> V_33 = V_29 ;
V_2 -> V_14 ( V_2 , V_15 | V_16 , V_29 ) ;
F_5 ( & V_2 -> V_31 , V_5 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , int V_36 )
{
struct V_27 * V_28 = NULL ;
struct V_37 V_38 ;
int V_39 ;
V_38 . V_40 = V_41 ;
V_38 . V_42 = V_43 ;
V_38 . V_44 = V_2 -> V_44 -> V_45 ;
V_38 . V_46 = V_36 ;
V_38 . V_47 = 0 ;
if ( ( V_39 = F_17 ( V_2 -> V_44 , L_3 , & V_38 , & V_28 ) ) >= 0 ) {
strcpy ( V_28 -> V_48 , L_3 ) ;
V_28 -> V_49 = V_2 ;
V_28 -> V_50 = V_51 ;
}
V_2 -> V_52 = V_28 ;
return V_39 ;
}
static int F_18 ( struct V_1 * V_2 , int V_36 )
{
struct V_27 * V_28 = NULL ;
struct V_37 V_38 ;
int V_39 ;
V_38 . V_40 = V_41 ;
V_38 . V_42 = V_43 ;
V_38 . V_44 = V_2 -> V_44 -> V_45 ;
V_38 . V_46 = V_36 ;
V_38 . V_47 = 0 ;
if ( ( V_39 = F_17 ( V_2 -> V_44 , L_4 , & V_38 , & V_28 ) ) >= 0 ) {
strcpy ( V_28 -> V_48 , L_4 ) ;
V_28 -> V_49 = V_2 ;
V_28 -> V_50 = V_53 ;
}
V_2 -> V_54 = V_28 ;
return V_39 ;
}
void F_19 ( struct V_55 * V_50 )
{
unsigned char V_56 ;
struct V_1 * V_2 ;
struct V_27 * V_28 ;
if ( V_50 == NULL )
return;
V_2 = V_50 -> V_49 ;
V_56 = F_7 ( V_2 -> V_9 ) ;
#if 0
snd_printk(KERN_DEBUG "AdLib IRQ status = 0x%x\n", status);
#endif
if ( ! ( V_56 & 0x80 ) )
return;
if ( V_56 & 0x40 ) {
V_28 = V_2 -> V_52 ;
F_20 ( V_28 , V_28 -> V_32 ) ;
}
if ( V_56 & 0x20 ) {
V_28 = V_2 -> V_54 ;
F_20 ( V_28 , V_28 -> V_32 ) ;
}
}
static int F_21 ( struct V_1 * V_2 )
{
if ( F_10 ( ! V_2 ) )
return - V_57 ;
if ( V_2 -> V_58 )
V_2 -> V_58 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_2 -> V_59 ) ;
F_23 ( V_2 -> V_60 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_61 * V_46 )
{
struct V_1 * V_2 = V_46 -> V_62 ;
return F_21 ( V_2 ) ;
}
int F_26 ( struct V_63 * V_44 ,
unsigned short V_23 ,
struct V_1 * * V_64 )
{
static struct V_65 V_66 = {
. V_67 = F_25 ,
} ;
struct V_1 * V_2 ;
int V_39 ;
* V_64 = NULL ;
V_2 = F_27 ( sizeof( * V_2 ) , V_68 ) ;
if ( V_2 == NULL ) {
F_28 ( V_69 L_5 ) ;
return - V_70 ;
}
V_2 -> V_44 = V_44 ;
V_2 -> V_23 = V_23 ;
F_29 ( & V_2 -> V_10 ) ;
F_29 ( & V_2 -> V_31 ) ;
if ( ( V_39 = F_30 ( V_44 , V_71 , V_2 , & V_66 ) ) < 0 ) {
F_21 ( V_2 ) ;
return V_39 ;
}
* V_64 = V_2 ;
return 0 ;
}
int F_31 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_14 ) {
F_32 ( V_69 L_6 ) ;
return - V_72 ;
}
V_2 -> V_14 ( V_2 , V_15 | V_73 , V_74 ) ;
V_2 -> V_14 ( V_2 , V_15 | V_75 , 0x00 ) ;
switch ( V_2 -> V_23 & V_76 ) {
case V_25 :
V_2 -> V_77 = V_78 ;
break;
case V_26 :
case V_79 :
V_2 -> V_77 = V_80 ;
V_2 -> V_14 ( V_2 , V_7 | V_81 , V_82 ) ;
}
return 0 ;
}
int F_33 ( struct V_63 * V_44 ,
unsigned long V_9 ,
unsigned long V_8 ,
unsigned short V_23 ,
int V_83 ,
struct V_1 * * V_64 )
{
struct V_1 * V_2 ;
int V_39 ;
* V_64 = NULL ;
if ( ( V_39 = F_26 ( V_44 , V_23 , & V_2 ) ) < 0 )
return V_39 ;
if ( ! V_83 ) {
if ( ( V_2 -> V_59 = F_34 ( V_9 , 2 , L_7 ) ) == NULL ) {
F_28 ( V_69 L_8 , V_9 ) ;
F_35 ( V_44 , V_2 ) ;
return - V_84 ;
}
if ( V_8 != 0 &&
( V_2 -> V_60 = F_34 ( V_8 , 2 , L_9 ) ) == NULL ) {
F_28 ( V_69 L_10 , V_8 ) ;
F_35 ( V_44 , V_2 ) ;
return - V_84 ;
}
}
V_2 -> V_9 = V_9 ;
V_2 -> V_8 = V_8 ;
switch ( V_2 -> V_23 ) {
case V_85 :
case V_86 :
case V_87 :
V_2 -> V_14 = & F_6 ;
break;
default:
V_2 -> V_14 = & F_1 ;
if ( ( V_39 = F_8 ( V_2 ) ) < 0 ) {
F_9 ( L_11 ,
V_2 -> V_9 , V_2 -> V_8 ) ;
F_35 ( V_44 , V_2 ) ;
return V_39 ;
}
switch ( V_2 -> V_23 & V_76 ) {
case V_26 :
case V_79 :
V_2 -> V_14 = & F_6 ;
}
}
F_31 ( V_2 ) ;
* V_64 = V_2 ;
return 0 ;
}
int F_36 ( struct V_1 * V_2 , int V_88 , int V_89 )
{
int V_39 ;
if ( V_88 >= 0 )
if ( ( V_39 = F_16 ( V_2 , V_88 ) ) < 0 )
return V_39 ;
if ( V_89 >= 0 ) {
if ( ( V_39 = F_18 ( V_2 , V_89 ) ) < 0 ) {
F_35 ( V_2 -> V_44 , V_2 -> V_52 ) ;
V_2 -> V_52 = NULL ;
return V_39 ;
}
}
return 0 ;
}
int F_37 ( struct V_1 * V_2 ,
int V_46 , int V_90 ,
struct V_55 * * V_91 )
{
struct V_55 * V_50 ;
struct V_63 * V_44 = V_2 -> V_44 ;
int V_39 ;
if ( V_91 )
* V_91 = NULL ;
if ( ( V_39 = F_38 ( V_44 , L_12 , V_46 , & V_50 ) ) < 0 ) {
F_35 ( V_44 , V_2 ) ;
return V_39 ;
}
V_50 -> V_49 = V_2 ;
V_50 -> V_92 = 1 ;
#ifdef F_39
if ( V_46 == 0 )
V_50 -> V_93 = V_94 ;
#endif
strcpy ( V_50 -> V_48 , V_50 -> V_95 ) ;
switch ( V_2 -> V_23 & V_76 ) {
case V_25 :
strcpy ( V_50 -> V_48 , L_13 ) ;
V_50 -> V_96 = V_97 ;
break;
case V_26 :
strcpy ( V_50 -> V_48 , L_14 ) ;
V_50 -> V_96 = V_98 ;
break;
case V_79 :
strcpy ( V_50 -> V_48 , L_15 ) ;
V_50 -> V_96 = V_99 ;
break;
}
V_50 -> V_66 . V_100 = V_101 ;
V_50 -> V_66 . V_102 = V_103 ;
V_50 -> V_66 . V_104 = V_105 ;
V_50 -> V_66 . V_106 = V_107 ;
V_2 -> V_108 = V_50 ;
V_2 -> V_109 = V_90 ;
#if F_40 ( V_110 ) || ( F_40 ( V_111 ) && F_40 ( V_112 ) )
if ( F_41 ( V_44 , V_90 , V_113 ,
sizeof( struct V_1 * ) , & V_2 -> V_114 ) >= 0 ) {
strcpy ( V_2 -> V_114 -> V_48 , V_50 -> V_48 ) ;
* (struct V_1 * * ) F_42 ( V_2 -> V_114 ) = V_2 ;
}
#endif
if ( V_91 )
* V_91 = V_50 ;
return 0 ;
}
static int T_1 F_43 ( void )
{
return 0 ;
}
static void T_2 F_44 ( void )
{
}
