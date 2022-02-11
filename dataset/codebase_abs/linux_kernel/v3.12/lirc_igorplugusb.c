static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( ! V_2 ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_1 , V_8 ) ;
return - V_9 ;
}
V_5 = V_2 -> V_5 ;
V_4 = V_2 -> V_4 ;
if ( ! V_4 ) {
F_2 ( & V_2 -> V_6 -> V_7 ,
L_2 , V_8 ) ;
return - V_9 ;
}
F_3 ( V_10 L_3 , V_5 ) ;
F_4 ( V_4 -> V_11 ) ;
return V_5 ;
}
static int F_5 ( void * V_12 )
{
struct V_1 * V_2 = V_12 ;
if ( ! V_2 ) {
F_6 ( V_10 L_4 ) ;
return - V_13 ;
}
F_3 ( V_10 L_5 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_6 )
return - V_14 ;
return 0 ;
}
static void F_7 ( void * V_12 )
{
struct V_1 * V_2 = V_12 ;
if ( ! V_2 ) {
F_6 ( V_10 L_6 ) ;
return;
}
F_3 ( V_10 L_7 , V_2 -> V_5 ) ;
}
static void F_8 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 , int V_18 )
{
int V_19 ;
while ( V_17 < V_18 ) {
V_19 = ( unsigned int ) V_2 -> V_20 [ V_17 ] * 85 +
( unsigned int ) V_2 -> V_20 [ V_17 ] / 3 ;
V_2 -> V_21 . V_22 += V_19 ;
if ( V_2 -> V_23 )
V_19 |= V_24 ;
F_9 ( V_16 , ( unsigned char * ) & V_19 ) ;
V_2 -> V_23 ^= 1 ;
++ V_17 ;
}
}
static int F_10 ( void * V_12 , struct V_15 * V_16 )
{
int V_25 ;
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
if ( ! V_2 || ! V_2 -> V_6 )
return - V_14 ;
memset ( V_2 -> V_20 , 0 , V_2 -> V_26 ) ;
V_25 = F_11 ( V_2 -> V_6 , F_12 ( V_2 -> V_6 , 0 ) ,
V_27 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 > 0 ) {
int V_19 , V_32 ;
struct V_33 V_34 ;
if ( V_25 < V_35 )
return - V_36 ;
F_3 ( V_10 L_8 ,
V_25 , 3 , V_2 -> V_20 ) ;
F_13 ( & V_34 ) ;
V_32 = V_34 . V_37 - V_2 -> V_21 . V_37 ;
if ( V_32 + 1 > V_38 / 1000000 )
V_32 = V_38 ;
else {
V_32 *= 1000000 ;
V_32 += V_34 . V_22 - V_2 -> V_21 . V_22 ;
}
V_2 -> V_21 . V_37 = V_34 . V_37 ;
V_2 -> V_21 . V_22 = V_34 . V_22 ;
V_19 = V_32 ;
F_9 ( V_16 , ( unsigned char * ) & V_19 ) ;
V_2 -> V_23 = 1 ;
if ( V_2 -> V_20 [ 2 ] == 0 )
F_8 ( V_2 , V_16 , V_35 , V_25 ) ;
else {
F_14 ( & V_2 -> V_6 -> V_7 ,
L_9 , V_2 -> V_5 ) ;
V_2 -> V_20 [ 2 ] %= V_25 - V_35 ;
F_8 ( V_2 , V_16 , V_35 +
V_2 -> V_20 [ 2 ] - ( V_2 -> V_20 [ 2 ] & 1 ) , V_25 ) ;
F_8 ( V_2 , V_16 , V_35 ,
V_35 + V_2 -> V_20 [ 2 ] ) ;
}
V_25 = F_11 (
V_2 -> V_6 , F_12 ( V_2 -> V_6 , 0 ) ,
V_39 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 < 0 )
F_6 ( V_10 L_10
L_11 , V_2 -> V_5 , V_25 ) ;
return 0 ;
} else if ( V_25 < 0 )
F_6 ( V_10 L_12 ,
V_2 -> V_5 , V_25 ) ;
return - V_36 ;
}
static int F_15 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_44 * V_7 ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_49 = NULL ;
int V_5 , V_50 , V_51 ;
char V_16 [ 63 ] , V_52 [ 128 ] = L_13 ;
int V_25 ;
F_3 ( V_10 L_14 ) ;
V_7 = F_16 ( V_41 ) ;
V_46 = V_41 -> V_53 ;
if ( V_46 -> V_54 . V_55 != 1 )
return - V_14 ;
V_48 = & V_46 -> V_56 -> V_54 ;
if ( ( ( V_48 -> V_57 & V_58 )
!= V_29 )
|| ( V_48 -> V_59 & V_60 )
!= V_61 )
return - V_14 ;
V_50 = F_12 ( V_7 , V_48 -> V_57 ) ;
V_5 = V_7 -> V_5 ;
V_51 = F_17 ( V_7 , V_50 , F_18 ( V_50 ) ) ;
F_3 ( V_10 L_15 ,
V_5 , V_62 , V_51 ) ;
V_2 = F_19 ( & V_41 -> V_7 , sizeof( * V_2 ) , V_63 ) ;
if ( ! V_2 )
return - V_64 ;
V_49 = F_19 ( & V_41 -> V_7 , sizeof( * V_49 ) , V_63 ) ;
if ( ! V_49 )
return - V_64 ;
V_2 -> V_20 = F_20 ( V_7 , V_65 + V_35 ,
V_66 , & V_2 -> V_67 ) ;
if ( ! V_2 -> V_20 )
return - V_64 ;
strcpy ( V_49 -> V_52 , V_10 L_16 ) ;
V_49 -> V_11 = - 1 ;
V_49 -> V_68 = V_62 * 8 ;
V_49 -> V_69 = V_70 ;
V_49 -> V_12 = V_2 ;
V_49 -> V_71 = V_62 ;
V_49 -> V_72 = V_65 + V_73 ;
V_49 -> F_5 = & F_5 ;
V_49 -> F_7 = & F_7 ;
V_49 -> V_74 = V_74 ;
V_49 -> V_75 = & F_10 ;
V_49 -> V_7 = & V_41 -> V_7 ;
V_49 -> V_76 = V_77 ;
V_25 = F_21 ( V_49 ) ;
if ( V_25 < 0 ) {
F_22 ( V_7 , V_65 + V_35 ,
V_2 -> V_20 , V_2 -> V_67 ) ;
return V_25 ;
}
V_49 -> V_11 = V_25 ;
V_2 -> V_4 = V_49 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_26 = V_65 + V_35 ;
V_2 -> V_23 = 1 ;
F_13 ( & V_2 -> V_21 ) ;
if ( V_7 -> V_78 . V_79
&& F_23 ( V_7 , V_7 -> V_78 . V_79 ,
V_16 , sizeof( V_16 ) ) > 0 )
F_24 ( V_52 , V_16 , sizeof( V_52 ) ) ;
if ( V_7 -> V_78 . V_80
&& F_23 ( V_7 , V_7 -> V_78 . V_80 , V_16 , sizeof( V_16 ) ) > 0 )
snprintf ( V_52 + strlen ( V_52 ) , sizeof( V_52 ) - strlen ( V_52 ) ,
L_17 , V_16 ) ;
F_6 ( V_10 L_18 , V_5 , V_52 ,
V_7 -> V_81 -> V_82 , V_5 ) ;
V_25 = F_11 ( V_2 -> V_6 , F_12 ( V_2 -> V_6 , 0 ) ,
V_39 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 < 0 )
F_6 ( V_10 L_19 ,
V_5 , V_25 ) ;
F_25 ( V_41 , V_2 ) ;
return 0 ;
}
static void F_26 ( struct V_40 * V_41 )
{
struct V_44 * V_6 = F_16 ( V_41 ) ;
struct V_1 * V_2 = F_27 ( V_41 ) ;
struct V_83 * V_7 = & V_41 -> V_7 ;
int V_5 ;
F_25 ( V_41 , NULL ) ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_2 -> V_6 = NULL ;
F_22 ( V_6 , V_2 -> V_26 , V_2 -> V_20 , V_2 -> V_67 ) ;
V_5 = F_1 ( V_2 ) ;
F_28 ( V_7 , V_10 L_20 , V_5 , V_8 ) ;
}
