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
struct V_6 * V_7 ;
struct V_8 * V_9 = NULL ;
unsigned long V_10 = ( unsigned long ) ( - 1 ) ;
unsigned long V_11 = 0 ;
unsigned long V_12 = 0 ;
int V_13 , V_3 = 0 ;
V_13 = V_14 * sizeof( struct V_15 ) ;
V_15 = (struct V_15 * ) F_5 ( V_13 , V_16 ) ;
while ( ( V_9 = F_6 ( V_9 , L_1 ) ) ) {
const T_2 * V_17 , * V_18 ;
int V_19 ;
if ( V_3 >= F_7 () )
break;
for ( V_7 = V_20 ; V_7 -> V_21 ; V_7 ++ )
if ( F_8 ( V_9 , V_7 -> V_21 ) )
break;
if ( V_7 -> V_21 == NULL )
continue;
V_17 = F_9 ( V_9 , L_2 , & V_19 ) ;
if ( ! V_17 || V_19 != 4 ) {
F_10 ( L_3 ,
V_9 -> V_22 ) ;
continue;
}
V_18 = F_9 ( V_9 , L_4 , & V_19 ) ;
if ( ! V_18 || V_19 != 4 ) {
F_10 ( L_5 , V_9 -> V_22 ) ;
continue;
}
V_12 = ( ( F_11 ( V_17 ) ) >> 20 ) * V_7 -> V_23 ;
if ( V_12 < V_10 )
V_10 = V_12 ;
if ( V_12 > V_11 )
V_11 = V_12 ;
V_15 [ V_3 ] . V_12 = V_12 ;
V_15 [ V_3 ++ ] . V_24 = F_11 ( V_18 ) ;
}
if ( V_3 < F_7 () )
V_15 [ V_3 ] . V_24 = ( unsigned long ) ( - 1 ) ;
if ( V_10 == V_11 )
V_15 [ 0 ] . V_24 = ( unsigned long ) ( - 1 ) ;
else if ( 4 * V_11 < ( 3 * ( V_11 + V_10 ) ) )
V_25 = ( V_10 + V_11 )
>> ( V_26 + 1 ) ;
else
V_25 = ( ( V_11 / 3 )
>> ( V_26 - 1 ) ) + 1 ;
}
void F_12 ( unsigned int V_3 , unsigned long V_24 )
{
unsigned int V_27 = 0 ;
for ( V_27 = 0 ; V_27 < F_7 () ; V_27 ++ ) {
if ( V_15 [ V_27 ] . V_24 == V_24 )
break;
if ( V_15 [ V_27 ] . V_24 == - 1 )
return;
}
if ( V_27 == F_7 () )
return;
F_3 ( V_3 , V_15 [ V_27 ] . V_12 / V_25 ) ;
F_13 ( V_28 L_6 ,
V_3 , F_1 ( NULL , V_3 ) ) ;
}
static inline void F_4 ( void ) {}
static inline void F_12 ( unsigned int V_29 , unsigned int V_30 ) {}
const struct V_31 * F_14 ( int V_3 )
{
return & V_32 [ V_3 ] . V_33 ;
}
void F_15 ( unsigned int V_29 )
{
struct V_34 * V_35 , * V_36 = & V_32 [ V_29 ] ;
int V_3 ;
F_16 (cpu) {
V_35 = & V_32 [ V_3 ] ;
if ( V_36 -> V_37 != V_35 -> V_37 )
continue;
F_17 ( V_29 , & V_35 -> V_33 ) ;
if ( V_3 != V_29 )
F_17 ( V_3 , & V_36 -> V_33 ) ;
if ( V_36 -> V_38 != V_35 -> V_38 )
continue;
F_17 ( V_29 , & V_35 -> V_39 ) ;
if ( V_3 != V_29 )
F_17 ( V_3 , & V_36 -> V_39 ) ;
}
F_18 () ;
}
void F_19 ( unsigned int V_29 )
{
struct V_34 * V_36 = & V_32 [ V_29 ] ;
unsigned int V_30 ;
if ( V_36 -> V_38 != - 1 )
return;
V_30 = F_20 () ;
if ( ( V_30 & V_40 ) == V_41 ) {
if ( V_30 & V_42 ) {
V_36 -> V_43 = F_21 ( V_30 , 0 ) ;
V_36 -> V_38 = F_21 ( V_30 , 1 ) ;
V_36 -> V_37 = F_21 ( V_30 , 2 ) ;
} else {
V_36 -> V_43 = - 1 ;
V_36 -> V_38 = F_21 ( V_30 , 0 ) ;
V_36 -> V_37 = F_21 ( V_30 , 1 ) ;
}
} else {
V_36 -> V_43 = - 1 ;
V_36 -> V_38 = 0 ;
V_36 -> V_37 = - 1 ;
}
F_15 ( V_29 ) ;
F_12 ( V_29 , V_30 & V_44 ) ;
F_13 ( V_28 L_7 ,
V_29 , V_32 [ V_29 ] . V_43 ,
V_32 [ V_29 ] . V_38 ,
V_32 [ V_29 ] . V_37 , V_30 ) ;
}
void T_1 F_22 ( void )
{
unsigned int V_3 ;
F_16 (cpu) {
struct V_34 * V_35 = & ( V_32 [ V_3 ] ) ;
V_35 -> V_43 = - 1 ;
V_35 -> V_38 = - 1 ;
V_35 -> V_37 = - 1 ;
F_23 ( & V_35 -> V_33 ) ;
F_23 ( & V_35 -> V_39 ) ;
F_3 ( V_3 , V_45 ) ;
}
F_18 () ;
F_4 () ;
}
