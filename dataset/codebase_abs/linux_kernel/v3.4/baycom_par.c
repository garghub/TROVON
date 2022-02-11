static void T_1 F_1 ( struct V_1 * V_2 )
{
#ifdef F_2
unsigned long V_3 = V_4 ;
V_2 -> V_5 . V_6 ++ ;
if ( F_3 ( V_3 , V_2 -> V_5 . V_7 + V_8 ) ) {
V_2 -> V_5 . V_7 = V_3 ;
V_2 -> V_5 . V_9 = V_2 -> V_5 . V_6 ;
V_2 -> V_5 . V_6 = 0 ;
V_2 -> V_5 . V_10 = V_2 -> V_5 . V_11 ;
V_2 -> V_5 . V_11 = 0 ;
}
#endif
}
static T_1 void F_4 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
int V_14 ;
unsigned int V_15 = F_5 ( & V_2 -> V_16 ) ;
struct V_17 * V_18 = V_2 -> V_19 -> V_20 ;
for( V_14 = 0 ; V_14 < V_21 ; V_14 ++ , V_15 >>= 1 ) {
unsigned char V_22 = V_23 ;
V_2 -> V_24 . V_25 . V_26 = ( ( V_2 -> V_24 . V_25 . V_26 << 1 ) |
( V_2 -> V_24 . V_25 . V_26 & 1 ) ) ;
if ( ! ( V_15 & 1 ) )
V_2 -> V_24 . V_25 . V_26 ^= 1 ;
if ( V_2 -> V_24 . V_25 . V_26 & ( V_27 << 1 ) )
V_2 -> V_24 . V_25 . V_26 ^=
( V_28 << 1 ) ;
if ( V_2 -> V_24 . V_25 . V_26 & ( V_27 << 2 ) )
V_22 |= V_29 ;
V_18 -> V_30 -> V_31 ( V_18 , V_22 ) ;
V_18 -> V_30 -> V_31 ( V_18 , V_22 | V_32 ) ;
}
}
static T_1 void F_6 ( struct V_12 * V_13 , struct V_1 * V_2 )
{
int V_14 ;
unsigned int V_15 , V_33 , V_34 , V_35 ;
struct V_17 * V_18 = V_2 -> V_19 -> V_20 ;
for( V_15 = V_14 = 0 ; V_14 < V_21 ; V_14 ++ ) {
V_2 -> V_24 . V_25 . V_36 = ( V_2 -> V_24 . V_25 . V_36 << 1 ) ;
if ( V_18 -> V_30 -> V_37 ( V_18 ) & V_38 )
V_2 -> V_24 . V_25 . V_36 |= 1 ;
V_35 = V_2 -> V_24 . V_25 . V_36 ^
( V_2 -> V_24 . V_25 . V_36 >> 1 ) ;
V_18 -> V_30 -> V_31 ( V_18 , V_23 | V_39 ) ;
V_35 ^= ( ( V_35 >> V_40 ) ^
( V_35 >> V_41 ) ) ;
V_15 >>= 1 ;
if ( ! ( V_35 & 1 ) )
V_15 |= 0x8000 ;
V_18 -> V_30 -> V_31 ( V_18 , V_23 | V_39 | V_32 ) ;
}
F_7 ( & V_2 -> V_16 , V_15 ) ;
if ( V_2 -> V_42 & V_43 ) {
V_2 -> V_24 . V_25 . V_44 = ( V_2 -> V_24 . V_25 . V_44 >> 16 )
| ( V_15 << 16 ) ;
for( V_33 = 0x1fe00 , V_34 = 0xfc00 , V_14 = 0 ;
V_14 < V_21 ; V_14 ++ , V_33 <<= 1 , V_34 <<= 1 )
if ( ( V_2 -> V_24 . V_25 . V_44 & V_33 ) == V_34 )
V_2 -> V_24 . V_25 . V_45 = V_46 + 4 ;
for( V_33 = 0x1fe00 , V_34 = 0x1fe00 , V_14 = 0 ;
V_14 < V_21 ; V_14 ++ , V_33 <<= 1 , V_34 <<= 1 )
if ( ( ( V_2 -> V_24 . V_25 . V_44 & V_33 ) == V_34 ) &&
( V_2 -> V_24 . V_25 . V_45 >= 0 ) )
V_2 -> V_24 . V_25 . V_45 -= V_46 - 10 ;
if ( V_2 -> V_24 . V_25 . V_45 >= 0 )
V_2 -> V_24 . V_25 . V_45 -= 2 ;
F_8 ( & V_2 -> V_16 , V_2 -> V_24 . V_25 . V_45 > 0 ) ;
} else {
F_8 ( & V_2 -> V_16 , ! ! ( V_18 -> V_30 -> V_37 ( V_18 ) & V_47 ) ) ;
}
}
static void F_9 ( void * V_48 )
{
struct V_12 * V_13 = V_48 ;
struct V_1 * V_2 = F_10 ( V_13 ) ;
F_1 ( V_2 ) ;
if ( F_11 ( & V_2 -> V_16 ) )
F_4 ( V_13 , V_2 ) ;
else {
F_6 ( V_13 , V_2 ) ;
if ( -- V_2 -> V_24 . V_49 <= 0 ) {
V_2 -> V_24 . V_49 = 6 ;
F_12 () ;
F_13 ( V_13 , & V_2 -> V_16 ) ;
}
}
F_12 () ;
F_14 ( V_13 , & V_2 -> V_16 ) ;
F_15 ( V_13 , & V_2 -> V_16 ) ;
F_16 () ;
}
static void F_17 ( void * V_50 )
{
struct V_12 * V_13 = (struct V_12 * ) V_50 ;
struct V_1 * V_2 = F_10 ( V_13 ) ;
F_18 ( V_51 L_1 , V_13 -> V_52 ) ;
if ( ! F_19 ( V_2 -> V_19 ) )
F_18 ( V_51 L_2 , V_13 -> V_52 ) ;
}
static int F_20 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_17 * V_18 ;
if ( ! V_13 || ! V_2 )
return - V_53 ;
V_18 = F_21 ( V_13 -> V_54 ) ;
if ( ! V_18 ) {
F_18 ( V_55 L_3 , V_13 -> V_54 ) ;
return - V_53 ;
}
if ( V_18 -> V_56 < 0 ) {
F_18 ( V_55 L_4 , V_18 -> V_57 ) ;
F_22 ( V_18 ) ;
return - V_53 ;
}
if ( ( ~ V_18 -> V_58 ) & ( V_59 | V_60 ) ) {
F_18 ( V_55 L_5 , V_18 -> V_57 ) ;
F_22 ( V_18 ) ;
return - V_53 ;
}
memset ( & V_2 -> V_24 , 0 , sizeof( V_2 -> V_24 ) ) ;
V_2 -> V_16 . V_61 . V_62 = 9600 ;
V_2 -> V_19 = F_23 ( V_18 , V_13 -> V_52 , NULL , F_17 ,
F_9 , V_63 , V_13 ) ;
F_22 ( V_18 ) ;
if ( ! V_2 -> V_19 ) {
F_18 ( V_55 L_6 , V_13 -> V_54 ) ;
return - V_53 ;
}
if ( F_19 ( V_2 -> V_19 ) ) {
F_18 ( V_55 L_7 , V_18 -> V_57 ) ;
F_24 ( V_2 -> V_19 ) ;
return - V_64 ;
}
V_18 = V_2 -> V_19 -> V_20 ;
V_13 -> V_56 = V_18 -> V_56 ;
V_18 -> V_30 -> V_65 ( V_18 ) ;
V_2 -> V_16 . V_61 . V_62 = 9600 ;
V_18 -> V_30 -> V_31 ( V_18 , V_39 | V_23 ) ;
V_18 -> V_30 -> V_66 ( V_18 ) ;
F_18 ( V_67 L_8 ,
V_68 , V_13 -> V_54 , V_13 -> V_56 , V_2 -> V_42 ) ;
return 0 ;
}
static int F_25 ( struct V_12 * V_13 )
{
struct V_1 * V_2 = F_10 ( V_13 ) ;
struct V_17 * V_18 ;
if ( ! V_13 || ! V_2 )
return - V_69 ;
V_18 = V_2 -> V_19 -> V_20 ;
V_18 -> V_30 -> V_70 ( V_18 ) ;
V_18 -> V_30 -> V_31 ( V_18 , V_39 | V_23 ) ;
F_26 ( V_2 -> V_19 ) ;
F_24 ( V_2 -> V_19 ) ;
F_18 ( V_67 L_9 ,
V_68 , V_13 -> V_54 , V_13 -> V_56 ) ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , const char * V_71 )
{
if ( ! strncmp ( V_71 , L_10 , 6 ) )
V_2 -> V_42 = 0 ;
else if ( ! strncmp ( V_71 , L_11 , 5 ) )
V_2 -> V_42 = V_43 ;
else
V_2 -> V_42 = ! ! strchr ( V_71 , '*' ) ;
return 0 ;
}
static int F_28 ( struct V_12 * V_13 , struct V_72 * V_73 ,
struct V_74 * V_75 , int V_76 )
{
struct V_1 * V_2 ;
struct F_28 V_77 ;
if ( ! V_13 )
return - V_69 ;
V_2 = F_10 ( V_13 ) ;
F_29 ( V_2 -> V_16 . V_78 != V_79 ) ;
if ( V_76 != V_80 )
return - V_81 ;
switch ( V_75 -> V_76 ) {
default:
break;
case V_82 :
strcpy ( V_75 -> V_15 . V_83 , V_2 -> V_42 ? L_11 : L_10 ) ;
if ( F_30 ( V_73 -> V_84 , V_75 , sizeof( struct V_74 ) ) )
return - V_85 ;
return 0 ;
case V_86 :
if ( F_31 ( V_13 ) || ! F_32 ( V_87 ) )
return - V_88 ;
V_75 -> V_15 . V_83 [ sizeof( V_75 -> V_15 . V_83 ) - 1 ] = '\0' ;
return F_27 ( V_2 , V_75 -> V_15 . V_83 ) ;
case V_89 :
strcpy ( V_75 -> V_15 . V_83 , L_12 ) ;
if ( F_30 ( V_73 -> V_84 , V_75 , sizeof( struct V_74 ) ) )
return - V_85 ;
return 0 ;
case V_90 :
return V_91 ;
}
if ( F_33 ( & V_77 , V_73 -> V_84 , sizeof( V_77 ) ) )
return - V_85 ;
switch ( V_77 . V_76 ) {
default:
return - V_81 ;
#ifdef F_2
case V_92 :
V_77 . V_15 . V_93 . V_94 = V_2 -> V_16 . V_95 ;
V_77 . V_15 . V_93 . V_96 = V_2 -> V_5 . V_9 ;
V_77 . V_15 . V_93 . V_97 = V_2 -> V_5 . V_10 ;
break;
#endif
}
if ( F_30 ( V_73 -> V_84 , & V_77 , sizeof( V_77 ) ) )
return - V_85 ;
return 0 ;
}
static int T_2 F_34 ( void )
{
int V_14 , V_98 = 0 ;
char V_99 = 1 ;
F_18 ( V_100 ) ;
for ( V_14 = 0 ; V_14 < V_101 ; V_14 ++ ) {
struct V_12 * V_13 ;
struct V_1 * V_2 ;
char V_102 [ V_103 ] ;
sprintf ( V_102 , L_13 , V_14 ) ;
if ( ! V_104 [ V_14 ] )
V_99 = 0 ;
if ( ! V_99 )
V_105 [ V_14 ] = 0 ;
V_13 = F_35 ( & V_106 ,
sizeof( struct V_1 ) ,
V_102 , V_105 [ V_14 ] , 0 , 0 ) ;
if ( F_36 ( V_13 ) )
break;
V_2 = F_10 ( V_13 ) ;
if ( V_99 && F_27 ( V_2 , V_104 [ V_14 ] ) )
V_99 = 0 ;
V_98 ++ ;
V_107 [ V_14 ] = V_13 ;
}
if ( ! V_98 )
return - V_53 ;
return 0 ;
}
static void T_3 F_37 ( void )
{
int V_14 ;
for( V_14 = 0 ; V_14 < V_101 ; V_14 ++ ) {
struct V_12 * V_13 = V_107 [ V_14 ] ;
if ( V_13 )
F_38 ( V_13 ) ;
}
}
static int T_2 F_39 ( char * V_108 )
{
static unsigned V_109 ;
int V_110 [ 2 ] ;
if ( V_109 >= V_101 )
return 0 ;
V_108 = F_40 ( V_108 , 2 , V_110 ) ;
if ( V_110 [ 0 ] < 1 )
return 0 ;
V_104 [ V_109 ] = V_108 ;
V_105 [ V_109 ] = V_110 [ 1 ] ;
V_109 ++ ;
return 1 ;
}
