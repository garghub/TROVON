static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
unsigned long V_5 ;
F_2 ( & V_6 -> V_7 , V_5 ) ;
if ( ( V_4 ) < 8 ) {
F_3 ( V_3 , V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_8 ) ;
F_3 ( V_3 , V_9 ) ;
}
F_4 ( & V_6 -> V_7 , V_5 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
unsigned long V_5 ;
T_1 V_10 ;
F_2 ( & V_6 -> V_7 , V_5 ) ;
if ( V_4 < 8 ) {
V_10 = F_6 ( V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_8 ) ;
V_10 = F_6 ( V_9 ) ;
}
F_4 ( & V_6 -> V_7 , V_5 ) ;
return V_10 ;
}
static int T_2 F_7 ( void )
{
return F_8 ( & V_11 ) ;
}
static void T_3 F_9 ( void )
{
F_10 ( & V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
if ( V_2 -> V_12 )
F_13 ( V_2 -> V_12 , V_13 ) ;
if ( V_2 -> V_14 )
F_14 ( V_2 -> V_14 , V_2 ) ;
if ( V_6 -> V_15 )
F_15 ( V_6 -> V_15 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * * V_2 )
{
struct V_16 * V_15 = NULL ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
V_15 = F_17 ( NULL ,
F_18 ( 'N' , 'I' , 'C' ) ,
F_19 ( V_19 [ V_17 ] .
V_20 ) , NULL ) ;
if ( V_15 == NULL || V_15 -> V_21 == NULL )
continue;
if ( F_20 ( V_15 ) < 0 ) {
F_21
( L_1 ,
V_19 [ V_17 ] . V_22 ) ;
continue;
}
if ( F_22 ( V_15 ) < 0 ) {
F_15 ( V_15 ) ;
return - V_23 ;
}
if ( ! F_23 ( V_15 , 0 )
|| ! F_24 ( V_15 , 0 ) ) {
F_15 ( V_15 ) ;
F_21 ( L_2 ) ;
return - V_24 ;
}
break;
}
if ( V_17 == V_18 )
return - V_25 ;
* V_2 = V_15 ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_26 * V_27 )
{
struct V_16 * V_15 ;
int V_10 ;
unsigned long V_12 ;
int V_28 ;
unsigned int V_14 ;
V_10 = F_26 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_29 = & F_1 ;
V_6 -> V_30 = & F_5 ;
V_6 -> V_31 = & V_32 ;
V_6 -> V_33 = & V_34 ;
V_12 = V_27 -> V_35 [ 0 ] ;
V_14 = V_27 -> V_35 [ 1 ] ;
V_15 = NULL ;
if ( V_12 == 0 ) {
V_10 = F_16 ( & V_15 ) ;
if ( V_10 < 0 )
return V_10 ;
V_12 = F_27 ( V_15 , 0 ) ;
V_14 = F_28 ( V_15 , 0 ) ;
V_6 -> V_15 = V_15 ;
}
F_21 ( L_3 , V_2 -> V_36 , V_12 ) ;
if ( ! F_29 ( V_12 , V_13 , L_4 ) ) {
F_21 ( L_5 ) ;
return - V_37 ;
}
V_2 -> V_12 = V_12 ;
#ifdef F_30
{
int V_17 ;
F_21 ( L_6 ) ;
for ( V_17 = 0 ; V_17 < 16 ; V_17 += 2 ) {
F_21 ( L_7 , F_31 ( V_2 -> V_12 + V_17 ) ,
F_32 ( V_2 -> V_12 + V_17 + 1 ) ) ;
}
}
#endif
V_28 = F_33 ( V_2 ) ;
if ( V_28 < 0 )
return - V_37 ;
V_2 -> V_38 = V_19 + V_28 ;
F_21 ( L_8 , V_39 . V_22 ) ;
V_2 -> V_40 = V_39 . V_22 ;
if ( V_14 != 0 ) {
if ( V_14 > 15 || V_41 [ V_14 ] == - 1 ) {
F_21 ( L_9 , V_14 ) ;
return - V_42 ;
}
F_21 ( L_10 , V_14 ) ;
V_10 = F_34 ( V_14 , V_43 , V_44 ,
L_4 , V_2 ) ;
if ( V_10 < 0 ) {
F_21 ( L_11 ) ;
return - V_42 ;
}
V_2 -> V_14 = V_14 ;
}
V_10 = F_35 ( V_2 , V_27 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
int V_45 = F_36 ( V_2 , 511 ) ;
int V_17 ;
for ( V_17 = 0 ; V_17 < V_18 ; V_17 ++ ) {
if ( V_19 [ V_17 ] . V_45 == V_45 )
return V_17 ;
}
if ( V_45 == 255 )
F_21 ( L_12 ) ;
else if ( V_45 == 0 )
F_21 ( L_13 ) ;
else
F_21 ( L_14 , V_45 ) ;
return - 1 ;
}
