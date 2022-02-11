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
V_4 -> V_13 = V_5 + V_2 -> V_14 ;
return true ;
}
int F_2 ( struct V_15 * V_8 , const char * V_16 ,
int V_17 , enum V_18 * V_12 )
{
struct V_4 V_4 = { . V_12 = V_12 , . V_13 = - V_19 } ;
int V_5 ;
if ( V_12 )
* V_12 = 0 ;
V_5 = F_3 ( V_8 , V_16 , L_1 , V_17 ,
& V_4 . V_7 ) ;
if ( V_5 ) {
F_4 ( L_2 ,
V_20 , V_8 -> V_21 , V_17 ) ;
return V_5 ;
}
F_5 ( & V_4 , F_1 ) ;
F_6 ( V_4 . V_7 . V_8 ) ;
F_4 ( L_3 , V_20 , V_4 . V_13 ) ;
return V_4 . V_13 ;
}
int F_7 ( struct V_1 * V_2 ,
const struct V_22 * V_7 , T_1 * V_12 )
{
if ( V_2 -> V_9 < 2 ) {
F_8 ( 1 ) ;
return - V_23 ;
}
if ( F_8 ( V_7 -> V_10 < V_2 -> V_9 ) )
return - V_23 ;
if ( V_7 -> args [ 0 ] >= V_2 -> V_24 )
return - V_23 ;
if ( V_12 )
* V_12 = V_7 -> args [ 1 ] ;
return V_7 -> args [ 0 ] ;
}
int F_9 ( struct V_15 * V_8 ,
struct V_25 * V_26 )
{
int V_5 = - V_27 ;
struct V_1 * V_2 = & V_26 -> V_2 ;
V_2 -> V_28 = F_10 ( V_8 -> V_21 , V_29 ) ;
if ( ! V_2 -> V_28 )
goto V_30;
V_26 -> V_31 = F_11 ( V_8 , 0 ) ;
if ( ! V_26 -> V_31 )
goto V_32;
V_2 -> V_14 = - 1 ;
if ( V_26 -> V_33 )
V_26 -> V_33 ( V_26 ) ;
V_26 -> V_2 . V_6 = V_8 ;
V_5 = F_12 ( V_2 ) ;
if ( V_5 )
goto V_34;
return 0 ;
V_34:
F_13 ( V_26 -> V_31 ) ;
V_32:
F_14 ( V_2 -> V_28 ) ;
V_30:
F_15 ( L_4 ,
V_8 -> V_21 , V_5 ) ;
return V_5 ;
}
static void F_16 ( struct V_1 * V_35 )
{
struct V_15 * V_8 = V_35 -> V_6 ;
struct V_22 V_36 ;
struct V_37 * V_38 ;
int V_17 = 0 , V_5 ;
if ( ! V_8 )
return;
for (; ; V_17 ++ ) {
V_5 = F_17 ( V_8 , L_5 , 3 ,
V_17 , & V_36 ) ;
if ( V_5 )
break;
V_38 = F_18 ( V_36 . V_8 ) ;
if ( ! V_38 )
break;
V_5 = F_19 ( V_35 ,
F_20 ( V_38 ) ,
V_36 . args [ 0 ] ,
V_36 . args [ 1 ] ,
V_36 . args [ 2 ] ) ;
if ( V_5 )
break;
}
}
static void F_16 ( struct V_1 * V_35 ) {}
void F_21 ( struct V_1 * V_35 )
{
if ( ( ! V_35 -> V_6 ) && ( V_35 -> V_39 ) )
V_35 -> V_6 = V_35 -> V_39 -> V_6 ;
if ( ! V_35 -> V_6 )
return;
if ( ! V_35 -> V_11 ) {
V_35 -> V_9 = 2 ;
V_35 -> V_11 = F_7 ;
}
F_16 ( V_35 ) ;
F_22 ( V_35 -> V_6 ) ;
}
void F_23 ( struct V_1 * V_35 )
{
F_24 ( V_35 ) ;
if ( V_35 -> V_6 )
F_6 ( V_35 -> V_6 ) ;
}
