static int F_1 ( struct V_1 * V_2 )
{
int V_3 , V_4 = 0 ;
if ( F_2 ( V_2 -> V_5 ) )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_6 ; V_3 ++ ) {
V_4 = V_2 -> V_7 [ V_3 ] ( V_2 ) ;
F_3 ( L_1 ,
V_4 ? L_2 : L_3 , V_3 + 1 ) ;
if ( ! V_4 )
break;
}
if ( V_4 ) {
F_4 ( L_4 ) ;
return V_4 ;
}
V_2 -> V_5 = true ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
if ( F_2 ( ! V_2 -> V_5 ) )
return;
V_2 -> V_8 ( V_2 ) ;
V_2 -> V_5 = false ;
}
long F_6 ( struct V_9 * V_10 ,
unsigned long V_11 , unsigned long * V_12 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
if ( V_11 < V_2 -> V_13 )
return V_2 -> V_13 ;
else if ( V_11 > V_2 -> V_14 )
return V_2 -> V_14 ;
else
return V_11 ;
}
int F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
int V_4 ;
if ( V_2 -> V_15 ) {
V_4 = V_2 -> V_15 ( V_2 ) ;
if ( V_4 )
goto error;
}
V_4 = F_1 ( V_2 ) ;
error:
return V_4 ;
}
void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
if ( V_2 -> V_16 )
V_2 -> V_16 ( V_2 ) ;
F_5 ( V_2 ) ;
}
void F_10 ( struct V_17 * V_18 ,
struct V_19 * * V_20 , T_1 V_21 )
{
F_11 ( V_18 -> V_22 . V_23 ) ;
if ( ! V_21 || ! V_20 )
return;
do {
F_12 ( V_20 [ -- V_21 ] ) ;
V_20 [ V_21 ] = NULL ;
} while ( V_21 );
}
int F_13 ( struct V_1 * V_2 ,
struct V_19 * * V_24 , struct V_19 * * V_25 )
{
if ( V_2 -> V_26 )
return V_2 -> V_26 ( V_2 ,
V_24 ,
V_25 ) ;
return - V_27 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_28 )
V_2 -> V_28 ( V_2 ) ;
}
struct V_1 * F_15 ( struct V_17 * V_18 ,
enum V_29 type , int V_30 )
{
struct V_31 * V_22 = & V_18 -> V_22 ;
struct V_1 * V_2 ;
switch ( type ) {
case V_32 :
case V_33 :
V_2 = F_16 ( V_18 , type , V_30 ) ;
break;
default:
V_2 = F_17 ( - V_34 ) ;
break;
}
if ( F_18 ( V_2 ) ) {
F_19 ( V_22 , L_5 , V_35 ) ;
return NULL ;
}
V_2 -> type = type ;
F_3 ( L_6 , V_30 ) ;
return V_2 ;
}
