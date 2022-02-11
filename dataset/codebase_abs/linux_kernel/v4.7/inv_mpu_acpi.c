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
int V_18 ;
V_15 = F_3 ( V_6 -> V_19 , L_1 , NULL , & V_12 ) ;
if ( F_4 ( V_15 ) )
return - V_20 ;
V_17 = V_12 . V_21 ;
for ( V_14 = 0 ; V_14 < V_17 -> V_22 . V_23 ; ++ V_14 ) {
union V_16 * V_24 ;
int V_25 ;
V_24 = & V_17 -> V_22 . V_26 [ V_14 ] ;
for ( V_25 = 0 ; V_25 < V_24 -> V_22 . V_23 ; ++ V_25 ) {
union V_16 * V_27 ;
V_27 = & V_24 -> V_22 . V_26 [ V_25 ] ;
if ( V_27 -> type == V_28 )
F_5 ( V_10 -> type , V_27 -> string . V_21 ,
sizeof( V_10 -> type ) ) ;
else if ( V_27 -> type == V_29 ) {
if ( V_27 -> integer . V_30 != V_8 -> V_31 ) {
V_10 -> V_31 = V_27 -> integer . V_30 ;
break;
}
}
}
}
V_18 = V_17 -> V_22 . V_23 ;
F_6 ( V_12 . V_21 ) ;
return V_18 ;
}
static int F_7 ( struct V_32 * V_33 , void * V_34 )
{
T_3 * V_31 = V_34 ;
if ( V_33 -> type == V_35 ) {
struct V_36 * V_37 ;
V_37 = & V_33 -> V_34 . V_38 ;
if ( V_37 -> type == V_39 ) {
if ( * V_31 )
* V_31 |= ( V_37 -> V_40 << 16 ) ;
else
* V_31 = V_37 -> V_40 ;
}
}
return 1 ;
}
static int F_8 ( struct V_7 * V_8 ,
unsigned short * V_41 ,
unsigned short * V_42 )
{
const struct V_43 * V_44 ;
struct V_5 * V_6 ;
T_3 V_45 = 0 ;
F_9 ( V_46 ) ;
int V_18 ;
V_44 = F_10 ( V_8 -> V_47 . V_48 -> V_49 ,
& V_8 -> V_47 ) ;
if ( ! V_44 )
return - V_20 ;
V_6 = F_11 ( & V_8 -> V_47 ) ;
if ( ! V_6 )
return - V_20 ;
V_18 = F_12 ( V_6 , & V_46 ,
F_7 , & V_45 ) ;
if ( V_18 < 0 )
return V_18 ;
F_13 ( & V_46 ) ;
* V_41 = V_45 & 0x0000ffff ;
* V_42 = ( V_45 & 0xffff0000 ) >> 16 ;
return 0 ;
}
int F_14 ( struct V_7 * V_8 )
{
struct V_50 * V_51 = F_15 ( F_16 ( & V_8 -> V_47 ) ) ;
V_51 -> V_52 = NULL ;
if ( F_17 ( & V_8 -> V_47 ) ) {
struct V_9 V_10 ;
struct V_5 * V_6 ;
int V_18 = - 1 ;
V_6 = F_11 ( & V_8 -> V_47 ) ;
memset ( & V_10 , 0 , sizeof( V_10 ) ) ;
F_18 ( V_53 ) ;
switch ( V_3 ) {
case V_4 :
V_18 = F_2 ( V_6 , V_8 ,
& V_10 ) ;
break;
default:
break;
}
if ( V_18 < 0 ) {
unsigned short V_54 , V_55 ;
V_18 = F_8 ( V_8 , & V_54 ,
& V_55 ) ;
if ( ! V_18 && V_55 ) {
char * V_56 ;
V_10 . V_31 = V_55 ;
F_5 ( V_10 . type , F_19 ( & V_6 -> V_47 ) ,
sizeof( V_10 . type ) ) ;
V_56 = strchr ( V_10 . type , ':' ) ;
if ( V_56 )
* V_56 = '\0' ;
F_20 ( V_10 . type , L_2 ,
sizeof( V_10 . type ) ) ;
} else
return 0 ;
}
V_51 -> V_52 = F_21 ( V_51 -> V_57 -> V_58 [ 0 ] , & V_10 ) ;
if ( ! V_51 -> V_52 )
return - V_20 ;
}
return 0 ;
}
void F_22 ( struct V_7 * V_8 )
{
struct V_50 * V_51 = F_15 ( F_16 ( & V_8 -> V_47 ) ) ;
if ( V_51 -> V_52 )
F_23 ( V_51 -> V_52 ) ;
}
int F_14 ( struct V_7 * V_8 )
{
return 0 ;
}
void F_22 ( struct V_7 * V_8 )
{
}
