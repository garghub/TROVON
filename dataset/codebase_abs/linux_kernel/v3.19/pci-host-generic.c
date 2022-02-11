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
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_17 , T_3 * V_18 )
{
void T_1 * V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
V_19 = V_9 -> V_13 . V_20 -> V_21 ( V_2 , V_3 , V_4 ) ;
switch ( V_17 ) {
case 1 :
* V_18 = F_4 ( V_19 ) ;
break;
case 2 :
* V_18 = F_5 ( V_19 ) ;
break;
default:
* V_18 = F_6 ( V_19 ) ;
}
return V_22 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_4 , int V_17 , T_3 V_18 )
{
void T_1 * V_19 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_10 ;
V_19 = V_9 -> V_13 . V_20 -> V_21 ( V_2 , V_3 , V_4 ) ;
switch ( V_17 ) {
case 1 :
F_8 ( V_18 , V_19 ) ;
break;
case 2 :
F_9 ( V_18 , V_19 ) ;
break;
default:
F_10 ( V_18 , V_19 ) ;
}
return V_22 ;
}
static void F_11 ( struct V_8 * V_9 )
{
F_12 ( & V_9 -> V_23 ) ;
}
static int F_13 ( struct V_8 * V_9 )
{
int V_24 , V_25 = 0 ;
struct V_26 * V_27 = V_9 -> V_28 . V_27 . V_29 ;
struct V_30 * V_31 = V_27 -> V_32 ;
T_2 V_33 ;
struct V_34 * V_16 ;
V_24 = F_14 ( V_31 , 0 , 0xff , & V_9 -> V_23 ,
& V_33 ) ;
if ( V_24 )
return V_24 ;
F_15 (win, &pci->resources, list) {
struct V_35 * V_29 , * V_36 = V_16 -> V_36 ;
switch ( F_16 ( V_36 ) ) {
case V_37 :
V_29 = & V_38 ;
V_24 = F_17 ( V_36 , V_33 ) ;
if ( V_24 ) {
F_18 ( V_27 , L_1 ,
V_24 , V_36 ) ;
continue;
}
break;
case V_39 :
V_29 = & V_40 ;
V_25 |= ! ( V_36 -> V_41 & V_42 ) ;
break;
case V_43 :
V_9 -> V_13 . V_14 = V_36 ;
default:
continue;
}
V_24 = F_19 ( V_27 , V_29 , V_36 ) ;
if ( V_24 )
goto V_44;
}
if ( ! V_25 ) {
F_20 ( V_27 , L_2 ) ;
V_24 = - V_45 ;
goto V_44;
}
return 0 ;
V_44:
F_11 ( V_9 ) ;
return V_24 ;
}
static int F_21 ( struct V_8 * V_9 )
{
int V_24 ;
T_4 V_46 ;
T_2 V_47 ;
struct V_35 * V_14 ;
struct V_26 * V_27 = V_9 -> V_28 . V_27 . V_29 ;
struct V_30 * V_31 = V_27 -> V_32 ;
V_24 = F_22 ( V_31 , 0 , & V_9 -> V_13 . V_36 ) ;
if ( V_24 ) {
F_20 ( V_27 , L_3 ) ;
return V_24 ;
}
V_46 = V_9 -> V_13 . V_14 -> V_15 +
( F_23 ( & V_9 -> V_13 . V_36 ) >> V_9 -> V_13 . V_20 -> V_48 ) - 1 ;
V_9 -> V_13 . V_14 -> V_49 = F_24 ( T_2 ,
V_9 -> V_13 . V_14 -> V_49 , V_46 ) ;
V_9 -> V_13 . V_16 = F_25 ( V_27 , F_23 ( V_9 -> V_13 . V_14 ) ,
sizeof( * V_9 -> V_13 . V_16 ) , V_50 ) ;
if ( ! V_9 -> V_13 . V_16 )
return - V_51 ;
if ( ! F_26 ( V_27 , V_9 -> V_13 . V_36 . V_15 ,
F_23 ( & V_9 -> V_13 . V_36 ) ,
L_4 ) )
return - V_51 ;
V_14 = V_9 -> V_13 . V_14 ;
for ( V_47 = V_14 -> V_15 ; V_47 <= V_14 -> V_49 ; ++ V_47 ) {
T_3 V_11 = V_47 - V_14 -> V_15 ;
T_3 V_52 = 1 << V_9 -> V_13 . V_20 -> V_48 ;
V_9 -> V_13 . V_16 [ V_11 ] = F_27 ( V_27 ,
V_9 -> V_13 . V_36 . V_15 + V_47 * V_52 ,
V_52 ) ;
if ( ! V_9 -> V_13 . V_16 [ V_11 ] )
return - V_51 ;
}
return 0 ;
}
static int F_28 ( int V_53 , struct V_5 * V_6 )
{
struct V_8 * V_9 = V_6 -> V_10 ;
F_29 ( & V_9 -> V_23 , & V_6 -> V_23 ) ;
return 1 ;
}
static int F_30 ( struct V_54 * V_55 )
{
int V_24 ;
const char * type ;
const struct V_56 * V_57 ;
const int * V_58 ;
struct V_26 * V_27 = & V_55 -> V_27 ;
struct V_30 * V_31 = V_27 -> V_32 ;
struct V_8 * V_9 = F_31 ( V_27 , sizeof( * V_9 ) , V_50 ) ;
struct V_59 V_60 = {
. V_61 = 1 ,
. V_10 = ( void * * ) & V_9 ,
. V_62 = F_28 ,
. V_63 = V_64 ,
. V_20 = & V_65 ,
} ;
if ( ! V_9 )
return - V_51 ;
type = F_32 ( V_31 , L_5 , NULL ) ;
if ( ! type || strcmp ( type , L_6 ) ) {
F_20 ( V_27 , L_7 , type ) ;
return - V_45 ;
}
V_58 = F_32 ( V_66 , L_8 , NULL ) ;
if ( V_58 ) {
if ( * V_58 )
F_33 ( V_67 ) ;
else
F_34 ( V_67 ) ;
}
V_57 = F_35 ( V_68 , V_31 ) ;
V_9 -> V_13 . V_20 = V_57 -> V_69 ;
V_9 -> V_28 . V_27 . V_29 = V_27 ;
F_36 ( & V_9 -> V_28 . V_70 ) ;
F_36 ( & V_9 -> V_23 ) ;
V_24 = F_13 ( V_9 ) ;
if ( V_24 )
return V_24 ;
V_24 = F_21 ( V_9 ) ;
if ( V_24 ) {
F_11 ( V_9 ) ;
return V_24 ;
}
F_37 ( V_27 , & V_60 ) ;
return 0 ;
}
