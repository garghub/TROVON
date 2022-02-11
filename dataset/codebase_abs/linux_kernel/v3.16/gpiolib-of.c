static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_4 = V_3 ;
int V_5 ;
if ( ( V_2 -> V_6 != V_4 -> V_7 . V_8 ) ||
( V_2 -> V_9 != V_4 -> V_7 . V_10 ) ||
( ! V_2 -> V_11 ) )
return false ;
V_5 = V_2 -> V_11 ( V_2 , & V_4 -> V_7 , V_4 -> V_12 ) ;
if ( V_5 < 0 )
return false ;
V_4 -> V_13 = F_2 ( V_2 , V_5 ) ;
return true ;
}
struct V_14 * F_3 ( struct V_15 * V_8 ,
const char * V_16 , int V_17 , enum V_18 * V_12 )
{
struct V_4 V_4 = {
. V_12 = V_12 ,
. V_13 = F_4 (-EPROBE_DEFER)
} ;
int V_5 ;
if ( V_12 )
* V_12 = 0 ;
V_5 = F_5 ( V_8 , V_16 , L_1 , V_17 ,
& V_4 . V_7 ) ;
if ( V_5 ) {
F_6 ( L_2 ,
V_19 , V_8 -> V_20 , V_17 ) ;
return F_4 ( V_5 ) ;
}
F_7 ( & V_4 , F_1 ) ;
F_8 ( V_4 . V_7 . V_8 ) ;
F_6 ( L_3 , V_19 ,
F_9 ( V_4 . V_13 ) ) ;
return V_4 . V_13 ;
}
int F_10 ( struct V_15 * V_8 , const char * V_21 ,
int V_17 , enum V_18 * V_12 )
{
struct V_14 * V_22 ;
V_22 = F_3 ( V_8 , V_21 , V_17 , V_12 ) ;
if ( F_11 ( V_22 ) )
return F_12 ( V_22 ) ;
else
return F_13 ( V_22 ) ;
}
int F_14 ( struct V_1 * V_2 ,
const struct V_23 * V_7 , T_1 * V_12 )
{
if ( V_2 -> V_9 < 2 ) {
F_15 ( 1 ) ;
return - V_24 ;
}
if ( F_15 ( V_7 -> V_10 < V_2 -> V_9 ) )
return - V_24 ;
if ( V_7 -> args [ 0 ] >= V_2 -> V_25 )
return - V_24 ;
if ( V_12 )
* V_12 = V_7 -> args [ 1 ] ;
return V_7 -> args [ 0 ] ;
}
int F_16 ( struct V_15 * V_8 ,
struct V_26 * V_27 )
{
int V_5 = - V_28 ;
struct V_1 * V_2 = & V_27 -> V_2 ;
V_2 -> V_29 = F_17 ( V_8 -> V_20 , V_30 ) ;
if ( ! V_2 -> V_29 )
goto V_31;
V_27 -> V_32 = F_18 ( V_8 , 0 ) ;
if ( ! V_27 -> V_32 )
goto V_33;
V_2 -> V_34 = - 1 ;
if ( V_27 -> V_35 )
V_27 -> V_35 ( V_27 ) ;
V_27 -> V_2 . V_6 = V_8 ;
V_5 = F_19 ( V_2 ) ;
if ( V_5 )
goto V_36;
return 0 ;
V_36:
F_20 ( V_27 -> V_32 ) ;
V_33:
F_21 ( V_2 -> V_29 ) ;
V_31:
F_22 ( L_4 ,
V_8 -> V_20 , V_5 ) ;
return V_5 ;
}
static void F_23 ( struct V_1 * V_37 )
{
struct V_15 * V_8 = V_37 -> V_6 ;
struct V_23 V_38 ;
struct V_39 * V_40 ;
int V_17 = 0 , V_5 ;
const char * V_41 ;
static const char V_42 [] = L_5 ;
struct V_43 * V_44 ;
if ( ! V_8 )
return;
V_44 = F_24 ( V_8 , V_42 , NULL ) ;
for (; ; V_17 ++ ) {
V_5 = F_25 ( V_8 , L_6 , 3 ,
V_17 , & V_38 ) ;
if ( V_5 )
break;
V_40 = F_26 ( V_38 . V_8 ) ;
if ( ! V_40 )
break;
if ( V_38 . args [ 2 ] ) {
if ( V_44 ) {
V_5 = F_27 ( V_8 ,
V_42 ,
V_17 , & V_41 ) ;
if ( strlen ( V_41 ) ) {
F_22 ( L_7 ,
V_8 -> V_20 ) ;
break;
}
}
V_5 = F_28 ( V_37 ,
F_29 ( V_40 ) ,
V_38 . args [ 0 ] ,
V_38 . args [ 1 ] ,
V_38 . args [ 2 ] ) ;
if ( V_5 )
break;
} else {
if ( V_38 . args [ 1 ] ) {
F_22 ( L_8 ,
V_8 -> V_20 ) ;
break;
}
if ( ! V_44 ) {
F_22 ( L_9 ,
V_8 -> V_20 , V_42 ) ;
break;
}
V_5 = F_27 ( V_8 ,
V_42 ,
V_17 , & V_41 ) ;
if ( V_5 )
break;
if ( ! strlen ( V_41 ) ) {
F_22 ( L_10 ,
V_8 -> V_20 ) ;
break;
}
V_5 = F_30 ( V_37 , V_40 ,
V_38 . args [ 0 ] , V_41 ) ;
if ( V_5 )
break;
}
}
}
static void F_23 ( struct V_1 * V_37 ) {}
void F_31 ( struct V_1 * V_37 )
{
if ( ( ! V_37 -> V_6 ) && ( V_37 -> V_45 ) )
V_37 -> V_6 = V_37 -> V_45 -> V_6 ;
if ( ! V_37 -> V_6 )
return;
if ( ! V_37 -> V_11 ) {
V_37 -> V_9 = 2 ;
V_37 -> V_11 = F_14 ;
}
F_23 ( V_37 ) ;
F_32 ( V_37 -> V_6 ) ;
}
void F_33 ( struct V_1 * V_37 )
{
F_34 ( V_37 ) ;
if ( V_37 -> V_6 )
F_8 ( V_37 -> V_6 ) ;
}
