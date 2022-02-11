static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
int V_9 = V_1 -> V_9 ;
struct V_10 * V_11 ;
int V_12 ;
int V_13 ;
switch ( V_9 ) {
case 0 :
break;
case - V_14 :
case - V_15 :
case - V_16 :
F_2 ( & V_8 -> V_17 , L_1 ,
V_18 , V_9 ) ;
return;
default:
F_2 ( & V_8 -> V_17 , L_2 ,
V_18 , V_9 ) ;
goto exit;
}
F_3 ( V_19 , & V_8 -> V_17 , V_18 , V_1 -> V_20 ,
V_5 ) ;
if ( V_1 -> V_20 > 1 ) {
V_13 = V_1 -> V_20 - 1 ;
V_11 = F_4 ( & V_8 -> V_8 ) ;
if ( V_11 ) {
F_5 ( V_11 , & V_5 [ 1 ] , V_13 ) ;
F_6 ( V_11 ) ;
F_7 ( V_11 ) ;
}
} else {
F_2 ( & V_3 -> V_21 -> V_17 ,
L_3
L_4 , V_1 -> V_20 ) ;
}
exit:
F_8 ( & V_3 -> V_22 ) ;
if ( ! V_3 -> V_23 ) {
F_9 ( V_3 -> V_24 , V_3 -> V_21 ,
F_10 ( V_3 -> V_21 ,
V_3 -> V_25 ) ,
V_3 -> V_26 , V_3 -> V_27 ,
F_1 , V_3 , V_3 -> V_28 ) ;
V_12 = F_11 ( V_3 -> V_24 , V_29 ) ;
if ( V_12 )
F_12 ( & V_8 -> V_17 ,
L_5 ,
V_18 , V_12 ) ;
} else
V_3 -> V_30 = true ;
F_13 ( & V_3 -> V_22 ) ;
}
static int F_14 ( struct V_10 * V_11 , struct V_7 * V_8 )
{
struct V_2 * V_3 = F_15 ( V_8 -> V_31 ) ;
unsigned long V_32 ;
int V_12 = 0 ;
F_16 ( & V_3 -> V_22 , V_32 ) ;
V_3 -> V_23 = false ;
V_3 -> V_30 = false ;
V_3 -> V_8 = V_8 ;
F_17 ( & V_3 -> V_22 , V_32 ) ;
F_9 ( V_3 -> V_24 , V_3 -> V_21 ,
F_10 ( V_3 -> V_21 , V_3 -> V_25 ) ,
V_3 -> V_26 , V_3 -> V_27 ,
F_1 , V_3 , V_3 -> V_28 ) ;
V_12 = F_11 ( V_3 -> V_24 , V_33 ) ;
if ( V_12 )
F_12 ( & V_8 -> V_17 ,
L_5 ,
V_18 , V_12 ) ;
return V_12 ;
}
static void F_18 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_15 ( V_8 -> V_31 ) ;
F_19 ( V_3 -> V_24 ) ;
}
static void F_20 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_34 ;
struct V_2 * V_3 = F_15 ( V_8 -> V_31 ) ;
F_21 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = true ;
F_22 ( & V_3 -> V_22 ) ;
}
static void F_23 ( struct V_10 * V_11 )
{
struct V_7 * V_8 = V_11 -> V_34 ;
struct V_2 * V_3 = F_15 ( V_8 -> V_31 ) ;
int V_12 ;
bool V_35 ;
F_21 ( & V_3 -> V_22 ) ;
V_3 -> V_23 = false ;
V_35 = V_3 -> V_30 ;
V_3 -> V_30 = false ;
F_22 ( & V_3 -> V_22 ) ;
if ( V_35 ) {
V_12 = F_11 ( V_3 -> V_24 , V_33 ) ;
if ( V_12 )
F_12 ( & V_8 -> V_17 ,
L_6 ,
V_18 , V_12 ) ;
}
}
static int F_24 ( struct V_36 * V_31 )
{
struct V_2 * V_3 ;
struct V_37 * V_38 ;
int V_39 ;
int V_40 = - V_41 ;
bool V_42 = false ;
V_3 = F_25 ( sizeof( * V_3 ) , V_33 ) ;
if ( V_3 == NULL ) {
F_12 ( & V_31 -> V_17 -> V_17 , L_7 , V_18 ) ;
return - V_41 ;
}
F_26 ( & V_3 -> V_22 ) ;
V_3 -> V_31 = V_31 ;
V_3 -> V_8 = V_31 -> V_8 [ 0 ] ;
V_3 -> V_21 = V_31 -> V_17 ;
V_38 = V_31 -> V_43 -> V_44 ;
for ( V_39 = 0 ; V_39 < V_38 -> V_45 . V_46 ; ++ V_39 ) {
struct V_47 * V_48 ;
V_48 = & V_38 -> V_48 [ V_39 ] . V_45 ;
if ( ! F_27 ( V_48 ) )
continue;
V_3 -> V_24 = F_28 ( 0 , V_33 ) ;
if ( ! V_3 -> V_24 ) {
F_12 ( & V_3 -> V_21 -> V_17 , L_8 ) ;
goto error;
}
V_3 -> V_27 = F_29 ( V_48 ) * 2 ;
V_3 -> V_26 = F_30 ( V_3 -> V_27 , V_33 ) ;
if ( ! V_3 -> V_26 ) {
F_12 ( & V_3 -> V_21 -> V_17 , L_8 ) ;
goto error;
}
V_3 -> V_25 = V_48 -> V_49 ;
V_3 -> V_28 = V_48 -> V_28 ;
F_9 ( V_3 -> V_24 , V_3 -> V_21 ,
F_10 ( V_3 -> V_21 ,
V_48 -> V_49 ) ,
V_3 -> V_26 , V_3 -> V_27 ,
F_1 , V_3 , V_3 -> V_28 ) ;
V_42 = true ;
break;
}
if ( ! V_42 ) {
F_12 ( & V_3 -> V_21 -> V_17 ,
L_9 ) ;
goto error;
}
F_31 ( V_31 , V_3 ) ;
return 0 ;
error:
F_32 ( V_3 -> V_24 ) ;
F_33 ( V_3 -> V_26 ) ;
F_33 ( V_3 ) ;
return V_40 ;
}
static void F_34 ( struct V_36 * V_31 )
{
struct V_2 * V_3 = F_15 ( V_31 ) ;
F_19 ( V_3 -> V_24 ) ;
F_32 ( V_3 -> V_24 ) ;
}
static void F_35 ( struct V_36 * V_31 )
{
struct V_2 * V_3 = F_15 ( V_31 ) ;
F_33 ( V_3 -> V_26 ) ;
F_33 ( V_3 ) ;
}
