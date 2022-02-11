static int T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( V_1 >= V_6 )
return 0 ;
V_5 = & V_4 [ V_1 ] ;
V_3 -> V_7 = V_5 ;
V_5 -> V_8 = V_3 -> V_9 ;
F_2 ( V_5 -> V_10 , V_3 -> V_9 ) ;
F_3 ( V_5 -> V_10 ) ;
snprintf ( V_5 -> V_11 , sizeof( V_5 -> V_11 ) ,
L_1 , V_5 -> V_12 ) ;
V_5 -> V_11 [ sizeof( V_5 -> V_11 ) - 1 ] = 0 ;
V_5 -> V_13 [ 0 ] . V_14 = V_5 -> V_11 ;
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_13 [ 0 ] . V_15 = V_16 ;
V_5 -> V_13 [ 0 ] . V_17 = V_5 -> V_13 [ 0 ] . V_15 + V_18 - 1 ;
} else {
V_5 -> V_13 [ 0 ] . V_15 = V_19 ;
V_5 -> V_13 [ 0 ] . V_17 = V_5 -> V_13 [ 0 ] . V_15 + V_20 - 1 ;
}
V_5 -> V_13 [ 0 ] . V_21 = V_22 ;
if ( F_4 ( & V_23 , & V_5 -> V_13 [ 0 ] ) )
F_5 ( L_2 ) ;
F_6 ( & V_3 -> V_24 , & V_5 -> V_13 [ 0 ] , V_3 -> V_25 ) ;
snprintf ( V_5 -> V_26 , sizeof( V_5 -> V_26 ) ,
L_3 , V_5 -> V_12 ) ;
V_5 -> V_26 [ sizeof( V_5 -> V_26 ) - 1 ] = 0 ;
V_5 -> V_13 [ 1 ] . V_14 = V_5 -> V_26 ;
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_13 [ 1 ] . V_15 = V_27 ;
V_5 -> V_13 [ 1 ] . V_17 = V_5 -> V_13 [ 1 ] . V_15 + V_28 - 1 ;
} else {
V_5 -> V_13 [ 1 ] . V_15 = V_29 ;
V_5 -> V_13 [ 1 ] . V_17 = V_5 -> V_13 [ 1 ] . V_15 + V_30 - 1 ;
}
V_5 -> V_13 [ 1 ] . V_21 = V_31 ;
if ( F_4 ( & V_32 , & V_5 -> V_13 [ 1 ] ) )
F_5 ( L_4 ) ;
F_6 ( & V_3 -> V_24 , & V_5 -> V_13 [ 1 ] , V_3 -> V_33 ) ;
return 1 ;
}
static int F_7 ( struct V_4 * V_5 , int V_34 , int V_35 )
{
if ( V_34 == V_5 -> V_8 && V_35 > 1 )
return 0 ;
return 1 ;
}
static int F_8 ( struct V_36 * V_34 , T_2 V_37 , int V_38 ,
int V_39 , T_2 * V_40 )
{
struct V_2 * V_3 = V_34 -> V_41 ;
struct V_4 * V_5 = V_3 -> V_7 ;
unsigned long V_21 ;
int V_42 ;
if ( F_7 ( V_5 , V_34 -> V_43 , F_9 ( V_37 ) ) == 0 ) {
* V_40 = 0xffffffff ;
return V_44 ;
}
F_10 ( & V_5 -> V_45 , V_21 ) ;
V_42 = F_11 ( V_5 -> V_10 , V_34 , V_37 , V_38 , V_39 , V_40 ) ;
F_12 ( & V_5 -> V_45 , V_21 ) ;
return V_42 ;
}
static int F_13 ( struct V_36 * V_34 , T_2 V_37 ,
int V_38 , int V_39 , T_2 V_40 )
{
struct V_2 * V_3 = V_34 -> V_41 ;
struct V_4 * V_5 = V_3 -> V_7 ;
unsigned long V_21 ;
int V_42 ;
if ( F_7 ( V_5 , V_34 -> V_43 , F_9 ( V_37 ) ) == 0 )
return V_44 ;
F_10 ( & V_5 -> V_45 , V_21 ) ;
V_42 = F_14 ( V_5 -> V_10 , V_34 , V_37 , V_38 , V_39 , V_40 ) ;
F_12 ( & V_5 -> V_45 , V_21 ) ;
return V_42 ;
}
static void T_3 F_15 ( struct V_46 * V_35 )
{
if ( V_35 -> V_34 -> V_47 == NULL && V_35 -> V_37 == 0 ) {
int V_48 ;
for ( V_48 = 0 ; V_48 < V_49 ; V_48 ++ ) {
V_35 -> V_50 [ V_48 ] . V_15 = 0 ;
V_35 -> V_50 [ V_48 ] . V_17 = 0 ;
V_35 -> V_50 [ V_48 ] . V_21 = 0 ;
}
}
}
static struct V_36 T_1 *
F_16 ( int V_1 , struct V_2 * V_3 )
{
struct V_36 * V_34 ;
if ( V_1 < V_6 ) {
V_34 = F_17 ( NULL , V_3 -> V_9 , & V_51 , V_3 ,
& V_3 -> V_24 ) ;
} else {
V_34 = NULL ;
F_18 () ;
}
return V_34 ;
}
static int T_1 F_19 ( const struct V_46 * V_35 , T_4 V_52 , T_4 V_53 )
{
struct V_2 * V_3 = V_35 -> V_41 ;
struct V_4 * V_5 = V_3 -> V_7 ;
return V_5 -> V_12 ? V_54 : V_55 ;
}
static void T_1 F_20 ( int V_12 , unsigned long V_10 )
{
F_21 ( V_56 L_5 , V_12 ) ;
if ( F_22 ( ( void V_57 * ) V_10 ) ) {
struct V_4 * V_5 = & V_4 [ V_6 ++ ] ;
F_21 ( V_56 L_6 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_8 = - 1 ;
V_5 -> V_10 = ( void V_57 * ) V_10 ;
F_23 ( & V_5 -> V_45 ) ;
memset ( V_5 -> V_13 , 0 , sizeof( V_5 -> V_13 ) ) ;
} else {
F_21 ( V_56 L_7 ) ;
}
}
void T_1 F_24 ( int V_58 , int V_59 )
{
V_60 = V_27 ;
if ( V_58 )
F_20 ( 0 , V_61 ) ;
if ( V_59 )
F_20 ( 1 , V_62 ) ;
F_25 ( & V_63 ) ;
}
