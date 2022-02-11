static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 ( struct V_5 * V_6 )
{
F_4 ( V_7 , 0 ) ;
}
static void F_5 ( struct V_8 * V_9 , bool V_10 )
{
}
static T_1 F_6 ( struct V_11 * V_12 )
{
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_5 * V_6 = V_9 -> V_6 ;
T_1 V_13 = 0 ;
V_13 = F_7 ( V_12 -> V_14 ) &
( V_15 |
V_16 ) ;
return V_13 ;
}
static int F_8 ( void * V_17 )
{
struct V_11 * V_12 = V_17 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_5 * V_6 = V_9 -> V_6 ;
T_1 V_13 = F_6 ( V_12 ) ;
F_4 ( V_12 -> V_14 , V_13 | V_18 ) ;
F_4 ( V_12 -> V_14 , V_13 ) ;
return ( F_7 ( V_12 -> V_14 ) & V_19 ) != 0 ;
}
static int F_9 ( void * V_17 )
{
struct V_11 * V_12 = V_17 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_5 * V_6 = V_9 -> V_6 ;
T_1 V_13 = F_6 ( V_12 ) ;
F_4 ( V_12 -> V_14 , V_13 | V_20 ) ;
F_4 ( V_12 -> V_14 , V_13 ) ;
return ( F_7 ( V_12 -> V_14 ) & V_21 ) != 0 ;
}
static void F_10 ( void * V_17 , int V_22 )
{
struct V_11 * V_12 = V_17 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_5 * V_6 = V_9 -> V_6 ;
T_1 V_13 = F_6 ( V_12 ) ;
T_1 V_23 ;
if ( V_22 )
V_23 = V_24 | V_18 ;
else
V_23 = V_25 | V_18 |
V_26 ;
F_4 ( V_12 -> V_14 , V_13 | V_23 ) ;
F_7 ( V_12 -> V_14 ) ;
}
static void F_11 ( void * V_17 , int V_22 )
{
struct V_11 * V_12 = V_17 ;
struct V_8 * V_9 = V_12 -> V_9 ;
struct V_5 * V_6 = V_9 -> V_6 ;
T_1 V_13 = F_6 ( V_12 ) ;
T_1 V_27 ;
if ( V_22 )
V_27 = V_28 | V_20 ;
else
V_27 = V_29 | V_20 |
V_30 ;
F_4 ( V_12 -> V_14 , V_13 | V_27 ) ;
F_7 ( V_12 -> V_14 ) ;
}
static struct V_2 *
F_12 ( struct V_8 * V_9 , T_1 V_31 )
{
static const int V_32 [] = {
0 ,
V_33 ,
V_34 ,
V_35 ,
V_36 ,
V_37 ,
0 ,
V_38 ,
} ;
struct V_11 * V_12 ;
if ( V_31 >= F_13 ( V_32 ) || ! V_32 [ V_31 ] )
return NULL ;
V_12 = F_14 ( sizeof( struct V_11 ) , V_39 ) ;
if ( V_12 == NULL )
return NULL ;
V_12 -> V_14 = V_32 [ V_31 ] ;
V_12 -> V_9 = V_9 ;
snprintf ( V_12 -> V_4 . V_40 , sizeof( V_12 -> V_4 . V_40 ) ,
L_1 , L_2 [ V_31 ] ) ;
V_12 -> V_4 . V_41 = V_42 ;
V_12 -> V_4 . V_43 = & V_12 -> V_44 ;
V_12 -> V_4 . V_6 . V_45 = & V_9 -> V_6 -> V_46 -> V_6 ;
V_12 -> V_44 . V_47 = F_11 ;
V_12 -> V_44 . V_48 = F_10 ;
V_12 -> V_44 . V_49 = F_9 ;
V_12 -> V_44 . V_50 = F_8 ;
V_12 -> V_44 . V_51 = V_52 ;
V_12 -> V_44 . V_53 = F_15 ( 2200 ) ;
V_12 -> V_44 . V_17 = V_12 ;
if ( F_16 ( & V_12 -> V_4 ) )
goto V_54;
return & V_12 -> V_4 ;
V_54:
F_17 ( V_12 ) ;
return NULL ;
}
static int
F_18 ( struct V_8 * V_9 ,
struct V_2 * V_4 ,
struct V_55 * V_56 ,
int V_57 )
{
struct V_11 * V_12 = F_2 ( V_4 ,
struct V_11 ,
V_4 ) ;
int V_58 ;
F_3 ( V_9 -> V_6 ) ;
F_5 ( V_9 , true ) ;
F_11 ( V_12 , 1 ) ;
F_10 ( V_12 , 1 ) ;
V_51 ( V_52 ) ;
V_58 = V_4 -> V_44 -> V_59 ( V_4 , V_56 , V_57 ) ;
F_11 ( V_12 , 1 ) ;
F_10 ( V_12 , 1 ) ;
F_5 ( V_9 , false ) ;
return V_58 ;
}
static int
F_19 ( struct V_2 * V_4 ,
struct V_55 * V_56 ,
int V_57 )
{
struct V_1 * V_60 = F_2 ( V_4 ,
struct V_1 ,
V_4 ) ;
struct V_8 * V_9 = V_4 -> V_43 ;
struct V_5 * V_6 = V_9 -> V_6 ;
int V_61 , V_62 ;
if ( V_60 -> V_63 )
return F_18 ( V_9 ,
V_60 -> V_63 , V_56 , V_57 ) ;
V_62 = 0 ;
F_4 ( V_7 + V_62 , V_60 -> V_64 ) ;
for ( V_61 = 0 ; V_61 < V_57 ; V_61 ++ ) {
T_2 V_65 = V_56 [ V_61 ] . V_65 ;
T_3 * V_66 = V_56 [ V_61 ] . V_66 ;
if ( V_56 [ V_61 ] . V_67 & V_68 ) {
F_4 ( V_69 + V_62 ,
V_70 | ( V_61 + 1 == V_57 ? V_71 : 0 ) |
( V_65 << V_72 ) |
( V_56 [ V_61 ] . V_73 << V_74 ) |
V_75 | V_76 ) ;
F_7 ( V_77 + V_62 ) ;
do {
T_1 V_78 , V_79 = 0 ;
if ( F_20 ( F_7 ( V_77 + V_62 ) & ( V_80 | V_81 ) , 50 ) )
goto V_53;
if ( F_7 ( V_77 + V_62 ) & V_80 )
goto V_82;
V_78 = F_7 ( V_83 + V_62 ) ;
do {
* V_66 ++ = V_78 & 0xff ;
V_78 >>= 8 ;
} while ( -- V_65 && ++ V_79 < 4 );
} while ( V_65 );
} else {
T_1 V_78 , V_79 ;
V_78 = V_79 = 0 ;
do {
V_78 |= * V_66 ++ << ( 8 * V_79 ) ;
} while ( -- V_65 && ++ V_79 < 4 );
F_4 ( V_83 + V_62 , V_78 ) ;
F_4 ( V_69 + V_62 ,
( V_61 + 1 == V_57 ? V_71 : V_70 ) |
( V_56 [ V_61 ] . V_65 << V_72 ) |
( V_56 [ V_61 ] . V_73 << V_74 ) |
V_84 | V_76 ) ;
F_7 ( V_77 + V_62 ) ;
while ( V_65 ) {
if ( F_20 ( F_7 ( V_77 + V_62 ) & ( V_80 | V_81 ) , 50 ) )
goto V_53;
if ( F_7 ( V_77 + V_62 ) & V_80 )
goto V_82;
V_78 = V_79 = 0 ;
do {
V_78 |= * V_66 ++ << ( 8 * V_79 ) ;
} while ( -- V_65 && ++ V_79 < 4 );
F_4 ( V_83 + V_62 , V_78 ) ;
F_7 ( V_77 + V_62 ) ;
}
}
if ( V_61 + 1 < V_57 && F_20 ( F_7 ( V_77 + V_62 ) & ( V_80 | V_85 ) , 50 ) )
goto V_53;
if ( F_7 ( V_77 + V_62 ) & V_80 )
goto V_82;
}
goto V_86;
V_82:
F_4 ( V_69 + V_62 , V_87 ) ;
F_4 ( V_69 + V_62 , 0 ) ;
V_86:
F_4 ( V_7 + V_62 , 0 ) ;
return V_61 ;
V_53:
F_21 ( L_3 ,
V_60 -> V_64 & 0xff , V_60 -> V_4 . V_40 ) ;
F_4 ( V_7 + V_62 , 0 ) ;
V_60 -> V_63 = F_12 ( V_9 , V_60 -> V_64 & 0xff ) ;
if ( ! V_60 -> V_63 )
return - V_88 ;
return F_18 ( V_9 , V_60 -> V_63 , V_56 , V_57 ) ;
}
static T_1 F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_60 = F_2 ( V_4 ,
struct V_1 ,
V_4 ) ;
if ( V_60 -> V_63 )
V_60 -> V_63 -> V_44 -> V_89 ( V_60 -> V_63 ) ;
return ( V_90 | V_91 |
V_92 |
V_93 ) ;
}
int F_23 ( struct V_5 * V_6 )
{
static const char * V_94 [ V_95 ] = {
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11 ,
} ;
struct V_8 * V_9 = V_6 -> V_96 ;
int V_58 , V_61 ;
V_9 -> V_97 = F_24 ( V_95 , sizeof( struct V_1 ) ,
V_39 ) ;
if ( V_9 -> V_97 == NULL )
return - V_88 ;
for ( V_61 = 0 ; V_61 < V_95 ; V_61 ++ ) {
struct V_1 * V_60 = & V_9 -> V_97 [ V_61 ] ;
V_60 -> V_4 . V_41 = V_42 ;
V_60 -> V_4 . V_98 = V_99 ;
snprintf ( V_60 -> V_4 . V_40 ,
sizeof( V_60 -> V_4 . V_40 ) ,
L_12 ,
V_94 [ V_61 ] ) ;
V_60 -> V_4 . V_6 . V_45 = & V_6 -> V_46 -> V_6 ;
V_60 -> V_4 . V_43 = V_9 ;
V_60 -> V_4 . V_44 = & V_100 ;
V_58 = F_25 ( & V_60 -> V_4 ) ;
if ( V_58 )
goto V_101;
V_60 -> V_64 = V_61 | V_102 ;
V_60 -> V_63 = F_12 ( V_9 , V_61 ) ;
}
F_3 ( V_9 -> V_6 ) ;
return 0 ;
V_101:
while ( -- V_61 ) {
struct V_1 * V_60 = & V_9 -> V_97 [ V_61 ] ;
F_26 ( & V_60 -> V_4 ) ;
}
F_17 ( V_9 -> V_97 ) ;
V_9 -> V_97 = NULL ;
return V_58 ;
}
void F_27 ( struct V_2 * V_4 , int V_103 )
{
struct V_1 * V_60 = F_1 ( V_4 ) ;
V_60 -> V_64 = ( V_60 -> V_64 & ~ ( 0x3 << 8 ) ) | ( V_103 << 8 ) ;
}
void F_28 ( struct V_2 * V_4 , bool V_63 )
{
struct V_1 * V_60 = F_1 ( V_4 ) ;
if ( V_63 ) {
if ( V_60 -> V_63 == NULL ) {
struct V_8 * V_9 = V_4 -> V_43 ;
V_60 -> V_63 = F_12 ( V_9 ,
V_60 -> V_64 & 0xff ) ;
}
} else {
if ( V_60 -> V_63 ) {
F_26 ( V_60 -> V_63 ) ;
F_17 ( V_60 -> V_63 ) ;
V_60 -> V_63 = NULL ;
}
}
}
void F_29 ( struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_96 ;
int V_61 ;
if ( V_9 -> V_97 == NULL )
return;
for ( V_61 = 0 ; V_61 < V_95 ; V_61 ++ ) {
struct V_1 * V_60 = & V_9 -> V_97 [ V_61 ] ;
if ( V_60 -> V_63 ) {
F_26 ( V_60 -> V_63 ) ;
F_17 ( V_60 -> V_63 ) ;
}
F_26 ( & V_60 -> V_4 ) ;
}
F_17 ( V_9 -> V_97 ) ;
V_9 -> V_97 = NULL ;
}
