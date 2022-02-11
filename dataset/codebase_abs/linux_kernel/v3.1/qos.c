static inline int F_1 ( T_1 V_1 , T_1 * V_2 , int V_3 )
{
int V_4 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ )
if ( V_2 [ V_4 ] == V_1 )
break;
return V_4 ;
}
static inline T_1 F_2 ( int V_5 , T_1 * V_2 )
{
return V_2 [ V_5 ] ;
}
static int F_3 ( T_2 V_6 )
{
T_2 V_7 = 0x8000 ;
int V_5 = 15 ;
if ( V_6 == 0 ) {
F_4 ( L_1 ,
V_8 ) ;
V_6 = 0x1 ;
}
while ( V_7 ) {
if ( V_6 & V_7 )
break;
V_7 >>= 1 ;
V_5 -- ;
}
return V_5 ;
}
static inline int F_5 ( T_1 V_1 , T_1 * V_2 , int V_3 , T_2 * V_9 )
{
int V_4 ;
T_2 V_10 = 0x1 ;
T_2 V_11 = 0x0 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
V_11 |= V_10 ;
V_10 <<= 1 ;
if ( V_2 [ V_4 ] >= V_1 )
break;
}
if( V_4 >= V_3 )
V_4 = V_3 - 1 ;
* V_9 = V_11 ;
return V_4 ;
}
static inline int F_6 ( T_1 V_1 , T_1 * V_2 , int V_3 , T_2 * V_9 )
{
int V_4 ;
T_2 V_10 = 0x1 ;
T_2 V_11 = 0x0 ;
for ( V_4 = 0 ; V_4 < V_3 ; V_4 ++ ) {
if ( V_2 [ V_4 ] <= V_1 )
break;
V_10 <<= 1 ;
}
V_11 |= V_10 ;
if( V_4 >= V_3 )
V_4 = V_3 - 1 ;
* V_9 = V_11 ;
return V_4 ;
}
void F_7 ( struct V_12 * V_13 , struct V_12 * V_14 )
{
F_8 (qos != NULL, return;) ;
F_8 (new != NULL, return;) ;
V_13 -> V_15 . V_16 &= V_14 -> V_15 . V_16 ;
V_13 -> V_17 . V_16 &= V_14 -> V_17 . V_16 ;
V_13 -> V_18 . V_16 &= V_14 -> V_18 . V_16 ;
V_13 -> V_19 . V_16 &= V_14 -> V_19 . V_16 ;
V_13 -> V_20 . V_16 &= V_14 -> V_20 . V_16 ;
V_13 -> V_21 . V_16 &= V_14 -> V_21 . V_16 ;
V_13 -> V_22 . V_16 &= V_14 -> V_22 . V_16 ;
F_9 ( V_13 ) ;
}
void F_10 ( struct V_12 * V_13 )
{
int V_4 ;
V_4 = F_5 ( V_23 , V_24 , 10 ,
& V_13 -> V_15 . V_16 ) ;
V_23 = F_2 ( V_4 , V_24 ) ;
V_4 = F_5 ( V_25 , V_26 , 8 ,
& V_13 -> V_21 . V_16 ) ;
V_25 = F_2 ( V_4 , V_26 ) ;
V_13 -> V_15 . V_16 &= 0x03ff ;
V_13 -> V_17 . V_16 = 0x7f ;
V_13 -> V_18 . V_16 = 0xff ;
V_13 -> V_19 . V_16 = 0x0f ;
V_13 -> V_20 . V_16 = 0x3f ;
V_13 -> V_21 . V_16 &= 0xff ;
V_13 -> V_22 . V_16 = 0xff ;
}
static void F_11 ( struct V_12 * V_13 )
{
T_1 V_27 ;
int V_5 ;
F_12 ( 2 , L_2 , V_8 ) ;
if ( V_28 > V_13 -> V_18 . V_1 ) {
int V_4 ;
F_4 ( L_3 ,
V_8 , V_28 ) ;
V_4 = F_6 ( V_28 , V_29 ,
8 , & V_13 -> V_18 . V_16 ) ;
V_28 = F_2 ( V_4 , V_29 ) ;
V_13 -> V_18 . V_1 = V_28 ;
}
if ( ( V_13 -> V_15 . V_1 < 115200 ) &&
( V_13 -> V_19 . V_1 < 500 ) )
{
F_12 ( 0 ,
L_4 ,
V_8 , V_13 -> V_19 . V_1 ) ;
V_13 -> V_19 . V_1 = 500 ;
}
V_5 = F_1 ( V_13 -> V_20 . V_1 , V_30 , 6 ) ;
V_27 = F_13 ( V_13 -> V_15 . V_1 ,
V_13 -> V_19 . V_1 ) ;
#ifdef F_14
while ( ( V_13 -> V_20 . V_1 > V_27 ) && ( V_5 > 0 ) ) {
V_13 -> V_20 . V_1 = V_30 [ V_5 -- ] ;
F_12 ( 2 , L_5 ,
V_8 , V_13 -> V_20 . V_1 ) ;
}
#else
while ( F_15 ( V_13 ) > V_27 ) {
F_8 (index != 0 , return;) ;
if ( V_13 -> V_17 . V_1 > 1 ) {
V_13 -> V_17 . V_1 -- ;
F_12 ( 2 , L_6 ,
V_8 , V_13 -> V_17 . V_1 ) ;
} else if ( V_5 > 1 ) {
V_13 -> V_20 . V_1 = V_30 [ V_5 -- ] ;
F_12 ( 2 , L_5 ,
V_8 , V_13 -> V_20 . V_1 ) ;
} else {
F_4 ( L_7 ,
V_8 ) ;
}
}
#endif
if ( V_13 -> V_20 . V_1 > V_31 )
V_13 -> V_20 . V_1 = V_31 ;
if ( V_13 -> V_17 . V_1 > V_32 )
V_13 -> V_17 . V_1 = V_32 ;
}
int F_16 ( struct V_33 * V_34 , struct V_35 * V_36 )
{
int V_37 ;
V_37 = F_17 ( V_34 , V_36 -> V_38 , V_36 -> V_39 ,
& V_40 ) ;
F_9 ( & V_34 -> V_41 ) ;
F_9 ( & V_34 -> V_42 ) ;
F_11 ( & V_34 -> V_41 ) ;
F_12 ( 2 , L_8 ,
V_34 -> V_41 . V_15 . V_1 ) ;
F_12 ( 2 , L_9 ,
V_34 -> V_41 . V_20 . V_1 ) ;
F_12 ( 2 , L_10 ,
V_34 -> V_41 . V_17 . V_1 ) ;
F_12 ( 2 , L_11 ,
V_34 -> V_41 . V_22 . V_1 ) ;
F_12 ( 2 , L_12 ,
V_34 -> V_41 . V_19 . V_1 ) ;
F_12 ( 2 , L_13 ,
V_34 -> V_41 . V_18 . V_1 ) ;
F_12 ( 2 , L_14 ,
V_34 -> V_41 . V_21 . V_1 ) ;
return V_37 ;
}
int F_18 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_37 ;
V_37 = F_19 ( V_34 , V_43 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
V_37 = F_19 ( V_34 , V_44 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
V_37 = F_19 ( V_34 , V_45 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
V_37 = F_19 ( V_34 , V_46 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
V_37 = F_19 ( V_34 , V_47 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
V_37 = F_19 ( V_34 , V_48 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
V_37 = F_19 ( V_34 , V_49 , F_20 ( V_36 ) ,
F_21 ( V_36 ) , & V_40 ) ;
if ( V_37 < 0 )
return V_37 ;
F_22 ( V_36 , V_37 ) ;
return 0 ;
}
static int F_23 ( void * V_50 , T_3 * V_51 , int V_52 )
{
T_2 V_53 ;
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 ) {
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_15 . V_16 ;
F_12 ( 2 , L_15 ,
V_8 , V_51 -> V_54 . V_4 ) ;
} else {
F_12 ( 2 , L_16 , ( T_2 ) V_51 -> V_54 . V_4 ) ;
V_53 = ( T_2 ) V_51 -> V_54 . V_4 & V_34 -> V_42 . V_15 . V_16 ;
F_12 ( 2 , L_17 , V_53 ) ;
V_34 -> V_41 . V_15 . V_16 = V_53 ;
V_34 -> V_42 . V_15 . V_16 = V_53 ;
}
return 0 ;
}
static int F_24 ( void * V_50 , T_3 * V_51 ,
int V_52 )
{
T_2 V_53 ;
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 )
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_21 . V_16 ;
else {
F_12 ( 2 , L_18 , ( V_55 ) V_51 -> V_54 . V_4 ) ;
V_53 = ( V_55 ) V_51 -> V_54 . V_4 & V_34 -> V_42 . V_21 . V_16 ;
F_12 ( 2 , L_19 , V_53 ) ;
V_34 -> V_41 . V_21 . V_16 = V_53 ;
V_34 -> V_42 . V_21 . V_16 = V_53 ;
}
return 0 ;
}
static int F_25 ( void * V_50 , T_3 * V_51 ,
int V_52 )
{
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 )
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_19 . V_16 ;
else
V_34 -> V_41 . V_19 . V_16 = ( V_55 ) V_51 -> V_54 . V_4 ;
return 0 ;
}
static int F_26 ( void * V_50 , T_3 * V_51 , int V_52 )
{
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 )
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_20 . V_16 ;
else
V_34 -> V_41 . V_20 . V_16 = ( V_55 ) V_51 -> V_54 . V_4 ;
return 0 ;
}
static int F_27 ( void * V_50 , T_3 * V_51 ,
int V_52 )
{
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 )
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_17 . V_16 ;
else
V_34 -> V_41 . V_17 . V_16 = ( V_55 ) V_51 -> V_54 . V_4 ;
return 0 ;
}
static int F_28 ( void * V_50 , T_3 * V_51 , int V_52 )
{
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 )
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_22 . V_16 ;
else
V_34 -> V_41 . V_22 . V_16 = ( V_55 ) V_51 -> V_54 . V_4 ;
return 0 ;
}
static int F_29 ( void * V_50 , T_3 * V_51 ,
int V_52 )
{
struct V_33 * V_34 = (struct V_33 * ) V_50 ;
F_8 (self != NULL, return -1;) ;
F_8 (self->magic == LAP_MAGIC, return -1;) ;
if ( V_52 )
V_51 -> V_54 . V_4 = V_34 -> V_42 . V_18 . V_16 ;
else
V_34 -> V_41 . V_18 . V_16 = ( V_55 ) V_51 -> V_54 . V_4 ;
return 0 ;
}
T_1 F_13 ( T_1 V_56 , T_1 V_19 )
{
T_1 V_27 ;
int V_4 , V_57 ;
F_12 ( 2 , L_20 ,
V_8 , V_56 , V_19 ) ;
V_4 = F_1 ( V_56 , V_24 , 10 ) ;
V_57 = F_1 ( V_19 , V_58 , 4 ) ;
F_8 (((i >=0) && (i <10)), return 0;) ;
F_8 (((j >=0) && (j <4)), return 0;) ;
V_27 = V_59 [ V_4 ] [ V_57 ] ;
F_12 ( 2 , L_21 ,
V_8 , V_27 ) ;
return V_27 ;
}
static T_1 F_15 ( struct V_12 * V_13 )
{
T_1 V_27 ;
V_27 = V_13 -> V_17 . V_1 *
( V_13 -> V_20 . V_1 + 6 + V_13 -> V_22 . V_1 ) +
F_30 ( V_13 -> V_15 . V_1 ,
V_13 -> V_18 . V_1 ) ;
F_12 ( 2 , L_22 ,
V_8 , V_27 ) ;
return V_27 ;
}
void F_9 ( struct V_12 * V_13 )
{
int V_5 ;
F_8 (qos != NULL, return;) ;
V_5 = F_3 ( V_13 -> V_15 . V_16 ) ;
V_13 -> V_15 . V_1 = V_24 [ V_5 ] ;
V_5 = F_3 ( V_13 -> V_20 . V_16 ) ;
V_13 -> V_20 . V_1 = V_30 [ V_5 ] ;
V_5 = F_3 ( V_13 -> V_17 . V_16 ) ;
V_13 -> V_17 . V_1 = V_5 + 1 ;
V_5 = F_3 ( V_13 -> V_18 . V_16 ) ;
V_13 -> V_18 . V_1 = V_29 [ V_5 ] ;
V_5 = F_3 ( V_13 -> V_19 . V_16 ) ;
V_13 -> V_19 . V_1 = V_58 [ V_5 ] ;
V_5 = F_3 ( V_13 -> V_21 . V_16 ) ;
V_13 -> V_21 . V_1 = V_26 [ V_5 ] ;
V_5 = F_3 ( V_13 -> V_22 . V_16 ) ;
V_13 -> V_22 . V_1 = V_60 [ V_5 ] ;
}
