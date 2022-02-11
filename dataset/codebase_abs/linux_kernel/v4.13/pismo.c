static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 -> V_6 . V_7 ) ;
struct V_8 * V_9 = F_3 ( V_5 ) ;
V_9 -> V_10 ( V_9 -> V_11 , V_3 ) ;
}
static unsigned int F_4 ( unsigned int V_12 )
{
V_12 &= 15 ;
if ( V_12 > 2 )
return 0 ;
return 1 << V_12 ;
}
static int F_5 ( struct V_4 * V_5 , void * V_13 , T_1 V_14 ,
T_2 V_15 )
{
int V_16 ;
struct V_17 V_18 [] = {
{
. V_14 = V_5 -> V_14 ,
. V_19 = sizeof( V_14 ) ,
. V_13 = & V_14 ,
} , {
. V_14 = V_5 -> V_14 ,
. V_20 = V_21 ,
. V_19 = V_15 ,
. V_13 = V_13 ,
} ,
} ;
V_16 = F_6 ( V_5 -> V_22 , V_18 , F_7 ( V_18 ) ) ;
return V_16 == F_7 ( V_18 ) ? V_15 : - V_23 ;
}
static int F_8 ( struct V_8 * V_9 , int V_24 ,
struct V_25 * V_26 , const char * V_27 ,
void * V_28 , T_2 V_29 )
{
struct V_1 * V_6 ;
struct V_30 V_31 = { } ;
T_3 V_32 = V_26 -> V_32 ;
int V_16 ;
if ( V_32 == ~ 0 )
return - V_33 ;
V_31 . V_34 = V_32 ;
V_31 . V_35 = V_32 + V_26 -> V_15 - 1 ;
V_31 . V_20 = V_36 ;
V_6 = F_9 ( V_27 , V_24 ) ;
if ( ! V_6 )
return - V_37 ;
V_6 -> V_6 . V_7 = & V_9 -> V_5 -> V_6 ;
do {
V_16 = F_10 ( V_6 , & V_31 , 1 ) ;
if ( V_16 )
break;
V_16 = F_11 ( V_6 , V_28 , V_29 ) ;
if ( V_16 )
break;
V_16 = F_12 ( V_6 ) ;
if ( V_16 )
break;
V_9 -> V_6 [ V_24 ] = V_6 ;
return 0 ;
} while ( 0 );
F_13 ( V_6 ) ;
return V_16 ;
}
static int F_14 ( struct V_8 * V_9 , int V_24 ,
struct V_25 * V_26 )
{
struct V_38 V_39 = {
. V_12 = V_26 -> V_12 ,
} ;
if ( V_9 -> V_10 )
V_39 . V_40 = F_1 ;
return F_8 ( V_9 , V_24 , V_26 , L_1 ,
& V_39 , sizeof( V_39 ) ) ;
}
static int F_15 ( struct V_8 * V_9 , int V_24 ,
struct V_25 * V_26 )
{
struct V_41 V_39 = {
. V_42 = V_26 -> V_12 ,
} ;
return F_8 ( V_9 , V_24 , V_26 , L_2 ,
& V_39 , sizeof( V_39 ) ) ;
}
static void F_16 ( struct V_8 * V_9 , int V_24 ,
const struct V_43 * V_44 , T_3 V_32 )
{
struct V_45 * V_6 = & V_9 -> V_5 -> V_6 ;
struct V_25 V_26 ;
V_26 . V_32 = V_32 ;
V_26 . type = V_44 -> type ;
V_26 . V_12 = F_4 ( V_44 -> V_12 ) ;
V_26 . V_46 = F_17 ( V_44 -> V_46 ) ;
V_26 . V_15 = F_18 ( V_44 -> V_15 ) ;
if ( V_26 . V_12 == 0 ) {
F_19 ( V_6 , L_3 , V_24 , V_44 -> V_12 ) ;
return;
}
F_20 ( V_6 , L_4 ,
V_24 , V_44 -> V_45 , V_26 . type , V_26 . V_46 , V_26 . V_15 / 1024 ) ;
switch ( V_26 . type ) {
case 0 :
break;
case 1 :
break;
case 2 :
F_14 ( V_9 , V_24 , & V_26 ) ;
break;
case 3 :
F_15 ( V_9 , V_24 , & V_26 ) ;
break;
}
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_8 * V_9 = F_3 ( V_5 ) ;
int V_24 ;
for ( V_24 = 0 ; V_24 < F_7 ( V_9 -> V_6 ) ; V_24 ++ )
F_22 ( V_9 -> V_6 [ V_24 ] ) ;
F_23 ( V_9 ) ;
return 0 ;
}
static int F_24 ( struct V_4 * V_5 ,
const struct V_47 * V_48 )
{
struct V_49 * V_22 = F_25 ( V_5 -> V_6 . V_7 ) ;
struct V_50 * V_28 = V_5 -> V_6 . V_51 ;
struct V_52 V_53 ;
struct V_8 * V_9 ;
int V_16 , V_24 ;
if ( ! F_26 ( V_22 , V_54 ) ) {
F_19 ( & V_5 -> V_6 , L_5 ) ;
return - V_23 ;
}
V_9 = F_27 ( sizeof( * V_9 ) , V_55 ) ;
if ( ! V_9 )
return - V_37 ;
V_9 -> V_5 = V_5 ;
if ( V_28 ) {
V_9 -> V_10 = V_28 -> V_40 ;
V_9 -> V_11 = V_28 -> V_11 ;
}
F_28 ( V_5 , V_9 ) ;
V_16 = F_5 ( V_5 , & V_53 , 0 , sizeof( V_53 ) ) ;
if ( V_16 < 0 ) {
F_19 ( & V_5 -> V_6 , L_6 , V_16 ) ;
goto V_56;
}
F_20 ( & V_5 -> V_6 , L_7 , V_53 . V_57 ) ;
for ( V_24 = 0 ; V_24 < F_7 ( V_53 . V_44 ) ; V_24 ++ )
if ( V_53 . V_44 [ V_24 ] . type != 0xff )
F_16 ( V_9 , V_24 , & V_53 . V_44 [ V_24 ] ,
V_28 -> V_58 [ V_24 ] ) ;
return 0 ;
V_56:
F_23 ( V_9 ) ;
return V_16 ;
}
static int T_4 F_29 ( void )
{
F_30 ( sizeof( struct V_43 ) != 48 ) ;
F_30 ( sizeof( struct V_52 ) != 256 ) ;
return F_31 ( & V_59 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_59 ) ;
}
