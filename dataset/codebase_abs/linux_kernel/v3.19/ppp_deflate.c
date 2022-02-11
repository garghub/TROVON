static void F_1 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 ) {
F_2 ( & V_3 -> V_4 ) ;
F_3 ( V_3 -> V_4 . V_5 ) ;
F_4 ( V_3 ) ;
}
}
static void * F_5 ( unsigned char * V_6 , int V_7 )
{
struct V_2 * V_3 ;
int V_8 ;
if ( V_7 != V_9 ||
( V_6 [ 0 ] != V_10 && V_6 [ 0 ] != V_11 ) ||
V_6 [ 1 ] != V_9 ||
F_6 ( V_6 [ 2 ] ) != V_12 ||
V_6 [ 3 ] != V_13 )
return NULL ;
V_8 = F_7 ( V_6 [ 2 ] ) ;
if ( V_8 < V_14 || V_8 > V_15 )
return NULL ;
V_3 = F_8 ( sizeof( * V_3 ) ,
V_16 ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_4 . V_17 = NULL ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_5 = F_9 ( F_10 ( - V_8 , 8 ) ) ;
if ( V_3 -> V_4 . V_5 == NULL )
goto V_18;
if ( F_11 ( & V_3 -> V_4 , V_19 ,
V_12 , - V_8 , 8 , V_20 )
!= V_21 )
goto V_18;
return ( void * ) V_3 ;
V_18:
F_1 ( V_3 ) ;
return NULL ;
}
static int F_12 ( void * V_1 , unsigned char * V_6 , int V_7 ,
int V_22 , int V_23 , int V_24 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_7 < V_9 ||
( V_6 [ 0 ] != V_10 && V_6 [ 0 ] != V_11 ) ||
V_6 [ 1 ] != V_9 ||
F_6 ( V_6 [ 2 ] ) != V_12 ||
F_7 ( V_6 [ 2 ] ) != V_3 -> V_8 ||
V_6 [ 3 ] != V_13 )
return 0 ;
V_3 -> V_25 = 0 ;
V_3 -> V_22 = V_22 ;
V_3 -> V_24 = V_24 ;
F_13 ( & V_3 -> V_4 ) ;
return 1 ;
}
static void F_14 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_25 = 0 ;
F_13 ( & V_3 -> V_4 ) ;
}
static int F_15 ( void * V_1 , unsigned char * V_26 , unsigned char * V_27 ,
int V_28 , int V_29 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_30 , V_31 , V_32 , V_33 , V_34 ;
unsigned char * V_35 ;
V_31 = F_16 ( V_26 ) ;
if ( V_31 > 0x3fff || V_31 == 0xfd || V_31 == 0xfb )
return 0 ;
if ( V_29 > V_28 )
V_29 = V_28 ;
V_35 = V_27 ;
V_35 [ 0 ] = F_17 ( V_26 ) ;
V_35 [ 1 ] = F_18 ( V_26 ) ;
F_19 ( V_36 , V_35 + 2 ) ;
V_35 += V_37 ;
F_19 ( V_3 -> V_25 , V_35 ) ;
V_35 += V_38 ;
V_33 = V_37 + V_38 ;
V_3 -> V_4 . V_39 = V_35 ;
V_3 -> V_4 . V_40 = V_34 = V_29 - V_33 ;
++ V_3 -> V_25 ;
V_32 = ( V_31 > 0xff ) ? 2 : 3 ;
V_26 += V_32 ;
V_3 -> V_4 . V_17 = V_26 ;
V_3 -> V_4 . V_41 = ( V_28 - V_32 ) ;
for (; ; ) {
V_30 = F_20 ( & V_3 -> V_4 , V_42 ) ;
if ( V_30 != V_21 ) {
if ( V_3 -> V_24 )
F_21 ( V_43
L_1 , V_30 ) ;
break;
}
if ( V_3 -> V_4 . V_40 == 0 ) {
V_33 += V_34 ;
V_3 -> V_4 . V_39 = NULL ;
V_3 -> V_4 . V_40 = V_34 = 1000000 ;
} else {
break;
}
}
V_33 += V_34 - V_3 -> V_4 . V_40 ;
if ( V_33 < V_28 && V_33 <= V_29 ) {
V_3 -> V_44 . V_45 += V_33 ;
V_3 -> V_44 . V_46 ++ ;
} else {
V_3 -> V_44 . V_47 += V_28 ;
V_3 -> V_44 . V_48 ++ ;
V_33 = 0 ;
}
V_3 -> V_44 . V_49 += V_28 ;
V_3 -> V_44 . V_50 ++ ;
return V_33 ;
}
static void F_22 ( void * V_1 , struct V_51 * V_44 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
* V_44 = V_3 -> V_44 ;
}
static void F_23 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_3 ) {
F_24 ( & V_3 -> V_4 ) ;
F_3 ( V_3 -> V_4 . V_5 ) ;
F_4 ( V_3 ) ;
}
}
static void * F_25 ( unsigned char * V_6 , int V_7 )
{
struct V_2 * V_3 ;
int V_8 ;
if ( V_7 != V_9 ||
( V_6 [ 0 ] != V_10 && V_6 [ 0 ] != V_11 ) ||
V_6 [ 1 ] != V_9 ||
F_6 ( V_6 [ 2 ] ) != V_12 ||
V_6 [ 3 ] != V_13 )
return NULL ;
V_8 = F_7 ( V_6 [ 2 ] ) ;
if ( V_8 < V_14 || V_8 > V_15 )
return NULL ;
V_3 = F_8 ( sizeof( * V_3 ) , V_16 ) ;
if ( V_3 == NULL )
return NULL ;
V_3 -> V_8 = V_8 ;
V_3 -> V_4 . V_39 = NULL ;
V_3 -> V_4 . V_5 = F_9 ( F_26 () ) ;
if ( V_3 -> V_4 . V_5 == NULL )
goto V_18;
if ( F_27 ( & V_3 -> V_4 , - V_8 ) != V_21 )
goto V_18;
return ( void * ) V_3 ;
V_18:
F_23 ( V_3 ) ;
return NULL ;
}
static int F_28 ( void * V_1 , unsigned char * V_6 , int V_7 ,
int V_22 , int V_23 , int V_52 , int V_24 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
if ( V_7 < V_9 ||
( V_6 [ 0 ] != V_10 && V_6 [ 0 ] != V_11 ) ||
V_6 [ 1 ] != V_9 ||
F_6 ( V_6 [ 2 ] ) != V_12 ||
F_7 ( V_6 [ 2 ] ) != V_3 -> V_8 ||
V_6 [ 3 ] != V_13 )
return 0 ;
V_3 -> V_25 = 0 ;
V_3 -> V_22 = V_22 ;
V_3 -> V_24 = V_24 ;
V_3 -> V_52 = V_52 ;
F_29 ( & V_3 -> V_4 ) ;
return 1 ;
}
static void F_30 ( void * V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_25 = 0 ;
F_29 ( & V_3 -> V_4 ) ;
}
static int F_31 ( void * V_1 , unsigned char * V_53 , int V_28 ,
unsigned char * V_27 , int V_29 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_33 , V_54 , V_30 ;
int V_55 , V_56 ;
unsigned char V_57 [ 1 ] ;
if ( V_28 <= V_37 + V_38 ) {
if ( V_3 -> V_24 )
F_21 ( V_58 L_2 ,
V_3 -> V_22 , V_28 ) ;
return V_59 ;
}
V_54 = F_32 ( V_53 + V_37 ) ;
if ( V_54 != ( V_3 -> V_25 & 0xffff ) ) {
if ( V_3 -> V_24 )
F_21 ( V_58 L_3 ,
V_3 -> V_22 , V_54 , V_3 -> V_25 & 0xffff ) ;
return V_59 ;
}
++ V_3 -> V_25 ;
V_27 [ 0 ] = F_17 ( V_53 ) ;
V_27 [ 1 ] = F_18 ( V_53 ) ;
V_27 [ 2 ] = 0 ;
V_3 -> V_4 . V_17 = V_53 + V_37 + V_38 ;
V_3 -> V_4 . V_41 = V_28 - ( V_37 + V_38 ) ;
V_3 -> V_4 . V_39 = V_27 + 3 ;
V_3 -> V_4 . V_40 = 1 ;
V_55 = 1 ;
V_56 = 0 ;
for (; ; ) {
V_30 = F_33 ( & V_3 -> V_4 , V_42 ) ;
if ( V_30 != V_21 ) {
if ( V_3 -> V_24 )
F_21 ( V_58 L_4 ,
V_3 -> V_22 , V_30 , ( V_3 -> V_4 . V_60 ? V_3 -> V_4 . V_60 : L_5 ) ) ;
return V_61 ;
}
if ( V_3 -> V_4 . V_40 != 0 )
break;
if ( V_55 ) {
V_3 -> V_4 . V_40 = V_29 - V_37 ;
if ( ( V_27 [ 3 ] & 1 ) == 0 ) {
V_27 [ 2 ] = V_27 [ 3 ] ;
-- V_3 -> V_4 . V_39 ;
++ V_3 -> V_4 . V_40 ;
}
V_55 = 0 ;
} else if ( ! V_56 ) {
V_3 -> V_4 . V_39 = V_57 ;
V_3 -> V_4 . V_40 = 1 ;
V_56 = 1 ;
} else {
if ( V_3 -> V_24 )
F_21 ( V_58 L_6 ,
V_3 -> V_22 ) ;
return V_61 ;
}
}
if ( V_55 ) {
if ( V_3 -> V_24 )
F_21 ( V_58 L_7 ,
V_3 -> V_22 ) ;
return V_59 ;
}
V_33 = V_29 + V_56 - V_3 -> V_4 . V_40 ;
V_3 -> V_44 . V_49 += V_33 ;
V_3 -> V_44 . V_50 ++ ;
V_3 -> V_44 . V_45 += V_28 ;
V_3 -> V_44 . V_46 ++ ;
return V_33 ;
}
static void F_34 ( void * V_1 , unsigned char * V_53 , int V_62 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
int V_31 , V_30 ;
V_31 = F_16 ( V_53 ) ;
if ( V_31 > 0x3fff || V_31 == 0xfd || V_31 == 0xfb )
return;
++ V_3 -> V_25 ;
V_3 -> V_4 . V_17 = V_53 + 3 ;
V_3 -> V_4 . V_41 = V_62 - 3 ;
if ( V_31 > 0xff ) {
-- V_3 -> V_4 . V_17 ;
++ V_3 -> V_4 . V_41 ;
}
V_30 = F_35 ( & V_3 -> V_4 ) ;
if ( V_30 != V_21 ) {
if ( V_3 -> V_24 ) {
F_21 ( V_58 L_8 ,
V_3 -> V_22 , V_30 , ( V_3 -> V_4 . V_60 ? V_3 -> V_4 . V_60 : L_5 ) ) ;
}
return;
}
V_3 -> V_44 . V_47 += V_62 ;
V_3 -> V_44 . V_48 ++ ;
V_3 -> V_44 . V_49 += V_62 ;
V_3 -> V_44 . V_50 ++ ;
}
static int T_1 F_36 ( void )
{
int V_63 = F_37 ( & V_64 ) ;
if ( V_63 == 0 )
F_21 ( V_65
L_9 ) ;
F_37 ( & V_66 ) ;
return V_63 ;
}
static void T_2 F_38 ( void )
{
F_39 ( & V_64 ) ;
F_39 ( & V_66 ) ;
}
