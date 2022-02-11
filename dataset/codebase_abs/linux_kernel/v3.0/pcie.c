static int T_1 F_1 ( int V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
if ( V_1 >= V_6 )
return 0 ;
V_5 = & V_4 [ V_1 ] ;
V_5 -> V_7 = V_3 -> V_8 ;
F_2 ( V_5 -> V_9 , V_3 -> V_8 ) ;
F_3 ( V_5 -> V_9 , & V_10 ) ;
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
V_3 -> V_24 [ 0 ] = & V_5 -> V_13 [ 0 ] ;
snprintf ( V_5 -> V_25 , sizeof( V_5 -> V_25 ) ,
L_3 , V_5 -> V_12 ) ;
V_5 -> V_25 [ sizeof( V_5 -> V_25 ) - 1 ] = 0 ;
V_5 -> V_13 [ 1 ] . V_14 = V_5 -> V_25 ;
if ( V_5 -> V_12 == 0 ) {
V_5 -> V_13 [ 1 ] . V_15 = V_26 ;
V_5 -> V_13 [ 1 ] . V_17 = V_5 -> V_13 [ 1 ] . V_15 + V_27 - 1 ;
} else {
V_5 -> V_13 [ 1 ] . V_15 = V_28 ;
V_5 -> V_13 [ 1 ] . V_17 = V_5 -> V_13 [ 1 ] . V_15 + V_29 - 1 ;
}
V_5 -> V_13 [ 1 ] . V_21 = V_30 ;
if ( F_4 ( & V_31 , & V_5 -> V_13 [ 1 ] ) )
F_5 ( L_4 ) ;
V_3 -> V_24 [ 1 ] = & V_5 -> V_13 [ 1 ] ;
V_3 -> V_24 [ 2 ] = NULL ;
return 1 ;
}
static struct V_4 * F_6 ( int V_32 )
{
int V_33 ;
for ( V_33 = V_6 - 1 ; V_33 >= 0 ; V_33 -- ) {
int V_34 = V_4 [ V_33 ] . V_7 ;
if ( V_34 != - 1 && V_34 <= V_32 )
break;
}
return V_33 >= 0 ? V_4 + V_33 : NULL ;
}
static int F_7 ( struct V_4 * V_5 , int V_32 , int V_35 )
{
if ( V_32 == V_5 -> V_7 && V_35 > 1 )
return 0 ;
return 1 ;
}
static int F_8 ( struct V_36 * V_32 , T_2 V_37 , int V_38 ,
int V_39 , T_2 * V_40 )
{
struct V_4 * V_5 = F_6 ( V_32 -> V_41 ) ;
unsigned long V_21 ;
int V_42 ;
if ( F_7 ( V_5 , V_32 -> V_41 , F_9 ( V_37 ) ) == 0 ) {
* V_40 = 0xffffffff ;
return V_43 ;
}
F_10 ( & V_5 -> V_44 , V_21 ) ;
V_42 = F_11 ( V_5 -> V_9 , V_32 , V_37 , V_38 , V_39 , V_40 ) ;
F_12 ( & V_5 -> V_44 , V_21 ) ;
return V_42 ;
}
static int F_13 ( struct V_36 * V_32 , T_2 V_37 ,
int V_38 , int V_39 , T_2 V_40 )
{
struct V_4 * V_5 = F_6 ( V_32 -> V_41 ) ;
unsigned long V_21 ;
int V_42 ;
if ( F_7 ( V_5 , V_32 -> V_41 , F_9 ( V_37 ) ) == 0 )
return V_43 ;
F_10 ( & V_5 -> V_44 , V_21 ) ;
V_42 = F_14 ( V_5 -> V_9 , V_32 , V_37 , V_38 , V_39 , V_40 ) ;
F_12 ( & V_5 -> V_44 , V_21 ) ;
return V_42 ;
}
static void T_3 F_15 ( struct V_45 * V_35 )
{
if ( V_35 -> V_32 -> V_46 == NULL && V_35 -> V_37 == 0 ) {
int V_33 ;
for ( V_33 = 0 ; V_33 < V_47 ; V_33 ++ ) {
V_35 -> V_24 [ V_33 ] . V_15 = 0 ;
V_35 -> V_24 [ V_33 ] . V_17 = 0 ;
V_35 -> V_24 [ V_33 ] . V_21 = 0 ;
}
}
}
static struct V_36 T_1 *
F_16 ( int V_1 , struct V_2 * V_3 )
{
struct V_36 * V_32 ;
if ( V_1 < V_6 ) {
V_32 = F_17 ( V_3 -> V_8 , & V_48 , V_3 ) ;
} else {
V_32 = NULL ;
F_18 () ;
}
return V_32 ;
}
static int T_1 F_19 ( struct V_45 * V_35 , T_4 V_49 , T_4 V_50 )
{
struct V_4 * V_5 = F_6 ( V_35 -> V_32 -> V_41 ) ;
return V_5 -> V_12 ? V_51 : V_52 ;
}
static void T_1 F_20 ( int V_12 , unsigned long V_9 )
{
F_21 ( V_53 L_5 , V_12 ) ;
if ( F_22 ( ( void V_54 * ) V_9 ) ) {
struct V_4 * V_5 = & V_4 [ V_6 ++ ] ;
F_21 ( V_53 L_6 ) ;
V_5 -> V_12 = V_12 ;
V_5 -> V_7 = - 1 ;
V_5 -> V_9 = ( void V_54 * ) V_9 ;
F_23 ( & V_5 -> V_44 ) ;
memset ( V_5 -> V_13 , 0 , sizeof( V_5 -> V_13 ) ) ;
} else {
F_21 ( V_53 L_7 ) ;
}
}
void T_1 F_24 ( int V_55 , int V_56 )
{
if ( V_55 )
F_20 ( 0 , V_57 ) ;
if ( V_56 )
F_20 ( 1 , V_58 ) ;
F_25 ( & V_59 ) ;
}
