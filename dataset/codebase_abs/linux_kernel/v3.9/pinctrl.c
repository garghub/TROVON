static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_7 [ V_6 ] . V_8 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_9 ,
const unsigned * * V_10 , unsigned * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_10 = & V_4 -> V_7 [ V_9 ] . V_12 ;
* V_11 = 1 ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , struct V_13 * V_14 ,
unsigned V_15 )
{
F_6 ( V_14 , L_1 , V_16 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_17 ;
}
static const char * F_8 ( struct V_1 * V_2 ,
unsigned V_6 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_18 [ V_6 ] -> V_8 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_19 ,
const char * const * * V_20 ,
unsigned * const V_21 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
* V_20 = & V_4 -> V_18 [ V_19 ] -> V_8 ;
* V_21 = 1 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_19 ,
unsigned V_9 )
{
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , unsigned V_19 ,
unsigned V_9 )
{
}
static int F_12 ( struct V_22 * V_23 , unsigned V_15 )
{
if ( F_13 ( V_23 , V_15 ,
V_24 ,
V_25 ) != 0 )
return - V_26 ;
if ( F_13 ( V_23 , V_15 ,
V_24 ,
V_27 ) != 0 )
return - V_26 ;
return 0 ;
}
static int F_14 ( struct V_22 * V_23 , unsigned V_15 ,
int V_28 )
{
unsigned long V_29 ;
int V_30 ;
int V_31 = - V_26 ;
F_15 ( & V_23 -> V_32 , V_29 ) ;
V_30 = V_23 -> V_33 -> V_34 [ V_15 ] . V_29 & V_35 ;
switch ( V_30 ) {
case V_36 :
break;
case V_37 :
case V_38 :
case V_39 :
case V_40 :
F_13 ( V_23 , V_15 , V_30 , V_41 ) ;
break;
default:
goto V_42;
}
if ( F_13 ( V_23 , V_15 , V_28 ,
V_25 ) != 0 )
goto V_42;
if ( F_13 ( V_23 , V_15 , V_28 ,
V_27 ) != 0 )
goto V_42;
V_23 -> V_33 -> V_34 [ V_15 ] . V_29 &= ~ V_35 ;
V_23 -> V_33 -> V_34 [ V_15 ] . V_29 |= V_28 ;
V_31 = 0 ;
V_42:
F_16 ( & V_23 -> V_32 , V_29 ) ;
return V_31 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
unsigned V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_4 -> V_23 ;
unsigned long V_29 ;
int V_31 , V_30 ;
F_15 ( & V_23 -> V_32 , V_29 ) ;
V_30 = V_23 -> V_33 -> V_34 [ V_15 ] . V_29 & V_35 ;
switch ( V_30 ) {
case V_24 :
F_18 ( L_2
L_3 ) ;
V_31 = F_12 ( V_23 , V_15 ) ;
if ( F_19 ( V_31 < 0 ) )
goto V_42;
break;
case V_36 :
case V_38 :
case V_37 :
break;
default:
F_20 ( L_4 , V_30 ) ;
V_31 = - V_45 ;
goto V_42;
}
V_31 = 0 ;
V_42:
F_16 ( & V_23 -> V_32 , V_29 ) ;
return V_31 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
unsigned V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_4 -> V_23 ;
unsigned long V_29 ;
int V_30 ;
F_15 ( & V_23 -> V_32 , V_29 ) ;
V_30 = V_23 -> V_33 -> V_34 [ V_15 ] . V_29 & V_35 ;
F_13 ( V_23 , V_15 , V_30 , V_41 ) ;
F_16 ( & V_23 -> V_32 , V_29 ) ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_43 * V_44 ,
unsigned V_15 , bool V_46 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int type = V_46 ? V_38 : V_37 ;
return F_14 ( V_4 -> V_23 , V_15 , type ) ;
}
static int F_23 ( struct V_1 * V_2 , unsigned V_47 ,
unsigned long * V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_22 * V_23 = V_4 -> V_23 ;
* V_48 = V_23 -> V_33 -> V_34 [ V_47 ] . V_29 & V_35 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_2 , unsigned V_47 ,
unsigned long V_48 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_48 >= V_35 )
return - V_26 ;
return F_14 ( V_4 -> V_23 , V_47 , V_48 ) ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_13 * V_14 , unsigned V_47 )
{
const char * V_49 [] = {
[ V_50 ] = L_5 ,
[ V_24 ] = L_6 ,
[ V_36 ] = L_7 ,
[ V_37 ] = L_8 ,
[ V_38 ] = L_9 ,
[ V_39 ] = L_10 ,
[ V_40 ] = L_11 ,
} ;
unsigned long V_48 ;
int V_51 ;
V_51 = F_23 ( V_2 , V_47 , & V_48 ) ;
if ( F_19 ( V_51 != 0 ) )
return;
F_6 ( V_14 , L_12 , V_49 [ V_48 ] ) ;
}
static void F_26 ( struct V_22 * V_23 , struct V_3 * V_4 ,
struct V_52 * V_53 , unsigned V_15 )
{
struct V_54 * V_55 ;
unsigned long V_29 ;
int V_56 ;
V_53 -> V_29 &= ~ V_35 ;
if ( F_27 ( V_23 , V_15 , & V_55 , & V_56 ) == 0 )
V_53 -> V_29 |= V_36 ;
else {
V_53 -> V_29 |= V_24 ;
F_15 ( & V_4 -> V_32 , V_29 ) ;
V_4 -> V_17 ++ ;
F_16 ( & V_4 -> V_32 , V_29 ) ;
}
}
static int F_28 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
unsigned long V_29 ;
int V_57 ;
V_4 -> V_5 = V_23 -> V_33 -> V_58 - V_23 -> V_33 -> V_59 + 1 ;
V_4 -> V_7 = F_29 ( V_23 -> V_60 , sizeof( * V_4 -> V_7 ) * V_4 -> V_5 ,
V_61 ) ;
if ( F_19 ( ! V_4 -> V_7 ) ) {
V_4 -> V_5 = 0 ;
return - V_62 ;
}
F_15 ( & V_23 -> V_32 , V_29 ) ;
for ( V_57 = 0 ; V_57 < V_4 -> V_5 ; V_57 ++ ) {
struct V_63 * V_47 = V_4 -> V_7 + V_57 ;
struct V_52 * V_53 = V_23 -> V_33 -> V_34 + V_57 ;
V_47 -> V_12 = V_23 -> V_33 -> V_59 + V_57 ;
V_47 -> V_8 = V_53 -> V_8 ;
if ( F_19 ( ! V_53 -> V_64 ) )
continue;
F_26 ( V_23 , V_4 , V_53 , V_57 ) ;
}
F_16 ( & V_23 -> V_32 , V_29 ) ;
V_65 . V_10 = V_4 -> V_7 ;
V_65 . V_66 = V_4 -> V_5 ;
return 0 ;
}
static int F_30 ( struct V_22 * V_23 , struct V_3 * V_4 )
{
unsigned long V_29 ;
int V_57 , V_67 ;
V_4 -> V_18 = F_29 ( V_23 -> V_60 , V_4 -> V_17 *
sizeof( * V_4 -> V_18 ) , V_61 ) ;
if ( F_19 ( ! V_4 -> V_18 ) )
return - V_62 ;
F_15 ( & V_4 -> V_32 , V_29 ) ;
for ( V_57 = V_67 = 0 ; V_57 < V_4 -> V_5 ; V_57 ++ ) {
struct V_52 * V_53 = V_23 -> V_33 -> V_34 + V_57 ;
if ( ( V_53 -> V_29 & V_35 ) == V_24 )
V_4 -> V_18 [ V_67 ++ ] = V_53 ;
}
F_16 ( & V_4 -> V_32 , V_29 ) ;
return 0 ;
}
int F_31 ( struct V_22 * V_23 )
{
struct V_3 * V_4 ;
int V_31 ;
V_4 = F_29 ( V_23 -> V_60 , sizeof( * V_4 ) , V_61 ) ;
if ( F_19 ( ! V_4 ) )
return - V_62 ;
F_32 ( & V_4 -> V_32 ) ;
V_4 -> V_23 = V_23 ;
V_23 -> V_68 = V_4 ;
V_31 = F_28 ( V_23 , V_4 ) ;
if ( F_19 ( V_31 != 0 ) )
return V_31 ;
V_31 = F_30 ( V_23 , V_4 ) ;
if ( F_19 ( V_31 != 0 ) )
return V_31 ;
V_4 -> V_69 = F_33 ( & V_65 , V_23 -> V_60 , V_4 ) ;
if ( F_34 ( V_4 -> V_69 ) )
return F_35 ( V_4 -> V_69 ) ;
V_70 . V_66 = V_23 -> V_33 -> V_58
- V_23 -> V_33 -> V_59 + 1 ;
V_70 . V_71 = V_23 -> V_33 -> V_59 ;
V_70 . V_72 = V_23 -> V_33 -> V_59 ;
F_36 ( V_4 -> V_69 , & V_70 ) ;
return 0 ;
}
int F_37 ( struct V_22 * V_23 )
{
struct V_3 * V_4 = V_23 -> V_68 ;
F_38 ( V_4 -> V_69 ) ;
V_23 -> V_68 = NULL ;
return 0 ;
}
