unsigned long F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_4 , V_3 ) ;
}
static void F_3 ( unsigned int V_3 , unsigned long V_5 )
{
F_2 ( V_4 , V_3 ) = V_5 ;
}
static void T_1 F_4 ( void )
{
const struct V_6 * V_7 ;
struct V_8 * V_9 = NULL ;
unsigned long V_10 = V_11 ;
unsigned long V_12 = 0 ;
unsigned long V_5 = 0 ;
int V_3 = 0 ;
V_13 = F_5 ( V_14 , sizeof( * V_13 ) ,
V_15 ) ;
F_6 (cpu) {
const T_2 * V_16 ;
int V_17 ;
V_9 = F_7 ( V_3 , NULL ) ;
if ( ! V_9 ) {
F_8 ( L_1 , V_3 ) ;
continue;
}
for ( V_7 = V_18 ; V_7 -> V_19 ; V_7 ++ )
if ( F_9 ( V_9 , V_7 -> V_19 ) )
break;
if ( V_7 -> V_19 == NULL )
continue;
V_16 = F_10 ( V_9 , L_2 , & V_17 ) ;
if ( ! V_16 || V_17 != 4 ) {
F_8 ( L_3 ,
V_9 -> V_20 ) ;
continue;
}
V_5 = ( ( F_11 ( V_16 ) ) >> 20 ) * V_7 -> V_21 ;
if ( V_5 < V_10 )
V_10 = V_5 ;
if ( V_5 > V_12 )
V_12 = V_5 ;
F_12 ( V_3 ) = V_5 ;
}
if ( 4 * V_12 < ( 3 * ( V_12 + V_10 ) ) )
V_22 = ( V_10 + V_12 )
>> ( V_23 + 1 ) ;
else
V_22 = ( ( V_12 / 3 )
>> ( V_23 - 1 ) ) + 1 ;
}
static void F_13 ( unsigned int V_3 )
{
if ( ! F_12 ( V_3 ) )
return;
F_3 ( V_3 , F_12 ( V_3 ) / V_22 ) ;
F_14 ( L_4 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
static inline void F_4 ( void ) {}
static inline void F_13 ( unsigned int V_24 ) {}
const struct V_25 * F_15 ( int V_3 )
{
return & V_26 [ V_3 ] . V_27 ;
}
const struct V_25 * F_16 ( int V_3 )
{
return & V_26 [ V_3 ] . V_28 ;
}
static void F_17 ( unsigned int V_24 )
{
struct V_29 * V_30 , * V_31 = & V_26 [ V_24 ] ;
int V_3 ;
F_6 (cpu) {
V_30 = & V_26 [ V_3 ] ;
if ( V_31 -> V_32 != V_30 -> V_32 )
continue;
F_18 ( V_24 , & V_30 -> V_27 ) ;
if ( V_3 != V_24 )
F_18 ( V_3 , & V_31 -> V_27 ) ;
if ( V_31 -> V_33 != V_30 -> V_33 )
continue;
F_18 ( V_24 , & V_30 -> V_28 ) ;
if ( V_3 != V_24 )
F_18 ( V_3 , & V_31 -> V_28 ) ;
}
F_19 () ;
}
void F_20 ( unsigned int V_24 )
{
struct V_29 * V_31 = & V_26 [ V_24 ] ;
unsigned int V_34 ;
if ( V_31 -> V_33 != - 1 )
return;
V_34 = F_21 () ;
if ( ( V_34 & V_35 ) == V_36 ) {
if ( V_34 & V_37 ) {
V_31 -> V_38 = F_22 ( V_34 , 0 ) ;
V_31 -> V_33 = F_22 ( V_34 , 1 ) ;
V_31 -> V_32 = F_22 ( V_34 , 2 ) ;
} else {
V_31 -> V_38 = - 1 ;
V_31 -> V_33 = F_22 ( V_34 , 0 ) ;
V_31 -> V_32 = F_22 ( V_34 , 1 ) ;
}
} else {
V_31 -> V_38 = - 1 ;
V_31 -> V_33 = 0 ;
V_31 -> V_32 = - 1 ;
}
F_17 ( V_24 ) ;
F_13 ( V_24 ) ;
F_14 ( L_5 ,
V_24 , V_26 [ V_24 ] . V_38 ,
V_26 [ V_24 ] . V_33 ,
V_26 [ V_24 ] . V_32 , V_34 ) ;
}
static inline int F_23 ( void )
{
return V_39 | V_40 ;
}
void T_1 F_24 ( void )
{
unsigned int V_3 ;
F_6 (cpu) {
struct V_29 * V_30 = & ( V_26 [ V_3 ] ) ;
V_30 -> V_38 = - 1 ;
V_30 -> V_33 = - 1 ;
V_30 -> V_32 = - 1 ;
F_25 ( & V_30 -> V_27 ) ;
F_25 ( & V_30 -> V_28 ) ;
}
F_19 () ;
F_4 () ;
F_26 ( V_41 ) ;
}
