static int T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( V_1 >= V_6 )
return 0 ;
V_5 = & V_4 [ V_1 ] ;
V_5 -> V_7 = V_3 -> V_8 ;
F_2 ( V_5 -> V_9 , V_3 -> V_8 ) ;
F_3 ( V_5 -> V_9 ) ;
snprintf ( V_5 -> V_10 , sizeof( V_5 -> V_10 ) ,
L_1 , V_5 -> V_11 ) ;
V_5 -> V_10 [ sizeof( V_5 -> V_10 ) - 1 ] = 0 ;
V_5 -> V_12 [ 0 ] . V_13 = V_5 -> V_10 ;
if ( V_5 -> V_11 == 0 ) {
V_5 -> V_12 [ 0 ] . V_14 = V_15 ;
V_5 -> V_12 [ 0 ] . V_16 = V_5 -> V_12 [ 0 ] . V_14 + V_17 - 1 ;
} else {
V_5 -> V_12 [ 0 ] . V_14 = V_18 ;
V_5 -> V_12 [ 0 ] . V_16 = V_5 -> V_12 [ 0 ] . V_14 + V_19 - 1 ;
}
V_5 -> V_12 [ 0 ] . V_20 = V_21 ;
if ( F_4 ( & V_22 , & V_5 -> V_12 [ 0 ] ) )
F_5 ( L_2 ) ;
F_6 ( & V_3 -> V_23 , & V_5 -> V_12 [ 0 ] , V_3 -> V_24 ) ;
snprintf ( V_5 -> V_25 , sizeof( V_5 -> V_25 ) ,
L_3 , V_5 -> V_11 ) ;
V_5 -> V_25 [ sizeof( V_5 -> V_25 ) - 1 ] = 0 ;
V_5 -> V_12 [ 1 ] . V_13 = V_5 -> V_25 ;
if ( V_5 -> V_11 == 0 ) {
V_5 -> V_12 [ 1 ] . V_14 = V_26 ;
V_5 -> V_12 [ 1 ] . V_16 = V_5 -> V_12 [ 1 ] . V_14 + V_27 - 1 ;
} else {
V_5 -> V_12 [ 1 ] . V_14 = V_28 ;
V_5 -> V_12 [ 1 ] . V_16 = V_5 -> V_12 [ 1 ] . V_14 + V_29 - 1 ;
}
V_5 -> V_12 [ 1 ] . V_20 = V_30 ;
if ( F_4 ( & V_31 , & V_5 -> V_12 [ 1 ] ) )
F_5 ( L_4 ) ;
F_6 ( & V_3 -> V_23 , & V_5 -> V_12 [ 1 ] , V_3 -> V_32 ) ;
return 1 ;
}
static struct V_4 * F_7 ( int V_33 )
{
int V_34 ;
for ( V_34 = V_6 - 1 ; V_34 >= 0 ; V_34 -- ) {
int V_35 = V_4 [ V_34 ] . V_7 ;
if ( V_35 != - 1 && V_35 <= V_33 )
break;
}
return V_34 >= 0 ? V_4 + V_34 : NULL ;
}
static int F_8 ( struct V_4 * V_5 , int V_33 , int V_36 )
{
if ( V_33 == V_5 -> V_7 && V_36 > 1 )
return 0 ;
return 1 ;
}
static int F_9 ( struct V_37 * V_33 , T_2 V_38 , int V_39 ,
int V_40 , T_2 * V_41 )
{
struct V_4 * V_5 = F_7 ( V_33 -> V_42 ) ;
unsigned long V_20 ;
int V_43 ;
if ( F_8 ( V_5 , V_33 -> V_42 , F_10 ( V_38 ) ) == 0 ) {
* V_41 = 0xffffffff ;
return V_44 ;
}
F_11 ( & V_5 -> V_45 , V_20 ) ;
V_43 = F_12 ( V_5 -> V_9 , V_33 , V_38 , V_39 , V_40 , V_41 ) ;
F_13 ( & V_5 -> V_45 , V_20 ) ;
return V_43 ;
}
static int F_14 ( struct V_37 * V_33 , T_2 V_38 ,
int V_39 , int V_40 , T_2 V_41 )
{
struct V_4 * V_5 = F_7 ( V_33 -> V_42 ) ;
unsigned long V_20 ;
int V_43 ;
if ( F_8 ( V_5 , V_33 -> V_42 , F_10 ( V_38 ) ) == 0 )
return V_44 ;
F_11 ( & V_5 -> V_45 , V_20 ) ;
V_43 = F_15 ( V_5 -> V_9 , V_33 , V_38 , V_39 , V_40 , V_41 ) ;
F_13 ( & V_5 -> V_45 , V_20 ) ;
return V_43 ;
}
static void T_3 F_16 ( struct V_46 * V_36 )
{
if ( V_36 -> V_33 -> V_47 == NULL && V_36 -> V_38 == 0 ) {
int V_34 ;
for ( V_34 = 0 ; V_34 < V_48 ; V_34 ++ ) {
V_36 -> V_49 [ V_34 ] . V_14 = 0 ;
V_36 -> V_49 [ V_34 ] . V_16 = 0 ;
V_36 -> V_49 [ V_34 ] . V_20 = 0 ;
}
}
}
static struct V_37 T_1 *
F_17 ( int V_1 , struct V_2 * V_3 )
{
struct V_37 * V_33 ;
if ( V_1 < V_6 ) {
V_33 = F_18 ( NULL , V_3 -> V_8 , & V_50 , V_3 ,
& V_3 -> V_23 ) ;
} else {
V_33 = NULL ;
F_19 () ;
}
return V_33 ;
}
static int T_1 F_20 ( const struct V_46 * V_36 , T_4 V_51 , T_4 V_52 )
{
struct V_4 * V_5 = F_7 ( V_36 -> V_33 -> V_42 ) ;
return V_5 -> V_11 ? V_53 : V_54 ;
}
static void T_1 F_21 ( int V_11 , unsigned long V_9 )
{
F_22 ( V_55 L_5 , V_11 ) ;
if ( F_23 ( ( void V_56 * ) V_9 ) ) {
struct V_4 * V_5 = & V_4 [ V_6 ++ ] ;
F_22 ( V_55 L_6 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_9 = ( void V_56 * ) V_9 ;
F_24 ( & V_5 -> V_45 ) ;
memset ( V_5 -> V_12 , 0 , sizeof( V_5 -> V_12 ) ) ;
} else {
F_22 ( V_55 L_7 ) ;
}
}
void T_1 F_25 ( int V_57 , int V_58 )
{
V_59 = V_26 ;
if ( V_57 )
F_21 ( 0 , V_60 ) ;
if ( V_58 )
F_21 ( 1 , V_61 ) ;
F_26 ( & V_62 ) ;
}
