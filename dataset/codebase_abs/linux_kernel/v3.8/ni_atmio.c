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
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
V_14 = F_8 ( NULL ,
F_9 ( 'N' , 'I' , 'C' ) ,
F_10 ( V_17 [ V_15 ] .
V_18 ) , NULL ) ;
if ( V_14 == NULL || V_14 -> V_19 == NULL )
continue;
if ( F_11 ( V_14 ) < 0 ) {
F_12
( L_1 ,
V_17 [ V_15 ] . V_20 ) ;
continue;
}
if ( F_13 ( V_14 ) < 0 ) {
F_14 ( V_14 ) ;
return - V_21 ;
}
if ( ! F_15 ( V_14 , 0 )
|| ! F_16 ( V_14 , 0 ) ) {
F_14 ( V_14 ) ;
F_12 ( L_2 ) ;
return - V_22 ;
}
break;
}
if ( V_15 == V_16 )
return - V_23 ;
* V_2 = V_14 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_24 = F_18 ( V_2 , 511 ) ;
int V_15 ;
for ( V_15 = 0 ; V_15 < V_16 ; V_15 ++ ) {
if ( V_17 [ V_15 ] . V_24 == V_24 )
return V_15 ;
}
if ( V_24 == 255 )
F_12 ( L_3 ) ;
else if ( V_24 == 0 )
F_12 ( L_4 ) ;
else
F_12 ( L_5 , V_24 ) ;
return - 1 ;
}
static int F_19 ( struct V_1 * V_2 ,
struct V_25 * V_26 )
{
struct V_5 * V_6 ;
struct V_13 * V_14 ;
int V_12 ;
unsigned long V_27 ;
int V_28 ;
unsigned int V_29 ;
V_12 = F_20 ( V_2 ) ;
if ( V_12 )
return V_12 ;
V_6 = V_2 -> V_7 ;
V_6 -> V_30 = & F_1 ;
V_6 -> V_31 = & F_5 ;
V_6 -> V_32 = & V_33 ;
V_6 -> V_34 = & V_35 ;
V_27 = V_26 -> V_36 [ 0 ] ;
V_29 = V_26 -> V_36 [ 1 ] ;
V_14 = NULL ;
if ( V_27 == 0 ) {
V_12 = F_7 ( & V_14 ) ;
if ( V_12 < 0 )
return V_12 ;
V_27 = F_21 ( V_14 , 0 ) ;
V_29 = F_22 ( V_14 , 0 ) ;
V_6 -> V_14 = V_14 ;
}
F_12 ( L_6 , V_2 -> V_37 , V_27 ) ;
if ( ! F_23 ( V_27 , V_38 , L_7 ) ) {
F_12 ( L_8 ) ;
return - V_39 ;
}
V_2 -> V_27 = V_27 ;
#ifdef F_24
{
int V_15 ;
F_12 ( L_9 ) ;
for ( V_15 = 0 ; V_15 < 16 ; V_15 += 2 ) {
F_12 ( L_10 , F_25 ( V_2 -> V_27 + V_15 ) ,
F_26 ( V_2 -> V_27 + V_15 + 1 ) ) ;
}
}
#endif
V_28 = F_17 ( V_2 ) ;
if ( V_28 < 0 )
return - V_39 ;
V_2 -> V_40 = V_17 + V_28 ;
F_12 ( L_11 , V_41 . V_20 ) ;
V_2 -> V_42 = V_41 . V_20 ;
if ( V_29 != 0 ) {
if ( V_29 > 15 || V_43 [ V_29 ] == - 1 ) {
F_12 ( L_12 , V_29 ) ;
return - V_44 ;
}
F_12 ( L_13 , V_29 ) ;
V_12 = F_27 ( V_29 , V_45 , V_46 ,
L_7 , V_2 ) ;
if ( V_12 < 0 ) {
F_12 ( L_14 ) ;
return - V_44 ;
}
V_2 -> V_29 = V_29 ;
}
V_12 = F_28 ( V_2 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_30 ( V_2 ) ;
if ( V_2 -> V_27 )
F_31 ( V_2 -> V_27 , V_38 ) ;
if ( V_2 -> V_29 )
F_32 ( V_2 -> V_29 , V_2 ) ;
if ( V_6 -> V_14 )
F_14 ( V_6 -> V_14 ) ;
}
