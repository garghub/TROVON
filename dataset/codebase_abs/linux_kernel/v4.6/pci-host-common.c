static void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
int V_4 , V_5 = 0 ;
struct V_6 * V_7 = V_2 -> V_8 . V_7 . V_9 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_1 V_13 ;
struct V_14 * V_15 ;
V_4 = F_4 ( V_11 , 0 , 0xff , & V_2 -> V_3 ,
& V_13 ) ;
if ( V_4 )
return V_4 ;
F_5 (win, &pci->resources) {
struct V_16 * V_9 , * V_17 = V_15 -> V_17 ;
switch ( F_6 ( V_17 ) ) {
case V_18 :
V_9 = & V_19 ;
V_4 = F_7 ( V_17 , V_13 ) ;
if ( V_4 ) {
F_8 ( V_7 , L_1 ,
V_4 , V_17 ) ;
continue;
}
break;
case V_20 :
V_9 = & V_21 ;
V_5 |= ! ( V_17 -> V_22 & V_23 ) ;
break;
case V_24 :
V_2 -> V_25 . V_26 = V_17 ;
default:
continue;
}
V_4 = F_9 ( V_7 , V_9 , V_17 ) ;
if ( V_4 )
goto V_27;
}
if ( ! V_5 ) {
F_10 ( V_7 , L_2 ) ;
V_4 = - V_28 ;
goto V_27;
}
return 0 ;
V_27:
F_1 ( V_2 ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 )
{
int V_4 ;
T_2 V_29 ;
T_1 V_30 ;
struct V_16 * V_26 ;
struct V_6 * V_7 = V_2 -> V_8 . V_7 . V_9 ;
struct V_10 * V_11 = V_7 -> V_12 ;
T_3 V_31 = 1 << V_2 -> V_25 . V_32 -> V_33 ;
V_4 = F_12 ( V_11 , 0 , & V_2 -> V_25 . V_17 ) ;
if ( V_4 ) {
F_10 ( V_7 , L_3 ) ;
return V_4 ;
}
V_29 = V_2 -> V_25 . V_26 -> V_34 +
( F_13 ( & V_2 -> V_25 . V_17 ) >> V_2 -> V_25 . V_32 -> V_33 ) - 1 ;
V_2 -> V_25 . V_26 -> V_35 = F_14 ( T_1 ,
V_2 -> V_25 . V_26 -> V_35 , V_29 ) ;
V_2 -> V_25 . V_15 = F_15 ( V_7 , F_13 ( V_2 -> V_25 . V_26 ) ,
sizeof( * V_2 -> V_25 . V_15 ) , V_36 ) ;
if ( ! V_2 -> V_25 . V_15 )
return - V_37 ;
if ( ! F_16 ( V_7 , V_2 -> V_25 . V_17 . V_34 ,
F_13 ( & V_2 -> V_25 . V_17 ) ,
L_4 ) )
return - V_37 ;
V_26 = V_2 -> V_25 . V_26 ;
for ( V_30 = V_26 -> V_34 ; V_30 <= V_26 -> V_35 ; ++ V_30 ) {
T_3 V_38 = V_30 - V_26 -> V_34 ;
V_2 -> V_25 . V_15 [ V_38 ] = F_17 ( V_7 ,
V_2 -> V_25 . V_17 . V_34 + V_38 * V_31 ,
V_31 ) ;
if ( ! V_2 -> V_25 . V_15 [ V_38 ] )
return - V_37 ;
}
return 0 ;
}
int F_18 ( struct V_39 * V_40 ,
struct V_1 * V_2 )
{
int V_4 ;
const char * type ;
struct V_6 * V_7 = & V_40 -> V_7 ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_41 * V_42 , * V_43 ;
type = F_19 ( V_11 , L_5 , NULL ) ;
if ( ! type || strcmp ( type , L_6 ) ) {
F_10 ( V_7 , L_7 , type ) ;
return - V_28 ;
}
F_20 () ;
V_2 -> V_8 . V_7 . V_9 = V_7 ;
F_21 ( & V_2 -> V_8 . V_44 ) ;
F_21 ( & V_2 -> V_3 ) ;
V_4 = F_3 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_11 ( V_2 ) ;
if ( V_4 ) {
F_1 ( V_2 ) ;
return V_4 ;
}
if ( ! F_22 ( V_45 ) )
F_23 ( V_46 | V_47 ) ;
V_42 = F_24 ( V_7 , V_2 -> V_25 . V_26 -> V_34 ,
& V_2 -> V_25 . V_32 -> V_32 , V_2 , & V_2 -> V_3 ) ;
if ( ! V_42 ) {
F_10 ( V_7 , L_8 ) ;
return - V_48 ;
}
F_25 ( V_49 , V_50 ) ;
if ( ! F_22 ( V_45 ) ) {
F_26 ( V_42 ) ;
F_27 ( V_42 ) ;
F_28 (child, &bus->children, node)
F_29 ( V_43 ) ;
}
F_30 ( V_42 ) ;
return 0 ;
}
