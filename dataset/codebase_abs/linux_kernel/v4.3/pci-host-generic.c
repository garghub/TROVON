static void T_1 * F_1 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = V_2 -> V_9 - V_6 -> V_10 . V_11 -> V_12 ;
return V_6 -> V_10 . V_13 [ V_8 ] + ( ( V_3 << 8 ) | V_4 ) ;
}
static void T_1 * F_2 ( struct V_1 * V_2 ,
unsigned int V_3 ,
int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_8 = V_2 -> V_9 - V_6 -> V_10 . V_11 -> V_12 ;
return V_6 -> V_10 . V_13 [ V_8 ] + ( ( V_3 << 12 ) | V_4 ) ;
}
static void F_3 ( struct V_5 * V_6 )
{
F_4 ( & V_6 -> V_14 ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
int V_15 , V_16 = 0 ;
struct V_17 * V_18 = V_6 -> V_19 . V_18 . V_20 ;
struct V_21 * V_22 = V_18 -> V_23 ;
T_2 V_24 ;
struct V_25 * V_13 ;
V_15 = F_6 ( V_22 , 0 , 0xff , & V_6 -> V_14 ,
& V_24 ) ;
if ( V_15 )
return V_15 ;
F_7 (win, &pci->resources) {
struct V_26 * V_20 , * V_27 = V_13 -> V_27 ;
switch ( F_8 ( V_27 ) ) {
case V_28 :
V_20 = & V_29 ;
V_15 = F_9 ( V_27 , V_24 ) ;
if ( V_15 ) {
F_10 ( V_18 , L_1 ,
V_15 , V_27 ) ;
continue;
}
break;
case V_30 :
V_20 = & V_31 ;
V_16 |= ! ( V_27 -> V_32 & V_33 ) ;
break;
case V_34 :
V_6 -> V_10 . V_11 = V_27 ;
default:
continue;
}
V_15 = F_11 ( V_18 , V_20 , V_27 ) ;
if ( V_15 )
goto V_35;
}
if ( ! V_16 ) {
F_12 ( V_18 , L_2 ) ;
V_15 = - V_36 ;
goto V_35;
}
return 0 ;
V_35:
F_3 ( V_6 ) ;
return V_15 ;
}
static int F_13 ( struct V_5 * V_6 )
{
int V_15 ;
T_3 V_37 ;
T_2 V_38 ;
struct V_26 * V_11 ;
struct V_17 * V_18 = V_6 -> V_19 . V_18 . V_20 ;
struct V_21 * V_22 = V_18 -> V_23 ;
V_15 = F_14 ( V_22 , 0 , & V_6 -> V_10 . V_27 ) ;
if ( V_15 ) {
F_12 ( V_18 , L_3 ) ;
return V_15 ;
}
V_37 = V_6 -> V_10 . V_11 -> V_12 +
( F_15 ( & V_6 -> V_10 . V_27 ) >> V_6 -> V_10 . V_39 -> V_40 ) - 1 ;
V_6 -> V_10 . V_11 -> V_41 = F_16 ( T_2 ,
V_6 -> V_10 . V_11 -> V_41 , V_37 ) ;
V_6 -> V_10 . V_13 = F_17 ( V_18 , F_15 ( V_6 -> V_10 . V_11 ) ,
sizeof( * V_6 -> V_10 . V_13 ) , V_42 ) ;
if ( ! V_6 -> V_10 . V_13 )
return - V_43 ;
if ( ! F_18 ( V_18 , V_6 -> V_10 . V_27 . V_12 ,
F_15 ( & V_6 -> V_10 . V_27 ) ,
L_4 ) )
return - V_43 ;
V_11 = V_6 -> V_10 . V_11 ;
for ( V_38 = V_11 -> V_12 ; V_38 <= V_11 -> V_41 ; ++ V_38 ) {
T_4 V_8 = V_38 - V_11 -> V_12 ;
T_4 V_44 = 1 << V_6 -> V_10 . V_39 -> V_40 ;
V_6 -> V_10 . V_13 [ V_8 ] = F_19 ( V_18 ,
V_6 -> V_10 . V_27 . V_12 + V_38 * V_44 ,
V_44 ) ;
if ( ! V_6 -> V_10 . V_13 [ V_8 ] )
return - V_43 ;
}
return 0 ;
}
static int F_20 ( struct V_45 * V_46 )
{
int V_15 ;
const char * type ;
const struct V_47 * V_48 ;
const int * V_49 ;
struct V_17 * V_18 = & V_46 -> V_18 ;
struct V_21 * V_22 = V_18 -> V_23 ;
struct V_5 * V_6 = F_21 ( V_18 , sizeof( * V_6 ) , V_42 ) ;
struct V_1 * V_2 , * V_50 ;
if ( ! V_6 )
return - V_43 ;
type = F_22 ( V_22 , L_5 , NULL ) ;
if ( ! type || strcmp ( type , L_6 ) ) {
F_12 ( V_18 , L_7 , type ) ;
return - V_36 ;
}
V_49 = F_22 ( V_51 , L_8 , NULL ) ;
if ( V_49 ) {
if ( * V_49 )
F_23 ( V_52 ) ;
else
F_24 ( V_52 ) ;
}
V_48 = F_25 ( V_53 , V_22 ) ;
V_6 -> V_10 . V_39 = V_48 -> V_54 ;
V_55 . V_56 = V_6 -> V_10 . V_39 -> V_56 ;
V_6 -> V_19 . V_18 . V_20 = V_18 ;
F_26 ( & V_6 -> V_19 . V_57 ) ;
F_26 ( & V_6 -> V_14 ) ;
V_15 = F_5 ( V_6 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_13 ( V_6 ) ;
if ( V_15 ) {
F_3 ( V_6 ) ;
return V_15 ;
}
if ( ! F_27 ( V_52 ) )
F_23 ( V_58 | V_59 ) ;
V_2 = F_28 ( V_18 , 0 , & V_55 , V_6 , & V_6 -> V_14 ) ;
if ( ! V_2 ) {
F_12 ( V_18 , L_9 ) ;
return - V_60 ;
}
F_29 ( V_61 , V_62 ) ;
if ( ! F_27 ( V_52 ) ) {
F_30 ( V_2 ) ;
F_31 ( V_2 ) ;
F_32 (child, &bus->children, node)
F_33 ( V_50 ) ;
}
F_34 ( V_2 ) ;
return 0 ;
}
