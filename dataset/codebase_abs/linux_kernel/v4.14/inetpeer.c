void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 = V_4 ;
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 = 0 ;
}
void T_1 F_3 ( void )
{
struct V_7 V_8 ;
F_4 ( & V_8 ) ;
if ( V_8 . V_9 <= ( 32768 * 1024 ) / V_10 )
V_11 >>= 1 ;
if ( V_8 . V_9 <= ( 16384 * 1024 ) / V_10 )
V_11 >>= 1 ;
if ( V_8 . V_9 <= ( 8192 * 1024 ) / V_10 )
V_11 >>= 2 ;
V_12 = F_5 ( L_1 ,
sizeof( struct V_13 ) ,
0 , V_14 | V_15 ,
NULL ) ;
}
static struct V_13 * F_6 ( const struct V_16 * V_17 ,
struct V_1 * V_18 ,
unsigned int V_19 ,
struct V_13 * V_20 [] ,
unsigned int * V_21 ,
struct V_22 * * V_23 ,
struct V_22 * * * V_24 )
{
struct V_22 * * V_25 , * V_26 , * V_27 ;
struct V_13 * V_28 ;
V_25 = & V_18 -> V_3 . V_22 ;
V_26 = NULL ;
while ( 1 ) {
int V_29 ;
V_27 = F_7 ( * V_25 ) ;
if ( ! V_27 )
break;
V_26 = V_27 ;
V_28 = F_8 ( V_26 , struct V_13 , V_22 ) ;
V_29 = F_9 ( V_17 , & V_28 -> V_17 ) ;
if ( V_29 == 0 ) {
if ( ! F_10 ( & V_28 -> V_30 ) )
break;
return V_28 ;
}
if ( V_20 ) {
if ( * V_21 < V_31 )
V_20 [ ( * V_21 ) ++ ] = V_28 ;
} else if ( F_11 ( F_12 ( & V_18 -> V_5 , V_19 ) ) ) {
break;
}
if ( V_29 == - 1 )
V_25 = & V_27 -> V_32 ;
else
V_25 = & V_27 -> V_33 ;
}
* V_23 = V_26 ;
* V_24 = V_25 ;
return NULL ;
}
static void F_13 ( struct V_34 * V_35 )
{
F_14 ( V_12 , F_15 ( V_35 , struct V_13 , V_36 ) ) ;
}
static void F_16 ( struct V_1 * V_18 ,
struct V_13 * V_20 [] ,
unsigned int V_21 )
{
struct V_13 * V_28 ;
T_2 V_37 , V_38 ;
int V_39 ;
if ( V_18 -> V_6 >= V_11 )
V_38 = 0 ;
else
V_38 = V_40
- ( V_40 - V_41 ) / V_42 *
V_18 -> V_6 / V_11 * V_42 ;
for ( V_39 = 0 ; V_39 < V_21 ; V_39 ++ ) {
V_28 = V_20 [ V_39 ] ;
V_37 = ( T_2 ) V_43 - V_28 -> V_44 ;
if ( V_37 < V_38 || ! F_17 ( & V_28 -> V_30 ) )
V_20 [ V_39 ] = NULL ;
}
for ( V_39 = 0 ; V_39 < V_21 ; V_39 ++ ) {
V_28 = V_20 [ V_39 ] ;
if ( V_28 ) {
F_18 ( & V_28 -> V_22 , & V_18 -> V_3 ) ;
V_18 -> V_6 -- ;
F_19 ( & V_28 -> V_36 , F_13 ) ;
}
}
}
struct V_13 * F_20 ( struct V_1 * V_18 ,
const struct V_16 * V_17 ,
int V_45 )
{
struct V_13 * V_28 , * V_20 [ V_31 ] ;
struct V_22 * * V_25 , * V_26 ;
unsigned int V_21 , V_19 ;
int V_46 ;
F_21 () ;
V_19 = F_22 ( & V_18 -> V_5 ) ;
V_28 = F_6 ( V_17 , V_18 , V_19 , NULL , & V_21 , & V_26 , & V_25 ) ;
V_46 = F_12 ( & V_18 -> V_5 , V_19 ) ;
F_23 () ;
if ( V_28 )
return V_28 ;
if ( ! V_45 && ! V_46 )
return NULL ;
V_26 = NULL ;
F_24 ( & V_18 -> V_5 ) ;
V_21 = 0 ;
V_28 = F_6 ( V_17 , V_18 , V_19 , V_20 , & V_21 , & V_26 , & V_25 ) ;
if ( ! V_28 && V_45 ) {
V_28 = F_25 ( V_12 , V_47 ) ;
if ( V_28 ) {
V_28 -> V_17 = * V_17 ;
F_26 ( & V_28 -> V_30 , 2 ) ;
F_27 ( & V_28 -> V_48 , 0 ) ;
V_28 -> V_49 [ V_50 - 1 ] = V_51 ;
V_28 -> V_52 = 0 ;
V_28 -> V_53 = V_43 - 60 * V_42 ;
F_28 ( & V_28 -> V_22 , V_26 , V_25 ) ;
F_29 ( & V_28 -> V_22 , & V_18 -> V_3 ) ;
V_18 -> V_6 ++ ;
}
}
if ( V_21 )
F_16 ( V_18 , V_20 , V_21 ) ;
F_30 ( & V_18 -> V_5 ) ;
return V_28 ;
}
void F_31 ( struct V_13 * V_28 )
{
V_28 -> V_44 = ( T_2 ) V_43 ;
if ( F_32 ( & V_28 -> V_30 ) )
F_19 ( & V_28 -> V_36 , F_13 ) ;
}
bool F_33 ( struct V_13 * V_54 , int V_55 )
{
unsigned long V_56 , V_57 ;
bool V_58 = false ;
if ( ! V_54 )
return true ;
V_57 = V_54 -> V_52 ;
V_56 = V_43 ;
V_57 += V_56 - V_54 -> V_53 ;
V_54 -> V_53 = V_56 ;
if ( V_57 > V_59 * V_55 )
V_57 = V_59 * V_55 ;
if ( V_57 >= V_55 ) {
V_57 -= V_55 ;
V_58 = true ;
}
V_54 -> V_52 = V_57 ;
return V_58 ;
}
void F_34 ( struct V_1 * V_18 )
{
struct V_13 * V_28 , * V_60 ;
F_35 (p, n, &base->rb_root, rb_node) {
F_31 ( V_28 ) ;
F_36 () ;
}
V_18 -> V_3 = V_4 ;
V_18 -> V_6 = 0 ;
}
