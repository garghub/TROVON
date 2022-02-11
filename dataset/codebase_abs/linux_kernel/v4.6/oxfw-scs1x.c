static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
T_1 V_4 [ 2 ] ;
V_4 [ 0 ] = V_3 >> 4 ;
V_4 [ 1 ] = V_3 & 0x0f ;
F_2 ( V_2 , V_4 , 2 ) ;
}
static void F_3 ( struct V_5 * V_6 ,
struct V_1 * V_2 , T_1 V_3 )
{
const T_1 V_7 = 0xf7 ;
if ( V_6 -> V_8 > 0 ) {
F_1 ( V_2 , V_3 ) ;
V_6 -> V_8 -- ;
if ( V_6 -> V_8 == 0 )
F_2 ( V_2 , & V_7 , sizeof( V_7 ) ) ;
} else if ( V_3 == 0xf9 ) {
F_2 ( V_2 , V_9 ,
F_4 ( V_9 ) ) ;
F_1 ( V_2 , 0x00 ) ;
F_1 ( V_2 , 0xf9 ) ;
V_6 -> V_8 = 3 ;
} else {
F_2 ( V_2 , & V_3 , 1 ) ;
}
}
static void F_5 ( struct V_5 * V_6 ,
struct V_1 * V_2 ,
const T_1 * V_10 , unsigned int V_11 )
{
unsigned int V_12 ;
const T_1 V_7 = 0xf7 ;
if ( V_10 [ 0 ] == V_13 ) {
for ( V_12 = 1 ; V_12 < V_11 ; ++ V_12 )
F_3 ( V_6 , V_2 , V_10 [ V_12 ] ) ;
} else {
F_2 ( V_2 , V_9 ,
F_4 ( V_9 ) ) ;
for ( V_12 = 0 ; V_12 < V_11 ; ++ V_12 )
F_1 ( V_2 , V_10 [ V_12 ] ) ;
F_2 ( V_2 , & V_7 , sizeof( V_7 ) ) ;
}
}
static void F_6 ( struct V_14 * V_15 , struct V_16 * V_17 ,
int V_18 , int V_19 , int V_20 , int V_21 ,
unsigned long long V_22 , void * V_10 , T_2 V_23 ,
void * V_24 )
{
struct V_5 * V_6 = V_24 ;
struct V_1 * V_2 ;
int V_25 ;
if ( V_22 != V_6 -> V_26 . V_22 ) {
V_25 = V_27 ;
goto V_28;
}
if ( V_18 != V_29 &&
V_18 != V_30 ) {
V_25 = V_31 ;
goto V_28;
}
if ( V_23 >= 1 ) {
V_2 = F_7 ( V_6 -> V_32 ) ;
if ( V_2 )
F_5 ( V_6 , V_2 , V_10 , V_23 ) ;
}
V_25 = V_33 ;
V_28:
F_8 ( V_15 , V_17 , V_25 ) ;
}
static void F_9 ( struct V_14 * V_15 , int V_25 ,
void * V_10 , T_2 V_23 , void * V_24 )
{
struct V_5 * V_6 = V_24 ;
if ( ! F_10 ( V_25 ) ) {
if ( V_25 == V_33 )
V_6 -> V_34 = 0 ;
} else {
V_6 -> error = true ;
}
V_6 -> V_35 = false ;
F_11 ( & V_6 -> V_36 ) ;
}
static bool F_12 ( T_1 V_37 )
{
return V_37 >= 0x80 && V_37 <= 0xef ;
}
static bool F_13 ( T_1 V_37 )
{
return V_37 == 0xf6 ||
V_37 >= 0xf8 ;
}
static bool F_14 ( T_1 V_37 )
{
return ( V_37 >= 0xc0 && V_37 <= 0xdf ) ||
V_37 == 0xf1 ||
V_37 == 0xf3 ;
}
static bool F_15 ( T_1 V_37 )
{
return ( V_37 >= 0x80 && V_37 <= 0xbf ) ||
( V_37 >= 0xe0 && V_37 <= 0xef ) ||
V_37 == 0xf2 ;
}
static bool F_16 ( T_1 V_37 )
{
return V_37 == 0xf4 ||
V_37 == 0xf5 ||
V_37 == 0xf9 ||
V_37 == 0xfd ;
}
static void F_17 ( struct V_38 * V_36 )
{
struct V_5 * V_6 = F_18 ( V_36 , struct V_5 , V_36 ) ;
struct V_1 * V_2 ;
unsigned int V_12 ;
T_1 V_3 ;
int V_21 ;
if ( V_6 -> V_35 )
return;
V_2 = F_7 ( V_6 -> V_39 ) ;
if ( ! V_2 || V_6 -> error ) {
V_6 -> V_40 = true ;
F_19 ( & V_6 -> V_41 ) ;
return;
}
if ( V_6 -> V_34 > 0 )
goto V_42;
V_12 = V_6 -> V_43 ;
for (; ; ) {
if ( F_20 ( V_2 , & V_3 , 1 ) != 1 ) {
V_6 -> V_43 = V_12 ;
V_6 -> V_40 = true ;
F_19 ( & V_6 -> V_41 ) ;
return;
}
if ( V_6 -> V_44 && V_3 < 0x80 ) {
if ( V_6 -> V_45 ) {
if ( V_12 < V_46 ) {
V_6 -> V_47 [ V_12 ] = V_3 << 4 ;
V_6 -> V_45 = false ;
}
} else {
V_6 -> V_47 [ V_12 ++ ] |= V_3 & 0x0f ;
V_6 -> V_45 = true ;
}
} else if ( V_3 < 0x80 ) {
if ( V_12 == 1 ) {
if ( ! F_12 (
V_6 -> V_48 ) )
continue;
V_6 -> V_47 [ 0 ] = V_13 ;
V_6 -> V_47 [ V_12 ++ ] = V_6 -> V_48 ;
}
V_6 -> V_47 [ V_12 ++ ] = V_3 ;
if ( ( V_12 == 3 && F_14 ( V_6 -> V_48 ) ) ||
( V_12 == 4 && F_15 ( V_6 -> V_48 ) ) )
break;
if ( V_12 == 1 + F_4 ( V_9 ) &&
! memcmp ( V_6 -> V_47 + 1 , V_9 ,
F_4 ( V_9 ) ) ) {
V_6 -> V_44 = true ;
V_6 -> V_45 = true ;
V_12 = 0 ;
}
if ( V_12 >= V_46 )
V_12 = 1 ;
} else if ( V_3 == 0xf7 ) {
if ( V_6 -> V_44 ) {
if ( V_12 >= 1 && V_6 -> V_45 &&
V_6 -> V_47 [ 0 ] !=
V_49 )
break;
} else {
if ( V_12 > 1 && V_6 -> V_48 == 0xf0 ) {
V_6 -> V_47 [ V_12 ++ ] = 0xf7 ;
break;
}
}
V_12 = 1 ;
V_6 -> V_44 = false ;
} else if ( ! F_16 ( V_3 ) && V_3 < 0xf8 ) {
V_12 = 1 ;
V_6 -> V_47 [ 0 ] = V_13 ;
V_6 -> V_47 [ V_12 ++ ] = V_3 ;
V_6 -> V_48 = V_3 ;
V_6 -> V_44 = false ;
if ( F_13 ( V_3 ) )
break;
}
}
V_6 -> V_43 = 1 ;
V_6 -> V_44 = false ;
V_6 -> V_34 = V_12 ;
V_42:
V_6 -> V_35 = true ;
V_21 = V_6 -> V_50 -> V_21 ;
F_21 () ;
F_22 ( V_6 -> V_50 -> V_15 , & V_6 -> V_51 ,
V_30 , V_6 -> V_50 -> V_52 ,
V_21 , V_6 -> V_50 -> V_53 , V_54 ,
V_6 -> V_47 , V_6 -> V_34 ,
F_9 , V_6 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_24 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_25 ( struct V_1 * V_2 , int V_55 )
{
struct V_5 * V_6 = V_2 -> V_56 -> V_57 ;
if ( V_55 ) {
V_6 -> V_8 = 0 ;
F_7 ( V_6 -> V_32 ) = V_2 ;
} else {
F_7 ( V_6 -> V_32 ) = NULL ;
}
}
static int F_26 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_27 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_28 ( struct V_1 * V_2 , int V_55 )
{
struct V_5 * V_6 = V_2 -> V_56 -> V_57 ;
if ( V_55 ) {
V_6 -> V_48 = 0 ;
V_6 -> V_43 = 1 ;
V_6 -> V_44 = false ;
V_6 -> V_40 = false ;
V_6 -> V_34 = 0 ;
V_6 -> error = false ;
F_7 ( V_6 -> V_39 ) = V_2 ;
F_11 ( & V_6 -> V_36 ) ;
} else {
F_7 ( V_6 -> V_39 ) = NULL ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_56 -> V_57 ;
F_30 ( V_6 -> V_41 , V_6 -> V_40 ) ;
}
static int F_31 ( struct V_58 * V_59 )
{
struct V_5 * V_6 = V_59 -> V_60 ;
T_3 V_10 ;
V_10 = F_32 ( ( ( V_61 ) V_49 << 56 ) |
V_6 -> V_26 . V_22 ) ;
return F_33 ( V_59 -> V_62 , V_30 ,
V_54 , & V_10 , sizeof( V_10 ) , 0 ) ;
}
static void F_34 ( struct V_63 * V_56 )
{
struct V_5 * V_6 = V_56 -> V_57 ;
F_35 ( & V_6 -> V_26 ) ;
}
void F_36 ( struct V_58 * V_59 )
{
F_31 ( V_59 ) ;
}
int F_37 ( struct V_58 * V_59 )
{
struct V_63 * V_56 ;
struct V_5 * V_6 ;
int V_64 ;
V_6 = F_38 ( sizeof( struct V_5 ) , V_65 ) ;
if ( V_6 == NULL )
return - V_66 ;
V_6 -> V_50 = F_39 ( V_59 -> V_62 ) ;
V_59 -> V_60 = V_6 ;
V_6 -> V_26 . V_23 = V_46 ;
V_6 -> V_26 . V_67 = F_6 ;
V_6 -> V_26 . V_24 = V_6 ;
V_64 = F_40 ( & V_6 -> V_26 ,
& V_68 ) ;
if ( V_64 < 0 )
return V_64 ;
V_64 = F_31 ( V_59 ) ;
if ( V_64 < 0 )
goto V_69;
V_64 = F_41 ( V_59 -> V_15 , L_1 , 0 , 1 , 1 , & V_56 ) ;
if ( V_64 < 0 )
goto V_69;
V_56 -> V_57 = V_6 ;
V_56 -> V_70 = F_34 ;
snprintf ( V_56 -> V_71 , sizeof( V_56 -> V_71 ) ,
L_2 , V_59 -> V_15 -> V_72 ) ;
V_56 -> V_73 = V_74 |
V_75 |
V_76 ;
F_42 ( V_56 , V_77 ,
& V_78 ) ;
F_42 ( V_56 , V_79 ,
& V_80 ) ;
F_43 ( & V_6 -> V_36 , F_17 ) ;
F_44 ( & V_6 -> V_41 ) ;
V_6 -> V_40 = true ;
return 0 ;
V_69:
F_35 ( & V_6 -> V_26 ) ;
return V_64 ;
}
