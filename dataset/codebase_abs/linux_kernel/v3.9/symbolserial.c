static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_5 = V_1 -> V_6 ;
struct V_7 * V_8 = V_3 -> V_8 ;
int V_9 = V_1 -> V_9 ;
int V_10 ;
int V_11 ;
switch ( V_9 ) {
case 0 :
break;
case - V_12 :
case - V_13 :
case - V_14 :
F_2 ( & V_8 -> V_15 , L_1 ,
V_16 , V_9 ) ;
return;
default:
F_2 ( & V_8 -> V_15 , L_2 ,
V_16 , V_9 ) ;
goto exit;
}
F_3 ( & V_8 -> V_15 , V_16 , V_1 -> V_17 , V_5 ) ;
if ( V_1 -> V_17 > 1 ) {
V_11 = V_1 -> V_17 - 1 ;
F_4 ( & V_8 -> V_8 , & V_5 [ 1 ] , V_11 ) ;
F_5 ( & V_8 -> V_8 ) ;
} else {
F_2 ( & V_3 -> V_18 -> V_15 ,
L_3
L_4 , V_1 -> V_17 ) ;
}
exit:
F_6 ( & V_3 -> V_19 ) ;
if ( ! V_3 -> V_20 ) {
F_7 ( V_3 -> V_21 , V_3 -> V_18 ,
F_8 ( V_3 -> V_18 ,
V_3 -> V_22 ) ,
V_3 -> V_23 , V_3 -> V_24 ,
F_1 , V_3 , V_3 -> V_25 ) ;
V_10 = F_9 ( V_3 -> V_21 , V_26 ) ;
if ( V_10 )
F_10 ( & V_8 -> V_15 ,
L_5 ,
V_16 , V_10 ) ;
} else
V_3 -> V_27 = true ;
F_11 ( & V_3 -> V_19 ) ;
}
static int F_12 ( struct V_28 * V_29 , struct V_7 * V_8 )
{
struct V_2 * V_3 = F_13 ( V_8 -> V_30 ) ;
unsigned long V_31 ;
int V_10 = 0 ;
F_14 ( & V_3 -> V_19 , V_31 ) ;
V_3 -> V_20 = false ;
V_3 -> V_27 = false ;
V_3 -> V_8 = V_8 ;
F_15 ( & V_3 -> V_19 , V_31 ) ;
F_7 ( V_3 -> V_21 , V_3 -> V_18 ,
F_8 ( V_3 -> V_18 , V_3 -> V_22 ) ,
V_3 -> V_23 , V_3 -> V_24 ,
F_1 , V_3 , V_3 -> V_25 ) ;
V_10 = F_9 ( V_3 -> V_21 , V_32 ) ;
if ( V_10 )
F_10 ( & V_8 -> V_15 ,
L_5 ,
V_16 , V_10 ) ;
return V_10 ;
}
static void F_16 ( struct V_7 * V_8 )
{
struct V_2 * V_3 = F_13 ( V_8 -> V_30 ) ;
F_17 ( V_3 -> V_21 ) ;
}
static void F_18 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_33 ;
struct V_2 * V_3 = F_13 ( V_8 -> V_30 ) ;
F_19 ( & V_3 -> V_19 ) ;
V_3 -> V_20 = true ;
F_20 ( & V_3 -> V_19 ) ;
}
static void F_21 ( struct V_28 * V_29 )
{
struct V_7 * V_8 = V_29 -> V_33 ;
struct V_2 * V_3 = F_13 ( V_8 -> V_30 ) ;
int V_10 ;
bool V_34 ;
F_19 ( & V_3 -> V_19 ) ;
V_3 -> V_20 = false ;
V_34 = V_3 -> V_27 ;
V_3 -> V_27 = false ;
F_20 ( & V_3 -> V_19 ) ;
if ( V_34 ) {
V_10 = F_9 ( V_3 -> V_21 , V_32 ) ;
if ( V_10 )
F_10 ( & V_8 -> V_15 ,
L_6 ,
V_16 , V_10 ) ;
}
}
static int F_22 ( struct V_35 * V_30 )
{
struct V_2 * V_3 ;
struct V_36 * V_37 ;
int V_38 ;
int V_39 = - V_40 ;
bool V_41 = false ;
V_3 = F_23 ( sizeof( * V_3 ) , V_32 ) ;
if ( V_3 == NULL ) {
F_10 ( & V_30 -> V_15 -> V_15 , L_7 , V_16 ) ;
return - V_40 ;
}
F_24 ( & V_3 -> V_19 ) ;
V_3 -> V_30 = V_30 ;
V_3 -> V_8 = V_30 -> V_8 [ 0 ] ;
V_3 -> V_18 = V_30 -> V_15 ;
V_37 = V_30 -> V_42 -> V_43 ;
for ( V_38 = 0 ; V_38 < V_37 -> V_44 . V_45 ; ++ V_38 ) {
struct V_46 * V_47 ;
V_47 = & V_37 -> V_47 [ V_38 ] . V_44 ;
if ( ! F_25 ( V_47 ) )
continue;
V_3 -> V_21 = F_26 ( 0 , V_32 ) ;
if ( ! V_3 -> V_21 ) {
F_10 ( & V_3 -> V_18 -> V_15 , L_8 ) ;
goto error;
}
V_3 -> V_24 = F_27 ( V_47 ) * 2 ;
V_3 -> V_23 = F_28 ( V_3 -> V_24 , V_32 ) ;
if ( ! V_3 -> V_23 ) {
F_10 ( & V_3 -> V_18 -> V_15 , L_8 ) ;
goto error;
}
V_3 -> V_22 = V_47 -> V_48 ;
V_3 -> V_25 = V_47 -> V_25 ;
F_7 ( V_3 -> V_21 , V_3 -> V_18 ,
F_8 ( V_3 -> V_18 ,
V_47 -> V_48 ) ,
V_3 -> V_23 , V_3 -> V_24 ,
F_1 , V_3 , V_3 -> V_25 ) ;
V_41 = true ;
break;
}
if ( ! V_41 ) {
F_10 ( & V_3 -> V_18 -> V_15 ,
L_9 ) ;
goto error;
}
F_29 ( V_30 , V_3 ) ;
return 0 ;
error:
F_30 ( V_3 -> V_21 ) ;
F_31 ( V_3 -> V_23 ) ;
F_31 ( V_3 ) ;
return V_39 ;
}
static void F_32 ( struct V_35 * V_30 )
{
struct V_2 * V_3 = F_13 ( V_30 ) ;
F_17 ( V_3 -> V_21 ) ;
F_30 ( V_3 -> V_21 ) ;
}
static void F_33 ( struct V_35 * V_30 )
{
struct V_2 * V_3 = F_13 ( V_30 ) ;
F_31 ( V_3 -> V_23 ) ;
F_31 ( V_3 ) ;
}
