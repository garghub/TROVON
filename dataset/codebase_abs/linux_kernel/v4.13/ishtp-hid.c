static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 ;
V_8 = F_2 ( V_2 , V_7 -> V_9 [ V_4 -> V_10 ] ,
V_7 -> V_11 [ V_4 -> V_10 ] ) ;
if ( V_8 )
return V_8 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_4 ( struct V_1 * V_2 )
{
}
static int F_5 ( struct V_1 * V_2 )
{
return 0 ;
}
static void F_6 ( struct V_1 * V_2 )
{
}
static int F_7 ( struct V_1 * V_12 , unsigned char V_13 ,
T_1 * V_14 , T_2 V_15 , unsigned char V_16 , int V_17 )
{
return 0 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_18 * V_19 ,
int V_17 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
unsigned int V_15 = ( ( V_19 -> V_20 - 1 ) >> 3 ) + 1 + ( V_19 -> V_21 > 0 ) ;
char * V_14 ;
unsigned int V_22 = sizeof( struct V_23 ) ;
V_15 += V_22 ;
V_4 -> V_24 = false ;
switch ( V_17 ) {
case V_25 :
F_9 ( V_2 , V_19 -> V_21 , V_19 -> type ) ;
break;
case V_26 :
V_14 = F_10 ( V_15 + 7 , V_27 ) ;
if ( ! V_14 )
return;
F_11 ( V_19 , V_14 + V_22 ) ;
F_12 ( V_2 , V_14 , V_15 , V_19 -> V_21 ) ;
F_13 ( V_14 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = V_4 -> V_7 ;
int V_8 ;
F_15 ( V_7 , L_1 , V_28 , V_2 ) ;
V_8 = F_16 ( V_4 -> V_7 ) ;
if ( V_8 )
return V_8 ;
if ( ! V_4 -> V_24 )
F_17 ( V_4 -> V_29 ,
V_4 -> V_24 , 3 * V_30 ) ;
if ( ! V_4 -> V_24 ) {
F_18 ( V_2 ,
L_2 ) ;
return - V_31 ;
}
F_15 ( V_7 , L_3 , V_28 , V_2 ) ;
V_4 -> V_24 = false ;
return 0 ;
}
void F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
V_4 -> V_24 = true ;
F_20 ( & V_4 -> V_29 ) ;
}
int F_21 ( unsigned int V_32 ,
struct V_6 * V_7 )
{
int V_8 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
V_2 = F_22 () ;
if ( F_23 ( V_2 ) ) {
V_8 = F_24 ( V_2 ) ;
return - V_33 ;
}
V_4 = F_10 ( sizeof( * V_4 ) , V_27 ) ;
if ( ! V_4 ) {
V_8 = - V_33 ;
goto V_34;
}
V_4 -> V_10 = V_32 ;
V_4 -> V_7 = V_7 ;
F_25 ( & V_4 -> V_29 ) ;
V_2 -> V_5 = V_4 ;
V_7 -> V_35 [ V_32 ] = V_2 ;
V_2 -> V_36 = & V_37 ;
V_2 -> V_38 = V_39 ;
V_2 -> V_40 . V_41 = & V_7 -> V_42 -> V_40 ;
V_2 -> V_43 = F_26 ( V_44 ) ;
V_2 -> V_45 = F_26 ( V_46 ) ;
V_2 -> V_47 = F_26 ( V_48 ) ;
snprintf ( V_2 -> V_49 , sizeof( V_2 -> V_49 ) , L_4 , L_5 ,
V_2 -> V_45 , V_2 -> V_47 ) ;
V_8 = F_27 ( V_2 ) ;
if ( V_8 )
goto V_50;
F_15 ( V_7 , L_6 , V_28 , V_2 ) ;
return 0 ;
V_50:
F_13 ( V_4 ) ;
V_34:
F_13 ( V_2 ) ;
return V_8 ;
}
void F_28 ( struct V_6 * V_7 )
{
int V_51 ;
for ( V_51 = 0 ; V_51 < V_7 -> V_52 ; ++ V_51 ) {
if ( V_7 -> V_35 [ V_51 ] ) {
F_13 ( V_7 -> V_35 [ V_51 ] -> V_5 ) ;
F_29 ( V_7 -> V_35 [ V_51 ] ) ;
V_7 -> V_35 [ V_51 ] = NULL ;
}
}
}
