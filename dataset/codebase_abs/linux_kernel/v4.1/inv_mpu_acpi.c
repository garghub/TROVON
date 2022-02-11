static int T_1 F_1 ( const struct V_1 * V_2 )
{
V_3 = V_4 ;
return 0 ;
}
static int F_2 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_9 * V_10 )
{
struct V_11 V_12 = { V_13 , NULL } ;
int V_14 ;
T_2 V_15 ;
union V_16 * V_17 ;
V_15 = F_3 ( V_6 -> V_18 , L_1 , NULL , & V_12 ) ;
if ( F_4 ( V_15 ) )
return - V_19 ;
V_17 = V_12 . V_20 ;
for ( V_14 = 0 ; V_14 < V_17 -> V_21 . V_22 ; ++ V_14 ) {
union V_16 * V_23 ;
int V_24 ;
V_23 = & ( V_17 -> V_21 . V_25 [ V_14 ] ) ;
for ( V_24 = 0 ; V_24 < V_23 -> V_21 . V_22 ; ++ V_24 ) {
union V_16 * V_26 ;
V_26 = & ( V_23 -> V_21 . V_25 [ V_24 ] ) ;
if ( V_26 -> type == V_27 )
F_5 ( V_10 -> type , V_26 -> string . V_20 ,
sizeof( V_10 -> type ) ) ;
else if ( V_26 -> type == V_28 ) {
if ( V_26 -> integer . V_29 != V_8 -> V_30 ) {
V_10 -> V_30 = V_26 -> integer . V_29 ;
break;
}
}
}
}
F_6 ( V_12 . V_20 ) ;
return V_17 -> V_21 . V_22 ;
}
static int F_7 ( struct V_31 * V_32 , void * V_33 )
{
T_3 * V_30 = V_33 ;
if ( V_32 -> type == V_34 ) {
struct V_35 * V_36 ;
V_36 = & V_32 -> V_33 . V_37 ;
if ( V_36 -> type == V_38 ) {
if ( * V_30 )
* V_30 |= ( V_36 -> V_39 << 16 ) ;
else
* V_30 = V_36 -> V_39 ;
}
}
return 1 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned short * V_40 ,
unsigned short * V_41 )
{
const struct V_42 * V_43 ;
struct V_5 * V_6 ;
T_3 V_44 = 0 ;
F_9 ( V_45 ) ;
int V_46 ;
V_43 = F_10 ( V_8 -> V_47 . V_48 -> V_49 ,
& V_8 -> V_47 ) ;
if ( ! V_43 )
return - V_19 ;
V_6 = F_11 ( & V_8 -> V_47 ) ;
if ( ! V_6 )
return - V_19 ;
V_46 = F_12 ( V_6 , & V_45 ,
F_7 , & V_44 ) ;
if ( V_46 < 0 )
return V_46 ;
F_13 ( & V_45 ) ;
* V_40 = V_44 & 0x0000ffff ;
* V_41 = ( V_44 & 0xffff0000 ) >> 16 ;
return 0 ;
}
int F_14 ( struct V_50 * V_51 )
{
V_51 -> V_52 = NULL ;
if ( F_15 ( & V_51 -> V_8 -> V_47 ) ) {
struct V_9 V_10 ;
struct V_5 * V_6 ;
int V_46 = - 1 ;
V_6 = F_11 ( & V_51 -> V_8 -> V_47 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_16 ( V_53 ) ;
switch ( V_3 ) {
case V_4 :
V_46 = F_2 ( V_6 , V_51 -> V_8 ,
& V_10 ) ;
break;
default:
break;
}
if ( V_46 < 0 ) {
unsigned short V_54 , V_55 ;
V_46 = F_8 ( V_51 -> V_8 , & V_54 ,
& V_55 ) ;
if ( ! V_46 && V_55 ) {
char * V_56 ;
V_10 . V_30 = V_55 ;
F_5 ( V_10 . type , F_17 ( & V_6 -> V_47 ) ,
sizeof( V_10 . type ) ) ;
V_56 = strchr ( V_10 . type , ':' ) ;
if ( V_56 )
* V_56 = '\0' ;
F_18 ( V_10 . type , L_2 ,
sizeof( V_10 . type ) ) ;
} else
return 0 ;
}
V_51 -> V_52 = F_19 ( V_51 -> V_57 , & V_10 ) ;
if ( ! V_51 -> V_52 )
return - V_19 ;
}
return 0 ;
}
void F_20 ( struct V_50 * V_51 )
{
if ( V_51 -> V_52 )
F_21 ( V_51 -> V_52 ) ;
}
int F_14 ( struct V_50 * V_51 )
{
return 0 ;
}
void F_20 ( struct V_50 * V_51 )
{
}
