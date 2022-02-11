static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void
F_3 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
if ( F_4 ( V_6 ) )
F_5 ( V_10 , 0 ) ;
else
F_5 ( V_11 , 0 ) ;
}
static void F_6 ( struct V_7 * V_8 , bool V_12 )
{
T_1 V_13 ;
if ( ! F_7 ( V_8 -> V_6 ) )
return;
V_13 = F_8 ( V_14 ) ;
if ( V_12 )
V_13 |= V_15 ;
else
V_13 &= ~ V_15 ;
F_5 ( V_14 , V_13 ) ;
}
static T_1 F_9 ( struct V_16 * V_17 )
{
struct V_7 * V_8 = V_17 -> V_8 ;
struct V_5 * V_6 = V_8 -> V_6 ;
T_1 V_18 = 0 ;
if ( ! F_10 ( V_6 ) && ! F_11 ( V_6 ) )
V_18 = F_12 ( V_17 -> V_19 ) &
( V_20 |
V_21 ) ;
return V_18 ;
}
static int F_13 ( void * V_22 )
{
struct V_16 * V_17 = V_22 ;
struct V_7 * V_8 = V_17 -> V_8 ;
T_1 V_18 = F_9 ( V_17 ) ;
F_14 ( V_17 -> V_19 , V_18 | V_23 ) ;
F_14 ( V_17 -> V_19 , V_18 ) ;
return ( F_12 ( V_17 -> V_19 ) & V_24 ) != 0 ;
}
static int F_15 ( void * V_22 )
{
struct V_16 * V_17 = V_22 ;
struct V_7 * V_8 = V_17 -> V_8 ;
T_1 V_18 = F_9 ( V_17 ) ;
F_14 ( V_17 -> V_19 , V_18 | V_25 ) ;
F_14 ( V_17 -> V_19 , V_18 ) ;
return ( F_12 ( V_17 -> V_19 ) & V_26 ) != 0 ;
}
static void F_16 ( void * V_22 , int V_27 )
{
struct V_16 * V_17 = V_22 ;
struct V_7 * V_8 = V_17 -> V_8 ;
T_1 V_18 = F_9 ( V_17 ) ;
T_1 V_28 ;
if ( V_27 )
V_28 = V_29 | V_23 ;
else
V_28 = V_30 | V_23 |
V_31 ;
F_14 ( V_17 -> V_19 , V_18 | V_28 ) ;
F_17 ( V_17 -> V_19 ) ;
}
static void F_18 ( void * V_22 , int V_27 )
{
struct V_16 * V_17 = V_22 ;
struct V_7 * V_8 = V_17 -> V_8 ;
T_1 V_18 = F_9 ( V_17 ) ;
T_1 V_32 ;
if ( V_27 )
V_32 = V_33 | V_25 ;
else
V_32 = V_34 | V_25 |
V_35 ;
F_14 ( V_17 -> V_19 , V_18 | V_32 ) ;
F_17 ( V_17 -> V_19 ) ;
}
static struct V_2 *
F_19 ( struct V_7 * V_8 , T_1 V_36 )
{
static const int V_37 [] = {
0 ,
V_38 ,
V_39 ,
V_40 ,
V_41 ,
V_42 ,
0 ,
V_43 ,
} ;
struct V_16 * V_17 ;
if ( V_36 >= F_20 ( V_37 ) || ! V_37 [ V_36 ] )
return NULL ;
V_17 = F_21 ( sizeof( struct V_16 ) , V_44 ) ;
if ( V_17 == NULL )
return NULL ;
V_17 -> V_19 = V_37 [ V_36 ] ;
if ( F_4 ( V_8 -> V_6 ) )
V_17 -> V_19 += V_45 - V_39 ;
V_17 -> V_8 = V_8 ;
snprintf ( V_17 -> V_4 . V_46 , sizeof( V_17 -> V_4 . V_46 ) ,
L_1 , L_2 [ V_36 ] ) ;
V_17 -> V_4 . V_47 = V_48 ;
V_17 -> V_4 . V_49 = & V_17 -> V_50 ;
V_17 -> V_4 . V_6 . V_51 = & V_8 -> V_6 -> V_52 -> V_6 ;
V_17 -> V_50 . V_53 = F_18 ;
V_17 -> V_50 . V_54 = F_16 ;
V_17 -> V_50 . V_55 = F_15 ;
V_17 -> V_50 . V_56 = F_13 ;
V_17 -> V_50 . V_57 = V_58 ;
V_17 -> V_50 . V_59 = F_22 ( 2200 ) ;
V_17 -> V_50 . V_22 = V_17 ;
if ( F_23 ( & V_17 -> V_4 ) )
goto V_60;
return & V_17 -> V_4 ;
V_60:
F_24 ( V_17 ) ;
return NULL ;
}
static int
F_25 ( struct V_7 * V_8 ,
struct V_2 * V_4 ,
struct V_61 * V_62 ,
int V_63 )
{
struct V_16 * V_17 = F_2 ( V_4 ,
struct V_16 ,
V_4 ) ;
int V_64 ;
F_3 ( V_8 -> V_6 ) ;
F_6 ( V_8 , true ) ;
F_18 ( V_17 , 1 ) ;
F_16 ( V_17 , 1 ) ;
V_57 ( V_58 ) ;
V_64 = V_4 -> V_50 -> V_65 ( V_4 , V_62 , V_63 ) ;
F_18 ( V_17 , 1 ) ;
F_16 ( V_17 , 1 ) ;
F_6 ( V_8 , false ) ;
return V_64 ;
}
static int
F_26 ( struct V_2 * V_4 ,
struct V_61 * V_62 ,
int V_63 )
{
struct V_1 * V_66 = F_2 ( V_4 ,
struct V_1 ,
V_4 ) ;
struct V_7 * V_8 = V_4 -> V_49 ;
int V_67 , V_68 ;
if ( V_66 -> V_69 )
return F_25 ( V_8 ,
V_66 -> V_69 , V_62 , V_63 ) ;
V_68 = F_4 ( V_8 -> V_6 ) ? V_10 - V_11 : 0 ;
F_5 ( V_11 + V_68 , V_66 -> V_70 ) ;
for ( V_67 = 0 ; V_67 < V_63 ; V_67 ++ ) {
T_2 V_71 = V_62 [ V_67 ] . V_71 ;
T_3 * V_72 = V_62 [ V_67 ] . V_72 ;
if ( V_62 [ V_67 ] . V_73 & V_74 ) {
F_5 ( V_75 + V_68 ,
V_76 | ( V_67 + 1 == V_63 ? V_77 : 0 ) |
( V_71 << V_78 ) |
( V_62 [ V_67 ] . V_79 << V_80 ) |
V_81 | V_82 ) ;
F_17 ( V_83 + V_68 ) ;
do {
T_1 V_13 , V_84 = 0 ;
if ( F_27 ( F_8 ( V_83 + V_68 ) & ( V_85 | V_86 ) , 50 ) )
goto V_59;
if ( F_8 ( V_83 + V_68 ) & V_85 )
goto V_87;
V_13 = F_8 ( V_88 + V_68 ) ;
do {
* V_72 ++ = V_13 & 0xff ;
V_13 >>= 8 ;
} while ( -- V_71 && ++ V_84 < 4 );
} while ( V_71 );
} else {
T_1 V_13 , V_84 ;
V_13 = V_84 = 0 ;
do {
V_13 |= * V_72 ++ << ( 8 * V_84 ) ;
} while ( -- V_71 && ++ V_84 < 4 );
F_5 ( V_88 + V_68 , V_13 ) ;
F_5 ( V_75 + V_68 ,
( V_67 + 1 == V_63 ? V_77 : V_76 ) |
( V_62 [ V_67 ] . V_71 << V_78 ) |
( V_62 [ V_67 ] . V_79 << V_80 ) |
V_89 | V_82 ) ;
F_17 ( V_83 + V_68 ) ;
while ( V_71 ) {
if ( F_27 ( F_8 ( V_83 + V_68 ) & ( V_85 | V_86 ) , 50 ) )
goto V_59;
if ( F_8 ( V_83 + V_68 ) & V_85 )
goto V_87;
V_13 = V_84 = 0 ;
do {
V_13 |= * V_72 ++ << ( 8 * V_84 ) ;
} while ( -- V_71 && ++ V_84 < 4 );
F_5 ( V_88 + V_68 , V_13 ) ;
F_17 ( V_83 + V_68 ) ;
}
}
if ( V_67 + 1 < V_63 && F_27 ( F_8 ( V_83 + V_68 ) & ( V_85 | V_90 ) , 50 ) )
goto V_59;
if ( F_8 ( V_83 + V_68 ) & V_85 )
goto V_87;
}
goto V_91;
V_87:
F_5 ( V_75 + V_68 , V_92 ) ;
F_5 ( V_75 + V_68 , 0 ) ;
V_91:
F_5 ( V_11 + V_68 , 0 ) ;
return V_67 ;
V_59:
F_28 ( L_3 ,
V_66 -> V_70 & 0xff , V_66 -> V_4 . V_46 ) ;
F_5 ( V_11 + V_68 , 0 ) ;
V_66 -> V_69 = F_19 ( V_8 , V_66 -> V_70 & 0xff ) ;
if ( ! V_66 -> V_69 )
return - V_93 ;
return F_25 ( V_8 , V_66 -> V_69 , V_62 , V_63 ) ;
}
static T_1 F_29 ( struct V_2 * V_4 )
{
struct V_1 * V_66 = F_2 ( V_4 ,
struct V_1 ,
V_4 ) ;
if ( V_66 -> V_69 )
V_66 -> V_69 -> V_50 -> V_94 ( V_66 -> V_69 ) ;
return ( V_95 | V_96 |
V_97 |
V_98 ) ;
}
int F_30 ( struct V_5 * V_6 )
{
static const char * V_99 [ V_100 ] = {
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
int V_64 , V_67 ;
V_8 -> V_101 = F_31 ( sizeof( struct V_1 ) , V_100 ,
V_44 ) ;
if ( V_8 -> V_101 == NULL )
return - V_93 ;
for ( V_67 = 0 ; V_67 < V_100 ; V_67 ++ ) {
struct V_1 * V_66 = & V_8 -> V_101 [ V_67 ] ;
V_66 -> V_4 . V_47 = V_48 ;
V_66 -> V_4 . V_102 = V_103 ;
snprintf ( V_66 -> V_4 . V_46 ,
sizeof( V_66 -> V_4 . V_46 ) ,
L_12 ,
V_99 [ V_67 ] ) ;
V_66 -> V_4 . V_6 . V_51 = & V_6 -> V_52 -> V_6 ;
V_66 -> V_4 . V_49 = V_8 ;
V_66 -> V_4 . V_50 = & V_104 ;
V_64 = F_32 ( & V_66 -> V_4 ) ;
if ( V_64 )
goto V_105;
V_66 -> V_70 = V_67 | V_106 ;
V_66 -> V_69 = F_19 ( V_8 , V_67 ) ;
}
F_3 ( V_8 -> V_6 ) ;
return 0 ;
V_105:
while ( -- V_67 ) {
struct V_1 * V_66 = & V_8 -> V_101 [ V_67 ] ;
F_33 ( & V_66 -> V_4 ) ;
}
F_24 ( V_8 -> V_101 ) ;
V_8 -> V_101 = NULL ;
return V_64 ;
}
void F_34 ( struct V_2 * V_4 , int V_107 )
{
struct V_1 * V_66 = F_1 ( V_4 ) ;
V_66 -> V_70 = ( V_66 -> V_70 & ~ ( 0x3 << 8 ) ) | ( V_107 << 8 ) ;
}
void F_35 ( struct V_2 * V_4 , bool V_69 )
{
struct V_1 * V_66 = F_1 ( V_4 ) ;
if ( V_69 ) {
if ( V_66 -> V_69 == NULL ) {
struct V_7 * V_8 = V_4 -> V_49 ;
V_66 -> V_69 = F_19 ( V_8 ,
V_66 -> V_70 & 0xff ) ;
}
} else {
if ( V_66 -> V_69 ) {
F_33 ( V_66 -> V_69 ) ;
F_24 ( V_66 -> V_69 ) ;
V_66 -> V_69 = NULL ;
}
}
}
void F_36 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_9 ;
int V_67 ;
if ( V_8 -> V_101 == NULL )
return;
for ( V_67 = 0 ; V_67 < V_100 ; V_67 ++ ) {
struct V_1 * V_66 = & V_8 -> V_101 [ V_67 ] ;
if ( V_66 -> V_69 ) {
F_33 ( V_66 -> V_69 ) ;
F_24 ( V_66 -> V_69 ) ;
}
F_33 ( & V_66 -> V_4 ) ;
}
F_24 ( V_8 -> V_101 ) ;
V_8 -> V_101 = NULL ;
}
