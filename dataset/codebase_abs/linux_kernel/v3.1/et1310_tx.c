int F_1 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
struct V_4 * V_4 = & V_2 -> V_4 ;
V_2 -> V_4 . V_5 =
F_2 ( V_6 , sizeof( struct V_7 ) , V_8 | V_9 ) ;
if ( ! V_2 -> V_4 . V_5 ) {
F_3 ( & V_2 -> V_10 -> V_11 , L_1 ) ;
return - V_12 ;
}
V_3 = ( sizeof( struct V_13 ) * V_14 ) + 4096 - 1 ;
V_4 -> V_15 =
(struct V_13 * ) F_4 ( V_2 -> V_10 , V_3 ,
& V_4 -> V_16 ) ;
if ( ! V_2 -> V_4 . V_15 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_2 ) ;
return - V_12 ;
}
V_4 -> V_17 = F_4 ( V_2 -> V_10 ,
sizeof( V_18 ) ,
& V_4 -> V_19 ) ;
if ( ! V_2 -> V_4 . V_19 ) {
F_3 ( & V_2 -> V_10 -> V_11 ,
L_3 ) ;
return - V_12 ;
}
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
int V_3 = 0 ;
if ( V_2 -> V_4 . V_15 ) {
V_3 = ( sizeof( struct V_13 ) * V_14 )
+ 4096 - 1 ;
F_6 ( V_2 -> V_10 ,
V_3 ,
V_2 -> V_4 . V_15 ,
V_2 -> V_4 . V_16 ) ;
V_2 -> V_4 . V_15 = NULL ;
}
if ( V_2 -> V_4 . V_17 ) {
F_6 ( V_2 -> V_10 ,
sizeof( V_18 ) ,
V_2 -> V_4 . V_17 ,
V_2 -> V_4 . V_19 ) ;
V_2 -> V_4 . V_17 = NULL ;
}
F_7 ( V_2 -> V_4 . V_5 ) ;
}
void F_8 ( struct V_1 * V_20 )
{
struct V_21 T_1 * V_22 = & V_20 -> V_23 -> V_22 ;
F_9 ( ( V_18 ) ( ( V_24 ) V_20 -> V_4 . V_16 >> 32 ) ,
& V_22 -> V_25 ) ;
F_9 ( ( V_18 ) V_20 -> V_4 . V_16 ,
& V_22 -> V_26 ) ;
F_9 ( V_14 - 1 , & V_22 -> V_27 ) ;
F_9 ( ( V_18 ) ( ( V_24 ) V_20 -> V_4 . V_19 >> 32 ) ,
& V_22 -> V_28 ) ;
F_9 ( ( V_18 ) V_20 -> V_4 . V_19 , & V_22 -> V_29 ) ;
* V_20 -> V_4 . V_17 = 0 ;
F_9 ( 0 , & V_22 -> V_30 ) ;
V_20 -> V_4 . V_31 = 0 ;
}
void F_10 ( struct V_1 * V_20 )
{
F_9 ( V_32 | V_33 ,
& V_20 -> V_23 -> V_22 . V_34 ) ;
}
void F_11 ( struct V_1 * V_20 )
{
F_9 ( V_33 | ( V_35 << V_36 ) ,
& V_20 -> V_23 -> V_22 . V_34 ) ;
}
void F_12 ( struct V_1 * V_2 )
{
struct V_7 * V_7 ;
V_18 V_37 ;
struct V_4 * V_4 ;
V_4 = & V_2 -> V_4 ;
V_7 = V_2 -> V_4 . V_5 ;
V_4 -> V_38 = V_7 ;
memset ( V_7 , 0 , sizeof( struct V_7 ) * V_6 ) ;
for ( V_37 = 0 ; V_37 ++ < V_6 ; V_7 ++ )
V_7 -> V_39 = V_7 + 1 ;
V_7 -- ;
V_4 -> V_40 = V_7 ;
V_7 -> V_39 = NULL ;
V_4 -> V_41 = NULL ;
V_4 -> V_42 = NULL ;
}
int F_13 ( struct V_43 * V_44 , struct V_45 * V_46 )
{
int V_47 = 0 ;
struct V_1 * V_20 = NULL ;
V_20 = F_14 ( V_46 ) ;
if ( V_20 -> V_4 . V_48 >= V_6 ) {
V_47 = - V_12 ;
} else {
if ( ( V_20 -> V_49 & V_50 ) ||
! F_15 ( V_46 ) ) {
F_16 ( V_44 ) ;
V_44 = NULL ;
V_20 -> V_51 . V_52 ++ ;
} else {
V_47 = F_17 ( V_44 , V_20 ) ;
if ( V_47 != 0 && V_47 != - V_12 ) {
F_16 ( V_44 ) ;
V_44 = NULL ;
V_20 -> V_51 . V_52 ++ ;
}
}
}
return V_47 ;
}
static int F_17 ( struct V_43 * V_44 ,
struct V_1 * V_20 )
{
int V_47 ;
struct V_7 * V_7 = NULL ;
T_2 * V_53 ;
unsigned long V_49 ;
if ( V_44 -> V_54 < V_55 )
return - V_56 ;
F_18 ( & V_20 -> V_57 , V_49 ) ;
V_7 = V_20 -> V_4 . V_38 ;
if ( V_7 == NULL ) {
F_19 ( & V_20 -> V_57 , V_49 ) ;
return - V_12 ;
}
V_20 -> V_4 . V_38 = V_7 -> V_39 ;
if ( V_20 -> V_4 . V_38 == NULL )
V_20 -> V_4 . V_40 = NULL ;
F_19 ( & V_20 -> V_57 , V_49 ) ;
V_7 -> V_44 = V_44 ;
if ( V_44 -> V_58 != NULL && V_44 -> V_54 - V_44 -> V_59 >= 6 ) {
V_53 = ( T_2 * ) V_44 -> V_58 ;
if ( ( V_53 [ 0 ] == 0xffff ) &&
( V_53 [ 1 ] == 0xffff ) && ( V_53 [ 2 ] == 0xffff ) ) {
V_7 -> V_49 |= V_60 ;
} else if ( ( V_53 [ 0 ] & 0x3 ) == 0x0001 ) {
V_7 -> V_49 |= V_61 ;
}
}
V_7 -> V_39 = NULL ;
V_47 = F_20 ( V_20 , V_7 ) ;
if ( V_47 != 0 ) {
F_18 ( & V_20 -> V_57 , V_49 ) ;
if ( V_20 -> V_4 . V_40 )
V_20 -> V_4 . V_40 -> V_39 = V_7 ;
else
V_20 -> V_4 . V_38 = V_7 ;
V_20 -> V_4 . V_40 = V_7 ;
F_19 ( & V_20 -> V_57 , V_49 ) ;
return V_47 ;
}
F_21 ( V_20 -> V_4 . V_48 > V_6 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_20 , struct V_7 * V_7 )
{
V_18 V_62 ;
struct V_13 V_63 [ 24 ] ;
V_18 V_64 = 0 ;
V_18 V_65 , V_66 ;
struct V_43 * V_44 = V_7 -> V_44 ;
V_18 V_67 = F_22 ( V_44 ) -> V_67 + 1 ;
struct V_68 * V_69 = & F_22 ( V_44 ) -> V_69 [ 0 ] ;
unsigned long V_49 ;
if ( V_67 > 23 )
return - V_56 ;
memset ( V_63 , 0 , sizeof( struct V_13 ) * ( V_67 + 1 ) ) ;
for ( V_62 = 0 ; V_62 < V_67 ; V_62 ++ ) {
if ( V_62 == 0 ) {
if ( ( V_44 -> V_54 - V_44 -> V_59 ) <= 1514 ) {
V_63 [ V_64 ] . V_70 = 0 ;
V_63 [ V_64 ] . V_71 =
V_44 -> V_54 - V_44 -> V_59 ;
V_63 [ V_64 ++ ] . V_72 =
F_23 ( V_20 -> V_10 ,
V_44 -> V_58 ,
V_44 -> V_54 -
V_44 -> V_59 ,
V_73 ) ;
} else {
V_63 [ V_64 ] . V_70 = 0 ;
V_63 [ V_64 ] . V_71 =
( V_44 -> V_54 - V_44 -> V_59 ) / 2 ;
V_63 [ V_64 ++ ] . V_72 =
F_23 ( V_20 -> V_10 ,
V_44 -> V_58 ,
( ( V_44 -> V_54 -
V_44 -> V_59 ) / 2 ) ,
V_73 ) ;
V_63 [ V_64 ] . V_70 = 0 ;
V_63 [ V_64 ] . V_71 =
( V_44 -> V_54 - V_44 -> V_59 ) / 2 ;
V_63 [ V_64 ++ ] . V_72 =
F_23 ( V_20 -> V_10 ,
V_44 -> V_58 +
( ( V_44 -> V_54 -
V_44 -> V_59 ) / 2 ) ,
( ( V_44 -> V_54 -
V_44 -> V_59 ) / 2 ) ,
V_73 ) ;
}
} else {
V_63 [ V_64 ] . V_70 = 0 ;
V_63 [ V_64 ] . V_71 =
V_69 [ V_62 - 1 ] . V_74 ;
V_63 [ V_64 ++ ] . V_72 =
F_24 ( V_20 -> V_10 ,
V_69 [ V_62 - 1 ] . V_75 ,
V_69 [ V_62 - 1 ] . V_76 ,
V_69 [ V_62 - 1 ] . V_74 ,
V_73 ) ;
}
}
if ( V_64 == 0 )
return - V_56 ;
if ( V_20 -> V_77 == V_78 ) {
if ( ++ V_20 -> V_4 . V_79 == V_80 ) {
V_63 [ V_64 - 1 ] . V_49 = 0x5 ;
V_20 -> V_4 . V_79 = 0 ;
} else {
V_63 [ V_64 - 1 ] . V_49 = 0x1 ;
}
} else
V_63 [ V_64 - 1 ] . V_49 = 0x5 ;
V_63 [ 0 ] . V_49 |= 2 ;
V_7 -> V_81 = V_20 -> V_4 . V_31 ;
V_7 -> V_82 = 0 ;
F_18 ( & V_20 -> V_83 , V_49 ) ;
V_65 = V_14 -
F_25 ( V_20 -> V_4 . V_31 ) ;
if ( V_65 >= V_64 ) {
V_66 = 0 ;
V_65 = V_64 ;
} else {
V_66 = V_64 - V_65 ;
}
memcpy ( V_20 -> V_4 . V_15 +
F_25 ( V_20 -> V_4 . V_31 ) , V_63 ,
sizeof( struct V_13 ) * V_65 ) ;
F_26 ( & V_20 -> V_4 . V_31 , V_65 ) ;
if ( F_25 ( V_20 -> V_4 . V_31 ) == 0 ||
F_25 ( V_20 -> V_4 . V_31 ) == V_14 ) {
V_20 -> V_4 . V_31 &= ~ V_84 ;
V_20 -> V_4 . V_31 ^= V_85 ;
}
if ( V_66 ) {
memcpy ( V_20 -> V_4 . V_15 ,
V_63 + V_65 ,
sizeof( struct V_13 ) * V_66 ) ;
F_26 ( & V_20 -> V_4 . V_31 , V_66 ) ;
}
if ( F_25 ( V_20 -> V_4 . V_31 ) == 0 ) {
if ( V_20 -> V_4 . V_31 )
V_7 -> V_86 = V_14 - 1 ;
else
V_7 -> V_86 = V_85 | ( V_14 - 1 ) ;
} else
V_7 -> V_86 = V_20 -> V_4 . V_31 - 1 ;
F_27 ( & V_20 -> V_87 ) ;
if ( V_20 -> V_4 . V_42 )
V_20 -> V_4 . V_42 -> V_39 = V_7 ;
else
V_20 -> V_4 . V_41 = V_7 ;
V_20 -> V_4 . V_42 = V_7 ;
F_21 ( V_7 -> V_39 != NULL ) ;
V_20 -> V_4 . V_48 ++ ;
F_28 ( & V_20 -> V_87 ) ;
F_9 ( V_20 -> V_4 . V_31 ,
& V_20 -> V_23 -> V_22 . V_30 ) ;
if ( V_20 -> V_77 == V_78 ) {
F_9 ( V_88 * V_89 ,
& V_20 -> V_23 -> V_90 . V_91 ) ;
}
F_19 ( & V_20 -> V_83 , V_49 ) ;
return 0 ;
}
inline void F_29 ( struct V_1 * V_20 ,
struct V_7 * V_7 )
{
unsigned long V_49 ;
struct V_13 * V_63 = NULL ;
struct V_92 * V_93 = & V_20 -> V_51 ;
if ( V_7 -> V_49 & V_60 )
F_30 ( & V_20 -> V_93 . V_94 ) ;
else if ( V_7 -> V_49 & V_61 )
F_30 ( & V_20 -> V_93 . V_95 ) ;
else
F_30 ( & V_20 -> V_93 . V_96 ) ;
if ( V_7 -> V_44 ) {
V_93 -> V_97 += V_7 -> V_44 -> V_54 ;
do {
V_63 = (struct V_13 * ) ( V_20 -> V_4 . V_15 +
F_25 ( V_7 -> V_81 ) ) ;
F_31 ( V_20 -> V_10 ,
V_63 -> V_72 ,
V_63 -> V_71 , V_73 ) ;
F_26 ( & V_7 -> V_81 , 1 ) ;
if ( F_25 ( V_7 -> V_81 ) >=
V_14 ) {
V_7 -> V_81 &= ~ V_84 ;
V_7 -> V_81 ^= V_85 ;
}
} while ( V_63 != ( V_20 -> V_4 . V_15 +
F_25 ( V_7 -> V_86 ) ) );
F_16 ( V_7 -> V_44 ) ;
}
memset ( V_7 , 0 , sizeof( struct V_7 ) ) ;
F_18 ( & V_20 -> V_57 , V_49 ) ;
V_20 -> V_51 . V_98 ++ ;
if ( V_20 -> V_4 . V_40 )
V_20 -> V_4 . V_40 -> V_39 = V_7 ;
else
V_20 -> V_4 . V_38 = V_7 ;
V_20 -> V_4 . V_40 = V_7 ;
F_19 ( & V_20 -> V_57 , V_49 ) ;
F_21 ( V_20 -> V_4 . V_48 < 0 ) ;
}
void F_32 ( struct V_1 * V_20 )
{
struct V_7 * V_7 ;
unsigned long V_49 ;
V_18 V_99 = 0 ;
F_18 ( & V_20 -> V_87 , V_49 ) ;
V_7 = V_20 -> V_4 . V_41 ;
while ( V_7 != NULL && V_99 < V_6 ) {
struct V_7 * V_39 = V_7 -> V_39 ;
V_20 -> V_4 . V_41 = V_39 ;
if ( V_39 == NULL )
V_20 -> V_4 . V_42 = NULL ;
V_20 -> V_4 . V_48 -- ;
F_19 ( & V_20 -> V_87 , V_49 ) ;
V_99 ++ ;
F_29 ( V_20 , V_7 ) ;
F_18 ( & V_20 -> V_87 , V_49 ) ;
V_7 = V_20 -> V_4 . V_41 ;
}
F_21 ( V_99 == V_6 ) ;
F_19 ( & V_20 -> V_87 , V_49 ) ;
V_20 -> V_4 . V_48 = 0 ;
}
void F_33 ( struct V_1 * V_20 )
{
unsigned long V_49 ;
V_18 V_100 ;
struct V_7 * V_7 ;
V_18 V_86 ;
V_100 = F_34 ( & V_20 -> V_23 -> V_22 . V_101 ) ;
V_86 = F_25 ( V_100 ) ;
F_18 ( & V_20 -> V_87 , V_49 ) ;
V_7 = V_20 -> V_4 . V_41 ;
while ( V_7 &&
( ( V_100 ^ V_7 -> V_86 ) & V_85 ) &&
V_86 < F_25 ( V_7 -> V_86 ) ) {
V_20 -> V_4 . V_48 -- ;
V_20 -> V_4 . V_41 = V_7 -> V_39 ;
if ( V_7 -> V_39 == NULL )
V_20 -> V_4 . V_42 = NULL ;
F_19 ( & V_20 -> V_87 , V_49 ) ;
F_29 ( V_20 , V_7 ) ;
F_18 ( & V_20 -> V_87 , V_49 ) ;
V_7 = V_20 -> V_4 . V_41 ;
}
while ( V_7 &&
! ( ( V_100 ^ V_7 -> V_86 ) & V_85 )
&& V_86 > ( V_7 -> V_86 & V_84 ) ) {
V_20 -> V_4 . V_48 -- ;
V_20 -> V_4 . V_41 = V_7 -> V_39 ;
if ( V_7 -> V_39 == NULL )
V_20 -> V_4 . V_42 = NULL ;
F_19 ( & V_20 -> V_87 , V_49 ) ;
F_29 ( V_20 , V_7 ) ;
F_18 ( & V_20 -> V_87 , V_49 ) ;
V_7 = V_20 -> V_4 . V_41 ;
}
if ( V_20 -> V_4 . V_48 <= V_6 / 3 )
F_35 ( V_20 -> V_46 ) ;
F_19 ( & V_20 -> V_87 , V_49 ) ;
}
