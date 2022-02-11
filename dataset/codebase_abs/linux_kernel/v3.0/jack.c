static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 )
V_4 -> V_6 ( V_4 ) ;
if ( V_4 -> V_7 )
F_2 ( V_4 -> V_8 ) ;
else
F_3 ( V_4 -> V_8 ) ;
F_4 ( V_4 -> V_9 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 = V_2 -> V_11 ;
int V_12 , V_13 ;
snprintf ( V_4 -> V_14 , sizeof( V_4 -> V_14 ) , L_1 ,
V_11 -> V_15 , V_4 -> V_9 ) ;
V_4 -> V_8 -> V_14 = V_4 -> V_14 ;
if ( ! V_4 -> V_8 -> V_16 . V_17 )
V_4 -> V_8 -> V_16 . V_17 = F_6 ( V_11 ) ;
for ( V_13 = 0 ; V_13 < F_7 ( V_4 -> V_18 ) ; V_13 ++ ) {
int V_19 = V_20 >> V_13 ;
if ( ! ( V_4 -> type & V_19 ) )
continue;
if ( ! V_4 -> V_18 [ V_13 ] )
V_4 -> V_18 [ V_13 ] = V_21 + V_13 ;
F_8 ( V_4 -> V_8 , V_22 , V_4 -> V_18 [ V_13 ] ) ;
}
V_12 = F_9 ( V_4 -> V_8 ) ;
if ( V_12 == 0 )
V_4 -> V_7 = 1 ;
return V_12 ;
}
int F_10 ( struct V_10 * V_11 , const char * V_9 , int type ,
struct V_3 * * V_23 )
{
struct V_3 * V_4 ;
int V_12 ;
int V_13 ;
static struct V_24 V_25 = {
. V_26 = F_1 ,
. V_27 = F_5 ,
} ;
V_4 = F_11 ( sizeof( struct V_3 ) , V_28 ) ;
if ( V_4 == NULL )
return - V_29 ;
V_4 -> V_9 = F_12 ( V_9 , V_28 ) ;
V_4 -> V_8 = F_13 () ;
if ( V_4 -> V_8 == NULL ) {
V_12 = - V_29 ;
goto V_30;
}
V_4 -> V_8 -> V_31 = L_2 ;
V_4 -> type = type ;
for ( V_13 = 0 ; V_13 < F_7 ( V_32 ) ; V_13 ++ )
if ( type & ( 1 << V_13 ) )
F_8 ( V_4 -> V_8 , V_33 ,
V_32 [ V_13 ] ) ;
V_12 = F_14 ( V_11 , V_34 , V_4 , & V_25 ) ;
if ( V_12 < 0 )
goto V_30;
* V_23 = V_4 ;
return 0 ;
V_30:
F_3 ( V_4 -> V_8 ) ;
F_4 ( V_4 -> V_9 ) ;
F_4 ( V_4 ) ;
return V_12 ;
}
void F_15 ( struct V_3 * V_4 , struct V_2 * V_17 )
{
F_16 ( V_4 -> V_7 ) ;
V_4 -> V_8 -> V_16 . V_17 = V_17 ;
}
int F_17 ( struct V_3 * V_4 , enum V_35 type ,
int V_36 )
{
int V_18 = F_18 ( V_20 ) - F_18 ( type ) ;
F_16 ( V_4 -> V_7 ) ;
if ( ! V_36 || V_18 >= F_7 ( V_4 -> V_18 ) )
return - V_37 ;
V_4 -> type |= type ;
V_4 -> V_18 [ V_18 ] = V_36 ;
return 0 ;
}
void F_19 ( struct V_3 * V_4 , int V_38 )
{
int V_13 ;
if ( ! V_4 )
return;
for ( V_13 = 0 ; V_13 < F_7 ( V_4 -> V_18 ) ; V_13 ++ ) {
int V_19 = V_20 >> V_13 ;
if ( V_4 -> type & V_19 )
F_20 ( V_4 -> V_8 , V_4 -> V_18 [ V_13 ] ,
V_38 & V_19 ) ;
}
for ( V_13 = 0 ; V_13 < F_7 ( V_32 ) ; V_13 ++ ) {
int V_19 = 1 << V_13 ;
if ( V_4 -> type & V_19 )
F_21 ( V_4 -> V_8 ,
V_32 [ V_13 ] ,
V_38 & V_19 ) ;
}
F_22 ( V_4 -> V_8 ) ;
}
