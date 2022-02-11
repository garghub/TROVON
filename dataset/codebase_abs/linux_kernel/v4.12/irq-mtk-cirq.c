static void F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_6 = V_2 -> V_7 ;
T_1 V_8 = 1 << ( V_6 % 32 ) ;
F_2 ( V_8 , V_5 -> V_9 + V_3 + ( V_6 / 32 ) * 4 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_10 ) ;
F_4 ( V_2 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_11 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int type )
{
int V_12 ;
switch ( type & V_13 ) {
case V_14 :
F_1 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_16 ) ;
break;
case V_17 :
F_1 ( V_2 , V_18 ) ;
F_1 ( V_2 , V_16 ) ;
break;
case V_19 :
F_1 ( V_2 , V_15 ) ;
F_1 ( V_2 , V_20 ) ;
break;
case V_21 :
F_1 ( V_2 , V_18 ) ;
F_1 ( V_2 , V_20 ) ;
break;
default:
break;
}
V_2 = V_2 -> V_22 ;
V_12 = V_2 -> V_23 -> V_24 ( V_2 , type ) ;
return V_12 ;
}
static int F_8 ( struct V_25 * V_26 ,
struct V_27 * V_28 ,
unsigned long * V_7 ,
unsigned int * type )
{
if ( F_9 ( V_28 -> V_29 ) ) {
if ( V_28 -> V_30 != 3 )
return - V_31 ;
if ( V_28 -> V_32 [ 0 ] != 0 )
return - V_31 ;
if ( V_28 -> V_32 [ 1 ] < V_33 -> V_34 ||
V_28 -> V_32 [ 1 ] > V_33 -> V_35 )
return - V_31 ;
* V_7 = V_28 -> V_32 [ 1 ] - V_33 -> V_34 ;
* type = V_28 -> V_32 [ 2 ] & V_13 ;
return 0 ;
}
return - V_31 ;
}
static int F_10 ( struct V_25 * V_36 , unsigned int V_37 ,
unsigned int V_38 , void * V_39 )
{
int V_12 ;
T_2 V_7 ;
unsigned int type ;
struct V_27 * V_28 = V_39 ;
struct V_27 V_40 = * V_28 ;
V_12 = F_8 ( V_36 , V_28 , & V_7 , & type ) ;
if ( V_12 )
return V_12 ;
if ( F_11 ( V_38 != 1 ) )
return - V_31 ;
F_12 ( V_36 , V_37 , V_7 ,
& V_41 ,
V_36 -> V_42 ) ;
V_40 . V_29 = V_36 -> V_43 -> V_29 ;
return F_13 ( V_36 , V_37 , V_38 ,
& V_40 ) ;
}
static int F_14 ( void )
{
T_1 V_44 , V_8 ;
unsigned int V_45 , V_46 ;
bool V_47 , V_48 ;
int V_49 , V_50 , V_51 ;
V_46 = V_33 -> V_35 - V_33 -> V_34 + 1 ;
for ( V_49 = 0 ; V_49 < V_46 ; V_49 ++ ) {
V_45 = F_15 ( V_33 -> V_36 , V_49 ) ;
if ( V_45 ) {
V_50 = F_16 ( V_45 ,
V_52 ,
& V_47 ) ;
V_51 = F_16 ( V_45 ,
V_53 ,
& V_48 ) ;
if ( V_50 == 0 && V_51 == 0 &&
( V_47 && ! V_48 ) )
continue;
}
V_8 = 1 << ( V_49 % 32 ) ;
F_2 ( V_8 , V_33 -> V_9 + V_54 + ( V_49 / 32 ) * 4 ) ;
}
V_44 = F_17 ( V_33 -> V_9 + V_55 ) ;
V_44 |= ( V_56 | V_57 ) ;
F_2 ( V_44 , V_33 -> V_9 + V_55 ) ;
return 0 ;
}
static void F_18 ( void )
{
T_1 V_44 ;
V_44 = F_17 ( V_33 -> V_9 + V_55 ) ;
F_2 ( V_44 | V_58 , V_33 -> V_9 + V_55 ) ;
V_44 = F_17 ( V_33 -> V_9 + V_55 ) ;
V_44 &= ~ ( V_56 | V_57 ) ;
F_2 ( V_44 , V_33 -> V_9 + V_55 ) ;
}
static void F_19 ( void )
{
F_20 ( & V_59 ) ;
}
static inline void F_19 ( void ) {}
static int T_3 F_21 ( struct V_60 * V_61 ,
struct V_60 * V_43 )
{
struct V_25 * V_36 , * V_62 ;
unsigned int V_63 ;
int V_12 ;
V_62 = F_22 ( V_43 ) ;
if ( ! V_62 ) {
F_23 ( L_1 ) ;
return - V_31 ;
}
V_33 = F_24 ( sizeof( * V_33 ) , V_64 ) ;
if ( ! V_33 )
return - V_65 ;
V_33 -> V_9 = F_25 ( V_61 , 0 ) ;
if ( ! V_33 -> V_9 ) {
F_23 ( L_2 ) ;
V_12 = - V_66 ;
goto V_67;
}
V_12 = F_26 ( V_61 , L_3 , 0 ,
& V_33 -> V_34 ) ;
if ( V_12 )
goto V_68;
V_12 = F_26 ( V_61 , L_3 , 1 ,
& V_33 -> V_35 ) ;
if ( V_12 )
goto V_68;
V_63 = V_33 -> V_35 - V_33 -> V_34 + 1 ;
V_36 = F_27 ( V_62 , 0 ,
V_63 , V_61 ,
& V_69 , V_33 ) ;
if ( ! V_36 ) {
V_12 = - V_65 ;
goto V_68;
}
V_33 -> V_36 = V_36 ;
F_19 () ;
return 0 ;
V_68:
F_28 ( V_33 -> V_9 ) ;
V_67:
F_29 ( V_33 ) ;
return V_12 ;
}
