static int
F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
unsigned int V_5 ;
memset ( & V_4 , 0 , sizeof( struct V_3 ) ) ;
V_2 -> V_6 -> V_7 ( V_2 , & V_4 ) ;
V_5 = V_4 . V_8 ? V_9 : 0 ;
V_5 |= V_4 . V_10 ? V_11 : 0 ;
V_5 |= V_4 . V_12 ? V_13 : 0 ;
V_5 |= V_4 . V_14 ? V_15 : 0 ;
V_5 |= V_4 . V_16 ? V_17 : 0 ;
V_5 |= V_2 -> V_18 . V_19 ? V_20 : 0 ;
if ( V_2 -> V_18 . V_21 & V_22 )
V_5 |= V_4 . V_23 ? V_24 : 0 ;
else {
if ( V_4 . V_23 == 0 )
V_5 |= V_25 ;
else if ( V_4 . V_26 == 0 )
V_5 |= V_27 ;
}
return V_5 ;
}
static int
F_2 ( struct V_1 * V_2 , T_1 * V_4 )
{
int V_28 ;
V_28 = V_2 -> V_6 -> V_29 ( V_2 , V_4 ) ;
if ( V_28 == 0 ) {
V_2 -> V_18 = * V_4 ;
}
if ( V_28 < 0 )
F_3 ( L_1 , V_2 -> V_30 ) ;
return V_28 ;
}
static int F_4 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_5 ( V_32 ) ;
F_3 ( L_2 , V_2 -> V_30 ) ;
V_2 -> V_6 -> V_33 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_5 ( V_32 ) ;
F_3 ( L_3 , V_2 -> V_30 ) ;
V_2 -> V_6 -> V_34 ( V_2 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
unsigned int V_35 ;
F_3 ( L_4 ) ;
do {
unsigned int V_36 ;
unsigned long V_21 ;
V_36 = F_1 ( V_2 ) ;
F_8 ( & V_37 , V_21 ) ;
V_35 = ( V_36 ^ V_2 -> V_36 ) & V_2 -> V_18 . V_38 ;
V_2 -> V_36 = V_36 ;
F_9 ( & V_37 , V_21 ) ;
F_3 ( L_5 ,
V_35 == 0 ? L_6 : L_7 ,
V_35 & V_9 ? L_8 : L_7 ,
V_35 & V_11 ? L_9 : L_7 ,
V_35 & V_25 ? L_10 : L_7 ,
V_35 & V_27 ? L_11 : L_7 ,
V_35 & V_24 ? L_12 : L_7 ) ;
if ( V_35 )
F_10 ( & V_2 -> V_39 , V_35 ) ;
} while ( V_35 );
}
static void F_11 ( unsigned long V_40 )
{
struct V_1 * V_2 = (struct V_1 * ) V_40 ;
F_3 ( L_13 ) ;
F_12 ( & V_2 -> V_41 , V_42 + V_43 ) ;
F_7 ( V_2 ) ;
}
static int
F_13 ( struct V_31 * V_32 , unsigned int * V_36 )
{
struct V_1 * V_2 = F_5 ( V_32 ) ;
V_2 -> V_36 = F_1 ( V_2 ) ;
* V_36 = V_2 -> V_36 ;
return 0 ;
}
static int
F_14 ( struct V_31 * V_32 , T_1 * V_4 )
{
struct V_1 * V_2 = F_5 ( V_32 ) ;
F_3 ( L_14 , V_2 -> V_30 ) ;
F_3 ( L_15 ,
( V_4 -> V_38 == 0 ) ? L_6 : L_7 ,
( V_4 -> V_38 & V_9 ) ? L_8 : L_7 ,
( V_4 -> V_38 & V_11 ) ? L_9 : L_7 ,
( V_4 -> V_38 & V_25 ) ? L_10 : L_7 ,
( V_4 -> V_38 & V_27 ) ? L_11 : L_7 ,
( V_4 -> V_38 & V_24 ) ? L_12 : L_7 ,
( V_4 -> V_21 == 0 ) ? L_6 : L_7 ,
( V_4 -> V_21 & V_44 ) ? L_16 : L_7 ,
( V_4 -> V_21 & V_22 ) ? L_17 : L_7 ,
( V_4 -> V_21 & V_45 ) ? L_18 : L_7 ,
( V_4 -> V_21 & V_46 ) ? L_19 : L_7 ,
( V_4 -> V_21 & V_47 ) ? L_20 : L_7 ) ;
F_3 ( L_21 ,
V_4 -> V_19 , V_4 -> V_48 , V_4 -> V_49 ) ;
return F_2 ( V_2 , V_4 ) ;
}
int
F_15 ( struct V_31 * V_32 , struct V_50 * V_51 )
{
struct V_1 * V_2 = F_5 ( V_32 ) ;
unsigned int V_52 ;
if( V_51 -> V_51 >= V_53 ) {
F_3 ( L_22 , V_51 -> V_51 ) ;
return - 1 ;
}
if( V_51 -> V_21 & V_54 ) {
V_52 = ( V_51 -> V_52 > 0 ) ? V_51 -> V_52 : V_55 ;
V_2 -> V_56 [ V_51 -> V_51 ] = V_52 ;
}
V_51 -> V_57 = ( unsigned int ) ( V_58 ) V_2 -> V_59 ;
V_51 -> V_60 = V_51 -> V_57 + V_61 ;
return 0 ;
}
static int
F_16 ( struct V_31 * V_32 , struct V_62 * V_51 )
{
struct V_1 * V_2 = F_5 ( V_32 ) ;
unsigned short V_52 = V_51 -> V_52 ;
if( V_51 -> V_51 >= V_63 ) {
F_3 ( L_22 , V_51 -> V_51 ) ;
return - 1 ;
}
if ( V_51 -> V_21 & V_64 ) {
V_2 -> V_65 [ V_51 -> V_51 ] = V_52 ;
V_2 -> V_66 [ V_51 -> V_51 ] = 0 ;
} else {
V_2 -> V_65 [ V_51 -> V_51 ] = 0 ;
V_2 -> V_66 [ V_51 -> V_51 ] = V_52 ;
}
if ( V_51 -> V_21 & V_64 ) {
V_51 -> V_67 = V_2 -> V_68 + V_51 -> V_69 ;
}
else {
V_51 -> V_67 = V_2 -> V_70 + V_51 -> V_69 ;
}
F_3 ( L_23 ,
V_51 -> V_51 , V_51 -> V_67 , V_51 -> V_69 ) ;
return 0 ;
}
int F_17 ( struct V_71 * V_72 , struct V_73 * V_6 , int V_74 , int V_30 )
{
struct V_75 * V_76 ;
struct V_1 * V_2 ;
int V_28 , V_77 ;
V_76 = F_18 ( sizeof( struct V_75 ) , V_78 ) ;
if ( ! V_76 ) {
V_28 = - V_79 ;
goto V_80;
}
V_76 -> V_81 = V_30 ;
for ( V_77 = 0 ; V_77 < V_30 ; V_77 ++ ) {
V_2 = F_19 ( V_77 ) ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_39 . V_82 = & V_83 ;
V_2 -> V_39 . V_6 = & V_84 ;
V_2 -> V_39 . V_85 = V_6 -> V_85 ;
V_2 -> V_39 . V_72 . V_86 = V_72 ;
F_20 ( & V_2 -> V_41 ) ;
V_2 -> V_41 . V_87 = F_11 ;
V_2 -> V_41 . V_88 = ( unsigned long ) V_2 ;
V_2 -> V_41 . V_89 = V_42 + V_43 ;
V_2 -> V_30 = V_74 + V_77 ;
V_2 -> V_90 = 255 ;
V_2 -> V_72 = V_72 ;
V_2 -> V_6 = V_6 ;
V_2 -> V_91 . V_92 = V_93 [ V_2 -> V_30 ] ;
V_2 -> V_94 . V_92 = L_24 ;
V_2 -> V_94 . V_21 = V_95 | V_96 ;
V_2 -> V_97 . V_92 = L_25 ;
V_2 -> V_97 . V_21 = V_95 ;
V_2 -> V_98 . V_92 = L_26 ;
V_2 -> V_98 . V_21 = V_95 ;
if ( V_77 == 0 ) {
V_2 -> V_59 = ( void * )
( F_21 ( ( V_99 ) V_100 , 0x1000 ) -
( V_58 ) V_101 ) ;
V_2 -> V_68 = V_102 ;
V_2 -> V_70 = V_103 ;
}
else {
V_2 -> V_59 = ( void * )
( F_21 ( ( V_99 ) V_104 , 0x1000 ) -
( V_58 ) V_101 ) ;
V_2 -> V_68 = V_105 ;
V_2 -> V_70 = V_106 ;
}
V_107 [ V_77 ] = ( V_58 * ) V_2 -> V_59 ;
V_28 = V_6 -> V_108 ( V_2 ) ;
V_2 -> V_39 . V_109 = V_110 | V_111 ;
V_2 -> V_39 . V_112 = 0 ;
V_2 -> V_39 . V_113 = V_61 ;
V_2 -> V_39 . V_114 = V_2 -> V_90 ;
V_2 -> V_39 . V_115 = ( unsigned long ) V_2 -> V_59 ;
V_2 -> V_36 = F_1 ( V_2 ) ;
V_28 = F_22 ( & V_2 -> V_39 ) ;
if ( V_28 )
goto V_116;
F_23 ( V_2 -> V_39 . V_32 != V_77 ) ;
F_24 ( & V_2 -> V_41 ) ;
}
F_25 ( V_72 , V_76 ) ;
return 0 ;
V_116:
V_6 -> V_117 ( V_2 ) ;
while ( V_77 -- > 0 ) {
V_2 = F_19 ( V_77 ) ;
F_26 ( & V_2 -> V_41 ) ;
F_27 ( & V_2 -> V_39 ) ;
if ( V_77 == 0 ) {
F_28 ( V_2 -> V_59 + ( V_58 ) V_101 ) ;
V_2 -> V_59 = NULL ;
}
#ifndef F_29
else {
F_28 ( V_2 -> V_59 + ( V_58 ) V_101 ) ;
V_2 -> V_59 = NULL ;
}
#endif
V_6 -> V_117 ( V_2 ) ;
}
F_30 ( V_76 ) ;
V_80:
return V_28 ;
}
int F_31 ( struct V_118 * V_72 )
{
struct V_75 * V_76 = F_32 ( V_72 ) ;
int V_77 ;
F_33 ( & V_119 ) ;
F_34 ( V_72 , NULL ) ;
for ( V_77 = 0 ; V_77 < V_76 -> V_81 ; V_77 ++ ) {
struct V_1 * V_2 = F_19 ( V_77 ) ;
F_26 ( & V_2 -> V_41 ) ;
F_27 ( & V_2 -> V_39 ) ;
V_2 -> V_6 -> V_117 ( V_2 ) ;
F_2 ( V_2 , & V_120 ) ;
F_28 ( V_2 -> V_59 + ( V_58 ) V_101 ) ;
V_2 -> V_59 = NULL ;
}
F_30 ( V_76 ) ;
F_35 ( & V_119 ) ;
return 0 ;
}
static int F_36 ( struct V_118 * V_72 )
{
int V_77 , V_28 = - V_121 ;
F_33 ( & V_119 ) ;
for ( V_77 = 0 ; V_77 < F_37 ( V_122 ) ; V_77 ++ ) {
V_28 = V_122 [ V_77 ] ( & V_72 -> V_72 ) ;
if ( V_28 == 0 )
break;
}
F_35 ( & V_119 ) ;
return V_28 ;
}
static int T_2 F_38 ( void )
{
int error = 0 ;
error = F_39 ( & V_123 ) ;
return error ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_123 ) ;
}
