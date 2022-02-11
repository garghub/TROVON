static int F_1 ( struct V_1 * V_2 ,
const T_1 * V_3 , unsigned int V_4 )
{
unsigned long V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
int V_8 = F_4 ( V_2 ) ;
T_1 * V_9 = F_5 ( & V_7 -> V_7 [ 0 ] , V_5 + 1 ) ;
int V_10 = 0 ;
T_1 V_11 [ V_8 ] ;
if ( ( V_10 = F_6 ( V_7 -> V_12 , V_3 , V_4 ) ) )
return V_10 ;
F_7 ( V_7 -> V_12 , V_9 , ( T_1 * ) V_13 + V_8 ) ;
F_7 ( V_7 -> V_12 , V_9 + V_8 , ( T_1 * ) V_13 + V_8 * 2 ) ;
F_7 ( V_7 -> V_12 , V_11 , ( T_1 * ) V_13 ) ;
return F_6 ( V_7 -> V_12 , V_11 , V_8 ) ;
}
static int F_8 ( struct V_14 * V_15 )
{
unsigned long V_5 = F_2 ( V_15 -> V_16 ) ;
struct V_17 * V_7 = F_9 ( V_15 ) ;
int V_8 = F_4 ( V_15 -> V_16 ) ;
T_1 * V_18 = F_5 ( & V_7 -> V_7 [ 0 ] , V_5 + 1 ) + V_8 ;
V_7 -> V_19 = 0 ;
memset ( V_18 , 0 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_14 * V_15 , const T_1 * V_20 ,
unsigned int V_19 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_5 = F_2 ( V_2 ) ;
struct V_6 * V_21 = F_3 ( V_2 ) ;
struct V_17 * V_7 = F_9 ( V_15 ) ;
struct V_22 * V_16 = V_21 -> V_12 ;
int V_8 = F_4 ( V_2 ) ;
T_1 * V_23 = F_5 ( & V_7 -> V_7 [ 0 ] , V_5 + 1 ) ;
T_1 * V_18 = V_23 + V_8 ;
if ( ( V_7 -> V_19 + V_19 ) <= V_8 ) {
memcpy ( V_23 + V_7 -> V_19 , V_20 , V_19 ) ;
V_7 -> V_19 += V_19 ;
return 0 ;
}
memcpy ( V_23 + V_7 -> V_19 , V_20 , V_8 - V_7 -> V_19 ) ;
V_19 -= V_8 - V_7 -> V_19 ;
V_20 += V_8 - V_7 -> V_19 ;
F_11 ( V_18 , V_23 , V_8 ) ;
F_7 ( V_16 , V_18 , V_18 ) ;
V_7 -> V_19 = 0 ;
while ( V_19 > V_8 ) {
F_11 ( V_18 , V_20 , V_8 ) ;
F_7 ( V_16 , V_18 , V_18 ) ;
V_20 += V_8 ;
V_19 -= V_8 ;
}
if ( V_19 ) {
memcpy ( V_23 , V_20 , V_19 ) ;
V_7 -> V_19 = V_19 ;
}
return 0 ;
}
static int F_12 ( struct V_14 * V_15 , T_1 * V_24 )
{
struct V_1 * V_2 = V_15 -> V_16 ;
unsigned long V_5 = F_2 ( V_2 ) ;
struct V_6 * V_21 = F_3 ( V_2 ) ;
struct V_17 * V_7 = F_9 ( V_15 ) ;
struct V_22 * V_16 = V_21 -> V_12 ;
int V_8 = F_4 ( V_2 ) ;
T_1 * V_9 = F_5 ( & V_21 -> V_7 [ 0 ] , V_5 + 1 ) ;
T_1 * V_23 = F_5 ( & V_7 -> V_7 [ 0 ] , V_5 + 1 ) ;
T_1 * V_18 = V_23 + V_8 ;
unsigned int V_25 = 0 ;
if ( V_7 -> V_19 != V_8 ) {
unsigned int V_26 ;
T_1 * V_20 = V_23 + V_7 -> V_19 ;
* V_20 = 0x80 ;
V_20 ++ ;
V_26 = V_8 - V_7 -> V_19 - 1 ;
if ( V_26 )
memset ( V_20 , 0 , V_26 ) ;
V_25 += V_8 ;
}
F_11 ( V_18 , V_23 , V_8 ) ;
F_11 ( V_18 , V_9 + V_25 , V_8 ) ;
F_7 ( V_16 , V_24 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_27 * V_16 )
{
struct V_22 * V_28 ;
struct V_29 * V_30 = ( void * ) V_16 -> V_31 ;
struct V_32 * V_33 = F_14 ( V_30 ) ;
struct V_6 * V_7 = F_15 ( V_16 ) ;
V_28 = F_16 ( V_33 ) ;
if ( F_17 ( V_28 ) )
return F_18 ( V_28 ) ;
V_7 -> V_12 = V_28 ;
return 0 ;
}
static void F_19 ( struct V_27 * V_16 )
{
struct V_6 * V_7 = F_15 ( V_16 ) ;
F_20 ( V_7 -> V_12 ) ;
}
static int F_21 ( struct V_34 * V_35 , struct V_36 * * V_37 )
{
struct V_38 * V_30 ;
struct V_39 * V_40 ;
unsigned long V_5 ;
int V_10 ;
V_10 = F_22 ( V_37 , V_41 ) ;
if ( V_10 )
return V_10 ;
V_40 = F_23 ( V_37 , V_42 ,
V_43 ) ;
if ( F_17 ( V_40 ) )
return F_18 ( V_40 ) ;
switch( V_40 -> V_44 ) {
case 16 :
break;
default:
goto V_45;
}
V_30 = F_24 ( L_1 , V_40 ) ;
V_10 = F_18 ( V_30 ) ;
if ( F_17 ( V_30 ) )
goto V_45;
V_10 = F_25 ( F_26 ( V_30 ) , V_40 ,
F_27 ( V_30 ) ,
V_43 ) ;
if ( V_10 )
goto V_46;
V_5 = V_40 -> V_47 | 3 ;
V_30 -> V_40 . V_48 . V_47 = V_5 ;
V_30 -> V_40 . V_48 . V_49 = V_40 -> V_49 ;
V_30 -> V_40 . V_48 . V_44 = V_40 -> V_44 ;
V_30 -> V_40 . V_50 = V_40 -> V_44 ;
V_30 -> V_40 . V_51 = F_28 ( sizeof( struct V_17 ) ,
F_29 () ) +
( V_5 &
~ ( F_29 () - 1 ) ) +
V_40 -> V_44 * 2 ;
V_30 -> V_40 . V_48 . V_52 = F_28 ( sizeof( struct V_6 ) ,
V_5 + 1 ) +
V_40 -> V_44 * 2 ;
V_30 -> V_40 . V_48 . V_53 = F_13 ;
V_30 -> V_40 . V_48 . V_54 = F_19 ;
V_30 -> V_40 . V_55 = F_8 ;
V_30 -> V_40 . V_56 = F_10 ;
V_30 -> V_40 . V_57 = F_12 ;
V_30 -> V_40 . V_58 = F_1 ;
V_10 = F_30 ( V_35 , V_30 ) ;
if ( V_10 ) {
V_46:
F_31 ( F_27 ( V_30 ) ) ;
}
V_45:
F_32 ( V_40 ) ;
return V_10 ;
}
static int T_2 F_33 ( void )
{
return F_34 ( & V_59 ) ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_59 ) ;
}
