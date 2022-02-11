static void F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
F_2 ( & V_6 -> V_9 , V_8 ) ;
if ( ( V_4 ) < 8 ) {
F_3 ( V_3 , V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_10 ) ;
F_3 ( V_3 , V_11 ) ;
}
F_4 ( & V_6 -> V_9 , V_8 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned long V_8 ;
T_1 V_12 ;
F_2 ( & V_6 -> V_9 , V_8 ) ;
if ( V_4 < 8 ) {
V_12 = F_6 ( V_4 * 2 ) ;
} else {
F_3 ( V_4 , V_10 ) ;
V_12 = F_6 ( V_11 ) ;
}
F_4 ( & V_6 -> V_9 , V_8 ) ;
return V_12 ;
}
static int F_7 ( struct V_13 * * V_2 )
{
struct V_13 * V_14 = NULL ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_8 ( V_16 ) ; V_15 ++ ) {
V_14 = F_9 ( NULL ,
F_10 ( 'N' , 'I' , 'C' ) ,
F_11 ( V_16 [ V_15 ] .
V_17 ) , NULL ) ;
if ( V_14 == NULL || V_14 -> V_18 == NULL )
continue;
if ( F_12 ( V_14 ) < 0 ) {
F_13
( L_1 ,
V_16 [ V_15 ] . V_19 ) ;
continue;
}
if ( F_14 ( V_14 ) < 0 ) {
F_15 ( V_14 ) ;
return - V_20 ;
}
if ( ! F_16 ( V_14 , 0 )
|| ! F_17 ( V_14 , 0 ) ) {
F_15 ( V_14 ) ;
F_13 ( L_2 ) ;
return - V_21 ;
}
break;
}
if ( V_15 == F_8 ( V_16 ) )
return - V_22 ;
* V_2 = V_14 ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_23 = F_19 ( V_2 , 511 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < F_8 ( V_16 ) ; V_15 ++ ) {
if ( V_16 [ V_15 ] . V_23 == V_23 )
return V_15 ;
}
if ( V_23 == 255 )
F_13 ( L_3 ) ;
else if ( V_23 == 0 )
F_13 ( L_4 ) ;
else
F_13 ( L_5 , V_23 ) ;
return - 1 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_24 * V_25 )
{
const struct V_26 * V_27 ;
struct V_5 * V_6 ;
struct V_13 * V_14 ;
int V_12 ;
unsigned long V_28 ;
int V_29 ;
unsigned int V_30 ;
V_12 = F_21 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_31 = & F_1 ;
V_6 -> V_32 = & F_5 ;
V_6 -> V_33 = & V_34 ;
V_6 -> V_35 = & V_36 ;
V_28 = V_25 -> V_37 [ 0 ] ;
V_30 = V_25 -> V_37 [ 1 ] ;
V_14 = NULL ;
if ( V_28 == 0 ) {
V_12 = F_7 ( & V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_28 = F_22 ( V_14 , 0 ) ;
V_30 = F_23 ( V_14 , 0 ) ;
V_6 -> V_14 = V_14 ;
}
V_12 = F_24 ( V_2 , V_28 , V_38 ) ;
if ( V_12 )
return V_12 ;
V_29 = F_18 ( V_2 ) ;
if ( V_29 < 0 )
return - V_39 ;
V_2 -> V_40 = V_16 + V_29 ;
V_27 = F_25 ( V_2 ) ;
F_13 ( L_6 , V_27 -> V_19 ) ;
V_2 -> V_41 = V_27 -> V_19 ;
if ( V_30 != 0 ) {
if ( V_30 > 15 || V_42 [ V_30 ] == - 1 ) {
F_13 ( L_7 , V_30 ) ;
return - V_43 ;
}
F_13 ( L_8 , V_30 ) ;
V_12 = F_26 ( V_30 , V_44 , V_45 ,
L_9 , V_2 ) ;
if ( V_12 < 0 ) {
F_13 ( L_10 ) ;
return - V_43 ;
}
V_2 -> V_30 = V_30 ;
}
V_12 = F_27 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_29 ( V_2 ) ;
F_30 ( V_2 ) ;
if ( V_6 -> V_14 )
F_15 ( V_6 -> V_14 ) ;
}
