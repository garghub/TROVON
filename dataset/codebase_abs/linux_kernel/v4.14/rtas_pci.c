static inline int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 < 256 )
return 1 ;
if ( V_3 < 4096 && V_2 -> V_4 )
return 1 ;
return 0 ;
}
int F_2 ( struct V_1 * V_5 , int V_3 , int V_6 , T_1 * V_7 )
{
int V_8 = - 1 ;
unsigned long V_9 , V_10 ;
int V_11 ;
if ( ! V_5 )
return V_12 ;
if ( ! F_1 ( V_5 , V_3 ) )
return V_13 ;
#ifdef F_3
if ( V_5 -> V_14 && V_5 -> V_14 -> V_15 &&
( V_5 -> V_14 -> V_15 -> V_16 & V_17 ) )
return V_18 ;
#endif
V_10 = F_4 ( V_5 -> V_19 , V_5 -> V_20 , V_3 ) ;
V_9 = V_5 -> V_21 -> V_9 ;
if ( V_9 ) {
V_11 = F_5 ( V_22 , 4 , 2 , & V_8 ,
V_10 , F_6 ( V_9 ) , F_7 ( V_9 ) , V_6 ) ;
} else {
V_11 = F_5 ( V_23 , 2 , 2 , & V_8 , V_10 , V_6 ) ;
}
* V_7 = V_8 ;
if ( V_11 )
return V_12 ;
return V_24 ;
}
static int F_8 ( struct V_25 * V_26 ,
unsigned int V_20 ,
int V_3 , int V_6 , T_1 * V_7 )
{
struct V_1 * V_5 ;
int V_11 ;
* V_7 = 0xFFFFFFFF ;
V_5 = F_9 ( V_26 , V_20 ) ;
V_11 = F_2 ( V_5 , V_3 , V_6 , V_7 ) ;
if ( * V_7 == F_10 ( V_6 ) &&
F_11 ( F_12 ( V_5 ) ) )
return V_12 ;
return V_11 ;
}
int F_13 ( struct V_1 * V_5 , int V_3 , int V_6 , T_1 V_7 )
{
unsigned long V_9 , V_10 ;
int V_11 ;
if ( ! V_5 )
return V_12 ;
if ( ! F_1 ( V_5 , V_3 ) )
return V_13 ;
#ifdef F_3
if ( V_5 -> V_14 && V_5 -> V_14 -> V_15 &&
( V_5 -> V_14 -> V_15 -> V_16 & V_17 ) )
return V_18 ;
#endif
V_10 = F_4 ( V_5 -> V_19 , V_5 -> V_20 , V_3 ) ;
V_9 = V_5 -> V_21 -> V_9 ;
if ( V_9 ) {
V_11 = F_5 ( V_27 , 5 , 1 , NULL , V_10 ,
F_6 ( V_9 ) , F_7 ( V_9 ) , V_6 , ( V_28 ) V_7 ) ;
} else {
V_11 = F_5 ( V_29 , 3 , 1 , NULL , V_10 , V_6 , ( V_28 ) V_7 ) ;
}
if ( V_11 )
return V_12 ;
return V_24 ;
}
static int F_14 ( struct V_25 * V_26 ,
unsigned int V_20 ,
int V_3 , int V_6 , T_1 V_7 )
{
struct V_1 * V_5 ;
V_5 = F_9 ( V_26 , V_20 ) ;
return F_13 ( V_5 , V_3 , V_6 , V_7 ) ;
}
static int F_15 ( struct V_30 * V_31 )
{
const char * V_32 = F_16 ( V_31 , L_1 , NULL ) ;
if ( V_32 && strstr ( V_32 , L_2 ) )
return 1 ;
return 0 ;
}
static void F_17 ( struct V_30 * V_31 )
{
struct V_33 V_34 ;
void T_2 * V_35 ;
volatile T_1 V_7 ;
if ( F_18 ( V_31 , 0 , & V_34 ) ) {
F_19 ( V_36 L_3 ) ;
return;
}
V_35 = F_20 ( V_34 . V_37 & ~ ( 0xfffffUL ) , 0x100000 ) ;
#define F_21 0x00010000
V_7 = F_22 ( V_35 + 0xf6030 ) ;
if ( V_7 & F_21 ) {
F_19 ( V_38 L_4 ) ;
V_7 &= ~ F_21 ;
F_23 ( V_35 + 0xf6030 , V_7 ) ;
V_7 = F_22 ( V_35 + 0xf6030 ) ;
F_19 ( L_5 , V_7 ) ;
}
F_24 ( V_35 ) ;
}
void T_3 F_25 ( void )
{
V_23 = F_26 ( L_6 ) ;
V_29 = F_26 ( L_7 ) ;
V_22 = F_26 ( L_8 ) ;
V_27 = F_26 ( L_9 ) ;
}
unsigned long F_27 ( struct V_30 * V_21 )
{
struct V_33 V_39 ;
if ( V_22 == - 1 )
return 0 ;
if ( F_18 ( V_21 , 0 , & V_39 ) )
return 0 ;
return V_39 . V_37 ;
}
static int F_28 ( struct V_30 * V_31 ,
struct V_40 * V_21 )
{
const T_4 * V_41 ;
unsigned int V_42 ;
V_41 = F_16 ( V_31 , L_10 , & V_42 ) ;
if ( V_41 == NULL || V_42 < 2 * sizeof( int ) ) {
return 1 ;
}
V_21 -> V_43 = F_29 ( V_41 [ 0 ] ) ;
V_21 -> V_44 = F_29 ( V_41 [ 1 ] ) ;
return 0 ;
}
int F_30 ( struct V_40 * V_21 )
{
struct V_30 * V_31 = V_21 -> V_2 ;
if ( F_15 ( V_31 ) )
F_17 ( V_31 ) ;
if ( F_28 ( V_31 , V_21 ) )
return 1 ;
V_21 -> V_45 = & V_46 ;
V_21 -> V_9 = F_27 ( V_31 ) ;
return 0 ;
}
