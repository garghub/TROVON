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
return F_1 ( V_2 ) ;
}
void F_9 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = F_7 ( V_10 ) ;
F_5 ( V_2 ) ;
}
void F_10 ( struct V_15 * V_16 ,
struct V_17 * * V_18 , T_1 V_19 )
{
F_11 ( V_16 -> V_20 . V_21 ) ;
if ( ! V_19 || ! V_18 )
return;
do {
F_12 ( V_18 [ -- V_19 ] ) ;
V_18 [ V_19 ] = NULL ;
} while ( V_19 );
}
int F_13 ( struct V_1 * V_2 ,
struct V_17 * * V_22 , struct V_17 * * V_23 )
{
if ( V_2 -> V_24 )
return V_2 -> V_24 ( V_2 ,
V_22 ,
V_23 ) ;
return - V_25 ;
}
void F_14 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 )
V_2 -> V_26 ( V_2 ) ;
}
void F_15 ( struct V_1 * V_2 )
{
if ( V_2 -> V_27 ) {
V_2 -> V_27 ( V_2 ) ;
V_2 -> V_28 = true ;
}
}
int F_16 ( struct V_1 * V_2 )
{
int V_4 ;
if ( V_2 -> V_29 && V_2 -> V_28 ) {
V_4 = V_2 -> V_29 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_28 = false ;
}
return 0 ;
}
int F_17 ( struct V_1 * V_2 ,
enum V_30 V_31 )
{
if ( V_2 -> V_32 )
return V_2 -> V_32 ( V_2 , V_31 ) ;
return 0 ;
}
struct V_1 * F_18 ( struct V_15 * V_16 ,
enum V_33 type , int V_34 )
{
struct V_35 * V_20 = & V_16 -> V_20 ;
struct V_1 * V_2 ;
switch ( type ) {
case V_36 :
case V_37 :
V_2 = F_19 ( V_16 , type , V_34 ) ;
break;
case V_38 :
V_2 = F_20 ( V_16 , V_34 ) ;
break;
case V_39 :
V_2 = F_21 ( V_16 , V_34 ) ;
break;
default:
V_2 = F_22 ( - V_40 ) ;
break;
}
if ( F_23 ( V_2 ) ) {
F_24 ( V_20 , L_5 , V_41 ) ;
return NULL ;
}
V_2 -> type = type ;
F_3 ( L_6 , V_34 ) ;
return V_2 ;
}
