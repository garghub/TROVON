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
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
} else {
if ( V_2 -> V_8 . type == V_15 )
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
F_6 ( V_4 -> V_14 ) ;
}
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 , V_7 , V_16 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_7 = F_3 ( V_6 , V_4 -> V_11 ) ;
V_16 = ( V_6 & V_4 -> V_13 ) ? 1 << 31 : 0 ;
if ( ( V_4 -> V_10 & 0x7f ) != V_7 ) {
F_4 ( L_7 ,
V_6 , V_7 ,
( V_6 & V_4 -> V_13 ) ? L_6 : L_8 ) ;
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
if ( V_16 )
F_6 ( V_4 -> V_14 ) ;
} else {
if ( ( V_4 -> V_10 & 1 << 31 ) == V_16 )
return;
F_4 ( L_9 ,
V_6 , V_7 ,
( V_6 & V_4 -> V_13 ) ? L_6 : L_10 ) ;
if ( V_16 )
F_6 ( V_4 -> V_14 ) ;
else
F_5 ( V_4 -> V_14 , V_7 , 0 ) ;
}
V_4 -> V_10 = V_7 | V_16 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_17 )
F_9 ( V_2 ) ;
else if ( ! V_4 -> V_9 )
F_1 ( V_2 ) ;
}
static void F_10 ( unsigned long V_7 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_2 -> V_8 . type == V_18 )
F_7 ( V_2 ) ;
else
F_1 ( V_2 ) ;
F_11 ( & V_4 -> V_19 , V_20 + F_12 ( V_4 -> V_9 ) ) ;
}
static T_1 F_13 ( unsigned int V_21 )
{
unsigned int V_22 = V_21 ;
unsigned int V_23 ;
unsigned int V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < 14 ; ++ V_25 ) {
V_23 = V_21 & 0x3 ;
V_21 >>= 2 ;
V_24 <<= 1 ;
switch ( V_23 ) {
case 0 :
case 2 :
break;
case 1 :
V_24 |= 1 ;
break;
case 3 :
F_4 ( L_11 ,
V_22 ) ;
return 0 ;
}
}
F_4 ( L_12
L_13 , V_24 , V_22 , F_14 ( V_24 ) ,
F_15 ( V_24 ) , F_16 ( V_24 ) , F_17 ( V_24 ) ) ;
return V_24 ;
}
static void F_18 ( unsigned long V_7 )
{
struct V_3 * V_4 = (struct V_3 * ) V_7 ;
struct V_26 V_27 ;
T_1 V_28 ;
T_1 V_24 = 0 ;
F_19 ( & V_27 ) ;
if ( V_27 . V_29 - V_4 -> V_30 . V_29 > 1 ) {
V_28 = 200000 ;
} else {
V_28 = 1000000 * ( V_27 . V_29 - V_4 -> V_30 . V_29 ) +
V_27 . V_31 - V_4 -> V_30 . V_31 ;
}
V_4 -> V_32 = false ;
if ( V_28 < 28000 ) {
F_4 ( L_14 ) ;
return;
}
if ( V_4 -> V_33 < 20 ) {
F_4 ( L_15 , V_4 -> V_21 ) ;
} else {
V_4 -> V_21 = ( V_4 -> V_21 << V_4 -> V_34 ) | 1 ;
V_24 = F_13 ( V_4 -> V_21 ) ;
if ( F_14 ( V_24 ) != V_4 -> V_35 ) {
F_20 ( V_36 L_16
L_17 , F_14 ( V_24 ) ) ;
} else if ( F_16 ( V_24 ) == V_4 -> V_37 ) {
T_1 V_38 = F_15 ( V_24 ) ;
T_1 V_39 = F_17 ( V_24 ) ;
F_21 ( V_4 -> V_14 , V_39 , V_38 ) ;
F_4 ( L_18 ,
V_39 , V_38 ) ;
}
}
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_26 V_27 ;
T_1 V_6 ;
T_1 V_28 ;
unsigned long V_40 ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
V_40 = V_20 ;
F_19 ( & V_27 ) ;
if ( V_27 . V_29 - V_4 -> V_30 . V_29 > 1 ) {
V_28 = 200000 ;
} else {
V_28 = 1000000 * ( V_27 . V_29 - V_4 -> V_30 . V_29 ) +
V_27 . V_31 - V_4 -> V_30 . V_31 ;
}
F_4 ( L_19 ,
V_28 , ( V_6 & 0x20 ) ? L_20 : L_21 ) ;
if ( ! ( V_6 & 0x20 ) )
return 0 ;
if ( V_4 -> V_32 ) {
if ( V_4 -> V_33 < 28 ) {
V_4 -> V_33 = ( V_28 - V_41 / 2 ) /
V_41 ;
V_4 -> V_21 |= 1 << V_4 -> V_33 ;
}
} else {
V_4 -> V_32 = true ;
V_4 -> V_21 = 0 ;
V_4 -> V_30 = V_27 ;
V_4 -> V_33 = 0 ;
F_11 ( & V_4 -> V_19 , V_40 + F_12 ( 30 ) ) ;
}
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_22 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
return 1 ;
}
static void F_23 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_4 -> V_9 ) {
F_24 ( & V_4 -> V_19 , F_10 , ( unsigned long ) V_2 ) ;
V_4 -> V_19 . V_42 = V_20 + F_12 ( 1000 ) ;
F_25 ( & V_4 -> V_19 ) ;
} else if ( V_4 -> V_17 ) {
F_24 ( & V_4 -> V_19 , F_18 , ( unsigned long ) V_4 ) ;
V_4 -> V_34 = 1 ;
V_4 -> V_35 = 3 ;
V_4 -> V_37 = 0x0 ;
V_4 -> V_43 = V_41 ;
}
}
static void F_26 ( struct V_1 * V_2 )
{
if ( V_2 -> V_5 -> V_9 )
F_27 ( & V_2 -> V_5 -> V_19 ) ;
if ( V_2 -> V_5 -> V_17 ) {
T_1 V_6 ;
F_27 ( & V_2 -> V_5 -> V_19 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
}
}
static int F_28 ( struct V_44 * V_4 , T_1 * V_45 , T_1 * V_46 )
{
unsigned char V_47 ;
if ( 1 != F_29 ( V_4 -> V_8 , & V_47 , 1 ) ) {
F_4 ( L_22 ) ;
return - V_48 ;
}
if ( V_47 == 0xaa )
return 0 ;
F_4 ( L_23 , V_47 ) ;
* V_45 = V_47 ;
* V_46 = V_47 ;
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
F_31 ( V_52 . type , L_24 , V_57 ) ;
switch ( V_2 -> V_8 . type ) {
case V_58 :
V_2 -> V_56 . V_59 = L_25 ;
V_2 -> V_56 . V_60 = F_28 ;
V_2 -> V_56 . V_61 = V_62 ;
V_52 . V_37 = 0x4b ;
break;
}
if ( V_2 -> V_56 . V_59 ) {
V_52 . V_63 = & V_2 -> V_56 ;
V_54 = F_32 ( & V_2 -> V_8 . V_64 , & V_52 ) ;
} else {
V_54 = F_33 ( & V_2 -> V_8 . V_64 , & V_52 , V_49 , NULL ) ;
}
if ( NULL == V_54 )
return;
#if F_34 ( V_65 ) && F_34 ( V_66 )
F_35 ( L_26 ) ;
#endif
}
int F_36 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
char * V_61 = NULL ;
struct V_67 * V_68 ;
int V_69 = - V_70 ;
if ( ! V_2 -> V_71 )
return - V_72 ;
V_4 = F_37 ( sizeof( * V_4 ) , V_73 ) ;
V_68 = F_38 () ;
if ( ! V_4 || ! V_68 )
goto V_74;
switch ( V_2 -> V_8 . type ) {
case V_75 :
case V_76 :
case V_77 :
V_61 = V_78 ;
V_4 -> V_11 = 0xf88000 ;
V_4 -> V_12 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_79 :
case V_80 :
V_61 = V_81 ;
V_4 -> V_11 = 0x0f00c0 ;
V_4 -> V_12 = 0x000020 ;
V_4 -> V_9 = 50 ;
break;
case V_82 :
V_61 = V_83 ;
V_4 -> V_11 = 0x003e00 ;
V_4 -> V_13 = 0x010000 ;
V_4 -> V_9 = 50 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_61 = V_83 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_15 :
V_61 = V_87 ;
V_4 -> V_11 = 0x1f8 ;
break;
case V_88 :
case V_89 :
V_61 = V_87 ;
V_4 -> V_11 = 0x0008e000 ;
V_4 -> V_12 = 0x00200000 ;
break;
case V_90 :
V_61 = V_91 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x008000 ;
V_4 -> V_9 = 50 ;
break;
case V_92 :
case V_93 :
case V_94 :
case V_95 :
V_61 = V_83 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_96 :
V_61 = V_97 ;
V_4 -> V_17 = true ;
break;
case V_98 :
V_61 = V_91 ;
V_4 -> V_11 = 0x001F00 ;
V_4 -> V_13 = 0x004000 ;
V_4 -> V_9 = 50 ;
break;
case V_99 :
V_61 = V_100 ;
V_4 -> V_11 = 0x001f00 ;
V_4 -> V_13 = 0x006000 ;
V_4 -> V_9 = 50 ;
break;
case V_18 :
V_61 = V_101 ;
V_4 -> V_11 = 0x00fd00 ;
V_4 -> V_13 = 0x000080 ;
V_4 -> V_9 = 1 ;
V_4 -> V_10 = F_3 ( F_2 ( & V_2 -> V_8 ) ,
V_4 -> V_11 ) ;
break;
}
if ( NULL == V_61 ) {
F_4 ( L_27 , V_2 -> V_8 . type ) ;
V_69 = - V_72 ;
goto V_74;
}
if ( V_4 -> V_17 ) {
T_1 V_6 ;
F_39 ( & V_2 -> V_8 , ( 1 << 4 ) , 1 << 4 ) ;
V_6 = F_2 ( & V_2 -> V_8 ) ;
F_22 ( & V_2 -> V_8 , V_6 & ~ ( 1 << 4 ) ) ;
F_22 ( & V_2 -> V_8 , V_6 | ( 1 << 4 ) ) ;
} else {
F_39 ( & V_2 -> V_8 , V_4 -> V_11 | V_4 -> V_12 , 0 ) ;
}
V_4 -> V_14 = V_68 ;
snprintf ( V_4 -> V_59 , sizeof( V_4 -> V_59 ) , L_28 ,
V_2 -> V_8 . type ) ;
snprintf ( V_4 -> V_102 , sizeof( V_4 -> V_102 ) , L_29 ,
F_40 ( V_2 -> V_8 . V_103 ) ) ;
V_68 -> V_104 = V_4 -> V_59 ;
V_68 -> V_105 = V_4 -> V_102 ;
V_68 -> V_106 . V_107 = V_108 ;
V_68 -> V_106 . V_109 = 1 ;
if ( V_2 -> V_8 . V_103 -> V_110 ) {
V_68 -> V_106 . V_111 = V_2 -> V_8 . V_103 -> V_110 ;
V_68 -> V_106 . V_112 = V_2 -> V_8 . V_103 -> V_113 ;
} else {
V_68 -> V_106 . V_111 = V_2 -> V_8 . V_103 -> V_111 ;
V_68 -> V_106 . V_112 = V_2 -> V_8 . V_103 -> V_114 ;
}
V_68 -> V_14 . V_115 = & V_2 -> V_8 . V_103 -> V_14 ;
V_68 -> V_116 = V_61 ;
V_68 -> V_117 = V_118 ;
V_2 -> V_5 = V_4 ;
F_23 ( V_2 , V_4 ) ;
V_69 = F_41 ( V_68 ) ;
if ( V_69 )
goto V_119;
return 0 ;
V_119:
F_26 ( V_2 ) ;
V_2 -> V_5 = NULL ;
V_74:
F_42 ( V_68 ) ;
F_43 ( V_4 ) ;
return V_69 ;
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
