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
static int F_7 ( struct V_11 * * V_2 )
{
struct V_11 * V_12 = NULL ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
V_12 = F_8 ( NULL ,
F_9 ( 'N' , 'I' , 'C' ) ,
F_10 ( V_15 [ V_13 ] .
V_16 ) , NULL ) ;
if ( V_12 == NULL || V_12 -> V_17 == NULL )
continue;
if ( F_11 ( V_12 ) < 0 ) {
F_12
( L_1 ,
V_15 [ V_13 ] . V_18 ) ;
continue;
}
if ( F_13 ( V_12 ) < 0 ) {
F_14 ( V_12 ) ;
return - V_19 ;
}
if ( ! F_15 ( V_12 , 0 )
|| ! F_16 ( V_12 , 0 ) ) {
F_14 ( V_12 ) ;
F_12 ( L_2 ) ;
return - V_20 ;
}
break;
}
if ( V_13 == V_14 )
return - V_21 ;
* V_2 = V_12 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_22 = F_18 ( V_2 , 511 ) ;
int V_13 ;
for ( V_13 = 0 ; V_13 < V_14 ; V_13 ++ ) {
if ( V_15 [ V_13 ] . V_22 == V_22 )
return V_13 ;
}
if ( V_22 == 255 )
F_12 ( L_3 ) ;
else if ( V_22 == 0 )
F_12 ( L_4 ) ;
else
F_12 ( L_5 , V_22 ) ;
return - 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_23 * V_24 )
{
struct V_11 * V_12 ;
int V_10 ;
unsigned long V_25 ;
int V_26 ;
unsigned int V_27 ;
V_10 = F_20 ( V_2 ) ;
if ( V_10 < 0 )
return V_10 ;
V_6 -> V_28 = & F_1 ;
V_6 -> V_29 = & F_5 ;
V_6 -> V_30 = & V_31 ;
V_6 -> V_32 = & V_33 ;
V_25 = V_24 -> V_34 [ 0 ] ;
V_27 = V_24 -> V_34 [ 1 ] ;
V_12 = NULL ;
if ( V_25 == 0 ) {
V_10 = F_7 ( & V_12 ) ;
if ( V_10 < 0 )
return V_10 ;
V_25 = F_21 ( V_12 , 0 ) ;
V_27 = F_22 ( V_12 , 0 ) ;
V_6 -> V_12 = V_12 ;
}
F_12 ( L_6 , V_2 -> V_35 , V_25 ) ;
if ( ! F_23 ( V_25 , V_36 , L_7 ) ) {
F_12 ( L_8 ) ;
return - V_37 ;
}
V_2 -> V_25 = V_25 ;
#ifdef F_24
{
int V_13 ;
F_12 ( L_9 ) ;
for ( V_13 = 0 ; V_13 < 16 ; V_13 += 2 ) {
F_12 ( L_10 , F_25 ( V_2 -> V_25 + V_13 ) ,
F_26 ( V_2 -> V_25 + V_13 + 1 ) ) ;
}
}
#endif
V_26 = F_17 ( V_2 ) ;
if ( V_26 < 0 )
return - V_37 ;
V_2 -> V_38 = V_15 + V_26 ;
F_12 ( L_11 , V_39 . V_18 ) ;
V_2 -> V_40 = V_39 . V_18 ;
if ( V_27 != 0 ) {
if ( V_27 > 15 || V_41 [ V_27 ] == - 1 ) {
F_12 ( L_12 , V_27 ) ;
return - V_42 ;
}
F_12 ( L_13 , V_27 ) ;
V_10 = F_27 ( V_27 , V_43 , V_44 ,
L_7 , V_2 ) ;
if ( V_10 < 0 ) {
F_12 ( L_14 ) ;
return - V_42 ;
}
V_2 -> V_27 = V_27 ;
}
V_10 = F_28 ( V_2 , V_24 ) ;
if ( V_10 < 0 )
return V_10 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_2 ) ;
if ( V_2 -> V_25 )
F_31 ( V_2 -> V_25 , V_36 ) ;
if ( V_2 -> V_27 )
F_32 ( V_2 -> V_27 , V_2 ) ;
if ( V_6 -> V_12 )
F_14 ( V_6 -> V_12 ) ;
}
