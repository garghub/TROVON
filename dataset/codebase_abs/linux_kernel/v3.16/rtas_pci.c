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
return V_19 ;
}
static int F_7 ( struct V_20 * V_21 ,
unsigned int V_15 ,
int V_3 , int V_6 , T_1 * V_7 )
{
struct V_22 * V_23 , * V_2 ;
struct V_1 * V_5 ;
bool V_24 = false ;
#ifdef F_8
struct V_25 * V_26 ;
#endif
int V_11 ;
* V_7 = 0xFFFFFFFF ;
V_23 = F_9 ( V_21 ) ;
for ( V_2 = V_23 -> V_27 ; V_2 ; V_2 = V_2 -> V_28 ) {
V_5 = F_10 ( V_2 ) ;
if ( V_5 && V_5 -> V_15 == V_15
&& F_11 ( V_2 ) ) {
V_24 = true ;
break;
}
}
if ( ! V_24 )
return V_12 ;
#ifdef F_8
V_26 = F_12 ( V_2 ) ;
if ( V_26 && V_26 -> V_29 && V_26 -> V_29 -> V_30 & V_31 )
return V_12 ;
#endif
V_11 = F_2 ( V_5 , V_3 , V_6 , V_7 ) ;
if ( * V_7 == F_13 ( V_6 ) &&
F_14 ( F_12 ( V_2 ) ) )
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
V_10 = F_3 ( V_5 -> V_14 , V_5 -> V_15 , V_3 ) ;
V_9 = V_5 -> V_16 -> V_9 ;
if ( V_9 ) {
V_11 = F_4 ( V_32 , 5 , 1 , NULL , V_10 ,
F_5 ( V_9 ) , F_6 ( V_9 ) , V_6 , ( V_33 ) V_7 ) ;
} else {
V_11 = F_4 ( V_34 , 3 , 1 , NULL , V_10 , V_6 , ( V_33 ) V_7 ) ;
}
if ( V_11 )
return V_12 ;
return V_19 ;
}
static int F_16 ( struct V_20 * V_21 ,
unsigned int V_15 ,
int V_3 , int V_6 , T_1 V_7 )
{
struct V_22 * V_23 , * V_2 ;
struct V_1 * V_5 ;
bool V_24 = false ;
#ifdef F_8
struct V_25 * V_26 ;
#endif
int V_11 ;
V_23 = F_9 ( V_21 ) ;
for ( V_2 = V_23 -> V_27 ; V_2 ; V_2 = V_2 -> V_28 ) {
V_5 = F_10 ( V_2 ) ;
if ( V_5 && V_5 -> V_15 == V_15
&& F_11 ( V_2 ) ) {
V_24 = true ;
break;
}
}
if ( ! V_24 )
return V_12 ;
#ifdef F_8
V_26 = F_12 ( V_2 ) ;
if ( V_26 && V_26 -> V_29 && ( V_26 -> V_29 -> V_30 & V_31 ) )
return V_12 ;
#endif
V_11 = F_15 ( V_5 , V_3 , V_6 , V_7 ) ;
return V_11 ;
}
static int F_17 ( struct V_22 * V_35 )
{
const char * V_36 = F_18 ( V_35 , L_1 , NULL ) ;
if ( V_36 && strstr ( V_36 , L_2 ) )
return 1 ;
return 0 ;
}
static void F_19 ( struct V_22 * V_35 )
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
V_18 = F_28 ( L_6 ) ;
V_34 = F_28 ( L_7 ) ;
V_17 = F_28 ( L_8 ) ;
V_32 = F_28 ( L_9 ) ;
}
unsigned long F_29 ( struct V_22 * V_16 )
{
struct V_37 V_43 ;
if ( V_17 == - 1 )
return 0 ;
if ( F_20 ( V_16 , 0 , & V_43 ) )
return 0 ;
return V_43 . V_41 ;
}
static int F_30 ( struct V_22 * V_35 ,
struct V_44 * V_16 )
{
const T_4 * V_45 ;
unsigned int V_46 ;
V_45 = F_18 ( V_35 , L_10 , & V_46 ) ;
if ( V_45 == NULL || V_46 < 2 * sizeof( int ) ) {
return 1 ;
}
V_16 -> V_47 = F_31 ( V_45 [ 0 ] ) ;
V_16 -> V_48 = F_31 ( V_45 [ 1 ] ) ;
return 0 ;
}
int F_32 ( struct V_44 * V_16 )
{
struct V_22 * V_35 = V_16 -> V_2 ;
if ( F_17 ( V_35 ) )
F_19 ( V_35 ) ;
if ( F_30 ( V_35 , V_16 ) )
return 1 ;
V_16 -> V_49 = & V_50 ;
V_16 -> V_9 = F_29 ( V_35 ) ;
return 0 ;
}
void T_3 F_33 ( void )
{
struct V_22 * V_51 ;
struct V_44 * V_16 ;
struct V_22 * V_52 = F_34 ( L_11 ) ;
F_35 (root, node) {
if ( V_51 -> type == NULL || ( strcmp ( V_51 -> type , L_12 ) != 0 &&
strcmp ( V_51 -> type , L_13 ) != 0 ) )
continue;
V_16 = F_36 ( V_51 ) ;
if ( ! V_16 )
continue;
F_32 ( V_16 ) ;
F_37 ( V_16 , V_51 , 0 ) ;
F_38 ( V_16 ) ;
}
F_39 ( V_52 ) ;
F_40 () ;
if ( V_53 ) {
const int * V_54 ;
V_54 = F_18 ( V_53 ,
L_14 , NULL ) ;
if ( V_54 ) {
if ( * V_54 )
F_41 ( V_55 ) ;
else
F_42 ( V_55 ) ;
}
#ifdef F_43
V_54 = F_18 ( V_53 ,
L_15 , NULL ) ;
if ( V_54 && * V_54 )
F_41 ( V_56 ) ;
#endif
}
}
