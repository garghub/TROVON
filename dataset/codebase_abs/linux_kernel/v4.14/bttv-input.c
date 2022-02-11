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
F_5 ( V_4 -> V_14 , V_15 , V_7 ,
0 ) ;
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
F_5 ( V_4 -> V_14 , V_15 , V_7 ,
0 ) ;
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
F_4 ( L_12 ,
V_25 , V_23 , F_14 ( V_25 ) ,
F_15 ( V_25 ) , F_16 ( V_25 ) , F_17 ( V_25 ) ) ;
return V_25 ;
}
static void F_18 ( unsigned long V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_7 ;
T_2 V_27 ;
T_1 V_28 , V_25 , V_29 ;
T_3 V_30 , V_31 , system ;
V_27 = F_19 () ;
V_28 = F_20 ( F_21 ( V_27 , V_4 -> V_32 ) ) ;
if ( V_28 > V_33 ) {
V_28 = 200000 ;
}
V_4 -> V_34 = false ;
if ( V_28 < 28000 ) {
F_4 ( L_13 ) ;
return;
}
if ( V_4 -> V_35 < 20 ) {
F_4 ( L_14 , V_4 -> V_22 ) ;
return;
}
V_4 -> V_22 = ( V_4 -> V_22 << V_4 -> V_36 ) | 1 ;
V_25 = F_13 ( V_4 -> V_22 ) ;
V_30 = F_15 ( V_25 ) ;
system = F_16 ( V_25 ) ;
V_31 = F_17 ( V_25 ) ;
switch ( F_14 ( V_25 ) ) {
case 0x3 :
break;
case 0x2 :
V_31 += 0x40 ;
break;
default:
return;
}
V_29 = F_22 ( system , V_31 ) ;
F_23 ( V_4 -> V_14 , V_37 , V_29 , V_30 ) ;
F_4 ( L_15 , V_29 , V_30 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_2 V_27 ;
T_1 V_6 ;
T_1 V_28 ;
unsigned long V_38 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_38 = V_21 ;
V_27 = F_19 () ;
V_28 = F_20 ( F_21 ( V_27 , V_4 -> V_32 ) ) ;
if ( V_28 > V_33 ) {
V_28 = 200000 ;
}
F_4 ( L_16 ,
V_28 , ( V_6 & 0x20 ) ? L_17 : L_18 ) ;
if ( ! ( V_6 & 0x20 ) )
return 0 ;
if ( V_4 -> V_34 ) {
if ( V_4 -> V_35 < 28 ) {
V_4 -> V_35 = ( V_28 - V_39 / 2 ) /
V_39 ;
V_4 -> V_22 |= 1 << V_4 -> V_35 ;
}
} else {
V_4 -> V_34 = true ;
V_4 -> V_22 = 0 ;
V_4 -> V_32 = V_27 ;
V_4 -> V_35 = 0 ;
F_11 ( & V_4 -> V_20 , V_38 + F_12 ( 30 ) ) ;
}
F_24 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_24 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
return 1 ;
}
static void F_25 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 ) {
F_26 ( & V_4 -> V_20 , F_10 , ( unsigned long ) V_2 ) ;
V_4 -> V_20 . V_40 = V_21 + F_12 ( 1000 ) ;
F_27 ( & V_4 -> V_20 ) ;
} else if ( V_4 -> V_18 ) {
F_26 ( & V_4 -> V_20 , F_18 , ( unsigned long ) V_4 ) ;
V_4 -> V_36 = 1 ;
V_4 -> V_41 = V_39 ;
}
}
static void F_28 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_9 )
F_29 ( & V_2 -> V_5 -> V_20 ) ;
if ( V_2 -> V_5 -> V_18 ) {
T_1 V_6 ;
F_29 ( & V_2 -> V_5 -> V_20 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_24 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
}
}
static int F_30 ( struct V_42 * V_4 , enum V_43 * V_44 ,
T_1 * V_29 , T_3 * V_30 )
{
unsigned char V_45 ;
if ( 1 != F_31 ( V_4 -> V_8 , & V_45 , 1 ) ) {
F_4 ( L_19 ) ;
return - V_46 ;
}
if ( V_45 == 0xaa )
return 0 ;
F_4 ( L_20 , V_45 ) ;
* V_44 = V_15 ;
* V_29 = V_45 ;
* V_30 = 0 ;
return 1 ;
}
void F_32 ( struct V_1 * V_2 )
{
const unsigned short V_47 [] = {
0x1a , 0x18 , 0x64 , 0x30 , 0x71 ,
V_48
} ;
struct V_49 V_50 ;
struct V_51 * V_52 ;
if ( 0 != V_2 -> V_53 )
return;
memset ( & V_50 , 0 , sizeof( struct V_49 ) ) ;
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
F_33 ( V_50 . type , L_21 , V_55 ) ;
switch ( V_2 -> V_8 . type ) {
case V_56 :
V_2 -> V_54 . V_57 = L_22 ;
V_2 -> V_54 . V_58 = F_30 ;
V_2 -> V_54 . V_59 = V_60 ;
V_50 . V_61 = 0x4b ;
break;
}
if ( V_2 -> V_54 . V_57 ) {
V_50 . V_62 = & V_2 -> V_54 ;
V_52 = F_34 ( & V_2 -> V_8 . V_63 , & V_50 ) ;
} else {
V_52 = F_35 ( & V_2 -> V_8 . V_63 , & V_50 , V_47 , NULL ) ;
}
if ( NULL == V_52 )
return;
#if F_36 ( V_64 ) && F_36 ( V_65 )
F_37 ( L_23 ) ;
#endif
}
int F_38 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
char * V_59 = NULL ;
struct V_66 * V_67 ;
int V_68 = - V_69 ;
if ( ! V_2 -> V_70 )
return - V_71 ;
V_4 = F_39 ( sizeof( * V_4 ) , V_72 ) ;
V_67 = F_40 ( V_73 ) ;
if ( ! V_4 || ! V_67 )
goto V_74;
switch ( V_2 -> V_8 . type ) {
case V_75 :
case V_76 :
case V_77 :
V_59 = V_78 ;
V_4 -> V_11 = 0xf88000 ;
V_4 -> V_12 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_79 :
case V_80 :
V_59 = V_81 ;
V_4 -> V_11 = 0x0f00c0 ;
V_4 -> V_12 = 0x000020 ;
V_4 -> V_9 = 50 ;
break;
case V_82 :
V_59 = V_83 ;
V_4 -> V_11 = 0x003e00 ;
V_4 -> V_13 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_59 = V_83 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_16 :
V_59 = V_87 ;
V_4 -> V_11 = 0x1f8 ;
break;
case V_88 :
case V_89 :
V_59 = V_87 ;
V_4 -> V_11 = 0x0008e000 ;
V_4 -> V_12 = 0x00200000 ;
break;
case V_90 :
V_59 = V_91 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_59 = V_83 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_96 :
V_59 = V_97 ;
V_4 -> V_18 = true ;
break;
case V_98 :
V_59 = V_91 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x004000 ;
V_4 -> V_9 = 50 ;
break;
case V_99 :
V_59 = V_100 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_19 :
V_59 = V_101 ;
V_4 -> V_11 = 0x00fd00 ;
V_4 -> V_13 = 0x000080 ;
V_4 -> V_9 = 1 ;
V_4 -> V_10 = F_3 ( F_2 ( & V_2 -> V_8 ) ,
V_4 -> V_11 ) ;
break;
}
if ( ! V_59 ) {
F_4 ( L_24 , V_2 -> V_8 . type ) ;
V_68 = - V_71 ;
goto V_74;
}
if ( V_4 -> V_18 ) {
T_1 V_6 ;
F_41 ( & V_2 -> V_8 , ( 1 << 4 ) , 1 << 4 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_24 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_24 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
} else {
F_41 ( & V_2 -> V_8 , V_4 -> V_11 | V_4 -> V_12 , 0 ) ;
}
V_4 -> V_14 = V_67 ;
snprintf ( V_4 -> V_57 , sizeof( V_4 -> V_57 ) , L_25 ,
V_2 -> V_8 . type ) ;
snprintf ( V_4 -> V_102 , sizeof( V_4 -> V_102 ) , L_26 ,
F_42 ( V_2 -> V_8 . V_103 ) ) ;
V_67 -> V_104 = V_4 -> V_57 ;
V_67 -> V_105 = V_4 -> V_102 ;
V_67 -> V_106 . V_107 = V_108 ;
V_67 -> V_106 . V_109 = 1 ;
if ( V_2 -> V_8 . V_103 -> V_110 ) {
V_67 -> V_106 . V_111 = V_2 -> V_8 . V_103 -> V_110 ;
V_67 -> V_106 . V_112 = V_2 -> V_8 . V_103 -> V_113 ;
} else {
V_67 -> V_106 . V_111 = V_2 -> V_8 . V_103 -> V_111 ;
V_67 -> V_106 . V_112 = V_2 -> V_8 . V_103 -> V_114 ;
}
V_67 -> V_14 . V_115 = & V_2 -> V_8 . V_103 -> V_14 ;
V_67 -> V_116 = V_59 ;
V_67 -> V_117 = V_118 ;
V_2 -> V_5 = V_4 ;
F_25 ( V_2 , V_4 ) ;
V_68 = F_43 ( V_67 ) ;
if ( V_68 )
goto V_119;
return 0 ;
V_119:
F_28 ( V_2 ) ;
V_2 -> V_5 = NULL ;
V_74:
F_44 ( V_67 ) ;
F_45 ( V_4 ) ;
return V_68 ;
}
void F_46 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 == NULL )
return;
F_28 ( V_2 ) ;
F_47 ( V_2 -> V_5 -> V_14 ) ;
F_45 ( V_2 -> V_5 ) ;
V_2 -> V_5 = NULL ;
}
