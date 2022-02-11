static struct V_1 * F_1 ( int V_2 )
{
if ( V_2 < 0 || V_2 > V_3 . V_4 )
return F_2 ( - V_5 ) ;
return & V_6 [ V_2 ] ;
}
struct V_1 * F_3 ( struct V_7 * V_8 ,
int V_9 )
{
struct V_10 * V_11 = V_3 . V_11 ;
struct V_1 * V_12 ;
unsigned long V_13 ;
V_12 = F_1 ( V_9 ) ;
if ( F_4 ( V_12 ) || V_12 -> V_8 ) {
F_5 ( V_11 , L_1 , V_9 ) ;
return F_2 ( - V_14 ) ;
}
F_6 ( & V_12 -> V_15 , V_13 ) ;
V_12 -> V_16 = 0 ;
V_12 -> V_17 = 0 ;
V_12 -> V_18 = NULL ;
V_12 -> V_8 = V_8 ;
F_7 ( & V_12 -> V_19 ) ;
if ( V_12 -> V_20 == V_21 && V_8 -> V_22 )
V_12 -> V_20 |= V_23 ;
F_8 ( & V_12 -> V_15 , V_13 ) ;
return V_12 ;
}
void F_9 ( struct V_1 * V_12 )
{
unsigned long V_13 ;
if ( ! V_12 || ! V_12 -> V_8 )
return;
F_6 ( & V_12 -> V_15 , V_13 ) ;
V_12 -> V_8 = NULL ;
V_12 -> V_18 = NULL ;
if ( V_12 -> V_20 == ( V_21 | V_23 ) )
V_12 -> V_20 = V_21 ;
F_8 ( & V_12 -> V_15 , V_13 ) ;
}
static int F_10 ( void T_1 * V_24 , T_2 * V_25 , unsigned int V_26 )
{
int V_27 = 0 ;
switch ( V_26 ) {
case 8 :
* V_25 = F_11 ( V_24 ) ;
break;
case 16 :
* V_25 = F_12 ( V_24 ) ;
break;
case 32 :
* V_25 = F_13 ( V_24 ) ;
break;
case 64 :
* V_25 = F_14 ( V_24 ) ;
break;
default:
F_15 ( L_2 ,
V_26 ) ;
V_27 = - V_28 ;
break;
}
return V_27 ;
}
static int F_16 ( void T_1 * V_24 , T_2 V_25 , unsigned int V_26 )
{
int V_27 = 0 ;
switch ( V_26 ) {
case 8 :
F_17 ( V_25 , V_24 ) ;
break;
case 16 :
F_18 ( V_25 , V_24 ) ;
break;
case 32 :
F_19 ( V_25 , V_24 ) ;
break;
case 64 :
F_20 ( V_25 , V_24 ) ;
break;
default:
F_15 ( L_3 ,
V_26 ) ;
V_27 = - V_28 ;
break;
}
return V_27 ;
}
static int F_21 ( struct V_1 * V_12 , void * V_29 )
{
struct V_30 * V_31 = V_12 -> V_32 ;
struct V_33 * V_34 ;
T_2 V_35 ;
T_2 V_36 ;
T_2 V_37 ;
T_3 V_2 = V_12 - V_6 ;
int V_38 = 0 ;
if ( V_2 >= V_3 . V_4 ) {
F_15 ( L_4 ) ;
return - V_5 ;
}
V_34 = & V_31 -> V_39 ;
V_35 = V_31 -> V_40 ;
V_37 = V_31 -> V_41 ;
if ( V_42 [ V_2 ] ) {
V_38 = F_10 ( V_42 [ V_2 ] , & V_36 ,
V_34 -> V_26 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_16 ( V_42 [ V_2 ] ,
( V_36 & V_35 ) | V_37 ,
V_34 -> V_26 ) ;
} else {
V_38 = F_22 ( & V_36 , V_34 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_23 ( ( V_36 & V_35 ) | V_37 ,
V_34 ) ;
}
return V_38 ;
}
static int F_24 ( struct V_43 * V_44 ,
const unsigned long V_45 )
{
struct V_30 * V_31 ;
if ( V_3 . V_4 <= V_46 ) {
V_31 = (struct V_30 * ) V_44 ;
if ( V_31 -> V_44 . type !=
V_47 ) {
F_25 ( L_5 ) ;
return - V_48 ;
}
}
return 0 ;
}
static int T_4 F_26 ( void )
{
T_5 V_49 ;
struct V_50 * V_51 ;
struct V_43 * V_52 ;
int V_53 , V_54 ;
T_6 V_55 = V_56 ;
V_55 = F_27 ( V_57 , 0 ,
& V_51 ,
& V_49 ) ;
if ( F_28 ( V_55 ) || ! V_51 ) {
F_29 ( L_6 ) ;
return - V_58 ;
}
V_53 = F_30 ( V_57 ,
sizeof( struct V_59 ) ,
V_47 ,
F_24 , V_46 ) ;
if ( V_53 <= 0 ) {
F_25 ( L_7 ) ;
return - V_48 ;
}
V_6 = F_31 ( sizeof( struct V_1 ) *
V_53 , V_60 ) ;
if ( ! V_6 ) {
F_25 ( L_8 ) ;
return - V_61 ;
}
V_42 = F_32 ( V_53 , sizeof( void * ) , V_60 ) ;
if ( ! V_42 ) {
F_33 ( V_6 ) ;
return - V_61 ;
}
V_52 = (struct V_43 * ) (
( unsigned long ) V_51 + sizeof( struct V_59 ) ) ;
for ( V_54 = 0 ; V_54 < V_53 ; V_54 ++ ) {
struct V_33 * V_62 ;
struct V_30 * V_31 ;
V_6 [ V_54 ] . V_32 = V_52 ;
V_31 = (struct V_30 * ) V_52 ;
V_62 = & V_31 -> V_39 ;
if ( V_62 -> V_63 == V_64 )
V_42 [ V_54 ] = F_34 ( V_62 -> V_65 ,
V_62 -> V_26 / 8 ) ;
V_52 = (struct V_43 * )
( ( unsigned long ) V_52 + V_52 -> V_66 ) ;
}
V_3 . V_4 = V_53 ;
F_35 ( L_9 , V_3 . V_4 ) ;
return 0 ;
}
static int F_36 ( struct V_67 * V_68 )
{
int V_38 = 0 ;
V_3 . V_69 = V_6 ;
V_3 . V_70 = & V_71 ;
V_3 . V_11 = & V_68 -> V_11 ;
F_35 ( L_10 ) ;
V_38 = F_37 ( & V_3 ) ;
if ( V_38 ) {
F_25 ( L_11 , V_38 ) ;
V_38 = - V_58 ;
}
return V_38 ;
}
static int T_4 F_38 ( void )
{
int V_38 ;
struct V_67 * V_72 ;
if ( V_73 )
return - V_58 ;
V_38 = F_26 () ;
if ( V_38 ) {
F_15 ( L_12 ) ;
return - V_58 ;
}
V_72 = F_39 ( & V_74 ,
F_36 , NULL , 0 , NULL , 0 ) ;
if ( F_4 ( V_72 ) ) {
F_15 ( L_13 ) ;
return F_40 ( V_72 ) ;
}
return 0 ;
}
