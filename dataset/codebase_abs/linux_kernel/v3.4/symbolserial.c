static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
int V_9 = V_1 -> V_9 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
F_2 ( L_1 , V_14 , V_8 -> V_15 ) ;
switch ( V_9 ) {
case 0 :
break;
case - V_16 :
case - V_17 :
case - V_18 :
F_2 ( L_2 ,
V_14 , V_9 ) ;
return;
default:
F_2 ( L_3 ,
V_14 , V_9 ) ;
goto exit;
}
F_3 ( V_19 , & V_8 -> V_20 , V_14 , V_1 -> V_21 ,
V_5 ) ;
if ( V_1 -> V_21 > 1 ) {
V_13 = V_1 -> V_21 - 1 ;
V_11 = F_4 ( & V_8 -> V_8 ) ;
if ( V_11 ) {
F_5 ( V_11 , & V_5 [ 1 ] , V_13 ) ;
F_6 ( V_11 ) ;
F_7 ( V_11 ) ;
}
} else {
F_8 ( & V_3 -> V_22 -> V_20 ,
L_4
L_5 , V_1 -> V_21 ) ;
}
exit:
F_9 ( & V_3 -> V_23 ) ;
if ( ! V_3 -> V_24 ) {
F_10 ( V_3 -> V_25 , V_3 -> V_22 ,
F_11 ( V_3 -> V_22 ,
V_3 -> V_26 ) ,
V_3 -> V_27 , V_3 -> V_28 ,
F_1 , V_3 , V_3 -> V_29 ) ;
V_12 = F_12 ( V_3 -> V_25 , V_30 ) ;
if ( V_12 )
F_13 ( & V_8 -> V_20 ,
L_6 ,
V_14 , V_12 ) ;
} else
V_3 -> V_31 = true ;
F_14 ( & V_3 -> V_23 ) ;
}
static int F_15 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
struct V_2 * V_3 = F_16 ( V_8 -> V_32 ) ;
unsigned long V_33 ;
int V_12 = 0 ;
F_2 ( L_1 , V_14 , V_8 -> V_15 ) ;
F_17 ( & V_3 -> V_23 , V_33 ) ;
V_3 -> V_24 = false ;
V_3 -> V_31 = false ;
V_3 -> V_8 = V_8 ;
F_18 ( & V_3 -> V_23 , V_33 ) ;
F_10 ( V_3 -> V_25 , V_3 -> V_22 ,
F_11 ( V_3 -> V_22 , V_3 -> V_26 ) ,
V_3 -> V_27 , V_3 -> V_28 ,
F_1 , V_3 , V_3 -> V_29 ) ;
V_12 = F_12 ( V_3 -> V_25 , V_34 ) ;
if ( V_12 )
F_13 ( & V_8 -> V_20 ,
L_6 ,
V_14 , V_12 ) ;
return V_12 ;
}
static void F_19 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_16 ( V_8 -> V_32 ) ;
F_2 ( L_1 , V_14 , V_8 -> V_15 ) ;
F_20 ( V_3 -> V_25 ) ;
}
static void F_21 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_35 ;
struct V_2 * V_3 = F_16 ( V_8 -> V_32 ) ;
F_2 ( L_1 , V_14 , V_8 -> V_15 ) ;
F_22 ( & V_3 -> V_23 ) ;
V_3 -> V_24 = true ;
F_23 ( & V_3 -> V_23 ) ;
}
static void F_24 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_35 ;
struct V_2 * V_3 = F_16 ( V_8 -> V_32 ) ;
int V_12 ;
bool V_36 ;
F_2 ( L_1 , V_14 , V_8 -> V_15 ) ;
F_22 ( & V_3 -> V_23 ) ;
V_3 -> V_24 = false ;
V_36 = V_3 -> V_31 ;
V_3 -> V_31 = false ;
F_23 ( & V_3 -> V_23 ) ;
if ( V_36 ) {
V_12 = F_12 ( V_3 -> V_25 , V_34 ) ;
if ( V_12 )
F_13 ( & V_8 -> V_20 ,
L_7 ,
V_14 , V_12 ) ;
}
}
static int F_25 ( struct V_37 * V_32 )
{
struct V_2 * V_3 ;
struct V_38 * V_39 ;
int V_40 ;
int V_41 = - V_42 ;
bool V_43 = false ;
V_3 = F_26 ( sizeof( * V_3 ) , V_34 ) ;
if ( V_3 == NULL ) {
F_13 ( & V_32 -> V_20 -> V_20 , L_8 , V_14 ) ;
return - V_42 ;
}
F_27 ( & V_3 -> V_23 ) ;
V_3 -> V_32 = V_32 ;
V_3 -> V_8 = V_32 -> V_8 [ 0 ] ;
V_3 -> V_22 = V_32 -> V_20 ;
V_39 = V_32 -> V_44 -> V_45 ;
for ( V_40 = 0 ; V_40 < V_39 -> V_46 . V_47 ; ++ V_40 ) {
struct V_48 * V_49 ;
V_49 = & V_39 -> V_49 [ V_40 ] . V_46 ;
if ( ! F_28 ( V_49 ) )
continue;
V_3 -> V_25 = F_29 ( 0 , V_34 ) ;
if ( ! V_3 -> V_25 ) {
F_13 ( & V_3 -> V_22 -> V_20 , L_9 ) ;
goto error;
}
V_3 -> V_28 = F_30 ( V_49 ) * 2 ;
V_3 -> V_27 = F_31 ( V_3 -> V_28 , V_34 ) ;
if ( ! V_3 -> V_27 ) {
F_13 ( & V_3 -> V_22 -> V_20 , L_9 ) ;
goto error;
}
V_3 -> V_26 = V_49 -> V_50 ;
V_3 -> V_29 = V_49 -> V_29 ;
F_10 ( V_3 -> V_25 , V_3 -> V_22 ,
F_11 ( V_3 -> V_22 ,
V_49 -> V_50 ) ,
V_3 -> V_27 , V_3 -> V_28 ,
F_1 , V_3 , V_3 -> V_29 ) ;
V_43 = true ;
break;
}
if ( ! V_43 ) {
F_13 ( & V_3 -> V_22 -> V_20 ,
L_10 ) ;
goto error;
}
F_32 ( V_32 , V_3 ) ;
return 0 ;
error:
F_33 ( V_3 -> V_25 ) ;
F_34 ( V_3 -> V_27 ) ;
F_34 ( V_3 ) ;
return V_41 ;
}
static void F_35 ( struct V_37 * V_32 )
{
struct V_2 * V_3 = F_16 ( V_32 ) ;
F_2 ( L_11 , V_14 ) ;
F_20 ( V_3 -> V_25 ) ;
F_33 ( V_3 -> V_25 ) ;
}
static void F_36 ( struct V_37 * V_32 )
{
struct V_2 * V_3 = F_16 ( V_32 ) ;
F_2 ( L_11 , V_14 ) ;
F_34 ( V_3 -> V_27 ) ;
F_34 ( V_3 ) ;
}
