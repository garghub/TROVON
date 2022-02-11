static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
int V_5 ;
for ( V_5 = 0 ; V_4 -> V_6 && ! V_5 ; V_4 ++ ) {
if ( V_4 -> V_7 == 0xffff )
V_5 = F_2 ( V_2 , V_4 -> V_6 , V_4 -> V_8 ,
V_4 -> V_9 ) ;
else
V_5 = F_3 ( V_2 , V_4 -> V_6 ,
V_4 -> V_8 , V_4 -> V_7 ,
V_4 -> V_9 ) ;
}
return V_5 ;
}
static void F_4 ( struct V_1 * V_2 )
{
int V_10 =
V_2 -> V_11 . V_12 == 0 ? V_13 : V_14 ;
F_5 ( 100 ) ;
F_6 ( V_2 -> V_15 , V_16 , 0 , V_10 ) ;
F_5 ( 30 ) ;
}
static int F_7 ( struct V_1 * V_2 , int V_17 , int V_18 )
{
int V_19 , V_5 ;
unsigned int V_20 , V_21 ;
V_5 = F_2 ( V_2 , V_22 , V_23 ,
( V_17 << 8 ) | ( 1 << 8 ) | V_18 ) ;
if ( V_5 )
return V_5 ;
for ( V_19 = 0 ; V_19 < 200 ; V_19 ++ ) {
F_5 ( 1 ) ;
V_5 = F_8 ( V_2 , V_22 , V_24 , & V_20 ) ;
if ( V_5 )
return V_5 ;
if ( ( V_20 & 3 ) == 1 ) {
V_5 = F_8 ( V_2 , V_22 , V_25 ,
& V_21 ) ;
if ( V_5 )
return V_5 ;
return V_21 >> 8 ;
}
}
F_9 ( V_2 -> V_15 , L_1 ,
V_2 -> V_11 . V_12 , V_17 , V_18 ) ;
return - V_26 ;
}
static int F_10 ( struct V_1 * V_2 , int V_27 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_22 , V_28 , ! ! V_27 ) ;
if ( ! V_5 )
V_5 = F_11 ( & V_2 -> V_11 , V_2 -> V_11 . V_12 ,
V_22 , V_29 ,
V_30 , V_27 ) ;
return V_5 ;
}
static int F_12 ( struct V_1 * V_2 , int V_31 )
{
int V_5 ;
if ( ( V_5 = F_10 ( V_2 , 0 ) ) ||
( V_5 = F_2 ( V_2 , V_22 , V_32 , 1 ) ) ||
( V_5 = F_2 ( V_2 , V_22 , V_33 , 0 ) ) ||
( V_5 = F_2 ( V_2 , V_22 , V_34 , 0 ) ) ||
( V_5 = F_2 ( V_2 , V_22 , V_35 , 0x18 ) ) ||
( V_5 = F_3 ( V_2 , V_22 , V_36 ,
0 , 1 << 5 ) ) )
return V_5 ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , int * V_37 , int * V_38 ,
int * V_39 , int * V_40 )
{
if ( V_37 ) {
unsigned int V_41 , V_42 , V_43 ;
int V_5 = F_8 ( V_2 , V_22 ,
V_44 , & V_41 ) ;
if ( ! V_5 )
V_5 = F_8 ( V_2 , V_45 ,
V_46 , & V_42 ) ;
if ( ! V_5 )
V_5 = F_8 ( V_2 , V_47 ,
V_48 , & V_43 ) ;
if ( V_5 )
return V_5 ;
* V_37 = ( V_41 & V_42 & ( V_43 >> 12 ) ) & 1 ;
}
if ( V_38 )
* V_38 = V_49 ;
if ( V_39 )
* V_39 = V_50 ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 , struct V_15 * V_15 ,
int V_51 , const struct V_52 * V_52 )
{
F_16 ( V_2 , V_15 , V_51 , & V_53 , V_52 ,
V_54 | V_55 | V_56 ,
L_2 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , int V_31 )
{
return F_18 ( V_2 , V_22 , V_31 ) ;
}
int F_19 ( struct V_1 * V_2 , struct V_15 * V_15 ,
int V_51 , const struct V_52 * V_52 )
{
F_16 ( V_2 , V_15 , V_51 , & V_57 , V_52 ,
V_54 | V_55 | V_56 ,
L_3 ) ;
F_4 ( V_2 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , int V_58 )
{
int V_59 ;
if ( V_58 )
F_5 ( V_58 ) ;
V_59 = F_7 ( V_2 , V_60 , 3 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 == 0x10 )
return V_61 ;
if ( V_59 == 0x20 )
return V_62 ;
if ( V_59 == 0x40 )
return V_63 ;
V_59 = F_7 ( V_2 , V_60 , 6 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 != 4 )
goto V_64;
V_59 = F_7 ( V_2 , V_60 , 10 ) ;
if ( V_59 < 0 )
return V_59 ;
if ( V_59 & 0x80 ) {
V_59 = F_7 ( V_2 , V_60 , 0x12 ) ;
if ( V_59 < 0 )
return V_59 ;
return V_59 > 10 ? V_65 : V_66 ;
}
V_64:
return V_67 ;
}
static int F_21 ( struct V_1 * V_2 )
{
static const struct V_3 V_68 [] = {
{ V_22 , 0xc003 , 0xffff , 0x181 } ,
{ V_22 , 0xc010 , 0xffff , 0x448a } ,
{ V_22 , 0xc04a , 0xffff , 0x5200 } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_19 , V_5 ;
V_5 = F_1 ( V_2 , V_68 ) ;
if ( V_5 )
return V_5 ;
F_5 ( 50 ) ;
if ( V_2 -> V_69 != V_70 )
V_5 = F_22 ( V_2 , V_71 ,
V_72 ) ;
if ( V_5 )
return V_5 ;
for ( V_19 = 0 ; V_19 < V_72 / sizeof( V_73 ) && ! V_5 ; V_19 += 2 )
V_5 = F_2 ( V_2 , V_22 ,
V_2 -> V_74 [ V_19 ] ,
V_2 -> V_74 [ V_19 + 1 ] ) ;
if ( ! V_5 )
V_2 -> V_69 = V_70 ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 , int V_75 )
{
static const struct V_3 V_68 [] = {
{ V_22 , 0xc04a , 0xffff , 0x5a00 } ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_3 V_76 [] = {
{ V_22 , 0xc014 , 0xffff , 0xfe16 } ,
{ V_22 , 0xc015 , 0xffff , 0xa000 } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_19 , V_5 ;
V_5 = F_1 ( V_2 , V_68 ) ;
if ( ! V_5 && V_75 == V_65 )
V_5 = F_1 ( V_2 , V_76 ) ;
if ( V_5 )
return V_5 ;
F_5 ( 50 ) ;
if ( V_2 -> V_69 != V_77 )
V_5 = F_22 ( V_2 , V_78 ,
V_79 ) ;
if ( V_5 )
return V_5 ;
for ( V_19 = 0 ; V_19 < V_79 / sizeof( V_73 ) && ! V_5 ; V_19 += 2 )
V_5 = F_2 ( V_2 , V_22 ,
V_2 -> V_74 [ V_19 ] ,
V_2 -> V_74 [ V_19 + 1 ] ) ;
if ( ! V_5 )
V_2 -> V_69 = V_77 ;
return V_5 ;
}
static int F_24 ( struct V_1 * V_2 , int V_58 )
{
int V_59 ;
unsigned int V_20 ;
V_59 = F_8 ( V_2 , V_22 , V_80 , & V_20 ) ;
if ( V_59 )
return V_59 ;
if ( V_20 & ( 1 << 8 ) )
return V_81 ;
return F_20 ( V_2 , V_58 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 , V_22 , V_80 , 0x200 ) ;
return V_5 ? V_5 : F_26 ( V_2 ) ;
}
static int F_27 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 , V_22 , V_80 , 0x100 ) ;
return V_5 ? V_5 : F_28 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 )
{
int V_5 = F_2 ( V_2 , V_22 , V_80 , 0xd00 ) ;
return V_5 ? V_5 : F_30 ( V_2 ) ;
}
static int F_31 ( struct V_1 * V_2 , int V_31 )
{
static const struct V_3 V_82 [] = {
{ V_22 , 0xc001 , 0 , 1 << 5 } ,
{ V_22 , 0xc017 , 0 , 1 << 5 } ,
{ V_22 , 0xc013 , 0xffff , 0xf341 } ,
{ V_22 , 0xc210 , 0xffff , 0x8000 } ,
{ V_22 , 0xc210 , 0xffff , 0x8100 } ,
{ V_22 , 0xc210 , 0xffff , 0x8000 } ,
{ V_22 , 0xc210 , 0xffff , 0 } ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_3 V_83 [] = {
{ V_22 , 0xca00 , 0xffff , 0x0080 } ,
{ V_22 , 0xca12 , 0xffff , 0 } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_5 ;
unsigned int V_84 ;
V_5 = F_8 ( V_2 , V_22 , V_85 ,
& V_84 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_18 ( V_2 , V_22 , 0 ) ;
if ( V_5 )
return V_5 ;
F_5 ( 125 ) ;
V_2 -> V_69 = V_86 ;
V_5 = F_1 ( V_2 , V_82 ) ;
if ( V_5 )
return V_5 ;
F_5 ( 50 ) ;
V_5 = F_24 ( V_2 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_75 = V_5 ;
if ( V_5 == V_66 || V_5 == V_65 )
V_5 = F_23 ( V_2 , V_5 ) ;
else
V_5 = F_21 ( V_2 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , V_83 ) ;
if ( V_5 )
return V_5 ;
if ( V_84 & 1 )
V_5 = F_25 ( V_2 ) ;
return V_5 ;
}
static int F_32 ( struct V_1 * V_2 )
{
unsigned int V_20 ;
int V_87 , V_88 , V_89 = 0 ;
V_87 = F_8 ( V_2 , V_22 , V_90 , & V_20 ) ;
if ( V_87 )
return V_87 ;
if ( V_20 & V_91 ) {
V_87 = F_2 ( V_2 , V_22 , V_80 ,
0xd00 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_24 ( V_2 , 300 ) ;
if ( V_87 < 0 )
return V_87 ;
V_2 -> V_75 = V_87 ;
if ( V_87 == V_81 )
V_88 = V_2 -> V_69 ;
else if ( V_87 == V_66 ||
V_87 == V_65 )
V_88 = V_77 ;
else
V_88 = V_70 ;
if ( V_88 != V_2 -> V_69 ) {
V_87 = F_31 ( V_2 , 0 ) ;
return V_87 ? V_87 : V_92 ;
}
V_89 = V_92 ;
}
V_87 = F_33 ( V_2 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 |= V_89 ;
return V_87 ? V_87 : V_93 ;
}
int F_34 ( struct V_1 * V_2 , struct V_15 * V_15 ,
int V_51 , const struct V_52 * V_52 )
{
F_16 ( V_2 , V_15 , V_51 , & V_94 , V_52 ,
V_54 | V_55 | V_56 |
V_95 , L_2 ) ;
F_5 ( 125 ) ;
return F_3 ( V_2 , V_22 , V_96 , 0 ,
1 << 5 ) ;
}
static int F_35 ( struct V_1 * V_2 )
{
static const struct V_3 V_68 [] = {
{ V_22 , 0xcc01 , 0xffff , 0x488a } ,
{ V_22 , 0xcb1b , 0xffff , 0x0200 } ,
{ V_22 , 0xcb1c , 0xffff , 0x00f0 } ,
{ V_22 , 0xcc06 , 0xffff , 0x00e0 } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_5 ;
V_5 = F_1 ( V_2 , V_68 ) ;
F_5 ( 50 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_69 = V_70 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_75 )
{
static const struct V_3 V_97 [] = {
{ V_22 , 0xff28 , 0xffff , 0x4001 } ,
{ V_22 , 0xff2a , 0xffff , 0x0002 } ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_3 V_98 [] = {
{ V_22 , 0xd000 , 0xffff , 0x5200 } ,
{ 0 , 0 , 0 , 0 }
} ;
static const struct V_3 V_99 [] = {
{ V_22 , 0xd080 , 0xffff , 0x0100 } ,
{ V_22 , 0xd092 , 0xffff , 0x0000 } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_19 , V_5 ;
V_5 = F_1 ( V_2 , V_97 ) ;
F_5 ( 500 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_1 ( V_2 , V_98 ) ;
F_5 ( 500 ) ;
if ( V_5 )
return V_5 ;
if ( V_2 -> V_69 != V_77 )
V_5 = F_22 ( V_2 , V_100 ,
V_101 ) ;
if ( V_5 )
return V_5 ;
for ( V_19 = 0 ; V_19 < V_101 / sizeof( V_73 ) && ! V_5 ; V_19 += 2 )
V_5 = F_2 ( V_2 , V_22 ,
V_2 -> V_74 [ V_19 ] ,
V_2 -> V_74 [ V_19 + 1 ] ) ;
V_5 = F_1 ( V_2 , V_99 ) ;
if ( ! V_5 )
V_2 -> V_69 = V_77 ;
return V_5 ;
}
static int F_37 ( struct V_1 * V_2 , int V_58 )
{
int V_59 ;
unsigned int V_20 ;
V_59 = F_8 ( V_2 , V_22 , V_102 , & V_20 ) ;
if ( V_59 )
return V_59 ;
if ( V_20 & ( 0x1 << ( V_103 * 4 ) ) ) {
return V_81 ;
}
return F_20 ( V_2 , V_58 ) ;
}
static int F_38 ( struct V_1 * V_2 )
{
static const struct V_3 V_68 [] = {
{ V_22 , V_104 + V_105 ,
0xffff , 0x4 } ,
{ V_22 , V_106 ,
0xffff , 0x8 << ( V_105 * 4 ) } ,
{ V_22 , V_106 ,
0xffff , 0x2 << ( V_103 * 4 ) } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_5 , V_37 = 0 ;
V_5 = F_1 ( V_2 , V_68 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_14 ( V_2 , & V_37 , NULL , NULL , NULL ) ;
if ( V_5 )
return V_5 ;
if ( V_37 )
F_39 ( V_2 -> V_15 ,
F_40 ( V_2 ) ) ;
V_5 = F_26 ( V_2 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
static const struct V_3 V_68 [] = {
{ V_22 , V_106 ,
0xffff , 0xb << ( V_105 * 4 ) } ,
{ V_22 , V_106 ,
0xffff , 0x1 << ( V_103 * 4 ) } ,
{ 0 , 0 , 0 , 0 }
} ;
int V_5 ;
V_5 = F_1 ( V_2 , V_68 ) ;
if ( V_5 )
return V_5 ;
return F_28 ( V_2 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
unsigned int V_20 ;
int V_5 = F_8 ( V_2 , V_22 , V_107 , & V_20 ) ;
return V_5 ? V_5 : F_30 ( V_2 ) ;
}
static int F_43 ( struct V_1 * V_2 , int V_31 )
{
int V_5 ;
unsigned int V_84 ;
V_5 = F_8 ( V_2 , V_22 , V_85 ,
& V_84 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_18 ( V_2 , V_22 , 125 ) ;
if ( V_5 )
return V_5 ;
F_5 ( 100 ) ;
V_2 -> V_69 = V_86 ;
V_5 = F_1 ( V_2 , V_108 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_37 ( V_2 , 0 ) ;
if ( V_5 < 0 )
return V_5 ;
V_2 -> V_75 = ( V_109 ) V_5 ;
if ( V_5 == V_66 || V_5 == V_65 )
V_5 = F_36 ( V_2 , V_5 ) ;
else
V_5 = F_35 ( V_2 ) ;
if ( V_5 )
return V_5 ;
if ( V_84 & 1 )
V_5 = F_25 ( V_2 ) ;
return V_5 ;
}
static int F_44 ( struct V_1 * V_2 )
{
unsigned int V_20 ;
int V_87 , V_88 , V_89 = 0 ;
V_87 = F_8 ( V_2 , V_22 , V_107 , & V_20 ) ;
if ( V_87 )
return V_87 ;
if ( V_20 & ( 0x1 << V_103 ) ) {
V_87 = F_37 ( V_2 , 300 ) ;
if ( V_87 < 0 )
return V_87 ;
V_2 -> V_75 = ( V_109 ) V_87 ;
if ( V_87 == V_81 )
V_88 = V_2 -> V_69 ;
else if ( V_87 == V_66 ||
V_87 == V_65 )
V_88 = V_77 ;
else
V_88 = V_70 ;
if ( V_88 != V_2 -> V_69 ) {
V_87 = F_43 ( V_2 , 0 ) ;
return V_87 ? V_87 : V_92 ;
}
V_89 = V_92 ;
}
V_87 = F_33 ( V_2 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 |= V_89 ;
return V_87 ? V_87 : V_93 ;
}
int F_45 ( struct V_1 * V_2 , struct V_15 * V_15 , int V_51 ,
const struct V_52 * V_52 )
{
int V_5 ;
F_16 ( V_2 , V_15 , V_51 , & V_110 , V_52 ,
V_54 | V_55 | V_56 |
V_95 , L_2 ) ;
F_5 ( 125 ) ;
V_5 = F_1 ( V_2 , V_108 ) ;
if ( V_5 )
return V_5 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 , int * V_37 , int * V_38 ,
int * V_39 , int * V_40 )
{
if ( V_37 ) {
unsigned int V_41 , V_42 , V_43 ;
int V_5 = F_8 ( V_2 , V_22 ,
V_44 , & V_41 ) ;
if ( ! V_5 )
V_5 = F_8 ( V_2 , V_45 ,
V_111 , & V_42 ) ;
if ( ! V_5 )
V_5 = F_8 ( V_2 , V_47 ,
V_48 , & V_43 ) ;
if ( V_5 )
return V_5 ;
* V_37 = ( V_41 & ( V_42 >> 12 ) & ( V_43 >> 12 ) ) & 1 ;
}
if ( V_38 )
* V_38 = V_49 ;
if ( V_39 )
* V_39 = V_50 ;
return 0 ;
}
int F_47 ( struct V_1 * V_2 , struct V_15 * V_15 ,
int V_51 , const struct V_52 * V_52 )
{
unsigned int V_20 ;
F_16 ( V_2 , V_15 , V_51 , & V_112 , V_52 ,
V_54 | V_55 | V_113 ,
L_4 ) ;
if ( ! V_51 &&
! F_8 ( V_2 , V_22 , V_114 , & V_20 ) &&
V_20 == 0xffff )
V_2 -> V_11 . V_12 = 1 ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 , int V_31 )
{
return 0 ;
}
static int F_49 ( struct V_1 * V_2 , int * V_37 ,
int * V_38 , int * V_39 , int * V_40 )
{
if ( V_37 ) {
unsigned int V_115 ;
int V_12 = V_2 -> V_11 . V_12 ;
V_115 = F_50 ( V_2 -> V_15 ,
F_51 ( V_116 , V_12 ) ) |
F_50 ( V_2 -> V_15 ,
F_51 ( V_117 , V_12 ) ) |
F_50 ( V_2 -> V_15 ,
F_51 ( V_118 , V_12 ) ) |
F_50 ( V_2 -> V_15 ,
F_51 ( V_119 , V_12 ) ) ;
* V_37 = ! ( V_115 & V_120 ) ;
}
if ( V_38 )
* V_38 = V_49 ;
if ( V_39 )
* V_39 = V_50 ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 , int V_27 )
{
return 0 ;
}
int F_53 ( struct V_1 * V_2 , struct V_15 * V_15 ,
int V_51 , const struct V_52 * V_52 )
{
F_16 ( V_2 , V_15 , V_51 , & V_121 , V_52 ,
V_54 | V_55 | V_113 ,
L_4 ) ;
return 0 ;
}
