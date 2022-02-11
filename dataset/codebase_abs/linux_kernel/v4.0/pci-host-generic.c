static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 = V_2 -> V_12 - V_9 -> V_13 . V_14 -> V_15 ;
return V_9 -> V_13 . V_16 [ V_11 ] + ( ( V_3 << 8 ) | V_4 ) ;
}
static void T_1 * F_2 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
T_2 V_11 = V_2 -> V_12 - V_9 -> V_13 . V_14 -> V_15 ;
return V_9 -> V_13 . V_16 [ V_11 ] + ( ( V_3 << 12 ) | V_4 ) ;
}
static void F_3 ( struct V_8 * V_9 )
{
F_4 ( & V_9 -> V_17 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
int V_18 , V_19 = 0 ;
struct V_20 * V_21 = V_9 -> V_22 . V_21 . V_23 ;
struct V_24 * V_25 = V_21 -> V_26 ;
T_2 V_27 ;
struct V_28 * V_16 ;
V_18 = F_6 ( V_25 , 0 , 0xff , & V_9 -> V_17 ,
& V_27 ) ;
if ( V_18 )
return V_18 ;
F_7 (win, &pci->resources) {
struct V_29 * V_23 , * V_30 = V_16 -> V_30 ;
switch ( F_8 ( V_30 ) ) {
case V_31 :
V_23 = & V_32 ;
V_18 = F_9 ( V_30 , V_27 ) ;
if ( V_18 ) {
F_10 ( V_21 , L_1 ,
V_18 , V_30 ) ;
continue;
}
break;
case V_33 :
V_23 = & V_34 ;
V_19 |= ! ( V_30 -> V_35 & V_36 ) ;
break;
case V_37 :
V_9 -> V_13 . V_14 = V_30 ;
default:
continue;
}
V_18 = F_11 ( V_21 , V_23 , V_30 ) ;
if ( V_18 )
goto V_38;
}
if ( ! V_19 ) {
F_12 ( V_21 , L_2 ) ;
V_18 = - V_39 ;
goto V_38;
}
return 0 ;
V_38:
F_3 ( V_9 ) ;
return V_18 ;
}
static int F_13 ( struct V_8 * V_9 )
{
int V_18 ;
T_3 V_40 ;
T_2 V_41 ;
struct V_29 * V_14 ;
struct V_20 * V_21 = V_9 -> V_22 . V_21 . V_23 ;
struct V_24 * V_25 = V_21 -> V_26 ;
V_18 = F_14 ( V_25 , 0 , & V_9 -> V_13 . V_30 ) ;
if ( V_18 ) {
F_12 ( V_21 , L_3 ) ;
return V_18 ;
}
V_40 = V_9 -> V_13 . V_14 -> V_15 +
( F_15 ( & V_9 -> V_13 . V_30 ) >> V_9 -> V_13 . V_42 -> V_43 ) - 1 ;
V_9 -> V_13 . V_14 -> V_44 = F_16 ( T_2 ,
V_9 -> V_13 . V_14 -> V_44 , V_40 ) ;
V_9 -> V_13 . V_16 = F_17 ( V_21 , F_15 ( V_9 -> V_13 . V_14 ) ,
sizeof( * V_9 -> V_13 . V_16 ) , V_45 ) ;
if ( ! V_9 -> V_13 . V_16 )
return - V_46 ;
if ( ! F_18 ( V_21 , V_9 -> V_13 . V_30 . V_15 ,
F_15 ( & V_9 -> V_13 . V_30 ) ,
L_4 ) )
return - V_46 ;
V_14 = V_9 -> V_13 . V_14 ;
for ( V_41 = V_14 -> V_15 ; V_41 <= V_14 -> V_44 ; ++ V_41 ) {
T_4 V_11 = V_41 - V_14 -> V_15 ;
T_4 V_47 = 1 << V_9 -> V_13 . V_42 -> V_43 ;
V_9 -> V_13 . V_16 [ V_11 ] = F_19 ( V_21 ,
V_9 -> V_13 . V_30 . V_15 + V_41 * V_47 ,
V_47 ) ;
if ( ! V_9 -> V_13 . V_16 [ V_11 ] )
return - V_46 ;
}
return 0 ;
}
static int F_20 ( int V_48 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_21 ( & V_9 -> V_17 , & V_6 -> V_17 ) ;
return 1 ;
}
static int F_22 ( struct V_49 * V_50 )
{
int V_18 ;
const char * type ;
const struct V_51 * V_52 ;
const int * V_53 ;
struct V_20 * V_21 = & V_50 -> V_21 ;
struct V_24 * V_25 = V_21 -> V_26 ;
struct V_8 * V_9 = F_23 ( V_21 , sizeof( * V_9 ) , V_45 ) ;
struct V_54 V_55 = {
. V_56 = 1 ,
. V_10 = ( void * * ) & V_9 ,
. V_57 = F_20 ,
. V_58 = V_59 ,
. V_42 = & V_60 ,
} ;
if ( ! V_9 )
return - V_46 ;
type = F_24 ( V_25 , L_5 , NULL ) ;
if ( ! type || strcmp ( type , L_6 ) ) {
F_12 ( V_21 , L_7 , type ) ;
return - V_39 ;
}
V_53 = F_24 ( V_61 , L_8 , NULL ) ;
if ( V_53 ) {
if ( * V_53 )
F_25 ( V_62 ) ;
else
F_26 ( V_62 ) ;
}
V_52 = F_27 ( V_63 , V_25 ) ;
V_9 -> V_13 . V_42 = V_52 -> V_64 ;
V_60 . V_65 = V_9 -> V_13 . V_42 -> V_65 ;
V_9 -> V_22 . V_21 . V_23 = V_21 ;
F_28 ( & V_9 -> V_22 . V_66 ) ;
F_28 ( & V_9 -> V_17 ) ;
V_18 = F_5 ( V_9 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_13 ( V_9 ) ;
if ( V_18 ) {
F_3 ( V_9 ) ;
return V_18 ;
}
F_29 ( V_21 , & V_55 ) ;
return 0 ;
}
