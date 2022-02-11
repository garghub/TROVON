static T_1 F_1 ( struct V_1 * V_2 , unsigned long V_3 )
{
T_1 V_4 ;
V_4 . V_5 [ 0 ] = F_2 ( V_2 -> V_6 , F_3 ( V_3 ) ) ;
if ( V_3 & 0x2 )
V_4 . V_5 [ 0 ] >>= 16 ;
else
V_4 . V_5 [ 0 ] &= 0x0000ffff ;
return V_4 ;
}
static void F_4 ( struct V_1 * V_2 , const T_1 V_7 ,
unsigned long V_3 )
{
T_2 V_8 = ( T_2 ) V_7 . V_5 [ 0 ] ;
F_5 ( V_2 -> V_6 , F_3 ( V_3 ) , V_8 ) ;
}
static void F_6 ( struct V_1 * V_2 , void * V_9 ,
unsigned long V_10 , T_3 V_11 )
{
T_4 V_12 = V_10 ;
T_5 * V_13 = V_9 ;
T_4 V_8 ;
while ( V_11 ) {
V_8 = F_2 ( V_2 -> V_6 , F_3 ( V_12 ) ) ;
do {
* V_13 = V_8 >> ( 8 * ( V_12 & 3 ) ) ;
V_12 ++ ;
V_13 ++ ;
V_11 -- ;
} while ( V_11 && ( V_12 % 4 ) );
}
}
static void F_7 ( struct V_1 * V_2 , unsigned long V_9 ,
const void * V_10 , T_3 V_11 )
{
const T_5 * V_12 = V_10 ;
T_4 V_13 = V_9 ;
F_8 ( L_1 , V_14 , V_13 , V_11 ) ;
while ( V_11 ) {
T_2 V_8 = 0xffff ;
do {
V_8 = * V_12 << ( 8 * ( V_13 & 1 ) ) ;
V_12 ++ ;
V_13 ++ ;
V_11 -- ;
} while ( V_11 && ( V_13 % 2 ) );
F_5 ( V_2 -> V_6 , F_3 ( V_13 - 2 ) , V_8 ) ;
}
}
int F_9 ( struct V_15 * V_15 )
{
struct V_1 * V_2 = & V_16 ;
struct V_17 * V_18 ;
F_10 ( ! F_11 ( V_2 -> V_19 ) ) ;
V_2 -> V_6 = V_15 -> V_20 ;
V_2 -> V_21 = F_1 ;
V_2 -> V_22 = F_4 ;
V_2 -> V_23 = F_6 ;
V_2 -> V_24 = F_7 ;
V_18 = F_12 ( L_2 , V_2 ) ;
V_15 -> V_18 = V_18 ;
if ( ! V_18 ) {
F_13 ( L_3 ) ;
return - 1 ;
}
V_18 -> V_25 = V_26 ;
V_18 -> V_27 . V_28 = & V_15 -> V_29 -> V_27 ;
F_14 ( V_18 , NULL , 0 ) ;
return 0 ;
}
void F_15 ( struct V_15 * V_15 )
{
if ( V_15 -> V_18 ) {
F_16 ( V_15 -> V_18 ) ;
F_17 ( V_15 -> V_18 ) ;
}
}
