static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 ;
if ( ! V_2 ) {
F_2 ( V_6 L_1 ,
V_7 ) ;
return - V_8 ;
}
V_5 = V_2 -> V_5 ;
V_4 = V_2 -> V_4 ;
if ( ! V_4 ) {
F_2 ( V_6 L_2 ,
V_7 ) ;
return - V_8 ;
}
F_3 ( V_9 L_3 , V_5 ) ;
F_4 ( V_4 -> V_10 ) ;
F_5 ( V_4 ) ;
V_2 -> V_4 = NULL ;
F_5 ( V_2 ) ;
return V_5 ;
}
static int F_6 ( void * V_11 )
{
struct V_1 * V_2 = V_11 ;
if ( ! V_2 ) {
F_2 ( V_9 L_4 ) ;
return - V_12 ;
}
F_3 ( V_9 L_5 , V_2 -> V_5 ) ;
if ( ! V_2 -> V_13 )
return - V_14 ;
return 0 ;
}
static void F_7 ( void * V_11 )
{
struct V_1 * V_2 = V_11 ;
if ( ! V_2 ) {
F_2 ( V_9 L_6 ) ;
return;
}
F_3 ( V_9 L_7 , V_2 -> V_5 ) ;
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
static int F_10 ( void * V_11 , struct V_15 * V_16 )
{
int V_25 ;
struct V_1 * V_2 = (struct V_1 * ) V_11 ;
if ( ! V_2 || ! V_2 -> V_13 )
return - V_14 ;
memset ( V_2 -> V_20 , 0 , V_2 -> V_26 ) ;
V_25 = F_11 ( V_2 -> V_13 , F_12 ( V_2 -> V_13 , 0 ) ,
V_27 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 > 0 ) {
int V_19 , V_32 ;
struct V_33 V_34 ;
if ( V_25 < V_35 )
return - V_36 ;
F_3 ( V_9 L_8 ,
V_25 , V_2 -> V_20 [ 0 ] , V_2 -> V_20 [ 1 ] , V_2 -> V_20 [ 2 ] ) ;
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
F_2 (KERN_WARNING DRIVER_NAME
L_9 , ir->devnum) ;
V_2 -> V_20 [ 2 ] %= V_25 - V_35 ;
F_8 ( V_2 , V_16 , V_35 +
V_2 -> V_20 [ 2 ] - ( V_2 -> V_20 [ 2 ] & 1 ) , V_25 ) ;
F_8 ( V_2 , V_16 , V_35 ,
V_35 + V_2 -> V_20 [ 2 ] ) ;
}
V_25 = F_11 (
V_2 -> V_13 , F_12 ( V_2 -> V_13 , 0 ) ,
V_39 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 < 0 )
F_2 ( V_9 L_10
L_11 , V_2 -> V_5 , V_25 ) ;
return 0 ;
} else if ( V_25 < 0 )
F_2 ( V_9 L_12 ,
V_2 -> V_5 , V_25 ) ;
return - V_36 ;
}
static int F_14 ( struct V_40 * V_41 ,
const struct V_42 * V_43 )
{
struct V_44 * V_45 = NULL ;
struct V_46 * V_47 = NULL ;
struct V_48 * V_49 ;
struct V_1 * V_2 = NULL ;
struct V_3 * V_50 = NULL ;
int V_5 , V_51 , V_52 ;
int V_10 = 0 ;
char V_16 [ 63 ] , V_53 [ 128 ] = L_13 ;
int V_54 = 0 ;
int V_25 ;
F_3 ( V_9 L_14 ) ;
V_45 = F_15 ( V_41 ) ;
V_47 = V_41 -> V_55 ;
if ( V_47 -> V_56 . V_57 != 1 )
return - V_14 ;
V_49 = & V_47 -> V_58 -> V_56 ;
if ( ( ( V_49 -> V_59 & V_60 )
!= V_29 )
|| ( V_49 -> V_61 & V_62 )
!= V_63 )
return - V_14 ;
V_51 = F_12 ( V_45 , V_49 -> V_59 ) ;
V_5 = V_45 -> V_5 ;
V_52 = F_16 ( V_45 , V_51 , F_17 ( V_51 ) ) ;
F_3 ( V_9 L_15 ,
V_5 , V_64 , V_52 ) ;
V_54 = 0 ;
V_2 = F_18 ( sizeof( struct V_1 ) , V_65 ) ;
if ( ! V_2 ) {
V_54 = 1 ;
goto V_66;
}
V_50 = F_18 ( sizeof( struct V_3 ) , V_65 ) ;
if ( ! V_50 ) {
V_54 = 2 ;
goto V_66;
}
V_2 -> V_20 = F_19 ( V_45 , V_67 + V_35 ,
V_68 , & V_2 -> V_69 ) ;
if ( ! V_2 -> V_20 ) {
V_54 = 3 ;
goto V_66;
}
strcpy ( V_50 -> V_53 , V_9 L_16 ) ;
V_50 -> V_10 = - 1 ;
V_50 -> V_70 = V_64 * 8 ;
V_50 -> V_71 = V_72 ;
V_50 -> V_11 = V_2 ;
V_50 -> V_73 = V_64 ;
V_50 -> V_74 = V_67 + V_75 ;
V_50 -> F_6 = & F_6 ;
V_50 -> F_7 = & F_7 ;
V_50 -> V_76 = V_76 ;
V_50 -> V_77 = & F_10 ;
V_50 -> V_45 = & V_41 -> V_45 ;
V_50 -> V_78 = V_79 ;
V_10 = F_20 ( V_50 ) ;
if ( V_10 < 0 )
V_54 = 9 ;
V_66:
switch ( V_54 ) {
case 9 :
F_21 ( V_45 , V_67 + V_35 ,
V_2 -> V_20 , V_2 -> V_69 ) ;
case 3 :
F_5 ( V_50 ) ;
case 2 :
F_5 ( V_2 ) ;
case 1 :
F_2 ( V_9 L_17 ,
V_5 , V_54 ) ;
return - V_80 ;
}
V_50 -> V_10 = V_10 ;
V_2 -> V_4 = V_50 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_13 = V_45 ;
V_2 -> V_26 = V_67 + V_35 ;
V_2 -> V_23 = 1 ;
F_13 ( & V_2 -> V_21 ) ;
if ( V_45 -> V_81 . V_82
&& F_22 ( V_45 , V_45 -> V_81 . V_82 ,
V_16 , sizeof( V_16 ) ) > 0 )
F_23 ( V_53 , V_16 , sizeof( V_53 ) ) ;
if ( V_45 -> V_81 . V_83
&& F_22 ( V_45 , V_45 -> V_81 . V_83 , V_16 , sizeof( V_16 ) ) > 0 )
snprintf ( V_53 + strlen ( V_53 ) , sizeof( V_53 ) - strlen ( V_53 ) ,
L_18 , V_16 ) ;
F_2 ( V_9 L_19 , V_5 , V_53 ,
V_45 -> V_84 -> V_85 , V_5 ) ;
V_25 = F_11 ( V_2 -> V_13 , F_12 ( V_2 -> V_13 , 0 ) ,
V_39 , V_28 | V_29 ,
0 , 0 ,
V_2 -> V_20 , V_2 -> V_26 ,
V_30 * V_31 ) ;
if ( V_25 < 0 )
F_2 ( V_9 L_20 ,
V_5 , V_25 ) ;
F_24 ( V_41 , V_2 ) ;
return 0 ;
}
static void F_25 ( struct V_40 * V_41 )
{
struct V_44 * V_13 = F_15 ( V_41 ) ;
struct V_1 * V_2 = F_26 ( V_41 ) ;
struct V_86 * V_45 = & V_41 -> V_45 ;
int V_5 ;
F_24 ( V_41 , NULL ) ;
if ( ! V_2 || ! V_2 -> V_4 )
return;
V_2 -> V_13 = NULL ;
F_21 ( V_13 , V_2 -> V_26 , V_2 -> V_20 , V_2 -> V_69 ) ;
V_5 = F_1 ( V_2 ) ;
F_27 ( V_45 , V_9 L_21 , V_5 , V_7 ) ;
}
