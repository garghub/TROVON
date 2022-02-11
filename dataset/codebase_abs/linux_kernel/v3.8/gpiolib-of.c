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
F_4 ( L_2 , V_20 ) ;
return V_5 ;
}
F_5 ( & V_4 , F_1 ) ;
F_6 ( V_4 . V_7 . V_8 ) ;
F_4 ( L_3 , V_20 , V_4 . V_13 ) ;
return V_4 . V_13 ;
}
unsigned int F_7 ( struct V_15 * V_8 , const char * V_16 )
{
unsigned int V_21 = 0 ;
do {
int V_5 ;
V_5 = F_3 ( V_8 , V_16 , L_1 ,
V_21 , NULL ) ;
if ( V_5 < 0 && V_5 != - V_22 )
break;
} while ( ++ V_21 );
return V_21 ;
}
int F_8 ( struct V_1 * V_2 ,
const struct V_23 * V_7 , T_1 * V_12 )
{
if ( V_2 -> V_9 < 2 ) {
F_9 ( 1 ) ;
return - V_24 ;
}
if ( F_9 ( V_7 -> V_10 < V_2 -> V_9 ) )
return - V_24 ;
if ( V_7 -> args [ 0 ] >= V_2 -> V_25 )
return - V_24 ;
if ( V_12 )
* V_12 = V_7 -> args [ 1 ] ;
return V_7 -> args [ 0 ] ;
}
int F_10 ( struct V_15 * V_8 ,
struct V_26 * V_27 )
{
int V_5 = - V_28 ;
struct V_1 * V_2 = & V_27 -> V_2 ;
V_2 -> V_29 = F_11 ( V_8 -> V_30 , V_31 ) ;
if ( ! V_2 -> V_29 )
goto V_32;
V_27 -> V_33 = F_12 ( V_8 , 0 ) ;
if ( ! V_27 -> V_33 )
goto V_34;
V_2 -> V_14 = - 1 ;
if ( V_27 -> V_35 )
V_27 -> V_35 ( V_27 ) ;
V_27 -> V_2 . V_6 = V_8 ;
V_5 = F_13 ( V_2 ) ;
if ( V_5 )
goto V_36;
return 0 ;
V_36:
F_14 ( V_27 -> V_33 ) ;
V_34:
F_15 ( V_2 -> V_29 ) ;
V_32:
F_16 ( L_4 ,
V_8 -> V_30 , V_5 ) ;
return V_5 ;
}
static void F_17 ( struct V_1 * V_37 )
{
struct V_15 * V_8 = V_37 -> V_6 ;
struct V_23 V_38 ;
struct V_39 * V_40 ;
int V_17 = 0 , V_5 ;
if ( ! V_8 )
return;
do {
V_5 = F_3 ( V_8 , L_5 ,
L_6 , V_17 , & V_38 ) ;
if ( V_5 )
break;
V_40 = F_18 ( V_38 . V_8 ) ;
if ( ! V_40 )
break;
V_5 = F_19 ( V_37 ,
F_20 ( V_40 ) ,
0 ,
V_38 . args [ 0 ] ,
V_38 . args [ 1 ] ) ;
if ( V_5 )
break;
} while ( V_17 ++ );
}
static void F_17 ( struct V_1 * V_37 ) {}
void F_21 ( struct V_1 * V_37 )
{
if ( ( ! V_37 -> V_6 ) && ( V_37 -> V_41 ) )
V_37 -> V_6 = V_37 -> V_41 -> V_6 ;
if ( ! V_37 -> V_6 )
return;
if ( ! V_37 -> V_11 ) {
V_37 -> V_9 = 2 ;
V_37 -> V_11 = F_8 ;
}
F_17 ( V_37 ) ;
F_22 ( V_37 -> V_6 ) ;
}
void F_23 ( struct V_1 * V_37 )
{
F_24 ( V_37 ) ;
if ( V_37 -> V_6 )
F_6 ( V_37 -> V_6 ) ;
}
