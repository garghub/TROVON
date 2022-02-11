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
struct V_27 * V_28 , * V_2 ;
struct V_1 * V_5 ;
bool V_29 = false ;
int V_11 ;
* V_7 = 0xFFFFFFFF ;
V_28 = F_9 ( V_26 ) ;
for ( V_2 = V_28 -> V_30 ; V_2 ; V_2 = V_2 -> V_31 ) {
V_5 = F_10 ( V_2 ) ;
if ( V_5 && V_5 -> V_20 == V_20
&& F_11 ( V_2 ) ) {
V_29 = true ;
break;
}
}
if ( ! V_29 )
return V_12 ;
V_11 = F_2 ( V_5 , V_3 , V_6 , V_7 ) ;
if ( * V_7 == F_12 ( V_6 ) &&
F_13 ( F_14 ( V_5 ) ) )
return V_12 ;
return V_11 ;
}
int F_15 ( struct V_1 * V_5 , int V_3 , int V_6 , T_1 V_7 )
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
V_11 = F_5 ( V_32 , 5 , 1 , NULL , V_10 ,
F_6 ( V_9 ) , F_7 ( V_9 ) , V_6 , ( V_33 ) V_7 ) ;
} else {
V_11 = F_5 ( V_34 , 3 , 1 , NULL , V_10 , V_6 , ( V_33 ) V_7 ) ;
}
if ( V_11 )
return V_12 ;
return V_24 ;
}
static int F_16 ( struct V_25 * V_26 ,
unsigned int V_20 ,
int V_3 , int V_6 , T_1 V_7 )
{
struct V_27 * V_28 , * V_2 ;
struct V_1 * V_5 ;
bool V_29 = false ;
V_28 = F_9 ( V_26 ) ;
for ( V_2 = V_28 -> V_30 ; V_2 ; V_2 = V_2 -> V_31 ) {
V_5 = F_10 ( V_2 ) ;
if ( V_5 && V_5 -> V_20 == V_20
&& F_11 ( V_2 ) ) {
V_29 = true ;
break;
}
}
if ( ! V_29 )
return V_12 ;
return F_15 ( V_5 , V_3 , V_6 , V_7 ) ;
}
static int F_17 ( struct V_27 * V_35 )
{
const char * V_36 = F_18 ( V_35 , L_1 , NULL ) ;
if ( V_36 && strstr ( V_36 , L_2 ) )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_27 * V_35 )
{
struct V_37 V_38 ;
void T_2 * V_39 ;
volatile T_1 V_7 ;
if ( F_20 ( V_35 , 0 , & V_38 ) ) {
F_21 ( V_40 L_3 ) ;
return;
}
V_39 = F_22 ( V_38 . V_41 & ~ ( 0xfffffUL ) , 0x100000 ) ;
#define F_23 0x00010000
V_7 = F_24 ( V_39 + 0xf6030 ) ;
if ( V_7 & F_23 ) {
F_21 ( V_42 L_4 ) ;
V_7 &= ~ F_23 ;
F_25 ( V_39 + 0xf6030 , V_7 ) ;
V_7 = F_24 ( V_39 + 0xf6030 ) ;
F_21 ( L_5 , V_7 ) ;
}
F_26 ( V_39 ) ;
}
void T_3 F_27 ( void )
{
V_23 = F_28 ( L_6 ) ;
V_34 = F_28 ( L_7 ) ;
V_22 = F_28 ( L_8 ) ;
V_32 = F_28 ( L_9 ) ;
}
unsigned long F_29 ( struct V_27 * V_21 )
{
struct V_37 V_43 ;
if ( V_22 == - 1 )
return 0 ;
if ( F_20 ( V_21 , 0 , & V_43 ) )
return 0 ;
return V_43 . V_41 ;
}
static int F_30 ( struct V_27 * V_35 ,
struct V_44 * V_21 )
{
const T_4 * V_45 ;
unsigned int V_46 ;
V_45 = F_18 ( V_35 , L_10 , & V_46 ) ;
if ( V_45 == NULL || V_46 < 2 * sizeof( int ) ) {
return 1 ;
}
V_21 -> V_47 = F_31 ( V_45 [ 0 ] ) ;
V_21 -> V_48 = F_31 ( V_45 [ 1 ] ) ;
return 0 ;
}
int F_32 ( struct V_44 * V_21 )
{
struct V_27 * V_35 = V_21 -> V_2 ;
if ( F_17 ( V_35 ) )
F_19 ( V_35 ) ;
if ( F_30 ( V_35 , V_21 ) )
return 1 ;
V_21 -> V_49 = & V_50 ;
V_21 -> V_9 = F_29 ( V_35 ) ;
return 0 ;
}
