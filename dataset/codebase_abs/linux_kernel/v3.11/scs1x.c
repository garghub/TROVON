static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 -> V_5 ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 1 ;
V_3 -> V_8 = false ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_3 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_3 = V_2 -> V_4 -> V_5 ;
F_4 ( V_3 -> V_10 ) = V_9 ? V_2 : NULL ;
if ( V_9 ) {
V_3 -> V_11 = false ;
F_5 ( & V_3 -> V_12 ) ;
}
}
static void F_6 ( struct V_13 * V_14 , int V_15 ,
void * V_16 , T_1 V_17 , void * V_18 )
{
struct V_3 * V_3 = V_18 ;
if ( V_15 == V_19 ) {
}
V_3 -> V_20 = false ;
F_5 ( & V_3 -> V_12 ) ;
}
static bool F_7 ( T_2 V_21 )
{
return V_21 >= 0x80 && V_21 <= 0xef ;
}
static bool F_8 ( T_2 V_21 )
{
return V_21 == 0xf6 ||
V_21 >= 0xf8 ;
}
static bool F_9 ( T_2 V_21 )
{
return ( V_21 >= 0xc0 && V_21 <= 0xdf ) ||
V_21 == 0xf1 ||
V_21 == 0xf3 ;
}
static bool F_10 ( T_2 V_21 )
{
return ( V_21 >= 0x80 && V_21 <= 0xbf ) ||
( V_21 >= 0xe0 && V_21 <= 0xef ) ||
V_21 == 0xf2 ;
}
static bool F_11 ( T_2 V_21 )
{
return V_21 == 0xf4 ||
V_21 == 0xf5 ||
V_21 == 0xf9 ||
V_21 == 0xfd ;
}
static void F_12 ( unsigned long V_16 )
{
struct V_3 * V_3 = ( void * ) V_16 ;
struct V_1 * V_2 ;
unsigned int V_22 ;
T_2 V_23 ;
struct V_24 * V_25 ;
int V_26 ;
if ( V_3 -> V_20 )
return;
V_2 = F_4 ( V_3 -> V_10 ) ;
if ( ! V_2 ) {
V_3 -> V_11 = true ;
F_13 ( & V_3 -> V_27 ) ;
return;
}
V_22 = V_3 -> V_7 ;
for (; ; ) {
if ( F_14 ( V_2 , & V_23 , 1 ) != 1 ) {
V_3 -> V_7 = V_22 ;
V_3 -> V_11 = true ;
F_13 ( & V_3 -> V_27 ) ;
return;
}
if ( V_3 -> V_8 && V_23 < 0x80 ) {
if ( V_3 -> V_28 ) {
if ( V_22 < V_29 ) {
V_3 -> V_30 [ V_22 ] = V_23 << 4 ;
V_3 -> V_28 = false ;
}
} else {
V_3 -> V_30 [ V_22 ++ ] |= V_23 & 0x0f ;
V_3 -> V_28 = true ;
}
} else if ( V_23 < 0x80 ) {
if ( V_22 == 1 ) {
if ( ! F_7 ( V_3 -> V_6 ) )
continue;
V_3 -> V_30 [ 0 ] = V_31 ;
V_3 -> V_30 [ V_22 ++ ] = V_3 -> V_6 ;
}
V_3 -> V_30 [ V_22 ++ ] = V_23 ;
if ( ( V_22 == 3 && F_9 ( V_3 -> V_6 ) ) ||
( V_22 == 4 && F_10 ( V_3 -> V_6 ) ) )
break;
if ( V_22 == 1 + F_15 ( V_32 ) &&
! memcmp ( V_3 -> V_30 + 1 , V_32 ,
F_15 ( V_32 ) ) ) {
V_3 -> V_8 = true ;
V_3 -> V_28 = true ;
V_22 = 0 ;
}
if ( V_22 >= V_29 )
V_22 = 1 ;
} else if ( V_23 == 0xf7 ) {
if ( V_3 -> V_8 ) {
if ( V_22 >= 1 && V_3 -> V_28 &&
V_3 -> V_30 [ 0 ] != V_33 )
break;
} else {
if ( V_22 > 1 && V_3 -> V_6 == 0xf0 ) {
V_3 -> V_30 [ V_22 ++ ] = 0xf7 ;
break;
}
}
V_22 = 1 ;
V_3 -> V_8 = false ;
} else if ( ! F_11 ( V_23 ) &&
V_23 < 0xf8 ) {
V_22 = 1 ;
V_3 -> V_30 [ 0 ] = V_31 ;
V_3 -> V_30 [ V_22 ++ ] = V_23 ;
V_3 -> V_6 = V_23 ;
V_3 -> V_8 = false ;
if ( F_8 ( V_23 ) )
break;
}
}
V_3 -> V_7 = 1 ;
V_3 -> V_8 = false ;
V_3 -> V_20 = true ;
V_25 = F_16 ( V_3 -> V_34 ) ;
V_26 = V_25 -> V_26 ;
F_17 () ;
F_18 ( V_25 -> V_14 , & V_3 -> V_35 , V_36 ,
V_25 -> V_37 , V_26 , V_25 -> V_38 ,
V_39 , V_3 -> V_30 , V_22 ,
F_6 , V_3 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 -> V_5 ;
F_20 ( V_3 -> V_27 , V_3 -> V_11 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_4 -> V_5 ;
V_3 -> V_40 = 0 ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_23 ( struct V_1 * V_2 , int V_9 )
{
struct V_3 * V_3 = V_2 -> V_4 -> V_5 ;
F_4 ( V_3 -> V_41 ) = V_9 ? V_2 : NULL ;
}
static void F_24 ( struct V_1 * V_2 ,
T_2 V_23 )
{
T_2 V_42 [ 2 ] ;
V_42 [ 0 ] = V_23 >> 4 ;
V_42 [ 1 ] = V_23 & 0x0f ;
F_25 ( V_2 , V_42 , 2 ) ;
}
static void F_26 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
T_2 V_23 )
{
if ( V_3 -> V_40 > 0 ) {
F_24 ( V_2 , V_23 ) ;
V_3 -> V_40 -- ;
if ( V_3 -> V_40 == 0 )
F_25 (stream, (const u8[]) { 0xf7 }, 1 ) ;
} else if ( V_23 == 0xf9 ) {
F_25 ( V_2 , V_32 ,
F_15 ( V_32 ) ) ;
F_24 ( V_2 , 0x00 ) ;
F_24 ( V_2 , 0xf9 ) ;
V_3 -> V_40 = 3 ;
} else {
F_25 ( V_2 , & V_23 , 1 ) ;
}
}
static void F_27 ( struct V_3 * V_3 ,
struct V_1 * V_2 ,
const T_2 * V_16 , unsigned int V_43 )
{
unsigned int V_22 ;
if ( V_16 [ 0 ] == V_31 ) {
for ( V_22 = 1 ; V_22 < V_43 ; ++ V_22 )
F_26 ( V_3 , V_2 , V_16 [ V_22 ] ) ;
} else {
F_25 ( V_2 , V_32 ,
F_15 ( V_32 ) ) ;
for ( V_22 = 0 ; V_22 < V_43 ; ++ V_22 )
F_24 ( V_2 , V_16 [ V_22 ] ) ;
F_25 (stream, (const u8[]) { 0xf7 }, 1 ) ;
}
}
static int F_28 ( struct V_3 * V_3 )
{
struct V_44 * V_4 ;
int V_45 ;
V_45 = F_29 ( V_3 -> V_14 , L_1 , 0 , 1 , 1 , & V_4 ) ;
if ( V_45 < 0 )
return V_45 ;
snprintf ( V_4 -> V_46 , sizeof( V_4 -> V_46 ) ,
L_2 , V_3 -> V_14 -> V_47 ) ;
V_4 -> V_48 = V_49 |
V_50 |
V_51 ;
V_4 -> V_5 = V_3 ;
F_30 ( V_4 , V_52 , & V_53 ) ;
F_30 ( V_4 , V_54 , & V_55 ) ;
return 0 ;
}
static void F_31 ( struct V_13 * V_14 , struct V_56 * V_57 ,
int V_58 , int V_59 , int V_60 , int V_26 ,
unsigned long long V_61 , void * V_16 , T_1 V_17 ,
void * V_18 )
{
struct V_3 * V_3 = V_18 ;
struct V_1 * V_2 ;
if ( V_61 != V_3 -> V_62 . V_61 ) {
F_32 ( V_14 , V_57 , V_63 ) ;
return;
}
if ( V_58 != V_64 &&
V_58 != V_36 ) {
F_32 ( V_14 , V_57 , V_65 ) ;
return;
}
if ( V_17 >= 1 ) {
V_2 = F_4 ( V_3 -> V_41 ) ;
if ( V_2 )
F_27 ( V_3 , V_2 , V_16 , V_17 ) ;
}
F_32 ( V_14 , V_57 , V_66 ) ;
}
static int F_33 ( struct V_3 * V_3 )
{
T_3 V_16 ;
int V_45 ;
V_16 = F_34 ( ( ( V_67 ) V_33 << 56 ) |
V_3 -> V_62 . V_61 ) ;
V_45 = F_35 ( V_3 -> V_34 , V_36 ,
V_39 , & V_16 , 8 ) ;
if ( V_45 < 0 )
F_36 ( & V_3 -> V_34 -> V_68 , L_3 ) ;
return V_45 ;
}
static void F_37 ( struct V_69 * V_14 )
{
struct V_3 * V_3 = V_14 -> V_5 ;
F_38 ( & V_3 -> V_62 ) ;
F_39 ( V_3 -> V_30 ) ;
}
static int F_40 ( struct V_70 * V_34 , const struct V_71 * V_72 )
{
struct V_24 * V_73 = F_16 ( V_34 ) ;
struct V_69 * V_14 ;
struct V_3 * V_3 ;
int V_45 ;
V_45 = F_41 ( - 16 , NULL , V_74 , sizeof( * V_3 ) , & V_14 ) ;
if ( V_45 < 0 )
return V_45 ;
F_42 ( V_14 , & V_34 -> V_68 ) ;
V_3 = V_14 -> V_5 ;
V_3 -> V_14 = V_14 ;
V_3 -> V_34 = V_34 ;
F_43 ( & V_3 -> V_12 , F_12 , ( unsigned long ) V_3 ) ;
F_44 ( & V_3 -> V_27 ) ;
V_3 -> V_11 = true ;
V_3 -> V_30 = F_45 ( V_29 , V_75 ) ;
if ( ! V_3 -> V_30 ) {
V_45 = - V_76 ;
goto V_77;
}
V_3 -> V_62 . V_17 = V_29 ;
V_3 -> V_62 . V_78 = F_31 ;
V_3 -> V_62 . V_18 = V_3 ;
V_45 = F_46 ( & V_3 -> V_62 ,
& V_79 ) ;
if ( V_45 < 0 )
goto V_80;
V_14 -> V_81 = F_37 ;
strcpy ( V_14 -> V_82 , L_1 ) ;
strcpy ( V_14 -> V_47 , L_1 ) ;
F_47 ( V_34 -> V_83 , V_84 ,
V_14 -> V_47 , sizeof( V_14 -> V_47 ) ) ;
snprintf ( V_14 -> V_85 , sizeof( V_14 -> V_85 ) ,
L_4 ,
V_14 -> V_47 , V_73 -> V_86 [ 3 ] , V_73 -> V_86 [ 4 ] ,
F_48 ( & V_34 -> V_68 ) , 100 << V_73 -> V_38 ) ;
strcpy ( V_14 -> V_87 , V_14 -> V_47 ) ;
V_45 = F_33 ( V_3 ) ;
if ( V_45 < 0 )
goto V_77;
V_45 = F_28 ( V_3 ) ;
if ( V_45 < 0 )
goto V_77;
V_45 = F_49 ( V_14 ) ;
if ( V_45 < 0 )
goto V_77;
F_50 ( & V_34 -> V_68 , V_3 ) ;
return 0 ;
V_80:
F_39 ( V_3 -> V_30 ) ;
V_77:
F_51 ( V_14 ) ;
return V_45 ;
}
static void F_52 ( struct V_70 * V_34 )
{
struct V_3 * V_3 = F_53 ( & V_34 -> V_68 ) ;
T_3 V_16 ;
V_16 = F_34 ( ( ( V_67 ) V_33 << 56 ) |
V_3 -> V_62 . V_61 ) ;
F_35 ( V_3 -> V_34 , V_36 ,
V_39 , & V_16 , 8 ) ;
}
static void F_54 ( struct V_70 * V_34 )
{
struct V_3 * V_3 = F_53 ( & V_34 -> V_68 ) ;
F_55 ( V_3 -> V_14 ) ;
F_4 ( V_3 -> V_10 ) = NULL ;
F_4 ( V_3 -> V_41 ) = NULL ;
F_20 ( V_3 -> V_27 , V_3 -> V_11 ) ;
F_56 ( & V_3 -> V_12 ) ;
F_57 ( V_3 -> V_14 ) ;
}
static int T_4 F_58 ( void )
{
return F_59 ( & V_88 . V_82 ) ;
}
static void T_5 F_60 ( void )
{
F_61 ( & V_88 . V_82 ) ;
}
