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
if ( V_5 -> V_11 == 0 )
F_4 ( V_3 -> V_9 * V_12 , V_13 ) ;
else
F_4 ( V_3 -> V_9 * V_12 , V_14 ) ;
snprintf ( V_5 -> V_15 , sizeof( V_5 -> V_15 ) ,
L_1 , V_5 -> V_11 ) ;
V_5 -> V_15 [ sizeof( V_5 -> V_15 ) - 1 ] = 0 ;
V_5 -> V_16 . V_17 = V_5 -> V_15 ;
if ( V_5 -> V_11 == 0 ) {
V_5 -> V_16 . V_18 = V_19 ;
V_5 -> V_16 . V_20 = V_5 -> V_16 . V_18 + V_21 - 1 ;
} else {
V_5 -> V_16 . V_18 = V_22 ;
V_5 -> V_16 . V_20 = V_5 -> V_16 . V_18 + V_23 - 1 ;
}
V_5 -> V_16 . V_24 = V_25 ;
if ( F_5 ( & V_26 , & V_5 -> V_16 ) )
F_6 ( L_2 ) ;
F_7 ( & V_3 -> V_27 , & V_5 -> V_16 , V_3 -> V_28 ) ;
return 1 ;
}
static int F_8 ( struct V_4 * V_5 , int V_29 , int V_30 )
{
if ( V_29 == V_5 -> V_8 && V_30 > 1 )
return 0 ;
return 1 ;
}
static int F_9 ( struct V_31 * V_29 , T_2 V_32 , int V_33 ,
int V_34 , T_2 * V_35 )
{
struct V_2 * V_3 = V_29 -> V_36 ;
struct V_4 * V_5 = V_3 -> V_7 ;
unsigned long V_24 ;
int V_37 ;
if ( F_8 ( V_5 , V_29 -> V_38 , F_10 ( V_32 ) ) == 0 ) {
* V_35 = 0xffffffff ;
return V_39 ;
}
F_11 ( & V_5 -> V_40 , V_24 ) ;
V_37 = F_12 ( V_5 -> V_10 , V_29 , V_32 , V_33 , V_34 , V_35 ) ;
F_13 ( & V_5 -> V_40 , V_24 ) ;
return V_37 ;
}
static int F_14 ( struct V_31 * V_29 , T_2 V_32 ,
int V_33 , int V_34 , T_2 V_35 )
{
struct V_2 * V_3 = V_29 -> V_36 ;
struct V_4 * V_5 = V_3 -> V_7 ;
unsigned long V_24 ;
int V_37 ;
if ( F_8 ( V_5 , V_29 -> V_38 , F_10 ( V_32 ) ) == 0 )
return V_39 ;
F_11 ( & V_5 -> V_40 , V_24 ) ;
V_37 = F_15 ( V_5 -> V_10 , V_29 , V_32 , V_33 , V_34 , V_35 ) ;
F_13 ( & V_5 -> V_40 , V_24 ) ;
return V_37 ;
}
static void T_3 F_16 ( struct V_41 * V_30 )
{
if ( V_30 -> V_29 -> V_42 == NULL && V_30 -> V_32 == 0 ) {
int V_43 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_30 -> V_45 [ V_43 ] . V_18 = 0 ;
V_30 -> V_45 [ V_43 ] . V_20 = 0 ;
V_30 -> V_45 [ V_43 ] . V_24 = 0 ;
}
}
}
static struct V_31 T_1 *
F_17 ( int V_1 , struct V_2 * V_3 )
{
struct V_31 * V_29 ;
if ( V_1 < V_6 ) {
V_29 = F_18 ( NULL , V_3 -> V_9 , & V_46 , V_3 ,
& V_3 -> V_27 ) ;
} else {
V_29 = NULL ;
F_19 () ;
}
return V_29 ;
}
static int T_1 F_20 ( const struct V_41 * V_30 , T_4 V_47 , T_4 V_48 )
{
struct V_2 * V_3 = V_30 -> V_36 ;
struct V_4 * V_5 = V_3 -> V_7 ;
return V_5 -> V_11 ? V_49 : V_50 ;
}
static void T_1 F_21 ( int V_11 , void T_5 * V_10 )
{
F_22 ( V_51 L_3 , V_11 ) ;
if ( F_23 ( V_10 ) ) {
struct V_4 * V_5 = & V_4 [ V_6 ++ ] ;
struct V_52 * V_52 = F_24 ( L_4 , ( V_11 ? L_5 : L_6 ) ) ;
if ( ! F_25 ( V_52 ) )
F_26 ( V_52 ) ;
F_22 ( V_51 L_7 ) ;
V_5 -> V_11 = V_11 ;
V_5 -> V_8 = - 1 ;
V_5 -> V_10 = V_10 ;
F_27 ( & V_5 -> V_40 ) ;
memset ( & V_5 -> V_16 , 0 , sizeof( V_5 -> V_16 ) ) ;
} else {
F_22 ( V_51 L_8 ) ;
}
}
void T_1 F_28 ( int V_53 , int V_54 )
{
V_55 = V_19 ;
if ( V_53 )
F_21 ( 0 , V_56 ) ;
if ( V_54 )
F_21 ( 1 , V_57 ) ;
F_29 ( & V_58 ) ;
}
