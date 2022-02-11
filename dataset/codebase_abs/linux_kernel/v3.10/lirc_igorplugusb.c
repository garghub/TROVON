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
F_5 ( V_4 ) ;
V_2 -> V_4 = NULL ;
F_5 ( V_2 ) ;
return V_5 ;
}
static int F_6 ( void * V_12 )
{
struct V_1 * V_2 = V_12 ;
if ( ! V_2 ) {
F_7 ( V_10 L_4 ) ;
return - V_13 ;
}
F_3 ( V_10 L_5 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_6 )
return - V_14 ;
return 0 ;
}
static void F_8 ( void * V_12 )
{
struct V_1 * V_2 = V_12 ;
if ( ! V_2 ) {
F_7 ( V_10 L_6 ) ;
return;
}
F_3 ( V_10 L_7 , V_2 -> V_5 ) ;
}
static void F_9 ( struct V_1 * V_2 , struct V_15 * V_16 ,
int V_17 , int V_18 )
{
int V_19 ;
while ( V_17 < V_18 ) {
V_19 = ( unsigned int ) V_2 -> V_20 [ V_17 ] * 85 +
( unsigned int ) V_2 -> V_20 [ V_17 ] / 3 ;
V_2 -> V_21 . V_22 += V_19 ;
if ( V_2 -> V_23 )
V_19 |= V_24 ;
F_10 ( V_16 , ( unsigned char * ) & V_19 ) ;
V_2 -> V_23 ^= 1 ;
++ V_17 ;
}
}
static int F_11 ( void * V_12 , struct V_15 * V_16 )
{
int V_25 ;
struct V_1 * V_2 = (struct V_1 * ) V_12 ;
if ( ! V_2 || ! V_2 -> V_6 )
return - V_14 ;
memset ( V_2 -> V_20 , 0 , V_2 -> V_26 ) ;
V_25 = F_12 ( V_2 -> V_6 , F_13 ( V_2 -> V_6 , 0 ) ,
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
F_14 ( & V_34 ) ;
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
F_10 ( V_16 , ( unsigned char * ) & V_19 ) ;
V_2 -> V_23 = 1 ;
if ( V_2 -> V_20 [ 2 ] == 0 )
F_9 ( V_2 , V_16 , V_35 , V_25 ) ;
else {
F_15 ( & V_2 -> V_6 -> V_7 ,
L_9 , V_2 -> V_5 ) ;
V_2 -> V_20 [ 2 ] %= V_25 - V_35 ;
F_9 ( V_2 , V_16 , V_35 +
V_2 -> V_20 [ 2 ] - ( V_2 -> V_20 [ 2 ] & 1 ) , V_25 ) ;
F_9 ( V_2 , V_16 , V_35 ,
V_35 + V_2 -> V_20 [ 2 ] ) ;
}
V_25 = F_12 (
V_2 -> V_6 , F_13 ( V_2 -> V_6 , 0 ) ,
V_39 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 < 0 )
F_7 ( V_10 L_10
L_11 , V_2 -> V_5 , V_25 ) ;
return 0 ;
} else if ( V_25 < 0 )
F_7 ( V_10 L_12 ,
V_2 -> V_5 , V_25 ) ;
return - V_36 ;
}
static int F_16 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_44 * V_7 = NULL ;
struct V_45 * V_46 = NULL ;
struct V_47 * V_48 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_49 = NULL ;
int V_5 , V_50 , V_51 ;
int V_11 = 0 ;
char V_16 [ 63 ] , V_52 [ 128 ] = L_13 ;
int V_53 = 0 ;
int V_25 ;
F_3 ( V_10 L_14 ) ;
V_7 = F_17 ( V_41 ) ;
V_46 = V_41 -> V_54 ;
if ( V_46 -> V_55 . V_56 != 1 )
return - V_14 ;
V_48 = & V_46 -> V_57 -> V_55 ;
if ( ( ( V_48 -> V_58 & V_59 )
!= V_29 )
|| ( V_48 -> V_60 & V_61 )
!= V_62 )
return - V_14 ;
V_50 = F_13 ( V_7 , V_48 -> V_58 ) ;
V_5 = V_7 -> V_5 ;
V_51 = F_18 ( V_7 , V_50 , F_19 ( V_50 ) ) ;
F_3 ( V_10 L_15 ,
V_5 , V_63 , V_51 ) ;
V_53 = 0 ;
V_2 = F_20 ( sizeof( struct V_1 ) , V_64 ) ;
if ( ! V_2 ) {
V_53 = 1 ;
goto V_65;
}
V_49 = F_20 ( sizeof( struct V_3 ) , V_64 ) ;
if ( ! V_49 ) {
V_53 = 2 ;
goto V_65;
}
V_2 -> V_20 = F_21 ( V_7 , V_66 + V_35 ,
V_67 , & V_2 -> V_68 ) ;
if ( ! V_2 -> V_20 ) {
V_53 = 3 ;
goto V_65;
}
strcpy ( V_49 -> V_52 , V_10 L_16 ) ;
V_49 -> V_11 = - 1 ;
V_49 -> V_69 = V_63 * 8 ;
V_49 -> V_70 = V_71 ;
V_49 -> V_12 = V_2 ;
V_49 -> V_72 = V_63 ;
V_49 -> V_73 = V_66 + V_74 ;
V_49 -> F_6 = & F_6 ;
V_49 -> F_8 = & F_8 ;
V_49 -> V_75 = V_75 ;
V_49 -> V_76 = & F_11 ;
V_49 -> V_7 = & V_41 -> V_7 ;
V_49 -> V_77 = V_78 ;
V_11 = F_22 ( V_49 ) ;
if ( V_11 < 0 )
V_53 = 9 ;
V_65:
switch ( V_53 ) {
case 9 :
F_23 ( V_7 , V_66 + V_35 ,
V_2 -> V_20 , V_2 -> V_68 ) ;
case 3 :
F_5 ( V_49 ) ;
case 2 :
F_5 ( V_2 ) ;
case 1 :
F_7 ( V_10 L_17 ,
V_5 , V_53 ) ;
return - V_79 ;
}
V_49 -> V_11 = V_11 ;
V_2 -> V_4 = V_49 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_6 = V_7 ;
V_2 -> V_26 = V_66 + V_35 ;
V_2 -> V_23 = 1 ;
F_14 ( & V_2 -> V_21 ) ;
if ( V_7 -> V_80 . V_81
&& F_24 ( V_7 , V_7 -> V_80 . V_81 ,
V_16 , sizeof( V_16 ) ) > 0 )
F_25 ( V_52 , V_16 , sizeof( V_52 ) ) ;
if ( V_7 -> V_80 . V_82
&& F_24 ( V_7 , V_7 -> V_80 . V_82 , V_16 , sizeof( V_16 ) ) > 0 )
snprintf ( V_52 + strlen ( V_52 ) , sizeof( V_52 ) - strlen ( V_52 ) ,
L_18 , V_16 ) ;
F_7 ( V_10 L_19 , V_5 , V_52 ,
V_7 -> V_83 -> V_84 , V_5 ) ;
V_25 = F_12 ( V_2 -> V_6 , F_13 ( V_2 -> V_6 , 0 ) ,
V_39 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 < 0 )
F_7 ( V_10 L_20 ,
V_5 , V_25 ) ;
F_26 ( V_41 , V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_40 * V_41 )
{
struct V_44 * V_6 = F_17 ( V_41 ) ;
struct V_1 * V_2 = F_28 ( V_41 ) ;
struct V_85 * V_7 = & V_41 -> V_7 ;
int V_5 ;
F_26 ( V_41 , NULL ) ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_2 -> V_6 = NULL ;
F_23 ( V_6 , V_2 -> V_26 , V_2 -> V_20 , V_2 -> V_68 ) ;
V_5 = F_1 ( V_2 ) ;
F_29 ( V_7 , V_10 L_21 , V_5 , V_8 ) ;
}
