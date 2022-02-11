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
unsigned long V_10 = ( unsigned long ) ( - 1 ) ;
unsigned long V_11 = 0 ;
unsigned long V_12 = 0 ;
int V_13 , V_3 = 0 ;
V_13 = V_14 * sizeof( * V_15 ) ;
V_15 = F_5 ( V_13 , V_16 ) ;
F_6 (cpu) {
const T_2 * V_17 ;
int V_18 ;
V_9 = F_7 ( V_3 , NULL ) ;
if ( ! V_9 ) {
F_8 ( L_1 , V_3 ) ;
continue;
}
for ( V_7 = V_19 ; V_7 -> V_20 ; V_7 ++ )
if ( F_9 ( V_9 , V_7 -> V_20 ) )
break;
if ( V_7 -> V_20 == NULL )
continue;
V_17 = F_10 ( V_9 , L_2 , & V_18 ) ;
if ( ! V_17 || V_18 != 4 ) {
F_8 ( L_3 ,
V_9 -> V_21 ) ;
continue;
}
V_12 = ( ( F_11 ( V_17 ) ) >> 20 ) * V_7 -> V_22 ;
if ( V_12 < V_10 )
V_10 = V_12 ;
if ( V_12 > V_11 )
V_11 = V_12 ;
F_12 ( V_3 ) = V_12 ;
}
if ( 4 * V_11 < ( 3 * ( V_11 + V_10 ) ) )
V_23 = ( V_10 + V_11 )
>> ( V_24 + 1 ) ;
else
V_23 = ( ( V_11 / 3 )
>> ( V_24 - 1 ) ) + 1 ;
}
static void F_13 ( unsigned int V_3 )
{
if ( ! F_12 ( V_3 ) )
return;
F_3 ( V_3 , F_12 ( V_3 ) / V_23 ) ;
F_14 ( V_25 L_4 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
static inline void F_4 ( void ) {}
static inline void F_13 ( unsigned int V_26 ) {}
const struct V_27 * F_15 ( int V_3 )
{
return & V_28 [ V_3 ] . V_29 ;
}
static void F_16 ( unsigned int V_26 )
{
struct V_30 * V_31 , * V_32 = & V_28 [ V_26 ] ;
int V_3 ;
F_6 (cpu) {
V_31 = & V_28 [ V_3 ] ;
if ( V_32 -> V_33 != V_31 -> V_33 )
continue;
F_17 ( V_26 , & V_31 -> V_29 ) ;
if ( V_3 != V_26 )
F_17 ( V_3 , & V_32 -> V_29 ) ;
if ( V_32 -> V_34 != V_31 -> V_34 )
continue;
F_17 ( V_26 , & V_31 -> V_35 ) ;
if ( V_3 != V_26 )
F_17 ( V_3 , & V_32 -> V_35 ) ;
}
F_18 () ;
}
void F_19 ( unsigned int V_26 )
{
struct V_30 * V_32 = & V_28 [ V_26 ] ;
unsigned int V_36 ;
if ( V_32 -> V_34 != - 1 )
return;
V_36 = F_20 () ;
if ( ( V_36 & V_37 ) == V_38 ) {
if ( V_36 & V_39 ) {
V_32 -> V_40 = F_21 ( V_36 , 0 ) ;
V_32 -> V_34 = F_21 ( V_36 , 1 ) ;
V_32 -> V_33 = F_21 ( V_36 , 2 ) ;
} else {
V_32 -> V_40 = - 1 ;
V_32 -> V_34 = F_21 ( V_36 , 0 ) ;
V_32 -> V_33 = F_21 ( V_36 , 1 ) ;
}
} else {
V_32 -> V_40 = - 1 ;
V_32 -> V_34 = 0 ;
V_32 -> V_33 = - 1 ;
}
F_16 ( V_26 ) ;
F_13 ( V_26 ) ;
F_14 ( V_25 L_5 ,
V_26 , V_28 [ V_26 ] . V_40 ,
V_28 [ V_26 ] . V_34 ,
V_28 [ V_26 ] . V_33 , V_36 ) ;
}
void T_1 F_22 ( void )
{
unsigned int V_3 ;
F_6 (cpu) {
struct V_30 * V_31 = & ( V_28 [ V_3 ] ) ;
V_31 -> V_40 = - 1 ;
V_31 -> V_34 = - 1 ;
V_31 -> V_33 = - 1 ;
F_23 ( & V_31 -> V_29 ) ;
F_23 ( & V_31 -> V_35 ) ;
F_3 ( V_3 , V_41 ) ;
}
F_18 () ;
F_4 () ;
}
