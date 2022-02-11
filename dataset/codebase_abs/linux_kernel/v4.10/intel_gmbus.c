static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
F_4 ( V_10 , 0 ) ;
}
static void F_5 ( struct V_7 * V_8 , bool V_11 )
{
}
static T_1 F_6 ( struct V_12 * V_13 )
{
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 V_14 = 0 ;
V_14 = F_7 ( V_13 -> V_15 ) &
( V_16 |
V_17 ) ;
return V_14 ;
}
static int F_8 ( void * V_18 )
{
struct V_12 * V_13 = V_18 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 V_14 = F_6 ( V_13 ) ;
F_4 ( V_13 -> V_15 , V_14 | V_19 ) ;
F_4 ( V_13 -> V_15 , V_14 ) ;
return ( F_7 ( V_13 -> V_15 ) & V_20 ) != 0 ;
}
static int F_9 ( void * V_18 )
{
struct V_12 * V_13 = V_18 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 V_14 = F_6 ( V_13 ) ;
F_4 ( V_13 -> V_15 , V_14 | V_21 ) ;
F_4 ( V_13 -> V_15 , V_14 ) ;
return ( F_7 ( V_13 -> V_15 ) & V_22 ) != 0 ;
}
static void F_10 ( void * V_18 , int V_23 )
{
struct V_12 * V_13 = V_18 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 V_14 = F_6 ( V_13 ) ;
T_1 V_24 ;
if ( V_23 )
V_24 = V_25 | V_19 ;
else
V_24 = V_26 | V_19 |
V_27 ;
F_4 ( V_13 -> V_15 , V_14 | V_24 ) ;
F_7 ( V_13 -> V_15 ) ;
}
static void F_11 ( void * V_18 , int V_23 )
{
struct V_12 * V_13 = V_18 ;
struct V_7 * V_8 = V_13 -> V_8 ;
T_1 V_14 = F_6 ( V_13 ) ;
T_1 V_28 ;
if ( V_23 )
V_28 = V_29 | V_21 ;
else
V_28 = V_30 | V_21 |
V_31 ;
F_4 ( V_13 -> V_15 , V_14 | V_28 ) ;
F_7 ( V_13 -> V_15 ) ;
}
static struct V_2 *
F_12 ( struct V_7 * V_8 , T_1 V_32 )
{
static const int V_33 [] = {
0 ,
V_34 ,
V_35 ,
V_36 ,
V_37 ,
V_38 ,
0 ,
V_39 ,
} ;
struct V_12 * V_13 ;
if ( V_32 >= F_13 ( V_33 ) || ! V_33 [ V_32 ] )
return NULL ;
V_13 = F_14 ( sizeof( struct V_12 ) , V_40 ) ;
if ( V_13 == NULL )
return NULL ;
V_13 -> V_15 = V_33 [ V_32 ] ;
V_13 -> V_8 = V_8 ;
snprintf ( V_13 -> V_4 . V_41 , sizeof( V_13 -> V_4 . V_41 ) ,
L_1 , L_2 [ V_32 ] ) ;
V_13 -> V_4 . V_42 = V_43 ;
V_13 -> V_4 . V_44 = & V_13 -> V_45 ;
V_13 -> V_4 . V_6 . V_46 = & V_8 -> V_6 -> V_47 -> V_6 ;
V_13 -> V_45 . V_48 = F_11 ;
V_13 -> V_45 . V_49 = F_10 ;
V_13 -> V_45 . V_50 = F_9 ;
V_13 -> V_45 . V_51 = F_8 ;
V_13 -> V_45 . V_52 = V_53 ;
V_13 -> V_45 . V_54 = F_15 ( 2200 ) ;
V_13 -> V_45 . V_18 = V_13 ;
if ( F_16 ( & V_13 -> V_4 ) )
goto V_55;
return & V_13 -> V_4 ;
V_55:
F_17 ( V_13 ) ;
return NULL ;
}
static int
F_18 ( struct V_7 * V_8 ,
struct V_2 * V_4 ,
struct V_56 * V_57 ,
int V_58 )
{
struct V_12 * V_13 = F_2 ( V_4 ,
struct V_12 ,
V_4 ) ;
int V_59 ;
F_3 ( V_8 -> V_6 ) ;
F_5 ( V_8 , true ) ;
F_11 ( V_13 , 1 ) ;
F_10 ( V_13 , 1 ) ;
V_52 ( V_53 ) ;
V_59 = V_4 -> V_45 -> V_60 ( V_4 , V_57 , V_58 ) ;
F_11 ( V_13 , 1 ) ;
F_10 ( V_13 , 1 ) ;
F_5 ( V_8 , false ) ;
return V_59 ;
}
static int
F_19 ( struct V_2 * V_4 ,
struct V_56 * V_57 ,
int V_58 )
{
struct V_1 * V_61 = F_2 ( V_4 ,
struct V_1 ,
V_4 ) ;
struct V_7 * V_8 = V_4 -> V_44 ;
int V_62 , V_63 ;
if ( V_61 -> V_64 )
return F_18 ( V_8 ,
V_61 -> V_64 , V_57 , V_58 ) ;
V_63 = 0 ;
F_4 ( V_10 + V_63 , V_61 -> V_65 ) ;
for ( V_62 = 0 ; V_62 < V_58 ; V_62 ++ ) {
T_2 V_66 = V_57 [ V_62 ] . V_66 ;
T_3 * V_67 = V_57 [ V_62 ] . V_67 ;
if ( V_57 [ V_62 ] . V_68 & V_69 ) {
F_4 ( V_70 + V_63 ,
V_71 |
( V_62 + 1 == V_58 ? V_72 : 0 ) |
( V_66 << V_73 ) |
( V_57 [ V_62 ] . V_74 << V_75 ) |
V_76 | V_77 ) ;
F_7 ( V_78 + V_63 ) ;
do {
T_1 V_79 , V_80 = 0 ;
if ( F_20 ( F_7 ( V_78 + V_63 ) &
( V_81 | V_82 ) , 50 ) )
goto V_54;
if ( F_7 ( V_78 + V_63 ) & V_81 )
goto V_83;
V_79 = F_7 ( V_84 + V_63 ) ;
do {
* V_67 ++ = V_79 & 0xff ;
V_79 >>= 8 ;
} while ( -- V_66 && ++ V_80 < 4 );
} while ( V_66 );
} else {
T_1 V_79 , V_80 ;
V_79 = V_80 = 0 ;
do {
V_79 |= * V_67 ++ << ( 8 * V_80 ) ;
} while ( -- V_66 && ++ V_80 < 4 );
F_4 ( V_84 + V_63 , V_79 ) ;
F_4 ( V_70 + V_63 ,
( V_62 + 1 == V_58 ? V_72 : V_71 ) |
( V_57 [ V_62 ] . V_66 << V_73 ) |
( V_57 [ V_62 ] . V_74 << V_75 ) |
V_85 | V_77 ) ;
F_7 ( V_78 + V_63 ) ;
while ( V_66 ) {
if ( F_20 ( F_7 ( V_78 + V_63 ) &
( V_81 | V_82 ) , 50 ) )
goto V_54;
if ( F_7 ( V_78 + V_63 ) &
V_81 )
goto V_83;
V_79 = V_80 = 0 ;
do {
V_79 |= * V_67 ++ << ( 8 * V_80 ) ;
} while ( -- V_66 && ++ V_80 < 4 );
F_4 ( V_84 + V_63 , V_79 ) ;
F_7 ( V_78 + V_63 ) ;
}
}
if ( V_62 + 1 < V_58 && F_20 ( F_7 ( V_78 + V_63 ) & ( V_81 | V_86 ) , 50 ) )
goto V_54;
if ( F_7 ( V_78 + V_63 ) & V_81 )
goto V_83;
}
goto V_87;
V_83:
F_4 ( V_70 + V_63 , V_88 ) ;
F_4 ( V_70 + V_63 , 0 ) ;
V_87:
F_4 ( V_10 + V_63 , 0 ) ;
return V_62 ;
V_54:
F_21 ( L_3 ,
V_61 -> V_65 & 0xff , V_61 -> V_4 . V_41 ) ;
F_4 ( V_10 + V_63 , 0 ) ;
V_61 -> V_64 = F_12 ( V_8 , V_61 -> V_65 & 0xff ) ;
if ( ! V_61 -> V_64 )
return - V_89 ;
return F_18 ( V_8 , V_61 -> V_64 , V_57 , V_58 ) ;
}
static T_1 F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_61 = F_2 ( V_4 ,
struct V_1 ,
V_4 ) ;
if ( V_61 -> V_64 )
V_61 -> V_64 -> V_45 -> V_90 ( V_61 -> V_64 ) ;
return ( V_91 | V_92 |
V_93 |
V_94 ) ;
}
int F_23 ( struct V_5 * V_6 )
{
static const char * V_95 [ V_96 ] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
} ;
struct V_7 * V_8 = V_6 -> V_9 ;
int V_59 , V_62 ;
V_8 -> V_97 = F_24 ( V_96 , sizeof( struct V_1 ) ,
V_40 ) ;
if ( V_8 -> V_97 == NULL )
return - V_89 ;
if ( F_25 ( V_6 ) )
V_8 -> V_98 = V_8 -> V_99 ;
else
V_8 -> V_98 = V_8 -> V_100 ;
for ( V_62 = 0 ; V_62 < V_96 ; V_62 ++ ) {
struct V_1 * V_61 = & V_8 -> V_97 [ V_62 ] ;
V_61 -> V_4 . V_42 = V_43 ;
V_61 -> V_4 . V_101 = V_102 ;
snprintf ( V_61 -> V_4 . V_41 ,
sizeof( V_61 -> V_4 . V_41 ) ,
L_12 ,
V_95 [ V_62 ] ) ;
V_61 -> V_4 . V_6 . V_46 = & V_6 -> V_47 -> V_6 ;
V_61 -> V_4 . V_44 = V_8 ;
V_61 -> V_4 . V_45 = & V_103 ;
V_59 = F_26 ( & V_61 -> V_4 ) ;
if ( V_59 )
goto V_104;
V_61 -> V_65 = V_62 | V_105 ;
V_61 -> V_64 = F_12 ( V_8 , V_62 ) ;
}
F_3 ( V_8 -> V_6 ) ;
return 0 ;
V_104:
while ( V_62 -- ) {
struct V_1 * V_61 = & V_8 -> V_97 [ V_62 ] ;
F_27 ( & V_61 -> V_4 ) ;
}
F_17 ( V_8 -> V_97 ) ;
V_8 -> V_97 = NULL ;
return V_59 ;
}
void F_28 ( struct V_2 * V_4 , int V_106 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
V_61 -> V_65 = ( V_61 -> V_65 & ~ ( 0x3 << 8 ) ) | ( V_106 << 8 ) ;
}
void F_29 ( struct V_2 * V_4 , bool V_64 )
{
struct V_1 * V_61 = F_1 ( V_4 ) ;
if ( V_64 ) {
if ( V_61 -> V_64 == NULL ) {
struct V_7 * V_8 = V_4 -> V_44 ;
V_61 -> V_64 = F_12 ( V_8 ,
V_61 -> V_65 & 0xff ) ;
}
} else {
if ( V_61 -> V_64 ) {
F_27 ( V_61 -> V_64 ) ;
F_17 ( V_61 -> V_64 ) ;
V_61 -> V_64 = NULL ;
}
}
}
void F_30 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
int V_62 ;
if ( V_8 -> V_97 == NULL )
return;
for ( V_62 = 0 ; V_62 < V_96 ; V_62 ++ ) {
struct V_1 * V_61 = & V_8 -> V_97 [ V_62 ] ;
if ( V_61 -> V_64 ) {
F_27 ( V_61 -> V_64 ) ;
F_17 ( V_61 -> V_64 ) ;
}
F_27 ( & V_61 -> V_4 ) ;
}
V_8 -> V_98 = NULL ;
F_17 ( V_8 -> V_97 ) ;
V_8 -> V_97 = NULL ;
}
