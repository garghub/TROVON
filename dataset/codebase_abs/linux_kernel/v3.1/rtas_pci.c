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
V_10 = F_3 ( V_5 -> V_14 , V_5 -> V_15 , V_3 ) ;
V_9 = V_5 -> V_16 -> V_9 ;
if ( V_9 ) {
V_11 = F_4 ( V_17 , 4 , 2 , & V_8 ,
V_10 , F_5 ( V_9 ) , F_6 ( V_9 ) , V_6 ) ;
} else {
V_11 = F_4 ( V_18 , 2 , 2 , & V_8 , V_10 , V_6 ) ;
}
* V_7 = V_8 ;
if ( V_11 )
return V_12 ;
if ( V_8 == F_7 ( V_6 ) &&
F_8 ( V_5 -> V_19 , NULL ) )
return V_12 ;
return V_20 ;
}
static int F_9 ( struct V_21 * V_22 ,
unsigned int V_15 ,
int V_3 , int V_6 , T_1 * V_7 )
{
struct V_23 * V_24 , * V_2 ;
V_24 = F_10 ( V_22 ) ;
for ( V_2 = V_24 -> V_25 ; V_2 ; V_2 = V_2 -> V_26 ) {
struct V_1 * V_5 = F_11 ( V_2 ) ;
if ( V_5 && V_5 -> V_15 == V_15
&& F_12 ( V_2 ) )
return F_2 ( V_5 , V_3 , V_6 , V_7 ) ;
}
return V_12 ;
}
int F_13 ( struct V_1 * V_5 , int V_3 , int V_6 , T_1 V_7 )
{
unsigned long V_9 , V_10 ;
int V_11 ;
if ( ! V_5 )
return V_12 ;
if ( ! F_1 ( V_5 , V_3 ) )
return V_13 ;
V_10 = F_3 ( V_5 -> V_14 , V_5 -> V_15 , V_3 ) ;
V_9 = V_5 -> V_16 -> V_9 ;
if ( V_9 ) {
V_11 = F_4 ( V_27 , 5 , 1 , NULL , V_10 ,
F_5 ( V_9 ) , F_6 ( V_9 ) , V_6 , ( V_28 ) V_7 ) ;
} else {
V_11 = F_4 ( V_29 , 3 , 1 , NULL , V_10 , V_6 , ( V_28 ) V_7 ) ;
}
if ( V_11 )
return V_12 ;
return V_20 ;
}
static int F_14 ( struct V_21 * V_22 ,
unsigned int V_15 ,
int V_3 , int V_6 , T_1 V_7 )
{
struct V_23 * V_24 , * V_2 ;
V_24 = F_10 ( V_22 ) ;
for ( V_2 = V_24 -> V_25 ; V_2 ; V_2 = V_2 -> V_26 ) {
struct V_1 * V_5 = F_11 ( V_2 ) ;
if ( V_5 && V_5 -> V_15 == V_15
&& F_12 ( V_2 ) )
return F_13 ( V_5 , V_3 , V_6 , V_7 ) ;
}
return V_12 ;
}
static int F_15 ( struct V_23 * V_30 )
{
const char * V_31 = F_16 ( V_30 , L_1 , NULL ) ;
if ( V_31 && strstr ( V_31 , L_2 ) )
return 1 ;
return 0 ;
}
static void F_17 ( struct V_23 * V_30 )
{
struct V_32 V_33 ;
void T_2 * V_34 ;
volatile T_1 V_7 ;
if ( F_18 ( V_30 , 0 , & V_33 ) ) {
F_19 ( V_35 L_3 ) ;
return;
}
V_34 = F_20 ( V_33 . V_36 & ~ ( 0xfffffUL ) , 0x100000 ) ;
#define F_21 0x00010000
V_7 = F_22 ( V_34 + 0xf6030 ) ;
if ( V_7 & F_21 ) {
F_19 ( V_37 L_4 ) ;
V_7 &= ~ F_21 ;
F_23 ( V_34 + 0xf6030 , V_7 ) ;
V_7 = F_22 ( V_34 + 0xf6030 ) ;
F_19 ( L_5 , V_7 ) ;
}
F_24 ( V_34 ) ;
}
void T_3 F_25 ( void )
{
V_18 = F_26 ( L_6 ) ;
V_29 = F_26 ( L_7 ) ;
V_17 = F_26 ( L_8 ) ;
V_27 = F_26 ( L_9 ) ;
}
unsigned long T_4 F_27 ( struct V_23 * V_16 )
{
struct V_32 V_38 ;
if ( V_17 == - 1 )
return 0 ;
if ( F_18 ( V_16 , 0 , & V_38 ) )
return 0 ;
return V_38 . V_36 ;
}
static int F_28 ( struct V_23 * V_30 ,
struct V_39 * V_16 )
{
const int * V_40 ;
unsigned int V_41 ;
V_40 = F_16 ( V_30 , L_10 , & V_41 ) ;
if ( V_40 == NULL || V_41 < 2 * sizeof( int ) ) {
return 1 ;
}
V_16 -> V_42 = V_40 [ 0 ] ;
V_16 -> V_43 = V_40 [ 1 ] ;
return 0 ;
}
int T_4 F_29 ( struct V_39 * V_16 )
{
struct V_23 * V_30 = V_16 -> V_2 ;
if ( F_15 ( V_30 ) )
F_17 ( V_30 ) ;
if ( F_28 ( V_30 , V_16 ) )
return 1 ;
V_16 -> V_44 = & V_45 ;
V_16 -> V_9 = F_27 ( V_30 ) ;
return 0 ;
}
void T_3 F_30 ( void )
{
struct V_23 * V_19 ;
struct V_39 * V_16 ;
struct V_23 * V_46 = F_31 ( L_11 ) ;
F_32 (root, node) {
if ( V_19 -> type == NULL || ( strcmp ( V_19 -> type , L_12 ) != 0 &&
strcmp ( V_19 -> type , L_13 ) != 0 ) )
continue;
V_16 = F_33 ( V_19 ) ;
if ( ! V_16 )
continue;
F_29 ( V_16 ) ;
F_34 ( V_16 , V_19 , 0 ) ;
F_35 ( V_16 ) ;
}
F_36 ( V_46 ) ;
F_37 () ;
if ( V_47 ) {
const int * V_48 ;
V_48 = F_16 ( V_47 ,
L_14 , NULL ) ;
if ( V_48 )
V_49 = * V_48 ;
#ifdef F_38
V_48 = F_16 ( V_47 ,
L_15 , NULL ) ;
if ( V_48 && * V_48 )
F_39 ( V_50 ) ;
#endif
}
}
