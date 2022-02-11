static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
if ( V_4 -> V_9 ) {
if ( V_4 -> V_10 == V_6 )
return;
V_4 -> V_10 = V_6 ;
}
V_7 = F_3 ( V_6 , V_4 -> V_11 ) ;
F_4 ( L_1 ,
V_6 , V_7 ,
V_4 -> V_9 ? L_2 : L_3 ,
( V_6 & V_4 -> V_12 ) ? L_4 : L_5 ,
( V_6 & V_4 -> V_13 ) ? L_6 : L_5 ) ;
if ( ( V_4 -> V_12 && ( V_6 & V_4 -> V_12 ) ) ||
( V_4 -> V_13 && ! ( V_6 & V_4 -> V_13 ) ) ) {
F_5 ( V_4 -> V_14 , V_15 , V_7 , 0 ) ;
} else {
if ( V_2 -> V_8 . type == V_16 )
F_5 ( V_4 -> V_14 , V_15 , V_7 , 0 ) ;
F_6 ( V_4 -> V_14 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_17 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_7 = F_3 ( V_6 , V_4 -> V_11 ) ;
V_17 = ( V_6 & V_4 -> V_13 ) ? 1 << 31 : 0 ;
if ( ( V_4 -> V_10 & 0x7f ) != V_7 ) {
F_4 ( L_7 ,
V_6 , V_7 ,
( V_6 & V_4 -> V_13 ) ? L_6 : L_8 ) ;
F_5 ( V_4 -> V_14 , V_15 , V_7 , 0 ) ;
if ( V_17 )
F_6 ( V_4 -> V_14 ) ;
} else {
if ( ( V_4 -> V_10 & 1 << 31 ) == V_17 )
return;
F_4 ( L_9 ,
V_6 , V_7 ,
( V_6 & V_4 -> V_13 ) ? L_6 : L_10 ) ;
if ( V_17 )
F_6 ( V_4 -> V_14 ) ;
else
F_5 ( V_4 -> V_14 , V_15 , V_7 , 0 ) ;
}
V_4 -> V_10 = V_7 | V_17 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_18 )
F_9 ( V_2 ) ;
else if ( ! V_4 -> V_9 )
F_1 ( V_2 ) ;
}
static void F_10 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_8 . type == V_19 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_11 ( & V_4 -> V_20 , V_21 + F_12 ( V_4 -> V_9 ) ) ;
}
static T_1 F_13 ( unsigned int V_22 )
{
unsigned int V_23 = V_22 ;
unsigned int V_24 ;
unsigned int V_25 = 0 ;
int V_26 ;
for ( V_26 = 0 ; V_26 < 14 ; ++ V_26 ) {
V_24 = V_22 & 0x3 ;
V_22 >>= 2 ;
V_25 <<= 1 ;
switch ( V_24 ) {
case 0 :
case 2 :
break;
case 1 :
V_25 |= 1 ;
break;
case 3 :
F_4 ( L_11 ,
V_23 ) ;
return 0 ;
}
}
F_4 ( L_12
L_13 , V_25 , V_23 , F_14 ( V_25 ) ,
F_15 ( V_25 ) , F_16 ( V_25 ) , F_17 ( V_25 ) ) ;
return V_25 ;
}
static void F_18 ( unsigned long V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_7 ;
struct V_27 V_28 ;
T_1 V_29 , V_25 , V_30 ;
T_2 V_31 , V_32 , system ;
F_19 ( & V_28 ) ;
if ( V_28 . V_33 - V_4 -> V_34 . V_33 > 1 ) {
V_29 = 200000 ;
} else {
V_29 = 1000000 * ( V_28 . V_33 - V_4 -> V_34 . V_33 ) +
V_28 . V_35 - V_4 -> V_34 . V_35 ;
}
V_4 -> V_36 = false ;
if ( V_29 < 28000 ) {
F_4 ( L_14 ) ;
return;
}
if ( V_4 -> V_37 < 20 ) {
F_4 ( L_15 , V_4 -> V_22 ) ;
return;
}
V_4 -> V_22 = ( V_4 -> V_22 << V_4 -> V_38 ) | 1 ;
V_25 = F_13 ( V_4 -> V_22 ) ;
V_31 = F_15 ( V_25 ) ;
system = F_16 ( V_25 ) ;
V_32 = F_17 ( V_25 ) ;
switch ( F_14 ( V_25 ) ) {
case 0x3 :
break;
case 0x2 :
V_32 += 0x40 ;
break;
default:
return;
}
V_30 = F_20 ( system , V_32 ) ;
F_21 ( V_4 -> V_14 , V_39 , V_30 , V_31 ) ;
F_4 ( L_16 , V_30 , V_31 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_27 V_28 ;
T_1 V_6 ;
T_1 V_29 ;
unsigned long V_40 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_40 = V_21 ;
F_19 ( & V_28 ) ;
if ( V_28 . V_33 - V_4 -> V_34 . V_33 > 1 ) {
V_29 = 200000 ;
} else {
V_29 = 1000000 * ( V_28 . V_33 - V_4 -> V_34 . V_33 ) +
V_28 . V_35 - V_4 -> V_34 . V_35 ;
}
F_4 ( L_17 ,
V_29 , ( V_6 & 0x20 ) ? L_18 : L_19 ) ;
if ( ! ( V_6 & 0x20 ) )
return 0 ;
if ( V_4 -> V_36 ) {
if ( V_4 -> V_37 < 28 ) {
V_4 -> V_37 = ( V_29 - V_41 / 2 ) /
V_41 ;
V_4 -> V_22 |= 1 << V_4 -> V_37 ;
}
} else {
V_4 -> V_36 = true ;
V_4 -> V_22 = 0 ;
V_4 -> V_34 = V_28 ;
V_4 -> V_37 = 0 ;
F_11 ( & V_4 -> V_20 , V_40 + F_12 ( 30 ) ) ;
}
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_22 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 ) {
F_24 ( & V_4 -> V_20 , F_10 , ( unsigned long ) V_2 ) ;
V_4 -> V_20 . V_42 = V_21 + F_12 ( 1000 ) ;
F_25 ( & V_4 -> V_20 ) ;
} else if ( V_4 -> V_18 ) {
F_24 ( & V_4 -> V_20 , F_18 , ( unsigned long ) V_4 ) ;
V_4 -> V_38 = 1 ;
V_4 -> V_43 = V_41 ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_9 )
F_27 ( & V_2 -> V_5 -> V_20 ) ;
if ( V_2 -> V_5 -> V_18 ) {
T_1 V_6 ;
F_27 ( & V_2 -> V_5 -> V_20 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
}
}
static int F_28 ( struct V_44 * V_4 , enum V_45 * V_46 ,
T_1 * V_30 , T_2 * V_31 )
{
unsigned char V_47 ;
if ( 1 != F_29 ( V_4 -> V_8 , & V_47 , 1 ) ) {
F_4 ( L_20 ) ;
return - V_48 ;
}
if ( V_47 == 0xaa )
return 0 ;
F_4 ( L_21 , V_47 ) ;
* V_46 = V_15 ;
* V_30 = V_47 ;
* V_31 = 0 ;
return 1 ;
}
void F_30 ( struct V_1 * V_2 )
{
const unsigned short V_49 [] = {
0x1a , 0x18 , 0x64 , 0x30 , 0x71 ,
V_50
} ;
struct V_51 V_52 ;
struct V_53 * V_54 ;
if ( 0 != V_2 -> V_55 )
return;
memset ( & V_52 , 0 , sizeof( struct V_51 ) ) ;
memset ( & V_2 -> V_56 , 0 , sizeof( V_2 -> V_56 ) ) ;
F_31 ( V_52 . type , L_22 , V_57 ) ;
switch ( V_2 -> V_8 . type ) {
case V_58 :
V_2 -> V_56 . V_59 = L_23 ;
V_2 -> V_56 . V_60 = F_28 ;
V_2 -> V_56 . V_61 = V_62 ;
V_52 . V_63 = 0x4b ;
break;
}
if ( V_2 -> V_56 . V_59 ) {
V_52 . V_64 = & V_2 -> V_56 ;
V_54 = F_32 ( & V_2 -> V_8 . V_65 , & V_52 ) ;
} else {
V_54 = F_33 ( & V_2 -> V_8 . V_65 , & V_52 , V_49 , NULL ) ;
}
if ( NULL == V_54 )
return;
#if F_34 ( V_66 ) && F_34 ( V_67 )
F_35 ( L_24 ) ;
#endif
}
int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
char * V_61 = NULL ;
struct V_68 * V_69 ;
int V_70 = - V_71 ;
if ( ! V_2 -> V_72 )
return - V_73 ;
V_4 = F_37 ( sizeof( * V_4 ) , V_74 ) ;
V_69 = F_38 () ;
if ( ! V_4 || ! V_69 )
goto V_75;
switch ( V_2 -> V_8 . type ) {
case V_76 :
case V_77 :
case V_78 :
V_61 = V_79 ;
V_4 -> V_11 = 0xf88000 ;
V_4 -> V_12 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_80 :
case V_81 :
V_61 = V_82 ;
V_4 -> V_11 = 0x0f00c0 ;
V_4 -> V_12 = 0x000020 ;
V_4 -> V_9 = 50 ;
break;
case V_83 :
V_61 = V_84 ;
V_4 -> V_11 = 0x003e00 ;
V_4 -> V_13 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_85 :
case V_86 :
case V_87 :
V_61 = V_84 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_16 :
V_61 = V_88 ;
V_4 -> V_11 = 0x1f8 ;
break;
case V_89 :
case V_90 :
V_61 = V_88 ;
V_4 -> V_11 = 0x0008e000 ;
V_4 -> V_12 = 0x00200000 ;
break;
case V_91 :
V_61 = V_92 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_93 :
case V_94 :
case V_95 :
case V_96 :
V_61 = V_84 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_97 :
V_61 = V_98 ;
V_4 -> V_18 = true ;
break;
case V_99 :
V_61 = V_92 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x004000 ;
V_4 -> V_9 = 50 ;
break;
case V_100 :
V_61 = V_101 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_19 :
V_61 = V_102 ;
V_4 -> V_11 = 0x00fd00 ;
V_4 -> V_13 = 0x000080 ;
V_4 -> V_9 = 1 ;
V_4 -> V_10 = F_3 ( F_2 ( & V_2 -> V_8 ) ,
V_4 -> V_11 ) ;
break;
}
if ( ! V_61 ) {
F_4 ( L_25 , V_2 -> V_8 . type ) ;
V_70 = - V_73 ;
goto V_75;
}
if ( V_4 -> V_18 ) {
T_1 V_6 ;
F_39 ( & V_2 -> V_8 , ( 1 << 4 ) , 1 << 4 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_22 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
} else {
F_39 ( & V_2 -> V_8 , V_4 -> V_11 | V_4 -> V_12 , 0 ) ;
}
V_4 -> V_14 = V_69 ;
snprintf ( V_4 -> V_59 , sizeof( V_4 -> V_59 ) , L_26 ,
V_2 -> V_8 . type ) ;
snprintf ( V_4 -> V_103 , sizeof( V_4 -> V_103 ) , L_27 ,
F_40 ( V_2 -> V_8 . V_104 ) ) ;
V_69 -> V_105 = V_4 -> V_59 ;
V_69 -> V_106 = V_4 -> V_103 ;
V_69 -> V_107 . V_108 = V_109 ;
V_69 -> V_107 . V_110 = 1 ;
if ( V_2 -> V_8 . V_104 -> V_111 ) {
V_69 -> V_107 . V_112 = V_2 -> V_8 . V_104 -> V_111 ;
V_69 -> V_107 . V_113 = V_2 -> V_8 . V_104 -> V_114 ;
} else {
V_69 -> V_107 . V_112 = V_2 -> V_8 . V_104 -> V_112 ;
V_69 -> V_107 . V_113 = V_2 -> V_8 . V_104 -> V_115 ;
}
V_69 -> V_14 . V_116 = & V_2 -> V_8 . V_104 -> V_14 ;
V_69 -> V_117 = V_61 ;
V_69 -> V_118 = V_119 ;
V_2 -> V_5 = V_4 ;
F_23 ( V_2 , V_4 ) ;
V_70 = F_41 ( V_69 ) ;
if ( V_70 )
goto V_120;
return 0 ;
V_120:
F_26 ( V_2 ) ;
V_2 -> V_5 = NULL ;
V_75:
F_42 ( V_69 ) ;
F_43 ( V_4 ) ;
return V_70 ;
}
void F_44 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == NULL )
return;
F_26 ( V_2 ) ;
F_45 ( V_2 -> V_5 -> V_14 ) ;
F_43 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
