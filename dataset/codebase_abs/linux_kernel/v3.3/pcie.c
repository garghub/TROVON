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
F_6 ( & V_3 -> V_23 , & V_5 -> V_12 [ 0 ] ) ;
snprintf ( V_5 -> V_24 , sizeof( V_5 -> V_24 ) ,
L_3 , V_5 -> V_11 ) ;
V_5 -> V_24 [ sizeof( V_5 -> V_24 ) - 1 ] = 0 ;
V_5 -> V_12 [ 1 ] . V_13 = V_5 -> V_24 ;
if ( V_5 -> V_11 == 0 ) {
V_5 -> V_12 [ 1 ] . V_14 = V_25 ;
V_5 -> V_12 [ 1 ] . V_16 = V_5 -> V_12 [ 1 ] . V_14 + V_26 - 1 ;
} else {
V_5 -> V_12 [ 1 ] . V_14 = V_27 ;
V_5 -> V_12 [ 1 ] . V_16 = V_5 -> V_12 [ 1 ] . V_14 + V_28 - 1 ;
}
V_5 -> V_12 [ 1 ] . V_20 = V_29 ;
if ( F_4 ( & V_30 , & V_5 -> V_12 [ 1 ] ) )
F_5 ( L_4 ) ;
F_6 ( & V_3 -> V_23 , & V_5 -> V_12 [ 1 ] ) ;
return 1 ;
}
static struct V_4 * F_7 ( int V_31 )
{
int V_32 ;
for ( V_32 = V_6 - 1 ; V_32 >= 0 ; V_32 -- ) {
int V_33 = V_4 [ V_32 ] . V_7 ;
if ( V_33 != - 1 && V_33 <= V_31 )
break;
}
return V_32 >= 0 ? V_4 + V_32 : NULL ;
}
static int F_8 ( struct V_4 * V_5 , int V_31 , int V_34 )
{
if ( V_31 == V_5 -> V_7 && V_34 > 1 )
return 0 ;
return 1 ;
}
static int F_9 ( struct V_35 * V_31 , T_2 V_36 , int V_37 ,
int V_38 , T_2 * V_39 )
{
struct V_4 * V_5 = F_7 ( V_31 -> V_40 ) ;
unsigned long V_20 ;
int V_41 ;
if ( F_8 ( V_5 , V_31 -> V_40 , F_10 ( V_36 ) ) == 0 ) {
* V_39 = 0xffffffff ;
return V_42 ;
}
F_11 ( & V_5 -> V_43 , V_20 ) ;
V_41 = F_12 ( V_5 -> V_9 , V_31 , V_36 , V_37 , V_38 , V_39 ) ;
F_13 ( & V_5 -> V_43 , V_20 ) ;
return V_41 ;
}
static int F_14 ( struct V_35 * V_31 , T_2 V_36 ,
int V_37 , int V_38 , T_2 V_39 )
{
struct V_4 * V_5 = F_7 ( V_31 -> V_40 ) ;
unsigned long V_20 ;
int V_41 ;
if ( F_8 ( V_5 , V_31 -> V_40 , F_10 ( V_36 ) ) == 0 )
return V_42 ;
F_11 ( & V_5 -> V_43 , V_20 ) ;
V_41 = F_15 ( V_5 -> V_9 , V_31 , V_36 , V_37 , V_38 , V_39 ) ;
F_13 ( & V_5 -> V_43 , V_20 ) ;
return V_41 ;
}
static void T_3 F_16 ( struct V_44 * V_34 )
{
if ( V_34 -> V_31 -> V_45 == NULL && V_34 -> V_36 == 0 ) {
int V_32 ;
for ( V_32 = 0 ; V_32 < V_46 ; V_32 ++ ) {
V_34 -> V_47 [ V_32 ] . V_14 = 0 ;
V_34 -> V_47 [ V_32 ] . V_16 = 0 ;
V_34 -> V_47 [ V_32 ] . V_20 = 0 ;
}
}
}
static struct V_35 T_1 *
F_17 ( int V_1 , struct V_2 * V_3 )
{
struct V_35 * V_31 ;
if ( V_1 < V_6 ) {
V_31 = F_18 ( NULL , V_3 -> V_8 , & V_48 , V_3 ,
& V_3 -> V_23 ) ;
} else {
V_31 = NULL ;
F_19 () ;
}
return V_31 ;
}
static int T_1 F_20 ( const struct V_44 * V_34 , T_4 V_49 , T_4 V_50 )
{
struct V_4 * V_5 = F_7 ( V_34 -> V_31 -> V_40 ) ;
return V_5 -> V_11 ? V_51 : V_52 ;
}
static void T_1 F_21 ( int V_11 , unsigned long V_9 )
{
F_22 ( V_53 L_5 , V_11 ) ;
if ( F_23 ( ( void V_54 * ) V_9 ) ) {
struct V_4 * V_5 = & V_4 [ V_6 ++ ] ;
F_22 ( V_53 L_6 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_9 = ( void V_54 * ) V_9 ;
F_24 ( & V_5 -> V_43 ) ;
memset ( V_5 -> V_12 , 0 , sizeof( V_5 -> V_12 ) ) ;
} else {
F_22 ( V_53 L_7 ) ;
}
}
void T_1 F_25 ( int V_55 , int V_56 )
{
V_57 = V_25 ;
if ( V_55 )
F_21 ( 0 , V_58 ) ;
if ( V_56 )
F_21 ( 1 , V_59 ) ;
F_26 ( & V_60 ) ;
}
